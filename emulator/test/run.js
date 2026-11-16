#!/usr/bin/env node
// Tests voor de emulator: CPU-instructies en regressie per firmware.
//   node emulator/test/run.js            tests draaien
//   node emulator/test/run.js --update   snapshots van displaybeelden opnieuw vastleggen
import { readFileSync, writeFileSync, mkdirSync, existsSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { CPU8051 } from '../core/cpu8051.js';
import { AZR802, IbisReceiver } from '../core/azr802.js';

const repo = fileURLToPath(new URL('../../', import.meta.url));
const snapDir = fileURLToPath(new URL('./snapshots/', import.meta.url));
const update = process.argv.includes('--update');
let failed = 0, passed = 0;
function check(name, cond, detail = '') {
  if (cond) { passed++; console.log('  ok   ' + name); }
  else { failed++; console.log('  FOUT ' + name + (detail ? ' — ' + detail : '')); }
}

// ---------- CPU-unittests ----------
function runProgram(bytes, steps = 100, setup) {
  const rom = new Uint8Array(0x10000).fill(0); rom.set(bytes);
  const tx = [];
  const bus = { code: (a) => rom[a], xread: () => 0, xwrite() {}, pins: () => 0xFF, portWrite() {},
    serialTx: (b, b8) => tx.push([b, b8, cpu.cycles]), serialRxAvailable: () => null, tick() {} };
  const cpu = new CPU8051(bus);
  if (setup) setup(cpu);
  for (let i = 0; i < steps; i++) cpu.step();
  cpu.tx = tx;
  return cpu;
}
const PSW = 0xD0, B = 0xF0;
console.log('CPU');
{ // ADD met carry, aux carry en overflow: 0x7F + 0x01 = 0x80, OV=1, AC=1, CY=0
  const c = runProgram([0x74, 0x7F, 0x24, 0x01, 0x80, 0xFE], 2);
  check('ADD vlaggen', c.acc === 0x80 && (c.sfr[PSW] & 0xC4) === 0x44, c.sfr[PSW].toString(16));
}
{ // SUBB: 0x10 - 0x20 met CY=1 -> 0xEF, CY=1
  const c = runProgram([0xD3, 0x74, 0x10, 0x94, 0x20, 0x80, 0xFE], 3);
  check('SUBB met lenen', c.acc === 0xEF && c.cy === 1, c.acc.toString(16));
}
{ // DA: 0x19 + 0x28 = 0x41 -> DA -> 0x47
  const c = runProgram([0x74, 0x19, 0x24, 0x28, 0xD4, 0x80, 0xFE], 3);
  check('DA A', c.acc === 0x47 && c.cy === 0, c.acc.toString(16));
}
{ // MUL 0x80*0x04 = 0x200: A=0, B=2, OV=1
  const c = runProgram([0x74, 0x80, 0x75, 0xF0, 0x04, 0xA4, 0x80, 0xFE], 3);
  check('MUL AB', c.acc === 0 && c.sfr[B] === 2 && (c.sfr[PSW] & 4), `${c.acc} ${c.sfr[B]}`);
}
{ // DIV 251/18 = 13 rest 17
  const c = runProgram([0x74, 0xFB, 0x75, 0xF0, 0x12, 0x84, 0x80, 0xFE], 3);
  check('DIV AB', c.acc === 13 && c.sfr[B] === 17);
}
{ // CJNE zet CY als A < imm en springt
  const c = runProgram([0x74, 0x05, 0xB4, 0x09, 0x02, 0x74, 0xAA, 0x80, 0xFE], 3);
  check('CJNE carry + sprong', c.cy === 1 && c.acc === 0x05);
}
{ // DJNZ R2 telt tot 0
  const c = runProgram([0x7A, 0x05, 0x04, 0xDA, 0xFD, 0x80, 0xFE], 1 + 5 * 2);
  check('DJNZ', c.acc === 5 && c.iram[2] === 0);
}
{ // MOVC A,@A+PC: tabel direct na de instructie (+1 voor de SJMP ertussen)
  const c = runProgram([0x74, 0x03, 0x83, 0x80, 0xFE, 0x11, 0x22, 0x33], 2);
  check('MOVC A,@A+PC', c.acc === 0x22, c.acc.toString(16));
}
{ // ACALL + RET
  const c = runProgram([0x11, 0x05, 0x80, 0xFE, 0x00, 0x74, 0x42, 0x22], 4);
  check('ACALL/RET', c.acc === 0x42 && c.pc === 0x02 && c.sfr[0x81] === 7);
}
{ // XCHD
  const c = runProgram([0x78, 0x30, 0x76, 0xAB, 0x74, 0x12, 0xD6, 0x80, 0xFE], 4);
  check('XCHD', c.acc === 0x1B && c.iram[0x30] === 0xA2);
}
{ // JBC wist bit en springt
  const c = runProgram([0xD2, 0x00, 0x10, 0x00, 0x02, 0x74, 0x01, 0x80, 0xFE], 3);
  check('JBC', (c.iram[0x20] & 1) === 0 && c.acc === 0);
}
{ // timer0-interrupt (mode 1) springt naar 0x0B en RETI terug
  const prog = new Uint8Array(0x40);
  prog.set([0x02, 0x00, 0x30], 0);                       // LJMP 0030
  prog.set([0x05, 0x40, 0x32], 0x0B);                    // INC 40h; RETI
  prog.set([0x75, 0x89, 0x01, 0x75, 0x8C, 0xFF, 0x75, 0x8A, 0xF0, 0x75, 0xA8, 0x82, 0xD2, 0x8C, 0x80, 0xFE], 0x30);
  const c = runProgram(prog, 60);
  check('timer0-interrupt + RETI', c.iram[0x40] >= 1 && c.inService.every((x) => !x));
}
{ // UART mode 3, 1200 Bd bij 6 MHz: 11 bits = 9,17 ms = ~4583 cycli
  const prog = [0x75, 0x89, 0x20, 0x75, 0x8D, 0xE6, 0x75, 0x8B, 0xE6, 0x75, 0x87, 0x80, 0x75, 0x98, 0xD8, 0xD2, 0x8E, 0x75, 0x99, 0x55, 0x80, 0xFE];
  const c = runProgram(prog, 3000);
  const t = c.tx[0];
  check('UART 1200 Bd 11 bits', t && t[0] === 0x55 && t[1] === 1 && Math.abs(t[2] - 4583) < 30, t && `${t[2]} cycli`);
}

// ---------- firmware-regressie ----------
function ascii(b) {
  const out = [];
  for (let r = 0; r < b.rows; r++) { let s = ''; for (let c = 0; c < b.cols; c++) s += b.dots[r * b.cols + c] ? '#' : '.'; out.push(s); }
  return out.join('\n') + '\n';
}
function boardFor(rom, extra = {}) {
  const load = (f) => new Uint8Array(readFileSync(repo + f));
  const b = new AZR802({ rom: load(rom), rm2: extra.rm ? load(extra.rm) : undefined, rm3: extra.rm ? load(extra.rm) : undefined, ...extra.opts });
  b.replies = [];
  const rx = new IbisReceiver((t, ok) => b.replies.push(ok ? t : '!' + t));
  b.on('tx', (x) => rx.push(x));
  return b;
}
function snapshot(name, b) {
  const file = snapDir + name + '.txt', cur = ascii(b);
  if (update || !existsSync(file)) { mkdirSync(snapDir, { recursive: true }); writeFileSync(file, cur); check(`snapshot ${name} vastgelegd`, true); return; }
  check(`display ${name}`, readFileSync(file, 'utf8') === cur, 'wijkt af van test/snapshots/' + name + '.txt');
}

const cases = [
  { name: 'ASFP', rom: 'firmware/ASFP.bin', version: 'aVF00293',
    text: 'aA11001\nRegel een\nRegel twee\n\n', wait: 8 },
  { name: 'AZIPZR1', rom: 'firmware/AZIPZR1.BIN', version: 'aVF00293' },
  { name: 'MLAWO-RET0902', rom: 'firmware/MLAWO_RET_RET60.PLM51_18-11-92.bin', rm: 'text-eproms/RET0902_14-10-2002_C256_05F55CD.bin',
    version: 'aVR.SCH.', text: 'z003', wait: 8 },
  { name: 'AZR-12C-front', rom: 'firmware/AZR-12C.BIN', rm: 'text-eproms/front.bin', version: 'aVLLEI12', text: 'z003', wait: 8 },
  { name: 'dvb_azrfr51', rom: 'firmware/dvb_azrfr51v16.bin', version: 'aVAZR51ZD' },
];
for (const tc of cases) {
  console.log(tc.name);
  const b = boardFor(tc.rom, tc);
  b.runSeconds(4);
  b.sendTelegram('aV1'); b.runSeconds(1);
  check('versie-antwoord ' + tc.version, b.replies.includes(tc.version), JSON.stringify(b.replies));
  b.sendTelegram('a1'); b.runSeconds(1);
  check('status-antwoord a0', b.replies.includes('a0'), JSON.stringify(b.replies));
  if (tc.text) { b.sendTelegram(tc.text); b.runSeconds(tc.wait); snapshot(tc.name, b); }
  check('geen watchdog-resets', b.stats.wdResets === 0, String(b.stats.wdResets));
}

console.log(`\n${passed} geslaagd, ${failed} mislukt`);
process.exit(failed ? 1 : 0);
