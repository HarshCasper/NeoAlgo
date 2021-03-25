/*
 
Author: Neha Baisane (@neha-baisane)

Definition:  A number is said to be an Armstrong number if the following equation is true for that number:
                   xyx... = pow(x,n) + pow(y,n) + pow(z,n) +... 
                   where n is equal to the number of digits present in the number.

Example:  371
Output: True
Explanation: 3*3*3 + 7*7*7 + 1*1*1 = 371
             Here, value of n is 3.

Method: The method is to first  find order i.e value of 'n. For every digit 'd' in input number x, perform d^n. If the sum of all such values equals to n, then return true or else it will return false.
                   
*/


import java.util.Scanner;
import java.lang.Math;

public class ArmstrongNumber
{
    /* Function to calculate m raised to the power n */
    int power(int m, long n)
    {
        if( n == 0)
            return 1;
        if (n%2 == 0)
            return power(m, n/2)*power(m, n/2);
        return m*power(m, n/2)*power(m, n/2);
    }
  
    /* Function for calculating order of given number */
    int order(int m)
    {
        int n = 0;
		
        while (m != 0)
        {
            n++;
            m = m/10;
        }
		
        return n;
    }
  
    /* Function to find whether given number is Armstrong number or not */
    boolean checkForArmstrongNumber (int m)
    {
        /* Call for order function */
        int n = order(m);
        int temp=m, sum=0;
        while (temp!=0)
        {
            int r = temp%10;
            sum = sum + power(r,n);
            temp = temp/10;
        }
  
        /* Returns if it satisfies Armstrong number condition */
        return (sum == m);
    }
  
      /* Driver Program*/
    public static void main(String[] args)
    {
	/* creating object of instance class */
        ArmstrongNumber object = new ArmstrongNumber();
		
	/* Taking input from user */
	System.out.print("Enter a number to check whether it is Armstrong or not : ");
	Scanner s = new Scanner(System.in);
	int m = s.nextInt();
        System.out.println(object.checkForArmstrongNumber(m));
        
    }
}


/*

Time Complexity: O(log (n))
Space Complexity: O(1)

Input:
Enter a number to check whether it is Armstrong or not : 1634

Output:
true

*/

