// input.c

#include "input.h"

void input_handle(t_game *game)
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

void input_keydown(t_game *game, SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if ((event->keysym.scancode == SDL_SCANCODE_UP) || (event->keysym.scancode == SDL_SCANCODE_W))
		{
			game->control.up = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_DOWN) || (event->keysym.scancode == SDL_SCANCODE_S))
		{
			game->control.down = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_LEFT) || (event->keysym.scancode == SDL_SCANCODE_A))
		{
			game->control.left = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_RIGHT) || (event->keysym.scancode == SDL_SCANCODE_D))
		{
			game->control.right = 1;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_RIGHT) || (event->keysym.scancode == SDL_SCANCODE_F))
		{
			game->control.use = 1;
		}
	}
}

void input_keyup(t_game *game, SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if ((event->keysym.scancode == SDL_SCANCODE_UP) || (event->keysym.scancode == SDL_SCANCODE_W))
		{
			game->control.up = 0;
			game->control.is_pressed_recently = false;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_DOWN) || (event->keysym.scancode == SDL_SCANCODE_S))
		{
			game->control.down = 0;
			game->control.is_pressed_recently = false;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_LEFT) || (event->keysym.scancode == SDL_SCANCODE_A))
		{
			game->control.left = 0;
			game->control.is_pressed_recently = false;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_RIGHT) || (event->keysym.scancode == SDL_SCANCODE_D))
		{
			game->control.right = 0;
			game->control.is_pressed_recently = false;
		}

		if ((event->keysym.scancode == SDL_SCANCODE_RIGHT) || (event->keysym.scancode == SDL_SCANCODE_F))
		{
			game->control.use = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			game->is_started = !game->is_started;
		}
		if (event->keysym.scancode == SDL_SCANCODE_SPACE && game->game_over_screen)
		{
			game->player->is_death = false;
		}
	}
}
