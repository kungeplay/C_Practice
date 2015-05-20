#include "myunp.h"
#include <math.h>
#include <string.h>
#include <sys/socket.h>//shutdown
#include <sys/un.h> //sockaddr_un
//使用Unix域字节流协议的回射客户程序,接受用户通过键盘输入的的内容，然后发送给服务器，由服务器反射回来，并显示出来

int max(int a ,int b)
{
	return a>=b?a:b;
}
void str_cli(FILE * fp,int sockfd)
{
	int maxfdp1,stdineof;
	fd_set rset;
	char buf[MAXLINE];
	int n;
	stdineof=0;
	FD_ZERO(&rset);
	for (; ;)
	{
		if (stdineof==0)
		{
			FD_SET(fileno(fp),&rset);
		}
		FD_SET(sockfd,&rset);
		maxfdp1=max(sockfd,fileno(fp))+1;
		Select(maxfdp1,&rset,NULL,NULL,NULL);

		if (FD_ISSET(sockfd,&rset))//socket is readable
		{
			if ((n=Read(sockfd,buf,MAXLINE))==0)
			{
				if (stdineof==1)
				{
					return;
				}
				else
					err_quit("str_cli:server terminated prematurely");
			}
			Write(fileno(stdout),buf,n);
		}
		if (FD_ISSET(fileno(fp),&rset)) //input is readable
		{
			if ((n=Read(fileno(fp),buf,MAXLINE))==0)
			{
				stdineof=1;
				Shutdown(sockfd,SHUT_WR);//send FIN
				FD_CLR(fileno(fp),&rset);
				continue;
			}
			Write(sockfd,buf,n);
		}
	}
}


int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_un servaddr;

	sockfd=Socket(AF_LOCAL,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(struct sockaddr_un));
	servaddr.sun_family=AF_LOCAL;
	strncpy(servaddr.sun_path,UNIXSTR_PATH,sizeof(servaddr.sun_path)-1);

	Connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	str_cli(stdin,sockfd);    //do it all
	return 0;
}
