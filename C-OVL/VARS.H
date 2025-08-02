#ifndef _VARS_H
#define _VARS_H

#ifndef STUB
#define STUB extern
#endif

/* size: 0x20; 55a8..55c7 * n */
typedef struct S_55a8
{
	char _0[9];	// 55a8; name
	u8 _9;	// 55b1; gender (0b: male, 0c: female)
	u8 _a;	// 55b2; class ('A', 'F', 'B', 'M'
	u8 _b;	// 55b3; status ('G': good, 'D': dead)
	u8 _c;	// 55b4; strength
	u8 _d;	// 55b5; deaerity
	u8 _e;	// 55b6; intelligence
	u8 _f;	// 55b7; magic
	int _10;	// 55b8; hp
	int _12;	// 55ba; max_hp
	int _14;	// 55bc; exp
	u8 _16;	// 55be
	u8 _17;	// 55bf
	u8 _18;	// 55c0
	u8 _19;	// 55c1 ; unk[0]
	u8 _1a;	// 55c2 ; unk[1]
	u8 _1b;	// 55c3 ; unk[2]
	u8 _1c;	// 55c4 ; unk[3]
	u8 _1d;	// 55c5 ; unk[4] ; magic_ring
	u8 _1e;	// 55c6 ; unk[5] ; amulet
	u8 _1f;	// 55c7
} S_55a8;

typedef struct TEXT {
	char* text;
} TEXT;

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

// 5200

// main parameters
STUB char** D_52a6;   // envp
STUB char** D_52a4;  // argv
STUB int D_52a2;     // argc

STUB int D_52ba; // force cga
STUB int D_52ef; // force ega
STUB int D_52f1; // force tandy
STUB int D_52f3; // force herc

// 5300

STUB u16 D_538c;

STUB u16 D_5394;
STUB u16 D_5396;

// 5500

STUB S_55a8 D_55a8[16]; // FIXME: count

// 5700

STUB u8  UNK_0000_57a8;
STUB u8  UNK_0000_57aa;
STUB u8  UNK_0000_57ac;
STUB u8  UNK_0000_57ad;
STUB u8  UNK_0000_57ae;
STUB u8  UNK_0000_57af;
STUB u8  UNK_0000_57b0;
STUB u8  UNK_0000_57b1;
STUB u8  UNK_0000_57b3;
STUB u8  UNK_0000_57b4;
STUB u8  UNK_0000_57b5;
STUB u8  UNK_0000_57b6[3];

STUB u8  UNK_0000_57ba;
STUB u8  UNK_0000_57bb;
STUB u8  UNK_0000_57bc;
STUB u8  UNK_0000_57bd;
STUB u8  UNK_0000_57be;
STUB u8  UNK_0000_57bf;
STUB u8  DAT_0000_57c0[1];

STUB u8  UNK_0000_57db;
STUB u8  UNK_0000_57dd;

// 5800

STUB u8  UNK_0000_5820[8];
STUB u8  UNK_0000_5828[8];
STUB u8  UNK_0000_5840[8];
STUB u8  DAT_0000_5850[1];

STUB u8  D_5893;  // map_id
STUB u8  D_5895;
STUB u8  DAT_58a3;
STUB u8  UNK_0000_589e;

STUB u8 DAT_0000_58f0[1];

// 5c00

STUB u8 UNK_0000_5c5a[1];

// a900

STUB u16 D_a9bd;
STUB u16 D_a9be;
STUB u16 D_a9c2;
STUB u8  D_a9c8;
STUB u8  D_a9c9;
STUB u8  D_a9ca;
STUB u8  D_a9cb;
STUB u8  D_a9cd;

// b100

STUB u16 D_b11c;

// b900

STUB u8  UNK_0000_b9ee[8];
STUB u8  UNK_0000_b9f6[8];
STUB u8  UNK_0000_b9fe;
STUB u8  UNK_0000_b9ff;

// ba00

STUB u8  UNK_0000_ba00;
STUB u8  UNK_0000_ba01;
STUB u8  UNK_0000_ba02;
STUB u8  UNK_0000_ba03[8];
STUB u8  UNK_0000_ba0b[3];
STUB u8  UNK_0000_ba0e;
STUB u8  UNK_0000_ba0f;
STUB u8  UNK_0000_ba10;
STUB u8  UNK_0000_ba11;
STUB u8  UNK_0000_ba12;
STUB u8  UNK_0000_ba13;
STUB u8  D_BA16[1];

STUB u8  UNK_0000_ba18[1];

#endif
