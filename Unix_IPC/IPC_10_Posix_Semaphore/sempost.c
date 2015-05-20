#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
int main(int argc,char *argv[])
{
	sem_t *sem;
	int val;
	if(argc!=2)
	{
		printf("usage: sempost <name>\n");
		exit(1);
	} 
	if((sem=sem_open(argv[1],0))==SEM_FAILED)
	{
		perror("sem_open wrong!");
		exit(1);
	}
	if(sem_post(sem)==-1)
	{
		perror("sem_post wrong!\n");
		exit(1);
	}

	if(sem_getvalue(sem,&val)==-1)
	{
		perror("sem_getvalue wrong!");
		exit(1);
	}
	printf("value= %d\n",val);
	exit(0);
}
