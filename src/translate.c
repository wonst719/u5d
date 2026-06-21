#include "common/common.h"
#include "vars.h"

#if defined(ENABLE_TRANSLATION)

#include "translate.h"

#include <string.h>

char* TRS_GetString(u32 addr, const char* originalText)
{
    return (char*)originalText;
}

static void TRS_PatchTable(char** table, int count)
{
    //debug("Count: %d", count);
    for (int i = 0; i < count; i++)
    {
        if (table[i] == 0)
            continue;

        char* text = table[i];

        //debug("- %s", text);

        char* end;
        int addr = strtol(text, &end, 16);
        ASSERT((int)(end - text) == 6);

        char* originalText = end;
        if (*originalText == '|')
            originalText++;

        table[i] = TRS_GetString(addr, originalText);
    }
}

void TRS_Initialize(void)
{
    TRS_PatchTable(D_17f6, ARRAYSIZE(D_17f6));
    TRS_PatchTable(D_1856, ARRAYSIZE(D_1856));
    TRS_PatchTable(D_18b6, ARRAYSIZE(D_18b6));
    TRS_PatchTable(D_1916, ARRAYSIZE(D_1916));
    TRS_PatchTable(D_1962, ARRAYSIZE(D_1962));
    TRS_PatchTable(D_19d2, ARRAYSIZE(D_19d2));
    TRS_PatchTable(D_19e2, ARRAYSIZE(D_19e2));
    TRS_PatchTable(D_1a44, ARRAYSIZE(D_1a44));
    TRS_PatchTable(D_1a6a, ARRAYSIZE(D_1a6a));
    TRS_PatchTable(D_1bfc, ARRAYSIZE(D_1bfc));
    TRS_PatchTable(D_1c30, ARRAYSIZE(D_1c30));
    TRS_PatchTable(D_1e3a, ARRAYSIZE(D_1e3a));
    TRS_PatchTable(D_1f4e, ARRAYSIZE(D_1f4e));
    TRS_PatchTable(D_1f5e, ARRAYSIZE(D_1f5e));
    TRS_PatchTable((char**)D_21ca, 8 * 16);
    TRS_PatchTable((char**)D_22ca, 8 * 16);
    TRS_PatchTable(D_24ea, ARRAYSIZE(D_24ea));
    //TRS_PatchTable(D_25ea, ARRAYSIZE(D_25ea));
    //TRS_PatchTable(D_2652, ARRAYSIZE(D_2652));
    TRS_PatchTable(D_27dc, ARRAYSIZE(D_27dc));
    TRS_PatchTable(D_2e10, ARRAYSIZE(D_2e10));
    TRS_PatchTable(D_3666, ARRAYSIZE(D_3666));
    TRS_PatchTable(D_3810, ARRAYSIZE(D_3810));
    TRS_PatchTable(D_3c20, ARRAYSIZE(D_3c20));
    TRS_PatchTable(D_3ca6, ARRAYSIZE(D_3ca6));
    TRS_PatchTable(D_3cae, ARRAYSIZE(D_3cae));
    TRS_PatchTable(D_3cb6, ARRAYSIZE(D_3cb6));
    TRS_PatchTable(D_3cce, ARRAYSIZE(D_3cce));
    TRS_PatchTable(D_3d2e, ARRAYSIZE(D_3d2e));
    TRS_PatchTable(D_3d36, ARRAYSIZE(D_3d36));
    TRS_PatchTable(D_3d3e, ARRAYSIZE(D_3d3e));
    TRS_PatchTable(D_3d46, ARRAYSIZE(D_3d46));
    TRS_PatchTable(D_3d4a, ARRAYSIZE(D_3d4a));
    TRS_PatchTable(D_3d52, ARRAYSIZE(D_3d52));

    D_3d5a = TRS_GetString(0x3d5a, D_3d5a);

    TRS_PatchTable(D_3e0c, ARRAYSIZE(D_3e0c));
    TRS_PatchTable(D_3e32, ARRAYSIZE(D_3e32));
    TRS_PatchTable(D_3e42, ARRAYSIZE(D_3e42));
    TRS_PatchTable(D_3e72, ARRAYSIZE(D_3e72));
    TRS_PatchTable(D_419c, ARRAYSIZE(D_419c));
    TRS_PatchTable(D_41ac, ARRAYSIZE(D_41ac));
    TRS_PatchTable(D_444a, ARRAYSIZE(D_444a));
    TRS_PatchTable(D_4502, ARRAYSIZE(D_4502));
    //TRS_PatchTable(D_4aa0, ARRAYSIZE(D_4aa0));
    TRS_PatchTable(D_4aa8, ARRAYSIZE(D_4aa8));
    TRS_PatchTable(D_4b3e, ARRAYSIZE(D_4b3e));
    TRS_PatchTable(D_4c74, ARRAYSIZE(D_4c74));
    TRS_PatchTable(D_4ca8, ARRAYSIZE(D_4ca8));
    TRS_PatchTable(D_4cf6, ARRAYSIZE(D_4cf6));
    TRS_PatchTable(D_515c, ARRAYSIZE(D_515c));
}

#endif
