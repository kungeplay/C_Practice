#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>//sysconf
#include <string.h>//strncpy
//一个简单的Posix消息队列发送消息程序，根据UNP_IPC P65页例子改写。
#define MAXLINE 1024
int main(int argc,char * argv[])
{
	mqd_t mqd;
	void *ptr;
	size_t len;
	int prio;
	int c;
	int maxpro=0;
	char buf[MAXLINE]={"This is a practice!"};
	prio=0;
	if((maxpro=sysconf(_SC_MQ_PRIO_MAX))==-1)//获取系统任意消息的最大优先级
	{
		printf("sysconf wrogn!");
		exit(1);
	}
	while((c=getopt(argc,argv,"p:m:"))!=-1)
	{
		switch(c)
		{
			case 'p':
				if(maxpro>atol(optarg))
					prio=atol(optarg);
				else
					prio=maxpro;
				break;
			case 'm':
				memset(buf,0,MAXLINE);
				strncpy(buf,optarg,strlen(optarg));
				break;
		}
	}
	if(optind!=argc-1)
	{
		printf("usage: mqsend [-p priority] [-m message] <name>\n");
		exit(1);
	}
	ptr=(void *)buf;
	len=strlen(buf);
	
	if((mqd=mq_open(argv[optind],O_WRONLY))==-1)
	{
		perror("mq_open wrong!");
		exit(1);
	}
	if(mq_send(mqd,ptr,len,prio)==-1)//注意len值应小于此消息队列中规定的每个消息最大字节数，否则报错
	{
		perror("mq_send wrong!");
		exit(1);
	}
	exit(0);
}
