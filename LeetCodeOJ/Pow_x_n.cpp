// Pow(x, n)
// Implement pow(x, n). 
#include <iostream>
using namespace std;
//这个题在剑指offer P90里有这个，在STL源码剖析也有power函数，只是STL源码里用的是循环迭代，不容易看懂，
//剑指offer里用的是递归函数调用，通俗易懂，且考虑的条件比这个题限制还要多，要多看一看额
class Solution {
public:
    double myPow(double x, int n) {
    		unsigned int expont=(unsigned int)n;
    		if(n<0)
    		{
    			expont=(unsigned int)-n;
    			cout<<expont<<endl;
    		}
    		if(n>0)
    		{
    			return powered(x,expont);
    		}
    		else
    		{
    			return 1.0/powered(x,expont);
    		}
    }
private:
	double powered(double x,unsigned int expont)
	{
		if(expont==0)
			return 1;
		else if(expont==1)
			return x;
		double result=powered(x,expont>>1);
		result*=result;
		if((expont&0x01)==1)
			result*=x;
		return result;
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.myPow(1.00000, -2147483648);
	return 0;
}