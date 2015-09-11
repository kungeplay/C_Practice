//剑指offer上的一个题，我突然想起来这个题，忘了怎么做的了，
//在网上查到思路，才知道剑指offer上也有这个题，哎，看我这脑子额
//题目：我们把只包含因子
//2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，
//因为它包含因子7。习惯上我们把1当做是第一个丑数。求按从小到大的顺序的
//第1500个丑数
//
//根据丑数的定义，丑数应该是另一个丑数乘以2、3或者5的结果（1除外）。因此我们可以创建一个数组，里面的数字是排好序的丑数。里面的每一个丑数是前面的丑数乘以2、
//3或者5得到的。
//这种思路的关键在于怎样确保数组里面的丑数是排好序的。我们假设数组中已经有若干个丑数，排好序后存在数组中。我们把现有的最大丑数记做M。现在我们来生成下一个丑数，
//该丑数肯定是前面某一个丑数乘以2、3或者5的结果。我们首先考虑把已有的每个丑数乘以2。在乘以2的时候，能得到若干个结果小于或等于M的。由于我们是按照顺序生成的，
//小于或者等于M肯定已经在数组中了，我们不需再次考虑；我们还会得到若干个大于M的结果，但我们只需要第一个大于M的结果，因为我们希望丑数是按从小到大顺序生成的，
//其他更大的结果我们以后再说。我们把得到的第一个乘以2后大于M的结果，记为M2。同样我们把已有的每一个丑数乘以3和5，能得到第一个大于M的结果M3和M5。
//那么下一个丑数应该是M2、M3和M5三个数的最小者。
//前面我们分析的时候，提到把已有的每个丑数分别都乘以2、3和5，事实上是不需要的，因为已有的丑数是按顺序存在数组中的。对乘以2而言，肯定存在某一个丑数T2，排在它
//之前的每一个丑数乘以2得到的结果都会小于已有最大的丑数，在它之后的每一个丑数乘以2得到的结果都会太大。我们只需要记下这个丑数的位置，同时每次生成新的丑数的时候，
//去更新这个T2。对乘以3和5而言，存在着同样的T3和T5
//
#include <iostream>
#include <vector>
using namespace std;

int min(int a,int b,int c)
{	
	int min=a<b?a:b;
	return min<c?min:c;
}

int GetUglyNumber_Solution(int index)
{
	vector<int> uglyArray(index);
	uglyArray[0]=1;

	int multiply2=0;
	int multiply3=0;
	int multiply5=0;

	int nextIndex=1;
	while(nextIndex<index)
	{
		int minNumber=min(uglyArray[multiply2]*2,uglyArray[multiply3]*3,uglyArray[multiply5]*5);
		uglyArray[nextIndex]=minNumber;
		while(uglyArray[multiply2]*2<=minNumber)
			++multiply2;
		while(uglyArray[multiply3]*3<=minNumber)
			++multiply3;
		while(uglyArray[multiply5]*5<=minNumber)
			++multiply5;
		++nextIndex;
	}
	return uglyArray[index-1]; 
}

int main(int argc,char *argv[])
{	

	cout<<"第1499个丑数是:"<<GetUglyNumber_Solution(1499)<<endl;
	cout<<"第1500个丑数是:"<<GetUglyNumber_Solution(1500)<<endl;
	cout<<"第1501个丑数是:"<<GetUglyNumber_Solution(1501)<<endl;
}

