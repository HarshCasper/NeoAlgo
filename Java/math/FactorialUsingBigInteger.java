// Calculating Factorial Using Big Integer
// https://www.hackerearth.com/practice/notes/factorial-of-large-number/
import java.math.BigInteger; 
import java.util.*; 
import java.io.*;
import java.lang.*;

class FactorialUsingBigInteger
{ 
	//Main Method
	public static void main(String args[]) throws IOException 
	{ 
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of N:\n");
		int N = sc.nextInt(); 
		
		BigInteger f = new BigInteger("1"); // Or BigInteger assigned to ONE 
		// Multiply f with number till N
		for (int i = 2; i <= N; i++) 
		{
			f = f.multiply(BigInteger.valueOf(i)); 
		}
		System.out.println("Factorial of given number is :"+f); 
	} 
} 
/*
Time Complexity:O(N)
Space Complexity:O(1)
Input:
Enter the value of N:
20
Output:
2432902008176640000
*/