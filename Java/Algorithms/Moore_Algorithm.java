/*The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of elements using linear time and constant space. */

import java.util.*;

public class MajorityVote {

	// naive approach
	public static void check(int arr[]) {
		int count = 0;
		for (int i = 0; i < arr.length - 1; i++) {
			count = 1;
			for (int j = i + 1; j < arr.length; j++) {
				// Counting the number by matching it with other numbers.
				if (arr[j] == arr[i]) {
					count++;
				}
			}
			if (count > arr.length / 2) {
				System.out.println("Number Occuring More than 'n/2'=" + arr[i]);
				System.exit(0);
			}
		}
		System.out.print("NO majority Elements ");
	}

	// using The Boyer–Moore majority vote algorithm
	public static int majority(int arr[], int arrsize) {

		int index = 0, count = 1;
		int i;
		// finding num to check majority
		for (i = 1; i < arrsize; i++) {
			if (arr[index] == arr[i])
				count++;
			else
				count--;
			if (count == 0) {
				index = i;
				count = 1;
			}
		}
		int num = arr[index];
		for (i = 0; i < arrsize; i++)
			if (arr[i] == num)
				count++;
		// checking for majority
		if (count > arrsize / 2)
			return num;
		else
			return -1;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter Number of elements (Eg. 6) : ");
		int element_count = input.nextInt();
		int[] arr = new int[element_count];
		System.out.println("Enter " + element_count + " Numbers:");
		for (int i = 0; i < element_count; i++) {
			// Giving values to array arr
			arr[i] = input.nextInt();
		}
		// Passing array to function
		check(arr);
		// using boyer-moore algorithm
		int result = majority(arr, element_count);
		if (result != -1)
			System.out.println("Majority of a sequence is " + result);

		else
			System.out.println("There is no majority \n");

	}

}

/*
 * Naive method: 
 * Enter Number of elements : 6 
 * Enter 6 Numbers: 5 5 5 5 4 2
 * Number Occuring More than 'n/2'=5 
 * Time Complexity : o(n^2) , Space Complexity : o(1).
 * 
 * The Boyer–Moore majority vote algorithm: 
 * Enter no of elements:5 
 * Enter elements: 1 1 1 1 2 
 * Majority of arr sequence is 1
 * 
 * Time complexity : O(n) Space complexity: O(1)
 */
