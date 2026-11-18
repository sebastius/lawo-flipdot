// Zelfde cache-buster als app.js doorgeven aan de kern (zie index.html).
const V = new URL(import.meta.url).searchParams.get('v') || Date.now();
const { AZR802, IbisReceiver, decode7seg } = await import(`../core/azr802.js?v=${V}`);

const FIRMWARES = [
  ['ASFP.bin', '../../firmware/ASFP.bin'],
  ['AZIPZR1.BIN', '../../firmware/AZIPZR1.BIN'],
  ['AZR-12C.BIN', '../../firmware/AZR-12C.BIN'],
  ['MLAWO_RET_RET60', '../../firmware/MLAWO_RET_RET60.PLM51_18-11-92.bin'],
  ['dvb_azrfr51v16.bin', '../../firmware/dvb_azrfr51v16.bin'],
  ['ASFP-bitmap 6 MHz · 15625 Bd', '../../firmware-patches/asfp-bitmap/ASFP-bitmap-6MHz-15625.bin', '80C31|6000000'],
  ['ASFP-bitmap 12 MHz · 31250 Bd', '../../firmware-patches/asfp-bitmap/ASFP-bitmap-12MHz-31250.bin', '80C31|12000000'],
];
// Standaard: de ASFP-bitmap-firmware die op hardware getest is (6 MHz, 15625 Bd, kolomverschuiving 28).
const DEFAULT_ROM = '../../firmware-patches/asfp-bitmap/ASFP-bitmap-6MHz-15625.bin';
const DEFAULTS_VERSION = '2026-11-18';   // ophogen om opgeslagen keuzes eenmalig te negeren
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
    log('sys', `geladen: ${$('rom').selectedOptions[0].textContent}, adres ${board.address}` +
      (xoff() ? `; pixels en bitmaps beginnen op kolom ${xoff()} (kolomverschuiving)` : ''));
    imageToWords();
    for (const id of ['rom', 'rm2', 'rm3', 'cpu', 'cols', 'rows', 'addr']) store.set(id, $(id).value);
    applyUrlActions();
  } catch (e) {
    const hint = location.protocol === 'file:' ? ' (open de emulator via node emulator/serve.js, niet als bestand)'
      : /fetch|NetworkError|: 404/.test(e.message) ? ' (bestand niet gevonden)' : ' (probeer Ctrl+Shift+R)';
    log('err', 'laden mislukt: ' + e.message + hint);
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

// ---------- telegrammen samenstellen ----------
// Symbolen in de ASFP-font (DIN 66003-variant): ze staan op de plek van gewone ASCII-tekens.
const SYMBOLS = [['🚶', '$', 'loopmannetje'], ['Ⓢ', '=', 'S-Bahn'], ['Ⓤ', '?', 'U-Bahn']];
const UMLAUT = { 'Ä': '[', 'Ö': '\\', 'Ü': ']', 'ä': '{', 'ö': '|', 'ü': '}', 'ß': '~' };
const SPECIAL = '$%=?^_[\\]{|}~';

const pad = (n, w) => String(Math.max(0, Math.min(10 ** w - 1, Math.floor(Number(n) || 0)))).padStart(w, '0');
const tAddr = () => String.fromCharCode(48 + Math.max(0, Math.min(15, Number($('taddr').value) || 0)));

function encodeText(text, warnings) {
  const lines = text.replace(/\r/g, '').split('\n');
  const pages = []; let cur = [];
  for (const l of lines) {
    if (l.trim() === '') { if (cur.length) pages.push(cur); cur = []; } else cur.push(l.trim());
  }
  if (cur.length) pages.push(cur);
  let literal = false, dropped = false;
  const conv = (str) => {
    let out = '';
    for (const ch of str) {
      const sym = SYMBOLS.find(([g]) => g === ch);
      if (sym) { out += sym[1]; continue; }
      if (UMLAUT[ch] && $('fumlaut').checked) { out += UMLAUT[ch]; continue; }
      if (SPECIAL.includes(ch)) literal = true;
      const code = ch.charCodeAt(0);
      if (code >= 0x20 && code < 0x7F) { out += ch; continue; }
      const plain = ch.normalize('NFD').replace(/[̀-ͯ]/g, '');
      if (plain.length === 1 && plain.charCodeAt(0) < 0x7F) { out += plain; dropped = true; continue; }
      dropped = true;
    }
    return out;
  };
  let body = '';
  pages.forEach((p, i) => {
    if (p.length > 2) warnings.push(`pagina ${i + 1} heeft ${p.length} regels; alleen de eerste twee worden getoond`);
    // één regel: "regel\n\n\n", twee regels: "regel1\nregel2\n\n" (getest in de emulator)
    body += conv(p[0]) + '\n' + (p[1] !== undefined ? conv(p[1]) : '') + '\n\n';
  });
  if (literal) warnings.push('tekens als ? = $ % [ ] { } verschijnen als symbool of umlaut (DIN 66003)');
  if (dropped) warnings.push('accenten en onbekende tekens zijn vereenvoudigd of weggelaten');
  if (!pages.length) body = '\n\n';
  return body;
}

function buildTelegram() {
  const kind = $('kind').value, warnings = [];
  let body;
  switch (kind) {
    case 'text': {
      // na het adres: 1 teken (genegeerd) + 3 tekens lijnnummer; "000" = geen lijnnummer (getest in de emulator)
      const ln = $('fline').value.trim();
      const head = ln === '' ? '0000' : '1' + (/^\d+$/.test(ln) ? ln.padStart(3, '0') : ln.padEnd(3, ' ').slice(0, 3));
      body = `aA${tAddr()}${head}\n` + encodeText($('ftext').value, warnings);
      break;
    }
    case 'dest': body = 'z' + pad($('fnum').value, 3); break;
    case 'line': body = 'l' + pad($('fnum').value, 3); break;
    case 'course': body = 'k' + pad($('fnum').value, 2); break;
    case 'test': body = `aT${tAddr()}${$('fpattern').value}`; break;
    case 'status': body = `a${tAddr()}`; break;
    case 'version': body = `aV${tAddr()}`; break;
    case 'pixel': body = `aP${tAddr()}` + pad($('fpx').value, 3) + pad($('fpy').value, 2) + $('fpc').value; break;
    case 'full': body = `aU${tAddr()}`; break;
    case 'bitmap': {
      if (!bitmapWords) { warnings.push('kies eerst een afbeelding'); body = `aB${tAddr()}000`; break; }
      body = `aB${tAddr()}000` + bitmapWords.map((w) => w.toString(16).padStart(4, '0').toUpperCase()).join('');
      break;
    }
    default: body = $('tele').value.replace(/\\n/g, '\n').replace(/\\r/g, '\r');
  }
  const limit = (kind === 'bitmap' || kind === 'pixel') ? 500 : 249;
  if (body.length + 1 > limit) warnings.push(`telegram is ${body.length + 1} tekens; de firmware negeert alles boven ~${limit} tekens`);
  if (['pixel', 'bitmap', 'full'].includes(kind) && !$('rom').value.includes('ASFP-bitmap')) warnings.push('dit telegram werkt alleen met de ASFP-bitmap-firmware');
  return { body, warnings };
}

function checksum(body) { let cs = 0x7F; for (const ch of body + '\r') cs ^= ch.charCodeAt(0); return cs; }

function updateBuilder() {
  const kind = $('kind').value;
  for (const f of document.querySelectorAll('.fields')) f.hidden = !f.dataset.kind.split(' ').includes(kind);
  $('screen').style.cursor = kind === 'pixel' ? 'crosshair' : '';
  $('numhint').textContent = {
    dest: 'DS003: bestemmingsnummer. MLAWO/AZR-12C zoeken de tekst op in de tekst-EPROM.',
    line: 'DS001: lijnnummer, getoond in het lijnnummervak.',
    course: 'DS002: koersnummer (2 cijfers volgens VDV 300).',
  }[kind] || '';
  const { body, warnings } = buildTelegram();
  const esc = (t) => t.replace(/[&<>]/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;' }[c]));
  $('preview').innerHTML = esc(body).replace(/\n/g, '<span class="ctl">↵</span>') +
    `<span class="ctl">␍ + checksum 0x${checksum(body).toString(16).padStart(2, '0').toUpperCase()}</span>`;
  $('plen').textContent = `${body.length + 2} tekens`;
  $('pwarn').textContent = warnings.join(' · ');
  store.set('kind', kind); store.set('ftext', $('ftext').value); store.set('fline', $('fline').value);
}

function send() {
  if (!board) return;
  const { body } = buildTelegram();
  board.sendTelegram(body);
  log('tx', `→ display ${show(body)}`);
}

function insertAtCursor(el, text) {
  const s = el.selectionStart ?? el.value.length, e = el.selectionEnd ?? s;
  el.value = el.value.slice(0, s) + text + el.value.slice(e);
  el.selectionStart = el.selectionEnd = s + text.length;
  el.focus();
}

// ---------- bitmap uit afbeelding ----------
let bitmapWords = null, bitmapImg = null;
// kolomverschuiving van de ASFP-bitmap-firmware (byte 0x5FFF): x = 0 is display-kolom xoff
function xoff() {
  if (!board || !$('rom').value.includes('ASFP-bitmap') || board.rom.length <= 0x5FFF) return 0;
  return board.rom[0x5FFF];
}

function imageToWords() {
  if (!bitmapImg) return;
  const cols = Math.max(1, Number($('cols').value) - xoff()), rows = Number($('rows').value);
  const c = document.createElement('canvas'); c.width = cols; c.height = rows;
  const g = c.getContext('2d');
  g.fillStyle = '#000'; g.fillRect(0, 0, cols, rows);
  const scale = Math.min(cols / bitmapImg.width, rows / bitmapImg.height);
  const w = bitmapImg.width * scale, h = bitmapImg.height * scale;
  g.drawImage(bitmapImg, (cols - w) / 2, (rows - h) / 2, w, h);
  const px = g.getImageData(0, 0, cols, rows).data, thr = Number($('fthr').value), inv = $('finv').checked;
  bitmapWords = [];
  for (let x = 0; x < cols; x++) {
    let word = 0;
    for (let y = 0; y < rows && y < 16; y++) {
      const i = (y * cols + x) * 4;
      const lum = 0.299 * px[i] + 0.587 * px[i + 1] + 0.114 * px[i + 2];
      if ((lum >= thr) !== inv) word |= 1 << y;
    }
    bitmapWords.push(word);
  }
}

function initBuilder() {
  $('kind').value = store.get('kind', 'text');
  $('ftext').value = store.get('ftext', $('ftext').value);
  $('fline').value = store.get('fline', '');
  $('taddr').value = $('addr').value;
  const sym = $('symbols');
  for (const [glyph, , name] of SYMBOLS) {
    const b = document.createElement('button'); b.type = 'button'; b.textContent = glyph; b.title = name;
    b.onclick = () => { insertAtCursor($('ftext'), glyph); updateBuilder(); };
    sym.appendChild(b);
  }
  $('fimg').addEventListener('change', (e) => {
    const f = e.target.files[0]; if (!f) return;
    const img = new Image();
    img.onload = () => { bitmapImg = img; imageToWords(); updateBuilder(); };
    img.src = URL.createObjectURL(f);
  });
  for (const id of ['finv', 'fthr']) $(id).addEventListener('input', () => { imageToWords(); updateBuilder(); });
  $('screen').addEventListener('click', (e) => {
    if ($('kind').value !== 'pixel' || !board) return;
    const r = $('screen').getBoundingClientRect();
    const x = Math.floor((e.clientX - r.left) / r.width * board.cols);
    const y = Math.floor((e.clientY - r.top) / r.height * board.rows);
    if (x < 0 || y < 0 || x >= board.cols || y >= board.rows) return;
    if (x < xoff()) { log('sys', `kolom ${x} ligt vóór de kolomverschuiving (${xoff()}) van deze firmware`); return; }
    $('fpx').value = x - xoff(); $('fpy').value = y;
    $('fpc').value = board.dots[y * board.cols + x] ? '0' : '1';
    updateBuilder(); send();
  });
  for (const id of ['kind', 'taddr', 'fline', 'ftext', 'fumlaut', 'fnum', 'fpattern', 'tele', 'fpx', 'fpy', 'fpc']) {
    $(id).addEventListener('input', updateBuilder);
    $(id).addEventListener('change', updateBuilder);
  }
  for (const id of ['ftext', 'tele', 'fnum']) {
    $(id).addEventListener('keydown', (e) => { if (e.key === 'Enter' && (e.ctrlKey || e.metaKey)) { e.preventDefault(); send(); } });
  }
  updateBuilder();
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

// URL-parameters: ?rom=ASFP.bin&addr=1&prerun=3&send=aA11001\nHallo\n\n\n&after=5&speed=1
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
    $('kind').value = 'raw';
    $('tele').value = params.get('send');
    updateBuilder();
    send();
    if (params.has('after')) board.runSeconds(Number(params.get('after')));
  }
  draw();
}

function init() {
  const fresh = store.get('defaults', '') !== DEFAULTS_VERSION;
  if (fresh) store.set('defaults', DEFAULTS_VERSION);
  fillSelect($('rom'), [...FIRMWARES, ['eigen bestand (upload)…', '__upload']], fresh ? DEFAULT_ROM : store.get('rom', DEFAULT_ROM));
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
  const syncCpu = () => { const f = FIRMWARES.find(([, p]) => p === $('rom').value); $('cpu').value = (f && f[2]) || '80C31|6000000'; };
  $('rom').addEventListener('change', syncCpu);
  if (fresh || params.has('rom')) syncCpu();
  $('load').onclick = load;
  $('send').onclick = send;
  initBuilder();
  $('btnReset').onclick = () => { if (board) { board.address = Number($('addr').value); board.cpu.reset(); log('sys', 'reset (knop)'); } };
  $('s1').onchange = () => { if (board) board.s1 = $('s1').checked ? 0 : 1; };
  $('s2').onchange = () => { if (board) board.s2 = $('s2').checked ? 1 : 0; };
  $('addr').onchange = () => { $('taddr').value = $('addr').value; updateBuilder(); };
  holdButton('btnYellow', 'yellow');
  holdButton('btnBlack', 'black');
  load();
  requestAnimationFrame(frame);
}
init();
