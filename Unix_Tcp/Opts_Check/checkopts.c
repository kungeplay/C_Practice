/*
 * 检测本机套接字的一些选项是否受支持，并获取默认值
 */
#include <stdio.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
 #include <unistd.h> //close
union val{
 	int i_val;
 	long l_var;
 	struct linger linger_val;
 	struct timeval timeval_var;
 }val;
 static char * sock_str_flag(union val*,int);
 static char * sock_str_int(union val*,int);
 static char * sock_str_linger(union val*,int);
 static char* sock_str_timeval(union val*,int);

 int Socket(int family,int type,int protocol);

 struct sock_opts
 {
 	const char * opt_str;
 	int opt_level;
 	int opt_name;
 	char *(*opt_val_str)(union val*,int);
 }sock_opts[]={
 	{"SO_BROADCAST",		SOL_SOCKET,		SO_BROADCAST,		sock_str_flag	},
 	{"SO_DEBUG",			SOL_SOCKET,		SO_DEBUG,			sock_str_flag	},
 	{"SO_DONTROUTE",		SOL_SOCKET,		SO_DONTROUTE,		sock_str_flag	},
 	{"SO_ERROR",			SOL_SOCKET,		SO_ERROR,			sock_str_int		},
 	{"SO_KEEPALIVE",		SOL_SOCKET,		SO_KEEPALIVE,		sock_str_flag	},
 	{"SO_LINGER",		SOL_SOCKET,		SO_LINGER,			sock_str_linger	},
 	{"SO_OOBINLINE",		SOL_SOCKET,		SO_OOBINLINE,		sock_str_flag	},
 	{"SO_RCVBUF",		SOL_SOCKET,		SO_RCVBUF,			sock_str_int		},
 	{"SO_SNDBUF",		SOL_SOCKET,		SO_SNDBUF,			sock_str_int		},
 	{"SO_RCVLOWAT",		SOL_SOCKET,		SO_RCVLOWAT,			sock_str_int		},
 	{"SO_SNDLOWAT",		SOL_SOCKET,		SO_SNDLOWAT,			sock_str_int		},
 	{"SO_RCVTIMEO",		SOL_SOCKET,		SO_RCVTIMEO,			sock_str_timeval	},
 	{"SO_SNDTIMEO",		SOL_SOCKET,		SO_SNDTIMEO,			sock_str_timeval	},
 	{"SO_REUSEADDR",		SOL_SOCKET,		SO_REUSEADDR,		sock_str_flag	},

#ifdef SO_REUSEPORT
 	{"SO_REUSEPORT",		SOL_SOCKET,		SO_REUSEPORT,		sock_str_flag	},
#else
 	{"SO_REUSEPORT",		0,				0,					NULL			},
#endif
 	{"SO_TYPE",			SOL_SOCKET,		SO_TYPE,				sock_str_int		},

 #ifdef SO_USELOOPBACK
 	{"SO_USELOOPBACK",	SOL_SOCKET,		SO_USELOOPBACK,		sock_str_flag    },
 #else
 	{"SO_USELOOPBACK",	0,				0,					NULL    			},
 #endif	

 	{"IP_TOS",			IPPROTO_IP,		IP_TOS,				sock_str_int		},
 	{"IP_TTL",			IPPROTO_IP,		IP_TTL,				sock_str_int		},

 #ifdef	IPV6_DONTFRAG	
 	{"IPV6_DONTFRAG",	IPPROTO_IPV6,	IPV6_DONTFRAG,		sock_str_flag	},
 #else
 	{"IPV6_DONTFRAG",	0,				0,					NULL			},
 #endif		

 	{"IPV6_UNICAST_HOPS",IPPROTO_IPV6,	IPV6_UNICAST_HOPS,	sock_str_int		},
 	{"IPV6_V6ONLY",		IPPROTO_IPV6,	IPV6_V6ONLY,			sock_str_flag	},
 	{"TCP_MAXSEG",		IPPROTO_TCP,		TCP_MAXSEG,			sock_str_int		},
 	{"TCP_NODELAY",		IPPROTO_TCP,		TCP_NODELAY,			sock_str_flag	},

 #ifdef SCTP_AUTOCLOSE
 	{"SCTP_AUTOCLOSE",	IPPROTO_SCTP,	SCTP_AUTOCLOSE,		sock_str_int		},
 #else
 	{"SCTP_AUTOCLOSE",	0,				0,					NULL			},
 #endif

 #ifdef	SCTP_MAXBUFST
 	{"SCTP_MAXBUFST",	IPPROTO_SCTP,	SCTP_MAXBUFST,		sock_str_int		},
 #else
 	{"SCTP_MAXBUFST",	0,				0,					NULL			},
 #endif

 #ifdef SCTP_MAXSEG
 	{"SCTP_MAXSEG",		IPPROTO_SCTP,	SCTP_MAXSEG,			sock_str_int		},
 #else
 	{"SCTP_MAXSEG",		0,				0,					NULL			},
 #endif

 #ifdef	SCTP_NODELAY
 	{"SCTP_NODELAY",		IPPROTO_SCTP,	SCTP_NODELAY,		sock_str_flag	},
 #else
 	{"SCTP_NODELAY",		0,				0,					NULL			},
 #endif	

 	{NULL,				0,				0,					NULL}
 };
 int main(int argc, char const *argv[])
 {
 	int fd;
 	socklen_t len;
 	struct sock_opts *ptr;

 	for (ptr = sock_opts; ptr->opt_str!=NULL;ptr++)
 	{
 		printf("%s: ", ptr->opt_str);
 		if (ptr->opt_val_str==NULL)
 		{
 			printf("(undefined)\n");
 		}
 		else
 		{
 			switch(ptr->opt_level)
 			{
 				case SOL_SOCKET:
 				case IPPROTO_IP:
 				case IPPROTO_TCP:
 					fd=Socket(AF_INET,SOCK_STREAM,0);
 					break;
#ifdef 	IPV6
 				case IPPROTO_IPV6:
 					fd=Socket(AF_INET6,SOCK_STREAM,0);
 					break;
 #endif
 #ifdef	IPPROTO_SCTP
 				case IPPROTO_SCTP:
 					fd=Socket(AF_INET,SOCK_SEQPACKET,IPPROTO_SCTP);
 					break;
 #endif			
 				default:
 					char buff[200];
 					snprintf(buff,sizeof(buff),"Can't create fd for level %d,%s",ptr->opt_level,ptr->opt_str);
 					perror(buff);
 					
 			}
 			len=sizeof(val);
 			if (getsockopt(fd, ptr->opt_level, ptr->opt_name, &val, &len) ==-1)
 			{
 				perror("getsockopt error\n");
 			}
 			else
 			{
 				printf("default = %s\n",(*ptr->opt_val_str)(&val,	len));
 			}
 			close(fd);
 		}
 	}
 	return 0;
 }
static char strres[128];
static char * sock_str_flag(union val *ptr,int len)
{
	if(len!=sizeof(int))
		snprintf(strres,sizeof(strres),"size (%d) not sizeof (int)",len);
	else
		snprintf(strres,sizeof(strres),"%s",(ptr->i_val==0)?"off":"on");
	return (strres);
}
static char * sock_str_int(union val *ptr, int len)
{
	if (len!=sizeof(int))
	{
		snprintf(strres,sizeof(strres),"size (%d) not sizeof (int)",len);
	}
	else
		snprintf(strres,sizeof(strres),"%d",ptr->i_val);
	return (strres);
}
static char * sock_str_linger(union val *ptr,int len)
{
	if (len!=sizeof(struct linger))
	{
		snprintf(strres,sizeof(strres),"size (%d) not sizeof (int)",len);
	}
	else
		snprintf(strres,sizeof(strres),"ptr->linger_val.l_onoff=%d,ptr->linger_val.l_linger=%d ",ptr->linger_val.l_onoff, ptr->linger_val.l_linger);
	return (strres);
}
static char * sock_str_timeval(union val *ptr,int len)
{

	if (len!=sizeof(struct timeval))
	{
		snprintf(strres,sizeof(strres),"size (%d) not sizeof (int)",len);
	}
	else
		snprintf(strres,sizeof(strres),"ptr->timeval_var.tv_sec=%ld,ptr->timeval_var.tv_usec=%ld ",ptr->timeval_var.tv_sec, ptr->timeval_var.tv_usec);
	return (strres);
}

 int Socket(int family,int type,int protocol)
 {
 	int n;
 	if((n=socket(family,type,protocol))<0)
 		perror("socket error");
 	return(n);
 }