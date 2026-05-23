#include "common/common.h"
#include "common/memory.h"
#include "image.h"

bool IMAGE_GetBitImageView(byte* rsrc, int idx, BitImageView* view)
{
    int imageCount = MEM_ReadU16LEOffset(rsrc, 0);
    if (idx >= imageCount)
        return false;

    u16 imageOffset = MEM_ReadU16LEOffset(rsrc, 2 + idx * 2);

    byte* imageBuf = &rsrc[imageOffset];
    view->width = MEM_ReadU16LEOffset(imageBuf, 0);
    view->height = MEM_ReadU16LEOffset(imageBuf, 2);
    view->bits = &imageBuf[4];
    view->stride = (view->width + 7) / 8;

    return true;
}

// TODO: use BitImageView instance as a mask?

bool IMAGE_GetImageView(byte* rsrc, int idx, ImageView* view)
{
    int imageCount = MEM_ReadU16LEOffset(rsrc, 0);
    if (idx >= imageCount)
        return false;

    // even idx: image, odd idx: mask
    u16 imageOffset = MEM_ReadU16LEOffset(rsrc, 2 + (idx * 2) * 2);
    u16 maskOffset = MEM_ReadU16LEOffset(rsrc, 2 + (idx * 2 + 1) * 2);

    byte* imageBuf = &rsrc[imageOffset];
    view->width = MEM_ReadU16LEOffset(imageBuf, 0);
    view->height = MEM_ReadU16LEOffset(imageBuf, 2);
    view->pixels = &imageBuf[4];
    view->stride = ((view->width + 7) / 8) * 4;

    if (maskOffset != 0)
    {
        view->hasMask = true;

        byte* maskBuf = &rsrc[maskOffset];
        view->maskWidth = MEM_ReadU16LEOffset(maskBuf, 0);
        view->maskHeight = MEM_ReadU16LEOffset(maskBuf, 2);
        // size: (w * h + 7) / 8 bytes
        view->maskBits = &maskBuf[4];
    }
    else
    {
        view->hasMask = false;
        view->maskBits = NULL;
    }

    return true;
}
