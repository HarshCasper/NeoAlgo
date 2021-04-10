/*
Description : In a given string, the task is to create a string
              with the first letter of every word in the string.
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
    //input string
    string input_string;
    getline(cin, input_string);
    //object of a class
    Solution ob;
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
        Input : united public school
        Output : ups
    Tes Case 2 : 
        Input : computer science
        Output : cs
*/
