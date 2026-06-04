#include "common/common.h"

#include <stdio.h>
#include <string.h>

int FILE_ReadU32LE(FILE* fp, u32* out)
{
    u8 b[4];

    if (fread(b, 1, 4, fp) != 4)
        return 0;

    *out = (u32)b[0] | ((u32)b[1] << 8) | ((u32)b[2] << 16) | ((u32)b[3] << 24);

    return 1;
}

int FILE_ReadU16LE(FILE* fp, u16* out)
{
    u8 b[2];

    if (fread(b, 1, 2, fp) != 2)
        return 0;

    *out = (u16)b[0] | ((u16)b[1] << 8);

    return 1;
}

int FILE_ReadU8(FILE* fp, u8* out)
{
    int c = fgetc(fp);
    if (c == EOF)
        return 0;

    *out = (u8)c;

    return 1;
}

int FILE_WriteU32LE(FILE* fp, u32 in)
{
    u8 b[4];

    b[0] = (u8)in;
    b[1] = (u8)(in << 8);
    b[2] = (u8)(in << 16);
    b[3] = (u8)(in << 24);

    if (fwrite(b, 1, 4, fp) != 4)
        return 0;

    return 1;
}

int FILE_WriteU16LE(FILE* fp, u16 in)
{
    u8 b[2];

    b[0] = (u8)in;
    b[1] = (u8)(in << 8);

    if (fwrite(b, 1, 2, fp) != 2)
        return 0;

    return 1;
}

int FILE_WriteU8(FILE* fp, u8 in)
{
    int ret = fputc(in, fp);
    if (ret == EOF)
        return 0;

    return 1;
}

int FILE_ReadFile(char* fileName, void* buffer, uint size, int offset)
{
	FILE* stream;

    char buf[256];
    if (!strcmp(fileName, "BRIT.OOL") || !strcmp(fileName, "UNDER.OOL") || !strcmp(fileName, "SAVED.OOL") ||
        !strcmp(fileName, "SAVED.GAM"))
    {
        sprintf(buf, "SAVEGAME\\%s", fileName);
        fileName = buf;
    }
    else if (!strcmp(fileName, "party.sav"))
    {
        sprintf(buf, "U4SAVE\\%s", fileName);
        fileName = buf;
    }

	stream = fopen(fileName, "rb");
	if (stream == 0)
	{
		return -1;
	}

	fseek(stream, offset, SEEK_SET);
	fread(buffer, 1, size, stream);
	fclose(stream);

	return 0;
}

int FILE_WriteFile(char* fileName, void* buffer, uint size, int offset)
{
    FILE* stream;

    char buf[256];
    if (!strcmp(fileName, "BRIT.OOL") || !strcmp(fileName, "UNDER.OOL") || !strcmp(fileName, "SAVED.OOL") ||
        !strcmp(fileName, "SAVED.GAM"))
    {
        sprintf(buf, "SAVEGAME\\%s", fileName);
        fileName = buf;
    }

    stream = fopen(fileName, "wb");
    if (stream == 0)
    {
        return -1;
    }

    fseek(stream, offset, SEEK_SET);
    fwrite(buffer, size, 1, stream);
    fclose(stream);

    return 0;
}
