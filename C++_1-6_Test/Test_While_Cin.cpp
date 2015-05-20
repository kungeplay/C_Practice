#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
using std::endl;
int main()
{
	vector<int> v;
	int i;
	while(cin>>i)
	{
		cout<<"输入的数字为:"<<i<<endl;
		v.push_back(i);
	}
	cout<<"最后一个输入为:"<<i<<endl;
	auto beg=v.begin();
	while(beg!=v.end() && *beg>=0)
		++beg;
	if(beg==v.end())
		cout<<"没有输入负数!"<<endl;
	else
		cout<<"第一个负数是:"<<*beg<<endl;
}
