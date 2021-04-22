
/*
 * The Kamenetsky Formula is used to calculate the number of digits in the factorial of a number.
 * Formula:
 *        number of digits in factorial = log10( ((n/e)^n) * sqrt(2*pi*n))
 *        which can be simplified to:
 *        number of digits in factorial = n* log10(( n/ e)) + log10(2*pi*n)/2
 * where n is the number.
 */

import java.util.*;
public class Kamenetsky_Formula
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter number: ");
        int number = scanner.nextInt();
        scanner.nextLine();
        
        long number_of_digits;
        
        if(number<0)
        {
            number_of_digits = -1;
            System.out.println("Factorial of negative number cannot be calucated!");
        }
        else if(number<=1)
        {
            number_of_digits = 1;
            System.out.println("Number of digits in factorial: "+number_of_digits);
        }
        else
        {
            number_of_digits = (long)(Math.floor(number * Math.log10(number / 2.718) + Math.log10(2 * 3.142 * number) /  2.0)) + 1;
            System.out.println("Number of digits in factorial: "+number_of_digits);
        }
    }
}
        
/*
  Test Cases-
   
  1.
  Enter number: 
  10
  Number of digits in factorial: 7
  
  2.
  Enter number: 
  1
  Number of digits in factorial: 1
  
  3.
  Enter number: 
  -9
  Factorial of negative number cannot be calucated!
  
  Time Complexity: O(1)
 */

    