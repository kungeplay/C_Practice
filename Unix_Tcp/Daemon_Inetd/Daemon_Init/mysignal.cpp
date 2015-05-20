#include <signal.h>  //sigaction,SIG_ERR,

#include "myunp.h"

Sigfunc * signal(int signo,Sigfunc *func)
{
	struct sigaction act,oact;

	act.sa_handler=func;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;

	if (signo==SIGALRM)
	{
#ifdef SA_INTERRUPT
		act.sa_flags|=SA_INTERRUPT;//SunOs 4.x
#endif		
	}
	else
	{
#ifdef SA_RESTART
		act.sa_flags|=SA_RESTART;//SVR4, 4.4BSD
#endif

	}
	if (sigaction(signo,&act,&oact)<0)
	{
		return (SIG_ERR);
	}
	return (oact.sa_handler);
}

Sigfunc * Signal(int signo,Sigfunc *func) //for our signal() function
{
	Sigfunc *sigfunc;
	if ( (sigfunc=signal(signo,func)) ==SIG_ERR)
	{
		err_sys("signal error");
		return (sigfunc);
	}
}