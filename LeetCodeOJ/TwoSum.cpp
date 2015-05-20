// Two Sum
// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
// Please note that your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//暂时想到的最简单的方法
    vector<int> twoSum(vector<int>& nums, int target) {
    		int len=nums.size();
  		for (int i = 0; i < len; ++i)
		{
			for (int j = i+1; j < len; ++j)
			{
				if (nums[i]+nums[j]==target)
				{
					std::vector<int> sumv;
					sumv.push_back(i+1);
					sumv.push_back(j+1);
					return sumv;
				}
			}
			
		}      
    }
};

int main(int argc, char const *argv[])
{
	std::vector<int> v{2,7,11,15};
	Solution so;
	std::vector<int> sumv=so.twoSum(v,9);
	for (int i = 0; i < sumv.size(); ++i)
	{
		cout<<sumv[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
