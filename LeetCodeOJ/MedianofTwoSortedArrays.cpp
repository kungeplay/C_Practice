// Median of Two Sorted Arrays 
// There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. 
// The overall run time complexity should be O(log (m+n)).
#include <iostream>
#include <vector>
using namespace std;
//其实相当与求两个有序数组的第K小数,这个题挺难的。要深入理解牢记
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m=nums1.size();
        size_t n=nums2.size();
        size_t total=m+n;
        if (total&0x1)//元素总数为奇数
        {
        		return findKth(nums1,0,nums2,0,total/2+1);
        }
        else//元素总数为偶数
        {
        		return (findKth(nums1,0,nums2,0,total/2)+findKth(nums1,0,nums2,0,total/2+1))/2;
        }
    }
private:
    double findKth(vector<int>& a,size_t begin1,vector<int> & b,size_t begin2,size_t key)
    {
    		if (a.size()-begin1>b.size()-begin2)//始终保持a数组的元素数小于b数组
    		{
    			return findKth(b,begin2,a,begin1,key);
    		}
    		if (begin1==a.size())//如果a数组元素数为0
    		{
    			return b[key-1];
    		}
    		if (key==1)//如果K==1
    		{
    			return min(a[begin1],b[begin2]);
    		}
    		size_t pa=min(key/2,a.size()-begin1);
    		size_t pb=key-pa;
    		if (a[begin1+pa-1]<b[begin2+pb-1])//说明a数组前pa个数位于第K数的前面，故丢弃这a数组中从索引begin1到begin1+pa-1个数
    		{
    			return findKth(a,begin1+pa,b,begin2,key-pa);
    		}
    		else if (a[begin1+pa-1]>b[begin2+pb-1])//说明b数组前pb个数位于第K数的前面，故丢弃b数组中从索引begin2到begin2+pb-1个数
    		{
    			return findKth(a,begin1,b,begin2+pb,key-pb);
    		}
    		else
    		{
    			return a[begin1+pa-1];
    		}
    }
    template<typename T> T min(T i,T j)
    {
    		return i<j?i:j;
    }
};
int main(int argc, char const *argv[])
{
	std::vector<int> nums1={1,3,5,7,9,10};
	std::vector<int> nums2={0,2,4,6,8};
	Solution so;
	cout<<so.findMedianSortedArrays(nums1,nums2)<<endl;;
	return 0;
}
