
#include <bits/stdc++.h> 
using namespace std;  

/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n) 
{ 
	if (d == 0) 
		return; 
	// in case the rotating factor is 
	// greater than array length 
	d = d % n; 

	reverse(arr, 0, d - 1); 
	reverse(arr, d, n - 1); 
	reverse(arr, 0, n - 1); 
} 

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int d = 2; 

	// Function calling 
	leftRotate(arr, d, n); 
	printArray(arr, n); 

	return 0; 
}
