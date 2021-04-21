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

	public static String addBinary(String a, String b){
		int carry = 0;	//creating a variable to store carry generated on adding
		StringBuilder ans = new StringBuilder();
		int n = a.length();
		int m = b.length();
		int i = n-1;	//we will start from the end of the strings
		int j = m-1;	//we will start from the end of the strings

		while(i >= 0 || j >= 0){
			int sum = carry;
			if(j >= 0){	//if our string b still has some characters then we should add it in
				sum += (b.charAt(j)-'0');	//adding the decimal values into sum
											//by subtracting the ascii value of 0 from characters of string 
				j--;
			}
			if(i >= 0){		//similar steps are followed for the string a
				sum += (a.charAt(i)-'0');
				i--;
			}
			carry = sum/2;	// we store the quotient of the sum generated into carry
			sum = sum%2;	// and the remainder is stored in the sum itself
			ans.append(sum);	// finally we append it into our ans StringBuilder
		}
		if(carry > 0){	//there might be a case where the carry has a value > 0
						// so to avoid it we append our carry if it is > 0
			ans.append(carry);
		}

		ans = ans.reverse();	// we neeed to reverse our string builder 
								//as we strated appending and adding from the end

		return ans.toString();	//finally we return the stringBuilder as a string
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