#ifndef _VARS_H
#define _VARS_H

#ifndef STUB
#define STUB extern
#endif

#include "STRUCTS.H"

// 103c..
// tlk word table

// 1300
STUB u16 D_13ae;

STUB u16 D_13b0_white_color;
STUB u16 D_13b2_frame_color;
STUB u16 D_13b4;
STUB u16 D_13b6;
STUB u16 D_13b8;
STUB u16 D_13ba;


// 1900

STUB TEXT D_1916[1];
STUB TEXT D_1962[1];
STUB char* D_19B2;
STUB TEXT D_19D2[1];
STUB TEXT D_19E2[1];

// 1a00

STUB char D_1A44[1];
STUB int D_1A58[1];
STUB char D_1A6A[1];
STUB char D_1A7E[1];
STUB byte D_1AE8[1];
STUB char D_1ADE[1];
STUB byte D_1AAE[1];

// 2500
// some table from 24ea..2625
// defined from assembly?
STUB char* D_24ea[0x80];
STUB char* D_25ea[3]; // PROPORT.PCS / BRITISH.BIT / TITLE.BIT
STUB char* D_25ec[1];
STUB char* D_25ee[1];
STUB char* D_25f0[27]; // TILES.16 / ITEMS.16 / DNG1.16 / ...

STUB u16 D_261e;

// 5200

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

STUB u16 D_5386_currentTextWindow; // charset_id (offset in 539a, data in 53a4..53ab)
STUB u16 D_5388; // charset_seg (in 5398)
STUB u16 D_538a; // bool: special keystroke
STUB u16 D_538c; // ? (keystroke)
STUB u16 D_538e; // cursor advance flag
STUB u16 D_5390; // ? (1b38)

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

STUB u8 D_53ea[24]; // character data from charset file (herc=24, others=8)

// STUB u8 540e..5405? // bios key scan code table
// STUB u8 5416..541d // special key table
STUB u8 D_541e; // drive number

STUB u16 D_5448; // current timer value
STUB u16 D_544a; // timer tick count to wait
// far D_544c; // far addr of original int 1c handler

// 5500
STUB u16 D_55a6;

STUB S_55a8 D_55a8_party[131]; // 55a6..6606

STUB u16 D_6606; // end

// 5700

STUB u8  D_57a8;
STUB u8  D_57aa;
STUB u8  D_57ac;
STUB u8  D_57ad;
STUB u8  D_57ae;
STUB u8  D_57af;
STUB u8  D_57b0;
STUB u8  D_57b1;
STUB u8  D_57b3;
STUB u8  D_57b4;
STUB u8  D_57b5;
STUB u8  D_57b6[3];

STUB u8  D_57ba;
STUB u8  D_57bb;
STUB u8  D_57bc;
STUB u8  D_57bd;
STUB u8  D_57be;
STUB u8  D_57bf;
STUB u8  D_57c0[1];

STUB u8  D_57db;
STUB u8  D_57dd;

// 5800

STUB u8  D_5820[8];
STUB u8  D_5828[8];
STUB u8  D_5840[8];
STUB u8  D_5850[1];

STUB u8  D_585b; // party member count

STUB u8  D_5876; // first party member that is not dead or sleeping
STUB u8  D_587a;
STUB u8  D_587c; // party icon (13=horse, 14=carpet, 1c=avatar, 24=frigate, 28=skiff)
STUB u8  D_5883; // ?
STUB u8  D_5892_wind_dir; // wind direction
STUB u8  D_5893_map_id;  // map_id (21h~: dungeon, 40: unloaded)
STUB u8  D_5895_map_level; // level (depth)
STUB u8  D_5896; // map_x
STUB u8  D_5897; // map_y
STUB u8  D_58a3; // battle successful flag (win?)

STUB u8  D_589e;

STUB u8 D_58f0[1];

STUB u8* D_595a;

// 5c00

STUB u8 D_5c5a[0x100];

// 6600
STUB u8 D_6604;

// a900

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
STUB u8 D_a9ce;

// b100

STUB u16 D_b11c;
STUB u8 D_b11e[0x100];
STUB u8 D_b21e[0x200];
STUB u8* D_b31e;

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
STUB u8  D_BA16[1];

STUB u8  D_ba18[1];

STUB u8  D_bb14; // pos?
STUB u8  D_bb15; // pos?
STUB u8  D_bb16;
STUB u8  D_bb17;
STUB u16 D_bb18;
STUB u16 D_bb1a;

#endif
