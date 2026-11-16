// Ghidra-decompilatie van MLAWO_RET_RET60.PLM51_18-11-92.bin

// ==== VEC_RESET @ CODE:0000  (3 bytes)

void VEC_RESET(void)

{
  reset_entry();
  return;
}



// ==== FUN_CODE_0003 @ CODE:0003  (8 bytes)

char FUN_CODE_0003(char param_1,byte param_2,char param_3,byte param_4)

{
  return param_3 - (param_1 - (((param_4 < param_2) << 7) >> 7));
}



// ==== VEC_TIMER0 @ CODE:000b  (3 bytes)

void VEC_TIMER0(void)

{
  isr_timer0();
  return;
}



// ==== FUN_CODE_000e @ CODE:000e  (17 bytes)

char FUN_CODE_000e(undefined2 param_1,char param_2,byte param_3)

{
  char cVar1;
  
  cVar1 = (char)((ushort)param_1 >> 8);
  if (CARRY1(param_3,param_3)) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1 + (param_2 * '\x02' - ((CARRY1(param_3 * '\x02',(byte)param_1) << 7) >> 7));
}



// ==== VEC_SERIAL @ CODE:0023  (3 bytes)

void VEC_SERIAL(void)

{
  isr_serial();
  return;
}



// ==== FUN_CODE_0027 @ CODE:0027  (19 bytes)

void FUN_CODE_0027(void)

{
  undefined1 uVar1;
  
  uVar1 = LATCH5;
  uVar1 = LATCH6_802_15;
  _0_0 = 0;
  return;
}



// ==== FUN_CODE_003a @ CODE:003a  (20 bytes)

char FUN_CODE_003a(void)

{
  char cVar1;
  
  cVar1 = BANK3_R1 - 0x30;
  if ((BANK3_R1 < 0x30) || (cVar1 = BANK3_R1 - 0x3a, -1 < (BANK3_R1 < 0x3a) << 7)) {
    return cVar1;
  }
  return cVar1;
}



// ==== FUN_CODE_004e @ CODE:004e  (100 bytes)

char FUN_CODE_004e(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte in_PSW;
  byte bVar5;
  undefined1 *puVar6;
  char *pcVar7;
  
  BANK2_R7 = 0;
  BANK2_R6 = '\0';
  BANK3_R0 = BANK2_R5;
  while( true ) {
    puVar6 = &DAT_EXTMEM_025a;
    FUN_CODE_3b75(BANK3_R0);
    BANK3_R1 = *puVar6;
    FUN_CODE_003a();
    if (BANK3_R0 < 6) {
      bVar5 = 0x80;
    }
    else {
      bVar5 = 0;
    }
    param_1 = param_1 & 0xfe | bVar5 >> 7;
    bVar2 = ((char)param_1 < '\0') << 5;
    bVar3 = (param_1 == 0) << 1;
    if (-1 < (char)(in_PSW & (bVar5 | 0x5d) | bVar2 | bVar3)) break;
    bVar3 = in_PSW & 0x5d | bVar2 | bVar3;
    bVar1 = 0x19 < (byte)(BANK2_R6 -
                         ((char)(bVar3 | (0x98 < BANK2_R7 - ((char)(bVar3 | 0x80) >> 7)) << 7) >> 7)
                         );
    in_PSW = bVar3 | bVar1 << 7;
    if (bVar1) {
      BANK2_R6 = -1;
      BANK2_R7 = 0xff;
    }
    else {
      cVar4 = BANK2_R6;
      bVar5 = BANK2_R7;
      FUN_CODE_3b31(10);
      pcVar7 = &DAT_EXTMEM_025a;
      FUN_CODE_3b75(BANK3_R0);
      BANK2_R7 = (*pcVar7 - 0x30U) + bVar5;
      in_PSW = in_PSW & 0x5d | CARRY1(*pcVar7 - 0x30U,bVar5) << 7 | ((char)BANK2_R7 < '\0') << 5 |
               (BANK2_R7 == 0) << 1;
      if ((char)in_PSW < '\0') {
        cVar4 = cVar4 + '\x01';
      }
      BANK2_R6 = cVar4;
    }
    BANK3_R0 = BANK3_R0 + 1;
  }
  return BANK3_R0 - 6;
}



// ==== FUN_CODE_00b2 @ CODE:00b2  (78 bytes)

void FUN_CODE_00b2(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  
  BANK2_R3 = 0xff;
  for (BANK2_R4 = 0; BANK2_R4 < BANK2_R2; BANK2_R4 = BANK2_R4 + 1) {
    FUN_CODE_3b75(BANK2_R4);
    cVar1 = P;
    if (cVar1 != '\0') {
      pbVar3 = &DAT_EXTMEM_0219;
      FUN_CODE_3b75(BANK2_R4);
      bVar2 = *pbVar3 ^ 0x80;
      pbVar3 = &DAT_EXTMEM_0219;
      FUN_CODE_3b75(BANK2_R4);
      *pbVar3 = bVar2;
    }
    pbVar3 = &DAT_EXTMEM_0219;
    FUN_CODE_3b75(BANK2_R4);
    BANK2_R3 = *pbVar3 ^ BANK2_R3;
  }
  pbVar3 = &DAT_EXTMEM_0219;
  FUN_CODE_3b75(BANK2_R4);
  *pbVar3 = BANK2_R3;
  return;
}



// ==== telegram_dispatch @ CODE:0100  (603 bytes)

byte telegram_dispatch(undefined1 param_1,byte param_2)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  undefined1 *puVar5;
  
  BANK2_R0 = 0;
  cVar4 = (DAT_EXTMEM_025a < 0x61) << 7;
  if (DAT_EXTMEM_025a == 0x61) {
    BANK3_R1 = DAT_EXTMEM_025b;
    FUN_CODE_003a();
    if (cVar4 < '\0') {
      BANK2_R0 = 7;
    }
    else if (DAT_EXTMEM_025b == 'V') {
      BANK2_R0 = 8;
    }
    else if (DAT_EXTMEM_025b == 'T') {
      BANK2_R0 = 9;
    }
  }
  else {
    cVar4 = (DAT_EXTMEM_025a < 0x6c) << 7;
    if (DAT_EXTMEM_025a == 0x6c) {
      BANK3_R1 = DAT_EXTMEM_025b;
      FUN_CODE_003a();
      if (cVar4 < '\0') {
        BANK2_R0 = 1;
      }
      else if (DAT_EXTMEM_025b == 'E') {
        BANK2_R0 = 2;
      }
      else if (DAT_EXTMEM_025b == 'S') {
        BANK2_R0 = 10;
      }
    }
    else {
      cVar4 = (DAT_EXTMEM_025a < 0x6b) << 7;
      if (DAT_EXTMEM_025a == 0x6b) {
        BANK3_R1 = DAT_EXTMEM_025b;
        FUN_CODE_003a();
        if (cVar4 < '\0') {
          BANK2_R0 = 3;
        }
      }
      else {
        cVar4 = (DAT_EXTMEM_025a < 0x7a) << 7;
        if (DAT_EXTMEM_025a == 0x7a) {
          BANK3_R1 = DAT_EXTMEM_025b;
          FUN_CODE_003a();
          if (cVar4 < '\0') {
            BANK2_R0 = 4;
          }
          else if (DAT_EXTMEM_025b == 'A') {
            BANK2_R0 = 5;
          }
        }
        else {
          cVar4 = (DAT_EXTMEM_025a < 0x77) << 7;
          if (DAT_EXTMEM_025a == 0x77) {
            BANK3_R1 = DAT_EXTMEM_025b;
            FUN_CODE_003a();
            if (cVar4 < '\0') {
              BANK2_R0 = 6;
            }
          }
          else {
            BANK2_R0 = 0;
          }
        }
      }
    }
  }
  bVar3 = BANK2_R0;
  if (BANK2_R0 != 0) {
    if (BANK2_R0 == 1) {
      BANK2_R5 = 1;
      FUN_CODE_004e();
      BANK2_R1 = 0;
      DAT_EXTMEM_000b = param_1;
      DAT_EXTMEM_000c = param_2;
      do {
        if (3 < BANK2_R1) {
          return BANK2_R1 - 4;
        }
        puVar5 = &DAT_EXTMEM_025a;
        FUN_CODE_3b75(BANK2_R1 + 1);
        uVar2 = *puVar5;
        puVar5 = &LATCH7;
        FUN_CODE_3b75(BANK2_R1);
        *puVar5 = uVar2;
        bVar1 = BANK2_R1 != 0xff;
        bVar3 = BANK2_R1 + 1;
        BANK2_R1 = bVar3;
      } while (bVar1);
    }
    else if (BANK2_R0 == 2) {
      BANK2_R5 = 2;
      FUN_CODE_004e();
      bVar3 = param_2;
      DAT_EXTMEM_0011 = param_1;
      DAT_EXTMEM_0012 = param_2;
    }
    else if (BANK2_R0 != 10) {
      if (BANK2_R0 == 3) {
        BANK2_R5 = 1;
        FUN_CODE_004e();
        bVar3 = param_2;
        DAT_EXTMEM_001b = param_1;
        DAT_EXTMEM_001c = param_2;
      }
      else if (BANK2_R0 == 4) {
        _0_7 = 1;
        BANK2_R5 = 1;
        FUN_CODE_004e();
        bVar3 = param_2;
        DAT_EXTMEM_0015 = param_1;
        DAT_EXTMEM_0016 = param_2;
      }
      else if (BANK2_R0 != 5) {
        if (BANK2_R0 == 0xb) {
          _1_1 = 1;
          bVar3 = BANK2_R0;
        }
        else if (BANK2_R0 == 6) {
          BANK2_R5 = 1;
          FUN_CODE_004e();
          bVar3 = param_2;
          DAT_EXTMEM_0021 = param_1;
          DAT_EXTMEM_0022 = param_2;
        }
        else if (BANK2_R0 == 7) {
          _0_5 = 0;
          bVar3 = DAT_INTMEM_3d + 0x30;
          if (bVar3 == BANK1_R6) {
            if (_1_4 == '\0') {
              BANK2_R1 = 0;
            }
            else {
              BANK2_R1 = 6;
            }
            _1_4 = '\0';
            DAT_EXTMEM_0219 = 0x61;
            DAT_EXTMEM_021a = BANK2_R1 + 0x30;
            DAT_EXTMEM_021b = 0xd;
            BANK2_R2 = 3;
            bVar3 = FUN_CODE_00b2(DAT_EXTMEM_025b);
            DAT_INTMEM_30 = 4;
            _0_4 = 1;
            DAT_INTMEM_34 = 0;
            TI = 1;
          }
        }
        else if (BANK2_R0 == 8) {
          _0_5 = 0;
          if ((DAT_EXTMEM_025c == '0') || (bVar3 = DAT_INTMEM_3d + 0x30, bVar3 == BANK1_R6)) {
            DAT_EXTMEM_0219 = 0x61;
            DAT_EXTMEM_021a = 'V';
            DAT_EXTMEM_021b = DAT_CODE_380b;
            DAT_EXTMEM_021c = DAT_CODE_380c;
            DAT_EXTMEM_021d = DAT_CODE_380d;
            DAT_EXTMEM_021e = DAT_CODE_380e;
            DAT_EXTMEM_021f = DAT_CODE_380f;
            DAT_EXTMEM_0220 = DAT_CODE_3810;
            DAT_EXTMEM_0221 = 0xd;
            BANK2_R2 = 9;
            bVar3 = FUN_CODE_00b2();
            DAT_INTMEM_30 = 10;
            _0_4 = 1;
            DAT_INTMEM_34 = 0;
            TI = 1;
          }
        }
        else if ((BANK2_R0 == 9) &&
                ((_0_5 = 0, DAT_EXTMEM_025c == '0' ||
                 (bVar3 = DAT_INTMEM_3d + 0x30, bVar3 == BANK1_R6)))) {
          bVar3 = DAT_EXTMEM_025d - 0x2f;
          DAT_INTMEM_48 = bVar3;
        }
      }
    }
  }
  return bVar3;
}



// ==== FUN_CODE_035b @ CODE:035b  (191 bytes)

byte FUN_CODE_035b(byte param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar2 = DAT_INTMEM_32;
  cVar1 = RI;
  if (cVar1 == '\x01') {
    BANK3_R2 = SBUF;
    RI = 0;
    _1_3 = 0;
    _1_2 = 0;
    cVar1 = P;
    if (cVar1 == '\0') {
      BANK3_R3 = BANK3_R2 & 0x7f;
      if (DAT_INTMEM_32 == 0) {
        if (((BANK3_R3 < 0x61) << 7 < '\0') || (0x7a < BANK3_R3)) {
          param_1 = BANK3_R3;
          if (BANK3_R3 == 0xd) {
            DAT_INTMEM_32 = 3;
          }
        }
        else {
          DAT_INTMEM_31 = 1;
          param_1 = BANK3_R2 ^ 0xff;
          DAT_INTMEM_32 = 1;
          DAT_INTMEM_2f = param_1;
          DAT_EXTMEM_025a = BANK3_R3;
        }
      }
      else if (DAT_INTMEM_32 == 1) {
        if (DAT_INTMEM_31 < 0xfa) {
          DAT_INTMEM_2f = DAT_INTMEM_2f ^ BANK3_R2;
          pbVar3 = &DAT_EXTMEM_025a;
          FUN_CODE_3b75(DAT_INTMEM_31);
          *pbVar3 = BANK3_R3;
          DAT_INTMEM_31 = DAT_INTMEM_31 + 1;
        }
        param_1 = BANK3_R3;
        if (BANK3_R3 == 0xd) {
          DAT_INTMEM_32 = 2;
        }
      }
      else if (DAT_INTMEM_32 == 2) {
        param_1 = BANK3_R2 ^ DAT_INTMEM_2f;
        if (param_1 == 0) {
          _1_2 = 0;
          _0_1 = 1;
          param_1 = telegram_dispatch();
        }
        else {
          _1_2 = 1;
          _0_1 = 0;
        }
        DAT_INTMEM_32 = 0;
      }
      else {
        DAT_INTMEM_32 = 0;
        param_1 = bVar2;
      }
    }
    else {
      _1_3 = 1;
      DAT_INTMEM_32 = 0;
      param_1 = BANK3_R2;
    }
  }
  cVar1 = TI;
  if ((cVar1 != '\0') && (TI = 0, _0_4 != '\0')) {
    param_1 = DAT_INTMEM_34 - DAT_INTMEM_30;
    if (DAT_INTMEM_34 < DAT_INTMEM_30) {
      pbVar3 = &DAT_EXTMEM_0219;
      FUN_CODE_3b75(DAT_INTMEM_34);
      param_1 = *pbVar3;
      SBUF = param_1;
      DAT_INTMEM_34 = DAT_INTMEM_34 + 1;
    }
    else {
      _0_4 = '\0';
    }
  }
  return param_1;
}



// ==== FUN_CODE_041a @ CODE:041a  (276 bytes)

void FUN_CODE_041a(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  T0 = 1;
  if (DAT_EXTMEM_0359 != '\0' || DAT_EXTMEM_0358 != '\0') {
    FUN_CODE_3b07(0x358);
  }
  if (_1_5 == '\x01') {
    bVar2 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar2 & 0xe0 | (_1_7 & 1) << 4 | DAT_EXTMEM_0360 & 0xf;
    LATCH2_module_enable = DAT_INTMEM_43 / 0x70;
    bVar2 = DAT_INTMEM_43 % 0x70;
    DAT_INTMEM_2d = bVar2;
    if (DAT_INTMEM_43 < 0x70) {
      cVar1 = '\x02';
      bVar3 = (_1_7 & 1) << 1;
      do {
        bVar3 = bVar3 >> 1 | bVar3 << 7;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      pbVar4 = (byte *)CONCAT11(DAT_INTMEM_4d,DAT_INTMEM_4e);
      FUN_CODE_3b75(bVar2,0);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    else if (DAT_EXTMEM_0354 == -0x74) {
      cVar1 = '\x02';
      bVar3 = (_1_7 & 1) << 1;
      do {
        bVar3 = bVar3 >> 1 | bVar3 << 7;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      pbVar4 = (byte *)CONCAT11(DAT_INTMEM_4d,DAT_INTMEM_4e);
      FUN_CODE_3b61(bVar2,0x54);
      FUN_CODE_3b75(bVar2);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    else {
      cVar1 = '\x02';
      bVar3 = (_1_7 & 1) << 1;
      do {
        bVar3 = bVar3 >> 1 | bVar3 << 7;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      pbVar4 = (byte *)CONCAT11(DAT_INTMEM_4d,DAT_INTMEM_4e);
      FUN_CODE_3b61(bVar2,0x62);
      FUN_CODE_3b75(bVar2);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    _1_5 = '\0';
    T0 = 1;
    T0 = 1;
    T0 = 1;
    T0 = 0;
  }
  if (DAT_INTMEM_41 != '\0' || DAT_INTMEM_40 != '\0') {
    FUN_CODE_3b98(0x40);
  }
  if (DAT_INTMEM_3f != '\0' || DAT_INTMEM_3e != '\0') {
    FUN_CODE_3b98(0x3e);
  }
  if (DAT_INTMEM_2c != '\0' || DAT_INTMEM_2b != '\0') {
    bVar2 = T1;
    T1 = bVar2 ^ 1;
    FUN_CODE_3b98(0x2b);
  }
  TL0 = 0xc;
  TH0 = 0xfe;
  return;
}



// ==== FUN_CODE_052e @ CODE:052e  (440 bytes)

void FUN_CODE_052e(void)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  
  do {
    if (_2_1 == 0) break;
  } while (DAT_INTMEM_41 != '\0' || DAT_INTMEM_40 != '\0');
  cVar5 = P1_6;
  if (((cVar5 == '\0') && (DAT_INTMEM_3d == -1)) && (_0_5 == '\x01')) {
    DAT_INTMEM_36 = '=';
    DAT_INTMEM_35 = '\0';
    while (DAT_INTMEM_36 != '\0' || DAT_INTMEM_35 != '\0') {
      cVar5 = DAT_INTMEM_35;
      if (DAT_INTMEM_36 == '\0') {
        cVar5 = DAT_INTMEM_35 + -1;
      }
      puVar9 = &DAT_EXTMEM_0219;
      FUN_CODE_3b56(cVar5);
      uVar2 = *puVar9;
      puVar9 = &DAT_EXTMEM_021c;
      FUN_CODE_3b56(DAT_INTMEM_35,DAT_INTMEM_36);
      *puVar9 = uVar2;
      pcVar7 = &DAT_EXTMEM_021c;
      FUN_CODE_3b56();
      if (*pcVar7 == '\r') {
        DAT_INTMEM_30 = DAT_INTMEM_36 + '\x04';
      }
      FUN_CODE_3b98(0x35);
    }
    DAT_INTMEM_36 = 1;
    DAT_INTMEM_35 = '\0';
    do {
      if ((DAT_INTMEM_35 != '\0') || ((3 < DAT_INTMEM_36) << 7 < '\0')) break;
      puVar9 = &DAT_EXTMEM_0219;
      FUN_CODE_3b56('\x03' - DAT_INTMEM_36);
      *puVar9 = 0x30;
      bVar1 = 0xfe < DAT_INTMEM_36;
      cVar5 = bVar1 << 7;
      DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
      if (bVar1) {
        DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
        cVar5 = '\0';
      }
    } while (-1 < cVar5);
    DAT_EXTMEM_0219 = 0x7a;
    DAT_EXTMEM_0259 = 0xd;
    DAT_INTMEM_34 = 0;
    _0_4 = 1;
    TI = 1;
  }
  pcVar7 = &DAT_CODE_3828;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
  _2_0 = *pcVar7 == '\0';
  if (_0_0 != '\0') {
    _2_0 = !(bool)_2_0;
  }
  FUN_CODE_3ae8(DAT_INTMEM_3d,0x3820,0xe);
  FUN_CODE_3b7e(0x51);
  DAT_INTMEM_43 = 0;
  do {
    if (DAT_EXTMEM_0354 - 1U < DAT_INTMEM_43) break;
    DAT_EXTMEM_0360 = 0;
    do {
      if (DAT_EXTMEM_0355 - 1U < DAT_EXTMEM_0360) break;
      FUN_CODE_3af8(DAT_EXTMEM_0360,CONCAT11(DAT_INTMEM_51,DAT_INTMEM_52));
      FUN_CODE_3b7e(0x4f);
      pbVar8 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_43);
      bVar6 = *pbVar8;
      bVar3 = pbVar8[1];
      pbVar8 = &DAT_EXTMEM_0593;
      FUN_CODE_3af8(DAT_INTMEM_43);
      BANK0_R6 = BANK0_R6 ^ bVar6;
      BANK0_R5 = BANK0_R5 ^ bVar3;
      BANK0_R4 = BANK0_R4 & *pbVar8;
      BANK0_R7 = BANK0_R7 & pbVar8[1];
      if ((DAT_INTMEM_50 != '\0' || DAT_INTMEM_4f != '\0') || ((char)((_2_1 & 1 ^ 1) << 7) < '\0'))
      {
        FUN_CODE_3af8(DAT_INTMEM_43);
        do {
          PCON = 0x81;
        } while( true );
      }
      bVar1 = DAT_EXTMEM_0360 != 0xff;
      DAT_EXTMEM_0360 = DAT_EXTMEM_0360 + 1;
    } while (bVar1);
    bVar1 = DAT_INTMEM_43 != 0xff;
    DAT_INTMEM_43 = DAT_INTMEM_43 + 1;
  } while (bVar1);
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = '\0';
  while( true ) {
    if (DAT_INTMEM_35 != '\0') {
      DAT_INTMEM_33 = 0;
      return;
    }
    if ((0x8b < DAT_INTMEM_36) << 7 < '\0') break;
    puVar9 = &DAT_EXTMEM_0363;
    FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
    uVar2 = *puVar9;
    uVar4 = puVar9[1];
    puVar9 = &DAT_EXTMEM_0593;
    FUN_CODE_000e();
    *puVar9 = uVar2;
    puVar9[1] = uVar4;
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar5 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    if (bVar1) {
      DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
      cVar5 = '\0';
    }
    if (cVar5 < '\0') {
      DAT_INTMEM_33 = 0;
      return;
    }
  }
  DAT_INTMEM_33 = 0;
  return;
}



// ==== FUN_CODE_06e6 @ CODE:06e6  (369 bytes)

char FUN_CODE_06e6(byte param_1,byte param_2)

{
  bool bVar1;
  short sVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  char *pcVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  
  BANK0_R4 = 0;
  BANK0_R5 = DAT_INTMEM_44;
  pcVar8 = &DAT_CODE_3900;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0x10);
  BANK0_R6 = param_1;
  BANK0_R7 = param_2;
  FUN_CODE_3b4b();
  DAT_INTMEM_54 = *pcVar8;
  pbVar9 = &DAT_CODE_3a02;
  FUN_CODE_3ae8(DAT_INTMEM_44,5);
  bVar5 = *pbVar9;
  DAT_EXTMEM_06ac = pbVar9[1];
  pcVar8 = (char *)0x6ab;
  DAT_EXTMEM_06ab = bVar5;
  FUN_CODE_3b3f();
  DAT_INTMEM_56 = *pcVar8;
  puVar10 = &DAT_CODE_3a00;
  FUN_CODE_3ae8(DAT_INTMEM_44,5);
  BANK0_R5 = *puVar10;
  bVar6 = puVar10[1];
  pbVar9 = &DAT_CODE_3a04;
  FUN_CODE_3ae8(DAT_INTMEM_44,5);
  BANK0_R0 = ~*pbVar9 + 1 + DAT_INTMEM_45;
  sVar2 = (ushort)(DAT_INTMEM_56 + 1) * (ushort)bVar5;
  bVar5 = (byte)sVar2;
  DAT_INTMEM_59 = bVar6 + bVar5;
  DAT_INTMEM_58 = param_2 + ((char)((ushort)sVar2 >> 8) - ((CARRY1(bVar6,bVar5) << 7) >> 7));
  DAT_INTMEM_57 = *(char *)CONCAT11(DAT_INTMEM_58,DAT_INTMEM_59);
  uVar3 = 0;
  bVar5 = 1;
  FUN_CODE_3b15(DAT_INTMEM_57 + -1);
  cVar7 = DAT_EXTMEM_0354 - (DAT_INTMEM_57 + DAT_INTMEM_42);
  DAT_INTMEM_50 = uVar3;
  DAT_INTMEM_51 = bVar5;
  if ((byte)(DAT_INTMEM_57 + DAT_INTMEM_42) <= DAT_EXTMEM_0354) {
    DAT_INTMEM_52 = 0;
    do {
      if (DAT_INTMEM_57 - 1U < DAT_INTMEM_52) break;
      DAT_INTMEM_53 = 0;
      do {
        if (DAT_INTMEM_56 - 1U < DAT_INTMEM_53) break;
        DAT_INTMEM_55 = ~(DAT_INTMEM_54 + DAT_INTMEM_53) + DAT_EXTMEM_0355;
        if (DAT_INTMEM_55 + 1U <= DAT_EXTMEM_0355) {
          pbVar9 = (byte *)(CONCAT11(DAT_INTMEM_58,DAT_INTMEM_59) + 1);
          FUN_CODE_3b4b(0,DAT_INTMEM_53);
          if ((*pbVar9 & DAT_INTMEM_51) == 0) {
            uVar3 = 0x7f;
            uVar4 = 0xff;
            FUN_CODE_3a7b(DAT_INTMEM_55);
            pbVar9 = &DAT_EXTMEM_0363;
            FUN_CODE_3af8(DAT_INTMEM_42);
            BANK0_R6 = BANK0_R6 & *pbVar9;
            BANK0_R7 = BANK0_R7 & pbVar9[1];
            puVar10 = &DAT_EXTMEM_0363;
            FUN_CODE_3af8(DAT_INTMEM_42);
            *puVar10 = uVar3;
            puVar10[1] = uVar4;
          }
          else {
            uVar3 = 0x80;
            uVar4 = 0;
            FUN_CODE_3a7b(DAT_INTMEM_55);
            pbVar9 = &DAT_EXTMEM_0363;
            FUN_CODE_3af8(DAT_INTMEM_42);
            BANK0_R6 = BANK0_R6 | *pbVar9;
            BANK0_R7 = BANK0_R7 | pbVar9[1];
            puVar10 = &DAT_EXTMEM_0363;
            FUN_CODE_3af8(DAT_INTMEM_42);
            *puVar10 = uVar3;
            puVar10[1] = uVar4;
          }
        }
        bVar1 = DAT_INTMEM_53 != 0xff;
        DAT_INTMEM_53 = DAT_INTMEM_53 + 1;
      } while (bVar1);
      DAT_INTMEM_42 = DAT_INTMEM_42 + '\x01';
      FUN_CODE_3b23(1);
      bVar1 = DAT_INTMEM_52 != 0xff;
      DAT_INTMEM_52 = DAT_INTMEM_52 + 1;
    } while (bVar1);
    cVar7 = DAT_INTMEM_42 + DAT_INTMEM_4f;
    DAT_INTMEM_42 = cVar7;
  }
  return cVar7;
}



// ==== FUN_CODE_0857 @ CODE:0857  (65 bytes)

char FUN_CODE_0857(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  pbVar3 = &DAT_EXTMEM_0025;
  FUN_CODE_3b56(DAT_INTMEM_37,DAT_INTMEM_38);
  DAT_INTMEM_44 = *pbVar3;
  if (DAT_INTMEM_44 < 0x30) {
    DAT_INTMEM_44 = 0x3f;
  }
  bVar1 = DAT_INTMEM_44;
  if (_2_3 == '\0') {
    _2_4 = 0;
  }
  else {
    _2_5 = 0;
  }
  bVar2 = DAT_INTMEM_44 - 0x30;
  if (0xf < DAT_INTMEM_44 - 0x30) {
    bVar2 = DAT_INTMEM_44 - 0x40;
    if (_2_3 == '\0') {
      _2_4 = 1;
    }
    else {
      _2_5 = 1;
    }
  }
  DAT_INTMEM_44 = bVar2;
  return bVar1 - 0x40;
}



// ==== FUN_CODE_0898 @ CODE:0898  (75 bytes)

void FUN_CODE_0898(void)

{
  undefined1 *puVar1;
  
  if (DAT_INTMEM_45 == '\x04') {
    _2_1 = 1;
    DAT_INTMEM_46 = DAT_INTMEM_38 + '\x01';
    DAT_INTMEM_38 = -6;
    DAT_INTMEM_37 = '\0';
  }
  else if ((DAT_INTMEM_45 == '\r') || (DAT_INTMEM_38 == -7 && DAT_INTMEM_37 == '\0')) {
    DAT_INTMEM_46 = '\0';
    DAT_INTMEM_38 = -6;
    DAT_INTMEM_37 = '\0';
  }
  if ((DAT_INTMEM_45 == '\x04') || (DAT_INTMEM_38 == -7 && DAT_INTMEM_37 == '\0')) {
    puVar1 = &DAT_EXTMEM_0219;
    FUN_CODE_3b75(DAT_INTMEM_33);
    *puVar1 = 0xd;
    DAT_INTMEM_33 = DAT_INTMEM_33 + '\x01';
  }
  return;
}



// ==== FUN_CODE_08e3 @ CODE:08e3  (591 bytes)

void FUN_CODE_08e3(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  byte *pbVar9;
  short sVar10;
  
  DAT_INTMEM_5d = DAT_INTMEM_42;
  do {
    if (0x8b < DAT_INTMEM_5d) break;
    puVar7 = &DAT_EXTMEM_0363;
    FUN_CODE_3af8(DAT_INTMEM_5d);
    *puVar7 = 0;
    puVar7[1] = 0;
    bVar1 = DAT_INTMEM_5d != 0xff;
    DAT_INTMEM_5d = DAT_INTMEM_5d + 1;
  } while (bVar1);
  DAT_INTMEM_5c = DAT_INTMEM_42;
  _2_3 = 0;
  DAT_INTMEM_38 = DAT_INTMEM_46;
  DAT_INTMEM_37 = 0;
  DAT_INTMEM_5b = DAT_INTMEM_46 + 1;
  DAT_INTMEM_5d = _2_4 & 1;
  FUN_CODE_0857();
  if ((char)((_2_6 & 1 & _2_1) << 7) < '\0') {
    if (DAT_INTMEM_5d != 0) {
      _2_4 = 1;
    }
    DAT_INTMEM_5d = DAT_INTMEM_5c;
    do {
      if ((DAT_EXTMEM_0354 < DAT_INTMEM_5d) << 7 < '\0') break;
      puVar7 = &DAT_EXTMEM_047b;
      FUN_CODE_3af8(DAT_INTMEM_5d);
      uVar4 = puVar7[1];
      uVar6 = 0;
      puVar7 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_5d);
      *puVar7 = uVar6;
      puVar7[1] = uVar4;
      bVar1 = DAT_INTMEM_5d != 0xff;
      DAT_INTMEM_5d = DAT_INTMEM_5d + 1;
    } while (bVar1);
  }
  DAT_INTMEM_4a = '\0';
  DAT_INTMEM_38 = DAT_INTMEM_5b;
  DAT_INTMEM_37 = '\0';
  do {
    if (DAT_INTMEM_37 != '\0') {
      return;
    }
    if (0xf9 < DAT_INTMEM_38) {
      return;
    }
    pcVar8 = &DAT_EXTMEM_0025;
    FUN_CODE_3b56(-7 - DAT_INTMEM_38);
    DAT_INTMEM_45 = *pcVar8;
    if (DAT_INTMEM_45 == '\x05') {
      FUN_CODE_3b90(0x37);
      _2_7 = _2_4 & 1;
      FUN_CODE_0857();
      bVar3 = _2_7;
      if (_2_4 != 0) {
        bVar3 = _2_7 & 1 ^ 1;
      }
      if (-1 < (char)(bVar3 << 7)) {
        DAT_INTMEM_42 = DAT_INTMEM_42 + 2;
      }
      DAT_INTMEM_47 = DAT_INTMEM_42;
    }
    else {
      if (((char)((_0_2 & 1 ^ 1) << 7) < '\0') && (DAT_INTMEM_45 != '\x04')) {
        pcVar8 = &DAT_EXTMEM_0219;
        FUN_CODE_3b75(DAT_INTMEM_33);
        *pcVar8 = DAT_INTMEM_45;
        DAT_INTMEM_33 = DAT_INTMEM_33 + '\x01';
      }
      if (DAT_INTMEM_45 == '\x03') {
        FUN_CODE_3b90(0x37);
        _2_3 = 1;
        DAT_INTMEM_5d = _2_5 & 1;
        FUN_CODE_0857();
        if ((char)((_2_6 & 1 & _2_1) << 7) < '\0') {
          if (DAT_INTMEM_5d != 0) {
            _2_5 = 1;
          }
          DAT_INTMEM_5d = DAT_INTMEM_5c;
          do {
            if ((DAT_EXTMEM_0354 < DAT_INTMEM_5d) << 7 < '\0') break;
            pbVar9 = &DAT_EXTMEM_047b;
            FUN_CODE_3af8(DAT_INTMEM_5d);
            uVar4 = 0xff;
            uVar6 = 0;
            BANK0_R6 = BANK0_R6 & *pbVar9;
            BANK0_R7 = BANK0_R7 & pbVar9[1];
            pbVar9 = &DAT_EXTMEM_0363;
            FUN_CODE_3af8(DAT_INTMEM_5d);
            BANK0_R6 = BANK0_R6 | *pbVar9;
            BANK0_R7 = BANK0_R7 | pbVar9[1];
            puVar7 = &DAT_EXTMEM_0363;
            FUN_CODE_3af8(DAT_INTMEM_5d);
            *puVar7 = uVar4;
            puVar7[1] = uVar6;
            bVar1 = DAT_INTMEM_5d != 0xff;
            DAT_INTMEM_5d = DAT_INTMEM_5d + 1;
          } while (bVar1);
        }
        DAT_INTMEM_42 = DAT_INTMEM_47;
      }
      else {
        DAT_INTMEM_4a = DAT_INTMEM_4a + '\x01';
        FUN_CODE_0898();
        if ((DAT_INTMEM_37 == '\0') && (DAT_INTMEM_38 + 1 < 0xfa)) {
          puVar7 = &DAT_CODE_3a02;
          FUN_CODE_3ae8(DAT_INTMEM_44,5);
          DAT_EXTMEM_06ab = *puVar7;
          DAT_EXTMEM_06ac = puVar7[1];
          cVar5 = DAT_INTMEM_37;
          if (DAT_INTMEM_38 == 0xff) {
            cVar5 = DAT_INTMEM_37 + '\x01';
          }
          pbVar9 = &DAT_EXTMEM_0025;
          FUN_CODE_3b56(DAT_EXTMEM_06ab,cVar5);
          bVar3 = *pbVar9;
          sVar10 = 0x6ab;
          FUN_CODE_3b3f();
          if (*(byte *)(sVar10 + 2) <= bVar3) {
            pbVar9 = &DAT_EXTMEM_0025;
            FUN_CODE_3b56(bVar3 - *(byte *)(sVar10 + 2),DAT_INTMEM_37);
            bVar3 = *pbVar9;
            sVar10 = 0x6ab;
            FUN_CODE_3b3f();
            if (*(byte *)(sVar10 + 2) <= bVar3) {
              pbVar9 = &DAT_EXTMEM_0025;
              FUN_CODE_3b56(bVar3 - *(byte *)(sVar10 + 2));
              bVar3 = *pbVar9;
              sVar10 = 0x6ab;
              FUN_CODE_3b3f();
              bVar2 = *(char *)(sVar10 + 3) + 1;
              if (bVar3 < bVar2) {
                pbVar9 = &DAT_EXTMEM_0025;
                FUN_CODE_3b56(bVar3 - bVar2,DAT_INTMEM_37,DAT_INTMEM_38);
                bVar3 = *pbVar9;
                sVar10 = 0x6ab;
                FUN_CODE_3b3f();
                if ((bVar3 < *(char *)(sVar10 + 3) + 1U) << 7 < '\0') {
                  DAT_INTMEM_4f = 0;
                  FUN_CODE_06e6();
                  DAT_INTMEM_4a = DAT_INTMEM_4a + -1;
                  goto LAB_CODE_0af2;
                }
              }
            }
          }
          DAT_INTMEM_4f = DAT_INTMEM_5a;
          FUN_CODE_06e6();
        }
      }
    }
LAB_CODE_0af2:
    DAT_INTMEM_5d = 0;
    do {
      if (0x8b < DAT_INTMEM_5d) break;
      puVar7 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_5d);
      uVar4 = *puVar7;
      uVar6 = puVar7[1];
      puVar7 = &DAT_EXTMEM_047b;
      FUN_CODE_3af8(DAT_INTMEM_5d);
      *puVar7 = uVar4;
      puVar7[1] = uVar6;
      bVar1 = DAT_INTMEM_5d != 0xff;
      DAT_INTMEM_5d = DAT_INTMEM_5d + 1;
    } while (bVar1);
    bVar1 = 0xfe < DAT_INTMEM_38;
    cVar5 = bVar1 << 7;
    DAT_INTMEM_38 = DAT_INTMEM_38 + 1;
    if (bVar1) {
      DAT_INTMEM_37 = DAT_INTMEM_37 + '\x01';
      cVar5 = '\0';
    }
    if (cVar5 < '\0') {
      return;
    }
  } while( true );
}



// ==== FUN_CODE_0b32 @ CODE:0b32  (222 bytes)

char FUN_CODE_0b32(void)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  DAT_INTMEM_4f = 0;
  do {
    pbVar4 = &DAT_CODE_3824;
    FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
    if ((*pbVar4 < DAT_INTMEM_4f) << 7 < '\0') break;
    puVar5 = &DAT_EXTMEM_0363;
    FUN_CODE_3af8(DAT_INTMEM_4f);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = &DAT_EXTMEM_047b;
    FUN_CODE_3af8(DAT_INTMEM_4f);
    *puVar5 = uVar3;
    puVar5[1] = uVar2;
    bVar1 = DAT_INTMEM_4f != 0xff;
    DAT_INTMEM_4f = DAT_INTMEM_4f + 1;
  } while (bVar1);
  DAT_INTMEM_50 = 0;
  pcVar6 = &DAT_CODE_3824;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
  DAT_INTMEM_4f = *pcVar6;
  while( true ) {
    DAT_INTMEM_4f = DAT_INTMEM_4f + -1;
    pcVar6 = &DAT_EXTMEM_0363;
    FUN_CODE_3af8(DAT_INTMEM_4f);
    if ((pcVar6[1] != '\0' || *pcVar6 != '\0') || (DAT_INTMEM_4f == '\0')) break;
    DAT_INTMEM_50 = DAT_INTMEM_50 + 1;
  }
  DAT_INTMEM_4f = 0;
  do {
    if ((DAT_INTMEM_50 / 2 != 0xff) && (DAT_INTMEM_50 / 2 + 2 <= DAT_INTMEM_4f)) break;
    puVar5 = &DAT_EXTMEM_0363;
    FUN_CODE_3af8(DAT_INTMEM_4f,DAT_INTMEM_50 % 2);
    *puVar5 = 0;
    puVar5[1] = 0;
    bVar1 = DAT_INTMEM_4f != 0xff;
    DAT_INTMEM_4f = DAT_INTMEM_4f + 1;
  } while (bVar1);
  DAT_INTMEM_4f = 0;
  do {
    pbVar4 = &DAT_CODE_3824;
    FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
    if ((*pbVar4 < DAT_INTMEM_4f) << 7 < '\0') {
      return *pbVar4 - DAT_INTMEM_4f;
    }
    puVar5 = &DAT_EXTMEM_047b;
    FUN_CODE_3af8(DAT_INTMEM_4f);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = &DAT_EXTMEM_0363;
    FUN_CODE_000e(DAT_INTMEM_50 % 2,CARRY1(DAT_INTMEM_4f,DAT_INTMEM_50 / 2),
                  DAT_INTMEM_4f + DAT_INTMEM_50 / 2);
    *puVar5 = uVar3;
    puVar5[1] = uVar2;
    bVar1 = DAT_INTMEM_4f != 0xff;
    DAT_INTMEM_4f = DAT_INTMEM_4f + 1;
  } while (bVar1);
  return '\0';
}



// ==== FUN_CODE_0c10 @ CODE:0c10  (951 bytes)

/* WARNING: Removing unreachable block (CODE,0x0efa) */
/* WARNING: Removing unreachable block (CODE,0x0f00) */
/* WARNING: Removing unreachable block (CODE,0x0f43) */
/* WARNING: Removing unreachable block (CODE,0x0fce) */
/* WARNING: Removing unreachable block (CODE,0x0fd3) */
/* WARNING: Removing unreachable block (CODE,0x0fd4) */
/* WARNING: Removing unreachable block (CODE,0x0fe6) */
/* WARNING: Removing unreachable block (CODE,0x0fea) */
/* WARNING: Removing unreachable block (CODE,0x1011) */
/* WARNING: Removing unreachable block (CODE,0x1012) */
/* WARNING: Removing unreachable block (CODE,0x101b) */
/* WARNING: Removing unreachable block (CODE,0x101c) */
/* WARNING: Removing unreachable block (CODE,0x1032) */
/* WARNING: Removing unreachable block (CODE,0x1033) */
/* WARNING: Removing unreachable block (CODE,0x103c) */
/* WARNING: Removing unreachable block (CODE,0x103d) */
/* WARNING: Removing unreachable block (CODE,0x1050) */

byte FUN_CODE_0c10(byte param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  
  if (_2_3 == '\0') {
    DAT_INTMEM_5f = 0;
    DAT_INTMEM_5e = DAT_EXTMEM_0354;
    while( true ) {
      DAT_INTMEM_5e = DAT_INTMEM_5e - 1;
      pcVar7 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_5e);
      if ((pcVar7[1] != '\0' || *pcVar7 != '\0') || (DAT_INTMEM_5e == 0)) break;
      DAT_INTMEM_5f = DAT_INTMEM_5f + 1;
    }
    bVar5 = 0;
    DAT_INTMEM_60 = DAT_INTMEM_5f;
    if (DAT_INTMEM_4a != 0) {
      DAT_INTMEM_60 = DAT_INTMEM_5f / DAT_INTMEM_4a;
      bVar5 = DAT_INTMEM_5f % DAT_INTMEM_4a;
    }
    if (DAT_INTMEM_60 == 0) {
      DAT_INTMEM_60 = 1;
    }
    if (6 < DAT_INTMEM_60) {
      DAT_INTMEM_60 = 6;
    }
    DAT_INTMEM_5a = DAT_INTMEM_60;
    FUN_CODE_08e3(bVar5,0);
    DAT_INTMEM_5f = 0;
    DAT_INTMEM_5e = DAT_EXTMEM_0354;
    while( true ) {
      DAT_INTMEM_5e = DAT_INTMEM_5e - 1;
      pcVar7 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_5e);
      if ((pcVar7[1] != '\0' || *pcVar7 != '\0') || (DAT_INTMEM_5e == 0)) break;
      DAT_INTMEM_5f = DAT_INTMEM_5f + 1;
    }
    DAT_INTMEM_5e = 0;
    do {
      if ((DAT_INTMEM_5f / 2 != 0xff) && (DAT_INTMEM_5f / 2 + 2 <= DAT_INTMEM_5e)) break;
      puVar9 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_5f % 2);
      *puVar9 = 0;
      puVar9[1] = 0;
      bVar1 = DAT_INTMEM_5e != 0xff;
      DAT_INTMEM_5e = DAT_INTMEM_5e + 1;
    } while (bVar1);
    DAT_INTMEM_5e = DAT_INTMEM_47;
    do {
      if ((DAT_INTMEM_5f / 2 <= DAT_EXTMEM_0354) &&
         (bVar5 = (DAT_EXTMEM_0354 - DAT_INTMEM_5f / 2) + 1, bVar5 <= DAT_INTMEM_5e)) {
        return DAT_INTMEM_5e - bVar5;
      }
      puVar9 = &DAT_EXTMEM_047b;
      FUN_CODE_3af8(DAT_INTMEM_5e,DAT_INTMEM_5f % 2);
      uVar3 = *puVar9;
      uVar4 = puVar9[1];
      puVar9 = &DAT_EXTMEM_0363;
      FUN_CODE_000e(DAT_INTMEM_5f % 2,CARRY1(DAT_INTMEM_5e,DAT_INTMEM_5f / 2),
                    DAT_INTMEM_5e + DAT_INTMEM_5f / 2);
      *puVar9 = uVar3;
      puVar9[1] = uVar4;
      bVar1 = DAT_INTMEM_5e != 0xff;
      bVar5 = DAT_INTMEM_5e + 1;
      DAT_INTMEM_5e = bVar5;
    } while (bVar1);
  }
  else {
    DAT_INTMEM_5a = 1;
    bVar5 = FUN_CODE_08e3();
    if (_2_4 == '\x01') {
      DAT_INTMEM_5f = 0;
      DAT_INTMEM_5e = DAT_EXTMEM_0354;
      while( true ) {
        DAT_INTMEM_5e = DAT_INTMEM_5e - 1;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_3af8(DAT_INTMEM_5e);
        if ((puVar9[1] != '\0') || (DAT_INTMEM_5e == 0)) break;
        DAT_INTMEM_5f = DAT_INTMEM_5f + 1;
      }
      DAT_INTMEM_5e = DAT_INTMEM_47;
      do {
        if ((DAT_EXTMEM_0354 - 1 < DAT_INTMEM_5e) << 7 < '\0') break;
        pbVar8 = &DAT_EXTMEM_0363;
        FUN_CODE_3af8(DAT_INTMEM_5e);
        uVar3 = 0xff;
        uVar4 = 0;
        BANK0_R6 = BANK0_R6 & *pbVar8;
        BANK0_R7 = BANK0_R7 & pbVar8[1];
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_3af8(DAT_INTMEM_5e);
        *puVar9 = uVar3;
        puVar9[1] = uVar4;
        bVar1 = DAT_INTMEM_5e != 0xff;
        DAT_INTMEM_5e = DAT_INTMEM_5e + 1;
      } while (bVar1);
      DAT_INTMEM_5e = DAT_INTMEM_47;
      do {
        if ((DAT_INTMEM_5f / 2 <= DAT_EXTMEM_0354) &&
           (bVar2 = (DAT_EXTMEM_0354 - DAT_INTMEM_5f / 2) + 1, bVar5 = DAT_INTMEM_5e - bVar2,
           bVar2 <= DAT_INTMEM_5e)) break;
        pbVar8 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(DAT_INTMEM_5f % 2,CARRY1(DAT_INTMEM_5e,DAT_INTMEM_5f / 2),
                      DAT_INTMEM_5e + DAT_INTMEM_5f / 2);
        bVar5 = *pbVar8;
        bVar2 = pbVar8[1];
        puVar9 = &DAT_EXTMEM_047b;
        FUN_CODE_3af8(DAT_INTMEM_5e);
        param_1 = puVar9[1];
        uVar3 = 0;
        BANK0_R5 = BANK0_R5 | bVar5;
        BANK0_R2 = BANK0_R2 | bVar2;
        BANK0_R7 = DAT_INTMEM_5e + DAT_INTMEM_5f / 2;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(DAT_INTMEM_5f % 2,CARRY1(DAT_INTMEM_5e,DAT_INTMEM_5f / 2));
        *puVar9 = uVar3;
        puVar9[1] = param_1;
        bVar1 = DAT_INTMEM_5e != 0xff;
        bVar5 = DAT_INTMEM_5e + 1;
        DAT_INTMEM_5e = bVar5;
      } while (bVar1);
    }
    if (_2_5 == '\x01') {
      _3_0 = 1;
      DAT_INTMEM_36 = DAT_INTMEM_47;
      DAT_INTMEM_35 = '\0';
      do {
        if ((DAT_INTMEM_35 != '\0') || ((DAT_EXTMEM_0354 < DAT_INTMEM_36) << 7 < '\0')) break;
        pbVar8 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(DAT_EXTMEM_0354 - DAT_INTMEM_36,0,DAT_INTMEM_36);
        param_1 = *pbVar8;
        param_2 = pbVar8[1];
        BANK0_R4 = BANK0_R4 & param_1;
        BANK0_R5 = BANK0_R5 & param_2;
        _3_0 = 0;
        bVar1 = 0xfe < DAT_INTMEM_36;
        cVar6 = bVar1 << 7;
        DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
        if (bVar1) {
          DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
          cVar6 = '\0';
        }
      } while (-1 < cVar6);
      DAT_INTMEM_5f = 0;
      DAT_INTMEM_5e = DAT_EXTMEM_0354 - 1;
      pbVar8 = &DAT_EXTMEM_0363;
      FUN_CODE_3af8(DAT_INTMEM_5e);
      BANK0_R6 = BANK0_R6 & *pbVar8;
      BANK0_R7 = BANK0_R7 & pbVar8[1];
      DAT_INTMEM_5e = DAT_INTMEM_47;
      do {
        if ((DAT_EXTMEM_0354 - 1 < DAT_INTMEM_5e) << 7 < '\0') break;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_3af8(DAT_INTMEM_5e);
        uVar3 = puVar9[1];
        uVar4 = 0;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_3af8(DAT_INTMEM_5e);
        *puVar9 = uVar4;
        puVar9[1] = uVar3;
        bVar1 = DAT_INTMEM_5e != 0xff;
        DAT_INTMEM_5e = DAT_INTMEM_5e + 1;
      } while (bVar1);
      DAT_INTMEM_5e = DAT_INTMEM_47;
      do {
        if ((DAT_INTMEM_5f / 2 <= DAT_EXTMEM_0354) &&
           (bVar5 = (DAT_EXTMEM_0354 - DAT_INTMEM_5f / 2) + 1, bVar5 <= DAT_INTMEM_5e)) {
          return DAT_INTMEM_5e - bVar5;
        }
        FUN_CODE_3af8(DAT_INTMEM_5e,DAT_INTMEM_5f % 2);
        BANK0_R6 = CARRY1(DAT_INTMEM_5e,DAT_INTMEM_5f / 2);
        BANK0_R7 = DAT_INTMEM_5e + DAT_INTMEM_5f / 2;
        BANK0_R2 = 0;
        BANK0_R3 = 0xff;
        pbVar8 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(DAT_INTMEM_5f % 2);
        BANK0_R3 = BANK0_R3 | *pbVar8;
        BANK0_R2 = BANK0_R2 | pbVar8[1];
        pbVar8 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(DAT_INTMEM_5f % 2,CARRY1(DAT_INTMEM_5e,DAT_INTMEM_5f / 2),
                      DAT_INTMEM_5e + DAT_INTMEM_5f / 2);
        *pbVar8 = param_2;
        pbVar8[1] = param_1;
        bVar1 = DAT_INTMEM_5e != 0xff;
        bVar5 = DAT_INTMEM_5e + 1;
        DAT_INTMEM_5e = bVar5;
      } while (bVar1);
    }
  }
  return bVar5;
}



// ==== thunk_FUN_CODE_1056 @ CODE:1054  (2 bytes)

byte thunk_FUN_CODE_1056(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  
  FUN_CODE_3b7e(0x3a50,0x4b);
  _1_4 = 0;
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = 0;
  do {
    bVar3 = DAT_INTMEM_35 - (((DAT_INTMEM_50 < DAT_INTMEM_36) << 7) >> 7);
    if (DAT_INTMEM_4f < bVar3) {
      return DAT_INTMEM_4f - bVar3;
    }
    DAT_INTMEM_61 = DAT_INTMEM_4b;
    DAT_INTMEM_62 = DAT_INTMEM_4c;
    DAT_INTMEM_63 = 0xd;
    cVar2 = -1;
    bVar3 = 0xff;
    FUN_CODE_0003(DAT_INTMEM_4b,DAT_INTMEM_4c);
    DAT_INTMEM_64 = cVar2;
    DAT_INTMEM_65 = bVar3;
    FUN_CODE_3a87();
    DAT_INTMEM_39 = cVar2;
    DAT_INTMEM_3a = bVar3;
    if ((bVar3 == 0xff) && (cVar2 == -1)) {
      _1_4 = 1;
      FUN_CODE_3b7e(0x3a50,0x4b);
      DAT_INTMEM_3a = 1;
      DAT_INTMEM_39 = '\0';
      DAT_INTMEM_36 = DAT_INTMEM_50 + 1;
      DAT_INTMEM_35 = DAT_INTMEM_4f;
      if (DAT_INTMEM_36 == 0) {
        DAT_INTMEM_35 = DAT_INTMEM_4f + 1;
      }
    }
    bVar3 = DAT_INTMEM_4c + DAT_INTMEM_3a;
    DAT_INTMEM_4b =
         DAT_INTMEM_4b + (DAT_INTMEM_39 - ((CARRY1(DAT_INTMEM_4c,DAT_INTMEM_3a) << 7) >> 7));
    DAT_INTMEM_4c = bVar3 + 2;
    if (0xfd < bVar3) {
      DAT_INTMEM_4b = DAT_INTMEM_4b + '\x01';
    }
    DAT_INTMEM_3a = 0;
    DAT_INTMEM_39 = '\0';
    while( true ) {
      pcVar4 = (char *)CONCAT11(DAT_INTMEM_4b,DAT_INTMEM_4c);
      FUN_CODE_3b56(DAT_INTMEM_39,DAT_INTMEM_3a);
      if (*pcVar4 != 'A') break;
      FUN_CODE_3b90(0x39);
    }
    cVar2 = '\x03';
    if ((DAT_INTMEM_39 != '\0') || (cVar2 = '\x03' - DAT_INTMEM_3a, 3 < DAT_INTMEM_3a)) {
      _1_4 = 1;
      FUN_CODE_3b7e(cVar2,0x3a50,0x4b);
      DAT_INTMEM_36 = DAT_INTMEM_50 + 1;
      DAT_INTMEM_35 = DAT_INTMEM_4f;
      if (DAT_INTMEM_36 == 0) {
        DAT_INTMEM_35 = DAT_INTMEM_4f + 1;
      }
    }
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar2 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    bVar3 = DAT_INTMEM_36;
    if (bVar1) {
      bVar3 = DAT_INTMEM_35 + 1;
      cVar2 = '\0';
      DAT_INTMEM_35 = bVar3;
    }
  } while (-1 < cVar2);
  return bVar3;
}



// ==== FUN_CODE_1056 @ CODE:1056  (211 bytes)

byte FUN_CODE_1056(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  
  FUN_CODE_3b7e(0x3a50,0x4b);
  _1_4 = 0;
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = 0;
  do {
    bVar3 = DAT_INTMEM_35 - (((DAT_INTMEM_50 < DAT_INTMEM_36) << 7) >> 7);
    if (DAT_INTMEM_4f < bVar3) {
      return DAT_INTMEM_4f - bVar3;
    }
    DAT_INTMEM_61 = DAT_INTMEM_4b;
    DAT_INTMEM_62 = DAT_INTMEM_4c;
    DAT_INTMEM_63 = 0xd;
    cVar2 = -1;
    bVar3 = 0xff;
    FUN_CODE_0003(DAT_INTMEM_4b,DAT_INTMEM_4c);
    DAT_INTMEM_64 = cVar2;
    DAT_INTMEM_65 = bVar3;
    FUN_CODE_3a87();
    DAT_INTMEM_39 = cVar2;
    DAT_INTMEM_3a = bVar3;
    if ((bVar3 == 0xff) && (cVar2 == -1)) {
      _1_4 = 1;
      FUN_CODE_3b7e(0x3a50,0x4b);
      DAT_INTMEM_3a = 1;
      DAT_INTMEM_39 = '\0';
      DAT_INTMEM_36 = DAT_INTMEM_50 + 1;
      DAT_INTMEM_35 = DAT_INTMEM_4f;
      if (DAT_INTMEM_36 == 0) {
        DAT_INTMEM_35 = DAT_INTMEM_4f + 1;
      }
    }
    bVar3 = DAT_INTMEM_4c + DAT_INTMEM_3a;
    DAT_INTMEM_4b =
         DAT_INTMEM_4b + (DAT_INTMEM_39 - ((CARRY1(DAT_INTMEM_4c,DAT_INTMEM_3a) << 7) >> 7));
    DAT_INTMEM_4c = bVar3 + 2;
    if (0xfd < bVar3) {
      DAT_INTMEM_4b = DAT_INTMEM_4b + '\x01';
    }
    DAT_INTMEM_3a = 0;
    DAT_INTMEM_39 = '\0';
    while( true ) {
      pcVar4 = (char *)CONCAT11(DAT_INTMEM_4b,DAT_INTMEM_4c);
      FUN_CODE_3b56(DAT_INTMEM_39,DAT_INTMEM_3a);
      if (*pcVar4 != 'A') break;
      FUN_CODE_3b90(0x39);
    }
    cVar2 = '\x03';
    if ((DAT_INTMEM_39 != '\0') || (cVar2 = '\x03' - DAT_INTMEM_3a, 3 < DAT_INTMEM_3a)) {
      _1_4 = 1;
      FUN_CODE_3b7e(cVar2,0x3a50,0x4b);
      DAT_INTMEM_36 = DAT_INTMEM_50 + 1;
      DAT_INTMEM_35 = DAT_INTMEM_4f;
      if (DAT_INTMEM_36 == 0) {
        DAT_INTMEM_35 = DAT_INTMEM_4f + 1;
      }
    }
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar2 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    bVar3 = DAT_INTMEM_36;
    if (bVar1) {
      bVar3 = DAT_INTMEM_35 + 1;
      cVar2 = '\0';
      DAT_INTMEM_35 = bVar3;
    }
  } while (-1 < cVar2);
  return bVar3;
}



// ==== hw_init @ CODE:1129  (507 bytes)

void hw_init(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  TMOD = 0x21;
  TCON = 0x50;
  SCON = 0xd8;
  TL1 = 0;
  TH1 = 0xe6;
  TL0 = 0xc;
  TH0 = 0xfe;
  IP = 0;
  PCON = 0x80;
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = '\0';
  do {
    if ((DAT_INTMEM_35 != '\0') || ((6 < DAT_INTMEM_36) << 7 < '\0')) break;
    *(undefined1 *)(DAT_INTMEM_36 + 0x24) = 0x20;
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar6 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    if (bVar1) {
      DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
      cVar6 = '\0';
    }
  } while (-1 < cVar6);
  DAT_EXTMEM_000b = 0;
  DAT_EXTMEM_000c = 0;
  DAT_EXTMEM_0011 = 0;
  DAT_EXTMEM_0012 = 0;
  DAT_EXTMEM_0015 = 0;
  DAT_EXTMEM_0016 = 0;
  DAT_EXTMEM_001b = 0;
  DAT_EXTMEM_001c = 0;
  DAT_EXTMEM_0021 = 0;
  DAT_EXTMEM_0022 = 0;
  DAT_INTMEM_29 = 0xd;
  LATCH1_ES_FP2800 = 0;
  LATCH0_EZ_row_color_LED_bank = 0;
  _1_7 = 0;
  T0 = 1;
  _1_5 = 0;
  DAT_INTMEM_43 = 0;
  DAT_EXTMEM_0360 = 0;
  _2_2 = 0;
  DAT_INTMEM_38 = 0;
  DAT_INTMEM_37 = 0;
  _2_3 = 0;
  _2_5 = 0;
  _2_4 = 0;
  _2_6 = 0;
  DAT_INTMEM_44 = 2;
  _2_1 = 0;
  DAT_INTMEM_41 = 0;
  DAT_INTMEM_40 = 0;
  DAT_INTMEM_2e = 0;
  DAT_INTMEM_34 = 0;
  _0_4 = 0;
  _0_5 = 0;
  DAT_INTMEM_33 = 0;
  _0_2 = 1;
  DAT_INTMEM_32 = 0;
  DAT_INTMEM_31 = 0;
  _0_1 = 0;
  _0_6 = 1;
  _1_0 = 0;
  DAT_INTMEM_2f = 0xff;
  _1_2 = 0;
  _1_3 = 0;
  _1_4 = 0;
  DAT_INTMEM_47 = 0;
  DAT_INTMEM_42 = 0;
  DAT_EXTMEM_035f = 0;
  DAT_INTMEM_48 = 0;
  _0_0 = 0;
  DAT_EXTMEM_0356 = 0x16;
  DAT_EXTMEM_0357 = 0;
  DAT_INTMEM_2b = 0x2f;
  DAT_INTMEM_2c = 0xff;
  DAT_EXTMEM_0358 = 0xff;
  DAT_EXTMEM_0359 = 0xff;
  _1_1 = 0;
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = '\0';
  do {
    if ((DAT_INTMEM_35 != '\0') || ((0xf9 < DAT_INTMEM_36) << 7 < '\0')) break;
    puVar7 = &DAT_EXTMEM_011f;
    FUN_CODE_3b56(-7 - DAT_INTMEM_36);
    *puVar7 = 0xd;
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar6 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    if (bVar1) {
      DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
      cVar6 = '\0';
    }
  } while (-1 < cVar6);
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = '\0';
  do {
    if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
    puVar7 = &DAT_EXTMEM_0363;
    FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7 = &DAT_EXTMEM_047b;
    FUN_CODE_000e();
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7 = &DAT_EXTMEM_0593;
    FUN_CODE_000e();
    *puVar7 = 0;
    puVar7[1] = 0;
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar6 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    if (bVar1) {
      DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
      cVar6 = '\0';
    }
  } while (-1 < cVar6);
  bVar2 = P1;
  bVar3 = P1;
  bVar4 = P1;
  bVar5 = P1;
  DAT_INTMEM_3d = ~bVar5 & 8 | (~bVar4 & 2) << 1 | (~bVar3 & 4) >> 1 | ~bVar2 & 1;
  puVar7 = &DAT_CODE_3824;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
  BANK0_R4 = *puVar7;
  pcVar8 = &DAT_CODE_3826;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
  DAT_EXTMEM_0354 = param_1 + *pcVar8;
  puVar7 = &DAT_CODE_3825;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
  DAT_EXTMEM_0355 = *puVar7;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0x3822,0xe);
  FUN_CODE_3b7e(0x4d);
  puVar7 = &DAT_CODE_382d;
  FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
  DAT_INTMEM_24 = *puVar7;
  DAT_INTMEM_36 = 0;
  DAT_INTMEM_35 = '\0';
  while( true ) {
    if (DAT_INTMEM_35 != '\0') {
      return;
    }
    if ((0x40 < DAT_INTMEM_36) << 7 < '\0') break;
    puVar7 = &DAT_EXTMEM_0219;
    FUN_CODE_3b56('@' - DAT_INTMEM_36);
    *puVar7 = 0x20;
    bVar1 = 0xfe < DAT_INTMEM_36;
    cVar6 = bVar1 << 7;
    DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
    if (bVar1) {
      DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
      cVar6 = '\0';
    }
    if (cVar6 < '\0') {
      return;
    }
  }
  return;
}



// ==== FUN_CODE_136f @ CODE:136f  (2509 bytes)

/* WARNING: Removing unreachable block (CODE,0x14e4) */
/* WARNING: Removing unreachable block (CODE,0x1502) */
/* WARNING: Removing unreachable block (CODE,0x1505) */
/* WARNING: Removing unreachable block (CODE,0x1511) */
/* WARNING: Removing unreachable block (CODE,0x1517) */
/* WARNING: Removing unreachable block (CODE,0x1526) */
/* WARNING: Removing unreachable block (CODE,0x153c) */
/* WARNING: Removing unreachable block (CODE,0x1550) */
/* WARNING: Removing unreachable block (CODE,0x1558) */
/* WARNING: Removing unreachable block (CODE,0x155c) */

void FUN_CODE_136f(void)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  undefined1 *puVar6;
  char cVar7;
  char *pcVar8;
  undefined1 *puVar9;
  
  IE = 0;
  hw_init();
  IE = 0x82;
  FUN_CODE_052e();
  IE = 0x92;
  do {
    if ((char)(((_0_4 & 1 ^ 1) & _0_1) << 7) < '\0') {
      DAT_EXTMEM_0358 = 0xff;
      DAT_EXTMEM_0359 = 0xff;
      _0_1 = 0;
      if (_0_6 == '\0') {
        cVar7 = LATCH3_7SEG_802_15;
        cVar2 = LATCH4_802_15;
        if ((DAT_EXTMEM_000c != cVar2) || (DAT_EXTMEM_000b != cVar7)) {
          LATCH3_7SEG_802_15 = DAT_EXTMEM_000b;
          LATCH4_802_15 = DAT_EXTMEM_000c;
          _2_1 = 0;
          _2_2 = 1;
          DAT_EXTMEM_000d = LATCH3_7SEG_802_15;
          DAT_EXTMEM_000e = LATCH4_802_15;
          BANK0_R4 = BANK0_R4 ^ 0xff;
          BANK0_R5 = BANK0_R5 ^ 0xff;
        }
        if ((DAT_EXTMEM_0012 != DAT_EXTMEM_0010) || (DAT_EXTMEM_0011 != DAT_EXTMEM_000f)) {
          DAT_EXTMEM_000f = DAT_EXTMEM_0011;
          DAT_EXTMEM_0010 = DAT_EXTMEM_0012;
          _2_1 = 0;
          _2_2 = 1;
          BANK0_R4 = BANK0_R4 ^ 0xff;
          BANK0_R5 = BANK0_R5 ^ 0xff;
          DAT_EXTMEM_0013 = DAT_EXTMEM_0011;
          DAT_EXTMEM_0014 = DAT_EXTMEM_0012;
        }
        cVar7 = LATCH5;
        cVar2 = LATCH6_802_15;
        if ((DAT_EXTMEM_0016 != cVar2) || (DAT_EXTMEM_0015 != cVar7)) {
          LATCH5 = DAT_EXTMEM_0015;
          LATCH6_802_15 = DAT_EXTMEM_0016;
          _2_1 = 0;
          _2_2 = 1;
          DAT_EXTMEM_0017 = LATCH5;
          DAT_EXTMEM_0018 = LATCH6_802_15;
          BANK0_R4 = BANK0_R4 ^ 0xff;
          BANK0_R5 = BANK0_R5 ^ 0xff;
        }
        if ((DAT_EXTMEM_001c != DAT_EXTMEM_001a) || (DAT_EXTMEM_001b != DAT_EXTMEM_0019)) {
          DAT_EXTMEM_0019 = DAT_EXTMEM_001b;
          DAT_EXTMEM_001a = DAT_EXTMEM_001c;
          _2_1 = 0;
          _2_2 = 1;
          BANK0_R4 = BANK0_R4 ^ 0xff;
          BANK0_R5 = BANK0_R5 ^ 0xff;
          DAT_EXTMEM_001d = DAT_EXTMEM_001b;
          DAT_EXTMEM_001e = DAT_EXTMEM_001c;
        }
        if ((DAT_EXTMEM_0022 != DAT_EXTMEM_0020) || (DAT_EXTMEM_0021 != DAT_EXTMEM_001f)) {
          DAT_EXTMEM_001f = DAT_EXTMEM_0021;
          DAT_EXTMEM_0020 = DAT_EXTMEM_0022;
          _2_1 = 0;
          _2_2 = 1;
          BANK0_R4 = BANK0_R4 ^ 0xff;
          BANK0_R5 = BANK0_R5 ^ 0xff;
          DAT_EXTMEM_0023 = DAT_EXTMEM_0021;
          DAT_EXTMEM_0024 = DAT_EXTMEM_0022;
        }
      }
      else {
        _2_1 = 0;
      }
      if (_0_7 != '\0') {
        if (((char)((_2_2 & 1 ^ 1) << 7) < '\0') &&
           ((((DAT_INTMEM_3e != '\0' || (1 < DAT_INTMEM_3f)) && ((char)((_2_1 & 1 ^ 1) << 7) < '\0')
             ) && (DAT_INTMEM_3d == -1)))) {
          _2_2 = 1;
        }
        _0_7 = '\0';
        if (DAT_INTMEM_3f == 0 && DAT_INTMEM_3e == '\0') {
          DAT_INTMEM_3e = DAT_EXTMEM_0356;
          DAT_INTMEM_3f = DAT_EXTMEM_0357;
        }
      }
      DAT_INTMEM_2e = 0;
    }
    if (_2_2 == 1) {
      _2_2 = 0;
      DAT_INTMEM_42 = 0;
      DAT_INTMEM_47 = 0;
      DAT_INTMEM_40 = 5;
      DAT_INTMEM_41 = 0xdc;
      DAT_INTMEM_46 = 0;
      _0_5 = 1;
      DAT_INTMEM_36 = 0;
      DAT_INTMEM_35 = '\0';
      do {
        if ((DAT_INTMEM_35 != '\0') || ((0x40 < DAT_INTMEM_36) << 7 < '\0')) break;
        puVar9 = &DAT_EXTMEM_0219;
        FUN_CODE_3b56('@' - DAT_INTMEM_36);
        *puVar9 = 0x20;
        bVar1 = 0xfe < DAT_INTMEM_36;
        cVar7 = bVar1 << 7;
        DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
        if (bVar1) {
          DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
          cVar7 = '\0';
        }
      } while (-1 < cVar7);
      DAT_INTMEM_33 = '\0';
      cVar7 = LATCH3_7SEG_802_15;
      bVar5 = LATCH4_802_15;
      DAT_INTMEM_50 = bVar5 - 0x18;
      DAT_INTMEM_4f = cVar7 + ('\x03' - (((0x17 < bVar5) << 7) >> 7));
      thunk_FUN_CODE_1056();
      DAT_INTMEM_36 = 0;
      DAT_INTMEM_35 = 0;
      do {
        bVar4 = DAT_INTMEM_36;
        bVar5 = DAT_INTMEM_35;
        if ((DAT_INTMEM_35 != 0) || ((4 < DAT_INTMEM_36) << 7 < '\0')) break;
        *(undefined1 *)(DAT_INTMEM_36 + 0x24) = 0x20;
        bVar1 = 0xfe < DAT_INTMEM_36;
        cVar7 = bVar1 << 7;
        DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
        if (bVar1) {
          DAT_INTMEM_35 = DAT_INTMEM_35 + 1;
          cVar7 = '\0';
        }
      } while (-1 < cVar7);
      DAT_INTMEM_29 = 0xd;
      DAT_INTMEM_61 = DAT_INTMEM_4b;
      DAT_INTMEM_62 = DAT_INTMEM_4c;
      DAT_INTMEM_63 = 0xd;
      DAT_INTMEM_65 = 0xfa;
      DAT_INTMEM_64 = 0;
      FUN_CODE_3a87();
      DAT_INTMEM_37 = bVar5;
      DAT_INTMEM_38 = bVar4;
      if ((bVar4 == 0xff) && (bVar5 == 0xff)) {
        DAT_INTMEM_38 = 0xf9;
        DAT_INTMEM_37 = 0;
      }
      DAT_INTMEM_61 = DAT_INTMEM_4b;
      DAT_INTMEM_62 = DAT_INTMEM_4c;
      DAT_INTMEM_63 = 5;
      DAT_INTMEM_64 = DAT_INTMEM_37;
      DAT_INTMEM_65 = DAT_INTMEM_38;
      FUN_CODE_3a87();
      DAT_INTMEM_39 = bVar5;
      DAT_INTMEM_3a = bVar4;
      if ((bVar4 == 0xff) && (bVar5 == 0xff)) {
        DAT_INTMEM_61 = DAT_INTMEM_4b;
        DAT_INTMEM_62 = DAT_INTMEM_4c;
        DAT_INTMEM_63 = 3;
        DAT_INTMEM_64 = DAT_INTMEM_37;
        DAT_INTMEM_65 = DAT_INTMEM_38;
        FUN_CODE_3a87();
        if (bVar5 == 0) {
          DAT_INTMEM_39 = 0;
          DAT_INTMEM_3a = bVar4;
          if (bVar4 < 7) goto LAB_CODE_17e7;
        }
        DAT_INTMEM_39 = 0xff;
        DAT_INTMEM_3a = 0xff;
      }
LAB_CODE_17e7:
      bVar5 = DAT_INTMEM_3a;
      if ((DAT_INTMEM_3a == 0xff) && (bVar5 = DAT_INTMEM_39, DAT_INTMEM_39 == 0xff)) {
        DAT_INTMEM_61 = DAT_INTMEM_4b;
        DAT_INTMEM_62 = DAT_INTMEM_4c;
        DAT_INTMEM_63 = 0xd;
        DAT_INTMEM_65 = DAT_INTMEM_38 + 1;
        DAT_INTMEM_64 = DAT_INTMEM_37;
        if (DAT_INTMEM_65 == 0) {
          DAT_INTMEM_64 = DAT_INTMEM_37 + 1;
        }
        FUN_CODE_3a87();
        bVar5 = 6;
        if (DAT_INTMEM_39 == 0) {
          bVar5 = 6 - DAT_INTMEM_3a;
          DAT_INTMEM_39 = 0;
          if (DAT_INTMEM_3a < 7) goto LAB_CODE_181f;
        }
        DAT_INTMEM_39 = 0xff;
        DAT_INTMEM_3a = 0xff;
      }
LAB_CODE_181f:
      FUN_CODE_3b90(bVar5,0x39);
      DAT_INTMEM_36 = 1;
      DAT_INTMEM_35 = 0;
      while (bVar5 = DAT_INTMEM_35 - (((DAT_INTMEM_3a < DAT_INTMEM_36 + 1) << 7) >> 7),
            bVar5 <= DAT_INTMEM_39) {
        puVar9 = (undefined1 *)CONCAT11(DAT_INTMEM_4b,DAT_INTMEM_4c);
        BANK0_R6 = DAT_INTMEM_35;
        BANK0_R7 = DAT_INTMEM_36;
        FUN_CODE_3b56(DAT_INTMEM_39 - bVar5);
        *(undefined1 *)(DAT_INTMEM_36 + 0x24) = *puVar9;
        FUN_CODE_3b90(0x35);
      }
      *(undefined1 *)(DAT_INTMEM_36 + 0x24) = 0xd;
      puVar9 = &DAT_CODE_382d;
      FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
      DAT_INTMEM_24 = *puVar9;
      DAT_INTMEM_36 = 0;
      DAT_INTMEM_35 = '\0';
      do {
        if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
        *puVar9 = 0;
        puVar9[1] = 0;
        bVar1 = 0xfe < DAT_INTMEM_36;
        cVar7 = bVar1 << 7;
        DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
        if (bVar1) {
          DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
          cVar7 = '\0';
        }
      } while (-1 < cVar7);
      DAT_EXTMEM_035f = '\0';
      DAT_INTMEM_42 = '\0';
      DAT_INTMEM_47 = '\0';
      pcVar8 = &DAT_CODE_3824;
      FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
      if (*pcVar8 != '\0') {
        pcVar8 = &DAT_CODE_3829;
        FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
        if (*pcVar8 == '\x01') {
          pcVar8 = &DAT_CODE_382c;
          FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
          if (*pcVar8 == '\0') {
            DAT_INTMEM_29 = 0xd;
            DAT_INTMEM_36 = 0;
            DAT_INTMEM_35 = '\0';
            do {
              if ((DAT_INTMEM_35 != '\0') || ((6 < DAT_INTMEM_36) << 7 < '\0')) break;
              puVar6 = (undefined1 *)(DAT_INTMEM_36 + 0x24);
              puVar9 = &DAT_EXTMEM_0025;
              FUN_CODE_3b56();
              *puVar9 = *puVar6;
              bVar1 = 0xfe < DAT_INTMEM_36;
              cVar7 = bVar1 << 7;
              DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
              if (bVar1) {
                DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
                cVar7 = '\0';
              }
            } while (-1 < cVar7);
            DAT_INTMEM_49 = 4;
            if (((((DAT_INTMEM_28 == ' ') || (DAT_INTMEM_28 == '\r')) &&
                 ((DAT_INTMEM_49 = 3, DAT_INTMEM_27 == ' ' || (DAT_INTMEM_27 == '\r')))) &&
                ((DAT_INTMEM_49 = 2, DAT_INTMEM_26 == ' ' || (DAT_INTMEM_26 == '\r')))) &&
               ((DAT_INTMEM_49 = 1, DAT_INTMEM_25 == ' ' || (DAT_INTMEM_25 == '\r')))) {
              DAT_INTMEM_49 = 0;
            }
            pcVar8 = &DAT_CODE_3812;
            FUN_CODE_3ae8(DAT_INTMEM_49,3);
            DAT_EXTMEM_035f = *pcVar8;
            puVar9 = &DAT_CODE_3811;
            FUN_CODE_3ae8(DAT_INTMEM_49,3);
            DAT_INTMEM_42 = *puVar9;
            _0_2 = 0;
            puVar9 = &DAT_CODE_3813;
            FUN_CODE_3ae8(DAT_INTMEM_49,3);
            DAT_INTMEM_5a = *puVar9;
            FUN_CODE_08e3();
            _0_2 = 1;
            puVar9 = &DAT_EXTMEM_0219;
            FUN_CODE_3b75(DAT_INTMEM_33 + -1);
            *puVar9 = 0x20;
            DAT_INTMEM_42 = DAT_EXTMEM_035f;
            DAT_INTMEM_47 = DAT_EXTMEM_035f;
          }
        }
      }
      pcVar8 = &DAT_CODE_3824;
      FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
      if (*pcVar8 != '\0') {
        pcVar8 = &DAT_CODE_3829;
        FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
        if (*pcVar8 == '\x01') {
          pcVar8 = &DAT_CODE_382c;
          FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
          if (*pcVar8 == '\x01') {
            DAT_INTMEM_29 = 0xd;
            DAT_INTMEM_36 = 0;
            DAT_INTMEM_35 = '\0';
            do {
              if ((DAT_INTMEM_35 != '\0') || ((6 < DAT_INTMEM_36) << 7 < '\0')) break;
              puVar6 = (undefined1 *)(DAT_INTMEM_36 + 0x24);
              puVar9 = &DAT_EXTMEM_0025;
              FUN_CODE_3b56();
              *puVar9 = *puVar6;
              bVar1 = 0xfe < DAT_INTMEM_36;
              cVar7 = bVar1 << 7;
              DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
              if (bVar1) {
                DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
                cVar7 = '\0';
              }
            } while (-1 < cVar7);
            DAT_INTMEM_42 = 0;
            _0_2 = 0;
            puVar9 = &DAT_CODE_382a;
            FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
            DAT_INTMEM_5a = *puVar9;
            FUN_CODE_08e3();
            _0_2 = 1;
            puVar9 = &DAT_EXTMEM_0219;
            FUN_CODE_3b75(DAT_INTMEM_33 + -1);
            *puVar9 = 0x20;
            DAT_EXTMEM_035f = '\0';
            DAT_INTMEM_36 = 0;
            DAT_INTMEM_35 = '\0';
            do {
              if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
              pcVar8 = &DAT_EXTMEM_0363;
              FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
              if (pcVar8[1] != '\0' || *pcVar8 != '\0') {
                DAT_EXTMEM_035f = DAT_INTMEM_36 + 1;
              }
              bVar1 = 0xfe < DAT_INTMEM_36;
              cVar7 = bVar1 << 7;
              DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
              if (bVar1) {
                DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
                cVar7 = '\0';
              }
            } while (-1 < cVar7);
            DAT_INTMEM_42 = DAT_EXTMEM_035f;
            DAT_INTMEM_47 = DAT_EXTMEM_035f;
          }
        }
      }
      pcVar8 = &DAT_CODE_3824;
      FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
      if (*pcVar8 != '\0') {
        pcVar8 = &DAT_CODE_382b;
        FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
        if (*pcVar8 == '\x01') {
          DAT_INTMEM_29 = 0xd;
          DAT_INTMEM_36 = 0;
          DAT_INTMEM_35 = '\0';
          do {
            if ((DAT_INTMEM_35 != '\0') || ((6 < DAT_INTMEM_36) << 7 < '\0')) break;
            puVar6 = (undefined1 *)(DAT_INTMEM_36 + 0x24);
            puVar9 = &DAT_EXTMEM_0025;
            FUN_CODE_3b56();
            *puVar9 = *puVar6;
            bVar1 = 0xfe < DAT_INTMEM_36;
            cVar7 = bVar1 << 7;
            DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
            if (bVar1) {
              DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
              cVar7 = '\0';
            }
          } while (-1 < cVar7);
          DAT_INTMEM_42 = 0;
          _0_2 = 0;
          puVar9 = &DAT_CODE_382a;
          FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
          DAT_INTMEM_5a = *puVar9;
          FUN_CODE_08e3();
          _0_2 = 1;
          puVar9 = &DAT_EXTMEM_0219;
          FUN_CODE_3b75(DAT_INTMEM_33 + -1);
          *puVar9 = 0x20;
          FUN_CODE_0b32();
          pcVar8 = &DAT_CODE_3824;
          FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
          DAT_INTMEM_42 = *pcVar8;
          DAT_INTMEM_47 = DAT_INTMEM_42;
          DAT_EXTMEM_035f = DAT_INTMEM_42;
        }
      }
      pcVar8 = &DAT_CODE_3826;
      FUN_CODE_3ae8(DAT_INTMEM_3d,0xe);
      if (*pcVar8 != '\0') {
        bVar5 = LATCH5;
        bVar4 = LATCH6_802_15;
        DAT_INTMEM_4f = bVar5;
        DAT_INTMEM_50 = bVar4;
        thunk_FUN_CODE_1056();
        FUN_CODE_0027();
        DAT_INTMEM_61 = DAT_INTMEM_4b;
        DAT_INTMEM_62 = DAT_INTMEM_4c;
        DAT_INTMEM_63 = 0xd;
        DAT_INTMEM_65 = 0xfa;
        DAT_INTMEM_64 = 0;
        FUN_CODE_3a87();
        if ((bVar5 == 0) && (-1 < (2 < bVar4) << 7)) {
          _1_6 = 1;
          DAT_INTMEM_3c = 0;
          DAT_INTMEM_3b = 0;
        }
        else {
          _1_6 = 0;
          DAT_INTMEM_3b = bVar5;
          DAT_INTMEM_3c = bVar4;
        }
        DAT_INTMEM_36 = 0;
        DAT_INTMEM_35 = '\0';
        DAT_INTMEM_39 = bVar5;
        DAT_INTMEM_3a = bVar4;
        do {
          bVar5 = DAT_INTMEM_35 - (((DAT_INTMEM_3a < DAT_INTMEM_36) << 7) >> 7);
          if ((DAT_INTMEM_39 < bVar5) << 7 < '\0') break;
          puVar9 = (undefined1 *)CONCAT11(DAT_INTMEM_4b,DAT_INTMEM_4c);
          FUN_CODE_3b56(DAT_INTMEM_39 - bVar5);
          uVar3 = *puVar9;
          puVar9 = &DAT_EXTMEM_0025;
          FUN_CODE_3b56();
          *puVar9 = uVar3;
          bVar1 = 0xfe < DAT_INTMEM_36;
          cVar7 = bVar1 << 7;
          DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
          if (bVar1) {
            DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
            cVar7 = '\0';
          }
        } while (-1 < cVar7);
        DAT_EXTMEM_0361 = DAT_INTMEM_46;
        _0_2 = 0;
        DAT_INTMEM_5a = 0;
        FUN_CODE_08e3();
        _0_2 = 1;
        DAT_EXTMEM_0362 = DAT_INTMEM_46;
        DAT_INTMEM_42 = DAT_EXTMEM_035f;
        DAT_INTMEM_46 = DAT_EXTMEM_0361;
        if ((char)((_2_3 & 1 & _2_5 | _2_4) << 7) < '\0') {
          FUN_CODE_0c10();
        }
        else {
          DAT_INTMEM_5a = 1;
          FUN_CODE_08e3();
        }
        DAT_INTMEM_46 = DAT_EXTMEM_0362;
      }
      FUN_CODE_052e();
    }
    if (_2_1 != 0) {
      _0_5 = 1;
      DAT_INTMEM_42 = DAT_EXTMEM_035f;
      DAT_EXTMEM_0361 = DAT_INTMEM_46;
      DAT_INTMEM_33 = '\0';
      _0_2 = 0;
      DAT_INTMEM_5a = 0;
      FUN_CODE_08e3();
      _0_2 = 1;
      DAT_EXTMEM_0362 = DAT_INTMEM_46;
      DAT_INTMEM_42 = DAT_EXTMEM_035f;
      DAT_INTMEM_47 = DAT_EXTMEM_035f;
      DAT_INTMEM_46 = DAT_EXTMEM_0361;
      if ((char)((_2_3 & 1 & _2_5 | _2_4) << 7) < '\0') {
        FUN_CODE_0c10();
      }
      else {
        DAT_INTMEM_5a = 1;
        FUN_CODE_08e3();
      }
      DAT_INTMEM_46 = DAT_EXTMEM_0362;
      FUN_CODE_052e();
      DAT_INTMEM_40 = 5;
      DAT_INTMEM_41 = 0xdc;
    }
    bVar5 = P1_4;
    if (((char)((bVar5 & 1 ^ 1) << 7) < '\0') &&
       (bVar5 = LATCH0_EZ_row_color_LED_bank, (bVar5 & 0x80) == 0)) {
      bVar5 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar5 | 0x80;
    }
    cVar7 = P1_4;
    if ((cVar7 != '\0') && (bVar5 = LATCH0_EZ_row_color_LED_bank, (bVar5 & 0x80) != 0)) {
      bVar5 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar5 & 0x7f;
    }
    if ((char)((_1_3 & 1 | _1_2) << 7) < '\0') {
      bVar5 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar5 | 0x20;
    }
    else {
      bVar5 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar5 & 0xdf;
    }
    cVar7 = P1_5;
    if (cVar7 == '\0') {
      IE = 0x92;
    }
    else {
      IE = 0x82;
      _2_1 = 0;
      DAT_EXTMEM_0358 = 0xff;
      DAT_EXTMEM_0359 = 0xff;
    }
    cVar7 = INT0;
    if (cVar7 != '\x01') {
      DAT_INTMEM_38 = 0;
      DAT_INTMEM_37 = 0;
      do {
        if ((DAT_INTMEM_37 != 0) || ((0x8b < DAT_INTMEM_38) << 7 < '\0')) break;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_38);
        *puVar9 = 0xff;
        puVar9[1] = 0xff;
        bVar1 = 0xfe < DAT_INTMEM_38;
        cVar7 = bVar1 << 7;
        DAT_INTMEM_38 = DAT_INTMEM_38 + 1;
        if (bVar1) {
          DAT_INTMEM_37 = DAT_INTMEM_37 + 1;
          cVar7 = '\0';
        }
      } while (-1 < cVar7);
      FUN_CODE_052e();
    }
    cVar7 = INT1;
    if (cVar7 != '\x01') {
      DAT_INTMEM_38 = 0;
      DAT_INTMEM_37 = 0;
      do {
        if ((DAT_INTMEM_37 != 0) || ((0x8b < DAT_INTMEM_38) << 7 < '\0')) break;
        puVar9 = &DAT_EXTMEM_0363;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_38);
        *puVar9 = 0;
        puVar9[1] = 0;
        bVar1 = 0xfe < DAT_INTMEM_38;
        cVar7 = bVar1 << 7;
        DAT_INTMEM_38 = DAT_INTMEM_38 + 1;
        if (bVar1) {
          DAT_INTMEM_37 = DAT_INTMEM_37 + 1;
          cVar7 = '\0';
        }
      } while (-1 < cVar7);
      FUN_CODE_052e();
    }
    DAT_INTMEM_2b = 0x2f;
    DAT_INTMEM_2c = 0xff;
    if (_0_6 == '\x01') {
      cVar7 = LATCH5;
      cVar2 = LATCH6_802_15;
      if ((DAT_EXTMEM_0018 != cVar2) || (DAT_EXTMEM_0017 != cVar7)) {
        LATCH5 = 0;
        LATCH6_802_15 = 0;
      }
      cVar7 = LATCH3_7SEG_802_15;
      cVar2 = LATCH4_802_15;
      if ((DAT_EXTMEM_000e != cVar2) || (DAT_EXTMEM_000d != cVar7)) {
        LATCH3_7SEG_802_15 = 0;
        LATCH4_802_15 = 0;
      }
      if ((DAT_EXTMEM_0014 != DAT_EXTMEM_0010) || (DAT_EXTMEM_0013 != DAT_EXTMEM_000f)) {
        DAT_EXTMEM_000f = '\0';
        DAT_EXTMEM_0010 = '\0';
      }
      if ((DAT_EXTMEM_001e != DAT_EXTMEM_001a) || (DAT_EXTMEM_001d != DAT_EXTMEM_0019)) {
        DAT_EXTMEM_0019 = '\0';
        DAT_EXTMEM_001a = '\0';
      }
      BANK0_R6 = BANK0_R6 ^ 0xff;
      BANK0_R7 = BANK0_R7 ^ 0xff;
      if ((DAT_EXTMEM_0024 != DAT_EXTMEM_0020) || (DAT_EXTMEM_0023 != DAT_EXTMEM_001f)) {
        DAT_EXTMEM_001f = '\0';
        DAT_EXTMEM_0020 = '\0';
      }
      _2_2 = 1;
      _0_6 = '\0';
    }
    if (DAT_INTMEM_48 != '\0') {
      _2_1 = 0;
      if (DAT_INTMEM_48 == '\x01') {
        DAT_INTMEM_36 = 0;
        DAT_INTMEM_35 = '\0';
        do {
          if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
          puVar9 = &DAT_EXTMEM_0363;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
          *puVar9 = 0;
          puVar9[1] = 0;
          bVar1 = 0xfe < DAT_INTMEM_36;
          cVar7 = bVar1 << 7;
          DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
          if (bVar1) {
            DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
            cVar7 = '\0';
          }
        } while (-1 < cVar7);
      }
      if (DAT_INTMEM_48 == '\x02') {
        DAT_INTMEM_36 = 0;
        DAT_INTMEM_35 = '\0';
        do {
          if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
          puVar9 = &DAT_EXTMEM_0363;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
          *puVar9 = 0xff;
          puVar9[1] = 0xff;
          bVar1 = 0xfe < DAT_INTMEM_36;
          cVar7 = bVar1 << 7;
          DAT_INTMEM_36 = DAT_INTMEM_36 + 1;
          if (bVar1) {
            DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
            cVar7 = '\0';
          }
        } while (-1 < cVar7);
      }
      else if (DAT_INTMEM_48 == '\x03') {
        DAT_INTMEM_36 = 0;
        DAT_INTMEM_35 = '\0';
        do {
          if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
          puVar9 = &DAT_EXTMEM_0363;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
          *puVar9 = 0xaa;
          puVar9[1] = 0xaa;
          puVar9 = &DAT_EXTMEM_0363;
          FUN_CODE_000e();
          *puVar9 = 0x55;
          puVar9[1] = 0x55;
          bVar1 = 0xfd < DAT_INTMEM_36;
          cVar7 = bVar1 << 7;
          DAT_INTMEM_36 = DAT_INTMEM_36 + 2;
          if (bVar1) {
            DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
            cVar7 = '\0';
          }
        } while (-1 < cVar7);
      }
      else if (DAT_INTMEM_48 == '\x04') {
        DAT_INTMEM_36 = 0;
        DAT_INTMEM_35 = '\0';
        do {
          if ((DAT_INTMEM_35 != '\0') || ((0x8b < DAT_INTMEM_36) << 7 < '\0')) break;
          puVar9 = &DAT_EXTMEM_0363;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_36);
          *puVar9 = 0x55;
          puVar9[1] = 0x55;
          puVar9 = &DAT_EXTMEM_0363;
          FUN_CODE_000e();
          *puVar9 = 0xaa;
          puVar9[1] = 0xaa;
          bVar1 = 0xfd < DAT_INTMEM_36;
          cVar7 = bVar1 << 7;
          DAT_INTMEM_36 = DAT_INTMEM_36 + 2;
          if (bVar1) {
            DAT_INTMEM_35 = DAT_INTMEM_35 + '\x01';
            cVar7 = '\0';
          }
        } while (-1 < cVar7);
      }
      FUN_CODE_052e();
      DAT_INTMEM_48 = '\0';
    }
  } while( true );
}



// ==== FUN_CODE_3a5a @ CODE:3a5a  (33 bytes)

char FUN_CODE_3a5a(byte param_1,byte param_2,byte param_3)

{
  byte bVar1;
  
  bVar1 = param_2;
  if ((param_1 >> 3 & 1) != 0) {
    bVar1 = param_3;
    param_3 = param_2;
  }
  return param_3 * (&DAT_CODE_3a7f)[param_1 & 7] +
         (char)((ushort)bVar1 * (ushort)(byte)(&DAT_CODE_3a7f)[param_1 & 7] >> 8);
}



// ==== FUN_CODE_3a7b @ CODE:3a7b  (4 bytes)

void FUN_CODE_3a7b(byte param_1)

{
  FUN_CODE_3a5a(~param_1 + 1);
  return;
}



// ==== FUN_CODE_3a87 @ CODE:3a87  (43 bytes)

byte FUN_CODE_3a87(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)CONCAT11(DAT_INTMEM_61,DAT_INTMEM_62);
  DAT_INTMEM_64 = DAT_INTMEM_64 + '\x01';
  DAT_INTMEM_65 = DAT_INTMEM_65 + '\x01';
  while ((DAT_INTMEM_65 = DAT_INTMEM_65 + -1, DAT_INTMEM_65 != '\0' ||
         (DAT_INTMEM_64 = DAT_INTMEM_64 + -1, DAT_INTMEM_64 != '\0'))) {
    param_1 = *pbVar1 ^ DAT_INTMEM_63;
    if (param_1 == 0) {
      return (char)((ushort)pbVar1 >> 8) -
             (DAT_INTMEM_61 - ((((byte)pbVar1 < DAT_INTMEM_62) << 7) >> 7));
    }
    pbVar1 = pbVar1 + 1;
  }
  return param_1;
}



// ==== isr_timer0 @ CODE:3ab2  (27 bytes)

undefined1 isr_timer0(undefined1 param_1)

{
  FUN_CODE_041a();
  return param_1;
}



// ==== isr_serial @ CODE:3acd  (27 bytes)

undefined1 isr_serial(undefined1 param_1)

{
  FUN_CODE_035b();
  return param_1;
}



// ==== FUN_CODE_3ae8 @ CODE:3ae8  (16 bytes)

char FUN_CODE_3ae8(undefined2 param_1,byte param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  
  bVar3 = (byte)param_1;
  cVar2 = (char)((ushort)param_1 >> 8);
  cVar1 = '\0';
  FUN_CODE_3b31(0);
  return cVar1 + (cVar2 - ((CARRY1(param_2,bVar3) << 7) >> 7));
}



// ==== FUN_CODE_3af8 @ CODE:3af8  (15 bytes)

void FUN_CODE_3af8(void)

{
  return;
}



// ==== FUN_CODE_3b07 @ CODE:3b07  (14 bytes)

void FUN_CODE_3b07(short param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *pcVar2;
  *pcVar2 = cVar1 + -1;
  if (cVar1 + -1 == -1) {
    FUN_CODE_3b6b();
    *pcVar2 = *pcVar2 + -1;
  }
  return;
}



// ==== FUN_CODE_3b15 @ CODE:3b15  (14 bytes)

void FUN_CODE_3b15(char param_1)

{
  param_1 = param_1 + '\x01';
  do {
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return;
}



// ==== FUN_CODE_3b23 @ CODE:3b23  (14 bytes)

void FUN_CODE_3b23(char param_1)

{
  param_1 = param_1 + '\x01';
  do {
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return;
}



// ==== FUN_CODE_3b31 @ CODE:3b31  (14 bytes)

char FUN_CODE_3b31(byte param_1,char param_2,byte param_3)

{
  return param_2 * param_1 + (char)((ushort)param_1 * (ushort)param_3 >> 8);
}



// ==== FUN_CODE_3b3f @ CODE:3b3f  (12 bytes)

undefined1 FUN_CODE_3b3f(undefined1 *param_1)

{
  return *param_1;
}



// ==== FUN_CODE_3b4b @ CODE:3b4b  (11 bytes)

char FUN_CODE_3b4b(undefined2 param_1,char param_2,byte param_3)

{
  return param_2 + ((char)((ushort)param_1 >> 8) - ((CARRY1(param_3,(byte)param_1) << 7) >> 7));
}



// ==== FUN_CODE_3b56 @ CODE:3b56  (11 bytes)

char FUN_CODE_3b56(undefined2 param_1,char param_2,byte param_3)

{
  return (char)((ushort)param_1 >> 8) + (param_2 - ((CARRY1((byte)param_1,param_3) << 7) >> 7));
}



// ==== FUN_CODE_3b61 @ CODE:3b61  (10 bytes)

void FUN_CODE_3b61(void)

{
  return;
}



// ==== FUN_CODE_3b6b @ CODE:3b6b  (10 bytes)

void FUN_CODE_3b6b(void)

{
  return;
}



// ==== FUN_CODE_3b75 @ CODE:3b75  (9 bytes)

void FUN_CODE_3b75(void)

{
  return;
}



// ==== FUN_CODE_3b7e @ CODE:3b7e  (9 bytes)

void FUN_CODE_3b7e(undefined1 *param_1,undefined1 *param_2)

{
  *param_2 = *param_1;
  param_2['\x01'] = param_1[1];
  return;
}



// ==== reset_entry @ CODE:3b87  (9 bytes)

void reset_entry(void)

{
  SP = 0x67;
  FUN_CODE_136f();
  return;
}



// ==== FUN_CODE_3b90 @ CODE:3b90  (8 bytes)

void FUN_CODE_3b90(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1 + '\x01';
  *pcVar1 = *pcVar1 + '\x01';
  if (*pcVar1 == '\0') {
    *param_1 = *param_1 + '\x01';
  }
  return;
}



// ==== FUN_CODE_3b98 @ CODE:3b98  (8 bytes)

void FUN_CODE_3b98(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1 + '\x01';
  *pcVar1 = *pcVar1 + -1;
  if (*pcVar1 == -1) {
    *param_1 = *param_1 + -1;
  }
  return;
}


