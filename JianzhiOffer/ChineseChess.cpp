#include <stdio.h>
//编程之美上的中国象棋问题
struct Grid{
	unsigned char a :4;
	unsigned char b :4;
};

int main(int argc, char *argv[])
{
	struct Grid pos;	
	for(pos.a=1;pos.a<=9;++pos.a)
	{
		for(pos.b=1;pos.b<=9;++pos.b)
		{
			if((pos.a%3)!=(pos.b%3))
				printf("a=%d,b=%d\n",pos.a, pos.b);
		}
	}
}
