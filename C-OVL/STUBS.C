#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include "FILE.H"
#include "GRAP.H"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void F_INTRO_0986_main();
void F_MAINOUT_0d22();

void SWAP(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//
#ifndef _WIN32
int u5_getch()
{
    return getch();
}
#endif

// thunks
void INTRO_intro_main() { puts("INTRO_intro_main"); F_INTRO_0986_main(); }

// load_mainout_ovl
void MAINOUT_0d22() { puts("MAINOUT_0d22"); F_MAINOUT_0d22(); }

void TOWN_main1_11f0(int x) { printf("TOWN_main1_11f0(%d)\n", x); }
void TOWN_main2_141e_MainLoop() { puts("TOWN_main2_141e"); }

// load_dungeon_ovl
void DUNGEON_0e2e_MainLoop(int x) { printf("DUNGEON_0e2e(%d)\n", x); F_DUNGEON_0e2e_MainLoop(x); }

// npc
void F_NPC_0000() {}
void F_NPC_00d6(int x) {}
F_NPC_0db4() {}

// blckthrn
void F_BLCKTHRN_0910_death() {}

// dnglook
void F_DNGLOOK_1130() {}
void F_DNGLOOK_109e() {}

F_CAST2_0e76() {}

// 0000
cdecl FUN_1000_02f4_exit_to_dos(int a) { printf("FUN_1000_02F4_exit_to_dos(%d)\n", a); exit(a); }
     FUN_0000_06c4(int a) { printf("FUN_0000_06c4(%d)\n", a); }
     FUN_1000_0878_set_old_video_mode() { puts("FUN_1000_0878_set_old_video_mode"); }

     FUN_1000_0ace(int a, int b, int c, int d, int e, int f) { printf("FUN_1000_0ACE(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
     FUN_1000_0bae_load_compressed_file(char* file_name) { printf("FUN_1000_0bae_load_compressed_file(%s)", file_name); }
void FUN_1000_0be4_free_memory(void* ptr) { puts("FUN_1000_0be4_free_memory"); }
     FUN_1000_0c22(int a) { printf("FUN_1000_0C22(%d)\n", a); }
     FUN_0000_0c76(int a, int b) { printf("FUN_0000_0c76(%d,%d)\n", a, b); }
     FUN_1000_0c9c(int a, int b, int c) { printf("FUN_1000_0c9c(%d,%d,%d)\n", a, b, c); }
     FUN_1000_0d4c(int a, int b, int c, int d, int e) { printf("FUN_1000_0d4c(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
int  FUN_1000_0D72(int a) { printf("FUN_1000_0D72(%d)\n", a); }
void FUN_1000_0DE0_detect_video(void) { puts("FUN_1000_0DE0_detect_video"); D_52ba_vdp._52c8_videoDriverSelection = 1; }
int  FUN_1000_0E94_load_video_driver(void) { puts("FUN_1000_0E94_load_video_driver"); return 1; } // DUMMY
int  FUN_1000_0F2A_init_data_buffer(void) { puts("FUN_1000_0F2A_init_data_buffer"); return 1; } // DUMMY
     FUN_1000_0f46(int a, int b, int c, int d) { printf("FUN_1000_0f46(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_0F6E_image_data_transfer(int a, int b) { printf("FUN_1000_0F6E_image_data_transfer(%d,%d)\n", a, b); }

int  FUN_1000_0fae_load_file(char* file_name) { printf("FUN_1000_0FAE_load_file(%s)\n", file_name); return 1; }

     FUN_1000_0fdc_free_memory(int a) { printf("FUN_1000_0FDC_free_memory(%d)\n", a); }
int  FUN_1000_0FF4_load_compressed_tileset(char* a) { printf("FUN_1000_0FF4_load_compressed_tileset(%s)\n", a); return 1; }

// 1000
     FUN_1000_102e_unload_tileset(void) { puts("FUN_1000_102E_unload_tileset"); }
     FUN_1000_1044_buffer_image(int a, int b, int c, int d) { printf("FUN_1000_1044_buffer_image(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_1158_init_timer(void) { puts("FUN_1000_1158_init_timer"); }
int  FUN_1000_1674_test_open_file(char* file_name) { printf("FUN_1000_1674_test_open_file(%s)\n", file_name); return 1; } // FMT
u8   FUN_1000_16a6_get_default_drive() { puts("FUN_1000_16a6_get_default_drive"); return 'C'; } // DUMMY

     // param: ES:DI
     FUN_1000_17f4_character_effects(int a, int b) { printf("FUN_1000_17f4_character_effects(%d,%d)\n", a, b); }
void FUN_1000_1a3e(int a, int b, int c) { printf("FUN_1000_1a3e(%d,%d,%d)\n", a, b, c); }
char FUN_1000_1B38_keystroke_cursor(void) { puts("FUN_1000_1B38_keystroke_cursor"); return u5_getch(); }
     FUN_1000_1c9e_get_char_segment(int a) { printf("FUN_1000_1c9e_get_char_segment(%d)\n", a); }
     FUN_1000_1cca_set_text_foreground_color(int a) { printf("FUN_1000_1cca_set_text_foreground_color(%d)\n", a); }
int  FUN_1000_1D02_load_character_set(char* a, int b) { printf("FUN_1000_1D02_load_character_set(%s,%d)\n", a, b); return 1; } // FMT
char FUN_1000_1d5e_peek_keystroke(void) { puts("FUN_1000_1D5E_peek_keystroke"); }
     FUN_1000_1DDA_wait_for_keystroke(int a) { printf("FUN_1000_1DDA_wait_for_keystroke(%d)\n", a); u5_getch(); }

// 2000
int  FUN_1000_2032_to_upper(unsigned int x)
{
    if (x < 0x61 || 0x7a < x)
        return (byte)x;
    return (byte)x - 0x20;
    //return toupper(x);
}

int  FUN_1000_2056_get_time(void) { puts("FUN_1000_2056_get_time"); }
     FUN_1000_207E(int a) { printf("FUN_1000_207E(%d)\n", a); }
     FUN_1000_2092(int a, int b) { printf("FUN_1000_2092(%d,%d)\n", a, b); }
     FUN_1000_20fa_wait_ticks(int a) { puts("FUN_1000_20FA_wait_ticks"); }

int FUN_1000_216c_strlen(char* param_1)
{
    int iVar1;

    iVar1 = 0;
    while (*param_1 != '\0') {
        iVar1 = iVar1 + 1;
        param_1 = param_1 + 1;
    }
    return iVar1;
}

int  FUN_1000_256e_read_file_from_disk(char* file_name, void* addr, u16 size, u16 offset)
{
    printf("FUN_1000_256e_read_file_from_disk(%s,%d,%d,%d)\n", file_name, (u16)addr, size, offset);
    FILE_ReadFile(file_name, addr, size, offset);
}
     FUN_1000_25d8_write_file_to_disk(char* file_name, void* addr, u16 size) { printf("FUN_1000_25d8_write_file_to_disk(%s,%d,%d)\n", file_name, (u16)addr, size); }
     FUN_1000_251e_switch_disks(int x) { printf("FUN_1000_251e_switch_disks(%d)\n", x); }

int  FUN_1000_266c_get_ch(void) { puts("FUN_1000_266c_get_ch"); }

void FUN_1000_2900(void) { puts("FUN_1000_2900"); }

int  FUN_1000_2d7a(/*?*/) { puts("FUN_1000_2d7a"); }

// 3000
     FUN_1000_3178_process_command() { puts("FUN_1000_3178_process_command"); }
     FUN_1000_39cc() { puts("FUN_1000_39cc"); }
int  FUN_1000_39fc() { puts("FUN_1000_39fc"); }


// 4000
     FUN_1000_43ae(int a, int b, int c, int d) { printf("FUN_1000_43ae(%d,%d,%d,%d)\n", a, b, c, d); }
int  FUN_1000_48a8(void) { puts("FUN_1000_48a8"); }
     FUN_1000_4c2a(void) { puts("FUN_1000_4C2A"); }
     FUN_1000_4cce(void) { puts("FUN_1000_4CCE"); }
     FUN_1000_4d76(void* a, byte b) { printf("FUN_1000_4d76(ptr,%d)", b); }
void FUN_1000_4daa(void) { puts("FUN_1000_4daa"); }
     FUN_1000_4dea(int a) { printf("FUN_1000_4dea(%d)\n", a); }
     FUN_1000_4e20(void) { puts("FUN_1000_4e20"); }
     FUN_1000_4efc(void) { puts("FUN_1000_4efc"); }

     FUN_1000_4f3c(void) { puts("FUN_1000_4f3c"); }
     FUN_1000_4f7c(int a) { printf("FUN_1000_4f7c(%d)\n", a); }

     FUN_1000_5910() { puts("FUN_1000_5910"); }

// 6000
     FUN_1000_6e60(int param_2, int param_1) { printf("FUN_1000_6e60(%d,%d)\n", param_2, param_1); }

// static thunks
void FUN_0000_7cce(void) /* 1778:054E; FONT.OVL 0EBC:012A */ { puts("FUN_0000_7CCE [thunk]"); }
void FUN_0000_7cda(void) /* 1778:055A; FONT.OVL 0E1E:04A4 */ { puts("FUN_0000_7CDA [thunk]"); }
