// scene.c

#include "scene.h"

void scene_init(t_game *game) {
	player_init(game, 17, 113);
	door_add(game, "front_door", set_tile(10, 0), set_tile(9, 0), 17, 10, true, ITEM_NOTSET, false);

	item_add(game, set_tile(2, 13), 23, 6, ITEM_PAINT, true);

	// Level 00
	npc_add(game, "real_general", set_tile(1, 11), 14, 112, true);
	npc_add(game, "real_scientist", set_tile(0, 11), 7, 116, false);
	object_add(game, "chair_of_vr0", set_tile(1, 14), set_tile(0, 14), 7, 117, false, ITEM_NOTSET, 1000, true);
	object_add(game, "chair_of_vr_main", set_tile(0, 14), set_tile(1, 14), 7, 118, false, ITEM_NOTSET, 1000, true);
	object_add(game, "chair_of_vr1", set_tile(1, 14), set_tile(0, 14), 7, 119, false, ITEM_NOTSET, 1000, true);
	object_add(game, "chair_of_vr2", set_tile(1, 14), set_tile(0, 14), 7, 120, false, ITEM_NOTSET, 1000, true);
	object_add(game, "computer0", set_tile(5, 14), set_tile(5, 14), 8, 116, false, ITEM_NOTSET, 1000, true);
	object_add(game, "computer1", set_tile(5, 14), set_tile(5, 14), 9, 116, false, ITEM_NOTSET, 1000, true);
	object_add(game, "computer2", set_tile(5, 14), set_tile(5, 14), 10, 116, false, ITEM_NOTSET, 1000, true);
	door_add(game, "locked_door", set_tile(10, 0), set_tile(9, 0), 17, 111, true, ITEM_NULL, false);

	message_add(entity_by_slag(game, "real_general"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 0);
	message_add(entity_by_slag(game, "real_general"), "Bill", "Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English.", 0);
	message_add(entity_by_slag(game, "real_general"), "Bill", "Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English.", 1);

	message_add(entity_by_slag(game, "real_scientist"), "Bill", "Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero.", 0);
	message_add(entity_by_slag(game, "real_scientist"), "David", "All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet.", 0);


	// Level 01
	npc_add(game, "virtual_general", set_tile(1, 11), 28, 35, false);
	npc_add(game, "virtual_guard", set_tile(4, 11), 18, 16, true);
	npc_add(game, "virtual_sarge", set_tile(5, 11), 10, 1, false);
	npc_add(game, "virtual_tumbleweed", set_tile(7, 12), 10, 112, true);
	object_add(game, "virtual_grass00", set_tile(3, 13), set_tile(4, 13), 2, 2, false, ITEM_PAINT, 1000, false);
	object_add(game, "virtual_grass01", set_tile(3, 13), set_tile(4, 13), 5, 7, false, ITEM_PAINT, 1000, false);
	object_add(game, "virtual_grass02", set_tile(3, 13), set_tile(4, 13), 9, 4, false, ITEM_PAINT, 1000, false);
	object_add(game, "virtual_grass03", set_tile(3, 13), set_tile(4, 13), 2, 5, false, ITEM_PAINT, 1000, false);
	object_add(game, "virtual_grass04", set_tile(3, 13), set_tile(4, 13), 5, 2, false, ITEM_PAINT, 1000, false);
	object_add(game, "virtual_potato00", set_tile(3, 13), set_tile(4, 13), 25, 12, false, ITEM_NOTSET, 1000, false);
	object_add(game, "virtual_potato01", set_tile(3, 13), set_tile(4, 13), 26, 14, false, ITEM_NOTSET, 1000, false);
	object_add(game, "virtual_potato02", set_tile(3, 13), set_tile(4, 13), 29, 13, false, ITEM_NOTSET, 1000, false);
	object_add(game, "portal0", set_tile(-1, -1), set_tile(-1, -1), 17, 1, false, ITEM_NOTSET, 1000, false);
	object_add(game, "portal1", set_tile(-1, -1), set_tile(-1, -1), 18, 1, false, ITEM_NOTSET, 1000, false);
	door_add(game, "mil_locked_door", set_tile(-1, -1), set_tile(-1, -1), 17, 16, true, ITEM_NULL, true);

	message_add(entity_by_slag(game, "virtual_guard"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 0);
	message_add(entity_by_slag(game, "virtual_guard"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 1);
	message_add(entity_by_slag(game, "virtual_guard"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 2);

	message_add(entity_by_slag(game, "virtual_general"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 0);
	message_add(entity_by_slag(game, "virtual_general"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 0);
	message_add(entity_by_slag(game, "virtual_general"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 1);

	message_add(entity_by_slag(game, "virtual_sarge"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 0);
	message_add(entity_by_slag(game, "virtual_sarge"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 1);
	message_add(entity_by_slag(game, "virtual_sarge"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 2);

	message_add(entity_by_slag(game, "virtual_tumbleweed"), "Dev", "hh", 0);
	message_add(entity_by_slag(game, "virtual_tumbleweed"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 1);
	message_add(entity_by_slag(game, "virtual_tumbleweed"), "Dev", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.", 2);




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
	questsys_logic(game);
	entity_logic(game);
	trap_logic(game);
	death_logic(game);
	sound_logic(game);
}

void scene_free(t_game* game) {
  trap_free(game);
	entity_free(game);
	tileset_free(game);
	death_free(game);
}
