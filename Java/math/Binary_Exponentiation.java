// Java Program to find Binary Exponent Iteratively and Recursively.

import java.util.Scanner;

public class Binary_Exponentiation {
   // Iterative function to calculate exponent.
   public static int binExpo_iterate(int a, int b) {
      int res = 1;
      while (b > 0) {
         if (b % 2 == 1) {
            res = res * a;
         }
         a = a * a;
         b /= 2;
      }
      return res;
   }
   // Recursive function to calculate exponent.
   public static int binExpo_recurse(int a, int b) {
      if (b == 0) {
         return 1;
      }
      int res = binExpo_recurse(a, b / 2);
      res = res * res;
      if (b % 2 == 1) {
         return res * a;
      } else {
         return res;
      }
   }
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      int a = sc.nextInt();
      int b = sc.nextInt();
      if (a == 0 && b == 0) {
         System.out.println("Math error");
      } else if (b < 0) {
         System.out.println("Exponent must be Positive");
      } else if (a == 0) {
         System.out.println("0");
      } else {
         int resIterate = binExpo_iterate(a, b);
         int resRecurse = binExpo_recurse(a, b);
         System.out.println(resIterate);
         System.out.println(resRecurse);
      }
   }
}
