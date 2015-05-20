#include <stdio.h>
#include <string.h>
#include <stdlib.h>//exit
#include <errno.h>
#include <sys/mman.h>//mmap,munmap,mprotect,msync
#include <fcntl.h>//open
#include <sys/stat.h>//fstat
#include <stdarg.h>
#include <unistd.h>//ftruncate
/*此程序用存储映射I/O复制文件
 */
#define COPYINCR (1024*1024*10)//10MB
#define MAXLINE 200
void err_sys(const char * fmt, ...)
{
	char buf[MAXLINE];
	va_list ap;
	va_start(ap,fmt);
	vsnprintf(buf,MAXLINE-1,fmt,ap);
	snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1," :%s ",strerror(errno));
	strcat(buf,"\n");
	fflush(stdout);//in case stdout and stderr are the same
	fputs(buf,stderr);
	fflush(NULL);//flushes all stdio output streams
	va_end(ap);
}
void err_quit(const char * fmt, ...)
{
	char buf[MAXLINE];
	va_list ap;
	va_start(ap,fmt);
	vsnprintf(buf,MAXLINE-1,fmt,ap);
	strcat(buf,"\n");
	fflush(stdout);//in case stdout and stderr are the same
	fputs(buf,stderr);
	fflush(NULL);//flushes all stdio output streams
	va_end(ap);
	exit(1);
}

int main(int argc,char *argv[])
{
	int fdin,fdout;
	void *src,*dst;
	size_t copysz;
	struct stat sbuf;
	off_t fsz=0;

	if(argc!=3)
		err_quit("useage:%s<fromfile> <tofile>",argv[0]);
	if((fdin=open(argv[1],O_RDONLY))<0)
		err_sys("can't open %s for reading",argv[1]);
	if((fdout=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR))<0)
		err_sys("can't create %s for writing",argv[2]);
	if(fstat(fdin,&sbuf)<0)	//need size of input file
		err_sys("fstat error");
	printf("%s size:%d\n",argv[0],sbuf.st_size);
	if(ftruncate(fdout,sbuf.st_size)<0)	//set output file size
		err_sys("ftruncate error");

	while(fsz<sbuf.st_size)
	{
		if((sbuf.st_size-fsz)>COPYINCR)
			copysz=COPYINCR;
		else
			copysz=sbuf.st_size-fsz;

		//void *mmap(void *addr,size_t len,int prot,int flag,int fd,off_t off)
		//addr参数用于指定映射存储区的起始地址。通常将其设置为0，这表示由系统选择该映射区的起始地址。此函数的返回值是该映射区的起始地址。
		//fd参数是指定要被映射文件的描述符。在文件映射到地址空间之前，必须先打开该文件。len参数是映射的字节数
		//off是要映射字节在文件中的起始偏移量。prot参数指定了映射存储区的保护要求。
		if((src=mmap(0,copysz,PROT_READ,MAP_SHARED,fdin,fsz))==MAP_FAILED)
			err_sys("mmap error for input");
		if((dst=mmap(0,copysz,PROT_READ|PROT_WRITE,MAP_SHARED,fdout,fsz))==MAP_FAILED)
			err_sys("mmap error for output");
		//close(fdin);//在此处关闭文件并不影响下面两个文件的复制操作，但是若一次没有复制完，再循环的时候，mmap操作由于文件描述符已关闭会失败。
		//close(fdout);

		memcpy(dst,src,copysz);  //does the file copy

		//当进程终止时，会自动解除存储映射区的映射，或者直接调用munmap函数也可以解除映射区。关闭映射存储区时使用的文件描述符并不解除映射区。
		munmap(src,copysz);
		munmap(dst,copysz);
		fsz+=copysz;
	}
	exit(0);
}
