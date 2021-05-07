/*
 This problem will be solved using dp.
 We will be given one strings and we have to print the
 Minimum number of deletion in a string to make it a palindrome.
*/

#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];

int minDeletion(string X, string Y, int m, int n) {
  // if length of any string is 0 then we cannot find common string
  for (int i = 0; i < m + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
    }
  }

  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      /* if letters of both string X and Y are equal 
      then we will decrease row i.e i and column i.e j both by 1 */
      if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      /* if letters of both string X and Y are not equal then first we will 
      decrease row i.e i by 1 and then column i.e j by 1 and then find maximum value b/w two */
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return m - dp[m][n];
}

int main() {
  cout<<"Enter string s1"<<endl;
  string s1;
  cin >> s1;
  string s2 = s1;
  reverse(s2.begin(), s2.end());
  int m = s1.length();
  int n = s2.length();
  cout <<"Minimum number of deletion in a string to make it a palindrome "<< minDeletion(s1, s2, m, n);
  return 0;
}
/*
Input - 
Enter string X
bbbab
Output -  
Minimum number of deletion in a string to make it a palindrome
4

Time Complexity - O(m*n)
Space Complexity - O(m*n)
*/
