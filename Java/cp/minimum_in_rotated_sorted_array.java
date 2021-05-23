/*
Given a sorted and rotated array.
The array is rotated between 1 and n times[ n = array size]
find the minimum element of the input array.
array may contain duplicate elements.
*/

import java.util.Scanner;
import java.lang.*;

public class Mineleinarray
{
    // this function  will give us the minimum element
    static int get_minimum_element(int ar[], int N)
    {
         int first = 0, last = N - 1;
         int minelement = -1;
        while(first < last)
        {
             //if ar[first] > ar[last] then we will increment first and last remains same
             if(ar[first] > ar[last])
             {
                first++;
                minelement = ar[last];
             }
             //if ar[first] <=  ar[last] then we will decrement last and first remains same
             if(ar[first] <= ar[last])
             {
                 last--;
                 minelement = ar[first];
             }
        }
        return minelement;
    }
    

    public static void main(String args[])  
    {
       Scanner scan = new Scanner(System.in);
       System.out.print("Enter the size of array \n");
       int number = scan.nextInt();
       int[] ar = new int[number];
       System.out.println("Enter array elements \n"); 
       for(int i = 0; i < number; i++)
       {
	  ar[i] = scan.nextInt();
       }
       int minimum_element = get_minimum_element(ar, number);
       System.out.println("Minimum Element of the array is: \n");
       System.out.println(minimum_element);
       scan.close();
    }
}
/*
Standard Input and Output

Enter the size of the array :
12
Enter array elements :
465 7878 3535 68 3435 89897 466 878 44 7879 3 67868

Minimum Element of the array is:
3

Time Complexity : O( N )
Space Complexity : O(1)

*/
