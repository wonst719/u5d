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
EXTRN	FUN_1000_4E50:NEAR
EXTRN	FUN_1000_1B94:NEAR
EXTRN	FUN_1000_266C:NEAR
EXTRN	FUN_1000_1F12:NEAR
EXTRN	FUN_1000_4DEA:NEAR
EXTRN	FUN_0000_8BCA:NEAR
EXTRN	FUN_1000_4D76:NEAR
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
EXTRN	D_1A44:BYTE
EXTRN	D_1A58:BYTE
EXTRN	D_1962:BYTE
EXTRN	D_1A6A:BYTE
_BSS      SEGMENT
COMM NEAR	D_19B2:	BYTE:	 2
EXTRN	D_BA16:BYTE
EXTRN	UNK_0000_57A8:WORD
EXTRN	UNK_0000_57AA:WORD
EXTRN	UNK_0000_57AC:BYTE
EXTRN	UNK_0000_57AD:BYTE
EXTRN	UNK_0000_57AE:BYTE
EXTRN	UNK_0000_57AF:BYTE
EXTRN	UNK_0000_5893:BYTE
EXTRN	UNK_0000_589E:BYTE
EXTRN	D_55A8:WORD
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
EXTRN	DAT_0000_96FA:WORD
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 104
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 109
	mov	WORD PTR [bp-4],-1	;local_4
; Line 111
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I227
; Line 112
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 113
	test	BYTE PTR D_BA16[si],128
	je	$I227
; Line 114
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 117
	jmp	SHORT $I233
$I227:
; Line 120
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 121
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 122
	or	ax,ax
	jl	$I233
; Line 123
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 124
	call	FUN_1000_1F12
	or	ax,ax
	je	$I233
; Line 125
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 126
; Line 127
$I233:
; Line 128
; Line 131
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I234
; Line 132
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 133
; Line 135
	jmp	SHORT $I236
	nop	
$I234:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I236
; Line 136
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 137
; Line 140
$I236:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 145
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
; Line 155
	call	FUN_0000_8BCA
; Line 157
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 159
	push	ax
	call	FUN_1000_4E50
; Line 160
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
; Line 161
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 162
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
; Line 164
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 165
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 166
	mov	WORD PTR [bp-4],0	;local_8
; Line 168
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I248
; Line 169
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 171
	sub	si,si
; Line 172
$FC250:
; Line 173
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 174
	inc	si
; Line 175
	cmp	WORD PTR [di],si
	jg	$FC250
; Line 176
; Line 179
	mov	WORD PTR [bp-4],si	;local_8
; Line 180
; Line 182
$I248:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 183
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 184
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 185
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 186
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 187
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
; Line 188
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 189
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 190
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 191
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
; Line 192
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 193
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 194
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 195
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 196
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 197
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 198
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 199
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 200
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 201
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 202
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 203
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 204
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 205
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 206
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 207
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 208
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 212
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 213
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I256
; Line 214
	sub	ax,ax
	jmp	SHORT $EX255
$I256:
; Line 215
; Line 216
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 217
	mov	ax,WORD PTR [bp+4]	;param_1
	shl	ax,1
	add	ax,OFFSET D_1962
	push	ax
	call	FUN_1000_1850
; Line 218
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 219
	mov	ax,1
$EX255:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 225
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 229
	call	FUN_1000_4DAA
; Line 231
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 232
	push	ax
	call	FUN_1000_4E50
; Line 233
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
; Line 234
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 235
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 236
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 237
	mov	ax,OFFSET DAT_0000_970E
	push	ax
	call	FUN_1000_1850
; Line 238
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 239
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 241
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 242
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 243
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 244
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 245
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 246
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 248
	jne	$I263
; Line 249
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 250
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 251
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 252
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 253
; Line 255
$I263:
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
; Line 256
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 260
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 261
	call	FUN_1000_4DAA
; Line 262
	mov	ax,OFFSET DAT_0000_9724
	push	ax
	call	FUN_1000_4E50
; Line 263
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
; Line 264
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 265
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
; Line 266
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 267
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 268
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 269
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 270
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 271
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 272
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 273
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 274
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 275
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 276
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I266
; Line 277
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 278
; Line 279
$I266:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 283
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
; Line 287
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
; Line 288
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 289
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
; Line 290
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 291
	mov	WORD PTR [bp-4],13	;local_4
; Line 292
	mov	si,13
$L20000:
; Line 293
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 294
	dec	si
	jne	$L20000
; Line 295
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 296
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 297
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 298
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 299
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 300
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 301
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 302
	mov	WORD PTR [bp-4],si	;local_4
; Line 303
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 304
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 305
	mov	WORD PTR [bp-4],13	;local_4
; Line 306
	mov	si,13
$L20003:
; Line 307
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 308
	dec	si
	jne	$L20003
; Line 309
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 310
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 314
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 315
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 322
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
	jmp	SHORT $EX284
	nop	
$L20004:
	sub	ax,ax
$EX284:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 327
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
; Line 328
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC293:
; Line 329
	dec	si
	js	$L20012
; Line 330
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I296
; Line 331
	cmp	di,255
	je	$FC293
; Line 332
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC293
; Line 334
; Line 337
$I296:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX291
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 343
	mov	ax,-1
$EX291:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 348
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
; Line 349
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC306:
; Line 350
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 351
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I309
; Line 352
	cmp	di,255
	je	$FC306
; Line 353
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC306
; Line 355
; Line 358
$I309:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX304
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 364
	mov	ax,-1
$EX304:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 373
	PUBLIC	FUN_ZSTATS__01E7C2
FUN_ZSTATS__01E7C2	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	di
	push	si
;	local_6 = -2
;	local_4 = -4
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
; Line 377
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 378
	cmp	al,255
	je	$I323
; Line 379
	or	al,al
	je	$I324
; Line 380
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 381
	jmp	SHORT $I325
	nop	
$I324:
; Line 382
	mov	ax,OFFSET DAT_0000_9778
	push	ax
	call	FUN_1000_1850
; Line 383
$I325:
; Line 384
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I326
; Line 385
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 386
; Line 387
$I326:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 388
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 389
; Line 391
$I323:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I328
; Line 392
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 393
	mov	ax,OFFSET DAT_0000_977C
	push	ax
	call	FUN_1000_1850
; Line 394
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 395
$L20026:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 396
	jmp	SHORT $I333
$I328:
	mov	si,WORD PTR [bp+10]	;param_4
	shl	si,1
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I330
; Line 397
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 398
	mov	ax,OFFSET DAT_0000_9782
	push	ax
	call	FUN_1000_1850
; Line 399
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 400
	mov	ax,WORD PTR D_19B2
	add	ax,si
	push	ax
	jmp	SHORT $L20027
	nop	
$I330:
; Line 401
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I332
; Line 402
	mov	ax,OFFSET DAT_0000_9788
	push	ax
	call	FUN_1000_1850
; Line 403
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 404
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20026
$I332:
; Line 406
; Line 407
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20027:
	call	FUN_1000_1850
; Line 408
$I333:
; Line 411
	call	FUN_1000_1F12
	mov	WORD PTR [bp-4],ax	;local_4
; Line 412
	cmp	ax,14
	jge	$I335
;	register si = si
; Line 413
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 414
	add	WORD PTR [bp-4],si	;local_4
; Line 416
$D337:
; Line 417
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 418
	dec	si
; Line 419
	jne	$D337
; Line 420
; Line 421
$I335:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 422
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
; Line 428
	PUBLIC	FUN_ZSTATS__01E8C8
FUN_ZSTATS__01E8C8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,20
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
; Line 437
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 438
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 439
	mov	WORD PTR [bp-4],0	;local_8
; Line 440
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 441
	cmp	ax,-1
	je	$JCC1823
	jmp	$I416
$JCC1823:
; Line 442
	mov	ax,8
	push	ax
	call	FUN_ZSTATS__01E63E
; Line 443
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 444
	mov	ax,OFFSET DAT_0000_9794
	push	ax
	call	FUN_1000_1850
; Line 445
	call	FUN_1000_4DAA
; Line 446
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 447
	call	FUN_1000_266C
	jmp	$EX345
	nop	
$FC358:
; Line 451
	mov	ax,1
	push	ax
	call	FUN_1000_1B94
; Line 452
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2
; Line 456
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20028
$FC361:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
$L20028:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB362
; Line 458
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	FUN_ZSTATS__01E7C2
; Line 460
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE
	push	ax
	call	FUN_1000_1BF2
; Line 461
	call	FUN_1000_1CEE
	cmp	ax,8
	jne	$FC361
; Line 462
$FB362:
; Line 466
	mov	WORD PTR [bp-8],0	;local_10
; Line 467
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I364
; Line 468
	mov	WORD PTR [bp-8],2	;local_10
; Line 469
; Line 472
$I364:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I365
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I365
; Line 473
	inc	WORD PTR [bp-8]	;local_10
; Line 474
; Line 477
$I365:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC370
	cmp	ax,1
	je	$SC371
	cmp	ax,2
	je	$SC373
	cmp	ax,3
	je	$SC374
	jmp	SHORT $SB367
$SC370:
; Line 479
	call	FUN_1000_4DAA
; Line 481
$SB367:
; Line 495
	mov	ax,2
	push	ax
	call	FUN_1000_1B94
; Line 496
	call	FUN_1000_266C
	mov	WORD PTR [bp-14],ax	;local_e
; Line 497
	cmp	ax,32
	jne	$I375
	jmp	$L20032
$SC371:
; Line 483
	mov	ax,25
$L20029:
	push	ax
	call	FUN_1000_4DEA
; Line 485
	jmp	SHORT $SB367
	nop	
$SC373:
; Line 487
	mov	ax,24
	jmp	SHORT $L20029
	nop	
$SC374:
; Line 490
	mov	ax,18
	jmp	SHORT $L20029
	nop	
$I375:
; Line 501
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2078
	jmp	$I377
$JCC2078:
; Line 503
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I378
; Line 505
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I379
; Line 506
	mov	WORD PTR [bp-12],7	;local_4
; Line 507
	jmp	SHORT $I380
	nop	
$I379:
; Line 509
	mov	WORD PTR [bp-12],1	;local_4
; Line 510
$I380:
; Line 512
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2118
	jmp	$I416
$JCC2118:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 513
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I384
; Line 514
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 515
; Line 516
$I384:
	dec	di
	jne	$L20016
$L20036:
	mov	WORD PTR [bp-2],si	;local_6
; Line 517
	jmp	$I416
$I378:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I385
; Line 521
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2186
	jmp	$I416
$JCC2186:
; Line 523
	cmp	WORD PTR [bp-14],2	;local_e
$L20034:
	jle	$JCC2195
	jmp	$I416
$JCC2195:
; Line 525
$L20032:
	mov	WORD PTR [bp-4],1	;local_8
; Line 526
	jmp	$I416
$I385:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I388
; Line 535
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I389
; Line 536
	mov	WORD PTR [bp-12],7	;local_4
; Line 537
	jmp	SHORT $I390
$I389:
; Line 538
	mov	WORD PTR [bp-12],1	;local_4
; Line 539
$I390:
; Line 541
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2242
	jmp	$I416
$JCC2242:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 542
	cmp	si,-1
	je	$I394
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I394
; Line 543
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 544
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 545
; Line 546
$I394:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20037:
	mov	WORD PTR [bp-10],si	;local_c
; Line 547
	jmp	$I416
$I388:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2328
	jmp	$I416
$JCC2328:
	jmp	$L20032
$I377:
; Line 556
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I397
; Line 558
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 559
	jmp	$I416
$I397:
; Line 560
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I399
; Line 561
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2377
	jmp	$I416
$JCC2377:
; Line 562
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20034
	nop	
$I399:
; Line 570
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I403
; Line 572
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	di,ax
; Line 573
	sub	si,si
; Line 575
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$L20021
; Line 577
	mov	di,WORD PTR [bp-10]	;local_c
; Line 578
	inc	si
; Line 579
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 580
	jmp	$I416
$I403:
; Line 581
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I408
; Line 584
	jne	$I409
; Line 585
	mov	WORD PTR [bp-12],7	;local_4
; Line 586
	jmp	SHORT $I410
$I409:
; Line 588
	mov	WORD PTR [bp-12],1	;local_4
; Line 589
$I410:
; Line 591
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2482
	jmp	$I416
$JCC2482:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 592
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	inc	ax
	je	$I414
; Line 593
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E74C
	mov	si,ax
; Line 594
; Line 595
$I414:
	dec	di
	jne	$L20022
	jmp	$L20036
	nop	
$I408:
; Line 597
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I416
; Line 600
	jne	$I417
; Line 601
	mov	WORD PTR [bp-12],7	;local_4
; Line 602
	jmp	SHORT $I418
$I417:
; Line 603
	mov	WORD PTR [bp-12],1	;local_4
; Line 604
$I418:
; Line 605
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I416
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-20],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 606
	cmp	si,-1
	je	$I422
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	inc	ax
	je	$I422
; Line 607
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	WORD PTR [bp-2],ax	;local_6
; Line 608
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	FUN_ZSTATS__01E784
	mov	si,ax
; Line 609
; Line 610
$I422:
	dec	WORD PTR [bp-20]
	jne	$L20024
	jmp	$L20037
$I416:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2648
	jmp	$FC358
$JCC2648:
; Line 616
; Line 618
	mov	ax,WORD PTR [bp-14]	;local_e
$EX345:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E8C8	ENDP
_TEXT	ENDS
END
