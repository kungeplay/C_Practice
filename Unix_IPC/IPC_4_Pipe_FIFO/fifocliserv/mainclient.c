#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include "myunp.h"

#define MAXLINE 200
#define SERV_FIFO "/tmp/fifo.serv"
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)/*default permissions for new files*/
int main(int argc,char * argv[])
{
	int readfifo,writefifo;
	size_t len;
	ssize_t n;
	char *ptr,fifoname[MAXLINE],buff[MAXLINE];
	pid_t pid;
	/*create FIFO with our PID as part of name*/
	pid=getpid();
	snprintf(fifoname,sizeof(fifoname),"/tmp/fifo.%ld",(long)pid);
	if((mkfifo(fifoname,FILE_MODE)<0)&&errno!=EEXIST)
		err_sys("can't create %s",fifoname);
	/*start buffer with pid and a blank*/
	snprintf(buff,sizeof(buff),"%ld ",(long)pid);
	len=strlen(buff);
	ptr=buff+len;
	/*read pathname*/
	fgets(ptr,MAXLINE-len,stdin);/*fgets() guarantees null byte at end*/
	len=strlen(buff);
	/*open FIFO to server and write PID and pathname to FIFO*/
	writefifo=open(SERV_FIFO,O_WRONLY,0);
	write(writefifo,buff,len);
	/*now open our FIFO;blocks until server opens for writing*/
	readfifo=open(fifoname,O_RDONLY,0);
	/*read from IPC,write to standard output*/
	while((n=read(readfifo,buff,MAXLINE))>0)
		write(STDOUT_FILENO,buff,n);
	close(readfifo);
	unlink(fifoname);
	exit(0);

}
