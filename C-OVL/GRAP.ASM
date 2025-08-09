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
EXTRN	FUN_1000_1F77_CONVERT_CHAR_DIME:NEAR
EXTRN	FUN_1000_17F4_CHARACTER_EFFECTS:NEAR
EXTRN	_printf:NEAR
EXTRN	D_52C8_VIDEODRIVERSELECTION:WORD
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
EXTRN	D_53EA:BYTE
_BSS      ENDS
_DATA      SEGMENT
$SG552	DB	'FUN_1000_1b94_select_charset(%d)',  0aH,  00H
$SG557	DB	'FUN_1000_1bf2_set_text_cursor_position(%d,%d)',  0aH,  00H
$SG570	DB	'FUN_1000_1c22_set_text_window_size(%d,%d,%d,%d,%d)',  0aH,  00H
$SG609	DB	'GRAP_PrintString(%s)',  0aH,  00H
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
	jmp	$I530
$JCC32:
; Line 46
	cmp	WORD PTR [bp+4],255	;ch
	jne	$I531
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
$I531:
	cmp	WORD PTR [bp+4],254	;ch
	jne	$I533
; Line 57
	xor	BYTE PTR D_53A4,1
; Line 58
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],1
; Line 59
	jmp	$I548
$I533:
	cmp	WORD PTR [bp+4],253	;ch
	jne	$I534
; Line 62
	xor	BYTE PTR D_53A8,1
; Line 63
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],4
; Line 64
	jmp	$I548
$I534:
	cmp	WORD PTR [bp+4],252	;ch
	jne	$I535
; Line 67
	mov	WORD PTR D_53A6,1
; Line 68
	mov	bx,WORD PTR [bp-16]	;text_window
	or	BYTE PTR [bx+7],2
; Line 69
	jmp	$I548
	nop	
$I535:
	cmp	WORD PTR [bp+4],251	;ch
	jne	$I536
; Line 72
	mov	WORD PTR D_53A6,0
; Line 73
	mov	bx,WORD PTR [bp-16]	;text_window
	and	BYTE PTR [bx+7],253
; Line 74
	jmp	$I548
	nop	
$I536:
	and	WORD PTR [bp+4],127	;ch
; Line 77
; Line 78
$I530:
	cmp	WORD PTR [bp+4],10	;ch
	jne	$JCC182
	jmp	$I537
$JCC182:
; Line 79
	cmp	WORD PTR [bp+4],13	;ch
	jne	$JCC191
	jmp	$LAB_1000_1745539
$JCC191:
; Line 80
	mov	ax,WORD PTR [bp-8]	;uVar6
	mov	cl,3
	shl	ax,cl
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 88
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,3
	jne	$I540
; Line 89
	mov	ax,24
	mul	WORD PTR [bp-8]	;uVar6
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 90
; Line 91
$I540:
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
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,3
	jne	$I542
; Line 97
	mov	WORD PTR [bp-14],12	;iVar4
; Line 98
; Line 99
$I542:
	cmp	WORD PTR [bp-14],0	;iVar4
	je	$FB545
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
$FB545:
; Line 105
	mov	ax,D_539A_TEXTWINFORCURRCHARSET
	mov	WORD PTR [bp-16],ax	;text_window
; Line 106
	cmp	WORD PTR D_538E,0
	je	$I548
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
	jbe	$I548
; Line 111
; Line 114
$I537:
	mov	bx,WORD PTR [bp-16]	;text_window
	inc	BYTE PTR [bx+5]
; Line 115
$LAB_1000_1745539:
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
	jbe	$I548
; Line 118
	push	bx
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 119
	mov	bx,WORD PTR [bp-16]	;text_window
	dec	BYTE PTR [bx+5]
; Line 120
	mov	ax,39
$L20016:
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 121
; Line 122
$I548:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 126
	PUBLIC	FUN_1000_1B94_SELECT_CHARSET
FUN_1000_1B94_SELECT_CHARSET	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
	push	si
;	id = 4
;	register si = b
; Line 129
	push	WORD PTR [bp+4]	;id
	mov	ax,OFFSET DGROUP:$SG552
	push	ax
	call	_printf
	add	sp,4
; Line 131
	cmp	WORD PTR [bp+4],3	;id
	jg	$I553
; Line 132
; Line 133
	mov	ax,WORD PTR [bp+4]	;id
	mov	D_5386_CURRENTTEXTWINDOW,ax
; Line 134
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	D_539A_TEXTWINFORCURRCHARSET,ax
; Line 136
	mov	bx,ax
	mov	al,BYTE PTR [bx+6]
	sub	ah,ah
	mov	si,ax
; Line 137
	and	al,15
	mov	D_53AA,al
; Line 138
	mov	ax,si
	and	ax,240
	mov	cl,4
	sar	ax,cl
	mov	D_53AB,al
; Line 140
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	mov	si,ax
; Line 141
	and	ax,1
	mov	D_53A4,ax
; Line 142
	mov	ax,si
	and	ax,2
	sar	ax,1
	mov	D_53A6,ax
; Line 143
	mov	ax,si
	and	ax,4
	sar	ax,1
	sar	ax,1
	mov	D_53A8,ax
; Line 144
; Line 145
$I553:
	pop	si
	mov	sp,bp
	pop	bp
	ret	2

FUN_1000_1B94_SELECT_CHARSET	ENDP
; Line 149
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 6
;	y = 4
; Line 150
	push	WORD PTR [bp+4]	;y
	push	WORD PTR [bp+6]	;x
	mov	ax,OFFSET DGROUP:$SG557
	push	ax
	call	_printf
	add	sp,6
; Line 152
	mov	al,BYTE PTR [bp+6]	;x
	sub	ah,ah
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	cmp	ax,40
	jae	$I558
	mov	al,BYTE PTR [bp+4]	;y
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	add	ax,cx
	cmp	ax,25
	jae	$I558
; Line 153
; Line 154
	mov	al,BYTE PTR [bp+6]	;x
	mov	BYTE PTR [bx+4],al
; Line 155
	mov	al,BYTE PTR [bp+4]	;y
	mov	BYTE PTR [bx+5],al
; Line 156
; Line 157
$I558:
	pop	bp
	ret	4

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 163
	PUBLIC	FUN_1000_1C22_SET_TEXT_WINDOW_S
FUN_1000_1C22_SET_TEXT_WINDOW_S	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	idx = 12
;	x1 = 10
;	y1 = 8
;	x2 = 6
;	y2 = 4
; Line 164
	push	WORD PTR [bp+4]	;y2
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+12]	;idx
	mov	ax,OFFSET DGROUP:$SG570
	push	ax
	call	_printf
	add	sp,12
; Line 165
	cmp	WORD PTR [bp+12],4	;idx
	jge	$I571
; Line 166
;	win = -2
; Line 167
	mov	ax,WORD PTR [bp+12]	;idx
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	WORD PTR [bp-2],ax	;win
; Line 168
	lea	ax,WORD PTR [bp+10]	;x1
	push	ax
	lea	ax,WORD PTR [bp+8]	;y1
	push	ax
	lea	ax,WORD PTR [bp+6]	;x2
	push	ax
	lea	ax,WORD PTR [bp+4]	;y2
	push	ax
	call	FUN_1000_1C5B_CONSTRAIN_TEXTWIN
; Line 169
	mov	bx,WORD PTR [bp-2]	;win
	mov	al,BYTE PTR [bp+10]	;x1
	mov	BYTE PTR [bx],al
; Line 170
	mov	al,BYTE PTR [bp+8]	;y1
	mov	BYTE PTR [bx+1],al
; Line 171
	mov	al,BYTE PTR [bp+6]	;x2
	mov	BYTE PTR [bx+2],al
; Line 172
	mov	al,BYTE PTR [bp+4]	;y2
	mov	BYTE PTR [bx+3],al
; Line 173
; Line 174
$I571:
	mov	sp,bp
	pop	bp
	ret	10
	nop	

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 178
	PUBLIC	FUN_1000_1C5B_CONSTRAIN_TEXTWIN
FUN_1000_1C5B_CONSTRAIN_TEXTWIN	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
	push	di
	push	si
;	y2 = 4
;	x1 = 10
;	y1 = 8
;	x2 = 6
; Line 179
	mov	bx,WORD PTR [bp+10]	;x1
	cmp	WORD PTR [bx],0
	jge	$I578
; Line 180
	mov	WORD PTR [bx],0
; Line 182
$I578:
	cmp	WORD PTR [bx],39
	jle	$I579
; Line 183
	mov	WORD PTR [bx],39
; Line 185
$I579:
	mov	bx,WORD PTR [bp+8]	;y1
	cmp	WORD PTR [bx],0
	jge	$I580
; Line 186
	mov	WORD PTR [bx],0
; Line 188
$I580:
	cmp	WORD PTR [bx],24
	jle	$I581
; Line 189
	mov	WORD PTR [bx],24
; Line 191
$I581:
	mov	bx,WORD PTR [bp+6]	;x2
	cmp	WORD PTR [bx],0
	jge	$I582
; Line 192
	mov	WORD PTR [bx],0
; Line 194
$I582:
	cmp	WORD PTR [bx],39
	jle	$I583
; Line 195
	mov	WORD PTR [bx],39
; Line 197
$I583:
	mov	bx,WORD PTR [bp+4]	;y2
	cmp	WORD PTR [bx],0
	jge	$I584
; Line 198
	mov	WORD PTR [bx],0
; Line 200
$I584:
	cmp	WORD PTR [bx],24
	jle	$I585
; Line 201
	mov	WORD PTR [bx],24
; Line 203
$I585:
	mov	bx,WORD PTR [bp+6]	;x2
	mov	si,WORD PTR [bx]
	mov	bx,WORD PTR [bp+10]	;x1
	mov	di,WORD PTR [bx]
	cmp	di,si
	jle	$I586
; Line 204
;	temp = -2
; Line 206
	mov	WORD PTR [bp-2],di	;temp
; Line 207
	mov	WORD PTR [bx],si
; Line 208
	mov	bx,WORD PTR [bp+6]	;x2
	mov	ax,di
	mov	WORD PTR [bx],ax
; Line 209
; Line 211
$I586:
	mov	bx,WORD PTR [bp+4]	;y2
	mov	si,WORD PTR [bx]
	mov	bx,WORD PTR [bp+8]	;y1
	mov	di,WORD PTR [bx]
	cmp	di,si
	jle	$I588
; Line 212
;	temp = -2
; Line 214
	mov	WORD PTR [bp-2],di	;temp
; Line 215
	mov	WORD PTR [bx],si
; Line 216
	mov	bx,WORD PTR [bp+4]	;y2
	mov	ax,di
	mov	WORD PTR [bx],ax
; Line 217
; Line 219
$I588:
	mov	ax,WORD PTR [bp+10]	;x1
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8
	nop	

FUN_1000_1C5B_CONSTRAIN_TEXTWIN	ENDP
; Line 223
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
; Line 224
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	ret	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 228
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
; Line 229
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	ret	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 235
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
; Line 251
	push	WORD PTR [bp+4]	;param_1
	mov	ax,OFFSET DGROUP:$SG609
	push	ax
	call	_printf
	add	sp,4
; Line 253
	mov	WORD PTR [bp-46],0	;local_8
; Line 254
	mov	WORD PTR [bp-52],0	;local_a
; Line 255
	mov	WORD PTR [bp-62],0	;local_4
; Line 256
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx],0
	jne	$JCC912
	jmp	$EX594
$JCC912:
; Line 257
; Line 259
	mov	ax,D_5386_CURRENTTEXTWINDOW
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	WORD PTR [bp-60],ax	;local_12
; Line 260
	mov	bx,ax
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	and	ax,2
	mov	WORD PTR [bp-56],ax	;local_1a
; Line 261
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	sub	ax,cx
	mov	WORD PTR [bp-48],ax	;local_44
; Line 264
$D611:
; Line 265
; Line 266
	cmp	WORD PTR [bp-62],0	;local_4
	je	$I614
; Line 267
; Line 268
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 269
; Line 272
$I614:
	sub	ax,ax
	mov	WORD PTR [bp-66],ax	;local_14
	mov	WORD PTR [bp-2],ax	;local_6
	mov	WORD PTR [bp-62],ax	;local_4
; Line 273
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	sub	ah,ah
	mov	cx,WORD PTR [bp-48]	;local_44
	sub	cx,ax
	mov	WORD PTR [bp-54],cx	;local_10
; Line 276
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
; Line 277
; Line 278
	mov	bx,cx
	add	bx,dx
	mov	al,BYTE PTR [bx]
	mov	[bp-42][si],al
; Line 279
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
; Line 282
	or	si,si
	jne	$I618
; Line 283
; Line 284
	mov	bx,cx
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I619
; Line 285
; Line 286
	inc	WORD PTR [bp-46]	;local_8
	mov	al,[bx][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 287
; Line 288
	jmp	$I621
$I619:
; Line 289
; Line 290
	inc	WORD PTR [bp-52]	;local_a
; Line 291
; Line 292
; Line 293
	jmp	$I621
$I618:
; Line 294
; Line 296
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jg	$JCC1094
	jmp	$I622
$JCC1094:
; Line 297
; Line 299
	mov	ax,WORD PTR [bp-58]	;local_c
	mov	WORD PTR [bp-50],ax	;local_18
; Line 300
	mov	ax,WORD PTR [bp-46]	;local_8
	mov	WORD PTR [bp-44],ax	;local_16
; Line 305
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
; Line 306
; Line 307
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
; Line 310
	or	si,si
	jne	$I626
; Line 311
	mov	ax,WORD PTR [bp-50]	;local_18
	mov	WORD PTR [bp-58],ax	;local_c
; Line 312
	mov	ax,WORD PTR [bp-44]	;local_16
	mov	WORD PTR [bp-46],ax	;local_8
; Line 314
	mov	bx,WORD PTR [bp-60]	;local_12
	cmp	BYTE PTR [bx+4],0
	je	$I633
; Line 315
; Line 316
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 317
	mov	WORD PTR [bp-2],1	;local_6
; Line 318
; Line 319
; Line 320
	jmp	SHORT $I633
	nop	
$I626:
; Line 321
; Line 323
	mov	cx,WORD PTR [bp-58]	;local_c
$D629:
; Line 324
; Line 325
	dec	cx
; Line 326
; Line 328
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$D629
	cmp	BYTE PTR [bp-42][si],13
	je	$D629
	cmp	BYTE PTR [bp-42][si],10
	je	$D629
	mov	WORD PTR [bp-58],cx	;local_c
; Line 330
	mov	bx,WORD PTR [bp-46]	;local_8
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I632
; Line 331
	inc	WORD PTR [bp-46]	;local_8
; Line 334
$I632:
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jge	$I633
; Line 335
	inc	WORD PTR [bp-62]	;local_4
; Line 336
$I633:
; Line 339
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I635
$I622:
; Line 343
; Line 344
	dec	WORD PTR [bp-58]	;local_c
; Line 345
$I635:
; Line 348
	cmp	WORD PTR [bp-56],0	;local_1a
	je	$I636
; Line 349
; Line 350
	mov	ax,WORD PTR [bp-48]	;local_44
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I637
; Line 351
; Line 352
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 353
; Line 360
$I637:
	mov	ax,WORD PTR [bp-54]	;local_10
	sub	ax,WORD PTR [bp-58]	;local_c
	cwd	
	sub	ax,dx
	sar	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 362
; Line 365
$I636:
	cmp	WORD PTR [bp-2],0	;local_6
	je	$I638
; Line 366
; Line 368
	mov	cx,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20012
$L20010:
; Line 369
; Line 370
	inc	cx
$L20012:
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$L20010
	mov	WORD PTR [bp-66],cx	;local_14
; Line 371
; Line 374
$I638:
	mov	di,WORD PTR [bp-58]	;local_c
	mov	si,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20015
$L20013:
; Line 375
; Line 377
	mov	al,[bp-42][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 378
	inc	si
$L20015:
	cmp	si,di
	jle	$L20013
	mov	WORD PTR [bp-66],si	;local_14
; Line 379
$I621:
; Line 380
	cmp	WORD PTR [bp-52],0	;local_a
	jne	$JCC1357
	jmp	$D611
$JCC1357:
; Line 381
; Line 382
$EX594:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

GRAP_PRINTSTRING	ENDP
_TEXT	ENDS
END
