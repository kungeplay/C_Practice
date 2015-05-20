// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
//The number of elements initialized in nums1 and nums2 are m and n respectively.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    		if (m<0||n<0)
    		{
    			return;
    		}

    		int n1=0,n2=0;
    		std::vector<int> numtemp;
    		while(n1!=m&&n2!=n)
    		{
    			if (nums1[n1]<nums2[n2])
    			{
    				numtemp.push_back(nums1[n1]);
    				++n1;
    			}
    			else
    			{
    				numtemp.push_back(nums2[n2]);
    				++n2;
    			}
    		}
    		if (n1!=m)
    		{
    			 numtemp.insert(numtemp.end(),nums1.begin()+n1,nums1.begin()+m);//这里insert最后一个参数之所以不是nums1.end()是由于串进来的m和n不一定刚好是两个vector的大小，可能只是让排前几数字。
    		}
    		else if(n2!=n)
    		{
    			 numtemp.insert(numtemp.end(),nums2.begin()+n2,nums2.begin()+n);
    		}

    		nums1=numtemp;
    }
};
int main(int argc, char const *argv[])
{
	Solution so;
	std::vector<int> nums1{1,3};
	std::vector<int> nums2{2,4};
	so.merge(nums1,1,nums2,nums2.size());
	for (const auto & i : nums1)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	return 0;
}