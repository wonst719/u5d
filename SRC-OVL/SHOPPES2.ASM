_TEXT SEGMENT BYTE 'CODE'
ORG 34dah
SUB_0000_34da:
ORG 3670h
SUB_0000_3670:
ORG 385eh
SUB_0000_385e:
ORG 9dfah
SUB_0000_9dfa:
ORG 5d34h
SUB_0000_5d34:
ORG 6222h
SUB_0000_6222:
ORG 7730h
SUB_0000_7730:
ORG 448ch
SUB_0000_448c:
ORG 5d56h
SUB_0000_5d56:
ORG 9dd6h
SUB_0000_9dd6:
ORG 2262h
SUB_0000_2262:
ORG 21c0h
SUB_0000_21c0:
ORG 3eb2h
SUB_0000_3eb2:
ORG 59beh
SUB_0000_59be:
ORG 5d74h
SUB_0000_5d74:
ORG 593ch
SUB_0000_593c:
ORG 8d3eh
SUB_0000_8d3e:
ORG 4720h
SUB_0000_4720:
ORG 9e12h
SUB_0000_9e12:
ORG 9e06h
SUB_0000_9e06:
ORG 3d32h
SUB_0000_3d32:
ORG 9d8eh
SUB_0000_9d8e:
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
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        DS:[0b118h],AX
	MOV        DS:[0bd1ch],AX
	MOV        DS:[0bd1ah],AX
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0054
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        SI,55b3h
	MOV        DI,word ptr DS:[0bd1ah]
	MOV        DX,word ptr DS:[0bd1ch]
	MOV        CX,word ptr [BP + -2h]	; local_4
L_0030:
	CMP        byte ptr [SI],44h
	JZ         L_003e
	INC        DX
	INC        DI
	MOV        AX,word ptr [BP + 4h]	; param_1
	ADD        word ptr DS:[0b118h],AX
L_003e:
	ADD        SI,20h
	INC        CX
	MOV        AX,CX
	CMP        AX,word ptr [BP + -4h]	; local_6
	JNZ        L_0030
	MOV        word ptr DS:[0bd1ah],DI
	MOV        word ptr DS:[0bd1ch],DX
	MOV        word ptr [BP + -2h],CX	; local_4
L_0054:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0000 ENDP
F_006a PROC NEAR
	MOV        AX,DS:[0bd1ch]
	CMP        AX,2h
	JZ         L_0088
	CMP        AX,3h
	JZ         L_0092
	CMP        AX,4h
	JZ         L_0098
	CMP        AX,5h
	JZ         L_009e
	CMP        AX,6h
	JZ         L_00a4
	JMP        L_00aa
L_0088:
	MOV        AX,9aa8h
L_008b:
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_00aa
	db 90h
L_0092:
	MOV        AX,9aach
	JMP        L_008b
	db 90h
L_0098:
	MOV        AX,9ab2h
	JMP        L_008b
	db 90h
L_009e:
	MOV        AX,9ab8h
	JMP        L_008b
	db 90h
L_00a4:
	MOV        AX,9abeh
	JMP        L_008b
	db 90h
L_00aa:
	RET
	db 90h
	; Func
F_006a ENDP
F_00ac PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AL,0ffh
	MOV        DS:[587bh],AL
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b1h],0bh
	JNZ        L_00d0
	MOV        AX,9ac2h
	JMP        L_00d3
	db 90h
L_00d0:
	MOV        AX,9ac6h
L_00d3:
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_00ac ENDP
F_00dc PROC NEAR
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,9aceh
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0b118h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9adch
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_006a
	MOV        AX,9aech
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_00ac
	MOV        AX,2eh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,DS:[57aah]
	CMP        word ptr DS:[0b118h],AX
	JLE        L_0140
	MOV        AX,9af6h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0aafeh]
	CALL       SUB_0000_3670
	MOV        AX,2eh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,1h
	JMP        L_01d1
	db 90h
L_0140:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_9dfa
	CMP        word ptr DS:[0bd1ah],0h
	JZ         L_01c4
	MOV        AX,57a8h
	PUSH       AX
	PUSH       word ptr DS:[0bd1ah]
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_5d34
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_6222
	MOV        BX,AX
	CMP        byte ptr [BX],95h
	JNZ        L_0194
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_6222
	MOV        BX,AX
	MOV        byte ptr [BX],9bh
	MOV        word ptr DS:[0bd1eh],9bh
L_018e:
	CALL       SUB_0000_7730
	JMP        L_01c8
	db 90h
L_0194:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_6222
	MOV        BX,AX
	CMP        byte ptr [BX],95h
	JNZ        L_01c8
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_6222
	MOV        BX,AX
	MOV        byte ptr [BX],9ah
	MOV        word ptr DS:[0bd1eh],9ah
	JMP        L_018e
L_01c4:
	INC        word ptr DS:[0bd20h]
L_01c8:
	MOV        AX,9b16h
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
L_01d1:
	RET
	; Func
F_00dc ENDP
F_01d2 PROC NEAR
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 4c1eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	PUSH       word ptr [BX + 4c36h]
	CALL       F_0000
	CALL       F_00dc
	RET
	db 90h
	; Func
F_01d2 ENDP
F_01f4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 4c24h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	CMP        word ptr DS:[0bd20h],3h
	JNZ        L_026f
	MOV        AX,9b22h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_00ac
	MOV        AX,9b38h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0aafeh]
	CALL       SUB_0000_3670
	MOV        AX,9b42h
	PUSH       AX
	CALL       SUB_0000_3670
L_0230:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,59h
	JNZ        L_0246
	MOV        AX,9b6ch
	PUSH       AX
	CALL       SUB_0000_3670
L_0241:
	SUB        AX,AX
	JMP        L_037b
L_0246:
	CMP        byte ptr [BP + -2h],4eh	; local_4
	JNZ        L_0263
	MOV        AX,9b72h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        byte ptr DS:[5957h],19h
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5d56
L_0263:
	CMP        byte ptr [BP + -2h],59h	; local_4
	JZ         L_026f
	CMP        byte ptr [BP + -2h],4eh	; local_4
	JNZ        L_0230
L_026f:
	MOV        AX,1h
	PUSH       AX
	CALL       F_0000
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	CMP        byte ptr [BX + 4c24h],57h
	JZ         L_0286
	JMP        L_0372
L_0286:
	MOV        AX,9b76h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_00ac
	MOV        AX,9b88h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9b8ch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9b9eh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9bb0h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9bc2h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9bd4h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9be6h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9bfah
	PUSH       AX
	CALL       SUB_0000_3670
L_02c8:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,20h
	JNZ        L_02f6
L_02d2:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	CMP        byte ptr [BP + -2h],20h	; local_4
	JZ         L_02e9
	JMP        L_0241
L_02e9:
	MOV        AX,1413h
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        AX,2h
	JMP        L_037b
L_02f6:
	CMP        byte ptr [BP + -2h],41h	; local_4
	JC         L_02c8
	CMP        byte ptr [BP + -2h],46h	; local_4
	JA         L_02c8
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,9c08h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_00ac
	MOV        AX,2eh
	PUSH       AX
	CALL       SUB_0000_34da
	SUB        byte ptr [BP + -2h],41h	; local_4
	MOV        BL,byte ptr [BP + -2h]	; local_4
	SUB        BH,BH
	SHL        BX,1h
	MOV        AX,DS:[57aah]
	CMP        word ptr [BX + 4c48h],AX
	JLE        L_0352
	MOV        AX,9c20h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0aafeh]
	CALL       SUB_0000_3670
	MOV        AX,2eh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,1h
	JMP        L_037b
	db 90h
L_0352:
	MOV        BL,byte ptr [BP + -2h]	; local_4
	SUB        BH,BH
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4c48h]
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_9dfa
	INC        word ptr DS:[0bd20h]
	MOV        AX,9c40h
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_02d2
L_0372:
	MOV        word ptr DS:[0bd1ah],0h
	CALL       F_00dc
L_037b:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_01f4 ENDP
F_0380 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 4c2ah]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4c54h]
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b6h]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	SUB        DX,DX
	SUB        AX,64h
	SBB        DX,DX
	NEG        AX
	ADC        DX,0h
	NEG        DX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_2262
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_21c0
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da
	SUB        AX,AX
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_3eb2
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 4c66h]
	CALL       SUB_0000_9dd6
	MOV        AX,9c4ah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_59be
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JNZ        L_0430
	MOV        AX,9c6ah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,2h
	JMP        L_0500
	db 90h
L_0430:
	CMP        word ptr [BP + -4h],0h	; local_6
	JNZ        L_0439
	JMP        L_04f4
L_0439:
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        SI,word ptr [BP + -4h]	; local_6
L_043f:
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JL         L_0474
	MOV        AX,57aah
	PUSH       AX
	PUSH       word ptr DS:[0b118h]
	CALL       SUB_0000_5d74
	MOV        AX,57a8h
	PUSH       AX
	MOV        AX,19h
	PUSH       AX
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_5d34
	CMP        word ptr DS:[57a8h],270fh
	JNZ        L_04d0
L_046a:
	MOV        word ptr [BP + -2h],DI	; local_4
	MOV        word ptr [BP + -4h],SI	; local_6
	JMP        L_04f4
	db 90h
L_0474:
	SUB        DI,SI
	MOV        AX,9c76h
	PUSH       AX
	CALL       SUB_0000_3670
	OR         DI,DI
	JNZ        L_04d6
	CMP        word ptr DS:[57a8h],3h
	JGE        L_04b2
	MOV        AX,57a8h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3eb2
	INC        AX
	PUSH       AX
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_5d34
	MOV        AX,143fh
	PUSH       AX
	CALL       SUB_0000_9dd6
L_04a6:
	MOV        AX,1h
L_04a9:
	MOV        word ptr [BP + -2h],DI	; local_4
	MOV        word ptr [BP + -4h],SI	; local_6
	JMP        L_0500
	db 90h
L_04b2:
	MOV        AX,9c7ah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9ca4h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0aafeh]
	CALL       SUB_0000_3670
	MOV        AX,9cach
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_04a6
L_04d0:
	DEC        SI
	JZ         L_046a
	JMP        L_043f
L_04d6:
	MOV        AX,9cb0h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       DI
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9ccah
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	JMP        L_04a9
L_04f4:
	MOV        AX,9cd0h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_9dfa
	SUB        AX,AX
L_0500:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0380 ENDP
F_0508 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 4c30h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,9efch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        DI,word ptr [BP + -2h]	; local_4
L_052a:
	MOV        AX,9f00h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_00ac
	MOV        AX,9f24h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0bcf8h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_593c
	MOV        AX,9f36h
	PUSH       AX
	CALL       SUB_0000_3670
	CMP        byte ptr DS:[0bcf8h],0h
	JNZ        L_055c
L_0554:
	SUB        AX,AX
L_0556:
	MOV        word ptr [BP + -2h],DI	; local_4
	JMP        L_065e
L_055c:
	SUB        DI,DI
	MOV        word ptr [BP + -6h],0ffffh	; local_8
	MOV        word ptr [BP + -8h],4c74h	; local_a
L_0568:
	MOV        BX,word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BX]
	MOV        AX,0bcf8h
	PUSH       AX
	CALL       SUB_0000_8d3e
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0585
	OR         SI,SI
	JLE        L_059a
	CMP        byte ptr [SI + 0bcf7h],20h
	JNZ        L_059a
L_0585:
	MOV        word ptr [BP + -6h],DI	; local_8
L_0588:
	MOV        word ptr [BP + -4h],SI	; local_6
	CMP        word ptr [BP + -6h],-1h	; local_8
	JNZ        L_05a6
	MOV        AX,9f3ah
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_052a
L_059a:
	ADD        word ptr [BP + -8h],2h	; local_a
	INC        DI
	CMP        DI,1ah
	JGE        L_0588
	JMP        L_0568
L_05a6:
	MOV        BX,word ptr [BP + -6h]	; local_8
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4d10h]
	MOV        DS:[0b118h],AX
	MOV        AX,134eh
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        AX,9f5ch
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        SI,SI
L_05c2:
	MOV        AX,SI
	CMP        AX,4eh
	JZ         L_05d3
	CALL       SUB_0000_448c
	MOV        SI,AX
	CMP        AX,59h
	JNZ        L_05c2
L_05d3:
	MOV        DI,SI
	MOV        AX,DI
	CMP        AX,4eh
	JNZ        L_05e6
	MOV        AX,9f6ch
L_05df:
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0554
L_05e6:
	MOV        AX,9f72h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,DS:[57aah]
	CMP        word ptr DS:[0b118h],AX
	JLE        L_060e
	MOV        AX,9f78h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_00ac
	MOV        AX,146ah
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        AX,1h
	JMP        L_0556
	db 90h
L_060e:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_4720
	MOV        BX,word ptr [BP + -6h]	; local_8
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4ca8h]
	MOV        DS:[0ab00h],AX
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        BL,byte ptr [BX + 4cdch]
	SUB        BH,BH
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4cf6h]
	MOV        DS:[0ac62h],AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_3eb2
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 4d44h]
	CALL       SUB_0000_9dd6
	MOV        AX,9f82h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0aafeh]
	CALL       SUB_0000_3670
	MOV        AX,9f8ah
	JMP        L_05df
L_065e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0508 ENDP
F_0664 PROC NEAR
	PUSH       word ptr DS:[0bd18h]
	CALL       SUB_0000_9e12
	RET
	; Func
F_0664 ENDP
F_066c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 4d4ch]
	MOV        DS:[0bd16h],AL
	SUB        AX,AX
	MOV        DS:[0bd18h],AX
	MOV        DS:[0bd1eh],AX
	CALL       SUB_0000_9e06
L_0688:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,4eh
	JZ         L_0696
	CMP        AL,20h
	JNZ        L_06a4
L_0696:
	MOV        AX,9f8eh
L_0699:
	PUSH       AX
	CALL       SUB_0000_3670
L_069d:
	CALL       F_0664
	JMP        L_07dc
	db 90h
L_06a4:
	CMP        byte ptr [BP + -2h],59h	; local_4
	JNZ        L_0688
	MOV        AX,9f92h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 4d56h]
	CALL       SUB_0000_9dd6
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	CALL       SUB_0000_3d32
	CMP        AX,0eh
	JLE        L_06dd
	MOV        AX,0ah
L_06d9:
	PUSH       AX
	CALL       SUB_0000_34da
L_06dd:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL	; local_4
	MOV        word ptr [BP + -4h],0h	; local_6
	CMP        AL,20h
	JZ         L_069d
	CMP        AL,1bh
	JZ         L_069d
	CMP        AL,0dh
	JZ         L_069d
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	CMP        byte ptr [BX + 4c1eh],AL
	JNZ        L_070a
	CALL       F_01d2
	OR         AX,AX
	JZ         L_070a
	JMP        L_07dc
L_070a:
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + 4c24h],AL
	JNZ        L_0727
	CALL       F_01f4
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,1h
	JNZ        L_0727
	JMP        L_07dc
L_0727:
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + 4c2ah],AL
	JNZ        L_0747
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0380
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,1h
	JNZ        L_0747
	JMP        L_07dc
L_0747:
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + 4c30h],AL
	JNZ        L_0767
	CMP        word ptr DS:[0bd18h],0h
	JNZ        L_0760
	JMP        L_06dd
L_0760:
	CALL       F_0508
	OR         AX,AX
	JNZ        L_07dc
L_0767:
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	MOV        AL,byte ptr [BP + -2h]	; local_4
	CMP        byte ptr [BX + 4c1eh],AL
	JZ         L_078b
	CMP        byte ptr [BX + 4c24h],AL
	JZ         L_078b
	CMP        byte ptr [BX + 4c2ah],AL
	JZ         L_078b
	CMP        byte ptr [BX + 4c30h],AL
	JZ         L_078b
	JMP        L_06dd
L_078b:
	CMP        word ptr [BP + -4h],2h	; local_6
	JZ         L_0797
	MOV        word ptr DS:[0bd18h],1h
L_0797:
	CALL       SUB_0000_4720
	MOV        AX,9f9ah
	PUSH       AX
	CALL       SUB_0000_3670
L_07a1:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,4eh
	JNZ        L_07b2
	MOV        AX,9fb6h
	JMP        L_0699
	db 90h
L_07b2:
	CMP        byte ptr [BP + -2h],59h	; local_4
	JNZ        L_07a1
	MOV        AX,9fbah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BL,byte ptr DS:[0bd16h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 4d5eh]
	CALL       SUB_0000_9dd6
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,20h
	JMP        L_06d9
	db 90h
L_07dc:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_066c ENDP
F_07e2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,DS:[57aah]
	CMP        word ptr [BP + 4h],AX	; param_1
	JLE        L_0806
	MOV        AX,198eh
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        AX,9fc2h
	PUSH       AX
	CALL       SUB_0000_9d8e
	MOV        word ptr DS:[0bd22h],1h
	SUB        AX,AX
	JMP        L_0809
	db 90h
L_0806:
	MOV        AX,1h
L_0809:
	POP        BP
	RET        2h
	db 90h
	; Func
F_07e2 ENDP
F_080e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        word ptr [BP + 8h],0h	; param_3
	JZ         L_0833
	MOV        AX,19abh
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 4d76h]
	MOV        DS:[5953h],AL
	MOV        AL,byte ptr [BX + 4d7ah]
	MOV        DS:[5954h],AL
L_0833:
	CMP        word ptr [BP + 6h],0h	; param_2
	JZ         L_0849
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	MOV        word ptr DS:[0bd24h],1h
	CALL       SUB_0000_9dfa
L_0849:
	CALL       SUB_0000_4720
	MOV        AX,19dah
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b1h],46h
	JNZ        L_0866
	MOV        AX,9fcch
	JMP        L_0869
L_0866:
	MOV        AX,9fd4h
L_0869:
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9fd8h
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_087c
L_0876:
	CMP        byte ptr [BP + -2h],4eh	; local_4
	JZ         L_0886
L_087c:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,59h
	JNZ        L_0876
L_0886:
	CMP        byte ptr [BP + -2h],59h	; local_4
	JNZ        L_0898
	MOV        AX,9fdch
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	JMP        L_08a2
	db 90h
L_0898:
	MOV        AX,9fe0h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,1h
L_08a2:
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_080e ENDP
F_08a8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55b6h
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        DI,word ptr [BP + 4h]	; param_1
L_08c5:
	MOV        AX,18ebh
	PUSH       AX
	CALL       SUB_0000_9dd6
	CALL       SUB_0000_448c
	CMP        AX,1bh
	JNZ        L_08d7
	JMP        L_0aa6
L_08d7:
	CMP        AX,20h
	JNZ        L_08df
	JMP        L_0aa6
L_08df:
	CMP        AX,46h
	JZ         L_08f0
	CMP        AX,53h
	JNZ        L_08ec
	JMP        L_09d4
L_08ec:
	JMP        L_0aa9
	db 90h
L_08f0:
	MOV        AX,9fe4h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        SI,1h
	TEST       byte ptr DS:[6605h],0c0h
	JZ         L_0940
	MOV        AX,19f2h
	PUSH       AX
	CALL       SUB_0000_9dd6
	JMP        L_0910
L_090a:
	CMP        byte ptr [BP + -4h],4eh	; local_6
	JZ         L_091a
L_0910:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -4h],AL	; local_6
	CMP        AL,59h
	JNZ        L_090a
L_091a:
	CMP        byte ptr [BP + -4h],59h	; local_6
	JNZ        L_0932
	MOV        AX,9fe8h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,2710h
	PUSH       AX
	CALL       F_07e2
	JMP        L_0aa9
	db 90h
L_0932:
	MOV        AX,9fech
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       DI
	CALL       F_08a8
	JMP        L_0aa9
L_0940:
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4d66h]
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	SUB        DX,DX
	SUB        AX,64h
	SBB        DX,DX
	NEG        AX
	ADC        DX,0h
	NEG        DX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_2262
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_21c0
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,183eh
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        AX,1a50h
	PUSH       AX
	CALL       SUB_0000_9dd6
	JMP        L_0998
L_0992:
	CMP        byte ptr [BP + -4h],4eh	; local_6
	JZ         L_09a2
L_0998:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -4h],AL	; local_6
	CMP        AL,59h
	JNZ        L_0992
L_09a2:
	CMP        byte ptr [BP + -4h],59h	; local_6
	JNZ        L_09ca
	MOV        AX,9ff0h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0b118h]
	CALL       F_07e2
	OR         AX,AX
	JNZ        L_09bd
	JMP        L_0ab0
L_09bd:
	MOV        byte ptr DS:[6605h],82h
	MOV        AX,1h
L_09c5:
	PUSH       AX
	JMP        L_0a82
	db 90h
L_09ca:
	MOV        AX,9ff6h
L_09cd:
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0ab0
L_09d4:
	MOV        AX,9ffah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4d6eh]
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	SUB        DX,DX
	SUB        AX,64h
	SBB        DX,DX
	NEG        AX
	ADC        DX,0h
	NEG        DX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_2262
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_21c0
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,188ch
	PUSH       AX
	CALL       SUB_0000_9dd6
	MOV        AX,1a50h
	PUSH       AX
	CALL       SUB_0000_9dd6
	JMP        L_0a34
	db 90h
L_0a2e:
	CMP        byte ptr [BP + -4h],4eh	; local_6
	JZ         L_0a3e
L_0a34:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -4h],AL	; local_6
	CMP        AL,59h
	JNZ        L_0a2e
L_0a3e:
	MOV        SI,1h
	CMP        byte ptr [BP + -4h],59h	; local_6
	JNZ        L_0aa0
	MOV        AX,9ffeh
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[0b118h]
	CALL       F_07e2
	OR         AX,AX
	JZ         L_0ab0
	TEST       byte ptr DS:[6605h],0c0h
	JNZ        L_0a6a
	MOV        byte ptr DS:[6605h],40h
	MOV        AX,SI
	JMP        L_09c5
L_0a6a:
	TEST       byte ptr DS:[6605h],80h
	JZ         L_0a8c
	MOV        AX,193bh
	PUSH       AX
	CALL       SUB_0000_9dd6
	INC        byte ptr DS:[6605h]
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
L_0a82:
	PUSH       AX
	PUSH       DI
	CALL       F_080e
	MOV        SI,AX
	JMP        L_0aa9
	db 90h
L_0a8c:
	TEST       byte ptr DS:[6605h],40h
	JZ         L_0aa9
	MOV        AX,195fh
	PUSH       AX
	CALL       SUB_0000_9dd6
	SUB        AX,AX
	JMP        L_09c5
	db 90h
L_0aa0:
	MOV        AX,0a004h
	JMP        L_09cd
L_0aa6:
	MOV        SI,1h
L_0aa9:
	OR         SI,SI
	JNZ        L_0ab0
	JMP        L_08c5
L_0ab0:
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_08a8 ENDP
F_0abc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
	MOV        word ptr DS:[0bd22h],SI
	MOV        word ptr DS:[0bd24h],SI
	CALL       SUB_0000_9e06
	MOV        DI,word ptr [BP + 4h]	; param_1
L_0ad4:
	CALL       SUB_0000_448c
	CMP        AX,20h
	JZ         L_0afa
	CMP        AX,4eh
	JZ         L_0afa
	CMP        AX,59h
	JNZ        L_0af4
	MOV        AX,0a008h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       DI
	CALL       F_08a8
L_0af1:
	MOV        SI,1h
L_0af4:
	OR         SI,SI
	JNZ        L_0b04
	JMP        L_0ad4
L_0afa:
	MOV        AX,0a00ch
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0af1
	db 90h
L_0b04:
	MOV        word ptr [BP + -2h],SI	; local_4
	CMP        word ptr DS:[0bd22h],0h
	JNZ        L_0b15
	PUSH       word ptr DS:[0bd24h]
	CALL       SUB_0000_9e12
L_0b15:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	db 00h
	db 00h
F_0abc ENDP
_TEXT ENDS
END
