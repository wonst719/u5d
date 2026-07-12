#ifndef _COMMON_SETTINGS_H
#define _COMMON_SETTINGS_H

int SETTINGS_GetString(char* section, char* key, char* defaultValue, char* outValue, int size);
int SETTINGS_GetInt(char* section, char* key, int defaultValue);

#endif
