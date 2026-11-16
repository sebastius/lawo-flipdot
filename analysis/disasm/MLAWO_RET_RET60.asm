L0000:
  0000  023b87    LJMP L3B87
L0003:
  0003  c3        CLR C
  0004  ef        MOV A,R7
  0005  9d        SUBB A,R5
  0006  ff        MOV R7,A
  0007  ee        MOV A,R6
  0008  9c        SUBB A,R4
  0009  fe        MOV R6,A
  000A  22        RET
L000B:
  000B  023ab2    LJMP L3AB2
L000E:
  000E  ef        MOV A,R7
  000F  2f        ADD A,R7
  0010  5002      JNC L0014
  0012  0583      INC DPH
L0014:
  0014  2582      ADD A,DPL
  0016  f582      MOV DPL,A
  0018  e583      MOV A,DPH
  001A  3e        ADDC A,R6
  001B  2e        ADD A,R6
  001C  f583      MOV DPH,A
  001E  22        RET
  001F  db 86 00 FF 50  ; ...P
L0023:
  0023  023acd    LJMP L3ACD
  0026  db 22  ; "
L0027:
  0027  900005    MOV DPTR,#0005h
  002A  e0        MOVX A,@DPTR
  002B  fe        MOV R6,A
  002C  a3        INC DPTR
  002D  e0        MOVX A,@DPTR
  002E  ff        MOV R7,A
  002F  ef        MOV A,R7
  0030  4e        ORL A,R6
  0031  7004      JNZ L0037
  0033  c200      CLR 20h.0{b00}
  0035  8002      SJMP L0039
L0037:
  0037  c200      CLR 20h.0{b00}
L0039:
  0039  22        RET
L003A:
  003A  e519      MOV A,19h
  003C  c3        CLR C
  003D  9430      SUBB A,#30h
  003F  4007      JC L0048
  0041  e519      MOV A,19h
  0043  d3        SETB C
  0044  9439      SUBB A,#39h
  0046  4002      JC L004A
L0048:
  0048  8002      SJMP L004C
L004A:
  004A  d3        SETB C
  004B  22        RET
L004C:
  004C  c3        CLR C
  004D  22        RET
L004E:
  004E  751700    MOV 17h,#00h
  0051  751600    MOV 16h,#00h
  0054  851518    MOV 18h,15h
L0057:
  0057  e518      MOV A,18h
  0059  90025a    MOV DPTR,#025Ah
  005C  123b75    LCALL L3B75
  005F  e0        MOVX A,@DPTR
  0060  f519      MOV 19h,A
  0062  12003a    LCALL L003A
  0065  c0d0      PUSH PSW
  0067  e518      MOV A,18h
  0069  c3        CLR C
  006A  9406      SUBB A,#06h
  006C  5003      JNC L0071
  006E  d3        SETB C
  006F  8001      SJMP L0072
L0071:
  0071  c3        CLR C
L0072:
  0072  92f0      MOV B.0,C
  0074  d0d0      POP PSW
  0076  82f0      ANL C,B.0
  0078  5033      JNC L00AD
  007A  ae16      MOV R6,16h
  007C  af17      MOV R7,17h
  007E  7498      MOV A,#98h
  0080  d3        SETB C
  0081  9f        SUBB A,R7
  0082  7419      MOV A,#19h
  0084  9e        SUBB A,R6
  0085  401c      JC L00A3
  0087  740a      MOV A,#0Ah
  0089  123b31    LCALL L3B31
  008C  e518      MOV A,18h
  008E  90025a    MOV DPTR,#025Ah
  0091  123b75    LCALL L3B75
  0094  e0        MOVX A,@DPTR
  0095  c3        CLR C
  0096  9430      SUBB A,#30h
  0098  2f        ADD A,R7
  0099  ff        MOV R7,A
  009A  5001      JNC L009D
  009C  0e        INC R6
L009D:
  009D  8e16      MOV 16h,R6
  009F  8f17      MOV 17h,R7
  00A1  8006      SJMP L00A9
L00A3:
  00A3  7516ff    MOV 16h,#FFh
  00A6  7517ff    MOV 17h,#FFh
L00A9:
  00A9  0518      INC 18h
  00AB  80aa      SJMP L0057
L00AD:
  00AD  ae16      MOV R6,16h
  00AF  af17      MOV R7,17h
  00B1  22        RET
L00B2:
  00B2  7513ff    MOV 13h,#FFh
  00B5  751400    MOV 14h,#00h
L00B8:
  00B8  e514      MOV A,14h
  00BA  c3        CLR C
  00BB  9512      SUBB A,12h
  00BD  5035      JNC L00F4
  00BF  e514      MOV A,14h
  00C1  900219    MOV DPTR,#0219h
  00C4  123b75    LCALL L3B75
  00C7  e0        MOVX A,@DPTR
  00C8  45e0      ORL A,ACC
  00CA  30d016    JNB P,L00E3
  00CD  e514      MOV A,14h
  00CF  900219    MOV DPTR,#0219h
  00D2  123b75    LCALL L3B75
  00D5  e0        MOVX A,@DPTR
  00D6  6480      XRL A,#80h
  00D8  fe        MOV R6,A
  00D9  e514      MOV A,14h
  00DB  900219    MOV DPTR,#0219h
  00DE  123b75    LCALL L3B75
  00E1  ee        MOV A,R6
  00E2  f0        MOVX @DPTR,A
L00E3:
  00E3  e514      MOV A,14h
  00E5  900219    MOV DPTR,#0219h
  00E8  123b75    LCALL L3B75
  00EB  e0        MOVX A,@DPTR
  00EC  6513      XRL A,13h
  00EE  f513      MOV 13h,A
  00F0  0514      INC 14h
  00F2  80c4      SJMP L00B8
L00F4:
  00F4  e514      MOV A,14h
  00F6  900219    MOV DPTR,#0219h
  00F9  123b75    LCALL L3B75
  00FC  e513      MOV A,13h
  00FE  f0        MOVX @DPTR,A
  00FF  22        RET
L0100:
  0100  751000    MOV 10h,#00h
  0103  90025a    MOV DPTR,#025Ah
  0106  e0        MOVX A,@DPTR
  0107  b46129    CJNE A,#61h,L0133
  010A  90025b    MOV DPTR,#025Bh
  010D  e0        MOVX A,@DPTR
  010E  f519      MOV 19h,A
  0110  12003a    LCALL L003A
  0113  5005      JNC L011A
  0115  751007    MOV 10h,#07h
  0118  8016      SJMP L0130
L011A:
  011A  90025b    MOV DPTR,#025Bh
  011D  e0        MOVX A,@DPTR
  011E  b45605    CJNE A,#56h,L0126
  0121  751008    MOV 10h,#08h
  0124  800a      SJMP L0130
L0126:
  0126  90025b    MOV DPTR,#025Bh
  0129  e0        MOVX A,@DPTR
  012A  b45403    CJNE A,#54h,L0130
  012D  751009    MOV 10h,#09h
L0130:
  0130  0201b8    LJMP L01B8
L0133:
  0133  90025a    MOV DPTR,#025Ah
  0136  e0        MOVX A,@DPTR
  0137  b46c28    CJNE A,#6Ch,L0162
  013A  90025b    MOV DPTR,#025Bh
  013D  e0        MOVX A,@DPTR
  013E  f519      MOV 19h,A
  0140  12003a    LCALL L003A
  0143  5005      JNC L014A
  0145  751001    MOV 10h,#01h
  0148  8016      SJMP L0160
L014A:
  014A  90025b    MOV DPTR,#025Bh
  014D  e0        MOVX A,@DPTR
  014E  b44505    CJNE A,#45h,L0156
  0151  751002    MOV 10h,#02h
  0154  800a      SJMP L0160
L0156:
  0156  90025b    MOV DPTR,#025Bh
  0159  e0        MOVX A,@DPTR
  015A  b45303    CJNE A,#53h,L0160
  015D  75100a    MOV 10h,#0Ah
L0160:
  0160  8056      SJMP L01B8
L0162:
  0162  90025a    MOV DPTR,#025Ah
  0165  e0        MOVX A,@DPTR
  0166  b46b10    CJNE A,#6Bh,L0179
  0169  90025b    MOV DPTR,#025Bh
  016C  e0        MOVX A,@DPTR
  016D  f519      MOV 19h,A
  016F  12003a    LCALL L003A
  0172  5003      JNC L0177
  0174  751003    MOV 10h,#03h
L0177:
  0177  803f      SJMP L01B8
L0179:
  0179  90025a    MOV DPTR,#025Ah
  017C  e0        MOVX A,@DPTR
  017D  b47a1e    CJNE A,#7Ah,L019E
  0180  90025b    MOV DPTR,#025Bh
  0183  e0        MOVX A,@DPTR
  0184  f519      MOV 19h,A
  0186  12003a    LCALL L003A
  0189  5005      JNC L0190
  018B  751004    MOV 10h,#04h
  018E  800c      SJMP L019C
L0190:
  0190  8000      SJMP L0192
L0192:
  0192  90025b    MOV DPTR,#025Bh
  0195  e0        MOVX A,@DPTR
  0196  b44103    CJNE A,#41h,L019C
  0199  751005    MOV 10h,#05h
L019C:
  019C  801a      SJMP L01B8
L019E:
  019E  90025a    MOV DPTR,#025Ah
  01A1  e0        MOVX A,@DPTR
  01A2  b47710    CJNE A,#77h,L01B5
  01A5  90025b    MOV DPTR,#025Bh
  01A8  e0        MOVX A,@DPTR
  01A9  f519      MOV 19h,A
  01AB  12003a    LCALL L003A
  01AE  5003      JNC L01B3
  01B0  751006    MOV 10h,#06h
L01B3:
  01B3  8003      SJMP L01B8
L01B5:
  01B5  751000    MOV 10h,#00h
L01B8:
  01B8  e510      MOV A,10h
  01BA  7003      JNZ L01BF
  01BC  02035a    LJMP L035A
L01BF:
  01BF  e510      MOV A,10h
  01C1  b4013b    CJNE A,#01h,L01FF
  01C4  7401      MOV A,#01h
  01C6  f515      MOV 15h,A
  01C8  12004e    LCALL L004E
  01CB  90000b    MOV DPTR,#000Bh
  01CE  ee        MOV A,R6
  01CF  f0        MOVX @DPTR,A
  01D0  a3        INC DPTR
  01D1  ef        MOV A,R7
  01D2  f0        MOVX @DPTR,A
  01D3  751100    MOV 11h,#00h
L01D6:
  01D6  e511      MOV A,11h
  01D8  d3        SETB C
  01D9  9403      SUBB A,#03h
  01DB  501f      JNC L01FC
  01DD  e511      MOV A,11h
  01DF  04        INC A
  01E0  90025a    MOV DPTR,#025Ah
  01E3  123b75    LCALL L3B75
  01E6  e511      MOV A,11h
  01E8  fe        MOV R6,A
  01E9  e0        MOVX A,@DPTR
  01EA  ff        MOV R7,A
  01EB  ee        MOV A,R6
  01EC  900007    MOV DPTR,#0007h
  01EF  123b75    LCALL L3B75
  01F2  ef        MOV A,R7
  01F3  f0        MOVX @DPTR,A
  01F4  7811      MOV R0,#11h
  01F6  7401      MOV A,#01h
  01F8  26        ADD A,@R0
  01F9  f6        MOV @R0,A
  01FA  50da      JNC L01D6
L01FC:
  01FC  02035a    LJMP L035A
L01FF:
  01FF  e510      MOV A,10h
  0201  b40212    CJNE A,#02h,L0216
  0204  7402      MOV A,#02h
  0206  f515      MOV 15h,A
  0208  12004e    LCALL L004E
  020B  900011    MOV DPTR,#0011h
  020E  ee        MOV A,R6
  020F  f0        MOVX @DPTR,A
  0210  a3        INC DPTR
  0211  ef        MOV A,R7
  0212  f0        MOVX @DPTR,A
  0213  02035a    LJMP L035A
L0216:
  0216  e510      MOV A,10h
  0218  b40a03    CJNE A,#0Ah,L021E
  021B  02035a    LJMP L035A
L021E:
  021E  e510      MOV A,10h
  0220  b40312    CJNE A,#03h,L0235
  0223  7401      MOV A,#01h
  0225  f515      MOV 15h,A
  0227  12004e    LCALL L004E
  022A  90001b    MOV DPTR,#001Bh
  022D  ee        MOV A,R6
  022E  f0        MOVX @DPTR,A
  022F  a3        INC DPTR
  0230  ef        MOV A,R7
  0231  f0        MOVX @DPTR,A
  0232  02035a    LJMP L035A
L0235:
  0235  e510      MOV A,10h
  0237  b40414    CJNE A,#04h,L024E
  023A  d207      SETB 20h.7{b07}
  023C  7401      MOV A,#01h
  023E  f515      MOV 15h,A
  0240  12004e    LCALL L004E
  0243  900015    MOV DPTR,#0015h
  0246  ee        MOV A,R6
  0247  f0        MOVX @DPTR,A
  0248  a3        INC DPTR
  0249  ef        MOV A,R7
  024A  f0        MOVX @DPTR,A
  024B  02035a    LJMP L035A
L024E:
  024E  e510      MOV A,10h
  0250  b40503    CJNE A,#05h,L0256
  0253  02035a    LJMP L035A
L0256:
  0256  e510      MOV A,10h
  0258  b40b05    CJNE A,#0Bh,L0260
  025B  d209      SETB 21h.1{b09}
  025D  02035a    LJMP L035A
L0260:
  0260  e510      MOV A,10h
  0262  b40612    CJNE A,#06h,L0277
  0265  7401      MOV A,#01h
  0267  f515      MOV 15h,A
  0269  12004e    LCALL L004E
  026C  900021    MOV DPTR,#0021h
  026F  ee        MOV A,R6
  0270  f0        MOVX @DPTR,A
  0271  a3        INC DPTR
  0272  ef        MOV A,R7
  0273  f0        MOVX @DPTR,A
  0274  02035a    LJMP L035A
L0277:
  0277  e510      MOV A,10h
  0279  b40743    CJNE A,#07h,L02BF
  027C  c205      CLR 20h.5{b05}
  027E  90025b    MOV DPTR,#025Bh
  0281  e0        MOVX A,@DPTR
  0282  fe        MOV R6,A
  0283  e53d      MOV A,3Dh
  0285  2430      ADD A,#30h
  0287  b50e32    CJNE A,0Eh,L02BC
  028A  300c05    JNB 21h.4{b0C},L0292
  028D  751106    MOV 11h,#06h
  0290  8003      SJMP L0295
L0292:
  0292  751100    MOV 11h,#00h
L0295:
  0295  c20c      CLR 21h.4{b0C}
  0297  7461      MOV A,#61h
  0299  900219    MOV DPTR,#0219h
  029C  f0        MOVX @DPTR,A
  029D  e511      MOV A,11h
  029F  2430      ADD A,#30h
  02A1  90021a    MOV DPTR,#021Ah
  02A4  f0        MOVX @DPTR,A
  02A5  740d      MOV A,#0Dh
  02A7  90021b    MOV DPTR,#021Bh
  02AA  f0        MOVX @DPTR,A
  02AB  7403      MOV A,#03h
  02AD  f512      MOV 12h,A
  02AF  1200b2    LCALL L00B2
  02B2  753004    MOV 30h,#04h
  02B5  d204      SETB 20h.4{b04}
  02B7  753400    MOV 34h,#00h
  02BA  d299      SETB TI
L02BC:
  02BC  02035a    LJMP L035A
L02BF:
  02BF  e510      MOV A,10h
  02C1  b40871    CJNE A,#08h,L0335
  02C4  c205      CLR 20h.5{b05}
  02C6  90025c    MOV DPTR,#025Ch
  02C9  e0        MOVX A,@DPTR
  02CA  6430      XRL A,#30h
  02CC  600c      JZ L02DA
  02CE  90025c    MOV DPTR,#025Ch
  02D1  e0        MOVX A,@DPTR
  02D2  fe        MOV R6,A
  02D3  e53d      MOV A,3Dh
  02D5  2430      ADD A,#30h
  02D7  b50e59    CJNE A,0Eh,L0333
L02DA:
  02DA  7461      MOV A,#61h
  02DC  900219    MOV DPTR,#0219h
  02DF  f0        MOVX @DPTR,A
  02E0  7456      MOV A,#56h
  02E2  90021a    MOV DPTR,#021Ah
  02E5  f0        MOVX @DPTR,A
  02E6  90380b    MOV DPTR,#380Bh
  02E9  e4        CLR A
  02EA  93        MOVC A,@A+DPTR
  02EB  90021b    MOV DPTR,#021Bh
  02EE  f0        MOVX @DPTR,A
  02EF  90380c    MOV DPTR,#380Ch
  02F2  e4        CLR A
  02F3  93        MOVC A,@A+DPTR
  02F4  90021c    MOV DPTR,#021Ch
  02F7  f0        MOVX @DPTR,A
  02F8  90380d    MOV DPTR,#380Dh
  02FB  e4        CLR A
  02FC  93        MOVC A,@A+DPTR
  02FD  90021d    MOV DPTR,#021Dh
  0300  f0        MOVX @DPTR,A
  0301  90380e    MOV DPTR,#380Eh
  0304  e4        CLR A
  0305  93        MOVC A,@A+DPTR
  0306  90021e    MOV DPTR,#021Eh
  0309  f0        MOVX @DPTR,A
  030A  90380f    MOV DPTR,#380Fh
  030D  e4        CLR A
  030E  93        MOVC A,@A+DPTR
  030F  90021f    MOV DPTR,#021Fh
  0312  f0        MOVX @DPTR,A
  0313  903810    MOV DPTR,#3810h
  0316  e4        CLR A
  0317  93        MOVC A,@A+DPTR
  0318  900220    MOV DPTR,#0220h
  031B  f0        MOVX @DPTR,A
  031C  740d      MOV A,#0Dh
  031E  900221    MOV DPTR,#0221h
  0321  f0        MOVX @DPTR,A
  0322  7409      MOV A,#09h
  0324  f512      MOV 12h,A
  0326  1200b2    LCALL L00B2
  0329  75300a    MOV 30h,#0Ah
  032C  d204      SETB 20h.4{b04}
  032E  753400    MOV 34h,#00h
  0331  d299      SETB TI
L0333:
  0333  8025      SJMP L035A
L0335:
  0335  e510      MOV A,10h
  0337  b40920    CJNE A,#09h,L035A
  033A  c205      CLR 20h.5{b05}
  033C  90025c    MOV DPTR,#025Ch
  033F  e0        MOVX A,@DPTR
  0340  6430      XRL A,#30h
  0342  600c      JZ L0350
  0344  90025c    MOV DPTR,#025Ch
  0347  e0        MOVX A,@DPTR
  0348  fe        MOV R6,A
  0349  e53d      MOV A,3Dh
  034B  2430      ADD A,#30h
  034D  b50e0a    CJNE A,0Eh,L035A
L0350:
  0350  90025d    MOV DPTR,#025Dh
  0353  e0        MOVX A,@DPTR
  0354  c3        CLR C
  0355  9430      SUBB A,#30h
  0357  04        INC A
  0358  f548      MOV 48h,A
L035A:
  035A  22        RET
L035B:
  035B  209803    JB RI,L0361
  035E  0203f9    LJMP L03F9
L0361:
  0361  85991a    MOV 1Ah,SBUF
  0364  c298      CLR RI
  0366  c20b      CLR 21h.3{b0B}
  0368  c20a      CLR 21h.2{b0A}
  036A  851ae0    MOV ACC,1Ah
  036D  30d008    JNB P,L0378
  0370  d20b      SETB 21h.3{b0B}
  0372  753200    MOV 32h,#00h
  0375  0203f9    LJMP L03F9
L0378:
  0378  e51a      MOV A,1Ah
  037A  547f      ANL A,#7Fh
  037C  f51b      MOV 1Bh,A
  037E  e532      MOV A,32h
  0380  702e      JNZ L03B0
  0382  e51b      MOV A,1Bh
  0384  c3        CLR C
  0385  9461      SUBB A,#61h
  0387  4007      JC L0390
  0389  e51b      MOV A,1Bh
  038B  d3        SETB C
  038C  947a      SUBB A,#7Ah
  038E  4002      JC L0392
L0390:
  0390  8014      SJMP L03A6
L0392:
  0392  e51b      MOV A,1Bh
  0394  90025a    MOV DPTR,#025Ah
  0397  f0        MOVX @DPTR,A
  0398  753101    MOV 31h,#01h
  039B  74ff      MOV A,#FFh
  039D  651a      XRL A,1Ah
  039F  f52f      MOV 2Fh,A
  03A1  753201    MOV 32h,#01h
  03A4  8008      SJMP L03AE
L03A6:
  03A6  e51b      MOV A,1Bh
  03A8  b40d03    CJNE A,#0Dh,L03AE
  03AB  753203    MOV 32h,#03h
L03AE:
  03AE  8049      SJMP L03F9
L03B0:
  03B0  e532      MOV A,32h
  03B2  b40124    CJNE A,#01h,L03D9
  03B5  e531      MOV A,31h
  03B7  d3        SETB C
  03B8  94f9      SUBB A,#F9h
  03BA  5013      JNC L03CF
  03BC  e52f      MOV A,2Fh
  03BE  651a      XRL A,1Ah
  03C0  f52f      MOV 2Fh,A
  03C2  e531      MOV A,31h
  03C4  90025a    MOV DPTR,#025Ah
  03C7  123b75    LCALL L3B75
  03CA  e51b      MOV A,1Bh
  03CC  f0        MOVX @DPTR,A
  03CD  0531      INC 31h
L03CF:
  03CF  e51b      MOV A,1Bh
  03D1  b40d03    CJNE A,#0Dh,L03D7
  03D4  753202    MOV 32h,#02h
L03D7:
  03D7  8020      SJMP L03F9
L03D9:
  03D9  e532      MOV A,32h
  03DB  b40218    CJNE A,#02h,L03F6
  03DE  e51a      MOV A,1Ah
  03E0  652f      XRL A,2Fh
  03E2  6006      JZ L03EA
  03E4  d20a      SETB 21h.2{b0A}
  03E6  c201      CLR 20h.1{b01}
  03E8  8007      SJMP L03F1
L03EA:
  03EA  c20a      CLR 21h.2{b0A}
  03EC  d201      SETB 20h.1{b01}
  03EE  120100    LCALL L0100
L03F1:
  03F1  753200    MOV 32h,#00h
  03F4  8003      SJMP L03F9
L03F6:
  03F6  753200    MOV 32h,#00h
L03F9:
  03F9  30991d    JNB TI,L0419
  03FC  c299      CLR TI
  03FE  300418    JNB 20h.4{b04},L0419
  0401  e534      MOV A,34h
  0403  c3        CLR C
  0404  9530      SUBB A,30h
  0406  500f      JNC L0417
  0408  e534      MOV A,34h
  040A  900219    MOV DPTR,#0219h
  040D  123b75    LCALL L3B75
  0410  e0        MOVX A,@DPTR
  0411  f599      MOV SBUF,A
  0413  0534      INC 34h
  0415  8002      SJMP L0419
L0417:
  0417  c204      CLR 20h.4{b04}
L0419:
  0419  22        RET
L041A:
  041A  d2b4      SETB T0
  041C  900358    MOV DPTR,#0358h
  041F  e0        MOVX A,@DPTR
  0420  fe        MOV R6,A
  0421  a3        INC DPTR
  0422  e0        MOVX A,@DPTR
  0423  ff        MOV R7,A
  0424  ef        MOV A,R7
  0425  4e        ORL A,R6
  0426  6006      JZ L042E
  0428  900358    MOV DPTR,#0358h
  042B  123b07    LCALL L3B07
L042E:
  042E  200d03    JB 21h.5{b0D},L0434
  0431  020504    LJMP L0504
L0434:
  0434  900360    MOV DPTR,#0360h
  0437  e0        MOVX A,@DPTR
  0438  540f      ANL A,#0Fh
  043A  fe        MOV R6,A
  043B  e4        CLR A
  043C  a20f      MOV C,21h.7{b0F}
  043E  33        RLC A
  043F  c4        SWAP A
  0440  54f0      ANL A,#F0h
  0442  541f      ANL A,#1Fh
  0444  4e        ORL A,R6
  0445  fe        MOV R6,A
  0446  900000    MOV DPTR,#0000h
  0449  e0        MOVX A,@DPTR
  044A  54e0      ANL A,#E0h
  044C  4e        ORL A,R6
  044D  900000    MOV DPTR,#0000h
  0450  f0        MOVX @DPTR,A
  0451  e543      MOV A,43h
  0453  75f070    MOV B,#70h
  0456  84        DIV AB
  0457  ff        MOV R7,A
  0458  7e00      MOV R6,#00h
  045A  ef        MOV A,R7
  045B  900002    MOV DPTR,#0002h
  045E  f0        MOVX @DPTR,A
  045F  e543      MOV A,43h
  0461  75f070    MOV B,#70h
  0464  84        DIV AB
  0465  adf0      MOV R5,B
  0467  7c00      MOV R4,#00h
  0469  8d2d      MOV 2Dh,R5
  046B  e543      MOV A,43h
  046D  c3        CLR C
  046E  9470      SUBB A,#70h
  0470  5027      JNC L0499
  0472  e4        CLR A
  0473  a20f      MOV C,21h.7{b0F}
  0475  33        RLC A
  0476  fe        MOV R6,A
  0477  7401      MOV A,#01h
  0479  ff        MOV R7,A
  047A  ee        MOV A,R6
  047B  0f        INC R7
  047C  23        RL A
L047D:
  047D  03        RR A
  047E  dffd      DJNZ R7,L047D
  0480  fe        MOV R6,A
  0481  e52d      MOV A,2Dh
  0483  854d83    MOV DPH,4Dh
  0486  854e82    MOV DPL,4Eh
  0489  123b75    LCALL L3B75
  048C  ee        MOV A,R6
  048D  fe        MOV R6,A
  048E  e4        CLR A
  048F  93        MOVC A,@A+DPTR
  0490  ff        MOV R7,A
  0491  ee        MOV A,R6
  0492  4f        ORL A,R7
  0493  900001    MOV DPTR,#0001h
  0496  f0        MOVX @DPTR,A
  0497  8061      SJMP L04FA
L0499:
  0499  900354    MOV DPTR,#0354h
  049C  e0        MOVX A,@DPTR
  049D  b48c2e    CJNE A,#8Ch,L04CE
  04A0  e4        CLR A
  04A1  a20f      MOV C,21h.7{b0F}
  04A3  33        RLC A
  04A4  fe        MOV R6,A
  04A5  7401      MOV A,#01h
  04A7  ff        MOV R7,A
  04A8  ee        MOV A,R6
  04A9  0f        INC R7
  04AA  23        RL A
L04AB:
  04AB  03        RR A
  04AC  dffd      DJNZ R7,L04AB
  04AE  fe        MOV R6,A
  04AF  e52d      MOV A,2Dh
  04B1  854d83    MOV DPH,4Dh
  04B4  854e82    MOV DPL,4Eh
  04B7  fc        MOV R4,A
  04B8  7f54      MOV R7,#54h
  04BA  123b61    LCALL L3B61
  04BD  ec        MOV A,R4
  04BE  123b75    LCALL L3B75
  04C1  ee        MOV A,R6
  04C2  fe        MOV R6,A
  04C3  e4        CLR A
  04C4  93        MOVC A,@A+DPTR
  04C5  ff        MOV R7,A
  04C6  ee        MOV A,R6
  04C7  4f        ORL A,R7
  04C8  900001    MOV DPTR,#0001h
  04CB  f0        MOVX @DPTR,A
  04CC  802c      SJMP L04FA
L04CE:
  04CE  e4        CLR A
  04CF  a20f      MOV C,21h.7{b0F}
  04D1  33        RLC A
  04D2  fe        MOV R6,A
  04D3  7401      MOV A,#01h
  04D5  ff        MOV R7,A
  04D6  ee        MOV A,R6
  04D7  0f        INC R7
  04D8  23        RL A
L04D9:
  04D9  03        RR A
  04DA  dffd      DJNZ R7,L04D9
  04DC  fe        MOV R6,A
  04DD  e52d      MOV A,2Dh
  04DF  854d83    MOV DPH,4Dh
  04E2  854e82    MOV DPL,4Eh
  04E5  fc        MOV R4,A
  04E6  7f62      MOV R7,#62h
  04E8  123b61    LCALL L3B61
  04EB  ec        MOV A,R4
  04EC  123b75    LCALL L3B75
  04EF  ee        MOV A,R6
  04F0  fe        MOV R6,A
  04F1  e4        CLR A
  04F2  93        MOVC A,@A+DPTR
  04F3  ff        MOV R7,A
  04F4  ee        MOV A,R6
  04F5  4f        ORL A,R7
  04F6  900001    MOV DPTR,#0001h
  04F9  f0        MOVX @DPTR,A
L04FA:
  04FA  c20d      CLR 21h.5{b0D}
  04FC  d2b4      SETB T0
  04FE  d2b4      SETB T0
  0500  d2b4      SETB T0
  0502  c2b4      CLR T0
L0504:
  0504  e541      MOV A,41h
  0506  4540      ORL A,40h
  0508  6005      JZ L050F
  050A  7840      MOV R0,#40h
  050C  123b98    LCALL L3B98
L050F:
  050F  e53f      MOV A,3Fh
  0511  453e      ORL A,3Eh
  0513  6005      JZ L051A
  0515  783e      MOV R0,#3Eh
  0517  123b98    LCALL L3B98
L051A:
  051A  e52c      MOV A,2Ch
  051C  452b      ORL A,2Bh
  051E  6007      JZ L0527
  0520  b2b5      CPL T1
  0522  782b      MOV R0,#2Bh
  0524  123b98    LCALL L3B98
L0527:
  0527  758a0c    MOV TL0,#0Ch
  052A  758cfe    MOV TH0,#FEh
  052D  22        RET
L052E:
  052E  301106    JNB 22h.1{b11},L0537
  0531  e541      MOV A,41h
  0533  4540      ORL A,40h
  0535  7002      JNZ L0539
L0537:
  0537  8002      SJMP L053B
L0539:
  0539  80f3      SJMP L052E
L053B:
  053B  309603    JNB P1.6,L0541
  053E  0205c7    LJMP L05C7
L0541:
  0541  74ff      MOV A,#FFh
  0543  b53d03    CJNE A,3Dh,L0549
  0546  200502    JB 20h.5{b05},L054B
L0549:
  0549  807c      SJMP L05C7
L054B:
  054B  75363d    MOV 36h,#3Dh
  054E  753500    MOV 35h,#00h
L0551:
  0551  e536      MOV A,36h
  0553  4535      ORL A,35h
  0555  6034      JZ L058B
  0557  ae35      MOV R6,35h
  0559  af36      MOV R7,36h
  055B  1f        DEC R7
  055C  bfff01    CJNE R7,#FFh,L0560
  055F  1e        DEC R6
L0560:
  0560  900219    MOV DPTR,#0219h
  0563  123b56    LCALL L3B56
  0566  ae35      MOV R6,35h
  0568  af36      MOV R7,36h
  056A  e0        MOVX A,@DPTR
  056B  fc        MOV R4,A
  056C  90021c    MOV DPTR,#021Ch
  056F  123b56    LCALL L3B56
  0572  ec        MOV A,R4
  0573  f0        MOVX @DPTR,A
  0574  90021c    MOV DPTR,#021Ch
  0577  123b56    LCALL L3B56
  057A  e0        MOVX A,@DPTR
  057B  b40d06    CJNE A,#0Dh,L0584
  057E  e536      MOV A,36h
  0580  2404      ADD A,#04h
  0582  f530      MOV 30h,A
L0584:
  0584  7835      MOV R0,#35h
  0586  123b98    LCALL L3B98
  0589  80c6      SJMP L0551
L058B:
  058B  753601    MOV 36h,#01h
  058E  753500    MOV 35h,#00h
L0591:
  0591  ae35      MOV R6,35h
  0593  af36      MOV R7,36h
  0595  7403      MOV A,#03h
  0597  be001a    CJNE R6,#00h,L05B4
  059A  9f        SUBB A,R7
  059B  4017      JC L05B4
  059D  900219    MOV DPTR,#0219h
  05A0  123b56    LCALL L3B56
  05A3  7430      MOV A,#30h
  05A5  f0        MOVX @DPTR,A
  05A6  7836      MOV R0,#36h
  05A8  7401      MOV A,#01h
  05AA  26        ADD A,@R0
  05AB  f6        MOV @R0,A
  05AC  5004      JNC L05B2
  05AE  18        DEC R0
  05AF  e4        CLR A
  05B0  36        ADDC A,@R0
  05B1  f6        MOV @R0,A
L05B2:
  05B2  50dd      JNC L0591
L05B4:
  05B4  747a      MOV A,#7Ah
  05B6  900219    MOV DPTR,#0219h
  05B9  f0        MOVX @DPTR,A
  05BA  740d      MOV A,#0Dh
  05BC  900259    MOV DPTR,#0259h
  05BF  f0        MOVX @DPTR,A
  05C0  753400    MOV 34h,#00h
  05C3  d204      SETB 20h.4{b04}
  05C5  d299      SETB TI
L05C7:
  05C7  e53d      MOV A,3Dh
  05C9  7f0e      MOV R7,#0Eh
  05CB  903828    MOV DPTR,#3828h
  05CE  123ae8    LCALL L3AE8
  05D1  e4        CLR A
  05D2  93        MOVC A,@A+DPTR
  05D3  7004      JNZ L05D9
  05D5  d2f0      SETB B.0
  05D7  8002      SJMP L05DB
L05D9:
  05D9  c2f0      CLR B.0
L05DB:
  05DB  300002    JNB 20h.0{b00},L05E0
  05DE  b2f0      CPL B.0
L05E0:
  05E0  30f003    JNB B.0,L05E6
  05E3  d3        SETB C
  05E4  8001      SJMP L05E7
L05E6:
  05E6  c3        CLR C
L05E7:
  05E7  9210      MOV 22h.0{b10},C
  05E9  e53d      MOV A,3Dh
  05EB  7f0e      MOV R7,#0Eh
  05ED  903820    MOV DPTR,#3820h
  05F0  123ae8    LCALL L3AE8
  05F3  7851      MOV R0,#51h
  05F5  123b7e    LCALL L3B7E
  05F8  754300    MOV 43h,#00h
L05FB:
  05FB  900354    MOV DPTR,#0354h
  05FE  e0        MOVX A,@DPTR
  05FF  14        DEC A
  0600  c3        CLR C
  0601  9543      SUBB A,43h
  0603  5003      JNC L0608
  0605  0206ac    LJMP L06AC
L0608:
  0608  900360    MOV DPTR,#0360h
  060B  e4        CLR A
  060C  f0        MOVX @DPTR,A
L060D:
  060D  900360    MOV DPTR,#0360h
  0610  e0        MOVX A,@DPTR
  0611  fe        MOV R6,A
  0612  900355    MOV DPTR,#0355h
  0615  e0        MOVX A,@DPTR
  0616  14        DEC A
  0617  c3        CLR C
  0618  9e        SUBB A,R6
  0619  5003      JNC L061E
  061B  0206a1    LJMP L06A1
L061E:
  061E  900360    MOV DPTR,#0360h
  0621  e0        MOVX A,@DPTR
  0622  855183    MOV DPH,51h
  0625  855282    MOV DPL,52h
  0628  123af8    LCALL L3AF8
  062B  784f      MOV R0,#4Fh
  062D  123b7e    LCALL L3B7E
  0630  e543      MOV A,43h
  0632  900363    MOV DPTR,#0363h
  0635  123af8    LCALL L3AF8
  0638  e543      MOV A,43h
  063A  fe        MOV R6,A
  063B  e0        MOVX A,@DPTR
  063C  ff        MOV R7,A
  063D  a3        INC DPTR
  063E  e0        MOVX A,@DPTR
  063F  fc        MOV R4,A
  0640  ee        MOV A,R6
  0641  900593    MOV DPTR,#0593h
  0644  123af8    LCALL L3AF8
  0647  e0        MOVX A,@DPTR
  0648  fe        MOV R6,A
  0649  a3        INC DPTR
  064A  e0        MOVX A,@DPTR
  064B  fd        MOV R5,A
  064C  ef        MOV A,R7
  064D  6206      XRL 06h,A
  064F  ec        MOV A,R4
  0650  6205      XRL 05h,A
  0652  ac4f      MOV R4,4Fh
  0654  af50      MOV R7,50h
  0656  ee        MOV A,R6
  0657  5204      ANL 04h,A
  0659  ed        MOV A,R5
  065A  5207      ANL 07h,A
  065C  ef        MOV A,R7
  065D  4c        ORL A,R4
  065E  7005      JNZ L0665
  0660  a211      MOV C,22h.1{b11}
  0662  b3        CPL C
  0663  5030      JNC L0695
L0665:
  0665  e543      MOV A,43h
  0667  900363    MOV DPTR,#0363h
  066A  123af8    LCALL L3AF8
  066D  ae4f      MOV R6,4Fh
  066F  af50      MOV R7,50h
  0671  e0        MOVX A,@DPTR
  0672  fc        MOV R4,A
  0673  a3        INC DPTR
  0674  e0        MOVX A,@DPTR
  0675  fd        MOV R5,A
  0676  ec        MOV A,R4
  0677  5206      ANL 06h,A
  0679  ed        MOV A,R5
  067A  5207      ANL 07h,A
  067C  ef        MOV A,R7
  067D  4e        ORL A,R6
  067E  6003      JZ L0683
  0680  d3        SETB C
  0681  8001      SJMP L0684
L0683:
  0683  c3        CLR C
L0684:
  0684  920f      MOV 21h.7{b0F},C
  0686  301002    JNB 22h.0{b10},L068B
  0689  b20f      CPL 21h.7{b0F}
L068B:
  068B  d20d      SETB 21h.5{b0D}
L068D:
  068D  300d05    JNB 21h.5{b0D},L0695
  0690  758781    MOV PCON,#81h
  0693  80f8      SJMP L068D
L0695:
  0695  900360    MOV DPTR,#0360h
  0698  e0        MOVX A,@DPTR
  0699  2401      ADD A,#01h
  069B  f0        MOVX @DPTR,A
  069C  4003      JC L06A1
  069E  02060d    LJMP L060D
L06A1:
  06A1  7843      MOV R0,#43h
  06A3  7401      MOV A,#01h
  06A5  26        ADD A,@R0
  06A6  f6        MOV @R0,A
  06A7  4003      JC L06AC
  06A9  0205fb    LJMP L05FB
L06AC:
  06AC  753600    MOV 36h,#00h
  06AF  753500    MOV 35h,#00h
L06B2:
  06B2  ae35      MOV R6,35h
  06B4  af36      MOV R7,36h
  06B6  748b      MOV A,#8Bh
  06B8  be0027    CJNE R6,#00h,L06E2
  06BB  9f        SUBB A,R7
  06BC  4024      JC L06E2
  06BE  900363    MOV DPTR,#0363h
  06C1  12000e    LCALL L000E
  06C4  e0        MOVX A,@DPTR
  06C5  fc        MOV R4,A
  06C6  a3        INC DPTR
  06C7  e0        MOVX A,@DPTR
  06C8  fd        MOV R5,A
  06C9  900593    MOV DPTR,#0593h
  06CC  12000e    LCALL L000E
  06CF  ec        MOV A,R4
  06D0  f0        MOVX @DPTR,A
  06D1  a3        INC DPTR
  06D2  ed        MOV A,R5
  06D3  f0        MOVX @DPTR,A
  06D4  7836      MOV R0,#36h
  06D6  7401      MOV A,#01h
  06D8  26        ADD A,@R0
  06D9  f6        MOV @R0,A
  06DA  5004      JNC L06E0
  06DC  18        DEC R0
  06DD  e4        CLR A
  06DE  36        ADDC A,@R0
  06DF  f6        MOV @R0,A
L06E0:
  06E0  50d0      JNC L06B2
L06E2:
  06E2  753300    MOV 33h,#00h
  06E5  22        RET
L06E6:
  06E6  e544      MOV A,44h
  06E8  ff        MOV R7,A
  06E9  7e00      MOV R6,#00h
  06EB  e53d      MOV A,3Dh
  06ED  8e04      MOV 04h,R6
  06EF  8f05      MOV 05h,R7
  06F1  7f10      MOV R7,#10h
  06F3  903900    MOV DPTR,#3900h
  06F6  123ae8    LCALL L3AE8
  06F9  8c06      MOV 06h,R4
  06FB  8d07      MOV 07h,R5
  06FD  123b4b    LCALL L3B4B
  0700  e4        CLR A
  0701  93        MOVC A,@A+DPTR
  0702  f554      MOV 54h,A
  0704  e544      MOV A,44h
  0706  7f05      MOV R7,#05h
  0708  903a02    MOV DPTR,#3A02h
  070B  123ae8    LCALL L3AE8
  070E  e4        CLR A
  070F  93        MOVC A,@A+DPTR
  0710  f8        MOV R0,A
  0711  7401      MOV A,#01h
  0713  93        MOVC A,@A+DPTR
  0714  9006ab    MOV DPTR,#06ABh
  0717  c8        XCH A,R0
  0718  f0        MOVX @DPTR,A
  0719  a3        INC DPTR
  071A  c8        XCH A,R0
  071B  f0        MOVX @DPTR,A
  071C  9006ab    MOV DPTR,#06ABh
  071F  123b3f    LCALL L3B3F
  0722  e4        CLR A
  0723  93        MOVC A,@A+DPTR
  0724  f556      MOV 56h,A
  0726  e544      MOV A,44h
  0728  7f05      MOV R7,#05h
  072A  903a00    MOV DPTR,#3A00h
  072D  123ae8    LCALL L3AE8
  0730  e544      MOV A,44h
  0732  fe        MOV R6,A
  0733  e4        CLR A
  0734  93        MOVC A,@A+DPTR
  0735  ff        MOV R7,A
  0736  7401      MOV A,#01h
  0738  93        MOVC A,@A+DPTR
  0739  fc        MOV R4,A
  073A  ee        MOV A,R6
  073B  8f05      MOV 05h,R7
  073D  7f05      MOV R7,#05h
  073F  903a04    MOV DPTR,#3A04h
  0742  123ae8    LCALL L3AE8
  0745  e4        CLR A
  0746  93        MOVC A,@A+DPTR
  0747  f4        CPL A
  0748  04        INC A
  0749  2545      ADD A,45h
  074B  fe        MOV R6,A
  074C  e556      MOV A,56h
  074E  04        INC A
  074F  8e00      MOV 00h,R6
  0751  88f0      MOV B,R0
  0753  a4        MUL AB
  0754  ff        MOV R7,A
  0755  aef0      MOV R6,B
  0757  ec        MOV A,R4
  0758  2f        ADD A,R7
  0759  ff        MOV R7,A
  075A  ed        MOV A,R5
  075B  3e        ADDC A,R6
  075C  fe        MOV R6,A
  075D  8e58      MOV 58h,R6
  075F  8f59      MOV 59h,R7
  0761  855883    MOV DPH,58h
  0764  855982    MOV DPL,59h
  0767  e4        CLR A
  0768  93        MOVC A,@A+DPTR
  0769  f557      MOV 57h,A
  076B  7e00      MOV R6,#00h
  076D  7f01      MOV R7,#01h
  076F  e557      MOV A,57h
  0771  14        DEC A
  0772  123b15    LCALL L3B15
  0775  8e50      MOV 50h,R6
  0777  8f51      MOV 51h,R7
  0779  e557      MOV A,57h
  077B  2542      ADD A,42h
  077D  fc        MOV R4,A
  077E  900354    MOV DPTR,#0354h
  0781  e0        MOVX A,@DPTR
  0782  c3        CLR C
  0783  9c        SUBB A,R4
  0784  5003      JNC L0789
  0786  020856    LJMP L0856
L0789:
  0789  755200    MOV 52h,#00h
L078C:
  078C  e557      MOV A,57h
  078E  14        DEC A
  078F  c3        CLR C
  0790  9552      SUBB A,52h
  0792  5003      JNC L0797
  0794  020850    LJMP L0850
L0797:
  0797  755300    MOV 53h,#00h
L079A:
  079A  e556      MOV A,56h
  079C  14        DEC A
  079D  c3        CLR C
  079E  9553      SUBB A,53h
  07A0  5003      JNC L07A5
  07A2  020836    LJMP L0836
L07A5:
  07A5  900355    MOV DPTR,#0355h
  07A8  e0        MOVX A,@DPTR
  07A9  14        DEC A
  07AA  fe        MOV R6,A
  07AB  e554      MOV A,54h
  07AD  2553      ADD A,53h
  07AF  f4        CPL A
  07B0  04        INC A
  07B1  2e        ADD A,R6
  07B2  f555      MOV 55h,A
  07B4  900355    MOV DPTR,#0355h
  07B7  e0        MOVX A,@DPTR
  07B8  d3        SETB C
  07B9  9555      SUBB A,55h
  07BB  406e      JC L082B
  07BD  e553      MOV A,53h
  07BF  ff        MOV R7,A
  07C0  7e00      MOV R6,#00h
  07C2  855883    MOV DPH,58h
  07C5  855982    MOV DPL,59h
  07C8  a3        INC DPTR
  07C9  123b4b    LCALL L3B4B
  07CC  e4        CLR A
  07CD  93        MOVC A,@A+DPTR
  07CE  5551      ANL A,51h
  07D0  ff        MOV R7,A
  07D1  7e00      MOV R6,#00h
  07D3  ef        MOV A,R7
  07D4  4e        ORL A,R6
  07D5  702b      JNZ L0802
  07D7  7e7f      MOV R6,#7Fh
  07D9  7fff      MOV R7,#FFh
  07DB  e555      MOV A,55h
  07DD  123a7b    LCALL L3A7B
  07E0  e542      MOV A,42h
  07E2  900363    MOV DPTR,#0363h
  07E5  123af8    LCALL L3AF8
  07E8  e0        MOVX A,@DPTR
  07E9  fc        MOV R4,A
  07EA  a3        INC DPTR
  07EB  e0        MOVX A,@DPTR
  07EC  fd        MOV R5,A
  07ED  ec        MOV A,R4
  07EE  5206      ANL 06h,A
  07F0  ed        MOV A,R5
  07F1  5207      ANL 07h,A
  07F3  e542      MOV A,42h
  07F5  900363    MOV DPTR,#0363h
  07F8  123af8    LCALL L3AF8
  07FB  ee        MOV A,R6
  07FC  f0        MOVX @DPTR,A
  07FD  a3        INC DPTR
  07FE  ef        MOV A,R7
  07FF  f0        MOVX @DPTR,A
  0800  8029      SJMP L082B
L0802:
  0802  7e80      MOV R6,#80h
  0804  7f00      MOV R7,#00h
  0806  e555      MOV A,55h
  0808  123a7b    LCALL L3A7B
  080B  e542      MOV A,42h
  080D  900363    MOV DPTR,#0363h
  0810  123af8    LCALL L3AF8
  0813  e0        MOVX A,@DPTR
  0814  fc        MOV R4,A
  0815  a3        INC DPTR
  0816  e0        MOVX A,@DPTR
  0817  fd        MOV R5,A
  0818  ec        MOV A,R4
  0819  4206      ORL 06h,A
  081B  ed        MOV A,R5
  081C  4207      ORL 07h,A
  081E  e542      MOV A,42h
  0820  900363    MOV DPTR,#0363h
  0823  123af8    LCALL L3AF8
  0826  ee        MOV A,R6
  0827  f0        MOVX @DPTR,A
  0828  a3        INC DPTR
  0829  ef        MOV A,R7
  082A  f0        MOVX @DPTR,A
L082B:
  082B  7853      MOV R0,#53h
  082D  7401      MOV A,#01h
  082F  26        ADD A,@R0
  0830  f6        MOV @R0,A
  0831  4003      JC L0836
  0833  02079a    LJMP L079A
L0836:
  0836  0542      INC 42h
  0838  ae50      MOV R6,50h
  083A  af51      MOV R7,51h
  083C  7401      MOV A,#01h
  083E  123b23    LCALL L3B23
  0841  8e50      MOV 50h,R6
  0843  8f51      MOV 51h,R7
  0845  7852      MOV R0,#52h
  0847  7401      MOV A,#01h
  0849  26        ADD A,@R0
  084A  f6        MOV @R0,A
  084B  4003      JC L0850
  084D  02078c    LJMP L078C
L0850:
  0850  e542      MOV A,42h
  0852  254f      ADD A,4Fh
  0854  f542      MOV 42h,A
L0856:
  0856  22        RET
L0857:
  0857  ae37      MOV R6,37h
  0859  af38      MOV R7,38h
  085B  900025    MOV DPTR,#0025h
  085E  123b56    LCALL L3B56
  0861  e0        MOVX A,@DPTR
  0862  f544      MOV 44h,A
  0864  8000      SJMP L0866
L0866:
  0866  e544      MOV A,44h
  0868  c3        CLR C
  0869  9430      SUBB A,#30h
  086B  5003      JNC L0870
  086D  75443f    MOV 44h,#3Fh
L0870:
  0870  e544      MOV A,44h
  0872  c3        CLR C
  0873  9430      SUBB A,#30h
  0875  f544      MOV 44h,A
  0877  301304    JNB 22h.3{b13},L087E
  087A  c215      CLR 22h.5{b15}
  087C  8002      SJMP L0880
L087E:
  087E  c214      CLR 22h.4{b14}
L0880:
  0880  e544      MOV A,44h
  0882  d3        SETB C
  0883  940f      SUBB A,#0Fh
  0885  4010      JC L0897
  0887  e544      MOV A,44h
  0889  c3        CLR C
  088A  9410      SUBB A,#10h
  088C  f544      MOV 44h,A
  088E  301304    JNB 22h.3{b13},L0895
  0891  d215      SETB 22h.5{b15}
  0893  8002      SJMP L0897
L0895:
  0895  d214      SETB 22h.4{b14}
L0897:
  0897  22        RET
L0898:
  0898  e545      MOV A,45h
  089A  b4040f    CJNE A,#04h,L08AC
  089D  d211      SETB 22h.1{b11}
  089F  e538      MOV A,38h
  08A1  04        INC A
  08A2  f546      MOV 46h,A
  08A4  7538fa    MOV 38h,#FAh
  08A7  753700    MOV 37h,#00h
  08AA  8019      SJMP L08C5
L08AC:
  08AC  e545      MOV A,45h
  08AE  640d      XRL A,#0Dh
  08B0  600a      JZ L08BC
  08B2  ae37      MOV R6,37h
  08B4  af38      MOV R7,38h
  08B6  74f9      MOV A,#F9h
  08B8  6f        XRL A,R7
  08B9  4e        ORL A,R6
  08BA  7009      JNZ L08C5
L08BC:
  08BC  754600    MOV 46h,#00h
  08BF  7538fa    MOV 38h,#FAh
  08C2  753700    MOV 37h,#00h
L08C5:
  08C5  e545      MOV A,45h
  08C7  6404      XRL A,#04h
  08C9  600a      JZ L08D5
  08CB  ae37      MOV R6,37h
  08CD  af38      MOV R7,38h
  08CF  74f9      MOV A,#F9h
  08D1  6f        XRL A,R7
  08D2  4e        ORL A,R6
  08D3  700d      JNZ L08E2
L08D5:
  08D5  e533      MOV A,33h
  08D7  900219    MOV DPTR,#0219h
  08DA  123b75    LCALL L3B75
  08DD  740d      MOV A,#0Dh
  08DF  f0        MOVX @DPTR,A
  08E0  0533      INC 33h
L08E2:
  08E2  22        RET
L08E3:
  08E3  85425d    MOV 5Dh,42h
L08E6:
  08E6  e55d      MOV A,5Dh
  08E8  d3        SETB C
  08E9  948b      SUBB A,#8Bh
  08EB  5018      JNC L0905
  08ED  e55d      MOV A,5Dh
  08EF  900363    MOV DPTR,#0363h
  08F2  123af8    LCALL L3AF8
  08F5  7400      MOV A,#00h
  08F7  f8        MOV R0,A
  08F8  e4        CLR A
  08F9  f0        MOVX @DPTR,A
  08FA  e8        MOV A,R0
  08FB  a3        INC DPTR
  08FC  f0        MOVX @DPTR,A
  08FD  785d      MOV R0,#5Dh
  08FF  7401      MOV A,#01h
  0901  26        ADD A,@R0
  0902  f6        MOV @R0,A
  0903  50e1      JNC L08E6
L0905:
  0905  85425c    MOV 5Ch,42h
  0908  c213      CLR 22h.3{b13}
  090A  854638    MOV 38h,46h
  090D  753700    MOV 37h,#00h
  0910  e538      MOV A,38h
  0912  04        INC A
  0913  f55b      MOV 5Bh,A
  0915  e4        CLR A
  0916  a214      MOV C,22h.4{b14}
  0918  33        RLC A
  0919  f55d      MOV 5Dh,A
  091B  120857    LCALL L0857
  091E  a216      MOV C,22h.6{b16}
  0920  8211      ANL C,22h.1{b11}
  0922  503c      JNC L0960
  0924  e55d      MOV A,5Dh
  0926  6002      JZ L092A
  0928  d214      SETB 22h.4{b14}
L092A:
  092A  855c5d    MOV 5Dh,5Ch
L092D:
  092D  900354    MOV DPTR,#0354h
  0930  e0        MOVX A,@DPTR
  0931  c3        CLR C
  0932  955d      SUBB A,5Dh
  0934  402a      JC L0960
  0936  e55d      MOV A,5Dh
  0938  90047b    MOV DPTR,#047Bh
  093B  123af8    LCALL L3AF8
  093E  74ff      MOV A,#FFh
  0940  fe        MOV R6,A
  0941  e0        MOVX A,@DPTR
  0942  ff        MOV R7,A
  0943  a3        INC DPTR
  0944  e0        MOVX A,@DPTR
  0945  fc        MOV R4,A
  0946  ee        MOV A,R6
  0947  5204      ANL 04h,A
  0949  7f00      MOV R7,#00h
  094B  e55d      MOV A,5Dh
  094D  900363    MOV DPTR,#0363h
  0950  123af8    LCALL L3AF8
  0953  ef        MOV A,R7
  0954  f0        MOVX @DPTR,A
  0955  a3        INC DPTR
  0956  ec        MOV A,R4
  0957  f0        MOVX @DPTR,A
  0958  785d      MOV R0,#5Dh
  095A  7401      MOV A,#01h
  095C  26        ADD A,@R0
  095D  f6        MOV @R0,A
  095E  50cd      JNC L092D
L0960:
  0960  754a00    MOV 4Ah,#00h
  0963  855b38    MOV 38h,5Bh
  0966  753700    MOV 37h,#00h
L0969:
  0969  ae37      MOV R6,37h
  096B  af38      MOV R7,38h
  096D  74f9      MOV A,#F9h
  096F  be0003    CJNE R6,#00h,L0975
  0972  9f        SUBB A,R7
  0973  5003      JNC L0978
L0975:
  0975  020b31    LJMP L0B31
L0978:
  0978  900025    MOV DPTR,#0025h
  097B  123b56    LCALL L3B56
  097E  e0        MOVX A,@DPTR
  097F  f545      MOV 45h,A
  0981  e545      MOV A,45h
  0983  b40520    CJNE A,#05h,L09A6
  0986  7837      MOV R0,#37h
  0988  123b90    LCALL L3B90
  098B  a214      MOV C,22h.4{b14}
  098D  9217      MOV 22h.7{b17},C
  098F  120857    LCALL L0857
  0992  a217      MOV C,22h.7{b17}
  0994  301401    JNB 22h.4{b14},L0998
  0997  b3        CPL C
L0998:
  0998  4006      JC L09A0
  099A  e542      MOV A,42h
  099C  2402      ADD A,#02h
  099E  f542      MOV 42h,A
L09A0:
  09A0  854247    MOV 47h,42h
  09A3  020af2    LJMP L0AF2
L09A6:
  09A6  a202      MOV C,20h.2{b02}
  09A8  b3        CPL C
  09A9  5005      JNC L09B0
  09AB  e545      MOV A,45h
  09AD  b40402    CJNE A,#04h,L09B2
L09B0:
  09B0  800d      SJMP L09BF
L09B2:
  09B2  e533      MOV A,33h
  09B4  900219    MOV DPTR,#0219h
  09B7  123b75    LCALL L3B75
  09BA  e545      MOV A,45h
  09BC  f0        MOVX @DPTR,A
  09BD  0533      INC 33h
L09BF:
  09BF  e545      MOV A,45h
  09C1  b4036d    CJNE A,#03h,L0A31
  09C4  7837      MOV R0,#37h
  09C6  123b90    LCALL L3B90
  09C9  d213      SETB 22h.3{b13}
  09CB  e4        CLR A
  09CC  a215      MOV C,22h.5{b15}
  09CE  33        RLC A
  09CF  f55d      MOV 5Dh,A
  09D1  120857    LCALL L0857
  09D4  a216      MOV C,22h.6{b16}
  09D6  8211      ANL C,22h.1{b11}
  09D8  5051      JNC L0A2B
  09DA  e55d      MOV A,5Dh
  09DC  6002      JZ L09E0
  09DE  d215      SETB 22h.5{b15}
L09E0:
  09E0  855c5d    MOV 5Dh,5Ch
L09E3:
  09E3  900354    MOV DPTR,#0354h
  09E6  e0        MOVX A,@DPTR
  09E7  c3        CLR C
  09E8  955d      SUBB A,5Dh
  09EA  403f      JC L0A2B
  09EC  e55d      MOV A,5Dh
  09EE  90047b    MOV DPTR,#047Bh
  09F1  123af8    LCALL L3AF8
  09F4  7eff      MOV R6,#FFh
  09F6  7f00      MOV R7,#00h
  09F8  e0        MOVX A,@DPTR
  09F9  fc        MOV R4,A
  09FA  a3        INC DPTR
  09FB  e0        MOVX A,@DPTR
  09FC  fd        MOV R5,A
  09FD  ec        MOV A,R4
  09FE  5206      ANL 06h,A
  0A00  ed        MOV A,R5
  0A01  5207      ANL 07h,A
  0A03  e55d      MOV A,5Dh
  0A05  900363    MOV DPTR,#0363h
  0A08  123af8    LCALL L3AF8
  0A0B  e0        MOVX A,@DPTR
  0A0C  fc        MOV R4,A
  0A0D  a3        INC DPTR
  0A0E  e0        MOVX A,@DPTR
  0A0F  fd        MOV R5,A
  0A10  ec        MOV A,R4
  0A11  4206      ORL 06h,A
  0A13  ed        MOV A,R5
  0A14  4207      ORL 07h,A
  0A16  e55d      MOV A,5Dh
  0A18  900363    MOV DPTR,#0363h
  0A1B  123af8    LCALL L3AF8
  0A1E  ee        MOV A,R6
  0A1F  f0        MOVX @DPTR,A
  0A20  a3        INC DPTR
  0A21  ef        MOV A,R7
  0A22  f0        MOVX @DPTR,A
  0A23  785d      MOV R0,#5Dh
  0A25  7401      MOV A,#01h
  0A27  26        ADD A,@R0
  0A28  f6        MOV @R0,A
  0A29  50b8      JNC L09E3
L0A2B:
  0A2B  854742    MOV 42h,47h
  0A2E  020af2    LJMP L0AF2
L0A31:
  0A31  054a      INC 4Ah
  0A33  120898    LCALL L0898
  0A36  ae37      MOV R6,37h
  0A38  af38      MOV R7,38h
  0A3A  74f9      MOV A,#F9h
  0A3C  be0004    CJNE R6,#00h,L0A43
  0A3F  d3        SETB C
  0A40  9f        SUBB A,R7
  0A41  5003      JNC L0A46
L0A43:
  0A43  020af2    LJMP L0AF2
L0A46:
  0A46  e544      MOV A,44h
  0A48  7f05      MOV R7,#05h
  0A4A  903a02    MOV DPTR,#3A02h
  0A4D  123ae8    LCALL L3AE8
  0A50  e4        CLR A
  0A51  93        MOVC A,@A+DPTR
  0A52  f8        MOV R0,A
  0A53  7401      MOV A,#01h
  0A55  93        MOVC A,@A+DPTR
  0A56  9006ab    MOV DPTR,#06ABh
  0A59  c8        XCH A,R0
  0A5A  f0        MOVX @DPTR,A
  0A5B  a3        INC DPTR
  0A5C  c8        XCH A,R0
  0A5D  f0        MOVX @DPTR,A
  0A5E  ae37      MOV R6,37h
  0A60  af38      MOV R7,38h
  0A62  0f        INC R7
  0A63  bf0001    CJNE R7,#00h,L0A67
  0A66  0e        INC R6
L0A67:
  0A67  900025    MOV DPTR,#0025h
  0A6A  123b56    LCALL L3B56
  0A6D  e0        MOVX A,@DPTR
  0A6E  fe        MOV R6,A
  0A6F  9006ab    MOV DPTR,#06ABh
  0A72  123b3f    LCALL L3B3F
  0A75  a3        INC DPTR
  0A76  a3        INC DPTR
  0A77  ee        MOV A,R6
  0A78  fe        MOV R6,A
  0A79  e4        CLR A
  0A7A  93        MOVC A,@A+DPTR
  0A7B  ff        MOV R7,A
  0A7C  ee        MOV A,R6
  0A7D  c3        CLR C
  0A7E  9f        SUBB A,R7
  0A7F  405d      JC L0ADE
  0A81  ae37      MOV R6,37h
  0A83  af38      MOV R7,38h
  0A85  900025    MOV DPTR,#0025h
  0A88  123b56    LCALL L3B56
  0A8B  e0        MOVX A,@DPTR
  0A8C  fc        MOV R4,A
  0A8D  9006ab    MOV DPTR,#06ABh
  0A90  123b3f    LCALL L3B3F
  0A93  a3        INC DPTR
  0A94  a3        INC DPTR
  0A95  ec        MOV A,R4
  0A96  fc        MOV R4,A
  0A97  e4        CLR A
  0A98  93        MOVC A,@A+DPTR
  0A99  fd        MOV R5,A
  0A9A  ec        MOV A,R4
  0A9B  c3        CLR C
  0A9C  9d        SUBB A,R5
  0A9D  403f      JC L0ADE
  0A9F  0f        INC R7
  0AA0  bf0001    CJNE R7,#00h,L0AA4
  0AA3  0e        INC R6
L0AA4:
  0AA4  900025    MOV DPTR,#0025h
  0AA7  123b56    LCALL L3B56
  0AAA  e0        MOVX A,@DPTR
  0AAB  fe        MOV R6,A
  0AAC  9006ab    MOV DPTR,#06ABh
  0AAF  123b3f    LCALL L3B3F
  0AB2  a3        INC DPTR
  0AB3  a3        INC DPTR
  0AB4  a3        INC DPTR
  0AB5  ee        MOV A,R6
  0AB6  fe        MOV R6,A
  0AB7  e4        CLR A
  0AB8  93        MOVC A,@A+DPTR
  0AB9  ff        MOV R7,A
  0ABA  ee        MOV A,R6
  0ABB  d3        SETB C
  0ABC  9f        SUBB A,R7
  0ABD  501f      JNC L0ADE
  0ABF  ae37      MOV R6,37h
  0AC1  af38      MOV R7,38h
  0AC3  900025    MOV DPTR,#0025h
  0AC6  123b56    LCALL L3B56
  0AC9  e0        MOVX A,@DPTR
  0ACA  fc        MOV R4,A
  0ACB  9006ab    MOV DPTR,#06ABh
  0ACE  123b3f    LCALL L3B3F
  0AD1  a3        INC DPTR
  0AD2  a3        INC DPTR
  0AD3  a3        INC DPTR
  0AD4  ec        MOV A,R4
  0AD5  fc        MOV R4,A
  0AD6  e4        CLR A
  0AD7  93        MOVC A,@A+DPTR
  0AD8  fd        MOV R5,A
  0AD9  ec        MOV A,R4
  0ADA  d3        SETB C
  0ADB  9d        SUBB A,R5
  0ADC  4002      JC L0AE0
L0ADE:
  0ADE  800b      SJMP L0AEB
L0AE0:
  0AE0  7400      MOV A,#00h
  0AE2  f54f      MOV 4Fh,A
  0AE4  1206e6    LCALL L06E6
  0AE7  154a      DEC 4Ah
  0AE9  8007      SJMP L0AF2
L0AEB:
  0AEB  e55a      MOV A,5Ah
  0AED  f54f      MOV 4Fh,A
  0AEF  1206e6    LCALL L06E6
L0AF2:
  0AF2  755d00    MOV 5Dh,#00h
L0AF5:
  0AF5  e55d      MOV A,5Dh
  0AF7  d3        SETB C
  0AF8  948b      SUBB A,#8Bh
  0AFA  5024      JNC L0B20
  0AFC  e55d      MOV A,5Dh
  0AFE  900363    MOV DPTR,#0363h
  0B01  123af8    LCALL L3AF8
  0B04  e55d      MOV A,5Dh
  0B06  fe        MOV R6,A
  0B07  e0        MOVX A,@DPTR
  0B08  ff        MOV R7,A
  0B09  a3        INC DPTR
  0B0A  e0        MOVX A,@DPTR
  0B0B  fc        MOV R4,A
  0B0C  ee        MOV A,R6
  0B0D  90047b    MOV DPTR,#047Bh
  0B10  123af8    LCALL L3AF8
  0B13  ef        MOV A,R7
  0B14  f0        MOVX @DPTR,A
  0B15  a3        INC DPTR
  0B16  ec        MOV A,R4
  0B17  f0        MOVX @DPTR,A
  0B18  785d      MOV R0,#5Dh
  0B1A  7401      MOV A,#01h
  0B1C  26        ADD A,@R0
  0B1D  f6        MOV @R0,A
  0B1E  50d5      JNC L0AF5
L0B20:
  0B20  7838      MOV R0,#38h
  0B22  7401      MOV A,#01h
  0B24  26        ADD A,@R0
  0B25  f6        MOV @R0,A
  0B26  5004      JNC L0B2C
  0B28  18        DEC R0
  0B29  e4        CLR A
  0B2A  36        ADDC A,@R0
  0B2B  f6        MOV @R0,A
L0B2C:
  0B2C  4003      JC L0B31
  0B2E  020969    LJMP L0969
L0B31:
  0B31  22        RET
L0B32:
  0B32  754f00    MOV 4Fh,#00h
L0B35:
  0B35  e53d      MOV A,3Dh
  0B37  7f0e      MOV R7,#0Eh
  0B39  903824    MOV DPTR,#3824h
  0B3C  123ae8    LCALL L3AE8
  0B3F  e4        CLR A
  0B40  93        MOVC A,@A+DPTR
  0B41  c3        CLR C
  0B42  954f      SUBB A,4Fh
  0B44  4024      JC L0B6A
  0B46  e54f      MOV A,4Fh
  0B48  900363    MOV DPTR,#0363h
  0B4B  123af8    LCALL L3AF8
  0B4E  e54f      MOV A,4Fh
  0B50  fe        MOV R6,A
  0B51  e0        MOVX A,@DPTR
  0B52  ff        MOV R7,A
  0B53  a3        INC DPTR
  0B54  e0        MOVX A,@DPTR
  0B55  fc        MOV R4,A
  0B56  ee        MOV A,R6
  0B57  90047b    MOV DPTR,#047Bh
  0B5A  123af8    LCALL L3AF8
  0B5D  ef        MOV A,R7
  0B5E  f0        MOVX @DPTR,A
  0B5F  a3        INC DPTR
  0B60  ec        MOV A,R4
  0B61  f0        MOVX @DPTR,A
  0B62  784f      MOV R0,#4Fh
  0B64  7401      MOV A,#01h
  0B66  26        ADD A,@R0
  0B67  f6        MOV @R0,A
  0B68  50cb      JNC L0B35
L0B6A:
  0B6A  755000    MOV 50h,#00h
  0B6D  e53d      MOV A,3Dh
  0B6F  7f0e      MOV R7,#0Eh
  0B71  903824    MOV DPTR,#3824h
  0B74  123ae8    LCALL L3AE8
  0B77  e4        CLR A
  0B78  93        MOVC A,@A+DPTR
  0B79  14        DEC A
  0B7A  f54f      MOV 4Fh,A
L0B7C:
  0B7C  e54f      MOV A,4Fh
  0B7E  900363    MOV DPTR,#0363h
  0B81  123af8    LCALL L3AF8
  0B84  e0        MOVX A,@DPTR
  0B85  fe        MOV R6,A
  0B86  a3        INC DPTR
  0B87  e0        MOVX A,@DPTR
  0B88  ff        MOV R7,A
  0B89  ef        MOV A,R7
  0B8A  4e        ORL A,R6
  0B8B  7004      JNZ L0B91
  0B8D  e54f      MOV A,4Fh
  0B8F  7002      JNZ L0B93
L0B91:
  0B91  8006      SJMP L0B99
L0B93:
  0B93  154f      DEC 4Fh
  0B95  0550      INC 50h
  0B97  80e3      SJMP L0B7C
L0B99:
  0B99  754f00    MOV 4Fh,#00h
L0B9C:
  0B9C  e550      MOV A,50h
  0B9E  75f002    MOV B,#02h
  0BA1  84        DIV AB
  0BA2  ff        MOV R7,A
  0BA3  7e00      MOV R6,#00h
  0BA5  0f        INC R7
  0BA6  bf0001    CJNE R7,#00h,L0BAA
  0BA9  0e        INC R6
L0BAA:
  0BAA  e54f      MOV A,4Fh
  0BAC  be0004    CJNE R6,#00h,L0BB3
  0BAF  d3        SETB C
  0BB0  9f        SUBB A,R7
  0BB1  5018      JNC L0BCB
L0BB3:
  0BB3  e54f      MOV A,4Fh
  0BB5  900363    MOV DPTR,#0363h
  0BB8  123af8    LCALL L3AF8
  0BBB  7400      MOV A,#00h
  0BBD  f8        MOV R0,A
  0BBE  e4        CLR A
  0BBF  f0        MOVX @DPTR,A
  0BC0  e8        MOV A,R0
  0BC1  a3        INC DPTR
  0BC2  f0        MOVX @DPTR,A
  0BC3  784f      MOV R0,#4Fh
  0BC5  7401      MOV A,#01h
  0BC7  26        ADD A,@R0
  0BC8  f6        MOV @R0,A
  0BC9  50d1      JNC L0B9C
L0BCB:
  0BCB  754f00    MOV 4Fh,#00h
L0BCE:
  0BCE  e53d      MOV A,3Dh
  0BD0  7f0e      MOV R7,#0Eh
  0BD2  903824    MOV DPTR,#3824h
  0BD5  123ae8    LCALL L3AE8
  0BD8  e4        CLR A
  0BD9  93        MOVC A,@A+DPTR
  0BDA  c3        CLR C
  0BDB  954f      SUBB A,4Fh
  0BDD  4030      JC L0C0F
  0BDF  e54f      MOV A,4Fh
  0BE1  90047b    MOV DPTR,#047Bh
  0BE4  123af8    LCALL L3AF8
  0BE7  e550      MOV A,50h
  0BE9  75f002    MOV B,#02h
  0BEC  84        DIV AB
  0BED  ff        MOV R7,A
  0BEE  7e00      MOV R6,#00h
  0BF0  e54f      MOV A,4Fh
  0BF2  2f        ADD A,R7
  0BF3  ff        MOV R7,A
  0BF4  5001      JNC L0BF7
  0BF6  0e        INC R6
L0BF7:
  0BF7  e0        MOVX A,@DPTR
  0BF8  fc        MOV R4,A
  0BF9  a3        INC DPTR
  0BFA  e0        MOVX A,@DPTR
  0BFB  fd        MOV R5,A
  0BFC  900363    MOV DPTR,#0363h
  0BFF  12000e    LCALL L000E
  0C02  ec        MOV A,R4
  0C03  f0        MOVX @DPTR,A
  0C04  a3        INC DPTR
  0C05  ed        MOV A,R5
  0C06  f0        MOVX @DPTR,A
  0C07  784f      MOV R0,#4Fh
  0C09  7401      MOV A,#01h
  0C0B  26        ADD A,@R0
  0C0C  f6        MOV @R0,A
  0C0D  50bf      JNC L0BCE
L0C0F:
  0C0F  22        RET
L0C10:
  0C10  301303    JNB 22h.3{b13},L0C16
  0C13  020d9d    LJMP L0D9D
L0C16:
  0C16  755f00    MOV 5Fh,#00h
  0C19  900354    MOV DPTR,#0354h
  0C1C  e0        MOVX A,@DPTR
  0C1D  14        DEC A
  0C1E  f55e      MOV 5Eh,A
L0C20:
  0C20  e55e      MOV A,5Eh
  0C22  900363    MOV DPTR,#0363h
  0C25  123af8    LCALL L3AF8
  0C28  e0        MOVX A,@DPTR
  0C29  fe        MOV R6,A
  0C2A  a3        INC DPTR
  0C2B  e0        MOVX A,@DPTR
  0C2C  ff        MOV R7,A
  0C2D  ef        MOV A,R7
  0C2E  4e        ORL A,R6
  0C2F  7004      JNZ L0C35
  0C31  e55e      MOV A,5Eh
  0C33  7002      JNZ L0C37
L0C35:
  0C35  8006      SJMP L0C3D
L0C37:
  0C37  155e      DEC 5Eh
  0C39  055f      INC 5Fh
  0C3B  80e3      SJMP L0C20
L0C3D:
  0C3D  e55f      MOV A,5Fh
  0C3F  854af0    MOV B,4Ah
  0C42  84        DIV AB
  0C43  ff        MOV R7,A
  0C44  7e00      MOV R6,#00h
  0C46  8f60      MOV 60h,R7
  0C48  e560      MOV A,60h
  0C4A  7003      JNZ L0C4F
  0C4C  756001    MOV 60h,#01h
L0C4F:
  0C4F  e560      MOV A,60h
  0C51  d3        SETB C
  0C52  9406      SUBB A,#06h
  0C54  4003      JC L0C59
  0C56  756006    MOV 60h,#06h
L0C59:
  0C59  e560      MOV A,60h
  0C5B  f55a      MOV 5Ah,A
  0C5D  1208e3    LCALL L08E3
  0C60  755f00    MOV 5Fh,#00h
  0C63  900354    MOV DPTR,#0354h
  0C66  e0        MOVX A,@DPTR
  0C67  14        DEC A
  0C68  f55e      MOV 5Eh,A
L0C6A:
  0C6A  e55e      MOV A,5Eh
  0C6C  900363    MOV DPTR,#0363h
  0C6F  123af8    LCALL L3AF8
  0C72  e0        MOVX A,@DPTR
  0C73  fe        MOV R6,A
  0C74  a3        INC DPTR
  0C75  e0        MOVX A,@DPTR
  0C76  ff        MOV R7,A
  0C77  ef        MOV A,R7
  0C78  4e        ORL A,R6
  0C79  7004      JNZ L0C7F
  0C7B  e55e      MOV A,5Eh
  0C7D  7002      JNZ L0C81
L0C7F:
  0C7F  8006      SJMP L0C87
L0C81:
  0C81  155e      DEC 5Eh
  0C83  055f      INC 5Fh
  0C85  80e3      SJMP L0C6A
L0C87:
  0C87  755e00    MOV 5Eh,#00h
L0C8A:
  0C8A  e55f      MOV A,5Fh
  0C8C  75f002    MOV B,#02h
  0C8F  84        DIV AB
  0C90  ff        MOV R7,A
  0C91  7e00      MOV R6,#00h
  0C93  0f        INC R7
  0C94  bf0001    CJNE R7,#00h,L0C98
  0C97  0e        INC R6
L0C98:
  0C98  e55e      MOV A,5Eh
  0C9A  be0004    CJNE R6,#00h,L0CA1
  0C9D  d3        SETB C
  0C9E  9f        SUBB A,R7
  0C9F  501a      JNC L0CBB
L0CA1:
  0CA1  e547      MOV A,47h
  0CA3  255e      ADD A,5Eh
  0CA5  900363    MOV DPTR,#0363h
  0CA8  123af8    LCALL L3AF8
  0CAB  7400      MOV A,#00h
  0CAD  f8        MOV R0,A
  0CAE  e4        CLR A
  0CAF  f0        MOVX @DPTR,A
  0CB0  e8        MOV A,R0
  0CB1  a3        INC DPTR
  0CB2  f0        MOVX @DPTR,A
  0CB3  785e      MOV R0,#5Eh
  0CB5  7401      MOV A,#01h
  0CB7  26        ADD A,@R0
  0CB8  f6        MOV @R0,A
  0CB9  50cf      JNC L0C8A
L0CBB:
  0CBB  85475e    MOV 5Eh,47h
L0CBE:
  0CBE  e55f      MOV A,5Fh
  0CC0  75f002    MOV B,#02h
  0CC3  84        DIV AB
  0CC4  ff        MOV R7,A
  0CC5  7e00      MOV R6,#00h
  0CC7  900354    MOV DPTR,#0354h
  0CCA  e0        MOVX A,@DPTR
  0CCB  c3        CLR C
  0CCC  9f        SUBB A,R7
  0CCD  ff        MOV R7,A
  0CCE  e4        CLR A
  0CCF  9e        SUBB A,R6
  0CD0  fe        MOV R6,A
  0CD1  e55e      MOV A,5Eh
  0CD3  be0004    CJNE R6,#00h,L0CDA
  0CD6  d3        SETB C
  0CD7  9f        SUBB A,R7
  0CD8  5030      JNC L0D0A
L0CDA:
  0CDA  e55e      MOV A,5Eh
  0CDC  90047b    MOV DPTR,#047Bh
  0CDF  123af8    LCALL L3AF8
  0CE2  e55f      MOV A,5Fh
  0CE4  75f002    MOV B,#02h
  0CE7  84        DIV AB
  0CE8  ff        MOV R7,A
  0CE9  7e00      MOV R6,#00h
  0CEB  e55e      MOV A,5Eh
  0CED  2f        ADD A,R7
  0CEE  ff        MOV R7,A
  0CEF  5001      JNC L0CF2
  0CF1  0e        INC R6
L0CF2:
  0CF2  e0        MOVX A,@DPTR
  0CF3  fc        MOV R4,A
  0CF4  a3        INC DPTR
  0CF5  e0        MOVX A,@DPTR
  0CF6  fd        MOV R5,A
  0CF7  900363    MOV DPTR,#0363h
  0CFA  12000e    LCALL L000E
  0CFD  ec        MOV A,R4
  0CFE  f0        MOVX @DPTR,A
  0CFF  a3        INC DPTR
  0D00  ed        MOV A,R5
  0D01  f0        MOVX @DPTR,A
  0D02  785e      MOV R0,#5Eh
  0D04  7401      MOV A,#01h
  0D06  26        ADD A,@R0
  0D07  f6        MOV @R0,A
  0D08  50b4      JNC L0CBE
L0D0A:
  0D0A  020d9a    LJMP L0D9A
  0D0D  db 90 03 54 E0 A8 35 B8 00 31 95 36 40 2D AE 35 AF  ; ..T..5..1.6@-.5.
  0D1D  db 36 90 03 63 12 00 0E 7C E0 7D 00 E0 FA A3 E0 FB  ; 6..c...|.}......
  0D2D  db EA 52 04 EB 52 05 ED 4C 60 02 C2 18 78 36 74 01  ; .R..R..L`...x6t.
  0D3D  db 26 F6 50 04 18 E4 36 F6 50 C6 A2 18 B3 40 4E 85  ; &.P...6.P....@N.
  0D4D  db 47 36 75 35 00 90 03 54 E0 A8 35 B8 00 3F 95 36  ; G6u5...T..5..?.6
  0D5D  db 40 3B AE 35 AF 36 90 03 63 12 00 0E 74 01 FC E0  ; @;.5.6..c...t...
  0D6D  db FD A3 E0 FA EC 8D 06 8A 07 12 3B 15 8F 04 8E 05  ; ..........;.....
  0D7D  db AE 35 AF 36 90 03 63 12 00 0E ED F0 A3 EC F0 78  ; .5.6..c........x
  0D8D  db 36 74 01 26 F6 50 04 18 E4 36 F6 50 B8  ; 6t.&.P...6.P.
L0D9A:
  0D9A  021053    LJMP L1053
L0D9D:
  0D9D  755a01    MOV 5Ah,#01h
  0DA0  1208e3    LCALL L08E3
  0DA3  201403    JB 22h.4{b14},L0DA9
  0DA6  020e8d    LJMP L0E8D
L0DA9:
  0DA9  755f00    MOV 5Fh,#00h
  0DAC  900354    MOV DPTR,#0354h
  0DAF  e0        MOVX A,@DPTR
  0DB0  14        DEC A
  0DB1  f55e      MOV 5Eh,A
L0DB3:
  0DB3  e55e      MOV A,5Eh
  0DB5  900363    MOV DPTR,#0363h
  0DB8  123af8    LCALL L3AF8
  0DBB  74ff      MOV A,#FFh
  0DBD  fe        MOV R6,A
  0DBE  e0        MOVX A,@DPTR
  0DBF  ff        MOV R7,A
  0DC0  a3        INC DPTR
  0DC1  e0        MOVX A,@DPTR
  0DC2  fc        MOV R4,A
  0DC3  ee        MOV A,R6
  0DC4  5204      ANL 04h,A
  0DC6  7f00      MOV R7,#00h
  0DC8  ec        MOV A,R4
  0DC9  4f        ORL A,R7
  0DCA  7004      JNZ L0DD0
  0DCC  e55e      MOV A,5Eh
  0DCE  7002      JNZ L0DD2
L0DD0:
  0DD0  8006      SJMP L0DD8
L0DD2:
  0DD2  155e      DEC 5Eh
  0DD4  055f      INC 5Fh
  0DD6  80db      SJMP L0DB3
L0DD8:
  0DD8  85475e    MOV 5Eh,47h
L0DDB:
  0DDB  900354    MOV DPTR,#0354h
  0DDE  e0        MOVX A,@DPTR
  0DDF  14        DEC A
  0DE0  c3        CLR C
  0DE1  955e      SUBB A,5Eh
  0DE3  402c      JC L0E11
  0DE5  e55e      MOV A,5Eh
  0DE7  900363    MOV DPTR,#0363h
  0DEA  123af8    LCALL L3AF8
  0DED  7eff      MOV R6,#FFh
  0DEF  7f00      MOV R7,#00h
  0DF1  e0        MOVX A,@DPTR
  0DF2  fc        MOV R4,A
  0DF3  a3        INC DPTR
  0DF4  e0        MOVX A,@DPTR
  0DF5  fd        MOV R5,A
  0DF6  ec        MOV A,R4
  0DF7  5206      ANL 06h,A
  0DF9  ed        MOV A,R5
  0DFA  5207      ANL 07h,A
  0DFC  e55e      MOV A,5Eh
  0DFE  900363    MOV DPTR,#0363h
  0E01  123af8    LCALL L3AF8
  0E04  ee        MOV A,R6
  0E05  f0        MOVX @DPTR,A
  0E06  a3        INC DPTR
  0E07  ef        MOV A,R7
  0E08  f0        MOVX @DPTR,A
  0E09  785e      MOV R0,#5Eh
  0E0B  7401      MOV A,#01h
  0E0D  26        ADD A,@R0
  0E0E  f6        MOV @R0,A
  0E0F  50ca      JNC L0DDB
L0E11:
  0E11  85475e    MOV 5Eh,47h
L0E14:
  0E14  e55f      MOV A,5Fh
  0E16  75f002    MOV B,#02h
  0E19  84        DIV AB
  0E1A  ff        MOV R7,A
  0E1B  7e00      MOV R6,#00h
  0E1D  900354    MOV DPTR,#0354h
  0E20  e0        MOVX A,@DPTR
  0E21  c3        CLR C
  0E22  9f        SUBB A,R7
  0E23  ff        MOV R7,A
  0E24  e4        CLR A
  0E25  9e        SUBB A,R6
  0E26  fe        MOV R6,A
  0E27  e55e      MOV A,5Eh
  0E29  be0004    CJNE R6,#00h,L0E30
  0E2C  d3        SETB C
  0E2D  9f        SUBB A,R7
  0E2E  505d      JNC L0E8D
L0E30:
  0E30  e55f      MOV A,5Fh
  0E32  75f002    MOV B,#02h
  0E35  84        DIV AB
  0E36  ff        MOV R7,A
  0E37  7e00      MOV R6,#00h
  0E39  e55e      MOV A,5Eh
  0E3B  2f        ADD A,R7
  0E3C  ff        MOV R7,A
  0E3D  5001      JNC L0E40
  0E3F  0e        INC R6
L0E40:
  0E40  900363    MOV DPTR,#0363h
  0E43  12000e    LCALL L000E
  0E46  e55e      MOV A,5Eh
  0E48  fe        MOV R6,A
  0E49  e0        MOVX A,@DPTR
  0E4A  ff        MOV R7,A
  0E4B  a3        INC DPTR
  0E4C  e0        MOVX A,@DPTR
  0E4D  fc        MOV R4,A
  0E4E  ee        MOV A,R6
  0E4F  90047b    MOV DPTR,#047Bh
  0E52  123af8    LCALL L3AF8
  0E55  74ff      MOV A,#FFh
  0E57  fe        MOV R6,A
  0E58  e0        MOVX A,@DPTR
  0E59  fd        MOV R5,A
  0E5A  a3        INC DPTR
  0E5B  e0        MOVX A,@DPTR
  0E5C  fa        MOV R2,A
  0E5D  ee        MOV A,R6
  0E5E  5202      ANL 02h,A
  0E60  7d00      MOV R5,#00h
  0E62  ef        MOV A,R7
  0E63  4205      ORL 05h,A
  0E65  ec        MOV A,R4
  0E66  4202      ORL 02h,A
  0E68  e55f      MOV A,5Fh
  0E6A  75f002    MOV B,#02h
  0E6D  84        DIV AB
  0E6E  fc        MOV R4,A
  0E6F  7e00      MOV R6,#00h
  0E71  e55e      MOV A,5Eh
  0E73  2c        ADD A,R4
  0E74  fc        MOV R4,A
  0E75  5001      JNC L0E78
  0E77  0e        INC R6
L0E78:
  0E78  8c07      MOV 07h,R4
  0E7A  900363    MOV DPTR,#0363h
  0E7D  12000e    LCALL L000E
  0E80  ed        MOV A,R5
  0E81  f0        MOVX @DPTR,A
  0E82  a3        INC DPTR
  0E83  ea        MOV A,R2
  0E84  f0        MOVX @DPTR,A
  0E85  785e      MOV R0,#5Eh
  0E87  7401      MOV A,#01h
  0E89  26        ADD A,@R0
  0E8A  f6        MOV @R0,A
  0E8B  5087      JNC L0E14
L0E8D:
  0E8D  201503    JB 22h.5{b15},L0E93
  0E90  021053    LJMP L1053
L0E93:
  0E93  d218      SETB 23h.0{b18}
  0E95  854736    MOV 36h,47h
  0E98  753500    MOV 35h,#00h
L0E9B:
  0E9B  900354    MOV DPTR,#0354h
  0E9E  e0        MOVX A,@DPTR
  0E9F  a835      MOV R0,35h
  0EA1  b80031    CJNE R0,#00h,L0ED5
  0EA4  9536      SUBB A,36h
  0EA6  402d      JC L0ED5
  0EA8  ae35      MOV R6,35h
  0EAA  af36      MOV R7,36h
  0EAC  900363    MOV DPTR,#0363h
  0EAF  12000e    LCALL L000E
  0EB2  7c80      MOV R4,#80h
  0EB4  7d00      MOV R5,#00h
  0EB6  e0        MOVX A,@DPTR
  0EB7  fa        MOV R2,A
  0EB8  a3        INC DPTR
  0EB9  e0        MOVX A,@DPTR
  0EBA  fb        MOV R3,A
  0EBB  ea        MOV A,R2
  0EBC  5204      ANL 04h,A
  0EBE  eb        MOV A,R3
  0EBF  5205      ANL 05h,A
  0EC1  ed        MOV A,R5
  0EC2  4c        ORL A,R4
  0EC3  6002      JZ L0EC7
  0EC5  c218      CLR 23h.0{b18}
L0EC7:
  0EC7  7836      MOV R0,#36h
  0EC9  7401      MOV A,#01h
  0ECB  26        ADD A,@R0
  0ECC  f6        MOV @R0,A
  0ECD  5004      JNC L0ED3
  0ECF  18        DEC R0
  0ED0  e4        CLR A
  0ED1  36        ADDC A,@R0
  0ED2  f6        MOV @R0,A
L0ED3:
  0ED3  50c6      JNC L0E9B
L0ED5:
  0ED5  755f00    MOV 5Fh,#00h
  0ED8  900354    MOV DPTR,#0354h
  0EDB  e0        MOVX A,@DPTR
  0EDC  14        DEC A
  0EDD  f55e      MOV 5Eh,A
L0EDF:
  0EDF  e55e      MOV A,5Eh
  0EE1  900363    MOV DPTR,#0363h
  0EE4  123af8    LCALL L3AF8
  0EE7  7eff      MOV R6,#FFh
  0EE9  7f00      MOV R7,#00h
  0EEB  e0        MOVX A,@DPTR
  0EEC  fc        MOV R4,A
  0EED  a3        INC DPTR
  0EEE  e0        MOVX A,@DPTR
  0EEF  fd        MOV R5,A
  0EF0  ec        MOV A,R4
  0EF1  5206      ANL 06h,A
  0EF3  ed        MOV A,R5
  0EF4  5207      ANL 07h,A
  0EF6  ef        MOV A,R7
  0EF7  4e        ORL A,R6
  0EF8  7004      JNZ L0EFE
  0EFA  e55e      MOV A,5Eh
  0EFC  7002      JNZ L0F00
L0EFE:
  0EFE  8006      SJMP L0F06
L0F00:
  0F00  155e      DEC 5Eh
  0F02  055f      INC 5Fh
  0F04  80d9      SJMP L0EDF
L0F06:
  0F06  85475e    MOV 5Eh,47h
L0F09:
  0F09  900354    MOV DPTR,#0354h
  0F0C  e0        MOVX A,@DPTR
  0F0D  14        DEC A
  0F0E  c3        CLR C
  0F0F  955e      SUBB A,5Eh
  0F11  402a      JC L0F3D
  0F13  e55e      MOV A,5Eh
  0F15  900363    MOV DPTR,#0363h
  0F18  123af8    LCALL L3AF8
  0F1B  74ff      MOV A,#FFh
  0F1D  fe        MOV R6,A
  0F1E  e0        MOVX A,@DPTR
  0F1F  ff        MOV R7,A
  0F20  a3        INC DPTR
  0F21  e0        MOVX A,@DPTR
  0F22  fc        MOV R4,A
  0F23  ee        MOV A,R6
  0F24  5204      ANL 04h,A
  0F26  7f00      MOV R7,#00h
  0F28  e55e      MOV A,5Eh
  0F2A  900363    MOV DPTR,#0363h
  0F2D  123af8    LCALL L3AF8
  0F30  ef        MOV A,R7
  0F31  f0        MOVX @DPTR,A
  0F32  a3        INC DPTR
  0F33  ec        MOV A,R4
  0F34  f0        MOVX @DPTR,A
  0F35  785e      MOV R0,#5Eh
  0F37  7401      MOV A,#01h
  0F39  26        ADD A,@R0
  0F3A  f6        MOV @R0,A
  0F3B  50cc      JNC L0F09
L0F3D:
  0F3D  a218      MOV C,23h.0{b18}
  0F3F  b3        CPL C
  0F40  d3        SETB C
  0F41  4003      JC L0F46
  0F43  020fcb    LJMP L0FCB
L0F46:
  0F46  85475e    MOV 5Eh,47h
L0F49:
  0F49  e55f      MOV A,5Fh
  0F4B  75f002    MOV B,#02h
  0F4E  84        DIV AB
  0F4F  ff        MOV R7,A
  0F50  7e00      MOV R6,#00h
  0F52  900354    MOV DPTR,#0354h
  0F55  e0        MOVX A,@DPTR
  0F56  c3        CLR C
  0F57  9f        SUBB A,R7
  0F58  ff        MOV R7,A
  0F59  e4        CLR A
  0F5A  9e        SUBB A,R6
  0F5B  fe        MOV R6,A
  0F5C  e55e      MOV A,5Eh
  0F5E  be0004    CJNE R6,#00h,L0F65
  0F61  d3        SETB C
  0F62  9f        SUBB A,R7
  0F63  5063      JNC L0FC8
L0F65:
  0F65  e55e      MOV A,5Eh
  0F67  90047b    MOV DPTR,#047Bh
  0F6A  123af8    LCALL L3AF8
  0F6D  7eff      MOV R6,#FFh
  0F6F  7f00      MOV R7,#00h
  0F71  e0        MOVX A,@DPTR
  0F72  fc        MOV R4,A
  0F73  a3        INC DPTR
  0F74  e0        MOVX A,@DPTR
  0F75  fd        MOV R5,A
  0F76  ec        MOV A,R4
  0F77  5206      ANL 06h,A
  0F79  ed        MOV A,R5
  0F7A  5207      ANL 07h,A
  0F7C  e55f      MOV A,5Fh
  0F7E  75f002    MOV B,#02h
  0F81  84        DIV AB
  0F82  fd        MOV R5,A
  0F83  7c00      MOV R4,#00h
  0F85  e55e      MOV A,5Eh
  0F87  2d        ADD A,R5
  0F88  fd        MOV R5,A
  0F89  5001      JNC L0F8C
  0F8B  0c        INC R4
L0F8C:
  0F8C  8f02      MOV 02h,R7
  0F8E  8e03      MOV 03h,R6
  0F90  8c06      MOV 06h,R4
  0F92  8d07      MOV 07h,R5
  0F94  900363    MOV DPTR,#0363h
  0F97  12000e    LCALL L000E
  0F9A  e0        MOVX A,@DPTR
  0F9B  fe        MOV R6,A
  0F9C  a3        INC DPTR
  0F9D  e0        MOVX A,@DPTR
  0F9E  ff        MOV R7,A
  0F9F  ee        MOV A,R6
  0FA0  4203      ORL 03h,A
  0FA2  ef        MOV A,R7
  0FA3  4202      ORL 02h,A
  0FA5  e55f      MOV A,5Fh
  0FA7  75f002    MOV B,#02h
  0FAA  84        DIV AB
  0FAB  ff        MOV R7,A
  0FAC  7e00      MOV R6,#00h
  0FAE  e55e      MOV A,5Eh
  0FB0  2f        ADD A,R7
  0FB1  ff        MOV R7,A
  0FB2  5001      JNC L0FB5
  0FB4  0e        INC R6
L0FB5:
  0FB5  900363    MOV DPTR,#0363h
  0FB8  12000e    LCALL L000E
  0FBB  eb        MOV A,R3
  0FBC  f0        MOVX @DPTR,A
  0FBD  a3        INC DPTR
  0FBE  ea        MOV A,R2
  0FBF  f0        MOVX @DPTR,A
  0FC0  785e      MOV R0,#5Eh
  0FC2  7401      MOV A,#01h
  0FC4  26        ADD A,@R0
  0FC5  f6        MOV @R0,A
  0FC6  5081      JNC L0F49
L0FC8:
  0FC8  021053    LJMP L1053
L0FCB:
  0FCB  85475e    MOV 5Eh,47h
L0FCE:
  0FCE  e55f      MOV A,5Fh
  0FD0  75f002    MOV B,#02h
  0FD3  84        DIV AB
  0FD4  ff        MOV R7,A
  0FD5  7e00      MOV R6,#00h
  0FD7  900354    MOV DPTR,#0354h
  0FDA  e0        MOVX A,@DPTR
  0FDB  c3        CLR C
  0FDC  9f        SUBB A,R7
  0FDD  ff        MOV R7,A
  0FDE  e4        CLR A
  0FDF  9e        SUBB A,R6
  0FE0  fe        MOV R6,A
  0FE1  e55e      MOV A,5Eh
  0FE3  be0004    CJNE R6,#00h,L0FEA
  0FE6  d3        SETB C
  0FE7  9f        SUBB A,R7
  0FE8  5069      JNC L1053
L0FEA:
  0FEA  e55e      MOV A,5Eh
  0FEC  90047b    MOV DPTR,#047Bh
  0FEF  123af8    LCALL L3AF8
  0FF2  7401      MOV A,#01h
  0FF4  fe        MOV R6,A
  0FF5  e0        MOVX A,@DPTR
  0FF6  ff        MOV R7,A
  0FF7  a3        INC DPTR
  0FF8  e0        MOVX A,@DPTR
  0FF9  fc        MOV R4,A
  0FFA  ee        MOV A,R6
  0FFB  8f06      MOV 06h,R7
  0FFD  8c07      MOV 07h,R4
  0FFF  123b15    LCALL L3B15
  1002  7cfe      MOV R4,#FEh
  1004  7d00      MOV R5,#00h
  1006  ee        MOV A,R6
  1007  5204      ANL 04h,A
  1009  ef        MOV A,R7
  100A  5205      ANL 05h,A
  100C  e55f      MOV A,5Fh
  100E  75f002    MOV B,#02h
  1011  84        DIV AB
  1012  ff        MOV R7,A
  1013  7e00      MOV R6,#00h
  1015  e55e      MOV A,5Eh
  1017  2f        ADD A,R7
  1018  ff        MOV R7,A
  1019  5001      JNC L101C
  101B  0e        INC R6
L101C:
  101C  900363    MOV DPTR,#0363h
  101F  12000e    LCALL L000E
  1022  e0        MOVX A,@DPTR
  1023  fe        MOV R6,A
  1024  a3        INC DPTR
  1025  e0        MOVX A,@DPTR
  1026  ff        MOV R7,A
  1027  ee        MOV A,R6
  1028  4204      ORL 04h,A
  102A  ef        MOV A,R7
  102B  4205      ORL 05h,A
  102D  e55f      MOV A,5Fh
  102F  75f002    MOV B,#02h
  1032  84        DIV AB
  1033  ff        MOV R7,A
  1034  7e00      MOV R6,#00h
  1036  e55e      MOV A,5Eh
  1038  2f        ADD A,R7
  1039  ff        MOV R7,A
  103A  5001      JNC L103D
  103C  0e        INC R6
L103D:
  103D  900363    MOV DPTR,#0363h
  1040  12000e    LCALL L000E
  1043  ec        MOV A,R4
  1044  f0        MOVX @DPTR,A
  1045  a3        INC DPTR
  1046  ed        MOV A,R5
  1047  f0        MOVX @DPTR,A
  1048  785e      MOV R0,#5Eh
  104A  7401      MOV A,#01h
  104C  26        ADD A,@R0
  104D  f6        MOV @R0,A
  104E  4003      JC L1053
  1050  020fce    LJMP L0FCE
L1053:
  1053  22        RET
L1054:
  1054  8000      SJMP L1056
L1056:
  1056  903a50    MOV DPTR,#3A50h
  1059  784b      MOV R0,#4Bh
  105B  123b7e    LCALL L3B7E
  105E  c20c      CLR 21h.4{b0C}
  1060  753600    MOV 36h,#00h
  1063  753500    MOV 35h,#00h
L1066:
  1066  ae35      MOV R6,35h
  1068  af36      MOV R7,36h
  106A  ac4f      MOV R4,4Fh
  106C  ad50      MOV R5,50h
  106E  ed        MOV A,R5
  106F  c3        CLR C
  1070  9f        SUBB A,R7
  1071  ec        MOV A,R4
  1072  9e        SUBB A,R6
  1073  5003      JNC L1078
  1075  021128    LJMP L1128
L1078:
  1078  854b61    MOV 61h,4Bh
  107B  854c62    MOV 62h,4Ch
  107E  740d      MOV A,#0Dh
  1080  f563      MOV 63h,A
  1082  7eff      MOV R6,#FFh
  1084  7fff      MOV R7,#FFh
  1086  ac4b      MOV R4,4Bh
  1088  ad4c      MOV R5,4Ch
  108A  120003    LCALL L0003
  108D  8e64      MOV 64h,R6
  108F  8f65      MOV 65h,R7
  1091  123a87    LCALL L3A87
  1094  8e39      MOV 39h,R6
  1096  8f3a      MOV 3Ah,R7
  1098  ef        MOV A,R7
  1099  b4ff21    CJNE A,#FFh,L10BD
  109C  ee        MOV A,R6
  109D  b4ff1d    CJNE A,#FFh,L10BD
  10A0  d20c      SETB 21h.4{b0C}
  10A2  903a50    MOV DPTR,#3A50h
  10A5  784b      MOV R0,#4Bh
  10A7  123b7e    LCALL L3B7E
  10AA  753a01    MOV 3Ah,#01h
  10AD  753900    MOV 39h,#00h
  10B0  ae4f      MOV R6,4Fh
  10B2  af50      MOV R7,50h
  10B4  0f        INC R7
  10B5  bf0001    CJNE R7,#00h,L10B9
  10B8  0e        INC R6
L10B9:
  10B9  8e35      MOV 35h,R6
  10BB  8f36      MOV 36h,R7
L10BD:
  10BD  ae4b      MOV R6,4Bh
  10BF  af4c      MOV R7,4Ch
  10C1  ac39      MOV R4,39h
  10C3  ad3a      MOV R5,3Ah
  10C5  ef        MOV A,R7
  10C6  2d        ADD A,R5
  10C7  fd        MOV R5,A
  10C8  ee        MOV A,R6
  10C9  3c        ADDC A,R4
  10CA  fc        MOV R4,A
  10CB  7402      MOV A,#02h
  10CD  2d        ADD A,R5
  10CE  fd        MOV R5,A
  10CF  5001      JNC L10D2
  10D1  0c        INC R4
L10D2:
  10D2  8c4b      MOV 4Bh,R4
  10D4  8d4c      MOV 4Ch,R5
  10D6  753a00    MOV 3Ah,#00h
  10D9  753900    MOV 39h,#00h
L10DC:
  10DC  ae39      MOV R6,39h
  10DE  af3a      MOV R7,3Ah
  10E0  854b83    MOV DPH,4Bh
  10E3  854c82    MOV DPL,4Ch
  10E6  123b56    LCALL L3B56
  10E9  e0        MOVX A,@DPTR
  10EA  b44107    CJNE A,#41h,L10F4
  10ED  7839      MOV R0,#39h
  10EF  123b90    LCALL L3B90
  10F2  80e8      SJMP L10DC
L10F4:
  10F4  ae39      MOV R6,39h
  10F6  af3a      MOV R7,3Ah
  10F8  7403      MOV A,#03h
  10FA  be0003    CJNE R6,#00h,L1100
  10FD  9f        SUBB A,R7
  10FE  5017      JNC L1117
L1100:
  1100  d20c      SETB 21h.4{b0C}
  1102  903a50    MOV DPTR,#3A50h
  1105  784b      MOV R0,#4Bh
  1107  123b7e    LCALL L3B7E
  110A  ac4f      MOV R4,4Fh
  110C  ad50      MOV R5,50h
  110E  0d        INC R5
  110F  bd0001    CJNE R5,#00h,L1113
  1112  0c        INC R4
L1113:
  1113  8c35      MOV 35h,R4
  1115  8d36      MOV 36h,R5
L1117:
  1117  7836      MOV R0,#36h
  1119  7401      MOV A,#01h
  111B  26        ADD A,@R0
  111C  f6        MOV @R0,A
  111D  5004      JNC L1123
  111F  18        DEC R0
  1120  e4        CLR A
  1121  36        ADDC A,@R0
  1122  f6        MOV @R0,A
L1123:
  1123  4003      JC L1128
  1125  021066    LJMP L1066
L1128:
  1128  22        RET
L1129:
  1129  758921    MOV TMOD,#21h
  112C  758850    MOV TCON,#50h
  112F  7598d8    MOV SCON,#D8h
  1132  758b00    MOV TL1,#00h
  1135  758de6    MOV TH1,#E6h
  1138  758a0c    MOV TL0,#0Ch
  113B  758cfe    MOV TH0,#FEh
  113E  75b800    MOV IP,#00h
  1141  758780    MOV PCON,#80h
  1144  753600    MOV 36h,#00h
  1147  753500    MOV 35h,#00h
L114A:
  114A  ae35      MOV R6,35h
  114C  af36      MOV R7,36h
  114E  7406      MOV A,#06h
  1150  be0018    CJNE R6,#00h,L116B
  1153  9f        SUBB A,R7
  1154  4015      JC L116B
  1156  e536      MOV A,36h
  1158  2424      ADD A,#24h
  115A  f8        MOV R0,A
  115B  7620      MOV @R0,#20h
  115D  7836      MOV R0,#36h
  115F  7401      MOV A,#01h
  1161  26        ADD A,@R0
  1162  f6        MOV @R0,A
  1163  5004      JNC L1169
  1165  18        DEC R0
  1166  e4        CLR A
  1167  36        ADDC A,@R0
  1168  f6        MOV @R0,A
L1169:
  1169  50df      JNC L114A
L116B:
  116B  90000b    MOV DPTR,#000Bh
  116E  e4        CLR A
  116F  f0        MOVX @DPTR,A
  1170  a3        INC DPTR
  1171  f0        MOVX @DPTR,A
  1172  900011    MOV DPTR,#0011h
  1175  e4        CLR A
  1176  f0        MOVX @DPTR,A
  1177  a3        INC DPTR
  1178  f0        MOVX @DPTR,A
  1179  900015    MOV DPTR,#0015h
  117C  e4        CLR A
  117D  f0        MOVX @DPTR,A
  117E  a3        INC DPTR
  117F  f0        MOVX @DPTR,A
  1180  90001b    MOV DPTR,#001Bh
  1183  e4        CLR A
  1184  f0        MOVX @DPTR,A
  1185  a3        INC DPTR
  1186  f0        MOVX @DPTR,A
  1187  900021    MOV DPTR,#0021h
  118A  e4        CLR A
  118B  f0        MOVX @DPTR,A
  118C  a3        INC DPTR
  118D  f0        MOVX @DPTR,A
  118E  75290d    MOV 29h,#0Dh
  1191  900001    MOV DPTR,#0001h
  1194  e4        CLR A
  1195  f0        MOVX @DPTR,A
  1196  900000    MOV DPTR,#0000h
  1199  e4        CLR A
  119A  f0        MOVX @DPTR,A
  119B  c20f      CLR 21h.7{b0F}
  119D  d2b4      SETB T0
  119F  c20d      CLR 21h.5{b0D}
  11A1  754300    MOV 43h,#00h
  11A4  900360    MOV DPTR,#0360h
  11A7  e4        CLR A
  11A8  f0        MOVX @DPTR,A
  11A9  c212      CLR 22h.2{b12}
  11AB  753800    MOV 38h,#00h
  11AE  753700    MOV 37h,#00h
  11B1  c213      CLR 22h.3{b13}
  11B3  c215      CLR 22h.5{b15}
  11B5  c214      CLR 22h.4{b14}
  11B7  c216      CLR 22h.6{b16}
  11B9  754402    MOV 44h,#02h
  11BC  c211      CLR 22h.1{b11}
  11BE  754100    MOV 41h,#00h
  11C1  754000    MOV 40h,#00h
  11C4  752e00    MOV 2Eh,#00h
  11C7  753400    MOV 34h,#00h
  11CA  c204      CLR 20h.4{b04}
  11CC  c205      CLR 20h.5{b05}
  11CE  753300    MOV 33h,#00h
  11D1  d202      SETB 20h.2{b02}
  11D3  753200    MOV 32h,#00h
  11D6  753100    MOV 31h,#00h
  11D9  c201      CLR 20h.1{b01}
  11DB  d206      SETB 20h.6{b06}
  11DD  c208      CLR 21h.0{b08}
  11DF  752fff    MOV 2Fh,#FFh
  11E2  c20a      CLR 21h.2{b0A}
  11E4  c20b      CLR 21h.3{b0B}
  11E6  c20c      CLR 21h.4{b0C}
  11E8  754700    MOV 47h,#00h
  11EB  754200    MOV 42h,#00h
  11EE  90035f    MOV DPTR,#035Fh
  11F1  e4        CLR A
  11F2  f0        MOVX @DPTR,A
  11F3  754800    MOV 48h,#00h
  11F6  c200      CLR 20h.0{b00}
  11F8  900356    MOV DPTR,#0356h
  11FB  7416      MOV A,#16h
  11FD  f0        MOVX @DPTR,A
  11FE  a3        INC DPTR
  11FF  7400      MOV A,#00h
  1201  f0        MOVX @DPTR,A
  1202  752b2f    MOV 2Bh,#2Fh
  1205  752cff    MOV 2Ch,#FFh
  1208  900358    MOV DPTR,#0358h
  120B  74ff      MOV A,#FFh
  120D  f0        MOVX @DPTR,A
  120E  a3        INC DPTR
  120F  74ff      MOV A,#FFh
  1211  f0        MOVX @DPTR,A
  1212  c209      CLR 21h.1{b09}
  1214  753600    MOV 36h,#00h
  1217  753500    MOV 35h,#00h
L121A:
  121A  ae35      MOV R6,35h
  121C  af36      MOV R7,36h
  121E  74f9      MOV A,#F9h
  1220  be001a    CJNE R6,#00h,L123D
  1223  9f        SUBB A,R7
  1224  4017      JC L123D
  1226  90011f    MOV DPTR,#011Fh
  1229  123b56    LCALL L3B56
  122C  740d      MOV A,#0Dh
  122E  f0        MOVX @DPTR,A
  122F  7836      MOV R0,#36h
  1231  7401      MOV A,#01h
  1233  26        ADD A,@R0
  1234  f6        MOV @R0,A
  1235  5004      JNC L123B
  1237  18        DEC R0
  1238  e4        CLR A
  1239  36        ADDC A,@R0
  123A  f6        MOV @R0,A
L123B:
  123B  50dd      JNC L121A
L123D:
  123D  753600    MOV 36h,#00h
  1240  753500    MOV 35h,#00h
L1243:
  1243  ae35      MOV R6,35h
  1245  af36      MOV R7,36h
  1247  748b      MOV A,#8Bh
  1249  be003b    CJNE R6,#00h,L1287
  124C  9f        SUBB A,R7
  124D  4038      JC L1287
  124F  900363    MOV DPTR,#0363h
  1252  12000e    LCALL L000E
  1255  7400      MOV A,#00h
  1257  f8        MOV R0,A
  1258  e4        CLR A
  1259  f0        MOVX @DPTR,A
  125A  e8        MOV A,R0
  125B  a3        INC DPTR
  125C  f0        MOVX @DPTR,A
  125D  90047b    MOV DPTR,#047Bh
  1260  12000e    LCALL L000E
  1263  7400      MOV A,#00h
  1265  f8        MOV R0,A
  1266  e4        CLR A
  1267  f0        MOVX @DPTR,A
  1268  e8        MOV A,R0
  1269  a3        INC DPTR
  126A  f0        MOVX @DPTR,A
  126B  900593    MOV DPTR,#0593h
  126E  12000e    LCALL L000E
  1271  7400      MOV A,#00h
  1273  f8        MOV R0,A
  1274  e4        CLR A
  1275  f0        MOVX @DPTR,A
  1276  e8        MOV A,R0
  1277  a3        INC DPTR
  1278  f0        MOVX @DPTR,A
  1279  7836      MOV R0,#36h
  127B  7401      MOV A,#01h
  127D  26        ADD A,@R0
  127E  f6        MOV @R0,A
  127F  5004      JNC L1285
  1281  18        DEC R0
  1282  e4        CLR A
  1283  36        ADDC A,@R0
  1284  f6        MOV @R0,A
L1285:
  1285  50bc      JNC L1243
L1287:
  1287  e590      MOV A,P1
  1289  f4        CPL A
  128A  5401      ANL A,#01h
  128C  fe        MOV R6,A
  128D  e590      MOV A,P1
  128F  f4        CPL A
  1290  5404      ANL A,#04h
  1292  c3        CLR C
  1293  13        RRC A
  1294  4e        ORL A,R6
  1295  fe        MOV R6,A
  1296  e590      MOV A,P1
  1298  f4        CPL A
  1299  5402      ANL A,#02h
  129B  c3        CLR C
  129C  33        RLC A
  129D  4e        ORL A,R6
  129E  fe        MOV R6,A
  129F  e590      MOV A,P1
  12A1  f4        CPL A
  12A2  5408      ANL A,#08h
  12A4  4e        ORL A,R6
  12A5  f53d      MOV 3Dh,A
  12A7  e53d      MOV A,3Dh
  12A9  7f0e      MOV R7,#0Eh
  12AB  903824    MOV DPTR,#3824h
  12AE  123ae8    LCALL L3AE8
  12B1  e53d      MOV A,3Dh
  12B3  fe        MOV R6,A
  12B4  e4        CLR A
  12B5  93        MOVC A,@A+DPTR
  12B6  ff        MOV R7,A
  12B7  ee        MOV A,R6
  12B8  8f04      MOV 04h,R7
  12BA  7f0e      MOV R7,#0Eh
  12BC  903826    MOV DPTR,#3826h
  12BF  123ae8    LCALL L3AE8
  12C2  ec        MOV A,R4
  12C3  fe        MOV R6,A
  12C4  e4        CLR A
  12C5  93        MOVC A,@A+DPTR
  12C6  ff        MOV R7,A
  12C7  ee        MOV A,R6
  12C8  2f        ADD A,R7
  12C9  900354    MOV DPTR,#0354h
  12CC  f0        MOVX @DPTR,A
  12CD  e53d      MOV A,3Dh
  12CF  7f0e      MOV R7,#0Eh
  12D1  903825    MOV DPTR,#3825h
  12D4  123ae8    LCALL L3AE8
  12D7  e4        CLR A
  12D8  93        MOVC A,@A+DPTR
  12D9  900355    MOV DPTR,#0355h
  12DC  f0        MOVX @DPTR,A
  12DD  e53d      MOV A,3Dh
  12DF  7f0e      MOV R7,#0Eh
  12E1  903822    MOV DPTR,#3822h
  12E4  123ae8    LCALL L3AE8
  12E7  784d      MOV R0,#4Dh
  12E9  123b7e    LCALL L3B7E
  12EC  e53d      MOV A,3Dh
  12EE  7f0e      MOV R7,#0Eh
  12F0  90382d    MOV DPTR,#382Dh
  12F3  123ae8    LCALL L3AE8
  12F6  e4        CLR A
  12F7  93        MOVC A,@A+DPTR
  12F8  f524      MOV 24h,A
  12FA  753600    MOV 36h,#00h
  12FD  753500    MOV 35h,#00h
L1300:
  1300  ae35      MOV R6,35h
  1302  af36      MOV R7,36h
  1304  7440      MOV A,#40h
  1306  be001a    CJNE R6,#00h,L1323
  1309  9f        SUBB A,R7
  130A  4017      JC L1323
  130C  900219    MOV DPTR,#0219h
  130F  123b56    LCALL L3B56
  1312  7420      MOV A,#20h
  1314  f0        MOVX @DPTR,A
  1315  7836      MOV R0,#36h
  1317  7401      MOV A,#01h
  1319  26        ADD A,@R0
  131A  f6        MOV @R0,A
  131B  5004      JNC L1321
  131D  18        DEC R0
  131E  e4        CLR A
  131F  36        ADDC A,@R0
  1320  f6        MOV @R0,A
L1321:
  1321  50dd      JNC L1300
L1323:
  1323  22        RET
  1324  db 75 4F 01 E5 4F D3 94 03 50 0A E5 4F 24 24 F8 E6  ; uO..O...P..O$$..
  1334  db 64 30 60 02 80 04 05 4F 80 E9 75 50 01 E5 4F D3  ; d0`....O..uP..O.
  1344  db 94 03 50 14 E5 4F 24 24 F8 E5 50 86 06 24 24 F8  ; ..P..O$$..P..$$.
  1354  db A6 06 05 4F 05 50 80 E5 E5 50 D3 94 03 50 0B E5  ; ...O.P...P...P..
  1364  db 50 24 24 F8 76 20 05 50 80 EE 22  ; P$$.v .P.."
L136F:
  136F  75a800    MOV IE,#00h
  1372  121129    LCALL L1129
  1375  75a882    MOV IE,#82h
  1378  12052e    LCALL L052E
  137B  75a892    MOV IE,#92h
L137E:
  137E  a204      MOV C,20h.4{b04}
  1380  b3        CPL C
  1381  8201      ANL C,20h.1{b01}
  1383  4003      JC L1388
  1385  021596    LJMP L1596
L1388:
  1388  900358    MOV DPTR,#0358h
  138B  74ff      MOV A,#FFh
  138D  f0        MOVX @DPTR,A
  138E  a3        INC DPTR
  138F  74ff      MOV A,#FFh
  1391  f0        MOVX @DPTR,A
  1392  c201      CLR 20h.1{b01}
  1394  300605    JNB 20h.6{b06},L139C
  1397  c211      CLR 22h.1{b11}
  1399  02155e    LJMP L155E
L139C:
  139C  90000b    MOV DPTR,#000Bh
  139F  e0        MOVX A,@DPTR
  13A0  fe        MOV R6,A
  13A1  a3        INC DPTR
  13A2  e0        MOVX A,@DPTR
  13A3  ff        MOV R7,A
  13A4  900003    MOV DPTR,#0003h
  13A7  e0        MOVX A,@DPTR
  13A8  fc        MOV R4,A
  13A9  a3        INC DPTR
  13AA  e0        MOVX A,@DPTR
  13AB  fd        MOV R5,A
  13AC  ef        MOV A,R7
  13AD  6d        XRL A,R5
  13AE  7004      JNZ L13B4
  13B0  ee        MOV A,R6
  13B1  6c        XRL A,R4
  13B2  6029      JZ L13DD
L13B4:
  13B4  90000b    MOV DPTR,#000Bh
  13B7  e0        MOVX A,@DPTR
  13B8  f8        MOV R0,A
  13B9  a3        INC DPTR
  13BA  e0        MOVX A,@DPTR
  13BB  900003    MOV DPTR,#0003h
  13BE  c8        XCH A,R0
  13BF  f0        MOVX @DPTR,A
  13C0  a3        INC DPTR
  13C1  c8        XCH A,R0
  13C2  f0        MOVX @DPTR,A
  13C3  c211      CLR 22h.1{b11}
  13C5  d212      SETB 22h.2{b12}
  13C7  900003    MOV DPTR,#0003h
  13CA  e0        MOVX A,@DPTR
  13CB  fc        MOV R4,A
  13CC  a3        INC DPTR
  13CD  e0        MOVX A,@DPTR
  13CE  fd        MOV R5,A
  13CF  74ff      MOV A,#FFh
  13D1  6204      XRL 04h,A
  13D3  6205      XRL 05h,A
  13D5  90000d    MOV DPTR,#000Dh
  13D8  ec        MOV A,R4
  13D9  f0        MOVX @DPTR,A
  13DA  a3        INC DPTR
  13DB  ed        MOV A,R5
  13DC  f0        MOVX @DPTR,A
L13DD:
  13DD  900011    MOV DPTR,#0011h
  13E0  e0        MOVX A,@DPTR
  13E1  fe        MOV R6,A
  13E2  a3        INC DPTR
  13E3  e0        MOVX A,@DPTR
  13E4  ff        MOV R7,A
  13E5  90000f    MOV DPTR,#000Fh
  13E8  e0        MOVX A,@DPTR
  13E9  fc        MOV R4,A
  13EA  a3        INC DPTR
  13EB  e0        MOVX A,@DPTR
  13EC  fd        MOV R5,A
  13ED  ef        MOV A,R7
  13EE  6d        XRL A,R5
  13EF  7004      JNZ L13F5
  13F1  ee        MOV A,R6
  13F2  6c        XRL A,R4
  13F3  6029      JZ L141E
L13F5:
  13F5  900011    MOV DPTR,#0011h
  13F8  e0        MOVX A,@DPTR
  13F9  f8        MOV R0,A
  13FA  a3        INC DPTR
  13FB  e0        MOVX A,@DPTR
  13FC  90000f    MOV DPTR,#000Fh
  13FF  c8        XCH A,R0
  1400  f0        MOVX @DPTR,A
  1401  a3        INC DPTR
  1402  c8        XCH A,R0
  1403  f0        MOVX @DPTR,A
  1404  c211      CLR 22h.1{b11}
  1406  d212      SETB 22h.2{b12}
  1408  90000f    MOV DPTR,#000Fh
  140B  e0        MOVX A,@DPTR
  140C  fc        MOV R4,A
  140D  a3        INC DPTR
  140E  e0        MOVX A,@DPTR
  140F  fd        MOV R5,A
  1410  74ff      MOV A,#FFh
  1412  6204      XRL 04h,A
  1414  6205      XRL 05h,A
  1416  900013    MOV DPTR,#0013h
  1419  ec        MOV A,R4
  141A  f0        MOVX @DPTR,A
  141B  a3        INC DPTR
  141C  ed        MOV A,R5
  141D  f0        MOVX @DPTR,A
L141E:
  141E  900015    MOV DPTR,#0015h
  1421  e0        MOVX A,@DPTR
  1422  fe        MOV R6,A
  1423  a3        INC DPTR
  1424  e0        MOVX A,@DPTR
  1425  ff        MOV R7,A
  1426  900005    MOV DPTR,#0005h
  1429  e0        MOVX A,@DPTR
  142A  fc        MOV R4,A
  142B  a3        INC DPTR
  142C  e0        MOVX A,@DPTR
  142D  fd        MOV R5,A
  142E  ef        MOV A,R7
  142F  6d        XRL A,R5
  1430  7004      JNZ L1436
  1432  ee        MOV A,R6
  1433  6c        XRL A,R4
  1434  6029      JZ L145F
L1436:
  1436  900015    MOV DPTR,#0015h
  1439  e0        MOVX A,@DPTR
  143A  f8        MOV R0,A
  143B  a3        INC DPTR
  143C  e0        MOVX A,@DPTR
  143D  900005    MOV DPTR,#0005h
  1440  c8        XCH A,R0
  1441  f0        MOVX @DPTR,A
  1442  a3        INC DPTR
  1443  c8        XCH A,R0
  1444  f0        MOVX @DPTR,A
  1445  c211      CLR 22h.1{b11}
  1447  d212      SETB 22h.2{b12}
  1449  900005    MOV DPTR,#0005h
  144C  e0        MOVX A,@DPTR
  144D  fc        MOV R4,A
  144E  a3        INC DPTR
  144F  e0        MOVX A,@DPTR
  1450  fd        MOV R5,A
  1451  74ff      MOV A,#FFh
  1453  6204      XRL 04h,A
  1455  6205      XRL 05h,A
  1457  900017    MOV DPTR,#0017h
  145A  ec        MOV A,R4
  145B  f0        MOVX @DPTR,A
  145C  a3        INC DPTR
  145D  ed        MOV A,R5
  145E  f0        MOVX @DPTR,A
L145F:
  145F  90001b    MOV DPTR,#001Bh
  1462  e0        MOVX A,@DPTR
  1463  fe        MOV R6,A
  1464  a3        INC DPTR
  1465  e0        MOVX A,@DPTR
  1466  ff        MOV R7,A
  1467  900019    MOV DPTR,#0019h
  146A  e0        MOVX A,@DPTR
  146B  fc        MOV R4,A
  146C  a3        INC DPTR
  146D  e0        MOVX A,@DPTR
  146E  fd        MOV R5,A
  146F  ef        MOV A,R7
  1470  6d        XRL A,R5
  1471  7004      JNZ L1477
  1473  ee        MOV A,R6
  1474  6c        XRL A,R4
  1475  6029      JZ L14A0
L1477:
  1477  90001b    MOV DPTR,#001Bh
  147A  e0        MOVX A,@DPTR
  147B  f8        MOV R0,A
  147C  a3        INC DPTR
  147D  e0        MOVX A,@DPTR
  147E  900019    MOV DPTR,#0019h
  1481  c8        XCH A,R0
  1482  f0        MOVX @DPTR,A
  1483  a3        INC DPTR
  1484  c8        XCH A,R0
  1485  f0        MOVX @DPTR,A
  1486  c211      CLR 22h.1{b11}
  1488  d212      SETB 22h.2{b12}
  148A  900019    MOV DPTR,#0019h
  148D  e0        MOVX A,@DPTR
  148E  fc        MOV R4,A
  148F  a3        INC DPTR
  1490  e0        MOVX A,@DPTR
  1491  fd        MOV R5,A
  1492  74ff      MOV A,#FFh
  1494  6204      XRL 04h,A
  1496  6205      XRL 05h,A
  1498  90001d    MOV DPTR,#001Dh
  149B  ec        MOV A,R4
  149C  f0        MOVX @DPTR,A
  149D  a3        INC DPTR
  149E  ed        MOV A,R5
  149F  f0        MOVX @DPTR,A
L14A0:
  14A0  900021    MOV DPTR,#0021h
  14A3  e0        MOVX A,@DPTR
  14A4  fe        MOV R6,A
  14A5  a3        INC DPTR
  14A6  e0        MOVX A,@DPTR
  14A7  ff        MOV R7,A
  14A8  90001f    MOV DPTR,#001Fh
  14AB  e0        MOVX A,@DPTR
  14AC  fc        MOV R4,A
  14AD  a3        INC DPTR
  14AE  e0        MOVX A,@DPTR
  14AF  fd        MOV R5,A
  14B0  ef        MOV A,R7
  14B1  6d        XRL A,R5
  14B2  7004      JNZ L14B8
  14B4  ee        MOV A,R6
  14B5  6c        XRL A,R4
  14B6  6029      JZ L14E1
L14B8:
  14B8  900021    MOV DPTR,#0021h
  14BB  e0        MOVX A,@DPTR
  14BC  f8        MOV R0,A
  14BD  a3        INC DPTR
  14BE  e0        MOVX A,@DPTR
  14BF  90001f    MOV DPTR,#001Fh
  14C2  c8        XCH A,R0
  14C3  f0        MOVX @DPTR,A
  14C4  a3        INC DPTR
  14C5  c8        XCH A,R0
  14C6  f0        MOVX @DPTR,A
  14C7  c211      CLR 22h.1{b11}
  14C9  d212      SETB 22h.2{b12}
  14CB  90001f    MOV DPTR,#001Fh
  14CE  e0        MOVX A,@DPTR
  14CF  fc        MOV R4,A
  14D0  a3        INC DPTR
  14D1  e0        MOVX A,@DPTR
  14D2  fd        MOV R5,A
  14D3  74ff      MOV A,#FFh
  14D5  6204      XRL 04h,A
  14D7  6205      XRL 05h,A
  14D9  900023    MOV DPTR,#0023h
  14DC  ec        MOV A,R4
  14DD  f0        MOVX @DPTR,A
  14DE  a3        INC DPTR
  14DF  ed        MOV A,R5
  14E0  f0        MOVX @DPTR,A
L14E1:
  14E1  c3        CLR C
  14E2  507a      JNC L155E
  14E4  c209      CLR 21h.1{b09}
  14E6  756102    MOV 61h,#02h
  14E9  75625a    MOV 62h,#5Ah
  14EC  740d      MOV A,#0Dh
  14EE  f563      MOV 63h,A
  14F0  7565f9    MOV 65h,#F9h
  14F3  756400    MOV 64h,#00h
  14F6  123a87    LCALL L3A87
  14F9  8e39      MOV 39h,R6
  14FB  8f3a      MOV 3Ah,R7
  14FD  74f9      MOV A,#F9h
  14FF  be0003    CJNE R6,#00h,L1505
  1502  9f        SUBB A,R7
  1503  500c      JNC L1511
L1505:
  1505  740d      MOV A,#0Dh
  1507  900353    MOV DPTR,#0353h
  150A  f0        MOVX @DPTR,A
  150B  753af9    MOV 3Ah,#F9h
  150E  753900    MOV 39h,#00h
L1511:
  1511  753600    MOV 36h,#00h
  1514  753500    MOV 35h,#00h
L1517:
  1517  ae35      MOV R6,35h
  1519  af36      MOV R7,36h
  151B  ac39      MOV R4,39h
  151D  ad3a      MOV R5,3Ah
  151F  ed        MOV A,R5
  1520  c3        CLR C
  1521  9f        SUBB A,R7
  1522  ec        MOV A,R4
  1523  9e        SUBB A,R6
  1524  4038      JC L155E
  1526  90011f    MOV DPTR,#011Fh
  1529  123b56    LCALL L3B56
  152C  e0        MOVX A,@DPTR
  152D  fa        MOV R2,A
  152E  90025a    MOV DPTR,#025Ah
  1531  123b56    LCALL L3B56
  1534  ea        MOV A,R2
  1535  fa        MOV R2,A
  1536  e0        MOVX A,@DPTR
  1537  fb        MOV R3,A
  1538  ea        MOV A,R2
  1539  6b        XRL A,R3
  153A  6014      JZ L1550
  153C  d212      SETB 22h.2{b12}
  153E  c211      CLR 22h.1{b11}
  1540  90025a    MOV DPTR,#025Ah
  1543  123b56    LCALL L3B56
  1546  e0        MOVX A,@DPTR
  1547  fa        MOV R2,A
  1548  90011f    MOV DPTR,#011Fh
  154B  123b56    LCALL L3B56
  154E  ea        MOV A,R2
  154F  f0        MOVX @DPTR,A
L1550:
  1550  7836      MOV R0,#36h
  1552  7401      MOV A,#01h
  1554  26        ADD A,@R0
  1555  f6        MOV @R0,A
  1556  5004      JNC L155C
  1558  18        DEC R0
  1559  e4        CLR A
  155A  36        ADDC A,@R0
  155B  f6        MOV @R0,A
L155C:
  155C  50b9      JNC L1517
L155E:
  155E  300732    JNB 20h.7{b07},L1593
  1561  a212      MOV C,22h.2{b12}
  1563  b3        CPL C
  1564  5017      JNC L157D
  1566  ae3e      MOV R6,3Eh
  1568  af3f      MOV R7,3Fh
  156A  7401      MOV A,#01h
  156C  be0003    CJNE R6,#00h,L1572
  156F  9f        SUBB A,R7
  1570  500b      JNC L157D
L1572:
  1572  a211      MOV C,22h.1{b11}
  1574  b3        CPL C
  1575  5006      JNC L157D
  1577  74ff      MOV A,#FFh
  1579  653d      XRL A,3Dh
  157B  6002      JZ L157F
L157D:
  157D  8002      SJMP L1581
L157F:
  157F  d212      SETB 22h.2{b12}
L1581:
  1581  c207      CLR 20h.7{b07}
  1583  e53f      MOV A,3Fh
  1585  453e      ORL A,3Eh
  1587  700a      JNZ L1593
  1589  900356    MOV DPTR,#0356h
  158C  e0        MOVX A,@DPTR
  158D  f53e      MOV 3Eh,A
  158F  a3        INC DPTR
  1590  e0        MOVX A,@DPTR
  1591  f53f      MOV 3Fh,A
L1593:
  1593  752e00    MOV 2Eh,#00h
L1596:
  1596  201203    JB 22h.2{b12},L159C
  1599  021c18    LJMP L1C18
L159C:
  159C  c212      CLR 22h.2{b12}
  159E  754200    MOV 42h,#00h
  15A1  754700    MOV 47h,#00h
  15A4  754005    MOV 40h,#05h
  15A7  7541dc    MOV 41h,#DCh
  15AA  754600    MOV 46h,#00h
  15AD  d205      SETB 20h.5{b05}
  15AF  753600    MOV 36h,#00h
  15B2  753500    MOV 35h,#00h
L15B5:
  15B5  ae35      MOV R6,35h
  15B7  af36      MOV R7,36h
  15B9  7440      MOV A,#40h
  15BB  be001a    CJNE R6,#00h,L15D8
  15BE  9f        SUBB A,R7
  15BF  4017      JC L15D8
  15C1  900219    MOV DPTR,#0219h
  15C4  123b56    LCALL L3B56
  15C7  7420      MOV A,#20h
  15C9  f0        MOVX @DPTR,A
  15CA  7836      MOV R0,#36h
  15CC  7401      MOV A,#01h
  15CE  26        ADD A,@R0
  15CF  f6        MOV @R0,A
  15D0  5004      JNC L15D6
  15D2  18        DEC R0
  15D3  e4        CLR A
  15D4  36        ADDC A,@R0
  15D5  f6        MOV @R0,A
L15D6:
  15D6  50dd      JNC L15B5
L15D8:
  15D8  753300    MOV 33h,#00h
  15DB  021704    LJMP L1704
  15DE  db AE 35 AF 36 74 04 BE 00 18 9F 40 15 E5 36 24 24  ; .5.6t.....@..6$$
  15EE  db F8 76 20 78 36 74 01 26 F6 50 04 18 E4 36 F6 50  ; .v x6t.&.P...6.P
  15FE  db DF 85 4B 61 85 4C 62 74 0D F5 63 75 65 FA 75 64  ; ..Ka.Lbt..cue.ud
  160E  db 00 12 3A 87 8E 37 8F 38 EF B4 FF 0A EE B4 FF 06  ; ..:..7.8........
  161E  db 75 38 F9 75 37 00 85 4B 61 85 4C 62 74 05 F5 63  ; u8.u7..Ka.Lbt..c
  162E  db 85 37 64 85 38 65 12 3A 87 8E 39 8F 3A EF B4 FF  ; .7d.8e.:..9.:...
  163E  db 29 EE B4 FF 25 85 4B 61 85 4C 62 74 03 F5 63 85  ; )...%.Ka.Lbt..c.
  164E  db 37 64 85 38 65 12 3A 87 8E 39 8F 3A 74 06 BE 00  ; 7d.8e.:..9.:t...
  165E  db 03 9F 50 06 75 39 FF 75 3A FF 78 39 12 3B 90 75  ; ..P.u9.u:.x9.;.u
  166E  db 36 01 75 35 00 80 32 AE 39 AF 3A AC 35 AD 36 EF  ; 6.u5..2.9.:.5.6.
  167E  db D3 9D EE 9C 40 21 1D BD FF 01 1C 85 4B 83 85 4C  ; ....@!......K..L
  168E  db 82 8C 06 8D 07 12 3B 56 E5 36 14 24 24 F8 E0 F6  ; ......;V.6.$$...
  169E  db 78 35 12 3B 90 80 D0 80 44 AE 39 AF 3A AC 35 AD  ; x5.;....D.9.:.5.
  16AE  db 36 EF D3 9D EE 9C 40 20 1D BD FF 01 1C 85 4B 83  ; 6.....@ ......K.
  16BE  db 85 4C 82 8C 06 8D 07 12 3B 56 E5 36 24 24 F8 E0  ; .L......;V.6$$..
  16CE  db F6 78 35 12 3B 90 80 D1 E5 36 24 24 F8 76 0D E5  ; .x5.;....6$$.v..
  16DE  db 3D 7F 0E 90 38 2D 12 3A E8 E4 93 F5 24 AE 4B AF  ; =...8-.:....$.K.
  16EE  db 4C AC 39 AD 3A EF 2D FD EE 3C FC 90 03 5C EC F0  ; L.9.:.-..<...\..
  16FE  db A3 ED F0 02 18 69  ; .....i
L1704:
  1704  8035      SJMP L173B
  1706  db AE 35 AF 36 74 03 BE 00 23 9F 40 20 1F BF FF 01  ; .5.6t...#.@ ....
  1716  db 1E 90 00 07 12 3B 56 E5 36 24 24 F8 E0 F6 78 36  ; .....;V.6$$...x6
  1726  db 74 01 26 F6 50 04 18 E4 36 F6 50 D4 12 00 26 12  ; t.&.P...6.P...&.
  1736  db 13 24 02 18 69  ; .$..i
L173B:
  173B  900003    MOV DPTR,#0003h
  173E  e0        MOVX A,@DPTR
  173F  fe        MOV R6,A
  1740  a3        INC DPTR
  1741  e0        MOVX A,@DPTR
  1742  ff        MOV R7,A
  1743  7c03      MOV R4,#03h
  1745  7de8      MOV R5,#E8h
  1747  ef        MOV A,R7
  1748  2d        ADD A,R5
  1749  fd        MOV R5,A
  174A  ee        MOV A,R6
  174B  3c        ADDC A,R4
  174C  fc        MOV R4,A
  174D  8c4f      MOV 4Fh,R4
  174F  8d50      MOV 50h,R5
  1751  121054    LCALL L1054
  1754  753600    MOV 36h,#00h
  1757  753500    MOV 35h,#00h
L175A:
  175A  ae35      MOV R6,35h
  175C  af36      MOV R7,36h
  175E  7404      MOV A,#04h
  1760  be0018    CJNE R6,#00h,L177B
  1763  9f        SUBB A,R7
  1764  4015      JC L177B
  1766  e536      MOV A,36h
  1768  2424      ADD A,#24h
  176A  f8        MOV R0,A
  176B  7620      MOV @R0,#20h
  176D  7836      MOV R0,#36h
  176F  7401      MOV A,#01h
  1771  26        ADD A,@R0
  1772  f6        MOV @R0,A
  1773  5004      JNC L1779
  1775  18        DEC R0
  1776  e4        CLR A
  1777  36        ADDC A,@R0
  1778  f6        MOV @R0,A
L1779:
  1779  50df      JNC L175A
L177B:
  177B  75290d    MOV 29h,#0Dh
  177E  854b61    MOV 61h,4Bh
  1781  854c62    MOV 62h,4Ch
  1784  740d      MOV A,#0Dh
  1786  f563      MOV 63h,A
  1788  7565fa    MOV 65h,#FAh
  178B  756400    MOV 64h,#00h
  178E  123a87    LCALL L3A87
  1791  8e37      MOV 37h,R6
  1793  8f38      MOV 38h,R7
  1795  ef        MOV A,R7
  1796  b4ff0a    CJNE A,#FFh,L17A3
  1799  ee        MOV A,R6
  179A  b4ff06    CJNE A,#FFh,L17A3
  179D  7538f9    MOV 38h,#F9h
  17A0  753700    MOV 37h,#00h
L17A3:
  17A3  854b61    MOV 61h,4Bh
  17A6  854c62    MOV 62h,4Ch
  17A9  7405      MOV A,#05h
  17AB  f563      MOV 63h,A
  17AD  853764    MOV 64h,37h
  17B0  853865    MOV 65h,38h
  17B3  123a87    LCALL L3A87
  17B6  8e39      MOV 39h,R6
  17B8  8f3a      MOV 3Ah,R7
  17BA  ef        MOV A,R7
  17BB  b4ff29    CJNE A,#FFh,L17E7
  17BE  ee        MOV A,R6
  17BF  b4ff25    CJNE A,#FFh,L17E7
  17C2  854b61    MOV 61h,4Bh
  17C5  854c62    MOV 62h,4Ch
  17C8  7403      MOV A,#03h
  17CA  f563      MOV 63h,A
  17CC  853764    MOV 64h,37h
  17CF  853865    MOV 65h,38h
  17D2  123a87    LCALL L3A87
  17D5  8e39      MOV 39h,R6
  17D7  8f3a      MOV 3Ah,R7
  17D9  7406      MOV A,#06h
  17DB  be0003    CJNE R6,#00h,L17E1
  17DE  9f        SUBB A,R7
  17DF  5006      JNC L17E7
L17E1:
  17E1  7539ff    MOV 39h,#FFh
  17E4  753aff    MOV 3Ah,#FFh
L17E7:
  17E7  ae39      MOV R6,39h
  17E9  af3a      MOV R7,3Ah
  17EB  ef        MOV A,R7
  17EC  b4ff30    CJNE A,#FFh,L181F
  17EF  ee        MOV A,R6
  17F0  b4ff2c    CJNE A,#FFh,L181F
  17F3  854b61    MOV 61h,4Bh
  17F6  854c62    MOV 62h,4Ch
  17F9  740d      MOV A,#0Dh
  17FB  f563      MOV 63h,A
  17FD  ac37      MOV R4,37h
  17FF  ad38      MOV R5,38h
  1801  0d        INC R5
  1802  bd0001    CJNE R5,#00h,L1806
  1805  0c        INC R4
L1806:
  1806  8c64      MOV 64h,R4
  1808  8d65      MOV 65h,R5
  180A  123a87    LCALL L3A87
  180D  8e39      MOV 39h,R6
  180F  8f3a      MOV 3Ah,R7
  1811  7406      MOV A,#06h
  1813  be0003    CJNE R6,#00h,L1819
  1816  9f        SUBB A,R7
  1817  5006      JNC L181F
L1819:
  1819  7539ff    MOV 39h,#FFh
  181C  753aff    MOV 3Ah,#FFh
L181F:
  181F  7839      MOV R0,#39h
  1821  123b90    LCALL L3B90
  1824  753601    MOV 36h,#01h
  1827  753500    MOV 35h,#00h
L182A:
  182A  ae39      MOV R6,39h
  182C  af3a      MOV R7,3Ah
  182E  ac35      MOV R4,35h
  1830  ad36      MOV R5,36h
  1832  ef        MOV A,R7
  1833  d3        SETB C
  1834  9d        SUBB A,R5
  1835  ee        MOV A,R6
  1836  9c        SUBB A,R4
  1837  401b      JC L1854
  1839  854b83    MOV DPH,4Bh
  183C  854c82    MOV DPL,4Ch
  183F  8c06      MOV 06h,R4
  1841  8d07      MOV 07h,R5
  1843  123b56    LCALL L3B56
  1846  e536      MOV A,36h
  1848  2424      ADD A,#24h
  184A  f8        MOV R0,A
  184B  e0        MOVX A,@DPTR
  184C  f6        MOV @R0,A
  184D  7835      MOV R0,#35h
  184F  123b90    LCALL L3B90
  1852  80d6      SJMP L182A
L1854:
  1854  e536      MOV A,36h
  1856  2424      ADD A,#24h
  1858  f8        MOV R0,A
  1859  760d      MOV @R0,#0Dh
  185B  e53d      MOV A,3Dh
  185D  7f0e      MOV R7,#0Eh
  185F  90382d    MOV DPTR,#382Dh
  1862  123ae8    LCALL L3AE8
  1865  e4        CLR A
  1866  93        MOVC A,@A+DPTR
  1867  f524      MOV 24h,A
  1869  753600    MOV 36h,#00h
  186C  753500    MOV 35h,#00h
L186F:
  186F  ae35      MOV R6,35h
  1871  af36      MOV R7,36h
  1873  748b      MOV A,#8Bh
  1875  be001f    CJNE R6,#00h,L1897
  1878  9f        SUBB A,R7
  1879  401c      JC L1897
  187B  900363    MOV DPTR,#0363h
  187E  12000e    LCALL L000E
  1881  7400      MOV A,#00h
  1883  f8        MOV R0,A
  1884  e4        CLR A
  1885  f0        MOVX @DPTR,A
  1886  e8        MOV A,R0
  1887  a3        INC DPTR
  1888  f0        MOVX @DPTR,A
  1889  7836      MOV R0,#36h
  188B  7401      MOV A,#01h
  188D  26        ADD A,@R0
  188E  f6        MOV @R0,A
  188F  5004      JNC L1895
  1891  18        DEC R0
  1892  e4        CLR A
  1893  36        ADDC A,@R0
  1894  f6        MOV @R0,A
L1895:
  1895  50d8      JNC L186F
L1897:
  1897  90035f    MOV DPTR,#035Fh
  189A  e4        CLR A
  189B  f0        MOVX @DPTR,A
  189C  754200    MOV 42h,#00h
  189F  754700    MOV 47h,#00h
  18A2  e53d      MOV A,3Dh
  18A4  7f0e      MOV R7,#0Eh
  18A6  903824    MOV DPTR,#3824h
  18A9  123ae8    LCALL L3AE8
  18AC  e4        CLR A
  18AD  93        MOVC A,@A+DPTR
  18AE  601d      JZ L18CD
  18B0  e53d      MOV A,3Dh
  18B2  7f0e      MOV R7,#0Eh
  18B4  903829    MOV DPTR,#3829h
  18B7  123ae8    LCALL L3AE8
  18BA  e4        CLR A
  18BB  93        MOVC A,@A+DPTR
  18BC  b4010e    CJNE A,#01h,L18CD
  18BF  e53d      MOV A,3Dh
  18C1  7f0e      MOV R7,#0Eh
  18C3  90382c    MOV DPTR,#382Ch
  18C6  123ae8    LCALL L3AE8
  18C9  e4        CLR A
  18CA  93        MOVC A,@A+DPTR
  18CB  6003      JZ L18D0
L18CD:
  18CD  021983    LJMP L1983
L18D0:
  18D0  75290d    MOV 29h,#0Dh
  18D3  753600    MOV 36h,#00h
  18D6  753500    MOV 35h,#00h
L18D9:
  18D9  ae35      MOV R6,35h
  18DB  af36      MOV R7,36h
  18DD  7406      MOV A,#06h
  18DF  be001e    CJNE R6,#00h,L1900
  18E2  9f        SUBB A,R7
  18E3  401b      JC L1900
  18E5  e536      MOV A,36h
  18E7  2424      ADD A,#24h
  18E9  f8        MOV R0,A
  18EA  900025    MOV DPTR,#0025h
  18ED  123b56    LCALL L3B56
  18F0  e6        MOV A,@R0
  18F1  f0        MOVX @DPTR,A
  18F2  7836      MOV R0,#36h
  18F4  7401      MOV A,#01h
  18F6  26        ADD A,@R0
  18F7  f6        MOV @R0,A
  18F8  5004      JNC L18FE
  18FA  18        DEC R0
  18FB  e4        CLR A
  18FC  36        ADDC A,@R0
  18FD  f6        MOV @R0,A
L18FE:
  18FE  50d9      JNC L18D9
L1900:
  1900  754904    MOV 49h,#04h
  1903  e528      MOV A,28h
  1905  6420      XRL A,#20h
  1907  6005      JZ L190E
  1909  e528      MOV A,28h
  190B  b40d2d    CJNE A,#0Dh,L193B
L190E:
  190E  754903    MOV 49h,#03h
  1911  e527      MOV A,27h
  1913  6420      XRL A,#20h
  1915  6005      JZ L191C
  1917  e527      MOV A,27h
  1919  b40d1f    CJNE A,#0Dh,L193B
L191C:
  191C  754902    MOV 49h,#02h
  191F  e526      MOV A,26h
  1921  6420      XRL A,#20h
  1923  6005      JZ L192A
  1925  e526      MOV A,26h
  1927  b40d11    CJNE A,#0Dh,L193B
L192A:
  192A  754901    MOV 49h,#01h
  192D  e525      MOV A,25h
  192F  6420      XRL A,#20h
  1931  6005      JZ L1938
  1933  e525      MOV A,25h
  1935  b40d03    CJNE A,#0Dh,L193B
L1938:
  1938  754900    MOV 49h,#00h
L193B:
  193B  e549      MOV A,49h
  193D  7f03      MOV R7,#03h
  193F  903812    MOV DPTR,#3812h
  1942  123ae8    LCALL L3AE8
  1945  e4        CLR A
  1946  93        MOVC A,@A+DPTR
  1947  90035f    MOV DPTR,#035Fh
  194A  f0        MOVX @DPTR,A
  194B  e549      MOV A,49h
  194D  7f03      MOV R7,#03h
  194F  903811    MOV DPTR,#3811h
  1952  123ae8    LCALL L3AE8
  1955  e4        CLR A
  1956  93        MOVC A,@A+DPTR
  1957  f542      MOV 42h,A
  1959  c202      CLR 20h.2{b02}
  195B  e549      MOV A,49h
  195D  7f03      MOV R7,#03h
  195F  903813    MOV DPTR,#3813h
  1962  123ae8    LCALL L3AE8
  1965  e4        CLR A
  1966  93        MOVC A,@A+DPTR
  1967  f55a      MOV 5Ah,A
  1969  1208e3    LCALL L08E3
  196C  d202      SETB 20h.2{b02}
  196E  e533      MOV A,33h
  1970  14        DEC A
  1971  900219    MOV DPTR,#0219h
  1974  123b75    LCALL L3B75
  1977  7420      MOV A,#20h
  1979  f0        MOVX @DPTR,A
  197A  90035f    MOV DPTR,#035Fh
  197D  e0        MOVX A,@DPTR
  197E  f542      MOV 42h,A
  1980  854247    MOV 47h,42h
L1983:
  1983  e53d      MOV A,3Dh
  1985  7f0e      MOV R7,#0Eh
  1987  903824    MOV DPTR,#3824h
  198A  123ae8    LCALL L3AE8
  198D  e4        CLR A
  198E  93        MOVC A,@A+DPTR
  198F  601f      JZ L19B0
  1991  e53d      MOV A,3Dh
  1993  7f0e      MOV R7,#0Eh
  1995  903829    MOV DPTR,#3829h
  1998  123ae8    LCALL L3AE8
  199B  e4        CLR A
  199C  93        MOVC A,@A+DPTR
  199D  b40110    CJNE A,#01h,L19B0
  19A0  e53d      MOV A,3Dh
  19A2  7f0e      MOV R7,#0Eh
  19A4  90382c    MOV DPTR,#382Ch
  19A7  123ae8    LCALL L3AE8
  19AA  e4        CLR A
  19AB  93        MOVC A,@A+DPTR
  19AC  6401      XRL A,#01h
  19AE  6003      JZ L19B3
L19B0:
  19B0  021a4b    LJMP L1A4B
L19B3:
  19B3  75290d    MOV 29h,#0Dh
  19B6  753600    MOV 36h,#00h
  19B9  753500    MOV 35h,#00h
L19BC:
  19BC  ae35      MOV R6,35h
  19BE  af36      MOV R7,36h
  19C0  7406      MOV A,#06h
  19C2  be001e    CJNE R6,#00h,L19E3
  19C5  9f        SUBB A,R7
  19C6  401b      JC L19E3
  19C8  e536      MOV A,36h
  19CA  2424      ADD A,#24h
  19CC  f8        MOV R0,A
  19CD  900025    MOV DPTR,#0025h
  19D0  123b56    LCALL L3B56
  19D3  e6        MOV A,@R0
  19D4  f0        MOVX @DPTR,A
  19D5  7836      MOV R0,#36h
  19D7  7401      MOV A,#01h
  19D9  26        ADD A,@R0
  19DA  f6        MOV @R0,A
  19DB  5004      JNC L19E1
  19DD  18        DEC R0
  19DE  e4        CLR A
  19DF  36        ADDC A,@R0
  19E0  f6        MOV @R0,A
L19E1:
  19E1  50d9      JNC L19BC
L19E3:
  19E3  754200    MOV 42h,#00h
  19E6  c202      CLR 20h.2{b02}
  19E8  e53d      MOV A,3Dh
  19EA  7f0e      MOV R7,#0Eh
  19EC  90382a    MOV DPTR,#382Ah
  19EF  123ae8    LCALL L3AE8
  19F2  e4        CLR A
  19F3  93        MOVC A,@A+DPTR
  19F4  f55a      MOV 5Ah,A
  19F6  1208e3    LCALL L08E3
  19F9  d202      SETB 20h.2{b02}
  19FB  e533      MOV A,33h
  19FD  14        DEC A
  19FE  900219    MOV DPTR,#0219h
  1A01  123b75    LCALL L3B75
  1A04  7420      MOV A,#20h
  1A06  f0        MOVX @DPTR,A
  1A07  90035f    MOV DPTR,#035Fh
  1A0A  e4        CLR A
  1A0B  f0        MOVX @DPTR,A
  1A0C  753600    MOV 36h,#00h
  1A0F  753500    MOV 35h,#00h
L1A12:
  1A12  ae35      MOV R6,35h
  1A14  af36      MOV R7,36h
  1A16  748b      MOV A,#8Bh
  1A18  be0027    CJNE R6,#00h,L1A42
  1A1B  9f        SUBB A,R7
  1A1C  4024      JC L1A42
  1A1E  900363    MOV DPTR,#0363h
  1A21  12000e    LCALL L000E
  1A24  e0        MOVX A,@DPTR
  1A25  fc        MOV R4,A
  1A26  a3        INC DPTR
  1A27  e0        MOVX A,@DPTR
  1A28  fd        MOV R5,A
  1A29  ed        MOV A,R5
  1A2A  4c        ORL A,R4
  1A2B  6007      JZ L1A34
  1A2D  e536      MOV A,36h
  1A2F  04        INC A
  1A30  90035f    MOV DPTR,#035Fh
  1A33  f0        MOVX @DPTR,A
L1A34:
  1A34  7836      MOV R0,#36h
  1A36  7401      MOV A,#01h
  1A38  26        ADD A,@R0
  1A39  f6        MOV @R0,A
  1A3A  5004      JNC L1A40
  1A3C  18        DEC R0
  1A3D  e4        CLR A
  1A3E  36        ADDC A,@R0
  1A3F  f6        MOV @R0,A
L1A40:
  1A40  50d0      JNC L1A12
L1A42:
  1A42  90035f    MOV DPTR,#035Fh
  1A45  e0        MOVX A,@DPTR
  1A46  f542      MOV 42h,A
  1A48  854247    MOV 47h,42h
L1A4B:
  1A4B  e53d      MOV A,3Dh
  1A4D  7f0e      MOV R7,#0Eh
  1A4F  903824    MOV DPTR,#3824h
  1A52  123ae8    LCALL L3AE8
  1A55  e4        CLR A
  1A56  93        MOVC A,@A+DPTR
  1A57  6010      JZ L1A69
  1A59  e53d      MOV A,3Dh
  1A5B  7f0e      MOV R7,#0Eh
  1A5D  90382b    MOV DPTR,#382Bh
  1A60  123ae8    LCALL L3AE8
  1A63  e4        CLR A
  1A64  93        MOVC A,@A+DPTR
  1A65  6401      XRL A,#01h
  1A67  6002      JZ L1A6B
L1A69:
  1A69  8070      SJMP L1ADB
L1A6B:
  1A6B  75290d    MOV 29h,#0Dh
  1A6E  753600    MOV 36h,#00h
  1A71  753500    MOV 35h,#00h
L1A74:
  1A74  ae35      MOV R6,35h
  1A76  af36      MOV R7,36h
  1A78  7406      MOV A,#06h
  1A7A  be001e    CJNE R6,#00h,L1A9B
  1A7D  9f        SUBB A,R7
  1A7E  401b      JC L1A9B
  1A80  e536      MOV A,36h
  1A82  2424      ADD A,#24h
  1A84  f8        MOV R0,A
  1A85  900025    MOV DPTR,#0025h
  1A88  123b56    LCALL L3B56
  1A8B  e6        MOV A,@R0
  1A8C  f0        MOVX @DPTR,A
  1A8D  7836      MOV R0,#36h
  1A8F  7401      MOV A,#01h
  1A91  26        ADD A,@R0
  1A92  f6        MOV @R0,A
  1A93  5004      JNC L1A99
  1A95  18        DEC R0
  1A96  e4        CLR A
  1A97  36        ADDC A,@R0
  1A98  f6        MOV @R0,A
L1A99:
  1A99  50d9      JNC L1A74
L1A9B:
  1A9B  754200    MOV 42h,#00h
  1A9E  c202      CLR 20h.2{b02}
  1AA0  e53d      MOV A,3Dh
  1AA2  7f0e      MOV R7,#0Eh
  1AA4  90382a    MOV DPTR,#382Ah
  1AA7  123ae8    LCALL L3AE8
  1AAA  e4        CLR A
  1AAB  93        MOVC A,@A+DPTR
  1AAC  f55a      MOV 5Ah,A
  1AAE  1208e3    LCALL L08E3
  1AB1  d202      SETB 20h.2{b02}
  1AB3  e533      MOV A,33h
  1AB5  14        DEC A
  1AB6  900219    MOV DPTR,#0219h
  1AB9  123b75    LCALL L3B75
  1ABC  7420      MOV A,#20h
  1ABE  f0        MOVX @DPTR,A
  1ABF  120b32    LCALL L0B32
  1AC2  e53d      MOV A,3Dh
  1AC4  7f0e      MOV R7,#0Eh
  1AC6  903824    MOV DPTR,#3824h
  1AC9  123ae8    LCALL L3AE8
  1ACC  e4        CLR A
  1ACD  93        MOVC A,@A+DPTR
  1ACE  90035f    MOV DPTR,#035Fh
  1AD1  f0        MOVX @DPTR,A
  1AD2  90035f    MOV DPTR,#035Fh
  1AD5  e0        MOVX A,@DPTR
  1AD6  f542      MOV 42h,A
  1AD8  854247    MOV 47h,42h
L1ADB:
  1ADB  e53d      MOV A,3Dh
  1ADD  7f0e      MOV R7,#0Eh
  1ADF  903826    MOV DPTR,#3826h
  1AE2  123ae8    LCALL L3AE8
  1AE5  e4        CLR A
  1AE6  93        MOVC A,@A+DPTR
  1AE7  7003      JNZ L1AEC
  1AE9  021c15    LJMP L1C15
L1AEC:
  1AEC  8000      SJMP L1AEE
L1AEE:
  1AEE  900005    MOV DPTR,#0005h
  1AF1  e0        MOVX A,@DPTR
  1AF2  fe        MOV R6,A
  1AF3  a3        INC DPTR
  1AF4  e0        MOVX A,@DPTR
  1AF5  ff        MOV R7,A
  1AF6  8e4f      MOV 4Fh,R6
  1AF8  8f50      MOV 50h,R7
  1AFA  121054    LCALL L1054
  1AFD  120027    LCALL L0027
  1B00  854b61    MOV 61h,4Bh
  1B03  854c62    MOV 62h,4Ch
  1B06  740d      MOV A,#0Dh
  1B08  f563      MOV 63h,A
  1B0A  7565fa    MOV 65h,#FAh
  1B0D  756400    MOV 64h,#00h
  1B10  123a87    LCALL L3A87
  1B13  8e39      MOV 39h,R6
  1B15  8f3a      MOV 3Ah,R7
  1B17  7402      MOV A,#02h
  1B19  be000d    CJNE R6,#00h,L1B29
  1B1C  9f        SUBB A,R7
  1B1D  400a      JC L1B29
  1B1F  d20e      SETB 21h.6{b0E}
  1B21  753c00    MOV 3Ch,#00h
  1B24  753b00    MOV 3Bh,#00h
  1B27  8008      SJMP L1B31
L1B29:
  1B29  85393b    MOV 3Bh,39h
  1B2C  853a3c    MOV 3Ch,3Ah
  1B2F  c20e      CLR 21h.6{b0E}
L1B31:
  1B31  753600    MOV 36h,#00h
  1B34  753500    MOV 35h,#00h
L1B37:
  1B37  ae35      MOV R6,35h
  1B39  af36      MOV R7,36h
  1B3B  ac39      MOV R4,39h
  1B3D  ad3a      MOV R5,3Ah
  1B3F  ed        MOV A,R5
  1B40  c3        CLR C
  1B41  9f        SUBB A,R7
  1B42  ec        MOV A,R4
  1B43  9e        SUBB A,R6
  1B44  4021      JC L1B67
  1B46  854b83    MOV DPH,4Bh
  1B49  854c82    MOV DPL,4Ch
  1B4C  123b56    LCALL L3B56
  1B4F  e0        MOVX A,@DPTR
  1B50  fa        MOV R2,A
  1B51  900025    MOV DPTR,#0025h
  1B54  123b56    LCALL L3B56
  1B57  ea        MOV A,R2
  1B58  f0        MOVX @DPTR,A
  1B59  7836      MOV R0,#36h
  1B5B  7401      MOV A,#01h
  1B5D  26        ADD A,@R0
  1B5E  f6        MOV @R0,A
  1B5F  5004      JNC L1B65
  1B61  18        DEC R0
  1B62  e4        CLR A
  1B63  36        ADDC A,@R0
  1B64  f6        MOV @R0,A
L1B65:
  1B65  50d0      JNC L1B37
L1B67:
  1B67  8071      SJMP L1BDA
  1B69  db AE 35 AF 36 AC 39 AD 3A ED C3 9F EC 9E 40 21 85  ; .5.6.9.:.....@!.
  1B79  db 4B 83 85 4C 82 12 3B 56 E0 FA 90 00 25 12 3B 56  ; K..L..;V....%.;V
  1B89  db EA F0 78 36 74 01 26 F6 50 04 18 E4 36 F6 50 D0  ; ..x6t.&.P...6.P.
  1B99  db 80 3F AE 35 AF 36 AC 39 AD 3A ED C3 9F EC 9E 40  ; .?.5.6.9.:.....@
  1BA9  db 30 85 4B 83 85 4C 82 12 3B 56 AA 3B AB 3C EB 2F  ; 0.K..L..;V.;.<./
  1BB9  db FF EA 3E FE 0F BF 00 01 0E E0 F9 90 00 25 12 3B  ; ..>..........%.;
  1BC9  db 56 E9 F0 78 36 74 01 26 F6 50 04 18 E4 36 F6 50  ; V..x6t.&.P...6.P
  1BD9  db C1  ; .
L1BDA:
  1BDA  e546      MOV A,46h
  1BDC  900361    MOV DPTR,#0361h
  1BDF  f0        MOVX @DPTR,A
  1BE0  c202      CLR 20h.2{b02}
  1BE2  755a00    MOV 5Ah,#00h
  1BE5  1208e3    LCALL L08E3
  1BE8  d202      SETB 20h.2{b02}
  1BEA  e546      MOV A,46h
  1BEC  900362    MOV DPTR,#0362h
  1BEF  f0        MOVX @DPTR,A
  1BF0  90035f    MOV DPTR,#035Fh
  1BF3  e0        MOVX A,@DPTR
  1BF4  f542      MOV 42h,A
  1BF6  900361    MOV DPTR,#0361h
  1BF9  e0        MOVX A,@DPTR
  1BFA  f546      MOV 46h,A
  1BFC  a213      MOV C,22h.3{b13}
  1BFE  8215      ANL C,22h.5{b15}
  1C00  7214      ORL C,22h.4{b14}
  1C02  5005      JNC L1C09
  1C04  120c10    LCALL L0C10
  1C07  8006      SJMP L1C0F
L1C09:
  1C09  755a01    MOV 5Ah,#01h
  1C0C  1208e3    LCALL L08E3
L1C0F:
  1C0F  900362    MOV DPTR,#0362h
  1C12  e0        MOVX A,@DPTR
  1C13  f546      MOV 46h,A
L1C15:
  1C15  12052e    LCALL L052E
L1C18:
  1C18  301152    JNB 22h.1{b11},L1C6D
  1C1B  d205      SETB 20h.5{b05}
  1C1D  90035f    MOV DPTR,#035Fh
  1C20  e0        MOVX A,@DPTR
  1C21  f542      MOV 42h,A
  1C23  e546      MOV A,46h
  1C25  900361    MOV DPTR,#0361h
  1C28  f0        MOVX @DPTR,A
  1C29  753300    MOV 33h,#00h
  1C2C  c202      CLR 20h.2{b02}
  1C2E  755a00    MOV 5Ah,#00h
  1C31  1208e3    LCALL L08E3
  1C34  d202      SETB 20h.2{b02}
  1C36  e546      MOV A,46h
  1C38  900362    MOV DPTR,#0362h
  1C3B  f0        MOVX @DPTR,A
  1C3C  90035f    MOV DPTR,#035Fh
  1C3F  e0        MOVX A,@DPTR
  1C40  f542      MOV 42h,A
  1C42  854247    MOV 47h,42h
  1C45  900361    MOV DPTR,#0361h
  1C48  e0        MOVX A,@DPTR
  1C49  f546      MOV 46h,A
  1C4B  a213      MOV C,22h.3{b13}
  1C4D  8215      ANL C,22h.5{b15}
  1C4F  7214      ORL C,22h.4{b14}
  1C51  5005      JNC L1C58
  1C53  120c10    LCALL L0C10
  1C56  8006      SJMP L1C5E
L1C58:
  1C58  755a01    MOV 5Ah,#01h
  1C5B  1208e3    LCALL L08E3
L1C5E:
  1C5E  900362    MOV DPTR,#0362h
  1C61  e0        MOVX A,@DPTR
  1C62  f546      MOV 46h,A
  1C64  12052e    LCALL L052E
  1C67  754005    MOV 40h,#05h
  1C6A  7541dc    MOV 41h,#DCh
L1C6D:
  1C6D  a294      MOV C,P1.4
  1C6F  b3        CPL C
  1C70  5008      JNC L1C7A
  1C72  900000    MOV DPTR,#0000h
  1C75  e0        MOVX A,@DPTR
  1C76  5480      ANL A,#80h
  1C78  6002      JZ L1C7C
L1C7A:
  1C7A  800a      SJMP L1C86
L1C7C:
  1C7C  900000    MOV DPTR,#0000h
  1C7F  e0        MOVX A,@DPTR
  1C80  4480      ORL A,#80h
  1C82  900000    MOV DPTR,#0000h
  1C85  f0        MOVX @DPTR,A
L1C86:
  1C86  309408    JNB P1.4,L1C91
  1C89  900000    MOV DPTR,#0000h
  1C8C  e0        MOVX A,@DPTR
  1C8D  5480      ANL A,#80h
  1C8F  7002      JNZ L1C93
L1C91:
  1C91  800a      SJMP L1C9D
L1C93:
  1C93  900000    MOV DPTR,#0000h
  1C96  e0        MOVX A,@DPTR
  1C97  547f      ANL A,#7Fh
  1C99  900000    MOV DPTR,#0000h
  1C9C  f0        MOVX @DPTR,A
L1C9D:
  1C9D  a20b      MOV C,21h.3{b0B}
  1C9F  720a      ORL C,21h.2{b0A}
  1CA1  500c      JNC L1CAF
  1CA3  900000    MOV DPTR,#0000h
  1CA6  e0        MOVX A,@DPTR
  1CA7  4420      ORL A,#20h
  1CA9  900000    MOV DPTR,#0000h
  1CAC  f0        MOVX @DPTR,A
  1CAD  800a      SJMP L1CB9
L1CAF:
  1CAF  900000    MOV DPTR,#0000h
  1CB2  e0        MOVX A,@DPTR
  1CB3  54df      ANL A,#DFh
  1CB5  900000    MOV DPTR,#0000h
  1CB8  f0        MOVX @DPTR,A
L1CB9:
  1CB9  309511    JNB P1.5,L1CCD
  1CBC  75a882    MOV IE,#82h
  1CBF  c211      CLR 22h.1{b11}
  1CC1  900358    MOV DPTR,#0358h
  1CC4  74ff      MOV A,#FFh
  1CC6  f0        MOVX @DPTR,A
  1CC7  a3        INC DPTR
  1CC8  74ff      MOV A,#FFh
  1CCA  f0        MOVX @DPTR,A
  1CCB  8003      SJMP L1CD0
L1CCD:
  1CCD  75a892    MOV IE,#92h
L1CD0:
  1CD0  20b230    JB INT0,L1D03
  1CD3  753800    MOV 38h,#00h
  1CD6  753700    MOV 37h,#00h
L1CD9:
  1CD9  ae37      MOV R6,37h
  1CDB  af38      MOV R7,38h
  1CDD  748b      MOV A,#8Bh
  1CDF  be001e    CJNE R6,#00h,L1D00
  1CE2  9f        SUBB A,R7
  1CE3  401b      JC L1D00
  1CE5  900363    MOV DPTR,#0363h
  1CE8  12000e    LCALL L000E
  1CEB  74ff      MOV A,#FFh
  1CED  f0        MOVX @DPTR,A
  1CEE  a3        INC DPTR
  1CEF  74ff      MOV A,#FFh
  1CF1  f0        MOVX @DPTR,A
  1CF2  7838      MOV R0,#38h
  1CF4  7401      MOV A,#01h
  1CF6  26        ADD A,@R0
  1CF7  f6        MOV @R0,A
  1CF8  5004      JNC L1CFE
  1CFA  18        DEC R0
  1CFB  e4        CLR A
  1CFC  36        ADDC A,@R0
  1CFD  f6        MOV @R0,A
L1CFE:
  1CFE  50d9      JNC L1CD9
L1D00:
  1D00  12052e    LCALL L052E
L1D03:
  1D03  20b331    JB INT1,L1D37
  1D06  753800    MOV 38h,#00h
  1D09  753700    MOV 37h,#00h
L1D0C:
  1D0C  ae37      MOV R6,37h
  1D0E  af38      MOV R7,38h
  1D10  748b      MOV A,#8Bh
  1D12  be001f    CJNE R6,#00h,L1D34
  1D15  9f        SUBB A,R7
  1D16  401c      JC L1D34
  1D18  900363    MOV DPTR,#0363h
  1D1B  12000e    LCALL L000E
  1D1E  7400      MOV A,#00h
  1D20  f8        MOV R0,A
  1D21  e4        CLR A
  1D22  f0        MOVX @DPTR,A
  1D23  e8        MOV A,R0
  1D24  a3        INC DPTR
  1D25  f0        MOVX @DPTR,A
  1D26  7838      MOV R0,#38h
  1D28  7401      MOV A,#01h
  1D2A  26        ADD A,@R0
  1D2B  f6        MOV @R0,A
  1D2C  5004      JNC L1D32
  1D2E  18        DEC R0
  1D2F  e4        CLR A
  1D30  36        ADDC A,@R0
  1D31  f6        MOV @R0,A
L1D32:
  1D32  50d8      JNC L1D0C
L1D34:
  1D34  12052e    LCALL L052E
L1D37:
  1D37  752b2f    MOV 2Bh,#2Fh
  1D3A  752cff    MOV 2Ch,#FFh
  1D3D  200603    JB 20h.6{b06},L1D43
  1D40  021e00    LJMP L1E00
L1D43:
  1D43  900017    MOV DPTR,#0017h
  1D46  e0        MOVX A,@DPTR
  1D47  fe        MOV R6,A
  1D48  a3        INC DPTR
  1D49  e0        MOVX A,@DPTR
  1D4A  ff        MOV R7,A
  1D4B  74ff      MOV A,#FFh
  1D4D  6206      XRL 06h,A
  1D4F  6207      XRL 07h,A
  1D51  900005    MOV DPTR,#0005h
  1D54  e0        MOVX A,@DPTR
  1D55  fc        MOV R4,A
  1D56  a3        INC DPTR
  1D57  e0        MOVX A,@DPTR
  1D58  fd        MOV R5,A
  1D59  ef        MOV A,R7
  1D5A  6d        XRL A,R5
  1D5B  7004      JNZ L1D61
  1D5D  ee        MOV A,R6
  1D5E  6c        XRL A,R4
  1D5F  6007      JZ L1D68
L1D61:
  1D61  900005    MOV DPTR,#0005h
  1D64  e4        CLR A
  1D65  f0        MOVX @DPTR,A
  1D66  a3        INC DPTR
  1D67  f0        MOVX @DPTR,A
L1D68:
  1D68  90000d    MOV DPTR,#000Dh
  1D6B  e0        MOVX A,@DPTR
  1D6C  fe        MOV R6,A
  1D6D  a3        INC DPTR
  1D6E  e0        MOVX A,@DPTR
  1D6F  ff        MOV R7,A
  1D70  74ff      MOV A,#FFh
  1D72  6206      XRL 06h,A
  1D74  6207      XRL 07h,A
  1D76  900003    MOV DPTR,#0003h
  1D79  e0        MOVX A,@DPTR
  1D7A  fc        MOV R4,A
  1D7B  a3        INC DPTR
  1D7C  e0        MOVX A,@DPTR
  1D7D  fd        MOV R5,A
  1D7E  ef        MOV A,R7
  1D7F  6d        XRL A,R5
  1D80  7004      JNZ L1D86
  1D82  ee        MOV A,R6
  1D83  6c        XRL A,R4
  1D84  6007      JZ L1D8D
L1D86:
  1D86  900003    MOV DPTR,#0003h
  1D89  e4        CLR A
  1D8A  f0        MOVX @DPTR,A
  1D8B  a3        INC DPTR
  1D8C  f0        MOVX @DPTR,A
L1D8D:
  1D8D  900013    MOV DPTR,#0013h
  1D90  e0        MOVX A,@DPTR
  1D91  fe        MOV R6,A
  1D92  a3        INC DPTR
  1D93  e0        MOVX A,@DPTR
  1D94  ff        MOV R7,A
  1D95  74ff      MOV A,#FFh
  1D97  6206      XRL 06h,A
  1D99  6207      XRL 07h,A
  1D9B  90000f    MOV DPTR,#000Fh
  1D9E  e0        MOVX A,@DPTR
  1D9F  fc        MOV R4,A
  1DA0  a3        INC DPTR
  1DA1  e0        MOVX A,@DPTR
  1DA2  fd        MOV R5,A
  1DA3  ef        MOV A,R7
  1DA4  6d        XRL A,R5
  1DA5  7004      JNZ L1DAB
  1DA7  ee        MOV A,R6
  1DA8  6c        XRL A,R4
  1DA9  6007      JZ L1DB2
L1DAB:
  1DAB  90000f    MOV DPTR,#000Fh
  1DAE  e4        CLR A
  1DAF  f0        MOVX @DPTR,A
  1DB0  a3        INC DPTR
  1DB1  f0        MOVX @DPTR,A
L1DB2:
  1DB2  90001d    MOV DPTR,#001Dh
  1DB5  e0        MOVX A,@DPTR
  1DB6  fe        MOV R6,A
  1DB7  a3        INC DPTR
  1DB8  e0        MOVX A,@DPTR
  1DB9  ff        MOV R7,A
  1DBA  74ff      MOV A,#FFh
  1DBC  6206      XRL 06h,A
  1DBE  6207      XRL 07h,A
  1DC0  900019    MOV DPTR,#0019h
  1DC3  e0        MOVX A,@DPTR
  1DC4  fc        MOV R4,A
  1DC5  a3        INC DPTR
  1DC6  e0        MOVX A,@DPTR
  1DC7  fd        MOV R5,A
  1DC8  ef        MOV A,R7
  1DC9  6d        XRL A,R5
  1DCA  7004      JNZ L1DD0
  1DCC  ee        MOV A,R6
  1DCD  6c        XRL A,R4
  1DCE  6007      JZ L1DD7
L1DD0:
  1DD0  900019    MOV DPTR,#0019h
  1DD3  e4        CLR A
  1DD4  f0        MOVX @DPTR,A
  1DD5  a3        INC DPTR
  1DD6  f0        MOVX @DPTR,A
L1DD7:
  1DD7  900023    MOV DPTR,#0023h
  1DDA  e0        MOVX A,@DPTR
  1DDB  fe        MOV R6,A
  1DDC  a3        INC DPTR
  1DDD  e0        MOVX A,@DPTR
  1DDE  ff        MOV R7,A
  1DDF  74ff      MOV A,#FFh
  1DE1  6206      XRL 06h,A
  1DE3  6207      XRL 07h,A
  1DE5  90001f    MOV DPTR,#001Fh
  1DE8  e0        MOVX A,@DPTR
  1DE9  fc        MOV R4,A
  1DEA  a3        INC DPTR
  1DEB  e0        MOVX A,@DPTR
  1DEC  fd        MOV R5,A
  1DED  ef        MOV A,R7
  1DEE  6d        XRL A,R5
  1DEF  7004      JNZ L1DF5
  1DF1  ee        MOV A,R6
  1DF2  6c        XRL A,R4
  1DF3  6007      JZ L1DFC
L1DF5:
  1DF5  90001f    MOV DPTR,#001Fh
  1DF8  e4        CLR A
  1DF9  f0        MOVX @DPTR,A
  1DFA  a3        INC DPTR
  1DFB  f0        MOVX @DPTR,A
L1DFC:
  1DFC  d212      SETB 22h.2{b12}
  1DFE  c206      CLR 20h.6{b06}
L1E00:
  1E00  e548      MOV A,48h
  1E02  7003      JNZ L1E07
  1E04  021f03    LJMP L1F03
L1E07:
  1E07  c211      CLR 22h.1{b11}
  1E09  e548      MOV A,48h
  1E0B  b4012e    CJNE A,#01h,L1E3C
  1E0E  753600    MOV 36h,#00h
  1E11  753500    MOV 35h,#00h
L1E14:
  1E14  ae35      MOV R6,35h
  1E16  af36      MOV R7,36h
  1E18  748b      MOV A,#8Bh
  1E1A  be001f    CJNE R6,#00h,L1E3C
  1E1D  9f        SUBB A,R7
  1E1E  401c      JC L1E3C
  1E20  900363    MOV DPTR,#0363h
  1E23  12000e    LCALL L000E
  1E26  7400      MOV A,#00h
  1E28  f8        MOV R0,A
  1E29  e4        CLR A
  1E2A  f0        MOVX @DPTR,A
  1E2B  e8        MOV A,R0
  1E2C  a3        INC DPTR
  1E2D  f0        MOVX @DPTR,A
  1E2E  7836      MOV R0,#36h
  1E30  7401      MOV A,#01h
  1E32  26        ADD A,@R0
  1E33  f6        MOV @R0,A
  1E34  5004      JNC L1E3A
  1E36  18        DEC R0
  1E37  e4        CLR A
  1E38  36        ADDC A,@R0
  1E39  f6        MOV @R0,A
L1E3A:
  1E3A  50d8      JNC L1E14
L1E3C:
  1E3C  e548      MOV A,48h
  1E3E  b40230    CJNE A,#02h,L1E71
  1E41  753600    MOV 36h,#00h
  1E44  753500    MOV 35h,#00h
L1E47:
  1E47  ae35      MOV R6,35h
  1E49  af36      MOV R7,36h
  1E4B  748b      MOV A,#8Bh
  1E4D  be001e    CJNE R6,#00h,L1E6E
  1E50  9f        SUBB A,R7
  1E51  401b      JC L1E6E
  1E53  900363    MOV DPTR,#0363h
  1E56  12000e    LCALL L000E
  1E59  74ff      MOV A,#FFh
  1E5B  f0        MOVX @DPTR,A
  1E5C  a3        INC DPTR
  1E5D  74ff      MOV A,#FFh
  1E5F  f0        MOVX @DPTR,A
  1E60  7836      MOV R0,#36h
  1E62  7401      MOV A,#01h
  1E64  26        ADD A,@R0
  1E65  f6        MOV @R0,A
  1E66  5004      JNC L1E6C
  1E68  18        DEC R0
  1E69  e4        CLR A
  1E6A  36        ADDC A,@R0
  1E6B  f6        MOV @R0,A
L1E6C:
  1E6C  50d9      JNC L1E47
L1E6E:
  1E6E  021efd    LJMP L1EFD
L1E71:
  1E71  e548      MOV A,48h
  1E73  b40341    CJNE A,#03h,L1EB7
  1E76  753600    MOV 36h,#00h
  1E79  753500    MOV 35h,#00h
L1E7C:
  1E7C  ae35      MOV R6,35h
  1E7E  af36      MOV R7,36h
  1E80  748b      MOV A,#8Bh
  1E82  be0030    CJNE R6,#00h,L1EB5
  1E85  9f        SUBB A,R7
  1E86  402d      JC L1EB5
  1E88  900363    MOV DPTR,#0363h
  1E8B  12000e    LCALL L000E
  1E8E  74aa      MOV A,#AAh
  1E90  f0        MOVX @DPTR,A
  1E91  a3        INC DPTR
  1E92  74aa      MOV A,#AAh
  1E94  f0        MOVX @DPTR,A
  1E95  0f        INC R7
  1E96  bf0001    CJNE R7,#00h,L1E9A
  1E99  0e        INC R6
L1E9A:
  1E9A  900363    MOV DPTR,#0363h
  1E9D  12000e    LCALL L000E
  1EA0  7455      MOV A,#55h
  1EA2  f0        MOVX @DPTR,A
  1EA3  a3        INC DPTR
  1EA4  7455      MOV A,#55h
  1EA6  f0        MOVX @DPTR,A
  1EA7  7836      MOV R0,#36h
  1EA9  7402      MOV A,#02h
  1EAB  26        ADD A,@R0
  1EAC  f6        MOV @R0,A
  1EAD  5004      JNC L1EB3
  1EAF  18        DEC R0
  1EB0  e4        CLR A
  1EB1  36        ADDC A,@R0
  1EB2  f6        MOV @R0,A
L1EB3:
  1EB3  50c7      JNC L1E7C
L1EB5:
  1EB5  8046      SJMP L1EFD
L1EB7:
  1EB7  e548      MOV A,48h
  1EB9  b40441    CJNE A,#04h,L1EFD
  1EBC  753600    MOV 36h,#00h
  1EBF  753500    MOV 35h,#00h
L1EC2:
  1EC2  ae35      MOV R6,35h
  1EC4  af36      MOV R7,36h
  1EC6  748b      MOV A,#8Bh
  1EC8  be0030    CJNE R6,#00h,L1EFB
  1ECB  9f        SUBB A,R7
  1ECC  402d      JC L1EFB
  1ECE  900363    MOV DPTR,#0363h
  1ED1  12000e    LCALL L000E
  1ED4  7455      MOV A,#55h
  1ED6  f0        MOVX @DPTR,A
  1ED7  a3        INC DPTR
  1ED8  7455      MOV A,#55h
  1EDA  f0        MOVX @DPTR,A
  1EDB  0f        INC R7
  1EDC  bf0001    CJNE R7,#00h,L1EE0
  1EDF  0e        INC R6
L1EE0:
  1EE0  900363    MOV DPTR,#0363h
  1EE3  12000e    LCALL L000E
  1EE6  74aa      MOV A,#AAh
  1EE8  f0        MOVX @DPTR,A
  1EE9  a3        INC DPTR
  1EEA  74aa      MOV A,#AAh
  1EEC  f0        MOVX @DPTR,A
  1EED  7836      MOV R0,#36h
  1EEF  7402      MOV A,#02h
  1EF1  26        ADD A,@R0
  1EF2  f6        MOV @R0,A
  1EF3  5004      JNC L1EF9
  1EF5  18        DEC R0
  1EF6  e4        CLR A
  1EF7  36        ADDC A,@R0
  1EF8  f6        MOV @R0,A
L1EF9:
  1EF9  50c7      JNC L1EC2
L1EFB:
  1EFB  8000      SJMP L1EFD
L1EFD:
  1EFD  12052e    LCALL L052E
  1F00  754800    MOV 48h,#00h
L1F03:
  1F03  802f      SJMP L1F34
  1F05  db AE 37 AF 38 74 8B BE 00 1F 9F 40 1C 90 03 63 12  ; .7.8t.....@...c.
  1F15  db 00 0E 74 00 F8 E4 F0 E8 A3 F0 78 38 74 01 26 F6  ; ..t.......x8t.&.
  1F25  db 50 04 18 E4 36 F6 50 D8 C2 11 D2 06 12 05 2E  ; P...6.P........
L1F34:
  1F34  02137e    LJMP L137E
  1F37  db 1F 1E 1D 1C 1B 1A 19 17 16 15 14 13 12 11 0F 0E  ; ................
  1F47  db 0D 0C 0B 0A 09 07 06 05 04 03 02 01 3F 3E 3D 3C  ; ............?>=<
  1F57  db 3B 3A 39 37 36 35 34 33 32 31 2F 2E 2D 2C 2B 2A  ; ;:97654321/.-,+*
  1F67  db 29 27 26 25 24 23 22 21 5F 5E 5D 5C 5B 5A 59 57  ; )'&%$#"!_^]\[ZYW
  1F77  db 56 55 54 53 52 51 4F 4E 4D 4C 4B 4A 49 47 46 45  ; VUTSRQONMLKJIGFE
  1F87  db 44 43 42 41 7F 7E 7D 7C 7B 7A 79 77 76 75 74 73  ; DCBA.~}|{zywvuts
  1F97  db 72 71 6F 6E 6D 6C 6B 6A 69 67 66 65 64 63 62 61  ; rqonmlkjigfedcba
  1FA7  db 61 62 63 64 65 66 67 69 6A 6B 6C 6D 6E 6F 71 72  ; abcdefgijklmnoqr
  1FB7  db 73 74 75 76 77 79 7A 7B 7C 7D 7E 7F 41 42 43 44  ; stuvwyz{|}~.ABCD
  1FC7  db 45 46 47 49 4A 4B 4C 4D 4E 4F 51 52 53 54 55 56  ; EFGIJKLMNOQRSTUV
  1FD7  db 57 59 5A 5B 5C 5D 5E 5F 21 22 23 24 25 26 27 29  ; WYZ[\]^_!"#$%&')
  1FE7  db 2A 2B 2C 2D 2E 2F 31 32 33 34 35 36 37 39 3A 3B  ; *+,-./12345679:;
  1FF7  db 3C 3D 3E 3F 01 02 03 04 05 06 07 09 0A 0B 0C 0D  ; <=>?............
  2007  db 0E 0F 11 12 13 14 15 16 17 19 1A 1B 1C 1D 1E 1F  ; ................
  2017  db 80 00 40 00 20 00 10 00 08 00 04 00 02 00 01 00  ; ..@. ...........
  2027  db 00 80 00 40 00 20 00 10 00 08 00 04 00 02 00 01  ; ...@. ..........
  2037  db 00 01 00 02 00 04 00 08 00 10 00 20 00 40 00 80  ; ........... .@..
  2047  db 01 00 02 00 04 00 08 00 10 00 20 00 40 00 80 00  ; .......... .@...
  2057  db 0F 60 61 FF 03 00 00 00 00 00 00 00 00 00 00 00  ; .`a.............
  2067  db 00 00 00 00 04 00 06 06 06 06 06 06 06 06 06 00  ; ................
  2077  db 00 06 06 00 04 00 09 09 09 09 09 00 00 00 00 00  ; ................
  2087  db 00 00 00 00 06 00 00 00 00 00 00 00 00 00 12 3F  ; ...............?
  2097  db 12 3F 12 00 08 00 00 00 00 18 18 00 3F 58 98 18  ; .?..........?X..
  20A7  db 18 24 42 00 08 00 00 18 18 00 3C 5A 99 98 18 18  ; .$B.......<Z....
  20B7  db 24 42 C3 00 01 00 00 00 00 00 00 00 00 00 00 00  ; $B..............
  20C7  db 00 00 00 00 04 00 06 06 06 0C 00 00 00 00 00 00  ; ................
  20D7  db 00 00 00 00 04 00 01 03 06 0C 0C 0C 0C 0C 0C 0C  ; ................
  20E7  db 06 03 01 00 04 00 08 0C 06 03 03 03 03 03 03 03  ; ................
  20F7  db 06 0C 08 00 05 00 00 00 00 00 00 00 00 15 0E 1F  ; ................
  2107  db 0E 15 00 00 04 00 00 00 00 00 00 00 02 07 02 00  ; ................
  2117  db 00 00 00 00 04 00 00 00 00 00 00 00 00 00 00 06  ; ................
  2127  db 06 06 0C 00 04 00 00 00 00 00 00 0F 0F 00 00 00  ; ................
  2137  db 00 00 00 00 02 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2147  db 00 03 03 00 04 00 00 01 01 03 03 06 06 0C 0C 08  ; ................
  2157  db 08 00 00 00 06 00 1E 3F 33 33 33 33 33 33 33 33  ; .......?33333333
  2167  db 33 3F 1E 00 04 00 03 07 0F 0F 03 03 03 03 03 03  ; 3?..............
  2177  db 03 03 03 00 07 00 3E 7F 63 03 03 07 0E 1C 38 70  ; ......>.c.....8p
  2187  db 60 7F 7F 00 07 00 3E 7F 63 03 03 1E 1E 03 03 03  ; `.....>.c.......
  2197  db 63 7F 3E 00 07 00 63 63 63 63 63 7F 7F 03 03 03  ; c.>...ccccc.....
  21A7  db 03 03 03 00 06 00 3F 3F 30 30 30 3E 3F 03 03 03  ; ......??000>?...
  21B7  db 33 3F 1E 00 06 00 1E 3F 33 30 30 3E 3F 33 33 33  ; 3?.....?300>?333
  21C7  db 33 3F 1E 00 06 00 3F 3F 03 03 03 06 0C 18 30 30  ; 3?....??......00
  21D7  db 30 30 30 00 06 00 1E 3F 33 33 33 1E 1E 33 33 33  ; 000....?333..333
  21E7  db 33 3F 1E 00 06 00 1E 3F 33 33 33 3F 1F 03 03 03  ; 3?.....?333?....
  21F7  db 33 3F 1E 00 04 00 00 00 00 00 06 06 00 00 06 06  ; 3?..............
  2207  db 00 00 00 00 04 00 00 00 00 00 06 06 00 00 06 06  ; ................
  2217  db 0C 00 00 00 04 00 00 00 00 01 02 04 08 08 04 02  ; ................
  2227  db 01 00 00 00 04 00 00 00 00 00 0F 0F 00 00 0F 0F  ; ................
  2237  db 00 00 00 00 04 00 00 00 00 08 04 02 01 01 02 04  ; ................
  2247  db 08 00 00 00 06 00 1E 3F 33 03 03 03 06 0C 0C 0C  ; .......?3.......
  2257  db 00 0C 0C 00 07 00 00 00 00 00 00 00 77 00 00 00  ; ............w...
  2267  db 00 00 00 00 07 00 3E 7F 63 63 63 7F 7F 63 63 63  ; ......>.ccc..ccc
  2277  db 63 63 63 00 07 00 7E 7F 63 63 63 7E 7E 63 63 63  ; ccc...~.ccc~~ccc
  2287  db 63 7F 7E 00 07 00 3E 7F 63 60 60 60 60 60 60 60  ; c.~...>.c```````
  2297  db 63 7F 3E 00 07 00 7E 7F 63 63 63 63 63 63 63 63  ; c.>...~.cccccccc
  22A7  db 63 7F 7E 00 05 00 1F 1F 18 18 18 1E 1E 18 18 18  ; c.~.............
  22B7  db 18 1F 1F 00 05 00 1F 1F 18 18 18 1E 1E 18 18 18  ; ................
  22C7  db 18 18 18 00 07 00 3E 7F 63 60 60 6F 6F 63 63 63  ; ......>.c``ooccc
  22D7  db 63 7F 3E 00 07 00 63 63 63 63 63 7F 7F 63 63 63  ; c.>...ccccc..ccc
  22E7  db 63 63 63 00 02 00 03 03 03 03 03 03 03 03 03 03  ; ccc.............
  22F7  db 03 03 03 00 06 00 03 03 03 03 03 03 03 03 03 03  ; ................
  2307  db 33 3F 1E 00 07 00 63 63 66 66 6C 7C 78 7C 6C 66  ; 3?....ccffl|x|lf
  2317  db 66 63 63 00 05 00 18 18 18 18 18 18 18 18 18 18  ; fcc.............
  2327  db 18 1F 1F 00 08 00 81 C3 E7 FF FF DB C3 C3 C3 C3  ; ................
  2337  db C3 C3 C3 00 07 00 63 63 73 73 7B 7B 6F 6F 67 67  ; ......ccss{{oogg
  2347  db 63 63 63 00 07 00 3E 7F 63 63 63 63 63 63 63 63  ; ccc...>.cccccccc
  2357  db 63 7F 3E 00 07 00 7E 7F 63 63 63 7F 7E 60 60 60  ; c.>...~.ccc.~```
  2367  db 60 60 60 00 07 00 3E 7F 63 63 63 63 63 63 63 6B  ; ```...>.ccccccck
  2377  db 65 7A 3D 00 07 00 7E 7F 63 63 63 7F 7E 6C 6C 66  ; ez=...~.ccc.~llf
  2387  db 66 63 63 00 07 00 3E 7F 63 60 60 7E 3F 03 03 03  ; fcc...>.c``~?...
  2397  db 63 7F 3E 00 06 00 3F 3F 0C 0C 0C 0C 0C 0C 0C 0C  ; c.>...??........
  23A7  db 0C 0C 0C 00 07 00 63 63 63 63 63 63 63 63 63 63  ; ......cccccccccc
  23B7  db 63 7F 3E 00 08 00 C3 C3 C3 C3 C3 C3 C3 66 66 3C  ; c.>..........ff<
  23C7  db 3C 18 18 00 08 00 C3 C3 C3 C3 C3 DB DB DB FF FF  ; <...............
  23D7  db E7 C3 81 00 08 00 C3 C3 C3 E7 7E 3C 18 3C 7E E7  ; ..........~<.<~.
  23E7  db C3 C3 C3 00 08 00 C3 C3 66 66 3C 3C 18 18 18 18  ; ........ff<<....
  23F7  db 18 18 18 00 07 00 7F 7F 06 06 0C 0C 18 18 30 30  ; ..............00
  2407  db 60 7F 7F 00 07 00 63 63 00 3E 7F 63 63 7F 7F 63  ; `.....cc.>.cc..c
  2417  db 63 63 63 00 07 00 63 63 00 3E 7F 63 63 63 63 63  ; ccc...cc.>.ccccc
  2427  db 63 7F 3E 00 07 00 63 63 00 63 63 63 63 63 63 63  ; c.>...cc.ccccccc
  2437  db 63 7F 3E 00 07 00 3E 7F 63 6E 6E 63 63 63 63 6F  ; c.>...>.cnncccco
  2447  db 6E 60 60 00 07 00 3E 7F 63 6E 6E 63 63 63 63 6F  ; n``...>.cnncccco
  2457  db 6E 60 60 00 04 00 00 00 00 00 00 00 00 00 00 00  ; n``.............
  2467  db 00 00 00 00 08 7F 40 58 58 58 58 58 58 58 58 5D  ; ......@XXXXXXXX]
  2477  db 4F 47 40 7F 05 1E 02 1A 1A 1A 1A 1A 1A 1A 1A 1A  ; OG@.............
  2487  db 12 02 02 1E 06 1F 10 10 13 17 16 16 17 13 10 10  ; ................
  2497  db 17 13 10 1F 06 3E 02 02 32 3A 02 02 32 3A 1A 1A  ; .....>..2:..2:..
  24A7  db 3A 32 02 3E 08 3F 7F 7D 7C 7C 7E 5E 60 5E 7E 7C  ; :2.>.?.}||~^`^~|
  24B7  db 7C 7D 7F 3F 08 FE FF FF FF 7F 3F 1F 01 1F 3F 7F  ; |}.?......?...?.
  24C7  db FF FF FF FE 08 03 0F 1D 3C 3C 7E 5E 60 5E 7E 3C  ; ........<<~^`^~<
  24D7  db 3C 1D 0F 03 08 E0 F8 FC FE 7E 3F 1F 01 1F 3F 7E  ; <........~?...?~
  24E7  db FE FC F8 E0 08 03 0C 1B 36 35 60 77 77 73 7B 3D  ; ........65`wws{=
  24F7  db 3B 18 0E 02 08 E0 18 EC 3E C6 FF FF FF FF FF FE  ; ;.......>.......
  2507  db FE FC F8 E0 08 00 00 18 18 00 3C 5A 99 98 18 18  ; ..........<Z....
  2517  db 24 42 C3 00 08 00 00 00 00 18 18 00 FC 1A 19 18  ; $B..............
  2527  db 18 24 42 00 08 7F FF 00 F8 FC CC CC FD F9 C0 C0  ; .$B.............
  2537  db C0 00 FF 7F 08 FF FF 00 03 03 63 63 FB FB 63 63  ; ..........cc..cc
  2547  db 03 00 FF FF 05 1C 1E 00 1C 1E 06 06 1E 1C 0C 06  ; ................
  2557  db 06 00 1E 1C 08 07 19 21 43 43 83 83 87 87 8E 4C  ; .......!CC.....L
  2567  db 50 20 18 07 07 60 18 04 42 42 41 41 61 61 71 32  ; P ...`..BBAAaaq2
  2577  db 0A 04 18 60 08 07 18 20 5E 46 86 87 87 87 86 4C  ; ...`... ^F.....L
  2587  db 58 20 18 07 07 60 18 04 3A 32 61 41 41 41 61 36  ; X ...`..:2aAAAa6
  2597  db 1A 04 18 60 08 01 03 03 01 7F FF 7F 07 0B 1D 3A  ; ...`...........:
  25A7  db 37 0E 1C 18 05 10 18 18 10 1C 1E 1F 1F 1B 16 06  ; 7...............
  25B7  db 00 08 14 08 07 03 0C 18 38 27 47 47 78 78 78 27  ; ........8'GGxxx'
  25C7  db 27 17 0C 03 08 C0 F0 E8 E4 1C 1E 1E E2 E2 E2 1C  ; '...............
  25D7  db 1C 18 F0 C0 04 00 00 00 00 00 00 00 00 00 00 00  ; ................
  25E7  db 00 00 00 00 06 00 1E 3F 33 33 33 3F 1E 00 00 00  ; .......?333?....
  25F7  db 00 00 00 00 07 00 00 00 00 10 28 28 10 2A 46 46  ; ..........((.*FF
  2607  db 39 00 00 00 04 00 00 00 00 00 00 00 00 00 00 00  ; 9...............
  2617  db 00 00 00 00 04 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2627  db 00 00 00 00 04 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2637  db 00 00 00 00 04 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2647  db 00 00 00 00 04 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2657  db 00 00 00 00 07 60 FF FF 03 00 00 00 00 00 00 00  ; .....`..........
  2667  db 02 03 03 03 03 03 00 03 04 03 06 0C 00 00 00 00  ; ................
  2677  db 05 0A 0A 1F 0A 1F 0A 0A 06 0C 00 1E 2D 0C 0C 12  ; ............-...
  2687  db 06 00 0C 00 3E 0D 0C 12 06 00 00 00 00 00 00 00  ; ....>...........
  2697  db 03 03 03 06 00 00 00 00 03 01 03 06 06 06 03 01  ; ................
  26A7  db 03 04 06 03 03 03 06 04 05 04 15 0E 15 0E 15 04  ; ................
  26B7  db 06 00 0C 0C 3F 0C 0C 00 03 00 00 00 00 03 03 06  ; ....?...........
  26C7  db 02 00 00 00 03 00 00 00 02 00 00 00 00 00 03 03  ; ................
  26D7  db 04 00 01 03 06 0C 08 00 05 0E 1B 1B 1B 1B 1B 0E  ; ................
  26E7  db 04 03 07 0F 03 03 03 03 05 0E 13 03 06 0C 18 1F  ; ................
  26F7  db 05 0E 1B 03 0E 03 1B 0E 06 36 36 36 3F 06 06 06  ; .........666?...
  2707  db 06 3F 30 30 3E 03 33 1E 06 0C 18 30 3E 33 33 1E  ; .?00>.3....0>33.
  2717  db 06 3F 33 03 06 0C 18 18 06 1E 33 33 1E 33 33 1E  ; .?3.......33.33.
  2727  db 06 1E 33 33 1F 03 06 0C 04 00 06 06 00 06 06 00  ; ..33............
  2737  db 04 00 00 00 06 00 06 0C 04 0F 0C 0C 0C 0C 0C 0F  ; ................
  2747  db 04 00 00 0F 00 0F 00 00 04 0F 03 03 03 03 03 0F  ; ................
  2757  db 06 1E 33 03 06 0C 00 0C 05 00 00 00 1B 00 00 00  ; ..3.............
  2767  db 06 0C 1E 33 33 3F 33 33 06 3E 33 33 3E 33 33 3E  ; ...33?33.>33>33>
  2777  db 06 1E 33 30 30 30 33 1E 06 3E 33 33 33 33 33 3E  ; ..30003..>33333>
  2787  db 05 1F 18 18 1F 18 18 1F 05 1F 18 18 1E 18 18 18  ; ................
  2797  db 06 1E 33 30 37 33 33 1E 06 33 33 33 3F 33 33 33  ; ..30733..333?333
  27A7  db 02 03 03 03 03 03 03 03 04 0F 03 03 03 03 0B 06  ; ................
  27B7  db 06 33 36 3C 38 3C 36 33 05 18 18 18 18 18 18 1F  ; .36<8<63........
  27C7  db 07 41 63 77 7F 6B 63 63 06 33 33 3B 3F 37 33 33  ; .Acw.kcc.33;?733
  27D7  db 06 1E 33 33 33 33 33 1E 06 3E 33 33 3E 30 30 30  ; ..33333..>33>000
  27E7  db 06 1E 33 33 33 35 32 1D 06 3E 33 33 3E 3C 36 33  ; ..33352..>33><63
  27F7  db 06 1E 33 30 1E 03 33 1E 06 3F 0C 0C 0C 0C 0C 0C  ; ..30..3..?......
  2807  db 06 33 33 33 33 33 33 1E 07 63 63 63 63 36 1C 08  ; .333333..cccc6..
  2817  db 07 63 63 63 6B 7F 77 63 06 33 33 1E 0C 1E 33 33  ; .ccck.wc.33...33
  2827  db 06 33 33 33 1E 0C 0C 0C 06 3F 03 06 0C 18 30 3F  ; .333.....?....0?
  2837  db 06 33 00 1E 33 3F 33 33 06 33 00 1E 33 33 33 1E  ; .3..3?33.3..333.
  2847  db 06 33 00 33 33 33 33 1E 07 3E 63 6E 63 7E 60 60  ; .3.3333..>cnc~``
  2857  db 05 1F 1F 1F 1F 1F 1F 1F 04 00 00 00 00 00 00 00  ; ................
  2867  db 04 06 09 09 0F 09 09 09 04 0E 09 09 0E 09 09 0E  ; ................
  2877  db 04 06 09 08 08 08 09 06 04 0E 09 09 09 09 09 0E  ; ................
  2887  db 04 0F 08 08 0E 08 08 0F 04 0F 08 08 0E 08 08 08  ; ................
  2897  db 04 06 09 08 0B 09 09 07 04 09 09 09 0F 09 09 09  ; ................
  28A7  db 01 01 01 01 01 01 01 01 04 01 01 01 01 01 09 06  ; ................
  28B7  db 04 09 0A 0C 08 0C 0A 09 03 04 04 04 04 04 04 07  ; ................
  28C7  db 05 11 1B 15 15 11 11 11 05 11 11 19 15 13 11 11  ; ................
  28D7  db 04 06 09 09 09 09 09 06 04 0E 09 09 0E 08 08 08  ; ................
  28E7  db 05 0C 12 12 12 12 16 0F 05 1E 11 11 1E 14 12 11  ; ................
  28F7  db 04 06 09 08 06 01 09 06 03 07 02 02 02 02 02 02  ; ................
  2907  db 04 09 09 09 09 09 09 06 05 11 11 11 11 11 0A 04  ; ................
  2917  db 05 11 11 11 15 15 1F 0A 05 11 11 0A 04 0A 11 11  ; ................
  2927  db 05 11 11 0A 04 04 04 04 04 0F 01 01 02 04 08 0F  ; ................
  2937  db 04 09 00 0F 09 0F 09 09 04 09 00 06 09 09 09 06  ; ................
  2947  db 04 09 00 09 09 09 09 06 05 0E 11 17 11 11 1E 10  ; ................
  2957  db 05 1F 1F 1F 1F 1F 1F 1F 07 60 FF FF 01 00 00 00  ; .........`......
  2967  db 00 00 00 00 01 01 01 01 01 01 00 01 04 03 06 0C  ; ................
  2977  db 00 00 00 00 05 0A 0A 1F 0A 1F 0A 0A 06 0C 00 1E  ; ................
  2987  db 2D 0C 0C 12 06 00 0C 00 3E 0D 0C 0C 05 00 00 00  ; -.......>.......
  2997  db 00 00 00 00 02 01 01 02 00 00 00 00 02 01 02 02  ; ................
  29A7  db 02 02 02 01 02 02 01 01 01 01 01 02 05 04 15 0E  ; ................
  29B7  db 15 0E 15 04 05 00 04 04 1F 04 04 00 02 00 00 00  ; ................
  29C7  db 00 00 01 02 02 00 00 00 03 00 00 00 01 00 00 00  ; ................
  29D7  db 00 00 00 01 03 00 00 01 02 04 00 00 04 06 09 09  ; ................
  29E7  db 09 09 09 06 02 01 03 01 01 01 01 01 04 06 09 01  ; ................
  29F7  db 02 04 08 0F 04 06 09 01 06 01 09 06 04 08 0A 0A  ; ................
  2A07  db 0F 02 02 02 04 0F 08 0E 01 01 09 06 04 06 08 08  ; ................
  2A17  db 0E 09 09 06 04 0F 01 01 02 04 04 04 04 06 09 09  ; ................
  2A27  db 06 09 09 06 04 06 09 09 07 01 01 06 01 00 00 00  ; ................
  2A37  db 01 00 00 01 03 00 00 00 02 00 02 04 04 0E 08 08  ; ................
  2A47  db 08 08 08 0E 04 00 00 00 0F 00 0F 00 04 07 01 01  ; ................
  2A57  db 01 01 01 07 04 06 09 01 02 04 00 04 05 00 00 00  ; ................
  2A67  db 1B 00 00 00 04 06 09 09 0F 09 09 09 04 0E 09 09  ; ................
  2A77  db 0E 09 09 0E 04 06 09 08 08 08 09 06 04 0E 09 09  ; ................
  2A87  db 09 09 09 0E 04 0F 08 08 0E 08 08 0F 04 0F 08 08  ; ................
  2A97  db 0E 08 08 08 04 06 09 08 0B 09 09 07 04 09 09 09  ; ................
  2AA7  db 0F 09 09 09 01 01 01 01 01 01 01 01 04 01 01 01  ; ................
  2AB7  db 01 01 09 06 04 09 0A 0C 08 0C 0A 09 03 04 04 04  ; ................
  2AC7  db 04 04 04 07 05 11 1B 15 15 11 11 11 05 11 11 19  ; ................
  2AD7  db 15 13 11 11 04 06 09 09 09 09 09 06 04 0E 09 09  ; ................
  2AE7  db 0E 08 08 08 05 0C 12 12 12 12 16 0F 05 1E 11 11  ; ................
  2AF7  db 1E 14 12 11 04 06 09 08 06 01 09 06 03 07 02 02  ; ................
  2B07  db 02 02 02 02 04 09 09 09 09 09 09 06 05 11 11 11  ; ................
  2B17  db 11 11 0A 04 05 11 11 11 15 15 1F 0A 05 11 11 0A  ; ................
  2B27  db 04 0A 11 11 05 11 11 0A 04 04 04 04 04 0F 01 03  ; ................
  2B37  db 06 0C 08 0F 04 09 00 0F 09 0F 09 09 04 09 00 06  ; ................
  2B47  db 09 09 09 06 04 09 00 09 09 09 09 06 05 0E 11 17  ; ................
  2B57  db 11 11 1E 10 05 1F 1F 1F 1F 1F 1F 1F 05 00 00 00  ; ................
  2B67  db 00 00 00 00 05 0E 11 01 0F 11 11 0F 04 08 08 0A  ; ................
  2B77  db 0D 09 09 06 04 06 09 08 08 08 09 06 04 01 01 01  ; ................
  2B87  db 0F 09 09 0F 04 06 09 09 0F 08 08 07 04 03 04 04  ; ................
  2B97  db 04 07 04 04 05 0E 11 11 0F 01 11 0E 04 08 08 08  ; ................
  2BA7  db 0F 09 09 09 04 04 00 0C 04 04 04 07 04 01 01 01  ; ................
  2BB7  db 01 09 09 06 04 09 0A 0C 0E 09 09 09 04 08 08 08  ; ................
  2BC7  db 08 08 08 07 05 04 0A 15 15 15 15 15 04 0E 09 09  ; ................
  2BD7  db 09 09 09 09 04 06 09 09 09 09 09 06 04 0E 09 09  ; ................
  2BE7  db 0E 08 08 08 04 07 09 09 07 01 01 01 05 16 09 08  ; ................
  2BF7  db 08 08 08 08 06 1E 33 30 1E 03 33 1E 04 02 02 0F  ; ......30..3.....
  2C07  db 02 02 02 03 04 09 09 09 09 09 09 0F 05 11 11 11  ; ................
  2C17  db 11 11 0A 04 05 11 11 15 15 15 0A 04 05 11 11 0A  ; ................
  2C27  db 04 0A 11 11 04 09 09 09 07 01 09 06 05 1F 01 02  ; ................
  2C37  db 04 08 10 1F 05 11 0E 01 0F 11 11 0F 04 09 00 06  ; ................
  2C47  db 09 09 09 06 04 09 00 09 09 09 09 0F 05 0E 11 1E  ; ................
  2C57  db 11 11 1E 10 05 00 00 00 00 00 00 00 10 60 61 FF  ; .............`a.
  2C67  db 07 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2C77  db 00 07 1C 1C 1C 1C 1C 1C 1C 1C 1C 1C 1C 00 00 1C  ; ................
  2C87  db 1C 1C 07 33 33 33 00 00 00 00 00 00 00 00 00 00  ; ...333..........
  2C97  db 00 00 00 07 00 00 00 00 00 14 14 7F 14 14 7F 14  ; ................
  2CA7  db 14 00 00 00 07 00 00 00 00 00 00 00 18 18 00 1F  ; ................
  2CB7  db 38 58 18 18 24 07 00 00 00 00 0C 0C 00 1E 2D 4D  ; 8X..$.........-M
  2CC7  db 4C 0C 0C 12 21 63 07 7F 7F 7F 7F 7F 7F 7F 7F 7F  ; L...!c..........
  2CD7  db 7F 7F 7F 7F 7F 7F 7F 07 0C 0C 0C 18 00 00 00 00  ; ................
  2CE7  db 00 00 00 00 00 00 00 00 06 03 07 0E 1C 38 38 38  ; .............888
  2CF7  db 38 38 38 38 38 1C 0E 07 03 06 30 38 1C 0E 07 07  ; 88888.....08....
  2D07  db 07 07 07 07 07 07 0E 1C 38 30 07 00 00 00 00 00  ; ........80......
  2D17  db 49 2A 1C 7F 1C 2A 49 00 00 00 00 07 00 00 00 00  ; I*...*I.........
  2D27  db 00 1C 1C 7F 7F 7F 1C 1C 00 00 00 00 05 00 00 00  ; ................
  2D37  db 00 00 00 00 00 00 00 00 07 07 07 0E 1C 07 00 00  ; ................
  2D47  db 00 00 00 00 7F 7F 7F 00 00 00 00 00 00 00 03 00  ; ................
  2D57  db 00 00 00 00 00 00 00 00 00 00 00 00 07 07 07 08  ; ................
  2D67  db 00 00 07 07 0E 0E 1C 1C 38 38 70 70 E0 E0 00 00  ; ........88pp....
  2D77  db 08 3C 7E FF E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 FF 7E  ; .<~............~
  2D87  db 3C 06 07 0F 1F 3F 3F 07 07 07 07 07 07 07 07 07  ; <....??.........
  2D97  db 07 07 08 7E FF FF E7 07 07 0F 1E 3C 78 F0 E0 E0  ; ...~.......<x...
  2DA7  db FF FF FF 08 7E FF FF E7 07 07 3E 3E 3E 07 07 07  ; ....~.....>>>...
  2DB7  db E7 FF FF 7E 08 E0 E0 E0 E0 E7 E7 E7 FF FF FF 07  ; ...~............
  2DC7  db 07 07 07 07 07 08 FF FF FF E0 E0 E0 FE FF FF 07  ; ................
  2DD7  db 07 07 E7 FF FF 7E 08 0E 1E 3C 78 F0 E0 E0 FE FF  ; .....~...<x.....
  2DE7  db FF E7 E7 E7 FF FF 7E 08 FF FF FF 07 07 07 07 07  ; ......~.........
  2DF7  db 0E 1C 38 38 38 38 38 38 08 7E FF FF E7 E7 E7 7E  ; ..888888.~.....~
  2E07  db 3C 7E E7 E7 E7 E7 FF FF 7E 08 7E FF FF E7 E7 E7  ; <~......~.~.....
  2E17  db FF FF 7F 07 07 0F 1E 3C 78 70 07 00 00 00 00 00  ; .......<xp......
  2E27  db 00 00 0C 0C 00 00 0C 0C 00 00 00 07 00 00 00 00  ; ................
  2E37  db 00 00 00 0C 0C 00 00 0C 0C 18 00 00 07 00 00 00  ; ................
  2E47  db 03 06 0C 18 30 60 30 18 0C 06 03 00 00 07 00 00  ; ....0`0.........
  2E57  db 00 00 00 00 7F 7F 00 00 7F 7F 00 00 00 00 07 00  ; ................
  2E67  db 00 00 60 30 18 0C 06 03 06 0C 18 30 60 00 00 07  ; ..`0.......0`...
  2E77  db 00 00 00 3E 7F 63 03 03 03 06 0C 0C 00 0C 0C 00  ; ...>.c..........
  2E87  db 07 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ; ................
  2E97  db 00 08 3C 7E FF E7 E7 E7 FF FF FF E7 E7 E7 E7 E7  ; ..<~............
  2EA7  db E7 E7 08 FC FE FF E7 E7 E7 FE FC FE E7 E7 E7 E7  ; ................
  2EB7  db FF FE FC 08 3C 7E FF E7 E0 E0 E0 E0 E0 E0 E0 E0  ; ....<~..........
  2EC7  db E7 FF FF 7E 08 FC FE FF E7 E7 E7 E7 E7 E7 E7 E7  ; ...~............
  2ED7  db E7 E7 FF FE FC 07 7F 7F 7F 70 70 70 7E 7E 7E 70  ; .........ppp~~~p
  2EE7  db 70 70 70 7F 7F 7F 07 7F 7F 7F 70 70 70 7E 7E 7E  ; ppp.......ppp~~~
  2EF7  db 70 70 70 70 70 70 70 08 3C 7E FF E7 E0 E0 E0 EF  ; ppppppp.<~......
  2F07  db EF EF E7 E7 E7 FF FF 7E 08 E7 E7 E7 E7 E7 E7 FF  ; .......~........
  2F17  db FF FF E7 E7 E7 E7 E7 E7 E7 05 1F 0E 0E 0E 0E 0E  ; ................
  2F27  db 0E 0E 0E 0E 0E 0E 0E 0E 0E 1F 07 07 07 07 07 07  ; ................
  2F37  db 07 07 07 07 07 07 07 77 7F 3E 1C 08 E7 E7 E6 EE  ; .......w.>......
  2F47  db EE FC FC F8 F8 FC FC EC EE EE E7 E7 07 70 70 70  ; .............ppp
  2F57  db 70 70 70 70 70 70 70 70 70 70 7F 7F 7F 08 E1 F3  ; pppppppppp......
  2F67  db FF FF EB EB EB E3 E3 E3 E3 E3 E3 E3 E3 E3 08 E7  ; ................
  2F77  db E7 F7 F7 F7 FF FF FF EF EF EF EF E7 E7 E7 E7 08  ; ................
  2F87  db 3C 7E FF E7 E7 E7 E7 E7 E7 E7 E7 E7 E7 FF 7E 3C  ; <~............~<
  2F97  db 08 FC FE FF E7 E7 FF FE FC E0 E0 E0 E0 E0 E0 E0  ; ................
  2FA7  db E0 08 3C 7E FF E7 E7 E7 E7 E7 E7 E7 E7 E7 EB F5  ; ..<~............
  2FB7  db 7A 3D 08 FC FE FF E7 E7 E7 FF FE FC FC EE EE EE  ; z=..............
  2FC7  db E6 E7 E7 08 7E FF FF E7 E0 F0 78 3C 1E 0F 07 07  ; ....~.....x<....
  2FD7  db E7 FF FF 7E 07 7F 7F 7F 1C 1C 1C 1C 1C 1C 1C 1C  ; ...~............
  2FE7  db 1C 1C 1C 1C 1C 08 E7 E7 E7 E7 E7 E7 E7 E7 E7 E7  ; ................
  2FF7  db E7 E7 E7 FF 7E 3C 08 E7 E7 E7 E7 E7 E7 E7 E7 E7  ; ....~<..........
  3007  db E7 66 7E 3C 3C 18 18 08 E3 E3 E3 E3 E3 E3 E3 E3  ; .f~<<...........
  3017  db E3 EB EB EB FF FF F7 E3 08 E7 E7 E7 E7 E7 FF 7E  ; ...............~
  3027  db 3C 18 3C 7E FF E7 E7 E7 E7 07 63 63 63 77 77 77  ; <.<~......cccwww
  3037  db 7F 3E 1C 1C 1C 1C 1C 1C 1C 1C 07 7F 7F 7F 07 07  ; .>..............
  3047  db 0E 0E 1C 1C 38 38 70 70 7F 7F 7F 08 E7 E7 E7 00  ; ....88pp........
  3057  db 3C 7E E7 E7 E7 FF FF FF E7 E7 E7 E7 08 E7 E7 E7  ; <~..............
  3067  db 00 3C 7E FF E7 E7 E7 E7 E7 E7 FF 7E 3C 08 E7 E7  ; .<~........~<...
  3077  db E7 00 E7 E7 E7 E7 E7 E7 E7 E7 E7 FF 7E 3C 08 3C  ; ............~<.<
  3087  db 7E E7 E7 E6 EE EF E7 E7 E7 EF EE EC E0 E0 E0 07  ; ~...............
  3097  db 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F 7F  ; ................
  30A7  db 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ; ................
  30B7  db 00 08 7F 40 58 58 58 58 58 58 58 58 5D 4F 47 40  ; ...@XXXXXXXX]OG@
  30C7  db 7F 00 05 1E 02 1A 1A 1A 1A 1A 1A 1A 1A 1A 12 02  ; ................
  30D7  db 02 1E 00 06 1F 10 10 13 17 16 16 17 13 10 10 17  ; ................
  30E7  db 13 10 1F 00 06 3E 02 02 32 3A 02 02 32 3A 1A 1A  ; .....>..2:..2:..
  30F7  db 3A 32 02 3E 00 08 3F 7F 7D 7C 7C 7E 5E 60 5E 7E  ; :2.>..?.}||~^`^~
  3107  db 7C 7C 7D 7F 3F 00 08 FE FF FF FF 7F 3F 1F 01 1F  ; ||}.?.......?...
  3117  db 3F 7F FF FF FF FE 00 08 03 0F 1D 3C 3C 7E 5E 60  ; ?..........<<~^`
  3127  db 5E 7E 3C 3C 1D 0F 03 00 08 E0 F8 FC FE 7E 3F 1F  ; ^~<<.........~?.
  3137  db 01 1F 3F 7E FE FC F8 E0 00 01 00 00 00 00 00 00  ; ..?~............
  3147  db 00 00 00 00 00 00 00 00 00 00 08 00 0E 1F 1F 0E  ; ................
  3157  db 06 0F 1E 2F 4F 0F 1F 31 60 C1 00 08 00 00 00 C1  ; .../O..1`.......
  3167  db C3 23 01 80 41 23 1D 01 83 C6 8C 00 06 00 00 00  ; .#..A#..........
  3177  db 30 38 38 30 30 38 3C 3A 38 0C 06 04 00 08 7F FF  ; 088008<:8.......
  3187  db 00 F8 FC CC CC FD F9 C0 C0 C0 00 FF 7F 00 08 FF  ; ................
  3197  db FF 00 03 03 63 63 FB FB 63 63 03 00 FF FF 00 05  ; ....cc..cc......
  31A7  db 1C 1E 00 1C 1E 06 06 1E 1C 0C 06 06 00 1E 1C 00  ; ................
  31B7  db 08 07 1F 18 0C 06 03 7F FC 00 00 00 00 00 00 00  ; ................
  31C7  db 00 03 07 06 00 00 00 00 00 00 00 00 00 00 00 00  ; ................
  31D7  db 00 00 08 07 19 21 41 41 43 83 83 83 87 4E 4C 50  ; .....!AAC....NLP
  31E7  db 20 18 07 07 60 18 04 02 02 42 41 41 41 61 72 32  ;  ...`....BAAAar2
  31F7  db 0A 04 18 60 08 00 01 01 00 7F FF 7F 07 0B 1D 3A  ; ...`...........:
  3207  db 37 0E 1C 38 30 08 C0 E0 E0 C0 F0 F8 FC FE EE DC  ; 7..80...........
  3217  db B8 30 00 40 A0 40 01 00 00 00 00 00 00 00 00 00  ; .0.@.@..........
  3227  db 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 00  ; ................
  3237  db 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00  ; ................
  3247  db 00 00 00 00 00 00 00 00 00 08 07 18 30 70 4F 8F  ; ............0pO.
  3257  db 8F 8F F0 F0 F0 70 4F 2F 1F 07 07 60 78 7C 7A 06  ; .....pO/...`x|z.
  3267  db 07 07 07 79 79 79 7A 06 04 18 60 01 00 00 00 00  ; ...yyyz...`.....
  3277  db 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00  ; ................
  3287  db 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00  ; ................
  3297  db 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00  ; ................
  32A7  db 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01  ; ................
  32B7  db 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ; ................
  32C7  db 0D 60 61 FF 07 00 00 00 00 00 00 00 00 00 00 00  ; .`a.............
  32D7  db 00 00 07 00 0C 0C 0C 0C 0C 0C 0C 0C 00 0C 0C 00  ; ................
  32E7  db 07 00 33 33 33 33 00 00 00 00 00 00 00 00 07 00  ; ..3333..........
  32F7  db 00 00 00 14 14 7F 14 14 7F 14 14 00 07 00 00 00  ; ................
  3307  db 1C 1C 08 1C 7E 1D 1C 1C 14 36 07 1C 1C 1C 08 1C  ; ....~....6......
  3317  db 3E 5D 5D 3E 7F 14 14 36 07 7F 7F 7F 7F 7F 7F 7F  ; >]]>...6........
  3327  db 7F 7F 7F 7F 7F 7F 07 00 0C 0C 0C 18 00 00 00 00  ; ................
  3337  db 00 00 00 00 07 00 0C 18 30 60 60 60 60 60 30 18  ; ........0`````0.
  3347  db 0C 00 07 00 18 0C 06 03 03 03 03 03 06 0C 18 00  ; ................
  3357  db 07 00 00 00 49 2A 1C 7F 1C 2A 49 00 00 00 07 00  ; ....I*...*I.....
  3367  db 00 00 00 0C 0C 3F 3F 0C 0C 00 00 00 07 00 00 00  ; .....??.........
  3377  db 00 00 00 00 00 0C 0C 0C 18 00 07 00 00 00 00 00  ; ................
  3387  db 00 7F 7F 00 00 00 00 00 07 00 00 00 00 00 00 00  ; ................
  3397  db 00 00 00 0C 0C 00 07 00 03 03 06 06 0C 0C 18 18  ; ................
  33A7  db 30 30 60 60 07 3E 7F 63 63 63 63 63 63 63 63 63  ; 00``.>.ccccccccc
  33B7  db 7F 3E 07 06 0E 3E 3E 06 06 06 06 06 06 06 06 0F  ; .>...>>.........
  33C7  db 07 3E 7F 63 03 03 07 0E 1C 38 70 60 7F 7F 07 3E  ; .>.c.....8p`...>
  33D7  db 7F 63 03 03 1E 1E 03 03 03 63 7F 3E 07 60 60 66  ; .c.......c.>.``f
  33E7  db 66 66 66 7F 7F 06 06 06 06 06 07 7F 7F 60 60 60  ; fff..........```
  33F7  db 7E 7F 03 03 03 63 7F 3E 07 3E 7F 63 60 60 7E 7F  ; ~....c.>.>.c``~.
  3407  db 63 63 63 63 7F 3E 07 7F 7F 03 03 03 07 0E 1C 38  ; cccc.>.........8
  3417  db 30 30 30 30 07 3E 7F 63 63 63 3E 3E 63 63 63 63  ; 0000.>.ccc>>cccc
  3427  db 7F 3E 07 3E 7F 63 63 63 7F 3F 03 03 03 63 7F 3E  ; .>.>.ccc.?...c.>
  3437  db 07 00 00 00 00 0C 0C 00 00 0C 0C 00 00 00 07 00  ; ................
  3447  db 00 00 00 0C 0C 00 00 0C 0C 18 00 00 07 00 03 06  ; ................
  3457  db 0C 18 30 60 30 18 0C 06 03 00 07 00 00 00 00 7F  ; ..0`0...........
  3467  db 7F 00 00 7F 7F 00 00 00 07 00 60 30 18 0C 06 03  ; ..........`0....
  3477  db 06 0C 18 30 60 00 07 3E 7F 63 03 03 03 06 0C 0C  ; ...0`..>.c......
  3487  db 00 0C 0C 00 07 00 00 00 00 00 00 00 00 00 00 00  ; ................
  3497  db 00 00 07 3E 7F 63 63 63 63 7F 7F 63 63 63 63 63  ; ...>.cccc..ccccc
  34A7  db 07 7E 7F 63 63 63 7E 7E 63 63 63 63 7F 7E 07 3E  ; .~.ccc~~cccc.~.>
  34B7  db 7F 63 60 60 60 60 60 60 60 63 7F 3E 07 7E 7F 63  ; .c```````c.>.~.c
  34C7  db 63 63 63 63 63 63 63 63 7F 7E 07 7F 7F 60 60 60  ; cccccccc.~...```
  34D7  db 7E 7E 60 60 60 60 7F 7F 07 7F 7F 60 60 60 7E 7E  ; ~~````.....```~~
  34E7  db 60 60 60 60 60 60 07 3E 7F 63 63 60 60 6E 6F 63  ; ``````.>.cc``noc
  34F7  db 63 63 7F 3E 07 63 63 63 63 63 7F 7F 63 63 63 63  ; cc.>.ccccc..cccc
  3507  db 63 63 07 3C 18 18 18 18 18 18 18 18 18 18 18 3C  ; cc.<...........<
  3517  db 07 03 03 03 03 03 03 03 03 03 63 63 7F 1E 07 61  ; ..........cc...a
  3527  db 63 66 6C 78 70 60 70 78 6C 66 63 61 07 60 60 60  ; cflxp`pxlfca.```
  3537  db 60 60 60 60 60 60 60 60 7F 7F 07 63 77 77 6B 6B  ; ````````...cwwkk
  3547  db 63 63 63 63 63 63 63 63 07 63 63 63 63 73 7B 6B  ; cccccccc.ccccs{k
  3557  db 6F 67 63 63 63 63 07 3E 7F 63 63 63 63 63 63 63  ; ogcccc.>.ccccccc
  3567  db 63 63 7F 3E 07 7E 7F 63 63 63 7F 7E 60 60 60 60  ; cc.>.~.ccc.~````
  3577  db 60 60 07 3E 7F 63 63 63 63 63 63 63 6B 65 7B 3E  ; ``.>.cccccccke{>
  3587  db 07 7E 7F 63 63 63 7F 7E 78 6C 6C 66 66 63 07 3E  ; .~.ccc.~xllffc.>
  3597  db 7F 63 60 60 7E 3F 03 03 03 63 7F 3E 07 3F 3F 0C  ; .c``~?...c.>.??.
  35A7  db 0C 0C 0C 0C 0C 0C 0C 0C 0C 0C 07 63 63 63 63 63  ; ...........ccccc
  35B7  db 63 63 63 63 63 63 7F 3E 07 63 63 63 63 63 36 36  ; cccccc.>.ccccc66
  35C7  db 36 36 14 14 1C 1C 07 63 63 63 63 63 63 63 6B 6B  ; 66.....ccccccckk
  35D7  db 6B 77 77 63 07 63 63 63 77 3E 1C 08 1C 3E 77 63  ; kwwc.cccw>...>wc
  35E7  db 63 63 07 63 63 63 63 36 36 36 18 18 18 18 18 18  ; cc.cccc666......
  35F7  db 07 7F 7F 03 06 06 0C 0C 18 30 30 60 7F 7F 07 63  ; .........00`...c
  3607  db 63 00 3E 7F 63 63 7F 7F 63 63 63 63 07 63 63 00  ; c.>.cc..cccc.cc.
  3617  db 3E 7F 63 63 63 63 63 63 7F 3E 07 63 63 00 00 63  ; >.cccccc.>.cc..c
  3627  db 63 63 63 63 63 63 7F 3E 07 3E 7F 63 63 6E 6E 63  ; cccccc.>.>.ccnnc
  3637  db 63 63 63 6F 6F 60 07 7F 7F 7F 7F 7F 7F 7F 7F 7F  ; cccoo`..........
  3647  db 7F 7F 7F 7F 01 00 00 00 00 00 00 00 00 00 00 00  ; ................
  3657  db 00 00 01 00 00 00 00 00 00 00 01 01 01 00 01 00  ; ................
  3667  db 01 00 00 00 00 00 00 00 00 00 00 00 00 00 01 01  ; ................
  3677  db 01 00 00 01 01 00 00 01 01 00 01 00 01 00 00 00  ; ................
  3687  db 00 00 00 00 00 00 00 00 00 00 08 3F 7D 7C 7C 7E  ; ...........?}||~
  3697  db 5E 60 5E 7E 7C 7C 7D 3F 08 FE FF FF 7F 3F 1F 01  ; ^`^~||}?.....?..
  36A7  db 1F 3F 7F FF FF FE 08 03 0F 1D 3C 7E 5E 60 5E 7E  ; .?........<~^`^~
  36B7  db 3C 1D 0F 03 08 E0 F8 FC 7E 3F 1F 01 1F 3F 7E FC  ; <.......~?...?~.
  36C7  db F8 E0 01 01 00 01 00 01 01 01 01 01 00 00 00 00  ; ................
  36D7  db 08 0E 1F 1F 0E 06 0F 1E 2F 4F 1F 31 60 C1 08 00  ; ......../O.1`...
  36E7  db 00 C1 C3 23 01 80 41 23 1D 83 C6 8C 06 00 00 30  ; ...#..A#.......0
  36F7  db 38 38 30 30 38 3C 3A 0C 06 04 08 FF 00 F8 FC CC  ; 88008<:.........
  3707  db CC FD F9 C0 C0 C0 00 FF 08 FF 00 03 03 63 63 FB  ; .............cc.
  3717  db FB 63 63 03 00 FF 05 1E 00 1C 1E 06 06 1E 1C 0C  ; .cc.............
  3727  db 06 06 00 1E 08 07 1F 18 0C 06 03 7F FC 00 00 00  ; ................
  3737  db 00 00 03 07 06 00 00 00 00 00 00 00 00 00 00 00  ; ................
  3747  db 07 03 0D 11 21 41 43 43 43 46 2C 10 0C 03 06 20  ; ....!ACCCF,.... 
  3757  db 18 04 02 01 21 21 21 31 1A 04 18 20 08 04 0E 0E  ; ....!!!1... ....
  3767  db 04 FF FF 0E 1E 3E 6C 19 32 61 05 00 00 00 00 10  ; .....>l.2a......
  3777  db 18 0C 18 10 00 00 10 00 08 0F 30 40 5E 86 87 86  ; ..........0@^...
  3787  db 87 8D 59 40 30 0F 05 10 0C 02 1E 19 11 01 01 15  ; ..Y@0...........
  3797  db 1A 02 0C 10 01 00 00 00 00 00 00 00 00 00 00 00  ; ................
  37A7  db 00 00 07 07 19 31 2E 4E 4E 71 71 71 2E 3E 1E 07  ; .....1.NNqqq.>..
  37B7  db 06 30 3C 32 0E 0F 0F 31 31 31 0E 0E 0C 30 01 00  ; .0<2...111...0..
  37C7  db 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00  ; ................
  37D7  db 00 00 00 00 00 00 00 00 00 00 01 00 00 00 00 00  ; ................
  37E7  db 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00  ; ................
  37F7  db 00 00 00 00 00 00 01 00 00 00 00 00 00 00 00 00  ; ................
  3807  db 00 00 00 00 52 2E 53 43 48 2E 00 00 00 02 0D 00  ; ....R.SCH.......
  3817  db 01 15 02 00 1C 01 00 23 01 20 17 1F 37 00 00 00  ; .......#. ..7...
  3827  db 00 00 00 00 00 00 3A 20 17 1F 37 1C 10 54 10 00  ; ......: ..7..T..
  3837  db 00 02 01 00 3A 20 37 1F A7 1C 10 00 00 00 00 02  ; ....: 7.........
  3847  db 01 00 3B 20 37 1F A7 1C 10 00 00 00 00 02 01 00  ; ..; 7...........
  3857  db 3B 20 37 1F 37 1C 10 00 00 00 00 02 01 00 3B 20  ; ; 7.7.........; 
  3867  db 17 1F 37 1C 10 54 10 00 00 00 00 00 3A 20 17 1F  ; ..7..T......: ..
  3877  db 37 15 10 54 10 00 00 00 00 00 3A 20 17 1F 37 15  ; 7..T......: ..7.
  3887  db 10 00 00 00 00 00 00 00 3A 20 17 1F 37 15 10 00  ; ........: ..7...
  3897  db 00 00 00 00 00 00 3A 20 17 1F 37 15 10 54 10 00  ; ......: ..7..T..
  38A7  db 00 00 00 00 3A 20 17 1F 37 15 10 54 10 00 00 00  ; ....: ..7..T....
  38B7  db 00 00 3A 20 17 1F 37 15 10 00 00 00 00 00 00 00  ; ..: ..7.........
  38C7  db 3A 20 17 1F 37 15 10 00 00 00 00 00 00 00 3A 20  ; : ..7.........: 
  38D7  db 17 1F 37 15 10 54 10 00 00 00 00 00 3A 20 17 1F  ; ..7..T......: ..
  38E7  db 37 15 10 54 10 00 00 00 00 00 3A 20 17 1F 37 15  ; 7..T......: ..7.
  38F7  db 10 00 00 00 00 00 00 00 3A 00 00 00 00 09 09 04  ; ........:.......
  3907  db 04 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3917  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3927  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3937  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3947  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3957  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3967  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3977  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3987  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  3997  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  39A7  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  39B7  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  39C7  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  39D7  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  39E7  db 05 00 00 00 01 00 00 00 00 00 00 00 00 09 09 05  ; ................
  39F7  db 05 00 00 00 01 00 00 00 00 00 00 00 00 20 20 5B  ; .............  [
  3A07  db 20 57 20 20 5B 20 57 20 20 5B 20 57 20 29 63 29  ;  W  [ W  [ W )c)
  3A17  db 5F 20 26 5F 26 5B 20 29 63 29 5F 20 26 5F 26 5B  ; _ &_&[ )c)_ &_&[
  3A27  db 20 29 63 29 5F 20 26 5F 26 5B 20 2C 67 2C 63 20  ;  )c)_ &_&[ ,g,c 
  3A37  db 32 CB 32 C7 20 00 00 00 00 20 00 00 00 00 20 00  ; 2.2. .... .... .
  3A47  db 00 00 00 20 00 00 00 00 20 80 00 55 4E 49 43 20  ; ... .... ..UNIC 
  3A57  db 20 20 20  ;    
L3A5A:
  3A5A  30e303    JNB ACC.3,L3A60
  3A5D  cf        XCH A,R7
  3A5E  ce        XCH A,R6
  3A5F  cf        XCH A,R7
L3A60:
  3A60  5407      ANL A,#07h
  3A62  f8        MOV R0,A
  3A63  903a7f    MOV DPTR,#3A7Fh
  3A66  93        MOVC A,@A+DPTR
  3A67  f5f0      MOV B,A
  3A69  ef        MOV A,R7
  3A6A  a4        MUL AB
  3A6B  ff        MOV R7,A
  3A6C  e8        MOV A,R0
  3A6D  93        MOVC A,@A+DPTR
  3A6E  a8f0      MOV R0,B
  3A70  f5f0      MOV B,A
  3A72  ee        MOV A,R6
  3A73  a4        MUL AB
  3A74  28        ADD A,R0
  3A75  fe        MOV R6,A
  3A76  ef        MOV A,R7
  3A77  25f0      ADD A,B
  3A79  ff        MOV R7,A
  3A7A  22        RET
L3A7B:
  3A7B  f4        CPL A
  3A7C  04        INC A
  3A7D  80db      SJMP L3A5A
  3A7F  db 01 02 04 08 10 20 40 80  ; ..... @.
L3A87:
  3A87  856183    MOV DPH,61h
  3A8A  856282    MOV DPL,62h
  3A8D  ac63      MOV R4,63h
  3A8F  0564      INC 64h
  3A91  0565      INC 65h
  3A93  023a9b    LJMP L3A9B
L3A96:
  3A96  e0        MOVX A,@DPTR
  3A97  6c        XRL A,R4
  3A98  600c      JZ L3AA6
  3A9A  a3        INC DPTR
L3A9B:
  3A9B  d565f8    DJNZ 65h,L3A96
  3A9E  d564f5    DJNZ 64h,L3A96
  3AA1  7eff      MOV R6,#FFh
  3AA3  7fff      MOV R7,#FFh
  3AA5  22        RET
L3AA6:
  3AA6  c3        CLR C
  3AA7  e582      MOV A,DPL
  3AA9  9562      SUBB A,62h
  3AAB  ff        MOV R7,A
  3AAC  e583      MOV A,DPH
  3AAE  9561      SUBB A,61h
  3AB0  fe        MOV R6,A
  3AB1  22        RET
L3AB2:
  3AB2  c0e0      PUSH ACC
  3AB4  c0f0      PUSH B
  3AB6  c083      PUSH DPH
  3AB8  c082      PUSH DPL
  3ABA  c0d0      PUSH PSW
  3ABC  75d008    MOV PSW,#08h
  3ABF  12041a    LCALL L041A
  3AC2  d0d0      POP PSW
  3AC4  d082      POP DPL
  3AC6  d083      POP DPH
  3AC8  d0f0      POP B
  3ACA  d0e0      POP ACC
  3ACC  32        RETI
L3ACD:
  3ACD  c0e0      PUSH ACC
  3ACF  c0f0      PUSH B
  3AD1  c083      PUSH DPH
  3AD3  c082      PUSH DPL
  3AD5  c0d0      PUSH PSW
  3AD7  75d008    MOV PSW,#08h
  3ADA  12035b    LCALL L035B
  3ADD  d0d0      POP PSW
  3ADF  d082      POP DPL
  3AE1  d083      POP DPH
  3AE3  d0f0      POP B
  3AE5  d0e0      POP ACC
  3AE7  32        RETI
L3AE8:
  3AE8  7e00      MOV R6,#00h
  3AEA  123b31    LCALL L3B31
  3AED  ef        MOV A,R7
  3AEE  2582      ADD A,DPL
  3AF0  f582      MOV DPL,A
  3AF2  ee        MOV A,R6
  3AF3  3583      ADDC A,DPH
  3AF5  f583      MOV DPH,A
  3AF7  22        RET
L3AF8:
  3AF8  25e0      ADD A,ACC
  3AFA  5002      JNC L3AFE
  3AFC  0583      INC DPH
L3AFE:
  3AFE  2582      ADD A,DPL
  3B00  5002      JNC L3B04
  3B02  0583      INC DPH
L3B04:
  3B04  f582      MOV DPL,A
  3B06  22        RET
L3B07:
  3B07  a3        INC DPTR
  3B08  e0        MOVX A,@DPTR
  3B09  14        DEC A
  3B0A  f0        MOVX @DPTR,A
  3B0B  b4ff06    CJNE A,#FFh,L3B14
  3B0E  123b6b    LCALL L3B6B
  3B11  e0        MOVX A,@DPTR
  3B12  14        DEC A
  3B13  f0        MOVX @DPTR,A
L3B14:
  3B14  22        RET
L3B15:
  3B15  04        INC A
  3B16  8007      SJMP L3B1F
L3B18:
  3B18  c3        CLR C
  3B19  cf        XCH A,R7
  3B1A  33        RLC A
  3B1B  cf        XCH A,R7
  3B1C  ce        XCH A,R6
  3B1D  33        RLC A
  3B1E  ce        XCH A,R6
L3B1F:
  3B1F  d5e0f6    DJNZ ACC,L3B18
  3B22  22        RET
L3B23:
  3B23  04        INC A
  3B24  8007      SJMP L3B2D
L3B26:
  3B26  c3        CLR C
  3B27  ce        XCH A,R6
  3B28  13        RRC A
  3B29  ce        XCH A,R6
  3B2A  cf        XCH A,R7
  3B2B  13        RRC A
  3B2C  cf        XCH A,R7
L3B2D:
  3B2D  d5e0f6    DJNZ ACC,L3B26
  3B30  22        RET
L3B31:
  3B31  f8        MOV R0,A
  3B32  8ff0      MOV B,R7
  3B34  a4        MUL AB
  3B35  ff        MOV R7,A
  3B36  e5f0      MOV A,B
  3B38  ce        XCH A,R6
  3B39  88f0      MOV B,R0
  3B3B  a4        MUL AB
  3B3C  2e        ADD A,R6
  3B3D  fe        MOV R6,A
  3B3E  22        RET
L3B3F:
  3B3F  e0        MOVX A,@DPTR
  3B40  c0e0      PUSH ACC
  3B42  a3        INC DPTR
  3B43  e0        MOVX A,@DPTR
  3B44  f582      MOV DPL,A
  3B46  d0e0      POP ACC
  3B48  f583      MOV DPH,A
  3B4A  22        RET
L3B4B:
  3B4B  ef        MOV A,R7
  3B4C  2582      ADD A,DPL
  3B4E  f582      MOV DPL,A
  3B50  ee        MOV A,R6
  3B51  3583      ADDC A,DPH
  3B53  f583      MOV DPH,A
  3B55  22        RET
L3B56:
  3B56  e582      MOV A,DPL
  3B58  2f        ADD A,R7
  3B59  f582      MOV DPL,A
  3B5B  e583      MOV A,DPH
  3B5D  3e        ADDC A,R6
  3B5E  f583      MOV DPH,A
  3B60  22        RET
L3B61:
  3B61  ef        MOV A,R7
  3B62  2582      ADD A,DPL
  3B64  f582      MOV DPL,A
  3B66  5002      JNC L3B6A
  3B68  0583      INC DPH
L3B6A:
  3B6A  22        RET
L3B6B:
  3B6B  0582      INC DPL
  3B6D  d58202    DJNZ DPL,L3B72
  3B70  1583      DEC DPH
L3B72:
  3B72  1582      DEC DPL
  3B74  22        RET
L3B75:
  3B75  2582      ADD A,DPL
  3B77  f582      MOV DPL,A
  3B79  5002      JNC L3B7D
  3B7B  0583      INC DPH
L3B7D:
  3B7D  22        RET
L3B7E:
  3B7E  e4        CLR A
  3B7F  93        MOVC A,@A+DPTR
  3B80  f6        MOV @R0,A
  3B81  08        INC R0
  3B82  7401      MOV A,#01h
  3B84  93        MOVC A,@A+DPTR
  3B85  f6        MOV @R0,A
  3B86  22        RET
L3B87:
  3B87  758167    MOV SP,#67h
  3B8A  75d000    MOV PSW,#00h
  3B8D  02136f    LJMP L136F
L3B90:
  3B90  08        INC R0
  3B91  06        INC @R0
  3B92  b60002    CJNE @R0,#00h,L3B97
  3B95  18        DEC R0
  3B96  06        INC @R0
L3B97:
  3B97  22        RET
L3B98:
  3B98  08        INC R0
  3B99  16        DEC @R0
  3B9A  b6ff02    CJNE @R0,#FFh,L3B9F
  3B9D  18        DEC R0
  3B9E  16        DEC @R0
L3B9F:
  3B9F  22        RET
  3BA0  ... FF x17504
