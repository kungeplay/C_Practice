#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//对环境变量进行操作
int main(int argc,char * argv[])
{
	char * temp;
	char var[20];
	printf("Please the variable name:");
	fgets(var,20,stdin);
	var[strlen(var)-1]=0;//删去最后一个读入的换行符
	temp=getenv(var);
	printf("%s\n",temp );
}