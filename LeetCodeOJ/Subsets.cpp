// Subsets
//  Given a set of distinct integers, nums, return all possible subsets.

// Note:

//     Elements in a subset must be in non-descending order.
//     The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include <iostream>
#include <vector>
using namespace std;
//不算难的题，多想一想就出来
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    		quickSort(nums);
    		vector<vector<int>> v_subsets;
    		vector<int> v_null;
    		v_subsets.push_back(v_null);
    		int len_nums=nums.size();
    		for(int i=0;i<len_nums;++i)
    		{
    			int len=v_subsets.size();
    			for(int j=0;j<len;++j)
    			{
    				vector<int> temp=v_subsets[j];
    				temp.push_back(nums[i]);
    				v_subsets.push_back(temp);
    			}
    		}
    		return v_subsets;
    }
private:
	void quickSort(vector<int> &nums)
	{
		qSort(nums,0,nums.size()-1);
	}
	void qSort(vector<int> &nums,int low,int high)
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
		int pivotValue=nums[low];
		while(low<high)
		{
			while(low<high&&nums[high]>pivotValue)	--high;
			nums[low]=nums[high];
			while(low<high&&nums[low]<=pivotValue)	++low;
			nums[high]=nums[low];
		}
		nums[low]=pivotValue;
		return low;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> nums={1,2,3};
	Solution so;
	vector<vector<int>> v_subsets=so.subsets(nums);
	for(size_t i=0;i<v_subsets.size();++i)
	{
		for(size_t j=0;j<v_subsets[i].size();++j)
			cout<<v_subsets[i][j]<<'\t';
		cout<<endl;
	}
	return 0;
}