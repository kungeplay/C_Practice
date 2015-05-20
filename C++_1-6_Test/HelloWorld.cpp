#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char  buf[]="idIP;20140112";
	cout<<"Hello World!"<<endl;
	char *n=strchr(buf,';');
	char temp[20];
	int weizhi=strcspn(buf,";");
	strncpy(temp,buf,weizhi);
	temp[weizhi]='\0';
	cout<<weizhi<<endl;
	cout<<n+1<<endl;
	cout<<strlen(n)<<endl;
	cout<<strlen(buf)-weizhi-1<<endl;
	cout<<temp<<endl;
}