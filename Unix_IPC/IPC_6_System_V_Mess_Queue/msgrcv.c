#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>

#define MSG_R 0400	//8进制
#define MSG_W 0200
#define SVMSG_MODE (MSG_R|MSG_W|MSG_R>>3|MSG_R>>6)//System V IPC权限见UNP_IPC P24 3.5节IPC权限
//下面定义一个用来发送接收消息的结构体
#define MY_DATA 200
 struct my_msgbuf
{
	long int mtype;	/*message type*/
	char mtext[MY_DATA];

};
int main(int argc,char *argv[])
{
	int c,flag;
	int mqid;
	key_t key;
	long type=0;
	ssize_t n;
	struct my_msgbuf * bufptr;
	
	while((c=getopt(argc,argv,"nt:"))!=-1)
	{
		switch(c)
		{
			case 'n':
			{
				flag|=IPC_NOWAIT;//非阻塞
				break;
			}
			case 't':
			{
				type=atol(optarg);//type指定了希望从所给定的队列中读出什么样的消息
				break;
			}
		}
	}
	if(optind!=argc-1)
	{
		printf("useage: msgrcv [-n] [-t type] <pathname>\n");
		exit(1);
	}
	if((key=ftok(argv[optind],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!\n");
		exit(1);
	}
	if((mqid=msgget(key,MSG_R))==-1)
	{
		perror("msgget wrong!\n");
		exit(1);
	}
	if((bufptr=malloc(MY_DATA+sizeof(long)))==NULL)
	{
		perror("malloc wrong!");
		exit(1);
	}
	if((n=msgrcv(mqid,bufptr,MY_DATA,type,flag))==-1)//如果type为0，那就返回该队列中的第一个消息。
	{
		perror("msgrcv wrong!");
		exit(1);
	}
	printf("read %d bytes, type=%ld, message:%s\n",n,bufptr->mtype,bufptr->mtext);
	exit(0);
}
