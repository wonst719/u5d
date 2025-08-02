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
EXTRN	FUN_1000_2032_TO_UPPER:NEAR
EXTRN	FUN_1000_256E_READ_FILE_FROM_DI:NEAR
EXTRN	FUN_1000_25D8_WRITE_FILE_TO_DIS:NEAR
EXTRN	FUN_1000_251E_SWITCH_DISKS:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	INTRO_INTRO_MAIN:NEAR
EXTRN	MAINOUT_0D22:NEAR
EXTRN	TOWN_MAIN1_11F0:NEAR
EXTRN	TOWN_MAIN2_141E:NEAR
EXTRN	DUNGEON_0E2E:NEAR
EXTRN	OUTSUBS_GET_WORLD_SAVEFILE_0348:NEAR
EXTRN	FUN_1000_0878_SET_OLD_VIDEO_MOD:NEAR
EXTRN	FUN_1000_1674_TEST_OPEN_FILE:NEAR
EXTRN	FUN_1000_16A6_GET_DEFAULT_DRIVE:NEAR
EXTRN	D_52EF:WORD
EXTRN	D_52F1:WORD
EXTRN	D_52F3:WORD
EXTRN	D_5893_MAP_ID:BYTE
EXTRN	D_5895:BYTE
EXTRN	D_A9BD:WORD
_BSS      SEGMENT
COMM NEAR	D_535E:	BYTE:	 32
EXTRN	D_A9BE:WORD
EXTRN	D_A9C2:WORD
EXTRN	D_A9C8:BYTE
EXTRN	D_A9C9:BYTE
EXTRN	D_538C:WORD
EXTRN	D_A9CA:BYTE
EXTRN	D_A9CB:BYTE
EXTRN	D_A9CD:BYTE
EXTRN	D_5394:WORD
EXTRN	D_B11C:WORD
EXTRN	D_5396:WORD
EXTRN	D_52A2:WORD
EXTRN	D_52A4:WORD
EXTRN	D_52A6:WORD
EXTRN	D_52BA:WORD
_BSS      ENDS
_DATA      SEGMENT
$SG399	DB	'BRIT.DAT',  00H
$SG404	DB	'UNDER.DAT',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 10
	PUBLIC	_F_1000_0000_main
_F_1000_0000_main	PROC NEAR
	push	bp
	mov	bp,sp
	sub	sp,8
;	local_4 = -8
;	local_2 = -6
;	argc = 4
;	argv = 6
;	envp = 8
;	local_8 = -4
;	local_6 = -2
; Line 16
	mov	BYTE PTR [bp-8],32	;local_4
; Line 18
	cmp	WORD PTR [bp+4],1	;argc
	jle	$I386
; Line 19
; Line 20
	mov	bx,WORD PTR [bp+6]	;argv
	mov	bx,WORD PTR [bx+2]
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	BYTE PTR [bp-8],al	;local_4
; Line 21
; Line 24
$I386:
	cmp	BYTE PTR [bp-8],67	;local_4
	jne	$L20000
	mov	ax,1
	jmp	SHORT $L20001
$L20000:
	sub	ax,ax
$L20001:
	mov	D_52BA,ax
; Line 25
	cmp	BYTE PTR [bp-8],72	;local_4
	jne	$L20002
	mov	ax,1
	jmp	SHORT $L20003
$L20002:
	sub	ax,ax
$L20003:
	mov	D_52F3,ax
; Line 26
	cmp	BYTE PTR [bp-8],84	;local_4
	jne	$L20004
	mov	ax,1
	jmp	SHORT $L20005
$L20004:
	sub	ax,ax
$L20005:
	mov	D_52F1,ax
; Line 27
	cmp	BYTE PTR [bp-8],69	;local_4
	jne	$L20006
	mov	ax,1
	jmp	SHORT $L20007
$L20006:
	sub	ax,ax
$L20007:
	mov	D_52EF,ax
; Line 30
	mov	WORD PTR D_5394,8994
; Line 31
	mov	WORD PTR D_5396,4096
; Line 33
	mov	WORD PTR D_A9BD,0
; Line 34
	mov	WORD PTR D_A9BE,0
; Line 35
	mov	WORD PTR D_A9C2,1
; Line 37
	call	FUN_1000_16A6_GET_DEFAULT_DRIVE
	mov	D_A9C8,al
	cmp	al,67
	jb	$I387
; Line 38
	mov	BYTE PTR [bp-2],al	;local_6
; Line 39
	jmp	SHORT $I388
$I387:
; Line 40
	mov	BYTE PTR [bp-2],255	;local_6
$I388:
; Line 43
	mov	al,BYTE PTR [bp-2]	;local_6
	mov	D_A9CD,al
; Line 44
	mov	D_A9CA,al
; Line 45
	mov	D_A9C9,al
; Line 47
	mov	BYTE PTR D_A9CB,255
; Line 48
	mov	WORD PTR D_B11C,-19938
; Line 49
	mov	WORD PTR D_538C,1
; Line 51
	call	INTRO_INTRO_MAIN
; Line 52
	call	FUN_1000_2900
; Line 54
	mov	WORD PTR [bp-4],0	;local_8
; Line 57
$D389:
; Line 58
; Line 59
	mov	WORD PTR [bp-6],0	;local_2
; Line 61
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I392
; Line 62
; Line 63
	call	MAINOUT_0D22
; Line 64
	mov	WORD PTR [bp-6],1	;local_2
; Line 65
	mov	WORD PTR [bp-4],0	;local_8
; Line 66
; Line 69
$I392:
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$JCC216
	jmp	$I400
$JCC216:
; Line 70
; Line 72
	cmp	BYTE PTR D_5893_MAP_ID,33
	jae	$I394
; Line 73
; Line 74
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
; Line 75
	call	TOWN_MAIN2_141E
; Line 76
	mov	WORD PTR [bp-4],0	;local_8
; Line 77
; Line 78
	jmp	SHORT $I395
$I394:
; Line 79
; Line 81
	mov	ax,2
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 82
	push	WORD PTR [bp-6]	;local_2
	call	DUNGEON_0E2E
; Line 83
	mov	WORD PTR [bp-4],1	;local_8
; Line 84
$I395:
; Line 87
	mov	WORD PTR [bp-6],0	;local_2
; Line 88
	mov	ax,1
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 91
$FC397:
	mov	ax,OFFSET DGROUP:$SG399
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC397
; Line 92
	call	OUTSUBS_GET_WORLD_SAVEFILE_0348
	push	ax
	mov	ax,23642
	push	ax
	mov	ax,256
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 94
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I400
	cmp	BYTE PTR D_5895,0
	je	$I400
; Line 95
; Line 96
	mov	ax,5
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 99
$FC402:
	mov	ax,OFFSET DGROUP:$SG404
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC402
; Line 100
	call	OUTSUBS_GET_WORLD_SAVEFILE_0348
	push	ax
	mov	ax,23642
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 101
; Line 102
$I400:
; Line 104
	cmp	WORD PTR [bp-6],0	;local_2
	jne	$JCC372
	jmp	$D389
$JCC372:
; Line 106
	call	FUN_1000_0878_SET_OLD_VIDEO_MOD
; Line 107
	mov	sp,bp
	pop	bp
	ret	

_F_1000_0000_main	ENDP
; Line 113
	PUBLIC	FUN_1000_017E_ENTRY_POINT
FUN_1000_017E_ENTRY_POINT	PROC NEAR
; Line 123
	push	WORD PTR D_52A6
	push	WORD PTR D_52A4
	push	WORD PTR D_52A2
	call	_F_1000_0000_main
	add	sp,6
	push	ax
	call	FUN_1000_02F4_EXIT_TO_DOS
; Line 124
	ret	
	nop	

FUN_1000_017E_ENTRY_POINT	ENDP
; Line 128
	PUBLIC	FUN_1000_0230
FUN_1000_0230	PROC NEAR
	ret	
	nop	

FUN_1000_0230	ENDP
; Line 132
	PUBLIC	FUN_1000_02F4_EXIT_TO_DOS
FUN_1000_02F4_EXIT_TO_DOS	PROC NEAR
	push	bp
;	return_code = 4
; Line 134
	pop	bp
	ret	2
	nop	

FUN_1000_02F4_EXIT_TO_DOS	ENDP
; Line 138
	PUBLIC	_main
_main	PROC NEAR
	push	bp
	mov	bp,sp
;	argc = 4
;	argv = 6
;	envp = 8
; Line 139
	mov	ax,WORD PTR [bp+8]	;envp
	mov	D_52A6,ax
; Line 140
	mov	ax,WORD PTR [bp+6]	;argv
	mov	D_52A4,ax
; Line 141
	mov	ax,WORD PTR [bp+4]	;argc
	mov	D_52A2,ax
; Line 143
	call	FUN_1000_017E_ENTRY_POINT
; Line 144
	pop	bp
	ret	

_main	ENDP
_TEXT	ENDS
END
