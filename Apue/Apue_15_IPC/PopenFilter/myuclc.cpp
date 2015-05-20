#include <stdio.h>
#include <ctype.h>//isupper,tolower
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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
	int c;
	while((c=getchar())!=EOF)
	{
		if(isupper(c))
			c=tolower(c);
		if(putchar(c)==EOF)
			err_sys("output error");
		if(c=='\n')
			fflush(stdout);//因为标准输出通常是行缓冲的，所以需要调用fflush.
	}
	exit(0);
}
