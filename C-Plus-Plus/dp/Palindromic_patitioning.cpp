/*
   Question:- Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
   We have to find the mnimum cuts which will convert our string into all palindromes.
*/

#include <bits/stdc++.h>

using namespace std;

int t[1001][1001];

bool isPallindrome(string str, int i, int j) {
  for (int k = i; k <= j; k++) {
    if (str[k] != str[j]) {
      return false;
    }
    j--;
  }

  return true;
}
int solve(string str, int i, int j) {
  // if string is empty or of only one element then its already a palindrome.
  if (i >= j) {
    return 0;
  }
  if (isPallindrome(str, i, j) == true) {
    return 0;
  }
  // will check if we have already processed that particular part answer.
  if (t[i][j] != -1) {
    return t[i][j];
  }

  int ans = INT_MAX, left, right;
  for (int k = i; k < j; k++) {
    // will check if we already have the answer for the left part in our matrix.
    if (t[i][k] != -1) {
      left = t[i][k];
    }
    // otherwise find the ans and store in matrix
    else {
      left = solve(str, i, k);
      t[i][j] = left;
    }
    // will check if we already have the answer for the right part in our matrix.
    if (t[k + 1][j] != -1) {
      right = t[k + 1][j];
    }
    // otherwise find the ans and store in matrix
    else {
      right = solve(str, k + 1, j);
      t[i][j] = right;
    }
    int temp = left + right + 1;
    ans = min(ans, temp);
  }

  return t[i][j] = ans;
}
int palindromicPartition(string str) {
  int i = 0, j = str.length() - 1;
  memset(t, -1, sizeof(t));

  return solve(str, i, j);
}

int main() {
  string s;
  cin >> s;
  cout << palindromicPartition(s);
}
/*
Time Complexity: O(n*n)
Space Complexity: O(n*n)
Input: str = "ababbbabbababa"
Output: 3
*/
