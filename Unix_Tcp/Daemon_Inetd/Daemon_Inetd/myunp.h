#ifndef MYUNP_H
#define MYUNP_H

#include <sys/socket.h>//socklen_t,size_t

extern int daemon_proc; //defined in myerror.cpp 
void daemon_inetd(const char *pname,int facility);
void * Malloc(unsigned int num_bytes);
int Getpeername(int sockfd,struct sockaddr *peeraddr,socklen_t *addrlen);
void err_msg(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_quit(const char *fmt, ...);
void err_ret(const char *fmt, ...);
char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);
void Write(int fd, void *ptr, size_t nbytes);
int Close(int fd);
#endif //MYUNP_H
