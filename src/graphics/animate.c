
#include "common/common.h"
#include "common/memory.h"

#include "animate.h"

#include <string.h>

// T1K:0263
static const u8 s_maskBytes[0x20] =
{
    0x00, 0x00, 0x0f, 0x00, 0xf0, 0x00, 0xff, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0xf0, 0x0f, 0xff, 0x0f,
    0x00, 0xf0, 0x0f, 0xf0, 0xf0, 0xf0, 0xff, 0xf0,
    0x00, 0xff, 0x0f, 0xff, 0xf0, 0xff, 0xff, 0xff
};

// T1K:14de
static u16 s_tilesetEffectSeed = 0x7664;

static void AnimateTile_ShiftDown(byte* tiles, int base)
{
    byte tail[8];
    memcpy(tail, &tiles[base + 0x78], sizeof(tail));
    memmove(&tiles[base + 8], &tiles[base], 0x78);
    memcpy(&tiles[base], tail, sizeof(tail));
}

// 194c
static void AnimateTile_SwapPairs(u8* tiles, int off)
{
    u16 a0 = MEM_ReadU16LE(&tiles[off]);
    u16 a1 = MEM_ReadU16LE(&tiles[off + 2]);
    u16 b0 = MEM_ReadU16LE(&tiles[off + 0x10]);
    u16 b1 = MEM_ReadU16LE(&tiles[off + 0x12]);

    MEM_WriteU16LE(&tiles[off], b0);
    MEM_WriteU16LE(&tiles[off + 2], b1);
    MEM_WriteU16LE(&tiles[off + 0x10], a0);
    MEM_WriteU16LE(&tiles[off + 0x12], a1);
}

// 1963
static void AnimateTile_SwapPairsPlus4(u8* tiles, int off)
{
    AnimateTile_SwapPairs(tiles, off + 4);
}

// 1968
static void AnimateTile_SwapPairsTwice(u8* tiles, int off)
{
    AnimateTile_SwapPairs(tiles, off);
    AnimateTile_SwapPairsPlus4(tiles, off);
}

// d &= m
static void AnimateTile_MaskColor(u8* tiles, int off, int mask, int words)
{
    for (int i = 0; i < words; i++)
    {
        MEM_WriteU16LE(&tiles[off + i * 2], (u16)(MEM_ReadU16LE(&tiles[off + i * 2]) & mask));
    }
}

// d &= ~s
static void AnimateTile_MaskTile(u8* tiles, int dst, int src, int words)
{
    for (int i = 0; i < words; i++)
    {
        int off = i * 2;
        MEM_WriteU16LE(&tiles[dst + off], (u16)(MEM_ReadU16LE(&tiles[dst + off]) & (u16)~MEM_ReadU16LE(&tiles[src + off])));
    }
}

// d ^= m & n
// dst: si (sic), mask: di, noise tile: bx, count: cx
static void AnimateTile_XorMasked(u8* tiles, int dst, int mask, int noise, int count)
{
    for (int i = 0; i < count; i++)
    {
        tiles[dst + i] ^= tiles[noise + i] & tiles[mask + i];
    }
}

// d ^= m & n
// dst: si (sic), mask: di, noise tile: bx, count: cx
static void AnimateTile_XorMaskedBlocks(u8* tiles, int dst, int mask, int noise, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off++)
        {
            tiles[dst + block * 0x80 + off] ^= tiles[noise + off] & tiles[mask + block * 0x80 + off];
        }
    }
}

// d |= m & s
// dst: di, mask: si, src: bx, count: cx
static void AnimateTile_MixTilesUsingMask(u8* tiles, int dst, int mask, int src, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off += 2)
        {
            int dstOff = dst + block * 0x80 + off;
            int maskOff = mask + block * 0x80 + off;
            int srcOff = src + off;

            u16 mixed = (u16)(MEM_ReadU16LE(&tiles[maskOff]) & MEM_ReadU16LE(&tiles[srcOff]));
            MEM_WriteU16LE(&tiles[dstOff], (u16)(MEM_ReadU16LE(&tiles[dstOff]) | mixed));
        }
    }
}

// d = s | m
static void AnimateTile_StoreSrcOrMask(u8* tiles, int dst, int src, int mask, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off += 2)
        {
            int dstOff = dst + block * 0x80 + off;
            int srcOff = src + block * 0x80 + off;

            MEM_WriteU16LE(&tiles[dstOff], (u16)(MEM_ReadU16LE(&tiles[srcOff]) | MEM_ReadU16LE(&tiles[mask + off])));
        }
    }
}

static void AnimateTile_InvertWords(u8* tiles, int off, int words)
{
    for (int i = 0; i < words; i++)
    {
        int wordOff = off + i * 2;
        MEM_WriteU16LE(&tiles[wordOff], (u16)~MEM_ReadU16LE(&tiles[wordOff]));
    }
}

static void AnimateTile_MaskedMergeBlock(u8* tiles, int dst, int src, int noise)
{
    AnimateTile_InvertWords(tiles, src, 0x40);
    for (int i = 0; i < 0x80; i++)
    {
        tiles[dst + i] &= tiles[src + i];
    }

    AnimateTile_InvertWords(tiles, src, 0x40);

    for (int i = 0; i < 0x80; i++) // T1K BUG: i < 0x200
    {
        tiles[dst + i] = (u8)((tiles[noise + i] & tiles[src + i]) | tiles[dst + i]);
    }
}

static void AnimateTile_GenerateMasks(u8* tiles)
{
    int off = 0xf400;

    for (int i = 0; i < 0x20; i++)
    {
        u8 b;
        u16 ax;
        u16 dx;

        s_tilesetEffectSeed = MEM_Ror16((u16)(s_tilesetEffectSeed + 0x9248), 3);
        s_tilesetEffectSeed = (u16)((s_tilesetEffectSeed ^ 0x9248) + 0x11);

        b = (u8)s_tilesetEffectSeed;
        dx = MEM_ReadU16LE(&s_maskBytes[b >> 4]);
        ax = MEM_ReadU16LE(&s_maskBytes[b & 0xf]);

        MEM_WriteU16LE(&tiles[off + 0x000], (u16)(ax & 0xaaaa));
        MEM_WriteU16LE(&tiles[off + 0x080], (u16)(ax & 0xdddd));
        MEM_WriteU16LE(&tiles[off + 0x100], (u16)((ax & 0xdddd) & 0xcccc));
        MEM_WriteU16LE(&tiles[off + 0x180], (u16)(ax & 0x9999));
        off += 2;

        MEM_WriteU16LE(&tiles[off + 0x000], (u16)(dx & 0xaaaa));
        MEM_WriteU16LE(&tiles[off + 0x080], (u16)(dx & 0xdddd));
        MEM_WriteU16LE(&tiles[off + 0x100], (u16)((dx & 0xdddd) & 0xcccc));
        MEM_WriteU16LE(&tiles[off + 0x180], (u16)(dx & 0x9999));
        off += 2;
    }
}

// T1K:196e (build -> puttile -> restore)
void AnimateTile_BuildMoongateTile(byte* tileset, int visibleRows, byte floorType, byte* backup)
{
    int visibleBytes;
    int visibleOffset;
    int floorOffset;

    memcpy(backup, &tileset[0x8b00], 0x80); // 8b00: magic circle tile (used as scratch)

    floorOffset = floorType == 0xff ? 0x2200 : 0x0280; // 2200: red brick floor, 0280: grass
    memcpy(&tileset[0x8b00], &tileset[floorOffset], 0x80);

    visibleBytes = visibleRows * 8;
    if (visibleBytes != 0)
    {
        visibleOffset = 0x8b00 + 0x80 - visibleBytes;
        memcpy(&tileset[visibleOffset], &tileset[0x6e00], visibleBytes); // 6e00: moongate
    }
}

void AnimateTile_RestoreMoongateTile(byte* tileset, byte* backup)
{
    memcpy(&tileset[0x8b00], backup, 0x80);
}

// animate tiles
void AnimateTileset(byte* tileset)
{
    AnimateTile_GenerateMasks(tileset);

    // animate water

    // 15ef, 1620, 1651, 1682
    // water 1, 2, 3, lava
    AnimateTile_ShiftDown(tileset, 0x0080);
    AnimateTile_ShiftDown(tileset, 0x0100);
    AnimateTile_ShiftDown(tileset, 0x0180);
    AnimateTile_ShiftDown(tileset, 0x4780);

    // 16b5: remove light blue from 3000..3500
    AnimateTile_MaskColor(tileset, 0x3000, 0x6666, 0x280);

    // 16c4: fixup horiz bridge (3500)
    memset(tileset + 0x3500, 0, 0x10);
    memset(tileset + 0x3570, 0, 0x10);

    // 16d6: fixup vert bridge (3580 <- 3d80)
    AnimateTile_MaskTile(tileset, 0x3580, 0x3d80, 0x40);

    // 16e9: remove light blue from 3600..3800
    AnimateTile_MaskColor(tileset, 0x3600, 0x6666, 0x100);

    // 16f8: mix mask (3000: water, 3800: mask)
    AnimateTile_MixTilesUsingMask(tileset, 0x3000, 0x3800, 0x0180, 16);

    // 1719: merge block (8400: some light, 8000: flash, f580: noise)
    AnimateTile_MaskedMergeBlock(tileset, 0x8400, 0x8000, 0xf580);
    // 1790 (da00: some light, 8000: flash, f480: noise)
    AnimateTile_MaskedMergeBlock(tileset, 0xda00, 0x8000, 0xf480);

    // 1807
    AnimateTile_MaskTile(tileset, 0x1a00, 0x6800, 0x100);

    // 181a
    AnimateTile_MixTilesUsingMask(tileset, 0x1a00, 0x6800, 0x0180, 4);

    // 183b (7200: water, 6800: diagonal masks)
    AnimateTile_StoreSrcOrMask(tileset, 0x7200, 0x6800, 0x0180, 4);
    // 1858
    AnimateTile_XorMaskedBlocks(tileset, 0x5800, 0x6000, 0xf500, 4);
    // 1884
    AnimateTile_XorMaskedBlocks(tileset, 0x5e00, 0x6600, 0xf500, 4);
    // 18b0
    AnimateTile_XorMasked(tileset, 0x6f00, 0x6100, 0xf580, 0x80);

    // flags, fireplaces, etc.
    // 18d2
    if (s_tilesetEffectSeed & 1) AnimateTile_SwapPairsTwice(tileset, 0x0900);
    // 18e1
    if (s_tilesetEffectSeed & 2) AnimateTile_SwapPairs(tileset, 0x0a10);
    // 18f0
    if (s_tilesetEffectSeed & 4) AnimateTile_SwapPairsTwice(tileset, 0x0a80);
    // 18ff
    if (s_tilesetEffectSeed & 8) AnimateTile_SwapPairsTwice(tileset, 0x1f00);
    // 190e
    if (s_tilesetEffectSeed & 0x10) AnimateTile_SwapPairsPlus4(tileset, 0x9088);
    // 191d
    if (s_tilesetEffectSeed & 0x20) AnimateTile_SwapPairs(tileset, 0x9188);
    // 192c
    if (s_tilesetEffectSeed & 0x40) AnimateTile_SwapPairsPlus4(tileset, 0x9688);
    // 193b
    if (s_tilesetEffectSeed & 1) AnimateTile_SwapPairs(tileset, 0x9788);
}
