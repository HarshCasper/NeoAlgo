//Java Code to find the last digit of nth fibonacci number

import java.io.* ;
import java.util.* ;

public class LastDigitFibonacci {

  public static void main(String[] args) {

    //dynamic input
    Scanner sc = new Scanner(System. in );
    System.out.println("Input:\n");
    System.out.println("Enter the value of N\n");
    //long used to hold large value of N
    long N = sc.nextLong();
    //On observing,we can find the repitition of last digit after 60
    //precomputed an array of size 60 and stored fibonacci respectively
    int f[] = new int[60];
    f[0] = 0;   //setting value of Oth index of f[] to 0
    f[1] = 1;   //setting value of 1th index of f[] to 1
    for (int i = 2; i < 60; i++) {
      //adding the previous and next previous elements mod 10 and storing it in present index
      //thus the last digit after adding is stored in f[i] 
      f[i] = (f[i - 2] + f[i - 1]) % 10;
    }
    System.out.println("Output:\n");
    System.out.println("The last digit of " + N + "th fibonaci is " + f[(int)(N % 60L)]);

  }
}

/*
  Input:
  Enter the value of N 
  67
  Output:
  The last digit of 67th fibonacci is 3
  
  Time Complexity: O(1)
  Space Complexity:O(1)
*/
