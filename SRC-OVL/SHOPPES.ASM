_TEXT SEGMENT BYTE 'CODE'
ORG 6196h
SUB_0000_6196:
ORG 75c0h
SUB_0000_75c0:
ORG 82deh
SUB_0000_82de:
ORG 7e02h
SUB_0000_7e02:
ORG 9cc4h
SUB_0000_9cc4:
ORG 742ah
SUB_0000_742a:
ORG 7c82h
SUB_0000_7c82:
ORG 83dch
SUB_0000_83dc:
ORG 61b2h
SUB_0000_61b2:
ORG 6110h
SUB_0000_6110:
ORG 8670h
SUB_0000_8670:
ORG 9c60h
SUB_0000_9c60:
ORG 0a172h
SUB_0000_a172:
ORG 93feh
SUB_0000_93fe:
ORG 0b680h
SUB_0000_b680:
ORG 7edch
SUB_0000_7edc:
ORG 0dcf6h
SUB_0000_dcf6:
ORG 0dd02h
SUB_0000_dd02:
ORG 7904h
SUB_0000_7904:
ORG 7962h
SUB_0000_7962:
ORG 7a5eh
SUB_0000_7a5e:
ORG 0dd0eh
SUB_0000_dd0e:
ORG 0a99ah
SUB_0000_a99a:
ORG 0acach
SUB_0000_acac:
ORG 0aa3eh
SUB_0000_aa3e:
ORG 9c84h
SUB_0000_9c84:
ORG 9ca6h
SUB_0000_9ca6:
ORG 85f4h
SUB_0000_85f4:
ORG 0abc0h
SUB_0000_abc0:
ORG 7992h
SUB_0000_7992:
ORG 0ab90h
SUB_0000_ab90:
ORG 8bfeh
SUB_0000_8bfe:
ORG 67e0h
SUB_0000_67e0:
ORG 68f6h
SUB_0000_68f6:
ORG 7f02h
SUB_0000_7f02:
ORG 0dc66h
SUB_0000_dc66:
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
	MOV        DI,word ptr [BP + 4h]
	MOV        SI,word ptr [BP + 6h]
	JMP        L_000f
	db 90h
L_000e:
	INC        SI
L_000f:
	MOV        AL,byte ptr [DI]
	INC        DI
	MOV        byte ptr [SI],AL
	OR         AL,AL
	JNZ        L_000e
	MOV        word ptr [BP + 4h],DI
	MOV        word ptr [BP + 6h],SI
	MOV        AX,SI
	POP        SI
	POP        DI
	POP        BP
	RET        4h
	; Func
F_0000 ENDP
F_0026 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + 4h]
	MOV        SI,0b7fah
	JMP        L_0060
L_0036:
	MOV        AL,byte ptr [BP + -0ch]
	SUB        AH,AH
	CMP        AX,25h
	JNZ        L_0043
	JMP        L_00fc
L_0043:
	JBE        L_0048
	JMP        L_0132
L_0048:
	CMP        AX,23h
	JZ         L_0056
	CMP        AX,24h
	JZ         L_00d0
	JMP        L_0060
	db 90h
	db 90h
L_0056:
	PUSH       SI
	PUSH       word ptr DS:[0aafch]
L_005b:
	CALL       F_0000
	MOV        SI,AX
L_0060:
	CMP        byte ptr [DI],0h
	JNZ        L_0068
	JMP        L_014a
L_0068:
	MOV        AL,byte ptr [DI]
	MOV        byte ptr [BP + -0ch],AL
	CMP        AL,23h
	JZ         L_008d
	CMP        AL,24h
	JZ         L_008d
	CMP        AL,40h
	JZ         L_008d
	CMP        AL,25h
	JZ         L_008d
	CMP        AL,5eh
	JZ         L_008d
	CMP        AL,26h
	JZ         L_008d
	CMP        AL,2ah
	JZ         L_008d
	CMP        AL,80h
	JC         L_00a4
L_008d:
	MOV        byte ptr [DI],0h
	PUSH       SI
	PUSH       word ptr [BP + 4h]
	CALL       F_0000
	MOV        SI,AX
	MOV        AL,byte ptr [BP + -0ch]
	MOV        byte ptr [DI],AL
	LEA        AX,[DI + 1h]
	MOV        word ptr [BP + 4h],AX
L_00a4:
	INC        DI
	CMP        byte ptr [BP + -0ch],80h
	JC         L_0036
	MOV        byte ptr [SI],20h
	INC        SI
	PUSH       SI
	MOV        BL,byte ptr [BP + -0ch]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 23eah]
	CALL       F_0000
	MOV        SI,AX
	CMP        byte ptr [DI],0h
	JZ         L_0060
	CMP        byte ptr [DI],80h
	JNC        L_0060
	MOV        byte ptr [SI],20h
	INC        SI
	JMP        L_0060
L_00d0:
	PUSH       SI
	PUSH       word ptr DS:[0aafeh]
	JMP        L_005b
	db 90h
L_00d8:
	CMP        byte ptr DS:[587fh],0ch
	JNC        L_00e8
	PUSH       SI
	MOV        AX,7826h
L_00e3:
	PUSH       AX
	JMP        L_005b
	db 90h
L_00e8:
	CMP        byte ptr DS:[587fh],12h
	JNC        L_00f6
	PUSH       SI
	MOV        AX,782eh
	JMP        L_00e3
	db 90h
L_00f6:
	PUSH       SI
	MOV        AX,7838h
	JMP        L_00e3
L_00fc:
	MOV        AX,0ah
	PUSH       AX
	LEA        AX,[BP + -0ah]
	PUSH       AX
	PUSH       word ptr DS:[0b118h]
L_0108:
	CALL       SUB_0000_6196
	ADD        SP,6h
	PUSH       SI
	LEA        AX,[BP + -0ah]
	JMP        L_00e3
L_0114:
	MOV        AX,0ah
	PUSH       AX
	LEA        AX,[BP + -0ah]
	PUSH       AX
	PUSH       word ptr DS:[0b11ah]
	JMP        L_0108
L_0122:
	PUSH       SI
	PUSH       word ptr DS:[0ab00h]
	JMP        L_005b
L_012a:
	PUSH       SI
	PUSH       word ptr DS:[0ac62h]
	JMP        L_005b
L_0132:
	CMP        AX,26h
	JZ         L_0122
	CMP        AX,2ah
	JZ         L_012a
	CMP        AX,40h
	JZ         L_00d8
	CMP        AX,5eh
	JZ         L_0114
	JMP        L_0060
	db 90h
L_014a:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	PUSH       DS
	POP        ES
	MOV        DI,word ptr [BP + 4h]
	MOV        CX,0ffffh
	XOR        AX,AX
	SCASB
	NOT        CX
	SUB        DI,CX
	XCHG       SI,DI
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
	MOV        AX,0b7fah
	PUSH       AX
	CALL       SUB_0000_75c0
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0026 ENDP
F_017a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,7840h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,5dch
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_82de
	MOV        AX,0b21eh
	PUSH       AX
	CALL       F_0026
	POP        BP
	RET        2h
	; Func
F_017a ENDP
F_019a PROC NEAR
	CMP        byte ptr DS:[5958h],0h
	JNZ        L_01b4
	MOV        AX,57aah
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,40h
	PUSH       AX
	CALL       SUB_0000_7e02
	PUSH       AX
	CALL       SUB_0000_9cc4
L_01b4:
	RET
	db 90h
	; Func
F_019a ENDP
F_01b6 PROC NEAR
	PUSH       SI
	MOV        AX,22h
	PUSH       AX
	CALL       SUB_0000_742a
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        SI,AX
	SHL        SI,1h
	MOV        BX,word ptr DS:[0b116h]
	MOV        CL,3h
	SHL        BX,CL
	PUSH       word ptr [BX + SI + 3b2ah]
	CALL       F_017a
	CALL       SUB_0000_7c82
	CMP        AX,0bh
	JLE        L_01ec
	MOV        AX,784ch
L_01e6:
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_01ff
L_01ec:
	CALL       SUB_0000_7c82
	OR         AX,AX
	JNZ        L_01f8
	MOV        AX,7850h
	JMP        L_01e6
L_01f8:
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_742a
L_01ff:
	POP        SI
	RET
	db 90h
	; Func
F_01b6 ENDP
F_0202 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	CMP        word ptr [BP + 4h],0h
	JNZ        L_0230
	MOV        AX,7854h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        SI,AX
	SHL        SI,1h
	MOV        BX,word ptr DS:[0b116h]
	MOV        CL,3h
	SHL        BX,CL
	PUSH       word ptr [BX + SI + 3b6ah]
	JMP        L_0257
	db 90h
L_0230:
	CMP        word ptr [BP + 4h],1h
	JNZ        L_025a
	MOV        AX,7858h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        SI,AX
	SHL        SI,1h
	MOV        BX,word ptr DS:[0b116h]
	MOV        CL,3h
	SHL        BX,CL
	PUSH       word ptr [BX + SI + 3baah]
L_0257:
	CALL       F_017a
L_025a:
	CMP        word ptr [BP + 4h],0h
	JZ         L_0266
	CMP        word ptr [BP + 4h],1h
	JNZ        L_027b
L_0266:
	CALL       SUB_0000_7c82
	OR         AX,AX
	JZ         L_0274
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
L_0274:
	MOV        AX,785ch
	PUSH       AX
	CALL       F_0026
L_027b:
	POP        SI
	POP        BP
	RET        2h
	; Func
F_0202 ENDP
F_0280 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
L_0287:
	CALL       SUB_0000_83dc
	MOV        SI,AX
	CMP        AX,4eh
	JNZ        L_0296
	MOV        AX,7866h
	JMP        L_02a0
L_0296:
	MOV        AX,SI
	CMP        AX,59h
	JNZ        L_02a4
	MOV        AX,786ah
L_02a0:
	PUSH       AX
	CALL       SUB_0000_75c0
L_02a4:
	MOV        AX,SI
	CMP        AX,4eh
	JZ         L_02b0
	CMP        AX,59h
	JNZ        L_0287
L_02b0:
	MOV        word ptr [BP + -2h],SI
	MOV        AX,SI
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0280 ENDP
F_02ba PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        AX,word ptr [BP + 6h]
	SHL        AX,1h
	MOV        word ptr [BP + -6h],AX
	MOV        SI,AX
	MOV        BX,word ptr DS:[0b114h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AX,word ptr [BX + SI + 3beah]
	MOV        DS:[0b118h],AX
	MOV        AX,word ptr [BP + 8h]
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -8h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + -8h]
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
	CALL       SUB_0000_61b2
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_6110
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,786eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,SI
	PUSH       word ptr [BX + 3c0ah]
	CALL       F_017a
	MOV        AX,7872h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        DI,word ptr [BP + -8h]
	ADD        DI,55b1h
	MOV        SI,word ptr [BP + 4h]
L_033d:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,4eh
	JNZ        L_034e
	MOV        AX,7882h
	JMP        L_03d6
	db 90h
L_034e:
	CMP        byte ptr [BP + -2h],59h
	JZ         L_0357
	JMP        L_03da
L_0357:
	MOV        AX,789ah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_0374
	MOV        AX,21e6h
	PUSH       AX
	CALL       F_017a
	MOV        SI,0ffffh
	JMP        L_03da
	db 90h
L_0374:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       F_019a
	CALL       SUB_0000_8670
	MOV        AX,word ptr [BP + 6h]
	OR         AX,AX
	JZ         L_0394
	CMP        AX,1h
	JZ         L_03b8
	CMP        AX,2h
	JZ         L_03c2
	JMP        L_03a3
L_0394:
	MOV        AX,57ach
	PUSH       AX
	MOV        AX,3h
L_039b:
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_9c60
L_03a3:
	MOV        SI,1h
	MOV        AX,78a0h
	PUSH       AX
	CALL       F_0026
	CMP        byte ptr [DI],0ch
	JNZ        L_03cc
	MOV        AX,78c0h
	JMP        L_03cf
	db 90h
L_03b8:
	MOV        AX,57adh
	PUSH       AX
	MOV        AX,4h
	JMP        L_039b
	db 90h
L_03c2:
	MOV        AX,57aeh
	PUSH       AX
	MOV        AX,5h
	JMP        L_039b
	db 90h
L_03cc:
	MOV        AX,78c8h
L_03cf:
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,78d0h
L_03d6:
	PUSH       AX
	CALL       SUB_0000_75c0
L_03da:
	CMP        byte ptr [BP + -2h],4eh
	JZ         L_03e9
	CMP        byte ptr [BP + -2h],59h
	JZ         L_03e9
	JMP        L_033d
L_03e9:
	MOV        word ptr [BP + 4h],SI
	MOV        AX,SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_02ba ENDP
F_03f6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -6h],AX
L_0404:
	CMP        word ptr [BP + -4h],0h
	JZ         L_040d
	JMP        L_0498
L_040d:
	MOV        AX,78d4h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,78e4h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,78f4h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,7906h
	PUSH       AX
	CALL       SUB_0000_75c0
L_0429:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	CMP        AX,20h
	JZ         L_0465
	JA         L_0482
	CMP        AX,1bh
	JZ         L_0465
	JMP        L_0491
	db 90h
L_0440:
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	OR         AL,20h
	PUSH       AX
	CALL       SUB_0000_742a
	PUSH       word ptr [BP + 4h]
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	SUB        AX,41h
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	CALL       F_02ba
	MOV        word ptr [BP + -6h],AX
	CMP        AX,0ffffh
	JNZ        L_046a
L_0465:
	MOV        word ptr [BP + -4h],1h
L_046a:
	CMP        byte ptr [BP + -2h],0h
	JNZ        L_0404
	CMP        word ptr [BP + -4h],0h
	JZ         L_0429
	JMP        L_0404
L_0478:
	MOV        AX,2215h
	PUSH       AX
	CALL       F_017a
	JMP        L_046a
	db 90h
L_0482:
	CMP        AX,41h
	JC         L_0491
	CMP        AX,43h
	JBE        L_0440
	CMP        AX,44h
	JZ         L_0478
L_0491:
	MOV        byte ptr [BP + -2h],0h
	JMP        L_046a
	db 90h
L_0498:
	MOV        AX,word ptr [BP + -6h]
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_03f6 ENDP
F_04a2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        DI,AX
	CALL       F_01b6
	MOV        SI,DI
L_04b6:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	CMP        AX,20h
	JZ         L_04e6
	CMP        AX,4eh
	JZ         L_04e6
	CMP        AX,59h
	JNZ        L_04df
	MOV        AX,7916h
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       word ptr [BP + 4h]
	CALL       F_03f6
	MOV        DI,AX
L_04dc:
	MOV        SI,1h
L_04df:
	OR         SI,SI
	JNZ        L_04f0
	JMP        L_04b6
	db 90h
L_04e6:
	MOV        AX,7928h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_04dc
	db 90h
L_04f0:
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -4h],SI
	PUSH       DI
	CALL       F_0202
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_04a2 ENDP
F_0502 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	SUB        DX,DX
	MOV        word ptr [BP + -6h],DX
	MOV        DI,word ptr DS:[0b114h]
	MOV        CL,3h
	SHL        DI,CL
	MOV        SI,word ptr [BP + 6h]
	MOV        CX,DX
L_051c:
	MOV        BX,CX
	ADD        BX,DI
	CMP        byte ptr [BX + 3a32h],0h
	JZ         L_053d
	CMP        DX,SI
	JNZ        L_053c
L_052b:
	MOV        word ptr [BP + -4h],DX
	MOV        word ptr [BP + -6h],CX
	CMP        CX,8h
	JNZ        L_0546
	MOV        AX,0fffeh
	JMP        L_065e
L_053c:
	INC        DX
L_053d:
	INC        CX
	CMP        CX,8h
	JGE        L_052b
	JMP        L_051c
	db 90h
L_0546:
	MOV        BX,word ptr [BP + -6h]
	CMP        byte ptr [BX + 5850h],63h
	JNZ        L_0560
	MOV        AX,792ch
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_83dc
L_055a:
	MOV        AX,word ptr [BP + 4h]
	JMP        L_065e
L_0560:
	MOV        SI,word ptr DS:[0b114h]
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,word ptr [BP + -6h]
	MOV        AL,byte ptr [SI + 3a32h]
	SUB        AH,AH
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + 8h]
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
	CALL       SUB_0000_61b2
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_6110
	ADD        word ptr DS:[0b118h],AX
	MOV        AL,byte ptr [SI + 3a5ah]
	SUB        AH,AH
	MOV        DS:[0b11ah],AX
	MOV        AX,7952h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + -6h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 3c10h]
	ADD        AX,97b7h
	PUSH       AX
	CALL       F_0026
	MOV        AX,7956h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_7c82
	CMP        AX,0ch
	JLE        L_05e5
	MOV        AX,796ch
	PUSH       AX
	CALL       SUB_0000_75c0
L_05e5:
	MOV        DI,word ptr [BP + -6h]
	MOV        SI,word ptr [BP + 4h]
L_05eb:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,4eh
	JNZ        L_05fa
	MOV        AX,7970h
	JMP        L_0647
L_05fa:
	CMP        byte ptr [BP + -2h],59h
	JNZ        L_064b
	MOV        AX,7982h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_061c
	MOV        AX,0b6e2h
	PUSH       AX
	CALL       F_0026
	MOV        SI,0ffffh
	JMP        L_064b
L_061c:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       F_019a
	CALL       SUB_0000_8670
	MOV        AX,DI
	ADD        AX,5850h
	PUSH       AX
	PUSH       word ptr DS:[0b11ah]
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_9c60
	MOV        SI,1h
	MOV        AX,7988h
	PUSH       AX
	CALL       F_0026
	MOV        AX,79a2h
L_0647:
	PUSH       AX
	CALL       SUB_0000_75c0
L_064b:
	CMP        byte ptr [BP + -2h],4eh
	JZ         L_0657
	CMP        byte ptr [BP + -2h],59h
	JNZ        L_05eb
L_0657:
	MOV        word ptr [BP + 4h],SI
	JMP        L_055a
	db 90h
L_065e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0502 ENDP
F_0666 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       SI
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,7a0ah
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,5dch
	PUSH       AX
	MOV        AX,1a67h
	PUSH       AX
	CALL       SUB_0000_82de
L_0688:
	CMP        word ptr [BP + -4h],0h
	JZ         L_0691
	JMP        L_0754
L_0691:
	MOV        byte ptr [BP + -0ah],41h
	MOV        word ptr [BP + -6h],0h
L_069a:
	MOV        SI,word ptr [BP + -6h]
	MOV        BX,word ptr DS:[0b114h]
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + SI + 3a32h],0h
	JZ         L_06d1
	MOV        AL,byte ptr [BP + -0ah]
	INC        byte ptr [BP + -0ah]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AX,7a16h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,SI
	SHL        BX,1h
	PUSH       word ptr [BX + 3c20h]
	CALL       SUB_0000_75c0
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
L_06d1:
	INC        word ptr [BP + -6h]
	CMP        word ptr [BP + -6h],8h
	JL         L_069a
	MOV        AX,7a1ah
	PUSH       AX
	CALL       SUB_0000_75c0
L_06e1:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	CMP        AX,1bh
	JZ         L_0717
	JA         L_0742
	CMP        AX,0dh
	JZ         L_0717
	JMP        L_0724
	db 90h
L_06f8:
	PUSH       word ptr [BP + 4h]
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	SUB        AX,41h
	PUSH       AX
	PUSH       word ptr [BP + -0ch]
	CALL       F_0502
	MOV        word ptr [BP + -8h],AX
	CMP        AX,0ffffh
	JNZ        L_071e
	MOV        word ptr [BP + -0ch],0ffffh
L_0717:
	MOV        word ptr [BP + -4h],1h
	JMP        L_0730
L_071e:
	CMP        word ptr [BP + -8h],-2h
	JNZ        L_072a
L_0724:
	MOV        byte ptr [BP + -2h],0h
	JMP        L_0730
L_072a:
	MOV        AX,word ptr [BP + -8h]
	MOV        word ptr [BP + -0ch],AX
L_0730:
	CMP        byte ptr [BP + -2h],0h
	JZ         L_0739
	JMP        L_0688
L_0739:
	CMP        word ptr [BP + -4h],0h
	JZ         L_06e1
	JMP        L_0688
L_0742:
	CMP        AX,20h
	JZ         L_0717
	CMP        AX,41h
	JC         L_0724
	CMP        AX,45h
	JBE        L_06f8
	JMP        L_0724
	db 90h
L_0754:
	MOV        AX,word ptr [BP + -0ch]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0666 ENDP
F_075e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        DI,AX
	CALL       F_01b6
	MOV        SI,DI
L_0772:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	CMP        AX,20h
	JZ         L_07a2
	CMP        AX,4eh
	JZ         L_07a2
	CMP        AX,59h
	JNZ        L_079b
	MOV        AX,7a2ch
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       word ptr [BP + 4h]
	CALL       F_0666
	MOV        DI,AX
L_0798:
	MOV        SI,1h
L_079b:
	OR         SI,SI
	JNZ        L_07ac
	JMP        L_0772
	db 90h
L_07a2:
	MOV        AX,7a44h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_0798
	db 90h
L_07ac:
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -4h],SI
	PUSH       DI
	CALL       F_0202
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_075e ENDP
F_07be PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	SUB        CX,CX
	MOV        SI,5c5ah
L_07cb:
	CMP        byte ptr [SI],0h
	JNZ        L_084a
L_07d0:
	MOV        word ptr [BP + -0ah],CX
	MOV        AX,CX
	MOV        word ptr [BP + -0eh],AX
	MOV        word ptr [BP + -0ah],0h
	MOV        word ptr [BP + -14h],3c38h
	MOV        DI,3c40h
L_07e5:
	MOV        BX,word ptr [BP + -14h]
	MOV        AX,word ptr [BX]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [DI]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	MOV        word ptr [BP + -0ch],AX
	PUSH       word ptr [BP + -8h]
	PUSH       AX
	CALL       SUB_0000_a172
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        SI,AX
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_93fe
	OR         AX,AX
	JNZ        L_085a
	CMP        SI,44h
	JZ         L_082f
	CMP        SI,45h
	JZ         L_082f
	CMP        SI,5h
	JNZ        L_085a
L_082f:
	MOV        word ptr [BP + -12h],SI
	CMP        word ptr [BP + -0ah],4h
	JZ         L_083e
	CMP        word ptr [BP + -0eh],20h
	JNZ        L_086e
L_083e:
	MOV        AX,7a48h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_09a3
	db 90h
	db 90h
L_084a:
	ADD        SI,8h
	INC        CX
	CMP        SI,5d5ah
	JC         L_0857
	JMP        L_07d0
L_0857:
	JMP        L_07cb
L_085a:
	ADD        word ptr [BP + -14h],2h
	ADD        DI,2h
	INC        word ptr [BP + -0ah]
	CMP        DI,3c48h
	JNC        L_082f
	JMP        L_07e5
	db 90h
L_086e:
	SUB        AX,AX
	MOV        word ptr [BP + -6h],AX
	MOV        word ptr [BP + -10h],AX
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 3c30h]
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + 4h]
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
	CALL       SUB_0000_61b2
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_6110
	ADD        word ptr DS:[0b118h],AX
	CALL       F_01b6
	MOV        AX,word ptr [BP + -0eh]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -16h],AX
	MOV        DI,word ptr [BP + -4h]
L_08d1:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	CMP        AX,20h
	JNZ        L_08e1
	JMP        L_0994
L_08e1:
	CMP        AX,4eh
	JNZ        L_08e9
	JMP        L_0994
L_08e9:
	CMP        AX,59h
	JZ         L_08f1
	JMP        L_098b
L_08f1:
	MOV        AX,7a62h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1643h
	PUSH       AX
	CALL       F_017a
	MOV        AX,7a6ah
	PUSH       AX
	CALL       SUB_0000_75c0
L_0906:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,59h
	JZ         L_0914
	CMP        AL,4eh
	JNZ        L_0906
L_0914:
	CMP        byte ptr [BP + -2h],4eh
	JNZ        L_0924
	MOV        AX,7a74h
L_091d:
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_0986
	db 90h
L_0924:
	MOV        AX,7a78h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_094a
	MOV        AX,7a7eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,7a9eh
	PUSH       AX
	CALL       F_0026
	MOV        word ptr [BP + -10h],0ffffh
	JMP        L_0986
	db 90h
L_094a:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       F_019a
	MOV        DI,word ptr [BP + -16h]
	SUB        AL,AL
	MOV        byte ptr [DI + 5h],AL
	MOV        byte ptr [DI + 7h],AL
	MOV        byte ptr [DI + 6h],AL
	MOV        AL,10h
	MOV        byte ptr [DI + 1h],AL
	MOV        byte ptr [DI],AL
	MOV        AL,byte ptr [BP + -8h]
	MOV        byte ptr [DI + 2h],AL
	MOV        AL,byte ptr [BP + -0ch]
	MOV        byte ptr [DI + 3h],AL
	MOV        AL,DS:[5895h]
	MOV        byte ptr [DI + 4h],AL
	CALL       SUB_0000_b680
	CALL       SUB_0000_8670
	MOV        word ptr [BP + -10h],1h
L_0986:
	MOV        word ptr [BP + -6h],1h
L_098b:
	CMP        word ptr [BP + -6h],0h
	JNZ        L_099a
	JMP        L_08d1
L_0994:
	MOV        AX,7ab2h
	JMP        L_091d
	db 90h
L_099a:
	MOV        word ptr [BP + -4h],DI
	PUSH       word ptr [BP + -10h]
	CALL       F_0202
L_09a3:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_07be ENDP
F_09ac PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        AX,word ptr [BP + 6h]
	SHL        AX,1h
	MOV        word ptr [BP + -4h],AX
	MOV        BX,AX
	MOV        AX,word ptr [BX + 3a82h]
	MOV        DS:[0b118h],AX
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        AX,DS:[0b118h]
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + 8h]
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
	CALL       SUB_0000_61b2
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_6110
	ADD        word ptr DS:[0b118h],AX
	MOV        AX,7b5eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + -4h]
	PUSH       word ptr [BX + 3c48h]
	CALL       F_017a
	MOV        AX,7b62h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3ca6h]
	CALL       SUB_0000_75c0
	MOV        AX,7b66h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        DI,word ptr [BP + 4h]
	MOV        SI,word ptr [BP + 6h]
L_0a3a:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,4eh
	JNZ        L_0a4e
	MOV        AX,7b6ah
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_0ae3
L_0a4e:
	CMP        byte ptr [BP + -2h],59h
	JZ         L_0a57
	JMP        L_0ae3
L_0a57:
	MOV        AX,7b70h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr [SI + 57c0h],63h
	JNZ        L_0a78
	MOV        AX,7b76h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,7b9ah
	PUSH       AX
	CALL       F_0026
	CALL       SUB_0000_83dc
	JMP        L_0ae3
L_0a78:
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_0aaa
	MOV        AX,7ba4h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3caeh]
	CALL       SUB_0000_75c0
	MOV        AX,7ba8h
	PUSH       AX
	CALL       F_0026
	MOV        DI,0ffffh
	JMP        L_0ae3
	db 90h
L_0aaa:
	MOV        AX,DS:[0b118h]
	SUB        word ptr DS:[57aah],AX
	CALL       F_019a
	CALL       SUB_0000_8670
	CMP        SI,1bh
	JZ         L_0ac1
	CMP        SI,1dh
	JNZ        L_0ac8
L_0ac1:
	MOV        byte ptr [SI + 57c0h],63h
	JMP        L_0ad9
L_0ac8:
	MOV        AX,SI
	ADD        AX,57c0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_9c60
L_0ad9:
	MOV        AX,7bb4h
	PUSH       AX
	CALL       F_0026
	MOV        DI,1h
L_0ae3:
	CMP        byte ptr [BP + -2h],4eh
	JZ         L_0af2
	CMP        byte ptr [BP + -2h],59h
	JZ         L_0af2
	JMP        L_0a3a
L_0af2:
	MOV        word ptr [BP + 4h],DI
	CMP        DI,-1h
	JZ         L_0b25
	MOV        AX,7bbch
	PUSH       AX
	CALL       SUB_0000_75c0
	OR         DI,DI
	JZ         L_0b1e
	MOV        BX,word ptr [BP + 8h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b1h],0ch
	JNZ        L_0b18
	MOV        AX,7bceh
	JMP        L_0b21
L_0b18:
	MOV        AX,7bd6h
	JMP        L_0b21
	db 90h
L_0b1e:
	MOV        AX,7bdch
L_0b21:
	PUSH       AX
	CALL       SUB_0000_75c0
L_0b25:
	MOV        AX,word ptr [BP + 4h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_09ac ENDP
F_0b30 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -8h],AX
L_0b40:
	MOV        AX,7c44h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        DI,DI
L_0b49:
	MOV        BX,word ptr DS:[0b114h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + DI + 3ae2h]
	SUB        AH,AH
	MOV        SI,AX
	CMP        SI,0ffh
	JNZ        L_0bcc
L_0b5f:
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -0ah],SI
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3cb6h]
	CALL       SUB_0000_75c0
	MOV        AX,7c4ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        DI,word ptr [BP + -4h]
L_0b8b:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	SUB        AX,41h
	MOV        SI,AX
	CMP        word ptr [BP + -6h],SI
	JLE        L_0c1c
	OR         SI,SI
	JL         L_0c1c
	ADD        AX,61h
	PUSH       AX
	CALL       SUB_0000_742a
	PUSH       word ptr [BP + 4h]
	MOV        BX,word ptr DS:[0b114h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 3ae2h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -8h]
	CALL       F_09ac
	MOV        word ptr [BP + -8h],AX
	CMP        AX,0ffffh
	JNZ        L_0c32
	JMP        L_0c28
	db 90h
	db 90h
L_0bcc:
	MOV        AX,DI
	ADD        AX,61h
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AX,7c48h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,SI
	SHL        BX,1h
	PUSH       word ptr [BX + 17f6h]
	CALL       SUB_0000_7edc
	CMP        AX,0dh
	JGE        L_0bf6
	MOV        BX,SI
	SHL        BX,1h
	PUSH       word ptr [BX + 17f6h]
	JMP        L_0bfe
L_0bf6:
	MOV        BX,SI
	SHL        BX,1h
	PUSH       word ptr [BX + 1962h]
L_0bfe:
	CALL       SUB_0000_75c0
	CALL       SUB_0000_7c82
	OR         AX,AX
	JZ         L_0c0f
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
L_0c0f:
	INC        DI
	CMP        DI,8h
	JL         L_0c18
	JMP        L_0b5f
L_0c18:
	JMP        L_0b49
	db 90h
L_0c1c:
	CMP        byte ptr [BP + -2h],1bh
	JZ         L_0c28
	CMP        byte ptr [BP + -2h],20h
	JNZ        L_0c2e
L_0c28:
	MOV        DI,1h
	JMP        L_0c32
	db 90h
L_0c2e:
	MOV        byte ptr [BP + -2h],0h
L_0c32:
	CMP        byte ptr [BP + -2h],0h
	JNZ        L_0c3f
	OR         DI,DI
	JNZ        L_0c3f
	JMP        L_0b8b
L_0c3f:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -0ah],SI
	OR         DI,DI
	JNZ        L_0c4c
	JMP        L_0b40
L_0c4c:
	MOV        AX,word ptr [BP + -8h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0b30 ENDP
F_0c58 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	SUB        SI,SI
L_0c61:
	CMP        byte ptr [SI + 57c0h],0h
	JZ         L_0c70
	MOV        AX,1h
	MOV        word ptr [BP + -2h],SI
	JMP        L_0c7b
L_0c70:
	INC        SI
	CMP        SI,30h
	JL         L_0c61
	MOV        word ptr [BP + -2h],SI
	SUB        AX,AX
L_0c7b:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0c58 ENDP
F_0c80 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]
	MOV        SI,word ptr [BX]
	CMP        byte ptr [SI + 57c0h],0h
	JZ         L_0c97
	JMP        L_0d3c
L_0c97:
	MOV        BX,word ptr [BP + 6h]
	CMP        word ptr [BX],SI
	JNZ        L_0cda
	PUSH       SI
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	MOV        BX,word ptr [BP + 4h]
	MOV        word ptr [BX],AX
	CMP        AX,0ffffh
	JNZ        L_0cd0
	MOV        AX,0ffffh
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        BX,word ptr [BP + 4h]
	MOV        word ptr [BX],AX
L_0cd0:
	MOV        BX,word ptr [BP + 6h]
	MOV        SI,word ptr [BP + 4h]
	MOV        AX,word ptr [SI]
	JMP        L_0d3a
L_0cda:
	MOV        BX,word ptr [BP + 4h]
	PUSH       word ptr [BX]
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        BX,word ptr [BP + 4h]
	MOV        word ptr [BX],AX
	CMP        AX,0ffffh
	JNZ        L_0d3c
	MOV        AX,30h
	PUSH       AX
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	MOV        BX,word ptr [BP + 4h]
	MOV        word ptr [BX],AX
	MOV        BX,word ptr [BP + 6h]
	MOV        SI,word ptr [BX]
	PUSH       SI
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	CMP        AX,0ffffh
	JLE        L_0d3c
	PUSH       SI
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	MOV        BX,word ptr [BP + 6h]
L_0d3a:
	MOV        word ptr [BX],AX
L_0d3c:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7904
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_7962
	MOV        BX,word ptr [BP + 6h]
	MOV        AX,word ptr [BX]
	MOV        word ptr [BP + -6h],AX
	CMP        AX,0ffffh
	JZ         L_0da5
	MOV        BX,word ptr [BP + 4h]
	MOV        DI,word ptr [BX]
	MOV        word ptr [BP + -0ch],DI
	MOV        SI,AX
L_0d62:
	CMP        word ptr [BP + -0ch],SI
	JNZ        L_0d74
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_742a
	CALL       SUB_0000_7a5e
	MOV        word ptr [BP + -2h],AX
L_0d74:
	PUSH       SI
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,1962h
	PUSH       AX
	MOV        AX,2dh
	PUSH       AX
	CALL       SUB_0000_dd0e
	CMP        DI,SI
	JNZ        L_0d8f
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_742a
L_0d8f:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a5e
	PUSH       AX
	CALL       SUB_0000_7962
	CALL       SUB_0000_7a5e
	CMP        AX,5h
	JNZ        L_0dac
L_0da2:
	MOV        word ptr [BP + -6h],SI
L_0da5:
	CALL       SUB_0000_7a5e
	MOV        SI,AX
	JMP        L_0dd6
L_0dac:
	PUSH       SI
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        SI,AX
	CMP        SI,-1h
	JZ         L_0da2
	JMP        L_0d62
	db 90h
L_0dc6:
	MOV        AX,1h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_7962
	MOV        AX,7c50h
	PUSH       AX
	CALL       SUB_0000_75c0
	INC        SI
L_0dd6:
	CMP        SI,5h
	JNZ        L_0dc6
	MOV        word ptr [BP + -4h],SI
	MOV        word ptr [BP + -8h],0h
	MOV        BX,word ptr [BP + 6h]
	PUSH       word ptr [BX]
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	INC        AX
	JZ         L_0dff
	MOV        word ptr [BP + -8h],2h
L_0dff:
	CMP        word ptr [BP + -6h],-1h
	JZ         L_0e1d
	PUSH       word ptr [BP + -6h]
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	INC        AX
	JZ         L_0e1d
	INC        word ptr [BP + -8h]
L_0e1d:
	CMP        word ptr [BP + -8h],0h
	JZ         L_0e2e
	MOV        AX,6h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_7962
	CALL       SUB_0000_a99a
L_0e2e:
	MOV        AX,word ptr [BP + -8h]
	OR         AX,AX
	JZ         L_0e46
	CMP        AX,1h
	JZ         L_0e56
	CMP        AX,2h
	JZ         L_0e62
	CMP        AX,3h
	JZ         L_0e68
	JMP        L_0e49
L_0e46:
	CALL       SUB_0000_acac
L_0e49:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_7904
	MOV        AX,word ptr [BP + -2h]
	JMP        L_0e6e
	db 90h
L_0e56:
	MOV        AX,19h
L_0e59:
	PUSH       AX
	CALL       SUB_0000_742a
	CALL       SUB_0000_aa3e
	JMP        L_0e49
L_0e62:
	MOV        AX,18h
	JMP        L_0e59
	db 90h
L_0e68:
	MOV        AX,12h
	JMP        L_0e59
	db 90h
L_0e6e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0c80 ENDP
F_0e76 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	CMP        word ptr [BP + 4h],1bh
	JZ         L_0e89
	CMP        word ptr [BP + 4h],1dh
	JNZ        L_0e96
L_0e89:
	MOV        AX,7d32h
	PUSH       AX
	CALL       F_0026
	MOV        AX,1h
	JMP        L_0f5d
L_0e96:
	MOV        AX,7d64h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        SI,word ptr [BP + 4h]
	SHL        SI,1h
	CMP        word ptr [SI + 3a82h],0h
	JNZ        L_0eac
	JMP        L_0f54
L_0eac:
	MOV        AX,64h
	CWD
	PUSH       DX
	PUSH       AX
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b6h]
	SUB        AH,AH
	MUL        word ptr [SI + 3a82h]
	SUB        DX,DX
	MOV        CX,AX
	MOV        BX,DX
	SHL        AX,1h
	RCL        DX,1h
	ADD        AX,CX
	ADC        DX,BX
	PUSH       DX
	PUSH       AX
	CALL       SUB_0000_6110
	INC        AX
	MOV        DS:[0b118h],AX
	MOV        AX,word ptr [SI + 3cceh]
	MOV        DS:[0ab00h],AX
	OR         AX,AX
	JNZ        L_0eec
	MOV        AX,word ptr [SI + 17f6h]
	MOV        DS:[0ab00h],AX
L_0eec:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	MOV        AX,word ptr [BX + 3cbeh]
	ADD        AX,0a65eh
	PUSH       AX
	CALL       F_0026
	MOV        AX,7d68h
	PUSH       AX
	CALL       SUB_0000_75c0
L_0f0c:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,4eh
	JZ         L_0f1a
	CMP        AL,59h
	JNZ        L_0f0c
L_0f1a:
	CMP        byte ptr [BP + -2h],4eh
	JNZ        L_0f2a
	MOV        AX,7d72h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_0f4e
	db 90h
L_0f2a:
	MOV        AX,7d76h
	PUSH       AX
	CALL       F_0026
	MOV        AX,57aah
	PUSH       AX
	PUSH       word ptr DS:[0b118h]
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_9c84
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,57c0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9ca6
L_0f4e:
	CALL       SUB_0000_85f4
	JMP        L_0f5b
	db 90h
L_0f54:
	MOV        AX,7d8ch
	PUSH       AX
	CALL       F_0026
L_0f5b:
	SUB        AX,AX
L_0f5d:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0e76 ENDP
F_0f64 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	CALL       F_0c58
	OR         AX,AX
	JNZ        L_0f76
	JMP        L_12a2
L_0f76:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3d2eh]
	CALL       SUB_0000_75c0
	MOV        AX,7ef0h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,7ef4h
	PUSH       AX
	CALL       SUB_0000_abc0
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7904
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       SUB_0000_7992
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_742a
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
	CALL       SUB_0000_7992
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        word ptr [BP + -0ch],0dh
	MOV        SI,0dh
L_0fe4:
	MOV        AX,11h
	PUSH       AX
	CALL       SUB_0000_742a
	DEC        SI
	JNZ        L_0fe4
	MOV        AX,13h
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        SI,1h
L_0ff8:
	SUB        AX,AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_7962
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AX,0eh
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_7962
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_742a
	INC        SI
	CMP        SI,5h
	JL         L_0ff8
	MOV        word ptr [BP + -0ch],SI
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        word ptr [BP + -0ch],0dh
	MOV        SI,0dh
L_1034:
	MOV        AX,15h
	PUSH       AX
	CALL       SUB_0000_742a
	DEC        SI
	JNZ        L_1034
	MOV        AX,16h
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AX,0ffffh
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -0eh],AX
	LEA        AX,[BP + -4h]
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       F_0c80
	MOV        word ptr [BP + -0ah],AX
	SUB        AX,AX
	MOV        word ptr [BP + -10h],AX
	MOV        word ptr [BP + -8h],AX
	MOV        AX,7efah
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,5dch
	PUSH       AX
	MOV        AX,0bc0h
	PUSH       AX
	CALL       SUB_0000_82de
L_1087:
	CMP        word ptr [BP + -8h],0h
	JZ         L_1090
	JMP        L_1266
L_1090:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -6h],AL
	SUB        AH,AH
	CMP        AX,0dh
	JNZ        L_10a0
	JMP        L_11ea
L_10a0:
	JBE        L_10a5
	JMP        L_123e
L_10a5:
	CMP        AX,1h
	JZ         L_10bc
	CMP        AX,2h
	JZ         L_1124
	CMP        AX,3h
	JZ         L_10bc
	CMP        AX,4h
L_10b7:
	JZ         L_1124
	JMP        L_1087
	db 90h
L_10bc:
	CMP        byte ptr [BP + -6h],0d5h
	JNZ        L_10ca
	MOV        word ptr [BP + -2h],4h
	JMP        L_10cf
	db 90h
L_10ca:
	MOV        word ptr [BP + -2h],1h
L_10cf:
	MOV        word ptr [BP + -0ch],0h
	CMP        word ptr [BP + -2h],0h
	JLE        L_1112
	MOV        AX,word ptr [BP + -2h]
	MOV        word ptr [BP + -14h],AX
	ADD        word ptr [BP + -0ch],AX
	MOV        DI,word ptr [BP + -0eh]
L_10e6:
	PUSH       DI
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	MOV        SI,AX
	CMP        DI,word ptr [BP + -4h]
	JNZ        L_1105
	CMP        SI,-1h
	JLE        L_1107
	MOV        word ptr [BP + -4h],SI
L_1105:
	MOV        DI,SI
L_1107:
	DEC        word ptr [BP + -14h]
	JNZ        L_10e6
	MOV        word ptr [BP + -0eh],DI
L_110f:
	MOV        word ptr [BP + -12h],SI
L_1112:
	LEA        AX,[BP + -4h]
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       F_0c80
	MOV        word ptr [BP + -0ah],AX
	JMP        L_1087
	db 90h
L_1124:
	CMP        byte ptr [BP + -6h],0d6h
	JNZ        L_1132
	MOV        word ptr [BP + -2h],4h
	JMP        L_1137
	db 90h
L_1132:
	MOV        word ptr [BP + -2h],1h
L_1137:
	MOV        word ptr [BP + -0ch],0h
	CMP        word ptr [BP + -2h],0h
	JLE        L_1112
	MOV        DI,word ptr [BP + -2h]
	MOV        AX,DI
	ADD        word ptr [BP + -0ch],AX
L_114a:
	PUSH       word ptr [BP + -0eh]
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        SI,AX
	CMP        SI,-1h
	JLE        L_1184
	MOV        word ptr [BP + -0eh],SI
	INC        word ptr [BP + -0ah]
	CMP        word ptr [BP + -0ah],4h
	JLE        L_1184
	PUSH       word ptr [BP + -4h]
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        word ptr [BP + -4h],AX
L_1184:
	DEC        DI
	JNZ        L_114a
	JMP        L_110f
	db 90h
L_118a:
	MOV        AX,0ffffh
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dd02
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -0eh],AX
	JMP        L_1112
L_11a6:
	MOV        AX,30h
	PUSH       AX
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -0eh],AX
	MOV        DI,1h
L_11bf:
	PUSH       word ptr [BP + -4h]
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dcf6
	MOV        SI,AX
	CMP        SI,-1h
	JNZ        L_11de
L_11d8:
	MOV        word ptr [BP + -0ch],DI
	JMP        L_110f
L_11de:
	MOV        word ptr [BP + -4h],SI
	INC        DI
	CMP        DI,4h
	JGE        L_11d8
	JMP        L_11bf
	db 90h
L_11ea:
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -0eh]
	CALL       F_0e76
	MOV        word ptr [BP + -10h],AX
	OR         AX,AX
	JNZ        L_1236
	CALL       F_0c58
	OR         AX,AX
	JZ         L_1236
	LEA        AX,[BP + -4h]
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       F_0c80
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,7f06h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3d3eh]
	CALL       SUB_0000_75c0
	MOV        AX,7f0ah
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_1087
	db 90h
L_1236:
	MOV        word ptr [BP + -8h],1h
	JMP        L_1087
L_123e:
	CMP        AX,1bh
	JZ         L_1236
	CMP        AX,20h
	JZ         L_11ea
	CMP        AX,0d3h
	JNZ        L_1250
	JMP        L_118a
L_1250:
	CMP        AX,0d4h
	JNZ        L_1258
	JMP        L_11a6
L_1258:
	CMP        AX,0d5h
	JNZ        L_1260
	JMP        L_10bc
L_1260:
	CMP        AX,0d6h
	JMP        L_10b7
L_1266:
	CALL       SUB_0000_8670
	CALL       SUB_0000_ab90
	CMP        word ptr [BP + -10h],0h
	JNZ        L_12a9
	MOV        AX,7f0eh
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3d36h]
	CALL       SUB_0000_75c0
	MOV        AX,7f12h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       F_0c58
	OR         AX,AX
	JZ         L_12a9
	MOV        AX,7f16h
	JMP        L_12a5
	db 90h
L_12a2:
	MOV        AX,7f20h
L_12a5:
	PUSH       AX
	CALL       F_0026
L_12a9:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0f64 ENDP
F_12b2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
	MOV        AX,8018h
	PUSH       AX
	CALL       F_0026
	CALL       SUB_0000_83dc
	MOV        AX,8036h
	PUSH       AX
	CALL       F_0026
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3d46h]
	CALL       SUB_0000_75c0
	MOV        AX,8042h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        DI,word ptr [BP + 4h]
L_12ec:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	SUB        AH,AH
	CMP        AX,20h
	JZ         L_1362
	CMP        AX,42h
	JZ         L_1306
	CMP        AX,53h
	JZ         L_1352
	JMP        L_133d
	db 90h
L_1306:
	MOV        AX,8046h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3d4ah]
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3d52h]
	CALL       SUB_0000_75c0
	PUSH       DI
	CALL       F_0b30
	MOV        SI,AX
L_133d:
	CMP        byte ptr [BP + -2h],42h
	JZ         L_136c
	CMP        byte ptr [BP + -2h],53h
	JZ         L_136c
	CMP        byte ptr [BP + -2h],20h
	JZ         L_136c
	JMP        L_12ec
	db 90h
L_1352:
	MOV        AX,804eh
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       DI
	CALL       F_0f64
	MOV        SI,0ffffh
	JMP        L_133d
L_1362:
	MOV        AX,8056h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_133d
	db 90h
L_136c:
	MOV        word ptr [BP + -4h],SI
	PUSH       SI
	CALL       F_0202
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_12b2 ENDP
F_137c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	CMP        byte ptr DS:[585bh],1h
	JNZ        L_1390
	MOV        word ptr [BP + -2h],0h
	JMP        L_13a9
L_1390:
	MOV        AX,805ah
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_8bfe
	MOV        word ptr [BP + -2h],AX
	CMP        AX,0ffffh
	JNZ        L_13a9
	MOV        AX,8072h
	PUSH       AX
	CALL       SUB_0000_75c0
L_13a9:
	MOV        AX,word ptr [BP + -2h]
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_137c ENDP
F_13b0 PROC NEAR
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_67e0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_68f6
	MOV        AX,100eh
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,57e4h
	PUSH       AX
	MOV        AX,1388h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7f02
	MOV        AX,100eh
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,57e4h
	PUSH       AX
	MOV        AX,6b6ch
	PUSH       AX
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_7f02
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_68f6
	MOV        AX,11b2h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,9c40h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_7f02
	MOV        AX,11b2h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,9c40h
	PUSH       AX
	PUSH       AX
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_7f02
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_68f6
	MOV        AX,8fch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,4650h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_7f02
	MOV        AX,8fch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,4650h
	PUSH       AX
	MOV        AX,8ca0h
	PUSH       AX
	MOV        AX,0fffeh
	PUSH       AX
	CALL       SUB_0000_7f02
	RET
	; Func
F_13b0 ENDP
F_146a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        AX,807ah
	PUSH       AX
	CALL       F_0026
L_1478:
	CALL       SUB_0000_83dc
	MOV        SI,AX
	CMP        AX,59h
	JNZ        L_1488
	MOV        AX,8098h
	JMP        L_1492
	db 90h
L_1488:
	MOV        AX,SI
	CMP        AX,4eh
	JNZ        L_1496
	MOV        AX,809ch
L_1492:
	PUSH       AX
	CALL       SUB_0000_75c0
L_1496:
	MOV        AX,SI
	CMP        AX,59h
	JZ         L_14a2
	CMP        AX,4eh
	JNZ        L_1478
L_14a2:
	MOV        word ptr [BP + -2h],SI
	CMP        SI,4eh
	JNZ        L_14b0
	MOV        AX,1h
	JMP        L_14b2
	db 90h
L_14b0:
	SUB        AX,AX
L_14b2:
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JNZ        L_14da
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JGE        L_14da
	CMP        AX,64h
	JG         L_14ce
	CMP        byte ptr DS:[5893h],7h
	JZ         L_14da
L_14ce:
	MOV        AX,23abh
	PUSH       AX
	CALL       F_017a
	MOV        word ptr [BP + -4h],1h
L_14da:
	CMP        word ptr [BP + -4h],0h
	JNZ        L_14f0
	MOV        AX,DS:[0b118h]
	CMP        word ptr DS:[57aah],AX
	JL         L_14f0
	SUB        word ptr DS:[57aah],AX
	CALL       F_019a
L_14f0:
	MOV        AX,word ptr [BP + -4h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_146a ENDP
F_14f8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	CALL       F_01b6
	MOV        word ptr [BP + -4h],0h
L_1507:
	CMP        word ptr [BP + -4h],0h
	JZ         L_1510
	JMP        L_171e
L_1510:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,4eh
	JNZ        L_1520
	MOV        AX,80a0h
	JMP        L_1529
	db 90h
L_1520:
	CMP        byte ptr [BP + -2h],59h
	JNZ        L_152d
	MOV        AX,80a4h
L_1529:
	PUSH       AX
	CALL       SUB_0000_75c0
L_152d:
	CMP        byte ptr [BP + -2h],4eh
	JZ         L_1539
	CMP        byte ptr [BP + -2h],59h
	JNZ        L_1510
L_1539:
	CMP        byte ptr [BP + -2h],4eh
	JNZ        L_1542
	JMP        L_171e
L_1542:
	MOV        AX,80aah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,80dah
	PUSH       AX
	CALL       F_0026
L_1550:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,43h
	JZ         L_156a
	CMP        AL,48h
	JZ         L_156a
	CMP        AL,52h
	JZ         L_156a
	CMP        AL,20h
	JZ         L_156a
	CMP        AL,0dh
	JNZ        L_1550
L_156a:
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	CMP        AX,0dh
	JNZ        L_1577
	JMP        L_170e
L_1577:
	CMP        AX,20h
	JNZ        L_157f
	JMP        L_170e
L_157f:
	CMP        AX,43h
	JZ         L_1596
	CMP        AX,48h
	JNZ        L_158c
	JMP        L_1622
L_158c:
	CMP        AX,52h
	JNZ        L_1594
	JMP        L_169a
L_1594:
	JMP        L_15a8
L_1596:
	MOV        AX,8106h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       F_137c
	MOV        word ptr [BP + -6h],AX
	CMP        AX,0ffffh
	JNZ        L_15c6
L_15a8:
	CMP        word ptr [BP + -4h],0h
	JZ         L_15b1
	JMP        L_1507
L_15b1:
	CALL       SUB_0000_8670
	MOV        AX,81c8h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,81f2h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_1507
	db 90h
L_15c6:
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],50h
	JZ         L_15de
L_15d4:
	MOV        AX,3d5ah
	PUSH       AX
	CALL       F_0026
	JMP        L_15a8
	db 90h
L_15de:
	MOV        AX,810eh
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr DS:[5893h],5h
	JNZ        L_15f6
	MOV        AX,8112h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_1611
	db 90h
L_15f6:
	MOV        AX,812ah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 3d8eh]
	SUB        AH,AH
	MOV        DS:[0b118h],AX
	CALL       F_146a
	OR         AX,AX
	JNZ        L_15a8
L_1611:
	CALL       F_13b0
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],47h
	JMP        L_15a8
L_1622:
	MOV        AX,8148h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       F_137c
	MOV        word ptr [BP + -6h],AX
	CMP        AX,0ffffh
	JNZ        L_1637
	JMP        L_15a8
L_1637:
	MOV        SI,AX
	MOV        CL,5h
	SHL        SI,CL
	CMP        byte ptr [SI + 55b3h],44h
	JZ         L_15d4
	MOV        AX,word ptr [SI + 55bah]
	CMP        word ptr [SI + 55b8h],AX
	JZ         L_15d4
	MOV        AX,8150h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr DS:[5893h],5h
	JNZ        L_1666
	MOV        AX,8154h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_1684
	db 90h
L_1666:
	MOV        AX,816ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr DS:[0b114h]
	MOV        AL,byte ptr [BX + 3d86h]
	SUB        AH,AH
	MOV        DS:[0b118h],AX
	CALL       F_146a
	OR         AX,AX
	JZ         L_1684
	JMP        L_15a8
L_1684:
	CALL       F_13b0
	MOV        SI,word ptr [BP + -6h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,word ptr [SI + 55bah]
	MOV        word ptr [SI + 55b8h],AX
	JMP        L_15a8
	db 90h
L_169a:
	MOV        AX,817eh
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       F_137c
	MOV        word ptr [BP + -6h],AX
	CMP        AX,0ffffh
	JNZ        L_16af
	JMP        L_15a8
L_16af:
	MOV        BX,AX
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JZ         L_16bf
	JMP        L_15d4
L_16bf:
	MOV        AX,8188h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,818ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,81b6h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr DS:[0b114h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 3d96h]
	MOV        DS:[0b118h],AX
	CALL       F_146a
	OR         AX,AX
	JZ         L_16eb
	JMP        L_15a8
L_16eb:
	CALL       F_13b0
	PUSH       word ptr [BP + -6h]
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_dc66
	MOV        SI,word ptr [BP + -6h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,word ptr [SI + 55bah]
	MOV        word ptr [SI + 55b8h],AX
	CALL       SUB_0000_8670
	JMP        L_15a8
	db 90h
L_170e:
	MOV        AX,81c0h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        word ptr [BP + -4h],1h
	JMP        L_15a8
	db 90h
L_171e:
	MOV        AX,1h
	PUSH       AX
	CALL       F_0202
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 00h
	db 00h
	db 00h
	db 00h
F_14f8 ENDP
_TEXT ENDS
END
