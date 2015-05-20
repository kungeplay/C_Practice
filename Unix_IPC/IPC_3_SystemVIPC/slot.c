#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>//msgget,msgctl
//一个简单的程序输出由msgget返回的前10个标识符值，标识符值的可能范围扩大到包含所有整数，而不是仅仅包含小整数,每次重用一个IPC表项时，把返回给调用进程的标识符值增加一个IPC表项数.见UNP_IPC 3.6节P26。
#define MSG_R 0400	//8进制
#define MSG_W 0200
#define SVMSG_MODE (MSG_R|MSG_W|MSG_R>>3|MSG_R>>6)//System V IPC权限见UNP_IPC P24 3.5节IPC权限
int main(int argc,char **argv)
{
	int i,msqid;
	for(i=0;i<10;i++)
	{
		if((msqid=msgget(IPC_PRIVATE,SVMSG_MODE|IPC_CREAT))==-1)
		{
			perror("msgget wrong!\n");
			exit(1);
		}
		printf("msqid=%d\n",msqid);
		if(msgctl(msqid,IPC_RMID,NULL)==-1)//由使用IPC_RMID命令的msgctl删除该队列
		{
			perror("msgctl wrong!\n");
			exit(1);
		}
	}
	exit(0);
}
