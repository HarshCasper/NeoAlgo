/* Below code is an implementation of binary search in Java using
recursive method. An array is taken as input from the user, followed
by the element the user wants to search in the array. The search function
is called. If the element is present in the array, then print the index
of the element in the array.
NOTE : For binary search to work, the input array must be SORTED*/

import java.util.*;

public class BinarySearchRecursive {

	// This method recursively searches for element in array
	static int search(int array[], int left, int right, int element) {
		
		// If left pointer exceeds the right pointer
		if(left > right) {
			return -1;
		}
		
		else {
			// Find the middle index
			int middle = left + (right - left) / 2;
			// If element is found return index
			if(array[middle] == element) 
				return middle;
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
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);

		// Take length of array as input from the user
		System.out.print("Enter the length of array: ");
		int length = scan.nextInt();

		// Take elements of array as input from the user
		int[] array = new int[length];
		System.out.print("Enter " + length + " elements followed by spaces: ");
		for(int i = 0; i < length; i++) {
			array[i] = scan.nextInt();
		}

		// Take element to search as input from the user
		System.out.print("Enter the element you want to search: ");
		int element = scan.nextInt();

		// Call search function to find the index
		int index = search(array, 0, length - 1, element);
		
		// If index is -1, the element is not present
		if(index == -1) {
			System.out.println("\nThe element " + element + " is not present in the array.");
		}
		
		// Else print index of element in the array
		else {
			System.out.println("\nThe element " + element + " is present at " + index + " index in the array.");
		}
		scan.close();
	}
}

/* 
Sample I/O:

Enter the length of array: 6
Enter 6 elements followed by spaces: -2 -1 4 7 9 11
Enter the element you want to search: 11

The element 11 is present at 5 index in the array.

Here, O - Thetha
Time Complexity: O(logn)

Space Complexity: O(n)
*/

