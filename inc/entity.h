// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"
#include "animation.h"
#include "player.h"
#include "door.h"
#include "item.h"

t_entity *entity_add(t_game *game, t_entity_type type, int x, int y, t_tile tile, t_facing facing);
void entity_logic(t_game *game);
void entity_draw(t_game *game);
void entity_free(t_game *game);

#endif
