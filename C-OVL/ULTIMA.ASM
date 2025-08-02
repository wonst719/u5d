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
EXTRN	EXIT:NEAR
EXTRN	D_52A6:WORD
EXTRN	D_52A4:WORD
EXTRN	D_52A2:WORD
EXTRN	D_52BA:WORD
EXTRN	D_52EF:WORD
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
_DATA      SEGMENT
$SG220	DB	'BRIT.DAT',  00H
$SG225	DB	'UNDER.DAT',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 4
	PUBLIC	FUN_1000_2032_TO_UPPER
FUN_1000_2032_TO_UPPER	PROC NEAR
	push	bp
;	x = 4
	pop	bp
	ret	2
	nop	

FUN_1000_2032_TO_UPPER	ENDP
; Line 6
	PUBLIC	FUN_1000_16A6_GET_DEFAULT_DRIVE
FUN_1000_16A6_GET_DEFAULT_DRIVE	PROC NEAR
	ret	
	nop	

FUN_1000_16A6_GET_DEFAULT_DRIVE	ENDP
; Line 8
	PUBLIC	INTRO_INTRO_MAIN
INTRO_INTRO_MAIN	PROC NEAR
	ret	
	nop	

INTRO_INTRO_MAIN	ENDP
; Line 10
	PUBLIC	MAINOUT_0D22
MAINOUT_0D22	PROC NEAR
	ret	
	nop	

MAINOUT_0D22	ENDP
; Line 12
	PUBLIC	TOWN_MAIN1_11F0
TOWN_MAIN1_11F0	PROC NEAR
	push	bp
;	x = 4
	pop	bp
	ret	2
	nop	

TOWN_MAIN1_11F0	ENDP
; Line 13
	PUBLIC	TOWN_MAIN2_141E
TOWN_MAIN2_141E	PROC NEAR
	ret	
	nop	

TOWN_MAIN2_141E	ENDP
; Line 15
	PUBLIC	DUNGEON_0E2E
DUNGEON_0E2E	PROC NEAR
	push	bp
;	x = 4
	pop	bp
	ret	2
	nop	

DUNGEON_0E2E	ENDP
; Line 17
	PUBLIC	OUTSUBS_GET_WORLD_SAVEFILE_0348
OUTSUBS_GET_WORLD_SAVEFILE_0348	PROC NEAR
	ret	
	nop	

OUTSUBS_GET_WORLD_SAVEFILE_0348	ENDP
; Line 19
	PUBLIC	FUN_1000_2900_UPDATE_VITALS
FUN_1000_2900_UPDATE_VITALS	PROC NEAR
	ret	
	nop	

FUN_1000_2900_UPDATE_VITALS	ENDP
; Line 20
	PUBLIC	SUB_828E_251E_SWITCH_DISKS
SUB_828E_251E_SWITCH_DISKS	PROC NEAR
	push	bp
;	x = 4
	pop	bp
	ret	2
	nop	

SUB_828E_251E_SWITCH_DISKS	ENDP
; Line 22
	PUBLIC	SUB_73E4_1674_TEST_OPEN_FILE
SUB_73E4_1674_TEST_OPEN_FILE	PROC NEAR
	push	bp
;	file_name = 4
	pop	bp
	ret	2
	nop	

SUB_73E4_1674_TEST_OPEN_FILE	ENDP
; Line 23
	PUBLIC	SUB_82DE_256E_READ_FILE_FROM_DI
SUB_82DE_256E_READ_FILE_FROM_DI	PROC NEAR
	push	bp
;	file_name = 10
;	addr = 8
;	size = 6
;	a = 4
	pop	bp
	ret	8
	nop	

SUB_82DE_256E_READ_FILE_FROM_DI	ENDP
; Line 24
	PUBLIC	SUB_8348_25D8_WRITE_FILE_TO_DIS
SUB_8348_25D8_WRITE_FILE_TO_DIS	PROC NEAR
	push	bp
;	addr = 6
;	size = 4
;	file_name = 8
	pop	bp
	ret	6
	nop	

SUB_8348_25D8_WRITE_FILE_TO_DIS	ENDP
; Line 26
	PUBLIC	FUN_1000_0878_SET_OLD_VIDEO_MOD
FUN_1000_0878_SET_OLD_VIDEO_MOD	PROC NEAR
	ret	
	nop	

FUN_1000_0878_SET_OLD_VIDEO_MOD	ENDP
; Line 34
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
; Line 40
	mov	BYTE PTR [bp-8],32	;local_4
; Line 42
	cmp	WORD PTR [bp+4],1	;argc
	jle	$I207
; Line 43
; Line 44
	mov	bx,WORD PTR [bp+6]	;argv
	mov	bx,WORD PTR [bx+2]
	mov	al,BYTE PTR [bx]
	sub	ah,ah
	push	ax
	call	FUN_1000_2032_TO_UPPER
	mov	BYTE PTR [bp-8],al	;local_4
; Line 45
; Line 48
$I207:
	cmp	BYTE PTR [bp-8],67	;local_4
	jne	$L20000
	mov	ax,1
	jmp	SHORT $L20001
$L20000:
	sub	ax,ax
$L20001:
	mov	D_52BA,ax
; Line 49
	cmp	BYTE PTR [bp-8],72	;local_4
	jne	$L20002
	mov	ax,1
	jmp	SHORT $L20003
$L20002:
	sub	ax,ax
$L20003:
	mov	D_52F3,ax
; Line 50
	cmp	BYTE PTR [bp-8],84	;local_4
	jne	$L20004
	mov	ax,1
	jmp	SHORT $L20005
$L20004:
	sub	ax,ax
$L20005:
	mov	D_52F1,ax
; Line 51
	cmp	BYTE PTR [bp-8],69	;local_4
	jne	$L20006
	mov	ax,1
	jmp	SHORT $L20007
$L20006:
	sub	ax,ax
$L20007:
	mov	D_52EF,ax
; Line 54
	mov	WORD PTR D_5394,8994
; Line 55
	mov	WORD PTR D_5396,4096
; Line 57
	mov	WORD PTR D_A9BD,0
; Line 58
	mov	WORD PTR D_A9BE,0
; Line 59
	mov	WORD PTR D_A9C2,1
; Line 61
	call	FUN_1000_16A6_GET_DEFAULT_DRIVE
	mov	D_A9C8,al
	cmp	al,67
	jb	$I208
; Line 62
	mov	BYTE PTR [bp-2],al	;local_6
; Line 63
	jmp	SHORT $I209
$I208:
; Line 64
	mov	BYTE PTR [bp-2],255	;local_6
$I209:
; Line 67
	mov	al,BYTE PTR [bp-2]	;local_6
	mov	D_A9CD,al
; Line 68
	mov	D_A9CA,al
; Line 69
	mov	D_A9C9,al
; Line 71
	mov	BYTE PTR D_A9CB,255
; Line 72
	mov	WORD PTR D_B11C,-19938
; Line 73
	mov	WORD PTR D_538C,1
; Line 75
	call	INTRO_INTRO_MAIN
; Line 76
	call	FUN_1000_2900_UPDATE_VITALS
; Line 78
	mov	WORD PTR [bp-4],0	;local_8
; Line 81
$D210:
; Line 82
; Line 83
	mov	WORD PTR [bp-6],0	;local_2
; Line 85
	cmp	BYTE PTR D_5893,0
	jne	$I213
; Line 86
; Line 87
	call	MAINOUT_0D22
; Line 88
	mov	WORD PTR [bp-6],1	;local_2
; Line 89
	mov	WORD PTR [bp-4],0	;local_8
; Line 90
; Line 93
$I213:
	cmp	BYTE PTR D_5893,0
	jne	$JCC272
	jmp	$I221
$JCC272:
; Line 94
; Line 96
	cmp	BYTE PTR D_5893,33
	jae	$I215
; Line 97
; Line 98
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
; Line 99
	call	TOWN_MAIN2_141E
; Line 100
	mov	WORD PTR [bp-4],0	;local_8
; Line 101
; Line 102
	jmp	SHORT $I216
$I215:
; Line 103
; Line 105
	mov	ax,2
	push	ax
	call	SUB_828E_251E_SWITCH_DISKS
; Line 106
	push	WORD PTR [bp-6]	;local_2
	call	DUNGEON_0E2E
; Line 107
	mov	WORD PTR [bp-4],1	;local_8
; Line 108
$I216:
; Line 111
	mov	WORD PTR [bp-6],0	;local_2
; Line 112
	mov	ax,1
	push	ax
	call	SUB_828E_251E_SWITCH_DISKS
; Line 115
$FC218:
	mov	ax,OFFSET DGROUP:$SG220
	push	ax
	call	SUB_73E4_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC218
; Line 116
	call	OUTSUBS_GET_WORLD_SAVEFILE_0348
	push	ax
	mov	ax,23642
	push	ax
	mov	ax,256
	push	ax
	sub	ax,ax
	push	ax
	call	SUB_82DE_256E_READ_FILE_FROM_DI
; Line 118
	cmp	BYTE PTR D_5893,0
	jne	$I221
	cmp	BYTE PTR D_5895,0
	je	$I221
; Line 119
; Line 120
	mov	ax,5
	push	ax
	call	SUB_828E_251E_SWITCH_DISKS
; Line 123
$FC223:
	mov	ax,OFFSET DGROUP:$SG225
	push	ax
	call	SUB_73E4_1674_TEST_OPEN_FILE
	or	ax,ax
	je	$FC223
; Line 124
	call	OUTSUBS_GET_WORLD_SAVEFILE_0348
	push	ax
	mov	ax,23642
	push	ax
	mov	ax,256
	push	ax
	call	SUB_8348_25D8_WRITE_FILE_TO_DIS
; Line 125
; Line 126
$I221:
; Line 128
	cmp	WORD PTR [bp-6],0	;local_2
	jne	$JCC428
	jmp	$D210
$JCC428:
; Line 130
	call	FUN_1000_0878_SET_OLD_VIDEO_MOD
; Line 131
	mov	sp,bp
	pop	bp
	ret	

_F_1000_0000_main	ENDP
; Line 137
	PUBLIC	FUN_1000_017E_ENTRY_POINT
FUN_1000_017E_ENTRY_POINT	PROC NEAR
; Line 147
	push	WORD PTR D_52A6
	push	WORD PTR D_52A4
	push	WORD PTR D_52A2
	call	_F_1000_0000_main
	add	sp,6
	push	ax
	call	FUN_1000_02F4_EXIT_TO_DOS
; Line 148
	ret	
	nop	

FUN_1000_017E_ENTRY_POINT	ENDP
; Line 152
	PUBLIC	FUN_1000_0230
FUN_1000_0230	PROC NEAR
	ret	
	nop	

FUN_1000_0230	ENDP
; Line 156
	PUBLIC	FUN_1000_02F4_EXIT_TO_DOS
FUN_1000_02F4_EXIT_TO_DOS	PROC NEAR
	push	bp
	mov	bp,sp
;	return_code = 4
; Line 157
	push	WORD PTR [bp+4]	;return_code
	call	EXIT
; Line 158
	pop	bp
	ret	2
	nop	

FUN_1000_02F4_EXIT_TO_DOS	ENDP
; Line 162
	PUBLIC	_main
_main	PROC NEAR
	push	bp
	mov	bp,sp
;	argc = 4
;	argv = 6
;	envp = 8
; Line 163
	mov	ax,WORD PTR [bp+8]	;envp
	mov	D_52A6,ax
; Line 164
	mov	ax,WORD PTR [bp+6]	;argv
	mov	D_52A4,ax
; Line 165
	mov	ax,WORD PTR [bp+4]	;argc
	mov	D_52A2,ax
; Line 167
	call	FUN_1000_017E_ENTRY_POINT
; Line 168
	pop	bp
	ret	

_main	ENDP
_TEXT	ENDS
END
