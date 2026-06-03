#include "common/common.h"
#include "vars.h"
#include "macros.h"

#include "time/pctimer.h"

#include <stdlib.h>
#include <conio.h>

#include <sys/movedata.h>
#include <bios.h>

void KEY_Initialize(void)
{}

void KEY_Cleanup(void)
{}

#define KEY_UP 0x48
#define KEY_LEFT 0x4b
#define KEY_RIGHT 0x4d
#define KEY_DOWN 0x50

#define KEYSCAN_SPACE 0x3920

extern void EVT_Yield(void);

const u32 biosKeySeg = 0x0040;
// 0040:001A
const u32 biosKeyHeadPtrOffset = 0x001a;
// 0040:001C
const u32 biosKeyTailPtrOffset = 0x001c;

const u32 biosKeyFirstDataOffset = 0x001e;

static u16 GetLastKeyInBiosBuffer()
{
    u16 headPtr;
    u16 tailPtr;
    u16 scancode = 0;

    _dosmemgetw(biosKeySeg * 16 + biosKeyHeadPtrOffset, 2, &headPtr);
    _dosmemgetw(biosKeySeg * 16 + biosKeyTailPtrOffset, 2, &tailPtr);

    if (headPtr != tailPtr)
    {
        // 0040:[TailPtr - 2]
        _dosmemgetw(biosKeySeg * 16 + tailPtr - 2, 2, &scancode);
    }

    return scancode;
}

static void FlushBiosKeyBuffer()
{
    u16 headPtr = biosKeyFirstDataOffset;
    u16 tailPtr = biosKeyFirstDataOffset;

    _dosmemputw(&headPtr, 2, biosKeySeg * 16 + biosKeyHeadPtrOffset);
    _dosmemputw(&tailPtr, 2, biosKeySeg * 16 + biosKeyTailPtrOffset);
}

int KEY_PollKey()
{
    D_538a = 0;

    EVT_Yield();

    // TODO
    if (kbhit() != 0)
    {
        int chr = getch();
        if (chr == 0)
        {
            chr = getch() | 0x80;
        }

        if (chr == 0)
        {
            return 0;
        }
        else if ((chr & 0x7f) == KEY_LEFT)
        {
            FlushBiosKeyBuffer();
            D_538a = 1;
            return U5_KEY_LEFT;
        }
        else if ((chr & 0x7f) == KEY_UP)
        {
            FlushBiosKeyBuffer();
            D_538a = 1;
            return U5_KEY_UP;
        }
        else if ((chr & 0x7f) == KEY_RIGHT)
        {
            FlushBiosKeyBuffer();
            D_538a = 1;
            return U5_KEY_RIGHT;
        }
        else if ((chr & 0x7f) == KEY_DOWN)
        {
            FlushBiosKeyBuffer();
            D_538a = 1;
            return U5_KEY_DOWN;
        }

        //FlushBiosKeyBuffer();

        // Ctrl+E: 0x5?
        // Ctrl+S: 0x13?
        // Ctrl+V: 0x16?
        // ?: 0xb?

        return chr;
    }

    return 0;
}

// for reference
#if 0
// int 16,1
bool HasKey(void)
{
    //
}

// int 21,6 dl=ff (console input)
u8 GetKey(void)
{
    //
}

// int 16,2 read keyboard flags
u8 GetKeyboardFlags(void) { return 0; }

void ClearKeyboardBuffer(void) {}

int ULTIMA_1d5e_PeekKey(void)
{
    byte flags;
    uint ret = 0;
    int iVar4;

    // 1d64
    D_538a = 0;
    bool hasKey = HasKey();
    if (!hasKey)
    {
        // 1d70
        return 0;
    }

    // 1d86
    u8 key = GetKey();
    if (key == 0) // zf
    {
        // extended keystroke
        // 1d92
        key = GetKey(); // scancode
        if (key == 0) // zf
        {
            return 0;
        }

        // 1d98
        if (key < 0x3b)
        {
            return 0;
        }

        // 1da0
        if (key <= 0x44)
        {
            // F1..F10 -> c9..d2
            ret = key + 0x8e;
        }
        else // 0x45~
        {
            // Arrow keys
            // l, r, d, u, home, end, pgup, pgdn -> 1, 2, 3, 4, d3, d4, d5, d6

            // 1da8
            for (iVar4 = 0; iVar4 < 8; iVar4++)
            {
                if (key == D_540e[iVar4])
                    break;
            }

            if (iVar4 == 8) // 1db6
            {
                return 0;
            }

            // 1db8
            ret = D_5416[iVar4];
            D_538a = 1;
        }
    }
    else if (key >= 0x31 && key <= 0x39) // 1dc2 '1'~'9'
    {
        // Flags
        flags = GetKeyboardFlags();
        if ((flags & 0x23) != 0) // lshift | rshift | numlock
        {
            D_538a = 1;
        }
    }

    // 1d77
    if (D_538c != 0)
    {
        //ULTIMA_1b24_ClearKeyboardBufferImpl();
        ClearKeyboardBuffer();
    }

    return ret;
}
#endif
