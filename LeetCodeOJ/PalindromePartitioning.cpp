// Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
//下面这个算法就算求出来，感觉也会超时吧，结果240ms
//这个算法的思路是比如，aab：先求出a的回文划分，再求出aa的回文划分，再求出aab的回文划分
//类似Word Ladder的解题思路
// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//     		vector<vector<string>> partitionPalindrome;
//     		if(s.size()==0)
//     			return partitionPalindrome;

//     		int curPalindromeNum=0;
//     		int NextPalindrromeNum=0;

//     		string tempstr;
//     		tempstr.push_back(s[0]);
//     		vector<string> palindromeVector={tempstr};
//     		tempstr.pop_back();
//     		if(s.size()==1)
//     		{
//     			partitionPalindrome.push_back(palindromeVector);
//     			return partitionPalindrome;
//     		}
//     		queue<vector<string>> palindromeQueue;
//     		palindromeQueue.push(palindromeVector);
//     		++curPalindromeNum;
//     		for(size_t index=1;index<s.size();++index)
//     		{
//     			set<vector<string>> Visited;
//     			while(curPalindromeNum>0)
//     			{
// 	    			vector<string> curVector=palindromeQueue.front();
// 	    			palindromeQueue.pop();
// 	    			--curPalindromeNum;

// 	    			tempstr.push_back(s[index]);
//     				curVector.push_back(tempstr);
//     				tempstr.pop_back();

//     				if(index==s.size()-1)
//     					partitionPalindrome.push_back(curVector);
//     				else
// 	    				palindromeQueue.push(curVector);
//     				++NextPalindrromeNum;

//     				for(int i=curVector.size()-2;i>=0;--i)
//     				{
//     					curVector[i]+=curVector[i+1];
//     					curVector.pop_back();
//     					if(Visited.find(curVector)!=Visited.end())
//     						continue;
//     					if(isPalindrome(curVector[i]))
//     					{
//     						if(index==s.size()-1)
//     							partitionPalindrome.push_back(curVector);
// 						else
// 	    						palindromeQueue.push(curVector);
// 	    					Visited.insert(curVector);
//     						++NextPalindrromeNum;
//     					}

//     				}

// 	    		}
// 	    		if(NextPalindrromeNum!=0)
// 	    		{
// 	    			curPalindromeNum=NextPalindrromeNum;
// 	    			NextPalindrromeNum=0;
// 	    		}
//     		}

//     		return partitionPalindrome;
//     }
// private:
// 	bool isPalindrome(const string &str)
// 	{
// 		int low=0;
// 		int hight=str.size()-1;
// 		while(low<hight)
// 		{
// 			if(str[low]!=str[hight])
// 				return false;
// 			++low;
// 			--hight;

// 		}
// 		return true;
// 	}
// };
//从网上找的一个算法，用深度优先遍历，先从0开始比如到end位置找到一个一个回文字串，然后再从end+1位置开始从后边再找一个回文字串，直到字符串结束，
//算一次插入到res中。一直这样下去。，察确实高效，12ms
// class Solution {
// public:
// 	vector<vector<string>> partition(string s) {
// 		vector<string> path;
// 		vector<vector<string>> res;
// 		dfs(s,path,res);
// 		return res;
// 	}
// private:
// 	void dfs(const string &s,vector<string> &path,vector<vector<string>> &res)
// 	{
// 		if(s.size()<1)
// 		{
// 			res.push_back(path);
// 			return;
// 		}
// 		for(size_t i=0;i<s.size();++i)
// 		{
// 			int begin=0;
// 			int end=i;
// 			while(begin<=end)//注意这里会有重复的循环，在下一个算法里，主要是用动态规划方法优化这个。
// 			{
// 				if(s[begin]!=s[end])
// 					break;
// 				++begin;
// 				--end;
// 			}
// 			if(begin>end)
// 			{
// 				path.push_back(s.substr(0,i+1));
// 				dfs(s.substr(i+1),path,res);
// 				path.pop_back();
// 			}
// 		}
// 	}
// };

//这个算法是上一个算法的改进，先利用动态规划法求出所有的回文子串
//具体思想见http://blog.csdn.net/worldwindjp/article/details/22042133
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<string> path;
		vector<vector<string>> res;
		vector<vector<bool>> palindrome_map(s.size(),vector<bool>(s.size(),false));
		dp(s,palindrome_map);
		dfs(s,0,path,res,palindrome_map);
		return res;
	}
private:
	void dfs(const string &s,int drift,vector<string> &path,vector<vector<string>> &res,const vector<vector<bool>> &palindrome_map)
	{
		int len=s.size();
		if(drift>=len)
		{
			res.push_back(path);
			return;
		}
		for(int i=drift;i<len;++i)
		{
			if(palindrome_map[drift][i])
			{
				path.push_back(s.substr(drift,i-drift+1));//复制子字符串，要求从指定位置开始，并具有指定的长度。
				dfs(s,i+1,path,res,palindrome_map);
				path.pop_back();
			}
		}
	}
	void dp(const string &s,vector<vector<bool>> & palindrome_map)
	{
		int len=s.size();
		for(int i=len-1;i>=0;--i)
		{
			for(int j=i;j<=len-1;++j)
			{
				if(j==i)
					palindrome_map[i][j]=true;
				else if(s[i]==s[j])
				{
					if(j==i+1||palindrome_map[i+1][j-1])
						palindrome_map[i][j]=true;
				}

			}
		}
	}
};



int main(int argc, char const *argv[])
{
	string s="cdd";
	Solution so;
	vector<vector<string>> partitionPalindrome=so.partition(s);
	for(size_t i=0;i<partitionPalindrome.size();++i)
	{
		for(size_t j=0;j<partitionPalindrome[i].size();++j)
		{
			cout<<partitionPalindrome[i][j]<<'\t';
		}
		cout<<endl;
	}

	return 0;
}
