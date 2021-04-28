/**
Program to find out the set bits in the
binary representation of a number using
the & operator by the concept of Bitmasking.
 */

import java.util.Scanner;

public class SetBitsBitmasking {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		System.out.print ("Enter a no - ");
		int n=sc.nextInt();
		
		int cnt=0, temp=n;
		while (temp!=0) {
			cnt++;
			temp=temp&(temp-1);
		}
		
		System.out.println("No. of set bits - "+cnt+"\nBinary representation - "+Integer.toBinaryString(n));
	}
}

/**
Time Complexity : O(log2(n+1))
Space Complexity : O(n)

Input :

Enter a no - 5

Output :

No. of set bits - 2
Binary representation - 101

*/

