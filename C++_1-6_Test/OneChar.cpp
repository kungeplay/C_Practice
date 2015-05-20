#include <iostream>
/*
 * 测试字符汉字的类型表示方法
 */
int main()
{
	char a='a';
	//char32_t b='你';
	char32_t b='b';
	unsigned char c=22;
	int d=20;
	std::cout<<a<<" "<<b<<std::endl;
	std::cout<<d+c<<std::endl;
	std::cout<<"It is over!"<<std::endl;
	return 0;
}
