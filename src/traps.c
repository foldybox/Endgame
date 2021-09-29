// traps.c

#include "traps.h"

void trap_init(t_game *game) {
    t_traps *trap = (t_traps *) malloc(sizeof(t_traps));
    if (trap == NULL) exit(-1);

    memset(trap, 0, sizeof(t_traps));

    int tX = 3;
    int tY = 3;

	trap->x = tX * (TILE_SIZE * TILE_SCALE);
	trap->y = tY * (TILE_SIZE * TILE_SCALE);
    trap->tile = set_tile(3, 3);

    game->trap = trap;
    game->trap->next = NULL;

    trap_add(game, 6, 5);
}


void trap_add(t_game * game, int x, int y) {
    int tX = x * (TILE_SIZE * TILE_SCALE);
    int tY = y * (TILE_SIZE * TILE_SCALE);

    t_traps *current = game->trap;

    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (t_traps *) malloc(sizeof(t_traps));
    current->next->x = tX;
    current->next->y = tY;
    current->next->next = NULL;
}

void trap_logic(t_game *game) {
    int pX = game->player->x / (TILE_SIZE * TILE_SCALE);
    int pY = game->player->y / (TILE_SIZE * TILE_SCALE);
    t_traps *current = game->trap;

    while (current != NULL) {
        int tX = current->x / (TILE_SIZE * TILE_SCALE);
        int tY = current->y / (TILE_SIZE * TILE_SCALE);

        if (pX == tX && pY == tY) {
            game->player->is_death = true;
            current->activated = true;
        }
        if (pX != tX || pY != tY) {
            current->activated = false;
        }

        current = current->next;
    }
}

void trap_draw(t_game *game) {
	double pX = 0, pY = 0;

    t_traps *current = game->trap;

    while (current != NULL) {
        pX = current->x;
        pY = current->y;
        current->tile = set_tile(2, 3);

        if (current->activated == true) current->tile = set_tile(3, 3);
        
        blit_tile(game, current->tile, pX, pY, false);

        current = current->next;
    }
}

void trap_free(t_game *game) {
    while (game->trap != NULL) {
        t_traps *next_node = NULL;
        next_node = game->trap->next;

        free(game->trap);
        game->trap = next_node;
    }

	game->trap = NULL;
}
