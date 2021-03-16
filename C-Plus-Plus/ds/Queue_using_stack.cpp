/*
A queue can be implemented using two stacks. 
Let queue to be implemented be q and stacks used to implement q be stack1 and stack2.
*/

#include <iostream>
#include <stack>
using namespace std;


class Queue{

public:

	stack<int> stack1;				
	stack<int> stack2;				

	void push(int x){ 
		stack1.push(x);
	}

	void pop(){
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack2.pop();
		while(!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	int front(){
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		int x = stack2.top();
		while(!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}

		return x;
	}
	int size(){
		return stack1.size();
	}
	bool empty(){
		return stack1.empty();
	}
};

int main()
{
	Queue q;

	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		q.push(i);
	}

	cout<<q.front()<<endl;
	cout<<q.size()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	cout<<q.empty()<<endl;

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}

	return 0;
}

/* 
	Test case :
	Input : 5
	Output : 
	1
	5
	2
	0
	2
	3
	4
	5
	Time Complexity : 
	Push operation : O(N).
	Pop operation : O(1).
	SpaceComplexity : O(N).
*/

