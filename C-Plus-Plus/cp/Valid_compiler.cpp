/*
This is CP problem
Description:
Suppose company want to build thier own compiler.Compiler checks
wheather given code expression is valid or not.

Example : Valid : <<>>, <> ,<><>
          Invalid: ><, >><<< ,><><>

You are an employee their and you have been assigned the task of 
compiler , weather the code expression is valid or not.

Given some expressions in form of string('<' and '>') which represent 
some instruction to be analyzed by Compiler.Your task is to write a code
for compiler to check weather given expression is valid or not if
valid return Compiled else Error
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int c = 0;
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() && s[i] == '>')
                break;
            if (s[i] == '<')
                st.push('<');
            else if (s[i] == '>' && !st.empty())
            {
                c += 2;
                st.pop();
            }
            if (st.empty())
                ans = max(ans, c);
        }
        if (ans != 0)
            cout << "Compiled\n";
        else
            cout << "Error\n";
    }
}
/*

Sample Input:
3
<<>>
><
<>>>

Sample output:
Compiled
Error
Compiled

Time-complexity: O(n) : n is size of expression string
Space-Complexity: O(1)

*/
