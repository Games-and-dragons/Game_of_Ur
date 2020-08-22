#include "ur.h"


static void receive(game *game)
{

}

static void send(game *game)
{

}

static void menu(game *game)
{

}

static void play(game *game)
{
	if (game->display->input.button.button == 0)
	{
		
	}

	//send(game);
}

void parse_state(game *game)
{
	if (game->display->state == 0)
		menu(game);
	if (game->turn == game->num)
		play(game);
	//else receive(game);
}

