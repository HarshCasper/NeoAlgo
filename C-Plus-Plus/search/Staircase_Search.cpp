/*
Search for key in row-wise and column-wise sorted matrix

Staircase Search Method:

In a sorted matrix, consider the top right corner. If we go down then the value increases
and if we go left then the value decreases.

Time Complexity: O(max(n, m))
Auxiliary Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void staircase_search(int** a, int n, int m, int key) {

	// int n = sizeof(a) / sizeof(a[0]);
	// int m = sizeof(a[0]) / sizeof(a[0][0]);

	// Start from top right corner
	int i = 0, j = m - 1;

	// While we donot find key
	while (a[i][j] != key) {

		// If curr value is less
		if (a[i][j] < key) {
			// that means array value must increase, for that we have to go down
			i++;
		}

		// If curr value is greater
		if (a[i][j] > key) {
			// that means array value must decrease, for that we have to go down
			j--;
		}
	}

	// If key is found, then print key
	if (a[i][j] == key) {
		cout << i << " " << j;
	} else {
		cout << "Key not found";
	}
}


int main() {

	// Take in input
	int n, m;
	cin >> n >> m;
	int key; cin >> key;

	// Declare 2D Matrix dynamically
	int** a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m] {0};
	}

	// Take matrix input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	staircase_search(a, n, m, key);

}

/*
Input:
4 4
16
1 4 8 10
2 5 9 15
6 16 18 20
11 17 19 23

Output:
2 1
*/
