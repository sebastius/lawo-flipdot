#!/usr/bin/env python3
"""Bouw de ASFP-bitmap-varianten: assembleer asfp_bitmap.asm, voeg het samen met
firmware/ASFP.bin en maak per kloksnelheid een image met hogere baudrate.

Vereist sdas8051 en sdld (SDCC). Pad via de omgevingsvariabele SDCC_BIN,
standaard ~/tools/sdcc-4.4.0/bin of de PATH.
"""
import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
SRC = HERE / "asfp_bitmap.asm"
ORIG = REPO / "firmware" / "ASFP.bin"

# Per variant: klok, baudrate en de klokafhankelijke bytes in ASFP (adres: (origineel, nieuw)).
# Baudrate = 2 * fosc / (384 * (256 - TH1))   (SMOD = 1, zoals ASFP instelt)
# Timer0 = 1 ms-tick: herlaadwaarde 65536 - fosc / 12000
VARIANTS = [
    {
        "name": "ASFP-bitmap-6MHz-15625.bin", "osc": 6_000_000, "baud": 15625,
        "bytes": {
            0x211C: (0xE6, 0xFE),   # TH1: 1200 -> 15625 Bd
            0x054C: (0x2C, 0x01),   # wachtlus voor antwoord (IBIS-busomschakeling): ~9 ms -> ~0,2 ms
        },
    },
    {
        "name": "ASFP-bitmap-12MHz-31250.bin", "osc": 12_000_000, "baud": 31250,
        "bytes": {
            0x211C: (0xE6, 0xFE),   # TH1: 31250 Bd bij 12 MHz
            0x211F: (0x0C, 0x18),   # timer0 init laag:  500 -> 1000 tellen (1 ms)
            0x2122: (0xFE, 0xFC),   # timer0 init hoog
            0x068D: (0x0C, 0x18),   # timer0 herlaad in ISR, laag
            0x0690: (0xFE, 0xFC),   # timer0 herlaad in ISR, hoog
            0x054C: (0x2C, 0x01),   # wachtlus voor antwoord: ~4,4 ms -> ~0,1 ms
        },
    },
]

# Plekken die de patch mag overschrijven: (start, eind, verwachte originele inhoud of None = moet 0xFF zijn)
ALLOWED = [
    (0x0000, 0x0002, bytes.fromhex("024ebf")),      # LJMP 4EBF (reset)
    (0x001F, 0x0021, bytes.fromhex("000000")),      # opvulling
    (0x018B, 0x018C, bytes.fromhex("8077")),        # SJMP 0204
    (0x0481, 0x0483, bytes.fromhex("752d01")),      # MOV 2Dh,#01h (begin telegram)
    (0x04A9, 0x04AB, bytes.fromhex("e52dd3")),      # MOV A,2Dh / SETB C (teken opslaan)
    (0x2FD9, 0x2FDB, bytes.fromhex("900571")),      # MOV DPTR,#0571h (hoofdlus)
    (0x30E0, 0x30E2, bytes.fromhex("120692")),      # LCALL 0692 na testbeeld/verzoek
]


def tool(name):
    d = os.environ.get("SDCC_BIN") or str(Path.home() / "tools/sdcc-4.4.0/bin")
    p = Path(d) / name
    if p.exists():
        return str(p)
    found = shutil.which(name)
    if not found:
        sys.exit(f"{name} niet gevonden; zet SDCC_BIN of installeer SDCC")
    return found


def parse_ihx(text):
    data = {}
    for line in text.splitlines():
        line = line.strip()
        if not line.startswith(":"):
            continue
        raw = bytes.fromhex(line[1:])
        n, addr, rtype = raw[0], (raw[1] << 8) | raw[2], raw[3]
        if sum(raw) & 0xFF:
            sys.exit("checksumfout in ihx")
        if rtype == 0:
            for i in range(n):
                data[addr + i] = raw[4 + i]
    return data


XOFF_ADDR = 0x5FFF   # kolomverschuiving voor aP/aB (zie asfp_bitmap.asm)


def main():
    xoff = None
    if "--xoff" in sys.argv:
        xoff = int(sys.argv[sys.argv.index("--xoff") + 1])
        if not 0 <= xoff <= 255:
            sys.exit("--xoff moet 0..255 zijn")
    with tempfile.TemporaryDirectory() as tmp:
        rel = Path(tmp) / "patch.rel"
        ihx = Path(tmp) / "patch.ihx"
        subprocess.run([tool("sdas8051"), "-plosgff", "-o", str(rel), str(SRC)], check=True, cwd=tmp)
        subprocess.run([tool("sdld"), "-n", "-i", str(ihx), str(rel)], check=True, cwd=tmp)
        patch = parse_ihx(ihx.read_text())
        lst = Path(tmp) / "patch.lst"
        if lst.exists():
            shutil.copy(lst, HERE / "asfp_bitmap.lst")

    rom = bytearray(ORIG.read_bytes())
    orig = bytes(rom)
    for addr, val in sorted(patch.items()):
        ok = False
        for start, end, expect in ALLOWED:
            if start <= addr <= end:
                ok = orig[addr] == expect[addr - start]
                break
        else:
            ok = orig[addr] == 0xFF
        if not ok:
            sys.exit(f"patch overschrijft gebruikte byte op 0x{addr:04X} (was 0x{orig[addr]:02X})")
        rom[addr] = val
    if xoff is not None:
        rom[XOFF_ADDR] = xoff
    print(f"kolomverschuiving aP/aB: {rom[XOFF_ADDR]} (byte op 0x{XOFF_ADDR:04X}; wijzigen met --xoff N)")
    used = [a for a in patch if 0x5000 <= a < XOFF_ADDR]
    print(f"patch: {len(patch)} bytes, nieuwe code 0x5000-0x{max(used):04X} ({len(used)} bytes)")
    for start, end, _ in ALLOWED:
        print(f"  haak 0x{start:04X}: {orig[start:end + 1].hex(' ')} -> {rom[start:end + 1].hex(' ')}")
    for v in VARIANTS:
        img = bytearray(rom)
        for addr, (before, after) in v["bytes"].items():
            if img[addr] != before:
                sys.exit(f"{v['name']}: 0x{addr:04X} is 0x{img[addr]:02X}, verwacht 0x{before:02X}")
            img[addr] = after
        (HERE / v["name"]).write_bytes(img)
        # 64 KB voor 27C512-achtige chips (W27C512, SST27SF512): pin 1 = A15 zit op de
        # AZR 802/24 vast aan 5 V, dus de bovenste helft wordt gelezen; image staat er 2x in.
        (HERE / v["name"].replace(".bin", "-27C512.bin")).write_bytes(bytes(img) * 2)
        th1 = img[0x211C]
        baud = 2 * v["osc"] / (384 * (256 - th1))
        tick = (65536 - ((img[0x2122] << 8) | img[0x211F])) * 12 / v["osc"] * 1000
        print(f"{v['name']}: {v['osc'] / 1e6:g} MHz, {baud:.0f} Bd (doel {v['baud']}), timertick {tick:.3f} ms")


if __name__ == "__main__":
    main()
