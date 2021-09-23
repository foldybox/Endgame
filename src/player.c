// player.c

#include "player.h"

t_entity *player_init(t_game *game) {
    t_entity *player = (t_entity *) malloc(sizeof(t_entity));
    if (player == NULL) return NULL;

    memset(player, 0, sizeof(t_entity));

	player->x = 100;
	player->y = 100;

    player->texture = loadTexture(game, "assets/sprites/sp_player.png");

    return player;
}

void player_free(t_entity *player) {
    free(player);
}
