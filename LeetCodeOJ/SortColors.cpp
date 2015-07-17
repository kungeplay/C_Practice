// Sort Colors
// Given an array with n objects colored red, white or blue, 
//sort them so that objects of the same color are adjacent(相邻; 邻近的，毗邻的; 紧接着的（时间上), with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note:
// You are not suppose to use the library's sort function for this problem. 
#include <iostream>
#include <vector>
using namespace std;

//不算难，又复习了快速排序算法，也可以统计红绿蓝分别有多少个，然后重新给数组赋值
class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums);
    }
private:
	void quickSort(vector<int>&nums)
	{
		qSort(nums,0,nums.size()-1);
	}
	void qSort(vector<int> &nums,int low,int high)
	{
		if(low<=high)
		{
			int pivotloc=Partition(nums,low,high);
			qSort(nums,low,pivotloc-1);
			qSort(nums,pivotloc+1,high);
		}

	}
	int Partition(vector<int> & nums,int low,int high)
	{
		int pivotValue=nums[low];
		while(low<high)//大小关系不要搞错了
		{
			while(low<high&&nums[high]>pivotValue)	--high;
				nums[low]=nums[high];
			while(low<high&&nums[low]<=pivotValue)	++low;
				nums[high]=nums[low];
		}
		nums[low]=pivotValue;
		return low;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> nums={1,2,0,2,2,1,1,1,0,0,1};
	// vector<int> nums={1,2,0,3};

	Solution so;
	so.sortColors(nums);
	for(auto iter=nums.begin();iter!=nums.end();++iter)
	{
		cout<<*iter<<'\t';
	}
	cout<<endl;
	return 0;
}
