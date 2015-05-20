#include <stdio.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>//exit
//一个简单的创建一个消息队列的例子，Posix消息队列至少具有随内核的持续性。
//注意编译时必须加上-lrt选项方可成功,若要在文件系统中查看创建的消息队列，需要通过man mq_overview命令查看
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)//注意是小括号

struct mq_attr attr;

int main(int argc,char * argv[])
{
	int c,flags;
	mqd_t mqd;
	flags=O_RDWR|O_CREAT;
	while((c=getopt(argc,argv,"em:z:"))!=-1)
	{
		switch(c)
		{
			case 'e'://排它性创建选项
				flags|=O_EXCL;
				break;
			case 'm'://队列中的最大消息数,注意attr.mq_maxmsg 不能超过文件 /proc/sys/fs/mqueue/msg_max 中的数值，我的机器上面是10.
				attr.mq_maxmsg=atol(optarg);
				break;
			case 'z'://队列中的一个消息的最大字节数,attr.mq_msgsize不能超过 /proc/sys/fs/mqueue/msgsize_max 的数值,我的机器上是8192.
				attr.mq_msgsize=atol(optarg);
				break;
		}
	}
	if(optind!=argc-1)//getopt在optind中存放下一个待处理参数的下标
	{
		printf("usage:mqcreate [-e] [-m maxmsg -z msgsize] <name>\n");
		exit(1);
	}

	if((attr.mq_maxmsg!=0&&attr.mq_msgsize==0)||(attr.mq_maxmsg==0&&attr.mq_msgsize!=0))//两个值都必须指定,见man mq_getattr
	{
		printf("must specify both -m maxmsg and -z msgsize\n");
		exit(1);
	}

	if((mqd=mq_open(argv[optind],flags,FILE_MODE,(attr.mq_maxmsg!=0)? (&attr):NULL))==-1)//注意在linux系统下mq_open函数第一个参数必须以'\'开头且只能包含一个'\'.见man mq_overview
	{
	        perror("mq_open wrong!");
		exit(1);
	}
	sleep(10);
	printf("休眠结束\n");
	if((mq_close(mqd))==-1)
	{
		perror("mq_close wrong!");
		exit(1);
	}
	exit(0);
}
