#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//针对线程和信号的编程练习与测试
//因为pthread并非Linux系统的默认库，编译时注意加上-lpthread参数，以调用链接库
sigset_t mask;
int quitflag;	//set nonzero by thread

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitloc=PTHREAD_COND_INITIALIZER;

void * thr_fn(void *arg)
{
	int err,signo;
	for(;;)
	{
		err=sigwait(&mask,&signo);//通过sigwait等待一个或多个信号的出现。set参数指定了线程等待的信号集。返回时，signop指向的整数将包含发送信号的数量
		if(err!=0)
		{
			printf("sigwait failed:%s",strerror(err));
			exit(1);
		}
		switch(signo)
		{
			case SIGINT:
				printf("\nsigint signal\n");
				break;
			case SIGQUIT:
				printf("\nsigquit signal\n");
				pthread_mutex_lock(&lock);
				quitflag=1;
				pthread_mutex_unlock(&lock);
				pthread_cond_signal(&waitloc);
				break;
			case SIGUSR1:
				printf("\nsigusr1 signal\n");
				break;
			default:
				printf("\nunexpected signal %d\n",signo);
				exit(1);
		}
	}
}

int main(void)
{
	int err;
	sigset_t oldmask;
	pthread_t tid;
	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	sigaddset(&mask,SIGQUIT);
	sigaddset(&mask,SIGUSR1);
	if((err=pthread_sigmask(SIG_BLOCK,&mask,&oldmask))!=0)//修改线程的信号屏蔽字
	{
		printf("SIG_BLOCK error:%s",strerror(err));
		exit(1);
	}
	err=pthread_create(&tid,NULL,thr_fn,NULL);//注意，新建线程屏蔽了现有的信号屏蔽字
	if(err!=0)
	{
		printf("can not create thread:%s",strerror(err));
		exit(1);
	}
	sleep(3);
	printf("send SIGUSR1 signal\n");
	err=pthread_kill(tid,SIGUSR1);//把信号发送给线程
	if(err!=0)
	{
		printf("can not send SIGUSR1\n",strerror(err));
	}

	pthread_mutex_lock(&lock);
	while(quitflag==0)
		pthread_cond_wait(&waitloc,&lock);
	pthread_mutex_unlock(&lock);

	//SIGQUIT has been caught and is now blocked;do whatever
	quitflag=0;

	//reset signal mask which unblocks SIGQUIT
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
	{
		printf("SIG_SETMASK error");
	}
	exit(0);

}
