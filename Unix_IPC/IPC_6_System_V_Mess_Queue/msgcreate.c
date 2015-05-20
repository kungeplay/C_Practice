#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//getopt
#include <sys/msg.h>
//创建消息队列
#define MSG_R 0400	//8进制
#define MSG_W 0200
#define SVMSG_MODE (MSG_R|MSG_W|MSG_R>>3|MSG_R>>6)//System V IPC权限见UNP_IPC P24 3.5节IPC权限
int main(int argc,char *argv[])
{
	int c,oflag,mqid;
	oflag=SVMSG_MODE|IPC_CREAT;
	key_t key;
	while((c=getopt(argc,argv,"e"))!=-1)
	{
		switch(c)
		{
			case 'e':
				oflag|=IPC_EXCL;
				break;
		}
	}
	if(optind!=argc-1)
	{
		printf("usage:msgcreate [-e] <pathname>\n");
		exit(1);
	}
	if((key=ftok(argv[optind],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!");
		exit(1);
	}
	if((mqid=msgget(key,oflag))==-1)
	{
		perror("msgget wrong!");
		exit(1);
	}
	exit(0);
}
