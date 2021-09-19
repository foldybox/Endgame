// main.c

#include "main.h"

// int argc, char *argv[]

int main()
{
	Game game;
	Entity player;

	memset(&game, 0, sizeof(Game));
	memset(&player, 0, sizeof(Entity));

	game_init(&game);

	player.x = 100;
	player.y = 100;
	player.texture = loadTexture(&game, "assets/sprites/sp_player.png");

	//atexit(cleanup);

	while (1)
	{
		scene_prepare(&game);

		if (game.up)
		{
			player.y -= 1;
		}

		if (game.down)
		{
			player.y += 1;
		}

		if (game.left)
		{
			player.x -= 1;
		}

		if (game.right)
		{
			player.x += 1;
		}

		blit(&game, player.texture, player.x, player.y);

		input_handle(&game);

		scene_present(&game);
	}

	return 0;
}
