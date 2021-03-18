/*
Infix to Postfix conversion using stacks in C++
ALGORITHM:
*Scan the element from left to right
*If the scanned element is a '(' push to stack
*If scanned element is a '), pop and output contents of stack till empty or '(' is encountered
*If scanned element is an operand output it
*If scanned element is an operator, then check for precedence
*If the precedence of scanned elements is less than the precedence of the operators in the stack then pop and output
*If the precedence of scanned elements is greater than the precedence of the operators in the stack then push into stack
*/
#include <bits/stdc++.h>
using namespace std;
int prec(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
}
void infixToPostfix(string s)
{
    int l = s.length();
    stack<char> st;
    string new_string = "";
    st.push('X');
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (st.top() != 'X' && st.top() != '(')
            {
                char x = st.top();
                new_string += x;
                st.pop();
            }
            if (st.top() != 'X' && st.top() == '(')
            {
                st.pop();
            }
        }
        else if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-')
        {
            while (st.top() != 'X' && prec(st.top()) >= prec(s[i]) && st.top() != '(')
            {
                new_string += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            new_string += s[i];
        }
    }
    while (st.top() != 'X')
    {
        new_string += st.top();
        st.pop();
    }
    cout << new_string << "\n";
}
int main()
{
    string s;
    cin >> s;
    infixToPostfix(s);
}
/*
Time Complexity: O(n^2)
INPUT:
a+b+(c*d)
OUTPUT:
ab+cd*+
*/
