/*
- Identical_Words :
    We will give 3 Strings as input and we will check if it is possible to make
    second_string and third_string equivalent to first_string by re-arranging characters of
    second_string and third_string any number of times

- Example :
     Input : words ordws rsdow
    Output : They are Identical

- Approach :
  1. After taking the 3-input Strings we will check if their lengths are equal or not, if not then
     they are not equivalent

  2. We will use string_sort method to sort the string by converting it to character array and then
     using Arrays.sort() method

  3. After all 3 Strings sorted we will check if they are equal or not, if equal then "They are Identical"
     and if not then "They are not Identical"
*/

import java.util.Arrays;
import java.util.Scanner;

public class Identical_Words {
	//string_sort method
	public static String string_sort(String s) {
		//converting string to char array
		char char_Array[] = s.toCharArray();
		//sorting char array
		Arrays.sort(char_Array);
		//converting char array back to String
		String sorted_string = new String(char_Array);
		return sorted_string;
	}
	//main method
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		//Enter 3 Strings as input
		System.out.print("Enter Strings : ");
		String first_string = sc.next();
		String second_string = sc.next();
		String third_string = sc.next();

		// Checking if length of all Strings are equal or not
		if(first_string.length() == second_string.length() && first_string.length() == third_string.length()) {

			String s1 = Identical_Words.string_sort(first_string);
			String s2 = Identical_Words.string_sort(second_string);
			String s3 = Identical_Words.string_sort(third_string);
			//Checking if Strings are equal or not
			if(s1.equals(s2) && s1.equals(s3)) {
				//if this condition satisfies then print "They are Identical"
				System.out.println("They are Identical");
			}else {
				//else print "They are not Identical"
				System.out.println("They are not Identical");
			}
		}else {
			System.out.println("They are not Identical");
		}
	}
}
/*
- Test Cases :
      Input : Enter Strings : identical inticalde lacitdeni
     Output : They are Identical

- Complexity Analysis :
  * Time Complexity : O(nlog(n))
        As we are using Arrays.sort()

  * Space Complexity : O(n)
        Auxiliary space : O(n)  +  input space : O(1)
*/
  
