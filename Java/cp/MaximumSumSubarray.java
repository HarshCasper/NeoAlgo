/**
 * Maximum Sum Subarray of Size K
 * Java program to find the maximum sum of a subarray of fixed size K, 
 * given an array of integers, using the 'Sliding Window Technique'. 
 */

import java.util.*; 
public class MaximumSumSubarray {
    
    public static int maximumSum(int[] numArray, int K) {
        int currentSum = 0; 

        //Calculating sum for first window of size K
        for(int i=0; i<K; i++) 
            currentSum += numArray[i]; 

        //Storing maximum sum till current window
        int maxSum = currentSum; 

        //Finding sum of all possible K-sized windows, one by one
        int subtractIndex = 0; 
        for(int i=K; i<numArray.length; i++) {
            currentSum += numArray[i] - numArray[subtractIndex]; 
            subtractIndex++; 
            maxSum = Math.max(maxSum, currentSum); 
        }
        return maxSum; 
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); 

        //Taking input from user
        System.out.println("Enter length of array and size of window: "); 
        int length = scan.nextInt(); 
        int K = scan.nextInt(); 
        int numArray[] = new int[length]; 
        System.out.println("Enter array elements: "); 
        for(int i=0; i<length; i++) {
            numArray[i] = scan.nextInt(); 
        }

        if(K > length || K <= 0)
            System.out.println("Invalid input"); 
        else {
            System.out.println("Maximum sum of a subarray of size " + K + ":"); 
            System.out.println(maximumSum(numArray, K));
        }
    }

}

/*
    Time complexity: O(N)
    Space complexity: O(1)

    TEST CASES

    INPUT
    Enter length of array and size of window: 
    10 3
    Enter array elements: 
    1 7 -2 4 5 2 1 6 11 -4
    OUTPUT
    Maximum sum of a subarray of size 3:
    18

    INPUT
    Enter length of array and size of window: 
    8 4
    Enter array elements:
    2 4 0 1 5 2 9 3
    OUTPUT
    Maximum sum of a subarray of size 4:
    19

 */
