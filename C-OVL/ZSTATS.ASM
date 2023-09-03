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
EXTRN	FUN_0000_5D32:NEAR
EXTRN	FUN_0000_8BCA:NEAR
EXTRN	FUN_0000_8C70:NEAR
EXTRN	FUN_0000_8B96:NEAR
EXTRN	FUN_0000_54DA:NEAR
EXTRN	FUN_0000_5670:NEAR
EXTRN	FUN_0000_585E:NEAR
EXTRN	FUN_0000_5A42:NEAR
EXTRN	FUN_0000_5A12:NEAR
EXTRN	FUN_0000_6B9A:NEAR
EXTRN	D_1A44:BYTE
EXTRN	D_1A58:BYTE
EXTRN	D_1A6A:BYTE
EXTRN	D_BA16:BYTE
EXTRN	UNK_0000_5893:BYTE
EXTRN	UNK_0000_589E:BYTE
EXTRN	UNK_0000_55A8:WORD
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
EXTRN	DAT_0000_9700:WORD
EXTRN	D_1962:BYTE
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 73
	PUBLIC	FUN_0000_2000
FUN_0000_2000	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
;	param_1 = 4
;	local_4 = -4
;	register si = si
; Line 78
	mov	WORD PTR [bp-4],-1	;local_4
; Line 80
	cmp	BYTE PTR UNK_0000_5893,128
	jbe	$I201
; Line 81
	mov	al,UNK_0000_589E
	sub	ah,ah
	mov	si,ax
	mov	cl,3
	shl	si,cl
; Line 82
	test	BYTE PTR D_BA16[si],128
	je	$I201
; Line 83
	mov	al,BYTE PTR D_BA16[si+1]
	mov	WORD PTR [bp-4],ax	;local_4
; Line 86
	jmp	SHORT $I207
$I201:
; Line 89
	mov	ax,OFFSET DAT_0000_96B4
	push	ax
	call	FUN_0000_5670
; Line 90
	push	WORD PTR [bp+4]	;param_1
	call	FUN_0000_6B9A
	mov	WORD PTR [bp-4],ax	;local_4
; Line 91
	or	ax,ax
	jl	$I207
; Line 92
	mov	cl,5
	shl	ax,cl
	add	ax,OFFSET UNK_0000_55A8
	push	ax
	call	FUN_0000_5670
; Line 93
	call	FUN_0000_5D32
	or	ax,ax
	je	$I207
; Line 94
	mov	ax,10
	push	ax
	call	FUN_0000_54DA
; Line 95
; Line 96
$I207:
; Line 97
; Line 100
	cmp	WORD PTR [bp-4],-1	;local_4
	jne	$I208
; Line 101
	mov	ax,OFFSET DAT_0000_96BE
	push	ax
	call	FUN_0000_5670
; Line 102
; Line 104
	jmp	SHORT $I210
$I208:
	cmp	WORD PTR [bp-4],-2	;local_4
	jne	$I210
; Line 105
	mov	ax,10
	push	ax
	call	FUN_0000_54DA
; Line 106
; Line 109
$I210:
	mov	ax,WORD PTR [bp-4]	;local_4
	pop	si
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_0000_2000	ENDP
; Line 114
	PUBLIC	FUN_0000_2082
FUN_0000_2082	PROC NEAR
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
; Line 124
	call	FUN_0000_8BCA
; Line 126
	mov	ax,WORD PTR [bp+4]	;param_1
	mov	cl,5
	shl	ax,cl
	add	ax,UNK_0000_55A8
	mov	WORD PTR [bp-12],ax	;local_4
; Line 128
	push	ax
	call	FUN_0000_8C70
; Line 129
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
	call	FUN_0000_5A42
; Line 130
	mov	ax,255
	push	ax
	call	FUN_0000_54DA
; Line 131
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
	call	FUN_0000_5A42
; Line 133
	mov	ax,OFFSET DAT_0000_96C6
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+10]
	sub	ah,ah
	push	ax
	call	FUN_0000_8B96
	mov	WORD PTR [bp-2],ax	;local_6
; Line 134
	mov	ax,OFFSET DAT_0000_96D0
	push	ax
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+11]
	sub	ah,ah
	push	ax
	call	FUN_0000_8B96
	mov	WORD PTR [bp-6],ax	;local_a
; Line 135
	mov	WORD PTR [bp-4],0	;local_8
; Line 137
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	cmp	WORD PTR D_1A58[bx],0
	jle	$I223
; Line 138
	mov	di,WORD PTR [bp-2]	;local_6
	shl	di,1
	add	di,OFFSET D_1A58
; Line 140
	sub	si,si
; Line 141
$FC225:
; Line 142
	mov	ax,32
	push	ax
	call	FUN_0000_54DA
; Line 143
	inc	si
; Line 144
	cmp	WORD PTR [di],si
	jg	$FC225
; Line 145
; Line 148
	mov	WORD PTR [bp-4],si	;local_8
; Line 149
; Line 151
$I223:
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+9]
	sub	ah,ah
	push	ax
	call	FUN_0000_54DA
; Line 152
	mov	ax,OFFSET DAT_0000_96D6
	push	ax
	call	FUN_0000_5670
; Line 153
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+22]
	sub	ah,ah
	push	ax
	mov	ax,1
	push	ax
	mov	ax,32
	push	ax
	call	FUN_0000_585E
; Line 154
	mov	ax,32
	push	ax
	call	FUN_0000_54DA
; Line 155
	mov	bx,WORD PTR [bp-2]	;local_6
	shl	bx,1
	push	WORD PTR D_1A44[bx]
	call	FUN_0000_5670
; Line 156
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
	call	FUN_0000_5A42
; Line 157
	sub	ax,ax
	push	ax
	mov	ax,1
	push	ax
	call	FUN_0000_5A12
; Line 158
	mov	ax,252
	push	ax
	call	FUN_0000_54DA
; Line 159
	mov	bx,WORD PTR [bp-6]	;local_a
	shl	bx,1
	push	WORD PTR D_1A6A[bx]
	call	FUN_0000_5670
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
	call	FUN_0000_5A42
; Line 161
	sub	ax,ax
	push	ax
	mov	ax,3
	push	ax
	call	FUN_0000_5A12
; Line 162
	mov	ax,251
	push	ax
	call	FUN_0000_54DA
; Line 163
	mov	ax,OFFSET DAT_0000_96DC
	push	ax
	call	FUN_0000_5670
; Line 164
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+12]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_0000_585E
; Line 165
	mov	ax,OFFSET DAT_0000_96E2
	push	ax
	call	FUN_0000_5670
; Line 166
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+16]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_0000_585E
; Line 167
	mov	ax,OFFSET DAT_0000_96E8
	push	ax
	call	FUN_0000_5670
; Line 168
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+14]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_0000_585E
; Line 169
	mov	ax,OFFSET DAT_0000_96EE
	push	ax
	call	FUN_0000_5670
; Line 170
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+18]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_0000_585E
; Line 171
	mov	ax,OFFSET DAT_0000_96F4
	push	ax
	call	FUN_0000_5670
; Line 172
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+13]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,48
	push	ax
	call	FUN_0000_585E
; Line 173
	mov	ax,OFFSET DAT_0000_96FA
	push	ax
	call	FUN_0000_5670
; Line 174
	mov	bx,WORD PTR [bp-12]	;local_4
	push	WORD PTR [bx+20]
	mov	ax,4
	push	ax
	mov	ax,32
	push	ax
	call	FUN_0000_585E
; Line 175
	mov	ax,OFFSET DAT_0000_9700
	push	ax
	call	FUN_0000_5670
; Line 176
	mov	bx,WORD PTR [bp-12]	;local_4
	mov	al,BYTE PTR [bx+15]
	sub	ah,ah
	push	ax
	mov	ax,2
	push	ax
	mov	ax,32
	push	ax
	call	FUN_0000_585E
; Line 177
	pop	si
	pop	di
	mov	sp,bp
	pop	bp
	ret	2
	nop	

FUN_0000_2082	ENDP
; Line 180
	PUBLIC	FUN_0000_2278
FUN_0000_2278	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
; Line 181
	cmp	WORD PTR [bp+4],255	;param_1
	jne	$I231
; Line 182
	sub	ax,ax
	jmp	SHORT $EX230
$I231:
; Line 183
; Line 184
	mov	ax,32
	push	ax
	call	FUN_0000_54DA
; Line 185
	mov	bx,WORD PTR [bp+4]	;param_1
	shl	bx,1
	push	WORD PTR D_1962[bx]
	call	FUN_0000_5670
; Line 186
	mov	ax,10
	push	ax
	call	FUN_0000_54DA
; Line 187
	mov	ax,1
$EX230:
	pop	bp
	ret	2
	nop	

FUN_0000_2278	ENDP
_TEXT	ENDS
END
