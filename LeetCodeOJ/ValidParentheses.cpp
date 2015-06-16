// Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets(括号) must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
#include <iostream>
#include <vector>
using namespace std;
//这个题没有什么难的，一遍过
class Solution {
public:
    bool isValid(string s) {
    		vector<char> v;
    		char match_c;
        	for(int i=0;i<s.size();++i)
        	{
        		int result_match=getMatch(s[i],match_c);
        		if(result_match==0)
        			v.push_back(s[i]);
        		else if(result_match==1)
        		{
        			if(v.size()==0||v[v.size()-1]!=match_c)
        				return false;
        			v.pop_back();
        		}
        		else
        		{
        			return false;
        		}
        	}
        	if(v.size()==0)
        		return true;
        	else
        		return false;
    }
private:
	int getMatch(const char &c,char & match_c)
	{
		switch(c)
		{
			case '(':
				return 0;
			case ')':
				match_c='(';
				return 1;
			case '{':
				return 0;
			case '}':
				match_c='{';
				return 1;
			case '[':
				return 0;
			case ']':
				match_c='[';
			return 1;
			default:
				return 2;

		}
	}
};
int main(int argc, char const *argv[])
{
	// string s="{}[](){([[[]]])}";
	string s="";
	Solution so;
	cout<<so.isValid(s)<<endl;
	return 0;
}
