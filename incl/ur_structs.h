#ifndef UR_STRUCTS_H
# define UR_STRUCTS_H
# include "SDL_Master.h"

typedef struct s_player
{
	int state;
	int pieces;
	int piece_state[7];
}				Player;

typedef struct s_game
{
	Display *display;
	Player player1;
	Player player2;

	char board[20];
}				game;

#endif
