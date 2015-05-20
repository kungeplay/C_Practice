#include <stdio.h>
#include <stdlib.h>

#define SEM_NAME "/mysem" 
int main(int argc,char *argv[])
{
	int fd,i,nloop,zero=0;
	int *ptr;
	sem_t *mutex;
	if(argc!=3)
	{
		printf("usage: incr2 <pathname> <#loops>\n");
		exit(1);
	}
	nloop=atoi(argv[2]);

	/*open file,initialize to 0,map into memroy*/
	fd=open(argv[1],O_RDWR|O_CREAT,FILE_MODE);
	Write(fd,&zero,sizeof(int));
	ptr=Mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	Close(fd);
	/*create initialzie,and unlink semaphore*/
	mutex=Sem_open(SEM_NAME,O_CREAT|O_EXCL,FILE_MODE,1);
	Sem_unlink(SEM_NAME);

	setbuf(stdout,NULL); /*stdout is unbuffered*/
	if(fork()==0)
	{
		for(i=0;i<nloop;i++)
		{
			Sem_wait(mutext);
			printf("child:%d\n",(*ptr)++);
			Sem_post(mutex);
		}
		exit(0);
	}
	/*parent*/
	for(i=0;i<nloop;i++)
	{
		Sem_wait(mutext);
		printf("parent:%d\n",(*ptr)++);
		Sem_post(mutex);
	}
	exit(0);
}
