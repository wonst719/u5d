#include "common/common.h"

#include "vars.h"

#include "grap_buf.h"
#include "origin.h"
#include "wd.h"

#include <stdlib.h>
#include <string.h>

#include <dpmi.h>
//#include <go32.h>
#include "grap_ops.h"

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

void GRAP_VGA_Initialize(void)
{
    GRAP_VGA_SetMode(0x13);

    GRAP_BUF_Initialize(GRAP_VGA_Present);

    debug("Initialized video driver");
}

void GRAP_VGA_Cleanup(void)
{
    GRAP_BUF_Cleanup();

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
    .Initialize = GRAP_VGA_Initialize,
    .Cleanup = GRAP_VGA_Cleanup,
    .Present = GRAP_VGA_Present,
    .SetPenColor = GRAP_BUF_SetPenColor,
    .SetPage = GRAP_BUF_SetPage,
    .PrintChar = GRAP_BUF_PrintChar,
    .ScrollWindow = GRAP_BUF_ScrollWindow,
    .Line = GRAP_BUF_Line,
    .Pset = GRAP_BUF_Pset,
    .FillWindow = GRAP_BUF_FillWindow,
    .LoadTileset = GRAP_BUF_LoadTileset,
    .UnloadTileset = GRAP_BUF_UnloadTileset,
    .AnimateTileset = GRAP_BUF_AnimateTileset,
    .UpdateTimeTileset = GRAP_BUF_UpdateTimeTileset,
    .ShowNextWDFrame = GRAP_BUF_ShowNextWDFrame,
    .AnimateWD = GRAP_BUF_AnimateWD,
    .AnimateOriginLogo = GRAP_BUF_AnimateOriginLogo,
    .PutAnimatedMoongateTile = GRAP_BUF_PutAnimatedMoongateTile,
    .PutTileRevealStep = GRAP_BUF_PutTileRevealStep,
    .PutTile = GRAP_BUF_PutTile,
    .PutImage = GRAP_BUF_PutImage,
    .PutBitImage = GRAP_BUF_PutBitImage,
    .TransferPage = GRAP_BUF_TransferPage,
    .TransferPage_Reveal = GRAP_BUF_TransferPage_Reveal
};

GraphicsDriverOps* GRAP_VGA_GetOps(void)
{
    return &s_vgaOps;
}
