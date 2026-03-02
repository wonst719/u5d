#include "COMMON.H"

#include <stdio.h>
#include <stdlib.h>

// TODO: implement proper stream
typedef struct MemStream
{
    u8* buffer;
    int len;
    int pos;
} MemStream;

static int write_u8_mem(MemStream* stream, u8 b)
{
    if (stream->pos >= stream->len)
        return 0;

    stream->buffer[stream->pos++] = b;

    return 1;
}

static int read_u32le(FILE* f, u32* out)
{
    u8 b[4];

    if (fread(b, 1, 4, f) != 4)
        return 0;

    *out = (u32)b[0] | ((u32)b[1] << 8) | ((u32)b[2] << 16) | ((u32)b[3] << 24);

    return 1;
}

static int read_u8(FILE* f, u8* out)
{
    int c = fgetc(f);
    if (c == EOF)
        return 0;

    *out = (u8)c;

    return 1;
}

typedef struct BitReader
{
    FILE* f;
    u32 bitbuf;
    int bits;
} BitReader;

static int br_read(BitReader* br, int n)
{
    ASSERT(br->bits + n <= 19);

    while (br->bits < n)
    {
        u8 b;
        if (!read_u8(br->f, &b))
            return -1;

        br->bitbuf |= (u32)b << br->bits;
        br->bits += 8;
    }

    int code = (int)(br->bitbuf & ((1 << n) - 1));
    br->bitbuf >>= n;
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

static u8 lzw_expand(u16 code, u16* prefix, u8* suffix, u8* stack, int* sp)
{
    while (code >= 256)
    {
        stack[(*sp)++] = suffix[code];
        code = prefix[code];
    }

    stack[(*sp)++] = (u8)code;
    return (u8)code;
}

int lzw_decompress_stream(FILE* fi, MemStream* fo, int out_len)
{
    u16 prefix[LZW_MAX];
    u8 suffix[LZW_MAX];
    u8 stack[LZW_MAX];

    BitReader br = {fi, 0, 0};

    int code_size = 9;
    int next_code = LZW_FIRST;
    int prev_code = -1;
    int produced = 0;

    for (;;)
    {
        if (produced >= out_len)
            break;

        int code = br_read(&br, code_size);
        if (code < 0)
            break;

        if (code == LZW_CLEAR)
        {
            code_size = 9;
            next_code = LZW_FIRST;
            prev_code = -1;
            continue;
        }

        if (code == LZW_EOI)
            break;

        int sp = 0;
        u8 first = 0;

        if (code < next_code)
        {
            first = lzw_expand((u16)code, prefix, suffix, stack, &sp);

            while (sp > 0 && produced < out_len)
            {
                if (!write_u8_mem(fo, stack[--sp]))
                    return 0;

                produced++;
            }
        }
        else if (code == next_code && prev_code >= 0)
        {
            first = lzw_expand((u16)prev_code, prefix, suffix, stack, &sp);

            while (sp > 0 && produced < out_len)
            {
                if (!write_u8_mem(fo, stack[--sp]))
                    return 0;

                produced++;
            }

            if (produced < out_len)
            {
                if (!write_u8_mem(fo, first))
                    return 0;

                produced++;
            }
        }
        else
        {
            fprintf(stderr, "Error: invalid LZW code %d (next=%d)\n", code, next_code);
            return 0;
        }

        if (prev_code >= 0 && next_code < LZW_MAX)
        {
            prefix[next_code] = (u16)prev_code;
            suffix[next_code] = first;
            next_code++;

            if (code_size < LZW_MAXBITS && next_code == (1 << code_size))
                code_size++;
        }

        prev_code = code;
    }

    if (produced != out_len)
    {
        fprintf(stderr, "Error: produced %d bytes, expected %d (header)\n", produced, out_len);
        return 0;
    }

    return 1;
}

int lzw_decompress_file(FILE* fi, u8** out)
{
    u32 out_len = 0;

    if (!read_u32le(fi, &out_len))
    {
        return 1;
    }

    u8* buf = (u8*)malloc(out_len);

    MemStream stream = {buf, out_len, 0};

    int res = lzw_decompress_stream(fi, &stream, out_len);

    if (!res)
    {
        *out = NULL;
        free(buf);

        return 1;
    }

    *out = buf;

    return 0;
}
