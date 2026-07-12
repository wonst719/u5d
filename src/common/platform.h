#ifndef _COMMON_PLATFORM_H
#define _COMMON_PLATFORM_H

//
// Compiler
//
#if defined(_MSC_VER)
#define COMPILER_MSVC 1
#elif defined(__GNUC__)
#define COMPILER_GCC 1
#else
#define COMPILER_UNKNOWN 1
#endif

//
// OS / Environment
//
#if defined(_WIN32) || defined(_WIN64)
// Windows
#define OS_WINDOWS 1
#elif defined(__DJGPP__)
// Protected mode DOS
#define OS_DOS32 1
#elif defined(MSDOS) && defined(M_I86) // MSC 5.x
// Real mode DOS
#define OS_DOS16 1
#elif defined(__linux__)
// Linux
#define OS_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
// Mac
#define OS_MACOS 1
#else
#define OS_UNKNOWN 1
#endif

//
// Target profiles
//
#if defined(OS_WINDOWS) || defined(OS_MACOS) || defined(OS_LINUX)
#define TARGET_SDL 1
#elif defined(OS_DOS32)
#define TARGET_DOS32 1
#elif defined(OS_DOS16)
#define TARGET_DOS16 1
#endif

#endif
