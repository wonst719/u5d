#include "common/common.h"
#include "vars.h"

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

int KEY_PollKey()
{
    D_538a = 0;

    EVT_Yield();

    // TODO
    // if (bioskey(1)) // int 16,1
    if (kbhit())
    {
        //int chr = bioskey(0); // int 16,0
        int chr = getch();
        if (chr == 0)
        {
            chr = getch() | 0x80;
        }

        //debug("u5_peekch %d", chr);

        if (chr == 0)
        {
            return 0;
        }
        else if ((chr & 0x7f) == KEY_LEFT)
        {
            D_538a = 1;
            return 1;
        }
        else if ((chr & 0x7f) == KEY_UP)
        {
            D_538a = 1;
            return 3;
        }
        else if ((chr & 0x7f) == KEY_RIGHT)
        {
            D_538a = 1;
            return 2;
        }
        else if ((chr & 0x7f) == KEY_DOWN)
        {
            D_538a = 1;
            return 4;
        }

        // Ctrl+E: 0x5?
        // Ctrl+S: 0x13?
        // Ctrl+V: 0x16?
        // ?: 0xb?

        return chr;
    }

    return 0;
}

const u32 biosKeySeg = 0x0040;
// 0040:001A
const u32 biosKeyHeadPtrOffset = 0x001a;
// 0040:001C
const u32 biosKeyTailPtrOffset = 0x001c;

const u32 biosKeyFirstDataOffset = 0x001e;

u16 GetLastKeyInBiosBuffer()
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

void FlushBiosKeyBuffer()
{
    u16 headPtr = biosKeyFirstDataOffset;
    u16 tailPtr = biosKeyFirstDataOffset;

    _dosmemputw(&headPtr, 2, biosKeySeg * 16 + biosKeyHeadPtrOffset);
    _dosmemputw(&tailPtr, 2, biosKeySeg * 16 + biosKeyTailPtrOffset);
}

// Mimic Apple II behaviour
unsigned int GetBiosBufferedKey()
{
    u16 key;

    if (GetLastKeyInBiosBuffer() == KEYSCAN_SPACE)
        FlushBiosKeyBuffer();

    // TODO: write custom keyboard routine
    key = kbhit() ? KEY_PollKey() : KEYSCAN_SPACE;

    return key;
}
