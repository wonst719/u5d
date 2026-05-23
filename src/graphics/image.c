#include "common/common.h"
#include "common/memory.h"
#include "image.h"

bool IMAGE_GetBitImageView(byte* img, int idx, BitImageView* view)
{
    byte* rsrcBytes;
    int imageCount;
    u16 imageOffset;
    byte* imageBuf;

    rsrcBytes = img;
    imageCount = MEM_ReadU16LEOffset(rsrcBytes, 0);
    if (idx >= imageCount)
        return false;

    imageOffset = MEM_ReadU16LEOffset(rsrcBytes, 2 + idx * 2);

    imageBuf = &rsrcBytes[imageOffset];
    view->width = MEM_ReadU16LEOffset(imageBuf, 0);
    view->height = MEM_ReadU16LEOffset(imageBuf, 2);
    view->bits = &imageBuf[4];
    view->stride = (view->width + 7) / 8;

    return true;
}

static bool IMAGE_GetBitmapImageViewWithMask(byte* rsrcBytes, int idx, ImageView* outView)
{
    u16 imageOffset = MEM_ReadU16LEOffset(rsrcBytes, 2 + idx * 2);
    byte* imageBuf = &rsrcBytes[imageOffset];

    outView->width = MEM_ReadU16LEOffset(imageBuf, 0);
    outView->height = MEM_ReadU16LEOffset(imageBuf, 2);
    outView->pixels = &imageBuf[4];
    // TODO: identify mask layout
    outView->stride = ((outView->width + 7) / 8) * 4;
    outView->hasMask = true;
    outView->maskBits = 0;

    return true;
}

static bool IMAGE_GetBitmapImageView(byte* rsrcBytes, int idx, ImageView* outView)
{
    u32 imageOffset = MEM_ReadU32LEOffset(rsrcBytes, 2 + idx * 4);
    byte* imageBuf = &rsrcBytes[imageOffset];

    outView->width = MEM_ReadU16LEOffset(imageBuf, 0);
    outView->height = MEM_ReadU16LEOffset(imageBuf, 2);
    outView->pixels = &imageBuf[4];
    outView->stride = ((outView->width + 7) / 8) * 4;
    outView->hasMask = false;
    outView->maskBits = 0;

    return true;
}

bool IMAGE_GetImageView(byte* rsrc, int idx, ImageView* view)
{
    byte* rsrcBytes = rsrc;
    int imageCount = MEM_ReadU16LEOffset(rsrcBytes, 0);
    if (idx >= imageCount)
        return false;

    // TODO: how to differentiate? need more format info
    if (MEM_ReadU16LEOffset(rsrcBytes, 4) != 0)
        return IMAGE_GetBitmapImageViewWithMask(rsrcBytes, idx, view);

    return IMAGE_GetBitmapImageView(rsrcBytes, idx, view);
}
