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
EXTRN	FUN_1000_4C2A:NEAR
EXTRN	FUN_1000_4CCE:NEAR
EXTRN	FUN_1000_1850_PRINT_STRING:NEAR
EXTRN	FUN_1000_0AA6_FILL_RECTANGLE:NEAR
EXTRN	FUN_1000_0B10_LINE:NEAR
EXTRN	D_5398:WORD
EXTRN	D_539A_TEXTWINFORCURRCHARSET:WORD
EXTRN	D_53A4:WORD
EXTRN	D_53A6:WORD
EXTRN	D_53A8:WORD
EXTRN	D_53AA:BYTE
EXTRN	D_53AB:BYTE
EXTRN	D_53EA:BYTE
EXTRN	D_52BA_VDP:BYTE
EXTRN	D_52DA_PEN_COLOR:WORD
EXTRN	D_13B0_WHITE_COLOR:WORD
EXTRN	D_5883:BYTE
EXTRN	D_13B2_FRAME_COLOR:WORD
EXTRN	D_5892_WIND_DIR:BYTE
EXTRN	D_5893_MAP_ID:BYTE
EXTRN	D_5895_MAP_LEVEL:BYTE
_BSS      SEGMENT
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
EXTRN	D_5386_CURRENTTEXTWINDOW:WORD
EXTRN	D_538E:WORD
_BSS      ENDS
_DATA      SEGMENT
$SG614	DB	'GRAP_PrintString(%s)',  0aH,  00H
$SG653	DB	'FUN_1000_1b94_select_charset(%d)',  0aH,  00H
$SG658	DB	'FUN_1000_1bf2_set_text_cursor_position(%d,%d)',  0aH,  00H
$SG671	DB	'FUN_1000_1c22_set_text_window_size(%d,%d,%d,%d,%d)',  0aH,  00H
$SG710	DB	'Calm ',  00H
$SG712	DB	'North',  00H
$SG714	DB	'South',  00H
$SG716	DB	'East ',  00H
$SG718	DB	'West ',  00H
$SG719	DB	' Winds',  00H
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
; Line 15
	PUBLIC	DRV_FARCALL_2D
DRV_FARCALL_2D	PROC FAR
	push	bp
;	al = 6
; Line 17
	pop	bp
	ret	2
	nop	

DRV_FARCALL_2D	ENDP
; Line 20
	PUBLIC	CONCAT22
CONCAT22	PROC NEAR
	ret	
	nop	

CONCAT22	ENDP
; Line 24
	PUBLIC	FUN_1000_0A70_SET_PEN_COLOR
FUN_1000_0A70_SET_PEN_COLOR	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 25
	cmp	WORD PTR [bp+4],-1	;param_1
	je	$I562
; Line 26
; Line 27
	cmp	WORD PTR D_52BA_VDP+14,0
	jne	$L20000
	mov	ax,3
	jmp	SHORT $L20001
	nop	
$L20000:
	mov	ax,15
$L20001:
	and	WORD PTR [bp+4],ax	;param_1
; Line 28
; Line 30
$I562:
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	D_52DA_PEN_COLOR,ax
; Line 32
	cmp	ax,-1
	je	$I563
; Line 33
; Line 34
	push	ax
	push	cs
	call	DRV_FARCALL_2D
; Line 35
; Line 36
$I563:
	pop	bp
	ret	2

FUN_1000_0A70_SET_PEN_COLOR	ENDP
; Line 39
	PUBLIC	FUN_1000_0892_INITIALIZE_VIDEO_
FUN_1000_0892_INITIALIZE_VIDEO_	PROC NEAR
	push	bp
;	a = 4
; Line 48
	pop	bp
	ret	2
	nop	

FUN_1000_0892_INITIALIZE_VIDEO_	ENDP
; Line 52
	PUBLIC	FUN_1000_16BA_PRINT_CHAR
FUN_1000_16BA_PRINT_CHAR	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,20
	push	di
	push	si
;	pCharacter = -18
;	unaff_DS = -12
;	ch = 4
;	puVar1 = -20
;	puVar2 = -2
;	puVar3 = -4
;	iVar4 = -14
;	puVar5 = -6
;	uVar6 = -8
;	puVar7 = -10
;	text_window = -16
; Line 64
	mov	ax,D_539A_TEXTWINFORCURRCHARSET
	mov	WORD PTR [bp-16],ax	;text_window
; Line 65
	cmp	WORD PTR [bp+4],127	;ch
	ja	$JCC86
	jmp	$I578
$JCC86:
; Line 66
	cmp	WORD PTR [bp+4],255	;ch
	jne	$I579
; Line 67
	mov	bx,ax
	mov	BYTE PTR [bx+4],0
; Line 68
	mov	BYTE PTR [bx+5],0
; Line 69
	mov	ax,45
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 70
	push	WORD PTR [bp-16]	;text_window
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 72
	mov	ax,63
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 73
	mov	ax,45
	jmp	$L20018
$I579:
	cmp	WORD PTR [bp+4],254	;ch
	jne	$I581
; Line 77
	xor	BYTE PTR D_53A4,1
; Line 78
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],1
; Line 79
	jmp	$I596
$I581:
	cmp	WORD PTR [bp+4],253	;ch
	jne	$I582
; Line 82
	xor	BYTE PTR D_53A8,1
; Line 83
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],4
; Line 84
	jmp	$I596
$I582:
	cmp	WORD PTR [bp+4],252	;ch
	jne	$I583
; Line 87
	mov	WORD PTR D_53A6,1
; Line 88
	mov	bx,WORD PTR [bp-16]	;text_window
	or	BYTE PTR [bx+7],2
; Line 89
	jmp	$I596
	nop	
$I583:
	cmp	WORD PTR [bp+4],251	;ch
	jne	$I584
; Line 92
	mov	WORD PTR D_53A6,0
; Line 93
	mov	bx,WORD PTR [bp-16]	;text_window
	and	BYTE PTR [bx+7],253
; Line 94
	jmp	$I596
	nop	
$I584:
	and	WORD PTR [bp+4],127	;ch
; Line 97
; Line 98
$I578:
	cmp	WORD PTR [bp+4],10	;ch
	jne	$JCC236
	jmp	$I585
$JCC236:
; Line 99
	cmp	WORD PTR [bp+4],13	;ch
	jne	$JCC245
	jmp	$LAB_1000_1745587
$JCC245:
; Line 100
	mov	ax,WORD PTR [bp-8]	;uVar6
	mov	cl,3
	shl	ax,cl
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 108
	cmp	WORD PTR D_52BA_VDP+14,3
	jne	$I588
; Line 109
	mov	ax,24
	mul	WORD PTR [bp-8]	;uVar6
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 110
; Line 111
$I588:
	mov	ax,D_5398
	mov	WORD PTR [bp-4],ax	;puVar3
; Line 112
	push	WORD PTR [bp-10]	;puVar7
	push	ax
	call	CONCAT22
	push	ax
	call	FUN_1000_17F4_CHARACTER_EFFECTS
; Line 113
	mov	ax,93
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 114
	mov	WORD PTR [bp-6],OFFSET D_53EA	;puVar5
; Line 115
	mov	WORD PTR [bp-14],4	;iVar4
; Line 116
	cmp	WORD PTR D_52BA_VDP+14,3
	jne	$I590
; Line 117
	mov	WORD PTR [bp-14],12	;iVar4
; Line 118
; Line 119
$I590:
	cmp	WORD PTR [bp-14],0	;iVar4
	je	$FB593
	mov	di,WORD PTR [bp-6]	;puVar5
	mov	si,WORD PTR [bp-10]	;puVar7
	mov	cx,WORD PTR [bp-14]	;iVar4
$L20002:
; Line 120
	mov	WORD PTR [bp-2],si	;puVar2
	add	si,2
; Line 121
	mov	WORD PTR [bp-20],di	;puVar1
	add	di,2
; Line 122
	mov	bx,WORD PTR [bp-20]	;puVar1
	mov	ax,WORD PTR [bx]
	mov	bx,WORD PTR [bp-2]	;puVar2
	mov	WORD PTR [bx],ax
; Line 123
	loop	$L20002
	mov	WORD PTR [bp-6],di	;puVar5
	mov	WORD PTR [bp-10],si	;puVar7
	mov	WORD PTR [bp-14],cx	;iVar4
$FB593:
; Line 125
	mov	ax,D_539A_TEXTWINFORCURRCHARSET
	mov	WORD PTR [bp-16],ax	;text_window
; Line 126
	cmp	WORD PTR D_538E,0
	je	$I596
; Line 127
	mov	bx,ax
	inc	BYTE PTR [bx+4]
; Line 130
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+2]
	cmp	ax,cx
	jbe	$I596
; Line 131
; Line 134
$I585:
	mov	bx,WORD PTR [bp-16]	;text_window
	inc	BYTE PTR [bx+5]
; Line 135
$LAB_1000_1745587:
; Line 136
	mov	bx,WORD PTR [bp-16]	;text_window
	mov	BYTE PTR [bx+4],0
; Line 137
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+3]
	cmp	ax,cx
	jbe	$I596
; Line 143
	push	bx
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 144
	mov	bx,WORD PTR [bp-16]	;text_window
	dec	BYTE PTR [bx+5]
; Line 146
	mov	ax,39
$L20018:
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 148
; Line 149
$I596:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 154
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
; Line 170
	push	WORD PTR [bp+4]	;param_1
	mov	ax,OFFSET DGROUP:$SG614
	push	ax
	call	_printf
	add	sp,4
; Line 172
	mov	WORD PTR [bp-46],0	;local_8
; Line 173
	mov	WORD PTR [bp-52],0	;local_a
; Line 174
	mov	WORD PTR [bp-62],0	;local_4
; Line 175
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx],0
	jne	$JCC508
	jmp	$EX599
$JCC508:
; Line 176
; Line 178
	mov	ax,D_5386_CURRENTTEXTWINDOW
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	WORD PTR [bp-60],ax	;local_12
; Line 179
	mov	bx,ax
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	and	ax,2
	mov	WORD PTR [bp-56],ax	;local_1a
; Line 180
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	sub	ax,cx
	mov	WORD PTR [bp-48],ax	;local_44
; Line 183
$D616:
; Line 184
; Line 185
	cmp	WORD PTR [bp-62],0	;local_4
	je	$I619
; Line 186
; Line 187
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 188
; Line 191
$I619:
	sub	ax,ax
	mov	WORD PTR [bp-66],ax	;local_14
	mov	WORD PTR [bp-2],ax	;local_6
	mov	WORD PTR [bp-62],ax	;local_4
; Line 192
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	sub	ah,ah
	mov	cx,WORD PTR [bp-48]	;local_44
	sub	cx,ax
	mov	WORD PTR [bp-54],cx	;local_10
; Line 195
	sub	si,si
	mov	di,cx
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,WORD PTR [bp-46]	;local_8
	jmp	SHORT $L20006
$L20004:
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],13
	je	$L20005
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],0
	je	$L20005
	cmp	si,di
	jg	$L20005
; Line 196
; Line 197
	mov	bx,cx
	add	bx,dx
	mov	al,BYTE PTR [bx]
	mov	[bp-42][si],al
; Line 198
	inc	cx
	inc	si
$L20006:
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],10
	jne	$L20004
$L20005:
	mov	WORD PTR [bp-58],si	;local_c
	mov	WORD PTR [bp-46],cx	;local_8
; Line 201
	or	si,si
	jne	$I623
; Line 202
; Line 203
	mov	bx,cx
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I624
; Line 204
; Line 205
	inc	WORD PTR [bp-46]	;local_8
	mov	al,[bx][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 206
; Line 207
	jmp	$I626
$I624:
; Line 208
; Line 209
	inc	WORD PTR [bp-52]	;local_a
; Line 210
; Line 211
; Line 212
	jmp	$I626
$I623:
; Line 213
; Line 215
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jg	$JCC690
	jmp	$I627
$JCC690:
; Line 216
; Line 218
	mov	ax,WORD PTR [bp-58]	;local_c
	mov	WORD PTR [bp-50],ax	;local_18
; Line 219
	mov	ax,WORD PTR [bp-46]	;local_8
	mov	WORD PTR [bp-44],ax	;local_16
; Line 224
	mov	si,WORD PTR [bp-58]	;local_c
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,ax
	jmp	SHORT $L20009
	nop	
$L20007:
	or	si,si
	je	$L20008
	mov	bx,cx
	mov	di,dx
	cmp	BYTE PTR [bx][di],10
	je	$L20008
	cmp	BYTE PTR [bx][di],0
	je	$L20008
	cmp	BYTE PTR [bx][di],13
	je	$L20008
; Line 225
; Line 226
	dec	si
	dec	cx
$L20009:
	mov	bx,cx
	mov	di,dx
	cmp	BYTE PTR [bx][di],32
	jne	$L20007
$L20008:
	mov	WORD PTR [bp-58],si	;local_c
	mov	WORD PTR [bp-46],cx	;local_8
; Line 229
	or	si,si
	jne	$I631
; Line 230
	mov	ax,WORD PTR [bp-50]	;local_18
	mov	WORD PTR [bp-58],ax	;local_c
; Line 231
	mov	ax,WORD PTR [bp-44]	;local_16
	mov	WORD PTR [bp-46],ax	;local_8
; Line 233
	mov	bx,WORD PTR [bp-60]	;local_12
	cmp	BYTE PTR [bx+4],0
	je	$I638
; Line 234
; Line 235
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 236
	mov	WORD PTR [bp-2],1	;local_6
; Line 237
; Line 238
; Line 239
	jmp	SHORT $I638
	nop	
$I631:
; Line 240
; Line 242
	mov	cx,WORD PTR [bp-58]	;local_c
$D634:
; Line 243
; Line 244
	dec	cx
; Line 245
; Line 247
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$D634
	cmp	BYTE PTR [bp-42][si],13
	je	$D634
	cmp	BYTE PTR [bp-42][si],10
	je	$D634
	mov	WORD PTR [bp-58],cx	;local_c
; Line 249
	mov	bx,WORD PTR [bp-46]	;local_8
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I637
; Line 250
	inc	WORD PTR [bp-46]	;local_8
; Line 253
$I637:
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jge	$I638
; Line 254
	inc	WORD PTR [bp-62]	;local_4
; Line 255
$I638:
; Line 258
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I640
$I627:
; Line 262
; Line 263
	dec	WORD PTR [bp-58]	;local_c
; Line 264
$I640:
; Line 267
	cmp	WORD PTR [bp-56],0	;local_1a
	je	$I641
; Line 268
; Line 269
	mov	ax,WORD PTR [bp-48]	;local_44
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I642
; Line 270
; Line 271
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 272
; Line 279
$I642:
	mov	ax,WORD PTR [bp-54]	;local_10
	sub	ax,WORD PTR [bp-58]	;local_c
	cwd	
	sub	ax,dx
	sar	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 281
; Line 284
$I641:
	cmp	WORD PTR [bp-2],0	;local_6
	je	$I643
; Line 285
; Line 287
	mov	cx,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20014
$L20012:
; Line 288
; Line 289
	inc	cx
$L20014:
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$L20012
	mov	WORD PTR [bp-66],cx	;local_14
; Line 290
; Line 293
$I643:
	mov	di,WORD PTR [bp-58]	;local_c
	mov	si,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20017
$L20015:
; Line 294
; Line 296
	mov	al,[bp-42][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 297
	inc	si
$L20017:
	cmp	si,di
	jle	$L20015
	mov	WORD PTR [bp-66],si	;local_14
; Line 298
$I626:
; Line 299
	cmp	WORD PTR [bp-52],0	;local_a
	jne	$JCC953
	jmp	$D616
$JCC953:
; Line 300
; Line 301
$EX599:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

GRAP_PRINTSTRING	ENDP
; Line 307
	PUBLIC	FUN_1000_1B94_SELECT_CHARSET
FUN_1000_1B94_SELECT_CHARSET	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
	push	si
;	id = 4
;	register si = b
; Line 310
	push	WORD PTR [bp+4]	;id
	mov	ax,OFFSET DGROUP:$SG653
	push	ax
	call	_printf
	add	sp,4
; Line 312
	cmp	WORD PTR [bp+4],3	;id
	jg	$I654
; Line 313
; Line 314
	mov	ax,WORD PTR [bp+4]	;id
	mov	D_5386_CURRENTTEXTWINDOW,ax
; Line 315
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	D_539A_TEXTWINFORCURRCHARSET,ax
; Line 317
	mov	bx,ax
	mov	al,BYTE PTR [bx+6]
	sub	ah,ah
	mov	si,ax
; Line 318
	and	al,15
	mov	D_53AA,al
; Line 319
	mov	ax,si
	and	ax,240
	mov	cl,4
	sar	ax,cl
	mov	D_53AB,al
; Line 321
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	mov	si,ax
; Line 322
	and	ax,1
	mov	D_53A4,ax
; Line 323
	mov	ax,si
	and	ax,2
	sar	ax,1
	mov	D_53A6,ax
; Line 324
	mov	ax,si
	and	ax,4
	sar	ax,1
	sar	ax,1
	mov	D_53A8,ax
; Line 325
; Line 326
$I654:
	pop	si
	mov	sp,bp
	pop	bp
	ret	2

FUN_1000_1B94_SELECT_CHARSET	ENDP
; Line 330
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 6
;	y = 4
; Line 331
	push	WORD PTR [bp+4]	;y
	push	WORD PTR [bp+6]	;x
	mov	ax,OFFSET DGROUP:$SG658
	push	ax
	call	_printf
	add	sp,6
; Line 333
	mov	al,BYTE PTR [bp+6]	;x
	sub	ah,ah
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	cmp	ax,40
	jae	$I659
	mov	al,BYTE PTR [bp+4]	;y
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	add	ax,cx
	cmp	ax,25
	jae	$I659
; Line 334
; Line 335
	mov	al,BYTE PTR [bp+6]	;x
	mov	BYTE PTR [bx+4],al
; Line 336
	mov	al,BYTE PTR [bp+4]	;y
	mov	BYTE PTR [bx+5],al
; Line 337
; Line 338
$I659:
	pop	bp
	ret	4

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 344
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
; Line 345
	push	WORD PTR [bp+4]	;y2
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+12]	;idx
	mov	ax,OFFSET DGROUP:$SG671
	push	ax
	call	_printf
	add	sp,12
; Line 346
	cmp	WORD PTR [bp+12],4	;idx
	jge	$I672
; Line 347
;	win = -2
; Line 348
	mov	ax,WORD PTR [bp+12]	;idx
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E_TEXTWINDOWS
	mov	WORD PTR [bp-2],ax	;win
; Line 349
	lea	ax,WORD PTR [bp+10]	;x1
	push	ax
	lea	ax,WORD PTR [bp+8]	;y1
	push	ax
	lea	ax,WORD PTR [bp+6]	;x2
	push	ax
	lea	ax,WORD PTR [bp+4]	;y2
	push	ax
	call	FUN_1000_1C5B_CONSTRAIN_TEXTWIN
; Line 350
	mov	bx,WORD PTR [bp-2]	;win
	mov	al,BYTE PTR [bp+10]	;x1
	mov	BYTE PTR [bx],al
; Line 351
	mov	al,BYTE PTR [bp+8]	;y1
	mov	BYTE PTR [bx+1],al
; Line 352
	mov	al,BYTE PTR [bp+6]	;x2
	mov	BYTE PTR [bx+2],al
; Line 353
	mov	al,BYTE PTR [bp+4]	;y2
	mov	BYTE PTR [bx+3],al
; Line 354
; Line 355
$I672:
	mov	sp,bp
	pop	bp
	ret	10
	nop	

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 359
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
; Line 360
	mov	bx,WORD PTR [bp+10]	;x1
	cmp	WORD PTR [bx],0
	jge	$I679
; Line 361
	mov	WORD PTR [bx],0
; Line 363
$I679:
	cmp	WORD PTR [bx],39
	jle	$I680
; Line 364
	mov	WORD PTR [bx],39
; Line 366
$I680:
	mov	bx,WORD PTR [bp+8]	;y1
	cmp	WORD PTR [bx],0
	jge	$I681
; Line 367
	mov	WORD PTR [bx],0
; Line 369
$I681:
	cmp	WORD PTR [bx],24
	jle	$I682
; Line 370
	mov	WORD PTR [bx],24
; Line 372
$I682:
	mov	bx,WORD PTR [bp+6]	;x2
	cmp	WORD PTR [bx],0
	jge	$I683
; Line 373
	mov	WORD PTR [bx],0
; Line 375
$I683:
	cmp	WORD PTR [bx],39
	jle	$I684
; Line 376
	mov	WORD PTR [bx],39
; Line 378
$I684:
	mov	bx,WORD PTR [bp+4]	;y2
	cmp	WORD PTR [bx],0
	jge	$I685
; Line 379
	mov	WORD PTR [bx],0
; Line 381
$I685:
	cmp	WORD PTR [bx],24
	jle	$I686
; Line 382
	mov	WORD PTR [bx],24
; Line 384
$I686:
	mov	bx,WORD PTR [bp+6]	;x2
	mov	si,WORD PTR [bx]
	mov	bx,WORD PTR [bp+10]	;x1
	mov	di,WORD PTR [bx]
	cmp	di,si
	jle	$I687
; Line 385
;	temp = -2
; Line 387
	mov	WORD PTR [bp-2],di	;temp
; Line 388
	mov	WORD PTR [bx],si
; Line 389
	mov	bx,WORD PTR [bp+6]	;x2
	mov	ax,di
	mov	WORD PTR [bx],ax
; Line 390
; Line 392
$I687:
	mov	bx,WORD PTR [bp+4]	;y2
	mov	si,WORD PTR [bx]
	mov	bx,WORD PTR [bp+8]	;y1
	mov	di,WORD PTR [bx]
	cmp	di,si
	jle	$I689
; Line 393
;	temp = -2
; Line 395
	mov	WORD PTR [bp-2],di	;temp
; Line 396
	mov	WORD PTR [bx],si
; Line 397
	mov	bx,WORD PTR [bp+4]	;y2
	mov	ax,di
	mov	WORD PTR [bx],ax
; Line 398
; Line 400
$I689:
	mov	ax,WORD PTR [bp+10]	;x1
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8
	nop	

FUN_1000_1C5B_CONSTRAIN_TEXTWIN	ENDP
; Line 404
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
; Line 405
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	ret	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 409
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
; Line 410
	mov	bx,D_539A_TEXTWINFORCURRCHARSET
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	ret	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 415
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
; Line 416
	mov	bx,WORD PTR [bp+4]	;window
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	mov	cl,3
	shr	ax,cl
	mov	WORD PTR [bp-2],ax	;ax
; Line 417
	mov	al,BYTE PTR [bx+1]
	sub	ah,ah
	shr	ax,cl
	mov	WORD PTR [bp-4],ax	;bx
; Line 418
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	shr	ax,cl
	add	ax,7
	mov	WORD PTR [bp-6],ax	;cx
; Line 419
	mov	al,BYTE PTR [bx+3]
	sub	ah,ah
	shr	ax,cl
	add	ax,7
	mov	WORD PTR [bp-8],ax	;dx
; Line 420
	mov	sp,bp
	pop	bp
	ret	2

FUN_1000_1F77_CONVERT_CHAR_DIME	ENDP
; Line 424
	PUBLIC	FUN_1000_2E96_PRINT_DIRECTION
FUN_1000_2E96_PRINT_DIRECTION	PROC NEAR
	push	bp
	mov	bp,sp
;	direction = 4
; Line 425
	cmp	WORD PTR [bp+4],-1	;direction
	je	$I701
; Line 426
; Line 427
	mov	al,BYTE PTR [bp+4]	;direction
	mov	D_5892_WIND_DIR,al
; Line 428
	mov	BYTE PTR D_5883,0
; Line 429
; Line 431
$I701:
	cmp	BYTE PTR D_5893_MAP_ID,33
	jb	$JCC1511
	jmp	$I720
$JCC1511:
	cmp	BYTE PTR D_5893_MAP_ID,25
	jne	$JCC1521
	jmp	$I720
$JCC1521:
; Line 432
	cmp	BYTE PTR D_5895_MAP_LEVEL,128
	jae	$I704
; Line 435
; Line 436
	sub	ax,ax
	push	ax
	call	FUN_1000_1B94_SELECT_CHARSET
; Line 437
	mov	ax,6
	push	ax
	mov	ax,23
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 438
	call	FUN_1000_4C2A
; Line 440
	mov	al,D_5892_WIND_DIR
	sub	ah,ah
	or	ax,ax
	je	$SC709
	cmp	ax,1
	je	$SC711
	cmp	ax,2
	je	$SC713
	cmp	ax,3
	je	$SC715
	cmp	ax,4
	je	$SC717
	jmp	SHORT $SB706
$SC709:
; Line 443
	mov	ax,OFFSET DGROUP:$SG710
$L20020:
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 444
$SB706:
; Line 459
	mov	ax,OFFSET DGROUP:$SG719
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 460
	call	FUN_1000_4CCE
; Line 461
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_SELECT_CHARSET
; Line 462
; Line 463
	jmp	SHORT $I720
$SC711:
; Line 446
	mov	ax,OFFSET DGROUP:$SG712
	jmp	SHORT $L20020
	nop	
$SC713:
; Line 449
	mov	ax,OFFSET DGROUP:$SG714
	jmp	SHORT $L20020
	nop	
$SC715:
; Line 452
	mov	ax,OFFSET DGROUP:$SG716
	jmp	SHORT $L20020
	nop	
$SC717:
; Line 455
	mov	ax,OFFSET DGROUP:$SG718
	jmp	SHORT $L20020
	nop	
$I704:
; Line 464
; Line 466
	push	WORD PTR D_13B0_WHITE_COLOR
	call	FUN_1000_0A70_SET_PEN_COLOR
; Line 467
	mov	ax,48
	push	ax
	mov	ax,184
	push	ax
	mov	ax,152
	push	ax
	mov	ax,184
	push	ax
	call	FUN_1000_0B10_LINE
; Line 468
	push	WORD PTR D_13B2_FRAME_COLOR
	call	FUN_1000_0A70_SET_PEN_COLOR
; Line 469
	mov	ax,48
	push	ax
	mov	ax,185
	push	ax
	mov	ax,152
	push	ax
	mov	ax,191
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 470
$I720:
; Line 471
	pop	bp
	ret	2

FUN_1000_2E96_PRINT_DIRECTION	ENDP
_TEXT	ENDS
END
