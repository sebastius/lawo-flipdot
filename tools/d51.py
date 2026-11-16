#!/usr/bin/env python3
"""Minimal 8051 recursive-traversal disassembler."""
import sys, collections

SFR = {0x80:'P0',0x81:'SP',0x82:'DPL',0x83:'DPH',0x87:'PCON',0x88:'TCON',0x89:'TMOD',
0x8A:'TL0',0x8B:'TL1',0x8C:'TH0',0x8D:'TH1',0x90:'P1',0x98:'SCON',0x99:'SBUF',0xA0:'P2',
0xA8:'IE',0xB0:'P3',0xB8:'IP',0xC8:'T2CON',0xCA:'RCAP2L',0xCB:'RCAP2H',0xCC:'TL2',0xCD:'TH2',
0xD0:'PSW',0xE0:'ACC',0xF0:'B'}
BITN = {0x88:['IT0','IE0','IT1','IE1','TR0','TF0','TR1','TF1'],
0x98:['RI','TI','RB8','TB8','REN','SM2','SM1','SM0'],
0xA8:['EX0','ET0','EX1','ET1','ES','ET2','IE.6','EA'],
0xB0:['RXD','TXD','INT0','INT1','T0','T1','WR','RD'],
0xB8:['PX0','PT0','PX1','PT1','PS','PT2','IP.6','IP.7'],
0xD0:['P','PSW.1','OV','RS0','RS1','F0','AC','CY'],
0xC8:['CP_RL2','C_T2','TR2','EXEN2','TCLK','RCLK','EXF2','TF2']}
def d(a): return SFR.get(a, '%02Xh'%a)
def bit(b):
    if b < 0x80: return '%02Xh.%d'%(0x20+(b>>3), b&7) + ('{b%02X}'%b)
    base = b & 0xF8
    if base in BITN: return BITN[base][b&7]
    return '%s.%d'%(d(base), b&7)

# opcode table: (mnemonic template, length, kind)
# operands codes: d=direct, i=#imm, b=bit, r=rel, a11, a16, I16=#data16
def build():
    T = {}
    rn = ['R%d'%i for i in range(8)]
    for i in range(8):
        T[0x08+i]=('INC '+rn[i],1); T[0x18+i]=('DEC '+rn[i],1)
        T[0x28+i]=('ADD A,'+rn[i],1); T[0x38+i]=('ADDC A,'+rn[i],1)
        T[0x48+i]=('ORL A,'+rn[i],1); T[0x58+i]=('ANL A,'+rn[i],1)
        T[0x68+i]=('XRL A,'+rn[i],1); T[0x78+i]=('MOV '+rn[i]+',#{i}',2)
        T[0x88+i]=('MOV {d},'+rn[i],2); T[0x98+i]=('SUBB A,'+rn[i],1)
        T[0xA8+i]=('MOV '+rn[i]+',{d}',2); T[0xB8+i]=('CJNE '+rn[i]+',#{i},{r}',3)
        T[0xC8+i]=('XCH A,'+rn[i],1); T[0xD8+i]=('DJNZ '+rn[i]+',{r}',2)
        T[0xE8+i]=('MOV A,'+rn[i],1); T[0xF8+i]=('MOV '+rn[i]+',A',1)
    for j,ri in ((0,'@R0'),(1,'@R1')):
        T[0x06+j]=('INC '+ri,1); T[0x16+j]=('DEC '+ri,1); T[0x26+j]=('ADD A,'+ri,1)
        T[0x36+j]=('ADDC A,'+ri,1); T[0x46+j]=('ORL A,'+ri,1); T[0x56+j]=('ANL A,'+ri,1)
        T[0x66+j]=('XRL A,'+ri,1); T[0x76+j]=('MOV '+ri+',#{i}',2); T[0x86+j]=('MOV {d},'+ri,2)
        T[0x96+j]=('SUBB A,'+ri,1); T[0xA6+j]=('MOV '+ri+',{d}',2); T[0xB6+j]=('CJNE '+ri+',#{i},{r}',3)
        T[0xC6+j]=('XCH A,'+ri,1); T[0xD6+j]=('XCHD A,'+ri,1); T[0xE6+j]=('MOV A,'+ri,1)
        T[0xF6+j]=('MOV '+ri+',A',1); T[0xE2+j]=('MOVX A,'+ri,1); T[0xF2+j]=('MOVX '+ri+',A',1)
    for k in range(8):
        T[0x01+k*0x20]=('AJMP {a11}',2); T[0x11+k*0x20]=('ACALL {a11}',2)
    T.update({0x00:('NOP',1),0x02:('LJMP {a16}',3),0x03:('RR A',1),0x04:('INC A',1),0x05:('INC {d}',2),
    0x10:('JBC {b},{r}',3),0x12:('LCALL {a16}',3),0x13:('RRC A',1),0x14:('DEC A',1),0x15:('DEC {d}',2),
    0x20:('JB {b},{r}',3),0x22:('RET',1),0x23:('RL A',1),0x24:('ADD A,#{i}',2),0x25:('ADD A,{d}',2),
    0x30:('JNB {b},{r}',3),0x32:('RETI',1),0x33:('RLC A',1),0x34:('ADDC A,#{i}',2),0x35:('ADDC A,{d}',2),
    0x40:('JC {r}',2),0x42:('ORL {d},A',2),0x43:('ORL {d},#{i2}',3),0x44:('ORL A,#{i}',2),0x45:('ORL A,{d}',2),
    0x50:('JNC {r}',2),0x52:('ANL {d},A',2),0x53:('ANL {d},#{i2}',3),0x54:('ANL A,#{i}',2),0x55:('ANL A,{d}',2),
    0x60:('JZ {r}',2),0x62:('XRL {d},A',2),0x63:('XRL {d},#{i2}',3),0x64:('XRL A,#{i}',2),0x65:('XRL A,{d}',2),
    0x70:('JNZ {r}',2),0x72:('ORL C,{b}',2),0x73:('JMP @A+DPTR',1),0x74:('MOV A,#{i}',2),0x75:('MOV {d},#{i2}',3),
    0x80:('SJMP {r}',2),0x82:('ANL C,{b}',2),0x83:('MOVC A,@A+PC',1),0x84:('DIV AB',1),0x85:('MOV {d2},{d}',3),
    0x90:('MOV DPTR,#{I16}',3),0x92:('MOV {b},C',2),0x93:('MOVC A,@A+DPTR',1),0x94:('SUBB A,#{i}',2),0x95:('SUBB A,{d}',2),
    0xA0:('ORL C,/{b}',2),0xA2:('MOV C,{b}',2),0xA3:('INC DPTR',1),0xA4:('MUL AB',1),0xA5:('???',1),
    0xB0:('ANL C,/{b}',2),0xB2:('CPL {b}',2),0xB3:('CPL C',1),0xB4:('CJNE A,#{i},{r}',3),0xB5:('CJNE A,{d},{r}',3),
    0xC0:('PUSH {d}',2),0xC2:('CLR {b}',2),0xC3:('CLR C',1),0xC4:('SWAP A',1),0xC5:('XCH A,{d}',2),
    0xD0:('POP {d}',2),0xD2:('SETB {b}',2),0xD3:('SETB C',1),0xD4:('DA A',1),0xD5:('DJNZ {d},{r}',3),
    0xE0:('MOVX A,@DPTR',1),0xE4:('CLR A',1),0xE5:('MOV A,{d}',2),
    0xF0:('MOVX @DPTR,A',1),0xF4:('CPL A',1),0xF5:('MOV {d},A',2)})
    return T
OPS = build()

def decode(rom, pc):
    op = rom[pc]; tpl, ln = OPS[op]
    b = rom[pc+1:pc+ln] if pc+ln <= len(rom) else bytes(3)
    targets = []; s = tpl
    def rel(x): return (pc+ln + (x-256 if x>127 else x)) & 0xFFFF
    if '{a11}' in s:
        t = ((pc+2)&0xF800) | ((op>>5)<<8) | b[0]; targets.append(t); s=s.replace('{a11}','L%04X'%t)
    if '{a16}' in s:
        t = (b[0]<<8)|b[1]; targets.append(t); s=s.replace('{a16}','L%04X'%t)
    if '{I16}' in s: s=s.replace('{I16}','%04Xh'%((b[0]<<8)|b[1]))
    if op==0x85: s=s.replace('{d2}',d(b[1])).replace('{d}',d(b[0]))
    if '{b}' in s: s=s.replace('{b}',bit(b[0]))
    if '{d}' in s: s=s.replace('{d}',d(b[0]))
    if '{i2}' in s: s=s.replace('{i2}','%02Xh'%b[1])
    if '{i}' in s: s=s.replace('{i}','%02Xh'%b[0])
    if '{r}' in s:
        t = rel(b[-1]); targets.append(t); s=s.replace('{r}','L%04X'%t)
    return s, ln, targets, op

def analyze(rom, entries):
    code = {}; labels=set(entries); calls=collections.Counter(); work=list(entries)
    while work:
        pc = work.pop()
        while pc < len(rom) and pc not in code:
            s, ln, tg, op = decode(rom, pc)
            code[pc]=(s,ln)
            for t in tg:
                labels.add(t)
                if t < len(rom): work.append(t)
                if op==0x12 or (op&0x1F)==0x11: calls[t]+=1
            if op in (0x02,0x22,0x32,0x73,0x80) or (op&0x1F)==0x01: break
            pc += ln
    return code, labels, calls

def listing(rom, code, labels, out):
    pc=0; n=len(rom)
    while pc<n:
        if pc in code:
            s,ln=code[pc]
            if pc in labels: out.write('L%04X:\n'%pc)
            out.write('  %04X  %-9s %s\n'%(pc, rom[pc:pc+ln].hex(), s)); pc+=ln
        else:
            st=pc
            while pc<n and pc not in code and pc-st<16: pc+=1
            chunk=rom[st:pc]
            if all(c==0xFF for c in chunk):
                while pc<n and pc not in code and rom[pc]==0xFF: pc+=1
                out.write('  %04X  ... FF x%d\n'%(st,pc-st)); continue
            out.write('  %04X  db %s  ; %s\n'%(st,' '.join('%02X'%c for c in chunk),''.join(chr(c) if 32<=c<127 else '.' for c in chunk)))

if __name__=='__main__':
    rom=open(sys.argv[1],'rb').read()
    extra=[int(x,16) for x in sys.argv[3:]]
    ents=[0]+[v for v in (3,0xB,0x13,0x1B,0x23,0x2B) if rom[v]==0x02]+extra
    code,labels,calls=analyze(rom,ents)
    with open(sys.argv[2],'w') as f: listing(rom,code,labels,f)
    print('code bytes', sum(l for _,l in code.values()), 'subs', len(calls))
