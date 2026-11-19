// Model van de LAWO AZR 802/24 (en grotendeels 802/15) rond de 8051-kern.
// Bronnen: schema AZR802-24-gereviseerd.pdf blad 1-5, moduleschema flipdot-module-28x13.pdf,
// en de kolomtabel in ASFP.bin (0x3122) als controle van de FP2800-adressering.
//
// XDATA:  0x0000-0x0FFF  RM1 (4 KB). Schrijven naar 0x0000-0x0007 gaat óók naar de latches.
//         0x1000-0xFFFF  RM2 (LD4=0) of RM3 (LD4=1), 32 KB, gespiegeld.
// Latch 0 (IC15, EZ): b0-3 AC0-3 rij, b4 AC4 (0 = rij bron/+ = geel, 1 = rij put/- = zwart), b5 LD2, b6 LD3, b7 LD4/bank
// Latch 1 (IC16, ES): b0-2 FP2800 A0-A2, b3-4 B0-B1, b5-6 AC7/AC8 (module via IC20), b7 DATA
// Latch 2 (IC17):     b0 AC11, b1 AC10, b2 AC9 (uitbreidingskaart, >4 modules)
// Latch 3 (802/15):   7-segment D16 (gemeenschappelijke anode, actief laag)
// P1: b0..3 adresbruggen (gewicht 1,4,2,8), b4 S1, b5 S2, b6/b7 spanningsbewaking
// P3: b2 TG (gele knop), b3 TS (zwarte knop), b4 E (puls, laag = actief), b5 WDI (MAX690)
//
// Optioneel fysiek model (opts.physics, standaard uit), zie docs/fast-refresh-onderzoek.md:
// - RC-enable: AEN (= NOT E, 0/5 V) gaat via C1 (0,33 uF) en R1 (15 k) naar ENABLE (pin 24) van de FP2800A.
//   Een flank van AEN verschuift de spanning op ENABLE met +/-5 V, daarna zakt die met tau = R1*C1 naar 0.
//   De driver staat aan zolang ENABLE >= V_IH (2,0 V). Zonder klemdiode (clamp: false) kan ENABLE na een puls
//   negatief worden, zodat de volgende puls lager begint. Een puls telt alleen als de effectieve aan-tijd
//   >= minPulseUs is ("zwakke puls" anders).
// - t_SE (datasheet: adres/data 50 us stabiel voor ENABLE): tijd tussen de laatste schrijfactie naar latch 0-2
//   en het begin van de puls; korter telt als overtreding (alleen geteld, tenzij strict).
// - schrijfacties naar latch 0-2 tijdens een puls (ook met dezelfde waarde) en duty cycle worden geteld.

// Cache-buster van de webpagina doorgeven (in Node is er geen ?v= en is dit gewoon ./cpu8051.js).
const V = new URL(import.meta.url).searchParams.get('v');
const { CPU8051 } = await import(V ? `./cpu8051.js?v=${V}` : './cpu8051.js');

export class AZR802 {
  constructor(opts = {}) {
    this.osc = opts.osc || 6000000;
    this.cpuType = opts.cpuType || '80C31';
    this.rom = new Uint8Array(0x8000).fill(0xFF);
    if (opts.rom) this.rom.set(opts.rom.subarray(0, 0x8000));
    this.rm1 = new Uint8Array(0x1000);
    this.bank = [this.makeBank(opts.rm2), this.makeBank(opts.rm3)];
    this.latch = new Uint8Array(8);
    this.cols = opts.cols || 112;
    this.rows = opts.rows || 16;
    this.dots = new Uint8Array(this.cols * this.rows);   // 0 = zwart, 1 = geel
    this.dotTime = new Float64Array(this.cols * this.rows);
    this.address = opts.address ?? 1;
    this.s1 = opts.s1 ?? 1;           // pinniveau P1.4 (1 = open)
    this.s2 = opts.s2 ?? 0;           // pinniveau P1.5 (0 = seriële ontvangst aan bij ASFP/MLAWO)
    this.p1Extra = opts.p1Extra ?? 0; // P1.6/P1.7 (0 = spanning in orde)
    this.buttons = { yellow: false, black: false };
    this.minPulseUs = opts.minPulseUs ?? 100;
    this.wdTimeoutS = opts.wdTimeoutS ?? 1.6;
    this.listeners = { tx: [], flip: [], log: [], reset: [] };
    this.rxQueue = [];
    this.stats = { flips: 0, pulses: 0, ignoredPulses: 0, outside: 0, resets: 0, wdResets: 0,
      weakPulses: 0, tseViolations: 0, latchWritesInPulse: 0, maxDuty: 0 };
    const ph = opts.physics === true ? {} : opts.physics;
    this.phys = ph ? { tauUs: 4950, vih: 2.0, vAen: 5, clamp: false, clampV: -0.6, tSEus: 50, strict: false, ...ph } : null;
    this.enV = 0; this.enT = 0; this.lastLatchW = 0; this.lastPulseEnd = 0;
    this.cpu = new CPU8051(this, { upperRam: this.cpuType === '80C32' });
    this.powerOn();
  }

  makeBank(spec) {
    if (!spec) return { ram: true, data: new Uint8Array(0x8000) };
    if (spec instanceof Uint8Array) {
      const d = new Uint8Array(0x8000).fill(0xFF); d.set(spec.subarray(0, 0x8000));
      return { ram: false, data: d };
    }
    return spec;
  }

  on(ev, fn) { this.listeners[ev].push(fn); }
  emit(ev, ...a) { for (const f of this.listeners[ev]) f(...a); }

  get cyclesPerSecond() { return this.osc / 12; }
  get time() { return this.cpu.cycles / this.cyclesPerSecond; }

  powerOn() {
    this.cpu.reset();
    this.portLatch = [0xFF, 0xFF, 0xFF, 0xFF];
    this.e = 1; this.pulseStart = 0;
    this.wdi = 1; this.wdLastEdge = this.cpu.cycles;
    this.inReset = false;
    this.enV = 0; this.enT = this.cpu.cycles; this.lastLatchW = 0; this.lastPulseEnd = 0;
    this.stats.resets++;
    this.emit('reset', 'power-on');
  }

  // ---------- bus voor de CPU ----------
  code(a) { return this.rom[a & 0x7FFF]; }
  xread(a) {
    if (a < 0x1000) return this.rm1[a];
    return this.bank[this.latch[0] >> 7].data[a & 0x7FFF];
  }
  xwrite(a, v) {
    if (a < 0x1000) {
      this.rm1[a] = v;
      if (a < 8) this.writeLatch(a, v);
      return;
    }
    const b = this.bank[this.latch[0] >> 7];
    if (b.ram) b.data[a & 0x7FFF] = v;
  }
  writeLatch(i, v) {
    const old = this.latch[i];
    this.latch[i] = v;
    if (i <= 2) {
      this.lastLatchW = this.cpu.cycles;
      if (this.e === 0) this.stats.latchWritesInPulse++;
    }
    // alleen bits die de spoelen aansturen (latch 0: b0-4, latch 1 en 2: alles)
    const mask = i === 0 ? 0x1F : (i <= 2 ? 0xFF : 0);
    if (this.e === 0 && ((old ^ v) & mask)) this.emit('log', `latch ${i} gewijzigd tijdens puls (${old.toString(16)} -> ${v.toString(16)})`);
  }
  pins(port) {
    if (port === 1) {
      const a = this.address & 15;
      // brug naar GND = 1 in het adres; pin laag
      const addrBits = ((a & 1) ? 0 : 1) | ((a & 4) ? 0 : 2) | ((a & 2) ? 0 : 4) | ((a & 8) ? 0 : 8);
      return addrBits | (this.s1 ? 0x10 : 0) | (this.s2 ? 0x20 : 0) | ((this.p1Extra & 3) << 6);
    }
    if (port === 3) {
      return 0xF3 | (this.buttons.yellow ? 0 : 0x04) | (this.buttons.black ? 0 : 0x08);
    }
    return 0xFF;
  }
  portWrite(port, v) {
    this.portLatch[port] = v;
    if (port !== 3) return;
    const e = (v >> 4) & 1, wdi = (v >> 5) & 1, now = this.cpu.cycles;
    if (e !== this.e) {
      if (e === 0) { this.pulseStart = now; this.pulseLatch = [this.latch[0], this.latch[1], this.latch[2]]; this.startPulsePhysics(now); }
      else this.endPulse(now);
      this.e = e;
    }
    if (wdi !== this.wdi) { this.wdi = wdi; this.wdLastEdge = now; }
  }
  serialTx(byte, bit8) { this.emit('tx', byte, bit8, this.time); }
  serialRxAvailable() { return this.rxQueue.length ? this.rxQueue.shift() : null; }
  tick() {
    // MAX690-watchdog
    if (this.cpu.cycles - this.wdLastEdge > this.wdTimeoutS * this.cyclesPerSecond) {
      this.stats.wdResets++;
      this.emit('log', `watchdog-reset op t=${this.time.toFixed(3)} s`);
      this.cpu.reset();
      this.e = 1; this.wdi = 1; this.wdLastEdge = this.cpu.cycles;
      this.emit('reset', 'watchdog');
    }
  }

  // ---------- fysiek model ----------
  cyclesToUs(c) { return c * 12e6 / this.osc; }
  startPulsePhysics(now) {
    const p = this.phys;
    if (!p) return;
    // ENABLE ontspant sinds de vorige flank, daarna +5 V door de stijgende flank van AEN
    this.enV = this.enV * Math.exp(-this.cyclesToUs(now - this.enT) / p.tauUs) + p.vAen;
    this.enT = now;
    this.pulseEnStart = this.enV;
    this.pulseTse = this.cyclesToUs(now - this.lastLatchW);
    if (this.pulseTse < p.tSEus) this.stats.tseViolations++;
  }
  // geeft de effectieve aan-tijd (us) van de puls die nu eindigt
  endPulsePhysics(now, us) {
    const p = this.phys;
    const v0 = this.pulseEnStart;
    const eff = v0 > p.vih ? Math.min(us, p.tauUs * Math.log(v0 / p.vih)) : 0;
    this.enV = v0 * Math.exp(-us / p.tauUs) - p.vAen;     // dalende flank van AEN
    if (p.clamp) this.enV = Math.max(this.enV, p.clampV);
    this.enT = now;
    if (this.lastPulseEnd) {
      const period = this.cyclesToUs(now - this.lastPulseEnd);
      if (period > 0 && period < 3 * us) this.stats.maxDuty = Math.max(this.stats.maxDuty, us / period);
    }
    this.lastPulseEnd = now;
    return eff;
  }

  // ---------- flipdot ----------
  endPulse(now) {
    this.stats.pulses++;
    let us = (now - this.pulseStart) * 12e6 / this.osc;
    if (this.phys) {
      const eff = this.endPulsePhysics(now, us);
      const tseBad = this.phys.strict && this.pulseTse < this.phys.tSEus;
      if (eff < this.minPulseUs || tseBad) {
        if (us >= this.minPulseUs && !this.stats.weakPulses++) {
          this.emit('log', `zwakke puls: ENABLE ${this.pulseEnStart.toFixed(2)} V bij start, ${eff.toFixed(0)} us boven ${this.phys.vih} V` +
            (tseBad ? `, t_SE ${this.pulseTse.toFixed(0)} us` : '') + '; verdere worden alleen geteld');
        }
        this.stats.ignoredPulses++;
        return;
      }
      us = eff;
    }
    if (us < this.minPulseUs) { this.stats.ignoredPulses++; return; }
    const l0 = this.latch[0], l1 = this.latch[1], l2 = this.latch[2];
    const code = l0 & 0x0F, rowSink = (l0 >> 4) & 1;
    // Rijcode 0 = Z49/Z50 = onderste rij (gekalibreerd op leesbare ASFP-tekst).
    const row = this.rows - 1 - code;
    const a = l1 & 7, b = (l1 >> 3) & 3, m = (l1 >> 5) & 3, data = l1 >> 7;
    if (a === 0) return;                     // FP2800: adres 0 = geen uitgang
    if (rowSink !== data) return;            // beide kanten zelfde polariteit: geen stroom
    const module = (l2 & 7) * 4 + m;
    const col = module * 28 + (3 - b) * 7 + (7 - a);
    if (col >= this.cols || row < 0) {
      if (!this.stats.outside++) this.emit('log', `puls buiten display (kolom ${col}, rij ${row}); verdere worden alleen geteld`);
      return;
    }
    const i = row * this.cols + col;
    // Polariteit gekalibreerd op het testtelegram aT (handleiding: 0 = zwart, 1 = geel):
    // DATA=0 + rij bron => geel, DATA=1 + rij put => zwart.
    const color = data ? 0 : 1;
    this.stats.flips++;
    if (this.dots[i] !== color) { this.dots[i] = color; this.dotTime[i] = this.time; }
    this.emit('flip', col, row, color, us);
  }

  // ---------- host-kant: IBIS ----------
  // 7E2: 7 databits + even pariteit in bit 7, tweede stopbit = 9e bit (1)
  sendChar(c) {
    c &= 0x7F;
    let p = 0, x = c; while (x) { p ^= x & 1; x >>= 1; }
    this.rxQueue.push({ byte: c | (p << 7), bit8: 1 });
  }
  sendRaw(str) { for (const ch of str) this.sendChar(ch.charCodeAt(0)); }
  sendTelegram(body) {
    // body zonder CR; checksum = 0x7F XOR alle tekens incl. CR
    const t = body + '\r';
    let cs = 0x7F; for (const ch of t) cs ^= ch.charCodeAt(0);
    this.sendRaw(t); this.sendChar(cs);
  }

  // ---------- uitvoeren ----------
  runCycles(n) {
    const end = this.cpu.cycles + n, cpu = this.cpu;
    while (cpu.cycles < end) cpu.step();
  }
  runSeconds(s) { this.runCycles(Math.round(s * this.cyclesPerSecond)); }

  leds() {
    return { LD1_reset: !this.inReset, LD2: (this.latch[0] >> 5) & 1, LD3: (this.latch[0] >> 6) & 1, LD4_bank: this.latch[0] >> 7 };
  }
  sevenSeg() { return decode7seg(this.latch[3]); }
}

// gemeenschappelijke anode, actief laag: bit0=a ... bit6=g, bit7=dp
const SEG = { 0xC0: '0', 0xF9: '1', 0xA4: '2', 0xB0: '3', 0x99: '4', 0x92: '5', 0x82: '6', 0xF8: '7',
  0x80: '8', 0x90: '9', 0x88: 'A', 0x83: 'b', 0xC6: 'C', 0xA1: 'd', 0x86: 'E', 0x8E: 'F', 0x89: 'H',
  0xC7: 'L', 0xC1: 'U', 0x8C: 'P', 0xFF: ' ', 0xBF: '-' };
export function decode7seg(v) { return SEG[v] ?? '?'; }

// IBIS-antwoorden uit losse 7E2-tekens opbouwen
export class IbisReceiver {
  constructor(onTelegram) { this.buf = ''; this.waitCs = false; this.on = onTelegram; }
  push(byte) {
    const c = byte & 0x7F;
    let p = 0, x = byte & 0xFF; while (x) { p ^= x & 1; x >>= 1; }
    if (this.waitCs) {
      let cs = 0x7F; for (const ch of this.buf + '\r') cs ^= ch.charCodeAt(0);
      this.on(this.buf, cs === c, p === 0);
      this.buf = ''; this.waitCs = false; return;
    }
    if (c === 0x0D) { this.waitCs = true; return; }
    this.buf += String.fromCharCode(c);
  }
}
