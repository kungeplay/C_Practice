// Gas Station( 加油站)
// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank(箱; 贮水池) and it costs cost[i] of gas to travel from station i to its next station (i+1). 
//You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique. 
#include <iostream>
#include <vector>
using namespace std;
//想了一会，想出来个这方法，叫什么方法来着，求循环数组中连续子序列和中不存在小于0值的起点
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len=gas.size();
		if(len<2)
		{
			if(gas[0]-cost[0]>=0)//要注意边界条件
				return 0;
			else
				return -1;
		}
		int start=0;
		int sum=gas[0]-cost[0];
		int end=1;
		while(start!=end)
		{
			if(sum>=0)//如果sum大于0，end向后移动
			{
				sum+=gas[end]-cost[end];
				++end;
				if(end==len)
					end=0;
			}
			if(sum<0)//如果sum小于0，则始发站向前移动
			{
				--start;
				if(start==-1)
					start=len-1;
				sum+=gas[start]-cost[start];
			}
		}
		if(sum<0)
			return -1;
		return start;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> gas={2,5,7,4,3,8,10};
	vector<int> cost={1,2,12,3,1,5,15};
	Solution so;
	cout<<so.canCompleteCircuit(gas,cost)<<endl;
	return 0;
}