
bin/kotori.elf:     file format elf64-littleriscv


Disassembly of section .text:

0000000080000000 <_start-0x4>:
    80000000:	004000ef          	jal	ra,80000004 <_start>

0000000080000004 <_start>:
    80000004:	00000117          	auipc	sp,0x0
    80000008:	7ac10113          	addi	sp,sp,1964 # 800007b0 <stack_addr>
    8000000c:	0ba000ef          	jal	ra,800000c6 <krnl>

0000000080000010 <memcpy>:
    80000010:	00a5c7b3          	xor	a5,a1,a0
    80000014:	8b9d                	andi	a5,a5,7
    80000016:	00c50733          	add	a4,a0,a2
    8000001a:	e781                	bnez	a5,80000022 <memcpy+0x12>
    8000001c:	479d                	li	a5,7
    8000001e:	00c7ee63          	bltu	a5,a2,8000003a <memcpy+0x2a>
    80000022:	87aa                	mv	a5,a0
    80000024:	0ae57063          	bleu	a4,a0,800000c4 <memcpy+0xb4>
    80000028:	0005c683          	lbu	a3,0(a1)
    8000002c:	0785                	addi	a5,a5,1
    8000002e:	0585                	addi	a1,a1,1
    80000030:	fed78fa3          	sb	a3,-1(a5)
    80000034:	fee7eae3          	bltu	a5,a4,80000028 <memcpy+0x18>
    80000038:	8082                	ret
    8000003a:	00757693          	andi	a3,a0,7
    8000003e:	87aa                	mv	a5,a0
    80000040:	ca91                	beqz	a3,80000054 <memcpy+0x44>
    80000042:	0005c683          	lbu	a3,0(a1)
    80000046:	0785                	addi	a5,a5,1
    80000048:	0585                	addi	a1,a1,1
    8000004a:	fed78fa3          	sb	a3,-1(a5)
    8000004e:	0077f693          	andi	a3,a5,7
    80000052:	b7fd                	j	80000040 <memcpy+0x30>
    80000054:	ff877693          	andi	a3,a4,-8
    80000058:	fc068613          	addi	a2,a3,-64
    8000005c:	06c7f063          	bleu	a2,a5,800000bc <memcpy+0xac>
    80000060:	0005b383          	ld	t2,0(a1)
    80000064:	0085b283          	ld	t0,8(a1)
    80000068:	0105bf83          	ld	t6,16(a1)
    8000006c:	0185bf03          	ld	t5,24(a1)
    80000070:	0205be83          	ld	t4,32(a1)
    80000074:	0285be03          	ld	t3,40(a1)
    80000078:	0305b303          	ld	t1,48(a1)
    8000007c:	0385b883          	ld	a7,56(a1)
    80000080:	04858593          	addi	a1,a1,72
    80000084:	0077b023          	sd	t2,0(a5)
    80000088:	ff85b803          	ld	a6,-8(a1)
    8000008c:	0057b423          	sd	t0,8(a5)
    80000090:	01f7b823          	sd	t6,16(a5)
    80000094:	01e7bc23          	sd	t5,24(a5)
    80000098:	03d7b023          	sd	t4,32(a5)
    8000009c:	03c7b423          	sd	t3,40(a5)
    800000a0:	0267b823          	sd	t1,48(a5)
    800000a4:	0317bc23          	sd	a7,56(a5)
    800000a8:	04878793          	addi	a5,a5,72
    800000ac:	ff07bc23          	sd	a6,-8(a5)
    800000b0:	b775                	j	8000005c <memcpy+0x4c>
    800000b2:	6190                	ld	a2,0(a1)
    800000b4:	07a1                	addi	a5,a5,8
    800000b6:	05a1                	addi	a1,a1,8
    800000b8:	fec7bc23          	sd	a2,-8(a5)
    800000bc:	fed7ebe3          	bltu	a5,a3,800000b2 <memcpy+0xa2>
    800000c0:	f6e7e4e3          	bltu	a5,a4,80000028 <memcpy+0x18>
    800000c4:	8082                	ret

Disassembly of section .text.krnl:

00000000800000c6 <krnl>:
    800000c6:	1141                	addi	sp,sp,-16
    800000c8:	e406                	sd	ra,8(sp)
    800000ca:	0be000ef          	jal	ra,80000188 <archKernelStart>
    800000ce:	0001                	nop
    800000d0:	bffd                	j	800000ce <krnl+0x8>

Disassembly of section .text._ZN2kt5riscv11trapHandlerEv:

00000000800000d2 <_ZN2kt5riscv11trapHandlerEv>:
    800000d2:	04200293          	li	t0,66
    800000d6:	8082                	ret

Disassembly of section .text._ZN2kt5riscv2vm7paToPPNEPv:

00000000800000d8 <_ZN2kt5riscv2vm7paToPPNEPv>:
    800000d8:	004007b7          	lui	a5,0x400
    800000dc:	02f54533          	div	a0,a0,a5
    800000e0:	8082                	ret

Disassembly of section .text._ZN2kt5riscv2vm10initMemoryEv:

00000000800000e2 <_ZN2kt5riscv2vm10initMemoryEv>:
    800000e2:	1101                	addi	sp,sp,-32
    800000e4:	ec06                	sd	ra,24(sp)
    800000e6:	180027f3          	csrr	a5,satp
    800000ea:	577d                	li	a4,-1
    800000ec:	8369                	srli	a4,a4,0x1a
    800000ee:	8ff9                	and	a5,a5,a4
    800000f0:	e43e                	sd	a5,8(sp)
    800000f2:	300027f3          	csrr	a5,mstatus
    800000f6:	83e1                	srli	a5,a5,0x18
    800000f8:	8bbd                	andi	a5,a5,15
    800000fa:	4731                	li	a4,12
    800000fc:	08f76163          	bltu	a4,a5,8000017e <_ZN2kt5riscv2vm10initMemoryEv+0x9c>
    80000100:	00000717          	auipc	a4,0x0
    80000104:	3c070713          	addi	a4,a4,960 # 800004c0 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x30>
    80000108:	078a                	slli	a5,a5,0x2
    8000010a:	97ba                	add	a5,a5,a4
    8000010c:	439c                	lw	a5,0(a5)
    8000010e:	97ba                	add	a5,a5,a4
    80000110:	8782                	jr	a5
    80000112:	00000517          	auipc	a0,0x0
    80000116:	3e650513          	addi	a0,a0,998 # 800004f8 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x68>
    8000011a:	2a6000ef          	jal	ra,800003c0 <printk>
    8000011e:	00400737          	lui	a4,0x400
    80000122:	00002797          	auipc	a5,0x2
    80000126:	6a678793          	addi	a5,a5,1702 # 800027c8 <_ZN2kt5riscv2vm9pageTableE>
    8000012a:	02e7c7b3          	div	a5,a5,a4
    8000012e:	18079073          	csrw	satp,a5
    80000132:	60e2                	ld	ra,24(sp)
    80000134:	6105                	addi	sp,sp,32
    80000136:	8082                	ret
    80000138:	00000517          	auipc	a0,0x0
    8000013c:	3e850513          	addi	a0,a0,1000 # 80000520 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x90>
    80000140:	bfe9                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    80000142:	00000517          	auipc	a0,0x0
    80000146:	40650513          	addi	a0,a0,1030 # 80000548 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0xb8>
    8000014a:	bfc1                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    8000014c:	00000517          	auipc	a0,0x0
    80000150:	42450513          	addi	a0,a0,1060 # 80000570 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0xe0>
    80000154:	b7d9                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    80000156:	00000517          	auipc	a0,0x0
    8000015a:	42a50513          	addi	a0,a0,1066 # 80000580 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0xf0>
    8000015e:	bf75                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    80000160:	00000517          	auipc	a0,0x0
    80000164:	43050513          	addi	a0,a0,1072 # 80000590 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x100>
    80000168:	bf4d                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    8000016a:	00000517          	auipc	a0,0x0
    8000016e:	43650513          	addi	a0,a0,1078 # 800005a0 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x110>
    80000172:	b765                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    80000174:	00000517          	auipc	a0,0x0
    80000178:	45450513          	addi	a0,a0,1108 # 800005c8 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x138>
    8000017c:	bf79                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>
    8000017e:	00000517          	auipc	a0,0x0
    80000182:	47250513          	addi	a0,a0,1138 # 800005f0 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x160>
    80000186:	bf51                	j	8000011a <_ZN2kt5riscv2vm10initMemoryEv+0x38>

Disassembly of section .text.archKernelStart:

0000000080000188 <archKernelStart>:
    80000188:	1141                	addi	sp,sp,-16
    8000018a:	00000517          	auipc	a0,0x0
    8000018e:	47e50513          	addi	a0,a0,1150 # 80000608 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x178>
    80000192:	e406                	sd	ra,8(sp)
    80000194:	22c000ef          	jal	ra,800003c0 <printk>
    80000198:	0001                	nop
    8000019a:	bffd                	j	80000198 <archKernelStart+0x10>

Disassembly of section .text._ZN2kt5riscv4proc9getHartIDEv:

000000008000019c <_ZN2kt5riscv4proc9getHartIDEv>:
    8000019c:	f1402573          	csrr	a0,mhartid
    800001a0:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6timersL15timerIRQhandlerEv:

00000000800001a2 <_ZN2kt5riscv6timersL15timerIRQhandlerEv>:
    800001a2:	0001                	nop
    800001a4:	bffd                	j	800001a2 <_ZN2kt5riscv6timersL15timerIRQhandlerEv>

Disassembly of section .text._ZN2kt5riscv6timers9setNewCMPEl:

00000000800001a6 <_ZN2kt5riscv6timers9setNewCMPEl>:
    800001a6:	0200c737          	lui	a4,0x200c
    800001aa:	ff873783          	ld	a5,-8(a4) # 200bff8 <_start-0x7dff400c>
    800001ae:	953e                	add	a0,a0,a5
    800001b0:	020047b7          	lui	a5,0x2004
    800001b4:	e388                	sd	a0,0(a5)
    800001b6:	ff873783          	ld	a5,-8(a4)
    800001ba:	82be                	mv	t0,a5
    800001bc:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6timers12rtcTimerInitEv:

00000000800001be <_ZN2kt5riscv6timers12rtcTimerInitEv>:
    800001be:	1141                	addi	sp,sp,-16
    800001c0:	6785                	lui	a5,0x1
    800001c2:	e406                	sd	ra,8(sp)
    800001c4:	8887879b          	addiw	a5,a5,-1912
    800001c8:	3047a073          	csrs	mie,a5
    800001cc:	00000597          	auipc	a1,0x0
    800001d0:	fd658593          	addi	a1,a1,-42 # 800001a2 <_ZN2kt5riscv6timersL15timerIRQhandlerEv>
    800001d4:	451d                	li	a0,7
    800001d6:	1ac000ef          	jal	ra,80000382 <_ZN2kt5riscv4inte19exAssignSyncHandlerENS1_11SyncExCodesEPFvvE>
    800001da:	60a2                	ld	ra,8(sp)
    800001dc:	6505                	lui	a0,0x1
    800001de:	fa050513          	addi	a0,a0,-96 # fa0 <_start-0x7ffff064>
    800001e2:	0141                	addi	sp,sp,16
    800001e4:	fc3ff06f          	j	800001a6 <_ZN2kt5riscv6timers9setNewCMPEl>

Disassembly of section .text._ZN2kt5riscv6sifiveL14uartAPIenqueueEmSt4byte:

00000000800001e8 <_ZN2kt5riscv6sifiveL14uartAPIenqueueEmSt4byte>:
    800001e8:	e519                	bnez	a0,800001f6 <_ZN2kt5riscv6sifiveL14uartAPIenqueueEmSt4byte+0xe>
    800001ea:	100137b7          	lui	a5,0x10013
    800001ee:	00b78023          	sb	a1,0(a5) # 10013000 <_start-0x6ffed004>
    800001f2:	4509                	li	a0,2
    800001f4:	8082                	ret
    800001f6:	450d                	li	a0,3
    800001f8:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6sifiveL14uartAPIdequeueEm:

00000000800001fa <_ZN2kt5riscv6sifiveL14uartAPIdequeueEm>:
    800001fa:	1101                	addi	sp,sp,-32
    800001fc:	c909                	beqz	a0,8000020e <_ZN2kt5riscv6sifiveL14uartAPIdequeueEm+0x14>
    800001fe:	00010023          	sb	zero,0(sp)
    80000202:	4791                	li	a5,4
    80000204:	e43e                	sd	a5,8(sp)
    80000206:	6502                	ld	a0,0(sp)
    80000208:	65a2                	ld	a1,8(sp)
    8000020a:	6105                	addi	sp,sp,32
    8000020c:	8082                	ret
    8000020e:	100137b7          	lui	a5,0x10013
    80000212:	0047c783          	lbu	a5,4(a5) # 10013004 <_start-0x6ffed000>
    80000216:	00f10823          	sb	a5,16(sp)
    8000021a:	4789                	li	a5,2
    8000021c:	ec3e                	sd	a5,24(sp)
    8000021e:	67c2                	ld	a5,16(sp)
    80000220:	e03e                	sd	a5,0(sp)
    80000222:	67e2                	ld	a5,24(sp)
    80000224:	b7c5                	j	80000204 <_ZN2kt5riscv6sifiveL14uartAPIdequeueEm+0xa>

Disassembly of section .text._ZN2kt5riscv6sifiveL16uartAPIenumerateERN3ktl6bufferINS_6serial4UARTEEE:

0000000080000226 <_ZN2kt5riscv6sifiveL16uartAPIenumerateERN3ktl6bufferINS_6serial4UARTEEE>:
    80000226:	651c                	ld	a5,8(a0)
    80000228:	c39d                	beqz	a5,8000024e <_ZN2kt5riscv6sifiveL16uartAPIenumerateERN3ktl6bufferINS_6serial4UARTEEE+0x28>
    8000022a:	1101                	addi	sp,sp,-32
    8000022c:	e822                	sd	s0,16(sp)
    8000022e:	4581                	li	a1,0
    80000230:	842a                	mv	s0,a0
    80000232:	850a                	mv	a0,sp
    80000234:	ec06                	sd	ra,24(sp)
    80000236:	1b8000ef          	jal	ra,800003ee <_ZN2kt6serial4UARTC1Em>
    8000023a:	6008                	ld	a0,0(s0)
    8000023c:	858a                	mv	a1,sp
    8000023e:	4631                	li	a2,12
    80000240:	0541                	addi	a0,a0,16
    80000242:	dcfff0ef          	jal	ra,80000010 <memcpy>
    80000246:	60e2                	ld	ra,24(sp)
    80000248:	6442                	ld	s0,16(sp)
    8000024a:	6105                	addi	sp,sp,32
    8000024c:	8082                	ret
    8000024e:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6sifive10SiFiveUARTC2Ev:

0000000080000250 <_ZN2kt5riscv6sifive10SiFiveUARTC1Ev>:
    80000250:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6sifive10SiFiveUART11enqueueDataESt4byte:

0000000080000252 <_ZN2kt5riscv6sifive10SiFiveUART11enqueueDataESt4byte>:
    80000252:	100137b7          	lui	a5,0x10013
    80000256:	00b78023          	sb	a1,0(a5) # 10013000 <_start-0x6ffed004>
    8000025a:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6sifive10SiFiveUART11dequeueDataEv:

000000008000025c <_ZN2kt5riscv6sifive10SiFiveUART11dequeueDataEv>:
    8000025c:	100137b7          	lui	a5,0x10013
    80000260:	0047c503          	lbu	a0,4(a5) # 10013004 <_start-0x6ffed000>
    80000264:	8082                	ret

Disassembly of section .text._ZN2kt5riscv6sifive4initEv:

0000000080000266 <_ZN2kt5riscv6sifive4initEv>:
    80000266:	00007797          	auipc	a5,0x7
    8000026a:	96278793          	addi	a5,a5,-1694 # 80006bc8 <_ZN2kt6serial4UART10uinterfaceE>
    8000026e:	00000717          	auipc	a4,0x0
    80000272:	fb870713          	addi	a4,a4,-72 # 80000226 <_ZN2kt5riscv6sifiveL16uartAPIenumerateERN3ktl6bufferINS_6serial4UARTEEE>
    80000276:	e398                	sd	a4,0(a5)
    80000278:	00000717          	auipc	a4,0x0
    8000027c:	f7070713          	addi	a4,a4,-144 # 800001e8 <_ZN2kt5riscv6sifiveL14uartAPIenqueueEmSt4byte>
    80000280:	e798                	sd	a4,8(a5)
    80000282:	00000717          	auipc	a4,0x0
    80000286:	f7870713          	addi	a4,a4,-136 # 800001fa <_ZN2kt5riscv6sifiveL14uartAPIdequeueEm>
    8000028a:	eb98                	sd	a4,16(a5)
    8000028c:	8082                	ret

Disassembly of section .text._ZN2kt5sched3PCBC2Ev:

000000008000028e <_ZN2kt5sched3PCBC1Ev>:
    8000028e:	8082                	ret

Disassembly of section .text._ZNK2kt5sched3PCB2idEv:

0000000080000290 <_ZNK2kt5sched3PCB2idEv>:
    80000290:	6108                	ld	a0,0(a0)
    80000292:	8082                	ret

Disassembly of section .text._ZNK2kt5sched3PCB4nextEv:

0000000080000294 <_ZNK2kt5sched3PCB4nextEv>:
    80000294:	6d08                	ld	a0,24(a0)
    80000296:	8082                	ret

Disassembly of section .text._ZN2kt5sched7ContextC2Eb:

0000000080000298 <_ZN2kt5sched7ContextC1Eb>:
    80000298:	00b50023          	sb	a1,0(a0)
    8000029c:	8082                	ret

Disassembly of section .text._ZN2kt5sched3TCB6parentEv:

000000008000029e <_ZN2kt5sched3TCB6parentEv>:
    8000029e:	1c053503          	ld	a0,448(a0)
    800002a2:	8082                	ret

Disassembly of section .text.enaint:

00000000800002a4 <enaint>:
    800002a4:	00000293          	li	t0,0
    800002a8:	02a1                	addi	t0,t0,8
    800002aa:	30029073          	csrw	mstatus,t0
    800002ae:	8082                	ret

Disassembly of section .text.disint:

00000000800002b0 <disint>:
    800002b0:	4781                	li	a5,0
    800002b2:	30479073          	csrw	mie,a5
    800002b6:	8082                	ret

Disassembly of section .text._ZN2kt5riscv4inte12queryExCauseEv:

00000000800002b8 <_ZN2kt5riscv4inte12queryExCauseEv>:
    800002b8:	142027f3          	csrr	a5,scause
    800002bc:	00f03733          	snez	a4,a5
    800002c0:	00e50023          	sb	a4,0(a0)
    800002c4:	c781                	beqz	a5,800002cc <_ZN2kt5riscv4inte12queryExCauseEv+0x14>
    800002c6:	0786                	slli	a5,a5,0x1
    800002c8:	e51c                	sd	a5,8(a0)
    800002ca:	8082                	ret
    800002cc:	00053823          	sd	zero,16(a0)
    800002d0:	8082                	ret

Disassembly of section .text._ZN2kt5riscv4inte14exSyncDispatchENS1_11SyncExCodesE:

00000000800002d2 <_ZN2kt5riscv4inte14exSyncDispatchENS1_11SyncExCodesE>:
    800002d2:	03f00793          	li	a5,63
    800002d6:	02a7e963          	bltu	a5,a0,80000308 <_ZN2kt5riscv4inte14exSyncDispatchENS1_11SyncExCodesE+0x36>
    800002da:	00006797          	auipc	a5,0x6
    800002de:	4ee78793          	addi	a5,a5,1262 # 800067c8 <_ZN2kt5riscv4inteL4syncE>
    800002e2:	050e                	slli	a0,a0,0x3
    800002e4:	953e                	add	a0,a0,a5
    800002e6:	611c                	ld	a5,0(a0)
    800002e8:	1141                	addi	sp,sp,-16
    800002ea:	e406                	sd	ra,8(sp)
    800002ec:	eb99                	bnez	a5,80000302 <_ZN2kt5riscv4inte14exSyncDispatchENS1_11SyncExCodesE+0x30>
    800002ee:	00000517          	auipc	a0,0x0
    800002f2:	33a50513          	addi	a0,a0,826 # 80000628 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x198>
    800002f6:	0ca000ef          	jal	ra,800003c0 <printk>
    800002fa:	4501                	li	a0,0
    800002fc:	60a2                	ld	ra,8(sp)
    800002fe:	0141                	addi	sp,sp,16
    80000300:	8082                	ret
    80000302:	9782                	jalr	a5
    80000304:	450d                	li	a0,3
    80000306:	bfdd                	j	800002fc <_ZN2kt5riscv4inte14exSyncDispatchENS1_11SyncExCodesE+0x2a>
    80000308:	4505                	li	a0,1
    8000030a:	8082                	ret

Disassembly of section .text._ZN2kt5riscv4inte15exAsyncDispatchENS1_12AsyncExCodesE:

000000008000030c <_ZN2kt5riscv4inte15exAsyncDispatchENS1_12AsyncExCodesE>:
    8000030c:	03f00793          	li	a5,63
    80000310:	02a7eb63          	bltu	a5,a0,80000346 <_ZN2kt5riscv4inte15exAsyncDispatchENS1_12AsyncExCodesE+0x3a>
    80000314:	00006797          	auipc	a5,0x6
    80000318:	4b478793          	addi	a5,a5,1204 # 800067c8 <_ZN2kt5riscv4inteL4syncE>
    8000031c:	050e                	slli	a0,a0,0x3
    8000031e:	953e                	add	a0,a0,a5
    80000320:	611c                	ld	a5,0(a0)
    80000322:	1141                	addi	sp,sp,-16
    80000324:	e406                	sd	ra,8(sp)
    80000326:	eb99                	bnez	a5,8000033c <_ZN2kt5riscv4inte15exAsyncDispatchENS1_12AsyncExCodesE+0x30>
    80000328:	00000517          	auipc	a0,0x0
    8000032c:	39850513          	addi	a0,a0,920 # 800006c0 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x230>
    80000330:	090000ef          	jal	ra,800003c0 <printk>
    80000334:	4501                	li	a0,0
    80000336:	60a2                	ld	ra,8(sp)
    80000338:	0141                	addi	sp,sp,16
    8000033a:	8082                	ret
    8000033c:	20053783          	ld	a5,512(a0)
    80000340:	9782                	jalr	a5
    80000342:	450d                	li	a0,3
    80000344:	bfcd                	j	80000336 <_ZN2kt5riscv4inte15exAsyncDispatchENS1_12AsyncExCodesE+0x2a>
    80000346:	4505                	li	a0,1
    80000348:	8082                	ret

Disassembly of section .text._ZN2kt5riscv4inte17trapVectorHandlerEv:

000000008000034c <_ZN2kt5riscv4inte17trapVectorHandlerEv>:
    8000034c:	7139                	addi	sp,sp,-64
    8000034e:	0828                	addi	a0,sp,24
    80000350:	fc06                	sd	ra,56(sp)
    80000352:	f67ff0ef          	jal	ra,800002b8 <_ZN2kt5riscv4inte12queryExCauseEv>
    80000356:	00000517          	auipc	a0,0x0
    8000035a:	40a50513          	addi	a0,a0,1034 # 80000760 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x2d0>
    8000035e:	062000ef          	jal	ra,800003c0 <printk>
    80000362:	01814783          	lbu	a5,24(sp)
    80000366:	cb81                	beqz	a5,80000376 <_ZN2kt5riscv4inte17trapVectorHandlerEv+0x2a>
    80000368:	7502                	ld	a0,32(sp)
    8000036a:	f69ff0ef          	jal	ra,800002d2 <_ZN2kt5riscv4inte14exSyncDispatchENS1_11SyncExCodesE>
    8000036e:	e42a                	sd	a0,8(sp)
    80000370:	70e2                	ld	ra,56(sp)
    80000372:	6121                	addi	sp,sp,64
    80000374:	8082                	ret
    80000376:	7522                	ld	a0,40(sp)
    80000378:	f95ff0ef          	jal	ra,8000030c <_ZN2kt5riscv4inte15exAsyncDispatchENS1_12AsyncExCodesE>
    8000037c:	e82a                	sd	a0,16(sp)
    8000037e:	bfcd                	j	80000370 <_ZN2kt5riscv4inte17trapVectorHandlerEv+0x24>
	...

Disassembly of section .text._ZN2kt5riscv4inte19exAssignSyncHandlerENS1_11SyncExCodesEPFvvE:

0000000080000382 <_ZN2kt5riscv4inte19exAssignSyncHandlerENS1_11SyncExCodesEPFvvE>:
    80000382:	03f00793          	li	a5,63
    80000386:	00a7eb63          	bltu	a5,a0,8000039c <_ZN2kt5riscv4inte19exAssignSyncHandlerENS1_11SyncExCodesEPFvvE+0x1a>
    8000038a:	00006797          	auipc	a5,0x6
    8000038e:	43e78793          	addi	a5,a5,1086 # 800067c8 <_ZN2kt5riscv4inteL4syncE>
    80000392:	050e                	slli	a0,a0,0x3
    80000394:	953e                	add	a0,a0,a5
    80000396:	e10c                	sd	a1,0(a0)
    80000398:	450d                	li	a0,3
    8000039a:	8082                	ret
    8000039c:	4505                	li	a0,1
    8000039e:	8082                	ret

Disassembly of section .text._ZN2kt5riscv4inte20exAssignAsyncHandlerENS1_12AsyncExCodesEPFvvE:

00000000800003a0 <_ZN2kt5riscv4inte20exAssignAsyncHandlerENS1_12AsyncExCodesEPFvvE>:
    800003a0:	03f00793          	li	a5,63
    800003a4:	00a7ec63          	bltu	a5,a0,800003bc <_ZN2kt5riscv4inte20exAssignAsyncHandlerENS1_12AsyncExCodesEPFvvE+0x1c>
    800003a8:	00006797          	auipc	a5,0x6
    800003ac:	42078793          	addi	a5,a5,1056 # 800067c8 <_ZN2kt5riscv4inteL4syncE>
    800003b0:	050e                	slli	a0,a0,0x3
    800003b2:	953e                	add	a0,a0,a5
    800003b4:	20b53023          	sd	a1,512(a0)
    800003b8:	450d                	li	a0,3
    800003ba:	8082                	ret
    800003bc:	4505                	li	a0,1
    800003be:	8082                	ret

Disassembly of section .text.printk:

00000000800003c0 <printk>:
    800003c0:	1141                	addi	sp,sp,-16
    800003c2:	00000597          	auipc	a1,0x0
    800003c6:	3be58593          	addi	a1,a1,958 # 80000780 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x2f0>
    800003ca:	00007517          	auipc	a0,0x7
    800003ce:	81650513          	addi	a0,a0,-2026 # 80006be0 <_ZN2kt7utilityL6htifioE>
    800003d2:	e406                	sd	ra,8(sp)
    800003d4:	0bc000ef          	jal	ra,80000490 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc>
    800003d8:	00000597          	auipc	a1,0x0
    800003dc:	3a858593          	addi	a1,a1,936 # 80000780 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x2f0>
    800003e0:	00007517          	auipc	a0,0x7
    800003e4:	80050513          	addi	a0,a0,-2048 # 80006be0 <_ZN2kt7utilityL6htifioE>
    800003e8:	0a8000ef          	jal	ra,80000490 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc>
    800003ec:	a001                	j	800003ec <printk+0x2c>

Disassembly of section .text._ZN2kt6serial4UARTC2Em:

00000000800003ee <_ZN2kt6serial4UARTC1Em>:
    800003ee:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UART9enumerateERN3ktl6bufferIS1_EE:

00000000800003f0 <_ZN2kt6serial4UART9enumerateERN3ktl6bufferIS1_EE>:
    800003f0:	00006797          	auipc	a5,0x6
    800003f4:	7d878793          	addi	a5,a5,2008 # 80006bc8 <_ZN2kt6serial4UART10uinterfaceE>
    800003f8:	0007b303          	ld	t1,0(a5)
    800003fc:	8302                	jr	t1

Disassembly of section .text._ZNK2kt6serial4UART2idEv:

00000000800003fe <_ZNK2kt6serial4UART2idEv>:
    800003fe:	6108                	ld	a0,0(a0)
    80000400:	8082                	ret

Disassembly of section .text._ZN2kt6serialanENS0_4UART14CommAccessMaskES2_:

0000000080000402 <_ZN2kt6serialanENS0_4UART14CommAccessMaskES2_>:
    80000402:	8d6d                	and	a0,a0,a1
    80000404:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UARTC2Ev:

0000000080000406 <_ZN2kt6serial4UARTC1Ev>:
    80000406:	4791                	li	a5,4
    80000408:	00053023          	sd	zero,0(a0)
    8000040c:	c51c                	sw	a5,8(a0)
    8000040e:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UARTC2EPKcNS1_14CommAccessMaskE:

0000000080000410 <_ZN2kt6serial4UARTC1EPKcNS1_14CommAccessMaskE>:
    80000410:	00053023          	sd	zero,0(a0)
    80000414:	c510                	sw	a2,8(a0)
    80000416:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UART10accessMaskEv:

0000000080000418 <_ZN2kt6serial4UART10accessMaskEv>:
    80000418:	4508                	lw	a0,8(a0)
    8000041a:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UART6enableENS1_14CommAccessMaskE:

000000008000041c <_ZN2kt6serial4UART6enableENS1_14CommAccessMaskE>:
    8000041c:	c50c                	sw	a1,8(a0)
    8000041e:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UART7enqueueESt4byte:

0000000080000420 <_ZN2kt6serial4UART7enqueueESt4byte>:
    80000420:	451c                	lw	a5,8(a0)
    80000422:	8b89                	andi	a5,a5,2
    80000424:	cb89                	beqz	a5,80000436 <_ZN2kt6serial4UART7enqueueESt4byte+0x16>
    80000426:	00006797          	auipc	a5,0x6
    8000042a:	7a278793          	addi	a5,a5,1954 # 80006bc8 <_ZN2kt6serial4UART10uinterfaceE>
    8000042e:	0087b303          	ld	t1,8(a5)
    80000432:	6108                	ld	a0,0(a0)
    80000434:	8302                	jr	t1
    80000436:	4505                	li	a0,1
    80000438:	8082                	ret

Disassembly of section .text._ZN2kt6serial4UART7dequeueEv:

000000008000043a <_ZN2kt6serial4UART7dequeueEv>:
    8000043a:	451c                	lw	a5,8(a0)
    8000043c:	8b85                	andi	a5,a5,1
    8000043e:	cb89                	beqz	a5,80000450 <_ZN2kt6serial4UART7dequeueEv+0x16>
    80000440:	00006797          	auipc	a5,0x6
    80000444:	78878793          	addi	a5,a5,1928 # 80006bc8 <_ZN2kt6serial4UART10uinterfaceE>
    80000448:	0107b303          	ld	t1,16(a5)
    8000044c:	6108                	ld	a0,0(a0)
    8000044e:	8302                	jr	t1
    80000450:	1141                	addi	sp,sp,-16
    80000452:	00010023          	sb	zero,0(sp)
    80000456:	4785                	li	a5,1
    80000458:	e43e                	sd	a5,8(sp)
    8000045a:	6502                	ld	a0,0(sp)
    8000045c:	65a2                	ld	a1,8(sp)
    8000045e:	0141                	addi	sp,sp,16
    80000460:	8082                	ret

Disassembly of section .text._ZN2kt5riscv5spike6HtifIO5cputcEl:

0000000080000462 <_ZN2kt5riscv5spike6HtifIO5cputcEl>:
    80000462:	00006717          	auipc	a4,0x6
    80000466:	78e70713          	addi	a4,a4,1934 # 80006bf0 <tohost>
    8000046a:	00006797          	auipc	a5,0x6
    8000046e:	77e78793          	addi	a5,a5,1918 # 80006be8 <fromhost>
    80000472:	6314                	ld	a3,0(a4)
    80000474:	c299                	beqz	a3,8000047a <_ZN2kt5riscv5spike6HtifIO5cputcEl+0x18>
    80000476:	6394                	ld	a3,0(a5)
    80000478:	bfed                	j	80000472 <_ZN2kt5riscv5spike6HtifIO5cputcEl+0x10>
    8000047a:	10100793          	li	a5,257
    8000047e:	17c2                	slli	a5,a5,0x30
    80000480:	0ff5f593          	andi	a1,a1,255
    80000484:	8ddd                	or	a1,a1,a5
    80000486:	00006797          	auipc	a5,0x6
    8000048a:	76b7b523          	sd	a1,1898(a5) # 80006bf0 <tohost>
    8000048e:	8082                	ret

Disassembly of section .text._ZN2kt5riscv5spike6HtifIO12print_stringEPKc:

0000000080000490 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc>:
    80000490:	1101                	addi	sp,sp,-32
    80000492:	e822                	sd	s0,16(sp)
    80000494:	e426                	sd	s1,8(sp)
    80000496:	e04a                	sd	s2,0(sp)
    80000498:	ec06                	sd	ra,24(sp)
    8000049a:	84aa                	mv	s1,a0
    8000049c:	842e                	mv	s0,a1
    8000049e:	02e00913          	li	s2,46
    800004a2:	00044583          	lbu	a1,0(s0)
    800004a6:	01258763          	beq	a1,s2,800004b4 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x24>
    800004aa:	8526                	mv	a0,s1
    800004ac:	0405                	addi	s0,s0,1
    800004ae:	fb5ff0ef          	jal	ra,80000462 <_ZN2kt5riscv5spike6HtifIO5cputcEl>
    800004b2:	bfc5                	j	800004a2 <_ZN2kt5riscv5spike6HtifIO12print_stringEPKc+0x12>
    800004b4:	60e2                	ld	ra,24(sp)
    800004b6:	6442                	ld	s0,16(sp)
    800004b8:	64a2                	ld	s1,8(sp)
    800004ba:	6902                	ld	s2,0(sp)
    800004bc:	6105                	addi	sp,sp,32
    800004be:	8082                	ret
