#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#define curr_text_win DAT_0003dd8c_current_text_window
#define textWindows ((TextWindow*)&DAT_0003dd6e_TextWindow0_left)
#define currentTextWindow textWindows[curr_text_win]

typedef struct EGB_PutBitmap_Param
{
    byte* _14;  // buffer_address
    u16 _10;    // DS
    s16 _e;     // x1
    s16 _c;     // y1
    s16 _a;     // x2
    s16 _8;     // y2
} EGB_PutBitmap_Param;

void cdecl GRAP_FMT_PrintChar(int ch)
{
    int iVar1;
    undefined4 *puVar2;
    undefined4 *puVar3;
    byte bVar4;
    EGB_PutBitmap_Param local_14;

    currentTextWindow.current_x;
    
    FUN_00032a8a(&DAT_000572cc,0,0xd);

    if (ch < 0x20)
    {
        switch(ch)
        {
        case 8:
            if (DAT_0005bde2 != 1)
            {
                GRAP_FMT_PrintChar(0x20);
                currentTextWindow.current_x -= 2;
                if (currentTextWindow.current_x < (byte)currentTextWindow.left) {
                    currentTextWindow.current_x = currentTextWindow.left;
                }
                GRAP_FMT_PrintChar(0x20);
                currentTextWindow.current_x--;
                if (currentTextWindow.current_x < (byte)currentTextWindow.left) {
                    currentTextWindow.current_x = currentTextWindow.left;
                }
                return;
            }
        default:
            if (ch == 0) {
                return;
            }
        }
    }
    // 27307
    if (ch == 0xfd)
    {
        DAT_0005ff64 = DAT_0005ff64 == '\0';
        currentTextWindow.text_effects? ^= 1;
    }
    else if (ch == 0xff)
    {
        FUN_000277c0_set_text_cursor_position(0,0);
    }
    else if ((ch == 0xfc) && (DAT_00055888 == 1))
    {
        currentTextWindow.text_effects? ^= 2;
    }
    else
    {
        if (ch == 10)   // line break
        {
            if ((currentTextWindow.current_x < currentTextWindow.right) && (DAT_00056144 != 1))
            {
                GRAP_FMT_PrintChar(0x20);
            }

            currentTextWindow.current_x = currentTextWindow.left;
            currentTextWindow.current_y++;
            if (currentTextWindow.current_y < currentTextWindow.bottom) {
                return;
            }
            if (DAT_0005bde0 != 0) {
                return;
            }
            currentTextWindow.current_y = currentTextWindow.bottom - 1;
        }
        else
        {
            // japanese
            if (((0x80 <= ch) && (ch < 0x84)) && (currentTextWindow.current_x < 8))
            {
                return;
            }

            if ((ch != 10) && (ch < 0x87))
            {
                if (DAT_0005ff64 == '\0') {
                    local_14._14 = &DAT_00041d28 + ch * 0x20;
                }
                else {
                    puVar2 = &DAT_00041d28 + ch * 0x20;
                    puVar3 = &DAT_0005feb4;
                    for (iVar1 = 0x20; iVar1 != 0; iVar1--) {
                        *puVar3 = *puVar2;
                        puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
                        puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
                    }
                    for (iVar1 = 0; iVar1 < 0x20; iVar1++) {
                        (&DAT_0005feb4)[iVar1] = ~(&DAT_0005feb4)[iVar1];
                    }
                    local_14._14 = &DAT_0005feb4;
                }
                local_14._10 = 20;
                local_14._e = (ushort)currentTextWindow.current_x * 16;
                local_14._c = (short)(DAT_0005fdf0 * 16) + (ushort)currentTextWindow.current_y * 16 + 0x40;
                local_14._a = (ushort)currentTextWindow.current_x * 16 + 15;
                local_14._8 = (short)(DAT_0005fdf0 * 16) + (ushort)currentTextWindow.current_y * 16 + 0x4f;
                FUN_00032e40_EGB_PutBitmap(&DAT_000572cc,0,&local_14);
            }

            // skip japanese character
            if ((0x80 <= ch) && (ch < 0x84))
            {
                return;
            }

            if (ch > 0x86)
            {
                return;
            }

            currentTextWindow.current_x++;
            if ((byte)currentTextWindow.right < currentTextWindow.current_x) {
                currentTextWindow.current_x = currentTextWindow.left;
                currentTextWindow.current_y++;
            }
            if (currentTextWindow.current_y < (byte)currentTextWindow.bottom ) {
                return;
            }
            if (DAT_0005bde0 != 0) {
                return;
            }
            currentTextWindow.current_y = currentTextWindow.bottom - 1;
            currentTextWindow.current_x = currentTextWindow.left;
            if (currentTextWindow.current_y < 21) {
                return;
            }
            if ((byte)currentTextWindow.left < 21) {
                return;
            }
        }
        FUN_000276d0();
    }
    return;
}

void cdecl FUN_00023c18_print_string(char *ch)
{
    char cVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    char *pcVar5;
    byte *pbVar6;
    bool bVar7;
    byte bVar8;
    byte local_44 [40];
    uint local_1c;
    int local_18;
    int local_14;
    int local_10;
    int local_c;
    uint local_8;
    
    bVar8 = 0;
    iVar4 = 0;
    local_18 = 0;
    if (*ch != '\0') {
        iVar3 = DAT_0003dd8c_current_text_window? * 8;
        local_10 = (uint)(byte)(&DAT_0003dd6e_TextWindow0_right)[iVar3] - (uint)(byte)(&DAT_0003dd6c_TextWindow0_left)[iVar3];
        iVar2 = FUN_00027ba4();
        local_c = (local_10 - iVar2) + 1;
        local_8 = (uint)((&DAT_0003dd73_TextWindow0_text_effects?)[iVar3] & 2);
        bVar7 = local_8 == 0;
        if (!bVar7) {
            iVar2 = -1;
            iVar3 = -1;
            pcVar5 = ch;
            do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar5 == '\0';
                pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
            } while (!bVar7);
            if (bVar7) {
                iVar2 = -1 - (iVar3 + 1);
            }
            local_1c = (uint)(local_c - iVar2) >> 1;
            iVar3 = FUN_00027bbc();
            FUN_000277c0_set_text_cursor_position(local_1c,iVar3);
        }
        do {
            iVar3 = 0;
            iVar2 = FUN_00027ba4();
            local_c = (local_10 - iVar2) + 1;
            pbVar6 = local_44;
            for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
                pbVar6[0] = 0;
                pbVar6[1] = 0;
                pbVar6[2] = 0;
                pbVar6[3] = 0;
                pbVar6 = pbVar6 + ((uint)bVar8 * -2 + 1) * 4;
            }
            for (; (((cVar1 = ch[iVar4], cVar1 != '\n' && (cVar1 != '\r')) && (cVar1 != '\0 '))
                   && (cVar1 != ' ')); iVar4 = iVar4 + 1) {
                local_44[iVar3] = ch[iVar4];
                iVar3 = iVar3 + 1;
            }
            if (iVar3 == 0) {
                if (ch[iVar4] == '\0') {
                    local_18 = 1;
                }
                else if (ch[iVar4] == '\n') {
                    FUN_000271ec();
                    iVar4 = iVar4 + 1;
                }
                else {
                    FUN_00027230_print_char((uint)(byte)ch[iVar4]);
                    iVar4 = iVar4 + 1;
                }
            }
            else {
                if (local_c < iVar3) {
                    FUN_000271ec();
                }
                for (local_14 = 0; local_14 < iVar3; local_14 = local_14 + 1) {
                    FUN_00027230_print_char((uint)local_44[local_14]);
                }
            }
        } while (local_18 == 0);
    }
    return;
}
