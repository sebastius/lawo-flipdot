#!/usr/bin/env python3
"""Bouw ASFP-bitmap.bin: assembleer asfp_bitmap.asm en voeg het samen met firmware/ASFP.bin.

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
OUT = HERE / "ASFP-bitmap.bin"

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


def main():
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
    OUT.write_bytes(rom)
    used = [a for a in patch if a >= 0x5000]
    print(f"{OUT.name}: {len(patch)} bytes gepatcht, nieuwe code 0x5000-0x{max(used):04X} ({len(used)} bytes)")
    for start, end, _ in ALLOWED:
        print(f"  haak 0x{start:04X}: {orig[start:end + 1].hex(' ')} -> {rom[start:end + 1].hex(' ')}")


if __name__ == "__main__":
    main()
