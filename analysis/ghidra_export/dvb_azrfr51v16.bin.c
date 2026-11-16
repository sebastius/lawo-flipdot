// Ghidra-decompilatie van dvb_azrfr51v16.bin

// ==== VEC_RESET @ CODE:0000  (3 bytes)

void VEC_RESET(void)

{
  reset_entry();
  return;
}



// ==== FUN_CODE_0008 @ CODE:0008  (3 bytes)

void FUN_CODE_0008(void)

{
  ES = 1;
  return;
}



// ==== VEC_TIMER0 @ CODE:000b  (3 bytes)

void VEC_TIMER0(void)

{
  isr_timer0();
  return;
}



// ==== FUN_CODE_001e @ CODE:001e  (4 bytes)

void FUN_CODE_001e(void)

{
  undefined1 uVar1;
  
  uVar1 = INT0;
  return;
}



// ==== FUN_CODE_0022 @ CODE:0022  (1 bytes)

void FUN_CODE_0022(void)

{
  return;
}



// ==== VEC_SERIAL @ CODE:0023  (3 bytes)

void VEC_SERIAL(void)

{
  isr_serial();
  return;
}



// ==== FUN_CODE_0026 @ CODE:0026  (122 bytes)

void FUN_CODE_0026(void)

{
  byte bVar1;
  char cVar2;
  
  cVar2 = ((DAT_EXTMEM_0a27 < 2) << 7) >> 7;
  if ((byte)-cVar2 <= DAT_EXTMEM_0a26) {
    FUN_CODE_2891(DAT_EXTMEM_0a26 + cVar2);
  }
  bVar1 = DAT_EXTMEM_0a26;
  if (DAT_EXTMEM_0a26 == 0) {
    bVar1 = DAT_EXTMEM_0a27 ^ 1;
  }
  if (bVar1 == 0) {
    _2_4 = 1;
    DAT_EXTMEM_0a26 = 0;
    DAT_EXTMEM_0a27 = 0;
  }
  bVar1 = DAT_EXTMEM_080e;
  if (DAT_EXTMEM_080e == 0) {
    bVar1 = DAT_EXTMEM_080f;
  }
  if (bVar1 != 0) {
    FUN_CODE_2891();
  }
  bVar1 = DAT_EXTMEM_080e;
  if (DAT_EXTMEM_080e == 0) {
    bVar1 = DAT_EXTMEM_080f ^ 1;
  }
  if (bVar1 == 0) {
    DAT_EXTMEM_0a14 = 0;
  }
  cVar2 = DAT_EXTMEM_0a2e;
  if (DAT_EXTMEM_0a2e == '\0') {
    cVar2 = DAT_EXTMEM_0a2f;
  }
  if (cVar2 != '\0') {
    FUN_CODE_2891();
  }
  return;
}



// ==== FUN_CODE_00a0 @ CODE:00a0  (272 bytes)

void FUN_CODE_00a0(undefined1 param_1)

{
  char cVar1;
  char cVar2;
  char in_PSW;
  
  LATCH4_802_15 = 0;
  FUN_CODE_2966();
  FUN_CODE_19a6();
  FUN_CODE_2104();
  FUN_CODE_2c9a();
  FUN_CODE_2a44();
  FUN_CODE_1a76();
  FUN_CODE_1fa1();
  FUN_CODE_27e1();
  DAT_EXTMEM_081f = 1;
  DAT_EXTMEM_0b2f = DAT_EXTMEM_0a12;
  DAT_EXTMEM_0b30 = DAT_EXTMEM_0a0b;
  DAT_EXTMEM_0a20 = param_1;
  FUN_CODE_2af7(DAT_EXTMEM_0736,DAT_EXTMEM_073e,DAT_EXTMEM_073f,DAT_EXTMEM_05d9);
  FUN_CODE_2805();
  FUN_CODE_0008();
  FUN_CODE_27f6();
  FUN_CODE_0b4e();
  FUN_CODE_27f6();
  FUN_CODE_0f55();
  FUN_CODE_27f6();
  FUN_CODE_1441();
  FUN_CODE_27f6();
  FUN_CODE_01b0();
  FUN_CODE_27f6();
  FUN_CODE_08de(0,0);
  cVar2 = '\0';
  _0_0 = 0;
  _0_1 = 0;
  FUN_CODE_090f();
  DAT_EXTMEM_05d7 = 0;
  DAT_EXTMEM_05d8 = 0;
  DAT_EXTMEM_0a19 = 0;
  DAT_EXTMEM_0a1a = 0;
  FUN_CODE_77ea(0xef,3,0,0xff,5,1);
  FUN_CODE_27f6();
  while( true ) {
    FUN_CODE_2801();
    if (cVar2 == '\0') break;
    FUN_CODE_27f6();
    FUN_CODE_0022();
    FUN_CODE_342d();
    FUN_CODE_001e();
    if (in_PSW < '\0') {
      FUN_CODE_08de(0xff,0);
      cVar2 = '\0';
      _0_0 = 0;
      _0_1 = 0;
      FUN_CODE_090f();
      DAT_EXTMEM_0a26 = 0;
      DAT_EXTMEM_0a27 = 0;
    }
    FUN_CODE_27eb();
    if (in_PSW < '\0') {
      FUN_CODE_08de(0,0);
      cVar2 = '\0';
      _0_0 = 0;
      _0_1 = 0;
      FUN_CODE_090f();
      DAT_EXTMEM_0a26 = 0;
      DAT_EXTMEM_0a27 = 0;
    }
    cVar1 = LATCH4_802_15;
    in_PSW = (cVar1 == '\0') << 7;
    if ((cVar1 == '\x01') && (LATCH4_802_15 = 0, DAT_EXTMEM_0741 != '\0')) {
      FUN_CODE_08de(0,0);
      cVar2 = '\0';
      _0_0 = 0;
      _0_1 = 0;
      FUN_CODE_090f();
      DAT_EXTMEM_0a26 = 0;
      DAT_EXTMEM_0a27 = 0;
      FUN_CODE_2c9a();
    }
  }
  FUN_CODE_2804();
  return;
}



// ==== FUN_CODE_01b0 @ CODE:01b0  (95 bytes)

char FUN_CODE_01b0(void)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  char *pcVar6;
  
  LATCH5 = 0;
  LATCH6_802_15 = 0;
  while( true ) {
    bVar3 = LATCH5;
    bVar4 = LATCH6_802_15;
    bVar1 = 0x80 - (((bVar4 < 2) << 7) >> 7);
    if (bVar1 <= (bVar3 ^ 0x80)) break;
    uVar5 = 0x4c;
    FUN_CODE_74de(bVar4,0xa0);
    pcVar6 = (char *)CONCAT11((bVar3 << 1 | CARRY1(bVar4,bVar4)) +
                              ('\x05' - (((0x73 < bVar4 * '\x02') << 7) >> 7)),bVar4 * '\x02' + 0x8c
                             );
    *pcVar6 = bVar4 * '\x02' + bVar3 * -0x60 + (char)((ushort)uVar5 >> 8);
    pcVar6[1] = (char)uVar5;
    uVar2 = LATCH6_802_15;
    FUN_CODE_08de(0,uVar2);
    FUN_CODE_7430(0,5,1);
  }
  return (bVar3 ^ 0x80) - bVar1;
}



// ==== FUN_CODE_020f @ CODE:020f  (65 bytes)

void FUN_CODE_020f(undefined1 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined2 uVar4;
  
  uVar4 = 0x82b;
  FUN_CODE_74de(param_1,0xd);
  DAT_EXTMEM_0008 = (byte)uVar4;
  cVar3 = (char)((ushort)uVar4 >> 8);
  LATCH7 = cVar3;
  uVar2 = *(undefined1 *)
           CONCAT11(cVar3 - (((0xf3 < DAT_EXTMEM_0008) << 7) >> 7),DAT_EXTMEM_0008 + 0xc);
  FUN_CODE_22f3();
  uVar1 = LATCH7;
  DAT_EXTMEM_0828 = uVar2;
  FUN_CODE_74ea(CONCAT11(uVar1,DAT_EXTMEM_0008));
  FUN_CODE_7385(0xd);
  return;
}



// ==== FUN_CODE_0250 @ CODE:0250  (306 bytes)

byte FUN_CODE_0250(byte param_1,byte param_2,byte param_3,byte param_4,char param_5)

{
  byte bVar1;
  undefined2 uVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  undefined2 uStack_1;
  
  bVar3 = (param_3 ^ 0x80) + 0x80;
  DAT_EXTMEM_0009 = param_5;
  DAT_EXTMEM_000a = param_3;
  DAT_EXTMEM_000b = param_4;
  if ((((0x7f < (param_3 ^ 0x80)) && (bVar3 = (param_1 ^ 0x80) + 0x80, 0x7f < (param_1 ^ 0x80))) &&
      (bVar1 = 0x80 - (((param_4 < DAT_EXTMEM_0a1b) << 7) >> 7), bVar3 = (param_3 ^ 0x80) - bVar1,
      ((param_3 ^ 0x80) < bVar1) << 7 < '\0')) &&
     (bVar1 = 0x80 - (((param_2 < DAT_EXTMEM_0a23) << 7) >> 7), bVar3 = (param_1 ^ 0x80) - bVar1,
     ((param_1 ^ 0x80) < bVar1) << 7 < '\0')) {
    DAT_EXTMEM_0011 = param_4 & 7;
    bVar3 = (byte)((ushort)param_2 * (ushort)DAT_EXTMEM_0827);
    DAT_EXTMEM_0010 = (param_4 >> 3) + bVar3;
    DAT_EXTMEM_000f =
         (char)((ushort)param_2 * (ushort)DAT_EXTMEM_0827 >> 8) -
         ((CARRY1(param_4 >> 3,bVar3) << 7) >> 7);
    if (DAT_EXTMEM_000e != '\0') {
      uVar2 = *(undefined2 *)
               CONCAT11('\x05' - (((0x73U < (byte)(param_5 * '\x02')) << 7) >> 7),
                        param_5 * '\x02' + 0x8c);
      bVar3 = (byte)uVar2;
      cVar4 = DAT_EXTMEM_0010 + bVar3;
      cVar5 = DAT_EXTMEM_000f +
              ((char)((ushort)uVar2 >> 8) - ((CARRY1(DAT_EXTMEM_0010,bVar3) << 7) >> 7));
      uStack_1 = (byte *)CONCAT11(cVar5,cVar4);
      bVar3 = ('\a' - DAT_EXTMEM_0011) * '\x02';
      bVar3 = *(byte *)CONCAT11(cVar5,cVar4) |
              *(byte *)(CONCAT11(-(((0xf1 < bVar3) << 7) >> 7),bVar3 + 0xe) + 1);
      *uStack_1 = bVar3;
      return bVar3;
    }
    uVar2 = *(undefined2 *)
             CONCAT11('\x05' - (((0x73U < (byte)(param_5 * '\x02')) << 7) >> 7),
                      param_5 * '\x02' + 0x8c);
    bVar3 = (byte)uVar2;
    cVar4 = DAT_EXTMEM_0010 + bVar3;
    cVar5 = DAT_EXTMEM_000f +
            ((char)((ushort)uVar2 >> 8) - ((CARRY1(DAT_EXTMEM_0010,bVar3) << 7) >> 7));
    uStack_1 = (byte *)CONCAT11(cVar5,cVar4);
    bVar3 = ('\a' - DAT_EXTMEM_0011) * '\x02';
    bVar3 = *(byte *)CONCAT11(cVar5,cVar4) &
            ~*(byte *)(CONCAT11(-(((0xf1 < bVar3) << 7) >> 7),bVar3 + 0xe) + 1);
    *uStack_1 = bVar3;
  }
  return bVar3;
}



// ==== FUN_CODE_0382 @ CODE:0382  (1215 bytes)

byte FUN_CODE_0382(char param_1,byte param_2,char param_3)

{
  undefined2 uVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined1 uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  char *pcVar11;
  byte *pbVar12;
  undefined2 uStack_1;
  
  bVar4 = (byte)((ushort)param_2 * 0xd);
  cVar5 = bVar4 + 0x2b;
  cVar6 = ((char)((ushort)param_2 * 0xd >> 8) - (((0xd4 < bVar4) << 7) >> 7)) + '\b';
  cVar2 = '\x01';
  DAT_EXTMEM_0012 = param_3;
  DAT_EXTMEM_0014 = param_1;
  FUN_CODE_74f3(0x32);
  FUN_CODE_74fc();
  if ((cVar5 == '\0' && cVar6 == '\0') && cVar2 == '\0') {
    DAT_EXTMEM_0035 = DAT_EXTMEM_0016;
    while (0x80 < (DAT_EXTMEM_0015 - (((0xfb < DAT_EXTMEM_0016) << 7) >> 7) ^ 0x80) -
                  (((DAT_EXTMEM_0035 < DAT_EXTMEM_0016 + 4) << 7) >> 7)) {
      DAT_EXTMEM_000e = 1;
      FUN_CODE_0250(DAT_EXTMEM_0017,DAT_EXTMEM_0018,0,DAT_EXTMEM_0035,DAT_EXTMEM_0012);
      DAT_EXTMEM_000e = 1;
      FUN_CODE_0250(DAT_EXTMEM_0017 - (((0xf9 < DAT_EXTMEM_0018) << 7) >> 7),DAT_EXTMEM_0018 + 6,0,
                    DAT_EXTMEM_0035,DAT_EXTMEM_0012);
      DAT_EXTMEM_0035 = DAT_EXTMEM_0035 + 1;
    }
    DAT_EXTMEM_0036 = DAT_EXTMEM_0018;
    while (bVar4 = (DAT_EXTMEM_0017 - (((0xf8 < DAT_EXTMEM_0018) << 7) >> 7) ^ 0x80) -
                   (((DAT_EXTMEM_0036 < DAT_EXTMEM_0018 + 7) << 7) >> 7), 0x80 < bVar4) {
      DAT_EXTMEM_000e = 1;
      FUN_CODE_0250(0,DAT_EXTMEM_0036,DAT_EXTMEM_0015,DAT_EXTMEM_0016,DAT_EXTMEM_0012);
      DAT_EXTMEM_000e = 1;
      FUN_CODE_0250(DAT_EXTMEM_0036,DAT_EXTMEM_0015 - (((0xfc < DAT_EXTMEM_0016) << 7) >> 7),
                    DAT_EXTMEM_0016 + 3,DAT_EXTMEM_0012);
      DAT_EXTMEM_0036 = DAT_EXTMEM_0036 + 1;
    }
    return 0x80 - bVar4;
  }
  FUN_CODE_74ea(0x32);
  uVar7 = FUN_CODE_7385(0xc);
  FUN_CODE_22f3();
  DAT_EXTMEM_0828 = uVar7;
  FUN_CODE_74ea(0x32);
  FUN_CODE_74fc();
  cVar5 = FUN_CODE_7385(0xf);
  DAT_EXTMEM_0021 = DAT_EXTMEM_0014 - cVar5;
  FUN_CODE_74ea(0x32);
  FUN_CODE_751c(3);
  uVar7 = (undefined1)((ushort)DAT_EXTMEM_0021 * 3 >> 8);
  bVar4 = FUN_CODE_7385((ushort)DAT_EXTMEM_0021 * 3);
  DAT_EXTMEM_001f = bVar4;
  FUN_CODE_74ea(0x32);
  FUN_CODE_74fc();
  DAT_EXTMEM_0030 = FUN_CODE_7487(0x1c);
  DAT_EXTMEM_002f = uVar7;
  DAT_EXTMEM_0031 = FUN_CODE_7385(0xd);
  if (bVar4 == 0) {
    return 0;
  }
  bVar4 = DAT_EXTMEM_0015 - ((CARRY1(DAT_EXTMEM_0016,DAT_EXTMEM_001f) << 7) >> 7) ^ 0x80;
  if (bVar4 < 0x80) {
    FUN_CODE_74ea(bVar4 + 0x80,0x32);
    FUN_CODE_751c(3);
    bVar4 = FUN_CODE_7385((ushort)DAT_EXTMEM_0021 * 3);
    return bVar4;
  }
  bVar4 = 0x80 - (((DAT_EXTMEM_0016 < DAT_EXTMEM_0a1b) << 7) >> 7);
  if (bVar4 <= (DAT_EXTMEM_0015 ^ 0x80)) {
    FUN_CODE_74ea((DAT_EXTMEM_0015 ^ 0x80) - bVar4,0x32);
    FUN_CODE_751c(3);
    bVar4 = FUN_CODE_7385((ushort)DAT_EXTMEM_0021 * 3);
    return bVar4;
  }
  if (((((DAT_EXTMEM_0015 ^ 0x80) < 0x80) ||
       (0x80U - (((DAT_EXTMEM_0016 + DAT_EXTMEM_001f < DAT_EXTMEM_0a1b + 1) << 7) >> 7) <=
        (DAT_EXTMEM_0015 - ((CARRY1(DAT_EXTMEM_0016,DAT_EXTMEM_001f) << 7) >> 7) ^ 0x80))) ||
      ((DAT_EXTMEM_0017 ^ 0x80) < 0x80)) ||
     (0x80U - (((DAT_EXTMEM_0018 + DAT_EXTMEM_0031 < DAT_EXTMEM_0a23 + 1U) << 7) >> 7) <=
      (DAT_EXTMEM_0017 - ((CARRY1(DAT_EXTMEM_0018,DAT_EXTMEM_0031) << 7) >> 7) ^ 0x80))) {
    DAT_EXTMEM_001c = 0;
  }
  else {
    DAT_EXTMEM_001c = 1;
  }
  DAT_EXTMEM_0022 = DAT_EXTMEM_001f + 7;
  cVar5 = '\x03';
  bVar3 = 0xf8 < DAT_EXTMEM_001f;
  do {
    DAT_EXTMEM_0022 = DAT_EXTMEM_0022 >> 1 | bVar3 << 7;
    cVar5 = cVar5 + -1;
    bVar3 = false;
  } while (cVar5 != '\0');
  FUN_CODE_74ea(0x32);
  FUN_CODE_751c(3);
  bVar4 = (byte)((ushort)DAT_EXTMEM_0021 * 3 >> 8);
  DAT_EXTMEM_0025 = FUN_CODE_7487(1);
  cVar5 = '\x03';
  do {
    DAT_EXTMEM_0024 = bVar4 >> 1;
    DAT_EXTMEM_0025 = DAT_EXTMEM_0025 >> 1 | bVar4 << 7;
    cVar5 = cVar5 + -1;
    bVar4 = DAT_EXTMEM_0024;
  } while (cVar5 != '\0');
  for (DAT_EXTMEM_0019 = 0; (DAT_EXTMEM_0019 < DAT_EXTMEM_0031) << 7 < '\0';
      DAT_EXTMEM_0019 = DAT_EXTMEM_0019 + 1) {
    DAT_EXTMEM_002e = DAT_EXTMEM_0018 + DAT_EXTMEM_0019;
    DAT_EXTMEM_002d = DAT_EXTMEM_0017 - ((CARRY1(DAT_EXTMEM_0018,DAT_EXTMEM_0019) << 7) >> 7);
    DAT_EXTMEM_0020 = DAT_EXTMEM_001f;
    for (DAT_EXTMEM_001a = 0; DAT_EXTMEM_001a < DAT_EXTMEM_0022;
        DAT_EXTMEM_001a = DAT_EXTMEM_001a + 1) {
      bVar4 = DAT_EXTMEM_001a;
      FUN_CODE_74ea(DAT_EXTMEM_001a - DAT_EXTMEM_0022,0x32);
      FUN_CODE_751c(9);
      DAT_EXTMEM_001e = FUN_CODE_736c();
      bVar8 = (byte)((ushort)bVar4 * 8);
      DAT_EXTMEM_002c = DAT_EXTMEM_0016 + bVar8;
      DAT_EXTMEM_002b =
           DAT_EXTMEM_0015 +
           ((char)((ushort)bVar4 * 8 >> 8) - ((CARRY1(DAT_EXTMEM_0016,bVar8) << 7) >> 7));
      if (DAT_EXTMEM_001c == 0) {
        DAT_EXTMEM_001b = DAT_EXTMEM_001c;
        while( true ) {
          bVar4 = DAT_EXTMEM_0020;
          if (8 < DAT_EXTMEM_0020) {
            bVar4 = 8;
          }
          if (bVar4 <= DAT_EXTMEM_001b) break;
          bVar4 = ('\a' - DAT_EXTMEM_001b) * '\x02';
          if ((*(byte *)(CONCAT11(-(((0xf1 < bVar4) << 7) >> 7),bVar4 + 0xe) + 1) & DAT_EXTMEM_001e)
              != 0) {
            bVar4 = (byte)((ushort)DAT_EXTMEM_001a * 8);
            bVar8 = bVar4 + DAT_EXTMEM_001b;
            DAT_EXTMEM_000e = 1;
            FUN_CODE_0250(DAT_EXTMEM_0018 + DAT_EXTMEM_0019,
                          DAT_EXTMEM_0015 +
                          (((char)((ushort)DAT_EXTMEM_001a * 8 >> 8) -
                           ((CARRY1(bVar4,DAT_EXTMEM_001b) << 7) >> 7)) -
                          ((CARRY1(DAT_EXTMEM_0016,bVar8) << 7) >> 7)),DAT_EXTMEM_0016 + bVar8,
                          DAT_EXTMEM_0012);
          }
          DAT_EXTMEM_001b = DAT_EXTMEM_001b + 1;
        }
      }
      else {
        DAT_EXTMEM_0023 = DAT_EXTMEM_002c & 7;
        DAT_EXTMEM_0027 = 0;
        cVar5 = '\t' - DAT_EXTMEM_0023;
        DAT_EXTMEM_001d = DAT_EXTMEM_001e;
        while (cVar5 = cVar5 + -1, cVar5 != '\0') {
          DAT_EXTMEM_0027 = DAT_EXTMEM_0027 << 1 | DAT_EXTMEM_001d >> 7;
          DAT_EXTMEM_001d = DAT_EXTMEM_001d << 1;
        }
        DAT_EXTMEM_0026 = 0;
        cVar6 = '\0';
        bVar8 = DAT_EXTMEM_0827;
        DAT_EXTMEM_002a = DAT_EXTMEM_0027;
        FUN_CODE_73e6(DAT_EXTMEM_002d,DAT_EXTMEM_002e);
        cVar5 = '\x03';
        bVar4 = DAT_EXTMEM_002b;
        bVar10 = DAT_EXTMEM_002c;
        do {
          bVar9 = bVar4 >> 1 | bVar4 & 0x80;
          bVar10 = bVar10 >> 1 | bVar4 << 7;
          cVar5 = cVar5 + -1;
          bVar4 = bVar9;
        } while (cVar5 != '\0');
        bVar4 = bVar10 + bVar8;
        cVar6 = cVar6 + (bVar9 - ((CARRY1(bVar10,bVar8) << 7) >> 7));
        uVar1 = *(undefined2 *)
                 CONCAT11('\x05' - (((0x73U < (byte)(DAT_EXTMEM_0012 * '\x02')) << 7) >> 7),
                          DAT_EXTMEM_0012 * '\x02' + 0x8c);
        bVar8 = (byte)uVar1;
        cVar5 = bVar4 + bVar8;
        cVar2 = cVar6 + ((char)((ushort)uVar1 >> 8) - ((CARRY1(bVar4,bVar8) << 7) >> 7));
        uStack_1 = (byte *)CONCAT11(cVar2,cVar5);
        DAT_EXTMEM_0028 = cVar6;
        DAT_EXTMEM_0029 = bVar4;
        *uStack_1 = *(byte *)CONCAT11(cVar2,cVar5) | DAT_EXTMEM_002a;
        if (DAT_EXTMEM_0023 != 0) {
          pcVar11 = (char *)CONCAT11('\x05' - (((0x73U < (byte)(DAT_EXTMEM_0012 * '\x02')) << 7) >>
                                              7),DAT_EXTMEM_0012 * '\x02' + 0x8c);
          bVar8 = pcVar11[1];
          pbVar12 = (byte *)(CONCAT11(cVar6 + (*pcVar11 - ((CARRY1(bVar8,bVar4) << 7) >> 7)),
                                      bVar8 + bVar4) + 1);
          *pbVar12 = *pbVar12 | DAT_EXTMEM_001d;
        }
      }
      DAT_EXTMEM_0020 = DAT_EXTMEM_0020 - 8;
    }
    FUN_CODE_7430(DAT_EXTMEM_002f,0x24,DAT_EXTMEM_0030);
  }
  return DAT_EXTMEM_001f;
}



// ==== FUN_CODE_0841 @ CODE:0841  (157 bytes)

undefined1 FUN_CODE_0841(undefined1 param_1,byte param_2)

{
  byte bVar1;
  undefined1 uVar2;
  
  DAT_EXTMEM_0037 = param_2;
  DAT_EXTMEM_0038 = param_1;
  FUN_CODE_74f3(0x39);
  DAT_EXTMEM_0042 = DAT_EXTMEM_003d;
  DAT_EXTMEM_0043 = DAT_EXTMEM_003e;
  DAT_EXTMEM_0044 = 0;
  DAT_EXTMEM_0045 = 0;
  while ((DAT_EXTMEM_0044 ^ 0x80) <
         ((char)DAT_EXTMEM_003c >> 7 ^ 0x80U) - (((DAT_EXTMEM_0045 < DAT_EXTMEM_003c) << 7) >> 7)) {
    FUN_CODE_74ea(0x39,DAT_EXTMEM_0038);
    uVar2 = FUN_CODE_7385(CONCAT11(DAT_EXTMEM_0044,DAT_EXTMEM_0045));
    DAT_EXTMEM_0015 = DAT_EXTMEM_0042;
    DAT_EXTMEM_0016 = DAT_EXTMEM_0043;
    DAT_EXTMEM_0017 = DAT_EXTMEM_003f;
    DAT_EXTMEM_0018 = DAT_EXTMEM_0040;
    bVar1 = DAT_EXTMEM_0037;
    FUN_CODE_0382(uVar2);
    FUN_CODE_7430(CARRY1(DAT_EXTMEM_0041,bVar1),0x42,DAT_EXTMEM_0041 + bVar1);
    FUN_CODE_7430(0,0x44,1);
  }
  return DAT_EXTMEM_0043;
}



// ==== FUN_CODE_08de @ CODE:08de  (49 bytes)

void FUN_CODE_08de(char param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           CONCAT11('\x05' - (((0x73U < (byte)(param_1 * '\x02')) << 7) >> 7),
                    param_1 * '\x02' + 0x8c);
  FUN_CODE_79b6(puVar1[1],*puVar1,1,DAT_EXTMEM_05e2,DAT_EXTMEM_05e3);
  return;
}



// ==== FUN_CODE_090f @ CODE:090f  (87 bytes)

void FUN_CODE_090f(char param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  
  if (_0_1 != '\0') {
    bVar3 = 0;
    bVar2 = 0;
    while (bVar2 < (byte)(DAT_EXTMEM_05e2 - (((bVar3 < DAT_EXTMEM_05e3) << 7) >> 7))) {
      pcVar4 = (char *)CONCAT11('\x05' - (((0x73U < (byte)(param_1 * '\x02')) << 7) >> 7),
                                param_1 * '\x02' + 0x8c);
      bVar1 = pcVar4[1];
      pbVar5 = (byte *)CONCAT11(bVar2 + (*pcVar4 - ((CARRY1(bVar1,bVar3) << 7) >> 7)),bVar1 + bVar3)
      ;
      *pbVar5 = ~*pbVar5;
      bVar3 = bVar3 + 1;
      if (bVar3 == 0) {
        bVar2 = bVar2 + 1;
      }
    }
  }
  puVar6 = (undefined1 *)
           CONCAT11('\x05' - (((0x73U < (byte)(param_1 * '\x02')) << 7) >> 7),
                    param_1 * '\x02' + 0x8c);
  _4_1 = _0_0 & 1;
  FUN_CODE_24a9(*puVar6,puVar6[1]);
  return;
}



// ==== uncalled_0966 @ CODE:0966  (107 bytes)

byte uncalled_0966(byte param_1,byte param_2,undefined1 param_3)

{
  DAT_EXTMEM_0046 = param_1;
  DAT_EXTMEM_0047 = param_2;
  DAT_EXTMEM_0048 = param_1;
  DAT_EXTMEM_0049 = param_2;
  while( true ) {
    if ((DAT_EXTMEM_0046 - ((CARRY1(DAT_EXTMEM_0047,DAT_EXTMEM_0827) << 7) >> 7)) -
        (((DAT_EXTMEM_0049 < DAT_EXTMEM_0047 + DAT_EXTMEM_0827) << 7) >> 7) <= DAT_EXTMEM_0048)
    break;
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0048 +
              (DAT_EXTMEM_058c - ((CARRY1(DAT_EXTMEM_058d,DAT_EXTMEM_0049) << 7) >> 7)),
              DAT_EXTMEM_058d + DAT_EXTMEM_0049) = param_3;
    FUN_CODE_7430(0,0x48,1);
  }
  FUN_CODE_7430(0,0x46,DAT_EXTMEM_0827);
  return DAT_EXTMEM_0047;
}



// ==== FUN_CODE_0a0a @ CODE:0a0a  (90 bytes)

undefined1 FUN_CODE_0a0a(byte param_1,byte param_2)

{
  DAT_EXTMEM_0590 = param_1;
  DAT_EXTMEM_0591 = param_2;
  FUN_CODE_27f6();
  if (DAT_EXTMEM_0590 < (byte)(DAT_EXTMEM_0825 - (((DAT_EXTMEM_0591 < DAT_EXTMEM_0826) << 7) >> 7)))
  {
    return DAT_EXTMEM_082a;
  }
  if ((((*(char *)CONCAT11(DAT_EXTMEM_0590,DAT_EXTMEM_0591) == 'F') &&
       (((char *)CONCAT11(DAT_EXTMEM_0590,DAT_EXTMEM_0591))[1] == 'O')) &&
      (*(char *)(CONCAT11(DAT_EXTMEM_0590,DAT_EXTMEM_0591) + 2) == 'R')) &&
     (*(char *)(CONCAT11(DAT_EXTMEM_0590,DAT_EXTMEM_0591) + 3) == 'M')) {
    return 0x4d;
  }
  return DAT_EXTMEM_082a;
}



// ==== FUN_CODE_0a64 @ CODE:0a64  (143 bytes)

byte FUN_CODE_0a64(char param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  DAT_EXTMEM_0a09 = param_1;
  DAT_EXTMEM_0a0a = param_2;
  bVar3 = *(byte *)CONCAT11(param_1,param_2) ^ 0x46;
  if ((((bVar3 == 0) && (bVar3 = *(byte *)(CONCAT11(param_1,param_2) + 1) ^ 0x4f, bVar3 == 0)) &&
      (bVar3 = *(byte *)(CONCAT11(param_1,param_2) + 2) ^ 0x52, bVar3 == 0)) &&
     (((bVar3 = *(byte *)(CONCAT11(param_1,param_2) + 3) ^ 0x4d, bVar3 == 0 &&
       (bVar3 = *(byte *)CONCAT11(param_1 - (((0xfb < param_2) << 7) >> 7),param_2 + 4) ^
                ~*(byte *)CONCAT11(param_1 - (((0xfa < param_2) << 7) >> 7),param_2 + 5), bVar3 == 0
       )) && (pbVar4 = (byte *)CONCAT11(param_1 - (((0xeb < param_2) << 7) >> 7),param_2 + 0x14),
             bVar1 = *pbVar4,
             bVar2 = (DAT_EXTMEM_0829 -
                     (DAT_EXTMEM_0825 - (((DAT_EXTMEM_082a < DAT_EXTMEM_0826) << 7) >> 7))) -
                     (((pbVar4[1] < (DAT_EXTMEM_082a - DAT_EXTMEM_0826) + 1) << 7) >> 7),
             bVar3 = bVar1 - bVar2, bVar1 < bVar2)))) {
    return bVar3;
  }
  return bVar3;
}



// ==== FUN_CODE_0af3 @ CODE:0af3  (91 bytes)

byte FUN_CODE_0af3(byte param_1,byte param_2)

{
  byte bVar1;
  
  FUN_CODE_0a0a();
  DAT_EXTMEM_0592 = param_1;
  DAT_EXTMEM_0593 = param_2;
  while( true ) {
    bVar1 = DAT_EXTMEM_0829 - (((DAT_EXTMEM_0593 < DAT_EXTMEM_082a) << 7) >> 7);
    if (bVar1 <= DAT_EXTMEM_0592) {
      return DAT_EXTMEM_0592 - bVar1;
    }
    DAT_EXTMEM_0594 = DAT_EXTMEM_0592;
    DAT_EXTMEM_0595 = DAT_EXTMEM_0593;
    bVar1 = DAT_EXTMEM_0593;
    FUN_CODE_0a64(DAT_EXTMEM_0592,DAT_EXTMEM_0593);
    if (bVar1 == 1) break;
    FUN_CODE_297b();
    DAT_EXTMEM_0592 = DAT_EXTMEM_0829;
    DAT_EXTMEM_0593 = DAT_EXTMEM_082a;
  }
  FUN_CODE_2974();
  return DAT_EXTMEM_0595;
}



// ==== FUN_CODE_0b4e @ CODE:0b4e  (938 bytes)

void FUN_CODE_0b4e(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  
  DAT_EXTMEM_0599 = 0;
  FUN_CODE_2982();
  DAT_EXTMEM_05de = DAT_EXTMEM_0829;
  DAT_EXTMEM_05df = DAT_EXTMEM_082a;
  DAT_EXTMEM_05dd = 0;
  for (DAT_EXTMEM_0596 = 0; bVar2 = DAT_EXTMEM_082a, bVar4 = DAT_EXTMEM_0829,
      bVar1 = DAT_EXTMEM_0596, (DAT_EXTMEM_0596 < 3) << 7 < '\0';
      DAT_EXTMEM_0596 = DAT_EXTMEM_0596 + 1) {
    pbVar5 = (byte *)CONCAT11('\x06' - (((0x42 < DAT_EXTMEM_0596 * '\x03') << 7) >> 7),
                              DAT_EXTMEM_0596 * '\x03' + 0xbd);
    *pbVar5 = DAT_EXTMEM_0829;
    pbVar5[1] = bVar2;
    *(undefined1 *)CONCAT11('\x06' - (((0x43 < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' + 0xbc) =
         0;
    pbVar5 = (byte *)CONCAT11('\x06' - (((0x39 < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' - 0x3a);
    *pbVar5 = bVar4;
    pbVar5[1] = bVar2;
    *(undefined1 *)CONCAT11('\x06' - (((0x3a < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' - 0x3b) =
         0;
    bVar4 = DAT_EXTMEM_082a;
    pbVar5 = (byte *)CONCAT11('\x05' - (((0x18 < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' - 0x19);
    *pbVar5 = DAT_EXTMEM_0829;
    pbVar5[1] = bVar4;
    *(undefined1 *)CONCAT11('\x05' - (((0x19 < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' - 0x1a) =
         0;
  }
  for (DAT_EXTMEM_0596 = 0; bVar4 = DAT_EXTMEM_082a, bVar1 = DAT_EXTMEM_0596, DAT_EXTMEM_0596 < 0x20
      ; DAT_EXTMEM_0596 = DAT_EXTMEM_0596 + 1) {
    pbVar5 = (byte *)CONCAT11('\x06' - (((0x29 < DAT_EXTMEM_0596 * '\x03') << 7) >> 7),
                              DAT_EXTMEM_0596 * '\x03' - 0x2a);
    *pbVar5 = DAT_EXTMEM_0829;
    pbVar5[1] = bVar4;
    *(undefined1 *)CONCAT11('\x06' - (((0x2a < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' - 0x2b) =
         0;
  }
  _0_2 = '\0';
  cVar3 = '\0';
  DAT_EXTMEM_0596 = 0;
  do {
    FUN_CODE_27f6(cVar3);
    bVar2 = DAT_EXTMEM_0596;
    FUN_CODE_22f3();
    bVar4 = DAT_EXTMEM_0826;
    bVar1 = DAT_EXTMEM_0825;
    pbVar5 = (byte *)CONCAT11('\b' - (((0xec < DAT_EXTMEM_0596 * '\x02') << 7) >> 7),
                              DAT_EXTMEM_0596 * '\x02' + 0x13);
    DAT_EXTMEM_0828 = bVar2;
    *pbVar5 = DAT_EXTMEM_0825;
    pbVar5[1] = bVar4;
    FUN_CODE_0af3();
    DAT_EXTMEM_0597 = bVar1;
    DAT_EXTMEM_0598 = bVar4;
    while (bVar2 = DAT_EXTMEM_0599, bVar4 = DAT_EXTMEM_0598, bVar1 = DAT_EXTMEM_0597,
          DAT_EXTMEM_0598 != 0 || DAT_EXTMEM_0597 != 0) {
      DAT_EXTMEM_0a09 = DAT_EXTMEM_0597;
      DAT_EXTMEM_0a0a = DAT_EXTMEM_0598;
      DAT_EXTMEM_0820 =
           *(char *)CONCAT11(DAT_EXTMEM_0597 - (((0xfb < DAT_EXTMEM_0598) << 7) >> 7),
                             DAT_EXTMEM_0598 + 4);
      if (DAT_EXTMEM_0820 == '2') {
        bVar2 = *(char *)CONCAT11(DAT_EXTMEM_0597 - (((0xed < DAT_EXTMEM_0598) << 7) >> 7),
                                  DAT_EXTMEM_0598 + 0x12) * '\x03';
        pbVar5 = (byte *)CONCAT11('\x06' - (((0x39 < bVar2) << 7) >> 7),bVar2 - 0x3a);
        *pbVar5 = DAT_EXTMEM_0597;
        pbVar5[1] = bVar4;
        bVar1 = *(char *)CONCAT11(bVar1 - (((0xed < bVar4) << 7) >> 7),bVar4 + 0x12) * '\x03';
        *(byte *)CONCAT11('\x06' - (((0x3a < bVar1) << 7) >> 7),bVar1 - 0x3b) = DAT_EXTMEM_0828;
      }
      else if (DAT_EXTMEM_0820 == '4') {
        bVar2 = *(char *)CONCAT11(DAT_EXTMEM_0597 - (((0xed < DAT_EXTMEM_0598) << 7) >> 7),
                                  DAT_EXTMEM_0598 + 0x12) * '\x03';
        pbVar5 = (byte *)CONCAT11('\x05' - (((0x18 < bVar2) << 7) >> 7),bVar2 - 0x19);
        *pbVar5 = DAT_EXTMEM_0597;
        pbVar5[1] = bVar4;
        bVar1 = *(char *)CONCAT11(bVar1 - (((0xed < bVar4) << 7) >> 7),bVar4 + 0x12) * '\x03';
        *(byte *)CONCAT11('\x05' - (((0x19 < bVar1) << 7) >> 7),bVar1 - 0x1a) = DAT_EXTMEM_0828;
      }
      else if (DAT_EXTMEM_0820 == '6') {
        DAT_EXTMEM_0811 = 2;
        DAT_EXTMEM_05de = DAT_EXTMEM_0597;
        DAT_EXTMEM_05df = DAT_EXTMEM_0598;
        DAT_EXTMEM_05dd = DAT_EXTMEM_0828;
        _0_2 = '\x01';
      }
      else if (DAT_EXTMEM_0820 == '8') {
        if (DAT_EXTMEM_0599 < 0x20) {
          pbVar5 = (byte *)CONCAT11('\x06' - (((0x29 < DAT_EXTMEM_0599 * '\x03') << 7) >> 7),
                                    DAT_EXTMEM_0599 * '\x03' - 0x2a);
          *pbVar5 = DAT_EXTMEM_0597;
          pbVar5[1] = bVar4;
          *(byte *)CONCAT11('\x06' - (((0x2a < bVar2 * '\x03') << 7) >> 7),bVar2 * '\x03' - 0x2b) =
               DAT_EXTMEM_0828;
          DAT_EXTMEM_0599 = DAT_EXTMEM_0599 + 1;
        }
      }
      else if (DAT_EXTMEM_0820 == '@') {
        DAT_EXTMEM_0811 = 4;
        DAT_EXTMEM_05de = DAT_EXTMEM_0597;
        DAT_EXTMEM_05df = DAT_EXTMEM_0598;
        DAT_EXTMEM_05dd = DAT_EXTMEM_0828;
        _0_2 = '\x01';
      }
      else if (DAT_EXTMEM_0820 == '0') {
        bVar2 = *(char *)CONCAT11(DAT_EXTMEM_0597 - (((0xed < DAT_EXTMEM_0598) << 7) >> 7),
                                  DAT_EXTMEM_0598 + 0x12) * '\x03';
        pbVar5 = (byte *)CONCAT11('\x06' - (((0x42 < bVar2) << 7) >> 7),bVar2 + 0xbd);
        *pbVar5 = DAT_EXTMEM_0597;
        pbVar5[1] = bVar4;
        bVar1 = *(char *)CONCAT11(bVar1 - (((0xed < bVar4) << 7) >> 7),bVar4 + 0x12) * '\x03';
        *(byte *)CONCAT11('\x06' - (((0x43 < bVar1) << 7) >> 7),bVar1 + 0xbc) = DAT_EXTMEM_0828;
      }
      puVar6 = (undefined1 *)
               CONCAT11(DAT_EXTMEM_0a09 - (((0xeb < DAT_EXTMEM_0a0a) << 7) >> 7),
                        DAT_EXTMEM_0a0a + 0x14);
      FUN_CODE_7430(*puVar6,0x597,puVar6[1]);
      bVar4 = DAT_EXTMEM_0598;
      bVar1 = DAT_EXTMEM_0597;
      pbVar5 = (byte *)CONCAT11('\b' - (((0xec < DAT_EXTMEM_0596 * '\x02') << 7) >> 7),
                                DAT_EXTMEM_0596 * '\x02' + 0x13);
      *pbVar5 = DAT_EXTMEM_0597;
      pbVar5[1] = bVar4;
      bVar4 = bVar4 ^ DAT_EXTMEM_0826;
      if (bVar4 == 0) {
        bVar4 = bVar1 ^ DAT_EXTMEM_0825;
      }
      if ((bVar4 == 0) ||
         (bVar1 = DAT_EXTMEM_0829 - (((DAT_EXTMEM_0598 < DAT_EXTMEM_082a) << 7) >> 7),
         bVar1 <= DAT_EXTMEM_0597)) break;
      FUN_CODE_0af3(DAT_EXTMEM_0597 - bVar1);
    }
    bVar1 = DAT_EXTMEM_082a;
    bVar4 = DAT_EXTMEM_0596 + 1;
    cVar3 = DAT_EXTMEM_0596 - 3;
    DAT_EXTMEM_0596 = bVar4;
    if (3 < bVar4) {
      bVar4 = DAT_EXTMEM_0599 - 0x20;
      if (DAT_EXTMEM_0599 < 0x20) {
        pbVar5 = (byte *)CONCAT11('\x06' - (((0x29 < DAT_EXTMEM_0599 * '\x03') << 7) >> 7),
                                  DAT_EXTMEM_0599 * '\x03' - 0x2a);
        *pbVar5 = DAT_EXTMEM_0829;
        pbVar5[1] = bVar1;
        bVar4 = bVar1;
      }
      if (_0_2 != '\x01') {
        DAT_EXTMEM_0741 = 1;
        DAT_EXTMEM_09cd = 0;
        DAT_EXTMEM_0821 = 0xf;
        DAT_EXTMEM_0822 = 0xa0;
        DAT_EXTMEM_0812 = 0;
        bVar4 = 1;
        DAT_EXTMEM_05da = 1;
      }
      FUN_CODE_2989(bVar4);
      return;
    }
  } while( true );
}



// ==== uncalled_0EF8 @ CODE:0ef8  (57 bytes)

undefined1 uncalled_0EF8(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar3 = param_2;
  uVar4 = param_3;
  FUN_CODE_73fa(param_1,param_2,param_3,0,8);
  cVar1 = '\0';
  cVar2 = '\b';
  DAT_EXTMEM_059a = uVar3;
  DAT_EXTMEM_059b = uVar4;
  FUN_CODE_73fa(uVar4,param_2,param_3);
  if (cVar2 != '\0' || cVar1 != '\0') {
    FUN_CODE_7430(0,0x59a,1);
  }
  return DAT_EXTMEM_059b;
}



// ==== FUN_CODE_0f55 @ CODE:0f55  (1260 bytes)

void FUN_CODE_0f55(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  
  FUN_CODE_2990();
  uVar4 = DAT_EXTMEM_05dd;
  FUN_CODE_22f3();
  DAT_EXTMEM_05c7 =
       *(byte *)(CONCAT11(DAT_EXTMEM_05de - (((0xf1 < DAT_EXTMEM_05df) << 7) >> 7),
                          DAT_EXTMEM_05df + 0xe) + 1) & 0x1f;
  DAT_EXTMEM_05c6 = 0;
  pbVar7 = (byte *)CONCAT11(DAT_EXTMEM_05de - (((0xf1 < DAT_EXTMEM_05df) << 7) >> 7),
                            DAT_EXTMEM_05df + 0xe);
  DAT_EXTMEM_05c3 = pbVar7[1] & 0xe0;
  cVar3 = '\x05';
  bVar5 = *pbVar7 & 1;
  do {
    DAT_EXTMEM_05c3 = DAT_EXTMEM_05c3 >> 1 | bVar5 << 7;
    cVar3 = cVar3 + -1;
    bVar5 = 0;
  } while (cVar3 != '\0');
  DAT_EXTMEM_05c2 = 0;
  bVar5 = *(byte *)CONCAT11(DAT_EXTMEM_05de - (((0xf1 < DAT_EXTMEM_05df) << 7) >> 7),
                            DAT_EXTMEM_05df + 0xe) >> 1;
  DAT_EXTMEM_05c5 = bVar5 + 0xbc;
  DAT_EXTMEM_05c4 = '\a' - (((0x43 < bVar5) << 7) >> 7);
  bVar5 = DAT_EXTMEM_082a ^ DAT_EXTMEM_05df;
  if (bVar5 == 0) {
    bVar5 = DAT_EXTMEM_05de ^ DAT_EXTMEM_0829;
  }
  DAT_EXTMEM_0828 = uVar4;
  if (bVar5 == 0) {
    DAT_EXTMEM_073c = 0;
    DAT_EXTMEM_05e4 = 0;
    DAT_EXTMEM_05f6 = 0;
    DAT_EXTMEM_05e5 = 0;
    DAT_EXTMEM_0a2d = 0;
    DAT_EXTMEM_0741 = 0;
    DAT_EXTMEM_06bb = 0;
    DAT_EXTMEM_09cd = 0;
    DAT_EXTMEM_0821 = 0;
    DAT_EXTMEM_0822 = 0;
    DAT_EXTMEM_073b = 0;
    DAT_EXTMEM_0812 = 0;
    DAT_EXTMEM_0a1c = '\0';
    DAT_EXTMEM_0a1e = '\0';
    DAT_EXTMEM_0809 = '\0';
    DAT_EXTMEM_080d = '\0';
    DAT_EXTMEM_0a32 = 0;
    DAT_EXTMEM_0a1d = -0x3c;
    DAT_EXTMEM_0a1f = '\x1c';
    DAT_EXTMEM_080c = '\x01';
    DAT_EXTMEM_0810 = '\x01';
    DAT_EXTMEM_0a33 = 0;
    DAT_EXTMEM_0744 = 0;
    DAT_EXTMEM_081b = 0;
    DAT_EXTMEM_081c = 0;
    DAT_EXTMEM_0742 = 0;
    DAT_EXTMEM_0743 = 0;
    DAT_EXTMEM_0735 = 0;
    DAT_EXTMEM_05da = 0;
    for (DAT_EXTMEM_059c = 0; DAT_EXTMEM_059c < 5; DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1) {
      *(undefined1 *)
       CONCAT11('\x06' - (((0x2f < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c - 0x30) = 0;
    }
    for (DAT_EXTMEM_059c = 0; DAT_EXTMEM_059c < 5; DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1) {
      *(undefined1 *)CONCAT11('\n' - (((0xd7 < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c + 0x28)
           = 0;
    }
    DAT_EXTMEM_059c = 0;
    do {
      bVar5 = DAT_EXTMEM_059c;
      *(undefined1 *)CONCAT11('\x05' - (((8 < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c - 9) =
           (&DAT_CODE_29f6)[DAT_EXTMEM_059c];
      *(undefined1 *)CONCAT11('\a' - (((0xba < bVar5) << 7) >> 7),bVar5 + 0x45) =
           (&DAT_CODE_29da)[bVar5];
      DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1;
    } while (DAT_EXTMEM_059c != 0x1c);
    DAT_EXTMEM_059c = 0;
    do {
      bVar5 = DAT_EXTMEM_059c;
      *(undefined1 *)CONCAT11('\t' - (((0x2f < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c - 0x30)
           = (&DAT_CODE_2a12)[DAT_EXTMEM_059c];
      *(undefined1 *)CONCAT11('\t' - (((0x13 < bVar5) << 7) >> 7),bVar5 - 0x14) =
           (&DAT_CODE_2a25)[bVar5];
      DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1;
    } while (DAT_EXTMEM_059c != 0x13);
  }
  else {
    bVar5 = DAT_EXTMEM_05df + 0x20;
    cVar3 = DAT_EXTMEM_05de - (((0xdf < DAT_EXTMEM_05df) << 7) >> 7);
    if (DAT_EXTMEM_0811 == '\x02') {
      DAT_EXTMEM_0741 =
           *(undefined1 *)CONCAT11(cVar3 - (((0x79 < bVar5) << 7) >> 7),DAT_EXTMEM_05df + 0xa6);
      DAT_EXTMEM_06bb =
           *(undefined1 *)CONCAT11(cVar3 - (((0x78 < bVar5) << 7) >> 7),DAT_EXTMEM_05df + 0xa7);
      DAT_EXTMEM_09cd =
           *(undefined1 *)CONCAT11(cVar3 - (((0x77 < bVar5) << 7) >> 7),DAT_EXTMEM_05df + 0xa8);
      sVar1 = (ushort)*(byte *)CONCAT11(cVar3 - (((0x76 < bVar5) << 7) >> 7),DAT_EXTMEM_05df + 0xa9)
              * 200;
      DAT_EXTMEM_073b =
           *(undefined1 *)CONCAT11(cVar3 - (((0x75 < bVar5) << 7) >> 7),DAT_EXTMEM_05df + 0xaa);
      DAT_EXTMEM_0812 =
           *(undefined1 *)CONCAT11(cVar3 - (((0x74 < bVar5) << 7) >> 7),DAT_EXTMEM_05df + 0xab);
      DAT_EXTMEM_0a1c =
           *(char *)CONCAT11(cVar3 - (((0x4f < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x30);
      DAT_EXTMEM_0a1e =
           *(char *)CONCAT11(cVar3 - (((0x4e < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x2f);
      DAT_EXTMEM_0809 =
           *(char *)CONCAT11(cVar3 - (((0x4d < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x2e);
      DAT_EXTMEM_080d =
           *(char *)CONCAT11(cVar3 - (((0x4c < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x2d);
      DAT_EXTMEM_0a32 =
           *(undefined1 *)CONCAT11(cVar3 - (((0x49 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x2a);
      DAT_EXTMEM_0a1d =
           *(char *)CONCAT11(cVar3 - (((0x44 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x25);
      DAT_EXTMEM_0a1f =
           *(char *)CONCAT11(cVar3 - (((0x43 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x24);
      DAT_EXTMEM_080c =
           *(char *)CONCAT11(cVar3 - (((0x42 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x23);
      DAT_EXTMEM_0810 =
           *(char *)CONCAT11(cVar3 - (((0x41 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x22);
      DAT_EXTMEM_0a33 =
           *(undefined1 *)CONCAT11(cVar3 - (((0x3e < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x1f);
      DAT_EXTMEM_0744 =
           *(undefined1 *)CONCAT11(cVar3 - (((0x3d < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x1e);
      puVar8 = (undefined1 *)CONCAT11(cVar3 - (((0x3b < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x1c);
      DAT_EXTMEM_081b = *puVar8;
      DAT_EXTMEM_081c = puVar8[1];
      puVar8 = (undefined1 *)CONCAT11(cVar3 - (((0x39 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x1a);
      DAT_EXTMEM_0742 = *puVar8;
      DAT_EXTMEM_0743 = puVar8[1];
      DAT_EXTMEM_0735 =
           *(undefined1 *)CONCAT11(cVar3 - (((0x3c < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x1d);
      DAT_EXTMEM_05da =
           *(undefined1 *)CONCAT11(cVar3 - (((0x37 < bVar5) << 7) >> 7),DAT_EXTMEM_05df - 0x18);
      DAT_EXTMEM_059c = 0;
      DAT_EXTMEM_05e0 = cVar3;
      DAT_EXTMEM_05e1 = bVar5;
      do {
        DAT_EXTMEM_0821 = (undefined1)((ushort)sVar1 >> 8);
        DAT_EXTMEM_0822 = (undefined1)sVar1;
        *(undefined1 *)
         CONCAT11('\x06' - (((0x2f < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c - 0x30) =
             *(undefined1 *)
              CONCAT11((DAT_EXTMEM_05e0 - (((0x36 < DAT_EXTMEM_05e1) << 7) >> 7)) -
                       ((CARRY1(DAT_EXTMEM_05e1 - 0x37,DAT_EXTMEM_059c) << 7) >> 7),
                       (DAT_EXTMEM_05e1 - 0x37) + DAT_EXTMEM_059c);
        sVar1 = CONCAT11(DAT_EXTMEM_0821,DAT_EXTMEM_0822);
        DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1;
      } while (DAT_EXTMEM_059c != 5);
      DAT_EXTMEM_059c = 0;
      do {
        *(undefined1 *)
         CONCAT11('\n' - (((0xd7 < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c + 0x28) =
             *(undefined1 *)
              CONCAT11((DAT_EXTMEM_05e0 - (((0x31 < DAT_EXTMEM_05e1) << 7) >> 7)) -
                       ((CARRY1(DAT_EXTMEM_05e1 - 0x32,DAT_EXTMEM_059c) << 7) >> 7),
                       (DAT_EXTMEM_05e1 - 0x32) + DAT_EXTMEM_059c);
        DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1;
      } while (DAT_EXTMEM_059c != 5);
      DAT_EXTMEM_059c = 0;
      do {
        bVar2 = DAT_EXTMEM_05e1;
        cVar3 = DAT_EXTMEM_05e0;
        bVar5 = DAT_EXTMEM_059c;
        *(undefined1 *)CONCAT11('\x05' - (((8 < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c - 9) =
             *(undefined1 *)
              CONCAT11((DAT_EXTMEM_05e0 - (((0x27 < DAT_EXTMEM_05e1) << 7) >> 7)) -
                       ((CARRY1(DAT_EXTMEM_05e1 - 0x28,DAT_EXTMEM_059c) << 7) >> 7),
                       (DAT_EXTMEM_05e1 - 0x28) + DAT_EXTMEM_059c);
        bVar6 = bVar2 + 0x9c;
        *(undefined1 *)CONCAT11('\a' - (((0xba < bVar5) << 7) >> 7),bVar5 + 0x45) =
             *(undefined1 *)
              CONCAT11((cVar3 + ('\x01' - (((99 < bVar2) << 7) >> 7))) -
                       ((CARRY1(bVar6,bVar5) << 7) >> 7),bVar6 + bVar5);
        DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1;
      } while (DAT_EXTMEM_059c != 0xc4);
      DAT_EXTMEM_059c = 0;
      do {
        bVar2 = DAT_EXTMEM_05e1;
        cVar3 = DAT_EXTMEM_05e0;
        bVar5 = DAT_EXTMEM_059c;
        *(undefined1 *)
         CONCAT11('\t' - (((0x2f < DAT_EXTMEM_059c) << 7) >> 7),DAT_EXTMEM_059c - 0x30) =
             *(undefined1 *)
              CONCAT11((DAT_EXTMEM_05e0 + ('\x02' - (((0x9f < DAT_EXTMEM_05e1) << 7) >> 7))) -
                       ((CARRY1(DAT_EXTMEM_05e1 + 0x60,DAT_EXTMEM_059c) << 7) >> 7),
                       DAT_EXTMEM_05e1 + 0x60 + DAT_EXTMEM_059c);
        bVar6 = bVar2 + 0x7c;
        *(undefined1 *)CONCAT11('\t' - (((0x13 < bVar5) << 7) >> 7),bVar5 - 0x14) =
             *(undefined1 *)
              CONCAT11((cVar3 + ('\x02' - (((0x83 < bVar2) << 7) >> 7))) -
                       ((CARRY1(bVar6,bVar5) << 7) >> 7),bVar6 + bVar5);
        DAT_EXTMEM_059c = DAT_EXTMEM_059c + 1;
      } while (DAT_EXTMEM_059c != 0x1c);
      DAT_EXTMEM_059c = 0x1c;
    }
  }
  DAT_EXTMEM_0a11 = DAT_EXTMEM_0809 * DAT_EXTMEM_0a1c;
  DAT_EXTMEM_0a13 = DAT_EXTMEM_080c * DAT_EXTMEM_0a1d;
  DAT_EXTMEM_0a1b = DAT_EXTMEM_0a13 + DAT_EXTMEM_0a11;
  DAT_EXTMEM_0a22 = DAT_EXTMEM_080d * DAT_EXTMEM_0a1e;
  DAT_EXTMEM_0a23 = DAT_EXTMEM_0810 * DAT_EXTMEM_0a1f;
  DAT_EXTMEM_0827 = DAT_EXTMEM_0a1b >> 3;
  if ((DAT_EXTMEM_0a1b & 7) != 0) {
    DAT_EXTMEM_0827 = DAT_EXTMEM_0827 + 1;
  }
  uVar4 = 0;
  bVar5 = DAT_EXTMEM_0827;
  FUN_CODE_73e6(0,DAT_EXTMEM_0a23);
  DAT_EXTMEM_05e2 = uVar4;
  DAT_EXTMEM_05e3 = bVar5;
  return;
}



// ==== FUN_CODE_1441 @ CODE:1441  (817 bytes)

void FUN_CODE_1441(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  undefined1 uVar7;
  byte *pbVar8;
  char *pcVar9;
  
  FUN_CODE_2997();
  for (DAT_EXTMEM_05c8 = 0; DAT_EXTMEM_05c8 < 0x20; DAT_EXTMEM_05c8 = DAT_EXTMEM_05c8 + 1) {
    FUN_CODE_74de(DAT_EXTMEM_05c8,0x82b,0xd,0,0,0);
    FUN_CODE_74f3();
  }
  cVar2 = '`';
  bVar1 = 3;
  FUN_CODE_74f3(DAT_EXTMEM_05c8 - 0x20,0x5c9,0xff);
  FUN_CODE_74f3(0x82b);
  DAT_EXTMEM_05d1 = '\0';
  DAT_EXTMEM_05d2 = 0x26;
  bVar4 = bVar1 + 0x26;
  cVar2 = cVar2 - (((0xd9 < bVar1) << 7) >> 7);
  FUN_CODE_74f3(0x82e);
  FUN_CODE_74ea(0x82b);
  bVar1 = FUN_CODE_7385(0x11);
  cVar5 = (char)((ushort)bVar1 * 3);
  FUN_CODE_7430((char)((ushort)bVar1 * 3 >> 8),0x5d1);
  FUN_CODE_74ea(0x5c9);
  bVar1 = DAT_EXTMEM_05d2 + bVar4;
  cVar2 = cVar2 + (DAT_EXTMEM_05d1 - ((CARRY1(DAT_EXTMEM_05d2,bVar4) << 7) >> 7));
  FUN_CODE_74f3(0x831);
  FUN_CODE_74ea(0x82b);
  bVar4 = FUN_CODE_7487(0x1e);
  DAT_EXTMEM_05d1 = cVar5;
  DAT_EXTMEM_05d2 = bVar4;
  FUN_CODE_74ea(0x5c9);
  FUN_CODE_74f3(0x834,bVar1 + bVar4,cVar2 + (cVar5 - ((CARRY1(bVar1,bVar4) << 7) >> 7)));
  cVar2 = '\0';
  DAT_EXTMEM_0837 = 0;
  DAT_EXTMEM_05d3 = 0;
  do {
    FUN_CODE_27f6(cVar2);
    cVar2 = *(char *)CONCAT11('\x06' - (((0x2a < DAT_EXTMEM_05d3 * '\x03') << 7) >> 7),
                              DAT_EXTMEM_05d3 * '\x03' - 0x2b);
    FUN_CODE_22f3();
    pbVar8 = (byte *)CONCAT11('\x06' - (((0x29 < DAT_EXTMEM_05d3 * '\x03') << 7) >> 7),
                              DAT_EXTMEM_05d3 * '\x03' - 0x2a);
    bVar1 = *pbVar8;
    bVar4 = pbVar8[1];
    bVar6 = bVar4 ^ DAT_EXTMEM_082a;
    if (bVar6 == 0) {
      bVar6 = bVar1 ^ DAT_EXTMEM_0829;
    }
    DAT_EXTMEM_0828 = cVar2;
    if (bVar6 == 0) break;
    uVar3 = 1;
    FUN_CODE_74f3(bVar6,0x5c9,1);
    uVar7 = FUN_CODE_74f3(0x5cd,bVar4 + 0x20,bVar1 - (((0xdf < bVar4) << 7) >> 7));
    FUN_CODE_74ea(uVar7,0x5cd,0x9d,5,uVar3);
    FUN_CODE_77ea();
    FUN_CODE_74ea(0x5cd);
    DAT_EXTMEM_05d0 = FUN_CODE_7385(0xd);
    DAT_EXTMEM_05cc = DAT_EXTMEM_0828;
    cVar5 = DAT_EXTMEM_05dd;
    FUN_CODE_22f3();
    bVar1 = DAT_EXTMEM_05df;
    cVar2 = DAT_EXTMEM_05de;
    DAT_EXTMEM_0828 = cVar5;
    FUN_CODE_74f3(0x5c9,1);
    DAT_EXTMEM_05d5 = bVar1 + 3;
    DAT_EXTMEM_05d4 =
         (cVar2 - (((0xdf < bVar1) << 7) >> 7)) + ('\x02' - (((0x1c < bVar1 + 0x20) << 7) >> 7));
    cVar2 = '\0';
    DAT_EXTMEM_05c8 = 0;
    do {
      FUN_CODE_27f6(cVar2);
      cVar2 = DAT_EXTMEM_05dd;
      FUN_CODE_22f3();
      bVar1 = (byte)((ushort)DAT_EXTMEM_05c8 * 0x10);
      DAT_EXTMEM_0828 = cVar2;
      FUN_CODE_77ea(0xaa,DAT_EXTMEM_05d5 + bVar1,
                    DAT_EXTMEM_05d4 +
                    ((char)((ushort)DAT_EXTMEM_05c8 * 0x10 >> 8) -
                    ((CARRY1(DAT_EXTMEM_05d5,bVar1) << 7) >> 7)),1,5,1);
      bVar1 = DAT_EXTMEM_05d5;
      cVar2 = DAT_EXTMEM_05d4;
      FUN_CODE_74de(DAT_EXTMEM_05c8,0x10);
      DAT_EXTMEM_05d6 = *(char *)CONCAT11(cVar2 - (((0xf2 < bVar1) << 7) >> 7),bVar1 + 0xd);
      cVar5 = DAT_EXTMEM_05cc;
      FUN_CODE_22f3();
      cVar2 = '\x05';
      bVar1 = 0xaa;
      DAT_EXTMEM_0828 = cVar5;
      FUN_CODE_7701(0x9d,1,5,1);
      if ((cVar5 == '\0') && (DAT_EXTMEM_05d0 == DAT_EXTMEM_05d6)) {
        FUN_CODE_74ea(0x5cd);
        FUN_CODE_74f3(0x5c9);
        FUN_CODE_74de(DAT_EXTMEM_05c8,0x82b,0xd);
        FUN_CODE_74f3();
        DAT_EXTMEM_05d1 = '\0';
        DAT_EXTMEM_05d2 = 0x26;
        bVar4 = bVar1 + 0x26;
        cVar2 = cVar2 - (((0xd9 < bVar1) << 7) >> 7);
        FUN_CODE_74de(DAT_EXTMEM_05c8,0x82e,0xd);
        FUN_CODE_74f3();
        FUN_CODE_74de(DAT_EXTMEM_05c8,0x82b,0xd);
        FUN_CODE_74ea();
        bVar1 = FUN_CODE_7385(0x11);
        FUN_CODE_7430((char)((ushort)bVar1 * 3 >> 8),0x5d1,(char)((ushort)bVar1 * 3));
        FUN_CODE_74ea(0x5c9);
        bVar6 = DAT_EXTMEM_05d2 + bVar4;
        cVar2 = cVar2 + (DAT_EXTMEM_05d1 - ((CARRY1(DAT_EXTMEM_05d2,bVar4) << 7) >> 7));
        FUN_CODE_74de(DAT_EXTMEM_05c8,0x831,0xd);
        FUN_CODE_74f3();
        cVar5 = '\r';
        bVar1 = DAT_EXTMEM_05c8;
        FUN_CODE_74de(0x82b,DAT_EXTMEM_05c8);
        FUN_CODE_74ea();
        bVar4 = FUN_CODE_7487(0x1e);
        DAT_EXTMEM_05d1 = cVar5;
        DAT_EXTMEM_05d2 = bVar4;
        FUN_CODE_74ea(0x5c9);
        FUN_CODE_74de(bVar1,0x834,0xd,bVar6 + bVar4,
                      cVar2 + (cVar5 - ((CARRY1(bVar6,bVar4) << 7) >> 7)));
        FUN_CODE_74f3();
        pcVar9 = &DAT_EXTMEM_0837;
        bVar1 = DAT_EXTMEM_05c8;
        cVar2 = DAT_EXTMEM_05cc;
        FUN_CODE_74de(0xd);
        *pcVar9 = cVar2;
        if (((DAT_EXTMEM_09cd == '\x01') || (DAT_EXTMEM_09cd == '\x02')) &&
           (DAT_EXTMEM_05da == bVar1)) {
          FUN_CODE_74ea(0x5cd);
          DAT_EXTMEM_073a = FUN_CODE_7385(0x12);
        }
        break;
      }
      bVar1 = DAT_EXTMEM_05c8 + 1;
      cVar2 = DAT_EXTMEM_05c8 - 0x1f;
      DAT_EXTMEM_05c8 = bVar1;
    } while (bVar1 < 0x20);
    bVar1 = DAT_EXTMEM_05d3 + 1;
    cVar2 = DAT_EXTMEM_05d3 - 0x1f;
    DAT_EXTMEM_05d3 = bVar1;
  } while (bVar1 < 0x20);
  FUN_CODE_299e();
  return;
}



// ==== FUN_CODE_1772 @ CODE:1772  (73 bytes)

void FUN_CODE_1772(void)

{
  FUN_CODE_74f3(0xf4b,0xbb,0x17,0xff);
  DAT_EXTMEM_0f4e = DAT_EXTMEM_05c6;
  DAT_EXTMEM_0f4f = DAT_EXTMEM_05c7;
  DAT_EXTMEM_0f50 = DAT_EXTMEM_05c2;
  DAT_EXTMEM_0f51 = DAT_EXTMEM_05c3;
  DAT_EXTMEM_0f52 = DAT_EXTMEM_05c4;
  DAT_EXTMEM_0f53 = DAT_EXTMEM_05c5;
  FUN_CODE_7af8(0xb7,5,1);
  return;
}



// ==== FUN_CODE_19a6 @ CODE:19a6  (208 bytes)

void FUN_CODE_19a6(void)

{
  DAT_EXTMEM_0a11 = 0;
  DAT_EXTMEM_0a13 = 0x14;
  DAT_EXTMEM_0a22 = 0;
  DAT_EXTMEM_0a23 = 7;
  DAT_EXTMEM_0827 = 0;
  DAT_EXTMEM_05e2 = 0;
  DAT_EXTMEM_05e3 = 0;
  DAT_EXTMEM_0a1b = 0x14;
  DAT_EXTMEM_0a1c = 0;
  DAT_EXTMEM_0a1e = 0;
  DAT_EXTMEM_0809 = 0;
  DAT_EXTMEM_080d = 0;
  DAT_EXTMEM_0a32 = 0;
  DAT_EXTMEM_0a1d = 0x14;
  DAT_EXTMEM_0a1f = 7;
  DAT_EXTMEM_080c = 1;
  DAT_EXTMEM_0810 = 1;
  DAT_EXTMEM_0a33 = 0;
  DAT_EXTMEM_09cb = 0;
  DAT_EXTMEM_09cc = 0;
  DAT_EXTMEM_0744 = 0;
  DAT_EXTMEM_081b = 0;
  DAT_EXTMEM_081c = 0;
  DAT_EXTMEM_0742 = 0;
  DAT_EXTMEM_0743 = 0;
  _2_3 = 0;
  _2_7 = 1;
  _2_1 = 0;
  _1_5 = 1;
  _2_0 = 0;
  _1_4 = 0;
  _1_6 = 0;
  _0_4 = 0;
  _0_5 = 0;
  _3_3 = 0;
  _2_5 = 0;
  _1_7 = 0;
  _1_3 = 0;
  _1_1 = 0;
  _0_7 = 0;
  _0_6 = 0;
  _3_0 = 1;
  _1_2 = 1;
  _1_0 = 1;
  DAT_EXTMEM_0a30 = 0;
  DAT_EXTMEM_0a31 = 0;
  _3_2 = 0;
  _2_4 = 0;
  _2_6 = 0;
  DAT_EXTMEM_0823 = 0;
  DAT_EXTMEM_0824 = 0x3c;
  DAT_EXTMEM_05db = 0;
  DAT_EXTMEM_05dc = 0;
  DAT_EXTMEM_080a = 0;
  DAT_EXTMEM_080b = 0;
  DAT_EXTMEM_080e = 0;
  DAT_EXTMEM_080f = 0;
  DAT_EXTMEM_0a2e = 0;
  DAT_EXTMEM_0a2f = 0;
  DAT_EXTMEM_0a0d = 0xff;
  DAT_EXTMEM_0a0e = 0xff;
  DAT_EXTMEM_0a0f = 0;
  DAT_EXTMEM_0a10 = 0;
  DAT_EXTMEM_0a26 = 0;
  DAT_EXTMEM_0a27 = 0;
  return;
}



// ==== FUN_CODE_1a76 @ CODE:1a76  (48 bytes)

void FUN_CODE_1a76(void)

{
  DAT_EXTMEM_0a14 = 0;
  DAT_EXTMEM_0a15 = 0;
  DAT_EXTMEM_0a34 = 0;
  DAT_EXTMEM_073e = 4;
  DAT_EXTMEM_073f = 0xb0;
  DAT_EXTMEM_0a0b = 0x6e;
  DAT_EXTMEM_0736 = 8;
  DAT_EXTMEM_0a12 = 2;
  DAT_EXTMEM_05d9 = 2;
  _2_2 = 0;
  return;
}



// ==== FUN_CODE_1aa6 @ CODE:1aa6  (69 bytes)

byte FUN_CODE_1aa6(undefined1 param_1,undefined1 param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  FUN_CODE_74f3(0xa35);
  bVar1 = 0xff;
  DAT_EXTMEM_0a38 = param_1;
  DAT_EXTMEM_0a39 = param_2;
  while( true ) {
    cVar2 = -1;
    bVar3 = FUN_CODE_7446(0xa38);
    cVar2 = ((cVar2 == '\0') << 7) >> 7;
    if ((bVar3 < (byte)-cVar2) << 7 < '\0') break;
    FUN_CODE_74ea(bVar3 + cVar2,0xa35);
    bVar3 = FUN_CODE_736c();
    bVar1 = bVar3 & 0x7f ^ bVar1;
    FUN_CODE_7430(0,0xa36,1,bVar3 & 0x7f,bVar1);
  }
  return bVar1 ^ 0xd;
}



// ==== FUN_CODE_1aeb @ CODE:1aeb  (783 bytes)

char FUN_CODE_1aeb(char param_1,char param_2,char param_3,undefined1 param_4,byte param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  
  DAT_EXTMEM_0a4d = param_5 & 0x7f;
  DAT_EXTMEM_0a4b = param_5;
  DAT_EXTMEM_0a4c = param_4;
  if (DAT_EXTMEM_0a14 != '\x01') {
    if (DAT_EXTMEM_0a14 == '\x02') {
      FUN_CODE_2939();
      DAT_EXTMEM_080e = 0;
      DAT_EXTMEM_080f = 0;
      if (DAT_EXTMEM_0a4d == (DAT_EXTMEM_0a3a & 0x7f)) {
        FUN_CODE_296d();
        DAT_EXTMEM_0823 = 0;
        DAT_EXTMEM_0824 = 0x3c;
        FUN_CODE_74ea(0xa48);
        if (((param_1 != '\0' || param_2 != '\0') || param_3 != '\0') &&
           (bVar3 = DAT_EXTMEM_0a3f - (((DAT_EXTMEM_0a3e < DAT_EXTMEM_0a40) << 7) >> 7),
           DAT_EXTMEM_0a3d < bVar3)) {
          bVar1 = DAT_EXTMEM_0a3d;
          bVar2 = DAT_EXTMEM_0a3e;
          FUN_CODE_74ea(DAT_EXTMEM_0a3d - bVar3,0xa48,DAT_EXTMEM_0a3e);
          FUN_CODE_73c4(0,CONCAT11(bVar1,bVar2));
          FUN_CODE_1fb5();
        }
      }
      else {
        FUN_CODE_2966();
      }
      DAT_EXTMEM_0a14 = 0;
      return '\0';
    }
    if (DAT_EXTMEM_0a14 == '\0') {
      FUN_CODE_2931();
      DAT_EXTMEM_080e = 0;
      DAT_EXTMEM_080f = 0xb;
      DAT_EXTMEM_0a3b = 0;
      DAT_EXTMEM_0a3c = 0;
      cVar4 = DAT_EXTMEM_0a4d + 0x9f;
      if ((0x60 < DAT_EXTMEM_0a4d) &&
         (cVar4 = DAT_EXTMEM_0a4d + 0x85, (DAT_EXTMEM_0a4d < 0x7b) << 7 < '\0')) {
        DAT_EXTMEM_0a3b = DAT_EXTMEM_0a4d;
        DAT_EXTMEM_0a14 = 1;
        DAT_EXTMEM_0a3d = 0;
        DAT_EXTMEM_0a3e = 1;
        FUN_CODE_74f3(0xa48,0,0,0);
        DAT_EXTMEM_0a3a = ~DAT_EXTMEM_0a4b;
        DAT_EXTMEM_0a3f = 0;
        DAT_EXTMEM_0a40 = 0;
        return '\0';
      }
    }
    else {
      cVar4 = '\0';
      DAT_EXTMEM_0a14 = '\0';
    }
    return cVar4;
  }
  bVar3 = DAT_EXTMEM_0a3d;
  if (DAT_EXTMEM_0a3d == 0) {
    bVar3 = DAT_EXTMEM_0a3e ^ 1;
  }
  if (bVar3 != 0) {
    bVar3 = DAT_EXTMEM_0a3d;
    if (DAT_EXTMEM_0a3d == 0) {
      bVar3 = DAT_EXTMEM_0a3e ^ 2;
    }
    if (((bVar3 == 0) && (DAT_EXTMEM_0a3b == 0x61)) && (DAT_EXTMEM_0a3c == 0x56)) {
      bVar3 = DAT_EXTMEM_0a4d ^ DAT_EXTMEM_0a20 + 0x30;
      if (bVar3 == 0) {
        bVar3 = 0xcf < DAT_EXTMEM_0a20;
      }
      if (bVar3 == 0) {
        param_3 = '\x01';
        param_2 = '\n';
        param_1 = 'A';
        FUN_CODE_74f3(0xa48);
        DAT_EXTMEM_0a3f = 0;
        DAT_EXTMEM_0a40 = 7;
        FUN_CODE_73b2(0x61);
        FUN_CODE_74ea(0xa48);
        FUN_CODE_73c4(0x56,1);
      }
    }
    goto LAB_CODE_1d14;
  }
  cVar4 = (DAT_EXTMEM_0a3b < 0x6c) << 7;
  DAT_EXTMEM_0a3f = bVar3;
  DAT_EXTMEM_0a40 = bVar3;
  if ((DAT_EXTMEM_0a3b == 0x6c) && (FUN_CODE_7def(DAT_EXTMEM_0a4d), cVar4 < '\0')) {
    param_3 = '\x01';
    param_2 = '\n';
    param_1 = 'S';
    FUN_CODE_74f3(0xa48);
    DAT_EXTMEM_0a3f = 0;
    DAT_EXTMEM_0a40 = 7;
    FUN_CODE_73b2(0x6c);
  }
  else if ((DAT_EXTMEM_0a3b == 0x6c) && (DAT_EXTMEM_0a4d == 0x45)) {
    param_3 = '\x01';
    param_2 = '\v';
    param_1 = '\t';
    FUN_CODE_74f3(0xa48);
    DAT_EXTMEM_0a3f = 0;
    DAT_EXTMEM_0a40 = 7;
    FUN_CODE_73b2(0x6c);
  }
  else if (DAT_EXTMEM_0a3b == 0x7a) {
    if (((&DAT_CODE_5fbc)[DAT_EXTMEM_0a20] == '\x04') &&
       ((&DAT_CODE_5fc7)[DAT_EXTMEM_0a20] == '\x01')) {
      bVar3 = DAT_EXTMEM_0a4d ^ DAT_EXTMEM_0a20 + 0x40;
      if (bVar3 == 0) {
        bVar3 = 0xbf < DAT_EXTMEM_0a20;
      }
      if (bVar3 == 0) {
        param_3 = '\x01';
        param_2 = '\n';
        param_1 = 'Z';
        FUN_CODE_74f3(0xa48);
        DAT_EXTMEM_0a3f = 0;
        DAT_EXTMEM_0a40 = 0xaf;
        FUN_CODE_73b2(0x7a);
        goto LAB_CODE_1cb4;
      }
    }
    if ((((&DAT_CODE_5fbc)[DAT_EXTMEM_0a20] == '\x03') &&
        ((&DAT_CODE_5fc7)[DAT_EXTMEM_0a20] == '\x03')) && (DAT_EXTMEM_0a4d == 0x41)) {
      param_3 = '\x01';
      param_2 = '\n';
      param_1 = 'Z';
      FUN_CODE_74f3(0xa48);
      DAT_EXTMEM_0a3f = 0;
      DAT_EXTMEM_0a40 = 0xaf;
      FUN_CODE_73b2(0x7a);
    }
    else {
      param_3 = '\0';
      param_2 = '\0';
      param_1 = '\0';
      FUN_CODE_74f3(0xa48);
    }
  }
  else {
    if (DAT_EXTMEM_0a3b == 0x61) {
      bVar3 = DAT_EXTMEM_0a4d ^ DAT_EXTMEM_0a20 + 0x30;
      if (bVar3 == 0) {
        bVar3 = 0xcf < DAT_EXTMEM_0a20;
      }
      if (bVar3 == 0) {
        param_3 = '\x01';
        param_2 = '\n';
        param_1 = 'A';
        FUN_CODE_74f3(0xa48);
        DAT_EXTMEM_0a3f = 0;
        DAT_EXTMEM_0a40 = 7;
        FUN_CODE_73b2(0x61);
        goto LAB_CODE_1cb4;
      }
    }
    param_3 = '\0';
    param_2 = '\0';
    param_1 = '\0';
    FUN_CODE_74f3(0xa48);
  }
LAB_CODE_1cb4:
  DAT_EXTMEM_0a3c = DAT_EXTMEM_0a4d;
LAB_CODE_1d14:
  if (DAT_EXTMEM_0a4d == 0xd) {
    DAT_EXTMEM_0a3a = DAT_EXTMEM_0a3a ^ DAT_EXTMEM_0a4b;
    DAT_EXTMEM_0a14 = 2;
    DAT_EXTMEM_080e = 0;
    DAT_EXTMEM_080f = 0xb;
    return '\v';
  }
  bVar3 = DAT_EXTMEM_0a3f - (((DAT_EXTMEM_0a3e < DAT_EXTMEM_0a40) << 7) >> 7);
  if ((DAT_EXTMEM_0a3d < bVar3) &&
     (bVar1 = DAT_EXTMEM_0a3d, bVar2 = DAT_EXTMEM_0a3e,
     FUN_CODE_74ea(DAT_EXTMEM_0a3d - bVar3,0xa48,DAT_EXTMEM_0a3e),
     (param_1 != '\0' || param_2 != '\0') || param_3 != '\0')) {
    bVar3 = DAT_EXTMEM_0a4d;
    FUN_CODE_74ea(0xa48,DAT_EXTMEM_0a4d);
    FUN_CODE_73c4(bVar3,CONCAT11(bVar1,bVar2));
  }
  DAT_EXTMEM_0a3a = DAT_EXTMEM_0a3a ^ DAT_EXTMEM_0a4b;
  DAT_EXTMEM_080e = 0;
  DAT_EXTMEM_080f = 0xb;
  cVar4 = FUN_CODE_7430(0,0xa3d,1);
  return cVar4;
}



// ==== FUN_CODE_1dfa @ CODE:1dfa  (34 bytes)

void FUN_CODE_1dfa(void)

{
  if (DAT_EXTMEM_0a15 == '\0') {
    FUN_CODE_74f3(0xa16);
    DAT_EXTMEM_0a15 = 1;
    DAT_EXTMEM_0737 = 0;
    DAT_EXTMEM_0738 = 0;
    FUN_CODE_2c76();
    return;
  }
  return;
}



// ==== FUN_CODE_1e1c @ CODE:1e1c  (341 bytes)

byte FUN_CODE_1e1c(undefined1 param_1,byte param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  
  DAT_EXTMEM_0a4e = 1;
  DAT_EXTMEM_0a4f = 0;
  if (DAT_EXTMEM_0a15 == '\x01') {
    cVar1 = ((DAT_EXTMEM_0738 < 0x32) << 7) >> 7;
    if ((DAT_EXTMEM_0737 < (byte)-cVar1) << 7 < '\0') {
      bVar2 = DAT_EXTMEM_0737;
      bVar3 = DAT_EXTMEM_0738;
      FUN_CODE_74ea(DAT_EXTMEM_0737 + cVar1,0xa16,DAT_EXTMEM_0738);
      DAT_EXTMEM_0a4f = FUN_CODE_7385(CONCAT11(bVar2,bVar3));
      if (DAT_EXTMEM_0a4f == 0) {
        DAT_EXTMEM_0a4f = 0xd;
        DAT_EXTMEM_0a15 = '\x02';
        DAT_EXTMEM_0a4e = 0;
      }
      else {
        DAT_EXTMEM_0a4e = 0;
        FUN_CODE_7430(0,0x737,1);
      }
    }
    else {
      DAT_EXTMEM_0a15 = '\0';
    }
  }
  else if (DAT_EXTMEM_0a15 == '\x02') {
    FUN_CODE_74ea(0xa16);
    uVar4 = FUN_CODE_7e29();
    FUN_CODE_74ea(uVar4,0xa16,param_1,param_2);
    FUN_CODE_1aa6();
    DAT_EXTMEM_0a4e = 0;
    DAT_EXTMEM_0a15 = '\0';
    DAT_EXTMEM_0a4f = param_2;
  }
  else if (DAT_EXTMEM_0a15 == '\x03') {
    FUN_CODE_296d();
    FUN_CODE_74ea(0xa16);
    DAT_EXTMEM_0a4f = FUN_CODE_7385(CONCAT11(DAT_EXTMEM_0737,DAT_EXTMEM_0738));
    DAT_EXTMEM_0a4e = 0;
    FUN_CODE_7430(0,0x737,1);
    if ((byte)-(((DAT_EXTMEM_0738 < DAT_EXTMEM_0a21) << 7) >> 7) <= DAT_EXTMEM_0737) {
      DAT_EXTMEM_0a15 = '\0';
      FUN_CODE_2974();
    }
  }
  else if (DAT_EXTMEM_0a15 == '\0') {
    DAT_EXTMEM_0a4e = 1;
    DAT_EXTMEM_0a4f = 0;
    FUN_CODE_2c79();
    if (_2_2 == '\x01') {
      DAT_EXTMEM_0b2f = DAT_EXTMEM_0a12;
      DAT_EXTMEM_0b30 = DAT_EXTMEM_0a0b;
      FUN_CODE_2af7(DAT_EXTMEM_0736,DAT_EXTMEM_073e,DAT_EXTMEM_073f,DAT_EXTMEM_05d9);
      _2_2 = '\0';
    }
  }
  else {
    DAT_EXTMEM_0a4e = 1;
    DAT_EXTMEM_0a4f = 0;
    DAT_EXTMEM_0a15 = '\0';
  }
  bVar2 = DAT_EXTMEM_0a4f;
  FUN_CODE_1f71(7,0);
  if (bVar2 == 0) {
    DAT_EXTMEM_0a4f = DAT_EXTMEM_0a4f & 0x7f;
  }
  else {
    DAT_EXTMEM_0a4f = DAT_EXTMEM_0a4f | 0x80;
  }
  return DAT_EXTMEM_0a4f;
}



// ==== FUN_CODE_1f71 @ CODE:1f71  (48 bytes)

byte FUN_CODE_1f71(byte param_1,byte param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = 0;
  for (bVar1 = 0; bVar1 < param_1; bVar1 = bVar1 + 1) {
    if ((param_3 & 1) != 0) {
      bVar2 = bVar2 + 1;
    }
    param_3 = param_3 >> 1;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (param_2 == 1) {
    return bVar2 & 1;
  }
  return param_2;
}



// ==== FUN_CODE_1fa1 @ CODE:1fa1  (20 bytes)

void FUN_CODE_1fa1(void)

{
  DAT_EXTMEM_0a53 = 0;
  _3_5 = 0;
  DAT_EXTMEM_0b09 = 0;
  _3_4 = 0;
  DAT_EXTMEM_0a5a = 0;
  _3_6 = 0;
  return;
}



// ==== FUN_CODE_1fb5 @ CODE:1fb5  (322 bytes)

void FUN_CODE_1fb5(void)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  char in_PSW;
  
  FUN_CODE_74f3(0xa50);
  FUN_CODE_74ea(0xa50);
  cVar1 = FUN_CODE_736c();
  if (cVar1 == 'l') {
    uVar2 = FUN_CODE_7385(1);
    FUN_CODE_7def(uVar2);
    if ((in_PSW < '\0') &&
       ((cVar1 = *(char *)CONCAT11(DAT_EXTMEM_05e0 - (((0x77 < DAT_EXTMEM_05e1) << 7) >> 7),
                                   DAT_EXTMEM_05e1 + 0x88), cVar1 == '\x01' || (cVar1 == '\x02'))))
    {
      _3_5 = 1;
      return;
    }
  }
  FUN_CODE_74ea(0xa50);
  cVar1 = FUN_CODE_736c();
  if (cVar1 == 'l') {
    cVar1 = FUN_CODE_7385(1);
    if (cVar1 == 'E') {
      cVar1 = '\0';
      bVar4 = *(byte *)CONCAT11(DAT_EXTMEM_05e0 - (((0x77 < DAT_EXTMEM_05e1) << 7) >> 7),
                                DAT_EXTMEM_05e1 + 0x88);
      if ((bVar4 == 1) || (cVar1 = (bVar4 < 2) << 7, bVar4 == 2)) {
        uVar2 = FUN_CODE_7385(2);
        FUN_CODE_7def(uVar2);
        if (cVar1 < '\0') {
          _3_4 = 1;
          return;
        }
      }
    }
  }
  FUN_CODE_74ea(0xa50);
  cVar1 = FUN_CODE_736c();
  if (cVar1 == 'z') {
    if (((&DAT_CODE_5fbc)[DAT_EXTMEM_0a20] == '\x04') &&
       ((&DAT_CODE_5fc7)[DAT_EXTMEM_0a20] == '\x01')) {
      bVar4 = DAT_EXTMEM_0a20;
      bVar3 = FUN_CODE_7385(1);
      bVar3 = bVar3 ^ bVar4 + 0x40;
      if (bVar3 == 0) {
        bVar3 = 0xbf < bVar4;
      }
      if (bVar3 == 0) {
        _3_6 = 1;
        return;
      }
    }
    if (((&DAT_CODE_5fbc)[DAT_EXTMEM_0a20] == '\x03') &&
       ((&DAT_CODE_5fc7)[DAT_EXTMEM_0a20] == '\x03')) {
      FUN_CODE_74ea(0xa50);
      cVar1 = FUN_CODE_7385(1);
      if (cVar1 == 'A') {
        _3_6 = 1;
        return;
      }
    }
    _3_6 = 0;
    return;
  }
  FUN_CODE_74ea(0xa50);
  cVar1 = FUN_CODE_736c();
  if (cVar1 == 'a') {
    bVar4 = FUN_CODE_7385(1);
    bVar4 = bVar4 ^ DAT_EXTMEM_0a20 + 0x30;
    if (bVar4 == 0) {
      bVar4 = 0xcf < DAT_EXTMEM_0a20;
    }
    if (bVar4 == 0) {
      FUN_CODE_1dfa(0xf7,0x20,0xff);
      return;
    }
  }
  FUN_CODE_74ea(0xa50);
  cVar1 = FUN_CODE_736c();
  if (cVar1 == 'a') {
    cVar1 = FUN_CODE_7385(1);
    if (cVar1 == 'V') {
      bVar4 = FUN_CODE_7385(2);
      bVar4 = bVar4 ^ DAT_EXTMEM_0a20 + 0x30;
      if (bVar4 == 0) {
        bVar4 = 0xcf < DAT_EXTMEM_0a20;
      }
      if (bVar4 == 0) {
        FUN_CODE_1dfa(0xfa,0x20,0xff);
      }
    }
  }
  return;
}



// ==== FUN_CODE_2104 @ CODE:2104  (495 bytes)

void FUN_CODE_2104(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  char cVar6;
  char in_PSW;
  byte *pbVar7;
  
  FUN_CODE_2808();
  LATCH0_EZ_row_color_LED_bank = 0;
  LATCH1_ES_FP2800 = 0;
  LATCH2_module_enable = 0x80;
  LATCH3_7SEG_802_15 = 0xff;
  FUN_CODE_2921();
  FUN_CODE_2931();
  FUN_CODE_2949();
  FUN_CODE_2959();
  DAT_EXTMEM_081f = 0;
  FUN_CODE_2951();
  FUN_CODE_295f();
  FUN_CODE_27f3();
  DAT_EXTMEM_0b26 = 0;
  IP = 0x10;
  TMOD = 0x21;
  TCON = 0x50;
  FUN_CODE_2897();
  IE = 2;
  FUN_CODE_296d();
  FUN_CODE_27f3();
  _3_7 = '\0';
  bVar5 = FUN_CODE_27eb();
  if (-1 < in_PSW) {
    DAT_INTMEM_27 = 0;
    DAT_INTMEM_28 = '\x04';
    while (bVar5 = DAT_INTMEM_27 - 0xf, DAT_INTMEM_27 < 0xf) {
      FUN_CODE_27f3(bVar5);
      DAT_INTMEM_2b = DAT_INTMEM_27;
      DAT_INTMEM_2c = DAT_INTMEM_28;
      DAT_INTMEM_2d = *(undefined1 *)CONCAT11(DAT_INTMEM_27,DAT_INTMEM_28);
      *(undefined1 *)CONCAT11(DAT_INTMEM_27,DAT_INTMEM_28) = 0x55;
      bVar5 = *(byte *)CONCAT11(DAT_INTMEM_27,DAT_INTMEM_28) ^ 0x55;
      if (bVar5 != 0) {
        _3_7 = '\x01';
        break;
      }
      *(undefined1 *)CONCAT11(DAT_INTMEM_27,DAT_INTMEM_28) = 0xaa;
      bVar5 = *(byte *)CONCAT11(DAT_INTMEM_27,DAT_INTMEM_28) ^ 0xaa;
      if (bVar5 != 0) {
        _3_7 = '\x01';
        break;
      }
      *(undefined1 *)CONCAT11(DAT_INTMEM_27,DAT_INTMEM_28) = DAT_INTMEM_2d;
      DAT_INTMEM_28 = DAT_INTMEM_28 + '\x01';
      if (DAT_INTMEM_28 == '\0') {
        DAT_INTMEM_27 = DAT_INTMEM_27 + 1;
      }
    }
  }
  if (_3_7 != '\0') {
    FUN_CODE_27f3(bVar5);
    cVar6 = FUN_CODE_2808();
    do {
      FUN_CODE_2929(cVar6);
      DAT_INTMEM_29 = 0;
      DAT_INTMEM_2a = 0;
      while (bVar5 = 0x13 - (((DAT_INTMEM_2a < 0x88) << 7) >> 7), DAT_INTMEM_29 < bVar5) {
        DAT_INTMEM_2a = DAT_INTMEM_2a + 1;
        if (DAT_INTMEM_2a == 0) {
          DAT_INTMEM_29 = DAT_INTMEM_29 + 1;
        }
      }
      FUN_CODE_2921(DAT_INTMEM_29 - bVar5);
      DAT_INTMEM_29 = 0;
      DAT_INTMEM_2a = 0;
      while (bVar5 = 0x13 - (((DAT_INTMEM_2a < 0x88) << 7) >> 7), cVar6 = DAT_INTMEM_29 - bVar5,
            DAT_INTMEM_29 < bVar5) {
        DAT_INTMEM_2a = DAT_INTMEM_2a + 1;
        if (DAT_INTMEM_2a == 0) {
          DAT_INTMEM_29 = DAT_INTMEM_29 + 1;
        }
      }
    } while( true );
  }
  FUN_CODE_2929();
  FUN_CODE_2931();
  FUN_CODE_27f3();
  FUN_CODE_2805();
  DAT_EXTMEM_0825 = '\x10';
  DAT_EXTMEM_0826 = 0;
  DAT_EXTMEM_0829 = 0xff;
  DAT_EXTMEM_082a = 0xff;
  DAT_EXTMEM_073d = 0;
  uVar3 = 0;
  FUN_CODE_22f3();
  DAT_EXTMEM_0828 = uVar3;
  FUN_CODE_2343();
  DAT_EXTMEM_073d = uVar3;
  FUN_CODE_2974();
  bVar5 = DAT_EXTMEM_09cf ^ ~DAT_EXTMEM_081e;
  if (bVar5 == 0) {
    bVar5 = ~DAT_EXTMEM_081d ^ DAT_EXTMEM_09ce;
  }
  if (bVar5 != 0) {
    DAT_EXTMEM_09ce = 0;
    DAT_EXTMEM_09cf = 0;
    DAT_EXTMEM_0a0c = 0xff;
  }
  FUN_CODE_297b();
  DAT_EXTMEM_0b10 = DAT_EXTMEM_0a08;
  cVar6 = '\b';
  cVar4 = '\x13';
  for (bVar5 = 0; bVar5 < 8; bVar5 = bVar5 + 1) {
    DAT_EXTMEM_0b10 = DAT_EXTMEM_0b10 ^ *(byte *)CONCAT11(cVar6,cVar4);
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\0') {
      cVar6 = cVar6 + '\x01';
    }
  }
  bVar5 = DAT_EXTMEM_0b10;
  if (DAT_EXTMEM_0b10 == 0) {
    for (bVar1 = 0; bVar5 = bVar1 - 4, bVar1 < 4; bVar1 = bVar1 + 1) {
      bVar2 = 0;
      cVar6 = bVar1 + 1;
      bVar5 = 1;
      while (cVar6 = cVar6 + -1, cVar6 != '\0') {
        bVar2 = bVar2 << 1 | bVar5 >> 7;
        bVar5 = bVar5 << 1;
      }
      if (((DAT_EXTMEM_09cf & bVar5) == 1 && (DAT_EXTMEM_09ce & bVar2) == 0) &&
         (pbVar7 = (byte *)CONCAT11('\b' - (((0xec < bVar1 * '\x02') << 7) >> 7),
                                    bVar1 * '\x02' + 0x13),
         *pbVar7 < (byte)(DAT_EXTMEM_0825 - (((pbVar7[1] < DAT_EXTMEM_0826) << 7) >> 7)))) {
        DAT_EXTMEM_0b10 = 0xff;
      }
    }
  }
  FUN_CODE_2939(bVar5);
  FUN_CODE_27f3();
  T0 = 1;
  return;
}



// ==== FUN_CODE_22f3 @ CODE:22f3  (80 bytes)

char FUN_CODE_22f3(char param_1)

{
  byte bVar1;
  
  DAT_EXTMEM_0b11 = param_1;
  FUN_CODE_2808();
  if (DAT_EXTMEM_0b11 == '\x01') {
    FUN_CODE_2951();
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 & 0xdf;
  }
  else if (DAT_EXTMEM_0b11 == '\x02') {
    FUN_CODE_2949();
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 | 0x20;
  }
  else if (DAT_EXTMEM_0b11 == '\x03') {
    FUN_CODE_2951();
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 | 0x20;
  }
  else if (DAT_EXTMEM_0b11 == '\0') {
    FUN_CODE_2949();
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 & 0xdf;
  }
  FUN_CODE_2805();
  return DAT_EXTMEM_0b11;
}



// ==== FUN_CODE_2343 @ CODE:2343  (358 bytes)

void FUN_CODE_2343(void)

{
  char cVar1;
  
  DAT_INTMEM_31 = 0;
  DAT_INTMEM_32 = '\x10';
  FUN_CODE_7343(0x33,0x38,0x2a,0xff,0,0,0,4);
  DAT_INTMEM_2e = '\x10';
  DAT_INTMEM_2f = 0;
  FUN_CODE_27f3();
  DAT_INTMEM_30 = *(undefined1 *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f);
  *(undefined1 *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f) = 0x55;
  if (*(char *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f) == 'U') {
    if (*(char *)CONCAT11(DAT_INTMEM_2e + -0x80,DAT_INTMEM_2f) ==
        *(char *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f)) {
      *(byte *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f) =
           ~*(byte *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f);
      if (*(char *)CONCAT11(DAT_INTMEM_2e + -0x80,DAT_INTMEM_2f) ==
          *(char *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f)) {
        DAT_EXTMEM_0825 = 0x80;
      }
      else {
        DAT_EXTMEM_0825 = 0x10;
      }
      DAT_EXTMEM_0826 = 0;
      *(byte *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f) =
           ~*(byte *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f);
    }
    else {
      DAT_EXTMEM_0825 = 0x10;
      DAT_EXTMEM_0826 = 0;
    }
    *(undefined1 *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f) = DAT_INTMEM_30;
    return;
  }
  DAT_EXTMEM_0b12 = 0x10;
  DAT_EXTMEM_0b13 = 0;
  cVar1 = DAT_INTMEM_32;
  FUN_CODE_798d(0,0,0x90,1,0x10,1,DAT_INTMEM_31);
  if (cVar1 == '\0') {
    cVar1 = '\x04';
    FUN_CODE_798d(0,0x33,0,0,0x80,1,0);
    if (cVar1 == '\0') {
      DAT_EXTMEM_0825 = 0x80;
      goto LAB_CODE_240a;
    }
  }
  cVar1 = DAT_INTMEM_32;
  FUN_CODE_798d(DAT_EXTMEM_0b13,0,0x90,1,DAT_EXTMEM_0b12,1,DAT_INTMEM_31);
  if (cVar1 != '\0') {
    cVar1 = '\x04';
    FUN_CODE_798d(0,0x33,0,0,0x10,1,0);
    if (cVar1 == '\0') {
      DAT_EXTMEM_0825 = 0x10;
      goto LAB_CODE_240a;
    }
  }
  DAT_EXTMEM_0825 = 0x10;
LAB_CODE_240a:
  DAT_EXTMEM_0826 = 0;
  *(undefined1 *)CONCAT11(DAT_INTMEM_2e,DAT_INTMEM_2f) = DAT_INTMEM_30;
  return;
}



// ==== FUN_CODE_24a9 @ CODE:24a9  (824 bytes)

void FUN_CODE_24a9(undefined1 param_1,undefined1 param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  DAT_EXTMEM_0b14 = param_1;
  DAT_EXTMEM_0b15 = param_2;
  FUN_CODE_7343(0x1a,0x3c,0x2a,0xff,0xb,1,0,8);
  for (DAT_EXTMEM_0b16 = 0; DAT_EXTMEM_0b16 < DAT_EXTMEM_0a1b; DAT_EXTMEM_0b16 = DAT_EXTMEM_0b16 + 1
      ) {
    FUN_CODE_27f6(DAT_EXTMEM_0b16 - DAT_EXTMEM_0a1b);
    if ((((DAT_EXTMEM_0b16 < DAT_EXTMEM_0a11) << 7) >> 7 ^ 0x80U) < 0x80) {
      DAT_EXTMEM_0b22 = DAT_EXTMEM_0a22;
    }
    else {
      DAT_EXTMEM_0b22 = DAT_EXTMEM_0a23;
    }
    for (DAT_EXTMEM_0b17 = 0; (DAT_EXTMEM_0b17 < DAT_EXTMEM_0b22) << 7 < '\0';
        DAT_EXTMEM_0b17 = DAT_EXTMEM_0b17 + 1) {
      bVar2 = (byte)((ushort)DAT_EXTMEM_0b17 * (ushort)DAT_EXTMEM_0827);
      DAT_EXTMEM_0b19 = (DAT_EXTMEM_0b16 >> 3) + bVar2;
      DAT_EXTMEM_0b18 =
           (char)((ushort)DAT_EXTMEM_0b17 * (ushort)DAT_EXTMEM_0827 >> 8) -
           ((CARRY1(DAT_EXTMEM_0b16 >> 3,bVar2) << 7) >> 7);
      bVar2 = *(byte *)CONCAT11('\v' - (((0xe5 < (DAT_EXTMEM_0b16 & 7)) << 7) >> 7),
                                (DAT_EXTMEM_0b16 & 7) + 0x1a);
      bVar3 = *(byte *)CONCAT11(DAT_EXTMEM_0b18 +
                                (DAT_EXTMEM_058c -
                                ((CARRY1(DAT_EXTMEM_058d,DAT_EXTMEM_0b19) << 7) >> 7)),
                                DAT_EXTMEM_058d + DAT_EXTMEM_0b19) & bVar2;
      if ((_4_1 == '\0') ||
         ((_4_1 == '\x01' &&
          ((*(byte *)CONCAT11(DAT_EXTMEM_0b18 +
                              (DAT_EXTMEM_058e -
                              ((CARRY1(DAT_EXTMEM_058f,DAT_EXTMEM_0b19) << 7) >> 7)),
                              DAT_EXTMEM_058f + DAT_EXTMEM_0b19) & bVar2) != bVar3)))) {
        _4_0 = bVar3 != 0;
        if (DAT_EXTMEM_0b16 < DAT_EXTMEM_0a11) {
          if (DAT_EXTMEM_0a32 != '\0') {
            _4_0 = !(bool)_4_0;
          }
        }
        else if (DAT_EXTMEM_0a33 != '\0') {
          _4_0 = !(bool)_4_0;
        }
        if (DAT_EXTMEM_0744 != '\0') {
          _4_0 = _4_0 ^ 1;
        }
        DAT_EXTMEM_0b24 = 1;
        DAT_EXTMEM_09cb = '\0';
        DAT_EXTMEM_09cc = 0;
        DAT_EXTMEM_05e4 = 0;
        for (DAT_EXTMEM_0b23 = 0; (DAT_EXTMEM_0b23 < DAT_EXTMEM_0b24) << 7 < '\0';
            DAT_EXTMEM_0b23 = DAT_EXTMEM_0b23 + 1) {
          if (*(char *)CONCAT11('\a' - (((0xba < DAT_EXTMEM_0b16) << 7) >> 7),DAT_EXTMEM_0b16 + 0x45
                               ) == '\x02') {
            bVar2 = LATCH0_EZ_row_color_LED_bank;
            LATCH0_EZ_row_color_LED_bank = bVar2 & 0xe1;
            if (_4_0 == '\0') {
              FUN_CODE_2911();
              FUN_CODE_2939();
            }
            else {
              FUN_CODE_2909();
              FUN_CODE_2931();
            }
            LATCH1_ES_FP2800 =
                 *(char *)CONCAT11('\x05' - (((8 < DAT_EXTMEM_0b16) << 7) >> 7),DAT_EXTMEM_0b16 - 9)
                 + DAT_EXTMEM_09cc;
            if (DAT_EXTMEM_0b16 < DAT_EXTMEM_0a11) {
              bVar2 = LATCH2_module_enable;
              bVar2 = *(byte *)CONCAT11('\t' - (((0x2f < DAT_EXTMEM_0b17) << 7) >> 7),
                                        DAT_EXTMEM_0b17 - 0x30) | bVar2 & 0xe0;
              LATCH2_module_enable = bVar2;
            }
            else {
              bVar2 = (DAT_EXTMEM_0b16 - DAT_EXTMEM_0a11) - DAT_EXTMEM_0a13;
              if ((DAT_EXTMEM_0b16 - DAT_EXTMEM_0a11 < DAT_EXTMEM_0a13) << 7 < '\0') {
                bVar2 = LATCH2_module_enable;
                bVar2 = *(byte *)CONCAT11('\t' - (((0x13 < DAT_EXTMEM_0b17) << 7) >> 7),
                                          DAT_EXTMEM_0b17 - 0x14) | bVar2 & 0xe0;
                LATCH2_module_enable = bVar2;
              }
            }
          }
          else {
            bVar2 = *(byte *)CONCAT11('\a' - (((0xba < DAT_EXTMEM_0b16) << 7) >> 7),
                                      DAT_EXTMEM_0b16 + 0x45) ^ 1;
            if (bVar2 == 0) {
              DAT_EXTMEM_0b25 =
                   *(char *)CONCAT11('\x05' - (((8 < DAT_EXTMEM_0b16) << 7) >> 7),
                                     DAT_EXTMEM_0b16 - 9) + DAT_EXTMEM_09cc;
              if (_4_0 == '\0') {
                if (DAT_EXTMEM_0b16 < DAT_EXTMEM_0a11) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x2f < DAT_EXTMEM_0b17) << 7) >> 7),
                                         DAT_EXTMEM_0b17 - 0x30) | bVar2 & 0xe0 | 0x10;
                }
                else if (DAT_EXTMEM_0b16 - DAT_EXTMEM_0a11 < DAT_EXTMEM_0a13) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x13 < DAT_EXTMEM_0b17) << 7) >> 7),
                                         DAT_EXTMEM_0b17 - 0x14) | bVar2 & 0xe0 | 0x10;
                }
                LATCH1_ES_FP2800 = DAT_EXTMEM_0b25 | 0x80;
              }
              else {
                FUN_CODE_2931();
                if (DAT_EXTMEM_0b16 < DAT_EXTMEM_0a11) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x2f < DAT_EXTMEM_0b17) << 7) >> 7),
                                         DAT_EXTMEM_0b17 - 0x30) & 0xef | bVar2 & 0xe0;
                }
                else if (DAT_EXTMEM_0b16 - DAT_EXTMEM_0a11 < DAT_EXTMEM_0a13) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x13 < DAT_EXTMEM_0b17) << 7) >> 7),
                                         DAT_EXTMEM_0b17 - 0x14) & 0xef | bVar2 & 0xe0;
                }
                LATCH1_ES_FP2800 = DAT_EXTMEM_0b25 & 0x7f;
              }
              if ((char)DAT_EXTMEM_0b25 < '\0') {
                bVar2 = LATCH2_module_enable;
                bVar2 = bVar2 & 0xe0 | 1;
                LATCH2_module_enable = bVar2;
              }
              else {
                bVar2 = LATCH2_module_enable;
                bVar2 = bVar2 & 0xe0;
                LATCH2_module_enable = bVar2;
              }
            }
          }
          FUN_CODE_28dc(bVar2);
          T0 = 0;
          FUN_CODE_28eb();
          FUN_CODE_2939();
          T0 = 1;
          FUN_CODE_28fa();
          bVar1 = CARRY1(DAT_EXTMEM_09cc,DAT_EXTMEM_05e4);
          DAT_EXTMEM_09cc = DAT_EXTMEM_09cc + DAT_EXTMEM_05e4;
          DAT_EXTMEM_09cb = DAT_EXTMEM_09cb - ((bVar1 << 7) >> 7);
        }
      }
    }
  }
  FUN_CODE_7343(DAT_EXTMEM_058f,DAT_EXTMEM_058d,DAT_EXTMEM_058c,1,DAT_EXTMEM_058e,1,DAT_EXTMEM_05e2,
                DAT_EXTMEM_05e3);
  return;
}



// ==== FUN_CODE_27e1 @ CODE:27e1  (10 bytes)

undefined1 FUN_CODE_27e1(void)

{
  byte bVar1;
  
  bVar1 = P1;
  return (&DAT_CODE_29ba)[bVar1 & 0xf];
}



// ==== FUN_CODE_27eb @ CODE:27eb  (4 bytes)

void FUN_CODE_27eb(void)

{
  undefined1 uVar1;
  
  uVar1 = INT1;
  return;
}



// ==== FUN_CODE_27f3 @ CODE:27f3  (3 bytes)

void FUN_CODE_27f3(void)

{
  byte bVar1;
  
  bVar1 = T1;
  T1 = bVar1 ^ 1;
  return;
}



// ==== FUN_CODE_27f6 @ CODE:27f6  (11 bytes)

void FUN_CODE_27f6(void)

{
  DAT_EXTMEM_0a24 = 3;
  DAT_EXTMEM_0a25 = 0xe8;
  return;
}



// ==== FUN_CODE_2801 @ CODE:2801  (3 bytes)

void FUN_CODE_2801(void)

{
  return;
}



// ==== FUN_CODE_2804 @ CODE:2804  (1 bytes)

void FUN_CODE_2804(void)

{
  return;
}



// ==== FUN_CODE_2805 @ CODE:2805  (3 bytes)

void FUN_CODE_2805(void)

{
  EA = 1;
  return;
}



// ==== FUN_CODE_2808 @ CODE:2808  (3 bytes)

void FUN_CODE_2808(void)

{
  EA = 0;
  return;
}



// ==== isr_timer0 @ CODE:280b  (77 bytes)

undefined1 isr_timer0(undefined1 param_1)

{
  bool bVar1;
  
  if (_0_3 == '\0') {
    TL0 = 0x78;
    TH0 = 0xec;
  }
  else {
    TL0 = 0x9e;
    TH0 = 0xd5;
  }
  if (DAT_EXTMEM_081f != '\0') {
    FUN_CODE_0026();
  }
  if ((byte)-(((DAT_EXTMEM_0a25 == '\0') << 7) >> 7) <= DAT_EXTMEM_0a24) {
    bVar1 = DAT_EXTMEM_0a25 != '\0';
    DAT_EXTMEM_0a25 = DAT_EXTMEM_0a25 + -1;
    DAT_EXTMEM_0a24 = DAT_EXTMEM_0a24 + (-1 - ((bVar1 << 7) >> 7));
    FUN_CODE_27f3();
  }
  DAT_EXTMEM_0b26 = DAT_EXTMEM_0b26 + 1;
  if (100 < DAT_EXTMEM_0b26) {
    DAT_EXTMEM_0b26 = 0;
    if (DAT_EXTMEM_0824 != '\0' || DAT_EXTMEM_0823 != '\0') {
      if (DAT_EXTMEM_0824 == '\x01' && DAT_EXTMEM_0823 == '\0') {
        FUN_CODE_29b3();
        LATCH4_802_15 = 1;
      }
      bVar1 = DAT_EXTMEM_0824 != '\0';
      DAT_EXTMEM_0824 = DAT_EXTMEM_0824 + -1;
      DAT_EXTMEM_0823 = DAT_EXTMEM_0823 + (-1 - ((bVar1 << 7) >> 7));
    }
  }
  return param_1;
}



// ==== FUN_CODE_2858 @ CODE:2858  (57 bytes)

undefined1 FUN_CODE_2858(byte param_1,undefined1 *param_2)

{
  bool bVar1;
  char in_PSW;
  undefined1 in_stack_000000fc;
  
  if (100U - (in_PSW >> 7) <= param_1) {
    *param_2 = 0;
    if (DAT_EXTMEM_0824 != '\0' || DAT_EXTMEM_0823 != '\0') {
      if (DAT_EXTMEM_0824 == '\x01' && DAT_EXTMEM_0823 == '\0') {
        FUN_CODE_29b3();
        LATCH4_802_15 = 1;
      }
      bVar1 = DAT_EXTMEM_0824 != '\0';
      DAT_EXTMEM_0824 = DAT_EXTMEM_0824 + -1;
      DAT_EXTMEM_0823 = DAT_EXTMEM_0823 + (-1 - ((bVar1 << 7) >> 7));
    }
  }
  return in_stack_000000fc;
}



// ==== FUN_CODE_2891 @ CODE:2891  (6 bytes)

void FUN_CODE_2891(void)

{
  return;
}



// ==== FUN_CODE_2897 @ CODE:2897  (69 bytes)

/* WARNING: Removing unreachable block (CODE,0x28d0) */

void FUN_CODE_2897(void)

{
  DAT_INTMEM_c0 = 0xaa;
  DAT_INTMEM_c1 = 0x55;
  DAT_INTMEM_c2 = 0xf0;
  DAT_INTMEM_37 = 0xaa;
  DAT_INTMEM_38 = 0x55;
  DAT_INTMEM_39 = 0xf0;
  _0_3 = 1;
  TL0 = 0x9e;
  TH0 = 0xd5;
  FUN_CODE_29a5();
  return;
}



// ==== FUN_CODE_28dc @ CODE:28dc  (15 bytes)

void FUN_CODE_28dc(void)

{
  if (_0_3 == '\0') {
    FUN_CODE_71c6(1);
    return;
  }
  FUN_CODE_71cf(2);
  return;
}



// ==== FUN_CODE_28eb @ CODE:28eb  (15 bytes)

void FUN_CODE_28eb(void)

{
  if (_0_3 == '\0') {
    FUN_CODE_71c6(0x1a);
    return;
  }
  FUN_CODE_71cf(0x37);
  return;
}



// ==== FUN_CODE_28fa @ CODE:28fa  (15 bytes)

void FUN_CODE_28fa(void)

{
  if (_0_3 == '\0') {
    FUN_CODE_71c6(1);
    return;
  }
  FUN_CODE_71cf(1);
  return;
}



// ==== FUN_CODE_2909 @ CODE:2909  (8 bytes)

void FUN_CODE_2909(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 | 1;
  return;
}



// ==== FUN_CODE_2911 @ CODE:2911  (8 bytes)

void FUN_CODE_2911(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 & 0xfe;
  return;
}



// ==== FUN_CODE_2921 @ CODE:2921  (8 bytes)

void FUN_CODE_2921(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 | 0x20;
  return;
}



// ==== FUN_CODE_2929 @ CODE:2929  (8 bytes)

void FUN_CODE_2929(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 & 0xdf;
  return;
}



// ==== FUN_CODE_2931 @ CODE:2931  (8 bytes)

void FUN_CODE_2931(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 | 0x40;
  return;
}



// ==== FUN_CODE_2939 @ CODE:2939  (8 bytes)

void FUN_CODE_2939(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 & 0xbf;
  return;
}



// ==== FUN_CODE_2949 @ CODE:2949  (8 bytes)

void FUN_CODE_2949(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 | 0x80;
  return;
}



// ==== FUN_CODE_2951 @ CODE:2951  (8 bytes)

void FUN_CODE_2951(void)

{
  byte bVar1;
  
  bVar1 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar1 & 0x7f;
  return;
}



// ==== FUN_CODE_2959 @ CODE:2959  (6 bytes)

void FUN_CODE_2959(void)

{
  LATCH3_7SEG_802_15 = 0;
  return;
}



// ==== FUN_CODE_295f @ CODE:295f  (7 bytes)

void FUN_CODE_295f(void)

{
  LATCH3_7SEG_802_15 = 0xff;
  return;
}



// ==== FUN_CODE_2966 @ CODE:2966  (7 bytes)

void FUN_CODE_2966(void)

{
  LATCH3_7SEG_802_15 = 0xc0;
  return;
}



// ==== FUN_CODE_296d @ CODE:296d  (7 bytes)

void FUN_CODE_296d(void)

{
  LATCH3_7SEG_802_15 = 0xf9;
  return;
}



// ==== FUN_CODE_2974 @ CODE:2974  (7 bytes)

void FUN_CODE_2974(void)

{
  LATCH3_7SEG_802_15 = 0xa4;
  return;
}



// ==== FUN_CODE_297b @ CODE:297b  (7 bytes)

void FUN_CODE_297b(void)

{
  LATCH3_7SEG_802_15 = 0xb0;
  return;
}



// ==== FUN_CODE_2982 @ CODE:2982  (7 bytes)

void FUN_CODE_2982(void)

{
  LATCH3_7SEG_802_15 = 0x99;
  return;
}



// ==== FUN_CODE_2989 @ CODE:2989  (7 bytes)

void FUN_CODE_2989(void)

{
  LATCH3_7SEG_802_15 = 0x92;
  return;
}



// ==== FUN_CODE_2990 @ CODE:2990  (7 bytes)

void FUN_CODE_2990(void)

{
  LATCH3_7SEG_802_15 = 0x80;
  return;
}



// ==== FUN_CODE_2997 @ CODE:2997  (7 bytes)

void FUN_CODE_2997(void)

{
  LATCH3_7SEG_802_15 = 0x88;
  return;
}



// ==== FUN_CODE_299e @ CODE:299e  (7 bytes)

void FUN_CODE_299e(void)

{
  LATCH3_7SEG_802_15 = 0xc6;
  return;
}



// ==== FUN_CODE_29a5 @ CODE:29a5  (7 bytes)

void FUN_CODE_29a5(void)

{
  LATCH3_7SEG_802_15 = 0x86;
  return;
}



// ==== FUN_CODE_29ac @ CODE:29ac  (7 bytes)

void FUN_CODE_29ac(void)

{
  LATCH3_7SEG_802_15 = 0x8e;
  return;
}



// ==== FUN_CODE_29b3 @ CODE:29b3  (7 bytes)

void FUN_CODE_29b3(void)

{
  LATCH3_7SEG_802_15 = 0xb6;
  return;
}



// ==== FUN_CODE_2a44 @ CODE:2a44  (11 bytes)

void FUN_CODE_2a44(void)

{
  DAT_EXTMEM_06ce = 0;
  DAT_EXTMEM_06cf = 0x4c;
  return;
}



// ==== isr_serial @ CODE:2a4f  (168 bytes)

char isr_serial(char param_1,char param_2,char param_3)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = TI;
  cVar3 = param_1;
  if (cVar2 != '\0') {
    TI = 0;
    FUN_CODE_2931();
    FUN_CODE_1e1c();
    cVar3 = param_2 + -1;
    DAT_EXTMEM_0b29 = param_2;
    DAT_EXTMEM_0b2a = param_3;
    if (param_2 == '\0') {
      DAT_EXTMEM_0b27 = param_3;
      if (DAT_EXTMEM_0b38 == 'n') {
        bVar1 = SCON;
        SCON = bVar1 | 8;
        SBUF = param_3;
        cVar3 = param_3;
      }
      else {
        if (DAT_EXTMEM_0b38 == 'e') {
          cVar2 = '\0';
          FUN_CODE_71dc(param_3);
          DAT_EXTMEM_0b28 = cVar2;
        }
        else if (DAT_EXTMEM_0b38 == 'o') {
          cVar2 = '\x01';
          FUN_CODE_71dc(param_3);
          DAT_EXTMEM_0b28 = cVar2;
        }
        if (DAT_EXTMEM_0b28 == '\0') {
          bVar1 = SCON;
          SCON = bVar1 & 0xf7;
        }
        else {
          bVar1 = SCON;
          SCON = bVar1 | 8;
        }
        SBUF = DAT_EXTMEM_0b27;
        cVar3 = DAT_EXTMEM_0b27;
      }
    }
  }
  cVar2 = RI;
  if (cVar2 == '\0') {
    FUN_CODE_2939(cVar3);
  }
  else {
    FUN_CODE_2931();
    RI = 0;
    DAT_EXTMEM_0b27 = SBUF;
    FUN_CODE_1aeb(0,DAT_EXTMEM_0b27);
  }
  return param_1;
}



// ==== FUN_CODE_2af7 @ CODE:2af7  (180 bytes)

undefined1
FUN_CODE_2af7(byte *param_1,char param_2,char param_3,byte param_4,byte param_5,undefined1 param_6,
             char param_7)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  undefined1 uStackX_0;
  
  DAT_EXTMEM_0b37 = DAT_EXTMEM_0b2f;
  puVar7 = &DAT_EXTMEM_0b30;
  DAT_EXTMEM_0b2e = param_4;
  DAT_EXTMEM_0b33 = param_7;
  DAT_EXTMEM_0b34 = param_5;
  DAT_EXTMEM_0b35 = param_6;
  DAT_EXTMEM_0b36 = param_4;
  do {
    DAT_EXTMEM_0b38 = *puVar7;
    puVar7 = (undefined1 *)0xb38;
    bVar5 = param_5;
    bVar2 = param_5;
    bVar3 = FUN_CODE_754c(param_6);
    bVar1 = CARRY1(bVar3,param_4);
    bVar3 = bVar3 + param_4 | (byte)param_1;
    param_2 = param_2 + '\x01';
    cVar4 = '\0';
    if (bVar3 == 0) goto LAB_CODE_2b58;
    cVar4 = FUN_CODE_2858(bVar3 ^ *param_1,param_2);
    bVar5 = cVar4 + param_4 * '\x02';
    if (param_7 != '\x12') {
      return uStackX_0;
    }
    if (bVar2 != 0) {
      bVar5 = bVar5 / bVar2;
    }
    param_7 = '\x12';
  } while (param_3 != '+');
  uVar6 = P0;
  cVar4 = P0;
  param_2 = (bVar5 - 1 ^ 0x2b) + cVar4 + param_4;
  nop();
  nop();
  nop();
  *param_1 = *param_1 - 1;
  bVar5 = 0;
  bVar1 = 0x73 < (_0_3 != '\0');
  cVar4 = (_0_3 != '\0') + -0x74;
LAB_CODE_2b58:
  TH1 = *(undefined1 *)CONCAT11(bVar5 + (',' - ((bVar1 << 7) >> 7)),cVar4);
  if ((DAT_EXTMEM_0b2e == 8) && (DAT_EXTMEM_0b30 != 'n')) {
    SCON = 0xd0;
  }
  else if ((DAT_EXTMEM_0b2e == 8) && (DAT_EXTMEM_0b30 == 'n')) {
    SCON = 0xd0;
  }
  else {
    SCON = 0x50;
  }
  PCON = 0x80;
  bVar5 = TMOD;
  TMOD = bVar5 & 0xf;
  bVar5 = TMOD;
  TMOD = bVar5 | 0x20;
  ET1 = 0;
  TR1 = 1;
  ES = 1;
  DAT_EXTMEM_0b32 = SBUF;
  DAT_EXTMEM_0b31 = 0;
  uVar6 = FUN_CODE_2c82(param_2);
  return uVar6;
}



// ==== FUN_CODE_2c76 @ CODE:2c76  (3 bytes)

void FUN_CODE_2c76(void)

{
  TI = 1;
  return;
}



// ==== FUN_CODE_2c79 @ CODE:2c79  (1 bytes)

void FUN_CODE_2c79(void)

{
  return;
}



// ==== FUN_CODE_2c82 @ CODE:2c82  (8 bytes)

void FUN_CODE_2c82(void)

{
  byte bVar1;
  
  bVar1 = LATCH2_module_enable;
  LATCH2_module_enable = bVar1 | 0x80;
  return;
}



// ==== FUN_CODE_2c9a @ CODE:2c9a  (52 bytes)

void FUN_CODE_2c9a(void)

{
  FUN_CODE_79b6(0x70,0xb,1,0,0,7);
  FUN_CODE_79b6(0x3e,0xb,1,0,0,7);
  FUN_CODE_79b6(0x77,0xb,1,0,0,0xaf);
  FUN_CODE_2cce();
  FUN_CODE_2ced();
  return;
}



// ==== FUN_CODE_2cce @ CODE:2cce  (31 bytes)

void FUN_CODE_2cce(void)

{
  FUN_CODE_79b6(0x37,0xc,1,0,0,0xba);
  FUN_CODE_79b6(0x45,0xb,1,0,0,0x12);
  return;
}



// ==== FUN_CODE_2ced @ CODE:2ced  (42 bytes)

void FUN_CODE_2ced(void)

{
  FUN_CODE_79b6(0x26,0xc,1,0,0,0x11);
  DAT_EXTMEM_0c33 = 0;
  DAT_EXTMEM_0c34 = DAT_EXTMEM_0a11;
  DAT_EXTMEM_0c35 = 0;
  DAT_EXTMEM_0c36 = DAT_EXTMEM_0a13;
  return;
}



// ==== FUN_CODE_2d17 @ CODE:2d17  (1814 bytes)

char FUN_CODE_2d17(char param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  bVar1 = 0;
  DAT_EXTMEM_0b39 = param_2;
  FUN_CODE_08de(0);
  _4_4 = 0;
  if ((DAT_EXTMEM_0b39 < 0x14) << 7 < '\0') {
    FUN_CODE_7e29(DAT_EXTMEM_0b39 - 0x14,0x2c,0xc,1);
    DAT_EXTMEM_003d = DAT_EXTMEM_0c26;
    DAT_EXTMEM_003e = DAT_EXTMEM_0c27;
    DAT_EXTMEM_003f = DAT_EXTMEM_0c28;
    DAT_EXTMEM_0040 = DAT_EXTMEM_0c29;
    DAT_EXTMEM_0041 = DAT_EXTMEM_0c2b;
    DAT_EXTMEM_003c = bVar1;
    FUN_CODE_0841(0x2c,0xc,1,DAT_EXTMEM_0c2a,0);
    cVar3 = (&DAT_CODE_5fbc)[DAT_EXTMEM_0a20];
    if (cVar3 == '\x01') {
      DAT_EXTMEM_0b39 = 0;
    }
    else if (cVar3 == '\x02') {
      DAT_EXTMEM_0b39 = 0;
    }
    else if (cVar3 == '\x03') {
      if ((&DAT_CODE_5fc7)[DAT_EXTMEM_0a20] == '\x03') {
        if ((&DAT_CODE_5fd2)[DAT_EXTMEM_0a20] == 'A') {
          if ((DAT_EXTMEM_0b39 == 10) || (DAT_EXTMEM_0b39 == 1)) {
            if (DAT_EXTMEM_0b39 == 10) {
              _4_3 = 0;
            }
            bVar1 = DAT_EXTMEM_0b39;
            FUN_CODE_7e29(0x3d,0xc,1);
            if (bVar1 != 0 || param_1 != '\0') {
              FUN_CODE_7e29(0x3d,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0c37;
              DAT_EXTMEM_003e = DAT_EXTMEM_0c38;
              DAT_EXTMEM_003f = DAT_EXTMEM_0c39;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0c3a;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0c3c;
              bVar2 = 0;
              DAT_EXTMEM_003c = bVar1;
              FUN_CODE_0841(0x3d,0xc,1,DAT_EXTMEM_0c3b);
              FUN_CODE_7e29(0x5c,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0c56;
              DAT_EXTMEM_003e = DAT_EXTMEM_0c57;
              DAT_EXTMEM_003f = DAT_EXTMEM_0c58;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0c59;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0c5b;
              DAT_EXTMEM_003c = bVar2;
              FUN_CODE_0841(0x5c,0xc,1,DAT_EXTMEM_0c5a,0);
              if (((DAT_EXTMEM_0b45 >> 4 & 1) == 1) || ((DAT_EXTMEM_0b48 >> 4 & 1) != 0)) {
                _4_4 = 1;
              }
            }
            DAT_EXTMEM_0b39 = 0;
          }
          else {
            DAT_EXTMEM_0b39 = 0;
          }
        }
        else if ((&DAT_CODE_5fd2)[DAT_EXTMEM_0a20] == 'B') {
          if (DAT_EXTMEM_0b39 == 2) {
            bVar1 = DAT_EXTMEM_0b39;
            FUN_CODE_7e29(0xb9,0xc,1);
            if (bVar1 == 0 && param_1 == '\0') {
              DAT_EXTMEM_0b39 = 0;
            }
            else {
              _4_3 = 1;
              FUN_CODE_7e29(0x7b,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0c75;
              DAT_EXTMEM_003e = DAT_EXTMEM_0c76;
              DAT_EXTMEM_003f = DAT_EXTMEM_0c77;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0c78;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0c7a;
              bVar2 = 0;
              DAT_EXTMEM_003c = bVar1;
              FUN_CODE_0841(0x7b,0xc,1,DAT_EXTMEM_0c79);
              FUN_CODE_7e29(0xb9,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0cb3;
              DAT_EXTMEM_003e = DAT_EXTMEM_0cb4;
              DAT_EXTMEM_003f = DAT_EXTMEM_0cb5;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0cb6;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0cb8;
              cVar3 = '\0';
              DAT_EXTMEM_003c = bVar2;
              FUN_CODE_0841(0xb9,0xc,1,DAT_EXTMEM_0cb7);
              if (((DAT_EXTMEM_0b4b >> 4 & 1) == 1) || ((DAT_EXTMEM_0b51 >> 4 & 1) != 0)) {
                _4_4 = 1;
              }
              FUN_CODE_7e29(0xd8,0xc,1);
              if (cVar3 == '\0' && param_1 == '\0') {
                DAT_EXTMEM_0b39 = 4;
              }
              else {
                DAT_EXTMEM_0b39 = 3;
              }
            }
          }
          else if (DAT_EXTMEM_0b39 == 3) {
            bVar1 = DAT_EXTMEM_0b39;
            FUN_CODE_7e29(0xd8,0xc,1);
            if (bVar1 != 0 || param_1 != '\0') {
              FUN_CODE_7e29(0x7b,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0c75;
              DAT_EXTMEM_003e = DAT_EXTMEM_0c76;
              DAT_EXTMEM_003f = DAT_EXTMEM_0c77;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0c78;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0c7a;
              bVar2 = 0;
              DAT_EXTMEM_003c = bVar1;
              FUN_CODE_0841(0x7b,0xc,1,DAT_EXTMEM_0c79);
              FUN_CODE_7e29(0xd8,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0cd2;
              DAT_EXTMEM_003e = DAT_EXTMEM_0cd3;
              DAT_EXTMEM_003f = DAT_EXTMEM_0cd4;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0cd5;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0cd7;
              DAT_EXTMEM_003c = bVar2;
              FUN_CODE_0841(0xd8,0xc,1,DAT_EXTMEM_0cd6,0);
              if (((DAT_EXTMEM_0b4b >> 4 & 1) == 1) || ((DAT_EXTMEM_0b54 >> 4 & 1) != 0)) {
                _4_4 = 1;
              }
            }
            DAT_EXTMEM_0b39 = 4;
          }
          else if (DAT_EXTMEM_0b39 == 4) {
            bVar1 = DAT_EXTMEM_0b39;
            FUN_CODE_7e29(0x7b,0xc,1);
            DAT_EXTMEM_003d = DAT_EXTMEM_0c75;
            DAT_EXTMEM_003e = DAT_EXTMEM_0c76;
            DAT_EXTMEM_003f = DAT_EXTMEM_0c77;
            DAT_EXTMEM_0040 = DAT_EXTMEM_0c78;
            DAT_EXTMEM_0041 = DAT_EXTMEM_0c7a;
            DAT_EXTMEM_003c = bVar1;
            FUN_CODE_0841(0x7b,0xc,1,DAT_EXTMEM_0c79,0);
            if ((DAT_EXTMEM_0b4b >> 4 & 1) != 0) {
              _4_4 = 1;
            }
            DAT_EXTMEM_0b39 = 1;
          }
          else if ((DAT_EXTMEM_0b39 == 10) || (DAT_EXTMEM_0b39 == 1)) {
            if (DAT_EXTMEM_0b39 == 10) {
              _4_3 = 0;
            }
            bVar1 = DAT_EXTMEM_0b39;
            FUN_CODE_7e29(0x7b,0xc,1);
            if (bVar1 == 0 && param_1 == '\0') {
              DAT_EXTMEM_0b39 = 0;
            }
            else {
              FUN_CODE_7e29(0x7b,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0c75;
              DAT_EXTMEM_003e = DAT_EXTMEM_0c76;
              DAT_EXTMEM_003f = DAT_EXTMEM_0c77;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0c78;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0c7a;
              bVar2 = 0;
              DAT_EXTMEM_003c = bVar1;
              FUN_CODE_0841(0x7b,0xc,1,DAT_EXTMEM_0c79);
              FUN_CODE_7e29(0x9a,0xc,1);
              DAT_EXTMEM_003d = DAT_EXTMEM_0c94;
              DAT_EXTMEM_003e = DAT_EXTMEM_0c95;
              DAT_EXTMEM_003f = DAT_EXTMEM_0c96;
              DAT_EXTMEM_0040 = DAT_EXTMEM_0c97;
              DAT_EXTMEM_0041 = DAT_EXTMEM_0c99;
              cVar3 = '\0';
              DAT_EXTMEM_003c = bVar2;
              FUN_CODE_0841(0x9a,0xc,1,DAT_EXTMEM_0c98);
              if (((DAT_EXTMEM_0b4b >> 4 & 1) == 1) || ((DAT_EXTMEM_0b4e >> 4 & 1) != 0)) {
                _4_4 = 1;
              }
              FUN_CODE_7e29(0xb9,0xc,1);
              if (cVar3 == '\0' && param_1 == '\0') {
                DAT_EXTMEM_0b39 = 0;
              }
              else {
                DAT_EXTMEM_0b39 = 2;
              }
            }
          }
          else {
            DAT_EXTMEM_0b39 = 0;
          }
        }
        else {
          DAT_EXTMEM_0b39 = 0;
        }
      }
    }
    else if (cVar3 == '\n') {
      DAT_EXTMEM_0b39 = 0;
    }
    else if (cVar3 == '\0') {
      DAT_EXTMEM_0b39 = 0;
    }
    else {
      DAT_EXTMEM_0b39 = 0;
    }
    _0_0 = _4_3 & 1;
    _0_1 = _4_4 & 1;
    FUN_CODE_090f(0);
  }
  else if (DAT_EXTMEM_0b39 == 0x14) {
    FUN_CODE_08de(0,0);
    _0_0 = 0;
    _0_1 = 0;
    FUN_CODE_090f(0);
    DAT_EXTMEM_0b39 = 0;
  }
  else if (DAT_EXTMEM_0b39 == 0x15) {
    FUN_CODE_08de(0xff,0);
    _0_0 = 0;
    _0_1 = 0;
    FUN_CODE_090f(0);
    DAT_EXTMEM_0b39 = 0;
  }
  else if (DAT_EXTMEM_0b39 == 0x16) {
    FUN_CODE_08de(0,0);
    _0_0 = 0;
    _0_1 = 0;
    FUN_CODE_090f(0);
    DAT_EXTMEM_0b39 = 0x17;
  }
  else if (DAT_EXTMEM_0b39 == 0x17) {
    FUN_CODE_08de(0xff,0);
    _0_0 = 0;
    _0_1 = 0;
    FUN_CODE_090f(0);
    DAT_EXTMEM_0b39 = 0x16;
  }
  else {
    bVar1 = DAT_EXTMEM_0b39 ^ 0x18;
    if (bVar1 == 0) {
      FUN_CODE_08de(0);
      FUN_CODE_7e29(0xce,0x5b,0xff);
      DAT_EXTMEM_003d = 0;
      DAT_EXTMEM_003e = '\0';
      DAT_EXTMEM_003f = 0;
      DAT_EXTMEM_0040 = 0;
      DAT_EXTMEM_0041 = 1;
      DAT_EXTMEM_003c = bVar1;
      FUN_CODE_0841(0xce,0x5b,0xff,0,0);
      _0_0 = 0;
      _0_1 = 0;
      FUN_CODE_090f(0);
      DAT_EXTMEM_0b39 = 0;
    }
    else {
      bVar1 = DAT_EXTMEM_0b39 ^ 0x19;
      if (bVar1 == 0) {
        FUN_CODE_08de(0);
        FUN_CODE_1772();
        FUN_CODE_74f3(0xb3a);
        FUN_CODE_7e29();
        DAT_EXTMEM_003c = bVar1;
        FUN_CODE_74ea(0xb3a,0,0);
        DAT_EXTMEM_003d = 0;
        DAT_EXTMEM_003e = '\0';
        DAT_EXTMEM_003f = 0;
        DAT_EXTMEM_0040 = 0;
        DAT_EXTMEM_0041 = 1;
        FUN_CODE_0841();
        if (((&DAT_CODE_5fbc)[DAT_EXTMEM_0a20] == '\x03') &&
           ((&DAT_CODE_5fc7)[DAT_EXTMEM_0a20] == '\x03')) {
          bVar1 = DAT_EXTMEM_0a20;
          FUN_CODE_7e29(0xce,0x5b,0xff);
          DAT_EXTMEM_003d = CARRY1(DAT_EXTMEM_0a11,DAT_EXTMEM_0a13 >> 1);
          DAT_EXTMEM_003e = DAT_EXTMEM_0a11 + (DAT_EXTMEM_0a13 >> 1);
          DAT_EXTMEM_003f = 0;
          DAT_EXTMEM_0040 = 0;
          DAT_EXTMEM_0041 = 1;
          DAT_EXTMEM_003c = bVar1;
          FUN_CODE_0841(0xce,0x5b,0xff,0,0);
        }
        _0_0 = 0;
        _0_1 = 0;
        FUN_CODE_090f(0);
        DAT_EXTMEM_0b39 = 0;
      }
      else {
        bVar1 = DAT_EXTMEM_0b39 ^ 0x1a;
        if (bVar1 == 0) {
          FUN_CODE_08de(0);
          FUN_CODE_1772();
          FUN_CODE_74f3(0xb3a);
          FUN_CODE_7e29();
          bVar2 = 0;
          DAT_EXTMEM_003c = bVar1;
          FUN_CODE_74ea(0xb3a,0);
          DAT_EXTMEM_003d = 0;
          DAT_EXTMEM_003e = 0;
          DAT_EXTMEM_003f = 0;
          DAT_EXTMEM_0040 = 0;
          DAT_EXTMEM_0041 = 1;
          FUN_CODE_0841();
          FUN_CODE_7e29(0xce,0x5b,0xff);
          DAT_EXTMEM_003d = CARRY1(DAT_EXTMEM_0a11,DAT_EXTMEM_0a13 >> 1);
          DAT_EXTMEM_003e = DAT_EXTMEM_0a11 + (DAT_EXTMEM_0a13 >> 1);
          DAT_EXTMEM_003f = 0;
          DAT_EXTMEM_0040 = 0;
          DAT_EXTMEM_0041 = 1;
          DAT_EXTMEM_003c = bVar2;
          FUN_CODE_0841(0xce,0x5b,0xff,0,0);
          _0_0 = 0;
          _0_1 = 0;
          FUN_CODE_090f(0);
          DAT_EXTMEM_0b39 = 0;
        }
        else if (DAT_EXTMEM_0b39 == 0x1b) {
          FUN_CODE_08de(0xff,0);
          _0_0 = 0;
          _0_1 = 0;
          FUN_CODE_090f(0);
          FUN_CODE_27f6();
          FUN_CODE_74f3(0xf4b,0xb5,0x5b,0xff);
          DAT_EXTMEM_0f4e = 0;
          DAT_EXTMEM_0f4f = DAT_EXTMEM_0a20;
          FUN_CODE_74f3(0xf50,0xc2,0x5b);
          FUN_CODE_74f3(0xf53,0x57,0xb,1);
          FUN_CODE_74f3(0xf56,0x6e,0xb);
          FUN_CODE_7af8(0x5a,0xb);
          bVar1 = 0;
          FUN_CODE_08de(0);
          FUN_CODE_7e29(0x5a,0xb,1);
          DAT_EXTMEM_003d = 0;
          DAT_EXTMEM_003e = '\0';
          DAT_EXTMEM_003f = 0;
          DAT_EXTMEM_0040 = 0;
          DAT_EXTMEM_0041 = 1;
          DAT_EXTMEM_003c = bVar1;
          FUN_CODE_0841(0x5a,0xb,1,0,0);
          _0_0 = 0;
          _0_1 = 0;
          FUN_CODE_090f(0);
          DAT_EXTMEM_0b39 = 0;
        }
        else {
          DAT_EXTMEM_0b39 = 0;
        }
      }
    }
  }
  cVar3 = DAT_EXTMEM_0b39 - 1;
  if (DAT_EXTMEM_0b39 != 0) {
    DAT_EXTMEM_0a26 = DAT_EXTMEM_0d33;
    DAT_EXTMEM_0a27 = DAT_EXTMEM_0d34;
    cVar3 = DAT_EXTMEM_0d34;
  }
  return cVar3;
}



// ==== FUN_CODE_342d @ CODE:342d  (552 bytes)

byte FUN_CODE_342d(byte param_1)

{
  byte bVar1;
  
  _4_6 = '\0';
  if ((_3_5 == '\x01') || (_3_4 == '\x01')) {
    _3_4 = '\0';
    _3_5 = '\0';
    FUN_CODE_7701(0xb,0x3e,0xb,1,0xb,1);
    if (param_1 == 0) {
      param_1 = 0;
    }
    else {
      do {
        _3_4 = '\0';
        FUN_CODE_77ea(0x3e,0xb,0xb,1,0xb,1);
      } while (_3_4 == '\x01');
      DAT_EXTMEM_0b40 = 0;
      if (((((DAT_EXTMEM_0b3e == 0x39) && (DAT_EXTMEM_0b3f == 0x34)) ||
           ((DAT_EXTMEM_0b3e == 0x39 && (DAT_EXTMEM_0b3f == 0x35)))) ||
          ((DAT_EXTMEM_0b3e == 0x39 && (DAT_EXTMEM_0b3f == 0x36)))) ||
         (((DAT_EXTMEM_0b3e == 0x39 && (DAT_EXTMEM_0b3f == 0x37)) ||
          (((DAT_EXTMEM_0b3e == 0x39 && (DAT_EXTMEM_0b3f == 0x38)) ||
           ((DAT_EXTMEM_0b3e == 0x39 && (DAT_EXTMEM_0b3f == 0x39)))))))) {
        if (DAT_EXTMEM_0b3f == 0x34) {
          DAT_EXTMEM_0b3d = 0x16;
        }
        else if (DAT_EXTMEM_0b3f == 0x35) {
          DAT_EXTMEM_0b3d = 0x19;
        }
        else if (DAT_EXTMEM_0b3f == 0x36) {
          DAT_EXTMEM_0b3d = 0x18;
        }
        else if (DAT_EXTMEM_0b3f == 0x38) {
          DAT_EXTMEM_0b3d = 0x15;
        }
        else if ((DAT_EXTMEM_0b3f == 0x37) || (DAT_EXTMEM_0b3f == 0x39)) {
          DAT_EXTMEM_0b3d = 0x1b;
        }
        else {
          DAT_EXTMEM_0b3d = 10;
        }
        _4_5 = '\x01';
        param_1 = DAT_EXTMEM_0b3f;
      }
      else {
        _4_6 = '\x01';
        _4_5 = '\0';
        param_1 = DAT_EXTMEM_0b3e;
      }
    }
    FUN_CODE_7701(0x54,0x70,0xb,1,10,1);
    if (param_1 != 0) {
      do {
        _3_5 = '\0';
        FUN_CODE_77ea(0x70,0x54,10,1,0xb,1);
      } while (_3_5 == '\x01');
      DAT_EXTMEM_0b74 = 0;
      _4_6 = '\x01';
    }
    if ((_4_6 != '\0') && (_4_5 != '\x01')) {
      FUN_CODE_74f3(0xd00,0x3e,0xb,1);
      DAT_EXTMEM_0d03 = DAT_EXTMEM_0a20;
      FUN_CODE_40e7(0x70,0xb);
      if (((param_1 ^ 0x80) < 0x80) << 7 < '\0') {
        FUN_CODE_2ced((param_1 ^ 0x80) + 0x80);
        DAT_EXTMEM_0b3d = 0;
        _4_6 = '\0';
      }
      else {
        DAT_EXTMEM_0b3d = 10;
      }
    }
  }
  if (((_3_6 == '\x01') || (_4_6 == '\x01')) && (_4_5 == '\0')) {
    _3_6 = '\0';
    FUN_CODE_7701(0x5c,0x77,0xb,1,10,1);
    if ((param_1 != 0) || (_4_6 != '\0')) {
      do {
        _3_6 = '\0';
        FUN_CODE_77ea(0x77,0x5c,10,1,0xb,1);
      } while (_3_6 == '\x01');
      if ((&DAT_CODE_5fbc)[DAT_EXTMEM_0a20] == '\x03') {
        bVar1 = DAT_EXTMEM_0a20;
        FUN_CODE_3655(0x77,0xb,1,(&DAT_CODE_5fc7)[DAT_EXTMEM_0a20]);
        if (((bVar1 ^ 0x80) < 0x80) << 7 < '\0') {
          FUN_CODE_2cce((bVar1 ^ 0x80) + 0x80);
          DAT_EXTMEM_0b3d = 0;
        }
        else if ((DAT_EXTMEM_0c3d == '*') || (DAT_EXTMEM_0c7b == '*')) {
          DAT_EXTMEM_0b3d = 0x16;
        }
        else if ((DAT_EXTMEM_0c3d == '+') || (DAT_EXTMEM_0c7b == '+')) {
          DAT_EXTMEM_0b3d = 0x1a;
        }
        else {
          DAT_EXTMEM_0b3d = 10;
        }
      }
    }
    _4_6 = '\0';
  }
  bVar1 = 0;
  if (((((DAT_EXTMEM_0b3d == 10) || (bVar1 = 0, DAT_EXTMEM_0b3d == 0x14)) ||
       (bVar1 = 0, DAT_EXTMEM_0b3d == 0x15)) ||
      (((bVar1 = 0, DAT_EXTMEM_0b3d == 0x16 || (bVar1 = 0, DAT_EXTMEM_0b3d == 0x17)) ||
       ((bVar1 = 0, DAT_EXTMEM_0b3d == 0x18 ||
        ((bVar1 = 0, DAT_EXTMEM_0b3d == 0x19 || (bVar1 = 0, DAT_EXTMEM_0b3d == 0x1a)))))))) ||
     ((bVar1 = 0, DAT_EXTMEM_0b3d == 0x1b ||
      (((bVar1 = DAT_EXTMEM_0b3d - 1, DAT_EXTMEM_0b3d != 0 &&
        (bVar1 = DAT_EXTMEM_0b3d - 10, DAT_EXTMEM_0b3d < 10)) && (_2_4 != '\0')))))) {
    _2_4 = '\0';
    FUN_CODE_2d17(bVar1);
    bVar1 = DAT_EXTMEM_0b3d;
  }
  return bVar1;
}



// ==== FUN_CODE_3655 @ CODE:3655  (2706 bytes)

byte FUN_CODE_3655(char param_1,byte param_2)

{
  ushort uVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  char *pcVar12;
  short sVar13;
  
  FUN_CODE_74f3(0xcf1);
  DAT_EXTMEM_0cf8 = 0xfc;
  DAT_EXTMEM_0cfc = 0;
  DAT_EXTMEM_0cf4 = param_1;
  FUN_CODE_74ea(0xcf1);
  FUN_CODE_74f3(0xcf5);
  if (DAT_EXTMEM_0cf4 == '\x02') {
    DAT_EXTMEM_0cf8 = 0xff;
  }
  else if (DAT_EXTMEM_0cf4 == '\x03') {
    FUN_CODE_2cce();
    DAT_EXTMEM_0cf9 = 0;
    while( true ) {
      cVar7 = (DAT_EXTMEM_0cf9 < 6) << 7;
      cVar2 = DAT_EXTMEM_0cf9 - 6;
      if (DAT_EXTMEM_0cf9 >= 6) break;
      bVar5 = DAT_EXTMEM_0cf9;
      FUN_CODE_7430(0,0xcf6,1);
      bVar8 = (byte)((ushort)bVar5 * 0x1f);
      bVar9 = bVar8 + 0x3d;
      cVar2 = ((char)((ushort)bVar5 * 0x1f >> 8) - (((0xc2 < bVar8) << 7) >> 7)) + '\f';
      FUN_CODE_74ea(0xcf5);
      FUN_CODE_74f3(0xf78);
      DAT_EXTMEM_0f7b = 10;
      DAT_EXTMEM_0f7c = 0;
      DAT_EXTMEM_0f7d = 0x18;
      FUN_CODE_7f16(1);
      cVar7 = '\0';
      bVar5 = 0;
      *(undefined1 *)
       CONCAT11('\f' - (((0xa9 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                DAT_EXTMEM_0cf9 * '\x1f' + 0x56) = 0;
      while( true ) {
        FUN_CODE_74ea(bVar5,0xcf5);
        cVar3 = FUN_CODE_736c();
        if (cVar3 == '\n') break;
        FUN_CODE_7430(0,0xcf6,1);
        uVar6 = FUN_CODE_74ea(0xcf1);
        cVar7 = cVar2;
        bVar5 = bVar9;
        FUN_CODE_74ea(uVar6,0xcf5);
        param_2 = cVar2 - (cVar7 - (((bVar9 < bVar5) << 7) >> 7));
        bVar4 = param_2 ^ 0x80;
        bVar8 = 0x80 - (((bVar9 - bVar5 < 0x97) << 7) >> 7);
        cVar7 = (bVar4 < bVar8) << 7;
        bVar5 = bVar4 - bVar8;
        if (bVar4 >= bVar8) {
          return bVar5;
        }
      }
      FUN_CODE_74ea(0xcf5);
      cVar3 = FUN_CODE_7385(1);
      cVar2 = '\0';
      if (cVar3 == '.') break;
      DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1;
    }
    FUN_CODE_74ea(cVar2,0xcf5);
    bVar5 = FUN_CODE_7385(1);
    if ((bVar5 ^ 0x2e) != 0) {
      return bVar5 ^ 0x2e;
    }
    FUN_CODE_7430(0xcf6,2);
    cVar2 = '\0';
    DAT_EXTMEM_0cf9 = 0;
    do {
      FUN_CODE_74ea(cVar2,0xcf5);
      uVar6 = FUN_CODE_736c();
      FUN_CODE_7e00(uVar6);
      if (cVar7 < '\0') {
LAB_CODE_379d:
        uVar1 = (ushort)DAT_EXTMEM_0cf9;
        bVar5 = (byte)(uVar1 * 3);
        FUN_CODE_74ea(0xcf5);
        FUN_CODE_74f3(0xf78);
        DAT_EXTMEM_0f7b = 0xd;
        DAT_EXTMEM_0f7c = 0;
        DAT_EXTMEM_0f7d = 3;
        FUN_CODE_7f16(bVar5 + 0x45,((char)(uVar1 * 3 >> 8) - (((0xba < bVar5) << 7) >> 7)) + '\v',1)
        ;
        FUN_CODE_7430(0,0xcf6,3);
      }
      else {
        FUN_CODE_74ea(0xcf5);
        cVar7 = FUN_CODE_736c();
        bVar5 = DAT_EXTMEM_0cf9;
        if (cVar7 == '@') goto LAB_CODE_379d;
        *(undefined1 *)
         CONCAT11('\v' - (((0xba < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                  DAT_EXTMEM_0cf9 * '\x03' + 0x45) = 0x41;
        bVar9 = bVar5 * '\x03';
        *(undefined1 *)CONCAT11('\v' - (((0xb9 < bVar9) << 7) >> 7),bVar9 + 0x46) = 0x41;
        bVar5 = bVar5 * '\x03';
        *(undefined1 *)CONCAT11('\v' - (((0xb8 < bVar5) << 7) >> 7),bVar5 + 0x47) = 0;
      }
      bVar5 = DAT_EXTMEM_0cf9 + 1;
      cVar7 = (bVar5 < 6) << 7;
      cVar2 = DAT_EXTMEM_0cf9 - 5;
      DAT_EXTMEM_0cf9 = bVar5;
    } while (bVar5 < 6);
    DAT_EXTMEM_0cf9 = 0;
    do {
      for (bVar5 = 0x18; bVar9 = DAT_EXTMEM_0cf9, 0x7f < (bVar5 ^ 0x80); bVar5 = bVar5 - 1) {
        bVar8 = DAT_EXTMEM_0cf9 * '\x1f' + 0x3d;
        cVar7 = *(char *)CONCAT11(((char)bVar5 >> 7) +
                                  (('\f' - (((0xc2 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7)) -
                                  ((CARRY1(bVar8,bVar5) << 7) >> 7)),bVar8 + bVar5);
        if (((cVar7 != ' ') && (cVar7 != '\0')) && (param_2 = DAT_EXTMEM_0cf9, cVar7 != '\n'))
        break;
        bVar8 = DAT_EXTMEM_0cf9 * '\x1f' + 0x3d;
        *(undefined1 *)
         CONCAT11(((char)bVar5 >> 7) +
                  (('\f' - (((0xc2 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7)) -
                  ((CARRY1(bVar8,bVar5) << 7) >> 7)),bVar8 + bVar5) = 0;
        param_2 = bVar9;
      }
      DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1;
    } while (DAT_EXTMEM_0cf9 != 6);
    for (DAT_EXTMEM_0cf9 = 0; DAT_EXTMEM_0cf9 < 6; DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1) {
      bVar9 = (byte)((ushort)DAT_EXTMEM_0cf9 * 0x1f);
      bVar5 = DAT_EXTMEM_0cf9;
      FUN_CODE_67fb(bVar9 + 0x3d,
                    ((char)((ushort)DAT_EXTMEM_0cf9 * 0x1f >> 8) - (((0xc2 < bVar9) << 7) >> 7)) +
                    '\f',1,1);
      if (bVar5 == 0 && param_2 == 0) {
        return 0;
      }
    }
    for (DAT_EXTMEM_0cf9 = 0; bVar5 = DAT_EXTMEM_0cf9, (DAT_EXTMEM_0cf9 < 6) << 7 < '\0';
        DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1) {
      bVar9 = *(byte *)CONCAT11('\v' - (((0xba < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                                DAT_EXTMEM_0cf9 * '\x03' + 0x45);
      if (((bVar9 < 0x40) << 7 < '\0') || (0x47 < bVar9)) {
        if (((bVar9 < 0x50) << 7 < '\0') || (0x57 < bVar9)) {
          *(undefined1 *)
           CONCAT11('\f' - (((0xc3 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                    DAT_EXTMEM_0cf9 * '\x1f' + 0x3c) = 0;
        }
        else {
          param_2 = *(char *)CONCAT11('\v' - (((0xba < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                                      DAT_EXTMEM_0cf9 * '\x03' + 0x45) + 0xb0;
          *(byte *)CONCAT11('\f' - (((0xc3 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                            DAT_EXTMEM_0cf9 * '\x1f' + 0x3c) = param_2;
        }
      }
      else {
        *(byte *)CONCAT11('\f' - (((0xc3 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                          DAT_EXTMEM_0cf9 * '\x1f' + 0x3c) = bVar9 - 0x40;
        param_2 = bVar5;
      }
    }
    for (DAT_EXTMEM_0cf9 = 0; DAT_EXTMEM_0cf9 < 6; DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1) {
      param_2 = *(byte *)CONCAT11('\v' - (((0xb8 < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                                  DAT_EXTMEM_0cf9 * '\x03' + 0x47);
      if (((param_2 < 0x30) << 7 < '\0') || (0x38 < param_2)) {
        *(undefined1 *)
         CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                  DAT_EXTMEM_0cf9 * '\x1f' + 0x3b) = 0;
      }
      else {
        param_2 = param_2 - 0x2f;
        *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                          DAT_EXTMEM_0cf9 * '\x1f' + 0x3b) = param_2;
      }
    }
    _4_7 = '\0';
    for (DAT_EXTMEM_0cf9 = 0; DAT_EXTMEM_0cf9 < 6; DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1) {
      param_2 = (&DAT_CODE_5fdd)[DAT_EXTMEM_0cf9];
      if (param_2 == 0x6f) {
        if ((*(byte *)CONCAT11('\v' - (((0xb9 < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                               DAT_EXTMEM_0cf9 * '\x03' + 0x46) & 1) == 0) {
          _4_7 = '\0';
        }
        else {
          _4_7 = '\x01';
        }
      }
      else if ((param_2 == 0x75) && (_4_7 != '\0')) {
        pbVar10 = (byte *)CONCAT11('\v' - (((0xb9 < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                                   DAT_EXTMEM_0cf9 * '\x03' + 0x46);
        *pbVar10 = *pbVar10 | 1;
      }
    }
    for (DAT_EXTMEM_0cf9 = 0; (DAT_EXTMEM_0cf9 < 6) << 7 < '\0';
        DAT_EXTMEM_0cf9 = DAT_EXTMEM_0cf9 + 1) {
      if ((*(byte *)CONCAT11('\v' - (((0xb9 < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                             DAT_EXTMEM_0cf9 * '\x03' + 0x46) >> 1 & 1) != 0) {
        bVar9 = (byte)((ushort)DAT_EXTMEM_0cf9 * 0x1f);
        bVar5 = DAT_EXTMEM_0cf9;
        FUN_CODE_7e29(bVar9 + 0x3d,
                      ((char)((ushort)DAT_EXTMEM_0cf9 * 0x1f >> 8) - (((0xc2 < bVar9) << 7) >> 7)) +
                      '\f',1);
        bVar9 = (byte)((ushort)DAT_EXTMEM_0cf9 * 0x1f);
        DAT_EXTMEM_0d13 = param_2;
        DAT_EXTMEM_0d14 = bVar5;
        FUN_CODE_4388(bVar9 + 0x3d,
                      ((char)((ushort)DAT_EXTMEM_0cf9 * 0x1f >> 8) - (((0xc2 < bVar9) << 7) >> 7)) +
                      '\f',1,0);
      }
      bVar5 = DAT_EXTMEM_0cf9;
      if ((*(byte *)CONCAT11('\v' - (((0xb9 < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                             DAT_EXTMEM_0cf9 * '\x03' + 0x46) & 1) == 1) {
        pbVar10 = (byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                   DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
        param_2 = *pbVar10;
        if ((param_2 < 9) && (param_2 != 0)) {
          *pbVar10 = 8;
        }
        if ((&DAT_CODE_5fdd)[bVar5] == 'o') {
          bVar9 = (byte)((ushort)bVar5 * 0x1f);
          FUN_CODE_678f(bVar9 + 0x3d,
                        ((char)((ushort)bVar5 * 0x1f >> 8) - (((0xc2 < bVar9) << 7) >> 7)) + '\f',1)
          ;
          if (bVar5 == 0 && param_2 == 0) {
            bVar5 = *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                      DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
            FUN_CODE_6775();
            bVar9 = DAT_EXTMEM_0cf9;
            param_2 = DAT_EXTMEM_0a23 >> 1;
            DAT_EXTMEM_0cfb = bVar5;
            if ((param_2 < bVar5) << 7 < '\0') {
              puVar11 = (undefined1 *)
                        CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                 DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
              *puVar11 = 0;
              puVar11[1] = 0;
              DAT_EXTMEM_0cfc = DAT_EXTMEM_0cfb;
            }
            else {
              puVar11 = (undefined1 *)
                        CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                 DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
              *puVar11 = 0;
              puVar11[1] = param_2 - bVar5 >> 1;
              param_2 = *(byte *)(CONCAT11('\f' - (((0xc6 < bVar9 * '\x1f') << 7) >> 7),
                                           bVar9 * '\x1f' + 0x39) + 1);
              DAT_EXTMEM_0cfc = bVar5 + param_2;
            }
          }
          else {
            bVar5 = *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                      DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
            FUN_CODE_020f();
            bVar9 = DAT_EXTMEM_0cf9;
            param_2 = DAT_EXTMEM_0a23 >> 1;
            DAT_EXTMEM_0cfa = bVar5;
            if ((param_2 < bVar5) << 7 < '\0') {
              puVar11 = (undefined1 *)
                        CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                 DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
              *puVar11 = 0;
              puVar11[1] = 0;
              DAT_EXTMEM_0cfc = DAT_EXTMEM_0cfa;
            }
            else {
              puVar11 = (undefined1 *)
                        CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                 DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
              *puVar11 = 0;
              puVar11[1] = param_2 - bVar5 >> 1;
              param_2 = *(byte *)(CONCAT11('\f' - (((0xc6 < bVar9 * '\x1f') << 7) >> 7),
                                           bVar9 * '\x1f' + 0x39) + 1);
              DAT_EXTMEM_0cfc = bVar5 + param_2;
            }
          }
        }
        else if ((&DAT_CODE_5fdd)[DAT_EXTMEM_0cf9] == 'u') {
          bVar9 = (byte)((ushort)DAT_EXTMEM_0cf9 * 0x1f);
          bVar5 = DAT_EXTMEM_0cf9;
          FUN_CODE_678f(bVar9 + 0x3d,
                        ((char)((ushort)DAT_EXTMEM_0cf9 * 0x1f >> 8) - (((0xc2 < bVar9) << 7) >> 7))
                        + '\f',1);
          if (bVar5 == 0 && param_2 == 0) {
            bVar5 = *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                      DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
            FUN_CODE_6775();
            param_2 = DAT_EXTMEM_0cfc;
            bVar9 = DAT_EXTMEM_0a23 >> 1;
            DAT_EXTMEM_0cfb = bVar5;
            if (((bVar9 < bVar5) << 7 < '\0') || (bVar9 + 1 <= DAT_EXTMEM_0cfc)) {
              if ((DAT_EXTMEM_0a23 < DAT_EXTMEM_0cfc) ||
                 (DAT_EXTMEM_0cfc < (DAT_EXTMEM_0a23 >> 1) + 1)) {
                bVar9 = DAT_EXTMEM_0a23 - bVar5;
                param_2 = ((DAT_EXTMEM_0a23 < bVar5) << 7) >> 7;
                pbVar10 = (byte *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                           DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *pbVar10 = param_2;
                pbVar10[1] = bVar9;
              }
              else if (bVar5 < (DAT_EXTMEM_0a23 - DAT_EXTMEM_0cfc) + 1) {
                bVar5 = (DAT_EXTMEM_0a23 - DAT_EXTMEM_0cfc) - bVar5;
                if ((bVar5 & 1) == 0) {
                  param_2 = CARRY1(DAT_EXTMEM_0cfc,bVar5 >> 1);
                  cVar7 = DAT_EXTMEM_0cfc + (bVar5 >> 1);
                  sVar13 = CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                    DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                  *(byte *)sVar13 = param_2;
                  *(char *)(sVar13 + 1) = cVar7;
                }
                else {
                  bVar9 = DAT_EXTMEM_0cfc + (bVar5 >> 1);
                  pcVar12 = (char *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                             DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                  *pcVar12 = CARRY1(DAT_EXTMEM_0cfc,bVar5 >> 1) - (((0xfe < bVar9) << 7) >> 7);
                  pcVar12[1] = bVar9 + 1;
                }
              }
              else {
                bVar9 = DAT_EXTMEM_0a23 - bVar5;
                param_2 = ((DAT_EXTMEM_0a23 < bVar5) << 7) >> 7;
                pbVar10 = (byte *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                           DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *pbVar10 = param_2;
                pbVar10[1] = bVar9;
              }
            }
            else {
              bVar9 = bVar9 - bVar5;
              if ((bVar9 & 1) == 0) {
                bVar5 = DAT_EXTMEM_0a23 >> 1;
                param_2 = CARRY1(bVar5,bVar9 >> 1);
                sVar13 = CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                  DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *(byte *)sVar13 = param_2;
                *(byte *)(sVar13 + 1) = bVar5 + (bVar9 >> 1);
              }
              else {
                param_2 = DAT_EXTMEM_0a23 >> 1;
                bVar5 = param_2 + (bVar9 >> 1);
                pcVar12 = (char *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                           DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *pcVar12 = CARRY1(param_2,bVar9 >> 1) - (((0xfe < bVar5) << 7) >> 7);
                pcVar12[1] = bVar5 + 1;
              }
            }
          }
          else {
            bVar5 = *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                      DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
            FUN_CODE_020f();
            param_2 = DAT_EXTMEM_0cfc;
            bVar9 = DAT_EXTMEM_0a23 >> 1;
            DAT_EXTMEM_0cfa = bVar5;
            if (((bVar9 < bVar5) << 7 < '\0') || (bVar9 + 1 <= DAT_EXTMEM_0cfc)) {
              if ((DAT_EXTMEM_0a23 < DAT_EXTMEM_0cfc) ||
                 (DAT_EXTMEM_0cfc < (DAT_EXTMEM_0a23 >> 1) + 1)) {
                bVar9 = DAT_EXTMEM_0a23 - bVar5;
                param_2 = ((DAT_EXTMEM_0a23 < bVar5) << 7) >> 7;
                pbVar10 = (byte *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                           DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *pbVar10 = param_2;
                pbVar10[1] = bVar9;
              }
              else if (bVar5 < (DAT_EXTMEM_0a23 - DAT_EXTMEM_0cfc) + 1) {
                bVar5 = (DAT_EXTMEM_0a23 - DAT_EXTMEM_0cfc) - bVar5;
                if ((bVar5 & 1) == 0) {
                  param_2 = CARRY1(DAT_EXTMEM_0cfc,bVar5 >> 1);
                  cVar7 = DAT_EXTMEM_0cfc + (bVar5 >> 1);
                  sVar13 = CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                    DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                  *(byte *)sVar13 = param_2;
                  *(char *)(sVar13 + 1) = cVar7;
                }
                else {
                  bVar9 = DAT_EXTMEM_0cfc + (bVar5 >> 1);
                  pcVar12 = (char *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                             DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                  *pcVar12 = CARRY1(DAT_EXTMEM_0cfc,bVar5 >> 1) - (((0xfe < bVar9) << 7) >> 7);
                  pcVar12[1] = bVar9 + 1;
                }
              }
              else {
                bVar9 = DAT_EXTMEM_0a23 - bVar5;
                param_2 = ((DAT_EXTMEM_0a23 < bVar5) << 7) >> 7;
                pbVar10 = (byte *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                           DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *pbVar10 = param_2;
                pbVar10[1] = bVar9;
              }
            }
            else {
              bVar9 = bVar9 - bVar5;
              if ((bVar9 & 1) == 0) {
                bVar5 = DAT_EXTMEM_0a23 >> 1;
                param_2 = CARRY1(bVar5,bVar9 >> 1);
                sVar13 = CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                  DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *(byte *)sVar13 = param_2;
                *(byte *)(sVar13 + 1) = bVar5 + (bVar9 >> 1);
              }
              else {
                param_2 = DAT_EXTMEM_0a23 >> 1;
                bVar5 = param_2 + (bVar9 >> 1);
                pcVar12 = (char *)CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                           DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
                *pcVar12 = CARRY1(param_2,bVar9 >> 1) - (((0xfe < bVar5) << 7) >> 7);
                pcVar12[1] = bVar5 + 1;
              }
            }
          }
        }
        else {
          puVar11 = (undefined1 *)
                    CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                             DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
          *puVar11 = 0;
          puVar11[1] = 0;
        }
      }
      else {
        bVar9 = (byte)((ushort)DAT_EXTMEM_0cf9 * 0x1f);
        FUN_CODE_678f(bVar9 + 0x3d,
                      ((char)((ushort)DAT_EXTMEM_0cf9 * 0x1f >> 8) - (((0xc2 < bVar9) << 7) >> 7)) +
                      '\f',1);
        if (bVar5 == 0 && param_2 == 0) {
          bVar5 = *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                    DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
          FUN_CODE_6775();
          param_2 = DAT_EXTMEM_0a23;
          DAT_EXTMEM_0cfb = bVar5;
          if ((DAT_EXTMEM_0a23 < bVar5) << 7 < '\0') {
            puVar11 = (undefined1 *)
                      CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                               DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
            *puVar11 = 0;
            puVar11[1] = 0;
          }
          else {
            bVar5 = DAT_EXTMEM_0a23 - bVar5;
            puVar11 = (undefined1 *)
                      CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                               DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
            *puVar11 = 0;
            puVar11[1] = bVar5 >> 1;
          }
        }
        else {
          bVar5 = *(byte *)CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                    DAT_EXTMEM_0cf9 * '\x1f' + 0x3b);
          FUN_CODE_020f();
          param_2 = DAT_EXTMEM_0a23;
          DAT_EXTMEM_0cfa = bVar5;
          if ((DAT_EXTMEM_0a23 < bVar5) << 7 < '\0') {
            puVar11 = (undefined1 *)
                      CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                               DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
            *puVar11 = 0;
            puVar11[1] = 0;
          }
          else {
            bVar5 = DAT_EXTMEM_0a23 - bVar5;
            puVar11 = (undefined1 *)
                      CONCAT11('\f' - (((0xc6 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                               DAT_EXTMEM_0cf9 * '\x1f' + 0x39);
            *puVar11 = 0;
            puVar11[1] = bVar5 >> 1;
          }
        }
      }
      bVar5 = DAT_EXTMEM_0c34;
      cVar7 = DAT_EXTMEM_0a11;
      if ((*(byte *)CONCAT11('\v' - (((0xb9 < DAT_EXTMEM_0cf9 * '\x03') << 7) >> 7),
                             DAT_EXTMEM_0cf9 * '\x03' + 0x46) >> 2 & 1) == 1) {
        bVar5 = (byte)((ushort)DAT_EXTMEM_0cf9 * 0x1f);
        DAT_EXTMEM_0ed0 =
             *(undefined1 *)
              CONCAT11('\f' - (((0xc3 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                       DAT_EXTMEM_0cf9 * '\x1f' + 0x3c);
        bVar9 = DAT_EXTMEM_0cf9;
        FUN_CODE_65e9(bVar5 + 0x3d,
                      ((char)((ushort)DAT_EXTMEM_0cf9 * 0x1f >> 8) - (((0xc2 < bVar5) << 7) >> 7)) +
                      '\f',1,*(undefined1 *)
                              CONCAT11('\f' - (((0xc4 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                       DAT_EXTMEM_0cf9 * '\x1f' + 0x3b));
        bVar5 = DAT_EXTMEM_0c34;
        cVar7 = DAT_EXTMEM_0a11;
        bVar8 = DAT_EXTMEM_0c36 - bVar9;
        param_2 = DAT_EXTMEM_0c35 - (param_2 - (((DAT_EXTMEM_0c36 < bVar9) << 7) >> 7));
        if (((param_2 ^ 0x80) < 0x80) << 7 < '\0') {
          if (DAT_EXTMEM_0a11 == '\0') {
            pcVar12 = (char *)CONCAT11('\f' - (((200 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                       DAT_EXTMEM_0cf9 * '\x1f' + 0x37);
            *pcVar12 = DAT_EXTMEM_0c33;
            pcVar12[1] = bVar5;
          }
          else {
            puVar11 = (undefined1 *)
                      CONCAT11('\f' - (((200 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                               DAT_EXTMEM_0cf9 * '\x1f' + 0x37);
            *puVar11 = 0;
            puVar11[1] = cVar7;
          }
        }
        else {
          FUN_CODE_73fa((param_2 ^ 0x80) + 0x80,0,2);
          bVar5 = DAT_EXTMEM_0c34 + bVar8;
          param_2 = DAT_EXTMEM_0c33 + (param_2 - ((CARRY1(DAT_EXTMEM_0c34,bVar8) << 7) >> 7));
          pbVar10 = (byte *)CONCAT11('\f' - (((200 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                     DAT_EXTMEM_0cf9 * '\x1f' + 0x37);
          *pbVar10 = param_2;
          pbVar10[1] = bVar5;
        }
      }
      else if (DAT_EXTMEM_0a11 == '\0') {
        pcVar12 = (char *)CONCAT11('\f' - (((200 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                                   DAT_EXTMEM_0cf9 * '\x1f' + 0x37);
        *pcVar12 = DAT_EXTMEM_0c33;
        pcVar12[1] = bVar5;
      }
      else {
        puVar11 = (undefined1 *)
                  CONCAT11('\f' - (((200 < DAT_EXTMEM_0cf9 * '\x1f') << 7) >> 7),
                           DAT_EXTMEM_0cf9 * '\x1f' + 0x37);
        *puVar11 = 0;
        puVar11[1] = cVar7;
      }
    }
    DAT_EXTMEM_0cf8 = 1;
  }
  else if (DAT_EXTMEM_0cf4 == '\x01') {
    DAT_EXTMEM_0cf8 = 0xff;
  }
  else {
    DAT_EXTMEM_0cf8 = 0xfe;
  }
  return DAT_EXTMEM_0cf8;
}



// ==== FUN_CODE_40e7 @ CODE:40e7  (673 bytes)

void FUN_CODE_40e7(byte param_1,char param_2)

{
  char cVar1;
  byte bVar2;
  
  FUN_CODE_74f3(0xcfd);
  FUN_CODE_2ced();
  FUN_CODE_74ea(0xd00);
  FUN_CODE_7e3e();
  DAT_EXTMEM_0d06 = param_1;
  DAT_EXTMEM_0d07 = param_2;
  FUN_CODE_74ea(0xcfd);
  FUN_CODE_7e3e();
  DAT_EXTMEM_0d04 = param_1;
  DAT_EXTMEM_0d05 = param_2;
  FUN_CODE_6e00(0x2c,0xc,1,DAT_EXTMEM_0d06,DAT_EXTMEM_0d07);
  if (param_2 == '\0' && param_1 == 0) {
    cVar1 = ((DAT_EXTMEM_0d05 == '\0') << 7) >> 7;
    if ((DAT_EXTMEM_0d04 < (byte)-cVar1) << 7 < '\0') {
      DAT_EXTMEM_0c2c = 0;
    }
    else {
      FUN_CODE_74f3(DAT_EXTMEM_0d04 + cVar1,0xf4b,0xcb,0x5b,0xff);
      DAT_EXTMEM_0f4e = DAT_EXTMEM_0d04;
      DAT_EXTMEM_0f4f = DAT_EXTMEM_0d05;
      FUN_CODE_7af8(0x2c,0xc,1);
      DAT_EXTMEM_0c30 = 0;
    }
  }
  FUN_CODE_74f3(0xee6,0x26,0xc,1);
  FUN_CODE_74f3(0xee9,0x28,0xc);
  cVar1 = '*';
  FUN_CODE_74f3(0xeec,0x2a,0xc);
  FUN_CODE_74f3(0xeef,cVar1 + '\x01',0xc);
  FUN_CODE_74f3(0xef2,8,0xd);
  FUN_CODE_74f3(0xef5,10,0xd);
  bVar2 = DAT_EXTMEM_0d03;
  FUN_CODE_6a14(0x2c,0xc,0,0);
  if ((bVar2 != 0 || param_1 != 0) && (FUN_CODE_7e3e(0x2c,0xc,1), bVar2 != 0 || param_1 != 0)) {
    FUN_CODE_2ced();
    DAT_EXTMEM_0c33 = DAT_EXTMEM_0d08;
    DAT_EXTMEM_0c34 = DAT_EXTMEM_0d09;
    DAT_EXTMEM_0c35 = DAT_EXTMEM_0d0a;
    DAT_EXTMEM_0c36 = DAT_EXTMEM_0d0b;
    return;
  }
  if ((DAT_EXTMEM_0a11 == '\0') || (DAT_EXTMEM_0a13 == 0)) {
    if ((DAT_EXTMEM_0a11 == '\0') && ((DAT_EXTMEM_0a13 < 0x32) << 7 < '\0')) {
      DAT_EXTMEM_0ed0 = DAT_EXTMEM_0c2b;
      FUN_CODE_65e9(0x2c,0xc,1,DAT_EXTMEM_0c2a);
      DAT_EXTMEM_0d0d = param_1;
      DAT_EXTMEM_0d0e = bVar2;
      if (0x80U - (((bVar2 < DAT_EXTMEM_0a13 + 1) << 7) >> 7) <= (param_1 ^ 0x80)) {
        DAT_EXTMEM_0d0c =
             *(undefined1 *)
              CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0d03) << 7) >> 7),DAT_EXTMEM_0d03 - 0x3f);
        *(undefined1 *)
         CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0d03) << 7) >> 7),DAT_EXTMEM_0d03 - 0x3f) = 0xc;
        FUN_CODE_74f3(0xee6,0x26,0xc,1);
        FUN_CODE_74f3(0xee9,0x28,0xc);
        cVar1 = '*';
        FUN_CODE_74f3(0xeec,0x2a,0xc);
        FUN_CODE_74f3(0xeef,cVar1 + '\x01',0xc);
        FUN_CODE_74f3(0xef2,8,0xd);
        FUN_CODE_74f3(0xef5,10,0xd);
        FUN_CODE_6a14(0x2c,0xc,0,0);
        *(undefined1 *)
         CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0d03) << 7) >> 7),DAT_EXTMEM_0d03 - 0x3f) =
             DAT_EXTMEM_0d0c;
      }
    }
  }
  else {
    DAT_EXTMEM_0ed0 = DAT_EXTMEM_0c2b;
    FUN_CODE_65e9(0x2c,0xc,1,DAT_EXTMEM_0c2a);
    DAT_EXTMEM_0d0d = param_1;
    DAT_EXTMEM_0d0e = bVar2;
    if (0x80U - (((bVar2 < DAT_EXTMEM_0a11 + 1U) << 7) >> 7) <= (param_1 ^ 0x80)) {
      DAT_EXTMEM_0d0c =
           *(undefined1 *)
            CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0d03) << 7) >> 7),DAT_EXTMEM_0d03 - 0x3f);
      *(undefined1 *)
       CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0d03) << 7) >> 7),DAT_EXTMEM_0d03 - 0x3f) = 0xc;
      FUN_CODE_74f3(0xee6,0x26,0xc,1);
      FUN_CODE_74f3(0xee9,0x28,0xc);
      cVar1 = '*';
      FUN_CODE_74f3(0xeec,0x2a,0xc);
      FUN_CODE_74f3(0xeef,cVar1 + '\x01',0xc);
      FUN_CODE_74f3(0xef2,8,0xd);
      FUN_CODE_74f3(0xef5,10,0xd);
      FUN_CODE_6a14(0x2c,0xc,0,0);
      *(undefined1 *)
       CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0d03) << 7) >> 7),DAT_EXTMEM_0d03 - 0x3f) =
           DAT_EXTMEM_0d0c;
    }
  }
  DAT_EXTMEM_0c33 = DAT_EXTMEM_0d08;
  DAT_EXTMEM_0c34 = DAT_EXTMEM_0d09;
  DAT_EXTMEM_0c35 = DAT_EXTMEM_0d0a;
  DAT_EXTMEM_0c36 = DAT_EXTMEM_0d0b;
  return;
}



// ==== FUN_CODE_4388 @ CODE:4388  (6189 bytes)

void FUN_CODE_4388(char param_1)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  undefined1 uVar10;
  
  FUN_CODE_74f3(0xd0f);
  DAT_EXTMEM_0d15 = 0;
  DAT_EXTMEM_0d16 = 0;
  bVar4 = 1;
  cVar3 = '\r';
  bVar2 = 0x17;
  DAT_EXTMEM_0d12 = param_1;
  FUN_CODE_79b6(0x17,0xd,1,0,DAT_EXTMEM_0d13,DAT_EXTMEM_0d14);
  while( true ) {
    FUN_CODE_74ea(0xd0f);
    bVar9 = DAT_EXTMEM_0d15;
    cVar6 = FUN_CODE_7385(DAT_EXTMEM_0d15);
    if ((cVar6 == '\0') ||
       (cVar6 = DAT_EXTMEM_0d13 - (((bVar9 < DAT_EXTMEM_0d14) << 7) >> 7), cVar6 == '\0')) break;
    while( true ) {
      FUN_CODE_74ea(-cVar6,0xd0f);
      cVar6 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      if ((((cVar6 != ' ') &&
           ((((cVar6 != '/' && (cVar6 != '-')) && (cVar6 != '(')) &&
            ((cVar6 != ')' && (cVar6 != '.')))))) && (cVar6 != ',')) && (cVar6 != '\n')) break;
      *(char *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) =
           cVar6;
      DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
      DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
      cVar6 = DAT_EXTMEM_0d13 - (((DAT_EXTMEM_0d16 < DAT_EXTMEM_0d14) << 7) >> 7);
      if (cVar6 == '\0') {
        *(undefined1 *)
         CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d14) << 7) >> 7),DAT_EXTMEM_0d14 + 0x17) = 0;
        uVar10 = FUN_CODE_74ea(0xd0f);
        FUN_CODE_77ea(uVar10,bVar2,0x17,0xd,1,cVar3,bVar4);
        return;
      }
    }
    FUN_CODE_74ea(0xd0f);
    bVar9 = DAT_EXTMEM_0d15;
    cVar6 = FUN_CODE_7385(DAT_EXTMEM_0d15);
    if ((cVar6 == '\0') ||
       (cVar3 = DAT_EXTMEM_0d13, bVar4 = DAT_EXTMEM_0d14,
       DAT_EXTMEM_0d13 == ((bVar9 < DAT_EXTMEM_0d14) << 7) >> 7)) break;
    if (DAT_EXTMEM_0d12 != '\0') {
      DAT_EXTMEM_0d12 = '\0';
    }
    if (cVar6 == 'A') {
      cVar5 = '\0';
      uVar10 = 0xfe < DAT_EXTMEM_0d15;
      cVar6 = DAT_EXTMEM_0d15 + 1;
      bVar9 = DAT_EXTMEM_0d15;
      FUN_CODE_74ea(0xd0f,uVar10,cVar6);
      cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
      if ((cVar6 != 'M') ||
         ((cVar6 = FUN_CODE_7385(CONCAT11(cVar5 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 != ' ' &&
          (cVar6 != '\0')))) goto LAB_CODE_44ec;
      *(undefined1 *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17)
           = 0x61;
      DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
      DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
    }
    else {
LAB_CODE_44ec:
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x41;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'N') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x61;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x41;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'B') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x61;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x41;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'U') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'F')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x61;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x42;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'E') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'I')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x62;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x42;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'E') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'I')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'M') &&
             ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == ' ' ||
              (cVar6 == '\0')))) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x62;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'A') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'S')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 100;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'E') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'M')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 100;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'E') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'N')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 100;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'E') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'R')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 100;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'E') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'S')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 100;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'I') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'E')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 100;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x49;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'M') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x69;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x49;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'N') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x69;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x4e;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == '.') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x6e;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x4e;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'A') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'C')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'H') &&
             ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == ' ' ||
              (cVar6 == '\0')))) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x6e;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x9a;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == '.') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x81;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x9a;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'B') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'E')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'R') &&
             ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == ' ' ||
              (cVar6 == '\0')))) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x81;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x55;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'M') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x75;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x55;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'N') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'D')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x75;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x55;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'N') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'T')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'E') &&
             (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == 'R')) {
            cVar6 = DAT_EXTMEM_0d15 + 5;
            bVar9 = bVar7 << 1 | 0xfa < DAT_EXTMEM_0d15;
            FUN_CODE_74ea(0xd0f,bVar9,cVar6);
            cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
            if ((cVar6 == ' ') || (cVar6 == '\0')) {
              *(undefined1 *)
               CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x75
              ;
              DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              goto LAB_CODE_5a4e;
            }
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x56;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'O') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'M')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x76;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x56;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'O') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'N')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x76;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x56;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'O') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'R')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x76;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x5a;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'U') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x7a;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x5a;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'U') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'E')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'R') &&
             (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == 'S')) {
            cVar6 = DAT_EXTMEM_0d15 + 5;
            bVar8 = bVar7 << 1 | 0xfa < DAT_EXTMEM_0d15;
            bVar9 = DAT_EXTMEM_0d15;
            FUN_CODE_74ea(0xd0f,bVar8,cVar6);
            cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
            if ((cVar6 == 'T') &&
               ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xf9 < bVar9,bVar9 + 6)), cVar6 == ' '
                || (cVar6 == '\0')))) {
              *(undefined1 *)
               CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x7a
              ;
              DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              goto LAB_CODE_5a4e;
            }
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x5a;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'U') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'M')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x7a;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x5a;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'U') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'R')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            *(undefined1 *)
             CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x7a;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x41;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'G') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          bVar1 = 0xe8 < DAT_EXTMEM_0d16;
          cVar6 = DAT_EXTMEM_0d16 + 0x17;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x41;
          bVar1 = 0xe8 < DAT_EXTMEM_0d16;
          cVar6 = DAT_EXTMEM_0d16 + 0x17;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x47;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 2;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x42;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'F') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == '.')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x46;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x2e;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 3;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x42;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'T') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'F')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == '.') &&
             ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == ' ' ||
              (cVar6 == '\0')))) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x54;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x46;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x2e;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 4;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x42;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'U') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'S')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x55;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x53;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 3;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'B') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          bVar1 = 0xe8 < DAT_EXTMEM_0d16;
          cVar6 = DAT_EXTMEM_0d16 + 0x17;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x44;
          bVar1 = 0xe8 < DAT_EXTMEM_0d16;
          cVar6 = DAT_EXTMEM_0d16 + 0x17;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 2;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x44;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'V') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'B')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x44;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x56;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 3;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x48;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'B') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'F')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x48;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x46;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 3;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x48;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'B') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'F')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == '.') &&
             ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == ' ' ||
              (cVar6 == '\0')))) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x48;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x46;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x2e;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 4;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x52;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'V') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'D')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar9 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar9,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
          if ((cVar6 == ' ') || (cVar6 == '\0')) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x52;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x56;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x44;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 3;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x53;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'B') &&
           ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == ' ' ||
            (cVar6 == '\0')))) {
          bVar1 = 0xe8 < DAT_EXTMEM_0d16;
          cVar6 = DAT_EXTMEM_0d16 + 0x17;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x53;
          bVar1 = 0xe8 < DAT_EXTMEM_0d16;
          cVar6 = DAT_EXTMEM_0d16 + 0x17;
          DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
          *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
          DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 2;
          goto LAB_CODE_5a4e;
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x53;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'T') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'R')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'A') &&
             (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == 'B')) {
            cVar6 = DAT_EXTMEM_0d15 + 5;
            bVar9 = bVar7 << 1 | 0xfa < DAT_EXTMEM_0d15;
            FUN_CODE_74ea(0xd0f,bVar9,cVar6);
            cVar6 = FUN_CODE_7385(CONCAT11(bVar9,cVar6));
            if ((cVar6 == ' ') || (cVar6 == '\0')) {
              bVar1 = 0xe8 < DAT_EXTMEM_0d16;
              cVar6 = DAT_EXTMEM_0d16 + 0x17;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x53;
              bVar1 = 0xe8 < DAT_EXTMEM_0d16;
              cVar6 = DAT_EXTMEM_0d16 + 0x17;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x54;
              bVar1 = 0xe8 < DAT_EXTMEM_0d16;
              cVar6 = DAT_EXTMEM_0d16 + 0x17;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x52;
              bVar1 = 0xe8 < DAT_EXTMEM_0d16;
              cVar6 = DAT_EXTMEM_0d16 + 0x17;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x41;
              bVar1 = 0xe8 < DAT_EXTMEM_0d16;
              cVar6 = DAT_EXTMEM_0d16 + 0x17;
              DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
              *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x42;
              DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 5;
              goto LAB_CODE_5a4e;
            }
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      bVar9 = DAT_EXTMEM_0d15;
      bVar7 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      bVar7 = bVar7 ^ 0x54;
      if (bVar7 == 0) {
        uVar10 = 0xfe < bVar9;
        cVar6 = bVar9 + 1;
        FUN_CODE_74ea(0xd0f,uVar10,cVar6);
        cVar6 = FUN_CODE_7385(CONCAT11(uVar10,cVar6));
        if ((cVar6 == 'R') &&
           (cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfd < bVar9,bVar9 + 2)), cVar6 == 'A')) {
          cVar6 = DAT_EXTMEM_0d15 + 3;
          bVar8 = bVar7 << 1 | 0xfc < DAT_EXTMEM_0d15;
          bVar9 = DAT_EXTMEM_0d15;
          FUN_CODE_74ea(0xd0f,bVar8,cVar6);
          cVar6 = FUN_CODE_7385(CONCAT11(bVar8,cVar6));
          if ((cVar6 == 'M') &&
             ((cVar6 = FUN_CODE_7385(CONCAT11(bVar7 << 1 | 0xfb < bVar9,bVar9 + 4)), cVar6 == ' ' ||
              (cVar6 == '\0')))) {
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x54;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x52;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x41;
            bVar1 = 0xe8 < DAT_EXTMEM_0d16;
            cVar6 = DAT_EXTMEM_0d16 + 0x17;
            DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
            *(undefined1 *)CONCAT11('\r' - ((bVar1 << 7) >> 7),cVar6) = 0x4d;
            DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 4;
            goto LAB_CODE_5a4e;
          }
        }
      }
      FUN_CODE_74ea(0xd0f);
      uVar10 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      *(undefined1 *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17)
           = uVar10;
      DAT_EXTMEM_0d15 = DAT_EXTMEM_0d15 + 1;
      DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
    }
LAB_CODE_5a4e:
    cVar6 = DAT_EXTMEM_0d13 - (((DAT_EXTMEM_0d16 < DAT_EXTMEM_0d14) << 7) >> 7);
    bVar9 = -cVar6;
    if (cVar6 == '\0') {
      *(undefined1 *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d14) << 7) >> 7),DAT_EXTMEM_0d14 + 0x17)
           = 0;
      uVar10 = FUN_CODE_74ea(0xd0f);
      FUN_CODE_77ea(uVar10,bVar2,0x17,0xd,1,cVar3,bVar4);
      return;
    }
    while( true ) {
      FUN_CODE_74ea(bVar9,0xd0f);
      bVar2 = FUN_CODE_7385(DAT_EXTMEM_0d15);
      if ((((bVar2 == 0x20) || (bVar2 == 0x2f)) || (bVar2 == 0x2d)) ||
         (((bVar2 == 0x28 || (bVar2 == 0x2c)) ||
          ((bVar2 == 0x2e || ((bVar2 == 0 || (bVar2 == 10)))))))) break;
      if (((bVar2 < 0x41) << 7 < '\0') || (0x5a < bVar2)) {
        if (bVar2 == 0x8e) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x84;
        }
        else if (bVar2 == 0x99) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x94;
        }
        else if (bVar2 == 0x9a) {
          *(undefined1 *)
           CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) = 0x81;
        }
        else {
          *(byte *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) =
               bVar2;
        }
      }
      else {
        *(byte *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d16) << 7) >> 7),DAT_EXTMEM_0d16 + 0x17) =
             bVar2 + 0x20;
      }
      DAT_EXTMEM_0d16 = DAT_EXTMEM_0d16 + 1;
      if (DAT_EXTMEM_0d13 == ((DAT_EXTMEM_0d16 < DAT_EXTMEM_0d14) << 7) >> 7) {
        *(undefined1 *)
         CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d14) << 7) >> 7),DAT_EXTMEM_0d14 + 0x17) = 0;
        uVar10 = FUN_CODE_74ea(0xd0f);
        FUN_CODE_77ea(uVar10,bVar2,0x17,0xd,1,cVar3,bVar4);
        return;
      }
      bVar9 = DAT_EXTMEM_0d15 + 1;
      DAT_EXTMEM_0d15 = bVar9;
    }
  }
  *(undefined1 *)CONCAT11('\r' - (((0xe8 < DAT_EXTMEM_0d14) << 7) >> 7),DAT_EXTMEM_0d14 + 0x17) = 0;
  uVar10 = FUN_CODE_74ea(0xd0f);
  FUN_CODE_77ea(uVar10,bVar2,0x17,0xd,1,cVar3,bVar4);
  return;
}



// ==== FUN_CODE_65e9 @ CODE:65e9  (396 bytes)

char FUN_CODE_65e9(char param_1,char param_2,char param_3,undefined1 param_4,byte param_5,
                  byte param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined2 uVar7;
  
  FUN_CODE_74f3(0xecc);
  DAT_EXTMEM_0ed7 = 0;
  DAT_EXTMEM_0ed8 = '\0';
  DAT_EXTMEM_0ecf = param_4;
  FUN_CODE_74ea(0xecc);
  FUN_CODE_7e29();
  uVar7 = 0x82b;
  DAT_EXTMEM_0ed3 = param_5;
  DAT_EXTMEM_0ed4 = param_6;
  FUN_CODE_74de(DAT_EXTMEM_0ecf,0xd);
  DAT_EXTMEM_0ed6 = (undefined1)uVar7;
  DAT_EXTMEM_0ed5 = (undefined1)((ushort)uVar7 >> 8);
  FUN_CODE_74ea(uVar7);
  if ((param_1 == '\0' && param_2 == '\0') && param_3 == '\0') {
    DAT_EXTMEM_0ed5 = 8;
    DAT_EXTMEM_0ed6 = 0x2b;
  }
  DAT_EXTMEM_0ed2 = 0;
  while( true ) {
    cVar5 = DAT_EXTMEM_0ed3 - (((DAT_EXTMEM_0ed2 < DAT_EXTMEM_0ed4) << 7) >> 7);
    if (cVar5 == '\0') {
      return DAT_EXTMEM_0ed8;
    }
    FUN_CODE_74ea(-cVar5,0xecc);
    bVar3 = FUN_CODE_7385(DAT_EXTMEM_0ed2);
    uVar1 = DAT_EXTMEM_0ed5;
    uVar2 = DAT_EXTMEM_0ed6;
    FUN_CODE_74ea(CONCAT11(DAT_EXTMEM_0ed5,DAT_EXTMEM_0ed6),DAT_EXTMEM_0ed6);
    bVar4 = FUN_CODE_7385(0xf);
    if ((bVar3 < bVar4) << 7 < '\0') {
      return bVar3 - bVar4;
    }
    FUN_CODE_74ea(bVar3 - bVar4,0xecc);
    bVar3 = FUN_CODE_7385(DAT_EXTMEM_0ed2);
    FUN_CODE_74ea(CONCAT11(uVar1,uVar2));
    cVar5 = FUN_CODE_7385(0x10);
    cVar6 = bVar3 - (cVar5 + 1U);
    if (cVar5 + 1U <= bVar3) {
      return cVar6;
    }
    FUN_CODE_74ea(cVar6,0xecc);
    cVar5 = FUN_CODE_7385(DAT_EXTMEM_0ed2);
    FUN_CODE_74ea(CONCAT11(DAT_EXTMEM_0ed5,DAT_EXTMEM_0ed6));
    cVar6 = FUN_CODE_7385(0xf);
    bVar3 = cVar5 - cVar6;
    FUN_CODE_74ea(CONCAT11(DAT_EXTMEM_0ed5,DAT_EXTMEM_0ed6) + 3);
    cVar5 = FUN_CODE_7385((ushort)bVar3 * 3);
    if (cVar5 == '\0') break;
    FUN_CODE_7430(0,0xed7,cVar5);
    DAT_EXTMEM_0ed1 = DAT_EXTMEM_0ed0;
    if (DAT_CODE_5f36 != 0) {
      bVar3 = DAT_CODE_5f36;
      FUN_CODE_74ea(0xecc);
      bVar4 = FUN_CODE_7385(DAT_EXTMEM_0ed2);
      if (bVar3 <= bVar4) {
        DAT_EXTMEM_0ed1 = 0;
      }
    }
    if ((byte)-(((DAT_EXTMEM_0ed4 < 2) << 7) >> 7) <= DAT_EXTMEM_0ed3) {
      bVar3 = DAT_EXTMEM_0ed2 ^ DAT_EXTMEM_0ed4 - 1;
      if (bVar3 == 0) {
        bVar3 = DAT_EXTMEM_0ed3 + (-1 - (((DAT_EXTMEM_0ed4 != 0) << 7) >> 7));
      }
      if (bVar3 != 0) {
        FUN_CODE_7430(0,0xed7,DAT_EXTMEM_0ed1);
      }
    }
    DAT_EXTMEM_0ed2 = DAT_EXTMEM_0ed2 + 1;
  }
  return '\0';
}



// ==== FUN_CODE_6775 @ CODE:6775  (26 bytes)

void FUN_CODE_6775(byte param_1)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)param_1 * 0xd);
  FUN_CODE_74fc(bVar1 + 0x2b,
                ((char)((ushort)param_1 * 0xd >> 8) - (((0xd4 < bVar1) << 7) >> 7)) + '\b',1);
  FUN_CODE_7385(0xe);
  return;
}



// ==== FUN_CODE_678f @ CODE:678f  (108 bytes)

char FUN_CODE_678f(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  FUN_CODE_74f3(0xed9);
  cVar1 = '\0';
  while( true ) {
    FUN_CODE_74ea(0xed9);
    cVar2 = FUN_CODE_7385(cVar1);
    cVar3 = '\0';
    if ((((cVar2 == '\n') || (cVar3 = '\0', cVar2 == '\r')) || (cVar3 = '\0', cVar2 == '\0')) ||
       (cVar3 = cVar1 + '\x01', cVar1 == -1)) {
      return cVar3;
    }
    cVar3 = '\0';
    if (((((cVar2 == 'g') || (cVar3 = '\0', cVar2 == 'j')) ||
         ((cVar3 = '\0', cVar2 == 'p' ||
          ((cVar3 = '\0', cVar2 == 'q' || (cVar3 = '\0', cVar2 == 'y')))))) ||
        (cVar3 = '\0', cVar2 == '#')) ||
       ((((cVar3 = '\0', cVar2 == '$' || (cVar3 = '\0', cVar2 == '%')) ||
         (cVar3 = '\0', cVar2 == ';')) ||
        ((cVar3 = '\0', cVar2 == '?' || (cVar3 = cVar2, cVar2 == '@')))))) break;
    cVar1 = cVar1 + '\x01';
  }
  return cVar3;
}



// ==== FUN_CODE_67fb @ CODE:67fb  (537 bytes)

void FUN_CODE_67fb(char param_1,byte param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  
  FUN_CODE_74f3(0xedc);
  if (param_1 == '\0') {
    DAT_EXTMEM_0edf = 0;
    while( true ) {
      FUN_CODE_74ea(0xedc);
      FUN_CODE_7e29();
      bVar1 = (param_2 ^ 0x80) - (((DAT_EXTMEM_0edf < param_3) << 7) >> 7);
      if (bVar1 < 0x81) break;
      FUN_CODE_74ea(-0x80 - bVar1,0xedc);
      param_3 = DAT_EXTMEM_0edf;
      param_2 = FUN_CODE_7385(DAT_EXTMEM_0edf);
      if (param_2 == 0x99) {
        FUN_CODE_74ea(0xedc);
        FUN_CODE_73c4(0x5c,param_3);
      }
      else if (param_2 == 0x94) {
        FUN_CODE_74ea(0xedc);
        FUN_CODE_73c4(0x7c,param_3);
      }
      else if (param_2 == 0x8e) {
        FUN_CODE_74ea(0xedc);
        FUN_CODE_73c4(0x5b,DAT_EXTMEM_0edf);
      }
      else {
        FUN_CODE_74ea(0xedc);
        param_3 = DAT_EXTMEM_0edf;
        param_2 = FUN_CODE_7385(DAT_EXTMEM_0edf);
        if (param_2 == 0x84) {
          FUN_CODE_74ea(0xedc);
          FUN_CODE_73c4(0x7b,param_3);
        }
        else if (param_2 == 0x9a) {
          FUN_CODE_74ea(0xedc);
          FUN_CODE_73c4(0x5d,param_3);
        }
        else if (param_2 == 0x81) {
          FUN_CODE_74ea(0xedc);
          FUN_CODE_73c4(0x7d,DAT_EXTMEM_0edf);
        }
        else {
          FUN_CODE_74ea(0xedc);
          param_3 = DAT_EXTMEM_0edf;
          cVar2 = FUN_CODE_7385(DAT_EXTMEM_0edf);
          if (cVar2 == -0x1f) {
            FUN_CODE_74ea(0xedc);
            FUN_CODE_73c4(0x7e,param_3);
          }
        }
      }
      DAT_EXTMEM_0edf = DAT_EXTMEM_0edf + 1;
    }
  }
  else {
    DAT_EXTMEM_0edf = 0;
    while( true ) {
      FUN_CODE_74ea(0xedc);
      FUN_CODE_7e29();
      bVar1 = (param_2 ^ 0x80) - (((DAT_EXTMEM_0edf < param_3) << 7) >> 7);
      if (bVar1 < 0x81) break;
      FUN_CODE_74ea(-0x80 - bVar1,0xedc);
      param_3 = DAT_EXTMEM_0edf;
      param_2 = FUN_CODE_7385(DAT_EXTMEM_0edf);
      if (param_2 == 0x5c) {
        FUN_CODE_74ea(0xedc);
        FUN_CODE_73c4(0x99,param_3);
      }
      else if (param_2 == 0x7c) {
        FUN_CODE_74ea(0xedc);
        FUN_CODE_73c4(0x94,param_3);
      }
      else if (param_2 == 0x5b) {
        FUN_CODE_74ea(0xedc);
        FUN_CODE_73c4(0x8e,DAT_EXTMEM_0edf);
      }
      else {
        FUN_CODE_74ea(0xedc);
        param_3 = DAT_EXTMEM_0edf;
        param_2 = FUN_CODE_7385(DAT_EXTMEM_0edf);
        if (param_2 == 0x7b) {
          FUN_CODE_74ea(0xedc);
          FUN_CODE_73c4(0x84,param_3);
        }
        else if (param_2 == 0x5d) {
          FUN_CODE_74ea(0xedc);
          FUN_CODE_73c4(0x9a,param_3);
        }
        else if (param_2 == 0x7d) {
          FUN_CODE_74ea(0xedc);
          FUN_CODE_73c4(0x81,DAT_EXTMEM_0edf);
        }
        else {
          FUN_CODE_74ea(0xedc);
          param_3 = DAT_EXTMEM_0edf;
          cVar2 = FUN_CODE_7385(DAT_EXTMEM_0edf);
          if (cVar2 == '~') {
            FUN_CODE_74ea(0xedc);
            FUN_CODE_73c4(0xe1,param_3);
          }
        }
      }
      DAT_EXTMEM_0edf = DAT_EXTMEM_0edf + 1;
    }
  }
  return;
}



// ==== FUN_CODE_6a14 @ CODE:6a14  (1004 bytes)

undefined1 FUN_CODE_6a14(byte param_1,byte param_2,byte param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  undefined2 uVar9;
  
  DAT_EXTMEM_0ee0 = param_3;
  DAT_EXTMEM_0ee1 = param_1;
  DAT_EXTMEM_0ee2 = param_2;
  FUN_CODE_74f3(0xee3);
  DAT_EXTMEM_0f10 = 0xff;
  DAT_EXTMEM_0f11 = 0xff;
  FUN_CODE_74ea(0xee9);
  FUN_CODE_74bf(0);
  FUN_CODE_74ea(0xee6);
  FUN_CODE_74bf(0);
  FUN_CODE_74ea(0xeec);
  FUN_CODE_73b2(0);
  FUN_CODE_74ea(0xeef);
  FUN_CODE_73b2(0);
  FUN_CODE_74ea(0xef2);
  FUN_CODE_74bf(0);
  bVar6 = DAT_EXTMEM_0a1b;
  FUN_CODE_74ea(0xef5,DAT_EXTMEM_0a1b);
  FUN_CODE_74bf(0,bVar6);
  bVar6 = DAT_EXTMEM_0ee1;
  bVar7 = DAT_EXTMEM_0ee2;
  if (DAT_EXTMEM_0ee2 == 0 && DAT_EXTMEM_0ee1 == 0) {
    FUN_CODE_74ea(0xee3);
    cVar3 = FUN_CODE_736c();
    if (cVar3 == '\0') goto LAB_CODE_6a97;
  }
  if (bVar7 != 0 || bVar6 != 0) {
    FUN_CODE_74ea(0xee3);
    cVar3 = FUN_CODE_736c();
    if (cVar3 != '\0') {
LAB_CODE_6a97:
      uVar4 = 0;
      if (DAT_EXTMEM_0a11 != 0) {
        bVar6 = DAT_EXTMEM_0a11;
        FUN_CODE_74ea(0xef2,DAT_EXTMEM_0a11);
        FUN_CODE_74bf(0,bVar6);
        bVar6 = DAT_EXTMEM_0a13;
        FUN_CODE_74ea(0xef5,DAT_EXTMEM_0a13);
        uVar4 = FUN_CODE_74bf(0,bVar6);
      }
      return uVar4;
    }
  }
  bVar6 = DAT_EXTMEM_0ee1;
  if (DAT_EXTMEM_0ee1 == 0) {
    bVar6 = DAT_EXTMEM_0ee2;
  }
  if (bVar6 != 0) {
    FUN_CODE_74ea(0xee3);
    cVar3 = FUN_CODE_736c();
    if (cVar3 == '\0') {
      FUN_CODE_74f3(0xf4b,0xc3,0x71,0xff);
      DAT_EXTMEM_0f4e = DAT_EXTMEM_0ee1;
      DAT_EXTMEM_0f4f = DAT_EXTMEM_0ee2;
      bVar7 = DAT_EXTMEM_0ee2;
      FUN_CODE_7af8(0xf9,0xe,1);
      goto LAB_CODE_6b0a;
    }
  }
  FUN_CODE_74ea(0xee3,0xf9,0xe,1);
  FUN_CODE_77ea();
LAB_CODE_6b0a:
  FUN_CODE_7e29(0xf9,0xe,1);
  DAT_EXTMEM_0f0d = bVar7;
  if (4 < bVar7) {
    DAT_EXTMEM_0f0d = 4;
  }
  uVar2 = 1;
  uVar1 = 0xe;
  uVar4 = 0xf9;
  uVar9 = 0x5f79;
  bVar6 = DAT_EXTMEM_0f0d;
  bVar7 = DAT_EXTMEM_0ee0;
  FUN_CODE_74de(DAT_EXTMEM_0ee0,5,0xf9,0xe,1,
                *(undefined1 *)
                 CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0ee0) << 7) >> 7),DAT_EXTMEM_0ee0 - 0x3f));
  DAT_EXTMEM_0ed0 =
       *(undefined1 *)
        CONCAT11((char)((ushort)uVar9 >> 8) - ((CARRY1((byte)uVar9,bVar6) << 7) >> 7),
                 (byte)uVar9 + bVar6);
  FUN_CODE_65e9();
  DAT_EXTMEM_0f0e = bVar6;
  DAT_EXTMEM_0f0f = bVar7;
  uVar5 = FUN_CODE_74ea(0xee3);
  FUN_CODE_77ea(uVar5,uVar4,0xf9,0xe,1,uVar1,uVar2);
  uVar9 = 0x5f79;
  bVar6 = DAT_EXTMEM_0f0d;
  FUN_CODE_74de(DAT_EXTMEM_0ee0,5);
  uVar4 = *(undefined1 *)
           CONCAT11((char)((ushort)uVar9 >> 8) - ((CARRY1((byte)uVar9,bVar6) << 7) >> 7),
                    (byte)uVar9 + bVar6);
  FUN_CODE_74ea(0xeef,uVar4);
  FUN_CODE_73b2(uVar4);
  uVar4 = *(undefined1 *)
           CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0ee0) << 7) >> 7),DAT_EXTMEM_0ee0 - 0x3f);
  FUN_CODE_74ea(0xeec,uVar4);
  FUN_CODE_73b2(uVar4);
  bVar6 = *(byte *)CONCAT11('\x0e' - (((0x3e < DAT_EXTMEM_0ee0) << 7) >> 7),DAT_EXTMEM_0ee0 - 0x3f);
  FUN_CODE_020f();
  DAT_EXTMEM_0ef8 = bVar6;
  cVar3 = (&DAT_CODE_5f37)[DAT_EXTMEM_0ee0];
  if (cVar3 == '\x01') {
    DAT_EXTMEM_0f10 = 0;
    DAT_EXTMEM_0f11 = 0;
    if (bVar6 < DAT_EXTMEM_0a22 + 1U) {
      bVar6 = DAT_EXTMEM_0a22 - bVar6 >> 1;
      FUN_CODE_74ea(0xee9,bVar6);
      FUN_CODE_74bf(0,bVar6);
    }
    else {
      FUN_CODE_74ea(bVar6 - (DAT_EXTMEM_0a22 + 1U),0xee9);
      FUN_CODE_74bf(0);
    }
    if (DAT_EXTMEM_0a11 == 0) {
      FUN_CODE_74ea(0xee6);
      FUN_CODE_74bf(0);
      bVar6 = DAT_EXTMEM_0f0e;
      bVar7 = DAT_EXTMEM_0f0f;
      FUN_CODE_74ea(0xef2,DAT_EXTMEM_0f0e,DAT_EXTMEM_0f0f);
      FUN_CODE_74bf(bVar6,bVar7);
      cVar8 = DAT_EXTMEM_0a1b - DAT_EXTMEM_0f0f;
      cVar3 = -(DAT_EXTMEM_0f0e - (((DAT_EXTMEM_0a1b < DAT_EXTMEM_0f0f) << 7) >> 7));
      FUN_CODE_74ea(0xef5,cVar3,cVar8);
      FUN_CODE_74bf(cVar3,cVar8);
    }
    else {
      bVar6 = DAT_EXTMEM_0a11;
      FUN_CODE_74ea(0xef2,DAT_EXTMEM_0a11);
      FUN_CODE_74bf(0,bVar6);
      bVar6 = DAT_EXTMEM_0a13;
      FUN_CODE_74ea(0xef5,DAT_EXTMEM_0a13);
      FUN_CODE_74bf(0,bVar6);
      bVar6 = 0x80 - (((DAT_EXTMEM_0f0f < DAT_EXTMEM_0a11 + 1) << 7) >> 7);
      if ((DAT_EXTMEM_0f0e ^ 0x80) < bVar6) {
        cVar3 = DAT_EXTMEM_0f0e - (((DAT_EXTMEM_0a11 < DAT_EXTMEM_0f0f) << 7) >> 7);
        bVar6 = -cVar3;
        bVar6 = bVar6 >> 1 | bVar6 & 0x80;
        bVar7 = DAT_EXTMEM_0a11 - DAT_EXTMEM_0f0f >> 1 | cVar3 * -0x80;
        FUN_CODE_74ea(0xee6,bVar6,bVar7);
        FUN_CODE_74bf(bVar6,bVar7);
      }
      else {
        FUN_CODE_74ea((DAT_EXTMEM_0f0e ^ 0x80) - bVar6,0xee6);
        FUN_CODE_74bf(0);
      }
    }
  }
  else if (cVar3 == '\x02') {
    DAT_EXTMEM_0f10 = 0;
    DAT_EXTMEM_0f11 = 0;
    if (DAT_EXTMEM_0a13 < 0x32) {
      bVar6 = 0x80 - (((DAT_EXTMEM_0f0f < DAT_EXTMEM_0a13 + 1) << 7) >> 7);
      if ((DAT_EXTMEM_0f0e ^ 0x80) < bVar6) {
        cVar3 = DAT_EXTMEM_0f0e - (((DAT_EXTMEM_0a13 < DAT_EXTMEM_0f0f) << 7) >> 7);
        bVar6 = -cVar3;
        bVar6 = bVar6 >> 1 | bVar6 & 0x80;
        bVar7 = DAT_EXTMEM_0a13 - DAT_EXTMEM_0f0f >> 1 | cVar3 * -0x80;
        FUN_CODE_74ea(0xee6,bVar6,bVar7);
        FUN_CODE_74bf(bVar6,bVar7);
      }
      else {
        FUN_CODE_74ea((DAT_EXTMEM_0f0e ^ 0x80) - bVar6,0xee6);
        FUN_CODE_74bf(0);
      }
    }
    else {
      uVar9 = 0x5f42;
      bVar6 = DAT_EXTMEM_0f0d;
      FUN_CODE_74de(DAT_EXTMEM_0ee0,5);
      uVar4 = *(undefined1 *)
               CONCAT11((char)((ushort)uVar9 >> 8) - ((CARRY1((byte)uVar9,bVar6) << 7) >> 7),
                        (byte)uVar9 + bVar6);
      FUN_CODE_74ea(0xee6,uVar4);
      FUN_CODE_74bf(0,uVar4);
    }
    if (DAT_EXTMEM_0ef8 < DAT_EXTMEM_0a23 + 1U) {
      bVar6 = DAT_EXTMEM_0a23 - DAT_EXTMEM_0ef8 >> 1;
      FUN_CODE_74ea(0xee9,bVar6);
      FUN_CODE_74bf(0,bVar6);
    }
    else {
      FUN_CODE_74ea(DAT_EXTMEM_0ef8 - (DAT_EXTMEM_0a23 + 1U),0xee9);
      FUN_CODE_74bf(0);
    }
    if (DAT_EXTMEM_0f0f == 0 && DAT_EXTMEM_0f0e == 0) {
      FUN_CODE_74ea(0xef2);
      cVar3 = '\0';
      FUN_CODE_74bf(0);
    }
    else {
      bVar7 = DAT_EXTMEM_0f0f + (&DAT_CODE_5fb1)[DAT_EXTMEM_0ee0];
      cVar8 = DAT_EXTMEM_0f0e -
              ((CARRY1(DAT_EXTMEM_0f0f,(&DAT_CODE_5fb1)[DAT_EXTMEM_0ee0]) << 7) >> 7);
      uVar9 = 0x5f42;
      bVar6 = DAT_EXTMEM_0f0d;
      FUN_CODE_74de(DAT_EXTMEM_0ee0,5,cVar8,bVar7);
      bVar6 = *(byte *)CONCAT11((char)((ushort)uVar9 >> 8) - ((CARRY1((byte)uVar9,bVar6) << 7) >> 7)
                                ,(byte)uVar9 + bVar6);
      cVar3 = bVar6 + bVar7;
      cVar8 = cVar8 - ((CARRY1(bVar6,bVar7) << 7) >> 7);
      FUN_CODE_74ea(0xef2,cVar8,cVar3);
      FUN_CODE_74bf(cVar8,cVar3);
    }
    FUN_CODE_74ea(0xef2);
    bVar6 = FUN_CODE_745c();
    cVar8 = DAT_EXTMEM_0a13 - bVar6;
    cVar3 = -(cVar3 - (((DAT_EXTMEM_0a13 < bVar6) << 7) >> 7));
    FUN_CODE_74ea(0xef5,cVar3,cVar8);
    FUN_CODE_74bf(cVar3,cVar8);
  }
  else if (cVar3 == '\0') {
    return 0;
  }
  return DAT_EXTMEM_0f11;
}



// ==== FUN_CODE_6e00 @ CODE:6e00  (963 bytes)

char FUN_CODE_6e00(undefined1 param_1,byte param_2,undefined1 param_3,undefined1 param_4)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  undefined1 uVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  
  DAT_EXTMEM_0f12 = param_3;
  DAT_EXTMEM_0f13 = param_4;
  DAT_EXTMEM_0f14 = param_1;
  DAT_EXTMEM_0f15 = param_2;
  FUN_CODE_74f3(0xf16);
  DAT_EXTMEM_0f46 = '\0';
  DAT_EXTMEM_0f47 = '\0';
  FUN_CODE_73b2();
  FUN_CODE_74f3(0xf4b,0xc3,0x71,0xff);
  DAT_EXTMEM_0f4e = DAT_EXTMEM_0f12;
  DAT_EXTMEM_0f4f = DAT_EXTMEM_0f13;
  FUN_CODE_7af8(0x1a,0xf,1);
  FUN_CODE_74f3(0xf4b,0xc3,0x71,0xff);
  DAT_EXTMEM_0f4e = DAT_EXTMEM_0f14;
  DAT_EXTMEM_0f4f = DAT_EXTMEM_0f15;
  cVar3 = '\x01';
  bVar2 = 0xf;
  bVar1 = 0x23;
  bVar9 = DAT_EXTMEM_0f15;
  FUN_CODE_7af8(0x23,0xf,1);
  if ((DAT_CODE_5fb0 == '\x03') || (DAT_CODE_5fb0 == '\x02')) {
    DAT_EXTMEM_0f44 = 0;
    DAT_EXTMEM_0f45 = 0;
    do {
      if (DAT_CODE_5fb0 == '\x02') {
        FUN_CODE_74f3(0xf38,0x1a,0xf,1);
        puVar12 = (undefined1 *)
                  CONCAT11('\r' - (((0xd0 < DAT_EXTMEM_0f45 * '\x04') << 7) >> 7),
                           DAT_EXTMEM_0f45 * '\x04' + 0x2f);
        cVar3 = -1;
        FUN_CODE_74f3(0xf3b,puVar12[1],*puVar12);
        pbVar13 = (byte *)CONCAT11('\r' - (((0xce < DAT_EXTMEM_0f45 * '\x04') << 7) >> 7),
                                   DAT_EXTMEM_0f45 * '\x04' + 0x31);
        bVar2 = *pbVar13;
        bVar1 = pbVar13[1];
        bVar8 = bVar2;
        FUN_CODE_74f3(0xf3e);
      }
      else {
        FUN_CODE_74f3(0xf38,0x23,0xf,1);
        cVar3 = '\x02';
        bVar2 = DAT_EXTMEM_0f44;
        bVar1 = DAT_EXTMEM_0f45;
        do {
          bVar8 = bVar1 * '\x02';
          bVar2 = bVar2 << 1 | bVar1 >> 7;
          cVar3 = cVar3 + -1;
          bVar1 = bVar8;
        } while (cVar3 != '\0');
        puVar12 = (undefined1 *)CONCAT11(bVar2 + ('\r' - (((0xca < bVar8) << 7) >> 7)),bVar8 + 0x35)
        ;
        FUN_CODE_74f3(0xf3b,puVar12[1],*puVar12,0xff);
        cVar3 = '\x02';
        bVar2 = DAT_EXTMEM_0f44;
        bVar1 = DAT_EXTMEM_0f45;
        do {
          bVar8 = bVar1 * '\x02';
          bVar2 = bVar2 << 1 | bVar1 >> 7;
          cVar3 = cVar3 + -1;
          bVar1 = bVar8;
        } while (cVar3 != '\0');
        pbVar13 = (byte *)CONCAT11(bVar2 + ('\r' - (((200 < bVar8) << 7) >> 7)),bVar8 + 0x37);
        bVar2 = *pbVar13;
        bVar1 = pbVar13[1];
        cVar3 = -1;
        bVar8 = bVar2;
        FUN_CODE_74f3(0xf3e);
      }
      FUN_CODE_74ea(0xf3b);
      if (((bVar1 != 0 || bVar2 != 0) || cVar3 != '\0') &&
         (FUN_CODE_74ea(0xf3e), (bVar1 != 0 || bVar2 != 0) || cVar3 != '\0')) {
        cVar3 = '\x01';
        bVar2 = 0xf;
        bVar1 = 0x1a;
        FUN_CODE_74f3(0xf41,0x1a,0xf,1);
        FUN_CODE_7e29();
        DAT_EXTMEM_0f35 = bVar9;
        FUN_CODE_74ea(0xf38);
        FUN_CODE_7e29();
        bVar4 = bVar8;
        bVar6 = bVar9;
        FUN_CODE_74ea(0xf3b);
        FUN_CODE_7e29();
        bVar6 = bVar6 ^ bVar9;
        if (bVar6 == 0) {
          bVar6 = bVar4 ^ bVar8;
        }
        if (bVar6 == 0) {
          cVar5 = '\0';
          bVar9 = 0;
          DAT_EXTMEM_0f37 = 0;
          while( true ) {
            FUN_CODE_74ea(0xf38);
            cVar7 = FUN_CODE_736c();
            if (cVar7 == '\0') break;
            FUN_CODE_74ea(0xf3b);
            cVar7 = FUN_CODE_736c();
            if ((cVar7 == 'x') || (cVar7 == 'X')) {
              bVar8 = 1;
              cVar7 = cVar5 + '\x01';
              while (cVar7 = cVar7 + -1, cVar7 != '\0') {
                bVar8 = bVar8 << 1;
              }
              bVar9 = bVar8 | bVar9;
            }
            else {
              FUN_CODE_74ea(0xf38);
              cVar7 = FUN_CODE_736c();
              FUN_CODE_74ea(0xf3b);
              cVar10 = FUN_CODE_736c();
              if (cVar10 == cVar7) {
                bVar8 = 1;
                cVar7 = cVar5 + '\x01';
                while (cVar7 = cVar7 + -1, cVar7 != '\0') {
                  bVar8 = bVar8 << 1;
                }
                bVar9 = bVar8 | bVar9;
              }
            }
            bVar8 = 1;
            cVar7 = cVar5 + '\x01';
            while (cVar7 = cVar7 + -1, cVar7 != '\0') {
              bVar8 = bVar8 << 1;
            }
            DAT_EXTMEM_0f37 = bVar8 | DAT_EXTMEM_0f37;
            cVar5 = cVar5 + '\x01';
            FUN_CODE_7430(0,0xf3c,1);
            FUN_CODE_7430(0,0xf39,1);
          }
          if (DAT_EXTMEM_0f37 == bVar9) {
            cVar3 = '\0';
            puVar12 = (undefined1 *)
                      CONCAT11('\r' - (((0xd0 < DAT_EXTMEM_0f45 * '\x04') << 7) >> 7),
                               DAT_EXTMEM_0f45 * '\x04' + 0x2f);
            FUN_CODE_74f3(0xf3b,puVar12[1],*puVar12,0xff);
            FUN_CODE_74f3(0xf41,0x1a,0xf,1);
            DAT_EXTMEM_0f36 = 0;
            FUN_CODE_79b6(0x2c,0xf,0,0,9);
            while( true ) {
              FUN_CODE_74ea(0xf3e);
              cVar5 = FUN_CODE_736c();
              if (cVar5 == '\0') break;
              if (cVar5 == '#') {
                FUN_CODE_7430(0,0xf3f,1);
                FUN_CODE_74ea(0xf3e);
                cVar5 = FUN_CODE_736c();
                if (cVar5 == '\0') break;
                FUN_CODE_7def();
                if (cVar3 < '\0') {
                  FUN_CODE_74ea(0xf3e);
                  cVar3 = FUN_CODE_736c();
                  DAT_EXTMEM_0f19 = cVar3 - 0x30;
                  if ((DAT_EXTMEM_0f19 < DAT_EXTMEM_0f35) << 7 < '\0') {
                    if (DAT_EXTMEM_0f19 == 1) {
                      cVar5 = DAT_EXTMEM_0f35 - 2;
                      cVar3 = (-1 - (((DAT_EXTMEM_0f35 != 0) << 7) >> 7)) +
                              (((DAT_EXTMEM_0f35 == 1) << 7) >> 7);
                      FUN_CODE_74ea(0xf41,cVar3,cVar5);
                      cVar3 = FUN_CODE_7385(CONCAT11(cVar3,cVar5));
                      if (cVar3 == '0') goto LAB_CODE_7149;
                    }
                    cVar5 = (DAT_EXTMEM_0f35 - 1) - DAT_EXTMEM_0f19;
                    cVar3 = (-1 - (((DAT_EXTMEM_0f35 != 0) << 7) >> 7)) +
                            (((DAT_EXTMEM_0f35 - 1 < DAT_EXTMEM_0f19) << 7) >> 7);
                    FUN_CODE_74ea(0xf41,cVar3,cVar5);
                    uVar11 = FUN_CODE_7385(CONCAT11(cVar3,cVar5));
                    *(undefined1 *)
                     CONCAT11('\x0f' - (((0xd3 < DAT_EXTMEM_0f36) << 7) >> 7),DAT_EXTMEM_0f36 + 0x2c
                             ) = uVar11;
                    DAT_EXTMEM_0f36 = DAT_EXTMEM_0f36 + 1;
                  }
                }
                else {
                  FUN_CODE_74ea(0xf3e);
                  cVar3 = FUN_CODE_736c();
                  if (cVar3 == '#') {
                    *(undefined1 *)
                     CONCAT11('\x0f' - (((0xd3 < DAT_EXTMEM_0f36) << 7) >> 7),DAT_EXTMEM_0f36 + 0x2c
                             ) = 0x23;
                    DAT_EXTMEM_0f36 = DAT_EXTMEM_0f36 + 1;
                  }
                }
              }
              else {
                *(char *)CONCAT11('\x0f' - (((0xd3 < DAT_EXTMEM_0f36) << 7) >> 7),
                                  DAT_EXTMEM_0f36 + 0x2c) = cVar5;
                DAT_EXTMEM_0f36 = DAT_EXTMEM_0f36 + 1;
              }
LAB_CODE_7149:
              cVar3 = (DAT_EXTMEM_0f36 < 10) << 7;
              if (DAT_EXTMEM_0f36 >= 10) {
                DAT_EXTMEM_0f36 = 9;
              }
              FUN_CODE_7430(0,0xf3f,1);
            }
            bVar9 = 0;
            cVar3 = '\x01';
            bVar2 = 0xf;
            bVar1 = 0x2c;
            FUN_CODE_77ea(0x1a,0x2c,0xf,1,0xf,1);
            DAT_EXTMEM_0f46 = '\0';
            DAT_EXTMEM_0f47 = '\x02';
          }
        }
      }
      FUN_CODE_7430(0,0xf44,1);
    } while (DAT_EXTMEM_0f44 < (byte)-(((DAT_EXTMEM_0f45 < 99) << 7) >> 7));
  }
  cVar5 = DAT_EXTMEM_0f46;
  if (DAT_EXTMEM_0f46 == '\0') {
    cVar5 = DAT_EXTMEM_0f47;
  }
  if (cVar5 != '\0') {
    uVar11 = FUN_CODE_74ea(0xf16);
    FUN_CODE_77ea(uVar11,bVar1,0x1a,0xf,1,bVar2,cVar3);
  }
  return DAT_EXTMEM_0f47;
}



// ==== FUN_CODE_71c6 @ CODE:71c6  (9 bytes)

void FUN_CODE_71c6(char param_1)

{
  param_1 = param_1 + '\x01';
  while (param_1 = param_1 + -1, param_1 != '\0') {
    nop();
    nop();
    nop();
  }
  return;
}



// ==== FUN_CODE_71cf @ CODE:71cf  (13 bytes)

void FUN_CODE_71cf(char param_1)

{
  param_1 = param_1 + '\x01';
  while (param_1 = param_1 + -1, param_1 != '\0') {
    nop();
    nop();
    nop();
    nop();
    nop();
    nop();
    nop();
  }
  return;
}



// ==== FUN_CODE_71dc @ CODE:71dc  (11 bytes)

byte FUN_CODE_71dc(byte param_1)

{
  char cVar1;
  
  cVar1 = P;
  if (cVar1 != '\0') {
    param_1 = param_1 & 1 ^ 1;
  }
  return param_1 & 1;
}



// ==== reset_entry @ CODE:71e7  (132 bytes)

void reset_entry(void)

{
  char cVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  puVar2 = &DAT_INTMEM_7f;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + -1;
  } while (puVar2 != (undefined1 *)0x0);
  SP = 0x39;
  pbVar7 = &DAT_CODE_17ca;
  while( true ) {
    bVar3 = 1;
    bVar5 = *pbVar7;
    if (bVar5 == 0) break;
    bVar6 = bVar5 & 0x3f;
    pbVar8 = pbVar7 + 1;
    if (bVar6 >> 5 != 0) {
      bVar3 = bVar5 & 0x1f;
      bVar6 = pbVar7[1];
      pbVar8 = pbVar7 + 2;
      if (bVar6 != 0) {
        bVar3 = bVar3 + 1;
      }
    }
    pbVar7 = pbVar8;
    cVar1 = CARRY1(bVar5 & 0xc0,bVar5 & 0xc0) << 7;
    if ((bVar5 & 0x40) == 0) {
      pbVar4 = (byte *)*pbVar7;
      pbVar7 = pbVar7 + 1;
      do {
        bVar3 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        if (cVar1 < '\0') {
          *(byte *)ZEXT12(pbVar4) = bVar3;
        }
        else {
          *pbVar4 = bVar3;
        }
        pbVar4 = pbVar4 + '\x01';
        bVar6 = bVar6 - 1;
      } while (bVar6 != 0);
    }
    else if (cVar1 < '\0') {
      do {
        bVar3 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        pbVar4 = (byte *)((bVar3 & 0x7f) >> 3 | 0x20);
        bVar5 = *(byte *)((ushort)((bVar3 & 7) + 0xc) + 0x721a);
        if ((char)bVar3 < '\0') {
          bVar5 = bVar5 | *pbVar4;
        }
        else {
          bVar5 = ~bVar5 & *pbVar4;
        }
        *pbVar4 = bVar5;
        bVar6 = bVar6 - 1;
      } while (bVar6 != 0);
    }
    else {
      pbVar8 = *(byte **)pbVar7;
      pbVar7 = pbVar7 + 2;
      do {
        do {
          bVar5 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          *pbVar8 = bVar5;
          pbVar8 = pbVar8 + 1;
          bVar6 = bVar6 - 1;
        } while (bVar6 != 0);
        bVar3 = bVar3 - 1;
      } while (bVar3 != 0);
    }
  }
  FUN_CODE_00a0();
  return;
}



// ==== FUN_CODE_7343 @ CODE:7343  (48 bytes)

char FUN_CODE_7343(undefined1 param_1,char param_2,char param_3,char param_4,char param_5)

{
  byte bVar1;
  char cVar2;
  
  if (((3 < param_3 + 2U) || (bVar1 = param_2 + 2, 3 < bVar1)) ||
     (bVar1 = (bVar1 * '\x02' | bVar1 >> 7) << 1 | (bVar1 & 0x7f) >> 6 | param_3 + 2U,
     param_5 == '\0' && param_4 == '\0')) {
    return param_3;
  }
  if (param_5 != '\0') {
    param_4 = param_4 + '\x01';
  }
                    /* WARNING: Could not recover jumptable at 0x736b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  cVar2 = (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x72c3))(param_1,param_4);
  return cVar2;
}



// ==== FUN_CODE_736c @ CODE:736c  (25 bytes)

undefined1 FUN_CODE_736c(undefined1 *param_1,undefined1 param_2,char param_3)

{
  if (param_3 == '\x01') {
    return *(undefined1 *)CONCAT11(param_2,param_1);
  }
  if (param_3 == '\0') {
    return *param_1;
  }
  if (param_3 == -2) {
    return *(undefined1 *)ZEXT12(param_1);
  }
  return *(undefined1 *)CONCAT11(param_2,param_1);
}



// ==== FUN_CODE_7385 @ CODE:7385  (45 bytes)

undefined1 FUN_CODE_7385(undefined2 param_1,byte param_2,char param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = (byte)param_1;
  cVar1 = (char)((ushort)param_1 >> 8);
  if (param_4 == '\x01') {
    return *(undefined1 *)
            CONCAT11(cVar1 + (param_3 - ((CARRY1(bVar2,param_2) << 7) >> 7)),bVar2 + param_2);
  }
  if (param_4 == '\0') {
    return *(undefined1 *)(param_2 + bVar2);
  }
  if (param_4 == -2) {
    return *(undefined1 *)(ushort)(param_2 + bVar2);
  }
  return *(undefined1 *)
          CONCAT11(cVar1 + (param_3 - ((CARRY1(bVar2,param_2) << 7) >> 7)),bVar2 + param_2);
}



// ==== FUN_CODE_73b2 @ CODE:73b2  (18 bytes)

void FUN_CODE_73b2(undefined1 param_1,undefined1 *param_2,undefined1 param_3,char param_4)

{
  if (param_4 == '\x01') {
    *(undefined1 *)CONCAT11(param_3,param_2) = param_1;
    return;
  }
  if (param_4 == '\0') {
    *param_2 = param_1;
    return;
  }
  if (param_4 == -2) {
    *(undefined1 *)ZEXT12(param_2) = param_1;
  }
  return;
}



// ==== FUN_CODE_73c4 @ CODE:73c4  (34 bytes)

void FUN_CODE_73c4(undefined1 param_1,undefined2 param_2,byte param_3,char param_4,char param_5)

{
  byte bVar1;
  
  bVar1 = (byte)param_2;
  if (param_5 == '\x01') {
    *(undefined1 *)
     CONCAT11((char)((ushort)param_2 >> 8) + (param_4 - ((CARRY1(bVar1,param_3) << 7) >> 7)),
              bVar1 + param_3) = param_1;
    return;
  }
  if (param_5 == '\0') {
    *(undefined1 *)(param_3 + bVar1) = param_1;
    return;
  }
  if (param_5 == -2) {
    *(undefined1 *)(ushort)(param_3 + bVar1) = param_1;
  }
  return;
}



// ==== FUN_CODE_73e6 @ CODE:73e6  (20 bytes)

char FUN_CODE_73e6(char param_1,byte param_2,char param_3,byte param_4)

{
  return param_1 * param_4 + param_3 * param_2 + (char)((ushort)param_4 * (ushort)param_2 >> 8);
}



// ==== FUN_CODE_73fa @ CODE:73fa  (54 bytes)

char FUN_CODE_73fa(char param_1,char param_2,char param_3,char param_4)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  
  F0 = 0;
  if (param_1 < '\0') {
    bVar2 = F0;
    F0 = bVar2 ^ 1;
    bVar1 = param_2 != '\0';
    param_2 = -param_2;
    param_1 = -(param_1 - ((bVar1 << 7) >> 7));
  }
  if (param_3 < '\0') {
    bVar2 = F0;
    F0 = bVar2 ^ 1;
    bVar1 = param_4 != '\0';
    param_4 = -param_4;
    param_3 = -(param_3 - ((bVar1 << 7) >> 7));
    FUN_CODE_79e3(param_1,param_2,param_3,param_4);
    cVar4 = -(param_1 - (((param_2 != '\0') << 7) >> 7));
  }
  else {
    cVar4 = FUN_CODE_79e3(param_1,param_2);
  }
  cVar3 = F0;
  if (cVar3 != '\0') {
    cVar4 = -(param_3 - (((param_4 != '\0') << 7) >> 7));
  }
  return cVar4;
}



// ==== FUN_CODE_7430 @ CODE:7430  (22 bytes)

void FUN_CODE_7430(char param_1,short param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  
  pbVar3 = (byte *)(param_2 + 1);
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + param_3;
  cVar2 = (char)((ushort)pbVar3 >> 8);
  if ((char)pbVar3 == '\0') {
    cVar2 = cVar2 + -1;
  }
  pcVar4 = (char *)CONCAT11(cVar2,(char)pbVar3 + -1);
  *pcVar4 = *pcVar4 + (param_1 - ((CARRY1(bVar1,param_3) << 7) >> 7));
  return;
}



// ==== FUN_CODE_7446 @ CODE:7446  (22 bytes)

char FUN_CODE_7446(char param_1,short param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  
  pbVar3 = (byte *)(param_2 + 1);
  bVar1 = *pbVar3;
  *pbVar3 = param_3 + bVar1;
  cVar2 = (char)((ushort)pbVar3 >> 8);
  if ((char)pbVar3 == '\0') {
    cVar2 = cVar2 + -1;
  }
  pcVar4 = (char *)CONCAT11(cVar2,(char)pbVar3 + -1);
  cVar2 = *pcVar4;
  *pcVar4 = param_1 + (cVar2 - ((CARRY1(param_3,bVar1) << 7) >> 7));
  return cVar2;
}



// ==== FUN_CODE_745c @ CODE:745c  (43 bytes)

undefined1 FUN_CODE_745c(char param_1,undefined1 param_2,char param_3)

{
  if (param_3 == '\x01') {
    return *(undefined1 *)(CONCAT11(param_2,param_1) + 1);
  }
  if (param_3 == '\0') {
    return *(undefined1 *)(param_1 + '\x01');
  }
  if (param_3 == -2) {
    return *(undefined1 *)(ushort)(param_1 + 1);
  }
  return *(undefined1 *)(CONCAT11(param_2,param_1) + 1);
}



// ==== FUN_CODE_7487 @ CODE:7487  (56 bytes)

undefined1 FUN_CODE_7487(undefined2 param_1,byte param_2,char param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = (byte)param_1;
  cVar1 = (char)((ushort)param_1 >> 8);
  if (param_4 == '\x01') {
    return *(undefined1 *)
            (CONCAT11(cVar1 + (param_3 - ((CARRY1(bVar2,param_2) << 7) >> 7)),bVar2 + param_2) + 1);
  }
  if (param_4 == '\0') {
    return *(undefined1 *)(param_2 + bVar2 + '\x01');
  }
  if (param_4 == -2) {
    return *(undefined1 *)(ushort)(param_2 + bVar2 + 1);
  }
  return *(undefined1 *)(CONCAT11(cVar1 + param_3,bVar2) + 1 + (ushort)param_2);
}



// ==== FUN_CODE_74bf @ CODE:74bf  (31 bytes)

void FUN_CODE_74bf(undefined1 param_1,undefined1 param_2,undefined1 *param_3,undefined1 param_4,
                  char param_5)

{
  if (param_5 == '\x01') {
    *(undefined1 *)CONCAT11(param_4,param_3) = param_1;
    ((undefined1 *)CONCAT11(param_4,param_3))[1] = param_2;
    return;
  }
  if (param_5 == '\0') {
    *param_3 = param_1;
    param_3['\x01'] = param_2;
    return;
  }
  if (param_5 == -2) {
    *(undefined1 *)ZEXT12(param_3) = param_1;
    *(undefined1 *)ZEXT12(param_3 + '\x01') = param_2;
  }
  return;
}



// ==== FUN_CODE_74de @ CODE:74de  (12 bytes)

char FUN_CODE_74de(byte param_1,undefined2 param_2,byte param_3)

{
  return (char)((ushort)param_1 * (ushort)param_3 >> 8) +
         ((char)((ushort)param_2 >> 8) -
         ((CARRY1((byte)((ushort)param_1 * (ushort)param_3),(byte)param_2) << 7) >> 7));
}



// ==== FUN_CODE_74ea @ CODE:74ea  (9 bytes)

undefined1 FUN_CODE_74ea(short param_1)

{
  return *(undefined1 *)(param_1 + 2);
}



// ==== FUN_CODE_74f3 @ CODE:74f3  (9 bytes)

void FUN_CODE_74f3(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  *param_1 = param_4;
  param_1[1] = param_3;
  param_1[2] = param_2;
  return;
}



// ==== FUN_CODE_74fc @ CODE:74fc  (32 bytes)

void FUN_CODE_74fc(undefined1 param_1,char param_2)

{
  if (param_2 == '\x01') {
    FUN_CODE_74ea(param_1);
    return;
  }
  if (param_2 == '\0') {
    FUN_CODE_7a38(param_1);
    return;
  }
  if (param_2 == -2) {
    FUN_CODE_7a58(param_1);
    return;
  }
  FUN_CODE_7a61(param_1);
  return;
}



// ==== FUN_CODE_751c @ CODE:751c  (48 bytes)

void FUN_CODE_751c(undefined2 param_1,byte param_2,char param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = (byte)param_1;
  cVar1 = (char)((ushort)param_1 >> 8);
  if (param_4 == '\x01') {
    FUN_CODE_74ea(cVar1 + (param_3 - ((CARRY1(bVar2,param_2) << 7) >> 7)),bVar2 + param_2);
    return;
  }
  if (param_4 == '\0') {
    FUN_CODE_7a38(param_2 + bVar2);
    return;
  }
  if (param_4 == -2) {
    FUN_CODE_7a58(param_2 + bVar2);
    return;
  }
  FUN_CODE_7a61(cVar1 + (param_3 - ((CARRY1(bVar2,param_2) << 7) >> 7)),bVar2 + param_2);
  return;
}



// ==== FUN_CODE_754c @ CODE:754c  (45 bytes)

void FUN_CODE_754c(char param_1,char param_2)

{
  char *pcVar1;
  undefined1 uStackX_0;
  undefined1 in_stack_000000ff;
  
  for (pcVar1 = (char *)CONCAT11(uStackX_0,in_stack_000000ff);
      (*pcVar1 != '\0' || (pcVar1[1] != '\0')); pcVar1 = pcVar1 + 4) {
    if ((pcVar1[2] == param_2) && (pcVar1[3] == param_1)) goto LAB_CODE_755c;
  }
  pcVar1 = pcVar1 + 2;
LAB_CODE_755c:
                    /* WARNING: Could not recover jumptable at 0x7566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)pcVar1)();
  return;
}



// ==== FUN_CODE_7701 @ CODE:7701  (51 bytes)

char FUN_CODE_7701(byte param_1,char param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  bVar1 = param_3 + 2;
  bVar2 = bVar1;
  if ((bVar1 < 4) && (bVar2 = param_2 + 2, bVar2 < 4)) {
    bVar1 = (bVar2 * '\x02' | bVar2 >> 7) << 1 | (bVar2 & 0x7f) >> 6 | bVar1;
                    /* WARNING: Could not recover jumptable at 0x771d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    cVar3 = (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x75f2))();
    return cVar3;
  }
  cVar3 = '\0';
  if (bVar2 != 0 || param_1 != 0) {
    cVar3 = (bVar2 ^ 0x80) - ((param_1 ^ 0x80) + 1);
  }
  return cVar3;
}



// ==== FUN_CODE_77ea @ CODE:77ea  (36 bytes)

char FUN_CODE_77ea(undefined1 param_1,char param_2,char param_3)

{
  byte bVar1;
  char cVar2;
  
  if ((param_3 + 2U < 4) && (bVar1 = param_2 + 2, bVar1 < 4)) {
    bVar1 = (bVar1 * '\x02' | bVar1 >> 7) << 1 | (bVar1 & 0x7f) >> 6 | param_3 + 2U;
                    /* WARNING: Could not recover jumptable at 0x7806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    cVar2 = (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x776e))(param_1);
    return cVar2;
  }
  return param_3;
}



// ==== FUN_CODE_798d @ CODE:798d  (53 bytes)

void FUN_CODE_798d(byte param_1,char param_2,char param_3,char param_4,char param_5)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = param_3 + 2;
  bVar2 = bVar1;
  if ((bVar1 < 4) && (bVar2 = param_2 + 2, bVar2 < 4)) {
    bVar1 = (bVar2 * '\x02' | bVar2 >> 7) << 1 | (bVar2 & 0x7f) >> 6 | bVar1;
    if (param_5 != '\0' || param_4 != '\0') {
      if (param_5 != '\0') {
        param_4 = param_4 + '\x01';
      }
                    /* WARNING: Could not recover jumptable at 0x79b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x787e))(param_4);
      return;
    }
  }
  else if (bVar2 == param_1) {
    return;
  }
  return;
}



// ==== FUN_CODE_79b6 @ CODE:79b6  (45 bytes)

void FUN_CODE_79b6(undefined1 *param_1,undefined1 param_2,char param_3,undefined1 param_4,
                  char param_5,char param_6)

{
  undefined1 *puVar1;
  
  if (param_6 != '\0' || param_5 != '\0') {
    if (param_3 != '\x01') {
      if (param_3 == '\0') {
        do {
          *param_1 = param_4;
          param_1 = param_1 + '\x01';
          param_6 = param_6 + -1;
        } while (param_6 != '\0');
        return;
      }
      if (param_3 == -2) {
        do {
          *(undefined1 *)ZEXT12(param_1) = param_4;
          param_1 = param_1 + '\x01';
          param_6 = param_6 + -1;
        } while (param_6 != '\0');
      }
      return;
    }
    puVar1 = (undefined1 *)CONCAT11(param_2,param_1);
    if (param_6 != '\0') {
      param_5 = param_5 + '\x01';
    }
    do {
      do {
        *puVar1 = param_4;
        puVar1 = puVar1 + 1;
        param_6 = param_6 + -1;
      } while (param_6 != '\0');
      param_5 = param_5 + -1;
    } while (param_5 != '\0');
  }
  return;
}



// ==== FUN_CODE_79e3 @ CODE:79e3  (85 bytes)

byte FUN_CODE_79e3(char param_1,byte param_2,byte param_3,byte param_4)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  
  if (param_1 != '\0') {
    bVar2 = 0;
    cVar3 = '\b';
    do {
      bVar1 = CARRY1(param_4,param_4);
      param_4 = param_4 * '\x02';
      bVar4 = param_3 << 1 | bVar1;
      bVar6 = bVar2 << 1 | param_3 >> 7;
      bVar5 = param_1 - (((bVar4 < param_2 - ((char)bVar2 >> 7)) << 7) >> 7);
      bVar2 = bVar6;
      if (bVar6 >= bVar5) {
        bVar4 = bVar4 - (param_2 - (((bVar6 < bVar5) << 7) >> 7));
        param_4 = param_4 + 1;
        bVar2 = bVar6 - bVar5;
      }
      cVar3 = cVar3 + -1;
      param_3 = bVar4;
    } while (cVar3 != '\0');
    return bVar4;
  }
  if (param_3 == 0) {
    if (param_2 != 0) {
      param_4 = param_4 / param_2;
    }
    return param_4;
  }
  bVar2 = 0;
  bVar5 = param_3;
  if (param_2 != 0) {
    bVar5 = param_3 / param_2;
    bVar2 = param_3 % param_2;
  }
  cVar3 = OV;
  if (cVar3 != '\x01') {
    cVar3 = '\b';
    bVar5 = bVar2;
LAB_CODE_7a21:
    do {
      bVar1 = CARRY1(param_4,param_4);
      param_4 = param_4 * '\x02';
      bVar2 = bVar5 << 1 | bVar1;
      if ((char)bVar5 < '\0') {
        bVar5 = bVar2 - param_2;
      }
      else {
        bVar4 = param_2 - ((char)bVar5 >> 7);
        bVar6 = bVar2 - bVar4;
        bVar5 = bVar6;
        if (bVar2 < bVar4) {
          cVar3 = cVar3 + -1;
          bVar5 = bVar2;
          if (cVar3 == '\0') {
            return bVar6;
          }
          goto LAB_CODE_7a21;
        }
      }
      param_4 = param_4 + 1;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
  }
  return bVar5;
}



// ==== FUN_CODE_7a38 @ CODE:7a38  (9 bytes)

undefined1 FUN_CODE_7a38(char param_1)

{
  return *(undefined1 *)(param_1 + '\x02');
}



// ==== FUN_CODE_7a41 @ CODE:7a41  (23 bytes)

void FUN_CODE_7a41(char param_1,short param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  
  pbVar3 = (byte *)(param_2 + 2);
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + param_3;
  cVar2 = (char)((ushort)pbVar3 >> 8);
  if ((char)pbVar3 == '\0') {
    cVar2 = cVar2 + -1;
  }
  pcVar4 = (char *)CONCAT11(cVar2,(char)pbVar3 + -1);
  *pcVar4 = *pcVar4 + (param_1 - ((CARRY1(bVar1,param_3) << 7) >> 7));
  return;
}



// ==== FUN_CODE_7a58 @ CODE:7a58  (9 bytes)

undefined1 FUN_CODE_7a58(char param_1)

{
  return *(undefined1 *)(ushort)(param_1 + 2);
}



// ==== FUN_CODE_7a61 @ CODE:7a61  (12 bytes)

undefined1 FUN_CODE_7a61(short param_1)

{
  return *(undefined1 *)(param_1 + 2);
}



// ==== FUN_CODE_7a6d @ CODE:7a6d  (38 bytes)

void FUN_CODE_7a6d(char param_1)

{
  char *pcVar1;
  undefined1 uStackX_0;
  undefined1 in_stack_000000ff;
  
  for (pcVar1 = (char *)CONCAT11(uStackX_0,in_stack_000000ff);
      (*pcVar1 != '\0' || (pcVar1[1] != '\0')); pcVar1 = pcVar1 + 3) {
    if (pcVar1[2] == param_1) goto LAB_CODE_7a7d;
  }
  pcVar1 = pcVar1 + 2;
LAB_CODE_7a7d:
                    /* WARNING: Could not recover jumptable at 0x7a87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)pcVar1)();
  return;
}



// ==== FUN_CODE_7aa2 @ CODE:7aa2  (19 bytes)

void FUN_CODE_7aa2(void)

{
  undefined2 uVar1;
  
  uVar1 = 0xf48;
  if (_5_7 != '\0') {
    uVar1 = 0xf4b;
  }
  FUN_CODE_7a41(0,uVar1,1);
  FUN_CODE_736c();
  return;
}



// ==== FUN_CODE_7ad6 @ CODE:7ad6  (20 bytes)

void FUN_CODE_7ad6(undefined1 param_1)

{
  if (BANK3_R1 != '\0') {
    BANK3_R1 = BANK3_R1 + -1;
  }
  BANK3_R4 = BANK3_R4 + '\x01';
  if (BANK3_R4 == '\0') {
    BANK3_R3 = BANK3_R3 + '\x01';
  }
  if (_5_7 == '\0') {
    FUN_CODE_7f7d();
    return;
  }
  FUN_CODE_7a41(0,0xf48,1);
  FUN_CODE_73b2(param_1);
  return;
}



// ==== FUN_CODE_7ae7 @ CODE:7ae7  (14 bytes)

void FUN_CODE_7ae7(undefined1 param_1)

{
  FUN_CODE_7a41(0,0xf48,1);
  FUN_CODE_73b2(param_1);
  return;
}



// ==== FUN_CODE_7af8 @ CODE:7af8  (214 bytes)

byte FUN_CODE_7af8(byte *param_1,byte param_2,byte param_3)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  pbVar7 = (undefined1 *)0x0;
  _5_7 = '\x01';
  BANK3_R0 = 3;
  FUN_CODE_74f3(0xf48);
  BANK3_R1 = 0;
  BANK3_R3 = 0;
  BANK3_R4 = 0;
  while( true ) {
    while (BANK3_R1 != 0) {
      FUN_CODE_7ad6(0x20);
    }
    BANK3_R2 = BANK3_R1;
    _5_1 = 0;
    _5_0 = 0;
    _5_2 = 0;
    _5_3 = '\0';
    _5_5 = 0;
    _5_6 = 0;
    _6_0 = '\0';
    cVar3 = FUN_CODE_7aa2();
    if (cVar3 == '\0') {
      bVar4 = 0;
      if (_5_7 != '\0') {
        bVar4 = FUN_CODE_7ae7(0);
      }
      return bVar4;
    }
    if (cVar3 == '%') break;
    FUN_CODE_7ad6(cVar3);
  }
  F0 = 0;
  while( true ) {
    _5_4 = '\0';
    bVar5 = FUN_CODE_7aa2();
    bVar4 = bVar5 - 0x30;
    if (9 < bVar4) break;
    cVar3 = F0;
    if (cVar3 == '\x01') {
      BANK3_R2 = BANK3_R2 * '\n' + bVar4;
    }
    else {
      BANK3_R1 = BANK3_R1 * '\n' + bVar4;
      if (BANK3_R1 == 0) {
        _5_3 = '\x01';
      }
    }
  }
  bVar1 = bVar5 + 0x9f < 0x1a;
  cVar3 = bVar1 << 7;
  if (bVar1) {
    bVar5 = bVar5 & 0xdf;
    _5_4 = '\x01';
  }
  bVar4 = FUN_CODE_7a6d(bVar5);
  param_3 = bVar4 & (byte)param_1 | param_3;
  DAT_INTMEM_7c = DAT_INTMEM_7c & 0x2c | param_3;
  if (_9_7 != '\0') {
    bVar4 = (char)param_1 - (cVar3 >> 7);
    DAT_INTMEM_7c = DAT_INTMEM_7c | 0x3e;
    return ((byte)(param_1 + ((param_3 + bVar4 | 0x7c) - ((CARRY1(param_3,bVar4) << 7) >> 7))) |
           param_2) & DAT_INTMEM_7c;
  }
  *param_1 = *param_1 & 0xf0 | param_3 & 0xf;
code_c0x7d71:
  if (_5_5 != 0) {
    param_2 = *pbVar7;
    pbVar7 = pbVar7 + -1;
  }
  do {
    bVar4 = *pbVar7;
    if (bVar4 == BANK3_R1) {
      if (_5_5 != 0) {
        uVar2 = 0x30;
        if (param_2 == 0x10) {
          *pbVar7 = 0x87;
          pbVar7['\x01'] = 0x7d;
          FUN_CODE_7ad6(0x30);
          uVar2 = 0x58;
          if (_5_4 != '\0') {
            uVar2 = 0x78;
          }
        }
        else if (param_2 != 8) goto LAB_CODE_7d96;
        *pbVar7 = 0x96;
        pbVar7['\x01'] = 0x7d;
        bVar4 = FUN_CODE_7ad6(uVar2);
      }
LAB_CODE_7d96:
      if (_5_2 == 0) {
        uVar2 = 0x20;
        if ((_6_0 != '\x01') && (uVar2 = 0x2b, _5_6 != 1)) {
          return bVar4;
        }
      }
      else {
        uVar2 = 0x2d;
      }
      bVar4 = FUN_CODE_7ad6(uVar2);
      return bVar4;
    }
    *pbVar7 = bVar4;
    uVar2 = 0x20;
    if ((_5_3 == '\0') || (uVar2 = 0x30, -1 < (char)((_5_2 & 1 | _5_6 & 1 | _5_5) << 7))) break;
    pbVar7['\x01'] = 0x5e;
    pbVar7['\x02'] = 0x7d;
    FUN_CODE_7d7c();
    _5_2 = 0;
    _5_6 = 0;
    _5_5 = 0;
  } while( true );
  if (_5_5 != 0) {
    pbVar6 = pbVar7 + '\x01';
    pbVar7 = pbVar7 + '\x01';
    *pbVar6 = param_2;
  }
  pbVar7['\x01'] = 0x71;
  pbVar7['\x02'] = 0x7d;
  FUN_CODE_7ad6(uVar2);
  goto code_c0x7d71;
}



// ==== FUN_CODE_7d7c @ CODE:7d7c  (45 bytes)

void FUN_CODE_7d7c(char param_1)

{
  undefined1 uVar1;
  
  if (_5_5 != '\0') {
    uVar1 = 0x30;
    if (param_1 == '\x10') {
      FUN_CODE_7ad6(0x30);
      uVar1 = 0x58;
      if (_5_4 != '\0') {
        uVar1 = 0x78;
      }
    }
    else if (param_1 != '\b') goto LAB_CODE_7d96;
    FUN_CODE_7ad6(uVar1);
  }
LAB_CODE_7d96:
  if (_5_2 == '\0') {
    uVar1 = 0x20;
    if ((_6_0 != '\x01') && (uVar1 = 0x2b, _5_6 != '\x01')) {
      return;
    }
  }
  else {
    uVar1 = 0x2d;
  }
  FUN_CODE_7ad6(uVar1);
  return;
}



// ==== FUN_CODE_7def @ CODE:7def  (17 bytes)

char FUN_CODE_7def(byte param_1)

{
  char cVar1;
  
  cVar1 = param_1 - 0x30;
  if (0x2f < param_1) {
    cVar1 = param_1 - 0x3a;
  }
  return cVar1;
}



// ==== FUN_CODE_7e00 @ CODE:7e00  (41 bytes)

char FUN_CODE_7e00(byte param_1)

{
  char cVar1;
  
  if ((((param_1 < 0x41) || (cVar1 = param_1 + 0xa5, 0x5a < param_1)) &&
      ((param_1 < 0x61 || (cVar1 = param_1 + 0x85, 0x7a < param_1)))) &&
     (cVar1 = param_1 - 0x30, 0x2f < param_1)) {
    cVar1 = param_1 - 0x3a;
  }
  return cVar1;
}



// ==== FUN_CODE_7e29 @ CODE:7e29  (21 bytes)

void FUN_CODE_7e29(void)

{
  char cVar1;
  
  do {
    cVar1 = FUN_CODE_736c();
  } while (cVar1 != '\0');
  return;
}



// ==== FUN_CODE_7e3e @ CODE:7e3e  (216 bytes)

byte FUN_CODE_7e3e(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  char in_PSW;
  byte bVar5;
  char *pcVar6;
  
  DAT_EXTMEM_0f70 = param_3;
  DAT_EXTMEM_0f71 = param_2;
  DAT_EXTMEM_0f72 = param_1;
  while( true ) {
    uVar1 = FUN_CODE_736c(DAT_EXTMEM_0f72,DAT_EXTMEM_0f71,DAT_EXTMEM_0f70);
    FUN_CODE_7fa4(uVar1);
    if (-1 < in_PSW) break;
    FUN_CODE_7430(0,0xf71,1);
  }
  _6_1 = 1;
  bVar2 = FUN_CODE_736c(DAT_EXTMEM_0f72,DAT_EXTMEM_0f71,DAT_EXTMEM_0f70);
  if ((bVar2 == 0x2b) || (bVar5 = (bVar2 < 0x2d) << 7, bVar2 == 0x2d)) {
    uVar1 = 1;
    uVar3 = FUN_CODE_7446(0,0xf71,1,DAT_EXTMEM_0f70);
    cVar4 = FUN_CODE_736c(uVar1,uVar3);
    if (cVar4 == '-') {
      bVar5 = 0;
    }
    else {
      bVar5 = 0x80;
    }
    _6_1 = bVar5 >> 7;
  }
  DAT_EXTMEM_0f73 = 0;
  DAT_EXTMEM_0f74 = 0;
  while( true ) {
    uVar1 = FUN_CODE_736c(DAT_EXTMEM_0f72,DAT_EXTMEM_0f71,DAT_EXTMEM_0f70);
    FUN_CODE_7def(uVar1);
    if (-1 < (char)bVar5) break;
    bVar2 = FUN_CODE_736c(DAT_EXTMEM_0f72,DAT_EXTMEM_0f71,DAT_EXTMEM_0f70);
    bVar5 = bVar2 - 0x30;
    cVar4 = ((char)bVar2 >> 7) + (-1 - (((0x2f < bVar2) << 7) >> 7));
    pcVar6 = (char *)&DAT_EXTMEM_0f74;
    bVar2 = DAT_EXTMEM_0f74;
    FUN_CODE_73e6(0,10);
    *pcVar6 = bVar2 + bVar5;
    bVar2 = cVar4 - ((CARRY1(bVar2,bVar5) << 7) >> 7);
    bVar5 = CARRY1(DAT_EXTMEM_0f73,bVar2) << 7;
    DAT_EXTMEM_0f73 = DAT_EXTMEM_0f73 + bVar2;
    FUN_CODE_7430(0,0xf71,1);
  }
  if (_6_1 == 0) {
    bVar2 = -(DAT_EXTMEM_0f73 - (((DAT_EXTMEM_0f74 != 0) << 7) >> 7));
  }
  else {
    bVar2 = DAT_EXTMEM_0f74;
  }
  return bVar2;
}



// ==== FUN_CODE_7f16 @ CODE:7f16  (103 bytes)

undefined1 FUN_CODE_7f16(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  
  DAT_EXTMEM_0f75 = param_3;
  DAT_EXTMEM_0f76 = param_2;
  DAT_EXTMEM_0f77 = param_1;
  while( true ) {
    cVar4 = DAT_EXTMEM_0f7c;
    if (DAT_EXTMEM_0f7c == '\0') {
      cVar4 = DAT_EXTMEM_0f7d;
    }
    if (cVar4 == '\0') break;
    uVar2 = 1;
    uVar3 = FUN_CODE_7446(0,0xf79,1,DAT_EXTMEM_0f78);
    cVar4 = FUN_CODE_736c(uVar2,uVar3);
    uVar2 = 1;
    uVar3 = FUN_CODE_7446(0,0xf76,1,DAT_EXTMEM_0f75);
    FUN_CODE_73b2(cVar4,uVar2,uVar3);
    if (DAT_EXTMEM_0f7b == cVar4) {
      return DAT_EXTMEM_0f77;
    }
    bVar1 = DAT_EXTMEM_0f7d != '\0';
    DAT_EXTMEM_0f7d = DAT_EXTMEM_0f7d + -1;
    DAT_EXTMEM_0f7c = DAT_EXTMEM_0f7c + (-1 - ((bVar1 << 7) >> 7));
  }
  return 0;
}



// ==== FUN_CODE_7f7d @ CODE:7f7d  (11 bytes)

char FUN_CODE_7f7d(char param_1)

{
  char cVar1;
  
  if (param_1 == '\n') {
    FUN_CODE_7f88(0xd);
    param_1 = '\n';
  }
  cVar1 = RI;
  if ((cVar1 != '\0') && (cVar1 = SBUF, cVar1 == '\x13')) {
    RI = 0;
    do {
      do {
        cVar1 = RI;
      } while (cVar1 == '\0');
      cVar1 = SBUF;
      RI = 0;
    } while (cVar1 != '\x11');
  }
  do {
    cVar1 = TI;
  } while (cVar1 == '\0');
  TI = 0;
  SBUF = param_1;
  return param_1;
}



// ==== FUN_CODE_7f88 @ CODE:7f88  (28 bytes)

void FUN_CODE_7f88(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = RI;
  if ((cVar1 != '\0') && (cVar1 = SBUF, cVar1 == '\x13')) {
    RI = 0;
    do {
      do {
        cVar1 = RI;
      } while (cVar1 == '\0');
      cVar1 = SBUF;
      RI = 0;
    } while (cVar1 != '\x11');
  }
  do {
    cVar1 = TI;
  } while (cVar1 == '\0');
  TI = 0;
  SBUF = param_1;
  return;
}



// ==== FUN_CODE_7fa4 @ CODE:7fa4  (21 bytes)

byte FUN_CODE_7fa4(byte param_1)

{
  byte bVar1;
  
  if ((param_1 < 9) || (bVar1 = param_1 - 0xe, 0xd < param_1)) {
    bVar1 = param_1;
  }
  return bVar1;
}


