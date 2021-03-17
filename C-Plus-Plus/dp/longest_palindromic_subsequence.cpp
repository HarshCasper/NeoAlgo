
/*
    Longest Palindromic Subsequence
        -> Find the longest subsequence of a string which is an palindrome

        -> A subsequence is a sequence that can be derived from another sequence
        by deleting some or no elements without changing the order of the remaining elements.

    Example
        s = "bbbab"
        ans = 4, "bbbb" is the longest palindromic subsequence

        s = "agbdba"
        ans = 5, "abdba" is the longest palindromic subsequence

    Approach
        -> calculate the ans for all possible length using dynamic programming
        -> for length 1 a,g,b,d,b,a ans is :1
        -> for length 2 ag,gb,bd,db,ba similarly for all other lenghts

        if let's say "agbdba", s[i] = s[j] i.e s[0] == s[5]
        then ans = 2 + lps(i+1,j-1) i.e check the ans for "gbdb"
        why 2 ??
        because let's say for "agbdba" first and last are same "a|gbdb|a"
        the length should be adding those charcters plus LPS of "gbdb"

        for "gbdb" s[i] != s[j] i.e s[0] != s[3]
        ans = max(lps(i+1,j),lps(i,j-1)) i.e max lps for "gbd" and "bdb"


*/
#include <bits/stdc++.h>
using namespace std;

int lps(string s) {
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	// if there is only 1 charcter it's an palindrome
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	// calculate ans for string of length '2' or more ex ab,cd,abc,abcd
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {

			int j = i + len - 1;

			// if start and end charcters are same
			if (s[i] == s[j]) {
				dp[i][j] = 2 + dp[i + 1][j - 1];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}

		}
	}

	// i.e the whole string ex: abba, dp[0][3] = 4
	return dp[0][n - 1];
}

int main() {

	// Input The String
	string s;
	cout << "Enter The String " << '\n';
	cin >> s;

	cout << "Length of Longest Palindrmoic Subsequence for " << s << " is: " << lps(s) << '\n';

	return 0;
}


	/*

		Time Complexity: O(N^2)
		Space Complexity O(N^2)

	    Sample Input:
	    s = "vavbhhb"
		Output: 4
	    Explanation:
	    -> there are two palindromic subsequences vav, bhhb
	    -> longest is bhhb therefore the ans is 4
	*/

