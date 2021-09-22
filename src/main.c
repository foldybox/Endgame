// main.c

#include "main.h"

// int argc, char *argv[]

int main()
{
	Game game;
	Entity player;
	Entity bullet;
	bool isPressed = false;

	memset(&game, 0, sizeof(Game));
	memset(&player, 0, sizeof(Entity));
	memset(&bullet, 0, sizeof(Entity));

	game_init(&game);

	player.texture = loadTexture(&game, "assets/sprites/sp_player.png");
	player.x = 100;
	player.y = 100;

	bullet.texture = loadTexture(&game, "assets/sprites/sp_bullet.png");

	//atexit(cleanup);

	while (1)
	{
		scene_prepare(&game);

		isPressed = false;

		if (game.control.up)
		{
			if (!isPressed || game.control.down)
			{
				player.y -= PLAYER_SPEED;
			}
			else
			{
				player.y -= side_by_diagonal(PLAYER_SPEED);
			}
			isPressed = true;
		}

		if (game.control.down)
		{
			if (!isPressed || game.control.up)
			{
				player.y += PLAYER_SPEED;
			}
			else
			{
				player.y += side_by_diagonal(PLAYER_SPEED);
			}
			isPressed = true;
		}

		if (game.control.left)
		{
			if (!isPressed || game.control.right)
			{
				player.x -= PLAYER_SPEED;
			}
			else
			{
				player.x -= side_by_diagonal(PLAYER_SPEED);
			}
			isPressed = true;
		}

		if (game.control.right)
		{
			if (!isPressed || game.control.left)
			{
				player.x += PLAYER_SPEED;
			}
			else
			{
				player.x += side_by_diagonal(PLAYER_SPEED);
			}
			isPressed = true;
		}

		if (game.control.use && bullet.health == 0)
		{
			bullet.x = player.x;
			bullet.y = player.y;
			bullet.dx = 1;
			bullet.dy = 0;
			bullet.health = 1;
		}

		bullet.x += bullet.dx;
		bullet.y += bullet.dy;

		if (bullet.x > SCREEN_WIDTH)
		{
			bullet.health = 0;
		}

		double pX = 100, pY = 100;

		pX = pX + (player.x - pX) / 5;
		pY = pY + (player.y - pY) / 5;

		blit(&game, player.texture, pX, pY);

		if (bullet.health > 0)
		{
			blit(&game, bullet.texture, bullet.x, bullet.y);
		}

		input_handle(&game);

		scene_present(&game);
	}

	return 0;
}
