// Container With Most Water
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
// Find two lines, which together with x-axis forms a container, 
// such that the container contains the most water.

// Note: You may not slant the container. 
#include <iostream>
#include <vector>
using namespace std;
//注意理解题意
class Solution {
public:
    int maxArea(vector<int>& height) {
    		int sum=0;
    		int currentArea=0;
    		auto iterbegin=height.cbegin();
    		auto iterlast=height.cend()-1;
		while(iterbegin!=iterlast)//从两边往中间找最低边
		{
			if (*iterbegin<*iterlast)
			{
				currentArea=(*iterbegin)*(iterlast-iterbegin);
				++iterbegin;
			}
			else
			{
				currentArea=(*iterlast)*(iterlast-iterbegin);
				--iterlast;
			}
			if(sum<currentArea)
				sum=currentArea;

		}
		return sum;
    }
};
int main(int argc, char const *argv[])
{
	std::vector<int> v={1,2,3,4,5,6,7,7};
	Solution so;
	cout<<so.maxArea(v)<<endl;
	return 0;
}
