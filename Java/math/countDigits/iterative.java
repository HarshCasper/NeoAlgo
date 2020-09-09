/*Iterative:*/
import java.util.Scanner;

public class CountDigits {

	public static void countdigit(int n) {
	        int count=0;
		while(n!=0){
                count=count+1;
                n=n/10;
              }
             System.out.println(count);   

	}
	
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
		System.out.print("Enter a number : ");
		int n=sc.nextInt();
		
		System.out.println("Number of digits in a number are : ");
		countdigit(n);
				
	}
/*	
 	Sample Input : 
	Enter a number : 24567
 	
	Sample Output : 5
	 	
*/
