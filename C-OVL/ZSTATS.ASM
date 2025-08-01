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
; Line 180
	PUBLIC	FUN_ZSTATS__01E1E0
FUN_ZSTATS__01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 185
	mov	WORD PTR [bp-4],-1	;local_4
; Line 187
	cmp	BYTE PTR DAT_5893,128
	jbe	$I292
; Line 188
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 189
	test	BYTE PTR D_BA16[si],128
	je	$I292
; Line 190
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 193
	jmp	SHORT $I298
$I292:
; Line 196
	push	WORD PTR TEXT_96B4
	call	FUN_1000_1850
; Line 197
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 198
	or	ax,ax
	jl	$I298
; Line 199
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	push	ax
	call	FUN_1000_1850
; Line 200
	call	FUN_1000_1F12
	or	ax,ax
	je	$I298
; Line 201
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 202
; Line 203
$I298:
; Line 204
; Line 207
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I299
; Line 208
	push	WORD PTR TEXT_96BE
	call	FUN_1000_1850
; Line 209
; Line 211
	jmp	SHORT $I301
	nop	
$I299:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I301
; Line 212
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 213
; Line 216
$I301:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E1E0	ENDP
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
	add	ax,DAT_55A8
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
	mov	ax,OFFSET TEXT_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 242
	mov	ax,OFFSET TEXT_96D0
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
	jle	$I313
; Line 246
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 248
	sub	si,si
; Line 249
$FC315:
; Line 250
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 251
	inc	si
; Line 252
	cmp	WORD PTR [di],si
	jg	$FC315
; Line 253
; Line 256
	mov	WORD PTR [bp-4],si	;local_8
; Line 257
; Line 259
$I313:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 260
	push	WORD PTR TEXT_96D6
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
	push	WORD PTR TEXT_96DC
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
	push	WORD PTR TEXT_96E2
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
	push	WORD PTR TEXT_96E8
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
	push	WORD PTR TEXT_96EE
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
	push	WORD PTR TEXT_96F4
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
	push	WORD PTR TEXT_96FA
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
	push	WORD PTR TEXT_9700
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
; Line 290
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 291
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I321
; Line 292
	sub	ax,ax
	jmp	SHORT $EX320
$I321:
; Line 293
; Line 294
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 295
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_1000_1850
; Line 296
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 297
	mov	ax,1
$EX320:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 304
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 308
	call	FUN_1000_4DAA
; Line 310
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 311
	push	ax
	call	FUN_1000_4E50
; Line 312
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
; Line 313
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 314
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 315
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 316
	push	WORD PTR TEXT_970E
	call	FUN_1000_1850
; Line 317
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 318
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 320
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 321
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 322
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 323
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 324
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 325
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 327
	jne	$I328
; Line 328
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 329
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 330
	push	WORD PTR TEXT_9716
	call	FUN_1000_1850
; Line 331
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 332
; Line 334
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
; Line 335
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 340
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 341
	call	FUN_1000_4DAA
; Line 342
	mov	ax,OFFSET TEXT_9724
	push	ax
	call	FUN_1000_4E50
; Line 343
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
; Line 344
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 345
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
; Line 346
	push	WORD PTR TEXT_972E
	call	FUN_1000_1850
; Line 347
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 348
	push	WORD PTR TEXT_9738
	call	FUN_1000_1850
; Line 349
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 350
	push	WORD PTR TEXT_9742
	call	FUN_1000_1850
; Line 351
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 352
	push	WORD PTR TEXT_9752
	call	FUN_1000_1850
; Line 353
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 354
	push	WORD PTR TEXT_9760
	call	FUN_1000_1850
; Line 355
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 356
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I331
; Line 357
	push	WORD PTR TEXT_976E
	call	FUN_1000_1850
; Line 358
; Line 359
$I331:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 364
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
; Line 368
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
; Line 369
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 370
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
; Line 371
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 372
	mov	WORD PTR [bp-4],13	;local_4
; Line 373
	mov	si,13
$L20000:
; Line 374
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 375
	dec	si
	jne	$L20000
; Line 376
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 377
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 378
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 379
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 380
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 381
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 382
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 383
	mov	WORD PTR [bp-4],si	;local_4
; Line 384
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 385
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 386
	mov	WORD PTR [bp-4],13	;local_4
; Line 387
	mov	si,13
$L20003:
; Line 388
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 389
	dec	si
	jne	$L20003
; Line 390
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 391
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 396
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 397
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 404
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

FUN_ZSTATS__01E6F8	ENDP
; Line 410
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
; Line 411
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC358:
; Line 412
	dec	si
	js	$L20012
; Line 413
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I361
; Line 414
	cmp	di,255
	je	$FC358
; Line 415
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC358
; Line 417
; Line 420
$I361:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX356
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 426
	mov	ax,-1
$EX356:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 432
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
; Line 433
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC371:
; Line 434
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 435
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I374
; Line 436
	cmp	di,255
	je	$FC371
; Line 437
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC371
; Line 439
; Line 442
$I374:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX369
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 448
	mov	ax,-1
$EX369:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 454
	PUBLIC	FUN_ZSTATS__01E7C2
FUN_ZSTATS__01E7C2	PROC NEAR
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
; Line 458
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 459
	cmp	al,255
	je	$I385
; Line 460
	or	al,al
	je	$I386
; Line 461
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 462
	jmp	SHORT $I387
	nop	
$I386:
; Line 463
	push	WORD PTR TEXT_9778
	call	FUN_1000_1850
; Line 464
$I387:
; Line 465
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I388
; Line 466
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 467
; Line 468
$I388:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 469
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 470
; Line 472
$I385:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I390
; Line 473
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 474
	push	WORD PTR TEXT_977C
	call	FUN_1000_1850
; Line 475
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 476
$L20045:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 477
	jmp	SHORT $I395
$I390:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I392
; Line 478
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 479
	push	WORD PTR TEXT_9782
	call	FUN_1000_1850
; Line 480
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 481
	mov	ax,WORD PTR [bp+10]	;param_4
	add	ax,WORD PTR D_19B2
	push	ax
	jmp	SHORT $L20046
	nop	
$I392:
; Line 482
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I394
; Line 483
	push	WORD PTR TEXT_9788
	call	FUN_1000_1850
; Line 484
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 485
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20045
$I394:
; Line 487
; Line 488
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20046:
	call	FUN_1000_1850
; Line 489
$I395:
; Line 492
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 493
	cmp	ax,14
	jge	$I397
;	register si = si
; Line 494
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 495
	add	WORD PTR [bp-4],si	;local_4
; Line 497
$D399:
; Line 498
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 499
	dec	si
; Line 500
	jne	$D399
; Line 501
; Line 502
$I397:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 503
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
; Line 510
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
; Line 519
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 520
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 521
	mov	WORD PTR [bp-4],0	;local_8
; Line 522
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 523
	cmp	ax,-1
	je	$JCC1821
	jmp	$I478
$JCC1821:
; Line 524
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 525
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 526
	push	WORD PTR TEXT_9794
	call	FUN_1000_1850
; Line 527
	call	FUN_1000_4DAA
; Line 528
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 529
	call	FUN_1000_266C
	jmp	$EX407
	nop	
$FC420:
; Line 533
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 534
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 538
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20047
$FC423:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
$L20047:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB424
; Line 540
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	FUN_ZSTATS__01E7C2
; Line 542
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 543
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC423
; Line 544
$FB424:
; Line 548
	mov	WORD PTR [bp-8],0	;local_10
; Line 549
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I426
; Line 550
	mov	WORD PTR [bp-8],2	;local_10
; Line 551
; Line 554
$I426:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I427
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I427
; Line 555
	inc	WORD PTR [bp-8]	;local_10
; Line 556
; Line 559
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
; Line 561
	call	FUN_1000_4DAA
; Line 563
$SB429:
; Line 577
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 578
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 579
	cmp	ax,32
	jne	$I437
	jmp	$L20051
$SC433:
; Line 565
	mov	ax,25
$L20048:
	push	ax
	call	FUN_1000_4DEA
; Line 567
	jmp	SHORT $SB429
	nop	
$SC435:
; Line 569
	mov	ax,24
	jmp	SHORT $L20048
	nop	
$SC436:
; Line 572
	mov	ax,18
	jmp	SHORT $L20048
	nop	
$I437:
; Line 583
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2076
	jmp	$I439
$JCC2076:
; Line 585
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I440
; Line 587
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I441
; Line 588
	mov	WORD PTR [bp-12],7	;local_4
; Line 589
	jmp	SHORT $I442
	nop	
$I441:
; Line 591
	mov	WORD PTR [bp-12],1	;local_4
; Line 592
$I442:
; Line 594
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
; Line 595
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I446
; Line 596
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 597
; Line 598
$I446:
	dec	di
	jne	$L20016
$L20055:
	mov	WORD PTR [bp-2],si	;local_6
; Line 599
	jmp	$I478
$I440:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I447
; Line 603
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2184
	jmp	$I478
$JCC2184:
; Line 605
	cmp	WORD PTR [bp-14],2	;local_e
$L20053:
	jle	$JCC2193
	jmp	$I478
$JCC2193:
; Line 607
$L20051:
	mov	WORD PTR [bp-4],1	;local_8
; Line 608
	jmp	$I478
$I447:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I450
; Line 617
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I451
; Line 618
	mov	WORD PTR [bp-12],7	;local_4
; Line 619
	jmp	SHORT $I452
$I451:
; Line 620
	mov	WORD PTR [bp-12],1	;local_4
; Line 621
$I452:
; Line 623
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
; Line 624
	cmp	si,-1
	je	$I456
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I456
; Line 625
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 626
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 627
; Line 628
$I456:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20056:
	mov	WORD PTR [bp-10],si	;local_c
; Line 629
	jmp	$I478
$I450:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2326
	jmp	$I478
$JCC2326:
	jmp	$L20051
$I439:
; Line 638
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I459
; Line 640
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 641
	jmp	$I478
$I459:
; Line 642
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I461
; Line 643
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2375
	jmp	$I478
$JCC2375:
; Line 644
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20053
	nop	
$I461:
; Line 652
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I465
; Line 654
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	di,ax
; Line 655
	sub	si,si
; Line 657
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$L20021
; Line 659
	mov	di,WORD PTR [bp-10]	;local_c
; Line 660
	inc	si
; Line 661
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 662
	jmp	$I478
$I465:
; Line 663
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I470
; Line 666
	jne	$I471
; Line 667
	mov	WORD PTR [bp-12],7	;local_4
; Line 668
	jmp	SHORT $I472
$I471:
; Line 670
	mov	WORD PTR [bp-12],1	;local_4
; Line 671
$I472:
; Line 673
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
; Line 674
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I476
; Line 675
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 676
; Line 677
$I476:
	dec	di
	jne	$L20022
	jmp	$L20055
	nop	
$I470:
; Line 679
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I478
; Line 682
	jne	$I479
; Line 683
	mov	WORD PTR [bp-12],7	;local_4
; Line 684
	jmp	SHORT $I480
$I479:
; Line 685
	mov	WORD PTR [bp-12],1	;local_4
; Line 686
$I480:
; Line 687
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I478
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 688
	cmp	si,-1
	je	$I484
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I484
; Line 689
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 690
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 691
; Line 692
$I484:
	dec	WORD PTR [bp-18]
	jne	$L20024
	jmp	$L20056
$I478:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2646
	jmp	$FC420
$JCC2646:
; Line 698
; Line 700
	mov	ax,WORD PTR [bp-14]	;local_e
$EX407:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E8C8	ENDP
; Line 706
	PUBLIC	FUN_ZSTATS__01EB7A
FUN_ZSTATS__01EB7A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 709
	sub	si,si
; Line 710
$D488:
; Line 711
	mov	al,BYTE PTR UNK_0000_5820[si]
	mov	BYTE PTR UNK_0000_B9EE[si],al
; Line 712
	mov	al,BYTE PTR UNK_0000_5828[si]
	mov	BYTE PTR UNK_0000_B9F6[si],al
; Line 713
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
; Line 714
	inc	si
	cmp	si,8
	jl	$D488
	mov	WORD PTR [bp-2],si	;local_4
; Line 716
	mov	al,UNK_0000_57B0
	mov	UNK_0000_B9FE,al
; Line 717
	mov	al,UNK_0000_57B1
	mov	UNK_0000_B9FF,al
; Line 718
	mov	al,UNK_0000_57B3
	mov	UNK_0000_BA00,al
; Line 719
	mov	al,UNK_0000_57B4
	mov	UNK_0000_BA01,al
; Line 720
	mov	al,UNK_0000_57B5
	mov	UNK_0000_BA02,al
; Line 722
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET UNK_0000_BA0B
	mov	si,OFFSET UNK_0000_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 726
	mov	al,UNK_0000_57BA
	mov	UNK_0000_BA0E,al
; Line 727
	cmp	BYTE PTR UNK_0000_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	UNK_0000_BA0F,al
; Line 728
	mov	al,UNK_0000_57BC
	mov	UNK_0000_BA10,al
; Line 729
	mov	al,UNK_0000_57BD
	mov	UNK_0000_BA11,al
; Line 730
	mov	al,UNK_0000_57BE
	mov	UNK_0000_BA12,al
; Line 731
	mov	al,UNK_0000_57BF
	mov	UNK_0000_BA13,al
; Line 732
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EB7A	ENDP
; Line 737
	PUBLIC	FUN_ZSTATS__01EC1A
FUN_ZSTATS__01EC1A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 742
	mov	ax,1
	push	ax
	call	FUN_ZSTATS__01E1E0
	mov	WORD PTR [bp-4],ax	;local_8
; Line 743
	cmp	ax,-2
	jne	$I499
; Line 744
	mov	WORD PTR [bp-4],6	;local_8
; Line 745
	jmp	SHORT $I500
	nop	
$I499:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2858
	jmp	$EX495
$JCC2858:
; Line 746
$I500:
	push	WORD PTR TEXT_97A2
	call	FUN_1000_1850
; Line 750
	call	FUN_ZSTATS__01EB7A
; Line 751
	call	FUN_1000_4EFC
; Line 752
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 753
	mov	BYTE PTR [bp-2],0	;local_6
; Line 756
$D503:
; Line 757
; Line 758
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2892
	jmp	$I509
$JCC2892:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2901
	jmp	$I509
$JCC2901:
; Line 759
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I511
	cmp	al,1
	jne	$I510
$I511:
; Line 760
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I512
; Line 761
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20058:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 762
; Line 763
	jmp	SHORT $I526
	nop	
$I512:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I514
; Line 764
	mov	WORD PTR [bp-6],16	;local_4
; Line 765
; Line 766
	jmp	SHORT $I526
	nop	
$I514:
; Line 767
	dec	WORD PTR [bp-6]	;local_4
; Line 768
; Line 769
	jmp	SHORT $I526
	nop	
$I510:
; Line 770
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I518
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I517
$I518:
; Line 771
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I524
; Line 772
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I520
; Line 773
	inc	WORD PTR [bp-6]	;local_4
; Line 774
	jmp	SHORT $I526
$I520:
; Line 775
	mov	WORD PTR [bp-6],0	;local_4
; Line 776
; Line 777
	jmp	SHORT $I526
	nop	
$I517:
; Line 779
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I524
; Line 780
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I524
; Line 781
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
; Line 782
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20058
$I524:
; Line 787
	mov	WORD PTR [bp-6],12	;local_4
; Line 788
; Line 789
$I526:
; Line 797
; Line 800
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 801
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I530
; Line 802
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I531
; Line 803
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E262
; Line 804
	jmp	SHORT $L20057
	nop	
$I509:
; Line 789
; Line 790
	call	FUN_1000_4DAA
; Line 791
	call	FUN_1000_4E20
; Line 792
	call	FUN_1000_4F3C
; Line 793
	call	FUN_1000_2900
; Line 794
	push	WORD PTR TEXT_97CE
	call	FUN_1000_1850
; Line 795
	jmp	$EX495
$I531:
; Line 804
; Line 805
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E488
; Line 806
	jmp	SHORT $L20057
	nop	
$I530:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I533
; Line 814
	call	FUN_ZSTATS__01E57C
; Line 817
$L20057:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 818
	call	FUN_1000_266C
	jmp	SHORT $L20061
	nop	
$I533:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I534
; Line 824
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
; Line 825
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I536
; Line 826
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
; Line 827
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I538
; Line 828
	mov	ax,OFFSET TEXT_97BE
	push	ax
	mov	ax,38
	push	ax
	mov	ax,OFFSET UNK_0000_B9EE
	push	ax
	mov	ax,OFFSET D_1916
$L20063:
	push	ax
	call	FUN_ZSTATS__01E8C8
$L20061:
	mov	BYTE PTR [bp-2],al	;local_6
; Line 829
	jmp	$D503
	nop	
$I538:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3234
	jmp	$D503
$JCC3234:
; Line 830
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

FUN_ZSTATS__01EC1A	ENDP
; Line 838
	PUBLIC	FUN_ZSTATS__01EDCE
FUN_ZSTATS__01EDCE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 839
	push	WORD PTR TEXT_97D4
	call	FUN_1000_1850
; Line 840
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850
; Line 841
	push	WORD PTR TEXT_97D8
	call	FUN_1000_1850
; Line 842
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDCE	ENDP
; Line 847
	PUBLIC	FUN_ZSTATS__01EDEA
FUN_ZSTATS__01EDEA	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 848
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	mov	WORD PTR [bp-2],ax	;s
; Line 850
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I548
	cmp	BYTE PTR [bx+28],255
	jne	$I548
; Line 851
	mov	ax,2
	jmp	SHORT $EX546
	nop	
$I548:
; Line 852
	cmp	BYTE PTR [bx+27],255
	jne	$I550
; Line 853
	sub	ax,ax
	jmp	SHORT $EX546
$I550:
; Line 854
	cmp	BYTE PTR [bx+28],255
	jne	$I552
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	BYTE PTR D_1A7E[bx],48
	je	$I552
; Line 855
	mov	ax,1
	jmp	SHORT $EX546
	nop	
$I552:
; Line 856
; Line 857
	mov	ax,255
$EX546:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDEA	ENDP
; Line 866
	PUBLIC	FUN_ZSTATS__01EE3C
FUN_ZSTATS__01EE3C	PROC NEAR
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
; Line 876
	cmp	BYTE PTR DAT_5893,127
	jbe	$I565
; Line 877
	mov	bl,UNK_0000_589E
	sub	bh,bh
	mov	cl,3
	shl	bx,cl
	mov	al,BYTE PTR UNK_0000_BA18[bx]
	sub	ah,ah
	shl	ax,cl
	add	ax,OFFSET UNK_0000_5C5A
	mov	WORD PTR [bp-2],ax	;local_6
; Line 878
; Line 882
$I565:
	cmp	WORD PTR [bp+4],27	;param_1
	je	$I567
	cmp	WORD PTR [bp+4],29	;param_1
	jne	$I566
$I567:
; Line 883
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
; Line 888
	push	WORD PTR TEXT_97E2
$L20086:
	call	FUN_ZSTATS__01EDCE
	jmp	SHORT $I567
	nop	
$I568:
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$I569
; Line 894
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_6E60
; Line 895
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR DAT_0000_57C0[bx],99
	jge	$I571
; Line 896
	inc	BYTE PTR DAT_0000_57C0[bx]
; Line 897
; Line 899
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
; Line 907
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	si,ax
	mov	al,BYTE PTR D_1ADE[si]
	mov	BYTE PTR [bx+1],al
	mov	BYTE PTR [bx],al
	jmp	$I567
$I569:
; Line 911
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
; Line 913
	push	WORD PTR TEXT_981C
	jmp	$L20086
	nop	
$I574:
	sub	dx,dx
; Line 920
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	add	si,DAT_55A8
	add	si,25
; Line 925
	mov	WORD PTR [bp-6],6	;local_a
	mov	WORD PTR [bp-16],6
	mov	cx,WORD PTR [bp-16]
$L20033:
; Line 926
	cmp	BYTE PTR [si],255
	je	$I581
; Line 927
	mov	bl,BYTE PTR [si]
	sub	bh,bh
	mov	al,BYTE PTR D_1AAE[bx]
	sub	ah,ah
	add	dx,ax
; Line 928
; Line 930
$I581:
	inc	si
; Line 931
	loop	$L20033
	mov	WORD PTR [bp-8],si	;local_10
	mov	WORD PTR [bp-12],dx	;local_4
; Line 934
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
; Line 937
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
; Line 941
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	al,[bx+29][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I587
; Line 942
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
; Line 947
$SB583:
; Line 1002
	cmp	WORD PTR [bp-14],0	;local_e
	je	$JCC3797
	jmp	$I599
$JCC3797:
; Line 1004
	push	WORD PTR TEXT_9942
	jmp	$L20086
	nop	
$SC588:
; Line 950
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	al,[bx+30][si]
	sub	ah,ah
	cmp	ax,-1
	je	$I589
; Line 951
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
; Line 959
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01EDEA
	mov	WORD PTR [bp-10],ax	;local_c
; Line 960
	cmp	ax,255
	jne	$I591
; Line 961
	push	WORD PTR TEXT_9892
	jmp	$L20086
	nop	
$I591:
	cmp	WORD PTR [bp-10],2	;local_c
	jne	$I592
; Line 966
	mov	WORD PTR [bp-10],0	;local_c
; Line 967
; Line 969
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
; Line 973
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01EDEA
	mov	WORD PTR [bp-10],ax	;local_c
; Line 974
	cmp	ax,2
	je	$I594
; Line 975
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
; Line 983
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	cmp	BYTE PTR [bx+26][si],255
	je	$I596
; Line 984
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
; Line 992
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	cmp	BYTE PTR [bx+25][si],255
	je	$I598
; Line 993
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
; Line 1006
; Line 1008
	mov	bx,WORD PTR [bp-8]	;local_10
	mov	al,BYTE PTR [bp+4]	;param_1
	mov	BYTE PTR [bx],al
; Line 1009
	mov	bx,WORD PTR [bp+4]	;param_1
	dec	BYTE PTR DAT_0000_57C0[bx]
; Line 1010
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
; Line 1012
	push	WORD PTR TEXT_995E
	call	FUN_1000_1850
; Line 1013
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	mov	bx,DAT_55A8
	mov	BYTE PTR [bx+29][si],255
; Line 1014
	mov	ax,1200
	push	ax
	mov	ax,2000
	push	ax
	mov	ax,1
	push	ax
	mov	ax,40
	push	ax
	call	FUN_1000_43AE
; Line 1015
	mov	ax,1
	jmp	SHORT $EX557
	nop	
$I602:
; Line 1016
; Line 1018
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
; Line 1031
	mov	BYTE PTR [bx],29
	jmp	$I567
$EX557:
	pop	si
	mov	sp,bp
	pop	bp
	ret	4
	nop	

FUN_ZSTATS__01EE3C	ENDP
; Line 1040
	PUBLIC	FUN_ZSTATS__01F10E
FUN_ZSTATS__01F10E	PROC NEAR
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
; Line 1057
	mov	WORD PTR [bp-8],0	;local_8
; Line 1058
	mov	WORD PTR [bp-14],1	;local_10
; Line 1059
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I627
; Line 1060
	mov	WORD PTR [bp-28],22464	;local_14
; Line 1061
	mov	WORD PTR [bp-12],48	;local_a
; Line 1062
	jmp	SHORT $I628
$I627:
; Line 1063
	mov	WORD PTR [bp-28],-17938	;local_14
; Line 1064
	mov	WORD PTR [bp-12],38	;local_a
; Line 1065
$I628:
; Line 1068
	cmp	WORD PTR [bp-8],0	;local_8
	je	$I629
; Line 1069
	mov	ax,WORD PTR [bp-16]	;local_1a
	jmp	$EX612
$I629:
; Line 1073
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 1074
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 1075
	mov	WORD PTR [bp-22],0	;local_4
; Line 1076
	mov	ax,WORD PTR [bp+8]	;param_3
$L20097:
	mov	WORD PTR [bp-20],ax	;local_12
; Line 1079
; Line 1080
	cmp	ax,-1
	jne	$I636
; Line 1082
	mov	WORD PTR [bp-10],0	;local_18
; Line 1083
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01E74C
	add	ax,1
	je	$I637
; Line 1084
	mov	WORD PTR [bp-10],2	;local_18
; Line 1085
; Line 1087
$I637:
	cmp	WORD PTR [bp-20],-1	;local_12
	je	$I639
; Line 1088
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01E784
	add	ax,1
$L20101:
	je	$I639
; Line 1089
	inc	WORD PTR [bp-10]	;local_18
; Line 1090
; Line 1091
$I639:
; Line 1152
	cmp	WORD PTR [bp-10],0	;local_18
	jne	$JCC4298
	jmp	$I652
$JCC4298:
; Line 1153
	cmp	WORD PTR [bp-10],1	;local_18
	je	$JCC4307
	jmp	$I653
$JCC4307:
; Line 1155
	mov	ax,25
	jmp	$L20099
$I636:
; Line 1094
; Line 1096
	inc	WORD PTR [bp-22]	;local_4
; Line 1097
	call	FUN_1000_1CEE
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I641
; Line 1098
	mov	ax,253
	push	ax
	call	FUN_1000_16BA
; Line 1099
	mov	ax,WORD PTR [bp-20]	;local_12
	mov	WORD PTR [bp-16],ax	;local_1a
; Line 1100
; Line 1103
$I641:
	cmp	WORD PTR [bp+4],82	;param_1
	je	$I642
; Line 1105
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6422
	push	ax
	mov	ax,32
	push	ax
	jmp	SHORT $L20096
$I642:
; Line 1106
; Line 1108
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-20]	;local_12
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$I644
; Line 1110
	mov	bx,WORD PTR [bp-20]	;local_12
	mov	al,BYTE PTR D_1AE8[bx]
	sub	ah,ah
	mov	WORD PTR [bp-18],ax	;local_c
; Line 1111
	jmp	SHORT $I645
	nop	
$I644:
; Line 1113
	mov	WORD PTR [bp-18],32	;local_c
; Line 1114
$I645:
; Line 1116
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6498
	push	ax
	push	WORD PTR [bp-18]	;local_c
$L20096:
	call	FUN_ZSTATS__01E7C2
; Line 1117
; Line 1122
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 1123
	call	FUN_1000_1CEE
	dec	ax
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I646
; Line 1124
	mov	ax,253
	push	ax
	call	FUN_1000_16BA
; Line 1125
; Line 1128
$I646:
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$I647
; Line 1130
	mov	WORD PTR [bp-10],0	;local_18
; Line 1131
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I648
; Line 1132
	mov	WORD PTR [bp-10],2	;local_18
; Line 1133
; Line 1135
$I648:
	cmp	WORD PTR [bp-20],-1	;local_12
	jne	$JCC4480
	jmp	$I639
$JCC4480:
; Line 1136
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01E784
	inc	ax
	jmp	$L20101
$I647:
; Line 1142
; Line 1144
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01E784
	jmp	$L20097
$I653:
; Line 1156
	cmp	WORD PTR [bp-10],2	;local_18
	jne	$I655
; Line 1158
	mov	ax,24
$L20099:
	push	ax
	call	FUN_1000_4DEA
; Line 1159
	jmp	SHORT $I658
	nop	
$I655:
	cmp	WORD PTR [bp-10],3	;local_18
	jne	$I658
; Line 1161
	mov	ax,18
	jmp	SHORT $L20099
	nop	
$I652:
; Line 1163
; Line 1165
	call	FUN_1000_4DAA
; Line 1166
$I658:
; Line 1170
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 1171
	call	FUN_1000_266C
	mov	WORD PTR [bp-6],ax	;local_16
; Line 1173
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
; Line 1180
	cmp	WORD PTR [bp-6],213	;local_16
	jne	$I664
; Line 1181
	mov	WORD PTR [bp-2],7	;local_6
; Line 1182
	jmp	SHORT $I665
$I664:
; Line 1183
	mov	WORD PTR [bp-2],1	;local_6
$I665:
; Line 1184
	mov	WORD PTR [bp-26],0	;local_e
; Line 1185
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4630
	jmp	$I628
$JCC4630:
; Line 1186
;	register si = si
;	register di = di
; Line 1190
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-24],ax	;local_1c
; Line 1191
	add	WORD PTR [bp-26],ax	;local_e
; Line 1192
	mov	di,WORD PTR [bp+8]	;param_3
; Line 1193
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1196
$D669:
; Line 1197
; Line 1198
	cmp	si,4
	je	$I673
	cmp	si,1
	jne	$I672
$I673:
; Line 1199
; Line 1201
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_056C
	inc	ax
	je	$I675
; Line 1202
; Line 1203
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_056C
	mov	di,ax
; Line 1204
; Line 1205
	jmp	SHORT $I678
	nop	
$I675:
; Line 1206
; Line 1208
	cmp	si,4
	jne	$I678
$I672:
; Line 1216
; Line 1218
	dec	si
; Line 1219
$I678:
; Line 1221
	dec	WORD PTR [bp-24]	;local_1c
	jne	$D669
; Line 1223
	mov	WORD PTR [bp+8],di	;param_3
; Line 1226
$L20106:
	mov	WORD PTR [bp-14],si	;local_10
; Line 1227
; Line 1228
	jmp	$I628
$SC679:
; Line 1235
	cmp	WORD PTR [bp-6],214	;local_16
	jne	$I680
; Line 1236
	mov	WORD PTR [bp-2],7	;local_6
; Line 1237
	jmp	SHORT $I681
$I680:
; Line 1238
	mov	WORD PTR [bp-2],1	;local_6
$I681:
; Line 1239
	mov	WORD PTR [bp-26],0	;local_e
; Line 1240
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4742
	jmp	$I628
$JCC4742:
; Line 1241
;	register si = si
;	register di = di
; Line 1245
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-4],ax	;local_1e
; Line 1246
	add	WORD PTR [bp-26],ax	;local_e
; Line 1247
	mov	di,WORD PTR [bp-20]	;local_12
; Line 1248
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1251
$D685:
; Line 1252
; Line 1253
	cmp	si,4
	je	$I689
	cmp	si,7
	je	$I689
	cmp	WORD PTR [bp-22],si	;local_4
	jge	$I688
$I689:
; Line 1254
; Line 1256
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
; Line 1257
; Line 1258
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1259
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_05A4
	mov	di,ax
; Line 1260
; Line 1261
	jmp	SHORT $I694
	nop	
$I691:
; Line 1262
; Line 1264
	cmp	si,4
	jne	$I694
	cmp	WORD PTR [bp-22],4	;local_4
	jne	$I694
$I688:
; Line 1271
; Line 1273
	inc	si
; Line 1274
$I694:
; Line 1276
	dec	WORD PTR [bp-4]	;local_1e
	jne	$D685
; Line 1278
	mov	WORD PTR [bp-20],di	;local_12
	jmp	$L20106
	nop	
$SC695:
; Line 1289
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I696
; Line 1290
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-16]	;local_1a
	call	FUN_ZSTATS__01EE3C
	mov	WORD PTR [bp-8],ax	;local_8
; Line 1291
	jmp	$I628
	nop	
$I696:
; Line 1293
	mov	WORD PTR [bp-8],1	;local_8
; Line 1294
; Line 1296
	jmp	$I628
$SC698:
; Line 1300
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
; Line 1301
	mov	WORD PTR [bp-8],1	;local_8
; Line 1302
	mov	WORD PTR [bp-16],-1	;local_1a
; Line 1305
	jmp	$I628
$SC699:
; Line 1310
	mov	ax,-1
	push	ax
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1311
	mov	WORD PTR [bp-14],1	;local_10
; Line 1313
	jmp	$I628
	nop	
$SC700:
; Line 1315
; Line 1319
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS_01E74C
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1321
	mov	di,1
; Line 1322
$D702:
; Line 1325
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	FUN_ZSTATS_01E74C
	mov	si,ax
; Line 1326
	cmp	si,-1
	jne	$I705
; Line 1327
; Line 1329
$L20105:
	mov	WORD PTR [bp-14],di	;local_10
	mov	WORD PTR [bp-16],si	;local_1a
	jmp	$I628
$I705:
	mov	WORD PTR [bp+8],si	;param_3
; Line 1334
	inc	di
; Line 1335
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

FUN_ZSTATS__01F10E	ENDP
; Line 1348
	PUBLIC	F_1296
F_1296	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	local_6 = -2
;	local_4 = -4
; Line 1353
	sub	ax,ax
	push	ax
	call	FUN_ZSTATS__01E1E0
	mov	WORD PTR [bp-2],ax	;local_6
; Line 1355
	or	ax,ax
	jl	$END711
; Line 1356
	mov	ax,-1
	push	ax
	mov	ax,48
	push	ax
	mov	ax,22464
	push	ax
	push	WORD PTR [bp-2]	;local_6
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-4],ax	;local_4
; Line 1360
	cmp	ax,-1
	jne	$I712
; Line 1361
; Line 1362
	mov	ax,-26242
	push	ax
	call	SUB_0000_3670
; Line 1363
	jmp	SHORT $END711
$I712:
	mov	ax,-26216
	push	ax
	call	SUB_0000_3670
; Line 1367
	call	SUB_0000_6D1C
; Line 1368
	mov	ax,1
	push	ax
	call	SUB_0000_39B4
; Line 1370
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	cl,5
	shl	ax,cl
	add	ax,DAT_55A8
	push	ax
	call	SUB_0000_6C70
; Line 1372
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 1374
	push	WORD PTR [bp-4]	;local_4
	push	WORD PTR [bp-2]	;local_6
	mov	ax,82
	push	ax
	call	FUN_ZSTATS__01F10E
; Line 1376
	call	SUB_0000_6BCA
; Line 1377
	call	SUB_0000_6C40
; Line 1378
	call	SUB_0000_6D5C
; Line 1379
	call	SUB_0000_4720
; Line 1381
$END711:
; Line 1382
	mov	sp,bp
	pop	bp
	ret	

F_1296	ENDP
_TEXT	ENDS
END
