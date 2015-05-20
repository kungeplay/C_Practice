#ifndef MYUNP_H
#define MYUNP_H

#include <unistd.h>
#include <stdio.h>

#define SA struct sockaddr
extern int daemon_proc;

typedef void Sigfunc(int);
Sigfunc * Signal(int signo,Sigfunc *func);


pid_t Fork(void);
void * Malloc(unsigned int num_bytes);
int Setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t optlen);
int Close(int fd);
void Listen(int fd,int backlog);
int Accept(int sockfd,struct sockaddr *cliaddr,socklen_t *addrlen);
void Write(int, void *, size_t);
ssize_t	 Read(int, void *, size_t);
int Getpeername(int sockfd,struct sockaddr *peeraddr,socklen_t *addrlen);

void Fputs(const char *ptr, FILE *stream);

char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);
char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);

int Tcp_listen(const char * host,const char * serv,socklen_t *addrlenp);
int Tcp_connect(const char *host,const char *serv);




int daemon_init(const char *pname,int facility);

/* Nonfatal error related to system call
 * Print message and return */

void err_ret(const char *fmt, ...);

/* Fatal error related to system call
 * Print message and terminate */

void err_sys(const char *fmt, ...);

/* Fatal error related to system call
 * Print message, dump core, and terminate */

void err_dump(const char *fmt, ...);

/* Nonfatal error unrelated to system call
 * Print message and return */

void err_msg(const char *fmt, ...);

/* Fatal error unrelated to system call
 * Print message and terminate */

void err_quit(const char *fmt, ...);
#endif