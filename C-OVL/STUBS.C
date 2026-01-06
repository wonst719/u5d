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
void F_TOWN_11f0_Entry(int param_1);
void F_TOWN_141e_MainLoop();
void F_DUNGEON_0e2e_MainLoop(int param_1);

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

int u5_peekch()
{
    if (kbhit())
        return getch();
    return 0;
}
#endif

// thunks
// off - 0x7780

// intro
void INTRO_intro_main() { F_INTRO_0986_main(); }

// mainout
void MAINOUT_0d22() { F_MAINOUT_0d22(); }

// town
void TOWN_main1_11f0(int x) { F_TOWN_11f0_Entry(x); }
void TOWN_main2_141e_MainLoop() { F_TOWN_141e_MainLoop(); }

// dungeon
void DUNGEON_0e2e_MainLoop(int x) { F_DUNGEON_0e2e_MainLoop(x); }

int F_TOWN_09e6_attack_cmd() { puts("F_TOWN_09e6_attack_cmd"); }
F_TOWN_0b82_klimb_cmd() { puts("F_TOWN_0b82_klimb_cmd"); }

int F_DUNGEON_1d4a_attack_cmd() { puts("F_DUNGEON_1d4a_attack_cmd"); }
F_DUNGEON_1e10_klimb_cmd() { puts("F_DUNGEON_1e10_klimb_cmd"); }

// lookobj
F_LOOKOBJ_0000_look_cmd_in_dungeon() { puts("F_LOOKOBJ_0000_look_cmd_in_dungeon"); }
F_LOOKOBJ_099c_look_cmd() { puts("F_LOOKOBJ_099c_look_cmd"); }
F_LOOKOBJ_10fc_view_cmd(int x, int y) { printf("F_LOOKOBJ_10fc_view_cmd(%d,%d)\n", x, y); }

// dnglook
F_DNGLOOK_06a8_view_cmd() { puts("F_DNGLOOK_06a8_view_cmd"); }
void F_DNGLOOK_1130() { puts("F_DNGLOOK_1130"); }
void F_DNGLOOK_109e() { puts("F_DNGLOOK_109e"); }

// cmds
F_CMDS_0552_hole_up_cmd() { puts("F_CMDS_0552_hole_up_cmd"); }
int F_CMDS_07f6_board_cmd() { puts("F_CMDS_07f6_board_cmd"); }
F_CMDS_0aea_fire_cmd() { puts("F_CMDS_0aea_fire_cmd"); }
F_CMDS_0d98_ignite_torch_cmd() { puts("F_CMDS_0d98_ignite_torch_cmd"); }
F_CMDS_0ddc_new_order_cmd() { puts("F_CMDS_0ddc_new_order_cmd"); }
F_CMDS_0eb4_xit_cmd() { puts("F_CMDS_0eb4_xit_cmd"); }
F_CMDS_1418_yell_cmd() { puts("F_CMDS_1418_yell_cmd"); }
F_CMDS_161a_push_cmd() { puts("F_CMDS_161a_push_cmd"); }
F_CMDS_1ad8_mix_cmd() { puts("F_CMDS_1ad8_mix_cmd"); }
F_CMDS_1c20_klimb_cmd() { puts("F_CMDS_1c20_klimb_cmd"); }

// cast
int F_CAST_0dba_cast_spell_cmd() { puts("F_CAST_0dba_cast_spell_cmd"); }
F_CAST2_0e76() { puts("F_CAST2_0e76"); }
F_CAST2_10fe_save_game() { puts("F_CAST2_10fe_save_game"); }
F_CAST_1792_use_cmd() { puts("F_CAST_1792_use_cmd"); }

int F_TALK_041c_talk_cmd(void);

// comsubs
int F_COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    printf("F_COMSUBS_12de(%d,%d,%d,%d,%d)\n", param_1, param_2, param_3, param_4, param_5);
}


// 1778:040A -> OUTSUBS 0A2B:0194 (01B4)
// 1778:0416 -> OUTSUBS 0A2B:0546 (0566)

// blckthrn
void F_BLCKTHRN_0910_death() { puts("F_BLCKTHRN_0910_death"); }

void FUN_0000_7cce(void) /* 1778:054E; FONT.OVL 0EBC:012A */ { puts("FUN_0000_7CCE [thunk]"); }
void FUN_0000_7cda(void) /* 1778:055A; FONT.OVL 0E1E:04A4 */ { puts("FUN_0000_7CDA [thunk]"); }

// 0000
cdecl FUN_1000_02f4_exit_to_dos(int a) { printf("FUN_1000_02F4_exit_to_dos(%d)\n", a); exit(a); }
     FUN_1000_0878_set_old_video_mode() { puts("FUN_1000_0878_set_old_video_mode"); }

     FUN_1000_0ace(int a, int b, int c, int d, int e, int f) { printf("FUN_1000_0ACE(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
void FUN_1000_0b86(int x1, int y1, int x2, int y2) { printf("FUN_1000_0ACE(%d,%d,%d,%d)\n", x1, y1, x2, y2); }
     FUN_1000_0bae_load_compressed_file(char* file_name) { printf("FUN_1000_0bae_load_compressed_file(%s)\n", file_name); }
void FUN_1000_0be4_free_memory(void* ptr) { puts("FUN_1000_0be4_free_memory"); }
     FUN_1000_0d4c(int a, int b, int c, int d, int e) { printf("FUN_1000_0d4c(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }
int  FUN_1000_0D72(int a) { printf("FUN_1000_0D72(%d)\n", a); }
void FUN_1000_0DE0_detect_video(void) { puts("FUN_1000_0DE0_detect_video"); D_52ba_vdp._52c8_videoDriverSelection = 1; }
int  FUN_1000_0E94_load_video_driver(void) { puts("FUN_1000_0E94_load_video_driver"); return 1; } // DUMMY
int  FUN_1000_0F2A_init_data_buffer(void) { puts("FUN_1000_0F2A_init_data_buffer"); return 1; } // DUMMY
     FUN_1000_0f46(int a, int b, int c, int d) { printf("FUN_1000_0f46(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_0F6E_image_data_transfer(int a, int b) { printf("FUN_1000_0F6E_image_data_transfer(%d,%d)\n", a, b); }

int  FUN_1000_0fae_load_file(char* file_name) { printf("FUN_1000_0FAE_load_file(%s)\n", file_name); return 1; }

     FUN_1000_0fdc_free_memory(int a) { printf("FUN_1000_0FDC_free_memory(%d)\n", a); }

// 1000
     FUN_1000_102e_unload_tileset(void) { puts("FUN_1000_102E_unload_tileset"); }
     FUN_1000_1044_buffer_image(int a, int b, int c, int d) { printf("FUN_1000_1044_buffer_image(%d,%d,%d,%d)\n", a, b, c, d); }
     FUN_1000_1068(int a, int b, int c) { printf("FUN_1000_1068(%d,%d,%d)\n", a, b, c); }
     FUN_1000_1158_init_timer(void) { puts("FUN_1000_1158_init_timer"); }
int  FUN_1000_1674_test_open_file(char* file_name) { printf("FUN_1000_1674_test_open_file(%s)\n", file_name); return 1; } // FMT
u8   FUN_1000_16a6_get_default_drive() { puts("FUN_1000_16a6_get_default_drive"); return 'C'; } // DUMMY

     // param: ES:DI
     FUN_1000_17f4_character_effects(int a, int b) { printf("FUN_1000_17f4_character_effects(%d,%d)\n", a, b); }
int  FUN_1000_1D02_load_character_set(char* a, int b) { printf("FUN_1000_1D02_load_character_set(%s,%d)\n", a, b); return 1; } // FMT
     FUN_1000_1DDA_wait_for_keystroke(int a) { printf("FUN_1000_1DDA_wait_for_keystroke(%d)\n", a); u5_getch(); }

void FUN_1000_1fa0_backspace(int x) { printf("FUN_1000_1fa0_backspace(%d)\n", x); }

// 2000

int  FUN_1000_256e_read_file_from_disk(char* file_name, void* addr, u16 size, u16 offset)
{
    printf("FUN_1000_256e_read_file_from_disk(%s,%d,%d,%d)\n", file_name, (u16)addr, size, offset);
    FILE_ReadFile(file_name, addr, size, offset);
}
     FUN_1000_25d8_write_file_to_disk(char* file_name, void* addr, u16 size) { printf("FUN_1000_25d8_write_file_to_disk(%s,%d,%d)\n", file_name, (u16)addr, size); }
     FUN_1000_251e_switch_disks(int x) { printf("FUN_1000_251e_switch_disks(%d)\n", x); }

// 3000
void FUN_1000_3072(void) { puts("FUN_1000_3072"); }

     FUN_1000_3522(int x, int y) { printf("FUN_1000_3522(%d,%d)\n", x, y); }
int  FUN_1000_3abe() { puts("FUN_1000_3abe"); }
     FUN_1000_3ae6(int a) { printf("FUN_1000_3ae6(%d)\n", a); }
     FUN_1000_3c9a_hole_up() { puts("FUN_1000_3c9a_hole_up"); }

// 4000
     FUN_1000_4080(int a) { printf("FUN_1000_4080(%d)\n", a); }
     FUN_1000_43ae(int a, int b, int c, int d) { printf("FUN_1000_43ae(%d,%d,%d,%d)\n", a, b, c, d); }

int  FUN_1000_4988(void) { puts("FUN_1000_4988"); }

     FUN_1000_4efc(void) { puts("FUN_1000_4efc"); }

// 5000

// 6000
     FUN_1000_6150_attack_monster(int a, int b) { printf("FUN_1000_6150_attack_monster(%d,%d)\n", a, b); }

     FUN_1000_6e60(int param_2, int param_1) { printf("FUN_1000_6e60(%d,%d)\n", param_2, param_1); }

// 7000

// MAX: < FUN_1000_7296
