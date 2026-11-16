#!/usr/bin/env bash
# Importeer de LAWO-firmwares in een Ghidra-project, analyseer en exporteer naar tekst.
# Gebruik: tools/ghidra/run_ghidra.sh            (alle firmwares)
#          tools/ghidra/run_ghidra.sh ASFP.bin   (één bestand, opnieuw)
# Vereist Ghidra 12.x (JDK 25). Pad via GHIDRA=..., standaard ~/tools/ghidra_12.2_PUBLIC.
set -euo pipefail
GHIDRA=${GHIDRA:-$HOME/tools/ghidra_12.2_PUBLIC}
HERE=$(cd "$(dirname "$0")" && pwd)
REPO=$(cd "$HERE/../.." && pwd)
ROMDIR="$REPO/firmware"
PROJ="$REPO/build/ghidra_project"      # niet in git
OUT="$REPO/analysis/ghidra_export"
mkdir -p "$PROJ" "$OUT"

FILES=("$@")
[ ${#FILES[@]} -eq 0 ] && FILES=(ASFP.bin AZIPZR1.BIN AZR-12C.BIN dvb_azrfr51v16.bin MLAWO_RET_RET60.PLM51_18-11-92.bin)

for f in "${FILES[@]}"; do
  echo "=== $f"
  "$GHIDRA/support/analyzeHeadless" "$PROJ" LAWO \
      -import "$ROMDIR/$f" -overwrite \
      -loader BinaryLoader -loader-baseAddr 0 \
      -processor 8051:BE:16:default \
      -scriptPath "$HERE/scripts" \
      -preScript LawoSetup.java \
      -postScript LawoJumpTables.java \
      -postScript LawoExport.java "$OUT" \
      2>&1 | grep -E "INFO .*(LawoSetup|LawoJumpTables|LawoExport)|ERROR|Exception|vector|functies" || true
done
echo "Klaar. Uitvoer in $OUT, project in $PROJ (open met $GHIDRA/ghidraRun)."
