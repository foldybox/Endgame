// npc.c

#include "npc.h"

t_entity *npc_add(t_game *game, t_tile tile, int x, int y, bool is_active) {
    t_entity *npc = entity_add(game, ENTYPE_NPC, x, y, tile, FACING_RIGHT);

    npc->data = malloc(sizeof(t_entdata_npc));

    t_entdata_npc *data = (t_entdata_npc *)npc->data;

    data->is_active = is_active;

    return npc;
}

void npc_logic(t_game *game, t_entity *npc) {
    // temp
    if (false)
    {
        game->control.left = 0;
        npc->is_death = true;
    }
    
}

void npc_draw(t_game *game, t_entity *npc) {
    blit_tile(game, npc->tile, game->scene_offset.x + npc->x * (TILE_SIZE * TILE_SCALE), game->scene_offset.y + npc->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, ANCHOR_TOP_LEFT);
}

void npc_free(t_entity *npc) {
    free(npc->data);
    npc->data = NULL;
}
