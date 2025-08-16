#include "COMMON.H"

#define STUB
#include "VARS.H"

char* D_1916[8] =
{
	"*VL",
	"*RH",
	"*IS",
	"*IA",
	"*IQW",
	"*KXC",
	"*IMC",
	"*AT"
};

char* D_1A44[10] =
{
	"Avatar",
	"Mage",
	"Bard",
	"Fighter",
	"Druid",
	"Tinker",
	"Paladin",
	"Ranger",
	"Shepherd",
	"Adept of Woznir"
};

char* D_1A6A[5] = {	"Good Health","Poisoned","Dead","Asleep","Charmed" };

// 4C 40 44 48 4C 4C 4C 4C 4C 00?
// "L@DHLLLLL"?
char D_1ADE[9] = { 0x4c, 0x40, 0x44, 0x48, 0x4c, 0x4c, 0x4c, 0x4c, 0x4c };

u8 D_24e6 = 1;

// 
char* D_25ea[30] =
{
	"PROPORT.PCS",
	"BRITISH.BIT",
	"TITLE.BIT",
	"TILES.16",
	"ITEMS.16",
	"DNG1.16",
	"DNG2.16",
	"DNG3.16",
	"MON0.16",
	"MON1.16",
	"MON2.16",
	"MON3.16",
	"MON4.16",
	"MON5.16",
	"MON6.16",
	"MON7.16",
	"CREATE.16",
	"TEXT.16",
	"STORY1.16",
	"STORY2.16",
	"STORY3.16",
	"STORY4.16",
	"STORY5.16",
	"STORY6.16",
	"END1.16",
	"END2.16",
	"ULTIMA.16",
	"STARTSC.16",
	"ENDSC.16",
	""
};

char* D_2652[4] = { "TOWNE.DAT", "DWELLING.DAT", "CASTLE.DAT", "KEEP.DAT" };

u8 D_2742[4] = { 0x03, 0x04, 0x02, 0x01 };

int D_5304 = -1;

u16 D_5358 = 0xffff;
u16 D_538e = 1;
u16 D_5390 = 5;
u16 D_5392 = 4;
u16 D_5394 = 0x1232;

u8 D_540e[8] = { 0x4B, 0x4D, 0x48, 0x50, 0x47, 0x4F, 0x49, 0x51 };
u8 D_5416[8] = { 0x01, 0x02, 0x03, 0x04, 0xD3, 0xD4, 0xD5, 0xD6 };

// FIXME: verification
TextWindow* D_539a_textWinForCurrCharset = &D_535e_textWindows[0];

u8* D_b31e = &D_b21e[0x100];

s16 D_5402[5] = {1, 10, 100, 1000, 10000};
