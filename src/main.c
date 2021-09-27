// main.c

#include "main.h"

// int argc, char *argv[]

int main()
{
	t_game *game = game_init();

	game->is_started = true;

	scene_init(game);

	while (1) {

		scene_prepare(game);

		scene_present(game);

		input_handle(game);

		while (game->is_started) {
			scene_prepare(game);

			scene_draw(game);

			scene_present(game);

			scene_logic(game);

			input_handle(game);

			SDL_Delay(16);
		}
	}
	game_free(game);

	return 0;
}
