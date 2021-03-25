// Below is the implementation of
// Cloning a stack into destination stack without using extra space


#include <bits/stdc++.h>
using namespace std;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;



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
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
	stack<int> source, dest;
	source.push(1);
	source.push(2);
	source.push(3);
	source.push(4);
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
	// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

/*

		OUTPUT

	Source Stack : 4 3 2 1 
	
	Cloned Stack : 4 3 2 1  

*/

