#ifndef _COMMON_LZW_H
#define _COMMON_LZW_H

#include <stdio.h>

int LzwDecompressFile(FILE* fi, u8** out, u32* size);

#endif
