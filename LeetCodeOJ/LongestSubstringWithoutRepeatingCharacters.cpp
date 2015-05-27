// Longest Substring Without Repeating Characters
// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
// For "bbbbb" the longest substring is "b", with the length of 1.
// 总是理解错题，还不注意鲁棒性，每次都要提交好几次，错误之后，才知道如何改代码
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    		vector<char> charv;
    		int len=0;
    		for(int i=0;i<s.size();i++)
    		{
    			for(auto iter=charv.begin();iter!=charv.end();++iter)
    			{
    				if(*iter==s[i])
    				{
    					charv.erase(charv.begin(),iter+1);
    					break;
    				}
    			}
		    	charv.push_back(s[i]);
	    		if (charv.size()>len)
    			{
    				len=charv.size();
    			}	    	
    		}
    		return len;
    }
};
int main(int argc, char const *argv[])
{
	string s="bbbbbb";
	Solution so;
	int len=so.lengthOfLongestSubstring(s);
	cout<<len<<endl;
	return 0;
}
