/*                                    Length Of Longest Common Substring

Given two strings.The task is to find the length of the longest common substring.
A Substring is a sequence that appears in the same relative order within Orignal string, and is contiguous.

*/

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string str1, string str2) {
   int m = str1.length();
   int n = str2.length();
   int dp[m + 1][n + 1];

   // This will handle base condition when any or both strings are empty
   memset(dp, 0, sizeof(dp));

   for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        /*if character are same then add 1 to the result and 
        remove the last character from both the strings 
        and check the result for the smaller string*/
         if (str1[i - 1] == str2[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        // when both character are not same 
         else
            dp[i][j] = 0;
      }
   }
   //traverse the matrix and find maximum length
   int maxElement = INT_MIN;
   for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
         maxElement = max(maxElement, dp[i][j]);
      }
   }

   return maxElement;
}

int main() {
   string str1, str2;

   cout << "Enter two strings :" << "\n";
   cin >> str1 >> str2;

   int length = longestCommonSubstring(str1, str2);

   cout << "Length Of Longest Common Substring is : " << length;

   return 0;
}

/*
SAMPLE I/0:
Enter two strings :
ABCDEKS
ZYABCDPRQ
Length Of Longest Common Substring is : 4

ALGORITHM ANALYSIS:
Time complexity : O(m*n)
Space complexity: O(m*n)
*/