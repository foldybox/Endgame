// input.h
#ifndef INPUT_H
#define INPUT_H


#include "common.h"

void input_handle(Game *game);
void input_keydown(Game *game, SDL_KeyboardEvent *event);
void input_keyup(Game *game, SDL_KeyboardEvent *event);


#endif
