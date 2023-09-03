
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


extern void FUN_1000_16ba(int);
extern void FUN_1000_1850(void *);
extern void FUN_1000_1a3e(int, int, int);
extern void FUN_1000_1c22(int, int, int, int, int);
extern void FUN_1000_1bf2(int, int);
extern void FUN_1000_16ba(int);
extern void FUN_1000_1bf2(int, int);

extern int FUN_1000_2d7a(/*?*/);
extern void FUN_1000_4daa();
extern void FUN_1000_4e50(void *);

int D_1962[0];
int D_1A44[0];
int D_1A58[0];
int D_1A6A[0];
byte D_BA16[0];

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
		FUN_1000_1850(&D_1962[param_1]);
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
	si = 0xd;
	do {
		FUN_1000_16ba(0x11);
		si = si - 1;
	} while (si != 0);
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
	si = 0xd;
	do {
		FUN_1000_16ba(0x15);
		si = si - 1;
	} while (si != 0);
	FUN_1000_16ba(0x16);
}
