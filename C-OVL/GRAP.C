#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

// 
undefined2 far DRV_FarCall(int offset)
{
    //
}

// set pen color
undefined2 far DRV_FarCall_2d(int al)
{
    // DRV:0312 = (byte)ax;
}

// TODO
CONCAT22(){}

// NOT MATCHING
void FUN_1000_0a70_set_pen_color(int param_1)
{
    if (param_1 != -1)
    {
        param_1 &= D_52ba_vdp._52c8_videoDriverSelection == 0 ? 3 : 0xf;
    }

    D_52da_pen_color = param_1;

    if (param_1 != -1)
    {
        DRV_FarCall_2d(param_1);
    }
}

void FUN_1000_0892_initialize_video_driver(int a)
{
#ifdef _WIN32
    extern void GRAP_WIN_InitializeVideoDriver();

    GRAP_WIN_InitializeVideoDriver();

    // FIXME
    D_538e = 1;
#endif
}

// NOT MATCHING
void FUN_1000_16ba_print_char(uint ch)
{
    undefined2* puVar1;
    undefined2* puVar2;
    undefined* puVar3;
    int iVar4;
    undefined2* puVar5;
    uint uVar6;
    undefined2* puVar7;
    TextWindow* text_window;
    undefined2* pCharacter;
    undefined2 unaff_DS;

    text_window = D_539a_textWinForCurrCharset;
    if (0x7f < ch) {
        if (ch == 0xff) {
            text_window->current_x = 0;
            text_window->current_y = 0;
            DRV_FarCall(0x2d);
            FUN_1000_1f77_convert_char_dimensions_to_pixels(text_window);

            DRV_FarCall(0x3f);
            DRV_FarCall(0x2d);
            return;
        }
        if (ch == 0xfe) {
            D_53a4_underline ^= 1;
            text_window->text_effects ^= 1;
            return;
        }
        if (ch == 0xfd) {
            D_53a8_inverse ^= 1;
            text_window->text_effects ^= 4; // inverse
            return;
        }
        if (ch == 0xfc) {
            D_53a6 = 1;
            text_window->text_effects |= 2;
            return;
        }
        if (ch == 0xfb) {
            D_53a6 = 0;
            text_window->text_effects &= 0xfd;
            return;
        }
        ch = ch & 0x7f;
    }
    if (ch != 0xa) {
        if (ch == 0xd)
            goto LAB_1000_1745;

#ifdef _WIN32
        extern void GRAP_WIN_PrintChar(int x, int y, uint ch);
        GRAP_WIN_PrintChar(text_window->current_x + text_window->left, text_window->current_y + text_window->top, ch);
#else
        // Render Character
        puVar7 = (undefined2*)(uVar6 * 8);
        if (D_52ba_vdp._52c8_videoDriverSelection == 3) {
            puVar7 = (undefined2*)(uVar6 * 0x18);
        }
        puVar3 = (undefined*)D_5398; // seg
        FUN_1000_17f4_character_effects((undefined*)CONCAT22(puVar7, puVar3));
        DRV_FarCall(0x5d);
        puVar5 = D_53ea;
        iVar4 = 4;
        if (D_52ba_vdp._52c8_videoDriverSelection == 3) {
            iVar4 = 12;
        }
        for (; iVar4 != 0; iVar4--) {
            puVar2 = puVar7++;
            puVar1 = puVar5++;
            *puVar2 = *puVar1;
        }
#endif
        text_window = D_539a_textWinForCurrCharset;
        if (D_538e == 0) {
            return;
        }
        text_window->current_x++;
        if ((char)(text_window->current_x + text_window->left) <= text_window->right) {
            return;
        }
    }
    text_window->current_y++;
LAB_1000_1745:
    text_window->current_x = 0;
    if (text_window->bottom < (char)(text_window->current_y + text_window->top)) {
#ifdef _WIN32
        extern void GRAP_WIN_ScrollWindow(TextWindow *window, int amount);
        GRAP_WIN_ScrollWindow(text_window, -8);
        text_window->current_y--;
#else
        FUN_1000_1f77_convert_char_dimensions_to_pixels(text_window);
        text_window->current_y--;
        // SI = 0xfff8 = -8;
        DRV_FarCall(0x27);
#endif
    }
}

// OK P1 (NOT MATCHING: register, loop optimization)
// 0000:1850
void FUN_1000_1850_print_string(char* param_1)
{
    undefined2 local_44;
    char local_42[40];
    uint local_1a;
    int local_18;
    int local_16;
    int local_14;
    TextWindow *local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;
    
    printf("GRAP_PrintString(%s)\n", param_1);

    local_8 = 0;
    local_a = 0;
    local_4 = 0;
    if (*param_1 != '\0')
    {
        // 1872 OK P1
        local_12 = &D_535e_textWindows[D_5386_currentTextWindow];
        local_1a = local_12->text_effects & 2;
        local_44 = (uint)local_12->right - (uint)local_12->left; // text_window_width = r - l;

        // 189a
        do
        {
            if (local_4 != 0)
            {
                FUN_1000_16ba_print_char(10);
            }

            // 18a7 (NOT MATCHING: si register)
            local_4 = local_6 = local_14 = 0;
            local_10 = local_44 - FUN_1000_1f12_get_current_text_column(); // remaining_length = text_window_length - column

            for (local_c = 0; param_1[local_8] != '\n' && param_1[local_8] != '\r' && param_1[local_8] != '\0'
                && local_c <= local_10; local_8++, local_c++)
            {
                local_42[local_c] = param_1[local_8];
            }

            // 18f4 (after loop)
            if (local_c == 0)
            {
                if (param_1[local_8] != '\0')
                {
                    FUN_1000_16ba_print_char((byte)param_1[local_8++]);
                }
                else
                {
                    local_a++;
                }
            }
            else
            {
                // 191c
                if (local_c > local_10)
                {
                    // 1927
                    local_18 = local_c;
                    local_16 = local_8;

                    // 1939 (NOT MATCHING: optimization)
                    for (; param_1[local_8] != ' ' && local_c != 0 &&
                           param_1[local_8] != '\n' &&
                            param_1[local_8] != '\0' && param_1[local_8] != '\r'; local_c--, local_8--)
                    {
                    }

                    // 1968
                    if (local_c == 0) {
                        local_c = local_18;
                        local_8 = local_16;

                        if (local_12->current_x != 0)
                        {
                            FUN_1000_16ba_print_char(10);
                            local_6 = 1;
                        }
                    }
                    else
                    {
                        // 1996
                        do
                        {
                            local_c--;
                        } while (local_42[local_c] == ' ' ||
                            local_42[local_c] == '\r' ||
                            local_42[local_c] == '\n');

                        if (param_1[local_8] != '\0')
                            local_8++;

                        // 19bf
                        if (local_c < local_10)
                            local_4++;
                    }

                    // 19ca
                    if (local_c > local_10)
                        local_c--;
                }
                else
                {
                    local_c--;
                }

                // 19d5
                if (local_1a != 0)
                {
                    if (local_c > local_44)
                    {
                        FUN_1000_16ba_print_char(10);
                    }

                    // 19ea
#ifdef _WIN32
                    FUN_1000_1bf2_set_text_cursor_position(FUN_1000_1cee_get_current_text_row((local_10 - local_c) / 2), 0);
#else
                    // FIXME: parameter missing; sic
                    FUN_1000_1bf2_set_text_cursor_position(FUN_1000_1cee_get_current_text_row((local_10 - local_c) / 2)/*, parameter missing */);
#endif
                }

                // 19fd (NOT MATCHING: loop optimization)
                if (local_6 != 0)
                {
                    // 1a03
                    for (; local_42[local_14] == ' '; local_14++)
                    {
                    }
                }

                // 1a14 (NOT MATCHING: loop optimization)
                for (; local_14 <= local_c; local_14++)
                {
                    // 1a1c
                    FUN_1000_16ba_print_char((byte)local_42[local_14]);
                }
            }
        } while (local_a == 0);
    }
    return;
}


// NOTE: not matching
void FUN_1000_1b94_select_charset(int id)
{
    register int b;

    printf("FUN_1000_1b94_select_charset(%d)\n", id);

    if (id <= 3)
    {
        D_5386_currentTextWindow = id;
        D_539a_textWinForCurrCharset = &D_535e_textWindows[id];

        b = D_539a_textWinForCurrCharset->text_colors;
        D_53aa_text_bg_color = b & 0xf;
        D_53ab_text_fg_color = (b & 0xf0) >> 4;

        b = D_539a_textWinForCurrCharset->text_effects;
        D_53a4_underline = b & 1;
        D_53a6 = (b & 2) >> 1;
        D_53a8_inverse = (b & 4) >> 2;
    }
}

// NOTE: not matching
void FUN_1000_1bf2_set_text_cursor_position(int x, int y)
{
    printf("FUN_1000_1bf2_set_text_cursor_position(%d,%d)\n", x, y);

    if ((byte)x + D_539a_textWinForCurrCharset->left < 40 && (byte)y + D_539a_textWinForCurrCharset->top < 25)
    {
        D_539a_textWinForCurrCharset->current_x = x;
        D_539a_textWinForCurrCharset->current_y = y;
    }
}

byte FUN_1000_1c5b_constrain_textwindow(int* x1, int* y1, int* x2, int* y2);

// NOTE: not matching
void FUN_1000_1c22_set_text_window_size(int idx, int x1, int y1, int x2, int y2)
{
    printf("FUN_1000_1c22_set_text_window_size(%d,%d,%d,%d,%d)\n", idx, x1, y1, x2, y2);
    if (idx < 4)
    {
        TextWindow* win = &D_535e_textWindows[idx];
        FUN_1000_1c5b_constrain_textwindow(&x1, &y1, &x2, &y2);
        win->left = (u8)x1;
        win->top = (u8)y1;
        win->right = (u8)x2;
        win->bottom = (u8)y2;
    }
}

// NOTE: not matching
byte FUN_1000_1c5b_constrain_textwindow(int* x1, int* y1, int* x2, int* y2)
{
    if (*x1 < 0)
        *x1 = 0;

    if (*x1 > 39)
        *x1 = 39;

    if (*y1 < 0)
        *y1 = 0;

    if (*y1 > 24)
        *y1 = 24;

    if (*x2 < 0)
        *x2 = 0;

    if (*x2 > 39)
        *x2 = 39;

    if (*y2 < 0)
        *y2 = 0;

    if (*y2 > 24)
        *y2 = 24;

    if (*x1 > *x2)
    {
        // XCHG
        int temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }

    if (*y1 > *y2)
    {
        // XCHG
        int temp = *y1;
        *y1 = *y2;
        *y2 = temp;
    }

    return x1;
}

int FUN_1000_1cee_get_current_text_row()
{
    return D_539a_textWinForCurrCharset->current_y;
}

byte FUN_1000_1f12_get_current_text_column()
{
    return D_539a_textWinForCurrCharset->current_x;
}

// param: SI
FUN_1000_1f77_convert_char_dimensions_to_pixels(TextWindow* window)
{
    int ax = window->left >> 3;
    int bx = window->top >> 3;
    int cx = (window->right >> 3) + 7;
    int dx = (window->bottom >> 3) + 7;
}

// OK P1
void FUN_1000_2e96_print_direction(int direction)
{
    if (direction != -1)
    {
        D_5892_wind_dir = (char)direction;
        D_5883 = 0;
    }

    if (D_5893_map_id >= 0x21 || D_5893_map_id == 0x19)
        return;

    if (D_5895_map_level < 0x80) // s8 level >= 0?
    {
        FUN_1000_1b94_select_charset(0);
        FUN_1000_1bf2_set_text_cursor_position(6, 0x17);
        FUN_1000_4c2a();

        switch (D_5892_wind_dir)
        {
        case 0:
            FUN_1000_1850_print_string("Calm "); // 555c
            break;
        case 1:
            FUN_1000_1850_print_string("North"); // 5562
            break;
        case 2:
            FUN_1000_1850_print_string("South"); // 5568
            break;
        case 3:
            FUN_1000_1850_print_string("East "); // 556e
            break;
        case 4:
            FUN_1000_1850_print_string("West "); // 5574
            break;
        }

        FUN_1000_1850_print_string(" Winds"); // 557a
        FUN_1000_4cce();
        FUN_1000_1b94_select_charset(2);
    }
    else
    {
        // level < 0
        FUN_1000_0a70_set_pen_color(D_13b0_white_color);
        FUN_1000_0b10_line(0x30, 0xb8, 0x98, 0xb8);
        FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
        FUN_1000_0aa6_fill_rectangle(0x30, 0xb9, 0x98, 0xbf);
    }
}
