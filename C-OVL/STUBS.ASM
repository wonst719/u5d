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
EXTRN	FILE_READFILE:NEAR
EXTRN	GRAP_PRINTSTRING:NEAR
EXTRN	_exit:NEAR
EXTRN	_printf:NEAR
EXTRN	_puts:NEAR
EXTRN	D_52BA_VDP:BYTE
_BSS      SEGMENT
COMM NEAR	D_535E_TEXTWINDOWS:	BYTE:	 32
_BSS      ENDS
_DATA      SEGMENT
$SG597	DB	'INTRO_intro_main',  00H
$SG599	DB	'MAINOUT_0d22',  00H
$SG602	DB	'TOWN_main1_11f0(%d)',  0aH,  00H
$SG604	DB	'TOWN_main2_141e',  00H
$SG607	DB	'DUNGEON_0e2e(%d)',  0aH,  00H
$SG610	DB	'FUN_1000_02F4_exit_to_dos(%d)',  0aH,  00H
$SG612	DB	'FUN_1000_0878_set_old_video_mode',  00H
$SG618	DB	'FUN_1000_0AA6(%d,%d,%d,%d)',  0aH,  00H
$SG626	DB	'FUN_1000_0ACE(%d,%d,%d,%d,%d)',  0aH,  00H
$SG629	DB	'FUN_1000_0C22(%d)',  0aH,  00H
$SG632	DB	'FUN_1000_0D72(%d)',  0aH,  00H
$SG634	DB	'FUN_1000_0DE0_detect_video',  00H
$SG636	DB	'FUN_1000_0E94_load_video_driver',  00H
$SG638	DB	'FUN_1000_0F2A_init_data_buffer',  00H
$SG642	DB	'FUN_1000_0F6E_image_data_transfer(%d,%d)',  0aH,  00H
$SG645	DB	'FUN_1000_0FAE_load_file(%s)',  0aH,  00H
$SG648	DB	'FUN_1000_0FDC_free_memory(%d)',  0aH,  00H
$SG651	DB	'FUN_1000_0FF4_load_compressed_tileset(%s)',  0aH,  00H
$SG653	DB	'FUN_1000_102E_unload_tileset',  00H
$SG659	DB	'FUN_1000_1044_buffer_image(%d,%d,%d,%d)',  0aH,  00H
$SG661	DB	'FUN_1000_1158_init_timer',  00H
$SG664	DB	'FUN_1000_1674_test_open_file(%s)',  0aH,  00H
$SG666	DB	'FUN_1000_16a6_get_default_drive',  00H
$SG671	DB	'FUN_1000_17f4_character_effects(%d,%d)',  0aH,  00H
$SG678	DB	'FUN_1000_1a3e(%d,%d,%d)',  0aH,  00H
$SG680	DB	'FUN_1000_1B38_keystroke_cursor',  00H
$SG683	DB	'FUN_1000_1c9e_get_char_segment(%d)',  0aH,  00H
$SG687	DB	'FUN_1000_1D02_load_character_set(%s,%d)',  0aH,  00H
$SG689	DB	'FUN_1000_1D5E_peek_keystroke',  00H
$SG692	DB	'FUN_1000_1DDA_wait_for_keystroke(%d)',  0aH,  00H
$SG696	DB	'FUN_1000_2056_get_time',  00H
$SG699	DB	'FUN_1000_207E(%d)',  0aH,  00H
$SG703	DB	'FUN_1000_2092(%d,%d)',  0aH,  00H
$SG706	DB	'FUN_1000_20FA_wait_ticks',  00H
$SG712	DB	'FUN_1000_256e_read_file_from_disk(%s,%d,%d,%d)',  0aH,  00H
$SG717	DB	'FUN_1000_25d8_write_file_to_disk(%s,%d,%d)',  0aH,  00H
$SG720	DB	'FUN_1000_251e_switch_disks(%d)',  0aH,  00H
$SG722	DB	'FUN_1000_266c_get_ch',  00H
$SG724	DB	'FUN_1000_2900',  00H
$SG726	DB	'FUN_1000_2d7a',  00H
$SG729	DB	'FUN_1000_2E96_print_direction(%d)',  0aH,  00H
$SG735	DB	'FUN_1000_43ae(%d,%d,%d,%d)',  0aH,  00H
$SG737	DB	'FUN_1000_4C2A',  00H
$SG739	DB	'FUN_1000_4CCE',  00H
$SG743	DB	'FUN_1000_4d76(ptr,%d)',  00H
$SG745	DB	'FUN_1000_4daa',  00H
$SG748	DB	'FUN_1000_4dea(%d)',  0aH,  00H
$SG750	DB	'FUN_1000_4e20',  00H
$SG753	DB	'FUN_1000_4e50()',  0aH,  00H
$SG755	DB	'FUN_1000_4efc',  00H
$SG757	DB	'FUN_1000_4f3c',  00H
$SG759	DB	'FUN_1000_637E',  00H
$SG763	DB	'FUN_1000_6e60(%d,%d)',  0aH,  00H
$SG765	DB	'FUN_0000_7CCE [thunk]',  00H
$SG767	DB	'FUN_0000_7CDA [thunk]',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 18
	PUBLIC	U5_GETCH
U5_GETCH	PROC NEAR
; Line 19
	call	_getch
	ret	

U5_GETCH	ENDP
; Line 24
	PUBLIC	INTRO_INTRO_MAIN
INTRO_INTRO_MAIN	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG597
	push	ax
	call	_puts
	add	sp,2
	call	F_INTRO_0986
	ret	

INTRO_INTRO_MAIN	ENDP
; Line 27
	PUBLIC	MAINOUT_0D22
MAINOUT_0D22	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG599
	push	ax
	call	_puts
	add	sp,2
	call	F_MAINOUT_0D22
	ret	

MAINOUT_0D22	ENDP
; Line 29
	PUBLIC	TOWN_MAIN1_11F0
TOWN_MAIN1_11F0	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	push	WORD PTR [bp+4]	;x
	mov	ax,OFFSET DGROUP:$SG602
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

TOWN_MAIN1_11F0	ENDP
; Line 30
	PUBLIC	TOWN_MAIN2_141E_MAINLOOP
TOWN_MAIN2_141E_MAINLOOP	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG604
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

TOWN_MAIN2_141E_MAINLOOP	ENDP
; Line 33
	PUBLIC	DUNGEON_0E2E_MAINLOOP
DUNGEON_0E2E_MAINLOOP	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	push	WORD PTR [bp+4]	;x
	mov	ax,OFFSET DGROUP:$SG607
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

DUNGEON_0E2E_MAINLOOP	ENDP
; Line 36
	PUBLIC	_FUN_1000_02F4_exit_to_dos
_FUN_1000_02F4_exit_to_dos	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG610
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
; Line 37
	PUBLIC	FUN_1000_0878_SET_OLD_VIDEO_MOD
FUN_1000_0878_SET_OLD_VIDEO_MOD	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG612
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_0878_SET_OLD_VIDEO_MOD	ENDP
; Line 39
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
	mov	ax,OFFSET DGROUP:$SG618
	push	ax
	call	_printf
	add	sp,10
	pop	bp
	ret	8
	nop	

FUN_1000_0AA6	ENDP
; Line 40
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
	mov	ax,OFFSET DGROUP:$SG626
	push	ax
	call	_printf
	add	sp,12
	pop	bp
	ret	12

FUN_1000_0ACE	ENDP
; Line 41
	PUBLIC	FUN_1000_0C22
FUN_1000_0C22	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG629
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_0C22	ENDP
; Line 42
	PUBLIC	FUN_1000_0D72
FUN_1000_0D72	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG632
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_0D72	ENDP
; Line 43
	PUBLIC	FUN_1000_0DE0_DETECT_VIDEO
FUN_1000_0DE0_DETECT_VIDEO	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG634
	push	ax
	call	_puts
	add	sp,2
	mov	WORD PTR D_52BA_VDP+14,1
	ret	
	nop	

FUN_1000_0DE0_DETECT_VIDEO	ENDP
; Line 44
	PUBLIC	FUN_1000_0E94_LOAD_VIDEO_DRIVER
FUN_1000_0E94_LOAD_VIDEO_DRIVER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG636
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	ret	

FUN_1000_0E94_LOAD_VIDEO_DRIVER	ENDP
; Line 45
	PUBLIC	FUN_1000_0F2A_INIT_DATA_BUFFER
FUN_1000_0F2A_INIT_DATA_BUFFER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG638
	push	ax
	call	_puts
	add	sp,2
	mov	ax,1
	ret	

FUN_1000_0F2A_INIT_DATA_BUFFER	ENDP
; Line 46
	PUBLIC	FUN_1000_0F6E_IMAGE_DATA_TRANSF
FUN_1000_0F6E_IMAGE_DATA_TRANSF	PROC NEAR
	push	bp
	mov	bp,sp
;	b = 4
;	a = 6
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG642
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_0F6E_IMAGE_DATA_TRANSF	ENDP
; Line 48
	PUBLIC	FUN_1000_0FAE_LOAD_FILE
FUN_1000_0FAE_LOAD_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	push	WORD PTR [bp+4]	;file_name
	mov	ax,OFFSET DGROUP:$SG645
	push	ax
	call	_printf
	add	sp,4
	mov	ax,1
	pop	bp
	ret	2
	nop	

FUN_1000_0FAE_LOAD_FILE	ENDP
; Line 50
	PUBLIC	FUN_1000_0FDC_FREE_MEMORY
FUN_1000_0FDC_FREE_MEMORY	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG648
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_0FDC_FREE_MEMORY	ENDP
; Line 51
	PUBLIC	FUN_1000_0FF4_LOAD_COMPRESSED_T
FUN_1000_0FF4_LOAD_COMPRESSED_T	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG651
	push	ax
	call	_printf
	add	sp,4
	mov	ax,1
	pop	bp
	ret	2
	nop	

FUN_1000_0FF4_LOAD_COMPRESSED_T	ENDP
; Line 54
	PUBLIC	FUN_1000_102E_UNLOAD_TILESET
FUN_1000_102E_UNLOAD_TILESET	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG653
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_102E_UNLOAD_TILESET	ENDP
; Line 55
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
	mov	ax,OFFSET DGROUP:$SG659
	push	ax
	call	_printf
	add	sp,10
	pop	bp
	ret	8
	nop	

FUN_1000_1044_BUFFER_IMAGE	ENDP
; Line 56
	PUBLIC	FUN_1000_1158_INIT_TIMER
FUN_1000_1158_INIT_TIMER	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG661
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1158_INIT_TIMER	ENDP
; Line 57
	PUBLIC	FUN_1000_1674_TEST_OPEN_FILE
FUN_1000_1674_TEST_OPEN_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	push	WORD PTR [bp+4]	;file_name
	mov	ax,OFFSET DGROUP:$SG664
	push	ax
	call	_printf
	add	sp,4
	mov	ax,1
	pop	bp
	ret	2
	nop	

FUN_1000_1674_TEST_OPEN_FILE	ENDP
; Line 58
	PUBLIC	FUN_1000_16A6_GET_DEFAULT_DRIVE
FUN_1000_16A6_GET_DEFAULT_DRIVE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG666
	push	ax
	call	_puts
	add	sp,2
	mov	ax,67
	ret	

FUN_1000_16A6_GET_DEFAULT_DRIVE	ENDP
; Line 61
	PUBLIC	FUN_1000_17F4_CHARACTER_EFFECTS
FUN_1000_17F4_CHARACTER_EFFECTS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG671
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_17F4_CHARACTER_EFFECTS	ENDP
; Line 62
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
; Line 63
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
	mov	ax,OFFSET DGROUP:$SG678
	push	ax
	call	_printf
	add	sp,8
	pop	bp
	ret	6

FUN_1000_1A3E	ENDP
; Line 64
	PUBLIC	FUN_1000_1B38_KEYSTROKE_CURSOR
FUN_1000_1B38_KEYSTROKE_CURSOR	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG680
	push	ax
	call	_puts
	add	sp,2
	call	U5_GETCH
	ret	

FUN_1000_1B38_KEYSTROKE_CURSOR	ENDP
; Line 65
	PUBLIC	FUN_1000_1C9E_GET_CHAR_SEGMENT
FUN_1000_1C9E_GET_CHAR_SEGMENT	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG683
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1C9E_GET_CHAR_SEGMENT	ENDP
; Line 66
	PUBLIC	FUN_1000_1D02_LOAD_CHARACTER_SE
FUN_1000_1D02_LOAD_CHARACTER_SE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG687
	push	ax
	call	_printf
	add	sp,6
	mov	ax,1
	pop	bp
	ret	4

FUN_1000_1D02_LOAD_CHARACTER_SE	ENDP
; Line 67
	PUBLIC	FUN_1000_1D5E_PEEK_KEYSTROKE
FUN_1000_1D5E_PEEK_KEYSTROKE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG689
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1D5E_PEEK_KEYSTROKE	ENDP
; Line 68
	PUBLIC	FUN_1000_1DDA_WAIT_FOR_KEYSTROK
FUN_1000_1DDA_WAIT_FOR_KEYSTROK	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG692
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_1DDA_WAIT_FOR_KEYSTROK	ENDP
; Line 71
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
; Line 72
	PUBLIC	FUN_1000_2056_GET_TIME
FUN_1000_2056_GET_TIME	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG696
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2056_GET_TIME	ENDP
; Line 73
	PUBLIC	FUN_1000_207E
FUN_1000_207E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG699
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_207E	ENDP
; Line 74
	PUBLIC	FUN_1000_2092
FUN_1000_2092	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	push	WORD PTR [bp+4]	;b
	push	WORD PTR [bp+6]	;a
	mov	ax,OFFSET DGROUP:$SG703
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_2092	ENDP
; Line 75
	PUBLIC	FUN_1000_20FA_WAIT_TICKS
FUN_1000_20FA_WAIT_TICKS	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG706
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_20FA_WAIT_TICKS	ENDP
; Line 77
	PUBLIC	FUN_1000_256E_READ_FILE_FROM_DI
FUN_1000_256E_READ_FILE_FROM_DI	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 10
;	addr = 8
;	size = 6
;	offset = 4
; Line 78
	push	WORD PTR [bp+4]	;offset
	push	WORD PTR [bp+6]	;size
	push	WORD PTR [bp+8]	;addr
	push	WORD PTR [bp+10]	;file_name
	mov	ax,OFFSET DGROUP:$SG712
	push	ax
	call	_printf
	add	sp,10
; Line 79
	push	WORD PTR [bp+10]	;file_name
	push	WORD PTR [bp+8]	;addr
	push	WORD PTR [bp+6]	;size
	push	WORD PTR [bp+4]	;offset
	call	FILE_READFILE
; Line 80
	pop	bp
	ret	8

FUN_1000_256E_READ_FILE_FROM_DI	ENDP
; Line 81
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
	mov	ax,OFFSET DGROUP:$SG717
	push	ax
	call	_printf
	add	sp,8
	pop	bp
	ret	6

FUN_1000_25D8_WRITE_FILE_TO_DIS	ENDP
; Line 82
	PUBLIC	FUN_1000_251E_SWITCH_DISKS
FUN_1000_251E_SWITCH_DISKS	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	push	WORD PTR [bp+4]	;x
	mov	ax,OFFSET DGROUP:$SG720
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_251E_SWITCH_DISKS	ENDP
; Line 84
	PUBLIC	FUN_1000_266C_GET_CH
FUN_1000_266C_GET_CH	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG722
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_266C_GET_CH	ENDP
; Line 86
	PUBLIC	FUN_1000_2900
FUN_1000_2900	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG724
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2900	ENDP
; Line 88
	PUBLIC	FUN_1000_2D7A
FUN_1000_2D7A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG726
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2D7A	ENDP
; Line 90
	PUBLIC	FUN_1000_2E96_PRINT_DIRECTION
FUN_1000_2E96_PRINT_DIRECTION	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG729
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_2E96_PRINT_DIRECTION	ENDP
; Line 93
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
	mov	ax,OFFSET DGROUP:$SG735
	push	ax
	call	_printf
	add	sp,10
	pop	bp
	ret	8
	nop	

FUN_1000_43AE	ENDP
; Line 94
	PUBLIC	FUN_1000_4C2A
FUN_1000_4C2A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG737
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4C2A	ENDP
; Line 95
	PUBLIC	FUN_1000_4CCE
FUN_1000_4CCE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG739
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4CCE	ENDP
; Line 96
	PUBLIC	FUN_1000_4D76
FUN_1000_4D76	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	al,BYTE PTR [bp+4]	;b
	sub	ah,ah
	push	ax
	mov	ax,OFFSET DGROUP:$SG743
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	4
	nop	

FUN_1000_4D76	ENDP
; Line 97
	PUBLIC	FUN_1000_4DAA
FUN_1000_4DAA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG745
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4DAA	ENDP
; Line 98
	PUBLIC	FUN_1000_4DEA
FUN_1000_4DEA	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	push	WORD PTR [bp+4]	;a
	mov	ax,OFFSET DGROUP:$SG748
	push	ax
	call	_printf
	add	sp,4
	pop	bp
	ret	2

FUN_1000_4DEA	ENDP
; Line 99
	PUBLIC	FUN_1000_4E20
FUN_1000_4E20	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG750
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4E20	ENDP
; Line 100
	PUBLIC	FUN_1000_4E50
FUN_1000_4E50	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG753
	push	ax
	call	_printf
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4E50	ENDP
; Line 101
	PUBLIC	FUN_1000_4EFC
FUN_1000_4EFC	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG755
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4EFC	ENDP
; Line 103
	PUBLIC	FUN_1000_4F3C
FUN_1000_4F3C	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG757
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4F3C	ENDP
; Line 106
	PUBLIC	FUN_1000_637E
FUN_1000_637E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG759
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_637E	ENDP
; Line 107
	PUBLIC	FUN_1000_6E60
FUN_1000_6E60	PROC NEAR
	push	bp
	mov	bp,sp
;	param_2 = 6
;	param_1 = 4
	push	WORD PTR [bp+4]	;param_1
	push	WORD PTR [bp+6]	;param_2
	mov	ax,OFFSET DGROUP:$SG763
	push	ax
	call	_printf
	add	sp,6
	pop	bp
	ret	4
	nop	

FUN_1000_6E60	ENDP
; Line 110
	PUBLIC	FUN_0000_7CCE
FUN_0000_7CCE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG765
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_7CCE	ENDP
; Line 111
	PUBLIC	FUN_0000_7CDA
FUN_0000_7CDA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG767
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_7CDA	ENDP
_TEXT	ENDS
END
