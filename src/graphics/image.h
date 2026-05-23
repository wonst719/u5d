#ifndef _GRAPHICS_IMAGE_H
#define _GRAPHICS_IMAGE_H

#include "common/common.h"

// 1bit image
typedef struct BitImageView
{
    u16 width;
    u16 height;
    u8* bits;
    int stride;
} BitImageView;

// 4bit image
typedef struct ImageView
{
    u16 width;
    u16 height;
    u8* pixels;
    int stride;
    bool hasMask;
    u8* maskBits;
} ImageView;

extern bool IMAGE_GetBitImageView(byte* rsrc, int idx, BitImageView* view);
extern bool IMAGE_GetImageView(byte* rsrc, int idx, ImageView* view);

#endif
