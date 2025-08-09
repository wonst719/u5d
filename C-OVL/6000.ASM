;	Static Name Aliases
;
	TITLE   6000.c
	NAME    6000

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
EXTRN	FUN_1000_0A70_SET_PEN_COLOR:NEAR
EXTRN	FUN_1000_1BF2_SET_TEXT_CURSOR_P:NEAR
EXTRN	FUN_1000_0AA6_FILL_RECTANGLE:NEAR
EXTRN	FUN_1000_1CCA_SET_TEXT_FOREGROU:NEAR
EXTRN	FUN_1000_0B10_LINE:NEAR
EXTRN	FUN_1000_0F90_PEN:NEAR
EXTRN	FUN_1000_16BA_PRINT_CHAR:NEAR
EXTRN	D_13B0_WHITE_COLOR:WORD
EXTRN	D_13B2_FRAME_COLOR:WORD
_BSS      SEGMENT
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
_BSS      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 8
	PUBLIC	FUN_1000_637E_DRAW_FRAME
FUN_1000_637E_DRAW_FRAME	PROC NEAR
; Line 10
	sub	ax,ax
	push	ax
	call	FUN_1000_0A70_SET_PEN_COLOR
; Line 11
	sub	ax,ax
	push	ax
	push	ax
	mov	ax,319
	push	ax
	mov	ax,199
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 13
	push	WORD PTR D_13B2_FRAME_COLOR
	call	FUN_1000_0A70_SET_PEN_COLOR
; Line 14
	sub	ax,ax
	push	ax
	push	ax
	mov	ax,319
	push	ax
	mov	ax,6
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 15
	sub	ax,ax
	push	ax
	mov	ax,185
	push	ax
	mov	ax,191
	push	ax
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 16
	sub	ax,ax
	push	ax
	push	ax
	mov	ax,6
	push	ax
	mov	ax,191
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 17
	mov	ax,185
	push	ax
	sub	ax,ax
	push	ax
	mov	ax,191
	push	ax
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 18
	mov	ax,313
	push	ax
	sub	ax,ax
	push	ax
	mov	ax,319
	push	ax
	mov	ax,87
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 19
	mov	ax,192
	push	ax
	mov	ax,80
	push	ax
	mov	ax,312
	push	ax
	mov	ax,87
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 20
	mov	ax,192
	push	ax
	mov	ax,57
	push	ax
	mov	ax,312
	push	ax
	mov	ax,63
	push	ax
	call	FUN_1000_0AA6_FILL_RECTANGLE
; Line 22
	push	WORD PTR D_13B2_FRAME_COLOR
	call	FUN_1000_1CCA_SET_TEXT_FOREGROU
; Line 23
	sub	ax,ax
	push	ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 24
	mov	ax,123
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 25
	mov	ax,39
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 26
	mov	ax,124
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 27
	sub	ax,ax
	push	ax
	mov	ax,23
	push	ax
	call	FUN_1000_1BF2_SET_TEXT_CURSOR_P
; Line 28
	mov	ax,125
	push	ax
	call	FUN_1000_16BA_PRINT_CHAR
; Line 30
	push	WORD PTR D_13B0_WHITE_COLOR
	call	FUN_1000_0A70_SET_PEN_COLOR
; Line 31
	mov	ax,7
	push	ax
	push	ax
	push	ax
	mov	ax,184
	push	ax
	call	FUN_1000_0B10_LINE
; Line 32
	mov	ax,184
	push	ax
	push	ax
	call	FUN_1000_0F90_PEN
; Line 33
	mov	ax,184
	push	ax
	mov	ax,7
	push	ax
	call	FUN_1000_0F90_PEN
; Line 34
	mov	ax,7
	push	ax
	push	ax
	call	FUN_1000_0F90_PEN
; Line 35
	mov	ax,191
	push	ax
	push	ax
	push	ax
	mov	ax,87
	push	ax
	call	FUN_1000_0B10_LINE
; Line 36
	mov	ax,319
	push	ax
	mov	ax,87
	push	ax
	call	FUN_1000_0F90_PEN
; Line 37
	mov	ax,191
	push	ax
	mov	ax,7
	push	ax
	mov	ax,312
	push	ax
	mov	ax,7
	push	ax
	call	FUN_1000_0B10_LINE
; Line 38
	mov	ax,312
	push	ax
	mov	ax,56
	push	ax
	call	FUN_1000_0F90_PEN
; Line 39
	mov	ax,191
	push	ax
	mov	ax,56
	push	ax
	call	FUN_1000_0F90_PEN
; Line 40
	mov	ax,191
	push	ax
	mov	ax,7
	push	ax
	call	FUN_1000_0F90_PEN
; Line 41
	mov	ax,191
	push	ax
	mov	ax,63
	push	ax
	mov	ax,312
	push	ax
	mov	ax,63
	push	ax
	call	FUN_1000_0B10_LINE
; Line 42
	mov	ax,312
	push	ax
	mov	ax,80
	push	ax
	call	FUN_1000_0F90_PEN
; Line 43
	mov	ax,191
	push	ax
	mov	ax,80
	push	ax
	call	FUN_1000_0F90_PEN
; Line 44
	mov	ax,191
	push	ax
	mov	ax,63
	push	ax
	call	FUN_1000_0F90_PEN
; Line 46
	push	WORD PTR D_13B0_WHITE_COLOR
	call	FUN_1000_1CCA_SET_TEXT_FOREGROU
; Line 47
	ret	

FUN_1000_637E_DRAW_FRAME	ENDP
_TEXT	ENDS
END
