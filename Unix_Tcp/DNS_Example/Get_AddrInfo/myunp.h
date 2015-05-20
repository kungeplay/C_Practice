#include <stdarg.h>//va_list
#include <sys/socket.h>//socklen_t,ssize_t
#ifndef MYUNP_H
#define MYUNP_H
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

/* Print message and return to caller
 * Caller specifies "errnoflag" and "level" */

static void err_doit(int errnoflag, int level, const char *fmt, va_list ap);

////////////////////////
char * sock_ntop_host(const struct sockaddr* sockaddr,socklen_t addrlen);
char * Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
/////////////////////////
ssize_t readn(int fd,void *vptr,size_t n); //UNIX Network Programming P72
ssize_t writen(int fd,const void *vptr,size_t n);
///////////////////////
#endif
