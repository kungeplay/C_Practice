#include <iostream>
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	unsigned char buf[24]={0x7a,0x7a,0x14,0x0d,0x09,0x12,0x00,0x5b,0x00,0x01,0x20};
	unsigned char msg[13]={0,11,61,'.',167,'.',40,'.',249,39,36,39,38};
	for (int i = 0; i < 11; ++i)
	{
		printf("%x\t",buf[i] );
	}
     printf("\n");
	for (int i = 0; i < 13; ++i)
	{
		printf("%x\t",msg[i]);
	}
	printf("\n");
	//strcat((char *)buf,(char *)msg);
	for (int i = 11; i < 24; ++i)
	{
		buf[i]=msg[i-11];
	}
	for (int i = 0; i < 24; ++i)
	{
		printf("%x   ",buf[i] );
	}
	printf("\n");
	printf("%s\n",buf );
      printf("\n");
	return 0;
}