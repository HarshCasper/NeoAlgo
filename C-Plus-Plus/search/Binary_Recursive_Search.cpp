/* Below code is an implementation of binary search in CPP using
recursive method. An array is taken as input from the user, followed
by the element the user wants to search in the array. The search function
is called. If the element is present in the array, then print the index
of the element in the array.
NOTE : For binary search to work, the input array must be SORTED*/

#include <bits/stdc++.h>
using namespace std;

// This function recursively searches for element in array
int search(int array[], int left, int right, int element) {

	// If left pointer exceeds the right pointer
	if(left > right) {
		return -1;
	}
	else {
		// Find the middle index
		int middle = left + (right - left) / 2;

		// If element is found return index
		if(array[middle] == element) {
			return middle;
		}
		/* If middle element is greater than the given element 
		to search, then, recursively search in the left half of
		the array.*/
		else if(array[middle] > element) {
			return search(array, left, middle - 1, element);
		}
		/* If middle element is less than the given element to
		search, then, recursively search in the right half of
		the array.*/
		else if(array[middle] < element) {
			return search(array, middle + 1, right, element);
		}
	}
	// If not found, return -1
	return -1;
}

int main() {

	// Take length of array as input from the user
	cout << "Enter the length of array: ";
	int length;
	cin >> length;

	// Take elements of array as input from the user
	cout << "Enter " << length << " elements followed by spaces: ";
	int array[length];
	for(int i = 0; i < length; i++) {
		cin >> array[i];
	}

	// Take element to search as input from the user
	cout << "Enter the element you want to search: ";
	int element;
	cin >> element;

	// Call search function to find the index
	int index = search(array, 0, length - 1, element);
	
	// New line
	cout << endl;

	// If index is -1, the element is not present
	if(index == -1) {
		cout << "The element " << element << " is not present in the given array." << endl;
	}
	// Else print index of element in the array
	else {
		cout << "The element " << element << " is present at index " << index << "." << endl;
	}
	return 0;
}

/* Sample I/O:

Enter the length of array: 10
Enter 10 elements followed by spaces: -11 -6 -3 2 4 6 8 10 12 20
Enter the element you want to search: 4

The element 4 is present at index 4.

Here, O is Thetha
Time Complexity: O(logn)
Space Complexity: O(n)
*/

