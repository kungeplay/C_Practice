#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
//创建一个System V 信号量集.-e命令行选项指定IPC_EXCL标志.可通过ipcs -qa查看
#define SEM_R 0400	//8进制
#define SEM_W 0200
#define SVSEM_MODE (SEM_R|SEM_W|SEM_R>>3|SEM_R>>6)//System V IPC权限见UNP_IPC P24 3.5节IPC权限
int main(int argc,char *argv[])
{
	int c,oflag,semid,nsems;
	key_t key;
	oflag=SVSEM_MODE|IPC_CREAT;
	while((c=getopt(argc,argv,"e"))!=-1)
	{
		switch(c)
		{
			case 'e':
				oflag|=IPC_EXCL;
				break;
		}
	}
	if(optind!=argc-2)
	{
		printf("usage: semcreate [-e] <pathname> <nsems>\n");
		exit(1);
	}
	nsems=atoi(argv[optind+1]);//集合中的信号量数,如果我们不创建一个新的信号量集,而只是访问一个已存在的集合,那就可以把该参数指定为0.

	if((key=ftok(argv[optind],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!\n");
		exit(1);
	}
	if((semid=semget(key,nsems,oflag))==-1)//semget函数创建一个信号量集或者访问一个已存在的信号量集.
	{
		perror("semget wrong!");
		exit(1);
	}
	exit(0);
	
}
