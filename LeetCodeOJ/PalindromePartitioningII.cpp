// Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <iostream>
#include <vector>

using namespace std;
//下面这种算法我是仿照Palindrome Partitioning来改进的，DFS结果超时
// class Solution {
// public:
// 	int minCut(string s) {
// 		vector<string> path;
// 		minNum=-1;
// 		vector<vector<bool>> palindrome_map(s.size(),vector<bool>(s.size(),false));
// 		dp(s,palindrome_map);
// 		dfs(s,0,path,-1,palindrome_map);
// 		return minNum;

// 	}
// private:
// 	int minNum;
// private:
// 	void dfs(const string &s,int drift,vector<string> &path,int count,const vector<vector<bool>> &palindrome_map)
// 	{
// 		if(minNum!=-1&&minNum<count)
// 			return;
// 		int len=s.size();
// 		if(drift>=len)
// 		{
// 			if(minNum==-1)
// 				minNum=count;
// 			else if(minNum>count)
// 				minNum=count;
// 			return;
// 		}
// 		for(int i=drift;i<len;++i)
// 		{
// 			if(palindrome_map[drift][i])
// 			{
// 				path.push_back(s.substr(drift,i-drift+1));//复制子字符串，要求从指定位置开始，并具有指定的长度。
// 				dfs(s,i+1,path,count+1,palindrome_map);
// 				path.pop_back();
// 			}
// 		}
// 	}
// 	void dp(const string &s,vector<vector<bool>> & palindrome_map)
// 	{
// 		int len=s.size();
// 		for(int i=len-1;i>=0;--i)
// 		{
// 			for(int j=i;j<=len-1;++j)
// 			{
// 				if(j==i)
// 					palindrome_map[i][j]=true;
// 				else if(s[i]==s[j])
// 				{
// 					if(j==i+1||palindrome_map[i+1][j-1])
// 						palindrome_map[i][j]=true;
// 				}

// 			}
// 		}
// 	}

// };


//这个又是动态规划，结果还挺简洁的，dp[i]表示区间[i,n]之间最小的cut数，n为字符串长度见http://blog.csdn.net/doc_sgl/article/details/13418125
//D[i] = min(1+D[j+1] )    i<=j <n，如果[i,j]之间是回文的话。
////这个网址讲的非常给力：http://blog.csdn.net/yutianzuijin/article/details/16850031
class Solution {
public:
	int minCut(string s) {
		int len=s.size();
		vector<int> dp(len+1);
		for(int i=len;i>=0;--i)//[i,n]之间的最大切割数，为i到n之间每个回文都为单个字符时最大。
			dp[i]=len-i;

		vector<vector<bool>> palindrome_map(len,vector<bool>(len,false));//用来记录[i,j]之间是否是回文，下面用到了
		for(int i=len-1;i>=0;--i)
		{
			for(int j=i;j<=len-1;++j)
			{
				if(s[i]==s[j]&&(j-i<2||palindrome_map[i+1][j-1]))//表示[i,j]也为回文。
				{
					palindrome_map[i][j]=true;
					dp[i]=min(dp[i],dp[j+1]+1);
				}
			}
		}
		return dp[0]-1;
	}
};


int main(int argc, char const *argv[])
{
	// string s="fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
	string s="aba";
	Solution so;
	cout<<so.minCut(s)<<endl;
	return 0;
}