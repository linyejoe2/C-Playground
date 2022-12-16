#ifndef MYQUEUE_H
#define MYQUEUE_H


#include "solution.h"

#include <stack>
class MyQueue
{
public:
	MyQueue(){};

	void push(int x)
	{
		stack1.push(x);
	};

	int pop()
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		int res = stack2.top();
		stack2.pop();

		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}

		return res;
	};

	int peek()
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		int res = stack2.top();

		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}

		return res;
	};

	bool empty()
	{
		return stack1.empty();
	};

private:
	stack<int> stack1;
	stack<int> stack2;
};

#endif // MYQUEUE_H
