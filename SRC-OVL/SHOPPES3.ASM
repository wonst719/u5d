_TEXT SEGMENT BYTE 'CODE'
ORG 3670h
SUB_0000_3670:
ORG 34dah
SUB_0000_34da:
ORG 2262h
SUB_0000_2262:
ORG 22b6h
SUB_0000_22b6:
ORG 9dd6h
SUB_0000_9dd6:
ORG 9d82h
SUB_0000_9d82:
ORG 9d8eh
SUB_0000_9d8e:
ORG 9dfah
SUB_0000_9dfa:
ORG 4720h
SUB_0000_4720:
ORG 5906h
SUB_0000_5906:
ORG 57ech
SUB_0000_57ec:
ORG 7730h
SUB_0000_7730:
ORG 6d9ch
SUB_0000_6d9c:
ORG 5e2ch
SUB_0000_5e2c:
ORG 98bah
SUB_0000_98ba:
ORG 98aeh
SUB_0000_98ae:
ORG 4caeh
SUB_0000_4cae:
ORG 39b4h
SUB_0000_39b4:
ORG 6d1ch
SUB_0000_6d1c:
ORG 3a42h
SUB_0000_3a42:
ORG 3a12h
SUB_0000_3a12:
ORG 3b0eh
SUB_0000_3b0e:
ORG 2890h
SUB_0000_2890:
ORG 29a6h
SUB_0000_29a6:
ORG 448ch
SUB_0000_448c:
ORG 6d5ch
SUB_0000_6d5c:
ORG 98f6h
SUB_0000_98f6:
ORG 9e06h
SUB_0000_9e06:
ORG 9e12h
SUB_0000_9e12:
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
	SUB        SP,8h
	PUSH       SI
	SUB        DX,DX
	MOV        word ptr [BP + -4h],10h	; local_6
	MOV        SI,55c7h
	MOV        CX,10h
L_0014:
	MOV        AL,DS:[5893h]
	CMP        byte ptr [SI],AL
	JNZ        L_001c
	INC        DX
L_001c:
	ADD        SI,20h
	LOOP       L_0014
	MOV        word ptr [BP + -2h],DX	; local_4
	MOV        AX,DX
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0000 ENDP
F_002c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,4d84h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       F_0000
	MOV        BX,word ptr DS:[0b114h]
	MOV        CL,byte ptr [BX + 4dc4h]
	SUB        CH,CH
	CMP        CX,AX
	JBE        L_004c
	MOV        AX,1h
	JMP        L_006e
L_004c:
	MOV        AX,4d87h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        word ptr [BP + 4h],0ch	; param_1
	JNZ        L_005e
	MOV        AX,4d95h
	JMP        L_0061
L_005e:
	MOV        AX,4d9ch
L_0061:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,4da0h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        AX,AX
L_006e:
	POP        BP
	RET        2h
	; Func
F_002c ENDP
F_0072 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        AX,52h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_002c
	OR         AX,AX
	JNZ        L_008e
	JMP        L_029e
L_008e:
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 4d7eh]
	MUL        byte ptr DS:[585bh]
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,word ptr [BP + 8h]	; param_3
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	CWD
	SUB        AX,64h
	SBB        DX,0h
	NEG        AX
	ADC        DX,0h
	NEG        DX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_2262 ; 1000:0442h
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_22b6 ; 1000:0496h
	ADD        word ptr DS:[0b118h],AX
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	PUSH       word ptr [BX + 4e6eh]
	CALL       SUB_0000_9dd6 ; 1000:7FB6h [THUNK]
	MOV        AX,4dcah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_9d82 ; 1000:7F62h [THUNK]
	MOV        byte ptr [BP + -6h],AL	; local_8
	MOV        AX,4de0h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        byte ptr [BP + -6h],59h	; local_8
	JZ         L_00ff
	JMP        L_02a3
L_00ff:
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_011a
	MOV        AX,4de3h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,4e07h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	JMP        L_02a3
	db 90h
L_011a:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_9dfa ; 1000:7FDAh [THUNK]
	CALL       SUB_0000_4720 ; 1000:2900h
	MOV        AX,4e13h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        word ptr [BP + 6h],0ch	; param_2
	JNZ        L_013a
	MOV        AX,4e2ch
	JMP        L_013d
	db 90h
L_013a:
	MOV        AX,4e33h
L_013d:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,4e37h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	MOV        AL,DS:[594fh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5950h]
	PUSH       AX
	MOV        AL,DS:[5951h]
	PUSH       AX
	CALL       SUB_0000_57ec ; 1000:39CCh
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 4e7ah]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [BX + 4e80h]
	MOV        DS:[5897h],AL
	MOV        byte ptr DS:[24e6h],1h
	MOV        AL,DS:[587bh]
	MOV        byte ptr [BP + -2h],AL	; local_4
	MOV        word ptr [BP + -8h],0h	; local_a
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_01a8
	MOV        DX,AX
	MOV        SI,55b3h
	MOV        CX,word ptr [BP + -8h]	; local_a
L_0193:
	CMP        byte ptr [SI],47h
	JNZ        L_019b
	MOV        byte ptr [SI],53h
L_019b:
	ADD        SI,20h
	INC        CX
	MOV        AX,CX
	CMP        AX,DX
	JC         L_0193
	MOV        word ptr [BP + -8h],CX	; local_a
L_01a8:
	CALL       SUB_0000_4720 ; 1000:2900h
	CALL       SUB_0000_7730 ; 1000:5910h
	MOV        AX,4e44h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -8h],0ch	; local_a
	MOV        SI,0ch
L_01bd:
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_6d9c ; 1000:4F7Ch
	DEC        SI
	JZ         L_01ef
	JMP        L_01bd
	db 90h
L_01ca:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	CALL       SUB_0000_5e2c ; 1000:400Ch
	CALL       SUB_0000_4720 ; 1000:2900h
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_6d9c ; 1000:4F7Ch
	CMP        byte ptr DS:[587fh],14h
	JZ         L_01ec
	CMP        byte ptr DS:[587fh],5h
	JNZ        L_01ef
L_01ec:
	CALL       SUB_0000_98ba ; 1000:7A9Ah [THUNK]
L_01ef:
	CMP        byte ptr DS:[587fh],6h
	JNZ        L_01ca
	MOV        AX,4e51h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_98ae ; 1000:7A8Eh [THUNK]
	MOV        word ptr [BP + -8h],0h	; local_a
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0285
	MOV        DI,55a8h
L_0211:
	MOV        SI,DI
	CMP        byte ptr [SI + 0bh],44h
	JZ         L_0272
	MOV        AX,word ptr [SI + 12h]
	MOV        word ptr [SI + 10h],AX
	MOV        AL,byte ptr [SI + 0ah]
	SUB        AH,AH
	CMP        AX,41h
	JZ         L_0233
	CMP        AX,42h
	JZ         L_025e
	CMP        AX,4dh
	JNZ        L_0239
L_0233:
	MOV        AL,byte ptr [SI + 0eh]
L_0236:
	MOV        byte ptr [SI + 0fh],AL
L_0239:
	CMP        byte ptr [SI + 0bh],50h
	JNZ        L_0268
	MOV        byte ptr [SI + 0bh],44h
	MOV        word ptr [SI + 10h],0h
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	PUSH       SI
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,4e5bh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	JMP        L_0272
	db 90h
	db 90h
L_025e:
	MOV        AL,byte ptr [SI + 0eh]
	SUB        AH,AH
	SHR        AX,1h
	JMP        L_0236
	db 90h
L_0268:
	CMP        byte ptr [SI + 0bh],53h
	JNZ        L_0272
	MOV        byte ptr [SI + 0bh],47h
L_0272:
	ADD        DI,20h
	INC        word ptr [BP + -8h]	; local_a
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -8h],AX	; local_a
	JC         L_0211
	MOV        word ptr [BP + -4h],SI	; local_6
L_0285:
	MOV        AL,byte ptr [BP + -2h]	; local_4
	MOV        DS:[587bh],AL
	INC        byte ptr DS:[5896h]
	MOV        byte ptr DS:[24e6h],1h
	CALL       SUB_0000_4720 ; 1000:2900h
	MOV        word ptr [BP + 4h],0ffffh	; param_1
	JMP        L_02a3
L_029e:
	MOV        word ptr [BP + 4h],0fffeh	; param_1
L_02a3:
	MOV        AX,word ptr [BP + 4h]	; param_1
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0072 ENDP
F_02ae PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,36h
	PUSH       DI
	PUSH       SI
	MOV        AX,4ch
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_002c
	OR         AX,AX
	JNZ        L_02ce
L_02c7:
	MOV        AX,word ptr [BP + 4h]	; param_1
	JMP        L_048c
	db 90h
L_02ce:
	CMP        byte ptr DS:[585bh],1h
	JNZ        L_02e4
	MOV        AX,26e8h
	PUSH       AX
	CALL       SUB_0000_9dd6 ; 1000:7FB6h [THUNK]
	MOV        word ptr [BP + 4h],0ffffh	; param_1
	JMP        L_02c7
	db 90h
L_02e4:
	MOV        AX,word ptr [BP + 8h]	; param_3
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	CWD
	SUB        AX,64h
	SBB        DX,0h
	NEG        AX
	ADC        DX,0h
	NEG        DX
	MOV        word ptr [BP + -36h],AX	; local_38
	MOV        word ptr [BP + -34h],DX	; local_36
L_0301:
	MOV        word ptr [BP + -22h],1h	; local_24
	MOV        AX,4e86h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	CALL       SUB_0000_4cae ; 1000:2E8Eh
	MOV        word ptr [BP + -28h],AX	; local_2a
	CMP        AX,0ffffh
	JNZ        L_0328
	MOV        AX,4ea0h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + 4h],0fffeh	; param_1
	JMP        L_0480
	db 90h
L_0328:
	MOV        AX,4ea9h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        word ptr [BP + -28h],0h	; local_2a
	JNZ        L_035a
	MOV        AX,4each
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        byte ptr DS:[585bh],2h
	JBE        L_034a
	MOV        AX,73h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
L_034a:
	MOV        AX,4eb7h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -22h],0h	; local_24
	JMP        L_0480
	db 90h
L_035a:
	MOV        BX,word ptr [BP + -28h]	; local_2a
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JNZ        L_0378
	MOV        AX,2723h
	PUSH       AX
	CALL       SUB_0000_9dd6 ; 1000:7FB6h [THUNK]
	MOV        word ptr [BP + 4h],0ffffh	; param_1
	JMP        L_0480
	db 90h
L_0378:
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 4d7eh]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,CX
	SHL        AX,1h
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	PUSH       word ptr [BP + -34h]	; local_36
	PUSH       word ptr [BP + -36h]	; local_38
	CALL       SUB_0000_2262 ; 1000:0442h
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_22b6 ; 1000:0496h
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,4ecfh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,4f00h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	MOV        AX,4f24h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_9d82 ; 1000:7F62h [THUNK]
	MOV        byte ptr [BP + -24h],AL	; local_26
	MOV        AX,4f3ah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        byte ptr [BP + -24h],59h	; local_26
	JZ         L_03d8
	JMP        L_0480
L_03d8:
	MOV        word ptr [BP + 4h],1h	; param_1
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	CMP        word ptr [BP + -28h],AX	; local_2a
	JNZ        L_03ee
	MOV        byte ptr DS:[587bh],0ffh
	JMP        L_0400
L_03ee:
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	CMP        word ptr [BP + -28h],AX	; local_2a
	JNC        L_0400
	CMP        AL,0ffh
	JZ         L_0400
	DEC        byte ptr DS:[587bh]
L_0400:
	MOV        AX,word ptr [BP + -28h]	; local_2a
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -30h],AX	; local_32
	MOV        BX,AX
	MOV        AL,DS:[5893h]
	MOV        byte ptr [BX + 55c7h],AL
	MOV        byte ptr [BX + 55bfh],0h
	LEA        DI,[BP + -20h]	; local_22
	LEA        SI,[BX + 55a8h]
	PUSH       SS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	MOV        AX,word ptr [BP + -28h]	; local_2a
	MOV        word ptr [BP + -26h],AX	; local_28
	CMP        AX,0fh
	JGE        L_0465
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -32h],AX	; local_34
	MOV        SI,AX
	ADD        SI,55a8h
	MOV        DI,AX
	ADD        DI,55c8h
	MOV        AX,0fh
	SUB        AX,word ptr [BP + -28h]	; local_2a
	MOV        DX,AX
	ADD        word ptr [BP + -26h],DX	; local_28
L_044f:
	PUSH       SI
	PUSH       DI
	XCHG       DI,SI
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	ADD        SI,20h
	ADD        DI,20h
	DEC        DX
	JNZ        L_044f
L_0465:
	MOV        DI,5788h
	LEA        SI,[BP + -20h]	; local_22
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	DEC        byte ptr DS:[585bh]
	CALL       SUB_0000_4720 ; 1000:2900h
	MOV        AX,4f3dh
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
L_0480:
	CMP        word ptr [BP + -22h],0h	; local_24
	JNZ        L_0489
	JMP        L_0301
L_0489:
	JMP        L_02c7
L_048c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_02ae ENDP
F_0494 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        DX,word ptr [BP + 4h]	; param_1
L_049a:
	DEC        DX
	JZ         L_04ac
	MOV        BX,DX
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,DS:[5893h]
	CMP        byte ptr [BX + 55c7h],AL
	JNZ        L_049a
L_04ac:
	MOV        word ptr [BP + 4h],DX	; param_1
	MOV        AX,DX
	POP        BP
	RET        2h
	db 90h
	; Func
F_0494 ENDP
F_04b6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        DX,word ptr [BP + 4h]	; param_1
L_04bc:
	INC        DX
	CMP        DX,10h
	JGE        L_04d1
	MOV        BX,DX
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,DS:[5893h]
	CMP        byte ptr [BX + 55c7h],AL
	JNZ        L_04bc
L_04d1:
	MOV        word ptr [BP + 4h],DX	; param_1
	CMP        DX,10h
	JNZ        L_04de
	SUB        AX,AX
	JMP        L_04e1
	db 90h
L_04de:
	MOV        AX,word ptr [BP + 4h]	; param_1
L_04e1:
	POP        BP
	RET        2h
	db 90h
	; Func
F_04b6 ENDP
F_04e6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,3ch
	PUSH       DI
	PUSH       SI
	CALL       F_0000
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        byte ptr DS:[585bh],6h
	JNZ        L_0506
	MOV        AX,4f57h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	JMP        L_0899
	db 90h
L_0506:
	CMP        word ptr [BP + -2h],0h	; local_4
	JNZ        L_0516
	MOV        AX,4f7ah
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	JMP        L_0899
L_0516:
	CMP        word ptr [BP + -2h],1h	; local_4
	JG         L_051f
	JMP        L_070c
L_051f:
	MOV        AX,4fa7h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_39b4 ; 1000:1B94h
	CALL       SUB_0000_6d1c ; 1000:4EFCh
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_3a42 ; 1000:1C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_3a42 ; 1000:1C22h
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        word ptr [BP + -2ch],0dh	; local_2e
	MOV        SI,0dh
L_0574:
	MOV        AX,11h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	DEC        SI
	JNZ        L_0574
	MOV        AX,13h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        SI,1h
L_0588:
	SUB        AX,AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_3a12 ; 1000:1BF2h
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        AX,0eh
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_3a12 ; 1000:1BF2h
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	INC        SI
	CMP        SI,8h
	JL         L_0588
	MOV        word ptr [BP + -2ch],SI	; local_2e
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        word ptr [BP + -2ch],0dh	; local_2e
	MOV        SI,0dh
L_05c4:
	MOV        AX,15h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	DEC        SI
	JNZ        L_05c4
	MOV        AX,16h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_3a12 ; 1000:1BF2h
	MOV        AX,4fc0h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_3a12 ; 1000:1BF2h
	MOV        AX,4fcah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -32h],10h	; local_34
	MOV        SI,55e7h
	MOV        DI,55c8h
	MOV        word ptr [BP + -38h],0fh	; local_3a
L_0606:
	MOV        AL,DS:[5893h]
	CMP        byte ptr [SI],AL
	JNZ        L_0623
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_3b0e ; 1000:1CEEh
	PUSH       AX
	CALL       SUB_0000_3a12 ; 1000:1BF2h
	PUSH       DI
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
L_0623:
	ADD        SI,20h
	ADD        DI,20h
	DEC        word ptr [BP + -38h]	; local_3a
	JNZ        L_0606
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_39b4 ; 1000:1B94h
	MOV        word ptr [BP + -28h],0h	; local_2a
	SUB        AX,AX
	PUSH       AX
	CALL       F_04b6
	MOV        word ptr [BP + -32h],AX	; local_34
	MOV        DI,28h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890 ; 1000:0A70h
L_064d:
	MOV        AX,0c6h
	PUSH       AX
	PUSH       DI
	MOV        AX,131h
	PUSH       AX
	LEA        AX,[DI + 7h]
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	MOV        SI,word ptr [BP + -26h]	; local_28
L_0660:
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        byte ptr [BP + -30h],AL	; local_32
	SUB        AH,AH
	CMP        AX,3h
	JZ         L_067c
	JA         L_06dc
	CMP        AX,1h
	JZ         L_067c
	CMP        AX,2h
	JZ         L_06a4
	JMP        L_06f0
	db 90h
L_067c:
	PUSH       word ptr [BP + -32h]	; local_34
	CALL       F_0494
	MOV        SI,AX
	OR         SI,SI
	JZ         L_069e
	MOV        AX,0c6h
	PUSH       AX
	PUSH       DI
	MOV        AX,131h
	PUSH       AX
	LEA        AX,[DI + 7h]
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	MOV        word ptr [BP + -32h],SI	; local_34
	SUB        DI,8h
L_069e:
	OR         SI,SI
	JNZ        L_06f4
	JMP        L_0660
L_06a4:
	PUSH       word ptr [BP + -32h]	; local_34
	CALL       F_04b6
	MOV        SI,AX
	OR         SI,SI
	JZ         L_069e
	MOV        AX,0c6h
	PUSH       AX
	PUSH       DI
	MOV        AX,131h
	PUSH       AX
	LEA        AX,[DI + 7h]
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	MOV        word ptr [BP + -32h],SI	; local_34
	ADD        DI,8h
	JMP        L_069e
L_06c8:
	MOV        AX,4fd8h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -32h],0h	; local_34
L_06d4:
	MOV        SI,1h
	MOV        word ptr [BP + -28h],SI	; local_2a
	JMP        L_069e
L_06dc:
	CMP        AX,4h
	JZ         L_06a4
	CMP        AX,0dh
	JZ         L_06d4
	CMP        AX,1bh
	JZ         L_06c8
	CMP        AX,20h
	JZ         L_06d4
L_06f0:
	SUB        SI,SI
	JMP        L_069e
L_06f4:
	MOV        word ptr [BP + -26h],SI	; local_28
	CMP        word ptr [BP + -28h],0h	; local_2a
	JNZ        L_0700
	JMP        L_064d
L_0700:
	MOV        word ptr [BP + -2eh],DI	; local_30
	CALL       SUB_0000_6d5c ; 1000:4F3Ch
	CALL       SUB_0000_4720 ; 1000:2900h
	JMP        L_0715
	db 90h
L_070c:
	SUB        AX,AX
	PUSH       AX
	CALL       F_04b6
	MOV        word ptr [BP + -32h],AX	; local_34
L_0715:
	CMP        word ptr [BP + -32h],0h	; local_34
	JNZ        L_071e
	JMP        L_0899
L_071e:
	MOV        BX,word ptr [BP + -32h]	; local_34
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55bfh]
	SUB        AH,AH
	MOV        word ptr [BP + -2ah],AX	; local_2c
	OR         AX,AX
	JNZ        L_0737
	MOV        word ptr [BP + -2ah],1h	; local_2c
L_0737:
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 4d7eh]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,CX
	SHL        AX,1h
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	CWD
	SUB        AX,64h
	SBB        DX,0h
	NEG        AX
	ADC        DX,0h
	NEG        DX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_2262 ; 1000:0442h
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_22b6 ; 1000:0496h
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,word ptr [BP + -2ah]	; local_2c
	IMUL       word ptr DS:[0b118h]
	MOV        DS:[0b118h],AX
	MOV        AX,4fe1h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_07ac
	MOV        AX,275ah
	PUSH       AX
	CALL       SUB_0000_9dd6 ; 1000:7FB6h [THUNK]
	CALL       SUB_0000_98f6 ; 1000:7AD6h [THUNK]
	MOV        word ptr [BP + 4h],0ffffh	; param_1
	JMP        L_0899
	db 90h
L_07ac:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_9dfa ; 1000:7FDAh [THUNK]
	CALL       SUB_0000_4720 ; 1000:2900h
	MOV        word ptr [BP + 4h],1h	; param_1
	MOV        BX,word ptr [BP + -32h]	; local_34
	MOV        CL,5h
	SHL        BX,CL
	LEA        DI,[BP + -22h]	; local_24
	LEA        SI,[BX + 55a8h]
	PUSH       SS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	MOV        AX,word ptr [BP + -32h]	; local_34
	MOV        word ptr [BP + -2ch],AX	; local_2e
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -2ch]	; local_2e
	JGE        L_081f
	MOV        word ptr [BP + -38h],AX	; local_3a
	MOV        AX,word ptr [BP + -32h]	; local_34
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -3ch],AX	; local_3e
	MOV        SI,AX
	ADD        SI,55a8h
	MOV        DI,AX
	ADD        DI,5588h
	MOV        AX,word ptr [BP + -32h]	; local_34
	SUB        AX,word ptr [BP + -38h]	; local_3a
	MOV        DX,AX
	NEG        AX
	ADD        word ptr [BP + -2ch],AX	; local_2e
L_0809:
	PUSH       SI
	PUSH       DI
	XCHG       DI,SI
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	SUB        SI,20h
	SUB        DI,20h
	DEC        DX
	JNZ        L_0809
L_081f:
	MOV        BL,byte ptr DS:[585bh]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	LEA        DI,[BX + 55a8h]
	LEA        SI,[BP + -22h]	; local_24
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	MOV        AL,DS:[585bh]
	INC        byte ptr DS:[585bh]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -24h],AX	; local_26
	MOV        BX,AX
	MOV        byte ptr [BX + 1fh],0h
	CMP        byte ptr [BX + 0bh],50h
	JNZ        L_0864
	MOV        byte ptr [BX + 0bh],44h
	MOV        word ptr [BX + 10h],0h
	MOV        AX,5005h
	JMP        L_088b
L_0864:
	MOV        SI,BX
	MOV        AX,word ptr [SI + 12h]
	MOV        word ptr [BX + 10h],AX
	MOV        AL,byte ptr [BX + 0ah]
	SUB        AH,AH
	CMP        AX,41h
	JZ         L_0880
	CMP        AX,42h
	JZ         L_089e
	CMP        AX,4dh
	JNZ        L_0888
L_0880:
	MOV        SI,BX
	MOV        AL,byte ptr [SI + 0eh]
L_0885:
	MOV        byte ptr [BX + 0fh],AL
L_0888:
	MOV        AX,5028h
L_088b:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,5055h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	CALL       SUB_0000_4720 ; 1000:2900h
L_0899:
	MOV        AX,word ptr [BP + 4h]	; param_1
	JMP        L_08ac
L_089e:
	MOV        BX,word ptr [BP + -24h]	; local_26
	MOV        SI,BX
	MOV        AL,byte ptr [SI + 0eh]
	SUB        AH,AH
	SHR        AX,1h
	JMP        L_0885
L_08ac:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_04e6 ENDP
F_08b4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 55b6h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,byte ptr [BX + 55b1h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	SUB        AL,AL
	MOV        DS:[588eh],AL
	MOV        DS:[587ah],AL
	CALL       SUB_0000_4720 ; 1000:2900h
	CALL       SUB_0000_9e06 ; 1000:7FE6h [THUNK]
	JMP        L_09a5
	db 90h
L_08f2:
	CMP        byte ptr [BP + -0ch],59h	; local_e
	JNZ        L_08ff
	MOV        AX,5062h
L_08fb:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_08ff:
	CMP        byte ptr [BP + -0ch],4eh	; local_e
	JZ         L_090e
	CMP        byte ptr [BP + -0ch],59h	; local_e
	JZ         L_090e
	JMP        L_09ab
L_090e:
	CMP        byte ptr [BP + -0ch],4eh	; local_e
	JNZ        L_0917
	JMP        L_09c8
L_0917:
	MOV        AX,5066h
	PUSH       AX
	CALL       SUB_0000_9d8e ; 1000:7F6Eh [THUNK]
	MOV        AX,508eh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        DI,word ptr [BP + -6h]	; local_8
	MOV        SI,word ptr [BP + -8h]	; local_a
L_092b:
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        byte ptr [BP + -0ch],AL	; local_e
	SUB        AH,AH
	CMP        AX,20h
	JZ         L_095f
	CMP        AX,4ch
	JZ         L_096c
	CMP        AX,50h
	JZ         L_0986
	CMP        AX,52h
	JZ         L_094c
	MOV        byte ptr [BP + -0ch],AH	; local_e
	JMP        L_0964
L_094c:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       SI
	CALL       F_0072
	MOV        DI,AX
	CMP        DI,-2h
	JLE        L_0964
	MOV        SI,DI
L_095f:
	MOV        word ptr [BP + -2h],1h	; local_4
L_0964:
	CMP        byte ptr [BP + -0ch],0h	; local_e
	JNZ        L_0992
	JMP        L_092b
L_096c:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       SI
	CALL       F_02ae
	MOV        DI,AX
	CMP        DI,-2h
	JLE        L_097f
	MOV        SI,DI
L_097f:
	CMP        SI,-1h
	JNZ        L_0964
	JMP        L_095f
L_0986:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       SI
	CALL       F_04e6
	MOV        SI,AX
	JMP        L_097f
	db 90h
L_0992:
	MOV        word ptr [BP + -6h],DI	; local_8
	MOV        word ptr [BP + -8h],SI	; local_a
	CMP        word ptr [BP + -2h],0h	; local_4
	JNZ        L_09a5
	MOV        AX,50bdh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_09a5:
	CMP        word ptr [BP + -2h],0h	; local_4
	JNZ        L_09c8
L_09ab:
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        byte ptr [BP + -0ch],AL	; local_e
	CMP        AL,20h
	JNZ        L_09b9
	MOV        byte ptr [BP + -0ch],4eh	; local_e
L_09b9:
	CMP        byte ptr [BP + -0ch],4eh	; local_e
	JZ         L_09c2
	JMP        L_08f2
L_09c2:
	MOV        AX,505fh
	JMP        L_08fb
L_09c8:
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       SUB_0000_9e12 ; 1000:7FF2h [THUNK]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
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
F_08b4 ENDP
_TEXT ENDS
END
