#include <stdio.h>
#include <stdlib.h>
//这个程序使用getc和putc将标准输入复制到标准输出。
int main(int argc, char const *argv[])
{
	int c;
	while((c=getc(stdin))!=EOF)
	{
		if (putc(c,stdout)==EOF)
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