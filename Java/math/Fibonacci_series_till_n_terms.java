/*
To input a number (suppose n) and display the fibonacci series till n terms.
Fibonacci series is such that each no is the sum of the previous 2 terms, starting from 0 and 1.
For n=4 
The Fibonacci series will be:
0 1 1 2
*/

import java.util.*;
public class  Fibonacci_series_till_n_terms {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    //enter the no of terms required in the series
    System.out.println("Enter the no of terms required in the series");
    int n = sc.nextInt();
     //initializing the first two no of the series
    int a = 0, b = 1;    
    int c = 0;
    if (n <= 0) {
     // prints the message "Enter a positive no" in case n is negative or 0
      System.out.println("Enter a positive number"); 
    } else if (n == 1) {
      System.out.println("The fibonaaci series upto " + n + " term is");
      // prints the first term i.e 0 in case n=1
      System.out.println(a); 
    } else {
      System.out.println("The fibonaaci series upto " + n + " terms is");
      //printing the first two terms of the series
      System.out.print(a + " " + b + " ");    
      //looping till n terms if n>2   
      for (int i = 3; i <= n; ++i) 
      {
        //storing the next term in c i.e the sum of previous two no.    
        c = a + b; 
        //changing the value of a to the next term  i.e b
        a = b; 
        //changing the value of b to the next term  i.e c
        b = c; 
        // printing the next term and adding space for the next term
        System.out.print(c + " "); 
      }
    }
  }
}

/*
Time Complexity : O(n)
Space Complexity : O(1)
Input 1 :
Enter the no of terms required in the series
-2
Output 1 :
Enter a positive number

Input 2 :
Enter the no of terms required in the series
1
Output 2 :
The fibonaaci series upto 1 term is
0

Input 3 :
Enter the no of terms required in the series
7
Output 3 :
The fibonaaci series upto 7 terms is
0 1 1 2 3 5 8 


*/