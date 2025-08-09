;	Static Name Aliases
;
	TITLE   grap.c
	NAME    grap

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
EXTRN	FUN_1000_17F4_CHARACTER_EFFECTS:NEAR
EXTRN	_printf:NEAR
EXTRN	D_53EA:BYTE
EXTRN	D_52BA_VDP:BYTE
_BSS      SEGMENT
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
EXTRN	D_5386_CURRENTTEXTWINDOW:WORD
EXTRN	D_538E:WORD
EXTRN	D_5398:WORD
EXTRN	D_539A_TEXTWINFORCURRCHARSET:WORD
EXTRN	D_53A4:WORD
EXTRN	D_53A6:WORD
EXTRN	D_53A8:WORD
EXTRN	D_53AA:BYTE
EXTRN	D_53AB:BYTE
_BSS      ENDS
_DATA      SEGMENT
$SG562	DB	'FUN_1000_1b94_select_charset(%d)',  0aH,  00H
$SG567	DB	'FUN_1000_1bf2_set_text_cursor_position(%d,%d)',  0aH,  00H
$SG580	DB	'FUN_1000_1c22_set_text_window_size(%d,%d,%d,%d,%d)',  0aH,  00H
$SG625	DB	'GRAP_PrintString(%s)',  0aH,  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 9
	PUBLIC	DRV_FARCALL
DRV_FARCALL	PROC FAR
	push	bp
;	offset = 6
; Line 11
	pop	bp
	ret	2
	nop	

DRV_FARCALL	ENDP
; Line 14
	PUBLIC	CONCAT22
CONCAT22	PROC NEAR
	ret	
	nop	

CONCAT22	ENDP
; Line 19
	PUBLIC	FUN_1000_0892_INITIALIZE_VIDEO_
FUN_1000_0892_INITIALIZE_VIDEO_	PROC NEAR
	push	bp
;	a = 4
; Line 28
	pop	bp
	ret	2
	nop	

FUN_1000_0892_INITIALIZE_VIDEO_	ENDP
; Line 32
	PUBLIC	FUN_1000_16BA_PRINT_CHAR
FUN_1000_16BA_PRINT_CHAR	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,20
	push	di
	push	si
;	ch = 4
;	puVar1 = -20
;	puVar2 = -2
;	puVar3 = -4
;	iVar4 = -14
;	puVar5 = -6
;	uVar6 = -8
;	puVar7 = -10
;	text_window = -16
;	pCharacter = -18
;	unaff_DS = -12
; Line 44
	mov	ax,D_539A_TEXTWINFORCURRCHARSET
	mov	WORD PTR [bp-16],ax	;text_window
; Line 45
	cmp	WORD PTR [bp+4],127	;ch
	ja	$JCC32
	jmp	$I540
$JCC32:
; Line 46
	cmp	WORD PTR [bp+4],255	;ch
	jne	$I541
; Line 47
	mov	bx,ax
	mov	BYTE PTR [bx+4],0
; Line 48
	mov	BYTE PTR [bx+5],0
; Line 49
	mov	ax,45
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 50
	push	WORD PTR [bp-16]	;text_window
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 52
	mov	ax,63
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 53
	mov	ax,45
	jmp	$L20016
$I541:
	cmp	WORD PTR [bp+4],254	;ch
	jne	$I543
; Line 57
	xor	BYTE PTR D_53A4,1
; Line 58
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],1
; Line 59
	jmp	$I558
$I543:
	cmp	WORD PTR [bp+4],253	;ch
	jne	$I544
; Line 62
	xor	BYTE PTR D_53A8,1
; Line 63
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],4
; Line 64
	jmp	$I558
$I544:
	cmp	WORD PTR [bp+4],252	;ch
	jne	$I545
; Line 67
	mov	WORD PTR D_53A6,1
; Line 68
	mov	bx,WORD PTR [bp-16]	;text_window
	or	BYTE PTR [bx+7],2
; Line 69
	jmp	$I558
	nop	
$I545:
	cmp	WORD PTR [bp+4],251	;ch
	jne	$I546
; Line 72
	mov	WORD PTR D_53A6,0
; Line 73
	mov	bx,WORD PTR [bp-16]	;text_window
	and	BYTE PTR [bx+7],253
; Line 74
	jmp	$I558
	nop	
$I546:
	and	WORD PTR [bp+4],127	;ch
; Line 77
; Line 78
$I540:
	cmp	WORD PTR [bp+4],10	;ch
	jne	$JCC182
	jmp	$I547
$JCC182:
; Line 79
	cmp	WORD PTR [bp+4],13	;ch
	jne	$JCC191
	jmp	$LAB_1000_1745549
$JCC191:
; Line 80
	mov	ax,WORD PTR [bp-8]	;uVar6
	mov	cl,3
	shl	ax,cl
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 88
	cmp	WORD PTR D_52BA_VDP+14,3
	jne	$I550
; Line 89
	mov	ax,24
	mul	WORD PTR [bp-8]	;uVar6
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 90
; Line 91
$I550:
	mov	ax,D_5398
	mov	WORD PTR [bp-4],ax	;puVar3
; Line 92
	push	WORD PTR [bp-10]	;puVar7
	push	ax
	call	CONCAT22
	push	ax
	call	FUN_1000_17F4_CHARACTER_EFFECTS
; Line 93
	mov	ax,93
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 94
	mov	WORD PTR [bp-6],OFFSET D_53EA	;puVar5
; Line 95
	mov	WORD PTR [bp-14],4	;iVar4
; Line 96
	cmp	WORD PTR D_52BA_VDP+14,3
	jne	$I552
; Line 97
	mov	WORD PTR [bp-14],12	;iVar4
; Line 98
; Line 99
$I552:
	cmp	WORD PTR [bp-14],0	;iVar4
	je	$FB555
	mov	di,WORD PTR [bp-6]	;puVar5
	mov	si,WORD PTR [bp-10]	;puVar7
	mov	cx,WORD PTR [bp-14]	;iVar4
$L20000:
; Line 100
	mov	WORD PTR [bp-2],si	;puVar2
	add	si,2
; Line 101
	mov	WORD PTR [bp-20],di	;puVar1
	add	di,2
; Line 102
	mov	bx,WORD PTR [bp-20]	;puVar1
	mov	ax,WORD PTR [bx]
	mov	bx,WORD PTR [bp-2]	;puVar2
	mov	WORD PTR [bx],ax
; Line 103
	loop	$L20000
	mov	WORD PTR [bp-6],di	;puVar5
	mov	WORD PTR [bp-10],si	;puVar7
	mov	WORD PTR [bp-14],cx	;iVar4
$FB555:
; Line 105
	mov	ax,D_539A_TEXTWINFORCURRCHARSET
	mov	WORD PTR [bp-16],ax	;text_window
; Line 106
	cmp	WORD PTR D_538E,0
	je	$I558
; Line 107
	mov	bx,ax
	inc	BYTE PTR [bx+4]
; Line 110
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+2]
	cmp	ax,cx
	jbe	$I558
; Line 111
; Line 114
$I547:
	mov	bx,WORD PTR [bp-16]	;text_window
	inc	BYTE PTR [bx+5]
; Line 115
$LAB_1000_1745549:
; Line 116
	mov	bx,WORD PTR [bp-16]	;text_window
	mov	BYTE PTR [bx+4],0
; Line 117
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+3]
	cmp	ax,cx
	jbe	$I558
; Line 123
	push	bx
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 124
	mov	bx,WORD PTR [bp-16]	;text_window
	dec	BYTE PTR [bx+5]
; Line 126
	mov	ax,39
$L20016:
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 128
; Line 129
$I558:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 133
	PUBLIC	FUN_1000_1B94_SELECT_CHARSET
FUN_1000_1B94_SELECT_CHARSET	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
	push	si
;	id = 4
;	register si = b
; Line 136
	push	WORD PTR [bp+4]	;id
	mov	ax,OFFSET DGROUP:$SG562
	push	ax
	call	_printf
	add	sp,4
; Line 138
	cmp	WORD PTR [bp+4],3	;id
	jg	$I563
; Line 139
; Line 140
	mov	ax,WORD PTR [bp+4]	;id
	mov	D_5386_CURRENTTEXTWINDOW,ax
; Line 141
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	D_539A_TEXTWINFORCURRCHARSET,ax
; Line 143
	mov	bx,ax
	mov	al,BYTE PTR [bx+6]
	sub	ah,ah
	mov	si,ax
; Line 144
	and	al,15
	mov	D_53AA,al
; Line 145
	mov	ax,si
	and	ax,240
	mov	cl,4
	sar	ax,cl
	mov	D_53AB,al
; Line 147
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	mov	si,ax
; Line 148
	and	ax,1
	mov	D_53A4,ax
; Line 149
	mov	ax,si
	and	ax,2
	sar	ax,1
	mov	D_53A6,ax
; Line 150
	mov	ax,si
	and	ax,4
	sar	ax,1
	sar	ax,1
	mov	D_53A8,ax
; Line 151
; Line 152
$I563:
	pop	si
	mov	sp,bp
	pop	bp
	ret	2

FUN_1000_1B94_SELECT_CHARSET	ENDP
; Line 156
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 6
;	y = 4
; Line 157
	push	WORD PTR [bp+4]	;y
	push	WORD PTR [bp+6]	;x
	mov	ax,OFFSET DGROUP:$SG567
	push	ax
	call	_printf
	add	sp,6
; Line 159
	mov	al,BYTE PTR [bp+6]	;x
	sub	ah,ah
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	cmp	ax,40
	jae	$I568
	mov	al,BYTE PTR [bp+4]	;y
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	add	ax,cx
	cmp	ax,25
	jae	$I568
; Line 160
; Line 161
	mov	al,BYTE PTR [bp+6]	;x
	mov	BYTE PTR [bx+4],al
; Line 162
	mov	al,BYTE PTR [bp+4]	;y
	mov	BYTE PTR [bx+5],al
; Line 163
; Line 164
$I568:
	pop	bp
	ret	4

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 170
	PUBLIC	FUN_1000_1C22_SET_TEXT_WINDOW_S
FUN_1000_1C22_SET_TEXT_WINDOW_S	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	y1 = 8
;	x2 = 6
;	y2 = 4
;	idx = 12
;	x1 = 10
; Line 171
	push	WORD PTR [bp+4]	;y2
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+12]	;idx
	mov	ax,OFFSET DGROUP:$SG580
	push	ax
	call	_printf
	add	sp,12
; Line 172
	cmp	WORD PTR [bp+12],4	;idx
	jge	$I581
; Line 173
;	win = -2
; Line 174
	mov	ax,WORD PTR [bp+12]	;idx
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	WORD PTR [bp-2],ax	;win
; Line 175
	lea	ax,WORD PTR [bp+10]	;x1
	push	ax
	lea	ax,WORD PTR [bp+8]	;y1
	push	ax
	lea	ax,WORD PTR [bp+6]	;x2
	push	ax
	lea	ax,WORD PTR [bp+4]	;y2
	push	ax
	call	FUN_1000_1C5B_CONSTRAIN_TEXTWIN
; Line 176
	mov	bx,WORD PTR [bp-2]	;win
	mov	al,BYTE PTR [bp+10]	;x1
	mov	BYTE PTR [bx],al
; Line 177
	mov	al,BYTE PTR [bp+8]	;y1
	mov	BYTE PTR [bx+1],al
; Line 178
	mov	al,BYTE PTR [bp+6]	;x2
	mov	BYTE PTR [bx+2],al
; Line 179
	mov	al,BYTE PTR [bp+4]	;y2
	mov	BYTE PTR [bx+3],al
; Line 180
; Line 181
$I581:
	mov	sp,bp
	pop	bp
	ret	10
	nop	

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 185
	PUBLIC	FUN_1000_1C5B_CONSTRAIN_TEXTWIN
FUN_1000_1C5B_CONSTRAIN_TEXTWIN	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
	push	di
	push	si
;	x1 = 10
;	y1 = 8
;	x2 = 6
;	y2 = 4
; Line 186
	mov	bx,WORD PTR [bp+10]	;x1
	cmp	WORD PTR [bx],0
	jge	$I588
; Line 187
	mov	WORD PTR [bx],0
; Line 189
$I588:
	cmp	WORD PTR [bx],39
	jle	$I589
; Line 190
	mov	WORD PTR [bx],39
; Line 192
$I589:
	mov	bx,WORD PTR [bp+8]	;y1
	cmp	WORD PTR [bx],0
	jge	$I590
; Line 193
	mov	WORD PTR [bx],0
; Line 195
$I590:
	cmp	WORD PTR [bx],24
	jle	$I591
; Line 196
	mov	WORD PTR [bx],24
; Line 198
$I591:
	mov	bx,WORD PTR [bp+6]	;x2
	cmp	WORD PTR [bx],0
	jge	$I592
; Line 199
	mov	WORD PTR [bx],0
; Line 201
$I592:
	cmp	WORD PTR [bx],39
	jle	$I593
; Line 202
	mov	WORD PTR [bx],39
; Line 204
$I593:
	mov	bx,WORD PTR [bp+4]	;y2
	cmp	WORD PTR [bx],0
	jge	$I594
; Line 205
	mov	WORD PTR [bx],0
; Line 207
$I594:
	cmp	WORD PTR [bx],24
	jle	$I595
; Line 208
	mov	WORD PTR [bx],24
; Line 210
$I595:
	mov	bx,WORD PTR [bp+6]	;x2
	mov	si,WORD PTR [bx]
	mov	bx,WORD PTR [bp+10]	;x1
	mov	di,WORD PTR [bx]
	cmp	di,si
	jle	$I596
; Line 211
;	temp = -2
; Line 213
	mov	WORD PTR [bp-2],di	;temp
; Line 214
	mov	WORD PTR [bx],si
; Line 215
	mov	bx,WORD PTR [bp+6]	;x2
	mov	ax,di
	mov	WORD PTR [bx],ax
; Line 216
; Line 218
$I596:
	mov	bx,WORD PTR [bp+4]	;y2
	mov	si,WORD PTR [bx]
	mov	bx,WORD PTR [bp+8]	;y1
	mov	di,WORD PTR [bx]
	cmp	di,si
	jle	$I598
; Line 219
;	temp = -2
; Line 221
	mov	WORD PTR [bp-2],di	;temp
; Line 222
	mov	WORD PTR [bx],si
; Line 223
	mov	bx,WORD PTR [bp+4]	;y2
	mov	ax,di
	mov	WORD PTR [bx],ax
; Line 224
; Line 226
$I598:
	mov	ax,WORD PTR [bp+10]	;x1
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8
	nop	

FUN_1000_1C5B_CONSTRAIN_TEXTWIN	ENDP
; Line 230
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
; Line 231
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	ret	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 235
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
; Line 236
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	ret	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 241
	PUBLIC	FUN_1000_1F77_CONVERT_CHAR_DIME
FUN_1000_1F77_CONVERT_CHAR_DIME	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,8
;	window = 4
;	ax = -2
;	bx = -4
;	cx = -6
;	dx = -8
; Line 242
	mov	bx,WORD PTR [bp+4]	;window
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	mov	cl,3
	shr	ax,cl
	mov	WORD PTR [bp-2],ax	;ax
; Line 243
	mov	al,BYTE PTR [bx+1]
	sub	ah,ah
	shr	ax,cl
	mov	WORD PTR [bp-4],ax	;bx
; Line 244
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	shr	ax,cl
	add	ax,7
	mov	WORD PTR [bp-6],ax	;cx
; Line 245
	mov	al,BYTE PTR [bx+3]
	sub	ah,ah
	shr	ax,cl
	add	ax,7
	mov	WORD PTR [bp-8],ax	;dx
; Line 246
	mov	sp,bp
	pop	bp
	ret	2

FUN_1000_1F77_CONVERT_CHAR_DIME	ENDP
; Line 251
	PUBLIC	GRAP_PRINTSTRING
GRAP_PRINTSTRING	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,66
	push	di
	push	si
;	param_1 = 4
;	local_44 = -48
;	local_42 = -42
;	local_1a = -56
;	local_18 = -50
;	local_16 = -44
;	local_14 = -66
;	local_12 = -60
;	local_10 = -54
;	local_e = -64
;	local_c = -58
;	local_a = -52
;	local_8 = -46
;	local_6 = -2
;	local_4 = -62
; Line 267
	push	WORD PTR [bp+4]	;param_1
	mov	ax,OFFSET DGROUP:$SG625
	push	ax
	call	_printf
	add	sp,4
; Line 269
	mov	WORD PTR [bp-46],0	;local_8
; Line 270
	mov	WORD PTR [bp-52],0	;local_a
; Line 271
	mov	WORD PTR [bp-62],0	;local_4
; Line 272
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx],0
	jne	$JCC974
	jmp	$EX610
$JCC974:
; Line 273
; Line 275
	mov	ax,D_5386_CURRENTTEXTWINDOW
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	WORD PTR [bp-60],ax	;local_12
; Line 276
	mov	bx,ax
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	and	ax,2
	mov	WORD PTR [bp-56],ax	;local_1a
; Line 277
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	sub	ax,cx
	mov	WORD PTR [bp-48],ax	;local_44
; Line 280
$D627:
; Line 281
; Line 282
	cmp	WORD PTR [bp-62],0	;local_4
	je	$I630
; Line 283
; Line 284
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 285
; Line 288
$I630:
	sub	ax,ax
	mov	WORD PTR [bp-66],ax	;local_14
	mov	WORD PTR [bp-2],ax	;local_6
	mov	WORD PTR [bp-62],ax	;local_4
; Line 289
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	sub	ah,ah
	mov	cx,WORD PTR [bp-48]	;local_44
	sub	cx,ax
	mov	WORD PTR [bp-54],cx	;local_10
; Line 292
	sub	si,si
	mov	di,cx
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,WORD PTR [bp-46]	;local_8
	jmp	SHORT $L20004
$L20002:
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],13
	je	$L20003
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],0
	je	$L20003
	cmp	si,di
	jg	$L20003
; Line 293
; Line 294
	mov	bx,cx
	add	bx,dx
	mov	al,BYTE PTR [bx]
	mov	[bp-42][si],al
; Line 295
	inc	cx
	inc	si
$L20004:
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],10
	jne	$L20002
$L20003:
	mov	WORD PTR [bp-58],si	;local_c
	mov	WORD PTR [bp-46],cx	;local_8
; Line 298
	or	si,si
	jne	$I634
; Line 299
; Line 300
	mov	bx,cx
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I635
; Line 301
; Line 302
	inc	WORD PTR [bp-46]	;local_8
	mov	al,[bx][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 303
; Line 304
	jmp	$I637
$I635:
; Line 305
; Line 306
	inc	WORD PTR [bp-52]	;local_a
; Line 307
; Line 308
; Line 309
	jmp	$I637
$I634:
; Line 310
; Line 312
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jg	$JCC1156
	jmp	$I638
$JCC1156:
; Line 313
; Line 315
	mov	ax,WORD PTR [bp-58]	;local_c
	mov	WORD PTR [bp-50],ax	;local_18
; Line 316
	mov	ax,WORD PTR [bp-46]	;local_8
	mov	WORD PTR [bp-44],ax	;local_16
; Line 321
	mov	si,WORD PTR [bp-58]	;local_c
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,ax
	jmp	SHORT $L20007
	nop	
$L20005:
	or	si,si
	je	$L20006
	mov	bx,cx
	mov	di,dx
	cmp	BYTE PTR [bx][di],10
	je	$L20006
	cmp	BYTE PTR [bx][di],0
	je	$L20006
	cmp	BYTE PTR [bx][di],13
	je	$L20006
; Line 322
; Line 323
	dec	si
	dec	cx
$L20007:
	mov	bx,cx
	mov	di,dx
	cmp	BYTE PTR [bx][di],32
	jne	$L20005
$L20006:
	mov	WORD PTR [bp-58],si	;local_c
	mov	WORD PTR [bp-46],cx	;local_8
; Line 326
	or	si,si
	jne	$I642
; Line 327
	mov	ax,WORD PTR [bp-50]	;local_18
	mov	WORD PTR [bp-58],ax	;local_c
; Line 328
	mov	ax,WORD PTR [bp-44]	;local_16
	mov	WORD PTR [bp-46],ax	;local_8
; Line 330
	mov	bx,WORD PTR [bp-60]	;local_12
	cmp	BYTE PTR [bx+4],0
	je	$I649
; Line 331
; Line 332
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 333
	mov	WORD PTR [bp-2],1	;local_6
; Line 334
; Line 335
; Line 336
	jmp	SHORT $I649
	nop	
$I642:
; Line 337
; Line 339
	mov	cx,WORD PTR [bp-58]	;local_c
$D645:
; Line 340
; Line 341
	dec	cx
; Line 342
; Line 344
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$D645
	cmp	BYTE PTR [bp-42][si],13
	je	$D645
	cmp	BYTE PTR [bp-42][si],10
	je	$D645
	mov	WORD PTR [bp-58],cx	;local_c
; Line 346
	mov	bx,WORD PTR [bp-46]	;local_8
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I648
; Line 347
	inc	WORD PTR [bp-46]	;local_8
; Line 350
$I648:
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jge	$I649
; Line 351
	inc	WORD PTR [bp-62]	;local_4
; Line 352
$I649:
; Line 355
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I651
$I638:
; Line 359
; Line 360
	dec	WORD PTR [bp-58]	;local_c
; Line 361
$I651:
; Line 364
	cmp	WORD PTR [bp-56],0	;local_1a
	je	$I652
; Line 365
; Line 366
	mov	ax,WORD PTR [bp-48]	;local_44
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I653
; Line 367
; Line 368
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 369
; Line 376
$I653:
	mov	ax,WORD PTR [bp-54]	;local_10
	sub	ax,WORD PTR [bp-58]	;local_c
	cwd	
	sub	ax,dx
	sar	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 378
; Line 381
$I652:
	cmp	WORD PTR [bp-2],0	;local_6
	je	$I654
; Line 382
; Line 384
	mov	cx,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20012
$L20010:
; Line 385
; Line 386
	inc	cx
$L20012:
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$L20010
	mov	WORD PTR [bp-66],cx	;local_14
; Line 387
; Line 390
$I654:
	mov	di,WORD PTR [bp-58]	;local_c
	mov	si,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20015
$L20013:
; Line 391
; Line 393
	mov	al,[bp-42][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 394
	inc	si
$L20015:
	cmp	si,di
	jle	$L20013
	mov	WORD PTR [bp-66],si	;local_14
; Line 395
$I637:
; Line 396
	cmp	WORD PTR [bp-52],0	;local_a
	jne	$JCC1419
	jmp	$D627
$JCC1419:
; Line 397
; Line 398
$EX610:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

GRAP_PRINTSTRING	ENDP
_TEXT	ENDS
END
