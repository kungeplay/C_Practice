
#define ServPort 55555

int main(int argc, char const *argv[])
{
	int sockfd,port,n;
	struct sockaddr_in serveraddr;
	if (argc<2 || argc>3)
	{
		printf("Use: %s <Broadcasting IPaddress> [<Port>]\n",argv[0]);
		exit(1);
	}
	else if (argc==3)
	{
		port=atoi(argv[2]);
	}
	else
	{
		port=atoi(ServPort);
	}

	memset(serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(port);
	if((n=inet_pton(AF_INET,argv[1],serveraddr.sin_addr))!=1)
	{
		if (n==0)
		{
			printf("IPaddress Wrong!\n");
			exit(1);
		}
		else
		{
			perror("inet_pton error!");
			exit(1);
		}
	}

	if((sockfd=socket(AF_INET,SOCK_DGRAM,0)==-1)
	{
		perror("socket create error!");
		exit(1);
	}
	dg_cli(stdin,sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));



	return 0;
}

void dg_cli(FILE *fp,int sockfd,const struct sockaddr *pservaddr,socklen_t servlen)
{
	const int on =1;
	char sendline[MAXLINE],recvline[MAXLINE+1];
	socklen_t len;
	struct sockaddr *preply_addr;

	if((preply_addr=(struct sockaddr *)malloc(servlen))==NULL)
	{
		perror("malloc error!");
		exit(1);
	}

	if(setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on))==-1)
	{
		perror("setsockopt error!");
		exit(1);
	}

	Signal(SIGALRM,recvfrom_alarm);

}