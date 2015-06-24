// Combination Sum II
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:

//     All numbers (including target) will be positive integers.
//     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//     The solution set must not contain duplicate combinations.

// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6] 

#include <iostream>
#include <vector>
using namespace std;
//不算难的题，和上一个combinationSum题类似
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    		this->target=target;
    		quickSort(candidates);
    		vector<int> temp;
    		for(size_t i=0;i<candidates.size();++i)
    		{
    			if(i!=0&&candidates[i]==candidates[i-1])//去重,由于候选集合中可能存在重复数字
    				continue;
    			getCombination(candidates,temp,0,i);
    		}
    		return rest_value;
    }
private:
	int target;
	vector<vector<int>> rest_value;
private:

	void getCombination(vector<int>& candidates,vector<int> temp,int sum,size_t current)
	{
		sum+=candidates[current];
		temp.push_back(candidates[current]);
		if(sum==target)
		{
			rest_value.push_back(temp);
		}
		else if(sum<target)
		{
			for(size_t i=current+1;i<candidates.size();++i)
			{	if(i!=current+1&&candidates[i]==candidates[i-1])//去重,由于候选集合中可能存在重复数字
					continue;
				getCombination(candidates,temp,sum,i);
			}
		}
	}

	void quickSort(vector<int>& candidates)
	{
		qSort(candidates,0,candidates.size()-1);
	}
	void qSort(vector<int>& candidates,int low,int high)
	{
		if(low<high)
		{
			int pivortloc=partition(candidates,low,high);
			qSort(candidates,low,pivortloc-1);
			qSort(candidates,pivortloc+1,high);
		}
	}
	int partition(vector<int>& candidates,int low,int high)
	{
		int pivortvalue=candidates[low];
		while(low<high)
		{
			while(low<high&&pivortvalue<=candidates[high])	--high;
			candidates[low]=candidates[high];
			while(low<high&&candidates[low]<=pivortvalue)	++low;
			candidates[high]=candidates[low];
		}
		candidates[low]=pivortvalue;
		return low;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> candidates={2,2,2};//{10,1,2,7,6,1,5};
	Solution so;
	vector<vector<int>> rest_value=so.combinationSum2(candidates,4);
	for(size_t i=0;i<rest_value.size();++i)
	{
		for(size_t j=0;j<rest_value[i].size();++j)
		{
			cout<<rest_value[i][j]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}
