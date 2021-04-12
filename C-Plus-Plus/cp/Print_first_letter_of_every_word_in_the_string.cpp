/*
Description: 
        In a given string, the task is to create a string
        with the first letter of every word in the string.
        For example a given string is = "hey you" ,so output 
        will be = "hy" (first letter of each word).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string firstAlphabet(string S)
    {
        //empty string to store answer
        string result = "";
        bool val = true;
        //size of the string
        int len = S.length();
        for (int i = 0; i < len; i++)
        {
            if (S[i] == ' ')
            {
                val = true;
            }
            else if (S[i] != ' ' && val == true)
            {
                result.push_back(S[i]);
                val = false;
            }
        }
        return result;
    }
};

int main()
{
    string input_string;
    cout << "Enter the string : " << endl;
    getline(cin, input_string);
    Solution ob;
    cout << "Resultant string : " << endl;
    cout << ob.firstAlphabet(input_string) << endl;
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Cases :
    Test Case 1 :
        Input :
        Enter the string : 
        united public school
        Output : 
        Resultant string : 
        ups
    Test Case 2 : 
        Input : 
        Enter the string : 
        computer science
        Output :
        Resultant string : 
        cs
*/

