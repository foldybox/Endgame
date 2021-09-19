// structs.c :: Ivan Ryzhenko 2021
#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL.h>

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	int up;
	int down;
	int left;
	int right;
} Game;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Entity;


#endif
