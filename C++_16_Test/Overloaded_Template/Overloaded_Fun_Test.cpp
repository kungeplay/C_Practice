#include <iostream>
#include <sstream>//ostringstream

using namespace std;
//debug_rep(const T&)本质上可以用于任何类型，包括指针类型。此模板比de_bug_rep(T*)更通用，后者只能用于指针类型.
template <typename T> string debug_rep(const T &t)
{
	ostringstream ret;
	ret<<t;//使用T的输出运算符打印t的一个表示形式
	return ret.str();//返回ret绑定的string的一个副本
}
template <typename T> string debug_rep(T *p)
{
	ostringstream ret;
	ret<<"pointer: "<<p;
	if(p)
		ret<<" "<<debug_rep(*p);
	else
		ret<<" null pointer";
	return ret.str();
}
//普通非模板版本的debug_rep，当存在多个同样好的函数模板时，编译器选择最特例化的版本，出于相同的原因，一个非模板函数比一个函数模板更好。
// string debug_rep(const string &s)
// {
// 	return '"'+s+'"';
// }

int main(int argc, char const *argv[])
{
	string s("hi");
	cout<<debug_rep(s)<<endl;
	cout<<debug_rep(&s)<<endl;
	const string *sp=&s;
	cout<<debug_rep(sp)<<endl;
	cout<<debug_rep("hi world")<<endl;//对于第一个，T被绑定到char [10],(精确匹配);对于第二个,T被绑定到const char,(精确匹配),且更加特例化;对于第三个，要求从const char*到string的类型转换
	return 0;
}
