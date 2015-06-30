// Jump Game
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false. 
#include <iostream>
#include <vector>
using namespace std;
//这个题想了一会，想出来这种做法，应该是最高效的了，从后往前找，认为处于post位置上是可以到达最后一个位置上的，然后判断前一个位置的最大跳能否超过它
class Solution {
public:
    bool canJump(vector<int>& nums) {
    		int len=nums.size();
    		if(len<=1)
    			return true;
  		int post=len-1; 
  		for(int i=post-1;i>=0;--i)
  		{
  			if(i+nums[i]>=post)
  				post=i;
  		}
  		if(post==0)
  			return true;
  		else
  			return false;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> nums={3,2,1,0,4};
	Solution so;
	cout<<so.canJump(nums)<<endl;
	return 0;
}
