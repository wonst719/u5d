#ifndef _STRUCTS_H
#define _STRUCTS_H

#pragma pack(push, 1)
/* size: 0x20; 55a8..55c7 * n */
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
#pragma pack(pop)

#endif
