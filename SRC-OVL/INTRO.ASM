_TEXT SEGMENT BYTE 'CODE'
ORG 8a62h
SUB_0000_8a62:
ORG 94fah
SUB_0000_94fa:
ORG 8b8ch
SUB_0000_8b8c:
ORG 88b0h
SUB_0000_88b0:
ORG 8aa4h
SUB_0000_8aa4:
ORG 9b9eh
SUB_0000_9b9e:
ORG 9f3ah
SUB_0000_9f3a:
ORG 8e6eh
SUB_0000_8e6e:
ORG 8deeh
SUB_0000_8dee:
ORG 0fb26h
SUB_0000_fb26:
ORG 9a32h
SUB_0000_9a32:
ORG 89eeh
SUB_0000_89ee:
ORG 0a3aeh
SUB_0000_a3ae:
ORG 9956h
SUB_0000_9956:
ORG 8daeh
SUB_0000_8dae:
ORG 8d86h
SUB_0000_8d86:
ORG 8a24h
SUB_0000_8a24:
ORG 8e1ch
SUB_0000_8e1c:
ORG 0a35eh
SUB_0000_a35e:
ORG 9fach
SUB_0000_9fac:
ORG 88e6h
SUB_0000_88e6:
ORG 8950h
SUB_0000_8950:
ORG 0ca6ah
SUB_0000_ca6a:
ORG 9690h
SUB_0000_9690:
ORG 0cb0eh
SUB_0000_cb0e:
ORG 9b0ah
SUB_0000_9b0a:
ORG 9b2eh
SUB_0000_9b2e:
ORG 8dd0h
SUB_0000_8dd0:
ORG 890eh
SUB_0000_890e:
ORG 8c20h
SUB_0000_8c20:
ORG 8f98h
SUB_0000_8f98:
ORG 8cd4h
SUB_0000_8cd4:
ORG 86d2h
SUB_0000_86d2:
ORG 8d6ah
SUB_0000_8d6a:
ORG 86b8h
SUB_0000_86b8:
ORG 8134h
SUB_0000_8134:
ORG 9b42h
SUB_0000_9b42:
ORG 9adeh
SUB_0000_9ade:
ORG 9a62h
SUB_0000_9a62:
ORG 99d4h
SUB_0000_99d4:
ORG 9e72h
SUB_0000_9e72:
ORG 8e34h
SUB_0000_8e34:
ORG 8bb2h
SUB_0000_8bb2:
ORG 8e84h
SUB_0000_8e84:
ORG 0fb1ah
SUB_0000_fb1a:
ORG 9e96h
SUB_0000_9e96:
ORG 9ebeh
SUB_0000_9ebe:
ORG 9978h
SUB_0000_9978:
ORG 0e1beh
SUB_0000_e1be:
ORG 0acd6h
SUB_0000_acd6:
ORG 9c1ah
SUB_0000_9c1a:
ORG 0a418h
SUB_0000_a418:
ORG 94b4h
SUB_0000_94b4:
ORG 0fb0eh
SUB_0000_fb0e:
ORG 94e6h
SUB_0000_94e6:
ORG 9cech
SUB_0000_9cec:
ORG 987eh
SUB_0000_987e:
ORG 9c78h
SUB_0000_9c78:
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
	db 0D9h
	db 95h
	db 00h
	db 00h
	db 0A3h
	db 95h
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
	; Func
F_0010 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        SI,SI
	SUB        DI,DI
L_002a:
	PUSH       word ptr DS:[0bb1ah]
	LEA        AX,[SI + 1h]
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	ADD        DI,32h
	INC        SI
	CMP        SI,4h
	JL         L_002a
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0010 ENDP
F_0050 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],55a6h	; local_6
	MOV        AX,DS:[13b0h]
	MOV        word ptr [BP + -0ch],AX	; local_e
	PUSH       AX
	CALL       SUB_0000_88b0 ; 1000:0A70h
	MOV        AX,DS:[5356h]
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        word ptr DS:[5356h],113h
	MOV        AX,DS:[0bb18h]
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AX,6606h
	SUB        AX,55a6h
	CMP        word ptr [BP + -6h],AX	; local_8
	JL         L_0087
	JMP        L_0136
L_0087:
	MOV        AX,6606h
	SUB        AX,55a6h
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        SI,word ptr [BP + -6h]	; local_8
L_0093:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JZ         L_00a2
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_8aa4 ; 1000:0C64h
L_00a2:
	MOV        AX,DS:[13b0h]
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + SI]
	SUB        AH,AH
	AND        AX,7h
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,2h
	JLE        L_00bf
	MOV        word ptr [BP + -0ch],0h	; local_e
L_00bf:
	TEST       byte ptr [BX + SI],8h
	JZ         L_00cc
	MOV        AX,word ptr [BP + -0ah]	; local_c
	NEG        AX
	MOV        word ptr [BP + -0ah],AX	; local_c
L_00cc:
	MOV        AL,byte ptr [BX + SI]
	SUB        AH,AH
	MOV        CL,4h
	SHR        AX,CL
	AND        AX,7h
	MOV        DI,AX
	CMP        DI,2h
	JLE        L_00e3
	MOV        word ptr [BP + -0ch],0h	; local_e
L_00e3:
	TEST       byte ptr [BX + SI],80h
	JZ         L_00ee
	MOV        AX,DI
	NEG        AX
	MOV        DI,AX
L_00ee:
	ADD        word ptr [BP + 6h],DI	; param_2
	MOV        AX,word ptr [BP + -0ah]	; local_c
	ADD        word ptr [BP + 4h],AX	; param_1
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	OR         AX,AX
	JZ         L_010e
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        DS:[5356h],AX
	SUB        AX,AX
	MOV        word ptr [BP + -8h],DI	; local_a
	MOV        word ptr [BP + -6h],SI	; local_8
	JMP        L_0146
L_010e:
	MOV        AX,SI
	TEST       AL,1fh
	JNZ        L_011b
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9f3a ; 1000:20FAh
L_011b:
	MOV        BX,word ptr [BP + -4h]	; local_6
	CMP        byte ptr [BX + SI],0h
	JNZ        L_012c
L_0123:
	MOV        word ptr [BP + -8h],DI	; local_a
	MOV        word ptr [BP + -6h],SI	; local_8
	JMP        L_0136
	db 90h
L_012c:
	INC        SI
	CMP        SI,word ptr [BP + -0eh]	; local_10
	JGE        L_0123
	JMP        L_0093
	db 90h
L_0136:
	MOV        AX,word ptr [BP + -6h]	; local_8
	INC        AX
	MOV        DS:[0bb18h],AX
	MOV        AX,word ptr [BP + -2h]	; local_4
	MOV        DS:[5356h],AX
	MOV        AX,DS:[0bb18h]
L_0146:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0050 ENDP
F_014e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],40h
	JZ         L_0160
	CALL       SUB_0000_8e6e ; 1000:102Eh
L_0160:
	MOV        byte ptr DS:[5893h],40h
L_0165:
	PUSH       word ptr DS:[25eah]
	CALL       SUB_0000_8dee ; 1000:0FAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0165
	MOV        word ptr [BP + -0ah],SI	; local_c
	PUSH       SI
	MOV        AX,2f30h
	PUSH       AX
	CALL       SUB_0000_fb26 ; 1000:7CE6h [THUNK]
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
L_01a2:
	PUSH       word ptr DS:[260ch]
	CALL       SUB_0000_89ee ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_01a2
	MOV        word ptr [BP + -2h],SI	; local_4
L_01b2:
	PUSH       word ptr DS:[260eh]
	CALL       SUB_0000_89ee ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_01b2
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_0384
	db 90h
L_01d0:
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0e0h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0a8h
	PUSH       AX
	MOV        AX,3ah
L_01f2:
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
L_01f9:
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX + 30dah]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,byte ptr [BX + 30c4h]
	MOV        DI,AX
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 3098h]
	PUSH       AX
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        byte ptr [BX + 30f0h],4h
	JC         L_023e
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 30f0h]
	SUB        AH,AH
	SHL        AX,1h
	SUB        AX,5h
	PUSH       AX
	PUSH       DI
	LEA        AX,[SI + 37h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
L_023e:
	MOV        SI,word ptr [BP + -8h]	; local_a
	SHL        SI,1h
	MOV        AL,byte ptr [SI + 2f98h]
	SUB        AH,AH
	MOV        DS:[5146h],AX
	MOV        AL,byte ptr [SI + 2f99h]
	MOV        DS:[5148h],AX
	MOV        SI,word ptr [BP + -8h]	; local_a
	MOV        CL,2h
	SHL        SI,CL
	MOV        AX,word ptr [SI + 2fc2h]
	MOV        DS:[514ch],AX
	MOV        AX,word ptr [SI + 2fc4h]
	MOV        DS:[514eh],AX
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX + 3040h]
	SUB        AH,AH
	MOV        DS:[5150h],AX
	MOV        AL,byte ptr [BX + 3056h]
	MOV        DS:[5152h],AX
	MOV        AL,byte ptr [BX + 306ch]
	MOV        SI,AX
	MOV        word ptr DS:[5156h],SI
	MOV        AL,byte ptr [BX + 3082h]
	MOV        DS:[5158h],AX
	CMP        byte ptr [BX + 30f0h],3h
	JNZ        L_030c
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AX,3h
	PUSH       AX
	MOV        AX,60h
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AX,2f31h
	PUSH       AX
	CALL       SUB_0000_fb26 ; 1000:7CE6h [THUNK]
	MOV        word ptr DS:[5156h],SI
	MOV        word ptr DS:[5158h],0b4h
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AX,2f5fh
	JMP        L_032a
L_02c4:
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0e8h
	PUSH       AX
	MOV        AX,1ah
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,2h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,36h
	JMP        L_01f2
	db 90h
L_02ea:
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0b8h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,3h
	PUSH       AX
	MOV        AX,0f8h
	PUSH       AX
	SUB        AX,AX
	JMP        L_01f2
	db 90h
L_030c:
	MOV        AX,2f8dh
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        BX,word ptr [BP + -8h]	; local_a
	SHL        BX,1h
	PUSH       word ptr [BX + 3016h]
	CALL       SUB_0000_a3ae ; 1000:256Eh
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AX,0b21eh
L_032a:
	PUSH       AX
	CALL       SUB_0000_fb26 ; 1000:7CE6h [THUNK]
	CMP        word ptr [BP + -8h],0h	; local_a
	JZ         L_033e
	CALL       SUB_0000_9956 ; 1000:1B16h
L_0337:
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	OR         AX,AX
	JZ         L_0337
L_033e:
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8dae ; 1000:0F6Eh
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        byte ptr [BX + 30f0h],2h
	JNZ        L_0381
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AX,2h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	MOV        AX,56h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        AX,28h
	PUSH       AX
	MOV        AX,56h
	PUSH       AX
	MOV        AX,4bh
	PUSH       AX
	MOV        AX,78h
	PUSH       AX
	CALL       SUB_0000_8d86 ; 1000:0F46h
L_0381:
	INC        word ptr [BP + -8h]	; local_a
L_0384:
	CMP        word ptr [BP + -8h],15h	; local_a
	JGE        L_03fc
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX + 30aeh]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -6h]	; local_8
	JZ         L_03c0
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_8a24 ; 1000:0BE4h
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BX + 30aeh]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        DI,AX
	SHL        DI,1h
	ADD        DI,260eh
L_03b2:
	PUSH       word ptr [DI]
	CALL       SUB_0000_89ee ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_03b2
	MOV        word ptr [BP + -4h],SI	; local_6
L_03c0:
	MOV        byte ptr DS:[0a9beh],2h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        BX,word ptr [BP + -8h]	; local_a
	CMP        byte ptr [BX + 30f0h],1h
	JZ         L_03e0
	JMP        L_01f9
L_03e0:
	MOV        AX,BX
	OR         AX,AX
	JNZ        L_03e9
	JMP        L_01d0
L_03e9:
	CMP        AX,7h
	JNZ        L_03f1
	JMP        L_02c4
L_03f1:
	CMP        AX,0eh
	JNZ        L_03f9
	JMP        L_02ea
L_03f9:
	JMP        L_01f9
L_03fc:
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_8a24 ; 1000:0BE4h
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_8a24 ; 1000:0BE4h
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_8e1c ; 1000:0FDCh
	CALL       SUB_0000_9956 ; 1000:1B16h
L_0411:
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	OR         AX,AX
	JZ         L_0411
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        byte ptr DS:[0a9beh],0h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_014e ENDP
F_043e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_9fac ; 1000:216Ch
	CWD
	SUB        AX,DX
	SAR        AX,1h
	SUB        AX,12h
	NEG        AX
	MOV        word ptr [BP + -2h],AX	; local_4
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_9fac ; 1000:216Ch
	ADD        AX,word ptr [BP + -2h]	; local_4
	ADD        AX,2h
	MOV        word ptr [BP + -4h],AX	; local_6
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_88b0 ; 1000:0A70h
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,8h
	PUSH       AX
	MOV        AX,0c1h
	PUSH       AX
	PUSH       SI
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_88e6 ; 1000:0AA6h
	MOV        DI,word ptr [BP + -4h]	; local_6
	MOV        CL,3h
	SHL        DI,CL
	PUSH       DI
	MOV        AX,0c1h
	PUSH       AX
	MOV        AX,137h
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_88e6 ; 1000:0AA6h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_88b0 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	MOV        AX,0c0h
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_8950 ; 1000:0B10h
	PUSH       DI
	MOV        AX,0c0h
	PUSH       AX
	MOV        AX,137h
	PUSH       AX
	MOV        AX,0c0h
	PUSH       AX
	CALL       SUB_0000_8950 ; 1000:0B10h
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CALL       SUB_0000_ca6a ; 1000:4C2Ah
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_9690 ; 1000:1850h
	CALL       SUB_0000_cb0e ; 1000:4CCEh
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_043e ENDP
F_04e0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,7bh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr [BP + -2h],26h	; local_4
	MOV        SI,26h
L_0507:
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	DEC        SI
	JNZ        L_0507
	MOV        AX,7ch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr [BP + -2h],8h	; local_4
	MOV        SI,8h
L_0520:
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,27h
	PUSH       AX
	CALL       SUB_0000_9b2e ; 1000:1CEEh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	DEC        SI
	JNZ        L_0520
	MOV        AX,7dh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr [BP + -2h],26h	; local_4
	MOV        SI,26h
L_054b:
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	DEC        SI
	JNZ        L_054b
	MOV        word ptr DS:[538eh],0h
	MOV        AX,7eh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr DS:[538eh],1h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_88b0 ; 1000:0A70h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	MOV        AX,138h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_8950 ; 1000:0B10h
	MOV        AX,138h
	PUSH       AX
	MOV        AX,0c0h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,0c0h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_04e0 ENDP
F_05b0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        byte ptr DS:[0a9beh],2h
	CMP        byte ptr DS:[5893h],40h
	JZ         L_05cb
	CALL       SUB_0000_8e6e ; 1000:102Eh
	MOV        byte ptr DS:[5893h],40h
L_05cb:
	PUSH       word ptr DS:[261eh]
	CALL       SUB_0000_89ee ; 1000:0BAEh
	MOV        DS:[0bb1ah],AX
	OR         AX,AX
	JZ         L_05cb
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	PUSH       word ptr DS:[0bb1ah]
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_061c
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,13fh
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_8d86 ; 1000:0F46h
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	CMP        AX,1h
	SBB        CX,CX
	NEG        CX
	MOV        word ptr [BP + 4h],CX	; param_1
L_061c:
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_0636
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,13fh
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
L_0636:
	CALL       F_0010
	PUSH       word ptr DS:[0bb1ah]
	CALL       SUB_0000_8a24 ; 1000:0BE4h
	CMP        word ptr [BP + 4h],0h	; param_1
	JZ         L_065e
L_0646:
	MOV        AX,3105h
	PUSH       AX
	CALL       SUB_0000_8dee ; 1000:0FAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0646
	MOV        word ptr [BP + -2h],SI	; local_4
	PUSH       SI
	CALL       F_20ae
	PUSH       SI
	CALL       SUB_0000_8e1c ; 1000:0FDCh
L_065e:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	CALL       F_2090
	MOV        byte ptr DS:[0a9beh],0h
	CALL       F_04e0
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_05b0 ENDP
F_0676 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,word ptr [BP + 0ah]	; param_4
	CMP        word ptr [BP + 8h],AX	; param_3
	JNZ        L_0688
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
L_0688:
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,word ptr [BP + 8h]	; param_3
	ADD        AX,11h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,word ptr [BP + 0ah]	; param_4
	CMP        word ptr [BP + 8h],AX	; param_3
	JNZ        L_06b8
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
L_06b8:
	POP        BP
	RET        8h
	; Func
F_0676 ENDP
F_06bc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       word ptr [BP + 4h]	; param_1
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	MOV        AX,310ch
	PUSH       AX
	CALL       F_0676
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,1h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	MOV        AX,311bh
	PUSH       AX
	CALL       F_0676
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,2h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	MOV        AX,3130h
	PUSH       AX
	CALL       F_0676
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,3h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	MOV        AX,3148h
	PUSH       AX
	CALL       F_0676
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,4h
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	MOV        AX,315eh
	PUSH       AX
	CALL       F_0676
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,316fh
	PUSH       AX
	CALL       F_0676
	POP        BP
	RET        2h
	; Func
F_06bc ENDP
F_072e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
L_0736:
	PUSH       word ptr DS:[2620h]
	CALL       SUB_0000_89ee ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0736
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        SI,0c7h
	MOV        DI,word ptr [BP + -2h]	; local_4
L_076c:
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       DI
	MOV        AX,2h
	PUSH       AX
	MOV        AX,0a0h
	PUSH       AX
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	DEC        SI
	CMP        SI,3fh
	JGE        L_076c
	MOV        word ptr [BP + -4h],SI	; local_6
	SUB        SI,SI
	MOV        DI,word ptr [BP + -2h]	; local_4
L_0799:
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,88h
	SUB        AX,SI
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,98h
	SUB        AX,SI
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	MOV        AX,9fh
	SUB        AX,SI
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
	PUSH       DI
	MOV        AX,2h
	PUSH       AX
	LEA        AX,[SI + 0a8h]
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	LEA        AX,[SI + 0a0h]
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	LEA        AX,[SI + 0a7h]
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9f3a ; 1000:20FAh
	ADD        SI,8h
	CMP        SI,90h
	JL         L_0799
	MOV        word ptr [BP + -4h],SI	; local_6
L_080e:
	PUSH       word ptr DS:[261eh]
	CALL       SUB_0000_89ee ; 1000:0BAEh
	MOV        DS:[0bb1ah],AX
	OR         AX,AX
	JZ         L_080e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	PUSH       word ptr DS:[0bb1ah]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	MOV        AX,41h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       word ptr DS:[0bb1ah]
	CALL       SUB_0000_8a24 ; 1000:0BE4h
	CALL       F_04e0
	MOV        AX,4h
	PUSH       AX
	CALL       F_06bc
L_0851:
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	OR         AX,AX
	JZ         L_0851
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        SI,88h
	MOV        DI,word ptr [BP + -2h]	; local_4
L_0864:
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	SUB        AX,SI
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,88h
	SUB        AX,SI
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	MOV        AX,8fh
	SUB        AX,SI
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
	PUSH       DI
	MOV        AX,2h
	PUSH       AX
	LEA        AX,[SI + 0a0h]
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	LEA        AX,[SI + 0b0h]
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	LEA        AX,[SI + 0b7h]
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9f3a ; 1000:20FAh
	SUB        SI,8h
	JNS        L_0864
	MOV        word ptr [BP + -4h],SI	; local_6
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_8a24 ; 1000:0BE4h
	MOV        SI,3fh
L_08de:
	MOV        DI,SI
	INC        DI
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,2h
	PUSH       AX
	MOV        AX,0a0h
	PUSH       AX
	PUSH       DI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8b8c ; 1000:0D4Ch
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	PUSH       SI
	MOV        AX,0afh
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_890e ; 1000:0ACEh
	INC        SI
	CMP        SI,0c7h
	JL         L_08de
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,90h
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	MOV        AX,0afh
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
	CALL       F_0010
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	CALL       SUB_0000_9956 ; 1000:1B16h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_072e ENDP
F_094e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h	; local_4
	SUB        SI,SI
	MOV        DI,word ptr [BP + 4h]	; param_1
	JMP        L_096a
L_0962:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9f3a ; 1000:20FAh
	INC        SI
L_096a:
	CMP        SI,DI
	JGE        L_0978
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JZ         L_0962
L_0978:
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_094e ENDP
F_0986 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	MOV        byte ptr DS:[0a9ceh],1h
	SUB        SI,SI
L_0995:
	MOV        AX,SI
	MOV        byte ptr [SI + 0b11eh],AL
	INC        SI
	CMP        SI,100h
	JL         L_0995
	MOV        word ptr [BP + -0ch],SI	; local_e
	CALL       SUB_0000_8c20 ; 1000:0DE0h
	CALL       SUB_0000_8f98 ; 1000:1158h
	MOV        AX,DS:[5356h]
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr DS:[52c8h],2h
	JNZ        L_09d2
	CMP        word ptr DS:[5358h],170h
	JNC        L_09d2
	MOV        word ptr DS:[52f1h],0h
	MOV        word ptr DS:[52bah],1h
	MOV        word ptr DS:[52c8h],0h
L_09d2:
	CALL       SUB_0000_8cd4 ; 1000:0E94h
	OR         AX,AX
	JZ         L_09d2
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_86d2 ; 1000:0892h
	CMP        word ptr DS:[52c8h],0h
	JZ         L_0a1a
	CMP        word ptr DS:[52c8h],3h
	JZ         L_0a1a
	MOV        word ptr DS:[13b2h],1h
	MOV        word ptr DS:[13aeh],4h
	MOV        word ptr DS:[13b0h],0fh
	MOV        word ptr DS:[13b6h],5h
	MOV        word ptr DS:[13b4h],2h
	MOV        word ptr DS:[13b8h],0eh
	MOV        word ptr DS:[13bah],7h
	JMP        L_0a49
L_0a1a:
	SUB        CX,CX
	MOV        SI,word ptr [BP + -4h]	; local_6
	JMP        L_0a35
	db 90h
L_0a22:
	INC        SI
	CMP        byte ptr [SI + -1h],2eh
	JNZ        L_0a22
	CMP        byte ptr [SI],31h
	JNZ        L_0a35
	MOV        byte ptr [SI],34h
	INC        SI
	MOV        byte ptr [SI],0h
L_0a35:
	MOV        BX,CX
	INC        CX
	SHL        BX,1h
	MOV        SI,word ptr [BX + 25eah]
	CMP        byte ptr [SI],0h
	JNZ        L_0a22
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        word ptr [BP + -0ch],CX	; local_e
L_0a49:
	CALL       SUB_0000_8d6a ; 1000:0F2Ah
	OR         AX,AX
	JNZ        L_0a5d
	CALL       SUB_0000_86b8 ; 1000:0878h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8134 ; 1000:02F4h
	ADD        SP,2h
L_0a5d:
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_0a84
L_0a64:
	MOV        AX,3182h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9b42 ; 1000:1D02h
	OR         AX,AX
	JZ         L_0a64
L_0a72:
	MOV        AX,318ah
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9b42 ; 1000:1D02h
	OR         AX,AX
	JNZ        L_0aa1
	JMP        L_0a72
	db 90h
L_0a84:
	MOV        AX,3194h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9b42 ; 1000:1D02h
	OR         AX,AX
	JZ         L_0a84
L_0a92:
	MOV        AX,319bh
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9b42 ; 1000:1D02h
	OR         AX,AX
	JZ         L_0a92
L_0aa1:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9ade ; 1000:1C9Eh
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	CALL       SUB_0000_9b9e ; 1000:1D5Eh
	PUSH       AX
	CALL       SUB_0000_9e72 ; 1000:2032h
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,4ah
	JNZ        L_0b06
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,31a4h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
L_0af2:
	PUSH       word ptr DS:[25f0h]
	CALL       SUB_0000_8e34 ; 1000:0FF4h
	OR         AX,AX
	JZ         L_0af2
	MOV        byte ptr DS:[5893h],41h
	JMP        L_0cc9
	db 90h
L_0b06:
	MOV        word ptr [BP + -8h],1h	; local_a
L_0b0b:
	PUSH       word ptr DS:[25eeh]
	CALL       SUB_0000_8dee ; 1000:0FAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0b0b
	MOV        word ptr [BP + -10h],SI	; local_12
L_0b1b:
	PUSH       word ptr DS:[25ech]
	CALL       SUB_0000_8dee ; 1000:0FAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0b1b
	MOV        word ptr [BP + -12h],SI	; local_14
	MOV        AX,31b5h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a3ae ; 1000:256Eh
	CMP        word ptr [BP + -8h],0h	; local_a
	JZ         L_0b56
	PUSH       word ptr [BP + -10h]	; local_12
	CALL       SUB_0000_8bb2 ; 1000:0D72h
	CMP        AX,1h
	SBB        CX,CX
	NEG        CX
	MOV        word ptr [BP + -8h],CX	; local_a
L_0b56:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,8ch
	PUSH       AX
	MOV        AX,13fh
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_88e6 ; 1000:0AA6h
	PUSH       word ptr [BP + -10h]	; local_12
	MOV        AX,7h
	PUSH       AX
	MOV        AX,6ch
	PUSH       AX
	MOV        AX,8ch
	PUSH       AX
	CALL       SUB_0000_8e84 ; 1000:1044h
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,8ch
	PUSH       AX
	MOV        AX,13fh
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_890e ; 1000:0ACEh
	CMP        word ptr [BP + -8h],0h	; local_a
	JZ         L_0bb6
	MOV        AX,12h
	PUSH       AX
	CALL       SUB_0000_9f3a ; 1000:20FAh
	MOV        AX,14h
	PUSH       AX
	CALL       F_094e
	CMP        AX,1h
	SBB        CX,CX
	NEG        CX
	MOV        word ptr [BP + -8h],CX	; local_a
L_0bb6:
	CMP        word ptr [BP + -8h],0h	; local_a
	JNZ        L_0bbf
	JMP        L_0c97
L_0bbf:
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	PUSH       word ptr [BP + -10h]	; local_12
	MOV        AX,8h
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8e84 ; 1000:1044h
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8dae ; 1000:0F6Eh
	MOV        AX,14h
	PUSH       AX
	CALL       F_094e
	CMP        AX,1h
	SBB        CX,CX
	NEG        CX
	MOV        word ptr [BP + -8h],CX	; local_a
	OR         CX,CX
	JZ         L_0c49
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        word ptr DS:[0bb18h],0h
	MOV        word ptr [BP + -8h],0h	; local_a
	MOV        AX,2ch
	PUSH       AX
	MOV        AX,44h
	PUSH       AX
	CALL       F_0050
	OR         AX,AX
	JZ         L_0c42
	MOV        AX,40h
	PUSH       AX
	MOV        AX,5eh
	PUSH       AX
	CALL       F_0050
	OR         AX,AX
	JZ         L_0c42
	MOV        AX,8fh
	PUSH       AX
	MOV        AX,4eh
	PUSH       AX
	CALL       F_0050
	OR         AX,AX
	JZ         L_0c42
	MOV        AX,0a7h
	PUSH       AX
	MOV        AX,69h
	PUSH       AX
	CALL       F_0050
	MOV        word ptr [BP + -8h],AX	; local_a
L_0c42:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
L_0c49:
	PUSH       word ptr [BP + -12h]	; local_14
	SUB        AX,AX
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,42h
	PUSH       AX
	CALL       SUB_0000_8e84 ; 1000:1044h
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8dae ; 1000:0F6Eh
	PUSH       word ptr [BP + -10h]	; local_12
	MOV        AX,9h
	PUSH       AX
	MOV        AX,68h
	PUSH       AX
	MOV        AX,0a0h
	PUSH       AX
	CALL       SUB_0000_8e84 ; 1000:1044h
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8dae ; 1000:0F6Eh
	CMP        word ptr [BP + -8h],0h	; local_a
	JZ         L_0c97
	MOV        AX,14h
	PUSH       AX
	CALL       F_094e
	CMP        AX,1h
	SBB        CX,CX
	NEG        CX
	MOV        word ptr [BP + -8h],CX	; local_a
L_0c97:
	PUSH       word ptr [BP + -12h]	; local_14
	CALL       SUB_0000_8e1c ; 1000:0FDCh
	PUSH       word ptr [BP + -10h]	; local_12
	CALL       SUB_0000_8e1c ; 1000:0FDCh
	MOV        byte ptr DS:[5893h],40h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	PUSH       word ptr [BP + -8h]	; local_a
	CALL       F_05b0
	CMP        word ptr [BP + -8h],0h	; local_a
	JZ         L_0cc4
	CALL       SUB_0000_fb1a ; 1000:7CDAh [THUNK]
L_0cc4:
	MOV        word ptr [BP + -8h],1h	; local_a
L_0cc9:
	CALL       SUB_0000_9e96 ; 1000:2056h
	PUSH       AX
	CALL       SUB_0000_9ebe ; 1000:207Eh
L_0cd0:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
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
	CALL       SUB_0000_9a62 ; 1000:1C22h
	MOV        AX,2h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	CMP        word ptr [BP + -8h],4ah	; local_a
	JNZ        L_0d3e
	MOV        byte ptr [BP + -0eh],4ah	; local_10
	JMP        L_0e47
L_0d3e:
	SUB        DI,DI
	MOV        AX,31c1h
	PUSH       AX
	CALL       F_043e
	SUB        AX,AX
	PUSH       AX
	CALL       F_06bc
L_0d4d:
	MOV        AX,0fh
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CALL       SUB_0000_ca6a ; 1000:4C2Ah
	MOV        AX,31ddh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	CALL       SUB_0000_cb0e ; 1000:4CCEh
	MOV        AX,17h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        word ptr DS:[5356h],113h
	SUB        SI,SI
L_0d75:
	CALL       SUB_0000_9978 ; 1000:1B38h
	PUSH       AX
	CALL       SUB_0000_9e72 ; 1000:2032h
	MOV        byte ptr [BP + -0eh],AL	; local_10
	OR         AL,AL
	JNZ        L_0d86
	CALL       F_2090
L_0d86:
	INC        SI
	CMP        SI,0c8h
	JGE        L_0d93
	CMP        byte ptr [BP + -0eh],0h	; local_10
	JZ         L_0d75
L_0d93:
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        AX,word ptr [BP + -6h]	; local_8
	MOV        DS:[5356h],AX
	MOV        AL,byte ptr [BP + -0eh]	; local_10
	SUB        AH,AH
	CMP        AX,0dh
	JZ         L_0de2
	JA         L_0e16
	OR         AX,AX
	JZ         L_0dec
	CMP        AX,1h
	JZ         L_0dc4
	CMP        AX,2h
	JZ         L_0dd8
	CMP        AX,3h
	JZ         L_0dc4
	CMP        AX,4h
	JZ         L_0dd8
	JMP        L_0e27
	db 90h
	db 90h
L_0dc4:
	DEC        DI
	JNS        L_0dca
	MOV        DI,5h
L_0dca:
	PUSH       DI
L_0dcb:
	CALL       F_06bc
L_0dce:
	CMP        byte ptr [BP + -0eh],20h	; local_10
	JA         L_0e44
	JMP        L_0d4d
	db 90h
L_0dd8:
	INC        DI
	CMP        DI,5h
	JLE        L_0dca
	SUB        DI,DI
	JMP        L_0dca
L_0de2:
	MOV        AL,byte ptr [DI + 3270h]
	MOV        byte ptr [BP + -0eh],AL	; local_10
	JMP        L_0dce
	db 90h
L_0dec:
	MOV        byte ptr [BP + -0eh],52h	; local_10
	JMP        L_0dce
L_0df2:
	SUB        AX,AX
L_0df4:
	PUSH       AX
	JMP        L_0dcb
	db 90h
L_0df8:
	MOV        AX,1h
	JMP        L_0df4
	db 90h
L_0dfe:
	MOV        AX,2h
	JMP        L_0df4
	db 90h
L_0e04:
	MOV        AX,3h
	JMP        L_0df4
	db 90h
L_0e0a:
	MOV        AX,4h
	JMP        L_0df4
	db 90h
L_0e10:
	MOV        AX,5h
	JMP        L_0df4
	db 90h
L_0e16:
	CMP        AX,43h
	JZ         L_0df8
	JA         L_0e2e
	CMP        AX,20h
	JZ         L_0de2
	CMP        AX,41h
	JZ         L_0e0a
L_0e27:
	MOV        byte ptr [BP + -0eh],0h	; local_10
	JMP        L_0dce
	db 90h
L_0e2e:
	CMP        AX,4ah
	JZ         L_0df2
	CMP        AX,52h
	JZ         L_0e10
	CMP        AX,54h
	JZ         L_0dfe
	CMP        AX,55h
	JZ         L_0e04
	JMP        L_0e27
L_0e44:
	MOV        word ptr [BP + -0ah],DI	; local_c
L_0e47:
	MOV        AL,byte ptr [BP + -0eh]	; local_10
	SUB        AH,AH
	CMP        AX,41h
	JNZ        L_0e54
	JMP        L_0ff4
L_0e54:
	CMP        AX,43h
	JNZ        L_0e5c
	JMP        L_0fa8
L_0e5c:
	CMP        AX,4ah
	JZ         L_0e7c
	CMP        AX,52h
	JNZ        L_0e69
	JMP        L_100a
L_0e69:
	CMP        AX,54h
	JNZ        L_0e71
	JMP        L_0f9c
L_0e71:
	CMP        AX,55h
	JNZ        L_0e79
	JMP        L_0fe8
L_0e79:
	JMP        L_0cd0
L_0e7c:
	CALL       SUB_0000_e1be ; 1000:637Eh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_acd6 ; 1000:2E96h
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CMP        byte ptr DS:[5893h],40h
	JNZ        L_0ead
L_0e9d:
	PUSH       word ptr DS:[25f0h]
	CALL       SUB_0000_8e34 ; 1000:0FF4h
	OR         AX,AX
	JZ         L_0e9d
	MOV        byte ptr DS:[5893h],41h
L_0ead:
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
	MOV        AX,31e6h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a3ae ; 1000:256Eh
	CMP        byte ptr DS:[55a8h],0h
	JNZ        L_0f26
	MOV        AX,31f0h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,3203h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,321eh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	MOV        byte ptr DS:[0a9cbh],0ffh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	SUB        AX,AX
	PUSH       AX
	CALL       F_05b0
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_0cd0
	db 90h
L_0f26:
	MOV        AX,323fh
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a3ae ; 1000:256Eh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
	MOV        AX,3249h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_a418 ; 1000:25D8h
	MOV        AX,3252h
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_a418 ; 1000:25D8h
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_0f8c
	CMP        byte ptr DS:[5895h],0h
	JZ         L_0f8c
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
L_0f72:
	MOV        AX,325ch
	PUSH       AX
	CALL       SUB_0000_94b4 ; 1000:1674h
	OR         AX,AX
	JZ         L_0f72
	MOV        AX,3266h
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_a418 ; 1000:25D8h
L_0f8c:
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_acd6 ; 1000:2E96h
	MOV        word ptr DS:[52beh],8h
	JMP        L_1010
	db 90h
L_0f9c:
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	CALL       F_132a
	JMP        L_0fab
L_0fa8:
	CALL       SUB_0000_fb0e ; 1000:7CCEh [THUNK]
L_0fab:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       F_05b0
	CALL       F_0010
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_8a62 ; 1000:0C22h
	JMP        L_0cd0
L_0fe8:
	CALL       F_014e
	SUB        AX,AX
	PUSH       AX
	CALL       F_05b0
	JMP        L_0cd0
L_0ff4:
	CMP        byte ptr DS:[5893h],40h
	JZ         L_1003
	CALL       SUB_0000_8e6e ; 1000:102Eh
	MOV        byte ptr DS:[5893h],40h
L_1003:
	CALL       F_072e
	JMP        L_0cd0
	db 90h
L_100a:
	CALL       SUB_0000_fb1a ; 1000:7CDAh [THUNK]
	JMP        L_0cd0
L_1010:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0986 ENDP
F_1016 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        word ptr [BP + -6h],0bc88h	; local_8
	MOV        word ptr [BP + -8h],0h	; local_a
	MOV        word ptr [BP + -0eh],8h	; local_10
	MOV        byte ptr DS:[0a9beh],1h
	MOV        byte ptr DS:[0a9bdh],4h
	CALL       SUB_0000_94e6 ; 1000:16A6h
	MOV        BX,4h
	MOV        byte ptr [BX + 0a9c8h],AL
	MOV        AX,3278h
	PUSH       AX
	MOV        AX,0bc88h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	PUSH       word ptr [BP + -0eh]	; local_10
	CALL       SUB_0000_a3ae ; 1000:256Eh
	CMP        word ptr DS:[0bc8eh],46h
	JA         L_108c
	CMP        word ptr DS:[0bc90h],46h
	JA         L_108c
	CMP        word ptr DS:[0bc92h],46h
	JA         L_108c
	CMP        word ptr DS:[0bc8ch],270fh
	JA         L_108c
	CMP        word ptr DS:[0bc88h],270fh
	JA         L_108c
	CMP        word ptr DS:[0bc8ah],270fh
	JA         L_108c
	CMP        byte ptr DS:[0bcadh],7h
	JBE        L_1091
L_108c:
	MOV        word ptr [BP + -2h],1h	; local_4
L_1091:
	SUB        CX,CX
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        DX,word ptr [BP + -6h]	; local_8
L_1099:
	MOV        DI,CX
	MOV        BX,DX
	CMP        byte ptr [BX + DI + 14h],0h
	JZ         L_10f6
	CMP        byte ptr [BX + DI + 14h],20h
	JNC        L_10f6
	MOV        SI,1h
L_10ac:
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        word ptr [BP + -0ch],CX	; local_e
	OR         SI,SI
	JZ         L_1106
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3282h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,32b4h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,32d4h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	MOV        AX,1h
	JMP        L_1272
L_10f6:
	MOV        AX,DX
	ADD        AX,14h
	JZ         L_10ac
	INC        CX
	CMP        CX,8h
	JGE        L_10ac
	JMP        L_1099
	db 90h
L_1106:
	MOV        AX,word ptr [BP + -8h]	; local_a
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        word ptr [BP + -0ch],0h	; local_e
	MOV        SI,AX
	MOV        DX,word ptr [BP + -6h]	; local_8
	MOV        CX,word ptr [BP + -0ch]	; local_e
L_1120:
	MOV        DI,CX
	MOV        BX,DX
	CMP        byte ptr [BX + DI + 14h],0h
	JZ         L_1137
	MOV        AL,byte ptr [BX + DI + 14h]
	MOV        BX,CX
	MOV        byte ptr [BX + SI],AL
	INC        CX
	CMP        CX,8h
	JL         L_1120
L_1137:
	MOV        word ptr [BP + -0ch],CX	; local_e
	MOV        BX,CX
	MOV        SI,word ptr [BP + -4h]	; local_6
	MOV        byte ptr [BX + SI],0h
	MOV        BX,word ptr [BP + -6h]	; local_8
	CMP        byte ptr [BX + 24h],0bh
	JNZ        L_1154
	MOV        BX,SI
	MOV        byte ptr [BX + 9h],0bh
	JMP        L_115b
	db 90h
L_1154:
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        byte ptr [BX + 9h],0ch
L_115b:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX + 25h]
	SUB        AH,AH
	CMP        AX,7h
	JA         L_11d0
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 9380h]
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 4Dh
	db 0EBh
	db 57h
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 42h
	db 0EBh
	db 4Dh
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 46h
	db 0EBh
	db 43h
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 44h
	db 0EBh
	db 39h
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 54h
	db 0EBh
	db 2Fh
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 50h
	db 0EBh
	db 25h
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 52h
	db 0EBh
	db 1Bh
	db 90h
	db 8Bh
	db 5Eh
	db 0FCh
	db 0C6h
	db 47h
	db 0Ah
	db 53h
	db 0EBh
	db 11h
	db 90h
	db 30h
	db 93h
	db 3Ah
	db 93h
	db 44h
	db 93h
	db 4Eh
	db 93h
	db 58h
	db 93h
	db 62h
	db 93h
	db 6Ch
	db 93h
	db 76h
	db 93h
L_11d0:
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        byte ptr [BX + 0bh],47h
	MOV        SI,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [SI + 6h]
	MOV        byte ptr [BX + 0ch],AL
	MOV        AL,byte ptr [SI + 8h]
	MOV        byte ptr [BX + 0dh],AL
	MOV        AL,byte ptr [SI + 0ah]
	MOV        byte ptr [BX + 0eh],AL
	MOV        AL,byte ptr [SI + 0ch]
	MOV        byte ptr [BX + 0fh],AL
	MOV        AX,word ptr [SI]
	MOV        word ptr [BX + 10h],AX
	MOV        AX,word ptr [SI + 2h]
	MOV        word ptr [BX + 12h],AX
	MOV        AX,word ptr [SI + 4h]
	MOV        word ptr [BX + 14h],AX
	MOV        BX,SI
	MOV        AX,word ptr [BX + 2h]
	SUB        DX,DX
	MOV        CX,64h
	DIV        CX
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        byte ptr [BX + 16h],AL
	MOV        word ptr [BP + -0eh],140h	; local_10
	MOV        word ptr [BP + -0ah],0bb1ch	; local_c
	MOV        AX,32f9h
	PUSH       AX
	MOV        AX,0bb1ch
	PUSH       AX
	MOV        AX,0b6h
	PUSH       AX
	MOV        AX,140h
	PUSH       AX
	CALL       SUB_0000_a3ae ; 1000:256Eh
	CMP        word ptr DS:[0bb22h],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb24h],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb26h],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb28h],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb2ah],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb2ch],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb2eh],0h
	JNZ        L_1270
	CMP        word ptr DS:[0bb30h],0h
	JNZ        L_1270
	MOV        word ptr DS:[3304h],1h
L_1270:
	SUB        AX,AX
L_1272:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1016 ENDP
F_1278 PROC NEAR
	MOV        AL,DS:[55b2h]
	SUB        AH,AH
	SUB        AX,42h
	CMP        AX,12h
	JA         L_12e8
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 9482h]
	db 90h
	db 0B8h
	db 06h
	db 33h
	db 50h
	db 0E8h
	db 0FBh
	db 83h
	db 0EBh
	db 51h
	db 90h
	db 0B8h
	db 0Ch
	db 33h
	db 0EBh
	db 0F4h
	db 90h
	db 0B8h
	db 12h
	db 33h
	db 0EBh
	db 0EEh
	db 90h
	db 0B8h
	db 1Bh
	db 33h
	db 0EBh
	db 0E8h
	db 90h
	db 0B8h
	db 22h
	db 33h
	db 0EBh
	db 0E2h
	db 90h
	db 0B8h
	db 2Ah
	db 33h
	db 0EBh
	db 0DCh
	db 90h
	db 0B8h
	db 33h
	db 33h
	db 0EBh
	db 0D6h
	db 90h
	db 0B8h
	db 3Bh
	db 33h
	db 0EBh
	db 0D0h
	db 90h
	db 58h
	db 94h
	db 0A8h
	db 94h
	db 64h
	db 94h
	db 0A8h
	db 94h
	db 5Eh
	db 94h
	db 0A8h
	db 94h
	db 0A8h
	db 94h
	db 0A8h
	db 94h
	db 0A8h
	db 94h
	db 0A8h
	db 94h
	db 0A8h
	db 94h
	db 4Eh
	db 94h
	db 0A8h
	db 94h
	db 0A8h
	db 94h
	db 70h
	db 94h
	db 0A8h
	db 94h
	db 76h
	db 94h
	db 7Ch
	db 94h
	db 6Ah
	db 94h
L_12e8:
	RET
	db 90h
	; Func
F_1278 ENDP
F_12ea PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 4h],0ah	; param_1
	JGE        L_12f8
	MOV        AX,word ptr [BP + 4h]	; param_1
	JMP        L_1326
L_12f8:
	CMP        word ptr [BP + 4h],1eh	; param_1
	JL         L_1318
	MOV        AX,word ptr [BP + 4h]	; param_1
	SUB        AX,1eh
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        CX,2h
	SAR        AX,CL
	XOR        AX,DX
	SUB        AX,DX
	ADD        AX,14h
	JMP        L_1326
	db 90h
L_1318:
	MOV        AX,word ptr [BP + 4h]	; param_1
	SUB        AX,9h
	CWD
	SUB        AX,DX
	SAR        AX,1h
	ADD        AX,0ah
L_1326:
	POP        BP
	RET        2h
	; Func
F_12ea ENDP
F_132a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[5893h]
L_1335:
	MOV        DS:[5893h],AL
	CMP        AL,42h
	JNZ        L_1340
	MOV        AL,41h
	JMP        L_1335
L_1340:
	XOR        AH,AH
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        AL,DS:[0a9c8h]
	MOV        DS:[0a9cbh],AL
	MOV        DS:[0a9cch],AL
	MOV        AX,3345h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a3ae ; 1000:256Eh
	MOV        AX,334eh
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a3ae ; 1000:256Eh
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AL,DS:[0a9c8h]
	MOV        byte ptr [BP + -10h],AL	; local_12
	JMP        L_1402
	db 0E8h
	db 95h
	db 86h
	db 0B8h
	db 57h
	db 33h
	db 50h
	db 0E8h
	db 0ECh
	db 82h
	db 2Bh
	db 0C0h
	db 50h
	db 0B8h
	db 0Fh
	db 00h
	db 50h
	db 0E8h
	db 84h
	db 86h
	db 0B8h
	db 79h
	db 33h
	db 50h
	db 0E8h
	db 0DBh
	db 82h
	db 0B8h
	db 08h
	db 00h
	db 50h
	db 0B8h
	db 10h
	db 00h
	db 50h
	db 0E8h
	db 72h
	db 86h
	db 0B8h
	db 0A1h
	db 33h
	db 50h
	db 0E8h
	db 0C9h
	db 82h
	db 0B8h
	db 03h
	db 00h
	db 50h
	db 0B8h
	db 12h
	db 00h
	db 50h
	db 0E8h
	db 60h
	db 86h
	db 0B8h
	db 0B8h
	db 33h
	db 50h
	db 0E8h
	db 0B7h
	db 82h
	db 0C7h
	db 06h
	db 94h
	db 53h
	db 20h
	db 23h
	db 0C7h
	db 06h
	db 96h
	db 53h
	db 00h
	db 00h
	db 8Bh
	db 76h
	db 0F4h
L_13e8:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	PUSH       AX
	CALL       SUB_0000_9e72 ; 1000:2032h
	MOV        byte ptr [BP + -10h],AL	; local_12
	CMP        AL,1bh
	JNZ        L_1402
	MOV        AX,SI
L_13fb:
	MOV        DS:[5893h],AL
	JMP        L_1e1c
	db 90h
L_1402:
	MOV        AL,byte ptr [BP + -10h]	; local_12
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_9cec ; 1000:1EACh
	OR         AX,AX
	JZ         L_13e8
	MOV        word ptr DS:[5394h],2322h
	MOV        word ptr DS:[5396h],0h
	CALL       F_1016
	OR         AX,AX
	JZ         L_1428
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	JMP        L_13fb
	db 90h
L_1428:
	CMP        word ptr DS:[3304h],0h
	JZ         L_1434
	MOV        byte ptr DS:[55b2h],41h
L_1434:
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,33d9h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ch
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,33e1h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55beh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	CMP        byte ptr DS:[55b1h],0bh
	JNZ        L_149a
	MOV        AX,33eah
	JMP        L_149d
L_149a:
	MOV        AX,33f1h
L_149d:
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	CALL       F_1278
	MOV        AX,11h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,33fah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55b4h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,11h
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3401h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55b5h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,11h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3408h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55b6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,340fh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	CMP        word ptr DS:[3304h],0h
	JZ         L_1530
	MOV        AX,3414h
	JMP        L_1533
	db 90h
L_1530:
	MOV        AX,341fh
L_1533:
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	CALL       F_2024
	SUB        SI,SI
L_1549:
	PUSH       SI
	CALL       F_1e22
	INC        SI
	CMP        SI,8h
	JL         L_1549
	MOV        word ptr [BP + -0eh],SI	; local_10
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CMP        byte ptr DS:[55b1h],0bh
	JNZ        L_1592
	MOV        AX,342dh
	JMP        L_1595
L_1592:
	MOV        AX,3432h
L_1595:
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CMP        word ptr DS:[3304h],0h
	JZ         L_15b4
	MOV        AX,3439h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	JMP        L_15b7
L_15b4:
	CALL       F_1278
L_15b7:
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	PUSH       word ptr DS:[55bch]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55beh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55b4h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55b5h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55b6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	CMP        word ptr DS:[3304h],0h
	JZ         L_165e
	MOV        AX,3440h
	JMP        L_1661
L_165e:
	MOV        AX,3447h
L_1661:
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,7h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3452h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3458h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,345eh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	JMP        L_16d4
	db 90h
L_16ce:
	CMP        byte ptr [BP + -10h],4eh	; local_12
	JZ         L_16e5
L_16d4:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	PUSH       AX
	CALL       SUB_0000_9e72 ; 1000:2032h
	MOV        byte ptr [BP + -10h],AL	; local_12
	CMP        AL,59h
	JNZ        L_16ce
L_16e5:
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	CMP        byte ptr [BP + -10h],4eh	; local_12
	JNZ        L_1715
L_16f2:
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,346eh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,55a8h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9c78 ; 1000:1E38h
	CMP        byte ptr DS:[55a8h],0h
	JZ         L_16f2
L_1715:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,7h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,347fh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3485h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,348ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3490h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3495h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	JMP        L_17d2
	db 90h
L_17cc:
	CMP        byte ptr [BP + -10h],4eh	; local_12
	JZ         L_17e3
L_17d2:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	PUSH       AX
	CALL       SUB_0000_9e72 ; 1000:2032h
	MOV        byte ptr [BP + -10h],AL	; local_12
	CMP        AL,59h
	JNZ        L_17cc
L_17e3:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CMP        byte ptr [BP + -10h],59h	; local_12
	JNZ        L_1802
	CMP        byte ptr DS:[55b1h],0bh
	JZ         L_180f
L_1802:
	CMP        byte ptr [BP + -10h],4eh	; local_12
	JNZ        L_181e
	CMP        byte ptr DS:[55b1h],0ch
	JNZ        L_181e
L_180f:
	MOV        AX,34a4h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        byte ptr DS:[55b1h],0bh
	JMP        L_182a
	db 90h
L_181e:
	MOV        AX,34a9h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        byte ptr DS:[55b1h],0ch
L_182a:
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,34b0h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,34b5h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CMP        word ptr DS:[3304h],0h
	JZ         L_1874
	MOV        AX,34bch
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	JMP        L_1877
L_1874:
	CALL       F_1278
L_1877:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,34c3h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,34c8h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,2h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	CMP        word ptr DS:[3304h],0h
	JZ         L_18d0
	MOV        AX,34cfh
	JMP        L_18d3
L_18d0:
	MOV        AX,34e7h
L_18d3:
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,34fch
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3503h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3508h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,350fh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        CX,0ah
	MOV        AX,DS:[55bch]
	CWD
	IDIV       CX
	MOV        DS:[55bch],AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3514h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3532h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3537h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,353eh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3543h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        byte ptr DS:[55beh],1h
	MOV        AX,DS:[55bch]
	CWD
	MOV        CX,64h
	IDIV       CX
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        CX,AX
	JMP        L_1a32
	db 90h
L_1a2c:
	INC        byte ptr DS:[55beh]
	SAR        CX,1h
L_1a32:
	OR         CX,CX
	JG         L_1a2c
	MOV        word ptr [BP + -0eh],CX	; local_10
	MOV        AL,1eh
	MUL        byte ptr DS:[55beh]
	MOV        DS:[55bah],AX
	MOV        DS:[55b8h],AX
	MOV        AL,DS:[55beh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,354ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3563h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,356ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,3h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,356fh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3576h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55b4h]
	SUB        AH,AH
	MOV        word ptr [BP + -12h],AX	; local_14
	PUSH       AX
	CALL       F_12ea
	MOV        DS:[55b4h],AL
	CMP        AL,14h
	JNC        L_1b13
	MOV        byte ptr DS:[55b4h],14h
L_1b13:
	MOV        AL,DS:[55b4h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,357bh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	PUSH       word ptr [BP + -12h]	; local_14
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,358ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55b4h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,3595h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,359ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,359fh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0bh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,35a4h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,35a9h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55b5h]
	SUB        AH,AH
	MOV        word ptr [BP + -12h],AX	; local_14
	PUSH       AX
	CALL       F_12ea
	MOV        DS:[55b5h],AL
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,35aeh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	PUSH       word ptr [BP + -12h]	; local_14
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,35beh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55b5h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,35c9h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,35ceh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,35d3h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,35d8h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,35ddh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AL,DS:[55b6h]
	SUB        AH,AH
	MOV        word ptr [BP + -12h],AX	; local_14
	PUSH       AX
	CALL       F_12ea
	MOV        DS:[55b6h],AL
	MOV        DS:[55b7h],AL
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,35e2h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	PUSH       word ptr [BP + -12h]	; local_14
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,35f2h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AL,DS:[55b6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_987e ; 1000:1A3Eh
	MOV        AX,35fdh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9c1a ; 1000:1DDAh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3602h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0dh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3607h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	CMP        word ptr DS:[3304h],0h
	JZ         L_1d9e
	MOV        AX,360ch
	JMP        L_1da1
	db 90h
L_1d9e:
	MOV        AX,3613h
L_1da1:
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,2h
	PUSH       AX
	PUSH       AX
	MOV        AX,15h
	PUSH       AX
	MOV        AX,25h
	PUSH       AX
	MOV        AX,16h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
	MOV        AX,361eh
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        CX,100h
	MOV        DI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	SUB        AX,AX
	REP STOSB
	MOV        AX,3641h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	CALL       SUB_0000_a418 ; 1000:25D8h
	MOV        AX,364bh
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	CALL       SUB_0000_a418 ; 1000:25D8h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_a35e ; 1000:251Eh
	MOV        AL,byte ptr [BP + -0ch]	; local_e
	MOV        DS:[5893h],AL
	MOV        byte ptr DS:[0a9beh],0h
L_1e1c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_132a ENDP
F_1e22 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        SI,word ptr [BP + 4h]	; param_1
	SHL        SI,1h
	MOV        AX,3h
	PUSH       AX
	PUSH       word ptr [SI + 3656h]
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	PUSH       word ptr [SI + 3666h]
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,3h
	PUSH       AX
	PUSH       word ptr [SI + 3656h]
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	PUSH       word ptr [SI + 3666h]
	CALL       SUB_0000_9690 ; 1000:1850h
	POP        SI
	POP        BP
	RET        2h
	db 90h
	; Func
F_1e22 ENDP
F_1e62 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,13h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,7bh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr [BP + -2h],26h	; local_4
	MOV        SI,26h
L_1e89:
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	DEC        SI
	JNZ        L_1e89
	MOV        AX,7ch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr [BP + -2h],3h	; local_4
	MOV        SI,3h
L_1ea2:
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,27h
	PUSH       AX
	CALL       SUB_0000_9b2e ; 1000:1CEEh
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	DEC        SI
	JNZ        L_1ea2
	MOV        AX,7dh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        word ptr [BP + -2h],26h	; local_4
	MOV        SI,26h
L_1ecd:
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	DEC        SI
	JNZ        L_1ecd
	MOV        AX,7eh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_88b0 ; 1000:0A70h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	MOV        AX,138h
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       SUB_0000_8950 ; 1000:0B10h
	MOV        AX,138h
	PUSH       AX
	MOV        AX,0b8h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,0b8h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	MOV        AX,7h
	PUSH       AX
	MOV        AX,9fh
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_1e62 ENDP
F_1f26 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_88b0 ; 1000:0A70h
	PUSH       word ptr [BP + 4h]	; param_1
	SUB        AX,AX
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,6h
	PUSH       AX
	MOV        AX,8fh
	PUSH       AX
	CALL       SUB_0000_88e6 ; 1000:0AA6h
	MOV        SI,word ptr [BP + 4h]	; param_1
	ADD        SI,8fh
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,97h
	PUSH       AX
	MOV        AX,89h
	PUSH       AX
	CALL       SUB_0000_88e6 ; 1000:0AA6h
	MOV        DI,word ptr [BP + 4h]	; param_1
	ADD        DI,7h
	PUSH       DI
	MOV        AX,89h
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,96h
	PUSH       AX
	MOV        AX,8fh
	PUSH       AX
	CALL       SUB_0000_88e6 ; 1000:0AA6h
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,3676h
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	CALL       SUB_0000_ca6a ; 1000:4C2Ah
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	MOV        AX,6d3ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	CALL       SUB_0000_cb0e ; 1000:4CCEh
	MOV        AX,367ah
	PUSH       AX
	CALL       SUB_0000_9690 ; 1000:1850h
	MOV        AX,7ch
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,11h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,7dh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	MOV        AX,12h
	PUSH       AX
	MOV        AX,11h
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,7eh
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_88b0 ; 1000:0A70h
	MOV        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,18h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	PUSH       DI
	PUSH       AX
	CALL       SUB_0000_8950 ; 1000:0B10h
	PUSH       DI
	MOV        AX,88h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	PUSH       SI
	MOV        AX,88h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	PUSH       SI
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	MOV        AX,word ptr [BP + 4h]	; param_1
	ADD        AX,80h
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_8dd0 ; 1000:0F90h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_9b0a ; 1000:1CCAh
	POP        SI
	POP        DI
	POP        BP
	RET        2h
	db 90h
	; Func
F_1f26 ENDP
F_2024 PROC NEAR
	CALL       F_1e62
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	MOV        AX,13h
	PUSH       AX
	MOV        AX,12h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	MOV        AX,1h
	PUSH       AX
	MOV        AX,15h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,27h
	PUSH       AX
	MOV        AX,12h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	MOV        AX,2h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	MOV        AX,15h
	PUSH       AX
	MOV        AX,25h
	PUSH       AX
	MOV        AX,15h
	PUSH       AX
	CALL       SUB_0000_9a62 ; 1000:1C22h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	SUB        AX,AX
	PUSH       AX
	CALL       F_1f26
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_99d4 ; 1000:1B94h
	MOV        AX,0a8h
	PUSH       AX
	CALL       F_1f26
	MOV        AX,0ch
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_9a32 ; 1000:1BF2h
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_94fa ; 1000:16BAh
	RET
	; Func
F_2024 ENDP
F_2090 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	PUSH       DI
	PUSH       DS
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9f3a ; 1000:20FAh
	CLC
	MOV        word ptr DS:[5350h],69h
	CALL DWORD PTR CS:DS:[5350h]
	POP        DS
	POP        DI
	POP        SI
	POP        BP
	RET
	db 00h
	; Func
F_2090 ENDP
F_20ae PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	PUSH       DI
	PUSH       DS
	MOV        AX,word ptr [BP + 4h]	; param_1
	STC
	MOV        word ptr DS:[5350h],69h
	CALL DWORD PTR CS:DS:[5350h]
	POP        DS
	POP        DI
	POP        SI
	POP        BP
	RET
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
	db 00h
F_20ae ENDP
_TEXT ENDS
END
