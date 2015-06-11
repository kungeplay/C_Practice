// Reverse Integer
// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321 
#include <iostream>
#include <limits>
using namespace std;
//这个题主要难点是要判断翻转后是否溢
class Solution {
public:
	    int reverse(int x) 
	    {
	    		int num=0;
			if (x>0)
			{
				num=x%10;
				int max=(numeric_limits<int>::max)()/10;
				int maxremain=(numeric_limits<int>::max)()%10;
				while((x=x/10)!=0)
				{
		    			if(num>max||(num==max&&x%10>maxremain))//判断正数的话是否会溢出
	    				{
	    					return 0;
	    				}
					num=num*10+x%10;
				}
				return num;
			}
			else
			{
				num=x%10;
				int min=(numeric_limits<int>::min)()/10;
				int minremain=(numeric_limits<int>::min)()%10; 
				while((x=x/10)!=0)
				{
					if(num<min||(num==min&&x%10<minremain))//判断负数的话，是否会溢出溢出情况。
	    				{
	    					return 0;
	    				}
	    				num=num*10+x%10;//两个负数相加	
				}
				return num;
			}
	    }
};
int main(int argc, char const *argv[])
{
	int mx=-2147447412;
	Solution so;
	cout<<so.reverse(mx)<<endl;
	return 0;
}
