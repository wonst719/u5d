#pragma once

int CONFIG_GetString(char* section, char* key, char* defaultValue, char* outValue, int size);
int CONFIG_GetInt(char* section, char* key, int defaultValue);
