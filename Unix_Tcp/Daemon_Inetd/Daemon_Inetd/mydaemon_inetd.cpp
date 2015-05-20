#include "myunp.h"
#include <syslog.h>
extern int daemon_proc; //defined in myerror.cpp
void daemon_inetd(const char *pname,int facility)
{
	daemon_proc=1;	// for our err_XXX() functions
	openlog(pname,LOG_PID,facility);
}