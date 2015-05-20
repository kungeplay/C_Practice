#include <sys/socket.h>

void err_quit(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_ret(const char *fmt, ...);
char * Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void * Malloc(unsigned int num_bytes);
int Socket(int family, int type, int protocol);
void * Calloc(size_t n, size_t size);