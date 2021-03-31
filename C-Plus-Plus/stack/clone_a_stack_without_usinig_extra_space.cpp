// Below is the implementation of
// Cloning a stack into destination stack without using extra space
#include<bits/stdc++.h>
using namespace std;
// This Function takes takes two stakes as input and
// copy data of first stack to the second stack  

void clonestack(stack<int> st, stack<int> &cloned) 
{
	if (st.size() > 0) //this is the base case when the source stack is empty
	{
		int x = st.top();  //stores the top of the stack
		st.pop();

		clonestack(st, cloned); //this will copy element of rest of stack

		cloned.push(x); // now put the current element on the top
	}
}
int main()
{
	stack<int> source, dest;
	cout<<"Enter the no. of elements\n";
	int n,element;
	cin>>n;
	cout<<"Enter the elements of stack\n";
	for(int i=0;i<n;i++){
		cin>>element;
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
}

/*

		OUTPUT

	Source Stack : 4 3 2 1 
	
	Cloned Stack : 4 3 2 1  

*/

