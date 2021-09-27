// draw.c

#include "draw.h"

SDL_Texture *loadTexture(t_game *game, char *filename) {
	SDL_Texture *texture;

	texture = IMG_LoadTexture(game->renderer, filename);

	return texture;
}

void blit(t_game *game, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(game->renderer, texture, NULL, &dest);
}
