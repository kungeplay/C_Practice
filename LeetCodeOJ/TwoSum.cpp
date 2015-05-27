// Two Sum
// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
// Please note that your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2 
// 这个题我刚开始是想来个循环里套循环，此时时间复杂度为O(n^2),提交后提示超时，后来在网上查到map底层使用红黑树实现的，所以它的查找时间是O(logN)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> v;    	
    		int len=nums.size();
    		std::map<int,int> mapcontainer;
  		for (int i = 0; i < len; ++i)
		{	
			//若当前元素没有插入到map中，则插入到map表里，key为元素值，value为元素索引。
			if(mapcontainer.find(nums[i])==mapcontainer.end())
				mapcontainer.insert(make_pair(nums[i],i));
			else if(nums[i]*2==target)//若碰到重复元素，则直接判断
			{
				if (i<mapcontainer.at(nums[i]))
				{
					v.push_back(i+1);
					v.push_back(mapcontainer.at(nums[i])+1);									
				}
				else
				{
					v.push_back(mapcontainer.at(nums[i])+1);
					v.push_back(i+1);
				}

				return v;
			}
		}
		for(auto iter=mapcontainer.begin();iter!=mapcontainer.end();++iter)
		{
			if (mapcontainer.find(target-iter->first)!=mapcontainer.end())//map底层使用红黑树实现的，所以它的查找时间是O(logN)
			{
				if (iter->second<mapcontainer.at(target-iter->first))
				{
					v.push_back(iter->second+1);
					v.push_back(mapcontainer.at(target-iter->first)+1);
				}
				else
				{
					v.push_back(mapcontainer.at(target-iter->first)+1);
					v.push_back(iter->second+1);					
				}
				return v;
			}
		}
		return v;
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
