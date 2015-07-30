// Single Number
// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

#include <iostream>
#include <vector>
using namespace std;
//剑指offer上或者在编程之美上都有这个题
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res=nums[0];
		for(size_t i=1;i<nums.size();++i)
		{
			res^=nums[i];
		}
		return res;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> nums={3,2,1,4,5,6,4,3,2,5,1,6,8};
	Solution so;
	cout<<so.singleNumber(nums)<<endl;
	return 0;
}