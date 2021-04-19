/**
 * Maximum of Minimum for Every Window Size in an Array
 * Find the maximum of the minimums of every window size in a given 
 * positive integer array of size n. The size of windows in an array 
 * vary from 1 to n. 
 */

import java.io.*;
import java.util.*; 
public class MaximumOfMinimumSubarrays {

    public static int[] findMaximumOfMinimums(int[] numArray, int n) {

        //The next[] and prev[] arrays store the indices of next smaller 
        //and previous smaller integers for each element.  
        int[] next = new int[n]; 
        int[] prev = new int[n];

        //If next smaller element is non-existent, then n is stored, if
        //previous smaller element in non-existent, then -1 is stored. 
        for(int i=0; i<n; ++i) {
            next[i] = n; 
            prev[i] = -1; 
        }

        //Using stack to get next smaller element
        ArrayDeque<Integer> indices = new ArrayDeque<>(); 
        for(int i=0; i<n; i++) {
            while(indices.peek()!=null && numArray[indices.peek()] > numArray[i]) {
                next[indices.peek()] = i;
                indices.pop(); 
            }
            indices.push(i); 
        }
        indices.clear(); 

        //Using stack to get previous smaller element
        for(int i=n-1; i>=0; i--) {
            while(indices.peek()!=null && numArray[indices.peek()] > numArray[i]) {
                prev[indices.peek()] = i;
                indices.pop(); 
            }
            indices.push(i); 
        }
        
        int[] result = new int[n]; 
        int windowSize = 0; 
        //Here, windowSize stores the window size (length) for which the 
        //concerned element is minimum.
        for(int i=0; i<n; i++) {
            windowSize = next[i] - prev[i] - 1; 
            
            //Since we need the maximum of minimum values for a given windowSize.
            //Since windowSize is from 1 to n, but indices are from 0 to n-1,
            //we take result[windowSize - 1].
            //numArray[i] could be a potential value for current windowSize
            result[windowSize-1] = Math.max(result[windowSize-1], numArray[i]); 
        }
        
        //To fill all the remaining entries of result[]. The observation used 
        //to obtain these values is that result[i] is always >= result[i+1].
        for(int i=n-2; i>=0; i--) 
            result[i] = Math.max(result[i], result[i+1]); 
        
        return result;
    }
    
    public static void main(String[] args) throws IOException {
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

        int arr[] = findMaximumOfMinimums(numArray, len); 
        //Printing the obtained array values as a String
        System.out.println("String of maximum of the minimums of every window" +
                            " size from 1 to " + len + ":");
        String result = "";
        for(int i=0; i<len; i++)
            result += (arr[i] + " "); 
        System.out.println(result); 
    }

}

/*
    Time complexity: O(N)
    Space complexity: O(N) (Space used for stack and auxiliary arrays)

    TEST CASES

    INPUT
    Enter length of array of integers: 
    10
    Enter array of integers: 
    4 7 3 5 0 8 4 10 10 0
    OUTPUT
    String of maximum of the minimums of every window size from 1 to 10:
    10 10 4 4 0 0 0 0 0 0

    INPUT
    Enter length of array of integers: 
    5
    Enter array of integers: 
    3 3 4 2 4
    OUTPUT
    String of maximum of the minimums of every window size from 1 to 10:
    4 3 3 2 2 

 */
