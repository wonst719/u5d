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
EXTRN	D_52C8_VIDEODRIVERSELECTION:WORD
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
$SG564	DB	'GRAP_PrintString(%s)',  0aH,  00H
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
	PUBLIC	FUN_1000_0892_INITIALIZE_VIDEO_
FUN_1000_0892_INITIALIZE_VIDEO_	PROC NEAR
	push	bp
;	a = 4
; Line 23
	pop	bp
	ret	2
	nop	

FUN_1000_0892_INITIALIZE_VIDEO_	ENDP
; Line 26
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
; Line 37
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	WORD PTR [bp-8],ax	;uVar6
; Line 38
	mov	ax,D_539A
	mov	WORD PTR [bp-16],ax	;text_window
; Line 39
	cmp	WORD PTR [bp+4],127	;param_1
	jg	$JCC38
	jmp	$I528
$JCC38:
; Line 40
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I529
; Line 41
	mov	bx,ax
	mov	BYTE PTR [bx+4],0
; Line 42
	mov	BYTE PTR [bx+5],0
; Line 43
	mov	ax,45
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 44
	push	WORD PTR [bp-16]	;text_window
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 46
	mov	ax,63
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 47
	mov	ax,45
	jmp	$L20013
$I529:
	cmp	WORD PTR [bp+4],254	;param_1
	jne	$I531
; Line 51
	xor	BYTE PTR D_53A4,1
; Line 52
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],1
; Line 53
	jmp	$I546
$I531:
	cmp	WORD PTR [bp+4],253	;param_1
	jne	$I532
; Line 56
	xor	BYTE PTR D_53A8,1
; Line 57
	mov	bx,WORD PTR [bp-16]	;text_window
	xor	BYTE PTR [bx+7],4
; Line 58
	jmp	$I546
$I532:
	cmp	WORD PTR [bp+4],252	;param_1
	jne	$I533
; Line 61
	mov	WORD PTR D_53A6,1
; Line 62
	mov	bx,WORD PTR [bp-16]	;text_window
	or	BYTE PTR [bx+7],2
; Line 63
	jmp	$I546
	nop	
$I533:
	cmp	WORD PTR [bp+4],251	;param_1
	jne	$I534
; Line 66
	mov	WORD PTR D_53A6,0
; Line 67
	mov	bx,WORD PTR [bp-16]	;text_window
	and	BYTE PTR [bx+7],253
; Line 68
	jmp	$I546
	nop	
$I534:
	and	WORD PTR [bp+4],127	;param_1
; Line 71
; Line 72
$I528:
	cmp	WORD PTR [bp+4],10	;param_1
	jne	$JCC188
	jmp	$I535
$JCC188:
; Line 73
	cmp	WORD PTR [bp+4],13	;param_1
	jne	$JCC197
	jmp	$LAB_1000_1745537
$JCC197:
	mov	ax,WORD PTR [bp-8]	;uVar6
	mov	cl,3
	shl	ax,cl
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 75
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,3
	jne	$I538
; Line 76
	mov	ax,24
	mul	WORD PTR [bp-8]	;uVar6
	mov	WORD PTR [bp-10],ax	;puVar7
; Line 77
; Line 78
$I538:
	mov	ax,D_5398
	mov	WORD PTR [bp-4],ax	;puVar3
; Line 79
	push	WORD PTR [bp-10]	;puVar7
	push	ax
	call	CONCAT22
	push	ax
	call	FUN_1000_17F4_CHARACTER_EFFECTS
; Line 80
	mov	ax,93
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 81
	mov	WORD PTR [bp-6],OFFSET D_53EA	;puVar5
; Line 82
	mov	WORD PTR [bp-14],4	;iVar4
; Line 83
	cmp	WORD PTR D_52C8_VIDEODRIVERSELECTION,3
	jne	$I540
; Line 84
	mov	WORD PTR [bp-14],12	;iVar4
; Line 85
; Line 86
$I540:
	cmp	WORD PTR [bp-14],0	;iVar4
	je	$FB543
	mov	di,WORD PTR [bp-6]	;puVar5
	mov	si,WORD PTR [bp-10]	;puVar7
	mov	cx,WORD PTR [bp-14]	;iVar4
$L20000:
; Line 87
	mov	WORD PTR [bp-2],si	;puVar2
	add	si,2
; Line 88
	mov	WORD PTR [bp-18],di	;puVar1
	add	di,2
; Line 89
	mov	bx,WORD PTR [bp-18]	;puVar1
	mov	ax,WORD PTR [bx]
	mov	bx,WORD PTR [bp-2]	;puVar2
	mov	WORD PTR [bx],ax
; Line 90
	loop	$L20000
	mov	WORD PTR [bp-6],di	;puVar5
	mov	WORD PTR [bp-10],si	;puVar7
	mov	WORD PTR [bp-14],cx	;iVar4
$FB543:
; Line 91
	mov	ax,D_539A
	mov	WORD PTR [bp-16],ax	;text_window
; Line 92
	cmp	WORD PTR D_538E,0
	je	$I546
; Line 93
	mov	bx,ax
	inc	BYTE PTR [bx+4]
; Line 96
	mov	al,BYTE PTR [bx+4]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+2]
	cmp	ax,cx
	jbe	$I546
; Line 97
; Line 100
$I535:
	mov	bx,WORD PTR [bp-16]	;text_window
	inc	BYTE PTR [bx+5]
; Line 101
$LAB_1000_1745537:
; Line 102
	mov	bx,WORD PTR [bp-16]	;text_window
	mov	BYTE PTR [bx+4],0
; Line 103
	mov	al,BYTE PTR [bx+5]
	sub	ah,ah
	mov	cl,BYTE PTR [bx+1]
	sub	ch,ch
	add	ax,cx
	mov	cl,BYTE PTR [bx+3]
	cmp	ax,cx
	jbe	$I546
; Line 104
	push	bx
	call	FUN_1000_1F77_CONVERT_CHAR_DIME
; Line 105
	mov	bx,WORD PTR [bp-16]	;text_window
	dec	BYTE PTR [bx+5]
; Line 106
	mov	ax,39
$L20013:
	push	ax
	push	cs
	call	DRV_FARCALL
; Line 107
; Line 108
$I546:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

GRAP_PRINTCHAR	ENDP
; Line 113
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
; Line 129
	push	WORD PTR [bp+4]	;param_1
	mov	ax,OFFSET DGROUP:$SG564
	push	ax
	call	_printf
	add	sp,4
; Line 131
	mov	WORD PTR [bp-46],0	;local_8
; Line 132
	mov	WORD PTR [bp-52],0	;local_a
; Line 133
	mov	WORD PTR [bp-62],0	;local_4
; Line 134
	mov	bx,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx],0
	jne	$JCC460
	jmp	$EX549
$JCC460:
; Line 135
; Line 137
	mov	ax,D_5386
	mov	cl,3
	shl	ax,cl
	add	ax,OFFSET DGROUP:D_535E
	mov	WORD PTR [bp-60],ax	;local_12
; Line 138
	mov	bx,ax
	mov	al,BYTE PTR [bx+7]
	sub	ah,ah
	and	ax,2
	mov	WORD PTR [bp-56],ax	;local_1a
; Line 139
	mov	al,BYTE PTR [bx+2]
	sub	ah,ah
	mov	cl,BYTE PTR [bx]
	sub	ch,ch
	sub	ax,cx
	mov	WORD PTR [bp-48],ax	;local_44
; Line 142
$D566:
; Line 143
; Line 144
	cmp	WORD PTR [bp-62],0	;local_4
	je	$I569
; Line 145
; Line 146
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 147
; Line 150
$I569:
	sub	ax,ax
	mov	WORD PTR [bp-66],ax	;local_14
	mov	WORD PTR [bp-2],ax	;local_6
	mov	WORD PTR [bp-62],ax	;local_4
; Line 151
	call	FUN_1000_1F12_GET_CURRENT_TEXT_
	mov	cx,WORD PTR [bp-48]	;local_44
	sub	cx,ax
	mov	WORD PTR [bp-54],cx	;local_10
; Line 154
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
; Line 155
; Line 156
	mov	bx,cx
	add	bx,dx
	mov	al,BYTE PTR [bx]
	mov	[bp-42][si],al
; Line 157
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
; Line 160
	or	si,si
	jne	$I573
; Line 161
; Line 162
	mov	bx,cx
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I574
; Line 163
; Line 164
	inc	WORD PTR [bp-46]	;local_8
	mov	al,[bx][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 165
; Line 166
	jmp	$FB599
$I574:
; Line 167
; Line 168
	inc	WORD PTR [bp-52]	;local_a
; Line 169
; Line 170
; Line 171
	jmp	$FB599
$I573:
; Line 172
; Line 174
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jg	$JCC640
	jmp	$I577
$JCC640:
; Line 175
; Line 177
	mov	ax,WORD PTR [bp-58]	;local_c
	mov	WORD PTR [bp-50],ax	;local_18
; Line 178
	mov	ax,WORD PTR [bp-46]	;local_8
	mov	WORD PTR [bp-44],ax	;local_16
; Line 183
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
; Line 184
; Line 185
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
; Line 188
	or	si,si
	jne	$I581
; Line 189
	mov	ax,WORD PTR [bp-50]	;local_18
	mov	WORD PTR [bp-58],ax	;local_c
; Line 190
	mov	ax,WORD PTR [bp-44]	;local_16
	mov	WORD PTR [bp-46],ax	;local_8
; Line 192
	mov	bx,WORD PTR [bp-60]	;local_12
	cmp	BYTE PTR [bx+4],0
	je	$I588
; Line 193
; Line 194
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 195
	mov	WORD PTR [bp-2],1	;local_6
; Line 196
; Line 197
; Line 198
	jmp	SHORT $I588
	nop	
$I581:
; Line 199
; Line 201
	mov	cx,WORD PTR [bp-58]	;local_c
$D584:
; Line 202
; Line 203
	dec	cx
; Line 204
; Line 206
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$D584
	cmp	BYTE PTR [bp-42][si],13
	je	$D584
	cmp	BYTE PTR [bp-42][si],10
	je	$D584
	mov	WORD PTR [bp-58],cx	;local_c
; Line 208
	mov	bx,WORD PTR [bp-46]	;local_8
	mov	si,WORD PTR [bp+4]	;param_1
	cmp	BYTE PTR [bx][si],0
	je	$I587
; Line 209
	inc	WORD PTR [bp-46]	;local_8
; Line 212
$I587:
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jge	$I588
; Line 213
	inc	WORD PTR [bp-62]	;local_4
; Line 214
$I588:
; Line 217
	mov	ax,WORD PTR [bp-54]	;local_10
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I590
$I577:
; Line 221
; Line 222
	dec	WORD PTR [bp-58]	;local_c
; Line 223
$I590:
; Line 226
	cmp	WORD PTR [bp-56],0	;local_1a
	je	$I591
; Line 227
; Line 228
	mov	ax,WORD PTR [bp-48]	;local_44
	cmp	WORD PTR [bp-58],ax	;local_c
	jle	$I592
; Line 229
; Line 230
	mov	ax,10
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 231
; Line 238
$I592:
	mov	ax,WORD PTR [bp-54]	;local_10
	sub	ax,WORD PTR [bp-58]	;local_c
	cwd	
	sub	ax,dx
	sar	ax,1
	push	ax
	call	FUN_1000_1CEE_GET_CURRENT_TEXT_
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 240
; Line 243
$I591:
	cmp	WORD PTR [bp-2],0	;local_6
	je	$F597
; Line 244
; Line 246
	mov	cx,WORD PTR [bp-66]	;local_14
	jmp	SHORT $L20012
$L20010:
; Line 247
; Line 248
	inc	cx
$L20012:
	mov	si,cx
	cmp	BYTE PTR [bp-42][si],32
	je	$L20010
	mov	WORD PTR [bp-66],cx	;local_14
; Line 249
; Line 252
	jmp	SHORT $F597
$FC598:
	inc	WORD PTR [bp-66]	;local_14
$F597:
	mov	ax,WORD PTR [bp-58]	;local_c
	cmp	WORD PTR [bp-66],ax	;local_14
	jg	$FB599
; Line 253
; Line 255
	mov	si,WORD PTR [bp-66]	;local_14
	mov	al,[bp-42][si]
	sub	ah,ah
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 256
	jmp	SHORT $FC598
	nop	
$FB599:
; Line 257
; Line 258
	cmp	WORD PTR [bp-52],0	;local_a
	jne	$JCC906
	jmp	$D566
$JCC906:
; Line 259
; Line 260
$EX549:
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

GRAP_PRINTSTRING	ENDP
_TEXT	ENDS
END
