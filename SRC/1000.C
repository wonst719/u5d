#include "COMMON.H"

#include "FUNCS.H"
#include "VARS.H"

#include "GRAP_DRV.H"

#include <string.h>

//#define VERBOSE_LOG

//
#if !defined(TARGET_DOS16)

extern int u5_getch();
extern int u5_peekch();

#else
int u5_getch() { return getch(); }

int u5_peekch()
{
    if (kbhit())
        return getch();
    return 0;
}
void u5_sleep(int ms) {}
#endif

int FONT_02fc(int param_1);
void DRV_66(int ax, int bx, int cx, int dx, int si, int di, int cf);

void ULTIMA_102e_UnloadTileset(void) { debug("ULTIMA_102e_UnloadTileset"); }

void ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(byte* img, int idx, int x, int y)
{
    //debug("ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(ptr,%d,%d,%d)", idx, x, y);
    // ax = a, bx = idx, si = c, di = d
    DRV_4e(img, idx, x, y);
}

// NOT MATCHING
int ULTIMA_1068(int param_1, int param_2, int param_3)
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

            ULTIMA_5910_UpdateFrame();
        }

        iVar1 = FONT_02fc(1);
    } while (iVar1 == 0);

    return iVar1;
}

// OK P1 (NOT MATCHING: driver)
void ULTIMA_10e0_GRAP_51_PutTile(uint tile, int x, int y)
{
    // al = x
    // ah = y
    // bx = tile
    // cx = 52bc, dx = 52be, si = 52c0, di = 52c2
    DRV_51_PutTile(x, y, tile, D_52ba_vdp._52bc, D_52ba_vdp._52be, D_52ba_vdp._52c0, D_52ba_vdp._52c2);
}

void ULTIMA_1112_GRAP_60(int a, int b, int c)
{
    debug("ULTIMA_1112(%d, %d, %d)", a, b, c);
    DRV_60(a, D_5893_map_id, D_52ba_vdp._52bc, D_52ba_vdp._52be, b, c, 1);
}

int ULTIMA_1140_GRAP_6f(void)
{
    return DRV_6f(D_5356);
}

// DUMMY
void ULTIMA_1158_InitTimer(void) { debug("ULTIMA_1158_InitTimer"); }

// NOTE: asm. ret: carry
// NOT MATCHING (asm)
int ULTIMA_1588_IsFileCompressed(char* fileName)
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

int ULTIMA_1674_TestOpenFile(char* file_name)
{
    debug("ULTIMA_1674_test_open_file(%s)", file_name);
    // FMT (dummy)
    return 1;
}

u8 ULTIMA_16a6_GetDefaultDrive(void)
{
    debug("ULTIMA_16a6_GetDefaultDrive");
    // FMT (dummy)
    return 'D';
}

//
// REGION: TEXT
//

void ULTIMA_17f4_ApplyCharEffects(byte* es, int di);

// NOT MATCHING (asm?)
void ULTIMA_16ba_PrintChar(uint ch)
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
            ULTIMA_1f77_ConvertCharCoordToPixel(text_window, &ax, &bx, &cx, &dx);
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
        ULTIMA_17f4_ApplyCharEffects(D_5398_currentCharset, uVar7);

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
        ULTIMA_1f77_ConvertCharCoordToPixel(text_window, &ax, &bx, &cx, &dx);
        text_window->current_y--;
        DRV_27(ax, bx, cx, dx, -8);
    }
}

// NOT MATCHING
// ptr = (es:)di
void ULTIMA_17f4_ApplyCharEffects(byte* es, int di)
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
void ULTIMA_1850_PrintString(char* param_1)
{
    undefined2 local_44;
    char local_42[40];
    uint local_1a;
    int local_18;
    int local_16;
    int local_14;
    TextWindow* local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    // debug("GRAP_PrintString(%s)", param_1);

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
                ULTIMA_16ba_PrintChar(10);
            }

            // 18a7 (NOT MATCHING: si register)
            local_4 = local_6 = local_14 = 0;
            local_10 =
                local_44 - ULTIMA_1f12_GetCurrentTextX(); // remaining_length = text_window_length - column

            for (local_c = 0; param_1[local_8] != '\n' && param_1[local_8] != '\r' && param_1[local_8] != '\0' &&
                              local_c <= local_10;
                 local_8++, local_c++)
            {
                local_42[local_c] = param_1[local_8];
            }

            // 18f4 (after loop)
            if (local_c == 0)
            {
                if (param_1[local_8] != '\0')
                {
                    ULTIMA_16ba_PrintChar((byte)param_1[local_8++]);
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
                    for (; param_1[local_8] != ' ' && local_c != 0 && param_1[local_8] != '\n' &&
                           param_1[local_8] != '\0' && param_1[local_8] != '\r';
                         local_c--, local_8--)
                    {
                    }

                    // 1968
                    if (local_c == 0)
                    {
                        local_c = local_18;
                        local_8 = local_16;

                        if (local_12->current_x != 0)
                        {
                            ULTIMA_16ba_PrintChar(10);
                            local_6 = 1;
                        }
                    }
                    else
                    {
                        // 1996
                        do
                        {
                            local_c--;
                        } while (local_42[local_c] == ' ' || local_42[local_c] == '\r' || local_42[local_c] == '\n');

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
                        ULTIMA_16ba_PrintChar(10);
                    }

                    // 19ea
                    ULTIMA_1bf2_SetTextPosition((local_10 - local_c) / 2, ULTIMA_1cee_GetCurrentTextY());
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
                    ULTIMA_16ba_PrintChar((byte)local_42[local_14]);
                }
            }
        } while (local_a == 0);
    }
    return;
}

// OK P1 (NOT MATCHING: optimization)
// print_integer(val, min_len, filler)
void ULTIMA_1a3e_PrintNumber(int param_1, int param_2, int param_3)
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

    ULTIMA_1850_PrintString(local_28);
}

//
// REGION: KEYBOARD
//

void ULTIMA_1b24_ClearKbdBufferImpl();

// STUB
void ULTIMA_1b16_ClearKbdBuffer(void)
{
    // push ds
    ULTIMA_1b24_ClearKbdBufferImpl();
    // pop ds
}

// asm
// STUB
void ULTIMA_1b24_ClearKbdBufferImpl(void)
{
    // BIOS key buffer
    // DS = 0x40
    // (word)DS:[0x1a] = 0x1e;
    // (word)DS:[0x1c] = 0x1e;

    // *headPtr = 0x1e;
    // *tailPtr = 0x1e;
}

// NOt MATCHING
u16 ULTIMA_1b38_KeystrokeCursor(void)
{
    int local_2;
    int local_4;

    local_2 = D_538e;
    D_538e = 0;
    ULTIMA_16ba_PrintChar(D_5390 + D_540c++); // animate cursor
    local_4 = (u8)ULTIMA_1d5e_PeekKeystroke();
    if (D_5392 <= D_540c) {
        D_540c = 0;
    }
    if (local_4 != 0) {
        ULTIMA_16ba_PrintChar(0x20);
    }
    else {
        ULTIMA_20fa_WaitTicks(1);
    }
    D_538e = local_2;
    return local_4;
}

// NOTE: not matching
void ULTIMA_1b94_SelectTextWindow(int id)
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
void ULTIMA_1bf2_SetTextPosition(int x, int y)
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

byte ULTIMA_1c5b_ClipTextWindow(int* x1, int* y1, int* x2, int* y2);

// NOTE: not matching
void ULTIMA_1c22_SetTextWindowSize(int idx, int x1, int y1, int x2, int y2)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1c22_SetTextWindowSize(%d,%d,%d,%d,%d)", idx, x1, y1, x2, y2);
#endif
    if (idx < 4)
    {
        TextWindow* win = &D_535e_textWindows[idx];
        ULTIMA_1c5b_ClipTextWindow(&x1, &y1, &x2, &y2);
        ASSERT(x1 <= x2);
        ASSERT(y1 <= y2);
        win->left = (u8)x1;
        win->top = (u8)y1;
        win->right = (u8)x2;
        win->bottom = (u8)y2;
    }
}

// NOTE: not matching
byte ULTIMA_1c5b_ClipTextWindow(int* x1, int* y1, int* x2, int* y2)
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

// NOT MATCHING
void ULTIMA_1c9e_SelectCharset(int param_1)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1c9e_set_charset(%d)", a);
#endif

    if (param_1 < 4 && D_539c[param_1] != 0)
    {
        D_5398_currentCharset = D_539c[param_1];
        D_5388_current_charset_idx = param_1;
    }
}

// TODO: NOT MATCHING
void ULTIMA_1cca_SetTextForegroundColor(int a)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1cca_set_text_foreground_color(%d) [%d]", a, D_5386_current_text_window_idx);
#endif

    D_53aa_text_fg_color = a & 0xf;
    D_539a_currentTextWindow->text_colors = (D_539a_currentTextWindow->text_colors & 0xf0) | (a & 0xf);
}

int ULTIMA_1cee_GetCurrentTextY(void) { return D_539a_currentTextWindow->current_y; }

// STUB
int ULTIMA_1d02_LoadCharset(char* a, int b)
{
    debug("ULTIMA_1d02_load_character_set(%s,%d)", a, b);

    D_539c[b] = ULTIMA_0fae_LoadFile(a);

    // FMT
    return 1;
}

// STUB
int ULTIMA_1d5e_PeekKeystroke(void)
{
    return u5_peekch();
}

// STUB
int ULTIMA_1dda_WaitForKeystroke(int a)
{
    debug("ULTIMA_1dda_wait_for_keystroke(%d)", a);
    return (u8)u5_getch();
}

// NOT MATCHING
void ULTIMA_1e38_IntroEnterString(char* param_1, int param_2)
{
    int local_6;
    int local_4;

    local_4 = 0;
    do
    {
        local_6 = ULTIMA_1dda_WaitForKeystroke(0);
        if ((local_6 == 8 || local_6 == 1) && local_4 != 0)
        {
            ULTIMA_1fa0_Backspace(1);
            local_4--;
        }
        else if (local_6 == 0x1b && local_4 != 0)
        {
            ULTIMA_1fa0_Backspace(local_4);
            local_4 = 0;
        }
        else if (local_6 > 0x1f && local_6 < 0x80 && local_4 < param_2)
        {
            param_1[local_4] = local_6;
            local_4++;
            ULTIMA_16ba_PrintChar(local_6);
        }
    } while (local_6 != 0xd);

    param_1[local_4] = 0;
}

// STUB
int ULTIMA_1eac_SetDefaultDrive(int param_1)
{ debug("ULTIMA_1eac_SetDefaultDrive(%c)", param_1); }

int ULTIMA_1f12_GetCurrentTextX(void) { return D_539a_currentTextWindow->current_x; }

// TODO: NOT MATCHING
void ULTIMA_1f26_SetTextBackgroundColor(int a)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1f26_set_text_background_color(%d) [%d]", a, D_5386_current_text_window_idx);
#endif

    D_53ab_text_bg_color = a & 0xf;
    D_539a_currentTextWindow->text_colors = (D_539a_currentTextWindow->text_colors & 0xf) | ((a & 0xf) << 4);
}

// NOT MATCHING
void ULTIMA_1fa0_Backspace(int char_count)
{
    u16 uVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    if ((ULTIMA_1f12_GetCurrentTextX() != 0 || ULTIMA_1cee_GetCurrentTextY() != 0) && char_count != 0)
    {
        uVar1 = D_538e;
        D_538e = 0;

        if (char_count > 0)
        {
            iVar2 = D_535e_textWindows[D_5386_current_text_window_idx].right - D_535e_textWindows[D_5386_current_text_window_idx].left;
            for (iVar5 = 0; iVar5 < char_count; iVar5++)
            {
                iVar3 = ULTIMA_1f12_GetCurrentTextX();
                ULTIMA_16ba_PrintChar(0x20);
                if (iVar3 == 0)
                {
                    iVar3 = iVar2;
                    iVar4 = ULTIMA_1cee_GetCurrentTextY() - 1;
                }
                else
                {
                    iVar3--;
                    iVar4 = ULTIMA_1cee_GetCurrentTextY();
                }

                ULTIMA_1bf2_SetTextPosition(iVar3, iVar4);
            }
        }

        D_538e = uVar1;
    }
}

// param: SI = window
void ULTIMA_1f77_ConvertCharCoordToPixel(TextWindow* window, int* pAX, int* pBX, int* pCX, int* pDX)
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
