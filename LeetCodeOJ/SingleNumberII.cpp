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
// class Solution {
// public:
// 	int singleNumber(vector<int>& nums) {
// 		int res=0;
// 		vector<int> bitnum(32);
// 		for(int i=0;i<32;++i)
// 		{
// 			for(size_t j=0;j<nums.size();++j)
// 			{
// 				bitnum[i]+=(nums[j]&1<<i)==0?0:1;
// 			}
// 			res+=(bitnum[i]%3)<<i;
// 		}
// 		return res;
// 	}
// };
//下面这种方法也是从网上扒的，用三个变量one，two，three分别保存数组中元素的各个二进制位上1出现的1次，2次，3次的分布情况，最后只需返回one就行了。
class Solution {  
public:  
	int singleNumber(vector<int>& nums) {
		int len=nums.size();
		int one=0, two=0, three=0;  
		for(int i=0; i<len; i++)
		{
			two |= one&nums[i];//上一次出现1次的位与这次的元素相与获得共出现两次1的分布，再与two相或，获得总共出现2次的位
			one^=nums[i];//one与这次的元素相异或，获得到目前位置1出现的分布。
			three=one&two;//获得到目前为止各位上出现3次1的位
			one&= ~three;//应该是清除那些出现3次1的位
			two&= ~three;//应该是清除那些出现3次1的位
		}  
		return one;  
	}  
};
//解释：每次循环先计算 twos，即出现两次的 1 的分布，然后计算出现一次的 1 的分布，接着 二者进行与操作得到出现三次的 1 的分布情况，然后对 threes 取反，
//再与 ones、twos进行与操作，这样的目的是将出现了三次的位置清零。
//这个方法虽然更快、更省空间了，但是并不通用。
//
//
int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1,2,2,2,3,3,3,6,5,5,5,12,12,12,8,8,8};
	Solution so;
	cout<<so.singleNumber(nums)<<endl;
	return 0;
}
