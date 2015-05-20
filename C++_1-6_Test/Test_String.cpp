#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
/*
 * 测试一下字符串的各种函数,功能
 */
int main()
{
	string s{"Hello, World!!"}; //C++11中的标准
	cout<<s<<endl;
	//auto c=s[1];
	for (char c:s) //C++11中的范围for语句
	{
		cout<<c<<endl;
}	{
