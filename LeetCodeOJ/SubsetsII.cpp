//Subsets II
// Given a collection of integers that might contain duplicates(复制的,完全相同的,复制品), nums, return all possible subsets.
//Note:
//    Elements in a subset must be in non-descending order.
//    The solution set must not contain duplicate subsets.
// For example,If nums = [1,2,2], a solution is:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
//不容易哈，提交后竟然没有超时，我用了两个set,先把所有的都放进vector和set里，然后逐个的去掉一个数字，再放到vector和另一个set里。
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    		std::vector<std::vector<int> > vresult;
    		int vindex=0;

    		sort(nums.begin(),nums.end());
    		vresult.push_back(nums);
    		set<std::vector<int>> set1;
    		set1.insert(nums);
    		while(set1.size()>0)
    		{
    			set<vector<int>> set2;
    			for (const auto &setv1 : set1)
    			{
    				for (int i = 0; i < setv1.size(); ++i)
    				{
    					std::vector<int> vtemp;
    					for (int j = 0; j < setv1.size(); ++j)
    					{
    						if(j!=i)
    						{
    							vtemp.push_back(setv1[j]);
    						}
    					}
    					 if (vtemp.size()>0)
    					 {
    						set2.insert(vtemp);
    					 }
    				}

    			}
    			set1=set2;
    			for (const auto &setv2: set2)
    			{
    				vresult.push_back(setv2);
    			}
    			if (set2.size()==0)
    			{
    				std::vector<int> v;
    				vresult.push_back(v);
    			}
    		}
    		return vresult;
    }
};
int main(int argc, char const *argv[])
{
	Solution sol;
	std::vector<std::vector<int> > vresult;
	std::vector<int> v({2,1,2,4});
	vresult=sol.subsetsWithDup(v);
	for (std::vector<std::vector<int> >::iterator i = vresult.begin(); i != vresult.end(); ++i)
	{
		for (std::vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j)
		{
			cout<<*j<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
