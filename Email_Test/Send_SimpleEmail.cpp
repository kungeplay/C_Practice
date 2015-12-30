#include <iostream>
#include <string>

extern "C"
{
	#include <string.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <stdio.h>
}
using namespace std;

const char Base64ValTab[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
#define AVal(x) Base64ValTab[x]
int encodeBase64(const char * pInput, char * pOutput)
{
	int i = 0;
	int loop = 0;
	int remain = 0;
	int iDstLen = 0;
	int iSrcLen = (int)strlen(pInput);

	loop = iSrcLen/3;
	remain = iSrcLen%3;

	// also can encode native char one by one as decode method
	// but because all of char in native string  is to be encoded so encode 3-chars one time is easier.

	for (i=0; i < loop; i++)
	{
		char a1 = (pInput[i*3] >> 2);
		char a2 = ( ((pInput[i*3] & 0x03) << 4) | (pInput[i*3+1] >> 4) );
		char a3 = ( ((pInput[i*3+1] & 0x0F) << 2) | ((pInput[i*3+2] & 0xC0) >> 6) );
		char a4 = (pInput[i*3+2] & 0x3F);

		pOutput[i*4] = AVal(a1);
		pOutput[i*4+1] = AVal(a2);
		pOutput[i*4+2] = AVal(a3);
		pOutput[i*4+3] = AVal(a4);
	}

	iDstLen = i*4;

	if (remain == 1)
	{
		// should pad two equal sign
		i = iSrcLen-1;
		char a1 = (pInput[i] >> 2);
		char a2 = ((pInput[i] & 0x03) << 4);

		pOutput[iDstLen++] = AVal(a1);
		pOutput[iDstLen++] = AVal(a2);
		pOutput[iDstLen++] = '=';
		pOutput[iDstLen++] = '=';
		pOutput[iDstLen] = 0x00;
	}
	else if (remain == 2)
	{
		// should pad one equal sign
		i = iSrcLen-2;
		char a1 = (pInput[i] >> 2);
		char a2 = ( ((pInput[i] & 0x03) << 4) | (pInput[i+1] >> 4));
		char a3 = ( (pInput[i+1] & 0x0F) << 2);

		pOutput[iDstLen++] = AVal(a1);
		pOutput[iDstLen++] = AVal(a2);
		pOutput[iDstLen++] = AVal(a3);
		pOutput[iDstLen++] = '=';
		pOutput[iDstLen] = 0x00;
	}
	else
	{
		// just division by 3
		pOutput[iDstLen] = 0x00;
	}
	return iDstLen;
}


int main(int argc, char const *argv[])
{
	string username= "xiumu826";
	string password="sqfj2005";
	string smtpServer="smtp.126.com";
	string fromAddress="xiumu826@126.com";
	string toAddress="blueskywww@126.com";

	//设置邮件中的发件人和收件人以及邮件标题
	string emailHead=
	"From:测试发件箱<xiumu826@126.com>\n"
	"To:LiuJiakun<blueskywww@126.com>\n"
	"Subject:C语言发送邮件测试!\n";

	//这里是邮件正文
	string emailContent="你好\n\t我是刘佳坤.";

	int smtpPort=25;
	int sockfd;
	struct sockaddr_in serv_addr;
	struct hostent *host;

	char sbuf[256];
	char rbuf[256];
	char userEncodingBuf[256];
	char passwordEncodingBuf[256];

	if((host=gethostbyname(smtpServer.c_str()))==NULL)
	{
		herror("gethostbyname wrong!");
		exit(1);
	}
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==1)
	{
		perror("socket create wrong!");
		exit(1);
	}

	memset((void *)&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(smtpPort);
	serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1)
	{
		perror("connect wrong!");
		exit(2);
	}

	//EHLO
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"EHLO %s\r\n",smtpServer.c_str());
	if (send(sockfd,sbuf,strlen(sbuf),0)==-1)
	{
		perror("EHLO send Wrong!");
		exit(3);
	}
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"EHLO:"<<rbuf<<endl;

	//AUTH LOGIN
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"AUTH LOGIN\r\n");
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"AUTH LOGIN:"<<rbuf<<endl;

	//USER
	memset(userEncodingBuf,0,sizeof(userEncodingBuf));
	encodeBase64(username.c_str(),userEncodingBuf);
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"%s\r\n",userEncodingBuf);
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"USER:"<<rbuf<<endl;

	//PASSWORD
	memset(passwordEncodingBuf,0,sizeof(passwordEncodingBuf));
	encodeBase64(password.c_str(),passwordEncodingBuf);
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"%s\r\n",passwordEncodingBuf);
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"PASSWORD:"<<rbuf<<endl;

	//MAIL FROM
	//发送者邮箱 
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"MAIL FROM:<%s>\r\n",fromAddress.c_str());
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"MAIL FROM:"<<rbuf<<endl;

	//RCPT TO
	//接收者邮箱 
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"RCPT TO:<%s>\r\n",toAddress.c_str());
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"RCPT TO:"<<rbuf<<endl;

	//DATA
	//请求发送数据
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"DATA\r\n");
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"DATA:"<<rbuf<<endl;

	//发送邮件内容，\r\n.\r\n内容结束标记
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"%s\r\n",emailHead.c_str());
	send(sockfd,sbuf,strlen(sbuf),0);
	cout<<emailHead;

	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"%s\r\n.\r\n",emailContent.c_str());
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<emailContent<<endl;
	cout<<"Send and Finish:"<<rbuf<<endl;

	//QUIT
	memset(sbuf,0,sizeof(sbuf));
	sprintf(sbuf,"QUIT\r\n");
	send(sockfd,sbuf,strlen(sbuf),0);
	memset(rbuf,0,sizeof(rbuf));
	recv(sockfd,rbuf,sizeof(rbuf),0);
	cout<<"QUIT:"<<rbuf<<endl;

	close(sockfd);
	return 0;
}
