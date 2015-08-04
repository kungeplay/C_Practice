// Find Minimum in Rotated Sorted Array

// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.
#include <iostream>
#include <vector>

using namespace std;
//这个题是以前的33题中的Search in Rotated Sorted Array某个题中的一个步骤
class Solution {
public:
	int findMin(vector<int>& nums) {
		int len=nums.size();
		int left=0;
		int right=len-1;
		if(nums[left]<nums[right])
			return nums[left];
		while(left+1<right)
		{
			int mid=(left+right)/2;
			if(nums[mid]>nums[left])
				left=mid;
			else
				right=mid;
		}
		return nums[right];
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums={5,6,7,1,2,3,4};
	Solution so;
	cout<<so.findMin(nums)<<endl;
	return 0;
}
