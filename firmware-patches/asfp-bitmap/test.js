#!/usr/bin/env node
// Test de ASFP-bitmap-varianten in de emulator.   node firmware-patches/asfp-bitmap/test.js
import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { AZR802, IbisReceiver } from '../../emulator/core/azr802.js';

const here = (f) => fileURLToPath(new URL(f, import.meta.url));
const VARIANTS = [
  { file: 'ASFP-bitmap-6MHz-15625.bin', osc: 6_000_000, baud: 15625 },
  { file: 'ASFP-bitmap-12MHz-31250.bin', osc: 12_000_000, baud: 31250 },
];
let failed = 0, passed = 0;
const check = (name, cond, detail = '') => {
  if (cond) { passed++; console.log('  ok   ' + name); } else { failed++; console.log('  FOUT ' + name + (detail ? ' — ' + detail : '')); }
};

for (const V of VARIANTS) {
  const rom = new Uint8Array(readFileSync(here('./' + V.file)));
  const txTime = (tele) => (tele.length + 2) * 11 / V.baud;     // 11 bits per teken (7E2)
  console.log(`\n===== ${V.file}`);

  const boot = (address = 1) => {
    const b = new AZR802({ rom, address, osc: V.osc });
    b.replies = [];
    const rx = new IbisReceiver((t, ok) => b.replies.push(ok ? t : '!' + t));
    b.on('tx', (x) => rx.push(x));
    b.flipLog = [];
    b.on('flip', (c, r, col, us) => b.flipLog.push({ t: b.time, us }));
    b.runSeconds(3);
    return b;
  };
  const dot = (b, x, y) => b.dots[y * b.cols + x];
  const yellow = (b) => b.dots.reduce((a, v) => a + v, 0);
  // versturen en wachten tot het display stil is (na verzendtijd + 3 s, dan 0,6 s zonder flips)
  const settle = (b, tele, max = 20) => {
    b.flipLog.length = 0; b.replies.length = 0;
    const t0 = b.time;
    b.sendTelegram(tele);
    let quiet = 0, last = 0;
    while (b.time - t0 < max) {
      b.runSeconds(0.1);
      if (b.flipLog.length === last) quiet += 0.1; else { quiet = 0; last = b.flipLog.length; }
      if (quiet >= 0.6 && b.time - t0 > txTime(tele) + 3) break;
    }
    const n = b.flipLog.length;
    return { flips: n, first: n ? b.flipLog[0].t - t0 : null, last: n ? b.flipLog[n - 1].t - t0 : null,
      maxPulse: Math.max(0, ...b.flipLog.map((f) => f.us)) };
  };
  // versturen en wachten op een antwoord (zoals een zender die op a0 wacht), max 1 s
  const sendWait = (b, tele) => {
    const before = b.replies.length, t0 = b.time;
    b.sendTelegram(tele);
    while (b.replies.length === before && b.time - t0 < 1) b.runSeconds(0.001);
    return b.replies.length > before ? b.time - t0 : null;
  };

  console.log('bestaand gedrag');
  {
    const b = boot();
    b.sendTelegram('aV1'); b.runSeconds(0.5);
    check('versie F00293', b.replies.includes('aVF00293'), JSON.stringify(b.replies));
    settle(b, 'aA11001\nHallo\n\n\n');
    check('vrije tekst', b.replies.includes('a0') && yellow(b) > 20, `geel=${yellow(b)}`);
    settle(b, 'aT11');
    check('testbeeld geel', yellow(b) === 112 * 16, String(yellow(b)));
  }

  console.log('aP: pixels');
  {
    const b = boot();
    const r = settle(b, 'aP1' + '000001' + '111151' + '056081');
    check('a0 + drie pixels', b.replies.includes('a0') && dot(b, 0, 0) && dot(b, 111, 15) && dot(b, 56, 8) && yellow(b) === 3, `geel=${yellow(b)}`);
    check('partial update: 3 flips', r.flips === 3, `flips=${r.flips}`);
    console.log(`       eerste flip na ${r.first?.toFixed(3)} s, langste puls ${r.maxPulse.toFixed(0)} µs`);
    b.runSeconds(60);
    check('pixels staan na 60 s nog', yellow(b) === 3);
    const r2 = settle(b, 'aP1' + '056080');
    check('pixel wissen: 1 flip', !dot(b, 56, 8) && r2.flips === 1, `flips=${r2.flips}`);
    const r3 = settle(b, 'aP1' + '200001' + '000201' + '00000x');
    check('buiten bereik / ongeldig: niets', r3.flips === 0 && yellow(b) === 2, `flips=${r3.flips}`);
    const r4 = settle(b, 'aP2' + '005051');
    check('ander adres: genegeerd', r4.flips === 0 && b.replies.length === 0);
    settle(b, 'aP0' + '005051');
    check('adres 0: uitgevoerd, geen antwoord', dot(b, 5, 5) && b.replies.length === 0);
  }

  console.log('aB: bitmap');
  {
    const b = boot();
    const word = (x) => (x * 0x0101 + 0x1234) & 0xFFFF;
    let hex = ''; for (let x = 0; x < 112; x++) hex += word(x).toString(16).padStart(4, '0').toUpperCase();
    const tele = 'aB1000' + hex;
    const r = settle(b, tele);
    let ok = true, want = 0;
    for (let x = 0; x < 112; x++) for (let y = 0; y < 16; y++) { const v = (word(x) >> y) & 1; want += v; if (dot(b, x, y) !== v) ok = false; }
    check(`volledige bitmap in één telegram (${tele.length + 1} tekens)`, ok && b.replies.includes('a0'), `geel=${yellow(b)}/${want}`);
    check('alleen veranderde dots', r.flips === want, `flips=${r.flips}`);
    console.log(`       verzenden ${txTime(tele).toFixed(3)} s, eerste flip na ${r.first?.toFixed(3)} s, klaar na ${r.last?.toFixed(2)} s, langste puls ${r.maxPulse.toFixed(0)} µs`);
    const r2 = settle(b, 'aB1110' + 'ffff'.repeat(5));
    check('kolommen voorbij de rand genegeerd (kleine letters)', r2.flips === 32 - ((word(110) & 0xFFFF).toString(2).split('1').length - 1) - ((word(111)).toString(2).split('1').length - 1), `flips=${r2.flips}`);
    const r3 = settle(b, 'aB1000' + '00G0');
    check('ongeldige hex: niets', r3.flips === 0);
    const r4 = settle(b, 'aA11001\n' + 'x'.repeat(260) + '\n\n\n');
    check('gewoon telegram > 250 tekens: genegeerd', b.replies.length === 0 && r4.flips === 0);
    const r5 = settle(b, 'aB1000' + 'F'.repeat(500));
    check('aB > 500 tekens: genegeerd', b.replies.length === 0 && r5.flips === 0);
  }

  console.log('reeks telegrammen, steeds wachten op a0');
  {
    const b = boot();
    const t0 = b.time;
    let acks = 0, maxAck = 0;
    for (let i = 0; i < 40; i++) {
      const dt = sendWait(b, 'aP1' + String(i * 2).padStart(3, '0') + String(i % 16).padStart(2, '0') + '1');
      if (dt !== null) { acks++; maxAck = Math.max(maxAck, dt); }
    }
    const sent = b.time - t0;
    b.runSeconds(2);
    let ok = true;
    for (let i = 0; i < 40; i++) if (!dot(b, i * 2, i % 16)) ok = false;
    check('40 pixeltelegrammen: allemaal a0 en allemaal getekend', acks === 40 && ok && yellow(b) === 40, `acks=${acks} geel=${yellow(b)}`);
    console.log(`       40 telegrammen verstuurd in ${sent.toFixed(2)} s (${(40 / sent).toFixed(0)}/s), langste wachttijd op a0 ${(maxAck * 1000).toFixed(1)} ms`);
    const tAck = sendWait(b, 'aB1000' + '8001'.repeat(112));
    const tAck2 = sendWait(b, 'aB1000' + '0180'.repeat(112));
    b.runSeconds(3);
    check('twee volledige bitmaps na elkaar (wachten op a0)', tAck !== null && tAck2 !== null && dot(b, 0, 7) && dot(b, 0, 8) && !dot(b, 0, 0), `${tAck} ${tAck2}`);
  }

  console.log('aU en bitmapmodus');
  {
    const b = boot();
    settle(b, 'aP1' + '010051');
    const r = settle(b, 'aU1');
    check('aU: alle 1792 dots, beeld gelijk', r.flips === 1792 && dot(b, 10, 5) && yellow(b) === 1, `flips=${r.flips}`);
    settle(b, 'aA10000\nTEKST\n\n\n');
    const t = yellow(b);
    const r2 = settle(b, 'aP1' + '000001');
    check('pixel op tekst: tekst blijft, 1 flip', yellow(b) === t + 1 && r2.flips === 1, `geel=${yellow(b)} flips=${r2.flips}`);
    b.sendTelegram('a1'); b.runSeconds(0.5);
    settle(b, 'aP1' + '001001');
    check('statusvraag beëindigt bitmapmodus niet', dot(b, 0, 0) && dot(b, 1, 0));
    settle(b, 'aA11001\nPagina een\n\n\nPagina twee\n\n\n');
    settle(b, 'aB1000' + '0F0F'.repeat(28));
    let bmOk = true;
    for (let x = 0; x < 28; x++) for (let y = 0; y < 16; y++) if (dot(b, x, y) !== ((0x0F0F >> y) & 1)) bmOk = false;
    const snap = b.dots.slice();
    b.runSeconds(60);
    let changed = 0; for (let i = 0; i < snap.length; i++) if (snap[i] !== b.dots[i]) changed++;
    check('bitmap over wisseltekst, blijft 60 s staan', bmOk && changed === 0, `bitmap ${bmOk}, ${changed} veranderd`);
    const r3 = settle(b, 'aA11001\nTerug\n\n\n');
    check('nieuwe tekst neemt het display weer over', b.replies.includes('a0') && r3.flips > 0);
    check('geen watchdog-resets', b.stats.wdResets === 0);
  }
}

console.log(`\n${passed} geslaagd, ${failed} mislukt`);
process.exit(failed ? 1 : 0);
