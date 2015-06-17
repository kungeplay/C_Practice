// Remove Duplicates from Sorted Array
// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
// It doesn't matter what you leave beyond the new length. 
#include <iostream>
#include <vector>
//这个题不难
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size()<=1)
			return nums.size();

		int i=0;
		int j=i+1;
		while(j!=nums.size())
		{
			if(nums[i]==nums[j])
				++j;
			else
			{
				nums[++i]=nums[j++];
			}

		}
		return i+1;

	}
};
int main(int argc, char const *argv[])
{
	vector<int> nums={2,2,2,2};
	Solution so;
	cout<<so.removeDuplicates(nums)<<endl;
	return 0;
}
