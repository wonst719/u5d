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
EXTRN	FUN_1000_1B94:NEAR
EXTRN	FUN_1000_266C:NEAR
EXTRN	FUN_1000_1F12:NEAR
EXTRN	FUN_1000_4DEA:NEAR
EXTRN	FUN_ZSTATS__01E1E0:NEAR
EXTRN	FUN_1000_4EFC:NEAR
EXTRN	FUN_0000_8BCA:NEAR
EXTRN	FUN_1000_4D76:NEAR
EXTRN	FUN_1000_1C9E:NEAR
EXTRN	FUN_1000_16BA:NEAR
EXTRN	FUN_1000_1850:NEAR
EXTRN	FUN_1000_1A3E:NEAR
EXTRN	FUN_1000_1C22:NEAR
EXTRN	FUN_1000_1CEE:NEAR
EXTRN	FUN_1000_1BF2:NEAR
EXTRN	FUN_1000_4E20:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	FUN_1000_4F3C:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	UNK_0000_5820:QWORD
EXTRN	UNK_0000_5828:QWORD
EXTRN	UNK_0000_5840:QWORD
EXTRN	DAT_0000_5850:BYTE
EXTRN	D_1916:BYTE
_BSS      SEGMENT
COMM NEAR	D_19B2:	BYTE:	 2
EXTRN	UNK_0000_5893:BYTE
EXTRN	D_19D2:BYTE
EXTRN	UNK_0000_589E:BYTE
EXTRN	D_19E2:BYTE
EXTRN	D_55A8:WORD
EXTRN	D_1A44:BYTE
EXTRN	DAT_0000_96B4:WORD
EXTRN	D_1A58:BYTE
EXTRN	DAT_0000_96BE:WORD
EXTRN	DAT_0000_96C6:WORD
EXTRN	D_1962:BYTE
EXTRN	DAT_0000_96D0:WORD
EXTRN	D_1A6A:BYTE
EXTRN	DAT_0000_96D6:WORD
EXTRN	D_1A7E:BYTE
EXTRN	DAT_0000_96DC:WORD
EXTRN	DAT_0000_96E2:WORD
EXTRN	DAT_0000_96E8:WORD
EXTRN	DAT_0000_96EE:WORD
EXTRN	DAT_0000_96F4:WORD
EXTRN	DAT_0000_96FA:WORD
EXTRN	DAT_0000_9700:WORD
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
EXTRN	DAT_0000_97AC:WORD
EXTRN	DAT_0000_97B6:WORD
EXTRN	DAT_0000_97BE:WORD
EXTRN	DAT_0000_97C4:WORD
EXTRN	DAT_0000_97D4:WORD
EXTRN	DAT_0000_97D8:WORD
EXTRN	UNK_0000_B9EE:QWORD
EXTRN	UNK_0000_B9F6:QWORD
EXTRN	UNK_0000_B9FE:BYTE
EXTRN	UNK_0000_B9FF:BYTE
EXTRN	UNK_0000_BA00:BYTE
EXTRN	UNK_0000_BA01:BYTE
EXTRN	UNK_0000_57A8:WORD
EXTRN	UNK_0000_BA02:BYTE
EXTRN	UNK_0000_57AA:WORD
EXTRN	UNK_0000_BA03:QWORD
EXTRN	UNK_0000_57AC:BYTE
EXTRN	UNK_0000_BA0B:BYTE
EXTRN	UNK_0000_57AD:BYTE
EXTRN	UNK_0000_BA0E:BYTE
EXTRN	UNK_0000_57AE:BYTE
EXTRN	UNK_0000_BA0F:BYTE
EXTRN	UNK_0000_57AF:BYTE
EXTRN	UNK_0000_57B0:BYTE
EXTRN	UNK_0000_BA10:BYTE
EXTRN	UNK_0000_57B1:BYTE
EXTRN	UNK_0000_BA11:BYTE
EXTRN	UNK_0000_57B3:BYTE
EXTRN	UNK_0000_BA12:BYTE
EXTRN	UNK_0000_57B4:BYTE
EXTRN	UNK_0000_BA13:BYTE
EXTRN	UNK_0000_57B5:BYTE
EXTRN	D_BA16:BYTE
EXTRN	UNK_0000_57B6:BYTE
EXTRN	UNK_0000_57BA:BYTE
EXTRN	UNK_0000_57BB:BYTE
EXTRN	UNK_0000_57BC:BYTE
EXTRN	UNK_0000_57BD:BYTE
EXTRN	UNK_0000_57BE:BYTE
EXTRN	UNK_0000_57BF:BYTE
EXTRN	DAT_0000_57C0:BYTE
EXTRN	DAT_0000_58F0:BYTE
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 157
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 162
	mov	WORD PTR [bp-4],-1	;local_4
; Line 164
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I273
; Line 165
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 166
	test	BYTE PTR D_BA16[si],128
	je	$I273
; Line 167
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 170
	jmp	SHORT $I279
$I273:
; Line 173
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 174
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 175
	or	ax,ax
	jl	$I279
; Line 176
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 177
	call	FUN_1000_1F12
	or	ax,ax
	je	$I279
; Line 178
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 179
; Line 180
$I279:
; Line 181
; Line 184
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I280
; Line 185
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 186
; Line 188
	jmp	SHORT $I282
	nop	
$I280:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I282
; Line 189
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 190
; Line 193
$I282:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 198
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
; Line 208
	call	FUN_0000_8BCA
; Line 210
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 212
	push	ax
	call	FUN_1000_4E50
; Line 213
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
; Line 214
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 215
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
; Line 217
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 218
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 219
	mov	WORD PTR [bp-4],0	;local_8
; Line 221
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I294
; Line 222
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 224
	sub	si,si
; Line 225
$FC296:
; Line 226
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 227
	inc	si
; Line 228
	cmp	WORD PTR [di],si
	jg	$FC296
; Line 229
; Line 232
	mov	WORD PTR [bp-4],si	;local_8
; Line 233
; Line 235
$I294:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 236
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 237
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 238
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 239
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 240
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
; Line 241
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 242
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 243
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 244
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
; Line 245
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 246
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 247
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 248
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 249
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 250
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 251
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 252
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 253
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 254
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 255
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 256
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 257
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 258
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 259
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 260
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 261
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 265
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 266
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I302
; Line 267
	sub	ax,ax
	jmp	SHORT $EX301
$I302:
; Line 268
; Line 269
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 270
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_1000_1850
; Line 271
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 272
	mov	ax,1
$EX301:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 278
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 282
	call	FUN_1000_4DAA
; Line 284
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 285
	push	ax
	call	FUN_1000_4E50
; Line 286
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
; Line 287
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 288
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 289
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 290
	mov	ax,OFFSET DAT_0000_970E
	push	ax
	call	FUN_1000_1850
; Line 291
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 292
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 294
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 295
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 296
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 297
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 298
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 299
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 301
	jne	$I309
; Line 302
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 303
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 304
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 305
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 306
; Line 308
$I309:
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
; Line 309
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 313
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 314
	call	FUN_1000_4DAA
; Line 315
	mov	ax,OFFSET DAT_0000_9724
	push	ax
	call	FUN_1000_4E50
; Line 316
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
; Line 317
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 318
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
; Line 319
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 320
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 321
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 322
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 323
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 324
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 325
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 326
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 327
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 328
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 329
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I312
; Line 330
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 331
; Line 332
$I312:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 336
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
; Line 340
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
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 344
	mov	WORD PTR [bp-4],13	;local_4
; Line 345
	mov	si,13
$L20000:
; Line 346
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 347
	dec	si
	jne	$L20000
; Line 348
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 349
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 350
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 351
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 352
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 353
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 354
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 355
	mov	WORD PTR [bp-4],si	;local_4
; Line 356
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 357
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 358
	mov	WORD PTR [bp-4],13	;local_4
; Line 359
	mov	si,13
$L20003:
; Line 360
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 361
	dec	si
	jne	$L20003
; Line 362
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 363
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 367
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 368
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 375
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
	jmp	SHORT $EX330
	nop	
$L20004:
	sub	ax,ax
$EX330:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 380
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
; Line 381
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC339:
; Line 382
	dec	si
	js	$L20012
; Line 383
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I342
; Line 384
	cmp	di,255
	je	$FC339
; Line 385
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC339
; Line 387
; Line 390
$I342:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX337
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 396
	mov	ax,-1
$EX337:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 401
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
; Line 402
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC352:
; Line 403
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 404
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I355
; Line 405
	cmp	di,255
	je	$FC352
; Line 406
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC352
; Line 408
; Line 411
$I355:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX350
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 417
	mov	ax,-1
$EX350:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 422
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
; Line 426
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 427
	cmp	al,255
	je	$I366
; Line 428
	or	al,al
	je	$I367
; Line 429
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 430
	jmp	SHORT $I368
	nop	
$I367:
; Line 431
	mov	ax,OFFSET DAT_0000_9778
	push	ax
	call	FUN_1000_1850
; Line 432
$I368:
; Line 433
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I369
; Line 434
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 435
; Line 436
$I369:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 437
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 438
; Line 440
$I366:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I371
; Line 441
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 442
	mov	ax,OFFSET DAT_0000_977C
	push	ax
	call	FUN_1000_1850
; Line 443
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 444
$L20033:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 445
	jmp	SHORT $I376
$I371:
	mov	si,WORD PTR [bp+10]	;param_4
	shl	si,1
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I373
; Line 446
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 447
	mov	ax,OFFSET DAT_0000_9782
	push	ax
	call	FUN_1000_1850
; Line 448
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 449
	mov	ax,WORD PTR D_19B2
	add	ax,si
	push	ax
	jmp	SHORT $L20034
	nop	
$I373:
; Line 450
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I375
; Line 451
	mov	ax,OFFSET DAT_0000_9788
	push	ax
	call	FUN_1000_1850
; Line 452
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 453
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20033
$I375:
; Line 455
; Line 456
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20034:
	call	FUN_1000_1850
; Line 457
$I376:
; Line 460
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 461
	cmp	ax,14
	jge	$I378
;	register si = si
; Line 462
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 463
	add	WORD PTR [bp-4],si	;local_4
; Line 465
$D380:
; Line 466
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 467
	dec	si
; Line 468
	jne	$D380
; Line 469
; Line 470
$I378:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 471
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
; Line 478
	PUBLIC	FUN_ZSTATS__01E8C8
FUN_ZSTATS__01E8C8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,18
	push	di
	push	si
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
;	param_4 = 10
; Line 487
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 488
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 489
	mov	WORD PTR [bp-4],0	;local_8
; Line 490
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 491
	cmp	ax,-1
	je	$JCC1823
	jmp	$I459
$JCC1823:
; Line 492
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 493
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 494
	mov	ax,OFFSET DAT_0000_9794
	push	ax
	call	FUN_1000_1850
; Line 495
	call	FUN_1000_4DAA
; Line 496
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 497
	call	FUN_1000_266C
	jmp	$EX388
	nop	
$FC401:
; Line 501
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 502
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 506
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20035
$FC404:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
$L20035:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB405
; Line 508
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	FUN_ZSTATS__01E7C2
; Line 510
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 511
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC404
; Line 512
$FB405:
; Line 516
	mov	WORD PTR [bp-8],0	;local_10
; Line 517
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I407
; Line 518
	mov	WORD PTR [bp-8],2	;local_10
; Line 519
; Line 522
$I407:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I408
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I408
; Line 523
	inc	WORD PTR [bp-8]	;local_10
; Line 524
; Line 527
$I408:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC413
	cmp	ax,1
	je	$SC414
	cmp	ax,2
	je	$SC416
	cmp	ax,3
	je	$SC417
	jmp	SHORT $SB410
$SC413:
; Line 529
	call	FUN_1000_4DAA
; Line 531
$SB410:
; Line 545
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 546
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 547
	cmp	ax,32
	jne	$I418
	jmp	$L20039
$SC414:
; Line 533
	mov	ax,25
$L20036:
	push	ax
	call	FUN_1000_4DEA
; Line 535
	jmp	SHORT $SB410
	nop	
$SC416:
; Line 537
	mov	ax,24
	jmp	SHORT $L20036
	nop	
$SC417:
; Line 540
	mov	ax,18
	jmp	SHORT $L20036
	nop	
$I418:
; Line 551
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2078
	jmp	$I420
$JCC2078:
; Line 553
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I421
; Line 555
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I422
; Line 556
	mov	WORD PTR [bp-12],7	;local_4
; Line 557
	jmp	SHORT $I423
	nop	
$I422:
; Line 559
	mov	WORD PTR [bp-12],1	;local_4
; Line 560
$I423:
; Line 562
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2118
	jmp	$I459
$JCC2118:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 563
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I427
; Line 564
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 565
; Line 566
$I427:
	dec	di
	jne	$L20016
$L20043:
	mov	WORD PTR [bp-2],si	;local_6
; Line 567
	jmp	$I459
$I421:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I428
; Line 571
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2186
	jmp	$I459
$JCC2186:
; Line 573
	cmp	WORD PTR [bp-14],2	;local_e
$L20041:
	jle	$JCC2195
	jmp	$I459
$JCC2195:
; Line 575
$L20039:
	mov	WORD PTR [bp-4],1	;local_8
; Line 576
	jmp	$I459
$I428:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I431
; Line 585
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I432
; Line 586
	mov	WORD PTR [bp-12],7	;local_4
; Line 587
	jmp	SHORT $I433
$I432:
; Line 588
	mov	WORD PTR [bp-12],1	;local_4
; Line 589
$I433:
; Line 591
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2242
	jmp	$I459
$JCC2242:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 592
	cmp	si,-1
	je	$I437
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I437
; Line 593
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 594
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 595
; Line 596
$I437:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20044:
	mov	WORD PTR [bp-10],si	;local_c
; Line 597
	jmp	$I459
$I431:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2328
	jmp	$I459
$JCC2328:
	jmp	$L20039
$I420:
; Line 606
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I440
; Line 608
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 609
	jmp	$I459
$I440:
; Line 610
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I442
; Line 611
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2377
	jmp	$I459
$JCC2377:
; Line 612
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20041
	nop	
$I442:
; Line 620
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I446
; Line 622
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	di,ax
; Line 623
	sub	si,si
; Line 625
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$L20021
; Line 627
	mov	di,WORD PTR [bp-10]	;local_c
; Line 628
	inc	si
; Line 629
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 630
	jmp	$I459
$I446:
; Line 631
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I451
; Line 634
	jne	$I452
; Line 635
	mov	WORD PTR [bp-12],7	;local_4
; Line 636
	jmp	SHORT $I453
$I452:
; Line 638
	mov	WORD PTR [bp-12],1	;local_4
; Line 639
$I453:
; Line 641
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2482
	jmp	$I459
$JCC2482:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 642
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I457
; Line 643
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 644
; Line 645
$I457:
	dec	di
	jne	$L20022
	jmp	$L20043
	nop	
$I451:
; Line 647
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I459
; Line 650
	jne	$I460
; Line 651
	mov	WORD PTR [bp-12],7	;local_4
; Line 652
	jmp	SHORT $I461
$I460:
; Line 653
	mov	WORD PTR [bp-12],1	;local_4
; Line 654
$I461:
; Line 655
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I459
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 656
	cmp	si,-1
	je	$I465
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I465
; Line 657
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 658
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 659
; Line 660
$I465:
	dec	WORD PTR [bp-18]
	jne	$L20024
	jmp	$L20044
$I459:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2648
	jmp	$FC401
$JCC2648:
; Line 666
; Line 668
	mov	ax,WORD PTR [bp-14]	;local_e
$EX388:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E8C8	ENDP
; Line 673
	PUBLIC	FUN_ZSTATS__01EB7A
FUN_ZSTATS__01EB7A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 676
	sub	si,si
; Line 677
$D469:
; Line 678
	mov	al,BYTE PTR UNK_0000_5820[si]
	mov	BYTE PTR UNK_0000_B9EE[si],al
; Line 679
	mov	al,BYTE PTR UNK_0000_5828[si]
	mov	BYTE PTR UNK_0000_B9F6[si],al
; Line 680
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
; Line 681
	inc	si
	cmp	si,8
	jl	$D469
	mov	WORD PTR [bp-2],si	;local_4
; Line 683
	mov	al,UNK_0000_57B0
	mov	UNK_0000_B9FE,al
; Line 684
	mov	al,UNK_0000_57B1
	mov	UNK_0000_B9FF,al
; Line 685
	mov	al,UNK_0000_57B3
	mov	UNK_0000_BA00,al
; Line 686
	mov	al,UNK_0000_57B4
	mov	UNK_0000_BA01,al
; Line 687
	mov	al,UNK_0000_57B5
	mov	UNK_0000_BA02,al
; Line 689
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET UNK_0000_BA0B
	mov	si,OFFSET UNK_0000_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 693
	mov	al,UNK_0000_57BA
	mov	UNK_0000_BA0E,al
; Line 694
	cmp	BYTE PTR UNK_0000_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	UNK_0000_BA0F,al
; Line 695
	mov	al,UNK_0000_57BC
	mov	UNK_0000_BA10,al
; Line 696
	mov	al,UNK_0000_57BD
	mov	UNK_0000_BA11,al
; Line 697
	mov	al,UNK_0000_57BE
	mov	UNK_0000_BA12,al
; Line 698
	mov	al,UNK_0000_57BF
	mov	UNK_0000_BA13,al
; Line 699
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EB7A	ENDP
; Line 703
	PUBLIC	FUN_ZSTATS__01EC1A
FUN_ZSTATS__01EC1A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 708
	mov	ax,1
	push	ax
	call	FUN_ZSTATS__01E1E0
	mov	WORD PTR [bp-4],ax	;local_8
; Line 709
	cmp	ax,-2
	jne	$I481
; Line 710
	mov	WORD PTR [bp-4],6	;local_8
; Line 711
	jmp	SHORT $I482
	nop	
$I481:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2860
	jmp	$EX476
$JCC2860:
; Line 712
$I482:
	mov	ax,-26718
	push	ax
	call	FUN_1000_1850
; Line 716
	call	FUN_ZSTATS__01EB7A
; Line 717
	call	FUN_1000_4EFC
; Line 718
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 719
	mov	BYTE PTR [bp-2],0	;local_6
; Line 722
$D485:
; Line 723
; Line 724
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2894
	jmp	$I491
$JCC2894:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2903
	jmp	$I491
$JCC2903:
; Line 725
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I493
	cmp	al,1
	jne	$I492
$I493:
; Line 726
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I494
; Line 727
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20046:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 728
; Line 729
	jmp	SHORT $I508
	nop	
$I494:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I496
; Line 730
	mov	WORD PTR [bp-6],16	;local_4
; Line 731
; Line 732
	jmp	SHORT $I508
	nop	
$I496:
; Line 733
	dec	WORD PTR [bp-6]	;local_4
; Line 734
; Line 735
	jmp	SHORT $I508
	nop	
$I492:
; Line 736
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I500
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I499
$I500:
; Line 737
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I506
; Line 738
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I502
; Line 739
	inc	WORD PTR [bp-6]	;local_4
; Line 740
	jmp	SHORT $I508
$I502:
; Line 741
	mov	WORD PTR [bp-6],0	;local_4
; Line 742
; Line 743
	jmp	SHORT $I508
	nop	
$I499:
; Line 745
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I506
; Line 746
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I506
; Line 747
	jbe	$I508
	cmp	BYTE PTR [bp-2],55	;local_6
	jae	$I508
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	mov	si,ax
	lea	ax,WORD PTR [si-49]
	mov	bx,22619
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	cmp	ax,cx
	jae	$I508
; Line 748
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20046
$I506:
; Line 753
	mov	WORD PTR [bp-6],12	;local_4
; Line 754
; Line 755
$I508:
; Line 763
; Line 766
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 767
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I512
; Line 768
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I513
; Line 769
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E262
; Line 770
	jmp	SHORT $L20045
	nop	
$I491:
; Line 755
; Line 756
	call	FUN_1000_4DAA
; Line 757
	call	FUN_1000_4E20
; Line 758
	call	FUN_1000_4F3C
; Line 759
	call	FUN_1000_2900
; Line 760
	mov	ax,-26674
	push	ax
	call	FUN_1000_1850
; Line 761
	jmp	$EX476
$I513:
; Line 770
; Line 771
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E488
; Line 772
	jmp	SHORT $L20045
	nop	
$I512:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I515
; Line 780
	call	FUN_ZSTATS__01E57C
; Line 783
$L20045:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 784
	call	FUN_1000_266C
	jmp	SHORT $L20049
	nop	
$I515:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I516
; Line 790
	mov	ax,OFFSET DAT_0000_97AC
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET DAT_0000_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20051
	nop	
$I516:
; Line 791
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I518
; Line 792
	mov	ax,OFFSET DAT_0000_97B6
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20051
	nop	
$I518:
; Line 793
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I520
; Line 794
	mov	ax,OFFSET DAT_0000_97BE
	push	ax
	mov	ax,38
	push	ax
	mov	ax,OFFSET UNK_0000_B9EE
	push	ax
	mov	ax,OFFSET D_1916
$L20051:
	push	ax
	call	FUN_ZSTATS__01E8C8
$L20049:
	mov	BYTE PTR [bp-2],al	;local_6
; Line 795
	jmp	$D485
	nop	
$I520:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3236
	jmp	$D485
$JCC3236:
; Line 796
	mov	ax,OFFSET DAT_0000_97C4
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20051
$EX476:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EC1A	ENDP
; Line 803
	PUBLIC	FUN_ZSTATS__01EDCE
FUN_ZSTATS__01EDCE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 804
	mov	ax,OFFSET DAT_0000_97D4
	push	ax
	call	FUN_1000_1850
; Line 805
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850
; Line 806
	mov	ax,OFFSET DAT_0000_97D8
	push	ax
	call	FUN_1000_1850
; Line 807
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDCE	ENDP
; Line 811
	PUBLIC	FUN_ZSTATS__01EDEA
FUN_ZSTATS__01EDEA	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 812
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;s
; Line 814
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I530
	cmp	BYTE PTR [bx+28],255
	jne	$I530
; Line 815
	mov	ax,2
	jmp	SHORT $EX528
	nop	
$I530:
; Line 816
	cmp	BYTE PTR [bx+27],255
	jne	$I532
; Line 817
	sub	ax,ax
	jmp	SHORT $EX528
$I532:
; Line 818
	cmp	BYTE PTR [bx+28],255
	jne	$I534
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	BYTE PTR D_1A7E[bx],48
	je	$I534
; Line 819
	mov	ax,1
	jmp	SHORT $EX528
	nop	
$I534:
; Line 820
; Line 821
	mov	ax,255
$EX528:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01EDEA	ENDP
_TEXT	ENDS
END
