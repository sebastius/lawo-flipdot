// Ghidra-decompilatie van AZR-12C.BIN

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

char FUN_CODE_000e(byte param_1)

{
  char cVar1;
  
  cVar1 = param_1 - 0x30;
  if (0x2f < param_1) {
    cVar1 = param_1 - 0x3a;
  }
  return cVar1;
}



// ==== VEC_SERIAL @ CODE:0023  (3 bytes)

void VEC_SERIAL(void)

{
  isr_serial();
  return;
}



// ==== main @ CODE:0026  (3376 bytes)

void main(byte param_1,byte param_2)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined2 uStack_1;
  
  FUN_CODE_0d57();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_6e9c();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_2d2c();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_24ce();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_1fa7();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_27d6();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  if (_1_2 == '\0') {
    DAT_EXTMEM_0f8f = 0;
    DAT_EXTMEM_0f90 = 0;
    do {
      bVar4 = DAT_EXTMEM_0f90;
      *(undefined1 *)CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x51)
           = (&DAT_CODE_3a08)[DAT_EXTMEM_0f90];
      *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) = (&DAT_CODE_39ec)[bVar4];
      DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
      if (DAT_EXTMEM_0f90 == 0) {
        DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
      }
      bVar4 = DAT_EXTMEM_0f8f;
      if (DAT_EXTMEM_0f8f == 0) {
        bVar4 = DAT_EXTMEM_0f90 ^ 0x70;
      }
    } while (bVar4 != 0);
    DAT_EXTMEM_0f8f = 0;
    DAT_EXTMEM_0f90 = 0;
    do {
      bVar4 = DAT_EXTMEM_0f90;
      *(undefined1 *)CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x66)
           = (&DAT_CODE_39b4)[DAT_EXTMEM_0f90];
      *(undefined1 *)CONCAT11('\t' - (((0x7b < bVar4) << 7) >> 7),bVar4 + 0x84) =
           (&DAT_CODE_39d0)[bVar4];
      DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
      if (DAT_EXTMEM_0f90 == 0) {
        DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
      }
      bVar4 = DAT_EXTMEM_0f8f;
      if (DAT_EXTMEM_0f8f == 0) {
        bVar4 = DAT_EXTMEM_0f90 ^ 0x1c;
      }
    } while (bVar4 != 0);
    _5_1 = 1;
    FUN_CODE_2488();
    _5_1 = 0;
    FUN_CODE_2488();
    DAT_EXTMEM_0f8f = 0;
    DAT_EXTMEM_0f90 = 0;
    do {
      bVar4 = DAT_EXTMEM_0f90;
      *(undefined1 *)CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x51)
           = (&DAT_CODE_3a78)[DAT_EXTMEM_0f90];
      *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) = (&DAT_CODE_3a5c)[bVar4];
      DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
      if (DAT_EXTMEM_0f90 == 0) {
        DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
      }
      bVar4 = DAT_EXTMEM_0f8f;
      if (DAT_EXTMEM_0f8f == 0) {
        bVar4 = DAT_EXTMEM_0f90 ^ 0x70;
      }
    } while (bVar4 != 0);
    DAT_EXTMEM_0f8f = 0;
    DAT_EXTMEM_0f90 = 0;
    do {
      param_2 = DAT_EXTMEM_0f90;
      *(undefined1 *)CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x66)
           = (&DAT_CODE_3a24)[DAT_EXTMEM_0f90];
      param_1 = (&DAT_CODE_3a40)[param_2];
      *(byte *)CONCAT11('\t' - (((0x7b < param_2) << 7) >> 7),param_2 + 0x84) = param_1;
      DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
      if (DAT_EXTMEM_0f90 == 0) {
        DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
      }
      bVar4 = DAT_EXTMEM_0f8f;
      if (DAT_EXTMEM_0f8f == 0) {
        bVar4 = DAT_EXTMEM_0f90 ^ 0x1c;
      }
    } while (bVar4 != 0);
    _5_1 = 1;
    FUN_CODE_2488();
    _5_1 = 0;
    FUN_CODE_2488();
  }
  else {
    _5_1 = 1;
    FUN_CODE_2488();
    _5_1 = 0;
    FUN_CODE_2488();
  }
  do {
    DAT_EXTMEM_09d3 = 0x4e;
    DAT_EXTMEM_09d4 = 0x20;
    PCON = 0x81;
    FUN_CODE_6e9c();
    cVar5 = INT1;
    if ((cVar5 == '\x01') && (cVar5 = INT0, cVar5 == '\0')) {
      if (_1_2 == '\0') {
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          bVar4 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x51) =
               (&DAT_CODE_3a08)[DAT_EXTMEM_0f90];
          *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) =
               (&DAT_CODE_39ec)[bVar4];
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x70;
          }
        } while (bVar4 != 0);
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          bVar4 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x66) =
               (&DAT_CODE_39b4)[DAT_EXTMEM_0f90];
          *(undefined1 *)CONCAT11('\t' - (((0x7b < bVar4) << 7) >> 7),bVar4 + 0x84) =
               (&DAT_CODE_39d0)[bVar4];
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x1c;
          }
        } while (bVar4 != 0);
        _5_1 = 1;
        FUN_CODE_2488();
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          bVar4 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x51) =
               (&DAT_CODE_3a78)[DAT_EXTMEM_0f90];
          *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) =
               (&DAT_CODE_3a5c)[bVar4];
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x70;
          }
        } while (bVar4 != 0);
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          param_2 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x66) =
               (&DAT_CODE_3a24)[DAT_EXTMEM_0f90];
          param_1 = (&DAT_CODE_3a40)[param_2];
          *(byte *)CONCAT11('\t' - (((0x7b < param_2) << 7) >> 7),param_2 + 0x84) = param_1;
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x1c;
          }
        } while (bVar4 != 0);
        _5_1 = 1;
        FUN_CODE_2488();
      }
      else {
        _5_1 = 1;
        FUN_CODE_2488();
        _4_1 = '\0';
        _5_0 = 0;
        _4_6 = '\0';
      }
    }
    cVar5 = INT0;
    if ((cVar5 == '\x01') && (cVar5 = INT1, cVar5 == '\0')) {
      if (_1_2 == '\0') {
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          bVar4 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x51) =
               (&DAT_CODE_3a08)[DAT_EXTMEM_0f90];
          *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) =
               (&DAT_CODE_39ec)[bVar4];
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x70;
          }
        } while (bVar4 != 0);
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          bVar4 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x66) =
               (&DAT_CODE_39b4)[DAT_EXTMEM_0f90];
          *(undefined1 *)CONCAT11('\t' - (((0x7b < bVar4) << 7) >> 7),bVar4 + 0x84) =
               (&DAT_CODE_39d0)[bVar4];
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x1c;
          }
        } while (bVar4 != 0);
        _5_1 = 0;
        FUN_CODE_2488();
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          bVar4 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x51) =
               (&DAT_CODE_3a78)[DAT_EXTMEM_0f90];
          *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) =
               (&DAT_CODE_3a5c)[bVar4];
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x70;
          }
        } while (bVar4 != 0);
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        do {
          param_2 = DAT_EXTMEM_0f90;
          *(undefined1 *)
           CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f90) << 7) >> 7),DAT_EXTMEM_0f90 + 0x66) =
               (&DAT_CODE_3a24)[DAT_EXTMEM_0f90];
          param_1 = (&DAT_CODE_3a40)[param_2];
          *(byte *)CONCAT11('\t' - (((0x7b < param_2) << 7) >> 7),param_2 + 0x84) = param_1;
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
          bVar4 = DAT_EXTMEM_0f8f;
          if (DAT_EXTMEM_0f8f == 0) {
            bVar4 = DAT_EXTMEM_0f90 ^ 0x1c;
          }
        } while (bVar4 != 0);
        _5_1 = 0;
        FUN_CODE_2488();
      }
      else {
        _5_1 = 0;
        FUN_CODE_2488();
        _4_1 = '\0';
        _5_0 = 0;
        _4_6 = '\0';
      }
    }
    if ((DAT_EXTMEM_06f9 >> 2 & 1) != 0) {
      DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xfb;
      FUN_CODE_7cc5(5,7,1);
      DAT_EXTMEM_0817 = ~param_2;
      DAT_EXTMEM_0816 = ~param_1;
      bVar4 = param_2 ^ DAT_EXTMEM_0132;
      if (bVar4 == 0) {
        bVar4 = param_1 ^ DAT_EXTMEM_0131;
      }
      if (bVar4 != 0) {
        _1_4 = '\x01';
        DAT_EXTMEM_0131 = param_1;
        DAT_EXTMEM_0132 = param_2;
      }
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_012f = param_1;
      DAT_EXTMEM_0130 = param_2;
    }
    if ((DAT_EXTMEM_06f9 & 1) != 0) {
      DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xfe;
      FUN_CODE_7cc5(0xfb,6,1);
      DAT_EXTMEM_0009 = ~param_2;
      DAT_EXTMEM_0008 = ~param_1;
      bVar4 = param_2 ^ DAT_EXTMEM_0134;
      if (bVar4 == 0) {
        bVar4 = param_1 ^ DAT_EXTMEM_0133;
      }
      if (bVar4 != 0) {
        _1_4 = '\x01';
        DAT_EXTMEM_0133 = param_1;
        DAT_EXTMEM_0134 = param_2;
      }
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_09b6 = param_1;
      DAT_EXTMEM_09b7 = param_2;
    }
    if ((DAT_EXTMEM_06f8 >> 2 & 1) != 0) {
      DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 & 0xfb;
      FUN_CODE_7cc5(0x32,8,1);
      DAT_EXTMEM_09df = ~param_2;
      DAT_EXTMEM_09de = ~param_1;
      bVar4 = param_2 ^ DAT_EXTMEM_013a;
      if (bVar4 == 0) {
        bVar4 = param_1 ^ DAT_EXTMEM_0139;
      }
      if (bVar4 != 0) {
        _1_4 = '\x01';
        DAT_EXTMEM_0139 = param_1;
        DAT_EXTMEM_013a = param_2;
      }
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_09a4 = param_1;
      DAT_EXTMEM_09a5 = param_2;
    }
    if ((DAT_EXTMEM_06f9 >> 4 & 1) != 0) {
      DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xef;
      FUN_CODE_7cc5(0x48,4,1);
      DAT_EXTMEM_0983 = ~param_2;
      DAT_EXTMEM_0982 = ~param_1;
      bVar4 = param_2 ^ DAT_EXTMEM_013c;
      if (bVar4 == 0) {
        bVar4 = param_1 ^ DAT_EXTMEM_013b;
      }
      DAT_EXTMEM_06f6 = param_1;
      DAT_EXTMEM_06f7 = param_2;
      if (bVar4 != 0) {
        DAT_EXTMEM_013b = param_1;
        DAT_EXTMEM_013c = param_2;
        FUN_CODE_6be2();
        _1_4 = '\x01';
      }
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
    }
    if ((DAT_EXTMEM_06f9 >> 5 & 1) != 0) {
      DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xdf;
      FUN_CODE_7cc5(0xc5,9,1);
      DAT_EXTMEM_09c1 = ~param_2;
      DAT_EXTMEM_09c0 = ~param_1;
      bVar4 = param_2 ^ DAT_EXTMEM_0138;
      if (bVar4 == 0) {
        bVar4 = param_1 ^ DAT_EXTMEM_0137;
      }
      if (bVar4 != 0) {
        _1_4 = '\x01';
        DAT_EXTMEM_0137 = param_1;
        DAT_EXTMEM_0138 = param_2;
      }
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_0960 = param_1;
      DAT_EXTMEM_0961 = param_2;
    }
    if ((DAT_EXTMEM_06f9 >> 6 & 1) == 1) {
      _4_1 = '\0';
      if (DAT_EXTMEM_0018 == '1') {
        DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xbf;
        _5_1 = 1;
        FUN_CODE_2488();
      }
      else if (DAT_EXTMEM_0018 == '2') {
        DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xbf;
        DAT_EXTMEM_0f91 = 0;
        DAT_EXTMEM_0f92 = 0;
        bVar4 = param_1;
        do {
          uVar1 = 0xaa;
          FUN_CODE_2c8f(DAT_EXTMEM_0f91,DAT_EXTMEM_0f92);
          bVar2 = 0x55;
          DAT_EXTMEM_0f91 = bVar4;
          DAT_EXTMEM_0f92 = uVar1;
          FUN_CODE_2c8f(bVar4,uVar1);
          bVar3 = DAT_EXTMEM_0016 - (((bVar2 < DAT_EXTMEM_0017) << 7) >> 7);
          DAT_EXTMEM_0f91 = bVar4;
          DAT_EXTMEM_0f92 = bVar2;
        } while ((bVar4 < bVar3) << 7 < '\0');
        param_1 = 10;
        param_2 = 0x10;
        _5_2 = 0;
        FUN_CODE_1ff3(bVar4 - bVar3);
      }
      else if (DAT_EXTMEM_0018 == '3') {
        DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xbf;
        DAT_EXTMEM_0f91 = 0;
        DAT_EXTMEM_0f92 = 0;
        bVar4 = param_1;
        do {
          uVar1 = 0x55;
          FUN_CODE_2c8f(DAT_EXTMEM_0f91,DAT_EXTMEM_0f92);
          bVar2 = 0xaa;
          DAT_EXTMEM_0f91 = bVar4;
          DAT_EXTMEM_0f92 = uVar1;
          FUN_CODE_2c8f(bVar4,uVar1);
          bVar3 = DAT_EXTMEM_0016 - (((bVar2 < DAT_EXTMEM_0017) << 7) >> 7);
          DAT_EXTMEM_0f91 = bVar4;
          DAT_EXTMEM_0f92 = bVar2;
        } while ((bVar4 < bVar3) << 7 < '\0');
        param_1 = 10;
        param_2 = 0x10;
        _5_2 = 0;
        FUN_CODE_1ff3(bVar4 - bVar3);
      }
      else if (DAT_EXTMEM_0018 == '9') {
        _5_1 = 0;
        FUN_CODE_2488();
        _5_1 = 1;
        FUN_CODE_2488();
      }
      else if (DAT_EXTMEM_0018 == '0') {
        DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xbf;
        _5_1 = 0;
        FUN_CODE_2488();
      }
      else {
        DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xbf;
      }
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
    }
    if ((DAT_EXTMEM_06f8 & 1) != 0) {
      DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 & 0xfe;
      _4_1 = '\0';
      _4_6 = '\0';
      _2_6 = '\0';
      FUN_CODE_54d5();
      DAT_EXTMEM_09b1 = '\0';
      DAT_EXTMEM_09a8 = 0;
      DAT_EXTMEM_09a9 = 0;
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
    }
    if ((DAT_EXTMEM_06f8 >> 1 & 1) != 0) {
      DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 & 0xfd;
      _4_1 = '\0';
      _4_6 = '\0';
      param_1 = 10;
      param_2 = 0x10;
      _5_2 = 0;
      FUN_CODE_1ff3();
      DAT_EXTMEM_09b1 = '\0';
      _0_4 = '\x01';
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_09a6 = 0;
      DAT_EXTMEM_09a7 = 0;
    }
    if (((0xeaU - (((DAT_EXTMEM_09a7 < 0x60) << 7) >> 7) <= DAT_EXTMEM_09a6) && (_0_4 != '\0')) &&
       (DAT_EXTMEM_09bd == 0)) {
      _1_4 = '\x01';
      DAT_EXTMEM_012f = DAT_EXTMEM_09bd;
      DAT_EXTMEM_0130 = DAT_EXTMEM_09bd;
      _0_4 = '\0';
    }
    if (((_1_4 == '\x01') || (_0_6 == '\x01')) || ((_4_1 == '\x01' || (_4_6 == '\x01')))) {
      DAT_EXTMEM_0f8f = 0;
      DAT_EXTMEM_0f90 = 0;
      while (bVar4 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7),
            DAT_EXTMEM_0f8f < bVar4) {
        bVar4 = 1;
        cVar5 = FUN_CODE_750b(0);
        *(undefined1 *)CONCAT11(cVar5 + ('\n' - (((0xef < bVar4) << 7) >> 7)),bVar4 + 0x10) = 0;
      }
      if ((_1_4 == '\x01') || (_0_6 == '\x01')) {
        _1_4 = '\0';
        _0_6 = '\0';
        _4_1 = '\0';
        _1_3 = 0;
        _3_6 = 1;
        _4_0 = '\0';
        _3_5 = 0;
        _3_7 = '\0';
        _2_3 = 0;
        _1_0 = 0;
        _4_6 = '\0';
        FUN_CODE_7002(DAT_EXTMEM_0f8f - bVar4,0x2c,4);
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        while (bVar4 = DAT_EXTMEM_09ef, cVar5 = DAT_EXTMEM_09ee,
              DAT_EXTMEM_0f8f < DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7))
        {
          bVar3 = 1;
          cVar6 = FUN_CODE_750b(0,0xf8f);
          *(undefined1 *)CONCAT11(cVar6 + (cVar5 - ((CARRY1(bVar4,bVar3) << 7) >> 7)),bVar4 + bVar3)
               = 0;
        }
        DAT_EXTMEM_0f8f = 0;
        DAT_EXTMEM_0f90 = 0;
        while (DAT_EXTMEM_0f8f < DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7)
              ) {
          *(undefined1 *)
           CONCAT11(DAT_EXTMEM_0f8f + ('\x01' - (((0x5b < DAT_EXTMEM_0f90) << 7) >> 7)),
                    DAT_EXTMEM_0f90 + 0xa4) = 0;
          DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
          if (DAT_EXTMEM_0f90 == 0) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
          }
        }
      }
      param_2 = DAT_EXTMEM_0017;
      param_1 = DAT_EXTMEM_0016;
      if (DAT_EXTMEM_0964 == 1) {
        DAT_EXTMEM_09e0 = 0;
        DAT_EXTMEM_09e1 = 0;
        bVar4 = DAT_EXTMEM_09b6;
        if (DAT_EXTMEM_09b6 == 0) {
          bVar4 = DAT_EXTMEM_09b7;
        }
        if (bVar4 == 0) {
          DAT_EXTMEM_09e0 = 0;
          DAT_EXTMEM_09e1 = 0;
        }
        else {
          FUN_CODE_7cc5(0xfb,6,1);
          bVar4 = DAT_EXTMEM_09b7 ^ param_2;
          if (bVar4 == 0) {
            bVar4 = param_1 ^ DAT_EXTMEM_09b6;
          }
          if (bVar4 == 0) {
            FUN_CODE_4a41();
            DAT_EXTMEM_09e0 = param_1;
            DAT_EXTMEM_09e1 = param_2;
          }
        }
      }
      else if (DAT_EXTMEM_0964 == 2) {
        DAT_EXTMEM_09e0 = 0;
        DAT_EXTMEM_09e1 = 0;
        param_1 = 1;
        param_2 = 0x21;
        FUN_CODE_3ad6(0,DAT_EXTMEM_09b6,DAT_EXTMEM_09b7);
        DAT_EXTMEM_082d = param_2;
        if (param_2 == 0) {
          bVar4 = DAT_EXTMEM_09b6;
          if (DAT_EXTMEM_09b6 == 0) {
            bVar4 = DAT_EXTMEM_09b7;
          }
          if (bVar4 == 0) {
            DAT_EXTMEM_09e0 = 0;
            DAT_EXTMEM_09e1 = 0;
          }
          else {
            FUN_CODE_7cc5(0xfb,6,1);
            if ((DAT_EXTMEM_09b7 == BANK0_R7) && (param_1 == BANK0_R4)) {
              FUN_CODE_4a41(DAT_EXTMEM_09b6);
              DAT_EXTMEM_09e0 = param_1;
              DAT_EXTMEM_09e1 = param_2;
            }
          }
        }
      }
      else if (DAT_EXTMEM_0964 == 0) {
        DAT_EXTMEM_09e0 = 0;
        DAT_EXTMEM_09e1 = 0;
      }
      if (_4_1 != '\0') {
        while (((param_1 = DAT_EXTMEM_0830, param_2 = DAT_EXTMEM_0831,
                DAT_EXTMEM_09d5 <
                DAT_EXTMEM_0830 - (((DAT_EXTMEM_09d6 < DAT_EXTMEM_0831 + 1) << 7) >> 7) &&
                (_2_6 != '\x01')) && (_1_7 != '\x01'))) {
          DAT_EXTMEM_09d3 = 0x4e;
          DAT_EXTMEM_09d4 = 0x20;
        }
      }
      if (_4_0 == '\0') {
        if (_4_6 == '\0') {
          param_1 = 1;
          bVar4 = 0x18;
          FUN_CODE_3ad6(1,DAT_EXTMEM_012f,DAT_EXTMEM_0130);
          DAT_EXTMEM_082e = bVar4;
        }
        else {
          param_1 = 1;
          bVar4 = 0x18;
          FUN_CODE_3ad6(1,DAT_EXTMEM_09eb,DAT_EXTMEM_09ec);
          DAT_EXTMEM_082e = bVar4;
        }
        param_2 = DAT_EXTMEM_082e;
        if (DAT_EXTMEM_082e == 1) {
          DAT_EXTMEM_0f8f = 0;
          DAT_EXTMEM_0f90 = 0;
          while (bVar4 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7),
                DAT_EXTMEM_0f8f < bVar4) {
            cVar5 = DAT_EXTMEM_0f8f + ('\n' - (((0xef < DAT_EXTMEM_0f90) << 7) >> 7));
            uStack_1 = (byte *)CONCAT11(cVar5,DAT_EXTMEM_0f90 + 0x10);
            *uStack_1 = *(byte *)CONCAT11(cVar5,DAT_EXTMEM_0f90 + 0x10) |
                        *(byte *)CONCAT11(DAT_EXTMEM_0f8f +
                                          (DAT_EXTMEM_09ee -
                                          ((CARRY1(DAT_EXTMEM_09ef,DAT_EXTMEM_0f90) << 7) >> 7)),
                                          DAT_EXTMEM_09ef + DAT_EXTMEM_0f90);
            DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
            if (DAT_EXTMEM_0f90 == 0) {
              DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
            }
          }
          param_1 = 10;
          param_2 = 0x10;
          _5_2 = _1_3 & 1;
          FUN_CODE_1ff3(DAT_EXTMEM_0f8f - bVar4);
        }
        if ((_4_0 == '\x01') || (DAT_EXTMEM_082e == 0)) {
          DAT_EXTMEM_0f8f = 0;
          DAT_EXTMEM_0f90 = 0;
          while (bVar4 = DAT_EXTMEM_09ef, cVar5 = DAT_EXTMEM_09ee,
                DAT_EXTMEM_0f8f <
                DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7)) {
            bVar3 = 1;
            cVar6 = FUN_CODE_750b(0,0xf8f);
            *(undefined1 *)
             CONCAT11(cVar6 + (cVar5 - ((CARRY1(bVar4,bVar3) << 7) >> 7)),bVar4 + bVar3) = 0;
          }
          _3_6 = 0;
          _3_5 = 1;
          param_1 = 0;
          param_2 = 0x1a;
          FUN_CODE_3ad6(2,DAT_EXTMEM_0960,DAT_EXTMEM_0961);
          DAT_EXTMEM_082f = param_2;
          if (param_2 == 1) {
            _4_0 = '\x01';
            _3_5 = 1;
            _3_7 = '\0';
            _4_1 = '\x01';
            _2_3 = 0;
          }
          else {
            _4_0 = '\0';
            _3_5 = 0;
            _3_7 = '\x01';
          }
        }
      }
      else if (_3_7 == '\0') {
        param_1 = 0;
        param_2 = 0x1a;
        FUN_CODE_3ad6(2,DAT_EXTMEM_0960,DAT_EXTMEM_0961);
        DAT_EXTMEM_082f = param_2;
        if (param_2 == 1) {
          DAT_EXTMEM_0f8f = 0;
          DAT_EXTMEM_0f90 = 0;
          while (bVar4 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7),
                DAT_EXTMEM_0f8f < bVar4) {
            cVar5 = DAT_EXTMEM_0f8f + ('\n' - (((0xef < DAT_EXTMEM_0f90) << 7) >> 7));
            uStack_1 = (byte *)CONCAT11(cVar5,DAT_EXTMEM_0f90 + 0x10);
            *uStack_1 = *(byte *)CONCAT11(cVar5,DAT_EXTMEM_0f90 + 0x10) |
                        *(byte *)CONCAT11(DAT_EXTMEM_0f8f +
                                          (DAT_EXTMEM_09ee -
                                          ((CARRY1(DAT_EXTMEM_09ef,DAT_EXTMEM_0f90) << 7) >> 7)),
                                          DAT_EXTMEM_09ef + DAT_EXTMEM_0f90);
            DAT_EXTMEM_0f90 = DAT_EXTMEM_0f90 + 1;
            if (DAT_EXTMEM_0f90 == 0) {
              DAT_EXTMEM_0f8f = DAT_EXTMEM_0f8f + 1;
            }
          }
          param_1 = 10;
          param_2 = 0x10;
          _5_2 = _1_3 & 1;
          FUN_CODE_1ff3(DAT_EXTMEM_0f8f - bVar4);
        }
        if ((_3_7 == '\x01') || (DAT_EXTMEM_082f == 0)) {
          DAT_EXTMEM_0f8f = 0;
          DAT_EXTMEM_0f90 = 0;
          while (bVar4 = DAT_EXTMEM_09ef, cVar5 = DAT_EXTMEM_09ee,
                DAT_EXTMEM_0f8f <
                DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7)) {
            bVar3 = 1;
            cVar6 = FUN_CODE_750b(0,0xf8f);
            *(undefined1 *)
             CONCAT11(cVar6 + (cVar5 - ((CARRY1(bVar4,bVar3) << 7) >> 7)),bVar4 + bVar3) = 0;
          }
          _3_5 = 0;
          _3_6 = 1;
          if (_4_6 == '\0') {
            param_1 = 1;
            bVar4 = 0x18;
            FUN_CODE_3ad6(1,DAT_EXTMEM_012f,DAT_EXTMEM_0130);
            DAT_EXTMEM_082e = bVar4;
          }
          else {
            param_1 = 1;
            bVar4 = 0x18;
            FUN_CODE_3ad6(1,DAT_EXTMEM_09eb,DAT_EXTMEM_09ec);
            DAT_EXTMEM_082e = bVar4;
          }
          param_2 = DAT_EXTMEM_082e;
          if (DAT_EXTMEM_082e == 1) {
            _3_7 = '\x01';
            _3_6 = 1;
            _4_0 = '\0';
            _4_1 = '\x01';
            _1_0 = 0;
          }
          else {
            _3_7 = '\0';
            _3_6 = 0;
            _4_0 = '\x01';
            if (_4_3 != '\0') {
              _4_1 = '\0';
            }
          }
        }
      }
      if ((DAT_EXTMEM_082e == 0) && (DAT_EXTMEM_082f == 0)) {
        bVar4 = DAT_EXTMEM_09b6;
        if (DAT_EXTMEM_0964 == 1) {
          if (DAT_EXTMEM_09b6 == 0) {
            bVar4 = DAT_EXTMEM_09b7;
          }
          if (bVar4 == 0) {
            DAT_EXTMEM_0f8f = 0;
            DAT_EXTMEM_0f90 = 0;
            while (bVar3 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7),
                  bVar4 = DAT_EXTMEM_0f8f - bVar3, DAT_EXTMEM_0f8f < bVar3) {
              bVar4 = 1;
              cVar5 = FUN_CODE_750b(0);
              *(undefined1 *)CONCAT11(cVar5 + ('\n' - (((0xef < bVar4) << 7) >> 7)),bVar4 + 0x10) =
                   0;
            }
          }
        }
        else if (DAT_EXTMEM_0964 == 2) {
          if (DAT_EXTMEM_09b6 == 0) {
            bVar4 = DAT_EXTMEM_09b7;
          }
          if ((bVar4 == 0) && (bVar4 = DAT_EXTMEM_082d, DAT_EXTMEM_082d == 0)) {
            DAT_EXTMEM_0f8f = DAT_EXTMEM_082d;
            DAT_EXTMEM_0f90 = DAT_EXTMEM_082d;
            while (bVar3 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7),
                  bVar4 = DAT_EXTMEM_0f8f - bVar3, DAT_EXTMEM_0f8f < bVar3) {
              bVar4 = 1;
              cVar5 = FUN_CODE_750b(0);
              *(undefined1 *)CONCAT11(cVar5 + ('\n' - (((0xef < bVar4) << 7) >> 7)),bVar4 + 0x10) =
                   0;
            }
          }
        }
        else {
          bVar4 = DAT_EXTMEM_0964;
          if (DAT_EXTMEM_0964 == 0) {
            DAT_EXTMEM_0f8f = 0;
            DAT_EXTMEM_0f90 = 0;
            while (bVar3 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f90 < DAT_EXTMEM_0017) << 7) >> 7),
                  bVar4 = DAT_EXTMEM_0f8f - bVar3, (DAT_EXTMEM_0f8f < bVar3) << 7 < '\0') {
              bVar4 = 1;
              cVar5 = FUN_CODE_750b(0);
              *(undefined1 *)CONCAT11(cVar5 + ('\n' - (((0xef < bVar4) << 7) >> 7)),bVar4 + 0x10) =
                   0;
            }
          }
        }
        param_1 = 10;
        param_2 = 0x10;
        _5_2 = 0;
        FUN_CODE_1ff3(bVar4);
        _4_0 = '\x01';
        _3_7 = '\x01';
        _4_1 = '\0';
      }
    }
    if (((0xeaU - (((DAT_EXTMEM_09a9 < 0x61) << 7) >> 7) <= DAT_EXTMEM_09a8) &&
        (param_2 = DAT_EXTMEM_0710, DAT_EXTMEM_0710 != 0)) && (DAT_EXTMEM_0710 != 5)) {
      LATCH3_7SEG_802_15 = 0xb6;
      _4_1 = '\0';
      _4_6 = '\0';
      _2_0 = '\x01';
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      _5_1 = 0;
      FUN_CODE_2488();
      DAT_EXTMEM_09a8 = 0;
      DAT_EXTMEM_09a9 = 0;
    }
    if ((DAT_EXTMEM_0013 == 0xff) && (_2_0 != '\x01')) {
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 & 0xfc;
      cVar5 = P1_5;
      if (cVar5 == '\x01') {
        param_2 = 6;
        FUN_CODE_6700();
      }
      else {
        param_2 = 0;
        FUN_CODE_6700();
      }
      DAT_EXTMEM_09b1 = '\0';
      DAT_EXTMEM_0013 = 0x6e;
      LATCH3_7SEG_802_15 = 0x92;
    }
    if ((DAT_EXTMEM_09b1 == '\x03') && (0xc < DAT_EXTMEM_0013)) {
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 & 0xfe;
      DAT_EXTMEM_000b = 0;
      DAT_EXTMEM_000c = 0;
      cVar5 = P1_5;
      if (cVar5 == '\x01') {
        param_2 = 6;
        FUN_CODE_6700();
      }
      else {
        param_2 = 0;
        FUN_CODE_6700();
      }
      DAT_EXTMEM_09b1 = '\0';
      LATCH3_7SEG_802_15 = 199;
      FUN_CODE_6be2();
      _0_6 = '\x01';
      LATCH3_7SEG_802_15 = 0x92;
    }
    if ((DAT_EXTMEM_09b1 == '\x01') && (10 < DAT_EXTMEM_0013)) {
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      DAT_EXTMEM_09b1 = '\0';
      cVar5 = P1_5;
      if (cVar5 == '\x01') {
        param_2 = 6;
        FUN_CODE_6700();
      }
      else {
        param_2 = 0;
        FUN_CODE_6700();
      }
      LATCH3_7SEG_802_15 = 0x92;
    }
  } while( true );
}



// ==== FUN_CODE_0d57 @ CODE:0d57  (1304 bytes)

/* WARNING: Removing unreachable block (CODE,0x0f45) */
/* WARNING: Removing unreachable block (CODE,0x0f14) */
/* WARNING: Removing unreachable block (CODE,0x0ef8) */
/* WARNING: Removing unreachable block (CODE,0x0ec7) */
/* WARNING: Removing unreachable block (CODE,0x0eab) */
/* WARNING: Removing unreachable block (CODE,0x0e7a) */
/* WARNING: Removing unreachable block (CODE,0x0e5e) */
/* WARNING: Removing unreachable block (CODE,0x0f61) */

char FUN_CODE_0d57(byte param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  EA = 0;
  LATCH0_EZ_row_color_LED_bank = 0;
  LATCH1_ES_FP2800 = 0;
  LATCH2_module_enable = 0;
  LATCH3_7SEG_802_15 = 0xff;
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 | 0x20;
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 | 0x40;
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 | 0x80;
  LATCH3_7SEG_802_15 = 0;
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 & 0x7f;
  LATCH3_7SEG_802_15 = 0xff;
  bVar4 = T1;
  T1 = bVar4 ^ 1;
  PCON = 0x80;
  IP = 0x10;
  TMOD = 0x21;
  TCON = 0x50;
  cVar3 = cpu_detect_80c31_80c32();
  SCON = 0xd8;
  IE = 2;
  bVar4 = T1;
  T1 = bVar4 ^ 1;
  _0_0 = '\0';
  cVar5 = INT1;
  if (cVar5 == '\0') {
    DAT_INTMEM_26 = 0;
    DAT_INTMEM_27 = 4;
    do {
      bVar4 = T1;
      T1 = bVar4 ^ 1;
      FUN_CODE_6e9c(cVar3);
      param_1 = DAT_INTMEM_27;
      DAT_INTMEM_2a = DAT_INTMEM_26;
      DAT_INTMEM_2b = DAT_INTMEM_27;
      DAT_INTMEM_2c = *(char *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27);
      *(undefined1 *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) = 0x55;
      if (*(char *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) != 'U') {
        *(char *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) = DAT_INTMEM_2c;
        _0_0 = '\x01';
        break;
      }
      *(undefined1 *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) = 0xaa;
      if (*(char *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) != -0x56) {
        *(char *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) = DAT_INTMEM_2c;
        _0_0 = '\x01';
        break;
      }
      *(char *)CONCAT11(DAT_INTMEM_26,DAT_INTMEM_27) = DAT_INTMEM_2c;
      DAT_INTMEM_27 = DAT_INTMEM_27 + 1;
      if (DAT_INTMEM_27 == 0) {
        DAT_INTMEM_26 = DAT_INTMEM_26 + 1;
      }
      cVar3 = DAT_INTMEM_26 - 0xf;
    } while (DAT_INTMEM_26 < 0xf);
  }
  else {
    DAT_INTMEM_2d = DAT_EXTMEM_0800;
    DAT_INTMEM_2e = DAT_EXTMEM_0801;
    _0_0 = '\0';
  }
  if (_0_0 != '\0') {
    bVar4 = T1;
    T1 = bVar4 ^ 1;
    EA = 0;
    do {
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 & 0xdf;
      DAT_INTMEM_28 = '\0';
      DAT_INTMEM_29 = '\0';
      do {
        DAT_INTMEM_29 = DAT_INTMEM_29 + '\x01';
        if (DAT_INTMEM_29 == '\0') {
          DAT_INTMEM_28 = DAT_INTMEM_28 + '\x01';
        }
      } while ((DAT_INTMEM_29 != -0x78) || (DAT_INTMEM_28 != '\x13'));
      bVar4 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar4 | 0x20;
      DAT_INTMEM_28 = 0;
      DAT_INTMEM_29 = 0;
      while (DAT_INTMEM_28 < 0x13U - (((DAT_INTMEM_29 < 0x88) << 7) >> 7)) {
        DAT_INTMEM_29 = DAT_INTMEM_29 + 1;
        if (DAT_INTMEM_29 == 0) {
          DAT_INTMEM_28 = DAT_INTMEM_28 + 1;
        }
      }
    } while( true );
  }
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 & 0xdf;
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 | 0x40;
  bVar4 = T1;
  T1 = bVar4 ^ 1;
  DAT_EXTMEM_0750 = 1;
  DAT_EXTMEM_083c = '\x10';
  DAT_EXTMEM_083d = '\0';
  FUN_CODE_368b();
  bVar4 = DAT_EXTMEM_0963 ^ ~DAT_EXTMEM_082c;
  if (bVar4 == 0) {
    bVar4 = ~DAT_EXTMEM_082b ^ DAT_EXTMEM_0962;
  }
  if (bVar4 != 0) {
    DAT_EXTMEM_0962 = 0;
    DAT_EXTMEM_0963 = 0;
  }
  cVar5 = INT0;
  DAT_EXTMEM_0750 = param_1;
  if ((cVar5 == '\x01') || (param_1 != 2)) {
    bVar4 = DAT_EXTMEM_0962;
    if (DAT_EXTMEM_0962 == 0) {
      bVar4 = DAT_EXTMEM_0963;
    }
    if ((bVar4 != 0) || (param_1 != 2)) {
      param_1 = param_1 ^ 3;
      if (param_1 == 0) {
        DAT_EXTMEM_0962 = param_1;
        DAT_EXTMEM_0963 = param_1;
        FUN_CODE_6ecb(0);
        cVar5 = '\0';
        FUN_CODE_7018(0x10,0);
        if (cVar5 == '\x01') {
          DAT_EXTMEM_0962 = DAT_EXTMEM_0f6e | DAT_EXTMEM_0962 | DAT_EXTMEM_0f6a;
          DAT_EXTMEM_0963 = DAT_EXTMEM_0f6f | DAT_EXTMEM_0963 | DAT_EXTMEM_0f6b;
        }
        FUN_CODE_6ecb(1);
        cVar5 = '\0';
        FUN_CODE_7018(0x10,0);
        if (cVar5 == '\x01') {
          DAT_EXTMEM_0962 = DAT_EXTMEM_0f70 | DAT_EXTMEM_0962 | DAT_EXTMEM_0f6c;
          DAT_EXTMEM_0963 = DAT_EXTMEM_0f71 | DAT_EXTMEM_0963 | DAT_EXTMEM_0f6d;
        }
        DAT_EXTMEM_082c = ~DAT_EXTMEM_0963;
        DAT_EXTMEM_082b = ~DAT_EXTMEM_0962;
      }
      goto LAB_CODE_1143;
    }
  }
  DAT_EXTMEM_0962 = 0;
  DAT_EXTMEM_0963 = 0;
  if ((DAT_EXTMEM_083d == '\0') && (DAT_EXTMEM_083c == -0x80)) {
    DAT_EXTMEM_0f94 = 2;
  }
  else if ((BANK0_R7 == '\0') && (DAT_EXTMEM_083c == '\x10')) {
    DAT_EXTMEM_0f94 = 4;
  }
  else {
    DAT_EXTMEM_0f94 = 0;
  }
  for (DAT_EXTMEM_0f93 = 0; DAT_EXTMEM_0f93 < DAT_EXTMEM_0f94; DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1
      ) {
    bVar4 = DAT_EXTMEM_0f93;
    FUN_CODE_6ecb(DAT_EXTMEM_0f93 - DAT_EXTMEM_0f94);
    FUN_CODE_3609();
    if (bVar4 == 1) {
      bVar4 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
      pbVar6 = (byte *)CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                                ('\x0f' - (((0x95 < bVar4) << 7) >> 7)),bVar4 + 0x6a);
      DAT_EXTMEM_0962 = DAT_EXTMEM_0962 | *pbVar6;
      DAT_EXTMEM_0963 = DAT_EXTMEM_0963 | pbVar6[1];
    }
  }
  DAT_EXTMEM_082c = ~DAT_EXTMEM_0963;
  DAT_EXTMEM_082b = ~DAT_EXTMEM_0962;
LAB_CODE_1143:
  for (DAT_EXTMEM_0f93 = 0; cVar5 = DAT_EXTMEM_083d, DAT_EXTMEM_0f93 < 4;
      DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1) {
    bVar4 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
    pbVar6 = (byte *)CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                              ('\x0f' - (((0x95 < bVar4) << 7) >> 7)),bVar4 + 0x6a);
    if ((DAT_EXTMEM_0963 & pbVar6[1]) == 0 && (DAT_EXTMEM_0962 & *pbVar6) == 0) {
      puVar7 = (undefined1 *)
               CONCAT11('\b' - (((0xe0 < DAT_EXTMEM_0f93 * '\x02') << 7) >> 7),
                        DAT_EXTMEM_0f93 * '\x02' + 0x1f);
      *puVar7 = 0xff;
      puVar7[1] = 0xff;
    }
    else {
      pcVar8 = (char *)CONCAT11('\b' - (((0xe0 < DAT_EXTMEM_0f93 * '\x02') << 7) >> 7),
                                DAT_EXTMEM_0f93 * '\x02' + 0x1f);
      *pcVar8 = DAT_EXTMEM_083c;
      pcVar8[1] = cVar5;
    }
  }
  FUN_CODE_68c0(DAT_EXTMEM_0f93 - 4);
  bVar4 = DAT_EXTMEM_0962;
  if (DAT_EXTMEM_0962 == 0) {
    bVar4 = DAT_EXTMEM_0963;
  }
  if ((bVar4 != 0) && ((DAT_EXTMEM_0750 == 2 || (DAT_EXTMEM_0750 == 3)))) {
    DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
    DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
    DAT_EXTMEM_0a05 = 0;
    _4_5 = 0;
    cVar5 = DAT_EXTMEM_083d;
    while (FUN_CODE_6775(), DAT_INTMEM_2c = cVar5, cVar5 == '\x01') {
      cVar3 = DAT_EXTMEM_0f52;
      cVar5 = DAT_EXTMEM_0f53;
      FUN_CODE_5411();
      if ((cVar5 != '\0' || cVar3 != '\0') && (DAT_EXTMEM_0750 == 2)) {
        LATCH3_7SEG_802_15 = 0x98;
        cVar5 = DAT_EXTMEM_0a07;
        FUN_CODE_6916(DAT_EXTMEM_0a06);
      }
    }
  }
  bVar4 = LATCH0_EZ_row_color_LED_bank;
  LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
  bVar4 = T1;
  T1 = bVar4 ^ 1;
  FUN_CODE_1d05();
  bVar4 = T1;
  T1 = bVar4 ^ 1;
  cVar5 = P1_5;
  if (cVar5 == '\x01') {
    FUN_CODE_6700(6);
  }
  else {
    FUN_CODE_6700(0);
  }
  cVar1 = P1_2;
  cVar5 = P1_0;
  cVar3 = P1_1;
  cVar2 = P1_3;
  DAT_EXTMEM_09bc =
       (cVar2 != '\x01') * '\b' +
       (cVar3 != '\x01') * '\x04' + (cVar1 != '\x01') * '\x02' + (cVar5 != '\x01');
  cVar5 = DAT_EXTMEM_09bc - 0x10;
  if (0xf < DAT_EXTMEM_09bc) {
    cVar5 = '\0';
    DAT_EXTMEM_09bc = 0;
  }
  ES = 1;
  EA = 1;
  return cVar5;
}



// ==== isr_timer0 @ CODE:126f  (744 bytes)

/* WARNING: Removing unreachable block (CODE,0x139b) */
/* WARNING: Removing unreachable block (CODE,0x138b) */
/* WARNING: Removing unreachable block (CODE,0x1393) */
/* WARNING: Removing unreachable block (CODE,0x1383) */

undefined1 isr_timer0(undefined1 param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  
  if (_4_7 == '\0') {
    TL0 = 5;
    TH0 = 0xff;
  }
  else {
    TL0 = 0x32;
    TH0 = 0xfe;
  }
  if ((byte)-(((DAT_EXTMEM_09d4 == '\0') << 7) >> 7) <= DAT_EXTMEM_09d3) {
    bVar1 = DAT_EXTMEM_09d4 != '\0';
    DAT_EXTMEM_09d4 = DAT_EXTMEM_09d4 + -1;
    DAT_EXTMEM_09d3 = DAT_EXTMEM_09d3 + (-1 - ((bVar1 << 7) >> 7));
    bVar2 = T1;
    T1 = bVar2 ^ 1;
  }
  if ((DAT_EXTMEM_0115 < 0xeaU - (((DAT_EXTMEM_0116 < 0x60) << 7) >> 7)) &&
     (DAT_EXTMEM_0116 = DAT_EXTMEM_0116 + 1, DAT_EXTMEM_0116 == 0)) {
    DAT_EXTMEM_0115 = DAT_EXTMEM_0115 + 1;
  }
  if (_2_1 == '\0') {
    _2_1 = 1;
  }
  else {
    if ((DAT_EXTMEM_09a6 < 0xfdU - (((DAT_EXTMEM_09a7 < 0xe8) << 7) >> 7)) &&
       (DAT_EXTMEM_09a7 = DAT_EXTMEM_09a7 + 1, DAT_EXTMEM_09a7 == 0)) {
      DAT_EXTMEM_09a6 = DAT_EXTMEM_09a6 + 1;
    }
    _2_1 = 0;
  }
  if (_2_2 == '\0') {
    _2_2 = 1;
  }
  else {
    if ((DAT_EXTMEM_09a8 < 0xfdU - (((DAT_EXTMEM_09a9 < 0xe8) << 7) >> 7)) &&
       (DAT_EXTMEM_09a9 = DAT_EXTMEM_09a9 + 1, DAT_EXTMEM_09a9 == 0)) {
      DAT_EXTMEM_09a8 = DAT_EXTMEM_09a8 + 1;
    }
    _2_2 = 0;
  }
  if ((DAT_EXTMEM_09d5 < 0xeaU - (((DAT_EXTMEM_09d6 < 0x60) << 7) >> 7)) &&
     (DAT_EXTMEM_09d6 = DAT_EXTMEM_09d6 + 1, DAT_EXTMEM_09d6 == 0)) {
    DAT_EXTMEM_09d5 = DAT_EXTMEM_09d5 + 1;
  }
  DAT_EXTMEM_070f = DAT_EXTMEM_070f + 1;
  if ((99 < DAT_EXTMEM_070f) && (DAT_EXTMEM_070f = 0, DAT_EXTMEM_0013 != -1)) {
    DAT_EXTMEM_0013 = DAT_EXTMEM_0013 + '\x01';
  }
  if ((DAT_EXTMEM_06f9 >> 3 & 1) == 1) {
    if ((DAT_EXTMEM_0710 == '\x05') && (DAT_EXTMEM_09e4 != '\0')) {
      DAT_EXTMEM_09e4 = DAT_EXTMEM_09e4 + -1;
    }
    else {
      DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xf7;
      DAT_EXTMEM_09c4 = 0;
      DAT_EXTMEM_0019 = 0x30;
      DAT_EXTMEM_00e7 = 0x61;
      DAT_EXTMEM_00e8 = 0x30;
      DAT_EXTMEM_00e9 = 0xd;
      DAT_EXTMEM_0f8b = 3;
      uVar4 = 3;
      FUN_CODE_2ce9();
      DAT_EXTMEM_0452 = 0xfe < DAT_EXTMEM_0f8b;
      DAT_EXTMEM_0453 = DAT_EXTMEM_0f8b + 1;
      DAT_EXTMEM_09ad = 0;
      DAT_EXTMEM_09ae = 0;
      DAT_EXTMEM_09b2 = '\x01';
      bVar2 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar2 & 0xbf;
      TI = 1;
      DAT_EXTMEM_00ea = uVar4;
    }
  }
  if ((char)DAT_EXTMEM_06f9 < '\0') {
    DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0x7f;
    DAT_EXTMEM_00e7 = 0x61;
    DAT_EXTMEM_00e8 = 0x56;
    DAT_EXTMEM_00e9 = 0x4c;
    DAT_EXTMEM_00ea = 0x4c;
    DAT_EXTMEM_00eb = 0x45;
    DAT_EXTMEM_00ec = 0x49;
    DAT_EXTMEM_00ed = 0x31;
    DAT_EXTMEM_00ee = 0x32;
    DAT_EXTMEM_00ef = 0xd;
    DAT_EXTMEM_0f8b = 9;
    uVar4 = 9;
    FUN_CODE_2ce9();
    DAT_EXTMEM_0452 = 0xfe < DAT_EXTMEM_0f8b;
    DAT_EXTMEM_0453 = DAT_EXTMEM_0f8b + 1;
    DAT_EXTMEM_09ad = 0;
    DAT_EXTMEM_09ae = 0;
    DAT_EXTMEM_09b2 = '\x01';
    bVar2 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar2 & 0xbf;
    TI = 1;
    DAT_EXTMEM_00f0 = uVar4;
  }
  if (((DAT_EXTMEM_06f8 >> 6 & 1) == 1) && (DAT_EXTMEM_09b2 == '\0')) {
    DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 & 0xbf;
    DAT_EXTMEM_019f = 0x61;
    DAT_EXTMEM_01a1 = DAT_EXTMEM_0017 + 6;
    DAT_EXTMEM_0452 = DAT_EXTMEM_0016 - (((0xf9 < DAT_EXTMEM_0017) << 7) >> 7);
    DAT_EXTMEM_01a2 = DAT_EXTMEM_09b5;
    if ((DAT_EXTMEM_09bf < DAT_EXTMEM_09be) << 7 < '\0') {
      DAT_EXTMEM_01a3 = DAT_EXTMEM_09be;
    }
    else {
      DAT_EXTMEM_01a3 = DAT_EXTMEM_09bf;
    }
    bVar2 = 0xff;
    bVar5 = 0;
    bVar3 = 0;
    while (bVar3 < (byte)((DAT_EXTMEM_0452 + (-1 - (((1 < BANK1_R7) << 7) >> 7))) -
                         (((bVar5 < BANK1_R7 - 2) << 7) >> 7))) {
      bVar2 = *(byte *)CONCAT11(bVar3 + ('\x01' - (((0x60 < bVar5) << 7) >> 7)),bVar5 + 0x9f) ^
              bVar2;
      bVar5 = bVar5 + 1;
      if (bVar5 == 0) {
        bVar3 = bVar3 + 1;
      }
    }
    DAT_EXTMEM_01a0 = DAT_EXTMEM_0452;
    *(byte *)CONCAT11(DAT_EXTMEM_0452 + ('\x01' - (((0x61 < BANK1_R7) << 7) >> 7)),BANK1_R7 + 0x9e)
         = bVar2;
    DAT_EXTMEM_0453 = BANK1_R5;
    DAT_EXTMEM_09ad = 0;
    DAT_EXTMEM_09ae = 0;
    DAT_EXTMEM_09b2 = '\x02';
    bVar2 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar2 & 0xbf;
    LATCH3_7SEG_802_15 = 0x7f;
    TI = 1;
  }
  if ((DAT_EXTMEM_09b4 & 1) != 0) {
    DAT_EXTMEM_09b4 = DAT_EXTMEM_09b4 & 0xfe;
    DAT_EXTMEM_00e7 = 0x61;
    DAT_EXTMEM_00e8 = 0x5a;
    DAT_EXTMEM_00e9 = 0x38;
    DAT_EXTMEM_00ea = 0xd;
    DAT_EXTMEM_0f8b = 4;
    uVar4 = 4;
    FUN_CODE_2ce9();
    DAT_EXTMEM_0452 = 0xfe < DAT_EXTMEM_0f8b;
    DAT_EXTMEM_0453 = DAT_EXTMEM_0f8b + 1;
    DAT_EXTMEM_09ad = 0;
    DAT_EXTMEM_09ae = 0;
    DAT_EXTMEM_09b2 = '\x01';
    bVar2 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar2 & 0xbf;
    TI = 1;
    DAT_EXTMEM_00eb = uVar4;
  }
  return param_1;
}



// ==== isr_serial @ CODE:1557  (1966 bytes)

undefined1 isr_serial(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  
  bVar1 = DAT_EXTMEM_09a1;
  bVar4 = DAT_EXTMEM_09a0;
  DAT_EXTMEM_0a0e = 10;
  DAT_EXTMEM_0a0f = 0x10;
  DAT_EXTMEM_0f56 = '\n';
  DAT_EXTMEM_0f57 = 0x10;
  DAT_EXTMEM_0013 = 0;
  cVar5 = RI;
  if (cVar5 == '\x01') {
    RI = 0;
    DAT_EXTMEM_0f8c = SBUF;
    if (DAT_EXTMEM_09b1 == '\x01') {
      if ((DAT_EXTMEM_09a0 < (byte)-(((DAT_EXTMEM_09a1 < 0x3c) << 7) >> 7)) << 7 < '\0') {
        DAT_EXTMEM_0965 = DAT_EXTMEM_0965 ^ DAT_EXTMEM_0f8c;
        *(byte *)CONCAT11('\a' - (((0xec < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 + 0x13) =
             DAT_EXTMEM_0f8c & 0x7f;
        if ((DAT_EXTMEM_0713 == 0x7a) && (DAT_EXTMEM_0714 == '\\')) {
          _4_1 = 0;
          _2_6 = 1;
          DAT_EXTMEM_09b1 = '\x03';
        }
        else if ((DAT_EXTMEM_0713 == 0x62) && (DAT_EXTMEM_0714 == 'm')) {
          DAT_EXTMEM_09b1 = '\a';
          DAT_EXTMEM_09a0 = 0xff;
          DAT_EXTMEM_09a1 = 0xff;
          bVar4 = LATCH0_EZ_row_color_LED_bank;
          LATCH0_EZ_row_color_LED_bank = bVar4 | 0x40;
          LATCH3_7SEG_802_15 = 0xc1;
        }
        if (*(char *)CONCAT11('\a' - (((0xec < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 + 0x13)
            == '\r') {
          DAT_EXTMEM_09b1 = '\x02';
        }
        else {
          DAT_EXTMEM_09a1 = DAT_EXTMEM_09a1 + 1;
          if (DAT_EXTMEM_09a1 == 0) {
            DAT_EXTMEM_09a0 = DAT_EXTMEM_09a0 + 1;
          }
        }
      }
      else {
        DAT_EXTMEM_09b1 = '\0';
      }
    }
    else if (DAT_EXTMEM_09b1 == '\x02') {
      if (DAT_EXTMEM_0f8c == DAT_EXTMEM_0965) {
        _0_7 = 0;
        cVar5 = (DAT_EXTMEM_0018 < 0x39) << 7;
        if ((DAT_EXTMEM_0018 == 0x39) && ((DAT_EXTMEM_06f9 >> 6 & 1) != 0)) {
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 & 0xbf;
          _1_4 = 1;
        }
        if (_2_0 != '\0') {
          _2_0 = '\0';
          _1_4 = 1;
        }
        if (_1_7 != '\0') {
          _1_7 = '\0';
          _1_4 = 1;
          _2_6 = 0;
        }
        DAT_EXTMEM_09a8 = 0;
        DAT_EXTMEM_09a9 = 0;
        LATCH3_7SEG_802_15 = 0xf9;
        bVar4 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar4 | 0x40;
        if ((DAT_EXTMEM_0713 == 0x6c) && (FUN_CODE_000e(DAT_EXTMEM_0714), cVar5 < '\0')) {
          DAT_EXTMEM_0f8d = 0;
          DAT_EXTMEM_0f8e = 1;
          while (bVar4 = DAT_EXTMEM_09a1,
                DAT_EXTMEM_0f8d <
                DAT_EXTMEM_09a0 - (((DAT_EXTMEM_0f8e < DAT_EXTMEM_09a1) << 7) >> 7)) {
            *(undefined1 *)
             CONCAT11('\x06' - (((5 < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e - 6) =
                 *(undefined1 *)
                  CONCAT11('\a' - (((0xec < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x13);
            DAT_EXTMEM_0f8e = DAT_EXTMEM_0f8e + 1;
            if (DAT_EXTMEM_0f8e == 0) {
              DAT_EXTMEM_0f8d = DAT_EXTMEM_0f8d + 1;
            }
          }
          *(undefined1 *)CONCAT11('\x06' - (((5 < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 - 6)
               = 0;
          DAT_EXTMEM_09af = bVar4 - 1;
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 1;
        }
        else if ((DAT_EXTMEM_0713 == 0x6c) && (DAT_EXTMEM_0714 == 'E')) {
          DAT_EXTMEM_0f8e = 2;
          DAT_EXTMEM_0f8d = 0;
          while (DAT_EXTMEM_0f8d <
                 DAT_EXTMEM_09a0 - (((DAT_EXTMEM_0f8e < DAT_EXTMEM_09a1) << 7) >> 7)) {
            *(undefined1 *)
             CONCAT11('\b' - (((0xcf < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x30) =
                 *(undefined1 *)
                  CONCAT11('\a' - (((0xec < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x13);
            DAT_EXTMEM_0f8e = DAT_EXTMEM_0f8e + 1;
            if (DAT_EXTMEM_0f8e == 0) {
              DAT_EXTMEM_0f8d = DAT_EXTMEM_0f8d + 1;
            }
          }
          *(undefined1 *)
           CONCAT11('\b' - (((0xcf < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 + 0x30) = 0;
          DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 | 4;
        }
        else if ((DAT_EXTMEM_0713 == 0x7a) && (FUN_CODE_000e(DAT_EXTMEM_0714), cVar5 < '\0')) {
          DAT_EXTMEM_0f8d = 0;
          DAT_EXTMEM_0f8e = 1;
          while (DAT_EXTMEM_0f8d <
                 DAT_EXTMEM_09a0 - (((DAT_EXTMEM_0f8e < DAT_EXTMEM_09a1) << 7) >> 7)) {
            *(undefined1 *)
             CONCAT11('\a' - (((0xfb < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 4) =
                 *(undefined1 *)
                  CONCAT11('\a' - (((0xec < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x13);
            DAT_EXTMEM_0f8e = DAT_EXTMEM_0f8e + 1;
            if (DAT_EXTMEM_0f8e == 0) {
              DAT_EXTMEM_0f8d = DAT_EXTMEM_0f8d + 1;
            }
          }
          *(undefined1 *)CONCAT11('\a' - (((0xfb < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 + 4)
               = 0;
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 4;
        }
        else if ((DAT_EXTMEM_0713 == 100) && (FUN_CODE_000e(DAT_EXTMEM_0714), cVar5 < '\0')) {
          DAT_EXTMEM_0f8d = 0;
          DAT_EXTMEM_0f8e = 1;
          while (DAT_EXTMEM_0f8d <
                 DAT_EXTMEM_09a0 - (((DAT_EXTMEM_0f8e < DAT_EXTMEM_09a1) << 7) >> 7)) {
            *(undefined1 *)
             CONCAT11('\x04' - (((0xb8 < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x47) =
                 *(undefined1 *)
                  CONCAT11('\a' - (((0xec < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x13);
            DAT_EXTMEM_0f8e = DAT_EXTMEM_0f8e + 1;
            if (DAT_EXTMEM_0f8e == 0) {
              DAT_EXTMEM_0f8d = DAT_EXTMEM_0f8d + 1;
            }
          }
          *(undefined1 *)
           CONCAT11('\x04' - (((0xb8 < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 + 0x47) = 0;
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 0x10;
        }
        else if ((DAT_EXTMEM_0713 == 0x77) && (FUN_CODE_000e(DAT_EXTMEM_0714), cVar5 < '\0')) {
          DAT_EXTMEM_0f8d = 0;
          DAT_EXTMEM_0f8e = 1;
          while (DAT_EXTMEM_0f8d <
                 DAT_EXTMEM_09a0 - (((DAT_EXTMEM_0f8e < DAT_EXTMEM_09a1) << 7) >> 7)) {
            *(undefined1 *)
             CONCAT11('\t' - (((0x3b < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e - 0x3c) =
                 *(undefined1 *)
                  CONCAT11('\a' - (((0xec < DAT_EXTMEM_0f8e) << 7) >> 7),DAT_EXTMEM_0f8e + 0x13);
            DAT_EXTMEM_0f8e = DAT_EXTMEM_0f8e + 1;
            if (DAT_EXTMEM_0f8e == 0) {
              DAT_EXTMEM_0f8d = DAT_EXTMEM_0f8d + 1;
            }
          }
          *(undefined1 *)
           CONCAT11('\t' - (((0x3b < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 - 0x3c) = 0;
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 0x20;
        }
        else if (((DAT_EXTMEM_0713 == 0x61) && (DAT_EXTMEM_0714 == 'T')) &&
                ((DAT_EXTMEM_0715 == '0' || (DAT_EXTMEM_09bc + '0' == BANK2_R7)))) {
          DAT_EXTMEM_0018 = DAT_EXTMEM_0716;
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 0x40;
          _4_1 = 0;
        }
        else if ((DAT_EXTMEM_0713 == 0x61) && (DAT_EXTMEM_0714 == BANK2_R7)) {
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 8;
          DAT_EXTMEM_09e4 = 7;
        }
        else if (((DAT_EXTMEM_0713 == 0x61) && (DAT_EXTMEM_0714 == 'G')) &&
                (DAT_EXTMEM_0715 == BANK2_R7)) {
          DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 | 0x40;
          _1_6 = 1;
        }
        else if (((DAT_EXTMEM_0713 == 0x61) && (DAT_EXTMEM_0714 == 'V')) &&
                ((DAT_EXTMEM_0715 == '0' || (DAT_EXTMEM_09bc + '0' == BANK2_R7)))) {
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 0x80;
        }
        else if (((DAT_EXTMEM_0713 == 0x61) && (DAT_EXTMEM_0714 == 'A')) &&
                (DAT_EXTMEM_0715 == BANK2_R7)) {
          DAT_EXTMEM_06f9 = DAT_EXTMEM_06f9 | 8;
          DAT_EXTMEM_09e4 = 7;
          DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 | 8;
        }
        else if ((((DAT_EXTMEM_0713 == 0x61) && (DAT_EXTMEM_0714 == 'Z')) &&
                 (DAT_EXTMEM_0715 == BANK2_R7)) && (DAT_EXTMEM_0716 == 0x38)) {
          _2_5 = 1;
          DAT_EXTMEM_09b4 = DAT_EXTMEM_09b4 | 1;
          _1_4 = 1;
        }
        else {
          bVar4 = LATCH0_EZ_row_color_LED_bank;
          LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
        }
      }
      else {
        _0_7 = 1;
        LATCH3_7SEG_802_15 = 0xc0;
        bVar4 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      }
      DAT_EXTMEM_09b1 = '\0';
    }
    else if (DAT_EXTMEM_09b1 == '\x03') {
      if ((DAT_EXTMEM_09a0 < 5U - (((DAT_EXTMEM_09a1 < 0x40) << 7) >> 7)) << 7 < '\0') {
        *(byte *)CONCAT11(DAT_EXTMEM_09a0 + ('\n' - (((0xef < DAT_EXTMEM_09a1) << 7) >> 7)),
                          DAT_EXTMEM_09a1 + 0x10) = DAT_EXTMEM_0f8c;
        if (bVar1 == 2 && bVar4 == 0) {
          DAT_EXTMEM_0a10 = 0x7a;
          DAT_EXTMEM_0a11 = 0x5c;
          bVar4 = LATCH0_EZ_row_color_LED_bank;
          LATCH0_EZ_row_color_LED_bank = bVar4 | 0x40;
        }
        else if (bVar1 == 9 && bVar4 == 0) {
          pbVar6 = (byte *)CONCAT11(DAT_EXTMEM_0f56 - (((0xf7 < DAT_EXTMEM_0f57) << 7) >> 7),
                                    DAT_EXTMEM_0f57 + 8);
          DAT_EXTMEM_000b = *pbVar6;
          DAT_EXTMEM_000c = pbVar6[1];
        }
        bVar2 = 1;
        bVar4 = DAT_EXTMEM_000b;
        bVar1 = DAT_EXTMEM_000c;
        bVar3 = FUN_CODE_74f5(0,0x9a0);
        bVar2 = bVar2 ^ bVar1;
        if (bVar2 == 0) {
          bVar2 = bVar3 ^ bVar4;
        }
        if (bVar2 == 0) {
          DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 | 1;
          DAT_EXTMEM_09b1 = '\x05';
          bVar4 = LATCH0_EZ_row_color_LED_bank;
          LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
        }
      }
      else {
        DAT_EXTMEM_09b1 = '\0';
        bVar4 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      }
    }
    else if (DAT_EXTMEM_09b1 == '\x05') {
      DAT_EXTMEM_0a08 = 6;
    }
    else if (DAT_EXTMEM_09b1 == '\x06') {
      *(byte *)CONCAT11(DAT_EXTMEM_000b + ('\n' - (((0xef < DAT_EXTMEM_000c) << 7) >> 7)),
                        DAT_EXTMEM_000c + 0x10) = DAT_EXTMEM_0f8c;
      DAT_EXTMEM_000c = DAT_EXTMEM_000c + 1;
      if (DAT_EXTMEM_000c == 0) {
        DAT_EXTMEM_000b = DAT_EXTMEM_000b + 1;
      }
    }
    else if (DAT_EXTMEM_09b1 == '\a') {
      if ((DAT_EXTMEM_09a0 < (byte)-(((DAT_EXTMEM_09a1 < 4) << 7) >> 7)) << 7 < '\0') {
        *(byte *)CONCAT11('\a' - (((0xec < DAT_EXTMEM_09a1) << 7) >> 7),DAT_EXTMEM_09a1 + 0x13) =
             DAT_EXTMEM_0f8c;
        if (bVar1 == 3 && bVar4 == 0) {
          LATCH6_802_15 = DAT_EXTMEM_0713;
          LATCH7 = DAT_EXTMEM_0714;
          puVar7 = &DAT_EXTMEM_0715;
          FUN_CODE_74bf(0,8,0,DAT_EXTMEM_0715);
          FUN_CODE_74bf(BANK2_R6,0,*puVar7);
          bVar1 = BANK2_R2;
          bVar2 = BANK2_R3;
          FUN_CODE_74ab(0,DAT_EXTMEM_0716);
          LATCH4_802_15 = bVar1;
          LATCH5 = bVar2;
          bVar4 = LATCH7;
          cVar5 = LATCH6_802_15;
          bVar3 = cVar5 + (-1 - (((1 < bVar4) << 7) >> 7));
          bVar2 = bVar4 - 2 ^ bVar2;
          if (bVar2 == 0) {
            bVar2 = bVar3 ^ bVar1;
          }
          if (bVar2 != 0) {
            bVar4 = DAT_EXTMEM_0017 ^ bVar4 - 2;
            if (bVar4 == 0) {
              bVar4 = bVar3 ^ DAT_EXTMEM_0016;
            }
            if (bVar4 != 0) {
              DAT_EXTMEM_09b1 = '\0';
              bVar4 = LATCH0_EZ_row_color_LED_bank;
              LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
            }
          }
        }
        DAT_EXTMEM_09a1 = DAT_EXTMEM_09a1 + 1;
        if (DAT_EXTMEM_09a1 == 0) {
          DAT_EXTMEM_09a0 = DAT_EXTMEM_09a0 + 1;
        }
      }
      else if (DAT_EXTMEM_09a0 + (-1 - (((3 < DAT_EXTMEM_09a1) << 7) >> 7)) <
               5U - (((DAT_EXTMEM_09a1 - 4 < 0x40) << 7) >> 7)) {
        *(byte *)CONCAT11(DAT_EXTMEM_09a0 + ('\n' - (((0xf3 < DAT_EXTMEM_09a1) << 7) >> 7)),
                          DAT_EXTMEM_09a1 + 0xc) = DAT_EXTMEM_0f8c;
        cVar5 = LATCH4_802_15;
        bVar2 = LATCH5;
        if (bVar4 + (-1 - (((2 < bVar1) << 7) >> 7)) <
            (byte)(cVar5 - (((bVar1 - 3 < bVar2) << 7) >> 7))) {
          DAT_EXTMEM_09a1 = DAT_EXTMEM_09a1 + 1;
          if (DAT_EXTMEM_09a1 == 0) {
            DAT_EXTMEM_09a0 = DAT_EXTMEM_09a0 + 1;
          }
        }
        else {
          DAT_EXTMEM_06f8 = DAT_EXTMEM_06f8 | 2;
          DAT_EXTMEM_09b1 = '\x05';
          LATCH3_7SEG_802_15 = 0x8c;
        }
      }
      else {
        DAT_EXTMEM_09b1 = '\0';
        bVar4 = LATCH0_EZ_row_color_LED_bank;
        LATCH0_EZ_row_color_LED_bank = bVar4 & 0xbf;
      }
    }
    else if (DAT_EXTMEM_09b1 == '\b') {
      DAT_EXTMEM_09b1 = '\0';
    }
    else if (DAT_EXTMEM_09b1 == '\0') {
      bVar4 = DAT_EXTMEM_0f8c & 0x7f;
      if (bVar4 == 0xd) {
        DAT_EXTMEM_09b1 = '\b';
      }
      else if ((0x60 < bVar4) && ((bVar4 < 0x7b) << 7 < '\0')) {
        DAT_EXTMEM_0965 = ~DAT_EXTMEM_0f8c;
        DAT_EXTMEM_09a0 = 0;
        DAT_EXTMEM_09a1 = 1;
        DAT_EXTMEM_09b1 = '\x01';
        DAT_EXTMEM_0713 = bVar4;
      }
    }
  }
  else {
    cVar5 = TI;
    if (cVar5 == '\x01') {
      TI = 0;
      if (DAT_EXTMEM_09b2 == '\x02') {
        if (DAT_EXTMEM_09ad <
            (byte)(DAT_EXTMEM_0452 - (((DAT_EXTMEM_09ae < DAT_EXTMEM_0453) << 7) >> 7))) {
          SBUF = *(undefined1 *)
                  CONCAT11(DAT_EXTMEM_09ad + ('\x01' - (((0x60 < DAT_EXTMEM_09ae) << 7) >> 7)),
                           DAT_EXTMEM_09ae + 0x9f);
          DAT_EXTMEM_09ae = DAT_EXTMEM_09ae + 1;
          if (DAT_EXTMEM_09ae == 0) {
            DAT_EXTMEM_09ad = DAT_EXTMEM_09ad + 1;
          }
        }
        else {
          DAT_EXTMEM_09b2 = '\0';
        }
      }
      else if (DAT_EXTMEM_09b2 == '\x01') {
        if (DAT_EXTMEM_09ad <
            (byte)(DAT_EXTMEM_0452 - (((DAT_EXTMEM_09ae < DAT_EXTMEM_0453) << 7) >> 7))) {
          SBUF = *(undefined1 *)
                  CONCAT11(-(((0x18 < DAT_EXTMEM_09ae) << 7) >> 7),DAT_EXTMEM_09ae - 0x19);
          DAT_EXTMEM_09ae = DAT_EXTMEM_09ae + 1;
          if (DAT_EXTMEM_09ae == 0) {
            DAT_EXTMEM_09ad = DAT_EXTMEM_09ad + 1;
          }
        }
        else {
          DAT_EXTMEM_09b2 = '\0';
        }
      }
    }
  }
  return param_1;
}



// ==== FUN_CODE_1d05 @ CODE:1d05  (674 bytes)

void FUN_CODE_1d05(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined1 *puVar4;
  
  _0_6 = 1;
  _4_1 = 0;
  _1_5 = 0;
  _1_4 = 0;
  _4_3 = 1;
  _1_3 = 0;
  _3_6 = 1;
  _4_0 = 0;
  _3_5 = 0;
  _3_7 = 0;
  _0_4 = 0;
  _2_1 = 0;
  _2_2 = 0;
  _2_7 = 0;
  _2_6 = 0;
  _1_7 = 0;
  _2_4 = 0;
  _2_3 = 0;
  _1_0 = 0;
  _5_0 = 0;
  _3_3 = 0;
  _3_1 = 0;
  _3_0 = 0;
  _4_4 = 0;
  _3_4 = 0;
  _3_2 = 0;
  _2_0 = 0;
  _1_6 = 0;
  _4_6 = 0;
  _2_5 = 0;
  _0_5 = 0;
  DAT_EXTMEM_070f = 0;
  DAT_EXTMEM_0013 = 0;
  DAT_EXTMEM_09bc = 0;
  DAT_EXTMEM_09e4 = 0;
  DAT_EXTMEM_09af = 3;
  DAT_EXTMEM_06f8 = 0;
  DAT_EXTMEM_06f9 = 0;
  DAT_EXTMEM_09b3 = 0;
  DAT_EXTMEM_09b4 = 0;
  DAT_EXTMEM_0115 = 0xff;
  DAT_EXTMEM_0116 = 0xff;
  DAT_EXTMEM_09a6 = 0xff;
  DAT_EXTMEM_09a7 = 0xff;
  DAT_EXTMEM_09a8 = 0;
  DAT_EXTMEM_09a9 = 0;
  DAT_EXTMEM_09d5 = 0xff;
  DAT_EXTMEM_09d6 = 0xff;
  bVar3 = DAT_EXTMEM_0130 ^ ~DAT_EXTMEM_0817;
  if (bVar3 == 0) {
    bVar3 = ~DAT_EXTMEM_0816 ^ DAT_EXTMEM_012f;
  }
  if (bVar3 != 0) {
    cVar2 = '\t';
    puVar4 = &DAT_EXTMEM_0705;
    do {
      *puVar4 = 0x30;
      puVar4 = puVar4 + 1;
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_EXTMEM_070e = 0;
    DAT_EXTMEM_012f = 0;
    DAT_EXTMEM_0130 = 0;
    DAT_EXTMEM_0131 = 0;
    DAT_EXTMEM_0132 = 0;
  }
  bVar3 = DAT_EXTMEM_09b7 ^ ~DAT_EXTMEM_0009;
  if (bVar3 == 0) {
    bVar3 = ~DAT_EXTMEM_0008 ^ DAT_EXTMEM_09b6;
  }
  if (bVar3 != 0) {
    cVar2 = '\t';
    puVar4 = &DAT_EXTMEM_06fb;
    do {
      *puVar4 = 0x30;
      puVar4 = puVar4 + 1;
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_EXTMEM_0704 = 0;
    DAT_EXTMEM_09b6 = 0;
    DAT_EXTMEM_09b7 = 0;
    DAT_EXTMEM_0133 = 0;
    DAT_EXTMEM_0134 = 0;
  }
  bVar3 = DAT_EXTMEM_0961 ^ ~DAT_EXTMEM_09c1;
  if (bVar3 == 0) {
    bVar3 = ~DAT_EXTMEM_09c0 ^ DAT_EXTMEM_0960;
  }
  if (bVar3 != 0) {
    cVar2 = '\t';
    puVar4 = &DAT_EXTMEM_09c5;
    do {
      *puVar4 = 0x30;
      puVar4 = puVar4 + 1;
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_EXTMEM_09ce = 0;
    DAT_EXTMEM_0960 = 0;
    DAT_EXTMEM_0961 = 0;
    DAT_EXTMEM_0137 = 0;
    DAT_EXTMEM_0138 = 0;
  }
  bVar3 = DAT_EXTMEM_09a5 ^ ~DAT_EXTMEM_09df;
  if (bVar3 == 0) {
    bVar3 = ~DAT_EXTMEM_09de ^ DAT_EXTMEM_09a4;
  }
  if (bVar3 != 0) {
    cVar2 = '\t';
    puVar4 = &DAT_EXTMEM_0832;
    do {
      *puVar4 = 0x30;
      puVar4 = puVar4 + 1;
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_EXTMEM_083b = 0;
    DAT_EXTMEM_09a4 = 0;
    DAT_EXTMEM_09a5 = 0;
    DAT_EXTMEM_0139 = 0;
    DAT_EXTMEM_013a = 0;
  }
  bVar3 = DAT_EXTMEM_06f7 ^ ~DAT_EXTMEM_0983;
  if (bVar3 == 0) {
    bVar3 = ~DAT_EXTMEM_0982 ^ DAT_EXTMEM_06f6;
  }
  if (bVar3 != 0) {
    cVar2 = '\t';
    puVar4 = &DAT_EXTMEM_0448;
    do {
      *puVar4 = 0x30;
      puVar4 = puVar4 + 1;
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_EXTMEM_0451 = 0;
    DAT_EXTMEM_06f6 = 0;
    DAT_EXTMEM_06f7 = 0;
    DAT_EXTMEM_013b = 0;
    DAT_EXTMEM_013c = 0;
  }
  T0 = 1;
  _0_7 = 0;
  DAT_EXTMEM_09b1 = 0;
  DAT_EXTMEM_09b2 = 0;
  DAT_EXTMEM_0452 = 0;
  DAT_EXTMEM_0453 = 0;
  DAT_EXTMEM_09c4 = 0;
  DAT_EXTMEM_0019 = 0;
  DAT_EXTMEM_09ad = 0;
  DAT_EXTMEM_09ae = 0;
  cVar2 = '<';
  puVar4 = &DAT_EXTMEM_0713;
  do {
    *puVar4 = 0x20;
    puVar4 = puVar4 + 1;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  cVar2 = '.';
  puVar4 = &DAT_EXTMEM_00e7;
  do {
    *puVar4 = 0x20;
    puVar4 = puVar4 + 1;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  DAT_EXTMEM_0f95 = 0;
  DAT_EXTMEM_0f96 = 0;
  while (bVar1 = DAT_EXTMEM_0f96, bVar3 = DAT_EXTMEM_0f95,
        DAT_EXTMEM_0f95 < 2U - (((DAT_EXTMEM_0f96 < 0xa0) << 7) >> 7)) {
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f95 + ('\n' - (((0xef < DAT_EXTMEM_0f96) << 7) >> 7)),
              DAT_EXTMEM_0f96 + 0x10) = 0;
    *(undefined1 *)CONCAT11(bVar3 + ('\x04' - (((0xaa < bVar1) << 7) >> 7)),bVar1 + 0x55) = 0;
    *(undefined1 *)
     CONCAT11(bVar3 + (DAT_EXTMEM_09ee - ((CARRY1(DAT_EXTMEM_09ef,bVar1) << 7) >> 7)),
              DAT_EXTMEM_09ef + bVar1) = 0;
    DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 + 1;
    if (DAT_EXTMEM_0f96 == 0) {
      DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1;
    }
  }
  DAT_EXTMEM_0f95 = 0;
  DAT_EXTMEM_0f96 = 0;
  while (DAT_EXTMEM_0f95 < 2U - (((DAT_EXTMEM_0f96 < 0xa8) << 7) >> 7)) {
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f95 + ('\x01' - (((0x60 < DAT_EXTMEM_0f96) << 7) >> 7)),
              DAT_EXTMEM_0f96 + 0x9f) = 0;
    DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 + 1;
    if (DAT_EXTMEM_0f96 == 0) {
      DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1;
    }
  }
  for (; bVar3 = DAT_EXTMEM_09ed, DAT_EXTMEM_09ed < 3; DAT_EXTMEM_09ed = DAT_EXTMEM_09ed + 1) {
    *(undefined1 *)CONCAT11('\b' - (((0xd2 < DAT_EXTMEM_09ed) << 7) >> 7),DAT_EXTMEM_09ed + 0x2d) =
         0;
    puVar4 = (undefined1 *)CONCAT11(-(((0xf2 < bVar3 * '\x02') << 7) >> 7),bVar3 * '\x02' + 0xd);
    *puVar4 = 0;
    puVar4[1] = 0;
  }
  if (DAT_EXTMEM_0f55 != ~DAT_EXTMEM_0a01) {
    DAT_EXTMEM_0f55 = 0xff;
    DAT_EXTMEM_0a01 = 0;
  }
  DAT_EXTMEM_0a08 = 0;
  return;
}



// ==== FUN_CODE_1fa7 @ CODE:1fa7  (76 bytes)

void FUN_CODE_1fa7(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  
  uVar1 = 0;
  uVar3 = DAT_EXTMEM_09b5;
  FUN_CODE_3aa0();
  DAT_EXTMEM_083e = uVar1;
  DAT_EXTMEM_083f = uVar3;
  if (DAT_EXTMEM_09bf < DAT_EXTMEM_09be) {
    uVar2 = 0;
    bVar4 = DAT_EXTMEM_09be;
    FUN_CODE_74ab(uVar1,uVar3);
    DAT_EXTMEM_0016 = uVar2;
    DAT_EXTMEM_0017 = bVar4;
    return;
  }
  uVar2 = 0;
  bVar4 = DAT_EXTMEM_09bf;
  FUN_CODE_74ab(uVar1,uVar3);
  DAT_EXTMEM_0016 = uVar2;
  DAT_EXTMEM_0017 = bVar4;
  return;
}



// ==== FUN_CODE_1ff3 @ CODE:1ff3  (1173 bytes)

byte FUN_CODE_1ff3(byte param_1,byte param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  _0_2 = '\0';
  DAT_EXTMEM_0f93 = param_1;
  DAT_EXTMEM_0f94 = param_2;
  if ((_2_6 == '\0') && (_1_7 == '\0')) {
    _0_3 = false;
    if (_0_5 == '\x01') {
      _0_5 = '\0';
    }
    else {
      _0_3 = DAT_EXTMEM_074f != '\0';
      param_1 = DAT_EXTMEM_0829;
      if ((DAT_EXTMEM_0829 - (((DAT_EXTMEM_0130 < DAT_EXTMEM_082a) << 7) >> 7) <= DAT_EXTMEM_012f)
         && (param_1 = DAT_EXTMEM_0711,
            DAT_EXTMEM_012f <
            DAT_EXTMEM_0711 - (((DAT_EXTMEM_0130 < DAT_EXTMEM_0712 + 1U) << 7) >> 7))) {
        _0_3 = !(bool)_0_3;
      }
      if (_2_4 != '\0') {
        _2_4 = '\0';
        _0_3 = _0_3 ^ 1;
      }
      if ((_2_3 == '\x01') || (_1_0 != '\0')) {
        _0_3 = _0_3 ^ 1;
      }
    }
    if ((DAT_EXTMEM_09e2 != '\0') && (DAT_EXTMEM_09e3 != '\0')) {
      _0_3 = _0_3 ^ 1;
    }
    cVar1 = P1_4;
    if (cVar1 != '\0') {
      _0_3 = _0_3 ^ 1;
    }
    if ((bool)_0_3 != false) {
      DAT_EXTMEM_0f95 = 0;
      DAT_EXTMEM_0f96 = 0;
      while (param_1 = DAT_EXTMEM_0f95,
            DAT_EXTMEM_0f95 < 2U - (((DAT_EXTMEM_0f96 < 0xa0) << 7) >> 7)) {
        pbVar4 = (byte *)CONCAT11(DAT_EXTMEM_0f95 +
                                  (DAT_EXTMEM_0f93 -
                                  ((CARRY1(DAT_EXTMEM_0f94,DAT_EXTMEM_0f96) << 7) >> 7)),
                                  DAT_EXTMEM_0f94 + DAT_EXTMEM_0f96);
        *pbVar4 = ~*pbVar4;
        DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 + 1;
        if (DAT_EXTMEM_0f96 == 0) {
          DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1;
        }
      }
    }
    if (((DAT_EXTMEM_09e2 != '\0') && (DAT_EXTMEM_09e3 == '\0')) ||
       ((DAT_EXTMEM_09e2 == '\0' && (DAT_EXTMEM_09e3 != '\0')))) {
      _0_2 = '\x01';
    }
    if ((((DAT_EXTMEM_0710 == '\0') && (DAT_EXTMEM_09bc == DAT_EXTMEM_06f5)) && (_5_0 != '\0')) &&
       (((_1_6 != '\x01' && (FUN_CODE_7cc5(5,7,1), DAT_EXTMEM_0130 == BANK0_R7)) &&
        ((((param_1 == BANK0_R4 &&
           ((FUN_CODE_7cc5(0xc5,9,1,DAT_EXTMEM_012f), DAT_EXTMEM_0961 == BANK0_R7 &&
            (param_1 == BANK0_R4)))) &&
          (FUN_CODE_7cc5(0xfb,6,1,DAT_EXTMEM_0960), DAT_EXTMEM_09b7 == BANK0_R7)) &&
         (param_1 == BANK0_R4)))))) {
      FUN_CODE_6f21(DAT_EXTMEM_09b6);
    }
    _5_0 = '\0';
    for (DAT_EXTMEM_0f97 = 0; (DAT_EXTMEM_0f97 < DAT_EXTMEM_09b5) << 7 < '\0';
        DAT_EXTMEM_0f97 = DAT_EXTMEM_0f97 + 1) {
      DAT_EXTMEM_09d3 = 0x4e;
      bVar2 = 0x20;
      DAT_EXTMEM_09d4 = 0x20;
      cVar1 = P1_6;
      if (cVar1 != '\0') {
        DAT_EXTMEM_09d3 = 0x4e;
        DAT_EXTMEM_09d4 = 0x20;
        return 0x20;
      }
      if (_1_6 != '\0') {
        bVar3 = DAT_EXTMEM_09b5;
        FUN_CODE_7cc5(5,7,1);
        bVar2 = DAT_EXTMEM_0130 ^ bVar3;
        if (bVar2 == 0) {
          bVar2 = param_1 ^ DAT_EXTMEM_012f;
        }
        if (bVar2 != 0) {
          return bVar2;
        }
        FUN_CODE_7cc5(0xfb,6,1);
        bVar3 = DAT_EXTMEM_09b7 ^ bVar3;
        if (bVar3 == 0) {
          bVar3 = param_1 ^ DAT_EXTMEM_09b6;
        }
        bVar2 = 0;
        if (bVar3 != 0) {
          return bVar3;
        }
      }
      if (_2_6 != '\0') {
        return bVar2;
      }
      if (_1_7 != '\0') {
        return bVar2;
      }
      if ((((DAT_EXTMEM_0f97 < DAT_EXTMEM_09ac) << 7) >> 7 ^ 0x80U) < 0x80) {
        DAT_EXTMEM_0f99 = DAT_EXTMEM_09be;
      }
      else {
        DAT_EXTMEM_0f99 = DAT_EXTMEM_09bf;
      }
      for (DAT_EXTMEM_0f98 = 0; (DAT_EXTMEM_0f98 < DAT_EXTMEM_0f99) << 7 < '\0';
          DAT_EXTMEM_0f98 = DAT_EXTMEM_0f98 + 1) {
        cVar1 = '\0';
        bVar2 = DAT_EXTMEM_0f98;
        FUN_CODE_74ab(DAT_EXTMEM_083e,DAT_EXTMEM_083f);
        bVar3 = (DAT_EXTMEM_0f97 >> 3) + bVar2;
        cVar1 = cVar1 - ((CARRY1(DAT_EXTMEM_0f97 >> 3,bVar2) << 7) >> 7);
        if ((_5_2 == '\0') ||
           (((*(byte *)CONCAT11(cVar1 + (DAT_EXTMEM_0f93 -
                                        ((CARRY1(DAT_EXTMEM_0f94,bVar3) << 7) >> 7)),
                                DAT_EXTMEM_0f94 + bVar3) ^
             *(byte *)CONCAT11(cVar1 + ('\x04' - (((0xaa < bVar3) << 7) >> 7)),bVar3 + 0x55)) &
            (&DAT_CODE_3a94)[DAT_EXTMEM_0f97 & 7]) != 0)) {
          _0_1 = (*(byte *)CONCAT11(cVar1 + (DAT_EXTMEM_0f93 -
                                            ((CARRY1(DAT_EXTMEM_0f94,bVar3) << 7) >> 7)),
                                    DAT_EXTMEM_0f94 + bVar3) & (&DAT_CODE_3a94)[DAT_EXTMEM_0f97 & 7]
                 ) != 0;
          if (_0_2 != '\0') {
            if (((DAT_EXTMEM_0f97 < DAT_EXTMEM_09ac) && (DAT_EXTMEM_09e2 != '\0')) &&
               (DAT_EXTMEM_09e3 == '\0')) {
              _0_1 = !(bool)_0_1;
            }
            else if (((DAT_EXTMEM_0f97 - DAT_EXTMEM_09ac < DAT_EXTMEM_09b0) &&
                     (DAT_EXTMEM_09e2 == '\0')) && (DAT_EXTMEM_09e3 != '\0')) {
              _0_1 = !(bool)_0_1;
            }
          }
          bVar2 = *(byte *)CONCAT11('\a' - (((0xae < DAT_EXTMEM_0f97) << 7) >> 7),
                                    DAT_EXTMEM_0f97 + 0x51);
          if (bVar2 == 2) {
            bVar2 = LATCH0_EZ_row_color_LED_bank;
            LATCH0_EZ_row_color_LED_bank = bVar2 & 0xe1;
            if ((bool)_0_1 == false) {
              bVar2 = LATCH0_EZ_row_color_LED_bank;
              LATCH0_EZ_row_color_LED_bank = bVar2 & 0xfe;
              bVar2 = LATCH0_EZ_row_color_LED_bank;
              LATCH0_EZ_row_color_LED_bank = bVar2 & 0xbf;
            }
            else {
              bVar2 = LATCH0_EZ_row_color_LED_bank;
              LATCH0_EZ_row_color_LED_bank = bVar2 | 1;
              bVar2 = LATCH0_EZ_row_color_LED_bank;
              LATCH0_EZ_row_color_LED_bank = bVar2 | 0x40;
            }
            LATCH1_ES_FP2800 =
                 *(undefined1 *)
                  CONCAT11(-(((0xdc < DAT_EXTMEM_0f97) << 7) >> 7),DAT_EXTMEM_0f97 + 0x23);
            if (DAT_EXTMEM_0f97 < DAT_EXTMEM_09ac) {
              bVar2 = LATCH2_module_enable;
              bVar2 = *(byte *)CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f98) << 7) >> 7),
                                        DAT_EXTMEM_0f98 + 0x66) | bVar2 & 0xe0;
              LATCH2_module_enable = bVar2;
            }
            else {
              bVar2 = (DAT_EXTMEM_0f97 - DAT_EXTMEM_09ac) - DAT_EXTMEM_09b0;
              if ((DAT_EXTMEM_0f97 - DAT_EXTMEM_09ac < DAT_EXTMEM_09b0) << 7 < '\0') {
                bVar2 = LATCH2_module_enable;
                bVar2 = *(byte *)CONCAT11('\t' - (((0x7b < DAT_EXTMEM_0f98) << 7) >> 7),
                                          DAT_EXTMEM_0f98 + 0x84) | bVar2 & 0xe0;
                LATCH2_module_enable = bVar2;
              }
            }
          }
          else {
            bVar2 = bVar2 ^ 1;
            if (bVar2 == 0) {
              if ((bool)_0_1 == false) {
                if (DAT_EXTMEM_0f97 < DAT_EXTMEM_09ac) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f98) << 7) >> 7),
                                         DAT_EXTMEM_0f98 + 0x66) | bVar2 & 0xe0 | 0x10;
                }
                else if (DAT_EXTMEM_0f97 - DAT_EXTMEM_09ac < DAT_EXTMEM_09b0) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x7b < DAT_EXTMEM_0f98) << 7) >> 7),
                                         DAT_EXTMEM_0f98 + 0x84) | bVar2 & 0xe0 | 0x10;
                }
                LATCH1_ES_FP2800 =
                     *(byte *)CONCAT11(-(((0xdc < DAT_EXTMEM_0f97) << 7) >> 7),
                                       DAT_EXTMEM_0f97 + 0x23) | 0x80;
              }
              else {
                bVar2 = LATCH0_EZ_row_color_LED_bank;
                LATCH0_EZ_row_color_LED_bank = bVar2 | 0x40;
                if (DAT_EXTMEM_0f97 < DAT_EXTMEM_09ac) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x99 < DAT_EXTMEM_0f98) << 7) >> 7),
                                         DAT_EXTMEM_0f98 + 0x66) & 0xef | bVar2 & 0xe0;
                }
                else if (DAT_EXTMEM_0f97 - DAT_EXTMEM_09ac < DAT_EXTMEM_09b0) {
                  bVar2 = LATCH0_EZ_row_color_LED_bank;
                  LATCH0_EZ_row_color_LED_bank =
                       *(byte *)CONCAT11('\t' - (((0x7b < DAT_EXTMEM_0f98) << 7) >> 7),
                                         DAT_EXTMEM_0f98 + 0x84) & 0xef | bVar2 & 0xe0;
                }
                LATCH1_ES_FP2800 =
                     *(byte *)CONCAT11(-(((0xdc < DAT_EXTMEM_0f97) << 7) >> 7),
                                       DAT_EXTMEM_0f97 + 0x23) & 0x7f;
              }
              if (*(char *)CONCAT11(-(((0xdc < DAT_EXTMEM_0f97) << 7) >> 7),DAT_EXTMEM_0f97 + 0x23)
                  < '\0') {
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
          T0 = 0;
          if (_4_7 == '\0') {
            FUN_CODE_7296(bVar2,0x19);
          }
          else {
            FUN_CODE_729f(0x2b);
          }
          bVar2 = LATCH0_EZ_row_color_LED_bank;
          LATCH0_EZ_row_color_LED_bank = bVar2 & 0xbf;
          T0 = 1;
        }
      }
      param_1 = DAT_EXTMEM_0f98;
    }
    _1_3 = 1;
    if (_4_1 != '\0') {
      DAT_EXTMEM_09d5 = 0;
      DAT_EXTMEM_09d6 = 0;
    }
    DAT_EXTMEM_0f95 = 0;
    DAT_EXTMEM_0f96 = 0;
    while (bVar2 = DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f96 < DAT_EXTMEM_0017) << 7) >> 7),
          param_2 = DAT_EXTMEM_0f95 - bVar2, DAT_EXTMEM_0f95 < bVar2) {
      *(undefined1 *)
       CONCAT11(DAT_EXTMEM_0f95 + ('\x04' - (((0xaa < DAT_EXTMEM_0f96) << 7) >> 7)),
                DAT_EXTMEM_0f96 + 0x55) =
           *(undefined1 *)
            CONCAT11(DAT_EXTMEM_0f95 +
                     (DAT_EXTMEM_0f93 - ((CARRY1(DAT_EXTMEM_0f94,DAT_EXTMEM_0f96) << 7) >> 7)),
                     DAT_EXTMEM_0f94 + DAT_EXTMEM_0f96);
      DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 + 1;
      if (DAT_EXTMEM_0f96 == 0) {
        DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1;
      }
    }
  }
  return param_2;
}



// ==== FUN_CODE_2488 @ CODE:2488  (70 bytes)

void FUN_CODE_2488(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  
  if (_5_1 == '\0') {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xff;
  }
  bVar3 = 0;
  bVar2 = 0;
  while (bVar1 = DAT_EXTMEM_0016 - (((bVar3 < DAT_EXTMEM_0017) << 7) >> 7), bVar2 < bVar1) {
    *(undefined1 *)CONCAT11(bVar2 + ('\n' - (((0xef < bVar3) << 7) >> 7)),bVar3 + 0x10) = uVar4;
    *(undefined1 *)CONCAT11(bVar2 + ('\x01' - (((0x5b < bVar3) << 7) >> 7)),bVar3 + 0xa4) = uVar4;
    bVar3 = bVar3 + 1;
    if (bVar3 == 0) {
      bVar2 = bVar2 + 1;
    }
  }
  _0_5 = 1;
  _5_2 = 0;
  FUN_CODE_1ff3(bVar2 - bVar1,10,0x10);
  return;
}



// ==== FUN_CODE_24ce @ CODE:24ce  (776 bytes)

void FUN_CODE_24ce(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined1 *puVar6;
  
  LATCH3_7SEG_802_15 = 0x80;
  FUN_CODE_6ecb(DAT_EXTMEM_081b);
  DAT_EXTMEM_09aa = DAT_EXTMEM_081c;
  DAT_EXTMEM_09ab = DAT_EXTMEM_081d;
  bVar4 = ~DAT_EXTMEM_081d;
  if (bVar4 == 0) {
    bVar4 = ~DAT_EXTMEM_081c;
  }
  if (bVar4 != 0) {
    DAT_EXTMEM_0015 = DAT_EXTMEM_081d + 0x20;
    DAT_EXTMEM_0014 = DAT_EXTMEM_081c - (((0xdf < DAT_EXTMEM_081d) << 7) >> 7);
    DAT_EXTMEM_0710 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x79 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d + 0xa6);
    DAT_EXTMEM_0117 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x78 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d + 0xa7);
    DAT_EXTMEM_0964 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x77 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d + 0xa8);
    DAT_EXTMEM_06fa =
         *(byte *)CONCAT11(DAT_EXTMEM_0014 - (((0x76 < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d + 0xa9);
    sVar1 = (ushort)DAT_EXTMEM_06fa * 200;
    DAT_EXTMEM_06f5 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x75 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d + 0xaa);
    DAT_EXTMEM_081e =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x74 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d + 0xab);
    DAT_EXTMEM_09b8 =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x4f < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x30);
    DAT_EXTMEM_09ba =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x4e < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x2f);
    DAT_EXTMEM_0815 =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x4d < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x2e);
    DAT_EXTMEM_0819 =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x4c < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x2d);
    DAT_EXTMEM_09e2 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x49 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d - 0x2a);
    DAT_EXTMEM_09b9 =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x44 < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x25);
    DAT_EXTMEM_09bb =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x43 < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x24);
    DAT_EXTMEM_0818 =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x42 < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x23);
    DAT_EXTMEM_081a =
         *(char *)CONCAT11(DAT_EXTMEM_0014 - (((0x41 < DAT_EXTMEM_0015) << 7) >> 7),
                           DAT_EXTMEM_081d - 0x22);
    DAT_EXTMEM_09e3 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x3e < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d - 0x1f);
    DAT_EXTMEM_09ac = DAT_EXTMEM_0815 * DAT_EXTMEM_09b8;
    DAT_EXTMEM_09b0 = DAT_EXTMEM_0818 * DAT_EXTMEM_09b9;
    DAT_EXTMEM_09b5 = DAT_EXTMEM_09b0 + DAT_EXTMEM_09ac;
    DAT_EXTMEM_09be = DAT_EXTMEM_0819 * DAT_EXTMEM_09ba;
    DAT_EXTMEM_09bf = DAT_EXTMEM_081a * DAT_EXTMEM_09bb;
    DAT_EXTMEM_074f =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x3d < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d - 0x1e);
    puVar6 = (undefined1 *)
             CONCAT11(DAT_EXTMEM_0014 - (((0x3b < DAT_EXTMEM_0015) << 7) >> 7),
                      DAT_EXTMEM_081d - 0x1c);
    DAT_EXTMEM_0829 = *puVar6;
    DAT_EXTMEM_082a = puVar6[1];
    puVar6 = (undefined1 *)
             CONCAT11(DAT_EXTMEM_0014 - (((0x39 < DAT_EXTMEM_0015) << 7) >> 7),
                      DAT_EXTMEM_081d - 0x1a);
    DAT_EXTMEM_0711 = *puVar6;
    DAT_EXTMEM_0712 = puVar6[1];
    DAT_EXTMEM_0447 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x3c < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d - 0x1d);
    DAT_EXTMEM_000a =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 - (((0x37 < DAT_EXTMEM_0015) << 7) >> 7),DAT_EXTMEM_081d - 0x18);
    bVar4 = 0;
    DAT_EXTMEM_09aa = DAT_EXTMEM_0014;
    DAT_EXTMEM_09ab = DAT_EXTMEM_0015;
    do {
      DAT_EXTMEM_0830 = (undefined1)((ushort)sVar1 >> 8);
      DAT_EXTMEM_0831 = (undefined1)sVar1;
      *(undefined1 *)CONCAT11('\x01' - (((0xd5 < bVar4) << 7) >> 7),bVar4 + 0x2a) =
           *(undefined1 *)
            CONCAT11((DAT_EXTMEM_0014 - (((0x36 < DAT_EXTMEM_0015) << 7) >> 7)) -
                     ((CARRY1(DAT_EXTMEM_0015 - 0x37,bVar4) << 7) >> 7),
                     (DAT_EXTMEM_0015 - 0x37) + bVar4);
      sVar1 = CONCAT11(DAT_EXTMEM_0830,DAT_EXTMEM_0831);
      bVar4 = bVar4 + 1;
    } while (bVar4 != 5);
    bVar4 = 0;
    do {
      *(undefined1 *)CONCAT11('\t' - (((0x28 < bVar4) << 7) >> 7),bVar4 - 0x29) =
           *(undefined1 *)
            CONCAT11((DAT_EXTMEM_0014 - (((0x31 < DAT_EXTMEM_0015) << 7) >> 7)) -
                     ((CARRY1(DAT_EXTMEM_0015 - 0x32,bVar4) << 7) >> 7),
                     (DAT_EXTMEM_0015 - 0x32) + bVar4);
      bVar4 = bVar4 + 1;
    } while (bVar4 != 5);
    bVar4 = 0;
    do {
      bVar3 = DAT_EXTMEM_0015;
      bVar2 = DAT_EXTMEM_0014;
      *(undefined1 *)CONCAT11(-(((0xdc < bVar4) << 7) >> 7),bVar4 + 0x23) =
           *(undefined1 *)
            CONCAT11((DAT_EXTMEM_0014 - (((0x27 < DAT_EXTMEM_0015) << 7) >> 7)) -
                     ((CARRY1(DAT_EXTMEM_0015 - 0x28,bVar4) << 7) >> 7),
                     (DAT_EXTMEM_0015 - 0x28) + bVar4);
      bVar5 = bVar3 + 0x9c;
      *(undefined1 *)CONCAT11('\a' - (((0xae < bVar4) << 7) >> 7),bVar4 + 0x51) =
           *(undefined1 *)
            CONCAT11((bVar2 + ('\x01' - (((99 < bVar3) << 7) >> 7))) -
                     ((CARRY1(bVar5,bVar4) << 7) >> 7),bVar5 + bVar4);
      bVar4 = bVar4 + 1;
    } while (bVar4 != 0xc4);
    bVar4 = 0;
    do {
      bVar3 = DAT_EXTMEM_0015;
      bVar2 = DAT_EXTMEM_0014;
      *(undefined1 *)CONCAT11('\t' - (((0x99 < bVar4) << 7) >> 7),bVar4 + 0x66) =
           *(undefined1 *)
            CONCAT11((DAT_EXTMEM_0014 + ('\x02' - (((0x9f < DAT_EXTMEM_0015) << 7) >> 7))) -
                     ((CARRY1(DAT_EXTMEM_0015 + 0x60,bVar4) << 7) >> 7),
                     DAT_EXTMEM_0015 + 0x60 + bVar4);
      bVar5 = bVar3 + 0x7c;
      *(undefined1 *)CONCAT11('\t' - (((0x7b < bVar4) << 7) >> 7),bVar4 + 0x84) =
           *(undefined1 *)
            CONCAT11((bVar2 + ('\x02' - (((0x83 < bVar3) << 7) >> 7))) -
                     ((CARRY1(bVar5,bVar4) << 7) >> 7),bVar5 + bVar4);
      bVar4 = bVar4 + 1;
    } while (bVar4 != 0x1c);
    DAT_EXTMEM_09bd =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0014 + ('\x02' - (((0x2a < DAT_EXTMEM_0015) << 7) >> 7)),
                   DAT_EXTMEM_0015 - 0x2b);
  }
  return;
}



// ==== FUN_CODE_27d6 @ CODE:27d6  (1048 bytes)

void FUN_CODE_27d6(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  byte *pbVar8;
  char *pcVar9;
  char *pcVar10;
  undefined1 *puVar11;
  undefined2 uVar12;
  
  LATCH3_7SEG_802_15 = 0x88;
  for (DAT_EXTMEM_0faf = 0; DAT_EXTMEM_0faf < 0x20; DAT_EXTMEM_0faf = DAT_EXTMEM_0faf + 1) {
    *(undefined1 *)(DAT_EXTMEM_0faf + 0x3c) = 0xff;
  }
  DAT_INTMEM_2f = '\0';
  DAT_EXTMEM_0fc3 = 0;
  while (DAT_EXTMEM_0fc3 < 0x20) {
    FUN_CODE_6ecb(*(undefined1 *)
                   CONCAT11('\x01' - (((0xc0 < DAT_EXTMEM_0fc3 * '\x03') << 7) >> 7),
                            DAT_EXTMEM_0fc3 * '\x03' + 0x3f));
    pbVar8 = (byte *)CONCAT11('\x01' - (((0xbf < DAT_EXTMEM_0fc3 * '\x03') << 7) >> 7),
                              DAT_EXTMEM_0fc3 * '\x03' + 0x40);
    bVar3 = *pbVar8;
    bVar5 = pbVar8[1];
    bVar2 = ~bVar5;
    if (bVar2 == 0) {
      bVar2 = ~bVar3;
    }
    if (bVar2 == 0) break;
    DAT_EXTMEM_0fb4 = bVar5 + 0x20;
    DAT_EXTMEM_0fb3 = bVar3 - (((0xdf < bVar5) << 7) >> 7);
    DAT_EXTMEM_0fb0 = bVar3;
    DAT_EXTMEM_0fb1 = bVar5;
    FUN_CODE_7804(0xb5,DAT_EXTMEM_0fb4,BANK0_R6,1,0xf,BANK0_R3,DAT_EXTMEM_0fb3);
    DAT_EXTMEM_0fc2 =
         *(char *)CONCAT11(DAT_EXTMEM_0fb3 - (((0xf2 < DAT_EXTMEM_0fb4) << 7) >> 7),
                           DAT_EXTMEM_0fb4 + 0xd);
    DAT_EXTMEM_0fb2 = DAT_EXTMEM_0f8a;
    FUN_CODE_6ecb(DAT_EXTMEM_081b);
    DAT_EXTMEM_0fb0 = DAT_EXTMEM_081c;
    DAT_EXTMEM_0fb1 = DAT_EXTMEM_081d;
    DAT_EXTMEM_0fc5 = DAT_EXTMEM_081d + 3;
    DAT_EXTMEM_0fc4 =
         (DAT_EXTMEM_081c - (((0xdf < DAT_EXTMEM_081d) << 7) >> 7)) +
         ('\x02' - (((0x1c < DAT_EXTMEM_081d + 0x20) << 7) >> 7));
    DAT_EXTMEM_0fae = 0;
    do {
      FUN_CODE_6ecb(DAT_EXTMEM_081b);
      bVar3 = (byte)((ushort)DAT_EXTMEM_0fae * 0x10);
      FUN_CODE_7804(0xc6,BANK0_R7,
                    DAT_EXTMEM_0fc4 +
                    ((char)((ushort)DAT_EXTMEM_0fae * 0x10 >> 8) -
                    ((CARRY1(DAT_EXTMEM_0fc5,bVar3) << 7) >> 7)),1,0xf,BANK0_R3,
                    DAT_EXTMEM_0fc5 + bVar3);
      bVar3 = DAT_EXTMEM_0fae;
      cVar4 = DAT_EXTMEM_0fc4;
      bVar5 = DAT_EXTMEM_0fc5;
      bVar2 = DAT_EXTMEM_0fc5;
      cVar7 = DAT_EXTMEM_0fc4;
      FUN_CODE_7587(0x10,DAT_EXTMEM_0fae);
      DAT_EXTMEM_0fd3 = *(char *)CONCAT11(cVar7 - (((0xf2 < bVar2) << 7) >> 7),bVar2 + 0xd);
      FUN_CODE_7587(bVar3,0x10);
      pcVar9 = (char *)CONCAT11(cVar4 - (((0xf1 < bVar5) << 7) >> 7),bVar5 + 0xe);
      DAT_EXTMEM_0fd4 = *pcVar9;
      DAT_EXTMEM_0fd5 = pcVar9[1];
      cVar4 = DAT_EXTMEM_0fb2;
      FUN_CODE_6ecb();
      FUN_CODE_771b(0xb5,0xc6,0xf,1,0xf,1);
      bVar5 = DAT_EXTMEM_0fb4;
      bVar3 = DAT_EXTMEM_0fae;
      if ((cVar4 == '\0') && (DAT_EXTMEM_0fc2 == DAT_EXTMEM_0fd3)) {
        DAT_EXTMEM_0fb0 = DAT_EXTMEM_0fb3;
        DAT_EXTMEM_0fb1 = DAT_EXTMEM_0fb4;
        bVar2 = (byte)((ushort)DAT_EXTMEM_0fae * 9);
        pbVar8 = (byte *)CONCAT11((char)((ushort)DAT_EXTMEM_0fae * 9 >> 8) +
                                  ('\b' - (((0xbf < bVar2) << 7) >> 7)),bVar2 + 0x40);
        *pbVar8 = DAT_EXTMEM_0fb3;
        pbVar8[1] = bVar5;
        cVar4 = DAT_EXTMEM_0fb1 + 0x26;
        bVar5 = (byte)((ushort)bVar3 * 9);
        pcVar9 = (char *)CONCAT11((char)((ushort)bVar3 * 9 >> 8) +
                                  ('\b' - (((0xbd < bVar5) << 7) >> 7)),bVar5 + 0x42);
        *pcVar9 = DAT_EXTMEM_0fb0 - (((0xd9 < DAT_EXTMEM_0fb1) << 7) >> 7);
        pcVar9[1] = cVar4;
        bVar5 = (byte)((ushort)bVar3 * 9);
        pcVar9 = (char *)CONCAT11((char)((ushort)bVar3 * 9 >> 8) +
                                  ('\b' - (((0xbf < bVar5) << 7) >> 7)),bVar5 + 0x40);
        bVar5 = pcVar9[1];
        sVar1 = (ushort)*(byte *)CONCAT11(*pcVar9 - (((0xee < bVar5) << 7) >> 7),bVar5 + 0x11) * 3;
        bVar5 = (byte)sVar1;
        bVar2 = bVar5 + 0x26;
        cVar4 = DAT_EXTMEM_0fb1 + bVar2;
        bVar6 = (byte)((ushort)bVar3 * 9);
        pcVar9 = (char *)CONCAT11((char)((ushort)bVar3 * 9 >> 8) +
                                  ('\b' - (((0xbb < bVar6) << 7) >> 7)),bVar6 + 0x44);
        *pcVar9 = DAT_EXTMEM_0fb0 +
                  (((char)((ushort)sVar1 >> 8) - (((0xd9 < bVar5) << 7) >> 7)) -
                  ((CARRY1(DAT_EXTMEM_0fb1,bVar2) << 7) >> 7));
        pcVar9[1] = cVar4;
        bVar5 = (byte)((ushort)bVar3 * 9);
        pcVar9 = (char *)CONCAT11((char)((ushort)bVar3 * 9 >> 8) +
                                  ('\b' - (((0xbf < bVar5) << 7) >> 7)),bVar5 + 0x40);
        bVar5 = pcVar9[1];
        pcVar9 = (char *)CONCAT11(*pcVar9 - (((0xe1 < bVar5) << 7) >> 7),bVar5 + 0x1e);
        bVar5 = pcVar9[1];
        cVar4 = DAT_EXTMEM_0fb1 + bVar5;
        bVar2 = (byte)((ushort)bVar3 * 9);
        pcVar10 = (char *)CONCAT11((char)((ushort)bVar3 * 9 >> 8) +
                                   ('\b' - (((0xb9 < bVar2) << 7) >> 7)),bVar2 + 0x46);
        *pcVar10 = DAT_EXTMEM_0fb0 + (*pcVar9 - ((CARRY1(DAT_EXTMEM_0fb1,bVar5) << 7) >> 7));
        pcVar10[1] = cVar4;
        bVar5 = (byte)((ushort)bVar3 * 9);
        *(char *)CONCAT11((char)((ushort)bVar3 * 9 >> 8) + ('\b' - (((0xb7 < bVar5) << 7) >> 7)),
                          bVar5 + 0x48) = DAT_EXTMEM_0fb2;
        if (((DAT_EXTMEM_0964 == '\x01') || (DAT_EXTMEM_0964 == '\x02')) &&
           (DAT_EXTMEM_0fae == BANK0_R7)) {
          DAT_EXTMEM_0454 =
               *(undefined1 *)
                CONCAT11(DAT_EXTMEM_0fb3 - (((0xed < DAT_EXTMEM_0fb4) << 7) >> 7),
                         DAT_EXTMEM_0fb4 + 0x12);
        }
        if (*(char *)(DAT_EXTMEM_0fae + 0x3c) == -1) {
          *(undefined1 *)(DAT_EXTMEM_0fae + 0x3c) = BANK0_R6;
        }
        else {
          DAT_INTMEM_2f = '\x01';
        }
        break;
      }
      DAT_EXTMEM_0fae = DAT_EXTMEM_0fae + 1;
    } while (DAT_EXTMEM_0fae < 0x20);
    cVar4 = DAT_EXTMEM_0962;
    if (DAT_EXTMEM_0962 == '\0') {
      cVar4 = DAT_EXTMEM_0963;
    }
    if (((cVar4 == '\0') || (DAT_EXTMEM_0750 != '\x02')) || (_1_1 != '\0')) {
LAB_CODE_2bde:
      DAT_EXTMEM_0fc3 = DAT_EXTMEM_0fc3 + 1;
    }
    else {
      bVar3 = ~DAT_EXTMEM_081d;
      if (bVar3 == 0) {
        bVar3 = ~DAT_EXTMEM_081c;
      }
      if (bVar3 == 0) goto LAB_CODE_2bde;
      if (DAT_EXTMEM_0fae != 0x20) {
        cVar4 = DAT_EXTMEM_0fd4;
        if (DAT_EXTMEM_0fd4 == '\0') {
          cVar4 = DAT_EXTMEM_0fd5;
        }
        if (((cVar4 != '\0') || (DAT_EXTMEM_000a == BANK0_R7)) && (DAT_INTMEM_2f != '\x01'))
        goto LAB_CODE_2bde;
      }
      if (DAT_INTMEM_2f == '\0') {
        LATCH3_7SEG_802_15 = 0x83;
        FUN_CODE_6ecb(*(undefined1 *)
                       CONCAT11('\x01' - (((0xc0 < DAT_EXTMEM_0fc3 * '\x03') << 7) >> 7),
                                DAT_EXTMEM_0fc3 * '\x03' + 0x3f));
        puVar11 = (undefined1 *)
                  CONCAT11('\x01' - (((0xbf < DAT_EXTMEM_0fc3 * '\x03') << 7) >> 7),
                           DAT_EXTMEM_0fc3 * '\x03' + 0x40);
        FUN_CODE_6916(*puVar11,puVar11[1]);
      }
      else if (DAT_INTMEM_2f == '\x01') {
        LATCH3_7SEG_802_15 = 0xf8;
        cVar4 = *(char *)(DAT_EXTMEM_0fae + 0x3c) >> 7;
        uVar12 = 0x13f;
        FUN_CODE_7587(*(char *)(DAT_EXTMEM_0fae + 0x3c),3);
        FUN_CODE_6ecb(*(undefined1 *)
                       CONCAT11(cVar4 * '\x03' + (char)((ushort)uVar12 >> 8),(char)uVar12));
        cVar4 = *(char *)(DAT_EXTMEM_0fae + 0x3c) >> 7;
        uVar12 = 0x140;
        FUN_CODE_7587(*(char *)(DAT_EXTMEM_0fae + 0x3c),3);
        puVar11 = (undefined1 *)CONCAT11(cVar4 * '\x03' + (char)((ushort)uVar12 >> 8),(char)uVar12);
        FUN_CODE_6916(*puVar11,puVar11[1]);
        DAT_INTMEM_2f = '\0';
      }
      DAT_EXTMEM_09d3 = 0x4e;
      DAT_EXTMEM_09d4 = 0x20;
      FUN_CODE_2d2c();
      DAT_EXTMEM_09d3 = 0x4e;
      DAT_EXTMEM_09d4 = 0x20;
      FUN_CODE_24ce();
      DAT_EXTMEM_09d3 = 0x4e;
      DAT_EXTMEM_09d4 = 0x20;
      FUN_CODE_1fa7();
      DAT_EXTMEM_09d3 = 0x4e;
      DAT_EXTMEM_09d4 = 0x20;
      for (DAT_EXTMEM_0faf = 0; DAT_EXTMEM_0faf < 0x20; DAT_EXTMEM_0faf = DAT_EXTMEM_0faf + 1) {
        *(undefined1 *)(DAT_EXTMEM_0faf + 0x3c) = 0xff;
      }
      DAT_EXTMEM_0fc3 = 0;
    }
  }
  LATCH3_7SEG_802_15 = 0xc6;
  return;
}



// ==== FUN_CODE_2bee @ CODE:2bee  (61 bytes)

byte FUN_CODE_2bee(byte param_1,byte param_2)

{
  byte bVar1;
  
  FUN_CODE_2c2b();
  bVar1 = ~param_2;
  if (bVar1 == 0) {
    bVar1 = ~param_1;
  }
  if (bVar1 == 0) {
    return 0;
  }
  DAT_EXTMEM_0fe3 = param_1;
  DAT_EXTMEM_0fe4 = param_2;
  check_FORM_header(BANK0_R6,BANK0_R7);
  if (param_2 == 1) {
    LATCH3_7SEG_802_15 = 0xa4;
    return DAT_EXTMEM_0fe4;
  }
  LATCH3_7SEG_802_15 = 0xb0;
  return 0xb0;
}



// ==== FUN_CODE_2c2b @ CODE:2c2b  (100 bytes)

char FUN_CODE_2c2b(void)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  
  bVar1 = ((byte *)CONCAT11(BANK0_R6,BANK0_R7))[1] ^ 0x4f;
  if (bVar1 == 0) {
    bVar1 = *(byte *)CONCAT11(BANK0_R6,BANK0_R7) ^ 0x46;
  }
  if (bVar1 != 0) {
    DAT_EXTMEM_09d3 = 0x4e;
    DAT_EXTMEM_09d4 = 0x20;
    return ' ';
  }
  bVar1 = 0xff - (((BANK0_R7 != 0xff) << 7) >> 7);
  if ((bVar1 <= BANK0_R6) ||
     (bVar1 = DAT_EXTMEM_083c - (((BANK0_R7 < DAT_EXTMEM_083d) << 7) >> 7), BANK0_R6 < bVar1)) {
    return BANK0_R6 - bVar1;
  }
  pcVar3 = (char *)CONCAT11(BANK0_R6 - (((0xfd < BANK0_R7) << 7) >> 7),BANK0_R7 + 2);
  cVar2 = pcVar3[1];
  if ((*pcVar3 == 'R') && (cVar2 == 'M')) {
    return cVar2;
  }
  return cVar2;
}



// ==== FUN_CODE_2c8f @ CODE:2c8f  (90 bytes)

char FUN_CODE_2c8f(byte param_1,byte param_2)

{
  bool bVar1;
  
  DAT_EXTMEM_0f93 = param_1;
  DAT_EXTMEM_0f94 = param_2;
  while (param_1 < (DAT_EXTMEM_083e +
                   (DAT_EXTMEM_0f93 - ((CARRY1(DAT_EXTMEM_083f,DAT_EXTMEM_0f94) << 7) >> 7))) -
                   (((param_2 < DAT_EXTMEM_083f + DAT_EXTMEM_0f94) << 7) >> 7)) {
    *(undefined1 *)CONCAT11(param_1 + ('\n' - (((0xef < param_2) << 7) >> 7)),param_2 + 0x10) =
         BANK0_R7;
    param_2 = param_2 + 1;
    if (param_2 == 0) {
      param_1 = param_1 + 1;
    }
  }
  bVar1 = CARRY1(DAT_EXTMEM_0f94,DAT_EXTMEM_083f);
  DAT_EXTMEM_0f94 = DAT_EXTMEM_0f94 + DAT_EXTMEM_083f;
  DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + (DAT_EXTMEM_083e - ((bVar1 << 7) >> 7));
  return DAT_EXTMEM_0f94;
}



// ==== FUN_CODE_2ce9 @ CODE:2ce9  (67 bytes)

char FUN_CODE_2ce9(byte param_1)

{
  char cVar1;
  byte *pbVar2;
  
  DAT_INTMEM_31 = 0xff;
  for (DAT_INTMEM_30 = 0; DAT_INTMEM_30 < param_1; DAT_INTMEM_30 = DAT_INTMEM_30 + 1) {
    pbVar2 = (byte *)CONCAT11(-(((0x18 < DAT_INTMEM_30) << 7) >> 7),DAT_INTMEM_30 - 0x19);
    *pbVar2 = *pbVar2 & 0x7f;
    pbVar2 = (byte *)CONCAT11(-(((0x18 < DAT_INTMEM_30) << 7) >> 7),DAT_INTMEM_30 - 0x19);
    cVar1 = P;
    if (cVar1 != '\0') {
      *pbVar2 = *pbVar2 ^ 0x80;
    }
    DAT_INTMEM_31 =
         DAT_INTMEM_31 ^
         *(byte *)CONCAT11(-(((0x18 < DAT_INTMEM_30) << 7) >> 7),DAT_INTMEM_30 - 0x19);
  }
  return DAT_INTMEM_30 - param_1;
}



// ==== FUN_CODE_2d2c @ CODE:2d2c  (2269 bytes)

char FUN_CODE_2d2c(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  undefined1 *puVar8;
  undefined2 uVar9;
  char *pcVar10;
  byte *pbVar11;
  
  DAT_EXTMEM_0fda = 0;
  _5_2 = '\0';
  _1_2 = '\0';
  _1_1 = 0;
  DAT_EXTMEM_081c = 0xff;
  DAT_EXTMEM_081d = 0xff;
  DAT_EXTMEM_081b = 0;
  for (DAT_EXTMEM_0fd6 = 0; ((DAT_EXTMEM_0fd6 ^ 0x80) < 0x83) << 7 < '\0';
      DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1) {
    cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
    uVar9 = 0x119;
    bVar6 = DAT_EXTMEM_0fd6;
    FUN_CODE_7587(DAT_EXTMEM_0fd6,3);
    puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
    *puVar8 = 0xff;
    puVar8[1] = 0xff;
    uVar9 = 0x118;
    FUN_CODE_7587(bVar6,3);
    *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
    uVar9 = 0x122;
    FUN_CODE_7587(bVar6,3);
    puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
    *puVar8 = 0xff;
    puVar8[1] = 0xff;
    uVar9 = 0x121;
    FUN_CODE_7587(bVar6,3);
    *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
    uVar9 = 0x1b;
    FUN_CODE_7587(bVar6,3);
    puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
    *puVar8 = 0xff;
    puVar8[1] = 0xff;
    uVar9 = 0x1a;
    FUN_CODE_7587(bVar6,3);
    *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
  }
  for (DAT_EXTMEM_0fd6 = 0; (DAT_EXTMEM_0fd6 ^ 0x80) < 0xa0; DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1)
  {
    cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
    uVar9 = 0x140;
    bVar6 = DAT_EXTMEM_0fd6;
    FUN_CODE_7587(DAT_EXTMEM_0fd6,3);
    puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
    *puVar8 = 0xff;
    puVar8[1] = 0xff;
    uVar9 = 0x13f;
    FUN_CODE_7587(bVar6,3);
    *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
  }
  if ((DAT_EXTMEM_083d == 0) && (DAT_EXTMEM_083c == 0x80)) {
    DAT_EXTMEM_0fd7 = 2;
  }
  else if ((BANK0_R7 == '\0') && (DAT_EXTMEM_083c == 0x10)) {
    DAT_EXTMEM_0fd7 = 4;
  }
  else {
    DAT_EXTMEM_0fd7 = 0;
  }
  LATCH3_7SEG_802_15 = 0x99;
  DAT_EXTMEM_0fd6 = 0;
  do {
    if ((DAT_EXTMEM_0fd7 ^ 0x80) <= (DAT_EXTMEM_0fd6 ^ 0x80)) {
      cVar7 = DAT_EXTMEM_0fda - 0x20;
      if (DAT_EXTMEM_0fda < 0x20) {
        puVar8 = (undefined1 *)
                 CONCAT11('\x01' - (((0xbf < DAT_EXTMEM_0fda * '\x03') << 7) >> 7),
                          DAT_EXTMEM_0fda * '\x03' + 0x40);
        cVar7 = -1;
        *puVar8 = 0xff;
        puVar8[1] = 0xff;
      }
      if (_1_2 == '\0') {
        DAT_EXTMEM_0710 = 1;
        DAT_EXTMEM_0117 = 3;
        DAT_EXTMEM_0964 = 0;
        DAT_EXTMEM_06fa = 0x14;
        DAT_EXTMEM_0830 = 0xf;
        DAT_EXTMEM_0831 = 0xa0;
        DAT_EXTMEM_06f5 = 0;
        DAT_EXTMEM_081e = 0;
        DAT_EXTMEM_09b8 = 0;
        DAT_EXTMEM_09ba = 0;
        DAT_EXTMEM_0815 = 0;
        DAT_EXTMEM_0819 = 0;
        DAT_EXTMEM_09e2 = 0;
        DAT_EXTMEM_09b9 = 0x1c;
        DAT_EXTMEM_09bb = 0x13;
        DAT_EXTMEM_0818 = 1;
        DAT_EXTMEM_081a = 1;
        DAT_EXTMEM_09e3 = 0;
        DAT_EXTMEM_09ac = 0;
        DAT_EXTMEM_09b0 = 0x1c;
        DAT_EXTMEM_09b5 = 0x1c;
        DAT_EXTMEM_09be = 0;
        DAT_EXTMEM_09bf = 0x13;
        DAT_EXTMEM_074f = 0;
        DAT_EXTMEM_0829 = 0xff;
        DAT_EXTMEM_082a = 0xff;
        DAT_EXTMEM_0711 = 0xff;
        DAT_EXTMEM_0712 = 0xff;
        DAT_EXTMEM_0447 = 1;
        DAT_EXTMEM_000a = 1;
        DAT_EXTMEM_012a = 3;
        DAT_EXTMEM_012b = 2;
        DAT_EXTMEM_012c = 0;
        DAT_EXTMEM_012d = 0;
        DAT_EXTMEM_09d7 = 2;
        DAT_EXTMEM_09d8 = 2;
        DAT_EXTMEM_09d9 = 1;
        DAT_EXTMEM_09da = 1;
        for (DAT_EXTMEM_0fd6 = 0; bVar6 = DAT_EXTMEM_0fd6, (DAT_EXTMEM_0fd6 ^ 0x80) < 0xf0;
            DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1) {
          cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
          *(undefined1 *)
           CONCAT11(cVar7 + ('\a' - (((0xae < DAT_EXTMEM_0fd6) << 7) >> 7)),DAT_EXTMEM_0fd6 + 0x51)
               = *(undefined1 *)
                  CONCAT11(cVar7 + (':' - (((0x87 < DAT_EXTMEM_0fd6) << 7) >> 7)),
                           DAT_EXTMEM_0fd6 + 0x78);
          *(undefined1 *)CONCAT11(cVar7 - (((0xdc < bVar6) << 7) >> 7),bVar6 + 0x23) =
               *(undefined1 *)CONCAT11(cVar7 + (':' - (((0xa3 < bVar6) << 7) >> 7)),bVar6 + 0x5c);
        }
        for (DAT_EXTMEM_0fd6 = 0; bVar6 = DAT_EXTMEM_0fd6, (DAT_EXTMEM_0fd6 ^ 0x80) < 0x9c;
            DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1) {
          cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
          *(undefined1 *)
           CONCAT11(cVar7 + ('\t' - (((0x99 < DAT_EXTMEM_0fd6) << 7) >> 7)),DAT_EXTMEM_0fd6 + 0x66)
               = *(undefined1 *)
                  CONCAT11(cVar7 + (':' - (((0xdb < DAT_EXTMEM_0fd6) << 7) >> 7)),
                           DAT_EXTMEM_0fd6 + 0x24);
          *(undefined1 *)CONCAT11(cVar7 + ('\t' - (((0x7b < bVar6) << 7) >> 7)),bVar6 + 0x84) =
               *(undefined1 *)CONCAT11(cVar7 + (':' - (((0xbf < bVar6) << 7) >> 7)),bVar6 + 0x40);
        }
        cVar7 = '\0';
        DAT_EXTMEM_09bd = 0;
      }
      return cVar7;
    }
    DAT_EXTMEM_09d3 = 0x4e;
    DAT_EXTMEM_09d4 = 0x20;
    FUN_CODE_6ecb();
    bVar6 = DAT_EXTMEM_083c;
    bVar1 = DAT_EXTMEM_083d;
    FUN_CODE_2bee();
    DAT_EXTMEM_0fd8 = bVar6;
    DAT_EXTMEM_0fd9 = bVar1;
LAB_CODE_2ea6:
    if (DAT_EXTMEM_0fd9 == 0 && DAT_EXTMEM_0fd8 == 0) goto LAB_CODE_3481;
    DAT_EXTMEM_09a2 = DAT_EXTMEM_0fd8;
    DAT_EXTMEM_09a3 = DAT_EXTMEM_0fd9;
    DAT_EXTMEM_0fdb =
         *(char *)CONCAT11(DAT_EXTMEM_0fd8 - (((0xfb < DAT_EXTMEM_0fd9) << 7) >> 7),
                           DAT_EXTMEM_0fd9 + 4);
    puVar8 = (undefined1 *)
             CONCAT11(DAT_EXTMEM_0fd8 - (((0xf1 < DAT_EXTMEM_0fd9) << 7) >> 7),DAT_EXTMEM_0fd9 + 0xe
                     );
    DAT_EXTMEM_0fe8 = *puVar8;
    DAT_EXTMEM_0fe9 = puVar8[1];
    DAT_EXTMEM_0fdc =
         *(char *)CONCAT11(DAT_EXTMEM_0fd8 - (((0xed < DAT_EXTMEM_0fd9) << 7) >> 7),
                           DAT_EXTMEM_0fd9 + 0x12);
    DAT_EXTMEM_0fdd =
         *(char *)CONCAT11(DAT_EXTMEM_0fd8 - (((0xec < DAT_EXTMEM_0fd9) << 7) >> 7),
                           DAT_EXTMEM_0fd9 + 0x13);
    pcVar10 = (char *)CONCAT11(DAT_EXTMEM_0fd8 - (((0xeb < DAT_EXTMEM_0fd9) << 7) >> 7),
                               DAT_EXTMEM_0fd9 + 0x14);
    DAT_EXTMEM_0fde = *pcVar10;
    DAT_EXTMEM_0fdf = pcVar10[1];
    pcVar10 = (char *)CONCAT11(DAT_EXTMEM_0fd8 - (((0xe5 < DAT_EXTMEM_0fd9) << 7) >> 7),
                               DAT_EXTMEM_0fd9 + 0x1a);
    DAT_EXTMEM_0fe0 = *pcVar10;
    cVar7 = pcVar10[1];
    DAT_EXTMEM_0fe1 = cVar7;
    FUN_CODE_6db4(0x48,4,1);
    cVar5 = DAT_EXTMEM_0fdc;
    bVar1 = DAT_EXTMEM_0fda;
    bVar6 = DAT_EXTMEM_0fd9;
    DAT_EXTMEM_0fe2 = cVar7;
    if (DAT_EXTMEM_0fdb == '2') {
      if (cVar7 == '\0') {
        cVar2 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar2 = DAT_EXTMEM_06f7;
        }
        if (cVar2 == '\0') goto LAB_CODE_305b;
      }
      else {
LAB_CODE_305b:
        if (cVar7 == '\x03') {
          cVar7 = DAT_EXTMEM_06f6;
          if (DAT_EXTMEM_06f6 == '\0') {
            cVar7 = DAT_EXTMEM_06f7;
          }
          if (cVar7 != '\0') goto LAB_CODE_3076;
        }
        cVar7 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar7 = DAT_EXTMEM_06f7;
        }
        if (cVar7 != '\0') goto LAB_CODE_32b9;
      }
LAB_CODE_3076:
      pbVar11 = (byte *)CONCAT11('\x01' - (((0xddU < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                 DAT_EXTMEM_0fdc * '\x03' + 0x22);
      bVar1 = *pbVar11;
      bVar4 = pbVar11[1];
      bVar3 = ~bVar4;
      if (bVar3 == 0) {
        bVar3 = ~bVar1;
      }
      if (((bVar3 == 0) || (DAT_EXTMEM_0750 == '\x01')) || (DAT_EXTMEM_0750 == '\x03')) {
        pbVar11 = (byte *)CONCAT11('\x01' - (((0xddU < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7)
                                   ,DAT_EXTMEM_0fdc * '\x03' + 0x22);
        *pbVar11 = DAT_EXTMEM_0fd8;
        pbVar11[1] = bVar6;
        *(undefined1 *)
         CONCAT11('\x01' - (((0xdeU < (byte)(cVar5 * '\x03')) << 7) >> 7),cVar5 * '\x03' + 0x21) =
             DAT_EXTMEM_0f8a;
      }
      else {
        bVar4 = ~bVar4;
        if (bVar4 == 0) {
          bVar4 = ~bVar1;
        }
        if ((bVar4 != 0) && (DAT_EXTMEM_0750 == '\x02')) {
          FUN_CODE_6ecb(*(undefined1 *)
                         CONCAT11('\x01' - (((0xdeU < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                  DAT_EXTMEM_0fdc * '\x03' + 0x21));
          puVar8 = (undefined1 *)
                   CONCAT11('\x01' - (((0xddU < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                            DAT_EXTMEM_0fdc * '\x03' + 0x22);
          FUN_CODE_6916(*puVar8,puVar8[1]);
          _5_2 = '\x01';
        }
      }
    }
    else if (DAT_EXTMEM_0fdb == '4') {
      if (cVar7 == '\0') {
        cVar2 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar2 = DAT_EXTMEM_06f7;
        }
        if (cVar2 == '\0') goto LAB_CODE_312c;
      }
      else {
LAB_CODE_312c:
        if (cVar7 == '\x03') {
          cVar7 = DAT_EXTMEM_06f6;
          if (DAT_EXTMEM_06f6 == '\0') {
            cVar7 = DAT_EXTMEM_06f7;
          }
          if (cVar7 != '\0') goto LAB_CODE_3147;
        }
        cVar7 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar7 = DAT_EXTMEM_06f7;
        }
        if (cVar7 != '\0') goto LAB_CODE_32b9;
      }
LAB_CODE_3147:
      pbVar11 = (byte *)CONCAT11(-(((0xe4U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                 DAT_EXTMEM_0fdc * '\x03' + 0x1b);
      bVar1 = *pbVar11;
      bVar4 = pbVar11[1];
      bVar3 = ~bVar4;
      if (bVar3 == 0) {
        bVar3 = ~bVar1;
      }
      if (((bVar3 == 0) || (DAT_EXTMEM_0750 == '\x01')) || (DAT_EXTMEM_0750 == '\x03')) {
        pbVar11 = (byte *)CONCAT11(-(((0xe4U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                   DAT_EXTMEM_0fdc * '\x03' + 0x1b);
        *pbVar11 = DAT_EXTMEM_0fd8;
        pbVar11[1] = bVar6;
        *(undefined1 *)
         CONCAT11(-(((0xe5U < (byte)(cVar5 * '\x03')) << 7) >> 7),cVar5 * '\x03' + 0x1a) =
             DAT_EXTMEM_0f8a;
      }
      else {
        bVar4 = ~bVar4;
        if (bVar4 == 0) {
          bVar4 = ~bVar1;
        }
        if ((bVar4 != 0) && (DAT_EXTMEM_0750 == '\x02')) {
          FUN_CODE_6ecb(*(undefined1 *)
                         CONCAT11(-(((0xe5U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                  DAT_EXTMEM_0fdc * '\x03' + 0x1a));
          puVar8 = (undefined1 *)
                   CONCAT11(-(((0xe4U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                            DAT_EXTMEM_0fdc * '\x03' + 0x1b);
          FUN_CODE_6916(*puVar8,puVar8[1]);
          _5_2 = '\x01';
        }
      }
    }
    else if (DAT_EXTMEM_0fdb == '6') {
      if (cVar7 == '\0') {
        cVar5 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar5 = DAT_EXTMEM_06f7;
        }
        if (cVar5 == '\0') goto LAB_CODE_31fd;
      }
      else {
LAB_CODE_31fd:
        if (cVar7 == '\x03') {
          cVar7 = DAT_EXTMEM_06f6;
          if (DAT_EXTMEM_06f6 == '\0') {
            cVar7 = DAT_EXTMEM_06f7;
          }
          if (cVar7 != '\0') goto LAB_CODE_3218;
        }
        cVar7 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar7 = DAT_EXTMEM_06f7;
        }
        if (cVar7 != '\0') goto LAB_CODE_32b9;
      }
LAB_CODE_3218:
      bVar6 = ~DAT_EXTMEM_081d;
      if (bVar6 == 0) {
        bVar6 = ~DAT_EXTMEM_081c;
      }
      if (((bVar6 == 0) || (DAT_EXTMEM_0750 == '\x01')) || (DAT_EXTMEM_0750 == '\x03')) {
        DAT_EXTMEM_081c = DAT_EXTMEM_0fd8;
        DAT_EXTMEM_081d = DAT_EXTMEM_0fd9;
        DAT_EXTMEM_081b = DAT_EXTMEM_0f8a;
        if (DAT_EXTMEM_0fdd == '\0') {
          _1_2 = '\x01';
        }
      }
      else {
        bVar6 = ~DAT_EXTMEM_081d;
        if (bVar6 == 0) {
          bVar6 = ~DAT_EXTMEM_081c;
        }
        if ((bVar6 != 0) && (DAT_EXTMEM_0750 == '\x02')) {
          FUN_CODE_6ecb(DAT_EXTMEM_081b);
          FUN_CODE_6916(DAT_EXTMEM_081c,DAT_EXTMEM_081d);
          _5_2 = '\x01';
        }
      }
    }
    else if (DAT_EXTMEM_0fdb == '8') {
      if (DAT_EXTMEM_0fda < 0x20) {
        pbVar11 = (byte *)CONCAT11('\x01' - (((0xbf < DAT_EXTMEM_0fda * '\x03') << 7) >> 7),
                                   DAT_EXTMEM_0fda * '\x03' + 0x40);
        *pbVar11 = DAT_EXTMEM_0fd8;
        pbVar11[1] = bVar6;
        *(undefined1 *)
         CONCAT11('\x01' - (((0xc0 < bVar1 * '\x03') << 7) >> 7),bVar1 * '\x03' + 0x3f) =
             DAT_EXTMEM_0f8a;
        DAT_EXTMEM_0fda = DAT_EXTMEM_0fda + 1;
      }
    }
    else if (DAT_EXTMEM_0fdb == '0') {
      if (cVar7 == '\0') {
        cVar2 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar2 = DAT_EXTMEM_06f7;
        }
        if (cVar2 == '\0') goto LAB_CODE_2f7e;
      }
      else {
LAB_CODE_2f7e:
        if (cVar7 == '\x03') {
          cVar7 = DAT_EXTMEM_06f6;
          if (DAT_EXTMEM_06f6 == '\0') {
            cVar7 = DAT_EXTMEM_06f7;
          }
          if (cVar7 != '\0') goto LAB_CODE_2f99;
        }
        cVar7 = DAT_EXTMEM_06f6;
        if (DAT_EXTMEM_06f6 == '\0') {
          cVar7 = DAT_EXTMEM_06f7;
        }
        if (cVar7 != '\0') goto LAB_CODE_32b9;
      }
LAB_CODE_2f99:
      cVar7 = DAT_EXTMEM_0fe0;
      if (DAT_EXTMEM_0fe0 == '\0') {
        cVar7 = DAT_EXTMEM_0fe1;
      }
      if (cVar7 != '\0') {
        _1_1 = 1;
      }
      pbVar11 = (byte *)CONCAT11('\x01' - (((0xe6U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                 DAT_EXTMEM_0fdc * '\x03' + 0x19);
      bVar1 = *pbVar11;
      bVar4 = pbVar11[1];
      bVar3 = ~bVar4;
      if (bVar3 == 0) {
        bVar3 = ~bVar1;
      }
      if (((bVar3 == 0) || (DAT_EXTMEM_0750 == '\x01')) || (DAT_EXTMEM_0750 == '\x03')) {
        pbVar11 = (byte *)CONCAT11('\x01' - (((0xe6U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7)
                                   ,DAT_EXTMEM_0fdc * '\x03' + 0x19);
        *pbVar11 = DAT_EXTMEM_0fd8;
        pbVar11[1] = bVar6;
        *(undefined1 *)
         CONCAT11('\x01' - (((0xe7U < (byte)(cVar5 * '\x03')) << 7) >> 7),cVar5 * '\x03' + 0x18) =
             DAT_EXTMEM_0f8a;
      }
      else {
        bVar4 = ~bVar4;
        if (bVar4 == 0) {
          bVar4 = ~bVar1;
        }
        if ((bVar4 != 0) && (DAT_EXTMEM_0750 == '\x02')) {
          FUN_CODE_6ecb(*(undefined1 *)
                         CONCAT11('\x01' - (((0xe7U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                                  DAT_EXTMEM_0fdc * '\x03' + 0x18));
          puVar8 = (undefined1 *)
                   CONCAT11('\x01' - (((0xe6U < (byte)(DAT_EXTMEM_0fdc * '\x03')) << 7) >> 7),
                            DAT_EXTMEM_0fdc * '\x03' + 0x19);
          FUN_CODE_6916(*puVar8,puVar8[1]);
          _5_2 = '\x01';
        }
      }
    }
LAB_CODE_32b9:
    if (_5_2 == '\0') {
      bVar6 = DAT_EXTMEM_0fd9 + DAT_EXTMEM_0fdf;
      DAT_EXTMEM_0fd8 =
           DAT_EXTMEM_0fd8 +
           (DAT_EXTMEM_0fde - ((CARRY1(DAT_EXTMEM_0fd9,DAT_EXTMEM_0fdf) << 7) >> 7));
      cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
      pbVar11 = (byte *)CONCAT11((cVar7 * '\x02' | CARRY1(DAT_EXTMEM_0fd6,DAT_EXTMEM_0fd6)) +
                                 ('\x0f' - (((0x95 < DAT_EXTMEM_0fd6 * '\x02') << 7) >> 7)),
                                 DAT_EXTMEM_0fd6 * '\x02' + 0x6a);
      DAT_EXTMEM_0fd9 = bVar6;
      if ((DAT_EXTMEM_0963 & pbVar11[1]) == 0 && (DAT_EXTMEM_0962 & *pbVar11) == 0) {
        puVar8 = (undefined1 *)
                 CONCAT11((cVar7 * '\x02' | CARRY1(DAT_EXTMEM_0fd6,DAT_EXTMEM_0fd6)) +
                          ('\b' - (((0xe0 < DAT_EXTMEM_0fd6 * '\x02') << 7) >> 7)),
                          DAT_EXTMEM_0fd6 * '\x02' + 0x1f);
        *puVar8 = 0xff;
        puVar8[1] = 0xff;
      }
      else {
        puVar8 = (undefined1 *)
                 CONCAT11((cVar7 * '\x02' | CARRY1(DAT_EXTMEM_0fd6,DAT_EXTMEM_0fd6)) +
                          ('\b' - (((0xe0 < DAT_EXTMEM_0fd6 * '\x02') << 7) >> 7)),
                          DAT_EXTMEM_0fd6 * '\x02' + 0x1f);
        *puVar8 = BANK0_R6;
        puVar8[1] = bVar6;
      }
      FUN_CODE_68c0();
      bVar6 = 0x10 - (((DAT_EXTMEM_0fd9 == 0) << 7) >> 7);
      if (DAT_EXTMEM_0fd8 < bVar6) goto LAB_CODE_3481;
      FUN_CODE_2bee(DAT_EXTMEM_0fd8 - bVar6);
      goto LAB_CODE_2ea6;
    }
    DAT_EXTMEM_0fda = 0;
    _1_2 = '\0';
    _5_2 = '\0';
    _1_1 = 0;
    DAT_EXTMEM_081c = 0xff;
    DAT_EXTMEM_081d = 0xff;
    DAT_EXTMEM_081b = 0;
    for (DAT_EXTMEM_0fd6 = 0; ((DAT_EXTMEM_0fd6 ^ 0x80) < 0x83) << 7 < '\0';
        DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1) {
      cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
      uVar9 = 0x119;
      bVar6 = DAT_EXTMEM_0fd6;
      FUN_CODE_7587(DAT_EXTMEM_0fd6,3);
      puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
      *puVar8 = 0xff;
      puVar8[1] = 0xff;
      uVar9 = 0x118;
      FUN_CODE_7587(bVar6,3);
      *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
      uVar9 = 0x122;
      FUN_CODE_7587(bVar6,3);
      puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
      *puVar8 = 0xff;
      puVar8[1] = 0xff;
      uVar9 = 0x121;
      FUN_CODE_7587(bVar6,3);
      *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
      uVar9 = 0x1b;
      FUN_CODE_7587(bVar6,3);
      puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
      *puVar8 = 0xff;
      puVar8[1] = 0xff;
      uVar9 = 0x1a;
      FUN_CODE_7587(bVar6,3);
      *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
    }
    for (DAT_EXTMEM_0fd6 = 0; (DAT_EXTMEM_0fd6 ^ 0x80) < 0xa0; DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1
        ) {
      cVar7 = (char)DAT_EXTMEM_0fd6 >> 7;
      uVar9 = 0x140;
      bVar6 = DAT_EXTMEM_0fd6;
      FUN_CODE_7587(DAT_EXTMEM_0fd6,3);
      puVar8 = (undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9);
      *puVar8 = 0xff;
      puVar8[1] = 0xff;
      uVar9 = 0x13f;
      FUN_CODE_7587(bVar6,3);
      *(undefined1 *)CONCAT11(cVar7 * '\x03' + (char)((ushort)uVar9 >> 8),(char)uVar9) = 0;
    }
    LATCH3_7SEG_802_15 = 0x99;
    DAT_EXTMEM_0fd6 = 0xff;
LAB_CODE_3481:
    DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + 1;
  } while( true );
}



// ==== FUN_CODE_3609 @ CODE:3609  (130 bytes)

byte FUN_CODE_3609(void)

{
  byte bVar1;
  
  DAT_INTMEM_32 = DAT_EXTMEM_083c;
  DAT_INTMEM_33 = DAT_EXTMEM_083d;
  while( true ) {
    if (DAT_INTMEM_32 == 0xff) {
      return 0;
    }
    bVar1 = T1;
    T1 = bVar1 ^ 1;
    DAT_INTMEM_34 = DAT_INTMEM_32;
    DAT_INTMEM_35 = DAT_INTMEM_33;
    DAT_INTMEM_36 = *(undefined1 *)CONCAT11(DAT_INTMEM_32,DAT_INTMEM_33);
    *(undefined1 *)CONCAT11(DAT_INTMEM_32,DAT_INTMEM_33) = 0x55;
    bVar1 = *(byte *)CONCAT11(DAT_INTMEM_32,DAT_INTMEM_33) ^ 0x55;
    if (bVar1 != 0) {
      return bVar1;
    }
    *(undefined1 *)CONCAT11(DAT_INTMEM_32,DAT_INTMEM_33) = 0xaa;
    bVar1 = *(byte *)CONCAT11(DAT_INTMEM_32,DAT_INTMEM_33) ^ 0xaa;
    if (bVar1 != 0) {
      return bVar1;
    }
    *(undefined1 *)CONCAT11(DAT_INTMEM_32,DAT_INTMEM_33) = DAT_INTMEM_36;
    bVar1 = ~DAT_INTMEM_33;
    if (bVar1 == 0) {
      bVar1 = ~DAT_INTMEM_32;
    }
    if (bVar1 == 0) break;
    DAT_INTMEM_33 = DAT_INTMEM_33 + 1;
    if (DAT_INTMEM_33 == 0) {
      DAT_INTMEM_32 = DAT_INTMEM_32 + 1;
    }
  }
  DAT_INTMEM_34 = DAT_INTMEM_32;
  DAT_INTMEM_35 = DAT_INTMEM_33;
  return 0;
}



// ==== FUN_CODE_368b @ CODE:368b  (742 bytes)

void FUN_CODE_368b(void)

{
  byte bVar1;
  char cVar2;
  
  FUN_CODE_7408(0x97,0x9c,0x3a,0xff,0xf,1,0,4);
  DAT_INTMEM_3a = 0;
  DAT_INTMEM_3b = '\x10';
  FUN_CODE_6ecb(0);
  DAT_INTMEM_37 = '\x10';
  DAT_INTMEM_38 = 0;
  bVar1 = T1;
  T1 = bVar1 ^ 1;
  FUN_CODE_6e9c();
  DAT_INTMEM_39 = *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38);
  *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = 0x55;
  if (*(char *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) != 'U') {
    cVar2 = '\0';
    FUN_CODE_7018(0x10,0);
    if (cVar2 == '\x01') {
      return;
    }
    DAT_EXTMEM_0f95 = 0x10;
    DAT_EXTMEM_0f96 = 0;
    cVar2 = DAT_INTMEM_3b;
    FUN_CODE_79a7(0,0,0x90,1,0x10,1,DAT_INTMEM_3a);
    if (cVar2 == '\0') {
      cVar2 = '\x04';
      FUN_CODE_79a7(0,0x97,0xf,1,0x80,1,0);
      if (cVar2 == '\0') {
        DAT_EXTMEM_083c = 0x80;
        DAT_EXTMEM_083d = 0;
        *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
        return;
      }
    }
    cVar2 = DAT_INTMEM_3b;
    FUN_CODE_79a7(DAT_EXTMEM_0f96,0,0x90,1,DAT_EXTMEM_0f95,1,DAT_INTMEM_3a);
    if (cVar2 != '\0') {
      cVar2 = '\x04';
      FUN_CODE_79a7(0,0x97,0xf,1,0x10,1,0);
      if (cVar2 == '\0') {
        DAT_EXTMEM_083c = 0x10;
        DAT_EXTMEM_083d = 0;
        *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
        return;
      }
    }
    DAT_EXTMEM_083c = 0x10;
    DAT_EXTMEM_083d = 0;
    *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
    return;
  }
  if (*(char *)CONCAT11(DAT_INTMEM_37 + -0x80,DAT_INTMEM_38) ==
      *(char *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38)) {
    *(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = ~*(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38)
    ;
    if (*(char *)CONCAT11(DAT_INTMEM_37 + -0x80,DAT_INTMEM_38) == BANK0_R7) {
      DAT_EXTMEM_083c = 0x80;
    }
    else {
      DAT_EXTMEM_083c = 0x10;
    }
    DAT_EXTMEM_083d = 0;
    *(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = ~*(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38)
    ;
  }
  else {
    DAT_EXTMEM_083c = 0x10;
    DAT_EXTMEM_083d = 0;
  }
  *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = 0xaa;
  if (*(char *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) == -0x56) {
    if (*(char *)CONCAT11(DAT_INTMEM_37 + -0x80,DAT_INTMEM_38) ==
        *(char *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38)) {
      *(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) =
           ~*(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38);
      if (*(char *)CONCAT11(DAT_INTMEM_37 + -0x80,DAT_INTMEM_38) == BANK0_R7) {
        DAT_EXTMEM_083c = 0x80;
      }
      else {
        DAT_EXTMEM_083c = 0x10;
      }
      DAT_EXTMEM_083d = 0;
      *(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) =
           ~*(byte *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38);
    }
    else {
      DAT_EXTMEM_083c = 0x10;
      DAT_EXTMEM_083d = 0;
    }
    *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
    return;
  }
  cVar2 = '\0';
  FUN_CODE_7018(0x10,0);
  if (cVar2 == '\x01') {
    return;
  }
  DAT_EXTMEM_0f95 = 0x10;
  DAT_EXTMEM_0f96 = 0;
  cVar2 = DAT_INTMEM_3b;
  FUN_CODE_79a7(0,0,0x90,1,0x10,1,DAT_INTMEM_3a);
  if (cVar2 == '\0') {
    cVar2 = '\x04';
    FUN_CODE_79a7(0,0x97,0xf,1,0x80,1,0);
    if (cVar2 == '\0') {
      DAT_EXTMEM_083c = 0x80;
      DAT_EXTMEM_083d = 0;
      *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
      return;
    }
  }
  cVar2 = DAT_INTMEM_3b;
  FUN_CODE_79a7(DAT_EXTMEM_0f96,0,0x90,1,DAT_EXTMEM_0f95,1,DAT_INTMEM_3a);
  if (cVar2 != '\0') {
    cVar2 = '\x04';
    FUN_CODE_79a7(0,0x97,0xf,1,0x10,1,0);
    if (cVar2 == '\0') {
      DAT_EXTMEM_083c = 0x10;
      DAT_EXTMEM_083d = 0;
      *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
      return;
    }
  }
  DAT_EXTMEM_083c = 0x10;
  DAT_EXTMEM_083d = 0;
  *(undefined1 *)CONCAT11(DAT_INTMEM_37,DAT_INTMEM_38) = DAT_INTMEM_39;
  return;
}



// ==== FUN_CODE_3aa0 @ CODE:3aa0  (54 bytes)

undefined1 FUN_CODE_3aa0(char param_1,undefined1 param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  
  FUN_CODE_74bf(BANK0_R6,BANK0_R7,0,8);
  pcVar3 = &DAT_EXTMEM_0fd7;
  cVar1 = '\0';
  cVar2 = '\b';
  DAT_EXTMEM_0fd6 = param_1;
  DAT_EXTMEM_0fd7 = param_2;
  FUN_CODE_74bf(BANK0_R2,BANK0_R3);
  if ((cVar2 != '\0' || cVar1 != '\0') &&
     (cVar1 = *pcVar3, *pcVar3 = cVar1 + '\x01', cVar1 + '\x01' == '\0')) {
    DAT_EXTMEM_0fd6 = DAT_EXTMEM_0fd6 + '\x01';
  }
  return DAT_EXTMEM_0fd7;
}



// ==== FUN_CODE_3ad6 @ CODE:3ad6  (878 bytes)

void FUN_CODE_3ad6(byte param_1,undefined1 param_2,undefined1 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  short *psVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  char *pcVar11;
  undefined2 uStack_1;
  
  DAT_EXTMEM_0f93 = param_2;
  DAT_EXTMEM_0f94 = param_3;
  if ((_2_6 == '\x01') || (_1_7 != '\0')) {
    return;
  }
  DAT_EXTMEM_09ed = param_1;
  if ((((_4_1 == '\0') || (param_1 == 0)) || (_3_5 == '\x01')) || (_3_6 == '\x01')) {
    FUN_CODE_3e44(param_2,param_3);
    bVar3 = (byte)((ushort)DAT_EXTMEM_09ed * 3);
    FUN_CODE_7408(BANK0_R1,bVar3 - 0x10,
                  ((char)((ushort)DAT_EXTMEM_09ed * 3 >> 8) - (((0xf < bVar3) << 7) >> 7)) + '\t',1,
                  0,3);
    bVar3 = DAT_EXTMEM_09ed;
    psVar7 = (short *)CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                               DAT_EXTMEM_09ed * '\x03' - 0xf);
    if ((char)*psVar7 == '\0' && *(char *)psVar7 == '\0') {
      return;
    }
    if (DAT_EXTMEM_09ed == 2) {
      _4_3 = 1;
    }
    bVar4 = *(byte *)(*psVar7 + 3);
    pbVar8 = (byte *)CONCAT11('\t' - (((5 < DAT_EXTMEM_09ed * '\x02') << 7) >> 7),
                              DAT_EXTMEM_09ed * '\x02' - 6);
    *pbVar8 = *(byte *)(*psVar7 + 2) & 0x1f;
    pbVar8[1] = bVar4;
    if ((bVar3 == 1) && (*(char *)(sEXTMEM09f4 + 2) < '\0')) {
      _2_3 = 1;
    }
    else if ((bVar3 == 2) && (*(char *)(sEXTMEM09f7 + 2) < '\0')) {
      _1_0 = 1;
    }
    bVar3 = DAT_EXTMEM_09ed;
    FUN_CODE_74f5(0,CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                             DAT_EXTMEM_09ed * '\x03' - 0xf),4);
    bVar4 = (byte)((ushort)bVar3 * 2);
    puVar9 = (undefined1 *)
             CONCAT11((char)((ushort)bVar3 * 2 >> 8) - (((0xf2 < bVar4) << 7) >> 7),bVar4 + 0xd);
    *puVar9 = 0;
    puVar9[1] = 0;
    if (((DAT_EXTMEM_0710 == '\0') && (DAT_EXTMEM_09bc == BANK0_R6)) &&
       ((bVar3 == 1 || (bVar3 == 2)))) {
      _3_4 = '\x01';
      _3_2 = '\x01';
      _4_4 = '\x01';
    }
  }
  if ((DAT_EXTMEM_0710 == '\0') && (DAT_EXTMEM_09bc == DAT_EXTMEM_06f5)) {
    if (((_4_4 != '\0') && (DAT_EXTMEM_0964 == '\0')) ||
       ((DAT_EXTMEM_09ed == 0 && (DAT_EXTMEM_0964 == '\x02')))) {
      FUN_CODE_7002(7,4);
    }
    if (_3_4 != '\0') {
      FUN_CODE_7002(0x17,8);
    }
    if (_3_2 != '\0') {
      FUN_CODE_7002(0x2c,0x19);
    }
    DAT_EXTMEM_0f58 = 4;
    DAT_EXTMEM_0f59 = 8;
    DAT_EXTMEM_0f5a = 0x19;
  }
  do {
    FUN_CODE_6ecb(*(undefined1 *)
                   CONCAT11('\t' - (((0xf < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                            DAT_EXTMEM_09ed * '\x03' - 0x10));
    puVar10 = (undefined2 *)
              CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                       DAT_EXTMEM_09ed * '\x03' - 0xf);
    uVar2 = *puVar10;
    uVar1 = *puVar10;
    bVar4 = (byte)uVar1;
    bVar3 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
    pcVar11 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                               (((0xf2 < bVar3) << 7) >> 7),bVar3 + 0xd);
    cVar5 = *pcVar11;
    bVar3 = pcVar11[1];
    DAT_EXTMEM_0f95 =
         *(byte *)CONCAT11(cVar5 + ((char)((ushort)uVar1 >> 8) - ((CARRY1(bVar3,bVar4) << 7) >> 7)),
                           bVar3 + bVar4);
    bVar4 = (byte)uVar2;
    bVar3 = *(byte *)(CONCAT11(cVar5 + ((char)((ushort)uVar2 >> 8) -
                                       ((CARRY1(bVar4,bVar3) << 7) >> 7)),bVar4 + bVar3) + 1);
    if ((((DAT_EXTMEM_0710 == '\0') && (DAT_EXTMEM_09bc == DAT_EXTMEM_06f5)) &&
        ((DAT_EXTMEM_0f95 >> 5 & 1) != 0)) && (bVar4 = bVar3 & 0x18, bVar4 != 0)) {
      if (bVar4 == 8) {
        _3_3 = 1;
        if ((char)bVar3 < '\0') {
          _4_4 = '\0';
        }
      }
      else if (bVar4 == 0x10) {
        _3_1 = 1;
        if ((char)bVar3 < '\0') {
          _3_4 = '\0';
        }
      }
      else if ((bVar4 == 0x18) && (_3_0 = 1, (char)bVar3 < '\0')) {
        _3_2 = '\0';
      }
    }
    if (((DAT_EXTMEM_0f95 >> 5 & 1) == 0) || (-1 < (char)bVar3)) {
      FUN_CODE_3f62(10,0x10);
    }
    else {
      FUN_CODE_3f62(DAT_EXTMEM_09ee,DAT_EXTMEM_09ef);
    }
  } while (-1 < (char)DAT_EXTMEM_0f95);
  if ((((DAT_EXTMEM_09ed == 1) && (_3_6 != '\0')) && (_3_7 == '\0')) ||
     ((((DAT_EXTMEM_09ed == 0 && (_3_6 != '\0')) && (_3_7 == '\0')) ||
      (((DAT_EXTMEM_09ed == 2 && (_4_0 == '\0')) && (_3_5 != '\0')))))) {
    DAT_EXTMEM_0f96 = 0;
    DAT_EXTMEM_0f97 = 0;
    while (bVar4 = DAT_EXTMEM_0f97, bVar3 = DAT_EXTMEM_0f96,
          DAT_EXTMEM_0f96 <
          (byte)(DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f97 < DAT_EXTMEM_0017) << 7) >> 7))) {
      cVar5 = DAT_EXTMEM_0f96 + ('\x01' - (((0x5b < DAT_EXTMEM_0f97) << 7) >> 7));
      uStack_1 = (byte *)CONCAT11(cVar5,DAT_EXTMEM_0f97 + 0xa4);
      *uStack_1 = *(byte *)CONCAT11(cVar5,DAT_EXTMEM_0f97 + 0xa4) |
                  *(byte *)CONCAT11(DAT_EXTMEM_0f96 +
                                    ('\n' - (((0xef < DAT_EXTMEM_0f97) << 7) >> 7)),
                                    DAT_EXTMEM_0f97 + 0x10);
      cVar5 = bVar3 + ('\x01' - (((0x5b < bVar4) << 7) >> 7));
      uStack_1 = (byte *)CONCAT11(cVar5,bVar4 + 0xa4);
      *uStack_1 = *(byte *)CONCAT11(cVar5,bVar4 + 0xa4) |
                  *(byte *)CONCAT11(bVar3 + (DAT_EXTMEM_09ee -
                                            ((CARRY1(DAT_EXTMEM_09ef,bVar4) << 7) >> 7)),
                                    DAT_EXTMEM_09ef + bVar4);
      DAT_EXTMEM_0f97 = DAT_EXTMEM_0f97 + 1;
      if (DAT_EXTMEM_0f97 == 0) {
        DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 + 1;
      }
    }
  }
  bVar3 = DAT_EXTMEM_09ed;
  if ((DAT_EXTMEM_09ed == 1) || (DAT_EXTMEM_09ed == 2)) {
    pcVar11 = (char *)CONCAT11('\t' - (((5 < DAT_EXTMEM_09ed * '\x02') << 7) >> 7),
                               DAT_EXTMEM_09ed * '\x02' - 6);
    bVar4 = pcVar11[1];
    bVar6 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
    pbVar8 = (byte *)CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                              (((0xf2 < bVar6) << 7) >> 7),bVar6 + 0xd);
    if (*pbVar8 < (byte)((*pcVar11 + (-1 - (((3 < bVar4) << 7) >> 7))) -
                        (((pbVar8[1] < bVar4 - 4) << 7) >> 7))) {
      _4_1 = '\x01';
      if (DAT_EXTMEM_09ed == 1) {
        _3_6 = '\0';
        _4_0 = '\0';
      }
      else if (DAT_EXTMEM_09ed == 2) {
        _4_3 = 0;
        _3_5 = '\0';
        _3_7 = '\0';
      }
    }
    else {
      bVar4 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
      puVar9 = (undefined1 *)
               CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) - (((0xf2 < bVar4) << 7) >> 7),
                        bVar4 + 0xd);
      *puVar9 = 0;
      puVar9[1] = 0;
      if (bVar3 == 1) {
        _4_0 = '\x01';
      }
      else if (bVar3 == 2) {
        _3_7 = '\x01';
      }
    }
  }
  return;
}



// ==== FUN_CODE_3e44 @ CODE:3e44  (286 bytes)

void FUN_CODE_3e44(byte param_1,byte param_2,undefined1 param_3,undefined1 param_4)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  undefined1 *puVar9;
  undefined2 uStack_1;
  
  DAT_EXTMEM_0f9c = '\0';
  DAT_EXTMEM_0f98 = param_3;
  DAT_EXTMEM_0f99 = param_4;
  DAT_EXTMEM_0f9a = param_1;
  DAT_EXTMEM_0f9b = param_2;
  do {
    uStack_1 = (undefined1 *)CONCAT11(DAT_EXTMEM_0f98,DAT_EXTMEM_0f99);
    cVar7 = DAT_EXTMEM_0f9c;
    uVar2 = DAT_EXTMEM_0f98;
    uVar3 = DAT_EXTMEM_0f99;
    FUN_CODE_7587(3,DAT_EXTMEM_0f9c);
    bVar4 = ~*(byte *)((short)uStack_1 + 2);
    if (bVar4 == 0) {
      bVar4 = ~*(byte *)((short)uStack_1 + 1);
    }
    if (bVar4 == 0) {
      DAT_EXTMEM_0f9d = 0;
      DAT_EXTMEM_0f9e = 0;
      DAT_EXTMEM_0f9f = 0;
      return;
    }
    puVar9 = (undefined1 *)CONCAT11(uVar2,uVar3);
    FUN_CODE_7587(cVar7,3);
    FUN_CODE_6ecb(*puVar9);
    uStack_1 = (undefined1 *)CONCAT11(DAT_EXTMEM_0f98,DAT_EXTMEM_0f99);
    FUN_CODE_7587(DAT_EXTMEM_0f9c,3);
    bVar4 = *(byte *)((short)uStack_1 + 2) + 0x20;
    cVar7 = BANK0_R6 - (((0xdf < *(byte *)((short)uStack_1 + 2)) << 7) >> 7);
    while( true ) {
      bVar8 = *(byte *)CONCAT11(cVar7,bVar4);
      bVar6 = ((byte *)CONCAT11(cVar7,bVar4))[1];
      bVar5 = ~bVar6;
      if (bVar5 == 0) {
        bVar5 = ~bVar8;
      }
      if (bVar5 == 0) break;
      DAT_EXTMEM_09d3 = 0x4e;
      DAT_EXTMEM_09d4 = 0x20;
      bVar6 = DAT_EXTMEM_0f9b ^ bVar6;
      if (bVar6 == 0) {
        bVar6 = bVar8 ^ DAT_EXTMEM_0f9a;
      }
      if (bVar6 == 0) break;
      bVar8 = *(byte *)(CONCAT11(cVar7,bVar4) + 3) >> 1;
      bVar6 = bVar8 | BANK0_R6 << 7;
      bVar8 = bVar8 * '\x02';
      bVar1 = CARRY1(bVar8,bVar4);
      bVar4 = bVar8 + bVar4;
      cVar7 = (BANK0_R6 & 0xfe | CARRY1(bVar6,bVar6)) + (cVar7 - ((bVar1 << 7) >> 7));
    }
    bVar8 = ~((byte *)CONCAT11(cVar7,bVar4))[1];
    if (bVar8 == 0) {
      bVar8 = ~*(byte *)CONCAT11(cVar7,bVar4);
    }
    if (bVar8 != 0) {
      uStack_1 = (undefined1 *)CONCAT11(DAT_EXTMEM_0f98,DAT_EXTMEM_0f99);
      FUN_CODE_7587(DAT_EXTMEM_0f9c,3);
      DAT_EXTMEM_0f9d = *uStack_1;
      DAT_EXTMEM_0f9e = cVar7;
      DAT_EXTMEM_0f9f = BANK0_R5;
      return;
    }
    DAT_EXTMEM_0f9c = DAT_EXTMEM_0f9c + '\x01';
  } while( true );
}



// ==== FUN_CODE_3f62 @ CODE:3f62  (1938 bytes)

void FUN_CODE_3f62(undefined1 param_1,char param_2)

{
  bool bVar1;
  short sVar2;
  undefined2 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  undefined1 *puVar11;
  char *pcVar12;
  byte bVar13;
  
  uVar3 = *(undefined2 *)
           CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                    DAT_EXTMEM_09ed * '\x03' - 0xf);
  bVar10 = (byte)uVar3;
  bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
  bVar7 = 1;
  DAT_EXTMEM_0f98 = param_1;
  DAT_EXTMEM_0f99 = param_2;
  cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                                   (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd));
  DAT_EXTMEM_0f9a =
       *(byte *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) - ((CARRY1(bVar10,bVar7) << 7) >> 7)),
                         bVar10 + bVar7);
  bVar7 = DAT_EXTMEM_0f9a & 0x7f;
  if (bVar7 == 4) {
    bVar8 = 0;
    bVar7 = 0;
    while (bVar8 < (byte)(DAT_EXTMEM_0016 - (((bVar7 < DAT_EXTMEM_0017) << 7) >> 7))) {
      if (bVar7 + 1 == 0) {
        bVar8 = bVar8 + 1;
      }
      *(undefined1 *)
       CONCAT11(BANK0_R6 + (DAT_EXTMEM_09ee - ((CARRY1(bVar7,DAT_EXTMEM_09ef) << 7) >> 7)),
                bVar7 + DAT_EXTMEM_09ef) = 0;
      bVar7 = bVar7 + 1;
    }
    if ((DAT_EXTMEM_0710 == '\0') && (DAT_EXTMEM_09bc == DAT_EXTMEM_06f5)) {
      _4_4 = 1;
      _3_4 = 1;
      _3_2 = 1;
      if (DAT_EXTMEM_0964 == '\0') {
        FUN_CODE_7002(0x2c,4);
      }
      else if ((DAT_EXTMEM_0964 == '\x01') || (DAT_EXTMEM_0964 == '\x02')) {
        FUN_CODE_7002(0x2c,8);
      }
      _5_0 = 0;
      return;
    }
  }
  else if (bVar7 == 0x28) {
    bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
    bVar7 = DAT_EXTMEM_09ed;
    FUN_CODE_74f5(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) - (((0xf2 < bVar8) << 7) >> 7)
                             ,bVar8 + 0xd),1);
    bVar8 = (byte)((ushort)bVar7 * 2);
    puVar11 = (undefined1 *)
              CONCAT11((char)((ushort)bVar7 * 2 >> 8) - (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd);
    FUN_CODE_5064(*puVar11,puVar11[1]);
    cVar9 = BANK0_R6;
    bVar7 = BANK0_R7;
    cVar4 = DAT_EXTMEM_09e0;
    bVar8 = DAT_EXTMEM_09e1;
    FUN_CODE_74bf(0,2);
    DAT_EXTMEM_0fa2 = bVar7 - bVar8;
    DAT_EXTMEM_0fa1 = cVar9 - (cVar4 - (((bVar7 < bVar8) << 7) >> 7));
    bVar7 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
    pcVar12 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                               (((0xf2 < bVar7) << 7) >> 7),bVar7 + 0xd);
    cVar9 = *pcVar12;
    bVar7 = pcVar12[1];
    FUN_CODE_5096();
    bVar10 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
    bVar8 = DAT_EXTMEM_09ed;
    DAT_EXTMEM_0fa3 = cVar9;
    DAT_EXTMEM_0fa4 = bVar7;
    FUN_CODE_74f5(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                             (((0xf2 < bVar10) << 7) >> 7),bVar10 + 0xd),2);
    uVar3 = *(undefined2 *)
             CONCAT11('\t' - (((0xe < bVar8 * '\x03') << 7) >> 7),bVar8 * '\x03' - 0xf);
    bVar13 = (byte)uVar3;
    bVar10 = (byte)((ushort)bVar8 * 2);
    bVar7 = 1;
    cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)bVar8 * 2 >> 8) - (((0xf2 < bVar10) << 7) >> 7),
                                     bVar10 + 0xd));
    DAT_EXTMEM_0f9a =
         *(byte *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) - ((CARRY1(bVar13,bVar7) << 7) >> 7))
                           ,bVar13 + bVar7) & 7;
    if (DAT_EXTMEM_0f9a == 0) {
      DAT_EXTMEM_0f9a = 1;
    }
    uVar3 = *(undefined2 *)
             CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                      DAT_EXTMEM_09ed * '\x03' - 0xf);
    bVar13 = (byte)uVar3;
    bVar10 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
    bVar7 = 1;
    bVar8 = DAT_EXTMEM_09ed;
    cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                                     (((0xf2 < bVar10) << 7) >> 7),bVar10 + 0xd));
    bVar7 = *(byte *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                      ((CARRY1(bVar13,bVar7) << 7) >> 7)),bVar13 + bVar7);
    DAT_EXTMEM_0fa6 = DAT_EXTMEM_0fa2 + bVar7;
    DAT_EXTMEM_0fa5 = DAT_EXTMEM_0fa1 - ((CARRY1(DAT_EXTMEM_0fa2,bVar7) << 7) >> 7);
    uVar3 = *(undefined2 *)
             CONCAT11('\t' - (((0xe < bVar8 * '\x03') << 7) >> 7),bVar8 * '\x03' - 0xf);
    bVar13 = (byte)uVar3;
    bVar10 = (byte)((ushort)bVar8 * 2);
    bVar7 = 1;
    cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)bVar8 * 2 >> 8) - (((0xf2 < bVar10) << 7) >> 7),
                                     bVar10 + 0xd));
    bVar7 = *(byte *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                      ((CARRY1(bVar13,bVar7) << 7) >> 7)),bVar13 + bVar7);
    DAT_EXTMEM_0fa8 = DAT_EXTMEM_0fa4 + bVar7;
    DAT_EXTMEM_0fa7 = DAT_EXTMEM_0fa3 - ((CARRY1(DAT_EXTMEM_0fa4,bVar7) << 7) >> 7);
    do {
      DAT_EXTMEM_0fa9 = DAT_EXTMEM_0fa1;
      DAT_EXTMEM_0faa = DAT_EXTMEM_0fa2;
      while ((DAT_EXTMEM_0fa9 ^ 0x80) <
             (DAT_EXTMEM_0fa5 ^ 0x80) - (((DAT_EXTMEM_0faa < DAT_EXTMEM_0fa6) << 7) >> 7)) {
        DAT_EXTMEM_0fd0 = 1;
        FUN_CODE_4927(DAT_EXTMEM_0fa3,DAT_EXTMEM_0fa4,DAT_EXTMEM_0f98,DAT_EXTMEM_0f99);
        DAT_EXTMEM_0fd0 = 1;
        FUN_CODE_4927(DAT_EXTMEM_0fa7 + (-1 - (((DAT_EXTMEM_0fa8 != 0) << 7) >> 7)),
                      DAT_EXTMEM_0fa8 - 1,DAT_EXTMEM_0fa9,DAT_EXTMEM_0faa,DAT_EXTMEM_0f98,
                      DAT_EXTMEM_0f99);
        DAT_EXTMEM_0faa = DAT_EXTMEM_0faa + 1;
        if (DAT_EXTMEM_0faa == 0) {
          DAT_EXTMEM_0fa9 = DAT_EXTMEM_0fa9 + 1;
        }
      }
      bVar7 = 1;
      DAT_EXTMEM_0fab = FUN_CODE_74f5(0,0xfa3,DAT_EXTMEM_0faa);
      DAT_EXTMEM_0fac = bVar7;
      while ((DAT_EXTMEM_0fab ^ 0x80) <
             (DAT_EXTMEM_0fa7 ^ 0x80) - (((DAT_EXTMEM_0fac < DAT_EXTMEM_0fa8) << 7) >> 7)) {
        DAT_EXTMEM_0fd0 = 1;
        FUN_CODE_4927(DAT_EXTMEM_0fac,DAT_EXTMEM_0fa1,DAT_EXTMEM_0fa2,DAT_EXTMEM_0f98,
                      DAT_EXTMEM_0f99);
        DAT_EXTMEM_0fd0 = 1;
        FUN_CODE_4927(DAT_EXTMEM_0fab,DAT_EXTMEM_0fac,
                      DAT_EXTMEM_0fa5 + (-1 - (((DAT_EXTMEM_0fa6 != 0) << 7) >> 7)),
                      DAT_EXTMEM_0fa6 - 1,DAT_EXTMEM_0f98,DAT_EXTMEM_0f99);
        DAT_EXTMEM_0fac = DAT_EXTMEM_0fac + 1;
        if (DAT_EXTMEM_0fac == 0) {
          DAT_EXTMEM_0fab = DAT_EXTMEM_0fab + 1;
        }
      }
      DAT_EXTMEM_0fa2 = DAT_EXTMEM_0fa2 + 1;
      if (DAT_EXTMEM_0fa2 == 0) {
        DAT_EXTMEM_0fa1 = DAT_EXTMEM_0fa1 + 1;
      }
      bVar1 = DAT_EXTMEM_0fa6 != 0;
      DAT_EXTMEM_0fa6 = DAT_EXTMEM_0fa6 - 1;
      DAT_EXTMEM_0fa5 = DAT_EXTMEM_0fa5 + (-1 - ((bVar1 << 7) >> 7));
      bVar1 = DAT_EXTMEM_0fa8 != 0;
      DAT_EXTMEM_0fa8 = DAT_EXTMEM_0fa8 - 1;
      DAT_EXTMEM_0fa7 = DAT_EXTMEM_0fa7 + (-1 - ((bVar1 << 7) >> 7));
      DAT_EXTMEM_0f9a = DAT_EXTMEM_0f9a - 1;
    } while (DAT_EXTMEM_0f9a != 0);
  }
  else {
    if (bVar7 == 0x48) {
      _2_4 = 1;
      return;
    }
    if (bVar7 == 0x20) {
      bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
      bVar7 = DAT_EXTMEM_09ed;
      FUN_CODE_74f5(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                               (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd),1);
      bVar8 = (byte)((ushort)bVar7 * 2);
      puVar11 = (undefined1 *)
                CONCAT11((char)((ushort)bVar7 * 2 >> 8) - (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd);
      FUN_CODE_5064(*puVar11,puVar11[1]);
      cVar9 = BANK0_R6;
      bVar7 = BANK0_R7;
      cVar4 = DAT_EXTMEM_09e0;
      bVar8 = DAT_EXTMEM_09e1;
      FUN_CODE_74bf(0,2);
      DAT_EXTMEM_0f9c = bVar7 - bVar8;
      DAT_EXTMEM_0f9b = cVar9 - (cVar4 - (((bVar7 < bVar8) << 7) >> 7));
      bVar7 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
      puVar11 = (undefined1 *)
                CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) - (((0xf2 < bVar7) << 7) >> 7),
                         bVar7 + 0xd);
      uVar5 = *puVar11;
      uVar6 = puVar11[1];
      FUN_CODE_5096();
      bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
      bVar7 = DAT_EXTMEM_09ed;
      DAT_EXTMEM_0f9d = uVar5;
      DAT_EXTMEM_0f9e = uVar6;
      FUN_CODE_74f5(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                               (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd),2);
      uVar3 = *(undefined2 *)
               CONCAT11('\t' - (((0xe < bVar7 * '\x03') << 7) >> 7),bVar7 * '\x03' - 0xf);
      bVar13 = (byte)uVar3;
      bVar10 = (byte)((ushort)bVar7 * 2);
      bVar8 = 1;
      cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)bVar7 * 2 >> 8) -
                                       (((0xf2 < bVar10) << 7) >> 7),bVar10 + 0xd));
      DAT_EXTMEM_0a0d =
           *(byte *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                     ((CARRY1(bVar13,bVar8) << 7) >> 7)),bVar13 + bVar8) & 0x1f;
      uVar3 = *(undefined2 *)
               CONCAT11('\t' - (((0xe < bVar7 * '\x03') << 7) >> 7),bVar7 * '\x03' - 0xf);
      bVar13 = (byte)uVar3;
      bVar10 = (byte)((ushort)bVar7 * 2);
      bVar8 = 1;
      cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)bVar7 * 2 >> 8) -
                                       (((0xf2 < bVar10) << 7) >> 7),bVar10 + 0xd));
      DAT_EXTMEM_0f9f =
           *(char *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                     ((CARRY1(bVar13,bVar8) << 7) >> 7)),bVar13 + bVar8);
      bVar8 = (byte)((ushort)bVar7 * 2);
      puVar11 = (undefined1 *)
                CONCAT11((char)((ushort)bVar7 * 2 >> 8) - (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd);
      DAT_EXTMEM_0fb5 = *puVar11;
      DAT_EXTMEM_0fb6 = puVar11[1];
      uVar3 = *(undefined2 *)
               CONCAT11('\t' - (((0xe < bVar7 * '\x03') << 7) >> 7),bVar7 * '\x03' - 0xf);
      bVar13 = (byte)uVar3;
      bVar10 = (byte)((ushort)bVar7 * 2);
      bVar8 = 1;
      cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)bVar7 * 2 >> 8) -
                                       (((0xf2 < bVar10) << 7) >> 7),bVar10 + 0xd));
      if (*(char *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) - ((CARRY1(bVar13,bVar8) << 7) >> 7)
                                    ),bVar13 + bVar8) == '#') {
        uVar3 = *(undefined2 *)
                 CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                          DAT_EXTMEM_09ed * '\x03' - 0xf);
        bVar10 = (byte)uVar3;
        bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
        bVar7 = 1;
        cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                                         (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd));
        if (*(char *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                      ((CARRY1(bVar10,bVar7) << 7) >> 7)),bVar10 + bVar7) == '!') {
          uVar3 = *(undefined2 *)
                   CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                            DAT_EXTMEM_09ed * '\x03' - 0xf);
          bVar10 = (byte)uVar3;
          bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
          bVar7 = 1;
          cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                                           (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd));
          DAT_EXTMEM_0fa0 =
               *(char *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                         ((CARRY1(bVar10,bVar7) << 7) >> 7)),bVar10 + bVar7);
          DAT_EXTMEM_0fae = 0;
          do {
            *(char *)CONCAT11('\x0f' - (((0x50 < DAT_EXTMEM_0fae) << 7) >> 7),DAT_EXTMEM_0fae + 0xaf
                             ) = DAT_EXTMEM_0fa0;
            uVar3 = *(undefined2 *)
                     CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                              DAT_EXTMEM_09ed * '\x03' - 0xf);
            bVar13 = (byte)uVar3;
            bVar7 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
            bVar10 = 1;
            bVar8 = FUN_CODE_750b(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                                             (((0xf2 < bVar7) << 7) >> 7),bVar7 + 0xd));
            bVar7 = (char)((ushort)uVar3 >> 8) - ((CARRY1(bVar13,bVar10) << 7) >> 7);
            cVar9 = CARRY1(bVar8,bVar7) << 7;
            cVar4 = *(char *)CONCAT11(bVar8 + bVar7,bVar13 + bVar10);
            DAT_EXTMEM_0fae = DAT_EXTMEM_0fae + 1;
            DAT_EXTMEM_0fa0 = cVar4;
            if ((cVar4 == '\0') || (FUN_CODE_000e(), -1 < cVar9)) break;
          } while (DAT_EXTMEM_0fae < 6);
          *(undefined1 *)
           CONCAT11('\x0f' - (((0x50 < DAT_EXTMEM_0fae) << 7) >> 7),DAT_EXTMEM_0fae + 0xaf) = 0;
          DAT_EXTMEM_0fb5 = 0;
          FUN_CODE_7cc5(0xaf,0xf,1);
          DAT_EXTMEM_09eb = bVar8;
          DAT_EXTMEM_09ec = cVar4;
          _4_6 = 1;
          return;
        }
      }
      uVar5 = DAT_EXTMEM_0fb6;
      bVar8 = DAT_EXTMEM_09ed;
      bVar7 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
      puVar11 = (undefined1 *)
                CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) - (((0xf2 < bVar7) << 7) >> 7),
                         bVar7 + 0xd);
      *puVar11 = DAT_EXTMEM_0fb5;
      puVar11[1] = uVar5;
      bVar7 = bVar8 * '\x03';
      uVar3 = *(undefined2 *)CONCAT11('\t' - (((0xe < bVar7) << 7) >> 7),bVar7 - 0xf);
      bVar10 = (byte)uVar3;
      sVar2 = (ushort)bVar8 * 2;
      bVar8 = (byte)sVar2;
      bVar7 = 1;
      cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)sVar2 >> 8) - (((0xf2 < bVar8) << 7) >> 7),
                                       bVar8 + 0xd));
      DAT_EXTMEM_0fa0 =
           *(char *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                     ((CARRY1(bVar10,bVar7) << 7) >> 7)),bVar10 + bVar7);
      while (DAT_EXTMEM_0fa0 != '\0') {
        if ((((_3_3 == '\x01') || (_3_1 == '\x01')) || (_3_0 == '\x01')) ||
           (((DAT_EXTMEM_0710 == '\0' && (DAT_EXTMEM_09bc == BANK0_R6)) &&
            ((DAT_EXTMEM_0964 == '\x02' && (cVar9 = DAT_EXTMEM_06f5, DAT_EXTMEM_09ed == 0)))))) {
          FUN_CODE_6f7e(cVar9,DAT_EXTMEM_0fa0);
        }
        DAT_EXTMEM_0fad = DAT_EXTMEM_0f8a;
        DAT_EXTMEM_0fbc = DAT_EXTMEM_0f9d;
        DAT_EXTMEM_0fbd = DAT_EXTMEM_0f9e;
        cVar9 = DAT_EXTMEM_0f99;
        FUN_CODE_46f4(DAT_EXTMEM_0f9b,DAT_EXTMEM_0f9c,DAT_EXTMEM_0fa0,DAT_EXTMEM_0f98);
        bVar1 = CARRY1(DAT_EXTMEM_0f9c,DAT_EXTMEM_0f9f + cVar9);
        DAT_EXTMEM_0f9c = DAT_EXTMEM_0f9c + DAT_EXTMEM_0f9f + cVar9;
        DAT_EXTMEM_0f9b = DAT_EXTMEM_0f9b - ((bVar1 << 7) >> 7);
        FUN_CODE_6ecb(DAT_EXTMEM_0fad);
        uVar3 = *(undefined2 *)
                 CONCAT11('\t' - (((0xe < DAT_EXTMEM_09ed * '\x03') << 7) >> 7),
                          DAT_EXTMEM_09ed * '\x03' - 0xf);
        bVar10 = (byte)uVar3;
        bVar8 = (byte)((ushort)DAT_EXTMEM_09ed * 2);
        bVar7 = 1;
        cVar9 = FUN_CODE_750b(0,CONCAT11((char)((ushort)DAT_EXTMEM_09ed * 2 >> 8) -
                                         (((0xf2 < bVar8) << 7) >> 7),bVar8 + 0xd));
        DAT_EXTMEM_0fa0 =
             *(char *)CONCAT11(cVar9 + ((char)((ushort)uVar3 >> 8) -
                                       ((CARRY1(bVar10,bVar7) << 7) >> 7)),bVar10 + bVar7);
      }
      _3_3 = 0;
      _3_1 = 0;
      _3_0 = 0;
      return;
    }
  }
  return;
}



// ==== FUN_CODE_46f4 @ CODE:46f4  (563 bytes)

undefined1
FUN_CODE_46f4(char param_1,byte param_2,char param_3,undefined1 param_4,undefined1 param_5)

{
  bool bVar1;
  undefined2 uVar2;
  char cVar3;
  byte bVar4;
  byte *pbVar5;
  short sVar6;
  byte bVar9;
  char *pcVar7;
  undefined1 *puVar8;
  
  bVar4 = (byte)((ushort)DAT_EXTMEM_0a0d * 9);
  DAT_EXTMEM_0fc9 = bVar4 + 0x40;
  DAT_EXTMEM_0fc8 = (char)((ushort)DAT_EXTMEM_0a0d * 9 >> 8) + ('\b' - (((0xbf < bVar4) << 7) >> 7))
  ;
  DAT_EXTMEM_0fb7 = param_4;
  DAT_EXTMEM_0fb8 = param_5;
  DAT_EXTMEM_0fb9 = param_3;
  DAT_EXTMEM_0fba = param_1;
  DAT_EXTMEM_0fbb = param_2;
  FUN_CODE_6ecb(*(undefined1 *)
                 CONCAT11(DAT_EXTMEM_0fc8 - (((0xf7 < DAT_EXTMEM_0fc9) << 7) >> 7),bVar4 + 0x48));
  bVar4 = ((char *)CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9))[1];
  DAT_EXTMEM_0fc2 =
       DAT_EXTMEM_0fb9 -
       *(char *)CONCAT11(*(char *)CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9) -
                         (((0xf0 < bVar4) << 7) >> 7),bVar4 + 0xf);
  pbVar5 = *(byte **)(CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9) + 2);
  FUN_CODE_7587(DAT_EXTMEM_0fc2,3);
  bVar4 = *pbVar5;
  DAT_EXTMEM_0fc7 = bVar4;
  FUN_CODE_3aa0(0);
  sVar6 = *(short *)(CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9) + 2);
  DAT_EXTMEM_0fc3 = bVar4;
  FUN_CODE_7587(DAT_EXTMEM_0fc2,3);
  DAT_EXTMEM_0fc5 = *(byte *)(sVar6 + 2);
  cVar3 = '\x03';
  bVar4 = *(byte *)(sVar6 + 1);
  do {
    DAT_EXTMEM_0fc4 = bVar4 >> 1;
    DAT_EXTMEM_0fc5 = DAT_EXTMEM_0fc5 >> 1 | bVar4 << 7;
    cVar3 = cVar3 + -1;
    bVar4 = DAT_EXTMEM_0fc4;
  } while (cVar3 != '\0');
  for (DAT_EXTMEM_0fbe = 0; bVar4 = ((char *)CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9))[1],
      (DAT_EXTMEM_0fbe <
      *(byte *)CONCAT11(*(char *)CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9) -
                        (((0xf2 < bVar4) << 7) >> 7),bVar4 + 0xd)) << 7 < '\0';
      DAT_EXTMEM_0fbe = DAT_EXTMEM_0fbe + 1) {
    DAT_EXTMEM_0fc1 = DAT_EXTMEM_0fc7;
    for (DAT_EXTMEM_0fbf = 0; (DAT_EXTMEM_0fbf < DAT_EXTMEM_0fc3) << 7 < '\0';
        DAT_EXTMEM_0fbf = DAT_EXTMEM_0fbf + 1) {
      uVar2 = *(undefined2 *)
               CONCAT11(DAT_EXTMEM_0fc8 - (((0xf9 < DAT_EXTMEM_0fc9) << 7) >> 7),DAT_EXTMEM_0fc9 + 6
                       );
      bVar9 = (byte)uVar2;
      bVar4 = DAT_EXTMEM_0fc5 + bVar9;
      DAT_EXTMEM_0fc6 =
           *(byte *)CONCAT11((DAT_EXTMEM_0fc4 +
                             ((char)((ushort)uVar2 >> 8) -
                             ((CARRY1(DAT_EXTMEM_0fc5,bVar9) << 7) >> 7))) -
                             ((CARRY1(bVar4,DAT_EXTMEM_0fbf) << 7) >> 7),bVar4 + DAT_EXTMEM_0fbf);
      DAT_EXTMEM_0fc0 = 0;
      while( true ) {
        bVar4 = DAT_EXTMEM_0fc1;
        if (8 < DAT_EXTMEM_0fc1) {
          bVar4 = BANK0_R6;
        }
        if (bVar4 <= DAT_EXTMEM_0fc0) break;
        if ((DAT_EXTMEM_0fc6 &
            *(byte *)CONCAT11((((7 < DAT_EXTMEM_0fc0) << 7) >> 7) +
                              ('\x0f' - (((0xa0 < -DAT_EXTMEM_0fc0 + 7) << 7) >> 7)),
                              -DAT_EXTMEM_0fc0 + 'f')) != 0) {
          bVar4 = DAT_EXTMEM_0fc0 + DAT_EXTMEM_0fbf * '\b';
          DAT_EXTMEM_0fd0 = 1;
          FUN_CODE_4927(DAT_EXTMEM_0fbc - ((CARRY1(DAT_EXTMEM_0fbd,DAT_EXTMEM_0fbe) << 7) >> 7),
                        DAT_EXTMEM_0fbd + DAT_EXTMEM_0fbe,
                        DAT_EXTMEM_0fba - ((CARRY1(DAT_EXTMEM_0fbb,bVar4) << 7) >> 7),
                        DAT_EXTMEM_0fbb + bVar4,DAT_EXTMEM_0fb7,DAT_EXTMEM_0fb8);
        }
        DAT_EXTMEM_0fc0 = DAT_EXTMEM_0fc0 + 1;
      }
      DAT_EXTMEM_0fc1 = DAT_EXTMEM_0fc1 - 8;
    }
    bVar4 = ((char *)CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9))[1];
    pcVar7 = (char *)CONCAT11(*(char *)CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9) -
                              (((0xe3 < bVar4) << 7) >> 7),bVar4 + 0x1c);
    bVar4 = pcVar7[1];
    bVar1 = CARRY1(DAT_EXTMEM_0fc5,bVar4);
    DAT_EXTMEM_0fc5 = DAT_EXTMEM_0fc5 + bVar4;
    DAT_EXTMEM_0fc4 = DAT_EXTMEM_0fc4 + (*pcVar7 - ((bVar1 << 7) >> 7));
  }
  puVar8 = *(undefined1 **)(CONCAT11(DAT_EXTMEM_0fc8,DAT_EXTMEM_0fc9) + 2);
  FUN_CODE_7587(DAT_EXTMEM_0fc2,3);
  return *puVar8;
}



// ==== FUN_CODE_4927 @ CODE:4927  (282 bytes)

byte FUN_CODE_4927(byte param_1,byte param_2,byte param_3,byte param_4,char param_5,byte param_6)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined2 uStack_1;
  
  bVar3 = (param_3 ^ 0x80) + 0x80;
  DAT_EXTMEM_0fca = param_5;
  DAT_EXTMEM_0fcb = param_6;
  DAT_EXTMEM_0fcc = param_3;
  DAT_EXTMEM_0fcd = param_4;
  if (((0x7f < (param_3 ^ 0x80)) && (bVar3 = (param_1 ^ 0x80) + 0x80, 0x7f < (param_1 ^ 0x80))) &&
     (bVar1 = 0x80 - (((param_4 < DAT_EXTMEM_09b5) << 7) >> 7), bVar3 = (param_3 ^ 0x80) - bVar1,
     ((param_3 ^ 0x80) < bVar1) << 7 < '\0')) {
    if ((DAT_EXTMEM_09bf < DAT_EXTMEM_09be) << 7 < '\0') {
      DAT_EXTMEM_0fd4 = DAT_EXTMEM_09be;
    }
    else {
      DAT_EXTMEM_0fd4 = DAT_EXTMEM_09bf;
    }
    bVar1 = 0x80 - (((param_2 < DAT_EXTMEM_0fd4) << 7) >> 7);
    bVar3 = (param_1 ^ 0x80) - bVar1;
    if (((param_1 ^ 0x80) < bVar1) << 7 < '\0') {
      DAT_EXTMEM_0fd3 = param_4 & 7;
      cVar2 = '\0';
      bVar3 = BANK0_R3;
      FUN_CODE_74ab(param_4,DAT_EXTMEM_083e,DAT_EXTMEM_083f);
      DAT_EXTMEM_0fd2 = (BANK0_R1 >> 3) + bVar3;
      DAT_EXTMEM_0fd1 = cVar2 - ((CARRY1(BANK0_R1 >> 3,bVar3) << 7) >> 7);
      if (DAT_EXTMEM_0fd0 != '\0') {
        cVar2 = DAT_EXTMEM_0fd1 +
                (DAT_EXTMEM_0fca - ((CARRY1(DAT_EXTMEM_0fcb,DAT_EXTMEM_0fd2) << 7) >> 7));
        uStack_1 = (byte *)CONCAT11(cVar2,DAT_EXTMEM_0fcb + DAT_EXTMEM_0fd2);
        bVar3 = *(byte *)CONCAT11(cVar2,DAT_EXTMEM_0fcb + DAT_EXTMEM_0fd2) |
                *(byte *)CONCAT11((((7 < DAT_EXTMEM_0fd3) << 7) >> 7) +
                                  ('\x0f' - (((0xa0 < -DAT_EXTMEM_0fd3 + 7) << 7) >> 7)),
                                  -DAT_EXTMEM_0fd3 + 'f');
        *uStack_1 = bVar3;
        return bVar3;
      }
      cVar2 = DAT_EXTMEM_0fd1 +
              (DAT_EXTMEM_0fca - ((CARRY1(DAT_EXTMEM_0fcb,DAT_EXTMEM_0fd2) << 7) >> 7));
      uStack_1 = (byte *)CONCAT11(cVar2,DAT_EXTMEM_0fcb + DAT_EXTMEM_0fd2);
      bVar3 = *(byte *)CONCAT11(cVar2,DAT_EXTMEM_0fcb + DAT_EXTMEM_0fd2) &
              ~*(byte *)CONCAT11((((7 < DAT_EXTMEM_0fd3) << 7) >> 7) +
                                 ('\x0f' - (((0xa0 < -DAT_EXTMEM_0fd3 + 7) << 7) >> 7)),
                                 -DAT_EXTMEM_0fd3 + 'f');
      *uStack_1 = bVar3;
    }
  }
  return bVar3;
}



// ==== FUN_CODE_4a41 @ CODE:4a41  (1571 bytes)

char FUN_CODE_4a41(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  undefined2 uStack_1;
  
  DAT_EXTMEM_0f95 = 0;
  do {
    *(undefined1 *)CONCAT11('\x0f' - (((0x60 < DAT_EXTMEM_0f95) << 7) >> 7),DAT_EXTMEM_0f95 + 0x9f)
         = *(undefined1 *)CONCAT11('\x06' - (((4 < DAT_EXTMEM_0f95) << 7) >> 7),DAT_EXTMEM_0f95 - 5)
    ;
    DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1;
  } while (DAT_EXTMEM_0f95 != 10);
  bVar3 = 10;
  if ((DAT_EXTMEM_0710 == '\0') && (DAT_EXTMEM_09bc == DAT_EXTMEM_06f5)) {
    _5_0 = 0;
    FUN_CODE_7002(7,4);
    _5_1 = '\0';
    for (DAT_EXTMEM_0f95 = 4; DAT_EXTMEM_0f95 < 7; DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1) {
      bVar3 = *(byte *)CONCAT11('\x0f' - (((100 < DAT_EXTMEM_0f95) << 7) >> 7),
                                DAT_EXTMEM_0f95 + 0x9b);
      cVar5 = (bVar3 < 0x30) << 7;
      if (((bVar3 != 0x30) || (_5_1 != '\0')) && (FUN_CODE_000e(bVar3), cVar5 < '\0')) {
        *(undefined1 *)CONCAT11(-(((0x18 < DAT_EXTMEM_0f95) << 7) >> 7),DAT_EXTMEM_0f95 - 0x19) =
             *(undefined1 *)
              CONCAT11('\x0f' - (((100 < DAT_EXTMEM_0f95) << 7) >> 7),DAT_EXTMEM_0f95 + 0x9b);
        _5_1 = '\x01';
        _5_0 = 1;
      }
    }
    DAT_EXTMEM_00ee = 0x20;
    bVar3 = DAT_EXTMEM_0f95;
  }
  DAT_EXTMEM_0f95 = bVar3;
  _5_1 = '\0';
  DAT_EXTMEM_0f9a = 0;
  DAT_EXTMEM_0f9b = '\0';
  DAT_EXTMEM_0a0d = DAT_EXTMEM_000a;
  DAT_EXTMEM_0f98 = 0;
  DAT_EXTMEM_0f99 = '\0';
  DAT_EXTMEM_0f96 = '\0';
  DAT_EXTMEM_0f97 = 0;
  DAT_EXTMEM_0f9c = 0;
  DAT_EXTMEM_0f9d = 0;
  DAT_EXTMEM_0faa = 0;
  if (DAT_EXTMEM_09b7 != 0 || DAT_EXTMEM_09b6 != 0) {
    if (DAT_EXTMEM_09b6 < (byte)-(((DAT_EXTMEM_09b7 < 10) << 7) >> 7)) {
      DAT_EXTMEM_0f9d = 1;
    }
    else if (DAT_EXTMEM_09b6 < (byte)-(((DAT_EXTMEM_09b7 < 100) << 7) >> 7)) {
      DAT_EXTMEM_0f9d = 2;
    }
    else if (DAT_EXTMEM_09b6 < 3U - (((DAT_EXTMEM_09b7 < 0xe8) << 7) >> 7)) {
      DAT_EXTMEM_0f9d = 3;
    }
    else if (DAT_EXTMEM_09b6 < 0x27U - (((DAT_EXTMEM_09b7 < 0x10) << 7) >> 7)) {
      DAT_EXTMEM_0f9d = 4;
    }
  }
  FUN_CODE_6ecb(DAT_EXTMEM_081b);
  if (((DAT_EXTMEM_0815 == '\0') && (DAT_EXTMEM_0819 == '\0')) &&
     ((DAT_EXTMEM_0818 != '\0' && ((DAT_EXTMEM_081a != '\0' && (0x32 < DAT_EXTMEM_09b0)))))) {
    if (DAT_EXTMEM_09b7 == 0 && DAT_EXTMEM_09b6 == 0) {
      DAT_EXTMEM_0f96 = '\0';
      DAT_EXTMEM_0f97 = 0;
      DAT_EXTMEM_0f9c = 0;
    }
    else if (DAT_EXTMEM_09b6 < (byte)-(((DAT_EXTMEM_09b7 < 10) << 7) >> 7)) {
      DAT_EXTMEM_0f97 =
           *(byte *)CONCAT11('\x01' - (((0xd5 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d + 0x2a)
      ;
      DAT_EXTMEM_0f96 = '\0';
      DAT_EXTMEM_0f9c = 0;
    }
    else if (DAT_EXTMEM_09b6 < (byte)-(((DAT_EXTMEM_09b7 < 100) << 7) >> 7)) {
      DAT_EXTMEM_0f97 =
           *(byte *)CONCAT11('\x01' - (((0xd5 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d + 0x2a)
      ;
      DAT_EXTMEM_0f96 = '\0';
      DAT_EXTMEM_0f9c =
           *(byte *)CONCAT11('\t' - (((0x28 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d - 0x29);
    }
    else if (DAT_EXTMEM_09b6 < 3U - (((DAT_EXTMEM_09b7 < 0xe8) << 7) >> 7)) {
      DAT_EXTMEM_0f97 =
           *(byte *)CONCAT11('\x01' - (((0xd5 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d + 0x2a)
      ;
      DAT_EXTMEM_0f96 = '\0';
      DAT_EXTMEM_0f9c =
           *(byte *)CONCAT11('\t' - (((0x28 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d - 0x29);
    }
    else if ((DAT_EXTMEM_09b6 < 0x27U - (((DAT_EXTMEM_09b7 < 0x10) << 7) >> 7)) << 7 < '\0') {
      DAT_EXTMEM_0f97 =
           *(byte *)CONCAT11('\x01' - (((0xd5 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d + 0x2a)
      ;
      DAT_EXTMEM_0f96 = '\0';
      DAT_EXTMEM_0f9c =
           *(byte *)CONCAT11('\t' - (((0x28 < DAT_EXTMEM_0f9d) << 7) >> 7),DAT_EXTMEM_0f9d - 0x29);
    }
  }
  else if (((((DAT_EXTMEM_0815 == '\0') << 7 < '\0') || ((DAT_EXTMEM_0819 == '\0') << 7 < '\0')) ||
           ((DAT_EXTMEM_0818 == '\0') << 7 < '\0')) || ((DAT_EXTMEM_081a == '\0') << 7 < '\0')) {
    if (((DAT_EXTMEM_0815 == '\0') && (DAT_EXTMEM_0819 == '\0')) &&
       ((DAT_EXTMEM_0818 != '\0' && ((DAT_EXTMEM_081a != '\0' && (DAT_EXTMEM_09b0 < 0x32)))))) {
      bVar3 = DAT_EXTMEM_09b0;
      bVar4 = DAT_EXTMEM_0015;
      cVar5 = DAT_EXTMEM_0014;
      FUN_CODE_7587(DAT_EXTMEM_0a0d,0x10);
      if (*(char *)CONCAT11(cVar5 + ('\x02' - (((0xf < bVar4) << 7) >> 7)),bVar4 - 0x10) == '\x13')
      {
        DAT_EXTMEM_0f98 = 0;
        DAT_EXTMEM_0f99 = '\x01';
      }
      DAT_EXTMEM_0faa = bVar3;
    }
  }
  else {
    bVar3 = DAT_EXTMEM_0015;
    cVar5 = DAT_EXTMEM_0014;
    FUN_CODE_7587(DAT_EXTMEM_0a0d,0x10);
    if (*(char *)CONCAT11(cVar5 + ('\x02' - (((0xf < bVar3) << 7) >> 7)),bVar3 - 0x10) == '\x13') {
      DAT_EXTMEM_0f98 = 0;
      DAT_EXTMEM_0f99 = '\x01';
    }
    DAT_EXTMEM_0faa = DAT_EXTMEM_09ac;
  }
  if ((((DAT_EXTMEM_0815 == '\0') && (DAT_EXTMEM_0819 == '\0')) && (DAT_EXTMEM_0818 != '\0')) &&
     ((DAT_EXTMEM_081a != '\0' && (0x32 < DAT_EXTMEM_09b0)))) {
    DAT_EXTMEM_0f9e =
         DAT_EXTMEM_0447 +
         (DAT_EXTMEM_0117 + -1) * DAT_EXTMEM_0f9c +
         DAT_EXTMEM_0117 * DAT_EXTMEM_0454 + DAT_EXTMEM_0f97;
    for (DAT_EXTMEM_0f95 = 0; DAT_EXTMEM_0f95 < DAT_EXTMEM_09af;
        DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1) {
      cVar5 = *(char *)CONCAT11('\x0f' - (((0x60 < DAT_EXTMEM_0f95) << 7) >> 7),
                                DAT_EXTMEM_0f95 + 0x9f);
      if ((cVar5 != '0') || (_5_1 != '\0')) {
        DAT_EXTMEM_0fa9 = DAT_EXTMEM_0f8a;
        DAT_EXTMEM_0fbc = DAT_EXTMEM_0f98;
        DAT_EXTMEM_0fbd = DAT_EXTMEM_0f99;
        cVar2 = DAT_EXTMEM_0f99;
        FUN_CODE_46f4(DAT_EXTMEM_0f96,DAT_EXTMEM_0f97,cVar5,10);
        bVar1 = CARRY1(DAT_EXTMEM_0f97,DAT_EXTMEM_0f9c + cVar2);
        DAT_EXTMEM_0f97 = DAT_EXTMEM_0f97 + DAT_EXTMEM_0f9c + cVar2;
        DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 - ((bVar1 << 7) >> 7);
        FUN_CODE_6ecb(DAT_EXTMEM_0fa9);
        _5_1 = '\x01';
      }
    }
    DAT_EXTMEM_0f9b = DAT_EXTMEM_0f9e - (DAT_EXTMEM_0f97 + 1);
    DAT_EXTMEM_0f9a =
         -((DAT_EXTMEM_0f96 - (((0xfe < DAT_EXTMEM_0f97) << 7) >> 7)) -
          (((DAT_EXTMEM_0f9e < DAT_EXTMEM_0f97 + 1) << 7) >> 7));
  }
  else if (((((DAT_EXTMEM_0815 != '\0') && (DAT_EXTMEM_0819 != '\0')) && (DAT_EXTMEM_0818 != '\0'))
           && (DAT_EXTMEM_081a != '\0')) ||
          (((DAT_EXTMEM_0815 == '\0' && (DAT_EXTMEM_0819 == '\0')) &&
           ((DAT_EXTMEM_0818 != '\0' && ((DAT_EXTMEM_081a != '\0' && (DAT_EXTMEM_09b0 < 0x32))))))))
  {
    for (DAT_EXTMEM_0f95 = 0; bVar3 = DAT_EXTMEM_0f97, DAT_EXTMEM_0f95 < DAT_EXTMEM_09af;
        DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1) {
      cVar5 = *(char *)CONCAT11('\x0f' - (((0x60 < DAT_EXTMEM_0f95) << 7) >> 7),
                                DAT_EXTMEM_0f95 + 0x9f);
      if ((cVar5 != '0') || (_5_1 != '\0')) {
        DAT_EXTMEM_0fa9 = DAT_EXTMEM_0f8a;
        DAT_EXTMEM_0fbc = DAT_EXTMEM_0f98;
        DAT_EXTMEM_0fbd = DAT_EXTMEM_0f99;
        cVar2 = DAT_EXTMEM_0f99;
        FUN_CODE_46f4(DAT_EXTMEM_0f96,DAT_EXTMEM_0f97,cVar5,10);
        bVar1 = CARRY1(DAT_EXTMEM_0f97,DAT_EXTMEM_0f9c + cVar2);
        DAT_EXTMEM_0f97 = DAT_EXTMEM_0f97 + DAT_EXTMEM_0f9c + cVar2;
        DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 - ((bVar1 << 7) >> 7);
        FUN_CODE_6ecb(DAT_EXTMEM_0fa9);
        _5_1 = '\x01';
      }
    }
    for (DAT_EXTMEM_0f95 = 1; DAT_EXTMEM_0f95 < 4; DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1) {
      bVar4 = (DAT_EXTMEM_0f9d - 1) * DAT_EXTMEM_0f95 + bVar3;
      if (DAT_EXTMEM_0faa + 1 <= bVar4) {
        if (DAT_EXTMEM_0f95 == 1) {
          DAT_EXTMEM_0f96 = '\0';
          DAT_EXTMEM_0f97 = 0;
          DAT_EXTMEM_0f9c = 0;
        }
        break;
      }
      DAT_EXTMEM_0f97 = DAT_EXTMEM_0faa - bVar4 >> 1;
      DAT_EXTMEM_0f96 = '\0';
      DAT_EXTMEM_0f9c = DAT_EXTMEM_0f95;
      _5_1 = '\0';
    }
    DAT_EXTMEM_0f93 = 0;
    DAT_EXTMEM_0f94 = 0;
    while (DAT_EXTMEM_0f93 <
           (byte)(DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f94 < DAT_EXTMEM_0017) << 7) >> 7))) {
      bVar3 = 1;
      cVar5 = FUN_CODE_750b(0);
      *(undefined1 *)CONCAT11(cVar5 + ('\n' - (((0xef < bVar3) << 7) >> 7)),bVar3 + 0x10) = 0;
    }
    _5_1 = '\0';
    for (DAT_EXTMEM_0f95 = 0; DAT_EXTMEM_0f95 < DAT_EXTMEM_09af;
        DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1) {
      cVar5 = *(char *)CONCAT11('\x0f' - (((0x60 < DAT_EXTMEM_0f95) << 7) >> 7),
                                DAT_EXTMEM_0f95 + 0x9f);
      if ((cVar5 != '0') || (_5_1 != '\0')) {
        DAT_EXTMEM_0fa9 = DAT_EXTMEM_0f8a;
        DAT_EXTMEM_0fbc = DAT_EXTMEM_0f98;
        DAT_EXTMEM_0fbd = DAT_EXTMEM_0f99;
        cVar2 = DAT_EXTMEM_0f99;
        FUN_CODE_46f4(DAT_EXTMEM_0f96,DAT_EXTMEM_0f97,cVar5,10);
        bVar1 = CARRY1(DAT_EXTMEM_0f97,DAT_EXTMEM_0f9c + cVar2);
        DAT_EXTMEM_0f97 = DAT_EXTMEM_0f97 + DAT_EXTMEM_0f9c + cVar2;
        DAT_EXTMEM_0f96 = DAT_EXTMEM_0f96 - ((bVar1 << 7) >> 7);
        FUN_CODE_6ecb(DAT_EXTMEM_0fa9);
        _5_1 = '\x01';
      }
    }
    DAT_EXTMEM_0f9a = 0;
    DAT_EXTMEM_0f9b = '\0';
  }
  if ((DAT_EXTMEM_0f9a ^ 0x80) < 0x80) {
    DAT_EXTMEM_0f9a = 0;
    DAT_EXTMEM_0f9b = '\0';
  }
  DAT_EXTMEM_0f93 = 0;
  DAT_EXTMEM_0f94 = 0;
  while (DAT_EXTMEM_0f93 <
         (byte)(DAT_EXTMEM_0016 - (((DAT_EXTMEM_0f94 < DAT_EXTMEM_0017) << 7) >> 7))) {
    cVar5 = DAT_EXTMEM_0f93 + ('\x01' - (((0x5b < DAT_EXTMEM_0f94) << 7) >> 7));
    uStack_1 = (byte *)CONCAT11(cVar5,DAT_EXTMEM_0f94 + 0xa4);
    *uStack_1 = *(byte *)CONCAT11(cVar5,DAT_EXTMEM_0f94 + 0xa4) |
                *(byte *)CONCAT11(DAT_EXTMEM_0f93 + ('\n' - (((0xef < DAT_EXTMEM_0f94) << 7) >> 7)),
                                  DAT_EXTMEM_0f94 + 0x10);
    DAT_EXTMEM_0f94 = DAT_EXTMEM_0f94 + 1;
    if (DAT_EXTMEM_0f94 == 0) {
      DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1;
    }
  }
  return DAT_EXTMEM_0f9b;
}



// ==== FUN_CODE_5064 @ CODE:5064  (50 bytes)

void FUN_CODE_5064(void)

{
  return;
}



// ==== FUN_CODE_5096 @ CODE:5096  (82 bytes)

void FUN_CODE_5096(void)

{
  return;
}



// ==== FUN_CODE_50e8 @ CODE:50e8  (436 bytes)

void FUN_CODE_50e8(byte param_1)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  char *pcVar6;
  
  DAT_EXTMEM_0a0e = 10;
  DAT_EXTMEM_0a0f = 0x10;
  DAT_EXTMEM_0f56 = '\n';
  DAT_EXTMEM_0f57 = '\x10';
  DAT_EXTMEM_09f9 = FUN_CODE_744a(2,0x10,10,1);
  DAT_EXTMEM_0a09 = FUN_CODE_744a(3);
  DAT_EXTMEM_0f69 = FUN_CODE_7521(4);
  DAT_EXTMEM_0f68 = param_1;
  bVar3 = FUN_CODE_7521(6);
  bVar4 = param_1;
  DAT_EXTMEM_0f5d = param_1;
  DAT_EXTMEM_0f5e = bVar3;
  DAT_EXTMEM_0a04 = FUN_CODE_7521(8);
  DAT_EXTMEM_0a03 = bVar4;
  DAT_EXTMEM_0a00 = FUN_CODE_744a(10);
  DAT_EXTMEM_0f67 = FUN_CODE_744a(0xb);
  DAT_EXTMEM_0a02 = FUN_CODE_744a(0xc);
  bVar4 = DAT_EXTMEM_0f69 ^ ~bVar3;
  if (bVar4 == 0) {
    bVar4 = ~param_1 ^ DAT_EXTMEM_0f68;
  }
  if (bVar4 != 0) {
    return;
  }
  if (DAT_EXTMEM_09f9 == '\0') {
    bVar4 = DAT_EXTMEM_09bc ^ DAT_EXTMEM_0f69;
    if ((DAT_EXTMEM_09bc ^ DAT_EXTMEM_0f69) == 0) {
      bVar4 = DAT_EXTMEM_0f68;
    }
    if (bVar4 != 0) {
      return;
    }
  }
  else {
    pbVar5 = (byte *)CONCAT11('\x0f' - (((0x95 < DAT_EXTMEM_09bc * '\x02') << 7) >> 7),
                              DAT_EXTMEM_09bc * '\x02' + 0x6a);
    if ((DAT_EXTMEM_0f69 & pbVar5[1]) == 0 && (DAT_EXTMEM_0f68 & *pbVar5) == 0) {
      return;
    }
  }
  bVar4 = DAT_EXTMEM_0a03 ^ DAT_EXTMEM_000b;
  if (bVar4 == 0) {
    bVar4 = DAT_EXTMEM_0a04 ^ DAT_EXTMEM_000c;
  }
  if (bVar4 != 0) {
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0xe
    ;
    cVar1 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar1;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    return;
  }
  cVar1 = DAT_EXTMEM_0f56;
  cVar2 = DAT_EXTMEM_0f57;
  FUN_CODE_537a();
  if (cVar2 != '\0' || cVar1 != '\0') {
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 2;
    cVar1 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar1;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    return;
  }
  if (DAT_EXTMEM_0a09 < 0x20) {
    return;
  }
  FUN_CODE_529c(DAT_EXTMEM_0a09 - 0x20,0,0x16,0xf);
  *(undefined1 *)
   CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0xb;
  cVar1 = DAT_EXTMEM_0f5b;
  bVar4 = DAT_EXTMEM_0f5c;
  FUN_CODE_537a();
  pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                            DAT_EXTMEM_0f5c + 0x12);
  *pcVar6 = cVar1;
  pcVar6[1] = bVar4;
  FUN_CODE_54a5();
  return;
}



// ==== FUN_CODE_529c @ CODE:529c  (222 bytes)

void FUN_CODE_529c(byte param_1,byte param_2,undefined1 param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined1 *puVar6;
  
  DAT_EXTMEM_0f50 = 0;
  DAT_EXTMEM_0f51 = 0xe7;
  DAT_EXTMEM_0f5b = '\0';
  DAT_EXTMEM_0f5c = 0xe7;
  DAT_EXTMEM_0fb0 = param_3;
  DAT_EXTMEM_0fb1 = param_1;
  DAT_EXTMEM_0fb2 = param_2;
  FUN_CODE_7477(0x7a,0xe7,0,1);
  FUN_CODE_7489(0x5c,1);
  FUN_CODE_7489(0,2);
  FUN_CODE_7489(DAT_EXTMEM_0fb0,3);
  FUN_CODE_7559(4,0);
  FUN_CODE_7559(6,0xff);
  bVar3 = DAT_EXTMEM_0fb1;
  bVar4 = DAT_EXTMEM_0fb2;
  FUN_CODE_7559(DAT_EXTMEM_0fb1,8,DAT_EXTMEM_0fb2);
  FUN_CODE_7489(8,10);
  FUN_CODE_7489(DAT_EXTMEM_09bc,0xb);
  FUN_CODE_7489(DAT_EXTMEM_0f55,0xc);
  FUN_CODE_7489(0,0xd);
  FUN_CODE_7489(0,0xe);
  FUN_CODE_7489(0,0xf);
  bVar2 = DAT_EXTMEM_0f5c;
  cVar1 = DAT_EXTMEM_0f5b;
  bVar4 = bVar4 >> 1 | bVar3 << 7;
  bVar5 = bVar4 - 2;
  puVar6 = (undefined1 *)
           CONCAT11((((bVar3 >> 1) + (-1 - (((1 < bVar4) << 7) >> 7))) * '\x02' |
                    CARRY1(bVar5,bVar5)) +
                    (DAT_EXTMEM_0f5b - ((CARRY1(DAT_EXTMEM_0f5c,bVar5 * '\x02') << 7) >> 7)),
                    DAT_EXTMEM_0f5c + bVar5 * '\x02');
  *puVar6 = 0;
  puVar6[1] = 0;
  bVar5 = bVar4 - 1;
  puVar6 = (undefined1 *)
           CONCAT11((((bVar3 >> 1) + (-1 - (((bVar4 != 0) << 7) >> 7))) * '\x02' |
                    CARRY1(bVar5,bVar5)) + (cVar1 - ((CARRY1(bVar2,bVar5 * '\x02') << 7) >> 7)),
                    bVar2 + bVar5 * '\x02');
  *puVar6 = 0xd;
  puVar6[1] = 10;
  return;
}



// ==== FUN_CODE_537a @ CODE:537a  (151 bytes)

byte FUN_CODE_537a(void)

{
  byte bVar1;
  byte *pbVar2;
  
  DAT_EXTMEM_0fb0 = 0xff;
  DAT_EXTMEM_0fb1 = 0xff;
  DAT_EXTMEM_0fb2 = 0;
  DAT_EXTMEM_0fb3 = 0;
  pbVar2 = (byte *)CONCAT11(BANK0_R6 - (((0xf7 < BANK0_R7) << 7) >> 7),BANK0_R7 + 8);
  bVar1 = *pbVar2;
  DAT_EXTMEM_0fb4 = bVar1 >> 1;
  DAT_EXTMEM_0fb5 = pbVar2[1] >> 1 | bVar1 << 7;
  DAT_EXTMEM_0fb6 = 0;
  DAT_EXTMEM_0fb7 = 0;
  while (DAT_EXTMEM_0fb6 < DAT_EXTMEM_0fb4 - (((DAT_EXTMEM_0fb7 < DAT_EXTMEM_0fb5) << 7) >> 7)) {
    pbVar2 = (byte *)CONCAT11((DAT_EXTMEM_0fb6 << 1 | CARRY1(DAT_EXTMEM_0fb7,DAT_EXTMEM_0fb7)) +
                              (BANK0_R6 - ((CARRY1(BANK0_R7,DAT_EXTMEM_0fb7 * '\x02') << 7) >> 7)),
                              BANK0_R7 + DAT_EXTMEM_0fb7 * '\x02');
    DAT_EXTMEM_0fb0 = DAT_EXTMEM_0fb0 ^ *pbVar2;
    DAT_EXTMEM_0fb1 = DAT_EXTMEM_0fb1 ^ pbVar2[1];
    DAT_EXTMEM_0fb7 = DAT_EXTMEM_0fb7 + 1;
    if (DAT_EXTMEM_0fb7 == 0) {
      DAT_EXTMEM_0fb6 = DAT_EXTMEM_0fb6 + 1;
    }
  }
  return DAT_EXTMEM_0fb1;
}



// ==== FUN_CODE_5411 @ CODE:5411  (148 bytes)

byte FUN_CODE_5411(char param_1,byte param_2)

{
  byte bVar1;
  byte *pbVar2;
  
  DAT_EXTMEM_0fb0 = 0xff;
  DAT_EXTMEM_0fb1 = 0xff;
  DAT_EXTMEM_0fae = param_1;
  DAT_EXTMEM_0faf = param_2;
  check_FORM_header(param_1);
  if (param_2 == 1) {
    pbVar2 = (byte *)CONCAT11(DAT_EXTMEM_0fae - (((0xeb < DAT_EXTMEM_0faf) << 7) >> 7),
                              DAT_EXTMEM_0faf + 0x14);
    bVar1 = *pbVar2;
    DAT_EXTMEM_0fb2 = bVar1 >> 1;
    DAT_EXTMEM_0fb3 = pbVar2[1] >> 1 | bVar1 << 7;
    DAT_EXTMEM_0fb4 = 0;
    DAT_EXTMEM_0fb5 = 0;
    while (DAT_EXTMEM_0fb4 < DAT_EXTMEM_0fb2 - (((DAT_EXTMEM_0fb5 < DAT_EXTMEM_0fb3) << 7) >> 7)) {
      bVar1 = T1;
      T1 = bVar1 ^ 1;
      pbVar2 = (byte *)CONCAT11((DAT_EXTMEM_0fb4 << 1 | CARRY1(DAT_EXTMEM_0fb5,DAT_EXTMEM_0fb5)) +
                                (DAT_EXTMEM_0fae -
                                ((CARRY1(DAT_EXTMEM_0faf,DAT_EXTMEM_0fb5 * '\x02') << 7) >> 7)),
                                DAT_EXTMEM_0faf + DAT_EXTMEM_0fb5 * '\x02');
      DAT_EXTMEM_0fb0 = DAT_EXTMEM_0fb0 ^ *pbVar2;
      DAT_EXTMEM_0fb1 = DAT_EXTMEM_0fb1 ^ pbVar2[1];
      DAT_EXTMEM_0fb5 = DAT_EXTMEM_0fb5 + 1;
      if (DAT_EXTMEM_0fb5 == 0) {
        DAT_EXTMEM_0fb4 = DAT_EXTMEM_0fb4 + 1;
      }
    }
  }
  return DAT_EXTMEM_0fb1;
}



// ==== FUN_CODE_54a5 @ CODE:54a5  (48 bytes)

/* WARNING: Removing unreachable block (CODE,0x54d4) */

void FUN_CODE_54a5(void)

{
  TI = 1;
  do {
  } while( true );
}



// ==== FUN_CODE_54d5 @ CODE:54d5  (4432 bytes)

void FUN_CODE_54d5(char param_1)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  
  FUN_CODE_50e8();
  if (param_1 != '\x01') {
    return;
  }
  cVar3 = *(char *)(CONCAT11(DAT_EXTMEM_0a0e,DAT_EXTMEM_0a0f) + 3);
  if (cVar3 != '\x11') {
    _2_7 = '\0';
  }
  if (0x13 < cVar3 - 1U) {
    return;
  }
                    /* WARNING: Switch is manually overridden */
  switch((cVar3 - 1U) * '\x03') {
  case 0:
    FUN_CODE_529c(0,0x14,2);
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xef < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x10);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    LATCH3_7SEG_802_15 = 0x89;
    return;
  case 3:
    break;
  case 6:
    break;
  case 9:
    break;
  case 0xc:
    FUN_CODE_6625();
    return;
  case 0xf:
    break;
  case 0x12:
    break;
  case 0x15:
    DAT_EXTMEM_0f99 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_0a0e - (((0xef < DAT_EXTMEM_0a0f) << 7) >> 7),DAT_EXTMEM_0a0f + 0x10);
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0;
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    FUN_CODE_6700(DAT_EXTMEM_0f99);
    return;
  case 0x18:
    break;
  case 0x1b:
    break;
  case 0x1e:
    DAT_EXTMEM_0f55 =
         *(byte *)CONCAT11(DAT_EXTMEM_0a0e - (((0xef < DAT_EXTMEM_0a0f) << 7) >> 7),
                           DAT_EXTMEM_0a0f + 0x10);
    DAT_EXTMEM_0a01 = ~DAT_EXTMEM_0f55;
    return;
  case 0x21:
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0;
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    FUN_CODE_6700(0);
    FUN_CODE_6be2();
    LATCH3_7SEG_802_15 = 199;
    _1_7 = 1;
    _0_6 = 1;
    if ((DAT_EXTMEM_09e5 ^ 2) == 0) {
      DAT_EXTMEM_09e5 = DAT_EXTMEM_09e5 ^ 2;
      return;
    }
    break;
  case 0x24:
    break;
  case 0x27:
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) =
         DAT_EXTMEM_0a08;
    DAT_EXTMEM_0a08 = 0;
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    return;
  case 0x2a:
    break;
  case 0x2d:
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 1;
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    return;
  case 0x30:
    DAT_EXTMEM_0f9a = '\0';
    if (_2_7 == '\x01') {
      if (DAT_EXTMEM_09e6 !=
          *(char *)CONCAT11(DAT_EXTMEM_0a0e - (((0xef < DAT_EXTMEM_0a0f) << 7) >> 7),
                            DAT_EXTMEM_0a0f + 0x10)) {
        DAT_EXTMEM_0f9a = '\x04';
      }
      if (DAT_EXTMEM_0f9a == '\0') {
        pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f56 - (((0xed < DAT_EXTMEM_0f57) << 7) >> 7),
                                  DAT_EXTMEM_0f57 + 0x12);
        DAT_EXTMEM_0f9b = *pcVar6;
        DAT_EXTMEM_0f9c = pcVar6[1];
        FUN_CODE_6ecb(DAT_EXTMEM_09e7);
        if (DAT_EXTMEM_0750 == 2) {
          DAT_EXTMEM_09d3 = 0x4e;
          DAT_EXTMEM_09d4 = 0x20;
          DAT_EXTMEM_0f94 = 0;
          DAT_EXTMEM_0f95 = 0;
          while ((DAT_EXTMEM_0f94 <
                 (byte)(DAT_EXTMEM_0f9b - (((DAT_EXTMEM_0f95 < DAT_EXTMEM_0f9c) << 7) >> 7))) << 7 <
                 '\0') {
            *(undefined1 *)
             CONCAT11(DAT_EXTMEM_0f94 +
                      (DAT_EXTMEM_09e8 - ((CARRY1(DAT_EXTMEM_09e9,DAT_EXTMEM_0f95) << 7) >> 7)),
                      DAT_EXTMEM_09e9 + DAT_EXTMEM_0f95) =
                 *(undefined1 *)
                  CONCAT11((DAT_EXTMEM_0f94 - (((0xeb < DAT_EXTMEM_0f95) << 7) >> 7)) +
                           (DAT_EXTMEM_0a0e -
                           ((CARRY1(DAT_EXTMEM_0a0f,DAT_EXTMEM_0f95 + 0x14) << 7) >> 7)),
                           DAT_EXTMEM_0a0f + DAT_EXTMEM_0f95 + 0x14);
            DAT_EXTMEM_0f95 = DAT_EXTMEM_0f95 + 1;
            if (DAT_EXTMEM_0f95 == 0) {
              DAT_EXTMEM_0f94 = DAT_EXTMEM_0f94 + 1;
            }
          }
        }
        else {
          if (DAT_EXTMEM_0750 != 3) {
            FUN_CODE_529c(0,0x16,0xf);
            *(undefined1 *)
             CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                      DAT_EXTMEM_0f51 + 0x10) = 5;
            cVar3 = DAT_EXTMEM_0f5b;
            bVar4 = DAT_EXTMEM_0f5c;
            FUN_CODE_537a();
            pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                      DAT_EXTMEM_0f5c + 0x12);
            *pcVar6 = cVar3;
            pcVar6[1] = bVar4;
            FUN_CODE_54a5();
            return;
          }
          DAT_EXTMEM_0fb2 = 1;
          DAT_EXTMEM_0fb3 = BANK0_R6;
          DAT_EXTMEM_0fb4 = DAT_EXTMEM_09e9;
          DAT_EXTMEM_0fb5 = DAT_EXTMEM_0f9b;
          DAT_EXTMEM_0fb6 = DAT_EXTMEM_0f9c;
          cVar3 = '\0';
          FUN_CODE_7189(DAT_EXTMEM_09e8);
          if (cVar3 != '\x01') {
            FUN_CODE_529c(0,0x16,0xf);
            *(undefined1 *)
             CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                      DAT_EXTMEM_0f51 + 0x10) = 5;
            cVar3 = DAT_EXTMEM_0f5b;
            bVar4 = DAT_EXTMEM_0f5c;
            FUN_CODE_537a();
            pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                      DAT_EXTMEM_0f5c + 0x12);
            *pcVar6 = cVar3;
            pcVar6[1] = bVar4;
            FUN_CODE_54a5();
            return;
          }
        }
        cVar3 = *(char *)CONCAT11(DAT_EXTMEM_0a0e - (((0xee < DAT_EXTMEM_0a0f) << 7) >> 7),
                                  DAT_EXTMEM_0a0f + 0x11);
        if (cVar3 != DAT_EXTMEM_0a0c) {
          if (cVar3 == -1) {
            _2_7 = '\0';
            bVar4 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
            pcVar6 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) +
                                      ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f);
            cVar3 = *pcVar6;
            cVar2 = pcVar6[1];
            FUN_CODE_5411();
            DAT_EXTMEM_0f97 = cVar3;
            DAT_EXTMEM_0f98 = cVar2;
            if (cVar2 == '\0' && cVar3 == '\0') {
              bVar4 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
              pcVar6 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) +
                                        ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f);
              DAT_EXTMEM_0a0a = *pcVar6;
              DAT_EXTMEM_0a0b = pcVar6[1];
              puVar7 = (undefined1 *)
                       CONCAT11(DAT_EXTMEM_0a0a - (((0xeb < DAT_EXTMEM_0a0b) << 7) >> 7),
                                DAT_EXTMEM_0a0b + 0x14);
              bVar4 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
              DAT_EXTMEM_0f52 = DAT_EXTMEM_0a0a;
              DAT_EXTMEM_0f53 = DAT_EXTMEM_0a0b;
              FUN_CODE_74f5(*puVar7,CONCAT11((char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) +
                                             ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f),
                            puVar7[1]);
              FUN_CODE_68c0();
            }
            else {
              DAT_EXTMEM_0f9a = '\r';
            }
          }
          else {
            DAT_EXTMEM_0f9a = '\x03';
          }
        }
      }
      if ((DAT_EXTMEM_0f9a == '\0') && (_2_7 != '\0')) {
        pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f56 - (((0xed < DAT_EXTMEM_0f57) << 7) >> 7),
                                  DAT_EXTMEM_0f57 + 0x12);
        bVar4 = pcVar6[1];
        bVar1 = CARRY1(DAT_EXTMEM_09e9,bVar4);
        DAT_EXTMEM_09e9 = DAT_EXTMEM_09e9 + bVar4;
        DAT_EXTMEM_09e8 = DAT_EXTMEM_09e8 + (*pcVar6 - ((bVar1 << 7) >> 7));
        DAT_EXTMEM_0a0c = DAT_EXTMEM_0a0c + '\x01';
      }
    }
    else {
      DAT_EXTMEM_0f9a = '\f';
    }
    FUN_CODE_529c(0,0x16,0xf);
    *(char *)CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                      DAT_EXTMEM_0f51 + 0x10) = DAT_EXTMEM_0f9a;
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    return;
  case 0x33:
    DAT_EXTMEM_09a3 = DAT_EXTMEM_0a0f + 0x10;
    DAT_EXTMEM_09a2 = DAT_EXTMEM_0a0e - (((0xef < DAT_EXTMEM_0a0f) << 7) >> 7);
    DAT_EXTMEM_09e6 =
         *(char *)CONCAT11(DAT_EXTMEM_09a2 - (((0xfb < DAT_EXTMEM_09a3) << 7) >> 7),
                           DAT_EXTMEM_0a0f + 0x14);
    DAT_EXTMEM_0fb2 = DAT_EXTMEM_09a2 - (((0xf9 < DAT_EXTMEM_09a3) << 7) >> 7);
    DAT_EXTMEM_0fb1 = 1;
    DAT_EXTMEM_0fb3 = BANK0_R7;
    DAT_EXTMEM_0fb4 = 0;
    DAT_EXTMEM_0fb5 = 8;
    FUN_CODE_7c5d(0x9d,0xf,1,DAT_EXTMEM_0a0f + 0x16);
    pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                              DAT_EXTMEM_09a3 + 0xe);
    DAT_EXTMEM_0fa5 = *pbVar8;
    DAT_EXTMEM_0fa6 = pbVar8[1];
    pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xef < DAT_EXTMEM_09a3) << 7) >> 7),
                              DAT_EXTMEM_09a3 + 0x10);
    DAT_EXTMEM_0fa7 = *pbVar8;
    DAT_EXTMEM_0fa8 = pbVar8[1];
    DAT_EXTMEM_0fa9 =
         *(undefined1 *)
          CONCAT11(DAT_EXTMEM_09a2 - (((0xed < DAT_EXTMEM_09a3) << 7) >> 7),DAT_EXTMEM_09a3 + 0x12);
    pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xeb < DAT_EXTMEM_09a3) << 7) >> 7),
                              DAT_EXTMEM_09a3 + 0x14);
    DAT_EXTMEM_0faa = *pbVar8;
    DAT_EXTMEM_0fab = pbVar8[1];
    pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                              DAT_EXTMEM_09a3 + 0x1a);
    DAT_EXTMEM_0fac = *pbVar8;
    DAT_EXTMEM_0fad = pbVar8[1];
    if (DAT_EXTMEM_09e5 == 1) {
      DAT_EXTMEM_09e5 = 2;
    }
    if ((DAT_EXTMEM_09e6 != '2') && (DAT_EXTMEM_09e6 != '4')) {
      if (DAT_EXTMEM_09e6 == '6') {
        DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
        DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
        DAT_EXTMEM_0a05 = 0;
        _4_5 = 0;
        bVar4 = DAT_EXTMEM_083d;
        while (FUN_CODE_6775(), DAT_EXTMEM_0f96 = bVar4, bVar4 == 1) {
          DAT_EXTMEM_09a2 = BANK0_R2;
          DAT_EXTMEM_09a3 = DAT_EXTMEM_0a0b;
          bVar4 = DAT_EXTMEM_0a0b;
          if (*(char *)CONCAT11(BANK0_R2 - (((0xfb < DAT_EXTMEM_0a0b) << 7) >> 7),
                                DAT_EXTMEM_0a0b + 4) == '6') {
            bVar4 = DAT_EXTMEM_0a0b + 6;
            DAT_EXTMEM_0fb1 = 1;
            DAT_EXTMEM_0fb2 = '\x0f';
            DAT_EXTMEM_0fb3 = 0x9d;
            DAT_EXTMEM_0fb4 = 0;
            DAT_EXTMEM_0fb5 = 8;
            FUN_CODE_7bf6(BANK0_R7,DAT_EXTMEM_0a0a - (((0xf9 < DAT_EXTMEM_0a0b) << 7) >> 7));
            if (bVar4 == 0) {
              pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                        DAT_EXTMEM_09a3 + 0xe);
              bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fa6;
              if (bVar4 == 0) {
                bVar4 = *pbVar8 ^ DAT_EXTMEM_0fa5;
              }
              if (bVar4 == 0) {
                pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xef < DAT_EXTMEM_09a3) << 7) >> 7),
                                          DAT_EXTMEM_09a3 + 0x10);
                bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fa8;
                if (bVar4 == 0) {
                  bVar4 = *pbVar8 ^ DAT_EXTMEM_0fa7;
                }
                if (bVar4 == 0) {
                  pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xeb < DAT_EXTMEM_09a3) << 7) >> 7)
                                            ,DAT_EXTMEM_09a3 + 0x14);
                  bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fab;
                  if (bVar4 == 0) {
                    bVar4 = *pbVar8 ^ DAT_EXTMEM_0faa;
                  }
                  if (bVar4 == 0) {
                    pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 -
                                              (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                                              DAT_EXTMEM_09a3 + 0x1a);
                    bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fad;
                    if (bVar4 == 0) {
                      bVar4 = *pbVar8 ^ DAT_EXTMEM_0fac;
                    }
                    if (bVar4 == 0) {
                      FUN_CODE_529c(0,0x16,0xf);
                      *(undefined1 *)
                       CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                                DAT_EXTMEM_0f51 + 0x10) = 8;
                      cVar3 = DAT_EXTMEM_0f5b;
                      bVar4 = DAT_EXTMEM_0f5c;
                      FUN_CODE_537a();
                      pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b -
                                                (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                                DAT_EXTMEM_0f5c + 0x12);
                      *pcVar6 = cVar3;
                      pcVar6[1] = bVar4;
                      FUN_CODE_54a5();
                      return;
                    }
                  }
                }
              }
              if (DAT_EXTMEM_0750 != 2) {
                if (DAT_EXTMEM_0750 != 3) {
                  FUN_CODE_529c(0,0x16,0xf);
                  *(undefined1 *)
                   CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                            DAT_EXTMEM_0f51 + 0x10) = 5;
                  cVar3 = DAT_EXTMEM_0f5b;
                  bVar4 = DAT_EXTMEM_0f5c;
                  FUN_CODE_537a();
                  pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7)
                                            ,DAT_EXTMEM_0f5c + 0x12);
                  *pcVar6 = cVar3;
                  pcVar6[1] = bVar4;
                  FUN_CODE_54a5();
                  return;
                }
                break;
              }
              DAT_EXTMEM_0fe8 = DAT_EXTMEM_0fa5;
              DAT_EXTMEM_0fe9 = DAT_EXTMEM_0fa6;
              bVar4 = DAT_EXTMEM_0fad;
              FUN_CODE_6db4(0x48,4,1,DAT_EXTMEM_0fac);
              DAT_EXTMEM_0f96 = bVar4;
              if (bVar4 == 1) {
                puVar7 = (undefined1 *)
                         CONCAT11(DAT_EXTMEM_09a2 - (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                                  DAT_EXTMEM_09a3 + 0x1a);
                bVar4 = puVar7[1];
                pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                          DAT_EXTMEM_09a3 + 0xe);
                DAT_EXTMEM_0fe8 = *pbVar8;
                DAT_EXTMEM_0fe9 = pbVar8[1];
                FUN_CODE_6db4(0x48,4,1,*puVar7);
                DAT_EXTMEM_0f96 = bVar4;
                if (bVar4 == 1) {
                  bVar4 = DAT_EXTMEM_0a07;
                  FUN_CODE_6916(DAT_EXTMEM_0a06);
                }
              }
              else if (bVar4 == 3) {
                pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                                          DAT_EXTMEM_09a3 + 0x1a);
                bVar4 = pbVar8[1];
                if (((*pbVar8 < DAT_EXTMEM_0fac - (((bVar4 < DAT_EXTMEM_0fad + 1) << 7) >> 7)) << 7
                     < '\0') || (DAT_EXTMEM_0fad == 0 && DAT_EXTMEM_0fac == 0)) {
                  bVar4 = DAT_EXTMEM_0a07;
                  FUN_CODE_6916(DAT_EXTMEM_0a06);
                }
              }
              else if (bVar4 == 0) {
                pcVar6 = (char *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                          DAT_EXTMEM_09a3 + 0xe);
                bVar4 = *pcVar6 - (((DAT_EXTMEM_0fa6 < (byte)pcVar6[1]) << 7) >> 7);
                if ((DAT_EXTMEM_0fa5 < bVar4) << 7 < '\0') {
                  FUN_CODE_529c(DAT_EXTMEM_0fa5 - bVar4,0,0x16,0xf);
                  *(undefined1 *)
                   CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                            DAT_EXTMEM_0f51 + 0x10) = 8;
                  cVar3 = DAT_EXTMEM_0f5b;
                  bVar4 = DAT_EXTMEM_0f5c;
                  FUN_CODE_537a();
                  pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7)
                                            ,DAT_EXTMEM_0f5c + 0x12);
                  *pcVar6 = cVar3;
                  pcVar6[1] = bVar4;
                  FUN_CODE_54a5();
                  return;
                }
                bVar4 = DAT_EXTMEM_0a07;
                FUN_CODE_6916(DAT_EXTMEM_0a06);
              }
            }
          }
        }
        if ((DAT_EXTMEM_0750 == 3) && (DAT_EXTMEM_09e5 == 0)) {
          DAT_EXTMEM_09e5 = 1;
          LATCH3_7SEG_802_15 = 0x80;
          cVar3 = '\0';
          FUN_CODE_70f3();
          if (cVar3 == '\x01') {
            LATCH3_7SEG_802_15 = 0xf9;
          }
          else {
            LATCH3_7SEG_802_15 = 0xc0;
          }
          for (DAT_EXTMEM_0f93 = 0; bVar4 = DAT_EXTMEM_083d, DAT_EXTMEM_0f93 < 4;
              DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1) {
            pbVar8 = (byte *)CONCAT11('\x0f' - (((0x95 < DAT_EXTMEM_0f93 * '\x02') << 7) >> 7),
                                      DAT_EXTMEM_0f93 * '\x02' + 0x6a);
            if ((DAT_EXTMEM_0963 & pbVar8[1]) == 0 && (DAT_EXTMEM_0962 & *pbVar8) == 0) {
              bVar4 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
              puVar7 = (undefined1 *)
                       CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f);
              *puVar7 = 0xff;
              puVar7[1] = 0xff;
            }
            else {
              bVar5 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
              puVar7 = (undefined1 *)
                       CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar5) << 7) >> 7)),bVar5 + 0x1f);
              *puVar7 = DAT_EXTMEM_083c;
              puVar7[1] = bVar4;
            }
          }
          FUN_CODE_68c0(DAT_EXTMEM_0f93 - 4);
          FUN_CODE_529c(0,0x16,0xf);
          *(undefined1 *)
           CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10)
               = 0x20;
          cVar3 = DAT_EXTMEM_0f5b;
          bVar4 = DAT_EXTMEM_0f5c;
          FUN_CODE_537a();
          pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                    DAT_EXTMEM_0f5c + 0x12);
          *pcVar6 = cVar3;
          pcVar6[1] = bVar4;
          FUN_CODE_54a5();
        }
        goto LAB_CODE_6477;
      }
      if (DAT_EXTMEM_09e6 == '8') {
        DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
        DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
        DAT_EXTMEM_0a05 = 0;
        _4_5 = 0;
        bVar4 = DAT_EXTMEM_083d;
        while (FUN_CODE_6775(), DAT_EXTMEM_0f96 = bVar4, bVar4 == 1) {
          DAT_EXTMEM_09a2 = BANK0_R2;
          DAT_EXTMEM_09a3 = DAT_EXTMEM_0a0b;
          if (*(char *)CONCAT11(BANK0_R2 - (((0xfb < DAT_EXTMEM_0a0b) << 7) >> 7),
                                DAT_EXTMEM_0a0b + 4) == '8') {
            cVar3 = DAT_EXTMEM_0a0b + 6;
            DAT_EXTMEM_0fb1 = 1;
            DAT_EXTMEM_0fb2 = '\x0f';
            DAT_EXTMEM_0fb3 = 0x9d;
            DAT_EXTMEM_0fb4 = 0;
            DAT_EXTMEM_0fb5 = 8;
            FUN_CODE_7bf6(BANK0_R7,DAT_EXTMEM_0a0a - (((0xf9 < DAT_EXTMEM_0a0b) << 7) >> 7));
            if (cVar3 == '\0') {
              pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                        DAT_EXTMEM_09a3 + 0xe);
              bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fa6;
              if (bVar4 == 0) {
                bVar4 = *pbVar8 ^ DAT_EXTMEM_0fa5;
              }
              if (bVar4 == 0) {
                pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xef < DAT_EXTMEM_09a3) << 7) >> 7),
                                          DAT_EXTMEM_09a3 + 0x10);
                bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fa8;
                if (bVar4 == 0) {
                  bVar4 = *pbVar8 ^ DAT_EXTMEM_0fa7;
                }
                if (bVar4 == 0) {
                  pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xeb < DAT_EXTMEM_09a3) << 7) >> 7)
                                            ,DAT_EXTMEM_09a3 + 0x14);
                  bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fab;
                  if (bVar4 == 0) {
                    bVar4 = *pbVar8 ^ DAT_EXTMEM_0faa;
                  }
                  if (bVar4 == 0) {
                    FUN_CODE_529c(0,0x16,0xf);
                    *(undefined1 *)
                     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                              DAT_EXTMEM_0f51 + 0x10) = 8;
                    cVar3 = DAT_EXTMEM_0f5b;
                    bVar4 = DAT_EXTMEM_0f5c;
                    FUN_CODE_537a();
                    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b -
                                              (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                              DAT_EXTMEM_0f5c + 0x12);
                    *pcVar6 = cVar3;
                    pcVar6[1] = bVar4;
                    FUN_CODE_54a5();
                    return;
                  }
                }
              }
            }
          }
          bVar4 = DAT_EXTMEM_0750;
          if ((DAT_EXTMEM_0750 != 2) && (DAT_EXTMEM_0750 != 3)) {
            FUN_CODE_529c(0,0x16,0xf);
            *(undefined1 *)
             CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                      DAT_EXTMEM_0f51 + 0x10) = 5;
            cVar3 = DAT_EXTMEM_0f5b;
            bVar4 = DAT_EXTMEM_0f5c;
            FUN_CODE_537a();
            pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                      DAT_EXTMEM_0f5c + 0x12);
            *pcVar6 = cVar3;
            pcVar6[1] = bVar4;
            FUN_CODE_54a5();
            return;
          }
        }
        if ((DAT_EXTMEM_0750 == 3) && (DAT_EXTMEM_09e5 == 0)) {
          DAT_EXTMEM_09e5 = 1;
          LATCH3_7SEG_802_15 = 0x80;
          cVar3 = '\0';
          FUN_CODE_70f3();
          if (cVar3 == '\x01') {
            LATCH3_7SEG_802_15 = 0xf9;
          }
          else {
            LATCH3_7SEG_802_15 = 0xc0;
          }
          for (DAT_EXTMEM_0f93 = 0; bVar4 = DAT_EXTMEM_083d, DAT_EXTMEM_0f93 < 4;
              DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1) {
            pbVar8 = (byte *)CONCAT11('\x0f' - (((0x95 < DAT_EXTMEM_0f93 * '\x02') << 7) >> 7),
                                      DAT_EXTMEM_0f93 * '\x02' + 0x6a);
            if ((DAT_EXTMEM_0963 & pbVar8[1]) == 0 && (DAT_EXTMEM_0962 & *pbVar8) == 0) {
              bVar4 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
              puVar7 = (undefined1 *)
                       CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f);
              *puVar7 = 0xff;
              puVar7[1] = 0xff;
            }
            else {
              bVar5 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
              puVar7 = (undefined1 *)
                       CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar5) << 7) >> 7)),bVar5 + 0x1f);
              *puVar7 = DAT_EXTMEM_083c;
              puVar7[1] = bVar4;
            }
          }
          FUN_CODE_68c0(DAT_EXTMEM_0f93 - 4);
          FUN_CODE_529c(0,0x16,0xf);
          *(undefined1 *)
           CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10)
               = 0x20;
          cVar3 = DAT_EXTMEM_0f5b;
          bVar4 = DAT_EXTMEM_0f5c;
          FUN_CODE_537a();
          pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                    DAT_EXTMEM_0f5c + 0x12);
          *pcVar6 = cVar3;
          pcVar6[1] = bVar4;
          FUN_CODE_54a5();
        }
        goto LAB_CODE_6477;
      }
      if (DAT_EXTMEM_09e6 == ':') goto LAB_CODE_6477;
      if (DAT_EXTMEM_09e6 != '0') {
        DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
        DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
        DAT_EXTMEM_0a05 = 0;
        _4_5 = 0;
        cVar3 = DAT_EXTMEM_09a2;
        bVar4 = DAT_EXTMEM_083d;
        do {
          bVar5 = bVar4;
          FUN_CODE_6775(cVar3);
          DAT_EXTMEM_0f96 = bVar5;
          if (bVar5 != 1) goto LAB_CODE_6439;
          bVar4 = *(byte *)CONCAT11(DAT_EXTMEM_0a0a - (((0xfb < DAT_EXTMEM_0a0b) << 7) >> 7),
                                    DAT_EXTMEM_0a0b + 4);
          DAT_EXTMEM_0f96 = 1;
          cVar3 = DAT_EXTMEM_09e6;
        } while ((bVar4 != BANK0_R6) || (DAT_EXTMEM_0750 != 2));
        DAT_EXTMEM_0f96 = bVar5;
        FUN_CODE_6916(DAT_EXTMEM_0a06,DAT_EXTMEM_0a07);
LAB_CODE_6439:
        FUN_CODE_529c(0,0x16,0xf);
        *(undefined1 *)
         CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) =
             0xb;
        cVar3 = DAT_EXTMEM_0f5b;
        bVar4 = DAT_EXTMEM_0f5c;
        FUN_CODE_537a();
        pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                  DAT_EXTMEM_0f5c + 0x12);
        *pcVar6 = cVar3;
        pcVar6[1] = bVar4;
        FUN_CODE_54a5();
        return;
      }
    }
    DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
    DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
    DAT_EXTMEM_0a05 = 0;
    _4_5 = 0;
    bVar4 = DAT_EXTMEM_083d;
    while (FUN_CODE_6775(), DAT_EXTMEM_0f96 = bVar4, bVar4 == 1) {
      DAT_EXTMEM_09a2 = BANK0_R2;
      DAT_EXTMEM_09a3 = DAT_EXTMEM_0a0b;
      bVar4 = DAT_EXTMEM_0a0b;
      if ((*(char *)CONCAT11(BANK0_R2 - (((0xfb < DAT_EXTMEM_0a0b) << 7) >> 7),DAT_EXTMEM_0a0b + 4)
           == BANK0_R4) &&
         (bVar4 = DAT_EXTMEM_0a0b,
         *(char *)CONCAT11(BANK0_R2 - (((0xed < DAT_EXTMEM_0a0b) << 7) >> 7),DAT_EXTMEM_0a0b + 0x12)
         == BANK0_R4)) {
        bVar4 = DAT_EXTMEM_0a0b + 6;
        DAT_EXTMEM_0fb1 = 1;
        DAT_EXTMEM_0fb2 = '\x0f';
        DAT_EXTMEM_0fb3 = 0x9d;
        DAT_EXTMEM_0fb4 = 0;
        DAT_EXTMEM_0fb5 = 8;
        FUN_CODE_7bf6(BANK0_R7,DAT_EXTMEM_0a0a - (((0xf9 < DAT_EXTMEM_0a0b) << 7) >> 7),
                      DAT_EXTMEM_0fa9);
        if (bVar4 == 0) {
          pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                    DAT_EXTMEM_09a3 + 0xe);
          bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fa6;
          if (bVar4 == 0) {
            bVar4 = *pbVar8 ^ DAT_EXTMEM_0fa5;
          }
          if (bVar4 == 0) {
            pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xef < DAT_EXTMEM_09a3) << 7) >> 7),
                                      DAT_EXTMEM_09a3 + 0x10);
            bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fa8;
            if (bVar4 == 0) {
              bVar4 = *pbVar8 ^ DAT_EXTMEM_0fa7;
            }
            if (bVar4 == 0) {
              pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xeb < DAT_EXTMEM_09a3) << 7) >> 7),
                                        DAT_EXTMEM_09a3 + 0x14);
              bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fab;
              if (bVar4 == 0) {
                bVar4 = *pbVar8 ^ DAT_EXTMEM_0faa;
              }
              if (bVar4 == 0) {
                pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                                          DAT_EXTMEM_09a3 + 0x1a);
                bVar4 = pbVar8[1] ^ DAT_EXTMEM_0fad;
                if (bVar4 == 0) {
                  bVar4 = *pbVar8 ^ DAT_EXTMEM_0fac;
                }
                if (bVar4 == 0) {
                  FUN_CODE_529c(0,0x16,0xf);
                  *(undefined1 *)
                   CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                            DAT_EXTMEM_0f51 + 0x10) = 8;
                  cVar3 = DAT_EXTMEM_0f5b;
                  bVar4 = DAT_EXTMEM_0f5c;
                  FUN_CODE_537a();
                  pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7)
                                            ,DAT_EXTMEM_0f5c + 0x12);
                  *pcVar6 = cVar3;
                  pcVar6[1] = bVar4;
                  FUN_CODE_54a5();
                  return;
                }
              }
            }
          }
          if (DAT_EXTMEM_0750 != 2) {
            if (DAT_EXTMEM_0750 != 3) {
              FUN_CODE_529c(0,0x16,0xf);
              *(undefined1 *)
               CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                        DAT_EXTMEM_0f51 + 0x10) = 5;
              cVar3 = DAT_EXTMEM_0f5b;
              bVar4 = DAT_EXTMEM_0f5c;
              FUN_CODE_537a();
              pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                        DAT_EXTMEM_0f5c + 0x12);
              *pcVar6 = cVar3;
              pcVar6[1] = bVar4;
              FUN_CODE_54a5();
              return;
            }
            break;
          }
          DAT_EXTMEM_0fe8 = DAT_EXTMEM_0fa5;
          DAT_EXTMEM_0fe9 = DAT_EXTMEM_0fa6;
          bVar4 = DAT_EXTMEM_0fad;
          FUN_CODE_6db4(0x48,4,1,DAT_EXTMEM_0fac);
          DAT_EXTMEM_0f96 = bVar4;
          if (bVar4 == 1) {
            puVar7 = (undefined1 *)
                     CONCAT11(DAT_EXTMEM_09a2 - (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                              DAT_EXTMEM_09a3 + 0x1a);
            bVar4 = puVar7[1];
            pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                      DAT_EXTMEM_09a3 + 0xe);
            DAT_EXTMEM_0fe8 = *pbVar8;
            DAT_EXTMEM_0fe9 = pbVar8[1];
            FUN_CODE_6db4(0x48,4,1,*puVar7);
            DAT_EXTMEM_0f96 = bVar4;
            if (bVar4 == 1) {
              bVar4 = DAT_EXTMEM_0a07;
              FUN_CODE_6916(DAT_EXTMEM_0a06);
            }
          }
          else if (bVar4 == 3) {
            pbVar8 = (byte *)CONCAT11(DAT_EXTMEM_09a2 - (((0xe5 < DAT_EXTMEM_09a3) << 7) >> 7),
                                      DAT_EXTMEM_09a3 + 0x1a);
            bVar4 = pbVar8[1];
            if (((*pbVar8 < DAT_EXTMEM_0fac - (((bVar4 < DAT_EXTMEM_0fad + 1) << 7) >> 7)) << 7 <
                 '\0') || (DAT_EXTMEM_0fad == 0 && DAT_EXTMEM_0fac == 0)) {
              bVar4 = DAT_EXTMEM_0a07;
              FUN_CODE_6916(DAT_EXTMEM_0a06);
            }
          }
          else if (bVar4 == 0) {
            pcVar6 = (char *)CONCAT11(DAT_EXTMEM_09a2 - (((0xf1 < DAT_EXTMEM_09a3) << 7) >> 7),
                                      DAT_EXTMEM_09a3 + 0xe);
            bVar4 = *pcVar6 - (((DAT_EXTMEM_0fa6 < (byte)pcVar6[1]) << 7) >> 7);
            if ((DAT_EXTMEM_0fa5 < bVar4) << 7 < '\0') {
              FUN_CODE_529c(DAT_EXTMEM_0fa5 - bVar4,0,0x16,0xf);
              *(undefined1 *)
               CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),
                        DAT_EXTMEM_0f51 + 0x10) = 8;
              cVar3 = DAT_EXTMEM_0f5b;
              bVar4 = DAT_EXTMEM_0f5c;
              FUN_CODE_537a();
              pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                        DAT_EXTMEM_0f5c + 0x12);
              *pcVar6 = cVar3;
              pcVar6[1] = bVar4;
              FUN_CODE_54a5();
              return;
            }
            bVar4 = DAT_EXTMEM_0a07;
            FUN_CODE_6916(DAT_EXTMEM_0a06);
          }
        }
      }
    }
    if ((DAT_EXTMEM_0750 == 3) && (DAT_EXTMEM_09e5 == 0)) {
      DAT_EXTMEM_09e5 = 1;
      LATCH3_7SEG_802_15 = 0x80;
      cVar3 = '\0';
      FUN_CODE_70f3();
      if (cVar3 == '\x01') {
        LATCH3_7SEG_802_15 = 0xf9;
      }
      else {
        LATCH3_7SEG_802_15 = 0xc0;
      }
      for (DAT_EXTMEM_0f93 = 0; bVar4 = DAT_EXTMEM_083d, DAT_EXTMEM_0f93 < 4;
          DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1) {
        pbVar8 = (byte *)CONCAT11('\x0f' - (((0x95 < DAT_EXTMEM_0f93 * '\x02') << 7) >> 7),
                                  DAT_EXTMEM_0f93 * '\x02' + 0x6a);
        if ((DAT_EXTMEM_0963 & pbVar8[1]) == 0 && (DAT_EXTMEM_0962 & *pbVar8) == 0) {
          bVar4 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
          puVar7 = (undefined1 *)
                   CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                            ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f);
          *puVar7 = 0xff;
          puVar7[1] = 0xff;
        }
        else {
          bVar5 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
          puVar7 = (undefined1 *)
                   CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                            ('\b' - (((0xe0 < bVar5) << 7) >> 7)),bVar5 + 0x1f);
          *puVar7 = DAT_EXTMEM_083c;
          puVar7[1] = bVar4;
        }
      }
      FUN_CODE_68c0(DAT_EXTMEM_0f93 - 4);
      FUN_CODE_529c(0,0x16,0xf);
      *(undefined1 *)
       CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) =
           0x20;
      cVar3 = DAT_EXTMEM_0f5b;
      bVar4 = DAT_EXTMEM_0f5c;
      FUN_CODE_537a();
      pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                DAT_EXTMEM_0f5c + 0x12);
      *pcVar6 = cVar3;
      pcVar6[1] = bVar4;
      FUN_CODE_54a5();
    }
LAB_CODE_6477:
    _5_1 = '\0';
    DAT_EXTMEM_0f93 = 0;
    do {
      cVar3 = DAT_EXTMEM_0f93 - 4;
      if (3 < DAT_EXTMEM_0f93) {
LAB_CODE_64f2:
        FUN_CODE_529c(cVar3,0,0x16,0xf);
        if (_5_1 == '\0') {
          *(undefined1 *)
           CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10)
               = 5;
        }
        else {
          *(undefined1 *)
           CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10)
               = 0;
        }
        cVar3 = DAT_EXTMEM_0f5b;
        bVar4 = DAT_EXTMEM_0f5c;
        FUN_CODE_537a();
        pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                                  DAT_EXTMEM_0f5c + 0x12);
        *pcVar6 = cVar3;
        pcVar6[1] = bVar4;
        FUN_CODE_54a5();
        return;
      }
      pbVar8 = (byte *)CONCAT11('\x0f' - (((0x95 < DAT_EXTMEM_0f93 * '\x02') << 7) >> 7),
                                DAT_EXTMEM_0f93 * '\x02' + 0x6a);
      if ((DAT_EXTMEM_0963 & pbVar8[1]) != 0 || (DAT_EXTMEM_0962 & *pbVar8) != 0) {
        bVar4 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
        pcVar6 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                                  ('\b' - (((0xe0 < bVar4) << 7) >> 7)),bVar4 + 0x1f);
        cVar2 = *pcVar6;
        bVar4 = pcVar6[1];
        if (DAT_EXTMEM_0faa - (((-bVar4 - 1 < DAT_EXTMEM_0fab) << 7) >> 7) <= -cVar2 - 1U) {
          _5_1 = '\x01';
          DAT_EXTMEM_09e7 = DAT_EXTMEM_0f93;
          _2_7 = '\x01';
          cVar3 = '\0';
          DAT_EXTMEM_0a0c = '\0';
          DAT_EXTMEM_09e8 = cVar2;
          DAT_EXTMEM_09e9 = bVar4;
          goto LAB_CODE_64f2;
        }
      }
      DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1;
    } while( true );
  case 0x36:
    FUN_CODE_6b64();
    if (cVar3 == '\x01') {
      FUN_CODE_6916(DAT_EXTMEM_0a06,DAT_EXTMEM_0a07);
      FUN_CODE_529c(0,0x16,0xf);
      *(undefined1 *)
       CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0
      ;
    }
    else {
      FUN_CODE_529c(0,0x16,0xf);
      *(undefined1 *)
       CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 7
      ;
    }
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
    return;
  case 0x39:
    for (DAT_EXTMEM_0f93 = 0; bVar4 = DAT_EXTMEM_083d, DAT_EXTMEM_0f93 < 4;
        DAT_EXTMEM_0f93 = DAT_EXTMEM_0f93 + 1) {
      bVar5 = (byte)((ushort)DAT_EXTMEM_0f93 * 2);
      puVar7 = (undefined1 *)
               CONCAT11((char)((ushort)DAT_EXTMEM_0f93 * 2 >> 8) +
                        ('\b' - (((0xe0 < bVar5) << 7) >> 7)),bVar5 + 0x1f);
      *puVar7 = DAT_EXTMEM_083c;
      puVar7[1] = bVar4;
    }
    FUN_CODE_68c0(DAT_EXTMEM_0f93 - 4);
    FUN_CODE_529c(0,0x16,0xf);
    *(undefined1 *)
     CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0;
    cVar3 = DAT_EXTMEM_0f5b;
    bVar4 = DAT_EXTMEM_0f5c;
    FUN_CODE_537a();
    pcVar6 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                              DAT_EXTMEM_0f5c + 0x12);
    *pcVar6 = cVar3;
    pcVar6[1] = bVar4;
    FUN_CODE_54a5();
  }
  return;
}



// ==== FUN_CODE_6625 @ CODE:6625  (219 bytes)

/* WARNING: Removing unreachable block (CODE,0x66ac) */
/* WARNING: Removing unreachable block (CODE,0x66b5) */

void FUN_CODE_6625(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  
  DAT_EXTMEM_0fae =
       *(undefined1 *)
        CONCAT11(DAT_EXTMEM_0a0e - (((0xef < DAT_EXTMEM_0a0f) << 7) >> 7),DAT_EXTMEM_0a0f + 0x10);
  DAT_EXTMEM_0faf =
       *(undefined1 *)
        CONCAT11(DAT_EXTMEM_0a0e - (((0xee < DAT_EXTMEM_0a0f) << 7) >> 7),DAT_EXTMEM_0a0f + 0x11);
  FUN_CODE_529c(0,0x16,0xf);
  *(undefined1 *)
   CONCAT11(DAT_EXTMEM_0f50 - (((0xef < DAT_EXTMEM_0f51) << 7) >> 7),DAT_EXTMEM_0f51 + 0x10) = 0;
  cVar1 = DAT_EXTMEM_0f5b;
  bVar2 = DAT_EXTMEM_0f5c;
  FUN_CODE_537a();
  pcVar3 = (char *)CONCAT11(DAT_EXTMEM_0f5b - (((0xed < DAT_EXTMEM_0f5c) << 7) >> 7),
                            DAT_EXTMEM_0f5c + 0x12);
  *pcVar3 = cVar1;
  pcVar3[1] = bVar2;
  FUN_CODE_54a5();
  FUN_CODE_6700(DAT_EXTMEM_0fae);
  do {
    bVar2 = T1;
    T1 = bVar2 ^ 1;
  } while( true );
}



// ==== FUN_CODE_6700 @ CODE:6700  (117 bytes)

void FUN_CODE_6700(byte param_1)

{
  if (7 < param_1) {
    param_1 = 0;
  }
  if (_4_7 == '\x01') {
    if (param_1 < 8) {
                    /* WARNING: Switch is manually overridden */
      switch(param_1 * '\x03') {
      case 0:
        TH1 = 0xd0;
        return;
      case 3:
        TH1 = 0xe8;
        return;
      case 6:
        TH1 = 0xf3;
        return;
      case 9:
        TH1 = 0xf5;
        return;
      case 0xc:
        TH1 = 0xf7;
        return;
      case 0xf:
        TH1 = 0xf4;
        return;
      case 0x12:
        TH1 = 0xfa;
        return;
      case 0x15:
        TH1 = 0xfd;
      }
    }
  }
  else {
    if (param_1 == 1) {
      TH1 = 0xf3;
      return;
    }
    if (param_1 == 2) {
      TH1 = 0xf9;
      return;
    }
    if (param_1 == 3) {
      TH1 = 0xfa;
      return;
    }
    if (param_1 == 4) {
      TH1 = 0xfb;
      return;
    }
    if (param_1 == 0) {
      TH1 = 0xe6;
      return;
    }
  }
  return;
}



// ==== FUN_CODE_6775 @ CODE:6775  (331 bytes)

char FUN_CODE_6775(void)

{
  bool bVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  
  DAT_EXTMEM_0a0a = DAT_EXTMEM_0a06;
  DAT_EXTMEM_0a0b = DAT_EXTMEM_0a07;
  DAT_EXTMEM_0f52 = DAT_EXTMEM_0a06;
  DAT_EXTMEM_0f53 = DAT_EXTMEM_0a07;
  FUN_CODE_6ecb(DAT_EXTMEM_0a05);
  if (_4_5 != '\0') {
    pcVar3 = (char *)CONCAT11(DAT_EXTMEM_0f52 - (((0xeb < DAT_EXTMEM_0f53) << 7) >> 7),
                              DAT_EXTMEM_0f53 + 0x14);
    bVar2 = pcVar3[1];
    bVar1 = CARRY1(DAT_EXTMEM_0a07,bVar2);
    DAT_EXTMEM_0a07 = DAT_EXTMEM_0a07 + bVar2;
    DAT_EXTMEM_0a06 = DAT_EXTMEM_0a06 + (*pcVar3 - ((bVar1 << 7) >> 7));
    DAT_EXTMEM_0a0a = DAT_EXTMEM_0a06;
    DAT_EXTMEM_0a0b = DAT_EXTMEM_0a07;
    DAT_EXTMEM_0f52 = DAT_EXTMEM_0a06;
    DAT_EXTMEM_0f53 = DAT_EXTMEM_0a07;
  }
  DAT_EXTMEM_0fb2 = DAT_EXTMEM_0a05;
  do {
    if (3 < DAT_EXTMEM_0fb2) {
      _4_5 = 0;
      return DAT_EXTMEM_0fb2 - 4;
    }
    pbVar4 = (byte *)CONCAT11('\x0f' - (((0x95 < DAT_EXTMEM_0fb2 * '\x02') << 7) >> 7),
                              DAT_EXTMEM_0fb2 * '\x02' + 0x6a);
    if ((DAT_EXTMEM_0963 & pbVar4[1]) != 0 || (DAT_EXTMEM_0962 & *pbVar4) != 0) {
      FUN_CODE_6ecb();
      if (DAT_EXTMEM_0a05 + 1 <= DAT_EXTMEM_0fb2) {
        DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
        DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
        DAT_EXTMEM_0a05 = DAT_EXTMEM_0fb2;
        DAT_EXTMEM_0a0a = DAT_EXTMEM_083c;
        DAT_EXTMEM_0a0b = DAT_EXTMEM_083d;
        DAT_EXTMEM_0f52 = DAT_EXTMEM_083c;
        DAT_EXTMEM_0f53 = DAT_EXTMEM_083d;
      }
      while (bVar2 = (byte)((ushort)DAT_EXTMEM_0fb2 * 2),
            pcVar3 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_0fb2 * 2 >> 8) +
                                      ('\b' - (((0xe0 < bVar2) << 7) >> 7)),bVar2 + 0x1f),
            DAT_EXTMEM_0f52 < (byte)(*pcVar3 - (((DAT_EXTMEM_0f53 < (byte)pcVar3[1]) << 7) >> 7))) {
        bVar2 = ((byte *)CONCAT11(DAT_EXTMEM_0f52,DAT_EXTMEM_0f53))[1] ^ 0x4f;
        if (bVar2 == 0) {
          bVar2 = *(byte *)CONCAT11(DAT_EXTMEM_0f52,DAT_EXTMEM_0f53) ^ 0x46;
        }
        if (bVar2 == 0) {
          bVar2 = DAT_EXTMEM_0f53;
          check_FORM_header(DAT_EXTMEM_0f52);
          if (bVar2 == 1) {
            _4_5 = 1;
            return '\x01';
          }
          if (DAT_EXTMEM_0750 != '\x02') break;
          FUN_CODE_6916(DAT_EXTMEM_0f52,DAT_EXTMEM_0f53);
        }
        else {
          if (DAT_EXTMEM_0750 != '\x02') break;
          FUN_CODE_6916(DAT_EXTMEM_0f52,DAT_EXTMEM_0f53);
        }
      }
    }
    DAT_EXTMEM_0fb2 = DAT_EXTMEM_0fb2 + 1;
  } while( true );
}



// ==== FUN_CODE_68c0 @ CODE:68c0  (86 bytes)

void FUN_CODE_68c0(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  DAT_EXTMEM_0fe9 = 0xff;
  DAT_EXTMEM_0fea = 0xff;
  bVar1 = 0;
  do {
    bVar2 = (byte)((ushort)bVar1 * 2);
    pbVar3 = (byte *)CONCAT11((char)((ushort)bVar1 * 2 >> 8) + ('\b' - (((0xdf < bVar2) << 7) >> 7))
                              ,bVar2 + 0x20);
    *pbVar3 = *pbVar3 & 0xfe;
    bVar2 = (byte)((ushort)bVar1 * 2);
    pbVar3 = (byte *)CONCAT11((char)((ushort)bVar1 * 2 >> 8) + ('\b' - (((0xe0 < bVar2) << 7) >> 7))
                              ,bVar2 + 0x1f);
    DAT_EXTMEM_0fe9 = DAT_EXTMEM_0fe9 ^ *pbVar3;
    DAT_EXTMEM_0fea = DAT_EXTMEM_0fea ^ pbVar3[1];
    bVar1 = bVar1 + 1;
  } while (bVar1 != 5);
  DAT_EXTMEM_0827 = DAT_EXTMEM_0fe9;
  DAT_EXTMEM_0828 = DAT_EXTMEM_0fea;
  return;
}



// ==== FUN_CODE_6916 @ CODE:6916  (345 bytes)

void FUN_CODE_6916(byte param_1,byte param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  char *pcVar7;
  short sVar8;
  byte *pbVar9;
  undefined2 uStack_1;
  
  bVar3 = ~param_2;
  if (bVar3 == 0) {
    bVar3 = ~param_1;
  }
  DAT_EXTMEM_0fe3 = param_1;
  DAT_EXTMEM_0fe4 = param_2;
  if ((bVar3 != 0) && (DAT_EXTMEM_0750 != '\x03')) {
    FUN_CODE_6a6f();
    bVar3 = DAT_EXTMEM_0fe4;
    uVar2 = BANK0_R7;
    uVar1 = BANK0_R6;
    DAT_EXTMEM_0fe5 = param_1;
    DAT_EXTMEM_0fe6 = param_2;
    if (param_2 == 0 && param_1 == 0) {
      bVar6 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
      pbVar9 = (byte *)CONCAT11((char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar6) << 7) >> 7)),bVar6 + 0x1f);
      *pbVar9 = DAT_EXTMEM_0fe3;
      pbVar9[1] = bVar3;
      BANK0_R7 = BANK0_R5;
      BANK0_R6 = BANK0_R4;
      FUN_CODE_79d0(uVar2,uVar1,1,0,0xff,bVar3);
    }
    else {
      bVar3 = T1;
      T1 = bVar3 ^ 1;
      bVar3 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
      pcVar7 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar3) << 7) >> 7)),bVar3 + 0x1f);
      bVar3 = pcVar7[1];
      sVar8 = 0xfe6;
      bVar6 = bVar3 - param_2;
      cVar4 = *pcVar7 - (param_1 - (((bVar3 < param_2) << 7) >> 7));
      FUN_CODE_74bf(param_2,0,2);
      *(char *)(sVar8 + 1) = cVar4;
      *(byte *)(sVar8 + 2) = bVar6;
      FUN_CODE_7b77(DAT_EXTMEM_0fe4,BANK0_R3,1,DAT_EXTMEM_0fe3,BANK0_R3,
                    cVar4 << 1 | CARRY1(bVar6,bVar6),bVar6 * '\x02');
      cVar4 = DAT_EXTMEM_0fe8 * '\x02';
      FUN_CODE_79a7(DAT_EXTMEM_0fe4,DAT_EXTMEM_0fe6,BANK0_R4,1,DAT_EXTMEM_0fe3,BANK0_R3,
                    DAT_EXTMEM_0fe7 << 1 | CARRY1(DAT_EXTMEM_0fe8,DAT_EXTMEM_0fe8));
      if (cVar4 == '\0') {
        FUN_CODE_79d0(DAT_EXTMEM_0fe6,DAT_EXTMEM_0fe5,1,0xff,
                      DAT_EXTMEM_0fe7 << 1 | CARRY1(DAT_EXTMEM_0fe8,DAT_EXTMEM_0fe8),
                      DAT_EXTMEM_0fe8 * '\x02');
      }
      bVar3 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
      cVar4 = bVar3 + 0x1f;
      cVar5 = (char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) + ('\b' - (((0xe0 < bVar3) << 7) >> 7));
      pcVar7 = (char *)CONCAT11(cVar5,cVar4);
      uStack_1 = (char *)CONCAT11(cVar5,cVar4);
      cVar4 = *pcVar7;
      bVar3 = pcVar7[1];
      bVar6 = DAT_EXTMEM_0fe6 - DAT_EXTMEM_0fe4;
      cVar5 = DAT_EXTMEM_0fe5 -
              (DAT_EXTMEM_0fe3 - (((DAT_EXTMEM_0fe6 < DAT_EXTMEM_0fe4) << 7) >> 7));
      FUN_CODE_74bf(0,2);
      *uStack_1 = cVar4 - ((cVar5 << 1 | CARRY1(bVar6,bVar6)) -
                          (((bVar3 < bVar6 * '\x02') << 7) >> 7));
      uStack_1[1] = bVar3 + bVar6 * -2;
    }
    FUN_CODE_68c0();
    _4_5 = 0;
  }
  return;
}



// ==== FUN_CODE_6a6f @ CODE:6a6f  (115 bytes)

byte FUN_CODE_6a6f(byte param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  
  DAT_EXTMEM_0fe9 = param_1;
  DAT_EXTMEM_0fea = param_2;
  while( true ) {
    do {
      bVar3 = T1;
      T1 = bVar3 ^ 1;
      bVar1 = 0xfd < DAT_EXTMEM_0fea;
      bVar2 = DAT_EXTMEM_0fea + 2;
      DAT_EXTMEM_0fea = bVar2;
      DAT_EXTMEM_0fe9 = DAT_EXTMEM_0fe9 - ((bVar1 << 7) >> 7);
      bVar3 = (byte)((ushort)DAT_EXTMEM_0f8a * 2);
      pcVar4 = (char *)CONCAT11((char)((ushort)DAT_EXTMEM_0f8a * 2 >> 8) +
                                ('\b' - (((0xe0 < bVar3) << 7) >> 7)),bVar3 + 0x1f);
      bVar3 = *pcVar4 - (((bVar2 < (byte)pcVar4[1]) << 7) >> 7);
      if (bVar3 <= DAT_EXTMEM_0fe9) {
        return DAT_EXTMEM_0fe9 - bVar3;
      }
    } while ((*(char *)CONCAT11(DAT_EXTMEM_0fe9,bVar2) != 'F') ||
            (((char *)CONCAT11(DAT_EXTMEM_0fe9,bVar2))[1] != 'O'));
    check_FORM_header(DAT_EXTMEM_0fe9);
    DAT_EXTMEM_0feb = bVar2;
    if (bVar2 == 1) break;
    if (bVar2 != 0) {
      return bVar2;
    }
  }
  return DAT_EXTMEM_0fea;
}



// ==== check_FORM_header @ CODE:6ae2  (130 bytes)

byte check_FORM_header(char param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  DAT_EXTMEM_09a2 = param_1;
  DAT_EXTMEM_09a3 = param_2;
  bVar3 = *(byte *)CONCAT11(param_1,param_2) ^ 0x46;
  if (bVar3 == 0) {
    bVar3 = *(byte *)(CONCAT11(param_1,param_2) + 1) ^ 0x4f;
    if (((bVar3 == 0) && (bVar3 = *(byte *)(CONCAT11(param_1,param_2) + 2) ^ 0x52, bVar3 == 0)) &&
       (bVar3 = *(byte *)(CONCAT11(param_1,param_2) + 3) ^ 0x4d, bVar3 == 0)) {
      bVar3 = *(byte *)CONCAT11(param_1 - (((0xfb < param_2) << 7) >> 7),param_2 + 4);
      if ((bVar3 == BANK0_R5) &&
         (pbVar4 = (byte *)CONCAT11(param_1 - (((0xeb < param_2) << 7) >> 7),param_2 + 0x14),
         bVar1 = *pbVar4,
         bVar2 = (-1 - DAT_EXTMEM_083c) - (((pbVar4[1] < (byte)-DAT_EXTMEM_083d) << 7) >> 7),
         bVar3 = bVar1 - bVar2, bVar1 < bVar2)) {
        return bVar3;
      }
    }
  }
  return bVar3;
}



// ==== FUN_CODE_6b64 @ CODE:6b64  (126 bytes)

char FUN_CODE_6b64(undefined1 param_1)

{
  undefined1 uVar1;
  byte bVar2;
  
  DAT_EXTMEM_0fb1 = DAT_EXTMEM_0a0f + 0x10;
  DAT_EXTMEM_0fb0 = DAT_EXTMEM_0a0e - (((0xef < DAT_EXTMEM_0a0f) << 7) >> 7);
  DAT_EXTMEM_0a06 = DAT_EXTMEM_083c;
  DAT_EXTMEM_0a07 = DAT_EXTMEM_083d;
  DAT_EXTMEM_0a05 = 0;
  _4_5 = 0;
  DAT_EXTMEM_0faf = '\0';
  bVar2 = DAT_EXTMEM_083d;
  uVar1 = DAT_EXTMEM_0fae;
  do {
    DAT_EXTMEM_0fae = uVar1;
    FUN_CODE_6775(param_1);
    DAT_EXTMEM_0fae = bVar2;
    if (bVar2 != 1) {
      return DAT_EXTMEM_0faf;
    }
    bVar2 = 0;
    do {
      param_1 = *(undefined1 *)
                 CONCAT11(DAT_EXTMEM_0a06 - ((CARRY1(DAT_EXTMEM_0a07,bVar2) << 7) >> 7),
                          DAT_EXTMEM_0a07 + bVar2);
      if (*(char *)CONCAT11(DAT_EXTMEM_0fb0 - ((CARRY1(DAT_EXTMEM_0fb1,bVar2) << 7) >> 7),
                            DAT_EXTMEM_0fb1 + bVar2) != BANK0_R6) {
        DAT_EXTMEM_0faf = '\0';
        break;
      }
      DAT_EXTMEM_0faf = '\x01';
      bVar2 = bVar2 + 1;
    } while (bVar2 != 0x20);
    uVar1 = 1;
    if (DAT_EXTMEM_0faf == '\x01') {
      return '\x01';
    }
  } while( true );
}



// ==== FUN_CODE_6be2 @ CODE:6be2  (63 bytes)

void FUN_CODE_6be2(void)

{
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_2d2c();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_24ce();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_1fa7();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  FUN_CODE_27d6();
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  return;
}



// ==== FUN_CODE_6c21 @ CODE:6c21  (403 bytes)

byte FUN_CODE_6c21(byte param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  
  DAT_EXTMEM_0fed = (param_1 >> 1) + 0xbc;
  DAT_EXTMEM_0fec = 7 - (((0x43 < param_1 >> 1) << 7) >> 7);
  DAT_EXTMEM_0fea = param_1;
  DAT_EXTMEM_0feb = param_2;
  cVar5 = FUN_CODE_744a(4);
  bVar6 = cVar5 - 0x30;
  if ((bVar6 < 5) << 7 < '\0') {
    bVar1 = 0x2f < bVar6;
    DAT_EXTMEM_0fef = cVar5 + 0xa0;
  }
  else {
    bVar1 = 0x39 < bVar6;
    DAT_EXTMEM_0fef = cVar5 + 0x96;
  }
  DAT_EXTMEM_0fee = '\a' - ((bVar1 << 7) >> 7);
  bVar6 = DAT_EXTMEM_0fee - (((DAT_EXTMEM_0fed < DAT_EXTMEM_0fef) << 7) >> 7);
  if (DAT_EXTMEM_0fec < bVar6) {
    return DAT_EXTMEM_0fec - bVar6;
  }
  DAT_EXTMEM_0ff1 = DAT_EXTMEM_0feb & 0xe0;
  cVar5 = '\x05';
  bVar6 = DAT_EXTMEM_0fea & 1;
  do {
    DAT_EXTMEM_0ff1 = DAT_EXTMEM_0ff1 >> 1 | bVar6 << 7;
    cVar5 = cVar5 + -1;
    bVar6 = 0;
  } while (cVar5 != '\0');
  DAT_EXTMEM_0ff0 = 0;
  cVar5 = FUN_CODE_744a(2);
  bVar6 = cVar5 - 0x30;
  cVar4 = '\0';
  cVar5 = '\0';
  FUN_CODE_74ab(10);
  cVar7 = FUN_CODE_744a(3);
  DAT_EXTMEM_0ff3 = (cVar7 - 0x30U) + bVar6;
  DAT_EXTMEM_0ff2 = cVar5 + (cVar4 - ((CARRY1(cVar7 - 0x30U,bVar6) << 7) >> 7));
  if (DAT_EXTMEM_0ff0 < (byte)(DAT_EXTMEM_0ff2 - (((DAT_EXTMEM_0ff1 < DAT_EXTMEM_0ff3) << 7) >> 7)))
  {
    bVar6 = DAT_EXTMEM_0fec;
    if (DAT_EXTMEM_0fec == BANK0_R6) {
      bVar6 = DAT_EXTMEM_0fed;
      if (DAT_EXTMEM_0fed == BANK0_R7) {
        return DAT_EXTMEM_0fed;
      }
    }
    return bVar6;
  }
  DAT_EXTMEM_0ff4 = 0;
  DAT_EXTMEM_0ff5 = DAT_EXTMEM_0feb & 0x1f;
  cVar5 = FUN_CODE_744a(1);
  bVar3 = BANK0_R5;
  bVar6 = BANK0_R4;
  cVar5 = FUN_CODE_7431(cVar5 + -0x30);
  bVar8 = cVar5 - 0x30;
  cVar5 = '\0';
  FUN_CODE_74ab(10);
  if ((DAT_EXTMEM_0fec == BANK0_R6) && (DAT_EXTMEM_0fed == BANK0_R7)) {
    if ((DAT_EXTMEM_0ff0 == BANK0_R6) &&
       (((DAT_EXTMEM_0ff1 == BANK0_R7 && (DAT_EXTMEM_0ff4 == BANK0_R4)) &&
        (DAT_EXTMEM_0ff5 == BANK0_R5)))) {
      return DAT_EXTMEM_0ff5;
    }
  }
  bVar2 = DAT_EXTMEM_0fee - (((DAT_EXTMEM_0fed < DAT_EXTMEM_0fef + 1) << 7) >> 7);
  bVar9 = DAT_EXTMEM_0fec - bVar2;
  if (DAT_EXTMEM_0fec < bVar2) {
    bVar2 = DAT_EXTMEM_0ff2 - (((DAT_EXTMEM_0ff1 < DAT_EXTMEM_0ff3 + 1) << 7) >> 7);
    bVar9 = DAT_EXTMEM_0ff0 - bVar2;
    if (DAT_EXTMEM_0ff0 < bVar2) {
      bVar9 = DAT_EXTMEM_0ff1;
      if (((DAT_EXTMEM_0ff1 != BANK0_R7) || (bVar9 = DAT_EXTMEM_0ff0, DAT_EXTMEM_0ff0 != BANK0_R6))
         || (bVar6 = (bVar6 + (cVar5 - ((CARRY1(bVar3,bVar8) << 7) >> 7))) -
                     (((DAT_EXTMEM_0ff5 < BANK0_R7 + 1) << 7) >> 7), bVar9 = DAT_EXTMEM_0ff4 - bVar6
            , (DAT_EXTMEM_0ff4 < bVar6) << 7 < '\0')) {
        return bVar9;
      }
    }
  }
  return bVar9;
}



// ==== FUN_CODE_6db4 @ CODE:6db4  (111 bytes)

void FUN_CODE_6db4(char param_1,char param_2)

{
  char cVar1;
  
  DAT_EXTMEM_0fe3 = param_1;
  DAT_EXTMEM_0fe4 = param_2;
  cVar1 = DAT_EXTMEM_06f6;
  if (DAT_EXTMEM_06f6 == '\0') {
    cVar1 = DAT_EXTMEM_06f7;
  }
  if (cVar1 == '\0') {
    if (param_2 == '\0' && param_1 == '\0') {
      cVar1 = DAT_EXTMEM_0fe8;
      if (DAT_EXTMEM_0fe8 == '\0') {
        cVar1 = DAT_EXTMEM_0fe9;
      }
      if (cVar1 != '\0') {
        return;
      }
    }
    if (param_2 != '\0' || param_1 != '\0') {
      cVar1 = DAT_EXTMEM_0fe8;
      if (DAT_EXTMEM_0fe8 == '\0') {
        cVar1 = DAT_EXTMEM_0fe9;
      }
      if (cVar1 != '\0') {
        return;
      }
    }
    return;
  }
  if (param_2 == '\0' && param_1 == '\0') {
    cVar1 = DAT_EXTMEM_0fe8;
    if (DAT_EXTMEM_0fe8 == '\0') {
      cVar1 = DAT_EXTMEM_0fe9;
    }
    if (cVar1 == '\0') {
      return;
    }
    return;
  }
  FUN_CODE_6c21(param_2);
  if (BANK0_R7 == '\x01') {
    return;
  }
  if (BANK0_R7 == '\x02') {
    return;
  }
  return;
}



// ==== cpu_detect_80c31_80c32 @ CODE:6e23  (121 bytes)

/* WARNING: Removing unreachable block (CODE,0x6e77) */
/* WARNING: Removing unreachable block (CODE,0x6e8e) */
/* WARNING: Removing unreachable block (CODE,0x6e94) */
/* WARNING: Removing unreachable block (CODE,0x6e95) */
/* WARNING: Removing unreachable block (CODE,0x6e98) */
/* WARNING: Removing unreachable block (CODE,0x6e9b) */

void cpu_detect_80c31_80c32(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  DAT_INTMEM_c0 = 0xaa;
  DAT_INTMEM_c1 = 0x55;
  DAT_INTMEM_c2 = 0xf0;
  BANK3_R0 = 0xaa;
  BANK3_R1 = 0x55;
  BANK3_R2 = 0xf0;
  _4_7 = 1;
  TL0 = 0x32;
  TH0 = 0xfe;
  TL1 = 0;
  TH1 = 0xd0;
  LATCH3_7SEG_802_15 = 0x86;
  cVar2 = '\0';
  cVar3 = '\0';
  do {
    bVar1 = T1;
    T1 = bVar1 ^ 1;
    cVar3 = cVar3 + '\x01';
    if (cVar3 == '\0') {
      cVar2 = cVar2 + '\x01';
    }
  } while ((cVar2 != 'N') || (cVar3 != ' '));
  return;
}



// ==== FUN_CODE_6e9c @ CODE:6e9c  (47 bytes)

void FUN_CODE_6e9c(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = P1_6;
  if (cVar2 != '\0') {
    EA = 0;
    while (cVar2 = P1_6, cVar2 != '\0') {
      bVar1 = T1;
      T1 = bVar1 ^ 1;
      cVar3 = '\0';
      cVar2 = '\0';
      do {
        cVar3 = cVar3 + '\x01';
        if (cVar3 == '\0') {
          cVar2 = cVar2 + '\x01';
        }
      } while ((cVar2 != '\x13') || (cVar3 != -0x78));
      bVar1 = LATCH0_EZ_row_color_LED_bank;
      LATCH0_EZ_row_color_LED_bank = bVar1 ^ 0x20;
    }
    bVar1 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar1 & 0xdf;
    bVar1 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar1 | 0x80;
    EA = 1;
  }
  return;
}



// ==== FUN_CODE_6ecb @ CODE:6ecb  (86 bytes)

void FUN_CODE_6ecb(char param_1)

{
  byte bVar1;
  
  EA = 0;
  if (param_1 == '\x01') {
    bVar1 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar1 & 0x7f;
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 & 0xdf;
  }
  else if (param_1 == '\x02') {
    bVar1 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar1 | 0x80;
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 | 0x20;
  }
  else if (param_1 == '\x03') {
    bVar1 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar1 & 0x7f;
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 | 0x20;
  }
  else if (param_1 == '\0') {
    bVar1 = LATCH0_EZ_row_color_LED_bank;
    LATCH0_EZ_row_color_LED_bank = bVar1 | 0x80;
    bVar1 = LATCH2_module_enable;
    LATCH2_module_enable = bVar1 & 0xdf;
  }
  DAT_EXTMEM_0f8a = param_1;
  EA = 1;
  return;
}



// ==== FUN_CODE_6f21 @ CODE:6f21  (93 bytes)

/* WARNING: Removing unreachable block (CODE,0x6f7d) */

void FUN_CODE_6f21(void)

{
  LATCH3_7SEG_802_15 = 0x7f;
  TI = 1;
  do {
  } while( true );
}



// ==== FUN_CODE_6f7e @ CODE:6f7e  (132 bytes)

byte FUN_CODE_6f7e(byte param_1)

{
  byte bVar1;
  
  if (((param_1 < 0x20) << 7 < '\0') || ((_2_5 != '\x01' && (0x7f < param_1)))) {
    param_1 = 0x20;
  }
  if ((_3_3 == '\x01') ||
     ((bVar1 = DAT_EXTMEM_0964, DAT_EXTMEM_0964 == 2 &&
      (bVar1 = DAT_EXTMEM_09ed, DAT_EXTMEM_09ed == 0)))) {
    _5_0 = 1;
    bVar1 = DAT_EXTMEM_0f58 - 8;
    if (DAT_EXTMEM_0f58 < 8) {
      *(byte *)CONCAT11(-(((0x18 < DAT_EXTMEM_0f58) << 7) >> 7),DAT_EXTMEM_0f58 - 0x19) = param_1;
      DAT_EXTMEM_0f58 = DAT_EXTMEM_0f58 + 1;
      return DAT_EXTMEM_0f58;
    }
  }
  else if (_3_1 == '\0') {
    if (_3_0 != '\0') {
      _5_0 = 1;
      bVar1 = DAT_EXTMEM_0f5a - 0x2d;
      if (DAT_EXTMEM_0f5a < 0x2d) {
        *(byte *)CONCAT11(-(((0x18 < DAT_EXTMEM_0f5a) << 7) >> 7),DAT_EXTMEM_0f5a - 0x19) = param_1;
        bVar1 = DAT_EXTMEM_0f5a + 1;
        DAT_EXTMEM_0f5a = bVar1;
      }
    }
  }
  else {
    _5_0 = 1;
    bVar1 = DAT_EXTMEM_0f59 - 0x18;
    if (DAT_EXTMEM_0f59 < 0x18) {
      *(byte *)CONCAT11(-(((0x18 < DAT_EXTMEM_0f59) << 7) >> 7),DAT_EXTMEM_0f59 - 0x19) = param_1;
      DAT_EXTMEM_0f59 = DAT_EXTMEM_0f59 + 1;
      return DAT_EXTMEM_0f59;
    }
  }
  return bVar1;
}



// ==== FUN_CODE_7002 @ CODE:7002  (22 bytes)

char FUN_CODE_7002(char param_1,byte param_2)

{
  for (; param_2 < param_1 + 1U; param_2 = param_2 + 1) {
    *(undefined1 *)CONCAT11(-(((0x18 < param_2) << 7) >> 7),param_2 - 0x19) = 0x20;
  }
  return param_2 - (param_1 + 1U);
}



// ==== FUN_CODE_7018 @ CODE:7018  (185 bytes)

undefined1 FUN_CODE_7018(char param_1)

{
  char cVar1;
  
  DAT_EXTMEM_0fb0 = 0;
  if (param_1 != '\x01') {
    if (param_1 == '\0') {
      DAT_EXTMEM_2aaa = 0x55;
      DAT_EXTMEM_5555 = 0x90;
      DAT_EXTMEM_0fb1 = BANK0_R4;
      DAT_EXTMEM_0fb2 = BANK0_R5;
      cVar1 = '\0';
      do {
        if ((*(char *)CONCAT11(DAT_EXTMEM_0fb1,BANK0_R5) != '\x01') ||
           (((char *)CONCAT11(DAT_EXTMEM_0fb1,BANK0_R5))[1] != ' ')) {
          DAT_EXTMEM_0fb0 = 2;
          break;
        }
        DAT_EXTMEM_0fb0 = 1;
        DAT_EXTMEM_0fb1 = DAT_EXTMEM_0fb1 + '\x01';
        cVar1 = cVar1 + '\x01';
      } while (cVar1 != '\n');
    }
    else {
      DAT_EXTMEM_0fb0 = 2;
    }
  }
  DAT_EXTMEM_0faf = param_1;
  FUN_CODE_70d1(param_1);
  return DAT_EXTMEM_0fb0;
}



// ==== FUN_CODE_70d1 @ CODE:70d1  (34 bytes)

void FUN_CODE_70d1(char param_1)

{
  if (param_1 == '\0') {
    DAT_EXTMEM_2aaa = 0x55;
    DAT_EXTMEM_5555 = 0xf0;
  }
  return;
}



// ==== FUN_CODE_70f3 @ CODE:70f3  (86 bytes)

undefined1 FUN_CODE_70f3(char param_1)

{
  char cVar1;
  
  DAT_EXTMEM_0fae = 0xff;
  if (param_1 == '\0') {
    _5_2 = 0;
    FUN_CODE_6ecb(0);
    cVar1 = '\0';
    FUN_CODE_7018(0x10,0);
    if (cVar1 == '\x01') {
      FUN_CODE_7149(0);
      _5_2 = 1;
    }
    _5_3 = 0;
    FUN_CODE_6ecb(1);
    cVar1 = '\0';
    FUN_CODE_7018(0x10,0);
    if (cVar1 == '\x01') {
      FUN_CODE_7149(0);
      _5_3 = 1;
    }
    DAT_EXTMEM_09d3 = 0x4e;
    DAT_EXTMEM_09d4 = 0x20;
    FUN_CODE_6ecb(0);
    DAT_EXTMEM_0fae = 1;
  }
  return DAT_EXTMEM_0fae;
}



// ==== FUN_CODE_7149 @ CODE:7149  (64 bytes)

void FUN_CODE_7149(char param_1)

{
  if (param_1 == '\0') {
    DAT_EXTMEM_2aaa = 0x55;
    DAT_EXTMEM_5555 = 0x10;
  }
  return;
}



// ==== FUN_CODE_7189 @ CODE:7189  (269 bytes)

undefined1 FUN_CODE_7189(undefined1 param_1,undefined1 param_2,undefined1 param_3,char param_4)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte bVar4;
  
  DAT_EXTMEM_0fb7 = 1;
  DAT_EXTMEM_09d3 = 0x4e;
  DAT_EXTMEM_09d4 = 0x20;
  bVar2 = 0;
  bVar1 = 0;
  DAT_EXTMEM_0fae = param_4;
  DAT_EXTMEM_0faf = param_3;
  DAT_EXTMEM_0fb0 = param_2;
  DAT_EXTMEM_0fb1 = param_1;
  while( true ) {
    if ((byte)(DAT_EXTMEM_0fb5 - (((bVar2 < DAT_EXTMEM_0fb6) << 7) >> 7)) <= bVar1) {
      return DAT_EXTMEM_0fb7;
    }
    if (DAT_EXTMEM_0fae == '\x01') break;
    if (DAT_EXTMEM_0fae != '\0') {
      DAT_EXTMEM_0fb7 = 0;
      return 0;
    }
    DAT_EXTMEM_2aaa = 0x55;
    DAT_EXTMEM_5555 = 0xa0;
    uVar3 = FUN_CODE_744a(CONCAT11(bVar1,bVar2),DAT_EXTMEM_0fb1,DAT_EXTMEM_0fb0,DAT_EXTMEM_0faf,0x55
                          ,0x55);
    FUN_CODE_7489(uVar3,CONCAT11(bVar1,bVar2),DAT_EXTMEM_0fb4,DAT_EXTMEM_0fb3,DAT_EXTMEM_0fb2);
    bVar4 = FUN_CODE_744a(CONCAT11(bVar1,bVar2),DAT_EXTMEM_0fb1,DAT_EXTMEM_0fb0,DAT_EXTMEM_0faf);
    DAT_EXTMEM_0fb8 = bVar4 & 0x80;
    _5_2 = '\x01';
    while (_5_2 != '\0') {
      DAT_EXTMEM_0fb9 =
           FUN_CODE_744a(CONCAT11(bVar1,bVar2),DAT_EXTMEM_0fb4,DAT_EXTMEM_0fb3,DAT_EXTMEM_0fb2);
      if (DAT_EXTMEM_0fb8 == BANK0_R6) {
        _5_2 = '\0';
      }
      else if ((DAT_EXTMEM_0fb9 >> 5 & 1) != 0) {
        if (DAT_EXTMEM_0fb8 == BANK0_R7) {
          _5_2 = '\0';
        }
        else {
          FUN_CODE_70d1(DAT_EXTMEM_0fb9 & 0x80,DAT_EXTMEM_0fae);
          DAT_EXTMEM_0fb7 = 0;
          _5_2 = '\0';
        }
      }
    }
    bVar2 = bVar2 + 1;
    if (bVar2 == 0) {
      bVar1 = bVar1 + 1;
    }
  }
  DAT_EXTMEM_0fb7 = 0;
  return 0;
}



// ==== FUN_CODE_7296 @ CODE:7296  (9 bytes)

void FUN_CODE_7296(char param_1)

{
  param_1 = param_1 + '\x01';
  while (param_1 = param_1 + -1, param_1 != '\0') {
    nop();
    nop();
    nop();
  }
  return;
}



// ==== FUN_CODE_729f @ CODE:729f  (13 bytes)

void FUN_CODE_729f(char param_1)

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



// ==== reset_entry @ CODE:72ac  (132 bytes)

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
  SP = 0x5b;
  pbVar7 = &DAT_CODE_3971;
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
        bVar5 = *(byte *)((ushort)((bVar3 & 7) + 0xc) + 0x72df);
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
  main();
  return;
}



// ==== FUN_CODE_7408 @ CODE:7408  (48 bytes)

char FUN_CODE_7408(undefined1 param_1,char param_2,char param_3,char param_4,char param_5)

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
                    /* WARNING: Could not recover jumptable at 0x7430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  cVar2 = (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x7388))(param_1,param_4);
  return cVar2;
}



// ==== FUN_CODE_7431 @ CODE:7431  (25 bytes)

undefined1 FUN_CODE_7431(undefined1 *param_1,undefined1 param_2,char param_3)

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



// ==== FUN_CODE_744a @ CODE:744a  (45 bytes)

undefined1 FUN_CODE_744a(undefined2 param_1,byte param_2,char param_3,char param_4)

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



// ==== FUN_CODE_7477 @ CODE:7477  (18 bytes)

void FUN_CODE_7477(undefined1 param_1,undefined1 *param_2,undefined1 param_3,char param_4)

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



// ==== FUN_CODE_7489 @ CODE:7489  (34 bytes)

void FUN_CODE_7489(undefined1 param_1,undefined2 param_2,byte param_3,char param_4,char param_5)

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



// ==== FUN_CODE_74ab @ CODE:74ab  (20 bytes)

char FUN_CODE_74ab(char param_1,byte param_2,char param_3,byte param_4)

{
  return param_1 * param_4 + param_3 * param_2 + (char)((ushort)param_4 * (ushort)param_2 >> 8);
}



// ==== FUN_CODE_74bf @ CODE:74bf  (54 bytes)

char FUN_CODE_74bf(char param_1,char param_2,char param_3,char param_4)

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
    FUN_CODE_7ba1(param_1,param_2,param_3,param_4);
    cVar4 = -(param_1 - (((param_2 != '\0') << 7) >> 7));
  }
  else {
    cVar4 = FUN_CODE_7ba1(param_1,param_2);
  }
  cVar3 = F0;
  if (cVar3 != '\0') {
    cVar4 = -(param_3 - (((param_4 != '\0') << 7) >> 7));
  }
  return cVar4;
}



// ==== FUN_CODE_74f5 @ CODE:74f5  (22 bytes)

void FUN_CODE_74f5(char param_1,short param_2,byte param_3)

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



// ==== FUN_CODE_750b @ CODE:750b  (22 bytes)

char FUN_CODE_750b(char param_1,short param_2,byte param_3)

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



// ==== FUN_CODE_7521 @ CODE:7521  (56 bytes)

undefined1 FUN_CODE_7521(undefined2 param_1,byte param_2,char param_3,char param_4)

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



// ==== FUN_CODE_7559 @ CODE:7559  (46 bytes)

void FUN_CODE_7559(undefined1 param_1,undefined2 param_2,undefined1 param_3,byte param_4,
                  char param_5,char param_6)

{
  byte bVar2;
  undefined1 *puVar1;
  
  bVar2 = (byte)param_2;
  if (param_6 == '\x01') {
    puVar1 = (undefined1 *)
             CONCAT11((char)((ushort)param_2 >> 8) + (param_5 - ((CARRY1(bVar2,param_4) << 7) >> 7))
                      ,bVar2 + param_4);
    *puVar1 = param_1;
    puVar1[1] = param_3;
    return;
  }
  if (param_6 == '\0') {
    *(undefined1 *)(param_4 + bVar2) = param_1;
    ((undefined1 *)(param_4 + bVar2))['\x01'] = param_3;
    return;
  }
  if (param_6 == -2) {
    *(undefined1 *)(ushort)(param_4 + bVar2) = param_1;
    *(undefined1 *)(ushort)(param_4 + bVar2 + 1) = param_3;
    return;
  }
  return;
}



// ==== FUN_CODE_7587 @ CODE:7587  (12 bytes)

char FUN_CODE_7587(byte param_1,undefined2 param_2,byte param_3)

{
  return (char)((ushort)param_1 * (ushort)param_3 >> 8) +
         ((char)((ushort)param_2 >> 8) -
         ((CARRY1((byte)((ushort)param_1 * (ushort)param_3),(byte)param_2) << 7) >> 7));
}



// ==== FUN_CODE_771b @ CODE:771b  (51 bytes)

char FUN_CODE_771b(byte param_1,char param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  bVar1 = param_3 + 2;
  bVar2 = bVar1;
  if ((bVar1 < 4) && (bVar2 = param_2 + 2, bVar2 < 4)) {
    bVar1 = (bVar2 * '\x02' | bVar2 >> 7) << 1 | (bVar2 & 0x7f) >> 6 | bVar1;
                    /* WARNING: Could not recover jumptable at 0x7737. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    cVar3 = (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x760c))();
    return cVar3;
  }
  cVar3 = '\0';
  if (bVar2 != 0 || param_1 != 0) {
    cVar3 = (bVar2 ^ 0x80) - ((param_1 ^ 0x80) + 1);
  }
  return cVar3;
}



// ==== FUN_CODE_7804 @ CODE:7804  (36 bytes)

char FUN_CODE_7804(undefined1 param_1,char param_2,char param_3)

{
  byte bVar1;
  char cVar2;
  
  if ((param_3 + 2U < 4) && (bVar1 = param_2 + 2, bVar1 < 4)) {
    bVar1 = (bVar1 * '\x02' | bVar1 >> 7) << 1 | (bVar1 & 0x7f) >> 6 | param_3 + 2U;
                    /* WARNING: Could not recover jumptable at 0x7820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    cVar2 = (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x7788))(param_1);
    return cVar2;
  }
  return param_3;
}



// ==== FUN_CODE_79a7 @ CODE:79a7  (53 bytes)

void FUN_CODE_79a7(byte param_1,char param_2,char param_3,char param_4,char param_5)

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
                    /* WARNING: Could not recover jumptable at 0x79cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((ushort)(bVar1 << 1 | bVar1 >> 7) + 0x7898))(param_4);
      return;
    }
  }
  else if (bVar2 == param_1) {
    return;
  }
  return;
}



// ==== FUN_CODE_79d0 @ CODE:79d0  (45 bytes)

void FUN_CODE_79d0(undefined1 *param_1,undefined1 param_2,char param_3,undefined1 param_4,
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



// ==== FUN_CODE_7b77 @ CODE:7b77  (51 bytes)

char FUN_CODE_7b77(undefined1 param_1,char param_2,char param_3,char param_4,char param_5)

{
  char cVar1;
  byte bVar2;
  
  if (((3 < param_3 + 2U) || (bVar2 = param_2 + 2, 3 < bVar2)) ||
     (bVar2 = (bVar2 * '\x02' | bVar2 >> 7) << 1 | (bVar2 & 0x7f) >> 6 | param_3 + 2U,
     param_4 == '\0' && param_5 == '\0')) {
    return param_3;
  }
  cVar1 = param_4;
  if (param_5 != '\0') {
    cVar1 = param_4 + '\x01';
  }
                    /* WARNING: Could not recover jumptable at 0x7ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  cVar1 = (*(code *)((ushort)(bVar2 << 1 | bVar2 >> 7) + 0x7a83))(param_1,param_4,cVar1);
  return cVar1;
}



// ==== FUN_CODE_7ba1 @ CODE:7ba1  (85 bytes)

byte FUN_CODE_7ba1(char param_1,byte param_2,byte param_3,byte param_4)

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
LAB_CODE_7bdf:
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
          goto LAB_CODE_7bdf;
        }
      }
      param_4 = param_4 + 1;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
  }
  return bVar5;
}



// ==== FUN_CODE_7bf6 @ CODE:7bf6  (103 bytes)

char FUN_CODE_7bf6(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  
  DAT_EXTMEM_0fae = param_3;
  DAT_EXTMEM_0faf = param_2;
  DAT_EXTMEM_0fb0 = param_1;
  while( true ) {
    bVar2 = FUN_CODE_7431(DAT_EXTMEM_0fb3,DAT_EXTMEM_0fb2,DAT_EXTMEM_0fb1);
    bVar3 = FUN_CODE_7431(DAT_EXTMEM_0fb0,DAT_EXTMEM_0faf,DAT_EXTMEM_0fae);
    if (bVar3 != bVar2) {
      bVar2 = (bVar2 ^ 0x80) + 1;
      cVar1 = (bVar3 ^ 0x80) - bVar2;
      if ((bVar3 ^ 0x80) < bVar2) {
        return cVar1;
      }
      return cVar1;
    }
    if (bVar3 == 0) break;
    cVar1 = -1;
    cVar4 = FUN_CODE_74f5(0xfb4);
    if (cVar4 == '\0' && cVar1 == '\0') {
      return '\0';
    }
    FUN_CODE_74f5(0,0xfaf,1);
    FUN_CODE_74f5(0,0xfb2,1);
  }
  return '\0';
}



// ==== FUN_CODE_7c5d @ CODE:7c5d  (104 bytes)

undefined1 FUN_CODE_7c5d(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  undefined1 uVar4;
  
  DAT_EXTMEM_0fb6 = 0;
  DAT_EXTMEM_0fb7 = 0;
  DAT_EXTMEM_0fae = param_3;
  DAT_EXTMEM_0faf = param_2;
  DAT_EXTMEM_0fb0 = param_1;
  while( true ) {
    cVar1 = -1;
    cVar3 = FUN_CODE_750b(0xfb4);
    if (cVar3 == '\0' && cVar1 == '\0') break;
    cVar1 = FUN_CODE_7431(DAT_EXTMEM_0fb3,DAT_EXTMEM_0fb2,DAT_EXTMEM_0fb1);
    uVar2 = 1;
    uVar4 = FUN_CODE_750b(0,0xfb6,1,DAT_EXTMEM_0fb0,DAT_EXTMEM_0faf,DAT_EXTMEM_0fae);
    FUN_CODE_7489(cVar1,CONCAT11(uVar4,uVar2));
    if (cVar1 != '\0') {
      FUN_CODE_74f5(0,0xfb2,1);
    }
  }
  return DAT_EXTMEM_0fb0;
}



// ==== FUN_CODE_7cc5 @ CODE:7cc5  (216 bytes)

byte FUN_CODE_7cc5(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  char in_PSW;
  byte bVar5;
  char *pcVar6;
  
  DAT_EXTMEM_0fb7 = param_3;
  DAT_EXTMEM_0fb8 = param_2;
  DAT_EXTMEM_0fb9 = param_1;
  while( true ) {
    uVar1 = FUN_CODE_7431(DAT_EXTMEM_0fb9,DAT_EXTMEM_0fb8,DAT_EXTMEM_0fb7);
    FUN_CODE_7d9d(uVar1);
    if (-1 < in_PSW) break;
    FUN_CODE_74f5(0,0xfb8,1);
  }
  _5_3 = 1;
  bVar2 = FUN_CODE_7431(DAT_EXTMEM_0fb9,DAT_EXTMEM_0fb8,DAT_EXTMEM_0fb7);
  if ((bVar2 == 0x2b) || (bVar5 = (bVar2 < 0x2d) << 7, bVar2 == 0x2d)) {
    uVar1 = 1;
    uVar3 = FUN_CODE_750b(0,0xfb8,1,DAT_EXTMEM_0fb7);
    cVar4 = FUN_CODE_7431(uVar1,uVar3);
    if (cVar4 == '-') {
      bVar5 = 0;
    }
    else {
      bVar5 = 0x80;
    }
    _5_3 = bVar5 >> 7;
  }
  DAT_EXTMEM_0fba = 0;
  DAT_EXTMEM_0fbb = 0;
  while( true ) {
    uVar1 = FUN_CODE_7431(DAT_EXTMEM_0fb9,DAT_EXTMEM_0fb8,DAT_EXTMEM_0fb7);
    FUN_CODE_000e(uVar1);
    if (-1 < (char)bVar5) break;
    bVar2 = FUN_CODE_7431(DAT_EXTMEM_0fb9,DAT_EXTMEM_0fb8,DAT_EXTMEM_0fb7);
    bVar5 = bVar2 - 0x30;
    cVar4 = ((char)bVar2 >> 7) + (-1 - (((0x2f < bVar2) << 7) >> 7));
    pcVar6 = (char *)&DAT_EXTMEM_0fbb;
    bVar2 = DAT_EXTMEM_0fbb;
    FUN_CODE_74ab(0,10);
    *pcVar6 = bVar2 + bVar5;
    bVar2 = cVar4 - ((CARRY1(bVar2,bVar5) << 7) >> 7);
    bVar5 = CARRY1(DAT_EXTMEM_0fba,bVar2) << 7;
    DAT_EXTMEM_0fba = DAT_EXTMEM_0fba + bVar2;
    FUN_CODE_74f5(0,0xfb8,1);
  }
  if (_5_3 == 0) {
    bVar2 = -(DAT_EXTMEM_0fba - (((DAT_EXTMEM_0fbb != 0) << 7) >> 7));
  }
  else {
    bVar2 = DAT_EXTMEM_0fbb;
  }
  return bVar2;
}



// ==== FUN_CODE_7d9d @ CODE:7d9d  (21 bytes)

byte FUN_CODE_7d9d(byte param_1)

{
  byte bVar1;
  
  if ((param_1 < 9) || (bVar1 = param_1 - 0xe, 0xd < param_1)) {
    bVar1 = param_1;
  }
  return bVar1;
}


