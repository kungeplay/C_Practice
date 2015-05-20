#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>
#define SERVPORT 3333
#define BACKLOG 10
#define TRUE 1
using namespace std;
int main()
{
	int sockfd,client_fd;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	char str[30];
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket create wrong!");
		exit(1);
	}
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(SERVPORT);
     my_addr.sin_addr.s_addr=INADDR_ANY;
     bzero(&(my_addr.sin_zero),8);
     if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
     {
      	perror("bind wrong!");
           exit(1);
     }
     if(listen(sockfd,BACKLOG)==-1)
     {
 		perror("listen wrong!");
		exit(1);
	}
	while(TRUE)
	{
		socklen_t sin_size=sizeof(struct sockaddr_in);
 		if((client_fd=accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size))==-1)
 		{
		perror("accept wrong!");
		continue;
		}
		printf("received a connection from %s\n",inet_ntoa(remote_addr.sin_addr));
		if(!fork())
		{
  			if(send(client_fd ,"Hello,you are connected!\n",26,0)==-1)
				perror("send wrong!");
  			if(recv(client_fd,str,20,0)==-1)
   				perror("recv wrong!");
  			cout<<"the recv is "<<str<<endl;
		}
		close(client_fd);
	}
	return 0;
}