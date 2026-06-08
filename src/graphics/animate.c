
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

static void AnimateTile_ShiftDown(byte* tileset, int base)
{
    byte tail[8];
    memcpy(tail, &tileset[base + 0x78], sizeof(tail));
    memmove(&tileset[base + 8], &tileset[base], 0x78);
    memcpy(&tileset[base], tail, sizeof(tail));
}

// T1K:194c
static void AnimateTile_SwapPairs(u8* tileset, int off)
{
    u16 a0 = MEM_ReadU16LE(&tileset[off]);
    u16 a1 = MEM_ReadU16LE(&tileset[off + 2]);
    u16 b0 = MEM_ReadU16LE(&tileset[off + 0x10]);
    u16 b1 = MEM_ReadU16LE(&tileset[off + 0x12]);

    MEM_WriteU16LE(&tileset[off], b0);
    MEM_WriteU16LE(&tileset[off + 2], b1);
    MEM_WriteU16LE(&tileset[off + 0x10], a0);
    MEM_WriteU16LE(&tileset[off + 0x12], a1);
}

// T1K:1963
static void AnimateTile_SwapPairsPlus4(u8* tileset, int off)
{
    AnimateTile_SwapPairs(tileset, off + 4);
}

// T1K:1968
static void AnimateTile_SwapPairsTwice(u8* tileset, int off)
{
    AnimateTile_SwapPairs(tileset, off);
    AnimateTile_SwapPairsPlus4(tileset, off);
}

// d &= m
static void AnimateTile_MaskColor(u8* tileset, int off, int mask, int words)
{
    for (int i = 0; i < words; i++)
    {
        MEM_WriteU16LE(&tileset[off + i * 2], (u16)(MEM_ReadU16LE(&tileset[off + i * 2]) & mask));
    }
}

// d &= ~s
static void AnimateTile_MaskTile(u8* tileset, int dst, int src, int words)
{
    for (int i = 0; i < words; i++)
    {
        int off = i * 2;
        MEM_WriteU16LE(&tileset[dst + off], (u16)(MEM_ReadU16LE(&tileset[dst + off]) & (u16)~MEM_ReadU16LE(&tileset[src + off])));
    }
}

// d ^= m & n
// dst: si (sic), mask: di, noise tile: bx, count: cx
static void AnimateTile_XorMasked(u8* tileset, int dst, int mask, int noise, int count)
{
    for (int i = 0; i < count; i++)
    {
        tileset[dst + i] ^= tileset[noise + i] & tileset[mask + i];
    }
}

// d ^= m & n
// dst: si (sic), mask: di, noise tile: bx, count: cx
static void AnimateTile_XorMaskedBlocks(u8* tileset, int dst, int mask, int noise, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off++)
        {
            tileset[dst + block * 0x80 + off] ^= tileset[noise + off] & tileset[mask + block * 0x80 + off];
        }
    }
}

// d |= m & s
// dst: di, mask: si, src: bx, count: cx
static void AnimateTile_MixTilesUsingMask(u8* tileset, int dst, int mask, int src, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off += 2)
        {
            int dstOff = dst + block * 0x80 + off;
            int maskOff = mask + block * 0x80 + off;
            int srcOff = src + off;

            u16 mixed = (u16)(MEM_ReadU16LE(&tileset[maskOff]) & MEM_ReadU16LE(&tileset[srcOff]));
            MEM_WriteU16LE(&tileset[dstOff], (u16)(MEM_ReadU16LE(&tileset[dstOff]) | mixed));
        }
    }
}

// d = s | m
static void AnimateTile_StoreSrcOrMask(u8* tileset, int dst, int src, int mask, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off += 2)
        {
            int dstOff = dst + block * 0x80 + off;
            int srcOff = src + block * 0x80 + off;

            MEM_WriteU16LE(&tileset[dstOff], (u16)(MEM_ReadU16LE(&tileset[srcOff]) | MEM_ReadU16LE(&tileset[mask + off])));
        }
    }
}

static void AnimateTile_InvertWords(u8* tileset, int off, int words)
{
    for (int i = 0; i < words; i++)
    {
        int wordOff = off + i * 2;
        MEM_WriteU16LE(&tileset[wordOff], (u16)~MEM_ReadU16LE(&tileset[wordOff]));
    }
}

static void AnimateTile_MaskedMergeBlock(u8* tileset, int dst, int src, int noise)
{
    AnimateTile_InvertWords(tileset, src, 0x40);
    for (int i = 0; i < 0x80; i++)
    {
        tileset[dst + i] &= tileset[src + i];
    }

    AnimateTile_InvertWords(tileset, src, 0x40);

    for (int i = 0; i < 0x80; i++) // T1K BUG: i < 0x200
    {
        tileset[dst + i] = (u8)((tileset[noise + i] & tileset[src + i]) | tileset[dst + i]);
    }
}

// T1K:156c
static void AnimateTile_GenerateMasks(u8* tileset)
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

        MEM_WriteU16LE(&tileset[off + 0x000], (u16)(ax & 0xaaaa));
        MEM_WriteU16LE(&tileset[off + 0x080], (u16)(ax & 0xdddd));
        MEM_WriteU16LE(&tileset[off + 0x100], (u16)((ax & 0xdddd) & 0xcccc));
        MEM_WriteU16LE(&tileset[off + 0x180], (u16)(ax & 0x9999));
        off += 2;

        MEM_WriteU16LE(&tileset[off + 0x000], (u16)(dx & 0xaaaa));
        MEM_WriteU16LE(&tileset[off + 0x080], (u16)(dx & 0xdddd));
        MEM_WriteU16LE(&tileset[off + 0x100], (u16)((dx & 0xdddd) & 0xcccc));
        MEM_WriteU16LE(&tileset[off + 0x180], (u16)(dx & 0x9999));
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

// 1562
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

// T1K:1bce
static void AnimateTime_BackupAndModifyLine(byte* tileset, int offset, byte* backup)
{
    memcpy(backup, &tileset[offset], 8);
    memcpy(&tileset[offset], &tileset[offset - 0x70], 8);
}

// T1K:1bf1
static void AnimateTime_RestoreLine(byte* tileset, int offset, byte* backup)
{
    memcpy(&tileset[offset], backup, 8);
}

// T1K:1c31
static void AnimateTime_ClearClockHandBackground(byte* tileset, int offset)
{
    // "rerolled"
    static const byte s_andOffsets[] = { 0x03, 0x0b, 0x0c, 0x13 };

    for (int i = 0; i < (int)sizeof(s_andOffsets); i++)
    {
        tileset[offset + s_andOffsets[i]] = (byte)((tileset[offset + s_andOffsets[i]] & 0xf0) | 0x04);
    }

    tileset[offset + 0x04] = 0x44;
    tileset[offset + 0x14] = 0x44;
}

// T1K:1c78
static const u16 s_clockHandRowOffsets[12] =
{
    0x0010, 0x0010, 0x0010, 0x0018, 0x0020, 0x0020,
    0x0020, 0x0020, 0x0020, 0x0018, 0x0010, 0x0010
};

// T1K:1c90
static const u16 s_clockHandColumnOffsets[12] =
{
    0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
    0x0004, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003
};

// T1K:1ca8
static const byte s_clockHandMasks[12] =
{
    0xf0, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0xf0, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
};

// T1K:1cb4
static void AnimateTime_DrawClockHand(byte* tileset, byte handPosition)
{
    int offset;

    handPosition %= 12;
    // 7d00: clock
    offset = 0x7d00 + s_clockHandRowOffsets[handPosition] + s_clockHandColumnOffsets[handPosition];
    tileset[offset] |= s_clockHandMasks[handPosition];
    tileset[offset + 0x80] |= s_clockHandMasks[handPosition];
}

// T1K:1d3c
static void AnimateTime_BitplaneSwapBlock(byte* tileset, int offset, int blocks)
{
    int count = blocks * 0x80;

    for (int i = 0; i < count; i += 2)
    {
        u16 value = MEM_ReadU16LE(&tileset[offset + i]);
        u16 mixed = (u16)(((value & 0x2222) << 1) |
            ((value & 0x4444) >> 1) |
            (value & 0x9999));

        MEM_WriteU16LE(&tileset[offset + i], mixed);
    }
}

// T1K:1dec
static const byte s_highMap[16] =
{
    0x00, 0x50, 0x40, 0x40, 0x20, 0x10, 0x20, 0x70,
    0x80, 0xc0, 0xc0, 0xc0, 0xa0, 0x90, 0xe0, 0xf0
};

// T1K:1dfc
static const byte s_lowMap[16] =
{
    0x00, 0x05, 0x04, 0x04, 0x02, 0x01, 0x02, 0x07,
    0x08, 0x0c, 0x0c, 0x0c, 0x0a, 0x09, 0x0e, 0x0f
};

// T1K:1e0c
// make tiles green (used in ending)
static void AnimateTime_RemapTileColor(byte* tileset, int offset)
{
    for (int i = 0; i < 0x80; i++)
    {
        byte value = tileset[offset + i];
        tileset[offset + i] = (byte)(s_highMap[value >> 4] | s_lowMap[value & 0x0f]);
    }
}

// T1K:1ba0
static byte s_tileBackup1[8];
// T1K:1ba8
static byte s_tileBackup2[8];

// mode: ax
// T1K:1bb0
void AnimateTimeTileset(byte* tileset, int mode, byte hour, byte minute)
{
    if (mode == 0)
    {
        // backup original line and copy top line
        // 6400: ladder
        AnimateTime_BackupAndModifyLine(tileset, 0x6470, s_tileBackup1);
        // 8b80: ladder w/man
        AnimateTime_BackupAndModifyLine(tileset, 0x8bf0, s_tileBackup2);
    }
    else if (mode == 1)
    {
        // restore line
        AnimateTime_RestoreLine(tileset, 0x6470, s_tileBackup1);
        AnimateTime_RestoreLine(tileset, 0x8bf0, s_tileBackup2);
    }
    else if (mode == 2)
    {
        // 7d00: clock frame 1
        AnimateTime_ClearClockHandBackground(tileset, 0x7d10);
        // 7d80: clock frame 2
        AnimateTime_ClearClockHandBackground(tileset, 0x7d90);

        if (hour >= 12)
        {
            hour -= 12;
        }

        AnimateTime_DrawClockHand(tileset, hour);
        AnimateTime_DrawClockHand(tileset, minute / 5);
    }
    else if (mode == 4) // 1cd1
    {
        // 1d60 "rerolled"
        static const u16 offsets[] =
        {
            0x2200, 0x2e00, 0x2e80, 0x4800, 0x4900, 0x4a00, 0x4b00,
            0x4d80, 0x5580, 0x5600, 0x5780, 0x5800, 0x5880, 0x5f80,
            0x6e00, 0x8400, 0x8700, 0x8d00, 0x9c00, 0x9c80,
            0x9d00, 0x9d80
        };

        for (int i = 0; i < ARRAYSIZE(offsets); i++)
        {
            AnimateTime_RemapTileColor(tileset, offsets[i]);
        }
    }
    else // if (mode == 3) // 1cd9
    {
        AnimateTime_BitplaneSwapBlock(tileset, 0x0280, 1);
        AnimateTime_BitplaneSwapBlock(tileset, 0x0f00, 1);
        AnimateTime_BitplaneSwapBlock(tileset, 0x0f80, 1);
        AnimateTime_BitplaneSwapBlock(tileset, 0x2600, 1);
        AnimateTime_BitplaneSwapBlock(tileset, 0x6500, 1);
        AnimateTime_BitplaneSwapBlock(tileset, 0x1000, 7);
        AnimateTime_BitplaneSwapBlock(tileset, 0x1800, 8);
        AnimateTime_BitplaneSwapBlock(tileset, 0x3000, 0x10);
    }
}
