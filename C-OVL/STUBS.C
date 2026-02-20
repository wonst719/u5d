#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

void SWAP(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void F_INTRO_0986_main();
void F_MAINOUT_0d22();
void F_TOWN_11f0_Entry(int param_1);
void F_TOWN_141e_MainLoop();
void F_DUNGEON_0e2e_MainLoop(int param_1);

int F_TALK_041c_talk_cmd(void);

// dnglook
void F_DNGLOOK_06a8_view_cmd(void) { puts("F_DNGLOOK_06a8_view_cmd"); }

void F_DNGLOOK_1130() { puts("F_DNGLOOK_1130"); }
void F_DNGLOOK_109e() { puts("F_DNGLOOK_109e"); }

void F_CAST_1792_use_cmd(void) { puts("F_CAST_1792_use_cmd"); }

void F_ENDGAME_0648_endgame_main(void) { puts("F_ENDGAME_0648_endgame_main"); }

void FUN_0000_7cce(void) /* 1778:054E; FONT.OVL 0EBC:012A */ { puts("FUN_0000_7CCE [thunk]"); }
void FUN_0000_7cda(void) /* 1778:055A; FONT.OVL 0E1E:04A4 */ { puts("FUN_0000_7CDA [thunk]"); }

// 0000
// 32bit div?
int  FUN_1000_03a0(int a, int b, int c, int d) { printf("FUN_1000_03a0(%d,%d,%d,%d)\n", a, b, c, d); }

     FUN_1000_0878_set_old_video_mode() { puts("FUN_1000_0878_set_old_video_mode"); }

     FUN_1000_0bae_load_compressed_file(char* file_name) { printf("FUN_1000_0bae_load_compressed_file(%s)\n", file_name); }
void FUN_1000_0be4_free_memory(void* ptr) { puts("FUN_1000_0be4_free_memory"); }
     FUN_1000_0d4c(int a, int b, int c, int d, int e) { printf("FUN_1000_0d4c(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
int  FUN_1000_0d72(int a) { printf("FUN_1000_0d72(%d)\n", a); }
void FUN_1000_0de0_detect_video(void) { puts("FUN_1000_0de0_detect_video"); D_52ba_vdp._52c8_videoDriverSelection = 1; }
int  FUN_1000_0e94_load_video_driver(void) { puts("FUN_1000_0e94_load_video_driver"); return 1; } // DUMMY
int  FUN_1000_0f2a_init_data_buffer(void) { puts("FUN_1000_0f2a_init_data_buffer"); return 1; } // DUMMY
     FUN_1000_0f46(int a, int b, int c, int d) { printf("FUN_1000_0f46(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_0f6e_image_data_transfer(int a, int b) { printf("FUN_1000_0f6e_image_data_transfer(%d,%d)\n", a, b); }

int  FUN_1000_0fae_load_file(char* file_name) { printf("FUN_1000_0FAE_load_file(%s)\n", file_name); return 1; }

     FUN_1000_0fdc_free_memory(int a) { printf("FUN_1000_0FDC_free_memory(%d)\n", a); }

// 1000
     FUN_1000_102e_unload_tileset(void) { puts("FUN_1000_102E_unload_tileset"); }
     FUN_1000_1044_buffer_image(int a, int b, int c, int d) { printf("FUN_1000_1044_buffer_image(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_1068(int a, int b, int c) { printf("FUN_1000_1068(%d,%d,%d)\n", a, b, c); }
     FUN_1000_1112(int a, int b, int c) { printf("FUN_1000_1112(%d, %d, %d)\n", a, b, c); }
     FUN_1000_1158_init_timer(void) { puts("FUN_1000_1158_init_timer"); }
int  FUN_1000_1674_test_open_file(char* file_name) { printf("FUN_1000_1674_test_open_file(%s)\n", file_name); return 1; } // FMT
u8   FUN_1000_16a6_get_default_drive() { puts("FUN_1000_16a6_get_default_drive"); return 'C'; } // DUMMY


// 4000
     FUN_1000_4080(int a) { printf("FUN_1000_4080(%d)\n", a); }
void FUN_1000_4368() { puts("FUN_1000_4368"); }
     FUN_1000_43ae(int a, int b, int c, int d) { printf("FUN_1000_43ae(%d,%d,%d,%d)\n", a, b, c, d); }

int  FUN_1000_4988(void) { puts("FUN_1000_4988"); }

     FUN_1000_4efc(void) { puts("FUN_1000_4efc"); }

// 5000

// 6000
int  FUN_1000_6d82(int a, int b) { printf("FUN_1000_6d82(%d,%d)\n", a, b); }
int  FUN_1000_6da8(int a) { printf("FUN_1000_6da8(%d)\n", a); }
     FUN_1000_6e60(int param_2, int param_1) { printf("FUN_1000_6e60(%d,%d)\n", param_2, param_1); }

// 7000

// MAX: < FUN_1000_7296
