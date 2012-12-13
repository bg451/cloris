#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	//Generation of header request

	//This block is the initialization for connecting to
	//the website server;
	int sockfd  = 0;
	int n = 0;
	char recvBuff[1024];
	struct sockaddr_in server_addr;

	memset(recvBuff, '0', sizeof(recvBuff));
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0)) {
		printf("%s\n", "Could not create socket");
		return 1;
	}

	memset(&server_addr, '0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	int ia = atoi(argv[1]);
	server_addr.sin_addr.s_addr = htons(ia);
	server_addr.sin_port = htons(8080);
	
	if(connect(sockfd, (struct sockaddr *)&server_addr,
									sizeof(server_addr)) < 0) 
	{
		printf("%s\n", "Could not connect to server");
		exit(1);
	}
	char msg[] = "Helasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfsadfasdflo world!";
	sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*) &server_addr, 
							sizeof(server_addr));
	return 0;
	
}