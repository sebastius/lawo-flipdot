# ASFP-bitmap: pixels, bitmaps, partial update en hogere baudrate

> [!WARNING]
> Deze patch is geschreven door een AI-tool (Claude Code) en getest in de [emulator](../../emulator/).
> Brand hem pas op een EPROM als je dat risico accepteert en het origineel bewaart. Zie [Stand op hardware](#stand-op-hardware).

Uitbreiding van [`firmware/ASFP.bin`](../../firmware/ASFP.bin) in twee varianten:

| Bestand | Kristal/oscillator Q1 | Baudrate (7E2) |
|---|---|---|
| `ASFP-bitmap-6MHz-15625.bin` | 6 MHz (origineel) | 15 625 |
| `ASFP-bitmap-12MHz-31250.bin` | 12 MHz (oscillator vervangen; de CPU is een µPD80C31BH-3 "12P") | 31 250 |

Van beide is er ook een `…-27C512.bin` van 64 KB voor 27C512-achtige chips; zie [Op een echte chip zetten](#op-een-echte-chip-zetten).
De bijbehorende ESP-firmware met baudrate-instelling staat in [flipdot-ret-mqtt](https://github.com/sebastius/flipdot-ret-mqtt).

Alle bestaande functies blijven werken: tekst, lijnnummer, testbeelden, status en versie `F00293`.
Daarbij komen drie telegrammen, en het display zet daarbij **alleen de dots om die echt veranderen**.

> [!IMPORTANT]
> De baudrate is niet meer 1200, de IBIS-standaard. Deze firmware is bedoeld voor een zender die direct op de
> RXD-pin van de 80C31 zit, zoals de ESP8266 in
> [flipdot-ret-mqtt](https://github.com/sebastius/flipdot-ret-mqtt), dus niet voor een echte IBIS-bus.
> De wachtlus voor het antwoord (bedoeld voor het omschakelen van de IBIS-bus) is ingekort van ~9 ms naar ~0,2 ms.

## Telegrammen

Zoals altijd sluit elk telegram af met CR + XOR-checksum. `<a>` is het displayadres als teken
(`1`–`9`, `:`–`?` voor 10–15). Met `0` gaat het telegram naar alle displays, en dan komt er geen antwoord.

| Telegram | Betekenis | Voorbeeld |
|---|---|---|
| `aP<a>` + n × `XXX YY C` | pixels: kolom x (3 cijfers), rij (2 cijfers, 0 = boven), kleur `0` zwart / `1` geel | `aP1005031` → dot (5,3) geel |
| `aB<a>XXX` + n × `HHHH` | kolommen vanaf kolom x = XXX, per kolom 16 bits hex; bit *y* = rij *y* van boven (`0001` = bovenste dot, `8000` = onderste) | `aB1000FFFF0001` |
| `aU<a>` | alle dots opnieuw omzetten, tegen vastzittende dots | `aU1` |
| `aD<a>` | diagnose: antwoord `aD` + 28 bytes interne toestand in hex (zie [Diagnose](#diagnose-ad)); geen `a0` | `aD1` |

- `aB` en `aP` mogen tot **500 tekens** lang zijn (gewone ASFP-telegrammen: 250). Een volledige bitmap van
  112 × 16 is 456 tekens incl. CR en past dus in één telegram.
- Na elk geaccepteerd telegram antwoordt het display `a0`.
- **Wacht op `a0` voordat je het volgende telegram stuurt.** Bij deze baudrates kan de verwerking aan het
  eind van een telegram anders het begin van het volgende missen. Er passen 2 telegrammen in de wachtrij.
  Blijft `a0` uit (wachtrij vol of telegram kapot), stuur het dan na ~50 ms opnieuw.
- **Kolomverschuiving:** bij `aP` en `aB` telt de firmware een vaste verschuiving op bij x, standaard **28**. Op het
  geteste display ontbreekt de eerste module van 28 kolommen (ASFP is voor adres 1 ingesteld op 112 kolommen, er
  hangen 3 modules = 84 kolommen aan), dus x = 0 is de eerste zichtbare kolom en x loopt tot 83. De verschuiving is
  één byte op `0x5FFF` (in de 64 KB-versie ook op `0xDFFF`); bouw met `python3 build.py --xoff 0` voor een display
  met alle 4 modules. Tekst, testbeelden en `aU` gebruiken geen verschuiving.
- Ongeldige tekens beëindigen de verwerking van dat telegram. Wat al was ingelezen, blijft staan. Pixels of
  kolommen buiten het display worden overgeslagen.

## Benchmark (emulator)

Gemeten met `node firmware-patches/asfp-bitmap/benchmark.js`, alleen in de emulator, met de originele
verversroutine (zie [Stand op hardware](#stand-op-hardware)) en kolomverschuiving 0. Tijden lopen vanaf het begin
van het versturen, dus inclusief verzendtijd. "Klaar" is de laatste dotpuls.

| | origineel ASFP<br>6 MHz · 1200 Bd | bitmap 6 MHz<br>6 MHz · 15625 Bd | bitmap 12 MHz<br>12 MHz · 31250 Bd |
|---|---|---|---|
| Opstarten: eerste antwoord op statusvraag | 0.24 s | 0.08 s | 0.05 s |
| Opstarten: opstartverversing klaar | 2.56 s | 2.55 s | 2.17 s |
| Statusvraag `a1` → `a0` | 85.8 ms | 7.4 ms | 3.7 ms |
| Versievraag `aV1` → antwoord | 152.2 ms | 13.9 ms | 7.1 ms |
| Tekst "Hallo": eerste flip | 1.31 s | 1.13 s | 0.51 s |
| Tekst "Hallo": klaar | 3.83 s | 3.65 s | 2.67 s |
| Tekst 2 regels: eerste flip | 2.66 s | 2.30 s | 1.04 s |
| Tekst 2 regels: klaar | 5.16 s | 4.80 s | 3.20 s |
| Testbeeld geel `aT11`: klaar | 4.31 s | 4.31 s | 3.37 s |
| Testbeeld zwart `aT10`: klaar | 2.59 s | 2.53 s | 2.16 s |
| Eén pixel `aP`: eerste flip | n.v.t. | 0.335 s | 0.154 s |
| Volledige bitmap 112×16 `aB`: eerste flip | n.v.t. | 0.44 s | 0.22 s |
| Volledige bitmap 112×16 `aB`: klaar | n.v.t. | 1.81 s (849 dots) | 1.25 s (849 dots) |
| Zelfde bitmap nogmaals: antwoord / flips | n.v.t. | 364.8 ms / 0 | 182.4 ms / 0 |
| Alles opnieuw `aU`: klaar | n.v.t. | 2.56 s (1792 dots) | 2.17 s (1792 dots) |
| Pixeltelegrammen per seconde (wachten op `a0`) | n.v.t. | 3 /s (39/100 a0) | 7 /s (59/100 a0) |
| Langste dotpuls | 1.11 ms | 1.11 ms | 1.06 ms |
| Watchdog-resets | 0 | 0 | 0 |

- Een dotpuls duurt in alle varianten ~1,1 ms, net als in het origineel.
- Bij tekst en testbeelden zet ASFP alle 1792 dots om (~2 s). Daar wint 12 MHz vooral bij het opmaken van de tekst.
- Een volledige bitmap is bij 6 MHz klaar in 1,8 s. Een vergelijkbare beeldwissel via tekst kost met het origineel 5,2 s.
- Elke verversing rekent eerst alle 1792 dots door (~0,3 s bij 6 MHz, ook voor één pixel). Daardoor haalt een
  zender die op `a0` wacht maar een paar pixeltelegrammen per seconde, en raakt de wachtrij (2 plaatsen) bij snel
  achter elkaar gestuurde telegrammen vol: dan komt er geen `a0` en moet de zender het opnieuw proberen. Zet bij veel
  pixels liever alles in één `aP`- of `aB`-telegram. Met de eigen snelle routine (`USE_FAST_REFRESH = 1`) was dit in
  de emulator 74 /s, maar die werkt nog niet op hardware.

## Gedrag

- **Partial update:** alleen veranderde dots krijgen een puls. De patch houdt bij welke kolommen
  veranderd zijn, en kopieert en vergelijkt alleen die.
- **Bitmapmodus:** het eerste pixel- of bitmaptelegram neemt het getoonde beeld over, bijvoorbeeld de tekst.
  Je tekent daar dus overheen.
  - Een **inhoudelijk** ASFP-telegram beëindigt de bitmapmodus, en de tekst neemt het display weer over. Inhoudelijk zijn: vrije tekst `aA`, lijn `l`, bestemming `z`, testbeeld `aT`, enzovoort.
  - Status- en versievragen (`a1`, `aV1`) beëindigen de bitmapmodus niet.
- **Wisseltekst:** loopt er een tekst met meerdere pagina's, dan stopt die zodra er een bitmap of pixel komt.

## Hoe het werkt

ASFP heeft een beeldbuffer (`0x057E`, 2 bytes per kolom), een kopie van het getoonde beeld (`0x07AE`) en een
verversroutine (`0x0692`). Zie [`docs/analyse.md`](../../docs/analyse.md), §2.9. De patch voegt toe:

1. **Ontvangst (interrupt):** voor `aB`/`aP` telt de ontvangstindex door tot 500 tekens, met een extra hoge byte.
2. **Herkenning (interrupt):** het adres wordt gecontroleerd en het ruwe telegram gaat in een wachtrij van
   2 × 512 bytes. Daarna volgt `a0`. Head en tail tellen modulo 4, zodat interrupt en hoofdlus elkaar niet hoeven te vergrendelen.
3. **Hoofdlus:** zolang de wachtrij niet leeg is, komt er een verzoek (`0x0571 = 5`). Dan gebeurt het volgende:
   - de telegrammen worden in een schaduwbuffer verwerkt;
   - alleen de gewijzigde kolommen gaan naar `0x057E`;
   - de originele verversroutine `0x0692` zet alleen de veranderde dots om: de patch zet daarvoor `22h.0` = 1 en
     de paginatimer `32h/33h` op 0 (anders wacht `0x0692` eerst de wisseltekst-paginatijd af), en daarna `22h.0` = 0,
     zodat de hoofdlus geen volgende tekstpagina over het beeld tekent.
   Met `USE_FAST_REFRESH = 1` gebruikt de patch in plaats daarvan een eigen snelle routine die per kolom vergelijkt
   (`fast_refresh`). Die werkt in de emulator, maar nog niet op hardware; zie [Stand op hardware](#stand-op-hardware).
4. **Reset:** de eigen variabelen worden gewist, want het werk-RAM is batterijgebufferd.

| Haak | Origineel | Patch |
|---|---|---|
| `0x0000` | `LJMP 4EBF` | `LJMP init` |
| `0x001F` | opvulling | `LJMP ext_a` |
| `0x018B` | `SJMP 0204` | `AJMP 001F` |
| `0x0481` | `MOV 2Dh,#01h` | `LCALL rx_start` |
| `0x04A9` | `MOV A,2Dh` / `SETB C` | `LJMP rx_store` |
| `0x2FD9` | `MOV DPTR,#0571h` | `LJMP main_poll` |
| `0x30E0` | `LCALL 0692` | `LCALL refresh_wrap` |

Per variant (in `build.py`):

| Adres | Origineel | 6 MHz | 12 MHz | Betekenis |
|---|---|---|---|---|
| `0x211C` | `E6` | `FE` | `FE` | TH1: baudrate |
| `0x211F` / `0x2122` | `0C` / `FE` | – | `18` / `FC` | timer0 bij het opstarten: 1 ms-tick |
| `0x068D` / `0x0690` | `0C` / `FE` | – | `18` / `FC` | timer0 herladen in de interrupt |
| `0x054C` | `2C` | `01` | `01` | wachtlus voor het antwoord |

De nieuwe code staat op `0x5000`–`0x5534` (plus de verschuivingsbyte op `0x5FFF`), in ROM die eerst leeg was. Het werk-RAM `0x0900`–`0x0F27` gebruikt ASFP niet;
ASFP gebruikt RAM tot `0x08D0`, zowel volgens de code als in de emulator gemeten.

## Voorbeeld

[`examples/kat-en-muizen.png`](examples/kat-en-muizen.png) is een kat die drie muizen achternazit, met rechts een stuk kaas.
[`examples/kat-en-muizen.txt`](examples/kat-en-muizen.txt) bevat het bijbehorende `aB`-telegram, en
[`examples/make_examples.py`](examples/make_examples.py) maakt beide.
In de emulator upload je het PNG bij *Bitmap uit afbeelding*, of je stuurt het telegram met de commandline:

```sh
node emulator/cli.js --rom firmware-patches/asfp-bitmap/ASFP-bitmap-6MHz-15625.bin \
  --script "wait 3; send $(cat firmware-patches/asfp-bitmap/examples/kat-en-muizen.txt); wait 3; show"
```

## Op een echte chip zetten

De firmware zit in socket **EP1**, een 28-pins DIL-voet voor een 27C256 (label "LLE-AZ-PROG"). Volgens schemablad 4:
- **pin 1 (VPP):** vast aan 5 V;
- **pin 27 (A14):** via jumper J4 aan de CPU;
- **/OE (pin 22):** aan PSEN;
- **/CE (pin 20):** aan massa.

| Chip | Image | Opmerking |
|---|---|---|
| **W27C512** (Winbond) of **SST27SF512**: aanrader | `…-27C512.bin` (64 KB) | Elektrisch wisbaar, dus geen UV-lamp nodig, en vaak tientallen keren te herprogrammeren. Pin 1 is A15 en staat vast hoog, dus de chip leest de bovenste helft; daarom staat de image er 2× in. |
| 27C256, UV-wisbaar (bijv. M27C256B, AT27C256) | `….bin` (32 KB) | Zoals het origineel; wissen met een UV-lamp. |
| AT27C256R, eenmalig programmeerbaar (OTP) | `….bin` (32 KB) | Goedkoop, maar één keer branden. |
| ~~28C256 (EEPROM)~~ | – | **Niet zonder adapter.** Pin 1 is daar A14 (vast hoog) en pin 27 is /WE, die dan aan A14 van de CPU hangt. Met /CE vast laag kan de chip zichzelf overschrijven. |

- **Snelheid:** bij 6 MHz is elke gangbare EPROM snel genoeg. Bij 12 MHz moet de data volgens de gebruikelijke
  80C51-timing binnen ~145 ns na PSEN klaarstaan (3·TCLCL − 105 ns), en binnen ~310 ns na een geldig adres, minus
  ~20–30 ns voor de 74HC573. Kies daarom een chip van **≤ 120 ns** (W27C512-45/-70 en SST27SF512-70 zijn ruim snel genoeg).
- **Programmer:** bijvoorbeeld een XGecu T48 of TL866II+, die de genoemde chips allemaal ondersteunen.
- **Voor het snel uitproberen van veel versies** kan een EPROM-emulator handig zijn, zoals het open-source *EPROM EMU NG*.
  Die zit dan via een kabel in de socket en wordt via USB geladen.
- **Bewaar de originele EPROM.** De inkeping wijst naar het midden van de print, zoals in de handleiding. Laat J4 staan zoals hij staat.

## Stand op hardware

Getest op 17 november 2026 met de 6 MHz-variant op een M27C512 in een AZR 802/24 met 3 modules (84 × 16 zichtbaar),
met de ESP8266 van [flipdot-ret-mqtt](https://github.com/sebastius/flipdot-ret-mqtt):

- **Werkt:** opstarten, tekst, testbeelden (`aT`), 15 625 baud, antwoorden (`a0`, versie `F00293`), pixels (`aP`),
  bitmaps (`aB`, het kattenplaatje), met de originele verversroutine 0x0692.
- **Valkuil:** de eerste module (kolom 0–27) was niet zichtbaar. Alle eerste pixeltests vielen daar, zodat het leek
  alsof er niets gebeurde. Daarom de kolomverschuiving van 28.
- **Werkt nog niet: de eigen snelle verversing (`fast_refresh`).** Daarmee klappen op hardware geen dots om, ook
  niet in het zichtbare deel, terwijl `aD` laat zien dat de pulsen worden aangevraagd en door de timer-interrupt
  afgehandeld; in de emulator werkt het wel. Daarom staat `USE_FAST_REFRESH = 0` en ververst de patch met 0x0692
  (alleen veranderde dots, 22h.0 = 1, paginatimer op 0). Oorzaak nog onbekend; zie [`docs/fast-refresh-onderzoek.md`](../../docs/fast-refresh-onderzoek.md).
- **12 MHz-variant:** niet getest.

### Diagnose (`aD`)

`aD1` antwoordt met `aD` gevolgd door 28 bytes in hex (56 tekens), in deze volgorde:

| # | Inhoud | # | Inhoud |
|---|---|---|---|
| 0 | `Q_HEAD` (0x0E02) | 13–14 | rijmasker-pointer 10h, 11h (verwacht `32 02`) |
| 1 | `Q_TAIL` (0x0E03) | 15 | bitvariabelen 20h |
| 2 | bitmapmodus (0x0E00) | 16 | 21h (bit 4 = puls gevraagd, 6 = kleur, 7 = omgekeerd) |
| 3 | alles-omzetten-verzoek (0x0E01) | 17 | 22h (bit 0 = wisseltekst) |
| 4–5 | gewijzigde kolommen min, max | 18 | P1 (adres, S1, S2, spanningsbewaking) |
| 6 | `REQ` (0x0571) | 19–20 | breedte, hoogte |
| 7 | 0x0554 (bezig) | 21 | xdata 0x0010 (gebruikt door de timer-interrupt) |
| 8 | teller: hoofdlus zette `REQ` = 5 | 22–23 | gewenst beeld, kolom 5 (0x0588) |
| 9 | teller: verwerkte telegrammen | 24–25 | getoond beeld, kolom 5 (0x07B8) |
| 10 | teller: aanroepen snelle verversing | 26–27 | schaduw, kolom 5 (0x0E1A) |
| 11–12 | teller: aangevraagde dotpulsen (16 bit) | | |

Tellers lopen modulo 256 en beginnen bij het opstarten op 0. Het formaat staat in `diag_tab` aan het eind van
[`asfp_bitmap.asm`](asfp_bitmap.asm).

Voorbeeld uit de emulator, na `aT10` en 5 pixels:
`aD01010100FF000000010101000532020680001E701009000800080008`.

## Bekende beperkingen

- **Displaybreedte:** een volledige bitmap in één telegram werkt tot ongeveer 120 kolommen. Bij 140 kolommen zijn het twee telegrammen.
- **Bitmap-telegram terwijl er nog vrije tekst onderweg is:** de ontvangen bitmap overschrijft de
  tekstbuffer (`0x0459`). Wachten op `a0` voorkomt dit.
- **12 MHz:** dit vraagt een hardware-aanpassing (oscillator Q1). Controleer de opdruk van de CPU en de snelheid
  van de EPROM. Niet getest op hardware.
- **Pixels en bitmaps op hardware:** zie [Stand op hardware](#stand-op-hardware).

## Bouwen en testen

Vereist SDCC (`sdas8051`, `sdld`) en Node.js:

```sh
python3 firmware-patches/asfp-bitmap/build.py      # maakt beide varianten
node firmware-patches/asfp-bitmap/test.js          # 48 tests (24 per variant) in de emulator
```

In de [online emulator](https://sebastius.github.io/lawo-flipdot/emulator/web/) kies je een van de
*ASFP-bitmap*-varianten; de juiste kloksnelheid wordt automatisch gekozen. De telegrambouwer heeft dan soorten
voor pixels (klik op het display), een bitmap uit een afbeelding, en "alles opnieuw".
