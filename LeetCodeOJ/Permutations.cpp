// Permutations
// Given a collection of numbers, return all possible permutations（一组事物可能的一种）序列，排列，排列中的任一组数字或文字( permutation的名词复数 ).

// For example,
// [1,2,3] have the following permutations(序列，排列，排列中的任一组数字或文字):
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]

#include <iostream>
#include <vector>
//类似STL源码剖析上的一个next_permutation算法
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> rest_value;
		rest_value.push_back(nums);    	
		if(nums.size()<=1)
        		return rest_value;

        	int count=factorial(nums.size());
		for(int i=1;i<count;++i)
		{
			rest_value.push_back(next_permutation(rest_value[i-1]));
		}
		return rest_value;
    }
private:
	vector<int> next_permutation(vector<int> nums)
	{
		auto first=nums.begin();
		auto last=nums.end();
		auto ii=last-1;
		while(ii!=first)
		{
			auto i=ii-1;
			if(*i<*ii)
			{
				auto j=last;
				while(*(--j)<=*i) ;
				swap_iter(i,j);
				reverse(ii,last);
				return nums;
			}
			--ii;
		}
		reverse(ii,last);
		return nums;
	}
	void reverse(vector<int>::iterator i,vector<int>::iterator j)
	{
		while(i<j)
			swap_iter(i++,--j);
	}
	void swap_iter(vector<int>::iterator i,vector<int>::iterator j)
	{
		int temp=*i;
		*i=*j;
		*j=temp;
	}
	int factorial(int n)
	{
		int sum=1;
		while(n!=1)
		{
			sum*=n;
			--n;
		}
		return sum;
	}
	//擦，这里没有用到，还在担心输入的vector里有重复数字呢，若是那样，应该只能用下面的判断了
	bool equality(const vector<int> &v1,const vector<int> &v2)		
	{
		auto first1=v1.begin();
		auto first2=v2.begin();
		while(first1!=v1.end()&&first2!=v2.end())
		{
			if(*first1!=*first2)
				return false;
			++first1;
			++first2;
		}
		if(first1==v1.end()&&first2==v2.end())
			return true;
		else
			return false;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> v={1,2,3,4,5};
	Solution so;
	vector<vector<int>> rest_value=so.permute(v);
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
