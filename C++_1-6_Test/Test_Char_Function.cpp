#include <iostream>
#include <string>
/*
 * 函数重载
 * 顺便测试了下,发现字符串字面值为C风格字符串，
 * 即默认存放在字符数组中以空字符结束
 * 字符串是字符串，字符数组是字符数组。
 * 二者默认不是可以隐式转换的
 * 字符串s可以通过s.c_str()来转换成一个c风格的字符串
 */
using std::string;
using std::cout;
using std::endl;
void Print(string );
void Print(const char *);
int main()
{
char a[]="ABCD";
cout<<sizeof(a)<<endl;
string s="Hello World!";
Print(s);
Print(a);
cout<<"存放的函数名字为:"<<__func__<<endl;
cout<<"存放文件名的字符串字面值为:"<<__FILE__<<endl;
cout<<"存放当前行号的整型字面值为:"<<__LINE__<<endl;
cout<<"存放文件编译时间的字符串字面值为："<<__TIME__<<endl;
cout<<"存放文件编译日期的字符串字面值为："<<__DATE__<<endl;

}
void Print(string s)
{
cout<<s<<"----"<<endl;
}

void Print(const char *c)
{
cout<<c<<"--"<<endl;
}
