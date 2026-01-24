#ifndef _FUNCS_H
#define _FUNCS_H

#include "STRUCTS.H"

extern void SWAP(int* a, int* b);

extern void INTRO_intro_main();

extern void MAINOUT_0d22();

extern void TOWN_main1_11f0(int x);
extern void TOWN_main2_141e_MainLoop();

extern      F_DUNGEON_0c76(int a, int b);
extern void DUNGEON_0e2e_MainLoop(int x);

extern void F_NPC_0000();
extern void F_NPC_00d6(int x);

// 0000
extern cdecl FUN_1000_02f4_exit_to_dos(int a);

extern int  FUN_1000_03a0(int a, int b, int c, int d);

extern void* cdecl FUN_1000_0402_memchr(void* param_1, int param_2, int param_3);

extern      FUN_1000_0878_set_old_video_mode();
extern void FUN_1000_0892_initialize_video_driver(int a);
extern int  FUN_1000_08e6_constraint_imagewindow(int* x1, int* y1, int* x2, int* y2);

extern void FUN_1000_0a70_set_pen_color(int a);

extern void FUN_1000_0aa6_fill_rectangle(int x1, int y1, int x2, int y2);
extern      FUN_1000_0ace(int a, int b, int c, int d, int e, int f);
extern void FUN_1000_0b10_line(int x1, int y1, int x2, int y2);
extern void FUN_1000_0b2d_line(int ax, int bx, int cx, int dx);
extern void FUN_1000_0b86(int x1, int y1, int x2, int y2);
extern      FUN_1000_0bae_load_compressed_file(char* file_name);
extern void FUN_1000_0be4_free_memory(void* ptr);
extern void FUN_1000_0c22(int a);
extern void FUN_1000_0c9c_grap_horiz_line(int x1, int y, int x2);
extern      FUN_1000_0cf2(int a, int b, int c);
extern      FUN_1000_0d4c(int a, int b, int c, int d, int e);
extern int  FUN_1000_0d72(int a);
extern void FUN_1000_0de0_detect_video(void);
extern int  FUN_1000_0e94_load_video_driver(void);
extern int  FUN_1000_0f2a_init_data_buffer(void);
extern      FUN_1000_0f46(int a, int b, int c, int d);
extern      FUN_1000_0f6e_image_data_transfer(int a, int b);
extern void FUN_1000_0f90_pen(int a, int b);

extern int  FUN_1000_0fae_load_file(char* file_name);

extern      FUN_1000_0fdc_free_memory(int a);
extern int  FUN_1000_0ff4_load_compressed_tileset(char* a);

// 1000
extern      FUN_1000_102e_unload_tileset(void);
extern      FUN_1000_1044_buffer_image(int a, int b, int c, int d);
extern      FUN_1000_1068(int a, int b, int c);
extern void FUN_1000_10e0_draw_tile(uint a, int b, int c);
extern      FUN_1000_1112(int a, int b, int c);
extern      FUN_1000_1158_init_timer(void);
extern int  FUN_1000_1674_test_open_file(char* file_name);
extern u8   FUN_1000_16a6_get_default_drive();
extern void FUN_1000_16ba_print_char(uint a);
extern void FUN_1000_1850_print_string(char *a);
extern void FUN_1000_1a3e_print_number(int a, int b, int c);
extern void FUN_1000_1b16_clear_keyboard_buffer();
extern void FUN_1000_1b24_clear_keyboard_buffer_impl();
extern u16  FUN_1000_1b38_keystroke_cursor(void);
extern void FUN_1000_1b94_select_charset(int a);
extern void FUN_1000_1bf2_set_text_cursor_position(int a, int b);
extern void FUN_1000_1c22_set_text_window_size(int a, int b, int c, int d, int e);
extern      FUN_1000_1c9e_get_char_segment(int a);
extern void FUN_1000_1cca_set_text_foreground_color(int a);
extern int  FUN_1000_1cee_get_current_text_row();
extern int  FUN_1000_1d02_load_character_set(char* a, int b);
extern int  FUN_1000_1d5e_peek_keystroke(void);
extern      FUN_1000_1dda_wait_for_keystroke(int a);
extern int  FUN_1000_1f12_get_current_text_column();
extern void FUN_1000_1f26_set_text_background_color(int a);
struct TextWindow;
extern      FUN_1000_1f77_convert_char_dimensions_to_pixels(struct TextWindow* window, int* pAX, int* pBX, int* pCX, int* pDX);
extern void FUN_1000_1fa0_backspace(int x);

// 2000
extern u16  FUN_1000_2032_to_upper(u8 x);
extern uint FUN_1000_2056_get_time(void);
extern void FUN_1000_207e_srand(uint a);
extern uint FUN_1000_2092_random_range(uint a, uint b);
extern void FUN_1000_20c8_some_delay(int param_1, int param_2);
extern      FUN_1000_20fa_wait_ticks(int a);
extern int  FUN_1000_216c_strlen(char* param_1);
extern void FUN_1000_2192_audio_some_noise(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void FUN_1000_223c_audio_white_noise(uint rate, uint dur, uint limit);
extern void FUN_1000_22c0_pcspk_play_tone(uint freq, uint dur);
extern void FUN_1000_22e2_pcspk_start_tone(uint freq);
extern void FUN_1000_230e_pcspk_off(void);
extern      FUN_1000_251e_switch_disks(int a);
extern int  FUN_1000_256e_read_file_from_disk(char* file_name, void* addr, u16 size, u16 offset);
extern      FUN_1000_25d8_write_file_to_disk(char* file_name, void* addr, u16 size);

extern int  FUN_1000_266c_get_ch(void);
extern void FUN_1000_2884_update_gold(void);
extern void FUN_1000_2900_update_vitals(void);
extern void FUN_1000_2a28(int param_1);
extern void FUN_1000_2a52(int param_1, uint param_2);
extern void FUN_1000_2aa8(void);
extern void FUN_1000_2ae8(void);
extern int  FUN_1000_2c4c(int param_2, int param_1);
extern int  FUN_1000_2d7a(int a);

extern void FUN_1000_2e96_print_direction(int a);
extern void FUN_1000_2f62(void);
extern void FUN_1000_2fd0(undefined2 param_1);

// 3000
extern void FUN_1000_3072(void);
extern int  FUN_1000_3178_process_command(int param_1);
extern      FUN_1000_3522(int x, int y);
extern void FUN_1000_3564(int a);
extern int  FUN_1000_35ec_select_direction();
extern int  FUN_1000_368e(int x, int y, int z);
extern int  FUN_1000_3702(int param_1, int param_2, int param_3);
extern int  FUN_1000_38e4();
extern void FUN_1000_39cc_set_new_tile_id(int new_tile_id, byte x, byte y);
extern int  FUN_1000_39fc_get_first_active_party_member();
extern void FUN_1000_3a74(byte a, byte b, byte c, byte d, byte e, byte f, int g);
extern int  FUN_1000_3aae(int a);
extern int  FUN_1000_3abe();
extern      FUN_1000_3ae6(int a);
extern void FUN_1000_3b1c_get_string(char* param_1, int param_2);
extern      FUN_1000_3c9a_hole_up();

extern void FUN_1000_3ef0(byte* param_1, int param_2, int param_3);
extern void FUN_1000_3f14(s16* a, int b, int c);
extern void FUN_1000_3f36(byte* param_1, int param_2);
extern void FUN_1000_3f54(s16* a, int b);

// 4000
extern void FUN_1000_400c();
extern      FUN_1000_4080(int a);
extern void FUN_1000_4102(void);
extern void FUN_1000_433e_audio_some_noise();
extern void FUN_1000_4368();
extern      FUN_1000_43ae(int a, int b, int c, int d);
extern byte* FUN_1000_4402_get_address_of_tile_id(int x, int y);
extern void FUN_1000_4552(void);
extern void FUN_1000_475a(void);
extern int  FUN_1000_48a8();
extern int  FUN_1000_4988();
extern void FUN_1000_4a84(void);
extern void FUN_1000_4be8();

extern void FUN_1000_4c2a(void);
extern void FUN_1000_4cce(void);
extern int  FUN_1000_4d76(char* a, int b);
extern void FUN_1000_4daa(void);
extern void FUN_1000_4dea(int a);
extern void FUN_1000_4e20(void);
extern void FUN_1000_4e50(char* a);
extern      FUN_1000_4efc(void);

extern void FUN_1000_4f3c(void);
extern void FUN_1000_4f7c(int a);

extern int  FUN_1000_5646(int a);
extern void FUN_1000_5910_update_map();

extern void FUN_1000_5d0a(int a, int x, int y, int d);
extern bool FUN_1000_5dfe(byte param_1, int param_2);
extern void FUN_1000_5e4a(void);

// 6000
extern      FUN_1000_6150_attack_monster(int a, int b);

extern void FUN_1000_637e_draw_frame(void);

extern int  FUN_1000_6506(int a, int b, int c, int d, int e);
extern void FUN_1000_6800(int a);
extern void FUN_1000_68ae(int a);
extern int  FUN_1000_6d82(int a, int b);
extern int  FUN_1000_6da8(int a);
extern      FUN_1000_6e60(int param_2, int param_1);
extern int  FUN_1000_6f1e(char* param_1, char* param_2);
extern void FUN_1000_6fd6();
extern int  FUN_1000_6ff0(register int param_1, register int param_2);

// 7000
extern void FUN_1000_70a6(void);
extern void FUN_1000_71aa();
extern void FUN_1000_71ca(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void FUN_1000_7200(int param_1, int param_2, int param_3, int param_4, int param_5);

// thunks

extern void FUN_0000_7cce(void);
extern void FUN_0000_7cda(void);

#endif
