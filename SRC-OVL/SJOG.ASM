_TEXT SEGMENT BYTE 'CODE'
ORG 58d0h
SUB_0000_58d0:
ORG 66ech
SUB_0000_66ec:
ORG 6112h
SUB_0000_6112:
ORG 7af4h
SUB_0000_7af4:
ORG 62bch
SUB_0000_62bc:
ORG 9990h
SUB_0000_9990:
ORG 770eh
SUB_0000_770e:
ORG 7964h
SUB_0000_7964:
ORG 5abeh
SUB_0000_5abe:
ORG 8a08h
SUB_0000_8a08:
ORG bcd6h
SUB_0000_bcd6:
ORG 4fc6h
SUB_0000_4fc6:
ORG 766ch
SUB_0000_766c:
ORG 8482h
SUB_0000_8482:
ORG 7782h
SUB_0000_7782:
ORG 842eh
SUB_0000_842e:
ORG bb9eh
SUB_0000_bb9e:
ORG bb7ah
SUB_0000_bb7a:
ORG 7f70h
SUB_0000_7f70:
ORG bb86h
SUB_0000_bb86:
ORG 7050h
SUB_0000_7050:
ORG 7a4ch
SUB_0000_7a4c:
ORG bb92h
SUB_0000_bb92:
ORG 7f94h
SUB_0000_7f94:
ORG 9ecah
SUB_0000_9eca:
ORG aee0h
SUB_0000_aee0:
ORG 96c6h
SUB_0000_96c6:
ORG 6340h
SUB_0000_6340:
ORG be02h
SUB_0000_be02:
ORG 6980h
SUB_0000_6980:
ORG bdf6h
SUB_0000_bdf6:
ORG 83beh
SUB_0000_83be:
ORG bf3ah
SUB_0000_bf3a:
ORG 5b96h
SUB_0000_5b96:
ORG 573ah
SUB_0000_573a:
ORG be1ah
SUB_0000_be1a:
ORG bccah
SUB_0000_bcca:
ORG 6212h
SUB_0000_6212:
ORG a92eh
SUB_0000_a92e:
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
	MOV        DX,20h
L_0009:
	DEC        DX
	JS         L_0020
	MOV        BX,DX
	MOV        CL,3h
	SHL        BX,CL
	CMP        byte ptr [BX + 5c5ah],0h
	JNZ        L_0009
	MOV        AX,DX
	MOV        word ptr [BP + -2h],DX
	JMP        L_0025
L_0020:
	MOV        word ptr [BP + -2h],DX
	SUB        AX,AX
L_0025:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0000 ENDP
F_002a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,word ptr [BP + 6h]
	MOV        DS:[5876h],AX
	MOV        AX,word ptr [BP + 4h]
	MOV        DS:[5878h],AX
	MOV        AX,word ptr [BP + 8h]
	OR         AX,AX
	JZ         L_0052
	CMP        AX,1h
	JZ         L_0058
	CMP        AX,2h
	JZ         L_005e
	CMP        AX,3h
	JZ         L_0064
	JMP        L_0068
	db 90h
L_0052:
	DEC        word ptr DS:[5878h]
	JMP        L_0068
L_0058:
	INC        word ptr DS:[5876h]
	JMP        L_0068
L_005e:
	INC        word ptr DS:[5878h]
	JMP        L_0068
L_0064:
	DEC        word ptr DS:[5876h]
L_0068:
	POP        BP
	RET        6h
	; Func
F_002a ENDP
F_006c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        AX,84e6h
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0094
	db 90h
L_007c:
	CMP        byte ptr [BP + -4h],3h
	JZ         L_009e
	CMP        byte ptr [BP + -4h],4h
	JZ         L_009e
	CMP        byte ptr [BP + -4h],2h
	JZ         L_009e
	CMP        byte ptr [BP + -4h],1h
	JZ         L_009e
L_0094:
	CALL       SUB_0000_66ec
	MOV        byte ptr [BP + -4h],AL
	CMP        AL,20h
	JNZ        L_007c
L_009e:
	MOV        AL,byte ptr [BP + -4h]
	SUB        AH,AH
	CMP        AX,1h
	JZ         L_0114
	CMP        AX,2h
	JZ         L_00fc
	CMP        AX,3h
	JZ         L_00c8
	CMP        AX,4h
	JZ         L_00e4
	CMP        AX,20h
	JNZ        L_00df
	MOV        AX,84ech
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
	JMP        L_0124
	db 90h
L_00c8:
	MOV        AX,84f2h
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + 4h]
L_00d2:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       F_002a
L_00df:
	MOV        AX,1h
	JMP        L_0124
L_00e4:
	MOV        AX,84fah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        DS:[5876h],AX
	MOV        AL,DS:[5897h]
	MOV        DS:[5878h],AX
	JMP        L_00df
	db 90h
L_00fc:
	MOV        AX,8500h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	INC        AX
L_0107:
	CWD
	MOV        CX,4h
	IDIV       CX
	MOV        word ptr [BP + -2h],DX
	PUSH       DX
	JMP        L_00d2
	db 90h
L_0114:
	MOV        AX,8508h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,3h
	JMP        L_0107
	db 90h
L_0124:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_006c ENDP
F_012a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AX,word ptr [BP + 4h]
	SUB        AX,1h
	CMP        AX,1eh
	JA         L_01aa
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0c130h]
	db 0B8h
	db 0Eh
	db 85h
L_0143:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_01ee
	db 0B8h
	db 18h
	db 85h
	db 0EBh
	db 0F4h
	db 90h
	db 0B8h
	db         2Ah    *
	db 85h
	db 0EBh
	db 0EEh
	db 90h
	db 0B8h
	db         36h    6
	db 85h
	db 0EBh
	db 0E8h
	db 90h
	db 0B8h
	db         42h    B
	db 85h
	db 0EBh
	db 0E2h
	db 90h
	db 0B8h
	db         4Eh    N
	db 85h
	db 0EBh
	db 0DCh
	db 90h
	db 0B8h
	db         5Ah    Z
	db 85h
	db 0EBh
	db 0D6h
	db 90h
	db 0B8h
	db         6Ch    l
	db 85h
	db 0EBh
	db 0D0h
	db 90h
	db 0B8h
	db         74h    t
	db 85h
	db 0EBh
	db 0CAh
	db 90h
	db 0B8h
	db         7Eh    ~
	db 85h
	db 0EBh
	db 0C4h
	db 90h
	db 0B8h
	db 88h
	db 85h
	db 0EBh
	db 0BEh
	db 90h
	db 0B8h
	db 96h
	db 85h
	db 0EBh
	db 0B8h
	db 90h
	db 0B8h
	db 0A2h
	db 85h
	db 0EBh
	db 0B2h
	db 90h
	db 0B8h
	db 0B2h
	db 85h
	db 0EBh
	db 0ACh
	db 90h
	db 0B8h
	db 0BEh
	db 85h
	db 0EBh
	db 0A6h
	db 90h
	db 0B8h
	db 0D0h
	db 85h
	db 0EBh
	db 0A0h
	db 90h
	db 0B8h
	db 0E2h
	db 85h
	db 0EBh
	db 9Ah
	db 90h
L_01aa:
	MOV        AX,85f4h
	JMP        L_0143
	db 90h
	db 0C0h
	db 0C0h
	db 0CAh
	db 0C0h
	db 0D0h
	db 0C0h
	db 0D6h
	db 0C0h
	db 0DCh
	db 0C0h
	db 0E2h
	db 0C0h
	db 0E8h
	db 0C0h
	db 0EEh
	db 0C0h
	db 0F4h
	db 0C0h
	db 0FAh
	db 0C0h
	db 00h
	db 0C1h
	db 06h
	db 0C1h
	db 0Ch
	db 0C1h
	db         2Ah    *
	db 0C1h
	db 12h
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db 18h
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db         2Ah    *
	db 0C1h
	db 1Eh
	db 0C1h
	db         24h    $
	db 0C1h
L_01ee:
	POP        BP
	RET        2h
	; Func
F_012a ENDP
F_01f2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JNZ        L_0207
	JMP        L_028e
L_0207:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_7af4
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1fh
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,13h
	JNZ        L_024e
	MOV        AX,8606h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,28h
	PUSH       AX
	MOV        AX,0bb8h
	PUSH       AX
	MOV        AX,1f4h
	PUSH       AX
	CALL       SUB_0000_62bc
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],50h
	MOV        byte ptr DS:[0a9fah],1h
	JMP        L_02e4
L_024e:
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_6112
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JZ         L_0272
	CMP        AX,1h
	JZ         L_027c
	CMP        AX,2h
	JZ         L_0282
	CMP        AX,3h
	JZ         L_0288
	JMP        L_02e4
L_0272:
	MOV        AX,8610h
L_0275:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_02e4
	db 90h
L_027c:
	MOV        AX,861ah
	JMP        L_0275
	db 90h
L_0282:
	MOV        AX,8622h
	JMP        L_0275
	db 90h
L_0288:
	MOV        AX,862ah
	JMP        L_0275
	db 90h
L_028e:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_6112
	OR         AX,AX
	JNZ        L_02ae
	MOV        AX,863ah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,0fh
	JMP        L_02be
L_02ae:
	MOV        AX,8642h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,2h
L_02be:
	MOV        byte ptr [SI + 5c5bh],AL
	MOV        byte ptr [SI + 5c5ah],AL
	MOV        AX,1h
	PUSH       AX
	MOV        AX,3h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c5fh],AL
	OR         byte ptr DS:[24e6h],2h
	CALL       SUB_0000_9990
L_02e4:
	POP        SI
	POP        BP
	RET        4h
	db 90h
	; Func
F_01f2 ENDP
F_02ea PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	TEST       byte ptr [BP + -2h],80h
	JNZ        L_0318
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b6h]
	SUB        AX,1eh
	NEG        AX
	JMP        L_0330
L_0318:
	MOV        AX,word ptr [BP + -2h]
	AND        AX,7fh
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        CL,byte ptr [BX + 55b6h]
	SUB        CH,CH
	SUB        AX,CX
	ADD        AX,1eh
L_0330:
	SHR        AX,1h
	MOV        word ptr [BP + -6h],AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,word ptr [BP + -6h]
	JL         L_034c
	MOV        word ptr [BP + -4h],1h
	JMP        L_0351
L_034c:
	MOV        word ptr [BP + -4h],0h
L_0351:
	CMP        word ptr [BP + -4h],0h
	JZ         L_035d
	TEST       byte ptr [BP + -2h],80h
	JZ         L_0369
L_035d:
	CMP        word ptr [BP + -4h],0h
	JNZ        L_036e
	TEST       byte ptr [BP + -2h],80h
	JZ         L_036e
L_0369:
	MOV        AX,864ah
	JMP        L_039d
L_036e:
	MOV        AX,word ptr [BP + -2h]
	AND        AX,7fh
	MOV        word ptr [BP + -6h],AX
	CMP        word ptr [BP + -4h],0h
	JZ         L_0388
	CMP        AX,0ah
	JGE        L_0388
	MOV        AX,8654h
	JMP        L_039d
	db 90h
L_0388:
	CMP        word ptr [BP + -4h],0h
	JZ         L_039a
	CMP        word ptr [BP + -6h],14h
	JLE        L_039a
	MOV        AX,8664h
	JMP        L_039d
	db 90h
L_039a:
	MOV        AX,8676h
L_039d:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_02ea ENDP
F_03a8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],8h
L_03b5:
	DEC        word ptr [BP + -4h]
	JNS        L_03bd
	JMP        L_0450
L_03bd:
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [BX + 5830h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 8h]
	JNZ        L_03b5
	MOV        AL,byte ptr [BX + 5838h]
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_03b5
	MOV        AL,byte ptr [BX + 5848h]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_03b5
	MOV        AL,DS:[5893h]
	CMP        byte ptr [BX + 5840h],AL
	JNZ        L_03b5
	SUB        DI,DI
	MOV        SI,20h
	JMP        L_0415
	db 90h
L_03ee:
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_770e
	CMP        AX,19h
	JNZ        L_0415
	MOV        BX,word ptr DS:[5876h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -4h]
	JNZ        L_0415
	MOV        DI,1h
L_0415:
	DEC        SI
	JNS        L_03ee
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -6h],SI
	OR         DI,DI
	JNZ        L_03b5
	CALL       SUB_0000_7964
	MOV        word ptr [BP + -8h],AX
	MOV        AX,19h
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_7af4
	MOV        AX,8680h
	PUSH       AX
	CALL       SUB_0000_58d0
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,1h
	JMP        L_0452
L_0450:
	SUB        AX,AX
L_0452:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_03a8 ENDP
F_045a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	SUB        SI,SI
	MOV        word ptr [BP + -8h],3e72h
	MOV        DI,word ptr [BP + -2h]
L_046c:
	MOV        AL,byte ptr [SI + 3e66h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_04f6
	MOV        AL,byte ptr [SI + 3e6ah]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_04f6
	CMP        byte ptr DS:[587fh],AH
	JNZ        L_04f6
	MOV        AL,DS:[587eh]
	CMP        byte ptr [SI + 5858h],AL
	JZ         L_04f6
	MOV        byte ptr [SI + 5858h],AL
	MOV        AL,byte ptr [SI + 3e6eh]
	MOV        word ptr [BP + -4h],AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        DI,AX
	MOV        BX,word ptr [BP + -4h]
	ADD        byte ptr [BX + 5850h],AL
	CMP        byte ptr [BX + 5850h],63h
	JBE        L_04ba
	MOV        byte ptr [BX + 5850h],63h
L_04ba:
	CMP        DI,0ah
	JGE        L_04c8
	PUSH       DI
	MOV        AX,1h
	JMP        L_04cc
	db 90h
	db 90h
	db 90h
L_04c8:
	PUSH       DI
	MOV        AX,2h
L_04cc:
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_5abe
	MOV        AX,86beh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + -8h]
	PUSH       word ptr [BX]
	CALL       SUB_0000_58d0
	MOV        AX,86cah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,1h
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -6h],SI
	JMP        L_050b
	db 90h
L_04f6:
	ADD        word ptr [BP + -8h],2h
	INC        SI
	CMP        SI,3h
	JGE        L_0503
	JMP        L_046c
L_0503:
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -6h],SI
	SUB        AX,AX
L_050b:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_045a ENDP
F_0514 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	SUB        SI,SI
	MOV        DI,word ptr [BP + -6h]
L_0526:
	MOV        AL,DS:[5893h]
	CMP        byte ptr [SI + 3f5ch],AL
	JZ         L_0532
	JMP        L_062a
L_0532:
	MOV        AL,DS:[5895h]
	CMP        byte ptr [SI + 3fceh],AL
	JZ         L_053e
	JMP        L_062a
L_053e:
	MOV        AL,byte ptr [SI + 4040h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 6h]
	JZ         L_054c
	JMP        L_062a
L_054c:
	MOV        AL,byte ptr [SI + 40b2h]
	CMP        AX,word ptr [BP + 4h]
	JZ         L_0558
	JMP        L_062a
L_0558:
	CMP        SI,0dh
	JNZ        L_0574
	CMP        byte ptr DS:[57ach],AH
	JNZ        L_0574
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JZ         L_05a1
L_0574:
	CMP        SI,0eh
	JNZ        L_0582
	MOV        AL,DS:[57b2h]
	CMP        byte ptr DS:[587eh],AL
	JNZ        L_05a1
L_0582:
	CMP        SI,0fh
	JNZ        L_05f6
	CMP        byte ptr DS:[57e7h],0h
	JNZ        L_05f6
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JNZ        L_05f6
L_05a1:
	MOV        word ptr [BP + -8h],1h
L_05a6:
	MOV        word ptr [BP + -6h],DI
	MOV        word ptr [BP + -2h],SI
	CMP        SI,0eh
	JNZ        L_05b7
	MOV        AL,DS:[587eh]
	MOV        DS:[57b2h],AL
L_05b7:
	CMP        word ptr [BP + -8h],0h
	JZ         L_0636
	CALL       SUB_0000_7964
	MOV        word ptr [BP + -4h],AX
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 3e78h]
	SUB        AH,AH
	MOV        SI,AX
	PUSH       SI
	PUSH       SI
	MOV        AL,byte ptr [BX + 4040h]
	PUSH       AX
	MOV        AL,byte ptr [BX + 40b2h]
	PUSH       AX
	MOV        AL,byte ptr [BX + 3fceh]
	PUSH       AX
	MOV        AL,byte ptr [BX + 3eeah]
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_7af4
	OR         byte ptr DS:[24e6h],2h
	PUSH       SI
	CALL       F_012a
	JMP        L_063d
	db 90h
L_05f6:
	MOV        DI,1h
	MOV        CX,SI
	AND        CL,7h
	SHL        DI,CL
	MOV        BX,SI
	MOV        CL,3h
	SAR        BX,CL
	MOV        AL,byte ptr [BX + 585ch]
	SUB        AH,AH
	TEST       DI,AX
	JNZ        L_062a
	CMP        SI,0dh
	JL         L_061a
	CMP        SI,0fh
	JLE        L_062a
L_061a:
	MOV        BX,SI
	MOV        CL,3h
	SAR        BX,CL
	MOV        AX,DI
	OR         byte ptr [BX + 585ch],AL
	JMP        L_05a1
	db 90h
L_062a:
	INC        SI
	CMP        SI,71h
	JL         L_0633
	JMP        L_05a6
L_0633:
	JMP        L_0526
L_0636:
	MOV        AX,86cch
	PUSH       AX
	CALL       SUB_0000_58d0
L_063d:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0514 ENDP
F_0646 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -0eh],AX
	INC        AX
	JNZ        L_065a
	JMP        L_0956
L_065a:
	CMP        byte ptr DS:[58a7h],0h
	JNZ        L_0672
	CMP        byte ptr DS:[58a6h],0h
	JNZ        L_0672
	MOV        AX,86deh
L_066b:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0956
L_0672:
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_006c
	OR         AX,AX
	JNZ        L_0682
	JMP        L_0956
L_0682:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -8h],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        DI,word ptr [BP + -0ah]
	AND        DI,7h
	MOV        CL,3h
	SHL        DI,CL
	MOV        AX,word ptr [BP + -8h]
	AND        AX,7h
	ADD        DI,AX
	MOV        BX,SI
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + DI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	MOV        BX,word ptr [BP + -0eh]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b5h]
	MOV        word ptr [BP + -2h],AX
	MOV        AX,SI
	SHL        AX,1h
	SUB        AX,word ptr [BP + -2h]
	ADD        AX,1eh
	SHR        AX,1h
	MOV        word ptr [BP + -4h],AX
	MOV        AX,86f4h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + -0ch]
	AND        AX,0f0h
	CMP        AX,70h
	JNZ        L_06e9
	JMP        L_0808
L_06e9:
	JLE        L_06ee
	JMP        L_0918
L_06ee:
	CMP        AX,20h
	JZ         L_070a
	JLE        L_06f8
	JMP        L_08f6
L_06f8:
	OR         AX,AX
	JZ         L_0704
	CMP        AX,10h
	JZ         L_070a
	JMP        L_0956
L_0704:
	MOV        AX,8700h
	JMP        L_066b
L_070a:
	MOV        AX,8712h
	JMP        L_066b
L_0710:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,word ptr [BP + -4h]
	JLE        L_0734
	CMP        word ptr [BP + -0ch],40h
	JNZ        L_072c
	MOV        AX,8732h
	JMP        L_066b
L_072c:
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	JMP        L_073f
	db 90h
L_0734:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,8h
	PUSH       AX
	CALL       SUB_0000_6112
L_073f:
	MOV        word ptr [BP + -6h],AX
	CMP        AX,4h
	JGE        L_074e
	MOV        AX,873ch
	JMP        L_066b
	db 90h
L_074e:
	CMP        word ptr [BP + -6h],7h
	JL         L_075a
	MOV        AX,874ch
	JMP        L_066b
L_075a:
	MOV        AX,875ch
	JMP        L_066b
L_0760:
	MOV        AX,8764h
	JMP        L_066b
L_0766:
	MOV        AX,word ptr [BP + -0ch]
	CMP        AX,60h
	JZ         L_077c
	CMP        AX,61h
	JZ         L_0782
	CMP        AX,62h
	JZ         L_07c6
	JMP        L_0956
	db 90h
L_077c:
	MOV        AX,8786h
	JMP        L_066b
L_0782:
	MOV        AX,87a2h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,6h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -0ah]
	AND        AX,7h
	MOV        CL,3h
	SHL        AX,CL
	MOV        CX,word ptr [BP + -8h]
	AND        CX,7h
	ADD        AX,CX
	ADD        SI,AX
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,8h
	ADD        AL,60h
	MOV        byte ptr [SI + 595ah],AL
	CMP        byte ptr DS:[5895h],7h
	JC         L_07be
	JMP        L_089e
L_07be:
	OR         byte ptr [SI + 599ah],8h
	JMP        L_089e
L_07c6:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,word ptr [BP + -4h]
	JLE        L_0802
	MOV        AX,87aah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + -0ah]
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -8h]
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	AND        byte ptr [BX + SI + 595ah],8h
	JMP        L_0956
L_0802:
	MOV        AX,87b8h
	JMP        L_066b
L_0808:
	MOV        AX,87cah
	JMP        L_066b
L_080e:
	MOV        AX,word ptr [BP + -0ch]
	CMP        AX,80h
	JZ         L_082c
	CMP        AX,81h
	JZ         L_0832
	CMP        AX,82h
	JZ         L_0838
	CMP        AX,83h
	JZ         L_083e
	MOV        AX,8822h
	JMP        L_066b
	db 90h
L_082c:
	MOV        AX,87d6h
	JMP        L_066b
L_0832:
	MOV        AX,87e6h
	JMP        L_066b
L_0838:
	MOV        AX,87fch
	JMP        L_066b
L_083e:
	MOV        AX,880eh
	JMP        L_066b
L_0844:
	MOV        AX,8834h
	JMP        L_066b
L_084a:
	MOV        AX,884eh
	JMP        L_066b
L_0850:
	MOV        AX,886ch
	JMP        L_066b
L_0856:
	MOV        AL,DS:[6604h]
	SUB        AH,AH
	AND        AX,0fh
	CMP        AX,1h
	JZ         L_08bc
	CMP        AX,2h
	JZ         L_08b6
	MOV        AX,88c8h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,88eah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + -0ah]
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -8h]
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,8h
	SUB        AL,50h
L_089a:
	MOV        byte ptr [BX + SI + 595ah],AL
L_089e:
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_bcd6
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_4fc6
	JMP        L_0956
	db 90h
L_08b6:
	MOV        AX,888ah
	JMP        L_066b
L_08bc:
	MOV        AX,88ach
	JMP        L_066b
L_08c2:
	MOV        AX,88feh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + -0ah]
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -8h]
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,8h
	SUB        AL,20h
	JMP        L_089a
	db 90h
L_08f0:
	MOV        AX,890eh
	JMP        L_066b
L_08f6:
	CMP        AX,30h
	JNZ        L_08fe
	JMP        L_070a
L_08fe:
	CMP        AX,40h
	JNZ        L_0906
	JMP        L_0710
L_0906:
	CMP        AX,50h
	JNZ        L_090e
	JMP        L_0760
L_090e:
	CMP        AX,60h
	JNZ        L_0916
	JMP        L_0766
L_0916:
	JMP        L_0956
L_0918:
	CMP        AX,0b0h
	JNZ        L_0920
	JMP        L_0850
L_0920:
	JG         L_093c
	CMP        AX,80h
	JNZ        L_092a
	JMP        L_080e
L_092a:
	CMP        AX,90h
	JNZ        L_0932
	JMP        L_0844
L_0932:
	CMP        AX,0a0h
	JNZ        L_093a
	JMP        L_084a
L_093a:
	JMP        L_0956
L_093c:
	CMP        AX,0c0h
	JNZ        L_0944
	JMP        L_0856
L_0944:
	CMP        AX,0d0h
	JNZ        L_094c
	JMP        L_08c2
L_094c:
	CMP        AX,0e0h
	JZ         L_08f0
	CMP        AX,0f0h
	JZ         L_08f0
L_0956:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0646 ENDP
F_095c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h
	CMP        byte ptr DS:[5893h],20h
	JBE        L_097e
	CMP        byte ptr DS:[5893h],29h
	JNC        L_097e
	CALL       F_0646
	JMP        L_0ba4
	db 90h
L_097e:
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_0988
	JMP        L_0ba4
L_0988:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	MOV        word ptr [BP + -8h],AX
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	MOV        word ptr [BP + -0ah],AX
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -0ch],AX
	INC        AX
	JNZ        L_09ac
	JMP        L_0ba4
L_09ac:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -0eh],AX
	MOV        word ptr [BP + -4h],1h
	MOV        DI,5c64h
	MOV        word ptr [BP + -12h],5c65h
	MOV        word ptr [BP + -14h],5c66h
	MOV        SI,5c62h
	MOV        DX,word ptr [BP + -6h]
	MOV        CX,word ptr [BP + -4h]
L_09d9:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JNZ        L_0a26
	MOV        BX,word ptr [BP + -12h]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + -0ah]
	JNZ        L_0a26
	CMP        byte ptr DS:[5893h],7fh
	JA         L_09fd
	MOV        BX,word ptr [BP + -14h]
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX],AL
	JNZ        L_0a26
L_09fd:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	MOV        DX,AX
	CMP        DX,1h
	JNZ        L_0a26
L_0a08:
	MOV        word ptr [BP + -6h],DX
	MOV        word ptr [BP + -4h],CX
	CMP        CX,20h
	JGE        L_0a3e
	MOV        AX,892ch
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -0ch]
	CALL       F_02ea
	JMP        L_0ba4
L_0a26:
	ADD        DI,8h
	ADD        word ptr [BP + -12h],8h
	ADD        word ptr [BP + -14h],8h
	ADD        SI,8h
	INC        CX
	CMP        SI,5d5ah
	JNC        L_0a08
	JMP        L_09d9
	db 90h
L_0a3e:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_7782
	MOV        word ptr [BP + -6h],AX
	CMP        AX,1fh
	JNZ        L_0a6a
	MOV        AX,893eh
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr DS:[5876h]
	PUSH       word ptr [BP + -0ch]
	CALL       F_01f2
	JMP        L_0ba4
	db 90h
L_0a6a:
	MOV        AX,word ptr [BP + -0eh]
	CMP        AX,0a5h
	JZ         L_0a9e
	JG         L_0aee
	CMP        AX,4fh
	JZ         L_0ace
	JG         L_0ad4
	CMP        AX,2bh
	JNZ        L_0ae8
	MOV        AX,8950h
L_0a83:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0b2c
	db 90h
	db 90h
L_0a8c:
	MOV        AX,8960h
	JMP        L_0a83
	db 90h
L_0a92:
	MOV        AX,8970h
	JMP        L_0a83
	db 90h
L_0a98:
	MOV        AX,8984h
	JMP        L_0a83
	db 90h
L_0a9e:
	MOV        AX,8996h
	JMP        L_0a83
	db 90h
	db 0B8h
	db 0A6h
	db 89h
	db 0EBh
	db 0DAh
	db 90h
	db 0B8h
	db 0B8h
	db 89h
	db 0EBh
	db 0D4h
	db 90h
	db 0B8h
	db 0CAh
	db 89h
	db 0EBh
	db 0CEh
	db 90h
	db 0B8h
	db 0DCh
	db 89h
	db 0EBh
	db 0C8h
	db 90h
	db 0B8h
	db 0EEh
	db 89h
	db 0EBh
	db 0C2h
	db 90h
	db 0B8h
	db 0FEh
	db 89h
	db 0EBh
	db 0BCh
	db 90h
	db 0B8h
	db 12h
	db 8Ah
	db 0EBh
	db 0B6h
	db 90h
L_0ace:
	MOV        AX,8a24h
	JMP        L_0a83
	db 90h
L_0ad4:
	CMP        AX,5ah
	JZ         L_0a8c
	CMP        AX,5ch
	JL         L_0ae8
	CMP        AX,5dh
	JLE        L_0a92
	CMP        AX,0a1h
	JZ         L_0a98
L_0ae8:
	MOV        AX,8a34h
	JMP        L_0a83
	db 90h
L_0aee:
	SUB        AX,0a6h
	CMP        AX,16h
	JA         L_0ae8
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0ca7eh]
	db         24h    $
	db 0CAh
	db 68h
	db 0CAh
	db         2Ah    *
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db         30h    0
	db 0CAh
	db         30h    0
	db 0CAh
	db         36h    6
	db 0CAh
	db 68h
	db 0CAh
	db         3Ch    <
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db         48h    H
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db 68h
	db 0CAh
	db         42h    B
	db 0CAh
L_0b2c:
	MOV        AX,8a38h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        word ptr [BP + -0eh],4eh
	JNZ        L_0b6e
	MOV        AX,8a48h
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        byte ptr DS:[5895h],80h
	JNC        L_0b58
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],0b9h
	JMP        L_0b66
	db 90h
L_0b58:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],0b8h
L_0b66:
	OR         byte ptr DS:[24e6h],2h
	JMP        L_0ba4
	db 90h
L_0b6e:
	CMP        word ptr [BP + -0eh],0dch
	JZ         L_0b8b
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_03a8
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JNZ        L_0ba4
L_0b8b:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	CALL       F_045a
	MOV        word ptr [BP + -2h],AX
	OR         AX,AX
	JNZ        L_0ba4
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ah]
	CALL       F_0514
L_0ba4:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_095c ENDP
F_0baa PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -6h],AX
	INC        AX
	JZ         L_0c38
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,80h
	JNC        L_0bd2
	MOV        AX,8a58h
	JMP        L_0c1d
	db 90h
	db 90h
L_0bd2:
	MOV        AL,byte ptr [BP + -2h]
	SUB        AH,AH
	AND        AX,7fh
	MOV        BX,word ptr [BP + -6h]
	MOV        CL,5h
	SHL        BX,CL
	MOV        CL,byte ptr [BX + 55b5h]
	SUB        CH,CH
	SUB        AX,CX
	ADD        AX,1eh
	SHR        AX,1h
	MOV        byte ptr [BP + -4h],AL
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        CL,byte ptr [BP + -4h]
	SUB        CH,CH
	CMP        AX,CX
	JBE        L_0c1a
	MOV        AX,8a64h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        BX,CL
	AND        byte ptr [BX + 5c5fh],7fh
	JMP        L_0c38
L_0c1a:
	MOV        AX,8a6eh
L_0c1d:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,320h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	CALL       SUB_0000_842e
	DEC        byte ptr DS:[57ach]
L_0c38:
	MOV        SP,BP
	POP        BP
	RET        8h
	; Func
F_0baa ENDP
F_0c3e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        AX,8a7ah
	PUSH       AX
	CALL       SUB_0000_58d0
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -0ah],AX
	INC        AX
	JNZ        L_0c59
	JMP        L_0d43
L_0c59:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -8h],AX
	MOV        AL,DS:[5895h]
	MOV        SI,AX
	MOV        DI,word ptr [BP + -8h]
	AND        DI,7h
	MOV        CL,3h
	SHL        DI,CL
	MOV        AX,word ptr [BP + -6h]
	AND        AX,7h
	ADD        DI,AX
	MOV        BX,SI
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + DI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -0ch],AX
	MOV        BX,word ptr [BP + -0ah]
	MOV        CL,5h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 55b5h]
	MOV        word ptr [BP + -2h],AX
	MOV        AX,SI
	SHL        AX,1h
	SUB        AX,word ptr [BP + -2h]
	ADD        AX,1eh
	SHR        AX,1h
	MOV        word ptr [BP + -4h],AX
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,0f7h
	CMP        AL,40h
	JNZ        L_0cd0
	CMP        byte ptr DS:[57ach],0h
	JNZ        L_0cc2
	MOV        AX,8a7ch
	JMP        L_0d3f
	db 90h
	db 90h
L_0cc2:
	MOV        AX,8a86h
L_0cc5:
	PUSH       AX
	CALL       SUB_0000_58d0
	DEC        byte ptr DS:[57ach]
	JMP        L_0d43
	db 90h
L_0cd0:
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,0f0h
	CMP        AL,40h
	JNZ        L_0d2e
	CMP        byte ptr DS:[57ach],0h
	JNZ        L_0ce6
	MOV        AX,8a92h
	JMP        L_0d3f
	db 90h
L_0ce6:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	CMP        AX,word ptr [BP + -4h]
	JLE        L_0d28
	MOV        AX,8a9ch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr [BP + -8h]
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -6h]
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,8h
	ADD        AL,40h
	MOV        byte ptr [BX + SI + 595ah],AL
	JMP        L_0d43
	db 90h
L_0d28:
	MOV        AX,8aach
	JMP        L_0cc5
	db 90h
L_0d2e:
	MOV        AL,byte ptr [BP + -0ch]
	AND        AL,0f0h
	CMP        AL,70h
	JNZ        L_0d3c
	MOV        AX,8ab8h
	JMP        L_0d3f
L_0d3c:
	MOV        AX,8ac8h
L_0d3f:
	PUSH       AX
	CALL       SUB_0000_58d0
L_0d43:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0c3e ENDP
F_0d4a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,12h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],20h
	JBE        L_0d66
	CMP        byte ptr DS:[5893h],29h
	JNC        L_0d66
	CALL       F_0c3e
	JMP        L_0f81
L_0d66:
	CMP        byte ptr DS:[57ach],0h
	JNZ        L_0d78
	MOV        AX,8ad0h
L_0d70:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_0f81
	db 90h
L_0d78:
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_0d82
	JMP        L_0f81
L_0d82:
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
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	CMP        AX,98h
	JLE        L_0db2
	JMP        L_0f1c
L_0db2:
	CMP        AX,97h
	JGE        L_0e1c
	CMP        AX,84h
	JGE        L_0dbf
	JMP        L_0f2c
L_0dbf:
	CMP        AX,85h
	JLE        L_0e22
	JMP        L_0f2c
	db 90h
L_0dc8:
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -0ah],AX
	INC        AX
	JNZ        L_0dd4
	JMP        L_0f81
L_0dd4:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1dh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        BX,word ptr [BP + -0ah]
	MOV        CL,5h
	SHL        BX,CL
	MOV        CL,byte ptr [BX + 55b5h]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_0dfe
	MOV        AX,8adah
L_0df2:
	PUSH       AX
	CALL       SUB_0000_58d0
	DEC        byte ptr DS:[57ach]
	JMP        L_0f81
	db 90h
L_0dfe:
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BP + -4h]
	DEC        AL
	MOV        byte ptr [BX],AL
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,8ae6h
	JMP        L_0d70
	db 90h
L_0e1c:
	MOV        AX,8af2h
	JMP        L_0df2
	db 90h
L_0e22:
	CMP        byte ptr DS:[5893h],80h
	JNC        L_0e42
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_770e
	OR         AX,AX
	JNZ        L_0e42
	MOV        AX,8afeh
	JMP        L_0d70
L_0e42:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -2h],AX
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -0ah],AX
	INC        AX
	JNZ        L_0e54
	JMP        L_0f81
L_0e54:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,1dh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        BX,word ptr [BP + -0ah]
	MOV        CL,5h
	SHL        BX,CL
	MOV        CL,byte ptr [BX + 55b5h]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_0e76
	MOV        AX,8b10h
	JMP        L_0df2
	db 90h
L_0e76:
	CMP        byte ptr DS:[5893h],7fh
	JNC        L_0ee4
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_bb9e
	MOV        word ptr [BP + -2h],AX
	INC        AX
	JNZ        L_0e90
	MOV        AX,8b1ch
	JMP        L_0d70
	db 90h
L_0e90:
	MOV        SI,word ptr [BP + -2h]
	MOV        CL,4h
	SHL        SI,CL
	ADD        SI,5f68h
	CMP        word ptr [SI],0h
	JZ         L_0ea4
	MOV        word ptr [SI],0h
L_0ea4:
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_bb7a
	OR         AX,AX
	JNZ        L_0eda
	MOV        SI,word ptr [BP + -2h]
	MOV        CL,4h
	SHL        SI,CL
	MOV        byte ptr [SI + 5d5eh],5h
	MOV        byte ptr [SI + 5d5fh],5h
	MOV        byte ptr [SI + 5d60h],5h
	MOV        AX,8b36h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,5888h
	PUSH       AX
	MOV        AX,2h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
L_0eda:
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_bb86
	JMP        L_0f81
	db 90h
L_0ee4:
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],44h
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,8b48h
	JMP        L_0d70
	db 90h
L_0efe:
	ADD        DI,8h
	ADD        word ptr [BP + -0eh],8h
	ADD        word ptr [BP + -10h],8h
	ADD        SI,8h
	INC        CX
	CMP        SI,5d5ah
	JNC        L_0f69
	JMP        L_0f43
	db 90h
L_0f16:
	MOV        AX,8b52h
	JMP        L_0d70
L_0f1c:
	CMP        AX,0b9h
	JNZ        L_0f24
	JMP        L_0dc8
L_0f24:
	CMP        AX,0bbh
	JNZ        L_0f2c
	JMP        L_0dc8
L_0f2c:
	MOV        CX,1h
	MOV        DI,5c64h
	MOV        word ptr [BP + -0eh],5c65h
	MOV        word ptr [BP + -10h],5c66h
	MOV        SI,5c62h
	MOV        DL,byte ptr DS:[5895h]
L_0f43:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -6h]
	JNZ        L_0efe
	MOV        BX,word ptr [BP + -0eh]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + -8h]
	JNZ        L_0efe
	CMP        byte ptr DS:[5893h],7fh
	JA         L_0f64
	MOV        BX,word ptr [BP + -10h]
	CMP        byte ptr [BX],DL
	JNZ        L_0efe
L_0f64:
	CMP        byte ptr [SI],1h
	JNZ        L_0efe
L_0f69:
	MOV        word ptr [BP + -4h],CX
	CMP        CX,20h
	JGE        L_0f16
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	PUSH       CX
	CALL       F_0baa
L_0f81:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0d4a ENDP
F_0f88 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	CMP        word ptr [BP + 10h],3h
	JZ         L_0f9b
	CMP        word ptr [BP + 10h],4h
	JNZ        L_0f9e
L_0f9b:
	DEC        word ptr [BP + 0eh]
L_0f9e:
	CMP        word ptr [BP + 10h],1h
	JNZ        L_0fb0
	MOV        AX,1h
	PUSH       AX
	PUSH       word ptr [BP + 6h]
L_0fab:
	CALL       SUB_0000_6112
	JMP        L_0fc9
L_0fb0:
	CMP        word ptr [BP + 10h],2h
	JNZ        L_0fc6
	MOV        AX,1h
	PUSH       AX
	MOV        AX,word ptr [BP + 6h]
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	PUSH       AX
	JMP        L_0fab
L_0fc6:
	MOV        AX,word ptr [BP + 0eh]
L_0fc9:
	MOV        word ptr [BP + -2h],AX
	CALL       F_0000
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JZ         L_1038
	PUSH       word ptr [BP + 10h]
	PUSH       word ptr [BP + 10h]
	PUSH       word ptr [BP + 0ch]
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + -2h]
	PUSH       AX
	CALL       SUB_0000_7af4
	CMP        byte ptr DS:[5893h],80h
	JNC        L_1008
	MOV        SI,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        byte ptr [SI + 5c61h],0h
	MOV        AL,byte ptr [BP + 8h]
	MOV        byte ptr [SI + 5c5eh],AL
	JMP        L_1014
L_1008:
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        byte ptr [BX + 5c61h],20h
L_1014:
	OR         byte ptr DS:[24e6h],2h
	CALL       SUB_0000_9990
	MOV        BX,word ptr [BP + 4h]
	CMP        word ptr [BX],0h
	JNZ        L_1032
	MOV        AX,8b5ch
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + 4h]
	MOV        word ptr [BX],1h
L_1032:
	PUSH       word ptr [BP + 10h]
	CALL       F_012a
L_1038:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        0eh
	db 90h
	; Func
F_0f88 ENDP
F_1040 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        SI,8h
	MOV        DI,word ptr [BP + -2h]
	JMP        L_107a
L_1050:
	MOV        AX,1h
	PUSH       AX
	MOV        AL,byte ptr [SI + 4134h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        DI,AX
L_1060:
	MOV        AL,byte ptr [SI + 4124h]
	SUB        AH,AH
	PUSH       AX
	PUSH       DI
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 0ch]
	PUSH       word ptr [BP + 4h]
	CALL       F_0f88
L_107a:
	DEC        SI
	JS         L_10aa
	MOV        AL,byte ptr [SI + 412ch]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 0ch]
	JA         L_107a
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        CL,byte ptr [SI + 412ch]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_107a
	CMP        byte ptr [SI + 4134h],1h
	JNZ        L_1050
	MOV        DI,1h
	JMP        L_1060
	db 90h
L_10aa:
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -4h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ah
	; Func
F_1040 ENDP
F_10b8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	MOV        AX,word ptr [BP + 0ch]
	CWD
	SUB        AX,DX
	SAR        AX,1h
	MOV        word ptr [BP + -2h],AX
	MOV        DI,word ptr [BP + 0ch]
	MOV        SI,word ptr [BP + -4h]
	JMP        L_1117
	db 90h
L_10d4:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,2fh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        SI,AX
	MOV        AL,byte ptr [SI + 416ch]
	SUB        AH,AH
	CMP        AX,DI
	JA         L_1117
	MOV        AX,1h
	PUSH       AX
	MOV        AX,1eh
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        CL,byte ptr [SI + 416ch]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_1117
	MOV        AL,byte ptr [SI + 413ch]
	SUB        AH,AH
	PUSH       AX
	PUSH       SI
	PUSH       word ptr [BP + 0ah]
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       DI
	PUSH       word ptr [BP + 4h]
	CALL       F_0f88
L_1117:
	MOV        AX,word ptr [BP + -2h]
	DEC        word ptr [BP + -2h]
	OR         AX,AX
	JGE        L_10d4
	MOV        word ptr [BP + -4h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        0ah
	; Func
F_10b8 ENDP
F_112c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,14h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        word ptr [BP + -4h],1h
	MOV        DI,5c64h
	MOV        word ptr [BP + -0eh],5c65h
	MOV        word ptr [BP + -10h],5c66h
	MOV        word ptr [BP + -12h],5c62h
	MOV        SI,5c62h
L_1153:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 8h]
	JNZ        L_119e
	MOV        BX,word ptr [BP + -0eh]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + 6h]
	JNZ        L_119e
	CMP        byte ptr DS:[5893h],7fh
	JA         L_117e
	CMP        byte ptr DS:[5893h],80h
	JNC        L_119e
	MOV        BX,word ptr [BP + -10h]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_119e
L_117e:
	MOV        BX,word ptr [BP + -12h]
	CMP        byte ptr [BX],1h
	JNZ        L_1192
L_1186:
	CMP        word ptr [BP + -4h],20h
	JNZ        L_11bc
	MOV        AX,8b6ch
	JMP        L_12c8
L_1192:
	CMP        byte ptr [SI],0eh
	JNZ        L_119e
	MOV        AX,8b64h
	JMP        L_12c8
	db 90h
L_119e:
	ADD        DI,8h
	ADD        word ptr [BP + -0eh],8h
	ADD        word ptr [BP + -10h],8h
	ADD        word ptr [BP + -12h],8h
	ADD        SI,8h
	INC        word ptr [BP + -4h]
	CMP        SI,5d5ah
	JNC        L_1186
	JMP        L_1153
	db 90h
L_11bc:
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -0ah],AX
	INC        AX
	JNZ        L_11c8
	JMP        L_12cc
L_11c8:
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	MOV        byte ptr [BP + -6h],AL
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
	CMP        byte ptr DS:[5893h],1h
	JC         L_120b
	CMP        byte ptr DS:[5893h],20h
	JA         L_120b
	CMP        byte ptr DS:[5888h],2h
	JBE        L_1206
	SUB        byte ptr DS:[5888h],2h
	JMP        L_120b
	db 90h
L_1206:
	MOV        byte ptr DS:[5888h],0h
L_120b:
	CMP        byte ptr [BP + -6h],7fh
	JA         L_1214
	JMP        L_1296
L_1214:
	AND        byte ptr [BP + -6h],7fh
	MOV        AX,8b7eh
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + -0ah]
	CALL       SUB_0000_7050
	CMP        byte ptr DS:[5893h],7fh
	JBE        L_1296
	MOV        BX,word ptr [BP + -0ah]
	MOV        CL,5h
	SHL        BX,CL
	CMP        byte ptr [BX + 55b3h],44h
	JNZ        L_1296
	MOV        word ptr [BP + -4h],0h
	MOV        SI,0ba14h
	MOV        DI,word ptr [BP + -12h]
L_1245:
	MOV        DX,SI
	MOV        BX,DX
	TEST       byte ptr [BX + 2h],80h
	JZ         L_1276
	MOV        AL,byte ptr [BX + 3h]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -0ah]
	JNZ        L_1276
	OR         byte ptr [BX + 2h],20h
	MOV        AL,byte ptr [BX + 4h]
	MOV        DI,AX
	MOV        CL,3h
	SHL        DI,CL
	MOV        AL,1eh
	MOV        byte ptr [DI + 5c5bh],AL
	MOV        byte ptr [DI + 5c5ah],AL
L_1270:
	MOV        word ptr [BP + -2h],DX
	JMP        L_1284
	db 90h
L_1276:
	ADD        SI,8h
	INC        word ptr [BP + -4h]
	CMP        SI,0bb14h
	JNC        L_1270
	JMP        L_1245
L_1284:
	MOV        AL,DS:[587bh]
	SUB        AH,AH
	CMP        word ptr [BP + -0ah],AX
	JNZ        L_1293
	MOV        byte ptr DS:[587bh],0ffh
L_1293:
	CALL       SUB_0000_9990
L_1296:
	MOV        AL,byte ptr [BP + -6h]
	SUB        AH,AH
	MOV        SI,AX
	PUSH       SI
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	LEA        AX,[BP + -8h]
	PUSH       AX
	CALL       F_1040
	PUSH       SI
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	LEA        AX,[BP + -8h]
	PUSH       AX
	CALL       F_10b8
	CMP        word ptr [BP + -8h],0h
	JNZ        L_12cc
	MOV        AX,8b88h
L_12c8:
	PUSH       AX
	CALL       SUB_0000_58d0
L_12cc:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        6h
	; Func
F_112c ENDP
F_12d4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       SI
	MOV        SI,word ptr DS:[5897h]
	AND        SI,0ffh
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -4h],AX
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,0f0h
	CMP        AL,40h
	JNZ        L_135a
	CALL       SUB_0000_8a08
	MOV        word ptr [BP + -2h],AX
	INC        AX
	JZ         L_136f
	TEST       byte ptr [BP + -4h],7h
	JZ         L_1326
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_7050
L_1326:
	MOV        SI,word ptr DS:[5897h]
	AND        SI,0ffh
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,8h
	ADD        AL,70h
	MOV        byte ptr [BX + SI + 595ah],AL
	MOV        AX,8b96h
	JMP        L_136b
L_135a:
	MOV        AL,byte ptr [BP + -4h]
	AND        AL,0f0h
	CMP        AL,70h
	JNZ        L_1368
	MOV        AX,8ba6h
	JMP        L_136b
L_1368:
	MOV        AX,8bb6h
L_136b:
	PUSH       AX
	CALL       SUB_0000_58d0
L_136f:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_12d4 ENDP
F_1374 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	CMP        byte ptr DS:[5893h],20h
	JBE        L_138e
	CMP        byte ptr DS:[5893h],29h
	JNC        L_138e
	CALL       F_12d4
	JMP        L_1453
L_138e:
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
	JNZ        L_13a9
	JMP        L_1453
L_13a9:
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5876h]
	MOV        word ptr [BP + -4h],AX
	MOV        AL,DS:[5897h]
	SUB        AH,AH
	ADD        AX,word ptr DS:[5878h]
	MOV        word ptr [BP + -6h],AX
	PUSH       word ptr [BP + -4h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	CMP        AX,0afh
	JZ         L_13ea
	JG         L_1430
	CMP        AX,97h
	JL         L_1444
	CMP        AX,98h
	JLE        L_13fa
	CMP        AX,99h
	JZ         L_13f4
	JMP        L_1444
	db 90h
L_13ea:
	MOV        AX,8bbeh
L_13ed:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1453
	db 90h
L_13f4:
	MOV        AX,8bcah
	JMP        L_13ed
	db 90h
L_13fa:
	MOV        AX,8bd6h
	JMP        L_13ed
	db 90h
L_1400:
	MOV        AL,byte ptr [BP + -2h]
	MOV        DS:[594fh],AL
	MOV        byte ptr DS:[5952h],4h
	MOV        AL,byte ptr [BP + -4h]
	MOV        DS:[5950h],AL
	MOV        AL,byte ptr [BP + -6h]
	MOV        DS:[5951h],AL
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -6h]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],44h
	MOV        byte ptr DS:[24e6h],1h
	MOV        AX,8be0h
	JMP        L_13ed
	db 90h
L_1430:
	CMP        AX,0b8h
	JZ         L_1400
	CMP        AX,0b9h
	JZ         L_13fa
	CMP        AX,0bah
	JZ         L_1400
	CMP        AX,0bbh
	JZ         L_13fa
L_1444:
	PUSH       word ptr [BP + -4h]
	PUSH       word ptr [BP + -6h]
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	PUSH       AX
	CALL       F_112c
L_1453:
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_1374 ENDP
F_1458 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       SI
	MOV        AX,word ptr [BP + 8h]
	CMP        AX,0ch
	JLE        L_1467
	JMP        L_172e
L_1467:
	CMP        AX,9h
	JL         L_146f
	JMP        L_1670
L_146f:
	SUB        AX,1h
	CMP        AX,7h
	JBE        L_147a
	JMP        L_1750
L_147a:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0d69eh]
	db 0B8h
	db         3Eh    >
	db 8Ch
L_1485:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1798
L_148c:
	MOV        AX,8c4eh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        BX,word ptr [BP + 6h]
	MOV        byte ptr [BX + 5840h],0ffh
	JMP        L_177a
L_149e:
	MOV        AX,8c5ch
	PUSH       AX
	CALL       SUB_0000_58d0
	INC        byte ptr DS:[57b0h]
	CMP        byte ptr DS:[57b0h],64h
	JNZ        L_14b5
	MOV        byte ptr DS:[57b0h],63h
L_14b5:
	CMP        byte ptr DS:[5893h],11h
	JZ         L_14bf
	JMP        L_177a
L_14bf:
	MOV        AX,16h
L_14c2:
	PUSH       AX
	CALL       SUB_0000_bb92
	JMP        L_177a
	db 90h
L_14ca:
	PUSH       word ptr [BP + 6h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_5abe
	MOV        AX,8c6eh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,57a8h
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_7f94
	JMP        L_177a
L_14f0:
	MOV        AX,8c76h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        byte ptr DS:[57bfh],0ffh
	OR         byte ptr DS:[5b9dh],80h
	JMP        L_177a
L_1504:
	PUSH       word ptr [BP + 6h]
	MOV        AX,1h
	PUSH       AX
	MOV        AX,20h
	PUSH       AX
	CALL       SUB_0000_5abe
	MOV        AX,8c8ah
	PUSH       AX
	CALL       SUB_0000_58d0
	CMP        word ptr [BP + 6h],1h
	JNZ        L_1524
	MOV        AX,8c92h
	JMP        L_1527
L_1524:
	MOV        AX,8c96h
L_1527:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,57aeh
	PUSH       AX
	PUSH       word ptr [BP + 6h]
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
	JMP        L_177a
	db 0FFh
	db         76h    v
	db 06h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 20h
	db 00h
	db         50h    P
	db 0E8h
	db         74h    t
	db         45h    E
	db 0B8h
	db 9Ch
	db 8Ch
	db         50h    P
	db 0E8h
	db         7Fh    
	db         43h    C
	db 83h
	db         7Eh    ~
	db 06h
	db 01h
	db         75h    u
	db 05h
	db 0B8h
	db 0A2h
	db 8Ch
	db 0EBh
	db 03h
	db 0B8h
	db 0A6h
	db 8Ch
	db         50h    P
	db 0E8h
	db         6Dh    m
	db         43h    C
	db 0B8h
	db 0ADh
	db         57h    W
	db 0EBh
	db 0C6h
	db 83h
	db         7Eh    ~
	db 06h
	db         7Fh    
	db         7Eh    ~
	db 20h
	db 81h
	db         66h    f
	db 06h
	db         7Fh    
	db 00h
	db 0FFh
	db         76h    v
	db 06h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 20h
	db 00h
	db         50h    P
	db 0E8h
	db 3Dh
	db         45h    E
	db 0B8h
	db 0AAh
	db 8Ch
	db         50h    P
	db 0E8h
	db         48h    H
	db         43h    C
	db 0B8h
	db 0B1h
	db         57h    W
	db 0EBh
	db 19h
	db 90h
	db 0FFh
	db         76h    v
	db 06h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 20h
	db 00h
	db         50h    P
	db 0E8h
	db         22h    "
	db         45h    E
	db 0B8h
	db 0B4h
	db 8Ch
	db         50h    P
	db 0E8h
	db         2Dh    -
	db         43h    C
	db 0B8h
	db 0ACh
	db         57h    W
	db         50h    P
	db 0FFh
	db         76h    v
	db 06h
	db 0B8h
	db         63h    c
	db 00h
	db         50h    P
	db 0E8h
	db 0BFh
	db         69h    i
	db 83h
	db         7Eh    ~
	db 06h
	db 01h
	db         75h    u
	db 05h
	db 0B8h
	db 0BAh
	db 8Ch
	db 0EBh
	db 03h
	db 0B8h
	db 0BEh
	db 8Ch
L_15bf:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_177a
	db 81h
	db         7Eh    ~
	db 06h
	db 0FFh
	db 00h
	db         75h    u
	db 0Fh
	db 0B8h
	db 0C2h
	db 8Ch
	db         50h    P
	db 0E8h
	db 0FCh
	db         42h    B
	db 0C6h
	db 06h
	db 0BBh
	db         57h    W
	db 0FFh
	db 0E9h
	db 9Eh
	db 01h
	db 0B8h
	db 0E0h
	db 8Ch
	db         50h    P
	db 0E8h
	db 0EDh
	db         42h    B
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0E8h
	db         34h    4
	db         47h    G
	db 8Bh
	db         5Eh    ^
	db 06h
	db 81h
	db 0E3h
	db 07h
	db 00h
	db 0D1h
	db 0E3h
	db 0FFh
	db 0B7h
	db 0ACh
	db         41h    A
	db 0E8h
	db 0D6h
	db         42h    B
	db         2Bh    +
	db 0C0h
	db         50h    P
	db 0E8h
	db 1Eh
	db         47h    G
	db 0B8h
	db 0ECh
	db 8Ch
	db         50h    P
	db 0E8h
	db 0C9h
	db         42h    B
	db 8Bh
	db         5Eh    ^
	db 06h
	db 0FEh
	db 87h
	db 20h
	db         58h    X
	db 80h
	db 0BFh
	db 20h
	db         58h    X
	db         64h    d
	db         74h    t
	db 03h
	db 0E9h
	db         62h    b
	db 01h
	db 0C6h
	db 87h
	db 20h
	db         58h    X
	db         63h    c
	db 0E9h
	db         5Ah    Z
	db 01h
	db 0FFh
	db         76h    v
	db 06h
	db 0B8h
	db 01h
	db 00h
	db         50h    P
	db 0B8h
	db 20h
	db 00h
	db         50h    P
	db 0E8h
	db 90h
	db         44h    D
	db 0B8h
	db 0F0h
	db 8Ch
	db         50h    P
	db 0E8h
	db 9Bh
	db         42h    B
	db 0B8h
	db 0AAh
	db         57h    W
	db 0E9h
	db 0A7h
	db 0FEh
	db 90h
	db 0B8h
	db 0F8h
	db 8Ch
	db         50h    P
	db 0E8h
	db 8Dh
	db         42h    B
	db 8Bh
	db         5Eh    ^
	db 06h
	db 0D1h
	db 0E3h
	db 0FFh
	db 0B7h
	db 9Ch
	db         41h    A
	db 0E8h
	db 81h
	db         42h    B
	db 0B8h
	db 0FCh
	db 8Ch
	db         50h    P
	db 0E8h
	db         7Ah    z
	db         42h    B
	db 8Bh
	db         5Eh    ^
	db 06h
	db 0FEh
	db 87h
	db         28h    (
	db         58h    X
	db 80h
	db 0BFh
	db         28h    (
	db         58h    X
	db         64h    d
	db         74h    t
	db 03h
	db 0E9h
	db 13h
	db 01h
	db 0C6h
	db 87h
	db         28h    (
	db         58h    X
	db         63h    c
	db 0E9h
	db 0Bh
	db 01h
	db 90h
L_1670:
	CMP        word ptr [BP + 6h],1bh
	JZ         L_167c
	CMP        word ptr [BP + 6h],1dh
	JNZ        L_1690
L_167c:
	MOV        AX,word ptr [BP + 6h]
	ADD        AX,57c0h
	PUSH       AX
	MOV        AX,5h
	PUSH       AX
	MOV        AX,63h
	PUSH       AX
	CALL       SUB_0000_7f70
	JMP        L_16a3
L_1690:
	MOV        BX,word ptr [BP + 6h]
	INC        byte ptr [BX + 57c0h]
	CMP        byte ptr [BX + 57c0h],64h
	JNZ        L_16a3
	MOV        byte ptr [BX + 57c0h],63h
L_16a3:
	MOV        BX,word ptr [BP + 6h]
	SHL        BX,1h
	PUSH       word ptr [BX + 17f6h]
	CALL       SUB_0000_58d0
	MOV        AX,8d06h
	JMP        L_15bf
	db 90h
L_16b6:
	MOV        SI,word ptr [BP + 6h]
	AND        SI,3h
	MOV        byte ptr [SI + 57b6h],0ffh
	MOV        AX,8d0ah
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,SI
	OR         AX,AX
	JZ         L_16da
	CMP        AX,1h
	JZ         L_16e0
	MOV        AX,8d2eh
	JMP        L_15bf
L_16da:
	MOV        AX,8d18h
	JMP        L_15bf
L_16e0:
	MOV        AX,8d24h
	JMP        L_15bf
L_16e6:
	MOV        byte ptr DS:[57b4h],0ffh
	MOV        AX,8d3ah
	PUSH       AX
	CALL       SUB_0000_58d0
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_bb9e
	PUSH       AX
	CALL       SUB_0000_bb86
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_bb9e
	JMP        L_14c2
	db 90h
L_1706:
	MOV        byte ptr DS:[57b5h],0ffh
	MOV        AX,8d56h
	JMP        L_15bf
	db 90h
L_1712:
	MOV        byte ptr DS:[57b3h],0ffh
	MOV        AX,8d74h
	JMP        L_15bf
	db 90h
	db 02h
	db 0D4h
	db 0A0h
	db 0D5h
	db 0BCh
	db 0D5h
	db         46h    F
	db 0D5h
	db 0F0h
	db 0D5h
	db 0F0h
	db 0D5h
	db 0E8h
	db 0D4h
	db 0BCh
	db 0D4h
L_172e:
	CMP        AX,19h
	JNZ        L_1736
	JMP        L_148c
L_1736:
	JG         L_1756
	CMP        AX,0dh
	JNZ        L_1740
	JMP        L_1504
L_1740:
	CMP        AX,0eh
	JNZ        L_1748
	JMP        L_14f0
L_1748:
	CMP        AX,0fh
	JNZ        L_1750
	JMP        L_14ca
L_1750:
	MOV        AX,8d92h
	JMP        L_1485
L_1756:
	CMP        AX,1bh
	JNZ        L_175e
	JMP        L_149e
L_175e:
	CMP        AX,0b4h
	JNZ        L_1766
	JMP        L_16b6
L_1766:
	CMP        AX,0b5h
	JNZ        L_176e
	JMP        L_16e6
L_176e:
	CMP        AX,0b6h
	JZ         L_1706
	CMP        AX,0b7h
	JZ         L_1712
	JMP        L_1750
L_177a:
	CMP        word ptr [BP + 4h],20h
	JGE        L_178e
	SUB        AX,AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_7af4
L_178e:
	OR         byte ptr DS:[24e6h],2h
	MOV        byte ptr DS:[0a9fah],1h
L_1798:
	POP        SI
	POP        BP
	RET        6h
	db 90h
	; Func
F_1458 ENDP
F_179e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	MOV        AX,8da4h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        SI,word ptr DS:[5897h]
	AND        SI,0ffh
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -8h],AX
	MOV        AL,byte ptr [BP + -8h]
	AND        AL,0f0h
	CMP        AL,40h
	JNZ        L_17ea
	MOV        AX,8daah
	JMP        L_18c3
	db 90h
L_17ea:
	MOV        AL,byte ptr [BP + -8h]
	AND        AL,0f0h
	CMP        AL,70h
	JZ         L_17f6
	JMP        L_18c0
L_17f6:
	MOV        DI,word ptr DS:[5897h]
	AND        DI,0ffh
	AND        DI,7h
	MOV        CL,3h
	SHL        DI,CL
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	AND        AX,7h
	ADD        DI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	AND        byte ptr [BX + DI + 595ah],8h
	MOV        AX,8dbch
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        SI,SI
	MOV        DI,word ptr [BP + -4h]
L_182b:
	MOV        AX,1h
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,4h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        CL,byte ptr [SI + 41bch]
	SUB        CH,CH
	CMP        CX,AX
	JA         L_18ae
	CMP        SI,5h
	JNZ        L_1862
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        DI,AX
	MOV        AX,3h
L_185d:
	PUSH       AX
	PUSH       DI
	JMP        L_18a7
	db 90h
L_1862:
	CMP        SI,6h
	JNZ        L_1878
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        DI,AX
	MOV        AX,4h
	JMP        L_185d
L_1878:
	CMP        SI,1h
	JNZ        L_188c
	MOV        AX,1h
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	JMP        L_1896
L_188c:
	MOV        AX,1h
	PUSH       AX
	MOV        AL,byte ptr [SI + 41c4h]
	SUB        AH,AH
L_1896:
	PUSH       AX
	CALL       SUB_0000_6112
	MOV        word ptr [BP + -2h],AX
	MOV        AL,byte ptr [SI + 41cch]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -2h]
L_18a7:
	MOV        AX,20h
	PUSH       AX
	CALL       F_1458
L_18ae:
	INC        SI
	CMP        SI,7h
	JGE        L_18b7
	JMP        L_182b
L_18b7:
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -6h],SI
	JMP        L_18c7
	db 90h
L_18c0:
	MOV        AX,8ddah
L_18c3:
	PUSH       AX
	CALL       SUB_0000_58d0
L_18c7:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_179e ENDP
F_18ce PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,16h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[5893h],20h
	JBE        L_18ea
	CMP        byte ptr DS:[5893h],29h
	JNC        L_18ea
	CALL       F_179e
	JMP        L_1b2e
L_18ea:
	CALL       SUB_0000_766c
	OR         AX,AX
	JNZ        L_18f4
	JMP        L_1b2e
L_18f4:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -0eh],AX
	MOV        AX,word ptr [BP + -0ah]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	MOV        word ptr [BP + -8h],AX
	MOV        AX,word ptr [BP + -0eh]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	MOV        word ptr [BP + -0ch],AX
	MOV        AX,8de6h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        word ptr [BP + -4h],1h
	MOV        DI,5c64h
	MOV        word ptr [BP + -12h],5c65h
	MOV        word ptr [BP + -14h],5c66h
	MOV        SI,5c62h
	MOV        DL,byte ptr DS:[5893h]
	MOV        CX,word ptr [BP + -6h]
L_193d:
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	CMP        AX,word ptr [BP + -8h]
	JNZ        L_19a6
	MOV        BX,word ptr [BP + -12h]
	MOV        AL,byte ptr [BX]
	CMP        AX,word ptr [BP + -0ch]
	JNZ        L_19a6
	CMP        DL,7fh
	JA         L_1964
	CMP        DL,80h
	JNC        L_19a6
	MOV        BX,word ptr [BP + -14h]
	MOV        AL,DS:[5895h]
	CMP        byte ptr [BX],AL
	JNZ        L_19a6
L_1964:
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	MOV        CX,AX
	CMP        CX,10h
	JL         L_197f
	CMP        CX,19h
	JZ         L_197f
	CMP        CX,1bh
	JZ         L_197f
	AND        AL,0fch
	CMP        AL,0b4h
	JNZ        L_19a6
L_197f:
	MOV        word ptr [BP + -6h],CX
	CMP        word ptr [BP + -4h],20h
	JGE        L_19c0
	MOV        BX,word ptr [BP + -4h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5fh]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	PUSH       word ptr [BP + -6h]
	PUSH       AX
	PUSH       word ptr [BP + -4h]
	CALL       F_1458
	JMP        L_1b2e
	db 90h
L_19a6:
	ADD        DI,8h
	ADD        word ptr [BP + -12h],8h
	ADD        word ptr [BP + -14h],8h
	ADD        SI,8h
	INC        word ptr [BP + -4h]
	CMP        SI,5d5ah
	JNC        L_197f
	JMP        L_193d
L_19c0:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX
	CMP        AX,9ah
	JNZ        L_19da
	JMP        L_1a6a
L_19da:
	JLE        L_19df
	JMP        L_1b0e
L_19df:
	CMP        AX,2dh
	JZ         L_1a2a
	JMP        L_1b28
	db 90h
L_19e8:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],44h
	MOV        byte ptr DS:[24e6h],1h
	CMP        byte ptr DS:[5893h],80h
	JNC        L_1a05
	CALL       SUB_0000_9eca
L_1a05:
	MOV        byte ptr DS:[58a7h],64h
	MOV        AX,8de8h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,320h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,32h
	PUSH       AX
	CALL       SUB_0000_842e
	CALL       SUB_0000_9990
	JMP        L_1b2e
L_1a2a:
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],2ch
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,8df4h
L_1a40:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,57a8h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_7f94
	MOV        byte ptr DS:[0a9fah],1h
L_1a58:
	CMP        byte ptr DS:[5888h],0h
	JNZ        L_1a62
	JMP        L_1b2e
L_1a62:
	DEC        byte ptr DS:[5888h]
	JMP        L_1b2e
	db 90h
L_1a6a:
	CMP        word ptr [BP + -0eh],1h
	JNZ        L_1a88
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],95h
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,8e04h
	JMP        L_1a40
L_1a88:
	MOV        AX,8e10h
L_1a8b:
	PUSH       AX
	CALL       SUB_0000_58d0
	JMP        L_1b2e
L_1a92:
	CMP        word ptr [BP + -0eh],-1h
	JNZ        L_1ac4
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],95h
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,8e24h
L_1aae:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,57a8h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,270fh
	PUSH       AX
	CALL       SUB_0000_7f94
	JMP        L_1a58
	db 90h
L_1ac4:
	MOV        AX,8e30h
	JMP        L_1a8b
	db 90h
L_1aca:
	CMP        word ptr [BP + -0ah],1h
	JZ         L_1ad6
	CMP        word ptr [BP + -0ah],-1h
	JNZ        L_1adc
L_1ad6:
	MOV        AX,8e44h
	JMP        L_1a8b
	db 90h
L_1adc:
	CMP        word ptr [BP + -0eh],1h
	JNZ        L_1af0
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],9bh
L_1af0:
	CMP        word ptr [BP + -0eh],-1h
	JNZ        L_1b04
	PUSH       word ptr [BP + -8h]
	PUSH       word ptr [BP + -0ch]
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        byte ptr [BX],9ah
L_1b04:
	OR         byte ptr DS:[24e6h],2h
	MOV        AX,8e58h
	JMP        L_1aae
L_1b0e:
	CMP        AX,9bh
	JNZ        L_1b16
	JMP        L_1a92
L_1b16:
	CMP        AX,9ch
	JZ         L_1aca
	CMP        AX,0b0h
	JL         L_1b28
	CMP        AX,0b1h
	JG         L_1b28
	JMP        L_19e8
L_1b28:
	MOV        AX,8e64h
	JMP        L_1a8b
L_1b2e:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_18ce ENDP
F_1b34 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	PUSH       DI
	PUSH       SI
	SUB        DI,DI
	SUB        SI,SI
	JMP        L_1b4f
L_1b42:
	PUSH       SI
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_aee0
	OR         AX,AX
	JZ         L_1b4e
	INC        DI
L_1b4e:
	INC        SI
L_1b4f:
	MOV        AX,SI
	MOV        CL,byte ptr DS:[585bh]
	SUB        CH,CH
	CMP        AX,CX
	JC         L_1b42
	MOV        word ptr [BP + -4h],DI
	MOV        word ptr [BP + -2h],SI
	MOV        AX,DI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_1b34 ENDP
F_1b6c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        DS:[5878h],AX
	MOV        DS:[5876h],AX
	SUB        DI,DI
	MOV        SI,0ba16h
L_1b81:
	CMP        byte ptr [SI],0h
	JZ         L_1ba0
	TEST       byte ptr [SI],20h
	JNZ        L_1ba0
	PUSH       DI
	CALL       SUB_0000_96c6
	MOV        word ptr [BP + -4h],AX
	OR         AX,AX
	JZ         L_1b9c
	INC        word ptr DS:[5876h]
	JMP        L_1ba0
L_1b9c:
	INC        word ptr DS:[5878h]
L_1ba0:
	ADD        SI,8h
	INC        DI
	CMP        DI,20h
	JL         L_1b81
	MOV        word ptr [BP + -2h],DI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1b6c ENDP
F_1bb2 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	MOV        AL,DS:[587ch]
	AND        AL,0f8h
	CMP        AL,20h
	JNZ        L_1bca
	MOV        AX,8e76h
	PUSH       AX
	CALL       SUB_0000_58d0
L_1bc5:
	SUB        AX,AX
	JMP        L_1c52
L_1bca:
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        BX,CL
	TEST       byte ptr [BX + 0ba16h],80h
	JZ         L_1be5
	CMP        byte ptr DS:[58a0h],0h
	JNZ        L_1bfa
	MOV        AL,byte ptr [BP + 4h]
	MOV        DS:[58a0h],AL
L_1be5:
	MOV        byte ptr DS:[589fh],1h
	CALL       F_1b6c
	CMP        word ptr DS:[5876h],0h
	JNZ        L_1c20
	MOV        AX,8ea6h
	JMP        L_1c23
	db 90h
L_1bfa:
	MOV        AL,DS:[58a0h]
	SUB        AH,AH
	CMP        word ptr [BP + 4h],AX
	JZ         L_1be5
	TEST       byte ptr DS:[58a1h],80h
	JZ         L_1be5
	MOV        AX,8e88h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,0a5h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	CALL       SUB_0000_6340
	JMP        L_1bc5
	db 90h
L_1c20:
	MOV        AX,8eaeh
L_1c23:
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_842e
	MOV        byte ptr DS:[587bh],0ffh
	MOV        AX,word ptr [BP + 6h]
	NEG        AX
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_be02
	CALL       SUB_0000_6980
	CALL       SUB_0000_9990
	MOV        AX,1h
L_1c52:
	POP        BP
	RET        4h
	; Func
F_1bb2 ENDP
F_1c56 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	SUB        AX,AX
	MOV        word ptr [BP + -0ah],AX
	MOV        word ptr [BP + -8h],AX
	MOV        BX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 0ba18h]
	SUB        AH,AH
	MOV        word ptr [BP + -6h],AX
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,1h
	JZ         L_1cf0
	CMP        AX,2h
	JZ         L_1ce6
	CMP        AX,3h
	JZ         L_1c90
	CMP        AX,4h
	JZ         L_1cdc
	JMP        L_1c9c
	db 90h
L_1c90:
	MOV        word ptr [BP + -0ah],0ffffh
	MOV        AX,8eb8h
L_1c98:
	PUSH       AX
	CALL       SUB_0000_58d0
L_1c9c:
	MOV        SI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba1ah]
	SUB        AH,AH
	ADD        AX,word ptr [BP + -8h]
	MOV        word ptr [BP + -2h],AX
	MOV        AL,byte ptr [SI + 0ba1bh]
	SUB        AH,AH
	ADD        AX,word ptr [BP + -0ah]
	MOV        word ptr [BP + -4h],AX
	CMP        word ptr [BP + -2h],0ah
	JG         L_1cd0
	CMP        AX,0ah
	JG         L_1cd0
	CMP        word ptr [BP + -2h],0h
	JL         L_1cd0
	OR         AX,AX
	JGE        L_1cfa
L_1cd0:
	PUSH       word ptr [BP + 6h]
	PUSH       word ptr [BP + 4h]
	CALL       F_1bb2
	JMP        L_1d61
L_1cdc:
	MOV        word ptr [BP + -0ah],1h
	MOV        AX,8ec0h
	JMP        L_1c98
L_1ce6:
	MOV        word ptr [BP + -8h],1h
	MOV        AX,8ec8h
	JMP        L_1c98
L_1cf0:
	MOV        word ptr [BP + -8h],0ffffh
	MOV        AX,8eceh
	JMP        L_1c98
L_1cfa:
	MOV        SI,word ptr [BP + -6h]
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 5c5ah]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_bdf6
	OR         AX,AX
	JZ         L_1d4a
	MOV        DI,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        DI,CL
	MOV        AL,byte ptr [BP + -2h]
	MOV        byte ptr [DI + 0ba1ah],AL
	MOV        byte ptr [SI + 5c5ch],AL
	MOV        AL,byte ptr [BP + -4h]
	MOV        byte ptr [DI + 0ba1bh],AL
	MOV        byte ptr [SI + 5c5dh],AL
	CALL       SUB_0000_83be
	TEST       byte ptr DS:[58a1h],82h
	JZ         L_1d45
	PUSH       word ptr [BP + -2h]
	PUSH       word ptr [BP + -4h]
	CALL       SUB_0000_bf3a
L_1d45:
	MOV        AX,1h
	JMP        L_1d61
L_1d4a:
	MOV        AX,8ed4h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,0a5h
	PUSH       AX
	MOV        AX,0c8h
	PUSH       AX
	CALL       SUB_0000_6340
	CALL       SUB_0000_5b96
	SUB        AX,AX
L_1d61:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_1c56 ENDP
F_1d6a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        AX,8edeh
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	PUSH       AX
	MOV        AL,DS:[5897h]
	PUSH       AX
	CALL       SUB_0000_8482
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	TEST       byte ptr DS:[58a1h],2h
	JZ         L_1dd5
	CMP        AX,0c8h
	JNZ        L_1dd5
	CMP        byte ptr DS:[0bb16h],AH
	JZ         L_1dd5
	MOV        AX,8ee6h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        DI,word ptr [BP + -2h]
L_1dab:
	CALL       SUB_0000_66ec
	MOV        SI,AX
	CMP        AX,3h
	JZ         L_1dcb
	CMP        AX,4h
	JZ         L_1dc8
	CMP        AX,44h
	JZ         L_1dc8
	CMP        AX,55h
	JZ         L_1dcb
	SUB        SI,SI
	JMP        L_1dcb
L_1dc8:
	MOV        DI,0c9h
L_1dcb:
	OR         SI,SI
	JZ         L_1dab
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -0ah],SI
L_1dd5:
	CMP        word ptr [BP + -2h],0c8h
	JNZ        L_1df4
	MOV        AX,8eech
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,5h
L_1dec:
	PUSH       AX
	CALL       F_1bb2
	JMP        L_1e9d
	db 90h
L_1df4:
	CMP        word ptr [BP + -2h],86h
	JNZ        L_1e02
	TEST       byte ptr DS:[58a1h],80h
	JNZ        L_1e09
L_1e02:
	CMP        word ptr [BP + -2h],0c9h
	JNZ        L_1e1c
L_1e09:
	MOV        AX,8ef2h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,6h
	JMP        L_1dec
	db 90h
L_1e1c:
	CALL       SUB_0000_766c
	OR         AX,AX
	JZ         L_1e8f
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
	CALL       SUB_0000_8482
	MOV        BX,AX
	CMP        byte ptr [BX],4ch
	JNZ        L_1e94
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7782
	OR         AX,AX
	JNZ        L_1e94
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	MOV        AL,byte ptr [SI + 0ba18h]
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -4h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BP + -6h]
	MOV        byte ptr [SI + 0ba1ah],AL
	MOV        byte ptr [BX + 2h],AL
	MOV        AL,byte ptr [BP + -8h]
	MOV        byte ptr [SI + 0ba1bh],AL
	MOV        byte ptr [BX + 3h],AL
	PUSH       word ptr [BP + -6h]
	PUSH       word ptr [BP + -8h]
	CALL       SUB_0000_bf3a
L_1e8f:
	MOV        AX,1h
	JMP        L_1e9d
L_1e94:
	MOV        AX,8efah
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        AX,AX
L_1e9d:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_1d6a ENDP
F_1ea4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,2h
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	CMP        byte ptr [BX + 2h],0h
	JZ         L_1f22
	TEST       byte ptr [BX + 2h],20h
	JNZ        L_1f22
	CMP        byte ptr [BX + 7h],2h
	JNZ        L_1f22
	MOV        BL,byte ptr [BX + 6h]
	SUB        BH,BH
	MOV        AL,byte ptr [BX + 0ac74h]
	AND        AL,0fch
	CMP        AL,3ch
	JNZ        L_1f22
	MOV        byte ptr DS:[58a0h],4dh
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_be1a
	MOV        AX,8f02h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,4b0h
	PUSH       AX
	MOV        AX,7d0h
	PUSH       AX
	MOV        AX,1h
	PUSH       AX
	MOV        AX,28h
	PUSH       AX
	CALL       SUB_0000_842e
	MOV        byte ptr DS:[587bh],0ffh
	CALL       SUB_0000_6980
	MOV        AL,DS:[589eh]
	SUB        AH,AH
	NEG        AX
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_be02
	CALL       SUB_0000_9990
L_1f22:
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_1ea4 ENDP
F_1f26 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_58d0
	MOV        AX,word ptr [BP + 4h]
	CMP        AX,1h
	JZ         L_1f44
	CMP        AX,2h
	JZ         L_1f6a
	CMP        AX,3h
	JZ         L_1f70
	JMP        L_1f4b
	db 90h
L_1f44:
	MOV        AX,8f12h
L_1f47:
	PUSH       AX
	CALL       SUB_0000_58d0
L_1f4b:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AX,0dch
	PUSH       AX
	MOV        AX,96h
	PUSH       AX
	CALL       SUB_0000_6340
	MOV        AX,96h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6340
	MOV        AX,1h
	JMP        L_1f76
L_1f6a:
	MOV        AX,8f1ah
	JMP        L_1f47
	db 90h
L_1f70:
	MOV        AX,8f24h
	JMP        L_1f47
	db 90h
L_1f76:
	POP        BP
	RET        4h
	; Func
F_1f26 ENDP
F_1f7a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	MOV        AX,8f3ah
	PUSH       AX
	CALL       SUB_0000_58d0
	SUB        SI,SI
	MOV        word ptr [BP + -8h],0ba16h
	MOV        word ptr [BP + -0ah],0ba17h
L_1f9a:
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        DI,AX
	TEST       AL,80h
	JZ         L_1ff0
	PUSH       SI
	CALL       SUB_0000_96c6
	OR         AX,AX
	JNZ        L_1ff0
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	CMP        AX,word ptr [BP + 4h]
	JNZ        L_1ff0
	MOV        AX,DI
	TEST       AL,2ch
	JZ         L_1fc8
	MOV        word ptr [BP + -6h],0h
	JMP        L_1fcd
L_1fc8:
	MOV        word ptr [BP + -6h],1h
L_1fcd:
	MOV        word ptr [BP + -2h],DI
	MOV        word ptr [BP + -4h],SI
	CMP        word ptr [BP + -6h],0h
	JZ         L_2000
	MOV        AL,byte ptr [BP + 4h]
	MOV        DS:[587bh],AL
	PUSH       SI
	CALL       SUB_0000_be1a
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	CALL       SUB_0000_6980
	JMP        L_2007
	db 90h
L_1ff0:
	ADD        word ptr [BP + -8h],8h
	ADD        word ptr [BP + -0ah],8h
	INC        SI
	CMP        SI,20h
	JGE        L_1fcd
	JMP        L_1f9a
L_2000:
	MOV        AX,8f4ch
	PUSH       AX
	CALL       SUB_0000_58d0
L_2007:
	MOV        AX,word ptr [BP + -6h]
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 0A0h
	db 9Eh
	db         58h    X
	db         2Ah    *
	db 0E4h
	db         50h    P
	db 0E8h
	db 0F9h
	db 87h
	db 0E8h
	db 84h
	db 0A0h
	db 80h
	db         3Eh    >
	db 8Eh
	db         58h    X
	db 00h
	db         74h    t
	db 17h
	db 80h
	db         3Eh    >
	db 8Eh
	db         58h    X
	db 0FFh
	db         74h    t
	db 10h
	db 0FEh
	db 0Eh
	db 8Eh
	db         58h    X
	db         75h    u
	db 0Ah
	db 0C6h
	db 06h
	db         7Ah    z
	db         58h    X
	db 00h
	db 0C6h
	db 06h
	db 0FAh
	db 0A9h
	db 01h
	db 0C3h
	db 90h
	; Func
F_1f7a ENDP
F_203e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,8h
	PUSH       DI
	PUSH       SI
	CMP        byte ptr DS:[58a0h],4dh
	JNZ        L_2050
	CALL       SUB_0000_bcca
L_2050:
	MOV        word ptr [BP + -4h],20h
	MOV        DI,5c5ah
	MOV        SI,0a9fch
L_205b:
	PUSH       SI
	PUSH       DI
	PUSH       DS
	POP        ES
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	POP        DI
	POP        SI
	ADD        DI,8h
	ADD        SI,8h
	CMP        SI,0aafch
	JC         L_205b
	TEST       byte ptr DS:[58a1h],82h
	JNZ        L_20d0
	CMP        word ptr [BP + 4h],20h
	JGE        L_20c3
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,5c5ah
	MOV        word ptr [BP + -2h],AX
	CMP        byte ptr DS:[58a3h],0h
	JZ         L_20ae
	MOV        BX,AX
	MOV        AL,byte ptr [BX]
	AND        AL,0fch
	CMP        AL,2ch
	JNZ        L_20ae
	SUB        byte ptr [BX],8h
	SUB        byte ptr [BX + 1h],8h
	MOV        byte ptr [BX + 5h],63h
	MOV        byte ptr [BX + 7h],2h
	JMP        L_20c3
	db 90h
L_20ae:
	MOV        BX,word ptr [BP + -2h]
	MOV        SI,BX
	SUB        AL,AL
	MOV        byte ptr [SI + 4h],AL
	MOV        byte ptr [BX + 3h],AL
	MOV        byte ptr [BX + 2h],AL
	MOV        byte ptr [BX + 1h],AL
	MOV        byte ptr [BX],AL
L_20c3:
	MOV        AX,0ah
	PUSH       AX
	CALL       SUB_0000_573a
	MOV        AL,DS:[5894h]
	MOV        DS:[5893h],AL
L_20d0:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_203e ENDP
F_20d8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,4h
	MOV        word ptr [BP + -4h],1h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	CMP        word ptr [BP + 8h],-1h
	JLE        L_2130
	CMP        word ptr [BP + 8h],0bh
	JGE        L_2130
	CMP        word ptr [BP + 6h],-1h
	JLE        L_2130
	CMP        word ptr [BP + 6h],0bh
	JGE        L_2130
	MOV        BX,AX
	MOV        BL,byte ptr [BX + 4h]
	SUB        BH,BH
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 5c5ah]
	SUB        AH,AH
	PUSH       AX
	PUSH       word ptr [BP + 8h]
	PUSH       word ptr [BP + 6h]
	CALL       SUB_0000_bdf6
	MOV        word ptr [BP + -4h],AX
	MOV        AX,1h
	SUB        AX,word ptr [BP + -4h]
	MOV        word ptr [BP + -4h],AX
	JMP        L_213e
	db 90h
L_2130:
	MOV        BX,word ptr [BP + -2h]
	TEST       byte ptr [BX + 2h],2h
	JZ         L_213e
	MOV        word ptr [BP + -4h],0h
L_213e:
	MOV        AX,word ptr [BP + -4h]
	MOV        SP,BP
	POP        BP
	RET        6h
	db 90h
	; Func
F_20d8 ENDP
F_2148 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -4h],0h
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,0ba14h
	MOV        word ptr [BP + -2h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 6h]
	SUB        AH,AH
	MOV        SI,AX
	MOV        AL,byte ptr [BX + 7h]
	MOV        DI,AX
	MOV        word ptr [BP + -0ah],0h
L_2175:
	MOV        AX,word ptr [BP + -0ah]
	OR         AX,AX
	JZ         L_218e
	CMP        AX,1h
	JZ         L_21ae
	CMP        AX,2h
	JZ         L_21aa
	CMP        AX,3h
	JZ         L_21ae
	JMP        L_218f
	db 90h
L_218e:
	INC        DI
L_218f:
	PUSH       SI
	PUSH       DI
	PUSH       word ptr [BP + 4h]
	CALL       F_20d8
	OR         AX,AX
	JZ         L_219e
	INC        word ptr [BP + -4h]
L_219e:
	INC        word ptr [BP + -0ah]
	CMP        word ptr [BP + -0ah],4h
	JGE        L_21b2
	JMP        L_2175
	db 90h
L_21aa:
	DEC        SI
	DEC        SI
	JMP        L_218f
L_21ae:
	DEC        DI
	INC        SI
	JMP        L_218f
L_21b2:
	MOV        word ptr [BP + -8h],DI
	MOV        word ptr [BP + -6h],SI
	CMP        word ptr [BP + -4h],4h
	JNZ        L_21c4
	MOV        AX,1h
	JMP        L_21c6
	db 90h
L_21c4:
	SUB        AX,AX
L_21c6:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_2148 ENDP
F_21ce PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0h
	MOV        SI,0ba16h
	MOV        DI,0ba17h
L_21e1:
	TEST       byte ptr [SI],1h
	JZ         L_223e
	TEST       byte ptr [SI],80h
	JZ         L_223e
	AND        byte ptr [SI],0feh
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	MOV        CL,5h
	SHL        AX,CL
	ADD        AX,55a8h
	PUSH       AX
	CALL       SUB_0000_58d0
	MOV        AX,8f56h
	PUSH       AX
	CALL       SUB_0000_58d0
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
	CALL       SUB_0000_6212
	MOV        AL,byte ptr [DI]
	SUB        AH,AH
	PUSH       AX
	MOV        AX,23h
	PUSH       AX
	CALL       SUB_0000_aee0
	PUSH       word ptr [BP + -2h]
	CALL       SUB_0000_a92e
L_222d:
	CMP        word ptr [BP + -2h],6h
	JNZ        L_2238
	MOV        word ptr [BP + -2h],0ffffh
L_2238:
	MOV        AX,word ptr [BP + -2h]
	JMP        L_2250
	db 90h
L_223e:
	ADD        SI,8h
	ADD        DI,8h
	INC        word ptr [BP + -2h]
	CMP        word ptr [BP + -2h],6h
	JGE        L_222d
	JMP        L_21e1
	db 90h
L_2250:
	POP        SI
	POP        DI
	MOV        SP,BP
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
	db 00h
F_21ce ENDP
_TEXT ENDS
END
