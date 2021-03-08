
/*
    Longest Palindromic Subsequence
        -> Find the longest subsequence of a string which is an palindrome

        -> A subsequence is a sequence that can be derived from another sequence 
        by deleting some or no elements without changing the order of the remaining elements.

    Example
        s = "bbbab"
        ans = 4, bbbb is the longest palindromic subsequence 

        s = "agbdba"
        ans = 5, abdba is the longest palindromic subsequence

    Approach
        -> calculate the ans for all possible length using dynamic programming
        -> for length 1 a,g,b,d,b,a ans is :1
        -> for length 2 ag,gb,bd,db,ba similarly for all other lenghts

        if let's say agbdba, s[i] = s[j] i.e s[0] == s[5]
        then ans = 2 + lps(i+1,j-1) i.e check the ans for gbdb

        for gbdb s[i] != s[j] i.e s[0] != s[3]
        ans = max(lps(i+1,j),lps(i,j-1)) i.e max lps for gbd and bdb  


*/
#include <bits/stdc++.h>
using namespace std;

int lps(string s){
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        dp[i][i] = 1; // if there is only 1 charcter 
    }

    for(int len = 2;len <= n;len++){ // calculate ans for string of lenght 2 or more ex ab,cd,abc,abcd
        for(int i=0;i<=n-len;i++){
            int j = i + len - 1; 
            if(s[i] == s[j]){ // if start and end charcters are same
                dp[i][j] = 2 + dp[i+1][j-1];
            }else {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1]; // i.e the whole string ex: abba, dp[0][3] = 4
}

int main(){
    string s;
    cin >> s;

    cout << lps(s) << endl;

}