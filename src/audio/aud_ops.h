#ifndef _GRAPHICS_GRAP_OPS_H
#define _GRAPHICS_GRAP_OPS_H

typedef struct AudioMusicDriverOps
{
    void (*Initialize)(void);
    void (*Cleanup)(void);
    void (*PlayBgm)(int id);
    void (*StopBgm)(void);
} AudioMusicDriverOps;

typedef struct AudioSfxDriverOps
{
    void (*Initialize)(void);
    void (*Cleanup)(void);
    void (*PlaySfx)(int id);
    void (*StopSfx)(void);
} AudioSfxDriverOps;

#endif
