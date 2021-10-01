// player.c

#include "player.h"

void player_init(t_game *game, int x, int y) {
    t_entity *player = entity_add(game, ENTYPE_PLAYER, x, y, set_tile(4, 3), FACING_RIGHT);
	player->animation = animation_init(&player->tile, set_tile(4, 3), 1, 150);
	for (int i = 0; i < 8; i++) {
		player->items[i] = 0;
	}
	
    game->player = player;
}

void player_use_door(t_game *game, t_entity *door) {
	int gX = game->player->x / (TILE_SIZE * TILE_SCALE);
	int gY = game->player->y / (TILE_SIZE * TILE_SCALE);
	//printf("p[%d:%d]\te[%d:%d]\n", gX, gY, door->x, door->y);
	if ((door->x - 1 <= gX) && (gX <= door->x + 1) &&
		(door->y - 1 <= gY) && (gY <= door->y + 1)) {
		for (int i = 0; i < 8; i++) {
			//printf("item[%d]: %d\t%d\n", i, game->player->items[i], ((t_entdata_door *) door->data)->required_item);
			if ((game->player->items[i] == ((t_entdata_door *) door->data)->required_item) || (((t_entdata_door *) door->data)->required_item == ITEM_NOTSET)) {
				((t_entdata_door *) door->data)->is_locked = false;
				break;
			}
		}
	}
}

void player_use_item(t_game *game, t_entity *item) {
	int gX = game->player->x / (TILE_SIZE * TILE_SCALE);
	int gY = game->player->y / (TILE_SIZE * TILE_SCALE);

	if ((item->x - 1 <= gX) && (gX <= item->x + 1) &&
		(item->y - 1 <= gY) && (gY <= item->y + 1) && 
		((t_entdata_item *) item->data)->is_picked_up == false) {
		for (int i = 0; i < 8; i++) {
			if (game->player->items[i] == 0) {
				game->player->items[i] = ((t_entdata_item *) item->data)->item;
				((t_entdata_item *) item->data)->is_picked_up = true;
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
			if ((entity->x == gX && entity->y == gY) && ((t_entdata_door *)entity->data)->is_locked) return;
			if (game->control.use) player_use_door(game, entity);
			break;
		
		case ENTYPE_ITEM:
			//if ((entity->x == gX && entity->y == gY) && !((t_entdata_item *)entity->data)->is_picked_up) return;
			if (game->control.use) player_use_item(game, entity);
			break;
		
		default:
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

	if ((game->control.left || game->control.right || game->control.up || game->control.down) && !game->control.is_pressed_recently) {
		if (game->player->facing == FACING_LEFT) {
			game->player->animation = animation_init(&game->player->tile, set_tile(4, 4), 4, 150);
		}
		else if (game->player->facing == FACING_RIGHT) {
			game->player->animation = animation_init(&game->player->tile, set_tile(4, 3), 4, 150);
		}
		else {
			game->player->animation = animation_init(&game->player->tile, set_tile(4, 3), 1, 150);
		}
	}

	if (!game->control.left && !game->control.right && !game->control.up && !game->control.down) {
		if (game->player->facing == FACING_LEFT) {
			game->player->animation = animation_init(&game->player->tile, set_tile(4, 4), 1, 150);
		}
		else if (game->player->facing == FACING_RIGHT) {
			game->player->animation = animation_init(&game->player->tile, set_tile(4, 3), 1, 150);
		}
	}

	if (game->control.left || game->control.right || game->control.up || game->control.down) {
		game->control.is_pressed_recently = true;
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

	animate(&game->player->animation);

	blit_tile(game, game->player->tile, SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2, ANCHOR_BOTTOM_CENTER);
}

void player_free(t_game *game) {
    free(game->player);
	game->player = NULL;
}
