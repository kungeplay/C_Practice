#include <stdio.h>
#include <stddef.h>//offsetof宏
//测试一下结构体的sizeof
//在网上找了那么多关于struct结构体对齐的解答，发现还是C和指针上给的最通俗易懂。另为offset宏表达式的结果是一个size_t值，表示这个指定成员开始存储的位置距离结构开始存储的位置偏移几个字节。
struct st
{
	char e;	
	int a;
	long b;
	double c;
	float d;
	char f;
} t1;
struct st2
{
	long b;
	double c;
	int a;	
	float d;
	char e;
	char f;	
};
class cla1
{
public:
	long a;
};
class cla2
{
	long a;
	virtual void f();
};
void cla2::f()
{
	printf("-------\n");
}

class X{};
class Y:public virtual X{};
class Z:public virtual X{};
class A:public Y,public Z{};



int main(int argc,char *argv[])
{
	printf ("sizeof(int)=%d\n",sizeof(int));
	printf ("sizeof(long)=%d\n",sizeof(long));
	printf ("sizeof(double)=%d\n",sizeof(double));
	printf ("sizeof(float)=%d\n",sizeof(float));
	printf ("sizeof(char)=%d\n",sizeof(char));
	printf("sizeof(char *)=%d\n",sizeof(char *) );
	printf ("sizeof(st)=%d\n",sizeof(st));
	printf ("sizeof(st2)=%d\n",sizeof(st2));	
	printf("%d\n",offsetof(struct st,e));
	printf("%d\n",offsetof(struct st,a));
	printf("%d\n",offsetof(struct st,b));
	printf("%d\n",offsetof(struct st,c));
	printf("%d\n",offsetof(struct st,d));
	printf("%d\n",offsetof(struct st,f));

	printf("sizeof(cla1)=%d\n",sizeof(cla1) );
	printf("%d\n",&cla1::a );	
	printf("sizeof(cla2)=%d\n",sizeof(cla2) );

	printf("sizeof(X)=%d\n",sizeof(X));
	printf("sizeof(Y)=%d\n",sizeof(Y));
	printf("sizeof(Z)=%d\n",sizeof(Z));
	printf("sizeof(A)=%d\n",sizeof(A));
	X a,b;
	printf("&a=0x%x\t&b=0x%x\n", &a,&b);

	return 0;
}
