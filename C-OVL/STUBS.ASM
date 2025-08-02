;	Static Name Aliases
;
	TITLE   stubs.c
	NAME    stubs

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
EXTRN	_puts:NEAR
EXTRN	F_INTRO_0986:NEAR
EXTRN	F_MAINOUT_0D22:NEAR
_DATA      SEGMENT
$SG283	DB	'INTRO_intro_main',  00H
$SG286	DB	'MAINOUT_0d22',  00H
$SG290	DB	'TOWN_main1_11f0',  00H
$SG292	DB	'TOWN_main2_141e',  00H
$SG295	DB	'DUNGEON_0e2e',  00H
$SG297	DB	'OUTSUBS_get_world_savefile_0348',  00H
$SG299	DB	'FUN_1000_0878_set_old_video_mode',  00H
$SG302	DB	'FUN_1000_0FAE_load_file',  00H
$SG305	DB	'FUN_1000_1674_test_open_file',  00H
$SG307	DB	'FUN_1000_16a6_get_default_drive',  00H
$SG310	DB	'FUN_1000_16ba_print_char',  00H
$SG313	DB	'FUN_1000_1850_print_string',  00H
$SG318	DB	'FUN_1000_1a3e',  00H
$SG321	DB	'FUN_1000_1b94_get_text_effects',  00H
$SG325	DB	'FUN_1000_1bf2_set_text_cursor_position',  00H
$SG332	DB	'FUN_1000_1c22_set_text_window_size',  00H
$SG335	DB	'FUN_1000_1c9e_get_char_segment',  00H
$SG337	DB	'FUN_1000_1cee_get_current_text_row',  00H
$SG339	DB	'FUN_1000_1f12_get_current_text_column',  00H
$SG342	DB	'FUN_1000_2032_to_upper',  00H
$SG346	DB	'FUN_1000_2092',  00H
$SG352	DB	'FUN_1000_256e_read_file_from_disk',  00H
$SG357	DB	'FUN_1000_25d8_write_file_to_disk',  00H
$SG360	DB	'FUN_1000_251e_switch_disks',  00H
$SG362	DB	'FUN_1000_266c_get_ch',  00H
$SG364	DB	'FUN_1000_2900',  00H
$SG366	DB	00H
$SG372	DB	'FUN_1000_43ae',  00H
$SG376	DB	'FUN_1000_4d76',  00H
$SG378	DB	'FUN_1000_4daa',  00H
$SG381	DB	'FUN_1000_4dea',  00H
$SG383	DB	'FUN_1000_4e20',  00H
$SG386	DB	'FUN_1000_4e50',  00H
$SG388	DB	'FUN_1000_4efc',  00H
$SG390	DB	'FUN_1000_4f3c',  00H
$SG394	DB	'FUN_1000_6e60',  00H
$SG396	DB	'FUN_0000_8bca',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 7
	PUBLIC	INTRO_INTRO_MAIN
INTRO_INTRO_MAIN	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG283
	push	ax
	call	_puts
	add	sp,2
	call	F_INTRO_0986
	ret	

INTRO_INTRO_MAIN	ENDP
; Line 10
	PUBLIC	MAINOUT_0D22
MAINOUT_0D22	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG286
	push	ax
	call	_puts
	add	sp,2
	call	F_MAINOUT_0D22
	ret	

MAINOUT_0D22	ENDP
; Line 12
	PUBLIC	TOWN_MAIN1_11F0
TOWN_MAIN1_11F0	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG290
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

TOWN_MAIN1_11F0	ENDP
; Line 13
	PUBLIC	TOWN_MAIN2_141E
TOWN_MAIN2_141E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG292
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

TOWN_MAIN2_141E	ENDP
; Line 16
	PUBLIC	DUNGEON_0E2E
DUNGEON_0E2E	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG295
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

DUNGEON_0E2E	ENDP
; Line 18
	PUBLIC	OUTSUBS_GET_WORLD_SAVEFILE_0348
OUTSUBS_GET_WORLD_SAVEFILE_0348	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG297
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

OUTSUBS_GET_WORLD_SAVEFILE_0348	ENDP
; Line 21
	PUBLIC	FUN_1000_0878_SET_OLD_VIDEO_MOD
FUN_1000_0878_SET_OLD_VIDEO_MOD	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG299
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_0878_SET_OLD_VIDEO_MOD	ENDP
; Line 23
	PUBLIC	FUN_1000_0FAE_LOAD_FILE
FUN_1000_0FAE_LOAD_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	mov	ax,OFFSET DGROUP:$SG302
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_0FAE_LOAD_FILE	ENDP
; Line 26
	PUBLIC	FUN_1000_1674_TEST_OPEN_FILE
FUN_1000_1674_TEST_OPEN_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	mov	ax,OFFSET DGROUP:$SG305
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1674_TEST_OPEN_FILE	ENDP
; Line 27
	PUBLIC	FUN_1000_16A6_GET_DEFAULT_DRIVE
FUN_1000_16A6_GET_DEFAULT_DRIVE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG307
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_16A6_GET_DEFAULT_DRIVE	ENDP
; Line 28
	PUBLIC	FUN_1000_16BA_PRINT_CHAR
FUN_1000_16BA_PRINT_CHAR	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG310
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 29
	PUBLIC	FUN_1000_1850_PRINT_STRING
FUN_1000_1850_PRINT_STRING	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG313
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1850_PRINT_STRING	ENDP
; Line 30
	PUBLIC	FUN_1000_1A3E
FUN_1000_1A3E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 8
;	b = 6
;	c = 4
	mov	ax,OFFSET DGROUP:$SG318
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	6
	nop	

FUN_1000_1A3E	ENDP
; Line 31
	PUBLIC	FUN_1000_1B94_GET_TEXT_EFFECTS
FUN_1000_1B94_GET_TEXT_EFFECTS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG321
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1B94_GET_TEXT_EFFECTS	ENDP
; Line 32
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG325
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 33
	PUBLIC	FUN_1000_1C22_SET_TEXT_WINDOW_S
FUN_1000_1C22_SET_TEXT_WINDOW_S	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 12
;	b = 10
;	c = 8
;	d = 6
;	e = 4
	mov	ax,OFFSET DGROUP:$SG332
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	10
	nop	

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 34
	PUBLIC	FUN_1000_1C9E_GET_CHAR_SEGMENT
FUN_1000_1C9E_GET_CHAR_SEGMENT	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG335
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1C9E_GET_CHAR_SEGMENT	ENDP
; Line 35
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG337
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 36
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG339
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 39
	PUBLIC	FUN_1000_2032_TO_UPPER
FUN_1000_2032_TO_UPPER	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG342
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_2032_TO_UPPER	ENDP
; Line 40
	PUBLIC	FUN_1000_2092
FUN_1000_2092	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG346
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_2092	ENDP
; Line 41
	PUBLIC	FUN_1000_256E_READ_FILE_FROM_DI
FUN_1000_256E_READ_FILE_FROM_DI	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 10
;	addr = 8
;	size = 6
;	a = 4
	mov	ax,OFFSET DGROUP:$SG352
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_256E_READ_FILE_FROM_DI	ENDP
; Line 42
	PUBLIC	FUN_1000_25D8_WRITE_FILE_TO_DIS
FUN_1000_25D8_WRITE_FILE_TO_DIS	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 8
;	addr = 6
;	size = 4
	mov	ax,OFFSET DGROUP:$SG357
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	6
	nop	

FUN_1000_25D8_WRITE_FILE_TO_DIS	ENDP
; Line 43
	PUBLIC	FUN_1000_251E_SWITCH_DISKS
FUN_1000_251E_SWITCH_DISKS	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG360
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_251E_SWITCH_DISKS	ENDP
; Line 45
	PUBLIC	FUN_1000_266C_GET_CH
FUN_1000_266C_GET_CH	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG362
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_266C_GET_CH	ENDP
; Line 47
	PUBLIC	FUN_1000_2900
FUN_1000_2900	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG364
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2900	ENDP
; Line 49
	PUBLIC	FUN_1000_2D7A
FUN_1000_2D7A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG366
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2D7A	ENDP
; Line 52
	PUBLIC	FUN_1000_43AE
FUN_1000_43AE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	mov	ax,OFFSET DGROUP:$SG372
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_43AE	ENDP
; Line 53
	PUBLIC	FUN_1000_4D76
FUN_1000_4D76	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG376
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_4D76	ENDP
; Line 54
	PUBLIC	FUN_1000_4DAA
FUN_1000_4DAA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG378
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4DAA	ENDP
; Line 55
	PUBLIC	FUN_1000_4DEA
FUN_1000_4DEA	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG381
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4DEA	ENDP
; Line 56
	PUBLIC	FUN_1000_4E20
FUN_1000_4E20	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG383
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4E20	ENDP
; Line 57
	PUBLIC	FUN_1000_4E50
FUN_1000_4E50	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG386
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4E50	ENDP
; Line 58
	PUBLIC	FUN_1000_4EFC
FUN_1000_4EFC	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG388
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4EFC	ENDP
; Line 60
	PUBLIC	FUN_1000_4F3C
FUN_1000_4F3C	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG390
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4F3C	ENDP
; Line 63
	PUBLIC	FUN_1000_6E60
FUN_1000_6E60	PROC NEAR
	push	bp
	mov	bp,sp
;	param_2 = 6
;	param_1 = 4
	mov	ax,OFFSET DGROUP:$SG394
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_6E60	ENDP
; Line 66
	PUBLIC	FUN_0000_8BCA
FUN_0000_8BCA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG396
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_8BCA	ENDP
_TEXT	ENDS
END
