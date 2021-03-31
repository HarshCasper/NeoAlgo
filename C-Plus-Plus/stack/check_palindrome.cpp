/*
This code is to find if the given string is palindrome or not with the help of stack.
Stack is used for this purpose because it works upon last in fast out criteria.
*/
#include <bits/stdc++.h>
using namespace std;

//boolean function to return true(1) if string is plindrome else return false(0);
bool func(string s)
{
    //find the length of string s;
    int length = s.length();
    int m = 0;
    //created inbuild stack
    stack<char> st;

    /*
   if string = aabba
   pushing each character of string in stack
    
    |a|
    |b|
    |b|
    |a|
    |a|
    ---
   */
    for (int i = 0; i < length; i++)
        st.push(s[i]);

    /* 
    poping all element one by one and then comparing with string char
    pop will result = abbaa
     string =aaba
     not maching return false ie 0;
    */
    while (!st.empty())
    {
        if (st.top() != s[m])
            return false;

        m++;
        st.pop();
    }
    return true;
}

//driver code
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    //this function will check if string is plindrome or not
    cout << func(s);
}
/*
  sample input;
  Enter the string: abbaa

  sample output
   0

   ->TC =O(n);
   ->SC =O(n);
*/
