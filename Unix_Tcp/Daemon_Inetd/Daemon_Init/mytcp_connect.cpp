#include <netdb.h>//gai_strerror,freeaddrinfo,getaddrinfo
#include <sys/socket.h>
#include <string.h>
#include "myunp.h"

int tcp_connect(const char *host,const char *serv)
{
	int sockfd,n;
	struct addrinfo hints,*res,*ressave;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;

	if ((n=getaddrinfo(host,serv,&hints,&res))!=0)
	{
		err_quit("tcp_connect error for %s,%s:%s",host,serv,gai_strerror(n));
	}
	ressave=res;

	do
	{
		sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
		if (sockfd<0)
		{
			continue; //ignore this one
		}

		if (connect(sockfd,res->ai_addr,res->ai_addrlen)==0)
		{
			break; //success
		}
		Close(sockfd); //ignore this one
	}
	while((res=res->ai_next)!=NULL);

	if (res==NULL)
	{
		err_sys("tcp_connect error for %s,%s",host,serv);
	}

	freeaddrinfo(ressave);

	return(sockfd);

}

int Tcp_connect(const char *host,const char *serv)
{
	return(tcp_connect(host,serv));
}