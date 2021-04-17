//Exponential Search

/* Basic Working
Find range where element is present.
Do Binary Search in above found range.*/

/*The idea is to start with subarray size 1 compare its last element with x, 
then try size 2, then 4 and so on until last element of a subarray is not greater.
Once we find an index i (after repeated doubling of i), 
we know that the element must be present between i/2 and i 
(Why i/2)? because we could not find a greater value in previous iteration)*/

import java.util.Arrays;

class ExponentialSearchApp
{

 static int exponentialSearch(int arr[], int n, int x)
 {

  if (arr[0] == x)
   return 0;
   
  int i = 1;
  while (i < n && arr[i] <= x)
   i = i*2;
 
  return Arrays.binarySearch(arr, i/2, Math.min(i, n), x);
 }
 
 public static void main(String args[])
 {
   val scan = Scanner(System.`in`)
   
   print("Enter the number of elements :")              //Taking input from user
   
   val arr = IntArray(scan.nextInt())

   print("Enter the elements :")
   for(i in array.indices){
     arr[i] = scan.nextInt()
   } 
   print("Enter the number you want to search for :")
   val x = scan.nextInt()
   scan.close()
  int result = exponentialSearch(arr, arr.length, x);
  
  System.out.println((result < 0) ? "Element is not present in array" :
        "Element is present at index " + result);
 }
}

/*Sample Testcase:

   Enter the number of elements :5
   Enter the elements :1 3 7 9 12
   Enter the number you want to search for : 7

   Output: Element is present at index 3


Time Complexity : O(Log n)
Auxiliary Space :Recursive Binary Search O(Log n) space.
Iterative Binary Search O(1) space.
*/

