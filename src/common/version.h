#ifndef _COMMON_VERSION_H
#define _COMMON_VERSION_H

#define U5_BASE_VERSION "1.16"

#if defined(RELEASE_BUILD) && !defined(MATCHING_BUILD)
#include "git_ver.h"
#define U5_VERSION U5_BASE_VERSION " (" GIT_HASH ")"
#else
#define U5_VERSION U5_BASE_VERSION
#endif

#endif
