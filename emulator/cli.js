#!/usr/bin/env node
// Commandline-emulator AZR 802/24 + flipdotdisplay.
//
//   node emulator/cli.js --rom firmware/ASFP.bin [opties] --script "<stappen>"
//
// Opties:
//   --rom <bestand>        firmware (27C256)                  (verplicht)
//   --rm2 / --rm3 <bestand> tekst-EPROM in RM2 (bank 0) / RM3 (bank 1); anders RAM
//   --addr <1-15>          displayadres (adresbruggen)          (standaard 1)
//   --cols / --rows        displaygrootte                       (standaard 112 x 16)
//   --cpu 80C31|80C32      (standaard 80C31)    --osc <Hz>      (standaard 6000000)
//   --s1 0|1 --s2 0|1      pinniveau P1.4 / P1.5                (standaard s1=1, s2=0)
//   --quiet                geen live-uitvoer van seriële antwoorden
//   --physics none|rc|clamp fysiek model: RC-enable zonder (rc) of met klemdiode (clamp); standaard none
//   --strict               met --physics: puls met t_SE < 50 us telt niet
//
// Scriptstappen, gescheiden door ';':
//   wait <s>               emuleer <s> seconden
//   send <telegram>        IBIS-telegram, CR + checksum worden toegevoegd (\n = LF)
//   raw <tekst>            losse tekens zonder CR/checksum
//   press yellow|black <s> knop ingedrukt houden
//   set s1|s2|addr <v>     schakelaar/adres wijzigen (adres pas na reset actief voor firmware)
//   reset                  CPU-reset (zoals rode knop)
//   show                   display als tekst tonen
//   status                 tijd, LEDs, 7-segment, statistieken

import { readFileSync } from 'node:fs';
import { AZR802, IbisReceiver, decode7seg } from './core/azr802.js';

function parseArgs(argv) {
  const o = {};
  for (let i = 0; i < argv.length; i++) {
    const a = argv[i];
    if (!a.startsWith('--')) continue;
    const k = a.slice(2);
    if (k === 'quiet' || k === 'strict') { o[k] = true; continue; }
    o[k] = argv[++i];
  }
  return o;
}

export function renderAscii(board) {
  const lines = [];
  lines.push('+' + '-'.repeat(board.cols) + '+');
  for (let r = 0; r < board.rows; r++) {
    let s = '|';
    for (let c = 0; c < board.cols; c++) s += board.dots[r * board.cols + c] ? '#' : '.';
    lines.push(s + '|');
  }
  lines.push('+' + '-'.repeat(board.cols) + '+');
  return lines.join('\n');
}

function unescape(s) {
  return s.replace(/\\n/g, '\n').replace(/\\r/g, '\r').replace(/\\x([0-9a-fA-F]{2})/g, (_, h) => String.fromCharCode(parseInt(h, 16)));
}

const args = parseArgs(process.argv.slice(2));
if (!args.rom) { console.error('gebruik: node emulator/cli.js --rom <firmware> --script "wait 2; show"'); process.exit(1); }

const load = (f) => (f ? new Uint8Array(readFileSync(f)) : undefined);
const board = new AZR802({
  rom: load(args.rom), rm2: load(args.rm2), rm3: load(args.rm3),
  address: Number(args.addr ?? 1), cols: Number(args.cols ?? 112), rows: Number(args.rows ?? 16),
  cpuType: args.cpu || '80C31', osc: Number(args.osc ?? 6000000),
  s1: Number(args.s1 ?? 1), s2: Number(args.s2 ?? 0),
  physics: (args.physics && args.physics !== 'none') ? { clamp: args.physics === 'clamp', strict: !!args.strict } : null,
});

const rx = new IbisReceiver((t, csOk, parOk) => {
  if (!args.quiet) console.log(`[${board.time.toFixed(3)} s] display -> ${JSON.stringify(t)}${csOk ? '' : ' (checksum fout)'}${parOk ? '' : ' (pariteit fout)'}`);
});
board.on('tx', (b) => rx.push(b));
board.on('log', (m) => { if (!args.quiet) console.log(`[${board.time.toFixed(3)} s] ${m}`); });

const steps = (args.script || 'wait 3; show; status').split(';').map((s) => s.trim()).filter(Boolean);
for (const step of steps) {
  const [cmd, ...rest] = step.split(/\s+/);
  const arg = step.slice(cmd.length).trim();
  switch (cmd) {
    case 'wait': board.runSeconds(Number(arg)); break;
    case 'send': board.sendTelegram(unescape(arg)); break;
    case 'raw': board.sendRaw(unescape(arg)); break;
    case 'press': {
      const [which, secs] = rest;
      board.buttons[which] = true; board.runSeconds(Number(secs || 0.5)); board.buttons[which] = false; break;
    }
    case 'set': {
      const [what, v] = rest;
      if (what === 'addr') board.address = Number(v); else board[what] = Number(v);
      break;
    }
    case 'reset': board.cpu.reset(); break;
    case 'show': console.log(renderAscii(board)); break;
    case 'status': {
      const yellow = board.dots.reduce((a, b) => a + b, 0);
      console.log(`t=${board.time.toFixed(3)} s  pc=${board.cpu.pc.toString(16)}  LEDs=${JSON.stringify(board.leds())}  7seg='${decode7seg(board.latch[3])}'  geel=${yellow}/${board.dots.length}  ${JSON.stringify(board.stats)}`);
      break;
    }
    default: console.error('onbekende stap: ' + step); process.exit(1);
  }
}
