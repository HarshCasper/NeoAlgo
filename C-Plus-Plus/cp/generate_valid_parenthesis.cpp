/*Problem Statement: 
You are given a number n, your job is to find all the n balanced parenthesis
combinations possible */

#include <bits/stdc++.h>
using namespace std;

/*Function description : 
At any index i, 
BASE CASE : 
The combination of brackets can at maximum reach 2*n length
therefore, if index reaches 2*n then print combination
RECURSIVE CASE:
1) If an open bracket is to be generated in the combination then,
	count of(open) bracket should be less than n
2) If a closed bracket is to be generated in the combination then,
	count of(close) bracket should be less than count of(open) bracket */

void FindValidParenthesis(char *out, int n, int index, int open, int close)
{
	if (index == 2 *n)
	{
		out[index] = '\0';
		cout << out << endl;
		return;
	}

	//If the number of open brackets is less than n
	if (open < n)
	{
		out[index] = '(';
		FindValidParenthesis(out, n, index + 1, open + 1, close);
	}

	//If the number of close brackets is less than the number of open brackets
	if (close < open)
	{
		out[index] = ')';
		FindValidParenthesis(out, n, index + 1, open, close + 1);
	}

	return;
}

int main()
{
	int n;
	cin >> n;
	char out[1000];
	int index = 0;
	FindValidParenthesis(out, n, 0, 0, 0);
	return 0;
}

/*Examples : 
1)Input : n = 2
Output-
(())
()()
2)Input : n = 3
Output-
((()))
(()())
(())()
()(())
()()()

Time Complexity : O(2^n)
Space Complexity : O(n) */

