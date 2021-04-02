/** 
Radix sort is based on counting sort
This sort is used for non-negative elements
Assuming the range is fixed, as int capacity
is limited in any language, this sort takes

MAX_INT contains 10 decimal values
If range is not fixed, this sort takes O(kn) time
where k is #decimal places in the number
This works because of the nature of counting sort
Counting sort is a stable sort
**/

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define K 10
#define M 10

void counting_sort(int arr[], int  n, int p) {
	int element = pow(10, p), i;
	int divs = element / 10;
	int count[M];
	for(i = 0; i < M; i++)
		count[i] = 0;
	for(i = 0; i < n; i++)
		count[(arr[i] % element) / divs] ++;
	for(i = 1; i < M; i++)
		count[i] += count[i-1];
	int op[n];
	for(i = n-1; i >= 0; i--) {
	    op[count[(arr[i] % element) / divs] - 1] = arr[i];
	    count[(arr[i] % element) / divs] --;
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

/**
Input : 
8
175 45 75 90 802 24 2 66
Output :
2 24 45 66 75 90 175 802

Time complexity : O(n)
Space complexity : O(n)
**/
