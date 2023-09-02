_TEXT SEGMENT BYTE 'CODE'
ORG 828eh
SUB_0000_828e:
ORG 6d1eh
SUB_0000_6d1e:
ORG 691eh
SUB_0000_691e:
ORG 6cb6h
SUB_0000_6cb6:
ORG 7904h
SUB_0000_7904:
ORG 6954h
SUB_0000_6954:
ORG 6992h
SUB_0000_6992:
ORG 742ah
SUB_0000_742a:
ORG 6abch
SUB_0000_6abc:
ORG 82deh
SUB_0000_82de:
ORG 0da56h
SUB_0000_da56:
ORG 7aceh
SUB_0000_7ace:
ORG 6cdeh
SUB_0000_6cde:
ORG 6d4ch
SUB_0000_6d4c:
ORG 75c0h
SUB_0000_75c0:
ORG 7962h
SUB_0000_7962:
ORG 7a0eh
SUB_0000_7a0e:
ORG 6196h
SUB_0000_6196:
ORG 9856h
SUB_0000_9856:
ORG 0a0aeh
SUB_0000_a0ae:
ORG 7e02h
SUB_0000_7e02:
ORG 8670h
SUB_0000_8670:
ORG 0cd0eh
SUB_0000_cd0e:
ORG 67e0h
SUB_0000_67e0:
ORG 68f6h
SUB_0000_68f6:
ORG 7f02h
SUB_0000_7f02:
ORG 0aae6h
SUB_0000_aae6:
ORG 83dch
SUB_0000_83dc:
ORG 6e50h
SUB_0000_6e50:
ORG 6d9eh
SUB_0000_6d9e:
ORG 6816h
SUB_0000_6816:
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
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_828e ; 1000:251Eh
L_000f:
	PUSH       word ptr DS:[25eah]
	CALL       SUB_0000_6d1e ; 1000:0FAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_000f
	MOV        word ptr [BP + -0ah],SI	; local_c
L_001f:
	PUSH       word ptr DS:[260ch]
	CALL       SUB_0000_691e ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_001f
	MOV        word ptr [BP + -2h],SI	; local_4
L_002f:
	PUSH       word ptr DS:[261ah]
	CALL       SUB_0000_691e ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_002f
	MOV        word ptr [BP + -4h],SI	; local_6
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,13fh
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_6cb6 ; 1000:0F46h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7904 ; 1000:1B94h
	MOV        word ptr [BP + -8h],31h	; local_a
	MOV        word ptr [BP + -6h],0h	; local_8
	MOV        word ptr [BP + -0eh],3da6h	; local_10
	MOV        word ptr [BP + -10h],3da7h	; local_12
	MOV        word ptr [BP + -12h],3db2h	; local_14
	MOV        word ptr [BP + -14h],3db4h	; local_16
	MOV        word ptr [BP + -16h],3dcah	; local_18
L_0077:
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX + 3df4h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]	; local_a
	JZ         L_00a8
	PUSH       SI
	CALL       SUB_0000_6954 ; 1000:0BE4h
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX + 3df4h]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX	; local_a
	MOV        DI,AX
	SHL        DI,1h
	ADD        DI,261ah
L_009d:
	PUSH       word ptr [DI]
	CALL       SUB_0000_691e ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_009d
L_00a8:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992 ; 1000:0C22h
	MOV        byte ptr DS:[0a9beh],2h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	MOV        BX,word ptr [BP + -6h]	; local_8
	CMP        byte ptr [BX + 3e06h],1h
	JNZ        L_00fc
	MOV        AX,BX
	OR         AX,AX
	JZ         L_00d6
	CMP        AX,3h
	JNZ        L_00d3
	JMP        L_01c4
L_00d3:
	JMP        L_00fc
	db 90h
L_00d6:
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0d8h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6abc ; 1000:0D4Ch
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,4h
	PUSH       AX
	MOV        AX,98h
	PUSH       AX
	MOV        AX,1ch
L_00f5:
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6abc ; 1000:0D4Ch
L_00fc:
	PUSH       SI
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX + 3deeh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 3dfah]
	PUSH       AX
	MOV        AL,byte ptr [BX + 3e00h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6abc ; 1000:0D4Ch
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        DS:[5146h],AX
	MOV        BX,word ptr [BP + -10h]	; local_12
	MOV        AL,byte ptr [BX]
	MOV        DS:[5148h],AX
	MOV        BX,word ptr [BP + -12h]	; local_14
	MOV        AX,word ptr [BX]
	MOV        DS:[514ch],AX
	MOV        BX,word ptr [BP + -14h]	; local_16
	MOV        AX,word ptr [BX]
	MOV        DS:[514eh],AX
	MOV        BX,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [BX + 3dd6h]
	SUB        AH,AH
	MOV        DS:[5150h],AX
	MOV        AL,byte ptr [BX + 3ddch]
	MOV        DS:[5152h],AX
	MOV        AL,byte ptr [BX + 3de2h]
	MOV        DS:[5156h],AX
	MOV        AL,byte ptr [BX + 3de8h]
	MOV        DS:[5158h],AX
	MOV        AX,81feh
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        BX,word ptr [BP + -16h]	; local_18
	PUSH       word ptr [BX]
	CALL       SUB_0000_82de ; 1000:256Eh
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_da56 ; 1000:7CE6h
	CMP        word ptr [BP + -6h],0h	; local_8
	JZ         L_0185
L_017e:
	CALL       SUB_0000_7ace ; 1000:1D5Eh
	OR         AX,AX
	JZ         L_017e
L_0185:
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6cde ; 1000:0F6Eh
	ADD        word ptr [BP + -0eh],2h	; local_10
	ADD        word ptr [BP + -10h],2h	; local_12
	ADD        word ptr [BP + -12h],4h	; local_14
	ADD        word ptr [BP + -14h],4h	; local_16
	ADD        word ptr [BP + -16h],2h	; local_18
	INC        word ptr [BP + -6h]	; local_8
	CMP        word ptr [BP + -6h],6h	; local_8
	JGE        L_01af
	JMP        L_0077
L_01af:
	MOV        word ptr [BP + -4h],SI	; local_6
	PUSH       SI
	CALL       SUB_0000_6954 ; 1000:0BE4h
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_6954 ; 1000:0BE4h
	PUSH       word ptr [BP + -0ah]	; local_c
	CALL       SUB_0000_6d4c ; 1000:0FDCh
	JMP        L_01e6
L_01c4:
	PUSH       word ptr [BP + -2h]	; local_4
	MOV        AX,5h
	PUSH       AX
	MOV        AX,0e0h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6abc ; 1000:0D4Ch
	PUSH       word ptr [BP + -2h]	; local_4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0b0h
	PUSH       AX
	SUB        AX,AX
	JMP        L_00f5
	db 90h
L_01e6:
	CALL       SUB_0000_7ace ; 1000:1D5Eh
	OR         AX,AX
	JZ         L_01e6
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992 ; 1000:0C22h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
L_01fb:
	PUSH       word ptr DS:[2622h]
	CALL       SUB_0000_691e ; 1000:0BAEh
	MOV        SI,AX
	OR         SI,SI
	JZ         L_01fb
	MOV        word ptr [BP + -4h],SI	; local_6
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6abc ; 1000:0D4Ch
	PUSH       SI
	CALL       SUB_0000_6954 ; 1000:0BE4h
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6cde ; 1000:0F6Eh
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6992 ; 1000:0C22h
	MOV        byte ptr DS:[0a9beh],0h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0000 ENDP
F_023a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]	; param_1
	MOV        CL,byte ptr DS:[0bcdah]
	JMP        L_025c
L_024a:
	CMP        CL,27h
	JNC        L_0261
	MOV        BX,CX
	SUB        BH,BH
	MOV        AL,byte ptr [SI]
	MOV        byte ptr [BX + 0bcb2h],AL
	INC        SI
	INC        CL
L_025c:
	CMP        byte ptr [SI],0h
	JNZ        L_024a
L_0261:
	MOV        word ptr [BP + 4h],SI	; param_1
	MOV        byte ptr DS:[0bcdah],CL
	MOV        AL,CL
	SUB        AH,AH
	MOV        SI,AX
	MOV        byte ptr [SI + 0bcb2h],AH
	CMP        byte ptr [SI + 0bcb1h],0ah
	JNZ        L_0285
	MOV        AX,0bcb2h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        byte ptr DS:[0bcdah],0h
L_0285:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_023a ENDP
F_028c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	CMP        word ptr [BP + 4h],15h	; param_1
	JGE        L_029c
	MOV        BX,word ptr [BP + 4h]	; param_1
	JMP        L_02c8
	db 90h
L_029c:
	MOV        AX,word ptr [BP + 4h]	; param_1
	CWD
	MOV        CX,0ah
	IDIV       CX
	MOV        BX,AX
	SHL        BX,1h
	PUSH       word ptr [BX + 3e2eh]
	CALL       F_023a
	MOV        AX,word ptr [BP + 4h]	; param_1
	CWD
	MOV        CX,0ah
	IDIV       CX
	MOV        SI,DX
	OR         SI,SI
	JZ         L_02d1
	MOV        AX,82c6h
	PUSH       AX
	CALL       F_023a
	MOV        BX,SI
L_02c8:
	SHL        BX,1h
	PUSH       word ptr [BX + 3e0ah]
	CALL       F_023a
L_02d1:
	POP        SI
	POP        BP
	RET        2h
	; Func
F_028c ENDP
F_02d6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 4h],0dh	; param_1
	JGE        L_02ea
	MOV        BX,word ptr [BP + 4h]	; param_1
	SHL        BX,1h
	PUSH       word ptr [BX + 3e40h]
	JMP        L_031e
L_02ea:
	CMP        word ptr [BP + 4h],14h	; param_1
	JGE        L_02fc
	PUSH       word ptr [BP + 4h]	; param_1
	CALL       F_028c
	MOV        AX,831eh
L_02f9:
	PUSH       AX
	JMP        L_031e
L_02fc:
	MOV        AX,8322h
	PUSH       AX
	CALL       F_023a
	CMP        word ptr [BP + 4h],14h	; param_1
	JNZ        L_030e
	MOV        AX,8328h
	JMP        L_02f9
L_030e:
	MOV        AX,832eh
	PUSH       AX
	CALL       F_023a
	MOV        BX,word ptr [BP + 4h]	; param_1
	SHL        BX,1h
	PUSH       word ptr [BX + 3e18h]
L_031e:
	CALL       F_023a
	POP        BP
	RET        2h
	db 90h
	; Func
F_02d6 ENDP
F_0326 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7962 ; 1000:1BF2h
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	MOV        AX,0fch
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	MOV        AX,8332h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        byte ptr DS:[0bcdah],0h
	MOV        AX,8348h
	PUSH       AX
	CALL       F_023a
	MOV        AL,DS:[587eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_02d6
	MOV        AX,834eh
	PUSH       AX
	CALL       F_023a
	MOV        AX,8358h
	PUSH       AX
	CALL       F_023a
	MOV        AL,DS:[587dh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_02d6
	MOV        AX,835eh
	PUSH       AX
	CALL       F_023a
	MOV        AX,8366h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,DS:[5874h]
	CWD
	MOV        CX,64h
	IDIV       CX
	PUSH       AX
	CALL       F_028c
	MOV        AX,8374h
	PUSH       AX
	CALL       F_023a
	MOV        AX,DS:[5874h]
	CWD
	MOV        CX,64h
	IDIV       CX
	PUSH       DX
	CALL       F_028c
	MOV        AX,837eh
	PUSH       AX
	CALL       F_023a
	MOV        AX,55a8h
	PUSH       AX
	CALL       F_023a
	MOV        AX,8382h
	PUSH       AX
	CALL       F_023a
	MOV        AX,8390h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,83a0h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,83b2h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,83cah
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,83deh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e ; 1000:1C9Eh
	MOV        AX,83eeh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,8404h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e ; 1000:1C9Eh
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	MOV        AX,8414h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,DS:[5874h]
	SUB        AX,8bh
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,DS:[587dh]
	SUB        AH,AH
	SUB        AX,4h
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AL,DS:[587eh]
	SUB        AH,AH
	SUB        AX,5h
	MOV        word ptr [BP + -2h],AX	; local_4
	OR         AX,AX
	JGE        L_0431
	ADD        word ptr [BP + -2h],1ch	; local_4
	DEC        word ptr [BP + -6h]	; local_8
L_0431:
	CMP        word ptr [BP + -6h],0h	; local_8
	JGE        L_043e
	ADD        word ptr [BP + -6h],0dh	; local_8
	DEC        word ptr [BP + -4h]	; local_6
L_043e:
	CMP        word ptr [BP + -4h],0h	; local_6
	JZ         L_0480
	MOV        AX,0ah
	PUSH       AX
	LEA        AX,[BP + -0eh]	; local_10
	PUSH       AX
	PUSH       word ptr [BP + -4h]	; local_6
	CALL       SUB_0000_6196 ; 1000:0426h
	ADD        SP,6h
	PUSH       AX
	CALL       F_023a
	MOV        AX,8438h
	PUSH       AX
	CALL       F_023a
	CMP        word ptr [BP + -4h],1h	; local_6
	JLE        L_046d
	MOV        AX,843eh
	PUSH       AX
	CALL       F_023a
L_046d:
	CMP        word ptr [BP + -6h],0h	; local_8
	JNZ        L_0479
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_0480
L_0479:
	MOV        AX,8440h
	PUSH       AX
	CALL       F_023a
L_0480:
	CMP        word ptr [BP + -6h],0h	; local_8
	JZ         L_04bc
	MOV        AX,0ah
	PUSH       AX
	LEA        AX,[BP + -0eh]	; local_10
	PUSH       AX
	PUSH       word ptr [BP + -6h]	; local_8
	CALL       SUB_0000_6196 ; 1000:0426h
	ADD        SP,6h
	PUSH       AX
	CALL       F_023a
	MOV        AX,8444h
	PUSH       AX
	CALL       F_023a
	CMP        word ptr [BP + -6h],1h	; local_8
	JLE        L_04af
	MOV        AX,844ch
	PUSH       AX
	CALL       F_023a
L_04af:
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_04bc
	MOV        AX,844eh
	PUSH       AX
	CALL       F_023a
L_04bc:
	CMP        word ptr [BP + -2h],0h	; local_4
	JZ         L_04eb
	MOV        AX,0ah
	PUSH       AX
	LEA        AX,[BP + -0eh]	; local_10
	PUSH       AX
	PUSH       word ptr [BP + -2h]	; local_4
	CALL       SUB_0000_6196 ; 1000:0426h
	ADD        SP,6h
	PUSH       AX
	CALL       F_023a
	MOV        AX,8452h
	PUSH       AX
	CALL       F_023a
	CMP        word ptr [BP + -2h],1h	; local_4
	JLE        L_04eb
	MOV        AX,8458h
	PUSH       AX
	CALL       F_023a
L_04eb:
	MOV        AX,845ah
	PUSH       AX
	CALL       F_023a
	MOV        AX,845ch
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_04f9:
	INC        word ptr [BP + -2h]	; local_4
	JMP        L_04f9
	; Func
F_0326 ENDP
F_04fe PROC NEAR
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	CALL       SUB_0000_a0ae ; 1000:433Eh
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	RET
	; Func
F_04fe ENDP
F_0510 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	MOV        word ptr [BP + -6h],1h	; local_8
	MOV        AX,word ptr [BP + 8h]	; param_3
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	CMP        byte ptr [BX],0h
	JNZ        L_0538
L_0530:
	MOV        word ptr [BP + -6h],0h	; local_8
	JMP        L_0598
	db 90h
L_0538:
	MOV        AL,byte ptr [BX + 2h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]	; param_2
	JNZ        L_054a
	MOV        AL,byte ptr [BX + 3h]
	CMP        AX,word ptr [BP + 4h]	; param_1
	JZ         L_0530
L_054a:
	MOV        AL,byte ptr [BX + 2h]
	SUB        AH,AH
	SUB        AX,word ptr [BP + 6h]	; param_2
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        SI,AX
	SUB        AX,word ptr [BP + 4h]	; param_1
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -8h],AX	; local_a
	CMP        word ptr [BP + -4h],AX	; local_6
	JGE        L_0582
	CMP        word ptr [BP + 4h],SI	; param_1
	JNC        L_057c
	DEC        byte ptr [BX + 3h]
	JMP        L_0595
	db 90h
L_057c:
	INC        byte ptr [BX + 3h]
	JMP        L_0595
	db 90h
L_0582:
	MOV        AL,byte ptr [BX + 2h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]	; param_2
	JBE        L_0592
	DEC        byte ptr [BX + 2h]
	JMP        L_0595
	db 90h
L_0592:
	INC        byte ptr [BX + 2h]
L_0595:
	CALL       F_04fe
L_0598:
	MOV        AX,word ptr [BP + -6h]	; local_8
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0510 ENDP
F_05a2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        AX,word ptr [BP + 4h]	; param_1
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX	; local_4
	MOV        BX,AX
	CMP        byte ptr [BX],0h
	JZ         L_0639
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	OR         AX,AX
	JZ         L_0639
	MOV        word ptr [BP + -8h],0h	; local_a
L_05d1:
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AL,byte ptr [BX + 2h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,byte ptr [BX + 3h]
	MOV        SI,AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02 ; 1000:2092h
	OR         AX,AX
	JZ         L_0600
	CMP        AX,1h
	JZ         L_061e
	CMP        AX,2h
	JZ         L_0622
	CMP        AX,3h
	JZ         L_0626
	JMP        L_0601
	db 90h
L_0600:
	INC        DI
L_0601:
	MOV        BX,SI
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + DI + 0ab02h],44h
	JNZ        L_062a
	MOV        BX,word ptr [BP + -2h]	; local_4
	MOV        AX,DI
	MOV        byte ptr [BX + 2h],AL
	MOV        AX,SI
	MOV        byte ptr [BX + 3h],AL
	JMP        L_0633
	db 90h
L_061e:
	DEC        DI
	JMP        L_0601
	db 90h
L_0622:
	INC        SI
	JMP        L_0601
	db 90h
L_0626:
	DEC        SI
	JMP        L_0601
	db 90h
L_062a:
	INC        word ptr [BP + -8h]	; local_a
	CMP        word ptr [BP + -8h],8h	; local_a
	JL         L_05d1
L_0633:
	MOV        word ptr [BP + -4h],DI	; local_6
	MOV        word ptr [BP + -6h],SI	; local_8
L_0639:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_05a2 ENDP
F_0648 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ch
	PUSH       DI
	PUSH       SI
	MOV        byte ptr DS:[589eh],0ffh
	CALL       SUB_0000_8670 ; 1000:2900h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_cd0e ; 1000:6F9Eh
	MOV        AX,8480h
	PUSH       AX
	MOV        AX,0ac64h
	PUSH       AX
	MOV        AX,0b0h
	PUSH       AX
	MOV        AX,210h
	PUSH       AX
	CALL       SUB_0000_82de ; 1000:256Eh
	MOV        AX,848eh
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,3e8h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_82de ; 1000:256Eh
	MOV        word ptr [BP + -0ah],0bh	; local_c
	SUB        DI,DI
	SUB        SI,SI
L_068d:
	MOV        word ptr [BP + -0ch],0h	; local_e
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
	MOV        word ptr [BP + -0ch],0bh	; local_e
	ADD        DI,10h
	ADD        SI,20h
	CMP        SI,160h
	JL         L_068d
	MOV        word ptr [BP + -0ah],20h	; local_c
	MOV        DI,5c5ah
	MOV        SI,5c5bh
L_06c4:
	SUB        AL,AL
	MOV        byte ptr [SI],AL
	MOV        byte ptr [DI],AL
	ADD        DI,8h
	ADD        SI,8h
	CMP        SI,5d5bh
	JC         L_06c4
	MOV        word ptr [BP + -4h],5d52h	; local_6
	MOV        AL,7ch
	MOV        DS:[5d53h],AL
	MOV        DS:[5d52h],AL
	MOV        byte ptr DS:[5d54h],5h
	MOV        byte ptr DS:[5d55h],8h
	MOV        byte ptr DS:[5d58h],0h
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
L_06f9:
	MOV        AX,1fh
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       F_0510
	OR         AX,AX
	JNZ        L_06f9
	MOV        word ptr [BP + -0ah],0h	; local_c
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JNZ        L_071d
	JMP        L_082c
L_071d:
	MOV        word ptr [BP + -0eh],55b3h	; local_10
	MOV        word ptr [BP + -14h],55a8h	; local_16
	MOV        word ptr [BP + -16h],55b8h	; local_18
	MOV        word ptr [BP + -18h],55bah	; local_1a
	MOV        word ptr [BP + -1ah],55b2h	; local_1c
	MOV        word ptr [BP + -1ch],5c5ah	; local_1e
L_073b:
	MOV        BX,word ptr [BP + -0eh]	; local_10
	CMP        byte ptr [BX],44h
	JNZ        L_0795
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a ; 1000:16BAh
	PUSH       word ptr [BP + -14h]	; local_16
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,849ah
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        BX,word ptr [BP + -0eh]	; local_10
	MOV        byte ptr [BX],47h
	MOV        BX,word ptr [BP + -16h]	; local_18
	MOV        SI,word ptr [BP + -18h]	; local_1a
	MOV        AX,word ptr [SI]
	MOV        word ptr [BX],AX
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0 ; 1000:0A70h
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_68f6 ; 1000:0B86h
	MOV        AX,2260h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,9c40h
	PUSH       AX
	MOV        AX,1388h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7f02 ; 1000:2192h
	CALL       SUB_0000_8670 ; 1000:2900h
L_0795:
	MOV        AX,84a4h
	PUSH       AX
	MOV        BX,word ptr [BP + -1ah]	; local_1c
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_aae6 ; 1000:4D76h
	MOV        word ptr [BP + -6h],AX	; local_8
	MOV        AX,word ptr [BP + -1ch]	; local_1e
	MOV        word ptr [BP + -4h],AX	; local_6
	MOV        BX,AX
	MOV        SI,word ptr [BP + -6h]	; local_8
	MOV        AL,byte ptr [SI + 1adeh]
	MOV        byte ptr [BX + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr [BX + 2h],5h
	MOV        byte ptr [BX + 3h],9h
	MOV        byte ptr [BX + 6h],0h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	PUSH       word ptr [BP + -0ah]	; local_c
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        AL,byte ptr [BX + 3e5ah]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 3e60h]
	PUSH       AX
	CALL       F_0510
	OR         AX,AX
	JZ         L_0804
	MOV        BX,word ptr [BP + -0ah]	; local_c
	MOV        AL,byte ptr [BX + 3e60h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,byte ptr [BX + 3e5ah]
	MOV        DI,AX
L_07f8:
	PUSH       word ptr [BP + -0ah]	; local_c
	PUSH       DI
	PUSH       SI
	CALL       F_0510
	OR         AX,AX
	JNZ        L_07f8
L_0804:
	ADD        word ptr [BP + -0eh],20h	; local_10
	ADD        word ptr [BP + -14h],20h	; local_16
	ADD        word ptr [BP + -16h],20h	; local_18
	ADD        word ptr [BP + -18h],20h	; local_1a
	ADD        word ptr [BP + -1ah],20h	; local_1c
	ADD        word ptr [BP + -1ch],8h	; local_1e
	INC        word ptr [BP + -0ah]	; local_c
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -0ah],AX	; local_c
	JNC        L_082c
	JMP        L_073b
L_082c:
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,84aeh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b23fh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_0852:
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        SI,AX
	CMP        AX,4eh
	JZ         L_0876
	CMP        AX,59h
	JNZ        L_0868
	MOV        AX,84b4h
L_0864:
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_0868:
	MOV        AX,SI
	CMP        AX,59h
	JZ         L_087c
	CMP        AX,4eh
	JZ         L_087c
	JMP        L_0852
L_0876:
	MOV        AX,84bah
	JMP        L_0864
	db 90h
L_087c:
	MOV        word ptr [BP + -2h],SI	; local_4
	CMP        SI,4eh
	JNZ        L_08b9
	MOV        AX,0b267h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_088b:
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        SI,AX
	CMP        AX,4eh
	JZ         L_08b0
	CMP        AX,59h
	JNZ        L_08a1
	MOV        AX,84c0h
L_089d:
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
L_08a1:
	MOV        AX,SI
	CMP        AX,59h
	JZ         L_08b6
	CMP        AX,4eh
	JZ         L_08b6
	JMP        L_088b
	db 90h
L_08b0:
	MOV        AX,84c6h
	JMP        L_089d
	db 90h
L_08b6:
	MOV        word ptr [BP + -2h],SI	; local_4
L_08b9:
	CMP        word ptr [BP + -2h],59h	; local_4
	JZ         L_08c2
	JMP        L_0a76
L_08c2:
	CMP        byte ptr DS:[57bfh],0h
	JNZ        L_08cc
	JMP        L_0a76
L_08cc:
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
L_08d3:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       F_0510
	OR         AX,AX
	JNZ        L_08d3
L_08e5:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	CALL       F_0510
	OR         AX,AX
	JNZ        L_08e5
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        word ptr [BP + -4h],5c8ah	; local_6
	MOV        AL,0eh
	MOV        DS:[5c8bh],AL
	MOV        DS:[5c8ah],AL
	MOV        byte ptr DS:[5c8ch],5h
	MOV        byte ptr DS:[5c8dh],4h
	MOV        byte ptr DS:[5c90h],0h
	MOV        AX,0b2c9h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        AX,84cch
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b2f1h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b346h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b385h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b3e7h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b42fh
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,0b469h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AL,8h
	MOV        DS:[5c8ah],AL
	MOV        DS:[5c8bh],AL
	CALL       SUB_0000_83dc ; 1000:266Ch
	MOV        AX,1450h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c350h
	PUSH       AX
	MOV        AX,2710h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7f02 ; 1000:2192h
	SUB        AL,AL
	MOV        DS:[5c8ah],AL
	MOV        DS:[5c8bh],AL
	MOV        byte ptr DS:[0ad99h],0dch
	MOV        byte ptr DS:[5887h],1h
L_099c:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	INC        byte ptr DS:[5887h]
	CMP        byte ptr DS:[5887h],10h
	JC         L_099c
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
L_09b5:
	MOV        AX,1fh
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       F_0510
	OR         AX,AX
	JNZ        L_09b5
	SUB        AL,AL
	MOV        DS:[5d53h],AL
	MOV        DS:[5d52h],AL
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        word ptr [BP + -0ah],0h	; local_c
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_0a27
	MOV        DI,5c5ah
	MOV        word ptr [BP + -1ah],5c5bh	; local_1c
	MOV        SI,word ptr [BP + -0ah]	; local_c
L_09f0:
	PUSH       SI
	MOV        AX,5h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       F_0510
	OR         AX,AX
	JNZ        L_09f0
	MOV        BX,word ptr [BP + -1ah]	; local_1c
	SUB        AL,AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr [DI],AL
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	ADD        DI,8h
	ADD        word ptr [BP + -1ah],8h	; local_1c
	INC        SI
	MOV        AX,SI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_09f0
	MOV        word ptr [BP + -0ah],SI	; local_c
L_0a27:
	MOV        byte ptr DS:[5887h],0fh
L_0a2c:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	DEC        byte ptr DS:[5887h]
	JNZ        L_0a2c
	MOV        AX,44h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       SUB_0000_6e50 ; 1000:10E0h
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992 ; 1000:0C22h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_67e0 ; 1000:0A70h
	CALL       SUB_0000_6d9e ; 1000:102Eh
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,13fh
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	CALL       SUB_0000_6816 ; 1000:0AA6h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6992 ; 1000:0C22h
	CALL       F_0000
	CALL       F_0326
	JMP        L_0ae8
	db 90h
L_0a76:
	MOV        AX,84dah
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_9856 ; 1000:3AE6h
	MOV        AX,0b4f3h
	PUSH       AX
	CALL       SUB_0000_75c0 ; 1000:1850h
	DEC        byte ptr DS:[5c5dh]
	CALL       F_04fe
L_0a92:
	MOV        AX,2h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       F_0510
	MOV        SI,AX
	MOV        AX,1fh
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       F_0510
	ADD        SI,AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       F_0510
	ADD        SI,AX
	JNZ        L_0a92
	MOV        word ptr [BP + -8h],SI	; local_a
L_0ac9:
	MOV        AX,1h
	PUSH       AX
	CALL       F_05a2
	MOV        AX,3h
	PUSH       AX
	CALL       F_05a2
	MOV        AX,4h
	PUSH       AX
	CALL       F_05a2
	MOV        AX,5h
	PUSH       AX
	CALL       F_05a2
	JMP        L_0ac9
	db 90h
L_0ae8:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 00h
	db 00h
F_0648 ENDP
_TEXT ENDS
END
