/*
Given a string s, determine the minimum number of cuts required to make all substrings into palindrome.
*/
#include <bits/stdc++.h> 
using namespace std; 

bool dp[1001][1001];

int minCutToPalindrome_Opt(string s) {
        int n = s.length();
        // Computing dp (2D matrix) where [a,b] stores whether the sub-string 'a' to 'b' is a palindrome.
        bool dp[s.length()][s.length()];
        for (int mid = 0; mid < s.length(); mid++) {
            int si = 0, ei = mid;
            while (ei < s.length()) {
                //If no letter is present in the gap then it is a palindrome
                if (mid == 0) {
                    dp[si][ei] = true;
                } 
                //If one letter is present in middle then it is a palindrome if both the extreme letters are same
                else if (mid == 1) {
                    dp[si][ei] = s[si] == s[ei];
                } 
                //If more than more letter in the middle then both the extreme letters must be same, and compare the middle string represented by dp[si + 1][ei - 1];
                else {
                    if (s[si] == s[ei]) {
                        dp[si][ei] = dp[si + 1][ei - 1];
                    } else {
                        dp[si][ei] = false;
                    }
                }
                si++;
                ei++;
            }
        }
// Array to store minCuts for every suffix
        int cuts[n];
        for (int i = 0; i < n; i++) {
            if (dp[0][i] == true) {
                cuts[i] = 0;
            } else {
                cuts[i] = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if(dp[j + 1][i] == true && 1 + cuts[j] < cuts[i]){
                        cuts[i] = 1 + cuts[j];
                    }
                }
            }
        }
        return cuts[n - 1];
    }

int main() 
{ 
    memset(dp,-1,sizeof(dp));
    string s;
    cin>>s;
    cout<<minCutToPalindrome_Opt(s)<<endl;
    return 0; 
}

/*
Time complexity: O(n^2) 

Sample Input 1: 
RADARROTATOR
Output: 1
Explanation: We can make 1 cut and make the resulting substrings palindromes. (RADAR | ROTATOR)

Sample Input 2:
REFERENCE
Output: 4
Explanation: We need to cut the string at 4 places i.e, REFER | E | N | C | E
*/
