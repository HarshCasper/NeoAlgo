//Program to swap two numbers using bit manipulation.
import java.util.Scanner;
public class swap {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		//swapping 
		a=a^b;
		b=a^b;
		a=a^b;
		System.out.println(a);
		System.out.println(b);

	}

}
