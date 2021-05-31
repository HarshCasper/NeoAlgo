/*
Description : 
    Given an input string, write a code that returns the Run Length Encoded string for the input string.
    For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”
*/

#include <bits/stdc++.h>
using namespace std;

// function to incode
void encode(string str)
{
    // length of the string
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        int counter = 1;
        while (i < len - 1 and str[i] == str[i + 1])
        {
            // updating the counter
            counter++;
            i++;
        }
        // printing the updated  counter
        cout << str[i] << counter;
    }
    cout << endl;
}

int main()
{
    // input string
    string str;
    cout << "Enter the string to encode : " << endl;
    cin >> str;

    cout << "Encoded string : " << endl;
    encode(str);
    return 0;
}
/*
Time complexity : O(N)
Space complexity : O(1)
*/

/*
Test Case : 
  Input :
    Enter the string to encode : 
    xxxxyyyyaa
  Output :
    Encoded string : 
    x4y4a2
*/

