// player.h
#ifndef PLAYER_H
#define PLAYER_H


#include "common.h"
#include "draw.h"

t_entity *player_init(t_game *game);
void player_free(t_entity *player);

#endif
