/* Below program checks if a number is a mystery number. 
Mystery number - A number that can be represented by sum
of two numbers, such that the two numbers are reverse of
each other.*/

import java.util.*;
import java.lang.*;

public class MysteryNumber {

	/* This function takes a number as a input and
	returns	a number with the digits reversed*/
	static int reverse(int number) {

		int rev = 0;
		while(number != 0) {
			rev *= 10;
			rev += number % 10;
			number = number / 10;
		}
		return rev;
	}

	// This function checks if the number is a mystery number
	static int isMystery(int number) {

		// We iterate till the middle of the number
		for(int i = 1; i <= number / 2; i++) {

			// Find reverse of current iteration value
			int rev = reverse(i);
			// Check the sum of number with its reverse
			if(i + rev == number) {
				// If its is equal to the given number we return and print
				System.out.println("\nThe two digits are: " + i + " " + rev);
				return 1;
			}
		}
		// Else return -1
		return -1;
	}

	public static void main(String args[]) {

		// Taking number as input from the user
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the number: ");
		int number = scan.nextInt();
		scan.close();

		// Calling the mystery function
		int result = isMystery(number);

		// If the result is 1, the number is a mystery number
		if(result == 1) {
			System.out.println("The given number " + number + " is a Mystery number.");
		}

		// Else it is not a mystery number
		else {
			System.out.println("\nThe given number " + number + " is not a Mystery number.");
		}
	}
}

/*
Sample I/O:

1)
Enter the number: 343

The two digits are: 122 221
The given number 343 is a Mystery number.

2)
Enter the number: 3214

The given number 3214 is not a Mystery number.

*/
