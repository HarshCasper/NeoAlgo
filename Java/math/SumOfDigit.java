/* Java Program to calculate the sum of digits of a number */

import java.util.Scanner;
public class SumOfDigit {

	/* Function to calculate the sum of digits */
	static int getSum(int n) {
		int temp = n;
		int sum = 0;

		while(temp > 0)
		{
			// Extracting the last digit of given number
			int lastDigit = temp % 10;
			// Adding the extracted last digit to sum
			sum += lastDigit;
			//Removing the last digit of the given number
			temp /= 10;	
		}
		  return sum;
	}
	
	public static void main(String[] args)
	{
		System.out.println("Enter the number for which you want to calculate the sum of digits:");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = getSum(n);
		System.out.println("Sum of the digits of "+n+" is "+x+".");
	}
}
/*
Sample Input and Output

Example 1:
Input:
Enter the number for which you want to calculate the sum of digits:
745
Output : Sum of the digits of 745 is 16.
Explanation : Sum of digits of the number 745 = (7+4+5) = 16

Example 2:
Input:
Enter the number for which you want to calculate the sum of digits:
8674
Output: Sum of the digits of 8674 is 25.
Explanation: Sum of digits of the number 8674 = (8+6+7+4) = 25

Space Complexity :O(1)
Time Complexity : O(logn)
*/
