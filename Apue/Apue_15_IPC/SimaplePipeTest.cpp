#include <stdio.h>
#include <unistd.h>//pipe,fork,fpathconf
#include <string.h>
#include <errno.h>
#include <stdlib.h>//exit
/*此程序创建了一个从父进程到子进程的管道，并且父进程经由该管道向子进程传送数据。见P432图15-5
 *管道只能在具有公共祖先的两个进程之间使用。通常，一个管道由一个进程创建，在进程调用fork之后，这个管道就能在父进程和子进程之间使用了。
 *管道为半双工通信.
 */
#define MAXLINE 200
void err_sys(const char * fmt)
{
	char buf[MAXLINE];
	snprintf(buf,MAXLINE-1,fmt);
	snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1," :%s ",strerror(errno));
	strcat(buf,"\n");
	fflush(stdout);//in case stdout and stderr are the same
	fputs(buf,stderr);
	fflush(NULL);//flushes all stdio output streams

}
int main(int argc,char *argv[])
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];
	char line1[MAXLINE];
	if(pipe(fd)==-1)//经由参数fd返回两个文件描述符：fd[0]为读而打开，fd[1]为写而打开，fd[1]的输出是fd[0]的输入.
		err_sys("pipe error");
	printf("%d,%d\n",fd[0],fd[1]);
	printf("内核的管道缓冲区大小PIPE_BUF:%ld\n",fpathconf(fd[0],_PC_PIPE_BUF));
	if((pid=fork())<0)
	{
		err_sys("pipe error");
	}
	else if(pid>0)//parent
	{
		char buf[]="Hello World!这是一个管道通信程序，父进程通过管道向子进程发送信息!\n";
		close(fd[0]);
		write(fd[1],buf,strlen(buf));
	}
	else
	{
		close(fd[1]);
		n=read(fd[0],line,MAXLINE);
		write(STDOUT_FILENO,line,n);
	}
	exit(0);
}
