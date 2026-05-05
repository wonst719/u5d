#include "COMMON.H"

#include "VARS.H"

#include "GRAP_BUF.H"

#include <stdlib.h>
#include <string.h>

#include <dpmi.h>
//#include <go32.h>
#include "GRAP_OPS.H"

#include <dos.h>

#include <sys/nearptr.h>
//#include <sys/movedata.h>

u32 s_egaPalette[16] = {
    0xff000000, 0xff0000aa, 0xff00aa00, 0xff00aaaa, 0xffaa0000, 0xffaa00aa, 0xffaa5500, 0xffaaaaaa,

    0xff555555, 0xff5555ff, 0xff55ff55, 0xff55ffff, 0xffff5555, 0xffff55ff, 0xffffff55, 0xffffffff,
};

extern VideoDriverParams D_52ba_vdp;

void GRAP_VGA_SetMode(byte mode)
{
    __dpmi_regs r;
    r.h.ah = 0x00;
    r.h.al = mode;
    __dpmi_int(0x10, &r);
}

void GRAP_VGA_WaitVsync()
{
    while (inportb(0x3DA) & 8)
        ;
    while (!(inportb(0x3DA) & 8))
        ;
}

void GRAP_VGA_SetPaletteEntry(byte color, byte r, byte g, byte b)
{
    outportb(0x3C8, color);
    outportb(0x3C9, r);
    outportb(0x3C9, g);
    outportb(0x3C9, b);
}

void GRAP_VGA_Present(void);

void GRAP_VGA_InitializeVideoDriver(void)
{
    GRAP_VGA_SetMode(0x13);

    GRAP_BUF_InitializeDriver(GRAP_VGA_Present);

    debug("Initialized video driver");
}

void GRAP_VGA_CleanupVideoDriver(void)
{
    GRAP_VGA_SetMode(0x3);
}

void GRAP_VGA_Present(void)
{
    //DisplayDebugMessages();

    byte* frameBuffer;
    if (__djgpp_nearptr_enable() == 0)
        return;

    frameBuffer = (byte*)(0xa0000 + __djgpp_conventional_base);

    memcpy(frameBuffer, g_linearEgaBuffer0, 320 * 200);

    __djgpp_nearptr_disable();
}

static GraphicsDriverOps s_vgaOps =
{
    .InitializeVideoDriver = GRAP_VGA_InitializeVideoDriver,
    .CleanupVideoDriver = GRAP_VGA_CleanupVideoDriver,
    .SetPenColor = GRAP_BUF_SetPenColor,
    .SetPage = GRAP_BUF_SetPage,
    .PrintChar = GRAP_BUF_PrintChar,
    .ScrollWindow = GRAP_BUF_ScrollWindow,
    .Line = GRAP_BUF_Line,
    .Pset = GRAP_BUF_Pset,
    .FillWindow = GRAP_BUF_FillWindow,
    .Temp_PutTile = GRAP_BUF_Temp_PutTile,
    .PutBitmap = GRAP_BUF_PutBitmap,
    .PutBitmap_Flip = GRAP_BUF_PutBitmap_Flip,
    .PutBitImage = GRAP_BUF_PutBitImage,
    .TransferPage = GRAP_BUF_TransferPage,
    .TransferPage_Reveal = GRAP_BUF_TransferPage_Reveal
};

GraphicsDriverOps* GRAP_VGA_GetOps(void)
{
    return &s_vgaOps;
}
