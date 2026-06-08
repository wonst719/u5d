#ifndef _COMMON_CONFIG_H
#define _COMMON_CONFIG_H

int CONFIG_GetString(char* section, char* key, char* defaultValue, char* outValue, int size);
int CONFIG_GetInt(char* section, char* key, int defaultValue);

#endif
