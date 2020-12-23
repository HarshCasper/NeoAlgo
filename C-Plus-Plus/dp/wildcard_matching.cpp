/**

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

**/

#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {

    int rows = p.length()+1, cols = s.length()+1;
    // dp table 
    bool dp[rows][cols];
    dp[0][0] = true;
    
    for(int i = 1; i < cols; i++)
        dp[0][i] = false;
    for(int i = 1; i < rows; i++)
        dp[i][0] = dp[i-1][0] && (p[i-1] == '*');
    
    // populating the dp table
    for(int row = 1; row < rows; row++)
        for(int col = 1; col < cols; col++)
            if(p[row-1] == '*')
                dp[row][col] = dp[row-1][col] || dp[row-1][col-1] || dp[row][col-1];
            else
                dp[row][col] = (dp[row-1][col-1] && ((p[row-1] == s[col-1]) || (p[row-1] == '?')));
    
    return dp[rows-1][cols-1];
}

int main() {
    string str, pattern;
    cin >> str >> pattern;
    cout << (isMatch(str, pattern) ? "Pattern matches the given string\n" : "Pattern does not match the given string\n");
}

/**

Input :
aa *
Output :
Pattern matches the given string

Time Complexity : O(mn)
Space Complexity : O(mn)

where m is length of the string
and n is length of the pattern

**/