// Search for a Range
// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4]. 

#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;
//这个题其实就是STL源码剖析上的equal_range算法，我没有按照那个算法上来
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		vector<int> v;
		if(nums.size()==0)
		{
			v.push_back(-1);
			v.push_back(-1);			
			return v;
		}
		// auto first=nums.begin();
		// auto last=nums.end();
		// auto len=last-first;
		// while(len>0)
		// {
		// 	auto half=len>>1;
		// 	auto mid=first+half;
		// 	if(*mid<target)
		// 	{
		// 		first=mid+1;
		// 		len=len-half-1;
		// 	}
		// 	else if(*mid>target)
		// 	{
		// 		len=half;
		// 		last=mid;
		// 	}
		// 	else
		// 	{

		// 	}
		// }
		int lower=lower_bound(nums,target);
		if(nums[lower]==target)
		{
			auto upper=upper_bound(nums,target);
			v.push_back(lower);
			v.push_back(upper-1);
		}
		else
		{
			v.push_back(-1);
			v.push_back(-1);
		}
		return v;
	}
private:

	int lower_bound(vector<int>&nums,int target)
	{
		auto first=nums.begin();
		auto last=nums.end();		
		auto len=last-first;
		ptrdiff_t half;
		vector<int>::iterator mid;
		while(len>0)
		{
			half=len>>1;
			mid=first+half;
			if(*mid<target)
			{
				first=mid+1;
				len=len-half-1;//因为last在这段代码里变化，所以通过这种方式求出len大小，-1是减去mid那个元素所占用的位置
			}
			else
				len=half;
		}
		return first-nums.begin();
	}
	int upper_bound(vector<int> &nums,int target)
	{
		auto first=nums.begin();
		auto last=nums.end();
		auto len=last-first;
		ptrdiff_t half;
		vector<int>::iterator mid;
		while(len>0)
		{
			half=len>>1;
			mid=first+half;
			if(*mid>target)
				len=half;
			else
			{
				first=mid+1;
				len=len-half-1;
			}
		}
		return first-nums.begin();
	}
};
int main(int argc, char const *argv[])
{
	vector<int> v={1,2,3,4,5,6,6,7,8,9,10};
	Solution so;
	std::vector<int> iv=so.searchRange(v,11);
	cout<<iv[0]<<'\t'<<iv[1]<<endl;
	return 0;
}