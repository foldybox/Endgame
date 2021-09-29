// map.c

#include "map.h"

void map_init(t_game *game, char *filename) {
	FILE *map_file = fopen(filename, "r");
	if (map_file == NULL) exit(-1);
    
	t_map *map = (t_map *) malloc(sizeof(t_map));
	if (map == NULL) exit(-1);

	fscanf(map_file, "%d", &map->size.x);
	fscanf(map_file, "%d", &map->size.y);

	fscanf(map_file, "%d", &map->offset.x);
	fscanf(map_file, "%d", &map->offset.y);

	map->data = (int **) malloc(map->size.x * sizeof(int *));
	if (map->data == NULL) exit(-1);
	for (int i = 0; i < map->size.x; i++) {
		map->data[i] = (int *) malloc(map->size.y * sizeof(int));
		if (map->data[i] == NULL) exit(-1);
	}
	
    for (int i = 0; i < map->size.y; i++) {
		for (int j = 0; j < map->size.x; j++) {
			if(feof(map_file)) exit(1);
			fscanf(map_file, "%d", &map->data[j][i]);
		}
	}

    fclose(map_file);

	game->map = map;

	// game->map = (t_map *) malloc(sizeof(t_map));
	// game->map->size.x = MAP_WIDTH;
	// game->map->size.y = MAP_HEIGHT;
	// game->map->offset.x = 0;
	// game->map->offset.y = 0;

	// game->map->data = (int **) malloc(game->map->size.x * sizeof(int *));
	// if (game->map->data == NULL) exit(-1);
	// for (int i = 0; i < game->map->size.x; i++) {
	// 	game->map->data[i] = (int *) malloc(game->map->size.y * sizeof(int));
	// 	if (game->map->data[i] == NULL) exit(-1);
	// }


	// srand(141);

	// int x, y;
	// for (x = 0; x < MAP_WIDTH; x++) {
	// 	for (y = 0; y < MAP_HEIGHT; y++) {
	// 		game->map->data[x][y] = TILE_GROUND;

	// 		if (rand() % 25 == 0)
	// 		{
	// 			game->map->data[x][y] = TILE_HOLE;
	// 		}

	// 		if (rand() % 30 == 0)
	// 		{
	// 			game->map->data[x][y] = TILE_WALL;
	// 		}
	// 	}
	// }
	// for (x = 0; x < MAP_WIDTH; x++) {
	// 	game->map->data[x][MAP_HEIGHT - 1] = TILE_WALL_FRONT;
	// }
}

void map_draw(t_game* game) {
	int x, y, n;

	for (y = 0; y < game->map->size.y; y++)
	{
		for (x = 0; x < game->map->size.x; x++)
		{
			n = game->map->data[x][y];
			t_tile tile = set_tile(0, 0);

			if (n == 0) {
				tile = set_tile(6, 0);
				blit_tile(game, tile, game->map->offset.x + x * TILE_SIZE * TILE_SCALE, game->map->offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
			else if (n == 1) {
				tile = set_tile(5, 0);
				blit_tile(game, tile, game->map->offset.x + x * TILE_SIZE * TILE_SCALE, game->map->offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
			else if (n == 11) {
				tile = set_tile(5, 6);
				blit_tile(game, tile, game->map->offset.x + x * TILE_SIZE * TILE_SCALE, game->map->offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
		}
	}
}

void map_draw_front(t_game* game) {
	int x, y, n;

	for (y = 0; y < game->map->size.y; y++)
	{
		for (x = 0; x < game->map->size.x; x++)
		{
			n = game->map->data[x][y];

			if (n == 12) {
				t_tile tile = set_tile(5, 7);
				blit_tile(game, tile, game->map->offset.x + x * TILE_SIZE * TILE_SCALE, game->map->offset.y + y * TILE_SIZE * TILE_SCALE, false);
			}
		}
	}
}
