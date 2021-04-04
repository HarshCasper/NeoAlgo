
//Given two sorted arrays nums1 and nums2 of size m and n 
//respectively, return the median of the two sorted arrays.

import java.io.*;
import java.util.*;

class Median_of_2_sorted_array {
    //if the length is odd
    else {
        //median is the average of two mid elements
        double first = arr3[arr3.length / 2>>0];
        double second = arr3[(arr3.length / 2 >> 0 )-1];
        mid =  first + second;
        return( mid ) / 2;
    }

    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int arr1[] = new int[n];
        for(int i = 0;i < n; i++)
          arr1[i] = sc.nextInt();

        for(int i = 0;i < m; i++)
            arr2[i] = sc.nextInt();

        System.out.println(findMedianSortedArrays(arr1,arr2));
        
    }
}


/*
Time complexity: O(n)
Space complexity: O(n)

Example 1:

Input:
2 1
1 3
2

Output:
2.00000

Example 2:

Input:
5 3
1 5 7 8 9
2 4 4

Output:
4.50000

*/


