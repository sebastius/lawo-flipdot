# Tekst-EPROMs

| Bestand | Bij firmware | Formaat |
|---|---|---|
| `RET0902_14-10-2002_C256_05F55CD.bin` | `MLAWO_RET…` | TED800-stijl: ASCII-records gescheiden door `CR LF`. Het recordnummer is het bestemmingsnummer; record 1001+n is lijn n. De eerste letter van een blok is een opmaak-/fontcode, `0x03` betekent tweede regel en `0x04` betekent wisseltekst. Bevat teksten van de RET (Rotterdam). |
| `RET0902_teksten.txt` | – | Alle gevulde records uit RET0902, leesbaar gemaakt. |
| `front.bin` | `AZR-12C` (waarschijnlijk) | `FORM`-stijl ("tedplus"): een `FORM0`-header met vrij gepositioneerde tekstblokken. Bevat bestemmingen in 's-Hertogenbosch. |

Zie [`../docs/analyse.md`](../docs/analyse.md), §4.
