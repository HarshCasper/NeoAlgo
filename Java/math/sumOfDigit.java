import java.util.Scanner;

public class SumOfDigit {

	
	public static void main(String[] args) {

		Scanner sc = new Scanner (System.in);
		
		System.out.println( "Enter the number = ");
		int n =sc.nextInt();
		
		System.out.println( "The sum of digit of " + n + " is "+ getSum(n) );
	}

	/* Function to get sum of digits */
        static int getSum(int n) {
    	   int temp = n;
    	   int sum = 0;
    	   
    	   while(temp >0) {
    		   int lastDigit = temp % 10;
    		   temp /= 10;
    		   sum +=lastDigit;
    				   
    	   }
    	   return sum;
       }
	

}
/*
   sample of input and output
   Example 1:
   Input = 523
   Output = 10
   
   Example 2:
   Input = 278356
   Output = 31
   
   Example 3:
   Input = 9273046
   Output = 31
   
   */