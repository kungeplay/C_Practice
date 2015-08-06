// Find Peak Element 
// A peak element is an element that is greater than its neighbors.

// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that num[-1] = num[n] = -∞.

// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

// click to show spoilers.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

#include <iostream>
#include <vector>
using namespace std;
//求数组中的一个最高点，不难的一个题
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		bool leftNeighbors=true;
		int len=nums.size();
		for(int i=0;i<len;++i)
		{
			if(i==len-1||nums[i]>nums[i+1])
			{
				if(leftNeighbors)
					return i;
				else
					leftNeighbors=false;
			}
			else
				leftNeighbors=true;
		}
		return -1;		
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums={1,2};
	Solution so;
	cout<<so.findPeakElement(nums)<<endl;
	return 0;
}
