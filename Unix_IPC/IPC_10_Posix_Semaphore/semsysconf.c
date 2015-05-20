#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//sysconf
//此程序用于调用sysconf输出信号量的两个由实现定义的限制值。SEM_NSEMS_MAX:一个进程可以同时打开着的最大信号量数；SEM_VALUE_MAX：一个信号量的最大值；
//结果发现在我的Centos系统中通过sysconf无法获取，返回-1.
int main(int argc,char *argv)
{
	long nsemsmax,valuemax;
	if((nsemsmax=sysconf(_SC_SEM_NSEMS_MAX))==-1)
	{
		perror("sysconf wrong!1");
		exit(1);
	}
	if((valuemax=sysconf(_SC_SEM_VALUE_MAX))==-1)
	{
		perror("sysconf wrong!");
		exit(1);
	}
	printf("SEM_NSEMS_MAX=%ld,SEM_VALUE_MAX=%ld\n",nsemsmax,valuemax);
	exit(0);
}
