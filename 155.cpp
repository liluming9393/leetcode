/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) --Push element x onto stack.
pop() --Removes the element on top of the stack.
top() --Get the top element.
getMin() --Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns - 3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns - 2.*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> s;
	stack<int> min;
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if (min.empty())
		{
			min.push(x);
		}
		else if (x <= min.top())
		{
			min.push(x);
		}
	}

	void pop() {
		if (s.empty())
		{
			return;
		}
		int temp = s.top();
		s.pop();
		if (temp == min.top())
		{
			min.pop();
		}
	}

	int top() {
		if (!s.empty())
			return s.top();
		return 0;
	}

	int getMin() {
		if (!s.empty())
			return min.top();
		return 0;
	}
};
int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	int result = minStack.getMin();
	cout << result << endl;
	minStack.pop();
	result = minStack.top();
	cout << result << endl;
	result = minStack.getMin();
	cout << result << endl;
	system("pause");
	return 0;
}