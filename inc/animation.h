// animation.h
#ifndef ANIMATION_H
#define ANIMATION_H

#include "common.h"
#include "tileset.h"

t_animation animation_init(t_tile *tile, t_tile tileset, int tileset_size, int duration);
t_animation animation_set(t_animation *anim);
void animate(t_animation *anim);

#endif
