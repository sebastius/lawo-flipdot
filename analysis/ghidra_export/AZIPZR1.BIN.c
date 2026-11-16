// Ghidra-decompilatie van AZIPZR1.BIN

// ==== VEC_RESET @ CODE:0000  (3 bytes)

void VEC_RESET(void)

{
  reset_entry();
  return;
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



// ==== FUN_CODE_0026 @ CODE:0026  (242 bytes)

void FUN_CODE_0026(void)

{
  char cVar1;
  char cVar2;
  
  DAT_INTMEM_28 = DAT_INTMEM_27;
  DAT_INTMEM_27 = DAT_INTMEM_26;
  DAT_INTMEM_26 = DAT_INTMEM_25;
  DAT_INTMEM_25 = DAT_EXTMEM_000e;
  cVar1 = LATCH5;
  cVar2 = LATCH6_802_15;
  if (cVar2 != '\0' || cVar1 != '\0') {
    DAT_INTMEM_25 = 0x20;
    DAT_INTMEM_26 = 0x20;
    DAT_INTMEM_27 = 0x20;
    DAT_INTMEM_28 = 0x20;
  }
  cVar1 = LATCH5;
  cVar2 = LATCH6_802_15;
  if (cVar2 == '\x01' && cVar1 == '\0') {
    DAT_INTMEM_25 = 0x45;
    DAT_INTMEM_26 = 0x20;
    DAT_INTMEM_27 = 0x20;
    DAT_INTMEM_28 = 0x20;
  }
  else {
    cVar1 = LATCH5;
    cVar2 = LATCH6_802_15;
    if (cVar2 == '\x02' && cVar1 == '\0') {
      DAT_INTMEM_25 = 0x20;
      DAT_INTMEM_26 = 0x20;
      DAT_INTMEM_27 = 0x20;
      DAT_INTMEM_28 = 0x20;
    }
    else {
      cVar1 = LATCH5;
      cVar2 = LATCH6_802_15;
      if (cVar2 == '\x03' && cVar1 == '\0') {
        DAT_INTMEM_25 = 0x6a;
        DAT_INTMEM_26 = 0x6b;
        DAT_INTMEM_27 = 0x6c;
        DAT_INTMEM_28 = 0x20;
      }
      else {
        cVar1 = LATCH5;
        cVar2 = LATCH6_802_15;
        if (cVar2 == '\x04' && cVar1 == '\0') {
          DAT_INTMEM_25 = 0x4e;
          DAT_INTMEM_26 = 0x20;
          DAT_INTMEM_27 = 0x20;
          DAT_INTMEM_28 = 0x20;
        }
        else {
          cVar1 = LATCH5;
          cVar2 = LATCH6_802_15;
          if (cVar2 == '\x05' && cVar1 == '\0') {
            DAT_INTMEM_25 = 0x53;
            DAT_INTMEM_26 = 0x20;
            DAT_INTMEM_27 = 0x20;
            DAT_INTMEM_28 = 0x20;
          }
          else {
            cVar1 = LATCH5;
            cVar2 = LATCH6_802_15;
            if (cVar2 == '!' && cVar1 == '\0') {
              DAT_INTMEM_25 = 0x6d;
              DAT_INTMEM_26 = 0x6e;
              DAT_INTMEM_27 = 0x6f;
              DAT_INTMEM_28 = 0x20;
            }
            else {
              cVar1 = LATCH5;
              cVar2 = LATCH6_802_15;
              if ((cVar2 == 'a' && cVar1 == '\0') || (cVar2 == 'b' && cVar1 == '\0')) {
                DAT_INTMEM_25 = 0x55;
                DAT_INTMEM_26 = 0x45;
                DAT_INTMEM_27 = 0x33;
                DAT_INTMEM_28 = 0x20;
              }
            }
          }
        }
      }
    }
  }
  return;
}



// ==== FUN_CODE_0118 @ CODE:0118  (19 bytes)

void FUN_CODE_0118(void)

{
  undefined1 uVar1;
  
  uVar1 = LATCH7;
  _0_0 = 0;
  return;
}



// ==== FUN_CODE_012b @ CODE:012b  (20 bytes)

char FUN_CODE_012b(void)

{
  char cVar1;
  
  cVar1 = DAT_INTMEM_41 - 0x30;
  if ((DAT_INTMEM_41 < 0x30) || (cVar1 = DAT_INTMEM_41 - 0x3a, -1 < (DAT_INTMEM_41 < 0x3a) << 7)) {
    return cVar1;
  }
  return cVar1;
}



// ==== FUN_CODE_013f @ CODE:013f  (100 bytes)

char FUN_CODE_013f(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte in_PSW;
  byte bVar5;
  undefined1 *puVar6;
  char *pcVar7;
  
  DAT_INTMEM_3f = 0;
  DAT_INTMEM_3e = '\0';
  DAT_INTMEM_40 = DAT_INTMEM_3d;
  while( true ) {
    puVar6 = &DAT_EXTMEM_035f;
    FUN_CODE_4a28(DAT_INTMEM_40);
    DAT_INTMEM_41 = *puVar6;
    FUN_CODE_012b();
    if (DAT_INTMEM_40 < 6) {
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
    bVar1 = 0x19 < (byte)(DAT_INTMEM_3e -
                         ((char)(bVar3 | (0x98 < DAT_INTMEM_3f - ((char)(bVar3 | 0x80) >> 7)) << 7)
                         >> 7));
    in_PSW = bVar3 | bVar1 << 7;
    if (bVar1) {
      DAT_INTMEM_3e = -1;
      DAT_INTMEM_3f = 0xff;
    }
    else {
      cVar4 = DAT_INTMEM_3e;
      bVar5 = DAT_INTMEM_3f;
      FUN_CODE_49d7(10);
      pcVar7 = &DAT_EXTMEM_035f;
      FUN_CODE_4a28(DAT_INTMEM_40);
      DAT_INTMEM_3f = (*pcVar7 - 0x30U) + bVar5;
      in_PSW = in_PSW & 0x5d | CARRY1(*pcVar7 - 0x30U,bVar5) << 7 |
               ((char)DAT_INTMEM_3f < '\0') << 5 | (DAT_INTMEM_3f == 0) << 1;
      if ((char)in_PSW < '\0') {
        cVar4 = cVar4 + '\x01';
      }
      DAT_INTMEM_3e = cVar4;
    }
    DAT_INTMEM_40 = DAT_INTMEM_40 + 1;
  }
  return DAT_INTMEM_40 - 6;
}



// ==== FUN_CODE_01a3 @ CODE:01a3  (78 bytes)

void FUN_CODE_01a3(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  
  DAT_INTMEM_3b = 0xff;
  for (DAT_INTMEM_3c = 0; DAT_INTMEM_3c < DAT_INTMEM_3a; DAT_INTMEM_3c = DAT_INTMEM_3c + 1) {
    FUN_CODE_4a28(DAT_INTMEM_3c);
    cVar1 = P;
    if (cVar1 != '\0') {
      pbVar3 = &DAT_EXTMEM_031e;
      FUN_CODE_4a28(DAT_INTMEM_3c);
      bVar2 = *pbVar3 ^ 0x80;
      pbVar3 = &DAT_EXTMEM_031e;
      FUN_CODE_4a28(DAT_INTMEM_3c);
      *pbVar3 = bVar2;
    }
    pbVar3 = &DAT_EXTMEM_031e;
    FUN_CODE_4a28(DAT_INTMEM_3c);
    DAT_INTMEM_3b = *pbVar3 ^ DAT_INTMEM_3b;
  }
  pbVar3 = &DAT_EXTMEM_031e;
  FUN_CODE_4a28(DAT_INTMEM_3c);
  *pbVar3 = DAT_INTMEM_3b;
  return;
}



// ==== FUN_CODE_01f1 @ CODE:01f1  (808 bytes)

byte FUN_CODE_01f1(byte param_1)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  
  DAT_INTMEM_38 = 0;
  BANK1_R4 = DAT_EXTMEM_035f;
  pbVar6 = &DAT_CODE_4786;
  FUN_CODE_498e(DAT_EXTMEM_055b,1);
  bVar3 = *pbVar6;
  cVar5 = (param_1 < BANK1_R7) << 7;
  if (param_1 == BANK1_R7) {
    DAT_INTMEM_41 = DAT_EXTMEM_0360;
    FUN_CODE_012b();
    if (cVar5 < '\0') {
      DAT_INTMEM_38 = 4;
    }
    else if (DAT_EXTMEM_0360 == 'A') {
      DAT_INTMEM_38 = 5;
    }
  }
  else {
    cVar5 = (DAT_EXTMEM_035f < 0x61) << 7;
    if (DAT_EXTMEM_035f == 0x61) {
      DAT_INTMEM_41 = DAT_EXTMEM_0360;
      FUN_CODE_012b();
      if (cVar5 < '\0') {
        DAT_INTMEM_38 = 7;
      }
      else if (DAT_EXTMEM_0360 == 'A') {
        DAT_INTMEM_38 = 0xc;
      }
      else if (DAT_EXTMEM_0360 == 'V') {
        DAT_INTMEM_38 = 8;
      }
      else if (DAT_EXTMEM_0360 == 'T') {
        DAT_INTMEM_38 = 9;
      }
    }
    else {
      cVar5 = (DAT_EXTMEM_035f < 0x6c) << 7;
      if (DAT_EXTMEM_035f == 0x6c) {
        DAT_INTMEM_41 = DAT_EXTMEM_0360;
        FUN_CODE_012b();
        if (cVar5 < '\0') {
          DAT_INTMEM_38 = 1;
        }
        else if (DAT_EXTMEM_0360 == 'E') {
          DAT_INTMEM_38 = 2;
        }
        else if (DAT_EXTMEM_0360 == 'S') {
          DAT_INTMEM_38 = 10;
        }
      }
      else {
        cVar5 = (DAT_EXTMEM_035f < 0x6b) << 7;
        if (DAT_EXTMEM_035f == 0x6b) {
          DAT_INTMEM_41 = DAT_EXTMEM_0360;
          FUN_CODE_012b();
          if (cVar5 < '\0') {
            DAT_INTMEM_38 = 3;
          }
        }
        else {
          cVar5 = (DAT_EXTMEM_035f < 0x77) << 7;
          if (DAT_EXTMEM_035f == 0x77) {
            DAT_INTMEM_41 = DAT_EXTMEM_0360;
            FUN_CODE_012b();
            if (cVar5 < '\0') {
              DAT_INTMEM_38 = 6;
            }
          }
          else {
            cVar5 = (DAT_EXTMEM_035f < 0x65) << 7;
            if (DAT_EXTMEM_035f == 0x65) {
              DAT_INTMEM_41 = DAT_EXTMEM_0360;
              FUN_CODE_012b();
              if (cVar5 < '\0') {
                DAT_INTMEM_38 = 0xd;
              }
            }
            else {
              DAT_INTMEM_38 = 0;
            }
          }
        }
      }
    }
  }
  bVar4 = DAT_INTMEM_38;
  if (DAT_INTMEM_38 != 0) {
    if (DAT_INTMEM_38 == 7) {
      _0_5 = 0;
      bVar4 = DAT_EXTMEM_055b + 0x30U;
      if (DAT_EXTMEM_055b + 0x30U == BANK1_R6) {
        if (_1_3 == '\0') {
          DAT_INTMEM_39 = 0;
        }
        else {
          DAT_INTMEM_39 = 6;
        }
        _1_3 = '\0';
        DAT_EXTMEM_031e = 0x61;
        DAT_EXTMEM_031f = DAT_INTMEM_39 + 0x30;
        DAT_EXTMEM_0320 = 0xd;
        DAT_INTMEM_3a = 3;
        FUN_CODE_01a3(DAT_EXTMEM_0360);
        DAT_EXTMEM_002f = 4;
        _0_4 = 1;
        DAT_EXTMEM_0555 = 0;
        TI = 1;
        bVar4 = 0;
      }
    }
    else if (DAT_INTMEM_38 == 1) {
      DAT_INTMEM_3d = 1;
      FUN_CODE_013f();
      DAT_INTMEM_39 = 0;
      DAT_EXTMEM_0015 = param_1;
      DAT_EXTMEM_0016 = bVar3;
      do {
        if (4 < DAT_INTMEM_39) {
          return DAT_INTMEM_39 - 5;
        }
        puVar7 = &DAT_EXTMEM_035f;
        FUN_CODE_4a28(DAT_INTMEM_39 + 1);
        uVar2 = *puVar7;
        puVar7 = &DAT_EXTMEM_0011;
        FUN_CODE_4a28(DAT_INTMEM_39);
        *puVar7 = uVar2;
        bVar1 = DAT_INTMEM_39 != 0xff;
        DAT_INTMEM_39 = DAT_INTMEM_39 + 1;
        bVar4 = DAT_INTMEM_39;
      } while (bVar1);
    }
    else if (DAT_INTMEM_38 == 2) {
      DAT_INTMEM_3d = 2;
      FUN_CODE_013f();
      bVar4 = bVar3;
      DAT_EXTMEM_0019 = param_1;
      DAT_EXTMEM_001a = bVar3;
    }
    else if (DAT_INTMEM_38 != 10) {
      if (DAT_INTMEM_38 == 3) {
        DAT_INTMEM_3d = 1;
        FUN_CODE_013f();
        bVar4 = bVar3;
        DAT_EXTMEM_0023 = param_1;
        DAT_EXTMEM_0024 = bVar3;
      }
      else if (DAT_INTMEM_38 == 4) {
        _0_7 = 1;
        DAT_INTMEM_3d = 1;
        FUN_CODE_013f();
        bVar4 = bVar3;
        DAT_EXTMEM_001d = param_1;
        DAT_EXTMEM_001e = bVar3;
      }
      else if (DAT_INTMEM_38 != 5) {
        if (DAT_INTMEM_38 == 0xb) {
          DAT_EXTMEM_0556 = 1;
          bVar4 = 1;
        }
        else if (DAT_INTMEM_38 == 6) {
          DAT_INTMEM_3d = 1;
          FUN_CODE_013f();
          bVar4 = bVar3;
          DAT_EXTMEM_0029 = param_1;
          DAT_EXTMEM_002a = bVar3;
        }
        else if (DAT_INTMEM_38 == 0xc) {
          _0_5 = 0;
          bVar4 = DAT_EXTMEM_055b + 0x30;
          if (bVar4 == BANK1_R6) {
            DAT_EXTMEM_0556 = 2;
            DAT_INTMEM_39 = 0;
            _1_3 = '\0';
            DAT_EXTMEM_031e = 0x61;
            DAT_EXTMEM_031f = '0';
            DAT_EXTMEM_0320 = 0xd;
            DAT_INTMEM_3a = 3;
            FUN_CODE_01a3(DAT_EXTMEM_0361);
            DAT_EXTMEM_002f = 4;
            _0_4 = 1;
            bVar4 = 0;
            DAT_EXTMEM_0555 = 0;
            TI = 1;
          }
        }
        else if (DAT_INTMEM_38 == 0xd) {
          DAT_INTMEM_39 = 1;
          do {
            if (6 < DAT_INTMEM_39) {
              return DAT_INTMEM_39 - 7;
            }
            puVar7 = &DAT_EXTMEM_035f;
            FUN_CODE_4a28(DAT_INTMEM_39);
            uVar2 = *puVar7;
            puVar7 = &DAT_EXTMEM_0009;
            FUN_CODE_4a28(DAT_INTMEM_39 - 1);
            *puVar7 = uVar2;
            bVar1 = DAT_INTMEM_39 != 0xff;
            bVar4 = DAT_INTMEM_39 + 1;
            DAT_INTMEM_39 = bVar4;
          } while (bVar1);
        }
        else if (DAT_INTMEM_38 == 8) {
          _0_5 = 0;
          if ((DAT_EXTMEM_0361 == '0') || (bVar4 = DAT_EXTMEM_055b + 0x30, bVar4 == BANK1_R6)) {
            DAT_EXTMEM_031e = 0x61;
            DAT_EXTMEM_031f = 'V';
            DAT_EXTMEM_0320 = DAT_CODE_4691;
            DAT_EXTMEM_0321 = DAT_CODE_4692;
            DAT_EXTMEM_0322 = DAT_CODE_4693;
            DAT_EXTMEM_0323 = DAT_CODE_4694;
            DAT_EXTMEM_0324 = DAT_CODE_4695;
            DAT_EXTMEM_0325 = DAT_CODE_4696;
            DAT_EXTMEM_0326 = 0xd;
            DAT_INTMEM_3a = 9;
            FUN_CODE_01a3();
            DAT_EXTMEM_002f = 10;
            _0_4 = 1;
            bVar4 = 0;
            DAT_EXTMEM_0555 = 0;
            TI = 1;
          }
        }
        else if ((DAT_INTMEM_38 == 9) &&
                ((_0_5 = 0, DAT_EXTMEM_0361 == '0' ||
                 (bVar4 = DAT_EXTMEM_055b + 0x30U, DAT_EXTMEM_055b + 0x30U == BANK1_R6)))) {
          DAT_EXTMEM_0571 = DAT_EXTMEM_0362 - 0x2f;
          bVar4 = DAT_EXTMEM_0571;
        }
      }
    }
  }
  return bVar4;
}



// ==== FUN_CODE_0519 @ CODE:0519  (296 bytes)

byte FUN_CODE_0519(byte param_1)

{
  char cVar1;
  undefined1 uVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  
  cVar1 = RI;
  if (cVar1 == '\x01') {
    DAT_INTMEM_42 = SBUF;
    RI = 0;
    _1_2 = 0;
    _1_1 = 0;
    cVar1 = P;
    if (cVar1 == '\0') {
      DAT_INTMEM_43 = DAT_INTMEM_42 & 0x7f;
      if (DAT_EXTMEM_0553 == '\0') {
        if (((DAT_INTMEM_43 < 0x61) << 7 < '\0') || (0x7a < DAT_INTMEM_43)) {
          param_1 = DAT_INTMEM_43;
          if (DAT_INTMEM_43 == 0xd) {
            param_1 = 3;
            DAT_EXTMEM_0553 = '\x03';
          }
        }
        else {
          DAT_INTMEM_2d = 1;
          DAT_EXTMEM_002e = DAT_INTMEM_42 ^ 0xff;
          param_1 = 1;
          DAT_EXTMEM_0553 = '\x01';
          DAT_EXTMEM_035f = DAT_INTMEM_43;
        }
      }
      else if (DAT_EXTMEM_0553 == '\x01') {
        if (DAT_INTMEM_2d < 0xfa) {
          DAT_EXTMEM_002e = DAT_EXTMEM_002e ^ DAT_INTMEM_42;
          pbVar3 = &DAT_EXTMEM_035f;
          FUN_CODE_4a28(DAT_INTMEM_2d);
          *pbVar3 = DAT_INTMEM_43;
          if (((DAT_EXTMEM_035f == 0x61) && (DAT_EXTMEM_0360 == 'A')) &&
             (DAT_EXTMEM_055b + '0' == DAT_EXTMEM_0361)) {
            puVar4 = &DAT_EXTMEM_035f;
            FUN_CODE_4a28(DAT_INTMEM_2d);
            uVar2 = *puVar4;
            puVar4 = &DAT_EXTMEM_0459;
            FUN_CODE_4a28(DAT_INTMEM_2d);
            *puVar4 = uVar2;
          }
          DAT_INTMEM_2d = DAT_INTMEM_2d + 1;
        }
        param_1 = DAT_INTMEM_43;
        if (DAT_INTMEM_43 == 0xd) {
          DAT_EXTMEM_0553 = '\x02';
          param_1 = 2;
        }
      }
      else if (DAT_EXTMEM_0553 == '\x02') {
        if (DAT_EXTMEM_002e == DAT_INTMEM_42) {
          _1_1 = 0;
          _0_1 = 1;
          FUN_CODE_01f1();
        }
        else {
          _1_1 = 1;
          _0_1 = 0;
        }
        DAT_EXTMEM_0553 = '\0';
        param_1 = 0;
      }
      else {
        DAT_EXTMEM_0553 = '\0';
        param_1 = 0;
      }
    }
    else {
      _1_2 = 1;
      DAT_EXTMEM_0553 = '\0';
      param_1 = 0;
    }
  }
  cVar1 = TI;
  if ((cVar1 != '\0') && (TI = 0, _0_4 != '\0')) {
    param_1 = DAT_EXTMEM_002f - (DAT_EXTMEM_0555 + 1);
    if ((DAT_EXTMEM_002f < DAT_EXTMEM_0555 + 1) << 7 < '\0') {
      _0_4 = '\0';
    }
    else {
      if (DAT_EXTMEM_0555 == 0) {
        FUN_CODE_497e(0x2c);
      }
      puVar4 = &DAT_EXTMEM_031e;
      FUN_CODE_4a28(DAT_EXTMEM_0555);
      SBUF = *puVar4;
      param_1 = DAT_EXTMEM_0555 + 1;
      DAT_EXTMEM_0555 = param_1;
    }
  }
  return param_1;
}



// ==== FUN_CODE_0641 @ CODE:0641  (298 bytes)

void FUN_CODE_0641(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  T0 = 1;
  if (DAT_EXTMEM_0563 != '\0' || DAT_EXTMEM_0562 != '\0') {
    FUN_CODE_49ad(0x562);
  }
  if (_1_4 == '\x01') {
    bVar2 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar2 & 0xe0 | (_1_6 & 1) << 4 | DAT_EXTMEM_056b & 0xf;
    LATCH2_module_enable = DAT_EXTMEM_056c / 0x70;
    bVar2 = DAT_EXTMEM_056c % 0x70;
    DAT_EXTMEM_0010 = bVar2;
    if (DAT_EXTMEM_056c < 0x70) {
      cVar1 = '\x02';
      bVar3 = (_1_6 & 1) << 1;
      do {
        bVar3 = bVar3 >> 1 | bVar3 << 7;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      pbVar4 = (byte *)CONCAT11(DAT_INTMEM_36,DAT_INTMEM_37);
      FUN_CODE_4a28(bVar2,0);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    else if (DAT_EXTMEM_055c == -0x74) {
      cVar1 = '\x02';
      bVar3 = (_1_6 & 1) << 1;
      do {
        bVar3 = bVar3 >> 1 | bVar3 << 7;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      pbVar4 = (byte *)CONCAT11(DAT_INTMEM_36,DAT_INTMEM_37);
      FUN_CODE_4a14(bVar2,0x54);
      FUN_CODE_4a28(bVar2);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    else {
      cVar1 = '\x02';
      bVar3 = (_1_6 & 1) << 1;
      do {
        bVar3 = bVar3 >> 1 | bVar3 << 7;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      pbVar4 = (byte *)CONCAT11(DAT_INTMEM_36,DAT_INTMEM_37);
      FUN_CODE_4a14(bVar2,0x62);
      FUN_CODE_4a28(bVar2);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    _1_4 = '\0';
    T0 = 1;
    T0 = 1;
    T0 = 1;
    T0 = 0;
  }
  if (DAT_INTMEM_33 != '\0' || DAT_INTMEM_32 != '\0') {
    FUN_CODE_4a4b(0x32);
  }
  if (DAT_EXTMEM_055f != '\0' || DAT_EXTMEM_055e != '\0') {
    FUN_CODE_49ad(0x55e);
  }
  if (DAT_INTMEM_2c != '\0' || DAT_INTMEM_2b != '\0') {
    bVar2 = T1;
    T1 = bVar2 ^ 1;
    FUN_CODE_4a4b(0x2b);
  }
  TL0 = 0xc;
  TH0 = 0xfe;
  return;
}



// ==== FUN_CODE_076b @ CODE:076b  (483 bytes)

void FUN_CODE_076b(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  
  do {
    if (_2_0 == 0) break;
  } while (DAT_INTMEM_33 != '\0' || DAT_INTMEM_32 != '\0');
  cVar4 = P1_6;
  if (((cVar4 == '\0') && (DAT_EXTMEM_055b == -1)) && (_0_5 == '\x01')) {
    DAT_INTMEM_2f = '=';
    DAT_INTMEM_2e = '\0';
    while (DAT_INTMEM_2f != '\0' || DAT_INTMEM_2e != '\0') {
      cVar4 = DAT_INTMEM_2e;
      if (DAT_INTMEM_2f == '\0') {
        cVar4 = DAT_INTMEM_2e + -1;
      }
      puVar9 = &DAT_EXTMEM_031e;
      FUN_CODE_4a09(cVar4);
      uVar6 = *puVar9;
      puVar9 = &DAT_EXTMEM_0321;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar9 = uVar6;
      pcVar7 = &DAT_EXTMEM_0321;
      FUN_CODE_4a09();
      if (*pcVar7 == '\r') {
        DAT_EXTMEM_002f = DAT_INTMEM_2f + '\x04';
      }
      FUN_CODE_4a4b(0x2e);
    }
    DAT_INTMEM_2f = 1;
    DAT_INTMEM_2e = '\0';
    do {
      if ((DAT_INTMEM_2e != '\0') || ((3 < DAT_INTMEM_2f) << 7 < '\0')) break;
      puVar9 = &DAT_EXTMEM_031e;
      FUN_CODE_4a09('\x03' - DAT_INTMEM_2f);
      *puVar9 = 0x30;
      bVar1 = 0xfe < DAT_INTMEM_2f;
      cVar4 = bVar1 << 7;
      DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
      if (bVar1) {
        DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
        cVar4 = '\0';
      }
    } while (-1 < cVar4);
    DAT_EXTMEM_031e = 0x7a;
    DAT_EXTMEM_035e = 0xd;
    DAT_EXTMEM_0555 = 0;
    _0_4 = 1;
    TI = 1;
  }
  pcVar7 = &DAT_CODE_46ae;
  FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
  _1_7 = *pcVar7 == '\0';
  if (_0_0 != '\0') {
    _1_7 = !(bool)_1_7;
  }
  FUN_CODE_498e(DAT_EXTMEM_055b,0x46a6,0xe);
  FUN_CODE_4a31(0x46);
  DAT_EXTMEM_056c = 0;
  do {
    if (DAT_EXTMEM_055c - 1U < DAT_EXTMEM_056c) break;
    DAT_EXTMEM_056b = 0;
    do {
      if (DAT_EXTMEM_055d - 1U < DAT_EXTMEM_056b) break;
      pcVar7 = (char *)CONCAT11(DAT_INTMEM_46,DAT_INTMEM_47);
      FUN_CODE_499e(DAT_EXTMEM_056b);
      DAT_EXTMEM_08c0 = *pcVar7;
      DAT_EXTMEM_08c1 = pcVar7[1];
      pbVar8 = &DAT_EXTMEM_0576;
      uVar6 = FUN_CODE_499e(DAT_EXTMEM_056c,DAT_EXTMEM_08c0);
      bVar5 = *pbVar8;
      bVar2 = pbVar8[1];
      pbVar8 = &DAT_EXTMEM_07a6;
      FUN_CODE_499e(DAT_EXTMEM_056c,uVar6);
      BANK0_R6 = BANK0_R6 ^ bVar5;
      BANK0_R5 = BANK0_R5 ^ bVar2;
      BANK0_R4 = BANK0_R4 & *pbVar8;
      BANK0_R7 = BANK0_R7 & pbVar8[1];
      if ((DAT_EXTMEM_08c1 != '\0' || DAT_EXTMEM_08c0 != '\0') ||
         ((char)((_2_0 & 1 ^ 1) << 7) < '\0')) {
        FUN_CODE_499e(DAT_EXTMEM_056c);
        do {
          PCON = 0x81;
        } while( true );
      }
      bVar1 = DAT_EXTMEM_056b != 0xff;
      DAT_EXTMEM_056b = DAT_EXTMEM_056b + 1;
    } while (bVar1);
    bVar1 = DAT_EXTMEM_056c != 0xff;
    DAT_EXTMEM_056c = DAT_EXTMEM_056c + 1;
  } while (bVar1);
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  while( true ) {
    if (DAT_INTMEM_2e != '\0') {
      DAT_EXTMEM_0554 = 0;
      return;
    }
    if ((0x8b < DAT_INTMEM_2f) << 7 < '\0') break;
    puVar9 = &DAT_EXTMEM_0576;
    FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
    uVar6 = *puVar9;
    uVar3 = puVar9[1];
    puVar9 = &DAT_EXTMEM_07a6;
    FUN_CODE_000e();
    *puVar9 = uVar6;
    puVar9[1] = uVar3;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar4 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar4 = '\0';
    }
    if (cVar4 < '\0') {
      DAT_EXTMEM_0554 = 0;
      return;
    }
  }
  DAT_EXTMEM_0554 = 0;
  return;
}



// ==== FUN_CODE_094e @ CODE:094e  (432 bytes)

char FUN_CODE_094e(char param_1,byte param_2,byte param_3)

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
  BANK0_R5 = DAT_EXTMEM_056d;
  pcVar8 = &DAT_CODE_4796;
  FUN_CODE_498e(DAT_EXTMEM_055b,0x10);
  BANK0_R6 = param_2;
  BANK0_R7 = param_3;
  FUN_CODE_49fe();
  DAT_INTMEM_49 = *pcVar8;
  pbVar9 = &DAT_CODE_4898;
  FUN_CODE_498e(DAT_EXTMEM_056d,5);
  bVar5 = *pbVar9;
  DAT_EXTMEM_08bf = pbVar9[1];
  pcVar8 = (char *)0x8be;
  DAT_EXTMEM_08be = bVar5;
  FUN_CODE_49f2();
  DAT_INTMEM_4b = *pcVar8;
  puVar10 = &DAT_CODE_4896;
  FUN_CODE_498e(DAT_EXTMEM_056d,5);
  BANK0_R2 = *puVar10;
  bVar6 = puVar10[1];
  BANK0_R5 = DAT_EXTMEM_056e;
  pcVar8 = &DAT_CODE_489a;
  FUN_CODE_498e(DAT_EXTMEM_056d,5);
  BANK0_R0 = param_3 - *pcVar8;
  sVar2 = (ushort)(DAT_INTMEM_4b + 1) * (ushort)bVar5;
  bVar5 = (byte)sVar2;
  DAT_INTMEM_4e = bVar6 + bVar5;
  DAT_INTMEM_4d = param_1 + ((char)((ushort)sVar2 >> 8) - ((CARRY1(bVar6,bVar5) << 7) >> 7));
  DAT_INTMEM_4c = *(char *)CONCAT11(DAT_INTMEM_4d,DAT_INTMEM_4e);
  uVar3 = 0;
  bVar5 = 1;
  FUN_CODE_49bb(DAT_INTMEM_4c + -1);
  cVar7 = DAT_EXTMEM_055c - (DAT_EXTMEM_0569 + DAT_INTMEM_4c);
  DAT_EXTMEM_08c2 = uVar3;
  DAT_EXTMEM_08c3 = bVar5;
  if ((byte)(DAT_EXTMEM_0569 + DAT_INTMEM_4c) <= DAT_EXTMEM_055c) {
    DAT_INTMEM_47 = 0;
    do {
      if (DAT_INTMEM_4c - 1U < DAT_INTMEM_47) break;
      DAT_INTMEM_48 = 0;
      do {
        if (DAT_INTMEM_4b - 1U < DAT_INTMEM_48) break;
        DAT_INTMEM_4a = ~(DAT_INTMEM_49 + DAT_INTMEM_48) + DAT_EXTMEM_055d;
        if (DAT_INTMEM_4a + 1U <= DAT_EXTMEM_055d) {
          BANK0_R4 = DAT_EXTMEM_08c2;
          BANK0_R5 = DAT_EXTMEM_08c3;
          pbVar9 = (byte *)(CONCAT11(DAT_INTMEM_4d,DAT_INTMEM_4e) + 1);
          FUN_CODE_49fe(0,DAT_INTMEM_48);
          BANK0_R5 = BANK0_R5 & *pbVar9;
          if (param_3 == 0) {
            uVar3 = 0x7f;
            uVar4 = 0xff;
            FUN_CODE_4911(DAT_INTMEM_4a);
            pbVar9 = &DAT_EXTMEM_0576;
            FUN_CODE_499e(DAT_EXTMEM_0569);
            param_3 = pbVar9[1];
            BANK0_R6 = BANK0_R6 & *pbVar9;
            BANK0_R7 = BANK0_R7 & param_3;
            puVar10 = &DAT_EXTMEM_0576;
            FUN_CODE_499e(DAT_EXTMEM_0569);
            *puVar10 = uVar3;
            puVar10[1] = uVar4;
          }
          else {
            uVar3 = 0x80;
            uVar4 = 0;
            FUN_CODE_4911(DAT_INTMEM_4a);
            pbVar9 = &DAT_EXTMEM_0576;
            FUN_CODE_499e(DAT_EXTMEM_0569);
            param_3 = pbVar9[1];
            BANK0_R6 = BANK0_R6 | *pbVar9;
            BANK0_R7 = BANK0_R7 | param_3;
            puVar10 = &DAT_EXTMEM_0576;
            FUN_CODE_499e(DAT_EXTMEM_0569);
            *puVar10 = uVar3;
            puVar10[1] = uVar4;
          }
        }
        bVar1 = DAT_INTMEM_48 != 0xff;
        DAT_INTMEM_48 = DAT_INTMEM_48 + 1;
      } while (bVar1);
      DAT_EXTMEM_0569 = DAT_EXTMEM_0569 + '\x01';
      FUN_CODE_49c9(1);
      bVar1 = DAT_INTMEM_47 != 0xff;
      DAT_INTMEM_47 = DAT_INTMEM_47 + 1;
    } while (bVar1);
    cVar7 = DAT_EXTMEM_0569 + DAT_INTMEM_46;
    DAT_EXTMEM_0569 = cVar7;
  }
  return cVar7;
}



// ==== FUN_CODE_0afe @ CODE:0afe  (82 bytes)

char FUN_CODE_0afe(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  pbVar3 = &DAT_EXTMEM_0030;
  FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
  DAT_EXTMEM_056d = *pbVar3;
  if (DAT_EXTMEM_056d < 0x30) {
    DAT_EXTMEM_056d = 0x3f;
  }
  bVar1 = DAT_EXTMEM_056d;
  if (_2_3 == '\0') {
    _2_4 = 0;
  }
  else {
    _2_5 = 0;
  }
  bVar2 = DAT_EXTMEM_056d - 0x30;
  if (0xf < DAT_EXTMEM_056d - 0x30) {
    bVar2 = DAT_EXTMEM_056d - 0x40;
    if (_2_3 == '\0') {
      _2_4 = 1;
    }
    else {
      _2_5 = 1;
    }
  }
  DAT_EXTMEM_056d = bVar2;
  return bVar1 - 0x40;
}



// ==== FUN_CODE_0b50 @ CODE:0b50  (95 bytes)

void FUN_CODE_0b50(void)

{
  undefined1 *puVar1;
  
  if (DAT_EXTMEM_056e == '\x04') {
    _2_0 = 1;
    DAT_EXTMEM_056f = DAT_INTMEM_31 + '\x01';
    DAT_INTMEM_31 = -6;
    DAT_INTMEM_30 = '\0';
  }
  else if ((DAT_EXTMEM_056e == '\r') || (DAT_INTMEM_31 == -7 && DAT_INTMEM_30 == '\0')) {
    DAT_EXTMEM_056f = '\0';
    DAT_INTMEM_31 = -6;
    DAT_INTMEM_30 = '\0';
  }
  if (DAT_EXTMEM_056e == '\x04') {
    puVar1 = &DAT_EXTMEM_031e;
    FUN_CODE_4a28(DAT_EXTMEM_0554);
    *puVar1 = 0xd;
    DAT_EXTMEM_0554 = DAT_EXTMEM_0554 + '\x01';
  }
  return;
}



// ==== FUN_CODE_0baf @ CODE:0baf  (635 bytes)

void FUN_CODE_0baf(void)

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
  
  DAT_INTMEM_50 = DAT_EXTMEM_0569;
  do {
    if (0x8b < DAT_INTMEM_50) break;
    puVar7 = &DAT_EXTMEM_0576;
    FUN_CODE_499e(DAT_INTMEM_50);
    *puVar7 = 0;
    puVar7[1] = 0;
    bVar1 = DAT_INTMEM_50 != 0xff;
    DAT_INTMEM_50 = DAT_INTMEM_50 + 1;
  } while (bVar1);
  DAT_EXTMEM_08c5 = DAT_EXTMEM_0569;
  _2_3 = 0;
  DAT_INTMEM_31 = DAT_EXTMEM_056f;
  DAT_INTMEM_30 = 0;
  DAT_EXTMEM_08c4 = DAT_EXTMEM_056f + 1;
  DAT_INTMEM_50 = _2_4 & 1;
  FUN_CODE_0afe();
  if ((char)((_2_6 & 1 & _2_0) << 7) < '\0') {
    if (DAT_INTMEM_50 != 0) {
      _2_4 = 1;
    }
    DAT_INTMEM_50 = DAT_EXTMEM_08c5;
    do {
      if ((DAT_EXTMEM_055c < DAT_INTMEM_50) << 7 < '\0') break;
      puVar7 = &DAT_EXTMEM_068e;
      FUN_CODE_499e(DAT_INTMEM_50);
      uVar4 = puVar7[1];
      uVar6 = 0;
      puVar7 = &DAT_EXTMEM_0576;
      FUN_CODE_499e(DAT_INTMEM_50);
      *puVar7 = uVar6;
      puVar7[1] = uVar4;
      bVar1 = DAT_INTMEM_50 != 0xff;
      DAT_INTMEM_50 = DAT_INTMEM_50 + 1;
    } while (bVar1);
  }
  DAT_EXTMEM_0573 = '\0';
  DAT_INTMEM_31 = DAT_EXTMEM_08c4;
  DAT_INTMEM_30 = '\0';
  do {
    if (DAT_INTMEM_30 != '\0') {
      return;
    }
    if (0xf9 < DAT_INTMEM_31) {
      return;
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(-7 - DAT_INTMEM_31);
    DAT_EXTMEM_056e = *pcVar8;
    if (DAT_EXTMEM_056e == '\x05') {
      FUN_CODE_4a43(0x30);
      _3_0 = _2_4 & 1;
      FUN_CODE_0afe();
      bVar3 = _3_0;
      if (_2_4 != 0) {
        bVar3 = _3_0 & 1 ^ 1;
      }
      if (-1 < (char)(bVar3 << 7)) {
        DAT_EXTMEM_0569 = DAT_EXTMEM_0569 + 2;
      }
      DAT_EXTMEM_0570 = DAT_EXTMEM_0569;
    }
    else if (DAT_EXTMEM_056e == '\x03') {
      FUN_CODE_4a43(0x30);
      _2_3 = 1;
      DAT_INTMEM_50 = _2_5 & 1;
      FUN_CODE_0afe();
      if ((char)((_2_6 & 1 & _2_0) << 7) < '\0') {
        if (DAT_INTMEM_50 != 0) {
          _2_5 = 1;
        }
        DAT_INTMEM_50 = DAT_EXTMEM_08c5;
        do {
          if ((DAT_EXTMEM_055c < DAT_INTMEM_50) << 7 < '\0') break;
          pbVar9 = &DAT_EXTMEM_068e;
          FUN_CODE_499e(DAT_INTMEM_50);
          uVar4 = 0xff;
          uVar6 = 0;
          BANK0_R6 = BANK0_R6 & *pbVar9;
          BANK0_R7 = BANK0_R7 & pbVar9[1];
          pbVar9 = &DAT_EXTMEM_0576;
          FUN_CODE_499e(DAT_INTMEM_50);
          BANK0_R6 = BANK0_R6 | *pbVar9;
          BANK0_R7 = BANK0_R7 | pbVar9[1];
          puVar7 = &DAT_EXTMEM_0576;
          FUN_CODE_499e(DAT_INTMEM_50);
          *puVar7 = uVar4;
          puVar7[1] = uVar6;
          bVar1 = DAT_INTMEM_50 != 0xff;
          DAT_INTMEM_50 = DAT_INTMEM_50 + 1;
        } while (bVar1);
      }
      DAT_EXTMEM_0569 = DAT_EXTMEM_0570;
    }
    else {
      DAT_EXTMEM_0573 = DAT_EXTMEM_0573 + '\x01';
      FUN_CODE_0b50();
      if ((DAT_INTMEM_30 == '\0') && (DAT_INTMEM_31 + 1 < 0xfa)) {
        puVar7 = &DAT_CODE_4898;
        FUN_CODE_498e(DAT_EXTMEM_056d,5);
        DAT_EXTMEM_08be = *puVar7;
        DAT_EXTMEM_08bf = puVar7[1];
        cVar5 = DAT_INTMEM_30;
        if (DAT_INTMEM_31 == 0xff) {
          cVar5 = DAT_INTMEM_30 + '\x01';
        }
        pbVar9 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_08be,cVar5);
        bVar3 = *pbVar9;
        sVar10 = 0x8be;
        FUN_CODE_49f2();
        cVar5 = bVar3 - *(byte *)(sVar10 + 2);
        if (*(byte *)(sVar10 + 2) <= bVar3) {
          pbVar9 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(cVar5,DAT_INTMEM_30);
          bVar3 = *pbVar9;
          sVar10 = 0x8be;
          FUN_CODE_49f2();
          cVar5 = bVar3 - *(byte *)(sVar10 + 2);
          if (*(byte *)(sVar10 + 2) <= bVar3) {
            pbVar9 = &DAT_EXTMEM_0030;
            FUN_CODE_4a09(cVar5);
            bVar3 = *pbVar9;
            sVar10 = 0x8be;
            FUN_CODE_49f2();
            bVar2 = *(char *)(sVar10 + 3) + 1;
            cVar5 = bVar3 - bVar2;
            if (bVar3 < bVar2) {
              pbVar9 = &DAT_EXTMEM_0030;
              FUN_CODE_4a09(cVar5,DAT_INTMEM_30,DAT_INTMEM_31);
              bVar3 = *pbVar9;
              sVar10 = 0x8be;
              FUN_CODE_49f2();
              bVar2 = *(char *)(sVar10 + 3) + 1;
              cVar5 = bVar3 - bVar2;
              if ((bVar3 < bVar2) << 7 < '\0') {
                DAT_INTMEM_46 = 0;
                FUN_CODE_094e(cVar5);
                DAT_EXTMEM_0573 = DAT_EXTMEM_0573 + -1;
                goto LAB_CODE_0dea;
              }
            }
          }
        }
        DAT_INTMEM_46 = DAT_INTMEM_4f;
        FUN_CODE_094e(cVar5);
      }
    }
LAB_CODE_0dea:
    DAT_INTMEM_50 = 0;
    do {
      if (0x8b < DAT_INTMEM_50) break;
      puVar7 = &DAT_EXTMEM_0576;
      FUN_CODE_499e(DAT_INTMEM_50);
      uVar4 = *puVar7;
      uVar6 = puVar7[1];
      puVar7 = &DAT_EXTMEM_068e;
      FUN_CODE_499e(DAT_INTMEM_50);
      *puVar7 = uVar4;
      puVar7[1] = uVar6;
      bVar1 = DAT_INTMEM_50 != 0xff;
      DAT_INTMEM_50 = DAT_INTMEM_50 + 1;
    } while (bVar1);
    bVar1 = 0xfe < DAT_INTMEM_31;
    cVar5 = bVar1 << 7;
    DAT_INTMEM_31 = DAT_INTMEM_31 + 1;
    if (bVar1) {
      DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      cVar5 = '\0';
    }
    if (cVar5 < '\0') {
      return;
    }
  } while( true );
}



// ==== FUN_CODE_0e2a @ CODE:0e2a  (228 bytes)

char FUN_CODE_0e2a(void)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  DAT_INTMEM_46 = 0;
  do {
    pbVar4 = &DAT_CODE_46aa;
    FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
    if ((*pbVar4 < DAT_INTMEM_46) << 7 < '\0') break;
    puVar5 = &DAT_EXTMEM_0576;
    FUN_CODE_499e(DAT_INTMEM_46);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = &DAT_EXTMEM_068e;
    FUN_CODE_499e(DAT_INTMEM_46);
    *puVar5 = uVar3;
    puVar5[1] = uVar2;
    bVar1 = DAT_INTMEM_46 != 0xff;
    DAT_INTMEM_46 = DAT_INTMEM_46 + 1;
  } while (bVar1);
  DAT_INTMEM_47 = 0;
  pcVar6 = &DAT_CODE_46aa;
  FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
  DAT_INTMEM_46 = *pcVar6;
  while( true ) {
    DAT_INTMEM_46 = DAT_INTMEM_46 + -1;
    pcVar6 = &DAT_EXTMEM_0576;
    FUN_CODE_499e(DAT_INTMEM_46);
    if ((pcVar6[1] != '\0' || *pcVar6 != '\0') || (DAT_INTMEM_46 == '\0')) break;
    DAT_INTMEM_47 = DAT_INTMEM_47 + 1;
  }
  DAT_INTMEM_46 = 0;
  do {
    if ((DAT_INTMEM_47 / 2 != 0xff) && (DAT_INTMEM_47 / 2 + 2 <= DAT_INTMEM_46)) break;
    puVar5 = &DAT_EXTMEM_0576;
    FUN_CODE_499e(DAT_INTMEM_46,DAT_INTMEM_47 % 2);
    *puVar5 = 0;
    puVar5[1] = 0;
    bVar1 = DAT_INTMEM_46 != 0xff;
    DAT_INTMEM_46 = DAT_INTMEM_46 + 1;
  } while (bVar1);
  DAT_INTMEM_46 = 0;
  do {
    pbVar4 = &DAT_CODE_46aa;
    FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
    if ((*pbVar4 < DAT_INTMEM_46) << 7 < '\0') {
      return *pbVar4 - DAT_INTMEM_46;
    }
    puVar5 = &DAT_EXTMEM_068e;
    FUN_CODE_499e(DAT_INTMEM_46);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = &DAT_EXTMEM_0576;
    FUN_CODE_000e(DAT_INTMEM_47 % 2,CARRY1(DAT_INTMEM_46,DAT_INTMEM_47 / 2),
                  DAT_INTMEM_46 + DAT_INTMEM_47 / 2);
    *puVar5 = uVar3;
    puVar5[1] = uVar2;
    bVar1 = DAT_INTMEM_46 != 0xff;
    DAT_INTMEM_46 = DAT_INTMEM_46 + 1;
  } while (bVar1);
  return '\0';
}



// ==== FUN_CODE_0f0e @ CODE:0f0e  (1141 bytes)

/* WARNING: Removing unreachable block (CODE,0x1221) */
/* WARNING: Removing unreachable block (CODE,0x1227) */

byte FUN_CODE_0f0e(byte param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  byte bVar7;
  char cVar8;
  char *pcVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  
  if (_2_3 == '\0') {
    DAT_INTMEM_52 = 0;
    DAT_INTMEM_51 = DAT_EXTMEM_055c;
    while( true ) {
      DAT_INTMEM_51 = DAT_INTMEM_51 - 1;
      pcVar9 = &DAT_EXTMEM_0576;
      FUN_CODE_499e(DAT_INTMEM_51);
      if ((pcVar9[1] != '\0' || *pcVar9 != '\0') || (DAT_INTMEM_51 == 0)) break;
      DAT_INTMEM_52 = DAT_INTMEM_52 + 1;
    }
    bVar7 = 0;
    DAT_EXTMEM_08c6 = DAT_INTMEM_52;
    if (DAT_EXTMEM_0573 != 0) {
      DAT_EXTMEM_08c6 = DAT_INTMEM_52 / DAT_EXTMEM_0573;
      bVar7 = DAT_INTMEM_52 % DAT_EXTMEM_0573;
    }
    if (DAT_EXTMEM_08c6 == 0) {
      DAT_EXTMEM_08c6 = 1;
    }
    if (6 < DAT_EXTMEM_08c6) {
      DAT_EXTMEM_08c6 = 6;
    }
    DAT_INTMEM_4f = DAT_EXTMEM_08c6;
    FUN_CODE_0baf(bVar7,0);
    DAT_INTMEM_52 = 0;
    DAT_INTMEM_51 = DAT_EXTMEM_055c;
    while( true ) {
      DAT_INTMEM_51 = DAT_INTMEM_51 - 1;
      pcVar9 = &DAT_EXTMEM_0576;
      FUN_CODE_499e(DAT_INTMEM_51);
      if ((pcVar9[1] != '\0' || *pcVar9 != '\0') || (DAT_INTMEM_51 == 0)) break;
      DAT_INTMEM_52 = DAT_INTMEM_52 + 1;
    }
    DAT_INTMEM_51 = 0;
    do {
      if ((DAT_INTMEM_52 / 2 != 0xff) && (DAT_INTMEM_52 / 2 + 2 <= DAT_INTMEM_51)) break;
      puVar11 = &DAT_EXTMEM_0576;
      FUN_CODE_499e(DAT_INTMEM_52 % 2);
      *puVar11 = 0;
      puVar11[1] = 0;
      bVar1 = DAT_INTMEM_51 != 0xff;
      DAT_INTMEM_51 = DAT_INTMEM_51 + 1;
    } while (bVar1);
    DAT_INTMEM_51 = DAT_EXTMEM_0570;
    do {
      if ((DAT_INTMEM_52 / 2 <= DAT_EXTMEM_055c) &&
         ((DAT_EXTMEM_055c - DAT_INTMEM_52 / 2) + 1 <= DAT_INTMEM_51)) break;
      puVar11 = &DAT_EXTMEM_068e;
      FUN_CODE_499e(DAT_INTMEM_51,DAT_INTMEM_52 % 2);
      uVar3 = *puVar11;
      uVar6 = puVar11[1];
      puVar11 = &DAT_EXTMEM_0576;
      FUN_CODE_000e(DAT_INTMEM_52 % 2,CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2),
                    DAT_INTMEM_51 + DAT_INTMEM_52 / 2);
      *puVar11 = uVar3;
      puVar11[1] = uVar6;
      bVar1 = DAT_INTMEM_51 != 0xff;
      DAT_INTMEM_51 = DAT_INTMEM_51 + 1;
    } while (bVar1);
    _3_1 = 1;
    DAT_INTMEM_2f = DAT_EXTMEM_0570;
    DAT_INTMEM_2e = 0;
    do {
      bVar7 = DAT_EXTMEM_055c;
      if ((DAT_INTMEM_2e != 0) ||
         (bVar7 = DAT_EXTMEM_055c - DAT_INTMEM_2f, (DAT_EXTMEM_055c < DAT_INTMEM_2f) << 7 < '\0'))
      break;
      pbVar10 = &DAT_EXTMEM_0576;
      FUN_CODE_000e(bVar7,0,DAT_INTMEM_2f);
      BANK0_R4 = BANK0_R4 & *pbVar10;
      BANK0_R5 = BANK0_R5 & pbVar10[1];
      _3_1 = 0;
      bVar1 = 0xfe < DAT_INTMEM_2f;
      cVar8 = bVar1 << 7;
      DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
      bVar7 = DAT_INTMEM_2f;
      if (bVar1) {
        bVar7 = DAT_INTMEM_2e + 1;
        cVar8 = '\0';
        DAT_INTMEM_2e = bVar7;
      }
    } while (-1 < cVar8);
    if (-1 < (char)((_3_1 ^ 1) << 7)) {
      DAT_INTMEM_2f = DAT_EXTMEM_0570;
      DAT_INTMEM_2e = 0;
      do {
        if (DAT_INTMEM_2e != 0) {
          return DAT_EXTMEM_055c;
        }
        if ((DAT_EXTMEM_055c < DAT_INTMEM_2f) << 7 < '\0') {
          return DAT_EXTMEM_055c - DAT_INTMEM_2f;
        }
        pbVar10 = &DAT_EXTMEM_0576;
        bVar4 = DAT_INTMEM_2e;
        bVar5 = DAT_INTMEM_2f;
        FUN_CODE_000e(DAT_EXTMEM_055c - DAT_INTMEM_2f);
        bVar2 = 1;
        bVar7 = *pbVar10;
        BANK0_R7 = pbVar10[1];
        BANK0_R6 = bVar7;
        FUN_CODE_49bb(1);
        pbVar10 = &DAT_EXTMEM_0576;
        BANK0_R4 = bVar5;
        BANK0_R5 = bVar4;
        FUN_CODE_000e(DAT_INTMEM_2e,DAT_INTMEM_2f);
        *pbVar10 = bVar7;
        pbVar10[1] = bVar2;
        bVar1 = 0xfe < DAT_INTMEM_2f;
        cVar8 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
        bVar7 = DAT_INTMEM_2f;
        if (bVar1) {
          bVar7 = DAT_INTMEM_2e + 1;
          cVar8 = '\0';
          DAT_INTMEM_2e = bVar7;
        }
      } while (-1 < cVar8);
    }
  }
  else {
    DAT_INTMEM_4f = 1;
    bVar7 = FUN_CODE_0baf();
    if (_2_4 == '\x01') {
      DAT_INTMEM_52 = 0;
      DAT_INTMEM_51 = DAT_EXTMEM_055c;
      while( true ) {
        DAT_INTMEM_51 = DAT_INTMEM_51 - 1;
        puVar11 = &DAT_EXTMEM_0576;
        FUN_CODE_499e(DAT_INTMEM_51);
        if ((puVar11[1] != '\0') || (DAT_INTMEM_51 == 0)) break;
        DAT_INTMEM_52 = DAT_INTMEM_52 + 1;
      }
      DAT_INTMEM_51 = DAT_EXTMEM_0570;
      do {
        if ((DAT_EXTMEM_055c - 1 < DAT_INTMEM_51) << 7 < '\0') break;
        pbVar10 = &DAT_EXTMEM_0576;
        FUN_CODE_499e(DAT_INTMEM_51);
        uVar3 = 0xff;
        uVar6 = 0;
        BANK0_R6 = BANK0_R6 & *pbVar10;
        BANK0_R7 = BANK0_R7 & pbVar10[1];
        puVar11 = &DAT_EXTMEM_0576;
        FUN_CODE_499e(DAT_INTMEM_51);
        *puVar11 = uVar3;
        puVar11[1] = uVar6;
        bVar1 = DAT_INTMEM_51 != 0xff;
        DAT_INTMEM_51 = DAT_INTMEM_51 + 1;
      } while (bVar1);
      DAT_INTMEM_51 = DAT_EXTMEM_0570;
      do {
        if ((DAT_INTMEM_52 / 2 <= DAT_EXTMEM_055c) &&
           (bVar4 = (DAT_EXTMEM_055c - DAT_INTMEM_52 / 2) + 1, bVar7 = DAT_INTMEM_51 - bVar4,
           bVar4 <= DAT_INTMEM_51)) break;
        pbVar10 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(DAT_INTMEM_52 % 2,CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2),
                      DAT_INTMEM_51 + DAT_INTMEM_52 / 2);
        bVar7 = *pbVar10;
        bVar4 = pbVar10[1];
        puVar11 = &DAT_EXTMEM_068e;
        FUN_CODE_499e(DAT_INTMEM_51);
        param_1 = puVar11[1];
        uVar3 = 0;
        BANK0_R5 = BANK0_R5 | bVar7;
        BANK0_R2 = BANK0_R2 | bVar4;
        BANK0_R7 = DAT_INTMEM_51 + DAT_INTMEM_52 / 2;
        puVar11 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(DAT_INTMEM_52 % 2,CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2));
        *puVar11 = uVar3;
        puVar11[1] = param_1;
        bVar1 = DAT_INTMEM_51 != 0xff;
        bVar7 = DAT_INTMEM_51 + 1;
        DAT_INTMEM_51 = bVar7;
      } while (bVar1);
    }
    if (_2_5 == '\x01') {
      _3_1 = 1;
      DAT_INTMEM_2f = DAT_EXTMEM_0570;
      DAT_INTMEM_2e = 0;
      do {
        if ((DAT_INTMEM_2e != 0) || ((DAT_EXTMEM_055c < DAT_INTMEM_2f) << 7 < '\0')) break;
        pbVar10 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(DAT_EXTMEM_055c - DAT_INTMEM_2f,0,DAT_INTMEM_2f);
        param_1 = *pbVar10;
        param_2 = pbVar10[1];
        BANK0_R4 = BANK0_R4 & param_1;
        BANK0_R5 = BANK0_R5 & param_2;
        _3_1 = 0;
        bVar1 = 0xfe < DAT_INTMEM_2f;
        cVar8 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + 1;
          cVar8 = '\0';
        }
      } while (-1 < cVar8);
      DAT_INTMEM_52 = 0;
      DAT_INTMEM_51 = DAT_EXTMEM_055c - 1;
      pbVar10 = &DAT_EXTMEM_0576;
      FUN_CODE_499e(DAT_INTMEM_51);
      BANK0_R6 = BANK0_R6 & *pbVar10;
      BANK0_R7 = BANK0_R7 & pbVar10[1];
      DAT_INTMEM_51 = DAT_EXTMEM_0570;
      do {
        if ((DAT_EXTMEM_055c - 1 < DAT_INTMEM_51) << 7 < '\0') break;
        puVar11 = &DAT_EXTMEM_0576;
        FUN_CODE_499e(DAT_INTMEM_51);
        uVar3 = puVar11[1];
        uVar6 = 0;
        puVar11 = &DAT_EXTMEM_0576;
        FUN_CODE_499e(DAT_INTMEM_51);
        *puVar11 = uVar6;
        puVar11[1] = uVar3;
        bVar1 = DAT_INTMEM_51 != 0xff;
        DAT_INTMEM_51 = DAT_INTMEM_51 + 1;
      } while (bVar1);
      if ((char)((_3_1 & 1 ^ 1) << 7) < '\0') {
        DAT_INTMEM_51 = DAT_EXTMEM_0570;
        do {
          if ((DAT_INTMEM_52 / 2 <= DAT_EXTMEM_055c) &&
             (bVar7 = (DAT_EXTMEM_055c - DAT_INTMEM_52 / 2) + 1, bVar7 <= DAT_INTMEM_51)) {
            return DAT_INTMEM_51 - bVar7;
          }
          FUN_CODE_499e(DAT_INTMEM_51,DAT_INTMEM_52 % 2);
          BANK0_R6 = CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2);
          BANK0_R7 = DAT_INTMEM_51 + DAT_INTMEM_52 / 2;
          BANK0_R2 = 0;
          BANK0_R3 = 0xff;
          pbVar10 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(DAT_INTMEM_52 % 2);
          BANK0_R3 = BANK0_R3 | *pbVar10;
          BANK0_R2 = BANK0_R2 | pbVar10[1];
          pbVar10 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(DAT_INTMEM_52 % 2,CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2),
                        DAT_INTMEM_51 + DAT_INTMEM_52 / 2);
          *pbVar10 = param_2;
          pbVar10[1] = param_1;
          bVar1 = DAT_INTMEM_51 != 0xff;
          bVar7 = DAT_INTMEM_51 + 1;
          DAT_INTMEM_51 = bVar7;
        } while (bVar1);
      }
      else {
        DAT_INTMEM_51 = DAT_EXTMEM_0570;
        do {
          if ((DAT_INTMEM_52 / 2 <= DAT_EXTMEM_055c) &&
             (bVar7 = (DAT_EXTMEM_055c - DAT_INTMEM_52 / 2) + 1, bVar7 <= DAT_INTMEM_51)) {
            return DAT_INTMEM_51 - bVar7;
          }
          pbVar10 = &DAT_EXTMEM_068e;
          FUN_CODE_499e(DAT_INTMEM_51,DAT_INTMEM_52 % 2);
          bVar4 = 1;
          bVar7 = *pbVar10;
          BANK0_R7 = pbVar10[1];
          BANK0_R6 = bVar7;
          FUN_CODE_49bb(1);
          uVar3 = 0xfe;
          uVar6 = 0;
          BANK0_R4 = BANK0_R4 & bVar4;
          BANK0_R5 = BANK0_R5 & bVar7;
          pbVar10 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(DAT_INTMEM_52 % 2,CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2),
                        DAT_INTMEM_51 + DAT_INTMEM_52 / 2);
          BANK0_R4 = BANK0_R4 | *pbVar10;
          BANK0_R5 = BANK0_R5 | pbVar10[1];
          puVar11 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(DAT_INTMEM_52 % 2,CARRY1(DAT_INTMEM_51,DAT_INTMEM_52 / 2),
                        DAT_INTMEM_51 + DAT_INTMEM_52 / 2);
          *puVar11 = uVar3;
          puVar11[1] = uVar6;
          bVar1 = DAT_INTMEM_51 != 0xff;
          bVar7 = DAT_INTMEM_51 + 1;
          DAT_INTMEM_51 = bVar7;
        } while (bVar1);
      }
    }
  }
  return bVar7;
}



// ==== FUN_CODE_1383 @ CODE:1383  (746 bytes)

char FUN_CODE_1383(void)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  
  DAT_INTMEM_47 = 0;
  DAT_INTMEM_46 = 0;
  do {
    if (0xf9 < DAT_INTMEM_46) {
      return DAT_INTMEM_46 + 6;
    }
    pcVar3 = &DAT_EXTMEM_0224;
    FUN_CODE_4a28(DAT_INTMEM_46);
    if (*pcVar3 == '\n') {
      DAT_INTMEM_47 = DAT_INTMEM_46 + 1;
    }
    else {
      pcVar3 = &DAT_EXTMEM_0224;
      FUN_CODE_4a28(DAT_INTMEM_46);
      if (*pcVar3 == '\r') {
        DAT_INTMEM_46 = 0xff;
      }
      else {
        pcVar3 = &DAT_EXTMEM_0224;
        FUN_CODE_4a28(DAT_INTMEM_46);
        if (*pcVar3 != ' ') {
          pcVar3 = &DAT_EXTMEM_0224;
          FUN_CODE_4a28(DAT_INTMEM_46);
          if (*pcVar3 != '-') {
            pcVar3 = &DAT_EXTMEM_0224;
            FUN_CODE_4a28(DAT_INTMEM_46);
            if (*pcVar3 != ',') {
              pcVar3 = &DAT_EXTMEM_0224;
              FUN_CODE_4a28(DAT_INTMEM_46);
              if (*pcVar3 != '.') {
                pcVar3 = &DAT_EXTMEM_0224;
                FUN_CODE_4a28(DAT_INTMEM_46);
                if (*pcVar3 != '/') {
                  pcVar3 = &DAT_EXTMEM_0224;
                  FUN_CODE_4a28(DAT_INTMEM_46);
                  if (*pcVar3 != '(') {
                    if (DAT_INTMEM_46 == DAT_INTMEM_47) {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == ']') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'B') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'E') {
                            pcVar3 = &DAT_EXTMEM_0227;
                            FUN_CODE_4a28(DAT_INTMEM_46);
                            if (*pcVar3 == 'R') {
                              puVar4 = &DAT_EXTMEM_0224;
                              FUN_CODE_4a28(DAT_INTMEM_46);
                              *puVar4 = 0x7d;
                            }
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'W') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'E') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'I') {
                            pcVar3 = &DAT_EXTMEM_0227;
                            FUN_CODE_4a28(DAT_INTMEM_46);
                            if (*pcVar3 == 'T') {
                              pcVar3 = &DAT_EXTMEM_0228;
                              FUN_CODE_4a28(DAT_INTMEM_46);
                              if (*pcVar3 == 'E') {
                                pcVar3 = &DAT_EXTMEM_0229;
                                FUN_CODE_4a28(DAT_INTMEM_46);
                                if (*pcVar3 == 'R') {
                                  puVar4 = &DAT_EXTMEM_0224;
                                  FUN_CODE_4a28(DAT_INTMEM_46);
                                  *puVar4 = 0x77;
                                }
                              }
                            }
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'N') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == '.') {
                          puVar4 = &DAT_EXTMEM_0224;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          *puVar4 = 0x6e;
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == ']') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'B') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == '.') {
                            puVar4 = &DAT_EXTMEM_0224;
                            FUN_CODE_4a28(DAT_INTMEM_46);
                            *puVar4 = 0x7d;
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'M') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'I') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'T') {
                            puVar4 = &DAT_EXTMEM_0224;
                            FUN_CODE_4a28(DAT_INTMEM_46);
                            *puVar4 = 0x6d;
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == ']') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == '.') {
                          puVar4 = &DAT_EXTMEM_0224;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          *puVar4 = 0x7d;
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'V') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'I') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'A') {
                            puVar4 = &DAT_EXTMEM_0224;
                            FUN_CODE_4a28(DAT_INTMEM_46);
                            *puVar4 = 0x76;
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'H') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'B') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'F') {
                            DAT_INTMEM_46 = DAT_INTMEM_46 + 2;
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'Z') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'O') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'B') {
                            DAT_INTMEM_46 = DAT_INTMEM_46 + 2;
                          }
                        }
                      }
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (*pcVar3 == 'K') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46 + 1);
                        if (*pcVar3 == 'V') {
                          pcVar3 = &DAT_EXTMEM_0226;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          if (*pcVar3 == 'A') {
                            pcVar3 = &DAT_EXTMEM_0227;
                            FUN_CODE_4a28(DAT_INTMEM_46);
                            if (*pcVar3 == 'G') {
                              DAT_INTMEM_46 = DAT_INTMEM_46 + 3;
                            }
                          }
                        }
                      }
                    }
                    else {
                      pbVar5 = &DAT_EXTMEM_0224;
                      FUN_CODE_4a28(DAT_INTMEM_46);
                      if (0x40 < *pbVar5) {
                        pbVar5 = &DAT_EXTMEM_0224;
                        FUN_CODE_4a28(DAT_INTMEM_46);
                        if ((*pbVar5 < 0x5e) << 7 < '\0') {
                          pcVar3 = &DAT_EXTMEM_0224;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          cVar2 = *pcVar3 + ' ';
                          pcVar3 = &DAT_EXTMEM_0224;
                          FUN_CODE_4a28(DAT_INTMEM_46);
                          *pcVar3 = cVar2;
                        }
                      }
                    }
                    goto LAB_CODE_1661;
                  }
                }
              }
            }
          }
        }
        DAT_INTMEM_47 = DAT_INTMEM_46 + 1;
      }
    }
LAB_CODE_1661:
    bVar1 = DAT_INTMEM_46 == 0xff;
    DAT_INTMEM_46 = DAT_INTMEM_46 + 1;
    if (bVar1) {
      return '\0';
    }
  } while( true );
}



// ==== FUN_CODE_166d @ CODE:166d  (304 bytes)

char FUN_CODE_166d(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  FUN_CODE_0afe();
  puVar7 = &DAT_CODE_4898;
  FUN_CODE_498e(DAT_EXTMEM_056d,5);
  DAT_EXTMEM_08be = *puVar7;
  DAT_EXTMEM_08bf = puVar7[1];
  DAT_EXTMEM_08c7 = 0;
  pcVar8 = &DAT_CODE_46af;
  FUN_CODE_498e(DAT_EXTMEM_055b,DAT_EXTMEM_08be,0xe);
  if (*pcVar8 == '\0') {
    pcVar8 = &DAT_CODE_46ac;
    FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
    DAT_EXTMEM_08c8 = *pcVar8 + 1;
  }
  else {
    DAT_EXTMEM_08c8 = ~DAT_EXTMEM_056a + DAT_EXTMEM_055c + 2;
  }
  while( true ) {
    cVar3 = DAT_INTMEM_30;
    if (DAT_INTMEM_31 == -1) {
      cVar3 = DAT_INTMEM_30 + '\x01';
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(cVar3);
    if (*pcVar8 == '\x03') break;
    cVar3 = DAT_INTMEM_30;
    if (DAT_INTMEM_31 == -1) {
      cVar3 = DAT_INTMEM_30 + '\x01';
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(cVar3);
    if (*pcVar8 == '\x04') break;
    cVar3 = DAT_INTMEM_30;
    if (DAT_INTMEM_31 == -1) {
      cVar3 = DAT_INTMEM_30 + '\x01';
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(cVar3);
    if (*pcVar8 == '\r') break;
    bVar2 = 0x30;
    FUN_CODE_4a43();
    pcVar8 = &DAT_CODE_4896;
    FUN_CODE_498e(DAT_EXTMEM_056d,5);
    cVar4 = *pcVar8;
    bVar5 = pcVar8[1];
    pcVar8 = &DAT_EXTMEM_0030;
    uVar6 = FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    cVar3 = *pcVar8;
    pcVar8 = &DAT_CODE_489a;
    FUN_CODE_498e(DAT_EXTMEM_056d,uVar6,5);
    cVar3 = cVar3 - *pcVar8;
    pcVar8 = (char *)0x8be;
    FUN_CODE_49f2();
    sVar1 = (ushort)(*pcVar8 + 1) * (ushort)bVar2;
    bVar2 = (byte)sVar1;
    DAT_INTMEM_47 = bVar5 + bVar2;
    DAT_INTMEM_46 = cVar4 + ((char)((ushort)sVar1 >> 8) - ((CARRY1(bVar5,bVar2) << 7) >> 7));
    DAT_EXTMEM_08c7 = DAT_EXTMEM_08c7 + *(char *)CONCAT11(DAT_INTMEM_46,DAT_INTMEM_47) + 1;
    BANK0_R0 = cVar3;
  }
  cVar3 = DAT_INTMEM_30;
  if (DAT_INTMEM_31 == -1) {
    cVar3 = DAT_INTMEM_30 + '\x01';
  }
  pcVar8 = &DAT_EXTMEM_0030;
  FUN_CODE_4a09(cVar3);
  if (*pcVar8 == '\r') {
    DAT_INTMEM_2f = 1;
    DAT_INTMEM_2e = 0;
  }
  _2_7 = DAT_EXTMEM_08c8 < DAT_EXTMEM_08c7;
  return DAT_EXTMEM_08c8 - DAT_EXTMEM_08c7;
}



// ==== thunk_FUN_CODE_179f @ CODE:179d  (2 bytes)

void thunk_FUN_CODE_179f(void)

{
  bool bVar1;
  short sVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined2 uVar10;
  
  DAT_INTMEM_34 = 1;
  DAT_INTMEM_35 = 0x30;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  do {
    if ((DAT_INTMEM_2e != '\0') || ((0xf3 < DAT_INTMEM_2f) << 7 < '\0')) break;
    puVar8 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4a09(-0xd - DAT_INTMEM_2f);
    uVar4 = *puVar8;
    puVar8 = &DAT_EXTMEM_0224;
    FUN_CODE_4a09();
    *puVar8 = uVar4;
    puVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09();
    *puVar8 = 0xd;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar5 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar5 = '\0';
    }
  } while (-1 < cVar5);
  bVar3 = P1_4;
  if ((char)((bVar3 & 1 ^ 1) << 7) < '\0') {
    FUN_CODE_1383();
  }
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = -7;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  while( true ) {
    pcVar9 = &DAT_EXTMEM_0224;
    FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
    if (*pcVar9 == '\r') break;
    pcVar9 = &DAT_EXTMEM_0224;
    FUN_CODE_4a09();
    if (*pcVar9 != ' ') {
      DAT_EXTMEM_0557 = DAT_INTMEM_2e;
      DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    }
    FUN_CODE_4a43(0x2e);
  }
  cVar5 = DAT_EXTMEM_0557;
  if (DAT_EXTMEM_0558 == -1) {
    cVar5 = DAT_EXTMEM_0557 + '\x01';
  }
  puVar8 = &DAT_EXTMEM_0224;
  FUN_CODE_4a09(cVar5);
  *puVar8 = 0xd;
  puVar8 = &DAT_EXTMEM_0226;
  FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
  *puVar8 = 0xd;
  DAT_EXTMEM_0557 = 0;
  DAT_EXTMEM_0558 = 0;
  DAT_INTMEM_31 = '\0';
  DAT_INTMEM_30 = '\0';
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = 0;
  DAT_EXTMEM_0559 = '\0';
  DAT_EXTMEM_055a = '\0';
  if (_2_1 == '\0') {
    DAT_INTMEM_34 = 2;
    DAT_INTMEM_35 = 0x24;
  }
  else {
    sVar2 = (ushort)(DAT_EXTMEM_012e + 0xbf) * 3;
    DAT_INTMEM_34 = 2;
    DAT_INTMEM_35 = 0x24;
    while( true ) {
      DAT_EXTMEM_0559 = (char)((ushort)sVar2 >> 8);
      DAT_EXTMEM_055a = (byte)sVar2;
      pcVar9 = &DAT_EXTMEM_0224;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      if ((*pcVar9 == '\r') || (DAT_EXTMEM_055a == '\0' && DAT_EXTMEM_0559 == '\0')) break;
      pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      if (*pcVar9 == '\n') {
        FUN_CODE_49ad(0x559);
      }
      FUN_CODE_4a43(0x2e);
      sVar2 = CONCAT11(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
    }
    uVar10 = 0x224;
    FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
    DAT_INTMEM_34 = (undefined1)((ushort)uVar10 >> 8);
    DAT_INTMEM_35 = (undefined1)uVar10;
    DAT_INTMEM_2f = 0;
    DAT_INTMEM_2e = 0;
  }
  while( true ) {
    pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    cVar6 = DAT_INTMEM_30;
    cVar7 = DAT_INTMEM_31;
    FUN_CODE_4a09();
    cVar5 = '\0';
    if (((*pcVar9 == '\r') || (cVar5 = -6, cVar6 != '\0')) ||
       (cVar5 = -6 - (cVar7 + 1U), 0xfa < cVar7 + 1U)) break;
    puVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(cVar5,DAT_INTMEM_2e,DAT_INTMEM_2f);
    *puVar8 = 0x49;
    DAT_EXTMEM_0557 = DAT_INTMEM_2e;
    DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    FUN_CODE_4a43(0x2e);
    _2_3 = '\x01';
    while( true ) {
      pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
      if (*pcVar9 == '\n') break;
      puVar8 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09();
      uVar4 = *puVar8;
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar8 = uVar4;
      FUN_CODE_4a43(0x2e);
      FUN_CODE_4a43(0x30);
    }
    FUN_CODE_4a43(0x30);
    pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar9 == '\n') {
      _2_3 = '\0';
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
      *puVar8 = 0x42;
      FUN_CODE_4a43(0x30);
    }
    if (_2_3 != '\0') {
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar8 = 3;
      FUN_CODE_4a43(0x2e);
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar8 = 0x45;
      FUN_CODE_4a43(0x2e);
      while( true ) {
        pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
        if (*pcVar9 == '\n') break;
        puVar8 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4a09();
        uVar4 = *puVar8;
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
        *puVar8 = uVar4;
        FUN_CODE_4a43(0x2e);
        FUN_CODE_4a43(0x30);
      }
      FUN_CODE_4a43(0x30);
    }
    FUN_CODE_4a43(0x30);
    pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar9 != '\n') {
      pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09();
      if (*pcVar9 != '\r') {
        if (_2_1 == '\0') {
          puVar8 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar8 = 4;
        }
        else {
          puVar8 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar8 = 0xd;
        }
        FUN_CODE_4a43(0x2e);
      }
    }
  }
  puVar8 = &DAT_EXTMEM_0030;
  FUN_CODE_4a09(cVar5,DAT_INTMEM_2e,DAT_INTMEM_2f);
  *puVar8 = 0xd;
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = 0;
  DAT_INTMEM_31 = 0;
  DAT_INTMEM_30 = '\0';
  DAT_EXTMEM_0559 = '\0';
  DAT_EXTMEM_055a = 0;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  while (DAT_INTMEM_2f == '\0' && DAT_INTMEM_2e == '\0') {
    DAT_EXTMEM_0557 = DAT_INTMEM_30;
    DAT_EXTMEM_0558 = DAT_INTMEM_31;
    DAT_EXTMEM_0559 = DAT_INTMEM_30;
    DAT_EXTMEM_055a = DAT_INTMEM_31;
    pcVar9 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    _2_3 = *pcVar9 != 'B';
    if ((bool)_2_3) {
      FUN_CODE_166d();
      if (_2_7 != '\0') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x48;
      }
      bVar1 = 0xfd < DAT_INTMEM_31;
      DAT_INTMEM_31 = DAT_INTMEM_31 + 2;
      if (bVar1) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
      pcVar9 = &DAT_EXTMEM_0030;
      DAT_EXTMEM_0557 = DAT_INTMEM_30;
      DAT_EXTMEM_0558 = DAT_INTMEM_31;
      FUN_CODE_4a09(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
      if (*pcVar9 == 'H') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x44;
      }
      FUN_CODE_166d();
      if (_2_7 != '\0') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x44;
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
        *puVar8 = 0x48;
      }
      if (0xfd < DAT_INTMEM_31) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
    }
    else {
      FUN_CODE_166d();
      if (_2_7 != '\0') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x47;
        DAT_INTMEM_30 = DAT_EXTMEM_0557;
        DAT_INTMEM_31 = DAT_EXTMEM_0558;
        FUN_CODE_166d();
        if (_2_7 != '\0') {
          puVar8 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
          *puVar8 = 0x46;
        }
      }
      if (0xfd < DAT_INTMEM_31) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
    }
    DAT_INTMEM_31 = DAT_INTMEM_31 + 2;
  }
  return;
}



// ==== FUN_CODE_179f @ CODE:179f  (975 bytes)

void FUN_CODE_179f(void)

{
  bool bVar1;
  short sVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined2 uVar10;
  
  DAT_INTMEM_34 = 1;
  DAT_INTMEM_35 = 0x30;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  do {
    if ((DAT_INTMEM_2e != '\0') || ((0xf3 < DAT_INTMEM_2f) << 7 < '\0')) break;
    puVar8 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4a09(-0xd - DAT_INTMEM_2f);
    uVar4 = *puVar8;
    puVar8 = &DAT_EXTMEM_0224;
    FUN_CODE_4a09();
    *puVar8 = uVar4;
    puVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09();
    *puVar8 = 0xd;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar5 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar5 = '\0';
    }
  } while (-1 < cVar5);
  bVar3 = P1_4;
  if ((char)((bVar3 & 1 ^ 1) << 7) < '\0') {
    FUN_CODE_1383();
  }
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = -7;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  while( true ) {
    pcVar9 = &DAT_EXTMEM_0224;
    FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
    if (*pcVar9 == '\r') break;
    pcVar9 = &DAT_EXTMEM_0224;
    FUN_CODE_4a09();
    if (*pcVar9 != ' ') {
      DAT_EXTMEM_0557 = DAT_INTMEM_2e;
      DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    }
    FUN_CODE_4a43(0x2e);
  }
  cVar5 = DAT_EXTMEM_0557;
  if (DAT_EXTMEM_0558 == -1) {
    cVar5 = DAT_EXTMEM_0557 + '\x01';
  }
  puVar8 = &DAT_EXTMEM_0224;
  FUN_CODE_4a09(cVar5);
  *puVar8 = 0xd;
  puVar8 = &DAT_EXTMEM_0226;
  FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
  *puVar8 = 0xd;
  DAT_EXTMEM_0557 = 0;
  DAT_EXTMEM_0558 = 0;
  DAT_INTMEM_31 = '\0';
  DAT_INTMEM_30 = '\0';
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = 0;
  DAT_EXTMEM_0559 = '\0';
  DAT_EXTMEM_055a = '\0';
  if (_2_1 == '\0') {
    DAT_INTMEM_34 = 2;
    DAT_INTMEM_35 = 0x24;
  }
  else {
    sVar2 = (ushort)(DAT_EXTMEM_012e + 0xbf) * 3;
    DAT_INTMEM_34 = 2;
    DAT_INTMEM_35 = 0x24;
    while( true ) {
      DAT_EXTMEM_0559 = (char)((ushort)sVar2 >> 8);
      DAT_EXTMEM_055a = (byte)sVar2;
      pcVar9 = &DAT_EXTMEM_0224;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      if ((*pcVar9 == '\r') || (DAT_EXTMEM_055a == '\0' && DAT_EXTMEM_0559 == '\0')) break;
      pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      if (*pcVar9 == '\n') {
        FUN_CODE_49ad(0x559);
      }
      FUN_CODE_4a43(0x2e);
      sVar2 = CONCAT11(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
    }
    uVar10 = 0x224;
    FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
    DAT_INTMEM_34 = (undefined1)((ushort)uVar10 >> 8);
    DAT_INTMEM_35 = (undefined1)uVar10;
    DAT_INTMEM_2f = 0;
    DAT_INTMEM_2e = 0;
  }
  while( true ) {
    pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    cVar6 = DAT_INTMEM_30;
    cVar7 = DAT_INTMEM_31;
    FUN_CODE_4a09();
    cVar5 = '\0';
    if (((*pcVar9 == '\r') || (cVar5 = -6, cVar6 != '\0')) ||
       (cVar5 = -6 - (cVar7 + 1U), 0xfa < cVar7 + 1U)) break;
    puVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(cVar5,DAT_INTMEM_2e,DAT_INTMEM_2f);
    *puVar8 = 0x49;
    DAT_EXTMEM_0557 = DAT_INTMEM_2e;
    DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    FUN_CODE_4a43(0x2e);
    _2_3 = '\x01';
    while( true ) {
      pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
      if (*pcVar9 == '\n') break;
      puVar8 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09();
      uVar4 = *puVar8;
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar8 = uVar4;
      FUN_CODE_4a43(0x2e);
      FUN_CODE_4a43(0x30);
    }
    FUN_CODE_4a43(0x30);
    pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar9 == '\n') {
      _2_3 = '\0';
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
      *puVar8 = 0x42;
      FUN_CODE_4a43(0x30);
    }
    if (_2_3 != '\0') {
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar8 = 3;
      FUN_CODE_4a43(0x2e);
      puVar8 = &DAT_EXTMEM_0030;
      FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar8 = 0x45;
      FUN_CODE_4a43(0x2e);
      while( true ) {
        pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
        if (*pcVar9 == '\n') break;
        puVar8 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4a09();
        uVar4 = *puVar8;
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
        *puVar8 = uVar4;
        FUN_CODE_4a43(0x2e);
        FUN_CODE_4a43(0x30);
      }
      FUN_CODE_4a43(0x30);
    }
    FUN_CODE_4a43(0x30);
    pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar9 != '\n') {
      pcVar9 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4a09();
      if (*pcVar9 != '\r') {
        if (_2_1 == '\0') {
          puVar8 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar8 = 4;
        }
        else {
          puVar8 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar8 = 0xd;
        }
        FUN_CODE_4a43(0x2e);
      }
    }
  }
  puVar8 = &DAT_EXTMEM_0030;
  FUN_CODE_4a09(cVar5,DAT_INTMEM_2e,DAT_INTMEM_2f);
  *puVar8 = 0xd;
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = 0;
  DAT_INTMEM_31 = 0;
  DAT_INTMEM_30 = '\0';
  DAT_EXTMEM_0559 = '\0';
  DAT_EXTMEM_055a = 0;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  while (DAT_INTMEM_2f == '\0' && DAT_INTMEM_2e == '\0') {
    DAT_EXTMEM_0557 = DAT_INTMEM_30;
    DAT_EXTMEM_0558 = DAT_INTMEM_31;
    DAT_EXTMEM_0559 = DAT_INTMEM_30;
    DAT_EXTMEM_055a = DAT_INTMEM_31;
    pcVar9 = &DAT_EXTMEM_0030;
    FUN_CODE_4a09(DAT_INTMEM_30,DAT_INTMEM_31);
    _2_3 = *pcVar9 != 'B';
    if ((bool)_2_3) {
      FUN_CODE_166d();
      if (_2_7 != '\0') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x48;
      }
      bVar1 = 0xfd < DAT_INTMEM_31;
      DAT_INTMEM_31 = DAT_INTMEM_31 + 2;
      if (bVar1) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
      pcVar9 = &DAT_EXTMEM_0030;
      DAT_EXTMEM_0557 = DAT_INTMEM_30;
      DAT_EXTMEM_0558 = DAT_INTMEM_31;
      FUN_CODE_4a09(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
      if (*pcVar9 == 'H') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x44;
      }
      FUN_CODE_166d();
      if (_2_7 != '\0') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x44;
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
        *puVar8 = 0x48;
      }
      if (0xfd < DAT_INTMEM_31) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
    }
    else {
      FUN_CODE_166d();
      if (_2_7 != '\0') {
        puVar8 = &DAT_EXTMEM_0030;
        FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar8 = 0x47;
        DAT_INTMEM_30 = DAT_EXTMEM_0557;
        DAT_INTMEM_31 = DAT_EXTMEM_0558;
        FUN_CODE_166d();
        if (_2_7 != '\0') {
          puVar8 = &DAT_EXTMEM_0030;
          FUN_CODE_4a09(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
          *puVar8 = 0x46;
        }
      }
      if (0xfd < DAT_INTMEM_31) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
    }
    DAT_INTMEM_31 = DAT_INTMEM_31 + 2;
  }
  return;
}



// ==== FUN_CODE_1c54 @ CODE:1c54  (528 bytes)

void FUN_CODE_1c54(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  undefined1 *puVar8;
  char *pcVar9;
  
  TMOD = 0x21;
  TCON = 0x50;
  SCON = 0xd8;
  TL1 = 0;
  TH1 = 0xe6;
  TL0 = 0xc;
  TH0 = 0xfe;
  IP = 0x10;
  PCON = 0x80;
  DAT_INTMEM_2f = 1;
  DAT_INTMEM_2e = '\0';
  do {
    if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
    *(undefined1 *)(DAT_INTMEM_2f + 0x24) = 0x20;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar7 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar7 = '\0';
    }
  } while (-1 < cVar7);
  DAT_INTMEM_24 = 0x39;
  DAT_EXTMEM_0015 = 0;
  DAT_EXTMEM_0016 = 0;
  DAT_EXTMEM_0019 = 0;
  DAT_EXTMEM_001a = 0;
  DAT_EXTMEM_001d = 0;
  DAT_EXTMEM_001e = 0;
  DAT_EXTMEM_0023 = 0;
  DAT_EXTMEM_0024 = 0;
  DAT_EXTMEM_0029 = 0;
  DAT_EXTMEM_002a = 0;
  DAT_INTMEM_29 = 0xd;
  LATCH1_ES_FP2800 = 0;
  LATCH0_EZ_row_color_LED_bank = 0;
  _1_6 = 0;
  T0 = 1;
  _1_4 = 0;
  DAT_EXTMEM_056c = 0;
  DAT_EXTMEM_056b = 0;
  _2_2 = 0;
  DAT_INTMEM_31 = 0;
  DAT_INTMEM_30 = 0;
  _2_3 = 0;
  _2_5 = 0;
  _2_4 = 0;
  _2_6 = 0;
  DAT_EXTMEM_056d = 2;
  _2_0 = 0;
  _2_1 = 0;
  DAT_INTMEM_33 = 0;
  DAT_INTMEM_32 = 0;
  DAT_EXTMEM_002d = 0;
  DAT_EXTMEM_0555 = 0;
  _0_4 = 0;
  _0_5 = 0;
  DAT_EXTMEM_0554 = 0;
  _0_2 = 1;
  DAT_EXTMEM_0553 = 0;
  DAT_INTMEM_2d = 0;
  _0_1 = 0;
  _0_6 = 1;
  _1_0 = 0;
  DAT_EXTMEM_002e = 0xff;
  _1_1 = 0;
  _1_2 = 0;
  _1_3 = 0;
  DAT_EXTMEM_0570 = 0;
  DAT_EXTMEM_0569 = 0;
  DAT_EXTMEM_056a = 0;
  DAT_EXTMEM_0571 = 0;
  _0_0 = 0;
  DAT_EXTMEM_0560 = 0x16;
  DAT_EXTMEM_0561 = 0;
  DAT_INTMEM_2b = 0x2f;
  DAT_INTMEM_2c = 0xff;
  DAT_EXTMEM_0562 = 0xff;
  DAT_EXTMEM_0563 = 0xff;
  DAT_EXTMEM_0556 = 0;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  do {
    if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
    puVar8 = &DAT_EXTMEM_0576;
    FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8 = &DAT_EXTMEM_068e;
    FUN_CODE_000e();
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8 = &DAT_EXTMEM_07a6;
    FUN_CODE_000e();
    *puVar8 = 0;
    puVar8[1] = 0;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar7 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar7 = '\0';
    }
  } while (-1 < cVar7);
  DAT_EXTMEM_0030 = 0x42;
  DAT_EXTMEM_0031 = 0x20;
  DAT_EXTMEM_0032 = 0xd;
  bVar2 = P1;
  bVar3 = P1;
  bVar4 = P1;
  bVar5 = P1;
  DAT_EXTMEM_055b = ~bVar5 & 8 | (~bVar4 & 2) << 1 | (~bVar3 & 4) >> 1 | ~bVar2 & 1;
  puVar8 = &DAT_CODE_46aa;
  uVar6 = FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
  BANK0_R4 = *puVar8;
  pcVar9 = &DAT_CODE_46ac;
  FUN_CODE_498e(DAT_EXTMEM_055b,uVar6,0xe);
  DAT_EXTMEM_055c = param_1 + *pcVar9;
  puVar8 = &DAT_CODE_46ab;
  FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
  DAT_EXTMEM_055d = *puVar8;
  FUN_CODE_498e(DAT_EXTMEM_055b,0x46a8,0xe);
  FUN_CODE_4a31(0x36);
  puVar8 = &DAT_CODE_46b3;
  FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
  DAT_INTMEM_24 = *puVar8;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  while( true ) {
    if (DAT_INTMEM_2e != '\0') {
      return;
    }
    if ((0x40 < DAT_INTMEM_2f) << 7 < '\0') break;
    puVar8 = &DAT_EXTMEM_031e;
    FUN_CODE_4a09('@' - DAT_INTMEM_2f);
    *puVar8 = 0x20;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar7 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar7 = '\0';
    }
    if (cVar7 < '\0') {
      return;
    }
  }
  return;
}



// ==== FUN_CODE_1e64 @ CODE:1e64  (75 bytes)

char FUN_CODE_1e64(void)

{
  for (DAT_INTMEM_46 = 1; (DAT_INTMEM_46 < 5 && (*(char *)(DAT_INTMEM_46 + 0x24) == '0'));
      DAT_INTMEM_46 = DAT_INTMEM_46 + 1) {
  }
  DAT_INTMEM_47 = 1;
  for (; DAT_INTMEM_46 < 5; DAT_INTMEM_46 = DAT_INTMEM_46 + 1) {
    BANK0_R6 = *(undefined1 *)(DAT_INTMEM_46 + 0x24);
    *(undefined1 *)(DAT_INTMEM_47 + 0x24) = BANK0_R6;
    DAT_INTMEM_47 = DAT_INTMEM_47 + 1;
  }
  for (; DAT_INTMEM_47 < 5; DAT_INTMEM_47 = DAT_INTMEM_47 + 1) {
    *(undefined1 *)(DAT_INTMEM_47 + 0x24) = 0x20;
  }
  return DAT_INTMEM_47 - 5;
}



// ==== FUN_CODE_1eaf @ CODE:1eaf  (2390 bytes)

void FUN_CODE_1eaf(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  IE = 0;
  FUN_CODE_1c54();
  IE = 0x82;
  IE = 0x92;
  FUN_CODE_076b();
  IE = 0x92;
  do {
    do {
      if ((char)(((_0_4 & 1 ^ 1) & _0_1) << 7) < '\0') {
        DAT_EXTMEM_0562 = 0xff;
        DAT_EXTMEM_0563 = 0xff;
        _0_1 = 0;
        if (_0_6 == 0) {
          cVar3 = LATCH3_7SEG_802_15;
          cVar2 = LATCH4_802_15;
          if ((DAT_EXTMEM_0016 != cVar2) || (DAT_EXTMEM_0015 != cVar3)) {
            LATCH3_7SEG_802_15 = DAT_EXTMEM_0015;
            LATCH4_802_15 = DAT_EXTMEM_0016;
            _2_0 = 0;
            _2_2 = 1;
            DAT_EXTMEM_0017 = LATCH3_7SEG_802_15;
            DAT_EXTMEM_0018 = LATCH4_802_15;
            BANK0_R4 = BANK0_R4 ^ 0xff;
            BANK0_R5 = BANK0_R5 ^ 0xff;
          }
          cVar3 = LATCH5;
          bVar5 = LATCH6_802_15;
          if ((DAT_EXTMEM_001a != bVar5) || (DAT_EXTMEM_0019 != cVar3)) {
            LATCH5 = DAT_EXTMEM_0019;
            LATCH6_802_15 = DAT_EXTMEM_001a;
            _2_0 = 0;
            _2_2 = 1;
            DAT_EXTMEM_001b = LATCH5;
            DAT_EXTMEM_001c = LATCH6_802_15;
            BANK0_R4 = BANK0_R4 ^ 0xff;
            BANK0_R5 = BANK0_R5 ^ 0xff;
          }
          BANK3_R0 = 3;
          BANK3_R1 = 0x5f;
          BANK3_R2 = 0xd;
          BANK3_R4 = 0xf9;
          BANK3_R3 = 0;
          cVar3 = DAT_EXTMEM_0019;
          bVar5 = DAT_EXTMEM_001a;
          FUN_CODE_491d();
          if ((cVar3 != '\0') || (DAT_EXTMEM_0558 = bVar5, 0xf9 < bVar5)) {
            DAT_EXTMEM_0458 = 0xd;
            DAT_EXTMEM_0558 = 0xf9;
          }
          DAT_EXTMEM_0557 = '\0';
        }
        else {
          _2_0 = 0;
        }
        if (_0_7 != '\0') {
          if (((char)((_2_2 & 1 ^ 1) << 7) < '\0') &&
             ((((DAT_EXTMEM_055e != '\0' || (1 < DAT_EXTMEM_055f)) &&
               ((char)((_2_0 & 1 ^ 1) << 7) < '\0')) && (DAT_EXTMEM_055b == -1)))) {
            _2_2 = 1;
          }
          _0_7 = '\0';
          if (DAT_EXTMEM_055f == 0 && DAT_EXTMEM_055e == '\0') {
            DAT_EXTMEM_055e = DAT_EXTMEM_0560;
            DAT_EXTMEM_055f = DAT_EXTMEM_0561;
          }
        }
        DAT_EXTMEM_002d = 0;
      }
      if ((DAT_EXTMEM_0556 != '\0') && ((char)((_0_6 & 1 ^ 1) << 7) < '\0')) {
        DAT_INTMEM_2f = 0;
        DAT_INTMEM_2e = '\0';
        do {
          if ((DAT_INTMEM_2e != '\0') || ((0xf8 < DAT_INTMEM_2f) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_0459;
          FUN_CODE_4a09(-8 - DAT_INTMEM_2f);
          uVar4 = *puVar7;
          puVar7 = &DAT_EXTMEM_012a;
          FUN_CODE_4a09();
          *puVar7 = uVar4;
          pcVar8 = &DAT_EXTMEM_0459;
          FUN_CODE_4a09();
          if (*pcVar8 == '\r') {
            DAT_INTMEM_2f = 0xfb;
            DAT_INTMEM_2e = '\0';
          }
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar3 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar3 = '\0';
          }
        } while (-1 < cVar3);
        DAT_EXTMEM_0223 = 0xd;
        _2_2 = 1;
        _2_0 = 0;
        _2_1 = 0;
        DAT_EXTMEM_0556 = '\0';
      }
      if (_2_2 == 1) {
        _2_2 = 0;
        DAT_EXTMEM_0569 = 0;
        DAT_EXTMEM_0570 = 0;
        DAT_INTMEM_32 = 5;
        DAT_INTMEM_33 = 0xdc;
        DAT_EXTMEM_056f = 0;
        DAT_EXTMEM_0554 = 0;
        DAT_INTMEM_2f = 1;
        DAT_INTMEM_2e = '\0';
        do {
          if ((DAT_INTMEM_2e != '\0') || ((4 < DAT_INTMEM_2f) << 7 < '\0')) break;
          uVar4 = 0;
          if (DAT_INTMEM_2f == 0) {
            uVar4 = 0xff;
          }
          puVar7 = &DAT_EXTMEM_0011;
          FUN_CODE_4a09('\x04' - DAT_INTMEM_2f,uVar4);
          *(undefined1 *)(DAT_INTMEM_2f + 0x24) = *puVar7;
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar3 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar3 = '\0';
          }
        } while (-1 < cVar3);
        FUN_CODE_0026();
        FUN_CODE_1e64();
        DAT_INTMEM_2f = 0;
        DAT_INTMEM_2e = '\0';
        do {
          if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
          *puVar7 = 0;
          puVar7[1] = 0;
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar3 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar3 = '\0';
          }
        } while (-1 < cVar3);
        DAT_EXTMEM_056a = '\0';
        DAT_EXTMEM_0569 = '\0';
        DAT_EXTMEM_0570 = '\0';
        pcVar8 = &DAT_CODE_46aa;
        FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_46af;
          FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\x01') {
            pcVar8 = &DAT_CODE_46b2;
            FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
            if (*pcVar8 == '\0') {
              DAT_INTMEM_29 = 0xd;
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
                puVar6 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
                puVar7 = &DAT_EXTMEM_0030;
                FUN_CODE_4a09();
                *puVar7 = *puVar6;
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar3 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar3 = '\0';
                }
              } while (-1 < cVar3);
              DAT_EXTMEM_0572 = 4;
              if (((((DAT_INTMEM_28 == ' ') || (DAT_INTMEM_28 == '\r')) &&
                   ((DAT_EXTMEM_0572 = 3, DAT_INTMEM_27 == ' ' || (DAT_INTMEM_27 == '\r')))) &&
                  ((DAT_EXTMEM_0572 = 2, DAT_INTMEM_26 == ' ' || (DAT_INTMEM_26 == '\r')))) &&
                 ((DAT_EXTMEM_0572 = 1, DAT_INTMEM_25 == ' ' || (DAT_INTMEM_25 == '\r')))) {
                DAT_EXTMEM_0572 = 0;
              }
              pcVar8 = &DAT_CODE_4698;
              FUN_CODE_498e(DAT_EXTMEM_0572,3);
              DAT_EXTMEM_056a = *pcVar8;
              puVar7 = &DAT_CODE_4697;
              FUN_CODE_498e(DAT_EXTMEM_0572,3);
              DAT_EXTMEM_0569 = *puVar7;
              _0_2 = 0;
              puVar7 = &DAT_CODE_4699;
              FUN_CODE_498e(DAT_EXTMEM_0572,3);
              DAT_INTMEM_4f = *puVar7;
              FUN_CODE_0baf();
              DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
              DAT_EXTMEM_0570 = DAT_EXTMEM_056a;
            }
          }
        }
        pcVar8 = &DAT_CODE_46aa;
        FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_46af;
          FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\x01') {
            pcVar8 = &DAT_CODE_46b2;
            FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
            if (*pcVar8 == '\x01') {
              DAT_INTMEM_29 = 0xd;
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
                puVar6 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
                puVar7 = &DAT_EXTMEM_0030;
                FUN_CODE_4a09();
                *puVar7 = *puVar6;
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar3 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar3 = '\0';
                }
              } while (-1 < cVar3);
              DAT_EXTMEM_0569 = 0;
              _0_2 = 0;
              puVar7 = &DAT_CODE_46b0;
              FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
              DAT_INTMEM_4f = *puVar7;
              FUN_CODE_0baf();
              DAT_EXTMEM_056a = '\0';
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
                pcVar8 = &DAT_EXTMEM_0576;
                FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
                if (pcVar8[1] != '\0' || *pcVar8 != '\0') {
                  DAT_EXTMEM_056a = DAT_INTMEM_2f + 1;
                }
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar3 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar3 = '\0';
                }
              } while (-1 < cVar3);
              DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
              DAT_EXTMEM_0570 = DAT_EXTMEM_056a;
            }
          }
        }
        pcVar8 = &DAT_CODE_46aa;
        FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_46af;
          FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\0') {
            pcVar8 = &DAT_CODE_46b1;
            FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
            if (*pcVar8 == '\0') {
              DAT_INTMEM_29 = 0xd;
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
                puVar6 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
                puVar7 = &DAT_EXTMEM_0030;
                FUN_CODE_4a09();
                *puVar7 = *puVar6;
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar3 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar3 = '\0';
                }
              } while (-1 < cVar3);
              DAT_EXTMEM_0569 = 0;
              _0_2 = 0;
              puVar7 = &DAT_CODE_46b0;
              FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
              DAT_INTMEM_4f = *puVar7;
              FUN_CODE_0baf();
              pcVar8 = &DAT_CODE_46aa;
              FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
              DAT_EXTMEM_0569 = *pcVar8;
              DAT_EXTMEM_056a = DAT_EXTMEM_0569;
              DAT_EXTMEM_0570 = DAT_EXTMEM_0569;
            }
          }
        }
        pcVar8 = &DAT_CODE_46aa;
        FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_46b1;
          FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\x01') {
            DAT_INTMEM_29 = 0xd;
            DAT_INTMEM_2f = 0;
            DAT_INTMEM_2e = '\0';
            do {
              if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
              puVar6 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
              puVar7 = &DAT_EXTMEM_0030;
              FUN_CODE_4a09();
              *puVar7 = *puVar6;
              bVar1 = 0xfe < DAT_INTMEM_2f;
              cVar3 = bVar1 << 7;
              DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
              if (bVar1) {
                DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                cVar3 = '\0';
              }
            } while (-1 < cVar3);
            DAT_EXTMEM_0569 = 0;
            _0_2 = 0;
            puVar7 = &DAT_CODE_46b0;
            FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
            DAT_INTMEM_4f = *puVar7;
            FUN_CODE_0baf();
            FUN_CODE_0e2a();
            pcVar8 = &DAT_CODE_46aa;
            FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
            DAT_EXTMEM_0569 = *pcVar8;
            DAT_EXTMEM_056a = DAT_EXTMEM_0569;
            DAT_EXTMEM_0570 = DAT_EXTMEM_0569;
          }
        }
        pcVar8 = &DAT_CODE_46ac;
        FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          cVar3 = LATCH7;
          DAT_INTMEM_49 = DAT_EXTMEM_0008;
          bVar5 = DAT_EXTMEM_0008;
          DAT_INTMEM_48 = cVar3;
          thunk_FUN_CODE_179f();
          FUN_CODE_0118();
          BANK3_R0 = DAT_INTMEM_34;
          BANK3_R1 = DAT_INTMEM_35;
          BANK3_R2 = 0xd;
          BANK3_R4 = 0xfa;
          BANK3_R3 = 0;
          FUN_CODE_491d();
          if ((cVar3 == '\0') && (-1 < (2 < bVar5) << 7)) {
            _1_5 = 1;
            DAT_EXTMEM_0559 = '\0';
            DAT_EXTMEM_055a = 0;
          }
          else {
            _1_5 = 0;
            DAT_EXTMEM_0559 = cVar3;
            DAT_EXTMEM_055a = bVar5;
          }
          DAT_EXTMEM_0574 = DAT_EXTMEM_056f;
          _0_2 = 0;
          DAT_INTMEM_4f = 0;
          DAT_EXTMEM_0557 = cVar3;
          DAT_EXTMEM_0558 = bVar5;
          FUN_CODE_0baf();
          _0_2 = 1;
          DAT_EXTMEM_0575 = DAT_EXTMEM_056f;
          DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
          DAT_EXTMEM_056f = DAT_EXTMEM_0574;
          if ((char)((_2_3 & 1 & _2_5 | _2_4) << 7) < '\0') {
            FUN_CODE_0f0e();
          }
          else {
            DAT_INTMEM_4f = 1;
            FUN_CODE_0baf();
          }
          DAT_EXTMEM_056f = DAT_EXTMEM_0575;
        }
        FUN_CODE_076b();
      }
      if (_2_0 != 0) {
        DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
        DAT_EXTMEM_0574 = DAT_EXTMEM_056f;
        DAT_EXTMEM_0554 = 0;
        _0_2 = 0;
        DAT_INTMEM_4f = 0;
        FUN_CODE_0baf();
        _0_2 = 1;
        DAT_EXTMEM_0575 = DAT_EXTMEM_056f;
        DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
        DAT_EXTMEM_0570 = DAT_EXTMEM_056a;
        DAT_EXTMEM_056f = DAT_EXTMEM_0574;
        if ((char)((_2_3 & 1 & _2_5 | _2_4) << 7) < '\0') {
          FUN_CODE_0f0e();
        }
        else {
          DAT_INTMEM_4f = 1;
          FUN_CODE_0baf();
        }
        DAT_EXTMEM_056f = DAT_EXTMEM_0575;
        FUN_CODE_076b();
        DAT_INTMEM_32 = 5;
        DAT_INTMEM_33 = 0xdc;
      }
      bVar5 = P1_4;
      if ((char)((bVar5 & 1 ^ 1) << 7) < '\0') {
        uVar4 = LATCH0_EZ_row_color_LED_bank;
      }
      bVar5 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar5 | 0x80;
      cVar3 = P1_4;
      if (cVar3 != '\0') {
        uVar4 = LATCH0_EZ_row_color_LED_bank;
      }
      if ((char)((_1_2 & 1 | _1_1) << 7) < '\0') {
        bVar5 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar5 | 0x20;
      }
      else {
        bVar5 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar5 & 0xdf;
      }
      cVar3 = P1_5;
      if (cVar3 == '\0') {
        IE = 0x92;
      }
      else {
        IE = 0x82;
        _2_0 = 0;
        DAT_EXTMEM_0562 = 0xff;
        DAT_EXTMEM_0563 = 0xff;
      }
      cVar3 = INT0;
      if (cVar3 != '\x01') {
        DAT_INTMEM_31 = 0;
        DAT_INTMEM_30 = '\0';
        do {
          if ((DAT_INTMEM_30 != '\0') || ((0x8b < DAT_INTMEM_31) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_31);
          *puVar7 = 0xff;
          puVar7[1] = 0xff;
          bVar1 = 0xfe < DAT_INTMEM_31;
          cVar3 = bVar1 << 7;
          DAT_INTMEM_31 = DAT_INTMEM_31 + 1;
          if (bVar1) {
            DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
            cVar3 = '\0';
          }
        } while (-1 < cVar3);
        DAT_EXTMEM_031e = 0xd;
        FUN_CODE_076b();
      }
      cVar3 = INT1;
      if (cVar3 != '\x01') {
        DAT_INTMEM_31 = 0;
        DAT_INTMEM_30 = '\0';
        do {
          if ((DAT_INTMEM_30 != '\0') || ((0x8b < DAT_INTMEM_31) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_0576;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_31);
          *puVar7 = 0;
          puVar7[1] = 0;
          bVar1 = 0xfe < DAT_INTMEM_31;
          cVar3 = bVar1 << 7;
          DAT_INTMEM_31 = DAT_INTMEM_31 + 1;
          if (bVar1) {
            DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
            cVar3 = '\0';
          }
        } while (-1 < cVar3);
        DAT_EXTMEM_031e = 0xd;
        FUN_CODE_076b();
      }
      DAT_INTMEM_2b = 0x2f;
      DAT_INTMEM_2c = 0xff;
      if (_0_6 == 1) {
        cVar3 = LATCH7;
        if ((DAT_EXTMEM_0020 != DAT_EXTMEM_0008) || (DAT_EXTMEM_001f != cVar3)) {
          LATCH7 = 0;
          DAT_EXTMEM_0008 = 0;
        }
        cVar3 = LATCH3_7SEG_802_15;
        cVar2 = LATCH4_802_15;
        if ((DAT_EXTMEM_0018 != cVar2) || (DAT_EXTMEM_0017 != cVar3)) {
          LATCH3_7SEG_802_15 = 0;
          LATCH4_802_15 = 0;
        }
        cVar3 = LATCH5;
        cVar2 = LATCH6_802_15;
        if ((DAT_EXTMEM_001c != cVar2) || (DAT_EXTMEM_001b != cVar3)) {
          LATCH5 = 0;
          LATCH6_802_15 = 0;
        }
        if ((DAT_EXTMEM_0026 != DAT_EXTMEM_0022) || (DAT_EXTMEM_0025 != DAT_EXTMEM_0021)) {
          DAT_EXTMEM_0021 = '\0';
          DAT_EXTMEM_0022 = '\0';
        }
        BANK0_R6 = BANK0_R6 ^ 0xff;
        BANK0_R7 = BANK0_R7 ^ 0xff;
        if ((DAT_EXTMEM_002c != DAT_EXTMEM_0028) || (DAT_EXTMEM_002b != DAT_EXTMEM_0027)) {
          DAT_EXTMEM_0027 = '\0';
          DAT_EXTMEM_0028 = '\0';
        }
        _2_2 = 0;
        if (DAT_EXTMEM_055b + '0' != DAT_EXTMEM_012c) {
          pcVar8 = &DAT_CODE_46ac;
          FUN_CODE_498e(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 != '\0') {
            _2_2 = 0;
            DAT_INTMEM_2f = 0;
            DAT_INTMEM_2e = '\0';
            do {
              if ((DAT_INTMEM_2e != '\0') || ((0xc < DAT_INTMEM_2f) << 7 < '\0')) break;
              puVar7 = &DAT_EXTMEM_012a;
              FUN_CODE_4a09('\f' - DAT_INTMEM_2f);
              *puVar7 = 10;
              bVar1 = 0xfe < DAT_INTMEM_2f;
              cVar3 = bVar1 << 7;
              DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
              if (bVar1) {
                DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                cVar3 = '\0';
              }
            } while (-1 < cVar3);
          }
        }
        _0_6 = 0;
      }
    } while (DAT_EXTMEM_0571 == '\0');
    _2_0 = 0;
    if (DAT_EXTMEM_0571 == '\x01') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0;
        puVar7[1] = 0;
        bVar1 = 0xfe < DAT_INTMEM_2f;
        cVar3 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar3 = '\0';
        }
      } while (-1 < cVar3);
    }
    if (DAT_EXTMEM_0571 == '\x02') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0xff;
        puVar7[1] = 0xff;
        bVar1 = 0xfe < DAT_INTMEM_2f;
        cVar3 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar3 = '\0';
        }
      } while (-1 < cVar3);
    }
    else if (DAT_EXTMEM_0571 == '\x03') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0xaa;
        puVar7[1] = 0xaa;
        puVar7 = &DAT_EXTMEM_0576;
        FUN_CODE_000e();
        *puVar7 = 0x55;
        puVar7[1] = 0x55;
        bVar1 = 0xfd < DAT_INTMEM_2f;
        cVar3 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 2;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar3 = '\0';
        }
      } while (-1 < cVar3);
    }
    else if (DAT_EXTMEM_0571 == '\x04') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_0576;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0x55;
        puVar7[1] = 0x55;
        puVar7 = &DAT_EXTMEM_0576;
        FUN_CODE_000e();
        *puVar7 = 0xaa;
        puVar7[1] = 0xaa;
        bVar1 = 0xfd < DAT_INTMEM_2f;
        cVar3 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 2;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar3 = '\0';
        }
      } while (-1 < cVar3);
    }
    FUN_CODE_076b();
    DAT_EXTMEM_0571 = '\0';
  } while( true );
}



// ==== FUN_CODE_48f0 @ CODE:48f0  (33 bytes)

char FUN_CODE_48f0(byte param_1,byte param_2,byte param_3)

{
  byte bVar1;
  
  bVar1 = param_2;
  if ((param_1 >> 3 & 1) != 0) {
    bVar1 = param_3;
    param_3 = param_2;
  }
  return param_3 * (&DAT_CODE_4915)[param_1 & 7] +
         (char)((ushort)bVar1 * (ushort)(byte)(&DAT_CODE_4915)[param_1 & 7] >> 8);
}



// ==== FUN_CODE_4911 @ CODE:4911  (4 bytes)

void FUN_CODE_4911(byte param_1)

{
  FUN_CODE_48f0(~param_1 + 1);
  return;
}



// ==== FUN_CODE_491d @ CODE:491d  (43 bytes)

byte FUN_CODE_491d(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)CONCAT11(BANK3_R0,BANK3_R1);
  BANK3_R3 = BANK3_R3 + '\x01';
  BANK3_R4 = BANK3_R4 + '\x01';
  while ((BANK3_R4 = BANK3_R4 + -1, BANK3_R4 != '\0' || (BANK3_R3 = BANK3_R3 + -1, BANK3_R3 != '\0')
         )) {
    param_1 = *pbVar1 ^ BANK3_R2;
    if (param_1 == 0) {
      return (char)((ushort)pbVar1 >> 8) - (BANK3_R0 - ((((byte)pbVar1 < BANK3_R1) << 7) >> 7));
    }
    pbVar1 = pbVar1 + 1;
  }
  return param_1;
}



// ==== isr_timer0 @ CODE:4948  (27 bytes)

undefined1 isr_timer0(undefined1 param_1)

{
  FUN_CODE_0641();
  return param_1;
}



// ==== isr_serial @ CODE:4963  (27 bytes)

undefined1 isr_serial(undefined1 param_1)

{
  FUN_CODE_0519();
  return param_1;
}



// ==== FUN_CODE_497e @ CODE:497e  (16 bytes)

void FUN_CODE_497e(char param_1)

{
  char cVar1;
  
  if (param_1 != '\0') {
    cVar1 = '+';
    while( true ) {
      do {
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
      param_1 = param_1 + -1;
      if (param_1 == '\0') break;
      nop();
      cVar1 = '0';
    }
  }
  return;
}



// ==== FUN_CODE_498e @ CODE:498e  (16 bytes)

char FUN_CODE_498e(undefined2 param_1,byte param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  
  bVar3 = (byte)param_1;
  cVar2 = (char)((ushort)param_1 >> 8);
  cVar1 = '\0';
  FUN_CODE_49d7(0);
  return cVar1 + (cVar2 - ((CARRY1(param_2,bVar3) << 7) >> 7));
}



// ==== FUN_CODE_499e @ CODE:499e  (15 bytes)

void FUN_CODE_499e(void)

{
  return;
}



// ==== FUN_CODE_49ad @ CODE:49ad  (14 bytes)

void FUN_CODE_49ad(short param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *pcVar2;
  *pcVar2 = cVar1 + -1;
  if (cVar1 + -1 == -1) {
    FUN_CODE_4a1e();
    *pcVar2 = *pcVar2 + -1;
  }
  return;
}



// ==== FUN_CODE_49bb @ CODE:49bb  (14 bytes)

void FUN_CODE_49bb(char param_1)

{
  param_1 = param_1 + '\x01';
  do {
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return;
}



// ==== FUN_CODE_49c9 @ CODE:49c9  (14 bytes)

void FUN_CODE_49c9(char param_1)

{
  param_1 = param_1 + '\x01';
  do {
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return;
}



// ==== FUN_CODE_49d7 @ CODE:49d7  (14 bytes)

char FUN_CODE_49d7(byte param_1,char param_2,byte param_3)

{
  return param_2 * param_1 + (char)((ushort)param_1 * (ushort)param_3 >> 8);
}



// ==== FUN_CODE_49f2 @ CODE:49f2  (12 bytes)

undefined1 FUN_CODE_49f2(undefined1 *param_1)

{
  return *param_1;
}



// ==== FUN_CODE_49fe @ CODE:49fe  (11 bytes)

char FUN_CODE_49fe(undefined2 param_1,char param_2,byte param_3)

{
  return param_2 + ((char)((ushort)param_1 >> 8) - ((CARRY1(param_3,(byte)param_1) << 7) >> 7));
}



// ==== FUN_CODE_4a09 @ CODE:4a09  (11 bytes)

char FUN_CODE_4a09(undefined2 param_1,char param_2,byte param_3)

{
  return (char)((ushort)param_1 >> 8) + (param_2 - ((CARRY1((byte)param_1,param_3) << 7) >> 7));
}



// ==== FUN_CODE_4a14 @ CODE:4a14  (10 bytes)

void FUN_CODE_4a14(void)

{
  return;
}



// ==== FUN_CODE_4a1e @ CODE:4a1e  (10 bytes)

void FUN_CODE_4a1e(void)

{
  return;
}



// ==== FUN_CODE_4a28 @ CODE:4a28  (9 bytes)

void FUN_CODE_4a28(void)

{
  return;
}



// ==== FUN_CODE_4a31 @ CODE:4a31  (9 bytes)

void FUN_CODE_4a31(undefined1 *param_1,undefined1 *param_2)

{
  *param_2 = *param_1;
  param_2['\x01'] = param_1[1];
  return;
}



// ==== reset_entry @ CODE:4a3a  (9 bytes)

void reset_entry(void)

{
  SP = 0x53;
  FUN_CODE_1eaf();
  return;
}



// ==== FUN_CODE_4a43 @ CODE:4a43  (8 bytes)

void FUN_CODE_4a43(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1 + '\x01';
  *pcVar1 = *pcVar1 + '\x01';
  if (*pcVar1 == '\0') {
    *param_1 = *param_1 + '\x01';
  }
  return;
}



// ==== FUN_CODE_4a4b @ CODE:4a4b  (8 bytes)

void FUN_CODE_4a4b(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1 + '\x01';
  *pcVar1 = *pcVar1 + -1;
  if (*pcVar1 == -1) {
    *param_1 = *param_1 + -1;
  }
  return;
}


