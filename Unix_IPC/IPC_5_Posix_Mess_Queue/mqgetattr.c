#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>//exit
//一个简单的测试练习mq_getattr和mq_setattr函数的例子

void print_attr(struct mq_attr attr)
{
	printf("mq_flags=%ld, max #msgs=%ld, max #bytes/msg=%ld, #currently on queue=%ld\n",attr.mq_flags,attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);
}
int main(int argc,char * argv[])
{
	mqd_t mqd;
	struct mq_attr attr,newattr,oldattr;
	if(argc!=2)
	{
		printf("usage:mqgetattr <name>");
		exit(1);
	}
	if((mqd=mq_open(argv[1],O_RDONLY))==-1)
	{
		perror("mq_open wrong!");
		exit(1);
	}
	if((mq_getattr(mqd,&attr))==-1)
	{
		perror("mq_getattr wrong!");
		exit(1);
	}
	printf("获得Posix消息队列属性为:\n");
	print_attr(attr);
	
	newattr.mq_flags=O_NONBLOCK;
	printf("设置的Posix消息队列属性为:\n");
	printf("mq_flags=%ld\n",newattr.mq_flags);

	if(mq_setattr(mqd,&newattr,&oldattr)==-1)
	{
		perror("mq_setattr wrong!");
		exit(1);
	}
	printf("从mq_setattr函数获得的旧的attr值为:\n");
	print_attr(oldattr);

	//打印调用mq_setattr函数后Posix消息队列的属性
	if((mq_getattr(mqd,&attr))==-1)
	{
		perror("mq_getattr wrong!");
		exit(1);
	}
	printf("mq_setattr设置后现在Posix消息队列属性为:\n");
	print_attr(attr);

	if(mq_close(mqd)==-1)
	{
		perror("mq_close wrong!");
		exit(1);
	}
	exit(0);
}
