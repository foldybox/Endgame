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
	bool is_pressed_recently;
} t_control;

typedef struct s_animation {
	t_tile *tile;
	t_tile tileset;
	int tileset_size;
	int duration;
	int current_tile;
	unsigned int timer_start;
	//bool pass_first;
} t_animation;

typedef struct s_entity {
	int x;
	int y;
	int w;
	int h;
	t_tile tile;
	t_entity_type type;
	t_animation animation;
	t_facing facing;
	struct s_entity *next;
	void *data;
	t_item items[8];
} t_entity;

typedef struct s_entdata_door {
	bool is_open;
	bool is_locked;
	t_item required_item;
	t_tile open;
	t_tile close;
} t_entdata_door;

typedef struct s_entdata_item {
	bool is_active;
	bool is_picked_up;
	t_item item;
} t_entdata_item;

typedef struct s_map {
	int **data;
	SDL_Point offset;
	SDL_Point size;
} t_map;

typedef struct s_game {
	SDL_Renderer *renderer;
	SDL_Window *window;
	t_control control;
	SDL_Texture *tileset;
	t_map *map;
	t_entity *player;
	t_entity *entities;
	bool is_started;
	SDL_Point scene_offset;
} t_game;

#endif
