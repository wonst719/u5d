#ifndef _FUNCS_H
#define _FUNCS_H

extern void INTRO_intro_main();

extern void MAINOUT_0d22();

extern void TOWN_main1_11f0(int x);
extern void TOWN_main2_141e();

extern void DUNGEON_0e2e(int x);

extern char* OUTSUBS_get_world_savefile_0348();

// 0000
extern cdecl FUN_1000_02F4_exit_to_dos(int a);
extern      FUN_1000_0878_set_old_video_mode();
extern      FUN_1000_0892_initialize_video_driver(int a);

extern      FUN_1000_0AA6(int a, int b, int c, int d);
extern      FUN_1000_0ACE(int a, int b, int c, int d, int e, int f);
extern      FUN_1000_0C22(int a);
extern int  FUN_1000_0D72(int a);
extern      FUN_1000_0DE0_detect_video(void);
extern int  FUN_1000_0E94_load_video_driver(void);
extern int  FUN_1000_0F2A_init_data_buffer(void);
extern      FUN_1000_0F6E_image_data_transfer(int a, int b);

extern int  FUN_1000_0FAE_load_file(char* file_name);

extern      FUN_1000_0FDC_free_memory(int a);
extern int  FUN_1000_0FF4_load_compressed_tileset(char a);

// 1000
extern      FUN_1000_102E_unload_tileset(void);
extern      FUN_1000_1044_buffer_image(int a, int b, int c, int d);
extern      FUN_1000_1158_init_timer(void);
extern int  FUN_1000_1674_test_open_file(char* file_name);
extern u8   FUN_1000_16a6_get_default_drive();
extern void FUN_1000_16ba_print_char(int a);
extern void FUN_1000_1850_print_string(char *a);
extern void FUN_1000_1a3e(int a, int b, int c);
extern char FUN_1000_1B38_keystroke_cursor(void);
extern      FUN_1000_1b94_get_text_effects(int a);
extern void FUN_1000_1bf2_set_text_cursor_position(int a, int b);
extern void FUN_1000_1c22_set_text_window_size(int a, int b, int c, int d, int e);
extern      FUN_1000_1c9e_get_char_segment(int a);
extern int  FUN_1000_1cee_get_current_text_row();
extern int  FUN_1000_1D02_load_character_set(char* a, int b);
extern char FUN_1000_1D5E_peek_keystroke(void);
extern      FUN_1000_1DDA_wait_for_keystroke(int a);
extern int  FUN_1000_1f12_get_current_text_column();

// 2000
extern int  FUN_1000_2032_to_upper(unsigned int x);
extern int  FUN_1000_2056_get_time(void);
extern      FUN_1000_207E(int a);
extern      FUN_1000_2092(int a, int b);
extern      FUN_1000_20FA_wait_ticks(int a);
extern      FUN_1000_251e_switch_disks(int a);
extern      FUN_1000_256e_read_file_from_disk(char* file_name, u16 addr, u16 size, u16 a);
extern      FUN_1000_25d8_write_file_to_disk(char* file_name, u16 addr, u16 size);
extern      FUN_1000_251e_switch_disks(int x);

extern int FUN_1000_266c_get_ch(void);

extern void FUN_1000_2900(void);

extern int  FUN_1000_2d7a(/*?*/);

extern void FUN_1000_2E96_print_direction(int a);

// 4000
extern      FUN_1000_43ae(int a, int b, int c, int d);
extern      FUN_1000_4C2A(void);
extern      FUN_1000_4CCE(void);
extern      FUN_1000_4d76(void* a, byte b);
extern void FUN_1000_4daa(void);
extern      FUN_1000_4dea(int a);
extern      FUN_1000_4e20(void);
extern void FUN_1000_4e50(char *a);
extern      FUN_1000_4efc(void);

extern      FUN_1000_4f3c(void);

// 6000

extern      FUN_1000_637E(void);
extern      FUN_1000_6e60(int param_2, int param_1);

// thunks

extern void FUN_0000_7CCE(void);
extern void FUN_0000_7CDA(void);

#endif
