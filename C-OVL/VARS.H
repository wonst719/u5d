#ifndef _VARS_H
#define _VARS_H

#ifndef STUB
#define STUB extern
#endif

// ref: u5tech
// Savegame ref: https://wiki.ultimacodex.com/wiki/Ultima_V_internal_formats#SAVED.GAM_and_RAM

#include "STRUCTS.H"

// 103c..
// tlk word table

// 1300

STUB u8 D_13a6[8]; // TODO: size?

STUB u16 D_13ae; // color
STUB u16 D_13b0_white_color;
STUB u16 D_13b2_frame_color;
STUB u16 D_13b4; // color
STUB u16 D_13b6; // color
STUB u16 D_13b8;
STUB u16 D_13ba;

#pragma pack(push, 1)
/* size: 0x8 */
typedef struct S_13bc // ?
{
    u8 _0;	// 13bc / 3f050
    u8 _1;	// 13bd
    u8 _2;	// 13be / 3f052
    u8 _3;	// 13bf
    u8 _4;	// 13c0
    u8 _5;	// 13c1 / 3f055
    u8 _6;	// 13c2
    u8 _7;	// 13c3
} S_13bc;
#pragma pack(pop)

STUB S_13bc D_13bc[0x30]; // 0x30? ~153c?

STUB u16 D_153c[0x30];
STUB u8 D_159c[0x30];
STUB u8 D_15cc[0x30];
STUB u8 D_15fc[0x30]; // ~162c)

STUB u8 D_169c[0x10]; // TODO: position, size

// TODO: size
STUB u8 D_1664[0x70]; // ~16d4)
// TODO: size
STUB u8 D_16d4[0x100]; // ~17d4)
STUB u8* D_1704;
STUB u8* D_1714;
STUB u8* D_1724;
STUB u8* D_172c;
//STUB u8 D_16d4[0x10]; // TODO: size == 0x100?, combine arrays?
//STUB u8 D_1704[0x10]; // NOTE: combine arrays?
//STUB u8 D_1714[0x10];
//STUB u8 D_1724[6];
//STUB u8 D_172c[6];

STUB char* D_17f6[0x30]; // Equipment names TODO: size

STUB char* D_1856[0x30]; // TODO: size

STUB char* D_18b6[0x30]; // foe names

// 1900
STUB char* D_1916[8]; // Scrolls
STUB char* D_1962[56]; // Item: Leath Helm, Chain Coif, ...
STUB char* D_19B2; // TODO
STUB char* D_19D2[1];
STUB char* D_19E2[1];

// 1a00

STUB char* D_1A44[10]; // Class/Jobs (Avatar, Mage, Bard, ...)
STUB int D_1A58[1];
STUB char* D_1A6A[5]; // Health (Good Health, Poisoned, ...)
STUB u16 D_1a74[5]; // karma string offset
STUB char D_1A7E[1];
STUB byte D_1AAE[1];
STUB char D_1ade[9]; // TODO: size. 9? 10?
// gap 1?
STUB byte D_1AE8[1];

STUB u8 D_1b18[0xb0];
STUB u8 D_1bc8[0x33]; // TODO: size? (min.33)

STUB u8 D_1e19[0x21]; // map offset table ~1e3a)
STUB char* D_1e3a[0x28]; // map name table ~1e8a)
STUB u8 D_1e8a[0x28]; // ~1eb1) ?? x?
#define D_1e89 (D_1e8a - 1)
STUB u8 D_1eb2[0x28]; // ~1ed9) ?? y?
#define D_1eb1 (D_1eb2 - 1)
STUB u8 D_1eda[28 * 2]; // ~1f12) moon phase table? TODO: offset?

STUB char* D_1f4e[8]; // size
// 1f5e string x8
STUB u8 D_1f6e[8];
STUB u8 D_1f76[8];
STUB u8 D_1f7e[0x200]; // ~217e)

STUB s16 D_217e;
STUB s16 D_2180;
STUB s16 D_2182;
STUB s16 D_2184;
STUB u8 D_2186;

STUB u8 D_2188[0x10]; // TODO: size
STUB u8 D_2198[0x10]; // TODO: size

STUB u8 D_21ba[0x10];

// 2500
STUB u8 D_24e6; // light intensity is changed? (?)
// some table from 24ea..2625
// defined from assembly?
STUB char* D_24ea[0x80];
STUB char* D_25ea[30]; // ~2626) PROPORT.PCS / BRITISH.BIT / TITLE.BIT / TILES.16 / ITEMS.16 / DNG1.16 / ...
#define D_25f0 (&D_25ea[3])

STUB char* D_2652[4]; // town dat names

STUB u8 D_2742[4]; // TODO: size?

STUB u8 D_28c2_raw[0x80]; // TODO: size
STUB u32* D_28c2; // TODO

// 2900
STUB u8 D_29f5[4]; // wind-releated
STUB u8 D_29f9[4]; // wind-releated

STUB u8 D_2bc0[0xc];
STUB u8 D_2bcc[0x8];
STUB u8 D_2bd4[0x6];
STUB u8 D_2bda[0x2];

STUB u8 D_2bdc[0xc];
STUB u8 D_2be8[0x8];
STUB u8 D_2bf0[0x6];
STUB u8 D_2bf6[0x2];

STUB u16 D_2bf8[0x60]; // ~2c58)? TODO: size

// 2c58~: Entering room...

//
STUB u8 D_2c55;
// 
STUB u8 D_2c57;

// 3000

STUB u16 D_3720[6];
STUB u16 D_372c[6];
STUB u16 D_3738[6];
STUB s16 D_3744[6]; // ~3750)

STUB u8 D_3750[8];
STUB u8 D_3758[8];
STUB u8 D_3760[0xb0]; // ~3810)

STUB u8 D_3812[16]; // ~3822) ? TODO: size?
STUB u8 D_3822[16]; // ~3832) ?

STUB u8 D_3866[8]; // ~386e)
STUB u8 D_386e[8]; // ~3876)
STUB u8 D_3876[0x100]; // ~3976) TODO: size?

STUB u8 D_3a06[3];
STUB u8 D_3a0a[3];
STUB u8 D_3a0e[3];

STUB u8 D_3a26[0xc];

// 4100
STUB u8 D_4124[8];
STUB u8 D_412c[8];
STUB u8 D_4134[8];

STUB u8 D_413c[0x30];
STUB u8 D_416c[0x30]; // ~419c)

STUB char* D_4aa0[4];
STUB char* D_4aa8[0x22+1];
// 4aec: "ELECTRONIC ARTS"

// talk related
STUB u8 D_4aee;
STUB u8 D_4aef;
STUB u8 D_4af0;
STUB u8 D_4af1;
STUB u8 D_4af2;
STUB u8 D_4af3;
STUB u8 D_4af4;
STUB u8 D_4af5;

// 5200

STUB u16 D_52c8;

// main parameters
STUB int D_52a2;     // argc
STUB char** D_52a4;  // argv
STUB char** D_52a6;   // envp

typedef struct VideoDriverParams
{
    int _52ba_forceCga;         // 52ba 0
    int _52bc;                  // 52bc 2
    int _52be;                  // 52be 4
    int _52c0;                  // 52c0
    int _52c2;                  // 52c2
    int _52c4;                  // 52c4
    int _52c6;                  // 52c6
    int _52c8_videoDriverSelection; // 52c8: video driver selection (0=cga, 1=ega, 2=tandy, 3=herc, ffff=none)
    int _52ca_machineType;      // 52ca: machine type (0=pcjr, 2=ibm, 3=tandy, 6=other)
    int _52cc_penX;             // 52cc
    int _52ce_penY;             // 52ce
    int _52d0;                  // 52d0: clip_window_x1?
    int _52d2;                  // 52d2: clip_window_x2?
    int _52d4;                  // 52d4: clip_window_y1?
    int _52d6;                  // 52d6: clip_window_y2?
    int _52d8_useBuffer;        // 52d8 1e
} VideoDriverParams;            // size: 0x20?

STUB VideoDriverParams D_52ba_vdp;

STUB int D_52da_pen_color;

STUB int D_52ec;

STUB int D_52ef; // force ega
STUB int D_52f1_forceTandy; // force tandy
STUB int D_52f3; // force herc

STUB int D_52f6; // temp area?
STUB int D_52f8; // temp area?

// ?
STUB int D_52fa; // x1
STUB int D_52fc; // y1
STUB int D_52fe; // x2
STUB int D_5300; // y2

// 5300
STUB int D_5304; // previous video mode

// 5322..5327: "Tandy"
// 5328..532f: video driver string table
// 5330..5337: "CGA.DRV"
// 5338..533f: "EGA.DRV"
// 5340..5347: "T1K.DRV"
// 5348..534f: "HER.DRV"
STUB void* far D_5350; // video driver pointer
STUB u16 D_5354; // segment of 3rd part of video buffer (a800)
STUB u16 D_5356; // timer calibration
STUB u16 D_5358; // memory size
STUB u16 D_535a; // current timer value
STUB u16 D_535c; // int21 error code

typedef struct TextWindow
{
    u8 left;   // 0
    u8 top;    // 1
    u8 right;  // 2
    u8 bottom; // 3
    u8 current_x; // 4
    u8 current_y; // 5
    u8 text_colors;  // 6; hi: bg, lo: fg
    u8 text_effects; // 7; flags: bits 0..2
} TextWindow;

// 535e..537d
TextWindow D_535e_textWindows[4];

STUB u16 D_5386_currentCharset; // charset_id (offset in 539a, data in 53a4..53ab)
STUB u16 D_5388; // charset_seg (in 5398)
STUB u16 D_538a; // bool: special keystroke
STUB u16 D_538c; // ? (keystroke)
STUB u16 D_538e; // cursor advance flag
STUB u16 D_5390; // ? (1b38)
STUB u16 D_5392;
STUB u16 D_5394; // far address for disk swap message
STUB u16 D_5396; // (far segment for disk swap message)
STUB u16 D_5398; // segment of current charset
STUB TextWindow* D_539a_textWinForCurrCharset; // address of text window data for current charset
STUB u16 D_539c[4]; // charset segment table
STUB u16 D_53a4_underline; // underline flag (bit 0 of byte 7)
STUB u16 D_53a6; // ? flag (bit 1 of byte 7)
STUB u16 D_53a8_inverse; // inverse flag (bit 1 of byte 7)
STUB u8  D_53aa_text_bg_color; // text bg color (lo nibble of byte 6)
STUB u8  D_53ab_text_fg_color; // text fg color (hi nibble of byte 6)

STUB u16 D_53b8; // file handle
STUB u16 D_53ba; // first allocated segment (for return)
STUB u16 D_53bc; // first allocated segment
STUB u16 D_53be; // second allocated segment

// u16 53c4: read pointer
// u16 53cc: 0x102
// u16 53d0: 0x200
// u16 53d2: read advance amount? (9)

// 53d6..53e8: "Out of Memory...\n$"

STUB u8 D_53ea[24]; // ~5402) character data from charset file (herc=24, others=8)
STUB s16 D_5402[5]; // 5402..540c) 1, 10, 100, 1000, 10000
STUB u16 D_540c; // cursor?
STUB u8 D_540e[8]; // bios key scan code table
STUB u8 D_5416[8]; // special key table
STUB u8 D_541e; // drive number
STUB u16 D_5420; // random seed?
STUB u16 D_5422;
STUB u16 D_5424;
STUB u16 D_5426[2]; // timer-related?

STUB u16 D_5448; // current timer value
STUB u16 D_544a; // timer tick count to wait
// far D_544c; // far addr of original int 1c handler

STUB u8 D_545e;

// 5460..5479: "Please insert the Ultima "
// 547a..547c: "V "
// ...54d2: strings

// 5500
STUB u8 D_54d4[32]; // normal walkable tile flag table
STUB u8 D_54f4[32]; // some table. TODO: size? 64? (party icon -> move type table)

STUB u8 D_5544[4];

STUB u8 D_559e[8]; // ~55a6)

//
// Savegame / User state
// 

// [55a6..6606): savegame (0x1060)
STUB u16 D_55a6;    // +0x0

STUB S_55a8 D_55a8_party[0x10]; // ~57a8)

// 5700
STUB u16 D_57a8;        // +0x0202 Food
STUB u16 D_57aa;        // +0x0204 Gold
STUB u8  D_57ac;        // +0x0206 #Keys
STUB u8  D_57ad;        // +0x0207 #Gems
STUB u8  D_57ae;        // +0x0208 #Torches
STUB u8  D_57af;        // +0x0209 Grapple
STUB u8  D_57b0;        // +0x020A #Magic Carpets
STUB u8  D_57b1;        // +0x020B #Skull Keys
STUB u8  D_57b2;        // +0x020C Last day Minoc skull keys were taken
STUB u8  D_57b3;        // +0x020D Amulet of Lord British
STUB u8  D_57b4;        // +0x020E Crown of Lord British
STUB u8  D_57b5;        // +0x020F Sceptre of Lord British
STUB u8  D_57b6[4];     // +0x0210 Shards   // [57b6..57ba)
STUB u8  D_57ba;        // +0x0214 #Spy Glass
STUB u8  D_57bb;        // +0x0215 HMS Cape Plans
STUB u8  D_57bc;        // +0x0216 #Sextant
STUB u8  D_57bd;        // +0x0217 Pocket Watch
STUB u8  D_57be;        // +0x0218 Black Badge
STUB u8  D_57bf;        // +0x0219 Sandalwood Box
// FMT pad 2byte (?)
STUB u8  D_57c0[0x30];  // +0x021A Equipment(Quantity owned by the party) [57c0..57f0)
#define D_57db D_57c0[0x1b] /* +0x0235 Arrows */
#define D_57dd D_57c0[0x1d] /* +0x0237 Quarrels */
STUB u8  D_57f0[0x30];  // +0x024A Spell Mixtures [57f0..5820)

// 5800
STUB u8  D_5820[8];     // +0x027A Scrolls
STUB u8  D_5828[8];     // +0x0282 Potions (Blue, Yellow, Red, Green, Orange, Purple, Black, White)
STUB u8  D_5830[8];     // +0x028A 0-0xFF Moonstone X-coordinates (valid only if buried)
STUB u8  D_5838[8];     // +0x0292 0-0xFF Moonstone Y-coordinates (valid only if buried)
STUB u8  D_5840[8];     // +0x029A 0=buried,0xFF=Inventory moonstone flags
STUB u8  D_5848[8];     // +0x02A2 0=Britannia,0xFF=Underworld moonstone Z-coordinates (valid only if buried)
STUB u8  D_5850[8];     // +0x02AA Reagents (A..H)
STUB u8  D_5858[3];     // +0x02B2 Day each of the three nightshade/mandrake spots was last harvested [5858..585b)
STUB u8  D_585b;        // +0x02B5 party member count
STUB u8  D_585c[0x18];  // [585c..5874)
STUB u16 D_5874;        // +0x02CE Current year
STUB s16 D_5876;        // selected x direction? // +0x02D0 first party member that is not dead or sleeping? # of active monsters & charmed PCs[2]?
STUB s16 D_5878;        // selected y direction? // +0x02D2 # of active PCs and charmed monsters[2]?
STUB u8  D_587a;        // +0x02D4 Icon
STUB u8  D_587b;        // +0x02D5 Active character
STUB u8  D_587c;        // +0x02D6 party icon (13=horse, 14=carpet, 1c=avatar, 24=frigate, 28=skiff)
STUB u8  D_587d;        // +0x02D7 Current month
STUB u8  D_587e;        // +0x02D8 Current day
STUB u8  D_587f;        // +0x02D9 Current hour
STUB u8  D_5880;        // +0x02DA copy of 0x2D9
STUB u8  D_5881;        // +0x02DB Current minute
STUB u8  D_5882;
STUB u8  D_5883;        // ?
STUB u8  D_5884;
STUB u8  D_5885;        // +0x02DF Phase of Trammel
STUB u8  D_5886;        // +0x02E0 Phase of Felucca
STUB u8  D_5887;        // +0x02E1 Current moongate height (in pixels)
STUB u8  D_5888;        // +0x02E2 Karma
STUB u8  D_5889;
STUB u8  D_588a;
STUB u8  D_588b;        // +0x02E5 Current turn count
STUB u8  D_588c;
STUB u8  D_588d;
STUB u8  D_588e;        // +0x02E8 Protective spell duration
STUB u8  D_588f;
STUB u8  D_5890;
STUB u8  D_5891;            // +0x02EB animate flag
STUB u8  D_5892_wind_dir;   // +0x02EC wind direction
STUB u8  D_5893_map_id;     // +0x02ED map_id (21h~: dungeon, 40: unloaded)
STUB u8  D_5894;            // +0x02EE Combat backup of 0x2ED
STUB u8  D_5895_map_level;  // +0x02EF level (depth)
STUB u8  D_5896_map_x;      // +0x02F0 map_x
STUB u8  D_5897_map_y;      // +0x02F1 map_y
STUB u8  D_5898;            // crosshair visible
STUB u8  D_5899;            // crosshair x
STUB u8  D_589a;            // crosshair y
STUB u8  D_589b;            // x upper left chunk
STUB u8  D_589c;            // y upper left chunk
STUB u8  D_589d;            // +0x02F7 Attacker's weapon
STUB u8  D_589e;            // +0x02F8 ?
STUB u8  D_589f;            // +0x02F9 show focus rectangle & crosshair?
STUB u8  D_58a0;            // +0x02FA exit direction from combat map
STUB u8  D_58a1;            // +0x02FB combat type flags
STUB u8  D_58a2;
STUB u8  D_58a3;            // +0x02FD battle successful flag (win?)
STUB u8  D_58a4;            // +0x02FE Update/animate 2D map?
STUB u8  D_58a5;            // +0x02FF Current light intensity
STUB u8  D_58a6;
STUB u8  D_58a7;
STUB u8  D_58a8[0x20];  // [58a8..58c8)
STUB u8  D_58c8[3];     // 58cb)
STUB u8  D_58cb;
STUB u16 D_58cc;
STUB u16 D_58ce;
STUB u8  D_58d0[8];
STUB u8  D_58d8[8];
STUB u8  D_58e0[0xe];   // ..58ee)
STUB u8  D_58ee[0x20];  // ..590e)
// 5900
STUB u8  D_590e[0x20];  // ..592e)
STUB u8  D_592e[0x20];  // .594e)
STUB u8  D_594e;
STUB u8  D_594f;        // +0x03A9 opened door
STUB u8  D_5950;        // +0x03AA open_door_x
STUB u8  D_5951;        // +0x03AB open_door_y
STUB u8  D_5952;        // +0x03AC # of turns the door stays open
STUB u8  D_5953;        // +0x03AD ship_x
STUB u8  D_5954;        // +0x03AE ship_y
STUB u8  D_5955;
STUB u8  D_5956;
STUB u8  D_5957;        // +0x03B1 remaining drunk turn count (TOWN_0dc4)
STUB u8  D_5958;
STUB u8  D_5959;
STUB u8 D_595a[0x200];  // +0x03B4 map data ..5b5a)
// 5b00
STUB u8 D_5b5a[0x80];   // +0x05B4 NPC killed flags (4 bytes / 32 bits per settlement) [..5bda)
STUB u8 D_5bda[0x80];   // +0x0634 NPC met flags (4 bytes / 32 bits per settlement) [..5c5a)

// 5c00
typedef struct ActorFmt // D_5c5a..
{
    u8 _0_tile;
    u8 _1;
    u8 _2_x;
    u8 _3_y;
    u8 _4_z;
    u8 _5;
    u8 _6;
    u8 _7;
} ActorFmt;

STUB ActorFmt D_5c5a[32]; // ~5d5a)
// 5d00
STUB u16 D_5d5a;
STUB u16 D_5d5c;

typedef struct NpcScheduleFmt
{
    u8 _0[3]; // type
    u8 _3[3]; // x
    u8 _6[3]; // y
    u8 _9[3]; // z (s8?)
    u8 _c[4]; // time
} NpcScheduleFmt;

STUB NpcScheduleFmt D_5d5e[32];  // +0x07B8 NPC Schedules [..5f5e) 0x200

// 5f00

// Character (npc) / monster
// TODO: field
typedef struct NpcFmt
{
    u16 _0;
    u16 _2;
    u16 _4;
    u16 _6;
    u16 _8;
    u16 _a;
    u16 _c;
    u16 _e;
} NpcFmt;

STUB NpcFmt D_5f5e[32];  // +0x09B8 Character/monster states (16bytes * 32) [..615e) 0x200

// 6100

typedef struct MovementFmt
{
    u8 data[0x20];
} MovementFmt;

STUB MovementFmt D_615e[0x20];  // +0x0BB8 Movement list table [..655e)
//STUB u8 D_615e[0x400];

// D_655e: s16?
STUB u16 D_655e[0x20];   // +0x0FB8 Movement list pointers [..659e)
STUB u8 D_659e[0x20];   // +0x0FF8 NPC types [..65be)
STUB u8 D_65be;
STUB u8 D_65bf;
STUB u16 D_65c0;
STUB u16 D_65c2[0x20];
// 6600
STUB u8 D_6602;
STUB u8 D_6603;         // +0x105D orientation in a dungeon
STUB u8 D_6604;         // +0x105E graphics for the current dungeon
STUB u8 D_6605;         // +0x105F purchased ship/skiff
STUB u16 D_6606; // end

//
STUB u8 D_6608[1024]; // ~6a08) layer4 * y16 * x16 / y32 * x32
#define D_6a07 (&D_6608[1023])

STUB u8 D_6a08;

STUB u8 D_6a14[0x20];

STUB u8 D_6a34;

STUB u8 D_6a48[1]; // TODO

STUB u8 D_6a7e;

STUB u8 D_6a80[6]; // light intensity slope?
STUB u8 D_6a86[0x13]; // ~6a99)

STUB u8 D_6a9a[10];

STUB u16 D_6aa4;
STUB u8 D_6aa8[0x24];

// a300

STUB char D_a3e2[0xd];

//////// (static) data: ..a522]

// a500

STUB u16 D_a524;


STUB u8 D_a728[0x100];
STUB u8 D_a872[0x100];

// a900

STUB u8  D_a9bc;
STUB u16 D_a9bd; // drive idx
STUB u16 D_a9be;
STUB u16 D_a9c2;
// disk drive table
STUB u8  D_a9c8; // actual current disk drive letter
STUB u8  D_a9c9; // adjusted disk drive letter, 0xff: floppy
STUB u8  D_a9ca; // adjusted disk drive letter, 0xff: floppy
STUB u8  D_a9cb; // floppy (0xff)
STUB u8  D_a9cc; // unused
STUB u8  D_a9cd; // adjusted disk drive letter, 0xff: floppy

// used in intro
STUB u8 D_a9ce; // use sound effect?

STUB u8 D_a9fa;

// combat?
STUB ActorFmt D_a9fc[0x20]; // TODO: type

STUB u8 D_ab02[0x160]; // copied map data? [ab02..ac62)
STUB u16 D_ac62; // ?
STUB u8 D_ac64[0xb0]; // npc map? size? (from 51b8)
STUB u8 D_ad14[32 * 32]; // combat map data? size? [ad14..b114)?

// b100

STUB u16 D_b11c;
STUB u8 D_b11e[0x100];
STUB u8 D_b21e[2000]; // TODO: size? 2000? 0x200? scratch?
#define D_b31e (D_b21e + 0x100)

// b900

STUB u8  D_b9ee[8];
STUB u8  D_b9f6[8];
STUB u8  D_b9fe;
STUB u8  D_b9ff;

// ba00

STUB u8  D_ba00;
STUB u8  D_ba01;
STUB u8  D_ba02;
STUB u8  D_ba03[8];
STUB u8  D_ba0b[3];
STUB u8  D_ba0e;
STUB u8  D_ba0f;
STUB u8  D_ba10;
STUB u8  D_ba11;
STUB u8  D_ba12;
STUB u8  D_ba13;

#pragma pack(push, 1)
/* size: 0x8 */
typedef struct S_ba14
{
    u8 _0;	// ba14
    u8 _1;	// ba15
    u8 _2;	// ba16
    u8 _3;	// ba17
    u8 _4;	// ba18
    u8 _5;	// ba19
    u8 _6;	// ba1a
    u8 _7;	// ba1b
} S_ba14;
#pragma pack(pop)

STUB S_ba14 D_ba14[32]; // struct array

STUB u8  D_bb14; // pos?
STUB u8  D_bb15; // pos?
STUB u8  D_bb16;
STUB u8  D_bb17;
STUB u16 D_bb18;
STUB u16 D_bb1a;

STUB u16 D_bcdc;
STUB char* D_bcde;
STUB char D_bce4[0x10];
STUB u8 D_bcf4;
STUB u16 D_bcf6;
STUB char D_bcf8[16];

// ..bd3f]

#endif
