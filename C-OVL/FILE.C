#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

// FMT 00027a60
int FILE_ReadFile(char* fileName, void* buffer, uint size, int offset)
{
	FILE* stream;

	if ((fileName[0] == 'A' || fileName[0] == 'a') && fileName[1] == ':')
	{
		// FUN_0034074();
		return;
	}

	stream = fopen(fileName, "rb");
	if (stream == 0)
	{
		return -1;
	}

	fseek(stream, offset, SEEK_SET);
	fread(buffer, size, 1, stream);
	fclose(stream);

	return 0;
}
