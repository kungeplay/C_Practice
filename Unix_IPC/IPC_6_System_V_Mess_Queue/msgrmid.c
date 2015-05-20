#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
//此程序以IPC_RMID命令调用msgctl删除一个消息队列
#define MSG_R 0400	//8进制
#define MSG_W 0200
#define SVMSG_MODE (MSG_R|MSG_W|MSG_R>>3|MSG_R>>6)//System V IPC权限见UNP_IPC P24 3.5节IPC权限
int main(int argc,char *argv[])
{
	int mqid;
	key_t key;
	if(argc!=2)
	{
		printf("usage: msgrmid <pathname>");
		exit(1);
	}
	
	if((key=ftok(argv[1],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!\n");
		exit(1);
	}
	if((mqid=msgget(key,0))==-1)
	{
		perror("msgget wrong!\n");
		exit(1);
	}
	if(msgctl(mqid,IPC_RMID,NULL)==-1)
	{
		perror("msgctl wrong!\n");
		exit(1);
	}
	exit(0);
}
