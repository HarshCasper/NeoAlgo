//Program to find the Unique numbers in an array out of which two numbers occur exactly once and are distinct.
// You need to find the other two numbers and print them in ascending order.

#include <stdio.h> 

void findUniquePair(int arr[], int size) 
{ 
	// XOR each element and get XOR of two unique elements(ans) 
	int XOR = arr[0]; 
	for (int i = 1; i < size; i++) 
		XOR = XOR ^ arr[i]; 

	// Get a set bit of XOR (We get the rightmost set bit) 
	int set_bit = XOR & ~(XOR-1); 

	// Now divide elements in two sets by comparing rightmost 
	int x = 0, y = 0; // Initialize missing numbers 
	for (int i = 0; i < size; i++) 
	{ 
		if (arr[i] & set_bit)
			x = x ^ arr[i]; //first unique number in arr[]
		else
			y = y ^ arr[i]; //second unique number in arr[]
	} 
	if(x>y)
		printf("Distinct Numbers are %d and  %d", y, x);
	else
		printf("Distinct Numbers are %d and %d", x, y);
	
} 

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