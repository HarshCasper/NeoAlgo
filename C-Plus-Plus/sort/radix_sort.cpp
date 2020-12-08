// Radix sort is based on counting sort
// This sort is used for non-negative elements
// Assuming the range is fixed, as int capacity
// is limited in any language, this sort takes
// Time complexity : O(n)
// Space complexity : O(n)
// MAX_INT contains 10 decimal values
// If range is not fixed, this sort takes O(kn) time
// where k is #decimal places in the number
// This works bcz of the nature of counting sort
// Counting sort is a stable sort

#include <bits/stdc++.h>
using namespace std;

#define K 10
#define M 10

void counting_sort(int arr[], int  n, int p) {
	int ele = pow(10, p);
	int divs = ele / 10;
	int count[M];
	for(int i = 0; i < M; i++)
		count[i] = 0;
	for(int i = 0; i < n; i++)
		count[(arr[i] % ele) / divs] ++;
	for(int i = 1; i < M; i++)
		count[i] += count[i-1];
	int op[n];
	for(int i = n-1; i >= 0; i--) {
	    op[count[(arr[i] % ele) / divs] - 1] = arr[i];
	    count[(arr[i] % ele) / divs] --;
	}
	// copying the array back
	for(int i = 0; i < n; i++)
		arr[i] = op[i];
}

void radix_sort(int arr[], int n) {
	// apply counting sort for all decimal places
	for(int i = 1; i <= K; i++)
		counting_sort(arr, n, i);
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	// taking ip
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	// perform the sort
	radix_sort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}