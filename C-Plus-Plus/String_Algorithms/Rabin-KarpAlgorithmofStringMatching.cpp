#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

int p1 = 27, p2 = 33;
int mod = (int)1e9 + 7;

int calcVal(char a) {
	int x = 0;
    if (a >= 'a' and a <= 'z') x = a - 'a' + 1;
    else if (a >= 'A' and a <= 'Z') x = a - 'A' + 27;
    else x = a - '0' + 53;
    return x;
}

auto computeHash(string &s) {
	array<int, 2> hs{0, 0};
	for (auto &i: s) {
		int x = calcVal(i);
		hs[0] = (((hs[0] * p1) % mod) + x) % mod;
		hs[1] = (((hs[1] * p2) % mod) + x) % mod;
	}
	return hs;
}

void solve() {
	string s, pat;
	cin >> s >> pat;
	int n = s.length();
	int m = pat.length();
	if (m > n) {
		cout << "Not Found\n\n";
		return;
	}
	vector<int> pw1(n), pw2(n);
	pw1[0] = 1;
	pw2[0] = 1;
	for (int i = 1; i < n; i++) pw1[i] = (pw1[i - 1] * p1) % mod, pw2[i] = (pw2[i - 1] * p2) % mod; 
	auto res = computeHash(pat);
	array<int, 2> hs{0, 0};
	auto hs2 = hs;
	for (int i = 0; i < m; i++) {
		int x = calcVal(s[i]);
		hs[0] = (((hs[0] * p1) % mod) + x) % mod;
		hs[1] = (((hs[1] * p2) % mod) + x) % mod;
	}

	for (int i = 1; i <= m; i++) {
		int x = calcVal(s[i]);
		hs2[0] = (((hs2[0] * p1) % mod) + x) % mod;
		hs2[1] = (((hs2[1] * p2) % mod) + x) % mod;
	}
	vector<int> flag;
	if (hs == res) flag.push_back(0);
	for (int i = m; i < n; i++) {
		int x = calcVal(s[i]), y = calcVal(s[i - m]);
		hs[0] = hs[0] - (y * pw1[m - 1]) % mod;
		hs[1] = hs[1] - (y * pw2[m - 1]) % mod;
		if (hs[0] < 0) hs[0] += mod;
		if (hs[1] < 0) hs[1] += mod;
		hs[0] = (((hs[0] * p1) % mod) + x) % mod;
		hs[1] = (((hs[1] * p2) % mod) + x) % mod;
		if (hs == res) flag.push_back(i - m + 1);
	}
	int len = flag.size();
	if (len) {
		cout << len << " Matches found at the following indices : \n";
		for (auto &i : flag) cout << i + 1 << " ";
		cout << "\n";
	} 
	else cout << "Not Found\n";
	cout << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}
