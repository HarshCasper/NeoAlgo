/*
__Kth largest element in an array__
Given an array of integers of size n and an integer k, find the kth largest number in the array.

Input:
Integer n denoting the size of input array
Next line contains n space-separated numbers denoting the array elements.
Next line contains integer k.

Output:
single line containing the kth largest element of array.
*/

import java.util.*;

public class Kth_largest_element_in_array {

    public static int findKthLargest(int[] arr, int k) {
        //checking that test case is valid or not
        if(arr.length == 0 || k > arr.length) return Integer.MIN_VALUE;

        //Declaring a priority queue to store values
        PriorityQueue<Integer> priority_queue = new PriorityQueue<>();
        
        for(int indx = 0; indx < arr.length; indx++){
            //add every element of array to priority queue
            priority_queue.add(arr[indx]);

            //if number of elements (indx+1) is more than k, remove number from queue
            if (indx+1 > k) priority_queue.poll();
        }
        
        //kth largest number = top of priority queue
        return priority_queue.peek();
    }    
    public static void main(String[] args){

        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        int[] numbers = new int[n];

        for(int x = 0; x < n; x++){
            numbers[x] = inp.nextInt();
        }

        int k = inp.nextInt();

        System.out.println(findKthLargest(numbers, k)); 

        inp.close();
    }
}

/*Sample I/O
Sample 1
5          -> n
6 8 2 4 1  -> array elements
2          -> k

6    (Output)

Sample 2
10
2 8 5 6 7 0 1 5 9 6
5

6    (Output)

Time Complexity = O(n + klogn)
Space Complexity = O(n)
*/

