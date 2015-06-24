// Valid Sudoku
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

    		for(int i=0;i<9;++i)
    		{
    			if(!rowValidsudoku(board,i))
    				return false;
    		}

    		for(int j=0;j<9;++j)
    		{
    			if(!colValidsudoku(board,j))
    				return false;
    		}
    		for(int i=0;i<9;i+=3)
    		{
    			for(int j=0;j<9;j+=3)
    			{
    				if(!gridValidsudoku(board,i,j,i+3,j+3))
    					return false;
    			}
    		}
    		return true;
        
    }
    bool rowValidsudoku(vector<vector<char>>&board,const int & nums)
    {
    		vector<bool> c(9,true);
    		for(int i=0;i<9;++i)
    		{
    			if(board[nums][i]!='.')
    			{
    				char temp=board[nums][i];
    				if(c[temp-'1'])
    					c[temp-'1']=false;
    				else
    					return false;
    			}

    		}
    		return true;
    }
    bool colValidsudoku(vector<vector<char>>&board,const int & nums)
    {
    		vector<bool> c(9,true);
    		for(int i=0;i<9;++i)
    		{
    			if(board[i][nums]!='.')
    			{
    				char temp=board[i][nums];
    				if(c[temp-'1'])
    					c[temp-'1']=false;
    				else
    					return false;
    			}
    		}
    		return true;

    }
    bool gridValidsudoku(vector<vector<char>>&board,int startrow,int startcol,int endrow,int endcol)
    {
    		vector<bool> c(9,true);
    		for(int i=startrow;i<endrow;++i)
    		{
    			for(int j=startcol;j<endcol;++j)
    			{
	    			if(board[i][j]!='.')
	    			{
	    				char temp=board[i][j];
	    				if(c[temp-'1'])
	    					c[temp-'1']=false;
	    				else
	    					return false;
	    			}    			
	    		}
    		}
    		return true;    	
    }
};
int main(int argc, char const *argv[])
{
	vector<vector<char>> cv;
	vector<char> i={'.','.','.','.','5','.','.','1','.'};
	cv.push_back(i);
	i={'.','4','.','3','.','.','.','.','.'};
	cv.push_back(i);
	i={'.','.','.','.','.','3','.','.','1'};;
	cv.push_back(i);
	i={'8','.','.','.','.','.','.','2','.'};;
	cv.push_back(i);
	i={'.','.','2','7','.','.','.','.','.'};;
	cv.push_back(i);
	i={'.','1','5','.','.','.','.','.','.'};;
	cv.push_back(i);	
	i={'.','.','.','.','.','2','.','.','.'};;
	cv.push_back(i);	
	i={'.','2','.','9','.','.','.','.','.'};;
	cv.push_back(i);	
	i={'.','.','4','.','.','.','.','.','.'};;
	cv.push_back(i);	
	// for(int i=0;i<9;++i)
	// {
	// 	for(int j=0;j<9;++j)
	// 	{
	// 		cout<<cv[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	Solution so;
	std::cout<<so.isValidSudoku(cv)<<endl;
	//["....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"]
	return 0;
}