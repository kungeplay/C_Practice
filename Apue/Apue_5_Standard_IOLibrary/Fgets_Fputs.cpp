#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 4096
int main(int argc, char const *argv[])
{
	char buf[MAXLINE];
	while(fgets(buf,MAXLINE,stdin)!=NULL)
	{
		if (fputs(buf,stdout)==EOF)
		{
			printf("output error\n");
			exit(1);
		}
	}

	if (ferror(stdin))
	{
		printf("input error\n");
		exit(1);
	}
	return 0;
}