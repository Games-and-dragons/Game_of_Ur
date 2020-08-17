#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

void host()
{
	int listenfd = 0,connfd = 0;

	struct sockaddr_in serv_addr;

	char sendBuff[1025];
	char talkBuff[1025];
	int numrv, n;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("HOST SOCKET\n");

	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

	listen(listenfd, 10);

	connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	int b;
	while(1)
	{
		b = recv(connfd, talkBuff, sizeof(talkBuff), 0);
		printf("received : %s", talkBuff);
		fgets(talkBuff, 100, stdin);
		send(connfd, talkBuff, strlen(talkBuff), 0);
	}
}

void join_game()
{
	int sockfd = 0,b = 0;
	char recvBuff[1024];
 	char talkBuff[1024];
	struct sockaddr_in serv_addr;

	memset(recvBuff, '0' ,sizeof(recvBuff));
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	while (1)
	{
		fgets(talkBuff, 100, stdin);
		send(sockfd, talkBuff, strlen(talkBuff), 0);
		b = recv(sockfd, talkBuff, sizeof(talkBuff), 0);
		printf("received : %s", talkBuff);
	}
}

int main(int argc, char**argv)
{
	if (argc > 1)
		join_game();
	else
		host();
}
