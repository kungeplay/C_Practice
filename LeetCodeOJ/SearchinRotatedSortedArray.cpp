// Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot(中心点，支杻，杻轴) unknown to you beforehand(事先，提前，预先，提前的，准备好的).
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        	int len=nums.size();
        	if (len==0||(target<nums[0]&&target>nums[len-1]))
        	{
        		return -1;
        	}
        	int minindex=-1;
        	if((minindex=findMinIndex(nums))==-1)
        		return -1;
        	cout<<minindex<<endl;
        	if (target>=nums[0]&&target<=nums[minindex-1])
        	{
        		return BinSearch(nums,0,minindex-1,target);
        	}
        	else if (target>=nums[minindex]&&target<=nums[len-1])
        	{
        		return BinSearch(nums,minindex,len-1,target);
        	}
        	return -1;
    }
private:
    	//查找旋转数组中的最小数字索引,比如，2,3,0,1返回索引2
	int findMinIndex(const std::vector<int>& nums)
	{
		int low=0,mid=0,hight=nums.size()-1;
		while(hight-low>1)
		{
			mid=(hight+low)/2;
			//如果中间元素位于前面的递增子树组，那么它应该大于或等于第一个指针指向的元素。
			//此时数组中最小的元素应该位于该中间元素的后边。我们可以把第一个指针指向该中间元素，这样就可以缩小寻找的范围.
			if(nums[mid]>nums[low])			
				low=mid;
			//如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指向的元素。
			//此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样也可以缩小寻找范围.
			else if (nums[mid]<nums[hight])
			{
				hight=mid;
			}
			else
				return -1;
		}
		return hight;

	}
	//二分查找元素
	int BinSearch(const std::vector<int>&nums,int low,int hight,int & target)
	{
		int mid=-1;
		while(low<=hight)
		{
			mid=(low+hight)/2;
			if (nums[mid]<target)
			{
				low=mid+1;
			}
			else if (nums[mid]>target)
			{
				hight=mid-1;
			}
			else
				return mid;
		}
		return -1;
	}

};
int main(int argc, char const *argv[])
{
	Solution so;
	std::vector<int> v{5};
	cout<<so.search(v,5)<<endl;
	return 0;
}
