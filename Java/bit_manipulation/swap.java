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


Example No1:- Let a=5 and b=10 
	after xor operation output is a=10 and b=5 
Example No2:- a=23 and b=5
	after xor operation output is a=5 and b=23

**Time Complexity **:- O(1) 
**Space Complexity ** :- O(1)
