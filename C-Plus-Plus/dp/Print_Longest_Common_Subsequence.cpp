/*
A subsequence is a sequence that can be derived from another sequence by removing zero or more elements, without 
changing the order of the remaining elements.
Example - If we have a string "Subsequence" - 
          Then some of the subsequences can be - "Sbsqnce" 
                                                 "bseqen"
                                                 "quene"

If we have two strings, then a common subsequence is the subsequence which is present in both of the strings
and the longest among all of them is called Longest Common Subsequence.

In this code we will know how to print the longest common subsequence using dp approach.
Example - for "QWERTYHU" and "WROPYHUI" , the output will be "WRYHU".
            
*/

#include <bits/stdc++.h>
using namespace std;

string longest_common_sub(string str_1, string str_2)
{
    string s;
    int len_1, len_2; // length of the strings
    len_1 = str_1.length();
    len_2 = str_2.length();
    int dp[len_1 + 1][len_2 + 1]; //dp matrix

    //initializing the matrix
    for (int i = 0; i <= len_1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= len_2; i++)
    {
        dp[0][i] = 0;
    }

    /* Filling the matrix int dp[] , where dp[i][j] contains the value of longest common subsequence of the
      strings s1 and s2, where length of s1 is 'i' and that of s2 is 'j';
    */
    for (int i = 1; i <= len_1; i++)
    {
        for (int j = 1; j <= len_2; j++)
        {
            if (str_1[i-1] == str_2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i, j;
    i = len_1;
    j = len_2;
    /* In this loop, we are traversing the matrix in backward direction and tracing the longest common
    subsequence. 
    */
    while (i >= 1 && j >= 1)
    {
        if (str_1[i-1] == str_2[j-1])
        {
            s.push_back(str_1[i-1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    cout<<"Length of the longest common subsequence is "<<s.length()<<endl;
    reverse(s.begin(),s.end());
    cout<<"Longest common subsequence is "<<s<<endl;
    return s;
}

int main()
{
    string str_1, str_2;
    cout << "Enter two strings: ";
    cin >> str_1 >> str_2;
    longest_common_sub(str_1,str_2);
}
 /*
    Time Complexity - O(lengthOfStr1*lengthofStr2) as in the above approach the dp matrix of dimensions [lengthOfStr1][lengthofStr2]
                      is firstly filled completely - first traversal and second traversal - to find the subsequence.
    SAMPLE INPUT AND OUTPUT - 
    1) Enter two strings: QWERTYHU   WROPYHUI
       Length of the longest common subsequence is 5
       Longest common subsequence is WRYHU
       
    2) Enter two strings: CODING   ENCODING
       Length of the longest common subsequence is 6
       Longest common subsequence is CODING
 */
