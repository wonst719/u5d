#ifndef _MACROS_H
#define _MACROS_H

// map
#define GetMapOverworld(x, y, z) (D_6608_map.overworld[z][y][x])
#define GetMap(x, y) (D_6608_map.town[y][x])

// combat map
#define GetCombatMap(x, y) (D_ad14[(y) * 0x20 + (x)])

#endif
