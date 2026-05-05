#include "common.h"
#include "funcs.h"
#include "vars.h"

#include "grap_drv.h"

// NOT MATCHING
void ULTIMA_7040(int param_4, int param_3, int param_2, int param_1)
{
    int iVar1;
    u8* pcVar2;
    undefined1 uStack_8;

    uStack_8 = 0;
    if (param_3 == 1)
    {
        uStack_8 = 0xff;
    }
    pcVar2 = &D_1f7e[(param_4 % 0x10) * 0x20];
    iVar1 = 0x10;
    do {
        D_ad14[(pcVar2[1] + param_1) * 0x20 + pcVar2[0] + param_2] = uStack_8;
        pcVar2 += 2;
        iVar1--;
    } while (iVar1 != 0);
    return;
}

// NOT MATCHING
void ULTIMA_70a6(void)
{
    int iVar1;
    undefined2 unaff_DS;

    if ((0x31 < D_58a5) || (D_217e == -1)) {
        D_2186 = 0xff;
        return;
    }
    D_24e6 = 1;
    if (D_2186 == 0xff)
    {
        D_2186++;
        ULTIMA_7040(0, 1, D_217e, D_2180);
        ULTIMA_7040(1, 1, D_217e, D_2180);
        ULTIMA_7040(2, 1, D_217e, D_2180);
        if (D_2182 == -1)
            goto LAB_1000_719c;
        ULTIMA_7040(0, 1, D_2182, D_2184);
        ULTIMA_7040(1, 1, D_2182, D_2184);
        iVar1 = 2;
    }
    else {
        ULTIMA_7040(D_2186, 0, D_217e, D_2180);
        if (D_2182 != -1)
        {
            ULTIMA_7040(D_2186, 0, D_2182, D_2184);
        }
        D_2186++;
        ULTIMA_7040(D_2186 + 2, 1, D_217e, D_2180);
        if (D_2182 == -1)
            goto LAB_1000_719c;
        iVar1 = D_2186 + 2;
    }
    ULTIMA_7040(iVar1, 1, D_2182, D_2184);
LAB_1000_719c:
    if (0xf < D_2186) {
        D_2186 = 0;
    }
}

// OK P1: driver
void ULTIMA_71aa(void)
{
    int ax = 2;
    byte bl = D_587f;
    byte bh = D_5881;
    DRV_6c(ax, bl, bh);
}

// NOT MATCHING: driver
void ULTIMA_71ca_DRV_27_ScrollTextWindow1(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int di;

    ULTIMA_08e6_ClipRectCoord(&param_1, &param_2, &param_3, &param_4);

    di = param_4 - param_2;
    if (param_5 > di)
    {
        param_5 = di;
    }

    // scroll text window
    DRV_27(param_1, param_2, param_3, param_4, -param_5);
}

// NOT MATCHING: driver
void ULTIMA_7200_DRV_27_ScrollTextWindow2(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int di;

    ULTIMA_08e6_ClipRectCoord(&param_1, &param_2, &param_3, &param_4);

    di = param_4 - param_2;
    if (param_5 > di)
    {
        param_5 = di;
    }

    // scroll text window
    DRV_27(param_1, param_2, param_3, param_4, param_5);
}

// ULTIMA:1000 MAX: < ULTIMA_7296
