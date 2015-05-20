#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>

//通过semop函数对某个信号量集执行一组数组的操作.
int main(int argc,char *argv[])
{
	int c,i,flag,semid,nops;
	struct sembuf *ptr;
	key_t key;
	flag=0;
	while((c=getopt(argc,argv,"nu"))!=-1)//注意特殊的"--"格式会导致getopt停止处理选项并返回-1.这允许用户传递以"-"开头但不是选项的参数.
	{
		switch(c)
		{
			case 'n':
				flag|=IPC_NOWAIT;	/*for each operation*/
				break;
			case 'u':
				flag|=SEM_UNDO;		/*for each operation*/
				break;
		}
	}
	if(argc-optind<2)	/*argc-optind=#args remaining*/
	{
		printf("usage: semops [-n] [-u] <pathname> <--> operation ...\n");
		exit(1);
	}

	if((key=ftok(argv[optind],0))==-1)//注意路径名必须是已经存在于文件系统中的文件路径
	{
		perror("ftok wrong!\n");
		exit(1);
	}
	if((semid=semget(key,0,0))==-1)//semget函数创建一个信号量集或者访问一个已存在的信号量集.
	{
		perror("semget wrong!");
		exit(1);
	}
	optind++;
	nops=argc-optind;	//要操作的信号量个数

	/*allocate memory to hold operations,store,and perform*/
	if((ptr=calloc(nops,sizeof(struct sembuf)))==NULL)
	{
		perror("calloc wrong!");
		exit(1);
	}
	for(i=0;i<nops;i++)
	{
		ptr[i].sem_num=i;
		ptr[i].sem_op=atoi(argv[optind+i]);	/*<0,0,or >0*/
		ptr[i].sem_flg=flag;
	}
	if(semop(semid,ptr,nops)==-1)
	{
		perror("semop wrong!");
		exit(1);
	}
	exit(0);
}
