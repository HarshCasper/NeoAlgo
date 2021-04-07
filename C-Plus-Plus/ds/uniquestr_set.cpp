/* Usualy we use sorting methid for finding a unique string in the c++ 
In this code we used the set data structure to find unique string from given string
Here we decleared a char data type into a set data structure and compare that if the character is in the 
set or not. If that character will be in the set then we can say that, string is not unique
other wise we will say string is a unique string.*/

#include <bits/stdc++.h>
using namespace std;

bool solve(string str)
{
    set<char> ans;
    for (int i = 0; i < str.length(); i++)
    {
        if (ans.count(str[i]))
        {
            return false;
        }
        ans.insert(str[i]);
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter a string\n";
    cin >> s;
    if (solve(s))
    {
        cout << "\n This is a Unique String \n";
    }
    else
    {
        cout << "\n This is not a unique string \n";
    }
    return 0;
}

/* Time complexity: - O(N)
Space Complexity :- O(N)

    Sample Test Cases 
Input : abcde
Output : true;

Input : aabbbcdd
Output : false*/