//to reverse the string with the help of stack( LIFO property)
// TC = O(n)
// SC = O(n) space taken by stack

#include <bits/stdc++.h>
using namespace std;

void reverse_string(string s)
{
    stack<char> st; //created the stack

    //pushing each charecter of string in the stack
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    s.empty();

    //poping each charecter and putting in empty string named 's'
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = st.top();
        st.pop();
    }

    //requires reverse string
    cout << s;
}

int main()
{
    string s;
    cout << "Enter any word to reverse " << endl;
    cin >> s; //this function is used to input the string

    reverse_string(s); //this function to reverse the string
}