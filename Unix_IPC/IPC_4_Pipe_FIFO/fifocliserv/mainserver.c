#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>//open,O_RDONLY
#include "myunp.h"

#define MAXLINE 200
#define SERV_FIFO "/tmp/fifo.serv"
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)/*default permissions for new files*/

int main(int argc,char *argv[])
{
	int readfifo,writefifo,dummyfd,fd;
	char *ptr,buff[MAXLINE+1],fifoname[MAXLINE];
	pid_t pid;
	ssize_t n;
	/* create server's well-known FIFO;OK if already exists*/
	if((mkfifo(SERV_FIFO,FILE_MODE)<0)&&(errno!=EEXIST))
	{
		err_sys("can't create %s",SERV_FIFO);
	}

							/*open server's well-known FIFO for reading and writing*/
	readfifo=open(SERV_FIFO,O_RDONLY,0);
	dummyfd=open(SERV_FIFO,O_WRONLY,0);		/*never used*/

	while((n=read(readfifo,buff,MAXLINE))>0)	/*读到的内容为"pid filename"*/
	{
		if(buff[n-1]=='\n')
			n--;				/*delete newline from readline()*/
		buff[n]='\0';				/*null terminate pathname*/

		if((ptr=strchr(buff,' '))==NULL)		/*strchr找出字符串str中第一次出现字符串str的位置，返回该字符串位置的指针*/
		{
			err_msg("bogus request:%s",buff);
			continue;
		}
		*ptr++=0;				/*null terminate PID,ptr=pathname*/
		pid=atol(buff);
		snprintf(fifoname,sizeof(fifoname),"/tmp/fifo.%ld",(long)pid);
		if((writefifo=open(fifoname,O_WRONLY,0))<0)
		{
			err_msg("cannot open:%s",fifoname);
			continue;
		}
		if((fd=open(ptr,O_RDONLY))<0)		/*获取服务器端要读取的文件名*/
		{
							/*error :must tell client*/
			snprintf(buff+n,sizeof(buff)-n,":can't open,%s\n",strerror(errno));
			n=strlen(ptr);
			write(writefifo,ptr,n);
			close(writefifo);
		}
		else
		{
							/*open succeeded:copy file to FIFO*/
			while((n=read(fd,buff,MAXLINE))>0)
				write(writefifo,buff,n);
			close(fd);
			close(writefifo);
		}


	}
	exit(0);
}
