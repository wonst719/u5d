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
EXTRN	FUN_1000_1BF2:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	FUN_1000_1F12:NEAR
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
; Line 102
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 107
	mov	WORD PTR [bp-4],-1	;local_4
; Line 109
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I225
; Line 110
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 111
	test	BYTE PTR D_BA16[si],128
	je	$I225
; Line 112
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 115
	jmp	SHORT $I231
$I225:
; Line 118
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 119
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 120
	or	ax,ax
	jl	$I231
; Line 121
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 122
	call	FUN_1000_1F12
	or	ax,ax
	je	$I231
; Line 123
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 124
; Line 125
$I231:
; Line 126
; Line 129
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I232
; Line 130
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 131
; Line 133
	jmp	SHORT $I234
	nop	
$I232:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I234
; Line 134
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 135
; Line 138
$I234:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 143
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
; Line 153
	call	FUN_0000_8BCA
; Line 155
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 157
	push	ax
	call	FUN_1000_4E50
; Line 158
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
; Line 159
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 160
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
; Line 162
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 163
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 164
	mov	WORD PTR [bp-4],0	;local_8
; Line 166
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I246
; Line 167
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 169
	sub	si,si
; Line 170
$FC248:
; Line 171
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 172
	inc	si
; Line 173
	cmp	WORD PTR [di],si
	jg	$FC248
; Line 174
; Line 177
	mov	WORD PTR [bp-4],si	;local_8
; Line 178
; Line 180
$I246:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 181
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 182
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 183
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 184
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 185
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
; Line 186
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 187
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 188
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 189
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
; Line 190
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 191
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 192
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 193
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 194
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 195
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 196
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 197
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 198
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 199
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 200
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 201
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 202
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 203
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 204
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 205
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 206
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 210
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 211
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I254
; Line 212
	sub	ax,ax
	jmp	SHORT $EX253
$I254:
; Line 213
; Line 214
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 215
	mov	ax,WORD PTR [bp+4]	;param_1
	shl	ax,1
	add	ax,OFFSET D_1962
	push	ax
	call	FUN_1000_1850
; Line 216
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 217
	mov	ax,1
$EX253:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 223
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 227
	call	FUN_1000_4DAA
; Line 229
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 230
	push	ax
	call	FUN_1000_4E50
; Line 231
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
; Line 232
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 233
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 234
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 235
	mov	ax,OFFSET DAT_0000_970E
	push	ax
	call	FUN_1000_1850
; Line 236
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 237
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 239
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 240
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 241
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 242
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 243
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 244
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 246
	jne	$I261
; Line 247
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 248
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 249
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 250
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 251
; Line 253
$I261:
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
; Line 254
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 258
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 259
	call	FUN_1000_4DAA
; Line 260
	mov	ax,OFFSET DAT_0000_9724
	push	ax
	call	FUN_1000_4E50
; Line 261
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
; Line 262
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 263
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
; Line 264
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 265
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 266
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 267
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 268
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 269
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 270
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 271
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 272
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 273
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 274
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I264
; Line 275
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 276
; Line 277
$I264:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 281
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
; Line 285
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
; Line 286
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 287
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
; Line 288
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 289
	mov	WORD PTR [bp-4],13	;local_4
; Line 290
	mov	si,13
$L20000:
; Line 291
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 292
	dec	si
	jne	$L20000
; Line 293
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 294
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 295
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 296
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 297
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 298
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 299
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 300
	mov	WORD PTR [bp-4],si	;local_4
; Line 301
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 302
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 303
	mov	WORD PTR [bp-4],13	;local_4
; Line 304
	mov	si,13
$L20003:
; Line 305
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 306
	dec	si
	jne	$L20003
; Line 307
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 308
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 312
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 313
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 320
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
	jmp	SHORT $EX282
	nop	
$L20004:
	sub	ax,ax
$EX282:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 325
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
; Line 326
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC291:
; Line 327
	dec	si
	js	$L20012
; Line 328
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I294
; Line 329
	cmp	di,255
	je	$FC291
; Line 330
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC291
; Line 332
; Line 335
$I294:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX289
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 341
	mov	ax,-1
$EX289:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
; Line 346
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
; Line 347
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC304:
; Line 348
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 349
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I307
; Line 350
	cmp	di,255
	je	$FC304
; Line 351
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC304
; Line 353
; Line 356
$I307:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX302
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 362
	mov	ax,-1
$EX302:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E784	ENDP
; Line 370
	PUBLIC	FUN_ZSTATS__01E7C2
FUN_ZSTATS__01E7C2	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,10
	push	di
	push	si
;	local_4 = -6
;	text = -4
;	param_4 = 10
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
;	local_6 = -2
; Line 374
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 375
	cmp	al,255
	je	$I322
; Line 376
	or	al,al
	je	$I323
; Line 377
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 378
	jmp	SHORT $I324
	nop	
$I323:
; Line 379
	mov	ax,OFFSET DAT_0000_9778
	push	ax
	call	FUN_1000_1850
; Line 380
$I324:
; Line 381
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I325
; Line 382
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 383
; Line 384
$I325:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA
; Line 385
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 386
; Line 388
$I322:
;	register si = text
; Line 389
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
; Line 390
	cmp	BYTE PTR [si],42
	jne	$I328
; Line 391
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 392
	mov	ax,OFFSET DAT_0000_977C
	push	ax
	call	FUN_1000_1850
; Line 393
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850
; Line 394
$L20016:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 395
	jmp	SHORT $L_0329
$I328:
; Line 399
; Line 400
	mov	si,WORD PTR [bp+10]	;param_4
	shl	si,1
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I330
; Line 401
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 402
	mov	ax,OFFSET DAT_0000_9782
	push	ax
	call	FUN_1000_1850
; Line 403
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E
; Line 404
	mov	ax,WORD PTR D_19B2
	add	ax,si
	push	ax
	jmp	SHORT $L20017
	nop	
$I330:
; Line 405
;	register si = text
; Line 406
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
; Line 407
	cmp	BYTE PTR [si],40
	jne	$I333
; Line 408
	mov	ax,OFFSET DAT_0000_9788
	push	ax
	call	FUN_1000_1850
; Line 409
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E
; Line 410
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
	jmp	SHORT $L20016
$I333:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][di]
$L20017:
	call	FUN_1000_1850
; Line 415
; Line 416
; Line 417
$L_0329:
; Line 418
	call	FUN_1000_1F12
	mov	WORD PTR [bp-6],ax	;local_4
; Line 419
	cmp	ax,14
	jge	$I334
;	register si = si
; Line 420
	mov	ax,14
	sub	ax,WORD PTR [bp-6]	;local_4
	mov	si,ax
; Line 421
	add	WORD PTR [bp-6],si	;local_4
; Line 423
$D336:
; Line 424
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 425
	dec	si
; Line 426
	jne	$D336
; Line 427
; Line 428
$I334:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 429
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

FUN_ZSTATS__01E7C2	ENDP
_TEXT	ENDS
END
