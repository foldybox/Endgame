// map.c

#include "map.h"

void map_init(t_game *game, int oX, int oY) {
	game->map.offset.x = oX;
	game->map.offset.y = oY;

	srand(141);

	int x, y;
	for (x = 0; x < MAP_WIDTH; x++) {
		for (y = 0; y < MAP_HEIGHT; y++) {
			game->map.data[x][y] = TILE_GROUND;

			if (rand() % 25 == 0)
			{
				game->map.data[x][y] = TILE_HOLE;
			}

			if (rand() % 30 == 0)
			{
				game->map.data[x][y] = TILE_WALL;
			}
		}
	}
	for (x = 0; x < MAP_WIDTH; x++) {
		game->map.data[x][MAP_HEIGHT - 1] = TILE_WALL_FRONT;
	}
}

void map_draw(t_game* game) {
	int x, y, n;

	for (y = 0; y < MAP_HEIGHT; y++)
	{
		for (x = 0; x < MAP_WIDTH; x++)
		{
			n = game->map.data[x][y];
			t_tile tile = set_tile(0, 0);

			if (n == 0) {
				tile = set_tile(6, 0);
				blit_tile(game, tile, game->map.offset.x + x * TILE_SIZE * TILE_SCALE, game->map.offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
			else if (n == 1) {
				tile = set_tile(5, 0);
				blit_tile(game, tile, game->map.offset.x + x * TILE_SIZE * TILE_SCALE, game->map.offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
			else if (n == 11) {
				tile = set_tile(5, 6);
				blit_tile(game, tile, game->map.offset.x + x * TILE_SIZE * TILE_SCALE, game->map.offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
		}
	}
}

void map_draw_front(t_game* game) {
	int x, y, n;

	for (y = 0; y < MAP_HEIGHT; y++)
	{
		for (x = 0; x < MAP_WIDTH; x++)
		{
			n = game->map.data[x][y];

			if (n == 12) {
				t_tile tile = set_tile(5, 7);
				blit_tile(game, tile, game->map.offset.x + x * TILE_SIZE * TILE_SCALE, game->map.offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
		}
	}
}
