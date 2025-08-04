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
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_1000_1CEE_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_1F12_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_1F77_CONVERT_CHAR_DIME:NEAR
EXTRN	FUN_1000_17F4_CHARACTER_EFFECTS:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	D_52C8:WORD
_BSS      SEGMENT
COMM NEAR	D_535E:	BYTE:	 32
EXTRN	D_5386:WORD
EXTRN	D_538E:WORD
EXTRN	D_5398:WORD
EXTRN	D_539A:WORD
EXTRN	D_53A4:WORD
EXTRN	D_53A6:WORD
EXTRN	D_53A8:WORD
EXTRN	D_53EA:BYTE
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 7
	PUBLIC	DRV_FARCALL
DRV_FARCALL	PROC FAR
	push	bp
;	offset = 6
; Line 9
	pop	bp
	ret	2
	nop	

DRV_FARCALL	ENDP
; Line 12
	PUBLIC	CONCAT22
CONCAT22	PROC NEAR
	ret	
	nop	

CONCAT22	ENDP
; Line 15
	PUBLIC	TEST
TEST	PROC NEAR
	push	bp
	mov	bp,sp
;	param = 8
;	a = 4
; Line 16
	mov	bx,WORD PTR [bp+8]	;param
	mov	ax,WORD PTR [bp+4]	;a
	mov	WORD PTR [bx],ax
; Line 17
	pop	bp
	ret	6
	nop	

TEST	ENDP
; Line 20
	PUBLIC	GRAP_FMT_PRINTCHAR
GRAP_FMT_PRINTCHAR	PROC NEAR
	push	bp
;	param_1 = 4
; Line 22
	pop	bp
	ret	2
	nop	

GRAP_FMT_PRINTCHAR	ENDP
; Line 156
	PUBLIC	GRAP_PRINTCHAR
GRAP_PRINTCHAR	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,18
	push	di
	push	si
;	param_1 = 4
;	puVar1 = -18
;	puVar2 = -2
;	puVar3 = -4
;	iVar4 = -14
;	puVar5 = -6
;	text_window = -16
;	uVar6 = -8
;	puVar7 = -10
;	unaff_DS = -12
; Line 167
	mov	al,BYTE PTR [bp+4]	;param_1
	sub	ah,ah
	mov	WORD PTR [bp-8],ax	;uVar6
; Line 168
	mov	ax,D_539A
	mov	WORD PTR [bp-16],ax	;text_window
; Line 169
	cmp	BYTE PTR [bp+4],127	;param_1
	ja	$JCC56
	jmp	$I478
$JCC56:
; Line 170
	cmp	BYTE PTR [bp+4],255	;param_1
	jne	$I479
; Line 171
	mov	bx,ax
	mov	BYTE PTR [bx+4],0
; Line 172
	mov	BYTE PTR [bx+5],0
; Line 173
	mov	ax,45
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 174
	push	WORD PTR [bp-16]	;text_window
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 176
	mov	ax,63
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 177
	mov	ax,45
	jmp	$L20013
	nop	
$I479:
	cmp	BYTE PTR [bp+4],254	;param_1
	jne	$I481
; Line 181
	xor	BYTE PTR D_53A4,1
; Line 182
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],1
; Line 183
	jmp	$I496
	nop	
$I481:
	cmp	BYTE PTR [bp+4],253	;param_1
	jne	$I482
; Line 186
	xor	BYTE PTR D_53A8,1
; Line 187
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],4
; Line 188
	jmp	$I496
	nop	
$I482:
	cmp	BYTE PTR [bp+4],252	;param_1
	jne	$I483
; Line 191
	mov	WORD PTR D_53A6,1
; Line 192
	mov	bx,WORD PTR [bp-16]	;text_window
	or	BYTE PTR [bx+7],2
; Line 193
	jmp	$I496
$I483:
	cmp	BYTE PTR [bp+4],251	;param_1
	jne	$I484
; Line 196
	mov	WORD PTR D_53A6,0
; Line 197
	mov	bx,WORD PTR [bp-16]	;text_window
	and	BYTE PTR [bx+7],253
; Line 198
	jmp	$I496
$I484:
	and	BYTE PTR [bp+4],127	;param_1
; Line 201
; Line 202
$I478:
	cmp	BYTE PTR [bp+4],10	;param_1
	jne	$JCC202
	jmp	$I485
$JCC202:
; Line 203
	cmp	BYTE PTR [bp+4],13	;param_1
	jne	$JCC211
	jmp	$LAB_1000_1745487
$JCC211:
	mov	ax,WORD PTR [bp-8]	;uVar6
	mov	cl,3
	shl	ax,cl
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 205
	cmp	WORD PTR D_52C8,3
	jne	$I488
; Line 206
	mov	ax,24
	mul	WORD PTR [bp-8]	;uVar6
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 207
; Line 208
$I488:
	mov	ax,D_5398
	mov	WORD PTR [bp-4],ax	;puVar3
; Line 209
	push	WORD PTR [bp-10]	;puVar7
	push	ax
	call	CONCAT22
	push	ax
	call	FUN_1000_17F4_CHARACTER_EFFECTS
; Line 210
	mov	ax,93
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 211
	mov	WORD PTR [bp-6],OFFSET D_53EA	;puVar5
; Line 212
	mov	WORD PTR [bp-14],4	;iVar4
; Line 213
	cmp	WORD PTR D_52C8,3
	jne	$I490
; Line 214
	mov	WORD PTR [bp-14],12	;iVar4
; Line 215
; Line 216
$I490:
	cmp	WORD PTR [bp-14],0	;iVar4
	je	$FB493
	mov	di,WORD PTR [bp-6]	;puVar5
	mov	si,WORD PTR [bp-10]	;puVar7
	mov	cx,WORD PTR [bp-14]	;iVar4
$L20000:
; Line 217
	mov	WORD PTR [bp-2],si	;puVar2
	add	si,2
; Line 218
	mov	WORD PTR [bp-18],di	;puVar1
	add	di,2
; Line 219
	mov	bx,WORD PTR [bp-18]	;puVar1
	mov	ax,WORD PTR [bx]
	mov	bx,WORD PTR [bp-2]	;puVar2
	mov	WORD PTR [bx],ax
; Line 220
	loop	$L20000
	mov	WORD PTR [bp-6],di	;puVar5
	mov	WORD PTR [bp-10],si	;puVar7
	mov	WORD PTR [bp-14],cx	;iVar4
$FB493:
; Line 221
	mov	ax,D_539A
	mov	WORD PTR [bp-16],ax	;text_window
; Line 222
	cmp	WORD PTR D_538E,0
	je	$I496
; Line 223
	mov	bx,ax
	inc	BYTE PTR [bx+4]
; Line 226
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+2]
	cmp	ax,cx
	jbe	$I496
; Line 227
; Line 230
$I485:
	mov	bx,WORD PTR [bp-16]	;text_window
	inc	BYTE PTR [bx+5]
; Line 231
$LAB_1000_1745487:
; Line 232
	mov	bx,WORD PTR [bp-16]	;text_window
	mov	BYTE PTR [bx+4],0
; Line 233
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+3]
	cmp	ax,cx
	jbe	$I496
; Line 234
	push	bx
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 235
	mov	bx,WORD PTR [bp-16]	;text_window
	dec	BYTE PTR [bx+5]
; Line 236
	mov	ax,39
$L20013:
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 237
; Line 238
$I496:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

GRAP_PRINTCHAR	ENDP
; Line 243
	PUBLIC	GRAP_PRINTSTRING
GRAP_PRINTSTRING	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,66
	push	di
	push	si
;	local_6 = -2
;	local_4 = -62
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
; Line 259
	mov	WORD PTR [bp-46],0	;local_8
; Line 260
	mov	WORD PTR [bp-52],0	;local_a
; Line 261
	mov	WORD PTR [bp-62],0	;local_4
; Line 262
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx],0
	jne	$JCC461
	jmp	$EX499
$JCC461:
; Line 263
; Line 265
	mov	ax,D_5386
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E
	mov	WORD PTR [bp-60],ax	;local_12
; Line 266
	mov	bx,ax
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	and	ax,2
	mov	WORD PTR [bp-56],ax	;local_1a
; Line 267
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	sub	ax,cx
	mov	WORD PTR [bp-48],ax	;local_44
; Line 270
$D515:
; Line 271
; Line 272
	cmp	WORD PTR [bp-62],0	;local_4
	je	$I518
; Line 273
; Line 274
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 275
; Line 278
$I518:
	sub	ax,ax
	mov	WORD PTR [bp-66],ax	;local_14
	mov	WORD PTR [bp-2],ax	;local_6
	mov	WORD PTR [bp-62],ax	;local_4
; Line 279
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	mov	cx,WORD PTR [bp-48]	;local_44
	sub	cx,ax
	mov	WORD PTR [bp-54],cx	;local_10
; Line 282
	sub	si,si
	mov	di,cx
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,WORD PTR [bp-46]	;local_8
	jmp	SHORT $L20004
	nop	
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
; Line 283
; Line 284
	mov	bx,cx
	add	bx,dx
	mov	al,BYTE PTR [bx]
	mov	[bp-42][si],al
; Line 285
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
; Line 288
	or	si,si
	jne	$I522
; Line 289
; Line 290
	mov	bx,cx
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I523
; Line 291
; Line 292
	inc	WORD PTR [bp-46]	;local_8
	mov	al,[bx][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 293
; Line 294
	jmp	$FB548
$I523:
; Line 295
; Line 296
	inc	WORD PTR [bp-52]	;local_a
; Line 297
; Line 298
; Line 299
	jmp	$FB548
$I522:
; Line 300
; Line 302
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jg	$JCC642
	jmp	$I526
$JCC642:
; Line 303
; Line 305
	mov	ax,WORD PTR [bp-58]	;local_c
	mov	WORD PTR [bp-50],ax	;local_18
; Line 306
	mov	ax,WORD PTR [bp-46]	;local_8
	mov	WORD PTR [bp-44],ax	;local_16
; Line 311
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
; Line 312
; Line 313
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
; Line 316
	or	si,si
	jne	$I530
; Line 317
	mov	ax,WORD PTR [bp-50]	;local_18
	mov	WORD PTR [bp-58],ax	;local_c
; Line 318
	mov	ax,WORD PTR [bp-44]	;local_16
	mov	WORD PTR [bp-46],ax	;local_8
; Line 320
	mov	bx,WORD PTR [bp-60]	;local_12
	cmp	BYTE PTR [bx+4],0
	je	$I537
; Line 321
; Line 322
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 323
	mov	WORD PTR [bp-2],1	;local_6
; Line 324
; Line 325
; Line 326
	jmp	SHORT $I537
	nop	
$I530:
; Line 327
; Line 329
	mov	cx,WORD PTR [bp-58]	;local_c
$D533:
; Line 330
; Line 331
	dec	cx
; Line 332
; Line 334
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$D533
	cmp	BYTE PTR [bp-42][si],13
	je	$D533
	cmp	BYTE PTR [bp-42][si],10
	je	$D533
	mov	WORD PTR [bp-58],cx	;local_c
; Line 336
	mov	bx,WORD PTR [bp-46]	;local_8
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I536
; Line 337
	inc	WORD PTR [bp-46]	;local_8
; Line 340
$I536:
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jge	$I537
; Line 341
	inc	WORD PTR [bp-62]	;local_4
; Line 342
$I537:
; Line 345
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I539
$I526:
; Line 349
; Line 350
	dec	WORD PTR [bp-58]	;local_c
; Line 351
$I539:
; Line 354
	cmp	WORD PTR [bp-56],0	;local_1a
	je	$I540
; Line 355
; Line 356
	mov	ax,WORD PTR [bp-48]	;local_44
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I541
; Line 357
; Line 358
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 359
; Line 363
$I541:
	mov	ax,WORD PTR [bp-54]	;local_10
	sub	ax,WORD PTR [bp-58]	;local_c
	cwd	
	sub	ax,dx
	sar	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 364
; Line 367
$I540:
	cmp	WORD PTR [bp-2],0	;local_6
	je	$F546
; Line 368
; Line 370
	mov	cx,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20012
$L20010:
; Line 371
; Line 372
	inc	cx
$L20012:
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$L20010
	mov	WORD PTR [bp-66],cx	;local_14
; Line 373
; Line 376
	jmp	SHORT $F546
$FC547:
	inc	WORD PTR [bp-66]	;local_14
$F546:
	mov	ax,WORD PTR [bp-58]	;local_c
	cmp	WORD PTR [bp-66],ax	;local_14
	jg	$FB548
; Line 377
; Line 379
	mov	si,WORD PTR [bp-66]	;local_14
	mov	al,[bp-42][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 380
	jmp	SHORT $FC547
	nop	
$FB548:
; Line 381
; Line 382
	cmp	WORD PTR [bp-52],0	;local_a
	jne	$JCC908
	jmp	$D515
$JCC908:
; Line 383
; Line 384
$EX499:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

GRAP_PRINTSTRING	ENDP
_TEXT	ENDS
END
