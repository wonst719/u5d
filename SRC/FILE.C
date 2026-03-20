#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>

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

#ifdef _WIN32

#define READ_16(TARGET) /*printf("%s: %d\n", #TARGET, (int)ftell(stream)); */fread(&TARGET, 2, 1, stream)
#define READ_8(TARGET) /*printf("%s: %d\n", #TARGET, (int)ftell(stream)); */fread(&TARGET, 1, 1, stream)

#define WRITE_16(TARGET) /*printf("%s: %d\n", #TARGET, (int)ftell(stream)); */ fwrite(&TARGET, 2, 1, stream)
#define WRITE_8(TARGET) /*printf("%s: %d\n", #TARGET, (int)ftell(stream)); */ fwrite(&TARGET, 1, 1, stream)

// based on FMT
int FILE_ReadSavegameFile(char* fileName)
{
    FILE* stream; 

    char buf[256];
    if (!strcmp(fileName, "BRIT.OOL") || !strcmp(fileName, "UNDER.OOL") || !strcmp(fileName, "SAVED.OOL") ||
        !strcmp(fileName, "SAVED.GAM"))
    {
        sprintf(buf, "SAVEGAME\\%s", fileName);
        fileName = buf;
    }

	stream = fopen(fileName, "rb");
	if (!stream)
		return -1;

	ASSERT(sizeof(S_55a8) == 0x20);

	READ_16(D_55a6);
	fread(D_55a8_party, 0x20, 0x10, stream);
	READ_16(D_57a8); // 3dfb4
	READ_16(D_57aa); // 3dfb6
    READ_8(D_57ac); // 3dfb8
    READ_8(D_57ad); // 3dfb9_gem_count
    READ_8(D_57ae); // 3dfba
    READ_8(D_57af); // 3dfbb
    READ_8(D_57b0); // 3dfbc
    READ_8(D_57b1); // 3dfbd
    READ_8(D_57b2); // 3dfbe
    READ_8(D_57b3); // 3dfbf
    READ_8(D_57b4); // 3dfc0
    READ_8(D_57b5); // 3dfc1
    fread(D_57b6, 4, 1, stream); // 3dfc4
    READ_8(D_57ba); // 3dfc8
    READ_8(D_57bb); // 3dfc9
    READ_8(D_57bc); // 3dfca
    READ_8(D_57bd); // 3dfcb
    READ_8(D_57be); // 3dfcc
    READ_8(D_57bf); // 3dfcd
    // FMT pad 2bytes
    fread(D_57c0, 0x30, 1, stream); // 3dfd0
    fread(D_57f0, 0x30, 1, stream); // 3e000
    fread(D_5820, 8, 1, stream); // 3e030
    fread(D_5828, 8, 1, stream); // 3e038
    fread(D_5830, 8, 1, stream); // 3e040
    fread(D_5838, 8, 1, stream); // 3e048
    fread(D_5840, 8, 1, stream); // 3e050
    fread(D_5848, 8, 1, stream); // 3e058
    fread(D_5850, 8, 1, stream); // 3e060
    fread(D_5858, 3, 1, stream); // 3e068
    READ_8(D_585b); // 3e06b
    fread(D_585c, 0x18, 1, stream); // 3e06c
    READ_16(D_5874); // 3e084
    READ_16(D_5876); // 3e086
    READ_16(D_5878); // 3e088
    READ_8(D_587a); // 3e08a
    READ_8(D_587b); // 3e08b
    READ_8(D_587c); // 3e08c
    READ_8(D_587d); // 3e08d
    READ_8(D_587e); // 3e08e
    READ_8(D_587f); // 3e08f
    READ_8(D_5880); // 3e090
    READ_8(D_5881); // 3e091
    READ_8(D_5882); // 3e092
    READ_8(D_5883); // 3e093
    READ_8(D_5884); // 3e094
    READ_8(D_5885); // 3e095
    READ_8(D_5886); // 3e096
    READ_8(D_5887); // 3e097
    READ_8(D_5888); // 3e098
    READ_8(D_5889); // 3e099
    READ_8(D_588a); // 3e09a
    READ_8(D_588b); // 3e09b
    READ_8(D_588c); // 3e09c
    READ_8(D_588d); // 3e09d
    READ_8(D_588e); // 3e09e
    READ_8(D_588f); // 3e09f
    READ_8(D_5890); // 3e0a0
    READ_8(D_5891); // 3e0a1
    READ_8(D_5892_wind_dir); // 0003e0a2
    READ_8(D_5893_map_id); // 3e0a3_5893_map_id
    READ_8(D_5894); // 3e0a4
    READ_8(D_5895_map_level); // 3e0a5_5895_map_level
    READ_8(D_5896_map_x); // 3e0a6_5896_map_x
    READ_8(D_5897_map_y); // 3e0a7_5897_map_y
    READ_8(D_5898); // 3e0a8
    READ_8(D_5899); // 3e0a9
    READ_8(D_589a); // 3e0aa
    READ_8(D_589b); // 3e0ab
    READ_8(D_589c); // 3e0ac
    READ_8(D_589d); // 3e0ad
    READ_8(D_589e); // 3e0ae
    READ_8(D_589f); // 3e0af
    READ_8(D_58a0); // 3e0b0
    READ_8(D_58a1); // 3e0b1
    READ_8(D_58a2); // 3e0b2
    READ_8(D_58a3); // 3e0b3_58a3_battle_finish_flg
    READ_8(D_58a4); // 3e0b4
    READ_8(D_58a5); // 3e0b5
    READ_8(D_58a6); // 3e0b6
    READ_8(D_58a7); // 3e0b7
    fread(&D_58a8, 0x20, 1, stream); // 3e0b8
    fread(&D_58c8, 3, 1, stream); // 3e0d8
    READ_8(D_58cb); // 3e0db
    READ_16(D_58cc); // 3e0dc
    READ_16(D_58ce); // 3e0de
    fread(D_58d0, 8, 1, stream); // 3e0e0
    fread(D_58d8, 8, 1, stream); // 3e0e8
    fread(D_58e0, 0xe, 1, stream); // 3e0f0
    // FMT pad 1byte
    fread(D_58ee, 0x20, 1, stream); // 3e100
    fread(D_590e, 0x20, 1, stream); // 3e120
    fread(D_592e, 0x20, 1, stream); // 3e140
    READ_8(D_594e); // 3e160
    READ_8(D_594f); // 3e161
    READ_8(D_5950); // 3e162
    READ_8(D_5951); // 3e163
    READ_8(D_5952); // 3e164
    READ_8(D_5953); // 3e165
    READ_8(D_5954); // 3e166
    READ_8(D_5955); // 3e167
    READ_8(D_5956); // 3e168
    READ_8(D_5957); // 3e169
    READ_8(D_5958); // 3e16a
    READ_8(D_5959); // 3e16b
    fread(D_595a, 0x200, 1, stream); // 3e16c; map data
    fread(D_5b5a, 0x80, 1, stream); // 3e36c
    fread(D_5bda, 0x80, 1, stream); // 3e3ec
    fread(D_5c5a, 0x100, 1, stream); // 3e46c
    READ_16(D_5d5a); // 3e56c
    READ_16(D_5d5c); // 3e56e
    fread(D_5d5e, 0x200, 1, stream); // 3e570
    fread(D_5f5e, 0x200, 1, stream); // 3e770
    fread(D_615e, 0x400, 1, stream); // 3e970
    fread(D_655e, 0x40, 1, stream); // 3ed70
    fread(D_659e, 0x20, 1, stream); // 3edb0
    // fread(D_659e, 0x20, 1, stream); // 3edb0 ; FMT sic
    READ_8(D_65be); // 3edd0
    READ_8(D_65bf); // 3edd1
    READ_16(D_65c0); // 3edd2
    fread(D_65c2, 0x40, 1, stream); // 3edd4
    READ_8(D_6602);// 3ee14
    READ_8(D_6603);// 3ee15
    READ_8(D_6604);// 3ee16
    READ_8(D_6605);// 3ee17
    //READ_16(D_6606);// 3ee18

    int pos = (int)ftell(stream);
    printf("pos: %d\n", pos);

    fclose(stream);

    //ASSERT(pos == 0x1060);

	return 0;
}

// based on FMT
int FILE_WriteSavegameFile(char* fileName)
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
    if (!stream)
        return -1;

    ASSERT(sizeof(S_55a8) == 0x20);

    WRITE_16(D_55a6);
    fwrite(D_55a8_party, 0x20, 0x10, stream);
    WRITE_16(D_57a8);             // 3dfb4
    WRITE_16(D_57aa);             // 3dfb6
    WRITE_8(D_57ac);              // 3dfb8
    WRITE_8(D_57ad);              // 3dfb9_gem_count
    WRITE_8(D_57ae);              // 3dfba
    WRITE_8(D_57af);              // 3dfbb
    WRITE_8(D_57b0);              // 3dfbc
    WRITE_8(D_57b1);              // 3dfbd
    WRITE_8(D_57b2);              // 3dfbe
    WRITE_8(D_57b3);              // 3dfbf
    WRITE_8(D_57b4);              // 3dfc0
    WRITE_8(D_57b5);              // 3dfc1
    fwrite(D_57b6, 4, 1, stream); // 3dfc4
    WRITE_8(D_57ba);              // 3dfc8
    WRITE_8(D_57bb);              // 3dfc9
    WRITE_8(D_57bc);              // 3dfca
    WRITE_8(D_57bd);              // 3dfcb
    WRITE_8(D_57be);              // 3dfcc
    WRITE_8(D_57bf);              // 3dfcd
    // FMT pad 2bytes
    fwrite(D_57c0, 0x30, 1, stream);  // 3dfd0
    fwrite(D_57f0, 0x30, 1, stream);  // 3e000
    fwrite(D_5820, 8, 1, stream);     // 3e030
    fwrite(D_5828, 8, 1, stream);     // 3e038
    fwrite(D_5830, 8, 1, stream);     // 3e040
    fwrite(D_5838, 8, 1, stream);     // 3e048
    fwrite(D_5840, 8, 1, stream);     // 3e050
    fwrite(D_5848, 8, 1, stream);     // 3e058
    fwrite(D_5850, 8, 1, stream);     // 3e060
    fwrite(D_5858, 3, 1, stream);     // 3e068
    WRITE_8(D_585b);                  // 3e06b
    fwrite(D_585c, 0x18, 1, stream);  // 3e06c
    WRITE_16(D_5874);                 // 3e084
    WRITE_16(D_5876);                 // 3e086
    WRITE_16(D_5878);                 // 3e088
    WRITE_8(D_587a);                  // 3e08a
    WRITE_8(D_587b);                  // 3e08b
    WRITE_8(D_587c);                  // 3e08c
    WRITE_8(D_587d);                  // 3e08d
    WRITE_8(D_587e);                  // 3e08e
    WRITE_8(D_587f);                  // 3e08f
    WRITE_8(D_5880);                  // 3e090
    WRITE_8(D_5881);                  // 3e091
    WRITE_8(D_5882);                  // 3e092
    WRITE_8(D_5883);                  // 3e093
    WRITE_8(D_5884);                  // 3e094
    WRITE_8(D_5885);                  // 3e095
    WRITE_8(D_5886);                  // 3e096
    WRITE_8(D_5887);                  // 3e097
    WRITE_8(D_5888);                  // 3e098
    WRITE_8(D_5889);                  // 3e099
    WRITE_8(D_588a);                  // 3e09a
    WRITE_8(D_588b);                  // 3e09b
    WRITE_8(D_588c);                  // 3e09c
    WRITE_8(D_588d);                  // 3e09d
    WRITE_8(D_588e);                  // 3e09e
    WRITE_8(D_588f);                  // 3e09f
    WRITE_8(D_5890);                  // 3e0a0
    WRITE_8(D_5891);                  // 3e0a1
    WRITE_8(D_5892_wind_dir);         // 0003e0a2
    WRITE_8(D_5893_map_id);           // 3e0a3_5893_map_id
    WRITE_8(D_5894);                  // 3e0a4
    WRITE_8(D_5895_map_level);        // 3e0a5_5895_map_level
    WRITE_8(D_5896_map_x);            // 3e0a6_5896_map_x
    WRITE_8(D_5897_map_y);            // 3e0a7_5897_map_y
    WRITE_8(D_5898);                  // 3e0a8
    WRITE_8(D_5899);                  // 3e0a9
    WRITE_8(D_589a);                  // 3e0aa
    WRITE_8(D_589b);                  // 3e0ab
    WRITE_8(D_589c);                  // 3e0ac
    WRITE_8(D_589d);                  // 3e0ad
    WRITE_8(D_589e);                  // 3e0ae
    WRITE_8(D_589f);                  // 3e0af
    WRITE_8(D_58a0);                  // 3e0b0
    WRITE_8(D_58a1);                  // 3e0b1
    WRITE_8(D_58a2);                  // 3e0b2
    WRITE_8(D_58a3);                  // 3e0b3_58a3_battle_finish_flg
    WRITE_8(D_58a4);                  // 3e0b4
    WRITE_8(D_58a5);                  // 3e0b5
    WRITE_8(D_58a6);                  // 3e0b6
    WRITE_8(D_58a7);                  // 3e0b7
    fwrite(&D_58a8, 0x20, 1, stream); // 3e0b8
    fwrite(&D_58c8, 3, 1, stream);    // 3e0d8
    WRITE_8(D_58cb);                  // 3e0db
    WRITE_16(D_58cc);                 // 3e0dc
    WRITE_16(D_58ce);                 // 3e0de
    fwrite(D_58d0, 8, 1, stream);    // 3e0e0
    fwrite(D_58d8, 8, 1, stream);    // 3e0e8
    fwrite(D_58e0, 0xe, 1, stream);  // 3e0f0
    // FMT pad 1byte
    fwrite(D_58ee, 0x20, 1, stream); // 3e100
    fwrite(D_590e, 0x20, 1, stream); // 3e120
    fwrite(D_592e, 0x20, 1, stream); // 3e140
    WRITE_8(D_594e);                  // 3e160
    WRITE_8(D_594f);                  // 3e161
    WRITE_8(D_5950);                  // 3e162
    WRITE_8(D_5951);                  // 3e163
    WRITE_8(D_5952);                  // 3e164
    WRITE_8(D_5953);                  // 3e165
    WRITE_8(D_5954);                  // 3e166
    WRITE_8(D_5955);                  // 3e167
    WRITE_8(D_5956);                  // 3e168
    WRITE_8(D_5957);                  // 3e169
    WRITE_8(D_5958);                  // 3e16a
    WRITE_8(D_5959);                  // 3e16b
    fwrite(D_595a, 0x200, 1, stream); // 3e16c; map data
    fwrite(D_5b5a, 0x80, 1, stream);  // 3e36c
    fwrite(D_5bda, 0x80, 1, stream);  // 3e3ec
    fwrite(D_5c5a, 0x100, 1, stream); // 3e46c
    WRITE_16(D_5d5a);                 // 3e56c
    WRITE_16(D_5d5c);                 // 3e56e
    fwrite(D_5d5e, 0x200, 1, stream); // 3e570
    fwrite(D_5f5e, 0x200, 1, stream); // 3e770
    fwrite(D_615e, 0x400, 1, stream); // 3e970
    fwrite(D_655e, 0x40, 1, stream);  // 3ed70
    fwrite(D_659e, 0x20, 1, stream);  // 3edb0
    // fwrite(D_659e, 0x20, 1, stream); // 3edb0 ; FMT sic
    WRITE_8(D_65be);                 // 3edd0
    WRITE_8(D_65bf);                 // 3edd1
    WRITE_16(D_65c0);                // 3edd2
    fwrite(D_65c2, 0x40, 1, stream); // 3edd4
    WRITE_8(D_6602);                 // 3ee14
    WRITE_8(D_6603);                 // 3ee15
    WRITE_8(D_6604);                 // 3ee16
    WRITE_8(D_6605);                 // 3ee17
    // WRITE_16(D_6606);// 3ee18

    int pos = (int)ftell(stream);
    printf("pos: %d\n", pos);

    fclose(stream);

    ASSERT(pos == 0x1060);

    return 0;
}

#endif
