# LAWO AZR 802/24 flipdot-controller – analyse van schema's en firmware

*Analyse 16-11-2026, gebaseerd op: `AZR802-24-gereviseerd.pdf` (schema blad 1–5, bestukking, pinout CN3),
`B_MATRIX_E1.pdf` (Full-matrix System User's Manual v2.3), `V_DIP_Schalter-und-Jumper_D1.pdf`,
`flipdot-module-28x13.pdf` (matrixmodule 28×13), alle in [`docs/manuals/`](manuals/), en de ROM-images in
[`firmware/`](../firmware/) en [`text-eproms/`](../text-eproms/).*

Zekerheid: **[zeker]** = direct in schema of code gezien, **[waarschijnlijk]** = sterk afgeleid,
**[vermoeden]** = interpretatie.

---

## 1. Hardware AZR 802/24

### 1.1 Kern

| Onderdeel | Type | Functie |
|---|---|---|
| PC1 | µPD80C31BH (8051 zonder ROM, EA=GND) | CPU |
| Q1 | 6,000 MHz oscillator | → 0,5 MHz machinecyclus (2 µs) |
| EP1 | 27C256 (32 KB) | firmware, socket "LLE-AZ-PROG" |
| RM1 | KM62256, maar A12–A14 aan GND → **slechts 4 KB** gebruikt | werk-RAM 0x0000–0x0FFF |
| RM2, RM3 | KM62256 / 27C256 (J5/J6 kiezen WE↔A14) | teksten-/bestemmingsgeheugen, gebankt |
| IC6 | 74HC573 | adres-latch (ALE) |
| IC4 | MAX690 | reset, watchdog (WDI ← P3.5), batterij-omschakeling VCCR |
| BAT1 | 3,6 V 150 mAh NiCd | houdt RM1–RM3 (VCCR) vast |
| UR1 | LM317 + R20 3,38 Ω | +18 V voor spoeldrivers (stroombegrensd) |
| UR2 | 7805 | +5 V logica |
| U1 (IC2) | LM393 | spanningsbewaking → P1.6 / P1.7 |

### 1.2 Geheugenmap (blad 3/4) **[zeker]**

Decodering: IC7A (4072) = A15|A14|A13|A12, IC7B → `BC1` = dat | A11, IC5B/C + IC8B en
emittervolgers T2/T3/T4 (basis aan RESET, zodat bij spanningsuitval alle CS-lijnen via 10k naar VCCR gaan
→ RAM schrijfbeveiligd).

| CPU-adres (XDATA) | Lezen | Schrijven |
|---|---|---|
| 0x0000–0x0FFF | RM1 (4 KB werk-RAM) | RM1 |
| 0x0000–0x0007 | RM1 | **óók** I/O-latches (74HC138 IC9: A3=0, /WR, A4–A15=0) |
| 0x1000–0xFFFF | RM2 (bank 0) of RM3 (bank 1) | idem |

- Banking: bit 7 van latch 0x0000 (signaal **LD4**, ook groene LED) kiest RM2/RM3.
  Dit is de "U15/U16"-keuze uit de handleiding; MLAWO koppelt het aan schakelaar S1 (P1.4).
- Omdat 32K-chips maar A0–A14 hebben, is een tekst-EPROM bereikbaar via 0x8000–0xFFFF
  (0x1000–0x7FFF is een spiegel; 0x0000–0x0FFF wordt overschaduwd door RM1).
- **Truc**: schrijven naar 0x0000–0x0007 gaat tegelijk naar latch én RAM. De firmware leest de
  RAM-schaduwkopie terug (`MOVX A,@DPTR; ANL/ORL; MOVX @DPTR,A`) om afzonderlijke latch-bits te wijzigen.

### 1.3 I/O-latches (blad 5) **[zeker]**

| Adres | Chip | Uitgangen |
|---|---|---|
| 0x0000 (`EZ`, Y0) | IC15 74HC574 | AC0–AC4 (rij-adres + polariteit/kleur), bit5 LD2, bit6 LD3, bit7 LD4 = bankselect |
| 0x0001 (`ES`, Y1) | IC16 74HC574 | X11–X16 → FP2800: B1, B0, DAT, A2, A1, A0 (+ AC5/AC6) |
| 0x0002 (Y2) | IC17 74HC574 | AC7–AC11 → module-/enable-selectie (IC20 → X7/X8/X9/X10) |
| 0x0003–0x0007 | – | niet aangesloten op 802/24; op 802/15 o.a. 7-segment (zie §3.4) |

Rijdrivers: 74HC238-decoders (IC10/11/18/19/20) sturen ULN2803 (sink, IC12/13) en UDN2981
(source, IC21/22); per matrixrij een `Z+`/`Z−` paar op CN3. De display-enable is **AEN = NOT P3.4**
(IC8F).

### 1.4 Poortpinnen

| Pin | Functie |
|---|---|
| P1.0–P1.3 | display-adres van Sub-D CN1 (pin 14/2/15/3, pull-up RN1; brug naar GND = 1). Bitvolgorde in firmware: P1.0=1, **P1.2=2, P1.1=4**, P1.3=8 – klopt met handleiding (pin 14=1, 15=2, 2=4, 3=8) |
| P1.4 / P1.5 | schakelaars S1 / S2 (S1 = bankkeuze, S2 = seriële IRQ uit) |
| P1.6 / P1.7 | LM393: onderspanning (+24 V resp. +18 V) |
| P3.0 / P3.1 | RXD / TXD (IBIS) |
| P3.2 / P3.3 | TG / TS: testknoppen geel / zwart (CN1 pin 4 / 17) |
| P3.4 (T0) | **E**: spoelpuls-strobe (laag = drivers aan) |
| P3.5 (T1) | **WD**: watchdog-trigger MAX690 |
| P3.6 / P3.7 | /WR, /RD |

### 1.5 IBIS-interface (blad 2)

- Ontvangen: WBSD+/WBSD− (CN1 19/7) → zener D8 5V6 + R21/R22 → optocoupler OK2 (SFH610) → 74HC14 → RXD.
- Zenden: TXD → 74HC14 → OK1 → T1 (BC338) trekt WBED+ (CN1 21) naar WBED− (CN1 9): open-collector-antwoordbus.
- Galvanisch gescheiden, 24 V-niveau, conform VDV 300 (IBIS-wagenbus).

### 1.6 Matrixmodule (`flipdot.pdf`, CN3-pinout)

- Module 28 kolommen × 13 rijen, **per dot één spoel met twee antiparallelle diodes** (D1…D728 = 2×364).
- Op elke module een **FP2800A** kolomdriver (28 uitgangen = 4 groepen × 7): A0–A2 kiest de uitgang
  binnen een groep, B0–B1 de groep, DATA de polariteit, ENABLE de puls.
- ENABLE is **AC-gekoppeld** (C1 0,33 µF + R1): een vastgelopen controller kan de spoelen niet
  doorbranden. Jumper JP2/J1 kiest welke enable-lijn (CN3 pin 7 `OR` of pin 10 `MR`) de module volgt.
- Rijen: per rij een `+`- en `−`-lijn uit de controller (CN3 pin 19–50).
- Eén dot omzetten = rij kiezen (+ of −), kolom kiezen (FP2800-adres + DATA), enable pulsen.

---

## 2. Firmware – overzicht

| Bestand | Grootte | Compiler | Rol (mail) | Gevonden in code |
|---|---|---|---|---|
| `ASFP.bin` | 32 KB (code tot 0x4ED7) | PL/M-51 | huidige firmware | versie-antwoord `aVF00293`, ingebouwde fonts, per-adres tabel, vrije tekst via `aA` |
| `AZIPZR1.BIN` | 19 027 B (niet opgevuld) | PL/M-51 | protocol DS21T | zelfde basis als ASFP, versie `F00293`, extra woord-afkortingen in tekst, lijnvoorvoegsels |
| `MLAWO_RET_RET60.PLM51_18-11-92.bin` | 32 KB (code tot 0x3B9F) | PL/M-51 (18-11-1992) | TED800 tekst-EPROM, DS1/DS3 | versie-antwoord `aVR.SCH.`, fonts + display-config in firmware, leest RET0902 |
| `AZR-12C.BIN` | 32 KB | Keil C51 | tedplus-tekst-EPROM | zoekt `FORM`-blokken, 80C31/80C32-autodetectie, 7-segment, bitmap-telegrammen |
| `dvb_azrfr51v16.bin` | 32 KB (vol) | Keil C51 | DS3a + config-EPROM | `aVAZR51ZD`, `FD51DSTB`, datum `16.08.2000`, printf-strings, lijntabel |
| `RET0902_14-10-2002_C256_05F55CD.bin` | 32 KB | – | tekst-EPROM (TED800-stijl) | RET Rotterdam, zie §4.1 |
| `front.bin` | 32 KB | – | (niet in mail) | `FORM0`-tekst-EPROM, 's-Hertogenbosch-bestemmingen, zie §4.2 |

De drie PL/M-images komen duidelijk uit **één codebasis** (identieke runtime-routines op 0x0003–0x0026,
identieke init, ISR's en telegramparser); MLAWO (1992) is de oudste, ASFP/AZIPZR1 zijn latere afsplitsingen.
AZR-12C en azrfr51 zijn **herschreven in C** (Keil-startup `MOV R0,#7Fh / CLR / DJNZ`, generic-pointer-library
op 0x7385, `printf`-formatstrings).

### 2.1 Gemeenschappelijk (PL/M-familie: MLAWO, ASFP, AZIPZR1) **[zeker]**

- Reset: `MOV SP,#xx; MOV PSW,#0; LJMP main`. Vectors: Timer0 (0x0B) en Serial (0x23); INT0/INT1 niet gebruikt
  (die vectorruimte bevat library-code).
- `TMOD=21h`, `SCON=D8h` (mode 3, 9 bit, REN, TB8=1), `PCON=80h` (SMOD), `TH1=E6h`
  → **1201,9 baud** bij 6 MHz. Mode 3 = 7 data + pariteit + TB8 als tweede stopbit → **IBIS 1200 7E2**.
- Timer0 reload `FE0Ch` = 500 tellen × 2 µs. Omdat de ISR pas aan het eind herlaadt (`068B`/`068E`), is de
  werkelijke tick ~700–740 cycli = **~1,45 ms** (zie [`fast-refresh-onderzoek.md`](fast-refresh-onderzoek.md) §2).
- Ontvangst-ISR:
  1. pariteit gecontroleerd met PSW.P (even pariteit over 8 bits);
  2. startteken moet `a`…`z` zijn; buffer tot 0xF9 tekens;
  3. `CR` sluit af, volgende byte = **IBIS-checksum** (XOR, start 0x7F);
  4. bij goede checksum → telegram-dispatcher.
- Zenden: antwoord-telegram via TI-interrupt, eerste byte na korte delay (busomschakeling).
- **Dotaansturing in de 1 ms-timer-ISR**: `SETB P3.4` (puls uit) → latches 0x0000 (rij + kleur, LED-bits
  bewaard), 0x0002 (kolom / 112 = moduleblok), 0x0001 (kolom mod 112 via kolomtabel in ROM, OR kleurbit)
  → `CLR P3.4` (puls aan). **Eén dot per tick (~1,45 ms), pulsduur ≈ 1,1 ms, E uit ≈ 0,3 ms.**
  Een 112×16-display (1 792 dots) kost dus ca. 2,5 s voor een volledige beeldopbouw.
  Bij 140 kolommen (`0x8C`) worden andere kolomtabel-offsets (0x54 / 0x62) gebruikt.
- Watchdog: `CPL P3.5` in de timer-ISR, maar alleen zolang een door de hoofdlus herladen teller
  (iRAM 2Bh/2Ch) > 0 is → hangt de hoofdlus, dan stopt de trigger en reset de MAX690.
- Adres: `CPL P1`, bits herschikt (zie §1.4).
- S1 (P1.4) → bankselect, S2 (P1.5) → `IE=82h` (seriële IRQ uit) i.p.v. `92h` (in MLAWO nagelopen).
- LED LD2 (latch-bit 5) gaat aan bij een ontvangstfout (pariteit/checksum) (in MLAWO nagelopen).

### 2.2 Telegrammen (PL/M-familie) **[zeker voor letters, waarschijnlijk voor VDV-namen]**

| Telegram | MLAWO | ASFP / AZIPZR1 | Actie |
|---|---|---|---|
| `l` + cijfers | ✓ | ✓ | DS001 lijnnummer (3 cijfers → 0x0007/0x0011) |
| `lE…` | ✓ | ✓ | lijn-aanvulling (2e waarde) |
| `lS…` | ✓ (genegeerd) | ✓ (genegeerd) | |
| `k` + cijfers | ✓ | ✓ | DS002 koersnummer |
| `z` + cijfers | ✓ | ✓* | DS003 bestemmingsnummer |
| `zA…` | ✓ | ✓* | DS003a bestemmingstekst |
| `w` + cijfers | ✓ | ✓ | (nummer, betekenis niet vastgesteld) |
| `e` + 5 tekens | – | ✓ | 5 tekens naar 0x0009 |
| `a` + adres + CR | ✓ | ✓ | DS020 statusvraag → antwoord `a0` of `a6` (DS120) |
| `aA` + adres + tekst | – | ✓ | DS021 vrije tekst voor dit adres (al in de ISR gekopieerd) |
| `aV` + adres/0 | ✓ | ✓ | DS201 versievraag → `aV` + 6 tekens (DS1201) |
| `aT` + adres + Z | ✓ | ✓ | testbeeld: 0 zwart, 1 geel, 2 dambord, 3 invers dambord (gedocumenteerd in handleiding §4) |

\* In ASFP/AZIPZR1 komt de bestemmingsletter uit een **tabel per adres** (ASFP 0x4C0B; in deze build
overal `z`), zodat verschillende displays op verschillende telegramletters kunnen reageren.

Versie-antwoorden: MLAWO `R.SCH.` (ROM 0x380B), ASFP en AZIPZR1 allebei `F00293` (0x4B16 / 0x4691).

### 2.3 MLAWO (TED800-tekst-EPROM, 1992)

- Fonts in de firmware (zie §5) en per adres een **configuratierecord van 14 bytes** vanaf ROM ~0x382D
  (adres 0…15). Daarin o.a. `0x1C`/`0x15` (28/21 kolommen lijnnummerveld) `0x10` (16 rijen),
  `0x54` (84 kolommen bestemmingsveld) **[waarschijnlijk]**. Dit is "font-config in firmware" uit de mail.
- Framebuffer: 16-bit woorden per kolom vanaf XDATA 0x0363 → max **16 rijen** (klopt met TED800-limiet).
- Leest tekstrecords uit de EPROM in RM2/RM3 (§4.1); verwerkt `0x03` (2e regel) en `0x04` (wisseltekst);
  tabel op 0x3811 kiest font/positie op basis van het aantal cijfers in het lijnnummer.

### 2.4 ASFP (huidige firmware)

- Zelfde kern als MLAWO, aangevuld met: `aA`-vrije tekst (DS021), `e`-telegram, adres-afhankelijke telegramletter,
  ondersteuning 140-koloms displays, grotere font-set (incl. S-Bahn/U-Bahn-pictogrammen en Duitse umlauts).
- 14-byte configuratierecords per adres rond 0x4B20–0x4C0A.

### 2.5 AZIPZR1 (DS21T)

- Afgeleid van ASFP (zelfde versie `F00293`), maar 13 KB korter en niet opgevuld met 0xFF.
- **Lijnvoorvoegsel/-symbool** op basis van een code in XDATA 0x0005: 1→`E`, 3→`jkl` (3-tekens pictogram),
  4→`N`, 5→`S`, 0x21→`mno` (pictogram), `a`/`b`→`UE3`.
- **Woordvervanging** in ontvangen tekst om ruimte te sparen: `]BER` (ÜBER, DIN 66003) → één glyph,
  `WEITER` → glyph `w`, `N.` → `n`, plus `]E…`, `MI…`, `VI…` – speciale glyphs in de font.

### 2.6 AZR-12C (tedplus-tekst-EPROM) **[zeker, tenzij anders vermeld]**

- Keil C51, main op 0x0026; schrijft na elke init-stap een statuscode naar 0x09D3.
- **CPU-/kristal-autodetectie**: schrijft `AA 55 F0` naar iRAM 0xC0–0xC2 (bestaat alleen op 80C32):
  - 80C32 → 11,0592 MHz: `TH1=D0h` (1200 Bd), T0 `FE32h` (0,5 ms), 7-segmentcode `86h`;
  - 80C31 → 6 MHz: `TH1=E6h` (1200 Bd), T0 `FF05h` (0,5 ms), 7-segmentcode `8Eh`.
  Dit zijn precies de 7-segmentcodes "80C32 / 11 MHz" en "80C31 / 6 MHz" uit de handleiding →
  **latch 0x0003 = 7-segment D16 op de 802/15**. De firmware draait dus op 802/24 én 802/15.
- Zoekt tekst-/configuratieblokken met header **`FORM` + byte + complement** (bv. `FORM0\xCF`) en een
  lengteveld op offset 0x14 – dat is de "formula search" uit de 7-segmentcodes.
- Kent bitmap-/downloadtelegrammen (`z\`, `bm` → 7-seg `C1h`), plus `l`, `z`, `d`, `w`, `aA`, `aV`, `aT`.
- Baudrate-tabel `TH1 = E6/F3/F9/FA/FB` (instelbare snelheden, o.a. voor download).
- P1.6-bewaking: bij onderspanning zet de firmware de interrupts uit en wacht (de watchdog blijft getriggerd) tot de spanning terug is.
- **7-segmentcodes ontcijferd (via Ghidra)**: gemeenschappelijke anode, actief laag (bit7=dp … bit0=a):
  `C0`=0, `F9`=1, `80`=8, `89`=H, `C7`=L, `86`=E, `8E`=F, `C1`=U. CPU-detectie toont dus **E** (80C32)
  of **F** (80C31); het `bm`-telegram toont **U**.
- Functie 0x5411 berekent een **16-bit XOR-checksum over een `FORM`-blok** (en triggert tussendoor de watchdog).
- Functie 0x54D5 (4,4 KB, aangeroepen vanuit `main`) is een `switch` met 20 commando's op byte 3 van een
  ontvangen frame; toont o.a. H, L en cijfers op het 7-segment → vermoedelijk het **downloadprotocol**
  (L1130A/801-7) **[waarschijnlijk]**. Deze code was voor de eigen disassembler onzichtbaar.

### 2.7 dvb_azrfr51v16 (DS3a + config-EPROM)

- Keil C51, 32 KB vrijwel vol. Strings: `a0`, `aVAZR51ZD` (versie-antwoord), `A%u-%s-V%s%s`, `FD51DSTB`,
  `16.08.2000`, `%02u.%02u.%04u` (datumweergave), `00.00.0000`.
- Adres via opzoektabel (0x29BA) i.p.v. bitgeschuif.
- Seriële modus wisselt tussen `SCON=D0h` (9-bit) en `50h` (8-bit), TH1 wordt berekend → meerdere protocollen/snelheden.
- Timer0-tick 10 ms (`EC78h` bij 6 MHz) of een alternatieve reload `D59Eh` afhankelijk van een vlag
  (vermoedelijk andere klok) **[vermoeden]**.
- Tabel vanaf 0x5BD9: lijnnummer → weergavestring met fontescapes, bv. `1` → `1/#1#0`, `61` → `E#1#0`,
  `62` → `N#1#0`, `63` → `C…`, `64` → `S…`. `#n` lijkt een fontwissel **[waarschijnlijk]**.
- Configuratie (displaygrootte, fonts) komt uit een aparte config-EPROM, niet uit de firmware (conform mail).

---

### 2.8 Vrije tekst (`aA`) in ASFP: pagina-opmaak (getest in de emulator)

- Na `aA` + adres volgen vier tekens en een `\n`. Het eerste teken lijkt er niet toe te doen. De **laatste drie zijn het lijnnummer**, dat zonder voorloopnullen in het lijnnummervak verschijnt.
  - `1001` toont "1", `1201` toont "201", `0000` of spaties laten het vak leeg.
  - Een apart `l`-telegram verandert dit vak bij vrije tekst niet. Eerder schreef ik dat ASFP deze tekens negeert; dat was fout.
- **Tekstbreedte:** de tekst blijft in het tekstvak van 84 kolommen (bij adres 1 kolom 28–111), ook zonder lijnnummer.
  Met een patch van twee bytes in de configuratie van adres 1 (0x4B3D `1C`→`00`, 0x4B3F `54`→`70`) loopt de tekst over de volle breedte. Dat is alleen in de emulator getest.
- **Pagina van twee regels:** `regel1\nregel2\n\n`. Beide regels krijgen het kleine font.
- **Pagina van één regel:** `regel\n\n\n`. Met maar `\n\n` valt het eerste teken van de volgende pagina weg.
  Een losse regel krijgt het grote font als hij past, anders een kleiner font.
- Bij meerdere pagina's wisselen die elkaar af.
- ASFP begint pas ongeveer 2,5 s na het telegram met tekenen. Daarna schrijft hij alle dots opnieuw, met pulsen van ongeveer 1,1 ms. Een nieuw beeld kost dus ongeveer 4,5 s.

---

### 2.9 Beeldopbouw in ASFP (met de emulator nagelopen)

| Onderdeel | Rol |
|---|---|
| `0x057E` | gewenst beeld, 2 bytes per kolom (hoog, laag); bit *y* = rij *y* van boven (masktabel `0x3202`) |
| `0x07AE` | kopie van het getoonde beeld, bijgewerkt na elke verversing |
| `0x0692` | verversroutine: per dot `056B`/`056C`/`21h.6` invullen, `21h.4` zetten en wachten tot de timer-interrupt de puls heeft gegeven |
| `22h.0` | **wisseltekst actief**: de tekstweergave zet hem bij meerdere pagina's (`0x0A7E`). Zolang hij gezet is, tekent de hoofdlus steeds de volgende pagina (`0x2D77`) en slaat `0x0692` onveranderde dots over. Staat hij uit, dan krijgt elke dot een puls. |
| `0x0571` | verzoek aan de hoofdlus (testbeeld `aT`: 1–4); daarna `0x0692` en terug naar 0 |

Eerder schreef ik dat ASFP altijd alle dots opnieuw schrijft. Dat klopt bij gewone tekst en testbeelden, maar
bij wisseltekst gebruikt ASFP partial update. De patch in [`firmware-patches/asfp-bitmap/`](../firmware-patches/asfp-bitmap/)
maakt hier gebruik van voor pixel- en bitmaptelegrammen.

---

## 3. Bediening en diagnose (uit firmware + handleiding)

- Testknop geel/zwart (TG/TS op P3.2/P3.3) → hele display geel/zwart.
- Testtelegram via laptop + V24/IBIS-converter: `aT` + adres (`0` = alle) + `0..3` + CR + checksum.
- Versie opvragen: `aV` + adres + CR + checksum → antwoord bv. `aVF00293`.
- LED's: LD1 = reset (aan = CPU draait), LD2 = fout (pariteit/checksum, onderspanning),
  LD3 = door firmware gestuurd (functie niet vastgesteld), LD4 = gekozen tekstbank.

---

## 4. Tekst-EPROM-formaten

### 4.1 RET0902 (TED800-stijl, voor MLAWO) **[zeker]**

- Platte ASCII, records gescheiden door `CR LF`; **recordnummer = bestemmingsnummer**.
- Records 1–1000: bestemmingen (286 gevuld; RET Rotterdam: "CENTRAAL STATION", "METRODIENST", "SPIJKENISSE"…).
- Records 1001 + n: **lijnnummer n** (`B1`…`B80`, `BN1`…`BN9` voor nachtlijnen).
- Eerste teken van elk blok = **opmaak-/fontcode**: `B` (groot, 1 regel), `I` (1e regel klein), `E` (2e regel klein),
  `G`, `H`, `F`, `A`.
- `0x03` = naar regel 2, `0x04` = **wisseltekst** (volgende pagina), bv.
  `BMETRODIENST␄ICENTRAAL␃ESTATION`.
- Trailer bij 0x23BF: `FORMPREF` + TED800-projectinstellingen met de 4 fontnamen
  `TS15`, `TBGF7B`, `TBGF7`, `TB16L`, poort `COM1`; daarna testregels `AAAA…`.
- Volledige lijst: `text-eproms/RET0902_teksten.txt`.

### 4.2 front.bin (`FORM`-stijl, voor AZR-12C) **[waarschijnlijk]**

- Header `FORM0`, `0xCF` (= NOT '0'), naam `RET     `, lengte/pointers; daarna blok `FR1`.
- Records: `[nummer:2][lengte:2]` + tekstblokken `[vlag][font][x][y][..][..] tekst\0`
  (bit 7 van de vlag = `0xA0`: laatste blok). Bijvoorbeeld record 3: "STATION NS" op y=0 en "CENTRUM" op y=9
  → **vrij gepositioneerde tekstblokken** (TED900/"tedplus").
- Inhoud: 's-Hertogenbosch (Rosmalen, Maaspoort, Vught de Baarzen, Pettelaar Park…); vanaf ~0x0D00 lijnnummers.
- 0x0000–0x3BFF data, rest leeg (0x00) – zeer waarschijnlijk ook fontdata in het `FORM`-blok.

---

## 5. Fontformaat in de firmware (ASFP, AZIPZR1, MLAWO) **[zeker]**

- Per glyph **17 bytes**: 1 byte breedte + 16 rij-bytes (MSB = linkerkolom), tekens 0x20–0x7F.
- ASFP 16-pixel font begint op **0x3246**; zie [`docs/images/ASFP_font16_0x3246.png`](images/ASFP_font16_0x3246.png).
- Tekenset DIN 66003 (Duits): `[ \ ] { | } ~` = Ä Ö Ü ä ö ü ß; `$`/`%` = loopmannetjes, `=`/`?` = S-Bahn/U-Bahn-symbool.
- Daarna volgen kleinere fonts (o.a. 7 pixels hoog) en een karaktervertalingstabel (de omgekeerde
  ASCII-reeks `?>=<;:9765…` op ASFP 0x313E).

---

## 6. Praktische conclusies

1. **Klok bepaalt firmware**: ASFP, AZIPZR1 en MLAWO zijn hard-coded voor **6 MHz / 80C31** (802/24).
   AZR-12C detecteert zelf 80C31-6 MHz of 80C32-11,0592 MHz.
2. **Tekst-EPROM hoort bij firmware**: MLAWO ↔ RET0902 (CR/LF-records, fonts in firmware);
   AZR-12C ↔ `FORM`-images zoals front.bin; azrfr51 ↔ config-EPROM; ASFP/AZIPZR1 tekenen IBIS-tekst
   met de eigen fonts.
3. **EPROM in RM2/RM3**: jumpers J5/J6 op EPROM-stand (pin 27 = A14, geen WE); S1 kiest de socket.
4. **Display zelf aansturen** (zonder deze controller): per dot rij ± kiezen, FP2800 adresseren
   (A0–A2, B0–B1, DATA) en ca. 1 ms enable-puls geven op 18 V; de AC-koppeling op de module begrenst de puls.
5. **Testen met IBIS**: 1200 Bd, 7E2, telegram + CR + XOR-checksum (start 0x7F); antwoorden op dezelfde bus via WBED.

---

## 7. Bestanden in deze repository

| Pad | Inhoud |
|---|---|
| `docs/analyse.md` | dit rapport |
| `docs/manuals/` | schema AZR 802/24, Full-matrix-handleiding, DIP/jumper-doc, schema matrixmodule 28×13, FP2800A-datasheet |
| `docs/fast-refresh-onderzoek.md` | onderzoek naar `fast_refresh` op hardware, FP2800A-controle |
| `docs/images/ASFP_font16_0x3246.png` | weergave van het 16-pixel font |
| `firmware/` | de vijf firmware-images (zie `firmware/README.md`) |
| `text-eproms/` | tekst-EPROMs RET0902 en front.bin, plus `RET0902_teksten.txt` (alle gevulde records) |
| `tools/d51.py` | eigen 8051-disassembler met recursieve tracering (`python3 tools/d51.py rom.bin out.asm [extra-entry-hex…]`) |
| `tools/ghidra/run_ghidra.sh` | importeert alle firmwares in Ghidra, analyseert en exporteert (zie §8) |
| `tools/ghidra/scripts/` | `LawoSetup.java`, `LawoJumpTables.java`, `LawoExport.java` |
| `analysis/disasm/*.asm` | disassembly per firmware (gevolgde code; data/dode code als `db`) |
| `analysis/ghidra_export/*.c` | gedecompileerde pseudo-C per firmware |
| `analysis/ghidra_export/*.functions.txt` | functielijst met grootte en aanroepers |
| `analysis/ghidra_export/*.xrefs.txt` | wie leest/schrijft de I/O-latches, SFR's en poortbits |
| `build/ghidra_project/` | Ghidra-project (lokaal gegenereerd, niet in git) |

**Beperkingen**: de eigen disassembler (`analysis/disasm/`) volgt alleen directe sprongen; gebruik voor AZR-12C de
Ghidra-uitvoer. De betekenis van velden in de 14-byte configuratierecords en het `FORM`-recordformaat is
afgeleid en niet volledig geverifieerd.

---

## 8. Ghidra-analyse

Ghidra 12.2 staat in `~/tools/ghidra_12.2_PUBLIC` (vereist JDK 25). Draaien: `tools/ghidra/run_ghidra.sh`
(alles) of `tools/ghidra/run_ghidra.sh AZR-12C.BIN` (één bestand). GUI: `~/tools/ghidra_12.2_PUBLIC/ghidraRun`,
open project `build/ghidra_project/LAWO`.

De pipeline (headless):
1. **LawoSetup** (vóór analyse): XDATA-blokken `IO_LATCH_RM1` (0x0000–0x0007, volatile), `RM1_WORK_RAM`,
   `RM2_RM3_TEXT`; benoemde latches (`LATCH0_EZ_row_color_LED_bank`, `LATCH1_ES_FP2800`, …);
   interruptvectoren als entry points; bekende routines (`main`, `telegram_dispatch`, `timer_1ms_dot_pulse`,
   `cpu_detect_80c31_80c32`, `check_FORM_header`, …).
2. **LawoJumpTables**: herkent `MOV DPTR,#tabel … JMP @A+DPTR` met `LJMP`/`AJMP`-tabel, disassembleert
   de doelen, voegt computed-jump-referenties toe en schrijft een jumptable-override → echte `switch` in C.
3. **LawoExport**: voegt XDATA-referenties toe voor elke `MOV DPTR,#x` + `MOVX`, en exporteert decompilatie,
   functielijst en xrefs.

| Firmware | Functies | Herkende code | Opmerking |
|---|---|---|---|
| ASFP | 48 | 9 762 B | rest = fonts, tabellen, PL/M-dode code |
| AZIPZR1 | 48 | 10 337 / 19 027 B | idem |
| MLAWO | 44 | 7 581 B | idem |
| AZR-12C | 83 | **30 339 B** (was 24 932) | 2 switch-tabellen (28 cases) opgelost |
| dvb_azrfr51v16 | 139 | 27 377 B | 2 nooit aangeroepen functies (0x0966, 0x0EF8) toegevoegd |

Resterende "Could not recover jumptable"-waarschuwingen (AZR-12C 0x7430…0x7BA0, idem in azrfr51) zitten in
de **Keil-C51-runtimebibliotheek** (generic-pointer-toegang per geheugentype) en zijn geen applicatielogica.
