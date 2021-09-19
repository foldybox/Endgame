// draw.c

#include "draw.h"

void scene_prepare(Game *game) {
	SDL_SetRenderDrawColor(game->renderer, 76, 0, 255, 255);
	SDL_RenderClear(game->renderer);
}

void scene_present(Game *game) {
	SDL_RenderPresent(game->renderer);
}

SDL_Texture *loadTexture(Game *game, char *filename) {
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(game->renderer, filename);

	return texture;
}

void blit(Game *game, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(game->renderer, texture, NULL, &dest);
}
