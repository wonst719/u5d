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
EXTRN	FUN_1000_1C9E:NEAR
EXTRN	FUN_1000_16BA:NEAR
EXTRN	UNK_0000_57DB:BYTE
EXTRN	UNK_0000_57DD:BYTE
EXTRN	DAT_0000_58F0:BYTE
EXTRN	UNK_0000_5820:QWORD
EXTRN	UNK_0000_5828:QWORD
EXTRN	UNK_0000_5840:QWORD
EXTRN	DAT_0000_5850:BYTE
EXTRN	UNK_0000_5893:BYTE
EXTRN	UNK_0000_589E:BYTE
EXTRN	UNK_0000_5C5A:BYTE
EXTRN	DAT_0000_96B4:WORD
EXTRN	DAT_0000_96BE:WORD
EXTRN	D_1916:BYTE
EXTRN	DAT_0000_96C6:WORD
EXTRN	D_1962:BYTE
EXTRN	DAT_0000_96D0:WORD
_BSS      SEGMENT
COMM NEAR	D_19B2:	BYTE:	 2
EXTRN	DAT_0000_96D6:WORD
EXTRN	D_19D2:BYTE
EXTRN	DAT_0000_96DC:WORD
EXTRN	D_19E2:BYTE
EXTRN	DAT_0000_96E2:WORD
EXTRN	D_1A44:BYTE
EXTRN	DAT_0000_96E8:WORD
EXTRN	D_1A58:BYTE
EXTRN	DAT_0000_96EE:WORD
EXTRN	D_1A6A:BYTE
EXTRN	DAT_0000_96F4:WORD
EXTRN	D_1A7E:BYTE
EXTRN	DAT_0000_96FA:WORD
EXTRN	D_1ADE:BYTE
EXTRN	DAT_0000_9700:WORD
EXTRN	D_1AAE:BYTE
EXTRN	DAT_0000_970E:WORD
EXTRN	DAT_0000_9716:WORD
EXTRN	DAT_0000_9724:WORD
EXTRN	DAT_0000_972E:WORD
EXTRN	DAT_0000_9738:WORD
EXTRN	DAT_0000_9742:WORD
EXTRN	DAT_0000_9752:WORD
EXTRN	DAT_0000_9760:WORD
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
EXTRN	DAT_0000_981C:WORD
EXTRN	D_55A8:WORD
EXTRN	DAT_0000_995E:WORD
EXTRN	UNK_0000_57A8:WORD
EXTRN	UNK_0000_B9EE:QWORD
EXTRN	UNK_0000_57AA:WORD
EXTRN	UNK_0000_B9F6:QWORD
EXTRN	UNK_0000_57AC:BYTE
EXTRN	UNK_0000_B9FE:BYTE
EXTRN	UNK_0000_57AD:BYTE
EXTRN	UNK_0000_B9FF:BYTE
EXTRN	UNK_0000_57AE:BYTE
EXTRN	UNK_0000_BA00:BYTE
EXTRN	UNK_0000_57AF:BYTE
EXTRN	UNK_0000_57B0:BYTE
EXTRN	UNK_0000_BA01:BYTE
EXTRN	UNK_0000_57B1:BYTE
EXTRN	UNK_0000_BA02:BYTE
EXTRN	UNK_0000_57B3:BYTE
EXTRN	UNK_0000_BA03:QWORD
EXTRN	UNK_0000_57B4:BYTE
EXTRN	UNK_0000_BA0B:BYTE
EXTRN	UNK_0000_57B5:BYTE
EXTRN	UNK_0000_BA0E:BYTE
EXTRN	UNK_0000_57B6:BYTE
EXTRN	UNK_0000_BA0F:BYTE
EXTRN	UNK_0000_BA10:BYTE
EXTRN	UNK_0000_57BA:BYTE
EXTRN	UNK_0000_BA11:BYTE
EXTRN	UNK_0000_57BB:BYTE
EXTRN	UNK_0000_BA12:BYTE
EXTRN	UNK_0000_57BC:BYTE
EXTRN	UNK_0000_BA13:BYTE
EXTRN	UNK_0000_57BD:BYTE
EXTRN	UNK_0000_57BE:BYTE
EXTRN	D_BA16:BYTE
EXTRN	UNK_0000_57BF:BYTE
EXTRN	UNK_0000_BA18:BYTE
EXTRN	DAT_0000_57C0:BYTE
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 174
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 179
	mov	WORD PTR [bp-4],-1	;local_4
; Line 181
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I283
; Line 182
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 183
	test	BYTE PTR D_BA16[si],128
	je	$I283
; Line 184
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 187
	jmp	SHORT $I289
$I283:
; Line 190
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 191
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 192
	or	ax,ax
	jl	$I289
; Line 193
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 194
	call	FUN_1000_1F12
	or	ax,ax
	je	$I289
; Line 195
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 196
; Line 197
$I289:
; Line 198
; Line 201
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I290
; Line 202
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 203
; Line 205
	jmp	SHORT $I292
	nop	
$I290:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I292
; Line 206
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 207
; Line 210
$I292:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 215
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
; Line 225
	call	FUN_0000_8BCA
; Line 227
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 229
	push	ax
	call	FUN_1000_4E50
; Line 230
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
; Line 231
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 232
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
; Line 234
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 235
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 236
	mov	WORD PTR [bp-4],0	;local_8
; Line 238
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I304
; Line 239
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 241
	sub	si,si
; Line 242
$FC306:
; Line 243
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 244
	inc	si
; Line 245
	cmp	WORD PTR [di],si
	jg	$FC306
; Line 246
; Line 249
	mov	WORD PTR [bp-4],si	;local_8
; Line 250
; Line 252
$I304:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 253
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 254
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 255
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 256
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 257
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
; Line 258
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 259
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 260
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 261
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
; Line 262
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 263
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 264
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 265
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 266
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 267
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 268
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 269
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 270
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 271
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 272
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 273
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 274
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 275
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 276
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 277
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 278
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 282
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 283
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I312
; Line 284
	sub	ax,ax
	jmp	SHORT $EX311
$I312:
; Line 285
; Line 286
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 287
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_1000_1850
; Line 288
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 289
	mov	ax,1
$EX311:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 295
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 299
	call	FUN_1000_4DAA
; Line 301
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 302
	push	ax
	call	FUN_1000_4E50
; Line 303
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
; Line 304
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 305
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 306
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 307
	mov	ax,OFFSET DAT_0000_970E
	push	ax
	call	FUN_1000_1850
; Line 308
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 309
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 311
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 312
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 313
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 314
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 315
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 316
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 318
	jne	$I319
; Line 319
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 320
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 321
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 322
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 323
; Line 325
$I319:
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
; Line 326
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 330
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 331
	call	FUN_1000_4DAA
; Line 332
	mov	ax,OFFSET DAT_0000_9724
	push	ax
	call	FUN_1000_4E50
; Line 333
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
; Line 334
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 335
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
; Line 336
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 337
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 338
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 339
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 340
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 341
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 342
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 343
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 344
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 345
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 346
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I322
; Line 347
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 348
; Line 349
$I322:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 353
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
; Line 357
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
; Line 358
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 359
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
; Line 360
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 361
	mov	WORD PTR [bp-4],13	;local_4
; Line 362
	mov	si,13
$L20000:
; Line 363
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 364
	dec	si
	jne	$L20000
; Line 365
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 366
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 367
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 368
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 369
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 370
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 371
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 372
	mov	WORD PTR [bp-4],si	;local_4
; Line 373
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 374
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 375
	mov	WORD PTR [bp-4],13	;local_4
; Line 376
	mov	si,13
$L20003:
; Line 377
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 378
	dec	si
	jne	$L20003
; Line 379
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 380
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 384
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 385
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 392
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
	jmp	SHORT $EX340
	nop	
$L20004:
	sub	ax,ax
$EX340:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 397
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
; Line 398
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC349:
; Line 399
	dec	si
	js	$L20012
; Line 400
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I352
; Line 401
	cmp	di,255
	je	$FC349
; Line 402
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC349
; Line 404
; Line 407
$I352:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX347
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 413
	mov	ax,-1
$EX347:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 418
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
; Line 419
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC362:
; Line 420
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 421
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I365
; Line 422
	cmp	di,255
	je	$FC362
; Line 423
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC362
; Line 425
; Line 428
$I365:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX360
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 434
	mov	ax,-1
$EX360:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 439
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
; Line 443
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 444
	cmp	al,255
	je	$I376
; Line 445
	or	al,al
	je	$I377
; Line 446
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 447
	jmp	SHORT $I378
	nop	
$I377:
; Line 448
	mov	ax,OFFSET DAT_0000_9778
	push	ax
	call	FUN_1000_1850
; Line 449
$I378:
; Line 450
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I379
; Line 451
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 452
; Line 453
$I379:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 454
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 455
; Line 457
$I376:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I381
; Line 458
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 459
	mov	ax,OFFSET DAT_0000_977C
	push	ax
	call	FUN_1000_1850
; Line 460
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 461
$L20037:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 462
	jmp	SHORT $I386
$I381:
	mov	si,WORD PTR [bp+10]	;param_4
	shl	si,1
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I383
; Line 463
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 464
	mov	ax,OFFSET DAT_0000_9782
	push	ax
	call	FUN_1000_1850
; Line 465
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 466
	mov	ax,WORD PTR D_19B2
	add	ax,si
	push	ax
	jmp	SHORT $L20038
	nop	
$I383:
; Line 467
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I385
; Line 468
	mov	ax,OFFSET DAT_0000_9788
	push	ax
	call	FUN_1000_1850
; Line 469
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 470
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20037
$I385:
; Line 472
; Line 473
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20038:
	call	FUN_1000_1850
; Line 474
$I386:
; Line 477
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 478
	cmp	ax,14
	jge	$I388
;	register si = si
; Line 479
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 480
	add	WORD PTR [bp-4],si	;local_4
; Line 482
$D390:
; Line 483
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 484
	dec	si
; Line 485
	jne	$D390
; Line 486
; Line 487
$I388:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 488
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
; Line 495
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
; Line 504
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 505
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 506
	mov	WORD PTR [bp-4],0	;local_8
; Line 507
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 508
	cmp	ax,-1
	je	$JCC1823
	jmp	$I469
$JCC1823:
; Line 509
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 510
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 511
	mov	ax,OFFSET DAT_0000_9794
	push	ax
	call	FUN_1000_1850
; Line 512
	call	FUN_1000_4DAA
; Line 513
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 514
	call	FUN_1000_266C
	jmp	$EX398
	nop	
$FC411:
; Line 518
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 519
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 523
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20039
$FC414:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
$L20039:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB415
; Line 525
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	FUN_ZSTATS__01E7C2
; Line 527
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 528
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC414
; Line 529
$FB415:
; Line 533
	mov	WORD PTR [bp-8],0	;local_10
; Line 534
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I417
; Line 535
	mov	WORD PTR [bp-8],2	;local_10
; Line 536
; Line 539
$I417:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I418
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I418
; Line 540
	inc	WORD PTR [bp-8]	;local_10
; Line 541
; Line 544
$I418:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC423
	cmp	ax,1
	je	$SC424
	cmp	ax,2
	je	$SC426
	cmp	ax,3
	je	$SC427
	jmp	SHORT $SB420
$SC423:
; Line 546
	call	FUN_1000_4DAA
; Line 548
$SB420:
; Line 562
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 563
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 564
	cmp	ax,32
	jne	$I428
	jmp	$L20043
$SC424:
; Line 550
	mov	ax,25
$L20040:
	push	ax
	call	FUN_1000_4DEA
; Line 552
	jmp	SHORT $SB420
	nop	
$SC426:
; Line 554
	mov	ax,24
	jmp	SHORT $L20040
	nop	
$SC427:
; Line 557
	mov	ax,18
	jmp	SHORT $L20040
	nop	
$I428:
; Line 568
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2078
	jmp	$I430
$JCC2078:
; Line 570
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I431
; Line 572
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I432
; Line 573
	mov	WORD PTR [bp-12],7	;local_4
; Line 574
	jmp	SHORT $I433
	nop	
$I432:
; Line 576
	mov	WORD PTR [bp-12],1	;local_4
; Line 577
$I433:
; Line 579
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2118
	jmp	$I469
$JCC2118:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 580
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I437
; Line 581
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 582
; Line 583
$I437:
	dec	di
	jne	$L20016
$L20047:
	mov	WORD PTR [bp-2],si	;local_6
; Line 584
	jmp	$I469
$I431:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I438
; Line 588
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2186
	jmp	$I469
$JCC2186:
; Line 590
	cmp	WORD PTR [bp-14],2	;local_e
$L20045:
	jle	$JCC2195
	jmp	$I469
$JCC2195:
; Line 592
$L20043:
	mov	WORD PTR [bp-4],1	;local_8
; Line 593
	jmp	$I469
$I438:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I441
; Line 602
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I442
; Line 603
	mov	WORD PTR [bp-12],7	;local_4
; Line 604
	jmp	SHORT $I443
$I442:
; Line 605
	mov	WORD PTR [bp-12],1	;local_4
; Line 606
$I443:
; Line 608
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2242
	jmp	$I469
$JCC2242:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 609
	cmp	si,-1
	je	$I447
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I447
; Line 610
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 611
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 612
; Line 613
$I447:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20048:
	mov	WORD PTR [bp-10],si	;local_c
; Line 614
	jmp	$I469
$I441:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2328
	jmp	$I469
$JCC2328:
	jmp	$L20043
$I430:
; Line 623
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I450
; Line 625
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 626
	jmp	$I469
$I450:
; Line 627
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I452
; Line 628
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2377
	jmp	$I469
$JCC2377:
; Line 629
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20045
	nop	
$I452:
; Line 637
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I456
; Line 639
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	di,ax
; Line 640
	sub	si,si
; Line 642
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$L20021
; Line 644
	mov	di,WORD PTR [bp-10]	;local_c
; Line 645
	inc	si
; Line 646
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 647
	jmp	$I469
$I456:
; Line 648
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I461
; Line 651
	jne	$I462
; Line 652
	mov	WORD PTR [bp-12],7	;local_4
; Line 653
	jmp	SHORT $I463
$I462:
; Line 655
	mov	WORD PTR [bp-12],1	;local_4
; Line 656
$I463:
; Line 658
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2482
	jmp	$I469
$JCC2482:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 659
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I467
; Line 660
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 661
; Line 662
$I467:
	dec	di
	jne	$L20022
	jmp	$L20047
	nop	
$I461:
; Line 664
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I469
; Line 667
	jne	$I470
; Line 668
	mov	WORD PTR [bp-12],7	;local_4
; Line 669
	jmp	SHORT $I471
$I470:
; Line 670
	mov	WORD PTR [bp-12],1	;local_4
; Line 671
$I471:
; Line 672
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I469
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 673
	cmp	si,-1
	je	$I475
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I475
; Line 674
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 675
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 676
; Line 677
$I475:
	dec	WORD PTR [bp-18]
	jne	$L20024
	jmp	$L20048
$I469:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2648
	jmp	$FC411
$JCC2648:
; Line 683
; Line 685
	mov	ax,WORD PTR [bp-14]	;local_e
$EX398:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E8C8	ENDP
; Line 690
	PUBLIC	FUN_ZSTATS__01EB7A
FUN_ZSTATS__01EB7A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 693
	sub	si,si
; Line 694
$D479:
; Line 695
	mov	al,BYTE PTR UNK_0000_5820[si]
	mov	BYTE PTR UNK_0000_B9EE[si],al
; Line 696
	mov	al,BYTE PTR UNK_0000_5828[si]
	mov	BYTE PTR UNK_0000_B9F6[si],al
; Line 697
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
; Line 698
	inc	si
	cmp	si,8
	jl	$D479
	mov	WORD PTR [bp-2],si	;local_4
; Line 700
	mov	al,UNK_0000_57B0
	mov	UNK_0000_B9FE,al
; Line 701
	mov	al,UNK_0000_57B1
	mov	UNK_0000_B9FF,al
; Line 702
	mov	al,UNK_0000_57B3
	mov	UNK_0000_BA00,al
; Line 703
	mov	al,UNK_0000_57B4
	mov	UNK_0000_BA01,al
; Line 704
	mov	al,UNK_0000_57B5
	mov	UNK_0000_BA02,al
; Line 706
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET UNK_0000_BA0B
	mov	si,OFFSET UNK_0000_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 710
	mov	al,UNK_0000_57BA
	mov	UNK_0000_BA0E,al
; Line 711
	cmp	BYTE PTR UNK_0000_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	UNK_0000_BA0F,al
; Line 712
	mov	al,UNK_0000_57BC
	mov	UNK_0000_BA10,al
; Line 713
	mov	al,UNK_0000_57BD
	mov	UNK_0000_BA11,al
; Line 714
	mov	al,UNK_0000_57BE
	mov	UNK_0000_BA12,al
; Line 715
	mov	al,UNK_0000_57BF
	mov	UNK_0000_BA13,al
; Line 716
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EB7A	ENDP
; Line 720
	PUBLIC	FUN_ZSTATS__01EC1A
FUN_ZSTATS__01EC1A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 725
	mov	ax,1
	push	ax
	call	FUN_ZSTATS__01E1E0
	mov	WORD PTR [bp-4],ax	;local_8
; Line 726
	cmp	ax,-2
	jne	$I491
; Line 727
	mov	WORD PTR [bp-4],6	;local_8
; Line 728
	jmp	SHORT $I492
	nop	
$I491:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2860
	jmp	$EX486
$JCC2860:
; Line 729
$I492:
	mov	ax,OFFSET DAT_0000_97A2
	push	ax
	call	FUN_1000_1850
; Line 733
	call	FUN_ZSTATS__01EB7A
; Line 734
	call	FUN_1000_4EFC
; Line 735
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 736
	mov	BYTE PTR [bp-2],0	;local_6
; Line 739
$D495:
; Line 740
; Line 741
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2894
	jmp	$I501
$JCC2894:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2903
	jmp	$I501
$JCC2903:
; Line 742
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I503
	cmp	al,1
	jne	$I502
$I503:
; Line 743
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I504
; Line 744
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20050:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 745
; Line 746
	jmp	SHORT $I518
	nop	
$I504:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I506
; Line 747
	mov	WORD PTR [bp-6],16	;local_4
; Line 748
; Line 749
	jmp	SHORT $I518
	nop	
$I506:
; Line 750
	dec	WORD PTR [bp-6]	;local_4
; Line 751
; Line 752
	jmp	SHORT $I518
	nop	
$I502:
; Line 753
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I510
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I509
$I510:
; Line 754
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I516
; Line 755
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I512
; Line 756
	inc	WORD PTR [bp-6]	;local_4
; Line 757
	jmp	SHORT $I518
$I512:
; Line 758
	mov	WORD PTR [bp-6],0	;local_4
; Line 759
; Line 760
	jmp	SHORT $I518
	nop	
$I509:
; Line 762
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I516
; Line 763
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I516
; Line 764
	jbe	$I518
	cmp	BYTE PTR [bp-2],55	;local_6
	jae	$I518
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	mov	si,ax
	lea	ax,WORD PTR [si-49]
	mov	bx,22619
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	cmp	ax,cx
	jae	$I518
; Line 765
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20050
$I516:
; Line 770
	mov	WORD PTR [bp-6],12	;local_4
; Line 771
; Line 772
$I518:
; Line 780
; Line 783
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 784
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I522
; Line 785
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I523
; Line 786
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E262
; Line 787
	jmp	SHORT $L20049
	nop	
$I501:
; Line 772
; Line 773
	call	FUN_1000_4DAA
; Line 774
	call	FUN_1000_4E20
; Line 775
	call	FUN_1000_4F3C
; Line 776
	call	FUN_1000_2900
; Line 777
	mov	ax,-26674
	push	ax
	call	FUN_1000_1850
; Line 778
	jmp	$EX486
$I523:
; Line 787
; Line 788
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E488
; Line 789
	jmp	SHORT $L20049
	nop	
$I522:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I525
; Line 797
	call	FUN_ZSTATS__01E57C
; Line 800
$L20049:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 801
	call	FUN_1000_266C
	jmp	SHORT $L20053
	nop	
$I525:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I526
; Line 807
	mov	ax,OFFSET DAT_0000_97AC
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET DAT_0000_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20055
	nop	
$I526:
; Line 808
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I528
; Line 809
	mov	ax,OFFSET DAT_0000_97B6
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20055
	nop	
$I528:
; Line 810
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I530
; Line 811
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
; Line 812
	jmp	$D495
	nop	
$I530:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3236
	jmp	$D495
$JCC3236:
; Line 813
	mov	ax,OFFSET DAT_0000_97C4
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20055
$EX486:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EC1A	ENDP
; Line 820
	PUBLIC	FUN_ZSTATS__01EDCE
FUN_ZSTATS__01EDCE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 821
	mov	ax,OFFSET DAT_0000_97D4
	push	ax
	call	FUN_1000_1850
; Line 822
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850
; Line 823
	mov	ax,OFFSET DAT_0000_97D8
	push	ax
	call	FUN_1000_1850
; Line 824
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDCE	ENDP
; Line 828
	PUBLIC	FUN_ZSTATS__01EDEA
FUN_ZSTATS__01EDEA	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 829
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;s
; Line 831
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I540
	cmp	BYTE PTR [bx+28],255
	jne	$I540
; Line 832
	mov	ax,2
	jmp	SHORT $EX538
	nop	
$I540:
; Line 833
	cmp	BYTE PTR [bx+27],255
	jne	$I542
; Line 834
	sub	ax,ax
	jmp	SHORT $EX538
$I542:
; Line 835
	cmp	BYTE PTR [bx+28],255
	jne	$I544
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	BYTE PTR D_1A7E[bx],48
	je	$I544
; Line 836
	mov	ax,1
	jmp	SHORT $EX538
	nop	
$I544:
; Line 837
; Line 838
	mov	ax,255
$EX538:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDEA	ENDP
; Line 843
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
; Line 852
	cmp	BYTE PTR UNK_0000_5893,127
	jbe	$I557
; Line 853
	mov	bl,UNK_0000_589E
	sub	bh,bh
	mov	cl,3
	shl	bx,cl
	mov	al,BYTE PTR UNK_0000_BA18[bx]
	sub	ah,ah
	shl	ax,cl
	add	ax,OFFSET UNK_0000_5C5A
	mov	WORD PTR [bp-2],ax	;local_6
; Line 854
; Line 857
$I557:
	cmp	WORD PTR [bp+6],27	;param_1
	je	$I559
	cmp	WORD PTR [bp+6],29	;param_1
	jne	$I558
$I559:
; Line 858
	sub	ax,ax
	jmp	$EX549
	nop	
$I558:
	cmp	WORD PTR [bp+6],9	;param_1
	jl	$I560
	cmp	WORD PTR [bp+6],15	;param_1
	jg	$I560
	cmp	BYTE PTR UNK_0000_5893,127
	jbe	$I560
	cmp	BYTE PTR UNK_0000_5893,0
	jne	$I560
; Line 862
	mov	ax,OFFSET DAT_0000_97E2
$L20077:
	push	ax
	call	FUN_ZSTATS__01EDCE
	jmp	SHORT $I559
	nop	
$I560:
	push	WORD PTR [bp+4]	;param_2
	push	WORD PTR [bp+6]	;param_1
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$I561
; Line 867
	push	WORD PTR [bp+4]	;param_2
	push	WORD PTR [bp+6]	;param_1
	call	FUN_1000_6E60
; Line 868
	mov	bx,WORD PTR [bp+6]	;param_1
	cmp	BYTE PTR DAT_0000_57C0[bx],99
	jge	$I563
; Line 869
	inc	BYTE PTR DAT_0000_57C0[bx]
; Line 870
; Line 872
$I563:
	cmp	BYTE PTR UNK_0000_5893,127
	jbe	$I559
	cmp	bx,42
	jne	$I559
	mov	ax,-26606
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
; Line 880
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	si,ax
	mov	al,BYTE PTR D_1ADE[si]
	mov	BYTE PTR [bx+1],al
	mov	BYTE PTR [bx],al
	jmp	$I559
$I561:
; Line 884
	cmp	WORD PTR [bp+6],26	;param_1
	je	$I569
	cmp	WORD PTR [bp+6],36	;param_1
	jne	$I568
$I569:
	cmp	BYTE PTR UNK_0000_57DB,0
	je	$I567
$I568:
	cmp	WORD PTR [bp+6],28	;param_1
	jne	$I566
	cmp	BYTE PTR UNK_0000_57DD,0
	jne	$I566
$I567:
; Line 885
	mov	ax,OFFSET DAT_0000_981C
	jmp	$L20077
$I566:
	sub	dx,dx
; Line 891
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	add	si,D_55A8
	add	si,25
; Line 896
	mov	WORD PTR [bp-6],6	;local_a
	mov	WORD PTR [bp-16],6
	mov	cx,WORD PTR [bp-16]
$L20033:
; Line 897
	cmp	BYTE PTR [si],255
	je	$I573
; Line 898
	mov	bl,BYTE PTR [si]
	sub	bh,bh
	mov	al,BYTE PTR D_1AAE[bx]
	sub	ah,ah
	add	dx,ax
; Line 899
; Line 901
$I573:
	inc	si
; Line 902
	loop	$L20033
	mov	WORD PTR [bp-8],si	;local_10
	mov	WORD PTR [bp-12],dx	;local_4
; Line 904
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
; Line 907
	mov	bx,WORD PTR [bp+6]	;param_1
	mov	al,BYTE PTR D_1A7E[bx]
	sub	ah,ah
	cmp	ax,2
	je	$SC578
	cmp	ax,4
	je	$SC580
	cmp	ax,32
	je	$SC582
	cmp	ax,48
	jne	$JCC3722
	jmp	$SC585
$JCC3722:
	cmp	ax,64
	jne	$JCC3730
	jmp	$SC587
$JCC3730:
	cmp	ax,128
	jne	$JCC3738
	jmp	$SC589
$JCC3738:
	jmp	SHORT $SB575
	nop	
$SC578:
; Line 911
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	al,[bx+29][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I579
; Line 912
	mov	ax,-26346
	jmp	$L20077
	nop	
$I579:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,29
$L20072:
	mov	WORD PTR [bp-8],ax	;local_10
; Line 917
$SB575:
; Line 974
	cmp	WORD PTR [bp-14],0	;local_e
	je	$JCC3793
	jmp	$I591
$JCC3793:
; Line 976
	mov	ax,-26302
	jmp	$L20077
$SC580:
; Line 920
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	al,[bx+30][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I581
; Line 921
	mov	ax,-26384
	jmp	$L20077
	nop	
$I581:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,30
	jmp	SHORT $L20072
$SC582:
; Line 929
	push	WORD PTR [bp+4]	;param_2
	call	FUN_ZSTATS__01EDEA
	mov	WORD PTR [bp-10],ax	;local_c
; Line 930
	cmp	ax,255
	jne	$I583
; Line 931
	mov	ax,-26478
	jmp	$L20077
$I583:
	cmp	WORD PTR [bp-10],2	;local_c
	jne	$I584
; Line 936
	mov	WORD PTR [bp-10],0	;local_c
; Line 937
; Line 941
$I584:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,WORD PTR [bp-10]	;local_c
$L20085:
	add	ax,D_55A8
	add	ax,27
	jmp	SHORT $L20072
$SC585:
; Line 945
	push	WORD PTR [bp+4]	;param_2
	call	FUN_ZSTATS__01EDEA
	mov	WORD PTR [bp-10],ax	;local_c
; Line 946
	cmp	ax,2
	je	$I586
; Line 947
	mov	ax,-26438
	jmp	$L20077
$I586:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	jmp	SHORT $L20085
	nop	
$SC587:
; Line 955
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	cmp	BYTE PTR [bx+26][si],255
	je	$I588
; Line 956
	mov	ax,-26522
	jmp	$L20077
	nop	
$I588:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,26
	jmp	$L20072
	nop	
$SC589:
; Line 964
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	cmp	BYTE PTR [bx+25][si],255
	je	$I590
; Line 965
	mov	ax,-26554
	jmp	$L20077
	nop	
$I590:
	mov	ax,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,bx
	add	ax,25
	jmp	$L20072
	nop	
$I591:
; Line 978
; Line 980
	mov	bx,WORD PTR [bp-8]	;local_10
	mov	al,BYTE PTR [bp+6]	;param_1
	mov	BYTE PTR [bx],al
; Line 981
	mov	bx,WORD PTR [bp+6]	;param_1
	cmp	BYTE PTR DAT_0000_57C0[bx],42
	je	$I595
	cmp	BYTE PTR DAT_0000_57C0[bx],44
	jne	$I594
$I595:
	sub	ax,ax
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_2092
	or	ax,ax
	jne	$I594
; Line 983
	mov	ax,OFFSET DAT_0000_995E
	push	ax
	call	FUN_1000_1850
; Line 984
	mov	si,WORD PTR [bp+4]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,D_55A8
	mov	BYTE PTR [bx+29][si],255
; Line 985
	mov	ax,1200
	push	ax
	mov	ax,2000
	push	ax
	mov	ax,1
	push	ax
	mov	ax,40
	push	ax
	call	FUN_1000_43AE
; Line 986
	mov	ax,1
	jmp	SHORT $EX549
	nop	
$I594:
; Line 987
; Line 989
	cmp	WORD PTR [bp+6],42	;param_1
	je	$JCC4096
	jmp	$I559
$JCC4096:
	cmp	BYTE PTR UNK_0000_5893,127
	ja	$JCC4106
	jmp	$I559
$JCC4106:
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	BYTE PTR [bx+1],29
; Line 1002
	mov	BYTE PTR [bx],29
; Line 1005
	mov	ax,29
$EX549:
	pop	si
	mov	sp,bp
	pop	bp
	ret	4
	nop	

FUN_ZSTATS__01EE3C	ENDP
_TEXT	ENDS
END
