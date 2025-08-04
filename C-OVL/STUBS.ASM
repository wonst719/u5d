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
EXTRN	_toupper:NEAR
EXTRN	_getch:NEAR
EXTRN	F_INTRO_0986:NEAR
EXTRN	F_MAINOUT_0D22:NEAR
EXTRN	GRAP_PRINTSTRING:NEAR
EXTRN	_exit:NEAR
EXTRN	_printf:NEAR
EXTRN	_puts:NEAR
_DATA      SEGMENT
$SG403	DB	'INTRO_intro_main',  00H
$SG406	DB	'MAINOUT_0d22',  00H
$SG410	DB	'TOWN_main1_11f0(%d)',  0aH,  00H
$SG412	DB	'TOWN_main2_141e',  00H
$SG415	DB	'DUNGEON_0e2e(%d)',  0aH,  00H
$SG417	DB	'OUTSUBS_get_world_savefile_0348',  00H
$SG420	DB	'FUN_1000_02F4_exit_to_dos(%d)',  0aH,  00H
$SG422	DB	'FUN_1000_0878_set_old_video_mode',  00H
$SG425	DB	'FUN_1000_0892_initialize_video_driver(%d)',  0aH,  00H
$SG431	DB	'FUN_1000_0AA6(%d,%d,%d,%d)',  0aH,  00H
$SG439	DB	'FUN_1000_0ACE(%d,%d,%d,%d,%d)',  0aH,  00H
$SG442	DB	'FUN_1000_0C22(%d)',  0aH,  00H
$SG445	DB	'FUN_1000_0D72(%d)',  0aH,  00H
$SG447	DB	'FUN_1000_0DE0_detect_video',  00H
$SG449	DB	'FUN_1000_0E94_load_video_driver',  00H
$SG451	DB	'FUN_1000_0F2A_init_data_buffer',  00H
$SG455	DB	'FUN_1000_0F6E_image_data_transfer(%d,%d)',  0aH,  00H
$SG458	DB	'FUN_1000_0FAE_load_file(%s)',  0aH,  00H
$SG461	DB	'FUN_1000_0FDC_free_memory(%d)',  0aH,  00H
$SG464	DB	'FUN_1000_0FF4_load_compressed_tileset(%d)',  0aH,  00H
$SG466	DB	'FUN_1000_102E_unload_tileset',  00H
$SG472	DB	'FUN_1000_1044_buffer_image(%d,%d,%d,%d)',  0aH,  00H
$SG474	DB	'FUN_1000_1158_init_timer',  00H
$SG477	DB	'FUN_1000_1674_test_open_file(%s)',  0aH,  00H
$SG479	DB	'FUN_1000_16a6_get_default_drive',  00H
$SG482	DB	'FUN_1000_16ba_print_char(%d)',  0aH,  00H
$SG487	DB	'FUN_1000_17f4_character_effects(%d,%d)',  0aH,  00H
$SG495	DB	'FUN_1000_1a3e(%d,%d,%d)',  0aH,  00H
$SG497	DB	'FUN_1000_1B38_keystroke_cursor',  00H
$SG500	DB	'FUN_1000_1b94_get_text_effects(%d)',  0aH,  00H
$SG504	DB	'FUN_1000_1bf2_set_text_cursor_position(%d,%d)',  0aH,  00H
$SG511	DB	'FUN_1000_1c22_set_text_window_size(%d,%d,%d,%d,%d)',  0aH,  00H
$SG514	DB	'FUN_1000_1c9e_get_char_segment(%d)',  0aH,  00H
$SG516	DB	'FUN_1000_1cee_get_current_text_row',  00H
$SG520	DB	'FUN_1000_1D02_load_character_set(%s,%d)',  0aH,  00H
$SG522	DB	'FUN_1000_1D5E_peek_keystroke',  00H
$SG525	DB	'FUN_1000_1DDA_wait_for_keystroke(%d)',  0aH,  00H
$SG527	DB	'FUN_1000_1f12_get_current_text_column',  00H
$SG531	DB	'FUN_1000_1f77_convert_char_dimensions_to_pixels(ptr)',  00H
$SG535	DB	'FUN_1000_2056_get_time',  00H
$SG538	DB	'FUN_1000_207E(%d)',  0aH,  00H
$SG542	DB	'FUN_1000_2092(%d,%d)',  0aH,  00H
$SG545	DB	'FUN_1000_20FA_wait_ticks',  00H
$SG551	DB	'FUN_1000_256e_read_file_from_disk(%s,%d,%d,%d)',  0aH,  00H
$SG556	DB	'FUN_1000_25d8_write_file_to_disk(%s,%d,%d)',  0aH,  00H
$SG559	DB	'FUN_1000_251e_switch_disks(%d)',  0aH,  00H
$SG561	DB	'FUN_1000_266c_get_ch',  00H
$SG563	DB	'FUN_1000_2900',  00H
$SG565	DB	'FUN_1000_2d7a',  00H
$SG568	DB	'FUN_1000_2E96_print_direction(%d)',  0aH,  00H
$SG574	DB	'FUN_1000_43ae(%d,%d,%d,%d)',  0aH,  00H
$SG576	DB	'FUN_1000_4C2A',  00H
$SG578	DB	'FUN_1000_4CCE',  00H
$SG582	DB	'FUN_1000_4d76(ptr,%d)',  00H
$SG584	DB	'FUN_1000_4daa',  00H
$SG587	DB	'FUN_1000_4dea(%d)',  0aH,  00H
$SG589	DB	'FUN_1000_4e20',  00H
$SG592	DB	'FUN_1000_4e50(%s)',  0aH,  00H
$SG594	DB	'FUN_1000_4efc',  00H
$SG596	DB	'FUN_1000_4f3c',  00H
$SG598	DB	'FUN_1000_637E',  00H
$SG602	DB	'FUN_1000_6e60(%d,%d)',  0aH,  00H
$SG604	DB	'FUN_0000_7CCE [thunk]',  00H
$SG606	DB	'FUN_0000_7CDA [thunk]',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 9
	PUBLIC	INTRO_INTRO_MAIN
INTRO_INTRO_MAIN	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG403
	push	ax
	call	_puts
	add	sp,2
	call	F_INTRO_0986
	ret	

INTRO_INTRO_MAIN	ENDP
; Line 12
	PUBLIC	MAINOUT_0D22
MAINOUT_0D22	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG406
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
	push	WORD PTR [bp+4]	;x
	mov	ax,OFFSET DGROUP:$SG410
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

TOWN_MAIN1_11F0	ENDP
; Line 15
	PUBLIC	TOWN_MAIN2_141E
TOWN_MAIN2_141E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG412
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
	push	WORD PTR [bp+4]	;x
	mov	ax,OFFSET DGROUP:$SG415
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

DUNGEON_0E2E	ENDP
; Line 20
	PUBLIC	OUTSUBS_GET_WORLD_SAVEFILE_0348
OUTSUBS_GET_WORLD_SAVEFILE_0348	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG417
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
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG420
	push	ax
	call	_printf
	add	sp,4
	push	WORD PTR [bp+4]	;a
	call	_exit
	add	sp,2
	pop	bp
	ret	
	nop	

_FUN_1000_02F4_exit_to_dos	ENDP
; Line 24
	PUBLIC	FUN_1000_0878_SET_OLD_VIDEO_MOD
FUN_1000_0878_SET_OLD_VIDEO_MOD	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG422
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
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG425
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

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
	push	WORD PTR [bp+4]	;d
	push	WORD PTR [bp+6]	;c
	push	WORD PTR [bp+8]	;b
	push	WORD PTR [bp+10]	;a
	mov	ax,OFFSET DGROUP:$SG431
	push	ax
	call	_printf
	add	sp,10
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
	push	WORD PTR [bp+6]	;e
	push	WORD PTR [bp+8]	;d
	push	WORD PTR [bp+10]	;c
	push	WORD PTR [bp+12]	;b
	push	WORD PTR [bp+14]	;a
	mov	ax,OFFSET DGROUP:$SG439
	push	ax
	call	_printf
	add	sp,12
	pop	bp
	ret	12

FUN_1000_0ACE	ENDP
; Line 29
	PUBLIC	FUN_1000_0C22
FUN_1000_0C22	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG442
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_0C22	ENDP
; Line 30
	PUBLIC	FUN_1000_0D72
FUN_1000_0D72	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG445
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_0D72	ENDP
; Line 31
	PUBLIC	FUN_1000_0DE0_DETECT_VIDEO
FUN_1000_0DE0_DETECT_VIDEO	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG447
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_0DE0_DETECT_VIDEO	ENDP
; Line 32
	PUBLIC	FUN_1000_0E94_LOAD_VIDEO_DRIVER
FUN_1000_0E94_LOAD_VIDEO_DRIVER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG449
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	ret	

FUN_1000_0E94_LOAD_VIDEO_DRIVER	ENDP
; Line 33
	PUBLIC	FUN_1000_0F2A_INIT_DATA_BUFFER
FUN_1000_0F2A_INIT_DATA_BUFFER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG451
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
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG455
	push	ax
	call	_printf
	add	sp,6
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
	push	WORD PTR [bp+4]	;file_name
	mov	ax,OFFSET DGROUP:$SG458
	push	ax
	call	_printf
	add	sp,4
	mov	ax,1
	pop	bp
	ret	2
	nop	

FUN_1000_0FAE_LOAD_FILE	ENDP
; Line 38
	PUBLIC	FUN_1000_0FDC_FREE_MEMORY
FUN_1000_0FDC_FREE_MEMORY	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG461
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_0FDC_FREE_MEMORY	ENDP
; Line 39
	PUBLIC	FUN_1000_0FF4_LOAD_COMPRESSED_T
FUN_1000_0FF4_LOAD_COMPRESSED_T	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	al,BYTE PTR [bp+4]	;a
	cbw	
	push	ax
	mov	ax,OFFSET DGROUP:$SG464
	push	ax
	call	_printf
	add	sp,4
	mov	ax,1
	pop	bp
	ret	2
	nop	

FUN_1000_0FF4_LOAD_COMPRESSED_T	ENDP
; Line 42
	PUBLIC	FUN_1000_102E_UNLOAD_TILESET
FUN_1000_102E_UNLOAD_TILESET	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG466
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
	push	WORD PTR [bp+4]	;d
	push	WORD PTR [bp+6]	;c
	push	WORD PTR [bp+8]	;b
	push	WORD PTR [bp+10]	;a
	mov	ax,OFFSET DGROUP:$SG472
	push	ax
	call	_printf
	add	sp,10
	pop	bp
	ret	8
	nop	

FUN_1000_1044_BUFFER_IMAGE	ENDP
; Line 44
	PUBLIC	FUN_1000_1158_INIT_TIMER
FUN_1000_1158_INIT_TIMER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG474
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
	push	WORD PTR [bp+4]	;file_name
	mov	ax,OFFSET DGROUP:$SG477
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1674_TEST_OPEN_FILE	ENDP
; Line 46
	PUBLIC	FUN_1000_16A6_GET_DEFAULT_DRIVE
FUN_1000_16A6_GET_DEFAULT_DRIVE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG479
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
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG482
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 50
	PUBLIC	FUN_1000_17F4_CHARACTER_EFFECTS
FUN_1000_17F4_CHARACTER_EFFECTS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG487
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_17F4_CHARACTER_EFFECTS	ENDP
; Line 51
	PUBLIC	FUN_1000_1850_PRINT_STRING
FUN_1000_1850_PRINT_STRING	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	call	GRAP_PRINTSTRING
	pop	bp
	ret	2
	nop	

FUN_1000_1850_PRINT_STRING	ENDP
; Line 52
	PUBLIC	FUN_1000_1A3E
FUN_1000_1A3E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 8
;	b = 6
;	c = 4
	push	WORD PTR [bp+4]	;c
	push	WORD PTR [bp+6]	;b
	push	WORD PTR [bp+8]	;a
	mov	ax,OFFSET DGROUP:$SG495
	push	ax
	call	_printf
	add	sp,8
	pop	bp
	ret	6

FUN_1000_1A3E	ENDP
; Line 53
	PUBLIC	FUN_1000_1B38_KEYSTROKE_CURSOR
FUN_1000_1B38_KEYSTROKE_CURSOR	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG497
	push	ax
	call	_puts
	add	sp,2
	call	_getch
	ret	

FUN_1000_1B38_KEYSTROKE_CURSOR	ENDP
; Line 54
	PUBLIC	FUN_1000_1B94_GET_TEXT_EFFECTS
FUN_1000_1B94_GET_TEXT_EFFECTS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG500
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1B94_GET_TEXT_EFFECTS	ENDP
; Line 55
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG504
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 56
	PUBLIC	FUN_1000_1C22_SET_TEXT_WINDOW_S
FUN_1000_1C22_SET_TEXT_WINDOW_S	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 12
;	b = 10
;	c = 8
;	d = 6
;	e = 4
	push	WORD PTR [bp+4]	;e
	push	WORD PTR [bp+6]	;d
	push	WORD PTR [bp+8]	;c
	push	WORD PTR [bp+10]	;b
	push	WORD PTR [bp+12]	;a
	mov	ax,OFFSET DGROUP:$SG511
	push	ax
	call	_printf
	add	sp,12
	pop	bp
	ret	10

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 57
	PUBLIC	FUN_1000_1C9E_GET_CHAR_SEGMENT
FUN_1000_1C9E_GET_CHAR_SEGMENT	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG514
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1C9E_GET_CHAR_SEGMENT	ENDP
; Line 58
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG516
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 59
	PUBLIC	FUN_1000_1D02_LOAD_CHARACTER_SE
FUN_1000_1D02_LOAD_CHARACTER_SE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG520
	push	ax
	call	_printf
	add	sp,6
	mov	ax,1
	pop	bp
	ret	4

FUN_1000_1D02_LOAD_CHARACTER_SE	ENDP
; Line 60
	PUBLIC	FUN_1000_1D5E_PEEK_KEYSTROKE
FUN_1000_1D5E_PEEK_KEYSTROKE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG522
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1D5E_PEEK_KEYSTROKE	ENDP
; Line 61
	PUBLIC	FUN_1000_1DDA_WAIT_FOR_KEYSTROK
FUN_1000_1DDA_WAIT_FOR_KEYSTROK	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG525
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1DDA_WAIT_FOR_KEYSTROK	ENDP
; Line 62
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG527
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 65
	PUBLIC	FUN_1000_1F77_CONVERT_CHAR_DIME
FUN_1000_1F77_CONVERT_CHAR_DIME	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG531
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1F77_CONVERT_CHAR_DIME	ENDP
; Line 68
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
; Line 69
	PUBLIC	FUN_1000_2056_GET_TIME
FUN_1000_2056_GET_TIME	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG535
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2056_GET_TIME	ENDP
; Line 70
	PUBLIC	FUN_1000_207E
FUN_1000_207E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG538
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_207E	ENDP
; Line 71
	PUBLIC	FUN_1000_2092
FUN_1000_2092	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG542
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_2092	ENDP
; Line 72
	PUBLIC	FUN_1000_20FA_WAIT_TICKS
FUN_1000_20FA_WAIT_TICKS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG545
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_20FA_WAIT_TICKS	ENDP
; Line 73
	PUBLIC	FUN_1000_256E_READ_FILE_FROM_DI
FUN_1000_256E_READ_FILE_FROM_DI	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 10
;	addr = 8
;	size = 6
;	a = 4
	push	WORD PTR [bp+4]	;a
	push	WORD PTR [bp+6]	;size
	push	WORD PTR [bp+8]	;addr
	push	WORD PTR [bp+10]	;file_name
	mov	ax,OFFSET DGROUP:$SG551
	push	ax
	call	_printf
	add	sp,10
	pop	bp
	ret	8
	nop	

FUN_1000_256E_READ_FILE_FROM_DI	ENDP
; Line 74
	PUBLIC	FUN_1000_25D8_WRITE_FILE_TO_DIS
FUN_1000_25D8_WRITE_FILE_TO_DIS	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 8
;	addr = 6
;	size = 4
	push	WORD PTR [bp+4]	;size
	push	WORD PTR [bp+6]	;addr
	push	WORD PTR [bp+8]	;file_name
	mov	ax,OFFSET DGROUP:$SG556
	push	ax
	call	_printf
	add	sp,8
	pop	bp
	ret	6

FUN_1000_25D8_WRITE_FILE_TO_DIS	ENDP
; Line 75
	PUBLIC	FUN_1000_251E_SWITCH_DISKS
FUN_1000_251E_SWITCH_DISKS	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	push	WORD PTR [bp+4]	;x
	mov	ax,OFFSET DGROUP:$SG559
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_251E_SWITCH_DISKS	ENDP
; Line 77
	PUBLIC	FUN_1000_266C_GET_CH
FUN_1000_266C_GET_CH	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG561
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_266C_GET_CH	ENDP
; Line 79
	PUBLIC	FUN_1000_2900
FUN_1000_2900	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG563
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2900	ENDP
; Line 81
	PUBLIC	FUN_1000_2D7A
FUN_1000_2D7A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG565
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2D7A	ENDP
; Line 83
	PUBLIC	FUN_1000_2E96_PRINT_DIRECTION
FUN_1000_2E96_PRINT_DIRECTION	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG568
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_2E96_PRINT_DIRECTION	ENDP
; Line 86
	PUBLIC	FUN_1000_43AE
FUN_1000_43AE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	push	WORD PTR [bp+4]	;d
	push	WORD PTR [bp+6]	;c
	push	WORD PTR [bp+8]	;b
	push	WORD PTR [bp+10]	;a
	mov	ax,OFFSET DGROUP:$SG574
	push	ax
	call	_printf
	add	sp,10
	pop	bp
	ret	8
	nop	

FUN_1000_43AE	ENDP
; Line 87
	PUBLIC	FUN_1000_4C2A
FUN_1000_4C2A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG576
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4C2A	ENDP
; Line 88
	PUBLIC	FUN_1000_4CCE
FUN_1000_4CCE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG578
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4CCE	ENDP
; Line 89
	PUBLIC	FUN_1000_4D76
FUN_1000_4D76	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	al,BYTE PTR [bp+4]	;b
	sub	ah,ah
	push	ax
	mov	ax,OFFSET DGROUP:$SG582
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	4
	nop	

FUN_1000_4D76	ENDP
; Line 90
	PUBLIC	FUN_1000_4DAA
FUN_1000_4DAA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG584
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4DAA	ENDP
; Line 91
	PUBLIC	FUN_1000_4DEA
FUN_1000_4DEA	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG587
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_4DEA	ENDP
; Line 92
	PUBLIC	FUN_1000_4E20
FUN_1000_4E20	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG589
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4E20	ENDP
; Line 93
	PUBLIC	FUN_1000_4E50
FUN_1000_4E50	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG592
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_4E50	ENDP
; Line 94
	PUBLIC	FUN_1000_4EFC
FUN_1000_4EFC	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG594
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4EFC	ENDP
; Line 96
	PUBLIC	FUN_1000_4F3C
FUN_1000_4F3C	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG596
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4F3C	ENDP
; Line 99
	PUBLIC	FUN_1000_637E
FUN_1000_637E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG598
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_637E	ENDP
; Line 100
	PUBLIC	FUN_1000_6E60
FUN_1000_6E60	PROC NEAR
	push	bp
	mov	bp,sp
;	param_2 = 6
;	param_1 = 4
	push	WORD PTR [bp+4]	;param_1
	push	WORD PTR [bp+6]	;param_2
	mov	ax,OFFSET DGROUP:$SG602
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_6E60	ENDP
; Line 103
	PUBLIC	FUN_0000_7CCE
FUN_0000_7CCE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG604
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_7CCE	ENDP
; Line 104
	PUBLIC	FUN_0000_7CDA
FUN_0000_7CDA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG606
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_7CDA	ENDP
_TEXT	ENDS
END
