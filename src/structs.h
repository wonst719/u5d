#ifndef _STRUCTS_H
#define _STRUCTS_H

#pragma pack(push, 1)

// size: 8
// monster/foe stats?
typedef struct S_13bc // ?
{
	u8 _0;	// 13bc / 3f050
	u8 _1;	// 13bd
	u8 _2;	// 13be / 3f052
	u8 _3;	// 13bf
	u8 _4;	// 13c0
	u8 _5;	// 13c1 / 3f055; max hp
	u8 _6;	// 13c2
	u8 _7;	// 13c3
} S_13bc;

// size: 32; 55a8..55c7 * n
// "Party"
typedef struct S_55a8
{
	char _0[9];	// 55a8; name
	u8 _9;	// 55b1; gender (0b: male, 0c: female)
	u8 _a;	// 55b2; class ('A', 'F', 'B', 'M')
	u8 _b;	// 55b3; status ('G': good, 'D': dead)
	u8 _c;	// 55b4; strength
	u8 _d;	// 55b5; dexerity
	u8 _e;	// 55b6; intelligence
	u8 _f;	// 55b7; magic
	s16 _10;	// 55b8; hp
	s16 _12;	// 55ba; max_hp
	s16 _14;	// 55bc; exp
	u8 _16;	// 55be; level
	u8 _17;	// 55bf
	u8 _18;	// 55c0
	u8 _19;	// 55c1 ; equip[0]
	u8 _1a;	// 55c2 ; equip[1]
	u8 _1b;	// 55c3 ; equip[2]
	u8 _1c;	// 55c4 ; equip[3]
	u8 _1d;	// 55c5 ; equip[4] ; magic_ring
	u8 _1e;	// 55c6 ; equip[5] ; amulet
	u8 _1f;	// 55c7
} S_55a8;

// x/y pair (u8) "coord"
typedef struct Pair
{
	u8 _0;
	u8 _1;
} Pair;

// x/y pair (s8) "coord"
typedef struct PairS8
{
	s8 _0;
	s8 _1;
} PairS8;

// x/y pair (u16) "coord"
typedef struct Pair2
{
	u16 _0;
	u16 _2;
} Pair2;

// 52ba
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

// 535e size: 8
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

// 5c00: Actor. size: 8 "Obj"
typedef struct ActorFmt // D_5c5a..
{
	u8 _0_tile; // base tile (shape)
	u8 _1;      // animated tile
	u8 _2_x;
	u8 _3_y;
	u8 _4_z;
	u8 _5;
	u8 _6;
	u8 _7;
} ActorFmt;

// 5f5e: Character (npc) / monster. size: 16
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

// size: 16
typedef struct NpcScheduleFmt
{
	u8 _0[3]; // type
	u8 _3[3]; // x
	u8 _6[3]; // y
	u8 _9[3]; // z (s8?)
	u8 _c[4]; // time
} NpcScheduleFmt;

// size: 32
typedef struct MovementFmt
{
	u8 data[0x20];
} MovementFmt;

// size: 1024 (0x400)
typedef union S_6608_Map
{
	u8 overworld[4][16][16]; // overworld
	u8 town[32][32]; // town / castle / ...
	u8 raw[1024];
} S_6608_Map;

// size: 8
// combat entity
typedef struct CombatEntity
{
	u8 _0;	// ba14; current hp
	u8 _1;	// ba15; dex
	u8 _2;	// ba16; flags (0x80: player, 0x40: monster, ...)
	u8 _3;	// ba17; player idx (->55a8)
	u8 _4;	// ba18; actor idx (->5c5a)
	u8 _5;	// ba19; turn timer?
	u8 _6;	// ba1a; x coord
	u8 _7;	// ba1b; y coord
} CombatEntity;

// size: 182
// U4 party related (party.sav:0x140)
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

// size: 40
// u4 character stat (party.sav:0x8)
typedef struct S_bc88
{
	u16 _0; // bc88; current hp
	u16 _2; // bc8a; max hp
	u16 _4; // bc8c; exp
	u16 _6; // bc8e; str
	u16 _8; // bc90; dex
	u16 _a; // bc92; int
	u16 _c; // bc94; mag
	u16 _e; // bc96; not accessed
	u16 _10; // bc98; weapon; not accessed
	u16 _12; // bc9a; armor; not accessed
	u8 _14[16]; // bc9c; name
	u8 _24; // bcac; gender
	u8 _25; // bcad; class
	u8 _26; // bcae; not accessed
	u8 _27; // bcaf
} S_bc88;

#pragma pack(pop)

#endif
