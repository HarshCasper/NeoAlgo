String Method:
import java.util.Scanner;

public class CountDigits {

	public static int countdigit(int n) {
	     if(n==0){
	         return 1;
	     }
         return (Integer.toString(n).length());
	}
	
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
		System.out.print("Enter a number : ");
		int n=sc.nextInt();
		
		System.out.println("Number of digits in a number are : ");
		System.out.println(countdigit(n));
				
	}
}	
/*	
 	Sample Input : 
	Enter a number : 24567
 	
	Sample Output : 5
	 	
*/