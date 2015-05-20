#include <stdio.h>
#include <unistd.h>//getopt
//这个程序主要测试使用getopt函数的使用方法
int main(int argc,char *argv[])
{
	int c;
	//opterr=0;//如果一个选项发生了错误,getopt会默认打印一条出错信息,通过设置opterr参数为0来禁止
	while((c=getopt(argc,argv,"asd:f:g:h"))!=-1)
	{
		switch(c)
		{
			case 'a':
				printf("c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			case 's':
				printf("c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			case 'd':
				printf("c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			case 'f':
				printf("c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			case 'g':
				printf("c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			case 'h':
				printf("c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			default:
				printf("no match! c=%c, optind=%d,optarg=%s,optopt=%c\n",c,optind,optarg,optopt);
				break;
			
		}
	}
	printf("It is over!\n%c\n",optopt);
	//printf();
}
