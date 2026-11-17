; ASFP-bitmap: uitbreiding van ASFP.bin (LAWO AZR 802/24) met pixel-, bitmap- en
; ververs-telegrammen en gedeeltelijke verversing (partial update).
; Alleen getest in de emulator (emulator/), niet op hardware.
;
; Nieuwe IBIS-telegrammen (CR + XOR-checksum zoals altijd):
;   aP<a><XXX><YY><C>[<XXX><YY><C>...]   pixels: kolom (3 cijfers), rij (2 cijfers, 0 = boven),
;                                        kleur 0 = zwart / 1 = geel
;   aB<a><XXX><HHHH>[<HHHH>...]          kolommen vanaf XXX; per kolom 16 bits hex,
;                                        bit y = rij y van boven (0001 = bovenste dot)
;   aU<a>                                alle dots opnieuw omzetten (tegen vastzittende dots)
; <a> = displayadres als teken ('1'..'?'); '0' = alle displays, dan geen antwoord.
; aB en aP mogen tot 500 tekens lang zijn (ASFP: 250), zodat een volledige bitmap van
; 112 x 16 (455 tekens) in één telegram past.
; Na elk geaccepteerd telegram antwoordt het display "a0"; daarna worden alleen de
; veranderde dots omgezet. Is de wachtrij vol, dan volgt geen antwoord (later opnieuw).
;
; Bitmapmodus: het eerste pixel/bitmap-telegram neemt het getoonde beeld over in een
; schaduwbuffer; daarna tekent alles in die schaduw. Een inhoudelijk ASFP-telegram
; (tekst, lijn, bestemming, testbeeld, ...) beëindigt de bitmapmodus; status- en
; versievragen (a<a>, aV<a>) niet.
;
; Werking in ASFP:
;   0x035F  ontvangstbuffer, index iRAM 2Dh (8 bit, max 0xF9); 0x0553 = ontvangststatus
;   0x057E  gewenst beeld, 2 bytes per kolom (hoog, laag); bit y = rij y van boven
;   0x07AE  getoond beeld (kopie na elke verversing)
;   0x0692  verversroutine; slaat onveranderde dots alleen over als 22h.0 = 1
;   22h.0   "wisseltekst actief": zolang gezet tekent de hoofdlus steeds de volgende pagina
;   0x0571  verzoek aan de hoofdlus (testbeeld aT gebruikt 1..4); 5 = verversen zonder vullen
;
; Opbouw van de patch:
;   - Ontvangst (interrupt): voor aB/aP telt de index door tot 500 (extra byte RX_HI).
;   - Herkenning (interrupt): adres controleren en het ruwe telegram in een wachtrij
;     kopiëren (2 x 512 bytes), "a0" antwoorden. Kort, zodat er geen tekens verloren gaan.
;   - Hoofdlus: zolang de wachtrij niet leeg is wordt 0x0571 = 5. Het omhulsel om de
;     verversing verwerkt dan alle telegrammen in de schaduw, kopieert die naar 0x057E en
;     ververst met 22h.0 = 1 (alleen verschillen); daarna 22h.0 = 0 (wisseltekst stopt).
;   - Reset: eigen variabelen wissen (het werk-RAM is batterijgebufferd).
;
; Haken in ASFP (origineel -> patch):
;   0x0000  LJMP 0x4EBF            -> LJMP init
;   0x001F  (opvulling 00 00 00)   -> LJMP ext_a
;   0x018B  SJMP 0x0204            -> AJMP 0x001F    (einde a-telegramherkenning)
;   0x0481  MOV 2Dh,#01h           -> LCALL rx_start (begin telegram)
;   0x04A9  MOV A,2Dh / SETB C     -> LJMP rx_store  (teken opslaan)
;   0x2FD9  MOV DPTR,#0571h        -> LJMP main_poll (hoofdlus)
;   0x30E0  LCALL 0x0692           -> LCALL refresh_wrap
; Nieuwe code vanaf 0x5000 (was 0xFF). Werk-RAM 0x0900-0x0F27 (ASFP gebruikt tot 0x08D0).
;
; Interruptcode draait in registerbank 1, hoofdluscode in bank 0. Gebruikt worden alleen
; R0-R7, ACC, B, DPTR en (tijdelijk, met herstel) P2, net als de ASFP-routines.

        .module asfp_bitmap
        .area   PATCH (ABS,CODE)

; ---------- ASFP ----------
BUF        = 0x035F        ; ontvangstbuffer, afgesloten met CR
RX_CS      = 0x002E        ; lopende checksum
RAW_CH     = 0x42          ; iRAM: ontvangen byte incl. pariteit
CH7        = 0x43          ; iRAM: ontvangen teken (7 bit)
RX_IDX     = 0x2D          ; iRAM: ontvangstindex (laag)
ADDR       = 0x055B        ; displayadres (binair)
WIDTH      = 0x055C        ; breedte in kolommen
HEIGHT     = 0x055D        ; hoogte in rijen
FB_NEW     = 0x057E        ; gewenst beeld
FB_OLD     = 0x07AE        ; getoond beeld
REQ        = 0x0571        ; verzoek aan hoofdlus
REQ_REFRESH = 5
TXBUF      = 0x031E
TXLEN      = 0x002F
TXIDX      = 0x0555
TYPE       = 0x38          ; iRAM: telegramtype in de verdeler (0 = onbekend)
T_STATUS   = 7
T_VERSION  = 8
LEN_CS     = 0x3A          ; iRAM: lengte voor de checksumroutine
DISPATCH_TAIL = 0x0204
REPLY_CS   = 0x00B2
REFRESH    = 0x0692
RESET_ORIG = 0x4EBF
RX_STORE_ORIG = 0x04B0     ; origineel: opslaan, aA-kopie, INC 2Dh
RX_AFTER   = 0x04FB        ; origineel: CR-controle
POLL_CONT  = 0x2FDC        ; origineel: MOVX A,@DPTR (DPTR = 0x0571)
B_TXBUSY   = 0x04          ; 20h.4
B_TI       = 0x99          ; SCON.1
B_PARTIAL  = 0x10          ; 22h.0
P2         = 0xA0

; ---------- eigen werk-RAM ----------
QBASE      = 0x09          ; wachtrij: slot i op (QBASE + 2*i) * 256, 512 bytes per slot
BM_FLAG    = 0x0E00        ; 1 = bitmapmodus (schaduw geldig)
FULL_REQ   = 0x0E01        ; 1 = volgende verversing alles omzetten
Q_HEAD     = 0x0E02        ; volgend te vullen slot (0/1)
Q_TAIL     = 0x0E03        ; volgend te verwerken slot (0/1)
RX_HI      = 0x0E04        ; ontvangstindex (hoog) voor lange telegrammen
SH         = 0x0E10        ; schaduwbuffer, max 140 kolommen x 2 bytes
RX_MAX     = 0x01F4        ; max. lengte aB/aP incl. CR (buffer tot vlak voor 0x0553)

CR         = 0x0D

; ---------- haken ----------
        .org    0x0000
        ljmp    init

        .org    0x001F
        ljmp    ext_a

        .org    0x018B
        ajmp    0x001F

        .org    0x0481
        lcall   rx_start

        .org    0x04A9
        ljmp    rx_store

        .org    0x2FD9
        ljmp    main_poll

        .org    0x30E0
        lcall   refresh_wrap

        .org    0x5000

; ---------- reset ----------
init:
        clr     a
        mov     dptr,#BM_FLAG
        movx    @dptr,a
        inc     dptr                    ; FULL_REQ
        movx    @dptr,a
        inc     dptr                    ; Q_HEAD
        movx    @dptr,a
        inc     dptr                    ; Q_TAIL
        movx    @dptr,a
        inc     dptr                    ; RX_HI
        movx    @dptr,a
        ljmp    RESET_ORIG

; ---------- ontvangst (seriële interrupt) ----------
; begin van een telegram (vervangt MOV 2Dh,#01h; daarna laadt ASFP A en DPTR opnieuw)
rx_start:
        mov     RX_IDX,#1
        mov     dptr,#RX_HI
        clr     a
        movx    @dptr,a
        ret

; teken opslaan (vervangt MOV A,2Dh / SETB C op 0x04A9)
rx_store:
        mov     dptr,#RX_HI
        movx    a,@dptr
        mov     r7,a                    ; index hoog
        jnz     rs_long
        mov     a,RX_IDX
        setb    c
        subb    a,#0xF9
        jnc     rs_long                 ; index >= 0xFA: voorbij de ASFP-grens
        ljmp    RX_STORE_ORIG           ; normaal: originele code
rs_long:
        mov     dptr,#BUF               ; alleen aB en aP mogen langer zijn
        movx    a,@dptr
        cjne    a,#0x61,rs_skip
        inc     dptr
        movx    a,@dptr
        cjne    a,#0x42,rs_p
        sjmp    rs_ok
rs_p:   cjne    a,#0x50,rs_skip
rs_ok:
        mov     a,RX_IDX                ; index < RX_MAX ?
        clr     c
        subb    a,#<RX_MAX
        mov     a,r7
        subb    a,#>RX_MAX
        jnc     rs_skip
        mov     dptr,#RX_CS             ; checksum bijwerken
        movx    a,@dptr
        xrl     a,RAW_CH
        movx    @dptr,a
        mov     a,RX_IDX                ; BUF[index] = teken
        add     a,#<BUF
        mov     dpl,a
        mov     a,r7
        addc    a,#>BUF
        mov     dph,a
        mov     a,CH7
        movx    @dptr,a
        inc     RX_IDX                  ; index++ (16 bit)
        mov     a,RX_IDX
        jnz     rs_skip
        inc     r7
        mov     dptr,#RX_HI
        mov     a,r7
        movx    @dptr,a
rs_skip:
        ljmp    RX_AFTER                ; CR-controle zoals origineel

; ---------- telegramherkenning (seriële interrupt) ----------
ext_a:
        mov     a,TYPE
        jz      ext_ours
        cjne    a,#T_STATUS,ext_k1      ; ASFP-telegram: inhoud beëindigt bitmapmodus,
        sjmp    ext_exit                ; status- en versievragen niet
ext_k1: cjne    a,#T_VERSION,ext_k2
        sjmp    ext_exit
ext_k2: mov     dptr,#BM_FLAG
        clr     a
        movx    @dptr,a
        sjmp    ext_exit
ext_ours:
        mov     dptr,#BUF
        movx    a,@dptr
        cjne    a,#0x61,ext_exit        ; 'a'
        inc     dptr
        movx    a,@dptr
        cjne    a,#0x50,ext_c1          ; 'P'
        sjmp    ext_addr
ext_c1: cjne    a,#0x42,ext_c2          ; 'B'
        sjmp    ext_addr
ext_c2: cjne    a,#0x55,ext_exit        ; 'U'
ext_addr:
        inc     dptr
        movx    a,@dptr
        mov     r6,a                    ; adresteken
        mov     r5,#0                   ; 1 = rondzending, geen antwoord
        mov     dptr,#ADDR
        movx    a,@dptr
        add     a,#0x30
        xrl     a,r6
        jz      ext_go
        mov     a,r6
        cjne    a,#0x30,ext_exit
        mov     r5,#1
ext_go:
        lcall   enqueue
        jc      ext_exit                ; wachtrij vol: geen antwoord
        mov     a,r5
        jnz     ext_exit
        lcall   reply_ok
ext_exit:
        ljmp    DISPATCH_TAIL

; ruw telegram (tot en met CR) naar slot Q_HEAD; C = 1 als de wachtrij vol is
enqueue:
        mov     dptr,#Q_HEAD
        movx    a,@dptr
        anl     a,#1
        mov     r2,a                    ; head
        inc     a
        anl     a,#1
        mov     r3,a                    ; head + 1
        mov     dptr,#Q_TAIL
        movx    a,@dptr
        anl     a,#1
        xrl     a,r3
        jz      eq_full
        push    P2
        mov     a,r2
        add     a,r2
        add     a,#QBASE
        mov     P2,a                    ; doel via MOVX @R1 (P2 = hoge byte)
        mov     r1,#0
        mov     dptr,#BUF
eq_loop:
        movx    a,@dptr
        movx    @r1,a
        inc     dptr
        inc     r1
        cjne    r1,#0,eq_cr
        inc     P2
eq_cr:  cjne    a,#CR,eq_loop
        pop     P2
        mov     dptr,#Q_HEAD
        mov     a,r3
        movx    @dptr,a
        clr     c
        ret
eq_full:
        setb    c
        ret

; ---------- hoofdlus ----------
; vervangt MOV DPTR,#0571h op 0x2FD9: wachtrij niet leeg en geen ander verzoek -> REQ = 5
main_poll:
        mov     dptr,#Q_TAIL
        movx    a,@dptr
        mov     b,a
        mov     dptr,#Q_HEAD
        movx    a,@dptr
        xrl     a,b
        jz      mp_done
        mov     dptr,#REQ
        movx    a,@dptr
        jnz     mp_done                 ; testbeeld eerst afhandelen
        mov     a,#REQ_REFRESH
        movx    @dptr,a
mp_done:
        mov     dptr,#REQ
        ljmp    POLL_CONT

; omhulsel om de verversing (0x30E0)
refresh_wrap:
        mov     dptr,#REQ
        movx    a,@dptr
        cjne    a,#REQ_REFRESH,rw_plain
        lcall   q_process
        mov     dptr,#BM_FLAG
        movx    a,@dptr
        jz      rw_go                   ; bitmapmodus intussen beëindigd
        lcall   sh_to_fb
rw_go:
        setb    B_PARTIAL               ; alleen veranderde dots omzetten
        lcall   REFRESH
        clr     B_PARTIAL               ; geen wisseltekst meer
        ret
rw_plain:
        ljmp    REFRESH                 ; testbeeld: origineel gedrag

; alle wachtende telegrammen verwerken in de schaduw
q_process:
        mov     dptr,#Q_TAIL
        movx    a,@dptr
        anl     a,#1
        mov     r5,a                    ; tail
        mov     dptr,#Q_HEAD
        movx    a,@dptr
        anl     a,#1
        xrl     a,r5
        jz      qp_end
        lcall   bm_enter                ; schaduw = getoond beeld (eerste keer)
        mov     a,r5
        add     a,r5
        add     a,#QBASE
        mov     dph,a
        mov     dpl,#1
        movx    a,@dptr                 ; commando
        mov     b,a
        inc     dptr
        inc     dptr                    ; eerste dataveld
        mov     a,b
        cjne    a,#0x50,qp_1
        lcall   do_pixels
        sjmp    qp_next
qp_1:   cjne    a,#0x42,qp_2
        lcall   do_bitmap
        sjmp    qp_next
qp_2:   mov     dptr,#FULL_REQ          ; 'U'
        mov     a,#1
        movx    @dptr,a
qp_next:
        mov     a,r5
        inc     a
        anl     a,#1
        mov     dptr,#Q_TAIL
        movx    @dptr,a
        sjmp    q_process
qp_end:
        ret

; ---------- aP: pixels in de schaduw ----------
do_pixels:
        movx    a,@dptr
        cjne    a,#CR,px_go
        ret
px_go:
        lcall   getnum3
        jc      px_end
        mov     r4,a                    ; x
        lcall   getdig
        jc      px_end
        mov     b,#10
        mul     ab
        mov     r3,a
        lcall   getdig
        jc      px_end
        add     a,r3
        mov     r3,a                    ; y
        movx    a,@dptr
        inc     dptr
        xrl     a,#0x30                 ; '0' -> 0, '1' -> 1
        mov     r2,a
        clr     c
        subb    a,#2
        jnc     px_end
        push    dpl
        push    dph
        lcall   x_lt_width
        jnc     px_skip                 ; x >= breedte
        mov     dptr,#HEIGHT
        movx    a,@dptr
        mov     r1,a
        mov     a,r3
        clr     c
        subb    a,r1
        jnc     px_skip                 ; y >= hoogte
        mov     r6,#>SH
        mov     r7,#<SH
        lcall   colptr                  ; dptr = SH + 2*x (hoge byte)
        mov     a,r3
        clr     c
        subb    a,#8
        jnc     px_bit                  ; y >= 8: hoge byte, bit y-8
        inc     dptr                    ; y < 8: lage byte, bit y
        mov     a,r3
px_bit:
        mov     r1,a
        inc     r1
        mov     a,#0x80
px_shift:
        rl      a
        djnz    r1,px_shift             ; a = 1 << bit
        mov     r1,a
        movx    a,@dptr
        orl     a,r1
        cjne    r2,#0,px_store
        xrl     a,r1                    ; kleur 0: bit wissen
px_store:
        movx    @dptr,a
px_skip:
        pop     dph
        pop     dpl
        sjmp    do_pixels
px_end:
        ret

; ---------- aB: kolommen in de schaduw ----------
do_bitmap:
        lcall   getnum3
        jc      bm_end
        mov     r4,a                    ; startkolom
bm_loop:
        movx    a,@dptr
        cjne    a,#CR,bm_go
        ret
bm_go:
        lcall   gethex
        jc      bm_end
        swap    a
        mov     r3,a
        lcall   gethex
        jc      bm_end
        orl     a,r3
        mov     r3,a                    ; hoge byte (rij 8-15)
        lcall   gethex
        jc      bm_end
        swap    a
        mov     r2,a
        lcall   gethex
        jc      bm_end
        orl     a,r2
        mov     r2,a                    ; lage byte (rij 0-7)
        push    dpl
        push    dph
        lcall   x_lt_width
        jnc     bm_skip
        mov     r6,#>SH
        mov     r7,#<SH
        lcall   colptr
        mov     a,r3
        movx    @dptr,a
        inc     dptr
        mov     a,r2
        movx    @dptr,a
bm_skip:
        pop     dph
        pop     dpl
        inc     r4
        sjmp    bm_loop
bm_end:
        ret

; ---------- bitmapmodus starten: schaduw := getoond beeld ----------
bm_enter:
        mov     dptr,#BM_FLAG
        movx    a,@dptr
        jnz     be_done
        mov     a,#1
        movx    @dptr,a
        mov     r4,#0
be_loop:
        lcall   x_lt_width
        jnc     be_done
        mov     r6,#>FB_OLD
        mov     r7,#<FB_OLD
        lcall   colptr
        movx    a,@dptr
        mov     r3,a
        inc     dptr
        movx    a,@dptr
        mov     r2,a
        mov     r6,#>SH
        mov     r7,#<SH
        lcall   colptr
        mov     a,r3
        movx    @dptr,a
        inc     dptr
        mov     a,r2
        movx    @dptr,a
        inc     r4
        sjmp    be_loop
be_done:
        ret

; schaduw -> gewenst beeld; bij FULL_REQ: getoond := NOT gewenst (alles verschilt)
sh_to_fb:
        mov     r4,#0
sf_loop:
        lcall   x_lt_width
        jnc     sf_full
        mov     r6,#>SH
        mov     r7,#<SH
        lcall   colptr
        movx    a,@dptr
        mov     r3,a
        inc     dptr
        movx    a,@dptr
        mov     r2,a
        mov     r6,#>FB_NEW
        mov     r7,#<FB_NEW
        lcall   colptr
        mov     a,r3
        movx    @dptr,a
        inc     dptr
        mov     a,r2
        movx    @dptr,a
        inc     r4
        sjmp    sf_loop
sf_full:
        mov     dptr,#FULL_REQ
        movx    a,@dptr
        jz      sf_end
        clr     a
        movx    @dptr,a
        mov     r4,#0
sf_inv:
        lcall   x_lt_width
        jnc     sf_end
        mov     r6,#>FB_NEW
        mov     r7,#<FB_NEW
        lcall   colptr
        movx    a,@dptr
        cpl     a
        mov     r3,a
        inc     dptr
        movx    a,@dptr
        cpl     a
        mov     r2,a
        mov     r6,#>FB_OLD
        mov     r7,#<FB_OLD
        lcall   colptr
        mov     a,r3
        movx    @dptr,a
        inc     dptr
        mov     a,r2
        movx    @dptr,a
        inc     r4
        sjmp    sf_inv
sf_end:
        ret

; ---------- hulproutines ----------
; C = 1 als r4 < breedte (gebruikt dptr, r1)
x_lt_width:
        mov     dptr,#WIDTH
        movx    a,@dptr
        mov     r1,a
        mov     a,r4
        clr     c
        subb    a,r1
        ret

; dptr = (r6:r7) + 2*r4
colptr:
        mov     a,r4
        add     a,r4
        mov     r0,a
        clr     a
        rlc     a
        xch     a,r0                    ; a = laag, r0 = hoog
        add     a,r7
        mov     dpl,a
        mov     a,r0
        addc    a,r6
        mov     dph,a
        ret

; cijfer op @dptr -> a (0..9), dptr++; C = 1 als geen cijfer
getdig:
        movx    a,@dptr
        inc     dptr
        clr     c
        subb    a,#0x30
        jc      gd_bad
        cjne    a,#10,gd_cmp
gd_cmp: cpl     c                       ; C was 1 als a < 10
        ret
gd_bad: setb    c
        ret

; drie cijfers -> a (0..255); C = 1 bij fout of > 255
getnum3:
        lcall   getdig
        jc      gn_bad
        mov     b,#100
        mul     ab
        mov     r0,a
        mov     a,b
        jnz     gn_bad
        lcall   getdig
        jc      gn_bad
        mov     b,#10
        mul     ab
        add     a,r0
        jc      gn_bad
        mov     r0,a
        lcall   getdig
        jc      gn_bad
        add     a,r0
        ret                             ; C uit add: 1 bij overloop
gn_bad: setb    c
        ret

; hexteken op @dptr -> a (0..15), dptr++; C = 1 als ongeldig
gethex:
        movx    a,@dptr
        inc     dptr
        clr     c
        subb    a,#0x30
        jc      gh_bad
        cjne    a,#10,gh_c1
gh_c1:  jc      gh_ok                   ; '0'..'9'
        clr     c
        subb    a,#17                   ; 'A' -> 0
        jc      gh_bad
        cjne    a,#6,gh_c2
gh_c2:  jc      gh_let                  ; 'A'..'F'
        clr     c
        subb    a,#32                   ; 'a' -> 0
        jc      gh_bad
        cjne    a,#6,gh_c3
gh_c3:  jnc     gh_bad
gh_let: add     a,#10
gh_ok:  clr     c
        ret
gh_bad: setb    c
        ret

; antwoord "a0" + CR + checksum, zoals ASFP bij statusvragen doet
reply_ok:
        mov     dptr,#TXBUF
        mov     a,#0x61
        movx    @dptr,a
        inc     dptr
        mov     a,#0x30
        movx    @dptr,a
        inc     dptr
        mov     a,#CR
        movx    @dptr,a
        mov     LEN_CS,#3
        lcall   REPLY_CS
        mov     dptr,#TXLEN
        mov     a,#4
        movx    @dptr,a
        setb    B_TXBUSY
        mov     dptr,#TXIDX
        clr     a
        movx    @dptr,a
        setb    B_TI
        ret
