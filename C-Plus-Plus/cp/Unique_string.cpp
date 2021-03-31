/* When we enter a string and if it have the duplicate values as well,
then this code remove that duplicate values and will give us a unique string */

#include <bits/stdc++.h>
using namespace std;

/*This code return true if the size of string will be 0 or 1.
If the sizeof the string will be more than 1 then it will remove all duplicate characters*/

bool solve(string s)
{
    if (s.length() == 0 || s.length() == 1)
    {
        return true;
    }
    sort(s.begin(), s.end());
    bool flag = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            flag = 0;
        }
    }
    return flag;
}

int main()
{
    string n;
    cout << "Enter a string: ";
    cin >> n;
    if (solve(n))
    {
        cout << "\n This string has all unique characters";
    }
    else
    {
        cout << "\n This string has duplicate characters";
    }
    return 0;
}

/* Sample test case:
Input: "abcde"
Output: true

Input: "aab"
Output: false

Time Complexity: O(N)
Space Complexity: O(1)
*/
