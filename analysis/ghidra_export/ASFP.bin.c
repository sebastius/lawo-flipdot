// Ghidra-decompilatie van ASFP.bin

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



// ==== FUN_CODE_0027 @ CODE:0027  (19 bytes)

void FUN_CODE_0027(void)

{
  undefined1 uVar1;
  
  uVar1 = LATCH7;
  _0_0 = 0;
  return;
}



// ==== is_digit @ CODE:003a  (20 bytes)

char is_digit(void)

{
  char cVar1;
  
  cVar1 = DAT_INTMEM_41 - 0x30;
  if ((DAT_INTMEM_41 < 0x30) || (cVar1 = DAT_INTMEM_41 - 0x3a, -1 < (DAT_INTMEM_41 < 0x3a) << 7)) {
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
  
  DAT_INTMEM_3f = 0;
  DAT_INTMEM_3e = '\0';
  DAT_INTMEM_40 = DAT_INTMEM_3d;
  while( true ) {
    puVar6 = &DAT_EXTMEM_035f;
    FUN_CODE_4ead(DAT_INTMEM_40);
    DAT_INTMEM_41 = *puVar6;
    is_digit();
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
      FUN_CODE_4e5c(10);
      pcVar7 = &DAT_EXTMEM_035f;
      FUN_CODE_4ead(DAT_INTMEM_40);
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



// ==== FUN_CODE_00b2 @ CODE:00b2  (78 bytes)

void FUN_CODE_00b2(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  
  DAT_INTMEM_3b = 0xff;
  for (DAT_INTMEM_3c = 0; DAT_INTMEM_3c < DAT_INTMEM_3a; DAT_INTMEM_3c = DAT_INTMEM_3c + 1) {
    FUN_CODE_4ead(DAT_INTMEM_3c);
    cVar1 = P;
    if (cVar1 != '\0') {
      pbVar3 = &DAT_EXTMEM_031e;
      FUN_CODE_4ead(DAT_INTMEM_3c);
      bVar2 = *pbVar3 ^ 0x80;
      pbVar3 = &DAT_EXTMEM_031e;
      FUN_CODE_4ead(DAT_INTMEM_3c);
      *pbVar3 = bVar2;
    }
    pbVar3 = &DAT_EXTMEM_031e;
    FUN_CODE_4ead(DAT_INTMEM_3c);
    DAT_INTMEM_3b = *pbVar3 ^ DAT_INTMEM_3b;
  }
  pbVar3 = &DAT_EXTMEM_031e;
  FUN_CODE_4ead(DAT_INTMEM_3c);
  *pbVar3 = DAT_INTMEM_3b;
  return;
}



// ==== telegram_dispatch @ CODE:0100  (822 bytes)

byte telegram_dispatch(byte param_1)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  
  DAT_INTMEM_38 = 0;
  BANK1_R4 = DAT_EXTMEM_035f;
  pbVar7 = &DAT_CODE_4c0b;
  FUN_CODE_4e13(DAT_EXTMEM_055b,1);
  bVar3 = *pbVar7;
  cVar6 = (param_1 < BANK1_R7) << 7;
  if (param_1 == BANK1_R7) {
    DAT_INTMEM_41 = DAT_EXTMEM_0360;
    is_digit();
    if (cVar6 < '\0') {
      DAT_INTMEM_38 = 4;
    }
    else if (DAT_EXTMEM_0360 == 'A') {
      DAT_INTMEM_38 = 5;
    }
  }
  else {
    bVar4 = (DAT_EXTMEM_035f < 0x61) << 7;
    if (DAT_EXTMEM_035f == 0x61) {
      DAT_INTMEM_41 = DAT_EXTMEM_0360;
      is_digit();
      if (DAT_EXTMEM_0361 == '\r') {
        bVar5 = 0x80;
      }
      else {
        bVar5 = 0;
      }
      if ((char)(bVar5 & bVar4) < '\0') {
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
      cVar6 = (DAT_EXTMEM_035f < 0x6c) << 7;
      if (DAT_EXTMEM_035f == 0x6c) {
        DAT_INTMEM_41 = DAT_EXTMEM_0360;
        is_digit();
        if (cVar6 < '\0') {
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
        cVar6 = (DAT_EXTMEM_035f < 0x6b) << 7;
        if (DAT_EXTMEM_035f == 0x6b) {
          DAT_INTMEM_41 = DAT_EXTMEM_0360;
          is_digit();
          if (cVar6 < '\0') {
            DAT_INTMEM_38 = 3;
          }
        }
        else {
          cVar6 = (DAT_EXTMEM_035f < 0x77) << 7;
          if (DAT_EXTMEM_035f == 0x77) {
            DAT_INTMEM_41 = DAT_EXTMEM_0360;
            is_digit();
            if (cVar6 < '\0') {
              DAT_INTMEM_38 = 6;
            }
          }
          else {
            cVar6 = (DAT_EXTMEM_035f < 0x65) << 7;
            if (DAT_EXTMEM_035f == 0x65) {
              DAT_INTMEM_41 = DAT_EXTMEM_0360;
              is_digit();
              if (cVar6 < '\0') {
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
    if (DAT_INTMEM_38 == 1) {
      DAT_INTMEM_3d = 1;
      FUN_CODE_004e();
      DAT_INTMEM_39 = 0;
      DAT_EXTMEM_0015 = param_1;
      DAT_EXTMEM_0016 = bVar3;
      do {
        if (3 < DAT_INTMEM_39) {
          return DAT_INTMEM_39 - 4;
        }
        puVar8 = &DAT_EXTMEM_035f;
        FUN_CODE_4ead(DAT_INTMEM_39 + 1);
        uVar2 = *puVar8;
        puVar8 = &DAT_EXTMEM_0011;
        FUN_CODE_4ead(DAT_INTMEM_39);
        *puVar8 = uVar2;
        bVar1 = DAT_INTMEM_39 != 0xff;
        DAT_INTMEM_39 = DAT_INTMEM_39 + 1;
        bVar4 = DAT_INTMEM_39;
      } while (bVar1);
    }
    else if (DAT_INTMEM_38 == 2) {
      DAT_INTMEM_3d = 2;
      FUN_CODE_004e();
      bVar4 = bVar3;
      DAT_EXTMEM_0019 = param_1;
      DAT_EXTMEM_001a = bVar3;
    }
    else if (DAT_INTMEM_38 != 10) {
      if (DAT_INTMEM_38 == 3) {
        DAT_INTMEM_3d = 1;
        FUN_CODE_004e();
        bVar4 = bVar3;
        DAT_EXTMEM_0023 = param_1;
        DAT_EXTMEM_0024 = bVar3;
      }
      else if (DAT_INTMEM_38 == 4) {
        _0_7 = 1;
        DAT_INTMEM_3d = 1;
        FUN_CODE_004e();
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
          FUN_CODE_004e();
          bVar4 = bVar3;
          DAT_EXTMEM_0029 = param_1;
          DAT_EXTMEM_002a = bVar3;
        }
        else if (DAT_INTMEM_38 == 7) {
          _0_5 = 0;
          bVar4 = DAT_EXTMEM_055b + 0x30;
          if (bVar4 == BANK1_R6) {
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
            FUN_CODE_00b2(DAT_EXTMEM_0360);
            DAT_EXTMEM_002f = 4;
            _0_4 = 1;
            bVar4 = 0;
            DAT_EXTMEM_0555 = 0;
            TI = 1;
          }
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
            FUN_CODE_00b2(DAT_EXTMEM_0361);
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
            puVar8 = &DAT_EXTMEM_035f;
            FUN_CODE_4ead(DAT_INTMEM_39);
            uVar2 = *puVar8;
            puVar8 = &DAT_EXTMEM_0009;
            FUN_CODE_4ead(DAT_INTMEM_39 - 1);
            *puVar8 = uVar2;
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
            DAT_EXTMEM_0320 = DAT_CODE_4b16;
            DAT_EXTMEM_0321 = DAT_CODE_4b17;
            DAT_EXTMEM_0322 = DAT_CODE_4b18;
            DAT_EXTMEM_0323 = DAT_CODE_4b19;
            DAT_EXTMEM_0324 = DAT_CODE_4b1a;
            DAT_EXTMEM_0325 = DAT_CODE_4b1b;
            DAT_EXTMEM_0326 = 0xd;
            DAT_INTMEM_3a = 9;
            FUN_CODE_00b2();
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



// ==== serial_rx_tx @ CODE:0436  (306 bytes)

byte serial_rx_tx(byte param_1)

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
          DAT_EXTMEM_0360 = '\0';
          DAT_EXTMEM_0361 = '\0';
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
          FUN_CODE_4ead(DAT_INTMEM_2d);
          *pbVar3 = DAT_INTMEM_43;
          if (((DAT_EXTMEM_035f == 0x61) && (DAT_EXTMEM_0360 == 'A')) &&
             (DAT_EXTMEM_055b + '0' == DAT_EXTMEM_0361)) {
            puVar4 = &DAT_EXTMEM_035f;
            FUN_CODE_4ead(DAT_INTMEM_2d);
            uVar2 = *puVar4;
            puVar4 = &DAT_EXTMEM_0459;
            FUN_CODE_4ead(DAT_INTMEM_2d);
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
          telegram_dispatch();
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
        FUN_CODE_4e03(0x2c);
      }
      puVar4 = &DAT_EXTMEM_031e;
      FUN_CODE_4ead(DAT_EXTMEM_0555);
      SBUF = *puVar4;
      param_1 = DAT_EXTMEM_0555 + 1;
      DAT_EXTMEM_0555 = param_1;
    }
  }
  return param_1;
}



// ==== timer_1ms_dot_pulse @ CODE:0568  (298 bytes)

void timer_1ms_dot_pulse(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  T0 = 1;
  if (DAT_EXTMEM_0563 != '\0' || DAT_EXTMEM_0562 != '\0') {
    FUN_CODE_4e32(0x562);
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
      FUN_CODE_4ead(bVar2,0);
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
      FUN_CODE_4e99(bVar2,0x54);
      FUN_CODE_4ead(bVar2);
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
      FUN_CODE_4e99(bVar2,0x62);
      FUN_CODE_4ead(bVar2);
      LATCH1_ES_FP2800 = bVar3 | *pbVar4;
    }
    _1_4 = '\0';
    T0 = 1;
    T0 = 1;
    T0 = 1;
    T0 = 0;
  }
  if (DAT_INTMEM_33 != '\0' || DAT_INTMEM_32 != '\0') {
    FUN_CODE_4ed0(0x32);
  }
  if (DAT_EXTMEM_055f != '\0' || DAT_EXTMEM_055e != '\0') {
    FUN_CODE_4e32(0x55e);
  }
  if (DAT_INTMEM_2c != '\0' || DAT_INTMEM_2b != '\0') {
    bVar2 = T1;
    T1 = bVar2 ^ 1;
    FUN_CODE_4ed0(0x2b);
  }
  TL0 = 0xc;
  TH0 = 0xfe;
  return;
}



// ==== FUN_CODE_0692 @ CODE:0692  (483 bytes)

void FUN_CODE_0692(void)

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
      FUN_CODE_4e8e(cVar4);
      uVar6 = *puVar9;
      puVar9 = &DAT_EXTMEM_0321;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar9 = uVar6;
      pcVar7 = &DAT_EXTMEM_0321;
      FUN_CODE_4e8e();
      if (*pcVar7 == '\r') {
        DAT_EXTMEM_002f = DAT_INTMEM_2f + '\x04';
      }
      FUN_CODE_4ed0(0x2e);
    }
    DAT_INTMEM_2f = 1;
    DAT_INTMEM_2e = '\0';
    do {
      if ((DAT_INTMEM_2e != '\0') || ((3 < DAT_INTMEM_2f) << 7 < '\0')) break;
      puVar9 = &DAT_EXTMEM_031e;
      FUN_CODE_4e8e('\x03' - DAT_INTMEM_2f);
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
  pcVar7 = &DAT_CODE_4b33;
  FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
  _1_7 = *pcVar7 == '\0';
  if (_0_0 != '\0') {
    _1_7 = !(bool)_1_7;
  }
  FUN_CODE_4e13(DAT_EXTMEM_055b,0x4b2b,0xe);
  FUN_CODE_4eb6(0x10);
  DAT_EXTMEM_056c = 0;
  do {
    if (DAT_EXTMEM_055c - 1U < DAT_EXTMEM_056c) break;
    DAT_EXTMEM_056b = 0;
    do {
      if (DAT_EXTMEM_055d - 1U < DAT_EXTMEM_056b) break;
      pcVar7 = (char *)CONCAT11(BANK2_R0,BANK2_R1);
      FUN_CODE_4e23(DAT_EXTMEM_056b);
      DAT_EXTMEM_08c8 = *pcVar7;
      DAT_EXTMEM_08c9 = pcVar7[1];
      pbVar8 = &DAT_EXTMEM_057e;
      uVar6 = FUN_CODE_4e23(DAT_EXTMEM_056c,DAT_EXTMEM_08c8);
      bVar5 = *pbVar8;
      bVar2 = pbVar8[1];
      pbVar8 = &DAT_EXTMEM_07ae;
      FUN_CODE_4e23(DAT_EXTMEM_056c,uVar6);
      BANK0_R6 = BANK0_R6 ^ bVar5;
      BANK0_R5 = BANK0_R5 ^ bVar2;
      BANK0_R4 = BANK0_R4 & *pbVar8;
      BANK0_R7 = BANK0_R7 & pbVar8[1];
      if ((DAT_EXTMEM_08c9 != '\0' || DAT_EXTMEM_08c8 != '\0') ||
         ((char)((_2_0 & 1 ^ 1) << 7) < '\0')) {
        FUN_CODE_4e23(DAT_EXTMEM_056c);
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
    puVar9 = &DAT_EXTMEM_057e;
    FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
    uVar6 = *puVar9;
    uVar3 = puVar9[1];
    puVar9 = &DAT_EXTMEM_07ae;
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



// ==== FUN_CODE_0875 @ CODE:0875  (432 bytes)

char FUN_CODE_0875(char param_1,byte param_2,byte param_3)

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
  pcVar8 = &DAT_CODE_4c1b;
  FUN_CODE_4e13(DAT_EXTMEM_055b,0x10);
  BANK0_R6 = param_2;
  BANK0_R7 = param_3;
  FUN_CODE_4e83();
  BANK2_R3 = *pcVar8;
  pbVar9 = &DAT_CODE_4d1d;
  FUN_CODE_4e13(DAT_EXTMEM_056d,5);
  bVar5 = *pbVar9;
  DAT_EXTMEM_08c7 = pbVar9[1];
  pcVar8 = (char *)0x8c6;
  DAT_EXTMEM_08c6 = bVar5;
  FUN_CODE_4e77();
  BANK2_R5 = *pcVar8;
  puVar10 = &DAT_CODE_4d1b;
  FUN_CODE_4e13(DAT_EXTMEM_056d,5);
  BANK0_R2 = *puVar10;
  bVar6 = puVar10[1];
  BANK0_R5 = DAT_EXTMEM_056e;
  pcVar8 = &DAT_CODE_4d1f;
  FUN_CODE_4e13(DAT_EXTMEM_056d,5);
  BANK0_R0 = param_3 - *pcVar8;
  sVar2 = (ushort)(BANK2_R5 + 1) * (ushort)bVar5;
  bVar5 = (byte)sVar2;
  BANK3_R0 = bVar6 + bVar5;
  BANK2_R7 = param_1 + ((char)((ushort)sVar2 >> 8) - ((CARRY1(bVar6,bVar5) << 7) >> 7));
  BANK2_R6 = *(char *)CONCAT11(BANK2_R7,BANK3_R0);
  uVar3 = 0;
  bVar5 = 1;
  FUN_CODE_4e40(BANK2_R6 + -1);
  cVar7 = DAT_EXTMEM_055c - (DAT_EXTMEM_0569 + BANK2_R6);
  DAT_EXTMEM_08ca = uVar3;
  DAT_EXTMEM_08cb = bVar5;
  if ((byte)(DAT_EXTMEM_0569 + BANK2_R6) <= DAT_EXTMEM_055c) {
    BANK2_R1 = 0;
    do {
      if (BANK2_R6 - 1U < BANK2_R1) break;
      BANK2_R2 = 0;
      do {
        if (BANK2_R5 - 1U < BANK2_R2) break;
        BANK2_R4 = ~(BANK2_R3 + BANK2_R2) + DAT_EXTMEM_055d;
        if (BANK2_R4 + 1U <= DAT_EXTMEM_055d) {
          BANK0_R4 = DAT_EXTMEM_08ca;
          BANK0_R5 = DAT_EXTMEM_08cb;
          pbVar9 = (byte *)(CONCAT11(BANK2_R7,BANK3_R0) + 1);
          FUN_CODE_4e83(0,BANK2_R2);
          BANK0_R5 = BANK0_R5 & *pbVar9;
          if (param_3 == 0) {
            uVar3 = 0x7f;
            uVar4 = 0xff;
            FUN_CODE_4d96(BANK2_R4);
            pbVar9 = &DAT_EXTMEM_057e;
            FUN_CODE_4e23(DAT_EXTMEM_0569);
            param_3 = pbVar9[1];
            BANK0_R6 = BANK0_R6 & *pbVar9;
            BANK0_R7 = BANK0_R7 & param_3;
            puVar10 = &DAT_EXTMEM_057e;
            FUN_CODE_4e23(DAT_EXTMEM_0569);
            *puVar10 = uVar3;
            puVar10[1] = uVar4;
          }
          else {
            uVar3 = 0x80;
            uVar4 = 0;
            FUN_CODE_4d96(BANK2_R4);
            pbVar9 = &DAT_EXTMEM_057e;
            FUN_CODE_4e23(DAT_EXTMEM_0569);
            param_3 = pbVar9[1];
            BANK0_R6 = BANK0_R6 | *pbVar9;
            BANK0_R7 = BANK0_R7 | param_3;
            puVar10 = &DAT_EXTMEM_057e;
            FUN_CODE_4e23(DAT_EXTMEM_0569);
            *puVar10 = uVar3;
            puVar10[1] = uVar4;
          }
        }
        bVar1 = BANK2_R2 != 0xff;
        BANK2_R2 = BANK2_R2 + 1;
      } while (bVar1);
      DAT_EXTMEM_0569 = DAT_EXTMEM_0569 + '\x01';
      FUN_CODE_4e4e(1);
      bVar1 = BANK2_R1 != 0xff;
      BANK2_R1 = BANK2_R1 + 1;
    } while (bVar1);
    cVar7 = DAT_EXTMEM_0569 + BANK2_R0;
    DAT_EXTMEM_0569 = cVar7;
  }
  return cVar7;
}



// ==== FUN_CODE_0a25 @ CODE:0a25  (82 bytes)

char FUN_CODE_0a25(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  pbVar3 = &DAT_EXTMEM_0030;
  FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
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



// ==== FUN_CODE_0a77 @ CODE:0a77  (95 bytes)

void FUN_CODE_0a77(void)

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
    FUN_CODE_4ead(DAT_EXTMEM_0554);
    *puVar1 = 0xd;
    DAT_EXTMEM_0554 = DAT_EXTMEM_0554 + '\x01';
  }
  return;
}



// ==== FUN_CODE_0ad6 @ CODE:0ad6  (635 bytes)

void FUN_CODE_0ad6(void)

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
  
  BANK3_R2 = DAT_EXTMEM_0569;
  do {
    if (0x8b < BANK3_R2) break;
    puVar7 = &DAT_EXTMEM_057e;
    FUN_CODE_4e23(BANK3_R2);
    *puVar7 = 0;
    puVar7[1] = 0;
    bVar1 = BANK3_R2 != 0xff;
    BANK3_R2 = BANK3_R2 + 1;
  } while (bVar1);
  DAT_EXTMEM_08cd = DAT_EXTMEM_0569;
  _2_3 = 0;
  DAT_INTMEM_31 = DAT_EXTMEM_056f;
  DAT_INTMEM_30 = 0;
  DAT_EXTMEM_08cc = DAT_EXTMEM_056f + 1;
  BANK3_R2 = _2_4 & 1;
  FUN_CODE_0a25();
  if ((char)((_2_6 & 1 & _2_0) << 7) < '\0') {
    if (BANK3_R2 != 0) {
      _2_4 = 1;
    }
    BANK3_R2 = DAT_EXTMEM_08cd;
    do {
      if ((DAT_EXTMEM_055c < BANK3_R2) << 7 < '\0') break;
      puVar7 = &DAT_EXTMEM_0696;
      FUN_CODE_4e23(BANK3_R2);
      uVar4 = puVar7[1];
      uVar6 = 0;
      puVar7 = &DAT_EXTMEM_057e;
      FUN_CODE_4e23(BANK3_R2);
      *puVar7 = uVar6;
      puVar7[1] = uVar4;
      bVar1 = BANK3_R2 != 0xff;
      BANK3_R2 = BANK3_R2 + 1;
    } while (bVar1);
  }
  DAT_EXTMEM_0573 = '\0';
  DAT_INTMEM_31 = DAT_EXTMEM_08cc;
  DAT_INTMEM_30 = '\0';
  do {
    if (DAT_INTMEM_30 != '\0') {
      return;
    }
    if (0xf9 < DAT_INTMEM_31) {
      return;
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(-7 - DAT_INTMEM_31);
    DAT_EXTMEM_056e = *pcVar8;
    if (DAT_EXTMEM_056e == '\x05') {
      FUN_CODE_4ec8(0x30);
      _3_0 = _2_4 & 1;
      FUN_CODE_0a25();
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
      FUN_CODE_4ec8(0x30);
      _2_3 = 1;
      BANK3_R2 = _2_5 & 1;
      FUN_CODE_0a25();
      if ((char)((_2_6 & 1 & _2_0) << 7) < '\0') {
        if (BANK3_R2 != 0) {
          _2_5 = 1;
        }
        BANK3_R2 = DAT_EXTMEM_08cd;
        do {
          if ((DAT_EXTMEM_055c < BANK3_R2) << 7 < '\0') break;
          pbVar9 = &DAT_EXTMEM_0696;
          FUN_CODE_4e23(BANK3_R2);
          uVar4 = 0xff;
          uVar6 = 0;
          BANK0_R6 = BANK0_R6 & *pbVar9;
          BANK0_R7 = BANK0_R7 & pbVar9[1];
          pbVar9 = &DAT_EXTMEM_057e;
          FUN_CODE_4e23(BANK3_R2);
          BANK0_R6 = BANK0_R6 | *pbVar9;
          BANK0_R7 = BANK0_R7 | pbVar9[1];
          puVar7 = &DAT_EXTMEM_057e;
          FUN_CODE_4e23(BANK3_R2);
          *puVar7 = uVar4;
          puVar7[1] = uVar6;
          bVar1 = BANK3_R2 != 0xff;
          BANK3_R2 = BANK3_R2 + 1;
        } while (bVar1);
      }
      DAT_EXTMEM_0569 = DAT_EXTMEM_0570;
    }
    else {
      DAT_EXTMEM_0573 = DAT_EXTMEM_0573 + '\x01';
      FUN_CODE_0a77();
      if ((DAT_INTMEM_30 == '\0') && (DAT_INTMEM_31 + 1 < 0xfa)) {
        puVar7 = &DAT_CODE_4d1d;
        FUN_CODE_4e13(DAT_EXTMEM_056d,5);
        DAT_EXTMEM_08c6 = *puVar7;
        DAT_EXTMEM_08c7 = puVar7[1];
        cVar5 = DAT_INTMEM_30;
        if (DAT_INTMEM_31 == 0xff) {
          cVar5 = DAT_INTMEM_30 + '\x01';
        }
        pbVar9 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_EXTMEM_08c6,cVar5);
        bVar3 = *pbVar9;
        sVar10 = 0x8c6;
        FUN_CODE_4e77();
        cVar5 = bVar3 - *(byte *)(sVar10 + 2);
        if (*(byte *)(sVar10 + 2) <= bVar3) {
          pbVar9 = &DAT_EXTMEM_0030;
          FUN_CODE_4e8e(cVar5,DAT_INTMEM_30);
          bVar3 = *pbVar9;
          sVar10 = 0x8c6;
          FUN_CODE_4e77();
          cVar5 = bVar3 - *(byte *)(sVar10 + 2);
          if (*(byte *)(sVar10 + 2) <= bVar3) {
            pbVar9 = &DAT_EXTMEM_0030;
            FUN_CODE_4e8e(cVar5);
            bVar3 = *pbVar9;
            sVar10 = 0x8c6;
            FUN_CODE_4e77();
            bVar2 = *(char *)(sVar10 + 3) + 1;
            cVar5 = bVar3 - bVar2;
            if (bVar3 < bVar2) {
              pbVar9 = &DAT_EXTMEM_0030;
              FUN_CODE_4e8e(cVar5,DAT_INTMEM_30,DAT_INTMEM_31);
              bVar3 = *pbVar9;
              sVar10 = 0x8c6;
              FUN_CODE_4e77();
              bVar2 = *(char *)(sVar10 + 3) + 1;
              cVar5 = bVar3 - bVar2;
              if ((bVar3 < bVar2) << 7 < '\0') {
                BANK2_R0 = 0;
                FUN_CODE_0875(cVar5);
                DAT_EXTMEM_0573 = DAT_EXTMEM_0573 + -1;
                goto LAB_CODE_0d11;
              }
            }
          }
        }
        BANK2_R0 = BANK3_R1;
        FUN_CODE_0875(cVar5);
      }
    }
LAB_CODE_0d11:
    BANK3_R2 = 0;
    do {
      if (0x8b < BANK3_R2) break;
      puVar7 = &DAT_EXTMEM_057e;
      FUN_CODE_4e23(BANK3_R2);
      uVar4 = *puVar7;
      uVar6 = puVar7[1];
      puVar7 = &DAT_EXTMEM_0696;
      FUN_CODE_4e23(BANK3_R2);
      *puVar7 = uVar4;
      puVar7[1] = uVar6;
      bVar1 = BANK3_R2 != 0xff;
      BANK3_R2 = BANK3_R2 + 1;
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



// ==== FUN_CODE_0d51 @ CODE:0d51  (228 bytes)

char FUN_CODE_0d51(void)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  BANK2_R0 = 0;
  do {
    pbVar4 = &DAT_CODE_4b2f;
    FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
    if ((*pbVar4 < BANK2_R0) << 7 < '\0') break;
    puVar5 = &DAT_EXTMEM_057e;
    FUN_CODE_4e23(BANK2_R0);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = &DAT_EXTMEM_0696;
    FUN_CODE_4e23(BANK2_R0);
    *puVar5 = uVar3;
    puVar5[1] = uVar2;
    bVar1 = BANK2_R0 != 0xff;
    BANK2_R0 = BANK2_R0 + 1;
  } while (bVar1);
  BANK2_R1 = 0;
  pcVar6 = &DAT_CODE_4b2f;
  FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
  BANK2_R0 = *pcVar6;
  while( true ) {
    BANK2_R0 = BANK2_R0 + -1;
    pcVar6 = &DAT_EXTMEM_057e;
    FUN_CODE_4e23(BANK2_R0);
    if ((pcVar6[1] != '\0' || *pcVar6 != '\0') || (BANK2_R0 == '\0')) break;
    BANK2_R1 = BANK2_R1 + 1;
  }
  BANK2_R0 = 0;
  do {
    if ((BANK2_R1 / 2 != 0xff) && (BANK2_R1 / 2 + 2 <= BANK2_R0)) break;
    puVar5 = &DAT_EXTMEM_057e;
    FUN_CODE_4e23(BANK2_R0,BANK2_R1 % 2);
    *puVar5 = 0;
    puVar5[1] = 0;
    bVar1 = BANK2_R0 != 0xff;
    BANK2_R0 = BANK2_R0 + 1;
  } while (bVar1);
  BANK2_R0 = 0;
  do {
    pbVar4 = &DAT_CODE_4b2f;
    FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
    if ((*pbVar4 < BANK2_R0) << 7 < '\0') {
      return *pbVar4 - BANK2_R0;
    }
    puVar5 = &DAT_EXTMEM_0696;
    FUN_CODE_4e23(BANK2_R0);
    uVar3 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = &DAT_EXTMEM_057e;
    FUN_CODE_000e(BANK2_R1 % 2,CARRY1(BANK2_R0,BANK2_R1 / 2),BANK2_R0 + BANK2_R1 / 2);
    *puVar5 = uVar3;
    puVar5[1] = uVar2;
    bVar1 = BANK2_R0 != 0xff;
    BANK2_R0 = BANK2_R0 + 1;
  } while (bVar1);
  return '\0';
}



// ==== FUN_CODE_0e35 @ CODE:0e35  (1140 bytes)

/* WARNING: Removing unreachable block (CODE,0x1147) */
/* WARNING: Removing unreachable block (CODE,0x114d) */

byte FUN_CODE_0e35(byte param_1,byte param_2)

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
    BANK3_R4 = 0;
    BANK3_R3 = DAT_EXTMEM_055c;
    while( true ) {
      BANK3_R3 = BANK3_R3 - 1;
      pcVar9 = &DAT_EXTMEM_057e;
      FUN_CODE_4e23(BANK3_R3);
      if ((pcVar9[1] != '\0' || *pcVar9 != '\0') || (BANK3_R3 == 0)) break;
      BANK3_R4 = BANK3_R4 + 1;
    }
    bVar7 = 0;
    DAT_EXTMEM_08ce = BANK3_R4;
    if (DAT_EXTMEM_0573 != 0) {
      DAT_EXTMEM_08ce = BANK3_R4 / DAT_EXTMEM_0573;
      bVar7 = BANK3_R4 % DAT_EXTMEM_0573;
    }
    if (DAT_EXTMEM_08ce == 0) {
      DAT_EXTMEM_08ce = 1;
    }
    if (6 < DAT_EXTMEM_08ce) {
      DAT_EXTMEM_08ce = 6;
    }
    BANK3_R1 = DAT_EXTMEM_08ce;
    FUN_CODE_0ad6(bVar7,0);
    BANK3_R4 = 0;
    BANK3_R3 = DAT_EXTMEM_055c;
    while( true ) {
      BANK3_R3 = BANK3_R3 - 1;
      pcVar9 = &DAT_EXTMEM_057e;
      FUN_CODE_4e23(BANK3_R3);
      if ((pcVar9[1] != '\0' || *pcVar9 != '\0') || (BANK3_R3 == 0)) break;
      BANK3_R4 = BANK3_R4 + 1;
    }
    BANK3_R3 = 0;
    do {
      if ((BANK3_R4 / 2 != 0xff) && (BANK3_R4 / 2 + 2 <= BANK3_R3)) break;
      puVar11 = &DAT_EXTMEM_057e;
      FUN_CODE_4e23(BANK3_R4 % 2);
      *puVar11 = 0;
      puVar11[1] = 0;
      bVar1 = BANK3_R3 != 0xff;
      BANK3_R3 = BANK3_R3 + 1;
    } while (bVar1);
    BANK3_R3 = DAT_EXTMEM_0570;
    do {
      if ((BANK3_R4 / 2 <= DAT_EXTMEM_055c) && ((DAT_EXTMEM_055c - BANK3_R4 / 2) + 1 <= BANK3_R3))
      break;
      puVar11 = &DAT_EXTMEM_0696;
      FUN_CODE_4e23(BANK3_R3,BANK3_R4 % 2);
      uVar3 = *puVar11;
      uVar6 = puVar11[1];
      puVar11 = &DAT_EXTMEM_057e;
      FUN_CODE_000e(BANK3_R4 % 2,CARRY1(BANK3_R3,BANK3_R4 / 2),BANK3_R3 + BANK3_R4 / 2);
      *puVar11 = uVar3;
      puVar11[1] = uVar6;
      bVar1 = BANK3_R3 != 0xff;
      BANK3_R3 = BANK3_R3 + 1;
    } while (bVar1);
    _3_1 = 1;
    DAT_INTMEM_2f = DAT_EXTMEM_0570;
    DAT_INTMEM_2e = 0;
    do {
      bVar7 = DAT_EXTMEM_055c;
      if ((DAT_INTMEM_2e != 0) ||
         (bVar7 = DAT_EXTMEM_055c - DAT_INTMEM_2f, (DAT_EXTMEM_055c < DAT_INTMEM_2f) << 7 < '\0'))
      break;
      pbVar10 = &DAT_EXTMEM_057e;
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
        pbVar10 = &DAT_EXTMEM_057e;
        bVar4 = DAT_INTMEM_2e;
        bVar5 = DAT_INTMEM_2f;
        FUN_CODE_000e(DAT_EXTMEM_055c - DAT_INTMEM_2f);
        bVar2 = 1;
        bVar7 = *pbVar10;
        BANK0_R7 = pbVar10[1];
        BANK0_R6 = bVar7;
        FUN_CODE_4e40(1);
        pbVar10 = &DAT_EXTMEM_057e;
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
    BANK3_R1 = 1;
    bVar7 = FUN_CODE_0ad6();
    if (_2_4 == '\x01') {
      BANK3_R4 = 0;
      BANK3_R3 = DAT_EXTMEM_055c;
      while( true ) {
        BANK3_R3 = BANK3_R3 - 1;
        puVar11 = &DAT_EXTMEM_057e;
        FUN_CODE_4e23(BANK3_R3);
        if ((puVar11[1] != '\0') || (BANK3_R3 == 0)) break;
        BANK3_R4 = BANK3_R4 + 1;
      }
      BANK3_R3 = DAT_EXTMEM_0570;
      do {
        if ((DAT_EXTMEM_055c - 1 < BANK3_R3) << 7 < '\0') break;
        pbVar10 = &DAT_EXTMEM_057e;
        FUN_CODE_4e23(BANK3_R3);
        uVar3 = 0xff;
        uVar6 = 0;
        BANK0_R6 = BANK0_R6 & *pbVar10;
        BANK0_R7 = BANK0_R7 & pbVar10[1];
        puVar11 = &DAT_EXTMEM_057e;
        FUN_CODE_4e23(BANK3_R3);
        *puVar11 = uVar3;
        puVar11[1] = uVar6;
        bVar1 = BANK3_R3 != 0xff;
        BANK3_R3 = BANK3_R3 + 1;
      } while (bVar1);
      BANK3_R3 = DAT_EXTMEM_0570;
      do {
        if ((BANK3_R4 / 2 <= DAT_EXTMEM_055c) &&
           (bVar4 = (DAT_EXTMEM_055c - BANK3_R4 / 2) + 1, bVar7 = BANK3_R3 - bVar4,
           bVar4 <= BANK3_R3)) break;
        pbVar10 = &DAT_EXTMEM_057e;
        FUN_CODE_000e(BANK3_R4 % 2,CARRY1(BANK3_R3,BANK3_R4 / 2),BANK3_R3 + BANK3_R4 / 2);
        bVar7 = *pbVar10;
        bVar4 = pbVar10[1];
        puVar11 = &DAT_EXTMEM_0696;
        FUN_CODE_4e23(BANK3_R3);
        param_1 = puVar11[1];
        uVar3 = 0;
        BANK0_R5 = BANK0_R5 | bVar7;
        BANK0_R2 = BANK0_R2 | bVar4;
        BANK0_R7 = BANK3_R3 + BANK3_R4 / 2;
        puVar11 = &DAT_EXTMEM_057e;
        FUN_CODE_000e(BANK3_R4 % 2,CARRY1(BANK3_R3,BANK3_R4 / 2));
        *puVar11 = uVar3;
        puVar11[1] = param_1;
        bVar1 = BANK3_R3 != 0xff;
        bVar7 = BANK3_R3 + 1;
        BANK3_R3 = bVar7;
      } while (bVar1);
    }
    if (_2_5 == '\x01') {
      _3_1 = 1;
      DAT_INTMEM_2f = DAT_EXTMEM_0570;
      DAT_INTMEM_2e = 0;
      do {
        if ((DAT_INTMEM_2e != 0) || ((DAT_EXTMEM_055c < DAT_INTMEM_2f) << 7 < '\0')) break;
        pbVar10 = &DAT_EXTMEM_057e;
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
      BANK3_R4 = 0;
      BANK3_R3 = DAT_EXTMEM_055c - 1;
      pbVar10 = &DAT_EXTMEM_057e;
      FUN_CODE_4e23(BANK3_R3);
      BANK0_R6 = BANK0_R6 & *pbVar10;
      BANK0_R7 = BANK0_R7 & pbVar10[1];
      BANK3_R3 = DAT_EXTMEM_0570;
      do {
        if ((DAT_EXTMEM_055c - 1 < BANK3_R3) << 7 < '\0') break;
        puVar11 = &DAT_EXTMEM_057e;
        FUN_CODE_4e23(BANK3_R3);
        uVar3 = puVar11[1];
        uVar6 = 0;
        puVar11 = &DAT_EXTMEM_057e;
        FUN_CODE_4e23(BANK3_R3);
        *puVar11 = uVar6;
        puVar11[1] = uVar3;
        bVar1 = BANK3_R3 != 0xff;
        BANK3_R3 = BANK3_R3 + 1;
      } while (bVar1);
      if ((char)((_3_1 & 1 ^ 1) << 7) < '\0') {
        BANK3_R3 = DAT_EXTMEM_0570;
        do {
          if ((BANK3_R4 / 2 <= DAT_EXTMEM_055c) &&
             (bVar7 = (DAT_EXTMEM_055c - BANK3_R4 / 2) + 1, bVar7 <= BANK3_R3)) {
            return BANK3_R3 - bVar7;
          }
          FUN_CODE_4e23(BANK3_R3,BANK3_R4 % 2);
          BANK0_R6 = CARRY1(BANK3_R3,BANK3_R4 / 2);
          BANK0_R7 = BANK3_R3 + BANK3_R4 / 2;
          BANK0_R2 = 0;
          BANK0_R3 = 0xff;
          pbVar10 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(BANK3_R4 % 2);
          BANK0_R3 = BANK0_R3 | *pbVar10;
          BANK0_R2 = BANK0_R2 | pbVar10[1];
          pbVar10 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(BANK3_R4 % 2,CARRY1(BANK3_R3,BANK3_R4 / 2),BANK3_R3 + BANK3_R4 / 2);
          *pbVar10 = param_2;
          pbVar10[1] = param_1;
          bVar1 = BANK3_R3 != 0xff;
          bVar7 = BANK3_R3 + 1;
          BANK3_R3 = bVar7;
        } while (bVar1);
      }
      else {
        BANK3_R3 = DAT_EXTMEM_0570;
        do {
          if ((BANK3_R4 / 2 <= DAT_EXTMEM_055c) &&
             (bVar7 = (DAT_EXTMEM_055c - BANK3_R4 / 2) + 1, bVar7 <= BANK3_R3)) {
            return BANK3_R3 - bVar7;
          }
          pbVar10 = &DAT_EXTMEM_0696;
          FUN_CODE_4e23(BANK3_R3,BANK3_R4 % 2);
          bVar4 = 1;
          bVar7 = *pbVar10;
          BANK0_R7 = pbVar10[1];
          BANK0_R6 = bVar7;
          FUN_CODE_4e40(1);
          uVar3 = 0xfe;
          uVar6 = 0;
          BANK0_R4 = BANK0_R4 & bVar4;
          BANK0_R5 = BANK0_R5 & bVar7;
          pbVar10 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(BANK3_R4 % 2,CARRY1(BANK3_R3,BANK3_R4 / 2),BANK3_R3 + BANK3_R4 / 2);
          BANK0_R4 = BANK0_R4 | *pbVar10;
          BANK0_R5 = BANK0_R5 | pbVar10[1];
          puVar11 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(BANK3_R4 % 2,CARRY1(BANK3_R3,BANK3_R4 / 2),BANK3_R3 + BANK3_R4 / 2);
          *puVar11 = uVar3;
          puVar11[1] = uVar6;
          bVar1 = BANK3_R3 != 0xff;
          bVar7 = BANK3_R3 + 1;
          BANK3_R3 = bVar7;
        } while (bVar1);
      }
    }
  }
  return bVar7;
}



// ==== FUN_CODE_12a9 @ CODE:12a9  (75 bytes)

char FUN_CODE_12a9(void)

{
  for (BANK2_R0 = 1; (BANK2_R0 < 4 && (*(char *)(BANK2_R0 + 0x24) == '0')); BANK2_R0 = BANK2_R0 + 1)
  {
  }
  BANK2_R1 = 1;
  for (; BANK2_R0 < 4; BANK2_R0 = BANK2_R0 + 1) {
    BANK0_R6 = *(undefined1 *)(BANK2_R0 + 0x24);
    *(undefined1 *)(BANK2_R1 + 0x24) = BANK0_R6;
    BANK2_R1 = BANK2_R1 + 1;
  }
  for (; BANK2_R1 < 4; BANK2_R1 = BANK2_R1 + 1) {
    *(undefined1 *)(BANK2_R1 + 0x24) = 0x20;
  }
  return BANK2_R1 - 4;
}



// ==== FUN_CODE_12f4 @ CODE:12f4  (556 bytes)

char FUN_CODE_12f4(void)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  
  BANK2_R1 = 0;
  BANK2_R0 = 0;
  do {
    if (0xf9 < BANK2_R0) {
      return BANK2_R0 + 6;
    }
    pcVar3 = &DAT_EXTMEM_0224;
    FUN_CODE_4ead(BANK2_R0);
    if (*pcVar3 == '\n') {
      BANK2_R1 = BANK2_R0 + 1;
    }
    else {
      pcVar3 = &DAT_EXTMEM_0224;
      FUN_CODE_4ead(BANK2_R0);
      if (*pcVar3 == '\r') {
        BANK2_R0 = 0xff;
      }
      else {
        pcVar3 = &DAT_EXTMEM_0224;
        FUN_CODE_4ead(BANK2_R0);
        if (*pcVar3 != ' ') {
          pcVar3 = &DAT_EXTMEM_0224;
          FUN_CODE_4ead(BANK2_R0);
          if (*pcVar3 != '-') {
            pcVar3 = &DAT_EXTMEM_0224;
            FUN_CODE_4ead(BANK2_R0);
            if (*pcVar3 != '.') {
              pcVar3 = &DAT_EXTMEM_0224;
              FUN_CODE_4ead(BANK2_R0);
              if (*pcVar3 != '/') {
                pcVar3 = &DAT_EXTMEM_0224;
                FUN_CODE_4ead(BANK2_R0);
                if (*pcVar3 != '(') {
                  if (BANK2_R0 == BANK2_R1) {
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == ']') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == 'B') {
                        pcVar3 = &DAT_EXTMEM_0226;
                        FUN_CODE_4ead(BANK2_R0);
                        if (*pcVar3 == 'E') {
                          pcVar3 = &DAT_EXTMEM_0227;
                          FUN_CODE_4ead(BANK2_R0);
                          if (*pcVar3 == 'R') {
                            puVar4 = &DAT_EXTMEM_0224;
                            FUN_CODE_4ead(BANK2_R0);
                            *puVar4 = 0x7d;
                          }
                        }
                      }
                    }
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == ']') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == 'B') {
                        pcVar3 = &DAT_EXTMEM_0226;
                        FUN_CODE_4ead(BANK2_R0);
                        if (*pcVar3 == '.') {
                          puVar4 = &DAT_EXTMEM_0224;
                          FUN_CODE_4ead(BANK2_R0);
                          *puVar4 = 0x7d;
                        }
                      }
                    }
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == ']') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == '.') {
                        puVar4 = &DAT_EXTMEM_0224;
                        FUN_CODE_4ead(BANK2_R0);
                        *puVar4 = 0x7d;
                      }
                    }
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == 'V') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == 'I') {
                        pcVar3 = &DAT_EXTMEM_0226;
                        FUN_CODE_4ead(BANK2_R0);
                        if (*pcVar3 == 'A') {
                          puVar4 = &DAT_EXTMEM_0224;
                          FUN_CODE_4ead(BANK2_R0);
                          *puVar4 = 0x76;
                        }
                      }
                    }
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == 'H') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == 'B') {
                        pcVar3 = &DAT_EXTMEM_0226;
                        FUN_CODE_4ead(BANK2_R0);
                        if (*pcVar3 == 'F') {
                          BANK2_R0 = BANK2_R0 + 2;
                        }
                      }
                    }
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == 'Z') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == 'O') {
                        pcVar3 = &DAT_EXTMEM_0226;
                        FUN_CODE_4ead(BANK2_R0);
                        if (*pcVar3 == 'B') {
                          BANK2_R0 = BANK2_R0 + 2;
                        }
                      }
                    }
                    pcVar3 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (*pcVar3 == 'K') {
                      pcVar3 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0 + 1);
                      if (*pcVar3 == 'V') {
                        pcVar3 = &DAT_EXTMEM_0226;
                        FUN_CODE_4ead(BANK2_R0);
                        if (*pcVar3 == 'A') {
                          pcVar3 = &DAT_EXTMEM_0227;
                          FUN_CODE_4ead(BANK2_R0);
                          if (*pcVar3 == 'G') {
                            BANK2_R0 = BANK2_R0 + 3;
                          }
                        }
                      }
                    }
                  }
                  else {
                    pbVar5 = &DAT_EXTMEM_0224;
                    FUN_CODE_4ead(BANK2_R0);
                    if (0x40 < *pbVar5) {
                      pbVar5 = &DAT_EXTMEM_0224;
                      FUN_CODE_4ead(BANK2_R0);
                      if ((*pbVar5 < 0x5e) << 7 < '\0') {
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4ead(BANK2_R0);
                        cVar2 = *pcVar3 + ' ';
                        pcVar3 = &DAT_EXTMEM_0224;
                        FUN_CODE_4ead(BANK2_R0);
                        *pcVar3 = cVar2;
                      }
                    }
                  }
                  goto LAB_CODE_1514;
                }
              }
            }
          }
        }
        BANK2_R1 = BANK2_R0 + 1;
      }
    }
LAB_CODE_1514:
    bVar1 = BANK2_R0 == 0xff;
    BANK2_R0 = BANK2_R0 + 1;
    if (bVar1) {
      return '\0';
    }
  } while( true );
}



// ==== FUN_CODE_1520 @ CODE:1520  (304 bytes)

char FUN_CODE_1520(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  FUN_CODE_0a25();
  puVar7 = &DAT_CODE_4d1d;
  FUN_CODE_4e13(DAT_EXTMEM_056d,5);
  DAT_EXTMEM_08c6 = *puVar7;
  DAT_EXTMEM_08c7 = puVar7[1];
  DAT_EXTMEM_08cf = 0;
  pcVar8 = &DAT_CODE_4b34;
  FUN_CODE_4e13(DAT_EXTMEM_055b,DAT_EXTMEM_08c6,0xe);
  if (*pcVar8 == '\0') {
    pcVar8 = &DAT_CODE_4b31;
    FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
    DAT_EXTMEM_08d0 = *pcVar8 + 1;
  }
  else {
    DAT_EXTMEM_08d0 = ~DAT_EXTMEM_056a + DAT_EXTMEM_055c + 2;
  }
  while( true ) {
    cVar3 = DAT_INTMEM_30;
    if (DAT_INTMEM_31 == -1) {
      cVar3 = DAT_INTMEM_30 + '\x01';
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(cVar3);
    if (*pcVar8 == '\x03') break;
    cVar3 = DAT_INTMEM_30;
    if (DAT_INTMEM_31 == -1) {
      cVar3 = DAT_INTMEM_30 + '\x01';
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(cVar3);
    if (*pcVar8 == '\x04') break;
    cVar3 = DAT_INTMEM_30;
    if (DAT_INTMEM_31 == -1) {
      cVar3 = DAT_INTMEM_30 + '\x01';
    }
    pcVar8 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(cVar3);
    if (*pcVar8 == '\r') break;
    bVar2 = 0x30;
    FUN_CODE_4ec8();
    pcVar8 = &DAT_CODE_4d1b;
    FUN_CODE_4e13(DAT_EXTMEM_056d,5);
    cVar4 = *pcVar8;
    bVar5 = pcVar8[1];
    pcVar8 = &DAT_EXTMEM_0030;
    uVar6 = FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
    cVar3 = *pcVar8;
    pcVar8 = &DAT_CODE_4d1f;
    FUN_CODE_4e13(DAT_EXTMEM_056d,uVar6,5);
    cVar3 = cVar3 - *pcVar8;
    pcVar8 = (char *)0x8c6;
    FUN_CODE_4e77();
    sVar1 = (ushort)(*pcVar8 + 1) * (ushort)bVar2;
    bVar2 = (byte)sVar1;
    BANK2_R1 = bVar5 + bVar2;
    BANK2_R0 = cVar4 + ((char)((ushort)sVar1 >> 8) - ((CARRY1(bVar5,bVar2) << 7) >> 7));
    DAT_EXTMEM_08cf = DAT_EXTMEM_08cf + *(char *)CONCAT11(BANK2_R0,BANK2_R1) + 1;
    BANK0_R0 = cVar3;
  }
  cVar3 = DAT_INTMEM_30;
  if (DAT_INTMEM_31 == -1) {
    cVar3 = DAT_INTMEM_30 + '\x01';
  }
  pcVar8 = &DAT_EXTMEM_0030;
  FUN_CODE_4e8e(cVar3);
  if (*pcVar8 == '\r') {
    DAT_INTMEM_2f = 1;
    DAT_INTMEM_2e = 0;
  }
  _2_7 = DAT_EXTMEM_08d0 < DAT_EXTMEM_08cf;
  return DAT_EXTMEM_08d0 - DAT_EXTMEM_08cf;
}



// ==== FUN_CODE_1650 @ CODE:1650  (302 bytes)

void FUN_CODE_1650(void)

{
  bool bVar1;
  char *pcVar2;
  undefined1 *puVar3;
  
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = 0;
  DAT_EXTMEM_0559 = '\0';
  DAT_EXTMEM_055a = 0;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  DAT_INTMEM_31 = BANK2_R2;
  DAT_INTMEM_30 = '\0';
  while (DAT_INTMEM_2f == '\0' && DAT_INTMEM_2e == '\0') {
    DAT_EXTMEM_0557 = DAT_INTMEM_30;
    DAT_EXTMEM_0558 = DAT_INTMEM_31;
    DAT_EXTMEM_0559 = DAT_INTMEM_30;
    DAT_EXTMEM_055a = DAT_INTMEM_31;
    pcVar2 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
    _2_3 = *pcVar2 != 'B';
    if ((bool)_2_3) {
      FUN_CODE_1520();
      if (_2_7 != '\0') {
        puVar3 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar3 = 0x48;
      }
      bVar1 = 0xfd < DAT_INTMEM_31;
      DAT_INTMEM_31 = DAT_INTMEM_31 + 2;
      if (bVar1) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
      pcVar2 = &DAT_EXTMEM_0030;
      DAT_EXTMEM_0557 = DAT_INTMEM_30;
      DAT_EXTMEM_0558 = DAT_INTMEM_31;
      FUN_CODE_4e8e(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
      if (*pcVar2 == 'H') {
        puVar3 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar3 = 0x44;
      }
      FUN_CODE_1520();
      if (_2_7 != '\0') {
        puVar3 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar3 = 0x44;
        puVar3 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_EXTMEM_0559,DAT_EXTMEM_055a);
        *puVar3 = 0x48;
      }
      if (0xfd < DAT_INTMEM_31) {
        DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
      }
    }
    else {
      FUN_CODE_1520();
      if (_2_7 != '\0') {
        puVar3 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
        *puVar3 = 0x47;
        DAT_INTMEM_30 = DAT_EXTMEM_0557;
        DAT_INTMEM_31 = DAT_EXTMEM_0558;
        FUN_CODE_1520();
        if (_2_7 != '\0') {
          puVar3 = &DAT_EXTMEM_0030;
          FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
          *puVar3 = 0x46;
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



// ==== thunk_FUN_CODE_1780 @ CODE:177e  (2 bytes)

void thunk_FUN_CODE_1780(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  DAT_INTMEM_34 = 1;
  DAT_INTMEM_35 = 0x32;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  do {
    if ((DAT_INTMEM_2e != '\0') || ((0xf1 < DAT_INTMEM_2f) << 7 < '\0')) break;
    puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4e8e(-0xf - DAT_INTMEM_2f);
    uVar3 = *puVar7;
    puVar7 = &DAT_EXTMEM_0224;
    FUN_CODE_4e8e();
    *puVar7 = uVar3;
    puVar7 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e();
    *puVar7 = 0xd;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar4 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar4 = '\0';
    }
  } while (-1 < cVar4);
  bVar2 = P1_4;
  if ((char)((bVar2 & 1 ^ 1) << 7) < '\0') {
    FUN_CODE_12f4();
  }
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = -7;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  while( true ) {
    pcVar8 = &DAT_EXTMEM_0224;
    FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
    if (*pcVar8 == '\r') break;
    pcVar8 = &DAT_EXTMEM_0224;
    FUN_CODE_4e8e();
    if (*pcVar8 != ' ') {
      DAT_EXTMEM_0557 = DAT_INTMEM_2e;
      DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    }
    FUN_CODE_4ec8(0x2e);
  }
  cVar4 = DAT_EXTMEM_0557;
  if (DAT_EXTMEM_0558 == -1) {
    cVar4 = DAT_EXTMEM_0557 + '\x01';
  }
  puVar7 = &DAT_EXTMEM_0224;
  FUN_CODE_4e8e(cVar4);
  *puVar7 = 0xd;
  puVar7 = &DAT_EXTMEM_0226;
  FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
  *puVar7 = 0xd;
  DAT_EXTMEM_0557 = 0;
  DAT_EXTMEM_0558 = 0;
  DAT_INTMEM_31 = '\0';
  DAT_INTMEM_30 = '\0';
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = 0;
  DAT_EXTMEM_0559 = 0;
  DAT_EXTMEM_055a = 0;
  DAT_INTMEM_34 = 2;
  DAT_INTMEM_35 = 0x24;
  while( true ) {
    pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    cVar5 = DAT_INTMEM_30;
    cVar6 = DAT_INTMEM_31;
    FUN_CODE_4e8e();
    cVar4 = '\0';
    if (((*pcVar8 == '\r') || (cVar4 = -6, cVar5 != '\0')) ||
       (cVar4 = -6 - (cVar6 + 1U), 0xfa < cVar6 + 1U)) break;
    puVar7 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(cVar4,DAT_INTMEM_2e,DAT_INTMEM_2f);
    *puVar7 = 0x49;
    DAT_EXTMEM_0557 = DAT_INTMEM_2e;
    DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    FUN_CODE_4ec8(0x2e);
    _2_3 = '\x01';
    while( true ) {
      pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
      if (*pcVar8 == '\n') break;
      puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4e8e();
      uVar3 = *puVar7;
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar7 = uVar3;
      FUN_CODE_4ec8(0x2e);
      FUN_CODE_4ec8(0x30);
    }
    FUN_CODE_4ec8(0x30);
    pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar8 == '\n') {
      _2_3 = '\0';
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
      *puVar7 = 0x42;
      FUN_CODE_4ec8(0x30);
    }
    if (_2_3 != '\0') {
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar7 = 3;
      FUN_CODE_4ec8(0x2e);
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar7 = 0x45;
      FUN_CODE_4ec8(0x2e);
      while( true ) {
        pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
        if (*pcVar8 == '\n') break;
        puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4e8e();
        uVar3 = *puVar7;
        puVar7 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
        *puVar7 = uVar3;
        FUN_CODE_4ec8(0x2e);
        FUN_CODE_4ec8(0x30);
      }
      FUN_CODE_4ec8(0x30);
    }
    FUN_CODE_4ec8(0x30);
    pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar8 != '\n') {
      pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4e8e();
      if (*pcVar8 != '\r') {
        if (_2_1 == '\0') {
          puVar7 = &DAT_EXTMEM_0030;
          FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar7 = 4;
        }
        else {
          puVar7 = &DAT_EXTMEM_0030;
          FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar7 = 0xd;
        }
        FUN_CODE_4ec8(0x2e);
      }
    }
  }
  puVar7 = &DAT_EXTMEM_0030;
  FUN_CODE_4e8e(cVar4,DAT_INTMEM_2e,DAT_INTMEM_2f);
  *puVar7 = 0xd;
  BANK2_R2 = 0;
  FUN_CODE_1650();
  return;
}



// ==== FUN_CODE_1780 @ CODE:1780  (561 bytes)

void FUN_CODE_1780(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  DAT_INTMEM_34 = 1;
  DAT_INTMEM_35 = 0x32;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  do {
    if ((DAT_INTMEM_2e != '\0') || ((0xf1 < DAT_INTMEM_2f) << 7 < '\0')) break;
    puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4e8e(-0xf - DAT_INTMEM_2f);
    uVar3 = *puVar7;
    puVar7 = &DAT_EXTMEM_0224;
    FUN_CODE_4e8e();
    *puVar7 = uVar3;
    puVar7 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e();
    *puVar7 = 0xd;
    bVar1 = 0xfe < DAT_INTMEM_2f;
    cVar4 = bVar1 << 7;
    DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
    if (bVar1) {
      DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
      cVar4 = '\0';
    }
  } while (-1 < cVar4);
  bVar2 = P1_4;
  if ((char)((bVar2 & 1 ^ 1) << 7) < '\0') {
    FUN_CODE_12f4();
  }
  DAT_EXTMEM_0557 = '\0';
  DAT_EXTMEM_0558 = -7;
  DAT_INTMEM_2f = '\0';
  DAT_INTMEM_2e = '\0';
  while( true ) {
    pcVar8 = &DAT_EXTMEM_0224;
    FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
    if (*pcVar8 == '\r') break;
    pcVar8 = &DAT_EXTMEM_0224;
    FUN_CODE_4e8e();
    if (*pcVar8 != ' ') {
      DAT_EXTMEM_0557 = DAT_INTMEM_2e;
      DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    }
    FUN_CODE_4ec8(0x2e);
  }
  cVar4 = DAT_EXTMEM_0557;
  if (DAT_EXTMEM_0558 == -1) {
    cVar4 = DAT_EXTMEM_0557 + '\x01';
  }
  puVar7 = &DAT_EXTMEM_0224;
  FUN_CODE_4e8e(cVar4);
  *puVar7 = 0xd;
  puVar7 = &DAT_EXTMEM_0226;
  FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
  *puVar7 = 0xd;
  DAT_EXTMEM_0557 = 0;
  DAT_EXTMEM_0558 = 0;
  DAT_INTMEM_31 = '\0';
  DAT_INTMEM_30 = '\0';
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = 0;
  DAT_EXTMEM_0559 = 0;
  DAT_EXTMEM_055a = 0;
  DAT_INTMEM_34 = 2;
  DAT_INTMEM_35 = 0x24;
  while( true ) {
    pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    cVar5 = DAT_INTMEM_30;
    cVar6 = DAT_INTMEM_31;
    FUN_CODE_4e8e();
    cVar4 = '\0';
    if (((*pcVar8 == '\r') || (cVar4 = -6, cVar5 != '\0')) ||
       (cVar4 = -6 - (cVar6 + 1U), 0xfa < cVar6 + 1U)) break;
    puVar7 = &DAT_EXTMEM_0030;
    FUN_CODE_4e8e(cVar4,DAT_INTMEM_2e,DAT_INTMEM_2f);
    *puVar7 = 0x49;
    DAT_EXTMEM_0557 = DAT_INTMEM_2e;
    DAT_EXTMEM_0558 = DAT_INTMEM_2f;
    FUN_CODE_4ec8(0x2e);
    _2_3 = '\x01';
    while( true ) {
      pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
      if (*pcVar8 == '\n') break;
      puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4e8e();
      uVar3 = *puVar7;
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar7 = uVar3;
      FUN_CODE_4ec8(0x2e);
      FUN_CODE_4ec8(0x30);
    }
    FUN_CODE_4ec8(0x30);
    pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar8 == '\n') {
      _2_3 = '\0';
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_EXTMEM_0557,DAT_EXTMEM_0558);
      *puVar7 = 0x42;
      FUN_CODE_4ec8(0x30);
    }
    if (_2_3 != '\0') {
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar7 = 3;
      FUN_CODE_4ec8(0x2e);
      puVar7 = &DAT_EXTMEM_0030;
      FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
      *puVar7 = 0x45;
      FUN_CODE_4ec8(0x2e);
      while( true ) {
        pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
        if (*pcVar8 == '\n') break;
        puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
        FUN_CODE_4e8e();
        uVar3 = *puVar7;
        puVar7 = &DAT_EXTMEM_0030;
        FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
        *puVar7 = uVar3;
        FUN_CODE_4ec8(0x2e);
        FUN_CODE_4ec8(0x30);
      }
      FUN_CODE_4ec8(0x30);
    }
    FUN_CODE_4ec8(0x30);
    pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
    FUN_CODE_4e8e(DAT_INTMEM_30,DAT_INTMEM_31);
    if (*pcVar8 != '\n') {
      pcVar8 = (char *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
      FUN_CODE_4e8e();
      if (*pcVar8 != '\r') {
        if (_2_1 == '\0') {
          puVar7 = &DAT_EXTMEM_0030;
          FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar7 = 4;
        }
        else {
          puVar7 = &DAT_EXTMEM_0030;
          FUN_CODE_4e8e(DAT_INTMEM_2e,DAT_INTMEM_2f);
          *puVar7 = 0xd;
        }
        FUN_CODE_4ec8(0x2e);
      }
    }
  }
  puVar7 = &DAT_EXTMEM_0030;
  FUN_CODE_4e8e(cVar4,DAT_INTMEM_2e,DAT_INTMEM_2f);
  *puVar7 = 0xd;
  BANK2_R2 = 0;
  FUN_CODE_1650();
  return;
}



// ==== hw_init @ CODE:210c  (528 bytes)

void hw_init(char param_1)

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
  IP = 0;
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
    puVar8 = &DAT_EXTMEM_057e;
    FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8 = &DAT_EXTMEM_0696;
    FUN_CODE_000e();
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8 = &DAT_EXTMEM_07ae;
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
  puVar8 = &DAT_CODE_4b2f;
  uVar6 = FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
  BANK0_R4 = *puVar8;
  pcVar9 = &DAT_CODE_4b31;
  FUN_CODE_4e13(DAT_EXTMEM_055b,uVar6,0xe);
  DAT_EXTMEM_055c = param_1 + *pcVar9;
  puVar8 = &DAT_CODE_4b30;
  FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
  DAT_EXTMEM_055d = *puVar8;
  FUN_CODE_4e13(DAT_EXTMEM_055b,0x4b2d,0xe);
  FUN_CODE_4eb6(0x36);
  puVar8 = &DAT_CODE_4b38;
  FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
  DAT_INTMEM_24 = *puVar8;
  DAT_INTMEM_2f = 0;
  DAT_INTMEM_2e = '\0';
  while( true ) {
    if (DAT_INTMEM_2e != '\0') {
      return;
    }
    if ((0x40 < DAT_INTMEM_2f) << 7 < '\0') break;
    puVar8 = &DAT_EXTMEM_031e;
    FUN_CODE_4e8e('@' - DAT_INTMEM_2f);
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



// ==== main @ CODE:231c  (2336 bytes)

/* WARNING: Removing unreachable block (CODE,0x2fc8) */

void main(char param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  IE = 0;
  hw_init();
  IE = 0x82;
  IE = 0x92;
  FUN_CODE_0692();
  IE = 0x92;
  do {
    do {
      if ((char)(((_0_4 & 1 ^ 1) & _0_1) << 7) < '\0') {
        DAT_EXTMEM_0562 = 0xff;
        DAT_EXTMEM_0563 = 0xff;
        _0_1 = 0;
        if (_0_6 == 0) {
          DAT_INTMEM_44 = '\x03';
          DAT_INTMEM_45 = 0x5f;
          DAT_INTMEM_46 = 0xd;
          DAT_INTMEM_48 = 0xf9;
          DAT_INTMEM_47 = 0;
          FUN_CODE_4da2();
          if ((param_1 != '\0') || (DAT_EXTMEM_0558 = param_2, 0xf9 < param_2)) {
            DAT_EXTMEM_0458 = 0xd;
            DAT_EXTMEM_0558 = 0xf9;
          }
          DAT_EXTMEM_0557 = '\0';
        }
        else {
          _2_0 = 0;
        }
        bVar2 = DAT_EXTMEM_055f;
        cVar6 = DAT_EXTMEM_055e;
        if (_0_7 != '\0') {
          if (((char)((_2_2 & 1 ^ 1) << 7) < '\0') &&
             ((((DAT_EXTMEM_055e != '\0' || (1 < DAT_EXTMEM_055f)) &&
               ((char)((_2_0 & 1 ^ 1) << 7) < '\0')) && (DAT_EXTMEM_055b == -1)))) {
            _2_2 = 1;
          }
          _0_7 = '\0';
          param_1 = cVar6;
          param_2 = bVar2;
          if (DAT_EXTMEM_055f == 0 && DAT_EXTMEM_055e == '\0') {
            DAT_EXTMEM_055e = DAT_EXTMEM_0560;
            DAT_EXTMEM_055f = DAT_EXTMEM_0561;
          }
        }
        DAT_EXTMEM_002d = 0;
      }
      if (_1_1 != 0) {
        DAT_EXTMEM_0556 = '\0';
      }
      if ((DAT_EXTMEM_0556 != '\0') && ((char)((_0_6 & 1 ^ 1) << 7) < '\0')) {
        DAT_INTMEM_2f = 0;
        DAT_INTMEM_2e = '\0';
        do {
          param_1 = DAT_INTMEM_2e;
          param_2 = DAT_INTMEM_2f;
          if ((DAT_INTMEM_2e != '\0') || ((0xf8 < DAT_INTMEM_2f) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_0459;
          FUN_CODE_4e8e(-8 - DAT_INTMEM_2f);
          uVar4 = *puVar7;
          puVar7 = &DAT_EXTMEM_012a;
          FUN_CODE_4e8e();
          *puVar7 = uVar4;
          pcVar8 = &DAT_EXTMEM_0459;
          FUN_CODE_4e8e();
          if (*pcVar8 == '\r') {
            DAT_INTMEM_2f = 0xfb;
            DAT_INTMEM_2e = '\0';
          }
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar6 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar6 = '\0';
          }
        } while (-1 < cVar6);
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
        DAT_INTMEM_34 = '\x01';
        DAT_INTMEM_35 = 0x2e;
        DAT_INTMEM_2f = 0;
        DAT_INTMEM_2e = '\0';
        do {
          if ((DAT_INTMEM_2e != '\0') || ((2 < DAT_INTMEM_2f) << 7 < '\0')) break;
          puVar7 = (undefined1 *)CONCAT11(DAT_INTMEM_34,DAT_INTMEM_35);
          FUN_CODE_4e8e('\x02' - DAT_INTMEM_2f);
          uVar4 = *puVar7;
          puVar7 = &DAT_EXTMEM_0224;
          FUN_CODE_4e8e();
          *puVar7 = uVar4;
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar6 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar6 = '\0';
          }
        } while (-1 < cVar6);
        DAT_INTMEM_2f = 1;
        DAT_INTMEM_2e = '\0';
        do {
          if ((DAT_INTMEM_2e != '\0') || ((3 < DAT_INTMEM_2f) << 7 < '\0')) break;
          uVar4 = 0;
          if (DAT_INTMEM_2f == 0) {
            uVar4 = 0xff;
          }
          puVar7 = &DAT_EXTMEM_0224;
          FUN_CODE_4e8e('\x03' - DAT_INTMEM_2f,uVar4);
          *(undefined1 *)(DAT_INTMEM_2f + 0x24) = *puVar7;
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar6 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar6 = '\0';
          }
        } while (-1 < cVar6);
        FUN_CODE_12a9();
        DAT_INTMEM_2f = 0;
        DAT_INTMEM_2e = '\0';
        do {
          param_1 = DAT_INTMEM_2e;
          if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
          *puVar7 = 0;
          puVar7[1] = 0;
          bVar1 = 0xfe < DAT_INTMEM_2f;
          cVar6 = bVar1 << 7;
          DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
          if (bVar1) {
            DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
            cVar6 = '\0';
          }
        } while (-1 < cVar6);
        DAT_EXTMEM_056a = '\0';
        DAT_EXTMEM_0569 = '\0';
        DAT_EXTMEM_0570 = '\0';
        pcVar8 = &DAT_CODE_4b2f;
        FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_4b34;
          FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\x01') {
            pcVar8 = &DAT_CODE_4b37;
            FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
            if (*pcVar8 == '\0') {
              DAT_INTMEM_29 = 0xd;
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                param_1 = DAT_INTMEM_2e;
                if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
                puVar5 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
                puVar7 = &DAT_EXTMEM_0030;
                FUN_CODE_4e8e();
                *puVar7 = *puVar5;
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar6 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar6 = '\0';
                }
              } while (-1 < cVar6);
              DAT_EXTMEM_0572 = 4;
              if (((((DAT_INTMEM_28 == ' ') || (DAT_INTMEM_28 == '\r')) &&
                   ((DAT_EXTMEM_0572 = 3, DAT_INTMEM_27 == ' ' || (DAT_INTMEM_27 == '\r')))) &&
                  ((DAT_EXTMEM_0572 = 2, DAT_INTMEM_26 == ' ' || (DAT_INTMEM_26 == '\r')))) &&
                 ((DAT_EXTMEM_0572 = 1, DAT_INTMEM_25 == ' ' || (DAT_INTMEM_25 == '\r')))) {
                DAT_EXTMEM_0572 = 0;
              }
              pcVar8 = &DAT_CODE_4b1d;
              FUN_CODE_4e13(DAT_EXTMEM_0572,3);
              DAT_EXTMEM_056a = *pcVar8;
              puVar7 = &DAT_CODE_4b1c;
              FUN_CODE_4e13(DAT_EXTMEM_0572,3);
              DAT_EXTMEM_0569 = *puVar7;
              _0_2 = 0;
              puVar7 = &DAT_CODE_4b1e;
              FUN_CODE_4e13(DAT_EXTMEM_0572,3);
              BANK3_R1 = *puVar7;
              FUN_CODE_0ad6();
              DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
              DAT_EXTMEM_0570 = DAT_EXTMEM_056a;
            }
          }
        }
        pcVar8 = &DAT_CODE_4b2f;
        FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_4b34;
          FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\x01') {
            pcVar8 = &DAT_CODE_4b37;
            FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
            if (*pcVar8 == '\x01') {
              DAT_INTMEM_29 = 0xd;
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
                puVar5 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
                puVar7 = &DAT_EXTMEM_0030;
                FUN_CODE_4e8e();
                *puVar7 = *puVar5;
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar6 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar6 = '\0';
                }
              } while (-1 < cVar6);
              DAT_EXTMEM_0569 = 0;
              _0_2 = 0;
              puVar7 = &DAT_CODE_4b35;
              FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
              BANK3_R1 = *puVar7;
              FUN_CODE_0ad6();
              DAT_EXTMEM_056a = '\0';
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                param_1 = DAT_INTMEM_2e;
                if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
                pcVar8 = &DAT_EXTMEM_057e;
                FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
                if (pcVar8[1] != '\0' || *pcVar8 != '\0') {
                  DAT_EXTMEM_056a = DAT_INTMEM_2f + 1;
                }
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar6 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar6 = '\0';
                }
              } while (-1 < cVar6);
              DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
              DAT_EXTMEM_0570 = DAT_EXTMEM_056a;
            }
          }
        }
        pcVar8 = &DAT_CODE_4b2f;
        FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_4b34;
          FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\0') {
            pcVar8 = &DAT_CODE_4b36;
            FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
            if (*pcVar8 == '\0') {
              DAT_INTMEM_29 = 0xd;
              DAT_INTMEM_2f = 0;
              DAT_INTMEM_2e = '\0';
              do {
                param_1 = DAT_INTMEM_2e;
                if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
                puVar5 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
                puVar7 = &DAT_EXTMEM_0030;
                FUN_CODE_4e8e();
                *puVar7 = *puVar5;
                bVar1 = 0xfe < DAT_INTMEM_2f;
                cVar6 = bVar1 << 7;
                DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
                if (bVar1) {
                  DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                  cVar6 = '\0';
                }
              } while (-1 < cVar6);
              DAT_EXTMEM_0569 = 0;
              _0_2 = 0;
              puVar7 = &DAT_CODE_4b35;
              FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
              BANK3_R1 = *puVar7;
              FUN_CODE_0ad6();
              pcVar8 = &DAT_CODE_4b2f;
              FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
              DAT_EXTMEM_0569 = *pcVar8;
              DAT_EXTMEM_056a = DAT_EXTMEM_0569;
              DAT_EXTMEM_0570 = DAT_EXTMEM_0569;
            }
          }
        }
        pcVar8 = &DAT_CODE_4b2f;
        FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
        if (*pcVar8 != '\0') {
          pcVar8 = &DAT_CODE_4b36;
          FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
          if (*pcVar8 == '\x01') {
            DAT_INTMEM_29 = 0xd;
            DAT_INTMEM_2f = 0;
            DAT_INTMEM_2e = '\0';
            do {
              param_1 = DAT_INTMEM_2e;
              if ((DAT_INTMEM_2e != '\0') || ((6 < DAT_INTMEM_2f) << 7 < '\0')) break;
              puVar5 = (undefined1 *)(DAT_INTMEM_2f + 0x24);
              puVar7 = &DAT_EXTMEM_0030;
              FUN_CODE_4e8e();
              *puVar7 = *puVar5;
              bVar1 = 0xfe < DAT_INTMEM_2f;
              cVar6 = bVar1 << 7;
              DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
              if (bVar1) {
                DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                cVar6 = '\0';
              }
            } while (-1 < cVar6);
            DAT_EXTMEM_0569 = 0;
            _0_2 = 0;
            puVar7 = &DAT_CODE_4b35;
            FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
            BANK3_R1 = *puVar7;
            FUN_CODE_0ad6();
            FUN_CODE_0d51();
            pcVar8 = &DAT_CODE_4b2f;
            FUN_CODE_4e13(DAT_EXTMEM_055b,0xe);
            DAT_EXTMEM_0569 = *pcVar8;
            DAT_EXTMEM_056a = DAT_EXTMEM_0569;
            DAT_EXTMEM_0570 = DAT_EXTMEM_0569;
          }
        }
        param_2 = 0xe;
        pcVar8 = &DAT_CODE_4b31;
        FUN_CODE_4e13(DAT_EXTMEM_055b);
        if (*pcVar8 != '\0') {
          BANK2_R3 = LATCH7;
          BANK2_R4 = DAT_EXTMEM_0008;
          thunk_FUN_CODE_1780();
          FUN_CODE_0027();
          DAT_INTMEM_44 = DAT_INTMEM_34;
          DAT_INTMEM_45 = DAT_INTMEM_35;
          DAT_INTMEM_46 = 0xd;
          DAT_INTMEM_48 = 0xfa;
          DAT_INTMEM_47 = 0;
          param_1 = DAT_INTMEM_34;
          param_2 = DAT_INTMEM_35;
          FUN_CODE_4da2();
          if ((param_1 == '\0') && (-1 < (2 < param_2) << 7)) {
            _1_5 = 1;
            DAT_EXTMEM_0559 = '\0';
            DAT_EXTMEM_055a = 0;
          }
          else {
            _1_5 = 0;
            DAT_EXTMEM_0559 = param_1;
            DAT_EXTMEM_055a = param_2;
          }
          DAT_EXTMEM_0574 = DAT_EXTMEM_056f;
          _0_2 = 0;
          BANK3_R1 = 0;
          DAT_EXTMEM_0557 = param_1;
          DAT_EXTMEM_0558 = param_2;
          FUN_CODE_0ad6();
          _0_2 = 1;
          DAT_EXTMEM_0575 = DAT_EXTMEM_056f;
          DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
          DAT_EXTMEM_056f = DAT_EXTMEM_0574;
          if ((char)((_2_3 & 1 & _2_5 | _2_4) << 7) < '\0') {
            FUN_CODE_0e35();
          }
          else {
            BANK3_R1 = 1;
            FUN_CODE_0ad6();
          }
          DAT_EXTMEM_056f = DAT_EXTMEM_0575;
        }
        FUN_CODE_0692();
      }
      if (_2_0 != 0) {
        DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
        DAT_EXTMEM_0574 = DAT_EXTMEM_056f;
        DAT_EXTMEM_0554 = 0;
        _0_2 = 0;
        BANK3_R1 = 0;
        FUN_CODE_0ad6();
        _0_2 = 1;
        DAT_EXTMEM_0575 = DAT_EXTMEM_056f;
        DAT_EXTMEM_0569 = DAT_EXTMEM_056a;
        DAT_EXTMEM_0570 = DAT_EXTMEM_056a;
        DAT_EXTMEM_056f = DAT_EXTMEM_0574;
        if ((char)((_2_3 & 1 & _2_5 | _2_4) << 7) < '\0') {
          FUN_CODE_0e35();
        }
        else {
          BANK3_R1 = 1;
          FUN_CODE_0ad6();
        }
        DAT_EXTMEM_056f = DAT_EXTMEM_0575;
        FUN_CODE_0692();
        DAT_INTMEM_32 = 5;
        DAT_INTMEM_33 = 0xdc;
      }
      bVar2 = P1_4;
      if ((char)((bVar2 & 1 ^ 1) << 7) < '\0') {
        uVar4 = LATCH0_EZ_row_color_LED_bank;
      }
      bVar2 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar2 | 0x80;
      cVar6 = P1_4;
      if (cVar6 != '\0') {
        uVar4 = LATCH0_EZ_row_color_LED_bank;
      }
      if ((char)((_1_2 & 1 | _1_1) << 7) < '\0') {
        bVar2 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar2 | 0x20;
      }
      else {
        bVar2 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar2 & 0xdf;
      }
      cVar6 = P1_5;
      if (cVar6 == '\0') {
        IE = 0x92;
      }
      else {
        IE = 0x82;
        _2_0 = 0;
        DAT_EXTMEM_0562 = 0xff;
        DAT_EXTMEM_0563 = 0xff;
      }
      cVar6 = INT0;
      if (cVar6 != '\x01') {
        DAT_INTMEM_31 = 0;
        DAT_INTMEM_30 = '\0';
        do {
          param_1 = DAT_INTMEM_30;
          param_2 = DAT_INTMEM_31;
          if ((DAT_INTMEM_30 != '\0') || ((0x8b < DAT_INTMEM_31) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_31);
          *puVar7 = 0xff;
          puVar7[1] = 0xff;
          bVar1 = 0xfe < DAT_INTMEM_31;
          cVar6 = bVar1 << 7;
          DAT_INTMEM_31 = DAT_INTMEM_31 + 1;
          if (bVar1) {
            DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
            cVar6 = '\0';
          }
        } while (-1 < cVar6);
        DAT_EXTMEM_031e = 0xd;
        FUN_CODE_0692();
      }
      cVar6 = INT1;
      if (cVar6 != '\x01') {
        DAT_INTMEM_31 = 0;
        DAT_INTMEM_30 = '\0';
        do {
          param_1 = DAT_INTMEM_30;
          param_2 = DAT_INTMEM_31;
          if ((DAT_INTMEM_30 != '\0') || ((0x8b < DAT_INTMEM_31) << 7 < '\0')) break;
          puVar7 = &DAT_EXTMEM_057e;
          FUN_CODE_000e(-0x75 - DAT_INTMEM_31);
          *puVar7 = 0;
          puVar7[1] = 0;
          bVar1 = 0xfe < DAT_INTMEM_31;
          cVar6 = bVar1 << 7;
          DAT_INTMEM_31 = DAT_INTMEM_31 + 1;
          if (bVar1) {
            DAT_INTMEM_30 = DAT_INTMEM_30 + '\x01';
            cVar6 = '\0';
          }
        } while (-1 < cVar6);
        DAT_EXTMEM_031e = 0xd;
        FUN_CODE_0692();
      }
      DAT_INTMEM_2b = 0x2f;
      DAT_INTMEM_2c = 0xff;
      if (_0_6 == 1) {
        cVar6 = LATCH7;
        if ((DAT_EXTMEM_0020 != DAT_EXTMEM_0008) || (DAT_EXTMEM_001f != cVar6)) {
          LATCH7 = 0;
          DAT_EXTMEM_0008 = '\0';
        }
        cVar6 = LATCH3_7SEG_802_15;
        cVar3 = LATCH4_802_15;
        if ((DAT_EXTMEM_0018 != cVar3) || (DAT_EXTMEM_0017 != cVar6)) {
          LATCH3_7SEG_802_15 = 0;
          LATCH4_802_15 = 0;
        }
        cVar6 = LATCH5;
        cVar3 = LATCH6_802_15;
        if ((DAT_EXTMEM_001c != cVar3) || (DAT_EXTMEM_001b != cVar6)) {
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
          DAT_EXTMEM_0028 = 0;
        }
        _2_2 = 1;
        param_1 = DAT_EXTMEM_012c;
        param_2 = DAT_EXTMEM_002c;
        if (DAT_EXTMEM_055b + '0' != DAT_EXTMEM_012c) {
          param_2 = 0xe;
          pcVar8 = &DAT_CODE_4b31;
          FUN_CODE_4e13(DAT_EXTMEM_055b);
          if (*pcVar8 != '\0') {
            _2_2 = 0;
            DAT_INTMEM_2f = 0;
            DAT_INTMEM_2e = '\0';
            do {
              param_1 = DAT_INTMEM_2e;
              param_2 = DAT_INTMEM_2f;
              if ((DAT_INTMEM_2e != '\0') || ((0xc < DAT_INTMEM_2f) << 7 < '\0')) break;
              puVar7 = &DAT_EXTMEM_012a;
              FUN_CODE_4e8e('\f' - DAT_INTMEM_2f);
              *puVar7 = 10;
              bVar1 = 0xfe < DAT_INTMEM_2f;
              cVar6 = bVar1 << 7;
              DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
              if (bVar1) {
                DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
                cVar6 = '\0';
              }
            } while (-1 < cVar6);
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
        param_1 = DAT_INTMEM_2e;
        param_2 = DAT_INTMEM_2f;
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_057e;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0;
        puVar7[1] = 0;
        bVar1 = 0xfe < DAT_INTMEM_2f;
        cVar6 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar6 = '\0';
        }
      } while (-1 < cVar6);
    }
    if (DAT_EXTMEM_0571 == '\x02') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        param_1 = DAT_INTMEM_2e;
        param_2 = DAT_INTMEM_2f;
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_057e;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0xff;
        puVar7[1] = 0xff;
        bVar1 = 0xfe < DAT_INTMEM_2f;
        cVar6 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 1;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar6 = '\0';
        }
      } while (-1 < cVar6);
    }
    else if (DAT_EXTMEM_0571 == '\x03') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        param_1 = DAT_INTMEM_2e;
        param_2 = DAT_INTMEM_2f;
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_057e;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0xaa;
        puVar7[1] = 0xaa;
        param_2 = param_2 + 1;
        if (param_2 == 0) {
          param_1 = param_1 + '\x01';
        }
        puVar7 = &DAT_EXTMEM_057e;
        FUN_CODE_000e();
        *puVar7 = 0x55;
        puVar7[1] = 0x55;
        bVar1 = 0xfd < DAT_INTMEM_2f;
        cVar6 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 2;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar6 = '\0';
        }
      } while (-1 < cVar6);
    }
    else if (DAT_EXTMEM_0571 == '\x04') {
      DAT_INTMEM_2f = 0;
      DAT_INTMEM_2e = '\0';
      do {
        param_1 = DAT_INTMEM_2e;
        param_2 = DAT_INTMEM_2f;
        if ((DAT_INTMEM_2e != '\0') || ((0x8b < DAT_INTMEM_2f) << 7 < '\0')) break;
        puVar7 = &DAT_EXTMEM_057e;
        FUN_CODE_000e(-0x75 - DAT_INTMEM_2f);
        *puVar7 = 0x55;
        puVar7[1] = 0x55;
        param_2 = param_2 + 1;
        if (param_2 == 0) {
          param_1 = param_1 + '\x01';
        }
        puVar7 = &DAT_EXTMEM_057e;
        FUN_CODE_000e();
        *puVar7 = 0xaa;
        puVar7[1] = 0xaa;
        bVar1 = 0xfd < DAT_INTMEM_2f;
        cVar6 = bVar1 << 7;
        DAT_INTMEM_2f = DAT_INTMEM_2f + 2;
        if (bVar1) {
          DAT_INTMEM_2e = DAT_INTMEM_2e + '\x01';
          cVar6 = '\0';
        }
      } while (-1 < cVar6);
    }
    FUN_CODE_0692();
    DAT_EXTMEM_0571 = '\0';
  } while( true );
}



// ==== FUN_CODE_4d75 @ CODE:4d75  (33 bytes)

char FUN_CODE_4d75(byte param_1,byte param_2,byte param_3)

{
  byte bVar1;
  
  bVar1 = param_2;
  if ((param_1 >> 3 & 1) != 0) {
    bVar1 = param_3;
    param_3 = param_2;
  }
  return param_3 * (&DAT_CODE_4d9a)[param_1 & 7] +
         (char)((ushort)bVar1 * (ushort)(byte)(&DAT_CODE_4d9a)[param_1 & 7] >> 8);
}



// ==== FUN_CODE_4d96 @ CODE:4d96  (4 bytes)

void FUN_CODE_4d96(byte param_1)

{
  FUN_CODE_4d75(~param_1 + 1);
  return;
}



// ==== FUN_CODE_4da2 @ CODE:4da2  (43 bytes)

byte FUN_CODE_4da2(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)CONCAT11(DAT_INTMEM_44,DAT_INTMEM_45);
  DAT_INTMEM_47 = DAT_INTMEM_47 + '\x01';
  DAT_INTMEM_48 = DAT_INTMEM_48 + '\x01';
  while ((DAT_INTMEM_48 = DAT_INTMEM_48 + -1, DAT_INTMEM_48 != '\0' ||
         (DAT_INTMEM_47 = DAT_INTMEM_47 + -1, DAT_INTMEM_47 != '\0'))) {
    param_1 = *pbVar1 ^ DAT_INTMEM_46;
    if (param_1 == 0) {
      return (char)((ushort)pbVar1 >> 8) -
             (DAT_INTMEM_44 - ((((byte)pbVar1 < DAT_INTMEM_45) << 7) >> 7));
    }
    pbVar1 = pbVar1 + 1;
  }
  return param_1;
}



// ==== isr_timer0 @ CODE:4dcd  (27 bytes)

undefined1 isr_timer0(undefined1 param_1)

{
  timer_1ms_dot_pulse();
  return param_1;
}



// ==== isr_serial @ CODE:4de8  (27 bytes)

undefined1 isr_serial(undefined1 param_1)

{
  serial_rx_tx();
  return param_1;
}



// ==== FUN_CODE_4e03 @ CODE:4e03  (16 bytes)

void FUN_CODE_4e03(char param_1)

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



// ==== FUN_CODE_4e13 @ CODE:4e13  (16 bytes)

char FUN_CODE_4e13(undefined2 param_1,byte param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  
  bVar3 = (byte)param_1;
  cVar2 = (char)((ushort)param_1 >> 8);
  cVar1 = '\0';
  FUN_CODE_4e5c(0);
  return cVar1 + (cVar2 - ((CARRY1(param_2,bVar3) << 7) >> 7));
}



// ==== FUN_CODE_4e23 @ CODE:4e23  (15 bytes)

void FUN_CODE_4e23(void)

{
  return;
}



// ==== FUN_CODE_4e32 @ CODE:4e32  (14 bytes)

void FUN_CODE_4e32(short param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *pcVar2;
  *pcVar2 = cVar1 + -1;
  if (cVar1 + -1 == -1) {
    FUN_CODE_4ea3();
    *pcVar2 = *pcVar2 + -1;
  }
  return;
}



// ==== FUN_CODE_4e40 @ CODE:4e40  (14 bytes)

void FUN_CODE_4e40(char param_1)

{
  param_1 = param_1 + '\x01';
  do {
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return;
}



// ==== FUN_CODE_4e4e @ CODE:4e4e  (14 bytes)

void FUN_CODE_4e4e(char param_1)

{
  param_1 = param_1 + '\x01';
  do {
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return;
}



// ==== FUN_CODE_4e5c @ CODE:4e5c  (14 bytes)

char FUN_CODE_4e5c(byte param_1,char param_2,byte param_3)

{
  return param_2 * param_1 + (char)((ushort)param_1 * (ushort)param_3 >> 8);
}



// ==== FUN_CODE_4e77 @ CODE:4e77  (12 bytes)

undefined1 FUN_CODE_4e77(undefined1 *param_1)

{
  return *param_1;
}



// ==== FUN_CODE_4e83 @ CODE:4e83  (11 bytes)

char FUN_CODE_4e83(undefined2 param_1,char param_2,byte param_3)

{
  return param_2 + ((char)((ushort)param_1 >> 8) - ((CARRY1(param_3,(byte)param_1) << 7) >> 7));
}



// ==== FUN_CODE_4e8e @ CODE:4e8e  (11 bytes)

char FUN_CODE_4e8e(undefined2 param_1,char param_2,byte param_3)

{
  return (char)((ushort)param_1 >> 8) + (param_2 - ((CARRY1((byte)param_1,param_3) << 7) >> 7));
}



// ==== FUN_CODE_4e99 @ CODE:4e99  (10 bytes)

void FUN_CODE_4e99(void)

{
  return;
}



// ==== FUN_CODE_4ea3 @ CODE:4ea3  (10 bytes)

void FUN_CODE_4ea3(void)

{
  return;
}



// ==== FUN_CODE_4ead @ CODE:4ead  (9 bytes)

void FUN_CODE_4ead(void)

{
  return;
}



// ==== FUN_CODE_4eb6 @ CODE:4eb6  (9 bytes)

void FUN_CODE_4eb6(undefined1 *param_1,undefined1 *param_2)

{
  *param_2 = *param_1;
  param_2['\x01'] = param_1[1];
  return;
}



// ==== reset_entry @ CODE:4ebf  (9 bytes)

void reset_entry(void)

{
  SP = 0x4a;
  main();
  return;
}



// ==== FUN_CODE_4ec8 @ CODE:4ec8  (8 bytes)

void FUN_CODE_4ec8(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1 + '\x01';
  *pcVar1 = *pcVar1 + '\x01';
  if (*pcVar1 == '\0') {
    *param_1 = *param_1 + '\x01';
  }
  return;
}



// ==== FUN_CODE_4ed0 @ CODE:4ed0  (8 bytes)

void FUN_CODE_4ed0(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1 + '\x01';
  *pcVar1 = *pcVar1 + -1;
  if (*pcVar1 == -1) {
    *param_1 = *param_1 + -1;
  }
  return;
}


