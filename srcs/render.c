#include "ur.h"

void compose_board(game *game)
{
	SDL_Rect tile;
	SDL_Texture *tmp = SDL_CreateTexture(game->display->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,WIN_W, WIN_H);

	SDL_SetRenderTarget(game->display->renderer, tmp);
	SDL_SetRenderDrawColor(game->display->renderer, 0, 255, 0, 255);


	tile.h = WIN_H / 10;
	tile.w =  WIN_W / 10;

	tile.x = tile.w;
	tile.y = 0;//(WIN_H / 2 ) - (4 * tile.h);

	for (int i = 1; i <= 24; i++)
	{
		if ((i - 1) % 3 == 0)
		{
			tile.y += tile.h;
			tile.x = (WIN_W / 2) - tile.w;
		}
		if (i < 13 || i == 14  || i == 17 || i > 18)
		SDL_RenderDrawRect(game->display->renderer, &tile);
		tile.x += tile.w;
	}
	game->display->text = tmp;
	SDL_SetRenderTarget(game->display->renderer, NULL);
	SDL_SetRenderDrawColor(game->display->renderer, 0, 0, 0, 255);
}
