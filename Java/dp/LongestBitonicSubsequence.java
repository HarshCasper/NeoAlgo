/* In Longest Bitonic Subsequence problem, a sequence is first increasing and then decreasing.
In this problem, an array of all positive integers is given. We have to find a subsequence
which is increasing first and then decreasing.
To solve this problem, we will define two subsequences,
they are the Longest Increasing Subsequence and the Longest Decreasing Subsequence.
The LIS array will hold the length of increasing subsequence ending with array[i].
The LDS array will store the length of decreasing subsequence starting from array[i].
Using these two arrays, we can get the length of longest bitonic subsequence.

Below is the dynamic approach in java for this problem*/
import java.util.*;
import java.lang.*;
import java.io.*;

class LongestBitonicSubsequence {
    /* lbs() function below returns the length of the Longest Bitonic Subsequence in
    arr[] of size n. The function mainly creates two temporary arrays
    lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1.

    lis[i] ==> Longest Increasing subsequence ending with arr[i]
    lds[i] ==> Longest decreasing subsequence starting with arr[i]
    */
    static int lbs( int arr[], int n ) {
        int i, j;
        /* Allocate memory for LIS[] and initialize LIS values as 1 for
            all indexes */
        int[] lis = new int[n];
        for (i = 0; i < n; i++)
            lis[i] = 1;
        /* Compute LIS values from left to right */
        for (i = 1; i < n; i++)
            for (j = 0; j < i; j++)
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        /* Allocate memory for lds and initialize LDS values for
            all indexes */
        int[] lds = new int [n];
        for (i = 0; i < n; i++)
            lds[i] = 1;
        /* Compute LDS values from right to left */
        for (i = n-2; i >= 0; i--)
            for (j = n-1; j > i; j--)
                if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
                    lds[i] = lds[j] + 1;
        /* Return the maximum value of lis[i] + lds[i] - 1*/
        int max = lis[0] + lds[0] - 1;
        for (i = 1; i < n; i++)
            if (lis[i] + lds[i] - 1 > max)
                max = lis[i] + lds[i] - 1;

        return max;
    }

    public static void main (String[] args) {
        int size;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of an array: ");
        size = sc.nextInt();
        System.out.print("Enter Array elements: ");
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Length of Longest Bitonic Subsequence is "+ lbs( arr, size ));
    }
}
/*
 Sample Input/Output:
 Input: Enter the size of an array: 16
        Enter Array elements: 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

 Output: Length of Longest Bitonic Subsequence is 7

 Time and space complexity for this approach:
 Time Complexity: O(n^2)
 Space Complexity: O(n)
*/

