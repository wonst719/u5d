#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

u16 D_52c4;
u16 D_52cc;
u16 D_52ce;

undefined2 far DRV_FarCall(int offset);

void FUN_1000_0a22(int ax, int bx, int cx, int dx, int* si, int* di);

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
// clip line?
bool FUN_1000_0935(int *x1, int *y1, int *x2, int *y2)
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

// fill rectangle
void FUN_1000_0aa6_fill_rectangle(int x1, int y1, int x2, int y2)
{
	printf("FUN_1000_0aa6_fill_rectangle(%d,%d,%d,%d)\n", x1, y1, x2, y2);
#ifdef _WIN32
	extern void GRAP_WIN_FillWindow(int x1, int y1, int x2, int y2);
	GRAP_WIN_FillWindow(x1, y1, x2, y2);
#else
	// AX = x1;
	// BX = y1;
	// CX = x2;
	// DX = y2;
	//DRV_FarCall(0x3f);
#endif
}

void FUN_1000_0b10_line(int x1, int y1, int x2, int y2)
{
	printf("FUN_1000_0b10_line(%d,%d,%d,%d)\n", x1, y1, x2, y2);
#ifdef _WIN32
	D_52ba_vdp._52cc_penX = x2;
	D_52ba_vdp._52ce_penY = y2;

	extern void GRAP_WIN_Line(int x1, int y1, int x2, int y2);
	GRAP_WIN_Line(x1, y1, x2, y2);
#else
	FUN_1000_0b2d_line(x1, y1, x2, y2);
#endif
}

void FUN_1000_0b2d_line(int ax, int bx, int cx, int dx)
{
	// 
	int x1 = ax;
	int y1 = bx;
	int x2 = cx;
	int y2 = dx;

	D_52ba_vdp._52cc_penX = x2;
	D_52ba_vdp._52ce_penY = y2;

	// pushf
	if (D_52ba_vdp._52c4 != 0)
	{
		if (FUN_1000_0935(&ax, &bx, &cx, &dx))
			return; // JC return
	}

	if (y1 == y2)
	{
		if (x1 == x2)
		{
			// 0b78
			// 0x30: pset
			DRV_FarCall(0x30);
			return;
		}
		else
		{
			// constraint_imagewindow
			// 0x39: h_line
			DRV_FarCall(0x39);
		}
	}
	else
	{
		// 0b59
		if (x1 == x2)
		{
			// constraint_imagewindow
			// 0x3c: v_line
			DRV_FarCall(0x3c);
			return;
		}
		else
		{
			// 0b6c
			// 0x33: line
			DRV_FarCall(0x33);
			return;
		}
	}

	// 0b84
}

void FUN_1000_0f90_pen(int x, int y)
{
	printf("FUN_1000_0f90_pen(%d,%d)\n", x, y);

#ifdef _WIN32
	extern void GRAP_WIN_Line(int x1, int y1, int x2, int y2);
	GRAP_WIN_Line(D_52ba_vdp._52cc_penX, D_52ba_vdp._52ce_penY, x, y);

	D_52ba_vdp._52cc_penX = x;
	D_52ba_vdp._52ce_penY = y;
#else
	FUN_1000_0b2d_line(D_52ba_vdp._52cc_penX, D_52ba_vdp._52ce_penY, x, y);
#endif
}
