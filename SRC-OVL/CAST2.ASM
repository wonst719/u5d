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
	CMP        word ptr [BP + 4h],9h	; param_1
	JGE        L_0080
	MOV        AX,320h
	PUSH       AX
	MOV        AX,640h
	IMUL       word ptr [BP + 4h]	; param_1
	ADD        AX,1f40h
	PUSH       AX
	MOV        AX,2bch
	PUSH       AX
	CALL       SUB_0000_405c ; 1000:223Ch
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	MOV        SI,word ptr [BP + 4h]	; param_1
	SHL        SI,1h
	MOV        AX,0fa0h
	IMUL       word ptr [BP + 4h]	; param_1
	MOV        DI,AX
	ADD        DI,2710h
	PUSH       word ptr [SI + 4af6h]
	MOV        AX,1h
	PUSH       AX
	PUSH       DI
	PUSH       word ptr [SI + 4b08h]
	PUSH       word ptr [SI + 4b2ch]
	CALL       SUB_0000_3fb2 ; 1000:2192h
	PUSH       word ptr [SI + 4af6h]
	MOV        AX,1h
	PUSH       AX
	PUSH       DI
	PUSH       word ptr [SI + 4b1ah]
	MOV        AX,word ptr [SI + 4b2ch]
	NEG        AX
	PUSH       AX
	CALL       SUB_0000_3fb2 ; 1000:2192h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
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
	CALL       SUB_0000_3fb2 ; 1000:2192h
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
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_4cae ; 1000:2E8Eh
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JGE        L_00ba
	MOV        AX,94feh
	JMP        L_00c4
L_00ba:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
L_00c4:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_3d32 ; 1000:1F12h
	OR         AX,AX
	JZ         L_00d6
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
L_00d6:
	MOV        AX,word ptr [BP + -2h]	; local_4
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
	MOV        word ptr [BP + -2h],0ffffh	; local_4
	MOV        word ptr [BP + -0ah],DI	; local_c
L_00f0:
	CALL       SUB_0000_448c ; 1000:266Ch
	PUSH       AX
	CALL       SUB_0000_3e52 ; 1000:2032h
	MOV        byte ptr [BP + -14h],AL	; local_16
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
	MOV        BL,byte ptr [BP + -14h]	; local_16
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1b7ah]
	CALL       SUB_0000_3f8c ; 1000:216Ch
	MOV        SI,AX
	CALL       SUB_0000_3d32 ; 1000:1F12h
	ADD        AX,SI
	CMP        AX,0dh
	JLE        L_0139
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
L_0139:
	CALL       SUB_0000_3d32 ; 1000:1F12h
	MOV        byte ptr [BP + DI + -6h],AL
	MOV        BL,byte ptr [BP + -14h]	; local_16
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1b7ah]
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	INC        DI
	JMP        L_01cf
	db 90h
L_0158:
	MOV        AL,byte ptr [BP + -14h]	; local_16
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
	CALL       SUB_0000_3d32 ; 1000:1F12h
	OR         AX,AX
	JNZ        L_018c
	MOV        AL,byte ptr [BP + DI + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3b0e ; 1000:1CEEh
	DEC        AX
	JMP        L_0195
L_018c:
	MOV        AL,byte ptr [BP + DI + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3b0e ; 1000:1CEEh
L_0195:
	PUSH       AX
	CALL       SUB_0000_3a12 ; 1000:1BF2h
	MOV        BL,byte ptr [BP + DI + -0eh]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1b7ah]
	CALL       SUB_0000_3f8c ; 1000:216Ch
	MOV        word ptr [BP + -1ah],AX	; local_1c
	MOV        word ptr [BP + -10h],0h	; local_12
	OR         AX,AX
	JLE        L_01c2
	MOV        SI,AX
	ADD        word ptr [BP + -10h],SI	; local_12
L_01b8:
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	DEC        SI
	JNZ        L_01b8
L_01c2:
	MOV        AL,byte ptr [BP + DI + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3b0e ; 1000:1CEEh
	PUSH       AX
	CALL       SUB_0000_3a12 ; 1000:1BF2h
L_01cf:
	CMP        word ptr [BP + -0ah],0h	; local_c
	JNZ        L_01e2
	JMP        L_00f0
L_01d8:
	SUB        DI,DI
L_01da:
	MOV        word ptr [BP + -0ah],1h	; local_c
	JMP        L_01cf
	db 90h
L_01e2:
	MOV        word ptr [BP + -8h],DI	; local_a
	DEC        DI
L_01e6:
	MOV        SI,1h
	SUB        CX,CX
	CMP        word ptr [BP + -8h],SI	; local_a
	JLE        L_022b
	MOV        DX,DI
L_01f2:
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0dh]	; local_f
	MOV        BX,CX
	ADD        BX,BP
	CMP        byte ptr [BX + -0ch],AL	; local_e
	JNC        L_0226
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0eh]	; local_10
	MOV        byte ptr [BP + -14h],AL	; local_16
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0dh]	; local_f
	MOV        BX,CX
	ADD        BX,BP
	MOV        byte ptr [BX + -0eh],AL	; local_10
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BP + -14h]	; local_16
	MOV        byte ptr [BX + -0dh],AL	; local_f
	SUB        SI,SI
L_0226:
	INC        CX
	CMP        CX,DX
	JNZ        L_01f2
L_022b:
	OR         SI,SI
	JZ         L_01e6
	MOV        word ptr [BP + -0ah],SI	; local_c
	MOV        word ptr [BP + -10h],CX	; local_12
	MOV        word ptr [BP + -10h],0h	; local_12
	MOV        AX,word ptr [BP + -8h]	; local_a
	DEC        AX
	MOV        word ptr [BP + -22h],AX	; local_24
	MOV        word ptr [BP + -24h],1c30h	; local_26
	MOV        word ptr [BP + -26h],1c30h	; local_28
	MOV        SI,word ptr [BP + -16h]	; local_18
L_024e:
	MOV        word ptr [BP + -18h],1h	; local_1a
	SUB        SI,SI
	MOV        word ptr [BP + -12h],SI	; local_14
	CMP        word ptr [BP + -8h],SI	; local_a
	JLE        L_0280
	MOV        DI,word ptr [BP + -22h]	; local_24
	MOV        BX,word ptr [BP + -24h]	; local_26
	MOV        AX,word ptr [BX]
	MOV        word ptr [BP + -20h],AX	; local_22
	MOV        CX,SI
L_026a:
	MOV        BX,CX
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -0eh]
	MOV        BX,word ptr [BP + -20h]	; local_22
	CMP        byte ptr [BX + SI],AL
	JZ         L_02b2
	MOV        word ptr [BP + -18h],0h	; local_1a
L_027d:
	MOV        word ptr [BP + -12h],CX	; local_14
L_0280:
	CMP        word ptr [BP + -18h],0h	; local_1a
	JZ         L_0295
	MOV        BX,word ptr [BP + -26h]	; local_28
	MOV        BX,word ptr [BX]
	CMP        byte ptr [BX + SI],0h
	JZ         L_0295
	MOV        word ptr [BP + -18h],0h	; local_1a
L_0295:
	CMP        word ptr [BP + -18h],0h	; local_1a
	JZ         L_02d6
	MOV        AX,word ptr [BP + -10h]	; local_12
	MOV        word ptr [BP + -2h],AX	; local_4
L_02a1:
	MOV        word ptr [BP + -16h],SI	; local_18
	CMP        word ptr [BP + -8h],0h	; local_a
	JNZ        L_02ea
	MOV        word ptr [BP + -2h],0ffffh	; local_4
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
	CMP        word ptr [BP + -8h],CX	; local_a
	JLE        L_027d
	JMP        L_026a
L_02d6:
	ADD        word ptr [BP + -24h],2h	; local_26
	ADD        word ptr [BP + -26h],2h	; local_28
	INC        word ptr [BP + -10h]	; local_12
	CMP        word ptr [BP + -10h],30h	; local_12
	JGE        L_02a1
	JMP        L_024e
L_02ea:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	CMP        word ptr [BP + -2h],0h	; local_4
	JGE        L_02fc
	MOV        word ptr [BP + -2h],0fffeh	; local_4
L_02fc:
	MOV        AX,word ptr [BP + -2h]	; local_4
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
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        SI,SI
L_0347:
	CALL       SUB_0000_448c ; 1000:266Ch
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
	CALL       SUB_0000_3670 ; 1000:1850h
	DEC        word ptr DS:[5878h]
L_0377:
	OR         SI,SI
	JNZ        L_03b4
	JMP        L_0347
	db 90h
L_037e:
	MOV        AX,9518h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	INC        word ptr DS:[5876h]
	JMP        L_0377
	db 90h
L_038c:
	MOV        AX,951eh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	INC        word ptr DS:[5878h]
	JMP        L_0377
	db 90h
L_039a:
	MOV        AX,9526h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	DEC        word ptr DS:[5876h]
	JMP        L_0377
	db 90h
L_03a8:
	MOV        AX,952ch
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        DI,DI
	JMP        L_0377
	db 90h
L_03b4:
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -2h],SI	; local_4
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
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JNZ        L_03de
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_0400
L_03de:
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,SI
	ADD        AX,55b8h
	PUSH       AX
	CALL       SUB_0000_58de ; 1000:3ABEh
	PUSH       AX
	PUSH       word ptr [SI + 55bah]
	CALL       SUB_0000_5d34 ; 1000:3F14h
	MOV        word ptr [BP + -2h],1h	; local_4
	MOV        byte ptr DS:[0a9fah],1h
L_0400:
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_03c2 ENDP
F_040a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 6h],0h	; param_2
	JNZ        L_0419
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0468
L_0419:
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0424
	MOV        AX,1h
	JMP        L_0427
L_0424:
	MOV        AX,2h
L_0427:
	PUSH       AX
	CALL       F_0000
	MOV        AX,word ptr [BP + 6h]	; param_2
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
	CALL       SUB_0000_4cb6 ; 1000:2E96h
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
	CALL       SUB_0000_7b2a ; 1000:5D0Ah
	MOV        word ptr [BP + -2h],14h	; local_4
	MOV        SI,14h
L_04a0:
	CMP        byte ptr DS:[587ah],54h
	JZ         L_04aa
	CALL       SUB_0000_6372 ; 1000:4552h
L_04aa:
	CALL       SUB_0000_71b4 ; 1000:5394h
	CALL       SUB_0000_74cc ; 1000:56ACh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3f1a ; 1000:20FAh
	DEC        SI
	JNZ        L_04a0
	CALL       SUB_0000_7730 ; 1000:5910h
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
	MOV        word ptr [BP + -8h],0h	; local_a
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_04da
	MOV        AX,5h
	JMP        L_04dd
L_04da:
	MOV        AX,8h
L_04dd:
	PUSH       AX
	CALL       F_0000
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        SI,word ptr [BP + -4h]	; local_6
L_04ec:
	CALL       SUB_0000_9cb6 ; 1000:7E96h
	OR         AX,AX
	JZ         L_0518
	MOV        AX,0d8h
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_9b96 ; 1000:7D76h
	OR         AX,AX
	JZ         L_0518
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_6222 ; 1000:4402h
	MOV        BX,AX
	CMP        byte ptr [BX],0ffh
	JNZ        L_0524
L_0518:
	INC        word ptr [BP + -6h]	; local_8
	CMP        word ptr [BP + -6h],8h	; local_8
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
	CALL       SUB_0000_8326 ; 1000:6506h
	MOV        DI,AX
	OR         DI,DI
	JGE        L_054c
L_0542:
	MOV        word ptr [BP + -2h],DI	; local_4
	MOV        word ptr [BP + -4h],SI	; local_6
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
	CALL       SUB_0000_3fb2 ; 1000:2192h
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
	CALL       SUB_0000_2e88 ; 1000:1068h
	MOV        AL,0d8h
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [SI],AL
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_05c0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_9ce6 ; 1000:7EC6h
	MOV        word ptr [BP + -0ah],AX	; local_c
	CALL       SUB_0000_58de ; 1000:3ABEh
	CMP        AX,word ptr [BP + -0ah]	; local_c
	JL         L_05c0
	MOV        AX,9532h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -8h],0ffffh	; local_a
	JMP        L_0542
L_05c0:
	MOV        BX,DI
	MOV        CL,3h
	SHL        BX,CL
	OR         byte ptr [BX + 0ba16h],1h
	MOV        word ptr [BP + -8h],1h	; local_a
	JMP        L_0542
	db 90h
L_05d4:
	MOV        AX,word ptr [BP + -8h]	; local_a
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
	CMP        word ptr [BP + 6h],0h	; param_2
	JGE        L_05f6
	MOV        word ptr [BP + -6h],0ffffh	; local_8
	JMP        L_06e1
	db 90h
L_05f6:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JZ         L_061a
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_0611
	MOV        AX,953ch
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_0611:
	MOV        word ptr [BP + -6h],0h	; local_8
	JMP        L_06e1
	db 90h
L_061a:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -2h],AX	; local_4
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
	CALL       SUB_0000_2262 ; 1000:0442h
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_22b6 ; 1000:0496h
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        word ptr [BX + 14h],AX
L_0678:
	MOV        word ptr [BP + -8h],1h	; local_a
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AX,word ptr [BX + 14h]
	CWD
	MOV        CX,64h
	IDIV       CX
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        DX,word ptr [BP + -8h]	; local_a
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
	MOV        word ptr [BP + -8h],DX	; local_a
	MOV        word ptr [BP + -4h],CX	; local_6
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BP + -8h]	; local_a
	MOV        byte ptr [BX + 16h],AL
	MOV        AX,1eh
	IMUL       DX
	MOV        word ptr [BX + 12h],AX
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_06ca
	MOV        AX,6h
	JMP        L_06d3
	db 90h
L_06ca:
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_06d7
	MOV        AX,8h
L_06d3:
	PUSH       AX
	CALL       F_0000
L_06d7:
	MOV        word ptr [BP + -6h],1h	; local_8
	MOV        byte ptr DS:[0a9fah],1h
L_06e1:
	MOV        AX,word ptr [BP + -6h]	; local_8
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0CBh
	db 33h
	db 0B8h
	db 0Ah
	db 00h
	db 50h
	db 0E8h
	db 0E0h
	db 2Dh
	db 0A0h
	db 97h
	db 58h
	db 2Ah
	db 0E4h
	db 25h
	db 0F0h
	db 00h
	db 0B1h
	db 04h
	db 0D3h
	db 0E8h
	db 05h
	db 41h
	db 00h
	db 50h
	db 0E8h
	db 0CDh
	db 2Dh
	db 0B8h
	db 27h
	db 00h
	db 50h
	db 0E8h
	db 0C6h
	db 2Dh
	db 0A0h
	db 97h
	db 58h
	db 2Ah
	db 0E4h
	db 25h
	db 0Fh
	db 00h
	db 05h
	db 41h
	db 00h
	db 50h
	db 0E8h
	db 0B7h
	db 2Dh
	db 0B8h
	db 48h
	db 95h
	db 50h
	db 0E8h
	db 46h
	db 2Fh
	db 0A0h
	db 96h
	db 58h
	db 2Ah
	db 0E4h
	db 25h
	db 0F0h
	db 00h
	db 0B1h
	db 04h
	db 0D3h
	db 0E8h
	db 05h
	db 41h
	db 00h
	db 50h
	db 0E8h
	db 9Dh
	db 2Dh
	db 0B8h
	db 27h
	db 00h
	db 50h
	db 0E8h
	db 96h
	db 2Dh
	db 0A0h
	db 96h
	db 58h
	db 2Ah
	db 0E4h
	db 25h
	db 0Fh
	db 00h
	db 05h
	db 41h
	db 00h
	db 50h
	db 0E8h
	db 87h
	db 2Dh
	db 0B8h
	db 22h
	db 00h
	db 50h
	db 0E8h
	db 80h
	db 2Dh
	db 2Bh
	db 0C0h
	db 50h
	db 0E8h
	db 5Eh
	db 33h
	db 0B8h
	db 0Ah
	db 00h
	db 50h
	db 0E8h
	db 73h
	db 2Dh
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
	CALL       SUB_0000_6222 ; 1000:4402h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        word ptr [BP + -4h],0h	; local_6
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
	MOV        word ptr [BP + -4h],1h	; local_6
L_07ad:
	MOV        AX,word ptr [BP + -4h]	; local_6
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
	CMP        word ptr [BP + 4h],0h	; param_1
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
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,word ptr [SI + 24deh]
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,DS:[5897h]
	MOV        DI,AX
	MOV        AL,DS:[5895h]
	MOV        CL,6h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        DX,DI
	MOV        CL,3h
	SHL        DX,CL
	ADD        AX,DX
	ADD        AX,SI
	ADD        AX,595ah
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0f0h
	CMP        AL,80h
	JZ         L_0840
	MOV        AX,word ptr [BP + -0ah]	; local_c
	ADD        AX,DI
	AND        AX,7h
	SHL        AX,CL
	MOV        CX,word ptr [BP + -8h]	; local_a
	ADD        CX,SI
	AND        CX,7h
	ADD        AX,CX
	ADD        AX,word ptr [BP + -0ch]	; local_e
	ADD        AX,595ah
	MOV        word ptr [BP + -2h],AX	; local_4
L_0840:
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX]
	AND        AL,0f0h
	CMP        AL,80h
	JNZ        L_085e
	AND        byte ptr [BX],8h
	MOV        AX,954ch
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -6h],0ffffh	; local_8
	JMP        L_08de
	db 90h
L_085e:
	MOV        word ptr [BP + -6h],0h	; local_8
	JMP        L_08de
	db 90h
L_0866:
	CALL       F_0306
	OR         AX,AX
	JNZ        L_0872
	MOV        AX,0ffffh
	JMP        L_08e1
L_0872:
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_087f
	MOV        AX,4h
	PUSH       AX
	CALL       F_0000
L_087f:
	MOV        word ptr [BP + -6h],0h	; local_8
	SUB        SI,SI
	MOV        DI,5c5ah
	MOV        word ptr [BP + -10h],5c5ch	; local_12
	MOV        word ptr [BP + -12h],5c5dh	; local_14
L_0893:
	MOV        AL,byte ptr [DI]
	AND        AL,0fch
	CMP        AL,0e8h
	JNZ        L_08ca
	MOV        BX,word ptr [BP + -10h]	; local_12
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr DS:[5876h]
	JNZ        L_08ca
	MOV        BX,word ptr [BP + -12h]	; local_14
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr DS:[5878h]
	JNZ        L_08ca
	MOV        word ptr [BP + -6h],1h	; local_8
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_5894 ; 1000:3A74h
L_08c4:
	MOV        word ptr [BP + -4h],SI	; local_6
	JMP        L_08de
	db 90h
L_08ca:
	ADD        DI,8h
	ADD        word ptr [BP + -10h],8h	; local_12
	ADD        word ptr [BP + -12h],8h	; local_14
	INC        SI
	CMP        SI,20h
	JGE        L_08c4
	JMP        L_0893
	db 90h
L_08de:
	MOV        AX,word ptr [BP + -6h]	; local_8
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
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        DS:[58a6h],AL
	POP        BP
	RET        2h
	db 90h
	; Func
F_08ea ENDP
F_08f8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 8h]	; param_3
	MOV        DS:[587ah],AL
	MOV        AL,byte ptr [BP + 6h]	; param_2
	MOV        DS:[588eh],AL
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0000
	CALL       SUB_0000_4720 ; 1000:2900h
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
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 4b95h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
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
	CALL       SUB_0000_5894 ; 1000:3A74h
	INC        SI
	INC        DI
L_0953:
	CMP        DI,word ptr [BP + 4h]	; param_1
	JNZ        L_0932
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -2h],SI	; local_4
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
	MOV        word ptr [BP + -0ah],1h	; local_c
	MOV        word ptr [BP + -4h],0h	; local_6
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
	MOV        word ptr [BP + -8h],SI	; local_a
	CMP        SI,8h
	JNZ        L_09a1
	MOV        word ptr [BP + -8h],6h	; local_a
L_09a1:
	MOV        AL,6ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	CALL       SUB_0000_7730 ; 1000:5910h
	MOV        AX,0b58bh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	MOV        AX,0b5b6h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,0bd08h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_593c ; 1000:3B1Ch
	CMP        byte ptr DS:[0bd08h],0h
	JNZ        L_09d6
	JMP        L_0d1d
L_09d6:
	MOV        BX,word ptr [BP + -8h]	; local_a
	SHL        BX,1h
	PUSH       word ptr [BX + 4b3eh]
	MOV        AX,0bd08h
	PUSH       AX
	CALL       SUB_0000_8d3e ; 1000:6F1Eh
	INC        AX
	JNZ        L_09ee
	MOV        word ptr [BP + -0ah],0h	; local_c
L_09ee:
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	SUB        SI,SI
	MOV        AX,word ptr [BP + -8h]	; local_a
	SHL        AX,1h
	ADD        AX,1f5eh
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        DI,word ptr [BP + -0ah]	; local_c
L_0a0c:
	MOV        AX,958eh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,0bd08h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_593c ; 1000:3B1Ch
	CMP        byte ptr DS:[0bd08h],0h
	JNZ        L_0a3a
	MOV        word ptr [BP + -0ah],DI	; local_c
	MOV        word ptr [BP + -6h],SI	; local_8
	JMP        L_0d1d
L_0a2e:
	INC        SI
	CMP        SI,8h
	JL         L_0a37
	JMP        L_0994
L_0a37:
	JMP        L_0982
L_0a3a:
	MOV        BX,word ptr [BP + -0ch]	; local_e
	PUSH       word ptr [BX]
	MOV        AX,0bd08h
	PUSH       AX
	CALL       SUB_0000_8d3e ; 1000:6F1Eh
	INC        AX
	JNZ        L_0a4b
	SUB        DI,DI
L_0a4b:
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	INC        SI
	CMP        SI,3h
	JL         L_0a0c
	MOV        word ptr [BP + -0ah],DI	; local_c
	MOV        word ptr [BP + -6h],SI	; local_8
	OR         DI,DI
	JNZ        L_0a6c
	MOV        AX,0b5deh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	JMP        L_0d1d
L_0a6c:
	MOV        AX,1h
	MOV        CL,byte ptr [BP + -8h]	; local_a
	SHL        AX,CL
	MOV        CL,byte ptr DS:[58ceh]
	SUB        CH,CH
	TEST       CX,AX
	JZ         L_0a81
	JMP        L_0b08
L_0a81:
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -8h]	; local_a
	SHL        AL,CL
	OR         byte ptr DS:[58cch],AL
	MOV        AX,0b5ffh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AL,1ch
	MOV        DS:[5c5bh],AL
	MOV        DS:[5c5ah],AL
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,0b62ch
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        BX,word ptr [BP + -8h]	; local_a
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4b5eh]
	ADD        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,9598h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,0b669h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -6h],7h	; local_8
	MOV        DI,4be6h
	MOV        word ptr [BP + -0eh],4bf4h	; local_10
	MOV        word ptr [BP + -10h],4c02h	; local_12
	MOV        SI,4c10h
L_0adb:
	PUSH       word ptr [DI]
	MOV        AX,1h
	PUSH       AX
	MOV        BX,word ptr [BP + -0eh]	; local_10
	PUSH       word ptr [BX]
	MOV        BX,word ptr [BP + -10h]	; local_12
	PUSH       word ptr [BX]
	PUSH       word ptr [SI]
	CALL       SUB_0000_3fb2 ; 1000:2192h
	ADD        DI,2h
	ADD        word ptr [BP + -0eh],2h	; local_10
	ADD        word ptr [BP + -10h],2h	; local_12
	ADD        SI,2h
	CMP        SI,4c1eh
	JC         L_0adb
	JMP        L_0d16
	db 90h
L_0b08:
	MOV        AX,1h
	MOV        CL,byte ptr [BP + -8h]	; local_a
	SHL        AX,CL
	MOV        CL,byte ptr DS:[58cch]
	SUB        CH,CH
	TEST       CX,AX
	JZ         L_0b1d
	JMP        L_0c18
L_0b1d:
	MOV        DI,word ptr [BP + -4h]	; local_6
	MOV        SI,word ptr [BP + -2h]	; local_4
	JMP        L_0b5f
	db 90h
L_0b26:
	PUSH       SI
	CALL       SUB_0000_34da ; 1000:16BAh
	SUB        SI,30h
	JNZ        L_0b40
	MOV        AX,959ch
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -2h],SI	; local_4
	JMP        L_0d1d
	db 90h
L_0b40:
	MOV        AX,95a2h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,64h
	IMUL       SI
	CMP        AX,word ptr DS:[57aah]
	JLE        L_0b5c
	MOV        AX,0b6b9h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	JMP        L_0b5f
	db 90h
L_0b5c:
	MOV        DI,1h
L_0b5f:
	OR         DI,DI
	JNZ        L_0b7c
	MOV        AX,0b692h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_0b6a:
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        SI,AX
	CMP        AX,30h
	JC         L_0b6a
	CMP        AX,39h
	JBE        L_0b26
	JMP        L_0b6a
	db 90h
L_0b7c:
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        AX,64h
	IMUL       SI
	SUB        word ptr DS:[57aah],AX
	CALL       SUB_0000_4720 ; 1000:2900h
	MOV        AL,byte ptr [BP + -2h]	; local_4
	ADD        byte ptr DS:[5888h],AL
	CMP        byte ptr DS:[5888h],63h
	JBE        L_0ba1
	MOV        byte ptr DS:[5888h],63h
L_0ba1:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	MOV        AX,95aah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	MOV        AX,95b4h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
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
	CALL       SUB_0000_3fb2 ; 1000:2192h
	ADD        SI,32h
	CMP        SI,61a8h
	JL         L_0bd3
	MOV        word ptr [BP + -6h],SI	; local_8
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
	CALL       SUB_0000_3fb2 ; 1000:2192h
	SUB        SI,32h
	CMP        SI,7d0h
	JG         L_0bf5
	MOV        word ptr [BP + -6h],SI	; local_8
	JMP        L_0d16
	db 90h
L_0c18:
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -8h]	; local_a
	SHL        AL,CL
	AND        AL,byte ptr DS:[58cch]
	XOR        AL,0ffh
	AND        byte ptr DS:[58cch],AL
	MOV        AX,0b6d7h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
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
	CALL       SUB_0000_3fb2 ; 1000:2192h
	ADD        SI,32h
	CMP        SI,61a8h
	JL         L_0c47
	MOV        word ptr [BP + -6h],SI	; local_8
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
	CALL       SUB_0000_3fb2 ; 1000:2192h
	SUB        SI,32h
	CMP        SI,7d0h
	JG         L_0c69
	MOV        word ptr [BP + -6h],SI	; local_8
	CALL       SUB_0000_4e92 ; 1000:3072h
	ADD        byte ptr DS:[5888h],3h
	CMP        byte ptr DS:[5888h],63h
	JBE        L_0c9c
	MOV        byte ptr DS:[5888h],63h
L_0c9c:
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        byte ptr [BX + 4b7eh],0h
	JZ         L_0cbd
	INC        byte ptr DS:[55b4h]
	CMP        byte ptr DS:[55b4h],1eh
	JBE        L_0cb6
	MOV        byte ptr DS:[55b4h],1eh
L_0cb6:
	MOV        AX,95b8h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_0cbd:
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        byte ptr [BX + 4b86h],0h
	JZ         L_0cde
	INC        byte ptr DS:[55b5h]
	CMP        byte ptr DS:[55b5h],1eh
	JBE        L_0cd7
	MOV        byte ptr DS:[55b5h],1eh
L_0cd7:
	MOV        AX,95c6h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_0cde:
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        byte ptr [BX + 4b8eh],0h
	JZ         L_0cff
	INC        byte ptr DS:[55b6h]
	CMP        byte ptr DS:[55b6h],1eh
	JBE        L_0cf8
	MOV        byte ptr DS:[55b6h],1eh
L_0cf8:
	MOV        AX,95d4h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
L_0cff:
	CMP        word ptr [BP + -8h],7h	; local_a
	JNZ        L_0d16
	ADD        byte ptr DS:[5888h],3h
	CMP        byte ptr DS:[5888h],63h
	JBE        L_0d16
	MOV        byte ptr DS:[5888h],63h
L_0d16:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
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
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,0b703h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,0b733h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AL,DS:[58cch]
	SUB        AH,AH
	MOV        SI,AX
	MOV        DX,word ptr [BP + -2h]	; local_4
L_0d51:
	MOV        AX,1h
	MOV        CX,DX
	SHL        AX,CL
	TEST       SI,AX
	JZ         L_0d6e
L_0d5c:
	MOV        word ptr [BP + -2h],DX	; local_4
	CMP        DX,8h
	JNZ        L_0d76
	MOV        AX,0b75ch
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	JMP        L_0e5e
L_0d6e:
	INC        DX
	CMP        DX,8h
	JGE        L_0d5c
	JMP        L_0d51
L_0d76:
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -2h]	; local_4
	SHL        AL,CL
	OR         byte ptr DS:[58ceh],AL
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	MOV        AX,word ptr [BX + 4b6eh]
	ADD        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,95e6h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_448c ; 1000:266Ch
	CMP        byte ptr DS:[58ceh],0ffh
	JZ         L_0dac
	JMP        L_0e5e
L_0dac:
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_2890 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	CALL       SUB_0000_4e92 ; 1000:3072h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	CALL       SUB_0000_4e92 ; 1000:3072h
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_2890 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_29a6 ; 1000:0B86h
	CALL       SUB_0000_4e92 ; 1000:3072h
	MOV        AX,0b773h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,95eah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	MOV        AX,0b79dh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	MOV        AX,0b7efh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	MOV        AX,0b82ah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	MOV        AX,0b89eh
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe ; 1000:1C9Eh
	CALL       SUB_0000_448c ; 1000:266Ch
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
	CALL       SUB_0000_5906 ; 1000:3AE6h
	CALL       SUB_0000_615e ; 1000:433Eh
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	RET
	; Func
F_0e64 ENDP
F_0e76 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_6222 ; 1000:4402h
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        byte ptr DS:[24e6h],1h
	MOV        AL,DS:[5893h]
	MOV        DS:[0bd15h],AL
	MOV        byte ptr DS:[5893h],0ffh
	MOV        byte ptr DS:[589eh],0ffh
	MOV        word ptr [BP + -8h],20h	; local_a
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
	CMP        word ptr [BP + -4h],11h	; local_6
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
	CALL       SUB_0000_438e ; 1000:256Eh
	MOV        AX,9618h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,3abh
	PUSH       AX
	CALL       SUB_0000_438e ; 1000:256Eh
	MOV        word ptr [BP + -8h],0bh	; local_a
	SUB        DI,DI
	SUB        SI,SI
L_0f15:
	MOV        word ptr [BP + -0ah],0h	; local_c
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
	MOV        word ptr [BP + -0ah],0bh	; local_c
	ADD        DI,10h
	ADD        SI,20h
	CMP        SI,160h
	JL         L_0f15
	CALL       SUB_0000_7730 ; 1000:5910h
	MOV        word ptr [BP + -8h],10h	; local_a
	MOV        SI,55e7h
	MOV        CX,word ptr [BP + -6h]	; local_8
L_0f4f:
	CMP        byte ptr [SI],7fh
	JNZ        L_0f55
	INC        CX
L_0f55:
	ADD        SI,20h
	CMP        SI,57c7h
	JC         L_0f4f
	MOV        word ptr [BP + -6h],CX	; local_8
	OR         CX,CX
	JLE        L_0f69
	PUSH       CX
	CALL       F_0914
L_0f69:
	CMP        word ptr [BP + -4h],11h	; local_6
	JZ         L_0f74
	MOV        AX,0b8cch
	JMP        L_0f77
L_0f74:
	MOV        AX,0b8f9h
L_0f77:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -8h],4h	; local_a
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
	CMP        word ptr [BP + -4h],11h	; local_6
	JZ         L_0fad
	JMP        L_103c
L_0fad:
	CMP        word ptr [BP + -6h],0h	; local_8
	JG         L_0fb6
	JMP        L_103c
L_0fb6:
	MOV        AX,9624h
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	CMP        word ptr [BP + -6h],1h	; local_8
	JNZ        L_0fc8
	MOV        AX,9636h
	JMP        L_0fcb
L_0fc8:
	MOV        AX,9648h
L_0fcb:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        word ptr [BP + -8h],10h	; local_a
	MOV        word ptr [BP + -0ch],55e7h	; local_e
	MOV        word ptr [BP + -12h],55c8h	; local_14
	MOV        word ptr [BP + -14h],20h	; local_16
	MOV        SI,word ptr [BP + -0ah]	; local_c
L_0fe6:
	MOV        BX,word ptr [BP + -0ch]	; local_e
	CMP        byte ptr [BX],7fh
	JNZ        L_1026
	SUB        SI,SI
	MOV        BX,word ptr [BP + -12h]	; local_14
	CMP        byte ptr [BX],0h
	JZ         L_101f
	MOV        DI,word ptr [BP + -14h]	; local_16
	MOV        word ptr [BP + -0eh],DI	; local_10
L_0ffe:
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        AX,SI
	INC        SI
	ADD        BX,AX
	MOV        AL,byte ptr [BX + 55a8h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_3e52 ; 1000:2032h
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
	MOV        BX,DI
	ADD        BX,SI
	CMP        byte ptr [BX + 55a8h],0h
	JNZ        L_0ffe
L_101f:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da ; 1000:16BAh
L_1026:
	ADD        word ptr [BP + -0ch],20h	; local_e
	ADD        word ptr [BP + -12h],20h	; local_14
	ADD        word ptr [BP + -14h],20h	; local_16
	CMP        word ptr [BP + -14h],200h	; local_16
	JL         L_0fe6
	MOV        word ptr [BP + -0ah],SI	; local_c
L_103c:
	CMP        word ptr [BP + -4h],11h	; local_6
	JZ         L_1048
	MOV        AX,4h
	JMP        L_104b
	db 90h
L_1048:
	MOV        AX,7h
L_104b:
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        word ptr [BP + -8h],0h	; local_a
	OR         AX,AX
	JLE        L_1066
	MOV        SI,AX
	ADD        word ptr [BP + -8h],AX	; local_a
L_105c:
	DEC        byte ptr DS:[5c5dh]
	CALL       F_0e64
	DEC        SI
	JNZ        L_105c
L_1066:
	CMP        word ptr [BP + -4h],11h	; local_6
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
	CALL       SUB_0000_5906 ; 1000:3AE6h
	MOV        AL,DS:[5c5dh]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,0ah
	JGE        L_10a6
	MOV        AX,0ah
	SUB        AX,word ptr [BP + -8h]	; local_a
	MOV        SI,AX
	ADD        word ptr [BP + -8h],SI	; local_a
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
	MOV        word ptr [BP + -8h],4h	; local_a
	MOV        SI,4h
L_10b9:
	CALL       F_0e64
	DEC        SI
	JNZ        L_10b9
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_5906 ; 1000:3AE6h
	MOV        word ptr [BP + -8h],20h	; local_a
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
	CALL       SUB_0000_6d9c ; 1000:4F7Ch
	CALL       SUB_0000_7c6a ; 1000:5E4Ah
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
	CALL       SUB_0000_3670 ; 1000:1850h
L_110b:
	CALL       SUB_0000_448c ; 1000:266Ch
	MOV        byte ptr [BP + -2h],AL	; local_4
	CMP        AL,59h
	JZ         L_1119
	CMP        AL,4eh
	JNZ        L_110b
L_1119:
	CMP        byte ptr [BP + -2h],4eh	; local_4
	JNZ        L_1126
	MOV        AX,9666h
	JMP        L_11b2
	db 90h
L_1126:
	MOV        AX,966ah
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
	MOV        AL,DS:[0a9bdh]
	MOV        byte ptr [BP + -4h],AL	; local_6
	CMP        AL,5h
	JZ         L_113e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_433e ; 1000:251Eh
L_113e:
	MOV        AX,967ah
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e ; 1000:256Eh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_433e ; 1000:251Eh
	MOV        AX,9684h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e ; 1000:256Eh
	CMP        byte ptr [BP + -4h],1h	; local_6
	JZ         L_117e
	MOV        AX,968eh
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_43f8 ; 1000:25D8h
L_117e:
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_433e ; 1000:251Eh
	MOV        AX,9698h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	CALL       SUB_0000_43f8 ; 1000:25D8h
	MOV        AX,96a2h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	CALL       SUB_0000_43f8 ; 1000:25D8h
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_433e ; 1000:251Eh
	MOV        AX,96ach
L_11b2:
	PUSH       AX
	CALL       SUB_0000_3670 ; 1000:1850h
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
