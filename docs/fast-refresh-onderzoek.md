# Onderzoek: waarom `fast_refresh` niet werkt op hardware

> [!WARNING]
> Geschreven door een AI-tool (Claude Code) op 18 november 2026, op basis van disassembly, listings, schema's,
> het FP2800A-datasheet en het tellen van cycli. De emulator is daarbij **niet** gedraaid en er is niets op
> hardware gemeten. Zie [Open punten](#open-punten).

Achtergrond: in [`firmware-patches/asfp-bitmap`](../firmware-patches/asfp-bitmap/) staat een eigen snelle
verversroutine (`fast_refresh`, schakelaar `USE_FAST_REFRESH`). In de emulator werkt die; op hardware
(17-11-2026) klapten er geen dots om, terwijl `aD` liet zien dat de pulsen werden aangevraagd en door de
timer-interrupt afgehandeld. Daarom staat de patch nu op de originele routine `0x0692`.

## 1. `fast_refresh` tegenover `0x0692`

Vergeleken: de bron (`asfp_bitmap.asm`, `fast_refresh` en `fr_setup`), de image die echt getest is
(commit `51464de`, opnieuw gedisassembleerd: hook `30E0 → 5131`, relocaties kloppen) en `0x0692` plus de
timer-ISR `0x0568` in [`analysis/disasm/ASFP.asm`](../analysis/disasm/ASFP.asm).

| Wat | `0x0692` | `fast_refresh` |
|---|---|---|
| 'omgekeerd' 21h.7 (tabel `4B33` + 20h.0) | `0732`–`0754` | `fr_setup`, identiek |
| rijmasker-pointer 10h:11h (tabel `4B2B`) | `0756`–`0764` | `fr_setup`, identiek |
| verschil per rij: masker & (nieuw ^ oud), hoge en lage byte | `07AE`–`07E4` | identiek, zelfde bytevolgorde |
| kleur: (nieuw & masker) ≠ 0, omgekeerd met 21h.7 → 21h.6 | `07EB`–`0815` | identiek |
| `056B` = rij, `056C` = kolom, `SETB 21h.4`, idle tot de ISR hem wist | `0817`–`081F` | identiek (`MOV PCON,#81h`) |
| `0554` = 0 aan het eind, getoond beeld (`07AE`) bijwerken | ja | ja (alleen gewijzigde kolommen) |

Verder gecontroleerd:

- `0x0692` schrijft per dot ook het rijmasker naar xdata `08C8/08C9`, maar alleen `0x0692` zelf leest dat;
  de ISR niet.
- Stack begint op `SP = 4Ah`, boven alles wat de ISR gebruikt (`36h:37h` kolomtabel, `10h:11h`).
- Beide interrupts draaien in registerbank 1; B, DPTR en PSW worden in de wrappers bewaard.
- Na de verversing schrijft de hoofdlus latch `0x0000` alleen via de RAM-schaduw terug (zelfde rij- en
  kleurbits) en komt hij niet aan T0 (P3.4). Dat de snelle routine terugkeert terwijl de laatste puls nog
  loopt, maakt dus niets uit.

**Conclusie:** per dot zet `fast_refresh` precies dezelfde waarden klaar als `0x0692`, en de puls komt uit
dezelfde ISR. De oorzaak zit niet in de per-dot-logica.

## 2. Timing: geen tick van 1 ms

[`analyse.md`](analyse.md) §2.1 zegt "1 ms tick, één dot per milliseconde, pulsduur ≈ 1 ms". Dat klopt niet:

- Timer0 draait in mode 1 en wordt pas **aan het eind van de ISR** herladen (`068B`/`068E`). De periode is
  500 tellen plus de ISR-duur tot dat punt, ongeveer 700–740 cycli: **~1,45 ms** bij 6 MHz.
- Na de flank `CLR T0` (`065F`, ~150–170 cycli na de overloop) blijft E laag tot `SETB T0` aan het begin van
  de volgende ISR: puls **~1,1 ms**, E uit **~0,3 ms**.
- De eigen benchmark bevestigt dit: 849 dots in 1,19 s (= 1,40 ms per dot) en "langste dotpuls 1,11 ms".
- Zowel de originele tekstverversing (alle 1792 dots, 1,41 ms per dot in de benchmark) als `fast_refresh`
  (1,40 ms per dot) geven één puls per tick. Qua pulsreeks verschillen ze nauwelijks.

## 3. FP2800A-datasheet

[`manuals/FP2800A-datasheet.pdf`](manuals/FP2800A-datasheet.pdf) (FP Electronics / Mark IV, F-P105 B E, 2003).

| Datasheet | Firmware / hardware | Oordeel |
|---|---|---|
| ENABLE pin 24, DATA 23, A0/A1/A2 19/18/20, B0/B1 21/22 | klopt met de CN3-pinout | ✓ |
| "A simple external RC timing circuit protects the output from staying on too long" | C1 0,33 µF + R1 15 kΩ op de module (τ ≈ 5 ms) | ✓ bewuste beveiliging |
| V_IH ≥ 2,0 V, V_IL ≤ 0,8 V; ENABLE-ingangsstroom max. −10 µA | na een flank van 5 V blijft ENABLE ~τ·ln(5/2) ≈ 4,5 ms boven 2 V; puls ~1,1 ms | ✓ voor één losse puls |
| spoelstroom normaal 350 mA, max. 370 mA | LM317 met R20 = 3,38 Ω: 1,25 / 3,38 = 370 mA | ✓ begrenzing precies op de FP2800A afgestemd |
| voedingsspanning normaal 26 V, max. 27,5 V | 18 V | ✓ |
| **t_SE (adres/data stabiel vóór ENABLE): 50 µs max** | ISR: latch 1 (kolom + DATA) op `05EC`, dan `SJMP`, `CLR 21h.4`, 3× `SETB T0`, `CLR T0` ≈ 7 cycli = **~14 µs** (7 µs bij 12 MHz) | ⚠ overschreden door de originele ISR, dus in beide routines |
| t_ON ≤ 50 µs, **t_OFF ≤ 150 µs** | na `SETB T0` (`0568`) wordt latch 0 al na ~70 µs herschreven | ⚠ uitgang mag nog aan zijn; rijdrivers zijn wel direct uit (74HC238, E3 = AEN) |
| **duty cycle max. 50 % bij 25 °C, 25 % bij 80 °C** | ~1,1 ms per ~1,45 ms ≈ **76 %** zolang er dot na dot wordt omgezet | ⚠ overschreden, door beide routines en door de tekstverversing |
| "Operating Frequency 5 Hz" | waarde staat in de MIN-kolom; betekenis onduidelijk | ? niet gebruikt |

### Mogelijk mechanisme: RC-enable en duty cycle

C1 blokkeert gelijkspanning. Heeft de ENABLE-ingang **geen** klemdiode naar GND, dan wordt het gemiddelde
op pin 24 0 V en zakt het hoge niveau bij duty D naar ongeveer 5·(1 − D) V. Bij 76 % is dat ~1,2 V, onder
V_IH: na een paar keer τ (een handvol pulsen) doet de driver niets meer. Onder ~60 % blijft het werken, wat
aansluit bij de 50 %-grens in het datasheet.

Het datasheet noemt alleen klemdiodes op de **uitgangen**, niet op ENABLE, dus dit valt niet uit te sluiten.
Maar het verklaart het verschil niet: de originele tekstverversing pulst even dicht op elkaar en werkt op
hardware. Óf de ENABLE-ingang klemt wel, óf de tekstverversing is op hardware minder perfect dan
aangenomen (valt niet op, omdat elke tekstverversing alle dots opnieuw pulst).

## 4. Aannames die niet (helemaal) klopten

1. **"Werkt in de emulator"** zegt alleen iets over de logica. [`emulator/core/azr802.js`](../emulator/core/azr802.js)
   telt een puls als E ≥ 100 µs laag is (`minPulseUs`). Niet gemodelleerd: de RC-enable per module, de
   FP2800A-drempels en t_SE/t_OFF, de 18 V-voeding (LM317, 1 µF aan de uitgang), de spoelinductie en de
   batterijgebufferde RAM (de emulator begint op 0).
2. **"`aD` laat zien dat de pulsen worden afgehandeld"** bewijst alleen dat de tellers lopen en dat 21h.4
   gewist is, niet wat er in latch 0/1/2 stond of hoe lang T0 laag was.
3. **Rekentijd per verversing met `0x0692`:** de README's noemen "~0,3 s", de asm en commit `837443e` 645 ms.
   Een telling komt op ~0,65–0,75 s.
4. **Opnieuw versturen:** de patch-README zegt "stuur na ~50 ms opnieuw" als `a0` uitblijft, maar
   [flipdot-ret-mqtt](https://github.com/sebastius/flipdot-ret-mqtt) (`flipdot_mqtt.ino`) publiceert dan
   alleen `timeout` en gaat door. Bij een volle wachtrij (2 plaatsen) raken pixels stil kwijt.
5. **De hardwaretest van `fast_refresh` is niet doorslaggevend.** De eerste "faal" viel op kolom 0–27 (die
   module ontbreekt). Daarna is de snelle versie één keer getest op zichtbare kolommen, tussen `51464de`
   (20:58) en `ae76f60` (21:05), in dezelfde commit als de kolomverschuiving, met een UV-wisbare M27C512.
   Niet vastgelegd is welke image er toen echt in zat en of er gewist en geverifieerd is.

## Aanvulling 18 november 2026 (uit de hardwaresessie van 17 november)

1. **De hardwaretest van `fast_refresh` was wel doorslaggevend.** De snelle build `51464de` is gebrand na een
   blanco-check en daarna losgelezen: gelijk aan het bestand (MD5 `686ed99b…`). Getest op zichtbare kolommen:
   10× pixel (4,0) wisselen (kolom 32), de kat vanaf x = 0 en 10× pixel (44,1). Er klapte niets om. Met de
   0692-build (`ae76f60`, MD5 `09923801…`, ook geverifieerd) werkten dezelfde pixel en de kat wel.
2. **De RC-enable/duty-cycle-verklaring dekt de losse pixel niet.** Bij het wisselen zat er 1 s tussen de
   pulsen (duty ≈ 0), en toch werkte `fast_refresh` niet. Voor reeksen kan het meespelen, maar het verschil
   bij één losse puls verklaart het niet.
3. **Rekentijd 0692:** een volledige doorloop is ~0,65–0,75 s, maar de eerste klik komt eerder omdat de routine
   kolom voor kolom werkt (emulator: ~0,19 s op kolom 28, benchmark ~0,33 s op kolom 56). De README's zijn
   aangepast naar "tot ~0,7 s".
4. **Testversie met verversingsmodi** (commit na `c4bd712`): `aM1<n>` kiest de verversing zonder opnieuw te
   branden: 0 = `0x0692`, 1 = `fast_refresh`, 2 = + ~3 ms na de laatste puls, 3 = + ~3 ms na elke puls (open
   punt 2), 4 = zonder `fr_setup`, 5 = 2+3, 6 = eerst ~300 ms wachten, 7 = 2+3+6. `aD1` toont de modus in byte 28.

## Open punten

1. Brand de snelle build (verifiëren na het branden), stuur één pixel op een zichtbare kolom (bijv.
   `aP1040051`) en meet met een scoop op TP E, TP EZ, TP ES **en op pin 24 van de FP2800A** (na C1). Doe
   hetzelfde met de 0692-build, en ook tijdens een reeks pulsen.
2. Zakt het hoge niveau op pin 24 onder 2 V tijdens een reeks, dan is het de RC-enable/duty cycle. Snelle
   proef zonder scoop: laat `fast_refresh` na elke puls één tick leeg (nog één keer `idle` na het wissen van
   21h.4), zodat de duty onder ~40 % komt.
3. `aD1`-dump van de hardware na `aT10` en die ene pixel, voor beide builds.
4. Los daarvan: in de ISR meer tijd tussen latch 1 en `CLR T0` inbouwen, zodat aan t_SE = 50 µs wordt voldaan
   (geldt ook voor het origineel).
5. Emulatorvergelijking van de latch-waarden per puls (0692 tegenover fast) is nog niet gedraaid.
