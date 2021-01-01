/*
Rabin Karp Algorithm (using prefix sum)
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

	int pat_hash = polyHashString(pat);
	int n = s.size(), m = pat.size();

	int pref[n] = {0};

	for (int i = 0; i < n; i++) {
		pref[i] = (s[i] - 'a' + 1) * powr(p, i);
		pref[i] %= mod;
	}

	for (int i = 1; i < n; i++) {
		pref[i] += pref[i - 1];
		pref[i] %= mod;
	}

	bool patFound = 0;
	for (int i = 0; i <= (n - m); i++) {
		// substring from s[l.......r]
		// r = i+m - 1
		int l = i;
		int r = i + m - 1;

		int new_hash = pref[r];

		if (i - 1 >= 0) {
			new_hash -= pref[l - 1];
		}

		new_hash += mod; new_hash %= mod;

		if (new_hash == (pat_hash * powr(p, l)) % mod) {
			cout << i << endl;
			patFound = 1;
		}
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
