// Java program to calculate 
// Euler's Totient Function 
import java.io.*; 
import java.util.*;

class Euler 
{ 
static int phi(int n) 
{ 
	// Initialize result as n 
	int result = n; 

	// Consider all prime factors 
	// of n and subtract their 
	// multiples from result 
	for (int p = 2; p * p <= n; ++p) 
	{ 
		
		// Check if p is 
		// a prime factor. 
		if (n % p == 0) 
		{ 
			
			// If yes, then update 
			// n and result 
			while (n % p == 0) 
				n /= p; 
			result -= result / p; 
		} 
	} 

	// If n has a prime factor 
	// greater than sqrt(n) 
	// (There can be at-most 
	// one such prime factor) 
	if (n > 1) 
		result -= result / n; 
	return result; 
} 


public static void main (String[] args) 
{ 
	System.out.println("Enter number");
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	for (int i = 1; i <= n; i++) 
		System.out.println("phi(" + i + 
						") = " + phi(i)); 
} 
}
