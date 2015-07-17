// Search in Rotated Sorted Array II
// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?
// Write a function to determine if a given target is in the array.

#include <iostream>
#include <vector>

using namespace std;
//不容易呀，没想到允许重复的元素，竟然要改动这么多地方，要考虑的细节太多了。
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    		int len=nums.size();
    		if(len==0||(target<nums[0]&&target>nums[len-1]))
    			return false;

    		if(nums[0]==target)
    			return true;

    		int i=0;
    		while(i<len-1&&nums[i]==nums[len-1])//去掉开头与结尾相等的元素
    			++i;
    		if(i==len-1)
    		{
			return false;
    		}

    		if(nums[i]<nums[len-1])//如果这时候已经元素已经升序，则直接折半查找
    			return BinSearch(nums,i,len-1,target);

         	int minindex=-1;
        	if((minindex=findMinIndex(i,nums))==-1)
        		return false;
         	if (target>=nums[0]&&target<=nums[minindex-1])
        	{
        		return BinSearch(nums,0,minindex-1,target);
        	}
        	else if (target>=nums[minindex]&&target<=nums[len-1])
        	{
        		return BinSearch(nums,minindex,len-1,target);
        	}
        	return false;       		   		 
    }
private:
    	//查找旋转数组中的最小数字索引,比如，2,3,0,1返回索引2
	int findMinIndex(int low,const std::vector<int>& nums)
	{
		int mid=0,hight=nums.size()-1;
		while(hight-low>1)
		{
			mid=(hight+low)/2;
			//如果中间元素位于前面的递增子树组，那么它应该大于或等于第一个指针指向的元素。
			//此时数组中最小的元素应该位于该中间元素的后边。我们可以把第一个指针指向该中间元素，这样就可以缩小寻找的范围.
			if(nums[mid]>=nums[low])	//相比Search in Rotated Sorted Array，这里要加个等号，否则像1，2，2，2，2，0存在nums[mid]==nums[low]的情况
				low=mid;
			//如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指向的元素。
			//此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样也可以缩小寻找范围.
			else if (nums[mid]<=nums[hight])
			{
				hight=mid;
			}
			else
			{
				return -1;
			}
		}
		return hight;

	}
	//二分查找元素
	bool BinSearch(const std::vector<int>&nums,int low,int hight,int & target)
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
				return true;
		}
		return false;
	}

};

int main(int argc, char const *argv[])
{
	Solution so;
	// std::vector<int> v{5,6,7,8,9,1,2,3,4,5};
	std::vector<int> v{8,9,9,9,9,9,2,2,4};
	cout<<so.search(v,)<<endl;
	return 0;
}