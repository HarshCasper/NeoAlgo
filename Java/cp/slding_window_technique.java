/*
Given an array of N elements and a value K (K <= N) , calculate maximum summation of K consecutive elements in the array.
We can solve this problem by using Sliding Window Technique. 
This technique will allow us to solve this problem in O(N)
*/

import java.util.Scanner;
import java.lang.*;

public class SlidingWindow
{
    // this function  will give us the maximum sum
    static int max_sum_by_sliding_window(int ar[] , int number , int K)
    {
        int final_sum = 0;
        if(number == K)
        {
            int sum = 0;
            // max_sum will be the sum of all elements of array.
            for(int i = 0; i < number; i++)
            {
                sum += ar[i];
            }
            final_sum = sum;
        }
        if(number > K)
        {
            // calculate sum of first window of size K
            int max_sum = 0, win_sum = 0;
            for(int i = 0; i < K; i++)
            {
                max_sum += ar[i];
            }

            /* calculate sum of remaining windows
             by removing elements from first window simultaneously add elements to current window */
            win_sum = max_sum;
            for(int i = K; i < number; i++)
            {
                win_sum += (ar[i] - ar[i - K]);
                if(win_sum > max_sum)
                {
                    max_sum = win_sum;
                }
            }
            final_sum = max_sum;
        }
        return final_sum;
    }
    


    public static void main(String args[])  
    {
       Scanner scan = new Scanner(System.in);
       System.out.print("Enter the size of array \n");
       int number = scan.nextInt();
       int K = scan.nextInt();
       int[] ar = new int[number];
       System.out.println("Enter array elements \n"); 
       for(int i = 0; i < number; i++)
       {
	   ar[i] = scan.nextInt();
       }
       int solve = max_sum_by_sliding_window(ar, number , K);
       System.out.print("maximum summation of K consecutive elements in the array is ");
       System.out.println(solve);
       scan.close();
    }
}
/*
Standard Input and Output

1. if N == K
Input array size and value
5 5
1 2 3 4 5

maximum summation of K consecutive elements in the array is 15

2. if N > K
Input array size and value
5 3
5 2 -1 0 3

maximum summation of K consecutive elements in the array is 6

Time Complexity : O(N)
Space Complexity : O(1)

*/
