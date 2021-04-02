
//Given two sorted arrays nums1 and nums2 of size m and n 
//respectively, return the median of the two sorted arrays.

import java.io.*;
import java.util.*;

class Median_of_2_sorted_array {
    static double findMedianSortedArrays(int[] nums1, int[] nums2) {
    // length of the merged array
    int nums3length = nums1.length + nums2.length;
        int nums3[] = new int[nums3length];
        int j=0;
        //storing the elements of both arrays into nums3
        for(int i =0;i<nums1.length;i++)
        {
            nums3[j++] = nums1[i];
        }
        for(int i =0;i<nums2.length;i++)
        {
            nums3[j++] = nums2[i];
        }
        //sorting nums3 array
        Arrays.sort(nums3);
    double mid;
    //checking if length of merged array is odd
    
    if(nums3length % 2 != 0) {
        //return the median
        mid = nums3[nums3length / 2>>0];
        return mid;
    } 
    //if the length is odd
    else {
        //median is the average of two mid elements
        double first = nums3[nums3.length / 2>>0];
        double second = nums3[(nums3.length / 2 >> 0 )-1];
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
        int arr2[] = new int[m];
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
[1,3]
[2]

Output:
2.00000

Example 2:

Input:
[1,5,7,8,9]
[2,4,4]

Output:
4.50000

*/


