/*program for calculating HCF of two number*/
import java.util.Scanner;

public class hcf
 {

	   public static void main(String args[]){
		   
	      int dividend , divisor , i , hcf = 0;
	      
	      Scanner sc = new Scanner(System.in);
	      
	        System.out.println("Enter first number : ");
	        dividend = sc.nextInt();

	        System.out.println("Enter second number : ");
	        divisor = sc.nextInt();

	      for(i = 1; i <= dividend|| i <= divisor; i++) 
              {
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
 * HCF of given two number is : 16 */
