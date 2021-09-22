// structs.c
#ifndef STRUCTS_H
#define STRUCTS_H


#include <SDL2/SDL.h>

typedef struct {
	int up;
	int down;
	int left;
	int right;
	int use;
} Control;

typedef struct {
	int x;
	int y;
	int dx;
	int dy;
	int health;
	SDL_Texture *texture;
} Entity;

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	Control control;
} Game;


#endif
