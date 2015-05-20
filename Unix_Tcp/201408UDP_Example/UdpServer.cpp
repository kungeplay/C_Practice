//
//这个程序主要是测试UDP
//接收客户端发来的数据，显示，并反射回去。
//
#include <sys/socket.h>//socket,connect,bind,listen,accept,getsockname,getpeername,struct sockaddr,

#include <stdio.h>  //perror,
#include <stdlib.h> //perror,

#include <netinet/in.h>//struct sockaddr_in,htons,htonl,ntohs,ntohl,

#include <arpa/inet.h> //inet_pton,inet_ntop,

#include <string.h>//bzero,memset,

#include <unistd.h> //sleep,

#define SERV_PORT 49140
#define MAXLINE 1024

void dg_echo(int sockfd,struct sockaddr* pcliaddr,socklen_t clilen);
char * sock_ntop(const struct sockaddr *sa,socklen_t salen);


int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;

	if(-1==(sockfd=socket(AF_INET,SOCK_DGRAM,0)))
	{
		perror("socket create wrong!");
		exit(1);
	}

	memset(&servaddr,0,sizeof(servaddr));
	//bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(SERV_PORT);

	if (-1==bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)))
	{
		perror("socket bind wrong!");
		exit(1);
	}

	dg_echo(sockfd,(struct sockaddr *)&cliaddr,sizeof(cliaddr));

	return 0;
}
void dg_echo(int sockfd,struct sockaddr * pcliaddr,socklen_t clilen)
{
	int n;
	socklen_t len;
	char mesg[MAXLINE];
	char buff[MAXLINE+50];
	for (; ; )
	{
		len=clilen;
		if(-1==(n=recvfrom(sockfd,mesg,MAXLINE,0,pcliaddr,&len)))
		{
			perror("socket recvfrom wrong!");
			exit(1);
		}

		mesg[n]=0;
		snprintf(buff,sizeof(buff),"recvfrom:%s,;%s",sock_ntop(pcliaddr,len),mesg);
		printf("%s",buff);
		if (-1==(sendto(sockfd,mesg,n,0,pcliaddr,len)))
		{
			perror("socket sendto wrong!");
			exit(1);
		}
		sleep(2);
	}
}
char * sock_ntop(const struct sockaddr *sa,socklen_t salen)
{
	char portstr[8];
	static char str[128]; /* Unix domain is largest*/
	switch(sa->sa_family)
	{
		case AF_INET:
		{
			struct sockaddr_in * sin=(struct sockaddr_in *)sa;
			if(inet_ntop(AF_INET,&sin->sin_addr,str,sizeof(str))==NULL)
				return (NULL);
			if(ntohs(sin->sin_port)!=0)
			{
				snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
				strcat(str,portstr);
			}
			return(str);
		}
		/* end sock_ntop */
		default:
			snprintf(str, sizeof(str), "sock_ntop: unknown AF_xxx: %d, len %d",sa->sa_family, salen);
		return(str);
	}
    return (NULL);
}
