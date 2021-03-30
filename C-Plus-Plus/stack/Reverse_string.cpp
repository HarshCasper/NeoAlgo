/*
The below code is used to reverse the string with the help of stack. The reason we always prefer stack for reverse string is because
 stack work on last in fast out criteria , i.e the first charector pushed in stack will pop at last and vise versa.
*/
#include <bits/stdc++.h> 
using namespace std;

//function to reverse the string using stack
void reverse_string(string s)
{
    stack<char> st; //created the stack

    //pushing each charecter of string in the stack
    for (int i = 0; i < s.length(); i++)
        st.push(s[i]);
   
    s.empty();
    //poping each charecter and putting in empty string named 's'
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = st.top();
        st.pop();
    }
    //prienting the reversed string
    cout <<"This is your reversed string: "<< s;
}
//driver code
int main()
{   string s;
    cout << "Enter any word to reverse: ";
    cin >> s; //this function is used to input the string
    reverse_string(s); //this function to reverse the string
    return 0;
}
/*
   Sample input:
   Enter any word to reverse: Laptop
   
   Sample output:
   This is your reversed string: potpaL
   
-> TC = O(n) as whole string is traversed linearly
-> SC = O(n) space taken by stack
   
*/
