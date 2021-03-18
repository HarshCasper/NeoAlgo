/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without 
using any extra space.
Input: array1[] = {1, 4, 9, 10, 17, 25};
       array2[] = {2, 3, 8, 12};
Output: array1[] = {1, 2, 3, 4, 8, 9}
        array2[] = {10, 12, 17, 25} 
 */


#include <bits/stdc++.h>
using namespace std;

void MergeArray(int array1[], int array2[], int n, int m)
{
	int maximum = 0;
	
	// Find maximum element of both array
	for (int i = 0; i < n; i++) {
		maximum = max (maximum, array1[i]);
	}
	for (int i = 0; i < m; i++) {
		maximum = max(maximum, array2[i]);
	}
	
	// increment one two avoid collision of 0 and maximum element of array in modulo operation
	maximum++;
	int i = 0, j = 0, k = 0;
	while (i < n && j < m && k < (n + m)) {
		
		// recover back original element to compare
		int e1 = array1[i] % maximum;
		int e2 = array2[j] % maximum;
		if (e1 <= e2) {
			
			// update element by adding multiplication with new number
			if (k < n)
				array1[k] += (e1 * maximum);
			else
				array2[k - n] += (e1 * maximum);
			i++;
			k++;
		}
		else {
			
			// update element by adding multiplication with new number
			if (k < n)
				array1[k] += (e2 * maximum);
			else
				array2[k - n] += (e2 * maximum);
			j++;
			k++;
		}
	}
	
	// process those elements which are left in array array1
	while (i < n) {
		int el = array1[i] % maximum;
		if (k < n)
			array1[k] += (el * maximum);
		else
			array2[k - n] += (el * maximum);
		i++;
		k++;
	}
	
	// process those elements which are left in array array2
	while (j < m) {
		int el = array2[j] % maximum;
		if (k < n)
			array2[k] += (el * maximum);
		else
			array2[k - n] += (el * maximum);
		j++;
		k++;
	}
	
	// Get elements by dividing with maximum element
	for (int i = 0; i < n; i++)
		array1[i] = array1[i] / maximum;

	// Get elements by dividing with maximum element
	for (int i = 0; i < m; i++)
		array2[i] = array2[i] / maximum;

	return;
}


int main()
{
	int array1[] = {1, 4, 9, 10, 17, 25};
    int array2[] = {2, 3, 8, 12};
	int n = sizeof(array1) / sizeof(int); // Length of array1
	int m = sizeof(array2) / sizeof(int); // length of array2

	// Function Call
	MergeArray(array1, array2, n, m);

	cout << "First array : ";
	for (int i = 0; i < n; i++)
		cout << array1[i] << " ";
	cout << endl;

	cout << "Second array : ";
	for (int i = 0; i < m; i++)
		cout << array2[i] << " ";
	cout << endl;

	return 0;
}

/*   Time Complexity: O(m+n)
     Space Complexity: O(1)
*/