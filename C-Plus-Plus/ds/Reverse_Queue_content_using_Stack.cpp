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
	
	// Dequeue
	while (!q->empty())
	{
		s.push(q->front());
		q->pop();
	}
	// Enqueue
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
