#include "SDL_Master.h"
#include <sys/time.h>

static void get_input(Input *input, Display *display)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			display->state = 0;
		if (MOUSE_IN && event.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&input->mouse_x, &input->mouse_y);
		if (KEY_IN && event.type == SDL_KEYDOWN)
			input->key = event.key.keysym.scancode;
	}
}

void update(Display *display)
{
	struct timeval time, current;
	long elapsed;

	while (display->state)
	{
		gettimeofday(&time, NULL);

		get_input(&display->input, display);

		SDL_RenderClear(display->renderer);
		SDL_RenderPresent(display->renderer);

		gettimeofday(&current, NULL);
		elapsed = ((current.tv_sec - time.tv_sec) * 1000 + ((current.tv_sec - time.tv_sec) / 1000));

		if (elapsed < FRAME_DELAY)
			SDL_Delay(FRAME_DELAY - elapsed);
	}
	annhilate(display);
	exit(0);
}
