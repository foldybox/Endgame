// tileset.c

#include "tileset.h"

void tileset_init(t_game* game, char *filename) {
	game->tileset = IMG_LoadTexture(game->renderer, filename);
}

void blit_tile(t_game* game, t_tile tile, int x, int y, bool is_centered) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = TILE_SIZE * TILE_SCALE;
	dest.h = TILE_SIZE * TILE_SCALE;

	if (is_centered) {
		dest.x -= (dest.w / 2);
		dest.y -= (dest.h / 2);
	}

	SDL_RenderCopy(game->renderer, game->tileset, &tile, &dest);
}

t_tile set_tile(int x, int y) {
	t_tile tile;

	tile.x = x * TILE_SIZE;
	tile.y = y * TILE_SIZE;
	tile.w = TILE_SIZE;
	tile.h = TILE_SIZE;

	return tile;
}

void tileset_free(t_game* game) {
	free(game->tileset);
	game->tileset = NULL;
}