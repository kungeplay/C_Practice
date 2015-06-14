// 3Sum Closest 
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <vector>
#include <iostream>

using namespace std;
//这个题与上个3Sum有点类似，比那个简单了点
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
    		quickSort(nums);

    		int closetnum=0;
    		bool isCloset=false;
    		for(int i=0;i<nums.size();++i)
    		{

    			int j=i+1;
    			int n=nums.size()-1;
    			if(j>=n||j==nums.size())
    				continue;
    			while(j<n)
    			{

	    			int sum=nums[i]+nums[j]+nums[n];
	    			if(isCloset==false)
	    			{
	    				closetnum=sum;
	    				isCloset=true;
	    			}
	    			else if(minusFabs(sum,target)<minusFabs(closetnum,target))
	    			{	
	    				closetnum=sum;
	    			}
	    			if(sum<target)
	    			{
	    				++j;
	    			}
	    			else if(sum>target)
	    			{
	    				--n;
	    			}
	    			else
	    				return sum;
    			}
    		}
    		return closetnum;
    }

private:
    //快速排序
	void quickSort(vector<int> &nums)
	{
		qSort(nums,0,nums.size()-1);
	}
	void qSort(vector<int>& nums,int low,int high)
	{
		if(low<high)
		{
			int pivotloc=Partition(nums,low,high);
			qSort(nums,low,pivotloc-1);
			qSort(nums,pivotloc+1,high);
		}
	}
	int Partition(vector<int>&nums,int low,int high)
	{
		int pivotkey=nums[low];
		while(low<high)
		{
			while(low<high&&nums[high]>=pivotkey) --high;//别忘了low<high
			nums[low]=nums[high];
			while(low<high&&nums[low]<=pivotkey) ++low;//别忘了low<high
			nums[high]=nums[low];
		}
		nums[low]=pivotkey;
		return low;
	}

	int minusFabs(const int & a,const int & b)
	{
		return a>b?(a-b):(b-a);
	}
};
int main(int argc, char const *argv[])
{
	vector<int> v={0,1,2};

	Solution so;
	cout<<so.threeSumClosest(v,3)<<endl;
	return 0;
}