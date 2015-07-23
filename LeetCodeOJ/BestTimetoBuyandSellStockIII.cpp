// Best Time to Buy and Sell Stock III

// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>
using namespace std;

// 分析：动态规划法。以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]，
// 最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益。
// 第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
            
    		int daynums=prices.size();
    		if(daynums<2)
    		    return 0;
    		vector<int> preProfit(daynums);
    		vector<int> postProfit(daynums);

    		int CurMin=prices[0];//设第一天价格为最小的股票价格
    		preProfit[0]=0;
    		for(int i=1;i<daynums;++i)
    		{
    			CurMin=min(CurMin,prices[i]);//获取前i天中最小的股票价格
    			preProfit[i]=max(preProfit[i-1],prices[i]-CurMin);//拿当前股票收益与前1天的最大股票收益进行对比，取最大
    		}

    		int CurMax=prices[daynums-1];//设最后1天股票价格为最大价格
    		preProfit[daynums-1]=0;
    		for(int i=daynums-2;i>=0;--i)
    		{
    			CurMax=max(CurMax,prices[i]);//获取第i天后的最大股票价格
    			postProfit[i]=(postProfit[i+1],CurMax-prices[i]);//拿当前股票收益与前i+1天的最大股票收益进行对比，取最大值
    		}

    		int sum=0;
    		for(int i=0;i<daynums;++i)
    		{
    			sum=max(sum,preProfit[i]+postProfit[i]);
    			cout<<preProfit[i]<<'\t'<<postProfit[i]<<endl;
    		}
    		return sum;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> prices={1,2};
	Solution so;
	cout<<so.maxProfit(prices)<<endl;
	return 0;
}