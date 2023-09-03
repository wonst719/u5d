
typedef char i8;
typedef int i16;

typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned int uint;
typedef int bool;

typedef struct S_55a8
{
	int _0;
	int _2;
	int _4;
	int _6;
	byte _8;
	byte _9;
	byte _a;
	byte _b;
	byte _c;
	byte _d;
	byte _e;
	byte _f;
	int _10;
	int _12;
	int _14;
	byte _16;
	byte _17;
	byte _18;
	byte _19;
	byte _1a;
	byte _1b;
	byte _1c;
	byte _1d;
	byte _1e;
	byte _1f;
} S_55a8;

extern byte UNK_0000_5893;
extern byte UNK_0000_589e;
extern S_55a8* UNK_0000_55a8;
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

extern void FUN_0000_54da(int);
extern void FUN_0000_5670(/*?*/);
extern void FUN_0000_585e(int, int, int);
extern void FUN_0000_5a42(int, int, int, int, int);
extern void FUN_0000_5a12(int, int);
extern void FUN_0000_54da(int);
extern void FUN_0000_5a12(int, int);

extern void FUN_0000_6b9a(/*?*/);

int D_1962[0];
int D_1A44[0];
int D_1A58[0];
int D_1A6A[0];
byte D_BA16[0];

// OK P1
int FUN_0000_2000(int param_1)
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
		FUN_0000_5670(&DAT_0000_96b4);
		local_4 = FUN_0000_6b9a(param_1);
		if (local_4 >= 0) {
			FUN_0000_5670((int)&UNK_0000_55a8 + local_4 * 0x20);
			if (FUN_0000_5d32() != 0) {
				FUN_0000_54da(10);
			}
		}
	}

	// 205b
	if (local_4 == 0xffff) {
		FUN_0000_5670((int)&DAT_0000_96be);
	}
	// 206a
	else if (local_4 == 0xfffe) {
		FUN_0000_54da(10);
	}

	// 2077
	return local_4;
}

// OK P1
void FUN_0000_2082(int param_1)
{
	// NOT MATCHING: STACK
	int local_6;
	int local_8;
	int local_a;
	S_55a8* local_4;

	register int si;
	register int* di;

	FUN_0000_8bca();

	local_4 = &UNK_0000_55a8[param_1];

	FUN_0000_8c70(local_4);
	FUN_0000_5a42(1, 0x18, 1, 0x26, 9);
	FUN_0000_54da(0xff);
	FUN_0000_5a42(1, 0x18, 1, 0x27, 9);

	local_6 = FUN_0000_8b96(&DAT_0000_96c6, local_4->_a);
	local_a = FUN_0000_8b96(&DAT_0000_96d0, local_4->_b);
	local_8 = 0;

	if (0 < D_1A58[local_6]) {
		di = &D_1A58[local_6];
	
		si = local_8; // NOT MATCHING: OP
		for (;;) {
			FUN_0000_54da(0x20);
			si++;
			if (*di <= si)
				break;
		}
	
		local_8 = si;
	}

	FUN_0000_54da(local_4->_9);
	FUN_0000_5670(&DAT_0000_96d6);
	FUN_0000_585e(local_4->_16,1,0x20);
	FUN_0000_54da(0x20);
	FUN_0000_5670(D_1A44[local_6]);
	FUN_0000_5a42(1,0x18,1,0x26,9);
	FUN_0000_5a12(0,1);
	FUN_0000_54da(0xfc);
	FUN_0000_5670(D_1A6A[local_a]);
	FUN_0000_5a42(1,0x18,1,0x27,9);
	FUN_0000_5a12(0,3);
	FUN_0000_54da(0xfb);
	FUN_0000_5670(&DAT_0000_96dc);
	FUN_0000_585e(local_4->_c,2,0x30);
	FUN_0000_5670(&DAT_0000_96e2);
	FUN_0000_585e(local_4->_10,4,0x20);
	FUN_0000_5670(&DAT_0000_96e8);
	FUN_0000_585e(local_4->_e,2,0x30);
	FUN_0000_5670(&DAT_0000_96ee);
	FUN_0000_585e(local_4->_12,4,0x20);
	FUN_0000_5670(&DAT_0000_96f4);
	FUN_0000_585e(local_4->_d,2,0x30);
	FUN_0000_5670(&DAT_0000_96fa);
	FUN_0000_585e(local_4->_14,4,0x20);
	FUN_0000_5670(&DAT_0000_9700);
	FUN_0000_585e(local_4->_f,2,0x20);
}

bool FUN_0000_2278(int param_1)
{
	if (param_1 == 0xff) {
		return 0;
	} else {
		FUN_0000_54da(0x20);
		FUN_0000_5670(D_1962[param_1]);
		FUN_0000_54da(10);
		return 1;
	}
}
