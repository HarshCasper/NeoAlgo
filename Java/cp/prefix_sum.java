/*
Given an array of N elements , find it's prefix sum array. 
In Competitive Programming, many times we need to calculate prefix sum array to solve our problem.
*/

import java.util.Scanner;
import java.lang.*;

public class PrefixSum 
{
    // this function will give us prefix sum of the array
	static void prefix_sum_array(int ar[], int N)
	{
	    int pref_ar[] = new int[N];
	   
	    pref_ar[0] = ar[0];
	    /* we will add the current element of ar[] array
         and previous element of pref_ar [] array */
        for(int i = 1; i < N; i++)
        {
           pref_ar[i] = ar[i] + pref_ar[i - 1];
        }
        System.out.println("The New Prefix sum array is \n");
		for (int i = 0; i < N; i++)
        {
            System.out.print(pref_ar[i] + " ");
        }
        System.out.println('\n');
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
		prefix_sum_array(ar,number);
		
		}
}
/*

Standard Input and Output

Enter the size of array 
7
Enter array elements
10 4 16 34 23 5 90

The New Prefix sum array is
10 14 30 64 87 92 182

Time Complexity : O(N)
Space Complexity : O(N)


*/
