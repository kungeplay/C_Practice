#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
//此简单程序打开一个有名信号量，取得它的当前值，然后输出该值。
int main(int argc,char *argv[])
{
	sem_t * sem;
	int val;
	if(argc!=2)
	{
		printf("usage: semgetvalue <name>\n");
		exit(1);
	}
	if((sem=sem_open(argv[1],0))==SEM_FAILED)//注意在系统中#define SEM_FAILED      ((sem_t *) 0),此外,sem_open的第二个参数为0，因为我们不指定O_CREATE,也没有其他O_XXX常值需指定。
	{
		perror("sem_open wrong!");
		exit(1);
	}
	if(sem_getvalue(sem,&val)==-1)
	{
		perror("sem_getvalue wrong!\n");
		exit(1);
	}
	printf("value=%d\n",val);
	exit(0);
}
