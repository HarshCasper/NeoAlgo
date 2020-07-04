/* Sieve of Eratosthenes : 
  
  Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.
  It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with
  the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers starting from that prime,
  with constant difference between them that is equal to that prime.

*/

import java.util.Scanner;

public class SieveOfEratosthenes {

	public static void sieve(int n) {
	
		boolean prime[]=new boolean[n+1];
		
		for(int i=0;i<=n;i++) {
			prime[i]=true;
		}
		
		prime[0]=prime[1]=false;
		
		for(int i=2;i*i<=n;i++) {
//	If a number is prime :	
			if(prime[i]==true) {
//	Marking all multiples of that number as false
				for(int j=i*i;j<=n;j+=i) {
					prime[j]=false;
				}
			}
		}
		
//	Printing all prime number less than n :	
		for(int i=0;i<=n;i++) {
			if(prime[i]==true) {
				System.out.print(i+" ");
			}
		}
		
	}
	
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
		System.out.print("Enter a number : ");
		int n=sc.nextInt();
		
		System.out.println("Prime number less than or equal to "+n+" are : ");
		sieve(n);
				
	}
/*	
 	Sample Input : 
	Enter a number : 100
 	
	Sample Output : 
	Prime number less than or equal to 100 are : 
	2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 	
*/

}
