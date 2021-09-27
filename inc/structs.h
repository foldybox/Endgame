// structs.c
#ifndef STRUCTS_H
#define STRUCTS_H


#include <SDL2/SDL.h>
#include "defs.h"
#include "enums.h"

typedef SDL_Rect t_tile;

typedef struct s_control {
	int up;
	int down;
	int left;
	int right;
	int use;
} t_control;

typedef struct s_entity {
	int x;
	int y;
	int w;
	int h;
	t_tile tile;
	t_facing facing;
} t_entity;

typedef struct s_map {
	int data[MAP_WIDTH][MAP_HEIGHT];
	SDL_Point offset;
} t_map;

typedef struct s_game {
	SDL_Renderer *renderer;
	SDL_Window *window;
	t_control control;
	SDL_Texture *tileset;
	t_map map;
	t_entity *player;
	bool is_started;
} t_game;

#endif
