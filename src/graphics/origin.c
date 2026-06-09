#include "common/common.h"
#include "key/key.h"
#include "time/time.h"

#include "grap_buf.h"
#include "origin.h"

#include <string.h>

// 112c
static const byte s_originLogoAnimationTable[] =
{
    0x07,
    // 0
    0x00, 0x4b, 0x03, 0x0b, 0xff, 0xff, 0xff, 0x01,
    0xff, 0xff, 0xff, 0xff, 0x00, 0x02, 0xff,
    // 1
    0x03, 0x48, 0x07, 0x0f, 0xff, 0xff, 0x01, 0x05,
    0xff, 0xff, 0x02, 0x04, 0xff, 0xff, 0x03, 0xff,
    0x00, 0x06, 0xff,
    // 2
    0x0a, 0x47, 0x0b, 0x13, 0xff, 0xff, 0x02, 0x08,
    0xff, 0x03, 0x07, 0xff, 0x01, 0x09, 0xff, 0x04,
    0x06, 0xff, 0x05, 0xff, 0x00, 0x0a, 0xff,
    // 3
    0x15, 0x42, 0x14, 0x1c, 0xff, 0x04, 0x0f, 0xff,
    0x01, 0x07, 0x0c, 0x12, 0xff, 0x05, 0x0e, 0xff,
    0x02, 0x08, 0x0b, 0x11, 0xff, 0x03, 0x06, 0x0d,
    0x10, 0xff, 0x09, 0x0a, 0xff, 0x00, 0x13, 0xff,
    // 4
    0x29, 0x3c, 0x20, 0x28, 0xff, 0x07, 0x18, 0xff,
    0x02, 0x0c, 0x13, 0x1d, 0xff, 0x03, 0x08, 0x0d,
    0x12, 0x17, 0x1c, 0xff, 0x01, 0x06, 0x0b, 0x14,
    0x19, 0x1e, 0xff, 0x04, 0x09, 0x0e, 0x11, 0x16,
    0x1b, 0xff, 0x05, 0x0a, 0x0f, 0x10, 0x15, 0x1a,
    0xff, 0x00, 0x1f, 0xff,
    // 5
    0x49, 0x35, 0x2d, 0x35, 0xff, 0x04, 0x0b, 0x12,
    0x1a, 0x21, 0x28, 0xff, 0x01, 0x08, 0x0f, 0x13,
    0x24, 0x2b, 0xff, 0x06, 0x0d, 0x14, 0x18, 0x1f,
    0x26, 0xff, 0x03, 0x0a, 0x11, 0x16, 0x1b, 0x22,
    0x29, 0xff, 0x02, 0x05, 0x09, 0x0c, 0x10, 0x13,
    0x19, 0x1c, 0x20, 0x23, 0x27, 0x2a, 0xff, 0x07,
    0x0e, 0x15, 0x17, 0x1e, 0x25, 0xff, 0x00, 0x2c,
    0xff,
    // 6
    0x76, 0x2e, 0x3d, 0x45, 0xff, 0x1c, 0x17, 0x12,
    0x0d, 0x08, 0x03, 0x20, 0x25, 0x2a, 0x2f, 0x34,
    0x39, 0xff, 0x1a, 0x15, 0x10, 0x0b, 0x06, 0x01,
    0x22, 0x27, 0x2c, 0x31, 0x36, 0x3b, 0xff, 0x1d,
    0x18, 0x13, 0x0e, 0x09, 0x04, 0x1f, 0x24, 0x29,
    0x2e, 0x33, 0x38, 0xff, 0x1b, 0x16, 0x11, 0x0c,
    0x07, 0x02, 0x21, 0x26, 0x2b, 0x30, 0x35, 0x3a,
    0xff, 0x19, 0x0f, 0x05, 0x23, 0x2d, 0x37, 0xff,
    0x1e, 0x28, 0x32, 0x14, 0x0a, 0xff, 0x00, 0x3c,
    0xff
};

static int s_originLogoListStart; // 0e53 (ptr)
static int s_originLogoTableCursor; // 0e55 (ptr)
static int s_originLogoListLenMinusOne; // 0e03
static int s_originLogoTargetBaseY; // 0e0b
static int s_originLogoSourceBaseY; // 0e0d
static int s_originLogoLineCount; // 0e0f
static byte s_originLogoLineVisible[128]; // 0e13

void GRAP_FlushPrevPresentReq(void);

// 0ebe
static void OriginLogoClearLine(int y)
{
    if (y < loresHeight)
    {
        memset(&g_linearEgaBuffer0[y * loresWidth], 0, loresWidth);
    }
}

// 0ed7
static void OriginLogoCopyColoredLineFromBackBuffer(int srcY, int dstY)
{
    if (srcY < loresHeight && dstY < loresHeight)
    {
        byte* src = &g_linearEgaBuffer1[srcY * loresWidth];
        byte* dst = &g_linearEgaBuffer0[dstY * loresWidth];

        for (int x = 0; x < loresWidth; x++)
        {
            dst[x] = src[x] & 9; // blue
        }
    }
}

static byte OriginLogoReadByte(void)
{
    if (s_originLogoTableCursor >= ARRAYSIZE(s_originLogoAnimationTable))
        return 0;

    return s_originLogoAnimationTable[s_originLogoTableCursor++];
}

// 106f
static void OriginLogoReadHeader(void)
{
    s_originLogoSourceBaseY = OriginLogoReadByte();
    s_originLogoTargetBaseY = OriginLogoReadByte();
    s_originLogoLineCount = OriginLogoReadByte();
}

// 1085
static void OriginLogoReadList(void)
{
    byte listLen = OriginLogoReadByte();

    s_originLogoListLenMinusOne = listLen - 1;
    s_originLogoListStart = s_originLogoTableCursor;
    s_originLogoTableCursor += listLen;
}

// 10a8
static void OriginLogoPreparePass(void)
{
    OriginLogoReadHeader();
    OriginLogoReadList();
}

static byte OriginLogoListAt(int index)
{
    if (index < 0 || s_originLogoListStart + index >= ARRAYSIZE(s_originLogoAnimationTable))
        return 0xff;

    return s_originLogoAnimationTable[s_originLogoListStart + index];
}

// 0e7f
static void OriginLogoCountLineStates(int* hiddenCount, int* visibleCount)
{
    *hiddenCount = 0;
    *visibleCount = 0;

    for (int i = 0; i < s_originLogoLineCount; i++)
    {
        if (s_originLogoLineVisible[i] == 0)
        {
            (*hiddenCount)++;
        }
        else
        {
            (*visibleCount)++;
        }
    }
}

// 0f12
static int OriginLogoInitialY(int direction)
{
    if (direction == 0)
        return s_originLogoTargetBaseY;

    return s_originLogoTargetBaseY + s_originLogoLineCount;
}

// 0f2e
static u16 OriginLogoAdvanceY(int direction, u16 y)
{
    if (direction == 0)
        return y + 1;

    return y - 1;
}

// 0f62
static bool OriginLogoRenderStateStep(int direction)
{
    int hiddenCount; // 0e57
    int visibleCount;
    int y;
    int scan;

    y = OriginLogoInitialY(direction);
    scan = 0;

    OriginLogoCountLineStates(&hiddenCount, &visibleCount);

    for (int i = 0; i < hiddenCount / 2; i++)
    {
        OriginLogoClearLine(y);
        y = OriginLogoAdvanceY(direction, y);
    }

    for (int i = 0; i < visibleCount; i++)
    {
        // 0eab
        while (scan < s_originLogoLineCount && s_originLogoLineVisible[scan] == 0)
        {
            scan++;
        }

        if (scan >= s_originLogoLineCount)
            break;

        OriginLogoCopyColoredLineFromBackBuffer(s_originLogoSourceBaseY + scan, y);
        scan++;
        y = OriginLogoAdvanceY(direction, y);
    }

    hiddenCount++;

    for (int i = 0; i < hiddenCount / 2; i++)
    {
        OriginLogoClearLine(y);
        y = OriginLogoAdvanceY(direction, y);
    }

    GRAP_BUF_Present();

    if (KEY_PollKey())
    {
        return true;
    }

    TIME_SleepMs(2 * (s_originLogoLineCount / 3 + 15));

    return false;
}

// 0fe2
static bool OriginLogoApplyReverseSet(int direction)
{
    int pos; // 0e05
    int count; // 0e07

    memset(s_originLogoLineVisible, 0, s_originLogoLineCount);

    pos = s_originLogoListLenMinusOne - 1;
    count = 6;

    while (count >= 0)
    {
        byte value = OriginLogoListAt(pos--);

        if (value == 0xff)
        {
            bool aborted = OriginLogoRenderStateStep(direction);
            count--;

            if (aborted)
                return true;
        }
        else if (value < s_originLogoLineCount)
        {
            s_originLogoLineVisible[value] = 1;
        }
    }

    return false;
}

// 1023
static bool OriginLogoApplyForwardClear(int direction)
{
    int pos;
    int count;

    pos = 1;
    count = 6;

    while (count > 0)
    {
        byte value = OriginLogoListAt(pos++);

        if (value == 0xff)
        {
            bool aborted = OriginLogoRenderStateStep(direction);
            count--;

            if (aborted)
                return true;
        }
        else if (value < s_originLogoLineCount)
        {
            s_originLogoLineVisible[value] = 0;
        }
    }

    return false;
}

// 1107
static void OriginLogoCleanupAfterAbort(void)
{
    s_originLogoTableCursor = 0xbf;
    OriginLogoReadHeader();

    memset(s_originLogoLineVisible, 1, s_originLogoLineCount);
    OriginLogoRenderStateStep(0);
}

// 10b7
int GRAP_BUF_AnimateOriginLogo(int timerCalibration)
{
    int passCount;
    int direction;
    bool abort;

    GRAP_FlushPrevPresentReq();

    s_originLogoListStart = 0;
    s_originLogoListLenMinusOne = 0;
    s_originLogoSourceBaseY = 0;
    s_originLogoTargetBaseY = 0;
    s_originLogoLineCount = 0;
    memset(s_originLogoLineVisible, 0, sizeof(s_originLogoLineVisible));

    s_originLogoTableCursor = 0;
    abort = false;
    passCount = OriginLogoReadByte();
    direction = 1;

    while (passCount != 0)
    {
        OriginLogoPreparePass();
        direction ^= 1;

        if (OriginLogoApplyReverseSet(direction))
        {
            OriginLogoCleanupAfterAbort();
            abort = true;
            break;
        }

        passCount--;
        if (passCount == 0)
            break;

        if (OriginLogoApplyForwardClear(direction))
        {
            OriginLogoCleanupAfterAbort();
            abort = true;
            break;
        }
    }

    return abort ? 1 : 0;
}
