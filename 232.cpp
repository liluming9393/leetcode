/*Implement the following operations of a queue using stacks.
push(x) --Push element x to the back of queue.
pop() --Removes the element from in front of queue.
peek() --Get the front element.
empty() --Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek / pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively.You may simulate a stack by using a list or deque(double - ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid(for example, no pop or peek operations will be called on an empty queue).*/
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
class Queue {
public:
	stack<int> s1;
	stack<int> s2;
	// Push element x to the back of queue.
	void push(int x) {
		s1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!s2.empty())
		{
			s2.pop();
		}
		else
		{
			int temp;
			while (!s1.empty())
			{
				temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
			s2.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if (!s2.empty())
		{
			return s2.top();
		}
		else
		{
			int temp;
			while (!s1.empty())
			{
				temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
		}
		return s2.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		if (s1.empty() && s2.empty())
		{
			return true;
		}
		return false;
	}
};
int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	int result;
	result = q.peek();
	cout << result << endl;
	q.push(3);
	q.pop();
	result = q.peek();
	cout << result << endl;
	system("pause");
	return 0;
}