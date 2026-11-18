#!/usr/bin/env node
// Benchmark in de emulator: origineel ASFP vs ASFP-bitmap 6 MHz en 12 MHz.
//   node firmware-patches/asfp-bitmap/benchmark.js            tabel in Markdown
// Alle tijden zijn gemeten vanaf het begin van het versturen (dus inclusief verzendtijd),
// tenzij anders vermeld. Alleen emulatie, geen metingen op echte hardware.
import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { AZR802, IbisReceiver } from '../../emulator/core/azr802.js';

const repo = (f) => fileURLToPath(new URL('../../' + f, import.meta.url));
const FIRMWARES = [
  { name: 'origineel ASFP', file: 'firmware/ASFP.bin', osc: 6e6, baud: 1200, bitmap: false },
  { name: 'bitmap 6 MHz', file: 'firmware-patches/asfp-bitmap/ASFP-bitmap-6MHz-15625.bin', osc: 6e6, baud: 15625, bitmap: true },
  { name: 'bitmap 12 MHz', file: 'firmware-patches/asfp-bitmap/ASFP-bitmap-12MHz-31250.bin', osc: 12e6, baud: 31250, bitmap: true },
];

function boot(fw) {
  const rom = new Uint8Array(readFileSync(repo(fw.file)));
  if (rom.length > 0x5FFF && fw.file.includes("bitmap")) rom[0x5FFF] = 0;   // kolomverschuiving uit: meten over het hele display
  const b = new AZR802({ rom, address: 1, osc: fw.osc });
  b.replies = [];
  const rx = new IbisReceiver((t, ok) => b.replies.push({ t: b.time, s: ok ? t : '!' + t }));
  b.on('tx', (x) => rx.push(x));
  b.flips = [];
  b.on('flip', (c, r, col, us) => b.flips.push({ t: b.time, us }));
  return b;
}

// versturen en meten: antwoord, eerste en laatste flip (stil = 1 s geen flips na de laatste)
function measure(b, tele, maxS = 30) {
  b.flips.length = 0; b.replies.length = 0;
  const t0 = b.time;
  b.sendTelegram(tele);
  let quiet = 0, n = 0;
  while (b.time - t0 < maxS) {
    b.runSeconds(0.01);
    if (b.flips.length === n) quiet += 0.01; else { quiet = 0; n = b.flips.length; }
    if (quiet >= 1.0 && (n > 0 || b.time - t0 > 6)) break;
  }
  return {
    reply: b.replies.length ? b.replies[0].t - t0 : null,
    first: b.flips.length ? b.flips[0].t - t0 : null,
    done: b.flips.length ? b.flips[b.flips.length - 1].t - t0 : null,
    flips: b.flips.length,
    pulse: b.flips.length ? Math.max(...b.flips.map((f) => f.us)) : null,
  };
}

const results = {};
for (const fw of FIRMWARES) {
  const r = {};
  // opstarten: eerste antwoord op een statusvraag (elke 20 ms gevraagd) en einde van de opstartverversing
  {
    const b = boot(fw);
    let firstAnswer = null;
    while (b.time < 10 && firstAnswer === null) {
      b.sendTelegram('a1');
      const t = b.time; b.runSeconds(0.02 + 6 * 11 / fw.baud);
      if (b.replies.length) firstAnswer = b.replies[0].t;
    }
    b.runSeconds(5);
    r.bootAnswer = firstAnswer;
    r.bootDone = b.flips.length ? b.flips[b.flips.length - 1].t : null;
  }
  const b = boot(fw);
  b.runSeconds(6);
  r.status = measure(b, 'a1', 2).reply;
  r.version = measure(b, 'aV1', 2).reply;
  r.text1 = measure(b, 'aA11001\nHallo\n\n\n');
  r.text2 = measure(b, 'aA11001\nCentraal Station\nvia Blaak\n\n');
  r.pages = measure(b, 'aA11001\nEen\n\n\nTwee\n\n\n', 8);
  r.testYellow = measure(b, 'aT11');
  r.testBlack = measure(b, 'aT10');
  if (fw.bitmap) {
    r.pixel = measure(b, 'aP1056081');
    let hex = ''; for (let x = 0; x < 112; x++) hex += ((x * 0x0101 + 0x1234) & 0xFFFF).toString(16).padStart(4, '0');
    r.bitmap = measure(b, 'aB1000' + hex);
    r.bitmapSame = measure(b, 'aB1000' + hex);           // zelfde beeld nogmaals: niets te doen
    r.full = measure(b, 'aU1');
    // reeks pixels, steeds wachten op a0
    const t0 = b.time; let acks = 0;
    for (let i = 0; i < 100; i++) {
      const n0 = b.replies.length, ts = b.time;
      b.sendTelegram('aP1' + String(i % 112).padStart(3, '0') + String(i % 16).padStart(2, '0') + '1');
      while (b.replies.length === n0 && b.time - ts < 0.2) b.runSeconds(0.0005);
      if (b.replies.length > n0) acks++;
    }
    r.pixelRate = acks / (b.time - t0);
    r.pixelAcks = acks;
  }
  r.wd = b.stats.wdResets;
  results[fw.name] = r;
}

// ---------- tabel ----------
const f = (v, d = 2) => (v === null || v === undefined ? '–' : v.toFixed(d) + ' s');
const ms = (v) => (v === null || v === undefined ? '–' : (v * 1000).toFixed(1) + ' ms');
const rows = [
  ['Opstarten: eerste antwoord op statusvraag', (r) => f(r.bootAnswer)],
  ['Opstarten: opstartverversing klaar', (r) => f(r.bootDone)],
  ['Statusvraag `a1` → `a0`', (r) => ms(r.status)],
  ['Versievraag `aV1` → antwoord', (r) => ms(r.version)],
  ['Tekst "Hallo": eerste flip', (r) => f(r.text1.first)],
  ['Tekst "Hallo": klaar', (r) => f(r.text1.done)],
  ['Tekst 2 regels: eerste flip', (r) => f(r.text2.first)],
  ['Tekst 2 regels: klaar', (r) => f(r.text2.done)],
  ['Testbeeld geel `aT11`: klaar', (r) => f(r.testYellow.done)],
  ['Testbeeld zwart `aT10`: klaar', (r) => f(r.testBlack.done)],
  ['Eén pixel `aP`: eerste flip', (r) => (r.pixel ? f(r.pixel.first, 3) : 'n.v.t.')],
  ['Volledige bitmap 112×16 `aB`: eerste flip', (r) => (r.bitmap ? f(r.bitmap.first) : 'n.v.t.')],
  ['Volledige bitmap 112×16 `aB`: klaar', (r) => (r.bitmap ? f(r.bitmap.done) + ` (${r.bitmap.flips} dots)` : 'n.v.t.')],
  ['Zelfde bitmap nogmaals: antwoord / flips', (r) => (r.bitmapSame ? `${ms(r.bitmapSame.reply)} / ${r.bitmapSame.flips}` : 'n.v.t.')],
  ['Alles opnieuw `aU`: klaar', (r) => (r.full ? f(r.full.done) + ` (${r.full.flips} dots)` : 'n.v.t.')],
  ['Pixeltelegrammen per seconde (wachten op `a0`)', (r) => (r.pixelRate ? `${r.pixelRate.toFixed(0)} /s (${r.pixelAcks}/100 a0)` : 'n.v.t.')],
  ['Langste dotpuls', (r) => (r.text2.pulse ? (r.text2.pulse / 1000).toFixed(2) + ' ms' : '–')],
  ['Watchdog-resets', (r) => String(r.wd)],
];
const names = FIRMWARES.map((x) => x.name);
console.log(`| | ${FIRMWARES.map((x) => `${x.name}<br>${x.osc / 1e6} MHz · ${x.baud} Bd`).join(' | ')} |`);
console.log(`|---|${names.map(() => '---').join('|')}|`);
for (const [label, fn] of rows) console.log(`| ${label} | ${names.map((n) => fn(results[n])).join(' | ')} |`);
