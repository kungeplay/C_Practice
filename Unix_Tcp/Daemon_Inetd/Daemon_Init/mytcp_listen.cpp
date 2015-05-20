#include <netdb.h> //gai_strerror
#include <string.h>//memset,


#include "myunp.h"


#define LISTENQ 20


int tcp_listen(const char * host,const char * serv,socklen_t *addrlenp)
{
	const int on=1;
	int listenfd,n;
	struct addrinfo hints,*res,*ressave;

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_flags=AI_PASSIVE;
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;

	if ((n=getaddrinfo(host,serv,&hints,&res))!=0)
	{
		err_quit("tcp_listen error for %s, %s :%s",host,serv,gai_strerror(n));
	}

	ressave=res;

	do
	{
		listenfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
		if (listenfd<0)
		{
			continue; //error,try next one
		}

		Setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
		if (bind(listenfd,res->ai_addr,res->ai_addrlen)==0)
		{
			break; //success
		}
		Close(listenfd); //bind error,close and try next one
	}while((res=res->ai_next)!=NULL);

	if (res==NULL)
	{
		err_sys("tcp_listen error for %s, %s",host,serv);
	}

	Listen(listenfd,LISTENQ);

	if(addrlenp)
		*addrlenp=res->ai_addrlen; //return size of protocol address

	freeaddrinfo(ressave);

	return listenfd;

}

int Tcp_listen(const char * host,const char * serv,socklen_t *addrlenp)
{
	return(tcp_listen(host,serv,addrlenp));
}