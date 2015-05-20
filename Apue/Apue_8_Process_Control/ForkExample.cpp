#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>//fork
#include <stdlib.h>//exit
//此程序演示了fork函数,从中可以看到子进程对变量所做的改变并不影响父进程中该变量的值,同时演示getlogin函数
#define MAXLINE 200
int globvar=6;
char buf[]="a write to stdout\n";

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

int main(void)
{
	int var;//automatic variable on the stack
	pid_t pid;
	var=88;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
	{
		err_sys("write error");
	}
	printf("before for\n");//we don't flush stdout,注意如果将输出重定向到一个文件时，会得到printf输出行两次。具体见Apue 184页

	if((pid=fork())<0)
	{
		err_sys("fork error");
	}
	else if(pid==0)
	{
		globvar++;//child
		var++;//modify variables
	}
	else
	{
		sleep(2);
	}

	printf("loginname=%s,pid=%ld,ppid=%ld,uid=%ld,euid=%ld,gid=%ld,egid=%ld,glob=%d,var=%d\n",getlogin(),(long)getpid(),(long)getppid(),(long)getuid(),(long)geteuid(),(long)getgid(),(long)getegid(),globvar,var);
	exit(0);
}
