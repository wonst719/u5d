_TEXT SEGMENT BYTE 'CODE'
ORG 405ch
SUB_0000_405c:
ORG 2890h
SUB_0000_2890:
ORG 29a6h
SUB_0000_29a6:
ORG 3fb2h
SUB_0000_3fb2:
ORG 3670h
SUB_0000_3670:
ORG 4caeh
SUB_0000_4cae:
ORG 3d32h
SUB_0000_3d32:
ORG 34dah
SUB_0000_34da:
ORG 448ch
SUB_0000_448c:
ORG 3e52h
SUB_0000_3e52:
ORG 3f8ch
SUB_0000_3f8c:
ORG 3b0eh
SUB_0000_3b0e:
ORG 3a12h
SUB_0000_3a12:
ORG 58deh
SUB_0000_58de:
ORG 5d34h
SUB_0000_5d34:
ORG 4cb6h
SUB_0000_4cb6:
ORG 7b2ah
SUB_0000_7b2a:
ORG 6372h
SUB_0000_6372:
ORG 71b4h
SUB_0000_71b4:
ORG 74cch
SUB_0000_74cc:
ORG 3f1ah
SUB_0000_3f1a:
ORG 7730h
SUB_0000_7730:
ORG 9cb6h
SUB_0000_9cb6:
ORG 9b96h
SUB_0000_9b96:
ORG 6222h
SUB_0000_6222:
ORG 8326h
SUB_0000_8326:
ORG 2e88h
SUB_0000_2e88:
ORG 9ce6h
SUB_0000_9ce6:
ORG 2262h
SUB_0000_2262:
ORG 22b6h
SUB_0000_22b6:
ORG 5894h
SUB_0000_5894:
ORG 4720h
SUB_0000_4720:
ORG 5906h
SUB_0000_5906:
ORG 593ch
SUB_0000_593c:
ORG 8d3eh
SUB_0000_8d3e:
ORG 3abeh
SUB_0000_3abe:
ORG 4e92h
SUB_0000_4e92:
ORG 615eh
SUB_0000_615e:
ORG 438eh
SUB_0000_438e:
ORG 6d9ch
SUB_0000_6d9c:
ORG 7c6ah
SUB_0000_7c6a:
ORG 433eh
SUB_0000_433e:
ORG 43f8h
SUB_0000_43f8:
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
	PUSH       DI
	PUSH       SI
	CMP        word ptr [BP + 4h],9h
	JGE        L_0080
	MOV        AX,320h
	PUSH       AX
	MOV        AX,640h
	IMUL       word ptr [BP + 4h]
	ADD        AX,1f40h
	PUSH       AX
	MOV        AX,2bch
	PUSH       AX
	CALL       SUB_0000_405c
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	MOV        SI,word ptr [BP + 4h]
	SHL        SI,1h
	MOV        AX,0fa0h
	IMUL       word ptr [BP + 4h]
	MOV        DI,AX
	ADD        DI,2710h
	PUSH       word ptr [SI + 4af6h]
	MOV        AX,1h
	PUSH       AX
	PUSH       DI
	PUSH       word ptr [SI + 4b08h]
	PUSH       word ptr [SI + 4b2ch]
	CALL       SUB_0000_3fb2
	PUSH       word ptr [SI + 4af6h]
	MOV        AX,1h
	PUSH       AX
	PUSH       DI
	PUSH       word ptr [SI + 4b1ah]
	MOV        AX,word ptr [SI + 4b2ch]
	NEG        AX
	PUSH       AX
	CALL       SUB_0000_3fb2
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	JMP        L_0097
	db 90h
L_0080:
	MOV        AX,1180h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0fde8h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3fb2
L_0097:
	POP        SI
	POP        DI
	POP        BP
	RET        2h
	db 90h
	; Func
F_0000 ENDP
F_009e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,94f4h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_4cae
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JGE        L_00ba
	MOV        AX,94feh
	JMP        L_00c4
L_00ba:
	MOV        AX,word ptr [BP + -2h]
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
L_00c4:
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_3d32
	OR         AX,AX
	JZ         L_00d6
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
L_00d6:
	MOV        AX,word ptr [BP + -2h]
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_009e ENDP
F_00de PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,26h
	PUSH       DI
	PUSH       SI
	SUB        DI,DI
	MOV        word ptr [BP + -2h],0ffffh
	MOV        word ptr [BP + -0ah],DI
L_00f0:
	CALL       SUB_0000_448c
	PUSH       AX
	CALL       SUB_0000_3e52
	MOV        byte ptr [BP + -14h],AL
	CMP        AL,4ah
	JNZ        L_0101
	JMP        L_01cf
L_0101:
	CMP        AL,4fh
	JNZ        L_0108
	JMP        L_01cf
L_0108:
	CMP        AL,41h
	JC         L_0158
	CMP        AL,5ah
	JA         L_0158
	CMP        DI,4h
	JGE        L_0158
	MOV        byte ptr [BP + DI + -0eh],AL
	MOV        BL,byte ptr [BP + -14h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1b7ah]
	CALL       SUB_0000_3f8c
	MOV        SI,AX
	CALL       SUB_0000_3d32
	ADD        AX,SI
	CMP        AX,0dh
	JLE        L_0139
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
L_0139:
	CALL       SUB_0000_3d32
	MOV        byte ptr [BP + DI + -6h],AL
	MOV        BL,byte ptr [BP + -14h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1b7ah]
	CALL       SUB_0000_3670
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	INC        DI
	JMP        L_01cf
	db 90h
L_0158:
	MOV        AL,byte ptr [BP + -14h]
	SUB        AH,AH
	CMP        AX,8h
	JZ         L_0174
	CMP        AX,0dh
	JZ         L_01da
	CMP        AX,1bh
	JZ         L_01d8
	CMP        AX,20h
	JZ         L_01da
	JMP        L_01cf
	db 90h
L_0174:
	OR         DI,DI
	JZ         L_01cf
	DEC        DI
	CALL       SUB_0000_3d32
	OR         AX,AX
	JNZ        L_018c
	MOV        AL,byte ptr [BP + DI + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3b0e
	DEC        AX
	JMP        L_0195
L_018c:
	MOV        AL,byte ptr [BP + DI + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3b0e
L_0195:
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        BL,byte ptr [BP + DI + -0eh]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1b7ah]
	CALL       SUB_0000_3f8c
	MOV        word ptr [BP + -1ah],AX
	MOV        word ptr [BP + -10h],0h
	OR         AX,AX
	JLE        L_01c2
	MOV        SI,AX
	ADD        word ptr [BP + -10h],SI
L_01b8:
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	DEC        SI
	JNZ        L_01b8
L_01c2:
	MOV        AL,byte ptr [BP + DI + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3b0e
	PUSH       AX
	CALL       SUB_0000_3a12
L_01cf:
	CMP        word ptr [BP + -0ah],0h
	JNZ        L_01e2
	JMP        L_00f0
L_01d8:
	SUB        DI,DI
L_01da:
	MOV        word ptr [BP + -0ah],1h
	JMP        L_01cf
	db 90h
L_01e2:
	MOV        word ptr [BP + -8h],DI
	DEC        DI
L_01e6:
	MOV        SI,1h
	SUB        CX,CX
	CMP        word ptr [BP + -8h],SI
	JLE        L_022b
	MOV        DX,DI
L_01f2:
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0dh]
	MOV        BX,CX
	ADD        BX,BP
	CMP        byte ptr [BX + -0ch],AL
	JNC        L_0226
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0eh]
	MOV        byte ptr [BP + -14h],AL
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0dh]
	MOV        BX,CX
	ADD        BX,BP
	MOV        byte ptr [BX + -0eh],AL
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BP + -14h]
	MOV        byte ptr [BX + -0dh],AL
	SUB        SI,SI
L_0226:
	INC        CX
	CMP        CX,DX
	JNZ        L_01f2
L_022b:
	OR         SI,SI
	JZ         L_01e6
	MOV        word ptr [BP + -0ah],SI
	MOV        word ptr [BP + -10h],CX
	MOV        word ptr [BP + -10h],0h
	MOV        AX,word ptr [BP + -8h]
	DEC        AX
	MOV        word ptr [BP + -22h],AX
	MOV        word ptr [BP + -24h],1c30h
	MOV        word ptr [BP + -26h],1c30h
	MOV        SI,word ptr [BP + -16h]
L_024e:
	MOV        word ptr [BP + -18h],1h
	SUB        SI,SI
	MOV        word ptr [BP + -12h],SI
	CMP        word ptr [BP + -8h],SI
	JLE        L_0280
	MOV        DI,word ptr [BP + -22h]
	MOV        BX,word ptr [BP + -24h]
	MOV        AX,word ptr [BX]
	MOV        word ptr [BP + -20h],AX
	MOV        CX,SI
L_026a:
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0eh]
	MOV        BX,word ptr [BP + -20h]
	CMP        byte ptr [BX + SI],AL
	JZ         L_02b2
	MOV        word ptr [BP + -18h],0h
L_027d:
	MOV        word ptr [BP + -12h],CX
L_0280:
	CMP        word ptr [BP + -18h],0h
	JZ         L_0295
	MOV        BX,word ptr [BP + -26h]
	MOV        BX,word ptr [BX]
	CMP        byte ptr [BX + SI],0h
	JZ         L_0295
	MOV        word ptr [BP + -18h],0h
L_0295:
	CMP        word ptr [BP + -18h],0h
	JZ         L_02d6
	MOV        AX,word ptr [BP + -10h]
	MOV        word ptr [BP + -2h],AX
L_02a1:
	MOV        word ptr [BP + -16h],SI
	CMP        word ptr [BP + -8h],0h
	JNZ        L_02ea
	MOV        word ptr [BP + -2h],0ffffh
	JMP        L_02fc
	db 90h
L_02b2:
	CMP        DI,CX
	JLE        L_02cd
	MOV        DX,DI
L_02b8:
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0eh]
	MOV        BX,CX
	ADD        BX,BP
	CMP        byte ptr [BX + -0dh],AL
	JNZ        L_02cd
	INC        CX
	CMP        CX,DX
	JL         L_02b8
L_02cd:
	INC        CX
	INC        SI
	CMP        word ptr [BP + -8h],CX
	JLE        L_027d
	JMP        L_026a
L_02d6:
	ADD        word ptr [BP + -24h],2h
	ADD        word ptr [BP + -26h],2h
	INC        word ptr [BP + -10h]
	CMP        word ptr [BP + -10h],30h
	JGE        L_02a1
	JMP        L_024e
L_02ea:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	CMP        word ptr [BP + -2h],0h
	JGE        L_02fc
	MOV        word ptr [BP + -2h],0fffeh
L_02fc:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_00de ENDP
F_0306 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_032e
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba1ah]
	MOV        DS:[5876h],AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	JMP        L_0339
	db 90h
L_032e:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        DS:[5876h],AX
	MOV        AL,DS:[5897h]
L_0339:
	SUB        AH,AH
	MOV        DS:[5878h],AX
	MOV        AX,9504h
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        SI,SI
L_0347:
	CALL       SUB_0000_448c
	MOV        DI,AX
	MOV        SI,1h
	CMP        AX,SI
	JZ         L_039a
	CMP        AX,2h
	JZ         L_037e
	CMP        AX,3h
	JZ         L_036c
	CMP        AX,4h
	JZ         L_038c
	CMP        AX,20h
	JZ         L_03a8
	SUB        SI,SI
	JMP        L_0377
	db 90h
L_036c:
	MOV        AX,9510h
	PUSH       AX
	CALL       SUB_0000_3670
	DEC        word ptr DS:[5878h]
L_0377:
	OR         SI,SI
	JNZ        L_03b4
	JMP        L_0347
	db 90h
L_037e:
	MOV        AX,9518h
	PUSH       AX
	CALL       SUB_0000_3670
	INC        word ptr DS:[5876h]
	JMP        L_0377
	db 90h
L_038c:
	MOV        AX,951eh
	PUSH       AX
	CALL       SUB_0000_3670
	INC        word ptr DS:[5878h]
	JMP        L_0377
	db 90h
L_039a:
	MOV        AX,9526h
	PUSH       AX
	CALL       SUB_0000_3670
	DEC        word ptr DS:[5876h]
	JMP        L_0377
	db 90h
L_03a8:
	MOV        AX,952ch
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        DI,DI
	JMP        L_0377
	db 90h
L_03b4:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	MOV        AX,DI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0306 ENDP
F_03c2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JNZ        L_03de
	MOV        word ptr [BP + -2h],0h
	JMP        L_0400
L_03de:
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,55b8h
	PUSH       AX
	CALL       SUB_0000_58de
	PUSH       AX
	PUSH       word ptr [SI + 55bah]
	CALL       SUB_0000_5d34
	MOV        word ptr [BP + -2h],1h
	MOV        byte ptr DS:[0a9fah],1h
L_0400:
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_03c2 ENDP
F_040a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 6h],0h
	JNZ        L_0419
	CMP        word ptr [BP + 4h],0h
	JZ         L_0468
L_0419:
	CMP        word ptr [BP + 4h],0h
	JZ         L_0424
	MOV        AX,1h
	JMP        L_0427
L_0424:
	MOV        AX,2h
L_0427:
	PUSH       AX
	CALL       F_0000
	MOV        AX,word ptr [BP + 6h]
	OR         AX,AX
	JZ         L_0464
	CMP        AX,1h
	JZ         L_045e
	CMP        AX,2h
	JZ         L_0458
	CMP        AX,3h
	JZ         L_0448
	CMP        AX,4h
	JZ         L_0452
	JMP        L_0468
L_0448:
	MOV        AX,1h
L_044b:
	PUSH       AX
	CALL       SUB_0000_4cb6
	JMP        L_0468
	db 90h
L_0452:
	MOV        AX,2h
	JMP        L_044b
	db 90h
L_0458:
	MOV        AX,3h
	JMP        L_044b
	db 90h
L_045e:
	MOV        AX,4h
	JMP        L_044b
	db 90h
L_0464:
	SUB        AX,AX
	JMP        L_044b
L_0468:
	POP        BP
	RET        4h
	; Func
F_040a ENDP
F_046c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        AX,0ffffh
	PUSH       AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[589bh]
	SUB        CH,CH
	SUB        AX,CX
	PUSH       AX
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[589ch]
	SUB        AX,CX
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_7b2a
	MOV        word ptr [BP + -2h],14h
	MOV        SI,14h
L_04a0:
	CMP        byte ptr DS:[587ah],54h
	JZ         L_04aa
	CALL       SUB_0000_6372
L_04aa:
	CALL       SUB_0000_71b4
	CALL       SUB_0000_74cc
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3f1a
	DEC        SI
	JNZ        L_04a0
	CALL       SUB_0000_7730
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_046c ENDP
F_04c2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	CMP        word ptr [BP + 4h],0h
	JZ         L_04da
	MOV        AX,5h
	JMP        L_04dd
L_04da:
	MOV        AX,8h
L_04dd:
	PUSH       AX
	CALL       F_0000
	MOV        word ptr [BP + -6h],0h
	MOV        DI,word ptr [BP + -2h]
	MOV        SI,word ptr [BP + -4h]
L_04ec:
	CALL       SUB_0000_9cb6
	OR         AX,AX
	JZ         L_0518
	MOV        AX,0d8h
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_9b96
	OR         AX,AX
	JZ         L_0518
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_6222
	MOV        BX,AX
	CMP        byte ptr [BX],0ffh
	JNZ        L_0524
L_0518:
	INC        word ptr [BP + -6h]
	CMP        word ptr [BP + -6h],8h
	JGE        L_0542
	JMP        L_04ec
	db 90h
L_0524:
	MOV        AX,26h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_8326
	MOV        DI,AX
	OR         DI,DI
	JGE        L_054c
L_0542:
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -4h],SI
	JMP        L_05d4
	db 90h
L_054c:
	MOV        AX,0ac8h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,2ee0h
	PUSH       AX
	MOV        AX,1f4h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_3fb2
	MOV        BX,DI
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba18h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,CL
	ADD        SI,5c5ah
	MOV        AL,16h
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [SI],AL
	MOV        AX,1d8h
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_2e88
	MOV        AL,0d8h
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [SI],AL
	CMP        word ptr [BP + 4h],0h
	JNZ        L_05c0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_9ce6
	MOV        word ptr [BP + -0ah],AX
	CALL       SUB_0000_58de
	CMP        AX,word ptr [BP + -0ah]
	JL         L_05c0
	MOV        AX,9532h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -8h],0ffffh
	JMP        L_0542
L_05c0:
	MOV        BX,DI
	MOV        CL,3h
	SHL        BX,CL
	OR         byte ptr [BX + 0ba16h],1h
	MOV        word ptr [BP + -8h],1h
	JMP        L_0542
	db 90h
L_05d4:
	MOV        AX,word ptr [BP + -8h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_04c2 ENDP
F_05e0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	CMP        word ptr [BP + 6h],0h
	JGE        L_05f6
	MOV        word ptr [BP + -6h],0ffffh
	JMP        L_06e1
	db 90h
L_05f6:
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JZ         L_061a
	CMP        word ptr [BP + 4h],0h
	JZ         L_0611
	MOV        AX,953ch
	PUSH       AX
	CALL       SUB_0000_3670
L_0611:
	MOV        word ptr [BP + -6h],0h
	JMP        L_06e1
	db 90h
L_061a:
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        byte ptr [BX + 0bh],47h
	MOV        word ptr [BX + 10h],1h
	MOV        AL,byte ptr [BX + 0ah]
	SUB        AH,AH
	CMP        AX,41h
	JZ         L_0646
	CMP        AX,42h
	JZ         L_0694
	CMP        AX,4dh
	JNZ        L_064e
L_0646:
	MOV        SI,BX
	MOV        AL,byte ptr [SI + 0eh]
L_064b:
	MOV        byte ptr [BX + 0fh],AL
L_064e:
	CMP        byte ptr DS:[5888h],62h
	JNC        L_0678
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AL,DS:[5888h]
	SUB        AH,AH
	SUB        CX,CX
	PUSH       CX
	PUSH       AX
	MOV        AX,word ptr [BX + 14h]
	CWD
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_2262
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_22b6
	MOV        BX,word ptr [BP + -2h]
	MOV        word ptr [BX + 14h],AX
L_0678:
	MOV        word ptr [BP + -8h],1h
	MOV        BX,word ptr [BP + -2h]
	MOV        AX,word ptr [BX + 14h]
	CWD
	MOV        CX,64h
	IDIV       CX
	MOV        word ptr [BP + -4h],AX
	MOV        DX,word ptr [BP + -8h]
	MOV        CX,AX
	JMP        L_06a3
	db 90h
L_0694:
	MOV        SI,BX
	MOV        AL,byte ptr [SI + 0eh]
	SUB        AH,AH
	SHR        AX,1h
	JMP        L_064b
	db 90h
L_06a0:
	INC        DX
	SAR        CX,1h
L_06a3:
	OR         CX,CX
	JG         L_06a0
	MOV        word ptr [BP + -8h],DX
	MOV        word ptr [BP + -4h],CX
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BP + -8h]
	MOV        byte ptr [BX + 16h],AL
	MOV        AX,1eh
	IMUL       DX
	MOV        word ptr [BX + 12h],AX
	CMP        word ptr [BP + 4h],1h
	JNZ        L_06ca
	MOV        AX,6h
	JMP        L_06d3
	db 90h
L_06ca:
	CMP        word ptr [BP + 4h],0h
	JNZ        L_06d7
	MOV        AX,8h
L_06d3:
	PUSH       AX
	CALL       F_0000
L_06d7:
	MOV        word ptr [BP + -6h],1h
	MOV        byte ptr DS:[0a9fah],1h
L_06e1:
	MOV        AX,word ptr [BP + -6h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db 0CBh
	db         33h    3
	db 0B8h
	db 0Ah
	db 00h
	db         50h    P
	db 0E8h
	db 0E0h
	db         2Dh    -
	db 0A0h
	db 97h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         25h    %
	db 0F0h
	db 00h
	db 0B1h
	db 04h
	db 0D3h
	db 0E8h
	db 05h
	db         41h    A
	db 00h
	db         50h    P
	db 0E8h
	db 0CDh
	db         2Dh    -
	db 0B8h
	db         27h    '
	db 00h
	db         50h    P
	db 0E8h
	db 0C6h
	db         2Dh    -
	db 0A0h
	db 97h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         25h    %
	db 0Fh
	db 00h
	db 05h
	db         41h    A
	db 00h
	db         50h    P
	db 0E8h
	db 0B7h
	db         2Dh    -
	db 0B8h
	db         48h    H
	db 95h
	db         50h    P
	db 0E8h
	db         46h    F
	db         2Fh    /
	db 0A0h
	db 96h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         25h    %
	db 0F0h
	db 00h
	db 0B1h
	db 04h
	db 0D3h
	db 0E8h
	db 05h
	db         41h    A
	db 00h
	db         50h    P
	db 0E8h
	db 9Dh
	db         2Dh    -
	db 0B8h
	db         27h    '
	db 00h
	db         50h    P
	db 0E8h
	db 96h
	db         2Dh    -
	db 0A0h
	db 96h
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         25h    %
	db 0Fh
	db 00h
	db 05h
	db         41h    A
	db 00h
	db         50h    P
	db 0E8h
	db 87h
	db         2Dh    -
	db 0B8h
	db         22h    "
	db 00h
	db         50h    P
	db 0E8h
	db 80h
	db         2Dh    -
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db         5Eh    ^
	db         33h    3
	db 0B8h
	db 0Ah
	db 00h
	db         50h    P
	db 0E8h
	db         73h    s
	db         2Dh    -
	db 0C3h
	; Func
F_05e0 ENDP
F_0768 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	CALL       F_0306
	OR         AX,AX
	JNZ        L_077a
	MOV        AX,0ffffh
	JMP        L_07b8
L_077a:
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_6222
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -4h],0h
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,97h
	JZ         L_07a0
	CMP        AX,98h
	JZ         L_07b2
	JMP        L_07ad
	db 90h
L_07a0:
	MOV        byte ptr [BX],0b8h
L_07a3:
	OR         byte ptr DS:[24e6h],2h
	MOV        word ptr [BP + -4h],1h
L_07ad:
	MOV        AX,word ptr [BP + -4h]
	JMP        L_07b8
L_07b2:
	MOV        byte ptr [BX],0bah
	JMP        L_07a3
	db 90h
L_07b8:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0768 ENDP
F_07bc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],80h
	JC         L_07ce
	JMP        L_0866
L_07ce:
	CMP        word ptr [BP + 4h],0h
	JZ         L_07db
	MOV        AX,4h
	PUSH       AX
	CALL       F_0000
L_07db:
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	MOV        AX,word ptr [SI + 24d6h]
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [SI + 24deh]
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,DS:[5897h]
	MOV        DI,AX
	MOV        AL,DS:[5895h]
	MOV        CL,6h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX
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
	CMP        AL,80h
	JZ         L_0840
	MOV        AX,word ptr [BP + -0ah]
	ADD        AX,DI
	AND        AX,7h
	SHL        AX,CL
	MOV        CX,word ptr [BP + -8h]
	ADD        CX,SI
	AND        CX,7h
	ADD        AX,CX
	ADD        AX,word ptr [BP + -0ch]
	ADD        AX,595ah
	MOV        word ptr [BP + -2h],AX
L_0840:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX]
	AND        AL,0f0h
	CMP        AL,80h
	JNZ        L_085e
	AND        byte ptr [BX],8h
	MOV        AX,954ch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -6h],0ffffh
	JMP        L_08de
	db 90h
L_085e:
	MOV        word ptr [BP + -6h],0h
	JMP        L_08de
	db 90h
L_0866:
	CALL       F_0306
	OR         AX,AX
	JNZ        L_0872
	MOV        AX,0ffffh
	JMP        L_08e1
L_0872:
	CMP        word ptr [BP + 4h],0h
	JZ         L_087f
	MOV        AX,4h
	PUSH       AX
	CALL       F_0000
L_087f:
	MOV        word ptr [BP + -6h],0h
	SUB        SI,SI
	MOV        DI,5c5ah
	MOV        word ptr [BP + -10h],5c5ch
	MOV        word ptr [BP + -12h],5c5dh
L_0893:
	MOV        AL,byte ptr [DI]
	AND        AL,0fch
	CMP        AL,0e8h
	JNZ        L_08ca
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr DS:[5876h]
	JNZ        L_08ca
	MOV        BX,word ptr [BP + -12h]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr DS:[5878h]
	JNZ        L_08ca
	MOV        word ptr [BP + -6h],1h
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_5894
L_08c4:
	MOV        word ptr [BP + -4h],SI
	JMP        L_08de
	db 90h
L_08ca:
	ADD        DI,8h
	ADD        word ptr [BP + -10h],8h
	ADD        word ptr [BP + -12h],8h
	INC        SI
	CMP        SI,20h
	JGE        L_08c4
	JMP        L_0893
	db 90h
L_08de:
	MOV        AX,word ptr [BP + -6h]
L_08e1:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_07bc ENDP
F_08ea PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 4h]
	MOV        DS:[58a6h],AL
	POP        BP
	RET        2h
	db 90h
	; Func
F_08ea ENDP
F_08f8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 8h]
	MOV        DS:[587ah],AL
	MOV        AL,byte ptr [BP + 6h]
	MOV        DS:[588eh],AL
	PUSH       word ptr [BP + 4h]
	CALL       F_0000
	CALL       SUB_0000_4720
	POP        BP
	RET        6h
	; Func
F_08f8 ENDP
F_0914 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,byte ptr [BX + 4b95h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	OR         BX,BX
	JLE        L_095e
	SUB        DI,DI
	MOV        SI,AX
	JMP        L_0953
L_0932:
	MOV        AX,3h
	PUSH       AX
	PUSH       AX
	MOV        AL,byte ptr [SI + 4b9eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 4bc2h]
	PUSH       AX
	MOV        AL,DS:[5895h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	LEA        AX,[DI + 1h]
	PUSH       AX
	CALL       SUB_0000_5894
	INC        SI
	INC        DI
L_0953:
	CMP        DI,word ptr [BP + 4h]
	JNZ        L_0932
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
L_095e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0914 ENDP
F_0966 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ah],1h
	MOV        word ptr [BP + -4h],0h
	SUB        SI,SI
	MOV        DL,byte ptr DS:[5896h]
	MOV        CL,byte ptr DS:[5897h]
L_0982:
	CMP        byte ptr [SI + 1f6eh],DL
	JZ         L_098b
	JMP        L_0a2e
L_098b:
	CMP        byte ptr [SI + 1f76h],CL
	JZ         L_0994
	JMP        L_0a2e
L_0994:
	MOV        word ptr [BP + -8h],SI
	CMP        SI,8h
	JNZ        L_09a1
	MOV        word ptr [BP + -8h],6h
L_09a1:
	MOV        AL,6ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	CALL       SUB_0000_7730
	MOV        AX,0b58bh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906
	MOV        AX,0b5b6h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0bd08h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_593c
	CMP        byte ptr DS:[0bd08h],0h
	JNZ        L_09d6
	JMP        L_0d1d
L_09d6:
	MOV        BX,word ptr [BP + -8h]
	SHL        BX,1h
	PUSH       word ptr [BX + 4b3eh]
	MOV        AX,0bd08h
	PUSH       AX
	CALL       SUB_0000_8d3e
	INC        AX
	JNZ        L_09ee
	MOV        word ptr [BP + -0ah],0h
L_09ee:
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_5906
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	SUB        SI,SI
	MOV        AX,word ptr [BP + -8h]
	SHL        AX,1h
	ADD        AX,1f5eh
	MOV        word ptr [BP + -0ch],AX
	MOV        DI,word ptr [BP + -0ah]
L_0a0c:
	MOV        AX,958eh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0bd08h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_593c
	CMP        byte ptr DS:[0bd08h],0h
	JNZ        L_0a3a
	MOV        word ptr [BP + -0ah],DI
	MOV        word ptr [BP + -6h],SI
	JMP        L_0d1d
L_0a2e:
	INC        SI
	CMP        SI,8h
	JL         L_0a37
	JMP        L_0994
L_0a37:
	JMP        L_0982
L_0a3a:
	MOV        BX,word ptr [BP + -0ch]
	PUSH       word ptr [BX]
	MOV        AX,0bd08h
	PUSH       AX
	CALL       SUB_0000_8d3e
	INC        AX
	JNZ        L_0a4b
	SUB        DI,DI
L_0a4b:
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_5906
	INC        SI
	CMP        SI,3h
	JL         L_0a0c
	MOV        word ptr [BP + -0ah],DI
	MOV        word ptr [BP + -6h],SI
	OR         DI,DI
	JNZ        L_0a6c
	MOV        AX,0b5deh
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0d1d
L_0a6c:
	MOV        AX,1h
	MOV        CL,byte ptr [BP + -8h]
	SHL        AX,CL
	MOV        CL,byte ptr DS:[58ceh]
	SUB        CH,CH
	TEST       CX,AX
	JZ         L_0a81
	JMP        L_0b08
L_0a81:
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -8h]
	SHL        AL,CL
	OR         byte ptr DS:[58cch],AL
	MOV        AX,0b5ffh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AL,1ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	CALL       SUB_0000_448c
	MOV        AX,0b62ch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -8h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4b5eh]
	ADD        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,9598h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_448c
	MOV        AX,0b669h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -6h],7h
	MOV        DI,4be6h
	MOV        word ptr [BP + -0eh],4bf4h
	MOV        word ptr [BP + -10h],4c02h
	MOV        SI,4c10h
L_0adb:
	PUSH       word ptr [DI]
	MOV        AX,1h
	PUSH       AX
	MOV        BX,word ptr [BP + -0eh]
	PUSH       word ptr [BX]
	MOV        BX,word ptr [BP + -10h]
	PUSH       word ptr [BX]
	PUSH       word ptr [SI]
	CALL       SUB_0000_3fb2
	ADD        DI,2h
	ADD        word ptr [BP + -0eh],2h
	ADD        word ptr [BP + -10h],2h
	ADD        SI,2h
	CMP        SI,4c1eh
	JC         L_0adb
	JMP        L_0d16
	db 90h
L_0b08:
	MOV        AX,1h
	MOV        CL,byte ptr [BP + -8h]
	SHL        AX,CL
	MOV        CL,byte ptr DS:[58cch]
	SUB        CH,CH
	TEST       CX,AX
	JZ         L_0b1d
	JMP        L_0c18
L_0b1d:
	MOV        DI,word ptr [BP + -4h]
	MOV        SI,word ptr [BP + -2h]
	JMP        L_0b5f
	db 90h
L_0b26:
	PUSH       SI
	CALL       SUB_0000_34da
	SUB        SI,30h
	JNZ        L_0b40
	MOV        AX,959ch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	JMP        L_0d1d
	db 90h
L_0b40:
	MOV        AX,95a2h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,64h
	IMUL       SI
	CMP        AX,word ptr DS:[57aah]
	JLE        L_0b5c
	MOV        AX,0b6b9h
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0b5f
	db 90h
L_0b5c:
	MOV        DI,1h
L_0b5f:
	OR         DI,DI
	JNZ        L_0b7c
	MOV        AX,0b692h
	PUSH       AX
	CALL       SUB_0000_3670
L_0b6a:
	CALL       SUB_0000_448c
	MOV        SI,AX
	CMP        AX,30h
	JC         L_0b6a
	CMP        AX,39h
	JBE        L_0b26
	JMP        L_0b6a
	db 90h
L_0b7c:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	MOV        AX,64h
	IMUL       SI
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_4720
	MOV        AL,byte ptr [BP + -2h]
	ADD        byte ptr DS:[5888h],AL
	CMP        byte ptr DS:[5888h],63h
	JBE        L_0ba1
	MOV        byte ptr DS:[5888h],63h
L_0ba1:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,95aah
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,95b4h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	MOV        SI,7d0h
L_0bd3:
	MOV        AX,0a8ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3fb2
	ADD        SI,32h
	CMP        SI,61a8h
	JL         L_0bd3
	MOV        word ptr [BP + -6h],SI
	MOV        SI,61a8h
L_0bf5:
	MOV        AX,0a8ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3fb2
	SUB        SI,32h
	CMP        SI,7d0h
	JG         L_0bf5
	MOV        word ptr [BP + -6h],SI
	JMP        L_0d16
	db 90h
L_0c18:
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -8h]
	SHL        AL,CL
	AND        AL,byte ptr DS:[58cch]
	XOR        AL,0ffh
	AND        byte ptr DS:[58cch],AL
	MOV        AX,0b6d7h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	MOV        SI,7d0h
L_0c47:
	MOV        AX,0c1ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3fb2
	ADD        SI,32h
	CMP        SI,61a8h
	JL         L_0c47
	MOV        word ptr [BP + -6h],SI
	MOV        SI,61a8h
L_0c69:
	MOV        AX,0c1ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3fb2
	SUB        SI,32h
	CMP        SI,7d0h
	JG         L_0c69
	MOV        word ptr [BP + -6h],SI
	CALL       SUB_0000_4e92
	ADD        byte ptr DS:[5888h],3h
	CMP        byte ptr DS:[5888h],63h
	JBE        L_0c9c
	MOV        byte ptr DS:[5888h],63h
L_0c9c:
	MOV        BX,word ptr [BP + -8h]
	CMP        byte ptr [BX + 4b7eh],0h
	JZ         L_0cbd
	INC        byte ptr DS:[55b4h]
	CMP        byte ptr DS:[55b4h],1eh
	JBE        L_0cb6
	MOV        byte ptr DS:[55b4h],1eh
L_0cb6:
	MOV        AX,95b8h
	PUSH       AX
	CALL       SUB_0000_3670
L_0cbd:
	MOV        BX,word ptr [BP + -8h]
	CMP        byte ptr [BX + 4b86h],0h
	JZ         L_0cde
	INC        byte ptr DS:[55b5h]
	CMP        byte ptr DS:[55b5h],1eh
	JBE        L_0cd7
	MOV        byte ptr DS:[55b5h],1eh
L_0cd7:
	MOV        AX,95c6h
	PUSH       AX
	CALL       SUB_0000_3670
L_0cde:
	MOV        BX,word ptr [BP + -8h]
	CMP        byte ptr [BX + 4b8eh],0h
	JZ         L_0cff
	INC        byte ptr DS:[55b6h]
	CMP        byte ptr DS:[55b6h],1eh
	JBE        L_0cf8
	MOV        byte ptr DS:[55b6h],1eh
L_0cf8:
	MOV        AX,95d4h
	PUSH       AX
	CALL       SUB_0000_3670
L_0cff:
	CMP        word ptr [BP + -8h],7h
	JNZ        L_0d16
	ADD        byte ptr DS:[5888h],3h
	CMP        byte ptr DS:[5888h],63h
	JBE        L_0d16
	MOV        byte ptr DS:[5888h],63h
L_0d16:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906
L_0d1d:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0966 ENDP
F_0d24 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	CALL       SUB_0000_448c
	MOV        AX,0b703h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_448c
	MOV        AX,0b733h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_448c
	MOV        word ptr [BP + -2h],0h
	MOV        AL,DS:[58cch]
	SUB        AH,AH
	MOV        SI,AX
	MOV        DX,word ptr [BP + -2h]
L_0d51:
	MOV        AX,1h
	MOV        CX,DX
	SHL        AX,CL
	TEST       SI,AX
	JZ         L_0d6e
L_0d5c:
	MOV        word ptr [BP + -2h],DX
	CMP        DX,8h
	JNZ        L_0d76
	MOV        AX,0b75ch
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0e5e
L_0d6e:
	INC        DX
	CMP        DX,8h
	JGE        L_0d5c
	JMP        L_0d51
L_0d76:
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -2h]
	SHL        AL,CL
	OR         byte ptr DS:[58ceh],AL
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr [BP + -2h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4b6eh]
	ADD        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,95e6h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_448c
	CMP        byte ptr DS:[58ceh],0ffh
	JZ         L_0dac
	JMP        L_0e5e
L_0dac:
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	CALL       SUB_0000_4e92
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	CALL       SUB_0000_4e92
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6
	CALL       SUB_0000_4e92
	MOV        AX,0b773h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_448c
	MOV        AX,95eah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,0b79dh
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	CALL       SUB_0000_448c
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,0b7efh
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	CALL       SUB_0000_448c
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,0b82ah
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	CALL       SUB_0000_448c
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,0b89eh
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	CALL       SUB_0000_448c
L_0e5e:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0d24 ENDP
F_0e64 PROC NEAR
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5906
	CALL       SUB_0000_615e
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_5906
	RET
	; Func
F_0e64 ENDP
F_0e76 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_6222
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        byte ptr DS:[24e6h],1h
	MOV        AL,DS:[5893h]
	MOV        DS:[0bd15h],AL
	MOV        byte ptr DS:[5893h],0ffh
	MOV        byte ptr DS:[589eh],0ffh
	MOV        word ptr [BP + -8h],20h
	MOV        DI,0a9fch
	MOV        SI,5c5ah
L_0eb9:
	PUSH       SI
	PUSH       DI
	PUSH       DS
	POP        ES
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	POP        DI
	POP        SI
	MOV        byte ptr [SI],0h
	ADD        DI,8h
	ADD        SI,8h
	CMP        SI,5d5ah
	JC         L_0eb9
	CMP        word ptr [BP + -4h],11h
	JZ         L_0ee6
	MOV        AX,95fch
	PUSH       AX
	MOV        AX,0ac64h
	PUSH       AX
	MOV        AX,0b0h
	PUSH       AX
	JMP        L_0ef5
L_0ee6:
	MOV        AX,960ah
	PUSH       AX
	MOV        AX,0ac64h
	PUSH       AX
	MOV        AX,0b0h
	PUSH       AX
	MOV        AX,160h
L_0ef5:
	PUSH       AX
	CALL       SUB_0000_438e
	MOV        AX,9618h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,3abh
	PUSH       AX
	CALL       SUB_0000_438e
	MOV        word ptr [BP + -8h],0bh
	SUB        DI,DI
	SUB        SI,SI
L_0f15:
	MOV        word ptr [BP + -0ah],0h
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
	MOV        word ptr [BP + -0ah],0bh
	ADD        DI,10h
	ADD        SI,20h
	CMP        SI,160h
	JL         L_0f15
	CALL       SUB_0000_7730
	MOV        word ptr [BP + -8h],10h
	MOV        SI,55e7h
	MOV        CX,word ptr [BP + -6h]
L_0f4f:
	CMP        byte ptr [SI],7fh
	JNZ        L_0f55
	INC        CX
L_0f55:
	ADD        SI,20h
	CMP        SI,57c7h
	JC         L_0f4f
	MOV        word ptr [BP + -6h],CX
	OR         CX,CX
	JLE        L_0f69
	PUSH       CX
	CALL       F_0914
L_0f69:
	CMP        word ptr [BP + -4h],11h
	JZ         L_0f74
	MOV        AX,0b8cch
	JMP        L_0f77
L_0f74:
	MOV        AX,0b8f9h
L_0f77:
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -8h],4h
	MOV        SI,4h
L_0f83:
	CALL       F_0e64
	DEC        SI
	JNZ        L_0f83
	MOV        AL,1ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	MOV        byte ptr DS:[5c5ch],5h
	MOV        byte ptr DS:[5c5dh],0ah
	MOV        AL,DS:[5895h]
	MOV        DS:[5c5eh],AL
	CALL       F_0e64
	CMP        word ptr [BP + -4h],11h
	JZ         L_0fad
	JMP        L_103c
L_0fad:
	CMP        word ptr [BP + -6h],0h
	JG         L_0fb6
	JMP        L_103c
L_0fb6:
	MOV        AX,9624h
	PUSH       AX
	CALL       SUB_0000_3670
	CMP        word ptr [BP + -6h],1h
	JNZ        L_0fc8
	MOV        AX,9636h
	JMP        L_0fcb
L_0fc8:
	MOV        AX,9648h
L_0fcb:
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -8h],10h
	MOV        word ptr [BP + -0ch],55e7h
	MOV        word ptr [BP + -12h],55c8h
	MOV        word ptr [BP + -14h],20h
	MOV        SI,word ptr [BP + -0ah]
L_0fe6:
	MOV        BX,word ptr [BP + -0ch]
	CMP        byte ptr [BX],7fh
	JNZ        L_1026
	SUB        SI,SI
	MOV        BX,word ptr [BP + -12h]
	CMP        byte ptr [BX],0h
	JZ         L_101f
	MOV        DI,word ptr [BP + -14h]
	MOV        word ptr [BP + -0eh],DI
L_0ffe:
	MOV        BX,word ptr [BP + -0eh]
	MOV        AX,SI
	INC        SI
	ADD        BX,AX
	MOV        AL,byte ptr [BX + 55a8h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3e52
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,DI
	ADD        BX,SI
	CMP        byte ptr [BX + 55a8h],0h
	JNZ        L_0ffe
L_101f:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
L_1026:
	ADD        word ptr [BP + -0ch],20h
	ADD        word ptr [BP + -12h],20h
	ADD        word ptr [BP + -14h],20h
	CMP        word ptr [BP + -14h],200h
	JL         L_0fe6
	MOV        word ptr [BP + -0ah],SI
L_103c:
	CMP        word ptr [BP + -4h],11h
	JZ         L_1048
	MOV        AX,4h
	JMP        L_104b
	db 90h
L_1048:
	MOV        AX,7h
L_104b:
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -8h],0h
	OR         AX,AX
	JLE        L_1066
	MOV        SI,AX
	ADD        word ptr [BP + -8h],AX
L_105c:
	DEC        byte ptr DS:[5c5dh]
	CALL       F_0e64
	DEC        SI
	JNZ        L_105c
L_1066:
	CMP        word ptr [BP + -4h],11h
	JZ         L_1072
	CALL       F_0966
	JMP        L_1075
	db 90h
L_1072:
	CALL       F_0d24
L_1075:
	MOV        AL,1ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5906
	MOV        AL,DS:[5c5dh]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX
	CMP        AX,0ah
	JGE        L_10a6
	MOV        AX,0ah
	SUB        AX,word ptr [BP + -8h]
	MOV        SI,AX
	ADD        word ptr [BP + -8h],SI
L_109c:
	INC        byte ptr DS:[5c5dh]
	CALL       F_0e64
	DEC        SI
	JNZ        L_109c
L_10a6:
	SUB        AL,AL
	MOV        DS:[5c5dh],AL
	MOV        DS:[5c5ch],AL
	MOV        DS:[5c5ah],AL
	MOV        word ptr [BP + -8h],4h
	MOV        SI,4h
L_10b9:
	CALL       F_0e64
	DEC        SI
	JNZ        L_10b9
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906
	MOV        word ptr [BP + -8h],20h
	MOV        DI,5c5ah
	MOV        SI,0a9fch
L_10d1:
	PUSH       SI
	PUSH       DI
	PUSH       DS
	POP        ES
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	POP        DI
	POP        SI
	ADD        DI,8h
	ADD        SI,8h
	CMP        SI,0aafch
	JC         L_10d1
	MOV        AL,DS:[0bd15h]
	MOV        DS:[5893h],AL
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_6d9c
	CALL       SUB_0000_7c6a
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0e76 ENDP
F_10fe PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,9658h
	PUSH       AX
	CALL       SUB_0000_3670
L_110b:
	CALL       SUB_0000_448c
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,59h
	JZ         L_1119
	CMP        AL,4eh
	JNZ        L_110b
L_1119:
	CMP        byte ptr [BP + -2h],4eh
	JNZ        L_1126
	MOV        AX,9666h
	JMP        L_11b2
	db 90h
L_1126:
	MOV        AX,966ah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AL,DS:[0a9bdh]
	MOV        byte ptr [BP + -4h],AL
	CMP        AL,5h
	JZ         L_113e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_433e
L_113e:
	MOV        AX,967ah
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_433e
	MOV        AX,9684h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e
	CMP        byte ptr [BP + -4h],1h
	JZ         L_117e
	MOV        AX,968eh
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_43f8
L_117e:
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_433e
	MOV        AX,9698h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	CALL       SUB_0000_43f8
	MOV        AX,96a2h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	CALL       SUB_0000_43f8
	MOV        AL,byte ptr [BP + -4h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_433e
	MOV        AX,96ach
L_11b2:
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        SP,BP
	POP        BP
	RET
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
F_10fe ENDP
_TEXT ENDS
END
