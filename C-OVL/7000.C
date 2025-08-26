#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include "GRAP_DRV.H"

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
