#include <errno.h>
#include <stdio.h>
#include <unistd.h>//fork,getpid,
#include <stdlib.h>//exit
#include <string.h>
#include <signal.h>
//一个父进程已终止的进程称为孤儿进程(orphan process),这种进程由init进程"收养"。

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

void pr_exit(int status)
{
	if(WIFEXITED(status))//若为正常终止子进程返回的状态，则为真。对于这种情况可执行WEXITSTATUS(status),获取子进程传递给exit或_exit参数的低8位
		printf("normal termination, exit status=%d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))//若为异常终止子进程返回的状态，则为真(接到一个不捕捉的信号)。对于这种情况，可执行WTERMSIG(status),获取使子进程终止的信号编号。另外有些实现定义宏WCOREDUMP(status),若已产生终止进程的core文件,则它返回真
		printf("abnormal termination, signal number= %d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ?"(core file generated)":"");
#else
				"");
#endif
	else if(WIFSTOPPED(status))//若为当前暂停子进程的返回状态，则为真。对于这种情况，可执行WSTOPSIG(status),获取使子进程暂停的信号编号。
		printf("child stopped,sinal number=%d\n",WSTOPSIG(status));
	else
		printf("It is over!\n");

}

static void sig_hup(int signo)
{
	printf("SIGHUP received,pid=%ld\n",(long)getpid());
}

static void pr_ids(const char *name)
{
	printf("%s:pid=%ld,ppid=%ld,pgrp=%ld,tpgrp=%ld,sid=%ld\n",name,(long)getpid(),(long)getppid(),(long)getpgrp(),(long)tcgetpgrp(STDIN_FILENO),(long)getsid(0));
	fflush(stdout);
}

int main(void)
{
	char c;
	pid_t pid;
	pr_ids("parent");
	if((pid=fork())<0)
	{
		err_sys("fork error");
	}
	else if(pid>0)	//parent
	{
		sleep(5);//sleep to let child stop itself
	}
	else	//child
	{
		pr_ids("child");
		signal(SIGHUP,sig_hup);//establish signal handler
		kill(getpid(),SIGTSTP);//stop ourself
		pr_ids("child");//prints only if we're continued;
		if(read(STDIN_FILENO,&c,1)!=1)
			printf("read error %d on controlling TTY\n",errno);

	}
	exit(0);
}
