// Find Minimum in Rotated Sorted Array II

//     Follow up for "Find Minimum in Rotated Sorted Array":
//     What if duplicates are allowed?

//     Would this affect the run-time complexity? How and why?

// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// The array may contain duplicates.
#include <iostream>
#include <vector>
using namespace std;
//这种重复的翻转数组，主要是去掉前面中与结尾相同的数字就行了
class Solution {
public:
	int findMin(vector<int>& nums) {
		int len=nums.size();
		int left=0;
		int right=len-1;
		while(left<right&&nums[left]==nums[right])
			++left;
		if(left==right||nums[left]<nums[right])
			return nums[left];
		while(left+1<right)
		{
			int mid=(left+right)/2;
			if(nums[mid]>=nums[left]&&nums[mid]>nums[right])
				left=mid;
			else
				right=mid;
		}
		return nums[right];
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1,1,0};
	Solution so;
	cout<<so.findMin(nums)<<endl;
	return 0;
}