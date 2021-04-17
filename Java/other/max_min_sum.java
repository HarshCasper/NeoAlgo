/*Given five positive integers, find the minimum and maximum values 
that can be calculated by summing exactly four of the five integers. 
Then print the respective minimum and maximum values as a single line of two space-separated long integers.*/
import java.io.*;

import java.util.*;//impoting java packages

public class sol{
  
    public static void main(String[] args){
      
        Scanner in = new Scanner(System.in);
      
        long arr[] = new long[5];
      
        for(int i=0;i<5;i++){
          
            arr[i] = in.nextLong();//taking input from user  --- time complexity of O(n)
          
        }
      
        Arrays.sort(arr);long min=0;long max=0;//sorting the array using Arrays.sort function
      
        for(int i=0;i<4;i++){
          
            min+=arr[i];//calculating minimum sum by summing the first 4 digits--- time complxity of O(n)
          
        }
        for(int i=1;i<5;i++){
          
            max+=arr[i];//calculating maximum sum by summing up the last 4 digits --- time complxity of O(n)
          
        }
        System.out.println(min+" "+max);//printing the output.
    }
}
/*
Sample Input

4 3 9 8 2

Sample Output

17 24

Time Complexity - 

O(n) + O(n) + O(n) = O(n)

