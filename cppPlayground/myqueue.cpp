#include "myqueue.h"

MyQueue::MyQueue()
{
}

void MyQueue::push(int x)
{
	stack1.push(x);
}

int MyQueue::pop()
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
}

int MyQueue::peek()
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
}

bool MyQueue::empty()
{
	return stack1.empty();
}
