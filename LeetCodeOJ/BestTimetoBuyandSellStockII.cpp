// Best Time to Buy and Sell Stock II
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>

using namespace std;

//静下心来，多想一想，多举例子试一试。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    		int nums=prices.size();
    		bool is_hold=false;
    		int low=0;
    		int max=0;
    		for(int i=1;i<nums;++i)
    		{
    			if(prices[i]>prices[i-1]&&!is_hold)
    			{
    				low=prices[i-1];
    				is_hold=true;//买入
    			}
    			else if(prices[i]<prices[i-1]&&is_hold)
    			{
    				max+=prices[i-1]-low;
    				is_hold=false;//卖出
    			}
    		}
    		if(is_hold)
    			max+=prices[nums-1]-low;
    		return max;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> prices={1,3,4,9,6,19};
	Solution so;
	cout<<so.maxProfit(prices)<<endl;
	return 0;
}