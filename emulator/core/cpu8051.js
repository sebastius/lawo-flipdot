// Instructie-nauwkeurige 8051/80C31/80C32-kern met timers 0/1, UART, interrupts en idle-modus.
// De kern kent geen board: externe toegang loopt via het `bus`-object:
//   bus.code(addr)            -> byte      (PSEN)
//   bus.xread(addr)           -> byte      (MOVX lezen, 16-bit adres)
//   bus.xwrite(addr, v)                    (MOVX schrijven)
//   bus.pins(port)            -> byte      (externe pinniveaus, 1 = hoog/los)
//   bus.portWrite(port, latch)             (melding na schrijven poortlatch)
//   bus.serialTx(byte, bit8)               (verzonden UART-frame)
//   bus.serialRxAvailable()   -> {byte, bit8} | null   (volgend frame van host)
//   bus.tick(cycles)                       (tijd voor board-randapparatuur)

const ACC = 0xE0, B = 0xF0, PSW = 0xD0, SP = 0x81, DPL = 0x82, DPH = 0x83;
const P0 = 0x80, P1 = 0x90, P2 = 0xA0, P3 = 0xB0;
const TCON = 0x88, TMOD = 0x89, TL0 = 0x8A, TL1 = 0x8B, TH0 = 0x8C, TH1 = 0x8D;
const SCON = 0x98, SBUF = 0x99, IE = 0xA8, IP = 0xB8, PCON = 0x87;

// machinecycli per opcode
const CYCLES = new Uint8Array(256).fill(1);
(function initCycles() {
  const two = [0x02, 0x10, 0x12, 0x20, 0x22, 0x30, 0x32, 0x40, 0x43, 0x50, 0x53, 0x60, 0x63, 0x70,
    0x72, 0x73, 0x75, 0x80, 0x82, 0x83, 0x85, 0x86, 0x87, 0x90, 0x92, 0x93, 0xA0, 0xA3, 0xA6, 0xA7,
    0xB0, 0xB4, 0xB5, 0xB6, 0xB7, 0xC0, 0xD0, 0xD5, 0xE0, 0xE2, 0xE3, 0xF0, 0xF2, 0xF3];
  for (const o of two) CYCLES[o] = 2;
  for (let i = 0; i < 8; i++) {
    CYCLES[0x01 + i * 0x20] = 2; CYCLES[0x11 + i * 0x20] = 2;       // AJMP/ACALL
    CYCLES[0x88 + i] = 2; CYCLES[0xA8 + i] = 2;                     // MOV dir,Rn / MOV Rn,dir
    CYCLES[0xB8 + i] = 2; CYCLES[0xD8 + i] = 2;                     // CJNE Rn / DJNZ Rn
  }
  CYCLES[0xA4] = 4; CYCLES[0x84] = 4;                               // MUL, DIV
})();

export class CPU8051 {
  constructor(bus, { upperRam = false } = {}) {
    this.bus = bus;
    this.upperRam = upperRam;          // 80C32: 256 bytes intern RAM; 80C31: 128
    this.iram = new Uint8Array(256);
    this.sfr = new Uint8Array(256);    // index = SFR-adres (0x80..0xFF)
    this.cycles = 0;                   // totaal machinecycli
    this.reset();
  }

  reset() {
    const s = this.sfr;
    s.fill(0);
    s[P0] = s[P1] = s[P2] = s[P3] = 0xFF;
    s[SP] = 0x07;
    this.pc = 0;
    this.idle = false;
    this.powerDown = false;
    this.inService = [false, false];   // actieve interruptniveaus (laag, hoog)
    this.irqBlock = false;             // na RETI / IE- of IP-schrijven 1 instructie wachten
    this.uart = { txBits: 0, txByte: 0, txBit8: 0, rxBits: 0, rxFrame: null, tick: 0, sbufRx: 0 };
    this.lastInt = [1, 1];
  }

  // ---------- geheugen ----------
  readDirect(a, rmw = false) {
    if (a < 0x80) return this.iram[a];
    return this.readSfr(a, rmw);
  }
  writeDirect(a, v) {
    v &= 0xFF;
    if (a < 0x80) { this.iram[a] = v; return; }
    this.writeSfr(a, v);
  }
  readIndirect(a) {
    if (a < 0x80 || this.upperRam) return this.iram[a];
    return 0xFF;                       // 80C31: geen RAM boven 0x7F
  }
  writeIndirect(a, v) {
    if (a < 0x80 || this.upperRam) this.iram[a] = v & 0xFF;
  }
  readSfr(a, rmw) {
    const s = this.sfr;
    switch (a) {
      case PSW: return (s[PSW] & 0xFE) | this.parity();
      case P0: case P1: case P2: case P3:
        return rmw ? s[a] : (s[a] & this.portPins(a));
      case SBUF: return this.uart.sbufRx;
      default: return s[a];
    }
  }
  writeSfr(a, v) {
    const s = this.sfr;
    switch (a) {
      case PSW: s[PSW] = v; return;
      case SBUF:
        this.uart.txByte = v;
        this.uart.txBit8 = (s[SCON] >> 3) & 1;
        this.uart.txBits = ((s[SCON] >> 6) === 1) ? 10 : 11;
        this.uart.tick = 0;
        return;
      case P0: case P1: case P2: case P3:
        s[a] = v; this.bus.portWrite((a - P0) >> 4, v); return;
      case IE: case IP: s[a] = v; this.irqBlock = true; return;
      case PCON:
        s[a] = v & 0x8F;
        if (v & 0x02) this.powerDown = true; else if (v & 0x01) this.idle = true;
        return;
      default: s[a] = v;
    }
  }
  portPins(a) {
    let pins = this.bus.pins((a - P0) >> 4);
    if (a === P3) {
      // RXD-pin volgt de ontvangstlijn: rust = 1
      pins = (pins & 0xFE) | (this.uart.rxBits > 0 ? 0 : 1);
    }
    return pins;
  }
  parity() {
    let a = this.sfr[ACC], p = 0;
    while (a) { p ^= a & 1; a >>= 1; }
    return p;
  }
  readBit(bit, rmw = false) {
    if (bit < 0x80) return (this.iram[0x20 + (bit >> 3)] >> (bit & 7)) & 1;
    return (this.readSfr(bit & 0xF8, rmw) >> (bit & 7)) & 1;
  }
  writeBit(bit, val) {
    const m = 1 << (bit & 7);
    if (bit < 0x80) {
      const a = 0x20 + (bit >> 3);
      this.iram[a] = val ? (this.iram[a] | m) : (this.iram[a] & ~m);
      return;
    }
    const a = bit & 0xF8;
    const cur = this.readSfr(a, true);
    this.writeSfr(a, val ? (cur | m) : (cur & ~m));
  }
  get acc() { return this.sfr[ACC]; }
  set acc(v) { this.sfr[ACC] = v & 0xFF; }
  get cy() { return this.sfr[PSW] >> 7; }
  set cy(v) { this.sfr[PSW] = v ? (this.sfr[PSW] | 0x80) : (this.sfr[PSW] & 0x7F); }
  setFlags(cy, ac, ov) {
    let p = this.sfr[PSW] & 0x3B;
    if (cy) p |= 0x80; if (ac) p |= 0x40; if (ov) p |= 0x04;
    this.sfr[PSW] = p;
  }
  regAddr(n) { return (this.sfr[PSW] & 0x18) + n; }
  get dptr() { return (this.sfr[DPH] << 8) | this.sfr[DPL]; }
  set dptr(v) { this.sfr[DPH] = (v >> 8) & 0xFF; this.sfr[DPL] = v & 0xFF; }
  push(v) { const sp = (this.sfr[SP] + 1) & 0xFF; this.sfr[SP] = sp; this.writeIndirect(sp, v); }
  pop() { const sp = this.sfr[SP]; const v = this.readIndirect(sp); this.sfr[SP] = (sp - 1) & 0xFF; return v; }
  fetch() { const v = this.bus.code(this.pc); this.pc = (this.pc + 1) & 0xFFFF; return v; }
  rel(o) { return (this.pc + ((o << 24) >> 24)) & 0xFFFF; }

  add(b, c) {
    const a = this.sfr[ACC], r = a + b + c;
    this.setFlags(r > 0xFF, ((a & 0xF) + (b & 0xF) + c) > 0xF, ((a ^ r) & (b ^ r) & 0x80) !== 0);
    this.sfr[ACC] = r & 0xFF;
  }
  subb(b) {
    const a = this.sfr[ACC], c = this.cy, r = a - b - c;
    this.setFlags(r < 0, ((a & 0xF) - (b & 0xF) - c) < 0, ((a ^ b) & (a ^ r) & 0x80) !== 0);
    this.sfr[ACC] = r & 0xFF;
  }

  // ---------- één instructie ----------
  step() {
    if (this.powerDown) { this.tickPeripherals(12); return 12; }
    if (this.idle) { this.tickPeripherals(1); this.checkInterrupts(); return 1; }
    const op = this.fetch();
    const n = CYCLES[op];
    this.exec(op);
    this.tickPeripherals(n);
    if (this.irqBlock) this.irqBlock = false; else this.checkInterrupts();
    return n;
  }

  exec(op) {
    const s = this.sfr;
    const lo = op & 0x0F;
    // Rn- en @Ri-varianten per rij
    if (lo >= 0x08 || lo === 0x06 || lo === 0x07) {
      const isReg = lo >= 0x08;
      const raddr = isReg ? this.regAddr(lo - 8) : this.iram[this.regAddr(lo - 6)];
      const rd = () => (isReg ? this.iram[raddr] : this.readIndirect(raddr));
      const wr = (v) => { if (isReg) this.iram[raddr] = v & 0xFF; else this.writeIndirect(raddr, v); };
      switch (op & 0xF0) {
        case 0x00: wr(rd() + 1); return;                       // INC
        case 0x10: wr(rd() - 1); return;                       // DEC
        case 0x20: this.add(rd(), 0); return;                  // ADD A,
        case 0x30: this.add(rd(), this.cy); return;            // ADDC
        case 0x40: s[ACC] |= rd(); return;                     // ORL A,
        case 0x50: s[ACC] &= rd(); return;                     // ANL A,
        case 0x60: s[ACC] ^= rd(); return;                     // XRL A,
        case 0x70: wr(this.fetch()); return;                   // MOV r,#
        case 0x80: this.writeDirect(this.fetch(), rd()); return; // MOV dir,r
        case 0x90: this.subb(rd()); return;                    // SUBB
        case 0xA0: wr(this.readDirect(this.fetch())); return;  // MOV r,dir
        case 0xB0: {                                           // CJNE r,#,rel
          const imm = this.fetch(), o = this.fetch(), v = rd();
          this.cy = v < imm ? 1 : 0;
          if (v !== imm) this.pc = this.rel(o);
          return;
        }
        case 0xC0: { const t = rd(); wr(s[ACC]); s[ACC] = t; return; }   // XCH
        case 0xD0:
          if (isReg) {                                          // DJNZ Rn
            const o = this.fetch(); const v = (rd() - 1) & 0xFF; wr(v);
            if (v) this.pc = this.rel(o);
          } else {                                              // XCHD
            const v = rd(); wr((v & 0xF0) | (s[ACC] & 0x0F)); s[ACC] = (s[ACC] & 0xF0) | (v & 0x0F);
          }
          return;
        case 0xE0: s[ACC] = rd(); return;                      // MOV A,r
        case 0xF0: wr(s[ACC]); return;                         // MOV r,A
      }
    }
    // AJMP / ACALL
    if ((op & 0x1F) === 0x01 || (op & 0x1F) === 0x11) {
      const a = this.fetch();
      const target = (this.pc & 0xF800) | ((op >> 5) << 8) | a;
      if (op & 0x10) { this.push(this.pc & 0xFF); this.push(this.pc >> 8); }
      this.pc = target;
      return;
    }
    switch (op) {
      case 0x00: return;                                                     // NOP
      case 0x02: { const h = this.fetch(), l = this.fetch(); this.pc = (h << 8) | l; return; }
      case 0x03: { const a = s[ACC]; s[ACC] = (a >> 1) | ((a & 1) << 7); return; }  // RR
      case 0x04: s[ACC] = (s[ACC] + 1) & 0xFF; return;
      case 0x05: { const d = this.fetch(); this.writeDirect(d, this.readDirect(d, true) + 1); return; }
      case 0x10: {                                                           // JBC
        const b = this.fetch(), o = this.fetch();
        if (this.readBit(b, true)) { this.writeBit(b, 0); this.pc = this.rel(o); }
        return;
      }
      case 0x12: {                                                           // LCALL
        const h = this.fetch(), l = this.fetch();
        this.push(this.pc & 0xFF); this.push(this.pc >> 8); this.pc = (h << 8) | l; return;
      }
      case 0x13: { const a = s[ACC], c = this.cy; this.cy = a & 1; s[ACC] = (a >> 1) | (c << 7); return; }
      case 0x14: s[ACC] = (s[ACC] - 1) & 0xFF; return;
      case 0x15: { const d = this.fetch(); this.writeDirect(d, this.readDirect(d, true) - 1); return; }
      case 0x20: { const b = this.fetch(), o = this.fetch(); if (this.readBit(b)) this.pc = this.rel(o); return; }
      case 0x22: { const h = this.pop(), l = this.pop(); this.pc = (h << 8) | l; return; }   // RET
      case 0x23: { const a = s[ACC]; s[ACC] = ((a << 1) | (a >> 7)) & 0xFF; return; }       // RL
      case 0x24: this.add(this.fetch(), 0); return;
      case 0x25: this.add(this.readDirect(this.fetch()), 0); return;
      case 0x30: { const b = this.fetch(), o = this.fetch(); if (!this.readBit(b)) this.pc = this.rel(o); return; }
      case 0x32: {                                                           // RETI
        const h = this.pop(), l = this.pop(); this.pc = (h << 8) | l;
        if (this.inService[1]) this.inService[1] = false; else this.inService[0] = false;
        this.irqBlock = true; return;
      }
      case 0x33: { const a = s[ACC], c = this.cy; this.cy = a >> 7; s[ACC] = ((a << 1) | c) & 0xFF; return; }
      case 0x34: this.add(this.fetch(), this.cy); return;
      case 0x35: this.add(this.readDirect(this.fetch()), this.cy); return;
      case 0x40: { const o = this.fetch(); if (this.cy) this.pc = this.rel(o); return; }
      case 0x42: { const d = this.fetch(); this.writeDirect(d, this.readDirect(d, true) | s[ACC]); return; }
      case 0x43: { const d = this.fetch(), i = this.fetch(); this.writeDirect(d, this.readDirect(d, true) | i); return; }
      case 0x44: s[ACC] |= this.fetch(); return;
      case 0x45: s[ACC] |= this.readDirect(this.fetch()); return;
      case 0x50: { const o = this.fetch(); if (!this.cy) this.pc = this.rel(o); return; }
      case 0x52: { const d = this.fetch(); this.writeDirect(d, this.readDirect(d, true) & s[ACC]); return; }
      case 0x53: { const d = this.fetch(), i = this.fetch(); this.writeDirect(d, this.readDirect(d, true) & i); return; }
      case 0x54: s[ACC] &= this.fetch(); return;
      case 0x55: s[ACC] &= this.readDirect(this.fetch()); return;
      case 0x60: { const o = this.fetch(); if (s[ACC] === 0) this.pc = this.rel(o); return; }
      case 0x62: { const d = this.fetch(); this.writeDirect(d, this.readDirect(d, true) ^ s[ACC]); return; }
      case 0x63: { const d = this.fetch(), i = this.fetch(); this.writeDirect(d, this.readDirect(d, true) ^ i); return; }
      case 0x64: s[ACC] ^= this.fetch(); return;
      case 0x65: s[ACC] ^= this.readDirect(this.fetch()); return;
      case 0x70: { const o = this.fetch(); if (s[ACC] !== 0) this.pc = this.rel(o); return; }
      case 0x72: { const b = this.fetch(); this.cy = this.cy | this.readBit(b); return; }
      case 0x73: this.pc = (s[ACC] + this.dptr) & 0xFFFF; return;
      case 0x74: s[ACC] = this.fetch(); return;
      case 0x75: { const d = this.fetch(), i = this.fetch(); this.writeDirect(d, i); return; }
      case 0x80: { const o = this.fetch(); this.pc = this.rel(o); return; }
      case 0x82: { const b = this.fetch(); this.cy = this.cy & this.readBit(b); return; }
      case 0x83: s[ACC] = this.bus.code((s[ACC] + this.pc) & 0xFFFF); return;
      case 0x84: {                                                           // DIV AB
        const a = s[ACC], b = s[B];
        if (b === 0) { this.setFlags(0, (s[PSW] >> 6) & 1, 1); return; }
        s[ACC] = Math.floor(a / b); s[B] = a % b; this.setFlags(0, (s[PSW] >> 6) & 1, 0); return;
      }
      case 0x85: { const src = this.fetch(), dst = this.fetch(); this.writeDirect(dst, this.readDirect(src)); return; }
      case 0x90: { const h = this.fetch(), l = this.fetch(); s[DPH] = h; s[DPL] = l; return; }
      case 0x92: this.writeBit(this.fetch(), this.cy); return;
      case 0x93: s[ACC] = this.bus.code((s[ACC] + this.dptr) & 0xFFFF); return;
      case 0x94: this.subb(this.fetch()); return;
      case 0x95: this.subb(this.readDirect(this.fetch())); return;
      case 0xA0: { const b = this.fetch(); this.cy = this.cy | (this.readBit(b) ^ 1); return; }
      case 0xA2: this.cy = this.readBit(this.fetch()); return;
      case 0xA3: this.dptr = (this.dptr + 1) & 0xFFFF; return;
      case 0xA4: {                                                           // MUL AB
        const r = s[ACC] * s[B]; s[ACC] = r & 0xFF; s[B] = r >> 8;
        this.setFlags(0, (s[PSW] >> 6) & 1, r > 0xFF); return;
      }
      case 0xA5: return;                                                     // ongeldig
      case 0xB0: { const b = this.fetch(); this.cy = this.cy & (this.readBit(b) ^ 1); return; }
      case 0xB2: { const b = this.fetch(); this.writeBit(b, this.readBit(b, true) ^ 1); return; }
      case 0xB3: this.cy = this.cy ^ 1; return;
      case 0xB4: {
        const i = this.fetch(), o = this.fetch(), a = s[ACC];
        this.cy = a < i ? 1 : 0; if (a !== i) this.pc = this.rel(o); return;
      }
      case 0xB5: {
        const d = this.fetch(), o = this.fetch(), a = s[ACC], v = this.readDirect(d);
        this.cy = a < v ? 1 : 0; if (a !== v) this.pc = this.rel(o); return;
      }
      case 0xC0: this.push(this.readDirect(this.fetch())); return;
      case 0xC2: this.writeBit(this.fetch(), 0); return;
      case 0xC3: this.cy = 0; return;
      case 0xC4: { const a = s[ACC]; s[ACC] = ((a << 4) | (a >> 4)) & 0xFF; return; }
      case 0xC5: { const d = this.fetch(); const t = this.readDirect(d); this.writeDirect(d, s[ACC]); s[ACC] = t; return; }
      case 0xD0: { const d = this.fetch(); this.writeDirect(d, this.pop()); return; }
      case 0xD2: this.writeBit(this.fetch(), 1); return;
      case 0xD3: this.cy = 1; return;
      case 0xD4: {                                                           // DA A
        let a = s[ACC], c = this.cy;
        if ((a & 0x0F) > 9 || (s[PSW] & 0x40)) { a += 6; if (a > 0xFF) c = 1; a &= 0xFF; }
        if ((a >> 4) > 9 || c) { a += 0x60; if (a > 0xFF) c = 1; a &= 0xFF; }
        s[ACC] = a; this.cy = c; return;
      }
      case 0xD5: {
        const d = this.fetch(), o = this.fetch();
        const v = (this.readDirect(d, true) - 1) & 0xFF; this.writeDirect(d, v);
        if (v) this.pc = this.rel(o); return;
      }
      case 0xE0: s[ACC] = this.bus.xread(this.dptr); return;
      case 0xE2: s[ACC] = this.bus.xread((s[P2] << 8) | this.iram[this.regAddr(0)]); return;
      case 0xE3: s[ACC] = this.bus.xread((s[P2] << 8) | this.iram[this.regAddr(1)]); return;
      case 0xE4: s[ACC] = 0; return;
      case 0xE5: s[ACC] = this.readDirect(this.fetch()); return;
      case 0xF0: this.bus.xwrite(this.dptr, s[ACC]); return;
      case 0xF2: this.bus.xwrite((s[P2] << 8) | this.iram[this.regAddr(0)], s[ACC]); return;
      case 0xF3: this.bus.xwrite((s[P2] << 8) | this.iram[this.regAddr(1)], s[ACC]); return;
      case 0xF4: s[ACC] ^= 0xFF; return;
      case 0xF5: this.writeDirect(this.fetch(), s[ACC]); return;
    }
    throw new Error('opcode niet geïmplementeerd: ' + op.toString(16));
  }

  // ---------- randapparatuur ----------
  tickPeripherals(n) {
    const s = this.sfr;
    this.cycles += n;
    const tcon = s[TCON], tmod = s[TMOD];
    // externe interrupts INT0/INT1 (P3.2/P3.3)
    const p3 = this.bus.pins(3);
    for (let i = 0; i < 2; i++) {
      const pin = (p3 >> (2 + i)) & 1;
      const itBit = i === 0 ? 0x01 : 0x04, ieBit = i === 0 ? 0x02 : 0x08;
      if (s[TCON] & itBit) { if (this.lastInt[i] === 1 && pin === 0) s[TCON] |= ieBit; }
      else if (pin === 0) s[TCON] |= ieBit; else s[TCON] &= ~ieBit;
      this.lastInt[i] = pin;
    }
    // timer 0
    if (tcon & 0x10) this.timerRun(0, tmod & 0x0F, n);
    // timer 1 (ook baudrategenerator)
    if (tcon & 0x40) {
      const ov = this.timerRun(1, (tmod >> 4) & 0x0F, n);
      for (let k = 0; k < ov; k++) this.uartBaudTick();
    }
    this.bus.tick(n);
  }

  // telt n cycli, geeft aantal overflows terug
  timerRun(t, mode, n) {
    const s = this.sfr;
    if (mode & 0x08) {                           // GATE
      const pin = (this.bus.pins(3) >> (2 + t)) & 1;
      if (!pin) return 0;
    }
    if (mode & 0x04) return 0;                   // tellermodus (externe pin) niet gemodelleerd
    const TL = t ? TL1 : TL0, TH = t ? TH1 : TH0, TF = t ? 0x80 : 0x20;
    let ov = 0;
    switch (mode & 3) {
      case 0: {                                  // 13 bit
        let v = ((s[TH] << 5) | (s[TL] & 0x1F)) + n;
        if (v > 0x1FFF) { ov = 1; v &= 0x1FFF; }
        s[TH] = v >> 5; s[TL] = (s[TL] & 0xE0) | (v & 0x1F); break;
      }
      case 1: {                                  // 16 bit
        let v = ((s[TH] << 8) | s[TL]) + n;
        if (v > 0xFFFF) { ov = 1; v &= 0xFFFF; }
        s[TH] = v >> 8; s[TL] = v & 0xFF; break;
      }
      case 2: {                                  // 8 bit auto-reload
        let v = s[TL] + n;
        while (v > 0xFF) { ov++; v = v - 0x100 + s[TH]; }
        s[TL] = v; break;
      }
      case 3: {                                  // timer 0 gesplitst; timer 1 stopt
        if (t === 1) return 0;
        let v = s[TL0] + n; if (v > 0xFF) { s[TCON] |= 0x20; v &= 0xFF; } s[TL0] = v;
        if (s[TCON] & 0x40) { let h = s[TH0] + n; if (h > 0xFF) { s[TCON] |= 0x80; h &= 0xFF; } s[TH0] = h; }
        return 0;
      }
    }
    if (ov) s[TCON] |= TF;
    return ov;
  }

  uartBaudTick() {
    const s = this.sfr, u = this.uart;
    const div = (s[PCON] & 0x80) ? 16 : 32;
    if (++u.tick < div) return;
    u.tick = 0;
    // zenden
    if (u.txBits > 0 && --u.txBits === 0) {
      s[SCON] |= 0x02;                                   // TI
      this.bus.serialTx(u.txByte, u.txBit8);
    }
    // ontvangen
    if (u.rxBits > 0) {
      if (--u.rxBits === 0) {
        const f = u.rxFrame, mode = s[SCON] >> 6, sm2 = (s[SCON] >> 5) & 1;
        const ninth = mode === 1 ? 1 : f.bit8;
        if (!(s[SCON] & 0x01) && (!sm2 || ninth)) {
          u.sbufRx = f.byte;
          s[SCON] = (s[SCON] & ~0x04) | (ninth ? 0x04 : 0) | 0x01;   // RB8, RI
        }
        u.rxFrame = null;
      }
    } else if (s[SCON] & 0x10) {                          // REN
      const f = this.bus.serialRxAvailable();
      if (f) { u.rxFrame = f; u.rxBits = (s[SCON] >> 6) === 1 ? 10 : 11; }
    }
  }

  checkInterrupts() {
    const s = this.sfr, ie = s[IE];
    if (!(ie & 0x80) || this.inService[1]) return;
    // bronnen in vaste pollingvolgorde: INT0, T0, INT1, T1, seriëel
    const pend = [
      (s[TCON] & 0x02) && (ie & 0x01),
      (s[TCON] & 0x20) && (ie & 0x02),
      (s[TCON] & 0x08) && (ie & 0x04),
      (s[TCON] & 0x80) && (ie & 0x08),
      (s[SCON] & 0x03) && (ie & 0x10),
    ];
    for (const level of [1, 0]) {
      if (level === 0 && this.inService[0]) return;
      for (let i = 0; i < 5; i++) {
        if (!pend[i] || ((s[IP] >> i) & 1) !== level) continue;
        if (i === 0 && (s[TCON] & 0x01)) s[TCON] &= ~0x02;     // flankgevoelig: IE0 wissen
        if (i === 1) s[TCON] &= ~0x20;                          // TF0
        if (i === 2 && (s[TCON] & 0x04)) s[TCON] &= ~0x08;     // IE1
        if (i === 3) s[TCON] &= ~0x80;                          // TF1
        this.idle = false;
        this.push(this.pc & 0xFF); this.push(this.pc >> 8);
        this.pc = 0x03 + 8 * i;
        this.inService[level] = true;
        this.tickPeripherals(2);
        return;
      }
    }
  }
}
