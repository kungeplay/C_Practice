// Palindrome Number
// Determine whether an integer is a palindrome. Do this without extra space.

// click to show spoilers.
// Some hints:

// Could negative integers be palindromes? (ie, -1)

// If you are thinking of converting the integer to string, note the restriction of using extra space.

// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

// There is a more generic way of solving this problem.
#include <limits>
#include <iostream>
using namespace std;
//察，负数竟然都不是回文，我是利用"reverse Integer"那个题的的方法
class Solution {
public:
    bool isPalindrome(int x) {
		return reverse(x)==x;        
    }
private:
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
			return 0;
		}
    }
};
int main(int argc, char const *argv[])
{
	int x=-121;
	Solution so;
	cout<<so.isPalindrome(x)<<endl;
	return 0;
}