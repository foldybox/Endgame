// draw.h
#ifndef DRAW_H
#define DRAW_H


#include "common.h"
#include "SDL2/SDL_image.h"

void scene_prepare(Game *game);
void scene_present(Game *game);

SDL_Texture *loadTexture(Game *game, char *filename);
void blit(Game *game, SDL_Texture *texture, int x, int y);


#endif
