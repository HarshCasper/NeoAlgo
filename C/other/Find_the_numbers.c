//Program to find the Unique numbers in an array out of which two numbers occur exactly once and are distinct.
// You need to find the other two numbers and print them in ascending order.

#include <stdio.h> 

void findUniquePair(int arr[], int size) 
{ 
	// XOR each element and get XOR of two unique 
	// elements(ans) 
	int XOR = arr[0]; 
	for (int i = 1; i < size; i++) 
		XOR = XOR ^ arr[i]; 
	
	// Now XOR has XOR of two missing elements. Any set 
	// bit in it must be set in one missing and unset in 
	// other missing number 

	// Get a set bit of XOR (We get the rightmost set bit) 
	int set_bit_no = XOR & ~(XOR-1); 

	// Now divide elements in two sets by comparing rightmost 
	// set bit of XOR with bit at same position in each element. 
	int x = 0, y = 0; // Initialize missing numbers 
	for (int i = 0; i < size; i++) 
	{ 
		if (arr[i] & set_bit_no) 
			x = x ^ arr[i]; /*XOR of first set in arr[] */
		else
			y = y ^ arr[i]; /*XOR of second set in arr[] */
	} 
	if(x>y)
		printf("Distinct Numbers are %d and  %d", y, x);
	else
		printf("Distinct Numbers are %d and %d", x, y);
	
} 

// Driver code 
int main() 
{ 
	
	int size;
	printf("Enter Size:");
	scanf("%d", &size);
	int arr[size];
	printf("Enter elements:\n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	findUniquePair(arr, size); 
	return 0; 
} 
/*
Sample I/O:
Input:
	Enter Size:6
	Enter elements:
	1 2 3 2 1 4

Output:
	Distinct Numbers are 3 and 4

Time Complexity: O(size)
Space Complexity: O(1)
*/