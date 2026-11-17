#!/usr/bin/env node
// Test ASFP-bitmap.bin in de emulator.  node firmware-patches/asfp-bitmap/test.js
import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { AZR802, IbisReceiver } from '../../emulator/core/azr802.js';

const here = (f) => fileURLToPath(new URL(f, import.meta.url));
const rom = new Uint8Array(readFileSync(here('./ASFP-bitmap.bin')));
let failed = 0, passed = 0;
const check = (name, cond, detail = '') => {
  if (cond) { passed++; console.log('  ok   ' + name); } else { failed++; console.log('  FOUT ' + name + (detail ? ' — ' + detail : '')); }
};

function boot(address = 1) {
  const b = new AZR802({ rom, address });
  b.replies = [];
  const rx = new IbisReceiver((t, ok) => b.replies.push(ok ? t : '!' + t));
  b.on('tx', (x) => rx.push(x));
  b.flipLog = [];
  b.on('flip', (c, r, col, us) => b.flipLog.push({ c, r, col, us, t: b.time }));
  b.runSeconds(3);
  return b;
}
const dot = (b, x, y) => b.dots[y * b.cols + x];
const yellowCount = (b) => b.dots.reduce((a, v) => a + v, 0);
// stuur, wacht tot het display stil is (geen flips meer gedurende 0,5 s), max 'max' s
function sendAndSettle(b, tele, max = 15) {
  b.flipLog.length = 0; b.replies.length = 0;
  const t0 = b.time;
  b.sendTelegram(tele);
  let quiet = 0, last = 0;
  while (b.time - t0 < max) {
    b.runSeconds(0.1);
    if (b.flipLog.length === last) quiet += 0.1; else { quiet = 0; last = b.flipLog.length; }
    // minimaal: verzendtijd (11 bits per teken bij 1200 Bd) + 3 s verwerking
    if (quiet >= 0.6 && b.time - t0 > (tele.length + 2) * 11 / 1200 + 3) break;
  }
  const flips = b.flipLog.length;
  const first = flips ? b.flipLog[0].t - t0 : null;
  const lastT = flips ? b.flipLog[flips - 1].t - t0 : null;
  return { flips, first, last: lastT, maxPulse: Math.max(0, ...b.flipLog.map((f) => f.us)) };
}

console.log('bestaand gedrag');
{
  const b = boot();
  b.sendTelegram('aV1'); b.runSeconds(1);
  check('versie nog F00293', b.replies.includes('aVF00293'), JSON.stringify(b.replies));
  const r = sendAndSettle(b, 'aA11001\nHallo\n\n\n');
  check('vrije tekst werkt nog (a0 + dots)', b.replies.includes('a0') && yellowCount(b) > 20, `${JSON.stringify(b.replies)} geel=${yellowCount(b)}`);
  b.sendTelegram('aT11'); b.runSeconds(6);
  check('testbeeld geel werkt nog', yellowCount(b) === 112 * 16, String(yellowCount(b)));
}

console.log('aP: pixels');
{
  const b = boot();
  const r = sendAndSettle(b, 'aP1' + '000001' + '111151' + '056081');
  check('antwoord a0', b.replies.includes('a0'), JSON.stringify(b.replies));
  check('drie pixels geel op (0,0) (111,15) (56,8)', dot(b, 0, 0) && dot(b, 111, 15) && dot(b, 56, 8) && yellowCount(b) === 3, `geel=${yellowCount(b)}`);
  check('partial update: precies 3 dots omgezet', r.flips === 3, `flips=${r.flips}`);
  console.log(`       eerste flip na ${r.first?.toFixed(3)} s, laatste na ${r.last?.toFixed(3)} s, langste puls ${r.maxPulse.toFixed(0)} µs`);
  b.runSeconds(120);
  check('pixels staan na 120 s nog', dot(b, 0, 0) && dot(b, 111, 15) && dot(b, 56, 8) && yellowCount(b) === 3, `geel=${yellowCount(b)}`);
  const r2 = sendAndSettle(b, 'aP1' + '056080');
  check('pixel weer zwart, 1 flip', !dot(b, 56, 8) && r2.flips === 1 && yellowCount(b) === 2, `flips=${r2.flips}`);
  const r3 = sendAndSettle(b, 'aP1' + '200001' + '000201' + '00000x');
  check('buiten bereik en ongeldige kleur: niets omgezet', r3.flips === 0 && yellowCount(b) === 2, `flips=${r3.flips}`);
  const r4 = sendAndSettle(b, 'aP2' + '005051');
  check('ander adres: genegeerd, geen antwoord', r4.flips === 0 && b.replies.length === 0);
  const r5 = sendAndSettle(b, 'aP0' + '005051');
  check('adres 0 (allen): uitgevoerd zonder antwoord', dot(b, 5, 5) && b.replies.length === 0);
}

console.log('aB: bitmap');
{
  const b = boot();
  // diagonaal: kolom x heeft bit (x % 16)
  let hex = '';
  for (let x = 0; x < 56; x++) hex += (1 << (x % 16)).toString(16).padStart(4, '0').toUpperCase();
  const r = sendAndSettle(b, 'aB1000' + hex);
  let ok = true;
  for (let x = 0; x < 56; x++) for (let y = 0; y < 16; y++) if (dot(b, x, y) !== (y === x % 16 ? 1 : 0)) ok = false;
  check('56 kolommen diagonaal correct', ok && yellowCount(b) === 56, `geel=${yellowCount(b)}`);
  check('partial update: 56 flips', r.flips === 56, `flips=${r.flips}`);
  console.log(`       telegram ${('aB1000' + hex).length + 2} tekens, eerste flip na ${r.first?.toFixed(3)} s, klaar na ${r.last?.toFixed(3)} s, langste puls ${r.maxPulse.toFixed(0)} µs`);
  const r2 = sendAndSettle(b, 'aB1056' + 'ffff'.repeat(56));
  check('tweede helft geel (kleine letters hex)', yellowCount(b) === 56 + 56 * 16 && r2.flips === 56 * 16, `geel=${yellowCount(b)} flips=${r2.flips}`);
  const r3 = sendAndSettle(b, 'aB1110' + 'FFFF'.repeat(5));
  check('kolommen voorbij de rand genegeerd', r3.flips === 0, `flips=${r3.flips}`);
  const r4 = sendAndSettle(b, 'aB1000' + '00G0');
  check('ongeldige hex: niets geschreven', r4.flips === 0, `flips=${r4.flips}`);
}

console.log('volledige bitmap in twee telegrammen');
{
  const b = boot();
  // schaakbord van 2x2: kolom x heeft patroon afhankelijk van x
  const word = (x) => ((x >> 1) & 1) ? 0xCCCC : 0x3333;
  const part = (x0, n) => { let h = ''; for (let x = x0; x < x0 + n; x++) h += word(x).toString(16).padStart(4, '0'); return h; };
  b.flipLog.length = 0; b.replies.length = 0;
  b.sendTelegram('aB1000' + part(0, 56));
  b.sendTelegram('aB1056' + part(56, 56));          // direct erachteraan, zonder te wachten
  b.runSeconds(12);
  let ok = true;
  for (let x = 0; x < 112; x++) for (let y = 0; y < 16; y++) if (dot(b, x, y) !== ((word(x) >> y) & 1)) ok = false;
  check('112 kolommen correct na twee telegrammen achter elkaar', ok, `geel=${yellowCount(b)}`);
  check('twee keer a0', b.replies.filter((r) => r === 'a0').length === 2, JSON.stringify(b.replies));
  check('alleen veranderde dots: 896 flips', b.flipLog.length === 896, String(b.flipLog.length));
}

console.log('volledige bitmap in één telegram (455 tekens)');
{
  const b = boot();
  const word = (x) => (x * 0x0101 + 0x1234) & 0xFFFF;   // willekeurig maar voorspelbaar
  let hex = ''; for (let x = 0; x < 112; x++) hex += word(x).toString(16).padStart(4, '0').toUpperCase();
  const tele = 'aB1000' + hex;
  const r = sendAndSettle(b, tele, 20);
  let ok = true, want = 0;
  for (let x = 0; x < 112; x++) for (let y = 0; y < 16; y++) { const v = (word(x) >> y) & 1; want += v; if (dot(b, x, y) !== v) ok = false; }
  check(`${tele.length + 1} tekens: alle 112 kolommen correct`, ok, `geel=${yellowCount(b)} verwacht=${want}`);
  check('antwoord a0', b.replies.includes('a0'), JSON.stringify(b.replies));
  check('alleen veranderde dots omgezet', r.flips === want, `flips=${r.flips} verwacht=${want}`);
  console.log(`       eerste flip na ${r.first?.toFixed(2)} s, klaar na ${r.last?.toFixed(2)} s`);
  const r2 = sendAndSettle(b, 'aA11001\n' + 'x'.repeat(260) + '\n\n\n');
  check('gewoon telegram > 250 tekens wordt nog steeds genegeerd', b.replies.length === 0 && r2.flips === 0, `${JSON.stringify(b.replies)} flips=${r2.flips}`);
  const r3 = sendAndSettle(b, 'aB1000' + 'F'.repeat(4 * 125));
  check('aB boven 500 tekens wordt genegeerd', b.replies.length === 0 && r3.flips === 0, `${JSON.stringify(b.replies)} flips=${r3.flips}`);
}

console.log('aU: alles opnieuw');
{
  const b = boot();
  sendAndSettle(b, 'aP1' + '010051');
  const r = sendAndSettle(b, 'aU1', 20);
  check('alle 1792 dots opnieuw omgezet', r.flips === 1792, `flips=${r.flips}`);
  check('beeld onveranderd', dot(b, 10, 5) && yellowCount(b) === 1);
  console.log(`       klaar na ${r.last?.toFixed(2)} s`);
}

console.log('samenspel met tekst');
{
  const b = boot();
  sendAndSettle(b, 'aA11001\nPagina een\n\n\nPagina twee\n\n\n');
  sendAndSettle(b, 'aB1000' + '0F0F'.repeat(28));
  let bm = true;
  for (let x = 0; x < 28; x++) for (let y = 0; y < 16; y++) if (dot(b, x, y) !== ((0x0F0F >> y) & 1)) bm = false;
  check('bitmap staat over de wisseltekst heen', bm);
  const snap = b.dots.slice();
  b.runSeconds(120);
  let changed = 0; for (let i = 0; i < snap.length; i++) if (snap[i] !== b.dots[i]) changed++;
  console.log(`       na 120 s: ${changed} dots veranderd t.o.v. direct na de bitmap`);
  check('bitmap blijft staan (geen wisseltekst eroverheen)', changed === 0, `${changed} dots veranderd`);
  const r = sendAndSettle(b, 'aA11001\nTerug naar tekst\n\n\n');
  check('nieuwe tekst neemt het display weer over', b.replies.includes('a0') && r.flips > 0);
  check('geen watchdog-resets', b.stats.wdResets === 0);
}

console.log('bitmapmodus');
{
  const b = boot();
  sendAndSettle(b, 'aA10000\nTEKST\n\n\n');
  const textDots = yellowCount(b);
  const r = sendAndSettle(b, 'aP1' + '000001');
  check('pixel op bestaande tekst: tekst blijft, 1 flip', yellowCount(b) === textDots + 1 && r.flips === 1, `geel=${yellowCount(b)} (tekst ${textDots}) flips=${r.flips}`);
  b.sendTelegram('a1'); b.runSeconds(1);
  sendAndSettle(b, 'aP1' + '001001');
  check('statusvraag beëindigt bitmapmodus niet', dot(b, 0, 0) && dot(b, 1, 0) && yellowCount(b) === textDots + 2, `geel=${yellowCount(b)}`);
  sendAndSettle(b, 'aA10000\nANDERS\n\n\n');
  const t2 = yellowCount(b);
  check('nieuwe tekst wist de pixels', !dot(b, 0, 0) && !dot(b, 1, 0));
  const r2 = sendAndSettle(b, 'aP1' + '000001');
  check('daarna begint bitmapmodus vanaf de nieuwe tekst', yellowCount(b) === t2 + 1 && r2.flips === 1, `geel=${yellowCount(b)} flips=${r2.flips}`);
  sendAndSettle(b, 'aT10');
  check('testbeeld werkt in/na bitmapmodus', yellowCount(b) === 0, String(yellowCount(b)));
}

console.log(`\n${passed} geslaagd, ${failed} mislukt`);
process.exit(failed ? 1 : 0);
