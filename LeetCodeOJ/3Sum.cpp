// 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

//     Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//     The solution set must not contain duplicate triplets.

//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)
//察，真不容易，这个题，做了两整天，把所有想到的map,set都用到了，还总是超时，最后参考别人写的博客才成功，要记下呀，总结在我的博客里
#include <vector>
#include <iostream>
#include <set>
using namespace std;
//这个方法超时
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) 
//     {
//     		set<vector<int>> settriplets;
//     		if (nums.size()==0)
//     		{
//     			return setToVector(settriplets);
//     		}
//     		quickSort(nums);
//     		int high=nums.size()-1;
//     		while(high>-1&&nums[high]>=0)
//     		{
//     			for(int i=0;i<high;++i)
//     			{
//     				int index=searchBin(nums,i+1,high-1,-nums[i]-nums[high]);
//     				if(index==-1)
//     					continue;
//     				else
//     				{
//     					std::vector<int> iv={nums[i],nums[index],nums[high]};
//     					settriplets.insert(iv);

//     				}
//     			}
//     			--high;
//     		}
//     		return setToVector(settriplets);
//     }
// private:

// 	void quickSort(vector<int> &nums)
// 	{
// 		qSort(nums,0,nums.size()-1);
// 	}
// 	void qSort(vector<int>& nums,int low,int high)
// 	{
// 		if(low<high)
// 		{
// 			int pivotloc=Partition(nums,low,high);
// 			qSort(nums,low,pivotloc-1);
// 			qSort(nums,pivotloc+1,high);
// 		}
// 	}
// 	int Partition(vector<int>&nums,int low,int high)
// 	{
// 		int pivotkey=nums[low];
// 		while(low<high)
// 		{
// 			while(low<high&&nums[high]>=pivotkey) --high;
// 			nums[low]=nums[high];
// 			while(low<high&&nums[low]<=pivotkey) ++low;
// 			nums[high]=nums[low];
// 		}
// 		nums[low]=pivotkey;
// 		return low;
// 	}

// 	int searchBin(const vector<int>& nums, const int &lowindex,const int & highindex,const int &elem)
// 	{
// 		int low=lowindex;
// 		int high=highindex;
// 		int mid=(low+high)/2;
// 		while(low<=high)
// 		{
// 			int mid=(low+high)/2;
// 			if(nums[mid]>elem)
// 				high=mid-1;
// 			else if(nums[mid]<elem)
// 				low=mid+1;
// 			else
// 				return mid;
// 		}
// 		return -1;
// 	}
// 	vector<vector<int>> setToVector(const set<vector<int>> &settriplets)
// 	{
// 		return vector<vector<int>> (settriplets.begin(),settriplets.end());
// 	}
// };

//-----------------------------//
//这个方法也超时
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) 
//     {
//     		set<vector<int>> settriplets;

//     		if(nums.size()<3)
//     			return setToVector(settriplets);

//     		multiset<int> nums_multiset(nums.begin(),nums.end());

//     		auto iterbegin=nums_multiset.begin();
//     		auto iterlast=--nums_multiset.end();


//     		if((*iterbegin)*(*iterlast)>0)
//     			return setToVector(settriplets);

// 		if(nums_multiset.count(0)>2)
// 		{
// 			vector<int> iv={0,0,0};
// 			settriplets.insert(iv);
// 		}

//     		if(((*iterbegin)*(*iterlast)==0))
//     		{

//     			return setToVector(settriplets);
//     		}
//     		else
//     		{
//     			while(*iterlast>0)
//     			{
//     				for(auto iter=nums_multiset.begin();iter!=iterlast;++iter)
//     				{
//     					auto iterindex=nums_multiset.find(-(*iterlast)-(*iter));
//     					if(iterindex!=nums_multiset.end()&&iterindex!=iter&&iterindex!=iterlast)
//     					{
//     						if(*iterindex<*iter)
//     						{
// 							vector<int> iv={*iterindex,*iter,*iterlast};
// 							settriplets.insert(iv);
//     						}
//     						else if(*iterindex>=*iter&&*iterindex<=*iterlast)
//     						{
// 		    					vector<int> iv={*iter,*iterindex,*iterlast};
// 							settriplets.insert(iv);		
//     						}
//     						else if(*iterindex>*iterlast)
//     						{
// 							vector<int> iv={*iter,*iterlast,*iterindex};
// 							settriplets.insert(iv);
//     						}
//     					}
//     				}
//     				--iterlast;
//     			}
//     			return setToVector(settriplets);
//     		}

//     }
// private:
// 	vector<vector<int>> setToVector(const set<vector<int>> &settriplets)
// 	{
// 		return vector<vector<int>> (settriplets.begin(),settriplets.end());
// 	}	
// };
//在网上找到的，这个方法不超时
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
    		vector<vector<int>> triplets;
    		if (nums.size()<3)
    		{
    			return triplets;
    		}
    		quickSort(nums);
    		for(int i=0;nums[i]<=0;++i)
    		{

    			if(i>0&&nums[i-1]==nums[i])
    				continue;

    			int j=i+1;
    			int n=nums.size()-1;
    			while(j<n)
    			{
    	    			int sum=nums[j]+nums[n];			
	    			if (sum==-nums[i])
	    			{
					vector<int> iv={nums[i],nums[j],nums[n]};
					triplets.push_back(iv);
					do
					{
						++j;
					} while (nums[j-1]==nums[j]);
					do
					{
						--n;
					}
					while(nums[n]==nums[n+1]);
	    			}
	    			else if(sum>-nums[i])
	    			{
	    				--n;
	    			}
	    			else 
	    			{
	    				++j;
	    			}
	    		}
    		}
    		return triplets;

    }

private:
    //快速排序
	void quickSort(vector<int> &nums)
	{
		qSort(nums,0,nums.size()-1);
	}
	void qSort(vector<int>& nums,int low,int high)
	{
		if(low<high)
		{
			int pivotloc=Partition(nums,low,high);
			qSort(nums,low,pivotloc-1);
			qSort(nums,pivotloc+1,high);
		}
	}
	int Partition(vector<int>&nums,int low,int high)
	{
		int pivotkey=nums[low];
		while(low<high)
		{
			while(low<high&&nums[high]>=pivotkey) --high;//别忘了low<high
			nums[low]=nums[high];
			while(low<high&&nums[low]<=pivotkey) ++low;//别忘了low<high
			nums[high]=nums[low];
		}
		nums[low]=pivotkey;
		return low;
	}
};


int main(int argc, char const *argv[])
{
	Solution so;
	// vector<int> v={0,0,0};
	vector<int> v={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	// vector<int> v={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<vector<int>> rv=so.threeSum(v);
	for(auto viter=rv.begin();viter!=rv.end();++viter)
	{
		for(auto iiter=(*viter).begin();iiter!=(*viter).end();++iiter)
		{
			cout<<*iiter<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
