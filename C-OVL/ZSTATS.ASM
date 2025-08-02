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
EXTRN	FUN_1000_1C9E_GET_CHAR_SEGMENT:NEAR
EXTRN	FUN_1000_6E60:NEAR
EXTRN	FUN_1000_1850_PRINT_STRING:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	FUN_1000_1F12_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	FUN_1000_4E20:NEAR
EXTRN	FUN_1000_4F3C:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	FUN_1000_1C22_SET_TEXT_WINDOW_S:NEAR
EXTRN	FUN_1000_4D76:NEAR
EXTRN	FUN_1000_1B94_GET_TEXT_EFFECTS:NEAR
EXTRN	FUN_1000_266C_GET_CH:NEAR
EXTRN	FUN_1000_1A3E:NEAR
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_1000_1CEE_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_2092:NEAR
EXTRN	FUN_1000_43AE:NEAR
EXTRN	FUN_1000_4DEA:NEAR
EXTRN	FUN_1000_4EFC:NEAR
EXTRN	D_1AE8:BYTE
EXTRN	D_BA18:BYTE
EXTRN	D_57AA:BYTE
EXTRN	D_1ADE:BYTE
EXTRN	D_57AC:BYTE
EXTRN	D_1AAE:BYTE
EXTRN	D_57AD:BYTE
EXTRN	D_57AE:BYTE
EXTRN	D_57AF:BYTE
EXTRN	D_57B0:BYTE
EXTRN	D_57B1:BYTE
EXTRN	D_57B3:BYTE
EXTRN	D_57B4:BYTE
EXTRN	D_57B5:BYTE
EXTRN	D_57B6:BYTE
EXTRN	D_57BA:BYTE
EXTRN	D_57BB:BYTE
EXTRN	D_57BC:BYTE
EXTRN	D_57BD:BYTE
EXTRN	D_57BE:BYTE
EXTRN	D_57BF:BYTE
EXTRN	D_57C0:BYTE
EXTRN	D_57DB:BYTE
EXTRN	D_57DD:BYTE
EXTRN	D_5820:QWORD
EXTRN	D_5828:QWORD
EXTRN	D_5840:QWORD
EXTRN	D_5850:BYTE
EXTRN	D_5893_MAP_ID:BYTE
EXTRN	D_58A3:BYTE
EXTRN	D_589E:BYTE
EXTRN	D_58F0:BYTE
EXTRN	D_5C5A:BYTE
_BSS      SEGMENT
COMM NEAR	D_535E:	BYTE:	 32
EXTRN	D_B9EE:QWORD
EXTRN	D_B9F6:QWORD
EXTRN	D_B9FE:BYTE
EXTRN	D_B9FF:BYTE
EXTRN	D_BA00:BYTE
EXTRN	D_BA01:BYTE
EXTRN	D_BA02:BYTE
EXTRN	D_1916:WORD
EXTRN	D_BA03:QWORD
EXTRN	D_BA0B:BYTE
EXTRN	D_1962:WORD
EXTRN	D_BA0E:BYTE
EXTRN	D_19B2:WORD
EXTRN	D_19D2:WORD
EXTRN	D_BA0F:BYTE
EXTRN	D_19E2:WORD
EXTRN	D_BA10:BYTE
EXTRN	D_BA11:BYTE
EXTRN	D_1A44:BYTE
EXTRN	D_BA12:BYTE
EXTRN	D_1A58:WORD
EXTRN	D_55A8_PARTY:BYTE
EXTRN	D_BA13:BYTE
EXTRN	D_1A6A:BYTE
EXTRN	D_1A7E:BYTE
EXTRN	D_57A8:BYTE
EXTRN	D_BA16:BYTE
_BSS      ENDS
_DATA      SEGMENT
$SG332	DB	'Player: ',  00H
$SG339	DB	'None!',  0aH,  00H
$SG355	DB	'AMBFDTPRS',  00H
$SG356	DB	'GPDSC',  00H
$SG362	DB	' Lv-',  00H
$SG365	DB	'Str=',  00H
$SG366	DB	'  HP:',  00H
$SG367	DB	0aH, 'Int=',  00H
$SG368	DB	'  HM:',  00H
$SG369	DB	0aH, 'Dex=',  00H
$SG370	DB	'  Ex:',  00H
$SG371	DB	0aH,  0aH, '    Magic:',  00H
$SG382	DB	'Arms',  0aH,  0aH,  00H
$SG384	DB	'(None ready)',  00H
$SG387	DB	'Equipment',  00H
$SG388	DB	0aH, ' Food: ',  00H
$SG389	DB	0aH, ' Gold: ',  00H
$SG390	DB	0aH,  0aH, ' Keys.......',  00H
$SG391	DB	0aH, ' Gems.......',  00H
$SG392	DB	0aH, ' Torches....',  00H
$SG394	DB	0aH, ' Grapple',  00H
$SG451	DB	'--',  00H
$SG455	DB	1cH, ' + ',  00H
$SG458	DB	1dH, ' + ',  00H
$SG461	DB	'Moonstone ',  00H
$SG483	DB	'(None owned!)',  00H
$SG571	DB	0aH, 'Status: ',  00H
$SG600	DB	'Done',  0aH,  00H
$SG606	DB	'Reagents',  00H
$SG609	DB	'Spells',  00H
$SG612	DB	'Items',  00H
$SG615	DB	'Armaments',  00H
$SG619	DB	0aH,  0aH,  00H
$SG620	DB	0aH,  0aH, 'Item: ',  00H
$SG646	DB	'Thou canst not change armour in heated battle!',  00H
$SG652	DB	'AMBFDTPRS',  00H
$SG657	DB	'Thou hast no ammunition for that weapon!',  00H
$SG668	DB	'Only one magic ring may be worn at a time!',  00H
$SG671	DB	'Thou must remove thine other amulet!',  00H
$SG674	DB	'Thou must free one of thy hands first!',  00H
$SG678	DB	'Both hands must be free before thou canst wield that!',  00H
$SG681	DB	'Thou must first remove thine other armour!',  00H
$SG684	DB	'Remove first thy present helm!',  00H
$SG686	DB	'Thou art not strong enough!',  00H
$SG691	DB	0aH,  0aH, 'Ring vanishes!',  0aH,  00H
$SG785	DB	'Thou art empty-',  0aH, 'handed!',  0aH,  00H
$SG786	DB	'Item: ',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 55
	PUBLIC	F_ZSTATS_0000
F_ZSTATS_0000	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 60
	mov	WORD PTR [bp-4],-1	;local_4
; Line 62
	cmp	BYTE PTR D_5893_MAP_ID,128
	jbe	$I327
; Line 63
	mov	al,D_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 64
	test	D_BA16[si],128
	je	$I327
; Line 65
	mov	al,D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 68
	jmp	SHORT $I336
$I327:
; Line 71
	mov	ax,OFFSET DGROUP:$SG332
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 72
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 73
	or	ax,ax
	jl	$I336
; Line 74
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 75
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	or	ax,ax
	je	$I336
; Line 76
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 77
; Line 78
$I336:
; Line 79
; Line 82
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I338
; Line 83
	mov	ax,OFFSET DGROUP:$SG339
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 84
; Line 86
	jmp	SHORT $I341
$I338:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I341
; Line 87
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 88
; Line 91
$I341:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0000	ENDP
; Line 97
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
; Line 107
	call	FUN_1000_4DAA
; Line 109
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-12],ax	;local_4
; Line 111
	push	ax
	call	FUN_1000_4E50
; Line 112
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 113
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 114
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 116
	mov	ax,OFFSET DGROUP:$SG355
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 117
	mov	ax,OFFSET DGROUP:$SG356
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 118
	mov	WORD PTR [bp-4],0	;local_8
; Line 120
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	D_1A58[bx],0
	jle	$I357
; Line 121
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 123
	sub	si,si
; Line 124
$FC359:
; Line 125
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 126
	inc	si
; Line 127
	cmp	WORD PTR [di],si
	jg	$FC359
; Line 128
; Line 131
	mov	WORD PTR [bp-4],si	;local_8
; Line 132
; Line 134
$I357:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 135
	mov	ax,OFFSET DGROUP:$SG362
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 136
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 137
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 138
	mov	ax,WORD PTR [bp-2]	;local_6
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 139
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 140
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 141
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 142
	mov	ax,WORD PTR [bp-6]	;local_a
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 143
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 144
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 145
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 146
	mov	ax,OFFSET DGROUP:$SG365
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 147
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 148
	mov	ax,OFFSET DGROUP:$SG366
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 149
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 150
	mov	ax,OFFSET DGROUP:$SG367
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 151
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 152
	mov	ax,OFFSET DGROUP:$SG368
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 153
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 154
	mov	ax,OFFSET DGROUP:$SG369
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 155
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 156
	mov	ax,OFFSET DGROUP:$SG370
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 157
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 158
	mov	ax,OFFSET DGROUP:$SG371
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 159
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 160
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

F_ZSTATS_0082	ENDP
; Line 165
	PUBLIC	F_ZSTATS_0278
F_ZSTATS_0278	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 166
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I375
; Line 167
	sub	ax,ax
	jmp	SHORT $EX374
$I375:
; Line 168
; Line 169
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 170
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	D_1962[bx]
	call	FUN_1000_1850_PRINT_STRING
; Line 171
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 172
	mov	ax,1
$EX374:
	pop	bp
	ret	2
	nop	

F_ZSTATS_0278	ENDP
; Line 179
	PUBLIC	F_ZSTATS_02A8
F_ZSTATS_02A8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 183
	call	FUN_1000_4DAA
; Line 185
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-2],ax	;local_6
; Line 186
	push	ax
	call	FUN_1000_4E50
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 188
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 189
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 190
	mov	ax,254
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 191
	mov	ax,OFFSET DGROUP:$SG382
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 192
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 193
	mov	ax,254
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 195
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	mov	WORD PTR [bp-4],ax	;local_4
; Line 196
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 197
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 198
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 199
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 200
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 202
	jne	$I383
; Line 203
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 204
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 205
	mov	ax,OFFSET DGROUP:$SG384
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 206
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 207
; Line 209
$I383:
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 210
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_02A8	ENDP
; Line 215
	PUBLIC	F_ZSTATS_039C
F_ZSTATS_039C	PROC NEAR
; Line 216
	call	FUN_1000_4DAA
; Line 217
	mov	ax,OFFSET DGROUP:$SG387
	push	ax
	call	FUN_1000_4E50
; Line 218
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 219
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 220
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 221
	mov	ax,OFFSET DGROUP:$SG388
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 222
	mov	al,D_57A8
	sub	ah,ah
	push	ax
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 223
	mov	ax,OFFSET DGROUP:$SG389
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 224
	mov	al,D_57AA
	sub	ah,ah
	push	ax
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 225
	mov	ax,OFFSET DGROUP:$SG390
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 226
	mov	al,D_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 227
	mov	ax,OFFSET DGROUP:$SG391
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 228
	mov	al,D_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 229
	mov	ax,OFFSET DGROUP:$SG392
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 230
	mov	al,D_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 231
	cmp	BYTE PTR D_57AF,0
	je	$I393
; Line 232
	mov	ax,OFFSET DGROUP:$SG394
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 233
; Line 234
$I393:
	ret	

F_ZSTATS_039C	ENDP
; Line 239
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
; Line 243
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 244
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 245
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
	call	FUN_1000_1C22_SET_TEXT_WINDOW_S
; Line 246
	mov	ax,16
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 247
	mov	WORD PTR [bp-4],13	;local_4
; Line 248
	mov	si,13
$L20000:
; Line 249
	mov	ax,17
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 250
	dec	si
	jne	$L20000
; Line 251
	mov	ax,19
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 252
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 253
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 254
	mov	ax,23
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 255
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 256
	mov	ax,23
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 257
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 258
	mov	WORD PTR [bp-4],si	;local_4
; Line 259
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 260
	mov	ax,20
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 261
	mov	WORD PTR [bp-4],13	;local_4
; Line 262
	mov	si,13
$L20003:
; Line 263
	mov	ax,21
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 264
	dec	si
	jne	$L20003
; Line 265
	mov	ax,22
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 266
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

F_ZSTATS_045E	ENDP
; Line 271
	PUBLIC	F_ZSTATS_0518
F_ZSTATS_0518	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 272
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-2],ax	;local_4
; Line 279
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
	jmp	SHORT $EX412
$L20004:
	sub	ax,ax
$EX412:
	mov	sp,bp
	pop	bp
	ret	4

F_ZSTATS_0518	ENDP
; Line 285
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
; Line 286
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC421:
; Line 287
	dec	si
	js	$L20012
; Line 288
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I424
; Line 289
	cmp	di,255
	je	$FC421
; Line 290
	push	di
	push	si
	call	F_ZSTATS_0518
	or	ax,ax
	je	$FC421
; Line 292
; Line 295
$I424:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX419
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 301
	mov	ax,-1
$EX419:
	pop	si
	pop	di
	pop	bp
	ret	8

F_ZSTATS_056C	ENDP
; Line 307
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
; Line 308
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC434:
; Line 309
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 310
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I437
; Line 311
	cmp	di,255
	je	$FC434
; Line 312
	push	di
	push	si
	call	F_ZSTATS_0518
	or	ax,ax
	je	$FC434
; Line 314
; Line 317
$I437:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX432
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 323
	mov	ax,-1
$EX432:
	pop	si
	pop	di
	pop	bp
	ret	8

F_ZSTATS_05A4	ENDP
; Line 329
	PUBLIC	F_ZSTATS_05E2
F_ZSTATS_05E2	PROC NEAR
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
; Line 333
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 334
	cmp	al,255
	je	$I448
; Line 335
	or	al,al
	je	$I449
; Line 336
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 337
	jmp	SHORT $I450
	nop	
$I449:
; Line 338
	mov	ax,OFFSET DGROUP:$SG451
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 339
$I450:
; Line 340
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I452
; Line 341
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 342
; Line 343
$I452:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA_PRINT_CHAR
; Line 344
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 345
; Line 347
$I448:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I454
; Line 348
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 349
	mov	ax,OFFSET DGROUP:$SG455
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 350
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 351
$L20045:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 352
	jmp	SHORT $I462
$I454:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I457
; Line 353
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 354
	mov	ax,OFFSET DGROUP:$SG458
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 355
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 356
	mov	ax,WORD PTR [bp+10]	;param_4
	add	ax,D_19B2
	push	ax
	jmp	SHORT $L20046
	nop	
$I457:
; Line 357
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I460
; Line 358
	mov	ax,OFFSET DGROUP:$SG461
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 359
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 360
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
	jmp	SHORT $L20045
$I460:
; Line 362
; Line 363
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20046:
	call	FUN_1000_1850_PRINT_STRING
; Line 364
$I462:
; Line 367
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	mov	WORD PTR [bp-4],ax	;local_4
; Line 368
	cmp	ax,14
	jge	$I464
;	register si = si
; Line 369
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 370
	add	WORD PTR [bp-4],si	;local_4
; Line 372
$D466:
; Line 373
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 374
	dec	si
; Line 375
	jne	$D466
; Line 376
; Line 377
$I464:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 378
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

F_ZSTATS_05E2	ENDP
; Line 385
	PUBLIC	F_ZSTATS_06E8
F_ZSTATS_06E8	PROC NEAR
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
; Line 394
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 395
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 396
	mov	WORD PTR [bp-4],0	;local_8
; Line 397
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 398
	cmp	ax,-1
	je	$JCC1819
	jmp	$I547
$JCC1819:
; Line 399
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 400
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 401
	mov	ax,OFFSET DGROUP:$SG483
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 402
	call	FUN_1000_4DAA
; Line 403
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 404
	call	FUN_1000_266C_GET_CH
	jmp	$EX474
	nop	
$FC488:
; Line 408
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 409
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 413
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20047
$FC491:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
$L20047:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB492
; Line 415
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	F_ZSTATS_05E2
; Line 417
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 418
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	cmp	ax,8
	jne	$FC491
; Line 419
$FB492:
; Line 423
	mov	WORD PTR [bp-8],0	;local_10
; Line 424
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I495
; Line 425
	mov	WORD PTR [bp-8],2	;local_10
; Line 426
; Line 429
$I495:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I496
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I496
; Line 430
	inc	WORD PTR [bp-8]	;local_10
; Line 431
; Line 434
$I496:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC501
	cmp	ax,1
	je	$SC502
	cmp	ax,2
	je	$SC504
	cmp	ax,3
	je	$SC505
	jmp	SHORT $SB498
$SC501:
; Line 436
	call	FUN_1000_4DAA
; Line 438
$SB498:
; Line 452
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 453
	call	FUN_1000_266C_GET_CH
	mov	WORD PTR [bp-14],ax	;local_e
; Line 454
	cmp	ax,32
	jne	$I506
	jmp	$L20051
$SC502:
; Line 440
	mov	ax,25
$L20048:
	push	ax
	call	FUN_1000_4DEA
; Line 442
	jmp	SHORT $SB498
	nop	
$SC504:
; Line 444
	mov	ax,24
	jmp	SHORT $L20048
	nop	
$SC505:
; Line 447
	mov	ax,18
	jmp	SHORT $L20048
	nop	
$I506:
; Line 458
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2074
	jmp	$I508
$JCC2074:
; Line 460
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I509
; Line 462
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I510
; Line 463
	mov	WORD PTR [bp-12],7	;local_4
; Line 464
	jmp	SHORT $I511
	nop	
$I510:
; Line 466
	mov	WORD PTR [bp-12],1	;local_4
; Line 467
$I511:
; Line 469
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2114
	jmp	$I547
$JCC2114:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 470
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I515
; Line 471
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	si,ax
; Line 472
; Line 473
$I515:
	dec	di
	jne	$L20016
$L20055:
	mov	WORD PTR [bp-2],si	;local_6
; Line 474
	jmp	$I547
$I509:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I516
; Line 478
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2182
	jmp	$I547
$JCC2182:
; Line 480
	cmp	WORD PTR [bp-14],2	;local_e
$L20053:
	jle	$JCC2191
	jmp	$I547
$JCC2191:
; Line 482
$L20051:
	mov	WORD PTR [bp-4],1	;local_8
; Line 483
	jmp	$I547
$I516:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I519
; Line 492
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I520
; Line 493
	mov	WORD PTR [bp-12],7	;local_4
; Line 494
	jmp	SHORT $I521
$I520:
; Line 495
	mov	WORD PTR [bp-12],1	;local_4
; Line 496
$I521:
; Line 498
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2238
	jmp	$I547
$JCC2238:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 499
	cmp	si,-1
	je	$I525
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I525
; Line 500
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 501
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	si,ax
; Line 502
; Line 503
$I525:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20056:
	mov	WORD PTR [bp-10],si	;local_c
; Line 504
	jmp	$I547
$I519:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2324
	jmp	$I547
$JCC2324:
	jmp	$L20051
$I508:
; Line 513
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I528
; Line 515
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 516
	jmp	$I547
$I528:
; Line 517
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I530
; Line 518
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2373
	jmp	$I547
$JCC2373:
; Line 519
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20053
	nop	
$I530:
; Line 527
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I534
; Line 529
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	di,ax
; Line 530
	sub	si,si
; Line 532
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$L20021
; Line 534
	mov	di,WORD PTR [bp-10]	;local_c
; Line 535
	inc	si
; Line 536
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 537
	jmp	$I547
$I534:
; Line 538
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I539
; Line 541
	jne	$I540
; Line 542
	mov	WORD PTR [bp-12],7	;local_4
; Line 543
	jmp	SHORT $I541
$I540:
; Line 545
	mov	WORD PTR [bp-12],1	;local_4
; Line 546
$I541:
; Line 548
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2478
	jmp	$I547
$JCC2478:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 549
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I545
; Line 550
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	si,ax
; Line 551
; Line 552
$I545:
	dec	di
	jne	$L20022
	jmp	$L20055
	nop	
$I539:
; Line 554
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I547
; Line 557
	jne	$I548
; Line 558
	mov	WORD PTR [bp-12],7	;local_4
; Line 559
	jmp	SHORT $I549
$I548:
; Line 560
	mov	WORD PTR [bp-12],1	;local_4
; Line 561
$I549:
; Line 562
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I547
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-20],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 563
	cmp	si,-1
	je	$I553
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I553
; Line 564
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 565
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	si,ax
; Line 566
; Line 567
$I553:
	dec	WORD PTR [bp-20]
	jne	$L20024
	jmp	$L20056
$I547:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2644
	jmp	$FC488
$JCC2644:
; Line 573
; Line 575
	mov	ax,WORD PTR [bp-14]	;local_e
$EX474:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

F_ZSTATS_06E8	ENDP
; Line 581
	PUBLIC	F_ZSTATS_099A
F_ZSTATS_099A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 584
	sub	si,si
; Line 585
$D557:
; Line 586
	mov	al,BYTE PTR D_5820[si]
	mov	BYTE PTR D_B9EE[si],al
; Line 587
	mov	al,BYTE PTR D_5828[si]
	mov	BYTE PTR D_B9F6[si],al
; Line 588
	cmp	BYTE PTR D_5840[si],255
	jne	$L20026
	mov	al,255
	jmp	SHORT $L20027
	nop	
$L20026:
	sub	al,al
$L20027:
	mov	BYTE PTR D_BA03[si],al
; Line 589
	inc	si
	cmp	si,8
	jl	$D557
	mov	WORD PTR [bp-2],si	;local_4
; Line 591
	mov	al,D_57B0
	mov	D_B9FE,al
; Line 592
	mov	al,D_57B1
	mov	D_B9FF,al
; Line 593
	mov	al,D_57B3
	mov	D_BA00,al
; Line 594
	mov	al,D_57B4
	mov	D_BA01,al
; Line 595
	mov	al,D_57B5
	mov	D_BA02,al
; Line 597
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET D_BA0B
	mov	si,OFFSET D_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 601
	mov	al,D_57BA
	mov	D_BA0E,al
; Line 602
	cmp	BYTE PTR D_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	D_BA0F,al
; Line 603
	mov	al,D_57BC
	mov	D_BA10,al
; Line 604
	mov	al,D_57BD
	mov	D_BA11,al
; Line 605
	mov	al,D_57BE
	mov	D_BA12,al
; Line 606
	mov	al,D_57BF
	mov	D_BA13,al
; Line 607
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_099A	ENDP
; Line 612
	PUBLIC	F_ZSTATS_0A3A
F_ZSTATS_0A3A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 617
	mov	ax,1
	push	ax
	call	F_ZSTATS_0000
	mov	WORD PTR [bp-4],ax	;local_8
; Line 618
	cmp	ax,-2
	jne	$I568
; Line 619
	mov	WORD PTR [bp-4],6	;local_8
; Line 620
	jmp	SHORT $I569
	nop	
$I568:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2854
	jmp	$EX564
$JCC2854:
; Line 621
$I569:
	mov	ax,OFFSET DGROUP:$SG571
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 625
	call	F_ZSTATS_099A
; Line 626
	call	FUN_1000_4EFC
; Line 627
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 628
	mov	BYTE PTR [bp-2],0	;local_6
; Line 631
$D573:
; Line 632
; Line 633
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2888
	jmp	$I579
$JCC2888:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2897
	jmp	$I579
$JCC2897:
; Line 634
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I581
	cmp	al,1
	jne	$I580
$I581:
; Line 635
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I582
; Line 636
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20058:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 637
; Line 638
	jmp	SHORT $I596
	nop	
$I582:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I584
; Line 639
	mov	WORD PTR [bp-6],16	;local_4
; Line 640
; Line 641
	jmp	SHORT $I596
	nop	
$I584:
; Line 642
	dec	WORD PTR [bp-6]	;local_4
; Line 643
; Line 644
	jmp	SHORT $I596
	nop	
$I580:
; Line 645
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I588
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I587
$I588:
; Line 646
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I594
; Line 647
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I590
; Line 648
	inc	WORD PTR [bp-6]	;local_4
; Line 649
	jmp	SHORT $I596
$I590:
; Line 650
	mov	WORD PTR [bp-6],0	;local_4
; Line 651
; Line 652
	jmp	SHORT $I596
	nop	
$I587:
; Line 654
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I594
; Line 655
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I594
; Line 656
	jbe	$I596
	cmp	BYTE PTR [bp-2],55	;local_6
	jae	$I596
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	mov	si,ax
	lea	ax,WORD PTR [si-49]
	mov	bx,22619
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	cmp	ax,cx
	jae	$I596
; Line 657
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20058
$I594:
; Line 662
	mov	WORD PTR [bp-6],12	;local_4
; Line 663
; Line 664
$I596:
; Line 672
; Line 675
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 676
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I601
; Line 677
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I602
; Line 678
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	F_ZSTATS_0082
; Line 679
	jmp	SHORT $L20057
	nop	
$I579:
; Line 664
; Line 665
	call	FUN_1000_4DAA
; Line 666
	call	FUN_1000_4E20
; Line 667
	call	FUN_1000_4F3C
; Line 668
	call	FUN_1000_2900
; Line 669
	mov	ax,OFFSET DGROUP:$SG600
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 670
	jmp	$EX564
$I602:
; Line 679
; Line 680
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	F_ZSTATS_02A8
; Line 681
	jmp	SHORT $L20057
	nop	
$I601:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I604
; Line 689
	call	F_ZSTATS_039C
; Line 692
$L20057:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 693
	call	FUN_1000_266C_GET_CH
	jmp	SHORT $L20061
	nop	
$I604:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I605
; Line 699
	mov	ax,OFFSET DGROUP:$SG606
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET D_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20063
	nop	
$I605:
; Line 700
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I608
; Line 701
	mov	ax,OFFSET DGROUP:$SG609
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET D_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20063
	nop	
$I608:
; Line 702
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I611
; Line 703
	mov	ax,OFFSET DGROUP:$SG612
	push	ax
	mov	ax,38
	push	ax
	mov	ax,OFFSET D_B9EE
	push	ax
	mov	ax,OFFSET D_1916
$L20063:
	push	ax
	call	F_ZSTATS_06E8
$L20061:
	mov	BYTE PTR [bp-2],al	;local_6
; Line 704
	jmp	$D573
	nop	
$I611:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3230
	jmp	$D573
$JCC3230:
; Line 705
	mov	ax,OFFSET DGROUP:$SG615
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET D_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20063
$EX564:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_0A3A	ENDP
; Line 713
	PUBLIC	F_ZSTATS_0BEE
F_ZSTATS_0BEE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 714
	mov	ax,OFFSET DGROUP:$SG619
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 715
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850_PRINT_STRING
; Line 716
	mov	ax,OFFSET DGROUP:$SG620
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 717
	pop	bp
	ret	2
	nop	

F_ZSTATS_0BEE	ENDP
; Line 722
	PUBLIC	F_ZSTATS_0C0A
F_ZSTATS_0C0A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 723
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-2],ax	;s
; Line 725
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I625
	cmp	BYTE PTR [bx+28],255
	jne	$I625
; Line 726
	mov	ax,2
	jmp	SHORT $EX623
$I625:
; Line 727
	cmp	BYTE PTR [bx+27],255
	jne	$I627
; Line 728
	sub	ax,ax
	jmp	SHORT $EX623
$I627:
; Line 729
	cmp	BYTE PTR [bx+28],255
	jne	$I629
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	D_1A7E[bx],48
	je	$I629
; Line 730
	mov	ax,1
	jmp	SHORT $EX623
	nop	
$I629:
; Line 731
; Line 732
	mov	ax,255
$EX623:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0C0A	ENDP
; Line 741
	PUBLIC	F_ZSTATS_0C5C
F_ZSTATS_0C5C	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,16
	push	si
;	local_6 = -2
;	local_4 = -12
;	param_2 = 6
;	param_1 = 4
;	local_10 = -8
;	local_e = -14
;	local_c = -10
;	local_a = -6
;	local_8 = -4
; Line 751
	cmp	BYTE PTR D_5893_MAP_ID,127
	jbe	$I642
; Line 752
	mov	bl,D_589E
	sub	bh,bh
	mov	cl,3
	shl	bx,cl
	mov	al,D_BA18[bx]
	sub	ah,ah
	shl	ax,cl
	add	ax,OFFSET D_5C5A
	mov	WORD PTR [bp-2],ax	;local_6
; Line 753
; Line 757
$I642:
	cmp	WORD PTR [bp+4],27	;param_1
	je	$I644
	cmp	WORD PTR [bp+4],29	;param_1
	jne	$I643
$I644:
; Line 758
	sub	ax,ax
	jmp	$EX634
	nop	
$I643:
	cmp	WORD PTR [bp+4],9	;param_1
	jl	$I645
	cmp	WORD PTR [bp+4],15	;param_1
	jg	$I645
	cmp	BYTE PTR D_5893_MAP_ID,127
	jbe	$I645
	cmp	BYTE PTR D_58A3,0
	jne	$I645
; Line 763
	mov	ax,OFFSET DGROUP:$SG646
$L20086:
	push	ax
	call	F_ZSTATS_0BEE
	jmp	SHORT $I644
	nop	
$I645:
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	F_ZSTATS_0518
	or	ax,ax
	je	$I647
; Line 769
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_6E60
; Line 770
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	D_57C0[bx],99
	jae	$I649
; Line 771
	inc	D_57C0[bx]
; Line 772
; Line 774
$I649:
	cmp	BYTE PTR D_5893_MAP_ID,127
	jbe	$I644
	cmp	bx,42
	jne	$I644
	mov	ax,OFFSET DGROUP:$SG652
	push	ax
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	al,BYTE PTR D_55A8_PARTY[bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-4],ax	;local_8
; Line 782
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	si,ax
	mov	al,D_1ADE[si]
	mov	BYTE PTR [bx+1],al
	mov	BYTE PTR [bx],al
	jmp	$I644
	nop	
$I647:
; Line 786
	cmp	WORD PTR [bp+4],26	;param_1
	je	$I656
	cmp	WORD PTR [bp+4],36	;param_1
	jne	$I655
$I656:
	cmp	BYTE PTR D_57DB,0
	je	$I654
$I655:
	cmp	WORD PTR [bp+4],28	;param_1
	jne	$I653
	cmp	BYTE PTR D_57DD,0
	jne	$I653
$I654:
; Line 788
	mov	ax,OFFSET DGROUP:$SG657
	jmp	$L20086
$I653:
	sub	dx,dx
; Line 795
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	add	si,OFFSET D_55A8_PARTY+25
; Line 800
	mov	WORD PTR [bp-6],6	;local_a
	mov	WORD PTR [bp-16],6
	mov	cx,WORD PTR [bp-16]
$L20033:
; Line 801
	cmp	BYTE PTR [si],255
	je	$I661
; Line 802
	mov	bl,BYTE PTR [si]
	sub	bh,bh
	mov	al,D_1AAE[bx]
	sub	ah,ah
	add	dx,ax
; Line 803
; Line 805
$I661:
	inc	si
; Line 806
	loop	$L20033
	mov	WORD PTR [bp-8],si	;local_10
	mov	WORD PTR [bp-12],dx	;local_4
; Line 809
	mov	bx,WORD PTR [bp+4]	;param_1
	mov	al,D_1AAE[bx]
	sub	ah,ah
	add	ax,dx
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	cl,BYTE PTR D_55A8_PARTY[bx+12]
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
; Line 812
	mov	bx,WORD PTR [bp+4]	;param_1
	mov	al,D_1A7E[bx]
	sub	ah,ah
	cmp	ax,2
	je	$SC666
	cmp	ax,4
	je	$SC669
	cmp	ax,32
	je	$SC672
	cmp	ax,48
	jne	$JCC3706
	jmp	$SC676
$JCC3706:
	cmp	ax,64
	jne	$JCC3714
	jmp	$SC679
$JCC3714:
	cmp	ax,128
	jne	$JCC3722
	jmp	$SC682
$JCC3722:
	jmp	SHORT $SB663
	nop	
$SC666:
; Line 816
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	al,BYTE PTR D_55A8_PARTY[bx+29]
	sub	ah,ah
	cmp	ax,-1
	je	$I667
; Line 817
	mov	ax,OFFSET DGROUP:$SG668
	jmp	$L20086
$I667:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+29
$L20081:
	mov	WORD PTR [bp-8],ax	;local_10
; Line 822
$SB663:
; Line 877
	cmp	WORD PTR [bp-14],0	;local_e
	je	$JCC3771
	jmp	$I685
$JCC3771:
; Line 879
	mov	ax,OFFSET DGROUP:$SG686
	jmp	$L20086
$SC669:
; Line 825
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	al,BYTE PTR D_55A8_PARTY[bx+30]
	sub	ah,ah
	cmp	ax,-1
	je	$I670
; Line 826
	mov	ax,OFFSET DGROUP:$SG671
	jmp	$L20086
$I670:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+30
	jmp	SHORT $L20081
$SC672:
; Line 834
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_0C0A
	mov	WORD PTR [bp-10],ax	;local_c
; Line 835
	cmp	ax,255
	jne	$I673
; Line 836
	mov	ax,OFFSET DGROUP:$SG674
	jmp	$L20086
$I673:
	cmp	WORD PTR [bp-10],2	;local_c
	jne	$I675
; Line 841
	mov	WORD PTR [bp-10],0	;local_c
; Line 842
; Line 844
$I675:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,WORD PTR [bp-10]	;local_c
$L20094:
	add	ax,OFFSET D_55A8_PARTY+27
	jmp	SHORT $L20081
$SC676:
; Line 848
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_0C0A
	mov	WORD PTR [bp-10],ax	;local_c
; Line 849
	cmp	ax,2
	je	$I677
; Line 850
	mov	ax,OFFSET DGROUP:$SG678
	jmp	$L20086
$I677:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	jmp	SHORT $L20094
	nop	
$SC679:
; Line 858
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	cmp	BYTE PTR D_55A8_PARTY[bx+26],255
	je	$I680
; Line 859
	mov	ax,OFFSET DGROUP:$SG681
	jmp	$L20086
$I680:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+26
	jmp	$L20081
	nop	
$SC682:
; Line 867
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	cmp	BYTE PTR D_55A8_PARTY[bx+25],255
	je	$I683
; Line 868
	mov	ax,OFFSET DGROUP:$SG684
	jmp	$L20086
$I683:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+25
	jmp	$L20081
	nop	
$I685:
; Line 881
; Line 883
	mov	bx,WORD PTR [bp-8]	;local_10
	mov	al,BYTE PTR [bp+4]	;param_1
	mov	BYTE PTR [bx],al
; Line 884
	mov	bx,WORD PTR [bp+4]	;param_1
	dec	D_57C0[bx]
; Line 885
	cmp	D_57C0[bx],42
	je	$I690
	cmp	D_57C0[bx],44
	jne	$I689
$I690:
	sub	ax,ax
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_2092
	or	ax,ax
	jne	$I689
; Line 887
	mov	ax,OFFSET DGROUP:$SG691
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 888
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	BYTE PTR D_55A8_PARTY[bx+29],255
; Line 889
	mov	ax,1200
	push	ax
	mov	ax,2000
	push	ax
	mov	ax,1
	push	ax
	mov	ax,40
	push	ax
	call	FUN_1000_43AE
; Line 890
	mov	ax,1
	jmp	SHORT $EX634
$I689:
; Line 891
; Line 893
	cmp	WORD PTR [bp+4],42	;param_1
	je	$JCC4052
	jmp	$I644
$JCC4052:
	cmp	BYTE PTR D_5893_MAP_ID,127
	ja	$JCC4062
	jmp	$I644
$JCC4062:
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	BYTE PTR [bx+1],29
; Line 906
	mov	BYTE PTR [bx],29
	jmp	$I644
$EX634:
	pop	si
	mov	sp,bp
	pop	bp
	ret	4
	nop	

F_ZSTATS_0C5C	ENDP
; Line 915
	PUBLIC	F_ZSTATS_0F2E
F_ZSTATS_0F2E	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,32
	push	di
	push	si
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
;	param_3 = 8
;	param_2 = 6
;	param_1 = 4
;	local_1e = -4
;	local_1c = -24
;	local_1a = -16
; Line 932
	mov	WORD PTR [bp-8],0	;local_8
; Line 933
	mov	WORD PTR [bp-14],1	;local_10
; Line 934
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I715
; Line 935
	mov	WORD PTR [bp-28],22464	;local_14
; Line 936
	mov	WORD PTR [bp-12],48	;local_a
; Line 937
	jmp	SHORT $I716
$I715:
; Line 938
	mov	WORD PTR [bp-28],-17938	;local_14
; Line 939
	mov	WORD PTR [bp-12],38	;local_a
; Line 940
$I716:
; Line 943
	cmp	WORD PTR [bp-8],0	;local_8
	je	$I717
; Line 944
	mov	ax,WORD PTR [bp-16]	;local_1a
	jmp	$EX700
$I717:
; Line 948
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 949
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 950
	mov	WORD PTR [bp-22],0	;local_4
; Line 951
	mov	ax,WORD PTR [bp+8]	;param_3
$L20097:
	mov	WORD PTR [bp-20],ax	;local_12
; Line 954
; Line 955
	cmp	ax,-1
	jne	$I724
; Line 957
	mov	WORD PTR [bp-10],0	;local_18
; Line 958
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	add	ax,1
	je	$I725
; Line 959
	mov	WORD PTR [bp-10],2	;local_18
; Line 960
; Line 962
$I725:
	cmp	WORD PTR [bp-20],-1	;local_12
	je	$I727
; Line 963
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	add	ax,1
$L20101:
	je	$I727
; Line 964
	inc	WORD PTR [bp-10]	;local_18
; Line 965
; Line 966
$I727:
; Line 1027
	cmp	WORD PTR [bp-10],0	;local_18
	jne	$JCC4240
	jmp	$I740
$JCC4240:
; Line 1028
	cmp	WORD PTR [bp-10],1	;local_18
	je	$JCC4249
	jmp	$I741
$JCC4249:
; Line 1030
	mov	ax,25
	jmp	$L20099
$I724:
; Line 969
; Line 971
	inc	WORD PTR [bp-22]	;local_4
; Line 972
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I729
; Line 973
	mov	ax,253
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 974
	mov	ax,WORD PTR [bp-20]	;local_12
	mov	WORD PTR [bp-16],ax	;local_1a
; Line 975
; Line 978
$I729:
	cmp	WORD PTR [bp+4],82	;param_1
	je	$I730
; Line 980
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6422
	push	ax
	mov	ax,32
	push	ax
	jmp	SHORT $L20096
$I730:
; Line 981
; Line 983
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-20]	;local_12
	call	F_ZSTATS_0518
	or	ax,ax
	je	$I732
; Line 985
	mov	bx,WORD PTR [bp-20]	;local_12
	mov	al,D_1AE8[bx]
	sub	ah,ah
	mov	WORD PTR [bp-18],ax	;local_c
; Line 986
	jmp	SHORT $I733
	nop	
$I732:
; Line 988
	mov	WORD PTR [bp-18],32	;local_c
; Line 989
$I733:
; Line 991
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6498
	push	ax
	push	WORD PTR [bp-18]	;local_c
$L20096:
	call	F_ZSTATS_05E2
; Line 992
; Line 997
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 998
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	dec	ax
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I734
; Line 999
	mov	ax,253
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 1000
; Line 1003
$I734:
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	cmp	ax,8
	jne	$I735
; Line 1005
	mov	WORD PTR [bp-10],0	;local_18
; Line 1006
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	inc	ax
	je	$I736
; Line 1007
	mov	WORD PTR [bp-10],2	;local_18
; Line 1008
; Line 1010
$I736:
	cmp	WORD PTR [bp-20],-1	;local_12
	jne	$JCC4422
	jmp	$I727
$JCC4422:
; Line 1011
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	inc	ax
	jmp	$L20101
$I735:
; Line 1017
; Line 1019
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	jmp	$L20097
$I741:
; Line 1031
	cmp	WORD PTR [bp-10],2	;local_18
	jne	$I743
; Line 1033
	mov	ax,24
$L20099:
	push	ax
	call	FUN_1000_4DEA
; Line 1034
	jmp	SHORT $I746
	nop	
$I743:
	cmp	WORD PTR [bp-10],3	;local_18
	jne	$I746
; Line 1036
	mov	ax,18
	jmp	SHORT $L20099
	nop	
$I740:
; Line 1038
; Line 1040
	call	FUN_1000_4DAA
; Line 1041
$I746:
; Line 1045
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 1046
	call	FUN_1000_266C_GET_CH
	mov	WORD PTR [bp-6],ax	;local_16
; Line 1048
	cmp	ax,13
	jne	$JCC4511
	jmp	$SC781
$JCC4511:
	jle	$JCC4516
	jmp	$L20044
$JCC4516:
	cmp	ax,1
	je	$SC751
	cmp	ax,2
	je	$SC766
	cmp	ax,3
	je	$SC751
	cmp	ax,4
	jmp	$L20098
	nop	
	nop	
$SC751:
; Line 1055
	cmp	WORD PTR [bp-6],213	;local_16
	jne	$I752
; Line 1056
	mov	WORD PTR [bp-2],7	;local_6
; Line 1057
	jmp	SHORT $I753
$I752:
; Line 1058
	mov	WORD PTR [bp-2],1	;local_6
$I753:
; Line 1059
	mov	WORD PTR [bp-26],0	;local_e
; Line 1060
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4572
	jmp	$I716
$JCC4572:
; Line 1061
;	register si = si
;	register di = di
; Line 1065
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-24],ax	;local_1c
; Line 1066
	add	WORD PTR [bp-26],ax	;local_e
; Line 1067
	mov	di,WORD PTR [bp+8]	;param_3
; Line 1068
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1071
$D757:
; Line 1072
; Line 1073
	cmp	si,4
	je	$I761
	cmp	si,1
	jne	$I760
$I761:
; Line 1074
; Line 1076
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	inc	ax
	je	$I762
; Line 1077
; Line 1078
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	mov	di,ax
; Line 1079
; Line 1080
	jmp	SHORT $I765
	nop	
$I762:
; Line 1081
; Line 1083
	cmp	si,4
	jne	$I765
$I760:
; Line 1091
; Line 1093
	dec	si
; Line 1094
$I765:
; Line 1096
	dec	WORD PTR [bp-24]	;local_1c
	jne	$D757
; Line 1098
	mov	WORD PTR [bp+8],di	;param_3
; Line 1101
$L20106:
	mov	WORD PTR [bp-14],si	;local_10
; Line 1102
; Line 1103
	jmp	$I716
$SC766:
; Line 1110
	cmp	WORD PTR [bp-6],214	;local_16
	jne	$I767
; Line 1111
	mov	WORD PTR [bp-2],7	;local_6
; Line 1112
	jmp	SHORT $I768
$I767:
; Line 1113
	mov	WORD PTR [bp-2],1	;local_6
$I768:
; Line 1114
	mov	WORD PTR [bp-26],0	;local_e
; Line 1115
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4684
	jmp	$I716
$JCC4684:
; Line 1116
;	register si = si
;	register di = di
; Line 1120
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-4],ax	;local_1e
; Line 1121
	add	WORD PTR [bp-26],ax	;local_e
; Line 1122
	mov	di,WORD PTR [bp-20]	;local_12
; Line 1123
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1126
$D772:
; Line 1127
; Line 1128
	cmp	si,4
	je	$I776
	cmp	si,7
	je	$I776
	cmp	WORD PTR [bp-22],si	;local_4
	jge	$I775
$I776:
; Line 1129
; Line 1131
	mov	ax,di
	cmp	ax,-1
	je	$I777
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	inc	ax
	je	$I777
; Line 1132
; Line 1133
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1134
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	di,ax
; Line 1135
; Line 1136
	jmp	SHORT $I780
	nop	
$I777:
; Line 1137
; Line 1139
	cmp	si,4
	jne	$I780
	cmp	WORD PTR [bp-22],4	;local_4
	jne	$I780
$I775:
; Line 1146
; Line 1148
	inc	si
; Line 1149
$I780:
; Line 1151
	dec	WORD PTR [bp-4]	;local_1e
	jne	$D772
; Line 1153
	mov	WORD PTR [bp-20],di	;local_12
	jmp	$L20106
	nop	
$SC781:
; Line 1164
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I782
; Line 1165
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-16]	;local_1a
	call	F_ZSTATS_0C5C
	mov	WORD PTR [bp-8],ax	;local_8
; Line 1166
	jmp	$I716
	nop	
$I782:
; Line 1168
	mov	WORD PTR [bp-8],1	;local_8
; Line 1169
; Line 1171
	jmp	$I716
$SC784:
; Line 1175
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$L20039
	mov	ax,OFFSET DGROUP:$SG785
	jmp	SHORT $L20040
	nop	
$L20039:
	mov	ax,OFFSET DGROUP:$SG786
$L20040:
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 1176
	mov	WORD PTR [bp-8],1	;local_8
; Line 1177
	mov	WORD PTR [bp-16],-1	;local_1a
; Line 1180
	jmp	$I716
$SC787:
; Line 1185
	mov	ax,-1
	push	ax
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1186
	mov	WORD PTR [bp-14],1	;local_10
; Line 1188
	jmp	$I716
	nop	
$SC788:
; Line 1190
; Line 1194
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1196
	mov	di,1
; Line 1197
$D789:
; Line 1200
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	mov	si,ax
; Line 1201
	cmp	si,-1
	jne	$I792
; Line 1202
; Line 1204
$L20105:
	mov	WORD PTR [bp-14],di	;local_10
	mov	WORD PTR [bp-16],si	;local_1a
	jmp	$I716
$I792:
	mov	WORD PTR [bp+8],si	;param_3
; Line 1209
	inc	di
; Line 1210
	cmp	di,7
	jl	$D789
	jmp	SHORT $L20105
	nop	
$L20044:
	cmp	ax,27
	jne	$JCC4959
	jmp	$SC784
$JCC4959:
	cmp	ax,32
	jne	$JCC4967
	jmp	$SC781
$JCC4967:
	cmp	ax,211
	je	$SC787
	cmp	ax,212
	je	$SC788
	cmp	ax,213
	jne	$JCC4985
	jmp	$SC751
$JCC4985:
	cmp	ax,214
$L20098:
	jne	$JCC4993
	jmp	$SC766
$JCC4993:
	jmp	$I716
	nop	
$EX700:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	6

F_ZSTATS_0F2E	ENDP
; Line 1223
	PUBLIC	F_ZSTATS_1296
F_ZSTATS_1296	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	local_6 = -2
;	local_4 = -4
; Line 1228
	sub	ax,ax
	push	ax
	call	F_ZSTATS_0000
	mov	WORD PTR [bp-2],ax	;local_6
; Line 1230
	or	ax,ax
	jl	$END798
; Line 1231
	mov	ax,-1
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET D_57C0
	push	ax
	push	WORD PTR [bp-2]	;local_6
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-4],ax	;local_4
; Line 1235
	cmp	ax,-1
	jne	$I799
; Line 1236
; Line 1237
	mov	ax,-26242
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 1238
	jmp	SHORT $END798
$I799:
	mov	ax,-26216
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 1242
	call	FUN_1000_4EFC
; Line 1243
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 1245
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	push	ax
	call	FUN_1000_4E50
; Line 1247
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 1249
	push	WORD PTR [bp-4]	;local_4
	push	WORD PTR [bp-2]	;local_6
	mov	ax,82
	push	ax
	call	F_ZSTATS_0F2E
; Line 1251
	call	FUN_1000_4DAA
; Line 1252
	call	FUN_1000_4E20
; Line 1253
	call	FUN_1000_4F3C
; Line 1254
	call	FUN_1000_2900
; Line 1256
$END798:
; Line 1257
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_1296	ENDP
_TEXT	ENDS
END
