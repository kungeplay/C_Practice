// curWord Ladder II
// Given two curWords (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

//     Only one letter can be changed at a time
//     Each intermediate curWord must exist in the dictionary

// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]

// Return

//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]

// Note:

//     All curWords have the same length.
//     All curWords contain only lowercase alphabetic characters.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
//不容易，这个题和上一个题相比主要是多了一个要保存访问过的路径，以便返回，我这里用queue实现，
//还要注意，一旦temp匹配到了dict，不要立即删除，因为同一层的其他单词可能通过变形也能变成temp
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

		vector<vector<string>> ShortestSequences;    	

    		if(start.size()==0||end.size()==0)
    			return ShortestSequences;
    		if(start.size()!=end.size())
    			return ShortestSequences;
    		int shortestLevel=0;
    		int levelcurWordNum=0;
    		int nextLevelcurWordNum=0;
    		int level=1;		
    		queue<string> visitedPath;

		queue<vector<string>> tracePath;//用来保存访问过的路径
    		vector<string> path={start};
    		tracePath.push(path);    		
    		visitedPath.push(start);
    		dict.erase(start);
    		levelcurWordNum=1;
    		vector<string> waitDeleteWord;

    		while(visitedPath.size()!=0)
    		{
    			string curWord=visitedPath.front();
    			visitedPath.pop();
    			--levelcurWordNum;

    			path=tracePath.front();
    			tracePath.pop();

    			for(size_t i=0;i<curWord.size();++i)
    			{
    				string temp=curWord;
    				for(char c='a';c<='z';++c)
    				{
    					if(temp[i]==c)
    						continue;
    					temp[i]=c;
    					if(temp==end)
    					{
    						if(shortestLevel==0||shortestLevel==level)
    						{
    							shortestLevel=level;
	    						path.push_back(end);
	    						ShortestSequences.push_back(path);
	    					}
    					}
    					if(dict.find(temp)==dict.end())
    						continue;
    					visitedPath.push(temp);
    					// dict.erase(temp);
    					waitDeleteWord.push_back(temp);//先记录下来，不要立即从dict里删除temp
    					++nextLevelcurWordNum;

    					path.push_back(temp);
    					tracePath.push(path);
    					path.pop_back();    					
    				}
    			}
    			if(levelcurWordNum==0&&nextLevelcurWordNum!=0)
    			{
    				++level;
    				if(shortestLevel!=0)
    					return ShortestSequences;
    				levelcurWordNum=nextLevelcurWordNum;
    				nextLevelcurWordNum=0;

    				for(auto iter=waitDeleteWord.begin();iter!=waitDeleteWord.end();++iter)//在这里删除
    				{
    					dict.erase(*iter);
    				}
    				waitDeleteWord.clear();
    			}
    		}
    		return ShortestSequences;
    }
};

int main(int argc, char const *argv[])
{
	// string start="hit";
	// string end="cog";
	// unordered_set<string> dict={"hot","dot","dog","lot","log"};
	string start="red";
	string end="tax";
	unordered_set<string> dict={"ted","tex","red","tax","tad","den","rex","pee"};
	//[["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
	Solution so;
	vector<vector<string>> ShortestSequences=so.findLadders(start,end,dict);
	for(size_t i=0;i<ShortestSequences.size();++i)
	{
		for(size_t j=0;j<ShortestSequences[i].size();++j)
		{
			cout<<ShortestSequences[i][j]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}