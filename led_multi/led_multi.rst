                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module led_multi
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _delay
                                     13 	.globl _CY
                                     14 	.globl _AC
                                     15 	.globl _F0
                                     16 	.globl _RS1
                                     17 	.globl _RS0
                                     18 	.globl _OV
                                     19 	.globl _F1
                                     20 	.globl _P
                                     21 	.globl _PS
                                     22 	.globl _PT1
                                     23 	.globl _PX1
                                     24 	.globl _PT0
                                     25 	.globl _PX0
                                     26 	.globl _RD
                                     27 	.globl _WR
                                     28 	.globl _T1
                                     29 	.globl _T0
                                     30 	.globl _INT1
                                     31 	.globl _INT0
                                     32 	.globl _TXD
                                     33 	.globl _RXD
                                     34 	.globl _P3_7
                                     35 	.globl _P3_6
                                     36 	.globl _P3_5
                                     37 	.globl _P3_4
                                     38 	.globl _P3_3
                                     39 	.globl _P3_2
                                     40 	.globl _P3_1
                                     41 	.globl _P3_0
                                     42 	.globl _EA
                                     43 	.globl _ES
                                     44 	.globl _ET1
                                     45 	.globl _EX1
                                     46 	.globl _ET0
                                     47 	.globl _EX0
                                     48 	.globl _P2_7
                                     49 	.globl _P2_6
                                     50 	.globl _P2_5
                                     51 	.globl _P2_4
                                     52 	.globl _P2_3
                                     53 	.globl _P2_2
                                     54 	.globl _P2_1
                                     55 	.globl _P2_0
                                     56 	.globl _SM0
                                     57 	.globl _SM1
                                     58 	.globl _SM2
                                     59 	.globl _REN
                                     60 	.globl _TB8
                                     61 	.globl _RB8
                                     62 	.globl _TI
                                     63 	.globl _RI
                                     64 	.globl _P1_7
                                     65 	.globl _P1_6
                                     66 	.globl _P1_5
                                     67 	.globl _P1_4
                                     68 	.globl _P1_3
                                     69 	.globl _P1_2
                                     70 	.globl _P1_1
                                     71 	.globl _P1_0
                                     72 	.globl _TF1
                                     73 	.globl _TR1
                                     74 	.globl _TF0
                                     75 	.globl _TR0
                                     76 	.globl _IE1
                                     77 	.globl _IT1
                                     78 	.globl _IE0
                                     79 	.globl _IT0
                                     80 	.globl _P0_7
                                     81 	.globl _P0_6
                                     82 	.globl _P0_5
                                     83 	.globl _P0_4
                                     84 	.globl _P0_3
                                     85 	.globl _P0_2
                                     86 	.globl _P0_1
                                     87 	.globl _P0_0
                                     88 	.globl _B
                                     89 	.globl _ACC
                                     90 	.globl _PSW
                                     91 	.globl _IP
                                     92 	.globl _P3
                                     93 	.globl _IE
                                     94 	.globl _P2
                                     95 	.globl _SBUF
                                     96 	.globl _SCON
                                     97 	.globl _P1
                                     98 	.globl _TH1
                                     99 	.globl _TH0
                                    100 	.globl _TL1
                                    101 	.globl _TL0
                                    102 	.globl _TMOD
                                    103 	.globl _TCON
                                    104 	.globl _PCON
                                    105 	.globl _DPH
                                    106 	.globl _DPL
                                    107 	.globl _SP
                                    108 	.globl _P0
                                    109 	.globl _seg
                                    110 ;--------------------------------------------------------
                                    111 ; special function registers
                                    112 ;--------------------------------------------------------
                                    113 	.area RSEG    (ABS,DATA)
      000000                        114 	.org 0x0000
                           000080   115 _P0	=	0x0080
                           000081   116 _SP	=	0x0081
                           000082   117 _DPL	=	0x0082
                           000083   118 _DPH	=	0x0083
                           000087   119 _PCON	=	0x0087
                           000088   120 _TCON	=	0x0088
                           000089   121 _TMOD	=	0x0089
                           00008A   122 _TL0	=	0x008a
                           00008B   123 _TL1	=	0x008b
                           00008C   124 _TH0	=	0x008c
                           00008D   125 _TH1	=	0x008d
                           000090   126 _P1	=	0x0090
                           000098   127 _SCON	=	0x0098
                           000099   128 _SBUF	=	0x0099
                           0000A0   129 _P2	=	0x00a0
                           0000A8   130 _IE	=	0x00a8
                           0000B0   131 _P3	=	0x00b0
                           0000B8   132 _IP	=	0x00b8
                           0000D0   133 _PSW	=	0x00d0
                           0000E0   134 _ACC	=	0x00e0
                           0000F0   135 _B	=	0x00f0
                                    136 ;--------------------------------------------------------
                                    137 ; special function bits
                                    138 ;--------------------------------------------------------
                                    139 	.area RSEG    (ABS,DATA)
      000000                        140 	.org 0x0000
                           000080   141 _P0_0	=	0x0080
                           000081   142 _P0_1	=	0x0081
                           000082   143 _P0_2	=	0x0082
                           000083   144 _P0_3	=	0x0083
                           000084   145 _P0_4	=	0x0084
                           000085   146 _P0_5	=	0x0085
                           000086   147 _P0_6	=	0x0086
                           000087   148 _P0_7	=	0x0087
                           000088   149 _IT0	=	0x0088
                           000089   150 _IE0	=	0x0089
                           00008A   151 _IT1	=	0x008a
                           00008B   152 _IE1	=	0x008b
                           00008C   153 _TR0	=	0x008c
                           00008D   154 _TF0	=	0x008d
                           00008E   155 _TR1	=	0x008e
                           00008F   156 _TF1	=	0x008f
                           000090   157 _P1_0	=	0x0090
                           000091   158 _P1_1	=	0x0091
                           000092   159 _P1_2	=	0x0092
                           000093   160 _P1_3	=	0x0093
                           000094   161 _P1_4	=	0x0094
                           000095   162 _P1_5	=	0x0095
                           000096   163 _P1_6	=	0x0096
                           000097   164 _P1_7	=	0x0097
                           000098   165 _RI	=	0x0098
                           000099   166 _TI	=	0x0099
                           00009A   167 _RB8	=	0x009a
                           00009B   168 _TB8	=	0x009b
                           00009C   169 _REN	=	0x009c
                           00009D   170 _SM2	=	0x009d
                           00009E   171 _SM1	=	0x009e
                           00009F   172 _SM0	=	0x009f
                           0000A0   173 _P2_0	=	0x00a0
                           0000A1   174 _P2_1	=	0x00a1
                           0000A2   175 _P2_2	=	0x00a2
                           0000A3   176 _P2_3	=	0x00a3
                           0000A4   177 _P2_4	=	0x00a4
                           0000A5   178 _P2_5	=	0x00a5
                           0000A6   179 _P2_6	=	0x00a6
                           0000A7   180 _P2_7	=	0x00a7
                           0000A8   181 _EX0	=	0x00a8
                           0000A9   182 _ET0	=	0x00a9
                           0000AA   183 _EX1	=	0x00aa
                           0000AB   184 _ET1	=	0x00ab
                           0000AC   185 _ES	=	0x00ac
                           0000AF   186 _EA	=	0x00af
                           0000B0   187 _P3_0	=	0x00b0
                           0000B1   188 _P3_1	=	0x00b1
                           0000B2   189 _P3_2	=	0x00b2
                           0000B3   190 _P3_3	=	0x00b3
                           0000B4   191 _P3_4	=	0x00b4
                           0000B5   192 _P3_5	=	0x00b5
                           0000B6   193 _P3_6	=	0x00b6
                           0000B7   194 _P3_7	=	0x00b7
                           0000B0   195 _RXD	=	0x00b0
                           0000B1   196 _TXD	=	0x00b1
                           0000B2   197 _INT0	=	0x00b2
                           0000B3   198 _INT1	=	0x00b3
                           0000B4   199 _T0	=	0x00b4
                           0000B5   200 _T1	=	0x00b5
                           0000B6   201 _WR	=	0x00b6
                           0000B7   202 _RD	=	0x00b7
                           0000B8   203 _PX0	=	0x00b8
                           0000B9   204 _PT0	=	0x00b9
                           0000BA   205 _PX1	=	0x00ba
                           0000BB   206 _PT1	=	0x00bb
                           0000BC   207 _PS	=	0x00bc
                           0000D0   208 _P	=	0x00d0
                           0000D1   209 _F1	=	0x00d1
                           0000D2   210 _OV	=	0x00d2
                           0000D3   211 _RS0	=	0x00d3
                           0000D4   212 _RS1	=	0x00d4
                           0000D5   213 _F0	=	0x00d5
                           0000D6   214 _AC	=	0x00d6
                           0000D7   215 _CY	=	0x00d7
                                    216 ;--------------------------------------------------------
                                    217 ; overlayable register banks
                                    218 ;--------------------------------------------------------
                                    219 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        220 	.ds 8
                                    221 ;--------------------------------------------------------
                                    222 ; internal ram data
                                    223 ;--------------------------------------------------------
                                    224 	.area DSEG    (DATA)
      000008                        225 _seg::
      000008                        226 	.ds 32
                                    227 ;--------------------------------------------------------
                                    228 ; overlayable items in internal ram 
                                    229 ;--------------------------------------------------------
                                    230 	.area	OSEG    (OVR,DATA)
                                    231 ;--------------------------------------------------------
                                    232 ; Stack segment in internal ram 
                                    233 ;--------------------------------------------------------
                                    234 	.area	SSEG
      000028                        235 __start__stack:
      000028                        236 	.ds	1
                                    237 
                                    238 ;--------------------------------------------------------
                                    239 ; indirectly addressable internal ram data
                                    240 ;--------------------------------------------------------
                                    241 	.area ISEG    (DATA)
                                    242 ;--------------------------------------------------------
                                    243 ; absolute internal ram data
                                    244 ;--------------------------------------------------------
                                    245 	.area IABS    (ABS,DATA)
                                    246 	.area IABS    (ABS,DATA)
                                    247 ;--------------------------------------------------------
                                    248 ; bit data
                                    249 ;--------------------------------------------------------
                                    250 	.area BSEG    (BIT)
                                    251 ;--------------------------------------------------------
                                    252 ; paged external ram data
                                    253 ;--------------------------------------------------------
                                    254 	.area PSEG    (PAG,XDATA)
                                    255 ;--------------------------------------------------------
                                    256 ; external ram data
                                    257 ;--------------------------------------------------------
                                    258 	.area XSEG    (XDATA)
                                    259 ;--------------------------------------------------------
                                    260 ; absolute external ram data
                                    261 ;--------------------------------------------------------
                                    262 	.area XABS    (ABS,XDATA)
                                    263 ;--------------------------------------------------------
                                    264 ; external initialized ram data
                                    265 ;--------------------------------------------------------
                                    266 	.area XISEG   (XDATA)
                                    267 	.area HOME    (CODE)
                                    268 	.area GSINIT0 (CODE)
                                    269 	.area GSINIT1 (CODE)
                                    270 	.area GSINIT2 (CODE)
                                    271 	.area GSINIT3 (CODE)
                                    272 	.area GSINIT4 (CODE)
                                    273 	.area GSINIT5 (CODE)
                                    274 	.area GSINIT  (CODE)
                                    275 	.area GSFINAL (CODE)
                                    276 	.area CSEG    (CODE)
                                    277 ;--------------------------------------------------------
                                    278 ; interrupt vector 
                                    279 ;--------------------------------------------------------
                                    280 	.area HOME    (CODE)
      000000                        281 __interrupt_vect:
      000000 02 00 06         [24]  282 	ljmp	__sdcc_gsinit_startup
                                    283 ;--------------------------------------------------------
                                    284 ; global & static initialisations
                                    285 ;--------------------------------------------------------
                                    286 	.area HOME    (CODE)
                                    287 	.area GSINIT  (CODE)
                                    288 	.area GSFINAL (CODE)
                                    289 	.area GSINIT  (CODE)
                                    290 	.globl __sdcc_gsinit_startup
                                    291 	.globl __sdcc_program_startup
                                    292 	.globl __start__stack
                                    293 	.globl __mcs51_genXINIT
                                    294 	.globl __mcs51_genXRAMCLEAR
                                    295 	.globl __mcs51_genRAMCLEAR
                                    296 ;	led_multi.c:3: unsigned int seg[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff,0xff,0x00,0,0x55,0x55,0xaa,0xaa};//rom允许情况可以无限添加
      00005F 75 08 7F         [24]  297 	mov	(_seg + 0),#0x7f
      000062 75 09 00         [24]  298 	mov	(_seg + 1),#0x00
      000065 75 0A BF         [24]  299 	mov	((_seg + 0x0002) + 0),#0xbf
      000068 75 0B 00         [24]  300 	mov	((_seg + 0x0002) + 1),#0x00
      00006B 75 0C DF         [24]  301 	mov	((_seg + 0x0004) + 0),#0xdf
      00006E 75 0D 00         [24]  302 	mov	((_seg + 0x0004) + 1),#0x00
      000071 75 0E EF         [24]  303 	mov	((_seg + 0x0006) + 0),#0xef
      000074 75 0F 00         [24]  304 	mov	((_seg + 0x0006) + 1),#0x00
      000077 75 10 F7         [24]  305 	mov	((_seg + 0x0008) + 0),#0xf7
      00007A 75 11 00         [24]  306 	mov	((_seg + 0x0008) + 1),#0x00
      00007D 75 12 FB         [24]  307 	mov	((_seg + 0x000a) + 0),#0xfb
      000080 75 13 00         [24]  308 	mov	((_seg + 0x000a) + 1),#0x00
      000083 75 14 FD         [24]  309 	mov	((_seg + 0x000c) + 0),#0xfd
      000086 75 15 00         [24]  310 	mov	((_seg + 0x000c) + 1),#0x00
      000089 75 16 FE         [24]  311 	mov	((_seg + 0x000e) + 0),#0xfe
      00008C 75 17 00         [24]  312 	mov	((_seg + 0x000e) + 1),#0x00
      00008F 75 18 FF         [24]  313 	mov	((_seg + 0x0010) + 0),#0xff
      000092 75 19 00         [24]  314 	mov	((_seg + 0x0010) + 1),#0x00
      000095 75 1A FF         [24]  315 	mov	((_seg + 0x0012) + 0),#0xff
      000098 E4               [12]  316 	clr	a
      000099 F5 1B            [12]  317 	mov	((_seg + 0x0012) + 1),a
      00009B F5 1C            [12]  318 	mov	((_seg + 0x0014) + 0),a
      00009D F5 1D            [12]  319 	mov	((_seg + 0x0014) + 1),a
      00009F F5 1E            [12]  320 	mov	((_seg + 0x0016) + 0),a
      0000A1 F5 1F            [12]  321 	mov	((_seg + 0x0016) + 1),a
      0000A3 75 20 55         [24]  322 	mov	((_seg + 0x0018) + 0),#0x55
                                    323 ;	1-genFromRTrack replaced	mov	((_seg + 0x0018) + 1),#0x00
      0000A6 F5 21            [12]  324 	mov	((_seg + 0x0018) + 1),a
      0000A8 75 22 55         [24]  325 	mov	((_seg + 0x001a) + 0),#0x55
                                    326 ;	1-genFromRTrack replaced	mov	((_seg + 0x001a) + 1),#0x00
      0000AB F5 23            [12]  327 	mov	((_seg + 0x001a) + 1),a
      0000AD 75 24 AA         [24]  328 	mov	((_seg + 0x001c) + 0),#0xaa
                                    329 ;	1-genFromRTrack replaced	mov	((_seg + 0x001c) + 1),#0x00
      0000B0 F5 25            [12]  330 	mov	((_seg + 0x001c) + 1),a
      0000B2 75 26 AA         [24]  331 	mov	((_seg + 0x001e) + 0),#0xaa
                                    332 ;	1-genFromRTrack replaced	mov	((_seg + 0x001e) + 1),#0x00
      0000B5 F5 27            [12]  333 	mov	((_seg + 0x001e) + 1),a
                                    334 	.area GSFINAL (CODE)
      0000B7 02 00 03         [24]  335 	ljmp	__sdcc_program_startup
                                    336 ;--------------------------------------------------------
                                    337 ; Home
                                    338 ;--------------------------------------------------------
                                    339 	.area HOME    (CODE)
                                    340 	.area HOME    (CODE)
      000003                        341 __sdcc_program_startup:
      000003 02 00 E3         [24]  342 	ljmp	_main
                                    343 ;	return from main will return to caller
                                    344 ;--------------------------------------------------------
                                    345 ; code
                                    346 ;--------------------------------------------------------
                                    347 	.area CSEG    (CODE)
                                    348 ;------------------------------------------------------------
                                    349 ;Allocation info for local variables in function 'delay'
                                    350 ;------------------------------------------------------------
                                    351 ;i                         Allocated to registers r4 r5 
                                    352 ;loop                      Allocated to registers r6 r7 
                                    353 ;------------------------------------------------------------
                                    354 ;	led_multi.c:5: void delay() {
                                    355 ;	-----------------------------------------
                                    356 ;	 function delay
                                    357 ;	-----------------------------------------
      0000BA                        358 _delay:
                           000007   359 	ar7 = 0x07
                           000006   360 	ar6 = 0x06
                           000005   361 	ar5 = 0x05
                           000004   362 	ar4 = 0x04
                           000003   363 	ar3 = 0x03
                           000002   364 	ar2 = 0x02
                           000001   365 	ar1 = 0x01
                           000000   366 	ar0 = 0x00
                                    367 ;	led_multi.c:6: unsigned int i = 512, loop = 10240;
      0000BA 7E 00            [12]  368 	mov	r6,#0x00
      0000BC 7F 28            [12]  369 	mov	r7,#0x28
      0000BE 7C 00            [12]  370 	mov	r4,#0x00
      0000C0 7D 02            [12]  371 	mov	r5,#0x02
      0000C2                        372 00107$:
                                    373 ;	led_multi.c:7: for (; i>0; i--){
      0000C2 EC               [12]  374 	mov	a,r4
      0000C3 4D               [12]  375 	orl	a,r5
      0000C4 60 1C            [24]  376 	jz	00109$
      0000C6 8E 02            [24]  377 	mov	ar2,r6
      0000C8 8F 03            [24]  378 	mov	ar3,r7
      0000CA                        379 00104$:
                                    380 ;	led_multi.c:8: for (;loop>0;loop--) {
      0000CA EA               [12]  381 	mov	a,r2
      0000CB 4B               [12]  382 	orl	a,r3
      0000CC 70 06            [24]  383 	jnz	00105$
      0000CE 8A 06            [24]  384 	mov	ar6,r2
      0000D0 8B 07            [24]  385 	mov	ar7,r3
      0000D2 80 07            [24]  386 	sjmp	00108$
      0000D4                        387 00105$:
      0000D4 1A               [12]  388 	dec	r2
      0000D5 BA FF 01         [24]  389 	cjne	r2,#0xff,00135$
      0000D8 1B               [12]  390 	dec	r3
      0000D9                        391 00135$:
      0000D9 80 EF            [24]  392 	sjmp	00104$
      0000DB                        393 00108$:
                                    394 ;	led_multi.c:7: for (; i>0; i--){
      0000DB 1C               [12]  395 	dec	r4
      0000DC BC FF 01         [24]  396 	cjne	r4,#0xff,00136$
      0000DF 1D               [12]  397 	dec	r5
      0000E0                        398 00136$:
      0000E0 80 E0            [24]  399 	sjmp	00107$
      0000E2                        400 00109$:
                                    401 ;	led_multi.c:12: }
      0000E2 22               [24]  402 	ret
                                    403 ;------------------------------------------------------------
                                    404 ;Allocation info for local variables in function 'main'
                                    405 ;------------------------------------------------------------
                                    406 ;i                         Allocated to registers r6 r7 
                                    407 ;------------------------------------------------------------
                                    408 ;	led_multi.c:14: void main(){
                                    409 ;	-----------------------------------------
                                    410 ;	 function main
                                    411 ;	-----------------------------------------
      0000E3                        412 _main:
                                    413 ;	led_multi.c:16: while(1)
      0000E3                        414 00107$:
                                    415 ;	led_multi.c:18: P0=0xFE;//第一个LED亮
      0000E3 75 80 FE         [24]  416 	mov	_P0,#0xfe
                                    417 ;	led_multi.c:19: for(i=0;i<8;i++)
      0000E6 7E 00            [12]  418 	mov	r6,#0x00
      0000E8 7F 00            [12]  419 	mov	r7,#0x00
      0000EA                        420 00109$:
                                    421 ;	led_multi.c:21: delay();
      0000EA C0 07            [24]  422 	push	ar7
      0000EC C0 06            [24]  423 	push	ar6
      0000EE 12 00 BA         [24]  424 	lcall	_delay
      0000F1 D0 06            [24]  425 	pop	ar6
      0000F3 D0 07            [24]  426 	pop	ar7
                                    427 ;	led_multi.c:22: P0 <<=1;
      0000F5 E5 80            [12]  428 	mov	a,_P0
      0000F7 FD               [12]  429 	mov	r5,a
      0000F8 25 E0            [12]  430 	add	a,acc
      0000FA F5 80            [12]  431 	mov	_P0,a
                                    432 ;	led_multi.c:19: for(i=0;i<8;i++)
      0000FC 0E               [12]  433 	inc	r6
      0000FD BE 00 01         [24]  434 	cjne	r6,#0x00,00170$
      000100 0F               [12]  435 	inc	r7
      000101                        436 00170$:
      000101 C3               [12]  437 	clr	c
      000102 EE               [12]  438 	mov	a,r6
      000103 94 08            [12]  439 	subb	a,#0x08
      000105 EF               [12]  440 	mov	a,r7
      000106 94 00            [12]  441 	subb	a,#0x00
      000108 40 E0            [24]  442 	jc	00109$
                                    443 ;	led_multi.c:25: P0=0x7F;//第七个LED亮
      00010A 75 80 7F         [24]  444 	mov	_P0,#0x7f
                                    445 ;	led_multi.c:26: for(i=0;i<8;i++)
      00010D 7E 00            [12]  446 	mov	r6,#0x00
      00010F 7F 00            [12]  447 	mov	r7,#0x00
      000111                        448 00111$:
                                    449 ;	led_multi.c:28: delay();
      000111 C0 07            [24]  450 	push	ar7
      000113 C0 06            [24]  451 	push	ar6
      000115 12 00 BA         [24]  452 	lcall	_delay
      000118 D0 06            [24]  453 	pop	ar6
      00011A D0 07            [24]  454 	pop	ar7
                                    455 ;	led_multi.c:29: P0 >>=1;
      00011C E5 80            [12]  456 	mov	a,_P0
      00011E C3               [12]  457 	clr	c
      00011F 13               [12]  458 	rrc	a
      000120 F5 80            [12]  459 	mov	_P0,a
                                    460 ;	led_multi.c:26: for(i=0;i<8;i++)
      000122 0E               [12]  461 	inc	r6
      000123 BE 00 01         [24]  462 	cjne	r6,#0x00,00172$
      000126 0F               [12]  463 	inc	r7
      000127                        464 00172$:
      000127 C3               [12]  465 	clr	c
      000128 EE               [12]  466 	mov	a,r6
      000129 94 08            [12]  467 	subb	a,#0x08
      00012B EF               [12]  468 	mov	a,r7
      00012C 94 00            [12]  469 	subb	a,#0x00
      00012E 40 E1            [24]  470 	jc	00111$
                                    471 ;	led_multi.c:32: P0=0xFE;//第一个LED亮
      000130 75 80 FE         [24]  472 	mov	_P0,#0xfe
                                    473 ;	led_multi.c:33: for(i=0;i<8;i++)
      000133 7E 00            [12]  474 	mov	r6,#0x00
      000135 7F 00            [12]  475 	mov	r7,#0x00
      000137                        476 00113$:
                                    477 ;	led_multi.c:35: delay();
      000137 C0 07            [24]  478 	push	ar7
      000139 C0 06            [24]  479 	push	ar6
      00013B 12 00 BA         [24]  480 	lcall	_delay
      00013E D0 06            [24]  481 	pop	ar6
      000140 D0 07            [24]  482 	pop	ar7
                                    483 ;	led_multi.c:36: P0 <<=1;
      000142 E5 80            [12]  484 	mov	a,_P0
      000144 25 E0            [12]  485 	add	a,acc
      000146 F5 80            [12]  486 	mov	_P0,a
                                    487 ;	led_multi.c:37: P0 |=0x01;
      000148 AC 80            [24]  488 	mov	r4,_P0
      00014A 7D 00            [12]  489 	mov	r5,#0x00
      00014C 43 04 01         [24]  490 	orl	ar4,#0x01
      00014F 8C 80            [24]  491 	mov	_P0,r4
                                    492 ;	led_multi.c:33: for(i=0;i<8;i++)
      000151 0E               [12]  493 	inc	r6
      000152 BE 00 01         [24]  494 	cjne	r6,#0x00,00174$
      000155 0F               [12]  495 	inc	r7
      000156                        496 00174$:
      000156 C3               [12]  497 	clr	c
      000157 EE               [12]  498 	mov	a,r6
      000158 94 08            [12]  499 	subb	a,#0x08
      00015A EF               [12]  500 	mov	a,r7
      00015B 94 00            [12]  501 	subb	a,#0x00
      00015D 40 D8            [24]  502 	jc	00113$
                                    503 ;	led_multi.c:40: P0=0x7F;//第七个LED亮
      00015F 75 80 7F         [24]  504 	mov	_P0,#0x7f
                                    505 ;	led_multi.c:41: for(i=0;i<8;i++)
      000162 7E 00            [12]  506 	mov	r6,#0x00
      000164 7F 00            [12]  507 	mov	r7,#0x00
      000166                        508 00115$:
                                    509 ;	led_multi.c:43: delay();
      000166 C0 07            [24]  510 	push	ar7
      000168 C0 06            [24]  511 	push	ar6
      00016A 12 00 BA         [24]  512 	lcall	_delay
      00016D D0 06            [24]  513 	pop	ar6
      00016F D0 07            [24]  514 	pop	ar7
                                    515 ;	led_multi.c:44: P0 >>=1;
      000171 E5 80            [12]  516 	mov	a,_P0
      000173 C3               [12]  517 	clr	c
      000174 13               [12]  518 	rrc	a
      000175 F5 80            [12]  519 	mov	_P0,a
                                    520 ;	led_multi.c:45: P0 |=0x80;
      000177 AC 80            [24]  521 	mov	r4,_P0
      000179 7D 00            [12]  522 	mov	r5,#0x00
      00017B 43 04 80         [24]  523 	orl	ar4,#0x80
      00017E 8C 80            [24]  524 	mov	_P0,r4
                                    525 ;	led_multi.c:41: for(i=0;i<8;i++)
      000180 0E               [12]  526 	inc	r6
      000181 BE 00 01         [24]  527 	cjne	r6,#0x00,00176$
      000184 0F               [12]  528 	inc	r7
      000185                        529 00176$:
      000185 C3               [12]  530 	clr	c
      000186 EE               [12]  531 	mov	a,r6
      000187 94 08            [12]  532 	subb	a,#0x08
      000189 EF               [12]  533 	mov	a,r7
      00018A 94 00            [12]  534 	subb	a,#0x00
      00018C 40 D8            [24]  535 	jc	00115$
                                    536 ;	led_multi.c:48: for(i=0;i<16;i++)//查表可以简单的显示各种花样 实用性更强
      00018E 7E 00            [12]  537 	mov	r6,#0x00
      000190 7F 00            [12]  538 	mov	r7,#0x00
      000192                        539 00117$:
                                    540 ;	led_multi.c:50: delay();
      000192 C0 07            [24]  541 	push	ar7
      000194 C0 06            [24]  542 	push	ar6
      000196 12 00 BA         [24]  543 	lcall	_delay
      000199 D0 06            [24]  544 	pop	ar6
      00019B D0 07            [24]  545 	pop	ar7
                                    546 ;	led_multi.c:51: P0=seg[i];
      00019D EE               [12]  547 	mov	a,r6
      00019E 2E               [12]  548 	add	a,r6
      00019F FC               [12]  549 	mov	r4,a
      0001A0 EF               [12]  550 	mov	a,r7
      0001A1 33               [12]  551 	rlc	a
      0001A2 FD               [12]  552 	mov	r5,a
      0001A3 EC               [12]  553 	mov	a,r4
      0001A4 24 08            [12]  554 	add	a,#_seg
      0001A6 F9               [12]  555 	mov	r1,a
      0001A7 87 80            [24]  556 	mov	_P0,@r1
                                    557 ;	led_multi.c:48: for(i=0;i<16;i++)//查表可以简单的显示各种花样 实用性更强
      0001A9 0E               [12]  558 	inc	r6
      0001AA BE 00 01         [24]  559 	cjne	r6,#0x00,00178$
      0001AD 0F               [12]  560 	inc	r7
      0001AE                        561 00178$:
      0001AE C3               [12]  562 	clr	c
      0001AF EE               [12]  563 	mov	a,r6
      0001B0 94 10            [12]  564 	subb	a,#0x10
      0001B2 EF               [12]  565 	mov	a,r7
      0001B3 94 00            [12]  566 	subb	a,#0x00
      0001B5 40 DB            [24]  567 	jc	00117$
                                    568 ;	led_multi.c:54: }
      0001B7 02 00 E3         [24]  569 	ljmp	00107$
                                    570 	.area CSEG    (CODE)
                                    571 	.area CONST   (CODE)
                                    572 	.area XINIT   (CODE)
                                    573 	.area CABS    (ABS,CODE)
