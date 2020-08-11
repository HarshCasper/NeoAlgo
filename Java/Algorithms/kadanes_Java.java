// Java Program for Kadane's Algorithm.

import java.util.*;
public class Kadane {

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] arr = new int[n];
      int maxSoFar = Integer.MIN_VALUE;
      int curSum = 0;
      for (int i = 0; i < arr.length; i++) {
         arr[i] = sc.nextInt();
      }
      for (int i = 0; i < arr.length; i++) {
         if (curSum + arr[i] < 0)
            curSum = 0;
         else
            curSum = curSum + arr[i];
         if (curSum > maxSoFar)
            maxSoFar = curSum;
      }
      System.out.println(maxSoFar);
      sc.close();
   }
}
