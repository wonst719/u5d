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
EXTRN	D_1962:BYTE
EXTRN	D_1A44:BYTE
EXTRN	D_1A58:BYTE
EXTRN	D_1A6A:BYTE
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
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 97
	PUBLIC	FUN_ZSTATS_01E1E0
FUN_ZSTATS_01E1E0	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 102
	mov	WORD PTR [bp-4],-1	;local_4
; Line 104
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I220
; Line 105
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 106
	test	BYTE PTR D_BA16[si],128
	je	$I220
; Line 107
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 110
	jmp	SHORT $I226
$I220:
; Line 113
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_1000_1850
; Line 114
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 115
	or	ax,ax
	jl	$I226
; Line 116
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	push	ax
	call	FUN_1000_1850
; Line 117
	call	FUN_1000_1F12
	or	ax,ax
	je	$I226
; Line 118
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 119
; Line 120
$I226:
; Line 121
; Line 124
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I227
; Line 125
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_1000_1850
; Line 126
; Line 128
	jmp	SHORT $I229
	nop	
$I227:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I229
; Line 129
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 130
; Line 133
$I229:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS_01E1E0	ENDP
; Line 138
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
; Line 148
	call	FUN_0000_8BCA
; Line 150
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 152
	push	ax
	call	FUN_1000_4E50
; Line 153
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
; Line 154
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 155
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
; Line 157
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 158
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 159
	mov	WORD PTR [bp-4],0	;local_8
; Line 161
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I241
; Line 162
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 164
	sub	si,si
; Line 165
$FC243:
; Line 166
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 167
	inc	si
; Line 168
	cmp	WORD PTR [di],si
	jg	$FC243
; Line 169
; Line 172
	mov	WORD PTR [bp-4],si	;local_8
; Line 173
; Line 175
$I241:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA
; Line 176
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_1000_1850
; Line 177
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 178
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 179
	mov	ax,WORD PTR [bp-2]	;local_6
	shl	ax,1
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850
; Line 180
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
; Line 181
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2
; Line 182
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 183
	mov	ax,WORD PTR [bp-6]	;local_a
	shl	ax,1
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850
; Line 184
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
; Line 185
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2
; Line 186
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 187
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_1000_1850
; Line 188
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 189
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_1000_1850
; Line 190
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 191
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_1000_1850
; Line 192
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 193
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_1000_1850
; Line 194
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 195
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_1000_1850
; Line 196
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 197
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_1000_1850
; Line 198
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 199
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_1000_1850
; Line 200
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 201
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E262	ENDP
; Line 205
	PUBLIC	FUN_ZSTATS__01E458
FUN_ZSTATS__01E458	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 206
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I249
; Line 207
	sub	ax,ax
	jmp	SHORT $EX248
$I249:
; Line 208
; Line 209
	mov	ax,32
	push	ax
	call	FUN_1000_16BA
; Line 210
	mov	ax,WORD PTR [bp+4]	;param_1
	shl	ax,1
	add	ax,OFFSET D_1962
	push	ax
	call	FUN_1000_1850
; Line 211
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 212
	mov	ax,1
$EX248:
	pop	bp
	ret	2
	nop	

FUN_ZSTATS__01E458	ENDP
; Line 218
	PUBLIC	FUN_ZSTATS__01E488
FUN_ZSTATS__01E488	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 222
	call	FUN_1000_4DAA
; Line 224
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_6
; Line 225
	push	ax
	call	FUN_1000_4E50
; Line 226
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
; Line 227
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 228
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 229
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 230
	mov	ax,OFFSET DAT_0000_970E
	push	ax
	call	FUN_1000_1850
; Line 231
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 232
	mov	ax,254
	push	ax
	call	FUN_1000_16BA
; Line 234
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	mov	WORD PTR [bp-4],ax	;local_4
; Line 235
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 236
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 237
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 238
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 239
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	FUN_ZSTATS__01E458
	add	WORD PTR [bp-4],ax	;local_4
; Line 241
	jne	$I256
; Line 242
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2
; Line 243
	mov	ax,252
	push	ax
	call	FUN_1000_16BA
; Line 244
	mov	ax,OFFSET DAT_0000_9716
	push	ax
	call	FUN_1000_1850
; Line 245
	mov	ax,251
	push	ax
	call	FUN_1000_16BA
; Line 246
; Line 248
$I256:
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
; Line 249
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E488	ENDP
; Line 253
	PUBLIC	FUN_ZSTATS__01E57C
FUN_ZSTATS__01E57C	PROC NEAR
; Line 254
	call	FUN_1000_4DAA
; Line 255
	mov	ax,OFFSET DAT_0000_9724
	push	ax
	call	FUN_1000_4E50
; Line 256
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
; Line 257
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 258
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
; Line 259
	mov	ax,OFFSET DAT_0000_972E
	push	ax
	call	FUN_1000_1850
; Line 260
	push	WORD PTR UNK_0000_57A8
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 261
	mov	ax,OFFSET DAT_0000_9738
	push	ax
	call	FUN_1000_1850
; Line 262
	push	WORD PTR UNK_0000_57AA
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 263
	mov	ax,OFFSET DAT_0000_9742
	push	ax
	call	FUN_1000_1850
; Line 264
	mov	al,UNK_0000_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 265
	mov	ax,OFFSET DAT_0000_9752
	push	ax
	call	FUN_1000_1850
; Line 266
	mov	al,UNK_0000_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 267
	mov	ax,OFFSET DAT_0000_9760
	push	ax
	call	FUN_1000_1850
; Line 268
	mov	al,UNK_0000_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 269
	cmp	BYTE PTR UNK_0000_57AF,0
	je	$I259
; Line 270
	mov	ax,OFFSET DAT_0000_976E
	push	ax
	call	FUN_1000_1850
; Line 271
; Line 272
$I259:
	ret	

FUN_ZSTATS__01E57C	ENDP
; Line 276
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
; Line 280
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
; Line 281
	mov	ax,255
	push	ax
	call	FUN_1000_16BA
; Line 282
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
; Line 283
	mov	ax,16
	push	ax
	call	FUN_1000_16BA
; Line 284
	mov	WORD PTR [bp-4],13	;local_4
; Line 285
	mov	si,13
$L20000:
; Line 286
	mov	ax,17
	push	ax
	call	FUN_1000_16BA
; Line 287
	dec	si
	jne	$L20000
; Line 288
	mov	ax,19
	push	ax
	call	FUN_1000_16BA
; Line 289
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 290
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 291
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 292
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2
; Line 293
	mov	ax,23
	push	ax
	call	FUN_1000_16BA
; Line 294
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 295
	mov	WORD PTR [bp-4],si	;local_4
; Line 296
	mov	ax,10
	push	ax
	call	FUN_1000_16BA
; Line 297
	mov	ax,20
	push	ax
	call	FUN_1000_16BA
; Line 298
	mov	WORD PTR [bp-4],13	;local_4
; Line 299
	mov	si,13
$L20003:
; Line 300
	mov	ax,21
	push	ax
	call	FUN_1000_16BA
; Line 301
	dec	si
	jne	$L20003
; Line 302
	mov	ax,22
	push	ax
	call	FUN_1000_16BA
; Line 303
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

FUN_ZSTATS__01E63E	ENDP
; Line 307
	PUBLIC	FUN_ZSTATS__01E6F8
FUN_ZSTATS__01E6F8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 308
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,D_55A8
	mov	WORD PTR [bp-2],ax	;local_4
; Line 315
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
	jmp	SHORT $EX277
	nop	
$L20004:
	sub	ax,ax
$EX277:
	mov	sp,bp
	pop	bp
	ret	4

FUN_ZSTATS__01E6F8	ENDP
; Line 320
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
; Line 321
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC286:
; Line 322
	dec	si
	js	$L20012
; Line 323
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I289
; Line 324
	cmp	di,255
	je	$FC286
; Line 325
	push	di
	push	si
	call	FUN_ZSTATS__01E6F8
	or	ax,ax
	je	$FC286
; Line 327
; Line 330
$I289:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX284
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 336
	mov	ax,-1
$EX284:
	pop	si
	pop	di
	pop	bp
	ret	8

FUN_ZSTATS__01E74C	ENDP
_TEXT	ENDS
END
