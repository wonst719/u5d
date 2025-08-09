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
EXTRN	FUN_1000_0AA6:NEAR
EXTRN	FUN_1000_2032_TO_UPPER:NEAR
EXTRN	FUN_1000_2056_GET_TIME:NEAR
EXTRN	FUN_1000_207E:NEAR
EXTRN	FUN_1000_0ACE:NEAR
EXTRN	FUN_1000_20FA_WAIT_TICKS:NEAR
EXTRN	FUN_1000_0C22:NEAR
EXTRN	FUN_1000_0D72:NEAR
EXTRN	FUN_1000_251E_SWITCH_DISKS:NEAR
EXTRN	FUN_1000_0DE0_DETECT_VIDEO:NEAR
EXTRN	FUN_1000_0E94_LOAD_VIDEO_DRIVER:NEAR
EXTRN	FUN_1000_0F2A_INIT_DATA_BUFFER:NEAR
EXTRN	FUN_1000_256E_READ_FILE_FROM_DI:NEAR
EXTRN	FUN_1000_0F6E_IMAGE_DATA_TRANSF:NEAR
EXTRN	FUN_1000_0FAE_LOAD_FILE:NEAR
EXTRN	FUN_1000_25D8_WRITE_FILE_TO_DIS:NEAR
EXTRN	FUN_1000_0FDC_FREE_MEMORY:NEAR
EXTRN	FUN_1000_0FF4_LOAD_COMPRESSED_T:NEAR
EXTRN	FUN_1000_102E_UNLOAD_TILESET:NEAR
EXTRN	FUN_1000_2E96_PRINT_DIRECTION:NEAR
EXTRN	FUN_1000_1044_BUFFER_IMAGE:NEAR
EXTRN	FUN_1000_1158_INIT_TIMER:NEAR
EXTRN	FUN_1000_4C2A:NEAR
EXTRN	FUN_1000_1674_TEST_OPEN_FILE:NEAR
EXTRN	FUN_1000_4CCE:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	FUN_1000_1850_PRINT_STRING:NEAR
EXTRN	FUN_1000_1B38_KEYSTROKE_CURSOR:NEAR
EXTRN	FUN_1000_1B94_GET_TEXT_EFFECTS:NEAR
EXTRN	FUN_1000_637E:NEAR
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_0000_7CCE:NEAR
EXTRN	FUN_0000_7CDA:NEAR
EXTRN	FUN_1000_1C22_SET_TEXT_WINDOW_S:NEAR
EXTRN	FUN_1000_1C9E_GET_CHAR_SEGMENT:NEAR
EXTRN	_FUN_1000_02F4_exit_to_dos:NEAR
EXTRN	FUN_1000_0878_SET_OLD_VIDEO_MOD:NEAR
EXTRN	FUN_1000_1D02_LOAD_CHARACTER_SE:NEAR
EXTRN	FUN_1000_0892_INITIALIZE_VIDEO_:NEAR
EXTRN	FUN_1000_1D5E_PEEK_KEYSTROKE:NEAR
EXTRN	FUN_1000_1DDA_WAIT_FOR_KEYSTROK:NEAR
EXTRN	D_55A8_PARTY:BYTE
EXTRN	D_6606:WORD
EXTRN	D_BB18:WORD
EXTRN	D_25EA:BYTE
EXTRN	D_25EC:WORD
EXTRN	D_25EE:WORD
EXTRN	D_25F0:BYTE
EXTRN	D_52BA_FORCECGA:WORD
EXTRN	D_52BE:WORD
EXTRN	D_52C8_VIDEODRIVERSELECTION:WORD
EXTRN	D_52F1_FORCETANDY:WORD
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
_BSS      ENDS
_DATA      SEGMENT
$SG572	DB	'ibm.hcs',  00H
$SG576	DB	'runes.hcs',  00H
$SG581	DB	'ibm.ch',  00H
$SG585	DB	'runes.ch',  00H
$SG587	DB	'Journey Onward',  0aH,  0aH,  00H
$SG598	DB	'BRITISH.PTH',  00H
$SG611	DB	'Copyright 1988 Lord British',  00H
$SG615	DB	'Select: ',  00H
$SG631	DB	'JCTUAR',  00H
$SG649	DB	'SAVED.GAM',  00H
$SG651	DB	0aH,  0aH, 'No active game.',  00H
$SG652	DB	'Please create a character ',  00H
$SG653	DB	'or transfer one from Ultima IV. ',  00H
$SG655	DB	'SAVED.OOL',  00H
$SG656	DB	'BRIT.OOL',  00H
$SG657	DB	'UNDER.OOL',  00H
$SG662	DB	'UNDER.DAT',  00H
$SG663	DB	'UNDER.OOL',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 10
	PUBLIC	F_INTRO_0010
F_INTRO_0010	PROC NEAR
	ret	
	nop	

F_INTRO_0010	ENDP
; Line 11
	PUBLIC	F_INTRO_0050
F_INTRO_0050	PROC NEAR
	push	bp
;	b = 4
;	a = 6
	pop	bp
	ret	4
	nop	

F_INTRO_0050	ENDP
; Line 12
	PUBLIC	F_INTRO_014E
F_INTRO_014E	PROC NEAR
	ret	
	nop	

F_INTRO_014E	ENDP
; Line 13
	PUBLIC	F_INTRO_043E
F_INTRO_043E	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_043E	ENDP
; Line 14
	PUBLIC	F_INTRO_04E0
F_INTRO_04E0	PROC NEAR
	ret	
	nop	

F_INTRO_04E0	ENDP
; Line 15
	PUBLIC	F_INTRO_05B0
F_INTRO_05B0	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_05B0	ENDP
; Line 16
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
; Line 17
	PUBLIC	F_INTRO_06BC
F_INTRO_06BC	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_06BC	ENDP
; Line 18
	PUBLIC	F_INTRO_072E
F_INTRO_072E	PROC NEAR
	ret	
	nop	

F_INTRO_072E	ENDP
; Line 19
	PUBLIC	F_INTRO_094E
F_INTRO_094E	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_094E	ENDP
; Line 25
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
; Line 37
	mov	BYTE PTR D_A9CE,1
; Line 41
	sub	si,si
$L20000:
; Line 42
	mov	ax,si
	mov	BYTE PTR D_B11E[si],al
; Line 43
	inc	si
	cmp	si,256
	jl	$L20000
	mov	WORD PTR [bp-18],si	;local_e
; Line 45
	call	FUN_1000_0DE0_DETECT_VIDEO
; Line 46
	call	FUN_1000_1158_INIT_TIMER
; Line 47
	mov	ax,D_5356
	mov	WORD PTR [bp-4],ax	;local_8
; Line 50
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,2
	jne	$L20002
	cmp	WORD PTR D_5358,368
	jae	$L20002
; Line 51
	mov	WORD PTR D_52F1_FORCETANDY,0
; Line 52
	mov	WORD PTR D_52BA_FORCECGA,1
; Line 53
	mov	WORD PTR D_52C8_VIDEODRIVERSELECTION,0
; Line 54
; Line 57
$L20002:
	call	FUN_1000_0E94_LOAD_VIDEO_DRIVER
	or	ax,ax
	je	$L20002
; Line 59
	mov	ax,1
	push	ax
	call	FUN_1000_0892_INITIALIZE_VIDEO_
; Line 61
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,0
	je	$I558
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,3
	je	$I558
; Line 62
; Line 63
	mov	WORD PTR D_13B2,1
; Line 64
	mov	WORD PTR D_13AE,4
; Line 65
	mov	WORD PTR D_13B0,15
; Line 66
	mov	WORD PTR D_13B6,5
; Line 67
	mov	WORD PTR D_13B4,2
; Line 68
	mov	WORD PTR D_13B8,14
; Line 69
	mov	WORD PTR D_13BA,7
; Line 70
	jmp	SHORT $I559
$I558:
; Line 72
	sub	cx,cx
; Line 75
	mov	si,WORD PTR [bp-2]	;local_6
	jmp	SHORT $I566
	nop	
$L20004:
	inc	si
	cmp	BYTE PTR [si-1],46
	jne	$L20004
; Line 80
	cmp	BYTE PTR [si],49
	jne	$I566
; Line 81
	mov	BYTE PTR [si],52
	inc	si
; Line 82
	mov	BYTE PTR [si],0
; Line 83
; Line 84
$I566:
	mov	bx,cx
	inc	cx
	shl	bx,1
	mov	si,WORD PTR D_25EA[bx]
	cmp	BYTE PTR [si],0
	jne	$L20004
; Line 76
; Line 78
	mov	WORD PTR [bp-2],si	;local_6
	mov	WORD PTR [bp-18],cx	;local_e
; Line 85
$I559:
; Line 88
	call	FUN_1000_0F2A_INIT_DATA_BUFFER
	or	ax,ax
	jne	$I567
; Line 89
; Line 90
	call	FUN_1000_0878_SET_OLD_VIDEO_MOD
; Line 91
	mov	ax,1
	push	ax
	call	_FUN_1000_02F4_exit_to_dos
	add	sp,2
; Line 93
; Line 94
$I567:
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,3
	jne	$L20014
; Line 95
; Line 98
$L20010:
	mov	ax,OFFSET DGROUP:$SG572
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	je	$L20010
$L20012:
	mov	ax,OFFSET DGROUP:$SG576
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	jne	$I577
	jmp	SHORT $L20012
	nop	
$L20014:
	mov	ax,OFFSET DGROUP:$SG581
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	je	$L20014
$L20016:
	mov	ax,OFFSET DGROUP:$SG585
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1D02_LOAD_CHARACTER_SE
	or	ax,ax
	je	$L20016
; Line 109
$I577:
; Line 112
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 113
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 114
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 115
	call	FUN_1000_1D5E_PEEK_KEYSTROKE
	cbw	
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	WORD PTR [bp-8],ax	;local_a
; Line 116
	cmp	ax,74
	jne	$I586
; Line 117
; Line 118
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 119
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 120
	sub	ax,ax
	push	ax
	mov	ax,11
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 122
	mov	ax,OFFSET DGROUP:$SG587
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 123
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 125
$L20018:
	push	WORD PTR D_25F0
	call	FUN_1000_0FF4_LOAD_COMPRESSED_T
	or	ax,ax
	je	$L20018
; Line 126
	mov	BYTE PTR D_5893_MAP_ID,65
; Line 128
; Line 129
	jmp	$I591
$I586:
; Line 130
; Line 132
	mov	WORD PTR [bp-8],1	;local_a
; Line 134
$D592:
; Line 135
	push	WORD PTR D_25EE
	call	FUN_1000_0FAE_LOAD_FILE
	mov	si,ax
; Line 136
	or	si,si
	je	$D592
	mov	WORD PTR [bp-10],si	;local_12
; Line 138
$D595:
; Line 139
	push	WORD PTR D_25EC
	call	FUN_1000_0FAE_LOAD_FILE
	mov	si,ax
; Line 140
	or	si,si
	je	$D595
	mov	WORD PTR [bp-16],si	;local_14
; Line 143
	mov	ax,OFFSET DGROUP:$SG598
	push	ax
	mov	ax,OFFSET D_55A6
	push	ax
	mov	ax,OFFSET D_6606
	sub	ax,OFFSET D_55A6
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 144
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I599
; Line 145
	push	WORD PTR [bp-10]	;local_12
	call	FUN_1000_0D72
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 148
$I599:
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 149
	sub	ax,ax
	push	ax
	mov	ax,140
	push	ax
	mov	ax,319
	push	ax
	mov	ax,199
	push	ax
	call	FUN_1000_0AA6
; Line 150
	push	WORD PTR [bp-10]	;local_12
	mov	ax,7
	push	ax
	mov	ax,108
	push	ax
	mov	ax,140
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 151
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
; Line 152
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I600
; Line 153
; Line 154
	mov	ax,18
	push	ax
	call	FUN_1000_20FA_WAIT_TICKS
; Line 155
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 156
; Line 158
$I600:
	cmp	WORD PTR [bp-8],0	;local_a
	jne	$JCC608
	jmp	$I604
$JCC608:
; Line 159
; Line 161
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 162
	push	WORD PTR [bp-10]	;local_12
	mov	ax,8
	push	ax
	mov	ax,152
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 163
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_0F6E_IMAGE_DATA_TRANSF
; Line 164
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 165
	or	cx,cx
	je	$I602
; Line 166
; Line 167
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 168
	mov	WORD PTR D_BB18,0
; Line 169
	mov	WORD PTR [bp-8],0	;local_a
; Line 172
	mov	ax,44
	push	ax
	mov	ax,68
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I603
	mov	ax,64
	push	ax
	mov	ax,94
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I603
	mov	ax,143
	push	ax
	mov	ax,78
	push	ax
	call	F_INTRO_0050
	or	ax,ax
	je	$I603
; Line 173
; Line 174
	mov	ax,167
	push	ax
	mov	ax,105
	push	ax
	call	F_INTRO_0050
	mov	WORD PTR [bp-8],ax	;local_a
; Line 175
; Line 177
$I603:
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 178
; Line 180
$I602:
	push	WORD PTR [bp-16]	;local_14
	sub	ax,ax
	push	ax
	mov	ax,24
	push	ax
	mov	ax,66
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 181
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_0F6E_IMAGE_DATA_TRANSF
; Line 182
	push	WORD PTR [bp-18]	;local_e
	mov	ax,9
	push	ax
	mov	ax,104
	push	ax
	mov	ax,160
	push	ax
	call	FUN_1000_1044_BUFFER_IMAGE
; Line 183
	mov	ax,1
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_0F6E_IMAGE_DATA_TRANSF
; Line 184
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I604
; Line 185
	mov	ax,20
	push	ax
	call	F_INTRO_094E
	cmp	ax,1
	sbb	cx,cx
	neg	cx
	mov	WORD PTR [bp-8],cx	;local_a
; Line 186
; Line 187
$I604:
; Line 189
	push	WORD PTR [bp-16]	;local_14
	call	FUN_1000_0FDC_FREE_MEMORY
; Line 190
	push	WORD PTR [bp-10]	;local_12
	call	FUN_1000_0FDC_FREE_MEMORY
; Line 191
	mov	BYTE PTR D_5893_MAP_ID,64
; Line 192
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 193
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 194
	push	WORD PTR [bp-8]	;local_a
	call	F_INTRO_05B0
; Line 195
	cmp	WORD PTR [bp-8],0	;local_a
	je	$I605
; Line 196
	call	FUN_0000_7CDA
; Line 197
; Line 199
$I605:
	mov	WORD PTR [bp-8],1	;local_a
; Line 200
$I591:
; Line 201
	call	FUN_1000_2056_GET_TIME
	push	ax
	call	FUN_1000_207E
; Line 204
$D606:
; Line 205
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
; Line 206
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 207
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 208
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 209
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
; Line 210
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
; Line 211
	cmp	WORD PTR [bp-8],74	;local_a
	jne	$I609
; Line 212
; Line 213
	mov	BYTE PTR [bp-6],74	;local_10
; Line 214
; Line 215
	jmp	$I610
$I609:
; Line 216
; Line 219
	sub	di,di
; Line 221
	mov	ax,OFFSET DGROUP:$SG611
	push	ax
	call	F_INTRO_043E
; Line 222
	sub	ax,ax
	push	ax
	call	F_INTRO_06BC
; Line 223
$D612:
; Line 225
	mov	ax,15
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 226
	call	FUN_1000_4C2A
; Line 228
	mov	ax,OFFSET DGROUP:$SG615
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 229
	call	FUN_1000_4CCE
; Line 230
	mov	ax,23
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 231
	mov	WORD PTR D_5356,275
; Line 232
	sub	si,si
; Line 233
$D616:
; Line 235
	call	FUN_1000_1B38_KEYSTROKE_CURSOR
	cbw	
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	BYTE PTR [bp-6],al	;local_10
; Line 236
	or	al,al
	jne	$I619
; Line 237
	call	F_INTRO_2090
; Line 238
; Line 240
$I619:
	inc	si
; Line 241
	cmp	si,200
	jge	$L20034
	cmp	BYTE PTR [bp-6],0	;local_10
	je	$D616
$L20034:
	mov	WORD PTR [bp-14],si	;local_4
; Line 242
	mov	ax,WORD PTR [bp-4]	;local_8
	mov	D_5356,ax
; Line 244
	mov	al,BYTE PTR [bp-6]	;local_10
	sub	ah,ah
	cmp	ax,13
	je	$SC630
	jg	$L20037
	or	ax,ax
	je	$SC632
	cmp	ax,1
	je	$SC626
	cmp	ax,2
	je	$SC628
	cmp	ax,3
	je	$SC626
	cmp	ax,4
	je	$SC628
	jmp	SHORT $SD639
	nop	
$SC626:
; Line 248
	dec	di
; Line 249
	jns	$I627
; Line 250
	mov	di,5
; Line 251
; Line 252
$I627:
	push	di
$L20044:
	call	F_INTRO_06BC
; Line 253
$SB623:
; Line 293
	cmp	BYTE PTR [bp-6],32	;local_10
	ja	$L20036
	jmp	$D612
	nop	
$SC628:
; Line 256
	inc	di
; Line 257
	cmp	di,5
	jle	$I627
; Line 258
	sub	di,di
; Line 259
; Line 260
	jmp	SHORT $I627
$SC630:
; Line 266
	mov	al,BYTE PTR $SG631[di]
	mov	BYTE PTR [bp-6],al	;local_10
; Line 267
	jmp	SHORT $SB623
	nop	
$SC632:
; Line 269
	mov	BYTE PTR [bp-6],82	;local_10
; Line 270
	jmp	SHORT $SB623
$SC633:
; Line 272
	sub	ax,ax
$L20051:
	push	ax
	jmp	SHORT $L20044
	nop	
$SC634:
; Line 275
	mov	ax,1
	jmp	SHORT $L20051
	nop	
$SC635:
; Line 278
	mov	ax,2
	jmp	SHORT $L20051
	nop	
$SC636:
; Line 281
	mov	ax,3
	jmp	SHORT $L20051
	nop	
$SC637:
; Line 284
	mov	ax,4
	jmp	SHORT $L20051
	nop	
$SC638:
; Line 287
	mov	ax,5
	jmp	SHORT $L20051
	nop	
$L20037:
	cmp	ax,67
	je	$SC634
	jg	$L20038
	cmp	ax,32
	je	$SC630
	cmp	ax,65
	je	$SC637
$SD639:
; Line 290
	mov	BYTE PTR [bp-6],0	;local_10
; Line 291
	jmp	SHORT $SB623
	nop	
$L20038:
	cmp	ax,74
	je	$SC633
	cmp	ax,82
	je	$SC638
	cmp	ax,84
	je	$SC635
	cmp	ax,85
	je	$SC636
	jmp	SHORT $SD639
$L20036:
	mov	WORD PTR [bp-12],di	;local_c
; Line 294
$I610:
; Line 297
	mov	al,BYTE PTR [bp-6]	;local_10
	sub	ah,ah
	cmp	ax,65
	jne	$JCC1269
	jmp	$SC669
$JCC1269:
	cmp	ax,67
	jne	$JCC1277
	jmp	$SC667
$JCC1277:
	cmp	ax,74
	je	$SC644
	cmp	ax,82
	jne	$JCC1290
	jmp	$SC671
$JCC1290:
	cmp	ax,84
	jne	$JCC1298
	jmp	$SC664
$JCC1298:
	cmp	ax,85
	jne	$JCC1306
	jmp	$SC668
$JCC1306:
	jmp	$D606
$SC644:
; Line 301
	call	FUN_1000_637E
; Line 302
	sub	ax,ax
	push	ax
	call	FUN_1000_2E96_PRINT_DIRECTION
; Line 303
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 304
	sub	ax,ax
	push	ax
	mov	ax,12
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 305
	cmp	BYTE PTR D_5893_MAP_ID,64
	jne	$I645
; Line 306
$L20039:
	push	WORD PTR D_25F0
	call	FUN_1000_0FF4_LOAD_COMPRESSED_T
	or	ax,ax
	je	$L20039
; Line 307
	mov	BYTE PTR D_5893_MAP_ID,65
; Line 308
; Line 310
$I645:
	mov	ax,3
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 312
	mov	ax,OFFSET DGROUP:$SG649
	push	ax
	mov	ax,OFFSET D_55A6
	push	ax
	mov	ax,OFFSET D_6606
	sub	ax,OFFSET D_55A6
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 313
	cmp	BYTE PTR D_55A8_PARTY,0
	jne	$I650
; Line 314
; Line 316
	mov	ax,OFFSET DGROUP:$SG651
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 318
	mov	ax,OFFSET DGROUP:$SG652
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 320
	mov	ax,OFFSET DGROUP:$SG653
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 321
	sub	ax,ax
	push	ax
	call	FUN_1000_1DDA_WAIT_FOR_KEYSTROK
; Line 322
	mov	BYTE PTR D_A9CB,255
; Line 323
	sub	ax,ax
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 324
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 325
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 326
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 327
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 328
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 329
	sub	ax,ax
	push	ax
	call	F_INTRO_05B0
; Line 330
	mov	WORD PTR [bp-8],0	;local_a
; Line 331
; Line 353
	jmp	$D606
	nop	
$I650:
; Line 333
; Line 336
	mov	ax,OFFSET DGROUP:$SG655
	push	ax
	mov	ax,-19938
	push	ax
	mov	ax,512
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 337
	mov	ax,1
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 339
	mov	ax,OFFSET DGROUP:$SG656
	push	ax
	mov	ax,-19938
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 341
	mov	ax,OFFSET DGROUP:$SG657
	push	ax
	mov	ax,-19682
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 342
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I658
	cmp	BYTE PTR D_5895,0
	je	$I658
; Line 343
	mov	ax,5
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 345
$L20041:
	mov	ax,OFFSET DGROUP:$SG662
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$L20041
; Line 347
	mov	ax,OFFSET DGROUP:$SG663
	push	ax
	mov	ax,-19682
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 348
; Line 349
$I658:
	mov	ax,-1
	push	ax
	call	FUN_1000_2E96_PRINT_DIRECTION
; Line 350
	mov	WORD PTR D_52BE,8
; Line 351
	jmp	SHORT $EX541
	nop	
$SC664:
; Line 356
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 357
	call	F_INTRO_132A
; Line 358
	jmp	SHORT $L_0fab666
$SC667:
; Line 363
	call	FUN_0000_7CCE
; Line 364
$L_0fab666:
; Line 365
	sub	ax,ax
	push	ax
	push	ax
	push	ax
	mov	ax,39
	push	ax
	mov	ax,24
	push	ax
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 366
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 367
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 368
	mov	ax,1
	push	ax
	call	FUN_1000_0C22
; Line 369
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 370
	sub	ax,ax
	push	ax
	call	F_INTRO_05B0
; Line 371
	call	F_INTRO_0010
; Line 372
	sub	ax,ax
	push	ax
	call	FUN_1000_0C22
; Line 393
	jmp	$D606
$SC668:
; Line 376
	call	F_INTRO_014E
; Line 377
	sub	ax,ax
	push	ax
	call	F_INTRO_05B0
; Line 378
	jmp	$D606
$SC669:
; Line 382
	cmp	BYTE PTR D_5893_MAP_ID,64
	je	$I670
; Line 383
	call	FUN_1000_102E_UNLOAD_TILESET
; Line 384
	mov	BYTE PTR D_5893_MAP_ID,64
; Line 385
; Line 386
$I670:
	call	F_INTRO_072E
; Line 387
	jmp	$D606
	nop	
$SC671:
; Line 390
	call	FUN_0000_7CDA
; Line 391
	jmp	$D606
$EX541:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	

F_INTRO_0986	ENDP
; Line 396
	PUBLIC	F_INTRO_1016
F_INTRO_1016	PROC NEAR
	ret	
	nop	

F_INTRO_1016	ENDP
; Line 397
	PUBLIC	F_INTRO_1278
F_INTRO_1278	PROC NEAR
	ret	
	nop	

F_INTRO_1278	ENDP
; Line 398
	PUBLIC	F_INTRO_12EA
F_INTRO_12EA	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_12EA	ENDP
; Line 399
	PUBLIC	F_INTRO_132A
F_INTRO_132A	PROC NEAR
	ret	
	nop	

F_INTRO_132A	ENDP
; Line 400
	PUBLIC	F_INTRO_1E22
F_INTRO_1E22	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_1E22	ENDP
; Line 401
	PUBLIC	F_INTRO_1E62
F_INTRO_1E62	PROC NEAR
	ret	
	nop	

F_INTRO_1E62	ENDP
; Line 402
	PUBLIC	F_INTRO_1F26
F_INTRO_1F26	PROC NEAR
	push	bp
;	a = 4
	pop	bp
	ret	2
	nop	

F_INTRO_1F26	ENDP
; Line 403
	PUBLIC	F_INTRO_2024
F_INTRO_2024	PROC NEAR
	ret	
	nop	

F_INTRO_2024	ENDP
; Line 404
	PUBLIC	F_INTRO_2090
F_INTRO_2090	PROC NEAR
	ret	
	nop	

F_INTRO_2090	ENDP
; Line 405
	PUBLIC	F_INTRO_20AE
F_INTRO_20AE	PROC NEAR
	ret	
	nop	

F_INTRO_20AE	ENDP
_TEXT	ENDS
END
