
typedef char i8;
typedef int i16;

typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned int uint;
typedef int bool;

typedef int undefined;
typedef int undefined2;

/* size: 0x20; 55a8..55c7 * n */
typedef struct S_55a8
{
	int _0;		// 55a8
	int _2;		// 55aa
	int _4;		// 55ac
	int _6;		// 55ae
	byte _8;	// 55b0
	byte _9;	// 55b1
	byte _a;	// 55b2
	byte _b;	// 55b3
	byte _c;	// 55b4
	byte _d;	// 55b5
	byte _e;	// 55b6
	byte _f;	// 55b7
	int _10;	// 55b8
	int _12;	// 55ba
	int _14;	// 55bc
	byte _16;	// 55be
	byte _17;	// 55bf
	byte _18;	// 55c0
	byte _19;	// 55c1
	byte _1a;	// 55c2
	byte _1b;	// 55c3
	byte _1c;	// 55c4
	byte _1d;	// 55c5
	byte _1e;	// 55c6
	byte _1f;	// 55c7
} S_55a8;

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

extern char DAT_0000_58f0[0];

extern char UNK_0000_5820[8];
extern char UNK_0000_5828[8];
extern char UNK_0000_5840[8];

extern char DAT_0000_5850[0];

extern byte UNK_0000_5893;
extern byte UNK_0000_589e;
extern S_55a8* D_55a8;
extern int DAT_0000_96b4;
extern int DAT_0000_96be;
extern int DAT_0000_96c6;
extern int DAT_0000_96d0;
extern int DAT_0000_96d6;
extern int DAT_0000_96dc;
extern int DAT_0000_96e2;
extern int DAT_0000_96e8;
extern int DAT_0000_96ee;
extern int DAT_0000_96f4;
extern int DAT_0000_96fa;
extern int DAT_0000_9700;
extern int DAT_0000_970e;
extern int DAT_0000_9716;
extern int DAT_0000_9716;
extern int DAT_0000_9724;
extern int DAT_0000_972e;
extern int DAT_0000_9738;
extern int DAT_0000_9742;
extern int DAT_0000_9752;
extern int DAT_0000_9760;
extern int DAT_0000_976e;
extern int DAT_0000_9778;
extern int DAT_0000_977c;
extern int DAT_0000_9782;
extern int DAT_0000_9788;
extern int DAT_0000_9794;

extern int DAT_0000_97ac;
extern int DAT_0000_97b6;
extern int DAT_0000_97be;
extern int DAT_0000_97c4;

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

extern void FUN_1000_16ba(int);
extern void FUN_1000_1850(void *);
extern void FUN_1000_1a3e(int, int, int);
extern void FUN_1000_1c22(int, int, int, int, int);
extern int FUN_1000_1cee();
extern void FUN_1000_1bf2(int, int);
extern void FUN_1000_16ba(int);
extern void FUN_1000_1bf2(int, int);

extern int FUN_1000_2d7a(/*?*/);
extern void FUN_1000_4daa();
extern void FUN_1000_4e50(void *);

typedef struct TEXT {
	char* text;
} TEXT;

TEXT D_1916[0];
int D_1A44[0];
int D_1A58[0];
TEXT D_1962[0];
int D_1A6A[0];
int* D_19B2;
TEXT D_19D2[0];
TEXT D_19E2[0];

// OK P1
int FUN_ZSTATS_01e1e0(int param_1)
{
	// NOT MATCHING: STACK
	int local_4;
	register int si;

	local_4 = -1;

	if (UNK_0000_5893 > 0x80) {
		si = UNK_0000_589e * 8;
		if ((D_BA16[si] & 0x80) == 0)
			goto L_202e; // TODO: remove goto

		local_4 = D_BA16[si + 1];
	} else {
L_202e:
		// 202e
		FUN_1000_1850(&DAT_0000_96b4);
		local_4 = FUN_1000_2d7a(param_1);
		if (local_4 >= 0) {
			FUN_1000_1850(&D_55a8[local_4]);
			if (FUN_1000_1f12() != 0) {
				FUN_1000_16ba(10);
			}
		}
	}

	// 205b
	if (local_4 == 0xffff) {
		FUN_1000_1850(&DAT_0000_96be);
	}
	// 206a
	else if (local_4 == 0xfffe) {
		FUN_1000_16ba(10);
	}

	// 2077
	return local_4;
}

// OK P1
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

	local_4 = &D_55a8[param_1];

	FUN_1000_4e50(local_4);
	FUN_1000_1c22(1, 0x18, 1, 0x26, 9);
	FUN_1000_16ba(0xff);
	FUN_1000_1c22(1, 0x18, 1, 0x27, 9);

	local_6 = FUN_1000_4d76(&DAT_0000_96c6, local_4->_a);
	local_a = FUN_1000_4d76(&DAT_0000_96d0, local_4->_b);
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
	FUN_1000_1850(&DAT_0000_96d6);
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
	FUN_1000_1850(&DAT_0000_96dc);
	FUN_1000_1a3e(local_4->_c,2,0x30);
	FUN_1000_1850(&DAT_0000_96e2);
	FUN_1000_1a3e(local_4->_10,4,0x20);
	FUN_1000_1850(&DAT_0000_96e8);
	FUN_1000_1a3e(local_4->_e,2,0x30);
	FUN_1000_1850(&DAT_0000_96ee);
	FUN_1000_1a3e(local_4->_12,4,0x20);
	FUN_1000_1850(&DAT_0000_96f4);
	FUN_1000_1a3e(local_4->_d,2,0x30);
	FUN_1000_1850(&DAT_0000_96fa);
	FUN_1000_1a3e(local_4->_14,4,0x20);
	FUN_1000_1850(&DAT_0000_9700);
	FUN_1000_1a3e(local_4->_f,2,0x20);
}

// OK P1
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
void FUN_ZSTATS__01e488(int param_1)
{
	int local_4;
	S_55a8* local_6;

	FUN_1000_4daa();

	local_6 = &D_55a8[param_1];
	FUN_1000_4e50(local_6);
	FUN_1000_1c22(1,0x18,1,0x26,9);
	FUN_1000_16ba(0xff);
	FUN_1000_16ba(0xfc);
	FUN_1000_16ba(0xfe);
	FUN_1000_1850(&DAT_0000_970e);
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
		FUN_1000_1850(&DAT_0000_9716);
		FUN_1000_16ba(0xfb);
	}

	FUN_1000_1c22(1,0x18,1,0x27,9);
}

// OK P1
void FUN_ZSTATS__01e57c()
{
	FUN_1000_4daa();
	FUN_1000_4e50(&DAT_0000_9724);
	FUN_1000_1c22(1,0x18,1,0x26,9);
	FUN_1000_16ba(0xff);
	FUN_1000_1c22(1,0x18,1,0x27,9);
	FUN_1000_1850(&DAT_0000_972e);
	FUN_1000_1a3e(UNK_0000_57a8,4,0x20);
	FUN_1000_1850(&DAT_0000_9738);
	FUN_1000_1a3e(UNK_0000_57aa,4,0x20);
	FUN_1000_1850(&DAT_0000_9742);
	FUN_1000_1a3e(UNK_0000_57ac,2,0x20);
	FUN_1000_1850(&DAT_0000_9752);
	FUN_1000_1a3e(UNK_0000_57ad,2,0x20);
	FUN_1000_1850(&DAT_0000_9760);
	FUN_1000_1a3e(UNK_0000_57ae,2,0x20);
	if (UNK_0000_57af != '\0') {
		FUN_1000_1850(&DAT_0000_976e);
	}
}

// OK P1
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
int FUN_ZSTATS__01e6f8(int param_2, uint param_1)
{
	S_55a8* local_4 = &D_55a8[param_2];

	return local_4->_19 == param_1 ||
		local_4->_1a == param_1 ||
		local_4->_1b == param_1 ||
		local_4->_1c == param_1 ||
		local_4->_1d == param_1 ||
		local_4->_1e == param_1;
}

// OK P1
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
void FUN_ZSTATS__01e7c2(int param_4,byte* param_3,TEXT* param_2,uint param_1)
{
	char local_6;
	int local_4;

	local_6 = param_3[param_4];
	if (local_6 != -1) {
		if (local_6 != '\0') {
			FUN_1000_1a3e((byte)local_6, 2, 0x20);
		} else {
			FUN_1000_1850(&DAT_0000_9778);
		}
		if (param_1 < 0x20) {
			FUN_1000_1c9e(1);
		}
		FUN_1000_16ba(param_1);
		FUN_1000_1c9e(0);
	}

	if (param_2[param_4].text[0] == '*') {
		FUN_1000_1c9e(1);
		FUN_1000_1850(&DAT_0000_977c);
		FUN_1000_1850(&param_2[param_4].text[1]);
		FUN_1000_1c9e(0);
	} else if (param_2[param_4].text[0] == '!') {
		FUN_1000_1c9e(1);
		FUN_1000_1850(&DAT_0000_9782);
		FUN_1000_1c9e(0);
		FUN_1000_1850(&D_19B2[param_4]); // NOT MATCHING
	} else if (param_2[param_4].text[0] == '(') {
		FUN_1000_1850(&DAT_0000_9788);
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
int FUN_ZSTATS__01e8c8(void *param_4, int param_3, char *param_2, TEXT* param_1)
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
		FUN_1000_1850(&DAT_0000_9794);
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
	FUN_1000_1850((void*)0x97a2);
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
				FUN_1000_1850((void*)0x97ce);
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
			local_6 = FUN_ZSTATS__01e8c8(&DAT_0000_97ac,8,DAT_0000_5850,D_19D2);
		} else if (local_4 == 0xe) {
			local_6 = FUN_ZSTATS__01e8c8(&DAT_0000_97b6,0x30,DAT_0000_58f0,D_19E2);
		} else if (local_4 == 0xf) {
			local_6 = FUN_ZSTATS__01e8c8(&DAT_0000_97be,0x26,UNK_0000_b9ee,D_1916);
		} else if (local_4 == 0x10) {
			local_6 = FUN_ZSTATS__01e8c8(&DAT_0000_97c4,0x30,DAT_0000_57c0,D_1962);
		}
	} while (true);
}
