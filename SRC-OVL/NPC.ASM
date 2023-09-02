_TEXT SEGMENT BYTE 'CODE'
ORG 82deh
SUB_0000_82de:
ORG 7e02h
SUB_0000_7e02:
ORG 0a172h
SUB_0000_a172:
ORG 9472h
SUB_0000_9472:
ORG 981eh
SUB_0000_981e:
ORG 0d89ah
SUB_0000_d89a:
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
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2ah
	PUSH       DI
	PUSH       SI
	DEC        byte ptr DS:[5893h]
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	MOV        CL,3h
	SHR        AX,CL
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JZ         L_0036
	CMP        AX,1h
	JNZ        L_0024
	JMP        L_00b0
L_0024:
	CMP        AX,2h
	JNZ        L_002c
	JMP        L_00b8
L_002c:
	CMP        AX,3h
	JNZ        L_0034
	JMP        L_00c0
L_0034:
	JMP        L_003b
L_0036:
	MOV        word ptr [BP + -4h],6d46h
L_003b:
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	MOV        DX,word ptr [BP + -2h]
	MOV        CL,3h
	SHL        DX,CL
	SUB        AX,DX
	MOV        word ptr [BP + -26h],AX
	MOV        AX,240h
	IMUL       word ptr [BP + -26h]
	MOV        word ptr [BP + -28h],AX
	PUSH       word ptr [BP + -4h]
	MOV        AX,5d5eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	PUSH       word ptr [BP + -28h]
	CALL       SUB_0000_82de ; 1000:256Eh
	PUSH       word ptr [BP + -4h]
	MOV        AX,659eh
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	MOV        AX,word ptr [BP + -28h]
	ADD        AH,2h
	PUSH       AX
	CALL       SUB_0000_82de ; 1000:256Eh
	PUSH       word ptr [BP + -4h]
	LEA        AX,[BP + -24h]
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	MOV        AX,word ptr [BP + -28h]
	ADD        AX,220h
	PUSH       AX
	CALL       SUB_0000_82de ; 1000:256Eh
	MOV        word ptr [BP + -2h],0h
	MOV        SI,5f68h
	MOV        CX,word ptr [BP + -2h]
L_009b:
	MOV        DI,CX
	MOV        AL,byte ptr [BP + DI + -24h]
	SUB        AH,AH
	MOV        word ptr [SI],AX
	ADD        SI,10h
	INC        CX
	CMP        CX,20h
	JGE        L_00c8
	JMP        L_009b
	db 90h
L_00b0:
	MOV        word ptr [BP + -4h],6d50h
	JMP        L_003b
	db 90h
L_00b8:
	MOV        word ptr [BP + -4h],6d5eh
	JMP        L_003b
L_00c0:
	MOV        word ptr [BP + -4h],6d6ah
	JMP        L_003b
L_00c8:
	MOV        word ptr [BP + -2h],CX
	INC        byte ptr DS:[5893h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_00d6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        DI,1h
	MOV        word ptr [BP + -6h],5f6eh	; local_8
	MOV        word ptr [BP + -8h],5f6eh	; local_a
	MOV        word ptr [BP + -0ah],5f70h	; local_c
	MOV        SI,10h
	MOV        word ptr [BP + -0eh],6560h	; local_10
	MOV        word ptr [BP + -10h],617eh	; local_12
	MOV        word ptr [BP + -12h],65c4h	; local_14
L_0102:
	CMP        byte ptr [DI + 659eh],0h
	JNZ        L_010e
	MOV        BX,word ptr [BP + -6h]	; local_8
	JMP        L_016c
L_010e:
	PUSH       DI
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_12e0
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        word ptr [BX],1h
	MOV        AX,SI
	ADD        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BP + -14h],AX	; local_16
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 5d61h]
	SUB        AH,AH
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        word ptr [BX],AX
	MOV        BX,word ptr [BP + -14h]	; local_16
	MOV        AL,byte ptr [BX + 5d64h]
	MOV        word ptr [SI + 5f62h],AX
	MOV        AL,byte ptr [BX + 5d67h]
	MOV        word ptr [SI + 5f64h],AX
	MOV        AL,byte ptr [DI + 659eh]
	MOV        word ptr [SI + 5f66h],AX
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [SI + 5f6ch],AX
	MOV        word ptr [SI + 5f6ah],0h
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        word ptr [BX],0ffffh
	MOV        BX,word ptr [BP + -10h]	; local_12
	MOV        byte ptr [BX],0h
	MOV        BX,word ptr [BP + -12h]	; local_14
L_016c:
	MOV        word ptr [BX],0h
	ADD        word ptr [BP + -6h],10h	; local_8
	ADD        word ptr [BP + -8h],10h	; local_a
	ADD        word ptr [BP + -0ah],10h	; local_c
	ADD        SI,10h
	ADD        word ptr [BP + -0eh],2h	; local_10
	ADD        word ptr [BP + -10h],20h	; local_12
	ADD        word ptr [BP + -12h],2h	; local_14
	INC        DI
	CMP        DI,20h
	JGE        L_0194
	JMP        L_0102
L_0194:
	MOV        word ptr [BP + -2h],DI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_00d6 ENDP
F_01a0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        word ptr [BP + 6h],0h	; param_2
	JZ         L_01b4
	MOV        word ptr [BP + -2h],0ffffh	; local_4
	JMP        L_01b9
	db 90h
L_01b4:
	MOV        word ptr [BP + -2h],0fffeh	; local_4
L_01b9:
	PUSH       word ptr [BP + 0ah]	; param_4
	PUSH       word ptr [BP + 8h]	; param_3
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_032c
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_01a0 ENDP
F_01d2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	CMP        word ptr [BP + 6h],-1h	; param_2
	JNZ        L_01e4
	MOV        byte ptr [BP + -0ch],0c8h	; local_e
L_01e4:
	CMP        word ptr [BP + 6h],-2h	; param_2
	JNZ        L_01ee
	MOV        byte ptr [BP + -0ch],0c9h	; local_e
L_01ee:
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_12e0
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        word ptr [BP + -14h],0h	; local_16
L_0207:
	SUB        SI,SI
	MOV        DI,word ptr [BP + -14h]	; local_16
	MOV        word ptr [BP + -10h],DI	; local_12
	MOV        word ptr [BP + -12h],DI	; local_14
L_0212:
	PUSH       SI
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       F_0adc
	OR         AX,AX
	JZ         L_0236
	MOV        BX,word ptr [BP + -12h]	; local_14
	ADD        BX,word ptr DS:[0b11ch]
	MOV        byte ptr [BX + SI],0h
	JMP        L_0240
	db 90h
L_0236:
	MOV        BX,word ptr [BP + -10h]	; local_12
	ADD        BX,word ptr DS:[0b11ch]
	MOV        byte ptr [BX + SI],90h
L_0240:
	CMP        word ptr [BP + 6h],0h	; param_2
	JGE        L_025c
	MOV        BX,DI
	ADD        BX,SI
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	CMP        byte ptr [BX + 6608h],AL
	JNZ        L_025c
	MOV        BX,word ptr DS:[0b11ch]
	ADD        BX,DI
	MOV        byte ptr [BX + SI],5h
L_025c:
	INC        SI
	CMP        SI,20h
	JL         L_0212
	MOV        word ptr [BP + -6h],SI	; local_8
	ADD        word ptr [BP + -14h],20h	; local_16
	INC        word ptr [BP + -4h]	; local_6
	CMP        word ptr [BP + -4h],20h	; local_6
	JL         L_0207
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,5f5eh
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        DI,5d52h
L_0287:
	MOV        SI,DI
	CMP        byte ptr [SI],3fh
	JBE        L_02c0
	MOV        AL,byte ptr [SI + 2h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 3h]
	PUSH       AX
	MOV        BX,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	CALL       F_06a0
	CMP        AX,4h
	JGE        L_02c0
	MOV        BL,byte ptr [SI + 3h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [SI + 2h]
	SUB        AH,AH
	ADD        BX,AX
	ADD        BX,word ptr DS:[0b11ch]
	MOV        byte ptr [BX],90h
L_02c0:
	SUB        DI,8h
	CMP        DI,5c5ah
	JA         L_0287
	MOV        word ptr [BP + -0ah],SI	; local_c
	MOV        word ptr [BP + -0ah],5c5ah	; local_c
	MOV        AL,DS:[5c5dh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,DS:[5c5ch]
	MOV        DI,AX
	PUSH       DI
	PUSH       SI
	MOV        BX,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	CALL       F_06a0
	CMP        AX,4h
	JGE        L_02fd
	MOV        BX,SI
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr DS:[0b11ch]
	MOV        byte ptr [BX + DI],90h
L_02fd:
	CMP        word ptr [BP + 6h],-1h	; param_2
	JLE        L_0313
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + 0ah]	; param_4
	MOV        SI,word ptr DS:[0b11ch]
	MOV        byte ptr [BX + SI],CL
L_0313:
	MOV        BX,word ptr [BP + 0ch]	; param_5
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + 0eh]	; param_6
	MOV        SI,word ptr DS:[0b11ch]
	MOV        byte ptr [BX + SI],46h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ch
	; Func
F_01d2 ENDP
F_032c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,50h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ch],0h	; local_e
	MOV        word ptr [BP + -0ah],0h	; local_c
	MOV        word ptr [BP + -2h],1h	; local_4
	PUSH       word ptr [BP + 0eh]	; param_6
	PUSH       word ptr [BP + 0ch]	; param_5
	PUSH       word ptr [BP + 0ah]	; param_4
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_01d2
	MOV        AL,byte ptr [BP + 0eh]	; param_6
	MOV        byte ptr [BP + -2ch],AL	; local_2e
	MOV        AL,byte ptr [BP + 0ch]	; param_5
	MOV        byte ptr [BP + -4eh],AL	; local_50
	MOV        DX,word ptr [BP + -0ch]	; local_e
L_0367:
	OR         DX,DX
	JZ         L_036e
	JMP        L_0479
L_036e:
	MOV        BX,word ptr [BP + -0ah]	; local_c
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -2ch]
	SUB        AH,AH
	MOV        DI,AX
	MOV        BX,word ptr [BP + -0ah]	; local_c
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -4eh]
	MOV        SI,AX
	MOV        BX,SI
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr DS:[0b11ch]
	MOV        AL,byte ptr [BX + DI]
	MOV        CL,4h
	SHR        AX,CL
	MOV        word ptr [BP + -2eh],AX	; local_30
	MOV        word ptr [BP + -4h],0h	; local_6
L_039c:
	MOV        AX,word ptr [BP + -2eh]	; local_30
	CMP        AX,1h
	JZ         L_03b6
	CMP        AX,2h
	JZ         L_0404
	CMP        AX,3h
	JZ         L_040c
	CMP        AX,4h
	JZ         L_0412
	JMP        L_03bc
	db 90h
L_03b6:
	DEC        DI
L_03b7:
	JNS        L_03bc
L_03b9:
	MOV        DX,2h
L_03bc:
	CMP        DX,2h
	JZ         L_0440
	MOV        BX,SI
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr DS:[0b11ch]
	CMP        byte ptr [BX + DI],10h
	JNC        L_0440
	MOV        AX,SI
	SHL        AX,CL
	ADD        AX,word ptr DS:[0b11ch]
	ADD        AX,DI
	MOV        word ptr [BP + -50h],AX	; local_52
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	AND        AX,0fh
	MOV        DX,AX
	MOV        AL,byte ptr [BP + -2eh]	; local_30
	MOV        CL,4h
	SHL        AL,CL
	MOV        byte ptr [BX],AL
	CMP        DX,5h
	JNZ        L_0416
	MOV        DX,1h
	MOV        word ptr DS:[5876h],DI
	MOV        word ptr DS:[5878h],SI
	JMP        L_046e
	db 90h
L_0404:
	INC        SI
	CMP        SI,20h
L_0408:
	JLE        L_03bc
	JMP        L_03b9
L_040c:
	INC        DI
	CMP        DI,20h
	JMP        L_0408
L_0412:
	DEC        SI
	JMP        L_03b7
	db 90h
L_0416:
	MOV        AX,word ptr [BP + -0ah]	; local_c
	CMP        word ptr [BP + -2h],AX	; local_4
	JZ         L_0435
	MOV        BX,word ptr [BP + -2h]	; local_4
	ADD        BX,BP
	MOV        AX,DI
	MOV        byte ptr [BX + -2ch],AL
	MOV        BX,word ptr [BP + -2h]	; local_4
	ADD        BX,BP
	MOV        AX,SI
	MOV        byte ptr [BX + -4eh],AL
	INC        word ptr [BP + -2h]	; local_4
L_0435:
	CMP        word ptr [BP + -2h],20h	; local_4
	JL         L_0440
	MOV        word ptr [BP + -2h],0h	; local_4
L_0440:
	SUB        DX,DX
	MOV        AX,word ptr [BP + -2eh]	; local_30
	AND        AX,3h
	INC        AX
	MOV        word ptr [BP + -2eh],AX	; local_30
	MOV        BX,word ptr [BP + -0ah]	; local_c
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -2ch]
	SUB        AH,AH
	MOV        DI,AX
	MOV        BX,word ptr [BP + -0ah]	; local_c
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -4eh]
	MOV        SI,AX
	INC        word ptr [BP + -4h]	; local_6
	CMP        word ptr [BP + -4h],4h	; local_6
	JGE        L_046e
	JMP        L_039c
L_046e:
	MOV        word ptr [BP + -8h],DI	; local_a
	MOV        word ptr [BP + -6h],SI	; local_8
	CMP        DX,1h
	JNZ        L_0486
L_0479:
	MOV        word ptr [BP + -0ch],DX	; local_e
	OR         DX,DX
	JZ         L_04a0
	MOV        AX,1h
	JMP        L_04a3
	db 90h
L_0486:
	INC        word ptr [BP + -0ah]	; local_c
	CMP        word ptr [BP + -0ah],20h	; local_c
	JNZ        L_0494
	MOV        word ptr [BP + -0ah],0h	; local_c
L_0494:
	MOV        AX,word ptr [BP + -2h]	; local_4
	CMP        word ptr [BP + -0ah],AX	; local_c
	JZ         L_0479
	JMP        L_0367
	db 90h
L_04a0:
	MOV        AX,word ptr [BP + -0ch]	; local_e
L_04a3:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ch
	db 90h
	; Func
F_032c ENDP
F_04ac PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],0h	; local_6
	SUB        DX,DX
	MOV        BX,word ptr [BP + 0ah]	; param_3
	SHL        BX,1h
	MOV        word ptr [BX + 655eh],DX
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + 6h]	; param_2
	ADD        BX,word ptr DS:[0b11ch]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -0eh],AX	; local_10
	AND        AX,0fh
	MOV        DI,AX
	MOV        SI,word ptr [BP + -0eh]	; local_10
	MOV        CL,4h
	SHR        SI,CL
	MOV        word ptr [BP + -0ah],SI	; local_c
	MOV        AX,word ptr [BP + 0ah]	; param_3
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX	; local_e
L_04f2:
	MOV        AX,SI
	CMP        AX,1h
	JZ         L_050a
	CMP        AX,2h
	JZ         L_0546
	CMP        AX,3h
	JZ         L_054c
	CMP        AX,4h
	JZ         L_0552
	JMP        L_050d
L_050a:
	INC        word ptr [BP + 6h]	; param_2
L_050d:
	CMP        word ptr [BP + -0ah],SI	; local_c
	JNZ        L_051a
	CMP        DI,6h
	JZ         L_051a
	INC        word ptr [BP + -4h]	; local_6
L_051a:
	CMP        word ptr [BP + -0ah],SI	; local_c
	JNZ        L_0524
	CMP        DI,6h
	JNZ        L_0560
L_0524:
	MOV        BX,word ptr [BP + -0ch]	; local_e
	ADD        BX,DX
	MOV        AL,byte ptr [BP + -4h]	; local_6
	MOV        byte ptr [BX + 615eh],AL
	INC        DX
	MOV        BX,word ptr [BP + -0ch]	; local_e
	ADD        BX,DX
	MOV        AL,byte ptr [BP + -0ah]	; local_c
	MOV        byte ptr [BX + 615eh],AL
	INC        DX
	CMP        DI,6h
	JNZ        L_0558
	JMP        L_0588
	db 90h
L_0546:
	DEC        word ptr [BP + 4h]	; param_1
	JMP        L_050d
	db 90h
L_054c:
	DEC        word ptr [BP + 6h]	; param_2
	JMP        L_050d
	db 90h
L_0552:
	INC        word ptr [BP + 4h]	; param_1
	JMP        L_050d
	db 90h
L_0558:
	MOV        word ptr [BP + -0ah],SI	; local_c
	MOV        word ptr [BP + -4h],1h	; local_6
L_0560:
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + 6h]	; param_2
	ADD        BX,word ptr DS:[0b11ch]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -10h],AX	; local_12
	MOV        SI,AX
	MOV        CL,4h
	SHR        SI,CL
	AND        AX,0fh
	MOV        DI,AX
	CMP        DX,20h
	JGE        L_0588
	JMP        L_04f2
L_0588:
	MOV        word ptr [BP + -6h],DI	; local_8
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        word ptr [BP + -8h],DX	; local_a
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        AX,DX
	SUB        AX,2h
	MOV        word ptr [BP + -6h],AX	; local_8
	OR         AX,AX
	JGE        L_05a5
	JMP        L_0627
L_05a5:
	MOV        DI,word ptr [BP + 0ah]	; param_3
	MOV        CL,5h
	SHL        DI,CL
	MOV        DX,word ptr [BP + -4h]	; local_6
	MOV        CX,AX
L_05b1:
	MOV        AX,DI
	ADD        AX,DX
	ADD        AX,615eh
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AX,DI
	ADD        AX,CX
	ADD        AX,615eh
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -0ch]	; local_e
	MOV        AX,SI
	MOV        byte ptr [BX],AL
	INC        CX
	INC        DX
	MOV        AX,DI
	ADD        AX,DX
	ADD        AX,615eh
	MOV        word ptr [BP + -12h],AX	; local_14
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	INC        AX
	AND        AX,3h
	INC        AX
	MOV        SI,AX
	MOV        AX,DI
	ADD        AX,CX
	ADD        AX,615eh
	MOV        word ptr [BP + -14h],AX	; local_16
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	INC        AL
	AND        AL,3h
	INC        AL
	MOV        BX,word ptr [BP + -12h]	; local_14
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -14h]	; local_16
	MOV        AX,SI
	MOV        byte ptr [BX],AL
	INC        DX
	SUB        CX,3h
	CMP        CX,DX
	JGE        L_05b1
	MOV        word ptr [BP + -0ah],SI	; local_c
	MOV        word ptr [BP + -4h],DX	; local_6
	MOV        word ptr [BP + -6h],CX	; local_8
L_0627:
	MOV        AX,word ptr [BP + -8h]	; local_a
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_04ac ENDP
F_0632 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,word ptr [BP + 4h]	; param_1
	CMP        AX,1h
	JZ         L_064e
	CMP        AX,2h
	JZ         L_0662
	CMP        AX,3h
	JZ         L_0676
	CMP        AX,4h
	JZ         L_068a
	JMP        L_069b
L_064e:
	INC        word ptr DS:[5876h]
	CMP        word ptr DS:[5878h],20h
	JLE        L_069b
	MOV        word ptr DS:[5876h],20h
	JMP        L_069b
	db 90h
L_0662:
	DEC        word ptr DS:[5878h]
	CMP        word ptr DS:[5876h],0h
	JGE        L_069b
	MOV        word ptr DS:[5878h],0h
	JMP        L_069b
	db 90h
L_0676:
	DEC        word ptr DS:[5876h]
	CMP        word ptr DS:[5878h],0h
	JGE        L_069b
	MOV        word ptr DS:[5876h],0h
	JMP        L_069b
	db 90h
L_068a:
	INC        word ptr DS:[5878h]
	CMP        word ptr DS:[5876h],20h
	JLE        L_069b
	MOV        word ptr DS:[5878h],20h
L_069b:
	POP        BP
	RET        2h
	db 90h
	; Func
F_0632 ENDP
F_06a0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,word ptr [BP + 0ah]	; param_4
	SUB        AX,word ptr [BP + 6h]	; param_2
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,word ptr [BP + 8h]	; param_3
	SUB        AX,word ptr [BP + 4h]	; param_1
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        word ptr [BP + -2h],0h	; local_4
	JGE        L_06c6
	MOV        AX,word ptr [BP + -2h]	; local_4
	NEG        AX
	MOV        word ptr [BP + -2h],AX	; local_4
L_06c6:
	CMP        word ptr [BP + -4h],0h	; local_6
	JGE        L_06d4
	MOV        AX,word ptr [BP + -4h]	; local_6
	NEG        AX
	MOV        word ptr [BP + -4h],AX	; local_6
L_06d4:
	MOV        AX,word ptr [BP + -4h]	; local_6
	ADD        word ptr [BP + -2h],AX	; local_4
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        SP,BP
	POP        BP
	RET        8h
	db 90h
	; Func
F_06a0 ENDP
F_06e4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,22h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -16h],5c5ah	; local_18
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,5f5eh
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + SI + 5d5eh]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,DS:[5c5ch]
	PUSH       AX
	MOV        AL,DS:[5c5dh]
	PUSH       AX
	MOV        BX,word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	CALL       F_06a0
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,1h
	JNZ        L_075a
	CMP        word ptr [BP + -2h],3h	; local_4
	JLE        L_075a
	CMP        word ptr [BP + -2h],4h	; local_4
	JZ         L_073d
	CMP        word ptr [BP + -2h],5h	; local_4
	JZ         L_073d
	JMP        L_07be
L_073d:
	MOV        BX,word ptr [BP + -6h]	; local_8
	CMP        word ptr [BX + 0ah],0h
	JZ         L_075a
	MOV        byte ptr DS:[65beh],74h
L_074b:
	MOV        AL,byte ptr [BP + 6h]	; param_2
	MOV        DS:[65bfh],AL
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_092f
	db 90h
L_075a:
	MOV        SI,1h
	MOV        BX,word ptr [BP + -16h]	; local_18
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        word ptr [BP + -1ch],AX	; local_1e
	MOV        AL,byte ptr [BX + 2h]
	MOV        word ptr [BP + -1eh],AX	; local_20
	MOV        DI,BP
	SUB        DI,0eh
	LEA        AX,[BP + -0eh]	; local_10
	MOV        word ptr [BP + -22h],AX	; local_24
L_0779:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AX,word ptr [BX + 2h]
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BX + 4h]
	MOV        DS:[5878h],AX
	PUSH       SI
	CALL       F_0632
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -10h],AX	; local_12
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -12h],AX	; local_14
	PUSH       word ptr DS:[5876h]
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffffh
	PUSH       AX
	CALL       F_0b9e
	OR         AX,AX
	JZ         L_07c6
	PUSH       word ptr [BP + -1eh]	; local_20
	PUSH       word ptr [BP + -1ch]	; local_1e
	PUSH       word ptr [BP + -10h]	; local_12
	PUSH       word ptr [BP + -12h]	; local_14
	CALL       F_06a0
	MOV        word ptr [DI],AX
	JMP        L_07cd
L_07be:
	MOV        byte ptr DS:[65beh],61h
	JMP        L_074b
	db 90h
L_07c6:
	MOV        BX,word ptr [BP + -22h]	; local_24
	MOV        word ptr [BX],63h
L_07cd:
	ADD        DI,2h
	ADD        word ptr [BP + -22h],2h	; local_24
	INC        SI
	CMP        SI,5h
	JL         L_0779
	MOV        word ptr [BP + -14h],SI	; local_16
	MOV        DI,0ffffh
	MOV        BX,word ptr [BP + -16h]	; local_18
	MOV        AL,byte ptr [BX + 2h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 3h]
	PUSH       AX
	MOV        BX,word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	CALL       F_06a0
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        SI,1h
	LEA        AX,[BP + -0eh]	; local_10
	MOV        word ptr [BP + -22h],AX	; local_24
	LEA        AX,[BP + -0eh]	; local_10
	MOV        word ptr [BP + -20h],AX	; local_22
	LEA        AX,[BP + -0eh]	; local_10
	MOV        word ptr [BP + -1eh],AX	; local_20
	LEA        AX,[BP + -16h]	; local_18
	MOV        word ptr [BP + -1ch],AX	; local_1e
L_0817:
	CMP        SI,5h
	JGE        L_0854
	MOV        BX,word ptr [BP + -22h]	; local_24
	CMP        word ptr [BX],63h
	JZ         L_0854
	CMP        word ptr [BP + -2h],3h	; local_4
	JNZ        L_0884
	MOV        AX,word ptr [BP + -4h]	; local_6
	CMP        word ptr [BX],AX
	JLE        L_0854
	CMP        DI,-1h
	JZ         L_0844
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	OR         AX,AX
	JZ         L_0846
L_0844:
	MOV        DI,SI
L_0846:
	CMP        SI,4h
	JNZ        L_0854
L_084b:
	MOV        word ptr [BP + -18h],DI	; local_1a
	MOV        word ptr [BP + -14h],SI	; local_16
	JMP        L_0892
	db 90h
L_0854:
	CMP        SI,4h
	JLE        L_086b
	MOV        BX,word ptr [BP + -1eh]	; local_20
	CMP        word ptr [BX],63h
	JZ         L_086b
	MOV        BX,word ptr [BP + -1ch]	; local_1e
	MOV        AX,word ptr [BP + -4h]	; local_6
	CMP        word ptr [BX],AX
	JZ         L_088e
L_086b:
	ADD        word ptr [BP + -22h],2h	; local_24
	ADD        word ptr [BP + -20h],2h	; local_22
	ADD        word ptr [BP + -1eh],2h	; local_20
	ADD        word ptr [BP + -1ch],2h	; local_1e
	INC        SI
	CMP        SI,8h
	JGE        L_084b
	JMP        L_0817
	db 90h
L_0884:
	MOV        BX,word ptr [BP + -20h]	; local_22
	MOV        AX,word ptr [BP + -4h]	; local_6
	CMP        word ptr [BX],AX
	JGE        L_0854
L_088e:
	MOV        DI,SI
	JMP        L_084b
L_0892:
	CMP        word ptr [BP + -2h],5h	; local_4
	JZ         L_089e
	CMP        word ptr [BP + -2h],7h	; local_4
	JNZ        L_08f1
L_089e:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	CMP        AX,10h
	JGE        L_08f1
	MOV        AX,word ptr [BP + -18h]	; local_1a
	MOV        word ptr [BP + -1ah],AX	; local_1c
	MOV        SI,1h
	MOV        DI,BP
	SUB        DI,0eh
L_08bb:
	CMP        SI,word ptr [BP + -18h]	; local_1a
	JZ         L_08df
	CMP        word ptr [DI],63h
	JZ         L_08df
	MOV        AX,word ptr [BP + -18h]	; local_1a
	CMP        word ptr [BP + -1ah],AX	; local_1c
	JZ         L_08dc
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	CMP        AX,10h
	JGE        L_08df
L_08dc:
	MOV        word ptr [BP + -1ah],SI	; local_1c
L_08df:
	ADD        DI,2h
	INC        SI
	CMP        SI,5h
	JL         L_08bb
	MOV        word ptr [BP + -14h],SI	; local_16
	MOV        AX,word ptr [BP + -1ah]	; local_1c
	MOV        word ptr [BP + -18h],AX	; local_1a
L_08f1:
	CMP        word ptr [BP + -18h],-1h	; local_1a
	JLE        L_092f
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AX,word ptr [BX + 2h]
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BX + 4h]
	MOV        DS:[5878h],AX
	PUSH       word ptr [BP + -18h]	; local_1a
	CALL       F_0632
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        SI,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,DS:[5876h]
	MOV        word ptr [BX + 2h],AX
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AX,DS:[5878h]
	MOV        word ptr [BX + 4h],AX
	MOV        byte ptr [SI + 5c5dh],AL
	OR         byte ptr DS:[24e6h],2h
L_092f:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_06e4 ENDP
F_0938 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        DI,0ffffh
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -0ah],AX	; local_c
	ADD        AX,5f5eh
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AX,word ptr [BP + -0ah]	; local_c
	ADD        AX,5d5eh
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        SI,word ptr [BP + -6h]	; local_8
L_0964:
	MOV        BX,word ptr [BP + -4h]	; local_6
	ADD        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0ch]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_0977
	JMP        L_0a2c
L_0977:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_12e0
	MOV        DI,AX
	CMP        word ptr [SI + 0eh],DI
	JNZ        L_09cc
	MOV        word ptr [SI],1h
L_098b:
	MOV        word ptr [BP + -8h],DI	; local_a
	CMP        DI,-1h
	JLE        L_09be
	MOV        SI,DI
	ADD        SI,word ptr [BP + -2h]	; local_4
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [SI + 3h]
	SUB        AH,AH
	CMP        word ptr [BX + 2h],AX
	JNZ        L_09be
	MOV        AL,byte ptr [SI + 6h]
	CMP        word ptr [BX + 4h],AX
	JNZ        L_09be
	MOV        AL,byte ptr [SI + 9h]
	CMP        word ptr [BX + 6h],AX
	JNZ        L_09be
	MOV        word ptr [BP + -8h],0h	; local_a
	MOV        word ptr [BX],1h
L_09be:
	CMP        word ptr [BP + -8h],-1h	; local_a
	JNZ        L_0a3c
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_0a3f
	db 90h
L_09cc:
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [SI + 6h],AX
	JZ         L_09e4
	MOV        BX,word ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + DI + 9h],AL
	JZ         L_09e4
	MOV        word ptr [SI],8h
	JMP        L_098b
L_09e4:
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [SI + 6h],AX
	JNZ        L_0a14
	MOV        BX,word ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + DI + 9h],AL
	JNZ        L_09fc
	MOV        word ptr [SI],2h
	JMP        L_098b
L_09fc:
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX + DI + 9h],AL
	JLE        L_0a0c
	MOV        word ptr [SI],6h
	JMP        L_098b
	db 90h
	db 90h
L_0a0c:
	MOV        word ptr [SI],7h
	JMP        L_098b
	db 90h
L_0a14:
	MOV        AL,DS:[5895h]
	CMP        byte ptr [SI + 6h],AL
	JLE        L_0a24
	MOV        word ptr [SI],4h
	JMP        L_098b
	db 90h
L_0a24:
	MOV        word ptr [SI],5h
	JMP        L_098b
	db 90h
L_0a2c:
	INC        word ptr [BP + -4h]	; local_6
	CMP        word ptr [BP + -4h],4h	; local_6
	JL         L_0a38
	JMP        L_098b
L_0a38:
	JMP        L_0964
	db 90h
L_0a3c:
	INC        word ptr [BP + -8h]	; local_a
L_0a3f:
	MOV        AX,word ptr [BP + -8h]	; local_a
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0938 ENDP
F_0a4a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,5f5eh
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	MOV        DI,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        DI,CL
	MOV        AL,byte ptr [DI + 5c5ch]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [DI + 5c5dh]
	PUSH       AX
	CALL       SUB_0000_a172 ; 1000:4402h
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        byte ptr [BP + -6h],AL	; local_8
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX + SI + 5d67h],AL
	JGE        L_0aa2
	CMP        byte ptr [BP + -6h],0c9h	; local_8
	JZ         L_0a9b
	MOV        AL,byte ptr [BP + -6h]	; local_8
	AND        AL,0f4h
	CMP        AL,0c4h
	JNZ        L_0acc
L_0a9b:
	MOV        word ptr [BP + -4h],1h	; local_6
	JMP        L_0ad1
L_0aa2:
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        SI,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ch]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 5c5dh]
	PUSH       AX
	CALL       SUB_0000_a172 ; 1000:4402h
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        byte ptr [BP + -6h],AL	; local_8
	CMP        AL,0c8h
	JZ         L_0a9b
	AND        AL,0f4h
	CMP        AL,0c4h
	JZ         L_0a9b
L_0acc:
	MOV        word ptr [BP + -4h],0h	; local_6
L_0ad1:
	MOV        AX,word ptr [BP + -4h]	; local_6
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0a4a ENDP
F_0adc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,5d5eh
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        word ptr [BP + 4h],-1h	; param_1
	JLE        L_0b22
	MOV        SI,word ptr [BP + 4h]	; param_1
	ADD        SI,AX
	MOV        AL,byte ptr [SI + 3h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 0ch]	; param_5
	JNZ        L_0b22
	MOV        AL,byte ptr [SI + 6h]
	CMP        AX,word ptr [BP + 0ah]	; param_4
	JNZ        L_0b22
	MOV        AL,byte ptr [SI + 9h]
	CMP        AX,word ptr [BP + 8h]	; param_3
	JNZ        L_0b22
	MOV        word ptr [BP + -4h],2h	; local_6
	JMP        L_0b94
	db 90h
L_0b22:
	CMP        word ptr [BP + 0ch],0h	; param_5
	JL         L_0b3a
	CMP        word ptr [BP + 0ah],0h	; param_4
	JL         L_0b3a
	CMP        word ptr [BP + 0ch],1fh	; param_5
	JG         L_0b3a
	CMP        word ptr [BP + 0ah],1fh	; param_4
	JLE        L_0b40
L_0b3a:
	MOV        AL,DS:[6a07h]
	JMP        L_0b4e
	db 90h
L_0b40:
	MOV        SI,word ptr [BP + 0ah]	; param_4
	MOV        CL,5h
	SHL        SI,CL
	MOV        BX,word ptr [BP + 0ch]	; param_5
	MOV        AL,byte ptr [BX + SI + 6608h]
L_0b4e:
	MOV        byte ptr [BP + -6h],AL	; local_8
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        BX,CL
	CMP        word ptr [BX + 5f5eh],3h
	JNZ        L_0b6e
	CMP        AL,0c8h
	JZ         L_0b67
	CMP        AL,0c9h
	JNZ        L_0b6e
L_0b67:
	MOV        word ptr [BP + -4h],1h	; local_6
	JMP        L_0b94
L_0b6e:
	MOV        BL,byte ptr [BP + -6h]	; local_8
	SUB        BH,BH
	MOV        CL,3h
	SHR        BX,CL
	MOV        AL,byte ptr [BX + 367eh]
	SUB        AH,AH
	MOV        DX,80h
	MOV        CL,byte ptr [BP + -6h]	; local_8
	AND        CL,7h
	SAR        DX,CL
	AND        AX,DX
	CMP        AX,1h
	SBB        CX,CX
	NEG        CX
	MOV        word ptr [BP + -4h],CX	; local_6
L_0b94:
	MOV        AX,word ptr [BP + -4h]	; local_6
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        0ah
	; Func
F_0adc ENDP
F_0b9e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	MOV        word ptr [BP + -4h],0h	; local_6
	CMP        word ptr [BP + 0ah],0h	; param_4
	JL         L_0bc1
	CMP        word ptr [BP + 0ah],1fh	; param_4
	JG         L_0bc1
	CMP        word ptr [BP + 8h],0h	; param_3
	JL         L_0bc1
	CMP        word ptr [BP + 8h],1fh	; param_3
	JLE        L_0bc6
L_0bc1:
	SUB        AX,AX
	JMP        L_0c4a
L_0bc6:
	PUSH       word ptr [BP + 0ah]	; param_4
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       SUB_0000_a172 ; 1000:4402h
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	AND        AX,0fch
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,word ptr [BP + 6h]	; param_2
	CMP        byte ptr [BX + 659eh],0fch
	JNZ        L_0bec
L_0be5:
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_0c26
L_0bec:
	CMP        word ptr [BP + -6h],30h	; local_8
	JZ         L_0be5
	CMP        word ptr [BP + -6h],90h	; local_8
	JNZ        L_0c0e
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        BX,CL
	CMP        word ptr [BX + 5f5eh],2h
	JZ         L_0c0e
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_0c26
L_0c0e:
	PUSH       word ptr [BP + 0ah]	; param_4
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0adc
	MOV        word ptr [BP + -2h],AX	; local_4
L_0c26:
	PUSH       word ptr [BP + 0ah]	; param_4
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_9472 ; 1000:3702h
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_0c42
	OR         AX,AX
	JZ         L_0c47
L_0c42:
	MOV        word ptr [BP + -2h],0h	; local_4
L_0c47:
	MOV        AX,word ptr [BP + -2h]	; local_4
L_0c4a:
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_0b9e ENDP
F_0c50 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	TEST       AL,8h
	JNZ        L_0c68
	JMP        L_0cf8
L_0c68:
	MOV        AX,40h
	PUSH       AX
	CALL       SUB_0000_981e ; 1000:3AAEh
	MOV        word ptr [BP + -2h],AX	; local_4
	AND        AX,3h
	INC        AX
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,word ptr [BP + 0ch]	; param_5
	MOV        AX,word ptr [BX + 2h]
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BX + 4h]
	MOV        DS:[5878h],AX
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0632
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr [BP + 0ah],0h	; param_4
	JZ         L_0cc0
	MOV        SI,word ptr [BP + 8h]	; param_3
	ADD        SI,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [SI + 3h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 6h]
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       F_06a0
	CMP        AX,word ptr [BP + 0ah]	; param_4
	JG         L_0cf8
L_0cc0:
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       F_0b9e
	OR         AX,AX
	JZ         L_0cf8
	MOV        BX,word ptr [BP + 0ch]	; param_5
	MOV        SI,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BX + 2h],AX
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX + 4h],AX
	MOV        byte ptr [SI + 5c5dh],AL
	OR         byte ptr DS:[24e6h],2h
L_0cf8:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        0ah
	db 90h
	; Func
F_0c50 ENDP
F_0d00 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,5f5eh
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,SI
	ADD        AX,5d5eh
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        DI,AX
	MOV        AL,byte ptr [BX + DI]
	SUB        AH,AH
	CMP        AX,7h
	JA         L_0dac
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0b02ch]
	db 0EBh
	db 75h
	db 90h
	db 0FFh
	db 76h
	db 0FEh
	db 2Bh
	db 0C0h
	db 0EBh
	db 27h
	db 90h
	db 8Bh
	db 76h
	db 04h
	db 03h
	db 76h
	db 0FCh
	db 0A0h
	db 96h
	db 58h
	db 2Ah
	db 0E4h
	db 50h
	db 0A0h
	db 97h
	db 58h
	db 50h
	db 8Ah
	db 44h
	db 03h
	db 50h
	db 8Ah
	db 44h
	db 06h
	db 50h
	db 0E8h
	db 45h
	db 0F9h
	db 3Dh
	db 04h
	db 00h
	db 7Ch
	db 31h
	db 0FFh
	db 76h
	db 0FEh
	db 0B8h
	db 03h
	db 00h
	db 50h
	db 0FFh
	db 76h
	db 04h
	db 0FFh
	db 76h
	db 06h
	db 0FFh
	db 76h
	db 0FCh
	db 0E8h
	db 0DDh
	db 0FEh
	db 0EBh
	db 37h
	db 90h
	db 0A0h
	db 96h
	db 58h
	db 2Ah
	db 0E4h
	db 50h
	db 0A0h
	db 97h
	db 58h
	db 50h
	db 8Bh
	db 5Eh
	db 0FEh
	db 0FFh
	db 77h
	db 02h
	db 0FFh
	db 77h
	db 04h
	db 0E8h
	db 14h
	db 0F9h
	db 3Dh
	db 04h
	db 00h
	db 7Dh
	db 1Bh
	db 0FFh
	db 76h
	db 06h
	db 0FFh
	db 76h
	db 04h
	db 0E8h
	db 4Ah
	db 0F9h
	db 0EBh
	db 10h
	db 3Ch
	db 0B0h
	db 0F0h
	db 0AFh
	db 0C8h
	db 0AFh
	db 06h
	db 0B0h
	db 0D0h
	db 0AFh
	db 21h
	db 0B0h
	db 06h
	db 0B0h
	db 21h
	db 0B0h
L_0dac:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0d00 ENDP
F_0db4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -12h],0h	; local_14
	MOV        byte ptr DS:[65beh],0h
	MOV        byte ptr DS:[65bfh],0h
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_1267
	db 90h
L_0dd4:
	MOV        word ptr [BP + -4h],4h	; local_6
L_0dd9:
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -0ch]	; local_e
	MOV        AL,byte ptr [SI + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 5d64h]
	PUSH       AX
	CMP        word ptr [BP + -4h],3h	; local_6
	JNZ        L_0dfa
	MOV        AX,1h
	JMP        L_0dfc
L_0dfa:
	SUB        AX,AX
L_0dfc:
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_01a0
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JZ         L_0e32
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       AX
	MOV        AL,byte ptr [SI + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 5d64h]
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_032c
	MOV        word ptr [BP + -0eh],AX	; local_10
L_0e32:
	CMP        word ptr [BP + -0eh],0h	; local_10
	JNZ        L_0e3b
	JMP        L_1264
L_0e3b:
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -0ch]	; local_e
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [SI + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 5d64h]
	PUSH       AX
	CALL       F_04ac
	MOV        DI,word ptr [BP + -0ah]	; local_c
	MOV        CL,5h
	SHL        DI,CL
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX + DI + 6608h]
	MOV        byte ptr [BP + -10h],AL	; local_12
	CMP        word ptr [BP + -4h],3h	; local_6
	JNZ        L_0e75
	CMP        AL,0c8h
	JZ         L_0e8a
L_0e75:
	CMP        word ptr [BP + -4h],4h	; local_6
	JNZ        L_0e81
	CMP        byte ptr [BP + -10h],0c9h	; local_12
	JZ         L_0e8a
L_0e81:
	MOV        AL,byte ptr [BP + -10h]	; local_12
	AND        AL,0fch
	CMP        AL,0c4h
	JNZ        L_0e9c
L_0e8a:
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_d89a ; 1000:7B2Ah [THUNK]
L_0e9c:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX],2h
	JMP        L_1264
L_0ea6:
	MOV        SI,word ptr [BX]
	CMP        SI,6h
	JZ         L_0eb2
	CMP        SI,7h
	JNZ        L_0ebf
L_0eb2:
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -0ch]	; local_e
	CALL       F_0a4a
	OR         AX,AX
	JZ         L_0efe
L_0ebf:
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -0ch]	; local_e
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [SI + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 5d64h]
	PUSH       AX
	MOV        AL,byte ptr [SI + 5d67h]
	PUSH       AX
	CALL       SUB_0000_d89a ; 1000:7B2Ah [THUNK]
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AX,word ptr [BP + -0ch]	; local_e
	MOV        word ptr [BX + 0eh],AX
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	MOV        word ptr [BX + 655eh],0ffffh
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX],1h
	JMP        L_1264
L_0efe:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        SI,word ptr [BX]
	CMP        SI,2h
	JNZ        L_0f0b
	JMP        L_1264
L_0f0b:
	CMP        word ptr [BP + -12h],1h	; local_14
	JNZ        L_0f14
	JMP        L_1264
L_0f14:
	MOV        word ptr [BP + -12h],1h	; local_14
	CMP        SI,6h
	JNZ        L_0f26
	MOV        word ptr [BP + -4h],1h	; local_6
	JMP        L_0f2b
	db 90h
L_0f26:
	MOV        word ptr [BP + -4h],2h	; local_6
L_0f2b:
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	CMP        word ptr [BP + -4h],1h	; local_6
	JNZ        L_0f3c
	MOV        AX,1h
	JMP        L_0f3e
L_0f3c:
	SUB        AX,AX
L_0f3e:
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_01a0
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JZ         L_0f71
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        BX,word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_032c
	MOV        word ptr [BP + -0eh],AX	; local_10
L_0f71:
	CMP        word ptr [BP + -0eh],0h	; local_10
	JNZ        L_0f7a
	JMP        L_1264
L_0f7a:
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_04ac
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX],3h
	JMP        L_1264
	db 90h
L_0f94:
	MOV        SI,word ptr [BP + -2h]	; local_4
	SHL        SI,1h
	CMP        word ptr [SI + 655eh],-1h
	JG         L_0fa3
	JMP        L_10e0
L_0fa3:
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        CL,5h
	SHL        DI,CL
	MOV        BX,word ptr [SI + 655eh]
	CMP        byte ptr [BX + DI + 615eh],0h
	JNZ        L_0fb8
	JMP        L_10e0
L_0fb8:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AX,word ptr [BX + 2h]
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BX + 4h]
	MOV        DS:[5878h],AX
	MOV        BX,word ptr [SI + 655eh]
	MOV        AL,byte ptr [BX + DI + 615fh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0632
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	PUSH       word ptr DS:[5876h]
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -0ch]	; local_e
	CALL       F_0b9e
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JNZ        L_0ff9
	JMP        L_109e
L_0ff9:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AX,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -14h],AX	; local_16
	MOV        BX,AX
	MOV        AL,byte ptr [BP + -8h]	; local_a
	MOV        byte ptr [BX + 5c5ch],AL
	SUB        AH,AH
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX + 2h],AX
	MOV        BX,word ptr [BP + -14h]	; local_16
	MOV        AL,byte ptr [BP + -0ah]	; local_c
	MOV        byte ptr [BX + 5c5dh],AL
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX + 4h],AX
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,word ptr [SI + 655eh]
	ADD        AX,DI
	ADD        AX,615eh
	MOV        word ptr [BP + -16h],AX	; local_18
	MOV        BX,AX
	DEC        byte ptr [BX]
	MOV        word ptr [SI + 65c2h],0h
	CMP        byte ptr [BX],0h
	JZ         L_104a
	JMP        L_1264
L_104a:
	INC        word ptr [SI + 655eh]
	MOV        AX,word ptr [SI + 655eh]
	INC        word ptr [SI + 655eh]
	MOV        BX,AX
	MOV        byte ptr [BX + DI + 615eh],0h
	CMP        word ptr [SI + 655eh],20h
	JGE        L_106f
	MOV        BX,word ptr [SI + 655eh]
	CMP        byte ptr [BX + DI + 615eh],1h
	JNC        L_107a
L_106f:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	MOV        word ptr [BX + 655eh],0ffffh
L_107a:
	CMP        word ptr [BP + -0eh],2h	; local_10
	JZ         L_1083
	JMP        L_1264
L_1083:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AX,word ptr [BP + -0ch]	; local_e
	MOV        word ptr [BX + 0eh],AX
	MOV        word ptr [BX],1h
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	MOV        word ptr [BX + 655eh],0ffffh
	JMP        L_1264
L_109e:
	MOV        SI,word ptr [BP + -2h]	; local_4
	SHL        SI,1h
	INC        word ptr [SI + 65c2h]
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        DI,CL
	MOV        AX,DI
	ADD        AX,5f5eh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -0ch]	; local_e
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,DI
	ADD        AX,5d5eh
	PUSH       AX
	CALL       F_0c50
	CMP        word ptr [SI + 65c2h],3h
	JG         L_10d0
	JMP        L_1264
L_10d0:
	MOV        word ptr [SI + 655eh],0ffffh
L_10d6:
	MOV        word ptr [SI + 65c2h],0h
	JMP        L_1264
	db 90h
L_10e0:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	CMP        word ptr [BX + 655eh],-1h
	JNZ        L_1124
	MOV        BX,word ptr [BP + -6h]	; local_8
	CMP        word ptr [BX],3h
	JNZ        L_1124
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_12e0
	MOV        BX,AX
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        SI,CL
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX + SI + 5d67h],AL
	JLE        L_111a
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX],6h
	JMP        L_12d8
	db 90h
L_111a:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BX],7h
	JMP        L_12d8
L_1124:
	CMP        word ptr [BP + -12h],1h	; local_14
	JL         L_112d
	JMP        L_120e
L_112d:
	MOV        BX,word ptr [BP + -6h]	; local_8
	CMP        word ptr [BX],1h
	JNZ        L_1138
	JMP        L_1264
L_1138:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	MOV        SI,word ptr [BX + 65c2h]
	CMP        SI,0c8h
	JL         L_114a
	JMP        L_11e8
L_114a:
	OR         SI,SI
	JZ         L_1160
	SUB        AX,AX
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	CMP        AX,1h
	JZ         L_1160
	JMP        L_11e8
L_1160:
	MOV        SI,word ptr [BP + -2h]	; local_4
	SHL        SI,1h
	CMP        word ptr [SI + 655eh],-1h
	JNZ        L_11c5
	INC        word ptr [BP + -12h]	; local_14
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        DI,CL
	ADD        DI,word ptr [BP + -0ch]	; local_e
	MOV        BX,word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BX + 2h]
	PUSH       word ptr [BX + 4h]
	MOV        AL,byte ptr [DI + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [DI + 5d64h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_032c
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JZ         L_11ba
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AL,byte ptr [DI + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [DI + 5d64h]
	PUSH       AX
	CALL       F_04ac
	MOV        word ptr [BP + -0eh],AX	; local_10
	JMP        L_10d6
	db 90h
L_11ba:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	MOV        word ptr [BX + 65c2h],0c8h
L_11c5:
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,5f5eh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -0ch]	; local_e
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,SI
	ADD        AX,5d5eh
	PUSH       AX
	CALL       F_0c50
	JMP        L_1264
	db 90h
	db 90h
L_11e8:
	MOV        SI,word ptr [BP + -2h]	; local_4
	SHL        SI,1h
	ADD        SI,65c2h
	CMP        word ptr [SI],0c8h
	JL         L_11f9
	INC        word ptr [SI]
L_11f9:
	MOV        SI,word ptr [BP + -2h]	; local_4
	SHL        SI,1h
	ADD        SI,65c2h
	CMP        word ptr [SI],0cch
	JLE        L_1264
	MOV        word ptr [SI],0h
	JMP        L_1264
L_120e:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [BX + 6h],AX
	JNZ        L_1264
	CMP        word ptr [BP + -0ch],1h	; local_e
	JZ         L_1227
	CMP        word ptr [BP + -0ch],2h	; local_e
	JNZ        L_122e
L_1227:
	MOV        word ptr [BP + -0eh],0h	; local_10
	JMP        L_1243
L_122e:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JNZ        L_123c
	MOV        word ptr [BP + -0eh],2h	; local_10
	JMP        L_1243
	db 90h
L_123c:
	MOV        AX,word ptr [BP + -0ch]	; local_e
	DEC        AX
	MOV        word ptr [BP + -0eh],AX	; local_10
L_1243:
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        BX,word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BX + 0eh]
	JMP        L_1261
L_124e:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [BX + 6h],AX
	JNZ        L_1264
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -0ch]	; local_e
L_1261:
	CALL       F_0d00
L_1264:
	INC        word ptr [BP + -2h]	; local_4
L_1267:
	CMP        word ptr [BP + -2h],20h	; local_4
	JGE        L_12d8
	MOV        BX,word ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + 659eh],0h
	JZ         L_1264
	PUSH       BX
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_12e0
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,5f5eh
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,AX
	CMP        word ptr [BX],1h
	JG         L_12a2
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0938
	OR         AX,AX
	JZ         L_124e
L_12a2:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        SI,word ptr [BX]
	CMP        SI,3h
	JG         L_12af
	JMP        L_0f94
L_12af:
	CMP        SI,4h
	JZ         L_12bc
	CMP        SI,5h
	JZ         L_12bc
	JMP        L_0ea6
L_12bc:
	CMP        word ptr [BP + -12h],1h	; local_14
	JZ         L_1264
	MOV        word ptr [BP + -12h],1h	; local_14
	CMP        word ptr [BX],4h
	JZ         L_12cf
	JMP        L_0dd4
L_12cf:
	MOV        word ptr [BP + -4h],3h	; local_6
	JMP        L_0dd9
	db 90h
L_12d8:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0db4 ENDP
F_12e0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	PUSH       DI
	PUSH       DS
	LEA        SI,DS:[5d5eh]
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        AX,CL
	ADD        SI,AX
	ADD        SI,0ch
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        AH,AL
	MOV        BX,AX
	SUB        AL,byte ptr [SI]
	SUB        AH,byte ptr [SI + 1h]
	SUB        BL,byte ptr [SI + 2h]
	SUB        BH,byte ptr [SI + 3h]
	XOR        DX,DX
	CMP        AL,AH
	JBE        L_1311
	MOV        AL,AH
	INC        DX
L_1311:
	CMP        AL,BL
	JBE        L_131a
	MOV        AL,BL
	MOV        DX,2h
L_131a:
	CMP        AL,BH
	JBE        L_1321
	MOV        DX,1h
L_1321:
	MOV        AX,DX
	POP        DS
	POP        DI
	POP        SI
	POP        BP
	RET        4h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
F_12e0 ENDP
_TEXT ENDS
END
