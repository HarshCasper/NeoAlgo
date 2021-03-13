import java.util.*;
public class MergeSortedArrays {
   public static void main(String[] args) {
      int A[] = {-2,3,5,8,9};
      int B[] = {1,2,3,4,5};
      
    // OR USED SCANNER FOR INPUT
      
     /* Scanner sc=  new Scanner(System.in);
      int N = sc.nextInt(); //length of Array A
      int A[] = new int[N];
      for(int i=0;i<N;i++) {
         A[i]  = sc.nextInt();
      }
      int M = sc.nextInt(); //length of Array B
      int B[] = new int[M];
      for(int i=0;i<M;i++) {
         B[i]  = sc.nextInt();
      }
      */
      
      System.out.println(Arrays.toString(solve(A,B)));   

   }
    public static int[] solve(final int[] A, final int[] B) {
        int ARR[] = new int[A.length+B.length];
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
