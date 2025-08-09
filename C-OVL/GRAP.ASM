;	Static Name Aliases
;
	TITLE   grap.c
	NAME    grap

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
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_1000_1CEE_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_1F12_GET_CURRENT_TEXT_:NEAR
EXTRN	FUN_1000_1F77_CONVERT_CHAR_DIME:NEAR
EXTRN	FUN_1000_17F4_CHARACTER_EFFECTS:NEAR
EXTRN	_printf:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	D_52C8:WORD
_BSS      SEGMENT
COMM NEAR	D_535E:	BYTE:	 32
EXTRN	D_5386:WORD
EXTRN	D_538E:WORD
EXTRN	D_5398:WORD
EXTRN	D_539A:WORD
EXTRN	D_53A4:WORD
EXTRN	D_53A6:WORD
EXTRN	D_53A8:WORD
EXTRN	D_53EA:BYTE
_BSS      ENDS
_DATA      SEGMENT
$SG567	DB	'GRAP_PrintString(%s)',  0aH,  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 9
	PUBLIC	DRV_FARCALL
DRV_FARCALL	PROC FAR
	push	bp
;	offset = 6
; Line 11
	pop	bp
	ret	2
	nop	

DRV_FARCALL	ENDP
; Line 14
	PUBLIC	CONCAT22
CONCAT22	PROC NEAR
	ret	
	nop	

CONCAT22	ENDP
; Line 17
	PUBLIC	TEST
TEST	PROC NEAR
	push	bp
	mov	bp,sp
;	param = 8
;	a = 4
; Line 18
	mov	bx,WORD PTR [bp+8]	;param
	mov	ax,WORD PTR [bp+4]	;a
	mov	WORD PTR [bx],ax
; Line 19
	pop	bp
	ret	6
	nop	

TEST	ENDP
; Line 22
	PUBLIC	GRAP_PRINTCHAR
GRAP_PRINTCHAR	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,18
	push	di
	push	si
;	param_1 = 4
;	puVar1 = -18
;	puVar2 = -2
;	puVar3 = -4
;	iVar4 = -14
;	puVar5 = -6
;	text_window = -16
;	uVar6 = -8
;	puVar7 = -10
;	unaff_DS = -12
; Line 33
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	WORD PTR [bp-8],ax	;uVar6
; Line 34
	mov	ax,D_539A
	mov	WORD PTR [bp-16],ax	;text_window
; Line 35
	cmp	WORD PTR [bp+4],127	;param_1
	jg	$JCC48
	jmp	$I531
$JCC48:
; Line 36
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I532
; Line 37
	mov	bx,ax
	mov	BYTE PTR [bx+4],0
; Line 38
	mov	BYTE PTR [bx+5],0
; Line 39
	mov	ax,45
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 40
	push	WORD PTR [bp-16]	;text_window
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 42
	mov	ax,63
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 43
	mov	ax,45
	jmp	$L20013
$I532:
	cmp	WORD PTR [bp+4],254	;param_1
	jne	$I534
; Line 47
	xor	BYTE PTR D_53A4,1
; Line 48
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],1
; Line 49
	jmp	$I549
$I534:
	cmp	WORD PTR [bp+4],253	;param_1
	jne	$I535
; Line 52
	xor	BYTE PTR D_53A8,1
; Line 53
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],4
; Line 54
	jmp	$I549
$I535:
	cmp	WORD PTR [bp+4],252	;param_1
	jne	$I536
; Line 57
	mov	WORD PTR D_53A6,1
; Line 58
	mov	bx,WORD PTR [bp-16]	;text_window
	or	BYTE PTR [bx+7],2
; Line 59
	jmp	$I549
	nop	
$I536:
	cmp	WORD PTR [bp+4],251	;param_1
	jne	$I537
; Line 62
	mov	WORD PTR D_53A6,0
; Line 63
	mov	bx,WORD PTR [bp-16]	;text_window
	and	BYTE PTR [bx+7],253
; Line 64
	jmp	$I549
	nop	
$I537:
	and	WORD PTR [bp+4],127	;param_1
; Line 67
; Line 68
$I531:
	cmp	WORD PTR [bp+4],10	;param_1
	jne	$JCC198
	jmp	$I538
$JCC198:
; Line 69
	cmp	WORD PTR [bp+4],13	;param_1
	jne	$JCC207
	jmp	$LAB_1000_1745540
$JCC207:
	mov	ax,WORD PTR [bp-8]	;uVar6
	mov	cl,3
	shl	ax,cl
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 71
	cmp	WORD PTR D_52C8,3
	jne	$I541
; Line 72
	mov	ax,24
	mul	WORD PTR [bp-8]	;uVar6
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 73
; Line 74
$I541:
	mov	ax,D_5398
	mov	WORD PTR [bp-4],ax	;puVar3
; Line 75
	push	WORD PTR [bp-10]	;puVar7
	push	ax
	call	CONCAT22
	push	ax
	call	FUN_1000_17F4_CHARACTER_EFFECTS
; Line 76
	mov	ax,93
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 77
	mov	WORD PTR [bp-6],OFFSET D_53EA	;puVar5
; Line 78
	mov	WORD PTR [bp-14],4	;iVar4
; Line 79
	cmp	WORD PTR D_52C8,3
	jne	$I543
; Line 80
	mov	WORD PTR [bp-14],12	;iVar4
; Line 81
; Line 82
$I543:
	cmp	WORD PTR [bp-14],0	;iVar4
	je	$FB546
	mov	di,WORD PTR [bp-6]	;puVar5
	mov	si,WORD PTR [bp-10]	;puVar7
	mov	cx,WORD PTR [bp-14]	;iVar4
$L20000:
; Line 83
	mov	WORD PTR [bp-2],si	;puVar2
	add	si,2
; Line 84
	mov	WORD PTR [bp-18],di	;puVar1
	add	di,2
; Line 85
	mov	bx,WORD PTR [bp-18]	;puVar1
	mov	ax,WORD PTR [bx]
	mov	bx,WORD PTR [bp-2]	;puVar2
	mov	WORD PTR [bx],ax
; Line 86
	loop	$L20000
	mov	WORD PTR [bp-6],di	;puVar5
	mov	WORD PTR [bp-10],si	;puVar7
	mov	WORD PTR [bp-14],cx	;iVar4
$FB546:
; Line 87
	mov	ax,D_539A
	mov	WORD PTR [bp-16],ax	;text_window
; Line 88
	cmp	WORD PTR D_538E,0
	je	$I549
; Line 89
	mov	bx,ax
	inc	BYTE PTR [bx+4]
; Line 92
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+2]
	cmp	ax,cx
	jbe	$I549
; Line 93
; Line 96
$I538:
	mov	bx,WORD PTR [bp-16]	;text_window
	inc	BYTE PTR [bx+5]
; Line 97
$LAB_1000_1745540:
; Line 98
	mov	bx,WORD PTR [bp-16]	;text_window
	mov	BYTE PTR [bx+4],0
; Line 99
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+3]
	cmp	ax,cx
	jbe	$I549
; Line 100
	push	bx
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 101
	mov	bx,WORD PTR [bp-16]	;text_window
	dec	BYTE PTR [bx+5]
; Line 102
	mov	ax,39
$L20013:
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 103
; Line 104
$I549:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

GRAP_PRINTCHAR	ENDP
; Line 109
	PUBLIC	GRAP_PRINTSTRING
GRAP_PRINTSTRING	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,66
	push	di
	push	si
;	param_1 = 4
;	local_44 = -48
;	local_42 = -42
;	local_1a = -56
;	local_18 = -50
;	local_16 = -44
;	local_14 = -66
;	local_12 = -60
;	local_10 = -54
;	local_e = -64
;	local_c = -58
;	local_a = -52
;	local_8 = -46
;	local_6 = -2
;	local_4 = -62
; Line 125
	push	WORD PTR [bp+4]	;param_1
	mov	ax,OFFSET DGROUP:$SG567
	push	ax
	call	_printf
	add	sp,4
; Line 127
	mov	WORD PTR [bp-46],0	;local_8
; Line 128
	mov	WORD PTR [bp-52],0	;local_a
; Line 129
	mov	WORD PTR [bp-62],0	;local_4
; Line 130
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx],0
	jne	$JCC470
	jmp	$EX552
$JCC470:
; Line 131
; Line 133
	mov	ax,D_5386
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E
	mov	WORD PTR [bp-60],ax	;local_12
; Line 134
	mov	bx,ax
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	and	ax,2
	mov	WORD PTR [bp-56],ax	;local_1a
; Line 135
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	sub	ax,cx
	mov	WORD PTR [bp-48],ax	;local_44
; Line 138
$D569:
; Line 139
; Line 140
	cmp	WORD PTR [bp-62],0	;local_4
	je	$I572
; Line 141
; Line 142
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 143
; Line 146
$I572:
	sub	ax,ax
	mov	WORD PTR [bp-66],ax	;local_14
	mov	WORD PTR [bp-2],ax	;local_6
	mov	WORD PTR [bp-62],ax	;local_4
; Line 147
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	mov	cx,WORD PTR [bp-48]	;local_44
	sub	cx,ax
	mov	WORD PTR [bp-54],cx	;local_10
; Line 150
	sub	si,si
	mov	di,cx
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,WORD PTR [bp-46]	;local_8
	jmp	SHORT $L20004
$L20002:
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],13
	je	$L20003
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],0
	je	$L20003
	cmp	si,di
	jg	$L20003
; Line 151
; Line 152
	mov	bx,cx
	add	bx,dx
	mov	al,BYTE PTR [bx]
	mov	[bp-42][si],al
; Line 153
	inc	cx
	inc	si
$L20004:
	mov	bx,cx
	add	bx,dx
	cmp	BYTE PTR [bx],10
	jne	$L20002
$L20003:
	mov	WORD PTR [bp-58],si	;local_c
	mov	WORD PTR [bp-46],cx	;local_8
; Line 156
	or	si,si
	jne	$I576
; Line 157
; Line 158
	mov	bx,cx
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I577
; Line 159
; Line 160
	inc	WORD PTR [bp-46]	;local_8
	mov	al,[bx][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 161
; Line 162
	jmp	$FB602
$I577:
; Line 163
; Line 164
	inc	WORD PTR [bp-52]	;local_a
; Line 165
; Line 166
; Line 167
	jmp	$FB602
$I576:
; Line 168
; Line 170
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jg	$JCC650
	jmp	$I580
$JCC650:
; Line 171
; Line 173
	mov	ax,WORD PTR [bp-58]	;local_c
	mov	WORD PTR [bp-50],ax	;local_18
; Line 174
	mov	ax,WORD PTR [bp-46]	;local_8
	mov	WORD PTR [bp-44],ax	;local_16
; Line 179
	mov	si,WORD PTR [bp-58]	;local_c
	mov	dx,WORD PTR [bp+4]	;param_1
	mov	cx,ax
	jmp	SHORT $L20007
	nop	
$L20005:
	or	si,si
	je	$L20006
	mov	bx,cx
	mov	di,dx
	cmp	BYTE PTR [bx][di],10
	je	$L20006
	cmp	BYTE PTR [bx][di],0
	je	$L20006
	cmp	BYTE PTR [bx][di],13
	je	$L20006
; Line 180
; Line 181
	dec	si
	dec	cx
$L20007:
	mov	bx,cx
	mov	di,dx
	cmp	BYTE PTR [bx][di],32
	jne	$L20005
$L20006:
	mov	WORD PTR [bp-58],si	;local_c
	mov	WORD PTR [bp-46],cx	;local_8
; Line 184
	or	si,si
	jne	$I584
; Line 185
	mov	ax,WORD PTR [bp-50]	;local_18
	mov	WORD PTR [bp-58],ax	;local_c
; Line 186
	mov	ax,WORD PTR [bp-44]	;local_16
	mov	WORD PTR [bp-46],ax	;local_8
; Line 188
	mov	bx,WORD PTR [bp-60]	;local_12
	cmp	BYTE PTR [bx+4],0
	je	$I591
; Line 189
; Line 190
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 191
	mov	WORD PTR [bp-2],1	;local_6
; Line 192
; Line 193
; Line 194
	jmp	SHORT $I591
	nop	
$I584:
; Line 195
; Line 197
	mov	cx,WORD PTR [bp-58]	;local_c
$D587:
; Line 198
; Line 199
	dec	cx
; Line 200
; Line 202
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$D587
	cmp	BYTE PTR [bp-42][si],13
	je	$D587
	cmp	BYTE PTR [bp-42][si],10
	je	$D587
	mov	WORD PTR [bp-58],cx	;local_c
; Line 204
	mov	bx,WORD PTR [bp-46]	;local_8
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I590
; Line 205
	inc	WORD PTR [bp-46]	;local_8
; Line 208
$I590:
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jge	$I591
; Line 209
	inc	WORD PTR [bp-62]	;local_4
; Line 210
$I591:
; Line 213
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I593
$I580:
; Line 217
; Line 218
	dec	WORD PTR [bp-58]	;local_c
; Line 219
$I593:
; Line 222
	cmp	WORD PTR [bp-56],0	;local_1a
	je	$I594
; Line 223
; Line 224
	mov	ax,WORD PTR [bp-48]	;local_44
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I595
; Line 225
; Line 226
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 227
; Line 231
$I595:
	mov	ax,WORD PTR [bp-54]	;local_10
	sub	ax,WORD PTR [bp-58]	;local_c
	cwd	
	sub	ax,dx
	sar	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 232
; Line 235
$I594:
	cmp	WORD PTR [bp-2],0	;local_6
	je	$F600
; Line 236
; Line 238
	mov	cx,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20012
$L20010:
; Line 239
; Line 240
	inc	cx
$L20012:
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$L20010
	mov	WORD PTR [bp-66],cx	;local_14
; Line 241
; Line 244
	jmp	SHORT $F600
$FC601:
	inc	WORD PTR [bp-66]	;local_14
$F600:
	mov	ax,WORD PTR [bp-58]	;local_c
	cmp	WORD PTR [bp-66],ax	;local_14
	jg	$FB602
; Line 245
; Line 247
	mov	si,WORD PTR [bp-66]	;local_14
	mov	al,[bp-42][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 248
	jmp	SHORT $FC601
	nop	
$FB602:
; Line 249
; Line 250
	cmp	WORD PTR [bp-52],0	;local_a
	jne	$JCC916
	jmp	$D569
$JCC916:
; Line 251
; Line 252
$EX552:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

GRAP_PRINTSTRING	ENDP
_TEXT	ENDS
END
