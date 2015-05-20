#include <iostream>
/*
 * 测试一下引用
 */
int main()
{
int a=1,&m=a;
int &n=m;//引用的引用？
char b='b',&c=b;
char &d=c;//引用的引用
std::cout<<"a="<<a<<" m="<<m<<" n="<<n<<std::endl;
std::cout<<"b="<<b<<" c="<<c<<" d="<<d<<std::endl;
std::cout<<"请输入新的整数n值"<<std::endl;
std::cin>>n;
std::cout<<"请输入新的字符d值"<<std::endl;
std::cin>>d;
std::cout<<"a="<<a<<" m="<<m<<" n="<<n<<std::endl;
std::cout<<"b="<<b<<" c="<<c<<" d="<<d<<std::endl;

}
