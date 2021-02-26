//Program to swap two numbers using bit manipulation.
/*
XOR operation can be defined as 
a	b	a^b
0	0	0
0	1	1
1	0	1
1	1	1



*/
import java.util.Scanner;
public class swap {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter No a=");
		int a=sc.nextInt();
		System.out.println("Enter No a=");
		int b=sc.nextInt();
		//swapping 
		a=a^b;
		b=a^b;
		a=a^b;
		
		System.out.println("Value in a after swap = "+ a);
		System.out.println("Value in b after swap = " +b);

	}
}

/*
Enter No a=4
Enter No b=8
Value in a after swap=8
Value in b after swap=4
/*

/*
Enter No a=10
Enter No b=20
Value in a after swap=20
Value in a after swap=10
*/
/*
**Time Complexity **:- O(1) 
**Space Complexity ** :- O(1)

*/
