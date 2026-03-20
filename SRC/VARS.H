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
STUB u8 D_15fc[0x30]; // ~162c) some equip table

STUB u8 D_1664[0x30]; // ~1694) some equip table
STUB u8 D_169c[0x30]; // ~16cc) some equip table

STUB u8 D_16d4[0x30]; // ~1704)
STUB u8 D_1704[0x10]; // ~1704)
STUB u8 D_1714[0x10]; // ~1714)
STUB u8 D_1724[6]; // ~172a)
// gap 2
STUB u8 D_172c[6]; // ~1732)
// gap 2
STUB u8 D_1734[8];

STUB u8 D_173c[8];
STUB u8 D_1744[8];

STUB char* D_17f6[0x30]; // Equipment names

STUB char* D_1856[0x30]; // Job names

STUB char* D_18b6[0x30]; // Foe names

// 1900
STUB char* D_1916[8]; // Scrolls
STUB char* D_1962[56]; // Item: Leath Helm, Chain Coif, ...
STUB char* D_19b2[8];
STUB char* D_19d2[8]; // reagent names
STUB char* D_19e2[48 + 1];

// 1a00

STUB char* D_1a44[10]; // Class/Jobs (Avatar, Mage, Bard, ...)
STUB u16 D_1a58[9];
STUB char* D_1a6a[5]; // Health (Good Health, Poisoned, ...)
STUB u16 D_1a74[5]; // karma string offset
STUB u8 D_1a7e[0x30]; // equipment type?
STUB u8 D_1aae[0x30];
STUB u8 D_1ade[9];
// gap 1
STUB u8 D_1ae8[0x30];
STUB u8 D_1b18[0xb0 + 0x33];
// gap 1
STUB char* D_1bfc[26];

STUB char* D_1c30[0x30]; // ~1c90)

STUB u8 D_1c90[0x30];

STUB u8 D_1cc0[0x30];
STUB u16 D_1cf0[0x15];

STUB u8 D_1e19[0x21]; // map offset table ~1e3a)
STUB char* D_1e3a[0x28]; // map name table ~1e8a)
STUB u8 D_1e8a[0x28]; // ~1eb1) ?? x?
STUB u8 D_1eb2[0x28]; // ~1ed9) ?? y?
STUB u8 D_1eda[28 * 2]; // ~1f12) moon phase table?

STUB u8 D_1f12[0x30]; // TODO: size, offset

STUB u8 D_1f42[6];
STUB u8 D_1f48[6];

STUB char* D_1f4e[8];
STUB char* D_1f5e[8]; // mantra
STUB u8 D_1f6e[8];
STUB u8 D_1f76[8];
STUB u8 D_1f7e[0x200]; // ~217e) (x,y) * 0x100

STUB s16 D_217e;
STUB s16 D_2180;
STUB s16 D_2182;
STUB s16 D_2184;
STUB u8 D_2186; // s8?

STUB s8 D_2188[0x32]; // ~21ba) some line table

STUB u8 D_21ba[0x10]; // some pixel drawing table

// shop related
STUB char* D_21ca[0x80]; // shop name?
STUB char* D_22ca[0x80]; // shop owner?
STUB u8 D_23ca[0x80];

// TODO: overlapping
STUB u16 D_21e6;

// 2500

STUB u8 D_244a[8];
STUB u8 D_2452[6];
STUB u8 D_2458[6];
STUB u8 D_245e[6];
STUB u8 D_2464[6];
STUB u8 D_246a[6];
STUB u8 D_2470[6];
STUB u8 D_2476[0x10];
STUB u8 D_2486[0x10];
STUB u8 D_2496[0x10];
STUB u8 D_24a6[0x10];
STUB u8 D_24b6[0x10];
STUB u8 D_24c6[0x10];

STUB s16 D_24d6[4]; // direction offset
STUB s16 D_24de[4]; // direction offset

STUB u8 D_24e6; // need to update map viewport?
STUB u8 D_24e7;

// some table from 24ea..2625
// defined from assembly?
STUB char* D_24ea[0x80];
STUB char* D_25ea[30]; // ~2626) compressed file name table
#define D_25f0 (&D_25ea[3])

STUB char* D_2652[4]; // town dat names

STUB u8 D_2742[4];
STUB u16 D_2746[0xa]; // some audio freqs
STUB u8 D_275a[0xd];
STUB u8 D_2767;

STUB char* D_27dc[3];

STUB u32 D_28c6[0x20]; // ~2946)

// 2946~: code strings

// 2900
STUB u8 D_29f5[4]; // wind-releated
STUB u8 D_29f9[4]; // wind-releated

// ...code strings...

STUB u8 D_2bc0[0xc];
STUB u8 D_2bcc[0x8];
STUB u8 D_2bd4[0x6];
STUB u8 D_2bda[0x2];

STUB u8 D_2bdc[0xc];
STUB u8 D_2be8[0x8];
STUB u8 D_2bf0[0x6];
STUB u8 D_2bf6[0x2];

STUB u16 D_2bf8[0x10];
STUB u8 D_2c18[0x3c];

// 2c58~: Entering room...

// u8 2c54
STUB u8 D_2c55;
// u8 2c56
STUB u8 D_2c57;

STUB u8 D_2c76[6]; // TODO: size

STUB u8 D_2de8[8];
STUB u8 D_2df0[8];
STUB u8 D_2df8[12];
STUB u8 D_2e04[12];
STUB char* D_2e10[11];

STUB u8 D_2e26[4];
STUB u16 D_2e2a[4]; // int
STUB u16 D_2e32[8]; // int
STUB u16 D_2e42[4]; // int
STUB u16 D_2e4a[4]; // int
STUB u16 D_2e52[4]; // int
STUB u16 D_2e5a[4]; // int
STUB u16 D_2e62[8]; // int
STUB u16 D_2e72[4]; // int
STUB u16 D_2e7a[4]; // int
STUB u16 D_2e82[4]; // int
STUB u8 D_2e8a[6]; // offset confirmed
STUB u8 D_2e90[10]; // offset confirmed
STUB u8 D_2e9a[10];

typedef struct Pair
{
    u8 _0;
    u8 _1;
} Pair;

typedef struct Pair2
{
    u16 _0;
    u16 _2;
} Pair2;

STUB Pair D_2ea4[24]; // TODO: size
STUB Pair D_2ed4[15]; // TODO: size
STUB Pair D_2ef2[12]; // TODO: size
STUB Pair D_2f0a[3]; // TODO: size
STUB Pair D_2f10[12]; // TODO: size

STUB u8 D_2f16[6]; // TODO: size
STUB u8 D_2f1e[6]; // TODO: size

STUB u8 D_2f24;
STUB u8 D_2f26;

STUB s8 D_2f28[4]; // direction x
STUB s8 D_2f2c[4]; // direction y

STUB Pair D_2f98[0x15];
STUB Pair2 D_2fc2[0x15];
STUB u16 D_3016[0x15];
STUB u8 D_3040[0x16]; // 0x15 + gap 1
STUB u8 D_3056[0x16]; // 0x15 + gap 1
STUB u8 D_306c[0x16]; // 0x15 + gap 1
STUB u8 D_3082[0x16]; // 0x15 + gap 1
STUB u8 D_3098[0x16]; // 0x15 + gap 1
STUB u8 D_30ae[0x16]; // 0x15 + gap 1
STUB u8 D_30c4[0x16]; // 0x15 + gap 1
STUB u8 D_30da[0x16]; // 0x15 + gap 1
STUB u8 D_30f0[0x15];
// 0x3105: "WD.BIT"

// 3000

STUB u16 D_3304;

STUB u16 D_3656[8];
STUB char* D_3666[8];

STUB u8 D_367e[0x20]; // TODO: size ~369e)

STUB u8 D_369e[0x3c]; // TODO: size
STUB u8 D_36da[];
STUB u8 D_3702[];
STUB u8 D_370e[];
STUB u8 D_3716[];

STUB u16 D_3720[6];
STUB u16 D_372c[6];
STUB u16 D_3738[6];
STUB s16 D_3744[6]; // ~3750)

STUB u8 D_3750[8];
STUB u8 D_3758[8];
STUB u8 D_3760[0xb0]; // ~3810)

STUB u8 D_3812[16]; // ~3822) ? TODO: size, offset?
STUB u8 D_3822[16]; // ~3832) ? TODO: size, offset?

STUB u8 D_383a[6];
STUB u8 D_3840;
//STUB u8 D_3841;

STUB u8 D_3842[0xd]; // ~384f)? TODO: size, offset
STUB u8 D_3850[0xd]; // ~385d)? TODO: size, offset
                     // D_383f, D_384d

STUB u8 D_385e[8]; // ~3866)
STUB u8 D_3866[8]; // ~386e)
STUB u8 D_386e[8]; // ~3876)
STUB u8 D_3876[0x100]; // ~3976) TODO: size?

STUB u8 D_3a06[3];
STUB u8 D_3a0a[3];
STUB u8 D_3a0e[3];

STUB u8 D_3a26[0xc];
STUB u8 D_3a32[0x28];
STUB u8 D_3a5a[0x28];

STUB u16 D_3a82[0x30]; // TODO: int (FMT)

STUB u8 D_3ae2[0x48]; // ~3b2a)

STUB u16 D_3b2a[0x20]; // int (FMT: 4byte)
STUB u16 D_3b6a[0x20]; // ~3baa)
STUB u16 D_3baa[0x20]; // ~3bea)

STUB u16 D_3bea[0x10];
STUB u16 D_3c0a[3];
STUB u16 D_3c10[8];    // string offset table. type: int (FMT: 4bytes)

STUB char* D_3c20[8];

STUB u16 D_3c30[4];
STUB s16 D_3c38[4]; // 3c38..3c40)
STUB s16 D_3c40[4]; // 3c40..3c48)

STUB s16 D_3c48[4];
STUB char* D_3ca6[4];
STUB char* D_3cae[4];
STUB char* D_3cb6[4];

STUB u16 D_3cbe[8]; // string offset table. type: int (FMT: 4bytes)

STUB char* D_3cce[0x30];

STUB char* D_3d2e[4];

STUB char* D_3d36[4];
STUB char* D_3d3e[4];
STUB char* D_3d46[2];
STUB char* D_3d4a[4];
STUB char* D_3d52[4];

STUB char* D_3d5a; // "\n\n\"Thou hast no need of this art!\"\nsays $."

STUB u8 D_3d86[8];
STUB u8 D_3d8e[8];
STUB u16 D_3d96[8];

STUB Pair D_3da6[6];
STUB Pair2 D_3db2[6];
STUB u16 D_3dca[6];

STUB u8 D_3dd6[6];
STUB u8 D_3ddc[6];
STUB u8 D_3de2[6];
STUB u8 D_3de8[6];
STUB u8 D_3dee[6]; // endgame_0000 image idx
STUB u8 D_3df4[6];
STUB u8 D_3dfa[6]; // endgame_0000 image x
STUB u8 D_3e00[6]; // endgame_0000 image y
STUB u8 D_3e06[6];

STUB char* D_3e0a[20];
STUB char* D_3e32[8];
STUB char* D_3e42[12];

STUB u8 D_3e5a[6];
STUB u8 D_3e60[6];

STUB u8 D_3e66[4];
STUB u8 D_3e6a[4];
STUB u8 D_3e6e[4];
STUB char* D_3e72[3];

STUB u8 D_3e78[0x72]; // TODO: size
STUB u8 D_3eea[0x72]; // hidden item - _5 TODO: size
STUB u8 D_3f5c[0x72]; // hidden item - map id TODO: size
STUB u8 D_3fce[0x72]; // hidden item - map z TODO: size
STUB u8 D_4040[0x72]; // hidden item - map x TODO: size
STUB u8 D_40b2[0x72]; // hidden item - map y TODO: size

// 4100
STUB u8 D_4124[8];
STUB u8 D_412c[8];
STUB u8 D_4134[8];

STUB u8 D_413c[0x30];
STUB u8 D_416c[0x30]; // ~419c)

STUB char* D_419c[8];
STUB char* D_41ac[8];
STUB u8 D_41bc[8];
STUB u8 D_41c4[8];
STUB u8 D_41cc[8];

STUB char* D_444a[3];

STUB char* D_4502[8];
STUB u8 D_4512[8];

STUB u8 D_4592[4];
STUB u8 D_4596[4];

STUB u8 D_4882[3]; // map x
STUB u8 D_4886[3]; // map y
STUB u8 D_488a[3]; // map id
STUB u8 D_488e[3]; // map level
STUB u8 D_4892[3];

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

STUB u16 D_4af6[9];
STUB u16 D_4b08[9];
STUB u16 D_4b1a[9];
STUB u16 D_4b2c[9];

STUB char* D_4b3e[8]; // virtue keywords

STUB u16 D_4b5e[8]; // int
STUB u16 D_4b6e[8];

STUB u8 D_4b7e[];
STUB u8 D_4b86[];
STUB u8 D_4b8e[];

STUB u8 D_4b95[9];
STUB u8 D_4b9e[0x24]; // TODO: size
STUB u8 D_4bc2[0x24]; // TODO: size

// some sound table
STUB u16 D_4be6[7];
STUB u16 D_4bf4[7];
STUB u16 D_4c02[7];
STUB u16 D_4c10[7];

STUB char* D_4c1e;
STUB char* D_4c24;
STUB char* D_4c2a;
STUB char* D_4c30;

STUB u16 D_4c36[9]; // TODO: size
STUB u16 D_4c48[6]; // TODO: size
STUB u16 D_4c54[9]; // TODO: size
STUB u16 D_4c66[7]; // TODO: size

STUB char* D_4c74[26];
STUB char* D_4ca8[26];
STUB u8  D_4cdc[26];
STUB char* D_4cf6[13];

STUB u16 D_4d10[0x1a]; // TODO: size
STUB u16 D_4d44[4];
STUB u8  D_4d4c[0xa]; // TODO: size
STUB u16 D_4d56[4];
STUB u16 D_4d5e[4];
STUB u16 D_4d66[4];
STUB u16 D_4d6e[4];
STUB u8  D_4d76[4];
STUB u8  D_4d7a[4];
STUB u8  D_4d7e[8]; // TODO: size

STUB u8 D_4dc4[6];

STUB u16 D_4e6e[6];
STUB u8 D_4e7a[6];
STUB u8 D_4e80[6];

STUB u8 D_50eb[0x5a]; // glyph width table

#define D_50f7 D_50eb[0xc]

STUB u16 D_5146[2];
STUB u16 D_514c[2];
STUB u16 D_5150;
STUB u16 D_5152;
STUB u16 D_5154;
STUB u16 D_5156;
STUB u16 D_5158;
STUB u16 D_515a; // = 0

STUB char* D_515c[4];

// 5200

STUB u8 D_5164[8];
STUB u8 D_516c[8];
STUB u8 D_5174[8];
STUB u16 D_517c[0x40];
STUB u8 D_51fc[8];
STUB u8 D_5204[8];
STUB u8 D_520c; // = 0

// main parameters
STUB int D_52a2;     // argc
STUB char** D_52a4;  // argv
STUB char** D_52a6;   // envp

typedef struct VideoDriverParams
{
    int _52ba_forceCga;         // 52ba 0
    int _52bc;                  // 52bc 2: x offset for tile drawing
    int _52be;                  // 52be 4: y offset for tile drawing
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
    int _52d8_page;             // 52d8 1e
} VideoDriverParams;            // size: 0x20?

STUB VideoDriverParams D_52ba_vdp;
#define D_52c8 D_52ba_vdp._52c8_videoDriverSelection

STUB int D_52da_pen_color;

STUB int D_52ef_forceEga; // force ega
STUB int D_52f1_forceTandy; // force tandy
STUB int D_52f3_forceHerc; // force herc

STUB int D_52f6; // temp area?
STUB int D_52f8; // temp area?

// ?
STUB int D_52fa; // x1
STUB int D_52fc; // y1
STUB int D_52fe; // x2
STUB int D_5300; // y2

// 5300
STUB int D_5304; // previous video mode

STUB u16 D_5306[7];
STUB u16 D_5314[7];

// 5322..5327: "Tandy"
// 5328..532f: video driver string table
// 5330..5337: "CGA.DRV"
// 5338..533f: "EGA.DRV"
// 5340..5347: "T1K.DRV"
// 5348..534f: "HER.DRV"
STUB void* FAR D_5350; // video driver pointer
STUB u16 D_5354; // segment of 3rd part of video buffer (a800)
STUB u16 D_5356; // timer calibration
STUB u16 D_5358; // memory size
STUB u16 D_535a; // current timer value
STUB u16 D_535c; // int21 error code

// size: 8
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
STUB TextWindow D_535e_textWindows[4];

STUB u16 D_5386_current_text_window_idx; // charset_id (offset in 539a, data in 53a4..53ab)
STUB u16 D_5388_current_charset_idx; // selected charset idx
STUB u16 D_538a; // bool: special keystroke
STUB u16 D_538c; // ? (keystroke)
STUB u16 D_538e; // cursor advance flag
STUB u16 D_5390; // keystroke cursor begin idx
STUB u16 D_5392;
STUB void* FAR D_5394_fn; // disk swap message function pointer
//STUB u16 D_5394; // far address for disk swap message
//STUB u16 D_5396; // (far segment for disk swap message)
//STUB u16 D_5398; // segment of current charset
STUB u8* FAR D_5398_currentCharset;        // ptr of current charset
STUB TextWindow* D_539a_currentTextWindow; // address of current text window data
//STUB u16 D_539c[4]; // charset segment table
STUB u8* FAR D_539c[4];    // charset table
STUB u16 D_53a4_underline; // underline flag (bit 0 of byte 7)
STUB u16 D_53a6; // ? flag (bit 1 of byte 7)
STUB u16 D_53a8_inverse; // inverse flag (bit 1 of byte 7)
STUB u8  D_53aa_text_fg_color; // text fg color (lo nibble of byte 6)
STUB u8  D_53ab_text_bg_color; // text bg color (hi nibble of byte 6)

STUB u16 D_53b4; // loaded file size (lsb)
STUB u16 D_53b6; // loaded file size (msb)

STUB u16 D_53b8; // file handle
STUB u16 D_53ba; // first allocated segment
STUB u16 D_53bc; // first allocated segment (for return)
STUB u16 D_53be; // second allocated segment (for lzw)

// u16 53c4: read pointer
// u16 53cc: 0x102
// u16 53d0: 0x200
// u16 53d2: read advance amount? (9)

// 53d6..53e8: "Out of Memory...\n$"

STUB u8 D_53ea[24]; // ~5402) character data from charset file (herc=24, others=8)
STUB s16 D_5402[5]; // 5402..540c) 1, 10, 100, 1000, 10000
STUB u16 D_540c; // cursor anim idx
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
STUB u8 D_54f4[64]; // some table. (party icon -> move type table)

STUB u8 D_5544[4];

STUB u8 D_559e[8]; // ~55a6)

//
// Savegame / User state
// 

// [55a6..6606): savegame (0x1060)
STUB u16 D_55a6;    // +0x0

STUB S_55a8 D_55a8_party[0x10]; // ~57a8)

// 5700
STUB u16 D_57a8;        // +0x0202 Food // TODO: s16? (F_TALK_c602)
STUB u16 D_57aa;        // +0x0204 Gold // TODO: s16? (F_MAINOUT_1b3e, FMT MOVSX)
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
    u8 _0_tile; // base tile
    u8 _1;      // animated tile
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

// size: 0x10
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
    u16 _0; // 5e
    s16 _2; // 60 x
    s16 _4; // 62 y
    u16 _6; // 64 z
    u16 _8; // 66
    u16 _a; // 68
    u16 _c; // 6a   // TODO: s16?
    u16 _e; // 6c
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
STUB u16 D_655e[0x20];   // +0x0FB8 Movement list pointers [..659e) TODO: signed?
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

STUB u8 D_6708[1024]; // same size with 6608

STUB u8 D_6a08; // some audio related

STUB u16 D_6a0a[5];

STUB u8 D_6a14[0x20];

STUB u8 D_6a34;

STUB u8 D_6a48[0x35]; // some audio related table

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
STUB u8 D_a526;
STUB u8 D_a527;

STUB u8 D_a528[0x100];
STUB u8 D_a628[0x100];
STUB u8 D_a728[0x100];
STUB u8 D_a872[0x100];

// a900

STUB u8  D_a9bc;
STUB u16 D_a9bd; // drive idx
STUB u16 D_a9be;
STUB u8* D_a9c0; // loaded image pointer
STUB u16 D_a9c2;
STUB u8* D_a9c4; // loaded image pointer
STUB u8* D_a9c6; // loaded image pointer

// disk drive table
STUB u8  D_a9c8; // actual current disk drive letter
STUB u8  D_a9c9; // adjusted disk drive letter, 0xff: floppy
STUB u8  D_a9ca; // adjusted disk drive letter, 0xff: floppy
STUB u8  D_a9cb; // floppy (0xff)
STUB u8  D_a9cc; // unused
STUB u8  D_a9cd; // adjusted disk drive letter, 0xff: floppy

// used in intro
STUB u8 D_a9ce; // use sound effect?

STUB u16 D_a9d0[0x15];

STUB u8 D_a9fa;
STUB u8 D_a9fb;

// combat?
STUB ActorFmt D_a9fc[0x20]; // ~ aafc? TODO: type

STUB char* D_aafc; // current shop name
STUB char* D_aafe; // current shop owner

STUB char* D_ab00;
STUB u8 D_ab02[0x160]; // copied map data? [20 * b]? [ab02..ac62)
STUB char* D_ac62;
STUB u8 D_ac64[0xb0]; // npc map? size? [10 * b]? (from 51b8)
STUB u8 D_ad14[32 * 32]; // combat map data? size? [ad14..b114)?

// b100

STUB s16 D_b114; // s16 (FMT MOVSX) max: 0x10?
STUB s16 D_b116; // s16 (FMT MOVSX)
STUB s16 D_b118; // s16 (FMT MOVSX)
STUB u16 D_b11a;

STUB u8* D_b11c;
STUB u8 D_b11e[0x100]; // animated tile lookup table
STUB u8 D_b21e[2000]; // 2000 byte scratch ~b9ee)

#define D_b31e (D_b21e + 0x100)
#define D_b7fa (D_b21e + 1500)

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
STUB u16 D_bb18; // "lord british" index
STUB void* D_bb1a; // pointer

typedef struct S_bb1c
{
    u8 _0[6]; // bb1c; fill

    u16 _6; // bb22
    u16 _8; // bb24
    u16 _a; // bb26
    u16 _c; // bb28
    u16 _e; // bb2a
    u16 _10; // bb2c
    u16 _12; // bb2e
    u16 _14; // bb30

    u8 _16[0xa0]; // fill
} S_bb1c;

STUB S_bb1c D_bb1c;

typedef struct S_bc88
{
    u16 _0; // bc88 
    u16 _2; // bc8a
    u16 _4; // bc8c
    u16 _6; // bc8e
    u16 _8; // bc90
    u16 _a; // bc92
    u16 _c; // bc94
    u16 _e; // bc96
    u16 _10; // bc98
    u16 _12; // bc9a
    char _14[16]; // bc9c
    u8 _24; // bcac
    u8 _25; // bcad
    u8 _26; // bcae
    u8 _27; // bcaf
} S_bc88;

STUB S_bc88 D_bc88;

STUB char D_bcb2[0x27 + 1];

STUB u8 D_bd2a[8];
STUB u8 D_bd32[8];

STUB u8 D_bcda;

STUB u16 D_bcdc;
STUB u8* D_bcde; // pointer
STUB u8 D_bce0[4]; // ?
STUB char D_bce4[0x10];
STUB u8 D_bcf4;
STUB u16 D_bcf6;
STUB char D_bcf8[16];

STUB char D_bd08[12];

STUB u8 D_bd15;
STUB u8 D_bd16;
STUB s16 D_bd18; // int?
STUB int D_bd1a; // int
STUB int D_bd1c; // int
STUB int D_bd1e; // int
STUB s16 D_bd20; // int?
STUB s16 D_bd22;
STUB s16 D_bd24;

STUB u8 D_bd26;
STUB u8 D_bd27;
STUB u8 D_bd28;
STUB u8 D_bd29;

STUB u8 D_bd3c;
STUB u8 D_bd3d;
STUB u8 D_bd3e;

// ..bd3f]

#endif
