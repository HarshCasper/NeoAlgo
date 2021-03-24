import java.util.Scanner;

public class Anagram {
	public static void main(String[] args) {
		/// This code is for Anagram algorithm in Java
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter a string");
		String string1 = scan.nextLine(); // takes a input string
		System.out.println("Enter another string");
		String string2 = scan.nextLine(); // takes another input string
		boolean isAnagram = true;
		int space[] = new int[256]; // created space in memory to store the numerical value of each character
		for (char c : string1.toCharArray()) { // initialized loop
			int index = (int) c; // to type caste character value into integer value
			space[index]++;
		} // to store the count of repeat of such characters
		for (char c : string2.toCharArray()) {
			int index = (int) c;
			space[index]--;
		} /*
			 * to subtract count by 1 if same character found, if two strings are anagram
			 * then from this approach space should be null
			 */
		for (int i = 0; i < 256; i++) {
			if (space[i] != 0) { // check for the each space to be null or not
				isAnagram = false;
				break;
			}
		}
		if (isAnagram) {
			System.out.println("anagram");
		} else {
			System.out.println("not anagram");
		}
	}
}

/*
 * This algorithm is used to find whether two strings are anagram or not This is
 * an optimized way for an anagram algorithm.
 *
 * Sample Testcase-1:
 *
 * Enter a string  
 * listen   //input1
 * Enter another string
 * silent   //input2
 * anagram  //output
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * Sample Testcase-2:
 *
 * Enter a string algorithm
 * chandar  //input1
 * Enter another string 
 * chamber  //input2
 * not anagram //output
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 *
 *
 */