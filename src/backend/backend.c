#include "common/common.h"

#include "backend.h"

#include "audio/audio.h"
#include "event/event.h"
#include "graphics/grap.h"
#include "key/key.h"
#include "time/time.h"

#if defined(TARGET_SDL)
#include <SDL3/SDL.h>
#endif

// TODO: process error
bool BACKEND_Initialize(void)
{
    void DEBUG_Initialize(void);
    DEBUG_Initialize();

#if defined(TARGET_SDL)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
#endif

    GRAP_Initialize();
    TIME_Initialize();
    EVT_Initialize();
    KEY_Initialize();
    AUDIO_Initialize();

    return true;
}

void BACKEND_Cleanup(void)
{
    AUDIO_Cleanup();
    KEY_Cleanup();
    EVT_Cleanup();
    TIME_Cleanup();
    GRAP_Cleanup();

#if defined(TARGET_SDL)
    SDL_Quit();
#endif
}
