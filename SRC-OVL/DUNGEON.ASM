_TEXT SEGMENT BYTE 'CODE'
ORG 9680h
SUB_0000_9680:
ORG 9946h
SUB_0000_9946:
ORG a39eh
SUB_0000_a39e:
ORG fa6eh
SUB_0000_fa6e:
ORG d740h
SUB_0000_d740:
ORG fa62h
SUB_0000_fa62:
ORG fa7ah
SUB_0000_fa7a:
ORG fa92h
SUB_0000_fa92:
ORG fa9eh
SUB_0000_fa9e:
ORG 9ec2h
SUB_0000_9ec2:
ORG 8a14h
SUB_0000_8a14:
ORG 89deh
SUB_0000_89de:
ORG 99c4h
SUB_0000_99c4:
ORG 9a22h
SUB_0000_9a22:
ORG 986eh
SUB_0000_986e:
ORG 88a0h
SUB_0000_88a0:
ORG 88d6h
SUB_0000_88d6:
ORG 8940h
SUB_0000_8940:
ORG ca5ah
SUB_0000_ca5a:
ORG cafeh
SUB_0000_cafe:
ORG a730h
SUB_0000_a730:
ORG 94eah
SUB_0000_94ea:
ORG 9968h
SUB_0000_9968:
ORG 9e62h
SUB_0000_9e62:
ORG 88feh
SUB_0000_88fe:
ORG 89b6h
SUB_0000_89b6:
ORG 9f2ah
SUB_0000_9f2a:
ORG a06ch
SUB_0000_a06c:
ORG a8d8h
SUB_0000_a8d8:
ORG a49ch
SUB_0000_a49c:
ORG 86a8h
SUB_0000_86a8:
ORG 8124h
SUB_0000_8124:
ORG afa8h
SUB_0000_afa8:
ORG beb0h
SUB_0000_beb0:
ORG a858h
SUB_0000_a858:
ORG fa32h
SUB_0000_fa32:
ORG fa3eh
SUB_0000_fa3e:
ORG fa56h
SUB_0000_fa56:
ORG ddb6h
SUB_0000_ddb6:
ORG b82ch
SUB_0000_b82c:
ORG a918h
SUB_0000_a918:
ORG fa4ah
SUB_0000_fa4a:
ORG cdach
SUB_0000_cdac:
ORG f88eh
SUB_0000_f88e:
ORG bd66h
SUB_0000_bd66:
ORG 9a52h
SUB_0000_9a52:
ORG 9aceh
SUB_0000_9ace:
ORG 8b7ch
SUB_0000_8b7c:
ORG 8a2ch
SUB_0000_8a2c:
ORG 8acch
SUB_0000_8acc:
ORG c1deh
SUB_0000_c1de:
ORG 8b22h
SUB_0000_8b22:
ORG 8a94h
SUB_0000_8a94:
ORG 8a52h
SUB_0000_8a52:
ORG 8a6ch
SUB_0000_8a6c:
ORG fae6h
SUB_0000_fae6:
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
	SUB        SP,1ch
	PUSH       DI
	PUSH       SI
	MOV        AX,2c58h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        BL,byte ptr DS:[6602h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 2c76h]
	MOV        DS:[6603h],AL
	CALL       SUB_0000_9946
	MOV        AL,byte ptr [BP + 4h]
	SUB        AH,AH
	AND        AX,0fh
	MOV        word ptr [BP + -1ah],AX
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	MOV        AL,0ffh
	MOV        DS:[587bh],AL
	MOV        DS:[589eh],AL
	MOV        AL,DS:[5893h]
	SUB        AX,21h
	MOV        word ptr [BP + -1ch],AX
	CMP        AX,1h
	JL         L_004b
	DEC        word ptr [BP + -1ch]
L_004b:
	MOV        AX,1600h
	IMUL       word ptr [BP + -1ch]
	MOV        CX,AX
	MOV        AX,160h
	IMUL       word ptr [BP + -1ah]
	ADD        CX,AX
	MOV        word ptr [BP + -8h],CX
	MOV        CX,160h
	MOV        DI,0ad14h
	MOV        AX,DS
	MOV        ES,AX
	SUB        AX,AX
	REP STOSB
	MOV        AX,2c6ah
	PUSH       AX
	MOV        AX,0ad14h
	PUSH       AX
	MOV        AX,160h
	PUSH       AX
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_a39e
	MOV        AL,DS:[5893h]
	MOV        DS:[5894h],AL
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -6h],AX
	LEA        DI,[BP + -10h]
	MOV        SI,5c62h
	PUSH       SS
	POP        ES
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	LEA        DI,[BP + -18h]
	MOV        SI,5c6ah
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	MOV        byte ptr DS:[5893h],0ffh
	MOV        byte ptr DS:[58a0h],AH
	MOV        AL,byte ptr [BP + 4h]
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_fa6e
	CALL       SUB_0000_d740
	MOV        byte ptr DS:[58a1h],82h
	CALL       SUB_0000_fa62
	OR         AX,AX
	JNZ        L_00fa
	CMP        byte ptr DS:[58a0h],4dh
	JNZ        L_00d5
	CALL       SUB_0000_fa7a
L_00d5:
	MOV        AL,DS:[5894h]
	MOV        DS:[5893h],AL
	PUSH       word ptr [BP + -1ah]
	CALL       SUB_0000_fa92
	MOV        SI,word ptr [BP + -6h]
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -4h]
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	AND        byte ptr [BX + SI + 595ah],0afh
L_00fa:
	MOV        AL,byte ptr [BP + -6h]
	MOV        DS:[5897h],AL
	MOV        AL,byte ptr [BP + -4h]
	MOV        DS:[5896h],AL
	MOV        AL,DS:[5894h]
	MOV        DS:[5893h],AL
	CALL       SUB_0000_fa9e
	MOV        DI,5c62h
	LEA        SI,[BP + -10h]
	PUSH       DS
	POP        ES
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	MOV        DI,5c6ah
	LEA        SI,[BP + -18h]
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	MOV        AL,byte ptr [BP + -2h]
	MOV        DS:[587bh],AL
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0000 ENDP
F_0134 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        word ptr [BP + -2h],5c62h
	MOV        AL,DS:[5c67h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + 4h],0h
	JZ         L_01ab
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        word ptr [BP + -6h],AX
	MOV        AL,byte ptr [BP + -6h]
	MOV        DS:[5c63h],AL
	MOV        DS:[5c62h],AL
	MOV        byte ptr DS:[5c69h],0h
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [BX + 1744h]
	MOV        DS:[5c68h],AL
	MOV        AL,byte ptr [BX + 173ch]
	MOV        DS:[5c67h],AL
	MOV        AL,DS:[5895h]
	MOV        DS:[5c66h],AL
	CMP        word ptr [BP + -4h],0ffh
	JZ         L_018e
	PUSH       word ptr DS:[0a9c6h]
	CALL       SUB_0000_8a14
L_018e:
	MOV        word ptr DS:[0a9c6h],0h
	CALL       F_0252
	OR         AX,AX
	JNZ        L_01ab
	MOV        BX,word ptr [BP + -2h]
	MOV        SI,BX
	SUB        AL,AL
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr [BX + 5h],0ffh
L_01ab:
	MOV        BX,word ptr [BP + -2h]
	CMP        byte ptr [BX + 5h],0ffh
	JZ         L_01ca
	MOV        SI,BX
L_01b6:
	MOV        BL,byte ptr [SI]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 25fah]
	CALL       SUB_0000_89de
	MOV        DS:[0a9c6h],AX
	OR         AX,AX
	JZ         L_01b6
L_01ca:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0134 ENDP
F_01d2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,DS:[5386h]
	MOV        word ptr [BP + -2h],AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99c4
	MOV        AX,0ch
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a22
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	INC        AX
	MOV        word ptr [BP + -4h],AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_986e
	MOV        AX,0ch
	PUSH       AX
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_9a22
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_022c
	CMP        AX,1h
	JZ         L_0236
	CMP        AX,2h
	JZ         L_023c
	CMP        AX,3h
	JZ         L_0242
	MOV        AX,2c94h
	JMP        L_022f
	db 90h
L_022c:
	MOV        AX,2c7ch
L_022f:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0248
	db 90h
L_0236:
	MOV        AX,2c82h
	JMP        L_022f
	db 90h
L_023c:
	MOV        AX,2c88h
	JMP        L_022f
	db 90h
L_0242:
	MOV        AX,2c8eh
	JMP        L_022f
	db 90h
L_0248:
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_99c4
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_01d2 ENDP
F_0252 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	MOV        DI,word ptr [BP + -2h]
L_0262:
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        CL,6h
	SHL        AX,CL
	ADD        AX,595ah
	MOV        word ptr [BP + -0ch],AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        SI,AX
	ADD        word ptr [BP + -0ch],SI
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [BX]
	AND        AL,0f0h
	MOV        byte ptr [BP + -0ah],AL
	CMP        AL,60h
	JC         L_0292
	CMP        AL,70h
	JNZ        L_0304
L_0292:
	MOV        AX,SI
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        CX,3h
	SAR        AX,CL
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -4h],AX
	MOV        AX,SI
	CWD
	MOV        CX,8h
	IDIV       CX
	MOV        DI,DX
	MOV        AX,DI
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	CMP        AX,CX
	JZ         L_0304
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	CMP        word ptr [BP + -4h],AX
	JZ         L_0304
	MOV        AX,DI
	MOV        DS:[5c6ch],AL
	MOV        DS:[5c64h],AL
	MOV        AL,byte ptr [BP + -4h]
	MOV        DS:[5c6dh],AL
	MOV        DS:[5c65h],AL
	CMP        byte ptr DS:[5c67h],16h
	JZ         L_02e4
	CMP        byte ptr DS:[5c67h],18h
	JNZ        L_02f8
L_02e4:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,30h
	JLE        L_02f8
	MOV        byte ptr DS:[5c69h],0ffh
L_02f8:
	MOV        SI,1h
L_02fb:
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -8h],SI
	JMP        L_0310
	db 90h
L_0304:
	INC        word ptr [BP + -6h]
	CMP        word ptr [BP + -6h],8h
	JGE        L_02fb
	JMP        L_0262
L_0310:
	CMP        word ptr [BP + -6h],8h
	JNZ        L_0329
	MOV        AL,0ffh
	MOV        DS:[5c6dh],AL
	MOV        DS:[5c65h],AL
	MOV        DS:[5c6ch],AL
	MOV        DS:[5c64h],AL
	MOV        word ptr [BP + -8h],0h
L_0329:
	MOV        AX,word ptr [BP + -8h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0252 ENDP
F_0332 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,DS:[5386h]
	MOV        word ptr [BP + -2h],AX
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_88a0
	MOV        AX,28h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_88d6
	MOV        AX,30h
	PUSH       AX
	MOV        AX,0b9h
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	MOV        AX,0bfh
	PUSH       AX
	CALL       SUB_0000_88d6
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_88a0
	MOV        AX,28h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_8940
	MOV        AX,30h
	PUSH       AX
	MOV        AX,0b8h
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	MOV        AX,0b8h
	PUSH       AX
	CALL       SUB_0000_8940
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99c4
	MOV        AX,0ah
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a22
	CALL       SUB_0000_ca5a
	MOV        AX,2c9ah
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_cafe
	MOV        AX,6h
	PUSH       AX
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_9a22
	CALL       SUB_0000_ca5a
	MOV        AX,2c9dh
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_cafe
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_99c4
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0332 ENDP
F_03d6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[0a9fah],0h
	JZ         L_03ed
	CALL       SUB_0000_a730
	MOV        byte ptr DS:[0a9fah],0h
L_03ed:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CALL       SUB_0000_ca5a
	MOV        DI,1h
L_03fa:
	CALL       SUB_0000_9968
	PUSH       AX
	CALL       SUB_0000_9e62
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0417
	CMP        SI,5h
	JGE        L_0417
	CMP        word ptr DS:[538ah],0h
	JNZ        L_0417
	ADD        SI,0fah
L_0417:
	OR         SI,SI
	JNZ        L_045e
	PUSH       DI
	CALL       F_1a90
	OR         DI,DI
	JZ         L_0438
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	MOV        AX,0eh
	PUSH       AX
	MOV        AX,0afh
	JMP        L_044a
	db 90h
L_0438:
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	MOV        AX,0eh
	PUSH       AX
	MOV        AX,96h
L_044a:
	PUSH       AX
	MOV        AX,0b2h
	PUSH       AX
	CALL       SUB_0000_88fe
	CMP        byte ptr DS:[6604h],1h
	JZ         L_045b
	SUB        DI,DI
L_045b:
	CALL       F_1020
L_045e:
	OR         SI,SI
	JZ         L_03fa
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -4h],SI
	MOV        AX,SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_03d6 ENDP
F_0470 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	CALL       F_1be0
	MOV        AX,2ca8h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,2cafh
	PUSH       AX
	CALL       SUB_0000_9680
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_88a0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_89b6
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9f2a
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_89b6
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1f4h
	PUSH       AX
	MOV        AX,4e20h
	PUSH       AX
	CALL       SUB_0000_a06c
	CMP        word ptr [BP + 4h],0h
	JLE        L_04de
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	MOV        AL,byte ptr [SI + 24d6h]
	SUB        byte ptr DS:[5896h],AL
	MOV        AL,byte ptr [SI + 24deh]
	SUB        byte ptr DS:[5897h],AL
	JMP        L_04f7
	db 90h
L_04de:
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	MOV        AL,byte ptr [SI + 24d6h]
	ADD        byte ptr DS:[5896h],AL
	MOV        AL,byte ptr [SI + 24deh]
	ADD        byte ptr DS:[5897h],AL
L_04f7:
	CALL       SUB_0000_a8d8
	CALL       F_1be0
	POP        SI
	POP        BP
	RET        2h
	; Func
F_0470 ENDP
F_0502 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       SI
	MOV        word ptr [BP + -4h],0h
	MOV        word ptr [BP + -2h],0h
	MOV        AX,word ptr [BP + 6h]
	CMP        AX,1h
	JNZ        L_051e
	JMP        L_065a
L_051e:
	CMP        AX,2h
	JNZ        L_0526
	JMP        L_0628
L_0526:
	CMP        AX,3h
	JZ         L_0542
	CMP        AX,4h
	JNZ        L_0533
	JMP        L_064a
L_0533:
	MOV        AX,2d0bh
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[6603h]
	ADD        AL,2h
	JMP        L_0642
L_0542:
	MOV        AX,2cc0h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -4h],1h
L_054e:
	MOV        AL,DS:[6603h]
	MOV        DS:[6602h],AL
	CMP        word ptr [BP + -4h],0h
	JNZ        L_055d
	JMP        L_06b6
L_055d:
	MOV        word ptr [BP + -2h],1h
	MOV        BL,AL
	SUB        BH,BH
	SHL        BX,1h
	MOV        AX,word ptr [BX + 24d6h]
	IMUL       word ptr [BP + -4h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -6h],AX
	OR         AX,AX
	JGE        L_0583
	MOV        word ptr [BP + -6h],7h
L_0583:
	CMP        word ptr [BP + -6h],7h
	JLE        L_058e
	MOV        word ptr [BP + -6h],0h
L_058e:
	MOV        BL,byte ptr DS:[6603h]
	SUB        BH,BH
	SHL        BX,1h
	MOV        AX,word ptr [BX + 24deh]
	IMUL       word ptr [BP + -4h]
	MOV        CL,byte ptr DS:[5897h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -8h],AX
	OR         AX,AX
	JGE        L_05b1
	MOV        word ptr [BP + -8h],7h
L_05b1:
	CMP        word ptr [BP + -8h],7h
	JLE        L_05bc
	MOV        word ptr [BP + -8h],0h
L_05bc:
	MOV        SI,word ptr [BP + -8h]
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -6h]
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + -0ah],AL
	CMP        AL,83h
	JNZ        L_05fb
	MOV        AL,byte ptr [BP + -6h]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [BP + -8h]
	MOV        DS:[5897h],AL
	PUSH       word ptr [BP + -4h]
	CALL       F_0470
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -8h],AX
L_05fb:
	AND        byte ptr [BP + -0ah],0f0h
	CMP        byte ptr [BP + -0ah],0a0h
	JBE        L_060b
	CMP        byte ptr [BP + -0ah],0e0h
	JC         L_061d
L_060b:
	CMP        word ptr [BP + -4h],-1h
	JNZ        L_067c
	CMP        byte ptr [BP + -0ah],0a0h
	JZ         L_061d
	CMP        byte ptr [BP + -0ah],0f0h
	JNZ        L_067c
L_061d:
	MOV        AX,2d19h
L_0620:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_06b6
	db 90h
L_0628:
	MOV        AL,byte ptr [BP + 4h]
	AND        AL,0f0h
	CMP        AL,0e0h
	JNZ        L_0636
	MOV        AX,2cc9h
	JMP        L_0666
L_0636:
	MOV        AX,2cdah
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[6603h]
	INC        AL
L_0642:
	AND        AL,3h
	MOV        DS:[6603h],AL
	JMP        L_054e
L_064a:
	MOV        AX,2ce6h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -4h],0ffffh
	JMP        L_054e
	db 90h
L_065a:
	MOV        AL,byte ptr [BP + 4h]
	AND        AL,0f0h
	CMP        AL,0e0h
	JNZ        L_066e
	MOV        AX,2cefh
L_0666:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_054e
	db 90h
L_066e:
	MOV        AX,2d00h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[6603h]
	ADD        AL,3h
	JMP        L_0642
L_067c:
	MOV        AL,DS:[5c64h]
	SUB        AH,AH
	CMP        word ptr [BP + -6h],AX
	JNZ        L_0694
	MOV        AL,DS:[5c65h]
	CMP        word ptr [BP + -8h],AX
	JNZ        L_0694
	MOV        AX,2d23h
	JMP        L_0620
	db 90h
L_0694:
	MOV        byte ptr DS:[0a9fbh],0fh
	MOV        byte ptr DS:[24e7h],0h
	CALL       F_1020
	MOV        byte ptr DS:[24e7h],0h
	MOV        AL,byte ptr [BP + -6h]
	AND        AL,7h
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [BP + -8h]
	AND        AL,7h
	MOV        DS:[5897h],AL
L_06b6:
	CALL       F_1be0
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0502 ENDP
F_06c4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -2h],1h
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,0bh
	JZ         L_06f2
	JLE        L_06dd
	JMP        L_07a8
L_06dd:
	CMP        AX,1h
	JGE        L_06e5
	JMP        L_07bc
L_06e5:
	CMP        AX,4h
	JLE        L_0744
	CMP        AX,5h
	JZ         L_0710
	JMP        L_07bc
L_06f2:
	MOV        AL,DS:[5888h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_986e
L_0703:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
L_070a:
	MOV        AX,word ptr [BP + -2h]
	JMP        L_07da
L_0710:
	MOV        AX,2d2dh
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_a49c
	MOV        word ptr [BP + 4h],AX
	CMP        AX,59h
	JNZ        L_0730
	CALL       SUB_0000_86a8
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8124
	ADD        SP,2h
	JMP        L_070a
L_0730:
	MOV        AX,2d3bh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_070a
	db 90h
L_073a:
	MOV        AX,2d3eh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0703
	db 90h
L_0744:
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + -4h],AL
	PUSH       word ptr [BP + 4h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0502
L_0771:
	MOV        word ptr [BP + -2h],AX
	JMP        L_070a
L_0776:
	MOV        AX,2d43h
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        byte ptr DS:[0a9ceh],0h
	JZ         L_078a
	MOV        AX,2d4ah
	JMP        L_078d
	db 90h
L_078a:
	MOV        AX,2d4fh
L_078d:
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        byte ptr DS:[0a9ceh],1h
	SBB        AX,AX
	NEG        AX
	MOV        DS:[0a9ceh],AL
	JMP        L_070a
L_07a0:
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_afa8
	JMP        L_0771
L_07a8:
	CMP        AX,0dh
	JZ         L_0744
	CMP        AX,13h
	JZ         L_0776
	CMP        AX,16h
	JZ         L_073a
	CMP        AX,2eh
	JZ         L_0744
L_07bc:
	CMP        word ptr [BP + 4h],30h
	JC         L_07a0
	CMP        word ptr [BP + 4h],39h
	JA         L_07a0
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_beb0
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -2h],0h
	JMP        L_070a
	db 90h
L_07da:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_06c4 ENDP
F_07e2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ah],0h
	MOV        word ptr [BP + -0eh],0h
	MOV        word ptr [BP + -0ch],3e7h
	MOV        word ptr [BP + -2h],5c62h
	MOV        word ptr [BP + -16h],5c6ah
	CMP        byte ptr DS:[5c67h],0ffh
	JNZ        L_080d
	JMP        L_093e
L_080d:
	MOV        BX,word ptr [BP + -2h]
	CMP        byte ptr [BX + 5h],1bh
	JNZ        L_0819
	JMP        L_0917
L_0819:
	MOV        word ptr [BP + -0ah],0h
	MOV        BX,word ptr [BP + -16h]
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        word ptr [BP + -18h],AX
	MOV        AL,byte ptr [BX + 2h]
	MOV        word ptr [BP + -1ah],AX
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 3h]
	MOV        word ptr [BP + -1ch],AX
	MOV        AL,byte ptr [BX + 2h]
	MOV        word ptr [BP + -1eh],AX
L_083e:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        word ptr [BP + -8h],AX
	MOV        BX,AX
	SHL        BX,1h
	MOV        AX,word ptr [BX + 24d6h]
	ADD        AX,word ptr [BP + -1eh]
	MOV        DI,AX
	CMP        DI,7h
	JLE        L_085f
	SUB        DI,DI
L_085f:
	OR         DI,DI
	JGE        L_0866
	MOV        DI,7h
L_0866:
	MOV        BX,word ptr [BP + -8h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 24deh]
	ADD        AX,word ptr [BP + -1ch]
	MOV        SI,AX
	CMP        SI,7h
	JLE        L_087b
	SUB        SI,SI
L_087b:
	OR         SI,SI
	JGE        L_0882
	MOV        SI,7h
L_0882:
	MOV        BX,SI
	MOV        CL,3h
	SHL        BX,CL
	ADD        BX,DI
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        CL,6h
	SHL        AX,CL
	ADD        BX,AX
	MOV        AL,byte ptr [BX + 595ah]
	MOV        byte ptr [BP + -14h],AL
	AND        byte ptr [BP + -14h],0f0h
	CMP        byte ptr [BP + -14h],60h
	JZ         L_08e4
	CMP        byte ptr [BP + -14h],80h
	JZ         L_08e4
	CMP        byte ptr [BP + -14h],0a0h
	JNC        L_08e4
	MOV        AX,word ptr [BP + -1ah]
	MOV        word ptr [BP + -4h],AX
	MOV        AX,word ptr [BP + -18h]
	MOV        word ptr [BP + -6h],AX
	CMP        DI,word ptr [BP + -4h]
	JNZ        L_08d6
	CMP        SI,AX
	JNZ        L_08d6
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,1h
	JNZ        L_08e4
L_08d6:
	MOV        word ptr [BP + -0ch],384h
L_08db:
	MOV        word ptr [BP + -10h],DI
	MOV        word ptr [BP + -12h],SI
	JMP        L_08f0
	db 90h
L_08e4:
	INC        word ptr [BP + -0ah]
	CMP        word ptr [BP + -0ah],8h
	JGE        L_08db
	JMP        L_083e
L_08f0:
	CMP        word ptr [BP + -0ch],384h
	JNZ        L_0917
	MOV        BX,word ptr [BP + -16h]
	MOV        SI,word ptr [BP + -2h]
	MOV        AL,byte ptr [SI + 2h]
	MOV        byte ptr [BX + 2h],AL
	MOV        AL,byte ptr [SI + 3h]
	MOV        byte ptr [BX + 3h],AL
	MOV        BX,SI
	MOV        AL,byte ptr [BP + -10h]
	MOV        byte ptr [BX + 2h],AL
	MOV        AL,byte ptr [BP + -12h]
	MOV        byte ptr [BX + 3h],AL
L_0917:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,DS:[5896h]
	CMP        byte ptr [BX + 2h],AL
	JNZ        L_093e
	MOV        AL,DS:[5897h]
	CMP        byte ptr [BX + 3h],AL
	JNZ        L_093e
	MOV        word ptr [BP + -0eh],1h
	MOV        SI,word ptr [BP + -16h]
	MOV        AL,byte ptr [SI + 2h]
	MOV        byte ptr [BX + 2h],AL
	MOV        AL,byte ptr [SI + 3h]
	MOV        byte ptr [BX + 3h],AL
L_093e:
	MOV        AX,word ptr [BP + -0eh]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_07e2 ENDP
F_0948 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        AX,2d53h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -2h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_09bd
	MOV        word ptr [BP + -4h],55b5h
	MOV        SI,55b3h
	MOV        DI,word ptr [BP + -2h]
L_0970:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,byte ptr [BX]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_09a6
	CMP        byte ptr [SI],44h
	JZ         L_09a6
	MOV        byte ptr [SI],53h
	PUSH       DI
	CALL       SUB_0000_a858
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	MOV        AX,0dach
	PUSH       AX
	CALL       SUB_0000_a06c
	MOV        byte ptr DS:[0a9fah],1h
L_09a6:
	ADD        word ptr [BP + -4h],20h
	ADD        SI,20h
	INC        DI
	MOV        AX,DI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_0970
	MOV        word ptr [BP + -2h],DI
L_09bd:
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	AND        byte ptr [BX + SI + 595ah],8h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0948 ENDP
F_09e6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        AX,2d61h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -2h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0a46
	MOV        DI,55b5h
	MOV        SI,55b3h
L_0a09:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        CL,byte ptr [DI]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_0a33
	CMP        byte ptr [SI],44h
	JZ         L_0a33
	MOV        byte ptr [SI],50h
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	MOV        AX,0dach
	PUSH       AX
	CALL       SUB_0000_a06c
L_0a33:
	ADD        DI,20h
	ADD        SI,20h
	INC        word ptr [BP + -2h]
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -2h],AX
	JC         L_0a09
L_0a46:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_09e6 ENDP
F_0a4c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        byte ptr DS:[6602h],5h
	MOV        DI,word ptr [BP + -2h]
	MOV        SI,word ptr [BP + -4h]
L_0a5f:
	CMP        byte ptr [BP + 4h],61h
	JZ         L_0a6e
	CMP        byte ptr [BP + 4h],69h
	JZ         L_0a6e
	JMP        L_0af0
L_0a6e:
	CMP        byte ptr DS:[5895h],8h
	JNC        L_0af0
	MOV        AX,2d6ah
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,2d75h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,DS:[5897h]
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	ADD        BX,SI
	AND        byte ptr [BX + DI + 595ah],0f8h
	INC        byte ptr DS:[5895h]
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	SHL        BX,CL
	ADD        BX,SI
	MOV        AL,byte ptr [BX + DI + 595ah]
	MOV        byte ptr [BP + 4h],AL
	CMP        AL,90h
	JNC        L_0ae0
	OR         byte ptr [BP + 4h],8h
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,DS:[5897h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        BX,AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        BX,AX
	MOV        AL,byte ptr [BP + 4h]
	MOV        byte ptr [BX + 595ah],AL
L_0ae0:
	CALL       F_1be0
	MOV        AX,2d81h
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_a8d8
	JMP        L_0a5f
L_0af0:
	CMP        byte ptr DS:[5895h],8h
	JNZ        L_0afc
	MOV        byte ptr DS:[5893h],0h
L_0afc:
	CMP        byte ptr DS:[5893h],0h
	JZ         L_0b76
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + 4h],AL
	AND        byte ptr [BP + 4h],0f0h
	CMP        byte ptr [BP + 4h],0a0h
	JZ         L_0b37
	CMP        byte ptr [BP + 4h],0f0h
	JNZ        L_0b6f
L_0b37:
	CALL       SUB_0000_fa32
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0000
	CMP        byte ptr DS:[5893h],0h
	JZ         L_0b76
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_fa3e
L_0b6f:
	MOV        AX,1h
	PUSH       AX
	CALL       F_0134
L_0b76:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0a4c ENDP
F_0b7e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,2d92h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -2h],5c6ah
	MOV        AL,DS:[5c6ch]
	DEC        AL
	AND        AL,7h
	CMP        AL,byte ptr DS:[5896h]
	JNZ        L_0ba4
	MOV        byte ptr DS:[6602h],1h
	JMP        L_0bd5
L_0ba4:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 2h]
	INC        AL
	AND        AL,7h
	CMP        AL,byte ptr DS:[5896h]
	JNZ        L_0bbc
	MOV        byte ptr DS:[6602h],3h
	JMP        L_0bd5
	db 90h
L_0bbc:
	MOV        AL,byte ptr [BX + 3h]
	DEC        AL
	AND        AL,7h
	CMP        AL,byte ptr DS:[5897h]
	JNZ        L_0bd0
	MOV        byte ptr DS:[6602h],2h
	JMP        L_0bd5
L_0bd0:
	MOV        byte ptr DS:[6602h],0h
L_0bd5:
	MOV        AL,DS:[6603h]
	CMP        byte ptr DS:[6602h],AL
	JZ         L_0c22
	MOV        AX,2d9bh
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[6602h]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0c00
	CMP        AX,1h
	JZ         L_0c0a
	CMP        AX,2h
	JZ         L_0c10
	CMP        AX,3h
	JZ         L_0c16
	JMP        L_0c1c
	db 90h
L_0c00:
	MOV        AX,2da6h
L_0c03:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0c1c
	db 90h
L_0c0a:
	MOV        AX,2dach
	JMP        L_0c03
	db 90h
L_0c10:
	MOV        AX,2db1h
	JMP        L_0c03
	db 90h
L_0c16:
	MOV        AX,2db7h
	JMP        L_0c03
	db 90h
L_0c1c:
	MOV        AL,DS:[6602h]
	MOV        DS:[6603h],AL
L_0c22:
	MOV        AX,2dbch
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       F_1be0
	CALL       SUB_0000_9946
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9f2a
	CALL       SUB_0000_fa32
	MOV        byte ptr DS:[58a0h],0h
	MOV        byte ptr DS:[58a1h],2h
	CALL       SUB_0000_fa56
	MOV        AX,2h
	PUSH       AX
	MOV        AL,DS:[5c67h]
	SUB        AH,AH
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_ddb6
	CALL       SUB_0000_fa9e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_fa3e
	MOV        AX,1h
	PUSH       AX
	CALL       F_0134
	CMP        byte ptr DS:[5893h],0h
	JZ         L_0c71
	CALL       F_1be0
L_0c71:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0b7e ENDP
F_0c76 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        AL,byte ptr [BP + 6h]
	AND        AL,0f0h
	MOV        byte ptr [BP + -2h],AL
	MOV        byte ptr [BP + -6h],0h
	MOV        word ptr [BP + -4h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0cd0
	MOV        SI,55b3h
	MOV        DI,word ptr [BP + -4h]
L_0ca3:
	CMP        byte ptr [SI],53h
	JNZ        L_0cbd
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,4h
	JGE        L_0cbd
	MOV        byte ptr [SI],47h
	INC        byte ptr [BP + -6h]
L_0cbd:
	ADD        SI,20h
	INC        DI
	MOV        AX,DI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_0ca3
	MOV        word ptr [BP + -4h],DI
L_0cd0:
	CMP        byte ptr [BP + -6h],0h
	JZ         L_0cd9
	CALL       SUB_0000_a730
L_0cd9:
	CMP        word ptr [BP + 4h],0h
	JZ         L_0ce5
	CALL       F_07e2
	MOV        word ptr [BP + -8h],AX
L_0ce5:
	CMP        word ptr [BP + -8h],0h
	JZ         L_0d17
	CALL       F_0b7e
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + 6h],AL
	AND        AL,0f0h
	MOV        byte ptr [BP + -2h],AL
L_0d17:
	CMP        byte ptr [BP + -2h],0f0h
	JZ         L_0d23
	CMP        byte ptr [BP + -2h],0a0h
	JNZ        L_0d8e
L_0d23:
	CALL       SUB_0000_fa32
L_0d26:
	CMP        byte ptr [BP + -2h],0f0h
	JZ         L_0d32
	CMP        byte ptr [BP + -2h],0a0h
	JNZ        L_0d4a
L_0d32:
	CALL       SUB_0000_b82c
	CMP        AX,0ffffh
	JLE        L_0d4a
	MOV        AL,byte ptr [BP + 6h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0000
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_0d62
L_0d4a:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_fa3e
	CMP        byte ptr DS:[5893h],20h
	JA         L_0d5b
	JMP        L_0e22
L_0d5b:
	CALL       F_1be0
	JMP        L_0e22
	db 90h
L_0d62:
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + 6h],AL
	AND        AL,0f0h
	MOV        byte ptr [BP + -2h],AL
	JMP        L_0d26
	db 90h
L_0d8e:
	MOV        AL,byte ptr [BP + 6h]
	SUB        AH,AH
	CMP        AX,80h
	JZ         L_0db0
	JA         L_0e06
	CMP        AX,61h
	JZ         L_0dfa
	CMP        AX,62h
	JZ         L_0dc8
	CMP        AX,69h
	JZ         L_0dfa
	CMP        AX,6ah
	JZ         L_0dc8
	JMP        L_0e1f
L_0db0:
	CALL       F_0948
	JMP        L_0e1f
	db 90h
L_0db6:
	CALL       F_09e6
	JMP        L_0e1f
	db 90h
L_0dbc:
	MOV        AX,2dbfh
	PUSH       AX
	CALL       SUB_0000_9680
L_0dc3:
	CALL       SUB_0000_a8d8
	JMP        L_0e1f
L_0dc8:
	MOV        AX,2dc7h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,2dd3h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	AND        byte ptr [BX + SI + 595ah],8h
	JMP        L_0dc3
L_0dfa:
	MOV        AL,byte ptr [BP + 6h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0a4c
	JMP        L_0e1f
	db 90h
L_0e06:
	CMP        AX,81h
	JZ         L_0db6
	CMP        AX,82h
	JZ         L_0dbc
	CMP        AX,88h
	JZ         L_0db0
	CMP        AX,89h
	JZ         L_0db6
	CMP        AX,8ah
	JZ         L_0dbc
L_0e1f:
	CALL       SUB_0000_a730
L_0e22:
	CALL       SUB_0000_a918
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0c76 ENDP
F_0e2e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ch],1h
	MOV        word ptr [BP + -0eh],0h
	MOV        word ptr [BP + -4h],0h
	MOV        byte ptr DS:[0bb17h],2h
	CALL       SUB_0000_fa4a
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + -6h],AL
	AND        byte ptr [BP + -6h],0f0h
	CALL       F_0332
	CALL       F_01d2
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	SUB        AX,20h
	MOV        word ptr [BP + -8h],AX
	CMP        AX,1h
	JZ         L_0e95
	CMP        AX,4h
	JZ         L_0e95
	CMP        AX,5h
	JNZ        L_0ea6
L_0e95:
	MOV        byte ptr DS:[0bb14h],4fh
	MOV        byte ptr DS:[0bb15h],45h
	MOV        byte ptr DS:[6604h],3h
	JMP        L_0ec9
L_0ea6:
	MOV        byte ptr DS:[0bb14h],4dh
	MOV        byte ptr DS:[0bb15h],5h
	CMP        word ptr [BP + -8h],6h
	JZ         L_0ebc
	CMP        word ptr [BP + -8h],7h
	JNZ        L_0ec4
L_0ebc:
	MOV        byte ptr DS:[6604h],2h
	JMP        L_0ec9
	db 90h
L_0ec4:
	MOV        byte ptr DS:[6604h],1h
L_0ec9:
	CMP        byte ptr [BP + -6h],0a0h
	JZ         L_0ed5
	CMP        byte ptr [BP + -6h],0f0h
	JNZ        L_0eff
L_0ed5:
	CALL       SUB_0000_fa32
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0000
L_0eff:
	CMP        byte ptr DS:[5893h],20h
	JBE        L_0f15
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_fa3e
	PUSH       word ptr [BP + 4h]
	CALL       F_0134
	CALL       F_1be0
L_0f15:
	MOV        DI,word ptr [BP + -4h]
	MOV        SI,word ptr [BP + -0ah]
	JMP        L_0f93
	db 90h
L_0f1e:
	CMP        byte ptr DS:[587ah],51h
	JNZ        L_0f34
	XOR        DI,1h
	JZ         L_0f36
	MOV        AX,1h
L_0f2e:
	PUSH       AX
	CALL       SUB_0000_cdac
	JMP        L_0f36
L_0f34:
	SUB        DI,DI
L_0f36:
	CALL       F_03d6
	MOV        word ptr [BP + -8h],AX
	CMP        AX,0ffffh
	JLE        L_0f47
	PUSH       AX
	CALL       F_06c4
	MOV        SI,AX
L_0f47:
	CMP        byte ptr DS:[5893h],21h
	JNC        L_0f53
	SUB        SI,SI
	MOV        word ptr [BP + -0ch],SI
L_0f53:
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        BX,AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        BX,AX
	MOV        AL,byte ptr [BX + 595ah]
	MOV        byte ptr [BP + -2h],AL
	AND        AL,0f0h
	MOV        byte ptr [BP + -6h],AL
	OR         SI,SI
	JZ         L_0f87
	MOV        AL,byte ptr [BP + -2h]
	PUSH       AX
	PUSH       DI
	CALL       F_0c76
L_0f87:
	CMP        byte ptr DS:[5893h],21h
	JNC        L_0f93
	SUB        SI,SI
	MOV        word ptr [BP + -0ch],SI
L_0f93:
	CMP        word ptr [BP + -0ch],0h
	JZ         L_0ff2
	CMP        byte ptr DS:[5893h],20h
	JBE        L_0ff2
	MOV        word ptr [BP + -0ch],1h
	MOV        SI,1h
	CALL       SUB_0000_b82c
	MOV        word ptr [BP + -0eh],AX
	CMP        AX,SI
	JNZ        L_0fc3
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CALL       SUB_0000_ca5a
	MOV        AX,2dddh
	PUSH       AX
	CALL       SUB_0000_9680
L_0fc3:
	CMP        word ptr [BP + -0eh],0h
	JGE        L_0fd0
	MOV        word ptr [BP + -0ch],0h
	SUB        SI,SI
L_0fd0:
	CMP        word ptr [BP + -0eh],0h
	JNZ        L_0f93
	CMP        byte ptr DS:[587ah],54h
	JNZ        L_0fe0
	JMP        L_0f1e
L_0fe0:
	CMP        byte ptr DS:[587ah],51h
	JNZ        L_0fea
	JMP        L_0f1e
L_0fea:
	MOV        DI,1h
	MOV        AX,DI
	JMP        L_0f2e
L_0ff2:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -0ah],SI
	TEST       byte ptr DS:[0bb17h],2h
	JZ         L_1006
	AND        byte ptr DS:[0bb17h],0fbh
	JMP        L_100b
L_1006:
	OR         byte ptr DS:[0bb17h],4h
L_100b:
	CALL       SUB_0000_fa32
	CMP        word ptr [BP + -0eh],0h
	JGE        L_1017
	CALL       SUB_0000_f88e
L_1017:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0e2e ENDP
F_1020 PROC NEAR
	XOR        byte ptr DS:[24e7h],1h
	JZ         L_104a
	CMP        byte ptr DS:[0a9fbh],0h
	JZ         L_104a
	MOV        AX,1h
	PUSH       AX
	MOV        AL,DS:[0a9fbh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,4e20h
	PUSH       AX
	CALL       SUB_0000_a06c
	MOV        AX,0a9fbh
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_bd66
L_104a:
	RET
	db 90h
	; Func
F_1020 ENDP
F_104c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        BL,byte ptr DS:[5893h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 2dcfh]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 4h]
	JC         L_10d6
	MOV        AL,byte ptr [BX + 2dc7h]
	ADD        AX,word ptr [BP + 4h]
	DEC        AX
	MOV        word ptr [BP + -2h],AX
	SUB        AX,AX
	PUSH       AX
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 2df8h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 2e04h]
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a52
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99c4
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ace
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a22
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94ea
	MOV        BX,word ptr [BP + -2h]
	SHL        BX,1h
	PUSH       word ptr [BX + 2e10h]
	CALL       SUB_0000_9680
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94ea
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9ace
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99c4
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a52
L_10d6:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_104c ENDP
F_10dc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + 6h]
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	CMP        AX,90h
	JGE        L_1113
	AND        word ptr [BP + -2h],0f7h
L_1113:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_10dc ENDP
F_111e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[587ah],54h
	JNZ        L_113a
	MOV        BL,byte ptr DS:[5c62h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 1744h]
	MOV        DS:[5c68h],AL
L_113a:
	CMP        byte ptr DS:[5c69h],0ffh
	JNZ        L_1146
	MOV        AX,1h
	JMP        L_1148
L_1146:
	SUB        AX,AX
L_1148:
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,DS:[5c68h]
	SUB        AH,AH
	MOV        SI,AX
	AND        AX,90h
	MOV        word ptr [BP + -8h],AX
	MOV        AX,SI
	AND        AX,60h
	MOV        word ptr [BP + -2h],AX
	MOV        AX,SI
	AND        AX,0fh
	MOV        word ptr [BP + -6h],AX
	CMP        byte ptr DS:[587ah],54h
	JNZ        L_117a
	MOV        AX,1h
	MOV        word ptr [BP + -0ch],AX
	MOV        word ptr [BP + -4h],AX
	JMP        L_11d3
L_117a:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,32h
	JGE        L_118e
	MOV        AX,1h
	JMP        L_1190
L_118e:
	SUB        AX,AX
L_1190:
	MOV        word ptr [BP + -4h],AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,32h
	JGE        L_11a8
	MOV        AX,1h
	JMP        L_11aa
	db 90h
L_11a8:
	SUB        AX,AX
L_11aa:
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,word ptr [BP + -2h]
	CMP        AX,20h
	JZ         L_11c2
	CMP        AX,40h
	JZ         L_11d3
	CMP        AX,60h
	JZ         L_11e6
	JMP        L_11d3
	db 90h
L_11c2:
	CMP        word ptr [BP + -6h],1h
	SBB        AX,AX
	NEG        AX
	MOV        word ptr [BP + -6h],AX
	MOV        word ptr [BP + -4h],AX
L_11d0:
	MOV        word ptr [BP + -0ch],AX
L_11d3:
	CMP        word ptr [BP + -8h],0h
	JZ         L_1210
	CMP        word ptr [BP + -8h],90h
	JNZ        L_1208
	MOV        AX,1h
	JMP        L_120a
	db 90h
L_11e6:
	DEC        word ptr [BP + -6h]
	JNS        L_11f0
	MOV        word ptr [BP + -6h],3h
L_11f0:
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [BX + 2e26h]
	SUB        AH,AH
	MOV        SI,AX
	SHR        AX,1h
	MOV        word ptr [BP + -4h],AX
	MOV        AX,SI
	AND        AX,1h
	JMP        L_11d0
	db 90h
L_1208:
	SUB        AX,AX
L_120a:
	XOR        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -0ch],AX
L_1210:
	CMP        word ptr DS:[0a9c6h],0h
	JNZ        L_1220
	MOV        AX,6c4eh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_1276
L_1220:
	MOV        SI,word ptr [BP + 4h]
	SHL        SI,1h
	MOV        BX,word ptr [BP + -0ah]
	MOV        CL,3h
	SHL        BX,CL
	MOV        DI,word ptr [BX + SI + 2e32h]
	PUSH       word ptr DS:[0a9c6h]
	MOV        AX,word ptr [BP + -4h]
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	ADD        AX,word ptr [BP + 4h]
	DEC        AX
	PUSH       AX
	PUSH       word ptr [SI + 2e2ah]
	PUSH       DI
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_8b7c
	PUSH       word ptr DS:[0a9c6h]
	MOV        AX,word ptr [BP + -0ch]
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	ADD        AX,word ptr [BP + 4h]
	DEC        AX
	PUSH       AX
	MOV        AX,60h
	PUSH       AX
	PUSH       DI
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_8a2c
	MOV        AL,byte ptr [BP + -2h]
	ADD        AL,byte ptr [BP + -8h]
	ADD        AL,byte ptr [BP + -6h]
	MOV        DS:[5c68h],AL
L_1276:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_111e ENDP
F_127e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        AX,DS:[52c4h]
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr DS:[52c4h],0h
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_12b4
	CMP        AX,1h
	JNZ        L_12a1
	JMP        L_1326
L_12a1:
	CMP        AX,2h
	JNZ        L_12a9
	JMP        L_132c
L_12a9:
	CMP        AX,3h
	JNZ        L_12b1
	JMP        L_1332
L_12b1:
	JMP        L_12be
	db 90h
L_12b4:
	MOV        AX,DS:[13b6h]
L_12b7:
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_88a0
L_12be:
	MOV        word ptr [BP + -6h],0h
	MOV        BX,word ptr [BP + 6h]
	SHL        BX,1h
	CMP        word ptr [BX + 2e52h],0h
	JLE        L_133b
	MOV        AX,word ptr [BP + 6h]
	SHL        AX,1h
	MOV        word ptr [BP + -14h],AX
	MOV        BX,AX
	MOV        DI,word ptr [BX + 2e52h]
	MOV        AX,word ptr [BX + 2e5ah]
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,word ptr [BX + 2e4ah]
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,word ptr [BX + 2e42h]
	MOV        word ptr [BP + -10h],AX
	MOV        AX,word ptr [BP + -0eh]
	SUB        AX,word ptr [BP + -0ch]
	MOV        word ptr [BP + -12h],AX
	ADD        word ptr [BP + -6h],DI
L_12fe:
	PUSH       word ptr [BP + -10h]
	PUSH       word ptr [BP + -12h]
	CALL       SUB_0000_9ec2
	MOV        SI,AX
	PUSH       word ptr [BP + -10h]
	PUSH       word ptr [BP + -0eh]
	CALL       SUB_0000_9ec2
	MOV        word ptr [BP + -8h],AX
	PUSH       SI
	PUSH       AX
	MOV        AX,word ptr [BP + -0ch]
	ADD        AX,SI
	PUSH       AX
	CALL       SUB_0000_8acc
	DEC        DI
	JZ         L_1338
	JMP        L_12fe
	db 90h
L_1326:
	MOV        AX,DS:[13b4h]
	JMP        L_12b7
	db 90h
L_132c:
	MOV        AX,DS:[13aeh]
	JMP        L_12b7
	db 90h
L_1332:
	MOV        AX,DS:[13b2h]
	JMP        L_12b7
L_1338:
	MOV        word ptr [BP + -4h],SI
L_133b:
	MOV        AX,word ptr [BP + -2h]
	MOV        DS:[52c4h],AX
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_127e ENDP
F_134a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	CMP        word ptr [BP + 8h],1fh
	JGE        L_13c6
	MOV        AX,word ptr [BP + 8h]
	AND        AX,3h
	MOV        word ptr [BP + -4h],AX
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        BX,AX
	SHL        BX,1h
	MOV        AX,word ptr [BX + SI + 2e62h]
	MOV        word ptr [BP + -6h],AX
	CMP        word ptr [BP + 4h],0h
	JZ         L_138f
	MOV        AL,byte ptr [BP + 8h]
	AND        AL,0f8h
	CMP        AL,8h
	JZ         L_138a
	MOV        AL,byte ptr [BP + 8h]
	AND        AL,0fch
	CMP        AL,18h
	JNZ        L_138f
L_138a:
	MOV        word ptr [BP + -6h],60h
L_138f:
	MOV        word ptr [BP + -8h],0eh
	CMP        word ptr [BP + 4h],0h
	JZ         L_13b2
	PUSH       word ptr DS:[0a9c0h]
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + -6h]
	MOV        AX,0eh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
L_13ab:
	CALL       SUB_0000_8a2c
	JMP        L_1455
	db 90h
L_13b2:
	PUSH       word ptr DS:[0a9c0h]
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	SUB        AX,AX
	PUSH       AX
	JMP        L_1452
	db 90h
L_13c6:
	MOV        SI,word ptr [BP + 8h]
	INC        SI
	MOV        AX,SI
	SAR        AX,1h
	SUB        AX,10h
	MOV        word ptr [BP + -2h],AX
	MOV        AX,SI
	SUB        AH,AH
	AND        AX,6h
	SHR        AX,1h
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + 4h],0h
	JZ         L_13ee
	MOV        word ptr [BP + -6h],60h
	JMP        L_13fa
	db 90h
L_13ee:
	MOV        BX,word ptr [BP + -4h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 2e72h]
	MOV        word ptr [BP + -6h],AX
L_13fa:
	CMP        word ptr [BP + -2h],8h
	JGE        L_1418
	CMP        word ptr [BP + 6h],0h
	JZ         L_1412
	MOV        BX,word ptr [BP + -4h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 2e82h]
	JMP        L_1428
	db 90h
L_1412:
	MOV        AX,60h
	JMP        L_1428
	db 90h
L_1418:
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        BX,word ptr [BP + -4h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + SI + 2e7ah]
L_1428:
	MOV        word ptr [BP + -8h],AX
	CMP        word ptr [BP + 4h],0h
	JZ         L_1442
	PUSH       word ptr DS:[0a9c4h]
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -6h]
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	JMP        L_13ab
L_1442:
	PUSH       word ptr DS:[0a9c4h]
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + 6h]
L_1452:
	CALL       SUB_0000_8b7c
L_1455:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_134a ENDP
F_145c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 6h],5h
	JNZ        L_148a
	MOV        word ptr [BP + 6h],0h
	MOV        AX,0c80h
	PUSH       AX
	MOV        AX,0dach
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	SUB        AX,14h
	NEG        AX
	PUSH       AX
	CALL       SUB_0000_c1de
	JMP        L_1502
	db 90h
	db 90h
L_148a:
	CMP        word ptr [BP + 6h],4h
	JNZ        L_14aa
	CMP        word ptr DS:[52c8h],0h
	JZ         L_149e
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_14a4
L_149e:
	MOV        AX,3h
L_14a1:
	PUSH       AX
	JMP        L_14ae
L_14a4:
	MOV        AX,0bh
	JMP        L_14a1
	db 90h
L_14aa:
	PUSH       word ptr DS:[13b2h]
L_14ae:
	CALL       SUB_0000_88a0
	MOV        AX,word ptr [BP + 0ah]
	DEC        AX
	PUSH       AX
	PUSH       word ptr [BP + 8h]
	MOV        AX,word ptr [BP + 0ah]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_8acc
	PUSH       word ptr [BP + 0ah]
	MOV        AX,word ptr [BP + 8h]
	DEC        AX
	PUSH       AX
	MOV        AX,word ptr [BP + 8h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_8b22
	CMP        word ptr [BP + 6h],4h
	JGE        L_14ea
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_88a0
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	CALL       SUB_0000_8a94
L_14ea:
	CMP        word ptr [BP + 6h],0h
	JNZ        L_14ff
	SUB        AX,AX
	PUSH       AX
	MOV        AX,40h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,4h
	JGE        L_1502
L_14ff:
	INC        word ptr [BP + 6h]
L_1502:
	MOV        AX,word ptr [BP + 6h]
	POP        BP
	RET        8h
	db 90h
	; Func
F_145c ENDP
F_150a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	CALL       F_10dc
	MOV        word ptr [BP + -4h],AX
	CMP        AX,0a0h
	JGE        L_152a
L_1523:
	MOV        AX,1h
	JMP        L_167a
	db 90h
L_152a:
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,4h
	SAR        BX,CL
	MOV        AL,byte ptr [BX + 2e80h]
	SUB        AH,AH
	ADD        AX,word ptr [BP + 4h]
	MOV        word ptr [BP + -2h],AX
	CMP        word ptr [BP + 4h],0h
	JNZ        L_1548
	MOV        word ptr [BP + -2h],0ch
L_1548:
	PUSH       word ptr [BP + -2h]
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       F_134a
	PUSH       word ptr [BP + -2h]
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       F_134a
	CMP        word ptr [BP + 4h],1h
	JZ         L_156b
	CMP        word ptr [BP + 4h],2h
	JNZ        L_15d6
L_156b:
	CMP        byte ptr DS:[6604h],1h
	JNZ        L_15d6
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,0f0h
	CMP        AL,0c0h
	JNZ        L_15d6
	MOV        AX,word ptr [BP + -4h]
	AND        AX,7h
	MOV        word ptr [BP + -6h],AX
	MOV        AX,5fh
	PUSH       AX
	MOV        DI,word ptr [BP + 4h]
	MOV        AX,DI
	SHL        DI,1h
	SHL        DI,1h
	ADD        DI,AX
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [BX + DI + 2e8bh]
	SUB        AH,AH
	ADD        AX,0eh
	PUSH       AX
	PUSH       BX
	PUSH       word ptr [BP + 4h]
	CALL       F_145c
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,6h
	SHL        SI,CL
	MOV        AX,word ptr [BP + 6h]
	AND        AX,7h
	MOV        CL,3h
	SHL        AX,CL
	MOV        CX,word ptr [BP + 8h]
	AND        CX,7h
	ADD        AX,CX
	ADD        SI,AX
	ADD        SI,595ah
	AND        byte ptr [SI],0f8h
	MOV        AL,byte ptr [BP + -6h]
	ADD        byte ptr [SI],AL
L_15d6:
	CMP        word ptr [BP + 4h],1h
	JZ         L_15df
	JMP        L_165f
L_15df:
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,0f0h
	CMP        AL,0b0h
	JNZ        L_15fa
	TEST       byte ptr [BP + -4h],0fh
	JZ         L_15fa
	MOV        AX,word ptr [BP + -4h]
	AND        AX,0fh
	PUSH       AX
	CALL       F_104c
	JMP        L_165f
L_15fa:
	CMP        byte ptr DS:[6604h],3h
	JNZ        L_165f
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,0f0h
	CMP        AL,0c0h
	JNZ        L_165f
	SUB        AX,AX
	PUSH       AX
	MOV        AX,40h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,4h
	JGE        L_165f
	MOV        AX,DS:[13aeh]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_88a0
	MOV        AX,5ch
	PUSH       AX
	MOV        AX,57h
	PUSH       AX
	MOV        AX,5dh
	PUSH       AX
	CALL       SUB_0000_8acc
	MOV        AX,5bh
	PUSH       AX
	MOV        AX,58h
	PUSH       AX
	MOV        AX,5dh
	PUSH       AX
	CALL       SUB_0000_8acc
	MOV        AX,61h
	PUSH       AX
	MOV        AX,57h
	PUSH       AX
	MOV        AX,62h
	PUSH       AX
	CALL       SUB_0000_8acc
	MOV        AX,61h
	PUSH       AX
	MOV        AX,58h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_8acc
L_165f:
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,0f0h
	CMP        AL,0e0h
	JNZ        L_1678
	CMP        word ptr [BP + 4h],0h
	JNZ        L_1678
	MOV        word ptr DS:[52c4h],1h
	JMP        L_1523
	db 90h
L_1678:
	SUB        AX,AX
L_167a:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_150a ENDP
F_1682 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	CALL       F_10dc
	MOV        word ptr [BP + -6h],AX
	CMP        AX,0a0h
	JGE        L_169e
	JMP        L_176e
L_169e:
	AND        AX,0f0h
	CMP        AX,0a0h
	JNZ        L_16a9
	JMP        L_1766
L_16a9:
	CMP        AX,0c0h
	JZ         L_16c4
	CMP        AX,0e0h
	JNZ        L_16b6
	JMP        L_1766
L_16b6:
	CMP        AX,0f0h
	JNZ        L_16be
	JMP        L_1766
L_16be:
	PUSH       word ptr [BP + 4h]
	JMP        L_1775
L_16c4:
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,14h
	MOV        word ptr [BP + -2h],AX
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	CALL       F_134a
	CMP        word ptr [BP + 4h],2h
	JL         L_16e0
	JMP        L_177e
L_16e0:
	CMP        byte ptr DS:[6604h],1h
	JZ         L_16ea
	JMP        L_177e
L_16ea:
	MOV        AX,word ptr [BP + -6h]
	AND        AX,7h
	MOV        word ptr [BP + -8h],AX
	CMP        word ptr [BP + 4h],0h
	JZ         L_16fe
	MOV        AX,43h
	JMP        L_1701
L_16fe:
	MOV        AX,21h
L_1701:
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + 6h],0h
	JZ         L_1713
	MOV        AX,0beh
	SUB        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -4h],AX
L_1713:
	PUSH       word ptr [BP + -4h]
	MOV        DI,word ptr [BP + 4h]
	MOV        AX,DI
	SHL        DI,1h
	SHL        DI,1h
	ADD        DI,AX
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX + DI + 2e9ah]
	SUB        AH,AH
	ADD        AX,0eh
	PUSH       AX
	PUSH       BX
	PUSH       word ptr [BP + 4h]
	CALL       F_145c
	MOV        word ptr [BP + -8h],AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,6h
	SHL        SI,CL
	MOV        AX,word ptr [BP + 8h]
	AND        AX,7h
	MOV        CL,3h
	SHL        AX,CL
	MOV        CX,word ptr [BP + 0ah]
	AND        CX,7h
	ADD        AX,CX
	ADD        SI,AX
	ADD        SI,595ah
	AND        byte ptr [SI],0f8h
	MOV        AL,byte ptr [BP + -8h]
	ADD        byte ptr [SI],AL
	JMP        L_177e
L_1766:
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,4h
	JMP        L_1774
L_176e:
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,10h
L_1774:
	PUSH       AX
L_1775:
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	CALL       F_134a
L_177e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_1682 ENDP
F_1786 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	CMP        word ptr DS:[52c8h],0h
	JZ         L_179c
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_17a2
L_179c:
	SUB        AX,AX
	PUSH       AX
	JMP        L_17a6
	db 90h
L_17a2:
	PUSH       word ptr DS:[13b2h]
L_17a6:
	CALL       SUB_0000_88a0
	MOV        AX,word ptr [BP + 6h]
	OR         AX,AX
	JZ         L_17cc
	CMP        AX,1h
	JNZ        L_17b8
	JMP        L_185e
L_17b8:
	CMP        AX,2h
	JNZ        L_17c0
	JMP        L_18c4
L_17c0:
	CMP        AX,3h
	JNZ        L_17c8
	JMP        L_1920
L_17c8:
	JMP        L_194a
	db 90h
L_17cc:
	CMP        word ptr DS:[52c8h],0h
	JZ         L_17e4
	CMP        word ptr DS:[52c8h],3h
	JZ         L_17e4
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_88a0
L_17e4:
	MOV        word ptr [BP + -2h],8h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -4h],AX
	ADD        AX,2ea4h
	MOV        word ptr [BP + -6h],AX
	MOV        SI,word ptr [BP + -4h]
	ADD        SI,2ea5h
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,2eb5h
	MOV        word ptr [BP + -0ah],AX
L_1809:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [BX]
	MOV        DI,AX
	PUSH       DI
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8a94
	MOV        AX,0beh
	SUB        AX,DI
	PUSH       AX
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8a94
	ADD        word ptr [BP + -6h],2h
	ADD        SI,2h
	CMP        SI,word ptr [BP + -0ah]
	JC         L_1809
	MOV        SI,word ptr [BP + 4h]
	SHL        SI,1h
	MOV        AL,byte ptr [SI + 2f11h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,byte ptr [SI + 2f10h]
	MOV        word ptr [BP + -0eh],AX
	PUSH       AX
	PUSH       DI
	CALL       SUB_0000_8a94
	MOV        AX,0beh
	SUB        AX,word ptr [BP + -0eh]
L_1855:
	PUSH       AX
	PUSH       DI
	CALL       SUB_0000_8a94
	JMP        L_194a
	db 90h
L_185e:
	MOV        word ptr [BP + -2h],5h
	MOV        AX,word ptr [BP + 4h]
	MOV        CX,AX
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,CX
	SHL        AX,1h
	MOV        word ptr [BP + -0ch],AX
	ADD        AX,2ed4h
	MOV        word ptr [BP + -0ah],AX
	MOV        SI,word ptr [BP + -0ch]
	ADD        SI,2ed5h
	MOV        AX,word ptr [BP + -0ch]
	ADD        AX,2edfh
	MOV        word ptr [BP + -6h],AX
L_1889:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	ADD        AX,60h
	MOV        word ptr [BP + -4h],AX
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        DI,AX
	LEA        AX,[DI + 48h]
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_8a94
	MOV        AX,76h
	SUB        AX,DI
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_8a94
	ADD        word ptr [BP + -0ah],2h
	ADD        SI,2h
	CMP        SI,word ptr [BP + -6h]
	JC         L_18c1
	JMP        L_194a
L_18c1:
	JMP        L_1889
	db 90h
L_18c4:
	MOV        word ptr [BP + -2h],4h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -10h],AX
	ADD        AX,2ef2h
	MOV        word ptr [BP + -0eh],AX
	MOV        SI,word ptr [BP + -10h]
	ADD        SI,2ef3h
	MOV        AX,word ptr [BP + -10h]
	ADD        AX,2efbh
	MOV        word ptr [BP + -0ah],AX
L_18e9:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	ADD        AX,60h
	MOV        word ptr [BP + -8h],AX
	MOV        BX,word ptr [BP + -0eh]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        DI,AX
	LEA        AX,[DI + 50h]
	PUSH       AX
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_8a94
	MOV        AX,6eh
	SUB        AX,DI
	PUSH       AX
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_8a94
	ADD        word ptr [BP + -0eh],2h
	ADD        SI,2h
	CMP        SI,word ptr [BP + -0ah]
	JNC        L_194a
	JMP        L_18e9
L_1920:
	MOV        SI,word ptr [BP + 4h]
	SHL        SI,1h
	MOV        AL,byte ptr [SI + 2f0bh]
	SUB        AH,AH
	ADD        AX,60h
	MOV        DI,AX
	MOV        AL,byte ptr [SI + 2f0ah]
	SUB        AH,AH
	MOV        word ptr [BP + -10h],AX
	ADD        AX,58h
	PUSH       AX
	PUSH       DI
	CALL       SUB_0000_8a94
	MOV        AX,66h
	SUB        AX,word ptr [BP + -10h]
	JMP        L_1855
L_194a:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_1786 ENDP
F_1952 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	CALL       F_10dc
	MOV        word ptr [BP + -4h],AX
	MOV        CL,4h
	SAR        AX,CL
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JLE        L_19f0
	CMP        AX,8h
	JGE        L_19f0
	CMP        AX,6h
	JNZ        L_1981
	TEST       byte ptr [BP + -4h],7h
	JNZ        L_19f0
L_1981:
	MOV        BX,word ptr [BP + -2h]
	CMP        byte ptr [BX + 2f16h],0h
	JZ         L_19ae
	MOV        AL,byte ptr [BX + 2f16h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	ADD        SI,AX
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_134a
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       F_134a
L_19ae:
	MOV        BX,word ptr [BP + -2h]
	CMP        byte ptr [BX + 2f1eh],0h
	JZ         L_19da
	MOV        AL,byte ptr [BX + 2f1eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	ADD        SI,AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       F_134a
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       F_134a
L_19da:
	CMP        word ptr [BP + -2h],5h
	JNZ        L_1a03
	PUSH       word ptr [BP + 4h]
	MOV        AL,DS:[2f26h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_1786
	JMP        L_1a03
	db 90h
	db 90h
L_19f0:
	CMP        word ptr [BP + -2h],8h
	JNZ        L_1a03
	PUSH       word ptr [BP + 4h]
	MOV        AX,word ptr [BP + -4h]
	AND        AX,7h
	PUSH       AX
	CALL       F_127e
L_1a03:
	CMP        word ptr [BP + -2h],9h
	JGE        L_1a4f
	MOV        DI,word ptr [BP + 6h]
	AND        DI,7h
	MOV        CL,3h
	SHL        DI,CL
	MOV        AX,word ptr [BP + 8h]
	AND        AX,7h
	ADD        DI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	TEST       byte ptr [BX + DI + 595ah],8h
	JZ         L_1a4f
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	MOV        SI,AX
	MOV        AL,DS:[2f24h]
	SUB        AH,AH
	ADD        SI,AX
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_134a
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       F_134a
L_1a4f:
	CMP        word ptr [BP + 4h],0h
	JZ         L_1a71
	MOV        AL,byte ptr [BP + 8h]
	AND        AL,7h
	CMP        AL,byte ptr DS:[5c64h]
	JNZ        L_1a71
	MOV        AL,byte ptr [BP + 6h]
	AND        AL,7h
	CMP        AL,byte ptr DS:[5c65h]
	JNZ        L_1a71
	PUSH       word ptr [BP + 4h]
	CALL       F_111e
L_1a71:
	CMP        word ptr [BP + 4h],0h
	JNZ        L_1a87
	INC        byte ptr DS:[2f26h]
	CMP        byte ptr DS:[2f26h],2h
	JBE        L_1a87
	MOV        byte ptr DS:[2f26h],0h
L_1a87:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_1952 ENDP
F_1a90 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        byte ptr DS:[545eh],0ffh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a52
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_88a0
	MOV        AX,60h
	PUSH       AX
	MOV        AX,0eh
	PUSH       AX
	MOV        AX,0afh
	PUSH       AX
	MOV        AX,0b2h
	PUSH       AX
	CALL       SUB_0000_88d6
	MOV        AX,28h
	PUSH       AX
	MOV        AX,2ah
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	CALL       SUB_0000_8a6c
	MOV        word ptr DS:[52c4h],0h
	CMP        byte ptr DS:[58a6h],0h
	JNZ        L_1ae7
	CMP        byte ptr DS:[58a7h],0h
	JNZ        L_1ae7
	JMP        L_1bbe
L_1ae7:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[6603h]
	SHL        AX,1h
	MOV        word ptr [BP + -0ch],AX
	MOV        BX,AX
	MOV        AX,word ptr [BX + 24d6h]
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [BX + 24deh]
	MOV        word ptr [BP + -0ah],AX
	SUB        SI,SI
L_1b0e:
	PUSH       DI
	PUSH       word ptr [BP + -6h]
	PUSH       SI
	CALL       F_150a
	OR         AX,AX
	JZ         L_1b92
	OR         SI,SI
	JNZ        L_1b36
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       F_10dc
	CMP        AX,0e0h
	JZ         L_1b80
	CMP        word ptr [BP + 4h],0h
	JZ         L_1b80
L_1b36:
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        word ptr [BP + -0eh],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 2f28h]
	ADD        AX,DI
	PUSH       AX
	MOV        AL,byte ptr [BX + 2f2ch]
	SUB        AH,AH
	ADD        AX,word ptr [BP + -6h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       SI
	CALL       F_1682
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        word ptr [BP + -10h],AX
	MOV        AX,DI
	MOV        BX,word ptr [BP + -10h]
	MOV        CL,byte ptr [BX + 2f28h]
	SUB        CH,CH
	SUB        AX,CX
	PUSH       AX
	MOV        AX,word ptr [BP + -6h]
	MOV        CL,byte ptr [BX + 2f2ch]
	SUB        AX,CX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	PUSH       SI
	CALL       F_1682
L_1b80:
	ADD        DI,word ptr [BP + -8h]
	MOV        AX,word ptr [BP + -0ah]
	ADD        word ptr [BP + -6h],AX
	INC        SI
	CMP        SI,4h
	JGE        L_1b92
	JMP        L_1b0e
L_1b92:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	DEC        word ptr [BP + -2h]
	JS         L_1bcb
	MOV        SI,word ptr [BP + -2h]
L_1ba0:
	SUB        DI,word ptr [BP + -8h]
	MOV        AX,word ptr [BP + -0ah]
	SUB        word ptr [BP + -6h],AX
	PUSH       DI
	PUSH       word ptr [BP + -6h]
	PUSH       SI
	CALL       F_1952
	DEC        SI
	JNS        L_1ba0
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	JMP        L_1bcb
	db 90h
	db 90h
L_1bbe:
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_88d6
L_1bcb:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a52
	MOV        word ptr DS:[52c4h],0h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_1a90 ENDP
F_1be0 PROC NEAR
	CALL       SUB_0000_a730
	MOV        AX,1h
	PUSH       AX
	CALL       F_1a90
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	MOV        AX,0eh
	PUSH       AX
	MOV        AX,0afh
	PUSH       AX
	MOV        AX,0b2h
	PUSH       AX
	CALL       SUB_0000_88fe
	CALL       F_1020
	CALL       F_01d2
	RET
	db 90h
	; Func
F_1be0 ENDP
F_1c0c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -2h],1h
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	AND        AX,0f0h
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + 4h],0h
	JZ         L_1c5f
	OR         AX,AX
	JNZ        L_1c5a
	CMP        AX,0e0h
	JZ         L_1c5a
	CMP        AX,0d0h
	JZ         L_1c5a
	CMP        AX,0c0h
	JZ         L_1c5a
	CMP        AX,0b0h
	JNZ        L_1c5f
L_1c5a:
	MOV        word ptr [BP + -2h],0h
L_1c5f:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_1c0c ENDP
F_1c6a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        word ptr [BP + -2h],0h
	CMP        word ptr [BP + 6h],0h
	JLE        L_1c80
	MOV        AX,6c6ch
	JMP        L_1c83
L_1c80:
	MOV        AX,6c74h
L_1c83:
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + 6h],0h
	JLE        L_1c94
	CMP        byte ptr DS:[5895h],7h
	JZ         L_1ca1
L_1c94:
	CMP        word ptr [BP + 6h],0h
	JGE        L_1ca8
	CMP        byte ptr DS:[5895h],0h
	JNZ        L_1ca8
L_1ca1:
	MOV        word ptr [BP + -2h],1h
	JMP        L_1cfe
L_1ca8:
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,byte ptr DS:[5895h]
	SUB        CH,CH
	ADD        AX,CX
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       F_1c0c
	OR         AX,AX
	JZ         L_1ce4
	MOV        AL,byte ptr [BP + 6h]
	ADD        byte ptr DS:[5895h],AL
	CMP        word ptr [BP + 6h],0h
	JLE        L_1cd2
	MOV        byte ptr DS:[6602h],5h
	JMP        L_1cd7
L_1cd2:
	MOV        byte ptr DS:[6602h],4h
L_1cd7:
	MOV        AX,1h
	PUSH       AX
	CALL       F_0134
	CALL       F_1be0
	JMP        L_1cfe
	db 90h
L_1ce4:
	MOV        AX,6c7ah
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,320h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	CALL       SUB_0000_c1de
L_1cfe:
	MOV        AX,word ptr [BP + -2h]
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_1c6a ENDP
F_1d08 PROC NEAR
	PUSH       SI
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,byte ptr [SI + 1e89h]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [SI + 1eb1h]
	MOV        DS:[5897h],AL
	MOV        AX,6c84h
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        byte ptr DS:[5895h],0h
	JZ         L_1d36
	MOV        byte ptr DS:[5895h],0ffh
	MOV        AX,6c8eh
	JMP        L_1d3e
L_1d36:
	MOV        byte ptr DS:[5895h],0h
	MOV        AX,6c9ch
L_1d3e:
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        byte ptr DS:[5893h],0h
	POP        SI
	RET
	db 90h
	; Func
F_1d08 ENDP
F_1d4a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        word ptr [BP + -2h],0h
	MOV        AX,6caah
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	MOV        AX,word ptr [SI + 24d6h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	AND        AX,7h
	MOV        word ptr [BP + -4h],AX
	MOV        AX,word ptr [SI + 24deh]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	AND        AX,7h
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[5c64h]
	SUB        AH,AH
	CMP        word ptr [BP + -4h],AX
	JNZ        L_1e00
	MOV        AL,DS:[5c65h]
	CMP        word ptr [BP + -6h],AX
	JNZ        L_1e00
	MOV        byte ptr DS:[58a1h],2h
	CALL       SUB_0000_fa32
	CALL       SUB_0000_fae6
	CALL       SUB_0000_fa56
	MOV        AX,2h
	PUSH       AX
	MOV        AL,DS:[5c67h]
	SUB        AH,AH
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_ddb6
	CMP        byte ptr DS:[58a0h],5h
	JNZ        L_1dec
	CMP        byte ptr DS:[5895h],0h
	JZ         L_1dce
	DEC        byte ptr DS:[5895h]
	JMP        L_1dd1
	db 90h
	db 90h
L_1dce:
	CALL       F_1d08
L_1dd1:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_fa3e
	CMP        byte ptr DS:[5893h],0h
	JZ         L_1e07
	MOV        AX,1h
	PUSH       AX
	CALL       F_0134
	CALL       F_1be0
	JMP        L_1e07
	db 90h
L_1dec:
	CMP        byte ptr DS:[58a0h],6h
	JNZ        L_1dd1
	CMP        byte ptr DS:[5895h],7h
	JNC        L_1dce
	INC        byte ptr DS:[5895h]
	JMP        L_1dd1
L_1e00:
	MOV        AX,6cb2h
	PUSH       AX
	CALL       SUB_0000_9680
L_1e07:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_1d4a ENDP
F_1e10 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h
	MOV        word ptr [BP + -4h],0h
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       F_10dc
	AND        AX,0f0h
	MOV        word ptr [BP + -8h],AX
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	AND        AX,8h
	MOV        word ptr [BP + -6h],AX
	CMP        word ptr [BP + -8h],10h
	JZ         L_1e74
	CMP        word ptr [BP + -8h],30h
	JZ         L_1e74
	OR         AX,AX
	JZ         L_1e79
	CMP        byte ptr DS:[57afh],BH
	JZ         L_1e79
L_1e74:
	MOV        word ptr [BP + -2h],1h
L_1e79:
	CMP        word ptr [BP + -8h],20h
	JZ         L_1e8b
	CMP        word ptr [BP + -8h],30h
	JZ         L_1e8b
	CMP        word ptr [BP + -8h],60h
	JNZ        L_1e90
L_1e8b:
	MOV        word ptr [BP + -4h],1h
L_1e90:
	CMP        word ptr [BP + -2h],0h
	JZ         L_1eee
	CMP        word ptr [BP + -4h],0h
	JZ         L_1eee
	MOV        AX,6cbah
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        DI,word ptr [BP + -4h]
	MOV        SI,word ptr [BP + -2h]
	JMP        L_1ece
	db 90h
L_1eac:
	OR         DI,DI
	JZ         L_1ee6
	CALL       SUB_0000_a49c
	CMP        AX,3h
	JZ         L_1ecc
	CMP        AX,4h
	JZ         L_1ed4
	CMP        AX,20h
	JZ         L_1ed8
	CMP        AX,44h
	JZ         L_1ed4
	CMP        AX,55h
	JNZ        L_1ece
L_1ecc:
	SUB        DI,DI
L_1ece:
	OR         SI,SI
	JZ         L_1ee6
	JMP        L_1eac
L_1ed4:
	SUB        SI,SI
	JMP        L_1ece
L_1ed8:
	MOV        AX,6cc6h
	PUSH       AX
	CALL       SUB_0000_9680
	SUB        DI,DI
	MOV        SI,DI
	JMP        L_1ece
	db 90h
L_1ee6:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	JMP        L_1f1c
L_1eee:
	CMP        word ptr [BP + -2h],0h
	JNZ        L_1efa
	CMP        word ptr [BP + -4h],0h
	JZ         L_1f04
L_1efa:
	MOV        AX,6cceh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_1f1c
	db 90h
L_1f04:
	CMP        word ptr [BP + -6h],0h
	JZ         L_1f16
	MOV        AX,6cd6h
L_1f0d:
	PUSH       AX
	CALL       SUB_0000_9680
	SUB        AX,AX
	JMP        L_1f4a
	db 90h
L_1f16:
	MOV        AX,6ceah
	JMP        L_1f0d
	db 90h
L_1f1c:
	CMP        word ptr [BP + -2h],0h
	JZ         L_1f30
	MOV        AX,0ffffh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_1c6a
	OR         AX,AX
	JNZ        L_1f44
L_1f30:
	CMP        word ptr [BP + -4h],0h
	JZ         L_1f47
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_1c6a
	OR         AX,AX
	JZ         L_1f47
L_1f44:
	CALL       F_1d08
L_1f47:
	MOV        AX,1h
L_1f4a:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
F_1e10 ENDP
_TEXT ENDS
END
