/*Implement the following operations of a stack using queues.
push(x) --Push element x onto stack.
pop() --Removes the element on top of the stack.
top() --Get the top element.
empty() --Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek / pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively.You may simulate a queue by using a list or deque(double - ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).*/
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
class Stack {
private:
	queue<int> q1;
	queue<int> q2;
public:
	// Push element x onto stack.
	void push(int x) {
		if (q1.empty())
		{
			q1.push(x);
			int temp;
			while (!q2.empty())
			{
				temp = q2.front();
				q2.pop();
				q1.push(temp);
			}
		}
		else
		{
			q2.push(x);
			int temp;
			while (!q1.empty())
			{
				temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!q1.empty())
		{
			q1.pop();
		}
		else
		{
			q2.pop();
		}
	}

	// Get the top element.
	int top() {
		if (!q1.empty())
		{
			return q1.front();
		}
		return q2.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		if (q1.empty() && q2.empty())
		{
			return true;
		}
		return false;
	}
};
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	int result;
	result = s.top();
	cout << result << endl;
	s.push(3);
	result = s.top();
	cout << result << endl;
	system("pause");
	return 0;
}