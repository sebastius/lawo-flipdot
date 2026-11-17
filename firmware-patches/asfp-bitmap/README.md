# ASFP-bitmap: pixels, bitmaps en partial update

> [!WARNING]
> Deze patch is geschreven door een AI-tool (Claude Code) en **alleen getest in de [emulator](../../emulator/)**,
> niet op een echte controller. Brand hem pas op een EPROM als je dat risico accepteert en het origineel bewaart.

Uitbreiding van [`firmware/ASFP.bin`](../../firmware/ASFP.bin). Alle bestaande functies (tekst, lijnnummer,
testbeelden, status, versie `F00293`) blijven werken. Daarbovenop komen drie telegrammen, en het display zet
daarbij **alleen de dots om die echt veranderen**.

| Bestand | Inhoud |
|---|---|
| `ASFP-bitmap.bin` | kant-en-klare firmware (27C256) |
| `asfp_bitmap.asm` | broncode van de patch (sdas8051), met uitleg |
| `asfp_bitmap.lst` | assemblerlisting met adressen |
| `build.py` | assembleert en voegt samen met het origineel; controleert dat alleen de haakplekken en lege ROM worden overschreven |
| `test.js` | 35 tests in de emulator |

## Telegrammen

Zoals altijd sluit elk telegram af met CR + XOR-checksum, bij 1200 baud 7E2. `<a>` is het displayadres als teken
(`1`–`9`, `:`–`?` voor 10–15). Met `0` gaat het telegram naar alle displays, en dan komt er geen antwoord.

| Telegram | Betekenis | Voorbeeld |
|---|---|---|
| `aP<a>` + n × `XXX YY C` | pixels zetten: kolom (3 cijfers), rij (2 cijfers, 0 = boven), kleur `0` zwart / `1` geel | `aP1005031` → dot (5,3) geel |
| `aB<a>XXX` + n × `HHHH` | kolommen vanaf kolom XXX, per kolom 16 bits hex; bit *y* = rij *y* van boven (`0001` = bovenste dot, `8000` = onderste) | `aB1000FFFF0001` → kolom 0 vol, kolom 1 alleen boven |
| `aU<a>` | alle dots opnieuw omzetten, tegen vastzittende dots | `aU1` |

- `aB` en `aP` mogen tot **500 tekens** lang zijn (gewone ASFP-telegrammen: 250). Een volledige bitmap van
  112 × 16 is `aB1000` + 448 hex-tekens = 456 tekens incl. CR, en past dus in één telegram (≈ 4,6 s bij 1200 Bd).
- Na elk geaccepteerd telegram antwoordt het display `a0`. Zit de wachtrij vol (2 telegrammen), dan blijft
  dat antwoord uit: stuur het telegram later opnieuw.
- Ongeldige tekens beëindigen de verwerking van dat telegram. Wat al was ingelezen, blijft staan. Pixels of
  kolommen buiten het display worden overgeslagen.

## Gedrag

- **Partial update:** alleen veranderde dots krijgen een puls (≈ 1,1 ms per dot). Eén pixel staat er ongeveer
  0,3 s na het begin van het telegram, en dat is vooral verzendtijd.
- **Bitmapmodus:** het eerste pixel- of bitmaptelegram neemt het getoonde beeld over, bijvoorbeeld de tekst.
  Je tekent daar dus overheen.
  - Een **inhoudelijk** ASFP-telegram beëindigt de bitmapmodus, en de tekst neemt het display weer over. Inhoudelijk zijn: vrije tekst `aA`, lijn `l`, bestemming `z`, testbeeld `aT`, enzovoort.
  - Status- en versievragen (`a1`, `aV1`) beëindigen de bitmapmodus niet.
- **Wisseltekst:** loopt er een tekst met meerdere pagina's, dan stopt die zodra er een bitmap of pixel komt.

## Hoe het werkt

ASFP heeft al alles wat nodig is (zie [`docs/analyse.md`](../../docs/analyse.md), §2.9):

- **Beeldbuffers:** een gewenst beeld op `0x057E` en een kopie van het getoonde beeld op `0x07AE`, elk 2 bytes per kolom.
- **Verversroutine:** `0x0692` slaat onveranderde dots over als vlag `22h.0` aan staat. Dat is de vlag "wisseltekst actief".
- **Hoofdlus:** die ververst wanneer `0x0571` niet 0 is. Zo werkt ook het testbeeld.

De patch voegt toe:
1. **Ontvangst (interrupt):** voor `aB`/`aP` telt de ontvangstindex door tot 500 tekens, met een extra hoge byte.
2. **Herkenning (interrupt):** het adres wordt gecontroleerd en het ruwe telegram gaat in een wachtrij
   (2 × 512 bytes). Daarna volgt `a0`. Dit duurt maar een paar ms, zodat er bij telegrammen direct achter elkaar
   geen tekens verloren gaan.
3. **Hoofdlus:** zolang de wachtrij niet leeg is, komt er een verzoek (`0x0571 = 5`). Het omhulsel om de verversing
   verwerkt alle telegrammen in een schaduwbuffer en kopieert die naar `0x057E`. Daarna ververst het met
   `22h.0 = 1` en zet `22h.0` weer op 0.
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

De nieuwe code staat op `0x5000`–`0x531C`, in ROM die eerst leeg was. Het werk-RAM `0x0900`–`0x0F27` gebruikt ASFP niet;
ASFP gebruikt RAM tot `0x08D0`, zowel volgens de code als in de emulator gemeten.

## Bekende beperkingen

- **Displaybreedte:** een volledige bitmap in één telegram werkt tot ongeveer 120 kolommen. Bij 140 kolommen zijn het twee telegrammen.
- **Bitmap-telegram terwijl er nog vrije tekst onderweg is:** de ontvangen bitmap overschrijft de
  tekstbuffer (`0x0459`). Komt een `aA` en direct daarna een lange `aB`, voordat ASFP de tekst heeft verwerkt,
  dan kan die tekst beschadigd raken. Gewoon even wachten op `a0` voorkomt dit.
- **Niet getest op echte hardware.** Let vooral op de lengte van de pulsen. In de emulator blijven die ongeveer 1,1 ms,
  ook tijdens lange telegrammen.

## Bouwen en testen

Vereist SDCC (`sdas8051`, `sdld`) en Node.js:

```sh
python3 firmware-patches/asfp-bitmap/build.py      # maakt ASFP-bitmap.bin
node firmware-patches/asfp-bitmap/test.js          # 35 tests in de emulator
```

In de [online emulator](https://sebastius.github.io/lawo-flipdot/emulator/web/) kies je
*ASFP-bitmap (patch)*. De telegrambouwer heeft dan soorten voor pixels (klik op het display), een bitmap uit een
afbeelding, en "alles opnieuw".
