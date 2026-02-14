#ifndef _COMMON_H
#define _COMMON_H

#ifdef _WIN32

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned short uint;
typedef int bool;

typedef byte undefined;
typedef byte undefined1;
typedef short undefined2;

#define CHECK_PARAM_RANGE(v, inclusive_min, exclusive_max)                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((v) < (inclusive_min) || (v) >= (exclusive_max))                                                           \
            __debugbreak();                                                                                            \
    } while (0)

// TODO: message
#define ASSERT(x, message) \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(x)) \
        { \
            __debugbreak(); \
        } \
    } while (0)

#else

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed int s16;
typedef signed long s32;

typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned int uint;
typedef int bool;

typedef byte undefined;
typedef byte undefined1;
typedef int undefined2;

#define CHECK_PARAM_RANGE(v, inclusive_min, exclusive_max)
#define ASSERT(x, message)

#endif

#define TRUE 1
#define FALSE 0

#ifdef _WIN32
#define cdecl
#define far
#define _CRT_SECURE_NO_WARNINGS
#endif

#endif
