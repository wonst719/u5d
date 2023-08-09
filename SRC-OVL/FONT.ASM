_TEXT SEGMENT BYTE 'CODE'
ORG 2a42h
SUB_0000_2a42:
ORG 2e64h
SUB_0000_2e64:
ORG 2f00h
SUB_0000_2f00:
ORG 6372h
SUB_0000_6372:
ORG 9b12h
SUB_0000_9b12:
ORG 3b7eh
SUB_0000_3b7e:
ORG 3f1ah
SUB_0000_3f1a:
ORG 405ch
SUB_0000_405c:
ORG 40e0h
SUB_0000_40e0:
ORG 9ae2h
SUB_0000_9ae2:
ORG 2890h
SUB_0000_2890:
ORG 28c6h
SUB_0000_28c6:
ORG 2930h
SUB_0000_2930:
ORG 438eh
SUB_0000_438e:
ORG 2e14h
SUB_0000_2e14:
ORG 3eb2h
SUB_0000_3eb2:
ORG 34dah
SUB_0000_34da:
ORG 2b6ch
SUB_0000_2b6c:
ORG 2d8eh
SUB_0000_2d8e:
ORG 3e52h
SUB_0000_3e52:
ORG 2e4eh
SUB_0000_2e4e:
ORG 2dceh
SUB_0000_2dce:
ORG 29ceh
SUB_0000_29ce:
ORG 3a12h
SUB_0000_3a12:
ORG 3670h
SUB_0000_3670:
ORG 3c58h
SUB_0000_3c58:
ORG 3bfah
SUB_0000_3bfa:
ORG 2a04h
SUB_0000_2a04:
ORG 2dfch
SUB_0000_2dfc:
ORG 433eh
SUB_0000_433e:
ORG 43f8h
SUB_0000_43f8:
ORG 9b1eh
SUB_0000_9b1e:
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
	SUB        SP,1ch
	PUSH       DI
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_2a42
	MOV        AX,DS:[5150h]
	CMP        word ptr DS:[5158h],AX
	JLE        L_0026
	MOV        AX,DS:[5152h]
	CMP        word ptr DS:[5158h],AX
	JGE        L_0026
	MOV        AX,1h
	JMP        L_0028
L_0026:
	SUB        AX,AX
L_0028:
	MOV        word ptr [BP + -10h],AX
	MOV        SI,AX
	SHL        SI,1h
	MOV        AX,word ptr [SI + 514ch]
	SUB        AX,word ptr [SI + 5146h]
	MOV        word ptr [BP + -0ah],AX
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,DS:[5156h]
	SUB        AX,word ptr [SI + 5146h]
	MOV        word ptr [BP + -2h],AX
	JMP        L_027b
	db 90h
L_0050:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],7bh
	JNZ        L_005e
	ADD        SI,0fh
	JMP        L_0078
L_005e:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],5fh
	JZ         L_0078
	MOV        BX,CX
	ADD        BX,DX
	MOV        BL,byte ptr [BX]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 50cah]
	SUB        AH,AH
	INC        AX
	ADD        SI,AX
L_0078:
	INC        CX
L_0079:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],0h
	JZ         L_00a0
	CMP        word ptr [BP + -0ah],SI
	JLE        L_00a0
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],0ah
	JZ         L_00a0
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],20h
	JA         L_0050
	ADD        SI,word ptr DS:[5154h]
	INC        DI
	JMP        L_0078
L_00a0:
	MOV        word ptr [BP + -8h],DI
	MOV        word ptr [BP + -2h],SI
	MOV        word ptr [BP + -0eh],CX
	MOV        AL,DS:[50f7h]
	SUB        AH,AH
	MOV        word ptr [BP + -16h],AX
	INC        AX
	MOV        word ptr [BP + -12h],AX
	MOV        AX,word ptr [BP + -16h]
	MOV        word ptr [BP + -14h],AX
	MOV        DI,word ptr [BP + -0ah]
	MOV        DX,word ptr [BP + 4h]
L_00c1:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],0h
	JNZ        L_00ce
	CMP        SI,DI
	JL         L_00f0
L_00ce:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],0ah
	JZ         L_00f0
	DEC        CX
	CMP        word ptr [BP + -0ch],CX
	JGE        L_00f0
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],20h
	JZ         L_00e9
	JMP        L_016a
L_00e9:
	SUB        SI,word ptr DS:[5154h]
	DEC        word ptr [BP + -8h]
L_00f0:
	MOV        word ptr [BP + -2h],SI
	MOV        word ptr [BP + -0eh],CX
	MOV        AX,word ptr [BP + -0ah]
	SUB        AX,SI
	MOV        word ptr [BP + -6h],AX
	MOV        AX,CX
	MOV        word ptr [BP + -4h],AX
	MOV        AX,word ptr [BP + -0ch]
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,word ptr [BP + -4h]
	CMP        word ptr [BP + -0eh],AX
	JL         L_0114
	JMP        L_020a
L_0114:
	MOV        BX,AX
	MOV        SI,word ptr [BP + 4h]
	MOV        AL,byte ptr [BX + SI]
	MOV        byte ptr [BP + -18h],AL
	MOV        DI,SI
	MOV        SI,word ptr [BP + -0eh]
L_0123:
	MOV        BX,SI
	ADD        BX,DI
	CMP        byte ptr [BX],20h
	JBE        L_012f
	JMP        L_01b0
L_012f:
	MOV        AX,DS:[5154h]
	ADD        word ptr DS:[5156h],AX
	CMP        word ptr [BP + -8h],0h
	JNZ        L_013f
	JMP        L_01fe
L_013f:
	CMP        byte ptr [BP + -18h],0h
	JNZ        L_0148
	JMP        L_01fe
L_0148:
	CMP        byte ptr [BP + -18h],0ah
	JNZ        L_0151
	JMP        L_01fe
L_0151:
	MOV        AX,word ptr [BP + -6h]
	CWD
	MOV        CX,word ptr [BP + -8h]
	IDIV       CX
	MOV        word ptr [BP + -1ah],AX
	ADD        word ptr DS:[5156h],AX
	SUB        word ptr [BP + -6h],AX
	DEC        word ptr [BP + -8h]
	JMP        L_01fe
L_016a:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],5fh
	JNZ        L_0184
	MOV        AX,word ptr [BP + -14h]
	ADD        AX,SI
	INC        AX
	CMP        AX,DI
	JNC        L_0184
	ADD        SI,word ptr [BP + -12h]
	JMP        L_00f0
	db 90h
L_0184:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],5fh
	JNZ        L_0190
	JMP        L_00c1
L_0190:
	MOV        BX,CX
	ADD        BX,DX
	CMP        byte ptr [BX],7bh
	JNZ        L_019c
	JMP        L_00c1
L_019c:
	MOV        BX,CX
	ADD        BX,DX
	MOV        BL,byte ptr [BX]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 50cah]
	SUB        AH,AH
	INC        AX
	SUB        SI,AX
	JMP        L_00c1
L_01b0:
	MOV        BX,SI
	ADD        BX,DI
	CMP        byte ptr [BX],7bh
	JNZ        L_01c0
	ADD        word ptr DS:[5156h],0fh
	JMP        L_01fe
L_01c0:
	MOV        BX,SI
	ADD        BX,DI
	CMP        byte ptr [BX],5fh
	JZ         L_01fe
	CMP        word ptr DS:[5158h],0c0h
	JGE        L_01eb
	PUSH       word ptr [BP + 6h]
	MOV        BX,SI
	ADD        BX,DI
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	SUB        AX,20h
	PUSH       AX
	PUSH       word ptr DS:[5156h]
	PUSH       word ptr DS:[5158h]
	CALL       SUB_0000_2e64
L_01eb:
	MOV        BX,SI
	ADD        BX,DI
	MOV        BL,byte ptr [BX]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 50cah]
	SUB        AH,AH
	INC        AX
	ADD        word ptr DS:[5156h],AX
L_01fe:
	INC        SI
	CMP        word ptr [BP + -4h],SI
	JZ         L_0207
	JMP        L_0123
L_0207:
	MOV        word ptr [BP + -0eh],SI
L_020a:
	MOV        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -0ch],AX
	MOV        BX,AX
	MOV        SI,word ptr [BP + 4h]
	CMP        byte ptr [BX + SI],0h
	JZ         L_027b
	CMP        byte ptr [BX + SI],5fh
	JNZ        L_0239
	CMP        word ptr DS:[5158h],0c0h
	JGE        L_0239
	PUSH       word ptr [BP + 6h]
	MOV        AX,0dh
	PUSH       AX
	PUSH       word ptr DS:[5156h]
	PUSH       word ptr DS:[5158h]
	CALL       SUB_0000_2e64
L_0239:
	MOV        word ptr [BP + -2h],0h
	ADD        word ptr DS:[5158h],9h
	MOV        AX,DS:[5150h]
	CMP        word ptr DS:[5158h],AX
	JLE        L_025a
	MOV        AX,DS:[5152h]
	CMP        word ptr DS:[5158h],AX
	JGE        L_025a
	MOV        AX,1h
	JMP        L_025c
L_025a:
	SUB        AX,AX
L_025c:
	MOV        word ptr [BP + -10h],AX
	SHL        AX,1h
	MOV        word ptr [BP + -1ch],AX
	MOV        BX,AX
	MOV        AX,word ptr [BX + 5146h]
	MOV        DS:[5156h],AX
	MOV        AX,word ptr [BX + 514ch]
	SUB        AX,word ptr DS:[5156h]
	MOV        word ptr [BP + -0ah],AX
	INC        word ptr [BP + -0ch]
L_027b:
	MOV        BX,word ptr [BP + -0ch]
	MOV        SI,word ptr [BP + 4h]
	CMP        byte ptr [BX + SI],0h
	JZ         L_0294
	SUB        DI,DI
	MOV        CX,BX
	MOV        SI,word ptr [BP + -2h]
	MOV        DX,word ptr [BP + 4h]
	JMP        L_0079
	db 90h
L_0294:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2a42
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0000 ENDP
F_02a2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        BX,word ptr [BP + 6h]
	MOV        AL,byte ptr [BX + SI + 6608h]
	MOV        byte ptr [BP + -2h],AL
	OR         AL,AL
	JZ         L_02ce
	MOV        BL,AL
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 0b11eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	JMP        L_02ea
L_02ce:
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        BX,word ptr [BP + 6h]
	MOV        AL,byte ptr [BX + SI + 6688h]
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,16h
	JZ         L_02f4
	SUB        AH,AH
	ADD        AH,1h
	PUSH       AX
	PUSH       BX
L_02ea:
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,7h
	PUSH       AX
	CALL       SUB_0000_2f00
L_02f4:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_02a2 ENDP
F_02fc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
L_0304:
	CALL       SUB_0000_6372
	CALL       SUB_0000_9b12
	MOV        word ptr [BP + -4h],20h
	MOV        DI,5c5ah
L_0312:
	MOV        SI,DI
	CMP        byte ptr [SI],0h
	JZ         L_0339
	MOV        AL,byte ptr [SI + 3h]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	MOV        CL,byte ptr [SI + 2h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -0ah],AX
	MOV        BX,AX
	MOV        byte ptr [BX + 6608h],CH
	MOV        AL,byte ptr [SI + 1h]
	MOV        byte ptr [BX + 6688h],AL
L_0339:
	ADD        DI,8h
	CMP        DI,5d5ah
	JC         L_0312
	MOV        word ptr [BP + -2h],SI
	MOV        AL,DS:[0bd26h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	JMP        L_0374
	db 90h
L_0350:
	SUB        SI,SI
	MOV        DI,word ptr [BP + -4h]
	ADD        DI,6608h
L_0359:
	CMP        byte ptr [DI],0feh
	JZ         L_0365
	PUSH       word ptr [BP + -4h]
	PUSH       SI
	CALL       F_02a2
L_0365:
	ADD        DI,20h
	INC        SI
	CMP        SI,4h
	JL         L_0359
	MOV        word ptr [BP + -6h],SI
	INC        word ptr [BP + -4h]
L_0374:
	MOV        AL,DS:[0bd27h]
	SUB        AH,AH
	CMP        word ptr [BP + -4h],AX
	JBE        L_0350
	CMP        byte ptr DS:[0bd26h],AH
	JZ         L_0392
	CMP        byte ptr DS:[0bd28h],AH
	JZ         L_0392
	DEC        byte ptr DS:[0bd26h]
	INC        byte ptr DS:[0bd27h]
L_0392:
	CMP        byte ptr DS:[0bd28h],1h
	SBB        AX,AX
	NEG        AX
	MOV        DS:[0bd28h],AL
	CALL       SUB_0000_3b7e
	OR         AX,AX
	JZ         L_03aa
	MOV        AX,1h
	JMP        L_0410
L_03aa:
	CMP        word ptr [BP + 4h],0h
	JZ         L_03b7
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_3f1a
L_03b7:
	CMP        byte ptr DS:[0bd29h],2h
	JNZ        L_03d0
	MOV        AX,14h
	PUSH       AX
	MOV        AX,3ch
	PUSH       AX
	MOV        AX,2710h
	PUSH       AX
	CALL       SUB_0000_405c
	JMP        L_0406
	db 90h
L_03d0:
	CMP        byte ptr DS:[0bd29h],3h
	JNZ        L_0406
	INC        word ptr DS:[515ah]
	CMP        word ptr DS:[515ah],7h
	JLE        L_03e8
	MOV        word ptr DS:[515ah],0h
L_03e8:
	CMP        word ptr DS:[515ah],0h
	JNZ        L_03f4
	MOV        AX,0bb8h
	JMP        L_03fe
L_03f4:
	CMP        word ptr DS:[515ah],4h
	JNZ        L_0406
	MOV        AX,7d0h
L_03fe:
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_40e0
L_0406:
	DEC        word ptr [BP + 4h]
	JZ         L_040e
	JMP        L_0304
L_040e:
	SUB        AX,AX
L_0410:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_02fc ENDP
F_0418 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,1h
	PUSH       word ptr [BX + 515ch]
	CALL       SUB_0000_9ae2
	MOV        word ptr [BP + -2h],0h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,7h
	SHL        AX,CL
	MOV        word ptr [BP + -12h],AX
	MOV        word ptr [BP + -4h],4h
L_0440:
	MOV        DX,word ptr [BP + -12h]
	MOV        DI,word ptr [BP + -2h]
	ADD        DI,6708h
	MOV        AX,word ptr [BP + -2h]
	ADD        AX,6608h
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,DX
	ADD        AX,word ptr [BP + -2h]
	MOV        word ptr [BP + -10h],AX
	MOV        SI,AX
	ADD        SI,0b21eh
	ADD        AX,0b29eh
	MOV        word ptr [BP + -0eh],AX
	MOV        CX,AX
L_0469:
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [SI]
	MOV        byte ptr [BX],AL
	MOV        byte ptr [DI],AL
	ADD        DI,20h
	ADD        word ptr [BP + -0ah],20h
	ADD        SI,20h
	CMP        SI,CX
	JC         L_0469
	INC        word ptr [BP + -2h]
	CMP        word ptr [BP + -2h],13h
	JL         L_0440
	MOV        AL,9h
	MOV        DS:[0bd27h],AL
	MOV        DS:[0bd26h],AL
	MOV        byte ptr DS:[0bd28h],0h
	MOV        AL,byte ptr [BP + 4h]
	MOV        DS:[0bd29h],AL
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0418 ENDP
F_04a4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,28h
	PUSH       DI
	PUSH       SI
	MOV        word ptr DS:[52beh],10h
	MOV        AL,9h
	MOV        DS:[0bd27h],AL
	MOV        DS:[0bd26h],AL
	MOV        byte ptr DS:[0bd28h],0h
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_2890
	MOV        AX,78h
	PUSH       AX
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	MOV        AX,7eh
	PUSH       AX
	CALL       SUB_0000_28c6
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,78h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	MOV        AX,0c7h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_2930
	CMP        byte ptr DS:[5893h],42h
	JZ         L_0522
	MOV        AX,0a044h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,2c0h
	PUSH       AX
	CALL       SUB_0000_438e
	CMP        byte ptr DS:[5893h],40h
	JNZ        L_0522
	CALL       F_0e52
L_0514:
	PUSH       word ptr DS:[25f0h]
	CALL       SUB_0000_2e14
	OR         AX,AX
	JZ         L_0514
	CALL       F_0e7b
L_0522:
	MOV        byte ptr DS:[5893h],42h
	MOV        word ptr [BP + -0ch],200h
	JMP        L_0974
	db 90h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db 8Bh
	db 0D8h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         76h    v
	db 0F4h
	db 8Ah
	db 84h
	db 1Eh
	db 0B2h
	db 88h
	db         47h    G
	db 01h
	db 88h
	db 07h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         76h    v
	db 0F4h
	db 8Ah
	db 84h
	db 1Eh
	db 0B2h
	db 88h
	db         47h    G
	db 02h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         76h    v
	db 0F4h
	db 8Ah
	db 84h
	db 1Eh
	db 0B2h
	db 88h
	db         47h    G
	db 03h
	db 0C6h
	db         47h    G
	db 06h
	db 00h
	db 0E9h
	db 0F2h
	db 03h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db 8Bh
	db 0D8h
	db 8Bh
	db 0F8h
	db         2Ah    *
	db 0C0h
	db 88h
	db         45h    E
	db 06h
	db 88h
	db         47h    G
	db 01h
	db 88h
	db 07h
	db 8Ah
	db         47h    G
	db 03h
	db         2Ah    *
	db 0E4h
	db 8Bh
	db 0F0h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 8Ah
	db         47h    G
	db 02h
	db 03h
	db 0F0h
	db 8Ah
	db 84h
	db 08h
	db         67h    g
	db 88h
	db 84h
	db 08h
	db         66h    f
	db 0E9h
	db 0B3h
	db 03h
	db 90h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0EAh
	db 8Bh
	db         5Eh    ^
	db 0F6h
	db 8Ah
	db         47h    G
	db 03h
	db 8Bh
	db 0F0h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 8Ah
	db         47h    G
	db 02h
	db 03h
	db 0F0h
	db 8Ah
	db 84h
	db 08h
	db         67h    g
	db 88h
	db 84h
	db 08h
	db         66h    f
	db 8Bh
	db         76h    v
	db 0EAh
	db 0D1h
	db 0E6h
	db 8Ah
	db 84h
	db 0D6h
	db         24h    $
	db 00h
	db         47h    G
	db 02h
	db 8Ah
	db 84h
	db 0DEh
	db         24h    $
	db 00h
	db         47h    G
	db 03h
	db 0E9h
	db         5Eh    ^
	db 03h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0E9h
	db 01h
	db 03h
	db 90h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0FCh
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db 89h
	db         46h    F
	db 0FAh
	db 0B1h
	db 05h
	db 0D3h
	db 0E0h
	db 03h
	db         46h    F
	db 0FCh
	db 89h
	db         46h    F
	db 0E6h
	db 8Bh
	db 0D8h
	db 0B0h
	db 0FEh
	db 88h
	db 87h
	db 08h
	db         67h    g
	db 88h
	db 87h
	db 08h
	db         66h    f
	db 0BEh
	db 01h
	db 00h
	db 8Bh
	db         7Eh    ~
	db 0FAh
	db 83h
	db 0C7h
	db 07h
	db         56h    V
	db 0FFh
	db         76h    v
	db 0FCh
	db         57h    W
	db 0E8h
	db 0D3h
	db         28h    (
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db 96h
	db 0FCh
	db 0Bh
	db 0C0h
	db         74h    t
	db 06h
	db 89h
	db         76h    v
	db 0F2h
	db 0E9h
	db         22h    "
	db 03h
	db         46h    F
	db 83h
	db 0FEh
	db 10h
	db         7Ch    |
	db 0E1h
	db 89h
	db         76h    v
	db 0F2h
	db 8Bh
	db         76h    v
	db 0FAh
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 03h
	db         76h    v
	db 0FCh
	db 0B0h
	db 0DCh
	db 88h
	db 84h
	db 08h
	db         67h    g
	db 88h
	db 84h
	db 08h
	db         66h    f
	db 0B8h
	db 02h
	db 00h
	db 0E9h
	db 89h
	db 02h
	db 90h
	db 8Bh
	db         46h    F
	db 0FAh
	db 0B1h
	db 05h
	db 0D3h
	db 0E0h
	db 03h
	db         46h    F
	db 0FCh
	db 89h
	db         46h    F
	db 0E2h
	db 8Bh
	db 0D8h
	db 0B0h
	db 0FEh
	db 88h
	db 87h
	db 08h
	db         67h    g
	db 88h
	db 87h
	db 08h
	db         66h    f
	db 0BEh
	db 0Fh
	db 00h
	db 8Bh
	db         7Eh    ~
	db 0FAh
	db 83h
	db 0C7h
	db 07h
	db         56h    V
	db 0FFh
	db         76h    v
	db 0FCh
	db         57h    W
	db 0E8h
	db         74h    t
	db         28h    (
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         37h    7
	db 0FCh
	db 0Bh
	db 0C0h
	db         75h    u
	db 0A1h
	db         4Eh    N
	db 0Bh
	db 0F6h
	db         7Fh    
	db 0E8h
	db 89h
	db         76h    v
	db 0F2h
	db 8Bh
	db         76h    v
	db 0FAh
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 03h
	db         76h    v
	db 0FCh
	db 8Ah
	db 0C1h
	db 0EBh
	db 0A6h
	db 90h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0E8h
	db         28h    (
	db 0FDh
	db 0E9h
	db         77h    w
	db 02h
	db 90h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db 8Bh
	db 0D8h
	db 8Ah
	db 07h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0F8h
	db 8Bh
	db 0F3h
	db 0B0h
	db 16h
	db 88h
	db         44h    D
	db 01h
	db 88h
	db 07h
	db 8Bh
	db         46h    F
	db 0F8h
	db 80h
	db 0C4h
	db 01h
	db         50h    P
	db 8Ah
	db         47h    G
	db 02h
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 8Ah
	db         47h    G
	db 03h
	db 05h
	db 07h
	db 00h
	db         50h    P
	db 0E8h
	db         55h    U
	db         27h    '
	db 0Bh
	db 0C0h
	db         74h    t
	db 03h
	db 0E9h
	db         58h    X
	db 02h
	db 8Bh
	db         5Eh    ^
	db 0F6h
	db 8Bh
	db 0F3h
	db 8Ah
	db         46h    F
	db 0F8h
	db 88h
	db         44h    D
	db 01h
	db 88h
	db 07h
	db 0E9h
	db 20h
	db 02h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db 8Bh
	db 0D8h
	db 8Ah
	db         47h    G
	db 02h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0F0h
	db 8Ah
	db         47h    G
	db 03h
	db 89h
	db         46h    F
	db 0EEh
	db 8Ah
	db 07h
	db 89h
	db         46h    F
	db 0F8h
	db 8Bh
	db 0F3h
	db 0B0h
	db 16h
	db 88h
	db         44h    D
	db 01h
	db 88h
	db 07h
	db 8Bh
	db         76h    v
	db 0EEh
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 8Bh
	db         5Eh    ^
	db 0F0h
	db 8Ah
	db 80h
	db 08h
	db         67h    g
	db         50h    P
	db         53h    S
	db 8Bh
	db         46h    F
	db 0EEh
	db 05h
	db 07h
	db 00h
	db         50h    P
	db 0E8h
	db 0F0h
	db         26h    &
	db 0Bh
	db 0C0h
	db         74h    t
	db 9Eh
	db 0E9h
	db 0F3h
	db 01h
	db 90h
	db 0C7h
	db         46h    F
	db 0F4h
	db 0FFh
	db 01h
	db 0E9h
	db 0C2h
	db 01h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0F8h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db 89h
	db         46h    F
	db 0F0h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db 89h
	db         46h    F
U_07d0	db 0EEh
	db 8Bh
	db 0F0h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 03h
	db         76h    v
	db 0F0h
	db 8Ah
	db         46h    F
	db 0F8h
	db 88h
	db 84h
	db 08h
	db         67h    g
	db 0E9h
	db 0CCh
	db 0FDh
	db         2Bh    +
	db 0C0h
	db 89h
	db         46h    F
	db 0EEh
	db 8Bh
	db 0F8h
	db 89h
	db         46h    F
	db 0F2h
	db 8Bh
	db 0F0h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db 05h
	db 0FBh
	db 0Bh
	db 0C0h
	db         74h    t
	db 09h
	db 89h
	db         7Eh    ~
	db 0F0h
	db 89h
	db         76h    v
	db 0EEh
	db 0E9h
	db 8Eh
	db 01h
	db 0FFh
	db         36h    6
	db 0B0h
	db 13h
	db 0E8h
	db 85h
	db 20h
	db 8Dh
	db 85h
	db 89h
	db 00h
	db 89h
	db         46h    F
	db 0E0h
	db 8Dh
	db 85h
	db 80h
	db 00h
	db 89h
	db         46h    F
	db 0DEh
	db         50h    P
	db 8Dh
	db 84h
	db 98h
	db 00h
	db         50h    P
	db 0FFh
	db         76h    v
	db 0E0h
	db 8Dh
	db 84h
	db 9Bh
	db 00h
	db         50h    P
	db 0E8h
	db 06h
	db         21h    !
	db 0FFh
	db         76h    v
	db 0DEh
	db 8Dh
	db 84h
	db 99h
	db 00h
	db         50h    P
	db 0FFh
	db         76h    v
	db 0E0h
	db 8Dh
	db 84h
	db 9Ch
	db 00h
	db         50h    P
	db 0E8h
	db 0F3h
	db 20h
	db 83h
	db 0C7h
	db 09h
	db 83h
	db 0C6h
	db 03h
	db 0FFh
	db         46h    F
	db 0F2h
	db 83h
	db         7Eh    ~
	db 0F2h
	db 05h
	db         7Ch    |
	db 0A4h
	db 89h
	db         7Eh    ~
	db 0F0h
	db 89h
	db         76h    v
	db 0EEh
	db 0FFh
	db         46h    F
	db 0F4h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 8Bh
	db         5Eh    ^
	db 0F6h
	db 8Ah
	db         47h    G
	db 02h
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 8Ah
	db         47h    G
	db 03h
	db 05h
	db 07h
	db 00h
	db         50h    P
	db 0E8h
	db         7Fh    
	db         26h    &
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 0B0h
	db 04h
	db         50h    P
	db 0B8h
	db 0A0h
	db 0Fh
	db         50h    P
	db 0E8h
	db 0CCh
	db         37h    7
	db 0B8h
	db 03h
	db 00h
	db 0E9h
	db 86h
	db 00h
	db 90h
	db 90h
	db 0C7h
	db         46h    F
	db 0F2h
	db 20h
	db 00h
	db 0BFh
	db         5Bh    [
	db         5Ch    \
	db 0C7h
	db         46h    F
	db 0DAh
	db         5Ah    Z
	db         5Ch    \
	db 0BEh
	db         60h    `
	db         5Ch    \
	db 8Bh
	db         5Eh    ^
	db 0DAh
	db         2Ah    *
	db 0C0h
	db 88h
	db 04h
	db 88h
	db 07h
	db 88h
	db 05h
	db 83h
	db 0C7h
	db 08h
	db 83h
	db         46h    F
	db 0DAh
	db 08h
	db 83h
	db 0C6h
	db 08h
	db 81h
	db 0FEh
	db         60h    `
	db         5Dh    ]
	db         72h    r
	db 03h
	db 0E9h
	db 0A4h
	db 00h
	db 0EBh
	db 0E0h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 0B1h
	db 03h
	db 0D3h
	db 0E0h
	db 05h
	db         5Ah    Z
	db         5Ch    \
	db 89h
	db         46h    F
	db 0F6h
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0EAh
	db 8Bh
	db         5Eh    ^
	db 0F6h
	db 8Ah
	db         47h    G
	db 03h
	db 8Bh
	db 0F0h
	db 0B1h
	db 05h
	db 0D3h
	db 0E6h
	db 8Ah
	db         47h    G
	db 02h
	db 03h
	db 0F0h
	db 8Ah
	db 84h
	db 08h
	db         67h    g
	db 88h
	db 84h
	db 08h
	db         66h    f
	db 8Bh
	db         76h    v
	db 0EAh
	db 0D1h
	db 0E6h
	db 8Ah
	db 84h
	db 0D6h
	db         24h    $
	db 00h
	db         47h    G
	db 02h
	db 8Ah
	db 84h
	db 0DEh
	db         24h    $
	db 00h
	db         47h    G
	db 03h
	db 0B8h
	db 07h
	db 00h
	db         50h    P
	db 0E8h
	db 0DCh
	db 0F9h
	db 0Bh
	db 0C0h
	db         74h    t
	db         46h    F
	db 0EBh
	db         6Ch    l
	db 0FFh
	db         46h    F
	db 0F4h
	db 8Bh
	db         5Eh    ^
	db 0F4h
	db 8Ah
	db 87h
	db 1Eh
	db 0B2h
	db         2Ah    *
	db 0E4h
	db 89h
	db         46h    F
	db 0ECh
	db 8Bh
	db 0C3h
	db 89h
	db         46h    F
	db 0FEh
	db 0EBh
	db         2Eh    .
	db 0FFh
	db         4Eh    N
	db 0ECh
	db         74h    t
	db         29h    )
	db 8Bh
	db         46h    F
	db 0FEh
	db 89h
	db         46h    F
	db 0F4h
	db 0EBh
	db         21h    !
	db 90h
	db 10h
	db 0E7h
	db         58h    X
	db 0E7h
	db 98h
	db 0E7h
	db 0ECh
	db 0E7h
	db 0FCh
	db 0E7h
	db         74h    t
	db 0E8h
	db 0C0h
	db 0E8h
	db 0D4h
	db 0E8h
	db         2Ah    *
	db 0E9h
	db 80h
	db 0E9h
	db 88h
	db 0E9h
	db 0C4h
	db 0E9h
	db         78h    x
	db 0EAh
	db 0A8h
	db 0EAh
	db 06h
	db 0EBh
	db 1Ch
	db 0EBh
L_096a:
	CALL       SUB_0000_3b7e
	OR         AX,AX
	JNZ        L_0992
	INC        word ptr [BP + -0ch]
L_0974:
	CMP        word ptr [BP + -0ch],7d0h
	JGE        L_0992
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [BX + 0b21eh]
	SUB        AH,AH
	CMP        AX,0fh
	JA         L_096a
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0eb2ah]
	db 90h
L_0992:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_04a4 ENDP
F_0998 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
L_099f:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_3eb2
	MOV        SI,AX
	CMP        byte ptr [SI + 0bd2ah],0h
	JNZ        L_099f
	CMP        byte ptr [SI + 0bd32h],0h
	JNZ        L_099f
	MOV        word ptr [BP + -2h],SI
	MOV        BX,SI
	MOV        byte ptr [BX + 0bd2ah],1h
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0998 ENDP
F_09c8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_2a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + 4h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_2b6c
	PUSH       word ptr [BP + 4h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_2b6c
	MOV        word ptr DS:[5156h],0h
	MOV        word ptr DS:[5158h],98h
	CALL       F_0998
	MOV        word ptr [BP + -4h],AX
	CALL       F_0998
	MOV        word ptr [BP + -6h],AX
	CMP        word ptr [BP + -4h],AX
	JLE        L_0a2e
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -0eh],AX
	MOV        byte ptr [BP + -0ah],42h
	JMP        L_0a3e
	db 90h
L_0a2e:
	MOV        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,word ptr [BP + -6h]
	MOV        word ptr [BP + -0eh],AX
	MOV        byte ptr [BP + -0ah],41h
L_0a3e:
	PUSH       word ptr [BP + 4h]
	MOV        AX,word ptr [BP + -0ch]
	ADD        AX,2h
	PUSH       AX
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [BX + 51fch]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 5204h]
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2b6c
	PUSH       word ptr [BP + 4h]
	MOV        AX,word ptr [BP + -0eh]
	ADD        AX,2h
	PUSH       AX
	MOV        BX,word ptr [BP + -0eh]
	MOV        AL,byte ptr [BX + 51fch]
	SUB        AH,AH
	ADD        AX,0b8h
	PUSH       AX
	MOV        AL,byte ptr [BX + 5204h]
	SUB        AH,AH
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2b6c
	MOV        AX,0a052h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,4h
	SHL        SI,CL
	MOV        BX,word ptr [BP + -6h]
	SHL        BX,1h
	PUSH       word ptr [BX + SI + 517ch]
	CALL       SUB_0000_438e
	PUSH       word ptr [BP + 6h]
	MOV        AX,0b21eh
	PUSH       AX
	CALL       F_0000
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2d8e
L_0ab4:
	CALL       SUB_0000_3b7e
	PUSH       AX
	CALL       SUB_0000_3e52
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,41h
	JZ         L_0ac6
	CMP        AL,42h
	JNZ        L_0ab4
L_0ac6:
	MOV        AL,byte ptr [BP + -0ah]
	CMP        byte ptr [BP + -2h],AL
	JZ         L_0ae0
	MOV        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [BP + -6h]
	MOV        word ptr [BP + -4h],AX
	MOV        AX,word ptr [BP + -8h]
	MOV        word ptr [BP + -6h],AX
L_0ae0:
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BX + 5164h]
	ADD        byte ptr DS:[0bd3ch],AL
	MOV        AL,byte ptr [BX + 516ch]
	ADD        byte ptr DS:[0bd3dh],AL
	MOV        AL,byte ptr [BX + 5174h]
	ADD        byte ptr DS:[0bd3eh],AL
	MOV        BX,word ptr [BP + -6h]
	MOV        byte ptr [BX + 0bd32h],1h
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_09c8 ENDP
F_0b0a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],40h
	JZ         L_0b1c
	CALL       SUB_0000_2e4e
L_0b1c:
	MOV        byte ptr DS:[0a9cbh],0ffh
L_0b21:
	PUSH       word ptr DS:[25eah]
	CALL       SUB_0000_2dce
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0b21
	MOV        word ptr [BP + -8h],SI
L_0b31:
	PUSH       word ptr DS:[260ah]
	CALL       SUB_0000_29ce
	MOV        SI,AX
	OR         SI,SI
	JZ         L_0b31
	MOV        word ptr [BP + -4h],SI
	MOV        AX,0a060h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e
	PUSH       word ptr DS:[13b2h]
	CALL       SUB_0000_2890
	MOV        AX,78h
	PUSH       AX
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,7eh
	PUSH       AX
	CALL       SUB_0000_28c6
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_2890
	MOV        AX,78h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,7fh
	PUSH       AX
	CALL       SUB_0000_2930
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2890
	MOV        AX,8h
	PUSH       AX
	MOV        AX,80h
	PUSH       AX
	MOV        AX,137h
	PUSH       AX
	MOV        AX,0bfh
	PUSH       AX
	CALL       SUB_0000_28c6
	MOV        AX,3h
	PUSH       AX
	MOV        AX,11h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,0a06ah
	PUSH       AX
	CALL       SUB_0000_3670
	MOV        AX,0eh
	PUSH       AX
	MOV        AX,13h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,3ah
	PUSH       AX
	CALL       SUB_0000_34da
	MOV        AX,55a8h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_3c58
	CMP        byte ptr DS:[55a8h],0h
	JNZ        L_0bd9
	JMP        L_0e40
L_0bd9:
	MOV        AX,8h
	PUSH       AX
	MOV        AX,15h
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,0a08ch
	PUSH       AX
	CALL       SUB_0000_3670
L_0beb:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_3bfa
	PUSH       AX
	CALL       SUB_0000_3e52
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,4dh
	JZ         L_0c00
	CMP        AL,46h
	JNZ        L_0beb
L_0c00:
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_34da
	CMP        byte ptr [BP + -2h],4dh
	JNZ        L_0c16
	MOV        byte ptr DS:[55b1h],0bh
	JMP        L_0c1b
L_0c16:
	MOV        byte ptr DS:[55b1h],0ch
L_0c1b:
	MOV        word ptr DS:[5156h],0h
	MOV        word ptr DS:[5158h],9h
	MOV        word ptr DS:[5146h],0h
	MOV        word ptr DS:[514ch],140h
	MOV        word ptr DS:[5148h],0afh
	MOV        word ptr DS:[514eh],140h
	MOV        word ptr DS:[5150h],59h
	MOV        word ptr DS:[5152h],0c8h
	MOV        AX,0a0a6h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_2a42
	MOV        byte ptr DS:[0a9beh],2h
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + -4h]
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,60h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2b6c
	PUSH       word ptr [BP + -8h]
	MOV        AX,0b21eh
	PUSH       AX
	CALL       F_0000
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2d8e
	MOV        word ptr DS:[5150h],0c8h
L_0c9b:
	CALL       SUB_0000_3b7e
	OR         AX,AX
	JZ         L_0c9b
	MOV        AL,DS:[55b6h]
	MOV        DS:[0bd3ch],AL
	MOV        AL,DS:[55b5h]
	MOV        DS:[0bd3dh],AL
	MOV        AL,DS:[55b4h]
	MOV        DS:[0bd3eh],AL
	SUB        CL,CL
L_0cb6:
	MOV        AX,CX
	SUB        AH,AH
	MOV        SI,AX
	SUB        AL,AL
	MOV        byte ptr [SI + 0bd32h],AL
	MOV        byte ptr [SI + 0bd2ah],AL
	INC        CL
	CMP        CL,8h
	JC         L_0cb6
	MOV        byte ptr [BP + -6h],CL
	MOV        byte ptr [BP + -6h],4h
	MOV        SI,4h
	MOV        DI,word ptr [BP + -4h]
L_0cda:
	PUSH       word ptr [BP + -8h]
	PUSH       DI
	CALL       F_09c8
	DEC        SI
	JNZ        L_0cda
	MOV        byte ptr [BP + -6h],0h
	SUB        BX,BX
	SUB        AX,AX
	MOV        CX,4h
	LEA        DI,[BX + 0bd2ah]
	PUSH       DS
	POP        ES
	REP STOSW
	ADD        byte ptr [BP + -6h],8h
	MOV        byte ptr [BP + -6h],2h
	MOV        SI,2h
	MOV        DI,word ptr [BP + -4h]
L_0d05:
	PUSH       word ptr [BP + -8h]
	PUSH       DI
	CALL       F_09c8
	DEC        SI
	JNZ        L_0d05
	MOV        byte ptr [BP + -6h],0h
	SUB        BX,BX
	SUB        AX,AX
	MOV        CX,4h
	LEA        DI,[BX + 0bd2ah]
	PUSH       DS
	POP        ES
	REP STOSW
	ADD        byte ptr [BP + -6h],8h
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -4h]
	CALL       F_09c8
	SUB        AX,AX
	MOV        DS:[5158h],AX
	MOV        DS:[5156h],AX
	MOV        word ptr DS:[5150h],5ah
	MOV        DS:[5148h],AX
	MOV        word ptr DS:[514eh],0a6h
	MOV        word ptr DS:[5154h],4h
	MOV        AX,0a0b4h
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,322h
	PUSH       AX
	CALL       SUB_0000_438e
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_2a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
	PUSH       word ptr [BP + -4h]
	MOV        AX,0ah
	PUSH       AX
	MOV        AX,0a8h
	PUSH       AX
	MOV        AX,64h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2b6c
	PUSH       word ptr [BP + -8h]
	MOV        AX,0b21eh
	PUSH       AX
	CALL       F_0000
	MOV        word ptr DS:[5154h],5h
	MOV        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2d8e
L_0d9c:
	CALL       SUB_0000_3b7e
	OR         AX,AX
	JZ         L_0d9c
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_2a04
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_2dfc
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_2a42
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_2a42
	MOV        byte ptr DS:[0a9beh],0h
	MOV        AL,DS:[0bd3ch]
	MOV        DS:[55b6h],AL
	MOV        DS:[55b7h],AL
	MOV        AL,DS:[0bd3dh]
	MOV        DS:[55b5h],AL
	MOV        AL,DS:[0bd3eh]
	SUB        AL,14h
	SBB        CL,CL
	NOT        CL
	AND        AL,CL
	ADD        AL,14h
	MOV        DS:[55b4h],AL
	MOV        AX,0a0c2h
	PUSH       AX
	MOV        AX,0b31eh
	PUSH       AX
	MOV        AX,100h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_438e
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_34da
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_3a12
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_433e
	MOV        CX,100h
	MOV        DI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	SUB        AL,AL
	REP STOSB
	MOV        AX,0a0cch
	PUSH       AX
	MOV        AX,0b21eh
	PUSH       AX
	MOV        AX,200h
	PUSH       AX
	CALL       SUB_0000_43f8
	MOV        AX,0a0d6h
	PUSH       AX
	MOV        AX,55a6h
	PUSH       AX
	MOV        AX,6606h
	SUB        AX,55a6h
	PUSH       AX
	CALL       SUB_0000_43f8
L_0e40:
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_433e
	MOV        byte ptr DS:[5893h],40h
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0b0a ENDP
F_0e52 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	PUSH       DI
	PUSH       DS
	CMP        word ptr DS:[520ch],0h
	JNZ        L_0e65
	CALL       SUB_0000_9b1e
	MOV        DS:[520ch],AX
L_0e65:
	MOV        DI,word ptr DS:[520ch]
	XOR        SI,SI
	MOV        DS,word ptr DS:[5354h]
	PUSH       CS
	POP        ES
	MOV        CX,1800h
	REP MOVSW
	POP        DS
	POP        DI
	POP        SI
	POP        BP
	RET
	; Func
F_0e52 ENDP
F_0e7b PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	PUSH       DI
	PUSH       DS
	MOV        SI,word ptr DS:[520ch]
	XOR        DI,DI
	MOV        ES,word ptr DS:[5354h]
	PUSH       CS
	POP        DS
	MOV        CX,1800h
	REP MOVSW
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
F_0e7b ENDP
_TEXT ENDS
END
