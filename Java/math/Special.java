/*
The program is to check whether a given number is a special number or not.
A special number is a number whose all digits are 1
*/
import java.util.*;
class special
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
		/*Taking the number which is to be checked*/
        System.out.println("Enter the number");
        int n=sc.nextInt();
        int s=0,c=0;
        while(n!=0)
        {
            int b=n%10;
			/*Calculating sum of digits*/
            s=s+b;
			/*Calculating count of digits*/
            c++;
            n=n/10;
        }
		/*If the sum of digits and count of digits is equal then special*/
        if(s==c)
        System.out.println("The given number is special");
        else
        System.out.println("The given number is not special");
    }
}

/*
Time Complexity:O(n)
Space Complexity:O(1)
Input/Output:-
Enter the number 
1111
The given number is special
*/