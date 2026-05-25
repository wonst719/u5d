#ifndef _MACROS_H
#define _MACROS_H

// map
#define GetMapOverworld(x, y, z) (D_6608_map.overworld[z][y][x])
#define GetMap(x, y) (D_6608_map.town[y][x])
#define GetCopiedMap(x, y) (D_6708_map.town[y][x])

// current map viewport (for rendering)
#define GetMapViewport(x, y) (D_ab02[(y) * 0x20 + (x)])

// actor map
#define GetActorMap(x, y) (D_ac64[(y) * 0x10 + (x)])

// dungeon map
#define GetDungeonMap(x, y, level) (D_595a[(level) * 0x40 + (y) * 8 + (x)])
#define GetDungeonMap2(x, y, level) (D_595a[((y) & 7) * 8 + ((x) & 7) + (level) * 0x40])

// combat map
// ref: https://wiki.ultimacodex.com/wiki/Ultima_V_internal_formats#*.CBT
// TODO: define struct?
#define COMBAT_MAP_STRIDE 0x20
#define COMBAT_MAP_TILE_WIDTH 0xb
#define COMBAT_MAP_SPECIAL_BASE COMBAT_MAP_TILE_WIDTH
#define COMBAT_MAP_PARTY_X_INDEX COMBAT_MAP_SPECIAL_BASE
#define COMBAT_MAP_PARTY_Y_INDEX (COMBAT_MAP_PARTY_X_INDEX + 6)
#define COMBAT_MAP_TRIGGER_X_INDEX COMBAT_MAP_SPECIAL_BASE
#define COMBAT_MAP_TRIGGER_Y_INDEX (COMBAT_MAP_TRIGGER_X_INDEX + 8)
#define COMBAT_MAP_NEW_TILE_X_INDEX COMBAT_MAP_SPECIAL_BASE
#define COMBAT_MAP_NEW_TILE_Y_INDEX (COMBAT_MAP_NEW_TILE_X_INDEX + 8)

#define COMBAT_MAP_SPECIAL_NEW_TILES 0
#define COMBAT_MAP_SPECIAL_PARTY_EAST 1
#define COMBAT_MAP_SPECIAL_PARTY_WEST 2
#define COMBAT_MAP_SPECIAL_PARTY_SOUTH 3
#define COMBAT_MAP_SPECIAL_PARTY_NORTH 4
#define COMBAT_MAP_SPECIAL_MONSTER_TILES 5
#define COMBAT_MAP_SPECIAL_MONSTER_X 6
#define COMBAT_MAP_SPECIAL_MONSTER_Y 7
#define COMBAT_MAP_SPECIAL_TRIGGERS 8
#define COMBAT_MAP_SPECIAL_NEW_TILE_1 9
#define COMBAT_MAP_SPECIAL_NEW_TILE_2 10

#define GetCombatMap(x, y) (D_ad14[(y) * COMBAT_MAP_STRIDE + (x)])
#define GetCombatMapSpecial(type, idx) GetCombatMap((idx), (type))

#define GetCombatMapNewTileId(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_NEW_TILES, COMBAT_MAP_SPECIAL_BASE + (idx))
#define GetCombatMapPartyX(type, idx) GetCombatMapSpecial((type), COMBAT_MAP_PARTY_X_INDEX + (idx))
#define GetCombatMapPartyY(type, idx) GetCombatMapSpecial((type), COMBAT_MAP_PARTY_Y_INDEX + (idx))
#define GetCombatMapMonsterTile(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_MONSTER_TILES, COMBAT_MAP_SPECIAL_BASE + (idx))
#define GetCombatMapMonsterX(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_MONSTER_X, COMBAT_MAP_SPECIAL_BASE + (idx))
#define GetCombatMapMonsterY(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_MONSTER_Y, COMBAT_MAP_SPECIAL_BASE + (idx))
#define GetCombatMapTriggerX(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_TRIGGERS, COMBAT_MAP_TRIGGER_X_INDEX + (idx))
#define GetCombatMapTriggerY(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_TRIGGERS, COMBAT_MAP_TRIGGER_Y_INDEX + (idx))
#define GetCombatMapNewTile1X(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_NEW_TILE_1, COMBAT_MAP_NEW_TILE_X_INDEX + (idx))
#define GetCombatMapNewTile1Y(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_NEW_TILE_1, COMBAT_MAP_NEW_TILE_Y_INDEX + (idx))
#define GetCombatMapNewTile2X(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_NEW_TILE_2, COMBAT_MAP_NEW_TILE_X_INDEX + (idx))
#define GetCombatMapNewTile2Y(idx) GetCombatMapSpecial(COMBAT_MAP_SPECIAL_NEW_TILE_2, COMBAT_MAP_NEW_TILE_Y_INDEX + (idx))

#endif
