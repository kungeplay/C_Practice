#include <iostream>
using namespace std;
//当定义可变参数版本的print时，非可变参数版本的声明必须在作用域中。否则，可变参数版本会无限递归。
//
//当我们需要知道包中有多少元素时，可以使用sizeof...运算符。类似sizeof，sizeof...也返回一个常量表达式,而且不会对其实参求值.
template <typename...Args> void foo(const Args &...rest)
{
	cout<<sizeof...(Args)<<endl;//类型参数的数目
	cout<<sizeof...(rest)<<endl;//函数参数的数目
}

//用来终止递归并打印最后一个元素的函数
//此函数必须在可变参数版本的print定义之前声明
template<typename T> ostream &print(ostream &os,const T&t)
{
	return os<<t<<endl;
}
//可变参数函数通常是递归的。第一步调用处理包中的第一个实参，然后用剩余实参调用自身。
//下面这个print函数也是这样的模式，每次递归调用将第二个实参打印到第一个第一个实参表示的流中。
template <typename T,typename...Args> ostream& print(ostream &os, const T& t, const Args&...rest)//扩展Args
{
	os<<t<<"\t";
	return print(os,rest...);//程序的关键部分.扩展rest
}

int main(int argc, char const *argv[])
{
	int i=0;
	double j=1.0;
	string s="Hello World!";
	float f=1.234;
	float f2=2.345;
	char c='d';
	char c2='c';
	foo(i,j,s,f,c,c2,f2);
	
	print(cout,i,j,s,f,f2);

	return 0;
}
