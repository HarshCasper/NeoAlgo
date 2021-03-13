/* Java Program to calculate the sum of digits of a number */

import java.util.Scanner;

public class SumOfDigit {
	
	/* Function to calculate the sum of digits */
	
	static int getSum(int n) {
		
		int sum = 0;
		
		while(n > 0)
		{
			// Extracting the last digit of given number
			int lastDigit = n % 10;
			
			// Adding the extracted last digit to sum
			sum += lastDigit;
			
			//Removing the last digit of the given number
			n /= 10;
			
		}
		
		return sum;
	}
	
	public static void main(String[] args)
	{
		System.out.println("Enter the number for which you want to calculate the sum of digits:");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = getSum(n);
		System.out.println(x);
		
	}
}


/*
 
Sample Input and Output

Example 1:

Input:
Enter the number for which you want to calculate the sum of digits:
745
Output : 16
Explanation : Sum of digits of the number 745 = (7+4+5) = 16


Example 2:

Input:
Enter the number for which you want to calculate the sum of digits:
8674
Output: 25
Explanation: Sum of digits of the number 8674 = (8+6+7+4) = 25

*/
