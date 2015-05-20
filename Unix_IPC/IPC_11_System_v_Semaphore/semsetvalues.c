#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
/*设置某个信号量集中的所有值*/
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

	if(argc<2)
	{
		printf("usage:semsetvalues <pathname> [values ...]\n");
		exit(1);
	}

	//first get the number of semaphores in the set
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
	if((semctl(semid,0,IPC_STAT,arg))==-1)
	{
		perror("semctl wrong!");
		exit(1);
	}
	nsems=arg.buf->sem_nsems;//获取信号量集中信号量的个数

	/*now get the values from the command line*/
	if(argc!=nsems+2)
	{
		printf("%d semaphores in set, %d values specified\n",nsems,argc-2);
		exit(1);
	}

	/*allocate memory to hold all the values in the set,and store*/
	if((ptr=calloc(nsems,sizeof(unsigned short)))==NULL)
	{
		perror("calloc wrong!");
		exit(1);
	}
	arg.array=ptr;
	for(i=0;i<nsems;i++)
	{
		ptr[i]=atoi(argv[i+2]);
	}

	if((semctl(semid,0,SETALL,arg))==-1)
	{
		perror("semctl wrong!");
		exit(1);
	}

	exit(0);

}
