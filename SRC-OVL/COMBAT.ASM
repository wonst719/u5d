_TEXT SEGMENT BYTE 'CODE'
ORG 0a172h
SUB_0000_a172:
ORG 89bch
SUB_0000_89bc:
ORG 7e02h
SUB_0000_7e02:
ORG 0a11eh
SUB_0000_a11e:
ORG 0db46h
SUB_0000_db46:
ORG 92d4h
SUB_0000_92d4:
ORG 742ah
SUB_0000_742a:
ORG 0db22h
SUB_0000_db22:
ORG 0db2eh
SUB_0000_db2e:
ORG 0db5eh
SUB_0000_db5e:
ORG 75c0h
SUB_0000_75c0:
ORG 0db0ah
SUB_0000_db0a:
ORG 9cc4h
SUB_0000_9cc4:
ORG 8670h
SUB_0000_8670:
ORG 0c570h
SUB_0000_c570:
ORG 0db16h
SUB_0000_db16:
ORG 0dbeeh
SUB_0000_dbee:
ORG 0b680h
SUB_0000_b680:
ORG 0db76h
SUB_0000_db76:
ORG 0db82h
SUB_0000_db82:
ORG 0db8eh
SUB_0000_db8e:
ORG 0dbbeh
SUB_0000_dbbe:
ORG 0db9ah
SUB_0000_db9a:
ORG 0dbb2h
SUB_0000_dbb2:
ORG 0da86h
SUB_0000_da86:
ORG 8798h
SUB_0000_8798:
ORG 0a99ah
SUB_0000_a99a:
ORG 7fach
SUB_0000_7fac:
ORG 83dch
SUB_0000_83dc:
ORG 0db6ah
SUB_0000_db6a:
ORG 0dadah
SUB_0000_dada:
ORG 0dba6h
SUB_0000_dba6:
ORG 0dafeh
SUB_0000_dafe:
ORG 0dab6h
SUB_0000_dab6:
ORG 0daaah
SUB_0000_daaa:
ORG 0db3ah
SUB_0000_db3a:
ORG 0dbd6h
SUB_0000_dbd6:
ORG 7886h
SUB_0000_7886:
ORG 0dbfah
SUB_0000_dbfa:
ORG 0acech
SUB_0000_acec:
ORG 0b3b6h
SUB_0000_b3b6:
ORG 0a0d8h
SUB_0000_a0d8:
ORG 982eh
SUB_0000_982e:
ORG 0dc42h
SUB_0000_dc42:
ORG 0dc1eh
SUB_0000_dc1e:
ORG 981eh
SUB_0000_981e:
ORG 0dc12h
SUB_0000_dc12:
ORG 0caf2h
SUB_0000_caf2:
ORG 0cbd0h
SUB_0000_cbd0:
ORG 0cb18h
SUB_0000_cb18:
ORG 0c276h
SUB_0000_c276:
ORG 6dd8h
SUB_0000_6dd8:
ORG 0dc4eh
SUB_0000_dc4e:
ORG 9c84h
SUB_0000_9c84:
ORG 0c61eh
SUB_0000_c61e:
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
	CMP        word ptr [BP + 6h],0ah
	JG         L_0020
	CMP        word ptr [BP + 4h],0ah
	JG         L_0020
	CMP        word ptr [BP + 6h],0h
	JL         L_0020
	CMP        word ptr [BP + 4h],0h
	JGE        L_0026
L_0020:
	MOV        AX,1h
	JMP        L_0146
L_0026:
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_a172
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_89bc
	OR         AX,AX
	JNZ        L_0043
	JMP        L_0144
L_0043:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_a172
	MOV        BX,AX
	CMP        byte ptr [BX],0ffh
	JNZ        L_0056
	JMP        L_0144
L_0056:
	MOV        word ptr [BP + -6h],0h
	MOV        word ptr [BP + -8h],5c5ch
	MOV        word ptr [BP + -0ah],5c5dh
	MOV        word ptr [BP + -0ch],5c5ah
	MOV        word ptr [BP + -0eh],5c5bh
	MOV        word ptr [BP + -10h],0ba1ah
	MOV        word ptr [BP + -12h],0ba1bh
	MOV        word ptr [BP + -14h],0ba16h
	MOV        DI,0ba18h
	MOV        SI,word ptr [BP + -4h]
	MOV        DX,word ptr [BP + -2h]
L_0087:
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_0108
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_0108
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [BX]
	MOV        DX,AX
	CMP        DX,0ebh
	JNZ        L_00b6
L_00aa:
	SUB        AX,AX
	MOV        word ptr [BP + -4h],SI
	MOV        word ptr [BP + -2h],DX
	JMP        L_0146
	db 90h
L_00b6:
	MOV        AX,DX
	AND        AL,0fch
	CMP        AL,0e8h
	JZ         L_00c8
	CMP        DX,1eh
	JZ         L_00c8
	CMP        DX,1fh
	JNZ        L_00fa
L_00c8:
	ADD        word ptr [BP + -8h],8h
	ADD        word ptr [BP + -0ah],8h
	ADD        word ptr [BP + -0ch],8h
	ADD        word ptr [BP + -0eh],8h
	ADD        word ptr [BP + -10h],8h
	ADD        word ptr [BP + -12h],8h
	ADD        word ptr [BP + -14h],8h
	ADD        DI,8h
	INC        word ptr [BP + -6h]
	CMP        DI,0bb18h
	JC         L_0087
	MOV        word ptr [BP + -4h],SI
	MOV        word ptr [BP + -2h],DX
	JMP        L_0020
	db 90h
L_00fa:
	OR         DX,DX
	JZ         L_00c8
	MOV        BX,word ptr [BP + -0eh]
	CMP        byte ptr [BX],0h
	JNZ        L_00aa
	JMP        L_00c8
L_0108:
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_00c8
	MOV        BX,word ptr [BP + -12h]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_00c8
	MOV        BX,word ptr [BP + -14h]
	MOV        AL,byte ptr [BX]
	MOV        SI,AX
	TEST       AL,24h
	JNZ        L_00c8
	OR         SI,SI
	JZ         L_00c8
	MOV        BL,byte ptr [DI]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 5c5bh],AH
	JNZ        L_013e
	JMP        L_00aa
L_013e:
	TEST       AL,8h
	JMP        L_00aa
	db 90h
L_0144:
	SUB        AX,AX
L_0146:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_0000 ENDP
F_014e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	MOV        BX,word ptr [BP + 8h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 15cch]
	MOV        word ptr [BP + -2h],AX
	CMP        BX,1ah
	JZ         L_0182
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_7e02
	CMP        AX,80h
	JGE        L_019d
L_0182:
	MOV        BX,word ptr [BP + -8h]
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],8000h
	JZ         L_01a2
	CMP        byte ptr DS:[587ah],4eh
	JZ         L_019d
	CMP        byte ptr DS:[587ah],1ch
	JNZ        L_01a2
L_019d:
	SUB        AX,AX
	JMP        L_021f
	db 90h
L_01a2:
	MOV        AX,2eeh
	PUSH       AX
	MOV        AX,190h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	CALL       SUB_0000_a11e
	CMP        word ptr [BP + 4h],0h
	JZ         L_01c2
	MOV        word ptr [BP + -4h],0h
	JMP        L_01d9
L_01c2:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 8h]
	MOV        AL,DS:[588fh]
	SUB        AH,AH
	NEG        AX
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_14d6
	MOV        word ptr [BP + -4h],AX
L_01d9:
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	PUSH       word ptr [BP + 8h]
	MOV        AL,byte ptr [SI + 0ba1ah]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_db46
	MOV        word ptr [BP + -6h],AX
	OR         AX,AX
	JL         L_021c
	PUSH       AX
	CALL       SUB_0000_92d4
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + 8h]
	CALL       F_194a
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + 8h]
	CALL       SUB_0000_db22
L_021c:
	MOV        AX,1h
L_021f:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_014e ENDP
F_0226 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       SI
	MOV        word ptr [BP + -0ah],0h
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX
	MOV        AL,byte ptr [SI + 0ba18h]
	MOV        word ptr [BP + -6h],AX
	PUSH       word ptr [BP + 4h]
	CALL       F_0d30
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JGE        L_025c
L_0256:
	SUB        AX,AX
	JMP        L_03ec
	db 90h
L_025c:
	MOV        BX,word ptr [BP + -2h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],1h
	JZ         L_029c
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_db2e
	CMP        AX,1h
	JNZ        L_0256
	MOV        byte ptr DS:[589dh],21h
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -2h]
	MOV        AX,21h
	PUSH       AX
	CALL       SUB_0000_db5e
	JMP        L_035f
	db 90h
L_029c:
	MOV        BX,word ptr [BP + -2h]
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_02df
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55c6h],2dh
	JNZ        L_02df
	MOV        BX,word ptr [BP + -8h]
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],8000h
	JZ         L_02df
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_7e02
	CMP        AX,80h
	JGE        L_02da
	MOV        AX,1h
	JMP        L_02dc
	db 90h
L_02da:
	SUB        AX,AX
L_02dc:
	MOV        word ptr [BP + -0ah],AX
L_02df:
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_db2e
	MOV        BX,word ptr [BP + -8h]
	MOV        CL,byte ptr [BX + 159ch]
	SUB        CH,CH
	CMP        CX,AX
	JNC        L_02f8
	JMP        L_0256
L_02f8:
	CMP        BX,1ah
	JNZ        L_0309
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c60h],20h
L_0309:
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_db2e
	CMP        AX,1h
	JZ         L_031a
	JMP        L_03e0
L_031a:
	CMP        word ptr [BP + -8h],2dh
	JNZ        L_032c
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c60h],20h
L_032c:
	MOV        AX,2eeh
	PUSH       AX
	MOV        AX,190h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	CALL       SUB_0000_a11e
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BP + 4h]
	MOV        byte ptr [BX + 58a8h],AL
	PUSH       BX
	PUSH       word ptr [BP + 4h]
	MOV        AL,DS:[588fh]
	SUB        AH,AH
	NEG        AX
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_14d6
	OR         AX,AX
	JNZ        L_0366
L_035f:
	MOV        AX,1h
	JMP        L_03ec
	db 90h
L_0366:
	MOV        BX,word ptr [BP + -8h]
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],2h
	JZ         L_03be
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	OR         AX,AX
	JZ         L_03be
	CMP        word ptr DS:[57a8h],0h
	JZ         L_03be
	MOV        AX,6d74h
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_db0a
	MOV        AX,6d78h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,57a8h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_9cc4
	MOV        AX,320h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	CALL       SUB_0000_a11e
	CALL       SUB_0000_8670
	JMP        L_035f
L_03be:
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_92d4
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + 4h]
	CALL       F_194a
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_db22
	JMP        L_035f
L_03e0:
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -0ah]
	CALL       F_014e
L_03ec:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0226 ENDP
F_03f4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        byte ptr DS:[589dh],0h
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	CMP        byte ptr DS:[587ah],54h
	JNZ        L_0422
	JMP        L_0540
L_0422:
	CMP        byte ptr DS:[587ah],51h
	JNZ        L_043a
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7e02
	OR         AX,AX
	JNZ        L_043a
	JMP        L_0540
L_043a:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],4h
	JZ         L_0446
	JMP        L_0540
L_0446:
	TEST       byte ptr [BX + 2h],8h
	JZ         L_046a
	SUB        AX,AX
	PUSH       AX
	MOV        AX,10h
	PUSH       AX
	CALL       SUB_0000_7e02
	CMP        AX,10h
	JZ         L_045e
	JMP        L_0540
L_045e:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_c570
	JMP        L_0540
L_046a:
	MOV        BX,word ptr [BP + -2h]
	CMP        byte ptr [BX + 3h],2dh
	JNZ        L_047f
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c60h],0h
L_047f:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],2h
	JZ         L_04ae
	TEST       byte ptr [BX + 2h],80h
	JNZ        L_04a2
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	CMP        AX,3h
	JNZ        L_04a2
	MOV        BX,word ptr [BP + -2h]
	INC        byte ptr [BX]
L_04a2:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_1a5c
	JMP        L_04cb
	db 90h
L_04ae:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_db16
	OR         AX,AX
	JZ         L_04be
	JMP        L_0540
L_04be:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0226
	OR         AX,AX
	JNZ        L_0540
L_04cb:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0ee4
	OR         AX,AX
	JZ         L_052e
	TEST       byte ptr DS:[58a2h],10h
	JZ         L_0527
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_a11e
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_db0a
	MOV        AX,6d8ch
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	NEG        AX
	DEC        AX
	PUSH       AX
	CALL       F_1236
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],80h
	JNZ        L_0527
	CMP        byte ptr [BX + 3h],2fh
	JNZ        L_0527
	CALL       SUB_0000_dbee
L_0527:
	CALL       SUB_0000_b680
	JMP        L_0540
	db 90h
	db 90h
L_052e:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],2h
	JZ         L_0540
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_0226
L_0540:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_03f4 ENDP
F_0544 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_75c0
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_05a4
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_0580
	CMP        AX,1h
	JZ         L_0586
	CMP        AX,2h
	JZ         L_058c
	CMP        AX,3h
	JZ         L_0592
	CMP        AX,4h
	JZ         L_0598
	CMP        AX,5h
	JZ         L_059e
	JMP        L_05b0
L_0580:
	CALL       SUB_0000_db76
	JMP        L_05b0
	db 90h
L_0586:
	CALL       SUB_0000_db82
	JMP        L_05b0
	db 90h
L_058c:
	CALL       SUB_0000_db8e
	JMP        L_05b0
	db 90h
L_0592:
	CALL       SUB_0000_dbbe
	JMP        L_05b0
	db 90h
L_0598:
	CALL       SUB_0000_db9a
	JMP        L_05b0
	db 90h
L_059e:
	CALL       SUB_0000_dbb2
	JMP        L_05b0
	db 90h
L_05a4:
	MOV        AX,6d98h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1h
	JMP        L_05b2
L_05b0:
	SUB        AX,AX
L_05b2:
	POP        BP
	RET        4h
	; Func
F_0544 ENDP
F_05b6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	CMP        word ptr [BP + 6h],0ffh
	JZ         L_0636
	MOV        BX,word ptr [BP + 6h]
	CMP        byte ptr [BX + 15fch],0h
	JZ         L_0636
	CMP        word ptr [BP + 4h],0h
	JZ         L_05fb
	MOV        DI,6da0h
	MOV        SI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	MOV        CX,0ffffh
	XOR        AX,AX
	SCASB.RE   ES:DI
	NOT        CX
	SUB        DI,CX
	MOV        BX,CX
	XCHG       SI,DI
	MOV        CX,0ffffh
	SCASB.RE   ES:DI
	DEC        DI
	MOV        CX,BX
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
L_05fb:
	MOV        BX,word ptr [BP + 6h]
	SHL        BX,1h
	MOV        AX,word ptr [BX + 17f6h]
	MOV        CX,AX
	MOV        DX,CX
	MOV        DI,DX
	MOV        SI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	MOV        CX,0ffffh
	XOR        AX,AX
	SCASB.RE   ES:DI
	NOT        CX
	SUB        DI,CX
	MOV        BX,CX
	XCHG       SI,DI
	MOV        CX,0ffffh
	SCASB.RE   ES:DI
	DEC        DI
	MOV        CX,BX
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
	MOV        AX,1h
	JMP        L_0638
	db 90h
L_0636:
	SUB        AX,AX
L_0638:
	POP        SI
	POP        DI
	POP        BP
	RET        4h
	; Func
F_05b6 ENDP
F_063e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba1ah]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [SI + 0ba1bh]
	MOV        DS:[5897h],AL
	MOV        AL,byte ptr [SI + 0ba17h]
	MOV        word ptr [BP + -8h],AX
	CMP        byte ptr DS:[587bh],0ffh
	JZ         L_0682
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_067c
	MOV        AL,DS:[587bh]
	CMP        word ptr [BP + -8h],AX
	JZ         L_0682
L_067c:
	CALL       SUB_0000_da86
	JMP        L_0b8e
L_0682:
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_06c8
	MOV        SI,word ptr [BP + -8h]
	MOV        CL,5h
	SHL        SI,CL
	CMP        byte ptr [SI + 55c3h],23h
	JZ         L_06a8
	CMP        byte ptr [SI + 55c4h],23h
	JNZ        L_06c8
L_06a8:
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	OR         byte ptr [BX + 0ba16h],1h
	MOV        byte ptr DS:[587bh],0ffh
	MOV        byte ptr DS:[0a9fah],1h
	CALL       F_03f4
	JMP        L_0b79
	db 90h
L_06c8:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_06e2
	MOV        AL,byte ptr [SI + 0ba17h]
	PUSH       AX
	CALL       SUB_0000_8798
L_06e2:
	CMP        byte ptr DS:[0a9fah],0h
	JZ         L_06f1
	CALL       SUB_0000_8670
	MOV        byte ptr DS:[0a9fah],0h
L_06f1:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_db0a
	MOV        byte ptr DS:[0b21eh],0h
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_0782
	MOV        AX,6da4h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        SI,word ptr [BP + -8h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 55c1h]
	SUB        AH,AH
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       F_05b6
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,byte ptr [SI + 55c3h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -0ah]
	CALL       F_05b6
	ADD        word ptr [BP + -0ah],AX
	MOV        AL,byte ptr [SI + 55c4h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -0ah]
	CALL       F_05b6
	ADD        word ptr [BP + -0ah],AX
	JNZ        L_0782
	PUSH       SI
	MOV        DI,6db2h
	MOV        SI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	MOV        CX,0ffffh
	XOR        AX,AX
	SCASB.RE   ES:DI
	NOT        CX
	SUB        DI,CX
	MOV        BX,CX
	XCHG       SI,DI
	MOV        CX,0ffffh
	SCASB.RE   ES:DI
	DEC        DI
	MOV        CX,BX
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
	POP        SI
L_0782:
	MOV        DI,6dbeh
	MOV        SI,0b21eh
	MOV        AX,DS
	MOV        ES,AX
	MOV        CX,0ffffh
	XOR        AX,AX
	SCASB.RE   ES:DI
	NOT        CX
	SUB        DI,CX
	MOV        BX,CX
	XCHG       SI,DI
	MOV        CX,0ffffh
	SCASB.RE   ES:DI
	DEC        DI
	MOV        CX,BX
	SHR        CX,1h
	REP MOVSW
	ADC        CX,CX
	REP MOVSB
	MOV        AX,0b21eh
	PUSH       AX
	CALL       SUB_0000_75c0
	SUB        AX,AX
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -4h],AX
L_07ba:
	CMP        word ptr [BP + -4h],0h
	JZ         L_07c3
	JMP        L_0b56
L_07c3:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_742a
	CALL       SUB_0000_a99a
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],4h
	JZ         L_0800
	MOV        AX,6dc0h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,28h
	PUSH       AX
	MOV        AX,0bb8h
	PUSH       AX
	MOV        AX,1f4h
	PUSH       AX
	CALL       SUB_0000_7fac
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       F_1c66
	JMP        L_0830
	db 90h
L_0800:
	MOV        BL,byte ptr DS:[589eh]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],8h
	JZ         L_0838
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_7e02
	CMP        AX,10h
	JGE        L_0829
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_c570
L_0829:
	MOV        AX,6dc8h
	PUSH       AX
	CALL       SUB_0000_75c0
L_0830:
	MOV        word ptr [BP + -4h],1h
	JMP        L_07ba
	db 90h
L_0838:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -6h],AL
	MOV        word ptr [BP + -4h],1h
	MOV        word ptr [BP + -2h],0h
	SUB        AH,AH
	CMP        AX,4ah
	JNZ        L_0852
	JMP        L_097a
L_0852:
	JBE        L_0857
	JMP        L_0ade
L_0857:
	CMP        AX,41h
	JNZ        L_085f
	JMP        L_08e0
L_085f:
	JBE        L_0864
	JMP        L_0abe
L_0864:
	CMP        AX,1bh
	JNZ        L_086c
	JMP        L_09dc
L_086c:
	JBE        L_0871
	JMP        L_0a9a
L_0871:
	CMP        AX,1h
	JNC        L_0879
	JMP        L_0ab7
L_0879:
	CMP        AX,4h
	JA         L_0881
	JMP        L_0a14
L_0881:
	CMP        AX,13h
	JZ         L_08b6
	JMP        L_0ab7
	db 90h
L_088a:
	MOV        AX,6dd2h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        word ptr DS:[538ch],1h
	SBB        AX,AX
	NEG        AX
	MOV        DS:[538ch],AX
	OR         AX,AX
	JZ         L_08a6
	MOV        AX,6ddch
	JMP        L_08a9
L_08a6:
	MOV        AX,6de0h
L_08a9:
	PUSH       AX
	CALL       SUB_0000_75c0
L_08ad:
	MOV        word ptr [BP + -4h],0h
	JMP        L_07ba
	db 90h
L_08b6:
	MOV        AX,6de4h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr DS:[0a9ceh],0h
	JZ         L_08ca
	MOV        AX,6dech
	JMP        L_08cd
	db 90h
L_08ca:
	MOV        AX,6df2h
L_08cd:
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        byte ptr DS:[0a9ceh],1h
	SBB        AX,AX
	NEG        AX
	MOV        DS:[0a9ceh],AL
	JMP        L_08ad
	db 90h
L_08e0:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_db6a
	JMP        L_07ba
	db 90h
	db 0B8h
	db 0F6h
	db         6Dh    m
	db         50h    P
	db 0E8h
	db 0C9h
	db         6Ch    l
	db 0C7h
	db         46h    F
	db 0FEh
	db 01h
	db 00h
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db 8Bh
	db 0F0h
	db 8Bh
	db 0DEh
	db 0B1h
	db 03h
	db 0D3h
	db 0E3h
	db 0F6h
	db 87h
	db 16h
	db 0BAh
	db 80h
	db         74h    t
	db         54h    T
	db         56h    V
	db 0E8h
	db         3Eh    >
	db 0D2h
	db 0Bh
	db 0C0h
	db         74h    t
	db 03h
	db 0E9h
	db 9Fh
	db 0FEh
	db 0B0h
	db 01h
	db 0A2h
	db 90h
	db         58h    X
	db 0A2h
	db 8Fh
	db         58h    X
	db 0C7h
	db         46h    F
	db 0FEh
	db 00h
	db 00h
	db 80h
	db         3Eh    >
	db         7Ah    z
	db         58h    X
	db         4Eh    N
	db         74h    t
	db 0Eh
	db 80h
	db         3Eh    >
	db 0B4h
	db         57h    W
	db 00h
	db         75h    u
	db         28h    (
	db 80h
	db         3Eh    >
	db 94h
	db         58h    X
	db 12h
	db         75h    u
	db         21h    !
	db 0B8h
	db 00h
	db         6Eh    n
	db         50h    P
	db 0E8h
	db         7Ch    |
	db         6Ch    l
	db 0B8h
	db         48h    H
	db         26h    &
	db         50h    P
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db         60h    `
	db         6Dh    m
	db         50h    P
	db 0B8h
	db 0E8h
	db 03h
	db         50h    P
	db 0B8h
	db 02h
	db 00h
	db         50h    P
	db 0E8h
	db 0A7h
	db         75h    u
	db 0E9h
	db         5Ch    \
	db 0FEh
	db 0E8h
	db         69h    i
	db 0D2h
	db 0E9h
	db         56h    V
	db 0FEh
	db 0B8h
	db 0Ch
	db         6Eh    n
	db 0EBh
	db         7Ch    |
	db 90h
	db 0B8h
	db 14h
	db         6Eh    n
	db         50h    P
	db         2Bh    +
	db 0C0h
L_0970:
	PUSH       AX
	CALL       F_0544
L_0974:
	MOV        word ptr [BP + -2h],AX
	JMP        L_07ba
L_097a:
	MOV        AX,6e1ah
	PUSH       AX
	MOV        AX,1h
	JMP        L_0970
	db 90h
	db 0E8h
	db         5Bh    [
	db 0D2h
	db 0E9h
	db 97h
	db 00h
	db 0B8h
	db         22h    "
	db         6Eh    n
	db         50h    P
	db 0B8h
	db 02h
	db 00h
	db 0EBh
	db 0DDh
	db 90h
	db 0B8h
	db         28h    (
	db         6Eh    n
	db         50h    P
	db 0E8h
	db         25h    %
	db         6Ch    l
	db 0E8h
	db 0DCh
	db 0D0h
	db 0E9h
	db 19h
	db 0FEh
	db 90h
L_09a2:
	MOV        AX,6e2eh
	PUSH       AX
	MOV        AX,3h
	JMP        L_0970
	db 90h
L_09ac:
	MOV        AX,6e3ah
	PUSH       AX
	MOV        AX,4h
	JMP        L_0970
	db 90h
L_09b6:
	MOV        AX,6e42h
	PUSH       AX
	MOV        AX,5h
	JMP        L_0970
	db 90h
L_09c0:
	MOV        AX,6e4eh
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_dada
	JMP        L_07ba
	db 90h
L_09ce:
	MOV        AX,6e54h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_dba6
	JMP        L_07ba
	db 90h
L_09dc:
	CALL       SUB_0000_dafe
	JMP        L_0974
	db 90h
L_09e2:
	MOV        AX,6e60h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_07ba
L_09ec:
	MOV        byte ptr DS:[587bh],0ffh
	MOV        AX,6e66h
	PUSH       AX
	CALL       SUB_0000_75c0
	CALL       SUB_0000_8670
	JMP        L_07ba
L_09fe:
	MOV        AL,byte ptr [BP + -6h]
	SUB        AH,AH
	SUB        AX,31h
	PUSH       AX
	CALL       SUB_0000_dab6
	OR         AX,AX
	JZ         L_0a11
	JMP        L_07ba
L_0a11:
	JMP        L_0a41
	db 90h
L_0a14:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BP + -6h]
	PUSH       AX
	CALL       SUB_0000_daaa
	OR         AX,AX
	JZ         L_0a28
	JMP        L_07ba
L_0a28:
	JMP        L_08ad
	db 90h
	db 0B8h
	db         7Eh    ~
	db         6Eh    n
L_0a2f:
	PUSH       AX
	MOV        AX,1h
L_0a33:
	PUSH       AX
	CALL       SUB_0000_db3a
	JMP        L_0974
	db 0B8h
	db 84h
	db         6Eh    n
L_0a3d:
	PUSH       AX
	CALL       SUB_0000_75c0
L_0a41:
	MOV        word ptr [BP + -2h],1h
	JMP        L_07ba
	db 90h
	db 0B8h
	db 8Eh
	db         6Eh    n
L_0a4d:
	PUSH       AX
	MOV        AX,2h
	JMP        L_0a33
	db 90h
	db 0B8h
	db 94h
	db         6Eh    n
	db 0EBh
	db 0F4h
	db 90h
	db 0B8h
	db 9Ah
	db         6Eh    n
	db 0EBh
	db 0EEh
	db 90h
	db 0B8h
	db 0A2h
	db         6Eh    n
	db 0EBh
	db 0E8h
	db 90h
	db 0B8h
	db 0B0h
	db         6Eh    n
	db 0EBh
	db 0E2h
	db 90h
	db 0B8h
	db 0B6h
	db         6Eh    n
	db 0EBh
	db 0DCh
	db 90h
	db 0B8h
	db 0BAh
	db         6Eh    n
	db 0EBh
	db 0D6h
	db 90h
	db 0B8h
	db 0C4h
	db         6Eh    n
	db 0EBh
	db 0D0h
	db 90h
L_0a7e:
	MOV        AX,6ecah
	PUSH       AX
	MOV        AX,3h
	JMP        L_0a33
	db 90h
L_0a88:
	MOV        AX,6ed0h
	JMP        L_0a4d
	db 90h
L_0a8e:
	MOV        AX,6ed6h
	JMP        L_0a3d
	db 90h
L_0a94:
	MOV        AX,6ee0h
	JMP        L_0a2f
	db 90h
L_0a9a:
	CMP        AX,20h
	JNZ        L_0aa2
	JMP        L_09e2
L_0aa2:
	CMP        AX,30h
	JNZ        L_0aaa
	JMP        L_09ec
L_0aaa:
	CMP        AX,31h
	JC         L_0ab7
	CMP        AX,36h
	JA         L_0ab7
	JMP        L_09fe
L_0ab7:
	MOV        AX,6ee6h
	JMP        L_08a9
	db 90h
L_0abe:
	SUB        AX,42h
	CMP        AX,7h
	JA         L_0ab7
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0ad5eh]
	db 0BCh
	db 0ACh
	db 80h
	db 0ABh
	db 0CAh
	db 0ACh
	db 0DAh
	db 0ACh
	db 0E4h
	db 0ACh
	db 0FAh
	db 0ABh
	db 0EAh
	db 0ACh
	db 0F0h
	db 0ACh
L_0ade:
	CMP        AX,52h
	JNZ        L_0ae6
	JMP        L_09a2
L_0ae6:
	JA         L_0b06
	SUB        AX,4bh
	CMP        AX,6h
	JA         L_0ab7
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0ad88h]
	db 14h
	db 0ACh
	db 0F6h
	db 0ACh
	db 0FCh
	db 0ACh
	db 02h
	db 0ADh
	db 1Ah
	db 0ACh
	db         24h    $
	db 0ACh
	db 08h
	db 0ADh
L_0b06:
	CMP        AX,56h
	JNZ        L_0b0e
	JMP        L_0a88
L_0b0e:
	JA         L_0b2a
	CMP        AX,53h
	JNZ        L_0b18
	JMP        L_09ac
L_0b18:
	CMP        AX,54h
	JNZ        L_0b20
	JMP        L_0a7e
L_0b20:
	CMP        AX,55h
	JNZ        L_0b28
	JMP        L_09b6
L_0b28:
	JMP        L_0ab7
L_0b2a:
	CMP        AX,57h
	JNZ        L_0b32
	JMP        L_0a8e
L_0b32:
	CMP        AX,58h
	JNZ        L_0b3a
	JMP        L_0a94
L_0b3a:
	CMP        AX,59h
	JNZ        L_0b42
	JMP        L_09c0
L_0b42:
	CMP        AX,5ah
	JNZ        L_0b4a
	JMP        L_09ce
L_0b4a:
	CMP        AX,0fch
	JNZ        L_0b52
	JMP        L_088a
L_0b52:
	JMP        L_0ab7
	db 90h
L_0b56:
	CMP        word ptr [BP + -2h],0h
	JZ         L_0b5f
	JMP        L_06f1
L_0b5f:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_0b79
	MOV        AL,byte ptr [SI + 0ba17h]
	PUSH       AX
	CALL       SUB_0000_8798
L_0b79:
	CMP        byte ptr [BP + -6h],30h
	JC         L_0b85
	CMP        byte ptr [BP + -6h],36h
	JBE        L_0b8e
L_0b85:
	CALL       SUB_0000_da86
	CALL       SUB_0000_b680
	CALL       SUB_0000_dbd6
L_0b8e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_063e ENDP
F_0b94 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],1h
	MOV        byte ptr DS:[58a0h],0h
	CALL       SUB_0000_b680
	CALL       SUB_0000_8670
	CALL       SUB_0000_7886
	CALL       SUB_0000_dbfa
	CMP        word ptr DS:[5876h],0h
	JNZ        L_0bc0
	MOV        byte ptr DS:[58a3h],1h
	JMP        L_0bc5
L_0bc0:
	MOV        byte ptr DS:[58a3h],0h
L_0bc5:
	MOV        word ptr [BP + -8h],0h
L_0bca:
	MOV        byte ptr DS:[589eh],0h
L_0bcf:
	MOV        byte ptr DS:[594fh],0h
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,0ba14h
	MOV        AL,byte ptr [SI + 2h]
	MOV        DI,AX
	TEST       AL,0c0h
	JNZ        L_0bef
	JMP        L_0d08
L_0bef:
	TEST       AL,20h
	JZ         L_0bf6
	JMP        L_0d08
L_0bf6:
	TEST       AL,80h
	JZ         L_0c26
	MOV        BL,byte ptr [SI + 3h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JNZ        L_0c26
	OR         byte ptr [SI + 2h],20h
	MOV        AL,DS:[589eh]
	PUSH       AX
	CALL       SUB_0000_92d4
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       F_1574
	JMP        L_0d08
	db 90h
L_0c26:
	MOV        BL,byte ptr [SI + 7h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [SI + 6h]
	SUB        AH,AH
	ADD        BX,AX
	MOV        AL,byte ptr [BX + 0ad14h]
	AND        AL,0feh
	CMP        AL,84h
	JNZ        L_0c43
	JMP        L_0d08
L_0c43:
	DEC        byte ptr [SI + 5h]
	JZ         L_0c4b
	JMP        L_0d08
L_0c4b:
	MOV        AL,24h
	SUB        AL,byte ptr [SI + 1h]
	MOV        byte ptr [SI + 5h],AL
	SUB        AL,AL
	MOV        DS:[5898h],AL
	MOV        DS:[58a2h],AL
	MOV        DS:[588fh],AL
	MOV        DS:[5890h],AL
	MOV        DS:[589dh],AL
	INC        byte ptr DS:[5882h]
	CMP        byte ptr DS:[5882h],0ah
	JNZ        L_0c79
	MOV        DS:[5882h],AL
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_acec
L_0c79:
	MOV        byte ptr DS:[589fh],1h
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_b3b6
	OR         AX,AX
	JZ         L_0c90
	CALL       F_03f4
	JMP        L_0c93
L_0c90:
	CALL       F_063e
L_0c93:
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX
	MOV        BX,AX
	MOV        byte ptr [BX + 58a8h],0ffh
	PUSH       AX
	CALL       F_1b1e
	CALL       SUB_0000_dbfa
	CMP        word ptr DS:[5878h],0h
	JNZ        L_0ce8
	CMP        word ptr DS:[5876h],0h
	JNZ        L_0cca
	MOV        word ptr [BP + -2h],0h
L_0cbc:
	MOV        word ptr [BP + -8h],1h
L_0cc1:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -6h],SI
	JMP        L_0d16
	db 90h
L_0cca:
	CALL       SUB_0000_dbee
	INC        AX
	JNZ        L_0d08
	CALL       SUB_0000_b680
	CMP        byte ptr DS:[58a3h],0h
	JNZ        L_0cbc
	MOV        AX,6eeeh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        word ptr [BP + -2h],1h
	JMP        L_0cbc
L_0ce8:
	CMP        word ptr DS:[5876h],0h
	JNZ        L_0d08
	CMP        byte ptr DS:[58a3h],0h
	JNZ        L_0d08
	MOV        AX,6f00h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        byte ptr DS:[58a3h],1h
	CALL       SUB_0000_a0d8
	CALL       SUB_0000_7886
L_0d08:
	INC        byte ptr DS:[589eh]
	CMP        byte ptr DS:[589eh],20h
	JNC        L_0cc1
	JMP        L_0bcf
L_0d16:
	CMP        word ptr [BP + -8h],0h
	JNZ        L_0d1f
	JMP        L_0bca
L_0d1f:
	CALL       SUB_0000_7886
	MOV        byte ptr DS:[2186h],0ffh
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0b94 ENDP
F_0d30 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ch
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0eh],0ffffh
	MOV        word ptr [BP + -14h],0ffffh
	MOV        word ptr [BP + -2h],63h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -4h],AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_b3b6
	MOV        word ptr [BP + -6h],AX
	CMP        byte ptr DS:[587ah],43h
	JNZ        L_0d7e
	PUSH       word ptr [BP + 4h]
	MOV        AX,0ffffh
	PUSH       AX
	CALL       F_13e2
	MOV        word ptr [BP + -16h],AX
	CALL       SUB_0000_982e
	CMP        AX,word ptr [BP + -16h]
	JLE        L_0d7e
	MOV        word ptr [BP + -6h],0h
L_0d7e:
	MOV        DI,1fh
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BX + 7h]
	SUB        AH,AH
	MOV        word ptr [BP + -18h],AX
	MOV        AL,byte ptr [BX + 6h]
	MOV        word ptr [BP + -1ah],AX
	MOV        word ptr [BP + -1ch],0bb0ch
L_0d97:
	MOV        SI,word ptr [BP + -1ch]
	CMP        DI,word ptr [BP + 4h]
	JZ         L_0e10
	CMP        byte ptr [SI + 2h],0h
	JZ         L_0e10
	TEST       byte ptr [SI + 2h],20h
	JNZ        L_0e10
	PUSH       DI
	CALL       SUB_0000_b3b6
	MOV        word ptr [BP + -8h],AX
	CMP        word ptr [BP + -6h],AX
	JZ         L_0e10
	CMP        byte ptr DS:[5894h],28h
	JZ         L_0dcd
	MOV        BX,word ptr [BP + -4h]
	CMP        byte ptr [BX + 3h],2fh
	JZ         L_0dcd
	TEST       byte ptr [SI + 2h],10h
	JNZ        L_0e10
L_0dcd:
	TEST       byte ptr [SI + 2h],4h
	JNZ        L_0e10
	CMP        DI,5h
	JGE        L_0ddb
	INC        word ptr [BP + -0eh]
L_0ddb:
	PUSH       word ptr [BP + -1ah]
	PUSH       word ptr [BP + -18h]
	MOV        AL,byte ptr [SI + 6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 7h]
	PUSH       AX
	CALL       SUB_0000_dc42
	MOV        word ptr [BP + -16h],AX
	MOV        AX,word ptr [BP + -2h]
	CMP        word ptr [BP + -16h],AX
	JGE        L_0e10
	MOV        AX,word ptr [BP + -16h]
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -14h],DI
	MOV        AL,byte ptr [SI + 6h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	MOV        AL,byte ptr [SI + 7h]
	MOV        word ptr [BP + -10h],AX
L_0e10:
	SUB        word ptr [BP + -1ch],8h
	DEC        DI
	CMP        DI,-1h
	JLE        L_0e1d
	JMP        L_0d97
L_0e1d:
	MOV        word ptr [BP + -12h],DI
	MOV        word ptr [BP + -0ah],SI
	CMP        word ptr [BP + -0eh],-1h
	JNZ        L_0e35
	CMP        word ptr [BP + -14h],-1h
	JNZ        L_0e35
	CALL       SUB_0000_dbee
	MOV        word ptr [BP + -14h],AX
L_0e35:
	CMP        word ptr [BP + -14h],-1h
	JNZ        L_0e67
	MOV        word ptr [BP + -12h],5h
	MOV        SI,0bb0eh
	MOV        DI,0bb0ch
L_0e46:
	TEST       byte ptr [SI],40h
	JZ         L_0e51
	MOV        byte ptr [DI],1h
	OR         byte ptr [SI],2h
L_0e51:
	SUB        SI,8h
	SUB        DI,8h
	CMP        DI,0ba3ch
	JA         L_0e46
	MOV        word ptr [BP + -0ch],5h
	MOV        word ptr [BP + -10h],5h
L_0e67:
	SUB        AX,AX
	MOV        DS:[5878h],AX
	MOV        DS:[5876h],AX
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -0ch]
	JBE        L_0e82
	MOV        word ptr DS:[5876h],0ffffh
L_0e82:
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -0ch]
	JNC        L_0e92
	MOV        word ptr DS:[5876h],1h
L_0e92:
	MOV        AL,byte ptr [BX + 7h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -10h]
	JBE        L_0ea2
	MOV        word ptr DS:[5878h],0ffffh
L_0ea2:
	MOV        AL,byte ptr [BX + 7h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -10h]
	JNC        L_0eb2
	MOV        word ptr DS:[5878h],1h
L_0eb2:
	TEST       byte ptr [BX + 2h],2h
	JZ         L_0ecc
	MOV        AX,0ffffh
	IMUL       word ptr DS:[5876h]
	MOV        DS:[5876h],AX
	MOV        AX,0ffffh
	IMUL       word ptr DS:[5878h]
	MOV        DS:[5878h],AX
L_0ecc:
	MOV        AX,word ptr [BP + 4h]
	CMP        word ptr [BP + -14h],AX
	JNZ        L_0ed9
	MOV        word ptr [BP + -14h],0ffffh
L_0ed9:
	MOV        AX,word ptr [BP + -14h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0d30 ENDP
F_0ee4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	MOV        word ptr [BP + -4h],0h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	CMP        byte ptr [BX + 3h],1bh
	JNZ        L_0f0e
	JMP        L_110e
L_0f0e:
	CMP        byte ptr [BX + 3h],1ah
	JNZ        L_0f17
	JMP        L_110e
L_0f17:
	TEST       byte ptr [BX + 2h],80h
	JZ         L_0f20
	JMP        L_0fab
L_0f20:
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],2000h
	JZ         L_0fab
	CMP        byte ptr DS:[587ah],4eh
	JZ         L_0fab
	CMP        byte ptr DS:[587ah],1ch
	JZ         L_0fab
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_dc1e
	OR         AX,AX
	JNZ        L_0f53
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_981e
	CMP        AX,3h
	JZ         L_0fab
L_0f53:
	CALL       F_120e
	OR         AX,AX
	JZ         L_0fab
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ah]
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       F_0000
	OR         AX,AX
	JZ         L_0fab
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,DS:[5876h]
	MOV        byte ptr [BX + 6h],AL
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AL,DS:[5878h]
	MOV        byte ptr [BX + 7h],AL
	MOV        byte ptr [SI + 5c5dh],AL
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1856h]
	CALL       SUB_0000_75c0
	MOV        AX,6f0ch
	PUSH       AX
	CALL       SUB_0000_75c0
	INC        word ptr [BP + -6h]
L_0fab:
	CMP        word ptr [BP + -6h],0h
	JZ         L_0fb4
	JMP        L_110e
L_0fb4:
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_dc1e
	OR         AX,AX
	JZ         L_0fc1
	JMP        L_110e
L_0fc1:
	PUSH       word ptr [BP + 4h]
	CALL       F_0d30
	MOV        word ptr [BP + -8h],AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_981e
	CMP        AX,7fh
	JLE        L_1000
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	PUSH       AX
	MOV        AL,byte ptr [BX + 7h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_dc12
	OR         AX,AX
	JNZ        L_1000
	MOV        word ptr DS:[5878h],0h
	MOV        word ptr [BP + -4h],3e7h
	JMP        L_1026
L_1000:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [BX + 7h]
	ADD        AX,word ptr DS:[5878h]
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_dc12
	OR         AX,AX
	JNZ        L_1026
	MOV        word ptr DS:[5876h],0h
	MOV        word ptr [BP + -4h],3e6h
L_1026:
	CMP        word ptr [BP + -4h],3deh
	JL         L_1030
	JMP        L_10c7
L_1030:
	SUB        SI,SI
	MOV        DI,4h
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 7h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,byte ptr [BX + 6h]
	MOV        word ptr [BP + -0ch],AX
L_1046:
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_981e
	MOV        SI,AX
	OR         AX,AX
	JZ         L_1064
	CMP        AX,1h
	JZ         L_1096
	CMP        AX,2h
	JZ         L_10a4
	CMP        AX,3h
	JZ         L_10ac
	JMP        L_1070
L_1064:
	MOV        word ptr DS:[5878h],1h
L_106a:
	MOV        word ptr DS:[5876h],0h
L_1070:
	MOV        AX,word ptr [BP + -0ch]
	ADD        AX,word ptr DS:[5876h]
	PUSH       AX
	MOV        AX,word ptr [BP + -0ah]
	ADD        AX,word ptr DS:[5878h]
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_dc12
	OR         AX,AX
	JNZ        L_108d
	MOV        SI,3dfh
L_108d:
	CMP        SI,3deh
	JLE        L_10b4
	JMP        L_10c1
	db 90h
L_1096:
	MOV        word ptr DS:[5876h],1h
L_109c:
	MOV        word ptr DS:[5878h],0h
	JMP        L_1070
L_10a4:
	MOV        word ptr DS:[5878h],0ffffh
	JMP        L_106a
L_10ac:
	MOV        word ptr DS:[5876h],0ffffh
	JMP        L_109c
L_10b4:
	SUB        AX,AX
	MOV        DS:[5878h],AX
	MOV        DS:[5876h],AX
	DEC        DI
	OR         DI,DI
	JG         L_1046
L_10c1:
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -4h],SI
L_10c7:
	CMP        word ptr [BP + -4h],0h
	JZ         L_110e
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,DS:[5876h]
	ADD        byte ptr [BX + 6h],AL
	MOV        AL,byte ptr [BX + 6h]
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AL,DS:[5878h]
	ADD        byte ptr [BX + 7h],AL
	MOV        AL,byte ptr [BX + 7h]
	MOV        byte ptr [SI + 5c5dh],AL
	MOV        word ptr [BP + -6h],1h
	MOV        AL,byte ptr [BX + 6h]
	PUSH       AX
	MOV        AL,byte ptr [BX + 7h]
	PUSH       AX
	CALL       SUB_0000_caf2
	OR         AX,AX
	JNZ        L_110e
	MOV        byte ptr DS:[58a2h],10h
L_110e:
	MOV        AX,word ptr [BP + -6h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0ee4 ENDP
F_111a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0eh],0h
	TEST       byte ptr DS:[58a1h],80h
	JNZ        L_1138
	TEST       byte ptr DS:[58a1h],2h
	JNZ        L_1138
	JMP        L_1202
L_1138:
	MOV        SI,0ae1fh
	MOV        DI,0ae27h
	MOV        word ptr [BP + -10h],0ad1fh
	MOV        word ptr [BP + -4h],0ae3fh
	MOV        word ptr [BP + -8h],0ae47h
	MOV        word ptr [BP + -6h],0ae5fh
	MOV        word ptr [BP + -0ah],0ae67h
	MOV        word ptr [BP + -0ch],8h
	MOV        DX,8h
L_115f:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_11dc
	MOV        AL,byte ptr [DI]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_11dc
	MOV        AL,0ffh
	MOV        byte ptr [DI],AL
	MOV        byte ptr [SI],AL
	MOV        BX,word ptr [BP + -4h]
	CMP        byte ptr [BX],0bh
	JNC        L_11a6
	MOV        BX,word ptr [BP + -8h]
	CMP        byte ptr [BX],0bh
	JNC        L_11a6
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX]
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,byte ptr [BX]
	SUB        CH,CH
	MOV        BX,word ptr [BP + -8h]
	MOV        BL,byte ptr [BX]
	SUB        BH,BH
	MOV        word ptr [BP + -16h],CX
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + -16h]
	MOV        byte ptr [BX + 0ad14h],AL
L_11a6:
	MOV        BX,word ptr [BP + -6h]
	CMP        byte ptr [BX],0bh
	JNC        L_11d7
	MOV        BX,word ptr [BP + -0ah]
	CMP        byte ptr [BX],0bh
	JNC        L_11d7
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX]
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,byte ptr [BX]
	SUB        CH,CH
	MOV        BX,word ptr [BP + -0ah]
	MOV        BL,byte ptr [BX]
	SUB        BH,BH
	MOV        word ptr [BP + -16h],CX
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + -16h]
	MOV        byte ptr [BX + 0ad14h],AL
L_11d7:
	MOV        word ptr [BP + -0eh],1h
L_11dc:
	INC        SI
	INC        DI
	INC        word ptr [BP + -10h]
	INC        word ptr [BP + -4h]
	INC        word ptr [BP + -8h]
	INC        word ptr [BP + -6h]
	INC        word ptr [BP + -0ah]
	DEC        DX
	JZ         L_11f3
	JMP        L_115f
L_11f3:
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -12h],SI
	CMP        word ptr [BP + -0eh],0h
	JZ         L_1202
	CALL       SUB_0000_b680
L_1202:
	MOV        AX,word ptr [BP + -0eh]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_111a ENDP
F_120e PROC NEAR
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_981e
	MOV        DS:[5876h],AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_981e
	MOV        DS:[5878h],AX
	CMP        word ptr DS:[5876h],0ah
	JG         L_122e
	CMP        AX,0ah
	JLE        L_1232
L_122e:
	SUB        AX,AX
	JMP        L_1235
L_1232:
	MOV        AX,1h
L_1235:
	RET
	; Func
F_120e ENDP
F_1236 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	CMP        word ptr [BP + 4h],0h
	JGE        L_1280
	MOV        AX,0ffffh
	IMUL       word ptr [BP + 4h]
	MOV        word ptr [BP + 4h],AX
	DEC        word ptr [BP + 4h]
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        SI,BX
	SUB        AL,AL
	MOV        byte ptr [SI + 4h],AL
	MOV        byte ptr [BX + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr [SI + 7h],AL
	MOV        byte ptr [BX + 6h],AL
	MOV        byte ptr [BX + 5h],AL
	MOV        byte ptr [BX + 2h],AL
	JMP        L_1287
L_1280:
	MOV        AX,word ptr [BP + 4h]
	DEC        AX
	MOV        word ptr [BP + -4h],AX
L_1287:
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        SI,CL
	SUB        AL,AL
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        byte ptr [SI + 5c5fh],AL
	MOV        byte ptr [SI + 5c5eh],AL
	MOV        byte ptr [SI + 5c5dh],AL
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_1236 ENDP
F_12b0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],40h
	JZ         L_12d8
	MOV        BL,byte ptr [SI + 0ba17h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13c0h]
	SUB        AH,AH
L_12d3:
	MOV        word ptr [BP + -6h],AX
	JMP        L_1323
L_12d8:
	MOV        AL,DS:[589dh]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX
	CMP        AX,27h
	JZ         L_130e
	CMP        AX,28h
	JZ         L_1338
	CMP        AX,0ffh
	JZ         L_1330
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 15fch]
	MOV        word ptr [BP + -6h],AX
	CMP        AX,1h
	JLE        L_1323
	CMP        AX,63h
	JZ         L_1323
	MOV        AX,1h
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	CALL       SUB_0000_7e02
	JMP        L_12d3
L_130e:
	MOV        AX,6f1ah
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + -6h]
	CALL       SUB_0000_cbd0
	MOV        word ptr [BP + -6h],63h
L_1323:
	CMP        word ptr [BP + -6h],63h
	JNZ        L_1340
	MOV        word ptr [BP + -4h],63h
	JMP        L_138f
L_1330:
	MOV        word ptr [BP + -6h],1h
	JMP        L_1323
	db 90h
L_1338:
	MOV        word ptr [BP + -6h],0h
	JMP        L_1323
	db 90h
L_1340:
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],40h
	JZ         L_135c
	MOV        BL,byte ptr [SI + 0ba17h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13bfh]
	JMP        L_1371
L_135c:
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba17h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55c0h]
L_1371:
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	MOV        AX,word ptr [BP + -6h]
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + -2h],0h
	JZ         L_138f
	MOV        AX,1h
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_7e02
	SUB        word ptr [BP + -4h],AX
L_138f:
	MOV        AX,word ptr [BP + -4h]
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_12b0 ENDP
F_139a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        byte ptr DS:[587ah],54h
	JNZ        L_13b8
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],40h
	JZ         L_13b8
L_13b2:
	MOV        AX,1h
	JMP        L_13dd
	db 90h
L_13b8:
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 0ba17h],1ah
	JZ         L_13b2
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],8h
	JNZ        L_13b2
	MOV        BX,word ptr [BP + 4h]
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba15h]
	SUB        AH,AH
L_13dd:
	POP        BP
	RET        2h
	db 90h
	; Func
F_139a ENDP
F_13e2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	TEST       byte ptr [BX + 2h],40h
	JZ         L_1418
	CMP        word ptr [BP + 4h],0h
	JNZ        L_142d
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],80h
	JZ         L_1428
L_1411:
	MOV        word ptr [BP + 4h],0fffdh
	JMP        L_142d
L_1418:
	CMP        word ptr [BP + 4h],0h
	JLE        L_142d
	MOV        BX,word ptr [BP + 4h]
	CMP        byte ptr [BX + 169ch],8h
	JZ         L_1411
L_1428:
	MOV        word ptr [BP + 4h],0fffeh
L_142d:
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,0fffch
	JZ         L_14aa
	CMP        AX,0fffdh
	JZ         L_1480
	CMP        AX,0fffeh
	JZ         L_1478
	CMP        AX,0ffffh
	JNZ        L_1473
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],40h
	JZ         L_145e
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13beh]
	JMP        L_146e
	db 90h
	db 90h
L_145e:
	MOV        BX,word ptr [BP + -2h]
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b6h]
L_146e:
	SUB        AH,AH
L_1470:
	MOV        word ptr [BP + -4h],AX
L_1473:
	MOV        AX,word ptr [BP + -4h]
	JMP        L_14d0
L_1478:
	PUSH       word ptr [BP + 6h]
	CALL       F_139a
	JMP        L_1470
L_1480:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],40h
	JZ         L_1498
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13bch]
	JMP        L_146e
L_1498:
	MOV        BX,word ptr [BP + -2h]
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b4h]
	JMP        L_146e
L_14aa:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],40h
	JZ         L_14c2
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13bfh]
	JMP        L_146e
L_14c2:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_cb18
	JMP        L_1470
L_14d0:
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_13e2 ENDP
F_14d6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	MOV        word ptr [BP + -8h],0ffffh
	MOV        word ptr [BP + -4h],0h
	CMP        byte ptr DS:[588fh],0h
	JZ         L_1512
	CMP        word ptr [BP + 4h],29h
	JLE        L_14f9
	CMP        word ptr [BP + 4h],32h
	JL         L_14ff
L_14f9:
	CMP        word ptr [BP + 4h],33h
	JNZ        L_1506
L_14ff:
	MOV        word ptr [BP + -4h],1h
	JMP        L_152f
L_1506:
	MOV        AX,0ffffh
	MOV        word ptr [BP + -8h],AX
	MOV        word ptr [BP + -6h],AX
	JMP        L_152f
	db 90h
L_1512:
	CMP        word ptr [BP + 4h],27h
	JZ         L_14ff
	CMP        word ptr [BP + 4h],23h
	JZ         L_14ff
	CMP        word ptr [BP + 4h],28h
	JZ         L_14ff
	MOV        word ptr [BP + -6h],0fffeh
	MOV        AX,word ptr [BP + 4h]
	MOV        word ptr [BP + -8h],AX
L_152f:
	CMP        word ptr [BP + -4h],0h
	JNZ        L_156b
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + -6h]
	CALL       F_13e2
	MOV        word ptr [BP + -6h],AX
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + -8h]
	CALL       F_13e2
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [BP + -6h]
	SUB        AX,word ptr [BP + -8h]
	ADD        AX,1eh
	CWD
	SUB        AX,DX
	SAR        AX,1h
	MOV        word ptr [BP + -2h],AX
	CALL       SUB_0000_982e
	CMP        AX,word ptr [BP + -2h]
	JL         L_156b
	MOV        word ptr [BP + -4h],1h
L_156b:
	MOV        AX,word ptr [BP + -4h]
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_14d6 ENDP
F_1574 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	MOV        word ptr [BP + -4h],0h
	MOV        word ptr [BP + -2h],0ffffh
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -8h],AX
	CMP        word ptr [BP + 4h],1h
	JGE        L_15a8
	MOV        byte ptr DS:[58a2h],20h
	MOV        word ptr [BP + 4h],0h
L_15a8:
	MOV        BX,word ptr [BP + -8h]
	TEST       byte ptr [BX + 2h],80h
	JZ         L_1610
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,5h
	SHL        SI,CL
	ADD        SI,55b8h
	MOV        AX,word ptr [BP + 4h]
	SUB        word ptr [SI],AX
	CMP        word ptr [SI],1h
	JL         L_15cf
	CMP        AX,63h
	JNZ        L_1609
L_15cf:
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,5h
	SHL        SI,CL
	MOV        word ptr [SI + 55b8h],0h
	OR         byte ptr [BX + 2h],20h
	MOV        byte ptr [SI + 55b3h],44h
	MOV        AL,byte ptr [BX + 4h]
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,1eh
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AL,DS:[587bh]
	CMP        byte ptr [BX + 3h],AL
	JNZ        L_1609
	MOV        byte ptr DS:[587bh],0ffh
L_1609:
	CALL       SUB_0000_8670
	JMP        L_18ae
	db 90h
L_1610:
	MOV        BX,word ptr [BP + -8h]
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],20h
	JZ         L_1634
	CMP        byte ptr DS:[5890h],0h
	JNZ        L_1634
	MOV        CX,2h
	MOV        AX,word ptr [BP + 4h]
	CWD
	IDIV       CX
	MOV        word ptr [BP + 4h],AX
L_1634:
	MOV        BX,word ptr [BP + -8h]
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],8h
	JZ         L_164a
	MOV        word ptr [BP + 4h],0h
L_164a:
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 4h]
	JNC        L_165a
	MOV        byte ptr [BX],AH
	JMP        L_165f
L_165a:
	MOV        AL,byte ptr [BP + 4h]
	SUB        byte ptr [BX],AL
L_165f:
	CMP        byte ptr [BX],0h
	JZ         L_166d
	CMP        word ptr [BP + 4h],63h
	JZ         L_166d
	JMP        L_17f6
L_166d:
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        DI,SI
	MOV        CL,3h
	SHL        DI,CL
	MOV        AL,byte ptr [DI + 13c1h]
	SHR        AX,1h
	SHR        AX,1h
	INC        AX
	MOV        word ptr [BP + -6h],AX
	MOV        AL,byte ptr [DI + 13c3h]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        byte ptr [BX + 2h],20h
	MOV        byte ptr [BX],AH
	MOV        AL,byte ptr [BX + 6h]
	MOV        word ptr [BP + -0eh],AX
	MOV        AL,byte ptr [BX + 7h]
	MOV        word ptr [BP + -10h],AX
	MOV        BX,AX
	MOV        CL,5h
	SHL        BX,CL
	ADD        BX,word ptr [BP + -0eh]
	MOV        AL,byte ptr [BX + 0ad14h]
	MOV        word ptr [BP + -0ch],AX
	MOV        BX,SI
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],1001h
	JZ         L_16c0
	JMP        L_1782
L_16c0:
	MOV        BX,word ptr [BP + -8h]
	CMP        byte ptr [BX + 3h],1ch
	JNZ        L_16f8
	MOV        AL,byte ptr [BX + 4h]
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,1fh
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AX,1fh
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -10h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_c276
	CALL       SUB_0000_b680
	JMP        L_18ae
L_16f8:
	MOV        BX,word ptr [BP + -8h]
	CMP        byte ptr [BX + 3h],1eh
	JNZ        L_1712
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -10h]
	CALL       SUB_0000_a172
	MOV        BX,AX
	MOV        byte ptr [BX],4ch
	JMP        L_171f
	db 90h
L_1712:
	CMP        word ptr [BP + -0ch],87h
	JZ         L_171f
	CMP        word ptr [BP + -0ch],4h
	JGE        L_172c
L_171f:
	MOV        AX,word ptr [BP + 6h]
	NEG        AX
	DEC        AX
L_1725:
	PUSH       AX
	CALL       F_1236
	JMP        L_18ae
L_172c:
	CALL       SUB_0000_982e
	CMP        AX,word ptr [BP + -4h]
	JG         L_1766
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,1h
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AL,byte ptr [BP + -4h]
	MOV        byte ptr [SI + 5c5fh],AL
	CALL       SUB_0000_982e
	CMP        AX,word ptr [BP + -4h]
	JL         L_175e
	JMP        L_18ae
L_175e:
	OR         byte ptr [SI + 5c5fh],80h
	JMP        L_18ae
L_1766:
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,1fh
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	JMP        L_18ae
	db 90h
L_1782:
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	MOV        SI,AX
	SHL        SI,1h
	TEST       word ptr [SI + 153ch],1000h
	JZ         L_17ec
	PUSH       word ptr [SI + 1856h]
	CALL       SUB_0000_75c0
	MOV        AX,6f36h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        byte ptr DS:[58a2h],2h
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,16h
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AL,byte ptr [BX + 6h]
	MOV        SI,AX
	MOV        AL,byte ptr [BX + 7h]
	MOV        DI,AX
	MOV        BX,DI
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 0ad14h]
	PUSH       AX
	PUSH       SI
	PUSH       DI
	CALL       SUB_0000_6dd8
	MOV        AX,word ptr [BP + 6h]
	INC        AX
	NEG        AX
	PUSH       AX
	CALL       F_1236
	CALL       SUB_0000_dbee
	JMP        L_18ae
	db 90h
L_17ec:
	MOV        AX,word ptr [BP + 6h]
	INC        AX
	NEG        AX
	JMP        L_1725
	db 90h
L_17f6:
	MOV        BX,word ptr [BP + -8h]
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       byte ptr [BX + 153ch],10h
	JNZ        L_180a
	JMP        L_18ae
L_180a:
	MOV        word ptr [BP + -0ah],0h
	MOV        DI,word ptr [BP + -2h]
	MOV        SI,word ptr [BP + -8h]
L_1815:
	MOV        AL,byte ptr [SI + 6h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,byte ptr [SI + 7h]
	PUSH       AX
	CALL       SUB_0000_dc4e
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -10h],AX
	MOV        BL,byte ptr [SI + 4h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -10h]
	CALL       F_0000
	OR         AX,AX
	JZ         L_18a2
	MOV        BL,byte ptr [SI + 4h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	SUB        AH,AH
	SUB        AX,40h
	SHR        AX,1h
	SHR        AX,1h
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -10h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_c276
	MOV        DI,AX
	CMP        DI,-1h
	JLE        L_18a2
	MOV        BX,DI
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [SI]
	MOV        byte ptr [BX + 0ba14h],AL
	MOV        BL,byte ptr [SI + 3h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1856h]
	CALL       SUB_0000_75c0
	MOV        AX,6f42h
	PUSH       AX
	CALL       SUB_0000_75c0
L_189c:
	MOV        word ptr [BP + -2h],DI
	JMP        L_18ae
	db 90h
L_18a2:
	INC        word ptr [BP + -0ah]
	CMP        word ptr [BP + -0ah],8h
	JGE        L_189c
	JMP        L_1815
L_18ae:
	MOV        AX,word ptr [BP + -6h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_1574 ENDP
F_18ba PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_1904
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        CL,5h
	SHL        DI,CL
	CMP        byte ptr [DI + 55b3h],47h
	JNZ        L_1904
	MOV        byte ptr [DI + 55b3h],50h
	MOV        AX,DI
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,6f4eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        byte ptr DS:[58a2h],8h
	MOV        byte ptr DS:[0a9fah],1h
	JMP        L_1941
L_1904:
	PUSH       word ptr [BP + 6h]
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_981e
	PUSH       AX
	CALL       F_1574
	MOV        word ptr [BP + -2h],AX
	CMP        word ptr [BP + 4h],-1h
	JLE        L_1941
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_1941
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55bch
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_9c84
L_1941:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_18ba ENDP
F_194a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        word ptr [BP + -4h],0h
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JNZ        L_1969
	MOV        word ptr [BP + -4h],1h
L_1969:
	CMP        word ptr [BP + -4h],0h
	JZ         L_19a0
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba17h]
	SUB        BH,BH
	SHL        BX,1h
	TEST       word ptr [BX + 153ch],204h
	JZ         L_19a0
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_7e02
	OR         AX,AX
	JZ         L_19a0
L_1994:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       F_18ba
	JMP        L_1a54
L_19a0:
	MOV        word ptr [BP + -2h],0h
	CMP        word ptr [BP + -4h],0h
	JZ         L_19d0
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 0ba17h],1ch
	JNZ        L_19d0
	MOV        BX,word ptr [BP + 6h]
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],8h
	JNZ        L_19d0
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_c61e
	MOV        word ptr [BP + -2h],1h
L_19d0:
	CMP        word ptr [BP + -2h],0h
	JNZ        L_1a54
	CMP        byte ptr DS:[5890h],0h
	JZ         L_19ee
	CMP        byte ptr DS:[589dh],34h
	JNZ        L_19ee
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_c61e
	JMP        L_1a54
	db 90h
	db 90h
L_19ee:
	CMP        byte ptr DS:[5890h],0h
	JZ         L_19fc
	CMP        byte ptr DS:[589dh],33h
	JZ         L_1994
L_19fc:
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + 6h]
	CALL       F_12b0
	MOV        word ptr [BP + -6h],AX
	OR         AX,AX
	JGE        L_1a22
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_1a22
	MOV        byte ptr DS:[58a2h],20h
	JMP        L_1a54
	db 90h
L_1a22:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + -6h]
	CALL       F_1574
	MOV        word ptr [BP + -6h],AX
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_1a54
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55bch
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_9c84
L_1a54:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_194a ENDP
F_1a5c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	MOV        word ptr [BP + -6h],0h
	MOV        word ptr [BP + -4h],0h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	TEST       byte ptr [BX + 2h],80h
	JZ         L_1a84
	JMP        L_1b18
L_1a84:
	MOV        BL,byte ptr [BX + 3h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13c1h]
	SUB        AH,AH
	SHR        AX,1h
	SHR        AX,1h
	MOV        word ptr [BP + -8h],AX
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JNC        L_1ab0
	MOV        word ptr [BP + -4h],1h
L_1aa9:
	MOV        word ptr [BP + -6h],1h
	JMP        L_1aff
L_1ab0:
	SHL        word ptr [BP + -8h],1h
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JNC        L_1ad2
	MOV        word ptr [BP + -4h],2h
	MOV        AX,100h
	PUSH       AX
	CALL       SUB_0000_981e
	MOV        word ptr [BP + -8h],AX
	CMP        AX,0fbh
	JLE        L_1aff
	JMP        L_1aa9
L_1ad2:
	MOV        CX,2h
	MOV        AX,word ptr [BP + -8h]
	CWD
	IDIV       CX
	MOV        word ptr [BP + -8h],AX
	MOV        AX,3h
	IMUL       word ptr [BP + -8h]
	MOV        word ptr [BP + -8h],AX
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JNC        L_1afa
	MOV        word ptr [BP + -4h],3h
	JMP        L_1aff
L_1afa:
	MOV        word ptr [BP + -4h],4h
L_1aff:
	CMP        word ptr [BP + -6h],0h
	JZ         L_1b0e
	MOV        BX,word ptr [BP + -2h]
	OR         byte ptr [BX + 2h],2h
	JMP        L_1b15
L_1b0e:
	MOV        BX,word ptr [BP + -2h]
	AND        byte ptr [BX + 2h],0fdh
L_1b15:
	MOV        AX,word ptr [BP + -4h]
L_1b18:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_1a5c ENDP
F_1b1e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -4h],AX
	MOV        BX,AX
	MOV        BL,byte ptr [BX + 6h]
	SUB        BH,BH
	MOV        SI,AX
	MOV        SI,word ptr [SI + 7h]
	AND        SI,0ffh
	MOV        CL,5h
	SHL        SI,CL
	MOV        AL,byte ptr [BX + SI + 0ad14h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	CMP        AX,8fh
	JZ         L_1b5f
	CMP        AX,0bch
	JNZ        L_1b64
L_1b5f:
	MOV        word ptr [BP + -8h],64h
L_1b64:
	CMP        word ptr [BP + -2h],4h
	JNZ        L_1b6f
	MOV        word ptr [BP + -8h],32h
L_1b6f:
	CMP        word ptr [BP + -8h],0h
	JNZ        L_1bdd
	SUB        DX,DX
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX
	MOV        SI,5c5ch
	MOV        DI,5c5dh
	MOV        word ptr [BP + -10h],5c5ah
	MOV        word ptr [BP + -12h],5c5ah
	MOV        word ptr [BP + -14h],5c5ah
	MOV        CX,word ptr [BP + -8h]
L_1b9a:
	MOV        AX,DX
	CMP        AX,word ptr [BP + -0ah]
	JZ         L_1bf2
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [SI]
	CMP        byte ptr [BX + 6h],AL
	JNZ        L_1bf2
	MOV        AL,byte ptr [DI]
	CMP        byte ptr [BX + 7h],AL
	JNZ        L_1bf2
	MOV        BX,word ptr [BP + -10h]
	CMP        byte ptr [BX],0eah
	JNZ        L_1bbd
	MOV        CX,64h
L_1bbd:
	MOV        BX,word ptr [BP + -12h]
	CMP        byte ptr [BX],0e8h
	JNZ        L_1bc8
	MOV        CX,32h
L_1bc8:
	MOV        BX,word ptr [BP + -14h]
	CMP        byte ptr [BX],0e9h
	JNZ        L_1bd3
	MOV        CX,96h
L_1bd3:
	OR         CX,CX
	JZ         L_1bf2
L_1bd7:
	MOV        word ptr [BP + -6h],DX
	MOV        word ptr [BP + -8h],CX
L_1bdd:
	MOV        AX,word ptr [BP + -8h]
	CMP        AX,32h
	JZ         L_1c3a
	CMP        AX,64h
	JZ         L_1c14
	CMP        AX,96h
	JZ         L_1c0c
	JMP        L_1c5d
	db 90h
L_1bf2:
	ADD        SI,8h
	ADD        DI,8h
	ADD        word ptr [BP + -10h],8h
	ADD        word ptr [BP + -12h],8h
	ADD        word ptr [BP + -14h],8h
	INC        DX
	CMP        DX,20h
	JGE        L_1bd7
	JMP        L_1b9a
L_1c0c:
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_c61e
	JMP        L_1c5d
L_1c14:
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_92d4
	PUSH       word ptr [BP + 4h]
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_981e
	PUSH       AX
	CALL       F_1574
	PUSH       word ptr [BP + 4h]
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_db22
	MOV        byte ptr DS:[0a9fah],1h
	JMP        L_1c5d
	db 90h
L_1c3a:
	MOV        BX,word ptr [BP + -4h]
	MOV        BL,byte ptr [BX + 4h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 5c5ah],80h
	JNC        L_1c5d
	PUSH       word ptr [BP + 4h]
	MOV        AX,0ffffh
	PUSH       AX
	CALL       F_18ba
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_92d4
L_1c5d:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_1b1e ENDP
F_1c66 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       DI
	PUSH       SI
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	CALL       SUB_0000_982e
	MOV        CL,byte ptr [SI + 0ba15h]
	SUB        CH,CH
	CMP        CX,AX
	JBE        L_1ce0
	TEST       byte ptr [SI + 0ba16h],80h
	JZ         L_1c96
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	JMP        L_1ca9
L_1c96:
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        BL,byte ptr [BX + 0ba17h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 1856h]
L_1ca9:
	CALL       SUB_0000_75c0
	MOV        AX,6f5eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1b58h
	PUSH       AX
	MOV        AX,258h
	PUSH       AX
	CALL       SUB_0000_7fac
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        SI,CL
	AND        byte ptr [SI + 0ba16h],0fbh
	MOV        AL,byte ptr [SI + 0ba18h]
	SUB        AH,AH
	MOV        DI,AX
	SHL        DI,CL
	MOV        AL,byte ptr [DI + 5c5ah]
	MOV        byte ptr [DI + 5c5bh],AL
L_1ce0:
	POP        SI
	POP        DI
	POP        BP
	RET        2h
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
F_1c66 ENDP
_TEXT ENDS
END
