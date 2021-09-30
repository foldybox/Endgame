// scene.c

#include "scene.h"

void scene_init(t_game *game) {
	player_init(game, 17 * (TILE_SIZE * TILE_SCALE), 1 * (TILE_SIZE * TILE_SCALE));

	map_init(game, "assets/maps/map2.csv");

	tileset_init(game, "assets/sprites/tileset.png");
}

void scene_prepare(t_game* game) {
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
	SDL_RenderClear(game->renderer);
}

void scene_draw(t_game* game) {
	map_draw(game);
	player_draw(game);
	map_draw_front(game);
}

void scene_present(t_game* game) {
	SDL_RenderPresent(game->renderer);
}

void scene_logic(t_game* game) {
	player_logic(game);
}

void scene_free(t_game* game) {
	player_free(game);
	tileset_free(game);
}
