
/*
 *只是测试一下本机是大端还是小端
 */

//#include "config.h"
#include <iostream>
using namespace std;
int main(int argc,char ** argv)
{
	union
	{
		short s;
		char c[sizeof(short)];
	}un;
	un.s=0x0102;
	//cout<<CPU_VENDOR_OS<<":";
	//printf("%s:",CPU_VENDOR_OS);
	if(sizeof(short)==2)
	{
		if(un.c[0]==1&&un.c[1]==2)
		{

			cout<<"big-endian"<<endl;
			//printf("big-endian\n");
		}
		else if(un.c[0]==2&&un.c[1]==1)
			cout<<"little-endian"<<endl;
			//printf("little-endian\n");
		else 
			cout<<"unknown"<<endl;
			//printf("unknown\n");
	}
	else
		cout<<"sizeof(short)="<<sizeof(short)<<endl;
		//printf("sizeof(short)=%d\n",sizeof(short));
	//exit(0);
	cout<<"un.s="<<un.s<<endl;
	return 0;
}
