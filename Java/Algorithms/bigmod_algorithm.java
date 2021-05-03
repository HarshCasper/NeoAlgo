/*
Given a number's base and power.
return the number.
base and power can be large as 10^6 to 10^9
so we need to mod with some big number in order to get the number
this can be done by bigmod algorithm
*/

import java.util.Scanner;
import java.lang.*;
import java.math.*;

public class NumberofDivisors
{
   //this function will give us the new number according to our base and power
   static long get_new_number_by_bigmod(long base, long power, long  mod_number)
   {
    long new_number;
    if(power == 0)
    {
        // no matter what base is , as power is 0 answer 1
        return 1;
    }
    else if(power % 2 == 0)
    {
        /* as power is even,
        we will divide the power each step by 2
        9^18 will be 9^9 , 9^9
        and thus goes on  by recursive call */
        
        new_number = get_new_number_by_bigmod(base , power / 2, mod_number);
        return ((new_number * new_number) % mod_number);
    }
    else
    {
         /* as power is odd,
        we will  take power - 1
        9^15 = 9^14 , 9^1
        and thus goes on  by recursive call  */
        long temp = get_new_number_by_bigmod(base , power - 1 , mod_number);
        return ((( base % mod_number)* temp)% mod_number);

    }
   }

    public static void main(String args[])  
    {
        Scanner scan = new Scanner(System.in);
	System.out.print("Enter the base number and power number : ");
	long base = scan.nextLong();
        long power = scan.nextLong();
        System.out.print("Enter the mod number: ");
        long mod_number = scan.nextLong();
        long new_number = get_new_number_by_bigmod(base, power, mod_number);

        System.out.print("After applying Bigmod algorithm the new number is : \n");
        System.out.print(new_number);
        scan.close();
    }
}

/*

Standard Input and Output

Enter the base number and power number :
45 67
Enter the mod number: 1000456

After applying Bigmod algorithm the new number is :
595941

Time Complexity : O( log N )
Space Complexity : O( 1 )

*/
