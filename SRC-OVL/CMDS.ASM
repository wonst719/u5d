_TEXT SEGMENT BYTE 'CODE'
ORG 0bcbeh
SUB_0000_bcbe:
ORG 0a9b6h
SUB_0000_a9b6:
ORG 0a900h
SUB_0000_a900:
ORG 9990h
SUB_0000_9990:
ORG 7b66h
SUB_0000_7b66:
ORG 58d0h
SUB_0000_58d0:
ORG 808ch
SUB_0000_808c:
ORG 6980h
SUB_0000_6980:
ORG 6112h
SUB_0000_6112:
ORG 60d6h
SUB_0000_60d6:
ORG 60feh
SUB_0000_60fe:
ORG 0a880h
SUB_0000_a880:
ORG 0ac42h
SUB_0000_ac42:
ORG 8ffch
SUB_0000_8ffc:
ORG 617ah
SUB_0000_617a:
ORG 8b04h
SUB_0000_8b04:
ORG 0ae02h
SUB_0000_ae02:
ORG 0bdf6h
SUB_0000_bdf6:
ORG 0bfd6h
SUB_0000_bfd6:
ORG 66ech
SUB_0000_66ec:
ORG 573ah
SUB_0000_573a:
ORG 0bb32h
SUB_0000_bb32:
ORG 4af0h
SUB_0000_4af0:
ORG 4b26h
SUB_0000_4b26:
ORG 0bb1ah
SUB_0000_bb1a:
ORG 6b68h
SUB_0000_6b68:
ORG 0bb0eh
SUB_0000_bb0e:
ORG 770eh
SUB_0000_770e:
ORG 6ccch
SUB_0000_6ccc:
ORG 0bb9eh
SUB_0000_bb9e:
ORG 7af4h
SUB_0000_7af4:
ORG 766ch
SUB_0000_766c:
ORG 842eh
SUB_0000_842e:
ORG 0bc5eh
SUB_0000_bc5e:
ORG 0bc6ah
SUB_0000_bc6a:
ORG 75a2h
SUB_0000_75a2:
ORG 7a4ch
SUB_0000_7a4c:
ORG 0bb56h
SUB_0000_bb56:
ORG 7782h
SUB_0000_7782:
ORG 8482h
SUB_0000_8482:
ORG 0bb86h
SUB_0000_bb86:
ORG 0bb92h
SUB_0000_bb92:
ORG 6b28h
SUB_0000_6b28:
ORG 6f0eh
SUB_0000_6f0e:
ORG 7964h
SUB_0000_7964:
ORG 0af9eh
SUB_0000_af9e:
ORG 6212h
SUB_0000_6212:
ORG 50e8h
SUB_0000_50e8:
ORG 7b9ch
SUB_0000_7b9c:
ORG 70f2h
SUB_0000_70f2:
ORG 0bf3ah
SUB_0000_bf3a:
ORG 0be02h
SUB_0000_be02:
ORG 5c14h
SUB_0000_5c14:
ORG 5ca2h
SUB_0000_5ca2:
ORG 8f7ch
SUB_0000_8f7c:
ORG 8ed0h
SUB_0000_8ed0:
ORG 5abeh
SUB_0000_5abe:
ORG 6aa8h
SUB_0000_6aa8:
ORG 5c72h
SUB_0000_5c72:
ORG 7c1eh
SUB_0000_7c1e:
ORG 0c10eh
SUB_0000_c10e:
ORG 7a7ch
SUB_0000_7a7c:
ORG 7050h
SUB_0000_7050:
ORG 8ea0h
SUB_0000_8ea0:
ORG 8fbch
SUB_0000_8fbc:
ORG 6ad2h
SUB_0000_6ad2:
ORG 0bc46h
SUB_0000_bc46:
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
	PUSH       BP
	MOV        BP,SP
	SUB        SP,3ch
	PUSH       DI
	PUSH       SI
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	MOV        word ptr [BP + -1eh],AX
	MOV        word ptr [BP + -4h],0ffffh
	MOV        word ptr [BP + -1ch],0ffffh
	SUB        AL,AL
	MOV        DS:[588eh],AL
	MOV        DS:[587ah],AL
	MOV        AL,DS:[587bh]
	MOV        byte ptr [BP + -1ah],AL
	MOV        byte ptr DS:[587bh],0ffh
	TEST       byte ptr [BP + 8h],2h
	JZ         L_005e
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_bcbe
	JMP        L_0061
	db 90h
L_005e:
	CALL       SUB_0000_a9b6
L_0061:
	MOV        byte ptr DS:[589eh],0ffh
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,byte ptr DS:[587fh]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -28h],AX
	CMP        AX,17h
	JLE        L_007d
	SUB        word ptr [BP + -28h],18h
L_007d:
	CMP        word ptr [BP + 6h],5h
	JG         L_0089
	CMP        word ptr [BP + 6h],-1h
	JGE        L_008e
L_0089:
	MOV        word ptr [BP + 6h],0ffffh
L_008e:
	MOV        word ptr [BP + -20h],8h
	SUB        AX,AX
	MOV        CX,8h
	LEA        DI,[BP + -14h]
	PUSH       SS
	POP        ES
	REP STOSW
	MOV        word ptr [BP + -20h],AX
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JNZ        L_00ae
	JMP        L_014c
L_00ae:
	MOV        word ptr [BP + -30h],55b3h
	LEA        AX,[BP + -14h]
	MOV        word ptr [BP + -32h],AX
	MOV        word ptr [BP + -34h],55b2h
L_00be:
	SUB        CX,CX
	MOV        SI,0ba17h
	MOV        DI,0ba14h
	MOV        DX,word ptr [BP + -18h]
L_00c9:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	CMP        word ptr [BP + -20h],AX
	JNZ        L_00f2
	MOV        DX,DI
L_00d4:
	MOV        word ptr [BP + -18h],DX
	MOV        word ptr [BP + -24h],CX
	MOV        BX,word ptr [BP + -30h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,47h
	JZ         L_0105
	CMP        AX,50h
	JZ         L_0100
	CMP        AX,53h
	JZ         L_0105
	JMP        L_0130
L_00f2:
	ADD        SI,8h
	ADD        DI,8h
	INC        CX
	CMP        CX,20h
	JGE        L_00d4
	JMP        L_00c9
L_0100:
	MOV        BX,word ptr [BP + -32h]
	INC        word ptr [BX]
L_0105:
	MOV        AX,word ptr [BP + 6h]
	CMP        word ptr [BP + -20h],AX
	JZ         L_0113
	PUSH       word ptr [BP + -24h]
	CALL       SUB_0000_a900
L_0113:
	MOV        BX,word ptr [BP + -34h]
	CMP        byte ptr [BX],42h
	JNZ        L_0130
	MOV        AX,word ptr [BP + 6h]
	CMP        word ptr [BP + -20h],AX
	JNZ        L_0130
	CMP        byte ptr DS:[0a9ceh],0h
	JZ         L_0130
	MOV        AX,word ptr [BP + -24h]
	MOV        word ptr [BP + -4h],AX
L_0130:
	ADD        word ptr [BP + -30h],20h
	ADD        word ptr [BP + -32h],2h
	ADD        word ptr [BP + -34h],20h
	INC        word ptr [BP + -20h]
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	CMP        word ptr [BP + -20h],AX
	JNC        L_014c
	JMP        L_00be
L_014c:
	CALL       SUB_0000_9990
	CMP        word ptr [BP + -4h],-1h
	JZ         L_01b0
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba18h]
	SUB        AH,AH
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        byte ptr [BP + -34h],AL
	MOV        byte ptr [BP + -26h],AL
	MOV        AL,byte ptr [BX + 1h]
	MOV        byte ptr [BP + -2ah],AL
	MOV        DI,BX
	MOV        AL,5fh
	MOV        byte ptr [DI + 1h],AL
	MOV        byte ptr [BX],AL
	MOV        byte ptr DS:[6a08h],1h
	MOV        AX,34h
	PUSH       AX
	CALL       SUB_0000_7b66
	MOV        BX,DI
	MOV        AL,byte ptr [BP + -26h]
	MOV        byte ptr [BX],AL
	MOV        AL,byte ptr [BP + -2ah]
	MOV        byte ptr [BX + 1h],AL
	MOV        AL,byte ptr [SI + 0ba17h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JZ         L_01ad
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_a900
L_01ad:
	CALL       SUB_0000_9990
L_01b0:
	MOV        AX,41d4h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        word ptr [BP + 6h],-1h
	JZ         L_01ee
	SUB        CX,CX
	MOV        SI,0ba17h
	MOV        DI,0ba14h
	MOV        DX,word ptr [BP + -18h]
L_01c8:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JZ         L_01d4
	JMP        L_025c
L_01d4:
	MOV        DX,DI
L_01d6:
	MOV        word ptr [BP + -18h],DX
	MOV        word ptr [BP + -24h],CX
	MOV        BX,DX
	MOV        BL,byte ptr [BX + 4h]
	SUB        BH,BH
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	MOV        byte ptr [BP + -16h],AL
L_01ee:
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	CMP        word ptr [BP + -28h],AX
	JNZ        L_01fb
	JMP        L_02fd
L_01fb:
	CMP        AL,18h
	JC         L_0204
	SUB        byte ptr DS:[587fh],18h
L_0204:
	CALL       SUB_0000_9990
	CALL       SUB_0000_808c
	CALL       SUB_0000_6980
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	CMP        word ptr [BP + -1eh],AX
	JNZ        L_021a
	JMP        L_030c
L_021a:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JZ         L_022b
	JMP        L_030c
L_022b:
	CALL       SUB_0000_60d6
	PUSH       AX
	CALL       SUB_0000_60fe
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 1734h]
	SUB        AH,AH
	MOV        word ptr [BP + -1ch],AX
	MOV        AX,41e0h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        word ptr [BP + 6h],-1h
	JLE        L_02be
	MOV        word ptr [BP + -22h],0h
	JMP        L_027d
	db 90h
L_025c:
	ADD        SI,8h
	ADD        DI,8h
	INC        CX
	CMP        CX,20h
	JL         L_026b
	JMP        L_01d6
L_026b:
	JMP        L_01c8
L_026e:
	MOV        BX,word ptr [BP + -20h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],47h
L_027a:
	INC        word ptr [BP + -22h]
L_027d:
	CMP        word ptr [BP + -22h],6h
	JGE        L_02be
	MOV        BX,word ptr [BP + -22h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba17h]
	SUB        AH,AH
	MOV        word ptr [BP + -20h],AX
	OR         AX,AX
	JL         L_027a
	MOV        AL,DS:[585bh]
	CMP        word ptr [BP + -20h],AX
	JNC        L_027a
	PUSH       word ptr [BP + -22h]
	CALL       SUB_0000_a880
	MOV        SI,word ptr [BP + -20h]
	SHL        SI,1h
	CMP        word ptr [BP + SI + -14h],0h
	JZ         L_026e
	MOV        BX,word ptr [BP + -20h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],50h
	JMP        L_027a
L_02be:
	CALL       SUB_0000_6980
	TEST       byte ptr [BP + 8h],2h
	JZ         L_02f4
	MOV        SI,word ptr DS:[5895h]
	AND        SI,0ffh
	MOV        CL,6h
	SHL        SI,CL
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5896h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_bcbe
	JMP        L_02fd
L_02f4:
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + -1ch]
	CALL       SUB_0000_ac42
L_02fd:
	CMP        word ptr [BP + -1ch],-1h
	JG         L_0306
	JMP        L_03ea
L_0306:
	MOV        AX,1h
	JMP        L_0549
L_030c:
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	MOV        word ptr [BP + -1eh],AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_8ffc
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_617a
	CMP        byte ptr DS:[5894h],21h
	JNC        L_0337
	MOV        AL,DS:[5894h]
	MOV        DS:[5893h],AL
	CALL       SUB_0000_8b04
	MOV        byte ptr DS:[5893h],0ffh
L_0337:
	CMP        word ptr [BP + 6h],-1h
	JNZ        L_0340
	JMP        L_01ee
L_0340:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,2h
	JZ         L_0352
	JMP        L_01ee
L_0352:
	MOV        BX,word ptr [BP + -18h]
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	MOV        DS:[5876h],AX
	MOV        AL,byte ptr [BX + 7h]
	MOV        DS:[5878h],AX
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JZ         L_0382
	CMP        AX,1h
	JZ         L_03d8
	CMP        AX,2h
	JZ         L_03de
	CMP        AX,3h
	JZ         L_03e4
	JMP        L_0386
L_0382:
	DEC        word ptr DS:[5878h]
L_0386:
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_ae02
	OR         AX,AX
	JNZ        L_0398
	JMP        L_01ee
L_0398:
	MOV        AL,byte ptr [BP + -16h]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr DS:[5878h]
	CALL       SUB_0000_bdf6
	OR         AX,AX
	JNZ        L_03b0
	JMP        L_01ee
L_03b0:
	MOV        BX,word ptr [BP + -18h]
	MOV        AL,byte ptr [BX + 4h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,DS:[5876h]
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        byte ptr [BX + 6h],AL
	MOV        AL,DS:[5878h]
	MOV        byte ptr [SI + 5c5dh],AL
	MOV        byte ptr [BX + 7h],AL
	CALL       SUB_0000_9990
	JMP        L_01ee
L_03d8:
	INC        word ptr DS:[5878h]
	JMP        L_0386
L_03de:
	INC        word ptr DS:[5876h]
	JMP        L_0386
L_03e4:
	DEC        word ptr DS:[5876h]
	JMP        L_0386
L_03ea:
	CMP        byte ptr DS:[588ch],1h
	JC         L_03f4
	JMP        L_050c
L_03f4:
	CMP        word ptr [BP + 4h],5h
	JG         L_03fd
	JMP        L_050c
L_03fd:
	MOV        AX,41ech
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -20h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JNZ        L_0415
	JMP        L_04e7
L_0415:
	LEA        AX,[BP + -14h]
	MOV        word ptr [BP + -34h],AX
	MOV        word ptr [BP + -32h],55b3h
	MOV        DI,55b8h
	MOV        word ptr [BP + -2eh],55bah
	MOV        word ptr [BP + -2ch],55b2h
	MOV        word ptr [BP + -36h],55b7h
	MOV        word ptr [BP + -38h],55b6h
	MOV        word ptr [BP + -3ah],55b7h
	MOV        word ptr [BP + -3ch],55b6h
	MOV        SI,word ptr [BP + -20h]
L_0444:
	MOV        BX,word ptr [BP + -34h]
	CMP        word ptr [BX],0h
	JNZ        L_04a3
	CMP        byte ptr DS:[588ch],1h
	JNC        L_04a3
	CMP        word ptr [BP + 4h],5h
	JLE        L_04a3
	MOV        BX,word ptr [BP + -32h]
	CMP        byte ptr [BX],44h
	JZ         L_04a3
	CMP        SI,word ptr [BP + 6h]
	JZ         L_04a3
	MOV        AX,1h
	PUSH       AX
	MOV        AX,3fh
	PUSH       AX
	CALL       SUB_0000_6112
	ADD        word ptr [DI],AX
	MOV        BX,word ptr [BP + -2eh]
	MOV        AX,word ptr [BX]
	CMP        word ptr [DI],AX
	JLE        L_047e
	MOV        word ptr [DI],AX
L_047e:
	CMP        SI,word ptr [BP + 6h]
	JZ         L_04a3
	MOV        BX,word ptr [BP + -2ch]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,41h
	JZ         L_0499
	CMP        AX,42h
	JZ         L_04d6
	CMP        AX,4dh
	JNZ        L_04a3
L_0499:
	MOV        BX,word ptr [BP + -38h]
	MOV        AL,byte ptr [BX]
	MOV        BX,word ptr [BP + -36h]
L_04a1:
	MOV        byte ptr [BX],AL
L_04a3:
	ADD        word ptr [BP + -34h],2h
	ADD        word ptr [BP + -32h],20h
	ADD        DI,20h
	db 83h
	db         46h    F
L_04b0:
	SHL        byte ptr [BX + SI],CL
	ADD        word ptr [BP + -2ch],20h
	ADD        word ptr [BP + -36h],20h
	ADD        word ptr [BP + -38h],20h
	ADD        word ptr [BP + -3ah],20h
	ADD        word ptr [BP + -3ch],20h
	INC        SI
	MOV        AX,SI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JNC        L_04e4
	JMP        L_0444
L_04d6:
	MOV        BX,word ptr [BP + -3ch]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	SHR        AX,1h
	MOV        BX,word ptr [BP + -3ah]
	JMP        L_04a1
L_04e4:
	MOV        word ptr [BP + -20h],SI
L_04e7:
	TEST       byte ptr [BP + 8h],82h
	JNZ        L_0505
	SUB        AX,AX
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,19h
	JGE        L_0505
	MOV        AL,DS:[587dh]
	MOV        DS:[588dh],AL
	CALL       SUB_0000_bfd6
L_0505:
	MOV        byte ptr DS:[588ch],0eh
	JMP        L_0513
L_050c:
	MOV        AX,41fbh
	PUSH       AX
	CALL       SUB_0000_58d0
L_0513:
	MOV        word ptr [BP + -20h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_053e
	MOV        DX,AX
	MOV        SI,55b3h
	MOV        CX,word ptr [BP + -20h]
L_0529:
	CMP        byte ptr [SI],53h
	JNZ        L_0531
	MOV        byte ptr [SI],47h
L_0531:
	ADD        SI,20h
	INC        CX
	MOV        AX,CX
	CMP        AX,DX
	JC         L_0529
	MOV        word ptr [BP + -20h],CX
L_053e:
	MOV        AL,byte ptr [BP + -1ah]
	MOV        DS:[587bh],AL
	CALL       SUB_0000_6980
	SUB        AX,AX
L_0549:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_0552 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        AX,4209h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0570
	db 90h
L_0564:
	CMP        byte ptr [BP + -4h],30h
	JC         L_0570
	CMP        byte ptr [BP + -4h],39h
	JBE        L_057a
L_0570:
	CALL       SUB_0000_66ec
	MOV        byte ptr [BP + -4h],AL
	CMP        AL,20h
	JNZ        L_0564
L_057a:
	CMP        byte ptr [BP + -4h],20h
	JNZ        L_0583
	JMP        L_06e8
L_0583:
	CMP        byte ptr [BP + -4h],30h
	JNZ        L_058c
	JMP        L_06e8
L_058c:
	MOV        AL,byte ptr [BP + -4h]
	SUB        AH,AH
	MOV        SI,AX
	PUSH       SI
	CALL       SUB_0000_573a
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	ADD        AX,SI
	SUB        AX,30h
	MOV        word ptr [BP + -6h],AX
	CMP        AX,17h
	JLE        L_05b4
	SUB        word ptr [BP + -6h],17h
L_05b4:
	SUB        SI,SI
L_05b6:
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_bb32
	CALL       SUB_0000_9990
	CMP        byte ptr DS:[65beh],61h
	JNZ        L_05d0
	MOV        word ptr [BP + -8h],SI
	JMP        L_06e8
	db 90h
L_05d0:
	INC        SI
	CMP        SI,10h
	JL         L_05b6
	MOV        word ptr [BP + -8h],SI
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -8h],0h
	MOV        AL,DS:[585bh]
	OR         AX,AX
	JZ         L_060a
	MOV        DX,AX
	MOV        SI,55b3h
	MOV        CX,word ptr [BP + -8h]
L_05f5:
	CMP        byte ptr [SI],47h
	JNZ        L_05fd
	MOV        byte ptr [SI],53h
L_05fd:
	ADD        SI,20h
	INC        CX
	MOV        AX,CX
	CMP        AX,DX
	JC         L_05f5
	MOV        word ptr [BP + -8h],CX
L_060a:
	CALL       SUB_0000_6980
	MOV        AX,421eh
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_4af0
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_4b26
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	MOV        DI,AX
	MOV        SI,word ptr [BP + -6h]
	JMP        L_063b
	db 90h
L_0634:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_617a
L_063b:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[587fh]
	SUB        CH,CH
	CMP        AX,CX
	JZ         L_0692
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_8ffc
	MOV        AX,DI
	MOV        CL,byte ptr DS:[587fh]
	SUB        CH,CH
	CMP        AX,CX
	JZ         L_0667
	CMP        CL,14h
	JZ         L_0664
	CMP        CL,5h
	JNZ        L_0667
L_0664:
	CALL       SUB_0000_bb1a
L_0667:
	MOV        AL,DS:[587fh]
	SUB        AH,AH
	MOV        DI,AX
	CALL       SUB_0000_8b04
	CALL       SUB_0000_6b68
	CALL       SUB_0000_6980
	CALL       SUB_0000_bb0e
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JZ         L_0634
	MOV        SI,0ffffh
L_0692:
	MOV        word ptr [BP + -0ah],DI
	MOV        word ptr [BP + -6h],SI
	CMP        SI,-1h
	JNZ        L_06a4
	MOV        AX,422ah
	PUSH       AX
	CALL       SUB_0000_58d0
L_06a4:
	MOV        word ptr [BP + -8h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_06cf
	MOV        DX,AX
	MOV        SI,55b3h
	MOV        CX,word ptr [BP + -8h]
L_06ba:
	CMP        byte ptr [SI],53h
	JNZ        L_06c2
	MOV        byte ptr [SI],47h
L_06c2:
	ADD        SI,20h
	INC        CX
	MOV        AX,CX
	CMP        AX,DX
	JC         L_06ba
	MOV        word ptr [BP + -8h],CX
L_06cf:
	MOV        AL,byte ptr [BP + -2h]
	MOV        DS:[587bh],AL
	INC        byte ptr DS:[5896h]
	MOV        byte ptr DS:[24e6h],1h
	INC        byte ptr DS:[5c5ch]
	CALL       SUB_0000_6980
	CALL       SUB_0000_9990
L_06e8:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0552 ENDP
F_06ee PROC NEAR
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_0708
	CMP        byte ptr DS:[587ch],1dh
	JZ         L_0708
	MOV        AX,423eh
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	JMP        L_070b
	db 90h
L_0708:
	MOV        AX,1h
L_070b:
	RET
	; Func
F_06ee ENDP
F_070c PROC NEAR
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	CMP        AX,14h
	JC         L_072f
	CMP        AX,15h
	JBE        L_073a
	CMP        AX,1ch
	JC         L_072f
	CMP        AX,1dh
	JBE        L_073a
	CMP        AX,28h
	JC         L_072f
	CMP        AX,2bh
	JBE        L_073a
L_072f:
	MOV        AX,4248h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	JMP        L_073d
L_073a:
	MOV        AX,1h
L_073d:
	RET
	; Func
F_070c ENDP
F_073e PROC NEAR
	MOV        AX,4h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       F_0788
	CMP        AX,1h
	JZ         L_077e
	MOV        AX,6h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       F_0788
	CMP        AX,1h
	JZ         L_077e
	MOV        AX,5h
	PUSH       AX
	MOV        AX,6h
	PUSH       AX
	CALL       F_0788
	CMP        AX,1h
	JZ         L_077e
	MOV        AX,5h
	PUSH       AX
	MOV        AX,4h
	PUSH       AX
	CALL       F_0788
	CMP        AX,1h
	JNZ        L_0784
L_077e:
	MOV        AX,1h
	JMP        L_0786
	db 90h
L_0784:
	SUB        AX,AX
L_0786:
	RET
	db 90h
	; Func
F_073e ENDP
F_0788 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	PUSH       SI
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,5h
	SHL        SI,CL
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,byte ptr [BX + SI + 0ab02h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JZ         L_07b2
	MOV        AX,1ch
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_6ccc
	JMP        L_07ef
L_07b2:
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,4h
	SHL        SI,CL
	MOV        BX,word ptr [BP + 4h]
	MOV        AL,byte ptr [BX + SI + 0ac64h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	CMP        AX,1bh
	JNZ        L_07d0
L_07ca:
	MOV        AX,1h
	JMP        L_07ef
	db 90h
L_07d0:
	AND        word ptr [BP + -2h],0fch
	CMP        word ptr [BP + -2h],1ch
	JZ         L_07ca
	CMP        word ptr [BP + -2h],24h
	JZ         L_07ca
	CMP        word ptr [BP + -2h],10h
	JZ         L_07ca
	CMP        word ptr [BP + -2h],28h
	JZ         L_07ca
	SUB        AX,AX
L_07ef:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0788 ENDP
F_07f6 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	CMP        byte ptr DS:[5893h],20h
	JBE        L_0818
	CMP        byte ptr DS:[5893h],29h
	JNC        L_0818
	MOV        AX,4252h
L_080d:
	PUSH       AX
	CALL       SUB_0000_58d0
L_0811:
	MOV        AX,1h
	JMP        L_095d
	db 90h
L_0818:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_770e
	MOV        byte ptr [BP + -0ah],AL
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -4h],AX
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0feh
	CMP        AL,10h
	JNZ        L_087c
	CMP        byte ptr DS:[5893h],0h
	JZ         L_0862
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_bb9e
	MOV        word ptr [BP + -2h],AX
	CMP        AX,0ffffh
	JZ         L_0862
	MOV        BX,AX
	MOV        CL,4h
	SHL        BX,CL
	CMP        word ptr [BX + 5f68h],0h
	JZ         L_0862
	MOV        AX,425eh
	JMP        L_080d
L_0862:
	CALL       F_06ee
	OR         AX,AX
	JZ         L_0811
	MOV        AX,4266h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,byte ptr [BP + -0ah]
	ADD        AL,2h
L_0875:
	MOV        DS:[587ch],AL
	JMP        L_093e
	db 90h
L_087c:
	CMP        byte ptr [BP + -0ah],1bh
	JNZ        L_0898
	CALL       F_06ee
	OR         AX,AX
	JZ         L_0811
	MOV        AX,426dh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        byte ptr DS:[587ch],14h
	JMP        L_093e
L_0898:
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0fch
	CMP        AL,28h
	JNZ        L_08b8
	CALL       F_06ee
	OR         AX,AX
	JNZ        L_08ab
	JMP        L_0811
L_08ab:
	MOV        AX,4275h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,byte ptr [BP + -0ah]
	JMP        L_0875
	db 90h
L_08b8:
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0fch
	CMP        AL,24h
	JZ         L_08c4
	JMP        L_0954
L_08c4:
	CALL       F_070c
	OR         AX,AX
	JNZ        L_08ce
	JMP        L_0811
L_08ce:
	MOV        AX,427ch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX
	CMP        AX,0ah
	JGE        L_08f1
	MOV        AX,4282h
	PUSH       AX
	CALL       SUB_0000_58d0
L_08f1:
	MOV        AL,byte ptr [BP + -8h]
	MOV        DS:[5c5fh],AL
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c61h]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[587ch]
	AND        AL,0feh
	CMP        AL,14h
	JNZ        L_0914
	INC        byte ptr DS:[57b0h]
L_0914:
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,28h
	JNZ        L_0920
	INC        word ptr [BP + -6h]
L_0920:
	CMP        word ptr [BP + -6h],0h
	JNZ        L_092d
	MOV        AX,42a0h
	PUSH       AX
	CALL       SUB_0000_58d0
L_092d:
	MOV        AL,byte ptr [BP + -0ah]
	MOV        DS:[587ch],AL
	MOV        AL,byte ptr [BP + -6h]
	MOV        DS:[5c61h],AL
	MOV        byte ptr DS:[0a9fah],1h
L_093e:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_7af4
	OR         byte ptr DS:[24e6h],2h
	JMP        L_0811
L_0954:
	MOV        AX,42bfh
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
L_095d:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_07f6 ENDP
F_0962 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,18h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[587ch],20h
	JC         L_0978
	CMP        byte ptr DS:[587ch],27h
	JBE        L_0982
L_0978:
	MOV        AX,42c6h
L_097b:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0ae4
L_0982:
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_098c
	JMP        L_0ae4
L_098c:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -12h],AX
	CMP        word ptr [BP + -0eh],0h
	JNZ        L_09a5
	TEST       byte ptr DS:[587ch],1h
	JZ         L_09b2
L_09a5:
	CMP        word ptr [BP + -0eh],0h
	JZ         L_09b8
	TEST       byte ptr DS:[587ch],1h
	JZ         L_09b8
L_09b2:
	MOV        AX,42cdh
	JMP        L_097b
	db 90h
L_09b8:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -14h],AX
	MOV        AX,3e8h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	CALL       SUB_0000_842e
	MOV        word ptr [BP + -0ch],0h
	MOV        SI,word ptr [BP + -4h]
L_09e0:
	ADD        DI,word ptr [BP + -0eh]
	MOV        AX,word ptr [BP + -12h]
	ADD        word ptr [BP + -14h],AX
	PUSH       DI
	PUSH       word ptr [BP + -14h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_770e
	MOV        word ptr [BP + -0ah],AX
	PUSH       AX
	CALL       SUB_0000_bc5e
	OR         AX,AX
	JNZ        L_0a04
	JMP        L_0aa2
L_0a04:
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0fch
	CMP        AL,0ech
	JNZ        L_0a10
	JMP        L_0aa2
L_0a10:
	MOV        SI,word ptr DS:[5876h]
	MOV        AX,SI
	MOV        CL,3h
	SHL        AX,CL
	MOV        word ptr [BP + -16h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 5c5ch]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	SUB        AX,CX
	ADD        AX,5h
	MOV        word ptr [BP + -6h],AX
	MOV        AL,byte ptr [BX + 5c5dh]
	SUB        AH,AH
	MOV        CL,byte ptr DS:[5897h]
	SUB        AX,CX
	ADD        AX,5h
	MOV        word ptr [BP + -8h],AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_bc6a
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JZ         L_0a9a
	CALL       SUB_0000_9990
	PUSH       DI
	PUSH       word ptr [BP + -14h]
	CALL       SUB_0000_75a2
	MOV        AX,SI
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5fh
	MOV        word ptr [BP + -18h],AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,14h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        BX,word ptr [BP + -18h]
	SUB        byte ptr [BX],AL
	CMP        byte ptr [BX],7fh
	JBE        L_0a9a
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       SI
	CALL       SUB_0000_7af4
	OR         byte ptr DS:[24e6h],2h
L_0a9a:
	MOV        word ptr [BP + -10h],DI
	MOV        word ptr [BP + -4h],SI
	JMP        L_0ae4
L_0aa2:
	INC        word ptr [BP + -0ch]
	CMP        word ptr [BP + -0ch],3h
	JGE        L_0aae
	JMP        L_09e0
L_0aae:
	MOV        word ptr [BP + -10h],DI
	MOV        word ptr [BP + -4h],SI
	MOV        AX,word ptr [BP + -0eh]
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	ADD        AX,5h
	MOV        word ptr [BP + -6h],AX
	MOV        AX,word ptr [BP + -12h]
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	ADD        AX,5h
	MOV        word ptr [BP + -8h],AX
	MOV        AX,5h
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_bc6a
L_0ae4:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0962 ENDP
F_0aea PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1eh
	CMP        byte ptr DS:[5893h],20h
	JBE        L_0b08
	CMP        byte ptr DS:[5893h],29h
	JNC        L_0b08
	MOV        AX,42e4h
L_0b01:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0d94
L_0b08:
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_0b16
	CALL       F_0962
	JMP        L_0d94
	db 90h
L_0b16:
	MOV        AL,DS:[594fh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5950h]
	PUSH       AX
	MOV        AL,DS:[5951h]
	PUSH       AX
	CALL       SUB_0000_7a4c
	MOV        AL,DS:[0ab87h]
	SUB        AH,AH
	MOV        word ptr [BP + -1eh],AX
	AND        AL,0fch
	CMP        AL,0b4h
	JNZ        L_0b42
	MOV        word ptr [BP + -14h],0h
	MOV        word ptr [BP + -1ch],0ffffh
	JMP        L_0b8a
	db 90h
L_0b42:
	MOV        AL,DS:[0aba8h]
	SUB        AH,AH
	MOV        word ptr [BP + -1eh],AX
	AND        AL,0fch
	CMP        AL,0b4h
	JNZ        L_0b58
	MOV        word ptr [BP + -14h],1h
	JMP        L_0b85
	db 90h
L_0b58:
	MOV        AL,DS:[0abc7h]
	SUB        AH,AH
	MOV        word ptr [BP + -1eh],AX
	AND        AL,0fch
	CMP        AL,0b4h
	JNZ        L_0b72
	MOV        word ptr [BP + -14h],0h
	MOV        word ptr [BP + -1ch],1h
	JMP        L_0b8a
L_0b72:
	MOV        AL,DS:[0aba6h]
	SUB        AH,AH
	MOV        word ptr [BP + -1eh],AX
	AND        AL,0fch
	CMP        AL,0b4h
	JNZ        L_0bde
	MOV        word ptr [BP + -14h],0ffffh
L_0b85:
	MOV        word ptr [BP + -1ch],0h
L_0b8a:
	MOV        AX,word ptr [BP + -14h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -12h],AX
	MOV        AX,word ptr [BP + -1ch]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	MOV        word ptr [BP + -1ah],AX
	MOV        AX,word ptr [BP + -14h]
	ADD        AX,5h
	MOV        word ptr [BP + -0ch],AX
	MOV        word ptr [BP + -6h],AX
	MOV        AX,word ptr [BP + -1ch]
	ADD        AX,5h
	MOV        word ptr [BP + -10h],AX
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,word ptr [BP + -1eh]
	AND        AX,3h
	JZ         L_0be4
	CMP        AX,1h
	JNZ        L_0bcc
	JMP        L_0c8c
L_0bcc:
	CMP        AX,2h
	JNZ        L_0bd4
	JMP        L_0c9a
L_0bd4:
	CMP        AX,3h
	JNZ        L_0bdc
	JMP        L_0ca8
L_0bdc:
	JMP        L_0bee
L_0bde:
	MOV        AX,42ebh
	JMP        L_0b01
L_0be4:
	MOV        word ptr [BP + -14h],0h
	MOV        word ptr [BP + -1ch],0ffffh
L_0bee:
	MOV        AX,42f2h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,3e8h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,12ch
	PUSH       AX
	CALL       SUB_0000_842e
	CALL       SUB_0000_bb56
	MOV        word ptr [BP + -2h],0h
	MOV        word ptr [BP + -18h],0h
	MOV        word ptr [BP + -16h],5h
L_0c1a:
	CMP        word ptr [BP + -2h],0h
	JZ         L_0c23
	JMP        L_0cee
L_0c23:
	CMP        word ptr [BP + -18h],0h
	JZ         L_0c2c
	JMP        L_0cee
L_0c2c:
	DEC        word ptr [BP + -16h]
	CMP        word ptr [BP + -16h],0h
	JG         L_0c38
	JMP        L_0cee
L_0c38:
	MOV        AX,word ptr [BP + -14h]
	ADD        word ptr [BP + -12h],AX
	MOV        AX,word ptr [BP + -1ch]
	ADD        word ptr [BP + -1ah],AX
	MOV        AX,word ptr [BP + -14h]
	ADD        word ptr [BP + -0ch],AX
	MOV        AX,word ptr [BP + -1ch]
	ADD        word ptr [BP + -10h],AX
	PUSH       word ptr [BP + -12h]
	PUSH       word ptr [BP + -1ah]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_7782
	MOV        word ptr [BP + -0eh],AX
	OR         AX,AX
	JNZ        L_0cb8
	PUSH       word ptr [BP + -12h]
	PUSH       word ptr [BP + -1ah]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,97h
	JC         L_0c1a
	CMP        AX,99h
	JBE        L_0cb0
	CMP        AX,0b8h
	JC         L_0c1a
	CMP        AX,0bbh
	JBE        L_0cb0
	JMP        L_0c1a
	db 90h
L_0c8c:
	MOV        word ptr [BP + -14h],1h
L_0c91:
	MOV        word ptr [BP + -1ch],0h
	JMP        L_0bee
	db 90h
L_0c9a:
	MOV        word ptr [BP + -14h],0h
	MOV        word ptr [BP + -1ch],1h
	JMP        L_0bee
	db 90h
L_0ca8:
	MOV        word ptr [BP + -14h],0ffffh
	JMP        L_0c91
	db 90h
L_0cb0:
	MOV        word ptr [BP + -2h],1h
	JMP        L_0c1a
L_0cb8:
	CMP        word ptr [BP + -0eh],1ch
	JL         L_0cd0
	MOV        AL,byte ptr [BP + -0eh]
	AND        AL,0f8h
	CMP        AL,78h
	JZ         L_0cd0
	MOV        AL,byte ptr [BP + -0eh]
	AND        AL,0fch
	CMP        AL,2fh
	JNZ        L_0cdf
L_0cd0:
	CMP        word ptr [BP + -0eh],10h
	JZ         L_0cdf
	CMP        word ptr [BP + -0eh],11h
	JZ         L_0cdf
	JMP        L_0c1a
L_0cdf:
	MOV        word ptr [BP + -18h],1h
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -8h],AX
	JMP        L_0c1a
	db 90h
L_0cee:
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -0ah]
	PUSH       word ptr [BP + -0ch]
	PUSH       word ptr [BP + -10h]
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_bc6a
	CMP        word ptr [BP + -2h],0h
	JNZ        L_0d0d
	CMP        word ptr [BP + -18h],0h
	JZ         L_0d16
L_0d0d:
	PUSH       word ptr [BP + -12h]
	PUSH       word ptr [BP + -1ah]
	CALL       SUB_0000_75a2
L_0d16:
	CMP        word ptr [BP + -2h],0h
	JZ         L_0d3b
	MOV        AX,42fah
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + -12h]
	PUSH       word ptr [BP + -1ah]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],44h
	MOV        byte ptr DS:[24e6h],1h
	MOV        byte ptr DS:[594fh],0h
L_0d3b:
	CMP        word ptr [BP + -18h],0h
	JZ         L_0d85
	CMP        word ptr [BP + -8h],0h
	JZ         L_0d85
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_7af4
	OR         byte ptr DS:[24e6h],2h
	CMP        byte ptr DS:[5888h],5h
	JBE        L_0d68
	SUB        byte ptr DS:[5888h],5h
	JMP        L_0d6d
L_0d68:
	MOV        byte ptr DS:[5888h],0h
L_0d6d:
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_bb9e
	MOV        word ptr [BP + -4h],AX
	INC        AX
	JZ         L_0d94
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_bb86
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_bb92
L_0d85:
	CMP        word ptr [BP + -18h],0h
	JZ         L_0d94
	CMP        word ptr [BP + -8h],0h
	JNZ        L_0d94
	CALL       SUB_0000_6b28
L_0d94:
	MOV        SP,BP
	POP        BP
	RET
	db 80h
	db         3Eh    >
	db 0AEh
	db         57h    W
	db 00h
	db         75h    u
	db 09h
	db 0B8h
	db 0Bh
	db         43h    C
	db         50h    P
	db 0E8h
	db         2Ah    *
	db         4Bh    K
	db 0EBh
	db         33h    3
	db 0FEh
	db 0Eh
	db 0AEh
	db         57h    W
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db 20h
	db         76h    v
	db         23h    #
	db 80h
	db         3Eh    >
	db 93h
	db         58h    X
	db         29h    )
	db         73h    s
	db 1Ch
	db 0B8h
	db 0A7h
	db         58h    X
	db         50h    P
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0B8h
	db 0Fh
	db 00h
	db         50h    P
	db 0E8h
	db         4Ah    J
	db         53h    S
	db 05h
	db         70h    p
	db 00h
	db         50h    P
	db 0B8h
	db 0FFh
	db 00h
	db         50h    P
	db 0E8h
	db 9Dh
	db         71h    q
	db 0EBh
	db 06h
	db 90h
	db 0C6h
	db 06h
	db 0A7h
	db         58h    X
	db 0F0h
	db 0C3h
	; Func
F_0aea ENDP
F_0ddc PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,24h
	PUSH       DI
	PUSH       SI
	MOV        AX,4318h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_6f0e
	MOV        word ptr [BP + -22h],AX
	INC        AX
	JNZ        L_0dfe
	MOV        AX,4320h
L_0df7:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0ead
L_0dfe:
	MOV        AX,word ptr [BP + -22h]
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        word ptr [BP + -22h],0h
	JNZ        L_0e26
	MOV        AX,4329h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,432ch
	JMP        L_0df7
	db 90h
L_0e26:
	MOV        AX,4339h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_6f0e
	MOV        word ptr [BP + -24h],AX
	INC        AX
	JNZ        L_0e3c
	MOV        AX,4340h
	JMP        L_0df7
	db 90h
L_0e3c:
	MOV        AX,word ptr [BP + -24h]
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        word ptr [BP + -24h],0h
	JNZ        L_0e64
	MOV        AX,4349h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,434ch
	JMP        L_0df7
	db 90h
L_0e64:
	MOV        AX,4359h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + -22h]
	MOV        CL,5h
	SHL        SI,CL
	ADD        SI,55a8h
	PUSH       SI
	PUSH       DI
	LEA        DI,[BP + -20h]
	PUSH       SS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	MOV        DI,word ptr [BP + -24h]
	MOV        CL,5h
	SHL        DI,CL
	ADD        DI,55a8h
	PUSH       SI
	PUSH       DI
	XCHG       DI,SI
	PUSH       DS
	POP        ES
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	PUSH       SI
	PUSH       DI
	LEA        SI,[BP + -20h]
	MOV        CX,10h
	REP MOVSW
	POP        DI
	POP        SI
	MOV        byte ptr DS:[0a9fah],1h
L_0ead:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0ddc ENDP
F_0eb4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       SI
	CMP        byte ptr DS:[5893h],20h
	JNC        L_0ed4
	CMP        byte ptr DS:[5893h],29h
	JBE        L_0ed4
	MOV        AX,435ch
L_0ecc:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_102a
	db 90h
L_0ed4:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	MOV        byte ptr [BP + -6h],AL
	MOV        AL,DS:[587ch]
	SUB        AH,AH
	AND        AX,0fch
	CMP        AX,10h
	JZ         L_0f60
	CMP        AX,14h
	JZ         L_0f20
	CMP        AX,1ch
	JZ         L_0f14
	CMP        AX,20h
	JZ         L_0f1a
	CMP        AX,24h
	JNZ        L_0f0c
	JMP        L_0f9c
L_0f0c:
	CMP        AX,28h
	JZ         L_0f72
	JMP        L_0ff4
L_0f14:
	MOV        AX,4368h
	JMP        L_0ecc
	db 90h
L_0f1a:
	MOV        AX,436fh
	JMP        L_0ecc
	db 90h
L_0f20:
	CALL       F_073e
	OR         AX,AX
	JNZ        L_0f38
	MOV        AX,1ch
	PUSH       AX
	MOV        AL,byte ptr [BP + -6h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_6ccc
	OR         AX,AX
	JZ         L_0f4c
L_0f38:
	MOV        AX,437dh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        byte ptr [BP + -2h],1bh
L_0f43:
	MOV        byte ptr DS:[587ch],1ch
	JMP        L_0ff4
	db 90h
L_0f4c:
	CALL       F_073e
	OR         AX,AX
	JNZ        L_0f5a
	MOV        AX,4386h
	JMP        L_0ecc
	db 90h
L_0f5a:
	MOV        AX,4398h
	JMP        L_0ecc
L_0f60:
	MOV        AX,43a4h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[587ch]
	SUB        AL,2h
L_0f6c:
	MOV        byte ptr [BP + -2h],AL
	JMP        L_0f43
	db 90h
L_0f72:
	CALL       F_073e
	OR         AX,AX
	JNZ        L_0f80
	MOV        AX,43ach
	JMP        L_0ecc
	db 90h
L_0f80:
	MOV        AL,byte ptr [BP + -6h]
	AND        AL,0feh
	CMP        AL,6ah
	JNZ        L_0f90
	MOV        AX,43beh
	JMP        L_0ecc
	db 90h
L_0f90:
	MOV        AX,43cah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[587ch]
	JMP        L_0f6c
L_0f9c:
	MOV        AX,43d2h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_073e
	OR         AX,AX
	JZ         L_0fba
	MOV        AL,DS:[587ch]
	MOV        byte ptr [BP + -2h],AL
	MOV        byte ptr DS:[587ch],1ch
L_0fb5:
	MOV        AL,DS:[5c61h]
	JMP        L_0fd1
L_0fba:
	CMP        byte ptr DS:[5c61h],0h
	JZ         L_0fd6
	MOV        AL,DS:[587ch]
	MOV        byte ptr [BP + -2h],AL
	ADD        byte ptr DS:[587ch],4h
	MOV        AL,DS:[5c61h]
	DEC        AL
L_0fd1:
	MOV        byte ptr [BP + -8h],AL
	JMP        L_0ff4
L_0fd6:
	CMP        byte ptr DS:[57b0h],0h
	JZ         L_0fee
	DEC        byte ptr DS:[57b0h]
	MOV        AL,DS:[587ch]
	MOV        byte ptr [BP + -2h],AL
	MOV        byte ptr DS:[587ch],14h
	JMP        L_0fb5
L_0fee:
	MOV        AX,43d9h
	JMP        L_0ecc
L_0ff4:
	CALL       SUB_0000_7964
	MOV        word ptr [BP + -4h],AX
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	MOV        SI,AX
	PUSH       SI
	PUSH       SI
	MOV        AL,DS:[5896h]
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	MOV        AL,DS:[5895h]
	PUSH       AX
	MOV        AL,DS:[5c5fh]
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_7af4
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BP + -8h]
	MOV        byte ptr [BX + 5c61h],AL
	CALL       SUB_0000_6980
L_102a:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0eb4 ENDP
F_1030 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],1h
	CMP        byte ptr DS:[5893h],1eh
	JZ         L_1055
	CMP        byte ptr DS:[5893h],1fh
	JZ         L_1055
	CMP        byte ptr DS:[5893h],20h
	JZ         L_1055
	JMP        L_11f4
L_1055:
	SUB        DI,DI
	MOV        SI,444ah
L_105a:
	PUSH       word ptr [SI]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_af9e
	CMP        AX,0ffffh
	JLE        L_108a
L_1067:
	MOV        word ptr [BP + -8h],DI
	CMP        DI,3h
	JZ         L_107f
	CMP        byte ptr DS:[5897h],2h
	JC         L_107f
	MOV        BX,DI
	CMP        byte ptr [BX + 58c8h],0ffh
	JNZ        L_1096
L_107f:
	MOV        AX,440bh
L_1082:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_11fa
	db 90h
L_108a:
	ADD        SI,2h
	INC        DI
	CMP        DI,3h
	JGE        L_1067
	JMP        L_105a
	db 90h
L_1096:
	SUB        DI,DI
	MOV        SI,5c5ah
L_109b:
	CMP        byte ptr [SI],0fch
	JNZ        L_10ae
	MOV        AX,4418h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -0ah],DI
	JMP        L_11fa
	db 90h
L_10ae:
	ADD        SI,8h
	INC        DI
	CMP        DI,20h
	JL         L_109b
	MOV        word ptr [BP + -0ah],DI
	MOV        AL,byte ptr [BP + -8h]
	MOV        DS:[58cbh],AL
	CALL       SUB_0000_7964
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,0fch
	PUSH       AX
	PUSH       AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	SUB        AX,2h
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	SUB        AX,AX
	PUSH       AX
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_7af4
	MOV        word ptr [BP + -2h],1fh
	MOV        SI,1fh
	MOV        CX,word ptr [BP + -2h]
L_10f2:
	CMP        byte ptr [SI + 659eh],0h
	JZ         L_10fc
	JMP        L_11ea
L_10fc:
	MOV        CX,SI
L_10fe:
	MOV        word ptr [BP + -6h],SI
	MOV        word ptr [BP + -2h],CX
	MOV        AX,CX
	MOV        CL,4h
	SHL        AX,CL
	MOV        word ptr [BP + -10h],AX
	MOV        BX,AX
	MOV        word ptr [BX + 5f5eh],1h
	MOV        AX,word ptr [BP + -0ah]
	MOV        word ptr [BX + 5f6ah],AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BX + 5f60h],AX
	MOV        AL,DS:[5897h]
	SUB        AX,2h
	MOV        word ptr [BX + 5f62h],AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        word ptr [BX + 5f64h],AX
	MOV        word ptr [BP + -6h],0h
	MOV        AX,BX
	MOV        word ptr [BP + -0ch],AX
	SUB        AX,AX
	MOV        CX,2h
	LEA        DI,[BX + 5d6ah]
	PUSH       DS
	POP        ES
	REP STOSW
	ADD        word ptr [BP + -6h],4h
	MOV        word ptr [BP + -6h],AX
	MOV        DX,word ptr [BP + -2h]
	MOV        CL,4h
	SHL        DX,CL
	MOV        AL,DS:[5897h]
	SUB        AL,2h
	MOV        byte ptr [BP + -0eh],AL
	MOV        CX,word ptr [BP + -6h]
L_1168:
	MOV        SI,DX
	ADD        SI,CX
	MOV        byte ptr [SI + 5d5eh],6h
	MOV        AL,DS:[5896h]
	MOV        byte ptr [SI + 5d61h],AL
	MOV        AL,byte ptr [BP + -0eh]
	MOV        byte ptr [SI + 5d64h],AL
	MOV        AL,DS:[5895h]
	MOV        byte ptr [SI + 5d67h],AL
	INC        CX
	CMP        CX,3h
	JL         L_1168
	MOV        word ptr [BP + -6h],CX
	MOV        BX,word ptr [BP + -2h]
	MOV        byte ptr [BX + 659eh],0fch
	MOV        AX,4425h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,28a0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,7530h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_6212
	MOV        SI,word ptr [BP + -0ah]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,16h
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AX,1fch
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_50e8
	MOV        AL,0fch
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        word ptr [BP + -4h],0h
	MOV        AX,word ptr [BP + -4h]
	JMP        L_11fa
	db 90h
L_11ea:
	DEC        SI
	JNS        L_11f0
	JMP        L_10fe
L_11f0:
	JMP        L_10f2
	db 90h
L_11f4:
	MOV        AX,443ch
	JMP        L_1082
L_11fa:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_1030 ENDP
F_1202 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,18h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -14h],1h
	MOV        AX,4450h
	PUSH       AX
	CALL       SUB_0000_58d0
	LEA        AX,[BP + -10h]
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_7b9c
	MOV        BX,word ptr [BP + 8h]
	SHL        BX,1h
	PUSH       word ptr [BX + 1f4eh]
	LEA        AX,[BP + -10h]
	PUSH       AX
	CALL       SUB_0000_af9e
	INC        AX
	JNZ        L_1239
	MOV        word ptr [BP + -14h],0h
L_1239:
	MOV        word ptr [BP + -12h],3h
	MOV        AX,word ptr [BP + 8h]
	SHL        AX,1h
	ADD        AX,1f5eh
	MOV        word ptr [BP + -16h],AX
	MOV        SI,3h
	MOV        DI,word ptr [BP + -14h]
L_124f:
	MOV        AX,4479h
	PUSH       AX
	CALL       SUB_0000_58d0
	LEA        AX,[BP + -10h]
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_7b9c
	MOV        BX,word ptr [BP + -16h]
	PUSH       word ptr [BX]
	LEA        AX,[BP + -10h]
	PUSH       AX
	CALL       SUB_0000_af9e
	INC        AX
	JNZ        L_1272
	SUB        DI,DI
L_1272:
	DEC        SI
	JNZ        L_124f
	MOV        word ptr [BP + -14h],DI
	OR         DI,DI
	JZ         L_12b8
	MOV        BX,word ptr [BP + 8h]
	MOV        AL,byte ptr [BX + 1f6eh]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_12b8
	MOV        AL,byte ptr [BX + 1f76h]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_12b8
	AND        byte ptr [BX + 58d8h],7fh
	MOV        AX,4482h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_70f2
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],19h
	OR         byte ptr DS:[24e6h],2h
	JMP        L_12bf
	db 90h
L_12b8:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
L_12bf:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_1202 ENDP
F_12c8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	SUB        SI,SI
	MOV        word ptr [BP + -0ch],4502h
	MOV        DI,word ptr [BP + -8h]
L_12df:
	MOV        BX,word ptr [BP + -0ch]
	PUSH       word ptr [BX]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_af9e
	CMP        AX,0ffffh
	JG         L_12f2
	JMP        L_13f4
L_12f2:
	MOV        AX,44d7h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_70f2
	MOV        AL,DS:[0aba6h]
	MOV        byte ptr [BP + -0ah],AL
	CMP        byte ptr [SI + 4512h],AL
	JZ         L_1310
	CMP        AL,0dfh
	JZ         L_1310
	CMP        AL,1ah
	JNZ        L_131a
L_1310:
	MOV        word ptr [BP + -4h],0ffffh
L_1315:
	SUB        DI,DI
	JMP        L_1373
	db 90h
L_131a:
	MOV        AL,DS:[0abc7h]
	MOV        byte ptr [BP + -0ah],AL
	CMP        byte ptr [SI + 4512h],AL
	JZ         L_132e
	CMP        AL,0dfh
	JZ         L_132e
	CMP        AL,1ah
	JNZ        L_1338
L_132e:
	MOV        word ptr [BP + -4h],0h
	MOV        DI,1h
	JMP        L_1373
L_1338:
	MOV        AL,DS:[0aba8h]
	MOV        byte ptr [BP + -0ah],AL
	CMP        byte ptr [SI + 4512h],AL
	JZ         L_134c
	CMP        AL,0dfh
	JZ         L_134c
	CMP        AL,1ah
	JNZ        L_1354
L_134c:
	MOV        word ptr [BP + -4h],1h
	JMP        L_1315
	db 90h
L_1354:
	MOV        AL,DS:[0ab87h]
	MOV        byte ptr [BP + -0ah],AL
	CMP        byte ptr [SI + 4512h],AL
	JZ         L_136b
	CMP        AL,0dfh
	JZ         L_136b
	CMP        AL,1ah
	JZ         L_136b
	JMP        L_13ec
L_136b:
	MOV        word ptr [BP + -4h],0h
	MOV        DI,0ffffh
L_1373:
	CMP        byte ptr [BP + -0ah],1ah
	JNZ        L_139a
	PUSH       SI
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	PUSH       AX
	MOV        AX,DI
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	PUSH       AX
	CALL       F_1202
	MOV        word ptr [BP + -8h],DI
	MOV        word ptr [BP + -2h],SI
	JMP        L_140f
L_139a:
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        CL,byte ptr [SI + 1eaah]
	CMP        AX,CX
	JNZ        L_13e7
	MOV        AX,DI
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	MOV        CL,byte ptr [SI + 1ed2h]
	CMP        AX,CX
	JNZ        L_13e7
	XOR        byte ptr [SI + 58d0h],80h
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,byte ptr DS:[5896h]
	ADD        AX,CX
	PUSH       AX
	MOV        AX,DI
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [SI + 4512h]
	XOR        AL,0dfh
	XOR        byte ptr [BX],AL
	OR         byte ptr DS:[24e6h],2h
L_13e7:
	MOV        word ptr [BP + -6h],1h
L_13ec:
	MOV        word ptr [BP + -8h],DI
	MOV        word ptr [BP + -2h],SI
	JMP        L_1402
L_13f4:
	ADD        word ptr [BP + -0ch],2h
	INC        SI
	CMP        SI,8h
	JGE        L_13ec
	JMP        L_12df
	db 90h
L_1402:
	CMP        word ptr [BP + -6h],0h
	JNZ        L_140f
	MOV        AX,44f4h
	PUSH       AX
	CALL       SUB_0000_58d0
L_140f:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_12c8 ENDP
F_1418 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,22h
	MOV        word ptr [BP + -22h],1h
	MOV        AL,DS:[587ch]
	AND        AL,0f8h
	CMP        AL,20h
	JNZ        L_1458
	CMP        byte ptr DS:[5893h],80h
	JNC        L_1458
	MOV        AL,DS:[587ch]
	AND        AL,0fch
	CMP        AL,20h
	JNZ        L_144a
	MOV        AX,451ah
	PUSH       AX
	CALL       SUB_0000_58d0
	ADD        byte ptr DS:[587ch],4h
	JMP        L_14b6
L_144a:
	MOV        AX,4521h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        byte ptr DS:[587ch],4h
	JMP        L_14b6
L_1458:
	MOV        AX,4529h
	PUSH       AX
	CALL       SUB_0000_58d0
	LEA        AX,[BP + -20h]
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_7b9c
	CMP        byte ptr [BP + -20h],0h
	JNZ        L_147a
	MOV        AX,4531h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_14b6
	db 90h
L_147a:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	CMP        byte ptr DS:[5893h],1h
	JC         L_149c
	CMP        byte ptr DS:[5893h],20h
	JA         L_149c
	LEA        AX,[BP + -20h]
	PUSH       AX
	CALL       F_1030
	MOV        word ptr [BP + -22h],AX
	JMP        L_14b3
	db 90h
L_149c:
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_14ac
	LEA        AX,[BP + -20h]
	PUSH       AX
	CALL       F_12c8
	JMP        L_14b3
L_14ac:
	MOV        AX,453ah
	PUSH       AX
	CALL       SUB_0000_58d0
L_14b3:
	MOV        AX,word ptr [BP + -22h]
L_14b6:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1418 ENDP
F_14ba PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,byte ptr [BP + 4h]
	SUB        AH,AH
	CMP        AX,0a6h
	JA         L_14e0
	CMP        AX,0a5h
	JNC        L_14db
	CMP        AX,5bh
	JZ         L_14db
	CMP        AX,90h
	JC         L_14fe
	CMP        AX,93h
	JA         L_14fe
L_14db:
	MOV        AX,1h
	JMP        L_1500
L_14e0:
	CMP        AX,0a8h
	JC         L_14fe
	CMP        AX,0a9h
	JBE        L_14db
	CMP        AX,0adh
	JC         L_14fe
	CMP        AX,0afh
	JBE        L_14db
	CMP        AX,0b4h
	JC         L_14fe
	CMP        AX,0b7h
	JBE        L_14db
L_14fe:
	SUB        AX,AX
L_1500:
	POP        BP
	RET        2h
	; Func
F_14ba ENDP
F_1504 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        word ptr [BP + 0ah],1h
	JNZ        L_1516
	CMP        word ptr [BP + 8h],0h
	JNZ        L_1516
	INC        word ptr [BP + 6h]
L_1516:
	CMP        word ptr [BP + 0ah],0h
	JNZ        L_1526
	CMP        word ptr [BP + 8h],1h
	JNZ        L_1526
	ADD        word ptr [BP + 6h],2h
L_1526:
	CMP        word ptr [BP + 0ah],-1h
	JNZ        L_1536
	CMP        word ptr [BP + 8h],0h
	JNZ        L_1536
	ADD        word ptr [BP + 6h],3h
L_1536:
	CMP        word ptr [BP + 4h],0h
	JZ         L_1540
	XOR        byte ptr [BP + 6h],2h
L_1540:
	MOV        AX,word ptr [BP + 6h]
	POP        BP
	RET        8h
	db 90h
	; Func
F_1504 ENDP
F_1548 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,4547h
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + 12h]
	MOV        byte ptr [BX],AL
	PUSH       word ptr [BP + 0eh]
	PUSH       word ptr [BP + 0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + 10h]
	MOV        byte ptr [BX],AL
	AND        word ptr [BP + 12h],0fch
	CMP        word ptr [BP + 12h],90h
	JZ         L_1588
	CMP        word ptr [BP + 12h],0b4h
	JNZ        L_15aa
L_1588:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + 12h]
	SUB        AX,AX
	PUSH       AX
	CALL       F_1504
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	MOV        word ptr [BP + -2h],AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + -2h]
	MOV        byte ptr [BX],AL
L_15aa:
	MOV        SP,BP
	POP        BP
	RET        10h
	; Func
F_1548 ENDP
F_15b0 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AX,4550h
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + 0eh]
	PUSH       word ptr [BP + 0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + 10h]
	MOV        byte ptr [BX],AL
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + 12h]
	MOV        byte ptr [BX],AL
	AND        word ptr [BP + 10h],0fch
	CMP        word ptr [BP + 10h],90h
	JZ         L_15f0
	CMP        word ptr [BP + 10h],0b4h
	JNZ        L_1613
L_15f0:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + 10h]
	MOV        AX,1h
	PUSH       AX
	CALL       F_1504
	PUSH       word ptr [BP + 0eh]
	PUSH       word ptr [BP + 0ch]
	MOV        word ptr [BP + -2h],AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + -2h]
	MOV        byte ptr [BX],AL
L_1613:
	MOV        SP,BP
	POP        BP
	RET        10h
	db 90h
	; Func
F_15b0 ENDP
F_161a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ah
	PUSH       SI
	MOV        AL,DS:[594fh]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5950h]
	PUSH       AX
	MOV        AL,DS:[5951h]
	PUSH       AX
	CALL       SUB_0000_7a4c
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_163c
	JMP        L_17e6
L_163c:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -10h],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -16h],AX
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_1674
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -0ch],AX
	MOV        AL,DS:[589eh]
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba1ah]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [SI + 0ba1bh]
	MOV        DS:[5897h],AL
L_1674:
	MOV        AX,word ptr [BP + -10h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,word ptr [BP + -16h]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	MOV        word ptr [BP + -14h],AX
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_16a3
	PUSH       word ptr [BP + -0eh]
	PUSH       AX
	CALL       SUB_0000_bf3a
	OR         AX,AX
	JZ         L_16a3
	JMP        L_17e6
L_16a3:
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -14h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -14h]
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JNZ        L_16d0
	PUSH       word ptr [BP + -2h]
	CALL       F_14ba
	OR         AX,AX
	JNZ        L_16da
L_16d0:
	MOV        AX,4559h
L_16d3:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_17e6
L_16da:
	MOV        AL,byte ptr [BP + -2h]
	AND        AL,0fch
	CMP        AL,0b4h
	JNZ        L_16e8
	MOV        AX,45h
	JMP        L_16eb
L_16e8:
	MOV        AX,44h
L_16eb:
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [BP + -0eh]
	ADD        AX,word ptr [BP + -10h]
	MOV        word ptr [BP + -12h],AX
	MOV        AX,word ptr [BP + -14h]
	ADD        AX,word ptr [BP + -16h]
	MOV        word ptr [BP + -18h],AX
	PUSH       word ptr [BP + -12h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        AL,DS:[5896h]
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -1ah],AX
	PUSH       word ptr [BP + -12h]
	PUSH       word ptr [BP + -18h]
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JNZ        L_175a
	MOV        AX,word ptr [BP + -8h]
	CMP        word ptr [BP + -4h],AX
	JNZ        L_175a
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -14h]
	PUSH       word ptr [BP + -12h]
	PUSH       word ptr [BP + -18h]
	PUSH       word ptr [BP + -10h]
	PUSH       word ptr [BP + -16h]
	CALL       F_1548
	JMP        L_178a
L_175a:
	MOV        AX,word ptr [BP + -8h]
	CMP        word ptr [BP + -1ah],AX
	JNZ        L_1784
	PUSH       word ptr [BP + -1ah]
	PUSH       word ptr [BP + -2h]
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	PUSH       word ptr [BP + -0eh]
	PUSH       word ptr [BP + -14h]
	PUSH       word ptr [BP + -10h]
	PUSH       word ptr [BP + -16h]
	CALL       F_15b0
	JMP        L_178a
	db 90h
L_1784:
	MOV        AX,4567h
	JMP        L_16d3
L_178a:
	MOV        AL,byte ptr [BP + -10h]
	ADD        byte ptr DS:[5896h],AL
	MOV        AL,byte ptr [BP + -16h]
	ADD        byte ptr DS:[5897h],AL
	MOV        byte ptr DS:[24e6h],1h
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_17e6
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba17h]
	MOV        word ptr [BP + -6h],AX
	MOV        AL,byte ptr [BP + -10h]
	ADD        byte ptr [SI + 0ba1ah],AL
	MOV        AL,byte ptr [BP + -16h]
	ADD        byte ptr [SI + 0ba1bh],AL
	MOV        SI,word ptr [BP + -6h]
	SHL        SI,CL
	MOV        AL,byte ptr [BP + -10h]
	ADD        byte ptr [SI + 5c5ch],AL
	MOV        AL,byte ptr [BP + -16h]
	ADD        byte ptr [SI + 5c5dh],AL
	MOV        AL,byte ptr [BP + -0ah]
	MOV        DS:[5896h],AL
	MOV        AL,byte ptr [BP + -0ch]
	MOV        DS:[5897h],AL
	CALL       SUB_0000_9990
L_17e6:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_161a ENDP
F_17ec PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        AX,4574h
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -2h],AX
	MOV        word ptr [BP + -6h],AX
	MOV        SI,0ba16h
	MOV        DX,AX
	MOV        CX,AX
L_180d:
	MOV        AL,byte ptr [SI]
	AND        AL,0a0h
	CMP        AL,80h
	JNZ        L_182e
	MOV        DX,1h
L_1818:
	MOV        word ptr [BP + -2h],DX
	MOV        word ptr [BP + -6h],CX
	OR         DX,DX
	JZ         L_184d
	TEST       byte ptr DS:[58a1h],80h
	JZ         L_183a
	MOV        AX,457bh
	JMP        L_1844
L_182e:
	ADD        SI,8h
	INC        CX
	CMP        CX,20h
	JGE        L_1818
	JMP        L_180d
	db 90h
L_183a:
	CMP        byte ptr DS:[58a3h],0h
	JNZ        L_184d
	MOV        AX,4587h
L_1844:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -4h],1h
L_184d:
	CMP        word ptr [BP + -4h],0h
	JNZ        L_18af
	MOV        AX,21h
	PUSH       AX
	CALL       SUB_0000_573a
	SUB        SI,SI
	MOV        DI,0ba16h
L_185f:
	CMP        byte ptr [DI],0h
	JZ         L_1870
	MOV        AX,SI
	NEG        AX
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_be02
	CALL       SUB_0000_9990
L_1870:
	ADD        DI,8h
	INC        SI
	CMP        SI,20h
	JL         L_185f
	MOV        word ptr [BP + -6h],SI
	SUB        SI,SI
	MOV        DI,5c5ah
L_1881:
	CMP        byte ptr [DI],0h
	JZ         L_1890
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_be02
	CALL       SUB_0000_9990
L_1890:
	ADD        DI,8h
	INC        SI
	CMP        SI,20h
	JL         L_1881
	MOV        word ptr [BP + -6h],SI
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_842e
L_18af:
	MOV        byte ptr DS:[0a9fah],1h
	MOV        AX,word ptr [BP + -4h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_17ec ENDP
F_18be PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,18h
	PUSH       DI
	PUSH       SI
	SUB        CX,CX
	SUB        SI,SI
L_18ca:
	CMP        byte ptr [SI + 5850h],0h
	JZ         L_18d9
	MOV        DI,CX
	MOV        AX,SI
	MOV        byte ptr [BP + DI + -10h],AL
	INC        CX
L_18d9:
	INC        SI
	CMP        SI,8h
	JL         L_18ca
	MOV        word ptr [BP + -6h],SI
	MOV        word ptr [BP + -14h],CX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5c14
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
	CALL       SUB_0000_5ca2
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_573a
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
	CALL       SUB_0000_5ca2
	CALL       SUB_0000_8f7c
	MOV        AX,8f64h
	PUSH       AX
	CALL       SUB_0000_8ed0
	SUB        SI,SI
	MOV        DI,word ptr [BP + -18h]
	JMP        L_196a
L_1932:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AL,byte ptr [BP + SI + -10h]
	SUB        AH,AH
	MOV        DI,AX
	MOV        AL,byte ptr [DI + 5850h]
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,30h
	PUSH       AX
	CALL       SUB_0000_5abe
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        BX,DI
	SHL        BX,1h
	PUSH       word ptr [BX + 19d2h]
	CALL       SUB_0000_58d0
	INC        SI
L_196a:
	CMP        SI,word ptr [BP + -14h]
	JNZ        L_1932
	MOV        word ptr [BP + -6h],SI
	SUB        AX,AX
	MOV        word ptr [BP + -16h],AX
	MOV        SI,AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6aa8
	MOV        word ptr [BP + -2h],SI
	MOV        AX,word ptr [BP + -14h]
	DEC        AX
	MOV        word ptr [BP + -18h],AX
	MOV        DI,SI
L_198c:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_5c14
	CALL       SUB_0000_66ec
	MOV        word ptr [BP + -8h],AX
	CMP        AX,4h
	JZ         L_19d0
	JLE        L_19a3
	JMP        L_1a3c
L_19a3:
	CMP        AX,1h
	JZ         L_19b2
	CMP        AX,2h
	JZ         L_19d0
	CMP        AX,3h
	JNZ        L_19c5
L_19b2:
	OR         SI,SI
	JLE        L_19c5
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_6aa8
	DEC        SI
L_19be:
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_6aa8
L_19c5:
	CMP        word ptr [BP + -2h],0h
	JZ         L_19ce
	JMP        L_1a54
L_19ce:
	JMP        L_198c
L_19d0:
	CMP        word ptr [BP + -18h],SI
	JLE        L_19c5
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_6aa8
	INC        SI
	JMP        L_19be
	db 90h
L_19e0:
	MOV        word ptr [BP + -2h],1h
	MOV        AX,8f6eh
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_19c5
L_19ee:
	MOV        CL,byte ptr [BP + SI + -10h]
	MOV        AX,80h
	SAR        AX,CL
	MOV        word ptr [BP + -12h],AX
	XOR        DI,AX
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_5c14
	MOV        AX,3h
	PUSH       AX
	LEA        AX,[SI + 1h]
	PUSH       AX
	CALL       SUB_0000_5c72
	MOV        AX,0fdh
	PUSH       AX
	CALL       SUB_0000_573a
	TEST       word ptr [BP + -12h],DI
	JZ         L_1a1e
	MOV        AX,0fh
	JMP        L_1a21
L_1a1e:
	MOV        AX,20h
L_1a21:
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,0fdh
L_1a28:
	PUSH       AX
	CALL       SUB_0000_573a
	JMP        L_19c5
L_1a2e:
	MOV        DI,0ffffh
	MOV        word ptr [BP + -2h],1h
	MOV        AX,0ah
	JMP        L_1a28
	db 90h
L_1a3c:
	CMP        AX,0dh
	JZ         L_19ee
	CMP        AX,1bh
	JZ         L_1a2e
	CMP        AX,20h
	JZ         L_19ee
	CMP        AX,4dh
	JZ         L_19e0
	JMP        L_19c5
	db 90h
L_1a54:
	MOV        word ptr [BP + -16h],DI
	MOV        word ptr [BP + -4h],SI
	MOV        AX,SI
	INC        AX
	PUSH       AX
	CALL       SUB_0000_6aa8
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_5c14
	MOV        AX,DI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_18be ENDP
F_1a70 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
L_1a78:
	MOV        word ptr [BP + -4h],1h
	MOV        AX,8f72h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_7c1e
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JZ         L_1ac6
	MOV        DI,80h
	SUB        SI,SI
L_1a97:
	TEST       word ptr [BP + 4h],DI
	JZ         L_1abc
	MOV        AL,byte ptr [SI + 5850h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -2h]
	JNC        L_1abc
	MOV        AX,8f7eh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -4h],0h
L_1ab3:
	MOV        word ptr [BP + -8h],DI
	MOV        word ptr [BP + -6h],SI
	JMP        L_1ac6
	db 90h
L_1abc:
	SAR        DI,1h
	INC        SI
	CMP        SI,8h
	JGE        L_1ab3
	JMP        L_1a97
L_1ac6:
	CMP        word ptr [BP + -4h],0h
	JZ         L_1a78
	MOV        AX,word ptr [BP + -2h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_1a70 ENDP
F_1ad8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	SUB        CX,CX
	SUB        SI,SI
L_1ae4:
	MOV        AL,byte ptr [SI + 5850h]
	SUB        AH,AH
	ADD        CX,AX
	INC        SI
	CMP        SI,8h
	JL         L_1ae4
	MOV        word ptr [BP + -8h],SI
	MOV        word ptr [BP + -6h],CX
	OR         CX,CX
	JNZ        L_1b06
	MOV        AX,8f98h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1c1a
L_1b06:
	MOV        AX,8fach
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_c10e
	MOV        word ptr [BP + -4h],AX
	CMP        AX,0ffffh
	JNZ        L_1b1e
	MOV        AX,8fbeh
	JMP        L_1c0d
L_1b1e:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,1bh
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,2ch
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,1ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,2ch
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,18h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,2ch
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,19h
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,8fc6h
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       F_18be
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JGE        L_1b6a
	JMP        L_1c11
L_1b6a:
	PUSH       AX
	CALL       F_1a70
	MOV        word ptr [BP + -6h],AX
	OR         AX,AX
	JG         L_1b78
	JMP        L_1c11
L_1b78:
	CMP        word ptr [BP + -2h],0h
	JNZ        L_1b81
	JMP        L_1c0a
L_1b81:
	MOV        AX,8ff0h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        byte ptr DS:[5893h],20h
	JBE        L_1b98
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_617a
	JMP        L_1b9f
L_1b98:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_7b66
L_1b9f:
	MOV        CX,80h
	SUB        SI,SI
	MOV        DI,word ptr [BP + -2h]
	MOV        DX,word ptr [BP + -6h]
L_1baa:
	TEST       CX,DI
	JZ         L_1bb4
	MOV        AX,DX
	SUB        byte ptr [SI + 5850h],AL
L_1bb4:
	SAR        CX,1h
	INC        SI
	CMP        SI,8h
	JL         L_1baa
	MOV        word ptr [BP + -8h],SI
	MOV        word ptr [BP + -0ah],CX
	CMP        word ptr [BP + -4h],0h
	JL         L_1bf6
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BX + 1cc0h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -2h]
	JNZ        L_1bf6
	MOV        AX,8ffch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BP + -6h]
	ADD        byte ptr [BX + 57f0h],AL
	CMP        byte ptr [BX + 57f0h],63h
	JBE        L_1c11
	MOV        byte ptr [BX + 57f0h],63h
	JMP        L_1c11
	db 90h
L_1bf6:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	CALL       SUB_0000_7a7c
	PUSH       word ptr DS:[5876h]
	CALL       SUB_0000_7050
	JMP        L_1c11
	db 90h
L_1c0a:
	MOV        AX,9004h
L_1c0d:
	PUSH       AX
	CALL       SUB_0000_58d0
L_1c11:
	CALL       SUB_0000_8ea0
	CALL       SUB_0000_8fbc
	CALL       SUB_0000_6980
L_1c1a:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1ad8 ENDP
F_1c20 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[57afh],0h
	JNZ        L_1c3a
	MOV        AX,9016h
L_1c32:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1d05
	db 90h
L_1c3a:
	CMP        byte ptr DS:[587ch],1ch
	JZ         L_1c46
	MOV        AX,9022h
	JMP        L_1c32
L_1c46:
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_1c50
	JMP        L_1d05
L_1c50:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -4h],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -8h],AX
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	MOV        word ptr [BP + -0ah],AX
	PUSH       word ptr [BP + -6h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	CMP        AX,0dh
	JNZ        L_1c8e
	MOV        AX,902ch
	JMP        L_1c32
L_1c8e:
	CMP        word ptr [BP + -0ch],0ch
	JZ         L_1c9a
	MOV        AX,903ah
	JMP        L_1c32
	db 90h
L_1c9a:
	MOV        word ptr [BP + -2h],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_1cfc
	MOV        DI,55b3h
	MOV        word ptr [BP + -10h],55b5h
	MOV        SI,word ptr [BP + -2h]
L_1cb3:
	CMP        byte ptr [DI],44h
	JZ         L_1ce5
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        BX,word ptr [BP + -10h]
	MOV        CL,byte ptr [BX]
	SUB        CH,CH
	CMP        CX,AX
	JNC        L_1ce5
	MOV        AX,904ah
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       SI
	MOV        AX,1h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	CALL       SUB_0000_6112
	PUSH       AX
	CALL       SUB_0000_6ad2
L_1ce5:
	ADD        DI,20h
	ADD        word ptr [BP + -10h],20h
	INC        SI
	MOV        AX,SI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_1cb3
	MOV        word ptr [BP + -2h],SI
L_1cfc:
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_bc46
L_1d05:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	db 00h
	db 00h
	db 00h
	db 00h
F_1c20 ENDP
_TEXT ENDS
END
