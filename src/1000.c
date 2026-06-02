#include "common/common.h"

#include "funcs.h"
#include "vars.h"

#include "grap_drv.h"

#include "key/key.h"

#include "font.h"
#include "common/lzw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define VERBOSE_LOG

void DRV_66(int ax, int bx, int cx, int dx, int si, int di, int cf);

// STUB (asm)
void ULTIMA_102e_UnloadTileset(void)
{
    debug("ULTIMA_102e_UnloadTileset");
    DRV_5a_FreeTileset();
}

// STUB (asm)
void ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(byte* img, int idx, int x, int y)
{
    //debug("ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(ptr,%d,%d,%d)", idx, x, y);
    // ax = a, bx = idx, si = c, di = d
    DRV_4e(img, idx, x, y);
}

// NOT MATCHING (asm)
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

// OK P1 (NOT MATCHING: asm)
void ULTIMA_10e0_GRAP_51_PutTile(uint tile, int x, int y)
{
    // al = x
    // ah = y
    // bx = tile
    // cx = 52bc, dx = 52be, si = 52c0, di = 52c2
    DRV_51_PutTile(x, y, tile, D_52ba_vdp._52bc, D_52ba_vdp._52be, D_52ba_vdp._52c0, D_52ba_vdp._52c2);
}

// STUB (asm)
void ULTIMA_1112_GRAP_60(int a, int b, int c)
{
    debug("ULTIMA_1112(%d, %d, %d)", a, b, c);
    // (int ax, byte bl, int cx, int dx, int si, int di, int carry)
    // ax
    // bl
    // cx: x offset
    // dx: y offset
    // cf: code path
    DRV_60(a, D_5893_map_id, D_52ba_vdp._52bc, D_52ba_vdp._52be, b, c, 1);
}

// STUB (asm)
int ULTIMA_1140_GRAP_6f(void)
{
    return DRV_6f(D_5356);
}

static void ULTIMA_1184_InitTextWindow(void);
static void ULTIMA_11b4_CalibrateTimer(void);
static void ULTIMA_1226_InitTextVars(void);

// STUB (asm)
void ULTIMA_1158_InitTimer(void)
{
    debug("ULTIMA_1158_InitTimer");

    ULTIMA_1184_InitTextWindow();
    ULTIMA_1226_InitTextVars();
    ULTIMA_11b4_CalibrateTimer();
}

// NOT MATCHING (asm?)
static void ULTIMA_1184_InitTextWindow(void)
{
    int i;
    TextWindow* win;

    D_539a_currentTextWindow = &D_535e_textWindows[0];

    for (i = 0; i < 4; i++)
    {
        win = &D_535e_textWindows[i];

        win->left = 0;
        win->top = 0;
        win->right = 39;
        win->bottom = 24;
        win->current_x = 0;
        win->current_y = 0;
        win->text_colors = 0xf;
        win->text_effects = 0;
    }

    D_5386_current_text_window_idx = 0;
}

// DUMMY (asm)
static void ULTIMA_11b4_CalibrateTimer(void)
{
    debug("ULTIMA_11b4_CalibrateTimer");

    // calibrates D_5356, D_535a
}

// OK P1 (asm?)
static void ULTIMA_1226_InitTextVars(void)
{
    D_53a8_inverse = D_53a6 = D_53a4_underline = 0;
}

static int ULTIMA_1588_IsFileCompressed(char* fileName);

// ASM, STUB
// return: BX
// - CF==0: ok
// - CF==1: fail
void* ULTIMA_125d_LoadResourceFileImpl(char* file_name)
{
    FILE* fp;
    u32 size;
    byte* buf = NULL;

    debug("ULTIMA_125d_ReadFileImpl(%s)", file_name);

    fp = fopen(file_name, "rb");
    if (!fp)
        return NULL;

    if (!ULTIMA_1588_IsFileCompressed(file_name))
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        buf = malloc(size);
        fread(buf, size, 1, fp);
    }
    else
    {
        LzwDecompressFile(fp, &buf, &size);
    }

    fclose(fp);

    return buf;
}

// asm
// ULTIMA_135a_ReadLzwCompressedFile

// NOTE: asm. ret: carry
// NOT MATCHING (asm)
static int ULTIMA_1588_IsFileCompressed(char* fileName)
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

// asm
// ULTIMA_15c6_AllocateMemory
// ULTIMA_160e_ReadFile
// ULTIMA_1649_DosReadFile
// ULTIMA_1654_DosGetFileSize

// STUB (asm)
int ULTIMA_1674_TestOpenFile(char* file_name)
{
    debug("ULTIMA_1674_TestOpenFile(%s)", file_name);

#if !defined(TARGET_DOS16)
    FILE* fp = fopen(file_name, "r");
    if (fp)
    {
        fclose(fp);
        return 1;
    }
    return 0;
#else
    // FMT (dummy)
    return 1;
#endif
}

// DUMMY (asm)
int ULTIMA_16a6_GetDefaultDrive(void)
{
    debug("ULTIMA_16a6_GetDefaultDrive");
    // FMT (dummy)
    return 'D';
}

//
// REGION: TEXT
//

static void ULTIMA_17f4_ApplyCharEffects(byte* es, int di);
static void ULTIMA_1f77_ConvertCharCoordToPixel(TextWindow* window, int* pAX, int* pBX, int* pCX, int* pDX);

// NOT MATCHING (asm)
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

// NOT MATCHING (asm?)
// ptr = (es:)di
static void ULTIMA_17f4_ApplyCharEffects(byte* es, int di)
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

// CHECKED (NOT MATCHING: register, loop optimization)
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

// CHECKED (NOT MATCHING: optimization)
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

static void ULTIMA_1b24_ClearKbdBufferImpl();

// STUB (asm)
void ULTIMA_1b16_ClearKbdBuffer(void)
{
    // push ds
    ULTIMA_1b24_ClearKbdBufferImpl();
    // pop ds
}

// STUB (asm)
static void ULTIMA_1b24_ClearKbdBufferImpl(void)
{
    // BIOS key buffer
    // DS = 0x40
    // (word)DS:[0x1a] = 0x1e;
    // (word)DS:[0x1c] = 0x1e;

    // *headPtr = 0x1e;
    // *tailPtr = 0x1e;
}

// OK P1
u16 ULTIMA_1b38_PollKeyWithCursor(void)
{
    int local_4;
    int local_6;

    local_4 = D_538e;
    D_538e = 0;

    ULTIMA_16ba_PrintChar(D_5390 + D_540c++); // animate cursor

    local_6 = ULTIMA_1d5e_PollKey();
    if ((int)D_540c >= (int)D_5392)
    {
        D_540c = 0;
    }

    if (local_6 != 0)
    {
        ULTIMA_16ba_PrintChar(0x20);
    }
    else
    {
        ULTIMA_20fa_WaitTicks(1);
    }

    D_538e = local_4;
    return local_6;
}

// NOT MATCHING (asm)
void ULTIMA_1b94_SelectTextWindow(int id)
{
    register int b;

#ifdef VERBOSE_LOG
    debug("ULTIMA_1b94_SelectTextWindow(%d)", id);
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

// NOT MATCHING (asm)
void ULTIMA_1bf2_SetTextPosition(int x, int y)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1bf2_SetTextPosition(%d,%d)", x, y);
#endif

    if ((byte)x + D_539a_currentTextWindow->left < 40 && (byte)y + D_539a_currentTextWindow->top < 25)
    {
        D_539a_currentTextWindow->current_x = x;
        D_539a_currentTextWindow->current_y = y;
    }
}

static byte ULTIMA_1c5b_ClipTextWindow(int* x1, int* y1, int* x2, int* y2);

// NOT MATCHING (asm)
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

// NOT MATCHING (asm)
static byte ULTIMA_1c5b_ClipTextWindow(int* x1, int* y1, int* x2, int* y2)
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

// NOT MATCHING (asm?)
void ULTIMA_1c9e_SelectCharset(int param_1)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1c9e_SelectCharset(%d)", a);
#endif

    if (param_1 < 4 && D_539c[param_1] != 0)
    {
        D_5398_currentCharset = D_539c[param_1];
        D_5388_current_charset_idx = param_1;
    }
}

// NOT MATCHING (asm?)
void ULTIMA_1cca_SetTextForegroundColor(int a)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1cca_SetTextForegroundColor(%d) [%d]", a, D_5386_current_text_window_idx);
#endif

    D_53aa_text_fg_color = a & 0xf;
    D_539a_currentTextWindow->text_colors = (D_539a_currentTextWindow->text_colors & 0xf0) | (a & 0xf);
}

// NOT MATCHING (asm?)
int ULTIMA_1cee_GetCurrentTextY(void) { return D_539a_currentTextWindow->current_y; }

// STUB (asm)
int ULTIMA_1d02_LoadCharset(char* a, int b)
{
    debug("ULTIMA_1d02_LoadCharset(%s,%d)", a, b);

    D_539c[b] = ULTIMA_0fae_LoadResourceFile(a);

    // FMT
    return 1;
}

// STUB
int ULTIMA_1d5e_PollKey(void)
{
    return KEY_PollKey();
}

// OK P1
int ULTIMA_1dda_WaitForKeystroke(int param_1)
{
    int local_8;
    int local_6;
    int local_4;

    local_4 = -1;
    if (param_1 != 0)
    {
        local_4++;
    }

    if (param_1 > 1)
    {
        local_6 = D_5356;
        D_5356 = 500;
    }

    do
    {
        local_8 = ULTIMA_1b38_PollKeyWithCursor();
        if (param_1 != 0)
        {
            local_4++;
        }
    } while (local_4 < param_1 && local_8 == 0);

    if (param_1 > 1)
    {
        D_5356 = local_6;
    }

    return local_8;
}

// OK P1
void ULTIMA_1e38_IntroGetString(char* param_1, int param_2)
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

// CHECKED (asm)
static int ULTIMA_1ef7_ConvertDriveLetterToNumber(char* al, char* dl);

// STUB (asm)
int ULTIMA_1eac_SetDefaultDrive(int param_1)
{
    char al = param_1;
    char dl;

    debug("ULTIMA_1eac_SetDefaultDrive(%d)", param_1);

    D_535c = 0;

    if (ULTIMA_1ef7_ConvertDriveLetterToNumber(&al, &dl) == 0)
    {
        D_541e = dl;

        // int 21,0e; // Select Disk
        //if (D_535c == 0) // success
        //{
        //    // int 21,19; // Get Current Default Drive
        //    if (D_541e == ret)
        //    {
        //        D_535c = 0;
        //        return 1;
        //    }
        //}
        //
        //return 0;

        // STUB
        return 1;
    }

    D_535c = 1;
    D_5394_fn();

    return 1;
}

// CHECKED (asm)
static int ULTIMA_1ef7_ConvertDriveLetterToNumber(char* al, char* dl)
{
    if ('a' <= *al && *al <= 'z')
    {
        *al -= 0x20; // to upper
    }

    *dl = *al - 'A';
    if ('A' <= *al && *al <= 'Z')
    {
        return 0;
    }

    return 1;
}

// NOT MATCHING (asm)
int ULTIMA_1f12_GetCurrentTextX(void) { return D_539a_currentTextWindow->current_x; }

// NOT MATCHING (asm)
void ULTIMA_1f26_SetTextBackgroundColor(int a)
{
#ifdef VERBOSE_LOG
    debug("ULTIMA_1f26_SetTextBackgroundColor(%d) [%d]", a, D_5386_current_text_window_idx);
#endif

    D_53ab_text_bg_color = a & 0xf;
    D_539a_currentTextWindow->text_colors = (D_539a_currentTextWindow->text_colors & 0xf) | ((a & 0xf) << 4);
}

// DUMMY (asm)
static void ULTIMA_1f4e(int param_1)
{
    // call ULTIMA_1f77_ConvertCharCoordToPixel
    // far call DRV_27(-(param_1 * 8)
}

// ASM
// param: SI = window
static void ULTIMA_1f77_ConvertCharCoordToPixel(TextWindow* window, int* pAX, int* pBX, int* pCX, int* pDX)
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

// OK P1
void ULTIMA_1fa0_Backspace(int char_count)
{
    u16 local_4;
    TextWindow* local_6;
    int local_8;
    int local_a;

    if ((ULTIMA_1f12_GetCurrentTextX() != 0 || ULTIMA_1cee_GetCurrentTextY() != 0) && char_count != 0)
    {
        local_4 = D_538e;
        local_6 = &D_535e_textWindows[D_5386_current_text_window_idx];
        D_538e = 0;

        for (local_8 = 0; local_8 < char_count; local_8++)
        {
            local_a = ULTIMA_1f12_GetCurrentTextX();
            ULTIMA_16ba_PrintChar(0x20);
            if (local_a != 0)
            {
                ULTIMA_1bf2_SetTextPosition(local_a - 1, ULTIMA_1cee_GetCurrentTextY());
            }
            else
            {
                ULTIMA_1bf2_SetTextPosition(local_6->right - local_6->left, ULTIMA_1cee_GetCurrentTextY() - 1);
            }
        }

        D_538e = local_4;
    }
}
