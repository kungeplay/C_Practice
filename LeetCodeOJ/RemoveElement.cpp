// Remove Element 
// Given an array and a value, remove all instances of that value in place(in place:在对的位置; 适当的; 在工作; 准备就绪) and return the new length.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
#include <vector>
#include <iostream>

using namespace std;
//不是很难
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		if(nums.size()==0)
			return 0;
		int i=0;
		int j=0;
		while(j<nums.size())
		{
			if(i==j&&nums[i]!=val)
			{
				++i;
				++j;
			}
			else
			{
				if(nums[j]!=val)
					nums[i++]=nums[j];
				++j;
			}

		}
		return i;
    }
};
int main(int argc, char const *argv[])
{
	vector<int>nums={1,1};
	cout<<nums.size()<<endl;
	Solution so;
	cout<<so.removeElement(nums,1)<<endl;
	return 0;
}