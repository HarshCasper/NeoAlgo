/*
Given a string str, need to check if it is formed by an interleaving of two strings S and T.
S = s1 + s2 + ... + sn
T = t1 + t2 + ... + tm
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Dynamic Programming is used to meet the objective .
-->moving across rows in dp matx- traversing the string S
-->moving across columns in dp matx- traversing the string T
*/
#include <iostream>
#include <vector>
using namespace std;
bool chkString(string s1, string s2, string s3)
{
    int l1 = s1.length();
    int l2 = s2.length();
    /*
    if summation of length of two strings is not equal to given string's length then the given
    string can never be formed by interleaving the other two.
    */
    if (l1 + l2 != s3.length())
    {
        return false;
    }
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));

    //s1=="" s2=="" and s3=="", hence dp[0][0]==true
    dp[0][0] = true;

    //Initialising first row of dp matrix
    for (int j = 1; j < l2 + 1; j++)
    {
        if (s2[j - 1] == s3[j - 1])

        {
            dp[0][j] = dp[0][j - 1];
        }
    }

    //Initialising first column of dp matrix
    for (int i = 1; i < l1 + 1; i++)
    {
        if (s1[i - 1] == s3[i - 1])
        {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            /*if last character from s3 matches last character from s2 
            then move one column back and copy the value*/
            if (s3[i + j - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i][j - 1];
            }
            /*if last character from s3 matches last character from s1, also previous chk was false 
            then move one row back and copy the value*/
            if (s3[i + j - 1] == s1[i - 1] && dp[i][j] == false)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    /* Display dp matrix
     for(int i=0;i<l1+1;i++)
    {
        for(int j=0;j<l2+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    */

    //final ans is stored at rightmost corner of matrix
    return dp[l1][l2];
}
int main()
{
    string s1;
    string s2;
    string s3;
    //cout << "Enter strings:";
    cin >> s1 >> s2 >> s3;
    cout << chkString(s1, s2, s3);
}
/*
Sample Input:
s1 = "aabcc";
s2 = "dbbca";
s3 = "aadbbcbcac";

Output:  true (1) 
Time complexity: O(l1*l2)    l1=s1.length()    l2=s2.length()
Space complexity: O(l1*l2)  
*/
