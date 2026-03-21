#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include "GRAP_DRV.H"

#include <stdio.h>
#include <string.h>

//#define VERBOSE_LOG

void ULTIMA_17f4_apply_character_effects(byte* es, int di);

// NOT MATCHING (asm?)
void ULTIMA_16ba_print_char(uint ch)
{
    int iVar4;
    byte bVar6;
    int uVar7;
    TextWindow* text_window;

    bVar6 = ch;
    text_window = D_539a_currentTextWindow;
    if (ch > 0x7f)
    {
        if (ch == 0xff)
        {
            int ax, bx, cx, dx;

            text_window->current_x = 0;
            text_window->current_y = 0;
            DRV_2d((text_window->text_colors >> 4) & 0xf);
            ULTIMA_1f77_convert_char_dimensions_to_pixels(text_window, &ax, &bx, &cx, &dx);
            DRV_3f(ax, bx, cx, dx, 0);
            DRV_2d(D_52da_pen_color);
            return;
        }
        if (ch == 0xfe) // toggle underline
        {
            D_53a4_underline ^= 1;
            text_window->text_effects ^= 1; // underline
            return;
        }
        if (ch == 0xfd) // toggle inversion
        {
            D_53a8_inverse ^= 1;
            text_window->text_effects ^= 4; // inverse
            return;
        }
        if (ch == 0xfc)
        {
            D_53a6 = 1;
            text_window->text_effects |= 2;
            return;
        }
        if (ch == 0xfb)
        {
            D_53a6 = 0;
            text_window->text_effects &= 0xfd;
            return;
        }
        ch &= 0x7f;
    }

    if (ch != 0xa)
    {
        if (ch == 0xd)
        {
            goto LAB_1000_1745;
        }

        // Render Character
        uVar7 = bVar6 * 8;
        if (D_52ba_vdp._52c8_videoDriverSelection == 3)
        {
            uVar7 = bVar6 * 24;
        }
        ULTIMA_17f4_apply_character_effects(D_5398_currentCharset, uVar7);

        // es = 5398
        // di = uVar7
        // dl = [D_53aa_text_fg_color]
        // dh = [D_53ab_text_bg_color]
        // al = [text_window + current_x] + [text_window + left]
        // ah = 0
        // bl = [text_window + current_y] + [text_window + top]
        // bh = 0
        DRV_5d(D_5398_currentCharset, uVar7, D_53aa_text_fg_color, D_53ab_text_bg_color,
            text_window->current_x + text_window->left, text_window->current_y + text_window->top);

        iVar4 = 4;
        if (D_52ba_vdp._52c8_videoDriverSelection == 3)
        {
            iVar4 = 12;
        }

        memcpy(D_5398_currentCharset + uVar7, D_53ea, iVar4 * 2);

        text_window = D_539a_currentTextWindow;
        if (D_538e == 0)
        {
            return;
        }

        text_window->current_x++;
        if ((char)(text_window->current_x + text_window->left) <= text_window->right)
        {
            return;
        }
    }

    text_window->current_y++;

LAB_1000_1745:
    text_window->current_x = 0;
    if (text_window->bottom < text_window->current_y + text_window->top)
    {
        int ax, bx, cx, dx;
        ULTIMA_1f77_convert_char_dimensions_to_pixels(text_window, &ax, &bx, &cx, &dx);
        text_window->current_y--;
        DRV_27(ax, bx, cx, dx, -8);
    }
}

// NOT MATCHING
// ptr = (es:)di
void ULTIMA_17f4_apply_character_effects(byte* es, int di)
{
    int size;
    byte* ptr = es + di;

    size = 4;
    if (D_52ba_vdp._52c8_videoDriverSelection == 3)
    {
        size = 12;
    }

    memcpy(D_53ea, ptr, size * 2);

    if (D_53a4_underline != 0)
    {
        if (D_52ba_vdp._52c8_videoDriverSelection == 3)
        {
            // herc
            *(u16*)&ptr[0x16] = 0xffff;
        }
        else
        {
            // ega/cga/t1k
            ptr[7] = 0xff;
        }
    }

    if (D_53a8_inverse != 0)
    {
        size = 4;
        if (D_52ba_vdp._52c8_videoDriverSelection == 3)
        {
            // herc
            size = 12;
        }

        size *= 2;
        for (; size > 0; size--)
        {
            *ptr = ~*ptr;
            ptr++;
        }
    }
}

// OK P1 (NOT MATCHING: register, loop optimization)
// 0000:1850
void ULTIMA_1850_print_string(char* param_1)
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
    
    //debug("GRAP_PrintString(%s)", param_1);

    local_8 = 0;
    local_a = 0;
    local_4 = 0;
    if (*param_1 != '\0')
    {
        // 1872 OK P1
        local_12 = &D_535e_textWindows[D_5386_current_text_window_idx];
        local_1a = local_12->text_effects & 2;
        local_44 = (uint)local_12->right - (uint)local_12->left; // text_window_width = r - l;

        // 189a
        do
        {
            if (local_4 != 0)
            {
                ULTIMA_16ba_print_char(10);
            }

            // 18a7 (NOT MATCHING: si register)
            local_4 = local_6 = local_14 = 0;
            local_10 = local_44 - ULTIMA_1f12_get_current_text_column(); // remaining_length = text_window_length - column

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
                    ULTIMA_16ba_print_char((byte)param_1[local_8++]);
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
                            ULTIMA_16ba_print_char(10);
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
                        ULTIMA_16ba_print_char(10);
                    }

                    // 19ea
                    ULTIMA_1bf2_set_text_cursor_position((local_10 - local_c) / 2, ULTIMA_1cee_get_current_text_row());
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
                    ULTIMA_16ba_print_char((byte)local_42[local_14]);
                }
            }
        } while (local_a == 0);
    }
    return;
}


// NOTE: not matching
void ULTIMA_1b94_select_text_window(int id)
{
    register int b;

#ifdef VERBOSE_LOG
    debug("ULTIMA_1b94_select_text_window(%d)", id);
#endif

    if (id <= 3)
    {
        D_5386_current_text_window_idx = id;
        D_539a_currentTextWindow = &D_535e_textWindows[id];

        b = D_539a_currentTextWindow->text_colors;
        D_53aa_text_fg_color = b & 0xf;
        D_53ab_text_bg_color = (b & 0xf0) >> 4;

        b = D_539a_currentTextWindow->text_effects;
        D_53a4_underline = b & 1;
        D_53a6 = (b & 2) >> 1;
        D_53a8_inverse = (b & 4) >> 2;
    }
}

// NOTE: not matching
void ULTIMA_1bf2_set_text_cursor_position(int x, int y)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1bf2_set_text_cursor_position(%d,%d)", x, y);
#endif

    if ((byte)x + D_539a_currentTextWindow->left < 40 && (byte)y + D_539a_currentTextWindow->top < 25)
    {
        D_539a_currentTextWindow->current_x = x;
        D_539a_currentTextWindow->current_y = y;
    }
}

byte ULTIMA_1c5b_constrain_textwindow(int* x1, int* y1, int* x2, int* y2);

// NOTE: not matching
void ULTIMA_1c22_set_text_window_size(int idx, int x1, int y1, int x2, int y2)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1c22_set_text_window_size(%d,%d,%d,%d,%d)", idx, x1, y1, x2, y2);
#endif
    if (idx < 4)
    {
        TextWindow* win = &D_535e_textWindows[idx];
        ULTIMA_1c5b_constrain_textwindow(&x1, &y1, &x2, &y2);
        ASSERT(x1 <= x2);
        ASSERT(y1 <= y2);
        win->left = (u8)x1;
        win->top = (u8)y1;
        win->right = (u8)x2;
        win->bottom = (u8)y2;
    }
}

// NOTE: not matching
byte ULTIMA_1c5b_constrain_textwindow(int* x1, int* y1, int* x2, int* y2)
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

    return *x1;
}

int ULTIMA_1cee_get_current_text_row()
{
    return D_539a_currentTextWindow->current_y;
}

int ULTIMA_1f12_get_current_text_column()
{
    return D_539a_currentTextWindow->current_x;
}

// param: SI = window
ULTIMA_1f77_convert_char_dimensions_to_pixels(TextWindow* window, int *pAX, int *pBX, int *pCX, int *pDX)
{
    int ax = (int)window->left << 3;
    int bx = (int)window->top << 3;
    int cx = ((int)window->right << 3) + 7;
    int dx = ((int)window->bottom << 3) + 7;

    *pAX = ax;
    *pBX = bx;
    *pCX = cx;
    *pDX = dx;
}
