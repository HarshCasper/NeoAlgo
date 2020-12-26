// unique BSTs using DP
// Given n, how many structurally unique BST's that store values 1 ... n?

#include <bits/stdc++.h>
using namespace std;

int uniqueBST(int n) {
	vector<int> count(n + 1);
	// for each 'i' number of nodes
	for (int i = 1; i <= n ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			// No. of trees if j is a root
			count[i] += max(count[j], 1) * max(count[i - j - 1], 1);
		}
	}
	return count[n];
}

int main() {
	int n;
	cout << "Enter value:";
	cin >> n;
	cout << "Number of Unique BSTs " << uniqueBST(n) << endl;

	return 0;
}

/*
output:
Enter value:3
Number of Unique BSTs 5
Time complexity : O(n)
*/
