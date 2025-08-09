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
EXTRN	INTRO_INTRO_MAIN:NEAR
EXTRN	MAINOUT_0D22:NEAR
EXTRN	TOWN_MAIN1_11F0:NEAR
EXTRN	OUTSUBS_0368_GETWORLDSAVEFILE:NEAR
EXTRN	TOWN_MAIN2_141E_MAINLOOP:NEAR
EXTRN	DUNGEON_0E2E_MAINLOOP:NEAR
EXTRN	_FUN_1000_02F4_exit_to_dos:NEAR
EXTRN	FUN_1000_0878_SET_OLD_VIDEO_MOD:NEAR
EXTRN	FUN_1000_2032_TO_UPPER:NEAR
EXTRN	FUN_1000_251E_SWITCH_DISKS:NEAR
EXTRN	FUN_1000_256E_READ_FILE_FROM_DI:NEAR
EXTRN	FUN_1000_25D8_WRITE_FILE_TO_DIS:NEAR
EXTRN	FUN_1000_2900:NEAR
EXTRN	FUN_1000_1674_TEST_OPEN_FILE:NEAR
EXTRN	FUN_1000_16A6_GET_DEFAULT_DRIVE:NEAR
EXTRN	D_52A2:WORD
EXTRN	D_52A4:WORD
EXTRN	D_52A6:WORD
EXTRN	D_52BA_FORCECGA:WORD
EXTRN	D_52EF:WORD
EXTRN	D_52F1_FORCETANDY:WORD
EXTRN	D_52F3:WORD
EXTRN	D_5893_MAP_ID:BYTE
EXTRN	D_5895:BYTE
EXTRN	D_5C5A:BYTE
_BSS      SEGMENT
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
EXTRN	D_A9BD:WORD
EXTRN	D_A9BE:WORD
EXTRN	D_A9C2:WORD
EXTRN	D_538C:WORD
EXTRN	D_A9C8:BYTE
EXTRN	D_A9C9:BYTE
EXTRN	D_A9CA:BYTE
EXTRN	D_A9CB:BYTE
EXTRN	D_5394:WORD
EXTRN	D_5396:WORD
EXTRN	D_A9CD:BYTE
EXTRN	D_B11C:WORD
_BSS      ENDS
_DATA      SEGMENT
$SG476	DB	'BRIT.DAT',  00H
$SG481	DB	'UNDER.DAT',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 12
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
; Line 18
	mov	BYTE PTR [bp-8],32	;local_4
; Line 20
	cmp	WORD PTR [bp+4],1	;argc
	jle	$I463
; Line 21
; Line 22
	mov	bx,WORD PTR [bp+6]	;argv
	mov	bx,WORD PTR [bx+2]
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	BYTE PTR [bp-8],al	;local_4
; Line 23
; Line 26
$I463:
	cmp	BYTE PTR [bp-8],67	;local_4
	jne	$L20000
	mov	ax,1
	jmp	SHORT $L20001
$L20000:
	sub	ax,ax
$L20001:
	mov	D_52BA_FORCECGA,ax
; Line 27
	cmp	BYTE PTR [bp-8],72	;local_4
	jne	$L20002
	mov	ax,1
	jmp	SHORT $L20003
$L20002:
	sub	ax,ax
$L20003:
	mov	D_52F3,ax
; Line 28
	cmp	BYTE PTR [bp-8],84	;local_4
	jne	$L20004
	mov	ax,1
	jmp	SHORT $L20005
$L20004:
	sub	ax,ax
$L20005:
	mov	D_52F1_FORCETANDY,ax
; Line 29
	cmp	BYTE PTR [bp-8],69	;local_4
	jne	$L20006
	mov	ax,1
	jmp	SHORT $L20007
$L20006:
	sub	ax,ax
$L20007:
	mov	D_52EF,ax
; Line 32
	mov	WORD PTR D_5394,8994
; Line 33
	mov	WORD PTR D_5396,4096
; Line 35
	mov	WORD PTR D_A9BD,0
; Line 36
	mov	WORD PTR D_A9BE,0
; Line 37
	mov	WORD PTR D_A9C2,1
; Line 39
	call	FUN_1000_16A6_GET_DEFAULT_DRIVE
	mov	D_A9C8,al
	cmp	al,67
	jb	$I464
; Line 40
	mov	BYTE PTR [bp-2],al	;local_6
; Line 41
	jmp	SHORT $I465
$I464:
; Line 42
	mov	BYTE PTR [bp-2],255	;local_6
$I465:
; Line 45
	mov	al,BYTE PTR [bp-2]	;local_6
	mov	D_A9CD,al
; Line 46
	mov	D_A9CA,al
; Line 47
	mov	D_A9C9,al
; Line 49
	mov	BYTE PTR D_A9CB,255
; Line 50
	mov	WORD PTR D_B11C,-19938
; Line 51
	mov	WORD PTR D_538C,1
; Line 53
	call	INTRO_INTRO_MAIN
; Line 54
	call	FUN_1000_2900
; Line 56
	mov	WORD PTR [bp-4],0	;local_8
; Line 59
$D466:
; Line 60
; Line 61
	mov	WORD PTR [bp-6],0	;local_2
; Line 63
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I469
; Line 64
; Line 65
	call	MAINOUT_0D22
; Line 66
	mov	WORD PTR [bp-6],1	;local_2
; Line 67
	mov	WORD PTR [bp-4],0	;local_8
; Line 68
; Line 71
$I469:
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$JCC216
	jmp	$I477
$JCC216:
; Line 72
; Line 74
	cmp	BYTE PTR D_5893_MAP_ID,33
	jae	$I471
; Line 75
; Line 76
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
; Line 77
	call	TOWN_MAIN2_141E_MAINLOOP
; Line 78
	mov	WORD PTR [bp-4],0	;local_8
; Line 79
; Line 80
	jmp	SHORT $I472
$I471:
; Line 81
; Line 83
	mov	ax,2
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 84
	push	WORD PTR [bp-6]	;local_2
	call	DUNGEON_0E2E_MAINLOOP
; Line 85
	mov	WORD PTR [bp-4],1	;local_8
; Line 86
$I472:
; Line 89
	mov	WORD PTR [bp-6],0	;local_2
; Line 90
	mov	ax,1
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 93
$FC474:
	mov	ax,OFFSET DGROUP:$SG476
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC474
; Line 94
	call	OUTSUBS_0368_GETWORLDSAVEFILE
	push	ax
	mov	ax,OFFSET D_5C5A
	push	ax
	mov	ax,256
	push	ax
	sub	ax,ax
	push	ax
	call	FUN_1000_256E_READ_FILE_FROM_DI
; Line 96
	cmp	BYTE PTR D_5893_MAP_ID,0
	jne	$I477
	cmp	BYTE PTR D_5895,0
	je	$I477
; Line 97
; Line 98
	mov	ax,5
	push	ax
	call	FUN_1000_251E_SWITCH_DISKS
; Line 101
$FC479:
	mov	ax,OFFSET DGROUP:$SG481
	push	ax
	call	FUN_1000_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC479
; Line 102
	call	OUTSUBS_0368_GETWORLDSAVEFILE
	push	ax
	mov	ax,OFFSET D_5C5A
	push	ax
	mov	ax,256
	push	ax
	call	FUN_1000_25D8_WRITE_FILE_TO_DIS
; Line 103
; Line 104
$I477:
; Line 106
	cmp	WORD PTR [bp-6],0	;local_2
	jne	$JCC372
	jmp	$D466
$JCC372:
; Line 108
	call	FUN_1000_0878_SET_OLD_VIDEO_MOD
; Line 109
	mov	sp,bp
	pop	bp
	ret	

_F_1000_0000_main	ENDP
; Line 115
	PUBLIC	FUN_1000_017E_ENTRY_POINT
FUN_1000_017E_ENTRY_POINT	PROC NEAR
; Line 125
	push	WORD PTR D_52A6
	push	WORD PTR D_52A4
	push	WORD PTR D_52A2
	call	_F_1000_0000_main
	add	sp,6
	push	ax
	call	_FUN_1000_02F4_exit_to_dos
	add	sp,2
; Line 126
	ret	

FUN_1000_017E_ENTRY_POINT	ENDP
; Line 130
	PUBLIC	FUN_1000_0230
FUN_1000_0230	PROC NEAR
	ret	
	nop	

FUN_1000_0230	ENDP
; Line 134
	PUBLIC	_main
_main	PROC NEAR
	push	bp
	mov	bp,sp
;	argc = 4
;	argv = 6
;	envp = 8
; Line 135
	mov	ax,WORD PTR [bp+8]	;envp
	mov	D_52A6,ax
; Line 136
	mov	ax,WORD PTR [bp+6]	;argv
	mov	D_52A4,ax
; Line 137
	mov	ax,WORD PTR [bp+4]	;argc
	mov	D_52A2,ax
; Line 139
	call	FUN_1000_017E_ENTRY_POINT
; Line 140
	pop	bp
	ret	

_main	ENDP
_TEXT	ENDS
END
