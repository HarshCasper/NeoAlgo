/*
Given a Number. Find it's Sum of Divisors.
The Number can be big such as 10^6 to 10^9
So, If we do this in O(N) we will get Time Limit Exceeded [TLE]
Better Approach is run a loop till sqrt(Number)
Example square root of 10^9 is 31622 (approx), so iteration optimized a lot.
*/

import java.util.Scanner;
import java.lang.*;
import java.math.*;

public class SumofDivisors
{
   //this get_sum_of_divisors will count the sum of divisors of the number
   static long get_sum_of_divisors(long number)
   {
    /* Sum of Divisors may not fit in int range
       so better take long long int */
      long sum_of_divisors = 0, i = 0;
      int limit = (int) Math.sqrt(number);
      for(i = 1; i < limit; i++)
      {
         if(number % i == 0)
         {
            /* Here i is a divisor of that number
            ( Number / i ) is also a divisor
            */
            sum_of_divisors += i;
            sum_of_divisors += (number / i);
         }
      }
	

    if(number % limit == 0)
    {
        if(limit * limit == number)
        {
            //means perfect square number
            sum_of_divisors += limit;
        }
        else
        {
            sum_of_divisors += limit;
            sum_of_divisors += (number / limit);
        }
    }
    return sum_of_divisors;
	   
   }

    public static void main(String args[])  
    {
        Scanner scan = new Scanner(System.in);
	System.out.print("Enter the number : \n");
	long number = scan.nextLong();
        long sum_of_divisors = get_sum_of_divisors(number);
        
        System.out.print("Sum of Divisors of this Number is : ");
        System.out.print(sum_of_divisors);
        scan.close();
    }
}
/*

Standard Input and Output

Enter the number :
1000000000
Sum of Divisors of this Number is : 2497558338

Enter the number :
456723
Sum of Divisors of this Number is : 681408

Time Complexity : O( sqrt(N) )
Space Complexity : O( 1 )

*/
