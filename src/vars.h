#ifndef _VARS_H
#define _VARS_H

// ref: u5tech
// Savegame ref: https://wiki.ultimacodex.com/wiki/Ultima_V_internal_formats#SAVED.GAM_and_RAM

#include "structs.h"

// 103c..
// tlk word table

// 1300

extern u8 D_13a6[8]; // TODO: size?

extern u16 D_13ae; // color
extern u16 D_13b0_white_color;
extern u16 D_13b2_frame_color;
extern u16 D_13b4; // color
extern u16 D_13b6; // color
extern u16 D_13b8;
extern u16 D_13ba;

extern S_13bc D_13bc[0x30]; // 0x30? ~153c?

extern u16 D_153c[0x30];
extern u8 D_159c[0x30];
extern u8 D_15cc[0x30];
extern u8 D_15fc[0x30]; // ~162c) some equip table

extern u8 D_1634[0x30]; // ~1664) equip defense table
extern u8 D_1664[0x30]; // ~1694) some equip table
extern u8 D_169c[0x30]; // ~16cc) some equip table

extern u8 D_16d4[0x30]; // ~1704)
extern u8 D_1704[0x10]; // ~1704)
extern u8 D_1714[0x10]; // ~1714)
extern u8 D_1724[6]; // ~172a)
// gap 2
extern u8 D_172c[6]; // ~1732)
// gap 2
extern u8 D_1734[8];

extern u8 D_173c[8];
extern u8 D_1744[8];

extern char* D_17f6[0x30]; // Equipment names

extern char* D_1856[0x30]; // Job names

extern char* D_18b6[0x30]; // Foe names

// 1900
extern char* D_1916[0x26]; // Items
extern char* D_1962[56]; // Armaments
extern char* D_19d2[8]; // reagent names
extern char* D_19e2[48 + 1]; // spell names

// 1a00

extern char* D_1a44[10]; // Class/Jobs (Avatar, Mage, Bard, ...)
extern s16 D_1a58[9];
extern char* D_1a6a[5]; // Health (Good Health, Poisoned, ...)

extern u16 D_1a74[5]; // karma string offset
extern u8 D_1a7e[0x30]; // equipment type?
extern u8 D_1aae[0x30];
extern u8 D_1ade[9];
// gap 1
extern u8 D_1ae8[0x30];
extern u8 D_1b18[0xb0 + 0x33];
// gap 1
extern char* D_1bfc[26];

extern char* D_1c30[0x30]; // ~1c90)

extern u8 D_1c90[0x30];

extern u8 D_1cc0[0x30];
extern u16 D_1cf0[0x15];

extern u8 D_1d1a[0xff];

extern u8 D_1e19[0x21]; // map offset table ~1e3a)
extern char* D_1e3a[0x28]; // map name table ~1e8a)
extern u8 D_1e8a[0x28]; // ~1eb1) town position x
extern u8 D_1eb2[0x28]; // ~1ed9) town position y
extern u8 D_1eda[28 * 2]; // ~1f12) moon phase table?

extern u8 D_1f12[0x30]; // TODO: size, offset

extern u8 D_1f42[6];
extern u8 D_1f48[6];

extern char* D_1f4e[8];
extern char* D_1f5e[8]; // mantra
extern u8 D_1f6e[8];
extern u8 D_1f76[8];
extern PairS8 D_1f7e[0x100]; // ~217e) (x,y) * 0x100 (TODO: Pair)

extern s16 D_217e;
extern s16 D_2180;
extern s16 D_2182;
extern s16 D_2184;
extern u8 D_2186; // s8?

extern s8 D_2188[0x32]; // ~21ba) comsubs: some line table

extern u8 D_21ba[0x10]; // comsubs: some pixel drawing table

// shop related
extern char* D_21ca[8][16]; // shop name
extern char* D_22ca[8][16]; // shop owner
extern u8 D_23ca[8][16]; // shop to map id table

// dnglook
// 244a..24d6)
extern u8 D_244a[8];

extern u8 D_2452[6];
extern u8 D_2458[6];
extern u8 D_245e[6];
extern u8 D_2464[6];
extern u8 D_246a[6];
extern u8 D_2470[6];

extern u8 D_2476[0x10];
extern u8 D_2486[0x10];
extern u8 D_2496[0x10];
extern u8 D_24a6[0x10];
extern u8 D_24b6[0x10];
extern u8 D_24c6[0x10];
// ^ dnglook

extern s16 D_24d6[4]; // direction offset
extern s16 D_24de[4]; // direction offset

extern u8 D_24e6; // need to update map viewport?
extern u8 D_24e7; // footstep sfx related flag in dungeon

extern char* D_24ea[0x80]; // word table
extern char* D_25ea[30]; // ~2626) compressed file name table
#define D_25f0 (&D_25ea[3])

// 2652~2946) town

// 2946~: code strings

// 2900
// 29f5..2c57: mainout

// 2c58~: Entering room...

// dungeon
// 2c76~2f2c

// intro
// 2f98..3666

// 0x3105: "WD.BIT"

// 3000

// D_367e npc

// D_369e ~ D_3744 blckthrn

// D_3750 ~ D_3832 lookobj

// D_383a ~ D_385e dnglook

// D_3866 ~ D_3a26 outsubs

// D_3a32 ~ D_3d96 shoppes

// D_3da6 ~ D_3e60 endgame

// D_3e66 ~ D_41cc sjog

// D_444a ~ D_4512 cmds

// D_4592 ~ D_4892 cast

// D_4aa0 ~ D_4af5 talk

// D_4af6 ~ D_4c10 cast2

// D_4c1e ~ D_4d7a shoppes2

// D_4d7e ~ D_4e80 shoppes3

// D_50eb: font

// font?
extern u16 D_5146[2];
extern u16 D_514c[2];
extern u16 D_5150; // TODO: int?
extern u16 D_5152; // TODO: int?

extern u16 D_5154;
extern u16 D_5156;
extern u16 D_5158; // TODO: int?
extern u16 D_515a;

extern char* D_515c[4];

// 5200

extern u8 D_5164[8];
extern u8 D_516c[8];
extern u8 D_5174[8];
extern u16 D_517c[8][8];
extern u8 D_51fc[8];
extern u8 D_5204[8];
extern u8 D_520c; // = 0
// ^ font?

// Sounds
// cast2
extern u16 D_4af6[9]; // cast effect - freq
extern u16 D_4b08[9]; // cast effect - pulse width table
extern u16 D_4b1a[9]; // cast effect - pulse width table 2
extern u16 D_4b2c[9]; // cast effect - pulse increment

// cast2
extern u16 D_4be6[7];
extern u16 D_4bf4[7];
extern u16 D_4c02[7];
extern u16 D_4c10[7];

// harpsichord audio freqs
extern u16 D_2746[0xa];

// blackthorn
extern u16 D_3720[6]; // sound freq
extern u16 D_372c[6]; // sound dur
extern u16 D_3738[6]; // sound pulse width
extern s16 D_3744[6]; // sound pulse increment ~3750)

// apparition phrase freqs
extern u16 D_3a26[6];

// main parameters
// int D_52a2;     // __argc
// char** D_52a4;  // __argv
// char** D_52a6;  // environ

extern VideoDriverParams D_52ba_vdp;
#define D_52c8 D_52ba_vdp._52c8_videoDriverSelection

extern int D_52da_pen_color;

/* 52dc .. 52ee: unknown */

extern int D_52ef_forceEga; // force ega
extern int D_52f1_forceTandy; // force tandy
extern int D_52f3_forceHerc; // force herc

extern int D_52f6; // temp area?
extern int D_52f8; // temp area?

// ?
extern int D_52fa; // x1
extern int D_52fc; // y1
extern int D_52fe; // x2
extern int D_5300; // y2

// 5300
extern int D_5304; // previous video mode

extern u16 D_5306[7];
extern u16 D_5314[7];

// 5322..5327: "Tandy"
// 5328..532f: video driver string table
// 5330..5337: "CGA.DRV"
// 5338..533f: "EGA.DRV"
// 5340..5347: "T1K.DRV"
// 5348..534f: "HER.DRV"
extern void* FAR D_5350; // video driver pointer
extern u16 D_5354; // segment of video page buffer (ega: 0xa800, t1k: allocated memory)
extern u16 D_5356; // timer calibration
extern u16 D_5358; // memory size
extern u16 D_535a; // current timer value
extern u16 D_535c; // int21 error code

// 535e..537d
extern TextWindow D_535e_textWindows[4];

extern u16 D_5386_current_text_window_idx; // charset_id (offset in 539a, data in 53a4..53ab)
extern u16 D_5388_current_charset_idx; // selected charset idx
extern u16 D_538a; // bool: special keystroke
extern u16 D_538c; // use keyboard buffer?
extern u16 D_538e; // cursor advance flag
extern u16 D_5390; // keystroke cursor begin idx
extern u16 D_5392;
extern void (FAR *D_5394_fn)(void); // disk swap message function pointer
extern u8* FAR D_5398_currentCharset;        // ptr (segment) of current charset
extern TextWindow* D_539a_currentTextWindow; // address of current text window data
extern u8* FAR D_539c[4];    // charset ptr (segment) table
extern u16 D_53a4_underline; // underline flag (bit 0 of byte 7)
extern u16 D_53a6; // ? flag (bit 1 of byte 7)
extern u16 D_53a8_inverse; // inverse flag (bit 1 of byte 7)
extern u8  D_53aa_text_fg_color; // text fg color (lo nibble of byte 6)
extern u8  D_53ab_text_bg_color; // text bg color (hi nibble of byte 6)

//extern u16 D_53b4; // loaded file size (lsb)
//extern u16 D_53b6; // loaded file size (msb)

//extern u16 D_53b8; // file handle
//extern u16 D_53ba; // first allocated segment
//extern u16 D_53bc; // first allocated segment (for return)
//extern u16 D_53be; // second allocated segment (for lzw)

// u16 53c4: read pointer
// u16 53cc: 0x102
// u16 53d0: 0x200
// u16 53d2: read advance amount? (9)

// 53d6..53e8: "Out of Memory...\n$"

extern u8 D_53ea[24]; // ~5402) character data from charset file (herc=24, others=8)

extern s16 D_5402[5]; // 5402..540c) 1, 10, 100, 1000, 10000
extern u16 D_540c; // cursor anim idx // TODO: int
extern u8 D_540e[8]; // extended ascii code for arrow keys
extern u8 D_5416[8]; // special key table
extern u8 D_541e; // drive number
extern u16 D_5420; // random seed?
extern u16 D_5422;
extern u16 D_5424;
extern u16 D_5426[2]; // timer-related?

// 542a..5447: unknown

extern u16 D_5448; // current timer value
extern u16 D_544a; // timer tick count to wait
// far D_544c; // far addr of original int 1c handler

extern u8 D_545e;

// ...54d2: strings

// 5500
extern u8 D_54d4[32]; // normal walkable tile flag table
extern u8 D_54f4[64]; // some table. (party icon -> move type table)

extern u8 D_5544[4];

extern u8 D_559e[8]; // ~55a6)

// Savegame / User state
// 55a6 ~ 6606
// -> state.h
#include "state.h"

extern S_6608_Map D_6608_map; // ~6a08) map data: layer4 * y16 * x16 / y32 * x32
#define D_6608 D_6608_map.raw
#define D_6a07 (D_6608[1023])

extern S_6608_Map D_6708_map; // copy of 6608
#define D_6708 D_6708_map.raw

extern u8 D_6a08; // some audio related

extern u16 D_6a0a[5];

extern u8 D_6a14[0x20];

extern u8 D_6a34_u8;
extern u16 D_6a36[9]; // lute freq table

extern u8 D_6a48[0x35]; // iolo's lute song note table

extern u8 D_6a7e;

extern u8 D_6a80[6]; // light intensity slope?
extern u8 D_6a86[0x13]; // ~6a99)

extern u8 D_6a9a[10];

extern u16 D_6aa4;
extern u8 D_6aa8[0x24];

// a300

extern char D_a3e2[0xd];

//////// (static) data: ..a522]

// a500

extern u16 D_a524;
extern u8 D_a526;
extern u8 D_a527;

extern u8 D_a528[0x100];
extern u8 D_a628[0x100];
extern u8 D_a728[0x100];
extern u8 D_a872[0x100];

// a900

extern u8  D_a9bc;
extern u8 D_a9bd[2]; // drive idx
extern u8* D_a9c0; // loaded image pointer
extern u8 D_a9c2;
extern u8* D_a9c4; // loaded image pointer
extern u8* D_a9c6; // loaded image pointer

// disk drive table
extern u8 D_a9c8[6];

#define D_a9c9 D_a9c8[1]
#define D_a9ca D_a9c8[2]
#define D_a9cb D_a9c8[3]
#define D_a9cc D_a9c8[4]
#define D_a9cd D_a9c8[5]

// used in intro
extern u8 D_a9ce; // use sound effect?

extern u16 D_a9d0[0x15];

extern u8 D_a9fa; // dirty flag for vital
extern u8 D_a9fb; // footstep sfx duration in dungeon

// combat?
extern ActorFmt D_a9fc[0x20];

extern char* D_aafc; // current shop name
extern char* D_aafe; // current shop owner

extern char* D_ab00;
extern u8 D_ab02[0x160]; // current visible map viewport [b * b], stride 0x20. 0: actor overlay, 0xff: hidden [ab02..ac62)
extern char* D_ac62;

extern u8 D_ac64[0xb0]; // actor map / misc map [0x10 * b] (from 51b8)

extern u8 D_ad14[32 * 32]; // combat map data / misc [ad14..b114)

// b100

extern s16 D_b114; // s16 (FMT MOVSX) max: 0x10?
extern s16 D_b116; // s16 (FMT MOVSX)
extern s16 D_b118; // s16 (FMT MOVSX)
extern u16 D_b11a;

extern u8* D_b11c;
extern u8 D_b11e[0x100]; // animated tile lookup table
extern u8 D_b21e[2000]; // 2000 byte scratch ~b9ee)

#define D_b31e (D_b21e + 0x100)
#define D_b7fa (D_b21e + 1500)

// b900

extern u8  D_b9ee[0x26]; // owned item counts
// [8]
#define D_b9f6 (D_b9ee + 8)
#define D_b9fe D_b9ee[0x10]
#define D_b9ff D_b9ee[0x11]
#define D_ba00 D_b9ee[0x12]
#define D_ba01 D_b9ee[0x13]
#define D_ba02 D_b9ee[0x14]
// [8]
#define D_ba03 (D_b9ee + 0x15)
// [3]
#define D_ba0b (D_b9ee + 0x1d)
#define D_ba0e D_b9ee[0x20]
#define D_ba0f D_b9ee[0x21]
#define D_ba10 D_b9ee[0x22]
#define D_ba11 D_b9ee[0x23]
#define D_ba12 D_b9ee[0x24]
#define D_ba13 D_b9ee[0x25]

extern CombatEntity D_ba14[32]; // combat entities

extern u8  D_bb14; // 0x4f or 0x4d (tile)
extern u8  D_bb15; // 0x45 or 5 (tile)
extern u8  D_bb16;
extern u8  D_bb17;
extern u16 D_bb18; // "lord british" index
extern void* D_bb1a; // pointer

extern S_bb1c D_bb1c;

extern S_bc88_U4Party D_bc88;

extern char D_bcb2[0x27 + 1];

extern u8 D_bd2a[8];
extern u8 D_bd32[8];

extern u8 D_bcda;

extern u16 D_bcdc;
extern u8* D_bcde; // pointer
extern u8 D_bce0[4]; // ?
extern char D_bce4[0x10];
extern u8 D_bcf4;
extern u16 D_bcf6;
extern char D_bcf8[16];

extern char D_bd08[12];

extern u8 D_bd15;
extern u8 D_bd16;
extern s16 D_bd18; // int?
extern int D_bd1a; // int
extern int D_bd1c; // int
extern int D_bd1e; // int
extern s16 D_bd20; // int?
extern s16 D_bd22;
extern s16 D_bd24;

extern u8 D_bd26;
extern u8 D_bd27;
extern u8 D_bd28;
extern u8 D_bd29;

extern u8 D_bd3c;
extern u8 D_bd3d;
extern u8 D_bd3e;

// ..bd3f]

#endif
