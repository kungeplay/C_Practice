// Next Permutation(排列，组合)
// Implement next permutation, which rearranges(重新排列) numbers into the lexicographically(辞典编撰上的) next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//察，怎么会这么巧，刚在STL源码剖析上看到实现上一个组合或下一个组合的算法p380
//结果就在LeetCode上看到了这个算法题
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

    		if(nums.size()<=1)
    			return;
    		auto last=nums.end();
 
    		for(auto ii=last-1;ii>nums.begin();--ii)
    		{
    			auto i=ii-1;
    			if(*i<*ii)
    			{
    				auto j=last;
    				while(*i>=*(--j));
    				swap_iter(i,j);
    				reverse(ii,last);
    				return;
    			}
    		}
    		reverse(nums.begin(),nums.end());
    }
private:
	void swap_iter(vector<int>::iterator a,vector<int>::iterator b)
	{
		auto temp=*a;
		*a=*b;
		*b=temp;
	}
	void reverse(vector<int>::iterator first,vector<int>::iterator last)//要会写这么简洁的代码
	{
		while(first<last)
		{
			swap_iter(first++,--last);
		}
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v={1,5,1};
	Solution so;
	so.nextPermutation(v);
	for (auto i : v)
		cout<<i<<'\t';
	cout<<endl;
	return 0;
}
