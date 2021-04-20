/*
Given a string str, need to check if it is formed by an interleaving of two strings S and T.
S = s1 + s2 + ... + sn
T = t1 + t2 + ... + tm
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Dynamic Programming is used to meet the objective.
We will be checking each character of the given string which can come either from the first string or 
from the second string.
Eg- let s=aabcc
        t=dbbca
        str=aadbbcbcac
aabcc  ,  dbbca  ,  aadbbcbcac  (str[0]==s[0])
abcc   ,  dbbca  ,  adbbcbcac   (str[0]==s[0])
bcc    ,  dbbca  ,  dbbcbcac    (str[0]==t[0])
bcc    ,  bbca   ,  bbcbcac     (str[0]==s[0] as well as str[0]==t[0] hence two cases arise)
      case 1:        |      case 2: 
    cc,bbca,bcbcac   |  bcc,bca,bcbcac
                     
If we go on cutting the strings in the same way then we will encounter multiple cases,
some of them are overlapping cases also, hence dynamic programming is used.
*/
#include <iostream>
#include <vector>
using namespace std;
bool chkString(string s1, string s2, string s3)
{
    int l1 = s1.length();
    int l2 = s2.length();

    /* if summation of length of two strings is not equal to given string's length then the given
    string can never be formed by interleaving the other two. */
    if (l1 + l2 != s3.length())
    {
        return false;
    }

    /* rows represent characters of string s1
       and columns represent characters of string s2 */
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
    dp[0][0] = true;

    /* Initialising first row and column of dp matrix */
    for (int j = 1; j < l2 + 1; j++)
    {
        if (s2[j - 1] == s3[j - 1])

        {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i < l1 + 1; i++)
    {
        if (s1[i - 1] == s3[i - 1])
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    /* Filling the dp matrix 
       if last character from s3 matches last character from s2 
       then move one column back and copy the value
       else if it matches from s1 then move one row back as rows contain characters from s1
       and we are checking if after cutting this character,the remaining string matches or not
       similar logic applies when we are cutting characters from s2. */
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (s3[i + j - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i][j - 1];
            }
            if (s3[i + j - 1] == s1[i - 1] && dp[i][j] == false)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    /* final ans is stored at rightmost corner of matrix */
    return dp[l1][l2];
}
int main()
{
    string s1;
    string s2;
    string s3;
    cout << "Enter the two strings :\n";
    cin >> s1 >> s2;
    cout << "\nEnter the string to be checked :\n";
    cin >> s3;
    bool result = chkString(s1, s2, s3);
    if (result == true)
    {
        cout << "Yes the given string is an interleaved string\n";
    }
    else
    {
        cout << "The given string is not formed by interleaving the other two.\n";
    }
}
/*
Example 1:
Input-->
Enter the two strings :
aabcc
dbbca

Enter the string to be checked :
aadbbcbcac

Output-->
Yes the given string is an interleaved string

Example 2:
Input-->
Enter the two strings :
aabcc
dbbca

Enter the string to be checked :
aadbbbaccc

Output-->
The given string is not formed by interleaving the other two.

Time complexity:  O(n^2)        
Space complexity: O(n^2)
*/
