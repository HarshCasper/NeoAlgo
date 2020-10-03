/*Problem: Given array of strings, find the longest common prefix present in all the strings.
Print the longest common prefix. If no common prefix is present, then print empty string ("").

Approach: Comparing characters of the same column in all the strings. If the character does not much
or the string ends at that column, algorithm will retun lcp till that point.

Time complexity:O(S) where S is the number of all the characters in all strings.
Space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

string solve(int n, string *strs)
{
    string lcp = "";
    char cur_car;
    int j = 0;
    if (n == 0)
    {
        return "";
    }
    while (1)
    {
        if (strs[0] == "")
        {
            return "";
        }
        if (strs[0][j] == '\0')
        {
            return lcp;
        }
        else
        {
            cur_car = strs[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            if (strs[i] == "")
            {
                return "";
            }
            if (strs[i][j] == '\0' || strs[i][j] != cur_car)
            {
                return lcp;
            }
        }
        lcp += cur_car;
        j++;
    }
    return lcp;
}

int main()
{
    //input
    //number of strings in array
    cout << "Enter number of strings:" << endl;
    int n;
    cin >> n;
    string *strs = new string[n];
    //enter strings
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    string lcp = solve(n, strs);
    if (lcp == "")
    {
        cout << "No common prefix";
    }
    else
    {
        cout << "Longest Common Prefix is: " << lcp;
    }
}

/*
Sample input:
"apple", "appology", "apps"

Sample output:
"app"
*/