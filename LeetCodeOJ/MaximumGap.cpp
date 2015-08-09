// Maximum Gap
// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

// Try to solve it in linear time/space.

// Return 0 if the array contains less than 2 elements.

// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>		//INT_MIN,INT_MAX

using namespace std;
//这个题很难，我在网上搜到的是用桶排序，第一次听说这个名字，http://www.cnblogs.com/skysand/p/4179099.html
// 用桶排序
// 算出相邻两个桶之间的最大差值
// 如果是平均分布，则桶的数目和元素的数目相同时，其排序的时间复杂度是0(n)
// 我们假设桶的个数和元素的数目相同，若是平均分布，则每个桶里有一个数；而若某个桶里有两个以上的数时，这时必有至少一个是空桶，那么最大间隔可能就落在空桶的相邻两个
// 桶存储的数之间，最大间隔不会落在同一个桶的数里，因此我们不需要对每个桶再排一次序，只需要记录同一个桶的最大值和最小值，算出前一个有最大值的桶和后一个有
// 最小值的桶之差，则可能是最大间隔
//步骤：1.算好用的桶的个数，用最大元素和最小元素算出平均间隔，记录在平均间隔上的最大值和最小值，
// 2. 再算出前一个间隔里的最大值和后一个间隔里的最小值之差，取最大的一个，
// 3. 再算出最小值和第二小的差（平均间隔最小值第一个），最大值和第二大（平均间隔最大值最后一个）的差，三个值相比，取最大的，就是最大间隔
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if(nums.size()<2)
			return 0;
		auto maxVal=*max_element(nums.begin(),nums.end());//找出无序数组的最大值
		auto minVal=*min_element(nums.begin(),nums.end());//找出无序数组的最小值
		//ceil:返回大于或者等于指定表达式的最小整数
		int agGap=ceil((double)(maxVal-minVal)/(nums.size()-1));//根据鸽巢原理最大差值不会小于ceiling[(maxVal - minVal)/(N - 1)],也即一个桶中最多agGap个元素
		int bucketCount=ceil((double)(maxVal-minVal)/agGap);//桶的数量
		
		//记录每个桶中元素的最大值和最小值
		vector<pair<int,int>> buckets(bucketCount,make_pair(INT_MIN,INT_MAX));
		for(auto val:nums)
		{
			if(val==maxVal||val==minVal)//这两个元素，在下面计算最大间隔时直接用到了，故不放入桶中了。
				continue;
			int bucketNum=(val-minVal)/agGap;
			if(val>buckets[bucketNum].first)
				buckets[bucketNum].first=val;//存储最大值

			if(val<buckets[bucketNum].second)
				buckets[bucketNum].second=val;//存储最小值
		}
		
		//算出最大间隔
		int maxGap=0,lastMax=minVal;
		for(auto bucket: buckets)
		{
			if(bucket.first==INT_MIN)//空桶
				continue;

			int curMax=bucket.first,curMin=bucket.second;
			maxGap=max(maxGap,curMin-lastMax);
			lastMax=curMax;
		}
		maxGap=max(maxGap,maxVal-lastMax);
		return maxGap;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums={3,6,9,1,5,4,44,21,23,43};
	Solution so;
	cout<<so.maximumGap(nums)<<endl;
	return 0;
}
