_TEXT SEGMENT BYTE 'CODE'
ORG 0a6f8h
SUB_0000_a6f8:
ORG 0dcaeh
SUB_0000_dcae:
ORG 75c0h
SUB_0000_75c0:
ORG 7e02h
SUB_0000_7e02:
ORG 83dch
SUB_0000_83dc:
ORG 87c2h
SUB_0000_87c2:
ORG 67e0h
SUB_0000_67e0:
ORG 6880h
SUB_0000_6880:
ORG 7962h
SUB_0000_7962:
ORG 7a3ah
SUB_0000_7a3a:
ORG 7a0eh
SUB_0000_7a0e:
ORG 6816h
SUB_0000_6816:
ORG 7904h
SUB_0000_7904:
ORG 742ah
SUB_0000_742a:
ORG 7b4ah
SUB_0000_7b4a:
ORG 0d966h
SUB_0000_d966:
ORG 0cd2ch
SUB_0000_cd2c:
ORG 6d9eh
SUB_0000_6d9e:
ORG 691eh
SUB_0000_691e:
ORG 6992h
SUB_0000_6992:
ORG 0c6a6h
SUB_0000_c6a6:
ORG 0c276h
SUB_0000_c276:
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
	SUB        SP,0ch
	PUSH       SI
	CALL       SUB_0000_a6f8
	MOV        word ptr [BP + -0ch],AX
	INC        AX
	JNZ        L_0013
	JMP        L_027e
L_0013:
	CMP        byte ptr DS:[58a7h],0h
	JNZ        L_0028
	CMP        byte ptr DS:[58a6h],0h
	JNZ        L_0028
	MOV        AX,752eh
	JMP        L_00df
	db 90h
L_0028:
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_dcae
	OR         AX,AX
	JNZ        L_0038
	JMP        L_027e
L_0038:
	MOV        AX,DS:[5876h]
	MOV        word ptr [BP + -6h],AX
	MOV        AX,DS:[5878h]
	MOV        word ptr [BP + -8h],AX
	MOV        SI,AX
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
	MOV        AL,byte ptr [BX + SI + 595ah]
	SUB        AH,AH
	MOV        word ptr [BP + -0ah],AX
	MOV        AX,7542h
	PUSH       AX
	CALL       SUB_0000_75c0
	CMP        word ptr [BP + -0ah],61h
	JNZ        L_007b
	MOV        word ptr [BP + -0ah],0h
L_007b:
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0f0h
	CMP        AL,80h
	JNZ        L_00b8
	MOV        AX,word ptr [BP + -0ah]
	CMP        AX,80h
	JZ         L_00a0
	CMP        AX,81h
	JZ         L_00a6
	CMP        AX,82h
	JZ         L_00ac
	CMP        AX,83h
	JZ         L_00b2
	MOV        AX,7598h
	JMP        L_00df
L_00a0:
	MOV        AX,754ch
	JMP        L_00df
	db 90h
L_00a6:
	MOV        AX,755ch
	JMP        L_00df
	db 90h
L_00ac:
	MOV        AX,7572h
	JMP        L_00df
	db 90h
L_00b2:
	MOV        AX,7584h
	JMP        L_00df
	db 90h
L_00b8:
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0f0h
	CMP        AL,0c0h
	JNZ        L_0102
	MOV        AL,DS:[6604h]
	SUB        AH,AH
	AND        AX,0fh
	MOV        word ptr [BP + -2h],AX
	CMP        AX,1h
	JNZ        L_00d6
	MOV        AX,75aah
	JMP        L_00df
L_00d6:
	CMP        word ptr [BP + -2h],2h
	JNZ        L_00e6
	MOV        AX,75c2h
L_00df:
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_027e
L_00e6:
	MOV        AX,1h
	PUSH       AX
	MOV        AX,0ffh
	PUSH       AX
	CALL       SUB_0000_7e02
	CMP        AX,0ffh
	JNZ        L_00fc
	MOV        AX,75d8h
	JMP        L_00df
	db 90h
L_00fc:
	MOV        AX,75fah
	JMP        L_00df
	db 90h
L_0102:
	MOV        AX,word ptr [BP + -0ah]
	AND        AX,0f0h
	CMP        AX,70h
	JZ         L_016a
	JLE        L_0112
	JMP        L_01b8
L_0112:
	CMP        AX,20h
	JZ         L_014c
	JLE        L_011c
	JMP        L_01a0
L_011c:
	OR         AX,AX
	JZ         L_0128
	CMP        AX,10h
	JZ         L_0146
	JMP        L_012f
	db 90h
L_0128:
	MOV        AX,7618h
L_012b:
	PUSH       AX
	CALL       SUB_0000_75c0
L_012f:
	MOV        AL,byte ptr [BP + -0ah]
	AND        AL,0f0h
	CMP        AL,50h
	JZ         L_013b
	JMP        L_027e
L_013b:
	MOV        AX,7700h
	PUSH       AX
	CALL       SUB_0000_75c0
	JMP        L_01f0
	db 90h
L_0146:
	MOV        AX,7624h
	JMP        L_012b
	db 90h
L_014c:
	MOV        AX,7634h
	JMP        L_012b
	db 90h
L_0152:
	MOV        AX,7644h
	JMP        L_012b
	db 90h
L_0158:
	MOV        AX,7650h
	JMP        L_012b
	db 90h
L_015e:
	MOV        AX,7662h
	JMP        L_012b
	db 90h
L_0164:
	MOV        AX,7670h
	JMP        L_012b
	db 90h
L_016a:
	MOV        AX,7678h
	JMP        L_012b
	db 90h
L_0170:
	MOV        AX,7688h
	JMP        L_012b
	db 90h
L_0176:
	MOV        AX,769ah
	JMP        L_012b
	db 90h
L_017c:
	MOV        AX,76ach
	JMP        L_012b
	db 90h
L_0182:
	MOV        AX,76bch
	JMP        L_012b
	db 90h
L_0188:
	MOV        AX,76c6h
	JMP        L_012b
	db 90h
L_018e:
	MOV        AX,76d6h
	JMP        L_012b
	db 90h
L_0194:
	MOV        AX,76e0h
	JMP        L_012b
	db 90h
L_019a:
	MOV        AX,76f0h
	JMP        L_012b
	db 90h
L_01a0:
	CMP        AX,30h
	JZ         L_0152
	CMP        AX,40h
	JZ         L_0158
	CMP        AX,50h
	JZ         L_015e
	CMP        AX,60h
	JZ         L_0164
	JMP        L_012f
	db 90h
L_01b8:
	CMP        AX,0b0h
	JZ         L_0182
	JG         L_01d2
	CMP        AX,80h
	JZ         L_0170
	CMP        AX,90h
	JZ         L_0176
	CMP        AX,0a0h
	JZ         L_017c
	JMP        L_012f
	db 90h
L_01d2:
	CMP        AX,0c0h
	JZ         L_0188
	CMP        AX,0d0h
	JZ         L_018e
	CMP        AX,0e0h
	JZ         L_0194
	CMP        AX,0f0h
	JZ         L_019a
	JMP        L_012f
	db 90h
L_01ea:
	CMP        byte ptr [BP + -4h],4eh
	JZ         L_01fa
L_01f0:
	CALL       SUB_0000_83dc
	MOV        byte ptr [BP + -4h],AL
	CMP        AL,59h
	JNZ        L_01ea
L_01fa:
	CMP        byte ptr [BP + -4h],4eh
	JNZ        L_0206
	MOV        AX,7712h
	JMP        L_00df
L_0206:
	MOV        AX,7718h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        AX,word ptr [BP + -0ah]
	CMP        AX,50h
	JZ         L_0222
	CMP        AX,51h
	JZ         L_0238
	CMP        AX,52h
	JZ         L_0250
	JMP        L_0266
	db 90h
L_0222:
	MOV        AX,7726h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + -0ch]
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],47h
	JMP        L_027e
	db 90h
L_0238:
	MOV        AX,772eh
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        SI,word ptr [BP + -0ch]
	MOV        CL,5h
	SHL        SI,CL
	MOV        AX,word ptr [SI + 55bah]
	MOV        word ptr [SI + 55b8h],AX
	JMP        L_027e
L_0250:
	MOV        AX,7738h
	PUSH       AX
	CALL       SUB_0000_75c0
	MOV        BX,word ptr [BP + -0ch]
	MOV        CL,5h
	SHL        BX,CL
	MOV        byte ptr [BX + 55b3h],50h
	JMP        L_027e
	db 90h
L_0266:
	MOV        AX,7744h
	PUSH       AX
	CALL       SUB_0000_75c0
	PUSH       word ptr [BP + -0ch]
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_7e02
	PUSH       AX
	CALL       SUB_0000_87c2
L_027e:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_0284 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0eh
	PUSH       DI
	PUSH       SI
	MOV        AX,DS:[13b6h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        SI,word ptr [BP + 6h]
	ADD        SI,6h
	MOV        DI,word ptr [BP + 6h]
	INC        DI
	PUSH       DI
	PUSH       word ptr [BP + 4h]
	PUSH       SI
	PUSH       word ptr [BP + 4h]
	CALL       SUB_0000_6880
	MOV        AX,word ptr [BP + 4h]
	INC        AX
	MOV        word ptr [BP + -2h],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        AX,DS:[13aeh]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,2h
	MOV        word ptr [BP + -4h],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,3h
	MOV        word ptr [BP + -6h],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        AX,DS:[13b2h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,4h
	MOV        word ptr [BP + -8h],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,5h
	MOV        word ptr [BP + -0ah],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        AX,DS:[13b4h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_67e0
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,6h
	MOV        word ptr [BP + -0ch],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	MOV        AX,word ptr [BP + 4h]
	ADD        AX,7h
	MOV        word ptr [BP + -0eh],AX
	PUSH       DI
	PUSH       AX
	PUSH       SI
	PUSH       AX
	CALL       SUB_0000_6880
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_0284 ENDP
F_0340 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,1ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -6h],0h
	CMP        word ptr [BP + 6h],0h
	JL         L_0365
	CMP        word ptr [BP + 6h],15h
	JG         L_0365
	CMP        word ptr [BP + 4h],0h
	JL         L_0365
	CMP        word ptr [BP + 4h],15h
	JLE        L_036a
L_0365:
	SUB        AX,AX
	JMP        L_06a0
L_036a:
	MOV        SI,word ptr [BP + 4h]
	MOV        CL,5h
	SHL        SI,CL
	ADD        SI,word ptr [BP + 6h]
	ADD        SI,0ad14h
	CMP        byte ptr [SI],0h
	JNZ        L_0380
	JMP        L_0690
L_0380:
	MOV        word ptr [BP + -6h],1h
	MOV        byte ptr [SI],0h
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,byte ptr DS:[5896h]
	SUB        CH,CH
	ADD        AX,CX
	SUB        AX,0bh
	AND        AX,7h
	MOV        word ptr [BP + -2h],AX
	MOV        AX,word ptr [BP + 4h]
	MOV        CL,byte ptr DS:[5897h]
	ADD        AX,CX
	SUB        AX,0bh
	AND        AX,7h
	MOV        word ptr [BP + -4h],AX
	MOV        DI,AX
	MOV        CL,3h
	SHL        DI,CL
	ADD        DI,word ptr [BP + -2h]
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + DI + 595ah]
	MOV        byte ptr [BP + -8h],AL
	MOV        CL,4h
	SHR        byte ptr [BP + -8h],CL
	MOV        AX,word ptr [BP + 6h]
	INC        AX
	PUSH       AX
	MOV        AX,word ptr [BP + 4h]
	INC        AX
	PUSH       AX
	CALL       SUB_0000_7962
	MOV        AX,word ptr [BP + 6h]
	MOV        CL,3h
	SHL        AX,CL
	ADD        AX,8h
	MOV        word ptr [BP + 6h],AX
	MOV        AX,word ptr [BP + 4h]
	SHL        AX,CL
	ADD        AX,8h
	MOV        word ptr [BP + 4h],AX
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0
	MOV        AL,byte ptr [BP + -8h]
	SUB        AH,AH
	CMP        AX,0fh
	JBE        L_0406
	JMP        L_0690
L_0406:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0a900h]
	db 8Bh
	db 76h
	db 0FCh
	db 0B1h
	db 03h
	db 0D3h
	db 0E6h
	db 03h
	db 76h
	db 0FEh
	db 8Ah
	db 1Eh
	db 95h
	db 58h
	db 2Ah
	db 0FFh
	db 0B1h
	db 06h
	db 0D3h
	db 0E3h
	db 0F6h
	db 80h
	db 5Ah
	db 59h
	db 08h
	db 75h
	db 03h
	db 0E9h
	db 64h
	db 02h
	db 0FFh
	db 36h
	db 0BAh
	db 13h
	db 0E8h
	db 07h
	db 76h
	db 0B8h
	db 18h
	db 00h
	db 50h
	db 0E8h
	db 0F0h
	db 6Fh
	db 0E9h
	db 53h
	db 02h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0C9h
	db 75h
	db 0FFh
	db 36h
	db 0BAh
	db 13h
	db 0E8h
	db 0EEh
	db 75h
	db 0B8h
	db 2Eh
	db 00h
	db 0EBh
	db 0E5h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0B5h
	db 75h
	db 0FFh
	db 36h
	db 0BAh
	db 13h
	db 0E8h
	db 0DAh
	db 75h
	db 0B8h
	db 2Dh
	db 00h
	db 0EBh
	db 0D1h
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0A1h
	db 75h
	db 0FFh
	db 36h
	db 0BAh
	db 13h
	db 0E8h
	db 0C6h
	db 75h
	db 0B8h
	db 2Fh
	db 00h
	db 0EBh
	db 0BDh
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 8Dh
	db 75h
	db 0FFh
	db 36h
	db 0B8h
	db 13h
	db 0E8h
	db 0B2h
	db 75h
	db 0B8h
	db 70h
	db 00h
	db 0EBh
	db 0A9h
	db 90h
	db 8Bh
	db 76h
	db 06h
	db 83h
	db 0C6h
	db 06h
	db 8Bh
	db 7Eh
	db 06h
	db 47h
	db 8Bh
	db 46h
	db 04h
	db 05h
	db 04h
	db 00h
	db 89h
	db 46h
	db 0F6h
	db 57h
	db 50h
	db 56h
	db 50h
	db 0E8h
	db 0D8h
	db 63h
	db 8Bh
	db 46h
	db 06h
	db 05h
	db 05h
	db 00h
	db 89h
	db 46h
	db 0F4h
	db 8Bh
	db 46h
	db 06h
	db 05h
	db 02h
	db 00h
	db 89h
	db 46h
	db 0F2h
	db 8Bh
	db 46h
	db 04h
	db 05h
	db 05h
	db 00h
	db 89h
	db 46h
	db 0F0h
	db 0FFh
	db 76h
	db 0F2h
	db 50h
	db 0FFh
	db 76h
	db 0F4h
	db 50h
	db 0E8h
	db 0B2h
	db 63h
	db 8Bh
	db 46h
	db 04h
	db 05h
	db 06h
	db 00h
	db 89h
	db 46h
	db 0EEh
	db 57h
	db 50h
	db 0FFh
	db 76h
	db 0F2h
	db 50h
	db 0E8h
	db 0A0h
	db 63h
	db 0FFh
	db 76h
	db 0F4h
	db 0FFh
	db 76h
	db 0EEh
	db 56h
	db 0FFh
	db 76h
	db 0EEh
	db 0E8h
	db 93h
	db 63h
	db 0A1h
	db 0B2h
	db 13h
	db 05h
	db 08h
	db 00h
	db 50h
	db 0E8h
	db 0E9h
	db 62h
	db 8Bh
	db 46h
	db 04h
	db 05h
	db 02h
	db 00h
	db 89h
	db 46h
	db 0ECh
	db 57h
	db 50h
	db 0E8h
	db 0CFh
	db 64h
	db 8Bh
	db 7Eh
	db 04h
	db 47h
	db 0FFh
	db 76h
	db 0F2h
	db 57h
	db 0E8h
	db 0C4h
	db 64h
	db 8Bh
	db 46h
	db 06h
	db 05h
	db 04h
	db 00h
	db 89h
	db 46h
	db 0EAh
	db 8Bh
	db 46h
	db 06h
	db 05h
	db 03h
	db 00h
	db 89h
	db 46h
	db 0E8h
	db 50h
	db 0FFh
	db 76h
	db 0ECh
	db 0FFh
	db 76h
	db 0EAh
	db 0FFh
	db 76h
	db 0ECh
	db 0E8h
	db 51h
	db 63h
	db 8Bh
	db 46h
	db 04h
	db 05h
	db 03h
	db 00h
	db 89h
	db 46h
	db 0E6h
	db 0FFh
	db 76h
	db 0E8h
	db 50h
	db 0FFh
	db 76h
	db 0EAh
	db 50h
	db 0E8h
	db 3Dh
	db 63h
	db 0FFh
	db 76h
	db 0F4h
	db 57h
	db 0E8h
	db 8Ah
	db 64h
	db 56h
	db 0FFh
	db 76h
	db 0ECh
	db 0E8h
	db 83h
	db 64h
	db 0E9h
	db 3Ch
	db 01h
	db 0FFh
	db 36h
	db 0BAh
	db 13h
	db 0E8h
	db 0DFh
	db 74h
	db 8Bh
	db 76h
	db 0FCh
	db 0B1h
	db 03h
	db 0D3h
	db 0E6h
	db 03h
	db 76h
	db 0FEh
	db 8Ah
	db 1Eh
	db 95h
	db 58h
	db 2Ah
	db 0FFh
	db 0B1h
	db 06h
	db 0D3h
	db 0E3h
	db 8Ah
	db 80h
	db 5Ah
	db 59h
	db 2Ah
	db 0E4h
	db 3Dh
	db 60h
	db 00h
	db 74h
	db 26h
	db 3Dh
	db 61h
	db 00h
	db 74h
	db 27h
	db 3Dh
	db 68h
	db 00h
	db 74h
	db 30h
	db 3Dh
	db 69h
	db 00h
	db 74h
	db 1Dh
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 7Eh
	db 74h
	db 0A1h
	db 0AEh
	db 13h
	db 05h
	db 08h
	db 00h
	db 50h
	db 0E8h
	db 0A0h
	db 74h
	db 0B8h
	db 72h
	db 00h
	db 0E9h
	db 96h
	db 0FEh
	db 0B8h
	db 19h
	db 00h
	db 0E9h
	db 90h
	db 0FEh
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 61h
	db 74h
	db 0B8h
	db 71h
	db 00h
	db 0E9h
	db 83h
	db 0FEh
	db 90h
	db 0B8h
	db 12h
	db 00h
	db 0E9h
	db 7Ch
	db 0FEh
	db 0FFh
	db 76h
	db 06h
	db 0FFh
	db 76h
	db 04h
	db 0E8h
	db 0C1h
	db 0FCh
	db 0E9h
	db 0CAh
	db 00h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 41h
	db 74h
	db 0FFh
	db 36h
	db 0B8h
	db 13h
	db 0E8h
	db 66h
	db 74h
	db 0B8h
	db 73h
	db 00h
	db 0E9h
	db 5Ch
	db 0FEh
	db 8Bh
	db 76h
	db 0FCh
	db 0B1h
	db 03h
	db 0D3h
	db 0E6h
	db 03h
	db 76h
	db 0FEh
	db 8Ah
	db 1Eh
	db 95h
	db 58h
	db 2Ah
	db 0FFh
	db 0B1h
	db 06h
	db 0D3h
	db 0E3h
	db 80h
	db 0B8h
	db 5Ah
	db 59h
	db 0B0h
	db 75h
	db 05h
	db 0B8h
	db 7Fh
	db 00h
	db 0EBh
	db 0Ah
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0Dh
	db 74h
	db 0B8h
	db 74h
	db 00h
	db 50h
	db 0E8h
	db 22h
	db 6Eh
	db 0C7h
	db 46h
	db 0FAh
	db 00h
	db 00h
	db 0E9h
	db 80h
	db 00h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0F7h
	db 73h
	db 0FFh
	db 36h
	db 0B2h
	db 13h
	db 0E8h
	db 78h
	db 76h
	db 0B8h
	db 75h
	db 00h
	db 50h
	db 0E8h
	db 05h
	db 6Eh
	db 2Bh
	db 0C0h
	db 50h
	db 0E8h
	db 6Bh
	db 76h
	db 0EBh
	db 0DBh
	db 90h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0D9h
	db 73h
	db 83h
	db 3Eh
	db 0C8h
	db 52h
	db 00h
	db 75h
	db 06h
	db 0FFh
	db 36h
	db 0B2h
	db 13h
	db 0EBh
	db 12h
	db 83h
	db 3Eh
	db 0C8h
	db 52h
	db 01h
	db 74h
	db 07h
	db 83h
	db 3Eh
	db 0C8h
	db 52h
	db 02h
	db 75h
	db 07h
	db 0FFh
	db 36h
	db 0BAh
	db 13h
	db 0E8h
	db 3Fh
	db 76h
	db 0B8h
	db 76h
	db 00h
	db 0EBh
	db 0C5h
	db 0B8h
	db 01h
	db 00h
	db 50h
	db 0E8h
	db 0ABh
	db 73h
	db 0FFh
	db 36h
	db 0B8h
	db 13h
	db 0E8h
	db 0D0h
	db 73h
	db 0B8h
	db 77h
	db 00h
	db 0E9h
	db 0C6h
	db 0FDh
	db 9Eh
	db 0A6h
	db 0CEh
	db 0A6h
	db 0E2h
	db 0A6h
	db 0F6h
	db 0A6h
	db 0Ah
	db 0A7h
	db 1Eh
	db 0A7h
	db 0E4h
	db 0A7h
	db 20h
	db 0A9h
	db 4Ah
	db 0A8h
	db 20h
	db 0A9h
	db 56h
	db 0A8h
	db 6Ah
	db 0A8h
	db 0A0h
	db 0A8h
	db 0BEh
	db 0A8h
	db 0ECh
	db 0A8h
	db 56h
	db 0A8h
L_0690:
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_7a3a
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,word ptr [BP + -6h]
L_06a0:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	; Func
F_0340 ENDP
F_06a8 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,18h
	PUSH       DI
	PUSH       SI
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
	MOV        AX,0a528h
	MOV        word ptr [BP + -0ah],AX
	MOV        word ptr [BP + -2h],AX
	MOV        AX,0a628h
	MOV        word ptr [BP + -0eh],AX
	MOV        word ptr [BP + -4h],AX
	MOV        word ptr [BP + -6h],0a627h
	MOV        CX,2e0h
	MOV        DI,0ad14h
	MOV        AX,DS
	MOV        ES,AX
	MOV        AX,0ffh
	REP STOSB
	MOV        BX,word ptr [BP + -2h]
	MOV        byte ptr [BX],0bh
	INC        word ptr [BP + -2h]
	MOV        BX,word ptr [BP + -4h]
	MOV        byte ptr [BX],0bh
	INC        word ptr [BP + -4h]
	MOV        word ptr [BP + -10h],60h
	MOV        word ptr [BP + -12h],60h
	MOV        byte ptr DS:[0ae7fh],0h
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_67e0
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7904
	MOV        AX,0ch
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_7962
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_7a0e
	MOV        AX,DS:[13b4h]
	ADD        AX,8h
	PUSH       AX
	CALL       SUB_0000_7a3a
	CMP        word ptr DS:[52c8h],3h
	JNZ        L_073e
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_7a3a
L_073e:
	MOV        AX,60h
	PUSH       AX
	CALL       SUB_0000_742a
	PUSH       word ptr DS:[13b0h]
	CALL       SUB_0000_7a3a
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7a0e
	JMP        L_07d6
	db 90h
	db 90h
	db 90h
	db 4Fh
	db 4Eh
	db 0EBh
	db 24h
	db 47h
	db 0EBh
	db 0FAh
	db 90h
	db 4Fh
	db 0EBh
	db 1Dh
	db 90h
	db 47h
	db 0EBh
	db 19h
	db 90h
	db 4Fh
	db 46h
	db 0EBh
	db 14h
	db 47h
	db 0EBh
	db 0FAh
	db 90h
	db 0E8h
	db 0A9h
	db 0E9h
	db 0A9h
	db 0ECh
	db 0A9h
	db 0F0h
	db 0A9h
	db 0F4h
	db 0A9h
	db 0F8h
	db 0A9h
	db 0F9h
	db 0A9h
	db 0FCh
	db 0A9h
L_0780:
	PUSH       DI
	PUSH       SI
	CALL       F_0340
	OR         AX,AX
	JZ         L_07af
	MOV        BX,word ptr [BP + -2h]
	MOV        AX,DI
	MOV        byte ptr [BX],AL
	INC        word ptr [BP + -2h]
	MOV        BX,word ptr [BP + -4h]
	MOV        AX,SI
	MOV        byte ptr [BX],AL
	INC        word ptr [BP + -4h]
	MOV        AX,word ptr [BP + -6h]
	CMP        word ptr [BP + -2h],AX
	JBE        L_07af
	MOV        word ptr [BP + -2h],0a528h
	MOV        word ptr [BP + -4h],0a628h
L_07af:
	INC        word ptr [BP + -14h]
	CMP        word ptr [BP + -14h],8h
	JL         L_07fb
	MOV        word ptr [BP + -10h],DI
	MOV        word ptr [BP + -12h],SI
	INC        word ptr [BP + -0ah]
	INC        word ptr [BP + -0eh]
	MOV        AX,word ptr [BP + -6h]
	CMP        word ptr [BP + -0ah],AX
	JBE        L_07d6
	MOV        word ptr [BP + -0ah],0a528h
	MOV        word ptr [BP + -0eh],0a628h
L_07d6:
	MOV        AX,word ptr [BP + -0ah]
	CMP        word ptr [BP + -2h],AX
	JZ         L_081a
	MOV        word ptr [BP + -14h],0h
	MOV        BX,word ptr [BP + -0eh]
	MOV        AL,byte ptr [BX]
	SUB        AH,AH
	MOV        word ptr [BP + -16h],AX
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [BX]
	MOV        word ptr [BP + -18h],AX
	MOV        DI,word ptr [BP + -10h]
	MOV        SI,word ptr [BP + -12h]
L_07fb:
	MOV        DI,word ptr [BP + -18h]
	MOV        word ptr [BP + -8h],DI
	MOV        SI,word ptr [BP + -16h]
	MOV        word ptr [BP + -0ch],SI
	MOV        AX,word ptr [BP + -14h]
	CMP        AX,7h
	JBE        L_0812
	JMP        L_0780
L_0812:
	ADD        AX,AX
	XCHG       AX,BX
	JMP        word ptr CS:[BX + 0aa00h]
L_081a:
	MOV        AX,2h
	PUSH       AX
	CALL       SUB_0000_7904
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_7b4a
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
	CALL       SUB_0000_d966
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	; Func
F_06a8 ENDP
F_0844 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       SI
	MOV        word ptr [BP + -4h],0h
	MOV        AL,DS:[3840h]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_088c
	MOV        word ptr [BP + -0ah],AX
	MOV        AL,DS:[5893h]
	MOV        DX,AX
	AND        DX,0fh
	MOV        CL,4h
	SHL        DX,CL
	ADD        DX,word ptr [BP + 4h]
	MOV        SI,word ptr [BP + -4h]
	MOV        CX,word ptr [BP + -0ah]
L_0872:
	MOV        AL,byte ptr [SI + 383ah]
	SUB        AH,AH
	CMP        AX,DX
	JNZ        L_0882
	MOV        word ptr [BP + -4h],SI
	JMP        L_08cd
	db 90h
L_0882:
	INC        SI
	MOV        AX,SI
	CMP        AX,CX
	JC         L_0872
	MOV        word ptr [BP + -4h],SI
L_088c:
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	SUB        AX,21h
	MOV        word ptr [BP + -2h],AX
	CMP        AX,1h
	JL         L_089f
	DEC        word ptr [BP + -2h]
L_089f:
	MOV        AX,word ptr [BP + -2h]
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,word ptr [BP + 4h]
	MOV        word ptr [BP + -8h],AX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        CX,3h
	SAR        AX,CL
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -6h],AX
	MOV        BX,AX
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -8h]
	AND        CL,7h
	SHL        AL,CL
	OR         byte ptr [BX + 58e0h],AL
L_08cd:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_0844 ENDP
F_08d4 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	MOV        AL,DS:[5893h]
	SUB        AH,AH
	SUB        AX,21h
	MOV        word ptr [BP + -4h],AX
	CMP        AX,1h
	JL         L_08ed
	DEC        word ptr [BP + -4h]
L_08ed:
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,4h
	SHL        AX,CL
	ADD        AX,word ptr [BP + 4h]
	MOV        word ptr [BP + -0ah],AX
	CWD
	XOR        AX,DX
	SUB        AX,DX
	MOV        CX,3h
	SAR        AX,CL
	XOR        AX,DX
	SUB        AX,DX
	MOV        word ptr [BP + -8h],AX
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 58e0h]
	MOV        byte ptr [BP + -2h],AL
	MOV        AL,1h
	MOV        CL,byte ptr [BP + -0ah]
	AND        CL,7h
	SHL        AL,CL
	MOV        byte ptr [BP + -6h],AL
	SUB        AH,AH
	MOV        CL,byte ptr [BP + -2h]
	SUB        CH,CH
	TEST       CX,AX
	JZ         L_0932
	MOV        AX,1h
	JMP        L_0934
	db 90h
L_0932:
	SUB        AX,AX
L_0934:
	MOV        SP,BP
	POP        BP
	RET        2h
	; Func
F_08d4 ENDP
F_093a PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ch
	PUSH       DI
	PUSH       SI
	MOV        SI,595ah
	MOV        word ptr [BP + -4h],200h
	MOV        DI,200h
L_094d:
	MOV        AL,byte ptr [SI]
	MOV        byte ptr [BP + -0ah],AL
	AND        AL,0f0h
	MOV        byte ptr [BP + -2h],AL
	CMP        AL,0f0h
	JNZ        L_0971
	MOV        AL,byte ptr [BP + -0ah]
	SUB        AH,AH
	AND        AX,0fh
	MOV        word ptr [BP + -6h],AX
	PUSH       AX
	CALL       F_08d4
	OR         AX,AX
	JZ         L_0971
	AND        byte ptr [SI],0afh
L_0971:
	INC        SI
	DEC        DI
	JNZ        L_094d
	MOV        word ptr [BP + -8h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_093a ENDP
F_097e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        word ptr [BP + -0ah],0h
	MOV        word ptr [BP + -2h],0h
	MOV        word ptr [BP + -4h],0h
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_09b2
	CMP        AX,1h
	JZ         L_09f8
	CMP        AX,2h
	JZ         L_0a02
	CMP        AX,3h
	JZ         L_0a0c
	JMP        L_09b5
L_09b2:
	INC        word ptr [BP + -8h]
L_09b5:
	MOV        word ptr [BP + -6h],0bh
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX
	MOV        DI,word ptr [BP + -0ah]
	SHL        DI,CL
	MOV        SI,0bh
	MOV        AX,word ptr [BP + -0ah]
	MOV        CX,AX
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,CX
	SHL        AX,1h
	ADD        AX,CX
	ADD        word ptr [BP + -4h],AX
	MOV        DX,word ptr [BP + -2h]
	MOV        CX,word ptr [BP + -0ch]
L_09e4:
	MOV        BX,CX
	ADD        BX,DX
	MOV        byte ptr [BX + 0ad14h],0ffh
	ADD        DX,word ptr [BP + -8h]
	ADD        CX,DI
	DEC        SI
	JZ         L_0a12
	JMP        L_09e4
	db 90h
L_09f8:
	INC        word ptr [BP + -0ah]
	MOV        word ptr [BP + -2h],0ah
	JMP        L_09b5
L_0a02:
	INC        word ptr [BP + -8h]
	MOV        word ptr [BP + -4h],0ah
	JMP        L_09b5
L_0a0c:
	INC        word ptr [BP + -0ah]
	JMP        L_09b5
	db 90h
L_0a12:
	MOV        word ptr [BP + -2h],DX
	CMP        word ptr [BP + 4h],0h
	JNZ        L_0a2a
	CMP        byte ptr [BP + 6h],0e0h
	JNZ        L_0a2a
	MOV        AL,DS:[0bb14h]
	MOV        DS:[0ae19h],AL
	MOV        DS:[0ad59h],AL
L_0a2a:
	CMP        word ptr [BP + 4h],3h
	JNZ        L_0a3f
	CMP        byte ptr [BP + 6h],0e0h
	JNZ        L_0a3f
	MOV        AL,DS:[0bb14h]
	MOV        DS:[0adbch],AL
	MOV        DS:[0adb6h],AL
L_0a3f:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
	db 90h
	; Func
F_097e ENDP
F_0a48 PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        word ptr [BP + -0ah],0h
	MOV        word ptr [BP + -2h],3h
	MOV        word ptr [BP + -4h],3h
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_0a7c
	CMP        AX,1h
	JZ         L_0ac4
	CMP        AX,2h
	JZ         L_0ace
	CMP        AX,3h
	JZ         L_0ad8
	JMP        L_0a84
L_0a7c:
	INC        word ptr [BP + -8h]
	MOV        word ptr [BP + -4h],1h
L_0a84:
	MOV        word ptr [BP + -6h],5h
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX
	MOV        DI,word ptr [BP + -0ah]
	SHL        DI,CL
	MOV        SI,5h
	MOV        AX,word ptr [BP + -0ah]
	MOV        CX,AX
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,CX
	ADD        word ptr [BP + -4h],AX
	MOV        DX,word ptr [BP + -2h]
	MOV        CX,word ptr [BP + -0ch]
L_0aaf:
	MOV        BX,CX
	ADD        BX,DX
	MOV        AL,DS:[0bb15h]
	MOV        byte ptr [BX + 0ad14h],AL
	ADD        DX,word ptr [BP + -8h]
	ADD        CX,DI
	DEC        SI
	JZ         L_0ae2
	JMP        L_0aaf
L_0ac4:
	INC        word ptr [BP + -0ah]
	MOV        word ptr [BP + -2h],9h
	JMP        L_0a84
L_0ace:
	INC        word ptr [BP + -8h]
	MOV        word ptr [BP + -4h],9h
	JMP        L_0a84
L_0ad8:
	INC        word ptr [BP + -0ah]
	MOV        word ptr [BP + -2h],1h
	JMP        L_0a84
L_0ae2:
	MOV        word ptr [BP + -2h],DX
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0a48 ENDP
F_0aee PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,10h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -8h],0h
	MOV        word ptr [BP + -0ah],0h
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_0b18
	CMP        AX,1h
	JZ         L_0b68
	CMP        AX,2h
	JZ         L_0b78
	CMP        AX,3h
	JZ         L_0b88
	JMP        L_0b25
L_0b18:
	INC        word ptr [BP + -8h]
	MOV        word ptr [BP + -2h],2h
	MOV        word ptr [BP + -4h],1h
L_0b25:
	MOV        word ptr [BP + -6h],7h
	MOV        AX,word ptr [BP + -4h]
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -0ch],AX
	MOV        DI,word ptr [BP + -0ah]
	SHL        DI,CL
	MOV        SI,7h
	MOV        AX,word ptr [BP + -0ah]
	MOV        CX,AX
	SHL        AX,1h
	ADD        AX,CX
	SHL        AX,1h
	ADD        AX,CX
	ADD        word ptr [BP + -4h],AX
	MOV        DX,word ptr [BP + -2h]
	MOV        CX,word ptr [BP + -0ch]
L_0b52:
	MOV        BX,CX
	ADD        BX,DX
	MOV        AL,DS:[0bb15h]
	MOV        byte ptr [BX + 0ad14h],AL
	ADD        DX,word ptr [BP + -8h]
	ADD        CX,DI
	DEC        SI
	JZ         L_0b92
	JMP        L_0b52
	db 90h
L_0b68:
	INC        word ptr [BP + -0ah]
	MOV        word ptr [BP + -2h],9h
L_0b70:
	MOV        word ptr [BP + -4h],2h
	JMP        L_0b25
	db 90h
L_0b78:
	INC        word ptr [BP + -8h]
	MOV        word ptr [BP + -2h],2h
	MOV        word ptr [BP + -4h],9h
	JMP        L_0b25
	db 90h
L_0b88:
	INC        word ptr [BP + -0ah]
	MOV        word ptr [BP + -2h],1h
	JMP        L_0b70
L_0b92:
	MOV        word ptr [BP + -2h],DX
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0aee ENDP
F_0b9e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,6h
	PUSH       SI
	MOV        AL,DS:[5896h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
	MOV        AL,DS:[5897h]
	MOV        word ptr [BP + -4h],AX
	MOV        AX,word ptr [BP + 4h]
	OR         AX,AX
	JZ         L_0bd4
	CMP        AX,1h
	JNZ        L_0bc2
	JMP        L_0c4c
L_0bc2:
	CMP        AX,2h
	JNZ        L_0bca
	JMP        L_0c52
L_0bca:
	CMP        AX,3h
	JNZ        L_0bd2
	JMP        L_0c58
L_0bd2:
	JMP        L_0bd7
L_0bd4:
	DEC        word ptr [BP + -4h]
L_0bd7:
	MOV        SI,word ptr [BP + -4h]
	AND        SI,7h
	MOV        CL,3h
	SHL        SI,CL
	MOV        AX,word ptr [BP + -2h]
	AND        AX,7h
	ADD        SI,AX
	MOV        BL,byte ptr DS:[5895h]
	SUB        BH,BH
	MOV        CL,6h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + SI + 595ah]
	MOV        byte ptr [BP + -6h],AL
	AND        byte ptr [BP + -6h],0f0h
	CMP        byte ptr [BP + -6h],0a0h
	JNC        L_0c0b
	PUSH       word ptr [BP + 4h]
	CALL       F_0aee
L_0c0b:
	CMP        byte ptr [BP + -6h],0b0h
	JZ         L_0c1d
	CMP        byte ptr [BP + -6h],0c0h
	JZ         L_0c1d
	CMP        byte ptr [BP + -6h],0d0h
	JNZ        L_0c5e
L_0c1d:
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
	AND        AX,0f0h
	PUSH       AX
	PUSH       word ptr [BP + 4h]
	CALL       F_097e
	JMP        L_0c64
L_0c4c:
	INC        word ptr [BP + -2h]
	JMP        L_0bd7
	db 90h
L_0c52:
	INC        word ptr [BP + -4h]
	JMP        L_0bd7
L_0c58:
	DEC        word ptr [BP + -2h]
	JMP        L_0bd7
L_0c5e:
	PUSH       word ptr [BP + 4h]
	CALL       F_0a48
L_0c64:
	POP        SI
	MOV        SP,BP
	POP        BP
	RET        2h
	db 90h
	; Func
F_0b9e ENDP
F_0c6c PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,0ah
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2h],0ad34h
	MOV        CX,0bh
	PUSH       DI
	MOV        DI,0ad34h
	MOV        AX,DS
	MOV        ES,AX
	MOV        AL,DS:[0bb14h]
	REP STOSB
	POP        DI
	MOV        word ptr [BP + -2h],0ae34h
	MOV        CX,0bh
	PUSH       DI
	MOV        DI,0ae34h
	MOV        AX,DS
	MOV        AL,DS:[0bb14h]
	REP STOSB
	POP        DI
	MOV        word ptr [BP + -4h],0bh
	MOV        DI,0ad15h
	MOV        SI,0ad1dh
L_0ca9:
	MOV        AL,DS:[0bb14h]
	MOV        byte ptr [SI],AL
	MOV        byte ptr [DI],AL
	ADD        DI,20h
	ADD        SI,20h
	CMP        SI,0ae7dh
	JC         L_0ca9
	MOV        AL,0ffh
	MOV        DS:[0ae5eh],AL
	MOV        DS:[0ae54h],AL
	MOV        DS:[0ad1eh],AL
	MOV        DS:[0ad14h],AL
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
	MOV        byte ptr [BP + -6h],AL
	AND        byte ptr [BP + -6h],0f0h
	JZ         L_0d29
	CMP        byte ptr [BP + -6h],80h
	JNC        L_0d29
	MOV        CL,4h
	SHR        byte ptr [BP + -6h],CL
	MOV        BL,byte ptr [BP + -6h]
	MOV        AL,byte ptr [BX + 244ah]
	MOV        byte ptr [BP + -0ah],AL
	CMP        AL,BH
	JZ         L_0d10
	MOV        DS:[0adb9h],AL
L_0d10:
	CMP        byte ptr [BP + -6h],3h
	JNZ        L_0d24
	MOV        byte ptr DS:[0bb16h],1h
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_cd2c
	JMP        L_0d29
	db 90h
L_0d24:
	MOV        byte ptr DS:[0bb16h],0h
L_0d29:
	SUB        SI,SI
L_0d2b:
	PUSH       SI
	CALL       F_0b9e
	INC        SI
	CMP        SI,4h
	JL         L_0d2b
	MOV        word ptr [BP + -4h],SI
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	; Func
F_0c6c ENDP
F_0d3e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,38h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -2eh],0bh
	MOV        SI,0ad14h
L_0d4e:
	MOV        DI,SI
	MOV        CX,0bh
	PUSH       DI
	MOV        AX,DS
	MOV        ES,AX
	MOV        AL,DS:[0bb15h]
	REP STOSB
	POP        DI
	ADD        SI,20h
	CMP        SI,0ae74h
	JC         L_0d4e
	MOV        word ptr [BP + -32h],DI
	TEST       byte ptr DS:[58a1h],4h
	JZ         L_0d76
	MOV        byte ptr DS:[0adb9h],0b3h
L_0d76:
	CALL       F_0c6c
	SUB        SI,SI
L_0d7b:
	MOV        AL,0ffh
	MOV        byte ptr [SI + 0ae27h],AL
	MOV        byte ptr [SI + 0ae1fh],AL
	INC        SI
	CMP        SI,8h
	JL         L_0d7b
	MOV        word ptr [BP + -2eh],SI
	MOV        DI,0ad7fh
	MOV        word ptr [BP + -8h],0ad5fh
	MOV        word ptr [BP + -4h],0ad9fh
	MOV        word ptr [BP + -0ch],0ad3fh
	SUB        SI,SI
	MOV        CL,byte ptr DS:[58a1h]
L_0da6:
	TEST       CL,4h
	JZ         L_0dc2
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [SI + 2452h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -4h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -8h]
	MOV        byte ptr [BX],AL
	MOV        byte ptr [DI],AL
	JMP        L_0de3
L_0dc2:
	MOV        AL,byte ptr [SI + 2470h]
	MOV        byte ptr [DI],AL
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [SI + 246ah]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [SI + 245eh]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [SI + 2464h]
	MOV        byte ptr [BX],AL
L_0de3:
	INC        DI
	INC        word ptr [BP + -8h]
	INC        word ptr [BP + -4h]
	INC        word ptr [BP + -0ch]
	INC        SI
	CMP        SI,6h
	JL         L_0da6
	MOV        word ptr [BP + -32h],DI
	MOV        word ptr [BP + -2eh],SI
	SUB        SI,SI
	MOV        CL,byte ptr DS:[58a1h]
L_0dff:
	TEST       CL,4h
	JZ         L_0e1c
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [SI + 2458h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -4h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -8h]
	MOV        byte ptr [BX],AL
	MOV        byte ptr [DI],AL
	JMP        L_0e3d
	db 90h
L_0e1c:
	MOV        AL,byte ptr [SI + 2464h]
	MOV        byte ptr [DI],AL
	MOV        BX,word ptr [BP + -8h]
	MOV        AL,byte ptr [SI + 245eh]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -4h]
	MOV        AL,byte ptr [SI + 246ah]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [SI + 2470h]
	MOV        byte ptr [BX],AL
L_0e3d:
	INC        DI
	INC        word ptr [BP + -8h]
	INC        word ptr [BP + -4h]
	INC        word ptr [BP + -0ch]
	INC        SI
	CMP        SI,6h
	JL         L_0dff
	MOV        word ptr [BP + -32h],DI
	MOV        word ptr [BP + -2eh],SI
	MOV        word ptr [BP + -6h],0addfh
	MOV        DI,0adffh
	SUB        SI,SI
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	MOV        CX,AX
	MOV        DL,byte ptr DS:[58a1h]
L_0e68:
	TEST       DL,4h
	JZ         L_0e7e
	MOV        AL,byte ptr [SI + 24c6h]
	MOV        byte ptr [DI],AL
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [SI + 24b6h]
	MOV        byte ptr [BX],AL
	JMP        L_0ea5
L_0e7e:
	MOV        AX,CX
	OR         AX,AX
	JZ         L_0e96
	CMP        AX,1h
	JZ         L_0eb2
	CMP        AX,2h
	JZ         L_0ec2
	CMP        AX,3h
	JZ         L_0ed2
	JMP        L_0ea5
	db 90h
L_0e96:
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [SI + 2476h]
	MOV        byte ptr [BX],AL
	MOV        AL,byte ptr [SI + 2496h]
L_0ea3:
	MOV        byte ptr [DI],AL
L_0ea5:
	INC        word ptr [BP + -6h]
	INC        DI
	INC        SI
	CMP        SI,10h
	JGE        L_0ee2
	JMP        L_0e68
	db 90h
L_0eb2:
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [SI + 2486h]
	MOV        byte ptr [BX],AL
	MOV        AL,byte ptr [SI + 24a6h]
	JMP        L_0ea3
	db 90h
L_0ec2:
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [SI + 24a6h]
	MOV        byte ptr [BX],AL
	MOV        AL,byte ptr [SI + 2486h]
	JMP        L_0ea3
	db 90h
L_0ed2:
	MOV        BX,word ptr [BP + -6h]
	MOV        AL,byte ptr [SI + 2496h]
	MOV        byte ptr [BX],AL
	MOV        AL,byte ptr [SI + 2476h]
	JMP        L_0ea3
	db 90h
L_0ee2:
	MOV        word ptr [BP + -0ah],DI
	MOV        word ptr [BP + -2eh],SI
	SUB        SI,SI
	MOV        DI,BP
	SUB        DI,2ch
L_0eef:
	MOV        word ptr [DI],SI
	ADD        DI,2h
	INC        SI
	CMP        SI,10h
	JL         L_0eef
	MOV        word ptr [BP + -2eh],SI
	SUB        DI,DI
	MOV        SI,BP
	SUB        SI,2ch
L_0f04:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,0fh
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        word ptr [BP + -30h],AX
	MOV        AX,word ptr [SI]
	MOV        word ptr [BP + -2h],AX
	MOV        AX,word ptr [BP + -30h]
	SHL        AX,1h
	ADD        AX,BP
	SUB        AX,2ch
	MOV        word ptr [BP + -36h],AX
	MOV        BX,AX
	MOV        AX,word ptr [BX]
	MOV        word ptr [SI],AX
	MOV        AX,word ptr [BP + -2h]
	MOV        word ptr [BX],AX
	MOV        byte ptr [DI + 0adbfh],0h
	ADD        SI,2h
	INC        DI
	CMP        DI,10h
	JL         L_0f04
	MOV        word ptr [BP + -2eh],DI
	TEST       byte ptr DS:[58a1h],4h
	JZ         L_0f58
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 173ch]
	JMP        L_0f5b
L_0f58:
	MOV        AL,DS:[5c67h]
L_0f5b:
	SUB        AH,AH
	MOV        word ptr [BP + -30h],AX
	MOV        SI,AX
	MOV        CL,3h
	SHL        SI,CL
	ADD        SI,13c2h
	MOV        AX,1h
	PUSH       AX
	MOV        AL,byte ptr [SI]
	SUB        AH,AH
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        word ptr [BP + -2h],AX
	CMP        byte ptr [SI],8h
	JZ         L_0f83
	CMP        byte ptr [SI],10h
	JNZ        L_0f93
L_0f83:
	MOV        BX,word ptr [BP + -30h]
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,byte ptr [BX + 13c2h]
	SUB        AH,AH
	MOV        word ptr [BP + -2h],AX
L_0f93:
	MOV        word ptr [BP + -2eh],0h
	CMP        word ptr [BP + -2h],0h
	JLE        L_0fd3
	MOV        AL,byte ptr [BP + -30h]
	SHL        AL,1h
	SHL        AL,1h
	ADD        AL,40h
	MOV        byte ptr [BP + -36h],AL
	MOV        SI,BP
	SUB        SI,2ch
	MOV        DI,word ptr [BP + -2h]
	SHL        DI,1h
	LEA        AX,[BP + DI + -2ch]
	MOV        word ptr [BP + -38h],AX
	MOV        AX,word ptr [BP + -2h]
	ADD        word ptr [BP + -2eh],AX
	MOV        CX,word ptr [BP + -38h]
L_0fc3:
	MOV        BX,word ptr [SI]
	MOV        AL,byte ptr [BP + -36h]
	MOV        byte ptr [BX + 0adbfh],AL
	ADD        SI,2h
	CMP        SI,CX
	JNZ        L_0fc3
L_0fd3:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET
	db 90h
	db 0A0h
	db 0A0h
	db 58h
	db 2Ah
	db 0E4h
	db 3Dh
	db 01h
	db 00h
	db 74h
	db 72h
	db 3Dh
	db 02h
	db 00h
	db 74h
	db 39h
	db 3Dh
	db 03h
	db 00h
	db 74h
	db 16h
	db 3Dh
	db 04h
	db 00h
	db 74h
	db 49h
	db 3Dh
	db 05h
	db 00h
	db 74h
	db 78h
	db 3Dh
	db 06h
	db 00h
	db 75h
	db 03h
	db 0E9h
	db 82h
	db 00h
	db 0E9h
	db 9Ah
	db 00h
	db 90h
	db 0FEh
	db 0Eh
	db 97h
	db 58h
	db 2Ah
	db 0C0h
	db 0A2h
	db 03h
	db 66h
	db 0A2h
	db 02h
	db 66h
	db 80h
	db 3Eh
	db 97h
	db 58h
	db 07h
	db 77h
	db 03h
	db 0E9h
	db 83h
	db 00h
	db 0C6h
	db 06h
	db 97h
	db 58h
	db 07h
	db 0EBh
	db 7Ch
	db 90h
	db 0FEh
	db 06h
	db 96h
	db 58h
	db 0B0h
	db 01h
	db 0A2h
	db 03h
	db 66h
	db 0A2h
	db 02h
	db 66h
	db 80h
	db 3Eh
	db 96h
	db 58h
	db 07h
	db 76h
	db 68h
	db 0C6h
	db 06h
	db 96h
	db 58h
	db 00h
	db 0EBh
	db 61h
	db 0FEh
	db 06h
	db 97h
	db 58h
	db 0B0h
	db 02h
	db 0A2h
	db 03h
	db 66h
	db 0A2h
	db 02h
	db 66h
	db 80h
	db 3Eh
	db 97h
	db 58h
	db 07h
	db 76h
	db 4Eh
	db 0C6h
	db 06h
	db 97h
	db 58h
	db 00h
	db 0EBh
	db 47h
	db 0FEh
	db 0Eh
	db 96h
	db 58h
	db 0B0h
	db 03h
	db 0A2h
	db 03h
	db 66h
	db 0A2h
	db 02h
	db 66h
	db 80h
	db 3Eh
	db 96h
	db 58h
	db 07h
	db 76h
	db 34h
	db 0C6h
	db 06h
	db 96h
	db 58h
	db 07h
	db 0EBh
	db 2Dh
	db 80h
	db 3Eh
	db 95h
	db 58h
	db 00h
	db 74h
	db 12h
	db 0FEh
	db 0Eh
	db 95h
	db 58h
	db 0C6h
	db 06h
	db 02h
	db 66h
	db 04h
	db 0EBh
	db 1Bh
	db 80h
	db 3Eh
	db 95h
	db 58h
	db 07h
	db 75h
	db 0Bh
	db 0E8h
	db 82h
	db 0C9h
	db 0C6h
	db 06h
	db 93h
	db 58h
	db 00h
	db 0EBh
	db 0Ah
	db 90h
	db 0FEh
	db 06h
	db 95h
	db 58h
	db 0C6h
	db 06h
	db 02h
	db 66h
	db 05h
	db 0C3h
	; Func
F_0d3e ENDP
F_109e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	CMP        byte ptr DS:[5893h],0h
	JNZ        L_10ab
	JMP        L_112b
L_10ab:
	TEST       byte ptr DS:[0bb17h],2h
	JZ         L_10b5
	CALL       SUB_0000_6d9e
L_10b5:
	TEST       byte ptr DS:[0bb17h],1h
	JNZ        L_10e0
L_10bc:
	MOV        BL,byte ptr DS:[6604h]
	SUB        BH,BH
	SHL        BX,1h
	PUSH       word ptr [BX + 25f2h]
	CALL       SUB_0000_691e
	MOV        DS:[0a9c0h],AX
	OR         AX,AX
	JZ         L_10bc
L_10d2:
	PUSH       word ptr DS:[25f2h]
	CALL       SUB_0000_691e
	MOV        DS:[0a9c4h],AX
	OR         AX,AX
	JZ         L_10d2
L_10e0:
	MOV        byte ptr DS:[0bb17h],1h
	CMP        word ptr [BP + 4h],0h
	JZ         L_10fe
	SUB        AL,AL
	MOV        DS:[5c63h],AL
	MOV        DS:[5c62h],AL
	MOV        AL,0ffh
	MOV        DS:[5c65h],AL
	MOV        DS:[5c64h],AL
	MOV        DS:[5c67h],AL
L_10fe:
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
	MOV        AX,1h
	PUSH       AX
	CALL       SUB_0000_6992
	MOV        AX,8h
	PUSH       AX
	PUSH       AX
	MOV        AX,0b7h
	PUSH       AX
	PUSH       AX
	CALL       SUB_0000_6816
	SUB        AX,AX
	PUSH       AX
	CALL       SUB_0000_6992
L_112b:
	POP        BP
	RET        2h
	db 90h
	db 0F6h
	db 06h
	db 17h
	db 0BBh
	db 01h
	db 74h
	db 22h
	db 80h
	db 3Eh
	db 67h
	db 5Ch
	db 0FFh
	db 74h
	db 07h
	db 0FFh
	db 36h
	db 0C6h
	db 0A9h
	db 0E8h
	db 0Fh
	db 58h
	db 0C7h
	db 06h
	db 0C6h
	db 0A9h
	db 00h
	db 00h
	db 0FFh
	db 36h
	db 0C4h
	db 0A9h
	db 0E8h
	db 02h
	db 58h
	db 0FFh
	db 36h
	db 0C0h
	db 0A9h
	db 0E8h
	db 0FBh
	db 57h
	db 0F6h
	db 06h
	db 17h
	db 0BBh
	db 02h
	db 75h
	db 0Bh
	db 0FFh
	db 36h
	db 0F0h
	db 25h
	db 0E8h
	db 0FDh
	db 5Bh
	db 0Bh
	db 0C0h
	db 74h
	db 0F5h
	db 0F6h
	db 06h
	db 17h
	db 0BBh
	db 04h
	db 75h
	db 06h
	db 2Bh
	db 0C0h
	db 50h
	db 0E8h
	db 96h
	db 0BBh
	db 0C6h
	db 06h
	db 17h
	db 0BBh
	db 06h
	db 0C3h
	; Func
F_109e ENDP
F_117e PROC NEAR
	PUSH       BP
	MOV        BP,SP
	SUB        SP,20h
	PUSH       DI
	PUSH       SI
	MOV        word ptr [BP + -0ah],0bh
	MOV        word ptr [BP + -0ch],11h
	MOV        word ptr [BP + -2h],4h
	CMP        word ptr [BP + 4h],1h
	JNZ        L_119e
	JMP        L_1248
L_119e:
	MOV        AL,DS:[6603h]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_11bc
	CMP        AX,1h
	JNZ        L_11af
	JMP        L_1232
L_11af:
	CMP        AX,3h
	JNZ        L_11b7
	JMP        L_123a
L_11b7:
	CMP        AX,5h
	JNZ        L_11c1
L_11bc:
	MOV        word ptr [BP + -2h],3h
L_11c1:
	CALL       SUB_0000_c6a6
	MOV        word ptr [BP + -0eh],0h
	MOV        AL,DS:[585bh]
	SUB        AH,AH
	OR         AX,AX
	JZ         L_1248
	MOV        word ptr [BP + -16h],AX
	MOV        AX,word ptr [BP + -2h]
	MOV        CL,5h
	SHL        AX,CL
	MOV        word ptr [BP + -18h],AX
	MOV        SI,0ba1ah
	MOV        DI,5c5ch
	MOV        word ptr [BP + -1eh],0ba1bh
	MOV        word ptr [BP + -20h],5c5dh
	MOV        DX,word ptr [BP + -0ch]
	MOV        CX,word ptr [BP + -0ah]
L_11f5:
	MOV        BX,word ptr [BP + -18h]
	ADD        BX,CX
	MOV        AL,byte ptr [BX + 0ad14h]
	MOV        byte ptr [DI],AL
	MOV        byte ptr [SI],AL
	MOV        BX,word ptr [BP + -18h]
	ADD        BX,DX
	MOV        AL,byte ptr [BX + 0ad14h]
	MOV        BX,word ptr [BP + -20h]
	MOV        byte ptr [BX],AL
	MOV        BX,word ptr [BP + -1eh]
	MOV        byte ptr [BX],AL
	INC        CX
	INC        DX
	ADD        SI,8h
	ADD        DI,8h
	ADD        word ptr [BP + -1eh],8h
	ADD        word ptr [BP + -20h],8h
	INC        word ptr [BP + -0eh]
	MOV        AX,word ptr [BP + -16h]
	CMP        word ptr [BP + -0eh],AX
	JZ         L_1242
	JMP        L_11f5
L_1232:
	MOV        word ptr [BP + -2h],2h
	JMP        L_11c1
	db 90h
L_123a:
	MOV        word ptr [BP + -2h],1h
	JMP        L_11c1
L_1242:
	MOV        word ptr [BP + -0ch],DX
	MOV        word ptr [BP + -0ah],CX
L_1248:
	CMP        word ptr [BP + 4h],0h
	JG         L_1251
	JMP        L_139c
L_1251:
	CMP        word ptr [BP + 6h],0efh
	JLE        L_125e
	CMP        word ptr [BP + 4h],3h
	JZ         L_1267
L_125e:
	CMP        word ptr [BP + 4h],3h
	JL         L_1267
	JMP        L_139c
L_1267:
	MOV        AX,0bh
	MOV        word ptr [BP + -0ah],AX
	MOV        word ptr [BP + -0ch],AX
	MOV        word ptr [BP + -2h],AX
	SUB        SI,SI
L_1275:
	SUB        AX,AX
	PUSH       AX
	MOV        AX,7h
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,AX
	MOV        AL,byte ptr [BX + 385eh]
	MOV        byte ptr [BP + SI + -6h],AL
	INC        SI
	CMP        SI,4h
	JL         L_1275
	MOV        word ptr [BP + -0eh],SI
	MOV        word ptr [BP + -0eh],10h
	MOV        word ptr [BP + -20h],10h
	MOV        DI,word ptr [BP + -10h]
	MOV        SI,word ptr [BP + -14h]
L_12a1:
	MOV        BX,word ptr [BP + -2h]
	MOV        AL,byte ptr [BX + 0adb4h]
	MOV        byte ptr [BP + -8h],AL
	OR         AL,AL
	JNZ        L_12b2
	JMP        L_1385
L_12b2:
	CMP        AL,40h
	JC         L_12c5
	AND        AL,0fch
	CMP        AL,0b4h
	JZ         L_12c5
	MOV        AL,byte ptr [BP + -8h]
	AND        AL,0fch
	CMP        AL,0e8h
	JNZ        L_12d2
L_12c5:
	MOV        word ptr [BP + -12h],2h
	MOV        AL,byte ptr [BP + -8h]
	SUB        AH,AH
	JMP        L_12e3
	db 90h
L_12d2:
	MOV        word ptr [BP + -12h],0h
	MOV        AL,byte ptr [BP + -8h]
	SUB        AH,AH
	SUB        AX,40h
	SHR        AX,1h
	SHR        AX,1h
L_12e3:
	MOV        SI,AX
	MOV        AL,byte ptr [BP + -8h]
	AND        AL,0fch
	CMP        AL,0ech
	JNZ        L_12fe
	MOV        BL,byte ptr [BP + -8h]
	AND        BX,3h
	ADD        BX,BP
	MOV        AL,byte ptr [BX + -6h]
	SUB        AH,AH
	MOV        SI,AX
L_12fe:
	PUSH       SI
	PUSH       word ptr [BP + -12h]
	MOV        BX,word ptr [BP + -0ah]
	MOV        AL,byte ptr [BX + 0add4h]
	SUB        AH,AH
	PUSH       AX
	MOV        BX,word ptr [BP + -0ch]
	MOV        AL,byte ptr [BX + 0adf4h]
	PUSH       AX
	MOV        AL,DS:[5895h]
	PUSH       AX
	CALL       SUB_0000_c276
	MOV        DI,AX
	CMP        word ptr [BP + -12h],2h
	JNZ        L_1385
	CMP        SI,1h
	JNZ        L_133c
	MOV        BX,DI
	MOV        CL,3h
	SHL        BX,CL
	MOV        AL,DS:[5895h]
	MOV        CX,AX
	SHL        AL,1h
	ADD        AL,CL
	ADD        AL,7h
	JMP        L_1381
	db 90h
L_133c:
	CMP        SI,2h
	JNZ        L_1360
	MOV        AX,1h
	PUSH       AX
	MOV        AL,DS:[5895h]
	SUB        AH,AH
	MOV        CX,AX
	SHL        AX,1h
	SHL        AX,1h
	ADD        AX,CX
	SHL        AX,1h
	ADD        AX,0ah
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        BX,DI
	JMP        L_137d
	db 90h
L_1360:
	CMP        SI,10h
	JGE        L_1385
	SUB        AX,AX
	PUSH       AX
	MOV        AL,byte ptr [SI + 383fh]
	SUB        AH,AH
	DEC        AX
	PUSH       AX
	CALL       SUB_0000_7e02
	MOV        CL,byte ptr [SI + 384dh]
	ADD        CL,AL
	MOV        BX,DI
	MOV        AX,CX
L_137d:
	MOV        CL,3h
	SHL        BX,CL
L_1381:
	MOV        byte ptr [BX + 5c5fh],AL
L_1385:
	INC        word ptr [BP + -2h]
	INC        word ptr [BP + -0ah]
	INC        word ptr [BP + -0ch]
	DEC        word ptr [BP + -20h]
	JZ         L_1396
	JMP        L_12a1
L_1396:
	MOV        word ptr [BP + -10h],DI
	MOV        word ptr [BP + -14h],SI
L_139c:
	POP        SI
	POP        DI
	MOV        SP,BP
	POP        BP
	RET        4h
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
	db 00h
	db 00h
F_117e ENDP
_TEXT ENDS
END
