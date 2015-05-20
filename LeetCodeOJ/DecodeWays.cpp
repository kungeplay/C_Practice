//  A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// The number of ways decoding "12" is 2. 
//注意我用如下的迭代方法调用时间超时
#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    int numDecodings(string s) {
        return getNumbers(s,0);
    }
private:    
    int getNumbers(const string &s,int beginindex)
    {
    		int leavelen=s.size()-beginindex;
    		if (leavelen<0)
    		{
    			return -1;
    		}
    		else if(leavelen==0)
    			return 1;
    		else if (leavelen==1&&(charToNum(s,beginindex,beginindex)!=-1))
    		{
    			return 1;
    		}
    		else
    		{
    			int num=0,num1=0,num2=0;
    			if ((charToNum(s,beginindex,beginindex)!=-1)&&(num1=getNumbers(s,beginindex+1))!=-1)
    				num+=num1;
    			if ((charToNum(s,beginindex,beginindex+1)!=-1)&&(num2=getNumbers(s,beginindex+2))!=-1)
    				num+=num2;
    			return (num==0)?-1:num;
    		}
    }
    int charToNum(const string &s,int beginindex,int endindex)
    {
    		int num=0;
    		for (int i = beginindex; i <=endindex; ++i)
    		{
    			if (s[i]>'0'&&s[i]<='9')
    			{
    				num=num*10+(s[i]-'0');
    			}
    			else
    				return -1;
    		}
    		return (num>26)?-1:num;
    }
};
int main(int argc, char const *argv[])
{
	string str="1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565";
	Solution s;
	std::cout<<s.numDecodings(str)<<std::endl;
	return 0;
}