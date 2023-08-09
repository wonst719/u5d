_TEXT SEGMENT BYTE 'CODE'
ORG 82deh
SUB_0000_82de:
ORG 75c0h
SUB_0000_75c0:
ORG 83dch
SUB_0000_83dc:
ORG 988ch
SUB_0000_988c:
ORG 0cc8eh
SUB_0000_cc8e:
ORG 7fach
SUB_0000_7fac:
ORG 9654h
SUB_0000_9654:
ORG 97e4h
SUB_0000_97e4:
ORG 8bfeh
SUB_0000_8bfe:
ORG 67e0h
SUB_0000_67e0:
ORG 69d4h
SUB_0000_69d4:
ORG 6a62h
SUB_0000_6a62:
ORG 976ch
SUB_0000_976c:
ORG 87c2h
SUB_0000_87c2:
ORG 8670h
SUB_0000_8670:
ORG 0b41ch
SUB_0000_b41c:
ORG 7e02h
SUB_0000_7e02:
ORG 78a8h
SUB_0000_78a8:
ORG 0a172h
SUB_0000_a172:
ORG 77aeh
SUB_0000_77ae:
ORG 742ah
SUB_0000_742a:
ORG 7c82h
SUB_0000_7c82:
ORG 7a0eh
SUB_0000_7a0e:
ORG 7a5eh
SUB_0000_7a5e:
ORG 7962h
SUB_0000_7962:
ORG 7edch
SUB_0000_7edc:
ORG 935ch
SUB_0000_935c:
ORG 93feh
SUB_0000_93fe:
ORG 0a6f8h
SUB_0000_a6f8:
ORG 6880h
SUB_0000_6880:
ORG 6816h
SUB_0000_6816:
ORG 6992h
SUB_0000_6992:
ORG 683eh
SUB_0000_683e:
ORG 68f6h
SUB_0000_68f6:
ORG 0b680h
SUB_0000_b680:
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
	SUB        SP,82h
	MOV        word ptr [BP + -2h],0h
	MOV        AX,71f8h
	PUSH       AX
	LEA        AX,[BP + -2h]
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	PUSH       AX
	CALL       SUB_0000_82de
	MOV        AX,7202h
	PUSH       AX
	LEA        AX,[BP + -82h]
	PUSH       AX
	MOV        AX,80h
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_82de
	LEA        AX,[BP + -82h]
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0000 ENDP
F_0042 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	MOV        AX,720ch
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_0058
	db 90h
L_0052:
	CMP        byte ptr [BP + -12h],4eh
	JZ         L_0062
L_0058:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -12h],AL
	CMP        AL,59h
	JNZ        L_0052
L_0062:
	CMP        byte ptr [BP + -12h],4eh
	JNZ        L_006e
	MOV        AX,7222h
	JMP        L_0157
L_006e:
	MOV        AX,7226h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        word ptr DS:[57aah],0h
	JNZ        L_007f
	JMP        L_015b
L_007f:
	MOV        AX,722ch
	PUSH       AX
	CALL       SUB_0000_75c0
	DEC        word ptr DS:[57aah]
	LEA        AX,[BP + -0eh]
	PUSH       AX
	MOV        AX,0ch
	PUSH       AX
	CALL       SUB_0000_988c
	CMP        byte ptr [BP + -0eh],0h
	JNZ        L_00a2
	MOV        AX,7238h
	JMP        L_0157
	db 90h
L_00a2:
	MOV        AX,7242h
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_cc8e
	CMP        AX,0ffffh
	JG         L_0102
	MOV        AX,724ch
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_cc8e
	CMP        AX,0ffffh
	JG         L_0102
	MOV        AX,7254h
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_cc8e
	CMP        AX,0ffffh
	JG         L_0102
	MOV        AX,7260h
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_cc8e
	CMP        AX,0ffffh
	JG         L_0102
	MOV        AX,7266h
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_cc8e
	CMP        AX,0ffffh
	JG         L_0102
	MOV        AX,726eh
	PUSH       AX
	LEA        AX,[BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_cc8e
	CMP        AX,0ffffh
	JLE        L_0154
L_0102:
	CMP        byte ptr DS:[5893h],16h
	JZ         L_0116
	CMP        byte ptr DS:[5893h],1fh
	JZ         L_0116
	MOV        AX,7274h
	JMP        L_0157
	db 90h
L_0116:
	MOV        AX,7284h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0bb8h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	CALL       SUB_0000_7fac
	CALL       SUB_0000_9654
	MOV        word ptr [BP + -10h],AX
	MOV        AX,10h
	PUSH       AX
	PUSH       AX
	MOV        AL,byte ptr [BP + 8h]
	SUB        AH,AH
	INC        AX
	PUSH       AX
	MOV        AL,byte ptr [BP + 6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BP + 4h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -10h]
	CALL       SUB_0000_97e4
	JMP        L_015b
	db 90h
L_0154:
	MOV        AX,728ch
L_0157:
	PUSH       AX
	CALL       SUB_0000_75c0
L_015b:
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_0042 ENDP
F_0162 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,729ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,72b4h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_8bfe
	MOV        word ptr [BP + -2h],AX
	INC        AX
	JNZ        L_0184
	MOV        AX,72c6h
	JMP        L_01a3
L_0184:
	MOV        BX,word ptr [BP + -2h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b3h]
	MOV        byte ptr [BP + -4h],AL
	CMP        AL,44h
	JZ         L_019a
	CMP        AL,53h
	JNZ        L_01a0
L_019a:
	MOV        AX,72ceh
	JMP        L_01a3
	db 90h
L_01a0:
	MOV        AX,72e0h
L_01a3:
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0162 ENDP
F_01ac PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,word ptr [BP + 6h]
	SHL        AX,CL
	MOV        word ptr [BP + -10h],AX
	ADD        AX,6h
	PUSH       AX
	MOV        AX,word ptr [BP + -0eh]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_69d4
	MOV        word ptr [BP + -2h],0h
	MOV        AX,word ptr [BP + -10h]
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,word ptr [BP + -0eh]
	MOV        word ptr [BP + -0ch],AX
L_01ec:
	SUB        SI,SI
	MOV        AX,word ptr [BP + -0ch]
	ADD        AX,word ptr [BP + -2h]
	ADD        AX,7h
	MOV        word ptr [BP + -6h],AX
	MOV        DI,word ptr [BP + -0ah]
L_01fd:
	MOV        AX,DI
	ADD        AX,SI
	CMP        AX,0b0h
	JG         L_0214
	MOV        AX,DI
	ADD        AX,SI
	ADD        AX,7h
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	CALL       SUB_0000_69d4
L_0214:
	INC        SI
	CMP        SI,3h
	JL         L_01fd
	MOV        word ptr [BP + -4h],SI
	INC        word ptr [BP + -2h]
	CMP        word ptr [BP + -2h],3h
	JL         L_01ec
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	CMP        SI,0adh
	JG         L_0243
	LEA        AX,[SI + 0ah]
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,CL
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_69d4
L_0243:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_01ac ENDP
F_024c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -2h],AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,CL
	MOV        word ptr [BP + -4h],AX
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_67e0
	CMP        word ptr [BP + -2h],2h
	JLE        L_0289
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,5h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ah
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ch
	PUSH       AX
	CALL       SUB_0000_6a62
L_0289:
	CMP        word ptr [BP + -2h],2h
	JLE        L_02a7
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,6h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ah
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ch
	PUSH       AX
	CALL       SUB_0000_6a62
L_02a7:
	CMP        word ptr [BP + -2h],2h
	JLE        L_02c5
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,7h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,8h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ch
	PUSH       AX
	CALL       SUB_0000_6a62
L_02c5:
	CMP        word ptr [BP + -2h],0afh
	JG         L_02e4
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,8h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,8h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ch
	PUSH       AX
	CALL       SUB_0000_6a62
L_02e4:
	CMP        word ptr [BP + -2h],0aeh
	JG         L_0303
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,9h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,6h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ah
	PUSH       AX
	CALL       SUB_0000_6a62
L_0303:
	CMP        word ptr [BP + -2h],0adh
	JG         L_0322
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,0ah
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,6h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,0ah
	PUSH       AX
	CALL       SUB_0000_6a62
L_0322:
	CMP        word ptr [BP + -2h],0ach
	JG         L_0341
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,0bh
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,5h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_6a62
L_0341:
	CMP        word ptr [BP + -2h],0abh
	JG         L_0360
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,0ch
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,5h
	PUSH       AX
	MOV        AX,word ptr [BP + -4h]
	ADD        AX,7h
	PUSH       AX
	CALL       SUB_0000_6a62
L_0360:
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_024c ENDP
F_0366 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ah
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[587fh],6h
	JC         L_03aa
	CMP        byte ptr DS:[587fh],12h
	JNC        L_03aa
	MOV        AX,72f0h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr DS:[587bh],0ffh
	JNZ        L_0397
	CALL       SUB_0000_976c
	OR         AX,AX
	JNZ        L_0397
	MOV        AL,DS:[5876h]
	MOV        DS:[587bh],AL
L_0397:
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_87c2
	CALL       SUB_0000_8670
	JMP        L_04fb
L_03aa:
	MOV        byte ptr DS:[24e6h],1h
	MOV        word ptr [BP + -4h],0bh
	SUB        SI,SI
L_03b6:
	SUB        DI,DI
	MOV        AX,0ffffh
	MOV        CX,5h
	PUSH       DI
	LEA        DI,[SI + 0ab02h]
	PUSH       DS
	POP        ES
	REP STOSW
	STOSB
	POP        DI
	MOV        DI,0bh
	ADD        SI,20h
	CMP        SI,160h
	JL         L_03b6
	MOV        word ptr [BP + -8h],DI
	MOV        byte ptr DS:[0ac47h],59h
	CALL       SUB_0000_b41c
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        word ptr [BP + -4h],50h
	MOV        SI,50h
L_03f2:
	MOV        AX,9h
	PUSH       AX
	MOV        AX,0b6h
	PUSH       AX
	CALL       SUB_0000_7e02
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	MOV        AX,0ach
	PUSH       AX
	CALL       SUB_0000_7e02
	PUSH       AX
	CALL       SUB_0000_69d4
	DEC        SI
	JNZ        L_03f2
	MOV        word ptr [BP + -10h],0h
	MOV        word ptr [BP + -16h],0h
L_041a:
	MOV        AX,DS:[5874h]
	CWD
	MOV        CX,64h
	IDIV       CX
	MOV        DI,DX
	MOV        AL,DS:[587dh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,DS:[587eh]
	MOV        word ptr [BP + -14h],AX
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX + 3750h]
	MOV        word ptr [BP + -2h],AX
L_043c:
	CMP        DI,27h
	JG         L_045b
	CMP        DI,27h
	JNZ        L_044b
	CMP        SI,4h
	JG         L_045b
L_044b:
	CMP        DI,27h
	JNZ        L_0490
	CMP        SI,4h
	JNZ        L_0490
	CMP        word ptr [BP + -14h],5h
	JLE        L_0490
L_045b:
	DEC        word ptr [BP + -14h]
	JNZ        L_0466
	MOV        word ptr [BP + -14h],1ch
	DEC        SI
L_0466:
	OR         SI,SI
	JNZ        L_046e
	MOV        SI,0dh
	DEC        DI
L_046e:
	MOV        AX,word ptr [BP + -16h]
	MOV        word ptr [BP + -18h],AX
	MOV        DX,AX
	MOV        CX,word ptr [BP + -2h]
L_0479:
	DEC        CX
	JNS        L_047f
	MOV        CX,15h
L_047f:
	MOV        BX,DX
	ADD        BX,CX
	CMP        byte ptr [BX + 3760h],0h
	JZ         L_0479
	MOV        word ptr [BP + -2h],CX
	JMP        L_043c
	db 90h
L_0490:
	MOV        word ptr [BP + -0eh],DI
	MOV        word ptr [BP + -12h],SI
	MOV        AX,word ptr [BP + -2h]
	INC        AX
	MOV        word ptr [BP + -6h],AX
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX + 3758h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	PUSH       word ptr [BP + -6h]
	PUSH       AX
	CALL       F_01ac
	DEC        word ptr [BP + -6h]
	SUB        SI,SI
	MOV        AX,word ptr [BP + -10h]
	INC        AX
	MOV        word ptr [BP + -1ah],AX
	MOV        DI,word ptr [BP + -0ch]
L_04bf:
	MOV        AL,byte ptr [SI + 58c8h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -1ah]
	JNZ        L_04d1
	PUSH       word ptr [BP + -6h]
	PUSH       DI
	CALL       F_024c
L_04d1:
	INC        SI
	CMP        SI,3h
	JL         L_04bf
	MOV        word ptr [BP + -8h],SI
	ADD        word ptr [BP + -16h],16h
	INC        word ptr [BP + -10h]
	CMP        word ptr [BP + -10h],8h
	JGE        L_04ea
	JMP        L_041a
L_04ea:
	MOV        AX,72fah
	PUSH       AX
	CALL       SUB_0000_75c0
L_04f1:
	CALL       SUB_0000_78a8
	MOV        byte ptr [BP + -0ah],AL
	OR         AL,AL
	JZ         L_04f1
L_04fb:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0366 ENDP
F_0502 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + 6h]
	MOV        SI,word ptr [BP + 8h]
L_0510:
	CMP        SI,0e0h
	JZ         L_0522
	CMP        SI,0e1h
	JZ         L_0522
	CMP        SI,0e2h
	JNZ        L_0552
L_0522:
	MOV        AX,SI
	CMP        AX,0e0h
	JZ         L_0536
	CMP        AX,0e1h
	JZ         L_054a
	CMP        AX,0e2h
	JZ         L_054e
	JMP        L_0539
	db 90h
L_0536:
	DEC        word ptr [BP + 4h]
L_0539:
	PUSH       DI
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_a172
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        SI,AX
	JMP        L_0510
L_054a:
	INC        DI
	JMP        L_0539
	db 90h
L_054e:
	DEC        DI
	JMP        L_0539
	db 90h
L_0552:
	MOV        word ptr [BP + 6h],DI
	MOV        word ptr [BP + 8h],SI
	CMP        SI,59h
	JNZ        L_0564
	CALL       F_0366
	JMP        L_069c
	db 90h
L_0564:
	CMP        word ptr [BP + 8h],0a1h
	JNZ        L_0580
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       F_0042
	JMP        L_069c
	db 90h
L_0580:
	MOV        AL,byte ptr [BP + 8h]
	AND        AL,0fch
	CMP        AL,0d8h
	JNZ        L_0590
	CALL       F_0162
	JMP        L_069c
	db 90h
L_0590:
	PUSH       word ptr [BP + 8h]
	CALL       F_0000
	MOV        AL,byte ptr [BP + 8h]
	AND        AL,0feh
	CMP        AL,0fah
	JNZ        L_05f6
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	MOV        CL,0ch
	DIV        CL
	MOV        AL,AH
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JNZ        L_05b8
	MOV        word ptr [BP + -2h],0ch
L_05b8:
	PUSH       word ptr [BP + -2h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_77ae
	MOV        AX,3ah
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AL,DS:[5881h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	CALL       SUB_0000_77ae
	CMP        byte ptr DS:[587fh],0bh
	JBE        L_05f0
	MOV        AX,730ah
L_05e8:
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_069c
	db 90h
L_05f0:
	MOV        AX,7310h
	JMP        L_05e8
	db 90h
L_05f6:
	CMP        word ptr [BP + 8h],0deh
	JNZ        L_0626
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	CMP        AX,1eh
	JZ         L_0614
	CMP        AX,1fh
	JZ         L_061a
	CMP        AX,20h
	JZ         L_0620
	JMP        L_069c
L_0614:
	MOV        AX,7316h
	JMP        L_05e8
	db 90h
L_061a:
	MOV        AX,731eh
	JMP        L_05e8
	db 90h
L_0620:
	MOV        AX,7324h
	JMP        L_05e8
	db 90h
L_0626:
	CMP        word ptr [BP + 8h],0dfh
	JNZ        L_068e
	MOV        AX,word ptr [BP + 6h]
	CMP        AX,7eh
	JZ         L_065a
	JG         L_0678
	CMP        AX,3ah
	JZ         L_0666
	CMP        AX,48h
	JZ         L_0654
	CMP        AX,5bh
	JZ         L_064e
	JMP        L_069c
L_0648:
	MOV        AX,732eh
	JMP        L_05e8
	db 90h
L_064e:
	MOV        AX,7336h
	JMP        L_05e8
	db 90h
L_0654:
	MOV        AX,7340h
	JMP        L_05e8
	db 90h
L_065a:
	MOV        AX,734ah
	JMP        L_05e8
	db 90h
L_0660:
	MOV        AX,7352h
	JMP        L_05e8
	db 90h
L_0666:
	MOV        AX,735ch
	JMP        L_05e8
L_066c:
	MOV        AX,7364h
	JMP        L_05e8
L_0672:
	MOV        AX,736eh
	JMP        L_05e8
L_0678:
	CMP        AX,80h
	JZ         L_0672
	CMP        AX,9ch
	JZ         L_0660
	CMP        AX,0efh
	JZ         L_066c
	CMP        AX,0f0h
	JZ         L_0648
	JMP        L_069c
L_068e:
	CALL       SUB_0000_7c82
	OR         AX,AX
	JZ         L_069c
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
L_069c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0502 ENDP
F_06a4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,82h
	MOV        word ptr [BP + -2h],0h
	MOV        AX,7374h
	PUSH       AX
	LEA        AX,[BP + -2h]
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	ADD        AH,2h
	PUSH       AX
	CALL       SUB_0000_82de
	MOV        AX,737eh
	PUSH       AX
	LEA        AX,[BP + -82h]
	PUSH       AX
	MOV        AX,80h
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_82de
	LEA        AX,[BP + -82h]
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_7c82
	OR         AX,AX
	JZ         L_06f1
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
L_06f1:
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_06a4 ENDP
F_06f8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	CMP        word ptr [BP + 4h],-1h
	JNZ        L_0724
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,742ah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,745eh
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	JMP        L_07dc
L_0724:
	ADD        word ptr [BP + 4h],4h
	MOV        SI,word ptr [BP + 4h]
	JMP        L_0731
	db 90h
L_072e:
	ADD        SI,6h
L_0731:
	CMP        byte ptr [SI + 0b21eh],0ah
	JZ         L_072e
	MOV        word ptr [BP + 4h],SI
	MOV        DI,SI
L_073d:
	MOV        AL,byte ptr [DI + 0b21eh]
	MOV        byte ptr [BP + -4h],AL
	TEST       byte ptr [BP + -4h],80h
	JZ         L_074e
	SUB        AX,AX
	JMP        L_0751
L_074e:
	MOV        AX,1h
L_0751:
	PUSH       AX
	CALL       SUB_0000_7a0e
	CMP        byte ptr [BP + -4h],26h
	JZ         L_0761
	CMP        byte ptr [BP + -4h],27h
	JNZ        L_0766
L_0761:
	MOV        AX,6ch
	JMP        L_07b6
L_0766:
	CMP        byte ptr [BP + -4h],29h
	JC         L_079a
	CMP        byte ptr [BP + -4h],31h
	JA         L_079a
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        BL,byte ptr [BP + -4h]
	SUB        BH,BH
	SHL        BX,1h
	MOV        SI,word ptr [BX + 37beh]
	JMP        L_0790
L_0786:
	INC        SI
	MOV        AL,byte ptr [SI + -1h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_742a
L_0790:
	CMP        byte ptr [SI],0h
	JNZ        L_0786
	MOV        word ptr [BP + -2h],SI
	JMP        L_07ba
L_079a:
	CMP        byte ptr [BP + -4h],0dh
	JNZ        L_07ae
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -4h],AL
	JMP        L_07ba
L_07ae:
	MOV        AL,byte ptr [BP + -4h]
	SUB        AH,AH
	AND        AX,7fh
L_07b6:
	PUSH       AX
	CALL       SUB_0000_742a
L_07ba:
	INC        DI
	CMP        byte ptr [DI + 0b21eh],0h
	JZ         L_07c5
	JMP        L_073d
L_07c5:
	MOV        word ptr [BP + 4h],DI
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	CALL       SUB_0000_7c82
	OR         AX,AX
	JZ         L_07dc
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
L_07dc:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_06f8 ENDP
F_07e4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,48h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h
	CMP        byte ptr DS:[5893h],4h
	JZ         L_07fb
	JMP        L_08de
L_07fb:
	CMP        byte ptr [BP + 8h],0h
	JZ         L_0804
	JMP        L_08de
L_0804:
	CMP        byte ptr [BP + 6h],11h
	JZ         L_080d
	JMP        L_08de
L_080d:
	CMP        byte ptr [BP + 4h],15h
	JZ         L_0816
	JMP        L_08de
L_0816:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,7492h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,74a8h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,74b4h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,0eh
	PUSH       AX
	CALL       SUB_0000_7a5e
	PUSH       AX
	CALL       SUB_0000_7962
	MOV        AX,74b8h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        SI,SI
	MOV        DI,55a8h
L_0856:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JNC        L_0889
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	PUSH       DI
	CALL       SUB_0000_7edc
	CWD
	SUB        AX,DX
	SAR        AX,1h
	SUB        AX,7h
	NEG        AX
	PUSH       AX
	CALL       SUB_0000_7a5e
	PUSH       AX
	CALL       SUB_0000_7962
	PUSH       DI
	CALL       SUB_0000_75c0
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
L_0889:
	MOV        AX,0eh
	PUSH       AX
	CALL       SUB_0000_7a5e
	PUSH       AX
	CALL       SUB_0000_7962
	MOV        AX,74bch
	PUSH       AX
	CALL       SUB_0000_75c0
	ADD        DI,20h
	INC        SI
	CMP        SI,3h
	JL         L_0856
	MOV        word ptr [BP + -4h],SI
	MOV        AX,0eh
	PUSH       AX
	CALL       SUB_0000_7a5e
	PUSH       AX
	CALL       SUB_0000_7962
	MOV        AX,74c0h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,74c4h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,74d2h
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	JMP        L_0993
	db 90h
L_08de:
	MOV        AX,74e6h
	PUSH       AX
	LEA        AX,[BP + -46h]
	PUSH       AX
	MOV        AX,42h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_82de
	MOV        SI,word ptr DS:[5893h]
	AND        SI,0ffh
	SHL        SI,1h
	MOV        AX,word ptr [BP + SI + -46h]
	MOV        word ptr [BP + -4h],AX
	MOV        CX,7d0h
	MOV        DI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	MOV        AX,0ffh
	REP STOSB
	CMP        word ptr [BP + -4h],0h
	JNZ        L_0920
	MOV        AX,0ffffh
	PUSH       AX
	CALL       F_06f8
	JMP        L_0993
	db 90h
	db 90h
L_0920:
	MOV        AX,74f0h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_82de
	MOV        word ptr [BP + -4h],0h
	MOV        DI,word ptr [BP + -2h]
	MOV        SI,word ptr [BP + -4h]
L_093d:
	MOV        AL,byte ptr [BP + 8h]
	CMP        byte ptr [SI + 0b21fh],AL
	JNZ        L_0960
	MOV        AL,byte ptr [BP + 6h]
	CMP        byte ptr [SI + 0b220h],AL
	JNZ        L_0960
	MOV        AL,byte ptr [BP + 4h]
	CMP        byte ptr [SI + 0b221h],AL
	JNZ        L_0960
	PUSH       SI
	CALL       F_06f8
	INC        DI
	JMP        L_0989
	db 90h
L_0960:
	ADD        SI,4h
L_0963:
	MOV        BX,SI
	INC        SI
	CMP        byte ptr [BX + 0b21eh],0h
	JNZ        L_0963
	CMP        byte ptr [SI + 0b21eh],0ffh
	JNZ        L_097a
	MOV        AX,1h
	JMP        L_097c
	db 90h
L_097a:
	SUB        AX,AX
L_097c:
	MOV        DI,AX
	OR         DI,DI
	JZ         L_0989
	MOV        AX,0ffffh
	PUSH       AX
	CALL       F_06f8
L_0989:
	OR         DI,DI
	JZ         L_093d
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -4h],SI
L_0993:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_07e4 ENDP
F_099c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	CALL       SUB_0000_935c
	OR         AX,AX
	JNZ        L_09ac
	JMP        L_0a98
L_09ac:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	MOV        word ptr [BP + -8h],AX
	PUSH       word ptr [BP + -6h]
	PUSH       AX
	CALL       SUB_0000_a172
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_93fe
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + -2h],29h
	JNZ        L_0a40
	CALL       SUB_0000_a6f8
	MOV        word ptr [BP + -0ah],AX
	INC        AX
	JNZ        L_09f6
	JMP        L_0a98
L_09f6:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,word ptr [BP + -0ah]
	MOV        CL,5h
	SHL        BX,CL
	MOV        CL,byte ptr [BX + 55b6h]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_0a2a
	MOV        AX,74fah
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       word ptr [BP + -0ah]
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_87c2
	CALL       SUB_0000_8670
	JMP        L_0a98
	db 90h
	db 90h
L_0a2a:
	MOV        AX,750ah
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       F_10fc
	JMP        L_0a98
L_0a40:
	MOV        AX,751ch
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        word ptr [BP + -4h],0h
	JZ         L_0a56
	PUSH       word ptr [BP + -4h]
	CALL       F_06a4
	JMP        L_0a98
	db 90h
L_0a56:
	MOV        AX,word ptr [BP + -2h]
	CMP        AX,0a0h
	JZ         L_0a6a
	JG         L_0a82
	CMP        AX,89h
	JL         L_0a8c
	CMP        AX,8ah
	JG         L_0a8c
L_0a6a:
	MOV        AX,752ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	CALL       F_07e4
	JMP        L_0a98
L_0a82:
	CMP        AX,0a4h
	JZ         L_0a6a
	CMP        AX,0f8h
	JZ         L_0a6a
L_0a8c:
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	CALL       F_0502
L_0a98:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_099c ENDP
F_0a9c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,word ptr [BP + 6h]
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,20h
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,20h
	MOV        DS:[5878h],AX
	POP        BP
	RET        4h
	db 90h
	; Func
F_0a9c ENDP
F_0abe PROC NEAR
	MOV        AX,DS:[13b4h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_69d4
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_69d4
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_69d4
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_69d4
	RET
	db 0A1h
	db 0B4h
	db 13h
	db 05h
	db 08h
	db 00h
	db 50h
	db 0E8h
	db 0D2h
	db 5Ch
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 0A1h
	db 76h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 0A1h
	db 78h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 0E8h
	db 0EFh
	db 5Ch
	db 0C3h
	db 56h
	db 0FFh
	db 36h
	db 0B0h
	db 13h
	db 0E8h
	db 0B0h
	db 5Ch
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 0A1h
	db 78h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 0E8h
	db 3Ah
	db 5Dh
	db 8Bh
	db 36h
	db 76h
	db 58h
	db 83h
	db 0C6h
	db 02h
	db 56h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 56h
	db 0A1h
	db 78h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 0E8h
	db 23h
	db 5Dh
	db 5Eh
	db 0C3h
	db 90h
	db 56h
	db 0FFh
	db 36h
	db 0B0h
	db 13h
	db 0E8h
	db 78h
	db 5Ch
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 0A1h
	db 76h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 0E8h
	db 02h
	db 5Dh
	db 8Bh
	db 36h
	db 78h
	db 58h
	db 83h
	db 0C6h
	db 03h
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 56h
	db 0A1h
	db 76h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 56h
	db 0E8h
	db 0EBh
	db 5Ch
	db 5Eh
	db 0C3h
	db 90h
	db 56h
	db 0FFh
	db 36h
	db 0B0h
	db 13h
	db 0E8h
	db 40h
	db 5Ch
	db 8Bh
	db 36h
	db 78h
	db 58h
	db 46h
	db 0A1h
	db 76h
	db 58h
	db 40h
	db 50h
	db 56h
	db 0A1h
	db 76h
	db 58h
	db 05h
	db 02h
	db 00h
	db 50h
	db 56h
	db 0E8h
	db 0CAh
	db 5Ch
	db 8Bh
	db 36h
L_0bb8:
	JS         L_0c12
	ADD        SI,2h
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       SI
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_6880
	POP        SI
	RET
	db 56h
	db 0FFh
	db 36h
	db 0B0h
	db 13h
	db 0E8h
	db 08h
	db 5Ch
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 0A1h
	db 76h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 0FFh
	db 36h
	db 78h
	db 58h
	db 0E8h
	db 92h
	db 5Ch
	db 8Bh
	db 36h
	db 78h
	db 58h
	db 83h
	db 0C6h
	db 03h
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 56h
	db 0A1h
	db 76h
	db 58h
	db 05h
	db 03h
	db 00h
	db 50h
	db 56h
	db 0E8h
	db 7Bh
	db 5Ch
	db 0FFh
	db 36h
	db 76h
	db 58h
	db 0A1h
	db 78h
	db 58h
	db 40h
	db 50h
	db 0FFh
	db 36h
	db 76h
	db 58h
L_0c12:
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        SI,word ptr DS:[5876h]
	ADD        SI,3h
	PUSH       SI
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	PUSH       SI
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_6880
	POP        SI
	RET
	; Func
F_0abe ENDP
F_0c36 PROC NEAR
	PUSH       SI
	PUSH       word ptr DS:[13b8h]
	CALL       SUB_0000_67e0
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_6880
	MOV        SI,word ptr DS:[5878h]
	INC        SI
	PUSH       word ptr DS:[5876h]
	PUSH       SI
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_6880
	MOV        SI,word ptr DS:[5878h]
	ADD        SI,2h
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	PUSH       SI
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_6880
	MOV        SI,word ptr DS:[5878h]
	ADD        SI,3h
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	PUSH       SI
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_6880
	POP        SI
	RET
	db 90h
	; Func
F_0c36 ENDP
F_0c9c PROC NEAR
	PUSH       SI
	MOV        AX,DS:[13b4h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_6880
	MOV        SI,word ptr DS:[5878h]
	ADD        SI,2h
	PUSH       word ptr DS:[5876h]
	PUSH       SI
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_6880
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_69d4
	PUSH       word ptr DS:[5876h]
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_69d4
	POP        SI
	RET
	db 90h
	; Func
F_0c9c ENDP
F_0cf4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ah
	PUSH       DI
	PUSH       SI
	MOV        DX,8h
	MOV        word ptr [BP + -0ah],4h
	MOV        AX,DS:[13b2h]
	ADD        AX,DX
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,DS:[13b4h]
	ADD        AX,DX
	MOV        word ptr [BP + -10h],AX
	MOV        BX,word ptr [BP + 4h]
	AND        BX,0fh
	MOV        AL,byte ptr [BX + 3822h]
	SUB        AH,AH
	MOV        word ptr [BP + -12h],AX
	MOV        AL,byte ptr [BP + 4h]
	AND        AL,0f0h
	MOV        byte ptr [BP + -14h],AL
	MOV        DI,BP
	SUB        DI,DX
	LEA        AX,[BP + -8h]
	MOV        word ptr [BP + -18h],AX
	MOV        SI,BP
	SUB        SI,DX
	MOV        CX,word ptr DS:[52c8h]
L_0d3e:
	CMP        byte ptr [BP + -14h],60h
	JNZ        L_0d52
	MOV        AX,DX
	TEST       word ptr [BP + -12h],AX
	JNZ        L_0d52
	MOV        AX,word ptr [BP + -10h]
	MOV        word ptr [DI],AX
	JMP        L_0d6b
L_0d52:
	OR         CX,CX
	JZ         L_0d5b
	CMP        CX,3h
	JNZ        L_0d66
L_0d5b:
	MOV        BX,word ptr [BP + -18h]
	MOV        AX,DS:[13b6h]
	MOV        word ptr [BX],AX
	JMP        L_0d6b
	db 90h
L_0d66:
	MOV        AX,word ptr [BP + -0eh]
	MOV        word ptr [SI],AX
L_0d6b:
	SAR        DX,1h
	ADD        DI,2h
	ADD        word ptr [BP + -18h],2h
	ADD        SI,2h
	CMP        SI,BP
	JC         L_0d3e
	MOV        word ptr [BP + -0ch],DX
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_69d4
	PUSH       word ptr [BP + -6h]
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_69d4
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_69d4
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_69d4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0cf4 ENDP
F_0dda PROC NEAR
	CMP        word ptr DS:[52c8h],0h
	JZ         L_0de8
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_0dee
L_0de8:
	PUSH       word ptr DS:[13b6h]
	JMP        L_0df5
L_0dee:
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
L_0df5:
	CALL       SUB_0000_67e0
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_69d4
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_69d4
	RET
	db 90h
	; Func
F_0dda ENDP
F_0e16 PROC NEAR
	MOV        AX,DS:[13b4h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_69d4
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_69d4
	CMP        word ptr DS:[52c8h],0h
	JZ         L_0e49
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_0e50
L_0e49:
	PUSH       word ptr DS:[13b6h]
	JMP        L_0e57
	db 90h
L_0e50:
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
L_0e57:
	CALL       SUB_0000_67e0
	PUSH       word ptr DS:[5876h]
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_69d4
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_69d4
	RET
	; Func
F_0e16 ENDP
F_0e7a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	CALL       F_0abe
	PUSH       word ptr DS:[13aeh]
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_6816
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,byte ptr [BX + 3812h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	TEST       byte ptr [BP + -2h],8h
	JZ         L_0ecf
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_6880
L_0ecf:
	TEST       byte ptr [BP + -2h],4h
	JZ         L_0eed
	MOV        SI,word ptr DS:[5876h]
	ADD        SI,3h
	PUSH       SI
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	PUSH       SI
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_6880
L_0eed:
	TEST       byte ptr [BP + -2h],2h
	JZ         L_0f0b
	MOV        SI,word ptr DS:[5878h]
	ADD        SI,3h
	MOV        AX,DS:[5876h]
	INC        AX
	PUSH       AX
	PUSH       SI
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_6880
L_0f0b:
	TEST       byte ptr [BP + -2h],1h
	JZ         L_0f28
	PUSH       word ptr DS:[5876h]
	MOV        AX,DS:[5878h]
	INC        AX
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_6880
L_0f28:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,22h
	JZ         L_0f48
	CMP        AX,23h
	JZ         L_0f5a
	CMP        AX,24h
	JZ         L_0f66
	CMP        AX,25h
	JZ         L_0f6e
	JMP        L_0f76
	db 90h
L_0f48:
	MOV        AX,DS:[5876h]
	INC        AX
L_0f4c:
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,2h
L_0f53:
	PUSH       AX
	CALL       SUB_0000_69d4
	JMP        L_0f76
	db 90h
L_0f5a:
	MOV        AX,DS:[5876h]
	INC        AX
L_0f5e:
	PUSH       AX
	MOV        AX,DS:[5878h]
	INC        AX
	JMP        L_0f53
	db 90h
L_0f66:
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	JMP        L_0f5e
L_0f6e:
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	JMP        L_0f4c
L_0f76:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0e7a ENDP
F_0f7e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        BX,word ptr [BP + 8h]
	MOV        AL,byte ptr [BX + 1d1ah]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       F_0a9c
	MOV        AX,word ptr [BP + -2h]
	CMP        AX,8h
	JZ         L_1002
	JLE        L_0fa7
	JMP        L_10ae
L_0fa7:
	CMP        AX,7h
	JBE        L_0faf
	JMP        L_10f4
L_0faf:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0b32eh]
	db 0E9h
	db 3Ah
	db 01h
	db 0E8h
	db 01h
	db 0FBh
	db 0E9h
	db 34h
	db 01h
	db 0E8h
	db 41h
	db 0FBh
	db 0E9h
	db 2Eh
	db 01h
	db 0FFh
	db 36h
	db 0AEh
	db 13h
L_0fca:
	CALL       SUB_0000_67e0
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_6816
	JMP        L_10f4
	db 90h
	db 0E8h
	db 73h
	db 0FBh
	db 0E9h
	db 04h
	db 01h
	db 0E8h
	db 0A5h
	db 0FBh
	db 0E9h
	db 0FEh
	db 00h
	db 0E8h
	db 0D7h
	db 0FBh
	db 0E9h
	db 0F8h
	db 00h
L_0ffc:
	PUSH       word ptr DS:[13b0h]
	JMP        L_0fca
L_1002:
	CALL       F_0c36
	JMP        L_10f4
L_1008:
	CALL       F_0c9c
	JMP        L_10f4
L_100e:
	PUSH       word ptr [BP + 8h]
	CALL       F_0cf4
	JMP        L_10f4
	db 90h
L_1018:
	CALL       F_0dda
	JMP        L_10f4
L_101e:
	CMP        word ptr DS:[52c8h],0h
	JZ         L_102c
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_1032
L_102c:
	PUSH       word ptr DS:[13b6h]
	JMP        L_1039
L_1032:
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
L_1039:
	CALL       SUB_0000_67e0
	MOV        AX,DS:[5876h]
	ADD        AX,2h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,2h
	PUSH       AX
	CALL       SUB_0000_69d4
	JMP        L_10f4
L_1050:
	CALL       F_0e16
	JMP        L_10f4
L_1056:
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0
	MOV        SI,word ptr DS:[5876h]
	INC        SI
	PUSH       SI
	PUSH       word ptr DS:[5878h]
	PUSH       SI
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        SI,word ptr DS:[5876h]
	ADD        SI,2h
	PUSH       SI
	PUSH       word ptr DS:[5878h]
	PUSH       SI
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_6880
	JMP        L_10f4
	db 90h
L_108c:
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
	JMP        L_0fca
L_1096:
	PUSH       word ptr [BP + 8h]
	CALL       F_0e7a
	JMP        L_10f4
	db 84h
	db 0B3h
	db 4Ah
	db 0B2h
	db 50h
	db 0B2h
	db 56h
	db 0B2h
	db 7Ah
	db 0B2h
	db 80h
	db 0B2h
	db 86h
	db 0B2h
	db 8Ch
	db 0B2h
L_10ae:
	CMP        AX,0ch
	JNZ        L_10b6
	JMP        L_101e
L_10b6:
	JG         L_10d2
	CMP        AX,9h
	JNZ        L_10c0
	JMP        L_1008
L_10c0:
	CMP        AX,0ah
	JNZ        L_10c8
	JMP        L_100e
L_10c8:
	CMP        AX,0bh
	JNZ        L_10d0
	JMP        L_1018
L_10d0:
	JMP        L_10f4
L_10d2:
	CMP        AX,0dh
	JNZ        L_10da
	JMP        L_1050
L_10da:
	CMP        AX,0eh
	JNZ        L_10e2
	JMP        L_1056
L_10e2:
	CMP        AX,0fh
	JZ         L_108c
	CMP        AX,10h
	JZ         L_1096
	CMP        AX,5ah
	JNZ        L_10f4
	JMP        L_0ffc
L_10f4:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_0f7e ENDP
F_10fc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[589bh]
	SUB        AH,AH
	SUB        word ptr [BP + 6h],AX
	MOV        AL,DS:[589ch]
	SUB        word ptr [BP + 4h],AX
	AND        byte ptr [BP + 6h+1h],AH
	AND        byte ptr [BP + 4h+1h],AH
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6816
	SUB        DI,DI
L_1134:
	SUB        SI,SI
L_1136:
	MOV        AL,DS:[589bh]
	SUB        AH,AH
	ADD        AX,SI
	PUSH       AX
	MOV        AL,DS:[589ch]
	SUB        AH,AH
	ADD        AX,DI
	PUSH       AX
	CALL       SUB_0000_a172
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	PUSH       SI
	PUSH       DI
	CALL       F_0f7e
	INC        SI
	CMP        SI,20h
	JL         L_1136
	MOV        word ptr [BP + -4h],SI
	INC        DI
	CMP        DI,20h
	JL         L_1134
	MOV        word ptr [BP + -2h],DI
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_683e
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6992
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       F_0a9c
	SUB        SI,SI
	JMP        L_11b6
L_118e:
	INC        SI
	CMP        SI,4h
	JNZ        L_11b6
	SUB        SI,SI
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	MOV        AX,DS:[5876h]
	ADD        AX,3h
	PUSH       AX
	MOV        AX,DS:[5878h]
	ADD        AX,3h
	PUSH       AX
	CALL       SUB_0000_68f6
L_11b6:
	CALL       SUB_0000_78a8
	OR         AX,AX
	JZ         L_118e
	MOV        word ptr [BP + -2h],SI
	CALL       SUB_0000_b680
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	db 00h
	db 00h
	db 00h
	db 00h
F_10fc ENDP
_TEXT ENDS
END
