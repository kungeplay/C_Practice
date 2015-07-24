/*
Longest Consecutive(连续的，连贯的) Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
*/
#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;
//在思考这个题的算法过程中我想过用hash表，unordered_set来存储，但又想了想以前没用过hash表且若用C语言做还得实现hash表，感觉不太现实，所以就把
//这想法给打消了，但在网上查别人的思路，发现竟然大都是hash表，看来以后要再多坚持自己的想法。
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    		if(nums.size()==0)
    			return 0;
    		unordered_set<int> sequence;
    		for(auto iter=nums.begin();iter!=nums.end();++iter)
    		{
    			sequence.insert(*iter);
    		}
    		int len=1;
    		int max=len;
    		while(!sequence.empty())
    		{
    			auto cur=sequence.cbegin();
    			int nextCur=*cur-1;
    			sequence.erase(cur);
    			len=1;
			while(sequence.find(nextCur)!=sequence.end())
			{
				++len;
				sequence.erase(nextCur);
				--nextCur;
			}
			nextCur=*cur+1;
			while(sequence.find(nextCur)!=sequence.end())
			{
				++len;
				sequence.erase(nextCur);
				++nextCur;
			}
			if(max<len)
				max=len;
    		}
    		return max;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums={100, 4, 200, 1, 3, 2,5};
	Solution so;
	cout<<so.longestConsecutive(nums)<<endl;
	return 0;
}