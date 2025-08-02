#ifndef _FUNCS_H
#define _FUNCS_H

extern void INTRO_intro_main();

extern void MAINOUT_0d22();

extern TOWN_main1_11f0(int x);
extern void TOWN_main2_141e();

extern DUNGEON_0e2e(int x);

extern char* OUTSUBS_get_world_savefile_0348();

// 0000
extern      FUN_1000_0878_set_old_video_mode();

extern int  FUN_1000_0FAE_load_file(char* file_name);

// 1000
extern int  FUN_1000_1674_test_open_file(char* file_name);
extern u8   FUN_1000_16a6_get_default_drive();
extern void FUN_1000_16ba_print_char(int a);
extern void FUN_1000_1850_print_string(char *a);
extern void FUN_1000_1a3e(int a, int b, int c);
extern      FUN_1000_1b94_get_text_effects(int a);
extern void FUN_1000_1bf2_set_text_cursor_position(int a, int b);
extern void FUN_1000_1c22_set_text_window_size(int a, int b, int c, int d, int e);
extern      FUN_1000_1c9e_get_char_segment(int a);
extern int  FUN_1000_1cee_get_current_text_row();
extern int  FUN_1000_1f12_get_current_text_column();

// 2000
extern int  FUN_1000_2032_to_upper(unsigned int x);
extern      FUN_1000_2092(int a, int b);
extern      FUN_1000_256e_read_file_from_disk(char* file_name, u16 addr, u16 size, u16 a);
extern      FUN_1000_25d8_write_file_to_disk(char* file_name, u16 addr, u16 size);
extern      FUN_1000_251e_switch_disks(int x);

extern      FUN_1000_266c_get_ch();

extern      FUN_1000_2900();

extern int  FUN_1000_2d7a(/*?*/);

// 4000
extern      FUN_1000_43ae(int a, int b, int c, int d);
extern      FUN_1000_4d76(void* a, byte b);
extern void FUN_1000_4daa();
extern      FUN_1000_4dea(int a);
extern      FUN_1000_4e20();
extern void FUN_1000_4e50(char *a);
extern      FUN_1000_4efc();

extern      FUN_1000_4f3c();

// 6000

extern      FUN_1000_6e60(int param_2, int param_1);

// thunks

extern      FUN_0000_8bca();

#endif
