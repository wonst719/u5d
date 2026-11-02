#include "mod/actors.h"
#include "mod/contents_game.h"
#include "crt.h"
#include "common/common.h"
#include "common/settings.h"
#include "common/icon.h"

#include "grap_buf.h"
#include "grap_ops.h"
#include "origin.h"
#include "wd.h"
#include "grap_sdl.h"
#include "widescreen.h"
#include "sprite_order.h"
#include "tileset.h"
#include "text/text_window.h"
#include "vars.h"
#include "funcs.h"
#include "macros.h"
#include "key/mouse.h"
#include "event/event.h"
#include <string.h>

#include <SDL3/SDL.h>

static SDL_Window* s_sdlWindow;
static SDL_Renderer* s_sdlRenderer;
static SDL_Surface* s_sdlSurface;
static SDL_Texture* s_sdlTexture;
static bool s_fullscreen;
static int s_videoMode;
static WideLayout VideoLayout(int width,int height)
{
    if(s_videoMode==GRAP_VIDEO_FULLSCREEN_43) {
        if(width*3>height*4) width=height*4/3;
        else height=width*3/4;
    }
    return WIDE_Layout(width,height);
}
static bool s_pixelUI;
static bool NativeGameplay(void)
{
    return s_videoMode==GRAP_VIDEO_FULLSCREEN_43 && !s_pixelUI &&
        !EVT_ImmediateExitEnabled() && D_58a4;
}
/* The native screen uses DOS 4:3 pixel aspect in this mode. */
static SDL_FRect NativeRect(int width,int height)
{
    if(s_videoMode==GRAP_VIDEO_FULLSCREEN_43) {
        float scale=SDL_min(width/320.0f,height/240.0f);
        float w=320*scale,h=240*scale;
        /* Gameplay occupies 192 rows; center it within the 200-row canvas. */
        return (SDL_FRect){(width-w)/2,(height-h)/2+(NativeGameplay()?h*4/200:0),w,h};
    }
    WideLayout l=VideoLayout(width,height);
    float w=320*l.scale,h=200*(s_videoMode==GRAP_VIDEO_FULLSCREEN?l.scaleY:l.scale);
    return (SDL_FRect){(width-w)/2,(height-h)/2,w,h};
}
static int s_windowedWidth=1280, s_windowedHeight=960;
static SDL_Texture* s_wideTexture;
static SDL_Texture* s_darknessTexture;
static SDL_Surface* s_wideSurface;
static byte* s_widePixels;
static byte* s_completedWidePixels;
static bool s_completedWideValid;
static int s_completedWideMap,s_completedWideLevel;
static bool s_expandedFrame;
static bool s_smoothMovement, s_mapDrawn, s_previousValid;
/* Keep turn uploads alive: deleting/recreating graphics resources while
 * their previous frames are in flight can stall the rendering driver. */
static SDL_Texture *s_scrollTerrain[2], *s_scrollPlayer[2], *s_darknessUploads[2];
static SDL_Texture **s_scrollActors[2];
static int s_scrollActorCapacity[2];
static SDL_Surface *s_scrollClean, *s_scrollPadded, *s_darknessSurface;
static unsigned s_scrollUpload, s_darknessUpload;
static SDL_Surface *ScratchSurface(SDL_Surface **slot,int w,int h) {
    if (*slot && ((*slot)->w!=w || (*slot)->h!=h)) {
        SDL_DestroySurface(*slot); *slot=NULL;
    }
    if (!*slot) *slot=SDL_CreateSurface(w,h,SDL_PIXELFORMAT_ARGB8888);
    return *slot;
}
static SDL_Texture *UploadTexture(SDL_Texture **slot,int w,int h,bool blend) {
    float width,height;
    if (*slot && (!SDL_GetTextureSize(*slot,&width,&height) || width!=w || height!=h)) {
        SDL_DestroyTexture(*slot); *slot=NULL;
    }
    if (!*slot) {
        *slot=SDL_CreateTexture(s_sdlRenderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,w,h);
        if (*slot) {
            SDL_SetTextureScaleMode(*slot,SDL_SCALEMODE_NEAREST);
            SDL_SetTextureBlendMode(*slot,blend?SDL_BLENDMODE_BLEND:SDL_BLENDMODE_NONE);
        }
    }
    return *slot;
}
static SDL_Texture *ScrollActorTexture(unsigned upload,int index) {
    if(index>=s_scrollActorCapacity[upload]) {
        int capacity=index+8;
        SDL_Texture **textures=realloc(s_scrollActors[upload],(size_t)capacity*sizeof(*textures));
        if(!textures) return NULL;
        memset(textures+s_scrollActorCapacity[upload],0,
               (capacity-s_scrollActorCapacity[upload])*sizeof(*textures));
        s_scrollActors[upload]=textures;s_scrollActorCapacity[upload]=capacity;
    }
    return UploadTexture(&s_scrollActors[upload][index],68,68,true);
}
static void ClearScrollResources(void) {
    s_darknessTexture=NULL;
    for(int i=0;i<2;i++) {
        for(int j=0;j<s_scrollActorCapacity[i];j++) SDL_DestroyTexture(s_scrollActors[i][j]);
        free(s_scrollActors[i]);s_scrollActors[i]=NULL;s_scrollActorCapacity[i]=0;
        SDL_DestroyTexture(s_scrollTerrain[i]);s_scrollTerrain[i]=NULL;
        SDL_DestroyTexture(s_scrollPlayer[i]);s_scrollPlayer[i]=NULL;
        SDL_DestroyTexture(s_darknessUploads[i]);s_darknessUploads[i]=NULL;
    }
    SDL_DestroySurface(s_scrollClean);s_scrollClean=NULL;
    SDL_DestroySurface(s_scrollPadded);s_scrollPadded=NULL;
    SDL_DestroySurface(s_darknessSurface);s_darknessSurface=NULL;
    s_scrollUpload=s_darknessUpload=0;
}
static float s_movementSpeed = 1.0f;
static bool s_customMovementSpeed;
static int s_previousWidth, s_previousHeight, s_previousX, s_previousY, s_previousMap, s_previousLevel;
typedef struct ActorVisual {
    bool visible, sighted;
    int x, y, worldX, worldY, kind, level, layer, height;
    Uint32 *sprite, *terrain;
} ActorVisual;
static ActorVisual *s_previousActors;
static int s_previousActorCount;
static void FreeActorVisuals(ActorVisual *actors, int count) {
    if (actors)
        for (int i = 0; i < count; i++)
            free(actors[i].sprite);
    free(actors);
}
#define s_egaPalette IMPERA_TextPalette

static void PatchActor(SDL_Surface* surface, const ActorVisual* actor, const Uint32* pixels, int left, int top, int right, int bottom)
{
    for (int y = 0; y < 68; y++) {
        if (actor->y+y/2 < top || actor->y+y/2 >= bottom) continue;
        for (int x = 0; x < 68; x++) {
            if (actor->x+x/2 < left || actor->x+x/2 >= right) continue;
            if (pixels[y * 68 + x] >> 24)
                ((Uint32 *)((byte *)surface->pixels +
                            (actor->y * 2 + y) * surface->pitch))[actor->x * 2 + x] =
                    pixels[y * 68 + x];
        }
    }
}
static void CaptureActors(ActorVisual* actors, const byte* indices, int w,
                          int mapX,int mapY,int columns,int rows)
{

    bool combat=D_5893_map_id>=128;
    for (int i = combat ? 0 : 1; i < MAP_ACTOR_COUNT + (combat ? 121 : 0); i++) {
        ActorFmt ground = {0};
        ActorFmt *a;
        if (i < MAP_ACTOR_COUNT)
            a = &D_5c5a[i];
        else {
            int cell = i - MAP_ACTOR_COUNT, x = cell % 11, y = cell / 11;
            if (GetMapViewport(x, y) == 255 || GetMapViewport(x, y) == TILE_MAP_87)
                continue;
            int shape = CONTENTS_GAME_Shape(x + MAP_VIEW_X, y + MAP_VIEW_Y);
            if (!shape && GetMapViewport(x, y) == 0)
                shape = GetActorMap(x, y);
            if (!shape || SPRITES_Layer(256 + shape))
                continue;
            bool duplicate = false;
            for (int j = 0; j < MAP_ACTOR_COUNT; ++j)
                if (D_5c5a[j]._0_tile && D_5c5a[j]._1_animTile == shape && D_5c5a[j]._2_x == x &&
                    D_5c5a[j]._3_y == y && !SPRITES_Layer(ACTORS_Sprite(j, 256 + shape))) {
                    duplicate = true;
                    break;
                }
            if (duplicate)
                continue;
            ground._0_tile = ground._1_animTile = shape;
            ground._2_x = x + MAP_VIEW_X;
            ground._3_y = y + MAP_VIEW_Y;
            ground._4_z = D_5895_map_level;
            a = &ground;
        }
        if (!a->_0_tile || !a->_1_animTile || (!combat && a->_4_z!=D_5895_map_level)) continue;
        int dx =
                a->_2_x -
                (combat ? (MAP_LARGE_COMBAT ? (s_expandedFrame ? D_5896_map_x : MAP_VIEW_X + 5) : 5)
                        : D_5896_map_x),
            dy =
                a->_3_y -
                (combat ? (MAP_LARGE_COMBAT ? (s_expandedFrame ? D_5897_map_y : MAP_VIEW_Y + 5) : 5)
                        : D_5897_map_y);
        if (!D_5893_map_id) { dx=((dx+128)&255)-128; dy=((dy+128)&255)-128; }
        int col=columns/2+dx, row=rows/2+dy;
        ActorVisual* v=&actors[i];
        v->x=mapX+col*16-1; v->y=mapY+row*16-1;
        v->worldX=a->_2_x; v->worldY=a->_3_y;
        v->kind=a->_0_tile<0x30?a->_0_tile:a->_0_tile&0xfc;
        v->level=a->_4_z;
        v->layer = SPRITES_Layer(256 + a->_1_animTile);
        if (!combat && !dx && !dy) continue;
        unsigned bodyW, bodyH;
        ACTORS_Size(i, &bodyW, &bodyH);
        v->height = bodyH;
        bool large = bodyW > 1 || bodyH > 1;
        if (large) {
            if (!WIDE_FootprintVisible(dx, dy, bodyW, bodyH))
                continue;
        } else if (abs(dx) <= 5 && abs(dy) <= 5) {
            if (GetMapViewport(dx+5,dy+5)!=0 || GetActorMap(dx+5,dy+5)==0x16) continue;
        } else if (combat || !WIDE_Visible(dx, dy))
            continue;
        v->sighted=true;
        if (col + (int)bodyW <= 0 || row + (int)bodyH <= 0 || col >= columns || row >= rows)
            continue;
        v->sprite = calloc(2 * 68 * 68, sizeof(Uint32));
        if (!v->sprite) {
            v->sighted = false;
            continue;
        }
        v->terrain = v->sprite + 68 * 68;
        v->visible=true;
        int tile;
        if (combat) {
            int x = a->_2_x, y = a->_3_y;
            int native = SPRITES_NativeActorTile(a, *ULTIMA_4402_GetTileAddr(x, y),
                                                 y ? *ULTIMA_4402_GetTileAddr(x, y - 1) : 0,
                                                 y + 1 < MAP_HEIGHT ? *ULTIMA_4402_GetTileAddr(x, y + 1) : 0);
            if (native < 0) {
                v->visible = v->sighted = false;
                continue;
            }
            tile = 256 + native;
        } else if (large)
            tile = ACTORS_Sprite(i, 256 + a->_1_animTile);
        else if (abs(dx) <= 5 && abs(dy) <= 5)
            tile = 256 + GetActorMap(dx + 5, dy + 5);
        else {
            tile=WIDE_ActorTile(i);
            if(tile<0) {v->visible=v->sighted=false;continue;}
        }
        tile = ACTORS_Sprite(i, tile);
        v->layer = SPRITES_Layer(tile);
        unsigned fw = 1, fh = 1;
        if (TYPES_ArtSlot(tile))
            TYPES_ArtSize(tile, D_5893_map_id == 0, &fw, &fh);
        v->height = fh;
        for (int y = 0; y < (int)(16 * fh + 2); y++)
            for (int x = 0; x < (int)(16 * fw + 2); x++) {
                int tx = x - 1, ty = y - 1;
                int nx = dx + (tx < 0 ? -1 : tx / 16), ny = dy + (ty < 0 ? -1 : ty / 16);
                int wx = a->_2_x + nx - dx, wy = a->_3_y + ny - dy;
                int color = WIDE_SpritePixel(tile, combat ? a->_2_x - D_5896_map_x : dx,
                                             combat ? a->_3_y - D_5897_map_y : dy, tx, ty);
                if (large && tx >= 0 && ty >= 0 && tx < (int)(16 * fw) && ty < (int)(16 * fh) &&
                    !WIDE_FootprintVisible(dx + tx / 16, dy + ty / 16, 1, 1))
                    color = -1;
                for (int sy = 0; sy < 2; sy++)
                    for (int sx = 0; sx < 2; sx++)
                        v->sprite[(y * 2 + sy) * 68 + x * 2 + sx] = TILESET_LastSpriteColor(
                            color, sx, sy, s_egaPalette, GRAP_BUF_SpriteIsTransparent(tile));
                color = WIDE_TerrainPixel(combat ? wx - D_5896_map_x : nx,
                                          combat ? wy - D_5897_map_y : ny, (tx + 16) % 16,
                                          (ty + 16) % 16);
                for (int sy = 0; sy < 2; sy++)
                    for (int sx = 0; sx < 2; sx++)
                        v->terrain[(y * 2 + sy) * 68 + x * 2 + sx] =
                            TILESET_LastColor(color, sx, sy, s_egaPalette);
            }
    }
}

void GRAP_SDL_SetSmoothMovement(bool enabled) { s_smoothMovement = enabled; s_previousValid = false; }
bool GRAP_SDL_SmoothMovementEnabled(void) { return s_smoothMovement; }
void GRAP_SDL_SetMovementSpeed(float speed) { s_movementSpeed = speed; s_customMovementSpeed = true; }
bool GRAP_SDL_CustomMovementSpeed(void) { return s_customMovementSpeed; }
unsigned int GRAP_SDL_MovementInterval(void)
{
    /* Match the seven frame waits exactly, including millisecond rounding. */
    if (s_smoothMovement) return 7 * (unsigned int)SDL_roundf(16.0f / s_movementSpeed);
    return (unsigned int)SDL_roundf(160.0f / s_movementSpeed);
}
void GRAP_SDL_MapDrawn(void) { s_mapDrawn = true; }


void GRAP_SDL_CursorSize(int* width, int* height)
{
    int w = 320, h = 200, outputW, outputH;
    if (s_sdlWindow) SDL_GetWindowSize(s_sdlWindow, &w, &h);
    float sx = w / 320.0f, sy = h / 200.0f;
    if ((s_fullscreen || s_pixelUI) && SDL_GetRenderOutputSize(s_sdlRenderer, &outputW, &outputH)) {
        WideLayout l = VideoLayout(outputW, outputH);
        sx = l.scale * (float)w / outputW;
        sy = l.scaleY * (float)h / outputH;
        if(!s_expandedFrame) {
            SDL_FRect native=NativeRect(outputW,outputH);
            sx=native.w/320*w/outputW;sy=native.h/200*h/outputH;
        }
    }
    *width = SDL_max(16, (int)SDL_roundf(16 * sx));
    *height = SDL_max(16, (int)SDL_roundf(16 * sy));
}

bool GRAP_SDL_MouseUIPoint(float x, float y, float* ux, float* uy)
{
    int w, h, ow, oh;
    if (!s_sdlWindow || !SDL_GetWindowSize(s_sdlWindow, &w, &h) || w <= 0 || h <= 0) return false;
    if (!s_fullscreen && !s_pixelUI) { *ux = x * 320 / w; *uy = y * 200 / h; return true; }
    if (!SDL_GetRenderOutputSize(s_sdlRenderer, &ow, &oh)) return false;
    WideLayout l = VideoLayout(ow, oh);
    int cw = s_expandedFrame ? l.width : 320, ch = s_expandedFrame ? l.height : 200;
    if(!s_expandedFrame) {
        SDL_FRect native=NativeRect(ow,oh);
        *ux=(x*ow/w-native.x)*320/native.w;
        *uy=(y*oh/h-native.y)*200/native.h;
    } else {
        *ux = (x * ow / w - (ow - cw * l.scale) / 2) / l.scale;
        *uy = (y * oh / h - (oh - ch * l.scaleY) / 2) / l.scaleY;
    }
    if (*ux < 0 || *uy < 0 || *ux >= cw || *uy >= ch) return false;
    /* The original right-hand 128 pixels move to the far edge in widescreen. */
    if (s_expandedFrame) {
        if (*ux < l.sidebarX) return false;
        *ux -= l.sidebarX - 192;
    }
    return true;
}

static bool MouseMapPoint(float x, float y, int* dx, int* dy, float* rx, float* ry, bool frame)
{
    int width, height, windowW, windowH;
    if (!s_sdlWindow || !s_sdlRenderer || !SDL_GetWindowSize(s_sdlWindow, &windowW, &windowH) ||
        !SDL_GetRenderOutputSize(s_sdlRenderer, &width, &height) || windowW <= 0 || windowH <= 0)
        return false;
    float gx = x * width / windowW, gy = y * height / windowH;
    int mapX = 8, mapY = 8, columns = 11, rows = 11;
    int frameWidth = 192, frameHeight = 192;
    if (s_fullscreen) {
        WideLayout l = VideoLayout(width, height);
        int canvasW = s_expandedFrame ? l.width : 320;
        int canvasH = s_expandedFrame ? l.height : 200;
        if(!s_expandedFrame) {
            SDL_FRect native=NativeRect(width,height);
            gx=(gx-native.x)*320/native.w;gy=(gy-native.y)*200/native.h;
        } else {
            gx = (gx - (width - canvasW * l.scale) / 2) / l.scale;
            gy = (gy - (height - canvasH * l.scaleY) / 2) / l.scaleY;
        }
        if (s_expandedFrame) {
            if(!frame && (gy<8 || gy>=l.height-8)) return false;
            frameWidth = l.sidebarX; frameHeight = l.height;
            mapX = l.mapX; mapY = l.mapY; columns = l.columns; rows = l.rows;
        }
    } else {
        gx = gx * 320 / width;
        gy = gy * 200 / height;
    }
    if (frame) {
        if (gx < 0 || gy < 0 || gx >= frameWidth || gy >= frameHeight) return false;
    } else if (gx < mapX || gy < mapY || gx >= mapX + columns * 16 || gy >= mapY + rows * 16)
        return false;
    *dx = (int)((gx - mapX) / 16) - columns / 2;
    *dy = (int)((gy - mapY) / 16) - rows / 2;
    *rx = (gx - mapX - columns / 2 * 16 - 8) / 16;
    *ry = (gy - mapY - rows / 2 * 16 - 8) / 16;
    if (MAP_LARGE_COMBAT) {
        int ox = s_expandedFrame ? (int)D_5896_map_x - 5 : MAP_VIEW_X;
        int oy = s_expandedFrame ? (int)D_5897_map_y - 5 : MAP_VIEW_Y;
        *dx += ox;
        *dy += oy;
        *rx += ox;
        *ry += oy;
    }
    return true;
}

bool GRAP_SDL_MouseMapPoint(float x, float y, int* dx, int* dy, float* rx, float* ry) {
    return MouseMapPoint(x, y, dx, dy, rx, ry, false);
}
bool GRAP_SDL_MouseMovementPoint(float x, float y, int* dx, int* dy, float* rx, float* ry) {
    return MouseMapPoint(x, y, dx, dy, rx, ry, true);
}

void GRAP_SDL_SetVideoMode(int mode)
{
    if(mode<GRAP_VIDEO_WINDOWED || mode>GRAP_VIDEO_FULLSCREEN_43) return;
    bool fullscreen=mode!=GRAP_VIDEO_WINDOWED;
    if (s_sdlWindow && s_fullscreen != fullscreen) {
        if (fullscreen) SDL_GetWindowSize(s_sdlWindow,&s_windowedWidth,&s_windowedHeight);
        if (!SDL_SetWindowFullscreen(s_sdlWindow,fullscreen)) {
            debug("Cannot change fullscreen: %s\n",SDL_GetError());
            return;
        }
        if (!fullscreen) SDL_SetWindowSize(s_sdlWindow,s_windowedWidth,s_windowedHeight);
        SDL_SetTextureScaleMode(s_sdlTexture,fullscreen || s_pixelUI ? SDL_SCALEMODE_NEAREST : SDL_SCALEMODE_LINEAR);
        s_previousValid=false;
    }
    if(s_videoMode!=mode) { s_previousValid=false;s_completedWideValid=false; }
    s_videoMode=mode;
    s_fullscreen = fullscreen;
}
int GRAP_SDL_VideoMode(void) { return s_videoMode; }
bool GRAP_SDL_MonitorSize(int* width,int* height)
{
    SDL_DisplayID display=s_sdlWindow?SDL_GetDisplayForWindow(s_sdlWindow):SDL_GetPrimaryDisplay();
    const SDL_DisplayMode* mode=SDL_GetDesktopDisplayMode(display);
    if(mode && mode->w>0 && mode->h>0) { *width=mode->w;*height=mode->h;return true; }
    SDL_Rect bounds;
    if(SDL_GetDisplayBounds(display,&bounds) && bounds.w>0 && bounds.h>0) {
        *width=bounds.w;*height=bounds.h;return true;
    }
    return false;
}
void GRAP_SDL_SetFullscreen(bool fullscreen)
{ GRAP_SDL_SetVideoMode(fullscreen?GRAP_VIDEO_FULLSCREEN:GRAP_VIDEO_WINDOWED); }
bool GRAP_SDL_Fullscreen(void) { return s_fullscreen; }
float GRAP_SDL_MovementSpeed(void) { return s_movementSpeed; }
bool GRAP_SDL_PixelUI(void) { return s_pixelUI; }
void GRAP_SDL_SetPixelUI(bool enabled)
{
    s_pixelUI=enabled;
    s_previousValid = s_mapDrawn = false;
    if(s_sdlTexture) SDL_SetTextureScaleMode(s_sdlTexture,s_fullscreen || enabled ? SDL_SCALEMODE_NEAREST : SDL_SCALEMODE_LINEAR);
}

int windowWidth = 1280;
int windowHeight = 960;

void GRAP_SDL_FlushFrame(void);

void AUDIO_SDL_Init(void);
void AUDIO_SDL_Cleanup(void);

void GRAP_SDL_Initialize(void)
{
    windowWidth = SETTINGS_GetInt("window", "width", windowWidth);
    windowHeight = SETTINGS_GetInt("window", "height", windowHeight);
    s_windowedWidth=windowWidth; s_windowedHeight=windowHeight;

    SDL_WindowFlags flags = SDL_WINDOW_HIGH_PIXEL_DENSITY;
    if (s_fullscreen)
    {
        const SDL_DisplayMode* mode = SDL_GetDesktopDisplayMode(SDL_GetPrimaryDisplay());
        if (!mode)
        {
            DEBUG_Error("Cannot detect desktop resolution: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        windowWidth = mode->w;
        windowHeight = mode->h;
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    if (!SDL_CreateWindowAndRenderer("Impera - An Ultima 5 Engine", windowWidth, windowHeight,
                                    flags, &s_sdlWindow, &s_sdlRenderer))
    {
        DEBUG_Error("Cannot create game window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    IMPERA_SetWindowIcon(s_sdlWindow);
    debug("Game window: %dx%d fullscreen=%d\n", windowWidth, windowHeight, s_fullscreen);

    s_sdlSurface = SDL_CreateSurface(hiresWidth, hiresHeight, SDL_GetPixelFormatForMasks(32, 0xff0000, 0xff00, 0xff, 0xff000000));

    if(!s_sdlSurface) { DEBUG_Error("Cannot create render surface: %s",SDL_GetError());exit(EXIT_FAILURE); }
    s_sdlTexture = SDL_CreateTextureFromSurface(s_sdlRenderer, s_sdlSurface);
    if(!s_sdlTexture) { DEBUG_Error("Cannot create render texture: %s",SDL_GetError());exit(EXIT_FAILURE); }
    debug("Renderer=%s video=%s",SDL_GetRendererName(s_sdlRenderer),SDL_GetCurrentVideoDriver());
    SDL_SetTextureScaleMode(s_sdlTexture, s_fullscreen ? SDL_SCALEMODE_NEAREST : SDL_SCALEMODE_LINEAR);

    if (SDL_MUSTLOCK(s_sdlSurface))
    {
        exit(0);
    }

    if (s_sdlSurface->pitch != hiresWidth * 4)
    {
        exit(0);
    }

    GRAP_BUF_Initialize(GRAP_SDL_FlushFrame);
}

void GRAP_SDL_Cleanup(void)
{
    CRT_Cleanup();
    GRAP_BUF_Cleanup();
    s_previousValid = s_mapDrawn = false;

    ClearScrollResources();
    SDL_DestroyTexture(s_wideTexture);
    SDL_DestroySurface(s_wideSurface);
    TILESET_Unregister(s_widePixels);
    free(s_widePixels);
    TILESET_Unregister(s_completedWidePixels);free(s_completedWidePixels);s_completedWidePixels=NULL;s_completedWideValid=false;
    s_wideTexture = NULL;
    s_wideSurface = NULL;
    s_widePixels = NULL;

    SDL_DestroyTexture(s_sdlTexture);
    SDL_DestroySurface(s_sdlSurface);
    FreeActorVisuals(s_previousActors, s_previousActorCount);
    s_previousActors = NULL;
    s_previousActorCount = 0;
    s_previousValid = false;
    SDL_DestroyRenderer(s_sdlRenderer);
    SDL_DestroyWindow(s_sdlWindow);

    s_sdlTexture = NULL;
    s_sdlSurface = NULL;
    s_sdlRenderer = NULL;
    s_sdlWindow = NULL;
}

static bool TextHistoryVisible(void)
{
    byte ignored;
    return !s_pixelUI && !EVT_ImmediateExitEnabled() && D_58a4 &&
           GRAP_BUF_TextHistoryPixel(D_535e_textWindows[2].left * 8,
                                    D_535e_textWindows[2].top * 8, &ignored);
}
static void LinearToRGB(void)
{
    bool showHistory = TextHistoryVisible();
    Uint32* pixels = s_sdlSurface->pixels;
    int pitch = s_sdlSurface->pitch / 4;

    for (int y = 0; y < loresHeight; y++)
    {
        for (int x = 0; x < loresWidth; x++)
        {
            const byte* source=g_linearEgaBuffer0+y*loresWidth+x;
            byte history;
            bool past = showHistory && GRAP_BUF_TextHistoryPixel(x, y, &history);
            for(int sy=0;sy<2;sy++) for(int sx=0;sx<2;sx++)
                pixels[(y*2+sy)*pitch+x*2+sx]=past ? s_egaPalette[history & 15] : s_pixelUI || EVT_ImmediateExitEnabled()?
                    TILESET_UIBufferColor(source,s_egaPalette):TILESET_BufferColor(source,sx,sy,s_egaPalette);
        }
    }

#if defined(ENABLE_GRAP_OVERLAY)
    if (!s_pixelUI) for (int y = 0; y < hiresHeight; y++)
    {
        for (int x = 0; x < hiresWidth; x++)
        {
            byte pixel = g_linearOverlayBuffer[y * hiresWidth + x] & 0xf;
            if (pixel != 0)
            {
                pixels[y * pitch + x] = s_egaPalette[pixel];
            }
            // pixels[y * pitch + x] |= egaPalette[pLinearOverlayBuffer[y * hiresWidth + x] & 0xf];
        }
    }
#endif
}

static int s_darknessColumns,s_darknessRows,s_darknessMap,s_darknessLevel;
static void PrepareDarkness(int columns,int rows,bool completed)
{
    if (!WIDE_DitheredDarkness() || EVT_ImmediateExitEnabled() || s_pixelUI || !D_58a4 ||
        !MAPS_Outside(D_5893_map_id)) {
        s_darknessTexture=NULL;return;
    }
    if(!completed && s_darknessTexture && columns==s_darknessColumns && rows==s_darknessRows && s_darknessMap==D_5893_map_id && s_darknessLevel==D_5895_map_level) return;
    /* One tile of padding keeps the mask over every exposed scrolling edge. */
    int width=(columns+2)*16,height=(rows+2)*16;
    byte* mask=malloc((size_t)width*height);
    SDL_Surface* surface=ScratchSurface(&s_darknessSurface,width,height);
    if(mask && surface && WIDE_DarknessMask(mask,columns+2,rows+2)) {
        static const byte pattern[16]={0,8,2,10,12,4,14,6,3,11,1,9,15,7,13,5};
        bool unchanged=s_darknessTexture && columns==s_darknessColumns && rows==s_darknessRows;
        for(int y=0;y<height;y++) {
            Uint32* pixels=(Uint32*)((byte*)surface->pixels+y*surface->pitch);
            for(int x=0;x<width;x++) {
                Uint32 next=pattern[(y&3)*4+(x&3)]<mask[y*width+x]?0xff000000:0;
                if(unchanged && pixels[x]!=next) unchanged=false;
                pixels[x]=next;
            }
        }
        /* Most steps preserve the light shape. Do not upload an identical
         * mask; changed masks alternate storage rather than overwrite the
         * texture sampled by the immediately preceding turn. */
        if(!unchanged) {
            SDL_Texture* next=UploadTexture(&s_darknessUploads[s_darknessUpload++ & 1],width,height,true);
            if(next && SDL_UpdateTexture(next,NULL,surface->pixels,surface->pitch))
                s_darknessTexture=next;
            else {
                s_darknessTexture=NULL;
                DEBUG_Error("Cannot update dithered darkness texture: %s",SDL_GetError());
            }
        }
        s_darknessColumns=columns;s_darknessRows=rows;s_darknessMap=D_5893_map_id;s_darknessLevel=D_5895_map_level;
    } else DEBUG_Error("Cannot allocate dithered darkness mask");
    free(mask);
}
static void DrawDarkness(SDL_FRect dst,int width,int height,int mapX,int mapY,int columns,int rows)
{
    if(!s_darknessTexture) return;
    SDL_FRect map={dst.x+mapX*dst.w/width,dst.y+mapY*dst.h/height,columns*16*dst.w/width,rows*16*dst.h/height};
    SDL_FRect source={16,16,columns*16,rows*16};
    SDL_Rect clip={(int)map.x,(int)(dst.y+8*dst.h/height),(int)map.w,(int)((height-16)*dst.h/height)};
    if(s_expandedFrame) SDL_SetRenderClipRect(s_sdlRenderer,&clip);
    SDL_RenderTexture(s_sdlRenderer,s_darknessTexture,&source,&map);
    if(s_expandedFrame) SDL_SetRenderClipRect(s_sdlRenderer,NULL);
}

/* Snapshot only completed map redraws, never intermediate text updates. The
 * camera follows the party: terrain slides while the player stays centered. */
static bool CombatSelectionPixel(int x, int y) { return x < 2 || x >= 14 || y < 2 || y >= 14; }
static void SmoothFrame(const byte* indices, int w, int h, int mapX, int mapY,
                        int columns, int rows, SDL_Texture* native, int sourceScale, SDL_FRect dst)
{
    if ((EVT_ImmediateExitEnabled() && D_5893_map_id != 255) || s_pixelUI || !s_smoothMovement ||
        !s_mapDrawn || !D_58a4 || (!MAPS_Outside(D_5893_map_id) && D_5893_map_id < 128))
        return;
    s_mapDrawn = false;
    Uint64 smoothingStarted=SDL_GetTicks();
    SDL_Surface* clean = ScratchSurface(&s_scrollClean,w*2,h*2);
    if (!clean) { s_previousValid = false; return; }
    for (int y = 0; y < h; y++) for(int sy=0;sy<2;sy++) {
        Uint32* row = (Uint32*)((byte*)clean->pixels + (y*2+sy) * clean->pitch);
        for (int x = 0; x < w; x++) for(int sx=0;sx<2;sx++)
            row[x*2+sx] = TILESET_BufferColor(indices+y*w+x,sx,sy,s_egaPalette);
    }
    int playerX = mapX + columns / 2 * 16, playerY = mapY + rows / 2 * 16;
    bool combat=D_5893_map_id>=128;
    /* Only world maps extend into partial edge rows. Combat's centered
     * margins must never expose the interpolation texture's padding. */
    int mapTop=s_expandedFrame && !combat?8:mapY;
    int mapBottom=s_expandedFrame && !combat?h-8:mapY+rows*16;
    for (int y = -1; !combat && y <= 16; y++) {
        for (int x = -1; x <= 16; x++) {
            if (WIDE_SpritePixel(256+GetActorMap(5,5),0,0,x,y)<0) continue;
            int color=WIDE_TerrainPixel(x<0?-1:x>=16?1:0,y<0?-1:y>=16?1:0,(x+16)%16,(y+16)%16);
            for(int sy=0;sy<2;sy++) for(int sx=0;sx<2;sx++)
                ((Uint32*)((byte*)clean->pixels+((playerY+y)*2+sy)*clean->pitch))[(playerX+x)*2+sx]=TILESET_LastColor(color,sx,sy,s_egaPalette);
        }
    }
    int dx = D_5896_map_x - s_previousX, dy = D_5897_map_y - s_previousY;
    if (!D_5893_map_id) { dx = ((dx+128)&255)-128; dy = ((dy+128)&255)-128; }
    if (combat) dx=dy=0;
    const int actorCount = MAP_ACTOR_COUNT + (combat ? 121 : 0);
    ActorVisual *actors = calloc(actorCount, sizeof(*actors));
    bool *moving = calloc(actorCount, sizeof(*moving));
    SDL_Texture **actorTextures = calloc(actorCount, sizeof(*actorTextures));
    if (!actors || !moving || !actorTextures) {
        free(actors);
        free(moving);
        free(actorTextures);
        s_previousValid = false;
        return;
    }
    CaptureActors(actors,indices,w,mapX,mapY,columns,rows);
    bool compatible = s_previousActorCount == actorCount && s_previousValid &&
                      s_previousWidth == w && s_previousHeight == h &&
                      s_previousMap == D_5893_map_id && s_previousLevel == D_5895_map_level &&
                      abs(dx) <= 1 && abs(dy) <= 1;
    bool animate=compatible && (dx || dy);
    if (compatible)
        for (int i = 0; i < actorCount; i++) {
            ActorVisual *old = &s_previousActors[i];
            ActorVisual *next = &actors[i];
            int ax = next->worldX - old->worldX, ay = next->worldY - old->worldY;
            if (!D_5893_map_id) {
                ax = ((ax + 128) & 255) - 128;
                ay = ((ay + 128) & 255) - 128;
            }
            moving[i] = (old->visible || next->visible) && old->sighted && next->sighted &&
                        old->kind == next->kind && old->level == next->level && abs(ax) <= 1 &&
                        abs(ay) <= 1 && (ax || ay);
            if (moving[i])
                animate = true;
            if (moving[i] || combat) {
                if (next->visible) {
                    for (int y = 0; y < 68; y++)
                        for (int x = 0; x < 68; x++)
                            if ((next->sprite[y * 68 + x] >> 24) && next->x + x / 2 >= mapX &&
                                next->x + x / 2 < mapX + columns * 16 &&
                                next->y + y / 2 >= mapTop && next->y + y / 2 < mapBottom)
                                ((Uint32 *)((byte *)clean->pixels +
                                            (next->y * 2 + y) * clean->pitch))[next->x * 2 + x] =
                                    next->terrain[y * 68 + x];
                }
            }
        }
    Uint32 selectionColor =
        s_egaPalette[D_13b0_brightWhiteColor &
                     (D_52ba_vdp._52c8_videoDriverSelection == VDP_VIDEO_CGA ? 3 : 15)];
    bool combatSelection = combat && D_589e < 32 && D_589f && ULTIMA_5646(D_589e) == 0;
    int selectionX = 0, selectionY = 0;
    if (combatSelection) {
        selectionX =
            mapX +
            (columns / 2 - 5 + D_ba14[D_589e].x -
             (MAP_LARGE_COMBAT ? (s_expandedFrame ? (int)D_5896_map_x - 5 : MAP_VIEW_X) : 0)) *
                16;
        selectionY =
            mapY +
            (rows / 2 - 5 + D_ba14[D_589e].y -
             (MAP_LARGE_COMBAT ? (s_expandedFrame ? (int)D_5897_map_y - 5 : MAP_VIEW_Y) : 0)) *
                16;
        /* Manual/modal frames may omit the cursor. Preserve what was actually
         * drawn, rather than introducing one while animating. */
        for (int y = 0; y < 16 && combatSelection; ++y)
            for (int x = 0; x < 16; ++x)
                if (CombatSelectionPixel(x, y) &&
                    (selectionX + x < 0 || selectionX + x >= w || selectionY + y < 0 ||
                     selectionY + y >= h ||
                     TILESET_BufferColor(indices + (selectionY + y) * w + selectionX + x, 0, 0,
                                         s_egaPalette) != selectionColor)) {
                    combatSelection = false;
                    break;
                }
        if (combatSelection)
            for (int y = 0; y < 16; ++y)
                for (int x = 0; x < 16; ++x)
                    if (CombatSelectionPixel(x, y)) {
                        int color = WIDE_TerrainPixel(D_ba14[D_589e].x - D_5896_map_x,
                                                      D_ba14[D_589e].y - D_5897_map_y, x, y);
                        for (int sy = 0; sy < 2; ++sy)
                            for (int sx = 0; sx < 2; ++sx)
                                ((Uint32 *)((byte *)clean->pixels +
                                            ((selectionY + y) * 2 + sy) *
                                                clean->pitch))[(selectionX + x) * 2 + sx] =
                                    TILESET_LastColor(color, sx, sy, s_egaPalette);
                    }
    }
    if (animate) {
        unsigned upload=s_scrollUpload++ & 1;
        int uploadedActors=0;
        debug("Smooth movement: offset=%d,%d\n", dx, dy);
        /* One padded current map covers all exposed edges, including diagonal
         * corner gaps. Never splice old/new water animation phases together. */
        int paddedWidth=(columns+2)*16,paddedHeight=(rows+2)*16;
        bool* hidden=calloc((size_t)(columns+2)*(rows+2),sizeof(bool));
        SDL_Surface* padded=hidden?ScratchSurface(&s_scrollPadded,paddedWidth*2,paddedHeight*2):NULL;
        if(padded) for(int row=-1;row<=rows;row++) for(int col=-1;col<=columns;col++) {
            bool interior=col>=0 && col<columns && row>=0 && row<rows;
            int tx=col-columns/2,ty=row-rows/2;
            bool lit=combat || (abs(tx)<=5 && abs(ty)<=5 ? GetMapViewport(tx+5,ty+5)!=255 : WIDE_Visible(tx,ty));
            hidden[(row+1)*(columns+2)+col+1]=!lit;
            bool valid=WIDE_MapTile(tx,ty)!=255;
            for(int y=0;y<16;y++) for(int sy=0;sy<2;sy++) {
                Uint32* dest=(Uint32*)((byte*)padded->pixels+(((row+1)*16+y)*2+sy)*padded->pitch)+(col+1)*32;
                /* Only unseen world/location cells have full darkness
                 * coverage. Combat cells, including native marker tiles, must
                 * retain their completed framebuffer and terrain handling. */
                if (!combat && !lit) {
                    for (int x=0;x<32;x++) dest[x]=0xff000000;
                }
                /* Partial edge rows contain terrain, never the static frame. */
                else if(interior && mapY+row*16+y>=mapTop && mapY+row*16+y<mapBottom && (combat || lit))
                    memcpy(dest,(byte*)clean->pixels+((mapY+row*16+y)*2+sy)*clean->pitch+(mapX+col*16)*8,32*4);
                else for(int x=0;x<16;x++) {
                    int color=valid?WIDE_TerrainPixel(tx,ty,x,y):0;
                    if(!valid) TILESET_SetSample(0);
                    for(int sx=0;sx<2;sx++) dest[x*2+sx]=TILESET_LastColor(color,sx,sy,s_egaPalette);
                }
            }
        }
        SDL_Texture* next=NULL;
        if(padded) {
            if(combat) next=SDL_CreateTextureFromSurface(s_sdlRenderer,padded);
            else {
                next=UploadTexture(&s_scrollTerrain[upload],padded->w,padded->h,false);
                if(next && !SDL_UpdateTexture(next,NULL,padded->pixels,padded->pitch)) next=NULL;
            }
        }
        if (next) {
            SDL_SetTextureScaleMode(next,SDL_SCALEMODE_NEAREST);

            for (int i = 0; i < actorCount; i++)
                if (moving[i] || (combat && actors[i].visible)) {
                    actorTextures[i] = combat
                        ? SDL_CreateTexture(s_sdlRenderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STATIC,68,68)
                        : ScrollActorTexture(upload,uploadedActors++);
                    if (actorTextures[i]) {
                        SDL_UpdateTexture(actorTextures[i], NULL,
                                          actors[i].visible ? actors[i].sprite
                                                            : s_previousActors[i].sprite,
                                          68 * 4);
                        SDL_SetTextureScaleMode(actorTextures[i], SDL_SCALEMODE_NEAREST);
                        SDL_SetTextureBlendMode(actorTextures[i], SDL_BLENDMODE_BLEND);
                    }
                }
            float sx = dst.w / w, sy = dst.h / h;
            SDL_Rect clip = {(int)(dst.x+mapX*sx),(int)(dst.y+mapY*sy),
                             (int)(columns*16*sx),(int)(rows*16*sy)};
            if(s_expandedFrame && !combat) { clip.y=(int)(dst.y+8*sy);clip.h=(int)((h-16)*sy); }
            SDL_FRect mapSrc = {0,0,paddedWidth*2,paddedHeight*2};
            SDL_FRect mapDst = {dst.x+mapX*sx,dst.y+mapY*sy,columns*16*sx,rows*16*sy};
            SDL_Texture* playerTexture=NULL;
            SDL_FRect playerDst = {dst.x+(playerX-1)*sx,dst.y+(playerY-1)*sy,18*sx,18*sy};
            if (!combat) {
                Uint32 sprite[36*36];
                for(int y=0;y<18;y++) for(int x=0;x<18;x++) {
                    int color=WIDE_SpritePixel(256+GetActorMap(5,5),0,0,x-1,y-1);
                    for(int sy=0;sy<2;sy++) for(int sx=0;sx<2;sx++)
                        sprite[(y*2+sy)*36+x*2+sx]=TILESET_LastSpriteColor(color,sx,sy,s_egaPalette,GRAP_BUF_SpriteIsTransparent(256+GetActorMap(5,5)));
                }
                playerTexture=UploadTexture(&s_scrollPlayer[upload],36,36,true);
                if(playerTexture) {
                    SDL_UpdateTexture(playerTexture,NULL,sprite,36*4);
                    SDL_SetTextureScaleMode(playerTexture,SDL_SCALEMODE_NEAREST);
                    SDL_SetTextureBlendMode(playerTexture,SDL_BLENDMODE_BLEND);
                }
            }
            SDL_Texture *selectionTexture = NULL;
            if (combatSelection) {
                Uint32 pixels[32 * 32] = {0};
                for (int y = 0; y < 32; ++y)
                    for (int x = 0; x < 32; ++x)
                        if (CombatSelectionPixel(x / 2, y / 2))
                            pixels[y * 32 + x] = selectionColor;
                selectionTexture = SDL_CreateTexture(s_sdlRenderer, SDL_PIXELFORMAT_ARGB8888,
                                                     SDL_TEXTUREACCESS_STATIC, 32, 32);
                if (selectionTexture) {
                    SDL_UpdateTexture(selectionTexture, NULL, pixels, 32 * 4);
                    SDL_SetTextureScaleMode(selectionTexture, SDL_SCALEMODE_NEAREST);
                    SDL_SetTextureBlendMode(selectionTexture, SDL_BLENDMODE_BLEND);
                }
            }
            Uint64 preparation=SDL_GetTicks()-smoothingStarted;
            if(preparation>50)
                debug("Slow smooth preparation: %llu ms map=%d position=%d,%d tiles=%dx%d CRT=%d",
                      (unsigned long long)preparation,D_5893_map_id,D_5896_map_x,D_5897_map_y,
                      columns,rows,CRT_Enabled());
            for (int frame = 1; frame <= 8; frame++) {
                Uint64 frameStarted=SDL_GetTicks();
                float t = frame / 8.0f;
                /* Constant speed avoids braking and restarting at every tile. */
                float progress = t;
                /* SDL invalidates the backbuffer after every present. Clear
                 * letterbox areas as well as redrawing the game each time. */
                SDL_RenderClear(s_sdlRenderer);
                SDL_RenderTexture(s_sdlRenderer,native,NULL,&dst);
                SDL_SetRenderClipRect(s_sdlRenderer,&clip);
                SDL_FRect b = {mapDst.x-16*sx,mapDst.y-16*sy,(columns+2)*16*sx,(rows+2)*16*sy};
                b.x += SDL_roundf(dx*16*sx*(1-progress)); b.y += SDL_roundf(dy*16*sy*(1-progress));
                SDL_RenderTexture(s_sdlRenderer,next,&mapSrc,&b);
                typedef struct {
                    SpriteOrder order;
                    int actor;
                } OrderedActor;
                OrderedActor combatOrder[32 + 121];
                int orderCount = 0;
                if (combat) {
                    for (int i = 0; i < actorCount; ++i) {
                        ActorVisual *a = &s_previousActors[i], *b = &actors[i];
                        if (!b->visible)
                            continue;
                        float y = moving[i] ? a->y + (b->y - a->y) * progress : b->y;
                        float x = moving[i] ? a->x + (b->x - a->x) * progress : b->x;
                        combatOrder[orderCount++] =
                            (OrderedActor){{b->layer, y + 16 * (b->height - 1), x, -i}, i};
                    }
                    qsort(combatOrder, orderCount, sizeof(*combatOrder), SPRITES_Compare);
                }
                for (int n = 0; n < (combat ? orderCount : actorCount); ++n) {
                    int i = combat ? combatOrder[n].actor : actorCount - 1 - n;
                    if (!combat && !moving[i])
                        continue;
                    ActorVisual *a = &s_previousActors[i], *b = &actors[i];
                    float x = moving[i] ? a->x + (b->x - a->x) * progress : b->x;
                    float y = moving[i] ? a->y + (b->y - a->y) * progress : b->y;
                    SDL_FRect rect = {dst.x + SDL_roundf(x * sx), dst.y + SDL_roundf(y * sy),
                                      34 * sx, 34 * sy};
                    if (actorTextures[i])
                        SDL_RenderTexture(s_sdlRenderer, actorTextures[i], NULL, &rect);
                    else if (b->visible) {
                        SDL_FRect src = {b->x * sourceScale, b->y * sourceScale, 16 * sourceScale,
                                         16 * sourceScale};
                        SDL_RenderTexture(s_sdlRenderer, native, &src, &rect);
                    }
                }
                if (selectionTexture) {
                    float x = selectionX, y = selectionY;
                    int actor = D_ba14[D_589e].actorIdx;
                    if (actor < actorCount && moving[actor]) {
                        x += (s_previousActors[actor].x - actors[actor].x) * (1 - progress);
                        y += (s_previousActors[actor].y - actors[actor].y) * (1 - progress);
                    }
                    SDL_FRect outline = {dst.x + x * sx, dst.y + y * sy, 16 * sx, 16 * sy};
                    SDL_RenderTexture(s_sdlRenderer, selectionTexture, NULL, &outline);
                }
                if (playerTexture) SDL_RenderTexture(s_sdlRenderer,playerTexture,NULL,&playerDst);
                /* Cover sprites as well as ground with the authoritative
                 * central visibility and expanded LOS result. */
                if(!combat && s_darknessTexture) {
                    /* Keep wall/door cutouts and the ordered pattern attached to
                     * their terrain throughout the same interpolated movement. */
                    SDL_RenderTexture(s_sdlRenderer,s_darknessTexture,NULL,&b);
                }
                else if(!combat) for(int row=-1;row<=rows;row++) for(int col=-1;col<=columns;col++) if(hidden[(row+1)*(columns+2)+col+1]) {
                    SDL_FRect shadow={b.x+(col+1)*16*sx,b.y+(row+1)*16*sy,16*sx,16*sy};
                    SDL_RenderFillRect(s_sdlRenderer,&shadow);
                }
                SDL_SetRenderClipRect(s_sdlRenderer,NULL);
                CRT_EndFrame(s_sdlRenderer);
                SDL_RenderPresent(s_sdlRenderer);
                CRT_ResumeFrame(s_sdlRenderer);
                if (EVT_ImmediateExitEnabled())
                    EVT_PollMessages();
                else
                    SDL_PumpEvents();
                MOUSE_UpdateCursor();
                Uint64 frameElapsed=SDL_GetTicks()-frameStarted;
                if(frameElapsed>50)
                    debug("Slow smooth frame: %llu ms frame=%d map=%d position=%d,%d CRT=%d",
                          (unsigned long long)frameElapsed,frame,D_5893_map_id,
                          D_5896_map_x,D_5897_map_y,CRT_Enabled());
                if (frame < 8) {
                    Uint64 elapsed=SDL_GetTicks()-frameStarted;
                    Uint32 interval=(Uint32)SDL_roundf(16.0f/s_movementSpeed);
                    if(elapsed<interval) SDL_Delay(interval-(Uint32)elapsed);
                }
            }
            SDL_DestroyTexture(selectionTexture);
            if(combat) for (int i = 0; i < actorCount; i++)
                SDL_DestroyTexture(actorTextures[i]);
        }
        if(combat) SDL_DestroyTexture(next);
        free(hidden);
        /* The caller still presents the completed frame (and may capture it).
         * Rebuild that backbuffer after the last interpolation presentation. */
        SDL_RenderClear(s_sdlRenderer);
        SDL_RenderTexture(s_sdlRenderer,native,NULL,&dst);
    }
    for (int i = 0; i < actorCount; i++)
        if (moving[i] && actors[i].visible)
            PatchActor(clean, &actors[i], actors[i].sprite, mapX, mapY, mapX + columns * 16,
                       mapY + rows * 16);
    FreeActorVisuals(s_previousActors, s_previousActorCount);
    s_previousActors = actors;
    s_previousActorCount = actorCount;
    free(moving);
    free(actorTextures);
    s_previousValid = true;
    s_previousWidth=w; s_previousHeight=h; s_previousX=D_5896_map_x; s_previousY=D_5897_map_y;
    s_previousMap=D_5893_map_id; s_previousLevel=D_5895_map_level;
}

/* Thumbnails are rendered at display resolution over the pixel UI. */
static SDL_Texture* s_uiThumbnails[4];
static SDL_FRect s_uiThumbnailRects[4];
void GRAP_SDL_ClearUIThumbnails(void)
{
    for(int i=0;i<4;i++) { SDL_DestroyTexture(s_uiThumbnails[i]);s_uiThumbnails[i]=NULL; }
}
static bool s_captureRequested;
static SDL_Surface* s_capturedFrame;
SDL_Surface* GRAP_SDL_CaptureFrame(void)
{
    /* Render the current gameplay buffer even within the same timer tick.
       SDL backbuffer contents are undefined after SDL_RenderPresent. */
    s_captureRequested=true;
    s_capturedFrame=NULL;
    GRAP_BUF_Present();
    s_captureRequested=false;
    SDL_Surface* frame=s_capturedFrame;
    s_capturedFrame=NULL;
    return frame;
}
void GRAP_SDL_UIThumbnailPNG(int i, const void *png, size_t size, int x, int y, int w, int h) {
    if (i < 0 || i >= 4) return;
    SDL_DestroyTexture(s_uiThumbnails[i]); s_uiThumbnails[i] = NULL;
    SDL_IOStream *stream = png && size ? SDL_IOFromConstMem(png, size) : NULL;
    SDL_Surface *image = stream ? SDL_LoadPNG_IO(stream, true) : NULL;
    if (image) {
        s_uiThumbnails[i] = SDL_CreateTextureFromSurface(s_sdlRenderer, image);
        SDL_DestroySurface(image);
        if (s_uiThumbnails[i]) SDL_SetTextureScaleMode(s_uiThumbnails[i], SDL_SCALEMODE_LINEAR);
    }
    s_uiThumbnailRects[i] = (SDL_FRect){x,y,w,h};
}
void GRAP_SDL_UIThumbnail(int i,const char* path,int x,int y,int w,int h)
{
    if(i<0 || i>=4) return;
    SDL_DestroyTexture(s_uiThumbnails[i]);s_uiThumbnails[i]=NULL;
    SDL_Surface* image=SDL_LoadBMP(path);
    if(image) {
        s_uiThumbnails[i]=SDL_CreateTextureFromSurface(s_sdlRenderer,image);
        SDL_DestroySurface(image);
        if(s_uiThumbnails[i]) SDL_SetTextureScaleMode(s_uiThumbnails[i],SDL_SCALEMODE_LINEAR);
    }
    s_uiThumbnailRects[i]=(SDL_FRect){x,y,w,h};
}
extern void DisplayDebugMessages(void);

void GRAP_SDL_FlushFrame(void)
{
    CRT_BeginFrame(s_sdlRenderer);
    /* Reconstruct the original pixels first; CRT owns the gentle softness. */
    SDL_SetTextureScaleMode(s_sdlTexture,
        s_fullscreen || s_pixelUI || CRT_Enabled() || TILESET_Selected()!=TILESET_DOS ? SDL_SCALEMODE_NEAREST : SDL_SCALEMODE_LINEAR);
    bool completedMap=s_mapDrawn;
    s_expandedFrame = false;
    if(!s_fullscreen || s_pixelUI || !D_58a4) s_completedWideValid=false;
    if (!D_58a4 || (!MAPS_Outside(D_5893_map_id) && D_5893_map_id < 128))
        s_previousValid = false;
    LinearToRGB();

    SDL_UpdateTexture(s_sdlTexture, NULL, s_sdlSurface->pixels, s_sdlSurface->pitch);

    SDL_FRect srcRect = {0, 0, hiresWidth, hiresHeight};
    SDL_SetRenderDrawColor(s_sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(s_sdlRenderer);
    if (s_fullscreen || s_pixelUI)
    {
        int width, height;
        if (!SDL_GetRenderOutputSize(s_sdlRenderer, &width, &height)) return;
        WideLayout layout = VideoLayout(width, height);
        if (!s_wideSurface || s_wideSurface->w != layout.width*2 || s_wideSurface->h != layout.height*2)
        {
            SDL_DestroyTexture(s_wideTexture);
            SDL_DestroySurface(s_wideSurface);
            TILESET_Unregister(s_widePixels);
    free(s_widePixels);
            TILESET_Unregister(s_completedWidePixels);free(s_completedWidePixels);s_completedWideValid=false;
            s_completedWidePixels=malloc((size_t)layout.width*layout.height);
            s_wideSurface = SDL_CreateSurface(layout.width*2, layout.height*2, SDL_PIXELFORMAT_ARGB8888);
            s_widePixels = malloc((size_t)layout.width * layout.height);
            TILESET_Register(s_widePixels,(size_t)layout.width*layout.height);
            TILESET_Register(s_completedWidePixels,(size_t)layout.width*layout.height);
            if (!s_wideSurface || !s_widePixels || !s_completedWidePixels)
            {
                DEBUG_Error("Cannot allocate expanded game viewport\n");
                exit(EXIT_FAILURE);
            }
            s_wideTexture = SDL_CreateTexture(s_sdlRenderer, SDL_PIXELFORMAT_ARGB8888,
                                             SDL_TEXTUREACCESS_STREAMING, layout.width*2, layout.height*2);
            if (!s_wideTexture)
            {
                DEBUG_Error("Cannot create expanded viewport texture: %s\n", SDL_GetError());
                exit(EXIT_FAILURE);
            }
            SDL_SetTextureScaleMode(s_wideTexture, SDL_SCALEMODE_NEAREST);
            debug("Expanded layout: %dx%d tiles, pixel scale=%d\n", layout.columns, layout.rows, layout.scale);
        }
        if (s_videoMode==GRAP_VIDEO_FULLSCREEN && !EVT_ImmediateExitEnabled() && !s_pixelUI && WIDE_Compose(s_widePixels, layout))
        {
            s_expandedFrame = true;
            /* UI/effect updates can flush between a movement/light change and
             * the original map redraw. Keep expanded tiles from that same
             * completed map; central tiles and modal effects remain live. */
            if(!completedMap && s_completedWideValid && s_completedWideMap==D_5893_map_id && s_completedWideLevel==D_5895_map_level) {
                for(int row=0;row<layout.rows;row++) for(int col=0;col<layout.columns;col++) {
                    if(abs(col-layout.columns/2)<=5 && abs(row-layout.rows/2)<=5) continue;
                    for(int y=0;y<16;y++) {
                        int py=layout.mapY+row*16+y;
                        if(py<8 || py>=layout.height-8) continue;
                        int offset=py*layout.width+layout.mapX+col*16;
                        TILESET_Copy(s_widePixels+offset,s_completedWidePixels+offset,16);
                        memcpy(s_widePixels+offset,s_completedWidePixels+offset,16);
                    }
                }
            }
            TILESET_Copy(s_completedWidePixels,s_widePixels,(size_t)layout.width*layout.height);
            memcpy(s_completedWidePixels,s_widePixels,(size_t)layout.width*layout.height);
            s_completedWideMap=D_5893_map_id;s_completedWideLevel=D_5895_map_level;s_completedWideValid=true;
            bool showHistory = TextHistoryVisible();
            for(int y=0;y<layout.height;y++) for(int x=0;x<layout.width;x++)
                for(int sy=0;sy<2;sy++) for(int sx=0;sx<2;sx++) {
                    Uint32* row=(Uint32*)((byte*)s_wideSurface->pixels+(y*2+sy)*s_wideSurface->pitch);
                    byte history;
                    bool past = showHistory && x >= layout.sidebarX &&
                                GRAP_BUF_TextHistoryPixel(x - layout.sidebarX + 192, y, &history);
                    row[x*2+sx]=past ? s_egaPalette[history & 15] :
                        TILESET_BufferColor(s_widePixels+y*layout.width+x,sx,sy,s_egaPalette);
                }
            SDL_UpdateTexture(s_wideTexture, NULL, s_wideSurface->pixels, s_wideSurface->pitch);
            SDL_FRect dst = {(width - layout.width * layout.scale) / 2,
                             (height - layout.height * layout.scaleY) / 2,
                             layout.width * layout.scale, layout.height * layout.scaleY};
            SDL_RenderTexture(s_sdlRenderer, s_wideTexture, NULL, &dst);
            PrepareDarkness(layout.columns,layout.rows,completedMap);
            SmoothFrame(s_widePixels,layout.width,layout.height,layout.mapX,layout.mapY,
                        layout.columns,layout.rows,s_wideTexture,2,dst);
            DrawDarkness(dst,layout.width,layout.height,layout.mapX,layout.mapY,layout.columns,layout.rows);
        }
        else
        {
            s_completedWideValid=false;
            SDL_FRect dst = NativeRect(width,height);
            SDL_FRect imageDst=dst;
            if(NativeGameplay()) {
                srcRect.h*=192.0f/200;
                imageDst.h*=192.0f/200;
            }
            SDL_RenderTexture(s_sdlRenderer, s_sdlTexture, &srcRect, &imageDst);
            PrepareDarkness(11,11,completedMap);
            SmoothFrame(g_linearEgaBuffer0,320,200,8,8,11,11,s_sdlTexture,2,dst);
            DrawDarkness(dst,320,200,8,8,11,11);
        }
    }
    else {
        SDL_RenderTexture(s_sdlRenderer, s_sdlTexture, &srcRect, NULL);
        int w,h;
        if (SDL_GetRenderOutputSize(s_sdlRenderer,&w,&h)) {
            SDL_FRect dst = {0,0,w,h};
            PrepareDarkness(11,11,completedMap);
            SmoothFrame(g_linearEgaBuffer0,320,200,8,8,11,11,s_sdlTexture,2,dst);
            DrawDarkness(dst,320,200,8,8,11,11);
        }
    }
    if(s_pixelUI) {
        int w,h;
        if(SDL_GetRenderOutputSize(s_sdlRenderer,&w,&h)) {
            SDL_FRect native=NativeRect(w,h);
            for(int i=0;i<4;i++) if(s_uiThumbnails[i]) {
                SDL_FRect r=s_uiThumbnailRects[i];
                r.x=native.x+r.x*native.w/320;
                r.y=native.y+r.y*native.h/200;
                r.w*=native.w/320;r.h*=native.h/200;
                SDL_RenderTexture(s_sdlRenderer,s_uiThumbnails[i],NULL,&r);
            }
        }
    }
    s_mapDrawn=false;
    if(s_captureRequested) s_capturedFrame=SDL_RenderReadPixels(s_sdlRenderer,NULL);
    CRT_EndFrame(s_sdlRenderer);
    SDL_RenderPresent(s_sdlRenderer);
    CRT_ResumeFrame(s_sdlRenderer);
}

static GraphicsDriverOps s_winOps =
{
    .Initialize = GRAP_SDL_Initialize,
    .Cleanup = GRAP_SDL_Cleanup,
    .Present = GRAP_BUF_Present,
    .FlushPendingPresent = GRAP_BUF_FlushPendingPresent,
    .SetPenColor = GRAP_BUF_SetPenColor,
    .SetPage = GRAP_BUF_SetPage,
    .PrintChar = GRAP_BUF_PrintChar,
    .ScrollWindow = GRAP_BUF_ScrollWindow,
    .Line = GRAP_BUF_Line,
    .Pset = GRAP_BUF_Pset,
    .FillWindow = GRAP_BUF_FillWindow,
    .LoadTileset = GRAP_BUF_LoadTileset,
    .UnloadTileset = GRAP_BUF_UnloadTileset,
    .AnimateTileset = GRAP_BUF_AnimateTileset,
    .UpdateTimeTileset = GRAP_BUF_UpdateTimeTileset,
    .ShowNextWDFrame = GRAP_BUF_ShowNextWDFrame,
    .AnimateWD = GRAP_BUF_AnimateWD,
    .AnimateOriginLogo = GRAP_BUF_AnimateOriginLogo,
    .PutAnimatedMoongateTile = GRAP_BUF_PutAnimatedMoongateTile,
    .PutTileRevealStep = GRAP_BUF_PutTileRevealStep,
    .PutTile = GRAP_BUF_PutTile,
    .PutImage = GRAP_BUF_PutImage,
    .PutBitImage = GRAP_BUF_PutBitImage,
    .TransferPage = GRAP_BUF_TransferPage,
    .TransferPage_Reveal = GRAP_BUF_TransferPage_Reveal
};

GraphicsDriverOps* GRAP_SDL_GetOps(void)
{
    return &s_winOps;
}
