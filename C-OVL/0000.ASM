;	Static Name Aliases
;
	TITLE   0000.c
	NAME    0000

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
EXTRN	_printf:NEAR
EXTRN	SWAP:NEAR
EXTRN	DRV_FARCALL:FAR
EXTRN	D_52BA_VDP:BYTE
EXTRN	D_52F6:WORD
EXTRN	D_52F8:WORD
EXTRN	D_52FA:WORD
EXTRN	D_52FC:WORD
EXTRN	D_52FE:WORD
EXTRN	D_5300:WORD
_BSS      SEGMENT
COMM NEAR	D_52C4:	BYTE:	 2
COMM NEAR	D_52CC:	BYTE:	 2
COMM NEAR	D_52CE:	BYTE:	 2
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
_BSS      ENDS
_DATA      SEGMENT
$SG628	DB	'FUN_1000_0aa6_fill_rectangle(%d,%d,%d,%d)',  0aH,  00H
$SG634	DB	'FUN_1000_0b10_line(%d,%d,%d,%d)',  0aH,  00H
$SG655	DB	'FUN_1000_0f90_pen(%d,%d)',  0aH,  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 17
	PUBLIC	FUN_1000_0991
FUN_1000_0991	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	ax = 10
;	bx = 8
;	cx = 6
;	dx = 4
;	si = -2
;	di = -4
; Line 20
$FC573:
; Line 21
; Line 23
; Line 24
	mov	bx,WORD PTR [bp+10]	;ax
	mov	ax,WORD PTR [bx]
	mov	WORD PTR [bp-2],ax	;si
; Line 25
	mov	bx,WORD PTR [bp+8]	;bx
	mov	ax,WORD PTR [bx]
	mov	WORD PTR [bp-4],ax	;di
; Line 27
	mov	bx,WORD PTR [bp+10]	;ax
	mov	si,WORD PTR [bp+6]	;cx
	mov	ax,WORD PTR [si]
	add	WORD PTR [bx],ax
; Line 28
	mov	bx,WORD PTR [bp+8]	;bx
	mov	si,WORD PTR [bp+4]	;dx
	mov	ax,WORD PTR [si]
	add	WORD PTR [bx],ax
; Line 29
	mov	bx,WORD PTR [bp+10]	;ax
	cmp	WORD PTR [bx],0
	jl	$I578
; Line 30
; Line 31
	sar	WORD PTR [bx],1
; Line 32
; Line 33
	jmp	SHORT $I579
	nop	
$I578:
; Line 34
; Line 35
	mov	cx,2
	mov	ax,WORD PTR [bx]
	cwd	
	idiv	cx
	mov	WORD PTR [bx],ax
; Line 36
$I579:
; Line 38
	mov	bx,WORD PTR [bp+8]	;bx
	cmp	WORD PTR [bx],0
	jl	$I580
; Line 39
; Line 40
	sar	WORD PTR [bx],1
; Line 41
; Line 42
	jmp	SHORT $I581
$I580:
; Line 43
; Line 44
	mov	cx,2
	mov	ax,WORD PTR [bx]
	cwd	
	idiv	cx
	mov	WORD PTR [bx],ax
; Line 45
$I581:
; Line 47
	mov	ax,WORD PTR [bp-2]	;si
	mov	bx,WORD PTR [bp+10]	;ax
	sub	ax,WORD PTR [bx]
	mov	D_52F6,ax
; Line 48
	mov	ax,WORD PTR [bp-4]	;di
	mov	bx,WORD PTR [bp+8]	;bx
	sub	ax,WORD PTR [bx]
	mov	D_52F8,ax
; Line 50
	mov	bx,WORD PTR [bp+10]	;ax
	push	WORD PTR [bx]
	mov	bx,WORD PTR [bp+8]	;bx
	push	WORD PTR [bx]
	mov	bx,WORD PTR [bp+6]	;cx
	push	WORD PTR [bx]
	mov	bx,WORD PTR [bp+4]	;dx
	push	WORD PTR [bx]
	lea	ax,WORD PTR [bp-2]	;si
	push	ax
	lea	ax,WORD PTR [bp-4]	;di
	push	ax
	call	FUN_1000_0A22
; Line 51
	cmp	WORD PTR [bp-2],0	;si
	jne	$I582
; Line 60
	mov	bx,WORD PTR [bp+10]	;ax
	mov	ax,WORD PTR D_52BA_VDP+22
	cmp	WORD PTR [bx],ax
	je	$I584
	mov	ax,WORD PTR D_52BA_VDP+24
	cmp	WORD PTR [bx],ax
	jne	$I585
$I584:
; Line 61
; Line 63
	mov	bx,WORD PTR [bp+8]	;bx
	mov	ax,WORD PTR D_52BA_VDP+26
	cmp	WORD PTR [bx],ax
	je	$EX569
	mov	ax,WORD PTR D_52BA_VDP+28
	cmp	WORD PTR [bx],ax
	jne	$I585
; Line 64
	jmp	SHORT $EX569
	nop	
$I582:
	mov	bx,WORD PTR [bp+6]	;cx
	mov	si,WORD PTR [bp+10]	;ax
	mov	ax,WORD PTR [si]
	mov	WORD PTR [bx],ax
; Line 54
	mov	bx,WORD PTR [bp+4]	;dx
	mov	si,WORD PTR [bp+8]	;bx
	mov	ax,WORD PTR [si]
	mov	WORD PTR [bx],ax
; Line 55
	mov	bx,WORD PTR [bp+10]	;ax
	mov	ax,D_52F6
	add	WORD PTR [bx],ax
; Line 56
	mov	bx,si
	mov	ax,D_52F8
	add	WORD PTR [bx],ax
; Line 57
	jmp	$FC573
$I585:
; Line 68
	mov	ax,D_52F6
	mov	WORD PTR [bp-2],ax	;si
; Line 69
	mov	ax,D_52F8
	mov	WORD PTR [bp-4],ax	;di
; Line 70
	cmp	WORD PTR [bp-2],0	;si
	jge	$I587
; Line 71
	mov	ax,WORD PTR [bp-2]	;si
	neg	ax
	mov	WORD PTR [bp-2],ax	;si
; Line 74
$I587:
	cmp	WORD PTR [bp-4],0	;di
	jge	$I588
; Line 75
	mov	ax,WORD PTR [bp-4]	;di
	neg	ax
	mov	WORD PTR [bp-4],ax	;di
; Line 78
$I588:
	mov	ax,WORD PTR [bp-4]	;di
	cmp	WORD PTR [bp-2],ax	;si
	jge	$I589
; Line 79
	mov	WORD PTR [bp-2],ax	;si
; Line 82
$I589:
	cmp	WORD PTR [bp-2],1	;si
	jl	$JCC277
	jmp	$FC573
$JCC277:
; Line 83
$EX569:
	pop	si
	mov	sp,bp
	pop	bp
	ret	8
	nop	

FUN_1000_0991	ENDP
; Line 90
	PUBLIC	FUN_1000_0935
FUN_1000_0935	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	x1 = 10
;	y1 = 8
;	x2 = 6
;	y2 = 4
;	si = -2
;	di = -4
; Line 91
	mov	WORD PTR [bp-2],0	;si
; Line 92
	mov	WORD PTR [bp-4],0	;di
; Line 93
	mov	bx,WORD PTR [bp+10]	;x1
	push	WORD PTR [bx]
	mov	bx,WORD PTR [bp+8]	;y1
	push	WORD PTR [bx]
	mov	bx,WORD PTR [bp+6]	;x2
	push	WORD PTR [bx]
	mov	bx,WORD PTR [bp+4]	;y2
	push	WORD PTR [bx]
	lea	ax,WORD PTR [bp-2]	;si
	push	ax
	lea	ax,WORD PTR [bp-4]	;di
	push	ax
	call	FUN_1000_0A22
; Line 95
	cmp	WORD PTR [bp-2],0	;si
	je	$I600
	cmp	WORD PTR [bp-4],0	;di
	jne	$I599
$I600:
; Line 96
	sub	ax,ax
	jmp	$EX596
$I599:
	mov	ax,WORD PTR [bp-2]	;si
	cmp	WORD PTR [bp-4],ax	;di
	je	$I601
; Line 99
	mov	ax,-1
	jmp	$EX596
$I601:
	mov	bx,WORD PTR [bp+10]	;x1
	mov	ax,WORD PTR [bx]
	mov	D_52FA,ax
; Line 103
	mov	bx,WORD PTR [bp+8]	;y1
	mov	ax,WORD PTR [bx]
	mov	D_52FC,ax
; Line 104
	mov	bx,WORD PTR [bp+6]	;x2
	mov	ax,WORD PTR [bx]
	mov	D_52FE,ax
; Line 105
	mov	bx,WORD PTR [bp+4]	;y2
	mov	ax,WORD PTR [bx]
	mov	D_5300,ax
; Line 107
	cmp	WORD PTR [bp-2],0	;si
	je	$I602
; Line 108
; Line 109
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+6]	;x2
	call	SWAP
; Line 110
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+4]	;y2
	call	SWAP
; Line 111
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+4]	;y2
	call	FUN_1000_0991
; Line 112
	mov	bx,WORD PTR [bp+10]	;x1
	mov	ax,WORD PTR [bx]
	mov	D_52FA,ax
; Line 113
	mov	bx,WORD PTR [bp+8]	;y1
	mov	ax,WORD PTR [bx]
	mov	D_52FC,ax
; Line 114
	mov	bx,WORD PTR [bp+6]	;x2
	mov	ax,D_52FE
	mov	WORD PTR [bx],ax
; Line 115
	mov	bx,WORD PTR [bp+4]	;y2
	mov	ax,D_5300
	mov	WORD PTR [bx],ax
; Line 116
; Line 119
$I602:
	cmp	WORD PTR [bp-4],0	;di
	je	$I603
; Line 120
; Line 121
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+6]	;x2
	push	bx
	call	FUN_1000_0991
; Line 122
	mov	bx,WORD PTR [bp+10]	;x1
	mov	ax,WORD PTR [bx]
	mov	D_52FE,ax
; Line 123
	mov	bx,WORD PTR [bp+8]	;y1
	mov	ax,WORD PTR [bx]
	mov	D_5300,ax
; Line 124
; Line 126
$I603:
	mov	bx,WORD PTR [bp+10]	;x1
	mov	ax,D_52FA
	mov	WORD PTR [bx],ax
; Line 127
	mov	bx,WORD PTR [bp+8]	;y1
	mov	ax,D_52FC
	mov	WORD PTR [bx],ax
; Line 128
	mov	bx,WORD PTR [bp+6]	;x2
	mov	ax,D_52FE
	mov	WORD PTR [bx],ax
; Line 129
	mov	bx,WORD PTR [bp+4]	;y2
	mov	ax,D_5300
	mov	WORD PTR [bx],ax
	jmp	$I600
	nop	
$EX596:
	mov	sp,bp
	pop	bp
	ret	8

FUN_1000_0935	ENDP
; Line 134
	PUBLIC	FUN_1000_0A22
FUN_1000_0A22	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,8
;	ax = 14
;	bx = 12
;	cx = 10
;	dx = 8
;	si = 6
;	di = 4
;	x1 = -2
;	y1 = -6
;	x2 = -4
;	y2 = -8
; Line 135
	mov	ax,WORD PTR [bp+14]	;ax
	mov	WORD PTR [bp-2],ax	;x1
; Line 136
	mov	ax,WORD PTR [bp+12]	;bx
	mov	WORD PTR [bp-6],ax	;y1
; Line 137
	mov	ax,WORD PTR [bp+10]	;cx
	mov	WORD PTR [bp-4],ax	;x2
; Line 138
	mov	ax,WORD PTR [bp+8]	;dx
	mov	WORD PTR [bp-8],ax	;y2
; Line 140
	mov	ax,WORD PTR D_52BA_VDP+22
	cmp	WORD PTR [bp-2],ax	;x1
	jge	$I615
; Line 141
	mov	bx,WORD PTR [bp+6]	;si
	or	BYTE PTR [bx],1
; Line 143
$I615:
	mov	ax,WORD PTR D_52BA_VDP+22
	cmp	WORD PTR [bp-4],ax	;x2
	jge	$I616
; Line 144
	mov	bx,WORD PTR [bp+4]	;di
	or	BYTE PTR [bx],1
; Line 146
$I616:
	mov	ax,WORD PTR D_52BA_VDP+24
	cmp	WORD PTR [bp-2],ax	;x1
	jle	$I617
; Line 147
	mov	bx,WORD PTR [bp+6]	;si
	or	BYTE PTR [bx],2
; Line 149
$I617:
	mov	ax,WORD PTR D_52BA_VDP+24
	cmp	WORD PTR [bp-4],ax	;x2
	jle	$I618
; Line 150
	mov	bx,WORD PTR [bp+4]	;di
	or	BYTE PTR [bx],2
; Line 152
$I618:
	mov	ax,WORD PTR D_52BA_VDP+28
	cmp	WORD PTR [bp-6],ax	;y1
	jle	$I619
; Line 153
	mov	bx,WORD PTR [bp+6]	;si
	or	BYTE PTR [bx],4
; Line 155
$I619:
	mov	ax,WORD PTR D_52BA_VDP+28
	cmp	WORD PTR [bp-8],ax	;y2
	jle	$I620
; Line 156
	mov	bx,WORD PTR [bp+4]	;di
	or	BYTE PTR [bx],4
; Line 158
$I620:
	mov	ax,WORD PTR D_52BA_VDP+26
	cmp	WORD PTR [bp-6],ax	;y1
	jge	$I621
; Line 159
	mov	bx,WORD PTR [bp+6]	;si
	or	BYTE PTR [bx],8
; Line 161
$I621:
	mov	ax,WORD PTR D_52BA_VDP+26
	cmp	WORD PTR [bp-8],ax	;y2
	jge	$I622
; Line 162
	mov	bx,WORD PTR [bp+4]	;di
	or	BYTE PTR [bx],8
; Line 163
$I622:
	mov	sp,bp
	pop	bp
	ret	12

FUN_1000_0A22	ENDP
; Line 167
	PUBLIC	FUN_1000_0AA6_FILL_RECTANGLE
FUN_1000_0AA6_FILL_RECTANGLE	PROC NEAR
	push	bp
	mov	bp,sp
;	x1 = 10
;	y1 = 8
;	x2 = 6
;	y2 = 4
; Line 168
	push	WORD PTR [bp+4]	;y2
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+10]	;x1
	mov	ax,OFFSET DGROUP:$SG628
	push	ax
	call	_printf
	add	sp,10
; Line 179
	pop	bp
	ret	8
	nop	

FUN_1000_0AA6_FILL_RECTANGLE	ENDP
; Line 182
	PUBLIC	FUN_1000_0B10_LINE
FUN_1000_0B10_LINE	PROC NEAR
	push	bp
	mov	bp,sp
;	x1 = 10
;	y1 = 8
;	x2 = 6
;	y2 = 4
; Line 183
	push	WORD PTR [bp+4]	;y2
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+10]	;x1
	mov	ax,OFFSET DGROUP:$SG634
	push	ax
	call	_printf
	add	sp,10
; Line 191
	push	WORD PTR [bp+10]	;x1
	push	WORD PTR [bp+8]	;y1
	push	WORD PTR [bp+6]	;x2
	push	WORD PTR [bp+4]	;y2
	call	FUN_1000_0B2D_LINE
; Line 193
	pop	bp
	ret	8

FUN_1000_0B10_LINE	ENDP
; Line 196
	PUBLIC	FUN_1000_0B2D_LINE
FUN_1000_0B2D_LINE	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,8
;	x1 = -2
;	y1 = -6
;	x2 = -4
;	y2 = -8
;	ax = 10
;	bx = 8
;	cx = 6
;	dx = 4
; Line 198
	mov	ax,WORD PTR [bp+10]	;ax
	mov	WORD PTR [bp-2],ax	;x1
; Line 199
	mov	ax,WORD PTR [bp+8]	;bx
	mov	WORD PTR [bp-6],ax	;y1
; Line 200
	mov	ax,WORD PTR [bp+6]	;cx
	mov	WORD PTR [bp-4],ax	;x2
; Line 201
	mov	ax,WORD PTR [bp+4]	;dx
	mov	WORD PTR [bp-8],ax	;y2
; Line 203
	mov	ax,WORD PTR [bp-4]	;x2
	mov	WORD PTR D_52BA_VDP+18,ax
; Line 204
	mov	ax,WORD PTR [bp-8]	;y2
	mov	WORD PTR D_52BA_VDP+20,ax
; Line 207
	cmp	WORD PTR D_52BA_VDP+10,0
	je	$I644
; Line 208
; Line 209
	lea	ax,WORD PTR [bp+10]	;ax
	push	ax
	lea	ax,WORD PTR [bp+8]	;bx
	push	ax
	lea	ax,WORD PTR [bp+6]	;cx
	push	ax
	lea	ax,WORD PTR [bp+4]	;dx
	push	ax
	call	FUN_1000_0935
	or	ax,ax
	jne	$I649
; Line 210
; Line 213
$I644:
	mov	ax,WORD PTR [bp-8]	;y2
	cmp	WORD PTR [bp-6],ax	;y1
	jne	$I646
; Line 214
; Line 215
	mov	ax,WORD PTR [bp-4]	;x2
	cmp	WORD PTR [bp-2],ax	;x1
	jne	$I647
; Line 216
; Line 219
	mov	ax,48
$L20001:
	push	ax
	call	FAR PTR DRV_FARCALL
; Line 220
	jmp	SHORT $I649
	nop	
$I647:
; Line 223
; Line 226
	mov	ax,57
	jmp	SHORT $L20001
	nop	
$I646:
; Line 230
; Line 232
	mov	ax,WORD PTR [bp-4]	;x2
	cmp	WORD PTR [bp-2],ax	;x1
	jne	$I650
; Line 233
; Line 236
	mov	ax,60
	jmp	SHORT $L20001
	nop	
$I650:
; Line 240
; Line 243
	mov	ax,51
	jmp	SHORT $L20001
	nop	
$I649:
; Line 249
	mov	sp,bp
	pop	bp
	ret	8

FUN_1000_0B2D_LINE	ENDP
; Line 252
	PUBLIC	FUN_1000_0F90_PEN
FUN_1000_0F90_PEN	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 6
;	y = 4
; Line 253
	push	WORD PTR [bp+4]	;y
	push	WORD PTR [bp+6]	;x
	mov	ax,OFFSET DGROUP:$SG655
	push	ax
	call	_printf
	add	sp,6
; Line 262
	push	WORD PTR D_52BA_VDP+18
	push	WORD PTR D_52BA_VDP+20
	push	WORD PTR [bp+6]	;x
	push	WORD PTR [bp+4]	;y
	call	FUN_1000_0B2D_LINE
; Line 264
	pop	bp
	ret	4

FUN_1000_0F90_PEN	ENDP
_TEXT	ENDS
END
