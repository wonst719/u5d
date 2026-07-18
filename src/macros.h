#ifndef _MACROS_H
#define _MACROS_H

#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 3
#define DIR_DOWN 4

// Control chars
#define CTRL_CHAR_CLEAR_WINDOW 0xff
#define CTRL_CHAR_TOGGLE_UNDERLINE 0xfe
#define CTRL_CHAR_TOGGLE_INVERSION 0xfd
#define CTRL_CHAR_CENTER_TEXT 0xfc
#define CTRL_CHAR_UNCENTER_TEXT 0xfb

// Keyboard

#define U5_KEY_LEFT 1
#define U5_KEY_RIGHT 2
#define U5_KEY_UP 3
#define U5_KEY_DOWN 4

#define U5_KEY_CTRL_B 0xfc
#define U5_KEY_CTRL_E 5
#define U5_KEY_CTRL_K 0xb
#define U5_KEY_CTRL_M 0xd
#define U5_KEY_CTRL_S 0x13
#define U5_KEY_CTRL_V 0x16

#define U5_KEY_BACKSPACE 8
#define U5_KEY_ENTER 0xd
#define U5_KEY_ESC 0x1b
#define U5_KEY_SPACE 0x20

#define U5_KEY_HOME 0xd3
#define U5_KEY_END 0xd4
#define U5_KEY_PGUP 0xd5
#define U5_KEY_PGDN 0xd6

#define U5_KEY_PLUS 0x2b
#define U5_KEY_MINUS 0x2d
#define U5_KEY_PERIOD 0x2e

// Class
#define CLASS_LIST "AMBFDTPRS"

#define CLASS_AVATAR 'A'
#define CLASS_MAGE 'M'
#define CLASS_BARD 'B'
#define CLASS_FIGHTER 'F'
#define CLASS_DRUID 'D'
#define CLASS_TINKER 'T'
#define CLASS_PALADIN 'P'
#define CLASS_RANGER 'R'
#define CLASS_SHEPHERD 'S'

// Status
#define STATUS_GOOD 'G'
#define STATUS_POISONED 'P'
#define STATUS_DEAD 'D'
#define STATUS_SLEEP 'S'
#define STATUS_CHARMED 'C'

#define STATUS_LIST "GPDSC"

// Enemy flags
// 0x8000: magic user
// 0x4000: (unused?)
// 0x2000: can teleport
// 0x1000: vanishes at death
// 0x800: can become invisible
// 0x400: can summon a daemon
// 0x200: can poison? (0x204?)
// 0x100: (unused?)
// 0x80: query str instead of dex
// 0x40: can possess/charm?
// 0x20: is undead? (half damage when D_5890 == 0)
// 0x10: can divide?
// 0x8: never takes damage
// 0x4: can poison? (from distance?)
// 0x2: can steal
// 0x1: leaves no corpse
#define ENEMY_FLAG_MAGIC 0x8000
#define ENEMY_FLAG_4000 0x4000
#define ENEMY_FLAG_TELEPORT 0x2000
#define ENEMY_FLAG_VANISH 0x1000
#define ENEMY_FLAG_DISAPPEAR 0x800
#define ENEMY_FLAG_SUMMON 0x400
#define ENEMY_FLAG_POISON_200 0x200
#define ENEMY_FLAG_100 0x100
#define ENEMY_FLAG_80 0x80
#define ENEMY_FLAG_CHARM 0x40
#define ENEMY_FLAG_UNDEAD 0x20
#define ENEMY_FLAG_DIVIDE 0x10
#define ENEMY_FLAG_NO_DAMAGE 0x8
#define ENEMY_FLAG_POISON_4 0x4
#define ENEMY_FLAG_STEAL 0x2
#define ENEMY_FLAG_NO_CORPSE 0x1

// Combat entity flags
#define COMBAT_FLAGS_PLAYER 0x80
#define COMBAT_FLAGS_MONSTER 0x40
#define COMBAT_FLAGS_DEAD 0x20
#define COMBAT_FLAGS_INVISIBLE 0x10
#define COMBAT_FLAGS_ASLEEP 0x8
#define COMBAT_FLAGS_4 0x4
#define COMBAT_FLAGS_2 0x2
#define COMBAT_FLAGS_CHARMED 0x1

#define QUERY_STAT_INTEL -1
#define QUERY_STAT_DEX -2
#define QUERY_STAT_STR -3
#define QUERY_STAT_DEF -4

// "Settlements"
//#define MAP_ID
//#define MAP_TOWN_END 0x20
//#define MAP_DUNGEON_START 0x20

// tile
//#define GetTileIs

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
