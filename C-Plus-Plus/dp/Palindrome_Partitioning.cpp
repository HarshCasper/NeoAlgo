/*
Given a string s, determine the minimum number of cuts required to make all substrings into palindrome.

Example : 
Given 
s = "aabbc",
Return 1, since the palindrome partitioning "aabb"|"c" can be made with just one cut. 
*/
#include <bits/stdc++.h> 
using namespace std; 

int dp[502][502];

/* 
Brute force: Recursion + Memoization

Recursively partition a substring into 2 substrings at k places and compute the temporary answer for every cut.
Memoize the code using a 2-dimenesional array where we look up before calling the function to avoid overlapping subproblems. 

TC=> O(n^3)
*/
bool palindromeCheck(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false;  
      i++;
      j--;
    }
    return true;
}

//Recursive function to check calculate minimum cuts
int minCutToPalindrome_Recc(string String, int i, int j)
{
    // If the sub problem is already stored in our table then return the value
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // if entire string is palindrome, return true. 
    if( i >= j || palindromeCheck(String, i, j) )
      return 0;
    int ans = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
        int left,right;
        // Check if the sub problem has already been computed before calling
        if(dp[i][k]!=-1){
            left= dp[i][k];
        } else{
            left= minCutToPalindrome_Recc(String, i, k);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1){
            right= dp[k+1][j];
        }
        else{
            right = minCutToPalindrome_Recc(String, k + 1, j);
            dp[k+1][j]=right;
        }
      count = left+right+1;
  
      ans = min(ans, count);
    }
    // store the answer before returning
    return dp[i][j]=ans;
}
/*
Optimal soltion: Computing dp (2D matrix) where [a,b] stores whether the sub-string 'a' to 'b' is a palindrome. 

*/
int minCutToPalindrome_Opt(string s) {
        int n = s.length();
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
    cout<<minCutToPalindrome_Recc(s,0,s.size()-1)<<endl;
    return 0; 
} 
