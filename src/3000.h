#ifndef _ULTIMA_3000_H
#define _ULTIMA_3000_H

extern void ULTIMA_3072(void);

// Game

extern int ULTIMA_3178_ProcessCommand(int param_1);
extern void ULTIMA_3522(int x, int y);
extern void ULTIMA_3564(int a);
extern int ULTIMA_35ec_SelectDirection(void);
extern int ULTIMA_368e_FindNpcTileAtPos(int x, int y, int z);
extern int ULTIMA_3702(int param_1, int param_2, int param_3);
extern int ULTIMA_38e4(void);
extern void ULTIMA_39cc_SetTile(byte new_tile_id, byte x, byte y);
extern int ULTIMA_39fc_GetFirstActivePartyMember(void);
extern void ULTIMA_3a74(byte a, byte b, byte c, byte d, byte e, byte f, int g);
extern int ULTIMA_3aae(int a);
extern int ULTIMA_3abe(void);
extern void ULTIMA_3ae6(int a);
extern void ULTIMA_3b1c_GetString(char* param_1, int param_2);
extern int ULTIMA_3b9e(int param_1);

extern void ULTIMA_3ef0(byte* param_1, int param_2, int param_3);
extern void ULTIMA_3f14(s16* a, int b, int c);
extern void ULTIMA_3f36(byte* param_1, int param_2);
extern void ULTIMA_3f54(s16* a, int b);
extern bool ULTIMA_3f6e(int param_1, int param_2);
extern void ULTIMA_3fb4(int param_1, int param_2);

#endif
