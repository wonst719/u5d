#include "common.h"

#if !defined(TARGET_DOS16)

#include <stdio.h>

char* u5_itoa(int value, char* buffer, int radix)
{
    ASSERT(radix == 10);
    sprintf(buffer, "%d", value);
    return buffer;
}

#endif
