// text.c

#include "text.h"

SDL_Texture* text_render(char *message, char *font_file_name, SDL_Color color, int font_size, t_game *game) {
    TTF_Font *font = TTF_OpenFont(font_file_name, font_size);

    SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(game->renderer, surf);

    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

void text_draw(t_game *game, char *text, int x, int y, int size){
    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Texture *image = text_render(text, "fonts/sample.ttf", color, size, game);

    SDL_Rect dest;
	dest.x = x;
	dest.y = y;

    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(game->renderer, image, NULL, &dest);
}
