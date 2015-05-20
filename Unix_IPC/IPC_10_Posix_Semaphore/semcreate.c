#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
//下面的程序创建一个有名信号量，允许的命令行选项有指定独占创建的-e和指定一个初始值(默认值1以外的值)的i。 注意编译时要加上-lrt,其中sem_open第一个路径名字参数必须以'/'开头且有且只有一个'/'.详细情况见man sem_overview 
#define	FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
int main(int argc,char *argv[])
{
	int c,flags;
	sem_t *sem;
	unsigned int value;
	//flags=O_RDWR|O_CREAT;
	flags=O_CREAT;//实际上只要这样就可以了，系统要求对某个已存在的信号量都具有读访问和写访问权限。
	value=1;
	while((c=getopt(argc,argv,"ei:"))!=-1)
	{
		switch(c)
		{
			case 'e':
				flags|=O_EXCL;
				break;
			case 'i':
				value=atoi(optarg);
				break;

		}
	}
	if(optind!=argc-1)
	{
		printf("usage: semcreate [-e] [-i initalvalue] <name>\n");
		exit(1);
	}
	if((sem=sem_open(argv[optind],flags,FILE_MODE,value))==SEM_FAILED)//注意#define SEM_FAILED      ((sem_t *) 0)，这点比较特殊
	{
		perror("sem_open wrong!");
		exit(1);
	}
	if(sem_close(sem)==-1)
	{
		perror("sem_close wrong!\n");
		exit(1);
	}
	exit(0);
}
