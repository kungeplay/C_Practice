// Remove Duplicates from Sorted Array II
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice(两倍，两边，两次)?
// For example,
// Given sorted array nums = [1,1,1,2,2,3],
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
// It doesn't matter what you leave beyond the new length.
#include <iostream>
#include <vector>

using namespace std;
//和Remove Duplicates from Sorted Array那个题方法一样，感觉不难，主要是多想一想，模拟一下
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    		if(nums.size()<3)
    			return nums.size();

    		bool istwice=false;
    		size_t started=0;
    		size_t ended=1;
    		while(ended!=nums.size())
    		{
    			if(nums[started]==nums[ended])
    			{
    				if(!istwice)
    				{
    					nums[++started]=nums[ended];
    					istwice=true;
    				}
    			}
    			else
    			{
    				nums[++started]=nums[ended];
    				istwice=false;
    			}
    			++ended;
    		}
    		return ++started;
    }
};

int main(int argc, char const *argv[])
{
	std::vector<int> v={1,1,1,1,2,2,2,3,3,3};
	Solution so;
	cout<<so.removeDuplicates(v)<<endl;
	return 0;
}