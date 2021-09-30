// defs.c :: Ivan Ryzhenko 2021
#ifndef DEFS_H
#define DEFS_H

#define GAME_TITLE "Game"
#define PLAYER_SPEED 4

#define MAP_WIDTH 20
#define MAP_HEIGHT 12

#define MAX_FILENAME_LENGTH 256

#define TILE_SIZE 16
#define TILE_SCALE 4

#define TILE_GROUND 0
#define TILE_HOLE 1
#define TILE_WALL 11
#define TILE_WALL_FRONT 12

#define SCREEN_WIDTH   MAP_WIDTH * TILE_SIZE * TILE_SCALE
#define SCREEN_HEIGHT  MAP_HEIGHT * TILE_SIZE * TILE_SCALE


#endif
