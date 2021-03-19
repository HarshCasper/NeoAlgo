/**
 * First Negative Integer in Every Window of Size K
 * Java program to find the first negative integer in each subarray 
 * of fixed size K, given an array of integers, using the 'Sliding 
 * Window Technique'. In case there is no negative integer in given
 * window, print 0.  
 */

import java.io.*;
import java.util.*;

public class FirstNegativeNumber {

    public static String findFirstNegativeNumber(int[] numArray, int K) {
        String str = ""; 

        //The ArrayDeque contains indices of all negative integers in a given 
        //window, with the first element being the index of first negative
        //integer in given window.  
        ArrayDeque<Integer> adeque = new ArrayDeque<>(); 
		for(int i=0; i<K; i++){
		    if(numArray[i] < 0)
		        adeque.add(i);
		}
 
		for(int i=K-1; i < (numArray.length-1); i++) {

            //If ArrayDeque is not empty, then its first element is the index
            //of first negative integer in the current window. Once our window 
            //crosses this index, we remove it from the deque. 
		    if(!adeque.isEmpty()) {
		        str += (numArray[adeque.peek()] + " "); 
		        if(adeque.peek() <= (i-K+1))
		            adeque.removeFirst(); 
		    } else {
                //When there is no negative integer in the window
		        str += "0 "; 
		    }

            //Checking if the element added for the next window is negative
		    if(numArray[i+1] < 0) 
		        adeque.add(i+1); 
		}

        // For printing the first negative integer of last window
		if(adeque.isEmpty()) 
		    str += "0 "; 
		else 
		    str += (numArray[adeque.peek()] + " "); 
		
		return str;
    }
    public static void main (String[] args) throws IOException {
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
	    
        //Printing output String 
        System.out.println("String of first negative number for each subarray of size "
                        + K + ": "); 
        System.out.println(findFirstNegativeNumber(numArray, K)); 
	}
}

/*
    Time complexity: O(N)
    Space complexity: O(K) (as maximum number of negative integers 
    stored in ArrayDeque at any point of time = K)

    TEST CASES

    INPUT
    Enter length of array of integers: 
    10
    Enter array of integers: 
    3 4 -1 6 7 8 -3 -1 0 12
    Enter size of window: 
    3
    OUTPUT
    String of first negative number for each subarray of size 3:
    -1 -1 -1 0 -3 -3 -3 -1

    INPUT
    Enter length of array of integers: 
    9
    Enter array of integers: 
    -1 2 0 3 -2 -1 -2 10 8
    Enter size of window: 
    5
    OUTPUT
    String of first negative number for each subarray of size 5:
    -1 -2 -2 -2 -2 

 */
