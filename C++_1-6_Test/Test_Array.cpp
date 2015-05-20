#include <iostream>
#include <iterator>
//using std::cout;
//using std::endl;
//using std::cin;
//using std::iterator
using namespace std;
int print(const int * begin,const int * end);
int main()
{
int input;
int Array[10];
cout<<"请输入10个数字："<<endl;
for(int i=0;i!=10;i++)
	cin>>Array[i];
cout<<"Array[0]的地址&Array[0]是： "<<&Array[0]<<endl;
cout<<"Array的值是： "<<Array<<endl;
cout<<"Array的地址&Array是："<<&Array<<endl;
int (*ArrT)[10]=&Array;
cout<<"(*ArrT)[0]="<<(*ArrT)[0]<<endl;
cout<<"ArrT[0]="<<ArrT[0]<<endl;
cout<<"下面将倒着打印输入的数字--"<<endl;
//print(begin(Array),end(Array));
}
int print(const int * begin,const int * end)
{
if(begin!=end)
{	
	do
	{
	cout<<*--end<<" ";
	}
	while(begin!=end);
cout<<endl;
return 0;
}
return 1;
}
