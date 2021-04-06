/*
* Shortest Common Supersequence finds the shortest supersequence which consist of all the characters of both the string in the order specified.
* Supersequence have the same relative order but may or may not be continuous.
* Problem Statement :- Given two strings s1 and s2 and we have to find the shortest supersequence consisting of both s1 and and s2 and also print its length.
* Approach used :- As we see we have 2 options either we should include a character of a string or either not.Thus we have to make choices and hence we will be using dynamic programming approach as the same process is repeated again and again.
* First we will be considering a 2D array of size (n+1) * (m+1) where n and m are the size of first and second string respectively
  and we are taking an extra column and row to get the value of the substring of length 1 to n (by 0 we determine the base conditions)
* Any position at i,j i.e dp[i][j] will denote the length of longest common subsequence of prefix string of s1[0...i-1] and prefix
  string of s2[0...j-1]
* For the shortest superstring, the common character between s1 and s2 should be included once and as we know the sequence of common character is what we call as LCS i.e. LCS should be included once in the result and all other characters will be concatenated as it is to mmake a final superstring.
* Therefore, we conclude that Shortest Supersequence = n+m - LCS.

*/

#include <bits/stdc++.h>
using namespace std;

void ShortestSupersequence(string s1, string s2)
{
    //string for storing the shortest supersequence
    string s;
    //calculating length of string
    int n = s1.length();
    int m = s2.length();
    //constructing an 2D matrix of size n+1 and m+1
    int dp[n + 1][m + 1];
    //base condition
    //initializing the first row and first column as 0
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) { 
            
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }

    //finding LCS
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            //cheking if character matches or not
            //and if it matches then we add 1 to the solution
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            //else length should be reduced and maximum of first or second string should be taken
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Start from the bottom right corner and one by one
    // push characters in output string
    int i = n, j = m;
    while (i > 0 && j > 0) {
        // If current character in X and Y are same, then
        // current character is a part of shortest subsquence
        if (s1[i - 1] == s2[j - 1])
        //push current character into result
        {
            s.push_back(s1[i - 1]);
            //reduce values of i and j
            i--;
            j--;
        }
        //if current character in s1 and s2 are different
        else if (dp[i][j - 1] > dp[i - 1][j]) { 
            //push current character of s2 in result
            s.push_back(s2[j - 1]);
            //reduce value of j
            j--;
        }
        else { 
            //push character of s1 in result
            s.push_back(s1[i - 1]);
            //reduce value of i
            i--;
        }
    }
    //if s2 reaches to its end then push remaining character of s1 in result string
    while (i > 0) {
        s.push_back(s1[i - 1]);
        i--;
    }
    //if s1 reaches to its end then push remaining character of s2 in result string

    while (j > 0) {
        s.push_back(s2[j - 1]);
        j--;
    }
    //reverse the string
    reverse(s.begin(), s.end());
    cout << "Shortest Common Supersequence: ";
    for (int i = 0; i < s.length(); i++)
        cout << s[i];
    cout << endl;
    cout << "Length of Shortest Common SuperSequence: ";
    cout << s.length();
}

int main()
{
    // taking input from user
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;
    ShortestSupersequence(s1, s2);
}

/*
Sample Test cases :-

  Input 1:
  Enter string s1: aggtab
  Enter string s2: gxtxayb

  Output 1:
  Shortest Common Supersequence: agxgtxayb
        Length of Shortest Common SuperSequence: 9
  
  Input 2:
  Enter string s1: luck
  Enter string s2: cyk

  Output 2:
  Shortest Common Supersequence: lucyk
  Length of Shortest Common SuperSequence: 5
  
  Input 3:
  Enter string s1: acbcf
  Enter string s2: abcdaf

  Output 3:
  Shortest Common Supersequence: acdcdaf
  Length of Shortest Common SuperSequence: 7
  
  EXPLAINATION:-
  For s1 = "a c b c f" and s2 = "a b c d a f"
  and LCS matrix for this is :
       #   a   b   c   d   a   f  <=== [s2]
  #    0   0   0   0   0   0   0
  a    0   1   1   1   1   1   1
  c    0   1   1   2   2   2   2
  b    0   1   2   2   2   2   2
  c    0   1   2   3   3   3   3
  f    0   1   2   3   3   3   4
  /\
  ||
  [s1]
 
  Now within this matrix we know if both characters are matching we have
  to include it's value just once.
 
  I am starting from matrix[s1.length()][s2.length()] to print the Shortest
  Common SuperSequence.
 
  So in this matrix[f][f] = 4.
  if you notice [f] == [f] hence this value must have came from left diagonal
  include this f in our result and move to leftDiagonal.
 
  Now compare matrix[c][a] = 3. [c] != [a]
  So we have to move to the max of top or left value, that's the only 2 choice.
  and we have to put in the result.

   matrix[f][f] = 4   : Result[f]
   matrix[c][a] = 3   : Result[a f]
   matrix[c][d] = 3   : Result[d a f]
   matrix[c][c] = 3   : Result[c d a f]
   matrix[b][b] = 2   : Result[b c d a f]
   matrix[c][a] = 1   : Result[c b c d a f]
   matrix[a][a] = 1   : Result[a c b c d a f]  ===> this is our ShortestCommonSuperSequence.
 
         

  Time Complexity: O(m*n)
  Space Complexity: O(m*n)
  where m and n are lengths of string s1 and s2 respectively.

*/

