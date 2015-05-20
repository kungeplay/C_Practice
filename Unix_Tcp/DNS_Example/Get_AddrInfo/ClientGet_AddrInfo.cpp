//getaddrinfo函数客户端
//做一个简单的tcp通信程序
//客户端定时向服务器端发送信息并接收服务器端发回来的信息显示出来

#include <stdio.h>//snprintf
#include <sys/socket.h>
#include <netdb.h> //getaddrinfo,addrinfo,gai_strerror,freeaddrinfo
#include <string.h> //memset,strlen
#include <unistd.h>//close
#include "myunp.h"

#include <errno.h>//error,EINTR
#define SERVPORT 55555
#define MAXDATASIZE 200



int  tcp_connect(const char *host,const char *serv)
{	
	int sockfd,n;
	struct addrinfo hints,*res,*ressave;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_flags=AI_CANONNAME;

	if((n=getaddrinfo(host,serv,&hints,&res))!=0)
	{
		err_quit("tcp_connect error for : %s,%s: %s",host,serv,gai_strerror(n));
	}
	ressave=res;
	do
	{
		if(-1==(sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol)))
		{
			continue;
		}
		if (0==connect(sockfd,res->ai_addr,res->ai_addrlen))
		{
			break; //success
		}
		close(sockfd);
	}
	while((res=res->ai_next)!=NULL);

	if (res==NULL) //errno set from final connect();
	{
		err_sys("tcp_connect error for %s,%s",host,serv);
	}

	freeaddrinfo(ressave);

	return (sockfd);

}


int main(int argc, char const *argv[])
{
	char serv[10];
	int sockfd,lenstr=0,sendcount=0;
	socklen_t len;
	struct sockaddr_storage ss;
	char tempbuf[MAXDATASIZE];

	if (argc<2||argc>3)
	{
		err_quit("useage:ClientGet_AddrInfo <hostname/IPaddress> [<service/port#>]\n");
	}
	if (argc==2)
	{
		snprintf(serv,10,"%d",SERVPORT);
		sockfd=tcp_connect(argv[1],serv);
	}
	else 
		sockfd=tcp_connect(argv[1],argv[2]);
	len=sizeof(ss);
	getpeername(sockfd,(struct sockaddr *)&ss,&len);
	printf("connected to %s\n", Sock_ntop_host((struct sockaddr*)&ss,len));
	printf("the socket is %d\n",sockfd );

	for (; ;)
	{
		sleep(1);
		snprintf(tempbuf,sizeof(tempbuf),"Hello Server! %d",++sendcount);
		writen(sockfd,tempbuf,strlen(tempbuf));

		if (0>(lenstr=read(sockfd,tempbuf,MAXDATASIZE)))
		{
			if (errno==EINTR)
			{
				lenstr=0;
			}
			else
			{
				return -1;
			}
		}
		else if(0==lenstr)
			break;
		tempbuf[lenstr]='\0';
		printf("recv: %s\n",tempbuf);
	}

	return 0;
}
