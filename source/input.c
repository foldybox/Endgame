// input.c

#include "input.h"

void input_handle(Game *game)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				input_keydown(game, &event.key);
				break;

			case SDL_KEYUP:
				input_keyup(game, &event.key);
				break;

			default:
				break;
		}
	}
}

void input_keydown(Game *game, SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if ((event->keysym.scancode == SDL_SCANCODE_UP) || (event->keysym.scancode == SDL_SCANCODE_W))
		{
			game->up = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_DOWN) || (event->keysym.scancode == SDL_SCANCODE_S))
		{
			game->down = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_LEFT) || (event->keysym.scancode == SDL_SCANCODE_A))
		{
			game->left = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_RIGHT) || (event->keysym.scancode == SDL_SCANCODE_D))
		{
			game->right = 1;
		}
	}
}

void input_keyup(Game *game, SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if ((event->keysym.scancode == SDL_SCANCODE_UP) || (event->keysym.scancode == SDL_SCANCODE_W))
		{
			game->up = 0;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_DOWN) || (event->keysym.scancode == SDL_SCANCODE_S))
		{
			game->down = 0;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_LEFT) || (event->keysym.scancode == SDL_SCANCODE_A))
		{
			game->left = 0;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_RIGHT) || (event->keysym.scancode == SDL_SCANCODE_D))
		{
			game->right = 0;
		}
	}
}
