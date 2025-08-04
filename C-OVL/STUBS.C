#include "COMMON.H"
#include "FUNCS.H"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// thunks
void INTRO_intro_main() { puts("INTRO_intro_main"); F_INTRO_0986(); }

// load_mainout_ovl
void MAINOUT_0d22() { puts("MAINOUT_0d22"); F_MAINOUT_0d22(); }

void TOWN_main1_11f0(int x) { printf("TOWN_main1_11f0(%d)\n", x); }
void TOWN_main2_141e() { puts("TOWN_main2_141e"); }

// load_dungeon_ovl
void DUNGEON_0e2e(int x) { printf("DUNGEON_0e2e(%d)\n", x); }

char* OUTSUBS_get_world_savefile_0348() { puts("OUTSUBS_get_world_savefile_0348"); }

// 0000
cdecl FUN_1000_02F4_exit_to_dos(int a) { printf("FUN_1000_02F4_exit_to_dos(%d)\n", a); exit(a); }
     FUN_1000_0878_set_old_video_mode() { puts("FUN_1000_0878_set_old_video_mode"); }
     FUN_1000_0892_initialize_video_driver(int a) { printf("FUN_1000_0892_initialize_video_driver(%d)\n", a); }

     FUN_1000_0AA6(int a, int b, int c, int d) { printf("FUN_1000_0AA6(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_0ACE(int a, int b, int c, int d, int e, int f) { printf("FUN_1000_0ACE(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
     FUN_1000_0C22(int a) { printf("FUN_1000_0C22(%d)\n", a); }
int  FUN_1000_0D72(int a) { printf("FUN_1000_0D72(%d)\n", a); }
     FUN_1000_0DE0_detect_video(void) { puts("FUN_1000_0DE0_detect_video"); }
int  FUN_1000_0E94_load_video_driver(void) { puts("FUN_1000_0E94_load_video_driver"); return 1; }
int  FUN_1000_0F2A_init_data_buffer(void) { puts("FUN_1000_0F2A_init_data_buffer"); return 1; }
     FUN_1000_0F6E_image_data_transfer(int a, int b) { printf("FUN_1000_0F6E_image_data_transfer(%d,%d)\n", a, b); }

int  FUN_1000_0FAE_load_file(char* file_name) { printf("FUN_1000_0FAE_load_file(%s)\n", file_name); return 1; }

     FUN_1000_0FDC_free_memory(int a) { printf("FUN_1000_0FDC_free_memory(%d)\n", a); }
int  FUN_1000_0FF4_load_compressed_tileset(char a) { printf("FUN_1000_0FF4_load_compressed_tileset(%d)\n", a); return 1; }

// 1000
     FUN_1000_102E_unload_tileset(void) { puts("FUN_1000_102E_unload_tileset"); }
     FUN_1000_1044_buffer_image(int a, int b, int c, int d) { printf("FUN_1000_1044_buffer_image(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_1158_init_timer(void) { puts("FUN_1000_1158_init_timer"); }
int  FUN_1000_1674_test_open_file(char* file_name) { printf("FUN_1000_1674_test_open_file(%s)\n", file_name);}
u8   FUN_1000_16a6_get_default_drive() { puts("FUN_1000_16a6_get_default_drive"); }
void FUN_1000_16ba_print_char(int a) { printf("FUN_1000_16ba_print_char(%d)\n", a); }

     // param: ES:DI
     FUN_1000_17f4_character_effects(int a, int b) { printf("FUN_1000_17f4_character_effects(%d,%d)\n", a, b); }
void FUN_1000_1850_print_string(char *a) { GRAP_PrintString(a); }//{ printf("FUN_1000_1850_print_string(%s)\n", a); }
void FUN_1000_1a3e(int a, int b, int c) { printf("FUN_1000_1a3e(%d,%d,%d)\n", a, b, c); }
char FUN_1000_1B38_keystroke_cursor(void) { puts("FUN_1000_1B38_keystroke_cursor"); return getch(); }
     FUN_1000_1b94_get_text_effects(int a) { printf("FUN_1000_1b94_get_text_effects(%d)\n", a); }
void FUN_1000_1bf2_set_text_cursor_position(int a, int b) { printf("FUN_1000_1bf2_set_text_cursor_position(%d,%d)\n", a, b); }
void FUN_1000_1c22_set_text_window_size(int a, int b, int c, int d, int e) { printf("FUN_1000_1c22_set_text_window_size(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
     FUN_1000_1c9e_get_char_segment(int a) { printf("FUN_1000_1c9e_get_char_segment(%d)\n", a); }
int  FUN_1000_1cee_get_current_text_row() { puts("FUN_1000_1cee_get_current_text_row"); }
int  FUN_1000_1D02_load_character_set(char* a, int b) { printf("FUN_1000_1D02_load_character_set(%s,%d)\n", a, b); return 1; }
char FUN_1000_1D5E_peek_keystroke(void) { puts("FUN_1000_1D5E_peek_keystroke"); }
     FUN_1000_1DDA_wait_for_keystroke(int a) { printf("FUN_1000_1DDA_wait_for_keystroke(%d)\n", a); }
int  FUN_1000_1f12_get_current_text_column() { puts("FUN_1000_1f12_get_current_text_column"); }

     // param: SI
     FUN_1000_1f77_convert_char_dimensions_to_pixels(void* a) { puts("FUN_1000_1f77_convert_char_dimensions_to_pixels(ptr)"); }

// 2000
int  FUN_1000_2032_to_upper(unsigned int x) { return toupper(x); }
int  FUN_1000_2056_get_time(void) { puts("FUN_1000_2056_get_time"); }
     FUN_1000_207E(int a) { printf("FUN_1000_207E(%d)\n", a); }
     FUN_1000_2092(int a, int b) { printf("FUN_1000_2092(%d,%d)\n", a, b); }
     FUN_1000_20FA_wait_ticks(int a) { puts("FUN_1000_20FA_wait_ticks"); }
     FUN_1000_256e_read_file_from_disk(char* file_name, u16 addr, u16 size, u16 a) { printf("FUN_1000_256e_read_file_from_disk(%s,%d,%d,%d)\n", file_name, addr, size, a); }
     FUN_1000_25d8_write_file_to_disk(char* file_name, u16 addr, u16 size) { printf("FUN_1000_25d8_write_file_to_disk(%s,%d,%d)\n", file_name, addr, size); }
     FUN_1000_251e_switch_disks(int x) { printf("FUN_1000_251e_switch_disks(%d)\n", x); }

int  FUN_1000_266c_get_ch(void) { puts("FUN_1000_266c_get_ch"); }

void FUN_1000_2900(void) { puts("FUN_1000_2900"); }

int  FUN_1000_2d7a(/*?*/) { puts("FUN_1000_2d7a"); }

void FUN_1000_2E96_print_direction(int a) { printf("FUN_1000_2E96_print_direction(%d)\n", a); }

// 4000
     FUN_1000_43ae(int a, int b, int c, int d) { printf("FUN_1000_43ae(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_4C2A(void) { puts("FUN_1000_4C2A"); }
     FUN_1000_4CCE(void) { puts("FUN_1000_4CCE"); }
     FUN_1000_4d76(void* a, byte b) { printf("FUN_1000_4d76(ptr,%d)", b); }
void FUN_1000_4daa(void) { puts("FUN_1000_4daa"); }
     FUN_1000_4dea(int a) { printf("FUN_1000_4dea(%d)\n", a); }
     FUN_1000_4e20(void) { puts("FUN_1000_4e20"); }
void FUN_1000_4e50(char *a) { printf("FUN_1000_4e50(%s)\n", a); }
     FUN_1000_4efc(void) { puts("FUN_1000_4efc"); }

     FUN_1000_4f3c(void) { puts("FUN_1000_4f3c"); }

// 6000
     FUN_1000_637E(void) { puts("FUN_1000_637E"); }
     FUN_1000_6e60(int param_2, int param_1) { printf("FUN_1000_6e60(%d,%d)\n", param_2, param_1); }

// static thunks
void FUN_0000_7CCE(void) /* 1778:054E; FONT.OVL 0EBC:012A */ { puts("FUN_0000_7CCE [thunk]"); }
void FUN_0000_7CDA(void) /* 1778:055A; FONT.OVL 0E1E:04A4 */ { puts("FUN_0000_7CDA [thunk]"); }
