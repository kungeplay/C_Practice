// Single Number II
// Given an array of integers, every element appears three times except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
#include <iostream>
#include <vector>
using namespace std;
//第一次碰到这样的每个数重复三次，只有一个数有一次，求这个数的题，不会做，在网上找到
//int型数据共有32位，可以用大小为32的数组变量存储这N个元素中各个二进制位上1出现的次数，最后再进行模三操作，
//如果为1，那说明这一位是要找元素二进制表示中为 1 的那一位。
//这是一个通用的解法，如果把出现3次改为 k 次，那么只需模k就行了。
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res=0;
		vector<int> bitnum(32);
		for(int i=0;i<32;++i)
		{
			for(size_t j=0;j<nums.size();++j)
			{
				bitnum[i]+=(nums[j]&1<<i)==0?0:1;
			}
			res+=(bitnum[i]%3)<<i;
		}
		return res;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1,2,2,2,3,3,3,6,5,5,5,12,12,12,8,8,8};
	Solution so;
	cout<<so.singleNumber(nums)<<endl;
	return 0;
}