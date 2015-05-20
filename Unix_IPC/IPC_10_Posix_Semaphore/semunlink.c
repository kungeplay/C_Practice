#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
//此程序用来删除一个有名信号量
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("usage:semunlink <name>\n");
		exit(1);
	}
	if(sem_unlink(argv[1])==-1)
	{
		perror("sem_unlink wrong!");
		exit(1);
	}
	exit(0);
}
