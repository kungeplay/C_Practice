#include <stdio.h>
#include<string.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>//fork
#include <stdlib.h>//exit
//函数pr_exit使用P191中的宏以打印进程终止状态的说明,演示终止状态的各种值
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
int main(void)
{
	pid_t pid;
	int status;


//-------------------
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)//child
		exit(7);
		
	if(wait(&status)!=pid)//wait for child
		err_sys("wait error");
	pr_exit(status);//and print its status
//-------------------
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)//child
		abort();//generates SIGABRT
		
	if(wait(&status)!=pid)//wait for child
		err_sys("wait error");
	pr_exit(status);//and print its status
//-------------------
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)//child
		status/=0;//divide by 0 generates SIGFPE
		
	if(wait(&status)!=pid)//wait for child
		err_sys("wait error");//and print its status
	pr_exit(status);

	exit(0);
}
