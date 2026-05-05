#include "common/common.h"

#include "backend.h"

#include <stdlib.h>

#include "graphics/grap.h"

#if defined(TARGET_WINDOWS)
#include <SDL3/SDL.h>
#endif

// TODO: process error

// TODO: audio header
void AUDIO_Init(void);
void AUDIO_Cleanup(void);

#if defined(TARGET_DOS32)
// TODO
void AUDIO_Init(void) {}
void AUDIO_Cleanup(void) {}
#endif

bool BACKEND_Initialize(void)
{
#if defined(TARGET_WINDOWS)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
#endif

    GRAP_InitializeVideoDriver();
    AUDIO_Init();

#if !defined(TARGET_DOS16)
    void TIME_Initialize(void);
    void TIME_Cleanup(void);

    TIME_Initialize();
    atexit(TIME_Cleanup);

    // TODO: separate keyboard
    void KEY_Initialize(void);
    void KEY_Cleanup(void);

    KEY_Initialize();
    atexit(KEY_Cleanup);
#endif

    return true;
}

void BACKEND_Cleanup(void)
{
    AUDIO_Cleanup();
    GRAP_CleanupVideoDriver();

#if defined(TARGET_WINDOWS)
    SDL_Quit();
#endif
}
