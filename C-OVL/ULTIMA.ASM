;	Static Name Aliases
;
	TITLE   ultima.c
	NAME    ultima

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
EXTRN	MAINOUT_0D22:NEAR
EXTRN	TOWN_MAIN1_11F0:NEAR
EXTRN	TOWN_MAIN2_141E:NEAR
EXTRN	DUNGEON_0E2E:NEAR
EXTRN	OUTSUBS_GET_WORLD_SAVEFILE_0348:NEAR
EXTRN	FUN_1000_0878_SET_OLD_VIDEO_MOD:NEAR
EXTRN	FUN_1000_1674_TEST_OPEN_FILE:NEAR
EXTRN	FUN_1000_16A6_GET_DEFAULT_DRIVE:NEAR
EXTRN	FUN_1000_2032_TO_UPPER:NEAR
EXTRN	FUN_1000_256E_READ_FILE_FROM_DI:NEAR
EXTRN	FUN_1000_25D8_WRITE_FILE_TO_DIS:NEAR
EXTRN	FUN_1000_251E_SWITCH_DISKS:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	INTRO_INTRO_MAIN:NEAR
EXTRN	D_52F1:WORD
EXTRN	D_52F3:WORD
EXTRN	D_538C:WORD
EXTRN	D_5394:WORD
EXTRN	D_5396:WORD
EXTRN	D_5893:BYTE
EXTRN	D_5895:BYTE
EXTRN	D_A9BD:WORD
EXTRN	D_A9BE:WORD
EXTRN	D_A9C2:WORD
EXTRN	D_A9C8:BYTE
EXTRN	D_A9C9:BYTE
EXTRN	D_A9CA:BYTE
EXTRN	D_A9CB:BYTE
EXTRN	D_A9CD:BYTE
EXTRN	D_B11C:WORD
EXTRN	D_52A6:WORD
EXTRN	D_52A4:WORD
EXTRN	D_52A2:WORD
EXTRN	D_52BA:WORD
EXTRN	D_52EF:WORD
_DATA      SEGMENT
$SG351	DB	'BRIT.DAT',  00H
$SG356	DB	'UNDER.DAT',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 11
	PUBLIC	_F_1000_0000_main
_F_1000_0000_main	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,8
;	argc = 4
;	argv = 6
;	envp = 8
;	local_8 = -4
;	local_6 = -2
;	local_4 = -8
;	local_2 = -6
; Line 17
	mov	BYTE PTR [bp-8],32	;local_4
; Line 19
	cmp	WORD PTR [bp+4],1	;argc
	jle	$I338
; Line 20
; Line 21
	mov	bx,WORD PTR [bp+6]	;argv
	mov	bx,WORD PTR [bx+2]
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	BYTE PTR [bp-8],al	;local_4
; Line 22
; Line 25
$I338:
	cmp	BYTE PTR [bp-8],67	;local_4
	jne	$L20000
	mov	ax,1
	jmp	SHORT $L20001
$L20000:
	sub	ax,ax
$L20001:
	mov	D_52BA,ax
; Line 26
	cmp	BYTE PTR [bp-8],72	;local_4
	jne	$L20002
	mov	ax,1
	jmp	SHORT $L20003
$L20002:
	sub	ax,ax
$L20003:
	mov	D_52F3,ax
; Line 27
	cmp	BYTE PTR [bp-8],84	;local_4
	jne	$L20004
	mov	ax,1
	jmp	SHORT $L20005
$L20004:
	sub	ax,ax
$L20005:
	mov	D_52F1,ax
; Line 28
	cmp	BYTE PTR [bp-8],69	;local_4
	jne	$L20006
	mov	ax,1
	jmp	SHORT $L20007
$L20006:
	sub	ax,ax
$L20007:
	mov	D_52EF,ax
; Line 31
	mov	WORD PTR D_5394,8994
; Line 32
	mov	WORD PTR D_5396,4096
; Line 34
	mov	WORD PTR D_A9BD,0
; Line 35
	mov	WORD PTR D_A9BE,0
; Line 36
	mov	WORD PTR D_A9C2,1
; Line 38
	call	FUN_1000_16A6_GET_DEFAULT_DRIVE
	mov	D_A9C8,al
	cmp	al,67
	jb	$I339
; Line 39
	mov	BYTE PTR [bp-2],al	;local_6
; Line 40
	jmp	SHORT $I340
$I339:
; Line 41
	mov	BYTE PTR [bp-2],255	;local_6
$I340:
; Line 44
	mov	al,BYTE PTR [bp-2]	;local_6
	mov	D_A9CD,al
; Line 45
	mov	D_A9CA,al
; Line 46
	mov	D_A9C9,al
; Line 48
	mov	BYTE PTR D_A9CB,255
; Line 49
	mov	WORD PTR D_B11C,-19938
; Line 50
	mov	WORD PTR D_538C,1
; Line 52
	call	INTRO_INTRO_MAIN
; Line 53
	call	FUN_1000_2900
; Line 55
	mov	WORD PTR [bp-4],0	;local_8
; Line 58
$D341:
; Line 59
; Line 60
	mov	WORD PTR [bp-6],0	;local_2
; Line 62
	cmp	BYTE PTR D_5893,0
	jne	$I344
; Line 63
; Line 64
	call	MAINOUT_0D22
; Line 65
	mov	WORD PTR [bp-6],1	;local_2
; Line 66
	mov	WORD PTR [bp-4],0	;local_8
; Line 67
; Line 70
$I344:
	cmp	BYTE PTR D_5893,0
	jne	$JCC216
	jmp	$I352
$JCC216:
; Line 71
; Line 73
	cmp	BYTE PTR D_5893,33
	jae	$I346
; Line 74
; Line 75
	cmp	WORD PTR [bp-6],0	;local_2
	jne	$L20010
	cmp	WORD PTR [bp-4],0	;local_8
	je	$L20008
$L20010:
	mov	ax,1
	jmp	SHORT $L20009
	nop	
$L20008:
	sub	ax,ax
$L20009:
	push	ax
	call	TOWN_MAIN1_11F0
; Line 76
	call	TOWN_MAIN2_141E
; Line 77
	mov	WORD PTR [bp-4],0	;local_8
; Line 78
; Line 79
	jmp	SHORT $I347
$I346:
; Line 80
; Line 82
	mov	ax,2
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 83
	push	WORD PTR [bp-6]	;local_2
	call	DUNGEON_0E2E
; Line 84
	mov	WORD PTR [bp-4],1	;local_8
; Line 85
$I347:
; Line 88
	mov	WORD PTR [bp-6],0	;local_2
; Line 89
	mov	ax,1
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 92
$FC349:
	mov	ax,OFFSET DGROUP:$SG351
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC349
; Line 93
	call	OUTSUBS_GET_WORLD_SAVEFILE_0348
	push	ax
	mov	ax,23642
	push	ax
	mov	ax,256
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 95
	cmp	BYTE PTR D_5893,0
	jne	$I352
	cmp	BYTE PTR D_5895,0
	je	$I352
; Line 96
; Line 97
	mov	ax,5
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 100
$FC354:
	mov	ax,OFFSET DGROUP:$SG356
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC354
; Line 101
	call	OUTSUBS_GET_WORLD_SAVEFILE_0348
	push	ax
	mov	ax,23642
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 102
; Line 103
$I352:
; Line 105
	cmp	WORD PTR [bp-6],0	;local_2
	jne	$JCC372
	jmp	$D341
$JCC372:
; Line 107
	call	FUN_1000_0878_SET_OLD_VIDEO_MOD
; Line 108
	mov	sp,bp
	pop	bp
	ret	

_F_1000_0000_main	ENDP
; Line 114
	PUBLIC	FUN_1000_017E_ENTRY_POINT
FUN_1000_017E_ENTRY_POINT	PROC NEAR
; Line 124
	push	WORD PTR D_52A6
	push	WORD PTR D_52A4
	push	WORD PTR D_52A2
	call	_F_1000_0000_main
	add	sp,6
	push	ax
	call	FUN_1000_02F4_EXIT_TO_DOS
; Line 125
	ret	
	nop	

FUN_1000_017E_ENTRY_POINT	ENDP
; Line 129
	PUBLIC	FUN_1000_0230
FUN_1000_0230	PROC NEAR
	ret	
	nop	

FUN_1000_0230	ENDP
; Line 133
	PUBLIC	FUN_1000_02F4_EXIT_TO_DOS
FUN_1000_02F4_EXIT_TO_DOS	PROC NEAR
	push	bp
;	return_code = 4
; Line 135
	pop	bp
	ret	2
	nop	

FUN_1000_02F4_EXIT_TO_DOS	ENDP
; Line 139
	PUBLIC	_main
_main	PROC NEAR
	push	bp
	mov	bp,sp
;	argc = 4
;	argv = 6
;	envp = 8
; Line 140
	mov	ax,WORD PTR [bp+8]	;envp
	mov	D_52A6,ax
; Line 141
	mov	ax,WORD PTR [bp+6]	;argv
	mov	D_52A4,ax
; Line 142
	mov	ax,WORD PTR [bp+4]	;argc
	mov	D_52A2,ax
; Line 144
	call	FUN_1000_017E_ENTRY_POINT
; Line 145
	pop	bp
	ret	

_main	ENDP
_TEXT	ENDS
END
