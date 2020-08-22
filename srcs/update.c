#include "ur.h"
#include <sys/time.h>

static void get_input(Input *input, Display *display)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			display->state = 0;
		if (MOUSE_IN)
		{
			if (event.type == SDL_MOUSEMOTION)
				SDL_GetMouseState(&input->mouse_x, &input->mouse_y);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				input->button = event.button;
		}
		if (KEY_IN && event.type == SDL_KEYDOWN)
			input->key = event.key.keysym.scancode;
	}
}

void update(game *game)
{
	struct timeval time, current;
	long elapsed;

	compose_board(game);
	while (game->display->state)
	{
		gettimeofday(&time, NULL);

		get_input(&game->display->input, game->display);

		SDL_RenderPresent(game->display->renderer);
		SDL_RenderClear(game->display->renderer);
		SDL_RenderCopy(game->display->renderer, game->display->text, NULL, NULL);

		gettimeofday(&current, NULL);
		elapsed = ((current.tv_sec - time.tv_sec) * 1000 + ((current.tv_sec - time.tv_sec) / 1000));

		if (elapsed < FRAME_DELAY)
			SDL_Delay(FRAME_DELAY - elapsed);
	}
	annhilate(game->display);
	exit(0);
}

int parse_input(game *game)
{
	
}
