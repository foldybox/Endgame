// scene.c

#include "scene.h"

void scene_init(t_game *game) {
	death_init(game);
	
	player_init(game, 0, 0);

	trap_init(game);

	map_init(game, 0, 0);

	tileset_init(game, "assets/sprites/tileset.png");
}

void scene_prepare(t_game* game) {
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
	SDL_RenderClear(game->renderer);
}

void scene_draw(t_game* game) {
	map_draw(game);
	trap_draw(game);
	player_draw(game);
	map_draw_front(game);
	death_draw(game, "assets/sprites/death.jpeg");
}

void scene_present(t_game* game) {
	SDL_RenderPresent(game->renderer);
}

void scene_logic(t_game* game) {
	death_logic(game);
	player_logic(game);
	trap_logic(game);
}

void scene_free(t_game* game) {
	trap_free(game);
	player_free(game);
	tileset_free(game);
	death_free(game);
}
