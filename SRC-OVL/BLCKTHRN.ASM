_TEXT SEGMENT BYTE 'CODE'
ORG 0a0aeh
SUB_0000_a0ae:
ORG 9856h
SUB_0000_9856:
ORG 75c0h
SUB_0000_75c0:
ORG 988ch
SUB_0000_988c:
ORG 7edch
SUB_0000_7edc:
ORG 7da2h
SUB_0000_7da2:
ORG 7f02h
SUB_0000_7f02:
ORG 9292h
SUB_0000_9292:
ORG 8670h
SUB_0000_8670:
ORG 83dch
SUB_0000_83dc:
ORG 742ah
SUB_0000_742a:
ORG 9ca6h
SUB_0000_9ca6:
ORG 0acech
SUB_0000_acec:
ORG 0b680h
SUB_0000_b680:
ORG 67e0h
SUB_0000_67e0:
ORG 6816h
SUB_0000_6816:
ORG 0a7f4h
SUB_0000_a7f4:
ORG 8c06h
SUB_0000_8c06:
ORG 7e6ah
SUB_0000_7e6a:
ORG 97e4h
SUB_0000_97e4:
ORG 82deh
SUB_0000_82de:
ORG 0aae6h
SUB_0000_aae6:
ORG 6dd8h
SUB_0000_6dd8:
ORG 828eh
SUB_0000_828e:
ORG 73e4h
SUB_0000_73e4:
ORG 0dc72h
SUB_0000_dc72:
ORG 6992h
SUB_0000_6992:
ORG 6cb6h
SUB_0000_6cb6:
ORG 8de2h
SUB_0000_8de2:
ORG 6110h
SUB_0000_6110:
ORG 0dc66h
SUB_0000_dc66:
ORG 6e50h
SUB_0000_6e50:
ORG 0d7b6h
SUB_0000_d7b6:
_TEXT ENDS
DGROUP GROUP _DATA, _BSS
_DATA SEGMENT PUBLIC WORD 'DATA'
	ASSUME DS:DGROUP
_DATA ENDS
_BSS SEGMENT PUBLIC WORD 'BSS'
_BSS ENDS
_TEXT SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT
	ORG 0h
	; Func
F_0000 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -2h],0h
	CMP        word ptr [BP + 4h],0h
	JLE        L_0027
	MOV        SI,word ptr [BP + 4h]
	MOV        AX,SI
	ADD        word ptr [BP + -2h],AX
L_001a:
	CALL       SUB_0000_a0ae
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9856
	DEC        SI
	JNZ        L_001a
L_0027:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0000 ENDP
F_002e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,word ptr [BP + 4h]
	AND        AX,0fch
	CMP        AX,10h
	JZ         L_0056
	CMP        AX,14h
	JZ         L_007c
	CMP        AX,18h
	JZ         L_0084
	CMP        AX,1ch
	JZ         L_008c
	CMP        AX,20h
	JZ         L_0094
	JMP        L_005b
	db 90h
L_0056:
	MOV        word ptr [BP + -2h],6h
L_005b:
	SUB        AX,AX
	MOV        DS:[5878h],AX
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BP + 4h]
	AND        AX,3h
	JZ         L_009c
	CMP        AX,1h
	JZ         L_00ac
	CMP        AX,2h
	JZ         L_00a6
	CMP        AX,3h
	JZ         L_00b2
	JMP        L_00a0
L_007c:
	MOV        word ptr [BP + -2h],7h
	JMP        L_005b
	db 90h
L_0084:
	MOV        word ptr [BP + -2h],8h
	JMP        L_005b
	db 90h
L_008c:
	MOV        word ptr [BP + -2h],0h
	JMP        L_005b
	db 90h
L_0094:
	MOV        word ptr [BP + -2h],1h
	JMP        L_005b
	db 90h
L_009c:
	DEC        word ptr DS:[5878h]
L_00a0:
	MOV        AX,word ptr [BP + -2h]
	JMP        L_00b8
	db 90h
L_00a6:
	INC        word ptr DS:[5878h]
	JMP        L_00a0
L_00ac:
	INC        word ptr DS:[5876h]
	JMP        L_00a0
L_00b2:
	DEC        word ptr DS:[5876h]
	JMP        L_00a0
L_00b8:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_002e ENDP
F_00be PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,26h
	PUSH       DI
	PUSH       SI
	MOV        DI,1h
	MOV        word ptr [BP + -4h],DI
	JMP        L_023e
	db 90h
	db 0C7h
	db 46h
	db 0F8h
	db 01h
	db 00h
	db 0E9h
	db 6Bh
	db 01h
	db 8Bh
	db 5Eh
	db 04h
	db 8Ah
	db 07h
	db 2Ah
	db 0E4h
	db 89h
	db 46h
	db 0FCh
	db 0FFh
	db 46h
	db 04h
	db 0E9h
	db 5Bh
	db 01h
	db 0BFh
	db 01h
	db 00h
	db 0E9h
	db 55h
	db 01h
	db 2Bh
	db 0FFh
	db 0E9h
	db 50h
	db 01h
	db 90h
	db 8Bh
	db 5Eh
	db 04h
	db 0FFh
	db 46h
	db 04h
	db 8Ah
	db 07h
	db 2Ah
	db 0E4h
	db 50h
	db 0E8h
	db 54h
	db 97h
	db 0E9h
	db 3Eh
	db 01h
	db 90h
	db 8Bh
	db 5Eh
	db 04h
	db 8Ah
	db 07h
	db 2Ah
	db 0E4h
	db 89h
	db 46h
	db 0F4h
	db 0FFh
	db 46h
	db 04h
	db 8Bh
	db 5Eh
	db 04h
	db 8Ah
	db 07h
	db 89h
	db 46h
	db 0F0h
	db 0FFh
	db 46h
	db 04h
	db 8Bh
	db 5Eh
	db 04h
	db 8Ah
	db 07h
	db 89h
	db 46h
	db 0ECh
	db 0FFh
	db 46h
	db 04h
	db 8Bh
	db 0F0h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 8Bh
	db 5Eh
	db 0F0h
	db 8Ah
	db 46h
	db 0F4h
	db 88h
	db 80h
	db 14h
	db 0ADh
	db 0E9h
	db 07h
	db 01h
	db 0E8h
	db 41h
	db 0B5h
	db 0E9h
	db 01h
	db 01h
	db 0FFh
	db 76h
	db 0FCh
	db 0E8h
	db 0B8h
	db 0FEh
	db 0C7h
	db 46h
	db 0FCh
	db 01h
	db 00h
	db 0E9h
	db 0F3h
	db 00h
	db 8Bh
	db 5Eh
	db 04h
	db 8Ah
	db 07h
	db 2Ah
	db 0E4h
	db 89h
	db 46h
	db 0F4h
	db 0FFh
	db 46h
	db 04h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 89h
	db 46h
	db 0DAh
	db 8Bh
	db 0D8h
	db 8Bh
	db 0F0h
	db 2Ah
	db 0C0h
	db 88h
	db 84h
	db 5Bh
	db 5Ch
	db 88h
	db 87h
	db 5Ah
	db 5Ch
	db 0E9h
	db 0CEh
	db 00h
	db 90h
	db 60h
	db 0A3h
	db 68h
	db 0A3h
	db 78h
	db 0A3h
	db 7Eh
	db 0A3h
	db 84h
	db 0A3h
	db 96h
	db 0A3h
	db 0CCh
	db 0A3h
	db 0D2h
	db 0A3h
	db 0E0h
	db 0A3h
	db 0E9h
	db 0B8h
	db 00h
	db 90h
L_018c:
	PUSH       word ptr [BP + -2h]
	CALL       F_002e
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -10h],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -14h],AX
	CMP        word ptr [BP + -8h],0h
	JZ         L_01c4
	MOV        BX,word ptr [BP + 4h]
	INC        word ptr [BP + 4h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       F_002e
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -12h],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -16h],AX
L_01c4:
	MOV        word ptr [BP + -6h],0h
	CMP        word ptr [BP + -4h],0h
	JLE        L_0239
	MOV        AX,word ptr [BP + -0eh]
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -22h],AX
	ADD        AX,5c5dh
	MOV        word ptr [BP + -18h],AX
	MOV        AX,word ptr [BP + -22h]
	ADD        AX,5c5ch
	MOV        word ptr [BP + -1ah],AX
	MOV        AX,word ptr [BP + -0ch]
	SHL        AX,CL
	MOV        word ptr [BP + -24h],AX
	ADD        AX,5c5dh
	MOV        word ptr [BP + -1ch],AX
	MOV        AX,word ptr [BP + -24h]
	ADD        AX,5c5ch
	MOV        word ptr [BP + -1eh],AX
	MOV        SI,word ptr [BP + -4h]
	ADD        word ptr [BP + -6h],SI
L_0205:
	MOV        BX,word ptr [BP + -1eh]
	MOV        AL,byte ptr [BP + -10h]
	ADD        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -1ch]
	MOV        AL,byte ptr [BP + -14h]
	ADD        byte ptr [BX],AL
	CMP        word ptr [BP + -8h],0h
	JZ         L_022b
	MOV        BX,word ptr [BP + -1ah]
	MOV        AL,byte ptr [BP + -12h]
	ADD        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -18h]
	MOV        AL,byte ptr [BP + -16h]
	ADD        byte ptr [BX],AL
L_022b:
	OR         DI,DI
	JZ         L_0236
	MOV        AX,1h
	PUSH       AX
	CALL       F_0000
L_0236:
	DEC        SI
	JNZ        L_0205
L_0239:
	MOV        word ptr [BP + -4h],1h
L_023e:
	MOV        word ptr [BP + -8h],0h
L_0243:
	MOV        BX,word ptr [BP + 4h]
	INC        word ptr [BP + 4h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JZ         L_026c
	CMP        AX,10h
	JL         L_025c
	JMP        L_018c
L_025c:
	SUB        AX,1h
	CMP        AX,8h
	JA         L_0243
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0a406h]
L_026c:
	MOV        word ptr [BP + -0ah],DI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_00be ENDP
F_0278 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,word ptr [BP + 6h]
	OR         AX,AX
	JZ         L_0294
	CMP        AX,1h
	JZ         L_02b0
	CMP        AX,2h
	JZ         L_02c8
	CMP        AX,3h
	JZ         L_02e0
	JMP        L_02e6
	db 90h
L_0294:
	MOV        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,1h
	PUSH       word ptr [BX + 1f4eh]
	CALL       SUB_0000_75c0
	MOV        AX,6f6eh
L_02aa:
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_02e6
L_02b0:
	MOV        AX,0b24bh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,1h
	PUSH       word ptr [BX + 1f4eh]
	CALL       SUB_0000_75c0
	MOV        AX,6f72h
	JMP        L_02aa
L_02c8:
	MOV        AX,0b270h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,1h
	PUSH       word ptr [BX + 1f4eh]
	CALL       SUB_0000_75c0
	MOV        AX,6f76h
	JMP        L_02aa
L_02e0:
	MOV        AX,0b2cah
	JMP        L_02aa
	db 90h
L_02e6:
	POP        BP
	RET        4h
	; Func
F_0278 ENDP
F_02ea PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,20h
	PUSH       DI
	PUSH       SI
	MOV        AX,6f7ah
	PUSH       AX
	CALL       SUB_0000_75c0
	LEA        AX,[BP + -12h]
	PUSH       AX
	MOV        AX,0eh
	PUSH       AX
	CALL       SUB_0000_988c
	MOV        AX,6f8eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,1h
	PUSH       word ptr [BX + 1f5eh]
	CALL       SUB_0000_7edc
	MOV        word ptr [BP + -1ah],AX
	MOV        word ptr [BP + -14h],0h
	MOV        word ptr [BP + -16h],0h
	LEA        AX,[BP + -12h]
	PUSH       AX
	CALL       SUB_0000_7edc
	CMP        AX,word ptr [BP + -1ah]
	JL         L_03a2
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	ADD        AX,1f5eh
	MOV        word ptr [BP + -1eh],AX
	MOV        DI,word ptr [BP + -1ah]
L_033e:
	MOV        word ptr [BP + -14h],1h
	SUB        SI,SI
	OR         DI,DI
	JLE        L_0379
	MOV        AX,word ptr [BP + -1eh]
	MOV        word ptr [BP + -1ch],AX
L_034f:
	MOV        BX,word ptr [BP + -1ch]
	MOV        BX,word ptr [BX]
	MOV        AL,byte ptr [BX + SI]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_7da2
	MOV        BX,word ptr [BP + -16h]
	ADD        BX,SI
	ADD        BX,BP
	MOV        CL,byte ptr [BX + -12h]
	SUB        CH,CH
	PUSH       CX
	MOV        word ptr [BP + -20h],AX
	CALL       SUB_0000_7da2
	CMP        AX,word ptr [BP + -20h]
	JZ         L_0386
	MOV        word ptr [BP + -14h],0h
L_0379:
	CMP        word ptr [BP + -14h],0h
	JZ         L_038e
L_037f:
	MOV        word ptr [BP + -18h],SI
	JMP        L_03a2
	db 90h
	db 90h
L_0386:
	INC        SI
	CMP        SI,DI
	JGE        L_0379
	JMP        L_034f
	db 90h
L_038e:
	INC        word ptr [BP + -16h]
	LEA        AX,[BP + -12h]
	PUSH       AX
	CALL       SUB_0000_7edc
	SUB        AX,DI
	CMP        AX,word ptr [BP + -16h]
	JL         L_037f
	JMP        L_033e
	db 90h
L_03a2:
	MOV        AX,word ptr [BP + -14h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_02ea ENDP
F_03ae PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2eh
	PUSH       DI
	PUSH       SI
	CMP        word ptr [BP + 4h],0h
	JZ         L_03c2
	MOV        AX,0b30fh
	JMP        L_03c5
	db 90h
L_03c2:
	MOV        AX,0b34bh
L_03c5:
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_9856
	MOV        SI,7d0h
L_03d3:
	MOV        AX,0a50h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7f02
	ADD        SI,32h
	CMP        SI,61a8h
	JL         L_03d3
	MOV        word ptr [BP + -22h],SI
	MOV        SI,61a8h
L_03f5:
	MOV        AX,0a50h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7f02
	SUB        SI,32h
	CMP        SI,7d0h
	JG         L_03f5
	MOV        word ptr [BP + -22h],SI
	MOV        AL,DS:[5c64h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5c65h]
	PUSH       AX
	CALL       SUB_0000_9292
	SUB        AL,AL
	MOV        DS:[5c63h],AL
	MOV        DS:[5c62h],AL
	MOV        byte ptr DS:[0adf9h],80h
	MOV        word ptr [BP + -24h],0h
	MOV        word ptr [BP + -26h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_046c
	MOV        DI,AX
	MOV        SI,55b3h
	MOV        DX,word ptr [BP + -26h]
	MOV        CX,word ptr [BP + -24h]
L_044c:
	CMP        byte ptr [SI],44h
	JZ         L_0452
	INC        CX
L_0452:
	CMP        CX,2h
	JNZ        L_0460
L_0457:
	MOV        word ptr [BP + -26h],DX
	MOV        word ptr [BP + -24h],CX
	JMP        L_046c
	db 90h
L_0460:
	ADD        SI,20h
	INC        DX
	MOV        AX,DX
	CMP        AX,DI
	JNC        L_0457
	JMP        L_044c
L_046c:
	MOV        BX,word ptr [BP + -26h]
	MOV        CL,5h
	SHL        BX,CL
	LEA        DI,[BP + -20h]
	LEA        SI,[BX + 55a8h]
	PUSH       SS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	MOV        AX,word ptr [BP + -26h]
	MOV        word ptr [BP + -22h],AX
	CMP        AX,0fh
	JGE        L_04c2
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -2eh],AX
	MOV        DI,AX
	ADD        DI,55a8h
	MOV        SI,AX
	ADD        SI,55c8h
	MOV        AX,0fh
	SUB        AX,word ptr [BP + -26h]
	MOV        word ptr [BP + -2ch],AX
	ADD        word ptr [BP + -22h],AX
L_04ab:
	PUSH       SI
	PUSH       DI
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	ADD        DI,20h
	ADD        SI,20h
	CMP        SI,57a8h
	JNZ        L_04ab
L_04c2:
	MOV        DI,5788h
	LEA        SI,[BP + -20h]
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	MOV        byte ptr DS:[57a7h],7fh
	DEC        byte ptr DS:[585bh]
	CALL       SUB_0000_8670
	CMP        word ptr [BP + 4h],0h
	JZ         L_0500
	MOV        AX,6f92h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,5788h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,6f96h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_83dc
	MOV        AX,0b3beh
	PUSH       AX
	CALL       SUB_0000_75c0
L_0500:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_03ae ENDP
F_0510 PROC NEAR
	CALL       SUB_0000_83dc
	MOV        AX,369eh
	PUSH       AX
	CALL       F_00be
	RET
	db 90h
	; Func
F_0510 ENDP
F_051c PROC NEAR
	MOV        AX,0b447h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,36dah
	PUSH       AX
	CALL       F_00be
	MOV        AX,0b47dh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,55c8h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,6fach
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_83dc
	MOV        AX,6fb4h
	PUSH       AX
	CALL       SUB_0000_75c0
	RET
	; Func
F_051c ENDP
F_054a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],0h
	MOV        AX,6fb8h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        SI,SI
	MOV        DI,word ptr [BP + 6h]
L_0563:
	PUSH       SI
	PUSH       DI
	CALL       F_0278
	PUSH       DI
	CALL       F_02ea
	OR         AX,AX
	JZ         L_059e
	MOV        byte ptr [DI + 58d8h],0ffh
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_9ca6
	CMP        word ptr [BP + 4h],1h
	JLE        L_058e
	SUB        AX,AX
	PUSH       AX
	CALL       F_03ae
	JMP        L_0595
L_058e:
	MOV        AX,0b4bah
L_0591:
	PUSH       AX
	CALL       SUB_0000_75c0
L_0595:
	CALL       F_0510
L_0598:
	MOV        word ptr [BP + -2h],SI
	JMP        L_0606
	db 90h
L_059e:
	CMP        word ptr [BP + 4h],2h
	JGE        L_05aa
	MOV        AX,0b4fah
	JMP        L_0591
	db 90h
L_05aa:
	CMP        word ptr [BP + -4h],0h
	JZ         L_05f4
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_acec
	CALL       SUB_0000_8670
	MOV        AX,SI
	OR         AX,AX
	JZ         L_05d2
	CMP        AX,1h
	JZ         L_05da
	CMP        AX,2h
	JZ         L_05e2
	CMP        AX,3h
	JZ         L_05ea
	JMP        L_05fc
	db 90h
L_05d2:
	MOV        byte ptr DS:[0ae39h],0eah
	JMP        L_05fc
	db 90h
L_05da:
	MOV        byte ptr DS:[0ae39h],0ebh
	JMP        L_05fc
	db 90h
L_05e2:
	MOV        byte ptr DS:[0ae39h],0e8h
	JMP        L_05fc
	db 90h
L_05ea:
	MOV        AX,1h
	PUSH       AX
	CALL       F_03ae
	JMP        L_05fc
	db 90h
L_05f4:
	MOV        word ptr [BP + -4h],1h
	CALL       F_051c
L_05fc:
	INC        SI
	CMP        SI,4h
	JGE        L_0598
	JMP        L_0563
	db 90h
L_0606:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_054a ENDP
F_060e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        word ptr [BP + -6h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_064a
	MOV        DI,AX
	MOV        SI,55b3h
	MOV        DX,word ptr [BP + -8h]
	MOV        CX,word ptr [BP + -6h]
L_0634:
	CMP        byte ptr [SI],44h
	JZ         L_063a
	INC        DX
L_063a:
	ADD        SI,20h
	INC        CX
	MOV        AX,CX
	CMP        AX,DI
	JNZ        L_0634
	MOV        word ptr [BP + -8h],DX
	MOV        word ptr [BP + -6h],CX
L_064a:
	MOV        byte ptr DS:[587ch],1ch
	CALL       SUB_0000_b680
	MOV        AX,6fbch
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        SI,SI
L_065b:
	CMP        byte ptr [SI + 58d8h],0h
	JNZ        L_06c6
L_0662:
	MOV        word ptr [BP + -0ah],SI
	CMP        SI,8h
	JL         L_066d
	JMP        L_08e7
L_066d:
	MOV        word ptr [BP + -0eh],0h
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9856
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6816
	MOV        byte ptr DS:[5895h],0ffh
	CALL       SUB_0000_a7f4
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_8c06
	MOV        word ptr [BP + -6h],5h
	MOV        SI,5h
L_06a3:
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_7e6a
	CALL       SUB_0000_a0ae
	DEC        SI
	JNZ        L_06a3
	MOV        AX,6fe0h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        SI,SI
L_06b9:
	CMP        byte ptr DS:[0a9ceh],0h
	JZ         L_06ce
	MOV        AX,12h
	JMP        L_06d1
	db 90h
L_06c6:
	INC        SI
	CMP        SI,8h
	JGE        L_0662
	JMP        L_065b
L_06ce:
	MOV        AX,3h
L_06d1:
	CMP        AX,SI
	JLE        L_06e2
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_7e6a
	CALL       SUB_0000_a0ae
	INC        SI
	JMP        L_06b9
L_06e2:
	MOV        word ptr [BP + -6h],SI
	SUB        SI,SI
L_06e7:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_97e4
	INC        SI
	CMP        SI,20h
	JL         L_06e7
	MOV        word ptr [BP + -6h],SI
	MOV        byte ptr DS:[5893h],0ffh
	MOV        byte ptr DS:[589eh],0ffh
	MOV        AX,7000h
	PUSH       AX
	MOV        AX,0ac64h
	PUSH       AX
	MOV        AX,0b0h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_82de
	MOV        AX,700eh
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,3e8h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_82de
	MOV        word ptr [BP + -6h],0bh
	SUB        DI,DI
	SUB        SI,SI
L_0733:
	MOV        word ptr [BP + -0ch],0h
	MOV        CX,5h
	PUSH       SI
	PUSH       DI
	LEA        SI,[SI + 0ad14h]
	LEA        DI,[DI + 0ac64h]
	XCHG       DI,SI
	PUSH       DS
	POP        ES
	REP MOVSW
	MOVSB
	POP        DI
	POP        SI
	MOV        word ptr [BP + -0ch],0bh
	ADD        DI,10h
	ADD        SI,20h
	CMP        SI,160h
	JL         L_0733
	MOV        word ptr [BP + -6h],0h
	CMP        word ptr [BP + -8h],0h
	JLE        L_07d1
	MOV        AX,word ptr [BP + -8h]
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -14h],AX
	MOV        word ptr [BP + -12h],5c5ah
	MOV        word ptr [BP + -10h],55b2h
	MOV        DI,word ptr [BP + -6h]
L_0781:
	MOV        SI,word ptr [BP + -12h]
	MOV        BX,word ptr [BP + -14h]
	MOV        AL,byte ptr [BX + DI + 1f0ah]
	SUB        AH,AH
	MOV        word ptr [BP + -16h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 1f42h]
	MOV        byte ptr [SI + 2h],AL
	MOV        AL,byte ptr [BX + 1f48h]
	MOV        byte ptr [SI + 3h],AL
	MOV        AX,701ah
	PUSH       AX
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_aae6
	MOV        word ptr [BP + -4h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 1adeh]
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [SI],AL
	ADD        word ptr [BP + -12h],8h
	ADD        word ptr [BP + -10h],20h
	INC        DI
	CMP        DI,word ptr [BP + -8h]
	JNZ        L_0781
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -2h],SI
L_07d1:
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_9856
	MOV        AX,7024h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,32h
	PUSH       AX
	CALL       SUB_0000_9856
	MOV        AX,704ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,8h
	PUSH       AX
	CALL       F_0000
	MOV        AX,70h
	PUSH       AX
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	MOV        AX,0ah
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_97e4
	MOV        AX,70h
	PUSH       AX
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	MOV        AX,0ah
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_97e4
	MOV        AX,3702h
	PUSH       AX
	CALL       F_00be
	MOV        AX,0af0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32c8h
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_7f02
	MOV        AX,16h
	PUSH       AX
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_97e4
	MOV        AX,178h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6dd8
	MOV        AX,78h
	PUSH       AX
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_97e4
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9856
	MOV        AX,705ah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,7074h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_83dc
	MOV        AX,70a4h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr DS:[55b1h],0ch
	JNZ        L_08aa
	MOV        AX,70c0h
	JMP        L_08b4
L_08aa:
	CMP        byte ptr DS:[55b1h],0bh
	JNZ        L_08b8
	MOV        AX,70c8h
L_08b4:
	PUSH       AX
	CALL       SUB_0000_75c0
L_08b8:
	MOV        AX,70ceh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,370eh
	PUSH       AX
	CALL       F_00be
	MOV        AX,0b54ah
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_83dc
	PUSH       word ptr [BP + -0ah]
	PUSH       word ptr [BP + -8h]
	CALL       F_054a
	CMP        byte ptr DS:[5c9ah],0h
	JZ         L_08e7
	MOV        AX,3716h
	PUSH       AX
	CALL       F_00be
L_08e7:
	MOV        byte ptr DS:[5895h],0ffh
	CALL       SUB_0000_a7f4
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_8c06
	MOV        byte ptr DS:[5896h],0ah
	MOV        byte ptr DS:[5897h],7h
	MOV        byte ptr DS:[57ach],0h
	MOV        byte ptr DS:[5893h],12h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_060e ENDP
F_0910 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_828e
L_091f:
	MOV        AX,70d8h
	PUSH       AX
	CALL       SUB_0000_73e4
	OR         AX,AX
	JZ         L_091f
	MOV        AL,DS:[58a6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_dc72
	MOV        byte ptr DS:[587ch],1eh
	CMP        byte ptr DS:[5893h],21h
	JNC        L_0942
	CALL       SUB_0000_b680
L_0942:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX
	MOV        byte ptr DS:[5893h],0ffh
	MOV        byte ptr DS:[589eh],0ffh
	MOV        AX,70e2h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6816
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6992
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6cb6
	MOV        word ptr [BP + -6h],0bh
	SUB        SI,SI
L_0996:
	SUB        DI,DI
	MOV        AX,0ffffh
	MOV        CX,5h
	PUSH       DI
	LEA        DI,[SI + 0ad14h]
	PUSH       DS
	POP        ES
	REP STOSW
	STOSB
	POP        DI
	MOV        DI,0bh
	ADD        SI,20h
	CMP        SI,160h
	JC         L_0996
	MOV        word ptr [BP + -8h],DI
	SUB        SI,SI
L_09ba:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_97e4
	INC        SI
	CMP        SI,20h
	JC         L_09ba
	MOV        word ptr [BP + -6h],SI
	CALL       SUB_0000_b680
	MOV        AX,7108h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,0eh
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        AX,7122h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1ch
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        AX,7152h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        byte ptr DS:[0adb9h],0h
	MOV        AL,1ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	MOV        AL,5h
	MOV        DS:[5c5dh],AL
	MOV        DS:[5c5ch],AL
	CALL       SUB_0000_b680
	MOV        word ptr [BP + -6h],6h
	MOV        DI,3720h
	MOV        word ptr [BP + -0ch],372ch
	MOV        word ptr [BP + -10h],3738h
	MOV        SI,3744h
L_0a22:
	PUSH       word ptr [DI]
	MOV        AX,1h
	PUSH       AX
	MOV        BX,word ptr [BP + -0ch]
	PUSH       word ptr [BX]
	MOV        BX,word ptr [BP + -10h]
	PUSH       word ptr [BX]
	PUSH       word ptr [SI]
	CALL       SUB_0000_7f02
	ADD        DI,2h
	ADD        word ptr [BP + -0ch],2h
	ADD        word ptr [BP + -10h],2h
	ADD        SI,2h
	CMP        SI,3750h
	JC         L_0a22
	MOV        AX,7172h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        AL,16h
	MOV        DS:[5c63h],AL
	MOV        DS:[5c62h],AL
	MOV        byte ptr DS:[5c64h],2h
	MOV        byte ptr DS:[5c65h],7h
	MOV        byte ptr DS:[0adf6h],0h
	MOV        AX,5eh
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6dd8
	MOV        byte ptr DS:[0adf6h],5eh
	MOV        byte ptr DS:[5c62h],0h
	CALL       SUB_0000_b680
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        byte ptr DS:[5c62h],16h
	MOV        byte ptr DS:[5c64h],8h
	MOV        byte ptr DS:[0adfch],0h
	MOV        AX,5fh
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6dd8
	MOV        byte ptr DS:[0adfch],5fh
	MOV        byte ptr DS:[5c62h],0h
	CALL       SUB_0000_b680
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        AX,719eh
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_8de2
	CALL       SUB_0000_8de2
	MOV        byte ptr DS:[0ad59h],0h
	MOV        AL,16h
	MOV        DS:[5c63h],AL
	MOV        DS:[5c62h],AL
	MOV        byte ptr DS:[5c64h],5h
	MOV        byte ptr DS:[5c65h],2h
	MOV        AX,174h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_6dd8
	MOV        AL,74h
	MOV        DS:[5c63h],AL
	MOV        DS:[5c62h],AL
	CALL       SUB_0000_b680
	MOV        AL,DS:[5888h]
	SUB        AH,AH
	MOV        CL,14h
	DIV        CL
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	MOV        AX,71beh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,71c2h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        BX,word ptr [BP + -2h]
	SHL        BX,1h
	PUSH       word ptr [BX + 1a74h]
	CALL       SUB_0000_82de
	MOV        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_742a
	CALL       SUB_0000_83dc
	MOV        AX,71cch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        word ptr [BP + -6h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0bb6
	MOV        DI,55b8h
	MOV        word ptr [BP + -10h],55bah
	MOV        SI,word ptr [BP + -6h]
L_0b68:
	LEA        AX,[SI + 7h]
	SUB        CX,CX
	PUSH       CX
	PUSH       AX
	MOV        AX,8e30h
	SUB        DX,DX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_6110
	MOV        word ptr [BP + -4h],AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,7530h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_7f02
	PUSH       SI
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dc66
	MOV        BX,word ptr [BP + -10h]
	MOV        AX,word ptr [BX]
	MOV        word ptr [DI],AX
	CALL       SUB_0000_8670
	ADD        DI,20h
	ADD        word ptr [BP + -10h],20h
	INC        SI
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        SI,AX
	JC         L_0b68
	MOV        word ptr [BP + -6h],SI
L_0bb6:
	MOV        AX,71eah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_7e6a
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6816
	MOV        AX,11ch
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6e50
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6992
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6cb6
	CMP        byte ptr DS:[5888h],4bh
	JNC        L_0c09
	MOV        byte ptr DS:[5888h],4bh
L_0c09:
	MOV        byte ptr DS:[5893h],11h
	MOV        byte ptr DS:[5895h],1h
	MOV        byte ptr DS:[587ch],1ch
	MOV        AL,0ah
	MOV        DS:[5897h],AL
	MOV        DS:[5896h],AL
	SUB        AL,AL
	MOV        DS:[588eh],AL
	MOV        DS:[587ah],AL
	JMP        L_0c31
L_0c2a:
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_acec
L_0c31:
	CMP        byte ptr DS:[587fh],6h
	JNZ        L_0c2a
	SUB        AL,AL
	MOV        DS:[58a6h],AL
	MOV        DS:[58a7h],AL
	CMP        word ptr DS:[57a8h],0h
	JNZ        L_0c4d
	MOV        word ptr DS:[57a8h],3fh
L_0c4d:
	CMP        word ptr [BP + -0ah],0h
	JZ         L_0c60
	CMP        word ptr [BP + -0ah],21h
	JGE        L_0c60
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_d7b6
L_0c60:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
F_0910 ENDP
_TEXT ENDS
END
