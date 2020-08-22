//euler function count number of integers between 1 to n which are coprime(greatest common divisor equals 1) to n.
//therefore we find GCD of given number and n.

import java.io.*;
import java.util.Scanner;

class EulerFunction{
	
	//here Function to check GCD of two numbers
	static int gcd(int a, int b) 
    	{ 
        	if (a == 0) 
            		return b; 
        	return gcd(b % a, a); 
    	} 
	
	//Function to solve Euler Totient Function example
	static int eulerfun(int n){
		int ans = 1;
		for(int i=2;i<n;i++){
			if(gcd(i,n) == 1)
			{
				ans++;
			}
		}
		return ans;
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Number of digits: ");
		int n = sc.nextInt();
		
		for(int i = 1;i<=n;i++)
		{
			System.out.println("Euler Function of "+ i +" : " + eulerfun(i));
		}
	}
}