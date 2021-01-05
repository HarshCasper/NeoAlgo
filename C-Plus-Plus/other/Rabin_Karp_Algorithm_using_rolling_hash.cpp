/*
Rabin Karp Algorithm (using rolling hash)
=========================================
Given a text and a pattern, find all the occurences of the pattern in the text

Time Complexity: O(n) n=size of string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int p = 31;

// returns (a^b)%mod
int powr(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1LL) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		b = b >> 1;
		a %= mod;
	}
	return ans % mod;
}

// returns (a^-1)%mod
int inv(int a) {
	return powr(a, mod - 2) % mod;
}

// Assigns hash to a string
int polyHashString(string s) {
	int hash = 0;
	int coef = 1;
	for (int i = 0; i < s.size(); i++) {
		hash += (s[i] - 'a' + 1) * coef;
		coef *= p;
		coef %= mod;
		hash %= mod;
	}
	return hash % mod;
}

// Rabin Karp Algorithm for pattern matching
// returns indices of pattern in string s
void rabinKarp(string s, string pat) {

	int n = s.size();
	int m = pat.size();

	int patHash = polyHashString(pat);
	// Maintains hash of current window of size m
	int currHash = polyHashString(s.substr(0, m));

	bool patFound = 0;

	// If first window matches pattern
	if (currHash == patHash) {
		cout << 0 << endl;
		patFound = 1;
	}

	// coefficient for next character
	int coef = powr(p, m - 1);

	for (int i = 1; i <= (n - m); i++) {
		int newHash = currHash;

		// Subtract previous character
		newHash -= s[i - 1] - 'a' + 1;
		newHash += mod; newHash %= mod;

		// divide by prime
		newHash *= inv(p);
		newHash %= mod;

		// Add next char
		newHash += (s[i + m - 1] - 'a' + 1) * coef;
		newHash %= mod;

		// Check
		if (newHash == patHash) {
			cout << i << endl;
			patFound = 1;
		}

		currHash = newHash;
	}

	if (!patFound) {
		cout << "Not found";
	}
}

// Driver Code
signed main() {

	// Take input
	string s, pat;
	cin >> s >> pat;

	rabinKarp(s, pat);
}

/*
Input:
ilovecoding
love

Output:
1

Input:
aaaaaaaa
aaa

Output:
0
1
2
3
4
5
*/