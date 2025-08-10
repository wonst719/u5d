#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

// OK P1
u16 FUN_1000_2032_to_upper(u8 x)
{
    if (x >= 0x61 && 0x7a >= x)
    {
        return x - 0x20;
    }

    return x;
}

// OK P1
u8 FUN_1000_266c_get_ch_impl(void)
{
    int local_4;

    if (D_52c8 == 2)
    {
        D_5891 = 0xff;
    }

    do
    {
        local_4 = FUN_1000_2032_to_upper(FUN_1000_1b38_keystroke_cursor());
        if ((local_4 == 0) && (D_5893_map_id < 0x21 || 0x7f < D_5893_map_id))
        {
            FUN_1000_5910();
        }
    } while (local_4 == 0);

    if (D_538a != 0)
    {
        // numpad
        switch (local_4)
        {
        case 0x31:
            local_4 = 0xd4;
            break;
        case 0x32:
            local_4 = 4;
            break;
        case 0x33:
            local_4 = 0xd6;
            break;
        case 0x34:
            local_4 = 1;
            break;
        case 0x36:
            local_4 = 2;
            break;
        case 0x37:
            local_4 = 0xd3;
            break;
        case 0x38:
            local_4 = 3;
            break;
        case 0x39:
            local_4 = 0xd5;
        }
    }
    else
    {
        if (local_4 < 5)
            local_4 += 0xfa;
    }

    return local_4;
}

FUN_1000_20fa_wait_ticks(int a)
{
    /*puts("FUN_1000_20FA_wait_ticks");*/

#ifdef _WIN32
    void u5_sleep(int ms);
    u5_sleep(a * 55); // 18.2 ticks per second
#endif
}
