#include "common/common.h"

#include "backend.h"

#include <stdlib.h>

#include "graphics/grap.h"
#include "audio/audio.h"
#include "time/time.h"
#include "key/key.h"

#if defined(TARGET_WINDOWS)
#include <SDL3/SDL.h>
#endif

// TODO: process error
bool BACKEND_Initialize(void)
{
#if defined(TARGET_WINDOWS)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
#endif

    GRAP_InitializeVideoDriver();
    AUDIO_Init();

    TIME_Initialize();
    KEY_Initialize();

    return true;
}

void BACKEND_Cleanup(void)
{
    KEY_Cleanup();
    TIME_Cleanup();
    AUDIO_Cleanup();
    GRAP_CleanupVideoDriver();

#if defined(TARGET_WINDOWS)
    SDL_Quit();
#endif
}
