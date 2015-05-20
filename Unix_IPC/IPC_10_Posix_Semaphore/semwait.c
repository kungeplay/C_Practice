#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>

int main(int argc,char *argv[])
{
	sem_t *sem;
	int val;
	if(argc!=2)
	{
		printf("usage: semwait <name>");
		exit(1);
	}
	if((sem=sem_open(argv[1],0))==SEM_FAILED)
	{
		perror("sem_open wrong!");
		exit(1);
	}
	if(sem_wait(sem)==-1)
	{
		if(errno==EINTR)
		{
			printf("sem_wait meet with signal\n");
			exit(1);
		}
		perror("sem_wait wrong!");
		exit(1);
	}
	if(sem_getvalue(sem,&val)==-1)
	{
		perror("sem_getvalue wrong!");
		exit(1);
	}
	printf("pid %ld has semaphore, value=%d\n",getpid(),val);
	pause();	//blocks until killed
	exit(0);
}
