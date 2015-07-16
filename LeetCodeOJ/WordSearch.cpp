// Word Search
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]

// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <iostream>
#include <vector>
using namespace std;
//深度递归，感觉只能这个样子吧
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    		if(word.size()==0)
    			return true;
    		int rownum=board.size();
    		int columnnum=board[0].size();
    		vector<vector<bool>> visited_v(rownum,vector<bool>(columnnum,false));
    		for(int i=0;i<rownum;++i)
    		{
    			for(int j=0;j<columnnum;++j)
    			{
    				if(board[i][j]==word[0])
    				{
    					visited_v[i][j]=true;
    					if(isExist(board,visited_v,word,1,i,j))
    						return true;
    					visited_v[i][j]=false;
    				}
    			}
    		}
    		return false;
    }

    bool isExist(const vector<vector<char>>&board, vector<vector<bool>> &visited_v,  const string &word, size_t index,int i,int j)
    {
    		int rownum=board.size();
    		int columnnum=board[0].size();

    		if(index>=word.size())
    			return true;

    		if(i-1>=0&&word[index]==board[i-1][j]&&visited_v[i-1][j]==false)
    		{
    			visited_v[i-1][j]=true;
    			if(isExist(board,visited_v,word,index+1,i-1,j))
    				return true;
    			visited_v[i-1][j]=false;
    		}
    		if(j+1<columnnum&&word[index]==board[i][j+1]&&visited_v[i][j+1]==false)
    		{
    			visited_v[i][j+1]=true;
    			if(isExist(board,visited_v,word,index+1,i,j+1))
    				return true;
    			visited_v[i][j+1]=false;
    		}
    		if(i+1<rownum&&word[index]==board[i+1][j]&&visited_v[i+1][j]==false)
    		{
    			visited_v[i+1][j]=true;
    			if(isExist(board,visited_v,word,index+1,i+1,j))
    				return true;
    			visited_v[i+1][j]=false;
    		}
    		if(j-1>=0&&word[index]==board[i][j-1]&&visited_v[i][j-1]==false)
    		{
    			visited_v[i][j-1]=true;
    			if(isExist(board,visited_v,word,index+1,i,j-1))
    				return true;
    			visited_v[i][j-1]=false;
    		}
    		return false;
    }
};

int main(int argc, char const *argv[])
{
	vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	Solution so;
	cout<<so.exist(board,"ABCB")<<endl;
	return 0;
}

// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]