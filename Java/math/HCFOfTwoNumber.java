/*program for calculating HCF of two number.
 *HCF is also known as Greatest Common divisor , HCF of two numbers is the largest 
 *positive integer that divides both the numbers. 
 *For example :
 *let there be two arbitrary numbers such as 30 & 90
 *30 = 3*10    ,   90 = 3*3*10  
 *Common Divisor = 3*10 = 30 
 *Here, the HCF of the two given numbers would be 30 
 *Since it divides every given number without leaving a fraction behind.

 *Algorithm
 * - Define two varibales -A,B
 * - Set loop from 1 to max of A,B
 * - Check if both are completely divided by same loop number, if yes, store it
 * - Display the store number is HCF */

import java.util.Scanner;
public class hcf {
  public static void main(String args[]){
       int dividend , divisor , i , hcf = 0;
       Scanner sc = new Scanner(System.in);
       // Number input from user
       System.out.println("Enter first number : ");
       dividend = sc.nextInt();
       System.out.println("Enter second number : ");
       divisor = sc.nextInt();
       
       for(i = 1; i <= dividend|| i <= divisor; i++) {
	    if( dividend % i == 0 && divisor% i== 0 )
	     hcf = i ;
       }
       System.out.println("HCF of given two numbers is : "+hcf);
   }
}

/*
 * Example-
 * 1.
 * Enter first number : 4
 * Enter second number : 4
 * HCF of given two number is : 4
 * 
 *  2.
 *  Enter first number : 0
 * Enter second number : 16
 * HCF of given two number is : 16 
 *
 * Time Complexity : O(n)
 * Space Complexity : O(1) 
 */