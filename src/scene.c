// scene.c

#include "scene.h"

void scene_init(t_game *game) {
	player_init(game, 17 * (TILE_SIZE * TILE_SCALE), 1 * (TILE_SIZE * TILE_SCALE));
	door_add(game, set_tile(10, 0), set_tile(9, 0), 17, 4, true, ITEM_NOTSET);
	door_add(game, set_tile(12, 4), set_tile(11, 4), 14, 3, true, ITEM_PAINT);

	item_add(game, set_tile(2, 3), 20, 5, ITEM_PAINT, true);
	item_add(game, set_tile(3, 3), 9, 3, ITEM_KEY, true);

	map_init(game, "assets/maps/map.csv");

	tileset_init(game, "assets/sprites/tileset2.png");
}

void scene_prepare(t_game* game) {
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
	SDL_RenderClear(game->renderer);
}

void scene_draw(t_game* game) {
	map_draw(game);
	entity_draw(game);
	map_draw_front(game);
}

void scene_present(t_game* game) {
	SDL_RenderPresent(game->renderer);
}

void scene_logic(t_game* game) {
	entity_logic(game);
}

void scene_free(t_game* game) {
	entity_free(game);
	tileset_free(game);
}
