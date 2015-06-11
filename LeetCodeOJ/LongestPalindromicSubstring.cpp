// Longest Palindromic Substring
// Given a string S, find the longest palindromic substring in S. 
// You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
//palindromic substring:回文子串.如果一个字符串从左向右写和从右向左写是一样的,这样的字符串就叫做palindromic string,如aba,或者abba。
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    		int len=1;
    		int start=0;
    		int sslen=s.size();
    		if (sslen==0)
    		{
    			return "";
    		}
        for (int i = 0; i < sslen; ++i)
        {
        		int j=0;
        		while(true)
        		{
        			if (i-j>-1&&i+j+1<sslen&&s[i-j]==s[i+j+1])
        			{
        				++j;	
        			}
        			else
        			{	
        				int templen=2*j;
        				if (len<templen)
        				{
        					len=templen;
        					start=i-j+1;
        				}
        				break;
        			}

        		}
        		j=1;
        		while(true)
        		{
        			if (i-j>-1&&i+j<s.size()&&s[i-j]==s[i+j])
        			{
        				++j;
        			}
        			else
        			{
        				int templen=2*j-1;
        				if (len<templen&&j!=1)
        				{
        					len=templen;
        					start=i-j+1;
        				}
        				break;
        			}
        		}
        }
        return s.substr(start,len);
    }
};
int main(int argc, char const *argv[])
{
	Solution so;
	string s="abcf";
	cout<<so.longestPalindrome(s)<<endl;
	return 0;
}