#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include "GRAP_DRV.H"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FUN_1000_0991(int* ax, int* bx, int* cx, int* dx);
void FUN_1000_0a22(int ax, int bx, int cx, int dx, int* si, int* di);

void SWAP(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cdecl FUN_1000_02f4_exit_to_dos(int a)
{
    printf("FUN_1000_02F4_exit_to_dos(%d)\n", a);
    exit(a);
}

// stdcall
// 32bit multiply
// A_hi, A_lo, B_hi, B_lo
s32 FUN_1000_0442(int A_hi, uint A_lo, int B_hi, uint B_lo)
{
    printf("FUN_1000_0442(%d,%d,%d,%d)\n", A_hi, A_lo, B_hi, B_lo);
}

// 32bit div?
s32 FUN_1000_03a0(int a, int b, int c, int d)
{
    printf("FUN_1000_03a0(%d,%d,%d,%d)\n", a, b, c, d);
}

// memchr
void* cdecl FUN_1000_0402_memchr(void* param_1, int param_2, int param_3)
{
	// original: assembly
	return memchr(param_1, param_2, param_3);
}

// itoa
void cdecl FUN_1000_0426_itoa(int a, char* b, int c)
{
	// original: assembly
#ifdef _WIN32
    _itoa(a, b, c);
#else
    itoa(a, b, c);
#endif
}

void FUN_1000_0878_set_old_video_mode(void) { puts("FUN_1000_0878_set_old_video_mode"); }

// STUB
void FUN_1000_0892_initialize_video_driver(int a)
{
#ifdef _WIN32
	extern void GRAP_WIN_InitializeVideoDriver();

	GRAP_WIN_InitializeVideoDriver();
#endif
}

// register call
// AX, BX => CARRY
int FUN_1000_08ca_inside_clip_window(int ax, int bx)
{
	int x = ax;
	int y = bx;

	if (D_52ba_vdp._52d0 <= x && x <= D_52ba_vdp._52d2 &&
		D_52ba_vdp._52d4 <= y && y <= D_52ba_vdp._52d6)
	{
		return 0;
	}

	return -1;
}

// register call
int FUN_1000_08e6_constraint_imagewindow(int *x1, int *y1, int *x2, int *y2)
{
	if (*x1 > *x2)
		SWAP(x1, x2);

	// 08eb
	if (*y1 > *y2)
		SWAP(y1, y2);

	// 08f1
	if (*x1 < 0)
		*x1 = 0;

	// 08f9
	if (*x1 > 319)
		*x1 = 319;

	// 0901
	if (*y1 < 0)
		*y1 = 0;

	// 0909
	if (*y1 > 199)
		*y1 = 199;

	// 0912
	if (*x2 < 0)
		*x2 = 0;

	// 091a
	if (*x2 > 319)
		*x2 = 319;

	// 0923
	if (*y2 < 0)
		*y2 = 0;

	// 092b
	if (*y2 > 199)
		*y2 = 199;

	// 0934
	return *x1; // void?
}

// register call
// clip line?
bool FUN_1000_0935_clip_line_coord(int* x1, int* y1, int* x2, int* y2)
{
	int si = 0;
	int di = 0;
	FUN_1000_0a22(*x1, *y1, *x2, *y2, &si, &di);

	if (si == 0 || di == 0)
		return 0; // CLC

	if (di != si)
		return -1; // STC

	// 0948
	D_52fa = *x1;
	D_52fc = *y1;
	D_52fe = *x2;
	D_5300 = *y2;

	if (si != 0)
	{
		SWAP(x1, x2);
		SWAP(y1, y2);
		FUN_1000_0991(x1, y1, x2, y2);
		D_52fa = *x1;
		D_52fc = *y1;
		*x2 = D_52fe;
		*y2 = D_5300;
	}

	// 0971
	if (di != 0)
	{
		FUN_1000_0991(x1, y1, x2, y2);
		D_52fe = *x1;
		D_5300 = *y1;
	}
	// 0980
	*x1 = D_52fa;
	*y1 = D_52fc;
	*x2 = D_52fe;
	*y2 = D_5300;
	return 0;
}

// register call
void FUN_1000_0991(int* ax, int* bx, int* cx, int* dx)
{
	int si;
	int di;
	while (1)
	{
		while (1)
		{
			si = *ax;
			di = *bx;

			*ax += *cx;
			*bx += *dx;
			if (*ax >= 0)
			{
				*ax >>= 1;
			}
			else
			{
				*ax /= 2;
			}

			if (*bx >= 0)
			{
				*bx >>= 1;
			}
			else
			{
				*bx /= 2;
			}

			D_52f6 = si - *ax;
			D_52f8 = di - *bx;

			FUN_1000_0a22(*ax, *bx, *cx, *dx, &si, &di);
			if (si == 0)
				break;
			*cx = *ax;
			*dx = *bx;
			*ax += D_52f6;
			*bx += D_52f8;
		}

		// 09e3
		if (*ax == D_52ba_vdp._52d0 || *ax == D_52ba_vdp._52d2)
		{
			// 09ef
			if (*bx == D_52ba_vdp._52d4 || *bx == D_52ba_vdp._52d6)
				return;
		}

		// 09fb
		si = D_52f6;
		di = D_52f8;
		if (si < 0)
			si = -si;

		// 0a0b
		if (di < 0)
			di = -di;

		// 0a13
		if (si < di)
			si = di;

		// 0a19
		if (si < 1)
			return;
	}
}

// register call
void FUN_1000_0a22(int ax, int bx, int cx, int dx, int *si, int *di)
{
	int x1 = ax;
	int y1 = bx;
	int x2 = cx;
	int y2 = dx;

	if (x1 < D_52ba_vdp._52d0)
		*si |= 1;

	if (x2 < D_52ba_vdp._52d0)
		*di |= 1;

	if (x1 > D_52ba_vdp._52d2)
		*si |= 2;

	if (x2 > D_52ba_vdp._52d2)
		*di |= 2;

	if (y1 > D_52ba_vdp._52d6)
		*si |= 4;

	if (y2 > D_52ba_vdp._52d6)
		*di |= 4;

	if (y1 < D_52ba_vdp._52d4)
		*si |= 8;

	if (y2 < D_52ba_vdp._52d4)
		*di |= 8;
}

// NOT MATCHING
void FUN_1000_0a70_set_pen_color(int param_1)
{
	if (param_1 != -1)
	{
		param_1 &= D_52ba_vdp._52c8_videoDriverSelection == 0 ? 3 : 0xf;
	}

	D_52da_pen_color = param_1;

	if (param_1 != -1)
	{
		DRV_2d(param_1);
	}
}

// fill rectangle
// NOT MATCHING
void FUN_1000_0aa6_fill_rectangle(int x1, int y1, int x2, int y2)
{
    FUN_1000_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);
	DRV_3f(x1, y1, x2, y2, 0);
}

// STUB
void FUN_1000_0ace(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int ax = param_3;
    int bx = param_4;
    int cx = param_5;
    int dx = param_6;
    int si = param_1;
    int di = param_2;

    printf("FUN_1000_0ace(%d,%d,%d,%d,%d,%d)\n", param_1, param_2, param_3, param_4, param_5, param_6);

	if (si != di && si <= 1 && di <= 1)
    {
        FUN_1000_08e6_constraint_imagewindow(&ax, &bx, &cx, &dx);

		// carry = si != 0;
		// DRV_18 (text_data_transfer)
        //DRV_18(ax, bx, cx, dx, si, di, carry);
    }
}

void FUN_1000_0b10_line(int x1, int y1, int x2, int y2)
{
	FUN_1000_0b2d_line(x1, y1, x2, y2);
}

// asm
void FUN_1000_0b2d_line(int ax, int bx, int cx, int dx)
{
	int x1 = ax;
	int y1 = bx;
	int x2 = cx;
	int y2 = dx;

	D_52ba_vdp._52cc_penX = x2;
	D_52ba_vdp._52ce_penY = y2;

	// pushf
	if (D_52ba_vdp._52c4 != 0)
	{
		if (FUN_1000_0935_clip_line_coord(&ax, &bx, &cx, &dx))
			return; // JC return
	}

	if (y1 == y2)
	{
		if (x1 == x2)
		{
			// 0b78
			// 0x30: pset
			DRV_30(x1, y1);
			return;
		}
		else
		{
			FUN_1000_08e6_constraint_imagewindow(&ax, &bx, &cx, &dx);
			DRV_39(ax, bx, cx);
		}
	}
	else
	{
		// 0b59
		if (x1 == x2)
		{
			FUN_1000_08e6_constraint_imagewindow(&ax, &bx, &cx, &dx);
			// 0x3c: v_line
			DRV_3c(ax, bx, dx);
			return;
		}
		else
		{
			// 0b6c
			// 0x33: line
			DRV_33(ax, bx, cx, dx);
			return;
		}
	}

	// 0b84
}

// NOT MATCHING
// some rectangle?
void FUN_1000_0b86(int x1, int y1, int x2, int y2)
{
	//printf("FUN_1000_0b86(%d,%d,%d,%d)\n", x1, y1, x2, y2);
    FUN_1000_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);
    DRV_3f(x1, y1, x2, y2, 1);
}

void* FUN_1000_0bae_load_compressed_file(char* file_name)
{
    printf("FUN_1000_0bae_load_compressed_file(%s)\n", file_name);
    return (void*)1; // TODO
}

void FUN_1000_0be4_free_memory(void* ptr) { puts("FUN_1000_0be4_free_memory"); }

// asm
void FUN_1000_0c22(int a)
{
	DRV_0f(a);
}

// NOT MATCHING (asm)
void FUN_1000_0c64_pset(int param_1, int param_2)
{
    D_52ba_vdp._52cc_penX = param_1;
    D_52ba_vdp._52ce_penY = param_2;

	if (D_52da_pen_color != -1)
    {
        if (D_52ba_vdp._52c4 != 0 && FUN_1000_08ca_inside_clip_window(param_1, param_2))
        {
            return;
        }

        DRV_30(param_1, param_2);
    }
}

bool FUN_1000_0ccd(int* pAX, int* pCX);

// NOT MATCHING (asm)
void FUN_1000_0c9c_grap_horiz_line(int x1, int y, int x2)
{
	int ax = x1;
	int bx = y;
	int cx = x2;

	D_52ba_vdp._52cc_penX = x2;

	if (D_52ba_vdp._52c4 != 0)
	{
		if (FUN_1000_0ccd(&ax, &cx))	// JC end
			return;
	}

	DRV_39(ax, bx, cx);
}

// NOT MATCHING (asm)
bool FUN_1000_0ccd(int *pAX, int *pCX)
{
	if (*pAX < *pCX)
	{
		SWAP(pAX, pCX);
	}

	if ((*pAX >= D_52ba_vdp._52d0) && (*pCX <= D_52ba_vdp._52d2) &&
		*pAX >= 0 && *pAX <= 319 && *pCX <= 319)
	{
		return FALSE; // CLC
	}

	return TRUE; // STC
}

int FUN_1000_0d2b(int bx, int dx);

// vline
// NOT MATCHING (asm)
void FUN_1000_0cf2(int param_1, int param_2, int param_3)
{
	int ax, bx, cx, dx;

    ax = param_1;
    bx = param_2;
    dx = param_3;
    cx = ax;
    D_52ba_vdp._52ce_penY = dx;
	if (bx > dx)
    {
		// xchg bx, dx
        bx ^= dx;
        dx ^= bx;
        bx ^= dx;
	}
    if (D_52ba_vdp._52c4 == 0 || !FUN_1000_0d2b(bx, dx))
    {
        // 0d19
        DRV_3c(ax, bx, dx);
	}
}

// NOT MATCHING (asm)
int FUN_1000_0d2b(int bx, int dx)
{
    if (D_52ba_vdp._52d4 <= bx && dx <= D_52ba_vdp._52d6 && 0 <= bx && bx < 200 && dx < 200)
    {
        return 0; // clc
    }

    return -1; // stc
}

void FUN_1000_0d4c(void* a, int b, int c, int d, int e) { printf("FUN_1000_0d4c(ptr,%d,%d,%d,%d)\n", b, c, d, e); }

int FUN_1000_0d72(int a) { printf("FUN_1000_0d72(%d)\n", a); }

void FUN_1000_0de0_detect_video(void)
{
    puts("FUN_1000_0de0_detect_video");
    D_52ba_vdp._52c8_videoDriverSelection = 1;
}

int FUN_1000_0e94_load_video_driver(void)
{
    puts("FUN_1000_0e94_load_video_driver");
    // DUMMY
    return 1;
}

int FUN_1000_0f2a_init_data_buffer(void)
{
    puts("FUN_1000_0f2a_init_data_buffer");
    // DUMMY
    return 1;
}

FUN_1000_0f46(int a, int b, int c, int d) { printf("FUN_1000_0f46(%d,%d,%d,%d)\n", a, b, c, d); }

FUN_1000_0f6e_image_data_transfer(int a, int b) { printf("FUN_1000_0f6e_image_data_transfer(%d,%d)\n", a, b); }

// NOT MATCHING (asm)
void FUN_1000_0f90_pen(int x, int y)
{
	FUN_1000_0b2d_line(D_52ba_vdp._52cc_penX, D_52ba_vdp._52ce_penY, x, y);
}

int FUN_1000_0fae_load_file(char* file_name)
{
    printf("FUN_1000_0FAE_load_file(%s)\n", file_name);
    return 1;
}

FUN_1000_0fdc_free_memory(int a) { printf("FUN_1000_0FDC_free_memory(%d)\n", a); }

#ifdef _WIN32
byte* g_tileset_mem;
#endif

// STUB
int FUN_1000_0ff4_load_compressed_tileset(char* file_name)
{
#ifdef _WIN32
	char buf[64];
	FILE* fp;
	strcpy(buf, file_name);
	char* z = strchr(buf, '.');
	strcpy(z + 1, "LZW");

	fp = fopen(buf, "rb");
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	byte* mem = malloc(size);
	fread(mem, size, 1, fp);

	fclose(fp);

	g_tileset_mem = mem;
#endif

	printf("FUN_1000_0ff4_load_compressed_tileset(%s)\n", file_name);
	return 1;
}
