// 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:

//     Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//     The solution set must not contain duplicate quadruplets.

//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)
#include <vector>
#include <iostream>
using namespace std;

//这个题，和前边的3Sum类似，最终要划分为两个元素的和的问题，主要考虑的难点是去重，别的就是快速排序
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

    		vector<vector<int>> quadruplets;

    		if(nums.size()<4)
    			return quadruplets;

        quickSort(nums);
        for(int i=0;i<nums.size()-3;++i)
        {
        		if(i>0&&nums[i-1]==nums[i])//去重
        			continue;
        		for(int j=i+1;j<nums.size()-2;++j)
        		{
        			if(j>i+1&&nums[j-1]==nums[j])//去重
        				continue;
        			int k=j+1;
        			int l=nums.size()-1;
        			while(k<l)
        			{
        				int sum=nums[i]+nums[j]+nums[k]+nums[l];
        				if(sum==target)
        				{
        					vector<int> iv={nums[i],nums[j],nums[k],nums[l]};

        					quadruplets.push_back(iv);
        					do
        					{
        						++k;
        					}while(k<nums.size()&&nums[k-1]==nums[k]);//去重
        					do
        					{
        						--l;
        					}while(l>j&&nums[l+1]==nums[l]);//去重

        				}
        				else if(sum<target)
        				{
        					do
        					{
        						++k;
        					}while(k<nums.size()&&nums[k-1]==nums[k]);//去重
        				}
        				else
        				{
        					do
        					{
        						--l;
        					}while(l>j&&nums[l+1]==nums[l]);//去重
        				}
        			}
        		}
        }
        return quadruplets;

    }
private:
    //快速排序
	void quickSort(vector<int> &nums)
	{
		qSort(nums,0,nums.size()-1);
	}
	void qSort(vector<int>&nums,int low,int high)
	{
		if(low<high)
		{
			int pivotloc=Partition(nums,low,high);
			qSort(nums,low,pivotloc-1);
			qSort(nums,pivotloc+1,high);
		}
	}
	int Partition(vector<int> &nums,int low,int high)
	{
		int pivotkey=nums[low];
		while(low<high)
		{
			while(low<high&&nums[high]>=pivotkey) --high;
			nums[low]=nums[high];
			while(low<high&&nums[low]<=pivotkey) ++low;
			nums[high]=nums[low];
		}
		nums[low]=pivotkey;
		return low;
	}

};

int main(int argc, char const *argv[])
{	
	vector<int> iv={0,0 ,0 ,0 ,0 ,0};
	Solution so;
	vector<vector<int>> v=so.fourSum(iv,0);
	for (std::vector<vector<int>>::iterator i = v.begin(); i != v.end(); ++i)
	{
		for (std::vector<int>::iterator iiter = (*i).begin(); iiter != (*i).end(); ++iiter)
		{
			cout<<*iiter<<"\t";
		}
		cout<<endl;
	}
	return 0;
}