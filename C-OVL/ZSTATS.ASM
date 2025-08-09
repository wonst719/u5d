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
EXTRN	FUN_1000_2092:NEAR
EXTRN	FUN_1000_266C_GET_CH:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_2D7A:NEAR
EXTRN	FUN_1000_43AE:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	FUN_1000_4D76:NEAR
EXTRN	FUN_1000_4DAA:NEAR
EXTRN	FUN_1000_1850_PRINT_STRING:NEAR
EXTRN	FUN_1000_4DEA:NEAR
EXTRN	FUN_1000_4E20:NEAR
EXTRN	FUN_1000_1A3E:NEAR
EXTRN	FUN_1000_4E50:NEAR
EXTRN	FUN_1000_4EFC:NEAR
EXTRN	FUN_1000_4F3C:NEAR
EXTRN	FUN_1000_1B94_GET_TEXT_EFFECTS:NEAR
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_1000_6E60:NEAR
EXTRN	FUN_1000_1C22_SET_TEXT_WINDOW_S:NEAR
EXTRN	FUN_1000_1C9E_GET_CHAR_SEGMENT:NEAR
EXTRN	FUN_1000_1CEE_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_1F12_GET_CURRENT_TEXT_:NEAR
EXTRN	D_BA12:BYTE
EXTRN	D_1A58:WORD
EXTRN	D_55A8_PARTY:BYTE
EXTRN	D_BA13:BYTE
EXTRN	D_1A6A:BYTE
EXTRN	D_1A7E:BYTE
EXTRN	D_57A8:BYTE
EXTRN	D_BA16:BYTE
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
_BSS      ENDS
_DATA      SEGMENT
$SG462	DB	'Player: ',  00H
$SG466	DB	'None!',  0aH,  00H
$SG478	DB	'AMBFDTPRS',  00H
$SG479	DB	'GPDSC',  00H
$SG485	DB	' Lv-',  00H
$SG486	DB	'Str=',  00H
$SG487	DB	'  HP:',  00H
$SG488	DB	0aH, 'Int=',  00H
$SG489	DB	'  HM:',  00H
$SG490	DB	0aH, 'Dex=',  00H
$SG491	DB	'  Ex:',  00H
$SG492	DB	0aH,  0aH, '    Magic:',  00H
$SG503	DB	'Arms',  0aH,  0aH,  00H
$SG505	DB	'(None ready)',  00H
$SG508	DB	'Equipment',  00H
$SG509	DB	0aH, ' Food: ',  00H
$SG510	DB	0aH, ' Gold: ',  00H
$SG511	DB	0aH,  0aH, ' Keys.......',  00H
$SG512	DB	0aH, ' Gems.......',  00H
$SG513	DB	0aH, ' Torches....',  00H
$SG515	DB	0aH, ' Grapple',  00H
$SG572	DB	'--',  00H
$SG575	DB	1cH, ' + ',  00H
$SG578	DB	1dH, ' + ',  00H
$SG581	DB	'Moonstone ',  00H
$SG603	DB	'(None owned!)',  00H
$SG687	DB	0aH, 'Status: ',  00H
$SG712	DB	'Done',  0aH,  00H
$SG718	DB	'Reagents',  00H
$SG721	DB	'Spells',  00H
$SG724	DB	'Items',  00H
$SG727	DB	'Armaments',  00H
$SG731	DB	0aH,  0aH,  00H
$SG732	DB	0aH,  0aH, 'Item: ',  00H
$SG758	DB	'Thou canst not change armour in heated battle!',  00H
$SG763	DB	'AMBFDTPRS',  00H
$SG768	DB	'Thou hast no ammunition for that weapon!',  00H
$SG779	DB	'Only one magic ring may be worn at a time!',  00H
$SG782	DB	'Thou must remove thine other amulet!',  00H
$SG785	DB	'Thou must free one of thy hands first!',  00H
$SG789	DB	'Both hands must be free before thou canst wield that!',  00H
$SG792	DB	'Thou must first remove thine other armour!',  00H
$SG795	DB	'Remove first thy present helm!',  00H
$SG797	DB	'Thou art not strong enough!',  00H
$SG801	DB	0aH,  0aH, 'Ring vanishes!',  0aH,  00H
$SG894	DB	'Thou art empty-',  0aH, 'handed!',  0aH,  00H
$SG895	DB	'Item: ',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 56
	PUBLIC	F_ZSTATS_0000
F_ZSTATS_0000	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 61
	mov	WORD PTR [bp-4],-1	;local_4
; Line 63
	cmp	BYTE PTR D_5893_MAP_ID,128
	jbe	$I458
; Line 64
	mov	al,D_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 65
	test	D_BA16[si],128
	je	$I458
; Line 66
	mov	al,D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 69
	jmp	SHORT $I464
$I458:
; Line 72
	mov	ax,OFFSET DGROUP:$SG462
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 73
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_2D7A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 74
	or	ax,ax
	jl	$I464
; Line 75
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 76
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	or	ax,ax
	je	$I464
; Line 77
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 78
; Line 79
$I464:
; Line 80
; Line 83
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I465
; Line 84
	mov	ax,OFFSET DGROUP:$SG466
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 85
; Line 87
	jmp	SHORT $I468
$I465:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I468
; Line 88
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 89
; Line 92
$I468:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0000	ENDP
; Line 98
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
; Line 108
	call	FUN_1000_4DAA
; Line 110
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-12],ax	;local_4
; Line 112
	push	ax
	call	FUN_1000_4E50
; Line 113
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
; Line 114
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 115
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
; Line 117
	mov	ax,OFFSET DGROUP:$SG478
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-2],ax	;local_6
; Line 118
	mov	ax,OFFSET DGROUP:$SG479
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-6],ax	;local_a
; Line 119
	mov	WORD PTR [bp-4],0	;local_8
; Line 121
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	D_1A58[bx],0
	jle	$I480
; Line 122
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 124
	sub	si,si
; Line 125
$FC482:
; Line 126
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 127
	inc	si
; Line 128
	cmp	WORD PTR [di],si
	jg	$FC482
; Line 129
; Line 132
	mov	WORD PTR [bp-4],si	;local_8
; Line 133
; Line 135
$I480:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 136
	mov	ax,OFFSET DGROUP:$SG485
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 137
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 138
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 139
	mov	ax,WORD PTR [bp-2]	;local_6
	add	ax,OFFSET D_1A44
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 140
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
; Line 141
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 142
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 143
	mov	ax,WORD PTR [bp-6]	;local_a
	add	ax,OFFSET D_1A6A
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 144
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
; Line 145
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 146
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 147
	mov	ax,OFFSET DGROUP:$SG486
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 148
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 149
	mov	ax,OFFSET DGROUP:$SG487
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 150
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 151
	mov	ax,OFFSET DGROUP:$SG488
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 152
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 153
	mov	ax,OFFSET DGROUP:$SG489
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 154
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 155
	mov	ax,OFFSET DGROUP:$SG490
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 156
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_1000_1A3E
; Line 157
	mov	ax,OFFSET DGROUP:$SG491
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 158
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 159
	mov	ax,OFFSET DGROUP:$SG492
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 160
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 161
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

F_ZSTATS_0082	ENDP
; Line 166
	PUBLIC	F_ZSTATS_0278
F_ZSTATS_0278	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 167
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I496
; Line 168
	sub	ax,ax
	jmp	SHORT $EX495
$I496:
; Line 169
; Line 170
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 171
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	D_1962[bx]
	call	FUN_1000_1850_PRINT_STRING
; Line 172
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 173
	mov	ax,1
$EX495:
	pop	bp
	ret	2
	nop	

F_ZSTATS_0278	ENDP
; Line 180
	PUBLIC	F_ZSTATS_02A8
F_ZSTATS_02A8	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	param_1 = 4
;	local_4 = -4
;	local_6 = -2
; Line 184
	call	FUN_1000_4DAA
; Line 186
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-2],ax	;local_6
; Line 187
	push	ax
	call	FUN_1000_4E50
; Line 188
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
; Line 189
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 190
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 191
	mov	ax,254
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 192
	mov	ax,OFFSET DGROUP:$SG503
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 193
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 194
	mov	ax,254
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 196
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+25]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	mov	WORD PTR [bp-4],ax	;local_4
; Line 197
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+26]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 198
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+27]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 199
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+28]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 200
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+29]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 201
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	al,BYTE PTR [bx+30]
	sub	ah,ah
	push	ax
	call	F_ZSTATS_0278
	add	WORD PTR [bp-4],ax	;local_4
; Line 203
	jne	$I504
; Line 204
	sub	ax,ax
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 205
	mov	ax,252
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 206
	mov	ax,OFFSET DGROUP:$SG505
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 207
	mov	ax,251
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 208
; Line 210
$I504:
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
; Line 211
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_02A8	ENDP
; Line 216
	PUBLIC	F_ZSTATS_039C
F_ZSTATS_039C	PROC NEAR
; Line 217
	call	FUN_1000_4DAA
; Line 218
	mov	ax,OFFSET DGROUP:$SG508
	push	ax
	call	FUN_1000_4E50
; Line 219
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
; Line 220
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 221
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
; Line 222
	mov	ax,OFFSET DGROUP:$SG509
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 223
	mov	al,D_57A8
	sub	ah,ah
	push	ax
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 224
	mov	ax,OFFSET DGROUP:$SG510
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 225
	mov	al,D_57AA
	sub	ah,ah
	push	ax
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 226
	mov	ax,OFFSET DGROUP:$SG511
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 227
	mov	al,D_57AC
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 228
	mov	ax,OFFSET DGROUP:$SG512
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 229
	mov	al,D_57AD
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 230
	mov	ax,OFFSET DGROUP:$SG513
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 231
	mov	al,D_57AE
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 232
	cmp	BYTE PTR D_57AF,0
	je	$I514
; Line 233
	mov	ax,OFFSET DGROUP:$SG515
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 234
; Line 235
$I514:
	ret	

F_ZSTATS_039C	ENDP
; Line 240
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
; Line 244
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
; Line 245
	mov	ax,255
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 246
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
; Line 247
	mov	ax,16
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 248
	mov	WORD PTR [bp-4],13	;local_4
; Line 249
	mov	si,13
$L20000:
; Line 250
	mov	ax,17
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 251
	dec	si
	jne	$L20000
; Line 252
	mov	ax,19
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 253
	mov	si,1
	mov	di,WORD PTR [bp+4]	;param_1
	jmp	SHORT $L20002
$L20001:
; Line 254
	sub	ax,ax
	push	ax
	push	si
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 255
	mov	ax,23
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 256
	mov	ax,14
	push	ax
	push	si
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 257
	mov	ax,23
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 258
	inc	si
$L20002:
	cmp	di,si
	jne	$L20001
; Line 259
	mov	WORD PTR [bp-4],si	;local_4
; Line 260
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 261
	mov	ax,20
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 262
	mov	WORD PTR [bp-4],13	;local_4
; Line 263
	mov	si,13
$L20003:
; Line 264
	mov	ax,21
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 265
	dec	si
	jne	$L20003
; Line 266
	mov	ax,22
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 267
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2

F_ZSTATS_045E	ENDP
; Line 272
	PUBLIC	F_ZSTATS_0518
F_ZSTATS_0518	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_2 = 6
;	param_1 = 4
;	local_4 = -2
; Line 273
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-2],ax	;local_4
; Line 280
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
	jmp	SHORT $EX533
$L20004:
	sub	ax,ax
$EX533:
	mov	sp,bp
	pop	bp
	ret	4

F_ZSTATS_0518	ENDP
; Line 286
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
; Line 287
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_3
$FC542:
; Line 288
	dec	si
	js	$L20012
; Line 289
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I545
; Line 290
	cmp	di,255
	je	$FC542
; Line 291
	push	di
	push	si
	call	F_ZSTATS_0518
	or	ax,ax
	je	$FC542
; Line 293
; Line 296
$I545:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_3
	jmp	SHORT $EX540
$L20012:
	mov	WORD PTR [bp+10],si	;param_3
; Line 302
	mov	ax,-1
$EX540:
	pop	si
	pop	di
	pop	bp
	ret	8

F_ZSTATS_056C	ENDP
; Line 308
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
; Line 309
	mov	di,WORD PTR [bp+4]	;param_1
	mov	si,WORD PTR [bp+10]	;param_4
$FC555:
; Line 310
	inc	si
	mov	ax,WORD PTR [bp+8]	;param_3
	cmp	si,ax
	jge	$L20014
; Line 311
	mov	bx,WORD PTR [bp+6]	;param_2
	cmp	BYTE PTR [bx][si],0
	jne	$I558
; Line 312
	cmp	di,255
	je	$FC555
; Line 313
	push	di
	push	si
	call	F_ZSTATS_0518
	or	ax,ax
	je	$FC555
; Line 315
; Line 318
$I558:
	mov	ax,si
	mov	WORD PTR [bp+10],si	;param_4
	jmp	SHORT $EX553
	nop	
$L20014:
	mov	WORD PTR [bp+10],si	;param_4
; Line 324
	mov	ax,-1
$EX553:
	pop	si
	pop	di
	pop	bp
	ret	8

F_ZSTATS_05A4	ENDP
; Line 330
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
; Line 334
	mov	bx,WORD PTR [bp+10]	;param_4
	mov	si,WORD PTR [bp+8]	;param_3
	mov	al,[bx][si]
	mov	BYTE PTR [bp-2],al	;local_6
; Line 335
	cmp	al,255
	je	$I569
; Line 336
	or	al,al
	je	$I570
; Line 337
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_1000_1A3E
; Line 338
	jmp	SHORT $I571
	nop	
$I570:
; Line 339
	mov	ax,OFFSET DGROUP:$SG572
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 340
$I571:
; Line 341
	cmp	WORD PTR [bp+4],32	;param_1
	jae	$I573
; Line 342
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 343
; Line 344
$I573:
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_16BA_PRINT_CHAR
; Line 345
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 346
; Line 348
$I569:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],42
	jne	$I574
; Line 349
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 350
	mov	ax,OFFSET DGROUP:$SG575
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 351
	lea	ax,WORD PTR [si+1]
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 352
$L20045:
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 353
	jmp	SHORT $I582
$I574:
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	mov	bx,[bx][si]
	cmp	BYTE PTR [bx],33
	jne	$I577
; Line 354
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 355
	mov	ax,OFFSET DGROUP:$SG578
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 356
	sub	ax,ax
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 357
	mov	ax,WORD PTR [bp+10]	;param_4
	add	ax,D_19B2
	push	ax
	jmp	SHORT $L20046
	nop	
$I577:
; Line 358
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,[bx][di]
	cmp	BYTE PTR [si],40
	jne	$I580
; Line 359
	mov	ax,OFFSET DGROUP:$SG581
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 360
	mov	ax,1
	push	ax
	call	FUN_1000_1C9E_GET_CHAR_SEGMENT
; Line 361
	mov	al,BYTE PTR [si+1]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
	jmp	SHORT $L20045
$I580:
; Line 363
; Line 364
	mov	bx,WORD PTR [bp+10]	;param_4
	shl	bx,1
	mov	si,WORD PTR [bp+6]	;param_2
	push	WORD PTR [bx][si]
$L20046:
	call	FUN_1000_1850_PRINT_STRING
; Line 365
$I582:
; Line 368
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	mov	WORD PTR [bp-4],ax	;local_4
; Line 369
	cmp	ax,14
	jge	$I584
;	register si = si
; Line 370
	mov	ax,14
	sub	ax,WORD PTR [bp-4]	;local_4
	mov	si,ax
; Line 371
	add	WORD PTR [bp-4],si	;local_4
; Line 373
$D586:
; Line 374
	mov	ax,32
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 375
	dec	si
; Line 376
	jne	$D586
; Line 377
; Line 378
$I584:
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 379
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

F_ZSTATS_05E2	ENDP
; Line 386
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
; Line 395
	push	WORD PTR [bp+10]	;param_4
	call	FUN_1000_4E50
; Line 396
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 397
	mov	WORD PTR [bp-4],0	;local_8
; Line 398
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 399
	cmp	ax,-1
	je	$JCC1819
	jmp	$I663
$JCC1819:
; Line 400
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 401
	mov	ax,1
	push	ax
	mov	ax,4
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 402
	mov	ax,OFFSET DGROUP:$SG603
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 403
	call	FUN_1000_4DAA
; Line 404
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 405
	call	FUN_1000_266C_GET_CH
	jmp	$EX594
	nop	
$FC606:
; Line 409
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 410
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 414
	mov	ax,WORD PTR [bp-2]	;local_6
	jmp	SHORT $L20047
$FC609:
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
$L20047:
	mov	WORD PTR [bp-10],ax	;local_c
	cmp	ax,-1
	je	$FB610
; Line 416
	push	ax
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	mov	ax,45
	push	ax
	call	F_ZSTATS_05E2
; Line 418
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 419
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	cmp	ax,8
	jne	$FC609
; Line 420
$FB610:
; Line 424
	mov	WORD PTR [bp-8],0	;local_10
; Line 425
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I612
; Line 426
	mov	WORD PTR [bp-8],2	;local_10
; Line 427
; Line 430
$I612:
	cmp	WORD PTR [bp-10],-1	;local_c
	je	$I613
	push	WORD PTR [bp-10]	;local_c
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I613
; Line 431
	inc	WORD PTR [bp-8]	;local_10
; Line 432
; Line 435
$I613:
	mov	ax,WORD PTR [bp-8]	;local_10
	or	ax,ax
	je	$SC618
	cmp	ax,1
	je	$SC619
	cmp	ax,2
	je	$SC620
	cmp	ax,3
	je	$SC621
	jmp	SHORT $SB615
$SC618:
; Line 437
	call	FUN_1000_4DAA
; Line 439
$SB615:
; Line 453
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 454
	call	FUN_1000_266C_GET_CH
	mov	WORD PTR [bp-14],ax	;local_e
; Line 455
	cmp	ax,32
	jne	$I622
	jmp	$L20051
$SC619:
; Line 441
	mov	ax,25
$L20048:
	push	ax
	call	FUN_1000_4DEA
; Line 443
	jmp	SHORT $SB615
	nop	
$SC620:
; Line 445
	mov	ax,24
	jmp	SHORT $L20048
	nop	
$SC621:
; Line 448
	mov	ax,18
	jmp	SHORT $L20048
	nop	
$I622:
; Line 459
	cmp	WORD PTR [bp-14],32	;local_e
	jle	$JCC2074
	jmp	$I624
$JCC2074:
; Line 461
	cmp	WORD PTR [bp-14],3	;local_e
	jne	$I625
; Line 463
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I626
; Line 464
	mov	WORD PTR [bp-12],7	;local_4
; Line 465
	jmp	SHORT $I627
	nop	
$I626:
; Line 467
	mov	WORD PTR [bp-12],1	;local_4
; Line 468
$I627:
; Line 470
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2114
	jmp	$I663
$JCC2114:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20016:
; Line 471
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I631
; Line 472
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	si,ax
; Line 473
; Line 474
$I631:
	dec	di
	jne	$L20016
$L20055:
	mov	WORD PTR [bp-2],si	;local_6
; Line 475
	jmp	$I663
$I625:
	cmp	WORD PTR [bp-14],3	;local_e
	jg	$I632
; Line 479
	cmp	WORD PTR [bp-14],1	;local_e
	jge	$JCC2182
	jmp	$I663
$JCC2182:
; Line 481
	cmp	WORD PTR [bp-14],2	;local_e
$L20053:
	jle	$JCC2191
	jmp	$I663
$JCC2191:
; Line 483
$L20051:
	mov	WORD PTR [bp-4],1	;local_8
; Line 484
	jmp	$I663
$I632:
	cmp	WORD PTR [bp-14],4	;local_e
	jne	$I635
; Line 493
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I636
; Line 494
	mov	WORD PTR [bp-12],7	;local_4
; Line 495
	jmp	SHORT $I637
$I636:
; Line 496
	mov	WORD PTR [bp-12],1	;local_4
; Line 497
$I637:
; Line 499
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2238
	jmp	$I663
$JCC2238:
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-18],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20018:
; Line 500
	cmp	si,-1
	je	$I641
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I641
; Line 501
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 502
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	si,ax
; Line 503
; Line 504
$I641:
	dec	WORD PTR [bp-18]
	jne	$L20018
$L20056:
	mov	WORD PTR [bp-10],si	;local_c
; Line 505
	jmp	$I663
$I635:
	cmp	WORD PTR [bp-14],27	;local_e
	je	$JCC2324
	jmp	$I663
$JCC2324:
	jmp	$L20051
$I624:
; Line 514
	cmp	WORD PTR [bp-14],211	;local_e
	jne	$I644
; Line 516
	mov	ax,-1
	push	ax
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 517
	jmp	$I663
$I644:
; Line 518
	cmp	WORD PTR [bp-14],211	;local_e
	jg	$I646
; Line 519
	cmp	WORD PTR [bp-14],48	;local_e
	jge	$JCC2373
	jmp	$I663
$JCC2373:
; Line 520
	cmp	WORD PTR [bp-14],54	;local_e
	jmp	$L20053
	nop	
$I646:
; Line 528
	cmp	WORD PTR [bp-14],212	;local_e
	jne	$I650
; Line 530
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	di,ax
; Line 531
	sub	si,si
; Line 533
$L20020:
	push	di
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$L20021
; Line 535
	mov	di,WORD PTR [bp-10]	;local_c
; Line 536
	inc	si
; Line 537
	cmp	si,6
	jl	$L20020
$L20021:
	mov	WORD PTR [bp-2],di	;local_6
	mov	WORD PTR [bp-6],si	;local_a
; Line 538
	jmp	$I663
$I650:
; Line 539
	cmp	WORD PTR [bp-14],213	;local_e
	jne	$I655
; Line 542
	jne	$I656
; Line 543
	mov	WORD PTR [bp-12],7	;local_4
; Line 544
	jmp	SHORT $I657
$I656:
; Line 546
	mov	WORD PTR [bp-12],1	;local_4
; Line 547
$I657:
; Line 549
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jg	$JCC2478
	jmp	$I663
$JCC2478:
	mov	di,WORD PTR [bp-12]	;local_4
	mov	ax,di
	add	WORD PTR [bp-6],ax	;local_a
	mov	si,WORD PTR [bp-2]	;local_6
$L20022:
; Line 550
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	inc	ax
	je	$I661
; Line 551
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp+6]	;param_2
	mov	ax,255
	push	ax
	call	F_ZSTATS_056C
	mov	si,ax
; Line 552
; Line 553
$I661:
	dec	di
	jne	$L20022
	jmp	$L20055
	nop	
$I655:
; Line 555
	cmp	WORD PTR [bp-14],214	;local_e
	jne	$I663
; Line 558
	jne	$I664
; Line 559
	mov	WORD PTR [bp-12],7	;local_4
; Line 560
	jmp	SHORT $I665
$I664:
; Line 561
	mov	WORD PTR [bp-12],1	;local_4
; Line 562
$I665:
; Line 563
	mov	WORD PTR [bp-6],0	;local_a
	cmp	WORD PTR [bp-12],0	;local_4
	jle	$I663
	mov	ax,WORD PTR [bp-12]	;local_4
	mov	WORD PTR [bp-20],ax
	add	WORD PTR [bp-6],ax	;local_a
	mov	di,WORD PTR [bp+6]	;param_2
	mov	si,WORD PTR [bp-10]	;local_c
$L20024:
; Line 564
	cmp	si,-1
	je	$I669
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	inc	ax
	je	$I669
; Line 565
	push	WORD PTR [bp-2]	;local_6
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-2],ax	;local_6
; Line 566
	push	si
	push	WORD PTR [bp+8]	;param_3
	push	di
	mov	ax,255
	push	ax
	call	F_ZSTATS_05A4
	mov	si,ax
; Line 567
; Line 568
$I669:
	dec	WORD PTR [bp-20]
	jne	$L20024
	jmp	$L20056
$I663:
	cmp	WORD PTR [bp-4],0	;local_8
	jne	$JCC2644
	jmp	$FC606
$JCC2644:
; Line 574
; Line 576
	mov	ax,WORD PTR [bp-14]	;local_e
$EX594:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	8

F_ZSTATS_06E8	ENDP
; Line 582
	PUBLIC	F_ZSTATS_099A
F_ZSTATS_099A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	di
	push	si
;	local_4 = -2
; Line 585
	sub	si,si
; Line 586
$D673:
; Line 587
	mov	al,BYTE PTR D_5820[si]
	mov	BYTE PTR D_B9EE[si],al
; Line 588
	mov	al,BYTE PTR D_5828[si]
	mov	BYTE PTR D_B9F6[si],al
; Line 589
	cmp	BYTE PTR D_5840[si],255
	jne	$L20026
	mov	al,255
	jmp	SHORT $L20027
	nop	
$L20026:
	sub	al,al
$L20027:
	mov	BYTE PTR D_BA03[si],al
; Line 590
	inc	si
	cmp	si,8
	jl	$D673
	mov	WORD PTR [bp-2],si	;local_4
; Line 592
	mov	al,D_57B0
	mov	D_B9FE,al
; Line 593
	mov	al,D_57B1
	mov	D_B9FF,al
; Line 594
	mov	al,D_57B3
	mov	D_BA00,al
; Line 595
	mov	al,D_57B4
	mov	D_BA01,al
; Line 596
	mov	al,D_57B5
	mov	D_BA02,al
; Line 598
	mov	WORD PTR [bp-2],0	;local_4
	mov	cx,1
	mov	di,OFFSET D_BA0B
	mov	si,OFFSET D_57B6
	push	ds
	pop	es
	rep	movsw
	movsb
	add	WORD PTR [bp-2],3	;local_4
; Line 602
	mov	al,D_57BA
	mov	D_BA0E,al
; Line 603
	cmp	BYTE PTR D_57BB,0
	je	$L20031
	mov	al,255
	jmp	SHORT $L20032
	nop	
$L20031:
	sub	al,al
$L20032:
	mov	D_BA0F,al
; Line 604
	mov	al,D_57BC
	mov	D_BA10,al
; Line 605
	mov	al,D_57BD
	mov	D_BA11,al
; Line 606
	mov	al,D_57BE
	mov	D_BA12,al
; Line 607
	mov	al,D_57BF
	mov	D_BA13,al
; Line 608
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_099A	ENDP
; Line 613
	PUBLIC	F_ZSTATS_0A3A
F_ZSTATS_0A3A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
;	local_8 = -4
;	local_6 = -2
;	local_4 = -6
; Line 618
	mov	ax,1
	push	ax
	call	F_ZSTATS_0000
	mov	WORD PTR [bp-4],ax	;local_8
; Line 619
	cmp	ax,-2
	jne	$I684
; Line 620
	mov	WORD PTR [bp-4],6	;local_8
; Line 621
	jmp	SHORT $I685
	nop	
$I684:
	cmp	WORD PTR [bp-4],0	;local_8
	jge	$JCC2854
	jmp	$EX680
$JCC2854:
; Line 622
$I685:
	mov	ax,OFFSET DGROUP:$SG687
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 626
	call	F_ZSTATS_099A
; Line 627
	call	FUN_1000_4EFC
; Line 628
	mov	ax,WORD PTR [bp-4]	;local_8
	shl	ax,1
	mov	WORD PTR [bp-6],ax	;local_4
; Line 629
	mov	BYTE PTR [bp-2],0	;local_6
; Line 632
$D688:
; Line 633
; Line 634
	cmp	BYTE PTR [bp-2],32	;local_6
	jne	$JCC2888
	jmp	$I694
$JCC2888:
	cmp	BYTE PTR [bp-2],27	;local_6
	jne	$JCC2897
	jmp	$I694
$JCC2897:
; Line 635
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	cmp	ax,3
	je	$I696
	cmp	al,1
	jne	$I695
$I696:
; Line 636
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I697
; Line 637
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
$L20058:
	mov	WORD PTR [bp-6],ax	;local_4
; Line 638
; Line 639
	jmp	SHORT $I711
	nop	
$I697:
	cmp	WORD PTR [bp-6],1	;local_4
	jge	$I699
; Line 640
	mov	WORD PTR [bp-6],16	;local_4
; Line 641
; Line 642
	jmp	SHORT $I711
	nop	
$I699:
; Line 643
	dec	WORD PTR [bp-6]	;local_4
; Line 644
; Line 645
	jmp	SHORT $I711
	nop	
$I695:
; Line 646
	cmp	BYTE PTR [bp-2],2	;local_6
	je	$I703
	cmp	BYTE PTR [bp-2],4	;local_6
	jne	$I702
$I703:
; Line 647
	mov	bx,22619
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	shl	ax,1
	dec	ax
	cmp	ax,WORD PTR [bp-6]	;local_4
	je	$I709
; Line 648
	cmp	WORD PTR [bp-6],16	;local_4
	jge	$I705
; Line 649
	inc	WORD PTR [bp-6]	;local_4
; Line 650
	jmp	SHORT $I711
$I705:
; Line 651
	mov	WORD PTR [bp-6],0	;local_4
; Line 652
; Line 653
	jmp	SHORT $I711
	nop	
$I702:
; Line 655
	cmp	BYTE PTR [bp-2],4	;local_6
	jbe	$I709
; Line 656
	cmp	BYTE PTR [bp-2],48	;local_6
	je	$I709
; Line 657
	jbe	$I711
	cmp	BYTE PTR [bp-2],55	;local_6
	jae	$I711
	mov	al,BYTE PTR [bp-2]	;local_6
	sub	ah,ah
	mov	si,ax
	lea	ax,WORD PTR [si-49]
	mov	bx,22619
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	cmp	ax,cx
	jae	$I711
; Line 658
	mov	ax,si
	shl	ax,1
	sub	ax,98
	jmp	SHORT $L20058
$I709:
; Line 663
	mov	WORD PTR [bp-6],12	;local_4
; Line 664
; Line 665
$I711:
; Line 673
; Line 676
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 677
	cmp	WORD PTR [bp-6],12	;local_4
	jge	$I713
; Line 678
	test	BYTE PTR [bp-6],1	;local_4
	jne	$I714
; Line 679
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	F_ZSTATS_0082
; Line 680
	jmp	SHORT $L20057
	nop	
$I694:
; Line 665
; Line 666
	call	FUN_1000_4DAA
; Line 667
	call	FUN_1000_4E20
; Line 668
	call	FUN_1000_4F3C
; Line 669
	call	FUN_1000_2900
; Line 670
	mov	ax,OFFSET DGROUP:$SG712
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 671
	jmp	$EX680
$I714:
; Line 680
; Line 681
	mov	ax,WORD PTR [bp-6]	;local_4
	sar	ax,1
	push	ax
	call	F_ZSTATS_02A8
; Line 682
	jmp	SHORT $L20057
	nop	
$I713:
	cmp	WORD PTR [bp-6],12	;local_4
	jne	$I716
; Line 690
	call	F_ZSTATS_039C
; Line 693
$L20057:
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 694
	call	FUN_1000_266C_GET_CH
	jmp	SHORT $L20061
	nop	
$I716:
	cmp	WORD PTR [bp-6],13	;local_4
	jne	$I717
; Line 700
	mov	ax,OFFSET DGROUP:$SG718
	push	ax
	mov	ax,8
	push	ax
	mov	ax,OFFSET D_5850
	push	ax
	mov	ax,OFFSET D_19D2
	jmp	SHORT $L20063
	nop	
$I717:
; Line 701
	cmp	WORD PTR [bp-6],14	;local_4
	jne	$I720
; Line 702
	mov	ax,OFFSET DGROUP:$SG721
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET D_58F0
	push	ax
	mov	ax,OFFSET D_19E2
	jmp	SHORT $L20063
	nop	
$I720:
; Line 703
	cmp	WORD PTR [bp-6],15	;local_4
	jne	$I723
; Line 704
	mov	ax,OFFSET DGROUP:$SG724
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
; Line 705
	jmp	$D688
	nop	
$I723:
	cmp	WORD PTR [bp-6],16	;local_4
	je	$JCC3230
	jmp	$D688
$JCC3230:
; Line 706
	mov	ax,OFFSET DGROUP:$SG727
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET D_57C0
	push	ax
	mov	ax,OFFSET D_1962
	jmp	SHORT $L20063
$EX680:
	pop	si
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_0A3A	ENDP
; Line 714
	PUBLIC	F_ZSTATS_0BEE
F_ZSTATS_0BEE	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 715
	mov	ax,OFFSET DGROUP:$SG731
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 716
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_1850_PRINT_STRING
; Line 717
	mov	ax,OFFSET DGROUP:$SG732
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 718
	pop	bp
	ret	2
	nop	

F_ZSTATS_0BEE	ENDP
; Line 723
	PUBLIC	F_ZSTATS_0C0A
F_ZSTATS_0C0A	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,2
;	param_1 = 4
;	s = -2
; Line 724
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	mov	WORD PTR [bp-2],ax	;s
; Line 726
	mov	bx,ax
	cmp	BYTE PTR [bx+27],255
	jne	$I737
	cmp	BYTE PTR [bx+28],255
	jne	$I737
; Line 727
	mov	ax,2
	jmp	SHORT $EX735
$I737:
; Line 728
	cmp	BYTE PTR [bx+27],255
	jne	$I739
; Line 729
	sub	ax,ax
	jmp	SHORT $EX735
$I739:
; Line 730
	cmp	BYTE PTR [bx+28],255
	jne	$I741
	mov	bl,BYTE PTR [bx+27]
	sub	bh,bh
	cmp	D_1A7E[bx],48
	je	$I741
; Line 731
	mov	ax,1
	jmp	SHORT $EX735
	nop	
$I741:
; Line 732
; Line 733
	mov	ax,255
$EX735:
	mov	sp,bp
	pop	bp
	ret	2
	nop	

F_ZSTATS_0C0A	ENDP
; Line 742
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
; Line 756
	cmp	BYTE PTR D_5893_MAP_ID,127
	jbe	$I754
; Line 757
	mov	bl,D_589E
	sub	bh,bh
	mov	cl,3
	shl	bx,cl
	mov	al,D_BA18[bx]
	sub	ah,ah
	shl	ax,cl
	add	ax,OFFSET D_5C5A
	mov	WORD PTR [bp-2],ax	;local_6
; Line 758
; Line 762
$I754:
	cmp	WORD PTR [bp+4],27	;param_1
	je	$I756
	cmp	WORD PTR [bp+4],29	;param_1
	jne	$I755
$I756:
; Line 763
	sub	ax,ax
	jmp	$EX746
	nop	
$I755:
	cmp	WORD PTR [bp+4],9	;param_1
	jl	$I757
	cmp	WORD PTR [bp+4],15	;param_1
	jg	$I757
	cmp	BYTE PTR D_5893_MAP_ID,127
	jbe	$I757
	cmp	BYTE PTR D_58A3,0
	jne	$I757
; Line 768
	mov	ax,OFFSET DGROUP:$SG758
$L20086:
	push	ax
	call	F_ZSTATS_0BEE
	jmp	SHORT $I756
	nop	
$I757:
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	F_ZSTATS_0518
	or	ax,ax
	je	$I759
; Line 774
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp+4]	;param_1
	call	FUN_1000_6E60
; Line 775
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	D_57C0[bx],99
	jae	$I760
; Line 776
	inc	D_57C0[bx]
; Line 777
; Line 779
$I760:
	cmp	BYTE PTR D_5893_MAP_ID,127
	jbe	$I756
	cmp	bx,42
	jne	$I756
	mov	ax,OFFSET DGROUP:$SG763
	push	ax
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	al,BYTE PTR D_55A8_PARTY[bx+10]
	sub	ah,ah
	push	ax
	call	FUN_1000_4D76
	mov	WORD PTR [bp-4],ax	;local_8
; Line 787
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	si,ax
	mov	al,D_1ADE[si]
	mov	BYTE PTR [bx+1],al
	mov	BYTE PTR [bx],al
	jmp	$I756
	nop	
$I759:
; Line 791
	cmp	WORD PTR [bp+4],26	;param_1
	je	$I767
	cmp	WORD PTR [bp+4],36	;param_1
	jne	$I766
$I767:
	cmp	BYTE PTR D_57DB,0
	je	$I765
$I766:
	cmp	WORD PTR [bp+4],28	;param_1
	jne	$I764
	cmp	BYTE PTR D_57DD,0
	jne	$I764
$I765:
; Line 793
	mov	ax,OFFSET DGROUP:$SG768
	jmp	$L20086
$I764:
	sub	dx,dx
; Line 800
	mov	si,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	si,cl
	add	si,OFFSET D_55A8_PARTY+25
; Line 805
	mov	WORD PTR [bp-6],6	;local_a
	mov	WORD PTR [bp-16],6
	mov	cx,WORD PTR [bp-16]
$L20033:
; Line 806
	cmp	BYTE PTR [si],255
	je	$I772
; Line 807
	mov	bl,BYTE PTR [si]
	sub	bh,bh
	mov	al,D_1AAE[bx]
	sub	ah,ah
	add	dx,ax
; Line 808
; Line 810
$I772:
	inc	si
; Line 811
	loop	$L20033
	mov	WORD PTR [bp-8],si	;local_10
	mov	WORD PTR [bp-12],dx	;local_4
; Line 814
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
; Line 817
	mov	bx,WORD PTR [bp+4]	;param_1
	mov	al,D_1A7E[bx]
	sub	ah,ah
	cmp	ax,2
	je	$SC777
	cmp	ax,4
	je	$SC780
	cmp	ax,32
	je	$SC783
	cmp	ax,48
	jne	$JCC3706
	jmp	$SC787
$JCC3706:
	cmp	ax,64
	jne	$JCC3714
	jmp	$SC790
$JCC3714:
	cmp	ax,128
	jne	$JCC3722
	jmp	$SC793
$JCC3722:
	jmp	SHORT $SB774
	nop	
$SC777:
; Line 821
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	al,BYTE PTR D_55A8_PARTY[bx+29]
	sub	ah,ah
	cmp	ax,-1
	je	$I778
; Line 822
	mov	ax,OFFSET DGROUP:$SG779
	jmp	$L20086
$I778:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+29
$L20081:
	mov	WORD PTR [bp-8],ax	;local_10
; Line 827
$SB774:
; Line 882
	cmp	WORD PTR [bp-14],0	;local_e
	je	$JCC3771
	jmp	$I796
$JCC3771:
; Line 884
	mov	ax,OFFSET DGROUP:$SG797
	jmp	$L20086
$SC780:
; Line 830
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	al,BYTE PTR D_55A8_PARTY[bx+30]
	sub	ah,ah
	cmp	ax,-1
	je	$I781
; Line 831
	mov	ax,OFFSET DGROUP:$SG782
	jmp	$L20086
$I781:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+30
	jmp	SHORT $L20081
$SC783:
; Line 839
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_0C0A
	mov	WORD PTR [bp-10],ax	;local_c
; Line 840
	cmp	ax,255
	jne	$I784
; Line 841
	mov	ax,OFFSET DGROUP:$SG785
	jmp	$L20086
$I784:
	cmp	WORD PTR [bp-10],2	;local_c
	jne	$I786
; Line 846
	mov	WORD PTR [bp-10],0	;local_c
; Line 847
; Line 849
$I786:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,WORD PTR [bp-10]	;local_c
$L20094:
	add	ax,OFFSET D_55A8_PARTY+27
	jmp	SHORT $L20081
$SC787:
; Line 853
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_0C0A
	mov	WORD PTR [bp-10],ax	;local_c
; Line 854
	cmp	ax,2
	je	$I788
; Line 855
	mov	ax,OFFSET DGROUP:$SG789
	jmp	$L20086
$I788:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	jmp	SHORT $L20094
	nop	
$SC790:
; Line 863
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	cmp	BYTE PTR D_55A8_PARTY[bx+26],255
	je	$I791
; Line 864
	mov	ax,OFFSET DGROUP:$SG792
	jmp	$L20086
$I791:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+26
	jmp	$L20081
	nop	
$SC793:
; Line 872
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	cmp	BYTE PTR D_55A8_PARTY[bx+25],255
	je	$I794
; Line 873
	mov	ax,OFFSET DGROUP:$SG795
	jmp	$L20086
$I794:
	mov	ax,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY+25
	jmp	$L20081
	nop	
$I796:
; Line 886
; Line 888
	mov	bx,WORD PTR [bp-8]	;local_10
	mov	al,BYTE PTR [bp+4]	;param_1
	mov	BYTE PTR [bx],al
; Line 889
	mov	bx,WORD PTR [bp+4]	;param_1
	dec	D_57C0[bx]
; Line 890
	cmp	D_57C0[bx],42
	je	$I800
	cmp	D_57C0[bx],44
	jne	$I799
$I800:
	sub	ax,ax
	push	ax
	mov	ax,15
	push	ax
	call	FUN_1000_2092
	or	ax,ax
	jne	$I799
; Line 892
	mov	ax,OFFSET DGROUP:$SG801
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 893
	mov	bx,WORD PTR [bp+6]	;param_2
	mov	cl,5
	shl	bx,cl
	mov	BYTE PTR D_55A8_PARTY[bx+29],255
; Line 894
	mov	ax,1200
	push	ax
	mov	ax,2000
	push	ax
	mov	ax,1
	push	ax
	mov	ax,40
	push	ax
	call	FUN_1000_43AE
; Line 895
	mov	ax,1
	jmp	SHORT $EX746
$I799:
; Line 896
; Line 898
	cmp	WORD PTR [bp+4],42	;param_1
	je	$JCC4052
	jmp	$I756
$JCC4052:
	cmp	BYTE PTR D_5893_MAP_ID,127
	ja	$JCC4062
	jmp	$I756
$JCC4062:
	mov	bx,WORD PTR [bp-2]	;local_6
	mov	BYTE PTR [bx+1],29
; Line 911
	mov	BYTE PTR [bx],29
	jmp	$I756
$EX746:
	pop	si
	mov	sp,bp
	pop	bp
	ret	4
	nop	

F_ZSTATS_0C5C	ENDP
; Line 920
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
; Line 941
	mov	WORD PTR [bp-8],0	;local_8
; Line 942
	mov	WORD PTR [bp-14],1	;local_10
; Line 943
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I824
; Line 944
	mov	WORD PTR [bp-28],22464	;local_14
; Line 945
	mov	WORD PTR [bp-12],48	;local_a
; Line 946
	jmp	SHORT $I825
$I824:
; Line 947
	mov	WORD PTR [bp-28],-17938	;local_14
; Line 948
	mov	WORD PTR [bp-12],38	;local_a
; Line 949
$I825:
; Line 952
	cmp	WORD PTR [bp-8],0	;local_8
	je	$I826
; Line 953
	mov	ax,WORD PTR [bp-16]	;local_1a
	jmp	$EX809
$I826:
; Line 957
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 958
	mov	ax,1
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 959
	mov	WORD PTR [bp-22],0	;local_4
; Line 960
	mov	ax,WORD PTR [bp+8]	;param_3
$L20097:
	mov	WORD PTR [bp-20],ax	;local_12
; Line 963
; Line 964
	cmp	ax,-1
	jne	$I833
; Line 966
	mov	WORD PTR [bp-10],0	;local_18
; Line 967
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	add	ax,1
	je	$I834
; Line 968
	mov	WORD PTR [bp-10],2	;local_18
; Line 969
; Line 971
$I834:
	cmp	WORD PTR [bp-20],-1	;local_12
	je	$I836
; Line 972
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	add	ax,1
$L20101:
	je	$I836
; Line 973
	inc	WORD PTR [bp-10]	;local_18
; Line 974
; Line 975
$I836:
; Line 1040
	cmp	WORD PTR [bp-10],0	;local_18
	jne	$JCC4240
	jmp	$I849
$JCC4240:
; Line 1041
	cmp	WORD PTR [bp-10],1	;local_18
	je	$JCC4249
	jmp	$I850
$JCC4249:
; Line 1043
	mov	ax,25
	jmp	$L20099
$I833:
; Line 978
; Line 980
	inc	WORD PTR [bp-22]	;local_4
; Line 981
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I838
; Line 982
	mov	ax,253
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 983
	mov	ax,WORD PTR [bp-20]	;local_12
	mov	WORD PTR [bp-16],ax	;local_1a
; Line 984
; Line 987
$I838:
	cmp	WORD PTR [bp+4],82	;param_1
	je	$I839
; Line 989
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6422
	push	ax
	mov	ax,32
	push	ax
	jmp	SHORT $L20096
$I839:
; Line 990
; Line 992
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-20]	;local_12
	call	F_ZSTATS_0518
	or	ax,ax
	je	$I841
; Line 994
	mov	bx,WORD PTR [bp-20]	;local_12
	mov	al,D_1AE8[bx]
	sub	ah,ah
	mov	WORD PTR [bp-18],ax	;local_c
; Line 995
	jmp	SHORT $I842
	nop	
$I841:
; Line 997
	mov	WORD PTR [bp-18],32	;local_c
; Line 998
$I842:
; Line 1000
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-28]	;local_14
	mov	ax,6498
	push	ax
	push	WORD PTR [bp-18]	;local_c
$L20096:
	call	F_ZSTATS_05E2
; Line 1001
; Line 1009
	mov	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 1011
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	dec	ax
	cmp	ax,WORD PTR [bp-14]	;local_10
	jne	$I843
; Line 1012
	mov	ax,253
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 1013
; Line 1016
$I843:
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	cmp	ax,8
	jne	$I844
; Line 1018
	mov	WORD PTR [bp-10],0	;local_18
; Line 1019
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	inc	ax
	je	$I845
; Line 1020
	mov	WORD PTR [bp-10],2	;local_18
; Line 1021
; Line 1023
$I845:
	cmp	WORD PTR [bp-20],-1	;local_12
	jne	$JCC4422
	jmp	$I836
$JCC4422:
; Line 1024
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	inc	ax
	jmp	$L20101
$I844:
; Line 1030
; Line 1032
	push	WORD PTR [bp-20]	;local_12
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	jmp	$L20097
$I850:
; Line 1044
	cmp	WORD PTR [bp-10],2	;local_18
	jne	$I852
; Line 1046
	mov	ax,24
$L20099:
	push	ax
	call	FUN_1000_4DEA
; Line 1047
	jmp	SHORT $I855
	nop	
$I852:
	cmp	WORD PTR [bp-10],3	;local_18
	jne	$I855
; Line 1049
	mov	ax,18
	jmp	SHORT $L20099
	nop	
$I849:
; Line 1051
; Line 1053
	call	FUN_1000_4DAA
; Line 1054
$I855:
; Line 1058
	mov	ax,2
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 1059
	call	FUN_1000_266C_GET_CH
	mov	WORD PTR [bp-6],ax	;local_16
; Line 1061
	cmp	ax,13
	jne	$JCC4511
	jmp	$SC890
$JCC4511:
	jle	$JCC4516
	jmp	$L20044
$JCC4516:
	cmp	ax,1
	je	$SC860
	cmp	ax,2
	je	$SC875
	cmp	ax,3
	je	$SC860
	cmp	ax,4
	jmp	$L20098
	nop	
	nop	
$SC860:
; Line 1068
	cmp	WORD PTR [bp-6],213	;local_16
	jne	$I861
; Line 1069
	mov	WORD PTR [bp-2],7	;local_6
; Line 1070
	jmp	SHORT $I862
$I861:
; Line 1071
	mov	WORD PTR [bp-2],1	;local_6
$I862:
; Line 1072
	mov	WORD PTR [bp-26],0	;local_e
; Line 1073
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4572
	jmp	$I825
$JCC4572:
; Line 1074
;	register si = si
;	register di = di
; Line 1078
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-24],ax	;local_1c
; Line 1079
	add	WORD PTR [bp-26],ax	;local_e
; Line 1080
	mov	di,WORD PTR [bp+8]	;param_3
; Line 1081
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1084
$D866:
; Line 1085
; Line 1086
	cmp	si,4
	je	$I870
	cmp	si,1
	jne	$I869
$I870:
; Line 1087
; Line 1089
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	inc	ax
	je	$I871
; Line 1090
; Line 1091
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	mov	di,ax
; Line 1092
; Line 1093
	jmp	SHORT $I874
	nop	
$I871:
; Line 1094
; Line 1096
	cmp	si,4
	jne	$I874
$I869:
; Line 1104
; Line 1106
	dec	si
; Line 1107
$I874:
; Line 1109
	dec	WORD PTR [bp-24]	;local_1c
	jne	$D866
; Line 1111
	mov	WORD PTR [bp+8],di	;param_3
; Line 1114
$L20106:
	mov	WORD PTR [bp-14],si	;local_10
; Line 1115
; Line 1116
	jmp	$I825
$SC875:
; Line 1123
	cmp	WORD PTR [bp-6],214	;local_16
	jne	$I876
; Line 1124
	mov	WORD PTR [bp-2],7	;local_6
; Line 1125
	jmp	SHORT $I877
$I876:
; Line 1126
	mov	WORD PTR [bp-2],1	;local_6
$I877:
; Line 1127
	mov	WORD PTR [bp-26],0	;local_e
; Line 1128
	cmp	WORD PTR [bp-2],0	;local_6
	jg	$JCC4684
	jmp	$I825
$JCC4684:
; Line 1129
;	register si = si
;	register di = di
; Line 1133
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	WORD PTR [bp-4],ax	;local_1e
; Line 1134
	add	WORD PTR [bp-26],ax	;local_e
; Line 1135
	mov	di,WORD PTR [bp-20]	;local_12
; Line 1136
	mov	si,WORD PTR [bp-14]	;local_10
; Line 1139
$D881:
; Line 1140
; Line 1141
	cmp	si,4
	je	$I885
	cmp	si,7
	je	$I885
	cmp	WORD PTR [bp-22],si	;local_4
	jge	$I884
$I885:
; Line 1142
; Line 1144
	mov	ax,di
	cmp	ax,-1
	je	$I886
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	inc	ax
	je	$I886
; Line 1145
; Line 1146
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1147
	push	di
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	di,ax
; Line 1148
; Line 1149
	jmp	SHORT $I889
	nop	
$I886:
; Line 1150
; Line 1152
	cmp	si,4
	jne	$I889
	cmp	WORD PTR [bp-22],4	;local_4
	jne	$I889
$I884:
; Line 1159
; Line 1161
	inc	si
; Line 1162
$I889:
; Line 1164
	dec	WORD PTR [bp-4]	;local_1e
	jne	$D881
; Line 1166
	mov	WORD PTR [bp-20],di	;local_12
	jmp	$L20106
	nop	
$SC890:
; Line 1177
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$I891
; Line 1178
	push	WORD PTR [bp+6]	;param_2
	push	WORD PTR [bp-16]	;local_1a
	call	F_ZSTATS_0C5C
	mov	WORD PTR [bp-8],ax	;local_8
; Line 1179
	jmp	$I825
	nop	
$I891:
; Line 1181
	mov	WORD PTR [bp-8],1	;local_8
; Line 1182
; Line 1184
	jmp	$I825
$SC893:
; Line 1188
	cmp	WORD PTR [bp+4],82	;param_1
	jne	$L20039
	mov	ax,OFFSET DGROUP:$SG894
	jmp	SHORT $L20040
	nop	
$L20039:
	mov	ax,OFFSET DGROUP:$SG895
$L20040:
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 1189
	mov	WORD PTR [bp-8],1	;local_8
; Line 1190
	mov	WORD PTR [bp-16],-1	;local_1a
; Line 1193
	jmp	$I825
$SC896:
; Line 1198
	mov	ax,-1
	push	ax
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1199
	mov	WORD PTR [bp-14],1	;local_10
; Line 1201
	jmp	$I825
	nop	
$SC897:
; Line 1203
; Line 1207
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	mov	WORD PTR [bp+8],ax	;param_3
; Line 1209
	mov	di,1
; Line 1210
$D898:
; Line 1213
	push	WORD PTR [bp+8]	;param_3
	push	WORD PTR [bp-12]	;local_a
	push	WORD PTR [bp-28]	;local_14
	push	WORD PTR [bp+6]	;param_2
	call	F_ZSTATS_056C
	mov	si,ax
; Line 1214
	cmp	si,-1
	jne	$I901
; Line 1215
; Line 1217
$L20105:
	mov	WORD PTR [bp-14],di	;local_10
	mov	WORD PTR [bp-16],si	;local_1a
	jmp	$I825
$I901:
	mov	WORD PTR [bp+8],si	;param_3
; Line 1222
	inc	di
; Line 1223
	cmp	di,7
	jl	$D898
	jmp	SHORT $L20105
	nop	
$L20044:
	cmp	ax,27
	jne	$JCC4959
	jmp	$SC893
$JCC4959:
	cmp	ax,32
	jne	$JCC4967
	jmp	$SC890
$JCC4967:
	cmp	ax,211
	je	$SC896
	cmp	ax,212
	je	$SC897
	cmp	ax,213
	jne	$JCC4985
	jmp	$SC860
$JCC4985:
	cmp	ax,214
$L20098:
	jne	$JCC4993
	jmp	$SC875
$JCC4993:
	jmp	$I825
	nop	
$EX809:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	6

F_ZSTATS_0F2E	ENDP
; Line 1236
	PUBLIC	F_ZSTATS_1296
F_ZSTATS_1296	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	local_6 = -2
;	local_4 = -4
; Line 1241
	sub	ax,ax
	push	ax
	call	F_ZSTATS_0000
	mov	WORD PTR [bp-2],ax	;local_6
; Line 1243
	or	ax,ax
	jl	$END907
; Line 1244
	mov	ax,-1
	push	ax
	mov	ax,48
	push	ax
	mov	ax,OFFSET D_57C0
	push	ax
	push	WORD PTR [bp-2]	;local_6
	call	F_ZSTATS_05A4
	mov	WORD PTR [bp-4],ax	;local_4
; Line 1248
	cmp	ax,-1
	jne	$I908
; Line 1249
; Line 1250
	mov	ax,-26242
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 1251
	jmp	SHORT $END907
$I908:
	mov	ax,-26216
	push	ax
	call	FUN_1000_1850_PRINT_STRING
; Line 1255
	call	FUN_1000_4EFC
; Line 1256
	mov	ax,1
	push	ax
	call	FUN_1000_1B94_GET_TEXT_EFFECTS
; Line 1258
	mov	ax,WORD PTR [bp-2]	;local_6
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET D_55A8_PARTY
	push	ax
	call	FUN_1000_4E50
; Line 1260
	mov	ax,8
	push	ax
	call	F_ZSTATS_045E
; Line 1262
	push	WORD PTR [bp-4]	;local_4
	push	WORD PTR [bp-2]	;local_6
	mov	ax,82
	push	ax
	call	F_ZSTATS_0F2E
; Line 1264
	call	FUN_1000_4DAA
; Line 1265
	call	FUN_1000_4E20
; Line 1266
	call	FUN_1000_4F3C
; Line 1267
	call	FUN_1000_2900
; Line 1269
$END907:
; Line 1270
	mov	sp,bp
	pop	bp
	ret	
	nop	

F_ZSTATS_1296	ENDP
_TEXT	ENDS
END
