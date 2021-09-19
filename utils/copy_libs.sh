# load_libs.sh

# Using to copy SDL libs to current workspace folder

mkdir libraries
mkdir libraries/include
mkdir libraries/lib

cp -r ~/.brew/opt/sdl2/include/ libraries/include
cp -r ~/.brew/opt/sdl2/lib/ libraries/lib

cp ~/.brew/opt/sdl2_image/include/SDL2/SDL_image.h libraries/include/SDL2/
cp ~/.brew/opt/sdl2_image/lib/libSDL2_image-2.0.0.dylib libraries/lib/
cp ~/.brew/opt/sdl2_image/lib/libSDL2_image.a libraries/lib/
cp ~/.brew/opt/sdl2_image/lib/libSDL2_image.dylib libraries/lib/
cp ~/.brew/opt/sdl2_image/lib/pkgconfig/SDL2_image.pc libraries/lib/pkgconfig/