#include <iostream>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char buf[]={'a','b','c','d','e','f'};
	for(int i=0;i<6;i++)
		printf("%x\t", buf[i]);
	return 0;
}
