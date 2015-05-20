#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
/*
 *下面这个程序创建一个消息队列，并往该队列中放置一个含有1字节数据的消息，发出msgctl的IPC_STAT命令，使用system函数执行ipcs命令，
 *最后使用msgctl的IPC_RMID命令删除该队列
 */
typedef  unsigned long int ulong_t;
#define MSG_R 0400	//8进制
#define MSG_W 0200
#define SVMSG_MODE (MSG_R|MSG_W|MSG_R>>3|MSG_R>>6)//System V IPC权限见UNP_IPC P24 3.5节IPC权限
//下面定义一个用来发送接收消息的结构体
#define MY_DATA 100
 struct my_msgbuf
{
	long int mtype;	/*message type*/
	char mtext[MY_DATA];

};
int main(int argc,char *argv[])
{
	int msqid;
	struct msqid_ds info;
	struct my_msgbuf buf;


	if((msqid=msgget(IPC_PRIVATE,SVMSG_MODE|IPC_CREAT))==-1)
	{
		perror("msgget wrong!\n");
		exit(1);
	}
	buf.mtype=1;
	buf.mtext[0]=1;
	if(msgsnd(msqid,&buf,1,0)==-1)
	{
		perror("msgsnd wrong!\n");
		exit(1);
	}
	if(msgctl(msqid,IPC_STAT,&info)==-1)
	{
		perror("msgctl wrong!\n");
		exit(1);
	}
	printf("read-write:%03o, cbytes=%lu, qnum=%lu, qbytes=%lu\n",info.msg_perm.mode&0777,(ulong_t)info.msg_cbytes,(ulong_t)info.msg_qnum,(ulong_t)info.msg_qbytes);
	system("ipcs -qa");
	sleep(10);
	if(msgctl(msqid,IPC_RMID,NULL)==-1)
	{
		perror("msgctl wrong!\n");
		exit(1);
	}
	exit(0);
}
