#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include "GRAP_DRV.H"

#include <string.h>

void F_SJOG_203e(int a);

void FUN_1000_60ec_load_special_map(int a) { printf("FUN_1000_60ec_load_special_map(%d)\n", a); }

void FUN_1000_6150_attack_monster(int param_1)
{
    byte bVar1;
    bool bVar2;
    uint uVar3;
    undefined2 local_4;

    uVar3 = D_5c5a[param_1]._0_tile & 0xfc;

    FUN_1000_16ba_print_char(10);
    FUN_1000_16ba_print_char(0xfc);
    if (uVar3 < 0x40)
    {
        FUN_1000_1850_print_string("PIRATES");
    }
    else
    {
        FUN_1000_1850_print_string(D_18b6[(uVar3 - 0x40) / 4]);
    }
    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1850_print_string("\n\n");

    bVar1 = *FUN_1000_4402_get_address_of_tile_id(D_5c5a[param_1]._2_x, D_5c5a[param_1]._3_y);
    if (bVar1 < 4 || (bVar1 & 0xfe) != 0x6a && ((bVar1 & 0xf0) == 0x60))
    {
        bVar2 = 1;
    }
    else
    {
        bVar2 = 0;
    }

    if (uVar3 == 0xfc)
    {
        local_4 = 10;
        if (D_57b5 != 0)
        {
            FUN_1000_1850_print_string("The Sceptre is reclaimed!\n");
            FUN_1000_2192_audio_some_noise(0xfd2, 1, 65000, 1, 1);
            D_57b5 = 0;
        }
    }
    else if (((byte)uVar3 & 0xf0) == 0x80)
    {
        bVar2 = 1;
    }

    if ((D_587c & 0xf8) == 0x20)
    {
        if (uVar3 == 0x2c)
        {
            local_4 = 0xe;
        }
        else if (bVar2)
        {
            local_4 = 0xb;
        }
        else
        {
            local_4 = 0xd;
        }
    }
    else if (uVar3 == 0x2c)
    {
        local_4 = 0xc;
    }
    else if (bVar2)
    {
        local_4 = 0xf;
    }
    else
    {
        switch (bVar1)
        {
        case 1:
        case 2:
        case 3:
            local_4 = 0xf;
            break;
        case 4:
            local_4 = 1;
            break;
        case 6:
        case 8:
            local_4 = 3;
            break;
        case 7:
        case 0x1e:
        case 0x1f:
            local_4 = 4;
            break;
        case 9:
        case 10:
            local_4 = 5;
            break;
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
            local_4 = 6;
            break;
        default:
            if (D_5893_map_id != '\0')
                local_4 = 8;
            // fall-through
        case 5:
            local_4 = 2;
            break;
        case 0x1d:
        case 0x48:
        case 0x49:
        case 0x6a:
        case 0x6b:
            local_4 = 7;
            break;
        case 0x44:
            local_4 = 8;
            break;
        }
    }

    FUN_1000_60ec_load_special_map(local_4);
    FUN_1000_5f86_special_handler(0, param_1, 0);
    F_SJOG_203e(param_1);
    FUN_1000_5e4a();
    FUN_1000_4f7c(0);
}

// draw_frame
// FMT: F_26840
void FUN_1000_637e_draw_frame(void)
{
    // black
    FUN_1000_0a70_set_pen_color(0);
    FUN_1000_0aa6_fill_rectangle(0, 0, 319, 199);

    FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
    FUN_1000_0aa6_fill_rectangle(0, 0, 319, 6);
    FUN_1000_0aa6_fill_rectangle(0, 185, 191, 191);
    FUN_1000_0aa6_fill_rectangle(0, 0, 6, 191);
    FUN_1000_0aa6_fill_rectangle(185, 0, 191, 191);
    FUN_1000_0aa6_fill_rectangle(313, 0, 319, 87);
    FUN_1000_0aa6_fill_rectangle(192, 80, 312, 87);
    FUN_1000_0aa6_fill_rectangle(192, 0x39, 312, 63);

    FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
    FUN_1000_1bf2_set_text_cursor_position(0, 0);
    FUN_1000_16ba_print_char(0x7b);
    FUN_1000_1bf2_set_text_cursor_position(39, 0);
    FUN_1000_16ba_print_char(0x7c);
    FUN_1000_1bf2_set_text_cursor_position(0, 23);
    FUN_1000_16ba_print_char(0x7d);

    FUN_1000_0a70_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_line(7, 7, 7, 184);
    FUN_1000_0f90_pen(184, 184);
    FUN_1000_0f90_pen(184, 7);
    FUN_1000_0f90_pen(7, 7);
    FUN_1000_0b10_line(191, 191, 191, 87);
    FUN_1000_0f90_pen(319, 87);
    FUN_1000_0b10_line(191, 7, 312, 7);
    FUN_1000_0f90_pen(312, 56);
    FUN_1000_0f90_pen(191, 56);
    FUN_1000_0f90_pen(191, 7);
    FUN_1000_0b10_line(191, 63, 312, 63);
    FUN_1000_0f90_pen(312, 80);
    FUN_1000_0f90_pen(191, 80);
    FUN_1000_0f90_pen(191, 63);

    FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
}

// from FMT
u8 DAT_000738d8[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x20, 0x20,
                     0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                     0x88, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
                     0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x10, 0x10, 0x10, 0x10, 0x20};

// from FMT (27c98)
int FUN_1000_6f1e(char* param_1, char* param_2)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    int local_18;
    char local_14[10];

    local_18 = -1;
    memset(local_14, 0, 10);

    for (iVar2 = 0; iVar2 < 9 && (iVar3 = iVar2, param_1[iVar2] != '\0'); iVar2++)
    {
        bVar1 = param_1[iVar2] & 0x7f;
        if ((DAT_000738d8[bVar1] & 2) != 0)
        {
            bVar1 = (param_1[iVar2] & 0x7fU) - 0x20;
        }
        local_14[iVar2] = bVar1;
    }

    iVar2 = strncmp(local_14, param_2, iVar3);
    if (iVar2 == 0)
    {
        local_18 = 0;
    }

    return local_18;
}

// assembly (uses al, bx, cx, di)
int FUN_1000_6f90(char* di)
{
    // repne scasb
    return strlen(di);
}

void FUN_1000_6fbc(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    DRV_6c(param_1, bl, bh);
}

// DUMMY
void FUN_1000_6fd6()
{
    // CLC
    // ax: D_539c
    // DRV_60(D_539c);
}

// NOT MATCHING (asm?)
int FUN_1000_6ff0(register int param_1, register int param_2)
{
    if ((param_1 < 0xb) && (param_2 < 0xb))
    {
        if ((param_1 > 5) || (param_2 > 5))
        {
            if (param_1 > 5)
            {
                param_1 = 10 - param_1;
            }
            if (param_2 > 5)
            {
                param_2 = 10 - param_2;
            }
        }

        return D_6aa8[param_1 + param_2 * 6];
    }

    return 0;
}
