#include "COMMON.H"

#include "FUNCS.H"
#include "VARS.H"

#include "GRAP_DRV.H"

#include <stdio.h>
#include <stdlib.h>

//#define VERBOSE_LOG

//
#ifdef _WIN32

int u5_getch();

#else
int u5_getch() { return getch(); }

int u5_peekch()
{
    if (kbhit())
        return getch();
    return 0;
}
#endif

FUN_1000_102e_unload_tileset(void) { puts("FUN_1000_102E_unload_tileset"); }

void FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(byte* img, int idx, int x, int y)
{
    //printf("FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(ptr,%d,%d,%d)\n", idx, x, y);
    // ax = a, bx = idx, si = c, di = d
    DRV_4e(img, idx, x, y);
}

int F_FONT_02fc(int param_1);
void DRV_66(int ax, int bx, int cx, int dx, int si, int di, int cf);

// NOT MATCHING
int FUN_1000_1068(int param_1, int param_2, int param_3)
{
    int iVar1;
    int di;

    di = 0;

    do
    {
        while (1)
        {
            do
            {
                // ax = param_2 <- x
                // bx = param_3 <- y
                // si = param_1 <- tile
                // di = progress
                // cx = 52bc <- offset x
                // dx = 52be <- offset y
                DRV_66(param_2, param_3, D_52ba_vdp._52bc, D_52ba_vdp._52be, param_1, di, 1);

                di++;
                DRV_66(param_2, param_3, D_52ba_vdp._52bc, D_52ba_vdp._52be, param_1, di, 1);

                di++;

                if (di == 0x100)
                {
                    return 0;
                }
            } while ((di & 7) != 0);

            if (D_5893_map_id == 0x42)
                break;

            FUN_1000_5910_update_map();
        }

        iVar1 = F_FONT_02fc(1);
    } while (iVar1 == 0);

    return iVar1;
}

// OK P1 (NOT MATCHING: driver)
void FUN_1000_10e0_GRAP_51_draw_tile(uint tile, int x, int y)
{
    // al = x
    // ah = y
    // bx = tile
    // cx = 52bc, dx = 52be, si = 52c0, di = 52c2
    DRV_51_put_tile(x, y, tile, D_52ba_vdp._52bc, D_52ba_vdp._52be, D_52ba_vdp._52c0, D_52ba_vdp._52c2);
}

void FUN_1000_1112_GRAP_60(int a, int b, int c)
{
    printf("FUN_1000_1112(%d, %d, %d)\n", a, b, c);
    DRV_60(a, D_5893_map_id, D_52ba_vdp._52bc, D_52ba_vdp._52be, b, c, 1);
}

int FUN_1000_1140_GRAP_6f(void)
{
    return DRV_6f(D_5356);
}

void FUN_1000_1158_init_timer(void) { puts("FUN_1000_1158_init_timer"); }

// NOTE: asm. ret: carry
// NOT MATCHING (asm)
int FUN_1000_1588_is_file_compressed(char* fileName)
{
    char* piVar1;
    char cVar2;
    char cVar3;
    char** puVar4;
    char* piVar5;
    char* pcVar6;

    puVar4 = D_25ea;
    while (1)
    {
        piVar5 = *puVar4;
        if (*piVar5 == 0)
        {
            return 0;
        }

        puVar4++;
        pcVar6 = fileName;
        while (1)
        {
            piVar1 = piVar5++;

            cVar2 = *piVar1;
            cVar3 = *pcVar6;
            if (cVar3 > 96 && cVar3 < 123)
            {
                cVar3 -= 0x20;
            }

            if (cVar2 > 96 && cVar2 < 123)
            {
                cVar2 -= 0x20;
            }

            if (cVar3 != cVar2)
                break;

            if (*piVar5 == '\0')
            {
                return 1;
            }

            pcVar6++;
        }
    }
}

int FUN_1000_1674_test_open_file(char* file_name)
{
    printf("FUN_1000_1674_test_open_file(%s)\n", file_name);
    // FMT (dummy)
    return 1;
}

u8 FUN_1000_16a6_get_default_drive()
{
    puts("FUN_1000_16a6_get_default_drive");
    // FMT (dummy)
    return 'D';
}

// OK P1 (NOT MATCHING: optimization)
// print_integer(val, min_len, filler)
void FUN_1000_1a3e_print_number(int param_1, int param_2, int param_3)
{
    int l_2a = 1; // required_length
    int l_2c;     // space
    int l_2e = 0; // is_negative
    int l_30;
    char local_28[40];

    register s16 *si;

    if (param_2 > 39)
    {
        param_2 = 39;
    }

    // 1a5b
    if (param_1 < 0) // is negative?
    {
        l_2e++; // is_negative = true
        param_1 = -param_1;
    }

    // 1a6c
    l_30 = 5;

    si = &D_5402[1];
    do
    {
        // 1a7a
        if (*si <= param_1) // cmp order?
        {
            l_2a++;
        }
        si++;
    } while (si < &D_5402[5]); // 1a7f

    if (l_2e)
    {
        l_2a++;
    }

    // 1a94
    l_2c = param_2 - l_2a;
    if (l_2c <= 0)
    {
        l_2c = 0;
    }
    else
    {
        // 1aa8: NOT MATCHING (loop optimization)
        for (l_30 = 0; l_30 != l_2c; l_30++)
        {
            local_28[l_30] = param_3;
        }
    }

    // 1ac0
    if (l_2e)
    {
        local_28[l_2c++] = '-';
        l_2a--;
    }

    // 1ad3: NOT MATCHING
    do
    {
        l_30 = D_5402[l_2a - 1];
        l_2e = param_1 / l_30;
        local_28[l_2c++] = (char)l_2e + '0';

        param_1 -= l_30 * l_2e;
    } while (--l_2a != 0);

    // 1afb
    local_28[l_2c] = '\0';

    FUN_1000_1850_print_string(local_28);
}

void FUN_1000_1b24_clear_keyboard_buffer_impl();

// STUB
void FUN_1000_1b16_clear_keyboard_buffer()
{
    // push ds
    FUN_1000_1b24_clear_keyboard_buffer_impl();
    // pop ds
}

// asm
// STUB
void FUN_1000_1b24_clear_keyboard_buffer_impl()
{
    // BIOS key buffer
    // DS = 0x40
    // (word)DS:[0x1a] = 0x1e;
    // (word)DS:[0x1c] = 0x1e;

    // *headPtr = 0x1e;
    // *tailPtr = 0x1e;
}

// NOt MATCHING
u16 FUN_1000_1b38_keystroke_cursor(void)
{
    int local_2;
    int local_4;

    local_2 = D_538e;
    D_538e = 0;
    FUN_1000_16ba_print_char(D_5390 + D_540c++);
    local_4 = (u8)FUN_1000_1d5e_peek_keystroke();
    if (D_5392 <= D_540c) {
        D_540c = 0;
    }
    if (local_4 != 0) {
        FUN_1000_16ba_print_char(0x20);
    }
    else {
        FUN_1000_20fa_wait_ticks(1);
    }
    D_538e = local_2;
    return local_4;
}

// NOT MATCHING
void FUN_1000_1c9e_set_charset(int param_1)
{
#ifdef VERBOSE_LOG
    printf("FUN_1000_1c9e_set_charset(%d)\n", a);
#endif

    if (param_1 < 4 && D_539c[param_1] != 0)
    {
        D_5398_currentCharset = D_539c[param_1];
        D_5388_current_charset_idx = param_1;
    }
}

// TODO: NOT MATCHING
void FUN_1000_1cca_set_text_foreground_color(int a)
{
#ifdef VERBOSE_LOG
    printf("FUN_1000_1cca_set_text_foreground_color(%d) [%d]\n", a, D_5386_current_text_window_idx);
#endif

    D_53aa_text_fg_color = a & 0xf;
    D_539a_currentTextWindow->text_colors = (D_539a_currentTextWindow->text_colors & 0xf0) | (a & 0xf);
}

// STUB
int FUN_1000_1d02_load_charset(char* a, int b)
{
    printf("FUN_1000_1d02_load_character_set(%s,%d)\n", a, b);

    D_539c[b] = FUN_1000_0fae_load_file(a);

    // FMT
    return 1;
}

extern int u5_peekch();

int FUN_1000_1d5e_peek_keystroke(void)
{
    return u5_peekch();
}

// STUB
int FUN_1000_1dda_wait_for_keystroke(int a)
{
    printf("FUN_1000_1dda_wait_for_keystroke(%d)\n", a);
    return (u8)u5_getch();
}

// NOT MATCHING
void FUN_1000_1e38_intro_enter_string(char* param_1, int param_2)
{
    int local_6;
    int local_4;

    local_4 = 0;
    do
    {
        local_6 = FUN_1000_1dda_wait_for_keystroke(0);
        if ((local_6 == 8 || local_6 == 1) && local_4 != 0)
        {
            FUN_1000_1fa0_backspace(1);
            local_4--;
        }
        else if (local_6 == 0x1b && local_4 != 0)
        {
            FUN_1000_1fa0_backspace(local_4);
            local_4 = 0;
        }
        else if (local_6 > 0x1f && local_6 < 0x80 && local_4 < param_2)
        {
            param_1[local_4] = local_6;
            local_4++;
            FUN_1000_16ba_print_char(local_6);
        }
    } while (local_6 != 0xd);

    param_1[local_4] = 0;
}

// STUB
int FUN_1000_1eac_set_default_drive(int param_1)
{
    printf("FUN_1000_1dda_wait_for_keystroke(%c)\n", param_1);
}

// TODO: NOT MATCHING
void FUN_1000_1f26_set_text_background_color(int a)
{
#ifdef VERBOSE_LOG
    printf("FUN_1000_1f26_set_text_background_color(%d) [%d]\n", a, D_5386_current_text_window_idx);
#endif

    D_53ab_text_bg_color = a & 0xf;
    D_539a_currentTextWindow->text_colors = (D_539a_currentTextWindow->text_colors & 0xf) | ((a & 0xf) << 4);
}

// NOT MATCHING
void FUN_1000_1fa0_backspace(int char_count)
{
    u16 uVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    if ((FUN_1000_1f12_get_current_text_column() != 0 || FUN_1000_1cee_get_current_text_row() != 0) && char_count != 0)
    {
        uVar1 = D_538e;
        D_538e = 0;

        if (char_count > 0)
        {
            iVar2 = D_535e_textWindows[D_5386_current_text_window_idx].right - D_535e_textWindows[D_5386_current_text_window_idx].left;
            for (iVar5 = 0; iVar5 < char_count; iVar5++)
            {
                iVar3 = FUN_1000_1f12_get_current_text_column();
                FUN_1000_16ba_print_char(0x20);
                if (iVar3 == 0)
                {
                    iVar3 = iVar2;
                    iVar4 = FUN_1000_1cee_get_current_text_row(iVar2) - 1;
                }
                else
                {
                    iVar3--;
                    iVar4 = FUN_1000_1cee_get_current_text_row(iVar3);
                }

                FUN_1000_1bf2_set_text_cursor_position(iVar3, iVar4);
            }
        }

        D_538e = uVar1;
    }
}
