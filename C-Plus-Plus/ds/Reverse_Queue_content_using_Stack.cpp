/*
Problem - 
	To reverse the content of a queue using only a stack.

Algorithm - 
	First we pop each element from the queue and push it element by element into the stack. We keep doing this until the queue is empty.
	Then we pop each element from the stack and push it element by element into the queue. We keep doing this until the stack is empty.
	We get the content of queue reversed.
*/

#include <bits/stdc++.h>
using namespace std;

// Displays all content of queue
void Q_Display(queue <int> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}

// Reverses content of queue using stack
void reverse_queue(queue <int> *q)
{
	stack <int> s;
	
	// Poping from queue and pushing into stack
	while (!q->empty())
	{
		s.push(q->front());
		q->pop();
	}
	// Poping from stack and pushing into queue
	while (!s.empty())
	{
		q->push(s.top());
		s.pop();
	}
}

int main()
{
	queue <int> q;
	int temp, n;
	
	cout << "Enter queue size : ";
	cin >> n;
	
	while (n--)
	{
		cout << "\nEnter a number : ";
		cin >> temp;
		q.push(temp);
	}
	
	cout << "\nOriginal queue : ";
	Q_Display(q);
	
	reverse_queue(&q);
	
	cout << "\nReversed queue : ";
	Q_Display(q);
}
/*
Test run example - 
	Enter queue size : 5
	Enter a number : 1
	Enter a number : 2
	Enter a number : 3
	Enter a number : 4
	Enter a number : 5
	
	Original queue : 1 2 3 4 5
	Reversed queue : 5 4 3 2 1

Time and Space Complexity - 
	Time - O(n)
	Space - O(n)
*/
