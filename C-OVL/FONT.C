#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

// NOT MATCHING
// param_1: image, param_2: text
void F_FONT_0000(byte* param_1, char* param_2)
{
    char cVar1;
    int iVar2;
    int iVar3;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_4;

    FUN_1000_0c22_GRAP_0f_select_page(1);
    if (D_5150 < D_5158 && D_5158 < D_5152)
    {
        iVar2 = 1;
    }
    else
    {
        iVar2 = 0;
    }

    local_c = D_514c[iVar2] - D_5146[iVar2];
    local_e = 0;
    local_4 = D_5156 - D_5146[iVar2];
    while (1)
    {
        if (param_2[local_e] == '\0')
        {
            FUN_1000_0c22_GRAP_0f_select_page(0);
            return;
        }

        local_a = 0;
        for (iVar2 = local_e; param_2[iVar2] != '\0' && local_4 < local_c && param_2[iVar2] != '\n'; iVar2++)
        {
            if (param_2[iVar2] < 0x21)
            {
                local_4 += D_5154;
                local_a += 1;
            }
            else if (param_2[iVar2] == '{')
            {
                local_4 += 0xf;
            }
            else if (param_2[iVar2] != '_')
            {
                local_4 += D_50eb[param_2[iVar2] - 0x21] + 1;
            }
        }

        while (1)
        {
            if ((param_2[iVar2] == '\0' && local_4 < local_c) || param_2[iVar2] == '\n' || --iVar2 <= local_e)
                break;

            if (param_2[iVar2] == ' ')
            {
                local_4 -= D_5154;
                local_a--;
                break;
            }

            if (param_2[iVar2] == '_' && (uint)D_50f7 + local_4 + 1 < local_c)
            {
                local_4 += D_50f7 + 1;
                break;
            }

            if (param_2[iVar2] != '_' && param_2[iVar2] != '{')
            {
                local_4 -= D_50eb[param_2[iVar2] - 0x21] + 1;
            }
        }

        local_8 = local_c - local_4;
        for (; local_e < iVar2; local_e++)
        {
            cVar1 = param_2[iVar2];
            if (param_2[local_e] < 0x21)
            {
                D_5156 += D_5154;
                if (local_a != 0 && cVar1 != '\0' && cVar1 != '\n')
                {
                    D_5156 += local_8 / local_a;
                    local_8 -= local_8 / local_a;
                    local_a--;
                }
            }
            else if (param_2[local_e] == '{')
            {
                D_5156 += 0xf;
            }
            else if (param_2[local_e] != '_')
            {
                if (D_5158 < 0xc0)
                {
                    // NOTE: "or" mix
                    FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(param_1, param_2[local_e] - 0x20, D_5156, D_5158);
                }
                D_5156 += D_50eb[param_2[local_e] - 0x21] + 1;
            }
        }

        local_e = iVar2;
        if (param_2[iVar2] != '\0')
        {
            if (param_2[iVar2] == '_' && D_5158 < 0xc0)
            {
                FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(param_1, 0xd, D_5156, D_5158);
            }

            local_4 = 0;
            D_5158 += 9;
            if (D_5150 < D_5158 && D_5158 < D_5152)
            {
                iVar3 = 1;
            }
            else
            {
                iVar3 = 0;
            }

            D_5156 = D_5146[iVar3];
            local_c = D_514c[iVar3] - D_5156;
            local_e = iVar2 + 1;
        }
    }
}

void F_FONT_0b0a(void) { puts("F_FONT_0b0a"); }

void F_FONT_04a4(void) { puts("F_FONT_04a4"); }
