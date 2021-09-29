// scene.h
#ifndef SCENE_H
#define SCENE_H


#include "common.h"
#include "player.h"
#include "traps.h"
#include "map.h"

void scene_init(t_game* game);
void scene_prepare(t_game* game);
void scene_draw(t_game* game);
void scene_present(t_game* game);
void scene_logic(t_game* game);
void scene_free(t_game* game);


#endif

