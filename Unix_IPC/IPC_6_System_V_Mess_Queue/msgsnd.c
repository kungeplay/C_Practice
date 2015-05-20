#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//getopt,sysconf
#include <string.h>//strncpy
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
int main(int argc,char * argv[])
{
	int c;
	key_t key;
	int mqid;
	struct my_msgbuf buf;
	char temp[MY_DATA]={"This is a practice!"};
	buf.mtype=1;

	memset(buf.mtext,0,MY_DATA);
	strncpy(buf.mtext,temp,strlen(temp));
	while((c=getopt(argc,argv,"t:m:"))!=-1)
	{
		switch(c)
		{
			case 't':
				buf.mtype=atol(optarg);
				break;
			case 'm':
				memset(buf.mtext,0,MY_DATA);
				strncpy(buf.mtext,optarg,strlen(optarg));
				break;
		}
	}
	if(optind!=argc-1)
	{
		printf("usage: msgsnd [-t mtype] [-m message] <pathname>\n");
		exit(1);
	}
	
	if((key=ftok(argv[optind],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!\n");
		exit(1);
	}
	if((mqid=msgget(key,MSG_W))==-1)
	{
		perror("msgget wrong!\n");
		exit(1);
	}
	
	if(msgsnd(mqid,&buf,strlen(buf.mtext),0)==-1)
	{
		perror("msgsnd wrong!");
		exit(1);
	}
	exit(0);
}
