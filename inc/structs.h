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
	int start;
	bool is_locked;
} t_control;

typedef struct s_animation {
	t_tile *tile;
	t_tile tileset;
	int id;
	int tileset_size;
	int duration;
	int current_tile;
	unsigned int timer_start;
	struct s_animation *next;
	bool is_playing;
	bool is_repeated;
} t_animation;

typedef struct s_entity {
	int x;
	int y;
	int w;
	int h;
	bool is_death;
	t_tile tile;
	t_entity_type type;
	t_animation *animations;
	t_facing facing;
	struct s_entity *next;
	void *data;
	t_item items[8];
	struct s_entity *usable;
} t_entity;

typedef struct s_map {
	int **data;
	SDL_Point offset;
	SDL_Point size;
} t_map;

typedef struct s_trap {
    int x1;
    int y1;
	int x2;
    int y2;
	int delay;
	unsigned int timer;
    bool activated;
	t_tile tile;
	t_trap_type type;
	struct s_trap *next;
} t_trap;

typedef struct s_game {
	SDL_Renderer *renderer;
	SDL_Window *window;
	t_control control;
	SDL_Texture *tileset;
	SDL_Point *spawn;
	t_map *map;
	t_entity *player;
	t_trap *traps;
	bool is_started;
	unsigned int death_timer;
	bool game_over_screen;
	t_entity *entities;
	SDL_Point scene_offset;
} t_game;

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

typedef struct s_entdata_object {
	bool is_active;
	bool is_used;
	bool is_using;
	bool is_obstacle;
	unsigned int timer;
	int delay;
	t_tile start_tile;
	t_tile finish_tile;
	t_item required_item;
	//void (* logic)(t_game *game, t_entity *entity);
} t_entdata_object;


#endif
