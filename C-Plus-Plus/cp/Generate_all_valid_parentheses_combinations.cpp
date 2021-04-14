/*
Problem statement : Given n pairs of parentheses, we have to write a function to generate all combinations of well-formed parentheses.

Constraints:

1 <= n <= 8

Approach : We will be given a number n which represents the pairs of parentheses, and we need to find out all of their valid combinations.So there are n opening brackets and n closing brackets ,and each valid combination will be of length 2*n.

A valid parentheses combination is the one where every opening parenthesis ( has its corresponding closing ).We can solve this problem using recursion by generating all the combinations of parenthesis but this will be the naive approach as it generates all the permutations.So,
The time complexity of this approach will be O(2^2n) which is quite large.

So , we can improve this by generating only those combinations which we know for sure will be valid combination and so our time complexity will reduce considerably.We can use backtracking for this purpose.We need to keep some points in mind for the combination to be valid:

1. Base case when number of opening and closing parentheses is equal to 0.
2. A closing parenthesis cannot occur before the open parenthesis.

For n = 2 , recursive tree is as follows
open denotes open parentheses count , similarly close denotes close parentheses count


                                 output_string "" {open = 2, close = 2}
                                               /
                                 choose (     /
                                             /
                                            /
                                           /
                                 output_string "(" {open = 1, close = 2}
                                            /    \
                                choose (   /      \  choose )
                                          /        \
                                         /          \
                                        /            \
       output_string "((" {open = 0,close = 2}      output_string "()" {open = 1 , close = 1}
                                \                                     /
                                 \ choose )              choose (    /
                                  \                                 /
                                   \                               /
          output_string "(()" {open = 0, close = 1}         output_string "()(" {open = 0 , close = 1}
                                \                                      \
                                 \ choose )                             \
                                  \                                      \  choose )
                                   \                                      \
          output_string "(())" {open = 0, close = 0}           output_string "()()" {open = 0, close = 0}

                             *STOP AND RETURN*                                       *STOP AND RETURN*



*/
/* Input  : an interger n
   Output : vector of strings which will store our valid parentheses combination strings.
*/

// Code part

#include<bits/stdc++.h>
using namespace std;


// This function is used to generate all well-formed combination of parentheses

void generateParenthesis(int open, int close, string op, vector<string>&ans)
{
    // Base case : if count of open and close parentheses is both 0.

	if (open == 0 && close == 0)
	{
	 // push the output valid string combination to the answer vector and return
		ans.push_back(op);

		return;
	}

    // open bracket will always be one of the choice , given only the condition that open != 0
	if (open != 0)
	{
		string op1 = op;

    // output1 string (like we can see in recursive tree , it is the output string of when  we select '(')
		op1.push_back('(');

	// now , count of open brackets will decrease by 1 as we have used it now , and output string will be given as the op1 string now.
		generateParenthesis(open - 1 , close, op1 , ans);
	}

    //close bracket will only be chooses if its count is not 0 , i.e close != 0 and count of close parenteses > count of open parenteses, i.e close > open

    // As the closing parenthesis cannot occur before the open parenthesis for generating valid combination.

	if (close != 0 && close > open)
	{
		string op2 = op;

    // output2 string (like we can see in recursive tree , it is the output string of when  we select ')')
		op2.push_back(')');

    // now , count of close brackets will decrease by 1 as we have used it now , and output string will be given as the op2 string now.
		generateParenthesis(open, close - 1, op2, ans);
	}
}

int main()
{
	int n;

	cout << "Enter the number:" << endl;

	cin >> n;

    // this is our output vector
	vector<string>ans;

    // this represents the open parentheses count.
	int open = n;

    // this represents the close parentheses count
	int close = n;

    // this is the output string , which will be out valid parentheses combination string , initially it is empty
	string op = "";

    // let's call the function
	generateParenthesis(open, close, op, ans);

    // printing the output vector
	for (int i = 0 ; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}

/* Time complexity:It is somewhat hard to calculate time complexity for this problem.This indicates the nth Catalan number problem (Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems) which is bounded asymptotically by 4^n/(n\sqrt(n)), where n is the atmost steps during the backtracking procedure.So the time complexity is O(4^n/sqrt(n))

Space complexity:Logic is same for atmost n steps of backtracking procedure space complexity would be O(4^n/sqrt(n)) and for storing the results O(n).

Sample test cases :

n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

n = 2, a solution set is:
[
  "()()",
  "(())"
]

n = 1, a solution set is:
[
  "()"
]

*/


