// player.c

#include "player.h"

void player_init(t_game *game, int x, int y) {
    t_entity *player = (t_entity *) malloc(sizeof(t_entity));
    if (player == NULL) exit(-1);

    memset(player, 0, sizeof(t_entity));

	player->x = x;
	player->y = y;
    player->tile = set_tile(4, 3);

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

	if (game->map->data[gX][gY] <= 10) {
		game->player->x = x;
		game->player->y = y;
	}
}

void player_logic(t_game *game) {
	player_move(game);

	if (game->control.left && !game->control.right) {
		game->player->facing = FACING_LEFT;
	}
	else if (!game->control.left && game->control.right) {
		game->player->facing = FACING_RIGHT;
	}
}

void player_draw(t_game *game) {
	double pX = 0, pY = 0;

	pX = game->player->x;
	pY = game->player->y;

	if (game->player->facing == FACING_LEFT) {
		game->player->tile = set_tile(4, 4);
	}
	else if (game->player->facing == FACING_RIGHT) {
		game->player->tile = set_tile(4, 3);
	}

	blit_tile(game, game->player->tile, pX, pY, true);
}

void player_free(t_game *game) {
    free(game->player);
	game->player = NULL;
}
