// Best Time to Buy and Sell Stock
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//静静的想了有一会，想出来这个O(n)的算法，我的这个脑子呀
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    		int nums=prices.size();
    		int max=0;
    		int low=0;
    		for(int i=1;i<nums;++i)
    		{
    			if(prices[i]<prices[low])
    				low=i;
    			else if(prices[i]-prices[low]>max)
    				max=prices[i]-prices[low];
    		}
    		return max;
    }
};
