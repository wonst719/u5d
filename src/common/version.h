#ifndef _COMMON_VERSION_H
#define _COMMON_VERSION_H

#if defined(MATCHING_BUILD)
#define U5_BASE_VERSION "1.16"
#else
#define U5_BASE_VERSION "u5d"
#endif

#if defined(RELEASE_BUILD) && !defined(MATCHING_BUILD)
#include "git_ver.h"
#define U5_VERSION U5_BASE_VERSION " " U5_RELEASE_VERSION " (" GIT_HASH ")"
#else
#define U5_VERSION U5_BASE_VERSION
#endif

#endif
