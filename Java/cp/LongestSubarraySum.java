/**
 * Longest Subarray Having Sum K
 * Given an array of integers, find the length of the longest sub-array 
 * having sum equal to the given value K.
 */

import java.io.*;
import java.util.*; 
public class LongestSubarraySum {

    public static int findLongestSubarray(int[] numArray, int K) {

        //HashMap containing (sum, index) key:value pairs
        HashMap<Long, Integer> hMap = new HashMap<>(); 

        long sum = 0l; //Stores cumulative sum as we traverse the integer array
        int length = 0; //Stores length of longest valid subarray

        for(int i=0; i<numArray.length; i++) {
            sum += numArray[i]; 

            if(sum == K)
                length = Math.max(length, i+1); 

            //Only the first index of occurrence of a particular sum is stored,
            //as we need to find length of longest valid subarray
            if(!hMap.containsKey(sum)) 
                hMap.put(sum, i); 

            //Checking if HashMap contains (sum-K) as we know that:
            // (sum - (sum - K)) = K, which is the required sum
            if(hMap.containsKey(sum - K))
                length = Math.max(length, i - hMap.get(sum - K)); 
        }

        return length; 
    }
    
    public static void main(String[] args) throws IOException{
        InputStreamReader read = new InputStreamReader(System.in);
	    BufferedReader buf = new BufferedReader(read); 

        //Taking input from user
        System.out.println("Enter length of array of integers: ");
	    int len = Integer.parseInt(buf.readLine());
        System.out.println("Enter array of integers: ");
	    StringTokenizer st = new StringTokenizer(buf.readLine());
	    int numArray[] = new int[len];
	    for(int i=0; i<len; i++) {
	        numArray[i] = Integer.parseInt(st.nextToken()); 
	    } 
        System.out.println("Enter sum: ");
	    int K = Integer.parseInt(buf.readLine()); 
	    
        System.out.print("Length of longest subarray having sum " + K + ": "); 
        System.out.println(findLongestSubarray(numArray, K)); 
    }

}

/*
    Time complexity: O(N)
    Space complexity: O(N) (for the HashMap)

    TEST CASES

    INPUT
    Enter length of array of integers: 
    8
    Enter array of integers: 
    2 1 3 2 1 1 1 3
    Enter sum: 
    4
    OUTPUT
    Length of longest subarray having sum 4: 3

    INPUT
    Enter length of array of integers:
    6
    Enter array of integers:
    -5 8 -14 2 4 12
    Enter sum:
    -5
    OUTPUT
    Length of longest subarray having sum -5: 5

 */
