#include "COMMON.H"
#include "VARS.H"

#include "PCTIMER.H"

#include <stdlib.h>
#include <conio.h>

void KEY_Initialize()
{
    // TODO: separate timer
    pctimer_init(1000);
    atexit(pctimer_exit);
}

void KEY_Cleanup()
{
}

#define KEY_UP 0x48
#define KEY_LEFT 0x4b
#define KEY_RIGHT 0x4d
#define KEY_DOWN 0x50

int u5_peekch()
{
    if (kbhit())
    {
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

int u5_getch()
{
    int ret;

    do
    {
        ret = u5_peekch();

        //debug("u5_getch %d", ret);

    } while (ret == 0);

    return ret;
}

void u5_sleep(int ms)
{ pctimer_sleep(ms); }
