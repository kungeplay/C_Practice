// Maximum Subarray
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
// More practice:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <vector>
#include <iostream>
#include <limits>

using namespace std;
//这是我想到的第一种算法，根据提示，应该还有一种算法
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//     		int sum=getMaxSub(nums,0);
//     		for(size_t i=1;i<nums.size();++i)
//     		{
//     			int temp_sum=getMaxSub(nums,i);
//     			if(sum<temp_sum)
//     				sum=temp_sum;
//     		}
//     		return sum;
//     }
//     int getMaxSub(std::vector<int> &nums,int start_i)
//     {
//     		int len=nums.size();
//     		int start=start_i;
//     		while(start<len&&nums[start]<=0) ++start;
//     		if(start==len)
//     			return nums[start_i];

//     		int i=start;
//     		int sum=nums[i++];
//     		int max_sum=sum;
//     		while(i<len&&sum>=0)
//     		{
//     			if(nums[i]<0&&max_sum<sum)
//     				max_sum=sum;
//     			sum+=nums[i];
//     			++i;
//     		}
//     		if(max_sum<sum)
//     			max_sum=sum;
//     		return max_sum;    	
//     }
// };
// 剑指offer上提到的第一种方法，发现我上面想得确实多了些，根据规律发现这样只遍历一遍就可以了,这里被我写的太繁琐了，要看一看剑指offer额
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//     		size_t start=0;
//     		size_t len=nums.size();
//     		int sum=(numeric_limits<int>::min)();
//     		while(start<len&&nums[start]<=0)
//     		{
//     			if(sum<nums[start])
//     				sum=nums[start];
//     			++start;
//     		}
//     		if(start==len)
//     		{
//     			return sum;
//     		}
//     		sum=nums[start++];
//     		int last_sum=sum;
//     		while(start<len)
//     		{
//     			if(nums[start]>=0)
//     			{
//     				last_sum+=nums[start];

//     			}
//     			else if(nums[start]<0)
//     			{
//     				last_sum+=nums[start];
//     				if(last_sum<0)
//     					last_sum=0;
//     			}
// 			if(sum<last_sum)
// 				sum=last_sum;
//     			++start;
//     		}
//     		return sum;
//     }
// };
// 这是最简便的方法，根据剑指offer上的第二种动态规划方法P173所得
// 用函数f(i)表示以第i个数字结尾的子数组的最大和，那么我们需要求出max[f(i)],其中0<=i<n.递归公式求f(i)如下：
// f(i)=pData[i]	i=0或者f(i-1)<=0
// f(i)=f(i-1)+pData[i]	i!=0并且f(i-1)>0
// 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    		int sum=(numeric_limits<int>::min)();
    		int last_sum=sum;
    		for(size_t i=0;i<nums.size();++i)
    		{
    			if(i==0||last_sum<0)
    				last_sum=nums[i];
    			else
    			{
    				last_sum+=nums[i];
    			}
    			if(sum<last_sum)
    				sum=last_sum;
    		}
    		return sum;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
	// vector<int> nums={-2,-1};

	Solution so;
	cout<<so.maxSubArray(nums)<<endl;
	return 0;
}
