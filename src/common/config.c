#include "common.h"
#include "config.h"

#include <stdio.h>

// TODO

#if defined(OS_WINDOWS)

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int CONFIG_GetString(char* section, char* key, char* defaultValue, char* outValue, int size)
{
    char fileName[] = ".\\ultima5.ini";

    return GetPrivateProfileStringA(section, key, defaultValue, outValue, size, fileName);
}

#else

int CONFIG_GetString(char* section, char* key, char* defaultValue, char* outValue, int size)
{
    if (defaultValue == NULL)
        defaultValue = "";

    strncpy(outValue, defaultValue, size - 1);
    return 0;
}

#endif

int CONFIG_GetInt(char* section, char* key, int defaultValue)
{
    char outValue[256] = { 0, };
    CONFIG_GetString(section, key, "", outValue, 255);

    int val = strtol(outValue, NULL, 10);
    if (errno != 0)
    {
        return defaultValue;
    }

    return val;
}
