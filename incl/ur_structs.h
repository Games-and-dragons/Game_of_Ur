#ifndef UR_STRUCTS_H
# define UR_STRUCTS_H
# include "SDL_Master.h"
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef struct s_player
{
	int pieces;
	int piece_state[7];
}				Player;

typedef struct s_newtork
{
	int sockfd;
	char recvBuff[1024];
 	char talkBuff[1024];
	struct sockaddr_in serv_addr;
}				Network;

typedef struct s_game
{
	Display *display;
	Network connection;
	Player player1;
	Player player2;

	int turn;
	int selected;
	int num;
	char board[20];
}				game;

#endif
