#include "mod/actors.h"
#include "common/common.h"
#include "mod/contents_game.h"
#include "mod/types_game.h"
#if defined(TARGET_SDL)
#include "graphics/grap_sdl.h"
#include "graphics/sprite_order.h"
#include "graphics/grap_buf.h"
#include "graphics/widescreen.h"
#endif
#include "vars.h"
#include "funcs.h"
#include "macros.h"
#include "tiles.h"

#include <string.h>
#include <stdlib.h>

#include "audio/aud_mus.h"

#include "cmds.h"
#include "combat.h"
#include "dnglook.h"

static int ULTIMA_51a0(void)
{
    if (D_587a == 'T')
    {
        return 0;
    }
    else
    {
        return ULTIMA_2092_RandomRange(0, 3);
    }
}

/* Shared by the original viewport and the fullscreen extension. Negative
 * results preserve terrain (-1), or substitute the special water tile (-2). */
int ULTIMA_ResolveActorTile(int param_5, int terrain, int above, int below, bool* reflection)
{
    int local_4;
    *reflection = false;
    if (param_5 == 0x1c || param_5 >= 0x12 && param_5 < 0x16 || param_5 >= 0x40 || param_5 >= 0x28 && param_5 < 0x2c)
    {
        // 51e9
        local_4 = terrain;
        if (local_4 == TILE_MAP_EC || local_4 == TILE_MAP_A)
            return -1;

        // 520b?
        if (local_4 == TILE_MAP_57) // 87
        {
            // 520b
            return -2;
        }

        if (local_4 == TILE_MAP_6A || local_4 == TILE_MAP_6B) // 106, 107
        {
            // 522e
            if ((param_5 & 0xf0) == 0x80)
            {
                return -1;
            }
            if ((param_5 & 0xfc) == 0x28)
            {
                return -1;
            }
        }
        else
        {
            // 524a
            if (param_5 < 0x80)
            {
                // 5254
                switch (local_4)
                {
                case TILE_MAP_84: // 132
                    // 5276
                    param_5 = ULTIMA_51a0() + 0x60; // -> 5300
                    break;

                case TILE_MAP_85: // 133
                    // 5280
                    param_5 = ULTIMA_51a0() + 0x64; // -> 5300
                    break;

                case TILE_MAP_LADDER_UP: // 200
                    // 528a
                    param_5 = 0x17;
                    break;

                case TILE_MAP_LADDER_DOWN: // 201
                    // 5292
                    param_5 = 0x18;
                    break;

                case TILE_MAP_BED: // 171
                    // 529a
                    param_5 = TILE_ACTOR_SLEEPING_IN_BED;
                    break;

                // 93..9e
                case TILE_MAP_MIRROR: // 157
                case TILE_MAP_MIRROR_9E: // 158 (531a)
                    // 52a2
                    param_5 = ULTIMA_51a0() + 0x3c;
                    break;

                case TILE_MAP_CHAIR_92: // 146
                    // 52aa
                    if ((below == TILE_MAP_TABLE_9A) ||
                        (below == TILE_MAP_TABLE_9C))
                    {
                        param_5 = ULTIMA_51a0() + 0x34;
                    }
                    else
                    {
                        param_5 = 0x32;
                    }
                    break;

                case TILE_MAP_CHAIR_90: // 144
                    // 52da
                    if ((above == TILE_MAP_TABLE_9B) ||
                        (above == TILE_MAP_TABLE_9C))
                    {
                        param_5 = ULTIMA_51a0() + 0x38;
                    }
                    else
                    {
                        param_5 = 0x30;
                    }
                    break;

                case TILE_MAP_CHAIR_91: // 145, 532a
                case TILE_MAP_CHAIR_93: // 147
                    // -> 530e -> 5300
                    param_5 = (local_4 & 3) + 0x30;
                    break;

                default:
                    // 532c
                    if ((above == TILE_MAP_MIRROR))
                    {
                        *reflection = true;
                    }
                    break;
                }
            }
        }
    }

    return param_5;
}

static void ULTIMA_51b8(int x, int y, int worldX, int worldY, int actor)
{
    bool reflection;
    int tile = ULTIMA_ResolveActorTile(
        actor, *ULTIMA_4402_GetTileAddr(worldX, worldY),
        D_5893_map_id >= 128 && worldY == 0 ? 0 : *ULTIMA_4402_GetTileAddr(worldX, worldY - 1),
        D_5893_map_id >= 128 && worldY == MAP_HEIGHT - 1
            ? 0
            : *ULTIMA_4402_GetTileAddr(worldX, worldY + 1),
        &reflection);
    if (tile == -1) return;
    if (tile == -2) { GetMapViewport(x, y) = TILE_MAP_38; return; }
    if (reflection && y != 0) GetMapViewport(x, y - 1) = TILE_MAP_MIRROR_9E;
    GetActorMap(x, y) = (byte)tile;
    GetMapViewport(x, y) = 0;
}

// CHECKED
void ULTIMA_5394(void)
{
    int local_c;
    int local_e;
    int local_a;
    int local_8;

    byte local_6;
    byte local_4;

    if (D_5893_map_id < 0x80)
    {
        D_5c5a[0]._2_x = D_5896_map_x;
        D_5c5a[0]._3_y = D_5897_map_y;
        D_5c5a[0]._4_z = D_5895_map_level;
        D_5c5a[0]._1_animTile = D_5c5a[0]._0_tile = D_587c_partyTile;
        
        for (local_e = 0; local_e < 0xb; local_e++)
        {
            for (local_c = 0; local_c < 0xb; local_c++)
            {
                if (GetMapViewport(local_c, local_e) == TILE_MAP_DD &&
                    ULTIMA_6ff0(local_c, local_e) > 5)
                {
                    GetMapViewport(local_c, local_e) = TILE_MAP_1C;
                }
                else if (GetMapViewport(local_c, local_e) == TILE_MAP_1C &&
                    ULTIMA_6ff0(local_c, local_e) <= 5)
                {
                    GetMapViewport(local_c, local_e) = TILE_MAP_DD;
                }
            }
        }
    }

    // 542a
    local_c = MAP_ACTOR_COUNT - 1;
    do
    {
        if (D_5c5a[local_c]._0_tile != 0)
        {
            local_8 = local_4 = D_5c5a[local_c]._2_x;
            local_a = local_6 = D_5c5a[local_c]._3_y;

            if (D_5893_map_id >= 128) {
                local_8 -= MAP_VIEW_X;
                local_a -= MAP_VIEW_Y;
                if (local_8 < 0 || local_a < 0 || local_8 > 10 || local_a > 10)
                    continue;
            }
            if (D_5893_map_id < 0x80)
            {
                local_8 -= D_5896_map_x - 5;
                local_a -= D_5897_map_y - 5;
                if (!D_5893_map_id) {
                    local_8 = MAPS_Wrap((int)D_5c5a[local_c]._2_x - D_5896_map_x + MAP_WIDTH / 2,
                                        MAP_WIDTH) -
                              MAP_WIDTH / 2 + 5;
                    local_a = MAPS_Wrap((int)D_5c5a[local_c]._3_y - D_5897_map_y + MAP_HEIGHT / 2,
                                        MAP_HEIGHT) -
                              MAP_HEIGHT / 2 + 5;
                }
                if (D_5c5a[local_c]._4_z != D_5895_map_level || local_8 < 0 || local_a < 0 ||
                    local_8 > 10 || local_a > 10)
                    continue;
            }

            if (D_5c5a[local_c]._1_animTile != 0 &&
                GetMapViewport(local_8, local_a) != 0xff &&
                GetMapViewport(local_8, local_a) != TILE_MAP_87)
            {
                if ((D_5c5a[local_c]._0_tile & 0xfc) == TILE_ACTOR_E8 || D_5c5a[local_c]._0_tile == TILE_ACTOR_SLEEP || D_5c5a[local_c]._0_tile == TILE_ACTOR_DEAD)
                {
                    // 5503
                    if (GetMapViewport(local_8, local_a) != 0)
                    {
                        GetActorMap(local_8, local_a) = D_5c5a[local_c]._1_animTile;
                        GetMapViewport(local_8, local_a) = 0;
                    }
                }
                else if (D_5c5a[local_c]._1_animTile == TILE_ACTOR_1D || D_5c5a[local_c]._1_animTile == TILE_ACTOR_SLEEP)
                {
                    GetActorMap(local_8, local_a) = D_5c5a[local_c]._1_animTile;
                    GetMapViewport(local_8, local_a) = 0;
                }
                else if (D_5c5a[local_c]._0_tile == TILE_ACTOR_BARD)
                {
                    if (GetMapViewport(local_8, local_a) == TILE_MAP_CHAIR_92)
                    {
                        GetActorMap(local_8, local_a) = D_5c5a[local_c]._1_animTile;
                        GetMapViewport(local_8, local_a) = 0;
                    }
                    else
                    {
                        ULTIMA_51b8(local_8, local_a, local_4, local_6, D_5c5a[local_c]._1_animTile - 8);
                    }
                }
                else
                {
                    ULTIMA_51b8(local_8, local_a, local_4, local_6, D_5c5a[local_c]._1_animTile);
                }
            }
        }
    } while (--local_c >= 0);
    if (MAPS_Outside(D_5893_map_id) || D_5893_map_id >= 128) {
        for (int y = 0; y < 11; y++)
            for (int x = 0; x < 11; x++)
            {
                int wx = MAP_VIEW_X + x;
                int wy = MAP_VIEW_Y + y;
                if (!D_5893_map_id)
                {
                    wx = MAPS_Wrap(wx, MAP_WIDTH);
                    wy = MAPS_Wrap(wy, MAP_HEIGHT);
                }
                int shape = CONTENTS_GAME_Shape(wx, wy);
                if (shape && GetActorMap(x, y) == 0 && GetMapViewport(x, y) != 0xff &&
                    GetMapViewport(x, y) != TILE_MAP_87)
                {
                    ULTIMA_51b8(x, y, wx, wy, shape);
                }
            }
    }
}

int ULTIMA_5646(int param_1)
{
    int local1_6;
    int local2_4;

    local1_6 = D_ba14[param_1].flags;
    local2_4 = D_ba14[param_1].entityIdx;

    if ((local1_6 & COMBAT_FLAGS_DEAD) != 0)
    {
        return 0;
    }

    // 566e
    if ((local1_6 & COMBAT_FLAGS_PLAYER) != 0)
    {
        if (local2_4 != 0 && D_55a8_party[local2_4].name[4] == 'j')
        {
            return 1;
        }
        else
        {
            // 568e
            return (local1_6 & COMBAT_FLAGS_CHARMED);
        }
    }
    else
    {
        // 5696
        return !(local1_6 & COMBAT_FLAGS_CHARMED);
    }

    // 56a4
}

#if defined(TARGET_SDL)
typedef struct {
    SpriteOrder order;
    unsigned tile;
    int x, y;
} CombatSprite;
static void AddCombatSprite(CombatSprite *sprites, int *count, unsigned tile, int x, int y,
                            int actor) {
    for (int i = 0; i < *count; ++i)
        if (sprites[i].x == x && sprites[i].y == y && sprites[i].tile == tile)
            return;
    unsigned w = 1, h = 1;
    if (TYPES_ArtSlot(tile))
        TYPES_ArtSize(tile, 0, &w, &h);
    sprites[(*count)++] =
        (CombatSprite){{SPRITES_Layer(tile), y + (int)h - 1, x, -actor}, tile, x, y};
}
static void DrawCombatSprites(void) {
    CombatSprite sprites[121 + 32 + 121];
    int count = 0;
    for (int i = 0; i < 32; i++) {
        ActorFmt *a = &D_5c5a[i];
        int x = (int)a->_2_x - MAP_VIEW_X, y = (int)a->_3_y - MAP_VIEW_Y;
        if (!a->_0_tile || !a->_1_animTile || x < -1 || y < -1 || x >= 11 || y >= 11 ||
            a->_1_animTile == 0x16)
            continue;
        if (x >= 0 && y >= 0 &&
            (GetMapViewport(x, y) == 255 || GetMapViewport(x, y) == TILE_MAP_87))
            continue;
        int native = SPRITES_NativeActorTile(a, *ULTIMA_4402_GetTileAddr(a->_2_x, a->_3_y),
                                             a->_3_y ? *ULTIMA_4402_GetTileAddr(a->_2_x, a->_3_y - 1) : 0,
                                             a->_3_y + 1 < MAP_HEIGHT
                                                 ? *ULTIMA_4402_GetTileAddr(a->_2_x, a->_3_y + 1)
                                                 : 0);
        if (native >= 0)
            AddCombatSprite(sprites, &count, ACTORS_Sprite(i, 256 + native), x, y, i);
    }
    for (int y = 0; y < 11; y++)
        for (int x = 0; x < 11; x++) {
            if (GetMapViewport(x, y) == 255 || GetMapViewport(x, y) == TILE_MAP_87)
                continue;
            int shape = CONTENTS_GAME_Shape(x + MAP_VIEW_X, y + MAP_VIEW_Y);
            if (shape && !SPRITES_Layer(256 + shape))
                AddCombatSprite(sprites, &count, 256 + shape, x, y, 32);
            bool owned = false;
            for (int i = 0; i < 32; i++)
                if (D_5c5a[i]._0_tile && D_5c5a[i]._1_animTile &&
                    D_5c5a[i]._2_x == x + MAP_VIEW_X && D_5c5a[i]._3_y == y + MAP_VIEW_Y)
                    owned = true;
            if (!owned && !GetMapViewport(x, y) && GetActorMap(x, y) != 0x16)
                AddCombatSprite(sprites, &count, 256 + GetActorMap(x, y), x, y, 32);
        }
    qsort(sprites, count, sizeof(*sprites), SPRITES_Compare);
    for (int i = 0; i < count; i++)
        GRAP_BUF_PutMapSprite(sprites[i].x, sprites[i].y, sprites[i].tile);
}
#endif

void ULTIMA_56ac_DrawMap(void)
{
    int local_2;
    int local_4;
    int local_6;
    int local_8;

    for (local_8 = 0; local_8 < 11; local_8++)
    {
        for (local_6 = 0; local_6 < 0xb; local_6++)
        {
            if (GetMapViewport(local_6, local_8) == 0)
            {
                if (GetActorMap(local_6, local_8) != 0x16)
                {
                    // Draw the ground before the sprite overlay on modern platforms.
#if defined(TARGET_SDL)
                    int dx = local_6 - (MAP_CENTER_X);
                    int dy = local_8 - (MAP_CENTER_Y);
                    ULTIMA_10e0_GRAP_51_PutTile(D_b11e[WIDE_GroundTile(dx,dy)], local_6, local_8);
#else
                    ULTIMA_10e0_GRAP_51_PutTile(0x100 + GetActorMap(local_6, local_8), local_6, local_8);
#endif
                }
            }
            else
            {
                if (GetMapViewport(local_6, local_8) == TILE_MAP_MOONGATE && D_5887 != 0 && D_5887 < 0x10)
                {
                    // moongate?
                    ULTIMA_1112_GRAP_60(D_5887, local_6, local_8);
                }
                else
                {
                    // draw map tile
#if defined(TARGET_SDL)
                    byte tile=GetMapViewport(local_6,local_8);
                    int dx = local_6 - (MAP_CENTER_X), dy = local_8 - (MAP_CENTER_Y);
                    if(tile!=255 && tile==WIDE_MapTile(dx,dy)) tile=WIDE_GroundTile(dx,dy);
                    ULTIMA_10e0_GRAP_51_PutTile(D_b11e[tile],local_6,local_8);
#else
                    ULTIMA_10e0_GRAP_51_PutTile(D_b11e[GetMapViewport(local_6, local_8)], local_6, local_8);
#endif
                }
            }
        }
    }

#if defined(TARGET_SDL)
    for (int ty = 0; ty < 11; ty++)
        for (int tx = 0; tx < 11; tx++)
            if (GetMapViewport(tx, ty) != 255 &&
                (GetMapViewport(tx, ty) != 0 ||
                 GRAP_BUF_SpriteIsTransparent(256 + GetActorMap(tx, ty))))
                TYPES_GAME_Draw(D_52ba_vdp._52d8_page ? g_linearEgaBuffer1 : g_linearEgaBuffer0,
                                320, 8 + tx * 16, 8 + ty * 16, tx - (MAP_CENTER_X),
                                ty - (MAP_CENTER_Y), 8, 184);
    for(local_8=0;local_8<11;local_8++) for(local_6=0;local_6<11;local_6++) {
        byte tile=GetMapViewport(local_6,local_8);
        int dx = local_6 - (MAP_CENTER_X), dy = local_8 - (MAP_CENTER_Y);
        if(tile==0 && GetActorMap(local_6,local_8)!=0x16) {
            if(!GRAP_BUF_SpriteIsTransparent(256+GetActorMap(local_6,local_8))) continue;
            tile=WIDE_MapTile(dx,dy);
        }
        if (!TYPES_ArtSlot(TYPES_GAME_At(D_5896_map_x + dx, D_5897_map_y + dy)) && tile != 255 &&
            tile == WIDE_MapTile(dx, dy) && WIDE_GroundTile(dx, dy) != tile)
            GRAP_BUF_PutMapSprite(local_6,local_8,D_b11e[tile]);
    }
    /* All terrain must be complete before outlines spill across cell edges.
     * Include offscreen large anchors in the same north-to-south order. */
    if (D_5893_map_id >= 128)
        DrawCombatSprites();
    else
        for (int layer = 0; layer < 2; ++layer)
            for (local_8 = -1; local_8 < 11; local_8++) {
                if (layer == 1)
                    for (unsigned actor = 0; actor < (unsigned)MAP_ACTOR_COUNT; ++actor) {
                        ActorFmt *a = &D_5c5a[actor];
                        if (!a->_0_tile || !a->_1_animTile || a->_4_z != D_5895_map_level)
                            continue;
                        int x = a->_2_x - MAP_VIEW_X;
                        int y = a->_3_y - MAP_VIEW_Y;
                        if (y != local_8 || (x >= 0 && y >= 0 && x < 11 && y < 11))
                            continue;
                        unsigned w, h;
                        ACTORS_Size(actor, &w, &h);
                        if ((w > 1 || h > 1) && x + (int)w > 0 && y + (int)h > 0 && x < 11 &&
                            WIDE_FootprintVisible(x - 5, y - 5, w, h))
                            GRAP_BUF_PutMapSprite(x, y, ACTORS_Sprite(actor, 256 + a->_1_animTile));
                    }
                if (local_8 < 0)
                    continue;
                for (local_6 = 0; local_6 < 11; local_6++) {
                    if (GetMapViewport(local_6, local_8) != 0 ||
                        GetActorMap(local_6, local_8) == 0x16)
                        continue;
                    unsigned native = GetActorMap(local_6, local_8);
                    bool body = native == TILE_ACTOR_SLEEP || native == TILE_ACTOR_DEAD;
                    if (body != (layer == 0))
                        continue;
                    /* Bodies occupy the ground beneath a footprint. Resolving their
                     * cell as a standing actor would redraw a large sprite off-anchor. */
                    unsigned sprite = body ? 256 + native
                                           : ACTORS_AtCell(MAP_VIEW_X + local_6,
                                                           MAP_VIEW_Y + local_8, 256 + native);
                    GRAP_BUF_PutMapSprite(local_6, local_8, sprite);
                }
            }
#endif

    if (0x7f < D_5893_map_id && (D_589f = !D_589f) != 0 && D_589e != 0xff && ULTIMA_5646(D_589e) == 0)
    {
        local_2 = (uint)D_ba14[D_589e].x * 0x10 + 8;
        local_4 = (uint)D_ba14[D_589e].y * 0x10 + 8;

        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_brightWhiteColor);

        for (local_6 = 0; local_6 < 2; local_6++)
        {
            for (local_8 = 0; local_8 < 0xf; local_8 += 0xe)
            {
                ULTIMA_0c9c_GRAP_39_HorizLine(local_2, local_4 + local_6 + local_8, local_2 + 0xf);
                ULTIMA_0cf2_GRAP_3c_VertLine(local_2 + local_6 + local_8, local_4, local_4 + 0xf);
            }
        }

        if (D_5898 != 0)
        {
            // 5813
            // draw crosshair / focus
            local_2 = (uint)D_5899 * 0x10 + 8; // cross hair x
            local_4 = (uint)D_589a * 0x10 + 8; // cross hair y

            // 586a
            for (local_6 = 0; local_6 < 2; local_6++)
            {
                for (local_8 = 0; local_8 < 2; local_8++)
                {
                    // 5887
                    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_brightWhiteColor);
                    ULTIMA_0b10_GRAP_Line(local_8 * 0xb + local_2 + 2, local_6 * 3 + local_4 + 6, local_8 * 3 + local_2 + 6, local_6 * 3 + local_4 + 6);
                    ULTIMA_0f90_GRAP_Pen(local_8 * 3 + local_2 + 6, local_6 * 0xb + local_4 + 2);
                    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
                    ULTIMA_0b10_GRAP_Line(local_8 * 0xb + local_2 + 2, local_6 * 5 + local_4 + 5, local_8 * 5 + local_2 + 5, local_6 * 5 + local_4 + 5);
                    ULTIMA_0f90_GRAP_Pen(local_8 * 5 + local_2 + 5, local_6 * 0xb + local_4 + 2);
                    ULTIMA_0b10_GRAP_Line(local_8 * 0xb + local_2 + 2, local_4 + local_6 + 7, local_8 * 3 + local_2 + 6, local_4 + local_6 + 7);

                    ULTIMA_0b10_GRAP_Line(local_2 + local_8 + 7, local_6 * 3 + local_4 + 6, local_2 + local_8 + 7, local_6 * 0xb + local_4 + 2);
                }
            }
        }
    }
#if defined(TARGET_SDL)
    GRAP_SDL_MapDrawn();
#endif
}

// Animate / Update
void ULTIMA_5910_UpdateFrame(void)
{
    int local_2;
    int local_4;

    D_545e = 0xff;
    if (D_587a == 'T')
    {
        D_5891 = 0;
    }
    if (D_58a4 != 0)
    {
        if (D_5891 != 0) // animate flag
        {
            if (D_5891 != 0xff)
            {
                ULTIMA_4552_AnimateActors();
            }
            ULTIMA_2f62_UpdateWindDirectionRandomly();
            if (D_5893_map_id < 0x80)
            {
                ULTIMA_475a();
                ULTIMA_70a6();
            }
        }

        if (D_5893_map_id < 0x80)
        {
            if (D_24e6 != 0)
            {
                ULTIMA_5d0a(D_58a5, (uint)D_5896_map_x - (uint)D_589b, (uint)D_5897_map_y - (uint)D_589c, 0xb);
                D_24e6 = 0;
            }
            else
            {
                for (local_4 = 0; local_4 < 11; local_4++)
                {
                    for (local_2 = 0; local_2 < 11; local_2++)
                    {
                        if (GetMapViewport(local_2, local_4) == 0)
                        {
                            GetMapViewport(local_2, local_4) =
                                *ULTIMA_4402_GetTileAddr((byte)local_2 + (uint)D_5896_map_x - 5, (byte)local_4 + (uint)D_5897_map_y - 5);
                        }
                    }
                }
            }
        }
        else // map_id >= 0x80; combat?
        {
            memcpy(D_ab02, D_ad14, 0x160);
            if (MAPS_ActiveCell(D_5893_map_id, D_5895_map_level, 0, 0))
                for (int y = 0; y < 11; y++)
                    for (int x = 0; x < 11; x++)
                        GetMapViewport(x, y) =
                            (x + MAP_VIEW_X < MAP_WIDTH && y + MAP_VIEW_Y < MAP_HEIGHT)
                                ? *ULTIMA_4402_GetTileAddr(x + MAP_VIEW_X, y + MAP_VIEW_Y)
                                : 255;
        }

        ULTIMA_5394();
        ULTIMA_56ac_DrawMap();
        if (D_5891 != 0)
        {
            ULTIMA_4102_AudioPlayAmbientSfx();
        }
    }

    D_5891 = 1;
}

static bool ULTIMA_5dfe(byte param_1, int param_2);

// CHECKED (NOT MATCHING: di, control flow, ...)
// generate visibility map (BFS)
static void ULTIMA_5a28(int param_1, int param_2_y, int param_3_x, int param_4, int param_5, uint param_6, byte* param_7_map)
{
    register byte* ptr;
    int local_218_dir; // -0x216
    byte local_216_tile;
    int local_214_y; // -0x212; y
    int local_212_x; // -0x210; x
    int local_210; // -0x20e
    int local_20e_queueReadPos; // -0x20c
    int local_20c; // -0x20a
    int local_20a_parentY; // -0x208
    int local_208_parentX; // -0x206
    int local_206_queue[257]; // -0x204
    int local_4_queueWritePos;

    local_20e_queueReadPos = 0;
    local_4_queueWritePos = 0;
    local_218_dir = 7;
    local_20c = 1;
    local_210 = 0;

    if (param_1 > 0)
    {
        // 5a57
        if (param_4 == -0x6f)
        {
            param_4 = 0;
            local_210++;
        }

        // 5a66 (si vs di)
        param_1++;
        local_206_queue[local_4_queueWritePos] = 5;
        local_206_queue[++local_4_queueWritePos] = 5;
        ++local_4_queueWritePos;
        param_7_map[param_4 * 0x20 + param_5 + 0xa5] =
            *ULTIMA_4402_GetTileAddr(param_3_x + (uint)D_589b + 5, param_2_y + (uint)D_589c + 5);

        while (local_20e_queueReadPos != local_4_queueWritePos)
        {
            // 5abc
            local_20a_parentY = local_214_y = local_206_queue[local_20e_queueReadPos];
            local_208_parentX = local_212_x = local_206_queue[++local_20e_queueReadPos];
            ++local_20e_queueReadPos;

            while (local_218_dir > -1) // 5ce5
            {
                // 5aec
                switch (local_218_dir)
                {
                case 0:
                case 1:
                case 7:
                    local_212_x--;
                    break;
                case 4:
                case 5:
                    local_212_x++;
                    break;
                case 2:
                case 3:
                    local_214_y--;
                    break;
                case 6:
                    local_214_y++;
                    break;
                }

                if (local_212_x < 0 || 10 < local_212_x || local_214_y < 0 || 10 < local_214_y)
                {
                    // 5b42
                    local_20c = 0;
                }

#if !defined(MATCHING_BUILD)
                // TODO: temporary!
                if (param_7_map == D_ad14)
                {
                    if (param_4 + local_214_y < 0 || param_5 + local_212_x < 0 || param_4 + local_214_y >= 0x20 || param_5 + local_212_x >= 0x20)
                    {
                        local_218_dir--;
                        local_20c = 1;
                        continue;
                    }
                }
                else if (param_7_map == D_ab02)
                {
                    if (param_4 + local_214_y < 0 || param_5 + local_212_x < 0 || param_4 + local_214_y >= 0xb || param_5 + local_212_x >= 0x20)
                    {
                        local_218_dir--;
                        local_20c = 1;
                        continue;
                    }
                }
                else
                {
                    ASSERT(0);
                }
#endif

                // 5b48
                ptr = &param_7_map[(param_4 + local_214_y) * 0x20 + param_5 + local_212_x];

                // 5b5f
                if (local_210 == 0)
                {
                    // 5b66
                    if ((GetMapViewport(local_212_x, local_214_y) != 0) && (0x1f >= param_4 + local_214_y))
                    {
                        // 5b83
                        GetMapViewport(local_212_x, local_214_y) = 0;

                        // -> 5b9b
                    }
                    else
                    {
                        // 5b95
                        local_20c = 0;
                    }
                }
                else
#if !defined(MATCHING_BUILD)
                    if (local_20c != 0)
#endif
                {
                    // 5b90
                    if (*ptr != 0xff)
                    {
                        // 5b95
                        local_20c = 0;
                    }
                }

                // 5b9b
                if (local_20c != 0)
                {
                    // 5ba5
                    local_216_tile = *ULTIMA_4402_GetTileAddr(param_3_x + local_212_x + (uint)D_589b, param_2_y + local_214_y + (uint)D_589c);
                    if (ULTIMA_6ff0(local_212_x, local_214_y) >= param_1)
                    {
                        // TODO: control flow position
                        if (local_210) // 5be1 : ??
                        {
                            // 5beb
                            if (TYPES_GAME_Sight(
                                    param_3_x + local_212_x + (uint)D_589b,
                                    param_2_y + local_214_y + (uint)D_589c,
                                    ULTIMA_6ff0(local_212_x, local_214_y),
                                    ULTIMA_5dfe(local_216_tile,
                                                ULTIMA_6ff0(local_212_x, local_214_y))) == 0) {
                                // 5c05
                                if (
#if !defined(MATCHING_BUILD)
                                    param_2_y + local_20a_parentY >= 0x20 || param_3_x + local_208_parentX >= 0x20 ||
                                    param_2_y + local_214_y < 0 || param_3_x + local_208_parentX < 0 ||
#endif
                                    param_7_map[local_20a_parentY * 0x20 + local_208_parentX] == 0 ||
                                    D_ad14[(param_2_y + local_20a_parentY) * 0x20 + param_3_x + local_208_parentX] == 0 ||
                                    D_ad14[(param_2_y + local_214_y) * 0x20 + param_3_x + local_212_x] == 0)
                                {
                                    // 5c47
                                    local_216_tile = *ptr = 0xff;
                                }
                                else
                                {
                                    // 5c93
                                    *ptr = local_216_tile;
                                }
                            } else {
                                // 5c52
                                if (param_2_y + local_214_y < 0 || param_3_x + local_212_x < 0 ||
                                    param_3_x + local_212_x >= 0x20 || param_2_y + local_214_y >= 0x20)
                                {
                                    // 5c74
                                    *ptr = 0;
                                }
                                else
                                {
                                    // 5c7a
                                    if (D_ad14[(param_2_y + local_214_y) * 0x20 + param_3_x + local_212_x] != 0)
                                    {
                                        // 5c93
                                        *ptr = local_216_tile;
                                    }
                                    else
                                    {
                                        // 5c74
                                        *ptr = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            // 5c9c
                            local_216_tile = 0xff;
                        }
                    }
                    else
                    {
                        // 5c93
                        *ptr = local_216_tile;
                    }

                    // 5ca1
                    if (TYPES_GAME_Sight(param_3_x + local_212_x + (uint)D_589b,
                                         param_2_y + local_214_y + (uint)D_589c,
                                         ULTIMA_6ff0(local_212_x, local_214_y),
                                         ULTIMA_5dfe(local_216_tile,
                                                     ULTIMA_6ff0(local_212_x, local_214_y))) != 0) {
                        local_206_queue[local_4_queueWritePos] = local_214_y;
                        local_4_queueWritePos++;
                        local_206_queue[local_4_queueWritePos] = local_212_x;
                        local_4_queueWritePos++;
                    }
                }

                // 5cdb
                local_218_dir--;
                local_20c = 1;
            }

            // 5cef
            local_218_dir = 7;
        }
    }

    // 5d01
}

// update map data?
// param_1: light intensity
void ULTIMA_5d0a(int param_1_light, int param_2_x, int param_3_y, int param_4)
{
    if (MAPS_ActiveCell(D_5893_map_id, D_5895_map_level, 0, 0)) {
        for (int y = 0; y < 11; y++)
            for (int x = 0; x < 11; x++) {
                int dx = x - 5, dy = y - 5,
                    visible = param_1_light > 0 &&
                              (param_1_light >= 50 || dx * dx + dy * dy <= param_1_light);
                int ax = abs(dx), ay = abs(dy), sx = dx < 0 ? -1 : 1, sy = dy < 0 ? -1 : 1,
                    err = ax - ay, cx = 0, cy = 0;
                while (visible && (cx != dx || cy != dy)) {
                    int e = 2 * err;
                    if (e > -ay) {
                        err -= ay;
                        cx += sx;
                    }
                    if (e < ax) {
                        err += ax;
                        cy += sy;
                    }
                    if (cx == dx && cy == dy)
                        break;
                    int tile = *ULTIMA_4402_GetTileAddr(D_5896_map_x + cx, D_5897_map_y + cy);
                    if (!TYPES_GAME_Sight(D_5896_map_x + cx, D_5897_map_y + cy, cx * cx + cy * cy,
                                          !memchr(D_6a86, tile, sizeof(D_6a86))))
                        visible = 0;
                }
                GetMapViewport(x, y) =
                    visible ? *ULTIMA_4402_GetTileAddr(D_5896_map_x + dx, D_5897_map_y + dy) : 255;
            }
        return;
    }

    int local5_4;
    int local4_6;
    byte* local3_8;
    int local2_a;
    int local1_c;

    for (local2_a = 0; local2_a < 0xb; local2_a++)
    {
        memset(&GetMapViewport(0, local2_a), 0xff, 0xb);
    }

    local2_a = param_2_x - 5;
    local1_c = param_3_y - 5;

    if (param_1_light > 0)
    {
        ULTIMA_5a28(param_1_light, local1_c, local2_a, -111, 0, 0x20, D_ab02);
        local3_8 = D_ab02;

        for (local1_c = 0; local1_c < 0xb; local1_c++)
        {
            for (local2_a = 0; local2_a < 0xb; local2_a++)
            {
                if (*local3_8 == 0)
                {
                    (*local3_8)--;
                }

                local3_8++;
            }

            local3_8 += 0x15;
        }
    }

    if (param_1_light < 0)
    {
        local5_4 = param_2_x - 5;
        local4_6 = param_3_y - 5;

        for (local1_c = 0; local1_c < 0xb; local1_c++)
        {
            for (local2_a = 0; local2_a < 0xb; local2_a++)
            {
                GetMapViewport(local2_a, local1_c) = *ULTIMA_4402_GetTileAddr(
                    local5_4 + local2_a + (uint)D_589b,
                    local4_6 + local1_c + (uint)D_589c);
            }
        }
    }
}

static bool ULTIMA_5dfe(byte param_1, int param_2)
{
    if (param_1 == TILE_MAP_4B || param_1 == TILE_MAP_4A || param_1 == TILE_MAP_DOOR_BA || param_1 == TILE_MAP_DOOR_BB || param_1 == TILE_MAP_98)
    {
        if (param_2 == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        if (!memchr(D_6a86, param_1, 0x13))
            return 1;
        else
            return 0;
    }
}

void ULTIMA_5e4a(void)
{
    byte local_92;
    int local_90;
    int local_8e[64];
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    u8* local_4;

    local_90 = 0;
    local_4 = D_ad14;

    memset(D_ad14, 0xff, 0x400);

    // 5e72
    for (local_8 = 0; local_8 < 0x20; local_8++)
    {
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            // 5e78
            local_92 = *ULTIMA_4402_GetTileAddr(D_589b + local_6, D_589c + local_8);
            if (local_90 < 64 && memchr(D_6a9a, local_92, 10) != 0) {
                // 5eb0
                local_8e[local_90++] = local_8;
                local_8e[local_90++] = local_6;
                *local_4 = local_92;
            }

            // 5ed2
            local_4++;
        }
    }

    local_6 = local_90;
    local_8 = 0;

    // 5ef5
    if (local_90 > 0)
    {
        do
        {
            // 5efe
            local_e = local_8e[local_8++] - 5;
            local_c = local_8e[local_8] - 5;

            // 5f23
            for (local_a = 0; local_a < 0xb; local_a++)
            {
                // 5f29
                memset(&GetMapViewport(0, local_a), 0xff, 0xb);
            }

            // 5f3f
            ULTIMA_5a28(10, local_e, local_c, local_e, local_c, 0x20, D_ad14);
            local_8++;
        } while (local_8 < local_6);
    }

    // 5f65
    local_4 = D_ad14;

    for (local_6 = 0; local_6 < 0x400; local_6++)
    {
        if (*local_4 == 0xff)
        {
            (*local_4)++;
        }
        local_4++;
    }
}

void ULTIMA_6fbc(int param_1);

void ULTIMA_6bc2(int param_1, int param_2);

// CHECKED
// param_1: special map type (flags)
// - 0: combat
// - 2: combat in dungeon?
// - 4: camping/hole up
// - 0x80: ?
void ULTIMA_5f86_SpecialMapHandler(int param_1, int param_2, int param_3)
{
    int local_8;
    int local_c;
    int local_a;
    int local_4; // active character
    int local_6;
    int local_e;

    D_58a1 = param_1;
    local_8 = D_5896_map_x;
    local_c = D_5897_map_y;
    local_a = D_5895_map_level;

    D_5894 = D_5893_map_id;
    local_4 = D_587b;
    debug("Entering special map: mode=%d map=%d active=%d\n", param_1, D_5894, local_4);
    D_5893_map_id = 0xff;

    // copy actors
    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        D_a9fc[local_6] = D_5c5a[local_6];
    }

    if (param_1 == 0)
    {
        if ((D_5c5a[param_2]._0_tile & 0xfc) == TILE_ACTOR_PIRATE)
        {
            local_6 = 0x1;
        }
        else
        {
            local_6 = ((D_5c5a[param_2]._0_tile - TILE_ACTOR_WIZARD) >> 2);
        }

        if (D_5c5a[param_2]._5 > 0x7f)
        {
            local_6 += 0x100;
        }

        // 6021
        ULTIMA_6bc2(1, local_6); // ***CONFLICT***
    }
    else
    {
        if ((param_1 & 4) != 0) // 602e
        {
            // 6034
            // hole up
            if (CMDS_0000(param_1, param_2, param_3) == 0)
            {
                goto L_606c;
            }
        }
        else if ((param_1 & 2) != 0) // 6046
        {
            local_6 = param_2;
            DNGLOOK_117e(0, 2);
        }
        else
        {
            goto L_606c;
        }
    }

    // 605c
    D_589e = D_587b = 0xff;
    D_58a3 = 0;

    COMBAT_0b94_MainLoop(); // COMBAT.0b94

L_606c:
    CONTENTS_EndEncounter();
    // 606c
    if (D_bb16 != 0)
    {
        D_bb16 = 0;
        ULTIMA_6fbc(1);
    }

    D_5896_map_x = local_8;
    D_5897_map_y = local_c;
    D_5895_map_level = local_a;
    D_5893_map_id = D_5894;
    D_24e6 = 1;

    AUDIO_PlayBgmPerMap();

    ULTIMA_2900_UpdateVitalsDisplay();

    /* 0xff means no active character; never use it as a party index. */
    if (local_4 < (int)(sizeof(D_55a8_party) / sizeof(D_55a8_party[0])) &&
        D_55a8_party[local_4].status != STATUS_DEAD && D_55a8_party[local_4].status != STATUS_SLEEP)
    {
        D_587b = local_4;
    }
    else
    {
        D_587b = 0xff;
    }

    for (local_e = 0; local_e < 0x20; local_e++)
    {
        D_5c5a[local_e] = D_a9fc[local_e];
    }
    debug("Returned from special map: map=%d active=%d\n", D_5893_map_id, D_587b);
}
