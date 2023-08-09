_TEXT SEGMENT BYTE 'CODE'
ORG 0c232h
SUB_0000_c232:
ORG 9eaeh
SUB_0000_9eae:
ORG 9ec2h
SUB_0000_9ec2:
ORG 9e86h
SUB_0000_9e86:
ORG 0b714h
SUB_0000_b714:
ORG 0ca18h
SUB_0000_ca18:
ORG 0c8b4h
SUB_0000_c8b4:
ORG 0acc6h
SUB_0000_acc6:
ORG 0a39eh
SUB_0000_a39e:
ORG 0dc7ah
SUB_0000_dc7a:
ORG 0cdach
SUB_0000_cdac:
ORG 0d740h
SUB_0000_d740:
ORG 9680h
SUB_0000_9680:
ORG 0c16eh
SUB_0000_c16e:
ORG 0b4beh
SUB_0000_b4be:
ORG 0aa7ch
SUB_0000_aa7c:
ORG 0a49ch
SUB_0000_a49c:
ORG 0a0f0h
SUB_0000_a0f0:
ORG 9946h
SUB_0000_9946:
ORG 0df80h
SUB_0000_df80:
ORG 0b41ch
SUB_0000_b41c:
ORG 0a06ch
SUB_0000_a06c:
ORG 0bd66h
SUB_0000_bd66:
ORG 0b352h
SUB_0000_b352:
ORG 0b532h
SUB_0000_b532:
ORG 0a730h
SUB_0000_a730:
ORG 94eah
SUB_0000_94ea:
ORG 0ca5ah
SUB_0000_ca5a:
ORG 9fc2h
SUB_0000_9fc2:
ORG 0aea2h
SUB_0000_aea2:
ORG 0beb0h
SUB_0000_beb0:
ORG 0a8d8h
SUB_0000_a8d8:
ORG 88a0h
SUB_0000_88a0:
ORG 88d6h
SUB_0000_88d6:
ORG 0a112h
SUB_0000_a112:
ORG 9ef8h
SUB_0000_9ef8:
ORG 0a13eh
SUB_0000_a13e:
ORG 0a918h
SUB_0000_a918:
ORG 0f8a6h
SUB_0000_f8a6:
ORG 0f8d6h
SUB_0000_f8d6:
ORG 0b82ch
SUB_0000_b82c:
ORG 0f8eeh
SUB_0000_f8ee:
ORG 0f912h
SUB_0000_f912:
ORG 0f88eh
SUB_0000_f88e:
ORG 0c6d8h
SUB_0000_c6d8:
ORG 0f89ah
SUB_0000_f89a:
ORG 0afa8h
SUB_0000_afa8:
ORG 0b7fch
SUB_0000_b7fc:
ORG 0f8e2h
SUB_0000_f8e2:
ORG 0b8a4h
SUB_0000_b8a4:
ORG 0f966h
SUB_0000_f966:
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
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]	; param_1
	CMP        byte ptr [BX + 659eh],0eh
	JZ         L_0015
	CMP        byte ptr [BX + 659eh],40h
	JC         L_004a
L_0015:
	MOV        BL,byte ptr DS:[5893h]
	SUB        BH,BH
	SHL        BX,1h
	SHL        BX,1h
	MOV        AX,word ptr [BX + 5b56h]
	MOV        DX,word ptr [BX + 5b58h]
	MOV        CX,1h
	SUB        BX,BX
	MOV        SI,CX
	MOV        CL,byte ptr [BP + 4h]	; param_1
	OR         CL,CL
	JZ         L_003d
L_0035:
	SHL        SI,1h
	RCL        BX,1h
	DEC        CL
	JNZ        L_0035
L_003d:
	AND        AX,SI
	AND        DX,BX
	OR         DX,AX
	JZ         L_004a
	MOV        AX,1h
	JMP        L_004c
L_004a:
	SUB        AX,AX
L_004c:
	POP        SI
	POP        BP
	RET        2h
	db 90h
	; Func
F_0000 ENDP
F_0052 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        word ptr [BP + 4h],0h	; param_1
	JL         L_00a9
	CMP        word ptr [BP + 4h],1fh	; param_1
	JG         L_00a9
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 659eh]
	SUB        AH,AH
	AND        AX,0fch
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,70h
	JZ         L_007d
	CMP        AX,80h
	JL         L_0084
L_007d:
	CMP        word ptr [BP + -2h],0b4h	; local_4
	JNZ        L_00a9
L_0084:
	MOV        BL,byte ptr DS:[5893h]
	SUB        BH,BH
	SHL        BX,1h
	SHL        BX,1h
	MOV        AX,1h
	CWD
	MOV        CL,byte ptr [BP + 4h]	; param_1
	OR         CL,CL
	JZ         L_00a1
L_0099:
	SHL        AX,1h
	RCL        DX,1h
	DEC        CL
	JNZ        L_0099
L_00a1:
	OR         word ptr [BX + 5b56h],AX
	OR         word ptr [BX + 5b58h],DX
L_00a9:
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0052 ENDP
F_00b0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        SI,CL
	MOV        AX,word ptr [SI + 5f6ah]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	MOV        DI,AX
	SUB        AX,AX
	MOV        word ptr [SI + 5f68h],AX
	MOV        word ptr [SI + 5f64h],AX
	MOV        word ptr [SI + 5f62h],AX
	MOV        word ptr [SI + 5f60h],AX
	MOV        word ptr [SI + 5f5eh],AX
	MOV        byte ptr [DI + 7h],AL
	MOV        byte ptr [BX + 6h],AL
	MOV        byte ptr [BX + 4h],AL
	MOV        byte ptr [BX + 3h],AL
	MOV        byte ptr [BX + 2h],AL
	MOV        byte ptr [BX + 1h],AL
	MOV        byte ptr [BX],AL
	SUB        AL,AL
	MOV        byte ptr [SI + 5d60h],AL
	MOV        byte ptr [SI + 5d5fh],AL
	MOV        byte ptr [SI + 5d5eh],AL
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        byte ptr [BX + 659eh],AL
	OR         byte ptr DS:[24e6h],2h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_00b0 ENDP
F_011e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        CX,0ffffh
	SUB        SI,SI
	MOV        DI,5f6ah
	MOV        word ptr [BP + -8h],5f5eh	; local_a
	MOV        DX,word ptr [BP + 4h]	; param_1
L_0136:
	CMP        word ptr [DI],DX
	JNZ        L_0154
	CMP        byte ptr [SI + 659eh],0h
	JZ         L_0154
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        word ptr [BX],0h
	JZ         L_0154
	MOV        CX,SI
L_014b:
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        word ptr [BP + -2h],CX	; local_4
	JMP        L_0164
	db 90h
L_0154:
	ADD        DI,10h
	ADD        word ptr [BP + -8h],10h	; local_a
	INC        SI
	CMP        SI,20h
	JGE        L_014b
	JMP        L_0136
	db 90h
L_0164:
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_011e ENDP
F_0170 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	SUB        DI,DI
L_017a:
	SUB        SI,SI
L_017c:
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],87h
	JNZ        L_0195
	PUSH       DI
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	XOR        byte ptr [BX],0ddh
L_0195:
	INC        SI
	CMP        SI,20h
	JL         L_017c
	MOV        word ptr [BP + -4h],SI	; local_6
	INC        DI
	CMP        DI,20h
	JL         L_017a
	MOV        word ptr [BP + -2h],DI	; local_4
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0feh
	CMP        AL,48h
	JZ         L_0207
	SUB        SI,SI
	JMP        L_01d7
L_01c2:
	MOV        AL,byte ptr [SI + 58eeh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 590eh]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        byte ptr [BX],3h
L_01d6:
	INC        SI
L_01d7:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[594eh]
	SUB        CH,CH
	CMP        AX,CX
	JNC        L_0204
	CMP        byte ptr DS:[587fh],5h
	JNZ        L_01c2
	MOV        AL,byte ptr [SI + 58eeh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 590eh]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [SI + 592eh]
	MOV        byte ptr [BX],AL
	JMP        L_01d6
	db 90h
L_0204:
	MOV        word ptr [BP + -2h],SI	; local_4
L_0207:
	OR         byte ptr DS:[24e6h],2h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0170 ENDP
F_0212 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5958h],0ffh
	JNZ        L_0224
	JMP        L_02a8
L_0224:
	MOV        AL,DS:[587eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_9eae
	MOV        word ptr [BP + -4h],20h	; local_6
	MOV        word ptr [BP + -0ch],0h	; local_e
L_0237:
	SUB        SI,SI
	MOV        DI,word ptr [BP + -0ch]	; local_e
	MOV        word ptr [BP + -8h],DI	; local_a
	MOV        word ptr [BP + -0ah],DI	; local_c
L_0242:
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        AL,byte ptr [BX + SI + 6608h]
	SUB        AH,AH
	CMP        AX,2dh
	JZ         L_0274
	CMP        AX,2eh
	JNZ        L_026b
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_026b
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        byte ptr [BX + SI + 6608h],2bh
L_026b:
	INC        SI
	CMP        SI,20h
	JGE        L_028e
	JMP        L_0242
	db 90h
L_0274:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_026b
	MOV        BX,DI
	ADD        BX,SI
	MOV        byte ptr [BX + 6608h],2ch
	JMP        L_026b
	db 90h
L_028e:
	MOV        word ptr [BP + -2h],SI	; local_4
	ADD        word ptr [BP + -0ch],20h	; local_e
	CMP        word ptr [BP + -0ch],400h	; local_e
	JL         L_0237
	OR         byte ptr DS:[24e6h],2h
	CALL       SUB_0000_9e86
	PUSH       AX
	CALL       SUB_0000_9eae
L_02a8:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0212 ENDP
F_02ae PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        byte ptr DS:[5958h],0ffh
	CMP        byte ptr DS:[5897h],4h
	JZ         L_02dd
	SUB        SI,SI
	MOV        DL,byte ptr DS:[5893h]
	MOV        CL,byte ptr DS:[5958h]
L_02cc:
	CMP        byte ptr [SI + 58c8h],DL
	JNZ        L_0300
	MOV        AX,SI
	MOV        CL,AL
L_02d6:
	MOV        word ptr [BP + -6h],SI	; local_8
	MOV        byte ptr DS:[5958h],CL
L_02dd:
	CMP        byte ptr DS:[5958h],0ffh
	JNZ        L_02e7
	JMP        L_0401
L_02e7:
	CALL       F_0212
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        SI,5c5ah
	MOV        CX,word ptr [BP + -6h]	; local_8
L_02f5:
	CMP        byte ptr [SI],0fch
	JNZ        L_0308
	MOV        word ptr [BP + -6h],CX	; local_8
	JMP        L_0401
L_0300:
	INC        SI
	CMP        SI,3h
	JGE        L_02d6
	JMP        L_02cc
L_0308:
	ADD        SI,8h
	INC        CX
	CMP        CX,20h
	JL         L_02f5
	MOV        word ptr [BP + -6h],CX	; local_8
	CALL       SUB_0000_b714
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        word ptr [BP + -2h],1fh	; local_4
	MOV        SI,1fh
	MOV        CX,word ptr [BP + -2h]	; local_4
L_032f:
	CMP        byte ptr [SI + 659eh],0h
	JNZ        L_0340
	MOV        CX,SI
L_0338:
	MOV        word ptr [BP + -6h],SI	; local_8
	MOV        word ptr [BP + -2h],CX	; local_4
	JMP        L_0346
L_0340:
	DEC        SI
	JS         L_0338
	JMP        L_032f
	db 90h
L_0346:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        BX,AX
	MOV        word ptr [BX + 5f5eh],1h
	MOV        AX,word ptr [BP + -8h]	; local_a
	MOV        word ptr [BX + 5f6ah],AX
	MOV        SI,word ptr [BP + -4h]	; local_6
	MOV        AL,0fh
	MOV        byte ptr [SI + 2h],AL
	SUB        AH,AH
	MOV        word ptr [BX + 5f60h],AX
	MOV        BX,SI
	MOV        SI,word ptr DS:[5893h]
	AND        SI,0ffh
	MOV        AL,byte ptr [SI + 13a5h]
	MOV        byte ptr [BX + 3h],AL
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        word ptr [BX + 5f62h],AX
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        SI,BX
	SUB        AL,AL
	MOV        byte ptr [SI + 7h],AL
	MOV        byte ptr [BX + 4h],AL
	MOV        byte ptr [BX + 5h],AL
	MOV        byte ptr [BX + 6h],AL
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        word ptr [BX + 5f64h],AX
	MOV        BX,SI
	MOV        AL,0fch
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        AX,word ptr [BP + -0eh]	; local_10
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        BX,AX
	SUB        AX,AX
	MOV        CX,2h
	LEA        DI,[BX + 5d6ah]
	PUSH       DS
	POP        ES
	REP STOSW
	ADD        word ptr [BP + -6h],4h	; local_8
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        CL,4h
	SHL        DI,CL
	MOV        DX,SI
	MOV        CX,AX
L_03d4:
	MOV        SI,DI
	ADD        SI,CX
	MOV        byte ptr [SI + 5d5eh],6h
	MOV        byte ptr [SI + 5d61h],0fh
	MOV        BX,DX
	MOV        AL,byte ptr [BX + 3h]
	MOV        byte ptr [SI + 5d64h],AL
	MOV        byte ptr [SI + 5d67h],0h
	INC        CX
	CMP        CX,3h
	JL         L_03d4
	MOV        word ptr [BP + -6h],CX	; local_8
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        byte ptr [BX + 659eh],0fch
L_0401:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_02ae ENDP
F_0408 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_ca18
	CALL       SUB_0000_c8b4
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_acc6
	MOV        byte ptr DS:[594fh],0h
	SUB        AL,AL
	MOV        DS:[589ch],AL
	MOV        DS:[589bh],AL
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	MOV        SI,AX
	LEA        BX,[SI + -1h]
	MOV        CL,3h
	SHR        BX,CL
	SHL        BX,1h
	MOV        AX,word ptr [BX + 2652h]
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,byte ptr [SI + 1e19h]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[5895h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        CL,7fh
	JBE        L_045c
	SUB        word ptr [BP + -6h],100h	; local_8
L_045c:
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,6608h
	PUSH       AX
	MOV        AX,400h
	PUSH       AX
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        CL,0ah
	SHL        AX,CL
	PUSH       AX
	CALL       SUB_0000_a39e
	MOV        byte ptr DS:[594eh],0h
	MOV        AX,0ffffh
	MOV        DS:[2184h],AX
	MOV        DS:[2182h],AX
	MOV        DS:[2180h],AX
	MOV        DS:[217eh],AX
	SUB        DI,DI
L_0488:
	SUB        SI,SI
L_048a:
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0feh
	CMP        AL,48h
	JNZ        L_04c3
	MOV        AL,DS:[594eh]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        BX,AX
	MOV        AX,DI
	MOV        byte ptr [BX + 58eeh],AL
	MOV        AX,SI
	MOV        byte ptr [BX + 590eh],AL
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        byte ptr [BX + 592eh],AL
	INC        byte ptr DS:[594eh]
L_04c3:
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],2ah
	JNZ        L_04e8
	CMP        word ptr DS:[217eh],-1h
	JNZ        L_04e0
	MOV        word ptr DS:[217eh],DI
	MOV        word ptr DS:[2180h],SI
	JMP        L_04e8
L_04e0:
	MOV        word ptr DS:[2182h],DI
	MOV        word ptr DS:[2184h],SI
L_04e8:
	INC        SI
	CMP        SI,20h
	JL         L_048a
	MOV        word ptr [BP + -8h],SI	; local_a
	INC        DI
	CMP        DI,20h
	JL         L_0488
	MOV        word ptr [BP + -4h],DI	; local_6
	CMP        byte ptr DS:[587fh],5h
	JC         L_0508
	CMP        byte ptr DS:[587fh],13h
	JBE        L_050b
L_0508:
	CALL       F_0170
L_050b:
	CALL       SUB_0000_dc7a
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_cdac
	CALL       F_0212
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0520
	CALL       F_1694
L_0520:
	MOV        byte ptr DS:[24e6h],1h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0408 ENDP
F_052e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 4h]	; param_1
	AND        AL,0fch
	CMP        AL,0c4h
	JNZ        L_0577
	CALL       SUB_0000_d740
	MOV        AX,word ptr [BP + 4h]	; param_1
	SUB        AX,0c4h
	CMP        AX,word ptr [BP + 6h]	; param_2
	JNZ        L_0556
	INC        byte ptr DS:[5895h]
	MOV        AX,265ah
L_054f:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0570
	db 90h
L_0556:
	MOV        AX,word ptr [BP + 4h]	; param_1
	SUB        AX,0c4h
	MOV        CX,word ptr [BP + 6h]	; param_2
	XOR        CL,2h
	CMP        AX,CX
	JNZ        L_0577
	DEC        byte ptr DS:[5895h]
	MOV        AX,265fh
	JMP        L_054f
	db 90h
L_0570:
	MOV        AX,1h
	PUSH       AX
	CALL       F_0408
L_0577:
	POP        BP
	RET        4h
	db 90h
	; Func
F_052e ENDP
F_057c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	AND        AX,0fch
	CMP        AX,10h
	JZ         L_05a2
	CMP        AX,14h
	JZ         L_05c4
	CMP        AX,20h
	JZ         L_05ed
	CMP        AX,24h
	JZ         L_05ed
	CMP        AX,28h
	JZ         L_05e6
	JMP        L_05fc
L_05a2:
	MOV        AX,2666h
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_05b6
	MOV        byte ptr DS:[587ch],12h
	JMP        L_05fc
L_05b6:
	CMP        word ptr [BP + 4h],3h	; param_1
	JNZ        L_05fc
	MOV        byte ptr DS:[587ch],13h
	JMP        L_05fc
	db 90h
L_05c4:
	MOV        AX,266ch
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_05d8
	MOV        byte ptr DS:[587ch],14h
	JMP        L_05fc
L_05d8:
	CMP        word ptr [BP + 4h],3h	; param_1
	JNZ        L_05fc
	MOV        byte ptr DS:[587ch],15h
	JMP        L_05fc
	db 90h
L_05e6:
	MOV        AX,2671h
	PUSH       AX
	CALL       SUB_0000_9680
L_05ed:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        CL,byte ptr DS:[587ch]
	AND        CL,0fch
	ADD        AL,CL
	MOV        DS:[587ch],AL
L_05fc:
	POP        BP
	RET        2h
	; Func
F_057c ENDP
F_0600 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       SI
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_0617
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,12h
	JNZ        L_061a
L_0617:
	CALL       SUB_0000_c16e
L_061a:
	SUB        AX,AX
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AX,word ptr [BP + 4h]	; param_1
	CMP        AX,1h
	JNZ        L_0630
	JMP        L_073c
L_0630:
	CMP        AX,2h
	JNZ        L_0638
	JMP        L_071a
L_0638:
	CMP        AX,3h
	JZ         L_0648
	CMP        AX,4h
	JNZ        L_0645
	JMP        L_06f8
L_0645:
	JMP        L_0669
	db 90h
L_0648:
	DEC        word ptr [BP + -0ch]	; local_e
	CMP        byte ptr DS:[5897h],1h
	JNC        L_0657
	MOV        word ptr [BP + -6h],1h	; local_8
L_0657:
	MOV        word ptr [BP + 4h],0h	; param_1
	SUB        AX,AX
	PUSH       AX
	CALL       F_057c
	MOV        AX,2676h
L_0665:
	PUSH       AX
	CALL       SUB_0000_9680
L_0669:
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        SI,word ptr [BP + -0ch]	; local_e
	MOV        CL,5h
	SHL        SI,CL
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        AL,byte ptr [BX + SI + 0aba7h]
	SUB        AH,AH
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        AX,BX
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	PUSH       AX
	MOV        AX,word ptr [BP + -0ch]	; local_e
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b4be
	MOV        word ptr [BP + -8h],AX	; local_a
	OR         AX,AX
	JNZ        L_06a9
	JMP        L_0776
L_06a9:
	MOV        word ptr [BP + -4h],0h	; local_6
	CMP        byte ptr DS:[587ch],30h
	JNC        L_06bf
	CMP        byte ptr DS:[587ch],20h
	JC         L_06bf
	JMP        L_075e
L_06bf:
	CMP        word ptr [BP + -8h],24h	; local_a
	JL         L_06ce
	CMP        word ptr [BP + -8h],2ch	; local_a
	JGE        L_06ce
	JMP        L_0771
L_06ce:
	CMP        word ptr [BP + -8h],1bh	; local_a
	JNZ        L_06d7
	JMP        L_0771
L_06d7:
	MOV        AL,byte ptr [BP + -8h]	; local_a
	AND        AL,0feh
	CMP        AL,10h
	JNZ        L_06e3
	JMP        L_0771
L_06e3:
	CMP        word ptr [BP + -8h],1eh	; local_a
	JNZ        L_06ec
	JMP        L_0771
L_06ec:
	CMP        word ptr [BP + -8h],1fh	; local_a
	JZ         L_06f5
	JMP        L_0776
L_06f5:
	JMP        L_0771
	db 90h
L_06f8:
	INC        word ptr [BP + -0ch]	; local_e
	CMP        byte ptr DS:[5897h],1eh
	JBE        L_0707
	MOV        word ptr [BP + -6h],1h	; local_8
L_0707:
	MOV        word ptr [BP + 4h],2h	; param_1
	MOV        AX,2h
	PUSH       AX
	CALL       F_057c
	MOV        AX,267dh
	JMP        L_0665
	db 90h
L_071a:
	INC        word ptr [BP + -0ah]	; local_c
	CMP        byte ptr DS:[5896h],1eh
	JBE        L_0729
	MOV        word ptr [BP + -6h],1h	; local_8
L_0729:
	MOV        word ptr [BP + 4h],1h	; param_1
	MOV        AX,1h
	PUSH       AX
	CALL       F_057c
	MOV        AX,2684h
	JMP        L_0665
	db 90h
L_073c:
	DEC        word ptr [BP + -0ah]	; local_c
	CMP        byte ptr DS:[5896h],1h
	JNC        L_074b
	MOV        word ptr [BP + -6h],1h	; local_8
L_074b:
	MOV        word ptr [BP + 4h],3h	; param_1
	MOV        AX,3h
	PUSH       AX
	CALL       F_057c
	MOV        AX,268ah
	JMP        L_0665
	db 90h
L_075e:
	CMP        byte ptr DS:[587ch],28h
	JC         L_0776
	CMP        word ptr [BP + -8h],24h	; local_a
	JL         L_0776
	CMP        word ptr [BP + -8h],28h	; local_a
	JGE        L_0776
L_0771:
	MOV        word ptr [BP + -4h],1h	; local_6
L_0776:
	CMP        word ptr [BP + -4h],0h	; local_6
	JNZ        L_077f
	JMP        L_083a
L_077f:
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -0eh]	; local_10
	CALL       SUB_0000_aa7c
	OR         AX,AX
	JNZ        L_0792
	JMP        L_083a
L_0792:
	CMP        word ptr [BP + -6h],0h	; local_8
	JZ         L_0810
	MOV        AX,2690h
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_07ac
	db 90h
L_07a2:
	CMP        AX,4eh
	JZ         L_07b6
	CMP        SI,1bh
	JZ         L_07b6
L_07ac:
	CALL       SUB_0000_a49c
	MOV        SI,AX
	CMP        AX,59h
	JNZ        L_07a2
L_07b6:
	MOV        word ptr [BP + -2h],SI	; local_4
	CMP        SI,59h
	JNZ        L_0806
	MOV        AX,26abh
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        byte ptr DS:[5893h],19h
	JNZ        L_07da
	MOV        AX,26b9h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        byte ptr DS:[5895h],0ffh
	JMP        L_07e6
L_07da:
	MOV        AX,26c6h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        byte ptr DS:[5895h],0h
L_07e6:
	MOV        byte ptr DS:[594fh],0h
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,byte ptr [SI + 1e89h]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [SI + 1eb1h]
	MOV        DS:[5897h],AL
	MOV        byte ptr DS:[5893h],AH
	JMP        L_0854
L_0806:
	MOV        AX,26d2h
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_084f
	db 90h
L_0810:
	MOV        AL,byte ptr [BP + -0ah]	; local_c
	ADD        byte ptr DS:[5896h],AL
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	ADD        byte ptr DS:[5897h],AL
	MOV        byte ptr DS:[24e6h],1h
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,12h
	JNZ        L_082f
	CALL       SUB_0000_c16e
L_082f:
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -0eh]	; local_10
	CALL       F_052e
	JMP        L_0854
L_083a:
	MOV        AX,26d6h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,0a5h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	CALL       SUB_0000_a0f0
	CALL       SUB_0000_9946
L_084f:
	MOV        word ptr [BP + -6h],0h	; local_8
L_0854:
	MOV        AX,word ptr [BP + -6h]	; local_8
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0600 ENDP
F_085e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	MOV        BX,word ptr [BP + 4h]	; param_1
	CMP        byte ptr [BX + 659eh],2fh
	JC         L_0876
	MOV        word ptr [BP + -2h],7h	; local_4
	JMP        L_087b
L_0876:
	MOV        word ptr [BP + -2h],6h	; local_4
L_087b:
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        AX,BX
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,AX
	SUB        AX,AX
	MOV        CX,2h
	LEA        DI,[BX + 5d6ah]
	PUSH       DS
	POP        ES
	REP STOSW
	ADD        word ptr [BP + -4h],4h	; local_6
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AH,byte ptr [BP + -0ah]	; local_c
	SUB        AL,AL
	MOV        CL,AH
	SUB        CH,CH
	ADD        AX,CX
	MOV        CX,1h
	LEA        DI,[BX + 5d5eh]
	REP STOSW
	STOSB
	ADD        word ptr [BP + -4h],3h	; local_6
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_085e ENDP
F_08d4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	SUB        DX,DX
	MOV        word ptr [BP + -6h],DX	; local_8
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        SI,CL
	MOV        CX,DX
L_08ea:
	MOV        BX,CX
	CMP        byte ptr [BX + SI + 5d6ah],0h
	JZ         L_08f6
	MOV        DX,1h
L_08f6:
	INC        CX
	CMP        CX,4h
	JL         L_08ea
	MOV        word ptr [BP + -4h],DX	; local_6
	MOV        word ptr [BP + -6h],CX	; local_8
	MOV        BX,word ptr [BP + 4h]	; param_1
	CMP        byte ptr [BX + 659eh],74h
	JNC        L_0950
	CMP        byte ptr [BX + 659eh],40h
	JC         L_0950
	MOV        CL,4h
	SHL        BX,CL
	CMP        word ptr [BX + 5f68h],0feh
	JZ         L_0923
	OR         DX,DX
	JZ         L_0950
L_0923:
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        BX,AX
	MOV        word ptr [BX + 5f68h],0fdh
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,303h
	MOV        CX,1h
	LEA        DI,[BX + 5d5eh]
	PUSH       DS
	POP        ES
	REP STOSW
	STOSB
	ADD        word ptr [BP + -6h],3h	; local_8
L_0950:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_08d4 ENDP
F_0958 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
	MOV        word ptr [BP + -6h],5f5eh	; local_8
	MOV        DI,word ptr [BP + -4h]	; local_6
L_096a:
	MOV        BX,word ptr [BP + -6h]	; local_8
	CMP        word ptr [BX],0h
	JZ         L_09a5
	MOV        AL,byte ptr [SI + 659eh]
	SUB        AH,AH
	MOV        DI,AX
	CMP        DI,0fch
	JZ         L_098b
	CMP        DI,0d8h
	JZ         L_098b
	CMP        DI,70h
	JNZ        L_0992
L_098b:
	PUSH       SI
	CALL       F_085e
	JMP        L_09a5
	db 90h
L_0992:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,80h
	JGE        L_09a5
	PUSH       SI
	CALL       F_08d4
L_09a5:
	ADD        word ptr [BP + -6h],10h	; local_8
	INC        SI
	CMP        SI,20h
	JL         L_096a
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0958 ENDP
F_09bc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0052
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        BX,CL
	PUSH       word ptr [BX + 5f6ah]
	CALL       SUB_0000_df80
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_00b0
	SUB        AX,AX
	PUSH       AX
	CALL       F_0408
	CALL       F_02ae
	POP        BP
	RET        2h
	; Func
F_09bc ENDP
F_09e6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       SI
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        AX,26e0h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],4h
	JNC        L_0a24
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_0a24
	MOV        AX,26e8h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -4h],0h	; local_6
	JMP        L_0b79
	db 90h
L_0a24:
	CALL       SUB_0000_b41c
	OR         AX,AX
	JNZ        L_0a2e
	JMP        L_0b79
L_0a2e:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],9dh
	JNZ        L_0a8e
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        byte ptr [BX],9fh
	MOV        AX,26f2h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        SI,7d0h
L_0a6c:
	MOV        AX,28h
	PUSH       AX
	MOV        AX,78h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_a06c
	ADD        SI,3e8h
	CMP        SI,4e20h
	JL         L_0a6c
	MOV        word ptr [BP + -0ch],SI	; local_e
	OR         byte ptr DS:[24e6h],2h
	JMP        L_0b79
	db 90h
L_0a8e:
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b4be
	MOV        word ptr [BP + -10h],AX	; local_12
	MOV        word ptr [BP + -6h],1h	; local_8
	OR         AX,AX
	JZ         L_0ad8
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -0eh],AX	; local_10
	PUSH       AX
	CALL       F_011e
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        word ptr [BP + -10h],40h	; local_12
	JL         L_0ad8
	CMP        word ptr [BP + -10h],0e8h	; local_12
	JL         L_0aca
	CMP        word ptr [BP + -10h],0f0h	; local_12
	JL         L_0ad8
L_0aca:
	MOV        AL,byte ptr [BP + -10h]	; local_12
	AND        AL,0fch
	CMP        AL,0b4h
	JZ         L_0ad8
	MOV        word ptr [BP + -6h],0h	; local_8
L_0ad8:
	CMP        word ptr [BP + -6h],0h	; local_8
	JZ         L_0ae8
	MOV        AX,26fbh
L_0ae1:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0b79
L_0ae8:
	CMP        word ptr [BP + -10h],80h	; local_12
	JGE        L_0afc
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_bd66
	JMP        L_0b05
L_0afc:
	MOV        AL,byte ptr [BP + -10h]	; local_12
	AND        AL,0fch
	CMP        AL,0d8h
	JNZ        L_0b08
L_0b05:
	CALL       F_0958
L_0b08:
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,84h
	JC         L_0b2b
	CMP        AX,85h
	JBE        L_0b40
	CMP        AX,9fh
	JZ         L_0b40
	CMP        AX,0abh
	JZ         L_0b40
L_0b2b:
	CMP        word ptr [BP + -2h],0h	; local_4
	JL         L_0b79
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0052
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_09bc
	JMP        L_0b79
	db 90h
L_0b40:
	CMP        word ptr [BP + -10h],78h	; local_12
	JNZ        L_0b4c
	MOV        AX,270fh
	JMP        L_0ae1
	db 90h
L_0b4c:
	MOV        AX,2718h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_bd66
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_b352
	CMP        word ptr [BP + -2h],0h	; local_4
	JL         L_0b79
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0052
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_00b0
L_0b79:
	MOV        AX,word ptr [BP + -4h]	; local_6
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_09e6 ENDP
F_0b82 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AX,2723h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,12h
	JNZ        L_0ba8
	MOV        AX,272ah
L_0ba0:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0c43
	db 90h
L_0ba8:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,86h
	JZ         L_0c32
	CMP        AX,0c8h
	JZ         L_0bce
	CMP        AX,0c9h
	JZ         L_0c32
	JMP        L_0bdd
	db 90h
	db 90h
L_0bce:
	SUB        AX,AX
L_0bd0:
	PUSH       AX
	MOV        AX,0c4h
	PUSH       AX
	CALL       F_052e
	MOV        word ptr [BP + -2h],1h	; local_4
L_0bdd:
	CMP        word ptr [BP + -2h],0h	; local_4
	JNZ        L_0c43
	CALL       SUB_0000_b41c
	OR         AX,AX
	JZ         L_0c3e
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	PUSH       AX
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,4ch
	JZ         L_0c19
	CMP        AX,0cah
	JZ         L_0c19
	CMP        AX,0cbh
	JNZ        L_0c38
L_0c19:
	MOV        AL,DS:[5876h]
	ADD        byte ptr DS:[5896h],AL
	MOV        AL,DS:[5878h]
	ADD        byte ptr DS:[5897h],AL
	MOV        byte ptr DS:[24e6h],1h
	CALL       SUB_0000_d740
	JMP        L_0c3e
	db 90h
L_0c32:
	MOV        AX,2h
	JMP        L_0bd0
	db 90h
L_0c38:
	MOV        AX,2735h
	JMP        L_0ba0
L_0c3e:
	MOV        word ptr [BP + -2h],1h	; local_4
L_0c43:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0b82 ENDP
F_0c4a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],0a2h
	JZ         L_0c6d
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],43h
	JNZ        L_0c72
L_0c6d:
	MOV        AX,1h
	JMP        L_0c74
L_0c72:
	SUB        AX,AX
L_0c74:
	POP        BP
	RET        4h
	; Func
F_0c4a ENDP
F_0c78 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h	; local_a
	MOV        word ptr [BP + -0eh],5c5ah	; local_10
	MOV        DI,word ptr [BP + -4h]	; local_6
	MOV        SI,word ptr [BP + -6h]	; local_8
L_0c90:
	MOV        AX,word ptr [BP + -0eh]	; local_10
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	AND        AL,0feh
	CMP        AL,10h
	JZ         L_0cab
	JMP        L_0da7
L_0cab:
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX + 4h],AL
	JZ         L_0cb6
	JMP        L_0da7
L_0cb6:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_0cc7
	JMP        L_0da7
L_0cc7:
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 2h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,byte ptr [BX + 3h]
	MOV        SI,AX
	PUSH       DI
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       F_0c4a
	OR         AX,AX
	JZ         L_0ce5
	JMP        L_0da7
L_0ce5:
	LEA        AX,[DI + 1h]
	PUSH       AX
	PUSH       SI
	CALL       F_0c4a
	OR         AX,AX
	JZ         L_0cf4
	JMP        L_0da7
L_0cf4:
	PUSH       DI
	LEA        AX,[SI + -1h]
	PUSH       AX
	CALL       F_0c4a
	OR         AX,AX
	JZ         L_0d03
	JMP        L_0da7
L_0d03:
	LEA        AX,[DI + -1h]
	PUSH       AX
	PUSH       SI
	CALL       F_0c4a
	OR         AX,AX
	JZ         L_0d12
	JMP        L_0da7
L_0d12:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_0d46
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	SHL        AX,1h
	DEC        AX
	MOV        word ptr [BP + -0ah],AX	; local_c
	ADD        DI,AX
	OR         AX,AX
	JLE        L_0d3e
	MOV        word ptr [BP + -0ch],10h	; local_e
	JMP        L_0d55
	db 90h
L_0d3e:
	MOV        word ptr [BP + -0ch],11h	; local_e
	JMP        L_0d55
	db 90h
L_0d46:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	SHL        AX,1h
	DEC        AX
	ADD        SI,AX
L_0d55:
	CMP        DI,1fh
	JG         L_0da7
	CMP        SI,1fh
	JG         L_0da7
	OR         DI,DI
	JL         L_0da7
	OR         SI,SI
	JL         L_0da7
	MOV        AX,10h
	PUSH       AX
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_aa7c
	OR         AX,AX
	JZ         L_0da7
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b532
	OR         AX,AX
	JNZ        L_0da7
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	MOV        byte ptr [BX + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        AX,DI
	MOV        byte ptr [BX + 2h],AL
	MOV        AX,SI
	MOV        byte ptr [BX + 3h],AL
	OR         byte ptr DS:[24e6h],2h
L_0da7:
	ADD        word ptr [BP + -0eh],8h	; local_10
	INC        word ptr [BP + -8h]	; local_a
	CMP        word ptr [BP + -8h],20h	; local_a
	JGE        L_0db7
	JMP        L_0c90
L_0db7:
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -6h],SI	; local_8
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0c78 ENDP
F_0dc4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0dec
	CALL       SUB_0000_d740
	CMP        byte ptr DS:[0a9fah],0h
	JZ         L_0de2
	CALL       SUB_0000_a730
	MOV        byte ptr DS:[0a9fah],0h
L_0de2:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CALL       SUB_0000_ca5a
L_0dec:
	CALL       SUB_0000_a49c
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        byte ptr DS:[5957h],0h
	JZ         L_0e2a
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_0e2a
	CALL       F_0958
	DEC        byte ptr DS:[5957h]
	MOV        AX,273ch
	PUSH       AX
	CALL       SUB_0000_9680
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 2742h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
L_0e2a:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0dc4 ENDP
F_0e34 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        word ptr [BP + -2h],3h	; local_4
	CMP        byte ptr DS:[0abc7h],8dh
	JZ         L_0e49
	JMP        L_0ef0
L_0e49:
	SUB        word ptr [BP + 4h],30h	; param_1
	CMP        byte ptr DS:[0a9ceh],0h
	JZ         L_0e70
	MOV        BX,word ptr [BP + 4h]	; param_1
	SHL        BX,1h
	PUSH       word ptr [BX + 2746h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0fa0h
	PUSH       AX
	MOV        AX,4e20h
	PUSH       AX
	MOV        AX,0fffch
	PUSH       AX
	CALL       SUB_0000_9fc2
L_0e70:
	MOV        BL,byte ptr DS:[2767h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 275ah]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 4h]	; param_1
	JNZ        L_0eae
	INC        byte ptr DS:[2767h]
	CMP        byte ptr DS:[2767h],0dh
	JNZ        L_0ef9
	MOV        byte ptr DS:[2767h],AH
	CMP        byte ptr DS:[5893h],11h
	JNZ        L_0ef9
	CMP        byte ptr DS:[5895h],2h
	JNZ        L_0ef9
	XOR        byte ptr DS:[67b9h],0bh
	CALL       SUB_0000_aea2
	MOV        byte ptr DS:[24e6h],1h
	JMP        L_0ef9
	db 90h
L_0eae:
	CMP        byte ptr DS:[2767h],0ah
	JNZ        L_0ec2
	CMP        word ptr [BP + 4h],8h	; param_1
	JNZ        L_0ec2
	MOV        byte ptr DS:[2767h],3h
	JMP        L_0ef9
L_0ec2:
	CMP        byte ptr DS:[2767h],0bh
	JNZ        L_0ed6
	CMP        word ptr [BP + 4h],7h	; param_1
	JNZ        L_0ed6
	MOV        byte ptr DS:[2767h],2h
	JMP        L_0ef9
L_0ed6:
	MOV        AL,DS:[275ah]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX	; param_1
	JNZ        L_0ee8
	MOV        byte ptr DS:[2767h],1h
	JMP        L_0ef9
	db 90h
L_0ee8:
	MOV        byte ptr DS:[2767h],0h
	JMP        L_0ef9
	db 90h
L_0ef0:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_beb0
	MOV        word ptr [BP + -2h],AX	; local_4
L_0ef9:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0e34 ENDP
F_0f02 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0f48
	MOV        SI,55b3h
	MOV        DI,word ptr [BP + -4h]	; local_6
L_0f1e:
	CMP        byte ptr [SI],53h
	JNZ        L_0f35
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,0fh
	JNZ        L_0f35
	MOV        byte ptr [SI],47h
L_0f35:
	ADD        SI,20h
	INC        DI
	MOV        AX,DI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_0f1e
	MOV        word ptr [BP + -4h],DI	; local_6
L_0f48:
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,8ch
	JZ         L_0f6b
	JMP        L_1050
L_0f6b:
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,14h
	JNZ        L_0f77
	JMP        L_1050
L_0f77:
	MOV        AX,2768h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        byte ptr DS:[587ch],AH
	CALL       SUB_0000_d740
	CALL       SUB_0000_a8d8
	MOV        AL,byte ptr [BP + -6h]	; local_8
	MOV        DS:[587ch],AL
	CMP        byte ptr DS:[5893h],1dh
	JZ         L_0fa0
	JMP        L_103c
L_0fa0:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_88a0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_88d6
	MOV        word ptr [BP + -4h],3e8h	; local_6
L_0fb8:
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_a112
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_9ef8
	DEC        word ptr [BP + -4h]	; local_6
	CMP        word ptr [BP + -4h],0fah	; local_6
	JG         L_0fb8
	CALL       SUB_0000_a13e
	MOV        CX,400h
	MOV        DI,6608h
	MOV        AX,DS
	MOV        ES,AX
	MOV        AX,8fh
	REP STOSB
	MOV        byte ptr DS:[24e6h],1h
	MOV        CX,100h
	MOV        DI,5c5ah
	MOV        AX,DS
	SUB        AX,AX
	REP STOSB
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JNZ        L_1005
	JMP        L_10c7
L_1005:
	MOV        SI,55b8h
	MOV        DI,55b3h
L_100b:
	MOV        word ptr [SI],0h
	MOV        byte ptr [DI],44h
	MOV        AX,28h
	PUSH       AX
	MOV        AX,0bb8h
	PUSH       AX
	MOV        AX,1f4h
	PUSH       AX
	CALL       SUB_0000_a06c
	CALL       SUB_0000_a730
	ADD        SI,20h
	ADD        DI,20h
	INC        word ptr [BP + -4h]	; local_6
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -4h],AX	; local_6
	JC         L_103a
	JMP        L_10c7
L_103a:
	JMP        L_100b
L_103c:
	DEC        byte ptr DS:[5895h]
	MOV        AX,1h
	PUSH       AX
	CALL       F_0408
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_10c7
	db 90h
	db 90h
L_1050:
	CMP        word ptr [BP + -8h],4h	; local_a
	JNZ        L_10ac
	CMP        byte ptr DS:[587ch],1ch
	JNZ        L_10ac
	MOV        word ptr [BP + -4h],0h	; local_6
	JMP        L_1067
L_1064:
	INC        word ptr [BP + -4h]	; local_6
L_1067:
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -4h],AX	; local_6
	JNC        L_10c7
	MOV        SI,word ptr [BP + -4h]	; local_6
	MOV        CL,5h
	SHL        SI,CL
	CMP        byte ptr [SI + 55b3h],44h
	JZ         L_1064
	CMP        byte ptr [SI + 55b3h],50h
	JZ         L_1064
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1dh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        CL,byte ptr [SI + 55b5h]
	SUB        CH,CH
	CMP        CX,AX
	JNC        L_1064
	MOV        AX,2775h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        byte ptr [SI + 55b3h],50h
	CALL       SUB_0000_a730
	JMP        L_1064
	db 90h
L_10ac:
	CMP        word ptr [BP + -8h],0bch	; local_a
	JZ         L_10ba
	CMP        word ptr [BP + -8h],8fh	; local_a
	JNZ        L_10c7
L_10ba:
	CALL       SUB_0000_d740
	MOV        AX,2780h
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_a8d8
L_10c7:
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_10d0
	JMP        L_0f48
L_10d0:
	CALL       SUB_0000_a918
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0f02 ENDP
F_10da PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,278ah
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_a8d8
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_08d4
	POP        BP
	RET        2h
	db 90h
	; Func
F_10da ENDP
F_10f2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	SUB        DX,DX
	MOV        word ptr [BP + -4h],DX	; local_6
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SHL        SI,CL
	MOV        CX,DX
L_1107:
	MOV        BX,CX
	CMP        byte ptr [BX + SI + 5d6ah],0h
	JZ         L_1113
	MOV        DX,1h
L_1113:
	INC        CX
	CMP        CX,4h
	JL         L_1107
	MOV        word ptr [BP + -2h],DX	; local_4
	MOV        word ptr [BP + -4h],CX	; local_6
	MOV        BX,CX
	MOV        AL,byte ptr [BX + 659eh]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,40h
	JL         L_1134
	CMP        AX,74h
	JL         L_1139
L_1134:
	MOV        word ptr [BP + -2h],0h	; local_4
L_1139:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_114c
	MOV        word ptr [BP + -2h],0h	; local_4
L_114c:
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_10f2 ENDP
F_1156 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[5958h]
	SUB        AH,AH
	CMP        AX,1h
	JZ         L_1170
	CMP        AX,2h
	JZ         L_1190
	JMP        L_11b1
	db 90h
L_1170:
	SUB        SI,SI
	MOV        DI,5f68h
L_1175:
	PUSH       SI
	CALL       F_10f2
	OR         AX,AX
	JZ         L_1185
	PUSH       SI
	CALL       F_085e
	MOV        word ptr [DI],0feh
L_1185:
	ADD        DI,10h
	INC        SI
	CMP        SI,20h
	JL         L_1175
	JMP        L_11ae
L_1190:
	SUB        SI,SI
	MOV        DI,5f68h
L_1195:
	PUSH       SI
	CALL       F_10f2
	OR         AX,AX
	JZ         L_11a5
	PUSH       SI
	CALL       F_08d4
	MOV        word ptr [DI],0fdh
L_11a5:
	ADD        DI,10h
	INC        SI
	CMP        SI,20h
	JL         L_1195
L_11ae:
	MOV        word ptr [BP + -2h],SI	; local_4
L_11b1:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_1156 ENDP
F_11b8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,27b8h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        BX,word ptr [BP + 4h]	; param_1
	SHL        BX,1h
	PUSH       word ptr [BX + 27dch]
	CALL       SUB_0000_9680
	MOV        AX,27c4h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,19c8h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0ea60h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9fc2
	POP        BP
	RET        2h
	; Func
F_11b8 ENDP
F_11f0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        AL,1h
	MOV        DS:[24e6h],AL
	MOV        DS:[0a9bch],AL
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_122e
	MOV        word ptr [BP + -2h],20h	; local_4
	MOV        SI,5c62h
	MOV        CX,1fh
L_1210:
	MOV        byte ptr [SI],0h
	ADD        SI,8h
	LOOP       L_1210
	MOV        byte ptr DS:[5957h],0h
	MOV        byte ptr DS:[58a4h],1h
	CALL       SUB_0000_f8a6
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_f8d6
L_122e:
	MOV        byte ptr DS:[5958h],0ffh
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0408
	CALL       F_02ae
	SUB        SI,SI
L_123e:
	PUSH       SI
	CALL       F_0000
	OR         AX,AX
	JZ         L_124a
	PUSH       SI
	CALL       F_00b0
L_124a:
	INC        SI
	CMP        SI,20h
	JL         L_123e
	MOV        word ptr [BP + -2h],SI	; local_4
	CMP        byte ptr DS:[5893h],1dh
	JNZ        L_1268
	CMP        byte ptr DS:[57b5h],0h
	JZ         L_1268
	MOV        AX,9h
	PUSH       AX
	CALL       F_00b0
L_1268:
	CALL       SUB_0000_a730
	CALL       SUB_0000_b82c
	OR         AX,AX
	JL         L_12a7
	CALL       SUB_0000_d740
	CMP        byte ptr DS:[5893h],1dh
	JNZ        L_1294
	MOV        SI,2h
L_127f:
	CMP        byte ptr [SI + 58c8h],80h
	JNC        L_128a
	PUSH       SI
	CALL       F_11b8
L_128a:
	DEC        SI
	JNS        L_127f
	MOV        word ptr [BP + -2h],SI	; local_4
	JMP        L_12a7
	db 90h
	db 90h
L_1294:
	CMP        byte ptr DS:[5958h],0ffh
	JZ         L_12a7
	MOV        AL,DS:[5958h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_11b8
	CALL       F_1156
L_12a7:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_11f0 ENDP
F_12ae PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -4h],0h	; local_6
	CMP        byte ptr DS:[5893h],12h
	JNZ        L_12d8
	CALL       SUB_0000_b82c
	OR         AX,AX
	JGE        L_12ca
	JMP        L_134b
L_12ca:
	CALL       SUB_0000_f8ee
L_12cd:
	MOV        AX,1h
	PUSH       AX
	CALL       F_11f0
	JMP        L_134b
	db 90h
	db 90h
L_12d8:
	MOV        AX,27e2h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,27feh
	PUSH       AX
	CALL       SUB_0000_9680
L_12e6:
	CALL       SUB_0000_a49c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,4eh
	JZ         L_12f4
	CMP        AL,59h
	JNZ        L_12e6
L_12f4:
	CMP        byte ptr [BP + -2h],59h	; local_4
	JNZ        L_133c
	MOV        AX,281bh
	PUSH       AX
	CALL       SUB_0000_9680
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_88a0
	MOV        AX,2845h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        byte ptr DS:[5893h],4h
	MOV        byte ptr DS:[5896h],19h
	MOV        byte ptr DS:[5897h],4h
	MOV        byte ptr DS:[24e6h],1h
	JMP        L_132b
L_1324:
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_cdac
L_132b:
	CMP        byte ptr DS:[587fh],8h
	JNZ        L_1324
	SUB        AL,AL
	MOV        DS:[57ach],AL
	MOV        DS:[5895h],AL
	JMP        L_12cd
L_133c:
	MOV        AX,285eh
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       F_0958
	MOV        word ptr [BP + -4h],1h	; local_6
L_134b:
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_12ae ENDP
F_1352 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        BL,byte ptr DS:[65bfh]
	SUB        BH,BH
	MOV        CL,4h
	SHL        BX,CL
	MOV        AX,word ptr [BX + 5f6ah]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -4h],AX	; local_6
	CALL       SUB_0000_d740
	CMP        byte ptr DS:[65beh],61h
	JNZ        L_13b4
	MOV        BL,byte ptr DS:[65bfh]
	SUB        BH,BH
	MOV        CL,4h
	SHL        BX,CL
	CMP        word ptr [BX + 5f68h],0feh
	JNZ        L_13a4
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	MOV        AL,DS:[65bfh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_10da
	JMP        L_13dc
L_13a4:
	MOV        BX,word ptr [BP + -4h]	; local_6
	CMP        byte ptr [BX],70h
	JZ         L_13d6
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_13dc
	db 90h
L_13b4:
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_13d6
	MOV        AL,DS:[65bfh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        BX,SI
	MOV        CL,4h
	SHL        BX,CL
	CMP        word ptr [BX + 5f68h],0h
	JZ         L_13dc
	PUSH       SI
	CALL       SUB_0000_f912
	OR         AX,AX
	JZ         L_13dc
L_13d6:
	CALL       F_12ae
	MOV        word ptr [BP + -2h],AX	; local_4
L_13dc:
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_1417
	MOV        BL,byte ptr DS:[65bfh]
	SUB        BH,BH
	MOV        CL,4h
	SHL        BX,CL
	MOV        BX,word ptr [BX + 5f6ah]
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 5c5ah],40h
	JC         L_140e
	MOV        AX,2881h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[65bfh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_09bc
	JMP        L_1417
	db 90h
L_140e:
	MOV        AL,DS:[65bfh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_00b0
L_1417:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_1352 ENDP
F_141e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	SUB        AX,AX
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        word ptr [BP + -4h],AX	; local_6
L_142c:
	MOV        word ptr [BP + -0ch],0h	; local_e
	MOV        word ptr [BP + -0ah],1h	; local_c
	CALL       SUB_0000_b82c
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,1h
	JNZ        L_1456
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CALL       SUB_0000_ca5a
	MOV        AX,288dh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_15a6
	db 90h
L_1456:
	CMP        word ptr [BP + -8h],-1h	; local_a
	JNZ        L_1468
	CALL       SUB_0000_f88e
	MOV        word ptr [BP + -0ah],0h	; local_c
	JMP        L_15a6
	db 90h
L_1468:
	CMP        byte ptr DS:[0a9bch],0h
	JZ         L_1476
	MOV        byte ptr DS:[0a9bch],0h
	JMP        L_1480
L_1476:
	CALL       SUB_0000_c6d8
	OR         AX,AX
	JZ         L_1480
	CALL       SUB_0000_f89a
L_1480:
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_148a
	JMP        L_168f
L_148a:
	MOV        word ptr [BP + -2h],1h	; local_4
L_148f:
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0dc4
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        word ptr [BP + -2h],0h	; local_4
	CMP        AX,20h
	JC         L_14a5
	JMP        L_1580
L_14a5:
	SUB        AX,1h
	CMP        AX,15h
	JBE        L_14b0
	JMP        L_1544
L_14b0:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 9722h]
	db 0A0h
	db 88h
	db 58h
	db 2Ah
	db 0E4h
	db 50h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0B8h
	db 20h
	db 00h
	db 50h
	db 0E8h
	db 0A5h
	db 83h
	db 0EBh
	db 34h
	db 90h
	db 0B8h
	db 98h
	db 28h
	db 50h
	db 0E8h
	db 0ADh
	db 81h
	db 0E8h
	db 0C6h
	db 8Fh
	db 89h
	db 46h
	db 0FAh
	db 3Dh
	db 59h
	db 00h
	db 75h
	db 10h
	db 0E8h
	db 0C7h
	db 71h
	db 2Bh
	db 0C0h
	db 50h
	db 0E8h
	db 3Dh
	db 6Ch
	db 83h
	db 0C4h
	db 02h
	db 0E9h
	db 0B0h
	db 00h
	db 90h
	db 0B8h
	db 0A6h
	db 28h
	db 50h
	db 0E8h
	db 8Bh
	db 81h
	db 0E9h
	db 0A5h
	db 00h
	db 0B8h
	db 0A9h
	db 28h
	db 50h
	db 0E8h
	db 81h
	db 81h
	db 0B8h
	db 0Ah
	db 00h
	db 50h
	db 0E8h
	db 0E4h
	db 7Fh
	db 0EBh
	db 43h
	db 0B8h
	db 0AEh
	db 28h
	db 50h
	db 0E8h
	db 71h
	db 81h
	db 80h
	db 3Eh
	db 0CEh
	db 0A9h
	db 00h
	db 74h
	db 06h
	db 0B8h
	db 0B5h
	db 28h
	db 0EBh
	db 04h
	db 90h
	db 0B8h
	db 0BAh
	db 28h
	db 50h
	db 0E8h
	db 5Dh
	db 81h
	db 80h
	db 3Eh
	db 0CEh
	db 0A9h
	db 01h
	db 1Bh
	db 0C0h
	db 0F7h
	db 0D8h
	db 0A2h
	db 0CEh
	db 0A9h
	db 0EBh
	db 1Ah
	db 90h
	db 0FFh
	db 76h
	db 0FAh
	db 0E8h
	db 0C8h
	db 0F0h
	db 89h
	db 46h
	db 0F4h
	db 3Dh
	db 01h
	db 00h
	db 1Bh
	db 0C0h
	db 0F7h
	db 0D8h
	db 0EBh
	db 56h
L_1544:
	MOV        AX,28beh
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -0ah],0h	; local_c
	JMP        L_159d
	db 02h
	db 97h
	db 02h
	db 97h
	db 02h
	db 97h
	db 02h
	db 97h
	db 9Ch
	db 96h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 88h
	db 96h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 14h
	db 97h
	db 0D8h
	db 96h
	db 14h
	db 97h
	db 14h
	db 97h
	db 0C8h
	db 96h
	db 0EBh
	db 1Dh
L_1580:
	CMP        word ptr [BP + -6h],30h	; local_8
	JC         L_158c
	CMP        word ptr [BP + -6h],39h	; local_8
	JBE        L_1594
L_158c:
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       SUB_0000_afa8
	JMP        L_159a
L_1594:
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       F_0e34
L_159a:
	MOV        word ptr [BP + -0ah],AX	; local_c
L_159d:
	CMP        word ptr [BP + -0ah],3h	; local_c
	JNZ        L_15a6
	JMP        L_148f
L_15a6:
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_15b6
	MOV        word ptr [BP + -0ch],1h	; local_e
	JMP        L_1686
	db 90h
L_15b6:
	CMP        word ptr [BP + -0ah],0h	; local_c
	JNZ        L_15bf
	JMP        L_1686
L_15bf:
	CALL       SUB_0000_b82c
	INC        AX
	JNZ        L_15c8
	JMP        L_1686
L_15c8:
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	MOV        word ptr [BP + -10h],AX	; local_12
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_cdac
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	CMP        word ptr [BP + -10h],AX	; local_12
	JZ         L_15ec
	CMP        AL,14h
	JZ         L_15e9
	CMP        AL,5h
	JNZ        L_15ec
L_15e9:
	CALL       F_0170
L_15ec:
	CALL       F_0f02
	CMP        byte ptr DS:[594fh],0h
	JZ         L_160d
	DEC        byte ptr DS:[5952h]
	JNZ        L_160d
	MOV        AL,DS:[594fh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5950h]
	PUSH       AX
	MOV        AL,DS:[5951h]
	PUSH       AX
	CALL       SUB_0000_b7fc
L_160d:
	MOV        AL,DS:[5896h]
	MOV        DS:[5c5ch],AL
	MOV        AL,DS:[5897h]
	MOV        DS:[5c5dh],AL
	MOV        AL,DS:[5895h]
	MOV        DS:[5c5eh],AL
	CMP        byte ptr DS:[587ch],12h
	JC         L_1642
	CMP        byte ptr DS:[587ch],16h
	JNC        L_1642
	CMP        word ptr [BP + -6h],20h	; local_8
	JZ         L_1642
	CMP        word ptr [BP + -4h],1h	; local_6
	SBB        AX,AX
	NEG        AX
	MOV        word ptr [BP + -4h],AX	; local_6
	OR         AX,AX
	JNZ        L_1686
L_1642:
	CMP        byte ptr DS:[587ah],54h
	JZ         L_1686
	CMP        byte ptr DS:[587ah],51h
	JNZ        L_165f
	CMP        word ptr [BP + -0eh],1h	; local_10
	SBB        AX,AX
	NEG        AX
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JNZ        L_1686
L_165f:
	CALL       F_0c78
	CMP        word ptr [BP + -0ah],2h	; local_c
	JGE        L_1671
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_f8e2
L_1671:
	CMP        byte ptr DS:[65bfh],0h
	JNZ        L_167e
	CMP        word ptr [BP + -0ah],2h	; local_c
	JNZ        L_1686
L_167e:
	MOV        AX,word ptr [BP + -0ah]	; local_c
	DEC        AX
	PUSH       AX
	CALL       F_1352
L_1686:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JNZ        L_168f
	JMP        L_142c
L_168f:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_141e ENDP
F_1694 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        SI,1h
	MOV        DI,5f7ah
L_16a2:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_b8a4
	MOV        word ptr [DI],0h
	ADD        DI,10h
	INC        SI
	CMP        SI,20h
	JL         L_16a2
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        SI,1h
	MOV        DI,10h
	MOV        word ptr [BP + -8h],6560h	; local_a
L_16c9:
	CMP        byte ptr [SI + 659eh],0h
	JZ         L_1710
	PUSH       SI
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_f966
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,DI
	ADD        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BP + -0ah],AX	; local_c
	PUSH       SI
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 5d61h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 5d64h]
	PUSH       AX
	MOV        AL,byte ptr [BX + 5d67h]
	PUSH       AX
	CALL       F_1726
	MOV        word ptr [DI + 5f5eh],1h
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [DI + 5f6ch],AX
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        word ptr [BX],0ffffh
L_1710:
	ADD        DI,10h
	ADD        word ptr [BP + -8h],2h	; local_a
	INC        SI
	CMP        SI,20h
	JL         L_16c9
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1694 ENDP
F_1726 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        BX,word ptr [BP + 0ah]	; param_4
	CMP        byte ptr [BX + 659eh],0h
	JNZ        L_173a
	JMP        L_185a
L_173a:
	MOV        AX,BX
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,5f5eh
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX	; param_1
	JZ         L_176c
	MOV        BX,word ptr [BP + -2h]	; local_4
	CMP        word ptr [BX + 0ch],0h
	JZ         L_176c
	MOV        BX,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5ah],AH
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        word ptr [BX + 0ch],0h
L_176c:
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX	; param_1
	JZ         L_1779
	JMP        L_180d
L_1779:
	MOV        BX,word ptr [BP + -2h]	; local_4
	CMP        word ptr [BX + 0ch],0h
	JZ         L_1785
	JMP        L_180d
L_1785:
	CALL       SUB_0000_b714
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        BX,word ptr [BP + 0ah]	; param_4
	CMP        byte ptr [BX + 659eh],1h
	JNZ        L_179c
	MOV        word ptr [BP + -6h],1eh	; local_8
	JMP        L_17d9
L_179c:
	MOV        BL,byte ptr DS:[5893h]
	SUB        BH,BH
	SHL        BX,1h
	SHL        BX,1h
	MOV        AX,word ptr [BX + 28c2h]
	MOV        DX,word ptr [BX + 28c4h]
	MOV        CX,1h
	SUB        BX,BX
	MOV        SI,CX
	MOV        CL,byte ptr [BP + 0ah]	; param_4
	OR         CL,CL
	JZ         L_17c4
L_17bc:
	SHL        SI,1h
	RCL        BX,1h
	DEC        CL
	JNZ        L_17bc
L_17c4:
	AND        AX,SI
	AND        DX,BX
	OR         DX,AX
	JZ         L_17d4
	MOV        word ptr [BP + -6h],0ffh	; local_8
	JMP        L_17d9
	db 90h
L_17d4:
	MOV        word ptr [BP + -6h],0h	; local_8
L_17d9:
	MOV        BX,word ptr [BP + 0ah]	; param_4
	MOV        AL,byte ptr [BX + 659eh]
	SUB        AH,AH
	MOV        SI,AX
	PUSH       SI
	PUSH       SI
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_b8a4
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c60h],0h
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BX + 0ch],AX
L_180d:
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX	; param_1
	JNZ        L_1841
	MOV        BX,word ptr [BP + -2h]	; local_4
	CMP        word ptr [BX + 0ch],0h
	JZ         L_1841
	MOV        AX,word ptr [BX + 0ch]
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [BP + 8h]	; param_3
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AL,byte ptr [BP + 6h]	; param_2
	MOV        byte ptr [SI + 5c5dh],AL
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        byte ptr [SI + 5c5eh],AL
L_1841:
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AX,word ptr [BP + 8h]	; param_3
	MOV        word ptr [BX + 2h],AX
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        word ptr [BX + 4h],AX
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        word ptr [BX + 6h],AX
	MOV        word ptr [BX],1h
L_185a:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        8h
	db 90h
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
	db 00h
	db 00h
	db 00h
	db 00h
F_1726 ENDP
_TEXT ENDS
END
