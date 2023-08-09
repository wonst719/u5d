_TEXT SEGMENT BYTE 'CODE'
ORG 0ca18h
SUB_0000_ca18:
ORG 0cdach
SUB_0000_cdac:
ORG 0f9bah
SUB_0000_f9ba:
ORG 0dc7ah
SUB_0000_dc7a:
ORG 0acc6h
SUB_0000_acc6:
ORG 0c8b4h
SUB_0000_c8b4:
ORG 0f9c6h
SUB_0000_f9c6:
ORG 0b916h
SUB_0000_b916:
ORG 9680h
SUB_0000_9680:
ORG 0b4beh
SUB_0000_b4be:
ORG 0aa7ch
SUB_0000_aa7c:
ORG 0a06ch
SUB_0000_a06c:
ORG 0a8d8h
SUB_0000_a8d8:
ORG 0a0f0h
SUB_0000_a0f0:
ORG 9946h
SUB_0000_9946:
ORG 0fa02h
SUB_0000_fa02:
ORG 0c232h
SUB_0000_c232:
ORG 0c16eh
SUB_0000_c16e:
ORG 0d740h
SUB_0000_d740:
ORG 0a730h
SUB_0000_a730:
ORG 0f972h
SUB_0000_f972:
ORG 94eah
SUB_0000_94ea:
ORG 0ca5ah
SUB_0000_ca5a:
ORG 9968h
SUB_0000_9968:
ORG 9e62h
SUB_0000_9e62:
ORG 0a49ch
SUB_0000_a49c:
ORG 0b41ch
SUB_0000_b41c:
ORG 0df80h
SUB_0000_df80:
ORG 0b714h
SUB_0000_b714:
ORG 0a34eh
SUB_0000_a34e:
ORG 94a4h
SUB_0000_94a4:
ORG 0f852h
SUB_0000_f852:
ORG 0a408h
SUB_0000_a408:
ORG 0a39eh
SUB_0000_a39e:
ORG 0f89ah
SUB_0000_f89a:
ORG 0f9eah
SUB_0000_f9ea:
ORG 9ec2h
SUB_0000_9ec2:
ORG 0aea2h
SUB_0000_aea2:
ORG 0b82ch
SUB_0000_b82c:
ORG 0f88eh
SUB_0000_f88e:
ORG 0c6d8h
SUB_0000_c6d8:
ORG 0afa8h
SUB_0000_afa8:
ORG 0beb0h
SUB_0000_beb0:
ORG 0f97eh
SUB_0000_f97e:
ORG 0f98ah
SUB_0000_f98a:
ORG 0a918h
SUB_0000_a918:
ORG 0b352h
SUB_0000_b352:
ORG 0b8a4h
SUB_0000_b8a4:
ORG 0c1deh
SUB_0000_c1de:
ORG 0fa1ah
SUB_0000_fa1a:
ORG 0b532h
SUB_0000_b532:
ORG 986eh
SUB_0000_986e:
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
	CALL       SUB_0000_ca18
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_cdac
	MOV        AL,1h
	MOV        DS:[24e6h],AL
	MOV        DS:[5956h],AL
	MOV        DS:[58a4h],AL
	MOV        byte ptr DS:[5955h],0h
	MOV        AL,DS:[5896h]
	AND        AL,0f0h
	MOV        DS:[589bh],AL
	MOV        AL,DS:[5896h]
	AND        AL,0fh
	CMP        AL,8h
	JNC        L_0034
	MOV        AL,DS:[589bh]
	SUB        AL,10h
	AND        AL,0f0h
	MOV        DS:[589bh],AL
L_0034:
	MOV        AL,DS:[5897h]
	AND        AL,0f0h
	MOV        DS:[589ch],AL
	MOV        AL,DS:[5897h]
	AND        AL,0fh
	CMP        AL,8h
	JNC        L_004f
	MOV        AL,DS:[589ch]
	SUB        AL,10h
	AND        AL,0f0h
	MOV        DS:[589ch],AL
L_004f:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_f9ba
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_f9ba
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_cdac
	CALL       SUB_0000_dc7a
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_acc6
	CALL       SUB_0000_c8b4
	CALL       SUB_0000_f9c6
	RET
	; Func
F_0000 ENDP
F_007a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        DI,5c62h
	MOV        SI,DI
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        CL,byte ptr [SI + 2h]
	SUB        CH,CH
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,byte ptr [SI + 3h]
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        byte ptr [SI],CH
	JZ         L_00d1
	MOV        AL,DS:[5895h]
	CMP        byte ptr [SI + 4h],AL
	JNZ        L_00d1
	CMP        word ptr [BP + -6h],6h	; local_8
	JGE        L_00d1
	CMP        word ptr [BP + -8h],6h	; local_a
	JGE        L_00d1
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_b916
L_00d1:
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_007a ENDP
F_00da PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	AND        AX,0fch
	CMP        AX,10h
	JZ         L_010a
	CMP        AX,14h
	JZ         L_0130
	CMP        AX,20h
	JZ         L_016a
	CMP        AX,24h
	JZ         L_016a
	CMP        AX,28h
	JZ         L_0152
	JMP        L_0129
	db 90h
	db 90h
L_010a:
	MOV        AX,2946h
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_011e
	MOV        byte ptr DS:[587ch],12h
	JMP        L_0129
L_011e:
	CMP        word ptr [BP + 4h],3h	; param_1
	JNZ        L_0129
	MOV        byte ptr DS:[587ch],13h
L_0129:
	MOV        AX,word ptr [BP + -2h]	; local_4
	JMP        L_01f8
	db 90h
L_0130:
	MOV        AX,294ch
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_0144
	MOV        byte ptr DS:[587ch],14h
	JMP        L_0129
L_0144:
	CMP        word ptr [BP + 4h],3h	; param_1
	JNZ        L_0129
	MOV        byte ptr DS:[587ch],15h
	JMP        L_0129
	db 90h
L_0152:
	MOV        AX,2951h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        CL,byte ptr DS:[587ch]
	AND        CL,0fch
	ADD        AL,CL
	MOV        DS:[587ch],AL
	JMP        L_0129
L_016a:
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        CL,byte ptr DS:[587ch]
	AND        CL,0fch
	ADD        AL,CL
	MOV        DS:[587ch],AL
	CMP        word ptr [BP + -4h],AX	; local_6
	JZ         L_01dc
	MOV        AX,2956h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,word ptr [BP + 4h]	; param_1
	OR         AX,AX
	JZ         L_01a6
	CMP        AX,1h
	JZ         L_01d0
	CMP        AX,2h
	JZ         L_01ca
	CMP        AX,3h
	JZ         L_01d6
	JMP        L_01ad
	db 90h
L_01a6:
	MOV        AX,295ch
L_01a9:
	PUSH       AX
	CALL       SUB_0000_9680
L_01ad:
	MOV        AX,1h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        DS:[5956h],AL
	CMP        byte ptr DS:[5c5fh],32h
	JC         L_01c0
	JMP        L_0129
L_01c0:
	MOV        AX,2976h
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0129
L_01ca:
	MOV        AX,2963h
	JMP        L_01a9
	db 90h
L_01d0:
	MOV        AX,296ah
	JMP        L_01a9
	db 90h
L_01d6:
	MOV        AX,2970h
	JMP        L_01a9
	db 90h
L_01dc:
	CMP        byte ptr DS:[587ch],24h
	JC         L_01e6
	JMP        L_0129
L_01e6:
	CMP        byte ptr DS:[5892h],0h
	JZ         L_01f0
	JMP        L_0129
L_01f0:
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_0129
L_01f8:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_00da ENDP
F_01fe PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,24h
	JNZ        L_0215
	MOV        AX,2982h
	PUSH       AX
	CALL       SUB_0000_9680
L_0215:
	MOV        word ptr [BP + -2h],1h	; local_4
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b4be
	MOV        word ptr [BP + -4h],AX	; local_6
	OR         AX,AX
	JZ         L_0288
	MOV        word ptr [BP + -2h],0h	; local_4
	CMP        byte ptr DS:[587ch],30h
	JNC        L_0253
	CMP        byte ptr DS:[587ch],20h
	JNC        L_0270
L_0253:
	CMP        word ptr [BP + -4h],24h	; local_6
	JL         L_025f
	CMP        word ptr [BP + -4h],2ch	; local_6
	JL         L_0283
L_025f:
	CMP        word ptr [BP + -4h],1bh	; local_6
	JZ         L_0283
	MOV        AL,byte ptr [BP + -4h]	; local_6
	AND        AL,0feh
	CMP        AL,10h
	JNZ        L_0288
	JMP        L_0283
L_0270:
	CMP        byte ptr DS:[587ch],28h
	JC         L_0288
	CMP        word ptr [BP + -4h],24h	; local_6
	JL         L_0288
	CMP        word ptr [BP + -4h],28h	; local_6
	JGE        L_0288
L_0283:
	MOV        word ptr [BP + -2h],1h	; local_4
L_0288:
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        SI,CL
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        AL,byte ptr [BX + SI + 0aba7h]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_02b4
	MOV        AL,DS:[587ch]
	PUSH       AX
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       SUB_0000_aa7c
	OR         AX,AX
	JZ         L_02b4
	MOV        AX,1h
	JMP        L_02b6
L_02b4:
	SUB        AX,AX
L_02b6:
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JZ         L_02c0
	JMP        L_034a
L_02c0:
	CMP        byte ptr DS:[5955h],0h
	JZ         L_0312
	CMP        word ptr [BP + -6h],3h	; local_8
	JNZ        L_02d2
	MOV        AX,298bh
	JMP        L_02db
L_02d2:
	CMP        word ptr [BP + -6h],47h	; local_8
	JZ         L_02df
	MOV        AX,2999h
L_02db:
	PUSH       AX
	CALL       SUB_0000_9680
L_02df:
	CMP        word ptr [BP + -6h],47h	; local_8
	JNZ        L_02f4
	MOV        AX,29a5h
	PUSH       AX
	CALL       SUB_0000_9680
	ADD        byte ptr DS:[587ch],4h
	JMP        L_0306
	db 90h
L_02f4:
	MOV        AX,64h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	CALL       SUB_0000_a06c
	CALL       F_109e
L_0306:
	MOV        byte ptr DS:[5955h],0h
	MOV        byte ptr DS:[5956h],1h
	JMP        L_034a
L_0312:
	CMP        byte ptr DS:[587ch],20h
	JC         L_0322
	MOV        AL,byte ptr [BP + -4h]	; local_6
	AND        AL,0fch
	CMP        AL,0ech
	JZ         L_034a
L_0322:
	MOV        AX,29aeh
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + -6h],2fh	; local_8
	JNZ        L_033c
	MOV        AX,29b8h
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_a8d8
	JMP        L_0347
	db 90h
L_033c:
	MOV        AX,0a5h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	CALL       SUB_0000_a0f0
L_0347:
	CALL       SUB_0000_9946
L_034a:
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_01fe ENDP
F_0354 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AL,byte ptr [BP + 6h]	; param_2
	ADD        byte ptr DS:[5896h],AL
	MOV        AL,byte ptr [BP + 4h]	; param_1
	ADD        byte ptr DS:[5897h],AL
	MOV        byte ptr DS:[24e6h],1h
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[589bh]
	SUB        CH,CH
	SUB        AX,CX
	AND        AX,1fh
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[589ch]
	SUB        AX,CX
	AND        AX,1fh
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        word ptr [BP + -2h],5h	; local_4
	JL         L_03a7
	CMP        word ptr [BP + -2h],1ah	; local_4
	JG         L_03a7
	CMP        AX,5h
	JL         L_03a7
	CMP        AX,1ah
	JLE        L_03da
L_03a7:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_fa02
	MOV        AL,byte ptr [BP + 6h]	; param_2
	MOV        CL,4h
	SHL        AL,CL
	ADD        AL,byte ptr DS:[589bh]
	AND        AL,0f0h
	MOV        DS:[589bh],AL
	MOV        AL,byte ptr [BP + 4h]	; param_1
	SHL        AL,CL
	ADD        AL,byte ptr DS:[589ch]
	AND        AL,0f0h
	MOV        DS:[589ch],AL
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_f9ba
	CALL       SUB_0000_dc7a
L_03da:
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0354 ENDP
F_03e0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
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
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,5h
	JNZ        L_040e
L_0406:
	MOV        word ptr [BP + -4h],0h	; local_6
	JMP        L_041f
	db 90h
L_040e:
	CMP        word ptr [BP + -6h],1eh	; local_8
	JZ         L_041a
	CMP        word ptr [BP + -6h],1fh	; local_8
	JNZ        L_042e
L_041a:
	MOV        word ptr [BP + -4h],1h	; local_6
L_041f:
	MOV        AX,word ptr [BP + -4h]	; local_6
	CMP        AX,1h
	JZ         L_0448
	CMP        AX,2h
	JZ         L_0468
	JMP        L_048c
L_042e:
	CMP        word ptr [BP + -6h],4h	; local_8
	JL         L_0406
	CMP        word ptr [BP + -6h],10h	; local_8
	JGE        L_0406
	CMP        word ptr [BP + -6h],9h	; local_8
	JL         L_041a
	MOV        word ptr [BP + -4h],2h	; local_6
	JMP        L_041f
	db 90h
L_0448:
	CALL       F_1a60
	ADD        word ptr [BP + -2h],AX	; local_4
	CALL       F_007a
	CMP        word ptr [BP + -2h],0h	; local_4
	JNZ        L_045e
	MOV        AX,29bfh
	PUSH       AX
	CALL       SUB_0000_9680
L_045e:
	MOV        AX,2h
L_0461:
	PUSH       AX
	CALL       SUB_0000_cdac
	JMP        L_048c
	db 90h
L_0468:
	CALL       F_1a60
	ADD        word ptr [BP + -2h],AX	; local_4
	CALL       F_007a
	CALL       F_1a60
	ADD        word ptr [BP + -2h],AX	; local_4
	CALL       F_007a
	CMP        word ptr [BP + -2h],0h	; local_4
	JNZ        L_0487
	MOV        AX,29cfh
	PUSH       AX
	CALL       SUB_0000_9680
L_0487:
	MOV        AX,4h
	JMP        L_0461
L_048c:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_03e0 ENDP
F_0490 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,20h
	JNZ        L_04b8
	MOV        AL,DS:[5955h]
	SUB        AH,AH
	CMP        word ptr [BP + 6h],AX	; param_2
	JZ         L_04b3
	MOV        AL,byte ptr [BP + 6h]	; param_2
	MOV        DS:[5955h],AL
	MOV        byte ptr DS:[5883h],AH
L_04b3:
	MOV        byte ptr DS:[5956h],0h
L_04b8:
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_04c8
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,12h
	JNZ        L_04cb
L_04c8:
	CALL       SUB_0000_c16e
L_04cb:
	SUB        AX,AX
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 6h]	; param_2
	CMP        AX,1h
	JNZ        L_04de
	JMP        L_0576
L_04de:
	CMP        AX,2h
	JZ         L_055c
	CMP        AX,3h
	JZ         L_04f0
	CMP        AX,4h
	JZ         L_0542
	JMP        L_050e
	db 90h
L_04f0:
	DEC        word ptr [BP + -6h]	; local_8
	SUB        AX,AX
	PUSH       AX
	CALL       F_00da
	OR         AX,AX
	JZ         L_0500
	JMP        L_0592
L_0500:
	CMP        byte ptr DS:[5955h],0h
	JNZ        L_050e
	MOV        AX,29dbh
L_050a:
	PUSH       AX
	CALL       SUB_0000_9680
L_050e:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       F_01fe
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_053c
	OR         AX,AX
	JZ         L_053c
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,12h
	JNZ        L_0530
	CALL       SUB_0000_c16e
L_0530:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       F_0354
	CALL       F_03e0
L_053c:
	MOV        AX,word ptr [BP + -2h]	; local_4
	JMP        L_0592
	db 90h
L_0542:
	INC        word ptr [BP + -6h]	; local_8
	MOV        AX,2h
	PUSH       AX
	CALL       F_00da
	OR         AX,AX
	JNZ        L_0592
	CMP        byte ptr DS:[5955h],0h
	JNZ        L_050e
	MOV        AX,29e2h
	JMP        L_050a
L_055c:
	INC        word ptr [BP + -4h]	; local_6
	MOV        AX,1h
	PUSH       AX
	CALL       F_00da
	OR         AX,AX
	JNZ        L_0592
	CMP        byte ptr DS:[5955h],0h
	JNZ        L_050e
	MOV        AX,29e9h
	JMP        L_050a
L_0576:
	DEC        word ptr [BP + -4h]	; local_6
	MOV        AX,3h
	PUSH       AX
	CALL       F_00da
	OR         AX,AX
	JNZ        L_0592
	CMP        byte ptr DS:[5955h],0h
	JNZ        L_050e
	MOV        AX,29efh
	JMP        L_050a
	db 90h
L_0592:
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0490 ENDP
F_0598 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_d740
	CMP        byte ptr DS:[0a9fah],0h
	JZ         L_05b2
	CALL       SUB_0000_a730
	MOV        byte ptr DS:[0a9fah],0h
L_05b2:
	MOV        AL,DS:[0abc7h]
	AND        AL,0fch
	CMP        AL,0d4h
	JNZ        L_05c6
	CALL       SUB_0000_f972
	MOV        word ptr [BP + -4h],0h	; local_6
	JMP        L_06e2
L_05c6:
	CMP        byte ptr DS:[5956h],0h
	JZ         L_05d7
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CALL       SUB_0000_ca5a
L_05d7:
	MOV        byte ptr DS:[5956h],1h
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        SI,word ptr [BP + -4h]	; local_6
	JMP        L_06ab
	db 90h
L_05e6:
	MOV        AL,DS:[5955h]
	SUB        AH,AH
	MOV        SI,AX
	CMP        byte ptr DS:[5892h],AH
	JZ         L_0670
	SUB        AX,AX
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AX,SI
	CMP        AX,1h
	JZ         L_0668
	CMP        AX,2h
	JZ         L_0660
	CMP        AX,3h
	JZ         L_0614
	CMP        AX,4h
	JZ         L_0658
	JMP        L_0619
	db 90h
L_0614:
	MOV        word ptr [BP + -8h],0ffh	; local_a
L_0619:
	MOV        DI,1h
	MOV        BL,byte ptr DS:[5892h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 29f5h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -6h]	; local_8
	JZ         L_062e
	INC        DI
L_062e:
	MOV        BL,byte ptr DS:[5892h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 29f9h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]	; local_a
	JZ         L_0640
	INC        DI
L_0640:
	MOV        AX,DI
	CWD
	MOV        CX,3h
	IDIV       CX
	MOV        AL,DS:[5883h]
	SUB        AH,AH
	CMP        DX,AX
	JA         L_0670
	MOV        byte ptr DS:[5883h],AH
	JMP        L_06cf
	db 90h
L_0658:
	MOV        word ptr [BP + -8h],1h	; local_a
	JMP        L_0619
	db 90h
L_0660:
	MOV        word ptr [BP + -6h],1h	; local_8
	JMP        L_0619
	db 90h
L_0668:
	MOV        word ptr [BP + -6h],0ffh	; local_8
	JMP        L_0619
	db 90h
L_0670:
	CMP        byte ptr DS:[57bbh],7fh
	JBE        L_0688
	CMP        word ptr DS:[0a524h],1h
	SBB        AX,AX
	NEG        AX
	MOV        DS:[0a524h],AX
	MOV        AX,1h
	JMP        L_068b
L_0688:
	MOV        AX,2h
L_068b:
	PUSH       AX
	CALL       SUB_0000_cdac
	CMP        word ptr DS:[0a524h],0h
	JZ         L_069d
	CMP        byte ptr DS:[57bbh],80h
	JNC        L_06a0
L_069d:
	CALL       F_1a60
L_06a0:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_b916
	INC        byte ptr DS:[5883h]
L_06ab:
	CMP        byte ptr DS:[5955h],0h
	JZ         L_06cf
	CALL       SUB_0000_9968
	PUSH       AX
	CALL       SUB_0000_9e62
	MOV        SI,AX
	OR         SI,SI
	JNZ        L_06c2
	JMP        L_05e6
L_06c2:
	MOV        CL,byte ptr DS:[5955h]
	SUB        CH,CH
	CMP        AX,CX
	JNZ        L_06cf
	JMP        L_05e6
L_06cf:
	MOV        word ptr [BP + -2h],DI	; local_4
	MOV        word ptr [BP + -4h],SI	; local_6
	CMP        byte ptr DS:[5955h],0h
	JNZ        L_06e2
	CALL       SUB_0000_a49c
	MOV        word ptr [BP + -4h],AX	; local_6
L_06e2:
	MOV        AX,word ptr [BP + -4h]	; local_6
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0598 ENDP
F_06ec PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AX,29feh
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
	JNC        L_0732
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,28h
	JZ         L_0724
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,14h
	JNZ        L_0732
L_0724:
	MOV        AX,2a06h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_0789
L_0732:
	CALL       SUB_0000_b41c
	OR         AX,AX
	JZ         L_0789
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	MOV        word ptr [BP + -6h],AX	; local_8
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b4be
	AND        AX,0fch
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,2ch
	JZ         L_0778
	CMP        AX,0b4h
	JZ         L_0782
	CMP        AX,0e8h
	JZ         L_0782
	CMP        AX,40h
	JL         L_0782
L_0778:
	PUSH       word ptr DS:[5876h]
	CALL       SUB_0000_df80
	JMP        L_0789
	db 90h
L_0782:
	MOV        AX,2a10h
	PUSH       AX
	CALL       SUB_0000_9680
L_0789:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_06ec ENDP
F_0790 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_9680
	MOV        SI,20h
	MOV        DL,byte ptr DS:[5896h]
	MOV        CL,byte ptr DS:[5897h]
L_07a8:
	CMP        byte ptr [SI + 1e8ah],DL
	JNZ        L_07d0
	CMP        byte ptr [SI + 1eb2h],CL
	JNZ        L_07d0
L_07b4:
	MOV        word ptr [BP + -2h],SI	; local_4
	CMP        SI,28h
	JL         L_07bf
	JMP        L_08cc
L_07bf:
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_07d8
	MOV        AX,2a24h
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_08d6
L_07d0:
	INC        SI
	CMP        SI,28h
	JGE        L_07b4
	JMP        L_07a8
L_07d8:
	CMP        word ptr [BP + -2h],27h	; local_4
	JNZ        L_0816
	MOV        AL,DS:[58c8h]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[58c9h]
	SUB        CH,CH
	AND        AX,CX
	MOV        CL,byte ptr DS:[58cah]
	AND        AX,CX
	CMP        AX,80h
	JNC        L_0837
	MOV        AX,2a2fh
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_b714
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        BX,AX
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5ah],0fch
	PUSH       AX
	CALL       SUB_0000_df80
	JMP        L_08d6
	db 90h
L_0816:
	MOV        AX,2a47h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94ea
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	PUSH       word ptr [BX + 1e3ah]
	CALL       SUB_0000_9680
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94ea
L_0837:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CMP        byte ptr DS:[0a9bdh],1h
	JZ         L_0857
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_a34e
L_084c:
	MOV        AX,2a4ah
	PUSH       AX
	CALL       SUB_0000_94a4
	OR         AX,AX
	JZ         L_084c
L_0857:
	CALL       SUB_0000_f852
	PUSH       AX
	MOV        AX,5c5ah
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_a408
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_a34e
	MOV        AX,2a53h
	PUSH       AX
	MOV        AX,595ah
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        CL,9h
	SHL        AX,CL
	SUB        AX,4000h
	PUSH       AX
	CALL       SUB_0000_a39e
	MOV        AL,byte ptr [BP + -2h]	; local_4
	INC        AL
	MOV        DS:[5893h],AL
	CMP        byte ptr DS:[5895h],0h
	JZ         L_08b4
	CMP        AL,28h
	JZ         L_08b4
	MOV        byte ptr DS:[5895h],7h
	MOV        byte ptr DS:[6603h],3h
	MOV        byte ptr DS:[6602h],4h
	MOV        AL,7h
	MOV        DS:[5897h],AL
	MOV        DS:[5896h],AL
	JMP        L_08d3
	db 90h
L_08b4:
	MOV        byte ptr DS:[5895h],0h
	MOV        AL,1h
	MOV        DS:[5897h],AL
	MOV        DS:[5896h],AL
	MOV        DS:[6603h],AL
	MOV        byte ptr DS:[6602h],5h
	JMP        L_08d3
	db 90h
L_08cc:
	MOV        AX,2a5fh
	PUSH       AX
	CALL       SUB_0000_9680
L_08d3:
	MOV        AX,1h
L_08d6:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0790 ENDP
F_08de PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        word ptr [BP + -2h],1h	; local_4
	MOV        AX,2a6fh
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,16h
	JNZ        L_090f
	JMP        L_09a8
L_090f:
	JLE        L_0914
	JMP        L_09da
L_0914:
	CMP        AX,10h
	JZ         L_097a
	CMP        AX,11h
	JZ         L_0986
	CMP        AX,12h
	JZ         L_0990
	CMP        AX,13h
	JZ         L_0996
	CMP        AX,14h
	JZ         L_099c
	CMP        AX,15h
	JZ         L_09a2
	JMP        L_09ee
	db 90h
L_0936:
	MOV        AX,2a76h
	PUSH       AX
	CALL       SUB_0000_9680
	SUB        SI,SI
	MOV        DL,byte ptr DS:[5896h]
	MOV        CL,byte ptr DS:[5897h]
L_0947:
	CMP        byte ptr [SI + 1f6eh],DL
	JNZ        L_0972
	CMP        byte ptr [SI + 1f76h],CL
	JNZ        L_0972
L_0953:
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        BX,SI
	SHL        BX,1h
	PUSH       word ptr [BX + 1f4eh]
	CALL       SUB_0000_9680
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
L_0968:
	CALL       SUB_0000_f89a
L_096b:
	MOV        AX,word ptr [BP + -2h]	; local_4
	JMP        L_0a14
	db 90h
L_0972:
	INC        SI
	CMP        SI,8h
	JGE        L_0953
	JMP        L_0947
L_097a:
	MOV        AX,2a85h
L_097d:
	PUSH       AX
	CALL       SUB_0000_f9ea
L_0981:
	MOV        word ptr [BP + -2h],AX	; local_4
	JMP        L_096b
L_0986:
	MOV        AX,2a89h
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0968
	db 90h
L_0990:
	MOV        AX,2aa3h
	JMP        L_097d
	db 90h
L_0996:
	MOV        AX,2aa8h
	JMP        L_097d
	db 90h
L_099c:
	MOV        AX,2ab0h
	JMP        L_097d
	db 90h
L_09a2:
	MOV        AX,2ab6h
	JMP        L_097d
	db 90h
L_09a8:
	MOV        AX,2abdh
L_09ab:
	PUSH       AX
	CALL       F_0790
	JMP        L_0981
	db 90h
L_09b2:
	MOV        AX,2ac2h
	JMP        L_09ab
	db 90h
L_09b8:
	MOV        AX,2ac7h
	JMP        L_09ab
	db 90h
L_09be:
	MOV        AX,2acfh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_096b
	db 90h
L_09c8:
	MOV        AX,2ad5h
	JMP        L_097d
	db 90h
L_09ce:
	MOV        AX,2ae0h
	JMP        L_097d
	db 90h
L_09d4:
	MOV        AX,2afah
	JMP        L_097d
	db 90h
L_09da:
	CMP        AX,19h
	JNZ        L_09e2
	JMP        L_0936
L_09e2:
	JG         L_09fe
	CMP        AX,17h
	JZ         L_09b2
	CMP        AX,18h
	JZ         L_09b8
L_09ee:
	MOV        AX,2b16h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_096b
	db 90h
L_09fe:
	CMP        AX,1ah
	JZ         L_09be
	CMP        AX,1bh
	JZ         L_09c8
	CMP        AX,39h
	JZ         L_09ce
	CMP        AX,3eh
	JZ         L_09d4
	JMP        L_09ee
L_0a14:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_08de ENDP
F_0a1a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],0ffh
	JNZ        L_0a4e
	CMP        byte ptr DS:[587ah],0eh
	JZ         L_0a4e
	MOV        byte ptr DS:[58a5h],0h
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_0a59
	CALL       SUB_0000_d740
	MOV        word ptr [BP + 4h],1h	; param_1
	JMP        L_0a59
	db 90h
L_0a4e:
	MOV        word ptr [BP + 4h],0h	; param_1
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_cdac
L_0a59:
	MOV        AX,word ptr [BP + 4h]	; param_1
	POP        BP
	RET        2h
	; Func
F_0a1a ENDP
F_0a60 PROC NEAR
	CMP        byte ptr DS:[5895h],0h
	JZ         L_0a83
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,69h
	JNZ        L_0a83
	MOV        AX,2b1dh
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_aea2
	CALL       SUB_0000_a8d8
L_0a83:
	RET
	; Func
F_0a60 ENDP
F_0a84 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	MOV        word ptr [BP + -2h],0h	; local_4
L_0a8f:
	MOV        word ptr [BP + -0ah],0h	; local_c
	MOV        word ptr [BP + -8h],1h	; local_a
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0a1a
	MOV        word ptr [BP + -2h],AX	; local_4
	CALL       SUB_0000_b82c
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,1h
	JNZ        L_0ac2
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CALL       SUB_0000_ca5a
	MOV        AX,2b2ah
L_0aba:
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0c12
	db 90h
L_0ac2:
	CMP        word ptr [BP + -6h],-1h	; local_8
	JNZ        L_0b00
	CMP        byte ptr DS:[0a9bdh],1h
	JZ         L_0ae1
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_a34e
L_0ad6:
	MOV        AX,2b35h
	PUSH       AX
	CALL       SUB_0000_94a4
	OR         AX,AX
	JZ         L_0ad6
L_0ae1:
	CALL       SUB_0000_f852
	PUSH       AX
	MOV        AX,5c5ah
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_a408
	CALL       SUB_0000_f88e
	MOV        word ptr [BP + -0ah],1h	; local_c
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_0c12
L_0b00:
	CALL       SUB_0000_c6d8
	OR         AX,AX
	JZ         L_0b0a
	CALL       SUB_0000_f89a
L_0b0a:
	CMP        byte ptr DS:[5893h],0h
	JZ         L_0b14
	JMP        L_0d1d
L_0b14:
	CALL       F_0598
	MOV        byte ptr [BP + -4h],AL	; local_6
	CMP        AL,20h
	JC         L_0b21
	JMP        L_0bee
L_0b21:
	SUB        AH,AH
	CMP        AX,16h
	JBE        L_0b2b
	JMP        L_0bb8
L_0b2b:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 8d8eh]
	db 90h
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
	db 29h
	db 8Dh
	db 0EBh
	db 2Eh
	db 90h
	db 0B8h
	db 3Eh
	db 2Bh
	db 50h
	db 0E8h
	db 31h
	db 8Bh
	db 0E8h
	db 4Ah
	db 99h
	db 88h
	db 46h
	db 0FCh
	db 3Ch
	db 59h
	db 75h
	db 0Fh
	db 0E8h
	db 4Ch
	db 7Bh
	db 2Bh
	db 0C0h
	db 50h
	db 0E8h
	db 0C2h
	db 75h
	db 83h
	db 0C4h
	db 02h
	db 0E9h
	db 0AAh
	db 00h
	db 0B8h
	db 4Ch
	db 2Bh
	db 0E9h
	db 4Ch
	db 0FFh
	db 0B8h
	db 4Fh
	db 2Bh
	db 50h
	db 0E8h
	db 0Bh
	db 8Bh
	db 0B8h
	db 0Ah
	db 00h
	db 50h
	db 0E8h
	db 6Eh
	db 89h
	db 0E9h
	db 79h
	db 0FFh
	db 90h
	db 0B8h
	db 54h
	db 2Bh
	db 50h
	db 0E8h
	db 0F9h
	db 8Ah
	db 80h
	db 3Eh
	db 0CEh
	db 0A9h
	db 00h
	db 74h
	db 06h
	db 0B8h
	db 5Bh
	db 2Bh
	db 0EBh
	db 04h
	db 90h
	db 0B8h
	db 60h
	db 2Bh
	db 50h
	db 0E8h
	db 0E5h
	db 8Ah
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
	db 69h
	db 90h
	db 8Ah
	db 46h
	db 0FCh
	db 2Ah
	db 0E4h
	db 50h
	db 0FFh
	db 76h
	db 0FEh
	db 0E8h
	db 0DAh
	db 0F8h
	db 0EBh
	db 57h
L_0bb8:
	MOV        AX,2b64h
	JMP        L_0aba
	db 0C8h
	db 8Ch
	db 7Ah
	db 8Dh
	db 7Ah
	db 8Dh
	db 7Ah
	db 8Dh
	db 7Ah
	db 8Dh
	db 18h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 04h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 50h
	db 8Dh
	db 88h
	db 8Dh
	db 88h
	db 8Dh
	db 3Eh
	db 8Dh
	db 0EBh
	db 24h
L_0bee:
	CMP        byte ptr [BP + -4h],30h	; local_6
	JC         L_0bfa
	CMP        byte ptr [BP + -4h],39h	; local_6
	JBE        L_0c06
L_0bfa:
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_afa8
	JMP        L_0c0f
	db 90h
L_0c06:
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_beb0
L_0c0f:
	MOV        word ptr [BP + -8h],AX	; local_a
L_0c12:
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,20h
	JZ         L_0c20
	MOV        byte ptr DS:[5955h],0h
L_0c20:
	CMP        byte ptr DS:[5893h],0h
	JZ         L_0c30
	MOV        word ptr [BP + -0ah],1h	; local_c
	JMP        L_0d14
	db 90h
L_0c30:
	CMP        word ptr [BP + -8h],0h	; local_a
	JNZ        L_0c39
	JMP        L_0d14
L_0c39:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_cdac
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -10h],AX	; local_12
	MOV        AL,byte ptr [BP + -10h]	; local_12
	AND        AL,0feh
	CMP        AL,6ah
	JNZ        L_0c64
	CALL       F_1be8
	JMP        L_0cd0
L_0c64:
	CMP        word ptr [BP + -10h],4h	; local_12
	JNZ        L_0c7e
	CMP        byte ptr DS:[587ch],1ch
	JNZ        L_0c7e
	CALL       SUB_0000_f97e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_b916
	JMP        L_0cd0
	db 90h
L_0c7e:
	CMP        word ptr [BP + -10h],8fh	; local_12
	JNZ        L_0c8a
	CALL       SUB_0000_f98a
	JMP        L_0cd0
L_0c8a:
	CMP        byte ptr DS:[5896h],0e9h
	JNZ        L_0cd0
	CMP        byte ptr DS:[5897h],0ebh
	JNZ        L_0cd0
	CMP        byte ptr DS:[5895h],0h
	JNZ        L_0cd0
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_0cd0
	MOV        AX,2b6bh
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        byte ptr DS:[58cch],0h
	JZ         L_0cbe
	MOV        AX,2b6eh
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_0cd0
	db 90h
L_0cbe:
	MOV        AX,2b7eh
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,2ba1h
	PUSH       AX
	CALL       SUB_0000_9680
	INC        byte ptr DS:[5897h]
L_0cd0:
	CALL       F_0a60
	CALL       SUB_0000_a918
	CMP        word ptr [BP + -10h],1h	; local_12
	JNZ        L_0d05
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,28h
	JZ         L_0cee
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,14h
	JNZ        L_0d05
L_0cee:
	MOV        AX,2bb3h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_b352
	CALL       F_109e
L_0d05:
	MOV        AL,byte ptr [BP + -10h]	; local_12
	AND        AL,0fch
	CMP        AL,0d4h
	JNZ        L_0d11
	CALL       SUB_0000_f972
L_0d11:
	CALL       F_1a60
L_0d14:
	CMP        word ptr [BP + -0ah],0h	; local_c
	JNZ        L_0d1d
	JMP        L_0a8f
L_0d1d:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0a84 ENDP
F_0d22 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	CALL       F_0000
	CMP        byte ptr DS:[6605h],40h
	JC         L_0d84
	CALL       SUB_0000_b714
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	MOV        AL,DS:[6605h]
	AND        AL,3fh
	MOV        byte ptr [BX + 7h],AL
	MOV        AL,DS:[5953h]
	MOV        byte ptr [BX + 2h],AL
	MOV        AL,DS:[5954h]
	MOV        byte ptr [BX + 3h],AL
	MOV        byte ptr [BX + 4h],0h
	CMP        byte ptr DS:[6605h],7fh
	JBE        L_0d6c
	MOV        word ptr [BP + -6h],25h	; local_8
	JMP        L_0d71
	db 90h
L_0d6c:
	MOV        word ptr [BP + -6h],29h	; local_8
L_0d71:
	MOV        SI,BX
	MOV        AL,byte ptr [BP + -6h]	; local_8
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr [BX + 5h],63h
	MOV        byte ptr DS:[6605h],0h
L_0d84:
	CALL       F_0a84
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0d22 ENDP
F_0d8c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	CMP        byte ptr DS:[5895h],7fh
	JBE        L_0d9e
	MOV        AX,3h
	JMP        L_0dff
L_0d9e:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,20h
	JL         L_0dc6
	CMP        AX,26h
	JG         L_0dc6
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_0de5
	db 90h
L_0dc6:
	CMP        word ptr [BP + -4h],4h	; local_6
	JZ         L_0dd8
	CMP        word ptr [BP + -4h],9h	; local_6
	JL         L_0de0
	CMP        word ptr [BP + -4h],0fh	; local_6
	JG         L_0de0
L_0dd8:
	MOV        word ptr [BP + -2h],2h	; local_4
	JMP        L_0de5
	db 90h
L_0de0:
	MOV        word ptr [BP + -2h],1h	; local_4
L_0de5:
	CMP        byte ptr DS:[587fh],20h
	JNC        L_0df3
	CMP        byte ptr DS:[587fh],5h
	JNC        L_0dfc
L_0df3:
	MOV        AX,word ptr [BP + -2h]	; local_4
	ADD        AX,3h
	JMP        L_0dff
	db 90h
L_0dfc:
	MOV        AX,word ptr [BP + -2h]	; local_4
L_0dff:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0d8c ENDP
F_0e04 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        DX,AX
	MOV        CX,word ptr [BP + -4h]	; local_6
	JMP        L_0e33
	db 90h
L_0e28:
	MOV        BX,CX
	ADD        BX,SI
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	SUB        DX,AX
	INC        CX
L_0e33:
	MOV        BX,CX
	ADD        BX,SI
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,DX
	JBE        L_0e28
	MOV        word ptr [BP + -2h],DX	; local_4
	MOV        word ptr [BP + -4h],CX	; local_6
	MOV        AX,CX
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0e04 ENDP
F_0e4e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        word ptr [BP + 4h],4h	; param_1
	JL         L_0e82
	CMP        word ptr [BP + 4h],60h	; param_1
	JL         L_0e66
	CMP        word ptr [BP + 4h],6fh	; param_1
	JLE        L_0e82
L_0e66:
	CMP        word ptr [BP + 4h],0d4h	; param_1
	JL         L_0e74
	CMP        word ptr [BP + 4h],0d7h	; param_1
	JLE        L_0e82
L_0e74:
	CMP        word ptr [BP + 4h],0e4h	; param_1
	JL         L_0ed6
	CMP        word ptr [BP + 4h],0e7h	; param_1
	JG         L_0ed6
L_0e82:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,40h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,10h
	JGE        L_0f0e
	CMP        byte ptr DS:[5895h],80h
	JNC        L_0ec6
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_0eb4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,7h
	JNZ        L_0eb4
	MOV        AX,0ech
	JMP        L_0f48
	db 90h
L_0eb4:
	MOV        AX,2bf0h
	PUSH       AX
	CALL       F_0e04
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 2bd4h]
L_0ec1:
	SUB        AH,AH
	JMP        L_0f48
L_0ec6:
	MOV        AX,2bf6h
	PUSH       AX
	CALL       F_0e04
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 2bdah]
	JMP        L_0ec1
	db 90h
L_0ed6:
	CMP        word ptr [BP + 4h],7h	; param_1
	JNZ        L_0ef0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JNZ        L_0f0e
	MOV        AX,0e0h
	JMP        L_0f48
	db 90h
L_0ef0:
	CMP        word ptr [BP + 4h],4h	; param_1
	JNZ        L_0f02
	CMP        byte ptr DS:[5895h],0ffh
	JNZ        L_0f02
	MOV        AX,0f8h
	JMP        L_0f48
L_0f02:
	CMP        word ptr [BP + 4h],0ch	; param_1
	JZ         L_0f0e
	CMP        word ptr [BP + 4h],0dh	; param_1
	JNZ        L_0f12
L_0f0e:
	SUB        AX,AX
	JMP        L_0f48
L_0f12:
	CMP        word ptr [BP + 4h],10h	; param_1
	JL         L_0f21
	MOV        AL,byte ptr [BP + 4h]	; param_1
	AND        AL,0fch
	CMP        AL,30h
	JNZ        L_0f0e
L_0f21:
	CMP        byte ptr DS:[5895h],80h
	JNC        L_0f38
	MOV        AX,2bdch
	PUSH       AX
	CALL       F_0e04
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 2bc0h]
	JMP        L_0ec1
	db 90h
L_0f38:
	MOV        AX,2be8h
	PUSH       AX
	CALL       F_0e04
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 2bcch]
	JMP        L_0ec1
L_0f48:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0e4e ENDP
F_0f4e PROC NEAR
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1fh
	PUSH       AX
	CALL       SUB_0000_9ec2
	ADD        AL,byte ptr DS:[589bh]
	SUB        AH,AH
	MOV        DS:[5876h],AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1fh
	PUSH       AX
	CALL       SUB_0000_9ec2
	ADD        AL,byte ptr DS:[589ch]
	SUB        AH,AH
	MOV        DS:[5878h],AX
	MOV        AX,DS:[5876h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	CMP        AX,6h
	JLE        F_0f4e
	MOV        AX,DS:[5878h]
	MOV        CL,byte ptr DS:[5897h]
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	CMP        AX,6h
	JLE        F_0f4e
	MOV        AX,DS:[5876h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	CMP        AX,0fah
	JGE        F_0f4e
	MOV        AX,DS:[5878h]
	MOV        CL,byte ptr DS:[5897h]
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	CMP        AX,0fah
	JGE        F_0f4e
	RET
	db 90h
	; Func
F_0f4e ENDP
F_0fc4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],0h	; local_6
L_0fd1:
	CALL       F_0f4e
	MOV        DI,word ptr DS:[5876h]
	MOV        SI,word ptr DS:[5878h]
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0e4e
	MOV        byte ptr [BP + -2h],AL	; local_4
	OR         AL,AL
	JZ         L_100e
	CMP        AL,2ch
	JNZ        L_1005
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0f0h
	CMP        AL,60h
	JZ         L_100e
L_1005:
	MOV        word ptr [BP + -6h],DI	; local_8
	MOV        word ptr [BP + -8h],SI	; local_a
	JMP        L_101a
	db 90h
L_100e:
	INC        word ptr [BP + -4h]	; local_6
	CMP        word ptr [BP + -4h],80h	; local_6
	JGE        L_1005
	JMP        L_0fd1
L_101a:
	CMP        word ptr [BP + -4h],80h	; local_6
	JZ         L_1055
	CALL       SUB_0000_b714
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        AH,AH
	MOV        SI,AX
	PUSH       SI
	PUSH       SI
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BP + -8h]	; local_a
	MOV        AL,DS:[5895h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_b8a4
	CMP        byte ptr [BP + -2h],2ch	; local_4
	JNZ        L_1055
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5fh],64h
L_1055:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0fc4 ENDP
F_105c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 4h],2ch	; param_1
	JL         L_1070
	CMP        word ptr [BP + 4h],2fh	; param_1
	JG         L_1070
L_106b:
	MOV        AX,1h
	JMP        L_109a
L_1070:
	CMP        word ptr [BP + 4h],80h	; param_1
	JGE        L_107c
L_1077:
	SUB        AX,AX
	JMP        L_109a
	db 90h
L_107c:
	CMP        word ptr [BP + 4h],0b4h	; param_1
	JL         L_108a
	CMP        word ptr [BP + 4h],0b7h	; param_1
	JLE        L_1077
L_108a:
	CMP        word ptr [BP + 4h],0e8h	; param_1
	JL         L_106b
	CMP        word ptr [BP + 4h],0ebh	; param_1
	JG         L_106b
	JMP        L_1077
L_109a:
	POP        BP
	RET        2h
	; Func
F_105c ENDP
F_109e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AL,DS:[587ch]
	AND        AL,0f8h
	CMP        AL,20h
	JZ         L_10b0
	JMP        L_1160
L_10b0:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,DS:[5c5fh]
	SUB        AH,AH
	CMP        word ptr [BP + -2h],AX	; local_4
	JNC        L_10d6
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        byte ptr DS:[5c5fh],AL
	CALL       SUB_0000_a730
	JMP        L_1163
	db 90h
L_10d6:
	MOV        AX,6adah
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[5c61h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	OR         AX,AX
	JG         L_10ef
	CMP        byte ptr DS:[57b0h],AH
	JZ         L_1120
L_10ef:
	MOV        AX,6ae6h
	PUSH       AX
	CALL       SUB_0000_9680
	CMP        word ptr [BP + -4h],0h	; local_6
	JLE        L_1106
	MOV        AL,DS:[587ch]
	AND        AL,3h
	ADD        AL,28h
	JMP        L_1116
	db 90h
L_1106:
	DEC        byte ptr DS:[57b0h]
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	ADD        AL,14h
L_1116:
	MOV        DS:[587ch],AL
	MOV        byte ptr DS:[0a9fah],1h
	JMP        L_1163
L_1120:
	MOV        byte ptr DS:[587ch],0h
	CALL       SUB_0000_a730
	CALL       SUB_0000_d740
	MOV        AX,294h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	MOV        AX,1e78h
	PUSH       AX
	CALL       SUB_0000_c1de
	MOV        AX,6af6h
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_1158
	db 90h
L_1148:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_b352
	CALL       SUB_0000_a8d8
L_1158:
	CALL       SUB_0000_b82c
	INC        AX
	JZ         L_1163
	JMP        L_1148
L_1160:
	CALL       SUB_0000_a8d8
L_1163:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_109e ENDP
F_1168 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	CMP        word ptr [BP + 6h],0h	; param_2
	JNZ        L_11a4
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5bh]
	MOV        byte ptr [BP + -8h],AL	; local_a
	CMP        AL,2ch
	JZ         L_118b
	CMP        AL,2eh
	JNZ        L_11a4
L_118b:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9ec2
	AND        AL,2h
	ADD        AL,2dh
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5bh],AL
L_11a4:
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_11d9
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5bh]
	MOV        byte ptr [BP + -8h],AL	; local_a
	CMP        AL,2dh
	JZ         L_11c0
	CMP        AL,2fh
	JNZ        L_11d9
L_11c0:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9ec2
	AND        AL,2h
	ADD        AL,2ch
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5bh],AL
L_11d9:
	CALL       SUB_0000_d740
	MOV        AX,514h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_c1de
	MOV        SI,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ch]
	SUB        AL,byte ptr DS:[5896h]
	ADD        AL,5h
	MOV        byte ptr [BP + -4h],AL	; local_6
	MOV        AL,byte ptr [SI + 5c5dh]
	SUB        AL,byte ptr DS:[5897h]
	ADD        AL,5h
	MOV        byte ptr [BP + -6h],AL	; local_8
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BP + -6h]	; local_8
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_fa1a
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JZ         L_1240
	CALL       SUB_0000_d740
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_b352
	CALL       F_109e
L_1240:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_1168 ENDP
F_1248 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	AND        AL,0fch
	CMP        AL,0ech
	JNZ        L_12c6
	CMP        byte ptr DS:[587ch],1ch
	JNZ        L_126e
L_1267:
	CALL       F_109e
	JMP        L_1313
	db 90h
L_126e:
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	SUB        AL,AL
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AX,6b04h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        byte ptr DS:[587ch],0ech
	CALL       SUB_0000_d740
	MOV        AX,294h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	MOV        AX,1e78h
	PUSH       AX
	CALL       SUB_0000_c1de
	MOV        AL,byte ptr [BP + -2h]	; local_4
	MOV        DS:[587ch],AL
	CALL       F_109e
	MOV        byte ptr DS:[5895h],0ffh
	MOV        byte ptr DS:[5896h],22h
	MOV        byte ptr DS:[5897h],12h
	CALL       F_0000
	JMP        L_1313
L_12c6:
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	AND        AL,0fch
	CMP        AL,0e0h
	JZ         L_1267
	CALL       SUB_0000_d740
	MOV        AX,6b12h
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
	JNC        L_130d
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,14h
	JNZ        L_1301
	JMP        L_1267
L_1301:
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,28h
	JNZ        L_130d
	JMP        L_1267
L_130d:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_df80
L_1313:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_1248 ENDP
F_131a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ah]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AL,byte ptr [SI + 5c5ch]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,7fh
	JLE        L_1353
	MOV        AX,100h
	SUB        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BP + -4h],AX	; local_6
L_1353:
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5dh]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[5897h]
	SUB        CH,CH
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,7fh
	JLE        L_137e
	MOV        AX,100h
	SUB        AX,word ptr [BP + -6h]	; local_8
	MOV        word ptr [BP + -6h],AX	; local_8
L_137e:
	CMP        word ptr [BP + -4h],1h	; local_6
	JNZ        L_138a
	CMP        word ptr [BP + -6h],0h	; local_8
	JZ         L_1396
L_138a:
	CMP        word ptr [BP + -4h],0h	; local_6
	JNZ        L_13a2
	CMP        word ptr [BP + -6h],1h	; local_8
	JNZ        L_13a2
L_1396:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_1248
L_139c:
	MOV        AX,1h
	JMP        L_147a
L_13a2:
	CMP        word ptr [BP + -0ah],88h	; local_c
	JZ         L_13b3
	CMP        word ptr [BP + -0ah],0dch	; local_c
	JZ         L_13b3
	JMP        L_1440
L_13b3:
	CMP        word ptr [BP + -4h],3h	; local_6
	JLE        L_13bc
	JMP        L_1478
L_13bc:
	CMP        word ptr [BP + -6h],3h	; local_8
	JLE        L_13c5
	JMP        L_1478
L_13c5:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_13d6
	JMP        L_1478
L_13d6:
	CALL       SUB_0000_d740
	MOV        AX,514h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_c1de
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ch]
	SUB        AL,byte ptr DS:[5896h]
	ADD        AL,5h
	MOV        byte ptr [BP + -8h],AL	; local_a
	MOV        AL,byte ptr [SI + 5c5dh]
	SUB        AL,byte ptr DS:[5897h]
	ADD        AL,5h
	MOV        byte ptr [BP + -0ch],AL	; local_e
	MOV        AL,byte ptr [BP + -8h]	; local_a
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_fa1a
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JNZ        L_142d
	JMP        L_139c
L_142d:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_b352
	CALL       F_109e
	JMP        L_139c
L_1440:
	MOV        AL,byte ptr [BP + -0ah]	; local_c
	AND        AL,0fch
	CMP        AL,2ch
	JNZ        L_1478
	CMP        word ptr [BP + -4h],0h	; local_6
	JNZ        L_1455
	CMP        word ptr [BP + -6h],4h	; local_8
	JL         L_1461
L_1455:
	CMP        word ptr [BP + -6h],0h	; local_8
	JNZ        L_1478
	CMP        word ptr [BP + -4h],4h	; local_6
	JGE        L_1478
L_1461:
	MOV        AX,6b1eh
	PUSH       AX
	CALL       SUB_0000_9680
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       F_1168
	JMP        L_139c
	db 90h
L_1478:
	SUB        AX,AX
L_147a:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_131a ENDP
F_1482 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_aa7c
	OR         AX,AX
	JNZ        L_14ae
L_14aa:
	SUB        AX,AX
	JMP        L_14c4
L_14ae:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b532
	OR         AX,AX
	JNZ        L_14aa
	MOV        AX,1h
L_14c4:
	POP        BP
	RET        6h
	; Func
F_1482 ENDP
F_14c8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,DS:[0a526h]
	SUB        AH,AH
	CMP        word ptr [BP + 6h],AX	; param_2
	JNZ        L_14e2
	MOV        AL,DS:[0a527h]
	CMP        word ptr [BP + 4h],AX	; param_1
	JNZ        L_14e2
	SUB        AX,AX
	JMP        L_14e5
	db 90h
L_14e2:
	MOV        AX,1h
L_14e5:
	POP        BP
	RET        4h
	db 90h
	; Func
F_14c8 ENDP
F_14ea PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ch]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,7fh
	JLE        L_151c
	MOV        AX,100h
	SUB        AX,word ptr [BP + -2h]	; local_4
	MOV        word ptr [BP + -2h],AX	; local_4
L_151c:
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5dh]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[5897h]
	SUB        CH,CH
	SUB        AX,CX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,7fh
	JLE        L_1547
	MOV        AX,100h
	SUB        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BP + -4h],AX	; local_6
L_1547:
	CMP        word ptr [BP + -2h],6h	; local_4
	JGE        L_156e
	CMP        word ptr [BP + -4h],6h	; local_6
	JGE        L_156e
	MOV        SI,word ptr [BP + -4h]	; local_6
	MOV        AX,SI
	SHL        SI,1h
	SHL        SI,1h
	ADD        SI,AX
	SHL        SI,1h
	ADD        SI,AX
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + SI + 2c18h]
	SUB        AH,AH
	JMP        L_1570
	db 90h
L_156e:
	SUB        AX,AX
L_1570:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_14ea ENDP
F_1578 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       SI
	MOV        SI,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ah]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,byte ptr [SI + 5c5ch]
	ADD        AX,word ptr [BP + 6h]	; param_2
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AL,byte ptr [SI + 5c5dh]
	SUB        AH,AH
	ADD        AX,word ptr [BP + 4h]	; param_1
	MOV        word ptr [BP + -8h],AX	; local_a
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       AX
	CALL       SUB_0000_c232
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AL,byte ptr [BP + -4h]	; local_6
	AND        AL,0fch
	CMP        AL,2ch
	JNZ        L_1622
	CMP        word ptr [BP + 6h],0h	; param_2
	JNZ        L_15d2
	CMP        word ptr [BP + 4h],-1h	; param_1
	JNZ        L_15d2
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_160b
	db 90h
L_15d2:
	CMP        word ptr [BP + 6h],1h	; param_2
	JNZ        L_15e6
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_15e6
	MOV        word ptr [BP + -2h],1h	; local_4
	JMP        L_160b
	db 90h
L_15e6:
	CMP        word ptr [BP + 6h],0h	; param_2
	JNZ        L_15fa
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_15fa
	MOV        word ptr [BP + -2h],2h	; local_4
	JMP        L_160b
	db 90h
L_15fa:
	CMP        word ptr [BP + 6h],-1h	; param_2
	JNZ        L_160b
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_160b
	MOV        word ptr [BP + -2h],3h	; local_4
L_160b:
	MOV        SI,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [BP + -2h]	; local_4
	ADD        AL,2ch
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	JMP        L_16b2
L_1622:
	CMP        word ptr [BP + -4h],0dch	; local_6
	JNZ        L_162c
	JMP        L_16b2
L_162c:
	CMP        word ptr [BP + -4h],94h	; local_6
	JZ         L_16b2
	CMP        word ptr [BP + -4h],0d8h	; local_6
	JZ         L_16b2
	CMP        word ptr [BP + -4h],0f0h	; local_6
	JZ         L_16b2
	MOV        AX,word ptr [BP + -0ah]	; local_c
	SUB        AX,4h
	CMP        AX,1bh
	JA         L_16b2
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 984ah]
	db 90h
	db 90h
	db 2Bh
	db 0C0h
	db 50h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 62h
	db 88h
	db 0Bh
	db 0C0h
	db 75h
	db 4Eh
	db 0E9h
	db 8Dh
	db 00h
	db 90h
	db 2Bh
	db 0C0h
	db 50h
	db 0B8h
	db 02h
	db 00h
	db 50h
	db 0E8h
	db 50h
	db 88h
	db 3Dh
	db 02h
	db 00h
	db 74h
	db 3Bh
	db 0EBh
	db 7Bh
	db 90h
	db 26h
	db 98h
	db 82h
	db 98h
	db 26h
	db 98h
	db 26h
	db 98h
	db 26h
	db 98h
	db 38h
	db 98h
	db 38h
	db 98h
	db 38h
	db 98h
	db 38h
	db 98h
	db 38h
	db 98h
	db 38h
	db 98h
	db 38h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 82h
	db 98h
	db 26h
	db 98h
	db 26h
	db 98h
L_16b2:
	MOV        SI,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ch]
	MOV        DS:[0a526h],AL
	MOV        AL,byte ptr [SI + 5c5dh]
	MOV        DS:[0a527h],AL
	MOV        AL,byte ptr [BP + -6h]	; local_8
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AL,byte ptr [BP + -8h]	; local_a
	MOV        byte ptr [SI + 5c5dh],AL
	OR         byte ptr DS:[24e6h],2h
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       SUB_0000_c232
	MOV        BX,AX
	CMP        byte ptr [BX],0dch
	JNZ        L_16f4
	SUB        AL,AL
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
L_16f4:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_1578 ENDP
F_16fc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -10h],AX	; local_12
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 5c5ch]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,byte ptr [BX + 5c5dh]
	MOV        word ptr [BP + -6h],AX	; local_8
	SUB        DI,DI
	MOV        AX,word ptr [BP + -4h]	; local_6
	DEC        AX
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,word ptr [BP + -6h]	; local_8
	INC        AX
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AX,word ptr [BP + -4h]	; local_6
	INC        AX
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        AX,word ptr [BP + -6h]	; local_8
	DEC        AX
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        SI,word ptr [BP + 4h]	; param_1
L_1741:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_1760
	CMP        AX,1h
	JZ         L_177c
	CMP        AX,2h
	JZ         L_1790
	CMP        AX,3h
	JZ         L_17a8
	JMP        L_17c0
L_1760:
	PUSH       SI
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0eh]	; local_10
	CALL       F_1482
	OR         AX,AX
	JZ         L_17c9
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffffh
L_1775:
	PUSH       AX
	CALL       F_1578
	JMP        L_17c9
	db 90h
L_177c:
	PUSH       SI
	PUSH       word ptr [BP + -0ch]	; local_e
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       F_1482
	OR         AX,AX
	JZ         L_17c9
	PUSH       SI
	MOV        AX,1h
	JMP        L_17ba
L_1790:
	PUSH       SI
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_1482
	OR         AX,AX
	JZ         L_17c9
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	JMP        L_1775
	db 90h
L_17a8:
	PUSH       SI
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       F_1482
	OR         AX,AX
	JZ         L_17c9
	PUSH       SI
	MOV        AX,0ffffh
L_17ba:
	PUSH       AX
	SUB        AX,AX
	JMP        L_1775
	db 90h
L_17c0:
	INC        DI
	CMP        DI,3h
	JGE        L_17c9
	JMP        L_1741
L_17c9:
	MOV        word ptr [BP + -2h],DI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_16fc ENDP
F_17d4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ch]
	SUB        AH,AH
	MOV        DI,AX
	MOV        word ptr [BP + -6h],DI	; local_8
	MOV        AL,byte ptr [SI + 5c5dh]
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AX,DI
	SUB        AL,byte ptr DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,7fh
	JLE        L_180a
	SUB        word ptr [BP + -8h],100h	; local_a
L_180a:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5dh]
	SUB        AL,byte ptr DS:[5897h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX	; local_e
	CMP        AX,7fh
	JLE        L_1828
	SUB        word ptr [BP + -0ch],100h	; local_e
L_1828:
	CMP        word ptr [BP + -8h],0h	; local_a
	JNZ        L_1836
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_1864
	db 90h
L_1836:
	CMP        word ptr [BP + -8h],0h	; local_a
	JLE        L_184a
	MOV        AX,1h
	MOV        word ptr [BP + 4h],AX	; param_1
	MOV        word ptr [BP + -2h],0ffffh	; local_4
	JMP        L_1864
	db 90h
L_184a:
	CMP        word ptr [BP + -8h],0h	; local_a
	JGE        L_1855
	SUB        AX,AX
	MOV        word ptr [BP + 4h],AX	; param_1
L_1855:
	CMP        word ptr [BP + -8h],0h	; local_a
	JGE        L_1872
	MOV        AX,1h
	MOV        word ptr [BP + 4h],AX	; param_1
	MOV        word ptr [BP + -2h],AX	; local_4
L_1864:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JNZ        L_1880
	MOV        word ptr [BP + -4h],0h	; local_6
	JMP        L_18ae
	db 90h
L_1872:
	CMP        word ptr [BP + -8h],0h	; local_a
	JLE        L_1864
	SUB        AX,AX
	MOV        word ptr [BP + 4h],AX	; param_1
	JMP        L_1864
	db 90h
L_1880:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JLE        L_1894
	MOV        AX,1h
	MOV        word ptr [BP + 4h],AX	; param_1
	MOV        word ptr [BP + -4h],0ffffh	; local_6
	JMP        L_18ae
	db 90h
L_1894:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JGE        L_189f
	SUB        AX,AX
	MOV        word ptr [BP + 4h],AX	; param_1
L_189f:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JGE        L_18ee
	MOV        AX,1h
	MOV        word ptr [BP + 4h],AX	; param_1
	MOV        word ptr [BP + -4h],AX	; local_6
L_18ae:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	CMP        AX,1h
	JNZ        L_1930
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_18fc
	MOV        SI,word ptr [BP + -6h]	; local_8
	ADD        SI,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       SI
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_1482
	OR         AX,AX
	JZ         L_18fc
	PUSH       SI
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_14c8
	OR         AX,AX
	JZ         L_18fc
L_18e2:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	JMP        L_192a
	db 90h
L_18ee:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JLE        L_18ae
	SUB        AX,AX
	MOV        word ptr [BP + 4h],AX	; param_1
	JMP        L_18ae
	db 90h
L_18fc:
	CMP        word ptr [BP + -4h],0h	; local_6
	JZ         L_197d
	MOV        SI,word ptr [BP + -0ah]	; local_c
	ADD        SI,word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       SI
	CALL       F_1482
	OR         AX,AX
	JZ         L_197d
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       SI
	CALL       F_14c8
	OR         AX,AX
	JZ         L_197d
L_1921:
	PUSH       word ptr [BP + 6h]	; param_2
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
L_192a:
	CALL       F_1578
	JMP        L_1983
	db 90h
L_1930:
	CMP        word ptr [BP + -4h],0h	; local_6
	JZ         L_1955
	MOV        SI,word ptr [BP + -0ah]	; local_c
	ADD        SI,word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       SI
	CALL       F_1482
	OR         AX,AX
	JZ         L_1955
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       SI
	CALL       F_14c8
	OR         AX,AX
	JNZ        L_1921
L_1955:
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_197d
	MOV        SI,word ptr [BP + -6h]	; local_8
	ADD        SI,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       SI
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_1482
	OR         AX,AX
	JZ         L_197d
	PUSH       SI
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_14c8
	OR         AX,AX
	JZ         L_197d
	JMP        L_18e2
L_197d:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_16fc
L_1983:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_17d4 ENDP
F_198c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ah]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AL,byte ptr [BP + -6h]	; local_8
	AND        AL,0fch
	CMP        AL,0ech
	JNZ        L_19d2
	XOR        byte ptr [SI + 5c5fh],1h
	JNZ        L_19b7
	JMP        L_1a58
L_19b7:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_19c8
	JMP        L_1a4e
L_19c8:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_16fc
	JMP        L_1a58
	db 90h
L_19d2:
	CMP        word ptr [BP + -6h],0fch	; local_8
	JNZ        L_19fe
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_14ea
	OR         AX,AX
	JZ         L_1a4e
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	INC        byte ptr [BX + 5c5fh]
	CMP        AL,14h
	JNC        L_1a4e
	PUSH       word ptr [BP + 4h]	; param_1
	SUB        AX,AX
	JMP        L_1a54
	db 90h
L_19fe:
	MOV        AL,byte ptr [BP + -6h]	; local_8
	AND        AL,0fch
	CMP        AL,2ch
	JNZ        L_1a4e
	CMP        byte ptr DS:[5892h],0h
	JZ         L_1a58
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ah]
	SUB        AH,AH
	SUB        AX,2ch
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        DI,AX
	SHL        DI,CL
	MOV        BL,byte ptr DS:[5892h]
	SUB        BH,BH
	SHL        BX,1h
	MOV        AX,word ptr [BX + DI + 2bf6h]
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,4h
	JZ         L_1a4e
	INC        byte ptr [SI + 5c61h]
	MOV        AL,byte ptr [SI + 5c61h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -2h]	; local_4
	JBE        L_1a4e
	MOV        byte ptr [SI + 5c61h],AH
	JMP        L_1a58
L_1a4e:
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,1h
L_1a54:
	PUSH       AX
	CALL       F_17d4
L_1a58:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_198c ENDP
F_1a60 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h	; local_4
	CMP        byte ptr DS:[587ah],54h
	JNZ        L_1a7a
L_1a74:
	SUB        AX,AX
	JMP        L_1b38
	db 90h
L_1a7a:
	CMP        byte ptr DS:[587ah],51h
	JNZ        L_1a88
	XOR        byte ptr DS:[2c55h],1h
	JNZ        L_1a74
L_1a88:
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	MOV        byte ptr [BP + -6h],AL	; local_8
	CMP        AL,12h
	JZ         L_1a98
	CMP        AL,14h
	JNZ        L_1a9f
L_1a98:
	XOR        byte ptr DS:[2c57h],1h
	JNZ        L_1a74
L_1a9f:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        SI,AX
	CALL       F_0d8c
	CMP        AX,SI
	JLE        L_1ab6
	CALL       F_0fc4
L_1ab6:
	MOV        SI,1fh
	MOV        DI,5d52h
L_1abc:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	PUSH       AX
	CALL       F_105c
	OR         AX,AX
	JZ         L_1ad5
	PUSH       SI
	CALL       F_131a
	ADD        word ptr [BP + -2h],AX	; local_4
	JNZ        L_1ad5
	PUSH       SI
	CALL       F_198c
L_1ad5:
	SUB        DI,8h
	DEC        SI
	OR         SI,SI
	JG         L_1abc
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        SI,1fh
	MOV        DI,5d52h
	MOV        word ptr [BP + -6h],5d54h	; local_8
	MOV        word ptr [BP + -0ah],5d55h	; local_c
L_1af0:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	PUSH       AX
	CALL       F_105c
	OR         AX,AX
	JZ         L_1b22
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX]
	SUB        AL,byte ptr DS:[589bh]
	CMP        AL,1fh
	JA         L_1b16
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        AL,byte ptr [BX]
	SUB        AL,byte ptr DS:[589ch]
	CMP        AL,1fh
	JBE        L_1b22
L_1b16:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_b8a4
L_1b22:
	SUB        DI,8h
	SUB        word ptr [BP + -6h],8h	; local_8
	SUB        word ptr [BP + -0ah],8h	; local_c
	DEC        SI
	OR         SI,SI
	JG         L_1af0
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        AX,word ptr [BP + -2h]	; local_4
L_1b38:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1a60 ENDP
F_1b3e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	MOV        AX,6b2ch
	PUSH       AX
	CALL       SUB_0000_9680
	CALL       SUB_0000_b82c
	MOV        BX,word ptr DS:[5876h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b4h]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	SUB        AX,63h
	NEG        AX
	MOV        word ptr [BP + -6h],AX	; local_8
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_986e
	MOV        AX,6b4ah
	PUSH       AX
	CALL       SUB_0000_9680
	JMP        L_1b86
	db 90h
L_1b80:
	CMP        byte ptr [BP + -2h],4eh	; local_4
	JZ         L_1b90
L_1b86:
	CALL       SUB_0000_a49c
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,59h
	JNZ        L_1b80
L_1b90:
	MOV        AL,byte ptr [BP + -2h]	; local_4
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_94ea
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_94ea
	CMP        byte ptr [BP + -2h],59h	; local_4
	JNZ        L_1bbd
	MOV        AX,word ptr [BP + -6h]	; local_8
	SUB        word ptr DS:[57aah],AX
	MOV        byte ptr DS:[0a9fah],1h
	CMP        word ptr DS:[57aah],0h
	JGE        L_1be4
	ADD        word ptr DS:[57aah],AX
L_1bbd:
	CALL       SUB_0000_b714
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,0e4h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_b8a4
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_df80
L_1be4:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1b3e ENDP
F_1be8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_9ec2
	OR         AX,AX
	JZ         L_1c01
	JMP        L_1ca9
L_1c01:
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_1c0b
	JMP        L_1ca9
L_1c0b:
	CALL       SUB_0000_d740
	MOV        AX,6b64h
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_b916
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_1ca2
	MOV        DI,55b3h
	MOV        word ptr [BP + -0ah],55a8h	; local_c
	MOV        word ptr [BP + -0ch],55b5h	; local_e
L_1c37:
	CMP        byte ptr [DI],44h
	JZ         L_1c8a
	CMP        byte ptr [DI],53h
	JZ         L_1c8a
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_9680
	MOV        AX,6b8ch
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        word ptr [BP + -4h],3h	; local_6
	MOV        SI,3h
L_1c56:
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_b916
	MOV        AX,2eh
	PUSH       AX
	CALL       SUB_0000_94ea
	DEC        SI
	JNZ        L_1c56
	MOV        AX,6b9ch
	PUSH       AX
	CALL       SUB_0000_9680
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_9ec2
	MOV        BX,word ptr [BP + -0ch]	; local_e
	MOV        CL,byte ptr [BX]
	SUB        CH,CH
	CMP        CX,AX
	JNC        L_1c8a
	CALL       F_1b3e
	JMP        L_1ca9
	db 90h
L_1c8a:
	ADD        DI,20h
	ADD        word ptr [BP + -0ah],20h	; local_c
	ADD        word ptr [BP + -0ch],20h	; local_e
	INC        word ptr [BP + -2h]	; local_4
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -2h],AX	; local_4
	JC         L_1c37
L_1ca2:
	MOV        AX,6ba0h
	PUSH       AX
	CALL       SUB_0000_9680
L_1ca9:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
F_1be8 ENDP
_TEXT ENDS
END
