/* Below is the implementation of Cloning a stack into destination stack without using extra space */
#include<bits/stdc++.h>
using namespace std;
/* This Function takes takes two stakes as input and copy data of first stack to the second stack.
   It is a recursive code in which we store the top element of the stack in a temporary variable
   and call the function which clones rest of the stack and push the stored to the top of
   the stack.
*/
void clonestack(stack<int> st, stack<int> &cloned)
{
	if (st.size() > 0)
	{
		int x = st.top();
		st.pop();
		clonestack(st, cloned);
		cloned.push(x);
	}
}

int main()
{
	stack<int> source, dest;
	cout << "Enter the no. of elements\n";
	int n, element;
	cin >> n;
	cout << "Enter the elements of stack\n";
	for (int i = 0; i < n; i++) {
		cin >> element;
		source.push(element);
	}
	clonestack(source, dest);
	cout << "Source Stack : ";
	while (!source.empty()) {
		cout << source.top() << " ";
		source.pop();
	}
	cout << endl;
	cout << "Cloned Stack : ";
	while (!dest.empty()) {
		cout << dest.top() << " ";
		dest.pop();
	}
	return 0;

	/*
	INPUT

	Enter the no. of elements
	5
	Enter the elements of stack
	3 5 1 2 4

	OUTPUT

	Source Stack : 3 5 1 2 4
	Cloned Stack : 3 5 1 2 4

	*/
