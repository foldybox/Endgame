// animation.c

#include "animation.h"

t_animation animation_init(t_tile *tile, t_tile tileset, int tileset_size, int duration) {
    t_animation anim;

    anim.tile = tile;
    anim.tileset = tileset;
    anim.tileset_size = tileset_size;
    anim.duration = duration;
    anim.current_tile = 0;
    anim.timer_start = 0;

    return anim;
}

t_animation animation_set(t_animation *anim) {
    anim->current_tile = 0;
    anim->timer_start = 0;

    return *anim;
}

void animate(t_animation *anim) {
    if (anim->timer_start == 0) {
        anim->timer_start = SDL_GetTicks();
        *anim->tile = set_tile(anim->tileset.x / TILE_SIZE + anim->current_tile, anim->tileset.y / TILE_SIZE);
        anim->current_tile++;
        return;
    }

    if (SDL_GetTicks() > anim->timer_start + anim->duration) {
        if (anim->current_tile >= anim->tileset_size) anim->current_tile = 0;

        *anim->tile = set_tile(anim->tileset.x / TILE_SIZE + anim->current_tile, anim->tileset.y / TILE_SIZE);
        anim->current_tile++;
        anim->timer_start = SDL_GetTicks();
    }
}
