// structs.c
#ifndef STRUCTS_H
#define STRUCTS_H


#include <SDL2/SDL.h>

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
	int dx;
	int dy;
	int health;
	SDL_Texture *texture;
} t_entity;

typedef struct s_game {
	SDL_Renderer *renderer;
	SDL_Window *window;
	t_control control;
} t_game;


#endif
