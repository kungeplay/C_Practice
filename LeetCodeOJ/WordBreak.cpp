// Word Break
// Given a string s and a dictionary of words dict, determine if s can be segmented(分开的; 被分离的; 被隔离的) into a space-separated sequence 
// of one or more dictionary words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].

// Return true because "leetcode" can be segmented as "leet code". 
#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>

using namespace std;
//深度递归的方法，注意各种边界条件，结果超时
// class Solution {
// public:
// 	bool wordBreak(string s, unordered_set<string>& wordDict) {
// 		return wordBreak(s,0,wordDict);
// 	}
// private:
// 	bool wordBreak(const string &s,int index, const unordered_set<string> &wordDict)
// 	{
// 		int len=s.size();
// 		if(index==len)
// 			return true;
// 		for(int i=index+1;i<=len;++i)
// 		{
// 			if(wordDict.find(s.substr(index,i-index))!=wordDict.end())
// 			{
// 				if(wordBreak(s,i,wordDict))
// 					return true;
// 			}
// 		}
// 		return false;
// 	}
// };

// //在网上找的一个方法，是由上面递归超时，发现递归调用时后缀字符串很多重复计算的问题，然后设置一个容器保存计算过的后缀字符子串。留着下一次用。
// //也算是动态规划吧,网上还说还可以再优化下，当前缀字符串长度小于字典中的最小字符串长度，则不用判断，当前缀字符串长度大于字典中的最大字符串长度时，也是不用判断。
// //刚开始先计算字典中的最小字符串长度和最大字符串长度。
// class Solution {
// public:
// 	bool wordBreak(string s, unordered_set<string>& wordDict) {
// 		unordered_set<string> unmatch;//保留向后匹配的结果
// 		return wordBreak(s,wordDict,unmatch);
// 	}
// private:
// 	bool wordBreak(const string &s,const unordered_set<string> &wordDict,unordered_set<string>& unmatch)
// 	{
// 		int len=s.size();
// 		if(len<1)
// 			return true;
// 		for(int i=1;i<=len;++i)
// 		{
// 			string prefixstr=s.substr(0,i);
// 			if(wordDict.find(prefixstr)!=wordDict.end())//前缀在字典中能找到
// 			{
// 				string suffixstr=s.substr(i);
// 				if(unmatch.find(suffixstr)!=unmatch.end())//后缀字符串以前计算过。
// 					continue;
// 				if(wordBreak(suffixstr,wordDict,unmatch))
// 					return true;
// 				unmatch.insert(suffixstr);
// 			}
// 		}
// 		return false;
// 	}
// };
//这是在网上看到的另一种动态规划算法，dp[n]表示到s[i]元素前的字串是可以被字典划分的。
class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n=s.size();
		vector<bool> dp(n+1,false);
		dp[0]=true;
		for(int i=0;i<n;++i)
		{
			if(dp[i])
			{
				for(int len=1;len+i<=n;++len)
				{
					if(wordDict.find(s.substr(i,len))!=wordDict.end())
						dp[i+len]=true;
				}
			}
		}
		return dp[n];
	}
};

int main(int argc, char const *argv[])
{
	string s="abcleetcodeer";
	unordered_set<string> wordDict={"abc","leet","leetcode","er"};
	// string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	// unordered_set<string> wordDict={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	// string s="abcd";
	// unordered_set<string> wordDict={"a","abc","b","cd"};

	Solution so;
	cout<<so.wordBreak(s,wordDict)<<endl;
	// map<int,vector<int>> segmentWord;
	// segmentWord[0].push_back(1);
	// segmentWord[0].push_back(2);
	// cout<<segmentWord[0][1]<<endl;
	return 0;
}
// "abcd", ["a","abc","b","cd"]
