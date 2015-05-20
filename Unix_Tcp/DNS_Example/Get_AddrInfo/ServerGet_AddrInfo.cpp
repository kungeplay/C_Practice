//getaddrinfo函数服务器端
//运行时默认端口号是55555，不过在程序运行参数里可指定端口号。
#include <stdio.h>
#include <netdb.h>//getaddrinfo,addrinfo
#include <string.h>
#include <sys/socket.h>//setsockopt,getsockopt,
#include <unistd.h> //fork
#include <errno.h>
#include <stdlib.h>//getenv,atoi
#include <time.h>
#include "myunp.h"

#define SERVPORT 55555
#define MAXDATASIZE 200
#define	LISTENQ 20
//#define 

int Close(int fd)
{
	int i;
	if(-1==(i=close(fd)))
		err_ret("Close error !");
	return i;
}

int Setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t optlen)
{
	if (-1==setsockopt(sockfd,level,optname,optval,optlen))
	{
		err_ret("Setsockopt error !");
	}
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int		n;

	again:
	if ( (n = accept(fd, sa, salenptr)) < 0) 
	{
#ifdef	EPROTO
		if (errno == EPROTO || errno == ECONNABORTED)
#else
		if (errno == ECONNABORTED)
#endif
			goto again;
		else
			err_sys("accept error");
	}
	return(n);
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		err_sys("bind error");
}

/* include Listen */
void Listen(int fd, int backlog)
{
	char	*ptr;

		/*4can override 2nd argument with environment variable */
	if ( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
		err_sys("listen error");
}

int tcp_listen(const char * hoststyle,const char * serv,socklen_t *addrlenp)
{
	int listenfd,n;
	struct addrinfo hints,*res,*ressave;
	const int on =1;

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_flags=AI_PASSIVE;
	hints.ai_family=AF_INET;
	hints.ai_socktype=SOCK_STREAM;

	if (0!=(n=getaddrinfo(hoststyle,serv,&hints,&res)))
	{
		err_quit("tcp_listen error for :%s,%s; %s",hoststyle,serv,gai_strerror(n));
	}
	ressave=res;

	do
	{
		listenfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
		if (listenfd<0)
		{
			continue;
		}

		Setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
		if (0==bind(listenfd,res->ai_addr,res->ai_addrlen))
		{
			break;
		}

		Close(listenfd);
	}while(NULL!=(res=res->ai_next));

	if(res==NULL)
		err_sys("tcp_listen error for %s,%s",hoststyle,serv);

	Listen(listenfd,LISTENQ);

	if (addrlenp)
	{
		*addrlenp=res->ai_addrlen;
	}

	freeaddrinfo(ressave);

	return (listenfd);


}
int main(int argc, char const *argv[])
{
	int listenfd,connfd,lenstr=0;
	socklen_t len;
	time_t ticks;
	struct sockaddr_storage cliaddr;
	char tempbuf[MAXDATASIZE],serv[10];
	char  gethost[100],getserv[30];

	if (argc==1)
	{
		snprintf(serv,10,"%d",SERVPORT);
	}
	else if(argc==2)
	{
		snprintf(serv,10,"%s",argv[1]);
	}
	else if (argc>2)
	{
		err_quit("useage:ServerGet_AddrInfo [<service/port#>]\n");
	}
	printf("Listen port:%s\n", serv);

	listenfd=tcp_listen(NULL,serv,NULL);
	printf("The listen socket is %d\n",listenfd );

	for(;;)
	{
		len=sizeof(cliaddr);
		connfd=Accept(listenfd,(struct sockaddr *)&cliaddr,&len);
		if(0==fork())
		{
			Close(listenfd);

			if (0==getnameinfo((struct sockaddr *)&cliaddr,len,gethost,100,getserv,30,NI_NUMERICHOST|NI_NUMERICSERV))
			{
				printf("client address: %s:%s\n",gethost,getserv );
			}
			printf("the socket from accetp is %d\n", connfd);

			while(true)
			{
				lenstr=read(connfd,tempbuf,MAXDATASIZE);
				if(0==lenstr)
				{
					printf("It is over!\n");
					break;
				}
				else if (lenstr<0)
				{
					printf("It is wrong!\n");
					break;
				}

				tempbuf[lenstr]='\0';
				printf("recv: %s\r\n",tempbuf);

				ticks=time(NULL);
				snprintf(tempbuf,sizeof(tempbuf),"%.24s",ctime(&ticks));
				writen(connfd,tempbuf,strlen(tempbuf));
			}
		}
		Close(connfd);
	}
	return 0;
}
