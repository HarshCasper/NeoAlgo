/*
Given an array of N elements.
Find MEX ( Minimum Excluded Element ) of input array.
Mex of an array is the minimum positive integer that doesn't appear in this array.
For example, MEX of the array containing 1, 3 and 4 is equal to 2.
*/

import java.util.Scanner;
import java.lang.*;

public class MEXofanarray
{
    // this get_MEX_of_array function will give us MEX of input array
    static int get_MEX_of_array(int ar[],int N)
    {
        /* we will use a visited_array[]
        check if visited_array[ar[i]] == 0 means
        ar[i] is visited or not if is not visited then we will increment it
        visited_array[ar[i]]++  */
        int visited_array[] = new int[N + 1];
    
        for(int i = 0; i < N; i++)
        {
             if(visited_array[ar[i]] == 0)
             {
                 visited_array[ar[i]]++;
             }
         }

         /* set MEX as 1
         then will start from 1 index and check if visited_array[i] == 0
         means that element is not present in array , hence that is the MEX
         */
         int MEX = 1;
         for(int i = 1; i < N; i++)
         {
             if(visited_array[i] == 0)
             {
                MEX = i;
                break;
             }
        }
        return MEX;
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
	   scan.close();
	   int MEX_of_array = get_MEX_of_array(ar , N);
	   System.out.println("MEX of the Array is :\n"); 
           System.out.println(MEX_of_array);
	}
}
/*
Standard Input and Output

Enter the size of the array :
8
Enter array elements :
8 2 7 4 6 2 1 4

MEX of the Array is :
3

Time Complexity : O( N )
Space Complexity : O(N)

*/
