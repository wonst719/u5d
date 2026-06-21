#include "common/common.h"
#include "vars.h"

#include "translate.h"

char* TRS_GetString(u32 addr, const char* originalText)
{
    return (char*)originalText;
}

static void TRS_PatchTable(char** table, int count)
{
    for (int i = 0; i < count; i++)
    {
        // TODO
    }
}

void TRS_PatchStringTables(void)
{
    TRS_PatchTable(D_17f6, ARRAYSIZE(D_17f6));
}
