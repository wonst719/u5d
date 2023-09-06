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
EXTRN	FUN_1000_1A3E:NEAR
EXTRN	FUN_1000_1C22:NEAR
EXTRN	FUN_1000_1CEE:NEAR
EXTRN	FUN_1000_1BF2:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	FUN_1000_4E20:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	FUN_1000_4F3C:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_2092:NEAR
EXTRN	FUN_1000_43AE:NEAR
EXTRN	FUN_1000_1B94:NEAR
EXTRN	FUN_1000_266C:NEAR
EXTRN	FUN_1000_1F12:NEAR
EXTRN	FUN_1000_4DEA:NEAR
EXTRN	FUN_ZSTATS__01E1E0:NEAR
EXTRN	FUN_1000_4EFC:NEAR
EXTRN	FUN_0000_8BCA:NEAR
EXTRN	FUN_1000_4D76:NEAR
EXTRN	FUN_1000_6E60:NEAR
EXTRN	UNK_0000_57DB:BYTE
EXTRN	UNK_0000_BA0F:BYTE
EXTRN	UNK_0000_57DD:BYTE
EXTRN	UNK_0000_BA10:BYTE
EXTRN	DAT_0000_58F0:BYTE
EXTRN	UNK_0000_BA11:BYTE
EXTRN	UNK_0000_5820:QWORD
EXTRN	UNK_0000_BA12:BYTE
EXTRN	UNK_0000_5828:QWORD
EXTRN	UNK_0000_BA13:BYTE
EXTRN	UNK_0000_5840:QWORD
EXTRN	D_BA16:BYTE
EXTRN	DAT_0000_5850:BYTE
EXTRN	UNK_0000_BA18:BYTE
EXTRN	UNK_0000_5893:BYTE
EXTRN	UNK_0000_589E:BYTE
EXTRN	UNK_0000_5C5A:BYTE
EXTRN	DAT_0000_96B4:WORD
EXTRN	DAT_0000_96BE:WORD
EXTRN	DAT_0000_96C6:WORD
EXTRN	DAT_0000_96D0:WORD
EXTRN	DAT_0000_96D6:WORD
EXTRN	DAT_0000_96DC:WORD
EXTRN	DAT_0000_96E2:WORD
EXTRN	DAT_0000_96E8:WORD
EXTRN	DAT_0000_96EE:WORD
EXTRN	DAT_0000_96F4:WORD
EXTRN	D_1916:BYTE
EXTRN	DAT_0000_96FA:WORD
EXTRN	D_1962:BYTE
EXTRN	DAT_0000_9700:WORD
_BSS      SEGMENT
COMM NEAR	D_19B2:	BYTE:	 2
EXTRN	DAT_0000_970E:WORD
EXTRN	D_19D2:BYTE
EXTRN	DAT_0000_9716:WORD
EXTRN	D_19E2:BYTE
EXTRN	DAT_0000_9724:WORD
EXTRN	D_1A44:BYTE
EXTRN	DAT_0000_972E:WORD
EXTRN	D_1A58:BYTE
EXTRN	DAT_0000_9738:WORD
EXTRN	D_1A6A:BYTE
EXTRN	DAT_0000_9742:WORD
EXTRN	D_1A7E:BYTE
EXTRN	DAT_0000_9752:WORD
EXTRN	D_1ADE:BYTE
EXTRN	DAT_0000_9760:WORD
EXTRN	D_1AAE:BYTE
EXTRN	DAT_0000_976E:WORD
EXTRN	DAT_0000_9778:WORD
EXTRN	DAT_0000_977C:WORD
EXTRN	DAT_0000_9782:WORD
EXTRN	DAT_0000_9788:WORD
EXTRN	DAT_0000_9794:WORD
EXTRN	DAT_0000_97A2:WORD
EXTRN	DAT_0000_97AC:WORD
EXTRN	DAT_0000_97B6:WORD
EXTRN	DAT_0000_97BE:WORD
EXTRN	DAT_0000_97C4:WORD
EXTRN	DAT_0000_97D4:WORD
EXTRN	DAT_0000_97D8:WORD
EXTRN	DAT_0000_97E2:WORD
EXTRN	DAT_0000_9812:WORD
EXTRN	D_55A8:WORD
EXTRN	DAT_0000_981C:WORD
EXTRN	UNK_0000_57A8:WORD
EXTRN	DAT_0000_9846:WORD
EXTRN	UNK_0000_57AA:WORD
EXTRN	DAT_0000_9866:WORD
EXTRN	UNK_0000_57AC:BYTE
EXTRN	DAT_0000_9892:WORD
EXTRN	UNK_0000_57AD:BYTE
EXTRN	DAT_0000_98BA:WORD
EXTRN	UNK_0000_57AE:BYTE
EXTRN	DAT_0000_98F0:WORD
EXTRN	UNK_0000_57AF:BYTE
EXTRN	DAT_0000_9916:WORD
EXTRN	UNK_0000_57B0:BYTE
EXTRN	DAT_0000_9942:WORD
EXTRN	UNK_0000_57B1:BYTE
EXTRN	DAT_0000_995E:WORD
EXTRN	UNK_0000_57B3:BYTE
EXTRN	UNK_0000_57B4:BYTE
EXTRN	UNK_0000_B9EE:QWORD
EXTRN	UNK_0000_57B5:BYTE
EXTRN	UNK_0000_B9F6:QWORD
EXTRN	UNK_0000_57B6:BYTE
EXTRN	UNK_0000_B9FE:BYTE
EXTRN	UNK_0000_57BA:BYTE
EXTRN	UNK_0000_B9FF:BYTE
EXTRN	UNK_0000_BA00:BYTE
EXTRN	UNK_0000_57BB:BYTE
EXTRN	UNK_0000_BA01:BYTE
EXTRN	UNK_0000_57BC:BYTE
EXTRN	UNK_0000_BA02:BYTE
EXTRN	UNK_0000_57BD:BYTE
EXTRN	UNK_0000_BA03:QWORD
EXTRN	UNK_0000_57BE:BYTE
EXTRN	UNK_0000_57BF:BYTE
EXTRN	UNK_0000_BA0B:BYTE
EXTRN	DAT_0000_57C0:BYTE
EXTRN	UNK_0000_BA0E:BYTE
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 181
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 186
	mov	WORD PTR [bp-4],-1	;local_4
; Line 188
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I291
; Line 189
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 190
	test	BYTE PTR D_BA16[si],128
	je	$I291
; Line 191
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 194
	jmp	SHORT $I297
$I291:
; Line 197
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 198
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 199
	or	ax,ax
	jl	$I297
; Line 200
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 201
	call	FUN_1000_1F12
	or	ax,ax
	je	$I297
; Line 202
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 203
; Line 204
$I297:
; Line 205
; Line 208
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I298
; Line 209
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 210
; Line 212
	jmp	SHORT $I300
	nop	
$I298:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I300
; Line 213
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 214
; Line 217
$I300:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 222
	PUBLIC	FUN_ZSTATS__01E262
FUN_ZSTATS__01E262	PROC NEAR
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
; Line 232
	call	FUN_0000_8BCA
; Line 234
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 236
	push	ax
	call	FUN_1000_4E50
; Line 237
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
; Line 238
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 239
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
; Line 241
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 242
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 243
	mov	WORD PTR [bp-4],0	;local_8
; Line 245
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I312
; Line 246
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 248
	sub	si,si
; Line 249
$FC314:
; Line 250
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 251
	inc	si
; Line 252
	cmp	WORD PTR [di],si
	jg	$FC314
; Line 253
; Line 256
	mov	WORD PTR [bp-4],si	;local_8
; Line 257
; Line 259
$I312:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 260
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 261
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 262
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 263
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 264
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
; Line 265
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 266
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 267
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 268
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
; Line 269
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 270
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 271
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 272
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 273
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 274
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 275
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 276
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 277
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 278
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 279
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 280
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 281
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 282
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 283
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 284
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 285
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 289
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 290
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I320
; Line 291
	sub	ax,ax
	jmp	SHORT $EX319
$I320:
; Line 292
; Line 293
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 294
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_1000_1850
; Line 295
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 296
	mov	ax,1
$EX319:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 302
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
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
	add	ax,D_55A8
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
	mov	ax,OFFSET DAT_0000_970E
	push	ax
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
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 319
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 320
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 321
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 322
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 323
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 325
	jne	$I327
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
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 329
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 330
; Line 332
$I327:
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

FUN_ZSTATS__01E488	ENDP
; Line 337
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 338
	call	FUN_1000_4DAA
; Line 339
	mov	ax,OFFSET DAT_0000_9724
	push	ax
	call	FUN_1000_4E50
; Line 340
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
; Line 341
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 342
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
; Line 343
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 344
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 345
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 346
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 347
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 348
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 349
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 350
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 351
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 352
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 353
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I330
; Line 354
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 355
; Line 356
$I330:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 360
	PUBLIC	FUN_ZSTATS__01E63E
FUN_ZSTATS__01E63E	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	param_1 = 4
;	register si = si
;	local_4 = -4
; Line 364
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
; Line 365
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 366
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
; Line 367
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 368
	mov	WORD PTR [bp-4],13	;local_4
; Line 369
	mov	si,13
$L20000:
; Line 370
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 371
	dec	si
	jne	$L20000
; Line 372
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 373
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 374
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 375
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 376
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 377
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 378
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 379
	mov	WORD PTR [bp-4],si	;local_4
; Line 380
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 381
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 382
	mov	WORD PTR [bp-4],13	;local_4
; Line 383
	mov	si,13
$L20003:
; Line 384
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 385
	dec	si
	jne	$L20003
; Line 386
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 387
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 391
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 392
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 399
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
	jmp	SHORT $EX348
	nop	
$L20004:
	sub	ax,ax
$EX348:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 404
	PUBLIC	FUN_ZSTATS__01E74C
FUN_ZSTATS__01E74C	PROC NEAR
	push	bp
	mov	bp,sp
	push	di
	push	si
;	param_3 = 10
;	notused = 8
;	param_2 = 6
;	param_1 = 4
; Line 405
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC357:
; Line 406
	dec	si
	js	$L20012
; Line 407
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I360
; Line 408
	cmp	di,255
	je	$FC357
; Line 409
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC357
; Line 411
; Line 414
$I360:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX355
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 420
	mov	ax,-1
$EX355:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 425
	PUBLIC	FUN_ZSTATS__01E784
FUN_ZSTATS__01E784	PROC NEAR
	push	bp
	mov	bp,sp
	push	di
	push	si
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
; Line 426
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC370:
; Line 427
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 428
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I373
; Line 429
	cmp	di,255
	je	$FC370
; Line 430
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC370
; Line 432
; Line 435
$I373:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX368
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 441
	mov	ax,-1
$EX368:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 446
	PUBLIC	FUN_ZSTATS__01E7C2
FUN_ZSTATS__01E7C2	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	di
	push	si
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
;	local_6 = -2
;	local_4 = -4
; Line 450
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 451
	cmp	al,255
	je	$I384
; Line 452
	or	al,al
	je	$I385
; Line 453
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 454
	jmp	SHORT $I386
	nop	
$I385:
; Line 455
	mov	ax,OFFSET DAT_0000_9778
	push	ax
	call	FUN_1000_1850
; Line 456
$I386:
; Line 457
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I387
; Line 458
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 459
; Line 460
$I387:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 461
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 462
; Line 464
$I384:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I389
; Line 465
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 466
	mov	ax,OFFSET DAT_0000_977C
	push	ax
	call	FUN_1000_1850
; Line 467
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 468
$L20037:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 469
	jmp	SHORT $I394
$I389:
	mov	si,WORD PTR [bp+10]	;param_4
	shl	si,1
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I391
; Line 470
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 471
	mov	ax,OFFSET DAT_0000_9782
	push	ax
	call	FUN_1000_1850
; Line 472
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 473
	mov	ax,WORD PTR D_19B2
	add	ax,si
	push	ax
	jmp	SHORT $L20038
	nop	
$I391:
; Line 474
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I393
; Line 475
	mov	ax,OFFSET DAT_0000_9788
	push	ax
	call	FUN_1000_1850
; Line 476
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 477
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20037
$I393:
; Line 479
; Line 480
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20038:
	call	FUN_1000_1850
; Line 481
$I394:
; Line 484
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 485
	cmp	ax,14
	jge	$I396
;	register si = si
; Line 486
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 487
	add	WORD PTR [bp-4],si	;local_4
; Line 489
$D398:
; Line 490
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 491
	dec	si
; Line 492
	jne	$D398
; Line 493
; Line 494
$I396:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 495
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
; Line 502
	PUBLIC	FUN_ZSTATS__01E8C8
FUN_ZSTATS__01E8C8	PROC NEAR
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
; Line 511
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 512
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 513
	mov	WORD PTR [bp-4],0	;local_8
; Line 514
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 515
	cmp	ax,-1
	je	$JCC1823
	jmp	$I477
$JCC1823:
; Line 516
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 517
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 518
	mov	ax,OFFSET DAT_0000_9794
	push	ax
	call	FUN_1000_1850
; Line 519
	call	FUN_1000_4DAA
; Line 520
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 521
	call	FUN_1000_266C
	jmp	$EX406
	nop	
$FC419:
; Line 525
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 526
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 530
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20039
$FC422:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
$L20039:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB423
; Line 532
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	FUN_ZSTATS__01E7C2
; Line 534
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 535
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC422
; Line 536
$FB423:
; Line 540
	mov	WORD PTR [bp-8],0	;local_10
; Line 541
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I425
; Line 542
	mov	WORD PTR [bp-8],2	;local_10
; Line 543
; Line 546
$I425:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I426
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I426
; Line 547
	inc	WORD PTR [bp-8]	;local_10
; Line 548
; Line 551
$I426:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC431
	cmp	ax,1
	je	$SC432
	cmp	ax,2
	je	$SC434
	cmp	ax,3
	je	$SC435
	jmp	SHORT $SB428
$SC431:
; Line 553
	call	FUN_1000_4DAA
; Line 555
$SB428:
; Line 569
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 570
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 571
	cmp	ax,32
	jne	$I436
	jmp	$L20043
$SC432:
; Line 557
	mov	ax,25
$L20040:
	push	ax
	call	FUN_1000_4DEA
; Line 559
	jmp	SHORT $SB428
	nop	
$SC434:
; Line 561
	mov	ax,24
	jmp	SHORT $L20040
	nop	
$SC435:
; Line 564
	mov	ax,18
	jmp	SHORT $L20040
	nop	
$I436:
; Line 575
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2078
	jmp	$I438
$JCC2078:
; Line 577
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I439
; Line 579
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I440
; Line 580
	mov	WORD PTR [bp-12],7	;local_4
; Line 581
	jmp	SHORT $I441
	nop	
$I440:
; Line 583
	mov	WORD PTR [bp-12],1	;local_4
; Line 584
$I441:
; Line 586
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2118
	jmp	$I477
$JCC2118:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 587
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I445
; Line 588
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 589
; Line 590
$I445:
	dec	di
	jne	$L20016
$L20047:
	mov	WORD PTR [bp-2],si	;local_6
; Line 591
	jmp	$I477
$I439:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I446
; Line 595
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2186
	jmp	$I477
$JCC2186:
; Line 597
	cmp	WORD PTR [bp-14],2	;local_e
$L20045:
	jle	$JCC2195
	jmp	$I477
$JCC2195:
; Line 599
$L20043:
	mov	WORD PTR [bp-4],1	;local_8
; Line 600
	jmp	$I477
$I446:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I449
; Line 609
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I450
; Line 610
	mov	WORD PTR [bp-12],7	;local_4
; Line 611
	jmp	SHORT $I451
$I450:
; Line 612
	mov	WORD PTR [bp-12],1	;local_4
; Line 613
$I451:
; Line 615
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2242
	jmp	$I477
$JCC2242:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 616
	cmp	si,-1
	je	$I455
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I455
; Line 617
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 618
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 619
; Line 620
$I455:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20048:
	mov	WORD PTR [bp-10],si	;local_c
; Line 621
	jmp	$I477
$I449:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2328
	jmp	$I477
$JCC2328:
	jmp	$L20043
$I438:
; Line 630
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I458
; Line 632
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 633
	jmp	$I477
$I458:
; Line 634
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I460
; Line 635
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2377
	jmp	$I477
$JCC2377:
; Line 636
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20045
	nop	
$I460:
; Line 644
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I464
; Line 646
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	di,ax
; Line 647
	sub	si,si
; Line 649
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$L20021
; Line 651
	mov	di,WORD PTR [bp-10]	;local_c
; Line 652
	inc	si
; Line 653
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 654
	jmp	$I477
$I464:
; Line 655
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I469
; Line 658
	jne	$I470
; Line 659
	mov	WORD PTR [bp-12],7	;local_4
; Line 660
	jmp	SHORT $I471
$I470:
; Line 662
	mov	WORD PTR [bp-12],1	;local_4
; Line 663
$I471:
; Line 665
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2482
	jmp	$I477
$JCC2482:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 666
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I475
; Line 667
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 668
; Line 669
$I475:
	dec	di
	jne	$L20022
	jmp	$L20047
	nop	
$I469:
; Line 671
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I477
; Line 674
	jne	$I478
; Line 675
	mov	WORD PTR [bp-12],7	;local_4
; Line 676
	jmp	SHORT $I479
$I478:
; Line 677
	mov	WORD PTR [bp-12],1	;local_4
; Line 678
$I479:
; Line 679
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I477
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 680
	cmp	si,-1
	je	$I483
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I483
; Line 681
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 682
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 683
; Line 684
$I483:
	dec	WORD PTR [bp-18]
	jne	$L20024
	jmp	$L20048
$I477:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2648
	jmp	$FC419
$JCC2648:
; Line 690
; Line 692
	mov	ax,WORD PTR [bp-14]	;local_e
$EX406:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E8C8	ENDP
; Line 697
	PUBLIC	FUN_ZSTATS__01EB7A
FUN_ZSTATS__01EB7A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 700
	sub	si,si
; Line 701
$D487:
; Line 702
	mov	al,BYTE PTR UNK_0000_5820[si]
	mov	BYTE PTR UNK_0000_B9EE[si],al
; Line 703
	mov	al,BYTE PTR UNK_0000_5828[si]
	mov	BYTE PTR UNK_0000_B9F6[si],al
; Line 704
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
; Line 705
	inc	si
	cmp	si,8
	jl	$D487
	mov	WORD PTR [bp-2],si	;local_4
; Line 707
	mov	al,UNK_0000_57B0
	mov	UNK_0000_B9FE,al
; Line 708
	mov	al,UNK_0000_57B1
	mov	UNK_0000_B9FF,al
; Line 709
	mov	al,UNK_0000_57B3
	mov	UNK_0000_BA00,al
; Line 710
	mov	al,UNK_0000_57B4
	mov	UNK_0000_BA01,al
; Line 711
	mov	al,UNK_0000_57B5
	mov	UNK_0000_BA02,al
; Line 713
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET UNK_0000_BA0B
	mov	si,OFFSET UNK_0000_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 717
	mov	al,UNK_0000_57BA
	mov	UNK_0000_BA0E,al
; Line 718
	cmp	BYTE PTR UNK_0000_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	UNK_0000_BA0F,al
; Line 719
	mov	al,UNK_0000_57BC
	mov	UNK_0000_BA10,al
; Line 720
	mov	al,UNK_0000_57BD
	mov	UNK_0000_BA11,al
; Line 721
	mov	al,UNK_0000_57BE
	mov	UNK_0000_BA12,al
; Line 722
	mov	al,UNK_0000_57BF
	mov	UNK_0000_BA13,al
; Line 723
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EB7A	ENDP
; Line 727
	PUBLIC	FUN_ZSTATS__01EC1A
FUN_ZSTATS__01EC1A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 732
	mov	ax,1
	push	ax
	call	FUN_ZSTATS__01E1E0
	mov	WORD PTR [bp-4],ax	;local_8
; Line 733
	cmp	ax,-2
	jne	$I499
; Line 734
	mov	WORD PTR [bp-4],6	;local_8
; Line 735
	jmp	SHORT $I500
	nop	
$I499:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2860
	jmp	$EX494
$JCC2860:
; Line 736
$I500:
	mov	ax,OFFSET DAT_0000_97A2
	push	ax
	call	FUN_1000_1850
; Line 740
	call	FUN_ZSTATS__01EB7A
; Line 741
	call	FUN_1000_4EFC
; Line 742
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 743
	mov	BYTE PTR [bp-2],0	;local_6
; Line 746
$D503:
; Line 747
; Line 748
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2894
	jmp	$I509
$JCC2894:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2903
	jmp	$I509
$JCC2903:
; Line 749
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I511
	cmp	al,1
	jne	$I510
$I511:
; Line 750
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I512
; Line 751
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20050:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 752
; Line 753
	jmp	SHORT $I526
	nop	
$I512:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I514
; Line 754
	mov	WORD PTR [bp-6],16	;local_4
; Line 755
; Line 756
	jmp	SHORT $I526
	nop	
$I514:
; Line 757
	dec	WORD PTR [bp-6]	;local_4
; Line 758
; Line 759
	jmp	SHORT $I526
	nop	
$I510:
; Line 760
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I518
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I517
$I518:
; Line 761
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I524
; Line 762
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I520
; Line 763
	inc	WORD PTR [bp-6]	;local_4
; Line 764
	jmp	SHORT $I526
$I520:
; Line 765
	mov	WORD PTR [bp-6],0	;local_4
; Line 766
; Line 767
	jmp	SHORT $I526
	nop	
$I517:
; Line 769
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I524
; Line 770
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I524
; Line 771
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
; Line 772
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20050
$I524:
; Line 777
	mov	WORD PTR [bp-6],12	;local_4
; Line 778
; Line 779
$I526:
; Line 787
; Line 790
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 791
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I530
; Line 792
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I531
; Line 793
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E262
; Line 794
	jmp	SHORT $L20049
	nop	
$I509:
; Line 779
; Line 780
	call	FUN_1000_4DAA
; Line 781
	call	FUN_1000_4E20
; Line 782
	call	FUN_1000_4F3C
; Line 783
	call	FUN_1000_2900
; Line 784
	mov	ax,-26674
	push	ax
	call	FUN_1000_1850
; Line 785
	jmp	$EX494
$I531:
; Line 794
; Line 795
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E488
; Line 796
	jmp	SHORT $L20049
	nop	
$I530:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I533
; Line 804
	call	FUN_ZSTATS__01E57C
; Line 807
$L20049:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 808
	call	FUN_1000_266C
	jmp	SHORT $L20053
	nop	
$I533:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I534
; Line 814
	mov	ax,OFFSET DAT_0000_97AC
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET DAT_0000_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20055
	nop	
$I534:
; Line 815
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I536
; Line 816
	mov	ax,OFFSET DAT_0000_97B6
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20055
	nop	
$I536:
; Line 817
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I538
; Line 818
	mov	ax,OFFSET DAT_0000_97BE
	push	ax
	mov	ax,38
	push	ax
	mov	ax,OFFSET UNK_0000_B9EE
	push	ax
	mov	ax,OFFSET D_1916
$L20055:
	push	ax
	call	FUN_ZSTATS__01E8C8
$L20053:
	mov	BYTE PTR [bp-2],al	;local_6
; Line 819
	jmp	$D503
	nop	
$I538:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3236
	jmp	$D503
$JCC3236:
; Line 820
	mov	ax,OFFSET DAT_0000_97C4
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20055
$EX494:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EC1A	ENDP
; Line 827
	PUBLIC	FUN_ZSTATS__01EDCE
FUN_ZSTATS__01EDCE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 828
	mov	ax,OFFSET DAT_0000_97D4
	push	ax
	call	FUN_1000_1850
; Line 829
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850
; Line 830
	mov	ax,OFFSET DAT_0000_97D8
	push	ax
	call	FUN_1000_1850
; Line 831
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDCE	ENDP
; Line 835
	PUBLIC	FUN_ZSTATS__01EDEA
FUN_ZSTATS__01EDEA	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 836
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;s
; Line 838
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I548
	cmp	BYTE PTR [bx+28],255
	jne	$I548
; Line 839
	mov	ax,2
	jmp	SHORT $EX546
	nop	
$I548:
; Line 840
	cmp	BYTE PTR [bx+27],255
	jne	$I550
; Line 841
	sub	ax,ax
	jmp	SHORT $EX546
$I550:
; Line 842
	cmp	BYTE PTR [bx+28],255
	jne	$I552
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	BYTE PTR D_1A7E[bx],48
	je	$I552
; Line 843
	mov	ax,1
	jmp	SHORT $EX546
	nop	
$I552:
; Line 844
; Line 845
	mov	ax,255
$EX546:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDEA	ENDP
; Line 850
	PUBLIC	FUN_ZSTATS__01EE3C
FUN_ZSTATS__01EE3C	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,16
	push	si
;	param_1 = 6
;	param_2 = 4
;	local_10 = -8
;	local_e = -14
;	local_c = -10
;	local_a = -6
;	local_8 = -4
;	local_6 = -2
;	local_4 = -12
; Line 859
	cmp	BYTE PTR UNK_0000_5893,127
	jbe	$I565
; Line 860
	mov	bl,UNK_0000_589E
	sub	bh,bh
	mov	cl,3
	shl	bx,cl
	mov	al,BYTE PTR UNK_0000_BA18[bx]
	sub	ah,ah
	shl	ax,cl
	add	ax,OFFSET UNK_0000_5C5A
	mov	WORD PTR [bp-2],ax	;local_6
; Line 861
; Line 864
$I565:
	cmp	WORD PTR [bp+6],27	;param_1
	je	$I567
	cmp	WORD PTR [bp+6],29	;param_1
	jne	$I566
$I567:
; Line 865
	sub	ax,ax
	jmp	$EX557
	nop	
$I566:
	cmp	WORD PTR [bp+6],9	;param_1
	jl	$I568
	cmp	WORD PTR [bp+6],15	;param_1
	jg	$I568
	cmp	BYTE PTR UNK_0000_5893,127
	jbe	$I568
	cmp	BYTE PTR UNK_0000_5893,0
	jne	$I568
; Line 869
	mov	ax,OFFSET DAT_0000_97E2
$L20077:
	push	ax
	call	FUN_ZSTATS__01EDCE
	jmp	SHORT $I567
	nop	
$I568:
	push	WORD PTR [bp+4]	;param_2
	push	WORD PTR [bp+6]	;param_1
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$I569
; Line 874
	push	WORD PTR [bp+4]	;param_2
	push	WORD PTR [bp+6]	;param_1
	call	FUN_1000_6E60
; Line 875
	mov	bx,WORD PTR [bp+6]	;param_1
	cmp	BYTE PTR DAT_0000_57C0[bx],99
	jge	$I571
; Line 876
	inc	BYTE PTR DAT_0000_57C0[bx]
; Line 877
; Line 879
$I571:
	cmp	BYTE PTR UNK_0000_5893,127
	jbe	$I567
	cmp	bx,42
	jne	$I567
	mov	ax,OFFSET DAT_0000_9812
	push	ax
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	al,[bx+10][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-4],ax	;local_8
; Line 887
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	si,ax
	mov	al,BYTE PTR D_1ADE[si]
	mov	BYTE PTR [bx+1],al
	mov	BYTE PTR [bx],al
	jmp	$I567
$I569:
; Line 891
	cmp	WORD PTR [bp+6],26	;param_1
	je	$I577
	cmp	WORD PTR [bp+6],36	;param_1
	jne	$I576
$I577:
	cmp	BYTE PTR UNK_0000_57DB,0
	je	$I575
$I576:
	cmp	WORD PTR [bp+6],28	;param_1
	jne	$I574
	cmp	BYTE PTR UNK_0000_57DD,0
	jne	$I574
$I575:
; Line 892
	mov	ax,OFFSET DAT_0000_981C
	jmp	$L20077
$I574:
	sub	dx,dx
; Line 898
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	add	si,D_55A8
	add	si,25
; Line 902
	mov	WORD PTR [bp-6],6	;local_a
	mov	WORD PTR [bp-16],6
	mov	cx,WORD PTR [bp-16]
$L20033:
; Line 903
	cmp	BYTE PTR [si],255
	je	$I581
; Line 904
	mov	bl,BYTE PTR [si]
	sub	bh,bh
	mov	al,BYTE PTR D_1AAE[bx]
	sub	ah,ah
	add	dx,ax
; Line 905
; Line 907
$I581:
	inc	si
; Line 908
	loop	$L20033
	mov	WORD PTR [bp-8],si	;local_10
	mov	WORD PTR [bp-12],dx	;local_4
; Line 910
	mov	bx,WORD PTR [bp+6]	;param_1
	mov	al,BYTE PTR D_1AAE[bx]
	sub	ah,ah
	add	ax,dx
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
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
; Line 913
	mov	bx,WORD PTR [bp+6]	;param_1
	mov	al,BYTE PTR D_1A7E[bx]
	sub	ah,ah
	cmp	ax,2
	je	$SC586
	cmp	ax,4
	je	$SC588
	cmp	ax,32
	je	$SC590
	cmp	ax,48
	jne	$JCC3722
	jmp	$SC593
$JCC3722:
	cmp	ax,64
	jne	$JCC3730
	jmp	$SC595
$JCC3730:
	cmp	ax,128
	jne	$JCC3738
	jmp	$SC597
$JCC3738:
	jmp	SHORT $SB583
	nop	
$SC586:
; Line 917
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	al,[bx+29][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I587
; Line 918
	mov	ax,OFFSET DAT_0000_9916
	jmp	$L20077
	nop	
$I587:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,29
$L20072:
	mov	WORD PTR [bp-8],ax	;local_10
; Line 923
$SB583:
; Line 980
	cmp	WORD PTR [bp-14],0	;local_e
	je	$JCC3793
	jmp	$I599
$JCC3793:
; Line 982
	mov	ax,OFFSET DAT_0000_9942
	jmp	$L20077
$SC588:
; Line 926
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	al,[bx+30][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I589
; Line 927
	mov	ax,OFFSET DAT_0000_98F0
	jmp	$L20077
	nop	
$I589:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,30
	jmp	SHORT $L20072
$SC590:
; Line 935
	push	WORD PTR [bp+4]	;param_2
	call	FUN_ZSTATS__01EDEA
	mov	WORD PTR [bp-10],ax	;local_c
; Line 936
	cmp	ax,255
	jne	$I591
; Line 937
	mov	ax,OFFSET DAT_0000_9892
	jmp	$L20077
$I591:
	cmp	WORD PTR [bp-10],2	;local_c
	jne	$I592
; Line 942
	mov	WORD PTR [bp-10],0	;local_c
; Line 943
; Line 947
$I592:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,WORD PTR [bp-10]	;local_c
$L20085:
	add	ax,D_55A8
	add	ax,27
	jmp	SHORT $L20072
$SC593:
; Line 951
	push	WORD PTR [bp+4]	;param_2
	call	FUN_ZSTATS__01EDEA
	mov	WORD PTR [bp-10],ax	;local_c
; Line 952
	cmp	ax,2
	je	$I594
; Line 953
	mov	ax,OFFSET DAT_0000_98BA
	jmp	$L20077
$I594:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	jmp	SHORT $L20085
	nop	
$SC595:
; Line 961
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	cmp	BYTE PTR [bx+26][si],255
	je	$I596
; Line 962
	mov	ax,OFFSET DAT_0000_9866
	jmp	$L20077
	nop	
$I596:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,26
	jmp	$L20072
	nop	
$SC597:
; Line 970
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	cmp	BYTE PTR [bx+25][si],255
	je	$I598
; Line 971
	mov	ax,OFFSET DAT_0000_9846
	jmp	$L20077
	nop	
$I598:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,25
	jmp	$L20072
	nop	
$I599:
; Line 984
; Line 986
	mov	bx,WORD PTR [bp-8]	;local_10
	mov	al,BYTE PTR [bp+6]	;param_1
	mov	BYTE PTR [bx],al
; Line 987
	mov	bx,WORD PTR [bp+6]	;param_1
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
; Line 989
	mov	ax,OFFSET DAT_0000_995E
	push	ax
	call	FUN_1000_1850
; Line 990
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	BYTE PTR [bx+29][si],255
; Line 991
	mov	ax,1200
	push	ax
	mov	ax,2000
	push	ax
	mov	ax,1
	push	ax
	mov	ax,40
	push	ax
	call	FUN_1000_43AE
; Line 992
	mov	ax,1
	jmp	SHORT $EX557
	nop	
$I602:
; Line 993
; Line 995
	cmp	WORD PTR [bp+6],42	;param_1
	je	$JCC4096
	jmp	$I567
$JCC4096:
	cmp	BYTE PTR UNK_0000_5893,127
	ja	$JCC4106
	jmp	$I567
$JCC4106:
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	BYTE PTR [bx+1],29
; Line 1008
	mov	BYTE PTR [bx],29
; Line 1011
	mov	ax,29
$EX557:
	pop	si
	mov	sp,bp
	pop	bp
	ret	4
	nop	

FUN_ZSTATS__01EE3C	ENDP
_TEXT	ENDS
END
