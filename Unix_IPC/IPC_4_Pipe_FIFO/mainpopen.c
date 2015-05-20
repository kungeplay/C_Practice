#include <stdio.h>
#include <unistd.h>
#define MAXLINE 1024
//此程序为P39 4.5节中的一个客户服务器例子的实现，使用popen函数和Unix的cat程序。路径名从标准输入读出，随后构建一个命令并把它传递给popen。来自shell或cat程序的输出被复制到标准输出。
int main (int argc, char * argv[])
{
	size_t n;
	char buff[MAXLINE],command[MAXLINE];
	FILE *fp;
	/*read pathname*/
	fgets(buff,MAXLINE,stdin);
	n=strlen(buff);//fgets() guarantees null byte at end
	if(buff[n-1]=='\n')
		n--;	//delete newline from fgets()常规下fgets()函数不会读进换行符
	snprintf(command,sizeof(command),"cat %s",buff);
	fp=popen(command,"r");
	//copy from pipe to standard output
	while(fgets(buff,MAXLINE,fp)!=NULL)
		fputs(buff,stdout);
	pclose(fp);
	exit(0);
}
