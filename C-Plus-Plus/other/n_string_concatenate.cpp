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

int main() {
    //n stores the no. of string
    int n; 
    cin>>n; 
    //f_str contains the final string  
    string f_str="";
    //loop for taking n strings from user and updating the final string 
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        //f_str.append() appends the string each time a new string is entered 
        f_str.append(a);
    }
    cout<<f_str;
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
