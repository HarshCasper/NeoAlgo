/*
 Introduction:-
    Given a valid parentheses string , consider its primitive decomposition:P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.
    Return a string after removing the outermost parentheses of every primitive string in the primitive decomposition of the String.

 Solution approach:-
    If the parentheses is outer most and it is a closing parenthese then the size of the stack has to be equal to one. If the parenthese is opening then the size should be 0. Other wise they are inner parentheses.
*/
#include <bits/stdc++.h>
using namespace std;

 string removeOuterParentheses(string S) 
 {
    stack<char> st;
    string ans = "";
    for(int i = 0;i<S.size();i++)
    {
        if(S[i] == '(')
        {
            if(st.size() >= 1)
            {
            ans.push_back(S[i]);
            }
            st.push(S[i]);
        }
        else
        {
            if(st.size() > 1)
            {
                ans.push_back(S[i]);
            }
            st.pop();
        }
    }
    return ans;
}
int main() 
{
    string S;
    cout<<"Enter the string consisting of '(' and ')' only : ";  
    cin >> S;
    string ans = removeOuterParentheses(S);
    cout<<"String after removing the outermost parenthesis is : "<<ans<<"\n";
    return 0;
}
/*
Standard Input and Output:-
Enter the string consisting of '(' and ')' only : (()())
String after removing the outermost parenthesis is : ()()

Time Complexity:O(n)
Space Complexity:O(n)
*/
