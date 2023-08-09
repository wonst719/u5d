_TEXT SEGMENT BYTE 'CODE'
ORG 3670h
SUB_0000_3670:
ORG 4b9ah
SUB_0000_4b9a:
ORG 3d32h
SUB_0000_3d32:
ORG 34dah
SUB_0000_34da:
ORG 6bcah
SUB_0000_6bca:
ORG 6c70h
SUB_0000_6c70:
ORG 3a42h
SUB_0000_3a42:
ORG 6b96h
SUB_0000_6b96:
ORG 385eh
SUB_0000_385e:
ORG 3a12h
SUB_0000_3a12:
ORG 3abeh
SUB_0000_3abe:
ORG 39b4h
SUB_0000_39b4:
ORG 448ch
SUB_0000_448c:
ORG 3b0eh
SUB_0000_3b0e:
ORG 6c0ah
SUB_0000_6c0a:
ORG 6d1ch
SUB_0000_6d1c:
ORG 6c40h
SUB_0000_6c40:
ORG 6d5ch
SUB_0000_6d5c:
ORG 4720h
SUB_0000_4720:
ORG 8c80h
SUB_0000_8c80:
ORG 3eb2h
SUB_0000_3eb2:
ORG 61ceh
SUB_0000_61ce:
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
	PUSH       SI
	MOV        word ptr [BP + -2h],0ffffh	; local_4
	CMP        byte ptr DS:[5893h],80h
	JBE        L_002e
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_002e
	MOV        AL,byte ptr [SI + 0ba17h]
	MOV        word ptr [BP + -2h],AX	; local_4
	JMP        L_005b
L_002e:
	MOV        AX,96b4h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_4b9a
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JL         L_005b
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_3d32
	OR         AX,AX
	JZ         L_005b
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
L_005b:
	CMP        word ptr [BP + -2h],-1h	; local_4
	JNZ        L_006a
	MOV        AX,96beh
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_0077
L_006a:
	CMP        word ptr [BP + -2h],-2h	; local_4
	JNZ        L_0077
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
L_0077:
	MOV        AX,word ptr [BP + -2h]	; local_4
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0000 ENDP
F_0082 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_6bca
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -2h],AX	; local_4
	PUSH       AX
	CALL       SUB_0000_6c70
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_3a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
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
	CALL       SUB_0000_3a42
	MOV        AX,96c6h
	PUSH       AX
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0ah]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_6b96
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AX,96d0h
	PUSH       AX
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0bh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_6b96
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        BX,word ptr [BP + -4h]	; local_6
	SHL        BX,1h
	CMP        word ptr [BX + 1a58h],0h
	JLE        L_0125
	MOV        DI,word ptr [BP + -4h]	; local_6
	SHL        DI,1h
	ADD        DI,1a58h
	MOV        SI,word ptr [BP + -6h]	; local_8
L_0116:
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	INC        SI
	CMP        word ptr [DI],SI
	JG         L_0116
	MOV        word ptr [BP + -6h],SI	; local_8
L_0125:
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 9h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,96d6h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 16h]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr [BP + -4h]	; local_6
	SHL        BX,1h
	PUSH       word ptr [BX + 1a44h]
	CALL       SUB_0000_3670
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_3a42
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr [BP + -8h]	; local_a
	SHL        BX,1h
	PUSH       word ptr [BX + 1a6ah]
	CALL       SUB_0000_3670
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
	CALL       SUB_0000_3a42
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,96dch
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0ch]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,96e2h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BX + 10h]
	MOV        AX,4h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,96e8h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,96eeh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BX + 12h]
	MOV        AX,4h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,96f4h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0dh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,96fah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BX + 14h]
	MOV        AX,4h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9700h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 0fh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0082 ENDP
F_0278 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 4h],0ffh	; param_1
	JNZ        L_0286
	SUB        AX,AX
	JMP        L_02a3
L_0286:
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr [BP + 4h]	; param_1
	SHL        BX,1h
	PUSH       word ptr [BX + 1962h]
	CALL       SUB_0000_3670
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,1h
L_02a3:
	POP        BP
	RET        2h
	db 90h
	; Func
F_0278 ENDP
F_02a8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	CALL       SUB_0000_6bca
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -4h],AX	; local_6
	PUSH       AX
	CALL       SUB_0000_6c70
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_3a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0feh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,970eh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0feh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 19h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0278
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 1ah]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0278
	ADD        word ptr [BP + -2h],AX	; local_4
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 1bh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0278
	ADD        word ptr [BP + -2h],AX	; local_4
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 1ch]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0278
	ADD        word ptr [BP + -2h],AX	; local_4
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 1dh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0278
	ADD        word ptr [BP + -2h],AX	; local_4
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        AL,byte ptr [BX + 1eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0278
	ADD        word ptr [BP + -2h],AX	; local_4
	JNZ        L_037e
	SUB        AX,AX
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,9716h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0fbh
	PUSH       AX
	CALL       SUB_0000_34da
L_037e:
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
	CALL       SUB_0000_3a42
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_02a8 ENDP
F_039c PROC NEAR
	CALL       SUB_0000_6bca
	MOV        AX,9724h
	PUSH       AX
	CALL       SUB_0000_6c70
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,9h
	PUSH       AX
	CALL       SUB_0000_3a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
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
	CALL       SUB_0000_3a42
	MOV        AX,972eh
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[57a8h]
	MOV        AX,4h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9738h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr DS:[57aah]
	MOV        AX,4h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9742h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AL,DS:[57ach]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9752h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AL,DS:[57adh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	MOV        AX,9760h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AL,DS:[57aeh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	CMP        byte ptr DS:[57afh],0h
	JZ         L_045d
	MOV        AX,976eh
	PUSH       AX
	CALL       SUB_0000_3670
L_045d:
	RET
	; Func
F_039c ENDP
F_045e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	MOV        AX,18h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]	; param_1
	INC        AX
	PUSH       AX
	CALL       SUB_0000_3a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
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
	CALL       SUB_0000_3a42
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        word ptr [BP + -2h],0dh	; local_4
	MOV        SI,0dh
L_04ab:
	MOV        AX,11h
	PUSH       AX
	CALL       SUB_0000_34da
	DEC        SI
	JNZ        L_04ab
	MOV        AX,13h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        SI,1h
	MOV        DI,word ptr [BP + 4h]	; param_1
	JMP        L_04e2
L_04c4:
	SUB        AX,AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_3a12
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,0eh
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_3a12
	MOV        AX,17h
	PUSH       AX
	CALL       SUB_0000_34da
	INC        SI
L_04e2:
	CMP        SI,DI
	JNZ        L_04c4
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        word ptr [BP + -2h],0dh	; local_4
	MOV        SI,0dh
L_04ff:
	MOV        AX,15h
	PUSH       AX
	CALL       SUB_0000_34da
	DEC        SI
	JNZ        L_04ff
	MOV        AX,16h
	PUSH       AX
	CALL       SUB_0000_34da
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_045e ENDP
F_0518 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 19h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_055f
	MOV        AL,byte ptr [BX + 1ah]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_055f
	MOV        AL,byte ptr [BX + 1bh]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_055f
	MOV        AL,byte ptr [BX + 1ch]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_055f
	MOV        AL,byte ptr [BX + 1dh]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_055f
	MOV        AL,byte ptr [BX + 1eh]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JNZ        L_0564
L_055f:
	MOV        AX,1h
	JMP        L_0566
L_0564:
	SUB        AX,AX
L_0566:
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0518 ENDP
F_056c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + 4h]	; param_1
	MOV        SI,word ptr [BP + 0ah]	; param_3
L_0577:
	DEC        SI
	JS         L_0598
	MOV        BX,word ptr [BP + 6h]	; param_2
	CMP        byte ptr [BX + SI],0h
	JNZ        L_0591
	CMP        DI,0ffh
	JZ         L_0577
	PUSH       DI
	PUSH       SI
	CALL       F_0518
	OR         AX,AX
	JZ         L_0577
L_0591:
	MOV        AX,SI
	MOV        word ptr [BP + 0ah],SI	; param_3
	JMP        L_059e
L_0598:
	MOV        word ptr [BP + 0ah],SI	; param_3
	MOV        AX,0ffffh
L_059e:
	POP        SI
	POP        DI
	POP        BP
	RET        8h
	; Func
F_056c ENDP
F_05a4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	MOV        DI,word ptr [BP + 4h]	; param_1
	MOV        SI,word ptr [BP + 0ah]	; param_4
L_05af:
	INC        SI
	MOV        AX,word ptr [BP + 8h]	; param_3
	CMP        SI,AX
	JGE        L_05d6
	MOV        BX,word ptr [BP + 6h]	; param_2
	CMP        byte ptr [BX + SI],0h
	JNZ        L_05ce
	CMP        DI,0ffh
	JZ         L_05af
	PUSH       DI
	PUSH       SI
	CALL       F_0518
	OR         AX,AX
	JZ         L_05af
L_05ce:
	MOV        AX,SI
	MOV        word ptr [BP + 0ah],SI	; param_4
	JMP        L_05dc
	db 90h
L_05d6:
	MOV        word ptr [BP + 0ah],SI	; param_4
	MOV        AX,0ffffh
L_05dc:
	POP        SI
	POP        DI
	POP        BP
	RET        8h
	; Func
F_05a4 ENDP
F_05e2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        BX,word ptr [BP + 0ah]	; param_4
	MOV        SI,word ptr [BP + 8h]	; param_3
	MOV        AL,byte ptr [BX + SI]
	MOV        byte ptr [BP + -4h],AL	; local_6
	CMP        AL,0ffh
	JZ         L_062e
	OR         AL,AL
	JZ         L_060e
	SUB        AH,AH
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_385e
	JMP        L_0615
	db 90h
L_060e:
	MOV        AX,9778h
	PUSH       AX
	CALL       SUB_0000_3670
L_0615:
	CMP        word ptr [BP + 4h],20h	; param_1
	JNC        L_0622
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
L_0622:
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_34da
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
L_062e:
	MOV        BX,word ptr [BP + 0ah]	; param_4
	SHL        BX,1h
	MOV        DI,word ptr [BP + 6h]	; param_2
	MOV        SI,word ptr [BX + DI]
	CMP        byte ptr [SI],2ah
	JNZ        L_065a
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,977ch
	PUSH       AX
	CALL       SUB_0000_3670
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_3670
L_0652:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	JMP        L_06b9
L_065a:
	MOV        SI,word ptr [BP + 0ah]	; param_4
	SHL        SI,1h
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        BX,word ptr [BX + SI]
	CMP        byte ptr [BX],21h
	JNZ        L_0684
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AX,9782h
	PUSH       AX
	CALL       SUB_0000_3670
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3abe
	PUSH       word ptr [SI + 19b2h]
	JMP        L_06b6
	db 90h
L_0684:
	MOV        BX,word ptr [BP + 0ah]	; param_4
	SHL        BX,1h
	MOV        DI,word ptr [BP + 6h]	; param_2
	MOV        SI,word ptr [BX + DI]
	CMP        byte ptr [SI],28h
	JNZ        L_06ac
	MOV        AX,9788h
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3abe
	MOV        AL,byte ptr [SI + 1h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	JMP        L_0652
L_06ac:
	MOV        BX,word ptr [BP + 0ah]	; param_4
	SHL        BX,1h
	MOV        SI,word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BX + SI]
L_06b6:
	CALL       SUB_0000_3670
L_06b9:
	CALL       SUB_0000_3d32
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,0eh
	JGE        L_06d9
	MOV        AX,0eh
	SUB        AX,word ptr [BP + -2h]	; local_4
	MOV        SI,AX
	ADD        word ptr [BP + -2h],SI	; local_4
L_06cf:
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_34da
	DEC        SI
	JNZ        L_06cf
L_06d9:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_34da
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_05e2 ENDP
F_06e8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       word ptr [BP + 0ah]	; param_4
	CALL       SUB_0000_6c70
	MOV        AX,8h
	PUSH       AX
	CALL       F_045e
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        AX,0ffffh
	PUSH       AX
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
	MOV        word ptr [BP + -4h],AX	; local_6
	CMP        AX,0ffffh
	JZ         L_071c
	JMP        L_092d
L_071c:
	MOV        AX,8h
	PUSH       AX
	CALL       F_045e
	MOV        AX,1h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,9794h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_6bca
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_39b4
	CALL       SUB_0000_448c
	JMP        L_0993
	db 90h
L_0746:
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
L_0756:
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,0ffffh
	JZ         L_077f
	PUSH       AX
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	MOV        AX,2dh
	PUSH       AX
	CALL       F_05e2
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3b0e
	PUSH       AX
	CALL       SUB_0000_3a12
	CALL       SUB_0000_3b0e
	CMP        AX,8h
	JNZ        L_0746
L_077f:
	MOV        word ptr [BP + -0eh],0h	; local_10
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_056c
	INC        AX
	JZ         L_079c
	MOV        word ptr [BP + -0eh],2h	; local_10
L_079c:
	CMP        word ptr [BP + -0ah],-1h	; local_c
	JZ         L_07b8
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
	INC        AX
	JZ         L_07b8
	INC        word ptr [BP + -0eh]	; local_10
L_07b8:
	MOV        AX,word ptr [BP + -0eh]	; local_10
	OR         AX,AX
	JZ         L_07d0
	CMP        AX,1h
	JZ         L_0806
	CMP        AX,2h
	JZ         L_0810
	CMP        AX,3h
	JZ         L_0816
	JMP        L_07d3
L_07d0:
	CALL       SUB_0000_6bca
L_07d3:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_39b4
	CALL       SUB_0000_448c
	MOV        word ptr [BP + -0ch],AX	; local_e
	CMP        AX,20h
	JNZ        L_07e8
	JMP        L_0948
L_07e8:
	JLE        L_07ed
	JMP        L_0960
L_07ed:
	CMP        AX,3h
	JZ         L_081c
	JLE        L_07f7
	JMP        L_0950
L_07f7:
	CMP        AX,1h
	JGE        L_07ff
	JMP        L_092d
L_07ff:
	CMP        AX,2h
	JMP        L_0972
	db 90h
L_0806:
	MOV        AX,19h
L_0809:
	PUSH       AX
	CALL       SUB_0000_6c0a
	JMP        L_07d3
	db 90h
L_0810:
	MOV        AX,18h
	JMP        L_0809
	db 90h
L_0816:
	MOV        AX,12h
	JMP        L_0809
	db 90h
L_081c:
	CMP        word ptr [BP + -0ch],0d5h	; local_e
	JNZ        L_082a
	MOV        word ptr [BP + -2h],7h	; local_4
	JMP        L_082f
L_082a:
	MOV        word ptr [BP + -2h],1h	; local_4
L_082f:
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_0839
L_0836:
	INC        word ptr [BP + -8h]	; local_a
L_0839:
	MOV        AX,word ptr [BP + -2h]	; local_4
	CMP        word ptr [BP + -8h],AX	; local_a
	JL         L_0844
	JMP        L_092d
L_0844:
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_056c
	INC        AX
	JZ         L_0836
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_056c
	MOV        word ptr [BP + -4h],AX	; local_6
	JMP        L_0836
L_086c:
	CMP        word ptr [BP + -0ch],0d6h	; local_e
	JNZ        L_087a
	MOV        word ptr [BP + -2h],7h	; local_4
	JMP        L_087f
L_087a:
	MOV        word ptr [BP + -2h],1h	; local_4
L_087f:
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_0889
L_0886:
	INC        word ptr [BP + -8h]	; local_a
L_0889:
	MOV        AX,word ptr [BP + -2h]	; local_4
	CMP        word ptr [BP + -8h],AX	; local_a
	JL         L_0894
	JMP        L_092d
L_0894:
	CMP        word ptr [BP + -0ah],-1h	; local_c
	JZ         L_0886
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
	INC        AX
	JZ         L_0886
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
	MOV        word ptr [BP + -4h],AX	; local_6
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
	MOV        word ptr [BP + -0ah],AX	; local_c
	JMP        L_0886
	db 90h
L_08d6:
	MOV        AX,0ffffh
	PUSH       AX
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_05a4
	MOV        word ptr [BP + -4h],AX	; local_6
	JMP        L_092d
L_08ec:
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_056c
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        word ptr [BP + -8h],0h	; local_a
	JMP        L_090f
L_0906:
	MOV        AX,word ptr [BP + -0ah]	; local_c
	MOV        word ptr [BP + -4h],AX	; local_6
	INC        word ptr [BP + -8h]	; local_a
L_090f:
	CMP        word ptr [BP + -8h],6h	; local_a
	JGE        L_092d
	PUSH       word ptr [BP + -4h]	; local_6
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + 6h]	; param_2
	MOV        AX,0ffh
	PUSH       AX
	CALL       F_056c
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,0ffffh
	JNZ        L_0906
L_092d:
	CMP        word ptr [BP + -6h],0h	; local_8
	JNZ        L_0990
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_39b4
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,word ptr [BP + -4h]	; local_6
	JMP        L_0756
L_0948:
	MOV        word ptr [BP + -6h],1h	; local_8
	JMP        L_092d
	db 90h
L_0950:
	CMP        AX,4h
	JNZ        L_0958
	JMP        L_086c
L_0958:
	CMP        AX,1bh
	JZ         L_0948
	JMP        L_092d
	db 90h
L_0960:
	CMP        AX,0d3h
	JNZ        L_0968
	JMP        L_08d6
L_0968:
	JG         L_0976
	CMP        AX,30h
	JL         L_092d
	CMP        AX,36h
L_0972:
	JLE        L_0948
	JMP        L_092d
L_0976:
	CMP        AX,0d4h
	JNZ        L_097e
	JMP        L_08ec
L_097e:
	CMP        AX,0d5h
	JNZ        L_0986
	JMP        L_081c
L_0986:
	CMP        AX,0d6h
	JNZ        L_098e
	JMP        L_086c
L_098e:
	JMP        L_092d
L_0990:
	MOV        AX,word ptr [BP + -0ch]	; local_e
L_0993:
	MOV        SP,BP
	POP        BP
	RET        8h
	db 90h
	; Func
F_06e8 ENDP
F_099a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
L_09a4:
	MOV        AL,byte ptr [SI + 5820h]
	MOV        byte ptr [SI + 0b9eeh],AL
	MOV        AL,byte ptr [SI + 5828h]
	MOV        byte ptr [SI + 0b9f6h],AL
	CMP        byte ptr [SI + 5840h],0ffh
	JNZ        L_09c0
	MOV        AL,0ffh
	JMP        L_09c2
	db 90h
L_09c0:
	SUB        AL,AL
L_09c2:
	MOV        byte ptr [SI + 0ba03h],AL
	INC        SI
	CMP        SI,8h
	JL         L_09a4
	MOV        word ptr [BP + -2h],SI	; local_4
	MOV        AL,DS:[57b0h]
	MOV        DS:[0b9feh],AL
	MOV        AL,DS:[57b1h]
	MOV        DS:[0b9ffh],AL
	MOV        AL,DS:[57b3h]
	MOV        DS:[0ba00h],AL
	MOV        AL,DS:[57b4h]
	MOV        DS:[0ba01h],AL
	MOV        AL,DS:[57b5h]
	MOV        DS:[0ba02h],AL
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        CX,1h
	MOV        DI,0ba0bh
	MOV        SI,57b6h
	PUSH       DS
	POP        ES
	REP MOVSW
	MOVSB
	ADD        word ptr [BP + -2h],3h	; local_4
	MOV        AL,DS:[57bah]
	MOV        DS:[0ba0eh],AL
	CMP        byte ptr DS:[57bbh],0h
	JZ         L_0a16
	MOV        AL,0ffh
	JMP        L_0a18
	db 90h
L_0a16:
	SUB        AL,AL
L_0a18:
	MOV        DS:[0ba0fh],AL
	MOV        AL,DS:[57bch]
	MOV        DS:[0ba10h],AL
	MOV        AL,DS:[57bdh]
	MOV        DS:[0ba11h],AL
	MOV        AL,DS:[57beh]
	MOV        DS:[0ba12h],AL
	MOV        AL,DS:[57bfh]
	MOV        DS:[0ba13h],AL
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_099a ENDP
F_0a3a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	MOV        AX,1h
	PUSH       AX
	CALL       F_0000
	MOV        word ptr [BP + -6h],AX	; local_8
	CMP        AX,0fffeh
	JNZ        L_0a56
	MOV        word ptr [BP + -6h],6h	; local_8
	JMP        L_0a5f
L_0a56:
	CMP        word ptr [BP + -6h],0h	; local_8
	JGE        L_0a5f
	JMP        L_0be9
L_0a5f:
	MOV        AX,97a2h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       F_099a
	CALL       SUB_0000_6d1c
	MOV        AX,word ptr [BP + -6h]	; local_8
	SHL        AX,1h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        byte ptr [BP + -4h],0h	; local_6
L_0a78:
	CMP        byte ptr [BP + -4h],20h	; local_6
	JNZ        L_0a81
	JMP        L_0bd6
L_0a81:
	CMP        byte ptr [BP + -4h],1bh	; local_6
	JNZ        L_0a8a
	JMP        L_0bd6
L_0a8a:
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	CMP        AX,3h
	JZ         L_0aa6
	JBE        L_0a99
	JMP        L_0b32
L_0a99:
	CMP        AX,1h
	JZ         L_0aa6
	CMP        AX,2h
	JZ         L_0aea
	JMP        L_0acb
	db 90h
L_0aa6:
	CMP        word ptr [BP + -2h],0ch	; local_4
	JNZ        L_0aba
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	SHL        AX,1h
	DEC        AX
L_0ab4:
	MOV        word ptr [BP + -2h],AX	; local_4
	JMP        L_0acb
	db 90h
L_0aba:
	CMP        word ptr [BP + -2h],0h	; local_4
	JLE        L_0ac6
	DEC        word ptr [BP + -2h]	; local_4
	JMP        L_0acb
	db 90h
L_0ac6:
	MOV        word ptr [BP + -2h],10h	; local_4
L_0acb:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_39b4
	CMP        word ptr [BP + -2h],0ch	; local_4
	JGE        L_0b56
	TEST       byte ptr [BP + -2h],1h	; local_4
	JZ         L_0b4a
	MOV        AX,word ptr [BP + -2h]	; local_4
	SAR        AX,1h
	PUSH       AX
	CALL       F_02a8
	JMP        L_0b5f
	db 90h
L_0aea:
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	SHL        AX,1h
	DEC        AX
	CMP        AX,word ptr [BP + -2h]	; local_4
	JNZ        L_0afe
L_0af7:
	MOV        word ptr [BP + -2h],0ch	; local_4
	JMP        L_0acb
L_0afe:
	CMP        word ptr [BP + -2h],10h	; local_4
	JGE        L_0b0a
	INC        word ptr [BP + -2h]	; local_4
	JMP        L_0acb
	db 90h
L_0b0a:
	MOV        word ptr [BP + -2h],0h	; local_4
	JMP        L_0acb
	db 90h
L_0b12:
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	SUB        AX,31h
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JNC        L_0acb
	MOV        AL,byte ptr [BP + -4h]	; local_6
	SUB        AH,AH
	SHL        AX,1h
	SUB        AX,62h
	JMP        L_0ab4
	db 90h
	db 90h
L_0b32:
	CMP        AX,4h
	JZ         L_0aea
	CMP        AX,30h
	JZ         L_0af7
	CMP        AX,31h
	JC         L_0acb
	CMP        AX,36h
	JBE        L_0b12
	JMP        L_0acb
	db 90h
	db 90h
L_0b4a:
	MOV        AX,word ptr [BP + -2h]	; local_4
	SAR        AX,1h
	PUSH       AX
	CALL       F_0082
	JMP        L_0b5f
	db 90h
L_0b56:
	CMP        word ptr [BP + -2h],0ch	; local_4
	JNZ        L_0b70
	CALL       F_039c
L_0b5f:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_39b4
	CALL       SUB_0000_448c
L_0b69:
	MOV        byte ptr [BP + -4h],AL	; local_6
	JMP        L_0a78
	db 90h
L_0b70:
	MOV        AX,word ptr [BP + -2h]	; local_4
	CMP        AX,0dh
	JZ         L_0b8a
	CMP        AX,0eh
	JZ         L_0ba0
	CMP        AX,0fh
	JZ         L_0bb2
	CMP        AX,10h
	JZ         L_0bc4
	JMP        L_0a78
L_0b8a:
	MOV        AX,97ach
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	MOV        AX,5850h
	PUSH       AX
	MOV        AX,19d2h
L_0b99:
	PUSH       AX
	CALL       F_06e8
	JMP        L_0b69
	db 90h
L_0ba0:
	MOV        AX,97b6h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57f0h
	PUSH       AX
	MOV        AX,19e2h
	JMP        L_0b99
	db 90h
L_0bb2:
	MOV        AX,97beh
	PUSH       AX
	MOV        AX,26h
	PUSH       AX
	MOV        AX,0b9eeh
	PUSH       AX
	MOV        AX,1916h
	JMP        L_0b99
	db 90h
L_0bc4:
	MOV        AX,97c4h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	MOV        AX,1962h
	JMP        L_0b99
	db 90h
L_0bd6:
	CALL       SUB_0000_6bca
	CALL       SUB_0000_6c40
	CALL       SUB_0000_6d5c
	CALL       SUB_0000_4720
	MOV        AX,97ceh
	PUSH       AX
	CALL       SUB_0000_3670
L_0be9:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0a3a ENDP
F_0bee PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,97d4h
	PUSH       AX
	CALL       SUB_0000_3670
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_3670
	MOV        AX,97d8h
	PUSH       AX
	CALL       SUB_0000_3670
	POP        BP
	RET        2h
	db 90h
	; Func
F_0bee ENDP
F_0c0a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	CMP        byte ptr [BX + 1bh],0ffh
	JNZ        L_0c30
	CMP        byte ptr [BX + 1ch],0ffh
	JNZ        L_0c30
	MOV        AX,2h
	JMP        L_0c55
L_0c30:
	CMP        byte ptr [BX + 1bh],0ffh
	JNZ        L_0c3a
	SUB        AX,AX
	JMP        L_0c55
L_0c3a:
	CMP        byte ptr [BX + 1ch],0ffh
	JNZ        L_0c52
	MOV        BL,byte ptr [BX + 1bh]
	SUB        BH,BH
	CMP        byte ptr [BX + 1a7eh],30h
	JZ         L_0c52
	MOV        AX,1h
	JMP        L_0c55
	db 90h
L_0c52:
	MOV        AX,0ffh
L_0c55:
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0c0a ENDP
F_0c5c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       SI
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_0c82
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba18h]
	SUB        AH,AH
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -4h],AX	; local_6
L_0c82:
	CMP        word ptr [BP + 4h],1bh	; param_1
	JZ         L_0c8e
	CMP        word ptr [BP + 4h],1dh	; param_1
	JNZ        L_0c94
L_0c8e:
	SUB        AX,AX
	JMP        L_0f26
	db 90h
L_0c94:
	CMP        word ptr [BP + 4h],9h	; param_1
	JL         L_0cb4
	CMP        word ptr [BP + 4h],0fh	; param_1
	JG         L_0cb4
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_0cb4
	CMP        byte ptr DS:[58a3h],0h
	JNZ        L_0cb4
	MOV        AX,97e2h
	JMP        L_0d2f
	db 90h
L_0cb4:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_0518
	OR         AX,AX
	JZ         L_0d0c
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       SUB_0000_8c80
	MOV        BX,word ptr [BP + 4h]	; param_1
	CMP        byte ptr [BX + 57c0h],63h
	JNC        L_0cd8
	INC        byte ptr [BX + 57c0h]
L_0cd8:
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_0c8e
	CMP        BX,2ah
	JNZ        L_0c8e
	MOV        AX,9812h
	PUSH       AX
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b2h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_6b96
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        SI,AX
	MOV        AL,byte ptr [SI + 1adeh]
	MOV        byte ptr [BX + 1h],AL
L_0d08:
	MOV        byte ptr [BX],AL
	JMP        L_0c8e
L_0d0c:
	CMP        word ptr [BP + 4h],1ah	; param_1
	JZ         L_0d18
	CMP        word ptr [BP + 4h],24h	; param_1
	JNZ        L_0d1f
L_0d18:
	CMP        byte ptr DS:[57dbh],0h
	JZ         L_0d2c
L_0d1f:
	CMP        word ptr [BP + 4h],1ch	; param_1
	JNZ        L_0d36
	CMP        byte ptr DS:[57ddh],0h
	JNZ        L_0d36
L_0d2c:
	MOV        AX,981ch
L_0d2f:
	PUSH       AX
	CALL       F_0bee
	JMP        L_0c8e
L_0d36:
	SUB        DX,DX
	MOV        SI,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        SI,CL
	ADD        SI,55c1h
	MOV        word ptr [BP + -8h],6h	; local_a
	MOV        word ptr [BP + -10h],6h	; local_12
	MOV        CX,word ptr [BP + -10h]	; local_12
L_0d50:
	CMP        byte ptr [SI],0ffh
	JZ         L_0d61
	MOV        BL,byte ptr [SI]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 1aaeh]
	SUB        AH,AH
	ADD        DX,AX
L_0d61:
	INC        SI
	LOOP       L_0d50
	MOV        word ptr [BP + -0eh],SI	; local_10
	MOV        word ptr [BP + -2h],DX	; local_4
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 1aaeh]
	SUB        AH,AH
	ADD        AX,DX
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	MOV        CL,byte ptr [BX + 55b4h]
	SUB        CH,CH
	CMP        AX,CX
	JA         L_0d8c
	MOV        AX,1h
	JMP        L_0d8e
	db 90h
L_0d8c:
	SUB        AX,AX
L_0d8e:
	MOV        word ptr [BP + -0ch],AX	; local_e
	MOV        BX,word ptr [BP + 4h]	; param_1
	MOV        AL,byte ptr [BX + 1a7eh]
	SUB        AH,AH
	CMP        AX,2h
	JNZ        L_0da2
	JMP        L_0ede
L_0da2:
	CMP        AX,4h
	JNZ        L_0daa
	JMP        L_0ebc
L_0daa:
	CMP        AX,20h
	JNZ        L_0db2
	JMP        L_0e6e
L_0db2:
	CMP        AX,30h
	JNZ        L_0dba
	JMP        L_0e9e
L_0dba:
	CMP        AX,40h
	JNZ        L_0dc2
	JMP        L_0e4c
L_0dc2:
	CMP        AX,80h
	JNZ        L_0de9
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55c1h],0ffh
	JZ         L_0ddc
	MOV        AX,9846h
	JMP        L_0d2f
	db 90h
L_0ddc:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55c1h
L_0de6:
	MOV        word ptr [BP + -0eh],AX	; local_10
L_0de9:
	CMP        word ptr [BP + -0ch],0h	; local_e
	JNZ        L_0df2
	JMP        L_0f00
L_0df2:
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        AL,byte ptr [BP + 4h]	; param_1
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + 4h]	; param_1
	DEC        byte ptr [BX + 57c0h]
	CMP        BX,2ah
	JZ         L_0e0e
	CMP        BX,2ch
	JZ         L_0e0e
	JMP        L_0f06
L_0e0e:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_3eb2
	OR         AX,AX
	JZ         L_0e1f
	JMP        L_0f06
L_0e1f:
	MOV        AX,995eh
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55c5h],0ffh
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_61ce
	MOV        AX,1h
	JMP        L_0f26
	db 90h
L_0e4c:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55c2h],0ffh
	JZ         L_0e60
	MOV        AX,9866h
	JMP        L_0d2f
L_0e60:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55c2h
	JMP        L_0de6
	db 90h
L_0e6e:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0c0a
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,0ffh
	JNZ        L_0e82
	MOV        AX,9892h
	JMP        L_0d2f
L_0e82:
	CMP        word ptr [BP + -0ah],2h	; local_c
	JNZ        L_0e8d
	MOV        word ptr [BP + -0ah],0h	; local_c
L_0e8d:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,word ptr [BP + -0ah]	; local_c
L_0e97:
	ADD        AX,55c3h
	JMP        L_0de6
	db 90h
L_0e9e:
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_0c0a
	MOV        word ptr [BP + -0ah],AX	; local_c
	CMP        AX,2h
	JZ         L_0eb2
	MOV        AX,98bah
	JMP        L_0d2f
L_0eb2:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	JMP        L_0e97
	db 90h
L_0ebc:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55c6h],0ffh
	JZ         L_0ed0
	MOV        AX,98f0h
	JMP        L_0d2f
L_0ed0:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55c6h
	JMP        L_0de6
	db 90h
L_0ede:
	MOV        BX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55c5h],0ffh
	JZ         L_0ef2
	MOV        AX,9916h
	JMP        L_0d2f
L_0ef2:
	MOV        AX,word ptr [BP + 6h]	; param_2
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55c5h
	JMP        L_0de6
	db 90h
L_0f00:
	MOV        AX,9942h
	JMP        L_0d2f
L_0f06:
	CMP        word ptr [BP + 4h],2ah	; param_1
	JZ         L_0f0f
	JMP        L_0c8e
L_0f0f:
	CMP        byte ptr DS:[5893h],7fh
	JA         L_0f19
	JMP        L_0c8e
L_0f19:
	MOV        BX,word ptr [BP + -4h]	; local_6
	MOV        SI,BX
	MOV        AL,1dh
	MOV        byte ptr [SI + 1h],AL
	JMP        L_0d08
L_0f26:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0c5c ENDP
F_0f2e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ch
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        word ptr [BP + -0eh],1h	; local_10
	CMP        word ptr [BP + 4h],52h	; param_1
	JNZ        L_0f54
	MOV        word ptr [BP + -12h],57c0h	; local_14
	MOV        word ptr [BP + -8h],30h	; local_a
	JMP        L_1282
	db 90h
L_0f54:
	MOV        word ptr [BP + -12h],0b9eeh	; local_14
	MOV        word ptr [BP + -8h],26h	; local_a
	JMP        L_1282
	db 90h
L_0f62:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_39b4
	MOV        AX,1h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        word ptr [BP + -2h],0h	; local_4
	MOV        AX,word ptr [BP + 8h]	; param_3
	JMP        L_102b
L_0f7c:
	MOV        word ptr [BP + -0ah],20h	; local_c
L_0f81:
	PUSH       word ptr [BP + -10h]	; local_12
	PUSH       word ptr [BP + -12h]	; local_14
	MOV        AX,1962h
	PUSH       AX
	PUSH       word ptr [BP + -0ah]	; local_c
	JMP        L_0f9e
L_0f90:
	PUSH       word ptr [BP + -10h]	; local_12
	PUSH       word ptr [BP + -12h]	; local_14
	MOV        AX,1916h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
L_0f9e:
	CALL       F_05e2
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3b0e
	PUSH       AX
	CALL       SUB_0000_3a12
	CALL       SUB_0000_3b0e
	DEC        AX
	CMP        AX,word ptr [BP + -0eh]	; local_10
	JNZ        L_0fbc
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_34da
L_0fbc:
	CALL       SUB_0000_3b0e
	CMP        AX,8h
	JNZ        L_101c
L_0fc4:
	MOV        word ptr [BP + -16h],0h	; local_18
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_056c
	INC        AX
	JZ         L_0fe0
	MOV        word ptr [BP + -16h],2h	; local_18
L_0fe0:
	CMP        word ptr [BP + -10h],-1h	; local_12
	JZ         L_0ffb
	PUSH       word ptr [BP + -10h]	; local_12
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_05a4
	INC        AX
	JZ         L_0ffb
	INC        word ptr [BP + -16h]	; local_18
L_0ffb:
	MOV        AX,word ptr [BP + -16h]	; local_18
	OR         AX,AX
	JZ         L_1074
	CMP        AX,1h
	JNZ        L_100a
	JMP        L_10aa
L_100a:
	CMP        AX,2h
	JNZ        L_1012
	JMP        L_10b4
L_1012:
	CMP        AX,3h
	JNZ        L_101a
	JMP        L_10ba
L_101a:
	JMP        L_1077
L_101c:
	PUSH       word ptr [BP + -10h]	; local_12
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_05a4
L_102b:
	MOV        word ptr [BP + -10h],AX	; local_12
	CMP        AX,0ffffh
	JZ         L_0fc4
	INC        word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_3b0e
	CMP        AX,word ptr [BP + -0eh]	; local_10
	JNZ        L_104b
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,word ptr [BP + -10h]	; local_12
	MOV        word ptr [BP + -18h],AX	; local_1a
L_104b:
	CMP        word ptr [BP + 4h],52h	; param_1
	JZ         L_1054
	JMP        L_0f90
L_1054:
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -10h]	; local_12
	CALL       F_0518
	OR         AX,AX
	JNZ        L_1064
	JMP        L_0f7c
L_1064:
	MOV        BX,word ptr [BP + -10h]	; local_12
	MOV        AL,byte ptr [BX + 1ae8h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX	; local_c
	JMP        L_0f81
	db 90h
L_1074:
	CALL       SUB_0000_6bca
L_1077:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_39b4
	CALL       SUB_0000_448c
	MOV        word ptr [BP + -14h],AX	; local_16
	CMP        AX,0dh
	JNZ        L_108c
	JMP        L_121c
L_108c:
	JLE        L_1091
	JMP        L_1258
L_1091:
	CMP        AX,1h
	JZ         L_10c0
	CMP        AX,2h
	JNZ        L_109e
	JMP        L_1130
L_109e:
	CMP        AX,3h
	JZ         L_10c0
	CMP        AX,4h
	JMP        L_127d
	db 90h
L_10aa:
	MOV        AX,19h
L_10ad:
	PUSH       AX
	CALL       SUB_0000_6c0a
	JMP        L_1077
	db 90h
L_10b4:
	MOV        AX,18h
	JMP        L_10ad
	db 90h
L_10ba:
	MOV        AX,12h
	JMP        L_10ad
	db 90h
L_10c0:
	CMP        word ptr [BP + -14h],0d5h	; local_16
	JNZ        L_10ce
	MOV        word ptr [BP + -4h],7h	; local_6
	JMP        L_10d3
L_10ce:
	MOV        word ptr [BP + -4h],1h	; local_6
L_10d3:
	MOV        word ptr [BP + -0ch],0h	; local_e
	CMP        word ptr [BP + -4h],0h	; local_6
	JG         L_10e1
	JMP        L_1282
L_10e1:
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BP + -1ah],AX	; local_1c
	ADD        word ptr [BP + -0ch],AX	; local_e
	MOV        DI,word ptr [BP + 8h]	; param_3
	MOV        SI,word ptr [BP + -0eh]	; local_10
L_10f0:
	CMP        SI,4h
	JZ         L_10fa
	CMP        SI,1h
	JNZ        L_1121
L_10fa:
	PUSH       DI
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_056c
	INC        AX
	JZ         L_111c
	PUSH       DI
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_056c
	MOV        DI,AX
	JMP        L_1122
	db 90h
L_111c:
	CMP        SI,4h
	JNZ        L_1122
L_1121:
	DEC        SI
L_1122:
	DEC        word ptr [BP + -1ah]	; local_1c
	JNZ        L_10f0
	MOV        word ptr [BP + 8h],DI	; param_3
L_112a:
	MOV        word ptr [BP + -0eh],SI	; local_10
	JMP        L_1282
L_1130:
	CMP        word ptr [BP + -14h],0d6h	; local_16
	JNZ        L_113e
	MOV        word ptr [BP + -4h],7h	; local_6
	JMP        L_1143
L_113e:
	MOV        word ptr [BP + -4h],1h	; local_6
L_1143:
	MOV        word ptr [BP + -0ch],0h	; local_e
	CMP        word ptr [BP + -4h],0h	; local_6
	JG         L_1151
	JMP        L_1282
L_1151:
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        word ptr [BP + -1ch],AX	; local_1e
	ADD        word ptr [BP + -0ch],AX	; local_e
	MOV        DI,word ptr [BP + -10h]	; local_12
	MOV        SI,word ptr [BP + -0eh]	; local_10
L_1160:
	CMP        SI,4h
	JZ         L_116f
	CMP        SI,7h
	JZ         L_116f
	CMP        SI,word ptr [BP + -2h]	; local_4
	JL         L_11b3
L_116f:
	CMP        DI,-1h
	JZ         L_11a8
	PUSH       DI
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_05a4
	INC        AX
	JZ         L_11a8
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_05a4
	MOV        word ptr [BP + 8h],AX	; param_3
	PUSH       DI
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_05a4
	MOV        DI,AX
	JMP        L_11b4
	db 90h
L_11a8:
	CMP        SI,4h
	JNZ        L_11b4
	CMP        word ptr [BP + -2h],4h	; local_4
	JLE        L_11b4
L_11b3:
	INC        SI
L_11b4:
	DEC        word ptr [BP + -1ch]	; local_1e
	JNZ        L_1160
	MOV        word ptr [BP + -10h],DI	; local_12
	JMP        L_112a
	db 90h
L_11c0:
	MOV        AX,0ffffh
	PUSH       AX
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_05a4
	MOV        word ptr [BP + 8h],AX	; param_3
	MOV        word ptr [BP + -0eh],1h	; local_10
	JMP        L_1282
	db 90h
L_11dc:
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_056c
	MOV        word ptr [BP + 8h],AX	; param_3
	MOV        DI,1h
L_11f1:
	PUSH       word ptr [BP + 8h]	; param_3
	PUSH       word ptr [BP + -8h]	; local_a
	PUSH       word ptr [BP + -12h]	; local_14
	PUSH       word ptr [BP + 6h]	; param_2
	CALL       F_056c
	MOV        SI,AX
	CMP        SI,-1h
	JNZ        L_1210
L_1207:
	MOV        word ptr [BP + -0eh],DI	; local_10
	MOV        word ptr [BP + -18h],SI	; local_1a
	JMP        L_1282
	db 90h
L_1210:
	MOV        word ptr [BP + 8h],SI	; param_3
	INC        DI
	CMP        DI,7h
	JGE        L_1207
	JMP        L_11f1
	db 90h
L_121c:
	CMP        word ptr [BP + 4h],52h	; param_1
	JNZ        L_1230
	PUSH       word ptr [BP + 6h]	; param_2
	PUSH       word ptr [BP + -18h]	; local_1a
	CALL       F_0c5c
	MOV        word ptr [BP + -6h],AX	; local_8
	JMP        L_1282
L_1230:
	MOV        word ptr [BP + -6h],1h	; local_8
	JMP        L_1282
	db 90h
L_1238:
	CMP        word ptr [BP + 4h],52h	; param_1
	JNZ        L_1244
	MOV        AX,9970h
	JMP        L_1247
	db 90h
L_1244:
	MOV        AX,9976h
L_1247:
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        word ptr [BP + -6h],1h	; local_8
	MOV        word ptr [BP + -18h],0ffffh	; local_1a
	JMP        L_1282
	db 90h
L_1258:
	CMP        AX,1bh
	JZ         L_1238
	CMP        AX,20h
	JZ         L_121c
	CMP        AX,0d3h
	JNZ        L_126a
	JMP        L_11c0
L_126a:
	CMP        AX,0d4h
	JNZ        L_1272
	JMP        L_11dc
L_1272:
	CMP        AX,0d5h
	JNZ        L_127a
	JMP        L_10c0
L_127a:
	CMP        AX,0d6h
L_127d:
	JNZ        L_1282
	JMP        L_1130
L_1282:
	CMP        word ptr [BP + -6h],0h	; local_8
	JNZ        L_128b
	JMP        L_0f62
L_128b:
	MOV        AX,word ptr [BP + -18h]	; local_1a
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0f2e ENDP
F_1296 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	SUB        AX,AX
	PUSH       AX
	CALL       F_0000
	MOV        word ptr [BP + -4h],AX	; local_6
	OR         AX,AX
	JL         L_130b
	MOV        AX,0ffffh
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	MOV        AX,57c0h
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       F_05a4
	MOV        word ptr [BP + -2h],AX	; local_4
	CMP        AX,0ffffh
	JNZ        L_12cc
	MOV        AX,997eh
	PUSH       AX
	CALL       SUB_0000_3670
	JMP        L_130b
L_12cc:
	MOV        AX,9998h
	PUSH       AX
	CALL       SUB_0000_3670
	CALL       SUB_0000_6d1c
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_39b4
	MOV        AX,word ptr [BP + -4h]	; local_6
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_6c70
	MOV        AX,8h
	PUSH       AX
	CALL       F_045e
	PUSH       word ptr [BP + -2h]	; local_4
	PUSH       word ptr [BP + -4h]	; local_6
	MOV        AX,52h
	PUSH       AX
	CALL       F_0f2e
	CALL       SUB_0000_6bca
	CALL       SUB_0000_6c40
	CALL       SUB_0000_6d5c
	CALL       SUB_0000_4720
L_130b:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
F_1296 ENDP
_TEXT ENDS
END
