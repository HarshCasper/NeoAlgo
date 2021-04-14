/* 
 Problem description:
 Given two strings, find the length of shortest common supersequence
 between them i.e. the length of shortest string that contains both 
 the strings as it's subsequences.


                          APPROACH
-------------------------------------------------------------------- 
We will use Dynamic Programming approach to solve this problem.Shortest
Common Supersequence of two strings can be found by concatenating
both the given strings and removing a single occurence of Longest
Common Subsequence from it, as it contains Longest Common Subsequence
twice. The length of Longest Common Supersequence can be determined
with the help of Dynamic Programming.
 
*/

#include<bits/stdc++.h>
using namespace std;


int ShortestCommonSuperseq(string str_1, string str_2){
    int str1_len = str_1.size();
    int str2_len = str_2.size();
    
    //Declaring dp matrix
    int dp[str1_len + 1][str2_len + 1]; 
    

    //Initialising DP matrix with 0
    memset(dp, 0, sizeof(dp));
    /*
      Filling DP matrix int dp[][], where dp[i][j] stores the length of longest common subsequence,
      considering first 'i' characters of the first string and first 'j' characters of second string.
    */
    
    for(int i=1; i<=str1_len; i++){
        for(int j=1; j<=str2_len; j++){
           if(str_1[i-1] == str_2[j-1]){
               dp[i][j] = 1 + dp[i-1][j-1];
           }
           else{
               dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
           }
        }
    }
    int LCS_len = INT_MIN;
    for(int i=0; i<=str1_len; i++){
        for(int j=0; j<=str2_len; j++){
          LCS_len = max(LCS_len, dp[i][j]);
        }
    }
   

    //Removing single occurence of LCS after concatenating both strings
     
    int ShortestCommonSuperseq_len = str1_len + str2_len - LCS_len;

    return ShortestCommonSuperseq_len;

}



int main(){
    string str1, str2;
    cin >> str1 >> str2;
    
    cout << ShortestCommonSuperseq(str1, str2);
      
    
  
    
	return 0;
}


/*

Sample Test Cases:
Input: 
ABCBDAB
BDCABA
Output:
9
Input:
opengenus
openragenues
Output:
12

Time Complexity: O(m * n)
Auxiliary Space: O(m * n)
where,
m = length of first string
n = length of second string

*/