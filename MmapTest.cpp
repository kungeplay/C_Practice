#include <sys/mman.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <map>
using namespace std;

//测试进程间同步，父进程与子进程同时使全局变量增加.使用匿名内存映射来实现进程间共享内存区
//因为pthread并非Linux系统的默认库，编译时注意加上-lpthread参数，以调用链接库
//g++ ./MmapTest.cpp -o MmapTest -lpthread
struct shared{
	sem_t mutex;
	int count;
} shared;

struct shared *ptr;
void ChildProcess(int nloop)
{
		for (int i = 0; i < nloop; ++i)
		{
			sem_wait(&ptr->mutex);
			printf("child: %d\n",ptr->count++);
			//if (i>nloop-5)
			//{
			//	break;
			//}
			sem_post(&ptr->mutex);
		}
}

int main(int argc, char const *argv[])
{
	int i,nloop;
	int fd;
	//struct shared *ptr;
	if(argc!=2)
	{
		printf("useage: MmapTest <loops>\n");
		exit(1);
	}
	nloop=atoi(argv[1]);
	

	ptr=(struct shared *)mmap(NULL,sizeof(struct shared),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
	
	sem_init(&ptr->mutex,1,1);
	setbuf(stdout,NULL);
	if (fork()==0)
	{
		ChildProcess(nloop);
		exit(0);
	}

	//parent
	for (int i = 0; i < nloop; ++i)
	{
		sem_wait(&ptr->mutex);
		printf("parent: %d\n",ptr->count++ );
		sem_post(&ptr->mutex);
	}
	return 0;
}