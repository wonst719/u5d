#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include "GRAP_DRV.H"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LzwDecompressFile(FILE* fi, u8** out, u32* size);

void ULTIMA_0991(int* ax, int* bx, int* cx, int* dx);
void ULTIMA_0a22(int ax, int bx, int cx, int dx, int* si, int* di);

void SWAP(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void CDECL ULTIMA_02f4_exit(int a)
{
    debug("ULTIMA_02F4_exit(%d)", a);
    exit(a);
}

// _aNuldiv (32bit division)
u32 ULTIMA_03a0(int a, int b, int c, int d)
{
    debug("ULTIMA_03a0(%d,%d,%d,%d)", a, b, c, d);
}

// memchr
void* CDECL ULTIMA_0402_memchr(void* param_1, int param_2, int param_3)
{
	// original: assembly
	return memchr(param_1, param_2, param_3);
}

// itoa
char* CDECL ULTIMA_0426_itoa(int a, char* b, int c)
{
	// original: assembly
#if defined(COMPILER_MSVC)
    _itoa(a, b, c);
#else
    itoa(a, b, c);
#endif
    return b;
}

// stdcall
// _aNlmul (32bit multiply)
// _aNulmul == _aNlmul?
// A_hi, A_lo, B_hi, B_lo
s32 ULTIMA_0442(int A_hi, uint A_lo, int B_hi, uint B_lo)
{
    debug("ULTIMA_0442(%d,%d,%d,%d)", A_hi, A_lo, B_hi, B_lo);
}

// 0476
// _aNNalshl (32bit shl)
void ULTIMA_0476(u32* x, u8 y)
{
	debug("ULTIMA_0476(%d,%d)", x, y);
}

// 082a
// _aNlshl

void ULTIMA_0878_RestoreVideoMode(void)
{
    debug("ULTIMA_0878_RestoreVideoMode");

#if !defined(TARGET_DOS16)
	extern void GRAP_CleanupVideoDriver(void);

	GRAP_CleanupVideoDriver();
#endif
}

// STUB
void ULTIMA_0892_InitializeVideoDriver(int a)
{
    debug("ULTIMA_0892_InitializeVideoDriver(%d)", a);

#if !defined(TARGET_DOS16)
	extern void GRAP_InitializeVideoDriver(void);

	GRAP_InitializeVideoDriver();

	// TODO: temporary
    D_535e_textWindows[0].text_colors = 0xf;
    D_535e_textWindows[1].text_colors = 0xf;
    D_535e_textWindows[2].text_colors = 0xf;
    D_535e_textWindows[3].text_colors = 0xf;
#endif
}

// ASM
// AX, BX => CARRY
int ULTIMA_08ca_InsideClipWindow(int ax, int bx)
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

// ASM
int ULTIMA_08e6_ClipRectCoord(int *x1, int *y1, int *x2, int *y2)
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

// ASM
bool ULTIMA_0935_ClipLineCoord(int* x1, int* y1, int* x2, int* y2)
{
	int si = 0;
	int di = 0;
	ULTIMA_0a22(*x1, *y1, *x2, *y2, &si, &di);

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
		ULTIMA_0991(x1, y1, x2, y2);
		D_52fa = *x1;
		D_52fc = *y1;
		*x2 = D_52fe;
		*y2 = D_5300;
	}

	// 0971
	if (di != 0)
	{
		ULTIMA_0991(x1, y1, x2, y2);
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

// ASM
void ULTIMA_0991(int* ax, int* bx, int* cx, int* dx)
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

			ULTIMA_0a22(*ax, *bx, *cx, *dx, &si, &di);
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

// ASM
void ULTIMA_0a22(int ax, int bx, int cx, int dx, int *si, int *di)
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
void ULTIMA_0a70_GRAP_2d_SetPenColor(int param_1)
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

// ASM
void ULTIMA_0aa6_GRAP_3f_FillRect(int x1, int y1, int x2, int y2)
{
    ASSERT(x1 < x2);
    ASSERT(y1 < y2);
    ULTIMA_08e6_ClipRectCoord(&x1, &y1, &x2, &y2);
    ASSERT(x1 < x2);
    ASSERT(y1 < y2);
	DRV_3f(x1, y1, x2, y2, 0);
}

// ASM
// src_page, dst_page, x1, y1, x2, y2
void ULTIMA_0ace_GRAP_18_TransferArea(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int ax = param_3; // x1
    int bx = param_4; // y1
    int cx = param_5; // x2
    int dx = param_6; // y2
    int si = param_1;
    int di = param_2;

	int carry;

    //debug("ULTIMA_0ace(%d,%d,%d,%d,%d,%d)", param_1, param_2, param_3, param_4, param_5, param_6);

	if (si != di && si <= 1 && di <= 1)
    {
        ASSERT(ax <= cx);
        ASSERT(bx <= dx);
        ULTIMA_08e6_ClipRectCoord(&ax, &bx, &cx, &dx);
        ASSERT(ax <= cx);
        ASSERT(bx <= dx);

		carry = si != 0;
		// DRV_18 (transfer_area)
        DRV_18(ax, bx, cx, dx, si, di, carry);
    }
}

// ASM
void ULTIMA_0b10_GRAP_Line(int x1, int y1, int x2, int y2)
{
	ULTIMA_0b2d_GRAP_Line(x1, y1, x2, y2, 0);
}

// ASM
void ULTIMA_0b2d_GRAP_Line(int ax, int bx, int cx, int dx, byte carry)
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
		if (ULTIMA_0935_ClipLineCoord(&ax, &bx, &cx, &dx))
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
			ULTIMA_08e6_ClipRectCoord(&ax, &bx, &cx, &dx);
			DRV_39(ax, bx, cx);
		}
	}
	else
	{
		// 0b59
		if (x1 == x2)
		{
			ULTIMA_08e6_ClipRectCoord(&ax, &bx, &cx, &dx);
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

// ASM
void ULTIMA_0b86_GRAP_XorFillRect(int x1, int y1, int x2, int y2)
{
    ULTIMA_08e6_ClipRectCoord(&x1, &y1, &x2, &y2);
    DRV_3f(x1, y1, x2, y2, 1);
}

void* ULTIMA_125d_ReadFileImpl(char* file_name);

// ASM, STUB
void* ULTIMA_0bae_LoadImageFile(char* file_name)
{
    debug("ULTIMA_0bae_LoadImageFile(%s)", file_name);

	return ULTIMA_125d_ReadFileImpl(file_name);

	// if (error)
    //     if (ret == 0) ax = -1;
    //     D_535c_dosErrorCode = ax
	//     far D_5394_fn(); // disk swap message
	// else
	//     DRV_42(); // prepare image data for ega (swizzle)
}

// ASM, STUB
void ULTIMA_0be4_FreeImage(void* ptr)
{
    debug("ULTIMA_0be4_FreeImage");
	// int 21,49h
    //free(ptr);
}

// ASM
// put image (forced hflip)
void ULTIMA_0bfc_GRAP_63(byte* param_1, int param_2, int param_3, int param_4, int param_5)
{
    debug("ULTIMA_0bfc_GRAP_63(ptr,%d,%d,%d,%d)", param_2, param_3, param_4, param_5);

    DRV_63(param_1, param_2, param_3, param_4, param_5);
}

// ASM
void ULTIMA_0c22_GRAP_0f_SelectPage(int a)
{
	DRV_0f(a);
}

// ASM
// set clip window coord
void ULTIMA_0c3c(int a, int b, int c, int d)
{
    D_52ba_vdp._52d0 = a;
    D_52ba_vdp._52d4 = b;
    D_52ba_vdp._52d2 = c;
    D_52ba_vdp._52d6 = d;
}

// NOT MATCHING (asm)
void ULTIMA_0c64_GRAP_30_Pset(int param_1, int param_2)
{
    D_52ba_vdp._52cc_penX = param_1;
    D_52ba_vdp._52ce_penY = param_2;

	if (D_52da_pen_color != -1)
    {
        if (D_52ba_vdp._52c4 != 0 && ULTIMA_08ca_InsideClipWindow(param_1, param_2))
        {
            return;
        }

        DRV_30(param_1, param_2);
    }
}

bool ULTIMA_0ccd(int* pAX, int* pCX);

// NOT MATCHING (asm)
void ULTIMA_0c9c_GRAP_39_HorizLine(int x1, int y, int x2)
{
	int ax = x1;
	int bx = y;
	int cx = x2;

	D_52ba_vdp._52cc_penX = x2;

	if (D_52ba_vdp._52c4 != 0)
	{
		if (ULTIMA_0ccd(&ax, &cx))	// JC end
			return;
	}

	DRV_39(ax, bx, cx);
}

// NOT MATCHING (asm)
bool ULTIMA_0ccd(int *pAX, int *pCX)
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

int ULTIMA_0d2b(int bx, int dx);

// NOT MATCHING (asm)
// vline
void ULTIMA_0cf2_GRAP_3c_VertLine(int param_1, int param_2, int param_3)
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
    if (D_52ba_vdp._52c4 == 0 || !ULTIMA_0d2b(bx, dx))
    {
        // 0d19
        DRV_3c(ax, bx, dx);
	}
}

// NOT MATCHING (asm)
int ULTIMA_0d2b(int bx, int dx)
{
    if (D_52ba_vdp._52d4 <= bx && dx <= D_52ba_vdp._52d6 && 0 <= bx && bx < 200 && dx < 200)
    {
        return 0; // clc
    }

    return -1; // stc
}

// put_image(rsrc, imageIdx, x, y, vflip?)
void ULTIMA_0d4c_GRAP_4b_PutImage(void* rsrc, int idx, int x, int y, int flags)
{
    debug("ULTIMA_0d4c_GRAP_4b_PutImage(rsrc:ptr,idx:%d,x:%d,y:%d,flags:%d)", idx, x, y, flags);
	
	DRV_4b(rsrc, idx, x, y, flags);
}

// NOT MATCHING
int ULTIMA_0d72_AnimateOriginLogo(byte* image)
{
    int iVar1;
    int iStack_4;

    iStack_4 = 0;
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 319, 199);

    for (iVar1 = 0; iVar1 < 7; iVar1++)
    {
        ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(image, iVar1, (320 - D_5306[iVar1]) >> 1, iStack_4);
        iStack_4 += D_5314[iVar1];
    }

    ULTIMA_0c22_GRAP_0f_SelectPage(0);

#if !defined(TARGET_DOS16)
	// TODO: temporary
    ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(image, 6, (320 - D_5306[6]) >> 1, 46);
#endif

    return ULTIMA_1140_GRAP_6f();
}

// STUB
void ULTIMA_0de0_DetectVideo(void)
{
    debug("ULTIMA_0de0_DetectVideo");
    D_52ba_vdp._52c8_videoDriverSelection = 1;
}

// STUB
int ULTIMA_0e94_LoadVideoDriver(void)
{
    debug("ULTIMA_0e94_LoadVideoDriver");
    // DUMMY
    return 1;
}

// STUB
int ULTIMA_0f2a_GRAP_06_AllocPageBuffer(void)
{
    debug("ULTIMA_0f2a_GRAP_06_AllocPageBuffer");
    // DUMMY
    return 1;
}

// NOT MATCHING (asm)
void ULTIMA_0f46_GRAP_66_Reveal(int x1, int y1, int x2, int y2)
{
    debug("ULTIMA_0f46_GRAP_66_Reveal(%d,%d,%d,%d)", x1, y1, x2, y2);
    ULTIMA_08e6_ClipRectCoord(&x1, &y1, &x2, &y2);
	DRV_66(x1, y1, x2, y2, 0, 0, 0);
}

// NOT MATCHING (asm)
void ULTIMA_0f6e_GRAP_1b_TransferFullscreen(int from, int to)
{
    debug("ULTIMA_0f6e_GRAP_1b_TransferFullscreen(%d,%d)", from, to);
    if (from != to)
    {
        DRV_1b(from, to);
    }
}

// NOT MATCHING (asm)
void ULTIMA_0f90_GRAP_Pen(int x, int y)
{
	ULTIMA_0b2d_GRAP_Line(D_52ba_vdp._52cc_penX, D_52ba_vdp._52ce_penY, x, y, 0);
}

void* ULTIMA_125d_ReadFileImpl(char* file_name);

// STUB
byte* ULTIMA_0fae_LoadFile(char* file_name)
{
    debug("ULTIMA_0fae_LoadFile(%s)", file_name);

	return ULTIMA_125d_ReadFileImpl(file_name);
	// if error
	//     if ret == 0
	//         ret = -1
	//     else
	//         535c_dosErrorCode = ret
	//         5394_diskSwapMessage();
}

// NOTE: same as 0be4
void ULTIMA_0fdc_FreeBitImage(void* ptr)
{
    debug("ULTIMA_0fdc_FreeBitImage(ptr)");
	// int 21,49
    //free(ptr);
}

// STUB
byte* g_tileset_mem;

// ASM
int ULTIMA_0ff4_LoadTileset(char* file_name)
{
    debug("ULTIMA_0ff4_LoadTileset(%s)", file_name);
    g_tileset_mem = (byte*)ULTIMA_125d_ReadFileImpl(file_name);

	return 1;
}
