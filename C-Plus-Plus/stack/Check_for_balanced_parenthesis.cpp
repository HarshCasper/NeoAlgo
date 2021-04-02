/*
Check for balanced parenthesis
==============================
Given an expression containing parenthesis, check if it is well-formed or balanced.
A balanced parenthesis means for every opening bracket there must be equivalent closing brackets.
Application: Stack data structure
Author: @gargvader
Edit by: @Mohim-Singla
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Driver code
int main()
{
    string expr;
    cout << "Enter a expression " << endl;
    cin >> expr;

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced Parenthesis";
    else
        cout << "Unbalanced Parenthesis";
    return 0;
}
/*
-------------------------------
Test case 1:
Input:
((a+b)+(c-d+f))
Output:
Balanced Parenthesis
-------------------------------
Test case 2:
Input:
{(a+b)+(c-d+f)]}
Output:
Unbalanced Parenthesis
---------------------------------
Test case 3:
Input:
(a+b)*{c*[a+b*(c+d)}]
Output:
Unbalanced Parenthesis
--------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/
