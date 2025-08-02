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
_DATA      SEGMENT
$SG280	DB	'INTRO_intro_main',  00H
$SG282	DB	'MAINOUT_0d22',  00H
$SG285	DB	'TOWN_main1_11f0',  00H
$SG287	DB	'TOWN_main2_141e',  00H
$SG290	DB	'DUNGEON_0e2e',  00H
$SG292	DB	'OUTSUBS_get_world_savefile_0348',  00H
$SG294	DB	'FUN_1000_0878_set_old_video_mode',  00H
$SG297	DB	'FUN_1000_1674_test_open_file',  00H
$SG299	DB	'FUN_1000_16a6_get_default_drive',  00H
$SG302	DB	'FUN_1000_16ba_print_char',  00H
$SG305	DB	'FUN_1000_1850_print_string',  00H
$SG310	DB	'FUN_1000_1a3e',  00H
$SG313	DB	'FUN_1000_1b94_get_text_effects',  00H
$SG317	DB	'FUN_1000_1bf2_set_text_cursor_position',  00H
$SG324	DB	'FUN_1000_1c22_set_text_window_size',  00H
$SG327	DB	'FUN_1000_1c9e_get_char_segment',  00H
$SG329	DB	'FUN_1000_1cee_get_current_text_row',  00H
$SG331	DB	'FUN_1000_1f12_get_current_text_column',  00H
$SG334	DB	'FUN_1000_2032_to_upper',  00H
$SG338	DB	'FUN_1000_2092',  00H
$SG344	DB	'FUN_1000_256e_read_file_from_disk',  00H
$SG349	DB	'FUN_1000_25d8_write_file_to_disk',  00H
$SG352	DB	'FUN_1000_251e_switch_disks',  00H
$SG354	DB	'FUN_1000_266c_get_ch',  00H
$SG356	DB	'FUN_1000_2900',  00H
$SG358	DB	00H
$SG364	DB	'FUN_1000_43ae',  00H
$SG368	DB	'FUN_1000_4d76',  00H
$SG370	DB	'FUN_1000_4daa',  00H
$SG373	DB	'FUN_1000_4dea',  00H
$SG375	DB	'FUN_1000_4e20',  00H
$SG378	DB	'FUN_1000_4e50',  00H
$SG380	DB	'FUN_1000_4efc',  00H
$SG382	DB	'FUN_1000_4f3c',  00H
$SG386	DB	'FUN_1000_6e60',  00H
$SG388	DB	'FUN_0000_8bca',  00H
_DATA      ENDS
_TEXT      SEGMENT
	ASSUME	CS: _TEXT
; Line 6
	PUBLIC	INTRO_INTRO_MAIN
INTRO_INTRO_MAIN	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG280
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

INTRO_INTRO_MAIN	ENDP
; Line 8
	PUBLIC	MAINOUT_0D22
MAINOUT_0D22	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG282
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

MAINOUT_0D22	ENDP
; Line 10
	PUBLIC	TOWN_MAIN1_11F0
TOWN_MAIN1_11F0	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG285
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

TOWN_MAIN1_11F0	ENDP
; Line 11
	PUBLIC	TOWN_MAIN2_141E
TOWN_MAIN2_141E	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG287
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

TOWN_MAIN2_141E	ENDP
; Line 13
	PUBLIC	DUNGEON_0E2E
DUNGEON_0E2E	PROC NEAR
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

DUNGEON_0E2E	ENDP
; Line 15
	PUBLIC	OUTSUBS_GET_WORLD_SAVEFILE_0348
OUTSUBS_GET_WORLD_SAVEFILE_0348	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG292
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

OUTSUBS_GET_WORLD_SAVEFILE_0348	ENDP
; Line 18
	PUBLIC	FUN_1000_0878_SET_OLD_VIDEO_MOD
FUN_1000_0878_SET_OLD_VIDEO_MOD	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG294
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_0878_SET_OLD_VIDEO_MOD	ENDP
; Line 21
	PUBLIC	FUN_1000_1674_TEST_OPEN_FILE
FUN_1000_1674_TEST_OPEN_FILE	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 4
	mov	ax,OFFSET DGROUP:$SG297
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1674_TEST_OPEN_FILE	ENDP
; Line 22
	PUBLIC	FUN_1000_16A6_GET_DEFAULT_DRIVE
FUN_1000_16A6_GET_DEFAULT_DRIVE	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG299
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_16A6_GET_DEFAULT_DRIVE	ENDP
; Line 23
	PUBLIC	FUN_1000_16BA_PRINT_CHAR
FUN_1000_16BA_PRINT_CHAR	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG302
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_16BA_PRINT_CHAR	ENDP
; Line 24
	PUBLIC	FUN_1000_1850_PRINT_STRING
FUN_1000_1850_PRINT_STRING	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG305
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1850_PRINT_STRING	ENDP
; Line 25
	PUBLIC	FUN_1000_1A3E
FUN_1000_1A3E	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 8
;	b = 6
;	c = 4
	mov	ax,OFFSET DGROUP:$SG310
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	6
	nop	

FUN_1000_1A3E	ENDP
; Line 26
	PUBLIC	FUN_1000_1B94_GET_TEXT_EFFECTS
FUN_1000_1B94_GET_TEXT_EFFECTS	PROC NEAR
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

FUN_1000_1B94_GET_TEXT_EFFECTS	ENDP
; Line 27
	PUBLIC	FUN_1000_1BF2_SET_TEXT_CURSOR_P
FUN_1000_1BF2_SET_TEXT_CURSOR_P	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG317
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_1BF2_SET_TEXT_CURSOR_P	ENDP
; Line 28
	PUBLIC	FUN_1000_1C22_SET_TEXT_WINDOW_S
FUN_1000_1C22_SET_TEXT_WINDOW_S	PROC NEAR
	push	bp
	mov	bp,sp
;	c = 8
;	d = 6
;	e = 4
;	a = 12
;	b = 10
	mov	ax,OFFSET DGROUP:$SG324
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	10
	nop	

FUN_1000_1C22_SET_TEXT_WINDOW_S	ENDP
; Line 29
	PUBLIC	FUN_1000_1C9E_GET_CHAR_SEGMENT
FUN_1000_1C9E_GET_CHAR_SEGMENT	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG327
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_1C9E_GET_CHAR_SEGMENT	ENDP
; Line 30
	PUBLIC	FUN_1000_1CEE_GET_CURRENT_TEXT_
FUN_1000_1CEE_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG329
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1CEE_GET_CURRENT_TEXT_	ENDP
; Line 31
	PUBLIC	FUN_1000_1F12_GET_CURRENT_TEXT_
FUN_1000_1F12_GET_CURRENT_TEXT_	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG331
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_1F12_GET_CURRENT_TEXT_	ENDP
; Line 34
	PUBLIC	FUN_1000_2032_TO_UPPER
FUN_1000_2032_TO_UPPER	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG334
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_2032_TO_UPPER	ENDP
; Line 35
	PUBLIC	FUN_1000_2092
FUN_1000_2092	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG338
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_2092	ENDP
; Line 36
	PUBLIC	FUN_1000_256E_READ_FILE_FROM_DI
FUN_1000_256E_READ_FILE_FROM_DI	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 10
;	addr = 8
;	size = 6
;	a = 4
	mov	ax,OFFSET DGROUP:$SG344
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_256E_READ_FILE_FROM_DI	ENDP
; Line 37
	PUBLIC	FUN_1000_25D8_WRITE_FILE_TO_DIS
FUN_1000_25D8_WRITE_FILE_TO_DIS	PROC NEAR
	push	bp
	mov	bp,sp
;	file_name = 8
;	addr = 6
;	size = 4
	mov	ax,OFFSET DGROUP:$SG349
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	6
	nop	

FUN_1000_25D8_WRITE_FILE_TO_DIS	ENDP
; Line 38
	PUBLIC	FUN_1000_251E_SWITCH_DISKS
FUN_1000_251E_SWITCH_DISKS	PROC NEAR
	push	bp
	mov	bp,sp
;	x = 4
	mov	ax,OFFSET DGROUP:$SG352
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_251E_SWITCH_DISKS	ENDP
; Line 40
	PUBLIC	FUN_1000_266C_GET_CH
FUN_1000_266C_GET_CH	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG354
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_266C_GET_CH	ENDP
; Line 42
	PUBLIC	FUN_1000_2900
FUN_1000_2900	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG356
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2900	ENDP
; Line 44
	PUBLIC	FUN_1000_2D7A
FUN_1000_2D7A	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG358
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_2D7A	ENDP
; Line 47
	PUBLIC	FUN_1000_43AE
FUN_1000_43AE	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 10
;	b = 8
;	c = 6
;	d = 4
	mov	ax,OFFSET DGROUP:$SG364
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	8
	nop	

FUN_1000_43AE	ENDP
; Line 48
	PUBLIC	FUN_1000_4D76
FUN_1000_4D76	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 6
;	b = 4
	mov	ax,OFFSET DGROUP:$SG368
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_4D76	ENDP
; Line 49
	PUBLIC	FUN_1000_4DAA
FUN_1000_4DAA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG370
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4DAA	ENDP
; Line 50
	PUBLIC	FUN_1000_4DEA
FUN_1000_4DEA	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG373
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4DEA	ENDP
; Line 51
	PUBLIC	FUN_1000_4E20
FUN_1000_4E20	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG375
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4E20	ENDP
; Line 52
	PUBLIC	FUN_1000_4E50
FUN_1000_4E50	PROC NEAR
	push	bp
	mov	bp,sp
;	a = 4
	mov	ax,OFFSET DGROUP:$SG378
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	2
	nop	

FUN_1000_4E50	ENDP
; Line 53
	PUBLIC	FUN_1000_4EFC
FUN_1000_4EFC	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG380
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4EFC	ENDP
; Line 55
	PUBLIC	FUN_1000_4F3C
FUN_1000_4F3C	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG382
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_1000_4F3C	ENDP
; Line 58
	PUBLIC	FUN_1000_6E60
FUN_1000_6E60	PROC NEAR
	push	bp
	mov	bp,sp
;	param_1 = 4
;	param_2 = 6
	mov	ax,OFFSET DGROUP:$SG386
	push	ax
	call	_puts
	add	sp,2
	pop	bp
	ret	4
	nop	

FUN_1000_6E60	ENDP
; Line 61
	PUBLIC	FUN_0000_8BCA
FUN_0000_8BCA	PROC NEAR
	mov	ax,OFFSET DGROUP:$SG388
	push	ax
	call	_puts
	add	sp,2
	ret	
	nop	

FUN_0000_8BCA	ENDP
_TEXT	ENDS
END
