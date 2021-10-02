// scene.c

#include "scene.h"

void scene_init(t_game *game) {
	player_init(game, 17 * (TILE_SIZE * TILE_SCALE), 1 * (TILE_SIZE * TILE_SCALE));
	door_add(game, set_tile(10, 0), set_tile(9, 0), 17, 10, true, ITEM_NOTSET);
	door_add(game, set_tile(12, 5), set_tile(11, 5), 19, 15, true, ITEM_KEY);

	item_add(game, set_tile(2, 3), 23, 14, ITEM_PAINT, true);
	item_add(game, set_tile(3, 3), 9, 3, ITEM_KEY, true);
  
  	trap_add(game, set_tile(2, 4), 17, 4, 18, 4, TRAP_TRIGGER, 0);
	trap_add(game, set_tile(2, 4), 20, 4, 24, 5, TRAP_GLIMMER, 500);

	object_add(game, set_tile(2, 4), set_tile(1, 4), 26, 4, true, ITEM_KEY, 3000);

	npc_add(game, set_tile(0, 11), 2, 2, true);

	map_init(game, "assets/maps/map.csv");

	tileset_init(game, "assets/sprites/tileset.png");
	death_init(game);
}

void scene_prepare(t_game* game) {
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
	SDL_RenderClear(game->renderer);
}

void scene_draw(t_game* game) {
	map_draw(game);
	trap_draw(game);
	entity_draw(game);
	
	char coords[16];
	sprintf(coords, "x: %d    y:%d", game->player->x / (TILE_SCALE * TILE_SIZE), game->player->y / (TILE_SCALE * TILE_SIZE));
	text_draw(game, coords, 10, 10, 24, ANCHOR_TOP_LEFT);

	death_draw(game, "assets/sprites/death.jpeg");
}

void scene_present(t_game* game) {
	SDL_RenderPresent(game->renderer);
}

void scene_logic(t_game* game) {
	entity_logic(game);
	trap_logic(game);
	death_logic(game);
}

void scene_free(t_game* game) {
  trap_free(game);
	entity_free(game);
	tileset_free(game);
	death_free(game);
}
