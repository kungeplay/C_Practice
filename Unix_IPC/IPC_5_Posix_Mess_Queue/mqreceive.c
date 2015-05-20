#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
//一个简单的从Posix消息队列中读取消息的程序,
int main(int argc,char *argv[])
{
	int c,flags;
	mqd_t mqd;
	ssize_t n;
	int prio;
	void *buff;
	struct mq_attr attr;
	flags=O_RDONLY;
	while((c=getopt(argc,argv,"n"))!=-1)
	{
		switch(c)
		{
			case 'n':
			{
				flags|=O_NONBLOCK;
				break;
			}
		}
	}
	if(optind!=argc-1)
	{
		printf("useage: mqreceive [-n] <name>\n");
		exit(1);
	}
	if((mqd=mq_open(argv[optind],flags))==-1)
	{
		perror("mq_open wrong!");
		exit(1);
	}
	if(mq_getattr(mqd,&attr)==-1)
	{
		perror("mq_getattr wrong!");
		exit(1);
	}
	if((buff=malloc(attr.mq_msgsize))==NULL)
	{
		perror("malloc wrong!");
		exit(1);
	}
	if((n=mq_receive(mqd,buff,attr.mq_msgsize,&prio))==-1)//若队列中有消息，返回的是最高优先级的消息。消息自动从队列中删
	{
		perror("mq_receive wrong!");
		exit(1);
	}
	printf("read msg priority:%u,len=%d,context:%s\n",prio,n,(char *)buff);
}
