#!/usr/bin/env python3
"""Maak voorbeeldbitmaps (112 x 16) voor ASFP-bitmap: PNG + kant-en-klaar aB-telegram.

    python3 firmware-patches/asfp-bitmap/examples/make_examples.py
"""
from pathlib import Path

W, H = 112, 16
HERE = Path(__file__).resolve().parent

# zittende kat in profiel, kijkt naar rechts, staart om de voorpoten
CAT = """
..............#..#..
..............##.##.
..............######
.............#######
.............##.####
.............#######
..............####..
...........#######..
..........########..
.........#########..
........##########..
##.....###########..
.##...############..
..##.#############..
...###############..
....##############..
"""

# rennende muis, kijkt naar rechts: oor, oog, snuit, pootjes, staart
MOUSE = """
.......##....
......####...
...#########.
..######.####
.###########.
#.#########..
...#.....#...
"""

CHEESE = """
.........###
......######
...#########
############
##.#####.###
############
#####.######
############
"""


def sprite(text):
    rows = [r for r in text.strip("\n").split("\n")]
    return [[c == "#" for c in r] for r in rows]


def blit(img, spr, x0, y0, flip=False):
    for y, row in enumerate(spr):
        for x, on in enumerate(row[::-1] if flip else row):
            if on and 0 <= x0 + x < W and 0 <= y0 + y < H:
                img[y0 + y][x0 + x] = True


def scene_cat_and_mice():
    img = [[False] * W for _ in range(H)]
    blit(img, sprite(CAT), 2, 0)
    mouse = sprite(MOUSE)
    for x, y in ((34, 9), (57, 8), (80, 9)):
        blit(img, mouse, x, y)
        for dx in (-7, -5, -3):                      # snelheidsstreepjes
            img[y + 3][x + dx] = True
    blit(img, sprite(CHEESE), 99, 8)
    return img


def to_words(img):
    words = []
    for x in range(W):
        w = 0
        for y in range(H):
            if img[y][x]:
                w |= 1 << y          # bit y = rij y van boven
        words.append(w)
    return words


def write_png(img, path, scale=1):
    import zlib, struct
    rows = b""
    for y in range(H * scale):
        line = bytearray([0])
        for x in range(W * scale):
            line.append(255 if img[y // scale][x // scale] else 0)
        rows += bytes(line)
    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", W * scale, H * scale, 8, 0, 0, 0, 0))
    png += chunk(b"IDAT", zlib.compress(rows, 9)) + chunk(b"IEND", b"")
    path.write_bytes(png)


def main():
    img = scene_cat_and_mice()
    words = to_words(img)
    tele = "aB1000" + "".join(f"{w:04X}" for w in words)
    (HERE / "kat-en-muizen.txt").write_text(tele + "\n")
    write_png(img, HERE / "kat-en-muizen.png")
    for line in img:
        print("".join("#" if v else "." for v in line))
    print(f"\ntelegram: {len(tele) + 1} tekens incl. CR")


if __name__ == "__main__":
    main()
