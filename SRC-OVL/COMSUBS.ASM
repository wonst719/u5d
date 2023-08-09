_TEXT SEGMENT BYTE 'CODE'
ORG 9ce6h
SUB_0000_9ce6:
ORG 58deh
SUB_0000_58de:
ORG 3eb2h
SUB_0000_3eb2:
ORG 9ba2h
SUB_0000_9ba2:
ORG 3670h
SUB_0000_3670:
ORG 34dah
SUB_0000_34da:
ORG 4720h
SUB_0000_4720:
ORG 3fb2h
SUB_0000_3fb2:
ORG 9cb6h
SUB_0000_9cb6:
ORG 9b96h
SUB_0000_9b96:
ORG 8326h
SUB_0000_8326:
ORG 2e88h
SUB_0000_2e88:
ORG 61ceh
SUB_0000_61ce:
ORG 5906h
SUB_0000_5906:
ORG 9b7eh
SUB_0000_9b7e:
ORG 7730h
SUB_0000_7730:
ORG 448ch
SUB_0000_448c:
ORG 405ch
SUB_0000_405c:
ORG 9cdah
SUB_0000_9cda:
ORG 9e2ah
SUB_0000_9e2a:
ORG 8c80h
SUB_0000_8c80:
ORG 7466h
SUB_0000_7466:
ORG 9b42h
SUB_0000_9b42:
ORG 5384h
SUB_0000_5384:
ORG 9b72h
SUB_0000_9b72:
ORG 3b0eh
SUB_0000_3b0e:
ORG 3a12h
SUB_0000_3a12:
ORG 2890h
SUB_0000_2890:
ORG 2a84h
SUB_0000_2a84:
ORG 2d8eh
SUB_0000_2d8e:
ORG 5dd4h
SUB_0000_5dd4:
ORG 3ee8h
SUB_0000_3ee8:
ORG 28eeh
SUB_0000_28ee:
ORG 5d8eh
SUB_0000_5d8e:
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
	CMP        word ptr [BP + 4h],30h	; param_1
	JZ         L_0018
	CMP        word ptr [BP + 4h],31h	; param_1
	JZ         L_0018
	CMP        word ptr [BP + 4h],33h	; param_1
	JL         L_001c
L_0018:
	SUB        AX,AX
	JMP        L_0050
L_001c:
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_9ce6
	MOV        word ptr [BP + -4h],AX	; local_6
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffffh
	PUSH       AX
	CALL       SUB_0000_9ce6
	MOV        word ptr [BP + -2h],AX	; local_4
	CALL       SUB_0000_58de
	MOV        CX,AX
	MOV        AX,word ptr [BP + -2h]	; local_4
	SUB        AX,word ptr [BP + -4h]	; local_6
	ADD        AX,1eh
	CWD
	SUB        AX,DX
	SAR        AX,1h
	CMP        AX,CX
	JLE        L_0018
	MOV        AX,1h
L_0050:
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0000 ENDP
F_0056 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
	MOV        DI,5c5ah
L_0063:
	MOV        AL,byte ptr [DI]
	AND        AL,0fch
	CMP        AL,0e8h
	JNZ        L_0081
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_3eb2
	CMP        AX,10h
	JGE        L_0081
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_9ba2
L_0081:
	ADD        DI,8h
	INC        SI
	CMP        SI,20h
	JL         L_0063
	MOV        word ptr [BP + -2h],SI	; local_4
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0056 ENDP
F_0094 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_00b6
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	JMP        L_00c9
L_00b6:
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba17h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1856h]
L_00c9:
	CALL       SUB_0000_3670
	POP        SI
	POP        BP
	RET        2h
	db 90h
	; Func
F_0094 ENDP
F_00d2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        byte ptr DS:[588fh],0h
	JZ         L_00e2
	MOV        AX,99a0h
	JMP        L_00eb
	db 90h
L_00e2:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0094
	MOV        AX,99aah
L_00eb:
	PUSH       AX
	CALL       SUB_0000_3670
	POP        BP
	RET        2h
	db 90h
	; Func
F_00d2 ENDP
F_00f4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,byte ptr [SI + 0ba18h]
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        byte ptr DS:[587ah],1ch
	JZ         L_0127
	CMP        byte ptr DS:[587ah],4eh
	JZ         L_0127
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_012c
L_0127:
	SUB        AX,AX
	JMP        L_030a
L_012c:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],40h
	JNZ        L_013b
	JMP        L_01ca
L_013b:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1fh
	PUSH       AX
	CALL       SUB_0000_3eb2
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba16h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX	; local_6
	TEST       byte ptr [BP + -4h],80h	; local_6
	JZ         L_01ca
	TEST       byte ptr [BP + -4h],3dh	; local_6
	JNZ        L_01ca
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -0ch]	; local_e
	SUB        AX,AX
	PUSH       AX
	CALL       F_0000
	OR         AX,AX
	JNZ        L_01c4
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	OR         byte ptr [SI + 0ba16h],1h
	MOV        AL,DS:[587bh]
	CMP        byte ptr [SI + 0ba17h],AL
	JNZ        L_018d
	MOV        byte ptr DS:[587bh],0ffh
L_018d:
	CALL       SUB_0000_4720
	PUSH       word ptr [BP + -0ch]	; local_e
	CALL       F_0094
	MOV        AX,99b4h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0c1ch
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,7530h
	PUSH       AX
	MOV        AX,3e8h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_3fb2
	CMP        word ptr [BP + -2h],26h	; local_4
	JNZ        L_01c4
	MOV        AX,word ptr [BP + 4h]	; param_1
	NEG        AX
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_9ba2
L_01c4:
	MOV        AX,1h
	JMP        L_030a
L_01ca:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],800h
	JZ         L_023e
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_3eb2
	CMP        AX,20h
	JGE        L_023e
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0094
	MOV        SI,word ptr [BP + -0ah]	; local_c
	MOV        CL,3h
	SHL        SI,CL
	CMP        byte ptr [SI + 5c5bh],0h
	JNZ        L_021e
	MOV        AX,99c2h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	AND        byte ptr [BX + 0ba16h],0efh
	MOV        AL,byte ptr [SI + 5c5ah]
	MOV        byte ptr [SI + 5c5bh],AL
	JMP        L_01c4
L_021e:
	MOV        AX,99ceh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	OR         byte ptr [BX + 0ba16h],10h
	MOV        BX,word ptr [BP + -0ah]	; local_c
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5bh],0h
	JMP        L_01c4
	db 90h
L_023e:
	MOV        BX,word ptr [BP + -2h]	; local_4
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],400h
	JNZ        L_024e
	JMP        L_0127
L_024e:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_3eb2
	CMP        AX,20h
	JL         L_0260
	JMP        L_0127
L_0260:
	CALL       SUB_0000_9cb6
	OR         AX,AX
	JNZ        L_026a
	JMP        L_0127
L_026a:
	MOV        AX,0d8h
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_9b96
	OR         AX,AX
	JNZ        L_0280
	JMP        L_0127
L_0280:
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
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,0ffffh
	JNZ        L_02a3
	JMP        L_0127
L_02a3:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0094
	MOV        AX,99dch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0ac8h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1388h
	PUSH       AX
	MOV        AX,3e8h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_3fb2
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba18h]
	SUB        AH,AH
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        BX,AX
	MOV        SI,AX
	MOV        AL,16h
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        AX,1d8h
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_2e88
	MOV        BX,SI
	MOV        AL,0d8h
	MOV        byte ptr [SI + 1h],AL
	MOV        byte ptr [BX],AL
	JMP        L_01c4
	db 90h
L_030a:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_00f4 ENDP
F_0312 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba16h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	AND        byte ptr DS:[58a2h],0feh
	TEST       byte ptr DS:[58a2h],20h
	JZ         L_0355
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0094
	MOV        AX,99f2h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_61ce
L_0355:
	TEST       byte ptr DS:[58a2h],22h
	JZ         L_035f
	JMP        L_044c
L_035f:
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_036b
	TEST       byte ptr [BP + -2h],20h	; local_4
	JZ         L_0380
L_036b:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0094
	MOV        AX,99fch
	PUSH       AX
	CALL       SUB_0000_3670
	OR         byte ptr DS:[58a2h],1h
	JMP        L_0426
L_0380:
	TEST       byte ptr DS:[58a2h],4h
	JZ         L_0394
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0094
	MOV        AX,9a06h
	JMP        L_0422
	db 90h
L_0394:
	TEST       byte ptr DS:[58a2h],8h
	JZ         L_039e
	JMP        L_0426
L_039e:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0094
	TEST       byte ptr [BP + -2h],80h	; local_4
	JZ         L_0402
	CMP        word ptr [BP + 4h],0ffh	; param_1
	JZ         L_03fc
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 0ba17h],2dh
	JNZ        L_03fc
	MOV        AX,9a10h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_61ce
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        SI,CL
	OR         byte ptr [SI + 0ba16h],4h
	MOV        BL,byte ptr [SI + 0ba18h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5bh],0h
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_5906
	JMP        L_0426
	db 90h
L_03fc:
	MOV        AX,9a22h
	JMP        L_0422
	db 90h
L_0402:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       SUB_0000_9b7e
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,1h
	JZ         L_0446
	CMP        AX,2h
	JZ         L_0440
	CMP        AX,3h
	JZ         L_043a
	CMP        AX,4h
	JNZ        L_0426
	MOV        AX,9a2ah
L_0422:
	PUSH       AX
	CALL       SUB_0000_3670
L_0426:
	TEST       byte ptr [BP + -2h],80h	; local_4
	JZ         L_0432
	CALL       SUB_0000_4720
	CALL       SUB_0000_7730
L_0432:
	AND        byte ptr DS:[58a2h],0f3h
	JMP        L_0451
	db 90h
L_043a:
	MOV        AX,9a3ch
	JMP        L_0422
	db 90h
L_0440:
	MOV        AX,9a50h
	JMP        L_0422
	db 90h
L_0446:
	MOV        AX,9a64h
	JMP        L_0422
	db 90h
L_044c:
	AND        byte ptr DS:[58a2h],0ddh
L_0451:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0312 ENDP
F_0458 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	MOV        AX,word ptr [BP + 0ah]	; param_4
	SUB        AX,word ptr [BP + 6h]	; param_2
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 8h]	; param_3
	SUB        AX,word ptr [BP + 4h]	; param_1
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AX,word ptr [BP + -4h]	; local_6
	IMUL       AX
	MOV        CX,AX
	MOV        AX,word ptr [BP + -6h]	; local_8
	IMUL       AX
	ADD        CX,AX
	MOV        word ptr [BP + -2h],CX	; local_4
	MOV        AX,CX
	MOV        SP,BP
	POP        BP
	RET        8h
	db 90h
	; Func
F_0458 ENDP
F_048a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        SI,1h
	MOV        word ptr [BP + -4h],0h	; local_6
	PUSH       word ptr [BP + 0ah]	; param_4
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0458
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        DX,word ptr [BP + -4h]	; local_6
	MOV        CX,AX
	JMP        L_04bd
	db 90h
L_04b8:
	SUB        CX,SI
	INC        SI
	INC        SI
	INC        DX
L_04bd:
	CMP        CX,SI
	JGE        L_04b8
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        word ptr [BP + -4h],DX	; local_6
	MOV        word ptr [BP + -6h],CX	; local_8
	MOV        AX,DX
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        8h
	db 90h
	; Func
F_048a ENDP
F_04d4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        SI,CL
	MOV        DI,word ptr [BP + 6h]	; param_2
	SHL        DI,CL
	MOV        AL,byte ptr [DI + 0ba1ah]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [DI + 0ba1bh]
	PUSH       AX
	MOV        AL,byte ptr [SI + 0ba1ah]
	PUSH       AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	PUSH       AX
	CALL       F_048a
	POP        SI
	POP        DI
	POP        BP
	RET        4h
	; Func
F_04d4 ENDP
F_0504 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,22h
	PUSH       DI
	PUSH       SI
	MOV        byte ptr DS:[5898h],1h
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba18h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c61h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        SI,AX
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba18h]
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr [BP + -0ah],1fh	; local_c
	JG         L_0562
	TEST       byte ptr [SI + 0ba16h],30h
	JNZ        L_0562
	CMP        byte ptr [SI + 0ba16h],0h
	JZ         L_0562
	MOV        BX,AX
	CMP        byte ptr [BX],0h
	JZ         L_0562
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_04d4
	CMP        AX,word ptr [BP + 4h]	; param_1
	JLE        L_0568
L_0562:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        word ptr [BP + -0ah],AX	; local_c
L_0568:
	MOV        AX,word ptr [BP + -0ah]	; local_c
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -20h],AX	; local_22
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 0ba1ah]
	MOV        DS:[5899h],AL
	MOV        AL,byte ptr [BX + 0ba1bh]
	MOV        DS:[589ah],AL
	SUB        AX,AX
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AX,word ptr [BP + 6h]	; param_2
	SHL        AX,CL
	MOV        word ptr [BP + -22h],AX	; local_24
	ADD        AX,0ba1bh
	MOV        word ptr [BP + -14h],AX	; local_16
	MOV        AX,word ptr [BP + -22h]	; local_24
	ADD        AX,0ba1ah
	MOV        word ptr [BP + -16h],AX	; local_18
	MOV        AX,word ptr [BP + -14h]	; local_16
	MOV        word ptr [BP + -18h],AX	; local_1a
	MOV        AX,word ptr [BP + -16h]	; local_18
	MOV        word ptr [BP + -1ah],AX	; local_1c
	MOV        AX,word ptr [BP + -14h]	; local_16
	MOV        word ptr [BP + -1ch],AX	; local_1e
	MOV        AX,word ptr [BP + -16h]	; local_18
	MOV        word ptr [BP + -1eh],AX	; local_20
	MOV        DI,word ptr [BP + -10h]	; local_12
	MOV        SI,word ptr [BP + -0eh]	; local_10
	JMP        L_0624
	db 90h
L_05c2:
	MOV        SI,0ffffh
L_05c5:
	MOV        DI,0ffffh
L_05c8:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[5899h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,DI
	MOV        CL,byte ptr DS:[589ah]
	ADD        AX,CX
	MOV        word ptr [BP + -4h],AX	; local_6
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       AX
	MOV        BX,word ptr [BP + -16h]	; local_18
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	MOV        BX,word ptr [BP + -14h]	; local_16
	MOV        AL,byte ptr [BX]
	PUSH       AX
	CALL       F_048a
	MOV        word ptr [BP + -12h],AX	; local_14
	MOV        AX,word ptr [BP + 4h]	; param_1
	CMP        word ptr [BP + -12h],AX	; local_14
	JG         L_0624
	CMP        word ptr [BP + -2h],0h	; local_4
	JL         L_0624
	CMP        word ptr [BP + -2h],0bh	; local_4
	JGE        L_0624
	CMP        word ptr [BP + -4h],0h	; local_6
	JL         L_0624
	CMP        word ptr [BP + -4h],0bh	; local_6
	JGE        L_0624
	MOV        AL,byte ptr [BP + -2h]	; local_4
	MOV        DS:[5899h],AL
	MOV        AL,byte ptr [BP + -4h]	; local_6
	MOV        DS:[589ah],AL
L_0624:
	CMP        word ptr [BP + -8h],0h	; local_a
	JZ         L_062d
	JMP        L_0720
L_062d:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JZ         L_0636
	JMP        L_0720
L_0636:
	SUB        DI,DI
	MOV        SI,DI
	CALL       SUB_0000_7730
	CALL       SUB_0000_448c
	CMP        AX,1bh
	JNZ        L_0648
	JMP        L_06ea
L_0648:
	JLE        L_064d
	JMP        L_06f2
L_064d:
	CMP        AX,1h
	JZ         L_0683
	CMP        AX,2h
	JZ         L_0679
	CMP        AX,3h
	JNZ        L_065f
	JMP        L_05c5
L_065f:
	CMP        AX,4h
	JZ         L_066f
	CMP        AX,0dh
	JZ         L_06a3
	JMP        L_05c8
L_066c:
	MOV        SI,1h
L_066f:
	MOV        DI,1h
	JMP        L_05c8
	db 90h
L_0676:
	MOV        DI,0ffffh
L_0679:
	MOV        SI,1h
	JMP        L_05c8
	db 90h
L_0680:
	MOV        DI,1h
L_0683:
	MOV        SI,0ffffh
	JMP        L_05c8
	db 90h
L_068a:
	MOV        BX,word ptr [BP + -1eh]	; local_20
	MOV        AL,DS:[5899h]
	CMP        byte ptr [BX],AL
	JNZ        L_06a3
	MOV        BX,word ptr [BP + -1ch]	; local_1e
	MOV        AL,DS:[589ah]
	CMP        byte ptr [BX],AL
	JNZ        L_06a3
	MOV        word ptr [BP + -0ch],1h	; local_e
L_06a3:
	MOV        BX,word ptr [BP + -1ah]	; local_1c
	MOV        AL,DS:[5899h]
	CMP        byte ptr [BX],AL
	JNZ        L_06ba
	MOV        BX,word ptr [BP + -18h]	; local_1a
	MOV        AL,DS:[589ah]
	CMP        byte ptr [BX],AL
	JNZ        L_06ba
	JMP        L_05c8
L_06ba:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	CMP        byte ptr DS:[588fh],0h
	JZ         L_06e1
	MOV        AX,320h
	PUSH       AX
	MOV        AL,DS:[588fh]
	SUB        AH,AH
	MOV        CX,640h
	MUL        CX
	ADD        AX,1f40h
	PUSH       AX
	MOV        AX,2bch
	PUSH       AX
	CALL       SUB_0000_405c
L_06e1:
	MOV        word ptr [BP + -8h],1h	; local_a
	JMP        L_05c8
	db 90h
L_06ea:
	MOV        word ptr [BP + -0ch],1h	; local_e
	JMP        L_05c8
L_06f2:
	CMP        AX,20h
	JZ         L_068a
	CMP        AX,41h
	JZ         L_06a3
	CMP        AX,0d3h
	JNZ        L_0704
	JMP        L_05c2
L_0704:
	CMP        AX,0d4h
	JNZ        L_070c
	JMP        L_0680
L_070c:
	CMP        AX,0d5h
	JNZ        L_0714
	JMP        L_0676
L_0714:
	CMP        AX,0d6h
	JNZ        L_071c
	JMP        L_066c
L_071c:
	JMP        L_05c8
	db 90h
L_0720:
	MOV        word ptr [BP + -10h],DI	; local_12
	MOV        word ptr [BP + -0eh],SI	; local_10
	MOV        byte ptr DS:[5898h],0h
	CMP        word ptr [BP + -0ch],0h	; local_e
	JZ         L_073c
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	SUB        AX,AX
	JMP        L_073f
L_073c:
	MOV        AX,word ptr [BP + -12h]	; local_14
L_073f:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0504 ENDP
F_0748 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0ffffh	; local_8
	SUB        SI,SI
	MOV        DI,0ba1ah
	MOV        word ptr [BP + -0ah],0ba1bh	; local_c
	MOV        word ptr [BP + -0ch],0ba16h	; local_e
	MOV        word ptr [BP + -0eh],0ba18h	; local_10
	MOV        DX,word ptr [BP + -2h]	; local_4
L_076c:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]	; param_2
	JNZ        L_07a9
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JNZ        L_07a9
	MOV        BX,word ptr [BP + -0ch]	; local_e
	MOV        AL,byte ptr [BX]
	MOV        DX,AX
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        BL,byte ptr [BX]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 5c5bh],0f4h
	JZ         L_07a4
	TEST       AL,0c0h
	JZ         L_07a4
	TEST       AL,20h
	JNZ        L_07a4
	TEST       AL,4h
	JZ         L_07c0
L_07a4:
	MOV        word ptr [BP + -6h],0ffffh	; local_8
L_07a9:
	ADD        DI,8h
	ADD        word ptr [BP + -0ah],8h	; local_c
	ADD        word ptr [BP + -0ch],8h	; local_e
	ADD        word ptr [BP + -0eh],8h	; local_10
	INC        SI
	CMP        SI,20h
	JGE        L_07c3
	JMP        L_076c
L_07c0:
	MOV        word ptr [BP + -6h],SI	; local_8
L_07c3:
	MOV        word ptr [BP + -4h],SI	; local_6
	MOV        word ptr [BP + -2h],DX	; local_4
	MOV        AX,word ptr [BP + -6h]	; local_8
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0748 ENDP
F_07d4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + 6h]	; param_2
	MOV        SI,word ptr [BP + 4h]	; param_1
L_07df:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_3eb2
	ADD        AX,DI
	SUB        AX,2h
	MOV        DS:[5876h],AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_3eb2
	ADD        AX,SI
	SUB        AX,2h
	MOV        DS:[5878h],AX
	CMP        word ptr DS:[5876h],0h
	JL         L_07df
	CMP        word ptr DS:[5876h],0ah
	JG         L_07df
	OR         AX,AX
	JL         L_07df
	CMP        AX,0ah
	JG         L_07df
	POP        SI
	POP        DI
	POP        BP
	RET        4h
	; Func
F_07d4 ENDP
F_0822 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        AX,word ptr [BP + 0ah]	; param_4
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 8h]	; param_3
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AX,word ptr [BP + 0ch]	; param_5
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 0ba1ah]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AL,byte ptr [BX + 0ba1bh]
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        word ptr [BP + 6h],0h	; param_2
	JNZ        L_087e
	MOV        DI,word ptr [BP + -2h]	; local_4
	MOV        SI,AX
L_085d:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_07d4
	CMP        DI,word ptr DS:[5876h]
	JNZ        L_0872
	CMP        SI,word ptr DS:[5878h]
	JZ         L_085d
L_0872:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
L_087e:
	CMP        byte ptr DS:[589dh],19h
	JZ         L_088c
	CMP        byte ptr DS:[589dh],22h
	JNZ        L_08a6
L_088c:
	CMP        word ptr [BP + 6h],0h	; param_2
	JZ         L_08d6
	MOV        AX,word ptr [BP + 0ah]	; param_4
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 8h]	; param_3
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        word ptr [BP + -0ch],1h	; local_e
	JMP        L_08d6
	db 90h
L_08a6:
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_12de
	MOV        word ptr [BP + -0ch],AX	; local_e
	OR         AX,AX
	JZ         L_08ca
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_9cda
	JMP        L_08d6
L_08ca:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX	; local_c
L_08d6:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JNZ        L_08df
	JMP        L_0964
L_08df:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       F_0748
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AL,DS:[589dh]
	SUB        AH,AH
	CMP        AX,13h
	JZ         L_090c
	CMP        AX,33h
	JZ         L_0952
	CMP        AX,34h
	JZ         L_0958
	CMP        AX,35h
	JZ         L_090c
	CMP        AX,36h
	JZ         L_095e
	JMP        L_0923
	db 90h
L_090c:
	MOV        AX,0eah
L_090f:
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_8326
L_0923:
	CMP        byte ptr DS:[588fh],0h
	JZ         L_0930
	CMP        word ptr [BP + 6h],0h	; param_2
	JZ         L_0964
L_0930:
	CMP        word ptr [BP + -6h],0h	; local_8
	JL         L_0964
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	CMP        word ptr [BP + -6h],AX	; local_8
	JZ         L_0964
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BP + -0ah]	; local_c
	MOV        DS:[5878h],AX
	MOV        AX,word ptr [BP + -6h]	; local_8
	JMP        L_0973
	db 90h
L_0952:
	MOV        AX,0e8h
	JMP        L_090f
	db 90h
L_0958:
	MOV        AX,0e9h
	JMP        L_090f
	db 90h
L_095e:
	MOV        AX,0ebh
	JMP        L_090f
	db 90h
L_0964:
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BP + -0ah]	; local_c
	MOV        DS:[5878h],AX
	MOV        AX,0ffffh
L_0973:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ah
	db 90h
	; Func
F_0822 ENDP
F_097c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        byte ptr DS:[588fh],0h
	JNZ        L_09f7
	MOV        AX,word ptr [BP + 6h]	; param_2
	CMP        AX,16h
	JG         L_09e8
	CMP        AX,15h
	JGE        L_09b8
	CMP        AX,10h
	JZ         L_09b8
	JMP        L_09f7
	db 90h
	db 90h
L_099c:
	DEC        byte ptr DS:[57dbh]
L_09a0:
	JNZ        L_09f7
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       SUB_0000_9e2a
	MOV        BX,word ptr [BP + 6h]	; param_2
	ADD        byte ptr [BX + 57c0h],AL
	JMP        L_09f7
	db 90h
L_09b2:
	DEC        byte ptr DS:[57ddh]
	JMP        L_09a0
L_09b8:
	CMP        word ptr [BP + 4h],1h	; param_1
	JLE        L_09f7
	MOV        BX,word ptr [BP + 6h]	; param_2
	CMP        byte ptr [BX + 57c0h],0h
	JZ         L_09ce
	DEC        byte ptr [BX + 57c0h]
	JMP        L_09f7
L_09ce:
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       SUB_0000_8c80
	JMP        L_09f7
	db 90h
L_09e8:
	CMP        AX,1ah
	JZ         L_099c
	CMP        AX,1ch
	JZ         L_09b2
	CMP        AX,24h
	JZ         L_099c
L_09f7:
	POP        BP
	RET        4h
	db 90h
	; Func
F_097c ENDP
F_09fc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 58a8h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,0ffh
	JZ         L_0a5e
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,0ba16h
	CMP        byte ptr [SI],AH
	JZ         L_0a5e
	PUSH       AX
	CALL       SUB_0000_7466
	OR         AX,AX
	JZ         L_0a5e
	TEST       byte ptr [SI],0ch
	JNZ        L_0a5e
	CMP        byte ptr DS:[587ah],54h
	JZ         L_0a5e
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_04d4
	CMP        AX,1h
	JNZ        L_0a5e
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0094
	MOV        AX,9a70h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,1h
	JMP        L_0a60
	db 90h
L_0a5e:
	SUB        AX,AX
L_0a60:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_09fc ENDP
F_0a68 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       SI
	CMP        word ptr [BP + 6h],1ah	; param_2
	JZ         L_0a8d
	CMP        word ptr [BP + 6h],1ch	; param_2
	JZ         L_0a8d
	CMP        word ptr [BP + 6h],24h	; param_2
	JZ         L_0a8d
	CMP        word ptr [BP + 6h],13h	; param_2
	JZ         L_0a8d
	CMP        word ptr [BP + 6h],11h	; param_2
	JNZ        L_0a9a
L_0a8d:
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       F_09fc
	OR         AX,AX
	JZ         L_0a9a
	JMP        L_0bf0
L_0a9a:
	MOV        AX,9a7eh
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        AL,byte ptr [BX + 1664h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0504
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JNZ        L_0abb
	JMP        L_0bf0
L_0abb:
	MOV        AX,514h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	CALL       SUB_0000_61ce
	CMP        word ptr [BP + 6h],13h	; param_2
	JNZ        L_0afb
	MOV        BX,word ptr [BP + 6h]	; param_2
	CMP        byte ptr [BX + 57c0h],0h
	JZ         L_0ae4
	DEC        byte ptr [BX + 57c0h]
	JMP        L_0afb
L_0ae4:
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       SUB_0000_8c80
L_0afb:
	MOV        BX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba18h]
	SUB        AH,AH
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        BX,AX
	MOV        byte ptr [BX + 7h],0ffh
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	CALL       F_0748
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,0ffffh
	JLE        L_0b6a
	MOV        BX,word ptr [BP + -8h]	; local_a
	MOV        AL,byte ptr [BP + -0ah]	; local_c
	MOV        byte ptr [BX + 7h],AL
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -0eh]	; local_10
	CALL       F_097c
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AL,DS:[588fh]
	SUB        AH,AH
	NEG        AX
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       SUB_0000_9b42
	MOV        word ptr [BP + -2h],AX	; local_4
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	JMP        L_0b7b
	db 90h
L_0b6a:
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
L_0b7b:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0822
	MOV        word ptr [BP + -0ah],AX	; local_c
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr [BP + -0ah],-1h	; local_c
	JLE        L_0bb8
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_5384
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       SUB_0000_9b72
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       F_0312
	JMP        L_0bcb
	db 90h
L_0bb8:
	CMP        word ptr [BP + -0ch],-1h	; local_e
	JLE        L_0bcb
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + -0ch]	; local_e
	CALL       F_00d2
L_0bcb:
	CMP        word ptr [BP + 6h],26h	; param_2
	JNZ        L_0bf0
	MOV        SI,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        SI,CL
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [SI + 0ba1ah]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	PUSH       AX
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_12de
L_0bf0:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_0a68 ENDP
F_0bf8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,190h
	PUSH       AX
	MOV        AX,2eeh
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	CALL       SUB_0000_61ce
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 8h]	; param_3
	MOV        AL,DS:[588fh]
	SUB        AH,AH
	NEG        AX
	PUSH       AX
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_9b42
	OR         AX,AX
	JZ         L_0c48
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       SUB_0000_5384
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       SUB_0000_9b72
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 8h]	; param_3
	CALL       F_0312
	JMP        L_0c4e
	db 90h
L_0c48:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_00d2
L_0c4e:
	POP        BP
	RET        6h
	; Func
F_0bf8 ENDP
F_0c52 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	CMP        word ptr [BP + 4h],23h	; param_1
	JL         L_0c64
	MOV        byte ptr DS:[5890h],1h
L_0c64:
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JNZ        L_0c9e
	MOV        BL,byte ptr [SI + 0ba17h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 159ch]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        AX,1h
	JNZ        L_0c8b
	MOV        word ptr [BP + -8h],0h	; local_a
L_0c8b:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba17h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 15cch]
	JMP        L_0cc0
L_0c9e:
	CMP        word ptr [BP + 4h],0ffh	; param_1
	JZ         L_0cb4
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 1664h]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX	; local_a
	JMP        L_0cb9
	db 90h
L_0cb4:
	MOV        word ptr [BP + -8h],0h	; local_a
L_0cb9:
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 169ch]
L_0cc0:
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        word ptr [BP + -8h],0h	; local_a
	JNZ        L_0d28
	MOV        AX,9a84h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,1h
	PUSH       AX
	CALL       F_0504
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,DS:[5899h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[589ah]
	PUSH       AX
	CALL       F_0748
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr [BP + -4h],0h	; local_6
	JZ         L_0cfa
	CMP        AX,0ffffh
	JNZ        L_0d04
L_0cfa:
	MOV        AX,9a8ah
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0d34
	db 90h
L_0d04:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba18h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,byte ptr [BP + -6h]	; local_8
	MOV        byte ptr [BX + 5c61h],AL
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -6h]	; local_8
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0bf8
	JMP        L_0d34
L_0d28:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       F_0a68
L_0d34:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0c52 ENDP
F_0d3c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 6h],0ffh	; param_2
	JZ         L_0d91
	MOV        BX,word ptr [BP + 6h]	; param_2
	CMP        byte ptr [BX + 15fch],0h
	JZ         L_0d91
	CMP        word ptr [BP + 4h],1h	; param_1
	JLE        L_0d78
	SUB        AL,AL
	MOV        DS:[588fh],AL
	MOV        DS:[5890h],AL
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr [BP + 6h]	; param_2
	SHL        BX,1h
	PUSH       word ptr [BX + 17f6h]
	CALL       SUB_0000_3670
	MOV        AX,9a94h
	PUSH       AX
	CALL       SUB_0000_3670
L_0d78:
	MOV        AL,byte ptr [BP + 6h]	; param_2
	MOV        DS:[589dh],AL
	MOV        AX,9a98h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0c52
L_0d91:
	POP        BP
	RET        4h
	db 90h
	; Func
F_0d3c ENDP
F_0d96 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_0db1
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_0dca
L_0db1:
	MOV        byte ptr DS:[589dh],0ffh
	MOV        AX,9aa0h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_0c52
	JMP        L_0e1f
	db 90h
L_0dca:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        word ptr [BP + 4h],1h	; param_1
	JLE        L_0df1
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3b0e
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
L_0df1:
	MOV        SI,word ptr [BP + -2h]	; local_4
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 55c1h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0d3c
	MOV        AL,byte ptr [SI + 55c3h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0d3c
	MOV        AL,byte ptr [SI + 55c4h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0d3c
L_0e1f:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0d96 ENDP
F_0e26 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],1h	; local_6
	MOV        word ptr [BP + -6h],1h	; local_8
	MOV        word ptr [BP + -0ah],148h	; local_c
	MOV        AX,word ptr [BP + 0eh]	; param_6
	CMP        word ptr [BP + 0ah],AX	; param_4
	JZ         L_0e5e
	MOV        CX,64h
	MOV        AX,word ptr [BP + 8h]	; param_3
	SUB        AX,word ptr [BP + 0ch]	; param_5
	IMUL       CX
	CWD
	MOV        CX,word ptr [BP + 0ah]	; param_4
	SUB        CX,word ptr [BP + 0eh]	; param_6
	IDIV       CX
	MOV        word ptr [BP + -8h],AX	; local_a
	JMP        L_0e63
L_0e5e:
	MOV        word ptr [BP + -8h],4b00h	; local_a
L_0e63:
	CMP        word ptr [BP + -8h],0h	; local_a
	JGE        L_0e71
	MOV        AX,word ptr [BP + -8h]	; local_a
	NEG        AX
	MOV        word ptr [BP + -8h],AX	; local_a
L_0e71:
	MOV        AX,word ptr [BP + 0eh]	; param_6
	CMP        word ptr [BP + 0ah],AX	; param_4
	JGE        L_0e7e
	MOV        word ptr [BP + -4h],0ffffh	; local_6
L_0e7e:
	MOV        AX,word ptr [BP + 0ch]	; param_5
	CMP        word ptr [BP + 8h],AX	; param_3
	JGE        L_0e8b
	MOV        word ptr [BP + -6h],0ffffh	; local_8
L_0e8b:
	MOV        AX,word ptr [BP + 0ah]	; param_4
	SUB        AX,word ptr [BP + 0eh]	; param_6
	MOV        word ptr [BP + -0eh],AX	; local_10
	OR         AX,AX
	JGE        L_0e9d
	NEG        AX
	MOV        word ptr [BP + -0eh],AX	; local_10
L_0e9d:
	MOV        AX,word ptr [BP + 8h]	; param_3
	SUB        AX,word ptr [BP + 0ch]	; param_5
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JGE        L_0eaf
	NEG        AX
	MOV        word ptr [BP + -2h],AX	; local_4
L_0eaf:
	MOV        DX,word ptr [BP + -8h]	; local_a
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        AL,byte ptr [BP + 0eh]	; param_6
	MOV        byte ptr [BX],AL
	INC        word ptr [BP + 6h]	; param_2
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BP + 0ch]	; param_5
	MOV        byte ptr [BX],AL
	INC        word ptr [BP + 4h]	; param_1
	MOV        DI,word ptr [BP + 4h]	; param_1
	MOV        SI,word ptr [BP + 0ch]	; param_5
	MOV        CX,word ptr [BP + -2h]	; local_4
L_0ed1:
	CMP        word ptr [BP + -0eh],0h	; local_10
	JG         L_0edb
	OR         CX,CX
	JLE        L_0f05
L_0edb:
	OR         DX,DX
	JLE        L_0eff
	OR         CX,CX
	JLE        L_0eff
	SUB        DX,64h
	ADD        SI,word ptr [BP + -6h]	; local_8
	MOV        AX,SI
	MOV        byte ptr [DI],AL
	INC        DI
	DEC        CX
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        AL,byte ptr [BP + 0eh]	; param_6
	MOV        byte ptr [BX],AL
	INC        word ptr [BP + 6h]	; param_2
	DEC        word ptr [BP + -0ah]	; local_c
	JNZ        L_0edb
L_0eff:
	CMP        word ptr [BP + -0ah],0h	; local_c
	JNZ        L_0f14
L_0f05:
	MOV        word ptr [BP + 4h],DI	; param_1
	MOV        word ptr [BP + 0ch],SI	; param_5
	MOV        word ptr [BP + -0ch],DX	; local_e
	MOV        word ptr [BP + -2h],CX	; local_4
	JMP        L_0f36
	db 90h
L_0f14:
	DEC        word ptr [BP + -0eh]	; local_10
	ADD        DX,word ptr [BP + -8h]	; local_a
	MOV        AX,word ptr [BP + -4h]	; local_6
	ADD        word ptr [BP + 0eh],AX	; param_6
	MOV        AX,SI
	MOV        byte ptr [DI],AL
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        AL,byte ptr [BP + 0eh]	; param_6
	MOV        byte ptr [BX],AL
	INC        DI
	INC        word ptr [BP + 6h]	; param_2
	DEC        word ptr [BP + -0ah]	; local_c
	JMP        L_0ed1
	db 90h
L_0f36:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        byte ptr [BX],0ffh
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        byte ptr [BX],0ffh
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ch
	; Func
F_0e26 ENDP
F_0f4a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,32h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -1ah],1h	; local_1c
	MOV        word ptr [BP + -1ch],1h	; local_1e
	MOV        word ptr [BP + -2h],0ffffh	; local_4
	CMP        word ptr [BP + 8h],2h	; param_1
	JNZ        L_0f70
	MOV        AX,2188h
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        word ptr [BP + -8h],AX	; local_a
L_0f70:
	CMP        word ptr [BP + 8h],2h	; param_1
	JLE        L_0f7f
	MOV        AX,2198h
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        word ptr [BP + -8h],AX	; local_a
L_0f7f:
	MOV        AX,word ptr [BP + 0ah]	; param_2
	CMP        AX,1h
	JZ         L_0f98
	CMP        AX,2h
	JZ         L_0fb6
	CMP        AX,3h
	JZ         L_0fc0
	CMP        AX,4h
	JZ         L_0fce
	JMP        L_0f9b
L_0f98:
	INC        word ptr [BP + -0ch]	; local_e
L_0f9b:
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,word ptr [BP + 8h]	; param_1
	CMP        AX,7h
	JBE        L_0fad
	JMP        L_1224
L_0fad:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0f3f4h]
	db 90h
L_0fb6:
	INC        word ptr [BP + -8h]	; local_a
	MOV        word ptr [BP + -1ah],0ffffh	; local_1c
	JMP        L_0f9b
L_0fc0:
	INC        word ptr [BP + -0ch]	; local_e
	MOV        AX,0ffffh
	MOV        word ptr [BP + -1ch],AX	; local_1e
	MOV        word ptr [BP + -1ah],AX	; local_1c
	JMP        L_0f9b
L_0fce:
	INC        word ptr [BP + -8h]	; local_a
	MOV        word ptr [BP + -1ch],0ffffh	; local_1e
	JMP        L_0f9b
	db 8Bh
	db 76h
	db 06h
	db 83h
	db 0EEh
	db 04h
	db 8Bh
	db 46h
	db 04h
	db 2Dh
	db 04h
	db 00h
	db 89h
	db 46h
	db 0EAh
	db 0C7h
	db 46h
	db 0ECh
	db 00h
	db 00h
	db 8Bh
	db 7Eh
	db 0E0h
	db 80h
	db 3Ch
	db 0FFh
	db 75h
	db 06h
	db 89h
	db 76h
	db 0F2h
	db 0E9h
	db 2Ah
	db 02h
	db 8Bh
	db 5Eh
	db 0EAh
	db 8Ah
	db 07h
	db 2Ah
	db 0E4h
	db 89h
	db 46h
	db 0E2h
	db 8Ah
	db 04h
	db 8Bh
	db 0F8h
	db 57h
	db 0FFh
	db 76h
	db 0E2h
	db 8Dh
	db 45h
	db 01h
	db 50h
	db 0FFh
	db 76h
	db 0E2h
	db 0E8h
	db 1Ah
	db 19h
	db 46h
	db 0FFh
	db 46h
	db 0EAh
	db 0FFh
	db 46h
	db 0ECh
	db 83h
	db 7Eh
	db 0ECh
	db 09h
	db 7Dh
	db 0D1h
	db 0EBh
	db 0CAh
	db 90h
	db 8Ah
	db 46h
	db 0Ch
	db 2Ah
	db 0E4h
	db 8Bh
	db 0F0h
	db 8Ah
	db 46h
	db 0Eh
	db 8Bh
	db 0F8h
	db 8Dh
	db 45h
	db 01h
	db 89h
	db 46h
	db 0E0h
	db 8Dh
	db 44h
	db 0FEh
	db 89h
	db 46h
	db 0E2h
	db 8Dh
	db 45h
	db 0FFh
	db 89h
	db 46h
	db 0DEh
	db 50h
	db 0FFh
	db 76h
	db 0E2h
	db 0FFh
	db 76h
	db 0E0h
	db 0FFh
	db 76h
	db 0E2h
	db 0E8h
	db 0DFh
	db 18h
	db 8Dh
	db 45h
	db 02h
	db 89h
	db 46h
	db 0DCh
	db 8Dh
	db 45h
	db 0FEh
	db 89h
	db 46h
	db 0DAh
	db 8Dh
	db 44h
	db 0FFh
	db 89h
	db 46h
	db 0D8h
	db 0FFh
	db 76h
	db 0DAh
	db 50h
	db 0FFh
	db 76h
	db 0DCh
	db 50h
	db 0E8h
	db 0C2h
	db 18h
	db 0FFh
	db 76h
	db 0DAh
	db 56h
	db 0FFh
	db 76h
	db 0DCh
	db 56h
	db 0E8h
	db 0B7h
	db 18h
	db 8Dh
	db 44h
	db 01h
	db 89h
	db 46h
	db 0D6h
	db 0FFh
	db 76h
	db 0DAh
	db 50h
	db 0FFh
	db 76h
	db 0DCh
	db 50h
	db 0E8h
	db 0A6h
	db 18h
	db 8Dh
	db 44h
	db 02h
	db 89h
	db 46h
	db 0D4h
	db 0FFh
	db 76h
	db 0DEh
	db 50h
	db 0FFh
	db 76h
	db 0E0h
	db 50h
	db 0E8h
	db 95h
	db 18h
	db 0E9h
	db 86h
	db 01h
	db 0C7h
	db 46h
	db 0ECh
	db 04h
	db 00h
	db 8Ah
	db 46h
	db 0Ch
	db 2Ah
	db 0E4h
	db 89h
	db 46h
	db 0D2h
	db 8Ah
	db 46h
	db 0Eh
	db 89h
	db 46h
	db 0D0h
	db 0C7h
	db 46h
	db 0CEh
	db 04h
	db 00h
	db 8Bh
	db 7Eh
	db 0F8h
	db 8Bh
	db 76h
	db 0F4h
	db 8Ah
	db 05h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 46h
	db 0D0h
	db 89h
	db 46h
	db 0F6h
	db 83h
	db 0C7h
	db 02h
	db 8Ah
	db 04h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 46h
	db 0D2h
	db 89h
	db 46h
	db 0EEh
	db 83h
	db 0C6h
	db 02h
	db 8Ah
	db 05h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 46h
	db 0D0h
	db 89h
	db 46h
	db 0F0h
	db 83h
	db 0C7h
	db 02h
	db 8Ah
	db 04h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 46h
	db 0D2h
	db 89h
	db 46h
	db 0E8h
	db 83h
	db 0C6h
	db 02h
	db 0FFh
	db 76h
	db 0F6h
	db 0FFh
	db 76h
	db 0EEh
	db 0FFh
	db 76h
	db 0F0h
	db 50h
	db 0E8h
	db 2Bh
	db 18h
	db 0FFh
	db 4Eh
	db 0CEh
	db 75h
	db 0B2h
	db 89h
	db 7Eh
	db 0F8h
	db 89h
	db 76h
	db 0F4h
	db 0E9h
	db 11h
	db 01h
	db 90h
	db 0A1h
	db 0AEh
	db 13h
	db 05h
	db 08h
	db 00h
	db 89h
	db 46h
	db 0FEh
	db 0E9h
	db 04h
	db 01h
	db 0A1h
	db 0B2h
	db 13h
	db 0EBh
	db 0F2h
	db 90h
	db 0A1h
	db 0B4h
	db 13h
	db 0EBh
	db 0ECh
	db 90h
	db 0A1h
	db 0B6h
	db 13h
	db 0EBh
	db 0E6h
	db 90h
	db 0C7h
	db 46h
	db 0ECh
	db 07h
	db 00h
	db 8Ah
	db 46h
	db 0Ch
	db 2Ah
	db 0E4h
	db 89h
	db 46h
	db 0CEh
	db 8Ah
	db 46h
	db 0Eh
	db 89h
	db 46h
	db 0D0h
	db 0C7h
	db 46h
	db 0D2h
	db 07h
	db 00h
	db 8Bh
	db 7Eh
	db 0F8h
	db 8Bh
	db 76h
	db 0F4h
	db 8Ah
	db 05h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 46h
	db 0D0h
	db 89h
	db 46h
	db 0F6h
	db 83h
	db 0C7h
	db 02h
	db 8Ah
	db 04h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 46h
	db 0CEh
	db 89h
	db 46h
	db 0EEh
	db 83h
	db 0C6h
	db 02h
	db 8Ah
	db 05h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 46h
	db 0D0h
	db 89h
	db 46h
	db 0F0h
	db 83h
	db 0C7h
	db 02h
	db 8Ah
	db 04h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 46h
	db 0CEh
	db 89h
	db 46h
	db 0E8h
	db 83h
	db 0C6h
	db 02h
	db 0FFh
	db 76h
	db 0F6h
	db 0FFh
	db 76h
	db 0EEh
	db 0FFh
	db 76h
	db 0F0h
	db 50h
	db 0E8h
	db 97h
	db 17h
	db 0FFh
	db 4Eh
	db 0D2h
	db 75h
	db 0B2h
	db 89h
	db 7Eh
	db 0F8h
	db 89h
	db 76h
	db 0F4h
	db 8Ah
	db 46h
	db 0Ch
	db 2Ah
	db 0E4h
	db 8Bh
	db 0F0h
	db 8Ah
	db 46h
	db 0Eh
	db 8Bh
	db 0F8h
	db 8Bh
	db 5Eh
	db 0F8h
	db 8Ah
	db 07h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 0C7h
	db 50h
	db 8Bh
	db 5Eh
	db 0F4h
	db 8Ah
	db 07h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 0C6h
	db 50h
	db 0E8h
	db 0B9h
	db 18h
	db 83h
	db 46h
	db 0F8h
	db 02h
	db 83h
	db 46h
	db 0F4h
	db 02h
	db 8Bh
	db 5Eh
	db 0F8h
	db 8Ah
	db 07h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 0C7h
	db 50h
	db 8Bh
	db 5Eh
	db 0F4h
	db 8Ah
	db 07h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 0C6h
	db 50h
	db 0E8h
	db 96h
	db 18h
	db 83h
	db 46h
	db 0F8h
	db 02h
	db 83h
	db 46h
	db 0F4h
	db 02h
	db 8Bh
	db 5Eh
	db 0F8h
	db 8Ah
	db 07h
	db 98h
	db 0F7h
	db 6Eh
	db 0E6h
	db 03h
	db 0C7h
	db 50h
	db 8Bh
	db 5Eh
	db 0F4h
	db 8Ah
	db 07h
	db 98h
	db 0F7h
	db 6Eh
	db 0E4h
	db 03h
	db 0C6h
	db 50h
	db 0E8h
	db 73h
	db 18h
	db 0EBh
	db 11h
	db 90h
	db 0B8h
	db 0F1h
	db 06h
	db 0F2h
	db 7Eh
	db 0F2h
	db 0F4h
	db 0F2h
	db 00h
	db 0F3h
	db 06h
	db 0F3h
	db 0Ch
	db 0F3h
	db 12h
	db 0F3h
L_1224:
	CMP        word ptr [BP + -2h],-1h	; local_4
	JG         L_122d
	JMP        L_12d5
L_122d:
	MOV        DI,0ffffh
	MOV        SI,1h
	MOV        word ptr [BP + -14h],30h	; local_16
	MOV        AL,byte ptr [BP + 0ch]	; param_3
	SUB        AH,AH
	MOV        word ptr [BP + -32h],AX	; local_34
	MOV        AL,byte ptr [BP + 0eh]	; param_4
	MOV        word ptr [BP + -30h],AX	; local_32
	MOV        word ptr [BP + -2eh],30h	; local_30
L_124b:
	MOV        AX,21bah
	MOV        word ptr [BP + -16h],AX	; local_18
	MOV        word ptr [BP + -0eh],AX	; local_10
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_3eb2
	ADD        word ptr [BP + -0eh],AX	; local_10
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_3eb2
	ADD        word ptr [BP + -16h],AX	; local_18
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3eb2
	MOV        word ptr [BP + -4h],AX	; local_6
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3eb2
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        word ptr [BP + -4h],0h	; local_6
	JZ         L_1294
	MOV        AX,DI
	NEG        AX
	MOV        DI,AX
L_1294:
	CMP        word ptr [BP + -6h],0h	; local_8
	JZ         L_12a0
	MOV        AX,SI
	NEG        AX
	MOV        SI,AX
L_12a0:
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_2890
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        CX,DI
	MUL        CX
	ADD        AX,word ptr [BP + -30h]	; local_32
	PUSH       AX
	MOV        BX,word ptr [BP + -16h]	; local_18
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        CX,SI
	MUL        CX
	ADD        AX,word ptr [BP + -32h]	; local_34
	PUSH       AX
	CALL       SUB_0000_2a84
	DEC        word ptr [BP + -2eh]	; local_30
	JZ         L_12cf
	JMP        L_124b
L_12cf:
	MOV        word ptr [BP + -1ah],DI	; local_1c
	MOV        word ptr [BP + -1ch],SI	; local_1e
L_12d5:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ch
	db 90h
	; Func
F_0f4a ENDP
F_12de PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ah],0dh	; local_c
	MOV        word ptr [BP + -8h],0h	; local_a
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_2d8e
	MOV        CX,100h
	MOV        DI,0a728h
	MOV        AX,DS
	MOV        ES,AX
	MOV        AX,0ffh
	REP STOSB
	MOV        CX,100h
	MOV        DI,0a872h
	REP STOSB
	MOV        AX,word ptr [BP + 0ch]	; param_5
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,10h
	MOV        word ptr [BP + -0eh],AX	; local_10
	MOV        AX,word ptr [BP + 0ah]	; param_4
	SHL        AX,CL
	ADD        AX,10h
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,word ptr [BP + 8h]	; param_3
	SHL        AX,CL
	ADD        AX,10h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        AX,word ptr [BP + 6h]	; param_2
	SHL        AX,CL
	ADD        AX,10h
	MOV        word ptr [BP + -6h],AX	; local_8
	PUSH       word ptr [BP + -0eh]	; local_10
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       AX
	MOV        AX,0a728h
	PUSH       AX
	MOV        AX,0a872h
	PUSH       AX
	CALL       F_0e26
	MOV        word ptr [BP + -0ch],0a728h	; local_e
	MOV        word ptr [BP + -10h],0a872h	; local_12
	CMP        byte ptr DS:[5893h],0h
	JZ         L_1374
	CMP        byte ptr DS:[5893h],21h
	JNC        L_1374
	MOV        word ptr [BP + -0ah],6h	; local_c
	JMP        L_137f
	db 90h
L_1374:
	CMP        word ptr [BP + 4h],7h	; param_1
	JNZ        L_137f
	MOV        word ptr [BP + -0ah],8h	; local_c
L_137f:
	CMP        word ptr [BP + 4h],0h	; param_1
	JNZ        L_138d
	ADD        word ptr [BP + -0ch],4h	; local_e
	ADD        word ptr [BP + -10h],4h	; local_12
L_138d:
	MOV        DI,word ptr [BP + -10h]	; local_12
	MOV        SI,word ptr [BP + -0ch]	; local_e
L_1393:
	CMP        byte ptr [SI],0ffh
	JZ         L_13b4
	MOV        AX,word ptr [BP + -8h]	; local_a
	AND        AX,3h
	INC        AX
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [DI]
	PUSH       AX
	CALL       SUB_0000_5dd4
	CMP        word ptr DS:[5876h],-1h
	JNZ        L_13be
L_13b4:
	MOV        word ptr [BP + -10h],DI	; local_12
	MOV        word ptr [BP + -0ch],SI	; local_e
	JMP        L_1452
	db 90h
L_13be:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [DI]
	PUSH       AX
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + 4h]	; param_1
	PUSH       SI
	PUSH       DI
	CALL       F_0f4a
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_3ee8
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	MOV        word ptr [BP + -12h],AX	; local_14
	MOV        AL,byte ptr [SI]
	AND        AX,0f8h
	MOV        word ptr [BP + -14h],AX	; local_16
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,word ptr [BP + -14h]	; local_16
	SUB        AX,8h
	PUSH       AX
	MOV        AX,word ptr [BP + -12h]	; local_14
	SUB        AX,8h
	PUSH       AX
	MOV        AX,word ptr [BP + -14h]	; local_16
	ADD        AX,0fh
	PUSH       AX
	MOV        AX,word ptr [BP + -12h]	; local_14
	ADD        AX,0fh
	PUSH       AX
	CALL       SUB_0000_28ee
	ADD        SI,word ptr [BP + -0ah]	; local_c
	ADD        DI,word ptr [BP + -0ah]	; local_c
	CMP        SI,0a872h
	JA         L_13b4
	CMP        byte ptr [SI],0ffh
	JZ         L_13b4
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_5d8e
	OR         AX,AX
	JZ         L_1434
	JMP        L_1393
L_1434:
	MOV        AX,DS:[5876h]
	CMP        word ptr [BP + 0ch],AX	; param_5
	JNZ        L_1447
	MOV        AX,DS:[5878h]
	CMP        word ptr [BP + 0ah],AX	; param_4
	JNZ        L_1447
	JMP        L_1393
L_1447:
	SUB        AX,AX
	MOV        word ptr [BP + -10h],DI	; local_12
	MOV        word ptr [BP + -0ch],SI	; local_e
	JMP        L_1455
	db 90h
L_1452:
	MOV        AX,1h
L_1455:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ah
	db 90h
	db 00h
	db 00h
F_12de ENDP
_TEXT ENDS
END
