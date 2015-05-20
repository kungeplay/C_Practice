#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#define MAXLINE 200
#define UNIXSTR_PATH "/tmp/ServUnixStrTest" 
typedef void Sigfunc(int);
int Socket(int family, int type, int protocol);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen); 
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd,int backlog);
Sigfunc * Signal(int signo,Sigfunc *func);
int Close(int fd);
void Shutdown(int fd, int how);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Write(int fd, void *ptr, size_t nbytes);
void Writen(int fd, void *ptr, size_t nbytes);
void err_sys(const char *fmt, ...);
void err_quit(const char *fmt, ...);
void err_ret(const char *fmt, ...);
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,struct timeval *timeout);
