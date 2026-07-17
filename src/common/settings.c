#include "common.h"
#include "settings.h"

#include <stdio.h>

// TODO

#if defined(OS_WINDOWS)

// TODO: clean up
#undef ARRAYSIZE
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int SETTINGS_GetString(char* section, char* key, char* defaultValue, char* outValue, int size)
{
    char fileName[] = ".\\ultima5.ini";

    return GetPrivateProfileStringA(section, key, defaultValue, outValue, size, fileName);
}

#else

#include <errno.h>
#include <string.h>

int SETTINGS_GetString(char* section, char* key, char* defaultValue, char* outValue, int size)
{
    if (defaultValue == NULL)
        defaultValue = "";

    strncpy(outValue, defaultValue, size - 1);
    return 0;
}

#endif

int SETTINGS_GetInt(char* section, char* key, int defaultValue)
{
    char outValue[256] = { 0, };
    SETTINGS_GetString(section, key, "", outValue, 255);

    int val = strtol(outValue, NULL, 10);
    if (errno != 0)
    {
        return defaultValue;
    }

    return val;
}
