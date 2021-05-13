/**
The program will find out the sum of Nth row
in the Pascal's Triangle using the concept of Bitmasking.
	1         -> 1st -> 1
	1 1       -> 2nd -> 2
	1 2 1     -> 3rd -> 4
	1 3 3 1   -> 4th -> 8
	1 4 6 4 1 -> 5th -> 16
	...       -> nst -> 2^(n-1)		
total sum = 2^0 + 2^1 + 2^2 + 2^3 + 2^4 + .. + upto nth row i.e 2^(n-1) = 2^n - 1;
*/

import java.util.Scanner;

public class PascalNthRowSum {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
              System.out.print ("Enter value of N - ");
		int n=sc.nextInt();
		
		int row= 1<<(n-1);
		System.out.println("Nth row sum - "+row);
		
		int sum=1<<n;
		sum=sum-1;
		System.out.println("Sum of entire Pascal Triangle upto Nth row - "+sum);
	}
}

/**
Time Complexity : O(1)
Space Complexity : O(1)

Input :

Enter value of N - 5

Output :

Nth row sum - 16
Sum of entire Pascal Triangle upto Nth row - 31

*/

