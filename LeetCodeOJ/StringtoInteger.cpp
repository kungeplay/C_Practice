// String to Integer (atoi)
// Implement atoi to convert a string to an integer.

// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

// Update (2015-02-10):
// The signature of the C++ function had been updated. 
// If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition. 
#include <iostream>
#include <limits>
using namespace std;
//这个题主要正如题中所说的要注意各种细节，各种临界值
class Solution {
public:
    int myAtoi(string str) 
    {
    		str=trim(str);//去除字符串的前后空格制表符
    		if(str.size()<=0)
    			return 0;
    		int num=0;
    		bool positiveNum=true;
    		auto iter=str.begin();
    		if(*iter=='-')
    			positiveNum=false;
    		else if(*iter=='+')
    			positiveNum=true;
    		else if(*iter<'0'||*iter>'9')
    			return 0;
    		else
    			num=*iter-'0';
		int max=(numeric_limits<int>::max)()/10;
		int maxremain=(numeric_limits<int>::max)()%10;
		int min=-((numeric_limits<int>::min)()/10);
		int minremain=-((numeric_limits<int>::min)()%10);
    		++iter;
    		for(;iter<str.end();++iter)
    		{
    			if(*iter<'0'||*iter>'9')
    				break;
    			else if(positiveNum==true&&(num>max||(num==max&&(*iter-'0')>maxremain)))//判断若是正数的话，是否会溢出，若溢出则返回正数最大值
    			{
    				return (numeric_limits<int>::max)();
    			}
    			else if((positiveNum==false&&(num>min||(num==min&&(*iter-'0')>minremain))))//判断若是负数的话，是否会溢出，若溢出，则返回负数最大值
    			{
    				return (numeric_limits<int>::min)();
    			}
			num=num*10+(*iter-'0');
    		}
		return positiveNum?num:-num;
    }
private:
	string trim(string s)
	{
		int i=0;
		int j=s.size()-1;
		string temp="";
		for(;i<s.size();i++)
		{
			if((s[i]=='\t')||s[i]==' ')
				continue;
			else
				break;
		}
		if(i==s.size())
			return temp;
		for(;j>i;j--)
		{
			if((s[j]=='\t')||s[j]==' ')
				continue;
			else
				break;
		}
		temp.insert(temp.end(),&s[i],&s[j+1]);
		return temp;
	}
};

int main(int argc, char const *argv[])
{
	string s="-00021474asda";
	Solution so;
	cout<<so.myAtoi(s)<<endl;
	// int min=(numeric_limits<int>::min)()/10;
	// int minremain=(numeric_limits<int>::min)()%10;
	// cout<<min<<"\t"<<minremain<<endl;
	return 0;
}
