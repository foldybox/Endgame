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
	bool is_death;
	t_tile tile;
	t_facing facing;
} t_entity;

typedef struct s_traps {
    int x1;
    int y1;
	int x2;
    int y2;
	int delay;
	unsigned int timer;
    bool activated;
	t_tile tile;
	t_trap_type trap_type;
	struct s_traps *next;
} t_traps;

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
	t_traps *trap;
	bool is_started;
} t_game;


#endif
