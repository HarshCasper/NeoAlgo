/*
	This is a java program to add to binary strings
	and return the result in binary string itself
*/
import java.util.Scanner;

public class AddBinaryStrings{
	private static Scanner inp = new Scanner(System.in);
	public static void main(String[] args) {
		System.out.print("Enter String a : ");
		String a = inp.nextLine();
		System.out.print("\nEnter String b : ");
		String b = inp.nextLine();
		System.out.println("\n" + a +" + "+ b + " = " + addBinary(a,b));
	}
	//This is the function responsible for adding the two binary strings
	//passed as an argument in this function
	public static String addBinary(String a, String b){
		//creating a variable to store carry generated on adding
		int carry = 0;
		//Using StringBuilder will make our program's execution faster
		StringBuilder ans = new StringBuilder();
		int n = a.length();
		int m = b.length();
		//we will start from the end of the strings
		int i = n-1;
		int j = m-1;

		while(i >= 0 || j >= 0){
			int sum = carry;
			//if our string b still has some characters then we should add it in
			if(j >= 0){	
				//adding the decimal values into sum
				//by subtracting the ascii value of 0 from characters of string 
				sum += (b.charAt(j)-'0');
				j--;
			}
			//similar steps are followed for the string a
			if(i >= 0){
				sum += (a.charAt(i)-'0');
				i--;
			}
			// we store the quotient of the sum generated into carry
			carry = sum/2;
			// and the remainder is stored in the sum itself
			sum = sum%2;
			// finally we append it into our ans StringBuilder
			ans.append(sum);
		}
		//there might be a case where the carry has a value > 0
		// so to avoid it we append our carry if it is > 0
		if(carry > 0){
			ans.append(carry);
		}
		// we neeed to reverse our string builder 
		//as we strated appending and adding from the end
		ans = ans.reverse();

		//finally we return the stringBuilder as a string
		return ans.toString();
	}
}

/**
 * Sample input/output :
 * 
 *	Enter String a : 101010
 *	Enter String b : 1101001
 *
 *	101010 + 1101001 = 10010011
 *
 *	Time complexity : O(n)
 *	Space Complexity: O(n)
*/