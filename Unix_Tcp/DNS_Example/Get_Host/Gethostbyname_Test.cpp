//这个程序用来检测gethostbyname函数的用法
//它为任意数目的命令行参数调用gethostbyname,并显示所有信息。
//经过发现，当参数为例如 www.baidu.com ,www.163.com这样的域名时可以正确的解析出来。
#include <stdio.h>//perror,
#include <stdlib.h>//perror,
#include <netdb.h> //gethostbyname
#include <errno.h>//errno
#include <stdarg.h>
#include <syslog.h>
#include <string.h>//strlen,strerror,strcat
#include <arpa/inet.h> //inet_pton,inet_ntop,

#define MAXLINE 200

int daemon_proc;
static void err_doit(int, int, const char *,va_list);

/*Nonfatal error related to system call
*Print message and return
*/
void err_ret(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(0,LOG_INFO,fmt,ap);
	va_end(ap);
	return;
}
/* Nonfatal error unrelated to system call
 * Print message and return
*/
 void err_msg(const char * fmt, ...)
 {
 	va_list ap;
 	va_start(ap,fmt);
 	err_doit(0,LOG_INFO,fmt,ap);
 	va_end(ap);
 	return;
 }

/*
Print message and  return to caller
Caller specifies "errnoflag" and "level"
*/
static void err_doit(int errnoflag,int level,const char *fmt,va_list ap)
{
	int errno_save,n;
	char buf[MAXLINE+1];

	errno_save=errno;
#ifdef HAVE_VSNPRINTF
	vsnprintf(buf,MAXLINE,fmt,ap);//safe
#else
	vsprintf(buf,fmt,ap);
#endif
	n=strlen(buf);
	if(errnoflag)
		snprintf(buf+n,MAXLINE-n,": %s",strerror(errno_save));
	strcat(buf,"\n");
	if (daemon_proc)
	{
		syslog(level,buf);
	}
	else
	{
		fflush(stdout);
		fputs(buf,stderr);
		fflush(stderr);
	}
	return;




}
int main(int argc, char const *argv[])
{
	 char const *ptr;
	 char **pptr;
	char str[INET_ADDRSTRLEN];
	struct hostent *hptr;
	while(--argc>0)
	{
		ptr=*++argv;
		if ((hptr=gethostbyname(ptr))==NULL)
		{
			err_msg("gethostbyname error for host: %s:%s",ptr,hstrerror(h_errno));
			continue;
		}
		printf("official hostname:%s\n",hptr->h_name );
		for(pptr=hptr->h_aliases;*pptr!=NULL;pptr++)
			printf("\talias:%s\n",*pptr );
		switch(hptr->h_addrtype)
		{
			case AF_INET:
				pptr=hptr->h_addr_list;
				for(;*pptr!=NULL;pptr++)
					printf("\taddress:%s\n", inet_ntop(hptr->h_addrtype,*pptr,str,sizeof(str)));
				break;
			default:
				err_ret("unknown address type");
				break;
		}
	}
	return 0;
}
