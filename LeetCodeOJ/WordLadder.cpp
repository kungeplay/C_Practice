// Word Ladder(梯子，阶梯)
// Given two words (beginWord and endWord), and a dictionary, 
//find the length of shortest transformation(变化,转化；转变；改造；转型) sequence from beginWord to endWord, such that:

//     1. Only one letter can be changed at a time
//     2. Each intermediate(中间的，中级的) word must exist in the dictionary

// For example,
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]

// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:

//     Return 0 if there is no such transformation sequence.
//     All words have the same length.
//     All words contain only lowercase alphabetic characters.

#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

//察，这种类型的题，我竟然没想到用广度优先搜索BFS，不过不得不说，我没有想到这么深
//，要好好看一看
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		if(beginWord.size()!=endWord.size())
			return 0;
		int level=1;//广度优先搜索所进行到的层数
		int levelWordNum=0;//当前层节点个数
		int nextLevelWordNum=0;//下一层节点个数
		queue<string> path;//定义一个队列，存放当前要进行广度搜索的字符串，
		path.push(beginWord);
		wordDict.erase(beginWord);
		++levelWordNum;
		while(path.size()!=0)
		{
			string curWord=path.front();
			path.pop();
			--levelWordNum;
			for(size_t i=0;i<curWord.size();++i)
			{
				string temp=curWord;				
				for(char c='a';c<='z';++c)
				{
					if(temp[i]==c)	continue;
					temp[i]=c;
					if(temp==endWord)	return level+1;
					if(wordDict.find(temp)!=wordDict.end())
					{
						path.push(temp);
						wordDict.erase(temp);					
						++nextLevelWordNum;
					}
				}
			}
			if(levelWordNum==0)//当当前层节点个数减为0时，广度优先搜索的层数加1
			{
				++level;
				levelWordNum=nextLevelWordNum;
				nextLevelWordNum=0;
			}
		}
		return 0;
	}
};
int main(int argc, char const *argv[])
{
	string beginWord="hit";
	string endWord="cog";
	unordered_set<string> wordDict={"hot","dot","dog","lot","log"};
	Solution so;
	cout<<so.ladderLength(beginWord,endWord,wordDict)<<endl;
	return 0;
}