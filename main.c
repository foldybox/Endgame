// main.c

#include "main.h"

int main(int argc, char *argv[])
{
	Game game;
	Entity player;

	memset(&game, 0, sizeof(Game));
	memset(&player, 0, sizeof(Entity));

	game_init(&game);

	player.x = 100;
	player.y = 100;
	player.texture = loadTexture(&game, "src/images/player.png");

	//atexit(cleanup);

	int i = 0;

	while (1)
	{
		scene_prepare(&game);

		blit(&game, player.texture, player.x, player.y);

		input_handle();

		scene_present(&game);

		SDL_Delay(20);

		player.x++;
	}

	return 0;
}
