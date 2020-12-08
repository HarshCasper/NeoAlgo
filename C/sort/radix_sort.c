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

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define K 10
#define M 10

void counting_sort(int arr[], int  n, int p) {
	int ele = pow(10, p), i;
	int divs = ele / 10;
	int count[M];
	for(i = 0; i < M; i++)
		count[i] = 0;
	for(i = 0; i < n; i++)
		count[(arr[i] % ele) / divs] ++;
	for(i = 1; i < M; i++)
		count[i] += count[i-1];
	int op[n];
	for(i = n-1; i >= 0; i--) {
	    op[count[(arr[i] % ele) / divs] - 1] = arr[i];
	    count[(arr[i] % ele) / divs] --;
	}
	// copying the array back
	for(i = 0; i < n; i++)
		arr[i] = op[i];
}

void radix_sort(int arr[], int n) {
	int i;
	// apply counting sort for all decimal places
	for(i = 1; i <= K; i++)
		counting_sort(arr, n, i);
}

int main() {
	int n, i;
	scanf(" %d", &n);
	int arr[n];
	// taking ip
	for(i = 0; i < n; i++)
		scanf(" %d", &arr[i]);
	// perform the sort
	radix_sort(arr, n);
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}