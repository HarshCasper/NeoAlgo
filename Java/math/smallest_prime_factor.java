/*
Given a number. find it's smallest prime factor.
we have to get the smallest factor of that number and
the smallest factor has to be a prime number.
*/

import java.util.Scanner;
import java.lang.*;
import java.math.*;

public class SmallestPrimeFactor
{
    //this function checks whether a number is prime or not
    static int check_prime(int number)
    {
       for(int i = 3; i * i <= number; i += 2)
       {
          if(number % i == 0)
          {
              return 0;
          }
       }
       return 1;
    }

    //this function gives us the smallest prime factor of a number
    static int get_smallest_prime_factor(int number)
    {
        int get_factor = 0;
        /* loop runs till sqrt( number ) for not any getting precision errors
         use i * i <= number */
         for(int i = 3 ; i * i <= number; i += 2)
         {
             if(number % i == 0)
             {
                get_factor = 1;
                int prime = check_prime(i);
                if(prime == 1)
                {
                  // that means the number is smallest prime factor 
                   get_factor = i;
                   break;
                 }
             }
        }
        if(get_factor == 0)
        {
        /*
        that means the number itself it's smallest prime factor.
        Ex : 17 so we can return the number. */
          return number;
        }
        return get_factor;
    }
    
    public static void main(String args[])  
    {
        Scanner scan = new Scanner(System.in);
	System.out.print("Enter the number : \n");
	int number = scan.nextInt();
	    
        /* if the number is even, we can say that the smallest prime factor
        is 2 for any even number. because 2 is prime and it's a factor of
        every even number. */
        if(number % 2 == 0)
        {
            System.out.println("Smallest prime factor for this number is : 2");
        }
        else if(number % 2 == 1)
        {
            int smallest_prime_factor = get_smallest_prime_factor(number);
            System.out.print("Smallest prime factor for this number is : ");
            System.out.println(smallest_prime_factor);
        }
        scan.close();
    }
}

/*

Standard Input and Output

1. Even number
Enter the number :
435346
Smallest prime factor for this number is : 2

2. Odd Number
Enter the number :
35345
Smallest prime factor for this number is : 5

3. Odd Prime Number :
Enter the number :
23
Smallest prime factor for this number is : 23

Time Complexity : O(sqrt (N) )
Space Complexity : O( 1 )

*/
