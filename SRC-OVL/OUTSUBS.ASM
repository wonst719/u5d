_TEXT SEGMENT BYTE 'CODE'
ORG 828eh
SUB_0000_828e:
ORG 82deh
SUB_0000_82de:
ORG 0a172h
SUB_0000_a172:
ORG 6172h
SUB_0000_6172:
ORG 75c0h
SUB_0000_75c0:
ORG 742ah
SUB_0000_742a:
ORG 73e4h
SUB_0000_73e4:
ORG 8348h
SUB_0000_8348:
ORG 0d936h
SUB_0000_d936:
ORG 9856h
SUB_0000_9856:
ORG 0a11eh
SUB_0000_a11e:
ORG 982eh
SUB_0000_982e:
ORG 87c2h
SUB_0000_87c2:
ORG 0d8eeh
SUB_0000_d8ee:
ORG 7e02h
SUB_0000_7e02:
ORG 7f02h
SUB_0000_7f02:
ORG 6dd8h
SUB_0000_6dd8:
ORG 77aeh
SUB_0000_77ae:
ORG 9c60h
SUB_0000_9c60:
ORG 83dch
SUB_0000_83dc:
ORG 8670h
SUB_0000_8670:
ORG 0aae6h
SUB_0000_aae6:
ORG 67e0h
SUB_0000_67e0:
ORG 68f6h
SUB_0000_68f6:
ORG 0acech
SUB_0000_acec:
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
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        AL,byte ptr [BP + 4h+1h]	; param_1
	SUB        AH,AH
	MOV        word ptr [BP + 4h],AX	; param_1
	SUB        SI,SI
	MOV        DX,AX
	MOV        CX,word ptr [BP + -4h]	; local_6
L_001b:
	MOV        AL,byte ptr [SI + 3866h]
	SUB        AH,AH
	CMP        AX,DX
	JNZ        L_0038
	CMP        byte ptr [SI + 58d0h],1h
	SBB        AX,AX
	NEG        AX
	MOV        CX,AX
L_0030:
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        word ptr [BP + -4h],CX	; local_6
	JMP        L_0040
L_0038:
	INC        SI
	CMP        SI,8h
	JGE        L_0030
	JMP        L_001b
L_0040:
	MOV        AX,word ptr [BP + -4h]	; local_6
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0000 ENDP
F_004a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -4h],0h	; local_6
	MOV        CL,8h
	SAR        word ptr [BP + 4h],CL	; param_1
	SUB        SI,SI
	MOV        DX,word ptr [BP + 4h]	; param_1
	MOV        CX,word ptr [BP + -4h]	; local_6
L_0063:
	MOV        AL,byte ptr [SI + 386eh]
	SUB        AH,AH
	CMP        AX,DX
	JNZ        L_0086
	CMP        byte ptr [SI + 58d8h],7fh
	JBE        L_007a
	MOV        AX,1h
	JMP        L_007c
	db 90h
L_007a:
	SUB        AX,AX
L_007c:
	MOV        CX,AX
L_007e:
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        word ptr [BP + -4h],CX	; local_6
	JMP        L_008e
L_0086:
	INC        SI
	CMP        SI,8h
	JGE        L_007e
	JMP        L_0063
L_008e:
	MOV        AX,word ptr [BP + -4h]	; local_6
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_004a ENDP
F_0098 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        BX,word ptr [BP + 8h]	; param_3
	CMP        byte ptr [BX],42h
	JNZ        L_00dc
	MOV        BL,byte ptr [BP + 4h+1h]	; param_1
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 3876h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,0ffh
	JNZ        L_00d4
	MOV        BH,byte ptr [BP + 6h]	; param_2
	SUB        BL,BL
	MOV        CX,100h
	LEA        DI,[BX + 6608h]
	MOV        AX,DS
	MOV        ES,AX
	MOV        AX,1h
	REP STOSB
	JMP        L_01ac
	db 90h
L_00d4:
	MOV        CL,8h
	SHL        word ptr [BP + -2h],CL	; local_4
	JMP        L_00e2
	db 90h
L_00dc:
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        word ptr [BP + -2h],AX	; local_4
L_00e2:
	CMP        byte ptr DS:[5895h],0h
	JZ         L_00f0
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_828e ; 1000:251Eh
L_00f0:
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AH,byte ptr [BP + 6h]	; param_2
	SUB        AL,AL
	ADD        AX,6608h
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_82de ; 1000:256Eh
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,4h
	SAR        AX,CL
	AND        AX,0f0h
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,8h
	SAR        AX,CL
	AND        AX,0f0h
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        word ptr [BP + -0ah],0h	; local_c
L_0125:
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_014f
L_012c:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0000
	OR         AX,AX
	JZ         L_014c
	MOV        AX,word ptr [BP + -8h]	; local_a
	ADD        AX,word ptr [BP + -4h]	; local_6
	PUSH       AX
	MOV        AX,word ptr [BP + -0ah]	; local_c
	ADD        AX,word ptr [BP + -6h]	; local_8
	PUSH       AX
	CALL       SUB_0000_a172 ; 1000:4402h
	MOV        BX,AX
	MOV        byte ptr [BX],0dfh
L_014c:
	INC        word ptr [BP + -8h]	; local_a
L_014f:
	CMP        word ptr [BP + -8h],10h	; local_a
	JGE        L_01a0
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,8h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -0ah]	; local_c
	MOV        CL,4h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX + SI + 6608h]
	SUB        AH,AH
	CMP        AX,16h
	JC         L_014c
	CMP        AX,18h
	JBE        L_012c
	CMP        AX,19h
	JNZ        L_014c
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_004a
	OR         AX,AX
	JZ         L_014c
	MOV        AX,word ptr [BP + -8h]	; local_a
	ADD        AX,word ptr [BP + -4h]	; local_6
	PUSH       AX
	MOV        AX,word ptr [BP + -0ah]	; local_c
	ADD        AX,word ptr [BP + -6h]	; local_8
	PUSH       AX
	CALL       SUB_0000_a172 ; 1000:4402h
	MOV        BX,AX
	MOV        byte ptr [BX],1ah
	JMP        L_014c
	db 90h
L_01a0:
	INC        word ptr [BP + -0ah]	; local_c
	CMP        word ptr [BP + -0ah],10h	; local_c
	JGE        L_01ac
	JMP        L_0125
L_01ac:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0098 ENDP
F_01b4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	MOV        AL,DS:[589bh]
	SUB        AH,AH
	MOV        CL,4h
	SHL        AX,CL
	MOV        CH,byte ptr DS:[589ch]
	SUB        CL,CL
	ADD        AX,CX
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        byte ptr DS:[589bh],0f0h
	JNZ        L_01dc
	MOV        word ptr [BP + -4h],0f100h	; local_6
	JMP        L_01e1
L_01dc:
	MOV        word ptr [BP + -4h],100h	; local_6
L_01e1:
	CMP        byte ptr DS:[5895h],7fh
	JBE        L_01f0
	MOV        word ptr [BP + -2h],3976h	; local_4
	JMP        L_01f5
	db 90h
L_01f0:
	MOV        word ptr [BP + -2h],3980h	; local_4
L_01f5:
	CMP        word ptr [BP + 6h],-1h	; param_2
	JZ         L_0201
	CMP        word ptr [BP + 4h],-1h	; param_1
	JNZ        L_020d
L_0201:
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       F_0098
L_020d:
	CMP        word ptr [BP + 6h],1h	; param_2
	JZ         L_0219
	CMP        word ptr [BP + 4h],-1h	; param_1
	JNZ        L_022a
L_0219:
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,1h
	PUSH       AX
	MOV        AX,word ptr [BP + -8h]	; local_a
	ADD        AX,word ptr [BP + -4h]	; local_6
	PUSH       AX
	CALL       F_0098
L_022a:
	CMP        word ptr [BP + 6h],-1h	; param_2
	JZ         L_0236
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_0247
L_0236:
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,2h
	PUSH       AX
	MOV        AX,word ptr [BP + -8h]	; local_a
	ADD        AH,10h
	PUSH       AX
	CALL       F_0098
L_0247:
	CMP        word ptr [BP + 6h],1h	; param_2
	JZ         L_0253
	CMP        word ptr [BP + 4h],1h	; param_1
	JNZ        L_0267
L_0253:
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,3h
	PUSH       AX
	MOV        AX,word ptr [BP + -8h]	; local_a
	ADD        AX,word ptr [BP + -4h]	; local_6
	ADD        AH,10h
	PUSH       AX
	CALL       F_0098
L_0267:
	MOV        AX,400h
	PUSH       AX
	MOV        AX,1bh
	PUSH       AX
	MOV        AX,6608h
	PUSH       AX
	CALL       SUB_0000_6172 ; 1000:0402h
	ADD        SP,6h
	MOV        word ptr [BP + -6h],AX	; local_8
	OR         AX,AX
	JNZ        L_028c
	MOV        AX,0ffffh
	MOV        DS:[2180h],AX
	MOV        DS:[217eh],AX
	JMP        L_02c2
	db 90h
L_028c:
	MOV        AX,word ptr [BP + -6h]	; local_8
	SUB        AX,6608h
	MOV        word ptr [BP + -0ah],AX	; local_c
	AND        AX,0fh
	MOV        DS:[217eh],AX
	MOV        AL,byte ptr [BP + -0ah]	; local_c
	SUB        AH,AH
	AND        AX,0f0h
	MOV        CL,4h
	SHR        AX,CL
	MOV        DS:[2180h],AX
	TEST       word ptr [BP + -0ah],100h	; local_c
	JZ         L_02b6
	ADD        word ptr DS:[217eh],10h
L_02b6:
	TEST       word ptr [BP + -0ah],200h	; local_c
	JZ         L_02c2
	ADD        word ptr DS:[2180h],10h
L_02c2:
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_01b4 ENDP
F_02c8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	CMP        word ptr [BP + 6h],0h	; param_2
	JL         L_02dc
	CMP        word ptr [BP + 4h],0h	; param_1
	JGE        L_02e2
L_02dc:
	MOV        AX,3h
	JMP        L_02e4
	db 90h
L_02e2:
	SUB        AX,AX
L_02e4:
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        word ptr [BP + 6h],0h	; param_2
	JL         L_02f3
	CMP        word ptr [BP + 4h],0h	; param_1
	JLE        L_02f8
L_02f3:
	MOV        AX,2h
	JMP        L_02fb
L_02f8:
	MOV        AX,1h
L_02fb:
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        SI,word ptr [BP + 6h]	; param_2
	SHL        SI,1h
	MOV        AX,word ptr [BP + -2h]	; local_4
	ADD        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,SI
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + -6h]	; local_8
	ADD        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,SI
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AH,byte ptr [BP + -6h]	; local_8
	SUB        AL,AL
	ADD        AX,6608h
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        BH,byte ptr [BP + -2h]	; local_4
	SUB        BL,BL
	MOV        CX,100h
	PUSH       SI
	LEA        DI,[BX + 6608h]
	MOV        SI,AX
	PUSH       DS
	POP        ES
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
	POP        SI
	MOV        AH,byte ptr [BP + -8h]	; local_a
	SUB        AL,AL
	ADD        AX,6608h
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        BH,byte ptr [BP + -4h]	; local_6
	MOV        CX,100h
	PUSH       SI
	LEA        DI,[BX + 6608h]
	MOV        SI,AX
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
	POP        SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_02c8 ENDP
F_0368 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        byte ptr DS:[5895h],0h
	JNZ        L_037c
	MOV        word ptr [BP + -2h],3989h	; local_4
	JMP        L_0381
L_037c:
	MOV        word ptr [BP + -2h],3992h	; local_4
L_0381:
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0368 ENDP
F_0388 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        word ptr [BP + -2h],1h	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_75c0 ; 1000:1850h
	SUB        SI,SI
	MOV        DL,byte ptr DS:[5896h]
	MOV        CL,byte ptr DS:[5897h]
L_03a4:
	CMP        byte ptr [SI + 1e8ah],DL
	JZ         L_03ad
	JMP        L_043a
L_03ad:
	CMP        byte ptr [SI + 1eb2h],CL
	JZ         L_03b6
	JMP        L_043a
L_03b6:
	MOV        word ptr [BP + -4h],SI	; local_6
	CMP        SI,20h
	JL         L_03c1
	JMP        L_0446
L_03c1:
	CMP        SI,0dh
	JL         L_03cb
	CMP        SI,11h
	JLE        L_03ec
L_03cb:
	MOV        AX,399ch
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	MOV        BX,word ptr [BP + -4h]	; local_6
	SHL        BX,1h
	PUSH       word ptr [BX + 1e3ah]
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
L_03ec:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	CMP        byte ptr DS:[0a9bdh],1h
	JZ         L_040c
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_828e ; 1000:251Eh
L_0401:
	MOV        AX,399fh
	PUSH       AX
	CALL       SUB_0000_73e4 ; 1000:1674h
	OR         AX,AX
	JZ         L_0401
L_040c:
	CALL       F_0368
	PUSH       AX
	MOV        AX,5c5ah
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_8348 ; 1000:25D8h
	MOV        AL,byte ptr [BP + -4h]	; local_6
	INC        AL
	MOV        DS:[5893h],AL
	MOV        byte ptr DS:[5895h],0h
	MOV        byte ptr DS:[5896h],0fh
	MOV        byte ptr DS:[5897h],1eh
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_044d
	db 90h
L_043a:
	INC        SI
	CMP        SI,20h
	JL         L_0443
	JMP        L_03b6
L_0443:
	JMP        L_03a4
L_0446:
	MOV        AX,39a8h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_044d:
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0388 ENDP
F_0458 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        AX,39b5h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_d936 ; 1000:7BC6h [THUNK]
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_d936 ; 1000:7BC6h [THUNK]
	MOV        AX,9c4h
	PUSH       AX
	MOV        AX,320h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	CALL       SUB_0000_a11e ; 1000:43AEh
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        byte ptr DS:[587ch],AH
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_04f3
	MOV        DI,55b3h
	MOV        word ptr [BP + -8h],55b5h	; local_a
	MOV        SI,word ptr [BP + -2h]	; local_4
L_04c1:
	CMP        byte ptr [DI],44h
	JZ         L_04dc
	CALL       SUB_0000_982e ; 1000:3ABEh
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        CL,byte ptr [BX]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_04dc
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_87c2 ; 1000:2A52h
L_04dc:
	ADD        DI,20h
	ADD        word ptr [BP + -8h],20h	; local_a
	INC        SI
	MOV        AX,SI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_04c1
	MOV        word ptr [BP + -2h],SI	; local_4
L_04f3:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        AL,byte ptr [BP + -4h]	; local_6
	MOV        DS:[587ch],AL
	CMP        byte ptr DS:[5896h],36h
	JNZ        L_055f
	CMP        byte ptr DS:[5897h],8ah
	JNZ        L_055f
	MOV        AX,39c3h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        byte ptr DS:[5895h],0ffh
	MOV        AX,39deh
	PUSH       AX
	MOV        AX,5c5ah
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_8348 ; 1000:25D8h
	MOV        AX,39e7h
	PUSH       AX
	MOV        AX,5c5ah
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_82de ; 1000:256Eh
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_828e ; 1000:251Eh
L_0542:
	MOV        AX,39f1h
	PUSH       AX
	CALL       SUB_0000_73e4 ; 1000:1674h
	OR         AX,AX
	JZ         L_0542
	MOV        AX,39fbh
	PUSH       AX
	MOV        AX,5c5ah
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_8348 ; 1000:25D8h
	CALL       SUB_0000_d8ee ; 1000:7B7Eh [THUNK]
L_055f:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0458 ENDP
F_0566 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5895h],0h
	JZ         L_05e8
	CMP        byte ptr DS:[57b3h],0h
	JNZ        L_059d
	MOV        word ptr [BP + -2h],5d3ah	; local_4
	MOV        AL,0b7h
	MOV        DS:[5d3bh],AL
	MOV        DS:[5d3ah],AL
	MOV        byte ptr DS:[5d3ch],69h
	MOV        byte ptr DS:[5d3dh],0e1h
	MOV        byte ptr DS:[5d3eh],0ffh
	MOV        byte ptr DS:[5d3fh],0f3h
L_059d:
	SUB        SI,SI
	MOV        word ptr [BP + -6h],5d42h	; local_8
	MOV        DI,word ptr [BP + -2h]	; local_4
L_05a7:
	CMP        byte ptr [SI + 57b6h],0h
	JNZ        L_05d8
	CMP        byte ptr [SI + 58c8h],80h
	JNC        L_05d8
	MOV        DI,word ptr [BP + -6h]	; local_8
	MOV        AL,0b4h
	MOV        byte ptr [DI + 1h],AL
	MOV        byte ptr [DI],AL
	MOV        AL,byte ptr [SI + 3a06h]
	MOV        byte ptr [DI + 2h],AL
	MOV        AL,byte ptr [SI + 3a0ah]
	MOV        byte ptr [DI + 3h],AL
	MOV        byte ptr [DI + 4h],0ffh
	MOV        AL,byte ptr [SI + 3a0eh]
	MOV        byte ptr [DI + 5h],AL
L_05d8:
	ADD        word ptr [BP + -6h],8h	; local_8
	INC        SI
	CMP        SI,3h
	JL         L_05a7
	MOV        word ptr [BP + -2h],DI	; local_4
	MOV        word ptr [BP + -4h],SI	; local_6
L_05e8:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 0E8h
	db 8Fh
	db 0B0h
	db 0B8h
	db 11h
	db 3Ah
	db 50h
	db 0E8h
	db 0C8h
	db 6Fh
	db 0E8h
	db 1Dh
	db 82h
	db 0C3h
	; Func
F_0566 ENDP
F_05fc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0652
	MOV        SI,55b3h
	MOV        DI,55b5h
L_0618:
	CMP        byte ptr [SI],44h
	JZ         L_063f
	CMP        byte ptr [SI],50h
	JZ         L_063f
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	MOV        CL,byte ptr [DI]
	SUB        CH,CH
	CMP        CX,AX
	JNC        L_063f
	MOV        byte ptr [SI],50h
	MOV        AX,3a1bh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_063f:
	ADD        SI,20h
	ADD        DI,20h
	INC        word ptr [BP + -2h]	; local_4
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -2h],AX	; local_4
	JC         L_0618
L_0652:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_05fc ENDP
F_0658 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        AX,7750h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,0a3ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,2710h
	PUSH       AX
	MOV        AX,9c4h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_7f02 ; 1000:2192h
	MOV        word ptr [BP + -6h],6h	; local_8
	MOV        SI,3a26h
L_0686:
	PUSH       word ptr [SI]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1388h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_7f02 ; 1000:2192h
	ADD        SI,2h
	CMP        SI,3a32h
	JC         L_0686
	MOV        word ptr [BP + -2h],5caah	; local_4
	MOV        AL,5h
	MOV        DS:[5cadh],AL
	MOV        DS:[5cach],AL
	MOV        AL,16h
	MOV        DS:[5cabh],AL
	MOV        DS:[5caah],AL
	MOV        AX,174h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6dd8 ; 1000:1068h
	MOV        AL,74h
	MOV        DS:[5cabh],AL
	MOV        DS:[5caah],AL
	MOV        word ptr [BP + -6h],0h	; local_8
	JMP        L_07fb
	db 90h
L_06d6:
	ADD        DI,8h
	ADD        SI,8h
	INC        DX
	CMP        SI,0bb18h
	JC         L_06e6
	JMP        L_084d
L_06e6:
	JMP        L_0835
	db 90h
L_06ea:
	INC        DX
	SAR        CX,1h
L_06ed:
	OR         CX,CX
	JG         L_06ea
	MOV        word ptr [BP + -0ch],DX	; local_e
	MOV        word ptr [BP + -8h],CX	; local_a
	MOV        SI,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 55beh]
	SUB        AH,AH
	CMP        AX,DX
	JNZ        L_070b
	JMP        L_079c
L_070b:
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	MOV        byte ptr [SI + 55beh],AL
	MOV        AX,1eh
	IMUL       DX
	MOV        word ptr [SI + 55bah],AX
	MOV        word ptr [SI + 55b8h],AX
	MOV        AX,776ah
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,SI
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,7774h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,77a4h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	PUSH       word ptr [BP + -0ch]	; local_e
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_77ae ; 1000:1A3Eh
	MOV        AX,77b8h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	CMP        AX,1h
	JZ         L_076e
	CMP        AX,2h
	JZ         L_07be
	CMP        AX,3h
	JZ         L_07d2
	JMP        L_078b
L_076e:
	MOV        AX,77c0h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55b4h
L_077f:
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_9c60 ; 1000:3EF0h
L_078b:
	MOV        AX,77dch
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
L_079c:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b2h]
	SUB        AH,AH
	CMP        AX,41h
	JZ         L_07e6
	CMP        AX,42h
	JNZ        L_07b6
	JMP        L_08fc
L_07b6:
	CMP        AX,4dh
	JZ         L_07e6
	JMP        L_07f5
	db 90h
L_07be:
	MOV        AX,77cah
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55b5h
	JMP        L_077f
	db 90h
L_07d2:
	MOV        AX,77d4h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55b6h
	JMP        L_077f
	db 90h
L_07e6:
	MOV        SI,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 55b6h]
L_07f1:
	MOV        byte ptr [SI + 55b7h],AL
L_07f5:
	CALL       SUB_0000_8670 ; 1000:2900h
	INC        word ptr [BP + -6h]	; local_8
L_07fb:
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -6h],AX	; local_8
	JC         L_0808
	JMP        L_090e
L_0808:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JZ         L_079c
	MOV        AX,word ptr [BP + -6h]	; local_8
	SHL        AX,CL
	MOV        word ptr [BP + -12h],AX	; local_14
	MOV        BX,AX
	MOV        AX,word ptr [BX + 55bah]
	MOV        word ptr [BX + 55b8h],AX
	MOV        byte ptr [BX + 55b3h],47h
	SUB        DX,DX
	MOV        DI,0ba17h
	MOV        SI,0ba18h
L_0835:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -6h]	; local_8
	JZ         L_0841
	JMP        L_06d6
L_0841:
	MOV        AL,byte ptr [SI]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX	; local_4
L_084d:
	MOV        word ptr [BP + -8h],DX	; local_a
	MOV        AX,7760h
	PUSH       AX
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b2h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_aae6 ; 1000:4D76h
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        DI,AX
	MOV        AL,byte ptr [DI + 1adeh]
	MOV        byte ptr [BX + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr DS:[5cb0h],0h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        AX,157ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1388h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_7f02 ; 1000:2192h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_68f6 ; 1000:0B86h
	MOV        AX,157ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0ea60h
	PUSH       AX
	MOV        AX,9c4h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7f02 ; 1000:2192h
	MOV        word ptr [BP + -8h],3h	; local_a
	MOV        SI,3h
L_08cc:
	MOV        byte ptr DS:[5cb0h],1h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	DEC        SI
	JNZ        L_08cc
	MOV        word ptr [BP + -0ch],1h	; local_e
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        BX,CL
	MOV        AX,word ptr [BX + 55bch]
	CWD
	MOV        CX,64h
	IDIV       CX
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        DX,word ptr [BP + -0ch]	; local_e
	MOV        CX,AX
	JMP        L_06ed
L_08fc:
	MOV        SI,word ptr [BP + -6h]	; local_8
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 55b6h]
	SUB        AH,AH
	SHR        AX,1h
	JMP        L_07f1
L_090e:
	MOV        AX,77e0h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AL,DS:[5888h]
	SUB        AH,AH
	MOV        CL,14h
	DIV        CL
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,4h
	JGE        L_0940
	MOV        AX,77e4h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        BX,word ptr [BP + -0ah]	; local_c
	SHL        BX,1h
	PUSH       word ptr [BX + 1a74h]
	JMP        L_0950
	db 90h
L_0940:
	MOV        AX,77eeh
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,29fh
	PUSH       AX
L_0950:
	CALL       SUB_0000_82de ; 1000:256Eh
	MOV        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,77f8h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AL,16h
	MOV        DS:[5cabh],AL
	MOV        DS:[5caah],AL
	MOV        AL,DS:[0adb9h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6dd8 ; 1000:1068h
	SUB        AL,AL
	MOV        DS:[5cabh],AL
	MOV        DS:[5caah],AL
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_acec ; 1000:4F7Ch
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 00h
	db 00h
	db 00h
	db 00h
F_0658 ENDP
_TEXT ENDS
END
