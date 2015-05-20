#include <netinet/in.h> //sockaddr_storage
#include <sys/socket.h>//getpeername
#include <stdio.h>
#include "myunp.h"
//协议无关的获取时间获取客户端程序


#define MAXLINE 200 

int main(int argc, char const *argv[])
{
	int sockfd,n;
	char recvline[MAXLINE+1];
	socklen_t len;
	struct sockaddr_storage ss;
	if (argc!=3)
	{
		err_quit("usage: %s <hostname/IPaddress> <service/port#>",argv[0]);
	}

	sockfd=Tcp_connect(argv[1],argv[2]);

	len=sizeof(ss);
	Getpeername(sockfd,(SA*)&ss,&len);
	printf("connected to %s\n",Sock_ntop_host((SA*)&ss,len));

	while((n=Read(sockfd,recvline,MAXLINE))>0)
	{
		recvline[n]='\0';
		Fputs(recvline,stdout);
	}
	return 0;
}
