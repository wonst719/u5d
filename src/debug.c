#include "COMMON.H"

#include <stdarg.h>
#include <stdio.h>

void CDECL debug(char* str, ...)
{
    char debugBuffer[256];

    va_list args;
    va_start(args, str);

    if (vsprintf(debugBuffer, str, args) < 0)
    {
        debugBuffer[0] = 0;
    }

    va_end(args);

#if defined(TARGET_WINDOWS)
    puts(debugBuffer);
#else
    FILE* fp = fopen("LOG.TXT", "ab");
    fputs(debugBuffer, fp);
    fputc('\n', fp);
    fclose(fp);
#endif
}
