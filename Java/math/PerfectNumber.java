/* Java program to check if a given number is perfect or not */

import java.util.Scanner;
public class PerfectNumber {
	
	/* Boolean Function to check if a given number is perfect */
	static boolean is_Perfect_Number(int num)
	{
		// For storing sum of all proper divisors
		int sum=1;
		// To check if the numbers are proper divisors
		for(int i=2; i*i<=num; i++)
		{
			if(num%i == 0)
			{
				if(i*i == num)
					sum+=i;
				else
					sum+=i+num/i;
			}
		}
		if(sum == num && num!=1)
			return true;
		else
			return false;
	}
	public static void main(String[] args)
	{
		System.out.println("Enter the number to check if it is a Perfect Number:");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(is_Perfect_Number(n))
			System.out.println(n + " is a Perfect Number.");
		else
			System.out.println(n + " is not a Perfect Number.");	
	}
	
}
/*Sample Input and Output

Example 1:
Input:
Enter the number to check if it is a Perfect Number:
28
Output:
28 is not a Perfect Number.
Explanation:
Proper Divisors of 28 are 1, 2, 4, 7 and 14.
Sum = 1+2+4+7+14 = 28 = 28
⇒ 28 is a perfect number.

Example 2:
Input:
Enter the number to check if it is a Perfect Number:
15
Output:
15 is not a Perfect Number.
Explanation:
Proper Divisors of 15 are 1,3 and 5.
Sum = 1+3+5 = 9 ≠ 15
⇒ 15 is not a perfect number.

Space Complexity :O(1)
Time Complexity : O(√n)
*/





	
		

	


