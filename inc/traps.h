// traps.h
#ifndef TRAPS_H
#define TRAPS_H

#include "common.h"
#include "draw.h"
#include "tileset.h"

void trap_add(t_game * game, int x, int y);
void trap_init(t_game* game);
void trap_draw(t_game* game);
void trap_logic(t_game* game);
void trap_free(t_game* game);

#endif
