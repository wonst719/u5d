#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include "GRAP_DRV.H"

// NOT MATCHING
void FUN_1000_7040(int param_4, int param_3, int param_2, int param_1)
{
    int iVar1;
    char* pcVar2;
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
void FUN_1000_70a6(void)
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
        FUN_1000_7040(0, 1, D_217e, D_2180);
        FUN_1000_7040(1, 1, D_217e, D_2180);
        FUN_1000_7040(2, 1, D_217e, D_2180);
        if (D_2182 == -1)
            goto LAB_1000_719c;
        FUN_1000_7040(0, 1, D_2182, D_2184);
        FUN_1000_7040(1, 1, D_2182, D_2184);
        iVar1 = 2;
    }
    else {
        FUN_1000_7040(D_2186, 0, D_217e, D_2180);
        if (D_2182 != -1)
        {
            FUN_1000_7040(D_2186, 0, D_2182, D_2184);
        }
        D_2186++;
        FUN_1000_7040(D_2186 + 2, 1, D_217e, D_2180);
        if (D_2182 == -1)
            goto LAB_1000_719c;
        iVar1 = D_2186 + 2;
    }
    FUN_1000_7040(iVar1, 1, D_2182, D_2184);
LAB_1000_719c:
    if (0xf < D_2186) {
        D_2186 = 0;
    }
}


// OK P1: driver
void FUN_1000_71aa()
{
    int ax = 2;
    byte bl = D_587f;
    byte bh = D_5881;
    DRV_6c(ax, bl, bh);
}

// NOT MATCHING: driver
void FUN_1000_71ca(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int di;

    FUN_1000_08e6_constraint_imagewindow(&param_1, &param_2, &param_3, &param_4);

    di = param_4 - param_2;
    if (param_5 > di)
    {
        param_5 = di;
    }

    // scroll text window
    DRV_27(param_1, param_2, param_3, param_4, -param_5);
}

// NOT MATCHING: driver
void FUN_1000_7200(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int di;

    FUN_1000_08e6_constraint_imagewindow(&param_1, &param_2, &param_3, &param_4);

    di = param_4 - param_2;
    if (param_5 > di)
    {
        param_5 = di;
    }

    // scroll text window
    DRV_27(param_1, param_2, param_3, param_4, param_5);
}
