/*Given five positive long integers, find the minimum and maximum values 
that can be calculated by summing exactly four of the five integers. 
Then print the respective minimum and maximum values as a single line of two space-separated long integers.*/
//impoting java packages
import java.io.*;
import java.util.*;
public class MaxMinSumLeavingOneElement{
  
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
         long arr[] = new long[5];
         System.out.println("Enter fiver numbers in the array - ");
        for(int i=0;i<5;i++){
          
          //taking input from user  --- time complexity of O(n)
            arr[i] = in.nextLong();   
            
        }
      //function call with passing the array as argumment
        MaxMinSumOfElements(arr);
    }
  
    public static void MaxMinSumOfElements(long arr[]){
        
        //sorting the array using Arrays.sort function
        Arrays.sort(arr);long min=0;long max=0;
      
        for(int i=0;i<4;i++){
          //calculating minimum sum by summing the first 4 digits of the sortedd array --- time complxity of O(n)
            min+=arr[i];
          
        }
        for(int i=1;i<5;i++){
          //calculating maximum sum by summing up the last 4 digits of the sorted array  --- time complxity of O(n)
            max+=arr[i];
          
        }
        //printing the output.
        System.out.println("The minimum sum of elements excluding exactly one element is - "+min);
        System.out.println("The maximum sum of elements excluding exactly one element is - "+max);
    }
}
/*
Sample Input

Enter five elements in the array - 
4 3 9 8 2

Sample Output

The minimum sum of elements excluding exactly one element is - 17 
The maximum sum of elements excluding exactly one element is - 24

Time Complexity - 

O(n) + O(n) + O(n) = O(n)

*/
