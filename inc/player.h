// player.h
#ifndef PLAYER_H
#define PLAYER_H


#include "common.h"
#include "draw.h"
#include "tileset.h"
#include "animation.h"

void player_init(t_game* game, int x, int y);
void player_draw(t_game* game);
void player_logic(t_game* game);
void player_free(t_game* game);

#endif
