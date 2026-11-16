# Firmware AZR 802/24

Alle images zijn voor een 27C256 (32 KB) in socket EP1 / U9 ("LLE-AZ-PROG") en worden vanaf adres 0x0000 geladen.

| Bestand | Toelichting (meegeleverd) | Uit de analyse |
|---|---|---|
| `ASFP.bin` | De huidige firmware. | PL/M-51, 6 MHz. Versie-antwoord `aVF00293`. Fonts in de firmware, vrije tekst via `aA`. |
| `AZIPZR1.BIN` | Werkt met protocol DS21T. | Variant van ASFP (zelfde versie). Vervangt woorden in tekst door speciale tekens en voegt lijnvoorvoegsels toe. 19 027 bytes, niet opgevuld tot 32 KB. |
| `AZR-12C.BIN` | Bedoeld voor tekst-EPROMs in tedplus-stijl. | Keil C51. Herkent zelf 80C31 op 6 MHz of 80C32 op 11,0592 MHz. Ondersteunt `FORM`-tekst-EPROMs, een 7-segmentdisplay (802/15) en bitmap-/downloadtelegrammen. |
| `dvb_azrfr51v16.bin` | Een DS3a-variant die een config-EPROM nodig heeft. | Keil C51. Versie `AZR51ZD`, `FD51DSTB`, gedateerd 16.08.2000. |
| `MLAWO_RET_RET60.PLM51_18-11-92.bin` | Firmware voor tekst-EPROMs in de oude TED800-stijl; de fontconfiguratie zit in de firmware. Gebruiken met tekst-EPROM RET0902 en protocol DS1 en DS3. | PL/M-51, uit 1992. Versie-antwoord `aVR.SCH.`. |

Bijbehorende tekst-EPROMs staan in [`../text-eproms/`](../text-eproms/). Meer details staan in [`../docs/analyse.md`](../docs/analyse.md), §2.

## Checksums (MD5)

```
ad46e0491b053d087edb00d7cc53bb2d  ASFP.bin
1ee2bfa6fa05f0ebea6f0e69bdec77f1  AZIPZR1.BIN
b3ce98bdc5df1e10f41f6daa250ef9e5  AZR-12C.BIN
3f2415664635bd8a190fa24b6287d9fd  MLAWO_RET_RET60.PLM51_18-11-92.bin
24cb82c2c048911fc0bd72cc9ed78ec3  dvb_azrfr51v16.bin
```
