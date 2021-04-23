/*
Problem Description: For a given unsorted array, your task is to return 
the length of longest sub-sequence such that elements in the subsequence 
are consecutive integers.

For example: For an array [3, 6, 10, 2, 4] the longest sequence of 
consecutive elements is 2, 3, 4 so the length will be 3.
*/

import java.io.*;
import java.util.*;

class Longest_Consecutive_Sequence {
    static int longestSeq(int[] arr){

        //Base case
        if(nums == null || nums.length == 0){
            return 0;
        }
        //Sort the given array
        Arrays.sort(nums);

        //Initializing count and maximum count 
        int count = 1, max = 1;

        //Traverse  the array
        for(int i=0 ; i<nums.length-1 ; i++){

            //Check for duplicate elements
            //Skip duplicates
            if(nums[i] == nums[i+1]){
                continue;
            }

            //Check if previous elements is one less than the current element,
            //if true increase count by one
            else if(nums[i+1] - nums[i] == 1){
                count++;
                //update the maximum
                max = Math.max(max, count);
            }

            else{
                count = 1;
            }
        }
        //Return the maximum length
        return max;
    }
    
    //driver method
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.pritln("Enter number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements: ");
        for(int i=0 ; i<n ; i++){
            arr[i] = sc.nextInt();
        }
        System.out.printn("Length of longest consecutive sequence: " + longestSeq(arr));
    }
}

/*
Time Complexity: O(n)
Space Complextiy: O(1)

Sample Case: 
Input-
Enter number of elements:
4
Enter elements:
1 2 0 1

Output-
Length of longest consecutive sequence: 
3
*/
