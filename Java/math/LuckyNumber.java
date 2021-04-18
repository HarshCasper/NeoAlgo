/* This program prints lucky numbers till a given number n. Lucky
number - It is a set of numbers which is formed by eliminating
numbers based on their position based on the remaining set.*/

import java.util.*;
import java.lang.*;

public class LuckyNumber {

	// Function to print lucky numbers
	static void luckynumbers(int number) {

		// This array stores the lucky numbers
		int array[] = new int[number];

		// This array is used for eliminating
		int count[] = new int[number];

		// This array is used for terminating
		int check[] = new int[number];
		check[0] = 0;

		// Fill the array with numbers from 1 to n
		for(int i = 0; i < number; i++) {
			array[i] = i + 1;
			count[i] = i + 1;
		}

		// First case where every second number is eliminated
		int counter = 1;
		for(int i = counter; i < number; i += 2) {
			array[i] = -1;
			count[i] = -1;
		}

		// Updating the count array for further eliminations
		int cnt = 0;
		for(int i = 0; i < number; i++) {
			if(count[i] != -1) {
				count[i] = cnt + 1;
				cnt++;
			}
		}

		counter = 3;
		int same = 0;
		int value = 1;

		// For further forming the series of lucky numbers
		while(true) {
			same = 0;
			/* Updating the value of array of lucky number
			according to the count array.*/

			for(int i = 0; i < number; i++) {
				if(count[i] % counter == 0) {
					array[i] = -1;
				}
			}

			// Setting the count array to initial state
			for(int i = 0; i < number; i++) {
				count[i] = -1;
			}

			// Forming the count array for next set of eliminations
			cnt = 0;

			for(int i = 0; i < number; i++) {
				if(array[i] != -1) {
					count[i] = cnt + 1;
					cnt++;
				}
				else {
					// Keeping a track of number of -1's in array
					same += 1;
				}
			}

			// Filling number of -1's at each iteration
			check[value] = same;

			// Finding the next index to eliminate from
			for(int i = counter; i < number; i++) {
				if(array[i] != -1) {
					counter = array[i];
					break;
				}
			}

			// Terminating step
			if(check[value] == check[value - 1]) {
				/* If the number of -1's don't change in
				two successive operations, exit the loop.*/
				break;
			}

			value++;
		}

		// Print the lucky numbers
		for(int i = 0; i < number; i++) {
			if(array[i] != -1) {
				System.out.print(array[i] + " ");
			}
		}
	}

	public static void main(String[] args) {

		// Take number as input from the user
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int number = scan.nextInt();
		scan.close();

		// Call the function and print the lucky numbers
		System.out.print("\nLucky numbers till " + number + " are: ");
		luckynumbers(number);
		System.out.print("\n");
	}
}

/*
Sample I/O:

Enter a number: 100

Lucky numbers till 100 are: 1 3 7 9 13 15 21 25 31 33 37 43 49 51 63 67 69 73 75 79 87 93 99

Time complexity - O(k * n)

Space complexity - O(n)

here n is the input number and k is a constant.

*/

