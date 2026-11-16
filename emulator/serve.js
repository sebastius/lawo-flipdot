#!/usr/bin/env node
// Minimale statische webserver voor de emulator (geen afhankelijkheden).
//   node emulator/serve.js [poort]   ->  http://localhost:8051/emulator/web/
import { createServer } from 'node:http';
import { readFile } from 'node:fs/promises';
import { extname, join, normalize, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const root = resolve(fileURLToPath(new URL('..', import.meta.url)));
const port = Number(process.argv[2] || 8051);
const types = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript; charset=utf-8', '.css': 'text/css', '.svg': 'image/svg+xml', '.png': 'image/png' };

createServer(async (req, res) => {
  const url = decodeURIComponent(new URL(req.url, 'http://x').pathname);
  const path = normalize(join(root, url.endsWith('/') ? url + 'index.html' : url));
  if (!path.startsWith(root)) { res.writeHead(403).end(); return; }
  try {
    const data = await readFile(path);
    res.writeHead(200, { 'Content-Type': types[extname(path)] || 'application/octet-stream', 'Cache-Control': 'no-cache' }).end(data);
  } catch {
    res.writeHead(404).end('niet gevonden');
  }
}).listen(port, '127.0.0.1', () => console.log(`emulator: http://localhost:${port}/emulator/web/`));
