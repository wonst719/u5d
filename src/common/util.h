#ifndef _COMMON_UTIL_H
#define _COMMON_UTIL_H

#if defined(TARGET_DOS16)
#define u5_itoa itoa
#else
extern char* u5_itoa(int value, char* buffer, int radix);
#endif

#endif
