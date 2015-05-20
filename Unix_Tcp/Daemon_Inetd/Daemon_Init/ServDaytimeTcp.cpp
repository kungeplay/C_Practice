#include <time.h>
#include <syslog.h>//LOG_LOCAL2
#include <stdio.h>//snprintf
#include <string.h>
#include "myunp.h"

#define MAXLINE 200
//作为守护进程运行的时间获取服务器程序，它调用我们的daemon_init函数以作为守护进程运行。

int main(int argc, char const *argv[])
{
	int listenfd,connfd;
	socklen_t addrlen,len;
	struct sockaddr *cliaddr;
	char buff[MAXLINE];
	time_t ticks;

	if(argc<2||argc>3)
	{
		//char temp[100];
		//snprintf(temp,100,"useage: %s [<host>] <service or port>",argv[0]);
		err_quit("useage: %s [<host>] <service or port>",argv[0]);
	}
	daemon_init(argv[0],LOG_LOCAL2);

	if (argc==2)
	{
		listenfd=Tcp_listen(NULL,argv[1],&addrlen);

	}
	else
		listenfd=Tcp_listen(argv[1],argv[2],&addrlen);

	cliaddr=(struct sockaddr *)Malloc(addrlen);

	for (; ;)
	{
		len=addrlen;
		connfd=Accept(listenfd,cliaddr,&len);
		err_msg("connection from %s",Sock_ntop(cliaddr,len));

		ticks=time(NULL);
		snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
		Write(connfd,buff,strlen(buff));

		Close(connfd);
	}

	return 0;
}
