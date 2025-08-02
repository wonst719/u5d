#ifndef _FUNCS_H
#define _FUNCS_H

extern int FUN_1000_2032_to_upper(unsigned int x);

extern u8 FUN_1000_16a6_get_default_drive();

extern INTRO_intro_main();

extern MAINOUT_0d22();

extern TOWN_main1_11f0(int x);
extern TOWN_main2_141e();

extern DUNGEON_0e2e(int x);

extern char* OUTSUBS_get_world_savefile_0348();

extern FUN_1000_2900_update_vitals();
extern FUN_1000_251e_switch_disks(int x);

extern int FUN_1000_1674_test_open_file(char* file_name);
extern FUN_1000_256e_read_file_from_disk(char* file_name, u16 addr, u16 size, u16 a);
extern FUN_1000_25d8_write_file_to_disk(char* file_name, u16 addr, u16 size);

extern FUN_1000_0878_set_old_video_mode();

extern void FUN_1000_16ba(int);
extern void FUN_1000_1850(char *); // print_string
extern void FUN_1000_1a3e(int, int, int);
extern void FUN_1000_1c22(int, int, int, int, int);
extern int FUN_1000_1cee();
extern void FUN_1000_1bf2(int, int);
extern void FUN_1000_16ba(int);

extern int FUN_1000_2d7a(/*?*/);
extern void FUN_1000_4daa();
extern void FUN_1000_4e50(void *);

#endif
