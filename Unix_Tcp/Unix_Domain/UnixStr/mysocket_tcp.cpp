#include <sys/socket.h>//accept,listen,bind,connect
#include <unistd.h>//close
#include <stdlib.h>//atoi,getenv
#include <errno.h>//errno,ECONNABORTED

#include "myunp.h"


void * Malloc(unsigned int num_bytes)
{
	void * ptr=malloc(num_bytes);
	if (ptr==NULL)
	{
		err_quit("Malloc error!");
	}
	return ptr;
}
pid_t Fork(void)
{
	pid_t t=fork();
	if (t==-1)
	{
		err_sys("Fork error!");
	}
	return t;
}

void Fputs(const char *ptr, FILE *stream)
{
	if (fputs(ptr, stream) == EOF)
		err_sys("fputs error");
}

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
	int	n;

	if ( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
		err_sys("select error");
	return(n);		/* can return 0 on timeout */
}


int Getpeername(int sockfd,struct sockaddr *peeraddr,socklen_t *addrlen)
{
	int n;
	if ((n=getpeername(sockfd,peeraddr,addrlen))!=0)
	{
		err_sys("Getpeername error!");
	}
	return n;
}

void Write(int fd, void *ptr, size_t nbytes)
{
	if (write(fd, ptr, nbytes) != nbytes)
		err_sys("Write error!");
}

ssize_t	writen(int fd, const void *vptr, size_t n)     /* Write "n" bytes to a descriptor. */
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = (const char *)vptr;
	nleft = n;
	while (nleft > 0) 
	{
		if ( (nwritten = write(fd, ptr, nleft)) <= 0) 
		{
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;		/* and call write() again */
			else
				return(-1);			/* error */
		}

		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(n);
}
/* end writen */
void Writen(int fd, void *ptr, size_t nbytes)
{
	if (writen(fd, ptr, nbytes) != nbytes)
		err_sys("writen error");
}


ssize_t Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t		n;

	if ( (n=read(fd, ptr, nbytes))== -1)
		err_sys("read error");
	return(n);
}

int Socket(int family, int type, int protocol)
{
	int		n;

	if ( (n = socket(family, type, protocol)) < 0)
		err_sys("socket error");
	return(n);
}
/* end Socket */

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		err_sys("bind error");
}


void Shutdown(int fd, int how)
{
	if (shutdown(fd, how) < 0)
		err_sys("shutdown error");
}

int Close(int fd)
{
	int i;
	if(-1==(i=close(fd)))
		err_ret("Close error!");
	return i;
}

int Setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t optlen)
{
	int i;
	if (-1==(i=setsockopt(sockfd,level,optname,optval,optlen)))
	{
		err_ret("Setsockopt error!");
	}
	return i;
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		err_sys("connect error");
}

void Listen(int fd,int backlog)
{
	char * ptr;

	if ((ptr=getenv("LISTENQ"))!=NULL)
	{
		backlog=atoi(ptr);
	}
	if (listen(fd,backlog)<0)
	{
		err_sys("Listen error!");
	}
}

int Accept(int sockfd,struct sockaddr *cliaddr,socklen_t *addrlen)
{
	int n;
again:	
	if ((n=accept(sockfd,cliaddr,addrlen))==-1)
	{
#ifdef EPROTO
		if(errno==EPROTO||errno==ECONNABORTED)
#else
		if (errno==ECONNABORTED)
#endif
			goto again;
		else
			err_sys("accept error!");
	}
	return n;
} 