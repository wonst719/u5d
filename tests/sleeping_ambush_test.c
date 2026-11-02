#undef NDEBUG
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL3/SDL.h>
#include "common/common.h"
#include "vars.h"
#include "funcs.h"
#include "macros.h"
#include "tiles.h"
#include "combat.h"
#include "graphics/grap_sdl.h"
#include "graphics/grap_buf.h"
#include "graphics/crt.h"
#include "graphics/widescreen.h"
extern void GRAP_SDL_Initialize(void);
extern void GRAP_SDL_FlushFrame(void);
extern void GRAP_SDL_Cleanup(void);
static jmp_buf entered;
/* Run real combat and drawing until the first player input prompt.
 * Replace only input and delays so ambush turns run deterministically. */
static int combatStarted;
int __wrap_ULTIMA_266c_GetChar(void) { longjmp(entered,1); }
void __wrap_ULTIMA_20fa_WaitTicks(int ticks) { (void)ticks; }
void __wrap_TIME_SleepMs(int ms) { (void)ms; }
void __wrap_ULTIMA_1b16_ClearKbdBuffer(void) { if(combatStarted) GRAP_SDL_FlushFrame(); }
int main(void) {
    assert(SDL_Init(SDL_INIT_VIDEO));
    GRAP_SDL_SetFullscreen(true);
    GRAP_SDL_Initialize();
    int count; SDL_Window **windows=SDL_GetWindows(&count);assert(count==1);
    SDL_SetWindowSize(windows[0],1920,1200);SDL_free(windows);
    GRAP_BUF_SetTransparentSprites(true);WIDE_SetDitheredDarkness(true);CRT_SetEnabled(true);
    byte *tiles=calloc(512,128);assert(tiles);memset(tiles,0x55,512*128);GRAP_BUF_LoadTileset(tiles);
    static byte font[2048];memset(font,255,sizeof(font));
    for(int i=0;i<4;i++) D_539c[i]=font;
    D_5398_currentCharset=font; D_538e=1;
    ULTIMA_1c22_SetTextWindowSize(0,0,0,39,24);
    ULTIMA_1c22_SetTextWindowSize(1,24,0,39,7);
    ULTIMA_1c22_SetTextWindowSize(2,24,11,39,23);
    ULTIMA_1b94_SelectTextWindow(2);
    D_585b=6;D_58a4=1;D_58a5=50;D_58a1=4;
    D_587b=D_589e=255;
    for(int i=0;i<256;i++) D_b11e[i]=i;
    memset(D_ad14,4,sizeof(D_ad14));
    for(int i=0;i<6;i++) {
        D_1724[i]=3+i%3;D_172c[i]=4+i/3;
        memset(&D_55a8_party[i],0,sizeof(D_55a8_party[i]));
        D_55a8_party[i].status=STATUS_SLEEP;
        D_55a8_party[i].hp=D_55a8_party[i].maxHp=200;
        D_55a8_party[i].dex=20;D_55a8_party[i].cls=CLASS_FIGHTER;
        memset(D_55a8_party[i].equips,255,sizeof(D_55a8_party[i].equips));
    }
    for(int i=0;i<16;i++) {D_1704[i]=i%11;D_1714[i]=i/11;}
    /* Match the fullscreen, transparency, darkness and CRT settings in the
     * crash log; cover every vanilla sleeping ambush, with/without smoothing. */
    for(int smooth=0;smooth<2;smooth++) for(int encounter=0;encounter<8;encounter++) {
        for(int i=0;i<6;i++) {
            D_55a8_party[i].status=STATUS_SLEEP;
            D_55a8_party[i].hp=200;
        }
        D_587b=D_589e=255;
        GRAP_SDL_SetSmoothMovement(smooth);
        D_5893_map_id=255;D_5894=0;D_5896_map_x=168;D_5897_map_y=19;
        ULTIMA_6936();ULTIMA_5910_UpdateFrame();GRAP_SDL_FlushFrame();
        ULTIMA_6bc2(4,D_1734[encounter]);
        combatStarted=1;
        if(!setjmp(entered)) COMBAT_0b94_MainLoop();
        combatStarted=0;
    }
    GRAP_SDL_Cleanup();SDL_Quit();
    puts("Sleeping ambush entry passed.");
}
