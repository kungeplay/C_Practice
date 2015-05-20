#include "myunp.h"
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>//unlink
#include <sys/wait.h>//waitpid
#include <stdio.h>//printf
#include <errno.h>
#include <string.h>
#include <stdlib.h>//exit
//使用Unix域套接字重新编写的回射服务器程序，其中socket文件定义在myunp.h中
#define LISTENQ 20



void sig_chld(int signo)
{
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))<0)
		printf("child %d terminated\n",pid );
	return;
}
void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];

again:
	while((n=read(sockfd,buf,MAXLINE))>0)
		Writen(sockfd,buf,n);
	if (n<0&&errno==EINTR)
	{
		goto again;
	}
	else
		if(n<0)
			err_sys("str_echo:read error");
}
int main(int argc, char const *argv[])
{
	int listenfd,connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_un cliaddr,servaddr;
	//void sig_chld(int);

	listenfd=Socket(AF_LOCAL,SOCK_STREAM,0);

	unlink(UNIXSTR_PATH);

	memset(&servaddr,0,sizeof(struct sockaddr_un));
	servaddr.sun_family=AF_LOCAL;
	strncpy(servaddr.sun_path,UNIXSTR_PATH,sizeof(servaddr.sun_path)-1);

	Bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

	Listen(listenfd,LISTENQ);

	Signal(SIGCHLD,sig_chld);

	for(;;)
	{
		clilen=sizeof(cliaddr);

		if ((connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen))<0)
		{
			if (errno==EINTR)
			{
				continue;
			}
			else
				err_sys("accept error");
		}

		if ((childpid=fork())==0)
		{
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
	return 0;
}
