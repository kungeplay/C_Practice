#include <iostream>
/*
 * 测试一下强制类型转换const_cast<>()的作用
 */
using std::cout;
using std::endl;
int main()
{
//int x=8;
const int i=5;
const int * p=&i;
int *j=const_cast<int *>(p);//<>里必须为指针或引用
int *k=const_cast<int *>(&i);
cout<<"i="<<i<<" *p="<<*p<<" *j="<<*j<<endl;
cout<<"&i="<<&i<<" p="<<p<<" j="<<j<<endl;
*j=6;
cout<<"i="<<i<<" *p="<<*p<<" *j="<<*j<<endl;//访问i时仍是从常量表中取值，而p和j指向的只是i在内存中的一个副本，
//故下面取地址时一样。但实际上常量i的地址只是为了便于指向而设的一个临时拷贝
cout<<"&i="<<&i<<" p="<<p<<" j="<<j<<endl;//但是若把i的初始值设为x则就对了
int x=8;
const int n=x;
const int *q=&n;
int *m=const_cast<int *>(q);
cout<<"x="<<x<<" n="<<n<<" *q="<<*q<<" *m="<<*m<<endl;
cout<<"&x="<<&x<<" &n="<<&n<<" q="<<q<<" m="<<m<<endl;
*m=9;
cout<<"x="<<x<<" n="<<n<<" *q="<<*q<<" *m="<<*m<<endl;
cout<<"&x="<<&x<<" &n="<<&n<<" q="<<q<<" m="<<m<<endl;
}
