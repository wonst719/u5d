#ifndef _STRUCTS_H
#define _STRUCTS_H

#pragma pack(push, 1)

// size: 8
// monster/foe stats?
typedef struct S_13bc // ?
{
	u8 _0;			// 0 / 13bc / 3f050; str
	u8 _1;			// 1 / 13bd
	u8 _2;			// 2 / 13be / 3f052; intel
	u8 _3;			// 3 / 13bf; def
	u8 _4;			// 4 / 13c0; atk
	u8 _5_maxHp;	// 5 / 13c1 / 3f055; max hp
	u8 _6;			// 6 / 13c2
	u8 _7;			// 7 / 13c3
} S_13bc;

// size: 32; 55a8..55c7 * n
// "Party"
typedef struct S_55a8
{
	char name[9];	// 0 / 55a8; name
	u8 gender;		// 9 / 55b1; gender (0b: male, 0c: female)
	u8 cls;			// a / 55b2; class ('A', 'F', 'B', 'M', ...)
	u8 status;		// b / 55b3; status ('G': good, 'D': dead, ...)
	u8 str;			// c / 55b4; strength
	u8 dex;			// d / 55b5; dexerity
	u8 intel;		// e / 55b6; intelligence
	u8 mag;			// f / 55b7; magic
	s16 hp;			// 10 / 55b8; hp
	s16 maxHp;		// 12 / 55ba; max_hp (HM)
	s16 exp;		// 14 / 55bc; exp
	u8 level;		// 16 / 55be; level
	u8 _17;			// 17 / 55bf
	u8 _18;			// 18 / 55c0; def?
	u8 equips[6];	// 19 / 55c1 ; equips ([4]: magic_ring, [5]: amulet)
	u8 mapId;		// 1f / 55c7
} S_55a8;

// x/y pair (u8) "coord"
typedef struct Pair
{
	u8 x;
	u8 y;
} Pair;

// x/y pair (s8) "coord"
typedef struct PairS8
{
	s8 x;
	s8 y;
} PairS8;

// x/y pair (u16) "coord"
typedef struct Pair2
{
	u16 x;
	u16 y;
} Pair2;

// 52ba
typedef struct VideoDriverParams
{
	int _52ba_forceCga;         // 52ba 0
	int _52bc_tileXOffset;      // 52bc 2
	int _52be_tileYOffset;      // 52be 4
	int _52c0;                  // 52c0
	int _52c2;                  // 52c2
	int _52c4;                  // 52c4
	int _52c6;                  // 52c6
	int _52c8_videoDriverSelection; // 52c8: video driver selection (0=cga, 1=ega, 2=tandy, 3=herc, ffff=none)
	int _52ca_machineType;      // 52ca: machine type (0=pcjr, 2=ibm, 3=tandy, 6=other)
	int _52cc_penX;             // 52cc
	int _52ce_penY;             // 52ce
	int _52d0_clipWindowX1;     // 52d0
	int _52d2_clipWindowX2;     // 52d2
	int _52d4_clipWindowY1;     // 52d4
	int _52d6_clipWindowY2;     // 52d6
	int _52d8_page;             // 52d8 1e
} VideoDriverParams;            // size: 0x20?

// 535e size: 8
typedef struct TextWindow
{
	u8 left;   // 0
	u8 top;    // 1
	u8 right;  // 2
	u8 bottom; // 3
	u8 currentX; // 4
	u8 currentY; // 5
	u8 colors;  // 6; hi: bg, lo: fg
	u8 flags; // 7; flags: bits 0..2
} TextWindow;

// 5c00: Actor. size: 8 "Obj"
typedef struct ActorFmt // D_5c5a..
{
	u8 _0_tile; // base tile (shape)
	u8 _1_animTile;      // animated tile
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
	u16 _0;   // 0 / 5f5e
	s16 _2_x; // 2 / 5f60 x
	s16 _4_y; // 4 / 5f62 y
	u16 _6_z; // 6 / 5f64 z
	u16 _8;   // 8 / 5f66
	u16 _a;   // a / 5f68
	u16 _c;   // c / 5f6a   // TODO: s16?
	u16 _e;   // e / 5f6c
} NpcFmt;

// size: 16
typedef struct NpcScheduleFmt
{
	u8 type[3]; // 0 / type
	u8 x[3];    // 3 / x
	u8 y[3];    // 6 / y
	u8 z[3];    // 9 / z (s8?)
	u8 time[4]; // c / time
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
// combat entity (ba14)
typedef struct CombatEntity
{
	u8 hp;			// 0 / ba14; current hp
	u8 dex;			// 1 / ba15; dex
	u8 flags;		// 2 / ba16; flags (0x80: player, 0x40: monster, ...)
	u8 entityIdx;	// 3 / ba17; entity idx (player, monster, ...) (->13bc, 153c, 15cc, 1856, 55a8, )
	u8 actorIdx;	// 4 / ba18; actor idx (->5c5a)
	u8 turnTimer;	// 5 / ba19; turn timer?
	u8 x;			// 6 / ba1a; x coord
	u8 y;			// 7 / ba1b; y coord
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
typedef struct S_bc88_U4Party
{
	u16 hp;		// bc88; current hp
	u16 maxHp;	// bc8a; max hp
	u16 exp;	// bc8c; exp
	u16 str;	// bc8e; str
	u16 dex;	// bc90; dex
	u16 intel;	// bc92; int
	u16 mag;	// bc94; mag
	u16 _e;		// bc96; not accessed
	u16 _10;	// bc98; weapon; not accessed
	u16 _12;	// bc9a; armor; not accessed
	u8 name[16]; // bc9c; name
	u8 gender;	// bcac; gender
	u8 cls;		// bcad; class
	u8 _26;		// bcae; not accessed
	u8 _27;		// bcaf
} S_bc88_U4Party;

#pragma pack(pop)

#endif
