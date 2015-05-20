#include <iostream>
/*
 * 测试一下对常量的引用
 */
int main()
{
	int i=2;
	const int m=3;
	const int &r1=i;//对常量的引用赋予一个变量
	const int &r2=6;//常量引用直接赋予常量
	const int &r3=m;
	double dval=3.14;
	const int &ri=dval;
	//int &rii=dval;
	std::cout<<"i="<<i<<" m="<<m<<" r1="<<r1<<" r2="<<r2<<" r3="<<r3<<std::endl;
	std::cout<<"dval="<<dval<<" ri="<<ri<<" rii="<<rii<<std::endl;
	//rii=10;
	std::cout<<"dval="<<dval<<" ri="<<ri<<" rii="<<rii<<std::endl;
}
