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
EXTRN	FUN_1000_4E20:NEAR
EXTRN	FUN_1000_1BF2:NEAR
EXTRN	FUN_1000_4F3C:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	UNK_0000_5820:QWORD
EXTRN	UNK_0000_5828:QWORD
EXTRN	D_1916:BYTE
EXTRN	UNK_0000_5840:QWORD
EXTRN	D_1A44:BYTE
EXTRN	DAT_0000_5850:BYTE
EXTRN	D_1A58:BYTE
EXTRN	UNK_0000_5893:BYTE
EXTRN	D_1962:BYTE
EXTRN	D_1A6A:BYTE
EXTRN	UNK_0000_589E:BYTE
_BSS      SEGMENT
COMM NEAR	D_19B2:	BYTE:	 2
EXTRN	D_55A8:WORD
EXTRN	D_19D2:BYTE
EXTRN	DAT_0000_96B4:WORD
EXTRN	D_19E2:BYTE
EXTRN	DAT_0000_96BE:WORD
EXTRN	DAT_0000_96C6:WORD
EXTRN	DAT_0000_96D0:WORD
EXTRN	DAT_0000_96D6:WORD
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
EXTRN	UNK_0000_B9EE:QWORD
EXTRN	UNK_0000_B9F6:QWORD
EXTRN	UNK_0000_B9FE:BYTE
EXTRN	UNK_0000_B9FF:BYTE
EXTRN	UNK_0000_BA00:BYTE
EXTRN	UNK_0000_BA01:BYTE
EXTRN	UNK_0000_BA02:BYTE
EXTRN	UNK_0000_BA03:QWORD
EXTRN	UNK_0000_57A8:WORD
EXTRN	UNK_0000_BA0B:BYTE
EXTRN	UNK_0000_57AA:WORD
EXTRN	UNK_0000_BA0E:BYTE
EXTRN	UNK_0000_57AC:BYTE
EXTRN	UNK_0000_BA0F:BYTE
EXTRN	UNK_0000_57AD:BYTE
EXTRN	UNK_0000_BA10:BYTE
EXTRN	UNK_0000_57AE:BYTE
EXTRN	UNK_0000_BA11:BYTE
EXTRN	UNK_0000_57AF:BYTE
EXTRN	UNK_0000_57B0:BYTE
EXTRN	UNK_0000_BA12:BYTE
EXTRN	UNK_0000_57B1:BYTE
EXTRN	UNK_0000_BA13:BYTE
EXTRN	UNK_0000_57B3:BYTE
EXTRN	D_BA16:BYTE
EXTRN	UNK_0000_57B4:BYTE
EXTRN	UNK_0000_57B5:BYTE
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
; Line 153
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 158
	mov	WORD PTR [bp-4],-1	;local_4
; Line 160
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I270
; Line 161
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 162
	test	BYTE PTR D_BA16[si],128
	je	$I270
; Line 163
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 166
	jmp	SHORT $I276
$I270:
; Line 169
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 170
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 171
	or	ax,ax
	jl	$I276
; Line 172
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 173
	call	FUN_1000_1F12
	or	ax,ax
	je	$I276
; Line 174
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 175
; Line 176
$I276:
; Line 177
; Line 180
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I277
; Line 181
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 182
; Line 184
	jmp	SHORT $I279
	nop	
$I277:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I279
; Line 185
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 186
; Line 189
$I279:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 194
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
; Line 204
	call	FUN_0000_8BCA
; Line 206
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 208
	push	ax
	call	FUN_1000_4E50
; Line 209
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
; Line 210
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 211
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
; Line 213
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 214
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 215
	mov	WORD PTR [bp-4],0	;local_8
; Line 217
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I291
; Line 218
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 220
	sub	si,si
; Line 221
$FC293:
; Line 222
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 223
	inc	si
; Line 224
	cmp	WORD PTR [di],si
	jg	$FC293
; Line 225
; Line 228
	mov	WORD PTR [bp-4],si	;local_8
; Line 229
; Line 231
$I291:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 232
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 233
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 234
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 235
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 236
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
; Line 237
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 238
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 239
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 240
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
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 242
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 243
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 244
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 245
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 246
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 247
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 248
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 249
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 250
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 251
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 252
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 253
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 254
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 255
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 256
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 257
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 261
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 262
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I299
; Line 263
	sub	ax,ax
	jmp	SHORT $EX298
$I299:
; Line 264
; Line 265
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 266
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_1000_1850
; Line 267
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 268
	mov	ax,1
$EX298:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 274
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 278
	call	FUN_1000_4DAA
; Line 280
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 281
	push	ax
	call	FUN_1000_4E50
; Line 282
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
; Line 283
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 284
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 285
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 286
	mov	ax,OFFSET DAT_0000_970E
	push	ax
	call	FUN_1000_1850
; Line 287
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 288
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 290
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 291
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 292
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 293
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 294
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 295
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 297
	jne	$I306
; Line 298
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 299
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 300
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 301
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 302
; Line 304
$I306:
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
; Line 305
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 309
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 310
	call	FUN_1000_4DAA
; Line 311
	mov	ax,OFFSET DAT_0000_9724
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
; Line 315
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 316
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 317
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 318
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 319
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 320
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 321
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 322
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 323
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 324
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 325
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I309
; Line 326
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 327
; Line 328
$I309:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 332
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
; Line 336
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
; Line 337
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 338
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
; Line 339
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 340
	mov	WORD PTR [bp-4],13	;local_4
; Line 341
	mov	si,13
$L20000:
; Line 342
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 343
	dec	si
	jne	$L20000
; Line 344
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 345
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 346
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 347
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 348
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 349
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 350
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 351
	mov	WORD PTR [bp-4],si	;local_4
; Line 352
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 353
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 354
	mov	WORD PTR [bp-4],13	;local_4
; Line 355
	mov	si,13
$L20003:
; Line 356
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 357
	dec	si
	jne	$L20003
; Line 358
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 359
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 363
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 364
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 371
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
	jmp	SHORT $EX327
	nop	
$L20004:
	sub	ax,ax
$EX327:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 376
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
; Line 377
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC336:
; Line 378
	dec	si
	js	$L20012
; Line 379
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I339
; Line 380
	cmp	di,255
	je	$FC336
; Line 381
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC336
; Line 383
; Line 386
$I339:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX334
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 392
	mov	ax,-1
$EX334:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 397
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
; Line 398
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC349:
; Line 399
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
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
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX347
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 413
	mov	ax,-1
$EX347:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 418
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
; Line 422
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 423
	cmp	al,255
	je	$I363
; Line 424
	or	al,al
	je	$I364
; Line 425
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 426
	jmp	SHORT $I365
	nop	
$I364:
; Line 427
	mov	ax,OFFSET DAT_0000_9778
	push	ax
	call	FUN_1000_1850
; Line 428
$I365:
; Line 429
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I366
; Line 430
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 431
; Line 432
$I366:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 433
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 434
; Line 436
$I363:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I368
; Line 437
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 438
	mov	ax,OFFSET DAT_0000_977C
	push	ax
	call	FUN_1000_1850
; Line 439
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 440
$L20033:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 441
	jmp	SHORT $I373
$I368:
	mov	si,WORD PTR [bp+10]	;param_4
	shl	si,1
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I370
; Line 442
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 443
	mov	ax,OFFSET DAT_0000_9782
	push	ax
	call	FUN_1000_1850
; Line 444
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 445
	mov	ax,WORD PTR D_19B2
	add	ax,si
	push	ax
	jmp	SHORT $L20034
	nop	
$I370:
; Line 446
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I372
; Line 447
	mov	ax,OFFSET DAT_0000_9788
	push	ax
	call	FUN_1000_1850
; Line 448
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 449
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20033
$I372:
; Line 451
; Line 452
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20034:
	call	FUN_1000_1850
; Line 453
$I373:
; Line 456
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 457
	cmp	ax,14
	jge	$I375
;	register si = si
; Line 458
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 459
	add	WORD PTR [bp-4],si	;local_4
; Line 461
$D377:
; Line 462
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 463
	dec	si
; Line 464
	jne	$D377
; Line 465
; Line 466
$I375:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 467
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
; Line 474
	PUBLIC	FUN_ZSTATS__01E8C8
FUN_ZSTATS__01E8C8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,18
	push	di
	push	si
;	local_10 = -8
;	local_e = -14
;	local_c = -10
;	local_a = -6
;	local_8 = -4
;	local_6 = -2
;	local_4 = -12
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
; Line 483
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 484
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 485
	mov	WORD PTR [bp-4],0	;local_8
; Line 486
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 487
	cmp	ax,-1
	je	$JCC1823
	jmp	$I456
$JCC1823:
; Line 488
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 489
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 490
	mov	ax,OFFSET DAT_0000_9794
	push	ax
	call	FUN_1000_1850
; Line 491
	call	FUN_1000_4DAA
; Line 492
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 493
	call	FUN_1000_266C
	jmp	$EX385
	nop	
$FC398:
; Line 497
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 498
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 502
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20035
$FC401:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
$L20035:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB402
; Line 504
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	FUN_ZSTATS__01E7C2
; Line 506
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 507
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC401
; Line 508
$FB402:
; Line 512
	mov	WORD PTR [bp-8],0	;local_10
; Line 513
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I404
; Line 514
	mov	WORD PTR [bp-8],2	;local_10
; Line 515
; Line 518
$I404:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I405
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I405
; Line 519
	inc	WORD PTR [bp-8]	;local_10
; Line 520
; Line 523
$I405:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC410
	cmp	ax,1
	je	$SC411
	cmp	ax,2
	je	$SC413
	cmp	ax,3
	je	$SC414
	jmp	SHORT $SB407
$SC410:
; Line 525
	call	FUN_1000_4DAA
; Line 527
$SB407:
; Line 541
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 542
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 543
	cmp	ax,32
	jne	$I415
	jmp	$L20039
$SC411:
; Line 529
	mov	ax,25
$L20036:
	push	ax
	call	FUN_1000_4DEA
; Line 531
	jmp	SHORT $SB407
	nop	
$SC413:
; Line 533
	mov	ax,24
	jmp	SHORT $L20036
	nop	
$SC414:
; Line 536
	mov	ax,18
	jmp	SHORT $L20036
	nop	
$I415:
; Line 547
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2078
	jmp	$I417
$JCC2078:
; Line 549
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I418
; Line 551
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I419
; Line 552
	mov	WORD PTR [bp-12],7	;local_4
; Line 553
	jmp	SHORT $I420
	nop	
$I419:
; Line 555
	mov	WORD PTR [bp-12],1	;local_4
; Line 556
$I420:
; Line 558
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2118
	jmp	$I456
$JCC2118:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 559
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I424
; Line 560
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 561
; Line 562
$I424:
	dec	di
	jne	$L20016
$L20043:
	mov	WORD PTR [bp-2],si	;local_6
; Line 563
	jmp	$I456
$I418:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I425
; Line 567
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2186
	jmp	$I456
$JCC2186:
; Line 569
	cmp	WORD PTR [bp-14],2	;local_e
$L20041:
	jle	$JCC2195
	jmp	$I456
$JCC2195:
; Line 571
$L20039:
	mov	WORD PTR [bp-4],1	;local_8
; Line 572
	jmp	$I456
$I425:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I428
; Line 581
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I429
; Line 582
	mov	WORD PTR [bp-12],7	;local_4
; Line 583
	jmp	SHORT $I430
$I429:
; Line 584
	mov	WORD PTR [bp-12],1	;local_4
; Line 585
$I430:
; Line 587
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2242
	jmp	$I456
$JCC2242:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 588
	cmp	si,-1
	je	$I434
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I434
; Line 589
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 590
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 591
; Line 592
$I434:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20044:
	mov	WORD PTR [bp-10],si	;local_c
; Line 593
	jmp	$I456
$I428:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2328
	jmp	$I456
$JCC2328:
	jmp	$L20039
$I417:
; Line 602
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I437
; Line 604
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 605
	jmp	$I456
$I437:
; Line 606
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I439
; Line 607
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2377
	jmp	$I456
$JCC2377:
; Line 608
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20041
	nop	
$I439:
; Line 616
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I443
; Line 618
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	di,ax
; Line 619
	sub	si,si
; Line 621
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$L20021
; Line 623
	mov	di,WORD PTR [bp-10]	;local_c
; Line 624
	inc	si
; Line 625
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 626
	jmp	$I456
$I443:
; Line 627
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I448
; Line 630
	jne	$I449
; Line 631
	mov	WORD PTR [bp-12],7	;local_4
; Line 632
	jmp	SHORT $I450
$I449:
; Line 634
	mov	WORD PTR [bp-12],1	;local_4
; Line 635
$I450:
; Line 637
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2482
	jmp	$I456
$JCC2482:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 638
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I454
; Line 639
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 640
; Line 641
$I454:
	dec	di
	jne	$L20022
	jmp	$L20043
	nop	
$I448:
; Line 643
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I456
; Line 646
	jne	$I457
; Line 647
	mov	WORD PTR [bp-12],7	;local_4
; Line 648
	jmp	SHORT $I458
$I457:
; Line 649
	mov	WORD PTR [bp-12],1	;local_4
; Line 650
$I458:
; Line 651
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I456
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 652
	cmp	si,-1
	je	$I462
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I462
; Line 653
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 654
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 655
; Line 656
$I462:
	dec	WORD PTR [bp-18]
	jne	$L20024
	jmp	$L20044
$I456:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2648
	jmp	$FC398
$JCC2648:
; Line 662
; Line 664
	mov	ax,WORD PTR [bp-14]	;local_e
$EX385:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E8C8	ENDP
; Line 669
	PUBLIC	FUN_ZSTATS__01EB7A
FUN_ZSTATS__01EB7A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 672
	sub	si,si
; Line 673
$D466:
; Line 674
	mov	al,BYTE PTR UNK_0000_5820[si]
	mov	BYTE PTR UNK_0000_B9EE[si],al
; Line 675
	mov	al,BYTE PTR UNK_0000_5828[si]
	mov	BYTE PTR UNK_0000_B9F6[si],al
; Line 676
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
; Line 677
	inc	si
	cmp	si,8
	jl	$D466
	mov	WORD PTR [bp-2],si	;local_4
; Line 679
	mov	al,UNK_0000_57B0
	mov	UNK_0000_B9FE,al
; Line 680
	mov	al,UNK_0000_57B1
	mov	UNK_0000_B9FF,al
; Line 681
	mov	al,UNK_0000_57B3
	mov	UNK_0000_BA00,al
; Line 682
	mov	al,UNK_0000_57B4
	mov	UNK_0000_BA01,al
; Line 683
	mov	al,UNK_0000_57B5
	mov	UNK_0000_BA02,al
; Line 685
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET UNK_0000_BA0B
	mov	si,OFFSET UNK_0000_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 689
	mov	al,UNK_0000_57BA
	mov	UNK_0000_BA0E,al
; Line 690
	cmp	BYTE PTR UNK_0000_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	UNK_0000_BA0F,al
; Line 691
	mov	al,UNK_0000_57BC
	mov	UNK_0000_BA10,al
; Line 692
	mov	al,UNK_0000_57BD
	mov	UNK_0000_BA11,al
; Line 693
	mov	al,UNK_0000_57BE
	mov	UNK_0000_BA12,al
; Line 694
	mov	al,UNK_0000_57BF
	mov	UNK_0000_BA13,al
; Line 695
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EB7A	ENDP
; Line 699
	PUBLIC	FUN_ZSTATS__01EC1A
FUN_ZSTATS__01EC1A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 704
	mov	ax,1
	push	ax
	call	FUN_ZSTATS__01E1E0
	mov	WORD PTR [bp-4],ax	;local_8
; Line 705
	cmp	ax,-2
	jne	$I478
; Line 706
	mov	WORD PTR [bp-4],6	;local_8
; Line 707
	jmp	SHORT $I479
	nop	
$I478:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2860
	jmp	$EX473
$JCC2860:
; Line 708
$I479:
	mov	ax,-26718
	push	ax
	call	FUN_1000_1850
; Line 712
	call	FUN_ZSTATS__01EB7A
; Line 713
	call	FUN_1000_4EFC
; Line 714
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 715
	mov	BYTE PTR [bp-2],0	;local_6
; Line 718
$D482:
; Line 719
; Line 720
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2894
	jmp	$I488
$JCC2894:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2903
	jmp	$I488
$JCC2903:
; Line 721
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I490
	cmp	al,1
	jne	$I489
$I490:
; Line 722
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I491
; Line 723
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20046:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 724
; Line 725
	jmp	SHORT $I505
	nop	
$I491:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I493
; Line 726
	mov	WORD PTR [bp-6],16	;local_4
; Line 727
; Line 728
	jmp	SHORT $I505
	nop	
$I493:
; Line 729
	dec	WORD PTR [bp-6]	;local_4
; Line 730
; Line 731
	jmp	SHORT $I505
	nop	
$I489:
; Line 732
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I497
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I496
$I497:
; Line 733
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I503
; Line 734
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I499
; Line 735
	inc	WORD PTR [bp-6]	;local_4
; Line 736
	jmp	SHORT $I505
$I499:
; Line 737
	mov	WORD PTR [bp-6],0	;local_4
; Line 738
; Line 739
	jmp	SHORT $I505
	nop	
$I496:
; Line 741
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I503
; Line 742
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I503
; Line 743
	jbe	$I505
	cmp	BYTE PTR [bp-2],55	;local_6
	jae	$I505
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	mov	si,ax
	lea	ax,WORD PTR [si-49]
	mov	bx,22619
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	cmp	ax,cx
	jae	$I505
; Line 744
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20046
$I503:
; Line 749
	mov	WORD PTR [bp-6],12	;local_4
; Line 750
; Line 751
$I505:
; Line 759
; Line 762
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 763
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I509
; Line 764
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I510
; Line 765
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E262
; Line 766
	jmp	SHORT $L20045
	nop	
$I488:
; Line 751
; Line 752
	call	FUN_1000_4DAA
; Line 753
	call	FUN_1000_4E20
; Line 754
	call	FUN_1000_4F3C
; Line 755
	call	FUN_1000_2900
; Line 756
	mov	ax,-26674
	push	ax
	call	FUN_1000_1850
; Line 757
	jmp	$EX473
$I510:
; Line 766
; Line 767
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	FUN_ZSTATS__01E488
; Line 768
	jmp	SHORT $L20045
	nop	
$I509:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I512
; Line 776
	call	FUN_ZSTATS__01E57C
; Line 779
$L20045:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 780
	call	FUN_1000_266C
	jmp	SHORT $L20049
	nop	
$I512:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I513
; Line 786
	mov	ax,OFFSET DAT_0000_97AC
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET DAT_0000_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20051
	nop	
$I513:
; Line 787
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I515
; Line 788
	mov	ax,OFFSET DAT_0000_97B6
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20051
	nop	
$I515:
; Line 789
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I517
; Line 790
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
; Line 791
	jmp	$D482
	nop	
$I517:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3236
	jmp	$D482
$JCC3236:
; Line 792
	mov	ax,OFFSET DAT_0000_97C4
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET DAT_0000_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20051
$EX473:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

FUN_ZSTATS__01EC1A	ENDP
_TEXT	ENDS
END
