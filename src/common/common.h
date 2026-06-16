#ifndef _COMMON_COMMON_H
#define _COMMON_COMMON_H

#undef bool

#include "platform.h"

#include <stdlib.h>

#if !defined(TARGET_DOS16)

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef uint8_t byte;
typedef uint16_t word;
typedef uint16_t uint;

typedef byte undefined;
typedef byte undefined1;
typedef int16_t undefined2;

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

#define true 1
#define false 0

#define const

#endif

#if defined(COMPILER_MSVC)

#define CHECK_PARAM_RANGE(v, inclusive_min, exclusive_max)                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((v) < (inclusive_min) || (v) >= (exclusive_max))                                                           \
            __debugbreak();                                                                                            \
    } while (0)

// TODO: message
#define ASSERT(x)                                                                                                      \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(x))                                                                                                      \
            __debugbreak();                                                                                            \
    } while (0)

// use with caution
#define SET_UNINITIALIZED_8(x) (x) = 0xdd

#define CHECK_UNINITIALIZED_8(x)                                                                                       \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((x) == 0xdd)                                                                                               \
            __debugbreak();                                                                                            \
    } while (0)

#define SET_UNINITIALIZED_16(x) (x) = 0xdead

#define CHECK_UNINITIALIZED_16(x)                                                                                      \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((x) == 0xdead)                                                                                             \
            __debugbreak();                                                                                            \
    } while (0)

#elif !defined(TARGET_DOS16)

// TODO

#define CHECK_PARAM_RANGE(v, inclusive_min, exclusive_max)                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((v) < (inclusive_min) || (v) >= (exclusive_max))                                                           \
            *((u32*)0) = 1;                                                                                            \
    } while (0)

// TODO: message
#define ASSERT(x)                                                                                                      \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(x))                                                                                                      \
            *((u32*)0) = 1;                                                                                            \
    } while (0)

// use with caution
#define SET_UNINITIALIZED_8(x) (x) = 0xdd

#define CHECK_UNINITIALIZED_8(x)                                                                                       \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((x) == 0xdd)                                                                                               \
            *((u32*)0) = 1;                                                                                            \
    } while (0)

#define SET_UNINITIALIZED_16(x) (x) = 0xdead

#define CHECK_UNINITIALIZED_16(x)                                                                                      \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((x) == 0xdead)                                                                                             \
            *((u32*)0) = 1;                                                                                            \
    } while (0)

#else

#define CHECK_PARAM_RANGE(v, inclusive_min, exclusive_max)
#define ASSERT(x)
#define SET_UNINITIALIZED_8(x)
#define CHECK_UNINITIALIZED_8(x)
#define SET_UNINITIALIZED_16(x)
#define CHECK_UNINITIALIZED_16(x)

#endif

extern void CDECL debug(char* str, ...);

#if defined(TARGET_SDL)
#define ENABLE_GRAP_OVERLAY 1
#define ENABLE_GRAP_OVERLAY_DEBUG 1
#endif

#if defined(COMPILER_MSVC)
#define u5_itoa _itoa
#else
#define u5_itoa itoa
#endif

#define ARRAYSIZE(array) ((int)(sizeof(array) / sizeof((array)[0])))

#endif
