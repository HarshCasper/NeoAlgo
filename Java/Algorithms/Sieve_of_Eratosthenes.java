/**
The Sieve of Eratosthenes is one of the most 
efficient ways to find all primes smaller than n.
*/ 

import java.util.Arrays;
import java.util.Scanner;

public class Sieve_of_Eratosthenes {

    public static void main(String[] args) {
        
		Scanner sc=new Scanner(System.in);
	        System.out.print ("Enter value of n - ");
		int n=sc.nextInt();
		
		boolean[] prime=new boolean[n+1];
	    
		for (int i=2; i<=n; i++) {
			prime[i]=true;
		}
		
		for (int i=2; i<=Math.sqrt(n); i++) {
			int x = i;

			if (prime[i]) {

				for (int j=2; j*x<=n; j++) {
					prime[j*x]=false;
				}
			}
		}
		
              System.out.print ("Prime numbers upto "+n+" - ");

		for (int i=2; i<=n; i++) {

                       if (prime[i]) {
                               System.out.print (i+", ");
                       }
              }

              System.out.println ("End.");
	}
}

/**

Time Complexity : O(N(log(log(N))))
Space Complexity : O(N)

Sample Test case 1 :

Enter value of n - 13

Output :

Prime numbers upto 13 - 2, 3, 5, 7, 11, 13, End.

*/
