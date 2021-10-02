// scene.c

#include "scene.h"

void scene_init(t_game *game) {
	player_init(game, 17, 113);
	door_add(game, "front_door", set_tile(10, 0), set_tile(9, 0), 17, 10, true, ITEM_NOTSET, false);
	door_add(game, "locked_door", set_tile(-1, -1), set_tile(-1, -1), 18, 16, true, ITEM_NULL, true);
	door_add(game, "locked_door", set_tile(10, 0), set_tile(9, 0), 17, 111, true, ITEM_NULL, false);

	item_add(game, set_tile(2, 3), 23, 14, ITEM_PAINT, true);
	item_add(game, set_tile(3, 3), 9, 3, ITEM_KEY, true);
  
  	trap_add(game, set_tile(3, 14), set_tile(4, 14), 17, 4, 17, 4, TRAP_TRIGGER, 0);
	trap_add(game, set_tile(4, 14), set_tile(4, 14), 19, 4, 19, 4, TRAP_TRIGGER, 0);
	trap_add(game, set_tile(3, 14), set_tile(4, 14), 20, 4, 24, 5, TRAP_GLIMMER, 500);

	object_add(game, "stone", set_tile(2, 4), set_tile(1, 4), 26, 4, false, ITEM_KEY, 3000);

	npc_add(game, "general", set_tile(1, 11), 17, 16, true);
	npc_add(game, "scientist", set_tile(0, 11), 26, 2, false);

	message_add(entity_by_slag(game, "general"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 0);
	message_add(entity_by_slag(game, "general"), "Bill", "Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English.", 0);

	message_add(entity_by_slag(game, "general"), "Bill", "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old.", 1);
	message_add(entity_by_slag(game, "general"), "Dev", "Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem.", 1);

	message_add(entity_by_slag(game, "scientist"), "Bill", "Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero.", 0);
	message_add(entity_by_slag(game, "scientist"), "David", "All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet.", 0);

	map_init(game, "resource/maps/map.csv");

	tileset_init(game, "resource/sprites/tileset.png");
	death_init(game);

	questsys_init(game);
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

	message_draw(game);

	death_draw(game);
}

void scene_present(t_game* game) {
	SDL_RenderPresent(game->renderer);
}

void scene_logic(t_game* game) {
	entity_logic(game);
	trap_logic(game);
	death_logic(game);
	sound_logic(game);
	questsys_logic(game);
}

void scene_free(t_game* game) {
  trap_free(game);
	entity_free(game);
	tileset_free(game);
	death_free(game);
}
