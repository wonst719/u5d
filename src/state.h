#pragma once

#include "common/common.h"

#ifndef STUB
#define STUB extern
#endif

//
// Savegame / User state
// 

// TODO: convert to a big struct?

// [55a6..6606): savegame (0x1060)
STUB u16 D_55a6;    // +0x0

STUB S_55a8 D_55a8_party[0x10]; // ~57a8)

// 5700
STUB s16 D_57a8;        // +0x0202 Food // int (TALK_0682, MOVSX)
STUB s16 D_57aa;        // +0x0204 Gold // int (MAINOUT_1b3e, MOVSX)
STUB u8  D_57ac;        // +0x0206 #Keys
STUB u8  D_57ad;        // +0x0207 #Gems
STUB u8  D_57ae;        // +0x0208 #Torches
STUB u8  D_57af;        // +0x0209 Grapple
STUB u8  D_57b0;        // +0x020A #Magic Carpets
STUB u8  D_57b1;        // +0x020B #Skull Keys
STUB u8  D_57b2;        // +0x020C Last day Minoc skull keys were taken
STUB u8  D_57b3;        // +0x020D Amulet of Lord British
STUB u8  D_57b4;        // +0x020E Crown of Lord British
STUB u8  D_57b5;        // +0x020F Sceptre of Lord British
STUB u8  D_57b6[4];     // +0x0210 Shards   // [57b6..57ba)
STUB u8  D_57ba;        // +0x0214 #Spy Glass
STUB u8  D_57bb;        // +0x0215 HMS Cape Plans
STUB u8  D_57bc;        // +0x0216 #Sextant
STUB u8  D_57bd;        // +0x0217 Pocket Watch
STUB u8  D_57be;        // +0x0218 Black Badge
STUB u8  D_57bf;        // +0x0219 Sandalwood Box
// FMT pad 2byte (?)
STUB u8  D_57c0[0x30];  // +0x021A Equipment(Quantity owned by the party) [57c0..57f0)
#define D_57db D_57c0[0x1b] /* +0x0235 Arrows */
#define D_57dd D_57c0[0x1d] /* +0x0237 Quarrels */
STUB u8  D_57f0[0x30];  // +0x024A Spell Mixtures [57f0..5820)

// 5800
STUB u8  D_5820[8];     // +0x027A Scrolls
STUB u8  D_5828[8];     // +0x0282 Potions (Blue, Yellow, Red, Green, Orange, Purple, Black, White)
STUB u8  D_5830[8];     // +0x028A 0-0xFF Moonstone X-coordinates (valid only if buried)
STUB u8  D_5838[8];     // +0x0292 0-0xFF Moonstone Y-coordinates (valid only if buried)
STUB u8  D_5840[8];     // +0x029A 0=buried,0xFF=Inventory moonstone flags
STUB u8  D_5848[8];     // +0x02A2 0=Britannia,0xFF=Underworld moonstone Z-coordinates (valid only if buried)
STUB u8  D_5850[8];     // +0x02AA Reagents (A..H)
STUB u8  D_5858[3];     // +0x02B2 Day each of the three nightshade/mandrake spots was last harvested [5858..585b)
STUB u8  D_585b;        // +0x02B5 party member count
STUB u8  D_585c[0x18];  // [585c..5874)
STUB u16 D_5874;        // +0x02CE Current year (TODO: int?)
STUB s16 D_5876;        // selected x direction? // +0x02D0 first party member that is not dead or sleeping? # of active monsters & charmed PCs[2]?
STUB s16 D_5878;        // selected y direction? // +0x02D2 # of active PCs and charmed monsters[2]?
STUB u8  D_587a;        // +0x02D4 Icon
STUB u8  D_587b;        // +0x02D5 Active character
STUB u8  D_587c_partyTile; // +0x02D6 party tile
STUB u8  D_587d;        // +0x02D7 Current month
STUB u8  D_587e;        // +0x02D8 Current day
STUB u8  D_587f;        // +0x02D9 Current hour
STUB u8  D_5880;        // +0x02DA copy of 0x2D9
STUB u8  D_5881;        // +0x02DB Current minute
STUB u8  D_5882;
STUB u8  D_5883;        // ?
STUB u8  D_5884;
STUB u8  D_5885;        // +0x02DF Phase of Trammel
STUB u8  D_5886;        // +0x02E0 Phase of Felucca
STUB u8  D_5887;        // +0x02E1 Current moongate height (in pixels)
STUB u8  D_5888;        // +0x02E2 Karma
STUB u8  D_5889;
STUB u8  D_588a;
STUB u8  D_588b;        // +0x02E5 Current turn count
STUB u8  D_588c;
STUB u8  D_588d;
STUB u8  D_588e;        // +0x02E8 Protective spell duration
STUB u8  D_588f;
STUB u8  D_5890;
STUB u8  D_5891;            // +0x02EB animate flag
STUB u8  D_5892_wind_dir;   // +0x02EC wind direction
STUB u8  D_5893_map_id;     // +0x02ED map_id (21h~: dungeon, 40: unloaded)
STUB u8  D_5894;            // +0x02EE Combat backup of 0x2ED
STUB u8  D_5895_map_level;  // +0x02EF level (depth)
STUB u8  D_5896_map_x;      // +0x02F0 map_x
STUB u8  D_5897_map_y;      // +0x02F1 map_y
STUB u8  D_5898;            // crosshair visible
STUB u8  D_5899;            // crosshair x
STUB u8  D_589a;            // crosshair y
STUB u8  D_589b;            // x upper left chunk
STUB u8  D_589c;            // y upper left chunk
STUB u8  D_589d;            // +0x02F7 Attacker's weapon
STUB u8  D_589e;            // +0x02F8 ?
STUB u8  D_589f;            // +0x02F9 show focus rectangle & crosshair?
STUB u8  D_58a0;            // +0x02FA exit direction from combat map
STUB u8  D_58a1;            // +0x02FB combat type flags
STUB u8  D_58a2;
STUB u8  D_58a3;            // +0x02FD battle successful flag (win?)
STUB u8  D_58a4;            // +0x02FE Update/animate 2D map?
STUB u8  D_58a5;            // +0x02FF Current light intensity
STUB u8  D_58a6;
STUB u8  D_58a7;
STUB u8  D_58a8[0x20];  // [58a8..58c8)
STUB u8  D_58c8[3];     // 58cb)
STUB u8  D_58cb;
STUB u16 D_58cc;        // shrine quest active flags TODO: u8?
STUB u16 D_58ce;        // shrine quest completed flags TODO: u8?
STUB u8  D_58d0[8];
STUB u8  D_58d8[8];
STUB u8  D_58e0[0xe];   // ..58ee)
STUB u8  D_58ee[0x20];  // ..590e) spell counts
// 5900
STUB u8  D_590e[0x20];  // ..592e)
STUB u8  D_592e[0x20];  // .594e)
STUB u8  D_594e;
STUB u8  D_594f;        // +0x03A9 opened door
STUB u8  D_5950;        // +0x03AA open_door_x
STUB u8  D_5951;        // +0x03AB open_door_y
STUB u8  D_5952;        // +0x03AC # of turns the door stays open
STUB u8  D_5953;        // +0x03AD ship_x
STUB u8  D_5954;        // +0x03AE ship_y
STUB u8  D_5955;
STUB u8  D_5956;
STUB u8  D_5957;        // +0x03B1 remaining drunk turn count (TOWN_0dc4)
STUB u8  D_5958;
STUB u8  D_5959;
STUB u8 D_595a[0x200];  // +0x03B4 dungeon map data ..5b5a)
// 5b00
STUB u8 D_5b5a[0x80];   // +0x05B4 NPC killed flags (4 bytes / 32 bits per settlement) [..5bda) // TODO: u32
STUB u8 D_5bda[0x80];   // +0x0634 NPC met flags (4 bytes / 32 bits per settlement) [..5c5a)

STUB ActorFmt D_5c5a[32]; // ~5d5a) "Object" struct

// 5d00
STUB u16 D_5d5a; // unused?
STUB u16 D_5d5c; // unused?

STUB NpcScheduleFmt D_5d5e[32];  // +0x07B8 NPC Schedules [..5f5e) 0x200

// 5f00
STUB NpcFmt D_5f5e[32];  // +0x09B8 Character/monster states (16bytes * 32) [..615e) 0x200

// 6100
STUB MovementFmt D_615e[0x20];  // +0x0BB8 Movement list table [..655e)

STUB s16 D_655e[0x20];   // +0x0FB8 Movement list pointers [..659e)
STUB u8 D_659e[0x20];   // +0x0FF8 NPC types [..65be)
STUB u8 D_65be;
STUB u8 D_65bf;
STUB u16 D_65c0; // unused?
STUB s16 D_65c2[0x20];

// 6600
STUB u8 D_6602;
STUB u8 D_6603;         // +0x105D orientation in a dungeon
STUB u8 D_6604;         // +0x105E graphics for the current dungeon
STUB u8 D_6605;         // +0x105F purchased ship/skiff
STUB u16 D_6606; // end
