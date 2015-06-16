// Generate Parentheses(圆括号)
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()" 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		if(n==0)	
			return parentheses;    		
		string s(n*2,'a');
		int leftp=0;
		int righyp=0;
		getParenthesis(s,0,0,0);
		return parentheses;
    }
private:
	vector<string> parentheses;
private:
	void getParenthesis(string &s,int leftp,int righyp,int sequence)
	{
		if(sequence<s.size())
		{
			if(leftp>righyp)
			{
				s[sequence]=')';
				getParenthesis(s,leftp,righyp+1,sequence+1);
				if(leftp<s.size()/2)
				{
					s[sequence]='(';
					getParenthesis(s,leftp+1,righyp,sequence+1);
				}
			}
			if(leftp==righyp)
			{
				s[sequence]='(';
				getParenthesis(s,leftp+1,righyp,sequence+1);
			}
		}
		else
			parentheses.push_back(s);
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	vector<string> parentheses=so.generateParenthesis(3);
	for (std::vector<string>::iterator i = parentheses.begin(); i != parentheses.end(); ++i)
	{
		cout<<*i<<'\t'<<(*i).size()<<endl;
	}
	return 0;
}