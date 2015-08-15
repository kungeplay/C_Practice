#include <iostream>
#include <vector>
using namespace std;
//寻找最大的K个数，这里采用的是快排，时间复杂度为O(N);也可以用堆排序，，但当面对海量数据时，块排的一次划分就不能再使用了，
//依然可以使用堆，还可以使用分治法。
class Solution
{
public:
	vector<int> getNumbers(vector<int> & nums,int k)
	{
		vector<int> kNums;
		int len=nums.size();
		if(len<k||k<=0)
			return kNums;
		quickSort(nums,0,nums.size()-1,k-1);
		for(int i=0;i<k;++i)
		{
			kNums.push_back(nums[i]);
		}
		return kNums;	
	}
private:
	void quickSort(vector<int> &nums,int low,int hight,int k)
	{
		if(low<hight)
		{
			int pivort=Partition(nums,low,hight);
			if(pivort>k)
				quickSort(nums,low,pivort-1,k);
			else if(pivort<k)
				quickSort(nums,pivort+1,hight,k);
		}
	}
	int Partition(vector<int> &nums,int low,int hight)
	{
		int pivortValue=nums[low];
		while(low<hight)
		{
			while(low<hight&&pivortValue>nums[hight])	--hight;
			nums[low]=nums[hight];
			while(low<hight&&pivortValue<=nums[low])	++low;
			nums[hight]=nums[low];
		}
		nums[low]=pivortValue;
		return low;
	}
};
//通过堆排序来寻找最大的k个值
class SolutionHeap{
public:
	vector<int> getNumbers(vector<int>& nums,int k)
	{	
		vector<int> minHeap;
		int len=nums.size();
		if(len<k||k<=0)
			return minHeap;
		for(int i=0;i<k;++i)
		{
			minHeap.push_back(nums[i]);
		}
		makeHeap(minHeap);
		for(int i=k;i<len;++i)
		{
			pushHeap(minHeap,nums[i]);
		}	
		return minHeap;
	}
private:
	void makeHeap(vector<int>& minHeap)//建堆，由下而上
	{	
		
		int len=minHeap.size();
		if(len<2)//如果元素长度为0或1，不必重新排列
			return;
		int parent=len/2-1;
		while(parent>=0)
		{
			adjustHeap(minHeap,parent);
			--parent;
		}
				
	}
	void adjustHeap(vector<int> &minHeap,int parent)//调整堆，自上而下，
	{
		int len=minHeap.size();
		int rightChild=2*parent	+2;
		while(rightChild<len)//存在右子节点
		{
			if(minHeap[rightChild]>minHeap[rightChild-1])//如果右子节点值小于左子节点值
				rightChild-=1;
			if(minHeap[rightChild]<minHeap[parent])
			{
				swap(minHeap[rightChild],minHeap[parent]);
				parent=rightChild;
				rightChild=2*parent+2;
			}
			else
			       	break;
		}
		if(rightChild==len)//没有右子节点
		{
			if(minHeap[rightChild-1]<minHeap[parent])
			{
				swap(minHeap[parent],minHeap[rightChild-1]);
			}
		}
	}
	void pushHeap(vector<int> &minHeap,int value)
	{
		if(value<minHeap[0])
			return;
		minHeap[0]=value;
		adjustHeap(minHeap,0);
	}
};
int main(int argc,char *argv[])
{
	Solution so;
	vector<int> nums={3,1,7,4,0,2,5,23,12,54,8,6,5};
	vector<int> kNums=so.getNumbers(nums,5);
	for(auto value : kNums)
	{
		cout<<value<<"\t";
	}
	cout<<endl;

	vector<int> nums2={51,4,3,12,10,7,11,8,14,20,102,40,100,200,300,400,102};
	SolutionHeap soheap;
	vector<int> minHeap=soheap.getNumbers(nums2,9);
	for(auto value : minHeap)
	{
		cout<<value<<"\t";
	}
	cout<<endl;
}
