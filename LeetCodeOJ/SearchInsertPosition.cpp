// Search Insert Position
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0 
#include <iostream>
#include <vector>
using namespace std;
//突然发现STL源码剖析这本书是多么的好呀，这么多源算法
//这个是lower_bound算法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		auto first=nums.begin();
		auto last=nums.end();
		auto len=last-first;
		while(len>0)
		{
			auto half=len>>1;
			auto mid=first+half;
			if(*mid<target)
			{
				first=mid+1;
				len=len-half-1;
			}
			else
				len=half;
		}
		return first-nums.begin();
    }
};
int main(int argc, char const *argv[])
{
	Solution so;
	std::vector<int> v={1,2,3,4,5,6};
	cout<<so.searchInsert(v,7)<<endl;
	return 0;
}
