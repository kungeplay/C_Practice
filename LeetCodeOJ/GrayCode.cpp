// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
// 这个题算我作弊吧，百度百科了下gray code的定义，直接找到了规律
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
		std::vector<int> vresult;
    		if (n<0)
    		{
    			return vresult;
    		}
    		if (n==0)
    		{
    			vresult.push_back(0);
    		}
    		else
    		{
    			std::vector<int> vtemp=grayCode(n-1);
    			vresult=vtemp;
    			int base=pow(2,n-1);
    			for(int vindex=vtemp.size()-1;vindex>=0;--vindex)
    			{
    				vresult.push_back(vtemp[vindex]+base);
    			}
    		}
    		return vresult;        
    }
};
int main(int argc, char const *argv[])
{
	Solution so;
	std::vector<int> v=so.grayCode(6);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i<<"\t";
	}
	cout<<endl;
	return 0;
}
