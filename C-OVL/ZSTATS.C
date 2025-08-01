
typedef char i8;
typedef int i16;

typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned int uint;
typedef int bool;

typedef byte undefined;
typedef int undefined2;

/* size: 0x20; 55a8..55c7 * n */
typedef struct S_55a8
{
	char _0[9];	// 55a8; name
	byte _9;	// 55b1; gender (0b: male, 0c: female)
	byte _a;	// 55b2; class ('A', 'F', 'B', 'M'
	byte _b;	// 55b3; status ('G': good, 'D': dead)
	byte _c;	// 55b4; strength
	byte _d;	// 55b5; deaerity
	byte _e;	// 55b6; intelligence
	byte _f;	// 55b7; magic
	int _10;	// 55b8; hp
	int _12;	// 55ba; max_hp
	int _14;	// 55bc; exp
	byte _16;	// 55be
	byte _17;	// 55bf
	byte _18;	// 55c0
	byte _19;	// 55c1 ; unk[0]
	byte _1a;	// 55c2 ; unk[1]
	byte _1b;	// 55c3 ; unk[2]
	byte _1c;	// 55c4 ; unk[3]
	byte _1d;	// 55c5 ; unk[4] ; magic_ring
	byte _1e;	// 55c6 ; unk[5] ; amulet
	byte _1f;	// 55c7
} S_55a8;
extern S_55a8* DAT_55a8; // units
//#define DAT_55a8 ((S_55a8*)0x55a8)

extern word UNK_0000_57a8;
extern word UNK_0000_57aa;
extern byte UNK_0000_57ac;
extern byte UNK_0000_57ad;
extern byte UNK_0000_57ae;
extern byte UNK_0000_57af;
extern byte UNK_0000_57b0;
extern byte UNK_0000_57b1;
extern byte UNK_0000_57b3;
extern byte UNK_0000_57b4;
extern byte UNK_0000_57b5;
extern byte UNK_0000_57b6[3];

extern byte UNK_0000_57ba;
extern byte UNK_0000_57bb;
extern byte UNK_0000_57bc;
extern byte UNK_0000_57bd;
extern byte UNK_0000_57be;
extern byte UNK_0000_57bf;
extern char DAT_0000_57c0[0];

extern char UNK_0000_57db;
extern char UNK_0000_57dd;

extern char DAT_0000_58f0[0];

extern char UNK_0000_5820[8];
extern char UNK_0000_5828[8];
extern char UNK_0000_5840[8];

extern char DAT_0000_5850[0];

extern byte DAT_5893; // map_id
extern byte DAT_58a3;
extern byte UNK_0000_589e;

extern byte UNK_0000_5c5a[0];

extern char* TEXT_96b4; // "Player: "
extern char* TEXT_96be; // "None!\n"
extern char* TEXT_96c6; // "AMBFDTPRS"
extern char* TEXT_96d0; // "GPDSC"
extern char* TEXT_96d6; // " Lv-"
extern char* TEXT_96dc; // "Str="
extern char* TEXT_96e2; // "  HP:"
extern char* TEXT_96e8; // "\nInt="
extern char* TEXT_96ee; // "  HM:"
extern char* TEXT_96f4; // "\nDex="
extern char* TEXT_96fa; // "  Ex:"
extern char* TEXT_9700; // "\n\n    Magic:"
extern char* TEXT_970e; // "Arms\n\n"
extern char* TEXT_9716; // "(None ready)"
extern char* TEXT_9724; // "Equipment"
extern char* TEXT_972e; // "\n Food: "
extern char* TEXT_9738; // "\n Gold: "
extern char* TEXT_9742; // "\n\n Keys......."
extern char* TEXT_9752; // "\n Gems......."
extern char* TEXT_9760; // "\n Torches...."
extern char* TEXT_976e; // "\n Grapple"
extern char* TEXT_9778; // "--"
extern char* TEXT_977c; // "\x1c + "
extern char* TEXT_9782; // "\x1d + "
extern char* TEXT_9788; // "Moonstone "
extern char* TEXT_9794; // "(None owned!)"
extern char* TEXT_97a2; // "\nStatus: "
extern char* TEXT_97ac; // "Reagents"
extern char* TEXT_97b6; // "Spells"
extern char* TEXT_97be; // "Items"
extern char* TEXT_97c4; // "Armaments"
extern char* TEXT_97ce; // "Done\n"
extern char* TEXT_97d4; // "\n\n"
extern char* TEXT_97d8; // "\n\nItem: "
extern char* TEXT_97e2; // "Thou canst not change armour in heated battle!"
extern char* TEXT_9812; // "AMBFDTPRS"
extern char* TEXT_981c; // "Thou hast no ammunition for that weapon!"
extern char* TEXT_9846; // "Remove first thy present helm!"
extern char* TEXT_9866; // "Thou must first remove thine other armour!"
extern char* TEXT_9892; // "Thou must free one of thy hands first!"
extern char* TEXT_98ba; // "Both hands must be free before thou canst wield that!"
extern char* TEXT_98f0; // "Thou must remove thine other amulet!"
extern char* TEXT_9916; // "Only one magic ring may be worn at a time!"
extern char* TEXT_9942; // "Thou art not strong enough!"
extern char* TEXT_995e; // "\n\nRing vanishes!\n"

extern char* TEXT_9970;
extern char* TEXT_9976;


extern char UNK_0000_b9ee[8];
extern char UNK_0000_b9f6[8];
extern byte UNK_0000_b9fe;
extern byte UNK_0000_b9ff;
extern byte UNK_0000_ba00;
extern byte UNK_0000_ba01;
extern byte UNK_0000_ba02;
extern char UNK_0000_ba03[8];
extern byte UNK_0000_ba0b[3];
extern byte UNK_0000_ba0e;
extern byte UNK_0000_ba0f;
extern byte UNK_0000_ba10;
extern byte UNK_0000_ba11;
extern byte UNK_0000_ba12;
extern byte UNK_0000_ba13;
byte D_BA16[0];

byte UNK_0000_ba18[0];

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

typedef struct TEXT {
	char* text;
} TEXT;

TEXT D_1916[0];
TEXT D_1962[0];
char* D_19B2;
TEXT D_19D2[0];
TEXT D_19E2[0];
char D_1A44[0];
int D_1A58[0];
char D_1A6A[0];
char D_1A7E[0];
byte D_1AE8[0];
char D_1ADE[0];
byte D_1AAE[0];

// OK P1
// F_0000
int FUN_ZSTATS__01e1e0(int param_1)
{
	// NOT MATCHING: STACK
	int local_4;
	register int si;

	local_4 = -1;

	if (DAT_5893 > 0x80) {
		si = UNK_0000_589e * 8;
		if ((D_BA16[si] & 0x80) == 0)
			goto L_202e; // TODO: remove goto

		local_4 = D_BA16[si + 1];
	} else {
L_202e:
		// 202e
		FUN_1000_1850(TEXT_96b4); // print_string("Player: ");
		local_4 = FUN_1000_2d7a(param_1);
		if (local_4 >= 0) {
			FUN_1000_1850(DAT_55a8[local_4]._0); // print_string(units[].name)
			if (FUN_1000_1f12() != 0) {
				FUN_1000_16ba(10);
			}
		}
	}

	// 205b
	if (local_4 == 0xffff) {
		FUN_1000_1850(TEXT_96be);
	}
	// 206a
	else if (local_4 == 0xfffe) {
		FUN_1000_16ba(10);
	}

	// 2077
	return local_4;
}

// OK P1
// F_0082
void FUN_ZSTATS__01e262(int param_1)
{
	// NOT MATCHING: STACK
	int local_6;
	int local_8;
	int local_a;
	S_55a8* local_4;

	register int si;
	register int* di;

	FUN_0000_8bca();

	local_4 = &DAT_55a8[param_1];

	FUN_1000_4e50(local_4);
	FUN_1000_1c22(1, 0x18, 1, 0x26, 9);
	FUN_1000_16ba(0xff);
	FUN_1000_1c22(1, 0x18, 1, 0x27, 9);

	local_6 = FUN_1000_4d76(&TEXT_96c6, local_4->_a);
	local_a = FUN_1000_4d76(&TEXT_96d0, local_4->_b);
	local_8 = 0;

	if (0 < D_1A58[local_6]) {
		di = &D_1A58[local_6];
	
		si = local_8; // NOT MATCHING: OP
		for (;;) {
			FUN_1000_16ba(0x20);
			si++;
			if (*di <= si)
				break;
		}
	
		local_8 = si;
	}

	FUN_1000_16ba(local_4->_9);
	FUN_1000_1850(TEXT_96d6);
	FUN_1000_1a3e(local_4->_16,1,0x20);
	FUN_1000_16ba(0x20);
	FUN_1000_1850(&D_1A44[local_6]);
	FUN_1000_1c22(1,0x18,1,0x26,9);
	FUN_1000_1bf2(0,1);
	FUN_1000_16ba(0xfc);
	FUN_1000_1850(&D_1A6A[local_a]);
	FUN_1000_1c22(1,0x18,1,0x27,9);
	FUN_1000_1bf2(0,3);
	FUN_1000_16ba(0xfb);
	FUN_1000_1850(TEXT_96dc);
	FUN_1000_1a3e(local_4->_c,2,0x30);
	FUN_1000_1850(TEXT_96e2);
	FUN_1000_1a3e(local_4->_10,4,0x20);
	FUN_1000_1850(TEXT_96e8);
	FUN_1000_1a3e(local_4->_e,2,0x30);
	FUN_1000_1850(TEXT_96ee);
	FUN_1000_1a3e(local_4->_12,4,0x20);
	FUN_1000_1850(TEXT_96f4);
	FUN_1000_1a3e(local_4->_d,2,0x30);
	FUN_1000_1850(TEXT_96fa);
	FUN_1000_1a3e(local_4->_14,4,0x20);
	FUN_1000_1850(TEXT_9700);
	FUN_1000_1a3e(local_4->_f,2,0x20);
}

// OK P1
// F_0278
bool FUN_ZSTATS__01e458(int param_1)
{
	if (param_1 == 0xff) {
		return 0;
	} else {
		FUN_1000_16ba(0x20);
		FUN_1000_1850(D_1962[param_1].text);
		FUN_1000_16ba(10);
		return 1;
	}
}

// OK P1
// F_02a8
void FUN_ZSTATS__01e488(int param_1)
{
	int local_4;
	S_55a8* local_6;

	FUN_1000_4daa();

	local_6 = &DAT_55a8[param_1];
	FUN_1000_4e50(local_6);
	FUN_1000_1c22(1,0x18,1,0x26,9);
	FUN_1000_16ba(0xff);
	FUN_1000_16ba(0xfc);
	FUN_1000_16ba(0xfe);
	FUN_1000_1850(TEXT_970e);
	FUN_1000_16ba(0xfb);
	FUN_1000_16ba(0xfe);

	local_4 = FUN_ZSTATS__01e458(local_6->_19);
	local_4 += FUN_ZSTATS__01e458(local_6->_1a);
	local_4 += FUN_ZSTATS__01e458(local_6->_1b);
	local_4 += FUN_ZSTATS__01e458(local_6->_1c);
	local_4 += FUN_ZSTATS__01e458(local_6->_1d);
	local_4 += FUN_ZSTATS__01e458(local_6->_1e);

	if (local_4 == 0) {
		FUN_1000_1bf2(0,4);
		FUN_1000_16ba(0xfc);
		FUN_1000_1850(TEXT_9716);
		FUN_1000_16ba(0xfb);
	}

	FUN_1000_1c22(1,0x18,1,0x27,9);
}

// OK P1
// F_039C
void FUN_ZSTATS__01e57c()
{
	FUN_1000_4daa();
	FUN_1000_4e50(&TEXT_9724);
	FUN_1000_1c22(1,0x18,1,0x26,9);
	FUN_1000_16ba(0xff);
	FUN_1000_1c22(1,0x18,1,0x27,9);
	FUN_1000_1850(TEXT_972e);
	FUN_1000_1a3e(UNK_0000_57a8,4,0x20);
	FUN_1000_1850(TEXT_9738);
	FUN_1000_1a3e(UNK_0000_57aa,4,0x20);
	FUN_1000_1850(TEXT_9742);
	FUN_1000_1a3e(UNK_0000_57ac,2,0x20);
	FUN_1000_1850(TEXT_9752);
	FUN_1000_1a3e(UNK_0000_57ad,2,0x20);
	FUN_1000_1850(TEXT_9760);
	FUN_1000_1a3e(UNK_0000_57ae,2,0x20);
	if (UNK_0000_57af != '\0') {
		FUN_1000_1850(TEXT_976e);
	}
}

// OK P1
// F_045E
void FUN_ZSTATS__01e63e(int param_1)
{
	register int si;
	int local_4;

	FUN_1000_1c22(1,0x18,1,0x26,param_1 + 1);
	FUN_1000_16ba(0xff);
	FUN_1000_1c22(1,0x18,1,0x27,9);
	FUN_1000_16ba(0x10);
	local_4 = 0xd;
	for (si = 0xd; si != 0; si = si - 1) {
		FUN_1000_16ba(0x11);
	}
	FUN_1000_16ba(0x13);
	for (si = 1; si != param_1; si = si + 1) {
		FUN_1000_1bf2(0, si);
		FUN_1000_16ba(0x17);
		FUN_1000_1bf2(0xe, si);
		FUN_1000_16ba(0x17);
	}
	local_4 = si;
	FUN_1000_16ba(10);
	FUN_1000_16ba(0x14);
	local_4 = 0xd;
	for (si = 0xd; si != 0; si = si - 1) {
		FUN_1000_16ba(0x15);
	}
	FUN_1000_16ba(0x16);
}

// OK P1
// F_0518
int FUN_ZSTATS__01e6f8(int param_2, uint param_1)
{
	S_55a8* local_4 = &DAT_55a8[param_2];

	return local_4->_19 == param_1 ||
		local_4->_1a == param_1 ||
		local_4->_1b == param_1 ||
		local_4->_1c == param_1 ||
		local_4->_1d == param_1 ||
		local_4->_1e == param_1;
}

// OK P1
// F_056C
int FUN_ZSTATS__01e74c(int param_3, int notused, char* param_2, int param_1)
{
	while (1) {
		if (--param_3 >= 0) {
			if (param_2[param_3] == 0) {
				if (param_1 == 0xff)
					continue;
				if (FUN_ZSTATS__01e6f8(param_1, param_3) == 0)
					continue;
			}

			return param_3;
		}

		break;
	}

	return -1;
}

// OK P1
// F_05A4
int FUN_ZSTATS__01e784(int param_4, int param_3, char* param_2, int param_1)
{
	while (1) {
		if (++param_4 < param_3) {
			if (param_2[param_4] == 0) {
				if (param_1 == 0xff)
					continue;
				if (FUN_ZSTATS__01e6f8(param_1, param_4) == 0)
					continue;
			}

			return param_4;
		}

		break;
	}

	return -1;
}

// OK P1
// F_05E2
void FUN_ZSTATS__01e7c2(int param_4,byte* param_3,TEXT* param_2,uint param_1)
{
	char local_6;
	int local_4;

	local_6 = param_3[param_4];
	if (local_6 != -1) {
		if (local_6 != '\0') {
			FUN_1000_1a3e((byte)local_6, 2, 0x20);
		} else {
			FUN_1000_1850(TEXT_9778);
		}
		if (param_1 < 0x20) {
			FUN_1000_1c9e(1);
		}
		FUN_1000_16ba(param_1);
		FUN_1000_1c9e(0);
	}

	if (param_2[param_4].text[0] == '*') {
		FUN_1000_1c9e(1);
		FUN_1000_1850(TEXT_977c);
		FUN_1000_1850(&param_2[param_4].text[1]);
		FUN_1000_1c9e(0);
	} else if (param_2[param_4].text[0] == '!') {
		FUN_1000_1c9e(1);
		FUN_1000_1850(TEXT_9782);
		FUN_1000_1c9e(0);
		FUN_1000_1850(&D_19B2[param_4]); // NOT MATCHING
	} else if (param_2[param_4].text[0] == '(') {
		FUN_1000_1850(TEXT_9788);
		FUN_1000_1c9e(1);
		FUN_1000_16ba((byte)param_2[param_4].text[1]);
		FUN_1000_1c9e(0);
	} else {
		FUN_1000_1850(param_2[param_4].text);
	}

L_0:
	local_4 = FUN_1000_1f12();
	if (local_4 < 0xe) {
		register int si = 0xe - local_4;
		local_4 += si;

		do {
			FUN_1000_16ba(0x20);
			si--;
		} while (si != 0);
	}
	FUN_1000_16ba(10);
}

#define false 0
#define true 1

// TODO: Match
int FUN_ZSTATS__01e8c8(void *param_4, int param_3, byte *param_2, TEXT* param_1)
{
	int local_10;
	int local_e;
	int local_c;
	int local_a;
	bool local_8;
	int local_6;
	int local_4;

	FUN_1000_4e50(param_4);
	FUN_ZSTATS__01e63e(8);
	local_8 = false;
	local_6 = FUN_ZSTATS__01e784(0xffff,param_3,param_2,0xff);
	if (local_6 == -1) {
		FUN_ZSTATS__01e63e(8);
		FUN_1000_1bf2(1,4);
		FUN_1000_1850(TEXT_9794);
		FUN_1000_4daa();
		FUN_1000_1b94(2);
		return FUN_1000_266c();
	} else {
		// LAB_ZSTATS__01eb0d
		while (!local_8) {
			FUN_1000_1b94(1); // eb17
			FUN_1000_1bf2(1,1); // eb1f

			for (local_c = local_6;
				local_c != -1;
				local_c = FUN_ZSTATS__01e784(local_c,param_3,param_2,0xff)) {

				FUN_ZSTATS__01e7c2(local_c,param_2,param_1,0x2d);

				FUN_1000_1bf2(1, FUN_1000_1cee());
				if (FUN_1000_1cee() == 8)
					break;
			}

			// LAB_ZSTATS__01e95f
			local_10 = 0;
			if (FUN_ZSTATS__01e74c(local_6,param_3,param_2,0xff) != -1) {
				local_10 = 2;
			}

			// LAB_ZSTATS__01e97c
			if ((local_c != -1) && (FUN_ZSTATS__01e784(local_c,param_3,param_2,0xff) != -1)) {
				local_10++;
			}
			
			// LAB_ZSTATS__01e998
			switch (local_10) {
				case 0:
					FUN_1000_4daa();
					// to 01e9b3
					break;
				case 1:
					FUN_1000_4dea(0x19);
					// to 01e9b3
					break;
				case 2:
					FUN_1000_4dea(0x18);
					break;
				case 3:
					FUN_1000_4dea(0x12);
					break;
			}
			
			// LAB_ZSTATS__01e9b3
			FUN_1000_1b94(2);
			local_e = FUN_1000_266c();
			if (local_e == 0x20) {
				// LAB_ZSTATS__01eb28
				local_8 = 1;
				continue;
			} else if (local_e <= 0x20) { // e9c8
				// e9cd
				if (local_e == 3) {
					// e9fc
					if (local_e == 0xd5) {
						local_4 = 7;
					} else {
						// ea0a
						local_4 = 1;
					}
					// ea0f
					for (local_a = 0; local_a < local_4; local_a++) {
						if (FUN_ZSTATS__01e74c(local_6,param_3,param_2,0xff) != -1) {
							local_6 = FUN_ZSTATS__01e74c(local_6,param_3,param_2,0xff);
						}
					}
					continue;
				}
				if (local_e <= 3) {
					// e9d7
					if (local_e >= 1) {
						// e9df
						if (local_e <= 2) {
							// eb28
							local_8 = 1;
							continue;
						}
						continue;
					}
					continue;
				}
				// eb30
				if (local_e == 4) {
					// ea4c
					if (local_e == 0xd6) {
						local_4 = 7;
					} else {
						local_4 = 1;
					}
					// ea5f
					for (local_a = 0; local_a < local_4; local_a++) {
						if ((local_c != -1) && (FUN_ZSTATS__01e784(local_c,param_3,param_2,0xff) != -1)) {
							local_6 = FUN_ZSTATS__01e784(local_6,param_3,param_2,0xff);
							local_c = FUN_ZSTATS__01e784(local_c,param_3,param_2,0xff);
						}
					}
					continue;
				}
				// eb38
				if (local_e == 0x1b) {
					// eb28
					local_8 = 1;
					continue;
				}
				continue;
			} else if (local_e == 0xd3) { // eb40
				// eab6
				local_6 = FUN_ZSTATS__01e784(0xffff,param_3,param_2,0xff);
				continue;
			} else if (local_e <= 0xd3) { // eb48
				if (local_e < 0x30) {
					continue;
				}
				if (local_e <= 0x36) { // eb52
					//eb28
					local_8 = 1;
					continue;
				}
				continue;
			} else if (local_e == 0xd4) { // eb56
				// eacc
				local_6 = FUN_ZSTATS__01e74c(param_3,param_3,param_2,0xff);
				local_a = 0;
				// eaef
				while (local_a < 6 && FUN_ZSTATS__01e74c(local_6,param_3,param_2,0xff) != -1) {
					// eae6
					local_6 = local_c;
					local_a++;
				}
				continue;
			} else if (local_e == 0xd5) { // eb5e
				// TODO: same with local_e == 3
				// e9fc
				if (local_e == 0xd5) {
					local_4 = 7;
				} else {
					//ea0a
					local_4 = 1;
				}
				// ea0f
				for (local_a = 0; local_a < local_4; local_a++) {
					if (FUN_ZSTATS__01e74c(local_6,param_3,param_2,0xff) != -1) {
						local_6 = FUN_ZSTATS__01e74c(local_6,param_3,param_2,0xff);
					}
				}
				continue;
			} else if (local_e == 0xd6) { // eb66
				// TODO: same with local_e == 4
				// ea4c
				if (local_e == 0xd6) {
					local_4 = 7;
				} else {
					local_4 = 1;
				}
				for (local_a = 0; local_a < local_4; local_a++) {
					if ((local_c != -1) && (FUN_ZSTATS__01e784(local_c,param_3,param_2,0xff) != -1)) {
						local_6 = FUN_ZSTATS__01e784(local_6,param_3,param_2,0xff);
						local_c = FUN_ZSTATS__01e784(local_c,param_3,param_2,0xff);
					}
				}
				continue;
			}
			// eb6e
			continue;
		}
	}
	
	return local_e;
}

// OK P1
// F_099A
void FUN_ZSTATS__01eb7a()
{
	int local_4;

	local_4 = 0;
	do {
		UNK_0000_b9ee[local_4] = UNK_0000_5820[local_4];
		UNK_0000_b9f6[local_4] = UNK_0000_5828[local_4];
		UNK_0000_ba03[local_4] = (UNK_0000_5840[local_4] == 0xff) ? 0xff : 0;
	} while (++local_4 < 8);

	UNK_0000_b9fe = UNK_0000_57b0;
	UNK_0000_b9ff = UNK_0000_57b1;
	UNK_0000_ba00 = UNK_0000_57b3;
	UNK_0000_ba01 = UNK_0000_57b4;
	UNK_0000_ba02 = UNK_0000_57b5;

	for (local_4 = 0; local_4 < 3; local_4++) {
		UNK_0000_ba0b[local_4] = UNK_0000_57b6[local_4];
	}

	UNK_0000_ba0e = UNK_0000_57ba;
	UNK_0000_ba0f = (UNK_0000_57bb != '\0') ? 0xff : 0;
	UNK_0000_ba10 = UNK_0000_57bc;
	UNK_0000_ba11 = UNK_0000_57bd;
	UNK_0000_ba12 = UNK_0000_57be;
	UNK_0000_ba13 = UNK_0000_57bf;
}

// TODO: Match
// F_0a3a
void FUN_ZSTATS__01ec1a()
{
	int local_8;
	byte local_6;
	uint local_4;
  
	local_8 = FUN_ZSTATS__01e1e0(1);
	if (local_8 == -2) {
		local_8 = 6;
	} else if (local_8 < 0) {
		return;
	}
	// ec3f
	FUN_1000_1850(TEXT_97a2);
	FUN_ZSTATS__01eb7a();
	FUN_1000_4efc();
	local_4 = local_8 << 1;
	local_6 = 0;
	// ^OK
	// ec58
	do {
		do {
			if (local_6 != 0x20 && local_6 != 0x1b) {
				if ((unsigned int)local_6 == 3 || local_6 == 1) {
					if (local_4 == 0xc) {
						local_4 = (uint)*(byte *)0x585b * 2 - 1;
					}
					else if ((int)local_4 < 1) {
						local_4 = 0x10;
					}
					else {
						local_4 = local_4 - 1;
					}
				} else {
					if (local_6 == 2 || local_6 == 4) {
						if ((uint)*(byte *)0x585b * 2 - 1 != local_4) {
							if ((int)local_4 < 0x10) {
								local_4 = local_4 + 1;
							} else {
								local_4 = 0;
							}
							break;
						}
					} else if (local_6 > 4) {
						if (local_6 != 0x30) {
							if (((0x30 < local_6) && (local_6 < 0x37)) && (local_6 - 0x31 < (uint)*(byte *)0x585b)) {
								local_4 = (uint)local_6 * 2 - 0x62;
							}
							break;
						}
					}
					local_4 = 0xc;
				}
			} else {
				FUN_1000_4daa();
				FUN_1000_4e20();
				FUN_1000_4f3c();
				FUN_1000_2900();
				FUN_1000_1850(TEXT_97ce);
				return;
			}
		} while (false);

		// ecab
		FUN_1000_1b94(1);
		if ((int)local_4 < 0xc) {
			if ((local_4 & 1) == 0) {
				FUN_ZSTATS__01e262((int)local_4 >> 1);
			} else {
				FUN_ZSTATS__01e488((int)local_4 >> 1);
			}

			// ed3f
			FUN_1000_1b94(2);
			local_6 = FUN_1000_266c();
			continue;
		}
		if (local_4 == 0xc) {
			FUN_ZSTATS__01e57c();

			// ed3f
			FUN_1000_1b94(2);
			local_6 = FUN_1000_266c();
			continue;
		}
		if (local_4 == 0xd) {
			// ed6a
			//int FUN_ZSTATS__01e8c8(void *param_4, int param_3, char *param_2, TEXT* param_1)
			local_6 = FUN_ZSTATS__01e8c8(&TEXT_97ac,8,DAT_0000_5850,D_19D2);
		} else if (local_4 == 0xe) {
			local_6 = FUN_ZSTATS__01e8c8(&TEXT_97b6,0x30,DAT_0000_58f0,D_19E2);
		} else if (local_4 == 0xf) {
			local_6 = FUN_ZSTATS__01e8c8(&TEXT_97be,0x26,UNK_0000_b9ee,D_1916);
		} else if (local_4 == 0x10) {
			local_6 = FUN_ZSTATS__01e8c8(&TEXT_97c4,0x30,DAT_0000_57c0,D_1962);
		}
	} while (true);
}

// OK P1
// F_0BEE
void FUN_ZSTATS__01edce(char* param_1)
{
	FUN_1000_1850(TEXT_97d4);
	FUN_1000_1850(param_1);
	FUN_1000_1850(TEXT_97d8);
}

// OK P1
// F_0c0a
undefined2 FUN_ZSTATS__01edea(int param_1)
{
	S_55a8* s = &DAT_55a8[param_1];

	if ((s->_1b == 0xff) && (s->_1c == 0xff)) {
		return 2;
	} else if (s->_1b == 0xff) {
		return 0;
	} else if ((s->_1c == 0xff) && (D_1A7E[s->_1b] != '0')) {
		return 1;
	} else {
		return 0xff;
	}
}

// F_0c5c
// 아이템 착용?
// param_2: whom?
// param_1: item_id?
undefined2 FUN_ZSTATS__01ee3c(int param_2, int param_1)
{
	byte *local_10;
	int local_e;
	int local_c;
	int local_a;
	int local_8;
	byte *local_6;
	int local_4;
  
    // OK P1
	if (0x7f < DAT_5893) {
		local_6 = &UNK_0000_5c5a[UNK_0000_ba18[UNK_0000_589e * 8] * 8];
	}

	// ee62
    // OK P1
	if (param_1 == 0x1b || param_1 == 0x1d) {
		return 0;
	}
	// ee74
	if (9 <= param_1 && param_1 <= 0xf && 0x7f < DAT_5893 && DAT_58a3 == 0) { // OK P1
        // NOT MATCHING
		FUN_ZSTATS__01edce(TEXT_97e2); // "Thou canst not change armour in heated battle!"
		return 0;
	}
	// ee94
    // OK P1 (NOT MATCHING 55a8)
	if (FUN_ZSTATS__01e6f8(param_2, param_1) != 0) {
		FUN_1000_6e60(param_2, param_1);
		if (DAT_0000_57c0[param_1] < 99) {
			DAT_0000_57c0[param_1]++;
		}
		// eeb8
		if (DAT_5893 <= 0x7f) {
			return 0;
		}
		if (param_1 != 0x2a) {
			return 0;
		}
		local_8 = FUN_1000_4d76(&TEXT_9812, DAT_55a8[param_2]._a);
		// ..eee8
		local_6[0] = local_6[1] = D_1ADE[local_8];
		return 0;
	}
	if ((((param_1 == 0x1a) || (param_1 == 0x24)) && (UNK_0000_57db == '\0')) ||
		((param_1 == 0x1c && (UNK_0000_57dd == '\0')))) { // OK P1
        // NOT MATCHING
		FUN_ZSTATS__01edce(TEXT_981c); // "Thou hast no ammunition for that weapon!"
		return 0;
	}

	// ef16
    // OK P1 (NOT MATCHING 55a8)
	local_4 = 0;
	local_10 = &DAT_55a8[param_2]._19;
	local_a = 6;

	// ef30
    // OK P1 (NOT MATCHING 55a8)
	for (local_a = 0; local_a < 6; local_a++) {
		if (*local_10 != 0xff) {
			local_4 += D_1AAE[*local_10];
		}
		// ef41
		local_10++;
	}

    // OK P1 (NOT MATCHING 55a8)
	local_e = D_1AAE[param_1] + local_4 <= DAT_55a8[param_2]._c/*strength*/;

	// ef6e
	switch ((uint)(byte)D_1A7E[param_1])
	{
		case 2:
			// f0be
			if (DAT_55a8[param_2]._1d != -1) {
				FUN_ZSTATS__01edce(TEXT_9916); // "Only one magic ring may be worn at a time!"
				return 0;
			}
			// f0d2..efc6
			local_10 = &DAT_55a8[param_2]._1d;
			break;
		case 4:
			// f09c
			if (DAT_55a8[param_2]._1e != -1) {
				FUN_ZSTATS__01edce(TEXT_98f0); // "Thou must remove thine other amulet!"
				return 0;
			}
			// f0b0..efc6
			local_10 = &DAT_55a8[param_2]._1e;
			break;
		case 0x20:
			// f04e
			local_c = FUN_ZSTATS__01edea(param_2);
			if (local_c == 0xff) {
				FUN_ZSTATS__01edce(TEXT_9892); // "Thou must free one of thy hands first!"
				return 0;
			}
			// f062
			if (local_c == 2) {
				local_c = 0;
			}
			// f06d..f077..efc6
			local_10 = &DAT_55a8[param_2]._1b + local_c;
			break;
		case 0x30:
			// f07e
			local_c = FUN_ZSTATS__01edea(param_2);
			if (local_c != 2) {
				FUN_ZSTATS__01edce(TEXT_98ba); // "Both hands must be free before thou canst wield that!"
				return 0;
			}
			// f092..f077..efc6
			local_10 = &DAT_55a8[param_2]._1b;
			break;
		case 0x40:
			// f02c
			if (DAT_55a8[param_2]._1a != 0xff) {
				FUN_ZSTATS__01edce(TEXT_9866); // "Thou must first remove thine other armour!"
				return 0;
			}
			// f040..efc6
			local_10 = &DAT_55a8[param_2]._1a;
			break;
		case 0x80:
			// efa7
			if (DAT_55a8[param_2]._19 != 0xff) {
				FUN_ZSTATS__01edce(TEXT_9846); // "Remove first thy present helm!"
				return 0;
			}
			// efbc
			local_10 = &DAT_55a8[param_2]._19;
			break;
	}

	// efc9
	if (local_e == 0) {
		// f0e0
		FUN_ZSTATS__01edce(TEXT_9942); // "Thou art not strong enough!"
		return 0;
	} else {
		// efd2
		*local_10 = param_1;
        --DAT_0000_57c0[param_1];
		if ((DAT_0000_57c0[param_1] == 0x2a || DAT_0000_57c0[param_1] == 0x2c) && (FUN_1000_2092(0, 0xf) == 0)) {
			// efff
			FUN_1000_1850(TEXT_995e); // "\n\nRing vanishes!\n"
			DAT_55a8[param_2]._1d = 0xff;
			FUN_1000_43ae(0x4b0,2000,1,0x28);
			return 1;
		} else {
			// f0e6
			if (param_1 != 0x2a) {
				// ee6e
				return 0;
			}
			// f0ef
			if (DAT_5893 <= 0x7f) {
				// ee6e
				return 0;
			}
			// f0f9
			local_6[1] = 0x1d;

			// eee8
			local_6[0] = 0x1d;

			// ee6e
			return 0;
		}
	}
}

int FUN_ZSTATS__01f10e(int param_3, undefined2 param_2, int param_1)
{
	int local_1e;
	int local_1c;
	int local_1a;
	int local_18;
	int local_16;
	byte* local_14; // char*?
	int local_12;
	int local_10;
	int local_e;
	int local_c;
	int local_a;
	int local_8;
	int local_6;
	int local_4;

	// f10e
	local_8 = 0;
	local_10 = 1;
	if (param_1 == 0x52) {
		local_14 = (byte*)0x57c0;
		local_a = 0x30;
	} else {
		local_14 = (byte*)0xb9ee;
		local_a = 0x26;
	}
	
	// f462
	if (local_8 != 0)
		return local_1a;

	// f142
	do {
		FUN_1000_1b94(1);
		FUN_1000_1bf2(1, 1);
		local_4 = 0;
		local_12 = param_3;
		
		// f20b
		do {
			if (local_12 == 0xffff) {
				// f1a4
				local_18 = 0;
				if (FUN_ZSTATS__01e74c(param_3, local_a, local_14, param_2) + 1 != 0) {
					local_18 = 2;
				}
				// f1c0
				if (local_12 != -1) {
					if (FUN_ZSTATS__01e784(local_12, local_a, local_14, param_2) + 1 != 0) {
						local_18++;
					}
				}
				// ->f1db
				break;
			} else {
				// f213
				local_4++;
				if (FUN_1000_1cee() == local_10) {
					FUN_1000_16ba(0xfd);
					local_1a = local_12;
				}
				
				// f22b
				if (param_1 != 0x52) {
					// f170..f17e
					FUN_ZSTATS__01e7c2(local_12, local_14, (TEXT*)0x1916, 0x20);
				} else {
					// f234
					if (FUN_ZSTATS__01e6f8(param_2, local_12) != 0) {
						// f244
						local_c = D_1AE8[local_12];
					} else {
						// f15c
						local_c = 0x20;
					}
					// f161..f17e
					FUN_ZSTATS__01e7c2(local_12, local_14, (TEXT*)0x1962, local_c);
				}

				// f181
                // 파라미터 개수가 적다. sic
                // OK P1
				FUN_1000_1bf2(FUN_1000_1cee(1));
				if (FUN_1000_1cee() - 1 == local_10) {
					FUN_1000_16ba(0xfd);
				}

				// f19c
				if (FUN_1000_1cee() == 0x8) {
					// f1a4
					local_18 = 0;
					if (FUN_ZSTATS__01e74c(param_3, local_a, local_14, param_2) != -1) {
						local_18 = 2;
					}
					// f1c0
					if (local_12 != -1) {
						if (FUN_ZSTATS__01e784(local_12, local_a, local_14, param_2) != -1) {
							local_18++;
						}
					}
					// -> f1db
					break;
				} else {
					// f1fc
					local_12 = FUN_ZSTATS__01e784(local_12, local_a, local_14, param_2);
					// -> f20b
					continue;
				}
			}
		} while (true);

		// f1db
		if (local_18 != 0) {
			if (local_18 == 1) {
				// f28a..f28d
				FUN_1000_4dea(0x19);
			} else if (local_18 == 2) {
				// f294..f28d
				FUN_1000_4dea(0x18);
			} else if (local_18 == 3) {
				// f29a..f28d
				FUN_1000_4dea(0x12);
			}
		} else {
			// f254
			FUN_1000_4daa();
		}

        // L_1077
		// f257
		FUN_1000_1b94(2);
		local_16 = FUN_1000_266c();
        
        switch (local_16)
        {
            // OK P1
            case 1:
            case 3:
            case 0xd5:
                // 10c0
                if (local_16 == 0xd5)
                    local_6 = 7;
                else
                    local_6 = 1;
                local_e = 0;
                if (local_6 > 0)
                {
                    register int si;
                    register int di;
                    // 10e1
                    local_1c = local_6;
                    local_e += local_6;
                    di = param_3;
                    si = local_10;

                    // 10f0
                    do
                    {
                        if (si == 4 || si == 1)
                        {
                            // 10fa
                            if (F_056c(di, local_a, local_14, param_2) != -1)
                            {
                                di = F_056c(di, local_a, local_14, param_2);
                            }
                            else
                            {
                                // 111c
                                if (si == 4)
                                {
                                    // 1121
                                    si--;
                                }
                            }
                        }
                        else
                        {
                            // 1121
                            si--;
                        }
                        // 1122
                    } while (--local_1c != 0);
                    
                    param_3 = di;

                    // 112a
                    local_10 = si;
                }
                break;

            // OK P1
            case 2:
            case 4:
            case 0xd6:
                // 1130
                if (local_16 == 0xd6)
                    local_6 = 7;
                else
                    local_6 = 1;
                local_e = 0;
                if (local_6 > 0)
                {
                    register int si;
                    register int di;
                    // 1151
                    local_1e = local_6;
                    local_e += local_6;
                    di = local_12;
                    si = local_10;
                    
                    // 1160
                    do
                    {
                        if (si == 4 || si == 7 || si > local_4)
                        {
                            // 116f
                            if (di != 0xffff && F_05a4(di, local_a, local_14, param_2) != -1)
                            {
                                param_3 = F_05a4(param_3, local_a, local_14, param_2);
                                di = F_05a4(di, local_a, local_14, param_2);
                            }
                            else
                            {
                                // 11a8
                                if (si == 4 && local_4 == 4)
                                {
                                    si++;
                                }
                            }
                        }
                        else
                        {
                            // 11b3
                            si++;
                        }
                        // 11b4
                    } while (--local_1e != 0);
                    
                    local_12 = di;

                    // 112a
                    local_10 = si;
                }
                break;

            case 0xd:
            case 0x20:
                // -> 121c;
                // f3fc
                if (param_1 == 0x52) {
                    local_8 = FUN_ZSTATS__01ee3c(param_2, local_1a);
                } else {
                    // f410
                    local_8 = 1;
                }
                // -> f462
                break;
            case 0x1b:
                // 1238
                // OK P1
                FUN_1000_1850(param_1 == 0x52 ? TEXT_9970 : TEXT_9976);
				local_8 = 1;
				local_1a = 0xffff;
				
				// -> f462
                break;
            case 0xd3:
                // 11C0
                // OK P1
				// f3a0
				param_3 = FUN_ZSTATS__01e784(0xffff, local_a, local_14, param_2);
				local_10 = 1;
				// -> f462
                break;
            case 0xd4:
                {
                    // OK P1
                    // f3bc
                    // L_11dc
                    param_3 = FUN_ZSTATS_01e74c(local_a, local_a, local_14, param_2);

                    local_10 = 1;
                    do {
                        // f3d1
                        // L_11f1
                        local_1a = FUN_ZSTATS_01e74c(param_3, local_a, local_14, param_2);
                        if (local_1a == -1)
                        {
                            // L_1207
                            break;
                        }
                        // f3e7
                        // L_1210
                        param_3 = local_1a;
                        local_10++;
                    } while (local_10 < 7);
                    // -> f462
                }
                break;
        }
		// f462
	} while (local_8 == 0); // -> f142

	return local_1a;
}

// OK P1
void F_1296(void)
{
    // NOT MATCHING: STACK
    int local_6;
    int local_4;

    local_6 = FUN_ZSTATS__01e1e0(0);

    if (local_6 < 0)
        goto END;

    local_4 = FUN_ZSTATS__01e784(0xFFFF, 0x30, (byte*)0x57C0, local_6);

    if (local_4 == 0xFFFF)
    {
        SUB_0000_3670(0x997E);  // "Thou art empty-\nhanded!\n"
        goto END;
    }

    SUB_0000_3670(0x9998);     // "Item: "
    SUB_0000_6d1c();
    SUB_0000_39b4(1);

    SUB_0000_6c70(&DAT_55a8[local_6]);

    FUN_ZSTATS__01e63e(0x08);

    FUN_ZSTATS__01f10e(local_4, local_6, 0x52);

    SUB_0000_6bca();
    SUB_0000_6c40();
    SUB_0000_6d5c();
    SUB_0000_4720();

END:
    return;
}
