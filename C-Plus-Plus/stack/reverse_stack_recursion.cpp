/*Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, 
for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)*/

#include<bits/stdc++.h>
using namespace std;

stack<char> st;

string ns;

char insert_at_bottom(char x)
{
if(st.size() == 0)
	st.push(x);

	else
	{}	
		char a = st.top();
		st.pop();
		insert_at_bottom(x);
		st.push(a);
	}
}

char reverse()
{
	if(st.size()>0)
	{
		char x = st.top();
		st.pop();
		reverse();
		insert_at_bottom(x);
	}
}

int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>x;
    st.push(x);
    }
	reverse();
	cout<<"Reversed Stack"<<endl;

	while(!st.empty())
	{
		char p=st.top();
		st.pop();
		ns+=p;
	}

	cout<<ns[3]<<" "<<ns[2]<<" "<<ns[1]<<" "<<ns[0]<<endl;
	return 0;
}
/*
Example
Input
4
1 2 3 4
Reversed Stack
4 3 2 1

Time Complexity: This approach takes the worst time complexity of O(n^2), 
*/

