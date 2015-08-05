// Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     getMin() -- Retrieve the minimum element in the stac

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
	void push(int x) {
		dataStack.push(x);
		if(minData.size()==0||minData.top()>x)
			minData.push(x);
		else
			minData.push(minData.top());
	}	

	void pop() {
		dataStack.pop();
		minData.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return minData.top();
	}
private:
	stack<int> dataStack;
	stack<int> minData;
};

int main(int argc, char const *argv[])
{
	MinStack ms;
	ms.push(2);
	ms.push(5);
	ms.push(3);
	ms.push(4);
	cout<<ms.getMin()<<endl;
	return 0;
}