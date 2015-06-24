// Combination Sum 
// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:

//     All numbers (including target) will be positive integers.
//     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//     The solution set must not contain duplicate combinations.

// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3] 
#include <iostream>
#include <vector>
using namespace std;
//也不算很难的题
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target=target;
        vector<int> temp;
        quickSort(candidates);

        for(size_t i=0;i<candidates.size();++i)
        {
	        getCombination(candidates,temp,0,i);
	    }
        return resv;
    }
private:
	int target;
	vector<vector<int>> resv;
	void getCombination(const vector<int> & candidates,vector<int> temp,int sum,int current)
	{
		sum+=candidates[current];
		temp.push_back(candidates[current]);		
		if(sum==target)
		{
			resv.push_back(temp);
		}
		else if(sum<target)
		{
			for(size_t i=current;i<candidates.size();++i)
				getCombination(candidates,temp,sum,i);
		}
	}
	void quickSort(vector<int> &candidates)
	{
		qSort(candidates,0,candidates.size()-1);
	}
	void qSort(vector<int> &candidates,int low,int high)
	{
		if(low<high)
		{
			int pivotloc=Partition(candidates,low,high);
			qSort(candidates,low,pivotloc-1);
			qSort(candidates,pivotloc+1,high);
		}
	}
	int Partition(vector<int>& candidates,int low,int high)
	{
		int pivotkey=candidates[low];
		while(low<high)
		{
			while(low<high&&pivotkey<=candidates[high]) --high;
			candidates[low]=candidates[high];
			while(low<high&&candidates[low]<=pivotkey)	++low;
			candidates[high]=candidates[low];
		}
		candidates[low]=pivotkey;
		return low;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> candidates={8,7,4,3};
	Solution so;
	vector<vector<int>> resv=so.combinationSum(candidates,11);
	for(size_t i=0;i<resv.size();++i)
	{
		for(size_t j=0;j<resv[i].size();++j)
		{
			cout<<resv[i][j]<<'\t';
		}
		cout<<endl;
	}

	return 0;
}