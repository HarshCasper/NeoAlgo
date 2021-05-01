/*
An expression is called prefix , if the operator appears in the expression before the operands. (operator operand operand)
An expression is called postfix , if the operator appears in the expression after the operands . (operand operand operator)
The program below accepts an expression in prefix and outputs the corresponding postfix expression .
*/
#include <bits/stdc++.h>
using namespace std;
// if operand function checks if the element is an operand
int ifoperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}
// prefixtopostfix function converts a prefix expression to postfix
void prefixtopostfix(string expression)
{
    stack<string> s;
    int len = expression.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (ifoperand(expression[i]))
        {
            s.push(string(1, expression[i]));
        }
        else
        {
            string exp(1, expression[i]);
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + exp;
            s.push(temp);
        }
    }
    cout << "the postfix expresssion is : " << s.top();
}
// Driver code
int main()
{
    string exp;
    printf("Enter the prefix expression \n");
    cin >> exp;
    prefixtopostfix(exp);
    return 0;
}

/*
Sample I/O:

Enter the prefix expression
*+abc
the postfix expresssion is : ab+c*

Time complexity : O(n)
space complexity : O (n)
*/
