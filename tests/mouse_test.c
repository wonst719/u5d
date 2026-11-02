#undef NDEBUG
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "common/common.h"
#include "common/file.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"
#include "funcs.h"
#include "talk.h"
#include "lookobj.h"
#include "mod/types.h"
#include "mod/actors.h"
#include "sjog.h"
#include "combat.h"
#include "comsubs.h"
#include "common/movement.h"
#include "event/event.h"
#include "key/mouse.h"
#include "key/key.h"
#include "graphics/grap_sdl.h"
#include "graphics/crt.h"
#include "graphics/grap_buf.h"
#include "graphics/animate.h"
#include "graphics/widescreen.h"
#include <SDL3/SDL.h>
static int loadedCursors;
void __wrap_ULTIMA_433e_AudioFootstep(void) {} /* Audio delay uses a real clock; this test mocks time. */
SDL_Cursor* __wrap_SDL_CreateColorCursor(SDL_Surface* surface, int x, int y)
{
    int width,height; GRAP_SDL_CursorSize(&width,&height);
    assert(surface->w == width && surface->h == height);
    /* Pointer, N, NE, E, SE, S, SW, W, NW: test every scaled arrow tip. */
    const int expectedX[9] = {0,17*width/32,width-1,29*width/32,width-1,17*width/32,0,5*width/32,0};
    const int expectedY[9] = {0,5*height/32,0,17*height/32,height-1,29*height/32,height-1,17*height/32,0};
    assert(x == expectedX[loadedCursors % 9]);
    assert(y == expectedY[loadedCursors % 9]);
    bool transparent = false, opaque = false;
    for (int yy = 0; yy < surface->h; ++yy) for (int xx = 0; xx < surface->w; ++xx) {
        Uint8 r,g,b,a;
        assert(SDL_ReadSurfacePixel(surface,xx,yy,&r,&g,&b,&a));
        assert((r==0 || r==255) && g==r && b==r && (a==0 || a==255));
        transparent |= a == 0; opaque |= a == 255;
    }
    assert(transparent && opaque);
    Uint8 tipR,tipG,tipB,tipA;
    assert(SDL_ReadSurfacePixel(surface,x,y,&tipR,&tipG,&tipB,&tipA));
    assert(tipA==255 && tipR==255 && tipG==255 && tipB==255);
    ++loadedCursors;
    return NULL; /* SDL dummy driver has no native cursor support. */
}
static Uint64 ticks = 2000;
static Uint32 animationDelay,renderCost;
void __wrap_SDL_Delay(Uint32 ms) { animationDelay += ms; }
static float cursorX, cursorY;
static bool sawGuardian;
static char actorLook[128];
static bool sawSleepingNpc, sawFountain, sawDrinkPrompt, sawWell, sawCoinPrompt;
static int presented;
static bool confirmAimOnPoll;
static bool checkAnimation;
static bool checkWater;
static bool checkDarkness;
static bool checkDither;
static bool profileDark;
static unsigned hiddenTerrainSamples;
static unsigned scrollingTextureAllocations, darknessUploads;
static int profileMaskWidth,profileMaskHeight;
SDL_Texture *__real_SDL_CreateTexture(SDL_Renderer *,SDL_PixelFormat,SDL_TextureAccess,int,int);
SDL_Texture *__wrap_SDL_CreateTexture(SDL_Renderer *r,SDL_PixelFormat format,
                                     SDL_TextureAccess access,int w,int h) {
    if(profileDark) ++scrollingTextureAllocations;
    return __real_SDL_CreateTexture(r,format,access,w,h);
}
SDL_Texture *__real_SDL_CreateTextureFromSurface(SDL_Renderer *,SDL_Surface *);
SDL_Texture *__wrap_SDL_CreateTextureFromSurface(SDL_Renderer *r,SDL_Surface *surface) {
    if(profileDark) ++scrollingTextureAllocations;
    return __real_SDL_CreateTextureFromSurface(r,surface);
}
bool __real_SDL_UpdateTexture(SDL_Texture *,const SDL_Rect *,const void *,int);
bool __wrap_SDL_UpdateTexture(SDL_Texture *texture,const SDL_Rect *rect,const void *pixels,int pitch) {
    float w,h;
    if(profileDark && SDL_GetTextureSize(texture,&w,&h) && w==profileMaskWidth && h==profileMaskHeight)
        ++darknessUploads;
    return __real_SDL_UpdateTexture(texture,rect,pixels,pitch);
}
byte __real_WIDE_TerrainPixel(int dx,int dy,int x,int y);
byte __wrap_WIDE_TerrainPixel(int dx,int dy,int x,int y) {
    if (profileDark) {
        bool visible=MAP_IN_VIEW(dx,dy) ? GetMapViewport(dx+MAP_CENTER_X,dy+MAP_CENTER_Y)!=255
                                      : WIDE_Visible(dx,dy);
        if (!visible) ++hiddenTerrainSamples;
    }
    return __real_WIDE_TerrainPixel(dx,dy,x,y);
}
static Uint64 darkStepStarted, darkPreparationTicks;
static unsigned darkSteps;
static bool checkCRT;
static int ditherDx,ditherDy;
static unsigned ditherPattern;
static bool checkEdges;
static bool edgeBright=true;
static int lightX,lightY,darkX;
static SDL_Rect waterMap;
static int animationRow, playerScreenX, previousMarkerX;
static bool checkActor;
static bool checkCombatOrder, orderMovingSouth, orderSelection;

static bool checkCombatMargins;
static bool transparentSprites;
static int actorRow, actorStart, actorEnd, actorMarker;
bool __real_SDL_RenderPresent(SDL_Renderer* renderer);
bool __wrap_SDL_RenderPresent(SDL_Renderer* renderer)
{
    presented++;
    if((checkDither || profileDark) && presented==1 && darkStepStarted) {
        darkPreparationTicks+=SDL_GetPerformanceCounter()-darkStepStarted; ++darkSteps;
    }
    ticks+=renderCost;
    if (checkCombatOrder) {
        SDL_Surface *image = SDL_RenderReadPixels(renderer, NULL);
        assert(image);
        WideLayout layout = WIDE_Layout(image->w, image->h);
        float cellX = orderMovingSouth ? 2 + SDL_min(presented, 8) / 8.0f : 3;
        int x = (image->w - layout.width * layout.scale) / 2 +
                (layout.mapX + (layout.columns / 2 - 5 + cellX) * 16 + 4) * layout.scale;
        int y = SDL_ceilf((image->h - layout.height * layout.scaleY) / 2 +
                          (layout.mapY + (layout.rows / 2 - 5 + 4) * 16) * layout.scaleY);
        Uint8 r, g, b, a;
        assert(SDL_ReadSurfacePixel(image, x, y, &r, &g, &b, &a));
        assert(orderSelection ? (r == 255 && g == 255 && b == 255)
                              : (r == 85 && g == 255 && b == 85));
        x=(image->w-layout.width*layout.scale)/2+
          (layout.mapX+(layout.columns/2-5+8)*16+8)*layout.scale;
        y=SDL_ceilf((image->h-layout.height*layout.scaleY)/2+
                    (layout.mapY+(layout.rows/2-5+8)*16+8)*layout.scaleY);
        assert(SDL_ReadSurfacePixel(image,x,y,&r,&g,&b,&a));
        assert(r==255 && g==85 && b==85); /* Native marker/effect survives every frame. */
        SDL_DestroySurface(image);
    }
    if(checkCombatMargins) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);
        assert(image);
        WideLayout combat=WIDE_Layout(image->w,image->h);
        int x=(image->w-combat.width*combat.scale)/2+(combat.mapX+combat.columns/2*16+8)*combat.scale;
        for(int edge=0;edge<2;edge++) {
            int y=(image->h-combat.height*combat.scaleY)/2+
                SDL_ceilf((edge?combat.mapY+combat.rows*16:combat.mapY-1)*combat.scaleY);
            Uint8 r,g,b,a;
            assert(SDL_ReadSurfacePixel(image,x,y,&r,&g,&b,&a));
            assert(r==0 && g==0 && b==0);
        }
        SDL_DestroySurface(image);
    }
    if (checkActor) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);
        assert(image);
        int marker=-1,count=0;
        for (int x=0;x<image->w;x++) {
            Uint8 r,g,b,a;
            assert(SDL_ReadSurfacePixel(image,x,actorRow,&r,&g,&b,&a));
            if (r==85 && g==255 && b==85) { if(marker<0) marker=x; count++; }
        }
        assert(count==48); /* exactly one sprite, with no stale copy or trail */
        assert(marker>=actorMarker && marker<=actorEnd);
        if (presented==1 && actorStart!=actorEnd) assert(marker>actorStart && marker<actorEnd);
        /* Top-half hole: its inner pixels show blue terrain during movement. */
        Uint8 r,g,b,a;
        assert(SDL_ReadSurfacePixel(image,marker+8*3,actorRow-3*3,&r,&g,&b,&a));
        if(D_5893_map_id<128) assert(r==0 && g==0 && b==(transparentSprites?170:0));
        actorMarker=marker;
        SDL_DestroySurface(image);
    }
    if(checkEdges) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);assert(image);
        Uint8 r,g,b,a;
        assert(SDL_ReadSurfacePixel(image,waterMap.x+1,waterMap.y+30,&r,&g,&b,&a));
        assert(r==0 && g==0 && b==(edgeBright?170:0)); /* completed map retained during UI-only flush */
        SDL_DestroySurface(image);
    }
    if(checkCRT) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);assert(image);
        Uint8 r,g,b,a;
        int x=waterMap.x+waterMap.w/2+59,y=waterMap.y+waterMap.h/2+28;
        assert(SDL_ReadSurfacePixel(image,x,y,&r,&g,&b,&a));
        assert(r==0 && g==0 && b>80 && b<200 && b!=170); /* filtered on every presented frame, with brightness compensation */
        if(presented==9) assert(SDL_SaveBMP(image,"crt-gameplay.bmp"));
        SDL_DestroySurface(image);
    }
    if(checkDither) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);assert(image);
        int dark=0,lit=0;
        unsigned pattern=0;
        int scrollX=presented<=8 ? ditherDx*(8-presented)*6 : 0;
        float scrollY=presented<=8 ? SDL_roundf(ditherDy*(8-presented)*7.2f) : 0;
        for(int y=4;y<8;y++) for(int x=4;x<8;x++) {
            Uint8 r,g,b,a;
            assert(SDL_ReadSurfacePixel(image,lightX-2+x*3+scrollX,lightY-8*3.6f+(y+0.5f)*3.6f+scrollY,&r,&g,&b,&a));
            assert(r==0 && g==0 && (b==0 || b==170));
            dark+=b==0;lit+=b==170;
            if(b==0) pattern|=1u<<((y-4)*4+x-4);
        }
        assert(dark>0 && lit>0);
        if(!ditherDx && !ditherDy) ditherPattern=pattern;
        else assert(pattern==ditherPattern); /* every pixel follows the terrain */
        SDL_DestroySurface(image);
    }
    if(checkDarkness) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);assert(image);
        Uint8 r,g,b,a;
        assert(SDL_ReadSurfacePixel(image,lightX+(presented<=8?ditherDx*(8-presented)*6:0),lightY+(presented<=8?SDL_roundf(ditherDy*(8-presented)*7.2f):0),&r,&g,&b,&a));
        assert(r==0 && g==0 && b==170); /* visible ground follows the map */
        assert(SDL_ReadSurfacePixel(image,darkX+(presented<=8?ditherDx*(8-presented)*6:0),lightY+(presented<=8?SDL_roundf(ditherDy*(8-presented)*7.2f):0),&r,&g,&b,&a));
        assert(r==0 && g==0 && b==0); /* hidden ground stays covered as it scrolls */
        SDL_DestroySurface(image);
    }
    if(checkWater) {
        SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);assert(image);
        int xs[]={waterMap.x+1,waterMap.x+waterMap.w/2,waterMap.x+waterMap.w-2};
        WideLayout edgeLayout=WIDE_Layout(1024,768);
        float canvasY=(768-edgeLayout.height*edgeLayout.scaleY)/2;
        int ys[]={(int)(canvasY+8*edgeLayout.scaleY)+1,waterMap.y+waterMap.h/2,
                  (int)(canvasY+(edgeLayout.height-8)*edgeLayout.scaleY)-2};
        for(int y=0;y<3;y++) for(int x=0;x<3;x++) {
            if(x==1 && y==1) continue; /* player sprite */
            Uint8 r,g,b,a;assert(SDL_ReadSurfacePixel(image,xs[x],ys[y],&r,&g,&b,&a));
            assert(r==0 && g==170 && b==170); /* one current water phase, no old/new seams */
        }
        SDL_DestroySurface(image);
    }
    if (checkAnimation) {
        SDL_Surface* image = SDL_RenderReadPixels(renderer,NULL);
        assert(image);
        Uint8 r,g,b,a;
        assert(SDL_ReadSurfacePixel(image,0,0,&r,&g,&b,&a));
        assert(r==85 && g==255 && b==85); /* interface pixel stays fixed */
        assert(SDL_ReadSurfacePixel(image,playerScreenX,animationRow,&r,&g,&b,&a));
        assert(r==255 && g==255 && b==85); /* centered player never duplicates */
        int marker = -1;
        for (int x=0; x<playerScreenX; x++) {
            assert(SDL_ReadSurfacePixel(image,x,animationRow,&r,&g,&b,&a));
            if (r==255 && g==85 && b==85) { marker=x; break; }
        }
        assert(marker>=0 && marker<=previousMarkerX);
        if (presented<=8) assert(marker==previousMarkerX-6); /* constant speed: 48 pixels / 8 frames */
        previousMarkerX=marker;
        SDL_DestroySurface(image);
    }
    bool result=__real_SDL_RenderPresent(renderer);
    /* Present invalidates the SDL backbuffer. Simulate a renderer that discards
     * it, so a second present without a full redraw cannot pass by accident. */
    if(checkAnimation || checkActor || checkWater || checkDarkness || checkDither || checkCRT) {
        SDL_SetRenderDrawColor(renderer,255,0,255,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
    }
    return result;
}
void __wrap_ULTIMA_1850_PrintString(char* text)
{
    if (!strcmp(text, "a guard") || !strcmp(text, "a royal guard") ||
        !strcmp(text, "Guard") || !strcmp(text, "Guards"))
        snprintf(actorLook, sizeof(actorLook), "%s", text);
    if (!strcmp(text, "the Guardian"))
        sawGuardian = true;
    if (strstr(text, "Zzzzzz")) sawSleepingNpc = true;
    if (strstr(text, "gurgling fountain")) sawFountain = true;
    if (strstr(text, "Who will drink")) sawDrinkPrompt = true;
    if (strstr(text, "a well")) sawWell = true;
    if (strstr(text, "Drop a coin")) sawCoinPrompt = true;
}
void __wrap_ULTIMA_16ba_PrintChar(uint ch) { (void)ch; }
Uint64 __wrap_SDL_GetTicks(void) { return ticks; }
SDL_MouseButtonFlags __wrap_SDL_GetMouseState(float* x, float* y)
{
    *x=cursorX; *y=cursorY;
    if (confirmAimOnPoll && D_5898) {
        confirmAimOnPoll=false;
        MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    }
    return SDL_BUTTON_RMASK;
}
extern void GRAP_SDL_Initialize(void);
extern void GRAP_SDL_Cleanup(void);
extern void GRAP_SDL_FlushFrame(void);
static void paintActor(int index,int x,int y)
{
    memset(g_linearEgaBuffer0,1,320*200);
    memset(D_ab02,1,sizeof(D_ab02));
    memset(D_5c5a,0,sizeof(D_5c5a));
    D_5c5a[index]._0_tile=D_5c5a[index]._1_animTile=0x44;
    D_5c5a[index]._2_x=x; D_5c5a[index]._3_y=y;
    bool combat=D_5893_map_id>=128;
    int col=combat?x:x-D_5896_map_x+5, row=combat?y:y-D_5897_map_y+5;
    GetMapViewport(col,row)=0;
    GetActorMap(col,row)=0x44;
    GRAP_BUF_PutMapSprite(col,row,256+0x44);
}
static void paintCombatCursor(int x, int y) {
    /* This fixture initializes SDL directly, without the driver dispatch used
     * by ULTIMA's line calls. Supply the same native selection bitmap. */
    GRAP_BUF_SetPenColor(15);
    x = 8 + x * 16;
    y = 8 + y * 16;
    for (int inset = 0; inset < 2; ++inset) {
        GRAP_BUF_Line(x, y + inset, x + 15, y + inset);
        GRAP_BUF_Line(x, y + 14 + inset, x + 15, y + 14 + inset);
        GRAP_BUF_Line(x + inset, y, x + inset, y + 15);
        GRAP_BUF_Line(x + 14 + inset, y, x + 14 + inset, y + 15);
    }
}
#include "synthetic_tileset_mask.h"
int main(int argc, char** argv)
{
    syntheticMaskBegin();
    transparentSprites = !(argc > 1 && strcmp(argv[1], "--opaque") == 0);
    GRAP_BUF_SetTransparentSprites(transparentSprites);
    assert(!MOVEMENT_Diagonal());
    assert(MOUSE_Direction(1,1)==U5_KEY_RIGHT);
    assert(MOUSE_Direction(-1,-2)==U5_KEY_UP);
    assert(!MOVEMENT_Adjacent(1,1));
    assert(!MOVEMENT_AttackAllowed(1,1));
    assert(MOVEMENT_AttackAllowed(0,3));
    MOVEMENT_SetDiagonal(true);
    D_587c_partyTile=TILE_ACTOR_AVATAR;
    for (int direction=U5_KEY_HOME; direction<=U5_KEY_PGDN; ++direction) {
        int horizontal=direction==U5_KEY_HOME || direction==U5_KEY_END ? U5_KEY_LEFT : U5_KEY_RIGHT;
        int vertical=direction==U5_KEY_HOME || direction==U5_KEY_PGUP ? U5_KEY_UP : U5_KEY_DOWN;
        assert(MOVEMENT_SlideDirection(direction,false,true)==vertical);
        assert(MOVEMENT_SlideDirection(direction,true,false)==horizontal);
        assert(MOVEMENT_SlideDirection(direction,true,true)==direction);
        assert(MOVEMENT_SlideDirection(direction,false,false)==direction);
        int dx=horizontal==U5_KEY_LEFT ? -1 : 1;
        int dy=vertical==U5_KEY_UP ? -1 : 1;
        GetMapViewport(5+dx,5)=TILE_MAP_WALL;
        GetMapViewport(5,5+dy)=TILE_MAP_GRASS;
        assert(MOVEMENT_MapSlideDirection(direction)==vertical);
        GetMapViewport(5+dx,5)=TILE_MAP_GRASS;
        GetMapViewport(5,5+dy)=TILE_MAP_WALL;
        assert(MOVEMENT_MapSlideDirection(direction)==horizontal);
        GetMapViewport(5+dx,5)=TILE_MAP_WALL;
        assert(MOVEMENT_MapSlideDirection(direction)==direction);
        GetMapViewport(5+dx,5)=GetMapViewport(5,5+dy)=TILE_MAP_GRASS;
        assert(MOVEMENT_MapSlideDirection(direction)==direction);
    }
    assert(MOUSE_Direction(-2,0)==U5_KEY_LEFT);
    assert(MOUSE_Direction(2,0)==U5_KEY_RIGHT);
    assert(MOUSE_Direction(0,-2)==U5_KEY_UP);
    assert(MOUSE_Direction(0,2)==U5_KEY_DOWN);
    assert(MOUSE_Direction(-2,-2)==U5_KEY_HOME);
    assert(MOUSE_Direction(2,-2)==U5_KEY_PGUP);
    assert(MOUSE_Direction(-2,2)==U5_KEY_END);
    assert(MOUSE_Direction(2,2)==U5_KEY_PGDN);
    assert(MOUSE_Direction(0,0)==0);
    D_5893_map_id=13; D_5896_map_x=16; D_5897_map_y=16; D_5895_map_level=0;
    memset(D_6608_map.town,1,32*32);
    D_5c5a[1]._0_tile=0x44; D_5c5a[1]._2_x=17; D_5c5a[1]._3_y=16;
    assert(MOUSE_Action(1,0,true)=='T');
    assert(MOUSE_Action(1,0,false)=='L');
    D_5c5a[1]._3_y=15;
    assert(MOUSE_Action(1,-1,true)=='T');
    D_5c5a[1]._3_y=16;
    assert(MOUSE_Action(2,0,true)==0);
    assert(MOUSE_Action(1,1,true)=='L');
    assert(MOUSE_Action(2,0,false)=='L');
    /* Match Talk's original reach across every supported intermediate tile. */
    const int talkThrough[]={TILE_MAP_29,TILE_MAP_TABLE_94,TILE_MAP_TABLE_95,TILE_MAP_TABLE_96,
        TILE_MAP_97,TILE_MAP_98,TILE_MAP_99,TILE_MAP_TABLE_9A,TILE_MAP_TABLE_9B,
        TILE_MAP_TABLE_9C,TILE_MAP_DESK,TILE_MAP_AE,TILE_MAP_DOOR_BA,TILE_MAP_DOOR_BB,
        TILE_MAP_TABLE_BE,TILE_MAP_CA,TILE_MAP_CB};
    D_5c5a[1]._2_x=18;
    for(size_t i=0;i<sizeof(talkThrough)/sizeof(talkThrough[0]);i++) {
        GetMap(17,16)=talkThrough[i];D_5876=7;
        assert(MOUSE_Action(2,0,true)=='T');assert(D_5876==7);
    }
    GetMap(17,16)=TILE_MAP_WALL;assert(MOUSE_Action(2,0,true)==0);
    GetMap(17,16)=TILE_MAP_TABLE_94;
    D_5c5a[2]=D_5c5a[1];D_5c5a[2]._2_x=17;D_5c5a[2]._0_tile=TILE_ACTOR_CHEST;
    assert(MOUSE_Action(2,0,true)==0);D_5c5a[2]._0_tile=0;
    D_5c5a[1]._4_z=1;assert(MOUSE_Action(2,0,true)==0);D_5c5a[1]._4_z=0;
    assert(MOUSE_Action(3,0,true)==0);assert(MOUSE_Action(2,1,true)==0);
    D_5c5a[1]._3_y=14;GetMap(17,15)=TILE_MAP_DESK;
    assert(MOUSE_Action(2,-2,true)=='T');MOVEMENT_SetDiagonal(false);
    assert(MOUSE_Action(2,-2,true)==0);MOVEMENT_SetDiagonal(true);
    D_5c5a[1]._2_x=17;D_5c5a[1]._3_y=16;GetMap(17,16)=1;

    D_5c5a[1]._0_tile=TILE_ACTOR_CHEST;
    assert(MOUSE_Action(1,0,true)=='O');
    D_5c5a[1]._0_tile=0;
    GetMap(17,16)=TILE_MAP_DOOR_B8;
    assert(MOUSE_Action(1,0,true)=='O');
    assert(SDL_Init(SDL_INIT_VIDEO));
    GRAP_SDL_Initialize();
    MOUSE_Initialize();
    int pixelWidth,pixelHeight;
    GRAP_SDL_CursorSize(&pixelWidth,&pixelHeight);
    assert(pixelWidth==64 && pixelHeight==77);
    int dx,dy; float rx,ry;
    assert(GRAP_SDL_MouseMapPoint(384,460.8f,&dx,&dy,&rx,&ry));
    assert(dx==0 && dy==0);
    assert(GRAP_SDL_MouseMapPoint(448,460.8f,&dx,&dy,&rx,&ry));
    assert(dx==1 && dy==0);
    assert(!GRAP_SDL_MouseMapPoint(1000,450,&dx,&dy,&rx,&ry));
    byte oldActive=D_58a4; D_58a4=1;
    const float framePoints[][2]={{4,96},{188,96},{96,4},{96,188}};
    const int frameDirections[]={U5_KEY_LEFT,U5_KEY_RIGHT,U5_KEY_UP,U5_KEY_DOWN};
    for(int i=0;i<4;i++) {
        float x=framePoints[i][0]*4, y=framePoints[i][1]*4.8f;
        assert(!GRAP_SDL_MouseMapPoint(x,y,&dx,&dy,&rx,&ry));
        assert(GRAP_SDL_MouseMovementPoint(x,y,&dx,&dy,&rx,&ry));
        assert(MOUSE_CursorDirection(x,y)==frameDirections[i]);
    }
    assert(!GRAP_SDL_MouseMovementPoint(192*4,96*4.8f,&dx,&dy,&rx,&ry));
    assert(!GRAP_SDL_MouseMovementPoint(96*4,192*4.8f,&dx,&dy,&rx,&ry));
    assert(!GRAP_SDL_MouseMovementPoint(-1,96*4.8f,&dx,&dy,&rx,&ry));
    D_58a4=oldActive;

    MOUSE_SetCommandInput(true);
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);
    ticks+=301;
    assert(MOUSE_PollCommand()==0); /* mouse is opt-in */
    MOUSE_SetEnabled(true);
    MOUSE_Initialize();
    assert(loadedCursors == 9);
    D_58a4=1;
    extern void KEY_SDL_ClearInput(void);
    extern void EVT_PollMessages(void);
    uint savedAdvance = D_538e;
    /* Wheel routing uses native UI coordinates, including aspect-correct
     * fullscreen scaling. Message history never changes live text pixels. */
    D_535e_textWindows[2] = (TextWindow){24,11,39,23,0,12,15,0};
    GRAP_BUF_ResetTextHistory();
    for (int row=0;row<13;row++) for(int y=0;y<8;y++)
        memset(g_linearEgaBuffer0+(88+row*8+y)*320+192,row+1,128);
    GRAP_BUF_ScrollWindow(192,88,319,191,-8);
    byte past=0;
    assert(g_linearEgaBuffer0[88*320+192]==2);
    MOUSE_Wheel(800,480,0.5f);
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    MOUSE_Wheel(800,480,0.5f);
    assert(GRAP_BUF_TextHistoryPixel(192,88,&past) && past==1);
    assert(GRAP_BUF_TextHistoryPixel(192,96,&past) && past==2);
    assert(g_linearEgaBuffer0[88*320+192]==2);
    byte cursorFont[8]={255,255,255,255,255,255,255,255};
    D_538e=0;GRAP_BUF_PrintChar(cursorFont,0,15,0,24,23);
    assert(GRAP_BUF_TextHistoryPixel(192,88,&past)&&past==1);
    D_538e=1;
    MOUSE_Wheel(800,480,-1);
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    // Real SDL wheel events and natural/flipped scrolling.
    SDL_Event wheel={0};wheel.type=SDL_EVENT_MOUSE_WHEEL;
    wheel.wheel.mouse_x=800;wheel.wheel.mouse_y=480;wheel.wheel.y=-1;
    wheel.wheel.direction=SDL_MOUSEWHEEL_FLIPPED;
    assert(SDL_PushEvent(&wheel));EVT_PollMessages();
    assert(GRAP_BUF_TextHistoryPixel(192,88,&past)&&past==1);
    GRAP_BUF_PrintChar(cursorFont,0,15,0,24,23);
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    MOUSE_Wheel(800,480,1);
    SDL_Event typing={0};typing.type=SDL_EVENT_KEY_DOWN;typing.key.key=SDLK_A;
    assert(SDL_PushEvent(&typing));EVT_PollMessages();
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    KEY_SDL_ClearInput();
    // Multiple notches navigate only a registered list, without Enter or
    // falling through to party movement when the list closes.
    MOUSE_MenuSet(192,8,120,7,3);
    MOUSE_Wheel(800,144,-3);
    for(int n=0;n<3;n++) assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    assert(MOUSE_PollCommand()==0);
    MOUSE_Wheel(800,144,1);
    assert(MOUSE_PollCommand()==U5_KEY_UP);
    MOUSE_MenuEnd();
    wheel.wheel.mouse_y=144;wheel.wheel.y=1;wheel.wheel.direction=SDL_MOUSEWHEEL_NORMAL;
    assert(SDL_PushEvent(&wheel));
    assert(MOUSE_ScrollRead()==U5_KEY_UP);
    // Events received during a list redraw remain available for its next read.
    MOUSE_Wheel(800,144,-2);
    assert(MOUSE_PollCommand()==0);
    MOUSE_MenuSet(192,8,128,9,0);
    assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    MOUSE_MenuEnd();MOUSE_Cancel();
    MOUSE_Wheel(800,144,-1);
    assert(MOUSE_PollCommand()==0);
    // Scrolling outside either panel does nothing.
    MOUSE_Wheel(384,460.8f,1);
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    // Scrollback is bounded, survives explicit message clears, and resets
    // when the message panel changes size rather than mixing row widths.
    GRAP_BUF_ResetTextHistory();
    for(int n=0;n<600;n++) {
        for(int y=88;y<96;y++) memset(g_linearEgaBuffer0+y*320+192,n%15+1,128);
        GRAP_BUF_ScrollWindow(192,88,319,191,-8);
    }
    GRAP_BUF_ScrollTextHistory(10000);
    assert(GRAP_BUF_TextHistoryPixel(192,88,&past)&&past==14);
    GRAP_BUF_ScrollTextHistory(-10000);
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    GRAP_BUF_ResetTextHistory();
    for(int row=0;row<13;row++) for(int y=0;y<8;y++)
        memset(g_linearEgaBuffer0+(88+row*8+y)*320+192,row<3?row+1:0,128);
    GRAP_BUF_SetPage(0);GRAP_BUF_SetPenColor(0);
    GRAP_BUF_FillWindow(192,88,319,191,0);
    GRAP_BUF_ScrollTextHistory(10000);
    assert(GRAP_BUF_TextHistoryPixel(192,88,&past)&&past==1);
    assert(g_linearEgaBuffer0[88*320+192]==0);
    GRAP_SDL_SetPixelUI(true);
    GRAP_BUF_FillWindow(0,0,319,199,0);
    GRAP_SDL_SetPixelUI(false);
    assert(GRAP_BUF_TextHistoryPixel(192,88,&past)&&past==1);
    // Modal UI clears must not erase the message archive.
    D_535e_textWindows[2].right=38;
    assert(!GRAP_BUF_TextHistoryPixel(192,88,&past));
    D_535e_textWindows[2].right=39;
    GRAP_BUF_ResetTextHistory();
    D_538e = savedAdvance;
    MOVEMENT_SetDiagonal(false);
    assert(MOUSE_CursorDirection(448,350)==U5_KEY_UP);
    assert(MOUSE_CursorDirection(320,570)==U5_KEY_DOWN);
    assert(MOUSE_Action(1,1,true)==0);
    assert(MOUSE_Action(1,1,false)=='L');
    MOVEMENT_SetDiagonal(true);
    MOUSE_SetCommandInput(true);
    D_58a4 = 1;
    assert(MOUSE_CursorDirection(448,460.8f) == U5_KEY_RIGHT);
    assert(MOUSE_CursorDirection(320,460.8f) == U5_KEY_LEFT);
    assert(MOUSE_CursorDirection(384,384) == U5_KEY_UP);
    assert(MOUSE_CursorDirection(384,537.6f) == U5_KEY_DOWN);
    assert(MOUSE_CursorDirection(320,384) == U5_KEY_HOME);
    assert(MOUSE_CursorDirection(448,384) == U5_KEY_PGUP);
    assert(MOUSE_CursorDirection(320,537.6f) == U5_KEY_END);
    assert(MOUSE_CursorDirection(448,537.6f) == U5_KEY_PGDN);
    assert(MOUSE_CursorDirection(384,460.8f) == U5_KEY_PGDN);
    assert(MOUSE_CursorDirection(448,460.8f) == U5_KEY_RIGHT);
    assert(MOUSE_CursorDirection(384,460.8f) == U5_KEY_RIGHT);
    /* All eight zones meet inside the sprite at its exact center. */
    assert(MOUSE_CursorDirection(385,460.8f)==U5_KEY_RIGHT);
    assert(MOUSE_CursorDirection(383,460.8f)==U5_KEY_LEFT);
    assert(MOUSE_CursorDirection(384,459.6f)==U5_KEY_UP);
    assert(MOUSE_CursorDirection(384,462.0f)==U5_KEY_DOWN);
    assert(MOUSE_CursorDirection(383,459.6f)==U5_KEY_HOME);
    assert(MOUSE_CursorDirection(385,459.6f)==U5_KEY_PGUP);
    assert(MOUSE_CursorDirection(383,462.0f)==U5_KEY_END);
    assert(MOUSE_CursorDirection(385,462.0f)==U5_KEY_PGDN);
    assert(MOUSE_CursorDirection(384,460.8f)==U5_KEY_PGDN);
    assert(MOUSE_Direction(0,0)==0);
    assert(MOUSE_Direction(0.1f,0.1f)==U5_KEY_PGDN);
    assert(MOUSE_CursorDirection(1000,450) == 0);
    assert(MOUSE_CursorDirection(384,460.8f) == U5_KEY_PGDN);
    D_58a4 = 0;
    assert(MOUSE_CursorDirection(448,460.8f) == 0);
    D_58a4 = 1;
    D_5893_map_id = 33;
    assert(MOUSE_CursorDirection(448,460.8f) == 0);
    D_5893_map_id = 13;
    /* Hover walks the native selection; a click confirms only its own row. */
    cursorX = 800; cursorY = 115.2f;
    MOUSE_MenuSet(192,8,120,3,0);
    assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    MOUSE_MenuSet(192,8,120,3,1);
    assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    MOUSE_MenuSet(192,8,120,3,2);
    assert(MOUSE_PollCommand()==0);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==U5_KEY_ENTER);
    assert(MOUSE_PollCommand()==0);
    MOUSE_Button(400,115.2f,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==0); /* map is outside the party list */
    MOUSE_Cancel();
    MOUSE_MenuSet(192,8,120,3,0);
    assert(MOUSE_PollCommand()==0); /* keyboard selection takes priority until mouse moves */
    MOUSE_MenuEnd();
    assert(MOUSE_PollCommand()==0);
    /* A title click arriving during an animation/event yield must remain queued
     * while the native highlight walks to the clicked row. */
    GRAP_SDL_SetPixelUI(true);
    for(int target=0;target<7;target++) {
        MOUSE_Cancel();MOUSE_MenuSet(64,132,192,7,0);
        float clickX=cursorX=100*4,clickY=cursorY=80+(132+target*8+4)*4;
        SDL_Event titleClick={0};titleClick.type=SDL_EVENT_MOUSE_BUTTON_DOWN;
        titleClick.button.button=SDL_BUTTON_LEFT;titleClick.button.clicks=1;
        titleClick.button.x=clickX;titleClick.button.y=clickY;
        assert(SDL_PushEvent(&titleClick));EVT_Yield();
        for(int selected=0;selected<target;selected++) {
            MOUSE_MenuSet(64,132,192,7,selected);
            assert(MOUSE_PollCommand()==U5_KEY_DOWN);
            EVT_Yield(); /* Redraw/animation may pump events between selection steps. */
        }
        MOUSE_MenuSet(64,132,192,7,target);
        assert(MOUSE_PollCommand()==U5_KEY_ENTER);
        assert(MOUSE_PollCommand()==0);
        MOUSE_MenuEnd();MOUSE_Cancel();
    }
    GRAP_SDL_SetPixelUI(false);
    /* Exercise the actual party selector, not only synthetic menu keystrokes. */
    static byte testFont[2048];
    D_5398_currentCharset = testFont;
    for (int i=0;i<4;i++) D_539c[i]=testFont;
    int savedPartySize = D_585b;
    D_585b = 3;
    MOUSE_MenuSet(192,8,120,3,0);
    MOUSE_Button(800,115.2f,SDL_BUTTON_LEFT,true,1);
    assert(ULTIMA_2d7a(0)==2);
    D_585b = savedPartySize;
    MOUSE_Cancel();
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==0);
    ticks+=301;
    assert(MOUSE_PollCommand()=='L');
    MOUSE_SetCommandInput(false);
    assert(MOUSE_TakeDirection()==U5_KEY_RIGHT);
    assert(MOUSE_TakeDirection()==0);
    MOUSE_SetCommandInput(true);
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);
    ticks+=100;
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,2);
    assert(MOUSE_PollCommand()=='O');
    ticks+=400;
    assert(MOUSE_PollCommand()==0); /* no stray Look after a double click */
    D_5c5a[1]._0_tile=0x44;
    GetMap(17,16)=TILE_MAP_BED;
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);
    ticks+=100;
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,2);
    assert(MOUSE_PollCommand()=='T');
    MOUSE_SetCommandInput(false);
    assert(TALK_041c_TalkCmd()==0); /* real keyboard handler, including bed rules */
    assert(sawSleepingNpc && D_5876==1 && D_5878==0);
    /* Diagonal Talk travels through the actual keyboard command handler. */
    MOUSE_SetCommandInput(true);
    D_5c5a[1]._3_y=15;
    GetMap(17,15)=TILE_MAP_BED;
    MOUSE_Button(448,384,SDL_BUTTON_LEFT,true,1);
    MOUSE_Button(448,384,SDL_BUTTON_LEFT,true,2);
    assert(MOUSE_PollCommand()=='T');
    MOUSE_SetCommandInput(false);
    sawSleepingNpc=false;
    assert(TALK_041c_TalkCmd()==0);
    assert(sawSleepingNpc && D_5876==1 && D_5878==-1);
    /* Double-click an NPC across a table, then use the real Talk handler. */
    MOUSE_SetCommandInput(true);D_5c5a[1]._2_x=16;D_5c5a[1]._3_y=14;
    GetMap(16,15)=TILE_MAP_TABLE_94;GetMap(16,14)=TILE_MAP_BED;
    MOUSE_Button(384,307.2f,SDL_BUTTON_LEFT,true,1);
    MOUSE_Button(384,307.2f,SDL_BUTTON_LEFT,true,2);
    assert(MOUSE_PollCommand()=='T');MOUSE_SetCommandInput(false);sawSleepingNpc=false;
    assert(TALK_041c_TalkCmd()==0);assert(sawSleepingNpc && D_5876==1 && D_5878==-1);
    /* The equivalent typed direction resolves the same actor and distance. */
    extern void KEY_SDL_ProcessKeyDown(SDL_KeyboardEvent ev);
    extern void KEY_SDL_ClearInput(void);
    SDL_KeyboardEvent up={0};up.key=SDLK_UP;KEY_SDL_ProcessKeyDown(up);sawSleepingNpc=false;
    assert(TALK_041c_TalkCmd()==0);assert(sawSleepingNpc && D_5876==1 && D_5878==-1);
    KEY_SDL_ClearInput();D_5c5a[1]._0_tile=0;
    /* A typed action accepts one click at its direction prompt, with no delay. */
    SDL_Event directionClick={0};directionClick.type=SDL_EVENT_MOUSE_BUTTON_DOWN;
    directionClick.button.button=SDL_BUTTON_LEFT;directionClick.button.clicks=1;
    directionClick.button.x=384;directionClick.button.y=307.2f;
    D_5c5a[1]._0_tile=0x44;sawSleepingNpc=false;
    assert(SDL_PushEvent(&directionClick));assert(TALK_041c_TalkCmd()==0);
    assert(sawSleepingNpc && D_5876==1 && D_5878==-1);
    assert(MOUSE_PollCommand()==0);
    /* General direction prompts accept neighbors, but not Talk's extended reach. */
    MOUSE_BeginDirectionInput(false);
    MOUSE_Button(384,307.2f,SDL_BUTTON_LEFT,true,1);assert(MOUSE_PollCommand()==0);
    MOUSE_Button(448,384,SDL_BUTTON_LEFT,true,1);assert(MOUSE_PollCommand()==U5_KEY_PGUP);
    MOUSE_EndDirectionInput();MOVEMENT_SetDiagonal(false);
    MOUSE_BeginDirectionInput(false);
    MOUSE_Button(448,384,SDL_BUTTON_LEFT,true,1);assert(MOUSE_PollCommand()==0);
    MOUSE_Button(384,384,SDL_BUTTON_LEFT,true,1);assert(MOUSE_PollCommand()==U5_KEY_UP);
    MOUSE_EndDirectionInput();MOVEMENT_SetDiagonal(true);
    directionClick.button.x=448;directionClick.button.y=460.8f;
    assert(SDL_PushEvent(&directionClick));assert(ULTIMA_35ec_SelectDirection()==1);
    assert(D_5876==1 && D_5878==0 && MOUSE_PollCommand()==0);
    KEY_SDL_ProcessKeyDown(up);assert(ULTIMA_35ec_SelectDirection()==1);
    assert(D_5876==0 && D_5878==-1);KEY_SDL_ClearInput();
    SDL_KeyboardEvent cancelDirection={0};cancelDirection.key=SDLK_ESCAPE;
    KEY_SDL_ProcessKeyDown(cancelDirection);assert(ULTIMA_35ec_SelectDirection()==0);KEY_SDL_ClearInput();
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);assert(MOUSE_PollCommand()==0);
    D_5c5a[1]._0_tile=0;
    /* Food plates obey the same direction-dependent reach as Get. */
    GetMap(16,15)=TILE_MAP_TABLE_9B;assert(MOUSE_Action(0,-1,true)=='G');
    GetMap(16,15)=TILE_MAP_TABLE_9A;assert(MOUSE_Action(0,-1,true)=='L');
    GetMap(16,17)=TILE_MAP_TABLE_9A;assert(MOUSE_Action(0,1,true)=='G');
    GetMap(17,16)=TILE_MAP_TABLE_9C;assert(MOUSE_Action(1,0,true)=='L');
    GetMap(16,17)=TILE_MAP_TABLE_9C;assert(MOUSE_Action(0,1,true)=='G');
    int food=D_57a8;
    GetMap(16,17)=TILE_MAP_TABLE_9A;MOUSE_SetCommandInput(true);
    MOUSE_Button(384,537.6f,SDL_BUTTON_LEFT,true,1);
    MOUSE_Button(384,537.6f,SDL_BUTTON_LEFT,true,2);
    assert(MOUSE_PollCommand()=='G');MOUSE_SetCommandInput(false);SJOG_18ce_GetCmd();
    assert(GetMap(16,17)==TILE_MAP_TABLE_95 && D_57a8==food+1);D_57a8=food;
    D_5893_map_id=0;
    byte* palace=ULTIMA_4402_GetTileAddr(D_5896_map_x,D_5897_map_y);byte previous=*palace;
    /* Every tile accepted by the keyboard Enter command also double-clicks
     * to Enter while standing on it, including the Brittany village tile. */
    const byte entrances[]={TILE_MAP_HUT,TILE_MAP_CODEX,TILE_MAP_KEEP,TILE_MAP_VILLAGE,
        TILE_MAP_TOWNE,TILE_MAP_CASTLE,TILE_MAP_CAVE,TILE_MAP_MINE,TILE_MAP_DUNGEON,
        TILE_MAP_SHRINE,TILE_MAP_RUINS,TILE_MAP_LIGHTHOUSE,TILE_MAP_PALACEBT,TILE_MAP_CASTLELB};
    for(unsigned i=0;i<sizeof(entrances);i++) {
        *palace=entrances[i];assert(MOUSE_Action(0,0,true)=='E');
        MOUSE_SetCommandInput(true);MOUSE_Cancel();
        MOUSE_Button(384,460.8f,SDL_BUTTON_LEFT,true,1);
        MOUSE_Button(384,460.8f,SDL_BUTTON_LEFT,true,2);
        assert(MOUSE_PollCommand()=='E');
        assert(MOUSE_PollCommand()==0);
    }
    *palace=TILE_MAP_GRASS;assert(MOUSE_Action(0,0,true)==0);
    /* Occupied transport takes priority over entering the underlying tile.
     * Every orientation routes double-clicks through the normal X-it command. */
    byte previousPartyTile=D_587c_partyTile;
    const byte transports[]={TILE_ACTOR_RIDING_HORSE,TILE_ACTOR_RIDING_HORSE+1,
        TILE_ACTOR_FLYING_CARPET,TILE_ACTOR_FRIGATE_20,TILE_ACTOR_FRIGATE_20+1,
        TILE_ACTOR_FRIGATE_20+2,TILE_ACTOR_FRIGATE_20+3,TILE_ACTOR_FRIGATE_24,
        TILE_ACTOR_FRIGATE_24+1,TILE_ACTOR_FRIGATE_24+2,TILE_ACTOR_FRIGATE_24+3,
        TILE_ACTOR_SKIFF,TILE_ACTOR_SKIFF_29};
    *palace=TILE_MAP_VILLAGE;
    for(unsigned i=0;i<sizeof(transports);i++) {
        D_587c_partyTile=transports[i];
        assert(MOUSE_Action(0,0,true)=='X');
        assert(MOUSE_Action(0,0,false)=='L');
        assert(MOUSE_Action(1,0,true)!='X');
        MOUSE_SetCommandInput(true);MOUSE_Cancel();
        MOUSE_Button(384,460.8f,SDL_BUTTON_LEFT,true,1);
        MOUSE_Button(384,460.8f,SDL_BUTTON_LEFT,true,2);
        assert(MOUSE_PollCommand()=='X');
        assert(MOUSE_PollCommand()==0);
        assert(MOUSE_TakeDirection()==0);
    }
    D_587c_partyTile=previousPartyTile;
    *palace=previous;D_5893_map_id=13;
    GetMap(16,16)=TILE_MAP_VILLAGE;
    assert(MOUSE_Action(0,0,true)==0); /* only overworld settlements enter */
    GetMap(16,16)=1;MOUSE_SetCommandInput(false);
    /* Far Look describes the exact target, without entering any action prompt. */
    GetMap(19,16)=TILE_MAP_FOUNTAIN;
    MOUSE_SetCommandInput(true);
    MOUSE_Button(576,460.8f,SDL_BUTTON_LEFT,true,1);
    ticks+=301;
    assert(MOUSE_PollCommand()=='L');
    MOUSE_SetCommandInput(false);
    LOOKOBJ_099c_LookCmd();
    assert(sawFountain && !sawDrinkPrompt);
    GetMap(19,16)=TILE_MAP_WELL;
    MOUSE_SetCommandInput(true);
    MOUSE_Button(576,460.8f,SDL_BUTTON_LEFT,true,1);
    ticks+=301;
    assert(MOUSE_PollCommand()=='L');
    MOUSE_SetCommandInput(false);
    int goldBefore=D_57aa;
    LOOKOBJ_099c_LookCmd();
    assert(sawWell && !sawCoinPrompt && D_57aa==goldBefore);
    /* Look resolves a custom NPC from any occupied cell, including extra slots,
     * and uses the singular type name rather than its vanilla base or plural. */
    unsigned char typeData[32 + 256 + 4 + 32 * 32 * 4 + 4 + 16 * 16 * 4] = {0};
    memcpy(typeData, "ITYPES01", 8);
    typeData[8] = 23;
    TYPES_Put32(typeData + 24, 1);
    TypeDef guardian;
    TYPES_Vanilla(1, 120, &guardian);
    guardian.id = 60000;
    guardian.width = guardian.height = 2;
    guardian.frames = 2;
    strcpy(guardian.name, "the Guardian");
    strcpy(guardian.description, "Guardians");
    TYPES_Encode(typeData + 32, &guardian);
    TYPES_Put32(typeData + 32, sizeof(typeData) - 32);
    typeData[32 + 257] = 16;
    typeData[32 + 258] = 100;
    const unsigned worldFrame = 32 + 256 + 4 + 32 * 32 * 4;
    typeData[worldFrame] = 6;
    typeData[worldFrame + 1] = 16;
    typeData[worldFrame + 2] = 100;
    assert(TYPES_Validate(typeData, sizeof(typeData)));
    TYPES_Mount(typeData, sizeof(typeData), NULL, 0);
    unsigned oldNpcCount = D_imperaNpcCount;
    D_imperaNpcCount = 258;
    D_5f5e[257]._0 = 1;
    D_5f5e[257]._c = 257;
    D_5c5a[257] = (ActorFmt){0};
    D_5c5a[257]._0_tile = D_5c5a[257]._1_animTile = 120;
    D_5c5a[257]._2_x = 19;
    D_5c5a[257]._3_y = 15;
    TypeCell guardianCell = {3, 13, 0, 1, 1, 60000, 0};
    assert(TYPES_Set(guardianCell, 60000));
    /* Custom artwork must not replace native furniture poses, including
     * the raw idle fallback used when drawing large actors. */
    const unsigned customIdle = ACTORS_Sprite(257, 256 + 120);
    assert(customIdle >= 512);
    GetMap(19,15)=TILE_MAP_BED;
    assert(ACTORS_Sprite(257,256+120)==256+TILE_ACTOR_SLEEPING_IN_BED);
    assert(ACTORS_Sprite(257,256+TILE_ACTOR_SLEEPING_IN_BED)==256+TILE_ACTOR_SLEEPING_IN_BED);
    const byte chairs[]={TILE_MAP_CHAIR_90,TILE_MAP_CHAIR_91,TILE_MAP_CHAIR_92,TILE_MAP_CHAIR_93};
    GetMap(19,14)=GetMap(19,16)=TILE_MAP_GRASS;
    for(unsigned facing=0;facing<4;facing++) {
        GetMap(19,15)=chairs[facing];
        assert(ACTORS_Sprite(257,256+120)==256+0x30+facing);
        assert(ACTORS_Sprite(257,256+0x30+facing)==256+0x30+facing);
    }
    GetMap(19,15)=TILE_MAP_GRASS;
    assert(ACTORS_Sprite(257,256+120)==customIdle);
    GetMap(20, 16) = 5;
    MOUSE_SetCommandInput(true);
    MOUSE_Button(640, 460.8f, SDL_BUTTON_LEFT, true, 1);
    ticks += 301;
    assert(MOUSE_PollCommand() == 'L');
    MOUSE_SetCommandInput(false);
    LOOKOBJ_099c_LookCmd();
    assert(sawGuardian);
    D_5c5a[257] = (ActorFmt){0};
    D_5f5e[257] = (NpcFmt){0};
    D_imperaNpcCount = oldNpcCount;
    TYPES_Mount(NULL, 0, NULL, 0);
    /* Artwork overrides must use the actual vanilla Look text source, not
     * either the singular or plural combat/type name. */
    unsigned char guardDefs[32 + 256] = {0};
    memcpy(guardDefs, "ITYPES01", 8);
    guardDefs[8] = 29;
    TYPES_Put32(guardDefs + 24, 1);
    TypeDef guard;
    TYPES_Vanilla(1, TILE_ACTOR_GUARD, &guard);
    strcpy(guard.name, "Guard");
    strcpy(guard.description, "Guards");
    TYPES_Encode(guardDefs + 32, &guard);
    assert(TYPES_Validate(guardDefs, sizeof(guardDefs)));
    TYPES_Mount(guardDefs, sizeof(guardDefs), NULL, 0);
    D_imperaNpcCount = 258;
    D_5f5e[257]._0 = 1;
    D_5f5e[257]._c = 257;
    D_5c5a[257] = (ActorFmt){0};
    D_5c5a[257]._0_tile = D_5c5a[257]._1_animTile = TILE_ACTOR_GUARD;
    D_5c5a[257]._2_x = 19;
    D_5c5a[257]._3_y = 16;
    const char *lookDirectory = transparentSprites ? "guard-look-transparent" : "guard-look-opaque";
    assert(SDL_CreateDirectory(lookDirectory));
    char lookPath[128];
    snprintf(lookPath, sizeof(lookPath), "%s/LOOK2.DAT", lookDirectory);
    for (int edited = 0; edited < 2; ++edited) {
        unsigned char lookBytes[1024 + 128] = {0};
        for (int frame = 0; frame < 4; ++frame) {
            int offset = (256 + TILE_ACTOR_GUARD + frame) * 2;
            lookBytes[offset] = 0;
            lookBytes[offset + 1] = 4;
        }
        const char *expected = edited ? "a royal guard" : "a guard";
        strcpy((char *)lookBytes + 1024, expected);
        FILE *file = fopen(lookPath, "wb");
        assert(file && fwrite(lookBytes, 1, sizeof(lookBytes), file) == sizeof(lookBytes));
        assert(!fclose(file));
        FILE_SetDataDirectory(lookDirectory);
        TYPES_Mount(guardDefs, sizeof(guardDefs), NULL, 0);
        assert(TYPES_Defined(guard.id) && ACTORS_Instance(257) == guard.id);
        for (int frame = 0; frame < 4; ++frame) {
            D_5c5a[257]._1_animTile = TILE_ACTOR_GUARD + frame;
            actorLook[0] = 0;
            MOUSE_SetCommandInput(true);
            MOUSE_Button(576, 460.8f, SDL_BUTTON_LEFT, true, 1);
            ticks += 301;
            assert(MOUSE_PollCommand() == 'L');
            MOUSE_SetCommandInput(false);
            LOOKOBJ_099c_LookCmd();
            assert(!strcmp(actorLook, expected));
        }
    }
    FILE_SetDataDirectory("");
    assert(!remove(lookPath));
    assert(SDL_RemovePath(lookDirectory));
    D_5c5a[257] = (ActorFmt){0};
    D_5f5e[257] = (NpcFmt){0};
    D_imperaNpcCount = oldNpcCount;
    TYPES_Mount(NULL, 0, NULL, 0);
    /* A diagonal fountain still offers drinking. Escape dismisses party selection. */
    GetMap(17,15)=TILE_MAP_FOUNTAIN;
    MOUSE_SetCommandInput(true);
    MOUSE_Button(448,384,SDL_BUTTON_LEFT,true,1);
    ticks+=301;
    assert(MOUSE_PollCommand()=='L');
    MOUSE_SetCommandInput(false);
    extern void KEY_SDL_ProcessKeyDown(SDL_KeyboardEvent ev);
    SDL_KeyboardEvent escape={0}; escape.key=SDLK_ESCAPE;
    KEY_SDL_ProcessKeyDown(escape);
    LOOKOBJ_099c_LookCmd();
    assert(sawDrinkPrompt);

    MOUSE_SetCommandInput(true);
    MOUSE_Cancel();
    MOUSE_SetCommandInput(false);
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);
    ticks+=400;
    assert(MOUSE_PollCommand()==0);
    MOUSE_SetCommandInput(true);
    MOUSE_Button(448,460.8f,SDL_BUTTON_LEFT,true,1);
    D_5896_map_x++;
    ticks+=400;
    assert(MOUSE_PollCommand()==0); /* discard stale click targets */
    D_5896_map_x--;
    /* Queued text preserves order, ignores unmapped keys, wraps, and clears. */
    KEY_SDL_ClearInput();
    for (int batch = 0; batch < 4; ++batch) {
        for (int i = 0; i < 80; ++i) {
            SDL_KeyboardEvent text = {0};
            text.key = SDLK_A + i % 26;
            KEY_SDL_ProcessKeyDown(text);
        }
        SDL_KeyboardEvent unknown = {0};
        unknown.key = SDLK_F12;
        KEY_SDL_ProcessKeyDown(unknown);
        for (int i = 0; i < 80; ++i)
            assert(KEY_PollKey() == 'a' + i % 26);
        assert(KEY_PollKey() == 0);
    }
    SDL_KeyboardEvent discarded = {0};
    discarded.key = SDLK_A;
    KEY_SDL_ProcessKeyDown(discarded);
    KEY_SDL_ClearInput();
    assert(KEY_PollKey() == 0);
    /* Perpendicular keyboard arrows use the same diagonal commands as mouse input. */
    extern void KEY_SDL_ReleaseKey(SDL_Keycode key);
    bool diagonalBefore=MOVEMENT_Diagonal();
    MOVEMENT_SetDiagonal(true);KEY_SDL_ClearInput();MOUSE_Cancel();
    const SDL_Keycode vertical[]={SDLK_UP,SDLK_UP,SDLK_DOWN,SDLK_DOWN};
    const SDL_Keycode horizontal[]={SDLK_LEFT,SDLK_RIGHT,SDLK_LEFT,SDLK_RIGHT};
    const int diagonals[]={U5_KEY_HOME,U5_KEY_PGUP,U5_KEY_END,U5_KEY_PGDN};
    const SDL_Keycode keypad[]={SDLK_KP_7,SDLK_KP_9,SDLK_KP_1,SDLK_KP_3};
    for(int i=0;i<4;i++) {
        SDL_KeyboardEvent press={0};KEY_SDL_ClearInput();
        press.key=vertical[i];KEY_SDL_ProcessKeyDown(press);
        press.key=horizontal[i];KEY_SDL_ProcessKeyDown(press);
        assert(KEY_PollKey()==diagonals[i]);
        KEY_SDL_ClearInput();press.key=keypad[i];KEY_SDL_ProcessKeyDown(press);
        assert(KEY_PollKey()==diagonals[i]);
    }
    KEY_SDL_ClearInput();MOVEMENT_SetDiagonal(false);
    SDL_KeyboardEvent chord={0};chord.key=SDLK_UP;KEY_SDL_ProcessKeyDown(chord);
    chord.key=SDLK_RIGHT;KEY_SDL_ProcessKeyDown(chord);assert(KEY_PollKey()==U5_KEY_RIGHT);
    KEY_SDL_ClearInput();MOVEMENT_SetDiagonal(true);GRAP_SDL_SetSmoothMovement(true);
    chord.key=SDLK_UP;KEY_SDL_ProcessKeyDown(chord);
    chord.key=SDLK_RIGHT;KEY_SDL_ProcessKeyDown(chord);assert(KEY_PollKey()==U5_KEY_PGUP);
    KEY_SDL_ReleaseKey(SDLK_RIGHT);ticks+=112;assert(KEY_PollKey()==U5_KEY_UP);
    KEY_SDL_ReleaseKey(SDLK_UP);ticks+=112;assert(KEY_PollKey()==0);
    KEY_SDL_ClearInput();GRAP_SDL_SetSmoothMovement(false);MOVEMENT_SetDiagonal(diagonalBefore);
    /* Smooth keyboard movement must not depend on OS repeat events, even
     * without an explicit movement-speed option. */
    assert(!GRAP_SDL_CustomMovementSpeed());
    GRAP_SDL_SetSmoothMovement(true);
    SDL_Event smoothKey={0};
    smoothKey.type=SDL_EVENT_KEY_DOWN;
    smoothKey.key.key=SDLK_RIGHT;
    SDL_PushEvent(&smoothKey);
    assert(KEY_PollKey()==U5_KEY_RIGHT);
    ticks+=111;
    assert(KEY_PollKey()==0);
    ticks++;
    assert(KEY_PollKey()==U5_KEY_RIGHT);
    ticks+=112;
    assert(KEY_PollKey()==U5_KEY_RIGHT);
    smoothKey.type=SDL_EVENT_KEY_UP;
    SDL_PushEvent(&smoothKey);
    ticks+=112;
    assert(KEY_PollKey()==0);
    GRAP_SDL_SetSmoothMovement(false);
    cursorX=448; cursorY=537.6f;
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_RIGHT,true,1);
    assert(MOUSE_PollCommand()==U5_KEY_PGDN);
    assert(MOUSE_PollCommand()==0);
    ticks+=160;
    assert(MOUSE_PollCommand()==U5_KEY_PGDN);
    GRAP_SDL_SetSmoothMovement(true);
    ticks+=111;
    assert(MOUSE_PollCommand()==0);
    ticks++;
    assert(MOUSE_PollCommand()==U5_KEY_PGDN);
    GRAP_SDL_SetMovementSpeed(2);
    ticks+=55;
    assert(MOUSE_PollCommand()==0);
    ticks++;
    assert(MOUSE_PollCommand()==U5_KEY_PGDN);
    GRAP_SDL_SetMovementSpeed(1);
    GRAP_SDL_SetSmoothMovement(false);
    ticks+=112;
    assert(MOUSE_PollCommand()==0); /* original cadence without smooth movement */
    cursorX=385; cursorY=460.8f; /* inside the player sprite, east of center */
    ticks+=160;
    assert(MOUSE_PollCommand()==U5_KEY_RIGHT);
    cursorX=384; /* exact center retains the displayed east cursor */
    ticks+=160;
    assert(MOUSE_PollCommand()==U5_KEY_RIGHT);
    cursorX=383; /* crossing the center immediately changes movement */
    ticks+=160;
    assert(MOUSE_PollCommand()==U5_KEY_LEFT);
    cursorX=1000; /* status column still never issues movement */
    ticks+=160;
    assert(MOUSE_PollCommand()==0);
    cursorX=4*4; cursorY=96*4.8f; ticks+=160;
    assert(MOUSE_PollCommand()==U5_KEY_LEFT); /* Blue frame remains a movement target. */
    cursorX=96*4; cursorY=188*4.8f; ticks+=160;
    assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_RIGHT,false,1);
    ticks+=160;
    assert(MOUSE_PollCommand()==0);
    GRAP_SDL_Cleanup();
    GRAP_SDL_SetFullscreen(true);
    GRAP_SDL_Initialize();
    byte* tiles=calloc(512,128);
    GRAP_BUF_LoadTileset(tiles);
    memset(D_5c5a,0,sizeof(D_5c5a));
    D_6a7e=0;
    D_b11e[0xd4]=0xd4;
    ANIMATION_SetSpeed(0.5f);
    ULTIMA_4552_AnimateActors();
    assert(D_6a7e==0 && D_b11e[0xd4]==0xd4);
    ULTIMA_4552_AnimateActors();
    assert(D_6a7e==1 && D_b11e[0xd4]==0xd5);
    ANIMATION_SetSpeed(2);
    ULTIMA_4552_AnimateActors();
    assert(D_6a7e==3 && D_b11e[0xd4]==0xd7);
    ANIMATION_SetSpeed(0.1f);
    for(int i=0;i<10;i++) ULTIMA_4552_AnimateActors();
    assert(D_6a7e==4 && D_b11e[0xd4]==0xd4);
    ANIMATION_SetSpeed(1);
    ULTIMA_4552_AnimateActors();
    assert(D_6a7e==5 && D_b11e[0xd4]==0xd5);
    /* Smooth rendering now samples actor art with an alpha mask, rather than
     * copying a square from the already-composited framebuffer. */
    memset(tiles + (256 + 0x44) * 128, 0xaa, 128);
    memset(tiles + (256 + 0x12) * 128, 0xee, 128);
    GetActorMap(5,5)=0x12;
    D_58a4=1; D_58a5=0;
    GRAP_SDL_FlushFrame();
    WideLayout l=WIDE_Layout(1024,768); /* dummy driver's desktop */
    float centerX=(1024-l.width*l.scale)/2+(l.mapX+(l.columns/2)*16+8)*l.scale;
    float centerY=(768-l.height*l.scaleY)/2+(l.mapY+(l.rows/2)*16+8)*l.scaleY;
    assert(GRAP_SDL_MouseMapPoint(centerX,centerY,&dx,&dy,&rx,&ry) && dx==0 && dy==0);
    assert(GRAP_SDL_MouseMapPoint(centerX+16*l.scale,centerY,&dx,&dy,&rx,&ry) && dx==1 && dy==0);
    assert(!GRAP_SDL_MouseMapPoint(1020,centerY,&dx,&dy,&rx,&ry));
    float canvasLeft=(1024-l.width*l.scale)/2.0f, canvasTop=(768-l.height*l.scaleY)/2.0f;
    float frameRight=canvasLeft+(l.sidebarX-4)*l.scale;
    assert(!GRAP_SDL_MouseMapPoint(frameRight,centerY,&dx,&dy,&rx,&ry));
    assert(GRAP_SDL_MouseMovementPoint(frameRight,centerY,&dx,&dy,&rx,&ry));
    assert(MOUSE_CursorDirection(frameRight,centerY)==U5_KEY_RIGHT);
    assert(GRAP_SDL_MouseMovementPoint(centerX,canvasTop+4*l.scaleY,&dx,&dy,&rx,&ry));
    assert(MOUSE_CursorDirection(centerX,canvasTop+4*l.scaleY)==U5_KEY_UP);
    assert(GRAP_SDL_MouseMovementPoint(centerX,canvasTop+(l.height-4)*l.scaleY,&dx,&dy,&rx,&ry));
    assert(!GRAP_SDL_MouseMovementPoint(canvasLeft+l.sidebarX*l.scale,centerY,&dx,&dy,&rx,&ry));

    int cursorWidth,cursorHeight;
    GRAP_SDL_CursorSize(&cursorWidth,&cursorHeight);
    assert(cursorWidth==48 && cursorHeight==58);
    /* Menu coordinates follow the shifted sidebar in expanded fullscreen. */
    float uiX,uiY;
    float sidebarX=(1024-l.width*l.scale)/2+(l.sidebarX+8)*l.scale;
    assert(GRAP_SDL_MouseUIPoint(sidebarX,(768-l.height*l.scaleY)/2+24*l.scaleY,&uiX,&uiY));
    assert(SDL_fabsf(uiX-200)<0.001f && SDL_fabsf(uiY-24)<0.001f);
    cursorX=sidebarX; cursorY=(768-l.height*l.scaleY)/2+24*l.scaleY;
    MOUSE_MenuSet(192,8,120,3,0);
    assert(MOUSE_PollCommand()==U5_KEY_DOWN);
    MOUSE_MenuEnd(); MOUSE_Cancel();
    GRAP_SDL_SetMovementSpeed(2);
    assert(GRAP_SDL_MovementInterval()==80);
    SDL_Event keyEvent={0};
    keyEvent.type=SDL_EVENT_KEY_DOWN;
    keyEvent.key.key=SDLK_DOWN;
    SDL_PushEvent(&keyEvent);
    assert(KEY_PollKey()==U5_KEY_DOWN);
    ticks+=79;
    assert(KEY_PollKey()==0);
    ticks++;
    assert(KEY_PollKey()==U5_KEY_DOWN);
    keyEvent.type=SDL_EVENT_KEY_UP;
    SDL_PushEvent(&keyEvent);
    ticks+=80;
    assert(KEY_PollKey()==0);
    GRAP_SDL_SetMovementSpeed(1);
    GRAP_SDL_SetSmoothMovement(true);
    assert(GRAP_SDL_MovementInterval()==112);
    ANIMATION_SetSpeed(2);
    GRAP_SDL_SetMovementSpeed(2);
    assert(GRAP_SDL_MovementInterval()==56);
    memset(g_linearEgaBuffer0,0,320*200);
    g_linearEgaBuffer0[0]=10;
    for (int y=8;y<184;y++) memset(g_linearEgaBuffer0+y*320+40,12,4);
    for (int y=88;y<104;y++) memset(g_linearEgaBuffer0+y*320+88,14,16);
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    presented=0;
    D_5896_map_x++;
    for (int y=8;y<184;y++) {
        memset(g_linearEgaBuffer0+y*320+40,0,4);
        memset(g_linearEgaBuffer0+y*320+24,12,4);
    }
    animationRow=(int)centerY;
    playerScreenX=(int)centerX;
    previousMarkerX=(l.mapX+(l.columns/2-5)*16+32)*l.scale;
    int initialMarkerX=previousMarkerX;
    checkAnimation=true;
    animationDelay=0;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    checkAnimation=false;
    assert(presented==9); /* eight intermediate frames plus the completed frame */
    assert(animationDelay==56); /* transition duration matches held movement cadence */
    GRAP_SDL_SetMovementSpeed(1);
    ANIMATION_SetSpeed(1);
    assert(previousMarkerX==initialMarkerX-16*l.scale);
    presented=0;
    D_5896_map_x+=5;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    assert(presented==1); /* teleport snaps rather than sliding across the map */
    presented=0;
    GRAP_SDL_SetSmoothMovement(false);
    D_5896_map_x++;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    assert(presented==1);
    /* A diagonal transition must cover both corner gaps, and must not splice
     * together different animation phases from the old and current frames. */
    D_5893_map_id=0;D_5895_map_level=0;D_5896_map_x=100;D_5897_map_y=100;D_58a5=50;
    memset(D_6608_map.raw,1,sizeof(D_6608_map.raw));
    D_589b=90;D_589c=90;
    /* Supply water chunks instead of mutating the engine's default map index. */
    FILE *waterFile=FILE_Open("BRIT.DAT","wb");assert(waterFile);
    for(int i=0;i<65536;i++) assert(fputc(1,waterFile)!=EOF);
    assert(!fclose(waterFile));
    memset(D_5c5a,0,sizeof(D_5c5a));
    D_b11e[1]=1;
    waterMap=(SDL_Rect){(1024-l.width*l.scale)/2+l.mapX*l.scale,(768-l.height*l.scaleY)/2+l.mapY*l.scaleY,l.columns*16*l.scale,l.rows*16*l.scaleY};
    for(int stepY=-1;stepY<=1;stepY+=2) for(int stepX=-1;stepX<=1;stepX+=2) {
        D_5896_map_x=100;D_5897_map_y=100;
        memset(tiles+128,0x11,128);memset(g_linearEgaBuffer0,1,320*200);
        GRAP_SDL_SetSmoothMovement(true); /* reset interpolation history */
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
        memset(tiles+128,0x33,128);memset(g_linearEgaBuffer0,3,320*200);
        /* A contrasting frame must never be sampled into scrolling terrain. */
        memset(g_linearEgaBuffer0,4,320*8);
        memset(g_linearEgaBuffer0+184*320,4,320*8);
        D_5896_map_x+=stepX;D_5897_map_y+=stepY;
        checkWater=true;presented=0;
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
        checkWater=false;assert(presented==9);
    }
    /* Expanded edges must wait for a complete map redraw, just as the original
     * central 11x11 tiles do, even if position/light globals already changed. */
    for(int smooth=0;smooth<2;smooth++) {
        GRAP_SDL_SetSmoothMovement(smooth!=0);
        D_58a5=50;D_5896_map_x=100;D_5897_map_y=100;
        memset(tiles+128,0x11,128);memset(g_linearEgaBuffer0,1,320*200);
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
        D_58a5=2;D_5896_map_x++;D_5897_map_y++;
        edgeBright=true;checkEdges=true;GRAP_SDL_FlushFrame();checkEdges=false;
        edgeBright=false;checkEdges=true;
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame(); /* completed night map replaces snapshot */
        D_58a5=50;GRAP_SDL_FlushFrame(); /* retain darkness until daylight redraw */
        checkEdges=false;edgeBright=true;checkEdges=true;
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
        checkEdges=false;
    }
    /* Both visibility modes follow scrolling terrain in all eight directions. */
    GRAP_BUF_SetTransparentSprites(false);
    memset(tiles+(256+GetActorMap(5,5))*128,0x11,128);
    D_58a5=2;memset(tiles+128,0x11,128);
    for(int yy=0;yy<11;yy++) for(int xx=0;xx<11;xx++) {
        bool visible=(xx-5)*(xx-5)+(yy-5)*(yy-5)<=2;
        GetMapViewport(xx,yy)=visible?1:255;
        for(int py=0;py<16;py++) memset(g_linearEgaBuffer0+(8+yy*16+py)*320+8+xx*16,visible?1:0,16);
    }
    lightX=waterMap.x+(l.columns/2-1)*16*l.scale+2;
    lightY=waterMap.y+(l.rows/2)*16*l.scaleY+8*l.scaleY;
    darkX=waterMap.x+(l.columns/2-2)*16*l.scale+8*l.scale;
    /* Also test daylight with an occluded central mask: the engine's LOS
     * result must win over the expanded view's independent visibility test. */
    for(int lighting=0;lighting<2;lighting++)
    for(int sy=-1;sy<=1;sy++) for(int sx=-1;sx<=1;sx++) {
        if(!sx && !sy) continue;
        D_58a5=lighting?50:2;
        D_5896_map_x=100;D_5897_map_y=100;GRAP_SDL_SetSmoothMovement(true);
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
        D_5896_map_x+=sx;D_5897_map_y+=sy;
        checkDarkness=true;presented=0;ditherDx=sx;ditherDy=sy;
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
        checkDarkness=false;assert(presented==9);
    }
    D_58a5=2;
    WIDE_SetDitheredDarkness(true);
    /* Isolate the mask from the stationary player's outline at the probe. */
    GRAP_BUF_SetTransparentSprites(false);
    memset(tiles+(256+GetActorMap(5,5))*128,0x11,128);
    checkDither=true;ditherDx=ditherDy=0;GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
    for(int sy=-1;sy<=1;sy++) for(int sx=-1;sx<=1;sx++) {
        if(!sx && !sy) continue;
        ditherDx=sx;ditherDy=sy;presented=0;
        darkStepStarted=SDL_GetPerformanceCounter();
        D_5896_map_x+=sx;D_5897_map_y+=sy;
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();assert(presented==9);
    }
    checkDither=false;
    printf("Dithered movement preparation: %.3f ms/step (%u steps)\n",
           1000.0*darkPreparationTicks/SDL_GetPerformanceFrequency()/darkSteps,darkSteps);
    darkPreparationTicks=0;darkSteps=0;
    GRAP_BUF_SetTransparentSprites(true);
    profileMaskWidth=(l.columns+2)*16;profileMaskHeight=(l.rows+2)*16;
    profileDark=true;
    for(int step=0;step<8;step++) {
        presented=0;darkStepStarted=SDL_GetPerformanceCounter();
        D_5896_map_x+=(step&1)?-1:1;
        GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();assert(presented==9);
    }
    profileDark=false;
    assert(scrollingTextureAllocations==0); /* Steady movement reuses upload storage. */
    assert(darknessUploads==0); /* Constant torch visibility needs no repeated mask uploads. */
    assert(hiddenTerrainSamples==0); /* Darkness must not reconstruct invisible terrain. */
    printf("Transparent dithered movement preparation: %.3f ms/step\n",
           1000.0*darkPreparationTicks/SDL_GetPerformanceFrequency()/darkSteps);
    GRAP_BUF_SetTransparentSprites(transparentSprites);
    WIDE_SetDitheredDarkness(false);
    CRT_SetEnabled(true);GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
    checkCRT=true;presented=0;D_5896_map_x++;D_5897_map_y++;
    GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();assert(presented==9);
    checkCRT=false;
    /* Rendering time is part of each movement interval, not extra delay. */
    renderCost=6;animationDelay=0;presented=0;D_5896_map_x++;
    GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
    assert(presented==9 && animationDelay==70);
    renderCost=20;animationDelay=0;presented=0;D_5897_map_y++;
    GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
    assert(presented==9 && animationDelay==0); /* don't wait when over budget */
    renderCost=0;CRT_SetEnabled(false);
    D_58a5=50;
    D_5893_map_id=1;D_5896_map_x=16;D_5897_map_y=16;
    memset(D_6608_map.town,1,sizeof(D_6608_map.town));
    D_b11e[1]=1;
    memset(tiles+128,0x11,128);
    /* A transparent hole must reveal scrolling ground, surrounded by black. */
    for(int y=3;y<=6;y++) for(int x=6;x<=9;x++) {
        byte* packed=&tiles[(256+0x44)*128+y*8+x/2];
        *packed &= x&1?0xf0:0x0f;
    }
    /* Moving NPC, then an NPC moving together with the scrolling camera. */
    GRAP_SDL_SetSmoothMovement(true);
    D_5896_map_x=16;
    paintActor(1,13,14);
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    actorStart=(l.mapX+(l.columns/2-3)*16)*l.scale;
    actorEnd=actorStart+48; actorMarker=actorStart;
    actorRow=(l.mapY+(l.rows/2-2)*16+8)*l.scaleY;
    paintActor(1,14,14);
    presented=0; checkActor=true;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    checkActor=false;
    assert(presented==9 && actorMarker==actorEnd);
    actorStart=actorEnd; actorMarker=actorStart;
    D_5896_map_x++;
    paintActor(1,15,14);
    presented=0; checkActor=true;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    checkActor=false;
    assert(presented==9 && actorMarker==actorEnd);
    /* Combat does not pan when active-character coordinates change. */
    D_5893_map_id=255;
    paintActor(7,2,3);
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    actorStart=(l.mapX+(l.columns/2-3)*16)*l.scale;
    actorEnd=actorStart+48; actorMarker=actorStart;
    actorRow=(l.mapY+(l.rows/2-2)*16+8)*l.scaleY;
    D_5896_map_x=3;
    paintActor(7,3,3);
    presented=0; checkActor=true;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    checkActor=false;
    assert(presented==9 && actorMarker==actorEnd);
    GRAP_SDL_SetSmoothMovement(true);
    paintActor(0,2,3);
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    paintActor(0,3,3);
    presented=0;
    GRAP_SDL_MapDrawn(); GRAP_SDL_FlushFrame();
    assert(presented==9); /* combat party members animate too */
    /* Centered combat margins stay black throughout interpolation, rather
     * than exposing the padded terrain used for world-map scrolling. */
    int windowCount;
    SDL_Window** windows=SDL_GetWindows(&windowCount);
    assert(windows && windowCount==1);
    SDL_Window* combatWindow=windows[0];SDL_free(windows);
    assert(SDL_SetWindowFullscreen(combatWindow,false));
    assert(SDL_SetWindowSize(combatWindow,1024,720));
    D_5896_map_x=D_5897_map_y=3;
    for(int y=0;y<11;y++) for(int x=0;x<11;x++) GetCombatMap(x,y)=1;
    D_b11e[1]=1;memset(tiles+128,0x11,128);
    GRAP_SDL_SetSmoothMovement(true);
    paintActor(0,2,3);
    GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
    paintActor(0,3,3);presented=0;checkCombatMargins=true;
    GRAP_SDL_MapDrawn();GRAP_SDL_FlushFrame();
    checkCombatMargins=false;assert(presented==9);
    assert(SDL_SetWindowSize(combatWindow,1024,768));
    /* Right-button combat commands use the active fighter, not the map center. */
    GRAP_SDL_SetSmoothMovement(false);
    D_5896_map_x=2; D_5897_map_y=3;
    D_589e=0;D_ba14[0].x=2;D_ba14[0].y=3;
    float fighterX=centerX+(2-5)*16*l.scale;
    float fighterY=centerY+(3-5)*16*l.scaleY;
    cursorX=fighterX+1; cursorY=fighterY;
    MOUSE_SetCommandInput(true);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_RIGHT,true,1);
    assert(MOUSE_PollCommand()==U5_KEY_RIGHT);
    MOUSE_SetCommandInput(false);
    ticks+=160;
    assert(MOUSE_PollCommand()==0); /* target prompts and enemy turns */
    MOUSE_SetCommandInput(true);
    cursorX=fighterX-48; cursorY=fighterY-48;
    assert(MOUSE_PollCommand()==U5_KEY_HOME);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_RIGHT,false,1);
    ticks+=160;
    assert(MOUSE_PollCommand()==0);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    ticks+=301;
    assert(MOUSE_PollCommand()==0); /* single clicks wait for Attack/Aim mode */
    memset(D_5c5a,0,sizeof(D_5c5a));
    memset(D_ba14,0,sizeof(D_ba14));
    for (int cy=0;cy<11;cy++) for (int cx=0;cx<11;cx++) GetCombatMap(cx,cy)=TILE_MAP_GRASS;
    D_ba14[0].x=5; D_ba14[0].y=5; D_ba14[0].actorIdx=1;
    D_5c5a[1]._0_tile=D_5c5a[1]._1_animTile=0x44;
    D_5c5a[1]._2_x=5; D_5c5a[1]._3_y=5;
    D_58a1=0;
    assert(SJOG_1c56_CombatMovePlayer(0,U5_KEY_PGUP)==1);
    assert(D_ba14[0].x==6 && D_ba14[0].y==4);
    GetCombatMap(7,4)=0xff;
    assert(SJOG_1c56_CombatMovePlayer(0,U5_KEY_PGDN)==1);
    assert(D_ba14[0].x==6 && D_ba14[0].y==5); /* slide south past the east blocker */
    assert(SJOG_1c56_CombatMovePlayer(0,U5_KEY_PGDN)==1);
    assert(D_ba14[0].x==7 && D_ba14[0].y==6); /* same intent resumes diagonal movement */
    D_ba14[0].x=D_5c5a[1]._2_x=6;
    D_ba14[0].y=D_5c5a[1]._3_y=4;
    MOVEMENT_SetDiagonal(false);
    GetCombatMap(7,4)=TILE_MAP_GRASS;
    assert(SJOG_1c56_CombatMovePlayer(0,U5_KEY_PGDN)==0);
    assert(D_ba14[0].x==6 && D_ba14[0].y==4);
    assert(COMSUBS_0822(0,7,5,1,0)==-1); /* no diagonal projectile or its effects */
    int hpBefore=D_ba14[1].hp;
    D_ba14[1].x=7; D_ba14[1].y=5;
    COMSUBS_0bf8(0,1,0);
    assert(D_ba14[1].hp==hpBefore); /* no diagonal melee */
    D_ba14[1].flags=COMBAT_FLAGS_MONSTER;
    D_ba14[1].actorIdx=2;
    D_5c5a[2]._1_animTile=0x44;
    D_589e=0; D_589d=25; D_588f=0;
    MOVEMENT_SetDiagonal(true);
    assert(COMSUBS_0822(0,7,5,1,0)==1); /* diagonal attack reaches its target */
    MOVEMENT_SetDiagonal(false);
    assert(COMSUBS_0822(0,7,5,1,0)==-1);

    /* Direction prompts and cursor orientation follow the active combatant,
     * even before the legacy map-position globals catch up with a turn change. */
    D_589e=0; D_ba14[0].x=2; D_ba14[0].y=8;
    D_5896_map_x=5; D_5897_map_y=5;
    MOVEMENT_SetDiagonal(true);
    fighterX=centerX-3*16*l.scale;fighterY=centerY+3*16*l.scaleY;
    assert(MOUSE_CursorDirection(fighterX+16*l.scale,fighterY)==U5_KEY_RIGHT);
    assert(MOUSE_CursorDirection(fighterX,fighterY-16*l.scaleY)==U5_KEY_UP);
    MOUSE_BeginDirectionInput(false);
    MOUSE_Button(fighterX+16*l.scale,fighterY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==U5_KEY_RIGHT);
    MOUSE_Button(centerX,centerY-16*l.scaleY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==0); /* adjacent to map center, far from fighter */
    MOUSE_EndDirectionInput();
    D_589e=1; D_ba14[1].x=8; D_ba14[1].y=2;
    fighterX=centerX+3*16*l.scale;fighterY=centerY-3*16*l.scaleY;
    assert(MOUSE_CursorDirection(fighterX-16*l.scale,fighterY)==U5_KEY_LEFT);
    MOUSE_BeginDirectionInput(false);
    MOUSE_Button(fighterX-16*l.scale,fighterY+16*l.scaleY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==U5_KEY_END);
    MOUSE_EndDirectionInput();
    D_ba14[0].x=6;D_ba14[0].y=4;
    MOVEMENT_SetDiagonal(false);

    /* Double-click combat loot uses the off-center active fighter and queues
     * the direction for the original Open/Get commands. */
    D_589e=0;D_ba14[0].flags=COMBAT_FLAGS_PLAYER;
    D_ba14[0].x=6;D_ba14[0].y=4;
    D_ba14[1].flags=0;
    D_5c5a[31]=(ActorFmt){0};
    D_5c5a[31]._2_x=7;D_5c5a[31]._3_y=4;
    MOUSE_SetCommandInput(true);
    const byte loot[]={TILE_ACTOR_CHEST,TILE_ACTOR_GOLD,TILE_ACTOR_WEAPON,TILE_ACTOR_FOOD};
    for(size_t i=0;i<sizeof(loot);i++) {
        D_5c5a[31]._0_tile=loot[i];
        int action=i?'G':'O';
        assert(MOUSE_Action(2,-1,true)==action);
        MOUSE_Button(centerX+2*16*l.scale,centerY-16*l.scaleY,SDL_BUTTON_LEFT,true,1);
        MOUSE_Button(centerX+2*16*l.scale,centerY-16*l.scaleY,SDL_BUTTON_LEFT,true,2);
        assert(MOUSE_PollCommand()==action);
        int tx,ty;assert(MOUSE_TakeTarget(&tx,&ty));assert(tx==1 && ty==0);
        D_5c5a[31]._2_x=8;
        assert(MOUSE_Action(3,-1,true)==0); /* out of reach */
        D_5c5a[31]._2_x=7;D_5c5a[31]._3_y=5;
        MOVEMENT_SetDiagonal(false);assert(MOUSE_Action(2,0,true)==0);
        MOVEMENT_SetDiagonal(true);assert(MOUSE_Action(2,0,true)==action);
        D_5c5a[31]._3_y=4;
    }
    D_5c5a[31]=(ActorFmt){0};MOUSE_SetCommandInput(false);
    MOVEMENT_SetDiagonal(false);
    /* Real mouse targeting preserves cardinal range rules and requires a separate confirmation. */
    D_589e=0; D_ba14[0].flags=COMBAT_FLAGS_PLAYER;
    D_ba14[0].entityIdx=0; D_5896_map_x=6; D_5897_map_y=4;
    D_55a8_party[0].equips[0]=D_55a8_party[0].equips[2]=D_55a8_party[0].equips[3]=0xff;
    D_ba14[1].flags=COMBAT_FLAGS_MONSTER; D_ba14[1].x=7; D_ba14[1].y=4;
    D_5c5a[2]._0_tile=D_5c5a[2]._1_animTile=0x44;
    assert(MOUSE_Action(2,-1,true)=='A'); /* tile 7,4, one east of active fighter */
    D_ba14[1].x=8;
    assert(MOUSE_Action(3,-1,true)==0); /* bare hands cannot reach two tiles */
    D_ba14[1].x=7; D_ba14[1].y=5;
    assert(MOUSE_Action(2,0,true)==0); /* classic diagonal attack */
    MOVEMENT_SetDiagonal(true);
    assert(MOUSE_Action(2,0,true)=='A');
    D_ba14[1].flags|=COMBAT_FLAGS_INVISIBLE;
    assert(MOUSE_Action(2,0,true)==0);
    D_ba14[1].flags=COMBAT_FLAGS_PLAYER;
    assert(MOUSE_Action(2,0,true)==0); /* friendly target */
    D_ba14[1].flags=COMBAT_FLAGS_MONSTER;
    cursorX=centerX+2*16*l.scale; cursorY=centerY;
    MOUSE_SetCommandInput(true);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,2);
    assert(MOUSE_PollCommand()=='A');
    MOUSE_SetCommandInput(false);
    int seededDistance;
    assert(MOUSE_CombatAttackTarget(0,1,&seededDistance) && seededDistance==1);
    MOUSE_SetCombatAimInput(0,1);
    assert(MOUSE_PollCommand()==0); /* double-click only seeds Aim, never confirms it */
    MOUSE_Button(1020,cursorY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==0); /* sidebar cannot confirm */
    MOUSE_Button(cursorX+48,cursorY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==0); /* out-of-range click keeps Aim open */
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==U5_KEY_ENTER);
    assert(MOUSE_PollCommand()==0);
    MOUSE_EndCombatAimInput();
    /* Run the real Aim loop: inject a distinct click when the Aim loop polls events. */
    confirmAimOnPoll=true;
    assert(COMSUBS_0504(0,1)==1);
    assert(!confirmAimOnPoll);
    assert(D_5899==7 && D_589a==5);
    assert(COMSUBS_0504(0,0)==0); /* second weapon must satisfy its own range */
    SDL_KeyboardEvent cancelAim={0}; cancelAim.key=SDLK_ESCAPE;
    KEY_SDL_ProcessKeyDown(cancelAim);
    assert(COMSUBS_0504(0,1)==0); /* Escape exits the native Aim prompt */
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    assert(MOUSE_PollCommand()==0); /* no Aim confirmation leaks into command entry */
    MOUSE_ClearCombatAttack();
    int unusedDistance;
    assert(!MOUSE_CombatAttackTarget(0,1,&unusedDistance));
    MOUSE_SetCommandInput(true);
    MOUSE_Button(cursorX,cursorY,SDL_BUTTON_LEFT,true,1);
    D_589e=1;
    ticks+=301;
    assert(MOUSE_PollCommand()==0); /* queued clicks cannot transfer to another fighter */
    D_589e=0;
    /* Exercise real AI movement for both enemy and friendly entities. */
    for (int friendly=0;friendly<2;friendly++) {
        memset(D_ba14,0,sizeof(D_ba14));
        memset(D_5c5a,0,sizeof(D_5c5a));
        D_ba14[0].flags=friendly ? COMBAT_FLAGS_MONSTER : COMBAT_FLAGS_PLAYER;
        D_ba14[0].actorIdx=1; D_ba14[0].x=8; D_ba14[0].y=8;
        D_ba14[1].flags=friendly ? COMBAT_FLAGS_PLAYER : COMBAT_FLAGS_MONSTER;
        D_ba14[1].actorIdx=2; D_ba14[1].x=5; D_ba14[1].y=5;
        D_ba14[1].entityIdx=8;
        D_5c5a[1]._0_tile=D_5c5a[1]._1_animTile=0x44;
        D_5c5a[1]._2_x=8; D_5c5a[1]._3_y=8;
        D_5c5a[2]._0_tile=D_5c5a[2]._1_animTile=0x44;
        D_5c5a[2]._2_x=5; D_5c5a[2]._3_y=5;
        D_587a='N';
        MOVEMENT_SetDiagonal(true);
        assert(COMBAT_0ee4(1)==1);
        assert(D_ba14[1].x==6 && D_ba14[1].y==6);
        D_ba14[1].x=D_5c5a[2]._2_x=5;
        D_ba14[1].y=D_5c5a[2]._3_y=5;
        MOVEMENT_SetDiagonal(false);
        assert(COMBAT_0ee4(1)==1);
        assert(abs(D_ba14[1].x-5)+abs(D_ba14[1].y-5)==1);
    }
    /* Both moving and stationary combat actors participate in depth ordering.
     * Check every interpolation frame, both slot orders, both movement roles,
     * and the selection overlay above the same overlap. */
    D_5893_map_id = 255;
    D_13b0_brightWhiteColor = 15;
    D_52ba_vdp._52c8_videoDriverSelection = VDP_VIDEO_EGA;
    D_52ba_vdp._52c4 = 0;
    D_5896_map_x = D_5897_map_y = 5;
    D_58a4 = 1;
    D_58a5 = 50;
    D_b11e[1] = 1;
    memset(D_ad14, 1, sizeof(D_ad14));
    memset(tiles + (256 + 0x44) * 128, 0xaa, 128);
    memset(tiles + (256 + 0x48) * 128, 0x44, 128);
    for (int swap = 0; swap < 2; ++swap)
        for (int southMoves = 0; southMoves < 2; ++southMoves)
            for (int selected = 0; selected < 2; ++selected) {
                int north = swap ? 31 : 0, south = swap ? 0 : 31;
                GRAP_SDL_SetSmoothMovement(true);
                memset(D_5c5a, 0, sizeof(D_5c5a));
                memset(D_ba14, 0, sizeof(D_ba14));
                D_5c5a[north]._0_tile = D_5c5a[north]._1_animTile = 0x48;
                D_5c5a[north]._2_x = southMoves ? 3 : 2;
                D_5c5a[north]._3_y = 3;
                D_5c5a[south]._0_tile = D_5c5a[south]._1_animTile = 0x44;
                D_5c5a[south]._2_x = southMoves ? 2 : 3;
                D_5c5a[south]._3_y = 4;
                D_ba14[7].flags = COMBAT_FLAGS_PLAYER;
                D_ba14[7].actorIdx = south;
                D_ba14[7].entityIdx = 0;
                D_ba14[7].x = D_5c5a[south]._2_x;
                D_ba14[7].y = 4;
                D_589e = selected ? 7 : 255;
                D_589f = 0;
                memcpy(D_ab02, D_ad14, sizeof(D_ab02));
                ULTIMA_5394();
                ULTIMA_56ac_DrawMap();
                /* 255 can mark native combat cells/effects; it is not a
                 * world-map darkness classification. */
                *ULTIMA_4402_GetTileAddr(8,8)=255;
                for(int y=136;y<152;y++) memset(g_linearEgaBuffer0+y*320+136,12,16);
                if (selected)
                    paintCombatCursor(D_ba14[7].x, 4);
                GRAP_SDL_FlushFrame();
                D_5c5a[southMoves ? south : north]._2_x = 3;
                D_ba14[7].x = 3;
                D_589f = 0;
                memcpy(D_ab02, D_ad14, sizeof(D_ab02));
                ULTIMA_5394();
                ULTIMA_56ac_DrawMap();
                /* 255 can mark native combat cells/effects; it is not a
                 * world-map darkness classification. */
                *ULTIMA_4402_GetTileAddr(8,8)=255;
                for(int y=136;y<152;y++) memset(g_linearEgaBuffer0+y*320+136,12,16);
                if (selected)
                    paintCombatCursor(3, 4);
                if (selected)
                    assert(g_linearEgaBuffer0[72 * 320 + 60] == 15);
                orderMovingSouth = southMoves;
                orderSelection = selected;
                presented = 0;
                checkCombatOrder = true;
                GRAP_SDL_FlushFrame();
                checkCombatOrder = false;
                assert(presented == 9);
            }
    MOUSE_SetCommandInput(false);
    remove("BRIT.DAT");
    MOUSE_Cleanup();
    GRAP_SDL_Cleanup();
    syntheticMaskEnd(); SDL_Quit();
    puts("Mouse directions, action ranges, click timing, modal gating, and coordinate mapping passed.");
}
