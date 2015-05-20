#include "myunp.h"
#include <unistd.h>//read,write,close
#include <errno.h>//error,EINTR

#include <stdio.h>

ssize_t readn(int fd,void *vptr,size_t n) //UNIX Network Programming P72
{    
//这个函数有个bug，若收到的字节数和小于n，而有没有信号产生，则一直阻塞在read里
//故我暂时在代码里没用到这个函数
	size_t nleft;
	ssize_t nread;
	char *ptr;
	ptr=(char *)vptr;
	nleft=n;
	while(nleft>0)
	{
		if((nread=read(fd,ptr,nleft))<0)
		{
			if(errno==EINTR)
				nread=0; //and call read() again;
			else
				return (-1);
		}
		else if (nread==0)
			break; //EOF
		nleft-=nread;
		ptr  +=nread;
	}
	return (n-nleft);
}
ssize_t writen(int fd,const void *vptr,size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr=(const char *)vptr;
	nleft=n;
	while(nleft>0)
	{
		if ((nwritten==write(fd,ptr,nleft))<=0)
		{
			if (nwritten<0&&errno==EINTR)
			{
				nwritten=0;
			}
			else
				return (-1);
		}
		nleft-=nwritten;
		ptr+=nwritten;
	}
	return (n);
}
