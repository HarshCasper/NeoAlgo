/* Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). 
Then doing some arithmetic to calculate the position of each object in the output sequence.

For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
*/
# Following is implementation of counting sort. 

// C Program for counting sort 
#include <stdio.h> 
#include <string.h> 
#define RANGE 255 

// The main function that sort the given string arr[] in 
// alphabatical order 
void countSort(char arr[]) 
{ 
	// The output character array that will have sorted arr 
	char output[strlen(arr)]; 

	// Create a count array to store count of inidividul 
	// characters and initialize count array as 0 
	int count[RANGE + 1], i; 
	memset(count, 0, sizeof(count)); 

	// Store count of each character 
	for (i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i - 1]; 

	// Build the output character array 
	for (i = 0; arr[i]; ++i) { 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	} 

	/* 
	For Stable algorithm 
	for (i = sizeof(arr)-1; i>=0; --i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 
	
	For Logic : See implementation 
	*/

	// Copy the output array to arr, so that arr now 
	// contains sorted characters 
	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
} 

// Driver program to test above function 
int main() 
{ 
	char arr[] = "geeksforgeeks"; //"applepp"; 

	countSort(arr); 

	printf("Sorted character array is %sn", arr); 
	return 0; 
} 

/* Output: 

` Sorted character array is eeeefggkkorss `

*/

*/ Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input. 
Auxiliary Space: O(n+k)
*/

