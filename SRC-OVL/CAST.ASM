_TEXT SEGMENT BYTE 'CODE'
ORG c14ah
SUB_0000_c14a:
ORG c186h
SUB_0000_c186:
ORG c1aah
SUB_0000_c1aa:
ORG a880h
SUB_0000_a880:
ORG c156h
SUB_0000_c156:
ORG c162h
SUB_0000_c162:
ORG 8482h
SUB_0000_8482:
ORG 58d0h
SUB_0000_58d0:
ORG 9990h
SUB_0000_9990:
ORG 842eh
SUB_0000_842e:
ORG c19eh
SUB_0000_c19e:
ORG 6112h
SUB_0000_6112:
ORG bf16h
SUB_0000_bf16:
ORG bdf6h
SUB_0000_bdf6:
ORG a586h
SUB_0000_a586:
ORG 50e8h
SUB_0000_50e8:
ORG bbfeh
SUB_0000_bbfe:
ORG 9414h
SUB_0000_9414:
ORG 972ch
SUB_0000_972c:
ORG 70f2h
SUB_0000_70f2:
ORG 96c6h
SUB_0000_96c6:
ORG 7b3eh
SUB_0000_7b3e:
ORG bf46h
SUB_0000_bf46:
ORG 75e4h
SUB_0000_75e4:
ORG bdaeh
SUB_0000_bdae:
ORG 7f94h
SUB_0000_7f94:
ORG be32h
SUB_0000_be32:
ORG c1c2h
SUB_0000_c1c2:
ORG c1ceh
SUB_0000_c1ce:
ORG 6980h
SUB_0000_6980:
ORG be1ah
SUB_0000_be1a:
ORG be02h
SUB_0000_be02:
ORG 66ech
SUB_0000_66ec:
ORG 573ah
SUB_0000_573a:
ORG 8874h
SUB_0000_8874:
ORG 6212h
SUB_0000_6212:
ORG 8a08h
SUB_0000_8a08:
ORG c10eh
SUB_0000_c10e:
ORG 7b66h
SUB_0000_7b66:
ORG 770eh
SUB_0000_770e:
ORG bb9eh
SUB_0000_bb9e:
ORG bb92h
SUB_0000_bb92:
ORG 75a2h
SUB_0000_75a2:
ORG 83e8h
SUB_0000_83e8:
ORG c1e6h
SUB_0000_c1e6:
ORG c012h
SUB_0000_c012:
ORG 8f7ch
SUB_0000_8f7c:
ORG 5c14h
SUB_0000_5c14:
ORG 8ed0h
SUB_0000_8ed0:
ORG c1dah
SUB_0000_c1da:
ORG c1f2h
SUB_0000_c1f2:
ORG 8e2ah
SUB_0000_8e2a:
ORG 8ea0h
SUB_0000_8ea0:
ORG 8fbch
SUB_0000_8fbc:
ORG 4af0h
SUB_0000_4af0:
ORG 4ce4h
SUB_0000_4ce4:
ORG 6362h
SUB_0000_6362:
ORG 8034h
SUB_0000_8034:
ORG 7feeh
SUB_0000_7fee:
ORG 7b2eh
SUB_0000_7b2e:
ORG 638eh
SUB_0000_638e:
ORG 62bch
SUB_0000_62bc:
ORG a92eh
SUB_0000_a92e:
ORG bf6ah
SUB_0000_bf6a:
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
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	CMP        AX,2fh
	JZ         L_0025
	CMP        AX,0eh
	JZ         L_0025
	CMP        AX,0fh
	JNZ        L_002a
L_0025:
	MOV        AX,1h
	JMP        L_002c
L_002a:
	SUB        AX,AX
L_002c:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0000 ENDP
F_0032 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 4h]
	MOV        DS:[589dh],AL
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_c14a
	POP        BP
	RET        2h
	db 90h
	; Func
F_0032 ENDP
F_004c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],80h
	JC         L_005e
	JMP        L_00ec
L_005e:
	CMP        word ptr [BP + 4h],3h
	JNZ        L_006a
	MOV        AX,4h
	JMP        L_006d
	db 90h
L_006a:
	MOV        AX,3h
L_006d:
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	MOV        AX,word ptr [SI + 24d6h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	AND        AX,7h
	MOV        word ptr [BP + -2h],AX
	MOV        AX,word ptr [SI + 24deh]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	AND        AX,7h
	MOV        word ptr [BP + -4h],AX
	MOV        DI,AX
	MOV        CL,3h
	SHL        DI,CL
	ADD        DI,word ptr [BP + -2h]
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + DI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX
	TEST       byte ptr [BP + -8h],0f7h
	JZ         L_00c6
	MOV        word ptr [BP + -6h],0h
	JMP        L_0108
	db 90h
L_00c6:
	MOV        AL,byte ptr [BP + -8h]
	AND        AL,8h
	MOV        BX,word ptr [BP + 4h]
	OR         AL,byte ptr [BX + 4596h]
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -2h]
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        byte ptr [BX + SI + 595ah],AL
	JMP        L_0103
L_00ec:
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,byte ptr [BX + 4592h]
	MOV        DS:[589dh],AL
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589dh]
	PUSH       AX
	CALL       SUB_0000_c14a
L_0103:
	MOV        word ptr [BP + -6h],0ffffh
L_0108:
	MOV        AX,word ptr [BP + -6h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_004c ENDP
F_0114 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_c1aa
	MOV        word ptr [BP + -6h],AX
	OR         AX,AX
	JGE        L_012e
	MOV        word ptr [BP + -2h],0ffffh
	JMP        L_01a5
	db 90h
L_012e:
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],53h
	JNZ        L_01a0
	MOV        BX,word ptr [BP + -6h]
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],47h
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_017c
	SUB        SI,SI
	MOV        DI,0ba16h
	MOV        word ptr [BP + -0ah],0ba17h
L_0157:
	MOV        AL,byte ptr [DI]
	AND        AL,0e8h
	CMP        AL,88h
	JNZ        L_0190
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -6h]
	JNZ        L_0190
	PUSH       SI
	CALL       SUB_0000_a880
L_016f:
	MOV        word ptr [BP + -4h],SI
	CMP        SI,20h
	JNZ        L_017c
	MOV        word ptr [BP + -2h],0h
L_017c:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        word ptr [BP + -2h],0ffffh
	MOV        byte ptr DS:[0a9fah],1h
	JMP        L_01a5
	db 90h
L_0190:
	ADD        DI,8h
	ADD        word ptr [BP + -0ah],8h
	INC        SI
	CMP        SI,20h
	JGE        L_016f
	JMP        L_0157
	db 90h
L_01a0:
	MOV        word ptr [BP + -2h],0h
L_01a5:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0114 ENDP
F_01ae PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	CALL       SUB_0000_c1aa
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JGE        L_01c6
	MOV        word ptr [BP + -2h],0ffffh
	JMP        L_01f1
L_01c6:
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        SI,CL
	ADD        SI,55b3h
	CMP        byte ptr [SI],50h
	JNZ        L_01ec
	MOV        byte ptr [SI],47h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        byte ptr DS:[0a9fah],1h
	MOV        word ptr [BP + -2h],1h
	JMP        L_01f1
L_01ec:
	MOV        word ptr [BP + -2h],0h
L_01f1:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_01ae ENDP
F_01fa PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	CALL       SUB_0000_c1aa
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JGE        L_0212
	MOV        word ptr [BP + -2h],0ffffh
	JMP        L_021b
	db 90h
L_0212:
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_c156
	MOV        word ptr [BP + -2h],AX
L_021b:
	CMP        word ptr [BP + -2h],0h
	JZ         L_0228
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_c186
L_0228:
	MOV        AX,word ptr [BP + -2h]
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_01fa ENDP
F_0230 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	CALL       SUB_0000_c162
	OR         AX,AX
	JNZ        L_0244
	MOV        AX,0ffffh
	JMP        L_02ce
	db 90h
L_0244:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_c186
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_8482
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,9dh
	JZ         L_0275
	JA         L_02a8
	CMP        AX,5bh
	JZ         L_0275
	CMP        AX,90h
	JC         L_02c6
	CMP        AX,93h
	JA         L_02c6
L_0275:
	MOV        BX,word ptr [BP + -2h]
	MOV        byte ptr [BX],44h
	MOV        AX,459ah
	PUSH       AX
	CALL       SUB_0000_58d0
	OR         byte ptr DS:[24e6h],2h
	CALL       SUB_0000_9990
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_842e
	MOV        word ptr [BP + -4h],0ffffh
L_02a2:
	MOV        AX,word ptr [BP + -4h]
	JMP        L_02ce
	db 90h
L_02a8:
	CMP        AX,0a5h
	JC         L_02c6
	CMP        AX,0a6h
	JBE        L_0275
	CMP        AX,0a8h
	JC         L_02c6
	CMP        AX,0a9h
	JBE        L_0275
	CMP        AX,0adh
	JC         L_02c6
	CMP        AX,0afh
	JBE        L_0275
L_02c6:
	MOV        word ptr [BP + -4h],0h
	JMP        L_02a2
	db 90h
L_02ce:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0230 ENDP
F_02d2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],20h
	JA         L_02e4
	JMP        L_0398
L_02e4:
	CMP        byte ptr DS:[5893h],80h
	JC         L_02ee
	JMP        L_0398
L_02ee:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	MOV        AX,word ptr [SI + 24d6h]
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,word ptr [SI + 24deh]
	MOV        word ptr [BP + -0ch],AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,DS:[5897h]
	MOV        DI,AX
	MOV        AL,DS:[5895h]
	MOV        CL,6h
	SHL        AX,CL
	MOV        word ptr [BP + -0eh],AX
	MOV        DX,DI
	MOV        CL,3h
	SHL        DX,CL
	ADD        AX,DX
	ADD        AX,SI
	ADD        AX,595ah
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0f0h
	CMP        AL,40h
	JZ         L_0359
	MOV        AX,word ptr [BP + -0ch]
	ADD        AX,DI
	AND        AX,7h
	SHL        AX,CL
	MOV        CX,word ptr [BP + -0ah]
	ADD        CX,SI
	AND        CX,7h
	ADD        AX,CX
	ADD        AX,word ptr [BP + -0eh]
	ADD        AX,595ah
	MOV        word ptr [BP + -2h],AX
L_0359:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX]
	MOV        byte ptr [BP + -0eh],AL
	AND        AL,0f0h
	CMP        AL,40h
	JNZ        L_0390
	TEST       byte ptr [BP + -0eh],1h
	JZ         L_0374
	MOV        AX,45a1h
	PUSH       AX
	CALL       SUB_0000_58d0
L_0374:
	MOV        BX,word ptr [BP + -2h]
	MOV        SI,BX
	MOV        AL,byte ptr [SI]
	AND        AL,8h
	OR         AL,70h
	MOV        byte ptr [BX],AL
	MOV        AX,45ach
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -6h],0ffffh
	JMP        L_0434
L_0390:
	MOV        word ptr [BP + -6h],0h
	JMP        L_0434
L_0398:
	CALL       SUB_0000_c162
	OR         AX,AX
	JNZ        L_03a6
	MOV        AX,0ffffh
	JMP        L_0437
	db 90h
L_03a6:
	MOV        word ptr [BP + -6h],0h
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_8482
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        byte ptr [BP + -0eh],AL
	CMP        AL,0b9h
	JZ         L_03c8
	CMP        AL,0bbh
	JNZ        L_03de
L_03c8:
	DEC        byte ptr [BX]
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        word ptr [BP + -6h],1h
	JMP        L_0434
	db 90h
L_03de:
	MOV        word ptr [BP + -8h],0h
	MOV        DI,5c5ah
L_03e6:
	MOV        SI,DI
	CMP        byte ptr [SI],1h
	JNZ        L_0426
	MOV        AL,byte ptr [SI + 2h]
	SUB        AH,AH
	CMP        AX,word ptr DS:[5876h]
	JNZ        L_0426
	MOV        AL,byte ptr [SI + 3h]
	CMP        AX,word ptr DS:[5878h]
	JNZ        L_0426
	CMP        byte ptr DS:[5893h],7fh
	JA         L_0410
	MOV        AL,DS:[5895h]
	CMP        byte ptr [SI + 4h],AL
	JNZ        L_0426
L_0410:
	AND        byte ptr [SI + 5h],7fh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        word ptr [BP + -6h],1h
L_0420:
	MOV        word ptr [BP + -4h],SI
	JMP        L_0434
	db 90h
L_0426:
	ADD        DI,8h
	INC        word ptr [BP + -8h]
	CMP        word ptr [BP + -8h],20h
	JGE        L_0420
	JMP        L_03e6
L_0434:
	MOV        AX,word ptr [BP + -6h]
L_0437:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_02d2 ENDP
F_043e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_c186
	SUB        DI,DI
	MOV        word ptr [BP + -6h],0ba14h
L_0454:
	MOV        SI,word ptr [BP + -6h]
	PUSH       DI
	CALL       F_0000
	OR         AX,AX
	JNZ        L_048e
	MOV        AL,byte ptr [SI + 2h]
	AND        AL,0c0h
	CMP        AL,40h
	JNZ        L_048e
	MOV        BL,byte ptr [SI + 3h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],20h
	JZ         L_048e
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_c19e
	OR         AX,AX
	JNZ        L_048e
	MOV        byte ptr [SI],1h
	OR         byte ptr [SI + 2h],2h
L_048e:
	ADD        word ptr [BP + -6h],8h
	INC        DI
	CMP        DI,20h
	JL         L_0454
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 0B8h
	db 02h
	db 00h
	db         50h    P
	db 0E8h
	db 0DBh
	db 0BCh
	db 0E8h
	db 90h
	db 0BCh
	db 0C3h
	db 90h
	; Func
F_043e ENDP
F_04b0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_c186
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        word ptr [BP + -0ah],AX
	CMP        AX,6h
	JGE        L_04d8
	MOV        word ptr [BP + -2h],14h
	JMP        L_04f9
L_04d8:
	CMP        word ptr [BP + -0ah],0bh
	JGE        L_04e6
	MOV        word ptr [BP + -2h],16h
	JMP        L_04f9
	db 90h
L_04e6:
	CMP        word ptr [BP + -0ah],0eh
	JGE        L_04f4
	MOV        word ptr [BP + -2h],15h
	JMP        L_04f9
	db 90h
L_04f4:
	MOV        word ptr [BP + -2h],22h
L_04f9:
	MOV        word ptr [BP + -8h],0h
	MOV        word ptr [BP + -0ah],0h
	MOV        AL,byte ptr [BP + -2h]
	SHL        AL,1h
	SHL        AL,1h
	ADD        AL,40h
	MOV        byte ptr [BP + -0ch],AL
	MOV        AX,word ptr [BP + -2h]
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,140h
	MOV        word ptr [BP + -0eh],AX
	MOV        DI,word ptr [BP + -10h]
	MOV        SI,word ptr [BP + -4h]
L_0522:
	CALL       SUB_0000_bf16
	OR         AX,AX
	JZ         L_053c
	MOV        AX,90h
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_bdf6
	OR         AX,AX
	JNZ        L_0548
L_053c:
	INC        word ptr [BP + -0ah]
	CMP        word ptr [BP + -0ah],8h
	JGE        L_0566
	JMP        L_0522
	db 90h
L_0548:
	PUSH       word ptr [BP + -2h]
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_a586
	MOV        word ptr [BP + -6h],AX
	OR         AX,AX
	JGE        L_056c
L_0566:
	MOV        word ptr [BP + -4h],SI
	JMP        L_05aa
	db 90h
L_056c:
	MOV        DI,word ptr [BP + -6h]
	MOV        CL,3h
	SHL        DI,CL
	MOV        AL,byte ptr [DI + 0ba18h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,CL
	ADD        SI,5c5ah
	MOV        AL,16h
	MOV        byte ptr [SI],AL
	MOV        byte ptr [SI + 1h],AL
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_50e8
	MOV        AL,byte ptr [BP + -0ch]
	MOV        byte ptr [SI],AL
	MOV        byte ptr [SI + 1h],AL
	OR         byte ptr [DI + 0ba16h],1h
	MOV        word ptr [BP + -8h],1h
	JMP        L_0566
L_05aa:
	MOV        AX,word ptr [BP + -8h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	db 0B8h
	db 02h
	db 00h
	db         50h    P
	db 0E8h
	db 0CBh
	db 0BBh
	db 0B8h
	db 0A8h
	db         57h    W
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 03h
	db 00h
	db         50h    P
	db 0E8h
	db         48h    H
	db         5Bh    [
	db         50h    P
	db 0B8h
	db 0Fh
	db         27h    '
	db         50h    P
	db 0E8h
	db 0C2h
	db         79h    y
	db 0C6h
	db 06h
	db 0FAh
	db 0A9h
	db 01h
	db 0B8h
	db 01h
	db 00h
	db 0C3h
	db 90h
	; Func
F_04b0 ENDP
F_05dc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ah],0h
	CMP        byte ptr DS:[5893h],7fh
	JA         L_05f3
	JMP        L_0680
L_05f3:
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba18h]
	SUB        AH,AH
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX
	TEST       byte ptr DS:[58a1h],2h
	JZ         L_061a
	MOV        word ptr [BP + -0ah],0h
	JMP        L_0743
L_061a:
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_c186
	SUB        DI,DI
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -14h],AX
	MOV        SI,word ptr [BP + -16h]
L_0630:
	CALL       SUB_0000_bf16
	OR         AX,AX
	JNZ        L_0640
L_0637:
	INC        DI
	CMP        DI,7h
	JGE        L_0679
	JMP        L_0630
	db 90h
L_0640:
	PUSH       word ptr [BP + -14h]
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_bdf6
	OR         AX,AX
	JZ         L_0637
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,DS:[5876h]
	MOV        byte ptr [SI + 0ba1ah],AL
	MOV        byte ptr [BX + 2h],AL
	MOV        AL,DS:[5878h]
	MOV        byte ptr [SI + 0ba1bh],AL
	MOV        byte ptr [BX + 3h],AL
	MOV        word ptr [BP + -0ah],1h
L_0679:
	MOV        word ptr [BP + -4h],DI
	JMP        L_0743
	db 90h
L_0680:
	CALL       SUB_0000_c162
	OR         AX,AX
	JNZ        L_068e
	MOV        AX,0ffffh
	JMP        L_0746
	db 90h
L_068e:
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AX,DS:[5876h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	SUB        AX,CX
	MOV        word ptr [BP + -10h],AX
	MOV        AX,DS:[5878h]
	MOV        CL,byte ptr DS:[5897h]
	SUB        AX,CX
	MOV        word ptr [BP + -12h],AX
	MOV        AL,DS:[589bh]
	SUB        AH,AH
	ADD        AX,20h
	MOV        word ptr [BP + -0ch],AX
	CMP        AX,100h
	JLE        L_06c4
	MOV        word ptr [BP + -0ch],100h
L_06c4:
	MOV        AL,DS:[589ch]
	SUB        AH,AH
	ADD        AX,20h
	MOV        word ptr [BP + -0eh],AX
	CMP        AX,100h
	JLE        L_06d9
	MOV        word ptr [BP + -0eh],100h
L_06d9:
	MOV        word ptr [BP + -0ah],0h
	MOV        AL,DS:[5876h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,DS:[5878h]
	MOV        DI,AX
	JMP        L_0728
L_06ec:
	CMP        SI,word ptr [BP + -0ch]
	JGE        L_0734
	MOV        AX,DI
	MOV        CL,byte ptr DS:[589ch]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_0734
	CMP        DI,word ptr [BP + -0eh]
	JGE        L_0734
	PUSH       SI
	PUSH       DI
	CALL       SUB_0000_8482
	MOV        BX,AX
	CMP        byte ptr [BX],5h
	JNZ        L_0722
	MOV        word ptr [BP + -0ah],0ffffh
	MOV        AX,SI
	MOV        DS:[5896h],AL
	MOV        AX,DI
	MOV        DS:[5897h],AL
	MOV        byte ptr DS:[24e6h],1h
L_0722:
	ADD        SI,word ptr [BP + -10h]
	ADD        DI,word ptr [BP + -12h]
L_0728:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[589bh]
	SUB        CH,CH
	CMP        AX,CX
	JNC        L_06ec
L_0734:
	MOV        word ptr [BP + -8h],DI
	MOV        word ptr [BP + -6h],SI
	CMP        word ptr [BP + -0ah],0h
	JZ         L_0743
	CALL       SUB_0000_bbfe
L_0743:
	MOV        AX,word ptr [BP + -0ah]
L_0746:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_05dc ENDP
F_074c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        word ptr [BP + -4h],20h
	MOV        SI,0ba16h
	MOV        word ptr [BP + -8h],0ba18h
	MOV        word ptr [BP + -0ah],20h
	MOV        DI,word ptr [BP + -2h]
L_0770:
	CMP        byte ptr [SI],0h
	JZ         L_079e
	TEST       byte ptr [SI],80h
	JNZ        L_079e
	TEST       byte ptr [SI],10h
	JZ         L_079e
	AND        byte ptr [SI],0efh
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        DI,AX
	MOV        CL,3h
	SHL        DI,CL
	ADD        DI,5c5ah
	MOV        AL,byte ptr [DI]
	MOV        byte ptr [DI + 1h],AL
	CALL       SUB_0000_9414
	CALL       SUB_0000_972c
L_079e:
	ADD        SI,8h
	ADD        word ptr [BP + -8h],8h
	DEC        word ptr [BP + -0ah]
	JNZ        L_0770
	MOV        word ptr [BP + -2h],DI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_074c ENDP
F_07b4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_c186
	SUB        DI,DI
	SUB        SI,SI
L_07c7:
	CALL       SUB_0000_bf16
	OR         AX,AX
	JZ         L_07e1
	MOV        AX,0bch
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_bdf6
	OR         AX,AX
	JNZ        L_07ea
L_07e1:
	INC        SI
	CMP        SI,8h
	JGE        L_07ed
	JMP        L_07c7
	db 90h
L_07ea:
	MOV        DI,1h
L_07ed:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -6h],SI
	OR         DI,DI
	JZ         L_083c
	MOV        word ptr [BP + -4h],0h
	SUB        DI,DI
L_07fe:
	MOV        AX,1fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_a586
	MOV        SI,AX
	OR         SI,SI
	JGE        L_0824
L_081c:
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -2h],SI
	JMP        L_083c
L_0824:
	MOV        BX,SI
	MOV        CL,3h
	SHL        BX,CL
	OR         byte ptr [BX + 0ba16h],1h
	MOV        word ptr [BP + -4h],1h
	INC        DI
	CMP        DI,4h
	JGE        L_081c
	JMP        L_07fe
L_083c:
	MOV        AX,word ptr [BP + -4h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_07b4 ENDP
F_0846 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	CALL       SUB_0000_c162
	OR         AX,AX
	JNZ        L_0858
	MOV        AX,0ffffh
	JMP        L_08a8
L_0858:
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_c186
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_8482
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -4h],0h
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,0b8h
	JC         L_089b
	CMP        AX,0b9h
	JBE        L_088e
	CMP        AX,0bah
	JC         L_089b
	CMP        AX,0bbh
	JBE        L_08a0
	JMP        L_089b
L_088e:
	MOV        byte ptr [BX],97h
L_0891:
	MOV        word ptr [BP + -4h],1h
	OR         byte ptr DS:[24e6h],2h
L_089b:
	MOV        AX,word ptr [BP + -4h]
	JMP        L_08a8
L_08a0:
	MOV        BX,word ptr [BP + -2h]
	MOV        byte ptr [BX],98h
	JMP        L_0891
L_08a8:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0846 ENDP
F_08ac PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	CALL       SUB_0000_c1aa
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JGE        L_08c4
	MOV        word ptr [BP + -2h],0ffffh
	JMP        L_0916
L_08c4:
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JZ         L_08e0
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_08e8
	CMP        byte ptr DS:[58a3h],0h
	JNZ        L_08e8
L_08e0:
	MOV        word ptr [BP + -2h],0h
	JMP        L_0916
	db 90h
L_08e8:
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_08f6
	CMP        byte ptr DS:[58a3h],0h
	JZ         L_08e0
L_08f6:
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,word ptr [SI + 55bah]
	MOV        word ptr [SI + 55b8h],AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        byte ptr DS:[0a9fah],1h
	MOV        word ptr [BP + -2h],1h
L_0916:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_08ac ENDP
F_091e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_c186
	CALL       SUB_0000_70f2
	SUB        SI,SI
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55bch
	MOV        word ptr [BP + -4h],AX
	MOV        DI,0ba16h
L_0942:
	CMP        byte ptr [DI],0h
	JZ         L_098b
	PUSH       SI
	CALL       SUB_0000_96c6
	OR         AX,AX
	JZ         L_098b
	CALL       SUB_0000_7b3e
	PUSH       SI
	MOV        CX,0fffeh
	PUSH       CX
	MOV        word ptr [BP + -8h],AX
	CALL       SUB_0000_bf46
	CMP        AX,word ptr [BP + -8h]
	JG         L_098b
	PUSH       SI
	CALL       SUB_0000_75e4
	PUSH       word ptr [BP + -4h]
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_6112
	PUSH       AX
	CALL       SUB_0000_bdae
	PUSH       AX
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_7f94
	PUSH       SI
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_be32
L_098b:
	ADD        DI,8h
	INC        SI
	CMP        SI,20h
	JL         L_0942
	MOV        word ptr [BP + -2h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_091e ENDP
F_09a0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        AX,45bbh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_c1c2
	OR         AX,AX
	JNZ        L_09c6
L_09bf:
	MOV        AX,0ffffh
	JMP        L_0a56
	db 90h
L_09c6:
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0feh
	CMP        AL,84h
	JNZ        L_09e8
L_09e4:
	SUB        AX,AX
	JMP        L_0a56
L_09e8:
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	CALL       SUB_0000_c1ce
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JL         L_09e4
	PUSH       AX
	CALL       F_0000
	OR         AX,AX
	JNZ        L_09e4
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_96c6
	OR         AX,AX
	JZ         L_09e4
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_c19e
	OR         AX,AX
	JNZ        L_09e4
	MOV        SI,word ptr [BP + -2h]
	MOV        CL,3h
	SHL        SI,CL
	XOR        byte ptr [SI + 0ba16h],1h
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_0a46
	MOV        BL,byte ptr [SI + 0ba17h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],47h
	CALL       SUB_0000_6980
L_0a46:
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_be1a
	MOV        AX,45c6h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_09bf
L_0a56:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_09a0 ENDP
F_0a5c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        AX,45d1h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_c1c2
	OR         AX,AX
	JNZ        L_0a82
	MOV        AX,0ffffh
	JMP        L_0af9
	db 90h
	db 90h
L_0a82:
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	CALL       SUB_0000_c1ce
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JGE        L_0aa2
L_0a9d:
	SUB        AX,AX
	JMP        L_0af9
	db 90h
L_0aa2:
	PUSH       word ptr [BP + -2h]
	CALL       F_0000
	OR         AX,AX
	JNZ        L_0a9d
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_c19e
	OR         AX,AX
	JNZ        L_0a9d
	MOV        SI,word ptr [BP + -2h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba1ah]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	MOV        word ptr [BP + -6h],AX
	MOV        AX,word ptr [BP + -2h]
	NEG        AX
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_be02
	MOV        AX,14h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -6h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_a586
	MOV        AX,1h
L_0af9:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db         56h    V
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db 8Bh
	db 0F0h
	db 0B1h
	db 03h
	db 0D3h
	db 0E6h
	db 8Ah
	db 9Ch
	db 18h
	db 0BAh
	db         2Ah    *
	db 0FFh
	db 0D3h
	db 0E3h
	db 0C6h
	db 87h
	db         5Bh    [
	db         5Ch    \
	db 1Dh
	db 80h
	db 8Ch
	db 16h
	db 0BAh
	db 10h
	db 0B8h
	db 07h
	db 00h
	db         50h    P
	db 0E8h
	db         63h    c
	db 0B6h
	db 0B8h
	db 01h
	db 00h
	db         5Eh    ^
	db 0C3h
	; Func
F_0a5c ENDP
F_0b28 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,18h
	PUSH       DI
	PUSH       SI
	MOV        AX,45dch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_c1c2
	OR         AX,AX
	JNZ        L_0b4e
	MOV        AX,0ffffh
	JMP        L_0c92
L_0b4e:
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	CALL       SUB_0000_c1ce
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JGE        L_0b72
	MOV        word ptr [BP + -6h],0h
	JMP        L_0c8f
	db 90h
L_0b72:
	MOV        AX,0ffh
	MOV        word ptr [BP + -0ah],AX
	MOV        word ptr [BP + -2h],AX
	SUB        SI,SI
	MOV        DI,5c5ah
	MOV        CX,AX
L_0b82:
	CMP        byte ptr [DI],0h
	JZ         L_0b8a
	JMP        L_0c4e
L_0b8a:
	MOV        CX,SI
L_0b8c:
	MOV        word ptr [BP + -8h],SI
	MOV        word ptr [BP + -0ah],CX
	CMP        CX,0ffh
	JNZ        L_0b9b
	JMP        L_0c8f
L_0b9b:
	SUB        SI,SI
	MOV        DI,0ba16h
	MOV        CX,word ptr [BP + -2h]
L_0ba3:
	CMP        byte ptr [DI],0h
	JZ         L_0bab
	JMP        L_0c5e
L_0bab:
	MOV        CX,SI
L_0bad:
	MOV        word ptr [BP + -8h],SI
	MOV        word ptr [BP + -2h],CX
	CMP        CX,0ffh
	JNZ        L_0bbc
	JMP        L_0c8f
L_0bbc:
	MOV        AX,CX
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -14h],AX
	MOV        AX,word ptr [BP + -4h]
	SHL        AX,CL
	MOV        word ptr [BP + -16h],AX
	MOV        BX,word ptr [BP + -14h]
	MOV        SI,AX
	PUSH       DI
	LEA        DI,[BX + 0ba14h]
	LEA        SI,[SI + 0ba14h]
	PUSH       DS
	POP        ES
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	POP        DI
	MOV        AL,byte ptr [BP + -0ah]
	MOV        byte ptr [BX + 0ba18h],AL
	MOV        AX,word ptr [BP + -0ah]
	SHL        AX,CL
	MOV        word ptr [BP + -18h],AX
	MOV        BX,AX
	MOV        SI,word ptr [BP + -16h]
	MOV        SI,word ptr [SI + 0ba18h]
	AND        SI,0ffh
	SHL        SI,CL
	PUSH       DI
	LEA        DI,[BX + 5c5ah]
	LEA        SI,[SI + 5c5ah]
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	POP        DI
	MOV        DI,word ptr [BP + -14h]
	ADD        DI,0ba1bh
	ADD        AX,5c5dh
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,word ptr [BP + -14h]
	ADD        AX,0ba1ah
	MOV        word ptr [BP + -10h],AX
	MOV        AX,BX
	ADD        AX,5c5ch
	MOV        word ptr [BP + -12h],AX
	MOV        SI,word ptr [BP + -6h]
L_0c2f:
	CALL       SUB_0000_bf16
	OR         AX,AX
	JZ         L_0c49
	MOV        AX,1ch
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_bdf6
	OR         AX,AX
	JNZ        L_0c6e
L_0c49:
	SUB        SI,SI
	JMP        L_0c88
	db 90h
L_0c4e:
	ADD        DI,8h
	INC        SI
	CMP        SI,20h
	JL         L_0c5a
	JMP        L_0b8c
L_0c5a:
	JMP        L_0b82
	db 90h
L_0c5e:
	ADD        DI,8h
	INC        SI
	CMP        SI,20h
	JL         L_0c6a
	JMP        L_0bad
L_0c6a:
	JMP        L_0ba3
	db 90h
L_0c6e:
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,DS:[5876h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -12h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -0eh]
	MOV        AL,DS:[5878h]
	MOV        byte ptr [DI],AL
	MOV        byte ptr [BX],AL
	MOV        SI,1h
L_0c88:
	OR         SI,SI
	JZ         L_0c2f
	MOV        word ptr [BP + -6h],SI
L_0c8f:
	MOV        AX,word ptr [BP + -6h]
L_0c92:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0b28 ENDP
F_0c98 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_c186
	SUB        SI,SI
	MOV        word ptr [BP + -6h],0ba14h
L_0cae:
	MOV        DI,word ptr [BP + -6h]
	MOV        AL,byte ptr [DI + 2h]
	AND        AL,0c0h
	CMP        AL,40h
	JNZ        L_0cda
	PUSH       SI
	CALL       F_0000
	OR         AX,AX
	JNZ        L_0cda
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_c19e
	OR         AX,AX
	JNZ        L_0cda
	MOV        byte ptr [DI],1h
	OR         byte ptr [DI + 2h],2h
L_0cda:
	ADD        word ptr [BP + -6h],8h
	INC        SI
	CMP        SI,20h
	JL         L_0cae
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -4h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0c98 ENDP
F_0cf0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AL,DS:[587ch]
	AND        AL,0f0h
	CMP        AL,20h
	JZ         L_0d46
	MOV        AX,45e7h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_66ec
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,20h
	JC         L_0d16
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_573a
L_0d16:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	CMP        byte ptr [BP + -2h],31h
	JC         L_0d46
	CMP        byte ptr [BP + -2h],38h
	JA         L_0d46
	SUB        byte ptr [BP + -2h],31h
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_8874
	OR         AX,AX
	JZ         L_0d46
	MOV        AX,0ffffh
	JMP        L_0d48
L_0d46:
	SUB        AX,AX
L_0d48:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0cf0 ENDP
F_0d4c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_c186
	MOV        word ptr [BP + -4h],0ffffh
	SUB        DI,DI
	MOV        SI,5c5ah
L_0d65:
	CMP        byte ptr [SI],0fch
	JNZ        L_0d92
	MOV        AX,45f2h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,2648h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,6d60h
	PUSH       AX
	MOV        AX,3e8h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_6212
	MOV        word ptr [BP + -4h],0h
L_0d8d:
	MOV        word ptr [BP + -2h],DI
	JMP        L_0d9e
L_0d92:
	ADD        SI,8h
	INC        DI
	CMP        DI,20h
	JGE        L_0d8d
	JMP        L_0d65
	db 90h
L_0d9e:
	CMP        word ptr [BP + -4h],0h
	JZ         L_0db1
	MOV        byte ptr DS:[587ah],54h
	MOV        byte ptr DS:[588eh],0ah
	CALL       SUB_0000_6980
L_0db1:
	MOV        AX,word ptr [BP + -4h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0d4c ENDP
F_0dba PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       SI
	MOV        AX,1h
	MOV        word ptr [BP + -6h],AX
	MOV        DS:[588fh],AL
	MOV        DS:[5890h],AL
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	MOV        word ptr [BP + -0ah],AX
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JGE        L_0de2
	JMP        L_11d9
L_0de2:
	MOV        AX,4603h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_c10e
	MOV        word ptr [BP + -2h],AX
	CMP        AX,0ffffh
	JNZ        L_0dfe
	MOV        AX,4611h
L_0df7:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_11d9
L_0dfe:
	CMP        word ptr [BP + -2h],-2h
	JNZ        L_0e0a
	MOV        AX,4618h
	JMP        L_0df7
	db 90h
L_0e0a:
	MOV        AX,word ptr [BP + -2h]
	CWD
	MOV        CX,6h
	IDIV       CX
	INC        AX
	MOV        word ptr [BP + -8h],AX
	MOV        DS:[588fh],AL
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_0e2c
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 1c90h],8h
	JMP        L_0e8e
	db 90h
L_0e2c:
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_0e3e
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 1c90h],1h
	JMP        L_0e8e
	db 90h
L_0e3e:
	CMP        byte ptr DS:[5893h],12h
	JNZ        L_0e4c
	CMP        byte ptr DS:[57b4h],0h
	JZ         L_0e53
L_0e4c:
	CMP        byte ptr DS:[5893h],1dh
	JNZ        L_0e74
L_0e53:
	MOV        AX,4624h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,2648h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,6d60h
	PUSH       AX
	MOV        AX,3e8h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_6212
	JMP        L_11d9
L_0e74:
	CMP        byte ptr DS:[5893h],21h
	JNC        L_0e86
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 1c90h],4h
	JMP        L_0e8e
	db 90h
L_0e86:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 1c90h],2h
L_0e8e:
	JNZ        L_0e95
	MOV        word ptr [BP + -0ch],0h
L_0e95:
	CMP        word ptr [BP + -0ch],0h
	JNZ        L_0eb8
	MOV        AX,462fh
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
	JMP        L_11d9
L_0eb8:
	MOV        BX,word ptr [BP + -2h]
	CMP        byte ptr [BX + 57f0h],0h
	JNZ        L_0ec8
	MOV        AX,463ah
	JMP        L_0df7
L_0ec8:
	DEC        byte ptr [BX + 57f0h]
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b7h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JNC        L_0eee
	MOV        AX,4647h
	PUSH       AX
	CALL       SUB_0000_58d0
L_0ee5:
	MOV        word ptr [BP + -0ah],0h
	JMP        L_11a6
	db 90h
L_0eee:
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [BP + -8h]
	SUB        byte ptr [SI + 55b7h],AL
	MOV        word ptr [BP + -0ah],0ffffh
	MOV        AL,byte ptr [SI + 55beh]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JC         L_0ee5
	MOV        AX,word ptr [BP + -2h]
	CMP        AX,2fh
	JBE        L_0f17
	JMP        L_11a6
L_0f17:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0d0c6h]
	db 90h
	db 0B8h
	db         64h    d
	db 00h
	db         50h    P
	db 0E8h
	db         5Bh    [
	db 0B0h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         58h    X
	db 0B2h
	db 0E9h
	db         75h    u
	db 02h
	db 90h
	db 0B8h
	db         30h    0
	db 00h
	db         50h    P
	db 0E8h
	db 0F9h
	db 0F0h
	db 0E9h
	db         6Ah    j
	db 02h
	db 0E8h
	db 0D5h
	db 0F1h
	db 89h
	db         46h    F
	db 0F6h
	db 0E9h
	db         61h    a
	db 02h
	db 90h
	db 0E8h
	db         65h    e
	db 0F2h
	db 0EBh
	db 0F4h
	db 90h
	db 0E8h
	db 0ABh
	db 0F2h
	db 0EBh
	db 0EEh
	db 90h
	db 0E8h
	db 0DBh
	db 0F2h
	db 0EBh
	db 0E8h
	db 90h
	db 0E8h
	db         77h    w
	db 0F3h
	db 0EBh
	db 0E2h
	db 90h
	db 0E8h
	db 0DDh
	db 0F4h
	db 0E9h
	db         42h    B
	db 02h
	db 0E8h
	db 0FBh
	db 0B1h
	db         50h    P
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db         48h    H
	db 0B2h
	db 0E9h
	db         35h    5
	db 02h
	db 90h
	db 0E8h
	db         2Fh    /
	db 0F5h
	db 0E9h
	db         2Eh    .
	db 02h
	db 0E8h
	db         35h    5
	db 0F5h
	db 0EBh
	db 0C2h
	db 90h
	db 0E8h
	db         33h    3
	db 0F6h
	db 0EBh
	db 0BCh
	db 90h
	db 0B8h
	db 0FFh
	db 00h
	db         50h    P
	db 0E8h
	db 0F7h
	db 0AFh
	db 0B8h
	db 03h
	db 00h
	db 0EBh
	db 9Ah
	db 0B8h
	db         31h    1
	db 00h
	db 0EBh
	db 0A0h
	db 90h
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db 0B0h
	db 0F0h
	db 0EBh
	db 0A1h
	db 0B8h
	db 01h
	db 00h
	db 0EBh
	db 0F5h
	db 90h
	db 0B8h
	db 02h
	db 00h
	db 0EBh
	db 0EFh
	db 90h
	db 0E8h
	db         2Fh    /
	db 0F6h
	db 0EBh
	db 90h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         6Fh    o
	db 0B1h
	db 0EBh
	db 86h
	db 90h
	db 0B8h
	db         50h    P
	db 00h
	db         50h    P
	db 0B8h
	db 14h
	db 00h
	db         50h    P
	db 0B8h
	db 04h
	db 00h
	db         50h    P
	db 0E8h
	db         69h    i
	db 0B1h
	db 0E9h
	db 0DAh
	db 01h
	db 0B8h
	db 03h
	db 00h
	db 0EBh
	db 0C7h
	db 90h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         28h    (
	db         75h    u
	db 03h
	db 0E9h
	db 09h
	db 0FFh
	db 0B8h
	db 04h
	db 00h
	db         50h    P
	db 0E8h
	db 0A3h
	db 0B1h
	db 0B8h
	db 0FFh
	db 0FFh
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         24h    $
	db 0ADh
	db 0Bh
	db 0C0h
	db         75h    u
	db 03h
	db 0E9h
	db 0B1h
	db 01h
	db 0E8h
	db         26h    &
	db 0ADh
	db 0E9h
	db 0ABh
	db 01h
	db 90h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         28h    (
	db         75h    u
	db 03h
	db 0E9h
	db 0DFh
	db 0FEh
	db 0B8h
	db 04h
	db 00h
	db         50h    P
	db 0E8h
	db         79h    y
	db 0B1h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0EBh
	db 0D7h
	db 90h
	db 0E8h
	db         35h    5
	db 0F7h
	db 0E9h
	db 8Ch
	db 01h
	db 0E8h
	db 97h
	db 0F7h
	db 0E9h
	db 1Fh
	db 0FFh
	db 0E8h
	db         23h    #
	db 0F8h
	db 0E9h
	db 19h
	db 0FFh
	db 0E8h
	db         45h    E
	db 0B1h
	db 89h
	db         46h    F
	db 0F6h
	db 3Dh
	db 0FFh
	db 0FFh
	db         75h    u
	db 03h
	db 0E9h
	db         72h    r
	db 01h
	db 0B8h
	db 05h
	db 00h
	db 0E9h
	db 0F0h
	db 0FEh
	db 0E8h
	db         6Fh    o
	db 0F8h
	db 0E9h
	db 0FFh
	db 0FEh
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0FFh
	db         36h    6
	db 0B6h
	db 13h
	db 0E8h
	db 0Fh
	db 0Fh
	db 0E9h
	db         52h    R
	db 01h
	db 0B8h
	db         51h    Q
	db 00h
	db         50h    P
	db 0B8h
	db 1Eh
	db 00h
	db         50h    P
	db 0B8h
	db 05h
	db 00h
	db 0E9h
	db         63h    c
	db 0FFh
	db 0FFh
	db         76h    v
	db 0FCh
	db 0E8h
	db 0B6h
	db 0F8h
	db 0E9h
	db         3Bh    ;
	db 01h
	db 90h
	db 0B8h
	db         43h    C
	db 00h
	db         50h    P
	db 0B8h
	db 14h
	db 00h
	db         50h    P
	db 0B8h
	db 06h
	db 00h
	db 0E9h
	db         4Bh    K
	db 0FFh
	db 0B8h
	db         4Eh    N
	db 00h
	db         50h    P
	db 0B8h
	db 0Ah
	db 00h
	db 0EBh
	db 0F0h
	db 90h
	db 0B8h
	db 06h
	db 00h
	db         50h    P
	db 0E8h
	db 0FBh
	db 0B0h
	db 0E8h
	db 0ECh
	db 0B0h
	db 0E9h
	db 15h
	db 01h
	db 90h
	db 0E8h
	db 0Bh
	db 0F9h
	db 0E9h
	db 0A7h
	db 0FEh
	db 0E8h
	db 0C1h
	db 0F9h
	db 0E9h
	db 0A1h
	db 0FEh
	db 0E8h
	db         5Dh    ]
	db 0FAh
	db 0E9h
	db 9Bh
	db 0FEh
	db 0B8h
	db         32h    2
	db 00h
	db 0E9h
	db 8Bh
	db 0FEh
	db 0E8h
	db         7Bh    {
	db 0FAh
	db 0E9h
	db 8Fh
	db 0FEh
	db 0B8h
	db 07h
	db 00h
	db         50h    P
	db 0E8h
	db 0CFh
	db 0B0h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         73h    s
	db 10h
	db 0A0h
	db 96h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0A0h
	db 97h
	db         58h    X
	db         50h    P
	db 0E8h
	db 0C3h
	db 0AEh
	db 0E9h
	db 0D8h
	db 00h
	db 0E8h
	db 0F9h
	db 0AEh
	db 0E9h
	db 0D2h
	db 00h
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0B8h
	db 02h
	db 00h
	db         50h    P
	db 0FFh
	db         36h    6
	db 0B4h
	db 13h
	db 0E9h
	db         69h    i
	db 0FFh
	db 90h
	db 0E8h
	db 0AFh
	db 0FBh
	db 0E9h
	db 0BAh
	db 00h
	db 0E8h
	db 0BBh
	db 0B0h
	db         50h    P
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db 80h
	db 0AEh
	db 89h
	db         46h    F
	db 0F6h
	db 0E8h
	db 84h
	db         58h    X
	db 0E9h
	db 0A7h
	db 00h
	db 90h
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db 8Ch
	db 0B0h
	db 0E9h
	db         36h    6
	db 0FEh
	db 90h
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0B8h
	db 04h
	db 00h
	db         50h    P
	db 0FFh
	db         36h    6
	db 0B2h
	db 13h
	db 0E9h
	db         33h    3
	db 0FFh
	db 90h
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0B8h
	db 03h
	db 00h
	db         50h    P
	db 0FFh
	db         36h    6
	db 0AEh
	db 13h
	db 0E9h
	db         21h    !
	db 0FFh
	db 90h
	db 0E8h
	db 0BFh
	db 0FBh
	db 89h
	db         46h    F
	db 0F6h
	db 0Bh
	db 0C0h
	db         74h    t
	db         6Eh    n
	db 0C7h
	db         46h    F
	db 0FAh
	db 00h
	db 00h
	db 0EBh
	db         67h    g
	db 90h
	db 0E8h
	db 09h
	db 0FCh
	db 0E9h
	db 0F9h
	db 0FDh
	db 0A0h
	db 0CEh
	db 0B2h
	db 0CEh
	db 0BCh
	db 0CEh
	db 0C6h
	db 0CEh
	db 0CCh
	db 0CEh
	db 0D2h
	db 0CEh
	db 0D8h
	db 0CEh
	db 0DEh
	db 0CEh
	db 0E4h
	db 0CEh
	db 0F2h
	db 0CEh
	db 0F8h
	db 0CEh
	db 0FEh
	db 0CEh
	db 04h
	db 0CFh
	db 10h
	db 0CFh
	db 16h
	db 0CFh
	db 1Eh
	db 0CFh
	db         24h    $
	db 0CFh
	db         2Ah    *
	db 0CFh
	db         30h    0
	db 0CFh
	db         3Ah    :
	db 0CFh
	db         4Ch    L
	db 0CFh
	db         52h    R
	db 0CFh
	db         7Ch    |
	db 0CFh
	db 94h
	db 0CFh
	db 9Ah
	db 0CFh
	db 0A0h
	db 0CFh
	db 0A6h
	db 0CFh
	db 0BAh
	db 0CFh
	db 0C0h
	db 0CFh
	db 0D4h
	db 0CFh
	db 0E2h
	db 0CFh
	db 0ECh
	db 0CFh
	db 0FAh
	db 0CFh
	db 04h
	db 0D0h
	db 12h
	db 0D0h
	db 18h
	db 0D0h
	db 1Eh
	db 0D0h
	db         24h    $
	db 0D0h
	db         2Ah    *
	db 0D0h
	db         30h    0
	db 0D0h
	db         54h    T
	db 0D0h
	db         66h    f
	db 0D0h
	db         6Ch    l
	db 0D0h
	db 80h
	db 0D0h
	db 8Ah
	db 0D0h
	db 9Ch
	db 0D0h
	db 0AEh
	db 0D0h
	db 0C0h
	db 0D0h
L_11a6:
	CMP        word ptr [BP + -0ah],1h
	JNZ        L_11b6
	MOV        AX,4656h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_11d6
	db 90h
L_11b6:
	CMP        word ptr [BP + -0ah],0h
	JNZ        L_11d6
	MOV        AX,4660h
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
L_11d6:
	MOV        AX,word ptr [BP + -6h]
L_11d9:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0dba ENDP
F_11de PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -2h],1h
	MOV        BX,word ptr [BP + 4h]
	DEC        byte ptr [BX + 5820h]
	MOV        AX,466ah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,7h
	JBE        L_1202
	JMP        L_1350
L_1202:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0d2c0h]
	db 0B8h
	db 0F0h
	db 00h
	db         50h    P
	db 0E8h
	db         71h    q
	db 0ADh
	db 0B8h
	db         73h    s
	db         46h    F
	db         50h    P
	db 0E8h
	db 0B8h
	db         46h    F
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db 68h
	db 0AFh
	db 0E9h
	db         2Fh    /
	db 01h
	db 90h
	db 0B8h
	db         7Bh    {
	db         46h    F
	db         50h    P
	db 0E8h
	db 0A7h
	db         46h    F
	db 0E8h
	db         36h    6
	db 0AFh
	db 89h
	db         46h    F
	db 0FCh
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         73h    s
	db 0Ch
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         78h    x
	db 0AFh
	db 0E9h
	db 0Fh
	db 01h
	db 90h
	db 0C7h
	db         46h    F
	db 0FEh
	db 00h
	db 00h
	db 0E9h
	db 06h
	db 01h
	db 0B8h
	db 89h
	db         46h    F
	db         50h    P
	db 0E8h
	db         7Fh    
	db         46h    F
	db 0B8h
	db         50h    P
	db 00h
	db         50h    P
	db 0B8h
	db         64h    d
	db 00h
	db         50h    P
	db 0B8h
	db 02h
	db 00h
	db         50h    P
	db 0E8h
	db 0D2h
	db 0AEh
	db 0E9h
	db 0EDh
	db 00h
	db 90h
	db 0B8h
	db 96h
	db         46h    F
	db         50h    P
	db 0E8h
	db         65h    e
	db         46h    F
	db 0B8h
	db         4Eh    N
	db 00h
	db         50h    P
	db 0B8h
	db 14h
	db 00h
	db         50h    P
	db 0B8h
	db 03h
	db 00h
	db 0EBh
	db 0E4h
	db 0B8h
	db 0A5h
	db         46h    F
	db         50h    P
	db 0E8h
	db         51h    Q
	db         46h    F
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         7Fh    
	db         76h    v
	db 0Ah
	db 0B8h
	db 0ACh
	db         46h    F
	db         50h    P
	db 0E8h
	db         43h    C
	db         46h    F
	db 0E9h
	db 0C0h
	db 00h
	db 0B8h
	db 04h
	db 00h
	db         50h    P
	db 0E8h
	db 0EFh
	db 0AEh
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         73h    s
	db 10h
	db 0A0h
	db 96h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0A0h
	db 97h
	db         58h    X
	db         50h    P
	db 0E8h
	db 0E3h
	db 0ACh
	db 0E9h
	db 0A2h
	db 00h
	db 0E8h
	db 19h
	db 0ADh
	db 0E9h
	db 9Ch
	db 00h
	db 0B8h
	db 0B7h
	db         46h    F
	db         50h    P
	db 0E8h
	db 15h
	db         46h    F
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         7Fh    
	db         76h    v
	db 10h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db 0C9h
	db 0AEh
	db 89h
	db         46h    F
	db 0FEh
	db 0E9h
	db 81h
	db 00h
	db 90h
	db 90h
	db 90h
	db 0B8h
	db 0C7h
	db         46h    F
	db 0EBh
	db 0B2h
	db 90h
	db 0B8h
	db 0D2h
	db         46h    F
	db         50h    P
	db 0E8h
	db 0F1h
	db         45h    E
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db 80h
	db         73h    s
	db 14h
	db 0E8h
	db 0C1h
	db 0AEh
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db 85h
	db 0ACh
	db 89h
	db         46h    F
	db 0FEh
	db 0E8h
	db 89h
	db         56h    V
	db 0EBh
	db         57h    W
	db 90h
	db 0B8h
	db 0E1h
	db         46h    F
	db 0EBh
	db 8Ah
	db 90h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db 1Dh
	db         74h    t
	db 07h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         28h    (
	db         75h    u
	db 1Ch
	db 0B8h
	db 0ECh
	db         46h    F
	db         50h    P
	db 0E8h
	db 0BBh
	db         45h    E
	db 0B8h
	db 20h
	db 03h
	db         50h    P
	db 0B8h
	db 0D0h
	db 07h
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db         32h    2
	db 00h
	db         50h    P
	db 0E8h
	db 06h
	db         71h    q
	db 0EBh
	db         26h    &
	db 0B8h
	db 0F8h
	db         46h    F
	db         50h    P
	db 0E8h
	db 9Fh
	db         45h    E
	db 0B8h
	db         54h    T
	db 00h
	db         50h    P
	db 0B8h
	db 14h
	db 00h
	db         50h    P
	db 0B8h
	db 07h
	db 00h
	db 0E9h
	db 1Dh
	db 0FFh
	db 90h
	db 8Ah
	db 0D1h
	db 0A2h
	db 0D1h
	db 0CAh
	db 0D1h
	db 0E4h
	db 0D1h
	db 0F8h
	db 0D1h
	db         34h    4
	db 0D2h
	db         58h    X
	db 0D2h
	db 80h
	db 0D2h
L_1350:
	MOV        AX,word ptr [BP + -2h]
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_11de ENDP
F_135a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],1h
	MOV        BX,word ptr [BP + 4h]
	DEC        byte ptr [BX + 5828h]
	MOV        AX,4706h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_138e
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	JMP        L_1391
L_138e:
	CALL       SUB_0000_c1aa
L_1391:
	MOV        word ptr [BP + -8h],AX
	OR         AX,AX
	JGE        L_139b
	JMP        L_1533
L_139b:
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_c186
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JNZ        L_13ba
	MOV        word ptr [BP + 4h],4h
	JMP        L_13cd
	db 90h
L_13ba:
	CMP        word ptr [BP + -2h],1h
	JNZ        L_13cd
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        word ptr [BP + 4h],AX
L_13cd:
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,7h
	JBE        L_13d8
	JMP        L_1530
L_13d8:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0d4a0h]
	db 8Bh
	db         76h    v
	db 0F8h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 81h
	db 0C6h
	db 0B3h
	db         55h    U
	db 80h
	db         3Ch    <
	db         53h    S
	db         75h    u
	db         32h    2
	db 0C6h
	db 04h
	db         47h    G
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         7Fh    
	db         76h    v
	db         47h    G
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db 8Bh
	db 0F0h
	db 8Bh
	db 0FEh
	db 0B1h
	db 03h
	db 0D3h
	db 0E7h
	db 8Ah
	db 85h
	db 17h
	db 0BAh
	db         3Bh    ;
	db         46h    F
	db 0F8h
	db         75h    u
	db 12h
	db 8Ah
	db 85h
	db 16h
	db 0BAh
	db         24h    $
	db 0E8h
	db         3Ch    <
	db 88h
	db         75h    u
	db 08h
	db         56h    V
	db 0E8h
	db         62h    b
	db 94h
	db 0E9h
	db 0Fh
	db 01h
	db 90h
	db 0C7h
	db         46h    F
	db 0FAh
	db 00h
	db 00h
	db 0E9h
	db 06h
	db 01h
	db 0FFh
	db         76h    v
	db 0F8h
	db 0E8h
	db         26h    &
	db 0ADh
	db 89h
	db         46h    F
	db 0FAh
	db 0Bh
	db 0C0h
	db         75h    u
	db 03h
	db 0E9h
	db 0F6h
	db 00h
	db 0B8h
	db 0Eh
	db         47h    G
	db         50h    P
	db 0E8h
	db 8Fh
	db         44h    D
	db 0E8h
	db         3Ch    <
	db         55h    U
	db 0E9h
	db 0E9h
	db 00h
	db 90h
	db 8Bh
	db         76h    v
	db 0F8h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 81h
	db 0C6h
	db 0B3h
	db         55h    U
	db 80h
	db         3Ch    <
	db         50h    P
	db         75h    u
	db 0CAh
	db 0C6h
	db 04h
	db         47h    G
	db 0B8h
	db 17h
	db         47h    G
	db 0EBh
	db 0DDh
	db 8Bh
	db         76h    v
	db 0F8h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 81h
	db 0C6h
	db 0B3h
	db         55h    U
	db 80h
	db         3Ch    <
	db         47h    G
	db         75h    u
	db 0B2h
	db 0C6h
	db 04h
	db         50h    P
	db 0B8h
	db         26h    &
	db         47h    G
	db 0EBh
	db 0C5h
	db 8Bh
	db         76h    v
	db 0F8h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 81h
	db 0C6h
	db 0B3h
	db         55h    U
	db 80h
	db         3Ch    <
	db         47h    G
	db         75h    u
	db 9Ah
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db 80h
	db         73h    s
	db 05h
	db 0C6h
	db 04h
	db         53h    S
	db 0EBh
	db 06h
	db 0FFh
	db         76h    v
	db 0F8h
	db 0E8h
	db 94h
	db 94h
	db 0B8h
	db         31h    1
	db         47h    G
	db 0EBh
	db 9Eh
	db 90h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         7Fh    
	db         76h    v
	db         2Bh    +
	db 0B8h
	db         39h    9
	db         47h    G
	db         50h    P
	db 0E8h
	db         22h    "
	db         44h    D
	db 8Ah
	db 1Eh
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0FFh
	db 0B1h
	db 03h
	db 0D3h
	db 0E3h
	db 8Ah
	db 87h
	db 18h
	db 0BAh
	db         2Ah    *
	db 0E4h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0FCh
	db 8Bh
	db 0D8h
	db 8Bh
	db 0F0h
	db 0B0h
	db 90h
	db 88h
	db         44h    D
	db 01h
	db 0EBh
	db         3Fh    ?
	db 90h
	db 0B8h
	db         4Ch    L
	db         47h    G
	db         50h    P
	db 0E8h
	db 0F7h
	db         43h    C
	db 0EBh
	db         55h    U
	db 90h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         7Fh    
	db         76h    v
	db 0EFh
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db 8Bh
	db 0F0h
	db 0B1h
	db 03h
	db 0D3h
	db 0E6h
	db 80h
	db 8Ch
	db 16h
	db 0BAh
	db 10h
	db 8Ah
	db 84h
	db 18h
	db 0BAh
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0FCh
	db 0B8h
	db         40h    @
	db         47h    G
	db         50h    P
	db 0E8h
	db 0CAh
	db         43h    C
	db 8Bh
	db         5Eh    ^
	db 0FCh
	db 8Bh
	db 0FBh
	db 0B0h
	db 1Dh
	db 88h
	db         45h    E
	db 01h
	db 88h
	db 07h
	db 0EBh
	db 1Ch
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         73h    s
	db 0B7h
	db 0E8h
	db         5Ch    \
	db 0ACh
	db 0EBh
	db 10h
	db         60h    `
	db 0D3h
	db 0AAh
	db 0D3h
	db 0C8h
	db 0D3h
	db 0E0h
	db 0D3h
	db 0F8h
	db 0D3h
	db 20h
	db 0D4h
	db         5Ch    \
	db 0D4h
	db 94h
	db 0D4h
L_1530:
	MOV        AX,word ptr [BP + -6h]
L_1533:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_135a ENDP
F_153c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	MOV        AX,4768h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        byte ptr DS:[5893h],21h
	JNC        L_15a6
	CMP        word ptr [BP + -2h],2ch
	JZ         L_157e
	CMP        word ptr [BP + -2h],2dh
	JZ         L_157e
	CMP        word ptr [BP + -2h],3h
	JLE        L_15a6
	CMP        word ptr [BP + -2h],0bh
	JGE        L_15a6
L_157e:
	MOV        AX,4773h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,DS:[5896h]
	MOV        byte ptr [BX + 5830h],AL
	MOV        AL,DS:[5897h]
	MOV        byte ptr [BX + 5838h],AL
	MOV        AL,DS:[5893h]
	MOV        byte ptr [BX + 5840h],AL
	MOV        AL,DS:[5895h]
	MOV        byte ptr [BX + 5848h],AL
	JMP        L_15ad
L_15a6:
	MOV        AX,477ch
	PUSH       AX
	CALL       SUB_0000_58d0
L_15ad:
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_153c ENDP
F_15b4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        AX,4794h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_15d6
	CMP        AX,1h
	JZ         L_15fe
	CMP        AX,2h
	JZ         L_1604
	JMP        L_15dd
	db 90h
L_15d6:
	MOV        AX,47cch
L_15d9:
	PUSH       AX
	CALL       SUB_0000_58d0
L_15dd:
	MOV        SI,7d0h
L_15e0:
	MOV        AX,0a50h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6212
	ADD        SI,32h
	CMP        SI,61a8h
	JGE        L_160a
	JMP        L_15e0
L_15fe:
	MOV        AX,47d9h
	JMP        L_15d9
	db 90h
L_1604:
	MOV        AX,47e3h
	JMP        L_15d9
	db 90h
L_160a:
	MOV        word ptr [BP + -2h],SI
	MOV        SI,61a8h
L_1610:
	MOV        AX,0a50h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6212
	SUB        SI,32h
	CMP        SI,7d0h
	JG         L_1610
	MOV        word ptr [BP + -2h],SI
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,DS:[5896h]
	CMP        byte ptr [BX + 4882h],AL
	JNZ        L_1656
	MOV        AL,DS:[5897h]
	CMP        byte ptr [BX + 4886h],AL
	JNZ        L_1656
	MOV        AL,DS:[5893h]
	CMP        byte ptr [BX + 488ah],AL
	JNZ        L_1656
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX + 488eh],AL
	JZ         L_1674
L_1656:
	MOV        AX,47f0h
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
	JMP        L_175c
	db 90h
L_1674:
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_7b66
	MOV        AX,47feh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_1696
	CMP        AX,1h
	JZ         L_16fc
	CMP        AX,2h
	JZ         L_1702
	JMP        L_169d
	db 90h
L_1696:
	MOV        AX,4822h
L_1699:
	PUSH       AX
	CALL       SUB_0000_58d0
L_169d:
	CALL       SUB_0000_70f2
	CALL       SUB_0000_70f2
	CALL       SUB_0000_70f2
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7b66
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	DEC        AX
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_770e
	CMP        AX,0fch
	JZ         L_16c9
	JMP        L_175c
L_16c9:
	MOV        AL,DS:[58cbh]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX
	JZ         L_16d6
	JMP        L_175c
L_16d6:
	PUSH       word ptr DS:[5876h]
	CALL       SUB_0000_bb9e
	PUSH       AX
	CALL       SUB_0000_bb92
	MOV        word ptr [BP + -2h],7h
	MOV        SI,7h
L_16e9:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_75a2
	DEC        SI
	JZ         L_1708
	JMP        L_16e9
L_16fc:
	MOV        AX,482ah
	JMP        L_1699
	db 90h
L_1702:
	MOV        AX,4831h
	JMP        L_1699
	db 90h
L_1708:
	MOV        BX,word ptr [BP + 4h]
	MOV        byte ptr [BX + 58c8h],0ffh
	MOV        byte ptr [BX + 57b6h],0h
	MOV        AL,byte ptr [BX + 4892h]
	SUB        AH,AH
	SUB        DX,DX
	OR         word ptr DS:[5bcah],AX
	MOV        AX,483bh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_173c
	CMP        AX,1h
	JZ         L_1746
	CMP        AX,2h
	JZ         L_174c
	JMP        L_1752
	db 90h
L_173c:
	MOV        AX,4858h
L_173f:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1752
	db 90h
L_1746:
	MOV        AX,4861h
	JMP        L_173f
	db 90h
L_174c:
	MOV        AX,486ah
	JMP        L_173f
	db 90h
L_1752:
	MOV        AX,4874h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_83e8
L_175c:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_15b4 ENDP
F_1764 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,DS:[587ah]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX
	JNZ        L_178a
	MOV        AX,4895h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AL,AL
	MOV        DS:[588eh],AL
	MOV        DS:[587ah],AL
	MOV        byte ptr DS:[0a9fah],1h
	SUB        AX,AX
	JMP        L_178d
	db 90h
L_178a:
	MOV        AX,1h
L_178d:
	POP        BP
	RET        2h
	db 90h
	; Func
F_1764 ENDP
F_1792 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ah],1h
	CALL       SUB_0000_c1e6
	MOV        AX,0ffffh
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,0b9eeh
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_c012
	MOV        word ptr [BP + -4h],AX
	CMP        AX,0ffffh
	JNZ        L_17c8
	MOV        AX,489fh
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1baa
	db 90h
L_17c8:
	MOV        AX,48b1h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_8f7c
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5c14
	MOV        AX,48b8h
	PUSH       AX
	CALL       SUB_0000_8ed0
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_c1da
	PUSH       word ptr [BP + -4h]
	MOV        AX,0ffh
	PUSH       AX
	MOV        AX,55h
	PUSH       AX
	CALL       SUB_0000_c1f2
	MOV        word ptr [BP + -12h],AX
	CALL       SUB_0000_8e2a
	CALL       SUB_0000_8ea0
	CALL       SUB_0000_8fbc
	CALL       SUB_0000_6980
	CMP        word ptr [BP + -12h],0h
	JGE        L_180d
	JMP        L_1baa
L_180d:
	CMP        word ptr [BP + -12h],8h
	JGE        L_1820
	PUSH       word ptr [BP + -12h]
	CALL       F_11de
L_1819:
	MOV        word ptr [BP + -0ah],AX
	JMP        L_1b8a
	db 90h
L_1820:
	CMP        word ptr [BP + -12h],10h
	JGE        L_1832
	MOV        AX,word ptr [BP + -12h]
	SUB        AX,8h
	PUSH       AX
	CALL       F_135a
	JMP        L_1819
L_1832:
	CMP        word ptr [BP + -12h],14h
	JLE        L_184c
	CMP        word ptr [BP + -12h],1dh
	JGE        L_184c
	MOV        AX,word ptr [BP + -12h]
	SUB        AX,15h
	PUSH       AX
	CALL       F_153c
	JMP        L_1b8a
	db 90h
L_184c:
	MOV        AX,word ptr [BP + -12h]
	SUB        AX,10h
	CMP        AX,15h
	JBE        L_185a
	JMP        L_1b8a
L_185a:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0dadeh]
	db 0B8h
	db 0BFh
	db         48h    H
	db         50h    P
	db 0E8h
	db         67h    g
	db         40h    @
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         73h    s
	db         4Eh    N
	db 0A0h
	db 96h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0A0h
	db 97h
	db         58h    X
	db         50h    P
	db 0E8h
	db 05h
	db         6Ch    l
	db 8Bh
	db 0D8h
	db 80h
	db         3Fh    ?
	db 0Ch
	db         74h    t
	db         3Ah    :
	db 80h
	db         3Eh    >
	db         7Ch    |
	db         58h    X
	db 1Ch
	db         75h    u
	db 1Dh
	db 0B8h
	db 0C8h
	db         48h    H
	db         50h    P
	db 0E8h
	db         3Eh    >
	db         40h    @
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         76h    v
	db         48h    H
	db 04h
	db 14h
	db 0A2h
	db         7Ch    |
	db         58h    X
	db 0FEh
	db 0Eh
	db 0B0h
	db         57h    W
	db 0E9h
	db 0E2h
	db 02h
	db 0A0h
	db         7Ch    |
	db         58h    X
	db         24h    $
	db 0F8h
	db         3Ch    <
	db 20h
	db         75h    u
	db 07h
	db 0B8h
	db 0D2h
	db         48h    H
	db 0E9h
	db         6Dh    m
	db 01h
	db 90h
	db 0B8h
	db 0E4h
	db         48h    H
	db 0E9h
	db         66h    f
	db 01h
	db 0B8h
	db 0F3h
	db         48h    H
	db 0E9h
	db         60h    `
	db 01h
	db 0FEh
	db 0Eh
	db 0B1h
	db         57h    W
	db 0B8h
	db 0FEh
	db         48h    H
	db         50h    P
	db 0E8h
	db 01h
	db         40h    @
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         72h    r
	db 07h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         7Fh    
	db         76h    v
	db         25h    %
	db 0E8h
	db 8Eh
	db 0A8h
	db 89h
	db         46h    F
	db 0F6h
	db 0Bh
	db 0C0h
	db         75h    u
	db 03h
	db 0E9h
	db 0A0h
	db 02h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db 80h
	db         72h    r
	db 03h
	db 0E9h
	db 96h
	db 02h
	db 0FFh
	db         36h    6
	db         76h    v
	db         58h    X
	db 0FFh
	db         36h    6
	db         78h    x
	db         58h    X
	db 0E8h
	db 0A3h
	db         5Ch    \
	db 0E9h
	db 88h
	db 02h
	db 0B8h
	db 09h
	db         49h    I
	db 0E9h
	db 1Ch
	db 01h
	db 0B8h
	db 14h
	db         49h    I
	db         50h    P
	db 0E8h
	db 0C1h
	db         3Fh    ?
	db 0B8h
	db 0Eh
	db 00h
	db         50h    P
	db 0E8h
	db         4Eh    N
	db 0FEh
	db 0Bh
	db 0C0h
	db         75h    u
	db 03h
	db 0E9h
	db         6Dh    m
	db 02h
	db 0B8h
	db 1Dh
	db         49h    I
	db         50h    P
	db 0E8h
	db 0ACh
	db         3Fh    ?
	db 0B8h
	db 84h
	db         4Ah    J
	db         50h    P
	db 0E8h
	db 0A5h
	db         3Fh    ?
	db 0B8h
	db 0Eh
	db 00h
	db         50h    P
	db 0B8h
	db 0FFh
	db 00h
	db         50h    P
	db 0B8h
	db 09h
	db 00h
	db         50h    P
	db 0E8h
	db 0F8h
	db 0A7h
	db 0E9h
	db         4Dh    M
	db 02h
	db 90h
	db 0B8h
	db         30h    0
	db         49h    I
	db         50h    P
	db 0E8h
	db 8Bh
	db         3Fh    ?
	db 0B8h
	db 1Ch
	db 00h
	db         50h    P
	db 0E8h
	db 18h
	db 0FEh
	db 0Bh
	db 0C0h
	db         75h    u
	db 03h
	db 0E9h
	db         37h    7
	db 02h
	db 0B8h
	db         38h    8
	db         49h    I
	db         50h    P
	db 0E8h
	db         76h    v
	db         3Fh    ?
	db 0B8h
	db 84h
	db         4Ah    J
	db         50h    P
	db 0E8h
	db         6Fh    o
	db         3Fh    ?
	db 0B8h
	db 1Ch
	db 00h
	db 0EBh
	db 0C8h
	db 0B8h
	db         50h    P
	db         49h    I
	db         50h    P
	db 0E8h
	db         63h    c
	db         3Fh    ?
	db 0B8h
	db         5Ah    Z
	db         49h    I
	db         50h    P
	db 0E8h
	db         5Ch    \
	db         3Fh    ?
	db 0B8h
	db 84h
	db         4Ah    J
	db         50h    P
	db 0E8h
	db         55h    U
	db         3Fh    ?
	db 0B8h
	db         50h    P
	db 14h
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db         50h    P
	db 0C3h
	db         50h    P
	db 0B8h
	db 88h
	db 13h
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db 80h
	db         48h    H
	db 0C7h
	db         46h    F
	db 0FEh
	db 00h
	db 00h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         72h    r
	db 07h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         28h    (
	db         76h    v
	db         56h    V
	db 0C7h
	db         46h    F
	db 0F4h
	db 0FFh
	db 0FFh
	db 0BEh
	db 0FFh
	db 0FFh
	db 8Bh
	db         46h    F
	db 0F4h
	db 8Ah
	db 0Eh
	db 96h
	db         58h    X
	db         2Ah    *
	db 0EDh
	db 03h
	db 0C1h
	db         50h    P
	db 0A0h
	db 97h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db 03h
	db 0C6h
	db         50h    P
	db 0E8h
	db 0BEh
	db         6Ah    j
	db 8Bh
	db 0F8h
	db 8Ah
	db 05h
	db         24h    $
	db 0F0h
	db         3Ch    <
	db         70h    p
	db         75h    u
	db 18h
	db 0C6h
	db 05h
	db 05h
	db 0E8h
	db 0BCh
	db         7Fh    
	db 0B8h
	db 0Ah
	db 00h
	db         50h    P
	db 0B8h
	db 0B8h
	db 0Bh
	db         50h    P
	db 0B8h
	db 0D0h
	db 07h
	db         50h    P
	db 0E8h
	db 0D9h
	db         48h    H
	db 0FFh
	db         46h    F
	db 0FEh
	db         46h    F
	db 83h
	db 0FEh
	db 01h
	db         7Eh    ~
	db 0C1h
	db 89h
	db         7Eh    ~
	db 0FAh
	db 89h
	db         76h    v
	db 0F0h
	db 0FFh
	db         46h    F
	db 0F4h
	db 83h
	db         7Eh    ~
	db 0F4h
	db 01h
	db         7Eh    ~
	db 0AFh
	db 83h
	db         7Eh    ~
	db 0FEh
	db 00h
	db         74h    t
	db 03h
	db 0E9h
	db 86h
	db 01h
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db 1Ch
	db 0A7h
	db 89h
	db         46h    F
	db 0F8h
	db 3Dh
	db 01h
	db 00h
	db         75h    u
	db 06h
	db 0B8h
	db         6Fh    o
	db         49h    I
	db 0EBh
	db 0Dh
	db 90h
	db 83h
	db         7Eh    ~
	db 0F8h
	db 00h
	db         74h    t
	db 03h
	db 0E9h
	db         69h    i
	db 01h
	db 0B8h
	db 81h
	db         49h    I
	db         50h    P
	db 0E8h
	db 0A8h
	db         3Eh    >
	db 0E9h
	db         5Fh    _
	db 01h
	db 90h
	db 8Bh
	db         46h    F
	db 0EEh
	db         2Dh    -
	db 1Dh
	db 00h
	db         50h    P
	db 0E8h
	db         7Eh    ~
	db 0FBh
	db 0E9h
	db         51h    Q
	db 01h
	db 90h
	db 0B8h
	db 8Dh
	db         49h    I
	db         50h    P
	db 0E8h
	db 8Fh
	db         3Eh    >
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         21h    !
	db         73h    s
	db         28h    (
	db 80h
	db         3Eh    >
	db 95h
	db         58h    X
	db 80h
	db         73h    s
	db         21h    !
	db 80h
	db         3Eh    >
	db         7Fh    
	db         58h    X
	db 06h
	db         72h    r
	db 07h
	db 80h
	db         3Eh    >
	db         7Fh    
	db         58h    X
	db 12h
	db         76h    v
	db 0Dh
	db 0B8h
	db 98h
	db         49h    I
	db         50h    P
	db 0E8h
	db         6Ch    l
	db         3Eh    >
	db 0E8h
	db         33h    3
	db 0A5h
	db 0E9h
	db 20h
	db 01h
	db 0B8h
	db 0A4h
	db         49h    I
	db 0EBh
	db 0B5h
	db 90h
	db 0B8h
	db 0AFh
	db         49h    I
	db 0EBh
	db 0AFh
	db 90h
	db 0B8h
	db 0BAh
	db         49h    I
	db         50h    P
	db 0E8h
	db         53h    S
	db         3Eh    >
	db 0A0h
	db         7Ch    |
	db         58h    X
	db         24h    $
	db 0F8h
	db         3Ch    <
	db 20h
	db         75h    u
	db 0Ah
	db 80h
	db 0Eh
	db 0BBh
	db         57h    W
	db 80h
	db 0B8h
	db 0C2h
	db         49h    I
	db 0EBh
	db 94h
	db 0B8h
	db 0E1h
	db         49h    I
	db 0EBh
	db 8Fh
	db 90h
	db 0B8h
	db 0FCh
	db         49h    I
	db         50h    P
	db 0E8h
	db         33h    3
	db         3Eh    >
	db 80h
	db         3Eh    >
	db 95h
	db         58h    X
	db         7Fh    
	db         77h    w
	db 07h
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db 00h
	db         74h    t
	db 07h
	db 0B8h
	db 06h
	db         4Ah    J
	db 0E9h
	db         73h    s
	db 0FFh
	db 90h
	db 80h
	db         3Eh    >
	db         7Fh    
	db         58h    X
	db 05h
	db         76h    v
	db 0Dh
	db 80h
	db         3Eh    >
	db         7Fh    
	db         58h    X
	db 13h
	db         73h    s
	db 06h
	db 0B8h
	db 16h
	db         4Ah    J
	db 0E9h
	db         5Eh    ^
	db 0FFh
	db 0B8h
	db         26h    &
	db         4Ah    J
	db         50h    P
	db 0E8h
	db 03h
	db         3Eh    >
	db 0E8h
	db         6Eh    n
	db 0A6h
	db 0E9h
	db 0B7h
	db 00h
	db 90h
	db 0B8h
	db         30h    0
	db         4Ah    J
	db         50h    P
	db 0E8h
	db 0F5h
	db 3Dh
	db 0A0h
	db         7Fh    
	db         58h    X
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 0Ch
	db 0F6h
	db 0F1h
	db 8Ah
	db 0C4h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0F2h
	db 0Bh
	db 0C0h
	db         75h    u
	db 05h
	db 0C7h
	db         46h    F
	db 0F2h
	db 0Ch
	db 00h
	db 0FFh
	db         76h    v
	db 0F2h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 20h
	db 00h
	db         50h    P
	db 0E8h
	db 0BCh
	db         3Fh    ?
	db 0B8h
	db         3Ah    :
	db 00h
	db         50h    P
	db 0E8h
	db         31h    1
	db         3Ch    <
	db 0A0h
	db 81h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0B8h
	db 02h
	db 00h
	db         50h    P
	db 0B8h
	db         30h    0
	db 00h
	db         50h    P
	db 0E8h
	db 0A4h
	db         3Fh    ?
	db 80h
	db         3Eh    >
	db         7Fh    
	db         58h    X
	db 0Bh
	db         76h    v
	db 07h
	db 0B8h
	db         4Fh    O
	db         4Ah    J
	db 0E9h
	db 0FDh
	db 0FEh
	db 90h
	db 0B8h
	db         55h    U
	db         4Ah    J
	db 0E9h
	db 0F6h
	db 0FEh
	db 0B8h
	db         5Bh    [
	db         4Ah    J
	db         50h    P
	db 0E8h
	db 9Bh
	db 3Dh
	db 0B8h
	db 1Dh
	db 00h
	db         50h    P
	db 0E8h
	db         28h    (
	db 0FCh
	db 0Bh
	db 0C0h
	db         74h    t
	db         4Ah    J
	db 0B8h
	db         63h    c
	db         4Ah    J
	db         50h    P
	db 0E8h
	db 89h
	db 3Dh
	db 0C6h
	db 06h
	db         7Ah    z
	db         58h    X
	db 1Dh
	db 0C6h
	db 06h
	db 8Eh
	db         58h    X
	db 0FFh
	db 0C6h
	db 06h
	db 0FAh
	db 0A9h
	db 01h
	db 0EBh
	db         32h    2
	db 0B8h
	db         70h    p
	db         4Ah    J
	db 0E9h
	db 0C6h
	db 0FEh
	db 0E2h
	db 0D7h
	db         44h    D
	db 0D8h
	db 88h
	db 0D8h
	db 0BEh
	db 0D8h
	db 0E6h
	db 0D8h
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0Ah
	db 0DBh
	db 0ACh
	db 0D9h
	db 0ACh
	db 0D9h
	db 0ACh
	db 0D9h
	db 0BAh
	db 0D9h
	db 0F6h
	db 0D9h
	db 16h
	db 0DAh
	db         54h    T
	db 0DAh
	db 0AEh
	db 0DAh
	db 0D8h
	db 0DAh
L_1b8a:
	CMP        word ptr [BP + -0ah],0h
	JNZ        L_1baa
	MOV        AX,4a7bh
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
L_1baa:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1792 ENDP
F_1bb0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 8h],8h
	JL         L_1bcd
	CMP        word ptr [BP + 8h],0b6h
	JG         L_1bcd
	CMP        word ptr [BP + 6h],8h
	JL         L_1bcd
	CMP        word ptr [BP + 6h],0b6h
	JLE        L_1bda
L_1bcd:
	MOV        AX,0ffffh
	MOV        DS:[5878h],AX
	MOV        DS:[5876h],AX
L_1bd6:
	SUB        AX,AX
	JMP        L_1c31
L_1bda:
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_4af0
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_4ce4
	MOV        AX,word ptr [BP + 8h]
	INC        AX
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_4ce4
	MOV        AX,64h
	PUSH       AX
	MOV        AX,2710h
	PUSH       AX
	CALL       SUB_0000_6112
	PUSH       AX
	CALL       SUB_0000_6362
	TEST       byte ptr [BP + 6h],1h
	JZ         L_1c2e
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_8034
	CMP        word ptr DS:[5876h],0h
	JL         L_1bd6
	CMP        word ptr DS:[5878h],0h
	JL         L_1bd6
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_7fee
	JMP        L_1c31
	db 90h
L_1c2e:
	MOV        AX,1h
L_1c31:
	POP        BP
	RET        6h
	db 90h
	; Func
F_1bb0 ENDP
F_1c36 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0beh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8eh],0h
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba1ah]
	SUB        AH,AH
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,8h
	MOV        word ptr [BP + -5eh],AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	SUB        AH,AH
	SHL        AX,CL
	ADD        AX,8h
	MOV        word ptr [BP + -60h],AX
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,1h
	JZ         L_1cde
	CMP        AX,2h
	JZ         L_1cda
	CMP        AX,3h
	JZ         L_1c84
	CMP        AX,4h
	JZ         L_1ce4
	JMP        L_1c88
	db 90h
L_1c84:
	ADD        word ptr [BP + -5eh],8h
L_1c88:
	ADD        word ptr [BP + 8h],8h
	MOV        word ptr [BP + -5ah],15h
	MOV        DI,BP
	SUB        DI,2eh
	MOV        SI,BP
	SUB        SI,58h
	SUB        AX,AX
	MOV        CX,15h
	PUSH       DI
	LEA        DI,[BP + -8ah]
	PUSH       SS
	POP        ES
	REP STOSW
	POP        DI
	MOV        CX,15h
	PUSH       SI
	PUSH       DI
	MOV        DI,0a9d0h
	MOV        SI,1cf0h
	PUSH       DS
	POP        ES
	REP MOVSW
	POP        DI
	POP        SI
	LEA        AX,[BP + -2eh]
	MOV        word ptr [BP + -9ah],AX
	MOV        CX,AX
L_1cc4:
	MOV        AX,word ptr [BP + -5eh]
	MOV        word ptr [DI],AX
	MOV        AX,word ptr [BP + -60h]
	MOV        word ptr [SI],AX
	ADD        DI,2h
	ADD        SI,2h
	CMP        SI,CX
	JNC        L_1cee
	JMP        L_1cc4
L_1cda:
	ADD        word ptr [BP + -5eh],10h
L_1cde:
	ADD        word ptr [BP + -60h],8h
	JMP        L_1c88
L_1ce4:
	ADD        word ptr [BP + -5eh],8h
	ADD        word ptr [BP + -60h],10h
	JMP        L_1c88
L_1cee:
	MOV        word ptr [BP + -2h],0h
	MOV        word ptr [BP + -8eh],0h
	MOV        word ptr [BP + -0beh],0h
L_1cff:
	MOV        word ptr [BP + -2h],0h
	MOV        word ptr [BP + -5ah],0h
	LEA        AX,[BP + -8ah]
	MOV        word ptr [BP + -0bah],AX
	MOV        word ptr [BP + -0b6h],0h
	MOV        AX,word ptr [BP + -0beh]
	MOV        word ptr [BP + -0b8h],AX
	LEA        AX,[BP + -8ah]
	MOV        word ptr [BP + -0bch],AX
L_1d27:
	MOV        BX,word ptr [BP + -0bah]
	CMP        word ptr [BX],0h
	JZ         L_1d33
	JMP        L_1f2a
L_1d33:
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_7b2e
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -5ch],0h
	OR         AX,AX
	JG         L_1d49
	JMP        L_1f2d
L_1d49:
	MOV        SI,word ptr [BP + -0b6h]
	LEA        AX,[BP + SI + 0ff76h]
	MOV        word ptr [BP + -9ah],AX
	MOV        AX,word ptr [BP + -0b6h]
	ADD        AX,1cf0h
	MOV        word ptr [BP + -98h],AX
	MOV        AX,word ptr [BP + -0b6h]
	ADD        AX,0a9d0h
	MOV        word ptr [BP + -96h],AX
	MOV        SI,word ptr [BP + -0b6h]
	LEA        AX,[BP + SI + -58h]
	MOV        word ptr [BP + -94h],AX
	MOV        word ptr [BP + -92h],AX
	MOV        SI,word ptr [BP + -0b6h]
	LEA        AX,[BP + SI + -2eh]
	MOV        word ptr [BP + -90h],AX
	MOV        word ptr [BP + -9ch],AX
	MOV        AX,word ptr [BP + -96h]
	MOV        word ptr [BP + -9eh],AX
	MOV        AX,word ptr [BP + -90h]
	MOV        word ptr [BP + -0a0h],AX
	MOV        word ptr [BP + -0a2h],AX
	MOV        AX,word ptr [BP + -94h]
	MOV        word ptr [BP + -0a4h],AX
	MOV        word ptr [BP + -0a6h],AX
	MOV        AX,word ptr [BP + -96h]
	MOV        word ptr [BP + -0a8h],AX
	MOV        AX,word ptr [BP + -9ah]
	MOV        word ptr [BP + -0aah],AX
	MOV        AX,word ptr [BP + -94h]
	MOV        word ptr [BP + -0ach],AX
	MOV        AX,word ptr [BP + -90h]
	MOV        word ptr [BP + -0aeh],AX
	MOV        AX,word ptr [BP + -0b8h]
	ADD        AX,word ptr [BP + 0ch]
	MOV        word ptr [BP + -0b0h],AX
	MOV        DI,word ptr [BP + -0b8h]
	ADD        DI,word ptr [BP + 0ah]
	MOV        AX,word ptr [BP + 0ah]
	ADD        AX,7eh
	MOV        word ptr [BP + -0b4h],AX
	MOV        SI,word ptr [BP + -8ch]
L_1de9:
	MOV        BX,word ptr [BP + -0aeh]
	PUSH       word ptr [BX]
	MOV        BX,word ptr [BP + -0ach]
	PUSH       word ptr [BX]
	PUSH       word ptr [BP + 8h]
	CALL       F_1bb0
	OR         AX,AX
	JZ         L_1e68
	CMP        word ptr [BP + -0b4h],DI
	JBE        L_1e70
	CMP        word ptr DS:[5876h],-1h
	JLE        L_1e70
	CMP        word ptr DS:[5878h],-1h
	JLE        L_1e70
	CMP        word ptr DS:[5876h],0bh
	JGE        L_1e70
	CMP        word ptr DS:[5878h],0bh
	JGE        L_1e70
	MOV        BX,word ptr DS:[5878h]
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr DS:[5876h]
	CMP        byte ptr [BX + 0ab02h],0h
	JNZ        L_1e70
	ADD        word ptr [BP + -0b0h],2h
	ADD        DI,2h
	ADD        word ptr [BP + -0b8h],2h
	ADD        word ptr [BP + -0beh],2h
	INC        word ptr [BP + -8eh]
	MOV        BX,word ptr [BP + -0b0h]
	MOV        AX,DS:[5876h]
	MOV        word ptr [BX],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [DI],AX
	MOV        BX,AX
	SHL        BX,CL
	ADD        BX,word ptr DS:[5876h]
	MOV        byte ptr [BX + 0ab02h],0ffh
	JMP        L_1e70
	db 90h
L_1e68:
	MOV        BX,word ptr [BP + -0bch]
	MOV        word ptr [BX],1h
L_1e70:
	MOV        BX,word ptr [BP + -0aah]
	CMP        word ptr [BX],0h
	JNZ        L_1ef6
	MOV        BX,word ptr [BP + -0a8h]
	SUB        word ptr [BX],0ah
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,1h
	JZ         L_1ec2
	CMP        AX,2h
	JZ         L_1ebc
	CMP        AX,3h
	JZ         L_1e9a
	CMP        AX,4h
	JZ         L_1eb4
	JMP        L_1ea0
	db 90h
L_1e9a:
	MOV        BX,word ptr [BP + -0a6h]
L_1e9e:
	DEC        word ptr [BX]
L_1ea0:
	MOV        BX,word ptr [BP + -9eh]
	CMP        word ptr [BX],1h
	JGE        L_1ef6
	CMP        word ptr [BP + -5ah],0ah
	JGE        L_1ec8
	MOV        SI,0ffffh
	JMP        L_1ecb
L_1eb4:
	MOV        BX,word ptr [BP + -0a4h]
L_1eb8:
	INC        word ptr [BX]
	JMP        L_1ea0
L_1ebc:
	MOV        BX,word ptr [BP + -0a2h]
	JMP        L_1eb8
L_1ec2:
	MOV        BX,word ptr [BP + -0a0h]
	JMP        L_1e9e
L_1ec8:
	MOV        SI,1h
L_1ecb:
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,1h
	JZ         L_1f10
	CMP        AX,2h
	JZ         L_1f0a
	CMP        AX,3h
	JZ         L_1ee4
	CMP        AX,4h
	JZ         L_1f02
	JMP        L_1eea
L_1ee4:
	MOV        BX,word ptr [BP + -9ch]
L_1ee8:
	ADD        word ptr [BX],SI
L_1eea:
	MOV        BX,word ptr [BP + -98h]
	MOV        AX,word ptr [BX]
	MOV        BX,word ptr [BP + -96h]
	ADD        word ptr [BX],AX
L_1ef6:
	MOV        BX,word ptr [BP + -9ah]
	CMP        word ptr [BX],0h
	JZ         L_1f16
	JMP        L_1f24
	db 90h
L_1f02:
	MOV        BX,word ptr [BP + -90h]
L_1f06:
	SUB        word ptr [BX],SI
	JMP        L_1eea
L_1f0a:
	MOV        BX,word ptr [BP + -92h]
	JMP        L_1ee8
L_1f10:
	MOV        BX,word ptr [BP + -94h]
	JMP        L_1f06
L_1f16:
	INC        word ptr [BP + -5ch]
	MOV        AX,word ptr [BP + -4h]
	CMP        word ptr [BP + -5ch],AX
	JGE        L_1f24
	JMP        L_1de9
L_1f24:
	MOV        word ptr [BP + -8ch],SI
	JMP        L_1f2d
L_1f2a:
	INC        word ptr [BP + -2h]
L_1f2d:
	ADD        word ptr [BP + -0bah],2h
	ADD        word ptr [BP + -0b6h],2h
	ADD        word ptr [BP + -0bch],2h
	INC        word ptr [BP + -5ah]
	CMP        word ptr [BP + -5ah],15h
	JGE        L_1f48
	JMP        L_1d27
L_1f48:
	CMP        word ptr [BP + -2h],15h
	JGE        L_1f51
	JMP        L_1cff
L_1f51:
	CALL       SUB_0000_638e
	MOV        AX,word ptr [BP + -8eh]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ah
	; Func
F_1c36 ENDP
F_1f60 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,11ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -10ah],1h
	MOV        BX,word ptr [BP + 8h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -102h],AX
	PUSH       word ptr [BP + 8h]
	CALL       SUB_0000_c162
	MOV        word ptr [BP + -10ch],AX
	MOV        AX,word ptr [BP + 6h]
	CMP        AX,1h
	JZ         L_1faa
	CMP        AX,2h
	JNZ        L_1fa1
	JMP        L_2088
L_1fa1:
	MOV        word ptr [BP + -108h],5140h
	JMP        L_1fb0
	db 90h
L_1faa:
	MOV        word ptr [BP + -108h],3e80h
L_1fb0:
	MOV        AX,320h
	PUSH       AX
	PUSH       word ptr [BP + -108h]
	MOV        AX,2bch
	PUSH       AX
	CALL       SUB_0000_62bc
	LEA        AX,[BP + -80h]
	PUSH       AX
	LEA        AX,[BP + -100h]
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + -10ch]
	CALL       F_1c36
	MOV        word ptr [BP + -10ch],AX
	INC        word ptr [BP + -10ch]
	MOV        word ptr [BP + -10ah],1h
	CMP        word ptr [BP + -10ch],1h
	JG         L_1fed
	JMP        L_2148
L_1fed:
	LEA        AX,[BP + 0h]
	MOV        word ptr [BP + -114h],AX
	MOV        AX,word ptr [BP + -10ch]
	SHL        AX,1h
	ADD        AX,BP
	MOV        word ptr [BP + -116h],AX
	MOV        AX,word ptr [BP + -10ch]
	DEC        AX
	MOV        word ptr [BP + -118h],AX
	ADD        word ptr [BP + -10ah],AX
L_200d:
	MOV        SI,1fh
	MOV        BX,word ptr [BP + -114h]
	MOV        AX,word ptr [BX + 0ff00h]
	MOV        word ptr [BP + -10eh],AX
	MOV        AX,word ptr [BX + -80h]
	MOV        word ptr [BP + -110h],AX
	MOV        word ptr [BP + -112h],0bb0ch
	MOV        DI,word ptr [BP + 8h]
L_202c:
	MOV        AX,word ptr [BP + -112h]
	MOV        word ptr [BP + -104h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -110h]
	JZ         L_2044
	JMP        L_2124
L_2044:
	MOV        AL,byte ptr [BX + 7h]
	CMP        AX,word ptr [BP + -10eh]
	JZ         L_2050
	JMP        L_2124
L_2050:
	TEST       byte ptr [BX + 5h],80h
	JZ         L_2059
	JMP        L_2124
L_2059:
	TEST       byte ptr [BX + 2h],20h
	JZ         L_2062
	JMP        L_2124
L_2062:
	CMP        byte ptr [BX + 2h],AH
	JNZ        L_206a
	JMP        L_2124
L_206a:
	OR         byte ptr [BX + 5h],80h
	MOV        AX,word ptr [BP + 6h]
	CMP        AX,1h
	JZ         L_2092
	CMP        AX,2h
	JZ         L_20bc
	CMP        AX,3h
	JZ         L_20dc
	CMP        AX,4h
	JZ         L_20fe
	JMP        L_2132
L_2088:
	MOV        word ptr [BP + -108h],4b00h
	JMP        L_1fb0
	db 90h
L_2092:
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_c19e
	OR         AX,AX
	JZ         L_20a1
	JMP        L_2132
L_20a1:
	PUSH       SI
	CALL       F_0000
	OR         AX,AX
	JZ         L_20ac
	JMP        L_2132
L_20ac:
	PUSH       SI
	CALL       SUB_0000_75e4
	PUSH       SI
	CALL       SUB_0000_a92e
L_20b4:
	PUSH       SI
	PUSH       DI
	CALL       SUB_0000_be32
	JMP        L_2132
	db 90h
L_20bc:
	PUSH       SI
	MOV        AX,0fffeh
	PUSH       AX
	CALL       SUB_0000_bf46
	MOV        word ptr [BP + -11ah],AX
	CALL       SUB_0000_7b3e
	CMP        AX,word ptr [BP + -11ah]
	JL         L_2132
	PUSH       SI
	CALL       SUB_0000_75e4
	PUSH       SI
	PUSH       DI
	CALL       SUB_0000_bf6a
	JMP        L_20b4
L_20dc:
	PUSH       SI
	CALL       SUB_0000_75e4
	MOV        AX,word ptr [BP + -102h]
	ADD        AX,14h
	PUSH       AX
	PUSH       SI
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_7b2e
L_20f0:
	PUSH       AX
	CALL       SUB_0000_bdae
	PUSH       AX
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_7f94
	JMP        L_20b4
L_20fe:
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_c19e
	OR         AX,AX
	JNZ        L_2132
	PUSH       SI
	CALL       F_0000
	OR         AX,AX
	JNZ        L_2132
	PUSH       SI
	CALL       SUB_0000_75e4
	MOV        AX,word ptr [BP + -102h]
	ADD        AX,14h
	PUSH       AX
	PUSH       SI
	MOV        AX,63h
	JMP        L_20f0
L_2124:
	SUB        word ptr [BP + -112h],8h
	DEC        SI
	CMP        SI,-1h
	JLE        L_2132
	JMP        L_202c
L_2132:
	MOV        word ptr [BP + -106h],SI
	ADD        word ptr [BP + -114h],2h
	MOV        AX,word ptr [BP + -116h]
	CMP        word ptr [BP + -114h],AX
	JZ         L_2148
	JMP        L_200d
L_2148:
	MOV        word ptr [BP + -106h],0ffffh
	MOV        SI,0bb11h
L_2151:
	AND        byte ptr [SI],7fh
	SUB        SI,8h
	CMP        SI,0ba11h
	JA         L_2151
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
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
F_1f60 ENDP
_TEXT ENDS
END
