;	Static Name Aliases
;
	TITLE   intro.c
	NAME    intro

	.8087
_TEXT	SEGMENT  WORD PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT  WORD PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT  WORD PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT  WORD PUBLIC 'BSS'
_BSS	ENDS
DGROUP	GROUP	CONST, _BSS, _DATA
	ASSUME  CS: _TEXT, DS: DGROUP, SS: DGROUP
EXTRN	__acrtused:ABS
EXTRN	FUN_0000_043E:NEAR
EXTRN	FUN_0000_072E:NEAR
EXTRN	FUN_0000_06BC:NEAR
EXTRN	FUNC_0X0000CA6A:NEAR
EXTRN	FUNC_0X0000CB0E:NEAR
EXTRN	FUNC_0X00009978:NEAR
EXTRN	FUN_1000_1C9E:NEAR
EXTRN	FUN_1000_1C22:NEAR
EXTRN	FUN_1000_1B94:NEAR
EXTRN	FUN_1000_2032:NEAR
EXTRN	FUN_1000_1D5E:NEAR
EXTRN	FUN_1000_16BA:NEAR
EXTRN	FUN_1000_1BF2:NEAR
EXTRN	FUN_1000_1850:NEAR
EXTRN	_FUN_1000_02F4:NEAR
EXTRN	FUNC_0X00008E34:NEAR
EXTRN	FUN_1000_0FAE_LOAD_FILE:NEAR
EXTRN	FUNC_0X0000A3AE:NEAR
EXTRN	FUNC_0X0000E1BE:NEAR
EXTRN	FUNC_0X0000ACD6:NEAR
EXTRN	FUN_1000_0DE0:NEAR
EXTRN	FUNC_0X00008BB2:NEAR
EXTRN	FUN_1000_1158:NEAR
EXTRN	FUNC_0X00008A62:NEAR
EXTRN	FUNC_0X000088E6:NEAR
EXTRN	FUN_1000_0E94:NEAR
EXTRN	FUNC_0X00008E84:NEAR
EXTRN	FUNC_0X0000A35E:NEAR
EXTRN	FUNC_0X0000890E:NEAR
EXTRN	FUNC_0X00009C1A:NEAR
EXTRN	FUNC_0X00009F3A:NEAR
EXTRN	FUN_1000_0892:NEAR
EXTRN	FUN_0000_094E:NEAR
EXTRN	FUNC_0X0000A418:NEAR
EXTRN	FUNC_0X00008DAE:NEAR
EXTRN	FUNC_0X000094B4:NEAR
EXTRN	FUNC_0X00008E1C:NEAR
EXTRN	FUN_0000_132A:NEAR
EXTRN	FUN_0000_05B0:NEAR
EXTRN	FUNC_0X0000FB1A:NEAR
EXTRN	FUNC_0X0000FB0E:NEAR
EXTRN	FUNC_0X00009EBE:NEAR
EXTRN	FUN_1000_0F2A:NEAR
EXTRN	FUN_0000_0010:NEAR
EXTRN	FUNC_0X00009E96:NEAR
EXTRN	FUN_1000_0878:NEAR
EXTRN	FUN_0000_014E:NEAR
EXTRN	FUN_1000_1D02:NEAR
EXTRN	FUNC_0X00008E6E:NEAR
EXTRN	D_BB18:WORD
EXTRN	D_25EA:WORD
EXTRN	D_25EC:WORD
EXTRN	D_25EE:WORD
EXTRN	D_25F0:WORD
EXTRN	D_52BA:WORD
EXTRN	D_52BE:WORD
EXTRN	D_52C8:WORD
EXTRN	D_52F1:WORD
EXTRN	D_5356:WORD
EXTRN	D_5358:WORD
EXTRN	D_5893_MAP_ID:BYTE
EXTRN	D_5895:BYTE
_BSS      SEGMENT
COMM NEAR	D_535E:	BYTE:	 32
EXTRN	D_A9CB:BYTE
EXTRN	D_A9CE:BYTE
EXTRN	D_B11E:BYTE
EXTRN	D_13AE:WORD
EXTRN	D_13B0:WORD
EXTRN	D_13B2:WORD
EXTRN	D_13B4:WORD
EXTRN	D_13B6:WORD
EXTRN	D_13B8:WORD
EXTRN	D_13BA:WORD
EXTRN	D_55A6:WORD
EXTRN	D_55A8_PARTY:BYTE
EXTRN	D_6606:WORD
_BSS      ENDS
_DATA      SEGMENT
$SG449	DB	'ibm.hcs',  00H
$SG453	DB	'runes.hcs',  00H
$SG458	DB	'ibm.ch',  00H
$SG462	DB	'runes.ch',  00H
$SG472	DB	'Journey Onward',  0aH,  0aH,  00H
$SG486	DB	'BRITISH.PTH',  00H
$SG535	DB	'JCTUAR',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 9
	PUBLIC	F_INTRO_0010
F_INTRO_0010	PROC NEAR
	ret	
	nop	

F_INTRO_0010	ENDP
; Line 10
	PUBLIC	F_INTRO_0050
F_INTRO_0050	PROC NEAR
	push	bp
;	a = 6
;	b = 4
	pop	bp
	ret	4
	nop	

F_INTRO_0050	ENDP
; Line 11
	PUBLIC	F_INTRO_014E
F_INTRO_014E	PROC NEAR
	ret	
	nop	

F_INTRO_014E	ENDP
; Line 12
	PUBLIC	F_INTRO_043E
F_INTRO_043E	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_043E	ENDP
; Line 13
	PUBLIC	F_INTRO_04E0
F_INTRO_04E0	PROC NEAR
	ret	
	nop	

F_INTRO_04E0	ENDP
; Line 14
	PUBLIC	F_INTRO_05B0
F_INTRO_05B0	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_05B0	ENDP
; Line 15
	PUBLIC	F_INTRO_0676
F_INTRO_0676	PROC NEAR
	push	bp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	pop	bp
	ret	8
	nop	

F_INTRO_0676	ENDP
; Line 16
	PUBLIC	F_INTRO_06BC
F_INTRO_06BC	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_06BC	ENDP
; Line 17
	PUBLIC	F_INTRO_072E
F_INTRO_072E	PROC NEAR
	ret	
	nop	

F_INTRO_072E	ENDP
; Line 18
	PUBLIC	F_INTRO_094E
F_INTRO_094E	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_094E	ENDP
; Line 23
	PUBLIC	F_INTRO_0986
F_INTRO_0986	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,18
	push	di
	push	si
;	local_4 = -14
;	local_6 = -2
;	local_8 = -4
;	local_a = -8
;	local_c = -12
;	local_e = -18
;	local_10 = -6
;	local_12 = -10
;	local_14 = -16
; Line 35
	mov	BYTE PTR D_A9CE,1
; Line 39
	sub	si,si
$L20000:
; Line 40
	mov	ax,si
	mov	BYTE PTR D_B11E[si],al
; Line 41
	inc	si
	cmp	si,256
	jl	$L20000
	mov	WORD PTR [bp-18],si	;local_e
; Line 43
	call	FUN_1000_0DE0
; Line 44
	call	FUN_1000_1158
; Line 45
	mov	ax,D_5356
	mov	WORD PTR [bp-4],ax	;local_8
; Line 48
	cmp	WORD PTR D_52C8,2
	jne	$L20002
	cmp	WORD PTR D_5358,368
	jae	$L20002
; Line 49
	mov	WORD PTR D_52F1,0
; Line 50
	mov	WORD PTR D_52BA,1
; Line 51
	mov	WORD PTR D_52C8,0
; Line 52
; Line 55
$L20002:
	call	FUN_1000_0E94
	or	ax,ax
	je	$L20002
; Line 57
	mov	ax,1
	push	ax
	call	FUN_1000_0892
; Line 59
	cmp	WORD PTR D_52C8,0
	je	$I432
	cmp	WORD PTR D_52C8,3
	je	$I432
; Line 60
; Line 61
	mov	WORD PTR D_13B2,1
; Line 62
	mov	WORD PTR D_13AE,4
; Line 63
	mov	WORD PTR D_13B0,15
; Line 64
	mov	WORD PTR D_13B6,5
; Line 65
	mov	WORD PTR D_13B4,2
; Line 66
	mov	WORD PTR D_13B8,14
; Line 67
	mov	WORD PTR D_13BA,7
; Line 68
	jmp	SHORT $I433
$I432:
; Line 70
	sub	cx,cx
; Line 71
	mov	si,WORD PTR [bp-2]	;local_6
	jmp	SHORT $I440
	nop	
$L20004:
	inc	si
	cmp	BYTE PTR [si-1],46
	jne	$L20004
; Line 76
	cmp	BYTE PTR [si],49
	jne	$I440
; Line 77
	mov	BYTE PTR [si],52
	inc	si
; Line 78
	mov	BYTE PTR [si],0
; Line 79
; Line 80
$I440:
	mov	bx,cx
	inc	cx
	shl	bx,1
	mov	si,D_25EA[bx]
	cmp	BYTE PTR [si],0
	jne	$L20004
; Line 72
; Line 74
	mov	WORD PTR [bp-2],si	;local_6
	mov	WORD PTR [bp-18],cx	;local_e
; Line 81
$I433:
; Line 84
	call	FUN_1000_0F2A
	or	ax,ax
	jne	$I442
; Line 85
; Line 86
	call	FUN_1000_0878
; Line 87
	mov	ax,1
	push	ax
	call	_FUN_1000_02F4
	add	sp,2
; Line 89
; Line 90
$I442:
	cmp	WORD PTR D_52C8,3
	jne	$L20014
; Line 91
; Line 94
$L20010:
	mov	ax,OFFSET DGROUP:$SG449
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1D02
	or	ax,ax
	je	$L20010
$L20012:
	mov	ax,OFFSET DGROUP:$SG453
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1D02
	or	ax,ax
	jne	$I454
	jmp	SHORT $L20012
	nop	
$L20014:
	mov	ax,OFFSET DGROUP:$SG458
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1D02
	or	ax,ax
	je	$L20014
$L20016:
	mov	ax,OFFSET DGROUP:$SG462
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1D02
	or	ax,ax
	je	$L20016
; Line 105
$I454:
; Line 108
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 109
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22
; Line 110
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94
; Line 111
	call	FUN_1000_1D5E
	push	ax
	call	FUN_1000_2032
	mov	WORD PTR [bp-8],ax	;local_a
; Line 112
	cmp	ax,74
	jne	$I468
; Line 113
; Line 114
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 115
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 116
	sub	ax,ax
	push	ax
	mov	ax,11
	push	ax
	call	FUN_1000_1BF2
; Line 118
	mov	ax,OFFSET DGROUP:$SG472
	push	ax
	call	FUN_1000_1850
; Line 119
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 121
$L20018:
	push	WORD PTR D_25F0
	call	FUNC_0X00008E34
	or	ax,ax
	je	$L20018
; Line 122
	mov	BYTE PTR D_5893_MAP_ID,65
; Line 124
; Line 125
	jmp	$I477
	nop	
$I468:
; Line 126
; Line 128
	mov	WORD PTR [bp-8],1	;local_a
; Line 130
$D478:
; Line 131
	push	WORD PTR D_25EE
	call	FUN_1000_0FAE_LOAD_FILE
	mov	si,ax
; Line 132
	or	si,si
	je	$D478
	mov	WORD PTR [bp-10],si	;local_12
; Line 134
$D482:
; Line 135
	push	WORD PTR D_25EC
	call	FUN_1000_0FAE_LOAD_FILE
	mov	si,ax
; Line 136
	or	si,si
	je	$D482
	mov	WORD PTR [bp-16],si	;local_14
; Line 139
	mov	ax,OFFSET DGROUP:$SG486
	push	ax
	mov	ax,OFFSET D_55A6
	push	ax
	mov	ax,OFFSET D_6606
	sub	ax,OFFSET D_55A6
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X0000A3AE
; Line 140
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I487
; Line 141
	push	WORD PTR [bp-10]	;local_12
	call	FUNC_0X00008BB2
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 144
$I487:
	mov	ax,1
	push	ax
	call	FUNC_0X00008A62
; Line 145
	sub	ax,ax
	push	ax
	mov	ax,140
	push	ax
	mov	ax,319
	push	ax
	mov	ax,199
	push	ax
	call	FUNC_0X000088E6
; Line 146
	push	WORD PTR [bp-10]	;local_12
	mov	ax,7
	push	ax
	mov	ax,108
	push	ax
	mov	ax,140
	push	ax
	call	FUNC_0X00008E84
; Line 147
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	push	ax
	mov	ax,140
	push	ax
	mov	ax,319
	push	ax
	mov	ax,199
	push	ax
	call	FUNC_0X0000890E
; Line 148
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I493
; Line 149
; Line 150
	mov	ax,18
	push	ax
	call	FUNC_0X00009F3A
; Line 151
	mov	ax,20
	push	ax
	call	FUN_0000_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 152
; Line 154
$I493:
	cmp	WORD PTR [bp-8],0	;local_a
	jne	$JCC608
	jmp	$I500
$JCC608:
; Line 155
; Line 157
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 158
	push	WORD PTR [bp-10]	;local_12
	mov	ax,8
	push	ax
	mov	ax,152
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X00008E84
; Line 159
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X00008DAE
; Line 160
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 161
	or	cx,cx
	je	$I498
; Line 162
; Line 163
	sub	ax,ax
	push	ax
	call	FUNC_0X00008A62
; Line 164
	mov	WORD PTR D_BB18,0
; Line 165
	mov	WORD PTR [bp-8],0	;local_a
; Line 168
	mov	ax,44
	push	ax
	mov	ax,68
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I499
	mov	ax,64
	push	ax
	mov	ax,94
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I499
	mov	ax,143
	push	ax
	mov	ax,78
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I499
; Line 169
; Line 170
	mov	ax,167
	push	ax
	mov	ax,105
	push	ax
	call	F_INTRO_0050
	mov	WORD PTR [bp-8],ax	;local_a
; Line 171
; Line 173
$I499:
	mov	ax,1
	push	ax
	call	FUNC_0X00008A62
; Line 174
; Line 176
$I498:
	push	WORD PTR [bp-16]	;local_14
	sub	ax,ax
	push	ax
	mov	ax,24
	push	ax
	mov	ax,66
	push	ax
	call	FUNC_0X00008E84
; Line 177
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X00008DAE
; Line 178
	push	WORD PTR [bp-18]	;local_e
	mov	ax,9
	push	ax
	mov	ax,104
	push	ax
	mov	ax,160
	push	ax
	call	FUNC_0X00008E84
; Line 179
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X00008DAE
; Line 180
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I500
; Line 181
	mov	ax,20
	push	ax
	call	FUN_0000_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 182
; Line 183
$I500:
; Line 185
	push	WORD PTR [bp-16]	;local_14
	call	FUNC_0X00008E1C
; Line 186
	push	WORD PTR [bp-10]	;local_12
	call	FUNC_0X00008E1C
; Line 187
	mov	BYTE PTR D_5893_MAP_ID,64
; Line 188
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 189
	sub	ax,ax
	push	ax
	call	FUNC_0X00008A62
; Line 190
	push	WORD PTR [bp-8]	;local_a
	call	FUN_0000_05B0
; Line 191
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I503
; Line 192
	call	FUNC_0X0000FB1A
; Line 193
; Line 195
$I503:
	mov	WORD PTR [bp-8],1	;local_a
; Line 196
$I477:
; Line 197
	call	FUNC_0X00009E96
	push	ax
	call	FUNC_0X00009EBE
; Line 200
$D507:
; Line 201
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	mov	ax,16
	push	ax
	mov	ax,38
	push	ax
	mov	ax,23
	push	ax
	call	FUN_1000_1C22
; Line 202
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94
; Line 203
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 204
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22
; Line 205
	mov	ax,1
	push	ax
	mov	ax,24
	push	ax
	mov	ax,1
	push	ax
	mov	ax,39
	push	ax
	mov	ax,9
	push	ax
	call	FUN_1000_1C22
; Line 206
	mov	ax,2
	push	ax
	mov	ax,24
	push	ax
	mov	ax,11
	push	ax
	mov	ax,39
	push	ax
	mov	ax,23
	push	ax
	call	FUN_1000_1C22
; Line 207
	cmp	WORD PTR [bp-8],74	;local_a
	jne	$I510
; Line 208
; Line 209
	mov	BYTE PTR [bp-6],74	;local_10
; Line 210
; Line 211
	jmp	$I511
$I510:
; Line 212
; Line 215
	sub	di,di
; Line 216
	mov	ax,12737
	push	ax
	call	FUN_0000_043E
; Line 217
	sub	ax,ax
	push	ax
	call	FUN_0000_06BC
; Line 218
$D514:
; Line 220
	mov	ax,15
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 221
	call	FUNC_0X0000CA6A
; Line 222
	mov	ax,12765
	push	ax
	call	FUN_1000_1850
; Line 223
	call	FUNC_0X0000CB0E
; Line 224
	mov	ax,23
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_1BF2
; Line 225
	mov	WORD PTR D_5356,275
; Line 226
	sub	si,si
; Line 227
$D519:
; Line 229
	call	FUNC_0X00009978
	push	ax
	call	FUN_1000_2032
	mov	BYTE PTR [bp-6],al	;local_10
; Line 230
	or	al,al
	jne	$I523
; Line 231
	call	F_INTRO_2090
; Line 232
; Line 234
$I523:
	inc	si
; Line 235
	cmp	si,200
	jge	$L20034
	cmp	BYTE PTR [bp-6],0	;local_10
	je	$D519
$L20034:
	mov	WORD PTR [bp-14],si	;local_4
; Line 236
	mov	ax,WORD PTR [bp-4]	;local_8
	mov	D_5356,ax
; Line 238
	mov	al,BYTE PTR [bp-6]	;local_10
	sub	ah,ah
	cmp	ax,13
	je	$SC534
	jg	$L20037
	or	ax,ax
	je	$SC536
	cmp	ax,1
	je	$SC530
	cmp	ax,2
	je	$SC532
	cmp	ax,3
	je	$SC530
	cmp	ax,4
	je	$SC532
	jmp	SHORT $SD543
	nop	
	nop	
$SC530:
; Line 242
	dec	di
; Line 243
	jns	$I531
; Line 244
	mov	di,5
; Line 245
; Line 246
$I531:
	push	di
$L20044:
	call	FUN_0000_06BC
; Line 247
$SB527:
; Line 287
	cmp	BYTE PTR [bp-6],32	;local_10
	ja	$L20036
	jmp	$D514
	nop	
$SC532:
; Line 250
	inc	di
; Line 251
	cmp	di,5
	jle	$I531
; Line 252
	sub	di,di
; Line 253
; Line 254
	jmp	SHORT $I531
$SC534:
; Line 260
	mov	al,BYTE PTR $SG535[di]
	mov	BYTE PTR [bp-6],al	;local_10
; Line 261
	jmp	SHORT $SB527
	nop	
$SC536:
; Line 263
	mov	BYTE PTR [bp-6],82	;local_10
; Line 264
	jmp	SHORT $SB527
$SC537:
; Line 266
	sub	ax,ax
$L20051:
	push	ax
	jmp	SHORT $L20044
	nop	
$SC538:
; Line 269
	mov	ax,1
	jmp	SHORT $L20051
	nop	
$SC539:
; Line 272
	mov	ax,2
	jmp	SHORT $L20051
	nop	
$SC540:
; Line 275
	mov	ax,3
	jmp	SHORT $L20051
	nop	
$SC541:
; Line 278
	mov	ax,4
	jmp	SHORT $L20051
	nop	
$SC542:
; Line 281
	mov	ax,5
	jmp	SHORT $L20051
	nop	
$L20037:
	cmp	ax,67
	je	$SC538
	jg	$L20038
	cmp	ax,32
	je	$SC534
	cmp	ax,65
	je	$SC541
$SD543:
; Line 284
	mov	BYTE PTR [bp-6],0	;local_10
; Line 285
	jmp	SHORT $SB527
	nop	
$L20038:
	cmp	ax,74
	je	$SC537
	cmp	ax,82
	je	$SC542
	cmp	ax,84
	je	$SC539
	cmp	ax,85
	je	$SC540
	jmp	SHORT $SD543
$L20036:
	mov	WORD PTR [bp-12],di	;local_c
; Line 288
$I511:
; Line 291
	mov	al,BYTE PTR [bp-6]	;local_10
	sub	ah,ah
	cmp	ax,65
	jne	$JCC1269
	jmp	$SC573
$JCC1269:
	cmp	ax,67
	jne	$JCC1277
	jmp	$SC568
$JCC1277:
	cmp	ax,74
	je	$SC548
	cmp	ax,82
	jne	$JCC1290
	jmp	$SC577
$JCC1290:
	cmp	ax,84
	jne	$JCC1298
	jmp	$SC565
$JCC1298:
	cmp	ax,85
	jne	$JCC1306
	jmp	$SC571
$JCC1306:
	jmp	$D507
$SC548:
; Line 295
	call	FUNC_0X0000E1BE
; Line 296
	sub	ax,ax
	push	ax
	call	FUNC_0X0000ACD6
; Line 297
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 298
	sub	ax,ax
	push	ax
	mov	ax,12
	push	ax
	call	FUN_1000_1BF2
; Line 299
	cmp	BYTE PTR D_5893_MAP_ID,64
	jne	$I551
; Line 300
$L20039:
	mov	bx,9712
	push	WORD PTR [bx]
	call	FUNC_0X00008E34
	or	ax,ax
	je	$L20039
; Line 301
	mov	BYTE PTR D_5893_MAP_ID,65
; Line 302
; Line 304
$I551:
	mov	ax,3
	push	ax
	call	FUNC_0X0000A35E
; Line 305
	mov	ax,12774
	push	ax
	mov	ax,21926
	push	ax
	mov	ax,OFFSET D_6606
	sub	ax,OFFSET D_55A6
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X0000A3AE
; Line 306
	cmp	BYTE PTR D_55A8_PARTY,0
	jne	$I556
; Line 307
; Line 308
	mov	ax,12784
	push	ax
	call	FUN_1000_1850
; Line 309
	mov	ax,12803
	push	ax
	call	FUN_1000_1850
; Line 310
	mov	ax,12830
	push	ax
	call	FUN_1000_1850
; Line 311
	sub	ax,ax
	push	ax
	call	FUNC_0X00009C1A
; Line 312
	mov	BYTE PTR D_A9CB,255
; Line 313
	sub	ax,ax
	push	ax
	call	FUNC_0X0000A35E
; Line 314
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94
; Line 315
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 316
	mov	ax,1
	push	ax
	call	FUNC_0X00008A62
; Line 317
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 318
	sub	ax,ax
	push	ax
	call	FUNC_0X00008A62
; Line 319
	sub	ax,ax
	push	ax
	call	FUN_0000_05B0
; Line 320
	mov	WORD PTR [bp-8],0	;local_a
; Line 321
; Line 338
	jmp	$D507
$I556:
; Line 323
; Line 325
	mov	ax,12863
	push	ax
	mov	ax,-19938
	push	ax
	mov	ax,512
	push	ax
	sub	ax,ax
	push	ax
	call	FUNC_0X0000A3AE
; Line 326
	mov	ax,1
	push	ax
	call	FUNC_0X0000A35E
; Line 327
	mov	ax,12873
	push	ax
	mov	ax,-19938
	push	ax
	mov	ax,256
	push	ax
	call	FUNC_0X0000A418
; Line 328
	mov	ax,12882
	push	ax
	mov	ax,-19682
	push	ax
	mov	ax,256
	push	ax
	call	FUNC_0X0000A418
; Line 329
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I560
	cmp	BYTE PTR D_5895,0
	je	$I560
; Line 330
	mov	ax,5
	push	ax
	call	FUNC_0X0000A35E
; Line 331
$L20041:
	mov	ax,12892
	push	ax
	call	FUNC_0X000094B4
	or	ax,ax
	je	$L20041
; Line 332
	mov	ax,12902
	push	ax
	mov	ax,-19682
	push	ax
	mov	ax,256
	push	ax
	call	FUNC_0X0000A418
; Line 333
; Line 334
$I560:
	mov	ax,-1
	push	ax
	call	FUNC_0X0000ACD6
; Line 335
	mov	WORD PTR D_52BE,8
; Line 336
	jmp	SHORT $EX411
	nop	
$SC565:
; Line 340
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 341
	call	FUN_0000_132A
; Line 342
	jmp	SHORT $L_0fab567
$SC568:
; Line 346
	call	FUNC_0X0000FB0E
; Line 347
$L_0fab567:
; Line 348
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22
; Line 349
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94
; Line 350
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 351
	mov	ax,1
	push	ax
	call	FUNC_0X00008A62
; Line 352
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 353
	sub	ax,ax
	push	ax
	call	FUN_0000_05B0
; Line 354
	call	FUN_0000_0010
; Line 355
	sub	ax,ax
	push	ax
	call	FUNC_0X00008A62
; Line 375
	jmp	$D507
$SC571:
; Line 358
	call	FUN_0000_014E
; Line 359
	sub	ax,ax
	push	ax
	call	FUN_0000_05B0
; Line 360
	jmp	$D507
$SC573:
; Line 364
	cmp	BYTE PTR D_5893_MAP_ID,64
	je	$I574
; Line 365
	call	FUNC_0X00008E6E
; Line 366
	mov	BYTE PTR D_5893_MAP_ID,64
; Line 367
; Line 368
$I574:
	call	FUN_0000_072E
; Line 369
	jmp	$D507
	nop	
$SC577:
; Line 372
	call	FUNC_0X0000FB1A
; Line 373
	jmp	$D507
$EX411:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	

F_INTRO_0986	ENDP
; Line 378
	PUBLIC	F_INTRO_1016
F_INTRO_1016	PROC NEAR
	ret	
	nop	

F_INTRO_1016	ENDP
; Line 379
	PUBLIC	F_INTRO_1278
F_INTRO_1278	PROC NEAR
	ret	
	nop	

F_INTRO_1278	ENDP
; Line 380
	PUBLIC	F_INTRO_12EA
F_INTRO_12EA	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_12EA	ENDP
; Line 381
	PUBLIC	F_INTRO_132A
F_INTRO_132A	PROC NEAR
	ret	
	nop	

F_INTRO_132A	ENDP
; Line 382
	PUBLIC	F_INTRO_1E22
F_INTRO_1E22	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_1E22	ENDP
; Line 383
	PUBLIC	F_INTRO_1E62
F_INTRO_1E62	PROC NEAR
	ret	
	nop	

F_INTRO_1E62	ENDP
; Line 384
	PUBLIC	F_INTRO_1F26
F_INTRO_1F26	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_1F26	ENDP
; Line 385
	PUBLIC	F_INTRO_2024
F_INTRO_2024	PROC NEAR
	ret	
	nop	

F_INTRO_2024	ENDP
; Line 386
	PUBLIC	F_INTRO_2090
F_INTRO_2090	PROC NEAR
	ret	
	nop	

F_INTRO_2090	ENDP
; Line 387
	PUBLIC	F_INTRO_20AE
F_INTRO_20AE	PROC NEAR
	ret	
	nop	

F_INTRO_20AE	ENDP
_TEXT	ENDS
END
