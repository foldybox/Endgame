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
//Common things
#define TILE_GROUND 0

//Labs assets
#define TILE_LAB_LEFT_CORNER_UP 13
#define TILE_LAB_LEFT_CORNER_DOWN 14
#define TILE_LAB_RIGHT_CORNER_UP 16
#define TILE_LAB_RIGHT_CORNER_DOWN 17
#define TILE_LAB_FLOOR 18
#define TILE_LAB_WALL_FRONT 19
#define TILE_LAB_WALL 20
#define TILE_LAB_WALL_LINER_LEFT 21
#define TILE_LAB_WALL_LINER_RIGHT 22
//First level assets(military base)
#define TILE_MIL_LEFT_CORNER_UP 23
#define TILE_MIL_LEFT_CORNER_DOWN 24
#define TILE_MIL_RIGHT_CORNER_UP 25
#define TILE_MIL_RIGHT_CORNER_DOWN 26
#define TILE_MIL_FLOOR 27
#define TILE_MIL_WALL_FRONT 28
#define TILE_MIL_WALL 29
#define TILE_MIL_WALL_LINER_LEFT 31
#define TILE_MIL_WALL_LINER_RIGHT 32

#define TILE_WALL 11

#define TILE_WALL_FRONT 99

#define TILE_MILL_ROOF 33


#define SCREEN_WIDTH   MAP_WIDTH * TILE_SIZE * TILE_SCALE
#define SCREEN_HEIGHT  MAP_HEIGHT * TILE_SIZE * TILE_SCALE

#endif
