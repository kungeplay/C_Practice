#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
//从系统中删除一个信号量集,删除该集合通过调用semctl函数执行IPC_RMID命令完成.
int main(int argc,char *argv[])
{
	int semid;
	key_t key;
	if(argc!=2)
	{
		printf("usage: semrmid <pathname>\n");
		exit(1);
	}

	if((key=ftok(argv[1],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!\n");
		exit(1);
	}
	if((semid=semget(key,0,0))==-1)//访问一个已存在的信号量集合,可以把第二个参数指定为0
	{
		perror("semget wrong!");
		exit(1);
	}
	if((semctl(semid,0,IPC_RMID))==-1)
	{
		perror("semctl wrong!");
		exit(1);
	}

	exit(0);
}

