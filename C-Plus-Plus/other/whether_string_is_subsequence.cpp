/*
Given two strings s1 and s2, check if s1 is a subsequence of s2.
A subsequence of a string is a new string that is formed from the original string
by deleting some (can be none) of the characters
without disturbing the relative positions of the remaining characters.
*/

#include <bits/stdc++.h>
using namespace std;

bool check_is_Subsequence(string s1, string s2)
{
    int size_1 = s1.size();
    int size_2 = s2.size();
    if(size_1 > size_2)
    {
        /* here string s1 size is greater than string s2 size
        so it can't be a subsequence of string s2.
        */
        return false;
    }
    if(size_1 <= size_2)
    {
        int j = 0;
        for(int i = 0; i < s2.size(); i++)
        {
            if(s1[j] == s2[i])
            {
                /* if s1[j] is same of s2[i]
                then we will increment j
                */
                j++;
            }
        }
        if(j == size_1)
        {
            /* here string s1 size is equal to j
              so it is a subsequence of string s2.
            */
            return true;
        }
        else
        {
            return false;
        }

    }
}
int main()
{
    cout << "Enter two strings : \n";
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    bool is_Subsequence = check_is_Subsequence(s1, s2);
    if(is_Subsequence)
    {
        cout << "Yes! string s1 is a subsequence of string s2\n";
    }
    else
    {
        cout << "No! string s1 is NOT a subsequence of string s2\n";

    }
}

/*
Standard Input and Output

1.
Enter two strings :
abc
ahbgdc

Yes! string s1 is a subsequence of string s2

2.
Enter two strings :
sgdtb
vrdgtrv

No! string s1 is NOT a subsequence of string s2

Time Complexity : O( N )
Space Complexity : O( 1 )

*/
