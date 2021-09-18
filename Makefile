game:
	clang *.c -o build/game.app -I libraries/include -L libraries/lib -lSDL2-2.0.0 -lSDL2_image -mwindows
