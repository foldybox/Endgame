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
}

void map_draw(t_game* game) {
	int x, y, n;

	for (y = 0; y < game->map->size.y; y++) {
		for (x = 0; x < game->map->size.x; x++) {
			n = game->map->data[x][y];
			t_tile tile = set_tile(0, 0);
			switch (n) {
      
			case TILE_GROUND:
				tile = set_tile(6, 0);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE,  ANCHOR_TOP_LEFT);
				break;
			case TILE_WALL:
				tile = set_tile(11, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
     //*********LAB Location sprite*******
			case TILE_WALL_FRONT:
				tile = set_tile(9,7);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_LAB_LEFT_CORNER_UP :
				tile = set_tile(8, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_LAB_RIGHT_CORNER_DOWN:
				tile = set_tile(10, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_RIGHT_CORNER_UP:
				tile = set_tile(10, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_LAB_WALL:
				tile = set_tile(9, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_WALL_FRONT :
				tile = set_tile(9, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_FLOOR :
				tile = set_tile(9, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_WALL_LINER_LEFT:
				tile = set_tile(8, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_WALL_LINER_RIGHT:
				tile = set_tile(10, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			
			case TILE_LAB_LEFT_CORNER_DOWN :
				tile = set_tile(8, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
	//********MIL location sprite*********
			case TILE_MIL_LEFT_CORNER_UP :
				tile = set_tile(10, 6);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_MIL_RIGHT_CORNER_DOWN:
				tile = set_tile(10, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_RIGHT_CORNER_UP:
				tile = set_tile(10, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_MIL_WALL:
				tile = set_tile(11, 6);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_WALL_FRONT :
				tile = set_tile(9, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_FLOOR :
				tile = set_tile(9, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_WALL_LINER_LEFT:
				tile = set_tile(10,7);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_WALL_LINER_RIGHT:
				tile = set_tile(12, 7);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			
			case TILE_MIL_LEFT_CORNER_DOWN :
				tile = set_tile(9, 8);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;	

			case TILE_MILL_ROOF :
				tile = set_tile(11, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;	
			default:
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			}
		}
	}
}

void map_draw_front(t_game* game) {
int x, y, n;

	for (y = 0; y < game->map->size.y; y++) {
		for (x = 0; x < game->map->size.x; x++) {
			n = game->map->data[x][y];
			t_tile tile = set_tile(0, 0);
			switch (n) {
      
			case TILE_WALL:
				tile = set_tile(11, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
     //*********LAB Location sprite*******
			case TILE_WALL_FRONT:
				tile = set_tile(9,7);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_LAB_LEFT_CORNER_UP :
				tile = set_tile(8, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_LAB_RIGHT_CORNER_DOWN:
				tile = set_tile(10, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_RIGHT_CORNER_UP:
				tile = set_tile(10, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_LAB_WALL:
				tile = set_tile(9, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_WALL_FRONT :
				tile = set_tile(9, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_FLOOR :
				tile = set_tile(9, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_WALL_LINER_LEFT:
				tile = set_tile(8, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_LAB_WALL_LINER_RIGHT:
				tile = set_tile(10, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			
			case TILE_LAB_LEFT_CORNER_DOWN :
				tile = set_tile(8, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
	//********MIL location sprite*********
			case TILE_MIL_LEFT_CORNER_UP :
				tile = set_tile(10, 6);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_MIL_RIGHT_CORNER_DOWN:
				tile = set_tile(10, 5);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_RIGHT_CORNER_UP:
				tile = set_tile(10, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;

			case TILE_MIL_WALL:
				tile = set_tile(11, 6);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_WALL_FRONT :
				tile = set_tile(9, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_FLOOR :
				tile = set_tile(9, 4);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_WALL_LINER_LEFT:
				tile = set_tile(10,7);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			case TILE_MIL_WALL_LINER_RIGHT:
				tile = set_tile(12, 7);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			
			case TILE_MIL_LEFT_CORNER_DOWN :
				tile = set_tile(9, 8);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;	

			case TILE_MILL_ROOF :
				tile = set_tile(11, 3);
				blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;	
			default:
				//blit_tile(game, tile, game->scene_offset.x + x * TILE_SIZE * TILE_SCALE, game->scene_offset.y + y * TILE_SIZE * TILE_SCALE - TILE_SCALE, ANCHOR_TOP_LEFT);
				break;
			}
		}
	}
}
