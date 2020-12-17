/*
Check for balanced paranthesis
==============================
Given an expression containing paranthesis, check if it is well-formed or balanced

Application: Stack data structure
*/

#include<iostream>
#include <stack>
using namespace std;

int main() {

	// Input the string
	string str; cin >> str;
	// Size of the string
	int n = str.size();

	// Stack to store open paranthesis
	stack<int> s;
	// Open paranthesis -> 1

	// Loop through characters in the string
	for (int i = 0; i < n; i++) {
		// Open paranthesis is always pushed into the stack
		if (str[i] == '(') {
			s.push(1);
		} else if (str[i] == ')') {
			// Closed paranthesis encountered must be balanced by an open paranthesis already
			// present in the stack
			if (!s.empty()) {
				// Stack contains open paranthesis, one of which has been balanced
				// Pop one paranthesis out
				s.pop();
			} else {
				// Stack contains no open paranthesis. So closed paranthesis cannot be balanced
				cout << "No" << endl;
				return 0;
			}
		}
	}

	// Check if we have open paranthesis remaining
	if (s.size()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}

/*
Input:
((a+b)+(c-d+f))

Output:
Yes

Input:
((a+b)+(c-d+f)))

Output:
No
*/