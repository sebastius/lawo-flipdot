# ASFP-bitmap: pixels, bitmaps, partial update en hogere baudrate

> [!WARNING]
> Deze patch is geschreven door een AI-tool (Claude Code) en **alleen getest in de [emulator](../../emulator/)**,
> niet op een echte controller. Brand hem pas op een EPROM als je dat risico accepteert en het origineel bewaart.

Uitbreiding van [`firmware/ASFP.bin`](../../firmware/ASFP.bin) in twee varianten:

| Bestand | Kristal/oscillator Q1 | Baudrate (7E2) |
|---|---|---|
| `ASFP-bitmap-6MHz-15625.bin` | 6 MHz (origineel) | 15 625 |
| `ASFP-bitmap-12MHz-31250.bin` | 12 MHz (oscillator vervangen; de CPU is een µPD80C31BH-3 "12P") | 31 250 |

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
| `aP<a>` + n × `XXX YY C` | pixels: kolom (3 cijfers), rij (2 cijfers, 0 = boven), kleur `0` zwart / `1` geel | `aP1005031` → dot (5,3) geel |
| `aB<a>XXX` + n × `HHHH` | kolommen vanaf kolom XXX, per kolom 16 bits hex; bit *y* = rij *y* van boven (`0001` = bovenste dot, `8000` = onderste) | `aB1000FFFF0001` |
| `aU<a>` | alle dots opnieuw omzetten, tegen vastzittende dots | `aU1` |

- `aB` en `aP` mogen tot **500 tekens** lang zijn (gewone ASFP-telegrammen: 250). Een volledige bitmap van
  112 × 16 is 456 tekens incl. CR en past dus in één telegram.
- Na elk geaccepteerd telegram antwoordt het display `a0`.
- **Wacht op `a0` voordat je het volgende telegram stuurt.** Bij deze baudrates kan de verwerking aan het
  eind van een telegram anders het begin van het volgende missen. Er passen 2 telegrammen in de wachtrij.
  Blijft `a0` uit (wachtrij vol of telegram kapot), stuur het dan na ~50 ms opnieuw.
- Ongeldige tekens beëindigen de verwerking van dat telegram. Wat al was ingelezen, blijft staan. Pixels of
  kolommen buiten het display worden overgeslagen.

## Snelheid (gemeten in de emulator)

| | 6 MHz · 15 625 Bd | 12 MHz · 31 250 Bd | ter vergelijking: ASFP, 1200 Bd |
|---|---|---|---|
| één pixel: eerste flip na begin van het telegram | 0,056 s | 0,027 s | – |
| volledige bitmap (456 tekens): versturen | 0,32 s | 0,16 s | (4,6 s) |
| volledige bitmap: klaar | 1,63 s | 1,23 s | – |
| pixeltelegrammen achter elkaar (wachten op `a0`) | 71 / s | 143 / s | – |
| tekst "Hallo": eerste flip na laatste teken | 1,1 s | 0,5 s | 1,1 s |

Een dotpuls duurt in beide varianten ~1,1 ms, net als in het origineel. Pulsen blijven ook tijdens lange
telegrammen ≤ 1,11 ms.

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
   - een **eigen snelle verversroutine** vergelijkt per kolom de woorden en vraagt alleen voor veranderde dots een puls aan.
   Die laatste stap gebruikt hetzelfde mechanisme als ASFP: `056B`/`056C`/`21h.6`, vlag `21h.4`, wachten in idle, met de rijmaskertabel van ASFP en de "omgekeerd"-vlag `21h.7`.
   `0x0692` deed 645 ms over één dot bij 6 MHz en wachtte bij wisseltekst eerst de paginatijd af.
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

De nieuwe code staat op `0x5000`–`0x53FB`, in ROM die eerst leeg was. Het werk-RAM `0x0900`–`0x0F27` gebruikt ASFP niet;
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

## Bekende beperkingen

- **Displaybreedte:** een volledige bitmap in één telegram werkt tot ongeveer 120 kolommen. Bij 140 kolommen zijn het twee telegrammen.
- **Bitmap-telegram terwijl er nog vrije tekst onderweg is:** de ontvangen bitmap overschrijft de
  tekstbuffer (`0x0459`). Wachten op `a0` voorkomt dit.
- **12 MHz:** dit vraagt een hardware-aanpassing (oscillator Q1). Controleer de opdruk van de CPU en de snelheid
  van de EPROM. Niet getest op hardware.
- **Niet getest op echte hardware.**

## Bouwen en testen

Vereist SDCC (`sdas8051`, `sdld`) en Node.js:

```sh
python3 firmware-patches/asfp-bitmap/build.py      # maakt beide varianten
node firmware-patches/asfp-bitmap/test.js          # 48 tests (24 per variant) in de emulator
```

In de [online emulator](https://sebastius.github.io/lawo-flipdot/emulator/web/) kies je een van de
*ASFP-bitmap*-varianten; de juiste kloksnelheid wordt automatisch gekozen. De telegrambouwer heeft dan soorten
voor pixels (klik op het display), een bitmap uit een afbeelding, en "alles opnieuw".
