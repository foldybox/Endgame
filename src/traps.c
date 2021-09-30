// traps.c

#include "traps.h"

void trap_init(t_game *game) {
    t_traps *trap = (t_traps *) malloc(sizeof(t_traps));
    if (trap == NULL) exit(-1);

    memset(trap, 0, sizeof(t_traps));

	trap->x1 = (0);
	trap->y1 = (0);
	trap->x2 = (0);
	trap->y2 = (0);
    trap->timer = 0;
    trap->delay = 1000;

    game->trap = trap;
    game->trap->next = NULL;

    trap_add(game, TRAP_GLIMMER, 3, 5, 3, 7);
    trap_add(game, TRAP_TRIGGER, 5, 5, 5, 7);
}

void trap_add(t_game * game, t_trap_type type, int x1, int y1, int x2, int y2) {
    int to_tile = TILE_SIZE * TILE_SCALE;
    int tX1 = x1 * to_tile;
    int tY1 = y1 * to_tile;
    int tX2 = x2 * to_tile;
    int tY2 = y2 * to_tile;

    t_traps *current = game->trap;

    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (t_traps *) malloc(sizeof(t_traps));

    current->next->delay = game->trap->delay;
    current->next->trap_type = type;
    current->next->x1 = tX1;
    current->next->y1 = tY1;
    current->next->x2 = tX2;
    current->next->y2 = tY2;
    current->next->timer = 0;
    current->next->next = NULL;
}

void trap_logic(t_game *game) {
    t_traps *current = game->trap;

    while (current != NULL) {
        if (current->x1 == (0) || current->y1 == (0) || current->x2 == (0) || current->y2 == (0)) {
            current = current->next;
            continue;
        }

        switch (current->trap_type)
        {
        case TRAP_TRIGGER:
            trap_trigger(game, current);
            break;
        
        case TRAP_GLIMMER:
            trap_glimmer(game, current);
            break;
        
        default:
            break;
        }

        current = current->next;
    }
}

void trap_draw(t_game *game) {
	double tX1 = 0, tY1 = 0, tX2 = 0, tY2 = 0;

    t_traps *current = game->trap;

    while (current != NULL) {
        if (current->x1 == (0) || current->y1 == (0) || current->x2 == (0) || current->y2 == (0)) {
            current = current->next;
            continue;
        }

        int to_tile = TILE_SIZE * TILE_SCALE;
        tX1 = current->x1 / to_tile;
        tY1 = current->y1 / to_tile;
        tX2 = current->x2 / to_tile;
        tY2 = current->y2 / to_tile;

        if (current->activated == true) {
            current->tile = set_tile(3, 3);
        }
        else {
            current->tile = set_tile(2, 3);
        }

        for (int i = tY1; i <= tY2; i++) {
            for (int j = tX1; j <= tX2; j++) {
                blit_tile(game, current->tile, j * to_tile, i * to_tile, false);
            }
        }

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

/*==========================================================================
                            Types traps
==========================================================================*/

void trap_trigger(t_game *game, t_traps *current) {
    int to_tile = TILE_SIZE * TILE_SCALE;
    int pX = game->player->x / to_tile;
    int pY = game->player->y / to_tile;
    int tX1 = current->x1 / to_tile;
    int tY1 = current->y1 / to_tile;
    int tX2 = current->x2 / to_tile;
    int tY2 = current->y2 / to_tile;
    current->activated = false;

    for (int i = tY1; i <= tY2; i++) {
        for (int j = tX1; j <= tX2; j++) {
            if (pX == j && pY == i) {
                current->activated = true;
                game->player->is_death = true;
            }
        }
    }
}

void trap_glimmer(t_game *game, t_traps *current) {
    int to_tile = TILE_SIZE * TILE_SCALE;
    int pX = game->player->x / to_tile;
    int pY = game->player->y / to_tile;
    int tX1 = current->x1 / to_tile;
    int tY1 = current->y1 / to_tile;
    int tX2 = current->x2 / to_tile;
    int tY2 = current->y2 / to_tile;
    game->player->is_death = false;

    if (current->timer == 0) current->timer = SDL_GetTicks();

    if (SDL_GetTicks() > current->timer + current->delay) {
        current->activated = false;

        if (SDL_GetTicks() > current->timer + current->delay * 2) current->timer = SDL_GetTicks();
    }
    else {
        current->activated = true;
    }

    for (int i = tY1; i <= tY2; i++) {
        for (int j = tX1; j <= tX2; j++) {
            if (pX == j && pY == i && current->activated == true) {
                game->player->is_death = true;
            }
        }
    }
}
