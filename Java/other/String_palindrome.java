import java.util.Scanner;

public class String_palindrome{
//PROGRAM TO CHECK  whether the string is a Palindrome or not IN JAVA.
	public static void main(String[] args) {

		//declaring an empty reverse_string variable and a string variable to be taken as input
		String string, reverse_string = "";

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter a string:");
		string = sc.nextLine();//taking input of the string to be checked

		int length = string.length();//assigning the length of the string to integger type  variable length

		for (int i = length - 1; i >= 0; i--) {
			reverse_string = reverse_string + string.charAt(i);
		}//reversing the string and storing it in the reverse_string variable

		if (string.equals(reverse_string)) {

			System.out.println(string + " is a palindrome string");

		} else {
			System.out.println(string + " is not a palindrome string");
		}

	}
}

/*OUTPUT:
1)when entered a non palindromic string

Enter a string:
NEOALGO
NEOALGO is not a palindrome string

2)when entered a palindromic string

Enter a string:
WEEW
WEEW is a palindrome string

3)when entered an empty space string

Enter a string:

 is a palindrome string
 */
