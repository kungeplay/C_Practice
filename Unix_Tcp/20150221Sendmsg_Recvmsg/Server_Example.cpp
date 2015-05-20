//TCP端口号的选择应该比5000大，比49152小
//采用fork子进程来处理来自客户端的连接
//此时，应该处理SIGCHLD信号，杀死僵尸子进程
//此程序主要是使用sendmsg和recvmsg函数
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<fcntl.h>
#include<netinet/tcp.h>
#include<string.h>
#include<sys/socket.h>//struct msghdr
#include<arpa/inet.h>
#include<sys/wait.h>//wait和waitpid函数的头文件


#define SERV_PORT 55555
#define LISTENQ 20
#define MAXBUF 200

void sig_chld(int signo)
{
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))>0)//WNOHANG指定若指定的子进程并不是立即可调用的则waitpid不阻塞，此时其返回值为0
		printf("child %d terminated\n",pid);//在信号处理函数中调用诸如printf这样的标准I/O函数是不合适的,(Unix网络编程卷1：P107)
	return;
}

int main(int argc, char const *argv[])
{
  	int sockfd,client_fd;	
  	struct sockaddr_in my_addr;
  	struct sockaddr_in remote_addr;
  	char buf[MAXBUF];
  	int lenstr=0;
  	socklen_t sin_size=0;

	struct iovec iov[1];
	struct msghdr msg;

  	if ((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
  	{
  		perror("socket create wrong!");
  		exit(1);
  	}
	int val=1;
	if(-1==setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,(void *)&val,sizeof(val))) //根据Unix网络编程P165 所有TCP服务器都应该指定本套接字选项，以允许服务器在这种情形下被重新启动。
	{
		perror("socket setsockopt wrong!");
		exit(1);
	}
  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(SERV_PORT);
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	bzero(&(my_addr.sin_zero),8);
  	if (bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
  	{
  		perror("bind error!");
  		exit(1);
  	}
  	if (listen(sockfd,LISTENQ)==-1)
  	{
  		perror("listen error!");
  		exit(1);
  	}
	signal(SIGCHLD,sig_chld);
  	while(true)
  	{
		sin_size=sizeof(struct sockaddr_in);
		if ((client_fd=accept(sockfd,(struct sockaddr*)&remote_addr,&sin_size))<0)
	       	{
	    		if (errno==EINTR)
	    		{
	      			continue; /*back to for()*/
	    		}
	     		else
	     		{
				perror("accept wrong!");
				return -1;
	      		}
	    	}
	    	printf("Receive a connection from %s\n",inet_ntoa(remote_addr.sin_addr));
	    	if (!fork())
	    	{
	      		close(sockfd);
	      		while(true)
	      		{
				lenstr=recv(client_fd,buf,200,0);
				if (lenstr<=0)
				{
		  			printf("It is Over!\n");
		  			exit(1);
				}
				buf[lenstr]='\0';
				printf("Receive:%s\n",buf);
	      		}
	    	}
	    	close(client_fd);//在父进程中关闭一个客户端的已连接套接字

  	}	
  	close(client_fd);

	return 0;
}
