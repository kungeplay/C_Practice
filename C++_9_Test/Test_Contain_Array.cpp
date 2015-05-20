#include <iostream>
#include <array>
/*
 * 测试一下容器array的用法
 */
using std::cout;
using std::cin;
using std::endl;
using std::array;
int main(int argc,char **argv)
{
array<int,10> ar1={0,1,2,3,4,5,6,7,8,9};
array<int,10> ar2;
auto begin=ar1.begin();
auto end=ar1.end();
while(begin!=end)//使用迭代器逐个输出
{
cout<<*begin++<<" ";
}
cout<<endl;
cout<<ar1[2]<<endl;
//ar2={0,1,2,3,4,5,6,7,8,9};//array容器不允许这种赋值
ar2=ar1;
auto len=ar2.size();
array<int,10>::size_type len2=ar2.size();
cout<<len<<endl;
cout<<len2<<endl;
}