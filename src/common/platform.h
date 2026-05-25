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
// CPU Architecture
//
#if defined(_M_X64) || defined(__x86_64__)
#define ARCH_X86_64 1
#elif defined(_M_IX86) || defined(__i386__) || defined(i386)
#define ARCH_X86_32 1
#elif defined(__aarch64__) || defined(_M_ARM64)
#define ARCH_ARM64 1
#elif defined(__arm__) || defined(_M_ARM)
#define ARCH_ARM32 1
#else
#define ARCH_UNKNOWN 1
#endif

//
// Bitness
//
#if defined(ARCH_X86_64) || defined(ARCH_ARM64)
#define ARCH_64BIT 1
#elif defined(ARCH_X86_32) || defined(ARCH_ARM32)
#define ARCH_32BIT 1
#elif defined(OS_DOS16)
#define ARCH_16BIT 1
#endif

//
// Target profiles
//
#if defined(COMPILER_MSVC) && defined(OS_WINDOWS)
#define TARGET_WINDOWS 1
#elif defined(COMPILER_GCC) && defined(__DJGPP__)
#define TARGET_DOS32 1
#elif defined(OS_DOS16)
#define TARGET_DOS16 1
#endif

// TODO: move out of this file
//
// Build Configurations
//
// Matching build configuration (IBM 1.16 720 KB release)
//#define MATCHING_BUILD 1

// Approximates the behavior of the binary-patched GOG release
//#define GOG_BUILD 1

#if defined(TARGET_DOS16)
#define MATCHING_BUILD 1
//#define GOG_BUILD 1
#else
//#define MATCHING_BUILD 1
#define GOG_BUILD 1
#endif

#if defined(TARGET_DOS16)
#define CDECL cdecl
#define FAR far
#else
#define CDECL
#define FAR
#endif

#if defined(COMPILER_MSVC)
#define _CRT_SECURE_NO_WARNINGS
#endif

#endif
