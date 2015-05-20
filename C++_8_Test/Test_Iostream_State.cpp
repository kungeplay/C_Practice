#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char ** argv)
{
int n=0;
do
{
cout<<"输入的值为："<<n<<endl;
cin>>n;
cout<<"----------"<<endl;
}
while(cin.good());//若流处于有效状态，则返回true，用下一条语句也可以
//while(!cin.fail());//若流的failbit或badbit置位，则返回true

}
