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
EXTRN	_toupper:NEAR
EXTRN	_getch:NEAR
EXTRN	F_INTRO_0986:NEAR
EXTRN	F_MAINOUT_0D22:NEAR
EXTRN	_exit:NEAR
EXTRN	_printf:NEAR
_DATA      SEGMENT
$SG404	DB	'INTRO_intro_main',  00H
$SG407	DB	'MAINOUT_0d22',  00H
$SG411	DB	'TOWN_main1_11f0',  00H
$SG413	DB	'TOWN_main2_141e',  00H
$SG416	DB	'DUNGEON_0e2e',  00H
$SG418	DB	'OUTSUBS_get_world_savefile_0348',  00H
$SG421	DB	'FUN_1000_02F4_exit_to_dos',  00H
$SG423	DB	'FUN_1000_0878_set_old_video_mode',  00H
$SG426	DB	'FUN_1000_0892_initialize_video_driver',  00H
$SG432	DB	'FUN_1000_0AA6',  00H
$SG440	DB	'FUN_1000_0ACE',  00H
$SG443	DB	'FUN_1000_0C22',  00H
$SG446	DB	'FUN_1000_0D72',  00H
$SG448	DB	'FUN_1000_0DE0_detect_video',  00H
$SG450	DB	'FUN_1000_0E94_load_video_driver',  00H
$SG452	DB	'FUN_1000_0F2A_init_data_buffer',  00H
$SG456	DB	'FUN_1000_0F6E_image_data_transfer',  00H
$SG459	DB	'FUN_1000_0FAE_load_file',  00H
$SG462	DB	'FUN_1000_0FDC_free_memory',  00H
$SG465	DB	'FUN_1000_0FF4_load_compressed_tileset',  00H
$SG467	DB	'FUN_1000_102E_unload_tileset',  00H
$SG473	DB	'FUN_1000_1044_buffer_image',  00H
$SG475	DB	'FUN_1000_1158_init_timer',  00H
$SG478	DB	'FUN_1000_1674_test_open_file',  00H
$SG480	DB	'FUN_1000_16a6_get_default_drive',  00H
$SG483	DB	'FUN_1000_16ba_print_char',  00H
$SG486	DB	'FUN_1000_1850_print_string: %s',  0aH,  00H
$SG491	DB	'FUN_1000_1a3e',  00H
$SG493	DB	'FUN_1000_1B38_keystroke_cursor',  00H
$SG496	DB	'FUN_1000_1b94_get_text_effects',  00H
$SG500	DB	'FUN_1000_1bf2_set_text_cursor_position',  00H
$SG507	DB	'FUN_1000_1c22_set_text_window_size',  00H
$SG510	DB	'FUN_1000_1c9e_get_char_segment',  00H
$SG512	DB	'FUN_1000_1cee_get_current_text_row',  00H
$SG516	DB	'FUN_1000_1D02_load_character_set',  00H
$SG518	DB	'FUN_1000_1D5E_peek_keystroke',  00H
$SG521	DB	'FUN_1000_1DDA_wait_for_keystroke',  00H
$SG523	DB	'FUN_1000_1f12_get_current_text_column',  00H
$SG527	DB	'FUN_1000_2056_get_time',  00H
$SG530	DB	'FUN_1000_207E',  00H
$SG534	DB	'FUN_1000_2092',  00H
$SG537	DB	'FUN_1000_20FA_wait_ticks',  00H
$SG543	DB	'FUN_1000_256e_read_file_from_disk',  00H
$SG548	DB	'FUN_1000_25d8_write_file_to_disk',  00H
$SG551	DB	'FUN_1000_251e_switch_disks',  00H
$SG553	DB	'FUN_1000_266c_get_ch',  00H
$SG555	DB	'FUN_1000_2900',  00H
$SG557	DB	'FUN_1000_2d7a',  00H
$SG560	DB	'FUN_1000_2E96_print_direction',  00H
$SG566	DB	'FUN_1000_43ae',  00H
$SG568	DB	'FUN_1000_4C2A',  00H
$SG570	DB	'FUN_1000_4CCE',  00H
$SG574	DB	'FUN_1000_4d76',  00H
$SG576	DB	'FUN_1000_4daa',  00H
$SG579	DB	'FUN_1000_4dea',  00H
$SG581	DB	'FUN_1000_4e20',  00H
$SG584	DB	'FUN_1000_4e50',  00H
$SG586	DB	'FUN_1000_4efc',  00H
$SG588	DB	'FUN_1000_4f3c',  00H
$SG590	DB	'FUN_1000_637E',  00H
$SG594	DB	'FUN_1000_6e60',  00H
$SG596	DB	'FUN_0000_7CCE [thunk]',  00H
$SG598	DB	'FUN_0000_7CDA [thunk]',  00H
$SG600	DB	'FUN_0000_8bca [thunk]',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 9
	PUBLIC	INTRO_INTRO_MAIN
INTRO_INTRO_MAIN	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG404
	push	ax
	call	_puts
	add	sp,2
	call	F_INTRO_0986
	ret	

INTRO_INTRO_MAIN	ENDP
; Line 12
	PUBLIC	MAINOUT_0D22
MAINOUT_0D22	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG407
	push	ax
	call	_puts
	add	sp,2
	call	F_MAINOUT_0D22
	ret	

MAINOUT_0D22	ENDP
; Line 14
	PUBLIC	TOWN_MAIN1_11F0
TOWN_MAIN1_11F0	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG411
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

TOWN_MAIN1_11F0	ENDP
; Line 15
	PUBLIC	TOWN_MAIN2_141E
TOWN_MAIN2_141E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG413
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

TOWN_MAIN2_141E	ENDP
; Line 18
	PUBLIC	DUNGEON_0E2E
DUNGEON_0E2E	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG416
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

DUNGEON_0E2E	ENDP
; Line 20
	PUBLIC	OUTSUBS_GET_WORLD_SAVEFILE_0348
OUTSUBS_GET_WORLD_SAVEFILE_0348	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG418
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

OUTSUBS_GET_WORLD_SAVEFILE_0348	ENDP
; Line 23
	PUBLIC	_FUN_1000_02F4_exit_to_dos
_FUN_1000_02F4_exit_to_dos	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG421
	push	ax
	call	_puts
	add	sp,2
	push	WORD PTR [bp+4]	;a
	call	_exit
	add	sp,2
	pop	bp
	ret	

_FUN_1000_02F4_exit_to_dos	ENDP
; Line 24
	PUBLIC	FUN_1000_0878_SET_OLD_VIDEO_MOD
FUN_1000_0878_SET_OLD_VIDEO_MOD	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG423
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_0878_SET_OLD_VIDEO_MOD	ENDP
; Line 25
	PUBLIC	FUN_1000_0892_INITIALIZE_VIDEO_
FUN_1000_0892_INITIALIZE_VIDEO_	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG426
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_0892_INITIALIZE_VIDEO_	ENDP
; Line 27
	PUBLIC	FUN_1000_0AA6
FUN_1000_0AA6	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	mov	ax,OFFSET DGROUP:$SG432
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_0AA6	ENDP
; Line 28
	PUBLIC	FUN_1000_0ACE
FUN_1000_0ACE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 14
;	b = 12
;	c = 10
;	d = 8
;	e = 6
;	f = 4
	mov	ax,OFFSET DGROUP:$SG440
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	12
	nop	

FUN_1000_0ACE	ENDP
; Line 29
	PUBLIC	FUN_1000_0C22
FUN_1000_0C22	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG443
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_0C22	ENDP
; Line 30
	PUBLIC	FUN_1000_0D72
FUN_1000_0D72	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG446
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_0D72	ENDP
; Line 31
	PUBLIC	FUN_1000_0DE0_DETECT_VIDEO
FUN_1000_0DE0_DETECT_VIDEO	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG448
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_0DE0_DETECT_VIDEO	ENDP
; Line 32
	PUBLIC	FUN_1000_0E94_LOAD_VIDEO_DRIVER
FUN_1000_0E94_LOAD_VIDEO_DRIVER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG450
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	ret	

FUN_1000_0E94_LOAD_VIDEO_DRIVER	ENDP
; Line 33
	PUBLIC	FUN_1000_0F2A_INIT_DATA_BUFFER
FUN_1000_0F2A_INIT_DATA_BUFFER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG452
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	ret	

FUN_1000_0F2A_INIT_DATA_BUFFER	ENDP
; Line 34
	PUBLIC	FUN_1000_0F6E_IMAGE_DATA_TRANSF
FUN_1000_0F6E_IMAGE_DATA_TRANSF	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG456
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_0F6E_IMAGE_DATA_TRANSF	ENDP
; Line 36
	PUBLIC	FUN_1000_0FAE_LOAD_FILE
FUN_1000_0FAE_LOAD_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	mov	ax,OFFSET DGROUP:$SG459
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	pop	bp
	ret	2

FUN_1000_0FAE_LOAD_FILE	ENDP
; Line 38
	PUBLIC	FUN_1000_0FDC_FREE_MEMORY
FUN_1000_0FDC_FREE_MEMORY	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG462
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_0FDC_FREE_MEMORY	ENDP
; Line 39
	PUBLIC	FUN_1000_0FF4_LOAD_COMPRESSED_T
FUN_1000_0FF4_LOAD_COMPRESSED_T	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG465
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	pop	bp
	ret	2

FUN_1000_0FF4_LOAD_COMPRESSED_T	ENDP
; Line 42
	PUBLIC	FUN_1000_102E_UNLOAD_TILESET
FUN_1000_102E_UNLOAD_TILESET	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG467
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_102E_UNLOAD_TILESET	ENDP
; Line 43
	PUBLIC	FUN_1000_1044_BUFFER_IMAGE
FUN_1000_1044_BUFFER_IMAGE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	mov	ax,OFFSET DGROUP:$SG473
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_1044_BUFFER_IMAGE	ENDP
; Line 44
	PUBLIC	FUN_1000_1158_INIT_TIMER
FUN_1000_1158_INIT_TIMER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG475
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1158_INIT_TIMER	ENDP
; Line 45
	PUBLIC	FUN_1000_1674_TEST_OPEN_FILE
FUN_1000_1674_TEST_OPEN_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	mov	ax,OFFSET DGROUP:$SG478
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1674_TEST_OPEN_FILE	ENDP
; Line 46
	PUBLIC	FUN_1000_16A6_GET_DEFAULT_DRIVE
FUN_1000_16A6_GET_DEFAULT_DRIVE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG480
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_16A6_GET_DEFAULT_DRIVE	ENDP
; Line 47
	PUBLIC	FUN_1000_16BA_PRINT_CHAR
FUN_1000_16BA_PRINT_CHAR	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG483
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 48
	PUBLIC	FUN_1000_1850_PRINT_STRING
FUN_1000_1850_PRINT_STRING	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG486
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1850_PRINT_STRING	ENDP
; Line 49
	PUBLIC	FUN_1000_1A3E
FUN_1000_1A3E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 8
;	b = 6
;	c = 4
	mov	ax,OFFSET DGROUP:$SG491
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	6
	nop	

FUN_1000_1A3E	ENDP
; Line 50
	PUBLIC	FUN_1000_1B38_KEYSTROKE_CURSOR
FUN_1000_1B38_KEYSTROKE_CURSOR	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG493
	push	ax
	call	_puts
	add	sp,2
	call	_getch
	ret	

FUN_1000_1B38_KEYSTROKE_CURSOR	ENDP
; Line 51
	PUBLIC	FUN_1000_1B94_GET_TEXT_EFFECTS
FUN_1000_1B94_GET_TEXT_EFFECTS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG496
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1B94_GET_TEXT_EFFECTS	ENDP
; Line 52
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG500
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 53
	PUBLIC	FUN_1000_1C22_SET_TEXT_WINDOW_S
FUN_1000_1C22_SET_TEXT_WINDOW_S	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 12
;	b = 10
;	c = 8
;	d = 6
;	e = 4
	mov	ax,OFFSET DGROUP:$SG507
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	10
	nop	

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 54
	PUBLIC	FUN_1000_1C9E_GET_CHAR_SEGMENT
FUN_1000_1C9E_GET_CHAR_SEGMENT	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG510
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1C9E_GET_CHAR_SEGMENT	ENDP
; Line 55
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG512
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 56
	PUBLIC	FUN_1000_1D02_LOAD_CHARACTER_SE
FUN_1000_1D02_LOAD_CHARACTER_SE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG516
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	pop	bp
	ret	4

FUN_1000_1D02_LOAD_CHARACTER_SE	ENDP
; Line 57
	PUBLIC	FUN_1000_1D5E_PEEK_KEYSTROKE
FUN_1000_1D5E_PEEK_KEYSTROKE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG518
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1D5E_PEEK_KEYSTROKE	ENDP
; Line 58
	PUBLIC	FUN_1000_1DDA_WAIT_FOR_KEYSTROK
FUN_1000_1DDA_WAIT_FOR_KEYSTROK	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG521
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1DDA_WAIT_FOR_KEYSTROK	ENDP
; Line 59
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG523
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 62
	PUBLIC	FUN_1000_2032_TO_UPPER
FUN_1000_2032_TO_UPPER	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	push	WORD PTR [bp+4]	;x
	call	_toupper
	add	sp,2
	pop	bp
	ret	2

FUN_1000_2032_TO_UPPER	ENDP
; Line 63
	PUBLIC	FUN_1000_2056_GET_TIME
FUN_1000_2056_GET_TIME	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG527
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2056_GET_TIME	ENDP
; Line 64
	PUBLIC	FUN_1000_207E
FUN_1000_207E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG530
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_207E	ENDP
; Line 65
	PUBLIC	FUN_1000_2092
FUN_1000_2092	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG534
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_2092	ENDP
; Line 66
	PUBLIC	FUN_1000_20FA_WAIT_TICKS
FUN_1000_20FA_WAIT_TICKS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG537
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_20FA_WAIT_TICKS	ENDP
; Line 67
	PUBLIC	FUN_1000_256E_READ_FILE_FROM_DI
FUN_1000_256E_READ_FILE_FROM_DI	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 10
;	addr = 8
;	size = 6
;	a = 4
	mov	ax,OFFSET DGROUP:$SG543
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_256E_READ_FILE_FROM_DI	ENDP
; Line 68
	PUBLIC	FUN_1000_25D8_WRITE_FILE_TO_DIS
FUN_1000_25D8_WRITE_FILE_TO_DIS	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 8
;	addr = 6
;	size = 4
	mov	ax,OFFSET DGROUP:$SG548
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	6
	nop	

FUN_1000_25D8_WRITE_FILE_TO_DIS	ENDP
; Line 69
	PUBLIC	FUN_1000_251E_SWITCH_DISKS
FUN_1000_251E_SWITCH_DISKS	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG551
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_251E_SWITCH_DISKS	ENDP
; Line 71
	PUBLIC	FUN_1000_266C_GET_CH
FUN_1000_266C_GET_CH	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG553
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_266C_GET_CH	ENDP
; Line 73
	PUBLIC	FUN_1000_2900
FUN_1000_2900	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG555
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2900	ENDP
; Line 75
	PUBLIC	FUN_1000_2D7A
FUN_1000_2D7A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG557
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2D7A	ENDP
; Line 77
	PUBLIC	FUN_1000_2E96_PRINT_DIRECTION
FUN_1000_2E96_PRINT_DIRECTION	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG560
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_2E96_PRINT_DIRECTION	ENDP
; Line 80
	PUBLIC	FUN_1000_43AE
FUN_1000_43AE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	mov	ax,OFFSET DGROUP:$SG566
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_43AE	ENDP
; Line 81
	PUBLIC	FUN_1000_4C2A
FUN_1000_4C2A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG568
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4C2A	ENDP
; Line 82
	PUBLIC	FUN_1000_4CCE
FUN_1000_4CCE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG570
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4CCE	ENDP
; Line 83
	PUBLIC	FUN_1000_4D76
FUN_1000_4D76	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG574
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_4D76	ENDP
; Line 84
	PUBLIC	FUN_1000_4DAA
FUN_1000_4DAA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG576
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4DAA	ENDP
; Line 85
	PUBLIC	FUN_1000_4DEA
FUN_1000_4DEA	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG579
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4DEA	ENDP
; Line 86
	PUBLIC	FUN_1000_4E20
FUN_1000_4E20	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG581
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4E20	ENDP
; Line 87
	PUBLIC	FUN_1000_4E50
FUN_1000_4E50	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG584
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4E50	ENDP
; Line 88
	PUBLIC	FUN_1000_4EFC
FUN_1000_4EFC	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG586
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4EFC	ENDP
; Line 90
	PUBLIC	FUN_1000_4F3C
FUN_1000_4F3C	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG588
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4F3C	ENDP
; Line 93
	PUBLIC	FUN_1000_637E
FUN_1000_637E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG590
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_637E	ENDP
; Line 94
	PUBLIC	FUN_1000_6E60
FUN_1000_6E60	PROC NEAR
	push	bp
	mov	bp,sp
;	param_2 = 6
;	param_1 = 4
	mov	ax,OFFSET DGROUP:$SG594
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_6E60	ENDP
; Line 97
	PUBLIC	FUN_0000_7CCE
FUN_0000_7CCE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG596
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_7CCE	ENDP
; Line 98
	PUBLIC	FUN_0000_7CDA
FUN_0000_7CDA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG598
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_7CDA	ENDP
; Line 99
	PUBLIC	FUN_0000_8BCA
FUN_0000_8BCA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG600
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_8BCA	ENDP
_TEXT	ENDS
END
