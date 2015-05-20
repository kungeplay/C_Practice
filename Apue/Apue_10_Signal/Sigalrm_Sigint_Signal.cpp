#include<setjmp.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
//如果SIGALRM中断了某个其他信号处理程序，则调用longjmp会提早终止该信号处理程序。下面的代码显示了这种情况，SIGINT处理程序中包含了for循环语句，它在系统上的执行时间超过5秒，也就是大于sleep2的参数值，这正是想要的结果，整形变量k说明为volatile,这样就阻止了优化编译程序去除循环语句。
//此程序在运行过程中，首先调用pause函数使调用进程挂起，然后按中断键使产生中断信号，执行中断处理函数。在此执行过程中，定时时间到，又转而处理定时中断函数，在中断处理函数中执行longjmp函数，使程序跳转到sleep2函数中的setjmp函数处，返回值为1，然后sleep2执行结束，跳转到main函数，main函数执行结束。则进程退出执行。程序结果不固定
static jmp_buf env_alrm;

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

static void sig_alrm(int signo)
{
	longjmp(env_alrm,1);
}

static void sig_int(int signo)
{
	int i,j;
	volatile int k;
	printf("\nsig_int starting\n");
	for(i=0;i<300000;i++)
		for(j=0;j<4000;j++)
			k+=i*j;
	printf("sig_int finished\n");
}

unsigned int sleep2(unsigned int seconds)
{
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		return seconds;
	if(setjmp(env_alrm)==0)
	{
		alarm(seconds);//start the timer
		pause();
	}
	return (alarm(0));//turn off timer,return unslept time
}
int main(int argc,char * argv[])
{
	unsigned int unslept;
	int j=32,i=3;
	j&=~(1<<(i-1));
	printf("%d\n",j);

	if(signal(SIGINT,sig_int)==SIG_ERR)//当用户按中断键时，终端驱动程序产生此信号。
		err_sys("signal(SIGINT) error");
	unslept=sleep2(5);
	printf("sleep2 returned:%u\n",unslept);
	exit(0);
}
