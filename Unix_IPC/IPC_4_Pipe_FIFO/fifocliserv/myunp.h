#ifndef MYUNP_H
#define MYUNP_H

#include <unistd.h>
#include <stdio.h>
int Close(int fd);

void Write(int, void *, size_t);
ssize_t	 Read(int, void *, size_t);

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
