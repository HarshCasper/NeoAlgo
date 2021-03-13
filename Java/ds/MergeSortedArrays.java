/*
    Description: 
    Given two sorted arrays, the task is to merge them in a sorted manner.
    There are two sorted arrays and after merging there will be only one array in sorted manner.
*/
import java.util.*;
public class MergeSortedArrays {
   public static void main(String[] args) {
      int A[] = {-2,3,5,8,9};
      int B[] = {1,2,3,4,5};
      System.out.println(Arrays.toString(solve(A,B)));   
   }
   /*
       function to merge the given sorted arrays. 
   */
    public static int[] solve(final int[] A, final int[] B) {
       /* 
          Declaring a new Array of the expected result size i,e sum of length of Array A and Array B 
       */ 
       int ARR[] = new int[A.length+B.length]; 
       /*
          Declaring two pointers p1 and p2
          p1 points to first element of Array A
          p2 points to first element of Array B
       */ 
       int pointer1=0,pointer2=0;
        int k=0;
        while(pointer1<A.length && pointer2<B.length) {
            if(A[pointer1]<B[pointer2]) {
                ARR[k++] = A[pointer1++];
            }
            else {
                 ARR[k++] = B[pointer2++];
            }
        }
        while(pointer1<A.length) {
            ARR[k++]=A[pointer1++];
        }
        while(pointer2<B.length) {
            ARR[k++]=B[pointer2++];
        }
        return ARR;
    }
}
/*
  Example: 
  Input: 
      A[] = {-2,3,5,8,9}
      B[] = {1,2,3,4,5}
  Output:
     [-2,1,2,3,3,4,5,5,8,9]
     
   Explanation: 
      After Merging A and B produces the output as described above.
*/
/*
  Time and Space Complexity
  M = length of Array A
  N = length of Array B
  Time Complexity O(M+N)
  Space Complexity O(M+N)
*/
