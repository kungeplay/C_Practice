// Evaluate(求…的数值) Reverse Polish Notation(逆波兰表达式又叫做后缀表达式,每一运算符都置于其运算对象之后，故称为后缀表示。)
// Evaluate the value of an arithmetic expression(算术表达式) in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand(操作数; 运算数) may be an integer or another expression.

// Some examples:

//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
//数据结构课本上介绍过，用栈来解决逆波兰表达式,只要知道是后缀表达式就不难
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int len=tokens.size();
		stack<int> tempResult;
		for(int i=0;i<len;++i)
		{
			if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
			{
				assert(tempResult.size()>1);
				int num2=tempResult.top();
				tempResult.pop();
				int num1=tempResult.top();
				tempResult.pop();
				tempResult.push(getCalculate(num1,num2,tokens[i][0]));
			}
			else
			{
				tempResult.push(stoi(tokens[i]));
			}
		}
		return tempResult.top();
	}
private:
	int getCalculate(int num1,int num2,char operat)
	{
		switch(operat)
		{
			case '+':
				return num1+num2;
				break;
			case '-':
				return num1-num2;
				break;
			case '*':
				return num1*num2;
				break;
			default:
				return num1/num2;
				break;
		}
	}
};

int main(int argc, char const *argv[])
{
	vector<string> tokens={"4", "13", "5", "/", "+"};
	Solution so;
	cout<<so.evalRPN(tokens)<<endl;
	return 0;
}
