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
EXTRN	FUN_0000_7CCE:NEAR
EXTRN	FUN_1000_4C2A:NEAR
EXTRN	FUN_1000_4CCE:NEAR
EXTRN	FUN_1000_102E_UNLOAD_TILESET:NEAR
EXTRN	FUN_1000_1B38_KEYSTROKE_CURSOR:NEAR
EXTRN	FUN_1000_1C9E_GET_CHAR_SEGMENT:NEAR
EXTRN	FUN_1000_1C22_SET_TEXT_WINDOW_S:NEAR
EXTRN	FUN_1000_1B94_GET_TEXT_EFFECTS:NEAR
EXTRN	FUN_1000_2032_TO_UPPER:NEAR
EXTRN	FUN_1000_1D5E_PEEK_KEYSTROKE:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_1000_1850_PRINT_STRING:NEAR
EXTRN	FUN_1000_0FF4_LOAD_COMPRESSED_T:NEAR
EXTRN	_FUN_1000_02F4_exit_to_dos:NEAR
EXTRN	FUN_1000_0FAE_LOAD_FILE:NEAR
EXTRN	FUN_1000_637E:NEAR
EXTRN	FUN_1000_2E96_PRINT_DIRECTION:NEAR
EXTRN	FUN_1000_256E_READ_FILE_FROM_DI:NEAR
EXTRN	FUN_1000_0D72:NEAR
EXTRN	FUN_1000_0DE0_DETECT_VIDEO:NEAR
EXTRN	FUN_1000_0C22:NEAR
EXTRN	FUN_1000_251E_SWITCH_DISKS:NEAR
EXTRN	FUN_1000_1158_INIT_TIMER:NEAR
EXTRN	FUN_1000_0AA6:NEAR
EXTRN	FUN_1000_1044_BUFFER_IMAGE:NEAR
EXTRN	FUN_1000_0E94_LOAD_VIDEO_DRIVER:NEAR
EXTRN	FUN_1000_0ACE:NEAR
EXTRN	FUN_1000_20FA_WAIT_TICKS:NEAR
EXTRN	FUN_1000_1DDA_WAIT_FOR_KEYSTROK:NEAR
EXTRN	FUN_1000_0892_INITIALIZE_VIDEO_:NEAR
EXTRN	FUN_1000_0F6E_IMAGE_DATA_TRANSF:NEAR
EXTRN	FUN_1000_25D8_WRITE_FILE_TO_DIS:NEAR
EXTRN	FUN_1000_0FDC_FREE_MEMORY:NEAR
EXTRN	FUN_0000_7CDA:NEAR
EXTRN	FUN_1000_1674_TEST_OPEN_FILE:NEAR
EXTRN	FUN_1000_207E:NEAR
EXTRN	FUN_1000_2056_GET_TIME:NEAR
EXTRN	FUN_1000_0F2A_INIT_DATA_BUFFER:NEAR
EXTRN	FUN_1000_0878_SET_OLD_VIDEO_MOD:NEAR
EXTRN	FUN_1000_1D02_LOAD_CHARACTER_SE:NEAR
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
$SG510	DB	'Copyright 1988 Lord British',  00H
$SG515	DB	'Select: ',  00H
$SG533	DB	'JCTUAR',  00H
$SG554	DB	'SAVED.GAM',  00H
$SG556	DB	0aH,  0aH, 'No active game.',  00H
$SG557	DB	'Please create a character ',  00H
$SG558	DB	'or transfer one from Ultima IV. ',  00H
$SG561	DB	'SAVED.OOL',  00H
$SG563	DB	'BRIT.OOL',  00H
$SG564	DB	'UNDER.OOL',  00H
$SG570	DB	'UNDER.DAT',  00H
$SG571	DB	'UNDER.OOL',  00H
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
; Line 24
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
; Line 36
	mov	BYTE PTR D_A9CE,1
; Line 40
	sub	si,si
$L20000:
; Line 41
	mov	ax,si
	mov	BYTE PTR D_B11E[si],al
; Line 42
	inc	si
	cmp	si,256
	jl	$L20000
	mov	WORD PTR [bp-18],si	;local_e
; Line 44
	call	FUN_1000_0DE0_DETECT_VIDEO
; Line 45
	call	FUN_1000_1158_INIT_TIMER
; Line 46
	mov	ax,D_5356
	mov	WORD PTR [bp-4],ax	;local_8
; Line 49
	cmp	WORD PTR D_52C8,2
	jne	$L20002
	cmp	WORD PTR D_5358,368
	jae	$L20002
; Line 50
	mov	WORD PTR D_52F1,0
; Line 51
	mov	WORD PTR D_52BA,1
; Line 52
	mov	WORD PTR D_52C8,0
; Line 53
; Line 56
$L20002:
	call	FUN_1000_0E94_LOAD_VIDEO_DRIVER
	or	ax,ax
	je	$L20002
; Line 58
	mov	ax,1
	push	ax
	call	FUN_1000_0892_INITIALIZE_VIDEO_
; Line 60
	cmp	WORD PTR D_52C8,0
	je	$I432
	cmp	WORD PTR D_52C8,3
	je	$I432
; Line 61
; Line 62
	mov	WORD PTR D_13B2,1
; Line 63
	mov	WORD PTR D_13AE,4
; Line 64
	mov	WORD PTR D_13B0,15
; Line 65
	mov	WORD PTR D_13B6,5
; Line 66
	mov	WORD PTR D_13B4,2
; Line 67
	mov	WORD PTR D_13B8,14
; Line 68
	mov	WORD PTR D_13BA,7
; Line 69
	jmp	SHORT $I433
$I432:
; Line 71
	sub	cx,cx
; Line 74
	mov	si,WORD PTR [bp-2]	;local_6
	jmp	SHORT $I440
	nop	
$L20004:
	inc	si
	cmp	BYTE PTR [si-1],46
	jne	$L20004
; Line 79
	cmp	BYTE PTR [si],49
	jne	$I440
; Line 80
	mov	BYTE PTR [si],52
	inc	si
; Line 81
	mov	BYTE PTR [si],0
; Line 82
; Line 83
$I440:
	mov	bx,cx
	inc	cx
	shl	bx,1
	mov	si,D_25EA[bx]
	cmp	BYTE PTR [si],0
	jne	$L20004
; Line 75
; Line 77
	mov	WORD PTR [bp-2],si	;local_6
	mov	WORD PTR [bp-18],cx	;local_e
; Line 84
$I433:
; Line 87
	call	FUN_1000_0F2A_INIT_DATA_BUFFER
	or	ax,ax
	jne	$I442
; Line 88
; Line 89
	call	FUN_1000_0878_SET_OLD_VIDEO_MOD
; Line 90
	mov	ax,1
	push	ax
	call	_FUN_1000_02F4_exit_to_dos
	add	sp,2
; Line 92
; Line 93
$I442:
	cmp	WORD PTR D_52C8,3
	jne	$L20014
; Line 94
; Line 97
$L20010:
	mov	ax,OFFSET DGROUP:$SG449
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	je	$L20010
$L20012:
	mov	ax,OFFSET DGROUP:$SG453
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	jne	$I454
	jmp	SHORT $L20012
	nop	
$L20014:
	mov	ax,OFFSET DGROUP:$SG458
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	je	$L20014
$L20016:
	mov	ax,OFFSET DGROUP:$SG462
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	je	$L20016
; Line 108
$I454:
; Line 111
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 112
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 113
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 114
	call	FUN_1000_1D5E_PEEK_KEYSTROKE
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	WORD PTR [bp-8],ax	;local_a
; Line 115
	cmp	ax,74
	jne	$I468
; Line 116
; Line 117
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 118
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 119
	sub	ax,ax
	push	ax
	mov	ax,11
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 121
	mov	ax,OFFSET DGROUP:$SG472
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 122
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 124
$L20018:
	push	WORD PTR D_25F0
	call	FUN_1000_0FF4_LOAD_COMPRESSED_T
	or	ax,ax
	je	$L20018
; Line 125
	mov	BYTE PTR D_5893_MAP_ID,65
; Line 127
; Line 128
	jmp	$I477
	nop	
$I468:
; Line 129
; Line 131
	mov	WORD PTR [bp-8],1	;local_a
; Line 133
$D478:
; Line 134
	push	WORD PTR D_25EE
	call	FUN_1000_0FAE_LOAD_FILE
	mov	si,ax
; Line 135
	or	si,si
	je	$D478
	mov	WORD PTR [bp-10],si	;local_12
; Line 137
$D482:
; Line 138
	push	WORD PTR D_25EC
	call	FUN_1000_0FAE_LOAD_FILE
	mov	si,ax
; Line 139
	or	si,si
	je	$D482
	mov	WORD PTR [bp-16],si	;local_14
; Line 142
	mov	ax,OFFSET DGROUP:$SG486
	push	ax
	mov	ax,OFFSET D_55A6
	push	ax
	mov	ax,OFFSET D_6606
	sub	ax,OFFSET D_55A6
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 143
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I487
; Line 144
	push	WORD PTR [bp-10]	;local_12
	call	FUN_1000_0D72
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 147
$I487:
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 148
	sub	ax,ax
	push	ax
	mov	ax,140
	push	ax
	mov	ax,319
	push	ax
	mov	ax,199
	push	ax
	call	FUN_1000_0AA6
; Line 149
	push	WORD PTR [bp-10]	;local_12
	mov	ax,7
	push	ax
	mov	ax,108
	push	ax
	mov	ax,140
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 150
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
	call	FUN_1000_0ACE
; Line 151
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I493
; Line 152
; Line 153
	mov	ax,18
	push	ax
	call	FUN_1000_20FA_WAIT_TICKS
; Line 154
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 155
; Line 157
$I493:
	cmp	WORD PTR [bp-8],0	;local_a
	jne	$JCC608
	jmp	$I499
$JCC608:
; Line 158
; Line 160
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 161
	push	WORD PTR [bp-10]	;local_12
	mov	ax,8
	push	ax
	mov	ax,152
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 162
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_0F6E_IMAGE_DATA_TRANSF
; Line 163
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 164
	or	cx,cx
	je	$I497
; Line 165
; Line 166
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 167
	mov	WORD PTR D_BB18,0
; Line 168
	mov	WORD PTR [bp-8],0	;local_a
; Line 171
	mov	ax,44
	push	ax
	mov	ax,68
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I498
	mov	ax,64
	push	ax
	mov	ax,94
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I498
	mov	ax,143
	push	ax
	mov	ax,78
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I498
; Line 172
; Line 173
	mov	ax,167
	push	ax
	mov	ax,105
	push	ax
	call	F_INTRO_0050
	mov	WORD PTR [bp-8],ax	;local_a
; Line 174
; Line 176
$I498:
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 177
; Line 179
$I497:
	push	WORD PTR [bp-16]	;local_14
	sub	ax,ax
	push	ax
	mov	ax,24
	push	ax
	mov	ax,66
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 180
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_0F6E_IMAGE_DATA_TRANSF
; Line 181
	push	WORD PTR [bp-18]	;local_e
	mov	ax,9
	push	ax
	mov	ax,104
	push	ax
	mov	ax,160
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 182
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_0F6E_IMAGE_DATA_TRANSF
; Line 183
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I499
; Line 184
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 185
; Line 186
$I499:
; Line 188
	push	WORD PTR [bp-16]	;local_14
	call	FUN_1000_0FDC_FREE_MEMORY
; Line 189
	push	WORD PTR [bp-10]	;local_12
	call	FUN_1000_0FDC_FREE_MEMORY
; Line 190
	mov	BYTE PTR D_5893_MAP_ID,64
; Line 191
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 192
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 193
	push	WORD PTR [bp-8]	;local_a
	call	F_INTRO_05B0
; Line 194
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I501
; Line 195
	call	FUN_0000_7CDA
; Line 196
; Line 198
$I501:
	mov	WORD PTR [bp-8],1	;local_a
; Line 199
$I477:
; Line 200
	call	FUN_1000_2056_GET_TIME
	push	ax
	call	FUN_1000_207E
; Line 203
$D505:
; Line 204
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 205
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 206
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 207
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 208
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 209
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 210
	cmp	WORD PTR [bp-8],74	;local_a
	jne	$I508
; Line 211
; Line 212
	mov	BYTE PTR [bp-6],74	;local_10
; Line 213
; Line 214
	jmp	$I509
$I508:
; Line 215
; Line 218
	sub	di,di
; Line 220
	mov	ax,OFFSET DGROUP:$SG510
	push	ax
	call	F_INTRO_043E
; Line 221
	sub	ax,ax
	push	ax
	call	F_INTRO_06BC
; Line 222
$D511:
; Line 224
	mov	ax,15
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 225
	call	FUN_1000_4C2A
; Line 227
	mov	ax,OFFSET DGROUP:$SG515
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 228
	call	FUN_1000_4CCE
; Line 229
	mov	ax,23
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 230
	mov	WORD PTR D_5356,275
; Line 231
	sub	si,si
; Line 232
$D517:
; Line 234
	call	FUN_1000_1B38_KEYSTROKE_CURSOR
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	BYTE PTR [bp-6],al	;local_10
; Line 235
	or	al,al
	jne	$I521
; Line 236
	call	F_INTRO_2090
; Line 237
; Line 239
$I521:
	inc	si
; Line 240
	cmp	si,200
	jge	$L20034
	cmp	BYTE PTR [bp-6],0	;local_10
	je	$D517
$L20034:
	mov	WORD PTR [bp-14],si	;local_4
; Line 241
	mov	ax,WORD PTR [bp-4]	;local_8
	mov	D_5356,ax
; Line 243
	mov	al,BYTE PTR [bp-6]	;local_10
	sub	ah,ah
	cmp	ax,13
	je	$SC532
	jg	$L20037
	or	ax,ax
	je	$SC534
	cmp	ax,1
	je	$SC528
	cmp	ax,2
	je	$SC530
	cmp	ax,3
	je	$SC528
	cmp	ax,4
	je	$SC530
	jmp	SHORT $SD541
	nop	
	nop	
$SC528:
; Line 247
	dec	di
; Line 248
	jns	$I529
; Line 249
	mov	di,5
; Line 250
; Line 251
$I529:
	push	di
$L20044:
	call	F_INTRO_06BC
; Line 252
$SB525:
; Line 292
	cmp	BYTE PTR [bp-6],32	;local_10
	ja	$L20036
	jmp	$D511
	nop	
$SC530:
; Line 255
	inc	di
; Line 256
	cmp	di,5
	jle	$I529
; Line 257
	sub	di,di
; Line 258
; Line 259
	jmp	SHORT $I529
$SC532:
; Line 265
	mov	al,BYTE PTR $SG533[di]
	mov	BYTE PTR [bp-6],al	;local_10
; Line 266
	jmp	SHORT $SB525
	nop	
$SC534:
; Line 268
	mov	BYTE PTR [bp-6],82	;local_10
; Line 269
	jmp	SHORT $SB525
$SC535:
; Line 271
	sub	ax,ax
$L20051:
	push	ax
	jmp	SHORT $L20044
	nop	
$SC536:
; Line 274
	mov	ax,1
	jmp	SHORT $L20051
	nop	
$SC537:
; Line 277
	mov	ax,2
	jmp	SHORT $L20051
	nop	
$SC538:
; Line 280
	mov	ax,3
	jmp	SHORT $L20051
	nop	
$SC539:
; Line 283
	mov	ax,4
	jmp	SHORT $L20051
	nop	
$SC540:
; Line 286
	mov	ax,5
	jmp	SHORT $L20051
	nop	
$L20037:
	cmp	ax,67
	je	$SC536
	jg	$L20038
	cmp	ax,32
	je	$SC532
	cmp	ax,65
	je	$SC539
$SD541:
; Line 289
	mov	BYTE PTR [bp-6],0	;local_10
; Line 290
	jmp	SHORT $SB525
	nop	
$L20038:
	cmp	ax,74
	je	$SC535
	cmp	ax,82
	je	$SC540
	cmp	ax,84
	je	$SC537
	cmp	ax,85
	je	$SC538
	jmp	SHORT $SD541
$L20036:
	mov	WORD PTR [bp-12],di	;local_c
; Line 293
$I509:
; Line 296
	mov	al,BYTE PTR [bp-6]	;local_10
	sub	ah,ah
	cmp	ax,65
	jne	$JCC1269
	jmp	$SC578
$JCC1269:
	cmp	ax,67
	jne	$JCC1277
	jmp	$SC575
$JCC1277:
	cmp	ax,74
	je	$SC546
	cmp	ax,82
	jne	$JCC1290
	jmp	$SC581
$JCC1290:
	cmp	ax,84
	jne	$JCC1298
	jmp	$SC572
$JCC1298:
	cmp	ax,85
	jne	$JCC1306
	jmp	$SC577
$JCC1306:
	jmp	$D505
$SC546:
; Line 300
	call	FUN_1000_637E
; Line 301
	sub	ax,ax
	push	ax
	call	FUN_1000_2E96_PRINT_DIRECTION
; Line 302
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 303
	sub	ax,ax
	push	ax
	mov	ax,12
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 304
	cmp	BYTE PTR D_5893_MAP_ID,64
	jne	$I549
; Line 305
$L20039:
	push	WORD PTR D_25F0
	call	FUN_1000_0FF4_LOAD_COMPRESSED_T
	or	ax,ax
	je	$L20039
; Line 306
	mov	BYTE PTR D_5893_MAP_ID,65
; Line 307
; Line 309
$I549:
	mov	ax,3
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 311
	mov	ax,OFFSET DGROUP:$SG554
	push	ax
	mov	ax,OFFSET D_55A6
	push	ax
	mov	ax,OFFSET D_6606
	sub	ax,OFFSET D_55A6
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 312
	cmp	BYTE PTR D_55A8_PARTY,0
	jne	$I555
; Line 313
; Line 315
	mov	ax,OFFSET DGROUP:$SG556
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 317
	mov	ax,OFFSET DGROUP:$SG557
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 319
	mov	ax,OFFSET DGROUP:$SG558
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 320
	sub	ax,ax
	push	ax
	call	FUN_1000_1DDA_WAIT_FOR_KEYSTROK
; Line 321
	mov	BYTE PTR D_A9CB,255
; Line 322
	sub	ax,ax
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 323
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 324
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 325
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 326
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 327
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 328
	sub	ax,ax
	push	ax
	call	F_INTRO_05B0
; Line 329
	mov	WORD PTR [bp-8],0	;local_a
; Line 330
; Line 352
	jmp	$D505
	nop	
$I555:
; Line 332
; Line 335
	mov	ax,OFFSET DGROUP:$SG561
	push	ax
	mov	ax,-19938
	push	ax
	mov	ax,512
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 336
	mov	ax,1
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 338
	mov	ax,OFFSET DGROUP:$SG563
	push	ax
	mov	ax,-19938
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 340
	mov	ax,OFFSET DGROUP:$SG564
	push	ax
	mov	ax,-19682
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 341
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I565
	cmp	BYTE PTR D_5895,0
	je	$I565
; Line 342
	mov	ax,5
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 344
$L20041:
	mov	ax,OFFSET DGROUP:$SG570
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$L20041
; Line 346
	mov	ax,OFFSET DGROUP:$SG571
	push	ax
	mov	ax,-19682
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 347
; Line 348
$I565:
	mov	ax,-1
	push	ax
	call	FUN_1000_2E96_PRINT_DIRECTION
; Line 349
	mov	WORD PTR D_52BE,8
; Line 350
	jmp	SHORT $EX411
	nop	
$SC572:
; Line 355
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 356
	call	F_INTRO_132A
; Line 357
	jmp	SHORT $L_0fab574
$SC575:
; Line 362
	call	FUN_0000_7CCE
; Line 363
$L_0fab574:
; Line 364
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 365
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 366
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 367
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 368
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 369
	sub	ax,ax
	push	ax
	call	F_INTRO_05B0
; Line 370
	call	F_INTRO_0010
; Line 371
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 392
	jmp	$D505
$SC577:
; Line 375
	call	F_INTRO_014E
; Line 376
	sub	ax,ax
	push	ax
	call	F_INTRO_05B0
; Line 377
	jmp	$D505
$SC578:
; Line 381
	cmp	BYTE PTR D_5893_MAP_ID,64
	je	$I579
; Line 382
	call	FUN_1000_102E_UNLOAD_TILESET
; Line 383
	mov	BYTE PTR D_5893_MAP_ID,64
; Line 384
; Line 385
$I579:
	call	F_INTRO_072E
; Line 386
	jmp	$D505
	nop	
$SC581:
; Line 389
	call	FUN_0000_7CDA
; Line 390
	jmp	$D505
$EX411:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	

F_INTRO_0986	ENDP
; Line 395
	PUBLIC	F_INTRO_1016
F_INTRO_1016	PROC NEAR
	ret	
	nop	

F_INTRO_1016	ENDP
; Line 396
	PUBLIC	F_INTRO_1278
F_INTRO_1278	PROC NEAR
	ret	
	nop	

F_INTRO_1278	ENDP
; Line 397
	PUBLIC	F_INTRO_12EA
F_INTRO_12EA	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_12EA	ENDP
; Line 398
	PUBLIC	F_INTRO_132A
F_INTRO_132A	PROC NEAR
	ret	
	nop	

F_INTRO_132A	ENDP
; Line 399
	PUBLIC	F_INTRO_1E22
F_INTRO_1E22	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_1E22	ENDP
; Line 400
	PUBLIC	F_INTRO_1E62
F_INTRO_1E62	PROC NEAR
	ret	
	nop	

F_INTRO_1E62	ENDP
; Line 401
	PUBLIC	F_INTRO_1F26
F_INTRO_1F26	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_1F26	ENDP
; Line 402
	PUBLIC	F_INTRO_2024
F_INTRO_2024	PROC NEAR
	ret	
	nop	

F_INTRO_2024	ENDP
; Line 403
	PUBLIC	F_INTRO_2090
F_INTRO_2090	PROC NEAR
	ret	
	nop	

F_INTRO_2090	ENDP
; Line 404
	PUBLIC	F_INTRO_20AE
F_INTRO_20AE	PROC NEAR
	ret	
	nop	

F_INTRO_20AE	ENDP
_TEXT	ENDS
END
