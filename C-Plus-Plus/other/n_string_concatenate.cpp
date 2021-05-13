/*
String Concatenation 
Problem Statement : Take n string from user and concatenate them together.
Input Format : First line takes number of strings to be concatenated.
               Next n lines contains the strings to be concatenated.
Output Format : Print a single line that contains the concatenated string.
Note : No space is there in between a single string.

Approach : Take n strings as input using loop.
           Take a string variable and update it using append() function each time a new sting is entered.
           Print the string.
*/

#include <bits/stdc++.h>
using namespace std;

//within concat_str(...) final string is calculated sing append()
void concat_str(vector<string> str,int size)
{
    string f_str="";
    for(int i=0;i<size;i++)
    {   
        f_str.append(str[i]);
    }
    cout<<f_str;
}

int main() 
{
    vector<string> s;
    //n stores the no. of string
    int n; 
    cin>>n; 
    //loop for taking n strings from user 
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        s.push_back(a);
    }
    concat_str(s,n);
    return 0;
}

/*
Time Complexity : O(n*m), where m is maximum length of string a
Space Complexity : O(k), where k is final length of f_str

Sample Test Case :
Input : 4
        "This"
        "is"
        "Concatenated"
        "String."
Output : "ThisisConcatenatedString."
*/
