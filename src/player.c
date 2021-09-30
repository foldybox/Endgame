// player.c

#include "player.h"

void player_init(t_game *game, int x, int y) {
    t_entity *player = (t_entity *) malloc(sizeof(t_entity));
    if (player == NULL) exit(-1);

    memset(player, 0, sizeof(t_entity));

	player->x = x;
	player->y = y;
    player->tile = set_tile(4, 3);
	player->animation = animation_init(&player->tile, set_tile(4, 3), 1, 150);

    game->player = player;
}

void player_move(t_game* game) {
	int x = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	bool is_pressed = false;

	if (game->control.up)
	{
		if (!is_pressed || game->control.down)
		{
			dy -= PLAYER_SPEED;
		}
		else
		{
			dy -= side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	if (game->control.down)
	{
		if (!is_pressed || game->control.up)
		{
			dy += PLAYER_SPEED;
		}
		else
		{
			dy += side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	if (game->control.left)
	{
		if (!is_pressed || game->control.right)
		{
			dx -= PLAYER_SPEED;
		}
		else
		{
			dx -= side_by_diagonal(PLAYER_SPEED);
		}
		is_pressed = true;
	}

	if (game->control.right)
	{
		if (!is_pressed || game->control.left)
		{
			dx += PLAYER_SPEED;
		}
		else
		{
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

	blit_tile(game, game->player->tile, SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2, BOTTOM_CENTER);
}

void player_free(t_game *game) {
    free(game->player);
	game->player = NULL;
}
