#include "COMMON.H"

#include "FILE.H"

#include <stdio.h>
#include <stdlib.h>

// TODO: implement proper stream
typedef struct MemStream
{
    u8* buffer;
    int len;
    int pos;
} MemStream;

static int MemWriteU8(MemStream* stream, u8 b)
{
    if (stream->pos >= stream->len)
        return 0;

    stream->buffer[stream->pos++] = b;

    return 1;
}

typedef struct BitReader
{
    FILE* f;
    u32 bitBuffer;
    int bits;
} BitReader;

static int BrRead(BitReader* br, int n)
{
    ASSERT(br->bits + n <= 19);

    while (br->bits < n)
    {
        u8 b;
        if (!FILE_ReadU8(br->f, &b))
            return -1;

        br->bitBuffer |= (u32)b << br->bits;
        br->bits += 8;
    }

    int code = (int)(br->bitBuffer & ((1 << n) - 1));
    br->bitBuffer >>= n;
    br->bits -= n;

    return code;
}

enum
{
    LZW_CLEAR = 256,
    LZW_EOI = 257,
    LZW_FIRST = 258,
    LZW_MAX = 4096,
    LZW_MAXBITS = 12
};

static u8 LzwExpand(u16 code, u16* prefix, u8* suffix, u8* stack, int* sp)
{
    while (code >= 256)
    {
        stack[(*sp)++] = suffix[code];
        code = prefix[code];
    }

    stack[(*sp)++] = (u8)code;
    return (u8)code;
}

int LzwDecompressStream(FILE* fi, MemStream* fo, int outLen)
{
    u16 prefix[LZW_MAX];
    u8 suffix[LZW_MAX];
    u8 stack[LZW_MAX];

    BitReader br = {fi, 0, 0};

    int codeSize = 9;
    int nextCode = LZW_FIRST;
    int prevCode = -1;
    int produced = 0;

    for (;;)
    {
        if (produced >= outLen)
            break;

        int code = BrRead(&br, codeSize);
        if (code < 0)
            break;

        if (code == LZW_CLEAR)
        {
            codeSize = 9;
            nextCode = LZW_FIRST;
            prevCode = -1;
            continue;
        }

        if (code == LZW_EOI)
            break;

        int sp = 0;
        u8 first = 0;

        if (code < nextCode)
        {
            first = LzwExpand((u16)code, prefix, suffix, stack, &sp);

            while (sp > 0 && produced < outLen)
            {
                if (!MemWriteU8(fo, stack[--sp]))
                    return 0;

                produced++;
            }
        }
        else if (code == nextCode && prevCode >= 0)
        {
            first = LzwExpand((u16)prevCode, prefix, suffix, stack, &sp);

            while (sp > 0 && produced < outLen)
            {
                if (!MemWriteU8(fo, stack[--sp]))
                    return 0;

                produced++;
            }

            if (produced < outLen)
            {
                if (!MemWriteU8(fo, first))
                    return 0;

                produced++;
            }
        }
        else
        {
            debug("Error: invalid LZW code %d (next=%d)\n", code, nextCode);
            return 0;
        }

        if (prevCode >= 0 && nextCode < LZW_MAX)
        {
            prefix[nextCode] = (u16)prevCode;
            suffix[nextCode] = first;
            nextCode++;

            if (codeSize < LZW_MAXBITS && nextCode == (1 << codeSize))
                codeSize++;
        }

        prevCode = code;
    }

    if (produced != outLen)
    {
        debug("Error: produced %d bytes, expected %d (header)\n", produced, outLen);
        return 0;
    }

    return 1;
}

int LzwDecompressFile(FILE* fi, u8** out, u32* size)
{
    u32 outLen = 0;

    if (!FILE_ReadU32LE(fi, &outLen))
    {
        return 1;
    }

    u8* buf = malloc(outLen);

    MemStream stream = {buf, outLen, 0};

    int res = LzwDecompressStream(fi, &stream, outLen);

    if (!res)
    {
        *out = NULL;
        *size = 0;
        free(buf);

        return 1;
    }

    *out = buf;
    *size = outLen;

    return 0;
}
