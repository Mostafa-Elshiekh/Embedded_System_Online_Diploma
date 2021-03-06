
.\learn-in-depth-cortex-m3.elf:     file format elf32-littlearm


Disassembly of section .text:

08000000 <vectors>:
 8000000:	20001000 	andcs	r1, r0, r0
 8000004:	080000bd 	stmdaeq	r0, {r0, r2, r3, r4, r5, r7}
 8000008:	0800001d 	stmdaeq	r0, {r0, r2, r3, r4}
 800000c:	08000029 	stmdaeq	r0, {r0, r3, r5}
 8000010:	080000b1 	stmdaeq	r0, {r0, r4, r5, r7}
 8000014:	080000b1 	stmdaeq	r0, {r0, r4, r5, r7}
 8000018:	080000b1 	stmdaeq	r0, {r0, r4, r5, r7}

0800001c <NMI_Handler>:
 800001c:	b480      	push	{r7}
 800001e:	af00      	add	r7, sp, #0
 8000020:	bf00      	nop
 8000022:	46bd      	mov	sp, r7
 8000024:	bc80      	pop	{r7}
 8000026:	4770      	bx	lr

08000028 <H_fault_Handler>:
 8000028:	b480      	push	{r7}
 800002a:	af00      	add	r7, sp, #0
 800002c:	bf00      	nop
 800002e:	46bd      	mov	sp, r7
 8000030:	bc80      	pop	{r7}
 8000032:	4770      	bx	lr

08000034 <main>:
 8000034:	b480      	push	{r7}
 8000036:	b083      	sub	sp, #12
 8000038:	af00      	add	r7, sp, #0
 800003a:	4b1a      	ldr	r3, [pc, #104]	; (80000a4 <main+0x70>)
 800003c:	681b      	ldr	r3, [r3, #0]
 800003e:	4a19      	ldr	r2, [pc, #100]	; (80000a4 <main+0x70>)
 8000040:	f043 0304 	orr.w	r3, r3, #4
 8000044:	6013      	str	r3, [r2, #0]
 8000046:	4b18      	ldr	r3, [pc, #96]	; (80000a8 <main+0x74>)
 8000048:	681b      	ldr	r3, [r3, #0]
 800004a:	4a17      	ldr	r2, [pc, #92]	; (80000a8 <main+0x74>)
 800004c:	f423 0370 	bic.w	r3, r3, #15728640	; 0xf00000
 8000050:	6013      	str	r3, [r2, #0]
 8000052:	4b15      	ldr	r3, [pc, #84]	; (80000a8 <main+0x74>)
 8000054:	681b      	ldr	r3, [r3, #0]
 8000056:	4a14      	ldr	r2, [pc, #80]	; (80000a8 <main+0x74>)
 8000058:	f443 1300 	orr.w	r3, r3, #2097152	; 0x200000
 800005c:	6013      	str	r3, [r2, #0]
 800005e:	4b13      	ldr	r3, [pc, #76]	; (80000ac <main+0x78>)
 8000060:	681b      	ldr	r3, [r3, #0]
 8000062:	4a12      	ldr	r2, [pc, #72]	; (80000ac <main+0x78>)
 8000064:	f443 5300 	orr.w	r3, r3, #8192	; 0x2000
 8000068:	6013      	str	r3, [r2, #0]
 800006a:	2300      	movs	r3, #0
 800006c:	607b      	str	r3, [r7, #4]
 800006e:	e002      	b.n	8000076 <main+0x42>
 8000070:	687b      	ldr	r3, [r7, #4]
 8000072:	3301      	adds	r3, #1
 8000074:	607b      	str	r3, [r7, #4]
 8000076:	687b      	ldr	r3, [r7, #4]
 8000078:	f241 3287 	movw	r2, #4999	; 0x1387
 800007c:	4293      	cmp	r3, r2
 800007e:	ddf7      	ble.n	8000070 <main+0x3c>
 8000080:	4b0a      	ldr	r3, [pc, #40]	; (80000ac <main+0x78>)
 8000082:	681b      	ldr	r3, [r3, #0]
 8000084:	4a09      	ldr	r2, [pc, #36]	; (80000ac <main+0x78>)
 8000086:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 800008a:	6013      	str	r3, [r2, #0]
 800008c:	2300      	movs	r3, #0
 800008e:	603b      	str	r3, [r7, #0]
 8000090:	e002      	b.n	8000098 <main+0x64>
 8000092:	683b      	ldr	r3, [r7, #0]
 8000094:	3301      	adds	r3, #1
 8000096:	603b      	str	r3, [r7, #0]
 8000098:	683b      	ldr	r3, [r7, #0]
 800009a:	f241 3287 	movw	r2, #4999	; 0x1387
 800009e:	4293      	cmp	r3, r2
 80000a0:	ddf7      	ble.n	8000092 <main+0x5e>
 80000a2:	e7dc      	b.n	800005e <main+0x2a>
 80000a4:	40021018 	andmi	r1, r2, r8, lsl r0
 80000a8:	40010804 	andmi	r0, r1, r4, lsl #16
 80000ac:	4001080c 	andmi	r0, r1, ip, lsl #16

080000b0 <Default_Handler>:
 80000b0:	b580      	push	{r7, lr}
 80000b2:	af00      	add	r7, sp, #0
 80000b4:	f000 f802 	bl	80000bc <Reset_Handler>
 80000b8:	bf00      	nop
 80000ba:	bd80      	pop	{r7, pc}

080000bc <Reset_Handler>:
 80000bc:	b580      	push	{r7, lr}
 80000be:	b086      	sub	sp, #24
 80000c0:	af00      	add	r7, sp, #0
 80000c2:	4a1a      	ldr	r2, [pc, #104]	; (800012c <Reset_Handler+0x70>)
 80000c4:	4b1a      	ldr	r3, [pc, #104]	; (8000130 <Reset_Handler+0x74>)
 80000c6:	1ad3      	subs	r3, r2, r3
 80000c8:	60bb      	str	r3, [r7, #8]
 80000ca:	4b1a      	ldr	r3, [pc, #104]	; (8000134 <Reset_Handler+0x78>)
 80000cc:	617b      	str	r3, [r7, #20]
 80000ce:	4b18      	ldr	r3, [pc, #96]	; (8000130 <Reset_Handler+0x74>)
 80000d0:	613b      	str	r3, [r7, #16]
 80000d2:	2300      	movs	r3, #0
 80000d4:	60fb      	str	r3, [r7, #12]
 80000d6:	e00a      	b.n	80000ee <Reset_Handler+0x32>
 80000d8:	697a      	ldr	r2, [r7, #20]
 80000da:	1c53      	adds	r3, r2, #1
 80000dc:	617b      	str	r3, [r7, #20]
 80000de:	693b      	ldr	r3, [r7, #16]
 80000e0:	1c59      	adds	r1, r3, #1
 80000e2:	6139      	str	r1, [r7, #16]
 80000e4:	7812      	ldrb	r2, [r2, #0]
 80000e6:	701a      	strb	r2, [r3, #0]
 80000e8:	68fb      	ldr	r3, [r7, #12]
 80000ea:	3301      	adds	r3, #1
 80000ec:	60fb      	str	r3, [r7, #12]
 80000ee:	68fb      	ldr	r3, [r7, #12]
 80000f0:	68ba      	ldr	r2, [r7, #8]
 80000f2:	429a      	cmp	r2, r3
 80000f4:	d8f0      	bhi.n	80000d8 <Reset_Handler+0x1c>
 80000f6:	4a10      	ldr	r2, [pc, #64]	; (8000138 <Reset_Handler+0x7c>)
 80000f8:	4b10      	ldr	r3, [pc, #64]	; (800013c <Reset_Handler+0x80>)
 80000fa:	1ad3      	subs	r3, r2, r3
 80000fc:	607b      	str	r3, [r7, #4]
 80000fe:	4b0f      	ldr	r3, [pc, #60]	; (800013c <Reset_Handler+0x80>)
 8000100:	613b      	str	r3, [r7, #16]
 8000102:	2300      	movs	r3, #0
 8000104:	60fb      	str	r3, [r7, #12]
 8000106:	e007      	b.n	8000118 <Reset_Handler+0x5c>
 8000108:	693b      	ldr	r3, [r7, #16]
 800010a:	1c5a      	adds	r2, r3, #1
 800010c:	613a      	str	r2, [r7, #16]
 800010e:	2200      	movs	r2, #0
 8000110:	701a      	strb	r2, [r3, #0]
 8000112:	68fb      	ldr	r3, [r7, #12]
 8000114:	3301      	adds	r3, #1
 8000116:	60fb      	str	r3, [r7, #12]
 8000118:	68fb      	ldr	r3, [r7, #12]
 800011a:	687a      	ldr	r2, [r7, #4]
 800011c:	429a      	cmp	r2, r3
 800011e:	d8f3      	bhi.n	8000108 <Reset_Handler+0x4c>
 8000120:	f7ff ff88 	bl	8000034 <main>
 8000124:	bf00      	nop
 8000126:	3718      	adds	r7, #24
 8000128:	46bd      	mov	sp, r7
 800012a:	bd80      	pop	{r7, pc}
 800012c:	20000000 	andcs	r0, r0, r0
 8000130:	20000000 	andcs	r0, r0, r0
 8000134:	08000140 	stmdaeq	r0, {r6, r8}
 8000138:	20000000 	andcs	r0, r0, r0
 800013c:	20000000 	andcs	r0, r0, r0

Disassembly of section .bss:

20000000 <_E_BSS>:
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000ea 	andeq	r0, r0, sl, ror #1
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000000e 	andeq	r0, r0, lr
  10:	00010a0c 	andeq	r0, r1, ip, lsl #20
  14:	00009000 	andeq	r9, r0, r0
  18:	00001c00 	andeq	r1, r0, r0, lsl #24
  1c:	00009408 	andeq	r9, r0, r8, lsl #8
  20:	00000000 	andeq	r0, r0, r0
  24:	06010200 	streq	r0, [r1], -r0, lsl #4
  28:	00000002 	andeq	r0, r0, r2
  2c:	00080102 	andeq	r0, r8, r2, lsl #2
  30:	02000000 	andeq	r0, r0, #0
  34:	01110502 	tsteq	r1, r2, lsl #10
  38:	02020000 	andeq	r0, r2, #0
  3c:	00007207 	andeq	r7, r0, r7, lsl #4
  40:	05040200 	streq	r0, [r4, #-512]	; 0xfffffe00
  44:	00000101 	andeq	r0, r0, r1, lsl #2
  48:	00008503 	andeq	r8, r0, r3, lsl #10
  4c:	534f0200 	movtpl	r0, #61952	; 0xf200
  50:	02000000 	andeq	r0, r0, #0
  54:	00de0704 	sbcseq	r0, lr, r4, lsl #14
  58:	08020000 	stmdaeq	r2, {}	; <UNPREDICTABLE>
  5c:	0000fc05 	andeq	pc, r0, r5, lsl #24
  60:	07080200 	streq	r0, [r8, -r0, lsl #4]
  64:	000000d9 	ldrdeq	r0, [r0], -r9
  68:	69050404 	stmdbvs	r5, {r2, sl}
  6c:	0200746e 	andeq	r7, r0, #1845493760	; 0x6e000000
  70:	00e30704 	rsceq	r0, r3, r4, lsl #14
  74:	87030000 	strhi	r0, [r3, -r0]
  78:	03000000 	movweq	r0, #0
  7c:	00004830 	andeq	r4, r0, r0, lsr r8
  80:	00d40500 	sbcseq	r0, r4, r0, lsl #10
  84:	25010000 	strcs	r0, [r1, #-0]
  88:	00000068 	andeq	r0, r0, r8, rrx
  8c:	08000034 	stmdaeq	r0, {r2, r4, r5}
  90:	0000007c 	andeq	r0, r0, ip, ror r0
  94:	00cb9c01 	sbceq	r9, fp, r1, lsl #24
  98:	6a060000 	bvs	1800a0 <vectors-0x7e7ff60>
  9c:	16080000 	strne	r0, [r8], -r0
  a0:	b4000000 	strlt	r0, [r0], #-0
  a4:	07000000 	streq	r0, [r0, -r0]
  a8:	30010069 	andcc	r0, r1, r9, rrx
  ac:	00000068 	andeq	r0, r0, r8, rrx
  b0:	00749102 	rsbseq	r9, r4, r2, lsl #2
  b4:	00008c08 	andeq	r8, r0, r8, lsl #24
  b8:	00001608 	andeq	r1, r0, r8, lsl #12
  bc:	00690700 	rsbeq	r0, r9, r0, lsl #14
  c0:	00683201 	rsbeq	r3, r8, r1, lsl #4
  c4:	91020000 	mrsls	r0, (UNDEF: 2)
  c8:	09000070 	stmdbeq	r0, {r4, r5, r6}
  cc:	000000c4 	andeq	r0, r0, r4, asr #1
  d0:	00282001 	eoreq	r2, r8, r1
  d4:	000c0800 	andeq	r0, ip, r0, lsl #16
  d8:	9c010000 	stcls	0, cr0, [r1], {-0}
  dc:	0000f009 	andeq	pc, r0, r9
  e0:	1c1c0100 	ldfnes	f0, [ip], {-0}
  e4:	0c080000 	stceq	0, cr0, [r8], {-0}
  e8:	01000000 	mrseq	r0, (UNDEF: 0)
  ec:	0152009c 			; <UNDEFINED> instruction: 0x0152009c
  f0:	00040000 	andeq	r0, r4, r0
  f4:	0000008e 	andeq	r0, r0, lr, lsl #1
  f8:	000e0104 	andeq	r0, lr, r4, lsl #2
  fc:	1b0c0000 	blne	300104 <vectors-0x7cffefc>
 100:	90000001 	andls	r0, r0, r1
 104:	b0000000 	andlt	r0, r0, r0
 108:	90080000 	andls	r0, r8, r0
 10c:	13000000 	movwne	r0, #0
 110:	02000001 	andeq	r0, r0, #1
 114:	00020601 	andeq	r0, r2, r1, lsl #12
 118:	01020000 	mrseq	r0, (UNDEF: 2)
 11c:	00000008 	andeq	r0, r0, r8
 120:	05020200 	streq	r0, [r2, #-512]	; 0xfffffe00
 124:	00000111 	andeq	r0, r0, r1, lsl r1
 128:	72070202 	andvc	r0, r7, #536870912	; 0x20000000
 12c:	02000000 	andeq	r0, r0, #0
 130:	01010504 	tsteq	r1, r4, lsl #10
 134:	85030000 	strhi	r0, [r3, #-0]
 138:	02000000 	andeq	r0, r0, #0
 13c:	0000534f 	andeq	r5, r0, pc, asr #6
 140:	07040200 	streq	r0, [r4, -r0, lsl #4]
 144:	000000de 	ldrdeq	r0, [r0], -lr
 148:	fc050802 	stc2	8, cr0, [r5], {2}
 14c:	02000000 	andeq	r0, r0, #0
 150:	00d90708 	sbcseq	r0, r9, r8, lsl #14
 154:	04040000 	streq	r0, [r4], #-0
 158:	746e6905 	strbtvc	r6, [lr], #-2309	; 0xfffff6fb
 15c:	07040200 	streq	r0, [r4, -r0, lsl #4]
 160:	000000e3 	andeq	r0, r0, r3, ror #1
 164:	00008703 	andeq	r8, r0, r3, lsl #14
 168:	48300300 	ldmdami	r0!, {r8, r9}
 16c:	05000000 	streq	r0, [r0, #-0]
 170:	0000015e 	andeq	r0, r0, lr, asr r1
 174:	006f1201 	rsbeq	r1, pc, r1, lsl #4
 178:	76060000 	strvc	r0, [r6], -r0
 17c:	9c000000 	stcls	0, cr0, [r0], {-0}
 180:	07000000 	streq	r0, [r0, -r0]
 184:	0000006f 	andeq	r0, r0, pc, rrx
 188:	39080006 	stmdbcc	r8, {r1, r2}
 18c:	01000001 	tsteq	r0, r1
 190:	00008c13 	andeq	r8, r0, r3, lsl ip
 194:	00030500 	andeq	r0, r3, r0, lsl #10
 198:	05080000 	streq	r0, [r8, #-0]
 19c:	00000156 	andeq	r0, r0, r6, asr r1
 1a0:	006f1e01 	rsbeq	r1, pc, r1, lsl #28
 1a4:	82050000 	andhi	r0, r5, #0
 1a8:	01000001 	tsteq	r0, r1
 1ac:	00006f1f 	andeq	r6, r0, pc, lsl pc
 1b0:	01470500 	cmpeq	r7, r0, lsl #10
 1b4:	20010000 	andcs	r0, r1, r0
 1b8:	0000006f 	andeq	r0, r0, pc, rrx
 1bc:	00018a05 	andeq	r8, r1, r5, lsl #20
 1c0:	6f210100 	svcvs	0x00210100
 1c4:	05000000 	streq	r0, [r0, #-0]
 1c8:	0000014f 	andeq	r0, r0, pc, asr #2
 1cc:	006f2201 	rsbeq	r2, pc, r1, lsl #4
 1d0:	25090000 	strcs	r0, [r9, #-0]
 1d4:	01000001 	tsteq	r0, r1
 1d8:	0000bc23 	andeq	fp, r0, r3, lsr #24
 1dc:	00008408 	andeq	r8, r0, r8, lsl #8
 1e0:	3e9c0100 	fmlcce	f0, f4, f0
 1e4:	0a000001 	beq	1f0 <vectors-0x7fffe10>
 1e8:	00000191 	muleq	r0, r1, r1
 1ec:	006f2601 	rsbeq	r2, pc, r1, lsl #12
 1f0:	91020000 	mrsls	r0, (UNDEF: 2)
 1f4:	01330a68 	teqeq	r3, r8, ror #20
 1f8:	27010000 	strcs	r0, [r1, -r0]
 1fc:	0000013e 	andeq	r0, r0, lr, lsr r1
 200:	0a749102 	beq	1d24610 <vectors-0x62db9f0>
 204:	00000141 	andeq	r0, r0, r1, asr #2
 208:	013e2801 	teqeq	lr, r1, lsl #16
 20c:	91020000 	mrsls	r0, (UNDEF: 2)
 210:	00690b70 	rsbeq	r0, r9, r0, ror fp
 214:	00682901 	rsbeq	r2, r8, r1, lsl #18
 218:	91020000 	mrsls	r0, (UNDEF: 2)
 21c:	01690a6c 	cmneq	r9, ip, ror #20
 220:	33010000 	movwcc	r0, #4096	; 0x1000
 224:	0000006f 	andeq	r0, r0, pc, rrx
 228:	00649102 	rsbeq	r9, r4, r2, lsl #2
 22c:	002c040c 	eoreq	r0, ip, ip, lsl #8
 230:	720d0000 	andvc	r0, sp, #0
 234:	01000001 	tsteq	r0, r1
 238:	0000b007 	andeq	fp, r0, r7
 23c:	00000c08 	andeq	r0, r0, r8, lsl #24
 240:	009c0100 	addseq	r0, ip, r0, lsl #2

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	0b0b0024 	bleq	2c00ac <vectors-0x7d3ff54>
  18:	0e030b3e 	vmoveq.16	d3[0], r0
  1c:	16030000 	strne	r0, [r3], -r0
  20:	3a0e0300 	bcc	380c28 <vectors-0x7c7f3d8>
  24:	490b3b0b 	stmdbmi	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  28:	04000013 	streq	r0, [r0], #-19	; 0xffffffed
  2c:	0b0b0024 	bleq	2c00c4 <vectors-0x7d3ff3c>
  30:	08030b3e 	stmdaeq	r3, {r1, r2, r3, r4, r5, r8, r9, fp}
  34:	2e050000 	cdpcs	0, 0, cr0, cr5, cr0, {0}
  38:	03193f01 	tsteq	r9, #1, 30
  3c:	3b0b3a0e 	blcc	2ce87c <vectors-0x7d31784>
  40:	4919270b 	ldmdbmi	r9, {r0, r1, r3, r8, r9, sl, sp}
  44:	12011113 	andne	r1, r1, #-1073741820	; 0xc0000004
  48:	97184006 	ldrls	r4, [r8, -r6]
  4c:	13011942 	movwne	r1, #6466	; 0x1942
  50:	0b060000 	bleq	180058 <vectors-0x7e7ffa8>
  54:	12011101 	andne	r1, r1, #1073741824	; 0x40000000
  58:	00130106 	andseq	r0, r3, r6, lsl #2
  5c:	00340700 	eorseq	r0, r4, r0, lsl #14
  60:	0b3a0803 	bleq	e82074 <vectors-0x717df8c>
  64:	13490b3b 	movtne	r0, #39739	; 0x9b3b
  68:	00001802 	andeq	r1, r0, r2, lsl #16
  6c:	11010b08 	tstne	r1, r8, lsl #22
  70:	00061201 	andeq	r1, r6, r1, lsl #4
  74:	002e0900 	eoreq	r0, lr, r0, lsl #18
  78:	0e03193f 			; <UNDEFINED> instruction: 0x0e03193f
  7c:	0b3b0b3a 	bleq	ec2d6c <vectors-0x713d294>
  80:	01111927 	tsteq	r1, r7, lsr #18
  84:	18400612 	stmdane	r0, {r1, r4, r9, sl}^
  88:	00194297 	mulseq	r9, r7, r2
  8c:	11010000 	mrsne	r0, (UNDEF: 1)
  90:	130e2501 	movwne	r2, #58625	; 0xe501
  94:	1b0e030b 	blne	380cc8 <vectors-0x7c7f338>
  98:	1201110e 	andne	r1, r1, #-2147483645	; 0x80000003
  9c:	00171006 	andseq	r1, r7, r6
  a0:	00240200 	eoreq	r0, r4, r0, lsl #4
  a4:	0b3e0b0b 	bleq	f82cd8 <vectors-0x707d328>
  a8:	00000e03 	andeq	r0, r0, r3, lsl #28
  ac:	03001603 	movweq	r1, #1539	; 0x603
  b0:	3b0b3a0e 	blcc	2ce8f0 <vectors-0x7d31710>
  b4:	0013490b 	andseq	r4, r3, fp, lsl #18
  b8:	00240400 	eoreq	r0, r4, r0, lsl #8
  bc:	0b3e0b0b 	bleq	f82cf0 <vectors-0x707d310>
  c0:	00000803 	andeq	r0, r0, r3, lsl #16
  c4:	03003405 	movweq	r3, #1029	; 0x405
  c8:	3b0b3a0e 	blcc	2ce908 <vectors-0x7d316f8>
  cc:	3f13490b 	svccc	0x0013490b
  d0:	00193c19 	andseq	r3, r9, r9, lsl ip
  d4:	01010600 	tsteq	r1, r0, lsl #12
  d8:	13011349 	movwne	r1, #4937	; 0x1349
  dc:	21070000 	mrscs	r0, (UNDEF: 7)
  e0:	2f134900 	svccs	0x00134900
  e4:	0800000b 	stmdaeq	r0, {r0, r1, r3}
  e8:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  ec:	0b3b0b3a 	bleq	ec2ddc <vectors-0x713d224>
  f0:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	; <UNPREDICTABLE>
  f4:	00001802 	andeq	r1, r0, r2, lsl #16
  f8:	3f012e09 	svccc	0x00012e09
  fc:	3a0e0319 	bcc	380d68 <vectors-0x7c7f298>
 100:	110b3b0b 	tstne	fp, fp, lsl #22
 104:	40061201 	andmi	r1, r6, r1, lsl #4
 108:	19429618 	stmdbne	r2, {r3, r4, r9, sl, ip, pc}^
 10c:	00001301 	andeq	r1, r0, r1, lsl #6
 110:	0300340a 	movweq	r3, #1034	; 0x40a
 114:	3b0b3a0e 	blcc	2ce954 <vectors-0x7d316ac>
 118:	0213490b 	andseq	r4, r3, #180224	; 0x2c000
 11c:	0b000018 	bleq	184 <vectors-0x7fffe7c>
 120:	08030034 	stmdaeq	r3, {r2, r4, r5}
 124:	0b3b0b3a 	bleq	ec2e14 <vectors-0x713d1ec>
 128:	18021349 	stmdane	r2, {r0, r3, r6, r8, r9, ip}
 12c:	0f0c0000 	svceq	0x000c0000
 130:	490b0b00 	stmdbmi	fp, {r8, r9, fp}
 134:	0d000013 	stceq	0, cr0, [r0, #-76]	; 0xffffffb4
 138:	193f002e 	ldmdbne	pc!, {r1, r2, r3, r5}	; <UNPREDICTABLE>
 13c:	0b3a0e03 	bleq	e83950 <vectors-0x717c6b0>
 140:	01110b3b 	tsteq	r1, fp, lsr fp
 144:	18400612 	stmdane	r0, {r1, r4, r9, sl}^
 148:	00194296 	mulseq	r9, r6, r2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
   c:	00000000 	andeq	r0, r0, r0
  10:	0800001c 	stmdaeq	r0, {r2, r3, r4}
  14:	00000094 	muleq	r0, r4, r0
	...
  20:	0000001c 	andeq	r0, r0, ip, lsl r0
  24:	00ee0002 	rsceq	r0, lr, r2
  28:	00040000 	andeq	r0, r4, r0
  2c:	00000000 	andeq	r0, r0, r0
  30:	080000b0 	stmdaeq	r0, {r4, r5, r7}
  34:	00000090 	muleq	r0, r0, r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000010f 	andeq	r0, r0, pc, lsl #2
   4:	00d60002 	sbcseq	r0, r6, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	64010000 	strvs	r0, [r1], #-0
  1c:	74735c3a 	ldrbtvc	r5, [r3], #-3130	; 0xfffff3c6
  20:	5c796475 	cfldrdpl	mvd6, [r9], #-468	; 0xfffffe2c
  24:	2d756e67 	ldclcs	14, cr6, [r5, #-412]!	; 0xfffffe64
  28:	6c6f6f74 	stclvs	15, cr6, [pc], #-464	; fffffe60 <_stack_top+0xdfffee60>
  2c:	72612d73 	rsbvc	r2, r1, #7360	; 0x1cc0
  30:	6d652d6d 	stclvs	13, cr2, [r5, #-436]!	; 0xfffffe4c
  34:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  38:	375c6465 	ldrbcc	r6, [ip, -r5, ror #8]
  3c:	31303220 	teqcc	r0, r0, lsr #4
  40:	34712d37 	ldrbtcc	r2, [r1], #-3383	; 0xfffff2c9
  44:	6a616d2d 	bvs	185b500 <vectors-0x67a4b00>
  48:	615c726f 	cmpvs	ip, pc, ror #4
  4c:	6e2d6d72 	mcrvs	13, 1, r6, cr13, cr2, {3}
  50:	2d656e6f 	stclcs	14, cr6, [r5, #-444]!	; 0xfffffe44
  54:	69626165 	stmdbvs	r2!, {r0, r2, r5, r6, r8, sp, lr}^
  58:	636e695c 	cmnvs	lr, #92, 18	; 0x170000
  5c:	6564756c 	strbvs	r7, [r4, #-1388]!	; 0xfffffa94
  60:	63616d5c 	cmnvs	r1, #92, 26	; 0x1700
  64:	656e6968 	strbvs	r6, [lr, #-2408]!	; 0xfffff698
  68:	5c3a6400 	cfldrspl	mvf6, [sl], #-0
  6c:	64757473 	ldrbtvs	r7, [r5], #-1139	; 0xfffffb8d
  70:	6e675c79 	mcrvs	12, 3, r5, cr7, cr9, {3}
  74:	6f742d75 	svcvs	0x00742d75
  78:	2d736c6f 	ldclcs	12, cr6, [r3, #-444]!	; 0xfffffe44
  7c:	2d6d7261 	sfmcs	f7, 2, [sp, #-388]!	; 0xfffffe7c
  80:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xfffff29b
  84:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  88:	3220375c 	eorcc	r3, r0, #92, 14	; 0x1700000
  8c:	2d373130 	ldfcss	f3, [r7, #-192]!	; 0xffffff40
  90:	6d2d3471 	cfstrsvs	mvf3, [sp, #-452]!	; 0xfffffe3c
  94:	726f6a61 	rsbvc	r6, pc, #397312	; 0x61000
  98:	6d72615c 	ldfvse	f6, [r2, #-368]!	; 0xfffffe90
  9c:	6e6f6e2d 	cdpvs	14, 6, cr6, cr15, cr13, {1}
  a0:	61652d65 	cmnvs	r5, r5, ror #26
  a4:	695c6962 	ldmdbvs	ip, {r1, r5, r6, r8, fp, sp, lr}^
  a8:	756c636e 	strbvc	r6, [ip, #-878]!	; 0xfffffc92
  ac:	735c6564 	cmpvc	ip, #100, 10	; 0x19000000
  b0:	00007379 	andeq	r7, r0, r9, ror r3
  b4:	6e69616d 	powvsez	f6, f1, #5.0
  b8:	0000632e 	andeq	r6, r0, lr, lsr #6
  bc:	645f0000 	ldrbvs	r0, [pc], #-0	; c4 <vectors-0x7ffff3c>
  c0:	75616665 	strbvc	r6, [r1, #-1637]!	; 0xfffff99b
  c4:	745f746c 	ldrbvc	r7, [pc], #-1132	; cc <vectors-0x7ffff34>
  c8:	73657079 	cmnvc	r5, #121	; 0x79
  cc:	0100682e 	tsteq	r0, lr, lsr #16
  d0:	735f0000 	cmpvc	pc, #0
  d4:	6e696474 	mcrvs	4, 3, r6, cr9, cr4, {3}
  d8:	00682e74 	rsbeq	r2, r8, r4, ror lr
  dc:	00000002 	andeq	r0, r0, r2
  e0:	1c020500 	cfstr32ne	mvfx0, [r2], {-0}
  e4:	03080000 	movweq	r0, #32768	; 0x8000
  e8:	4c30011c 	ldfmis	f0, [r0], #-112	; 0xffffff90
  ec:	673d4d30 			; <UNDEFINED> instruction: 0x673d4d30
  f0:	00676c67 	rsbeq	r6, r7, r7, ror #24
  f4:	06030402 	streq	r0, [r3], -r2, lsl #8
  f8:	0402003c 	streq	r0, [r2], #-60	; 0xffffffc4
  fc:	59063c01 	stmdbpl	r6, {r0, sl, fp, ip, sp}
 100:	04020067 	streq	r0, [r2], #-103	; 0xffffff99
 104:	003c0603 	eorseq	r0, ip, r3, lsl #12
 108:	3c010402 	cfstrscc	mvf0, [r1], {2}
 10c:	07025506 	streq	r5, [r2, -r6, lsl #10]
 110:	1c010100 	stfnes	f0, [r1], {-0}
 114:	02000001 	andeq	r0, r0, #1
 118:	0000d900 	andeq	sp, r0, r0, lsl #18
 11c:	fb010200 	blx	40926 <vectors-0x7fbf6da>
 120:	01000d0e 	tsteq	r0, lr, lsl #26
 124:	00010101 	andeq	r0, r1, r1, lsl #2
 128:	00010000 	andeq	r0, r1, r0
 12c:	3a640100 	bcc	1900534 <vectors-0x66ffacc>
 130:	7574735c 	ldrbvc	r7, [r4, #-860]!	; 0xfffffca4
 134:	675c7964 	ldrbvs	r7, [ip, -r4, ror #18]
 138:	742d756e 	strtvc	r7, [sp], #-1390	; 0xfffffa92
 13c:	736c6f6f 	cmnvc	ip, #444	; 0x1bc
 140:	6d72612d 	ldfvse	f6, [r2, #-180]!	; 0xffffff4c
 144:	626d652d 	rsbvs	r6, sp, #188743680	; 0xb400000
 148:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
 14c:	20375c64 	eorscs	r5, r7, r4, ror #24
 150:	37313032 			; <UNDEFINED> instruction: 0x37313032
 154:	2d34712d 	ldfcss	f7, [r4, #-180]!	; 0xffffff4c
 158:	6f6a616d 	svcvs	0x006a616d
 15c:	72615c72 	rsbvc	r5, r1, #29184	; 0x7200
 160:	6f6e2d6d 	svcvs	0x006e2d6d
 164:	652d656e 	strvs	r6, [sp, #-1390]!	; 0xfffffa92
 168:	5c696261 	sfmpl	f6, 2, [r9], #-388	; 0xfffffe7c
 16c:	6c636e69 	stclvs	14, cr6, [r3], #-420	; 0xfffffe5c
 170:	5c656475 	cfstrdpl	mvd6, [r5], #-468	; 0xfffffe2c
 174:	6863616d 	stmdavs	r3!, {r0, r2, r3, r5, r6, r8, sp, lr}^
 178:	00656e69 	rsbeq	r6, r5, r9, ror #28
 17c:	735c3a64 	cmpvc	ip, #100, 20	; 0x64000
 180:	79647574 	stmdbvc	r4!, {r2, r4, r5, r6, r8, sl, ip, sp, lr}^
 184:	756e675c 	strbvc	r6, [lr, #-1884]!	; 0xfffff8a4
 188:	6f6f742d 	svcvs	0x006f742d
 18c:	612d736c 			; <UNDEFINED> instruction: 0x612d736c
 190:	652d6d72 	strvs	r6, [sp, #-3442]!	; 0xfffff28e
 194:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
 198:	5c646564 	cfstr64pl	mvdx6, [r4], #-400	; 0xfffffe70
 19c:	30322037 	eorscc	r2, r2, r7, lsr r0
 1a0:	712d3731 			; <UNDEFINED> instruction: 0x712d3731
 1a4:	616d2d34 	cmnvs	sp, r4, lsr sp
 1a8:	5c726f6a 	ldclpl	15, cr6, [r2], #-424	; 0xfffffe58
 1ac:	2d6d7261 	sfmcs	f7, 2, [sp, #-388]!	; 0xfffffe7c
 1b0:	656e6f6e 	strbvs	r6, [lr, #-3950]!	; 0xfffff092
 1b4:	6261652d 	rsbvs	r6, r1, #188743680	; 0xb400000
 1b8:	6e695c69 	cdpvs	12, 6, cr5, cr9, cr9, {3}
 1bc:	64756c63 	ldrbtvs	r6, [r5], #-3171	; 0xfffff39d
 1c0:	79735c65 	ldmdbvc	r3!, {r0, r2, r5, r6, sl, fp, ip, lr}^
 1c4:	73000073 	movwvc	r0, #115	; 0x73
 1c8:	74726174 	ldrbtvc	r6, [r2], #-372	; 0xfffffe8c
 1cc:	632e7075 			; <UNDEFINED> instruction: 0x632e7075
 1d0:	00000000 	andeq	r0, r0, r0
 1d4:	6665645f 			; <UNDEFINED> instruction: 0x6665645f
 1d8:	746c7561 	strbtvc	r7, [ip], #-1377	; 0xfffffa9f
 1dc:	7079745f 	rsbsvc	r7, r9, pc, asr r4
 1e0:	682e7365 	stmdavs	lr!, {r0, r2, r5, r6, r8, r9, ip, sp, lr}
 1e4:	00000100 	andeq	r0, r0, r0, lsl #2
 1e8:	6474735f 	ldrbtvs	r7, [r4], #-863	; 0xfffffca1
 1ec:	2e746e69 	cdpcs	14, 7, cr6, cr4, cr9, {3}
 1f0:	00020068 	andeq	r0, r2, r8, rrx
 1f4:	05000000 	streq	r0, [r0, #-0]
 1f8:	0000b002 	andeq	fp, r0, r2
 1fc:	2f2f1908 	svccs	0x002f1908
 200:	3e2e1a03 	vmulcc.f32	s2, s28, s6
 204:	00312f4b 	eorseq	r2, r1, fp, asr #30
 208:	3f030402 	svccc	0x00030402
 20c:	03040200 	movweq	r0, #16896	; 0x4200
 210:	0402007f 	streq	r0, [r2], #-127	; 0xffffff81
 214:	063c0601 	ldrteq	r0, [ip], -r1, lsl #12
 218:	002f4b52 	eoreq	r4, pc, r2, asr fp	; <UNPREDICTABLE>
 21c:	3f030402 	svccc	0x00030402
 220:	03040200 	movweq	r0, #16896	; 0x4200
 224:	04020055 	streq	r0, [r2], #-85	; 0xffffffab
 228:	063c0601 	ldrteq	r0, [ip], -r1, lsl #12
 22c:	0e022f52 	mcreq	15, 0, r2, cr2, cr2, {2}
 230:	Address 0x00000230 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	4e470072 	mcrmi	0, 2, r0, cr7, cr2, {3}
  10:	31432055 	qdaddcc	r2, r5, r3
  14:	2e372031 	mrccs	0, 1, r2, cr7, cr1, {1}
  18:	20312e32 	eorscs	r2, r1, r2, lsr lr
  1c:	37313032 			; <UNDEFINED> instruction: 0x37313032
  20:	34303930 	ldrtcc	r3, [r0], #-2352	; 0xfffff6d0
  24:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  28:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  2c:	5b202965 	blpl	80a5c8 <vectors-0x77f5a38>
  30:	2f4d5241 	svccs	0x004d5241
  34:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xfffff29b
  38:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  3c:	622d372d 	eorvs	r3, sp, #11796480	; 0xb40000
  40:	636e6172 	cmnvs	lr, #-2147483620	; 0x8000001c
  44:	65722068 	ldrbvs	r2, [r2, #-104]!	; 0xffffff98
  48:	69736976 	ldmdbvs	r3!, {r1, r2, r4, r5, r6, r8, fp, sp, lr}^
  4c:	32206e6f 	eorcc	r6, r0, #1776	; 0x6f0
  50:	30323535 	eorscc	r3, r2, r5, lsr r5
  54:	2d205d34 	stccs	13, cr5, [r0, #-208]!	; 0xffffff30
  58:	7570636d 	ldrbvc	r6, [r0, #-877]!	; 0xfffffc93
  5c:	726f633d 	rsbvc	r6, pc, #-201326592	; 0xf4000000
  60:	2d786574 	cfldr64cs	mvdx6, [r8, #-464]!	; 0xfffffe30
  64:	2d20336d 	stccs	3, cr3, [r0, #-436]!	; 0xfffffe4c
  68:	7568746d 	strbvc	r7, [r8, #-1133]!	; 0xfffffb93
  6c:	2d20626d 	sfmcs	f6, 4, [r0, #-436]!	; 0xfffffe4c
  70:	68730067 	ldmdavs	r3!, {r0, r1, r2, r5, r6}^
  74:	2074726f 	rsbscs	r7, r4, pc, ror #4
  78:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  7c:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  80:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
  84:	755f5f00 	ldrbvc	r5, [pc, #-3840]	; fffff18c <_stack_top+0xdfffe18c>
  88:	33746e69 	cmncc	r4, #1680	; 0x690
  8c:	00745f32 	rsbseq	r5, r4, r2, lsr pc
  90:	735c3a44 	cmpvc	ip, #68, 20	; 0x44000
  94:	79647574 	stmdbvc	r4!, {r2, r4, r5, r6, r8, sl, ip, sp, lr}^
  98:	554e475c 	strbpl	r4, [lr, #-1884]	; 0xfffff8a4
  9c:	6f6f542d 	svcvs	0x006f542d
  a0:	412d736c 			; <UNDEFINED> instruction: 0x412d736c
  a4:	452d4d52 	strmi	r4, [sp, #-3410]!	; 0xfffff2ae
  a8:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  ac:	5c646564 	cfstr64pl	mvdx6, [r4], #-400	; 0xfffffe70
  b0:	30322037 	eorscc	r2, r2, r7, lsr r0
  b4:	712d3731 			; <UNDEFINED> instruction: 0x712d3731
  b8:	616d2d34 	cmnvs	sp, r4, lsr sp
  bc:	5c726f6a 	ldclpl	15, cr6, [r2], #-424	; 0xfffffe58
  c0:	006e6962 	rsbeq	r6, lr, r2, ror #18
  c4:	61665f48 	cmnvs	r6, r8, asr #30
  c8:	5f746c75 	svcpl	0x00746c75
  cc:	646e6148 	strbtvs	r6, [lr], #-328	; 0xfffffeb8
  d0:	0072656c 	rsbseq	r6, r2, ip, ror #10
  d4:	6e69616d 	powvsez	f6, f1, #5.0
  d8:	6e6f6c00 	cdpvs	12, 6, cr6, cr15, cr0, {0}
  dc:	6f6c2067 	svcvs	0x006c2067
  e0:	7520676e 	strvc	r6, [r0, #-1902]!	; 0xfffff892
  e4:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  e8:	2064656e 	rsbcs	r6, r4, lr, ror #10
  ec:	00746e69 	rsbseq	r6, r4, r9, ror #28
  f0:	5f494d4e 	svcpl	0x00494d4e
  f4:	646e6148 	strbtvs	r6, [lr], #-328	; 0xfffffeb8
  f8:	0072656c 	rsbseq	r6, r2, ip, ror #10
  fc:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
 100:	6e6f6c20 	cdpvs	12, 6, cr6, cr15, cr0, {1}
 104:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
 108:	616d0074 	smcvs	53252	; 0xd004
 10c:	632e6e69 			; <UNDEFINED> instruction: 0x632e6e69
 110:	6f687300 	svcvs	0x00687300
 114:	69207472 	stmdbvs	r0!, {r1, r4, r5, r6, sl, ip, sp, lr}
 118:	7300746e 	movwvc	r7, #1134	; 0x46e
 11c:	74726174 	ldrbtvc	r6, [r2], #-372	; 0xfffffe8c
 120:	632e7075 			; <UNDEFINED> instruction: 0x632e7075
 124:	73655200 	cmnvc	r5, #0, 4
 128:	485f7465 	ldmdami	pc, {r0, r2, r5, r6, sl, ip, sp, lr}^	; <UNPREDICTABLE>
 12c:	6c646e61 	stclvs	14, cr6, [r4], #-388	; 0xfffffe7c
 130:	50007265 	andpl	r7, r0, r5, ror #4
 134:	6372735f 	cmnvs	r2, #2080374785	; 0x7c000001
 138:	63657600 	cmnvs	r5, #0, 12
 13c:	73726f74 	cmnvc	r2, #116, 30	; 0x1d0
 140:	645f5000 	ldrbvs	r5, [pc], #-0	; 148 <vectors-0x7fffeb8>
 144:	5f007465 	svcpl	0x00007465
 148:	41445f45 	cmpmi	r4, r5, asr #30
 14c:	5f004154 	svcpl	0x00004154
 150:	53425f45 	movtpl	r5, #12101	; 0x2f45
 154:	455f0053 	ldrbmi	r0, [pc, #-83]	; 109 <vectors-0x7fffef7>
 158:	5845545f 	stmdapl	r5, {r0, r1, r2, r3, r4, r6, sl, ip, lr}^
 15c:	735f0054 	cmpvc	pc, #84	; 0x54
 160:	6b636174 	blvs	18d8738 <vectors-0x67278c8>
 164:	706f745f 	rsbvc	r7, pc, pc, asr r4	; <UNPREDICTABLE>
 168:	53534200 	cmppl	r3, #0, 4
 16c:	5a49535f 	bpl	1254ef0 <vectors-0x6dab110>
 170:	65440045 	strbvs	r0, [r4, #-69]	; 0xffffffbb
 174:	6c756166 	ldfvse	f6, [r5], #-408	; 0xfffffe68
 178:	61485f74 	hvcvs	34292	; 0x85f4
 17c:	656c646e 	strbvs	r6, [ip, #-1134]!	; 0xfffffb92
 180:	535f0072 	cmppl	pc, #114	; 0x72
 184:	5441445f 	strbpl	r4, [r1], #-1119	; 0xfffffba1
 188:	535f0041 	cmppl	pc, #65	; 0x41
 18c:	5353425f 	cmppl	r3, #-268435451	; 0xf0000005
 190:	54414400 	strbpl	r4, [r1], #-1024	; 0xfffffc00
 194:	49535f41 	ldmdbmi	r3, {r0, r6, r8, r9, sl, fp, ip, lr}^
 198:	Address 0x00000198 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <vectors-0x6f2f2dc>
   4:	4e472820 	cdpmi	8, 4, cr2, cr7, cr0, {1}
   8:	6f542055 	svcvs	0x00542055
   c:	20736c6f 	rsbscs	r6, r3, pc, ror #24
  10:	20726f66 	rsbscs	r6, r2, r6, ror #30
  14:	206d7241 	rsbcs	r7, sp, r1, asr #4
  18:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xfffff2bb
  1c:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  20:	6f725020 	svcvs	0x00725020
  24:	73736563 	cmnvc	r3, #415236096	; 0x18c00000
  28:	2073726f 	rsbscs	r7, r3, pc, ror #4
  2c:	30322d37 	eorscc	r2, r2, r7, lsr sp
  30:	712d3731 			; <UNDEFINED> instruction: 0x712d3731
  34:	616d2d34 	cmnvs	sp, r4, lsr sp
  38:	29726f6a 	ldmdbcs	r2!, {r1, r3, r5, r6, r8, r9, sl, fp, sp, lr}^
  3c:	322e3720 	eorcc	r3, lr, #32, 14	; 0x800000
  40:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  44:	30373130 	eorscc	r3, r7, r0, lsr r1
  48:	20343039 	eorscs	r3, r4, r9, lsr r0
  4c:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  50:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  54:	415b2029 	cmpmi	fp, r9, lsr #32
  58:	652f4d52 	strvs	r4, [pc, #-3410]!	; fffff30e <_stack_top+0xdfffe30e>
  5c:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  60:	2d646564 	cfstr64cs	mvdx6, [r4, #-400]!	; 0xfffffe70
  64:	72622d37 	rsbvc	r2, r2, #3520	; 0xdc0
  68:	68636e61 	stmdavs	r3!, {r0, r5, r6, r9, sl, fp, sp, lr}^
  6c:	76657220 	strbtvc	r7, [r5], -r0, lsr #4
  70:	6f697369 	svcvs	0x00697369
  74:	3532206e 	ldrcc	r2, [r2, #-110]!	; 0xffffff92
  78:	34303235 	ldrtcc	r3, [r0], #-565	; 0xfffffdcb
  7c:	Address 0x0000007c is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003241 	andeq	r3, r0, r1, asr #4
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000028 	andeq	r0, r0, r8, lsr #32
  10:	726f4305 	rsbvc	r4, pc, #335544320	; 0x14000000
  14:	2d786574 	cfldr64cs	mvdx6, [r8, #-464]!	; 0xfffffe30
  18:	0600334d 	streq	r3, [r0], -sp, asr #6
  1c:	094d070a 	stmdbeq	sp, {r1, r3, r8, r9, sl}^
  20:	14041202 	strne	r1, [r4], #-514	; 0xfffffdfe
  24:	17011501 	strne	r1, [r1, -r1, lsl #10]
  28:	19011803 	stmdbne	r1, {r0, r1, fp, ip}
  2c:	1e011a01 	vmlane.f32	s2, s2, s2
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	0000001c 	andeq	r0, r0, ip, lsl r0
  14:	00000000 	andeq	r0, r0, r0
  18:	0800001c 	stmdaeq	r0, {r2, r3, r4}
  1c:	0000000c 	andeq	r0, r0, ip
  20:	87040e41 	strhi	r0, [r4, -r1, asr #28]
  24:	070d4101 	streq	r4, [sp, -r1, lsl #2]
  28:	410d0d42 	tstmi	sp, r2, asr #26
  2c:	00000ec7 	andeq	r0, r0, r7, asr #29
  30:	0000001c 	andeq	r0, r0, ip, lsl r0
  34:	00000000 	andeq	r0, r0, r0
  38:	08000028 	stmdaeq	r0, {r3, r5}
  3c:	0000000c 	andeq	r0, r0, ip
  40:	87040e41 	strhi	r0, [r4, -r1, asr #28]
  44:	070d4101 	streq	r4, [sp, -r1, lsl #2]
  48:	410d0d42 	tstmi	sp, r2, asr #26
  4c:	00000ec7 	andeq	r0, r0, r7, asr #29
  50:	00000018 	andeq	r0, r0, r8, lsl r0
  54:	00000000 	andeq	r0, r0, r0
  58:	08000034 	stmdaeq	r0, {r2, r4, r5}
  5c:	0000007c 	andeq	r0, r0, ip, ror r0
  60:	87040e41 	strhi	r0, [r4, -r1, asr #28]
  64:	100e4101 	andne	r4, lr, r1, lsl #2
  68:	00070d41 	andeq	r0, r7, r1, asr #26
  6c:	0000000c 	andeq	r0, r0, ip
  70:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
  74:	7c020001 	stcvc	0, cr0, [r2], {1}
  78:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  7c:	00000018 	andeq	r0, r0, r8, lsl r0
  80:	0000006c 	andeq	r0, r0, ip, rrx
  84:	080000b0 	stmdaeq	r0, {r4, r5, r7}
  88:	0000000c 	andeq	r0, r0, ip
  8c:	87080e41 	strhi	r0, [r8, -r1, asr #28]
  90:	41018e02 	tstmi	r1, r2, lsl #28
  94:	0000070d 	andeq	r0, r0, sp, lsl #14
  98:	00000020 	andeq	r0, r0, r0, lsr #32
  9c:	0000006c 	andeq	r0, r0, ip, rrx
  a0:	080000bc 	stmdaeq	r0, {r2, r3, r4, r5, r7}
  a4:	00000084 	andeq	r0, r0, r4, lsl #1
  a8:	87080e41 	strhi	r0, [r8, -r1, asr #28]
  ac:	41018e02 	tstmi	r1, r2, lsl #28
  b0:	0d41200e 	stcleq	0, cr2, [r1, #-56]	; 0xffffffc8
  b4:	080e7307 	stmdaeq	lr, {r0, r1, r2, r8, r9, ip, sp, lr}
  b8:	000d0d41 	andeq	r0, sp, r1, asr #26
