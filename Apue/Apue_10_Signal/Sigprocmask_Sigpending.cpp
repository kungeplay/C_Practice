#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
/*
 *此代码为10.13函数sigpending的例子,sigpending函数返回一信号集，对于调用进程而言，其中的各信号是阻塞不能递送的，因而一定是当前未决的。该信号集通过set参数返回。
 *此程序还有个功能是验证了在调用sigprocmask后如果有任何未决的，不再阻塞的信号，则在sigprocmask返回前，至少将其中之一递送给该进程。见P275
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
static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT,SIG_DFL)==SIG_ERR)//SIGQUIT为按产生ctrl+'\'  此处将SIGQUIT信号恢复为默认，即中断当前进程，产生core file
		err_sys("can not reset SIGQUIT");
}

int main(int argc,char * argv[])
{
	sigset_t newmask,oldmask,pendmask;
	if(signal(SIGQUIT,sig_quit)==SIG_ERR)
		err_sys("can not catch SIGQUIT");

	/*
	 *Block SIGQUIT and save current signal mask
	 */
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
		err_sys("SIG_BLOCK error");

	sleep(5);//SIGQUIT here will remain pending
	
	if(sigpending(&pendmask)<0)
		err_sys("sigpending error");
	if(sigismember(&pendmask,SIGQUIT))
		printf("\nSIGQUIT pending\n");

	/*
	 * Restore signal mask which unblocks SIGQUIT.
	 */
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");

	sleep(5); //SIGQUIT here will terminate with core file
	exit(0);
}
