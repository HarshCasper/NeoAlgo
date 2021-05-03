/*
Code to convert a postfix expression to prefix expression using stacks
ALGORITHM
* Scan the postfix expression from left to right
* If the symbol is an operand, push it to the stack
* If the symbol is an operator, pop two operands from the stack 
* Create a string by concatenating the two operands and the operator before them. 
* Push the resultant string back to Stack
*/

#include<bits/stdc++.h>
using namespace std;

void postfixToPrefix(string s)
{
    stack<string> str;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            string operand1=str.top();
            str.pop();
            string operand2=str.top();
            str.pop();
            //Creating the string by concatenating the operator and the operands
            string prefix_part=s[i]+operand2+operand1;
            str.push(prefix_part);
        }
        else
        {
            str.push(string(1,s[i]));
        }
    }
    while(!str.empty())
    {
        cout<<str.top();
        str.pop();
    }
}

//Driver code
int main()
{
    string s;
    cout<<"Enter the postfix expression:\n";
    cin>>s;
    cout<<"Prefix expression:\n";
    postfixToPrefix(s);
}

/*
Space Complexity : O(n)

Time Comlexity : O(n)

Example:
Input:
Enter the postfix expression:
ABC/-A

Output: 
Prefix Expression:
A-A/BC
*/
