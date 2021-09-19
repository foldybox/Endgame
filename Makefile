# Makefile

# b - Build project, p - Play game, bnp - Build'n'Play.

b:
	clang source/*.c -o build/game.app -I libraries/include -L libraries/lib -lSDL2-2.0.0 -lSDL2_image -mwindows

p:
	build/game.app

bnp:
	clang source/*.c -o build/game.app -I libraries/include -L libraries/lib -lSDL2-2.0.0 -lSDL2_image -mwindows
	build/game.app