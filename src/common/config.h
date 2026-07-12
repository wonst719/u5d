#ifndef _COMMON_CONFIG_H
#define _COMMON_CONFIG_H

//
// Build Configurations
//
// Matching build configuration (IBM 1.16 720 KB release)
//#define MATCHING_BUILD 1

// Approximates the behavior of the binary-patched GOG release
//#define GOG_BUILD 1

// Enable BGM
//#define ENABLE_BGM 1

// Enable speed fixes for modern build
//#define ENABLE_SPEED_FIX 1

// Enable bug fixes
//#define ENABLE_BUG_FIX 1

#if defined(TARGET_DOS16)
#define MATCHING_BUILD 1
#else
#define GOG_BUILD 1
#endif

#if !defined(TARGET_DOS16)
#define ENABLE_BGM 1
#define ENABLE_SPEED_FIX 1
#define ENABLE_BUG_FIX 1
//#define ENABLE_TRANSLATION 1
#endif

#if defined(TARGET_SDL)
#define ENABLE_GRAP_OVERLAY 1
#define ENABLE_GRAP_OVERLAY_DEBUG 1
#endif

#endif
