_TEXT SEGMENT BYTE 'CODE'
ORG 60b2h
SUB_0000_60b2:
ORG 8482h
SUB_0000_8482:
ORG 58d0h
SUB_0000_58d0:
ORG 66ech
SUB_0000_66ec:
ORG 7a7ch
SUB_0000_7a7c:
ORG 573ah
SUB_0000_573a:
ORG 6980h
SUB_0000_6980:
ORG 5abeh
SUB_0000_5abe:
ORG 7b9ch
SUB_0000_7b9c:
ORG 0bb02h
SUB_0000_bb02:
ORG 0bbb6h
SUB_0000_bbb6:
ORG 766ch
SUB_0000_766c:
ORG 770eh
SUB_0000_770e:
ORG 0bb9eh
SUB_0000_bb9e:
ORG 5d1eh
SUB_0000_5d1e:
ORG 5f92h
SUB_0000_5f92:
ORG 7f70h
SUB_0000_7f70:
ORG 0bb86h
SUB_0000_bb86:
ORG 0bb92h
SUB_0000_bb92:
ORG 0af9eh
SUB_0000_af9e:
ORG 9990h
SUB_0000_9990:
ORG 5ddeh
SUB_0000_5dde:
ORG 5b96h
SUB_0000_5b96:
ORG 617ah
SUB_0000_617a:
ORG 44f6h
SUB_0000_44f6:
ORG 7fb6h
SUB_0000_7fb6:
ORG 0bb56h
SUB_0000_bb56:
ORG 60d6h
SUB_0000_60d6:
ORG 60feh
SUB_0000_60fe:
ORG 6112h
SUB_0000_6112:
ORG 842eh
SUB_0000_842e:
ORG 7fd4h
SUB_0000_7fd4:
ORG 65eeh
SUB_0000_65ee:
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
	SUB        SP,2h
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + 6h]	; param_2
	MOV        SI,word ptr [BP + 4h]	; param_1
L_000e:
	INC        SI
	MOV        AL,byte ptr [SI + -1h]
	SUB        AH,AH
	AND        AX,7fh
	PUSH       AX
	CALL       SUB_0000_60b2
	INC        DI
	MOV        CL,byte ptr [DI + -1h]
	SUB        CH,CH
	AND        CX,7fh
	PUSH       CX
	MOV        word ptr [BP + -2h],AX	; local_4
	CALL       SUB_0000_60b2
	CMP        AX,word ptr [BP + -2h]	; local_4
	JZ         L_003c
	SUB        AX,AX
L_0033:
	MOV        word ptr [BP + 6h],DI	; param_2
	MOV        word ptr [BP + 4h],SI	; param_1
	JMP        L_004c
	db 90h
L_003c:
	CMP        byte ptr [DI],0h
	JNZ        L_000e
	CMP        byte ptr [SI],0h
	JNZ        L_000e
	MOV        AX,1h
	JMP        L_0033
	db 90h
L_004c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0000 ENDP
F_0054 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,0a5h
	JZ         L_007c
	JA         L_0082
	CMP        AX,29h
	JZ         L_007c
	CMP        AX,94h
	JC         L_0091
	CMP        AX,9ch
	JMP        L_00a3
L_007c:
	MOV        AX,1h
	JMP        L_00a8
	db 90h
L_0082:
	CMP        AX,0bbh
	JA         L_0096
	CMP        AX,0bah
	JNC        L_007c
	CMP        AX,0aeh
	JZ         L_007c
L_0091:
	SUB        AX,AX
	JMP        L_00a8
	db 90h
L_0096:
	CMP        AX,0beh
	JZ         L_007c
	CMP        AX,0cah
	JC         L_0091
	CMP        AX,0cbh
L_00a3:
	JBE        L_007c
	JMP        L_0091
	db 90h
L_00a8:
	POP        BP
	RET        4h
	; Func
F_0054 ENDP
F_00ac PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,9052h
	PUSH       AX
	CALL       SUB_0000_58d0
L_00b9:
	CALL       SUB_0000_66ec
	PUSH       AX
	CALL       SUB_0000_60b2
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,59h
	JNZ        L_00d2
	MOV        AX,9066h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	JMP        L_00e2
L_00d2:
	CMP        byte ptr [BP + -2h],4eh	; local_4
	JNZ        L_00b9
	MOV        AX,906ch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,1h
L_00e2:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_00ac ENDP
F_00e6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,12h
	JNZ        L_0108
	CMP        word ptr [BP + 4h],83h	; param_1
	JZ         L_0108
	MOV        AX,9072h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_01da
	db 90h
L_0108:
	CMP        byte ptr DS:[587bh],0ffh
	JZ         L_0116
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	JMP        L_011c
L_0116:
	CALL       SUB_0000_7a7c
	MOV        AX,DS:[5876h]
L_011c:
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,word ptr [BP + 4h]	; param_1
	SUB        AX,81h
	MOV        DS:[0b116h],AX
	MOV        word ptr DS:[0b114h],0h
	MOV        BX,AX
	MOV        CL,4h
	SHL        BX,CL
	MOV        AL,DS:[5893h]
	CMP        byte ptr [BX + 23cah],AL
	JZ         L_015d
	MOV        SI,word ptr DS:[0b116h]
	SHL        SI,CL
	MOV        DL,AL
	MOV        CX,word ptr DS:[0b114h]
L_0149:
	CMP        CX,10h
	JGE        L_0159
	INC        CX
	MOV        BX,SI
	ADD        BX,CX
	CMP        byte ptr [BX + 23cah],DL
	JNZ        L_0149
L_0159:
	MOV        word ptr DS:[0b114h],CX
L_015d:
	MOV        SI,word ptr DS:[0b116h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,DS:[0b114h]
	SHL        AX,1h
	ADD        SI,AX
	MOV        AX,word ptr [SI + 21cah]
	MOV        DS:[0aafch],AX
	MOV        AX,word ptr [SI + 22cah]
	MOV        DS:[0aafeh],AX
	MOV        AX,DS:[0b116h]
	CMP        AX,7h
	JA         L_01da
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0c14ah]
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 0B2h
	db 0BEh
	db 0EBh
	db 48h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 66h
	db 0C0h
	db 0EBh
	db 40h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 0DEh
	db 0BEh
	db 0EBh
	db 38h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 62h
	db 0C0h
	db 0EBh
	db 30h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 9Eh
	db 0BEh
	db 0EBh
	db 28h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 42h
	db 0BEh
	db 0EBh
	db 20h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 6Ah
	db 0BEh
	db 0EBh
	db 18h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 5Ah
	db 0C0h
	db 0EBh
	db 10h
	db 0Ah
	db 0C1h
	db 12h
	db 0C1h
	db 1Ah
	db 0C1h
	db 22h
	db 0C1h
	db 2Ah
	db 0C1h
	db 32h
	db 0C1h
	db 3Ah
	db 0C1h
	db 42h
	db 0C1h
L_01da:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_00e6 ENDP
F_01e2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ch
	PUSH       SI
	CMP        byte ptr DS:[5893h],12h
	JNZ        L_01f3
	JMP        L_02a4
L_01f3:
	CMP        byte ptr DS:[5893h],5h
	JNZ        L_0230
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,90a2h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	CALL       F_00ac
	OR         AX,AX
	JZ         L_021c
L_0216:
	MOV        AX,1h
	JMP        L_0318
L_021c:
	MOV        CX,2h
	MOV        AX,DS:[57aah]
	CWD
	IDIV       CX
	MOV        DS:[57aah],AX
L_0228:
	CALL       SUB_0000_6980
L_022b:
	SUB        AX,AX
	JMP        L_0318
L_0230:
	MOV        word ptr [BP + -14h],0h	; local_16
	MOV        word ptr [BP + -12h],0h	; local_14
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_026c
	MOV        word ptr [BP + -16h],AX	; local_18
	MOV        SI,55b3h
	MOV        DX,AX
	MOV        CL,5h
	SHL        DX,CL
	ADD        DX,SI
	MOV        word ptr [BP + -1ch],AX	; local_1e
	ADD        word ptr [BP + -12h],AX	; local_14
	MOV        CX,word ptr [BP + -14h]	; local_16
L_025a:
	CMP        byte ptr [SI],44h
	JZ         L_0262
	ADD        CX,0ah
L_0262:
	ADD        SI,20h
	CMP        SI,DX
	JNZ        L_025a
	MOV        word ptr [BP + -14h],CX	; local_16
L_026c:
	MOV        AX,90cch
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + -14h]	; local_16
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_5abe
	MOV        AX,90e0h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_00ac
	OR         AX,AX
	JNZ        L_0216
	MOV        AX,DS:[57aah]
	CMP        word ptr [BP + -14h],AX	; local_16
	JBE        L_029a
	JMP        L_0216
L_029a:
	MOV        AX,word ptr [BP + -14h]	; local_16
	SUB        word ptr DS:[57aah],AX
	JMP        L_0228
	db 90h
L_02a4:
	CMP        byte ptr DS:[587ah],1dh
	JZ         L_02ae
	JMP        L_0216
L_02ae:
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,90fch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,9128h
	PUSH       AX
	CALL       SUB_0000_58d0
	LEA        AX,[BP + -10h]	; local_12
	PUSH       AX
	MOV        AX,0eh
	PUSH       AX
	CALL       SUB_0000_7b9c
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        byte ptr [BP + -0ch],0h	; local_e
	MOV        AX,4a9ah
	PUSH       AX
	LEA        AX,[BP + -10h]	; local_12
	PUSH       AX
	CALL       F_0000
	OR         AX,AX
	JNZ        L_02f2
	JMP        L_0216
L_02f2:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,913ah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	JMP        L_022b
L_0318:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_01e2 ENDP
F_031e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        DS:[0bcdch],AX
	MOV        SI,AX
	MOV        CL,4h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,5f5eh
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,SI
	ADD        AX,5d5eh
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        SI,word ptr [BX + 0eh]
	ADD        SI,AX
	CMP        byte ptr [SI],CL
	JNZ        L_036a
	MOV        byte ptr [SI],1h
L_0357:
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AX,word ptr [BX + 0ah]
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JNZ        L_0396
	MOV        AX,9168h
	JMP        L_038a
	db 90h
L_036a:
	MOV        BX,word ptr [BX + 0ch]
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 5c5ah],70h
	JNZ        L_0357
	MOV        BX,word ptr [BP + -4h]	; local_6
	TEST       byte ptr [BX + 0eh],1h
	JZ         L_0387
	CMP        word ptr [BX + 0ah],0h
	JNZ        L_0357
L_0387:
	MOV        AX,9148h
L_038a:
	PUSH       AX
	CALL       SUB_0000_58d0
L_038e:
	SUB        AX,AX
	JMP        L_0414
	db 90h
	db 90h
	db 90h
L_0396:
	CMP        word ptr [BP + -2h],80h	; local_4
	JGE        L_03a6
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_127e
	JMP        L_038e
	db 90h
L_03a6:
	CMP        word ptr [BP + -2h],0fdh	; local_4
	JNZ        L_03cc
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,9176h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	JMP        L_038e
	db 90h
L_03cc:
	CMP        word ptr [BP + -2h],0feh	; local_4
	JNZ        L_03d8
	CALL       SUB_0000_bb02
	JMP        L_038e
L_03d8:
	CMP        word ptr [BP + -2h],0ffh	; local_4
	JNZ        L_03e4
	CALL       F_01e2
	JMP        L_0414
L_03e4:
	MOV        BX,word ptr [BP + -4h]	; local_6
	TEST       byte ptr [BX + 0eh],1h
	JZ         L_0406
	PUSH       word ptr DS:[0bcdch]
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_bbb6
	TEST       AL,1h
	JZ         L_0406
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_00e6
	JMP        L_038e
L_0406:
	MOV        AX,9196h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,91c4h
	JMP        L_038a
	db 90h
L_0414:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_031e ENDP
F_041c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_042e
L_0429:
	SUB        AX,AX
	JMP        L_04ce
L_042e:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + -0ah]	; local_c
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	MOV        word ptr [BP + -8h],AX	; local_a
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JNZ        L_047e
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       F_0054
	OR         AX,AX
	JZ         L_047e
	MOV        AX,word ptr [BP + -6h]	; local_8
	ADD        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + -0ah]	; local_c
	ADD        word ptr [BP + -8h],AX	; local_a
L_047e:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -8h]	; local_a
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JNZ        L_049a
	MOV        AX,91d6h
L_0494:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0429
L_049a:
	PUSH       word ptr DS:[5876h]
	CALL       SUB_0000_bb9e
	MOV        word ptr [BP + -2h],AX	; local_4
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,9dh
	JZ         L_04c2
	CMP        AX,0abh
	JNZ        L_04c8
	MOV        AX,91e8h
	JMP        L_0494
L_04c2:
	MOV        AX,91f6h
	JMP        L_0494
	db 90h
L_04c8:
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_031e
L_04ce:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_041c ENDP
F_04d2 PROC NEAR
	MOV        AX,8dh
	PUSH       AX
	CALL       F_0f32
	RET
	; Func
F_04d2 ENDP
F_04da PROC NEAR
	MOV        AX,0a2h
	PUSH       AX
	CALL       F_0f32
	RET
	; Func
F_04da ENDP
F_04e2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -2h],0h	; local_4
	CMP        byte ptr DS:[4af1h],0h
	JZ         L_056e
	MOV        SI,word ptr [BP + -2h]	; local_4
	JMP        L_0549
	db 90h
	db 90h
L_04fc:
	MOV        AX,1h
L_04ff:
	PUSH       AX
	CALL       SUB_0000_5d1e
	MOV        AL,byte ptr [SI + 0bce4h]
	AND        AL,7fh
	MOV        byte ptr [BP + -4h],AL	; local_6
	INC        SI
	CALL       SUB_0000_5f92
	OR         AX,AX
	JNZ        L_051a
	CMP        byte ptr [BP + -4h],20h	; local_6
	JZ         L_0549
L_051a:
	CMP        byte ptr DS:[4af3h],0fh
	JC         L_0527
	CMP        byte ptr [BP + -4h],0ah	; local_6
	JZ         L_053e
L_0527:
	CMP        byte ptr [BP + -4h],0ah	; local_6
	JZ         L_0533
	CALL       SUB_0000_5f92
	MOV        DS:[4af3h],AL
L_0533:
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_573a
	JMP        L_0549
L_053e:
	CMP        byte ptr [BP + -4h],0ah	; local_6
	JNZ        L_0549
	MOV        byte ptr DS:[4af3h],0h
L_0549:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[4af1h]
	SUB        CH,CH
	CMP        AX,CX
	JNC        L_0560
	TEST       byte ptr [SI + 0bce4h],80h
	JZ         L_04fc
	SUB        AX,AX
	JMP        L_04ff
L_0560:
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        byte ptr DS:[4af1h],0h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_5d1e
L_056e:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_04e2 ENDP
F_0574 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        byte ptr DS:[4af1h],10h
	JZ         L_05ae
	MOV        BL,byte ptr DS:[4af1h]
	INC        word ptr DS:[4af1h]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        byte ptr [BX + 0bce4h],AL
	CMP        AL,8ah
	JZ         L_0597
	CMP        AL,0a0h
	JNZ        L_05b1
L_0597:
	CALL       SUB_0000_5f92
	MOV        CL,byte ptr DS:[4af1h]
	SUB        CH,CH
	ADD        AX,CX
	CMP        AX,12h
	JC         L_05ae
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
L_05ae:
	CALL       F_04e2
L_05b1:
	POP        BP
	RET        2h
	db 90h
	; Func
F_0574 ENDP
F_05b6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AL,DS:[0bce0h]
	SUB        AH,AH
	AND        AX,7fh
	MOV        CX,64h
	MUL        CX
	MOV        CL,byte ptr DS:[0bce1h]
	SUB        CH,CH
	AND        CX,7fh
	MOV        DX,CX
	SHL        CX,1h
	SHL        CX,1h
	ADD        CX,DX
	SHL        CX,1h
	ADD        AX,CX
	MOV        CL,byte ptr DS:[0bce2h]
	SUB        CH,CH
	AND        CX,7fh
	ADD        AX,CX
	SUB        AX,14d0h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,DS:[57aah]
	CMP        word ptr [BP + -2h],AX	; local_4
	JG         L_0652
	MOV        AX,word ptr [BP + -2h]	; local_4
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_6980
	MOV        BX,word ptr DS:[0bcdch]
	MOV        CL,4h
	SHL        BX,CL
	MOV        BX,word ptr [BX + 5f6ah]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	AND        AL,0fch
	CMP        AL,6ch
	JNZ        L_064e
	CMP        byte ptr DS:[588bh],64h
	JC         L_064e
	MOV        byte ptr DS:[588bh],0h
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
	CMP        word ptr DS:[57aah],0h
	JNZ        L_064e
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
L_064e:
	SUB        AX,AX
	JMP        L_067e
L_0652:
	MOV        byte ptr DS:[4af1h],0h
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,9328h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,9344h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AL,AL
	MOV        DS:[4aeeh],AL
	MOV        DS:[4aefh],AL
	CALL       F_0b04
L_067e:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_05b6 ENDP
F_0682 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        byte ptr [BP + 4h],40h	; param_1
	JNC        L_06a2
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	ADD        AX,57c0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
	JMP        L_0724
L_06a2:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	SUB        AX,41h
	CMP        AX,0ah
	JA         L_0724
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0c68eh]
	db 90h
	db 0B8h
	db 0A8h
	db 57h
	db 50h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0B8h
	db 0Fh
	db 27h
	db 50h
	db 0E8h
	db 0CDh
	db 78h
	db 0E8h
	db 0B6h
	db 62h
	db 0EBh
	db 58h
	db 0B8h
	db 0AAh
	db 57h
	db 0EBh
	db 0EAh
	db 90h
	db 0B8h
	db 0ACh
	db 57h
	db 0EBh
	db 0BCh
	db 90h
	db 0B8h
	db 0ADh
	db 57h
	db 0EBh
	db 0B6h
	db 90h
	db 0B8h
	db 0AEh
	db 57h
	db 0EBh
	db 0B0h
	db 90h
	db 0B8h
	db 0AFh
	db 57h
	db 0EBh
	db 0AAh
	db 90h
	db 0B8h
	db 0B0h
	db 57h
	db 0EBh
	db 0A4h
	db 90h
	db 0C6h
	db 06h
	db 0BCh
	db 57h
	db 0FFh
	db 0EBh
	db 2Dh
	db 90h
	db 0C6h
	db 06h
	db 0BAh
	db 57h
	db 0FFh
	db 0EBh
	db 25h
	db 90h
	db 0C6h
	db 06h
	db 0BEh
	db 57h
	db 0FFh
	db 0EBh
	db 1Dh
	db 90h
	db 0B8h
	db 0B1h
	db 57h
	db 0EBh
	db 86h
	db 90h
	db 38h
	db 0C6h
	db 4Ch
	db 0C6h
	db 52h
	db 0C6h
	db 58h
	db 0C6h
	db 5Eh
	db 0C6h
	db 64h
	db 0C6h
	db 6Ah
	db 0C6h
	db 70h
	db 0C6h
	db 78h
	db 0C6h
	db 80h
	db 0C6h
	db 88h
	db 0C6h
L_0724:
	POP        BP
	RET        2h
	; Func
F_0682 ENDP
F_0728 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        SI,word ptr DS:[0bcdeh]
	MOV        DL,byte ptr [BP + 4h]	; param_1
L_0736:
	MOV        CL,byte ptr [SI]
	INC        SI
	CMP        CL,byte ptr [BP + 6h]	; param_2
	JNZ        L_074a
	MOV        AX,1h
L_0741:
	MOV        word ptr DS:[0bcdeh],SI
	MOV        byte ptr [BP + -2h],CL	; local_4
	JMP        L_0752
L_074a:
	CMP        CL,DL
	JNZ        L_0736
	SUB        AX,AX
	JMP        L_0741
L_0752:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0728 ENDP
F_075a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	MOV        word ptr DS:[0bcdeh],0b21eh
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0783
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0783
	MOV        SI,word ptr [BP + 4h]	; param_1
L_0773:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	CALL       F_0728
	DEC        SI
	JNZ        L_0773
	MOV        word ptr [BP + 4h],SI	; param_1
L_0783:
	POP        SI
	POP        BP
	RET        2h
	; Func
F_075a ENDP
F_0788 PROC NEAR
	MOV        BX,word ptr DS:[0bcdeh]
	CMP        byte ptr [BX],0h
	JZ         L_07a6
	INC        word ptr DS:[0bcdeh]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0f32
	OR         AX,AX
	JZ         F_0788
	MOV        AX,1h
	JMP        L_07a8
L_07a6:
	SUB        AX,AX
L_07a8:
	RET
	db 90h
	; Func
F_0788 ENDP
F_07aa PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	PUSH       AX
	CALL       F_075a
	CALL       F_0788
	POP        BP
	RET        2h
	db 90h
	db 56h
	db 0FFh
	db 06h
	db 0DEh
	db 0BCh
	db 8Bh
	db 36h
	db 0DEh
	db 0BCh
	db 0EBh
	db 02h
	db 90h
	db 46h
	db 80h
	db 3Ch
	db 00h
	db 74h
	db 0FAh
L_07d0:
	MOV        word ptr DS:[0bcdeh],SI
L_07d4:
	INC        SI
	CMP        byte ptr [SI + -1h],0h
	JNZ        L_07d4
	MOV        word ptr DS:[0bcdeh],SI
	CALL       F_0788
	POP        SI
	RET
	; Func
F_07aa ENDP
F_07e4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        SI,55a8h
	JMP        L_07fc
L_07f0:
	INC        SI
	MOV        AL,byte ptr [SI + -1h]
	SUB        AH,AH
	OR         AL,80h
	PUSH       AX
	CALL       F_0f32
L_07fc:
	CMP        byte ptr [SI],0h
	JNZ        L_07f0
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_07e4 ENDP
F_080a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,32h
	PUSH       DI
	PUSH       SI
	MOV        AX,DS:[0bcdeh]
	MOV        word ptr [BP + -2ch],AX	; local_2e
	MOV        word ptr [BP + -2h],0fh	; local_4
	CMP        byte ptr DS:[585bh],6h
	JNZ        L_083a
	CALL       SUB_0000_66ec
	MOV        AX,9348h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,9372h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	JMP        L_0933
L_083a:
	SUB        AX,AX
	PUSH       AX
	CALL       F_075a
	MOV        word ptr [BP + -2eh],0h	; local_30
	MOV        AX,DS:[0bcdeh]
	MOV        CX,1h
	LEA        DI,[BP + -6h]	; local_8
	MOV        SI,AX
	PUSH       SS
	POP        ES
	REP MOVSW
	MOVSB
	ADD        word ptr [BP + -2eh],3h	; local_30
	ADD        word ptr DS:[0bcdeh],3h
	MOV        byte ptr [BP + -3h],0h	; local_5
	MOV        byte ptr [BP + -27h],0h	; local_29
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,5h
	SHL        SI,CL
L_086d:
	SUB        DI,DI
	MOV        CX,1h
	PUSH       SI
	PUSH       DI
	LEA        DI,[BP + -2ah]	; local_2c
	LEA        SI,[SI + 55a8h]
	PUSH       SS
	POP        ES
	REP MOVSW
	MOVSB
	POP        DI
	POP        SI
	MOV        DI,3h
	LEA        AX,[BP + -6h]	; local_8
	PUSH       AX
	LEA        AX,[BP + -2ah]	; local_2c
	PUSH       AX
	CALL       F_0000
	OR         AX,AX
	JZ         L_089a
	MOV        word ptr [BP + -2eh],DI	; local_30
	JMP        L_08c8
	db 90h
L_089a:
	SUB        SI,20h
	DEC        word ptr [BP + -2h]	; local_4
	OR         SI,SI
	JNZ        L_086d
	MOV        AX,22h
	PUSH       AX
	CALL       F_0574
	MOV        AX,0ah
	PUSH       AX
	CALL       F_0574
	MOV        AX,93a8h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + -2ch]	; local_2e
	MOV        DS:[0bcdeh],AX
	MOV        AX,1h
	MOV        word ptr [BP + -2eh],DI	; local_30
	JMP        L_0933
	db 90h
L_08c8:
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,5h
	SHL        SI,CL
	MOV        byte ptr [SI + 55c7h],0h
	PUSH       SI
	PUSH       DI
	LEA        DI,[BP + -26h]	; local_28
	LEA        SI,[SI + 55a8h]
	PUSH       SS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	MOV        DI,AX
	MOV        CL,5h
	SHL        DI,CL
	ADD        DI,55a8h
	PUSH       SI
	PUSH       DI
	LEA        SI,[SI + 55a8h]
	XCHG       DI,SI
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	PUSH       SI
	PUSH       DI
	LEA        SI,[BP + -26h]	; local_28
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	INC        byte ptr DS:[585bh]
	PUSH       word ptr DS:[0bcdch]
	CALL       SUB_0000_bb86
	PUSH       word ptr DS:[0bcdch]
	CALL       SUB_0000_bb92
	CALL       SUB_0000_6980
	CALL       F_04e2
	MOV        AX,word ptr [BP + -2ch]	; local_2e
	MOV        DS:[0bcdeh],AX
	MOV        AX,1h
L_0933:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_080a ENDP
F_093a PROC NEAR
	MOV        word ptr DS:[0bcdeh],0b21eh
	JMP        L_094d
L_0942:
	MOV        AX,90h
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       F_0728
L_094d:
	MOV        BX,word ptr DS:[0bcdeh]
	MOV        AL,DS:[0bcf4h]
	CMP        byte ptr [BX],AL
	JNZ        L_0942
	INC        word ptr DS:[0bcdeh]
	CALL       F_0788
	RET
	; Func
F_093a ENDP
F_0960 PROC NEAR
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	CALL       F_0728
	CALL       F_0788
	RET
	; Func
F_0960 ENDP
F_096e PROC NEAR
	MOV        word ptr DS:[0bcdeh],0b21eh
	JMP        L_0981
L_0976:
	MOV        AX,90h
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       F_0728
L_0981:
	MOV        BX,word ptr DS:[0bcdeh]
	MOV        AL,DS:[0bcf4h]
	CMP        byte ptr [BX],AL
	JNZ        L_0976
	SUB        AX,AX
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       F_0728
	CALL       F_0788
	RET
	; Func
F_096e ENDP
F_099a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	MOV        word ptr DS:[0bcdeh],0b21eh
	MOV        AX,word ptr [BP + 4h]	; param_1
	SHL        AX,1h
	ADD        AX,5h
	MOV        word ptr [BP + 4h],AX	; param_1
	OR         AX,AX
	JZ         L_09d0
	MOV        SI,AX
L_09b5:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	CALL       F_0728
	OR         AX,AX
	JNZ        L_09ca
	SUB        AX,AX
	MOV        word ptr [BP + 4h],SI	; param_1
	JMP        L_09d3
L_09ca:
	DEC        SI
	JNZ        L_09b5
	MOV        word ptr [BP + 4h],SI	; param_1
L_09d0:
	MOV        AX,1h
L_09d3:
	POP        SI
	POP        BP
	RET        2h
	; Func
F_099a ENDP
F_09d8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        word ptr DS:[0bcf6h],0h
	MOV        SI,word ptr [BP + -2h]	; local_4
L_09e8:
	PUSH       word ptr DS:[0bcf6h]
	CALL       F_099a
	OR         AX,AX
	JNZ        L_09fa
	SUB        AX,AX
L_09f5:
	MOV        word ptr [BP + -2h],SI	; local_4
	JMP        L_0a26
L_09fa:
	PUSH       word ptr DS:[0bcdeh]
	MOV        AX,0bcf8h
	PUSH       AX
	CALL       SUB_0000_af9e
	MOV        SI,AX
	CMP        SI,-1h
	JZ         L_0a1c
	OR         SI,SI
	JZ         L_0a17
	CMP        byte ptr [SI + 0bcf7h],20h
	JNZ        L_0a1c
L_0a17:
	MOV        AX,1h
	JMP        L_09f5
L_0a1c:
	INC        word ptr DS:[0bcdeh]
	INC        word ptr DS:[0bcf6h]
	JMP        L_09e8
L_0a26:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_09d8 ENDP
F_0a2c PROC NEAR
	CALL       F_04e2
	MOV        AX,0bcf8h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_7b9c
	RET
	db 90h
	; Func
F_0a2c ENDP
F_0a3c PROC NEAR
	CALL       F_04da
	MOV        AX,4h
	PUSH       AX
	CALL       F_07aa
	OR         AX,AX
	JNZ        L_0a50
	CALL       F_04da
	CALL       F_04d2
L_0a50:
	MOV        AX,1h
	RET
	; Func
F_0a3c ENDP
F_0a54 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0a9c
	CMP        AX,1h
	JC         L_0a78
	CMP        AX,2h
	JBE        L_0abe
	CMP        AX,3h
	JC         L_0a78
	CMP        AX,4h
	JBE        L_0ae0
L_0a78:
	MOV        AX,93d0h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_04da
	CALL       F_04d2
	CALL       F_04d2
	SUB        SI,SI
L_0a8a:
	CALL       SUB_0000_9990
	CALL       SUB_0000_5dde
	OR         AX,AX
	JZ         L_0aec
L_0a94:
	MOV        word ptr [BP + -2h],SI	; local_4
	CALL       SUB_0000_5b96
	JMP        L_0adc
L_0a9c:
	CMP        byte ptr DS:[4af2h],0h
	JZ         L_0aa8
L_0aa3:
	MOV        AX,2h
	JMP        L_0afc
L_0aa8:
	MOV        AX,93c2h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	PUSH       AX
	CALL       F_07aa
	OR         AX,AX
	JZ         L_0ad3
L_0ab9:
	MOV        AX,1h
	JMP        L_0afc
L_0abe:
	CMP        byte ptr DS:[4af2h],0h
	JNZ        L_0aa3
	CALL       F_04da
	MOV        AX,3h
	PUSH       AX
	CALL       F_07aa
	OR         AX,AX
	JNZ        L_0ab9
L_0ad3:
	CALL       F_04da
	CALL       F_04d2
	CALL       F_04d2
L_0adc:
	SUB        AX,AX
	JMP        L_0afc
L_0ae0:
	CMP        byte ptr DS:[4af2h],0h
	JNZ        L_0aa3
	CALL       F_0a3c
	JMP        L_0afc
L_0aec:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_617a
	INC        SI
	CMP        SI,1ch
	JGE        L_0a94
	JMP        L_0a8a
	db 90h
L_0afc:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0a54 ENDP
F_0b04 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + -4h]	; local_6
L_0b0f:
	MOV        byte ptr DS:[4af2h],0h
	MOV        AX,9408h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_0a2c
	CMP        byte ptr DS:[0bcf8h],0h
	JNZ        L_0b36
	MOV        AX,941ah
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_0a3c
L_0b2f:
	MOV        word ptr [BP + -4h],DI	; local_6
	JMP        L_0bce
	db 90h
L_0b36:
	CALL       F_04d2
	CALL       F_04d2
	MOV        byte ptr [BP + -2h],0h	; local_4
	MOV        DI,0ffffh
	MOV        word ptr [BP + -8h],4aa8h	; local_a
L_0b48:
	MOV        BX,word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BX]
	MOV        AX,0bcf8h
	PUSH       AX
	CALL       SUB_0000_af9e
	MOV        SI,AX
	CMP        SI,-1h
	JZ         L_0ba4
	OR         SI,SI
	JZ         L_0b66
	CMP        byte ptr [SI + 0bcf7h],20h
	JNZ        L_0ba4
L_0b66:
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        AH,AH
	PUSH       AX
	CALL       F_0a54
	MOV        DI,AX
	OR         DI,DI
	JNZ        L_0b96
L_0b75:
	MOV        word ptr [BP + -6h],SI	; local_8
	OR         DI,DI
	JZ         L_0b0f
	CALL       F_09d8
	OR         AX,AX
	JNZ        L_0bb4
	MOV        AX,9420h
	PUSH       AX
	CALL       SUB_0000_58d0
L_0b8a:
	CALL       F_04da
	CALL       F_04d2
	CALL       F_04d2
	JMP        L_0b0f
L_0b96:
	CMP        DI,1h
	JNZ        L_0ba4
	MOV        AX,1h
	MOV        word ptr [BP + -6h],SI	; local_8
	JMP        L_0b2f
	db 90h
L_0ba4:
	ADD        word ptr [BP + -8h],2h	; local_a
	INC        byte ptr [BP + -2h]	; local_4
	CMP        byte ptr [BP + -2h],22h	; local_4
	JNC        L_0b75
	JMP        L_0b48
	db 90h
L_0bb4:
	CALL       F_04da
	MOV        AX,DS:[0bcf6h]
	SHL        AX,1h
	ADD        AX,6h
	PUSH       AX
	CALL       F_07aa
	OR         AX,AX
	JZ         L_0b8a
	MOV        AX,1h
	JMP        L_0b2f
	db 90h
L_0bce:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0b04 ENDP
F_0bd4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        word ptr DS:[0bcdeh],0b21eh
	JMP        L_0bef
	db 90h
L_0be4:
	MOV        AX,90h
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       F_0728
L_0bef:
	MOV        BX,word ptr DS:[0bcdeh]
	MOV        AL,DS:[0bcf4h]
	CMP        byte ptr [BX],AL
	JNZ        L_0be4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       F_0728
	SUB        AX,AX
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       F_0728
L_0c0e:
	PUSH       word ptr DS:[0bcdeh]
	MOV        AX,0bcf8h
	PUSH       AX
	CALL       SUB_0000_af9e
	MOV        SI,AX
	CMP        SI,-1h
	JZ         L_0c34
	OR         SI,SI
	JZ         L_0c2b
	CMP        byte ptr [SI + 0bcf7h],20h
	JNZ        L_0c34
L_0c2b:
	MOV        AX,1h
L_0c2e:
	MOV        word ptr [BP + -2h],SI	; local_4
	JMP        L_0c56
	db 90h
L_0c34:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	CALL       F_0728
	OR         AX,AX
	JNZ        L_0c46
L_0c42:
	SUB        AX,AX
	JMP        L_0c2e
L_0c46:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	CALL       F_0728
	OR         AX,AX
	JNZ        L_0c0e
	JMP        L_0c42
L_0c56:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0bd4 ENDP
F_0c5c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + -4h]	; local_6
L_0c67:
	CALL       F_04da
	CALL       F_093a
	OR         AX,AX
	JZ         L_0c7a
L_0c71:
	MOV        AX,1h
L_0c74:
	MOV        word ptr [BP + -4h],DI	; local_6
	JMP        L_0d3c
L_0c7a:
	CALL       F_04da
L_0c7d:
	CALL       F_04d2
	CALL       F_04d2
	MOV        byte ptr DS:[4af2h],0ffh
	MOV        AX,9440h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_0a2c
	CMP        byte ptr DS:[0bcf8h],0h
	JNZ        L_0ca0
	MOV        AX,9450h
	PUSH       AX
	CALL       SUB_0000_58d0
L_0ca0:
	CMP        byte ptr DS:[0bcf8h],0h
	JZ         L_0c7d
	CALL       F_04d2
	CALL       F_04d2
	MOV        byte ptr [BP + -2h],0h	; local_4
	MOV        DI,0ffffh
	MOV        word ptr [BP + -8h],4aa8h	; local_a
L_0cb9:
	MOV        BX,word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BX]
	MOV        AX,0bcf8h
	PUSH       AX
	CALL       SUB_0000_af9e
	MOV        SI,AX
	CMP        SI,-1h
	JZ         L_0d0e
	OR         SI,SI
	JZ         L_0cd7
	CMP        byte ptr [SI + 0bcf7h],20h
	JNZ        L_0d0e
L_0cd7:
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        AH,AH
	PUSH       AX
	CALL       F_0a54
	MOV        DI,AX
	OR         DI,DI
	JNZ        L_0d00
L_0ce6:
	MOV        word ptr [BP + -6h],SI	; local_8
	OR         DI,DI
	JNZ        L_0cf0
	JMP        L_0c67
L_0cf0:
	CALL       F_0bd4
	OR         AX,AX
	JNZ        L_0d2e
	CALL       F_04da
	CALL       F_096e
	JMP        L_0d34
	db 90h
L_0d00:
	CMP        DI,1h
	JNZ        L_0d0e
	MOV        AX,1h
	MOV        word ptr [BP + -6h],SI	; local_8
	JMP        L_0c74
L_0d0e:
	ADD        word ptr [BP + -8h],2h	; local_a
	INC        byte ptr [BP + -2h]	; local_4
	CMP        byte ptr [BP + -2h],22h	; local_4
	JNC        L_0ce6
	JMP        L_0cb9
	db 90h
L_0d1e:
	CALL       F_04da
	CALL       F_04d2
	CALL       F_04d2
	CALL       F_0b04
	JMP        L_0c74
	db 90h
L_0d2e:
	CALL       F_04da
	CALL       F_0960
L_0d34:
	OR         AX,AX
	JZ         L_0d1e
	JMP        L_0c71
	db 90h
L_0d3c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0c5c ENDP
F_0d42 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        word ptr [BP + -2h],0h	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	LEA        AX,[BP + -4h]	; local_6
	PUSH       AX
	CALL       SUB_0000_44f6
	MOV        BL,byte ptr DS:[5893h]
	SUB        BH,BH
	SHL        BX,1h
	SHL        BX,1h
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        DX,word ptr [BP + -2h]	; local_4
	OR         word ptr [BX + 5bd6h],AX
	OR         word ptr [BX + 5bd8h],DX
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0d42 ENDP
F_0d7a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        word ptr [BP + -2h],0h	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	LEA        AX,[BP + -4h]	; local_6
	PUSH       AX
	CALL       SUB_0000_44f6
	MOV        BL,byte ptr DS:[5893h]
	SUB        BH,BH
	SHL        BX,1h
	SHL        BX,1h
	MOV        AX,word ptr [BX + 5bd6h]
	MOV        DX,word ptr [BX + 5bd8h]
	AND        AX,word ptr [BP + -4h]	; local_6
	AND        DX,word ptr [BP + -2h]	; local_4
	OR         DX,AX
	JZ         L_0db6
	MOV        AX,1h
	JMP        L_0db8
	db 90h
L_0db6:
	SUB        AX,AX
L_0db8:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0d7a ENDP
F_0dbe PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,DS:[4aeeh]
	SUB        AH,AH
	CMP        AX,85h
	JZ         L_0de4
	CMP        AX,86h
	JZ         L_0e0e
	CMP        AX,8ch
	JZ         L_0e1c
	CMP        AX,0feh
	JZ         L_0e46
L_0dda:
	SUB        AL,AL
	MOV        DS:[4aeeh],AL
	MOV        DS:[4aefh],AL
	JMP        L_0dfc
L_0de4:
	MOV        BL,byte ptr DS:[4aefh]
	INC        word ptr DS:[4aefh]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        byte ptr [BX + 0bce0h],AL
	CMP        byte ptr DS:[4aefh],3h
	JZ         L_0e02
L_0dfc:
	SUB        AX,AX
	JMP        L_0e74
	db 90h
	db 90h
L_0e02:
	CALL       F_05b6
	OR         AX,AX
	JZ         L_0dda
	MOV        AX,1h
	JMP        L_0e74
L_0e0e:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	AND        AX,7fh
	PUSH       AX
	CALL       F_0682
	JMP        L_0dda
L_0e1c:
	SUB        AL,AL
	MOV        DS:[4aeeh],AL
	MOV        DS:[4aefh],AL
	PUSH       word ptr DS:[0bcdch]
	CALL       F_0d7a
	OR         AX,AX
	JZ         L_0dfc
	CMP        byte ptr [BP + 4h],0ffh	; param_1
	JNZ        L_0e3a
	CALL       F_0b04
	JMP        L_0e74
L_0e3a:
	MOV        AL,byte ptr [BP + 4h]	; param_1
L_0e3d:
	MOV        DS:[0bcf4h],AL
	CALL       F_0c5c
	JMP        L_0e74
	db 90h
L_0e46:
	MOV        BL,byte ptr DS:[4aefh]
	INC        word ptr DS:[4aefh]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        byte ptr [BX + 0bce0h],AL
	CMP        byte ptr DS:[4aefh],2h
	JNZ        L_0dfc
	SUB        AL,AL
	MOV        DS:[4aeeh],AL
	MOV        DS:[4aefh],AL
	MOV        AL,DS:[5888h]
	CMP        byte ptr DS:[0bce0h],AL
	JA         L_0dfc
	MOV        AL,DS:[0bce1h]
	JMP        L_0e3d
L_0e74:
	POP        BP
	RET        2h
	; Func
F_0dbe ENDP
F_0e78 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h	; local_a
	CALL       F_04da
	CALL       F_04e2
	MOV        AX,9468h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,947ch
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_0a2c
	SUB        AL,AL
	MOV        DS:[4aefh],AL
	MOV        DS:[4aeeh],AL
	CMP        byte ptr DS:[0bcf8h],AL
	JNZ        L_0eb0
	MOV        AX,948ch
	JMP        L_0f28
	db 90h
L_0eb0:
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -8h],AX	; local_a
	JNC        L_0f25
	MOV        DI,word ptr [BP + -8h]	; local_a
	MOV        CL,5h
	SHL        DI,CL
L_0ec1:
	MOV        word ptr [BP + -0ah],0h	; local_c
	MOV        CX,2h
	PUSH       SI
	PUSH       DI
	LEA        SI,[DI + 55a8h]
	LEA        DI,[BP + -6h]	; local_8
	PUSH       SS
	POP        ES
	REP MOVSW
	POP        DI
	POP        SI
	MOV        word ptr [BP + -0ah],4h	; local_c
	MOV        byte ptr [BP + -2h],0h	; local_4
	LEA        AX,[BP + -6h]	; local_8
	PUSH       AX
	MOV        AX,0bcf8h
	PUSH       AX
	CALL       SUB_0000_af9e
	MOV        SI,AX
	CMP        SI,-1h
	JZ         L_0f12
	OR         SI,SI
	JZ         L_0efe
	CMP        byte ptr [SI + 0bcf7h],20h
	JNZ        L_0f12
L_0efe:
	PUSH       word ptr DS:[0bcdch]
	CALL       F_0d42
	MOV        AX,94a0h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -0ch],SI	; local_e
	JMP        L_0f2c
	db 90h
L_0f12:
	ADD        DI,20h
	INC        word ptr [BP + -8h]	; local_a
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -8h],AX	; local_a
	JC         L_0ec1
	MOV        word ptr [BP + -0ch],SI	; local_e
L_0f25:
	MOV        AX,94b0h
L_0f28:
	PUSH       AX
	CALL       SUB_0000_58d0
L_0f2c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0e78 ENDP
F_0f32 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	CMP        byte ptr DS:[4aeeh],0h
	JZ         L_0f4c
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	PUSH       AX
	CALL       F_0dbe
	JMP        L_1114
L_0f4c:
	MOV        byte ptr DS:[4aefh],0h
	CMP        byte ptr [BP + 4h],0a2h	; param_1
	JNZ        L_0f64
	CMP        byte ptr DS:[4af4h],0a2h
	JNZ        L_0f64
L_0f5e:
	SUB        AX,AX
	JMP        L_1114
	db 90h
L_0f64:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	CMP        AX,89h
	JZ         L_0fd8
	JBE        L_0f73
	JMP        L_10ac
L_0f73:
	SUB        AX,81h
	CMP        AX,7h
	JBE        L_0f7e
	JMP        L_10ce
L_0f7e:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0d01ch]
	db 0E8h
	db 5Bh
	db 0F8h
	db 0EBh
	db 0D3h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 0E9h
	db 82h
	db 01h
	db 2Bh
	db 0F6h
	db 0E8h
	db 0F9h
	db 89h
	db 0E8h
	db 44h
	db 4Eh
	db 0Bh
	db 0C0h
	db 74h
	db 08h
	db 89h
	db 76h
	db 0FCh
	db 0E8h
	db 0F2h
	db 4Bh
	db 0EBh
	db 0B8h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0CDh
	db 51h
	db 46h
	db 83h
	db 0FEh
	db 1Ch
	db 7Dh
	db 0EBh
	db 0EBh
	db 0DFh
	db 90h
	db 0E8h
	db 51h
	db 0F8h
	db 0E9h
	db 58h
	db 01h
	db 0A1h
	db 0DEh
	db 0BCh
	db 89h
	db 46h
	db 0FEh
	db 0E8h
	db 0F9h
	db 0F7h
	db 0Bh
	db 0C0h
	db 75h
	db 0C3h
	db 8Bh
	db 46h
	db 0FEh
	db 0A3h
	db 0DEh
	db 0BCh
	db 0EBh
	db 8Dh
	db 90h
	db 0E8h
	db 0A3h
	db 0FEh
	db 0EBh
	db 87h
	db 90h
L_0fd8:
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
	JMP        L_0f5e
L_0fea:
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7fb6
	JMP        L_0f5e
L_0ff8:
	CALL       SUB_0000_bb56
	JMP        L_0f5e
L_0ffe:
	XOR        byte ptr DS:[4af0h],80h
	JMP        L_0f5e
L_1006:
	CALL       F_04e2
	CALL       F_0b04
	JMP        L_1114
	db 90h
L_1010:
	CALL       SUB_0000_66ec
	JMP        L_0f5e
L_1016:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        DS:[4aeeh],AL
	JMP        L_0f5e
	db 90h
L_1020:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        DS:[0bcf4h],AL
	CALL       F_0c5c
	JMP        L_1114
L_102c:
	INC        SI
	MOV        AL,byte ptr [SI + -1h]
	SUB        AH,AH
	OR         AL,80h
	PUSH       AX
	CALL       F_0574
L_1038:
	CMP        byte ptr [SI],0h
	JNZ        L_102c
	MOV        word ptr [BP + -6h],SI	; local_8
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	MOV        SI,AX
	MOV        BX,SI
	SHL        BX,1h
	MOV        BX,word ptr [BX + 24e8h]
	CMP        byte ptr [BX],AH
	JNZ        L_105a
	PUSH       SI
	CALL       F_0574
	JMP        L_0f5e
L_105a:
	MOV        byte ptr DS:[4af5h],1h
	JMP        L_0f5e
L_1062:
	OR         byte ptr [BP + 4h],80h	; param_1
	CMP        byte ptr [BP + 4h],8dh	; param_1
	JNZ        L_1070
	MOV        byte ptr [BP + 4h],8ah	; param_1
L_1070:
	MOV        AL,DS:[4af0h]
	AND        byte ptr [BP + 4h],AL	; param_1
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        DS:[4af4h],AL
	CMP        byte ptr DS:[4af5h],0h
	JZ         L_108a
	MOV        AX,0a0h
	PUSH       AX
	CALL       F_0574
L_108a:
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SUB        AH,AH
	PUSH       AX
	CALL       F_0574
	MOV        byte ptr DS:[4af5h],0h
	JMP        L_0f5e
	db 90h
	db 06h
	db 0CFh
	db 0Ch
	db 0CFh
	db 12h
	db 0CFh
	db 36h
	db 0CFh
	db 96h
	db 0CFh
	db 96h
	db 0CFh
	db 3Ch
	db 0CFh
	db 52h
	db 0CFh
L_10ac:
	CMP        AX,8eh
	JNZ        L_10b4
	JMP        L_0ffe
L_10b4:
	JA         L_10ea
	CMP        AX,8ah
	JNZ        L_10be
	JMP        L_0fea
L_10be:
	CMP        AX,8bh
	JNZ        L_10c6
	JMP        L_0ff8
L_10c6:
	CMP        AX,8ch
	JNZ        L_10ce
	JMP        L_1016
L_10ce:
	CMP        byte ptr [BP + 4h],81h	; param_1
	JNC        L_1062
	MOV        AX,0a0h
	PUSH       AX
	CALL       F_0574
	MOV        BL,byte ptr [BP + 4h]	; param_1
	SUB        BH,BH
	SHL        BX,1h
	MOV        SI,word ptr [BX + 24e8h]
	JMP        L_1038
	db 90h
L_10ea:
	CMP        AX,9fh
	JA         L_1102
	CMP        AX,91h
	JC         L_10f7
	JMP        L_1020
L_10f7:
	CMP        AX,8fh
	JNZ        L_10ff
	JMP        L_1010
L_10ff:
	JMP        L_10ce
	db 90h
L_1102:
	CMP        AX,0feh
	JNZ        L_110a
	JMP        L_1016
L_110a:
	CMP        AX,0ffh
	JNZ        L_1112
	JMP        L_1006
L_1112:
	JMP        L_10ce
L_1114:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0f32 ENDP
F_111c PROC NEAR
	MOV        AX,94c4h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,1h
	PUSH       AX
	CALL       F_07aa
	OR         AX,AX
	JZ         L_1134
L_112e:
	MOV        AX,1h
	JMP        L_117f
	db 90h
L_1134:
	CALL       F_04d2
	CALL       F_04d2
	PUSH       word ptr DS:[0bcdch]
	CALL       F_0d7a
	OR         AX,AX
	JNZ        L_1166
	CALL       SUB_0000_60d6
	PUSH       AX
	CALL       SUB_0000_60fe
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JZ         L_117d
	MOV        AX,94ceh
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	JMP        L_116c
	db 90h
L_1166:
	CALL       F_04da
	MOV        AX,2h
L_116c:
	PUSH       AX
	CALL       F_07aa
	OR         AX,AX
	JNZ        L_112e
	CALL       F_04da
	CALL       F_04d2
	CALL       F_04d2
L_117d:
	SUB        AX,AX
L_117f:
	RET
	; Func
F_111c ENDP
F_1180 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	CMP        byte ptr DS:[5958h],0h
	JZ         L_1191
	JMP        L_1278
L_1191:
	MOV        AX,94dch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,320h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	CALL       SUB_0000_842e
	CALL       SUB_0000_60d6
	PUSH       AX
	CALL       SUB_0000_60fe
	MOV        AL,DS:[57ach]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[57adh]
	SUB        CH,CH
	OR         AX,CX
	MOV        CL,byte ptr DS:[57aeh]
	OR         AX,CX
	JZ         L_1210
L_11c7:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JZ         L_11e2
	CMP        AX,1h
	JZ         L_11f8
	CMP        AX,2h
	JZ         L_1204
	JMP        L_1278
L_11e2:
	CMP        byte ptr DS:[57ach],0h
	JZ         L_11c7
	MOV        AX,57ach
L_11ec:
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7fb6
	JMP        L_1278
	db 90h
L_11f8:
	CMP        byte ptr DS:[57adh],0h
	JZ         L_11c7
	MOV        AX,57adh
	JMP        L_11ec
L_1204:
	CMP        byte ptr DS:[57aeh],0h
	JZ         L_11c7
	MOV        AX,57aeh
	JMP        L_11ec
L_1210:
	MOV        SI,2fh
L_1213:
	CMP        byte ptr [SI + 57c0h],0h
	JZ         L_122c
	MOV        AX,SI
	ADD        AX,57c0h
L_121f:
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7fb6
	MOV        word ptr [BP + -2h],SI	; local_4
	JMP        L_1278
L_122c:
	DEC        SI
	JNS        L_1213
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        SI,7h
L_1235:
	CMP        byte ptr [SI + 5828h],0h
	JZ         L_1244
	MOV        AX,SI
	ADD        AX,5828h
	JMP        L_121f
	db 90h
L_1244:
	DEC        SI
	JNS        L_1235
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        SI,7h
L_124d:
	CMP        byte ptr [SI + 5820h],0h
	JZ         L_125c
	MOV        AX,SI
	ADD        AX,5820h
	JMP        L_121f
	db 90h
L_125c:
	DEC        SI
	JNS        L_124d
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        AX,57aah
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_6112
	PUSH       AX
	CALL       SUB_0000_7fd4
	CALL       SUB_0000_6980
L_1278:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_1180 ENDP
F_127e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	DEC        AX
	MOV        CL,3h
	SHR        AX,CL
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 4aa0h]
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_65ee
	MOV        SI,0b21eh
	LODSW
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        word ptr [BP + -8h],1h	; local_a
	MOV        DI,AX
	MOV        DX,word ptr [BP + 4h]	; param_1
	MOV        CX,word ptr [BP + -8h]	; local_a
	JMP        L_12c8
	db 90h
L_12c0:
	CMP        CX,DI
	JG         L_12d0
	ADD        SI,2h
	INC        CX
L_12c8:
	ADD        SI,2h
	CMP        word ptr [SI + -2h],DX
	JNZ        L_12c0
L_12d0:
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        word ptr [BP + -8h],CX	; local_a
	MOV        BX,SI
	MOV        AX,word ptr [BX]
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	PUSH       word ptr [BX + 4aa0h]
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,400h
	PUSH       AX
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       SUB_0000_65ee
	CALL       F_111c
	OR         AX,AX
	JNZ        L_1305
	CALL       F_0b04
	OR         AX,AX
	JNZ        L_1305
	CALL       F_0a3c
L_1305:
	CALL       F_1180
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
F_127e ENDP
_TEXT ENDS
END
