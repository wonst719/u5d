;	Static Name Aliases
;
	TITLE   zstats.c
	NAME    zstats

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
EXTRN	FUN_1000_1C9E:NEAR
EXTRN	FUN_1000_16BA:NEAR
EXTRN	FUN_1000_1850:NEAR
EXTRN	SUB_0000_3670:NEAR
EXTRN	FUN_1000_1A3E:NEAR
EXTRN	SUB_0000_6D1C:NEAR
EXTRN	FUN_1000_1C22:NEAR
EXTRN	SUB_0000_39B4:NEAR
EXTRN	FUN_1000_1CEE:NEAR
EXTRN	SUB_0000_6C70:NEAR
EXTRN	FUN_1000_1BF2:NEAR
EXTRN	SUB_0000_6BCA:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	SUB_0000_6C40:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	SUB_0000_6D5C:NEAR
EXTRN	FUN_1000_4E20:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	SUB_0000_4720:NEAR
EXTRN	FUN_1000_4F3C:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_2092:NEAR
EXTRN	FUN_1000_43AE:NEAR
EXTRN	FUN_1000_1B94:NEAR
EXTRN	FUN_1000_266C:NEAR
EXTRN	F_056C:NEAR
EXTRN	FUN_1000_1F12:NEAR
EXTRN	F_05A4:NEAR
EXTRN	FUN_1000_4DEA:NEAR
EXTRN	FUN_1000_4EFC:NEAR
EXTRN	FUN_0000_8BCA:NEAR
EXTRN	FUN_1000_4D76:NEAR
EXTRN	FUN_1000_6E60:NEAR
EXTRN	FUN_ZSTATS_01E74C:NEAR
EXTRN	UNK_0000_5828:QWORD
EXTRN	UNK_0000_BA0F:BYTE
EXTRN	UNK_0000_5840:QWORD
EXTRN	UNK_0000_BA10:BYTE
EXTRN	DAT_0000_5850:BYTE
EXTRN	UNK_0000_BA11:BYTE
EXTRN	UNK_0000_BA12:BYTE
EXTRN	DAT_5893:BYTE
EXTRN	DAT_58A3:BYTE
EXTRN	UNK_0000_BA13:BYTE
EXTRN	D_BA16:BYTE
EXTRN	UNK_0000_589E:BYTE
EXTRN	UNK_0000_5C5A:BYTE
EXTRN	UNK_0000_BA18:BYTE
EXTRN	TEXT_96B4:WORD
EXTRN	TEXT_96BE:WORD
EXTRN	TEXT_96C6:WORD
EXTRN	TEXT_96D0:WORD
EXTRN	TEXT_96D6:WORD
EXTRN	TEXT_96DC:WORD
EXTRN	TEXT_96E2:WORD
EXTRN	TEXT_96E8:WORD
EXTRN	TEXT_96EE:WORD
EXTRN	TEXT_96F4:WORD
EXTRN	TEXT_96FA:WORD
EXTRN	TEXT_9700:WORD
EXTRN	TEXT_970E:WORD
EXTRN	D_1916:BYTE
EXTRN	TEXT_9716:WORD
EXTRN	D_1962:BYTE
EXTRN	TEXT_9724:WORD
_BSS      SEGMENT
COMM NEAR	D_19B2:	BYTE:	 2
EXTRN	TEXT_972E:WORD
EXTRN	D_19D2:BYTE
EXTRN	TEXT_9738:WORD
EXTRN	D_19E2:BYTE
EXTRN	TEXT_9742:WORD
EXTRN	D_1A44:BYTE
EXTRN	TEXT_9752:WORD
EXTRN	D_1A58:BYTE
EXTRN	TEXT_9760:WORD
EXTRN	D_1A6A:BYTE
EXTRN	TEXT_976E:WORD
EXTRN	D_1A7E:BYTE
EXTRN	TEXT_9778:WORD
EXTRN	D_1AE8:BYTE
EXTRN	TEXT_977C:WORD
EXTRN	D_1ADE:BYTE
EXTRN	TEXT_9782:WORD
EXTRN	D_1AAE:BYTE
EXTRN	TEXT_9788:WORD
EXTRN	TEXT_9794:WORD
EXTRN	TEXT_97A2:WORD
EXTRN	TEXT_97AC:WORD
EXTRN	TEXT_97B6:WORD
EXTRN	TEXT_97BE:WORD
EXTRN	TEXT_97C4:WORD
EXTRN	TEXT_97CE:WORD
EXTRN	TEXT_97D4:WORD
EXTRN	TEXT_97D8:WORD
EXTRN	DAT_55A8:WORD
EXTRN	TEXT_97E2:WORD
EXTRN	UNK_0000_57A8:WORD
EXTRN	TEXT_9812:WORD
EXTRN	UNK_0000_57AA:WORD
EXTRN	TEXT_981C:WORD
EXTRN	UNK_0000_57AC:BYTE
EXTRN	TEXT_9846:WORD
EXTRN	UNK_0000_57AD:BYTE
EXTRN	TEXT_9866:WORD
EXTRN	UNK_0000_57AE:BYTE
EXTRN	TEXT_9892:WORD
EXTRN	UNK_0000_57AF:BYTE
EXTRN	TEXT_98BA:WORD
EXTRN	UNK_0000_57B0:BYTE
EXTRN	TEXT_98F0:WORD
EXTRN	UNK_0000_57B1:BYTE
EXTRN	TEXT_9916:WORD
EXTRN	UNK_0000_57B3:BYTE
EXTRN	TEXT_9942:WORD
EXTRN	UNK_0000_57B4:BYTE
EXTRN	TEXT_995E:WORD
EXTRN	UNK_0000_57B5:BYTE
EXTRN	TEXT_9970:WORD
EXTRN	UNK_0000_57B6:BYTE
EXTRN	TEXT_9976:WORD
EXTRN	UNK_0000_57BA:BYTE
EXTRN	UNK_0000_57BB:BYTE
EXTRN	UNK_0000_B9EE:QWORD
EXTRN	UNK_0000_57BC:BYTE
EXTRN	UNK_0000_B9F6:QWORD
EXTRN	UNK_0000_57BD:BYTE
EXTRN	UNK_0000_B9FE:BYTE
EXTRN	UNK_0000_57BE:BYTE
EXTRN	UNK_0000_B9FF:BYTE
EXTRN	UNK_0000_BA00:BYTE
EXTRN	UNK_0000_57BF:BYTE
EXTRN	DAT_0000_57C0:BYTE
EXTRN	UNK_0000_BA01:BYTE
EXTRN	UNK_0000_57DB:BYTE
EXTRN	UNK_0000_BA02:BYTE
EXTRN	UNK_0000_57DD:BYTE
EXTRN	UNK_0000_BA03:QWORD
EXTRN	DAT_0000_58F0:BYTE
EXTRN	UNK_0000_BA0B:BYTE
EXTRN	UNK_0000_5820:QWORD
EXTRN	UNK_0000_BA0E:BYTE
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 178
	PUBLIC	F_ZSTATS_0000
F_ZSTATS_0000	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 183
	mov	WORD PTR [bp-4],-1	;local_4
; Line 185
	cmp	BYTE PTR DAT_5893,128
	jbe	$I292
; Line 186
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 187
	test	BYTE PTR D_BA16[si],128
	je	$I292
; Line 188
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 191
	jmp	SHORT $I298
$I292:
; Line 194
	push	WORD PTR TEXT_96B4
	call	FUN_1000_1850
; Line 195
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 196
	or	ax,ax
	jl	$I298
; Line 197
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	push	ax
	call	FUN_1000_1850
; Line 198
	call	FUN_1000_1F12
	or	ax,ax
	je	$I298
; Line 199
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 200
; Line 201
$I298:
; Line 202
; Line 205
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I299
; Line 206
	push	WORD PTR TEXT_96BE
	call	FUN_1000_1850
; Line 207
; Line 209
	jmp	SHORT $I301
	nop	
$I299:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I301
; Line 210
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 211
; Line 214
$I301:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0000	ENDP
; Line 220
	PUBLIC	F_ZSTATS_0082
F_ZSTATS_0082	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,12
	push	di
	push	si
;	param_1 = 4
;	local_6 = -2
;	local_8 = -4
;	local_a = -6
;	local_4 = -12
;	register si = si
;	register di = di
; Line 230
	call	FUN_0000_8BCA
; Line 232
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 234
	push	ax
	call	FUN_1000_4E50
; Line 235
	mov	ax,1
	push	ax
	mov	ax,24
	push	ax
	mov	ax,1
	push	ax
	mov	ax,38
	push	ax
	mov	ax,9
	push	ax
	call	FUN_1000_1C22
; Line 236
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 237
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
; Line 239
	mov	ax,OFFSET TEXT_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 240
	mov	ax,OFFSET TEXT_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 241
	mov	WORD PTR [bp-4],0	;local_8
; Line 243
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I313
; Line 244
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 246
	sub	si,si
; Line 247
$FC315:
; Line 248
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 249
	inc	si
; Line 250
	cmp	WORD PTR [di],si
	jg	$FC315
; Line 251
; Line 254
	mov	WORD PTR [bp-4],si	;local_8
; Line 255
; Line 257
$I313:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 258
	push	WORD PTR TEXT_96D6
	call	FUN_1000_1850
; Line 259
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 260
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 261
	mov	ax,WORD PTR [bp-2]	;local_6
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 262
	mov	ax,1
	push	ax
	mov	ax,24
	push	ax
	mov	ax,1
	push	ax
	mov	ax,38
	push	ax
	mov	ax,9
	push	ax
	call	FUN_1000_1C22
; Line 263
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 264
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 265
	mov	ax,WORD PTR [bp-6]	;local_a
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 266
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
; Line 267
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 268
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 269
	push	WORD PTR TEXT_96DC
	call	FUN_1000_1850
; Line 270
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 271
	push	WORD PTR TEXT_96E2
	call	FUN_1000_1850
; Line 272
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 273
	push	WORD PTR TEXT_96E8
	call	FUN_1000_1850
; Line 274
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 275
	push	WORD PTR TEXT_96EE
	call	FUN_1000_1850
; Line 276
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 277
	push	WORD PTR TEXT_96F4
	call	FUN_1000_1850
; Line 278
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 279
	push	WORD PTR TEXT_96FA
	call	FUN_1000_1850
; Line 280
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 281
	push	WORD PTR TEXT_9700
	call	FUN_1000_1850
; Line 282
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 283
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0082	ENDP
; Line 288
	PUBLIC	F_ZSTATS_0278
F_ZSTATS_0278	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 289
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I321
; Line 290
	sub	ax,ax
	jmp	SHORT $EX320
$I321:
; Line 291
; Line 292
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 293
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_1000_1850
; Line 294
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 295
	mov	ax,1
$EX320:
	pop	bp
	ret	2
	nop	

F_ZSTATS_0278	ENDP
; Line 302
	PUBLIC	F_ZSTATS_02A8
F_ZSTATS_02A8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 306
	call	FUN_1000_4DAA
; Line 308
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 309
	push	ax
	call	FUN_1000_4E50
; Line 310
	mov	ax,1
	push	ax
	mov	ax,24
	push	ax
	mov	ax,1
	push	ax
	mov	ax,38
	push	ax
	mov	ax,9
	push	ax
	call	FUN_1000_1C22
; Line 311
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 312
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 313
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 314
	push	WORD PTR TEXT_970E
	call	FUN_1000_1850
; Line 315
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 316
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 318
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	mov	WORD PTR [bp-4],ax	;local_4
; Line 319
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 320
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 321
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 322
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 323
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 325
	jne	$I328
; Line 326
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 327
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 328
	push	WORD PTR TEXT_9716
	call	FUN_1000_1850
; Line 329
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 330
; Line 332
$I328:
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
; Line 333
	mov	sp,bp
	pop	bp
	ret	2

F_ZSTATS_02A8	ENDP
; Line 338
	PUBLIC	F_ZSTATS_039C
F_ZSTATS_039C	PROC NEAR
; Line 339
	call	FUN_1000_4DAA
; Line 340
	mov	ax,OFFSET TEXT_9724
	push	ax
	call	FUN_1000_4E50
; Line 341
	mov	ax,1
	push	ax
	mov	ax,24
	push	ax
	mov	ax,1
	push	ax
	mov	ax,38
	push	ax
	mov	ax,9
	push	ax
	call	FUN_1000_1C22
; Line 342
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 343
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
; Line 344
	push	WORD PTR TEXT_972E
	call	FUN_1000_1850
; Line 345
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 346
	push	WORD PTR TEXT_9738
	call	FUN_1000_1850
; Line 347
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 348
	push	WORD PTR TEXT_9742
	call	FUN_1000_1850
; Line 349
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 350
	push	WORD PTR TEXT_9752
	call	FUN_1000_1850
; Line 351
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 352
	push	WORD PTR TEXT_9760
	call	FUN_1000_1850
; Line 353
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 354
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I331
; Line 355
	push	WORD PTR TEXT_976E
	call	FUN_1000_1850
; Line 356
; Line 357
$I331:
	ret	

F_ZSTATS_039C	ENDP
; Line 362
	PUBLIC	F_ZSTATS_045E
F_ZSTATS_045E	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	param_1 = 4
;	register si = si
;	local_4 = -4
; Line 366
	mov	ax,1
	push	ax
	mov	ax,24
	push	ax
	mov	ax,1
	push	ax
	mov	ax,38
	push	ax
	mov	ax,WORD PTR [bp+4]	;param_1
	inc	ax
	push	ax
	call	FUN_1000_1C22
; Line 367
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 368
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
; Line 369
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 370
	mov	WORD PTR [bp-4],13	;local_4
; Line 371
	mov	si,13
$L20000:
; Line 372
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 373
	dec	si
	jne	$L20000
; Line 374
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 375
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 376
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 377
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 378
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 379
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 380
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 381
	mov	WORD PTR [bp-4],si	;local_4
; Line 382
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 383
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 384
	mov	WORD PTR [bp-4],13	;local_4
; Line 385
	mov	si,13
$L20003:
; Line 386
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 387
	dec	si
	jne	$L20003
; Line 388
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 389
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

F_ZSTATS_045E	ENDP
; Line 394
	PUBLIC	F_ZSTATS_0518
F_ZSTATS_0518	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 395
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 402
	mov	bx,ax
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	cmp	ax,WORD PTR [bp+4]	;param_1
	je	$L20006
	mov	al,BYTE PTR [bx+26]
	cmp	ax,WORD PTR [bp+4]	;param_1
	je	$L20006
	mov	al,BYTE PTR [bx+27]
	cmp	ax,WORD PTR [bp+4]	;param_1
	je	$L20006
	mov	al,BYTE PTR [bx+28]
	cmp	ax,WORD PTR [bp+4]	;param_1
	je	$L20006
	mov	al,BYTE PTR [bx+29]
	cmp	ax,WORD PTR [bp+4]	;param_1
	je	$L20006
	mov	al,BYTE PTR [bx+30]
	cmp	ax,WORD PTR [bp+4]	;param_1
	jne	$L20004
$L20006:
	mov	ax,1
	jmp	SHORT $EX349
	nop	
$L20004:
	sub	ax,ax
$EX349:
	mov	sp,bp
	pop	bp
	ret	4

F_ZSTATS_0518	ENDP
; Line 408
	PUBLIC	F_ZSTATS_056C
F_ZSTATS_056C	PROC NEAR
	push	bp
	mov	bp,sp
	push	di
	push	si
;	param_3 = 10
;	notused = 8
;	param_2 = 6
;	param_1 = 4
; Line 409
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC358:
; Line 410
	dec	si
	js	$L20012
; Line 411
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I361
; Line 412
	cmp	di,255
	je	$FC358
; Line 413
	push	di
	push	si
	call	F_ZSTATS_0518
	or	ax,ax
	je	$FC358
; Line 415
; Line 418
$I361:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX356
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 424
	mov	ax,-1
$EX356:
	pop	si
	pop	di
	pop	bp
	ret	8

F_ZSTATS_056C	ENDP
; Line 430
	PUBLIC	F_ZSTATS_05A4
F_ZSTATS_05A4	PROC NEAR
	push	bp
	mov	bp,sp
	push	di
	push	si
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
; Line 431
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC371:
; Line 432
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 433
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I374
; Line 434
	cmp	di,255
	je	$FC371
; Line 435
	push	di
	push	si
	call	F_ZSTATS_0518
	or	ax,ax
	je	$FC371
; Line 437
; Line 440
$I374:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX369
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 446
	mov	ax,-1
$EX369:
	pop	si
	pop	di
	pop	bp
	ret	8

F_ZSTATS_05A4	ENDP
; Line 452
	PUBLIC	F_ZSTATS_05E2
F_ZSTATS_05E2	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	di
	push	si
;	local_4 = -4
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
;	local_6 = -2
; Line 456
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 457
	cmp	al,255
	je	$I385
; Line 458
	or	al,al
	je	$I386
; Line 459
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 460
	jmp	SHORT $I387
	nop	
$I386:
; Line 461
	push	WORD PTR TEXT_9778
	call	FUN_1000_1850
; Line 462
$I387:
; Line 463
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I388
; Line 464
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 465
; Line 466
$I388:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 467
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 468
; Line 470
$I385:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I390
; Line 471
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 472
	push	WORD PTR TEXT_977C
	call	FUN_1000_1850
; Line 473
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 474
$L20045:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 475
	jmp	SHORT $I395
$I390:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I392
; Line 476
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 477
	push	WORD PTR TEXT_9782
	call	FUN_1000_1850
; Line 478
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 479
	mov	ax,WORD PTR [bp+10]	;param_4
	add	ax,WORD PTR D_19B2
	push	ax
	jmp	SHORT $L20046
	nop	
$I392:
; Line 480
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I394
; Line 481
	push	WORD PTR TEXT_9788
	call	FUN_1000_1850
; Line 482
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 483
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20045
$I394:
; Line 485
; Line 486
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20046:
	call	FUN_1000_1850
; Line 487
$I395:
; Line 490
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 491
	cmp	ax,14
	jge	$I397
;	register si = si
; Line 492
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 493
	add	WORD PTR [bp-4],si	;local_4
; Line 495
$D399:
; Line 496
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 497
	dec	si
; Line 498
	jne	$D399
; Line 499
; Line 500
$I397:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 501
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

F_ZSTATS_05E2	ENDP
; Line 508
	PUBLIC	F_ZSTATS_06E8
F_ZSTATS_06E8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,18
	push	di
	push	si
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
;	local_10 = -8
;	local_e = -14
;	local_c = -10
;	local_a = -6
;	local_8 = -4
;	local_6 = -2
;	local_4 = -12
; Line 517
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 518
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 519
	mov	WORD PTR [bp-4],0	;local_8
; Line 520
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 521
	cmp	ax,-1
	je	$JCC1821
	jmp	$I478
$JCC1821:
; Line 522
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 523
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 524
	push	WORD PTR TEXT_9794
	call	FUN_1000_1850
; Line 525
	call	FUN_1000_4DAA
; Line 526
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 527
	call	FUN_1000_266C
	jmp	$EX407
	nop	
$FC420:
; Line 531
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 532
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 536
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20047
$FC423:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
$L20047:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB424
; Line 538
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	F_ZSTATS_05E2
; Line 540
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 541
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC423
; Line 542
$FB424:
; Line 546
	mov	WORD PTR [bp-8],0	;local_10
; Line 547
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I426
; Line 548
	mov	WORD PTR [bp-8],2	;local_10
; Line 549
; Line 552
$I426:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I427
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I427
; Line 553
	inc	WORD PTR [bp-8]	;local_10
; Line 554
; Line 557
$I427:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC432
	cmp	ax,1
	je	$SC433
	cmp	ax,2
	je	$SC435
	cmp	ax,3
	je	$SC436
	jmp	SHORT $SB429
$SC432:
; Line 559
	call	FUN_1000_4DAA
; Line 561
$SB429:
; Line 575
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 576
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 577
	cmp	ax,32
	jne	$I437
	jmp	$L20051
$SC433:
; Line 563
	mov	ax,25
$L20048:
	push	ax
	call	FUN_1000_4DEA
; Line 565
	jmp	SHORT $SB429
	nop	
$SC435:
; Line 567
	mov	ax,24
	jmp	SHORT $L20048
	nop	
$SC436:
; Line 570
	mov	ax,18
	jmp	SHORT $L20048
	nop	
$I437:
; Line 581
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2076
	jmp	$I439
$JCC2076:
; Line 583
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I440
; Line 585
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I441
; Line 586
	mov	WORD PTR [bp-12],7	;local_4
; Line 587
	jmp	SHORT $I442
	nop	
$I441:
; Line 589
	mov	WORD PTR [bp-12],1	;local_4
; Line 590
$I442:
; Line 592
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2116
	jmp	$I478
$JCC2116:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 593
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I446
; Line 594
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	si,ax
; Line 595
; Line 596
$I446:
	dec	di
	jne	$L20016
$L20055:
	mov	WORD PTR [bp-2],si	;local_6
; Line 597
	jmp	$I478
$I440:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I447
; Line 601
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2184
	jmp	$I478
$JCC2184:
; Line 603
	cmp	WORD PTR [bp-14],2	;local_e
$L20053:
	jle	$JCC2193
	jmp	$I478
$JCC2193:
; Line 605
$L20051:
	mov	WORD PTR [bp-4],1	;local_8
; Line 606
	jmp	$I478
$I447:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I450
; Line 615
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I451
; Line 616
	mov	WORD PTR [bp-12],7	;local_4
; Line 617
	jmp	SHORT $I452
$I451:
; Line 618
	mov	WORD PTR [bp-12],1	;local_4
; Line 619
$I452:
; Line 621
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2240
	jmp	$I478
$JCC2240:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 622
	cmp	si,-1
	je	$I456
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I456
; Line 623
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 624
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	si,ax
; Line 625
; Line 626
$I456:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20056:
	mov	WORD PTR [bp-10],si	;local_c
; Line 627
	jmp	$I478
$I450:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2326
	jmp	$I478
$JCC2326:
	jmp	$L20051
$I439:
; Line 636
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I459
; Line 638
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 639
	jmp	$I478
$I459:
; Line 640
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I461
; Line 641
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2375
	jmp	$I478
$JCC2375:
; Line 642
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20053
	nop	
$I461:
; Line 650
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I465
; Line 652
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	di,ax
; Line 653
	sub	si,si
; Line 655
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$L20021
; Line 657
	mov	di,WORD PTR [bp-10]	;local_c
; Line 658
	inc	si
; Line 659
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 660
	jmp	$I478
$I465:
; Line 661
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I470
; Line 664
	jne	$I471
; Line 665
	mov	WORD PTR [bp-12],7	;local_4
; Line 666
	jmp	SHORT $I472
$I471:
; Line 668
	mov	WORD PTR [bp-12],1	;local_4
; Line 669
$I472:
; Line 671
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2480
	jmp	$I478
$JCC2480:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 672
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I476
; Line 673
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	si,ax
; Line 674
; Line 675
$I476:
	dec	di
	jne	$L20022
	jmp	$L20055
	nop	
$I470:
; Line 677
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I478
; Line 680
	jne	$I479
; Line 681
	mov	WORD PTR [bp-12],7	;local_4
; Line 682
	jmp	SHORT $I480
$I479:
; Line 683
	mov	WORD PTR [bp-12],1	;local_4
; Line 684
$I480:
; Line 685
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I478
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 686
	cmp	si,-1
	je	$I484
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I484
; Line 687
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 688
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	si,ax
; Line 689
; Line 690
$I484:
	dec	WORD PTR [bp-18]
	jne	$L20024
	jmp	$L20056
$I478:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2646
	jmp	$FC420
$JCC2646:
; Line 696
; Line 698
	mov	ax,WORD PTR [bp-14]	;local_e
$EX407:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

F_ZSTATS_06E8	ENDP
; Line 704
	PUBLIC	F_ZSTATS_099A
F_ZSTATS_099A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 707
	sub	si,si
; Line 708
$D488:
; Line 709
	mov	al,BYTE PTR UNK_0000_5820[si]
	mov	BYTE PTR UNK_0000_B9EE[si],al
; Line 710
	mov	al,BYTE PTR UNK_0000_5828[si]
	mov	BYTE PTR UNK_0000_B9F6[si],al
; Line 711
	mov	al,BYTE PTR UNK_0000_5840[si]
	cbw	
	cmp	ax,255
	jne	$L20026
	mov	al,255
	jmp	SHORT $L20027
$L20026:
	sub	al,al
$L20027:
	mov	BYTE PTR UNK_0000_BA03[si],al
; Line 712
	inc	si
	cmp	si,8
	jl	$D488
	mov	WORD PTR [bp-2],si	;local_4
; Line 714
	mov	al,UNK_0000_57B0
	mov	UNK_0000_B9FE,al
; Line 715
	mov	al,UNK_0000_57B1
	mov	UNK_0000_B9FF,al
; Line 716
	mov	al,UNK_0000_57B3
	mov	UNK_0000_BA00,al
; Line 717
	mov	al,UNK_0000_57B4
	mov	UNK_0000_BA01,al
; Line 718
	mov	al,UNK_0000_57B5
	mov	UNK_0000_BA02,al
; Line 720
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET UNK_0000_BA0B
	mov	si,OFFSET UNK_0000_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 724
	mov	al,UNK_0000_57BA
	mov	UNK_0000_BA0E,al
; Line 725
	cmp	BYTE PTR UNK_0000_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	UNK_0000_BA0F,al
; Line 726
	mov	al,UNK_0000_57BC
	mov	UNK_0000_BA10,al
; Line 727
	mov	al,UNK_0000_57BD
	mov	UNK_0000_BA11,al
; Line 728
	mov	al,UNK_0000_57BE
	mov	UNK_0000_BA12,al
; Line 729
	mov	al,UNK_0000_57BF
	mov	UNK_0000_BA13,al
; Line 730
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_099A	ENDP
; Line 735
	PUBLIC	F_ZSTATS_0A3A
F_ZSTATS_0A3A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 740
	mov	ax,1
	push	ax
	call	F_ZSTATS_0000
	mov	WORD PTR [bp-4],ax	;local_8
; Line 741
	cmp	ax,-2
	jne	$I499
; Line 742
	mov	WORD PTR [bp-4],6	;local_8
; Line 743
	jmp	SHORT $I500
	nop	
$I499:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2858
	jmp	$EX495
$JCC2858:
; Line 744
$I500:
	push	WORD PTR TEXT_97A2
	call	FUN_1000_1850
; Line 748
	call	F_ZSTATS_099A
; Line 749
	call	FUN_1000_4EFC
; Line 750
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 751
	mov	BYTE PTR [bp-2],0	;local_6
; Line 754
$D503:
; Line 755
; Line 756
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2892
	jmp	$I509
$JCC2892:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2901
	jmp	$I509
$JCC2901:
; Line 757
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I511
	cmp	al,1
	jne	$I510
$I511:
; Line 758
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I512
; Line 759
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20058:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 760
; Line 761
	jmp	SHORT $I526
	nop	
$I512:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I514
; Line 762
	mov	WORD PTR [bp-6],16	;local_4
; Line 763
; Line 764
	jmp	SHORT $I526
	nop	
$I514:
; Line 765
	dec	WORD PTR [bp-6]	;local_4
; Line 766
; Line 767
	jmp	SHORT $I526
	nop	
$I510:
; Line 768
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I518
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I517
$I518:
; Line 769
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I524
; Line 770
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I520
; Line 771
	inc	WORD PTR [bp-6]	;local_4
; Line 772
	jmp	SHORT $I526
$I520:
; Line 773
	mov	WORD PTR [bp-6],0	;local_4
; Line 774
; Line 775
	jmp	SHORT $I526
	nop	
$I517:
; Line 777
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I524
; Line 778
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I524
; Line 779
	jbe	$I526
	cmp	BYTE PTR [bp-2],55	;local_6
	jae	$I526
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	mov	si,ax
	lea	ax,WORD PTR [si-49]
	mov	bx,22619
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	cmp	ax,cx
	jae	$I526
; Line 780
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20058
$I524:
; Line 785
	mov	WORD PTR [bp-6],12	;local_4
; Line 786
; Line 787
$I526:
; Line 795
; Line 798
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 799
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I530
; Line 800
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I531
; Line 801
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	F_ZSTATS_0082
; Line 802
	jmp	SHORT $L20057
	nop	
$I509:
; Line 787
; Line 788
	call	FUN_1000_4DAA
; Line 789
	call	FUN_1000_4E20
; Line 790
	call	FUN_1000_4F3C
; Line 791
	call	FUN_1000_2900
; Line 792
	push	WORD PTR TEXT_97CE
	call	FUN_1000_1850
; Line 793
	jmp	$EX495
$I531:
; Line 802
; Line 803
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	F_ZSTATS_02A8
; Line 804
	jmp	SHORT $L20057
	nop	
$I530:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I533
; Line 812
	call	F_ZSTATS_039C
; Line 815
$L20057:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 816
	call	FUN_1000_266C
	jmp	SHORT $L20061
	nop	
$I533:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I534
; Line 822
	mov	ax,OFFSET TEXT_97AC
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET DAT_0000_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20063
	nop	
$I534:
; Line 823
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I536
; Line 824
	mov	ax,OFFSET TEXT_97B6
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20063
	nop	
$I536:
; Line 825
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I538
; Line 826
	mov	ax,OFFSET TEXT_97BE
	push	ax
	mov	ax,38
	push	ax
	mov	ax,OFFSET UNK_0000_B9EE
	push	ax
	mov	ax,OFFSET D_1916
$L20063:
	push	ax
	call	F_ZSTATS_06E8
$L20061:
	mov	BYTE PTR [bp-2],al	;local_6
; Line 827
	jmp	$D503
	nop	
$I538:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3234
	jmp	$D503
$JCC3234:
; Line 828
	mov	ax,OFFSET TEXT_97C4
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20063
$EX495:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_0A3A	ENDP
; Line 836
	PUBLIC	F_ZSTATS_0BEE
F_ZSTATS_0BEE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 837
	push	WORD PTR TEXT_97D4
	call	FUN_1000_1850
; Line 838
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850
; Line 839
	push	WORD PTR TEXT_97D8
	call	FUN_1000_1850
; Line 840
	pop	bp
	ret	2
	nop	

F_ZSTATS_0BEE	ENDP
; Line 845
	PUBLIC	F_ZSTATS_0C0A
F_ZSTATS_0C0A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 846
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-2],ax	;s
; Line 848
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I548
	cmp	BYTE PTR [bx+28],255
	jne	$I548
; Line 849
	mov	ax,2
	jmp	SHORT $EX546
	nop	
$I548:
; Line 850
	cmp	BYTE PTR [bx+27],255
	jne	$I550
; Line 851
	sub	ax,ax
	jmp	SHORT $EX546
$I550:
; Line 852
	cmp	BYTE PTR [bx+28],255
	jne	$I552
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	BYTE PTR D_1A7E[bx],48
	je	$I552
; Line 853
	mov	ax,1
	jmp	SHORT $EX546
	nop	
$I552:
; Line 854
; Line 855
	mov	ax,255
$EX546:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0C0A	ENDP
; Line 864
	PUBLIC	F_ZSTATS_0C5C
F_ZSTATS_0C5C	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,16
	push	si
;	param_2 = 6
;	param_1 = 4
;	local_10 = -8
;	local_e = -14
;	local_c = -10
;	local_a = -6
;	local_8 = -4
;	local_6 = -2
;	local_4 = -12
; Line 874
	cmp	BYTE PTR DAT_5893,127
	jbe	$I565
; Line 875
	mov	bl,UNK_0000_589E
	sub	bh,bh
	mov	cl,3
	shl	bx,cl
	mov	al,BYTE PTR UNK_0000_BA18[bx]
	sub	ah,ah
	shl	ax,cl
	add	ax,OFFSET UNK_0000_5C5A
	mov	WORD PTR [bp-2],ax	;local_6
; Line 876
; Line 880
$I565:
	cmp	WORD PTR [bp+4],27	;param_1
	je	$I567
	cmp	WORD PTR [bp+4],29	;param_1
	jne	$I566
$I567:
; Line 881
	sub	ax,ax
	jmp	$EX557
	nop	
$I566:
	cmp	WORD PTR [bp+4],9	;param_1
	jl	$I568
	cmp	WORD PTR [bp+4],15	;param_1
	jg	$I568
	cmp	BYTE PTR DAT_5893,127
	jbe	$I568
	cmp	BYTE PTR DAT_58A3,0
	jne	$I568
; Line 886
	push	WORD PTR TEXT_97E2
$L20086:
	call	F_ZSTATS_0BEE
	jmp	SHORT $I567
	nop	
$I568:
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	F_ZSTATS_0518
	or	ax,ax
	je	$I569
; Line 892
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_6E60
; Line 893
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR DAT_0000_57C0[bx],99
	jge	$I571
; Line 894
	inc	BYTE PTR DAT_0000_57C0[bx]
; Line 895
; Line 897
$I571:
	cmp	BYTE PTR DAT_5893,127
	jbe	$I567
	cmp	bx,42
	jne	$I567
	mov	ax,OFFSET TEXT_9812
	push	ax
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	al,[bx+10][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-4],ax	;local_8
; Line 905
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	si,ax
	mov	al,BYTE PTR D_1ADE[si]
	mov	BYTE PTR [bx+1],al
	mov	BYTE PTR [bx],al
	jmp	$I567
$I569:
; Line 909
	cmp	WORD PTR [bp+4],26	;param_1
	je	$I577
	cmp	WORD PTR [bp+4],36	;param_1
	jne	$I576
$I577:
	cmp	BYTE PTR UNK_0000_57DB,0
	je	$I575
$I576:
	cmp	WORD PTR [bp+4],28	;param_1
	jne	$I574
	cmp	BYTE PTR UNK_0000_57DD,0
	jne	$I574
$I575:
; Line 911
	push	WORD PTR TEXT_981C
	jmp	$L20086
	nop	
$I574:
	sub	dx,dx
; Line 918
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	add	si,DAT_55A8
	add	si,25
; Line 923
	mov	WORD PTR [bp-6],6	;local_a
	mov	WORD PTR [bp-16],6
	mov	cx,WORD PTR [bp-16]
$L20033:
; Line 924
	cmp	BYTE PTR [si],255
	je	$I581
; Line 925
	mov	bl,BYTE PTR [si]
	sub	bh,bh
	mov	al,BYTE PTR D_1AAE[bx]
	sub	ah,ah
	add	dx,ax
; Line 926
; Line 928
$I581:
	inc	si
; Line 929
	loop	$L20033
	mov	WORD PTR [bp-8],si	;local_10
	mov	WORD PTR [bp-12],dx	;local_4
; Line 932
	mov	bx,WORD PTR [bp+4]	;param_1
	mov	al,BYTE PTR D_1AAE[bx]
	sub	ah,ah
	add	ax,dx
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	cl,[bx+12][si]
	sub	ch,ch
	cmp	ax,cx
	ja	$L20035
	mov	ax,1
	jmp	SHORT $L20036
	nop	
$L20035:
	sub	ax,ax
$L20036:
	mov	WORD PTR [bp-14],ax	;local_e
; Line 935
	mov	bx,WORD PTR [bp+4]	;param_1
	mov	al,BYTE PTR D_1A7E[bx]
	sub	ah,ah
	cmp	ax,2
	je	$SC586
	cmp	ax,4
	je	$SC588
	cmp	ax,32
	jne	$JCC3717
	jmp	$SC590
$JCC3717:
	cmp	ax,48
	jne	$JCC3725
	jmp	$SC593
$JCC3725:
	cmp	ax,64
	jne	$JCC3733
	jmp	$SC595
$JCC3733:
	cmp	ax,128
	jne	$JCC3741
	jmp	$SC597
$JCC3741:
	jmp	SHORT $SB583
	nop	
	nop	
$SC586:
; Line 939
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	al,[bx+29][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I587
; Line 940
	push	WORD PTR TEXT_9916
	jmp	$L20086
$I587:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,29
$L20081:
	mov	WORD PTR [bp-8],ax	;local_10
; Line 945
$SB583:
; Line 1000
	cmp	WORD PTR [bp-14],0	;local_e
	je	$JCC3797
	jmp	$I599
$JCC3797:
; Line 1002
	push	WORD PTR TEXT_9942
	jmp	$L20086
	nop	
$SC588:
; Line 948
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	al,[bx+30][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I589
; Line 949
	push	WORD PTR TEXT_98F0
	jmp	$L20086
$I589:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,30
	jmp	SHORT $L20081
$SC590:
; Line 957
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_0C0A
	mov	WORD PTR [bp-10],ax	;local_c
; Line 958
	cmp	ax,255
	jne	$I591
; Line 959
	push	WORD PTR TEXT_9892
	jmp	$L20086
	nop	
$I591:
	cmp	WORD PTR [bp-10],2	;local_c
	jne	$I592
; Line 964
	mov	WORD PTR [bp-10],0	;local_c
; Line 965
; Line 967
$I592:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,WORD PTR [bp-10]	;local_c
$L20094:
	add	ax,DAT_55A8
	add	ax,27
	jmp	SHORT $L20081
$SC593:
; Line 971
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_0C0A
	mov	WORD PTR [bp-10],ax	;local_c
; Line 972
	cmp	ax,2
	je	$I594
; Line 973
	push	WORD PTR TEXT_98BA
	jmp	$L20086
	nop	
$I594:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	jmp	SHORT $L20094
	nop	
$SC595:
; Line 981
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	cmp	BYTE PTR [bx+26][si],255
	je	$I596
; Line 982
	push	WORD PTR TEXT_9866
	jmp	$L20086
$I596:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,26
	jmp	$L20081
	nop	
$SC597:
; Line 990
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	cmp	BYTE PTR [bx+25][si],255
	je	$I598
; Line 991
	push	WORD PTR TEXT_9846
	jmp	$L20086
$I598:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,25
	jmp	$L20081
	nop	
$I599:
; Line 1004
; Line 1006
	mov	bx,WORD PTR [bp-8]	;local_10
	mov	al,BYTE PTR [bp+4]	;param_1
	mov	BYTE PTR [bx],al
; Line 1007
	mov	bx,WORD PTR [bp+4]	;param_1
	dec	BYTE PTR DAT_0000_57C0[bx]
; Line 1008
	cmp	BYTE PTR DAT_0000_57C0[bx],42
	je	$I603
	cmp	BYTE PTR DAT_0000_57C0[bx],44
	jne	$I602
$I603:
	sub	ax,ax
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_2092
	or	ax,ax
	jne	$I602
; Line 1010
	push	WORD PTR TEXT_995E
	call	FUN_1000_1850
; Line 1011
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	BYTE PTR [bx+29][si],255
; Line 1012
	mov	ax,1200
	push	ax
	mov	ax,2000
	push	ax
	mov	ax,1
	push	ax
	mov	ax,40
	push	ax
	call	FUN_1000_43AE
; Line 1013
	mov	ax,1
	jmp	SHORT $EX557
	nop	
$I602:
; Line 1014
; Line 1016
	cmp	WORD PTR [bp+4],42	;param_1
	je	$JCC4110
	jmp	$I567
$JCC4110:
	cmp	BYTE PTR DAT_5893,127
	ja	$JCC4120
	jmp	$I567
$JCC4120:
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	BYTE PTR [bx+1],29
; Line 1029
	mov	BYTE PTR [bx],29
	jmp	$I567
$EX557:
	pop	si
	mov	sp,bp
	pop	bp
	ret	4
	nop	

F_ZSTATS_0C5C	ENDP
; Line 1038
	PUBLIC	F_ZSTATS_0F2E
F_ZSTATS_0F2E	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,32
	push	di
	push	si
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
;	local_1e = -4
;	local_1c = -24
;	local_1a = -16
;	local_18 = -10
;	local_16 = -6
;	local_14 = -28
;	local_12 = -20
;	local_10 = -14
;	local_e = -26
;	local_c = -18
;	local_a = -12
;	local_8 = -8
;	local_6 = -2
;	local_4 = -22
; Line 1055
	mov	WORD PTR [bp-8],0	;local_8
; Line 1056
	mov	WORD PTR [bp-14],1	;local_10
; Line 1057
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I627
; Line 1058
	mov	WORD PTR [bp-28],22464	;local_14
; Line 1059
	mov	WORD PTR [bp-12],48	;local_a
; Line 1060
	jmp	SHORT $I628
$I627:
; Line 1061
	mov	WORD PTR [bp-28],-17938	;local_14
; Line 1062
	mov	WORD PTR [bp-12],38	;local_a
; Line 1063
$I628:
; Line 1066
	cmp	WORD PTR [bp-8],0	;local_8
	je	$I629
; Line 1067
	mov	ax,WORD PTR [bp-16]	;local_1a
	jmp	$EX612
$I629:
; Line 1071
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 1072
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 1073
	mov	WORD PTR [bp-22],0	;local_4
; Line 1074
	mov	ax,WORD PTR [bp+8]	;param_3
$L20097:
	mov	WORD PTR [bp-20],ax	;local_12
; Line 1077
; Line 1078
	cmp	ax,-1
	jne	$I636
; Line 1080
	mov	WORD PTR [bp-10],0	;local_18
; Line 1081
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	add	ax,1
	je	$I637
; Line 1082
	mov	WORD PTR [bp-10],2	;local_18
; Line 1083
; Line 1085
$I637:
	cmp	WORD PTR [bp-20],-1	;local_12
	je	$I639
; Line 1086
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	add	ax,1
$L20101:
	je	$I639
; Line 1087
	inc	WORD PTR [bp-10]	;local_18
; Line 1088
; Line 1089
$I639:
; Line 1150
	cmp	WORD PTR [bp-10],0	;local_18
	jne	$JCC4298
	jmp	$I652
$JCC4298:
; Line 1151
	cmp	WORD PTR [bp-10],1	;local_18
	je	$JCC4307
	jmp	$I653
$JCC4307:
; Line 1153
	mov	ax,25
	jmp	$L20099
$I636:
; Line 1092
; Line 1094
	inc	WORD PTR [bp-22]	;local_4
; Line 1095
	call	FUN_1000_1CEE
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I641
; Line 1096
	mov	ax,253
	push	ax
	call	FUN_1000_16BA
; Line 1097
	mov	ax,WORD PTR [bp-20]	;local_12
	mov	WORD PTR [bp-16],ax	;local_1a
; Line 1098
; Line 1101
$I641:
	cmp	WORD PTR [bp+4],82	;param_1
	je	$I642
; Line 1103
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6422
	push	ax
	mov	ax,32
	push	ax
	jmp	SHORT $L20096
$I642:
; Line 1104
; Line 1106
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-20]	;local_12
	call	F_ZSTATS_0518
	or	ax,ax
	je	$I644
; Line 1108
	mov	bx,WORD PTR [bp-20]	;local_12
	mov	al,BYTE PTR D_1AE8[bx]
	sub	ah,ah
	mov	WORD PTR [bp-18],ax	;local_c
; Line 1109
	jmp	SHORT $I645
	nop	
$I644:
; Line 1111
	mov	WORD PTR [bp-18],32	;local_c
; Line 1112
$I645:
; Line 1114
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6498
	push	ax
	push	WORD PTR [bp-18]	;local_c
$L20096:
	call	F_ZSTATS_05E2
; Line 1115
; Line 1120
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 1121
	call	FUN_1000_1CEE
	dec	ax
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I646
; Line 1122
	mov	ax,253
	push	ax
	call	FUN_1000_16BA
; Line 1123
; Line 1126
$I646:
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$I647
; Line 1128
	mov	WORD PTR [bp-10],0	;local_18
; Line 1129
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	inc	ax
	je	$I648
; Line 1130
	mov	WORD PTR [bp-10],2	;local_18
; Line 1131
; Line 1133
$I648:
	cmp	WORD PTR [bp-20],-1	;local_12
	jne	$JCC4480
	jmp	$I639
$JCC4480:
; Line 1134
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	inc	ax
	jmp	$L20101
$I647:
; Line 1140
; Line 1142
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	jmp	$L20097
$I653:
; Line 1154
	cmp	WORD PTR [bp-10],2	;local_18
	jne	$I655
; Line 1156
	mov	ax,24
$L20099:
	push	ax
	call	FUN_1000_4DEA
; Line 1157
	jmp	SHORT $I658
	nop	
$I655:
	cmp	WORD PTR [bp-10],3	;local_18
	jne	$I658
; Line 1159
	mov	ax,18
	jmp	SHORT $L20099
	nop	
$I652:
; Line 1161
; Line 1163
	call	FUN_1000_4DAA
; Line 1164
$I658:
; Line 1168
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 1169
	call	FUN_1000_266C
	mov	WORD PTR [bp-6],ax	;local_16
; Line 1171
	cmp	ax,13
	jne	$JCC4569
	jmp	$SC695
$JCC4569:
	jle	$JCC4574
	jmp	$L20044
$JCC4574:
	cmp	ax,1
	je	$SC663
	cmp	ax,2
	je	$SC679
	cmp	ax,3
	je	$SC663
	cmp	ax,4
	jmp	$L20098
	nop	
	nop	
$SC663:
; Line 1178
	cmp	WORD PTR [bp-6],213	;local_16
	jne	$I664
; Line 1179
	mov	WORD PTR [bp-2],7	;local_6
; Line 1180
	jmp	SHORT $I665
$I664:
; Line 1181
	mov	WORD PTR [bp-2],1	;local_6
$I665:
; Line 1182
	mov	WORD PTR [bp-26],0	;local_e
; Line 1183
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4630
	jmp	$I628
$JCC4630:
; Line 1184
;	register si = si
;	register di = di
; Line 1188
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-24],ax	;local_1c
; Line 1189
	add	WORD PTR [bp-26],ax	;local_e
; Line 1190
	mov	di,WORD PTR [bp+8]	;param_3
; Line 1191
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1194
$D669:
; Line 1195
; Line 1196
	cmp	si,4
	je	$I673
	cmp	si,1
	jne	$I672
$I673:
; Line 1197
; Line 1199
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_056C
	inc	ax
	je	$I675
; Line 1200
; Line 1201
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_056C
	mov	di,ax
; Line 1202
; Line 1203
	jmp	SHORT $I678
	nop	
$I675:
; Line 1204
; Line 1206
	cmp	si,4
	jne	$I678
$I672:
; Line 1214
; Line 1216
	dec	si
; Line 1217
$I678:
; Line 1219
	dec	WORD PTR [bp-24]	;local_1c
	jne	$D669
; Line 1221
	mov	WORD PTR [bp+8],di	;param_3
; Line 1224
$L20106:
	mov	WORD PTR [bp-14],si	;local_10
; Line 1225
; Line 1226
	jmp	$I628
$SC679:
; Line 1233
	cmp	WORD PTR [bp-6],214	;local_16
	jne	$I680
; Line 1234
	mov	WORD PTR [bp-2],7	;local_6
; Line 1235
	jmp	SHORT $I681
$I680:
; Line 1236
	mov	WORD PTR [bp-2],1	;local_6
$I681:
; Line 1237
	mov	WORD PTR [bp-26],0	;local_e
; Line 1238
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4742
	jmp	$I628
$JCC4742:
; Line 1239
;	register si = si
;	register di = di
; Line 1243
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-4],ax	;local_1e
; Line 1244
	add	WORD PTR [bp-26],ax	;local_e
; Line 1245
	mov	di,WORD PTR [bp-20]	;local_12
; Line 1246
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1249
$D685:
; Line 1250
; Line 1251
	cmp	si,4
	je	$I689
	cmp	si,7
	je	$I689
	cmp	WORD PTR [bp-22],si	;local_4
	jge	$I688
$I689:
; Line 1252
; Line 1254
	mov	ax,di
	cmp	ax,-1
	je	$I691
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_05A4
	inc	ax
	je	$I691
; Line 1255
; Line 1256
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1257
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_05A4
	mov	di,ax
; Line 1258
; Line 1259
	jmp	SHORT $I694
	nop	
$I691:
; Line 1260
; Line 1262
	cmp	si,4
	jne	$I694
	cmp	WORD PTR [bp-22],4	;local_4
	jne	$I694
$I688:
; Line 1269
; Line 1271
	inc	si
; Line 1272
$I694:
; Line 1274
	dec	WORD PTR [bp-4]	;local_1e
	jne	$D685
; Line 1276
	mov	WORD PTR [bp-20],di	;local_12
	jmp	$L20106
	nop	
$SC695:
; Line 1287
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I696
; Line 1288
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-16]	;local_1a
	call	F_ZSTATS_0C5C
	mov	WORD PTR [bp-8],ax	;local_8
; Line 1289
	jmp	$I628
	nop	
$I696:
; Line 1291
	mov	WORD PTR [bp-8],1	;local_8
; Line 1292
; Line 1294
	jmp	$I628
$SC698:
; Line 1298
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$L20039
	mov	ax,TEXT_9970
	jmp	SHORT $L20040
	nop	
$L20039:
	mov	ax,TEXT_9976
$L20040:
	push	ax
	call	FUN_1000_1850
; Line 1299
	mov	WORD PTR [bp-8],1	;local_8
; Line 1300
	mov	WORD PTR [bp-16],-1	;local_1a
; Line 1303
	jmp	$I628
$SC699:
; Line 1308
	mov	ax,-1
	push	ax
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1309
	mov	WORD PTR [bp-14],1	;local_10
; Line 1311
	jmp	$I628
	nop	
$SC700:
; Line 1313
; Line 1317
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS_01E74C
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1319
	mov	di,1
; Line 1320
$D702:
; Line 1323
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS_01E74C
	mov	si,ax
; Line 1324
	cmp	si,-1
	jne	$I705
; Line 1325
; Line 1327
$L20105:
	mov	WORD PTR [bp-14],di	;local_10
	mov	WORD PTR [bp-16],si	;local_1a
	jmp	$I628
$I705:
	mov	WORD PTR [bp+8],si	;param_3
; Line 1332
	inc	di
; Line 1333
	cmp	di,7
	jl	$D702
	jmp	SHORT $L20105
	nop	
$L20044:
	cmp	ax,27
	jne	$JCC5017
	jmp	$SC698
$JCC5017:
	cmp	ax,32
	jne	$JCC5025
	jmp	$SC695
$JCC5025:
	cmp	ax,211
	je	$SC699
	cmp	ax,212
	je	$SC700
	cmp	ax,213
	jne	$JCC5043
	jmp	$SC663
$JCC5043:
	cmp	ax,214
$L20098:
	jne	$JCC5051
	jmp	$SC679
$JCC5051:
	jmp	$I628
	nop	
$EX612:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	6

F_ZSTATS_0F2E	ENDP
; Line 1346
	PUBLIC	F_ZSTATS_1296
F_ZSTATS_1296	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	local_6 = -2
;	local_4 = -4
; Line 1351
	sub	ax,ax
	push	ax
	call	F_ZSTATS_0000
	mov	WORD PTR [bp-2],ax	;local_6
; Line 1353
	or	ax,ax
	jl	$END711
; Line 1354
	mov	ax,-1
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_57C0
	push	ax
	push	WORD PTR [bp-2]	;local_6
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-4],ax	;local_4
; Line 1358
	cmp	ax,-1
	jne	$I712
; Line 1359
; Line 1360
	mov	ax,-26242
	push	ax
	call	SUB_0000_3670
; Line 1361
	jmp	SHORT $END711
$I712:
	mov	ax,-26216
	push	ax
	call	SUB_0000_3670
; Line 1365
	call	SUB_0000_6D1C
; Line 1366
	mov	ax,1
	push	ax
	call	SUB_0000_39B4
; Line 1368
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	push	ax
	call	SUB_0000_6C70
; Line 1370
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 1372
	push	WORD PTR [bp-4]	;local_4
	push	WORD PTR [bp-2]	;local_6
	mov	ax,82
	push	ax
	call	F_ZSTATS_0F2E
; Line 1374
	call	SUB_0000_6BCA
; Line 1375
	call	SUB_0000_6C40
; Line 1376
	call	SUB_0000_6D5C
; Line 1377
	call	SUB_0000_4720
; Line 1379
$END711:
; Line 1380
	mov	sp,bp
	pop	bp
	ret	

F_ZSTATS_1296	ENDP
_TEXT	ENDS
END
