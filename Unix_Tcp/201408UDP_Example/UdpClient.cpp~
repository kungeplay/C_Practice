//
//这个程序主要是测试UDP
//主要功能是读取标准键盘输入或者文件，
//把读到的内容发送给服务器，并接收服务器的反射。把接收到的字符串显示出来。
//
#include <sys/socket.h>//socket,connect,bind,listen,accept,getsockname,getpeername,struct sockaddr,

#include <stdio.h>  //perror,
#include <stdlib.h> //perror,

#include <netinet/in.h>//struct sockaddr_in,

#include <string.h>//bzero,bcopy,bcmp,memset,memcpy,memcmp,

#include <arpa/inet.h> //inet_pton,inet_ntop,

#define SERV_PORT 49140
#define MAXLINE 1024

void dg_cli(FILE *fp,int sockfd,const struct sockaddr * pservaddr,socklen_t servlen);
char * sock_ntop(const struct sockaddr *sa,socklen_t salen);


int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

	if (argc!=2)
	{
		printf("usage UdpClient <IPaddress>\n");
		exit(1);
	}

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	if(-1==inet_pton(AF_INET,argv[1],&servaddr.sin_addr))
	{
		perror("socket inet_pton wrong!");
		exit(1);
	}

	if(-1==(sockfd=socket(AF_INET,SOCK_DGRAM,0)))
	{
		perror("socket create wrong!");
		exit(1);
	}

	/*//读取文件，以行为单位,发送给服务器，
	FILE *fp;
	fp=fopen("./Test.txt","r");
	if (fp==NULL)
	{
		perror("FILE open wrong!");
		exit(1);
	}	
	dg_cli(fp,sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	*///

	//读取标准键盘,发送给服务器。
	dg_cli(stdin,sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

	return 0;
}

void dg_cli(FILE *fp,int sockfd,const struct sockaddr * pservaddr,socklen_t servlen)
{
	int n;
	char sendline[MAXLINE],recvline[MAXLINE+1];
	socklen_t len;
	struct sockaddr * preply_addr;

	if(NULL==(preply_addr=(struct sockaddr *)malloc(servlen)))
	{
		perror("malloc wrong!");
		exit(1);
	}

	while(fgets(sendline,MAXLINE,fp)!=NULL)//fgets函数
	{
		if(-1==sendto(sockfd,sendline,strlen(sendline),0,pservaddr,servlen))
		{
			perror("socket sendto wrong!");
			exit(1);
		}
		len=servlen;
		printf("send success!\n");
		/*
		if (-1==(n=recvfrom(sockfd,recvline,MAXLINE,0,preply_addr,&len)))
		{
			perror("socket recvfrom wrong!");
			exit(1);
		}
		
		//验证接收到的相应是不是来自服务器的应答。，只保留来自 数据报所发往服务器的应答。
		if (len!=servlen||memcmp(pservaddr,preply_addr,len)!=0)
		{
			printf("reply from %s (ignored)\n", sock_ntop(preply_addr,len));
		}

		recvline[n]=0; // null terminate 
		fputs(recvline,stdout);//fputs函数

		*/
	}

}

char * sock_ntop(const struct sockaddr *sa,socklen_t salen)
{
	char portstr[8];
	static char str[128]; /* Unix domain is largest*/
	switch(sa->sa_family)
	{
		case AF_INET:
		{
			struct sockaddr_in * sin=(struct sockaddr_in *)sa;
			if(inet_ntop(AF_INET,&sin->sin_addr,str,sizeof(str))==NULL)
				return (NULL);
			if(ntohs(sin->sin_port)!=0)
			{
				snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
				strcat(str,portstr);
			}
			return(str);
		}
		/* end sock_ntop */
		default:
			snprintf(str, sizeof(str), "sock_ntop: unknown AF_xxx: %d, len %d",sa->sa_family, salen);
		return(str);
	}
    return (NULL);
}
