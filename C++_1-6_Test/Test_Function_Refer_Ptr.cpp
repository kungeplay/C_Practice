#include <iostream>
#include <string>
/*
 * 测试一下引用和指针在函数形参中的用法，以及字符串在函数实参的中传递，尽量用引用吧，
 */
using std::cout;
using std::endl;
using std::string;
int Change(string *a);
int Change(string &a);//注意，这两个函数重载，只是一个参数为引用，另一个函数参数为指针
int main(int argc,char *argv[])
{
string s{"hello world!"};
cout<<"argc是:"<<argc<<" argv[0]是:"<<argv[0]<<endl;
cout<<"s的地址为"<<&s<<endl;
cout<<"通过指针形参改变字符串"<<endl;
Change(&s);//字符串也是这样传递地址的.
cout<<s<<endl;
Change(s);
cout<<s<<endl;
}
int Change(string *a)
{
(*a)[1]=toupper((*a)[1]);
cout<<"在函数Change中形参指针a所指向的地址为: "<<a<<endl;
return 0;
}
int Change(string &a)
{
cout<<"在函数Change中形参引用a的地址为: "<<&a<<endl;
a[0]=toupper(a[0]);
return 0;
}
