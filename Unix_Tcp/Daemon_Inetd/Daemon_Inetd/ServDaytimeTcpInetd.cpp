#include <time.h>
#include <sys/socket.h>//socklen_t
#include <syslog.h>//LOG_LOCAL2
#include <string.h>//strlen
#include <stdio.h>//snprintf
#include "myunp.h"
//这个服务器程序由系统inetd守护进程启动。协议无关的时间获取服务器程序
//这个程序有两个大的改动，和上一次写的Daemon_Init相比,首先，所有套接字创建代码(即对tcp_listen和accept的调用)都消失了。这些步骤改由inetd执行，我们使用描述符0(标准输入)指代已由inetd接受的TCP连接。其次，无限的for循环也消失了，因为本服务器程序将针对每个客户连接启动一次，服务完当前客户后进程就终止。
//客户端程序可以使用Daemon_Init目录下的客户程序,端口号为55544
#define MAXLINE 200
int main(int argc, char const *argv[])
{
	socklen_t len;
	struct sockaddr *cliaddr;
	char buff[MAXLINE];
	time_t ticks;
	daemon_inetd(argv[0],LOG_LOCAL2);
	cliaddr=(struct sockaddr *)Malloc(sizeof(struct sockaddr_storage));
	len=sizeof(struct sockaddr_storage);
	Getpeername(0,cliaddr,&len);
	err_msg("connection from %s",Sock_ntop(cliaddr,len));

	ticks=time(NULL);
	snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
	Write(0,buff,strlen(buff));
	Close(0);//close TCP connection
	return 0;
}
