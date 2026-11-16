import { AZR802, IbisReceiver, decode7seg } from '../core/azr802.js';

const FIRMWARES = [
  ['ASFP.bin', '../../firmware/ASFP.bin'],
  ['AZIPZR1.BIN', '../../firmware/AZIPZR1.BIN'],
  ['AZR-12C.BIN', '../../firmware/AZR-12C.BIN'],
  ['MLAWO_RET_RET60', '../../firmware/MLAWO_RET_RET60.PLM51_18-11-92.bin'],
  ['dvb_azrfr51v16.bin', '../../firmware/dvb_azrfr51v16.bin'],
];
const EPROMS = [
  ['RAM (62256)', null],
  ['RET0902 (TED800)', '../../text-eproms/RET0902_14-10-2002_C256_05F55CD.bin'],
  ['front.bin (FORM)', '../../text-eproms/front.bin'],
];

const $ = (id) => document.getElementById(id);
const uploads = { rom: null, eprom: null };
let board = null, rx = null;

const store = {
  get(k, d) { try { const v = localStorage.getItem('azr-' + k); return v === null ? d : JSON.parse(v); } catch { return d; } },
  set(k, v) { try { localStorage.setItem('azr-' + k, JSON.stringify(v)); } catch { /* geen opslag */ } },
};

function fillSelect(sel, items, saved) {
  sel.innerHTML = '';
  for (const [name, path] of items) {
    const o = document.createElement('option'); o.textContent = name; o.value = path ?? ''; sel.appendChild(o);
  }
  if (saved !== undefined) sel.value = saved;
}

async function fetchBin(path) {
  const r = await fetch(path);
  if (!r.ok) throw new Error(`${path}: ${r.status}`);
  return new Uint8Array(await r.arrayBuffer());
}

function log(cls, text) {
  const el = $('log');
  const line = document.createElement('div');
  line.className = cls;
  line.textContent = (board ? `[${board.time.toFixed(3)}] ` : '') + text;
  el.appendChild(line);
  while (el.childNodes.length > 400) el.removeChild(el.firstChild);
  el.scrollTop = el.scrollHeight;
}

function show(s) { return JSON.stringify(s).slice(1, -1); }

async function load() {
  try {
    const romSel = $('rom').value;
    const rom = romSel === '__upload' ? uploads.rom : await fetchBin(romSel);
    const bank = async (v) => (v === '' ? undefined : v === '__upload' ? uploads.eprom : await fetchBin(v));
    const [cpuType, osc] = $('cpu').value.split('|');
    board = new AZR802({
      rom, rm2: await bank($('rm2').value), rm3: await bank($('rm3').value),
      cpuType, osc: Number(osc), cols: Number($('cols').value), rows: Number($('rows').value),
      address: Number($('addr').value), s1: $('s1').checked ? 0 : 1, s2: $('s2').checked ? 1 : 0,
    });
    rx = new IbisReceiver((t, csOk, parOk) => log(csOk && parOk ? 'rx' : 'err', `display → ${show(t)}${csOk ? '' : ' (checksum fout)'}${parOk ? '' : ' (pariteit fout)'}`));
    board.on('tx', (b) => rx.push(b));
    board.on('log', (m) => log('sys', m));
    board.on('reset', (why) => log('sys', `reset (${why})`));
    setupCanvas();
    buildPresets();
    log('sys', `geladen: ${$('rom').selectedOptions[0].textContent}, adres ${board.address}`);
    for (const id of ['rom', 'rm2', 'rm3', 'cpu', 'cols', 'rows', 'addr']) store.set(id, $(id).value);
    applyUrlActions();
  } catch (e) {
    log('err', 'laden mislukt: ' + e.message + ' (draai de emulator via node emulator/serve.js)');
  }
}

// ---------- display ----------
const CELL = 10;
let ctx;
function setupCanvas() {
  const c = $('screen');
  c.width = board.cols * CELL; c.height = board.rows * CELL;
  ctx = c.getContext('2d');
}
function draw() {
  if (!board || !ctx) return;
  const css = getComputedStyle(document.documentElement);
  const on = css.getPropertyValue('--dot-on').trim(), off = css.getPropertyValue('--dot-off').trim();
  ctx.fillStyle = '#0c0d0f'; ctx.fillRect(0, 0, board.cols * CELL, board.rows * CELL);
  const t = board.time;
  for (let r = 0; r < board.rows; r++) {
    for (let c = 0; c < board.cols; c++) {
      const i = r * board.cols + c;
      const age = t - board.dotTime[i];
      // korte draaianimatie: schijfje smal tijdens de eerste 60 ms
      const w = age < 0.06 ? 0.25 + (age / 0.06) * 0.75 : 1;
      ctx.fillStyle = board.dots[i] ? on : off;
      ctx.beginPath();
      ctx.ellipse(c * CELL + CELL / 2, r * CELL + CELL / 2, 4 * w, 4, 0, 0, Math.PI * 2);
      ctx.fill();
    }
  }
  const l = board.leds();
  $('ld1').classList.toggle('on', l.LD1_reset);
  $('ld2').classList.toggle('on', !!l.LD2);
  $('ld3').classList.toggle('on', !!l.LD3);
  $('ld4').classList.toggle('on', !!l.LD4_bank);
  $('seg').textContent = board.latch[3] ? decode7seg(board.latch[3]) : ' ';
  const st = board.stats;
  $('stats').textContent = `t = ${t.toFixed(2)} s · pulsen ${st.pulses} · flips ${st.flips} · buiten display ${st.outside} · watchdog-resets ${st.wdResets}`;
}

// ---------- telegrammen ----------
function addrChar() { return String.fromCharCode(48 + Number($('addr').value)); }
function buildPresets() {
  const a = addrChar();
  const presets = [
    ['status', `a${a}`], ['versie', `aV${a}`],
    ['test zwart', `aT${a}0`], ['test geel', `aT${a}1`], ['dambord', `aT${a}2`], ['invers', `aT${a}3`],
    ['vrije tekst', `aA${a}1001\\nHallo\\nwereld\\n\\n`], ['lijn 12', 'l012'], ['bestemming 3', 'z003'],
  ];
  const el = $('presets'); el.innerHTML = '';
  for (const [name, tele] of presets) {
    const b = document.createElement('button'); b.textContent = name;
    b.onclick = () => { $('tele').value = tele; send(); };
    el.appendChild(b);
  }
}
function send() {
  if (!board) return;
  const body = $('tele').value.replace(/\\n/g, '\n').replace(/\r?\n$/, (m) => m);
  board.sendTelegram(body);
  log('tx', `→ display ${show(body)}`);
}

// ---------- knoppen ----------
function holdButton(id, key) {
  const b = $(id);
  const down = () => { if (board) board.buttons[key] = true; b.classList.add('held'); };
  const up = () => { if (board) board.buttons[key] = false; b.classList.remove('held'); };
  b.addEventListener('pointerdown', down); b.addEventListener('pointerup', up); b.addEventListener('pointerleave', up);
}

// ---------- hoofdlus ----------
let last = performance.now();
function frame(now) {
  const dt = Math.min((now - last) / 1000, 0.1); last = now;
  const speed = Number($('speed').value);
  if (board && speed > 0) {
    try { board.runCycles(Math.round(dt * board.cyclesPerSecond * speed)); }
    catch (e) { log('err', 'CPU-fout: ' + e.message); $('speed').value = '0'; }
  }
  draw();
  requestAnimationFrame(frame);
}

// URL-parameters: ?rom=ASFP.bin&addr=1&prerun=3&send=aA11001\nHallo\n\n&after=5&speed=1
const params = new URLSearchParams(location.search);
function applyUrlParams() {
  const rom = params.get('rom');
  if (rom) { const f = FIRMWARES.find(([n]) => n === rom); if (f) $('rom').value = f[1]; }
  for (const k of ['addr', 'cols', 'rows', 'speed']) if (params.has(k)) $(k).value = params.get(k);
}
let urlActionsDone = false;
function applyUrlActions() {
  if (urlActionsDone) return;
  urlActionsDone = true;
  if (params.has('prerun')) board.runSeconds(Number(params.get('prerun')));
  if (params.has('send')) {
    $('tele').value = params.get('send');
    send();
    if (params.has('after')) board.runSeconds(Number(params.get('after')));
  }
  draw();
}

function init() {
  fillSelect($('rom'), [...FIRMWARES, ['eigen bestand (upload)…', '__upload']], store.get('rom', FIRMWARES[0][1]));
  fillSelect($('rm2'), [...EPROMS, ['geüpload bestand', '__upload']], store.get('rm2', ''));
  fillSelect($('rm3'), [...EPROMS, ['geüpload bestand', '__upload']], store.get('rm3', ''));
  for (const id of ['cpu', 'cols', 'rows', 'addr']) { const v = store.get(id, null); if (v !== null) $(id).value = v; }
  $('romFile').onchange = async (e) => {
    const f = e.target.files[0]; if (!f) return;
    uploads.rom = new Uint8Array(await f.arrayBuffer());
    $('rom').value = '__upload'; log('sys', `firmware geüpload: ${f.name} (${uploads.rom.length} bytes)`); load();
  };
  $('epromFile').onchange = async (e) => {
    const f = e.target.files[0]; if (!f) return;
    uploads.eprom = new Uint8Array(await f.arrayBuffer());
    log('sys', `tekst-EPROM geüpload: ${f.name}; kies "geüpload bestand" bij RM2/RM3 en laad opnieuw`);
  };
  applyUrlParams();
  $('load').onclick = load;
  $('send').onclick = send;
  $('tele').addEventListener('keydown', (e) => { if (e.key === 'Enter' && (e.ctrlKey || e.metaKey)) send(); });
  $('btnReset').onclick = () => { if (board) { board.address = Number($('addr').value); board.cpu.reset(); log('sys', 'reset (knop)'); buildPresets(); } };
  $('s1').onchange = () => { if (board) board.s1 = $('s1').checked ? 0 : 1; };
  $('s2').onchange = () => { if (board) board.s2 = $('s2').checked ? 1 : 0; };
  $('addr').onchange = () => buildPresets();
  holdButton('btnYellow', 'yellow');
  holdButton('btnBlack', 'black');
  load();
  requestAnimationFrame(frame);
}
init();
