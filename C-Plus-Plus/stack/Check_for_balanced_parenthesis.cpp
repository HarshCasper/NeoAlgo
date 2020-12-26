/*
Check for balanced parenthesis
==============================
Given an expression containing parenthesis, check if it is well-formed or balanced.
Example of balanced parenthesis are: (), ((())), (a+b), (a/b)*(b/a)

Application: Stack data structure
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
	// Size of the string
	int n = str.size();

	// Stack to store open parenthesis
	stack<int> s;
	// Open parenthesis -> 1

	// Loop through characters in the string
	for (int i = 0; i < n; i++) {
		// Open parenthesis is always pushed into the stack
		if (str[i] == '(') {
			s.push(1);
		} else if (str[i] == ')') {
			// Closed parenthesis encountered must be balanced by an open parenthesis already
			// present in the stack
			if (!s.empty()) {
				// Stack contains open parenthesis, one of which has been balanced
				// Pop one parenthesis out
				s.pop();
			} else {
				// Stack contains no open parenthesis. So closed parenthesis cannot be balanced
				return 0;
			}
		}
	}

	// Check if we have open parenthesis remaining
	if (s.size()) {
		return 0;
	} else {
		return 1;
	}
}

int main() {

	// Input the string
	string str; cin >> str;

	if (isBalanced(str)) cout << "Yes";
	else cout << "No";
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