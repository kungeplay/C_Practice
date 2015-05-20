#include <stdio.h>
#include <sys/un.h>
#include <stdlib.h>//exit
#include <sys/socket.h>//socket,bind,
#include <string.h> //memset
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int sockfd;
	socklen_t len;
	struct sockaddr_un addr1,addr2;

	if (argc!=2)
	{
		printf("useage:unixbind <pathname\n");
		exit(1);
	}

	if((sockfd=socket(AF_LOCAL,SOCK_STREAM,0))==-1)
	{
		printf("socket error!\n");
		exit(1);
	}

	unlink(argv[1]); //OK if this fails

	memset(&addr1,0,sizeof(addr1));
	addr1.sun_family=AF_LOCAL;
	strncpy(addr1.sun_path,argv[1],sizeof(addr1.sun_path)-1);
	if((bind(sockfd,(struct sockaddr*)&addr1,SUN_LEN(&addr1)))==-1)
	{
		perror("bind error!\n");
		exit(1);
	}

	len=sizeof(addr2);
	if((getsockname(sockfd,(struct sockaddr*)&addr2,&len))==-1)
	{
		perror("getsockname error!");
		exit(1);
	}
	printf("bound name=%s,returned len=%d\n",addr2.sun_path,len);
	return 0;
}