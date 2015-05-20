#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
//取得并输出某个信号量集中的所有值.
union semun 
{
	int val;	/*used for SETVAL only*/
	struct semid_ds *buf;	/*used for IPC_SET and IPC_STAT*/
	ushort *array;		/*used for GETALL and SETALL*/
};
int main(int argc,char *argv[])
{
	int semid,nsems,i;
	struct semid_ds seminfo;
	unsigned short *ptr;
	union semun arg;
	key_t key;
	if(argc!=2)
	{
		printf("usage:semgetvalues <pathname>");
		exit(1);
	}
	/*first get the number of semaphores in the set*/
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
	arg.buf=&seminfo;
	if((semctl(semid,0,IPC_STAT,arg))==-1)//(通过arg.buf参数)返回所指定信号量集当前的semid_ds结构.注意,调用者必须首先分配一个semid_ds结构,并把arg.buf设置成指向这个结构.
	{
		perror("semctl wrong!");
		exit(1);
	}
	nsems=arg.buf->sem_nsems;

	/*allocate memory to hold all the values in the set*/
	if((ptr=calloc(nsems,sizeof(unsigned short)))==NULL)
	{
		perror("calloc wrong!");
		exit(1);
	}
	arg.array=ptr;

	/*fetch the values and print*/
	if((semctl(semid,0,GETALL,arg))==-1)//GETALL 返回所指定信号量集内每个成员的semval值.这些值通过arg.array指针返回,函数本身的返回值则为0.
	{
		perror("semctl wrong!");
		exit(1);
	}
	for(i=0;i<nsems;i++)
	{
		printf("semval[%d]=%d\n",i,ptr[i]);
	}
	exit(0);
}
