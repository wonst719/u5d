;	Static Name Aliases
;
	TITLE   file.c
	NAME    file

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
EXTRN	_fclose:NEAR
EXTRN	_fopen:NEAR
EXTRN	_fread:NEAR
EXTRN	_fseek:NEAR
_BSS      SEGMENT
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
_BSS      ENDS
_DATA      SEGMENT
$SG528	DB	'rb',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 9
	PUBLIC	FILE_READFILE
FILE_READFILE	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,4
;	fileName = 10
;	buffer = 8
;	size = 6
;	offset = 4
;	stream = -2
; Line 12
	mov	bx,WORD PTR [bp+10]	;fileName
	mov	al,BYTE PTR [bx]
	mov	BYTE PTR [bp-4],al
	cmp	al,65
	je	$I527
	cmp	al,97
	jne	$I526
$I527:
	cmp	BYTE PTR [bx+1],58
	je	$EX524
; Line 13
; Line 15
$I526:
	mov	ax,OFFSET DGROUP:$SG528
	push	ax
	push	bx
	call	_fopen
	add	sp,4
	mov	WORD PTR [bp-2],ax	;stream
; Line 19
	or	ax,ax
	jne	$I529
; Line 20
; Line 21
	mov	ax,-1
	jmp	SHORT $EX524
	nop	
$I529:
	sub	ax,ax
	push	ax
	mov	ax,WORD PTR [bp+4]	;offset
	cwd	
	push	dx
	push	ax
	push	WORD PTR [bp-2]	;stream
	call	_fseek
	add	sp,8
; Line 25
	push	WORD PTR [bp-2]	;stream
	mov	ax,1
	push	ax
	push	WORD PTR [bp+6]	;size
	push	WORD PTR [bp+8]	;buffer
	call	_fread
	add	sp,8
; Line 26
	push	WORD PTR [bp-2]	;stream
	call	_fclose
	add	sp,2
; Line 28
	sub	ax,ax
$EX524:
	mov	sp,bp
	pop	bp
	ret	8

FILE_READFILE	ENDP
_TEXT	ENDS
END
