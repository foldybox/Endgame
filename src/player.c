// player.c

#include "player.h"

void player_init(t_game *game, int x, int y) {
    t_entity *player = entity_add(game, ENTYPE_PLAYER, x, y, set_tile(4, 3), FACING_RIGHT);
	for (int i = 0; i < 8; i++) {
		player->items[i] = 0;
	}

	animation_add(player, 0, set_tile(4, 5), 2, 300, true);
	animation_add(player, 1, set_tile(6, 5), 2, 300, true);
	animation_add(player, 2, set_tile(4, 3), 4, 150, true);
	animation_add(player, 3, set_tile(4, 4), 4, 150, true);
	animation_add(player, 4, set_tile(0, 10), 7, 150, false);
	
    game->player = player;
}

void player_use_door(t_game *game, t_entity *door) {
	//printf("p[%d:%d]\te[%d:%d]\n", gX, gY, door->x, door->y);
	for (int i = 0; i < 8; i++) {
		//printf("item[%d]: %d\t%d\n", i, game->player->items[i], ((t_entdata_door *) door->data)->required_item);
		if ((game->player->items[i] == ((t_entdata_door *) door->data)->required_item) || (((t_entdata_door *) door->data)->required_item == ITEM_NOTSET)) {
			((t_entdata_door *) door->data)->is_locked = false;
			game->is_door_sound = true;
			break;
		}
	}
}

void player_use_item(t_game *game, t_entity *item) {
	if (((t_entdata_item *) item->data)->is_picked_up == false) {
		for (int i = 0; i < 8; i++) {
			if (game->player->items[i] == 0) {
				game->player->items[i] = ((t_entdata_item *) item->data)->item;
				((t_entdata_item *) item->data)->is_picked_up = true;
				break;
			}
		}
	}
}

void player_use_object(t_game *game, t_entity *obj) {
	if (!((t_entdata_object *) obj->data)->is_used && ((t_entdata_object *) obj->data)->is_active) {
		for (int i = 0; i < 8; i++) {
			if ((game->player->items[i] == ((t_entdata_object *) obj->data)->required_item) || (((t_entdata_object *) obj->data)->required_item == ITEM_NOTSET)) {
				((t_entdata_object *) obj->data)->is_using = true;
				break;
			}
		}
	}
}

void player_move(t_game* game) {
	int x = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	bool is_pressed = false;

	if (game->control.up) {
		if (!is_pressed || game->control.down) {
			dy -= PLAYER_SPEED;
		}
		else {
			dy -= side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	if (game->control.down) {
		if (!is_pressed || game->control.up) {
			dy += PLAYER_SPEED;
		}
		else {
			dy += side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	if (game->control.left) {
		if (!is_pressed || game->control.right) {
			dx -= PLAYER_SPEED;
		}
		else {
			dx -= side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	if (game->control.right) {
		if (!is_pressed || game->control.left) {
			dx += PLAYER_SPEED;
		}
		else {
			dx += side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	x = game->player->x + dx;
	y = game->player->y + dy;

	if (x < 0) x = 0;
	if (y < 0) y = 0;

	int gX = x / (TILE_SIZE * TILE_SCALE);
	int gY = y / (TILE_SIZE * TILE_SCALE);

	if (game->map->data[gX][gY] >= 10) return;

	t_entity *entity = game->entities;
    while (entity != NULL) {
		switch (entity->type) {
		case ENTYPE_DOOR:
			if ((entity->x - 1 <= gX) && (gX <= entity->x + 1) && (entity->y - 1 <= gY) && (gY <= entity->y + 1)) {
				game->player->usable = entity;
				if (game->control.use) player_use_door(game, entity);
			}
			if ((entity->x == gX && entity->y == gY) && ((t_entdata_door *)entity->data)->is_locked) return;
			break;
		
		case ENTYPE_ITEM:
			if ((entity->x - 1 <= gX) && (gX <= entity->x + 1) && (entity->y - 1 <= gY) && (gY <= entity->y + 1)) {
				game->player->usable = entity;
				if (game->control.use) player_use_item(game, entity);
			}
			break;

		case ENTYPE_OBJECT:
			if ((entity->x - 1 <= gX) && (gX <= entity->x + 1) && (entity->y - 1 <= gY) && (gY <= entity->y + 1)) {
				game->player->usable = entity;
				if (game->control.use) player_use_object(game, entity);
			}
			if ((entity->x == gX && entity->y == gY) && ((t_entdata_object *)entity->data)->is_obstacle) return;
			break;
		
		default:
			game->player->usable = NULL;
			break;
		}
        entity = entity->next;
    }

	if (game->control.left && !game->control.right) {
		game->player->facing = FACING_LEFT;
	}
	else if (!game->control.left && game->control.right) {
		game->player->facing = FACING_RIGHT;
	}

	if (game->control.left || game->control.right || game->control.up || game->control.down) {
		if (game->player->facing == FACING_RIGHT) animation_play(game->player, 2, 1);
		else if (game->player->facing == FACING_LEFT) animation_play(game->player, 3, 1);
	}
	else {
		if (game->player->facing == FACING_RIGHT) animation_play(game->player, 0, 0);
		else if (game->player->facing == FACING_LEFT) animation_play(game->player, 1, 0);
	}

	game->player->x = x;
	game->player->y = y;
	
	game->scene_offset.x = SCREEN_WIDTH / 2 - game->player->x;
	game->scene_offset.y = SCREEN_HEIGHT / 2 - game->player->y;
}

void player_logic(t_game *game) {
	player_move(game);
}

void player_draw(t_game *game) {
	// if (game->player->facing == FACING_LEFT) {
	// 	game->player->animation = animation_init(&game->player->tile, set_tile(4, 4), 4, 150);
	// }
	// else if (game->player->facing == FACING_RIGHT) {
	// 	game->player->animation = animation_init(&player->tile, set_tile(4, 3), 4, 150);
	// }

	animate(game->player);

	blit_tile(game, game->player->tile, SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2, ANCHOR_BOTTOM_CENTER);

	if (game->player->usable != NULL) {
		switch (game->player->usable->type) {
			case ENTYPE_NPC:
				
				break;

			case ENTYPE_ITEM:
				if (!((t_entdata_item *) game->player->usable->data)->is_picked_up) {
					text_draw(game, "[F] PICK UP", game->scene_offset.x + game->player->usable->x * (TILE_SIZE * TILE_SCALE) + (TILE_SIZE * TILE_SCALE) / 2, game->scene_offset.y + game->player->usable->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, 24, ANCHOR_BOTTOM_CENTER);
				}
				break;

			case ENTYPE_DOOR:
				if (((t_entdata_door *) game->player->usable->data)->is_locked) {
					bool has_key = false;
					for (int i = 0; i < 8; i++) {
						if ((game->player->items[i] == ((t_entdata_door *) game->player->usable->data)->required_item) || (((t_entdata_door *) game->player->usable->data)->required_item == ITEM_NOTSET)) {
							has_key = true;
							break;
						}
					}
					if (has_key) {
						text_draw(game, "[F] OPEN", game->scene_offset.x + game->player->usable->x * (TILE_SIZE * TILE_SCALE) + (TILE_SIZE * TILE_SCALE) / 2, game->scene_offset.y + game->player->usable->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, 24, ANCHOR_BOTTOM_CENTER);
					}
					else {
						text_draw(game, "NEED A KEY", game->scene_offset.x + game->player->usable->x * (TILE_SIZE * TILE_SCALE) + (TILE_SIZE * TILE_SCALE) / 2, game->scene_offset.y + game->player->usable->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, 24, ANCHOR_BOTTOM_CENTER);
					}
				}
				break;

			case ENTYPE_OBJECT:
				if (!((t_entdata_object *) game->player->usable->data)->is_used) {
					if (((t_entdata_object *) game->player->usable->data)->is_using) {
						text_draw(game, "USING...", game->scene_offset.x + game->player->usable->x * (TILE_SIZE * TILE_SCALE) + (TILE_SIZE * TILE_SCALE) / 2, game->scene_offset.y + game->player->usable->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, 24, ANCHOR_BOTTOM_CENTER);
					}
					else {
						bool has_key = false;
						for (int i = 0; i < 8; i++) {
							if ((game->player->items[i] == ((t_entdata_object *) game->player->usable->data)->required_item) || (((t_entdata_object *) game->player->usable->data)->required_item == ITEM_NOTSET)) {
								has_key = true;
								break;
							}
						}
						if (has_key) {
							text_draw(game, "[F] USE", game->scene_offset.x + game->player->usable->x * (TILE_SIZE * TILE_SCALE) + (TILE_SIZE * TILE_SCALE) / 2, game->scene_offset.y + game->player->usable->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, 24, ANCHOR_BOTTOM_CENTER);
						}
						else {
							text_draw(game, "NEED SOMETHING", game->scene_offset.x + game->player->usable->x * (TILE_SIZE * TILE_SCALE) + (TILE_SIZE * TILE_SCALE) / 2, game->scene_offset.y + game->player->usable->y * (TILE_SIZE * TILE_SCALE) - TILE_SCALE, 24, ANCHOR_BOTTOM_CENTER);
						}
					}
				}
				break;
			
			default:
				break;
		}
	}
}

void player_free(t_game *game) {
    free(game->player);
	game->player = NULL;
}
