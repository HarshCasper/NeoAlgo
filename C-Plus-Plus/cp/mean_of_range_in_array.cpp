
#include <bits/stdc++.h> 
#define MAX 1000005 
using namespace std; 

int prefixSum[MAX]; 

// To calculate prefixSum of array 
void calculatePrefixSum(int arr[], int n) 
{ 
	// Calculate prefix sum of array 
	prefixSum[0] = arr[0]; 
	for (int i = 1; i < n; i++) 
		prefixSum[i] = prefixSum[i - 1] + arr[i]; 
} 

// To return floor of mean 
// in range l to r 
int findMean(int l, int r) 
{ 
	if (l == 0) 
	return floor(prefixSum[r]/(r+1)); 

	// Sum of elements in range l to 
	// r is prefixSum[r] - prefixSum[l-1] 
	// Number of elements in range 
	// l to r is r - l + 1 
	return floor((prefixSum[r] - 
		prefixSum[l - 1]) / (r - l + 1)); 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	calculatePrefixSum(arr, n); 
	cout << findMean(0, 2) << endl; 
	cout << findMean(1, 3) << endl; 
	cout << findMean(0, 4) << endl; 
	return 0; 
} 
