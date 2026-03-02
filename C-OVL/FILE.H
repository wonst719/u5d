#ifndef _FILE_H
#define _FILE_H

int FILE_ReadFile(char* fileName, void* buffer, uint size, int offset);
void FILE_ReadSavegameFile(char* fileName);
void FILE_WriteSavegameFile(char* fileName);

#endif
