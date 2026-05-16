#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include "grap_drv.h"
#include "common/file.h"

// OK P1
static void ULTIMA_7040(int param_1, int param_2, int param_3, int param_4)
{
    int local_6;
    PairS8* local_4;
    undefined1 local_8;

    local_8 = 0;
    if (param_2 == 1)
    {
        local_8 = 0xff;
    }

    param_1 = (param_1 % 0x10);
    local_4 = &D_1f7e[param_1 * 0x10];

    for (local_6 = 0; local_6 < 0x10; local_6++)
    {
        D_ad14[(local_4->_1 + param_4) * 0x20 + local_4->_0 + param_3] = local_8;
        local_4++;
    }
}

// OK P1
void ULTIMA_70a6(void)
{
    if (D_58a5 >= 0x32 || D_217e == -1)
    {
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

        if (D_2182 != -1)
        {
            ULTIMA_7040(0, 1, D_2182, D_2184);
            ULTIMA_7040(1, 1, D_2182, D_2184);
            ULTIMA_7040(2, 1, D_2182, D_2184);
        }
    }
    else
    {
        ULTIMA_7040(D_2186, 0, D_217e, D_2180);

        if (D_2182 != -1)
        {
            ULTIMA_7040(D_2186, 0, D_2182, D_2184);
        }

        D_2186++;
        ULTIMA_7040(D_2186 + 2, 1, D_217e, D_2180);

        if (D_2182 != -1)
        {
            ULTIMA_7040(D_2186 + 2, 1, D_2182, D_2184);
        }
    }

    if (D_2186 > 0xf)
    {
        D_2186 = 0;
    }
}

// NOT MATCHING: driver
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

// STUB
int ULTIMA_7234_ReadFile(char* fileName, void* addr, u16 size, u16 offset)
{
    D_535c = 0;
    if (FILE_ReadFile(fileName, addr, size, offset) != 0)
    {
        D_535c = 1;
        D_5394_fn();

        return 0;
    }

    return 1;
}

// STUB
int ULTIMA_7296_WriteFile(char* fileName, void* addr, u16 size)
{
    D_535c = 0;
    if (FILE_WriteFile(fileName, addr, size, 0) != 0)
    {
        D_535c = 1;
        D_5394_fn();

        return 0;
    }

    return 1;
}

// ULTIMA:1000 MAX: < ULTIMA_7296
