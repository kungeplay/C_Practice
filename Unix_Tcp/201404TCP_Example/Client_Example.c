//客户端每隔一段时间向服务器发送数据
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<fcntl.h>
#include<netinet/tcp.h>
#include<string.h>
#include<sys/socket.h>
#define SERVPORT 55555
#define MAXDATASIZE 200
int main(int argc,char * argv[])
{
    int sockfd,recvbytes;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    int srcount=0,lenstr=0;
    char tempbuf[MAXDATASIZE];

    if(argc<2){
        fprintf(stderr,"Please enter the server's hostname!\n");
        exit(1);
    }
    if((host=gethostbyname(argv[1]))==NULL)
    {
        herror("gethostbyname wrong !");
        exit(1);
    } 
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket create wrong !");
        exit(1);
    }       	
    bzero(&serv_addr,sizeof(serv_addr));//推荐使用memset替代bzero
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERVPORT);
    serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1)
    {
        perror("connect wrong !");
        exit(1);
    }
    for(;;)
    {
    	 sleep(1);
         srcount++;
         sprintf(tempbuf,"Hello server! %d",srcount);
         lenstr=strlen(tempbuf);
         if(send(sockfd,tempbuf,lenstr,0)==-1)//发送
         {
             	perror("send wrong !");
              exit(1);
         }
         printf("send:%s\n",tempbuf );
    }
    close(sockfd);
}
