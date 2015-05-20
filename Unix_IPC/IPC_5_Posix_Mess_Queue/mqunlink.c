#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>
//一个简单的测试mq_unlink函数从系统中删除一个Posix消息队列的例子。
//注意当一个消息队列的引用计数仍大于0时，其name就能删除，但是该队列的析构(这与从系统中删除其名字不同)要到最后一个mq_close发生时才进行。
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("usage:mqunlink <name>\n");
		exit(1);
	}
	if((mq_unlink(argv[1]))==-1)
	{
		perror("mq_unlink wrong!");
		exit(1);
	}
	printf("删除消息成功!\n");
	exit(0);
}
