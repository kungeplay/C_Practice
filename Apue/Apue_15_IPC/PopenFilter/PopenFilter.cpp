#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>//write
#include <stdlib.h>//exit
/*
 *利用Popen和pclose，调用大写/小写过滤程序读取命令的一个程序
 *使用popen,可以在应用程序和输入之间插入一个程序以便对输入进行变换处理。
 *此程序将标准输入复制到标准输出，在复制时将大写字符变换为小写字符。
 */
#define MAXLINE 200
void err_sys(const char * fmt)
{
	char buf[MAXLINE];
	snprintf(buf,MAXLINE-1,fmt);
	snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1," :%s ",strerror(errno));
	strcat(buf,"\n");
	fflush(stdout);//in case stdout and stderr are the same
	fputs(buf,stderr);
	fflush(NULL);//flushes all stdio output streams

}
int main(int argc,char * argv[])
{
	FILE * fpin;
	const char execfile[]="./myuclc";
	char buf[MAXLINE];
	if((fpin=popen(execfile,"r"))==NULL)
		err_sys("popen error");
	for(;;)
	{
		fputs("PopenFilter>",stdout);
		fflush(stdout);//因为标准输出通常是行缓冲的，所以在写了提示之后，需要调用fflush，注意此处若不掉用fflush,则以后也不不会输出上一句输出到标准输出的内容不明白为什么,好像是由于下面并没有使用fflush刷新缓冲区,write并不使用缓冲区
		if((fgets(buf,MAXLINE,fpin))==NULL)
			break;
		write(STDOUT_FILENO,buf,strlen(buf));
	}
	if(pclose(fpin)==-1)
		err_sys("pclose error");
	putchar('\n');
	exit(0);
}
