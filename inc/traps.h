// traps.h
#ifndef TRAPS_H
#define TRAPS_H

#include "common.h"
#include "draw.h"
#include "tileset.h"

void trap_add(t_game * game, t_trap_type type, int x1, int y1, int x2, int y2);
void trap_init(t_game* game);
void trap_draw(t_game* game);
void trap_logic(t_game* game);
void trap_free(t_game* game);
void trap_trigger(t_game *game, t_traps *current);
void trap_glimmer(t_game *game, t_traps *current);

#endif
