//PROGRAM TO CHECK  whether the string is a Palindrome or not IN JAVA.

/*This is a program to check if the user entered string is palindrome or not . 
 * A palindrome is a string that is the same irrespective of wheather you read it in forward or backward direction.
 *  For example, "dad" is the same whether you read it in forward or reverse direction.*/

import java.util.Scanner;

public class String_palindrome {
	// function to check if the string is palindrome or not
	static void checkpalindrome(String string, String reverse_string) {

		// assigning the length of the string to integger type length variable.
		int length = string.length();

//reversing the string and storing it in the variable reverse_string. 
		for (int i = length - 1; i >= 0; i--) {
			reverse_string = reverse_string + string.charAt(i);
		}

		if (string.equals(reverse_string)) {

			System.out.println(string + " is a palindrome string");

		} else {
			System.out.println(string + " is not a palindrome string");
		}

	}

	public static void main(String[] args) {
		String string, reverse_string;

		Scanner sc = new Scanner(System.in);

		// taking input of the string to be checked
		System.out.println("Enter a string:");
		string = sc.nextLine();

		checkpalindrome(string, "");

	}
}

/*
 * OUTPUT: 1)when entered a non palindromic string
 * 
 * Enter a string: NEOALGO NEOALGO is not a palindrome string
 * 
 * 2)when entered a palindromic string
 * 
 * Enter a string: WEEW WEEW is a palindrome string
 * 
 * 3)when entered an empty space string
 * 
 * Enter a string:
 * 
 * is a palindrome string
 */
