#include <iostream>
#include <vector>
/*测试范围for语句
 */
using std::cout;
using std::endl;
using std::vector;
int main()
{
vector<int> v={0,1,2,3,4,5,6,7,8,9};
for(auto &r : v)
	r*=2;
for(auto beg=v.begin();beg!=v.end();++beg)
	cout<<*beg<<endl;
}
