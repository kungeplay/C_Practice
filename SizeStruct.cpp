#include <stdio.h>
//测试一下结构体的sizeof
//1、数据成员对齐规则：结构体（struct）的数据成员，第一个数据成员放在offset为0的地方，之后的每个数据成员存储的起始位置要从该成员大小的整数倍开始（比如int在32位机子上为4字节，所以要从4的整数倍地址开始存储）。
//2、结构体作为成员：如果一个结构体里同时包含结构体成员，则结构体成员要从其内部最大元素大小的整数倍地址开始存储（如struct a里有struct b,b里有char,int ,double等元素，那么b应该从8(即double类型的大小)的整数倍开始存储）。
//3、结构体的总大小：即sizeof的结果。在按之前的对齐原则计算出来的大小的基础上，必须还得是其内部最大成员的整数倍，不足的要补齐（如struct里最大为double，现在计算得到的已经是11，则总大小为16）。/
struct st
{
	int a;
	long b;
	double c;
	float d;
	char e;
} t1;
int main(int argc,char *argv[])
{
	printf ("sizeof(int)=%d\n",sizeof(int));
	printf ("sizeof(long)=%d\n",sizeof(long));
	printf ("sizeof(double)=%d\n",sizeof(double));
	printf ("sizeof(float)=%d\n",sizeof(float));
	printf ("sizeof(char)=%d\n",sizeof(char));
	printf ("sizeof(st)=%d\n",sizeof(st));
	return 0;
}
