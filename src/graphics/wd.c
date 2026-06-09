#include "common/common.h"
#include "key/key.h"
#include "time/time.h"

#include "grap_buf.h"
#include "wd.h"

#include <stdlib.h>
#include <string.h>

#define WD_FRAME_X 0x10
#define WD_FRAME_WIDTH 0x120
#define WD_FRAME_HEIGHT 0x31
#define WD_FRAME_SPACING 0x32
#define WD_FRAME_COUNT 4
#define WD_SCREEN_Y 0x41

// T1K:12ba
static int s_wdFrame = 0;

// T1K:12be
static void WdShowNextFrame(void)
{
    int srcY = s_wdFrame * WD_FRAME_SPACING;

    for (int row = 0; row < WD_FRAME_HEIGHT; row++)
    {
        memcpy(&g_linearEgaBuffer0[(WD_SCREEN_Y + row) * loresWidth], &g_linearEgaBuffer1[(srcY + row) * loresWidth], loresWidth);
    }

    s_wdFrame = (s_wdFrame + 1) & 3;
}

void GRAP_BUF_ShowNextWDFrame(void)
{
    WdShowNextFrame();
    GRAP_BUF_MarkDirty();
}

static u16 StepWdSeed(u16 seed)
{
    int carry = seed & 1;

    seed >>= 1;
    if (carry)
    {
        seed ^= 0x3500;
    }

    return seed;
}

static bool WdMaskMatches(BitImageView* mask, int x, int y, bool maskedPixels)
{
    if (x >= mask->width || y >= mask->height)
        return false;

    return ((mask->bits[y * mask->stride + x / 8] & (0x80 >> (x % 8))) != 0) == maskedPixels;
}

static void WdCopyFramePixelsFromBackup(byte* backup, int maskX, int maskY)
{
    int x = WD_FRAME_X + maskX;

    for (int frame = 0; frame < WD_FRAME_COUNT; frame++)
    {
        int y = frame * WD_FRAME_SPACING + maskY;
        g_linearEgaBuffer1[y * loresWidth + x] = backup[y * loresWidth + x];
    }
}

// T1K:139c
static bool AnimateWdPass(BitImageView* mask, byte* backup, bool maskedPixels)
{
    u16 seed;
    int frameCountdown;
    int generated;

    seed = 1;
    frameCountdown = 0x100;
    generated = 0;

    for (int i = 0; i < 0x8000; i++)
    {
        int relY = seed / WD_FRAME_WIDTH;
        int x = seed % WD_FRAME_WIDTH;

        if (relY < WD_FRAME_HEIGHT && WdMaskMatches(mask, x, relY, maskedPixels))
        {
            WdCopyFramePixelsFromBackup(backup, x, relY);

            if (generated % 64 == 63)
            {
                GRAP_BUF_Present();

                if (KEY_PollKey())
                    return true;

                if (maskedPixels)
                {
                    TIME_SleepMs(120);
                }
                else
                {
                    TIME_SleepMs(33);
                }
            }

            generated++;
        }

        frameCountdown--;
        if (frameCountdown == 0)
        {
            WdShowNextFrame();
            GRAP_BUF_Present();
            frameCountdown = 0x100;
        }

        seed = StepWdSeed(seed);
        if (seed == 1)
            break;
    }

    return false;
}

void GRAP_BUF_AnimateWD(BitImageView* mask)
{
    byte* backup;
    bool aborted;
    int pageSize;

    GRAP_BUF_FlushPendingPresent();

    pageSize = loresWidth * loresHeight;
    backup = malloc(pageSize); // TODO: temp
    if (backup == NULL)
        return;

    memcpy(backup, g_linearEgaBuffer1, pageSize);
    memset(g_linearEgaBuffer1, 0, pageSize);

    aborted = AnimateWdPass(mask, backup, false);
    if (!aborted)
    {
        aborted = AnimateWdPass(mask, backup, true);
    }

    if (aborted)
    {
        memcpy(g_linearEgaBuffer1, backup, pageSize);
        WdShowNextFrame();
        GRAP_BUF_Present();
        free(backup);
        return;
    }

    WdCopyFramePixelsFromBackup(backup, 0, 0);
    WdShowNextFrame();
    GRAP_BUF_Present();

    memcpy(g_linearEgaBuffer1, backup, pageSize);
    free(backup);
}
