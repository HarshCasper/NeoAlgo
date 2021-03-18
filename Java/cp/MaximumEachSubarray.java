/**
 * Maximum of All Subarrays of Size k
 * Java program to find the maximum integer in each subarray of 
 * fixed size k, given an array of integers, using the 'Sliding 
 * Window Technique'. 
 */

import java.io.*;
import java.util.*; 
public class MaximumEachSubarray {

    private static String findMaxEachSubarray(int[] numArray, int k) {
        String result = ""; 

        //ArrayDeque stores indices of useful elements for each window.
        //These indices are sorted in decreasing order, so that for each
        //window, index of maximum element is at the front. 
        ArrayDeque<Integer> indices = new ArrayDeque<>();
        
        //For first window 
        for(int i=0; i<k; i++){

            //For any element, all elements smaller than it and to its left in 
            //the window are useless as they cannot be the maximum for that 
            //window. Hence, we remove them from rear of deque. 
            while(!indices.isEmpty() && (numArray[i] >= numArray[indices.peekLast()]))
                indices.removeLast(); 

            //Adding newest element to rear of deque
            indices.addLast(i); 
        }
        
        //For first window
        result += (numArray[indices.peek()] + " "); 
        
        //The same process is repeated over all windows of length k.
        for(int i=k; i<numArray.length; i++) {

            //If window has crossed the index at front of deque
            if(indices.peek() <= (i-k)) 
                indices.removeFirst(); 

            while(!indices.isEmpty() && (numArray[indices.peekLast()] <= numArray[i]))
                indices.removeLast(); 
            indices.addLast(i); 
            result += (numArray[indices.peek()] + " "); 
        }

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
        System.out.println("Enter size of window: ");
	    int K = Integer.parseInt(buf.readLine()); 
	    
        //Output is a String in which the first integer is maximum for 1st K-sized window, 
        //the second integer is maximum for 2nd K-sized window, and so on.
        System.out.println("String of maximum integers in all K-sized subarrays: ");
        System.out.println(findMaxEachSubarray(numArray, K));
    }

}

/*
    Time complexity: O(N)
    Space complexity: O(k) (ArrayDeque used to store indices can be, 
                            at most, k in length)

    TEST CASES

    INPUT
    Enter length of array of integers: 
    10
    Enter array of integers: 
    12 3 4 5 1 7 2 9 1 18
    Enter size of window: 
    4
    OUTPUT
    String of maximum integers in all K-sized subarrays:
    12 5 7 7 9 9 18 

    INPUT
    Enter length of array of integers: 
    8
    Enter array of integers: 
    1 3 -1 -3 5 3 6 7 
    Enter size of window: 
    3
    OUTPUT
    String of maximum integers in all K-sized subarrays:
    3 3 5 5 6 7

 */
