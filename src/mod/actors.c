#include "actors.h"
#include "vars.h"
#include "contents.h"
#include "macros.h"
#include "types_game.h"
#include "funcs.h"
#include "tiles.h"
#include <string.h>
static unsigned encounter;
TypeDef ACTORS_Def(unsigned type) {
    TypeDef d;
    /* Look resolves an authored actor's tile-type ID (including vanilla
     * overrides); combat also accepts its original 0..47 entity index. */
    if (type >= 256 && TYPES_Get(type, &d) && d.kind)
        return d;
    if (type < 48 && TYPES_Defined(320 + type * 4) && TYPES_Get(320 + type * 4, &d) && d.kind)
        return d;
    unsigned i = type < 48 ? type : 0;
    TYPES_Vanilla(1, 64 + i * 4, &d);
    memcpy(d.stats, &D_13bc_enemyStats[i], 8);
    d.actorFlags = D_153c_enemyFlags[i];
    d.range = D_159c[i];
    d.projectileAppearance = D_15cc[i];
    d.companion = D_16d4[i];
    return d;
}
EnemyStats ACTORS_Stats(unsigned type) {
    TypeDef d = ACTORS_Def(type);
    EnemyStats result;
    memcpy(&result, d.stats, sizeof(result));
    return result;
}
unsigned ACTORS_Flags(unsigned type) { return ACTORS_Def(type).actorFlags; }
unsigned ACTORS_Range(unsigned type) { return ACTORS_Def(type).range; }
unsigned ACTORS_Projectile(unsigned type) { return ACTORS_Def(type).projectileAppearance; }
unsigned ACTORS_Profile(unsigned type) {
    return (ACTORS_Def(type).base - 64) / 4;
}
char *ACTORS_Name(unsigned type, int plural) {
    if (type < 48 && !TYPES_Defined(320 + type * 4))
        return plural ? D_18b6[type] : D_1856[type];
    static char names[4][128];
    static unsigned next;
    TypeDef d = ACTORS_Def(type);
    char *out = names[next++ % 4];
    snprintf(out, 128, "%s", plural && d.description[0] ? d.description : d.name);
    return out;
}
unsigned ACTORS_Target(unsigned type, unsigned action, unsigned fallback) {
    TypeDef d = ACTORS_Def(type);
    unsigned id = action < 4 ? d.result[action] : 0;
    return id ? (id < 512 ? ((id - 320) / 4) : id) : fallback;
}
unsigned ACTORS_Instance(unsigned actor) {
    if (actor >= (unsigned)MAP_ACTOR_COUNT || !D_5c5a[actor]._0_tile)
        return 0;
    unsigned type = 0;
    if (D_5893_map_id >= 128) {
        for (unsigned i = 0; i < 32; i++)
            if ((D_ba14[i].flags & COMBAT_FLAGS_MONSTER) && D_ba14[i].actorIdx == actor) {
                type = D_ba14[i].entityIdx >= 512 ? D_ba14[i].entityIdx : 0;
                break;
            }
    } else if (!D_5893_map_id) {
        TypeCell key = {4, 0, (int8_t)D_5895_map_level, actor, 0, 0, 0};
        type = TYPES_At(key, 0);
    } else if (MAPS_Outside(D_5893_map_id)) {
        for (unsigned slot = actor >= 32 ? actor : 1; slot < (actor >= 32 ? actor + 1 : 32); slot++)
            if (D_5f5e[slot]._0 && D_5f5e[slot]._c == actor) {
                TypeCell key = {3, D_5893_map_id, 0, slot & 255, slot >> 8, 0, 0};
                type = TYPES_At(key, 0);
                break;
            }
    }
    if (!type) {
        unsigned original = 256 + (D_5c5a[actor]._0_tile & 252);
        if (TYPES_Defined(original))
            type = original;
    }
    TypeDef d;
    /* Corpse, invisibility and temporary native effects retain their native artwork. */
    if (!type || !TYPES_Get(type, &d) || !d.kind || (D_5c5a[actor]._0_tile & 252) != d.base)
        return 0;
    return type;
}
void ACTORS_Size(unsigned actor, unsigned *width, unsigned *height) {
    *width = *height = 1;
    unsigned type = ACTORS_Instance(actor);
    if (type)
        TYPES_ArtSize(type, D_5893_map_id == 0, width, height);
}
int ACTORS_Contains(unsigned actor, int x, int y) {
    if (actor >= (unsigned)MAP_ACTOR_COUNT)
        return 0;
    unsigned w, h;
    ACTORS_Size(actor, &w, &h);
    int dx = x - D_5c5a[actor]._2_x, dy = y - D_5c5a[actor]._3_y;
    if (!D_5893_map_id) {
        dx = MAPS_Wrap(dx, MAP_WIDTH);
        dy = MAPS_Wrap(dy, MAP_HEIGHT);
    }
    return dx >= 0 && dy >= 0 && dx < (int)w && dy < (int)h;
}
int ACTORS_CombatContains(unsigned entity, int x, int y) {
    if (entity >= 32 || D_ba14[entity].actorIdx >= 32)
        return 0;
    unsigned w, h;
    ACTORS_Size(D_ba14[entity].actorIdx, &w, &h);
    return x >= D_ba14[entity].x && y >= D_ba14[entity].y && x < D_ba14[entity].x + (int)w &&
           y < D_ba14[entity].y + (int)h;
}
int ACTORS_CanPlace(unsigned type, int x, int y, unsigned ignoreActor) {
    TypeDef d = ACTORS_Def(type);
    unsigned w = D_5893_map_id ? TYPES_Width(&d) : 1;
    unsigned h = D_5893_map_id ? TYPES_Height(&d) : 1;

    if (x < 0 || y < 0 || x + (int)w > MAP_WIDTH || y + (int)h > MAP_HEIGHT)
        return 0;
    unsigned shape = d.base;
    if (ignoreActor < (unsigned)MAP_ACTOR_COUNT)
        shape = ACTORS_MoveShape(ignoreActor, shape);
    else {
        TypeDef native;
        TYPES_Vanilla(1, shape, &native);
        if (native.moveProfile != d.moveProfile)
            for (unsigned candidate = 0; candidate < 256; candidate += 4) {
                TYPES_Vanilla(1, candidate, &native);
                if (native.moveProfile == d.moveProfile) {
                    shape = candidate;
                    break;
                }
            }
    }
    for (unsigned oy = 0; oy < h; ++oy)
        for (unsigned ox = 0; ox < w; ++ox) {
            int tx = x + ox, ty = y + oy;
            if (!TYPES_GAME_Walkable(shape, tx, ty))
                return 0;
            if (D_5893_map_id >= 128 && *ULTIMA_4402_GetTileAddr(tx, ty) == 255)
                return 0;
            for (unsigned other = 0; other < (unsigned)MAP_ACTOR_COUNT; ++other) {
                ActorFmt *a = &D_5c5a[other];
                if (other == ignoreActor || !a->_0_tile || !a->_1_animTile)
                    continue;
                if (D_5893_map_id < 128 && a->_4_z != D_5895_map_level)
                    continue;
                if ((a->_0_tile & 252) == TILE_ACTOR_E8 || a->_0_tile == TILE_ACTOR_DEAD ||
                    a->_0_tile == TILE_ACTOR_SLEEP)
                    continue;
                if (ACTORS_Contains(other, tx, ty))
                    return 0;
            }
            if (D_5893_map_id > 0 && D_5893_map_id < 128 && ignoreActor != 0 &&
                tx == D_5896_map_x && ty == D_5897_map_y)
                return 0;
        }
    return 1;
}
int ACTORS_CanMove(unsigned actor, int x, int y) {
    if (actor >= (unsigned)MAP_ACTOR_COUNT)
        return 0;
    unsigned type = ACTORS_Instance(actor);
    if (!type) {
        unsigned shape = D_5c5a[actor]._0_tile & 252;
        type = shape >= 64 ? (shape - 64) / 4 : 0;
    }
    unsigned w, h;
    ACTORS_Size(actor, &w, &h);
    int dx = x - D_5c5a[actor]._2_x, dy = y - D_5c5a[actor]._3_y;
    if ((w > 1 || h > 1) && (dx == 1 || dx == -1) && (dy == 1 || dy == -1) &&
        (!ACTORS_CanPlace(type, x, D_5c5a[actor]._3_y, actor) ||
         !ACTORS_CanPlace(type, D_5c5a[actor]._2_x, y, actor)))
        return 0;
    return ACTORS_CanPlace(type, x, y, actor);
}
static int clampCell(int value, int start, unsigned size) {
    return value < start ? start : value >= start + (int)size ? start + (int)size - 1 : value;
}
void ACTORS_AttackCells(unsigned first, unsigned second, int *ax, int *ay, int *bx, int *by) {
    unsigned aw, ah, bw, bh;
    ACTORS_Size(D_ba14[first].actorIdx, &aw, &ah);
    ACTORS_Size(D_ba14[second].actorIdx, &bw, &bh);
    *bx = clampCell(D_ba14[first].x, D_ba14[second].x, bw);
    *by = clampCell(D_ba14[first].y, D_ba14[second].y, bh);
    *ax = clampCell(*bx, D_ba14[first].x, aw);
    *ay = clampCell(*by, D_ba14[first].y, ah);
}
int ACTORS_Distance(unsigned first, unsigned second) {
    int ax, ay, bx, by;
    ACTORS_AttackCells(first, second, &ax, &ay, &bx, &by);
    int dx = bx - ax, dy = by - ay, squared = dx * dx + dy * dy, distance = 0;
    while (squared >= (distance + 1) * (distance + 1))
        ++distance;
    return distance;
}
unsigned ACTORS_Sprite(unsigned actor, unsigned fallback) {
    if (actor < (unsigned)MAP_ACTOR_COUNT && D_5c5a[actor]._0_tile >= 64 &&
        D_5c5a[actor]._1_animTile < 0x20)
        return fallback; /* Native death/sleep/hit effects are not authored idle poses. */
    unsigned type = ACTORS_Instance(actor);
    if (!type || !D_5c5a[actor]._1_animTile)
        return fallback;
    ActorFmt *a = &D_5c5a[actor];
    /* Large-sprite paths may supply the idle frame before furniture has been
     * resolved. Apply the same native pose rules as the normal viewport. */
    if (fallback == 256u + a->_1_animTile) {
        bool reflection;
        int pose = ULTIMA_ResolveActorTile(
            a->_1_animTile, *ULTIMA_4402_GetTileAddr(a->_2_x, a->_3_y),
            a->_3_y ? *ULTIMA_4402_GetTileAddr(a->_2_x, a->_3_y - 1) : 0,
            a->_3_y + 1 < MAP_HEIGHT ? *ULTIMA_4402_GetTileAddr(a->_2_x, a->_3_y + 1) : 0,
            &reflection);
        if (pose >= 0)
            fallback = 256u + pose;
    }
    /* Furniture, reflections and climbing use shared native artwork, not
     * frames from the actor's authored standing/walking animation. */
    if (fallback >= 256 && fallback < 512 &&
        ((fallback - 256) & 252) != (a->_1_animTile & 252))
        return fallback;
    return TYPES_ActorArt(type, fallback);
}
unsigned ACTORS_AtCell(int x, int y, unsigned fallback) {
    for (unsigned actor = 0; actor < (unsigned)MAP_ACTOR_COUNT; actor++) {
        ActorFmt *a = &D_5c5a[actor];
        if (a->_0_tile && a->_1_animTile && ACTORS_Contains(actor, x, y) &&
            a->_4_z == D_5895_map_level)
            return ACTORS_Sprite(actor, fallback);
    }
    return fallback;
}
unsigned ACTORS_MoveShape(unsigned actor, unsigned fallback) {
    unsigned type = ACTORS_Instance(actor);
    if (!type)
        return fallback;
    TypeDef d;
    TYPES_Get(type, &d);
    TypeDef native;
    TYPES_Vanilla(1, fallback, &native);
    if (native.moveProfile == d.moveProfile)
        return fallback;
    for (unsigned shape = 0; shape < 256; shape += 4) {
        TYPES_Vanilla(1, shape, &native);
        if (native.moveProfile == d.moveProfile)
            return shape | (fallback & 3);
    }
    return fallback;
}
void ACTORS_SetEncounter(unsigned actor) {
    encounter = ACTORS_Instance(actor);
    if (encounter < 512)
        encounter = 0;
}
unsigned ACTORS_Encounter(void) { return encounter; }
unsigned ACTORS_PlacedEncounter(unsigned slot, unsigned fallback) {
    TypeCell key = {
        CONTENTS_EncounterKind() + 4, CONTENTS_EncounterMap(), 0, slot & 255, slot >> 8, 0, 0};
    return TYPES_At(key, fallback);
}

int ACTORS_Transform(unsigned entity) {
    if (entity >= 32 || !(D_ba14[entity].flags & COMBAT_FLAGS_MONSTER))
        return 0;
    CombatEntity *e = &D_ba14[entity];
    TypeDef old = ACTORS_Def(e->entityIdx);
    if (!old.result[0])
        return 0;
    unsigned target = ACTORS_Target(e->entityIdx, 0, e->entityIdx);
    TypeDef next = ACTORS_Def(target);
    if (!ACTORS_CanPlace(target, e->x, e->y, e->actorIdx))
        return 0;
    e->entityIdx = target;
    e->hp = next.stats[5];
    e->dex = next.stats[1];
    e->turnTimer = 36 - e->dex;
    D_5c5a[e->actorIdx]._0_tile = D_5c5a[e->actorIdx]._1_animTile = next.base;
    return 1;
}
