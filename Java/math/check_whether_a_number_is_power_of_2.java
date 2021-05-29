/*
Given a number , check whether the number is power of 2 or not.
We can check this by doing some bitwise operation.
Bitwise operations are best because they perform the operation in least possible time.
*/

import java.util.*;
import java.lang.*;
public class Powerof2 
{
	
	// This function will tell us whether a number is power of 2
	static boolean number_is_power_of_2(int number) 
	{
		/* if bitwise and of number and number-1 is zero
        then we can say that number is power of 2
        otherwise it is not. */
        if((number & (number - 1)) == 0)
        {
            return true;
        }
        return false;
	}
	public static void main(String args[]) 
	{
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the number \n");
		int number = scan.nextInt();
		scan.close();
		
		// Calling the number_is_power_of_2 function
		boolean result = number_is_power_of_2(number);
		if(result) 
		{
			System.out.println("The Number is power of 2\n");
		}
		// else that number is not power of 2
		else 
		{
			System.out.println("No. the number is not power of 2\n");
		}
	}
}

/*

Standard Input and Output

Enter the number
64
The Number is power of 2

Enter the number
34
No. the number is not power of 2

Time Complexity : O(1)
Space Complexity : O(1)

*/
