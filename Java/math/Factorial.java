/*
Factorial is the product of all positive integers less than or equal to a given positive integer 
and denoted by that integer and an exclamation point. 
Thus, factorial five is written 5!, meaning 1 × 2 × 3 × 4 × 5.
Factorial zero is defined as equal to 1.
*/

import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int n = sc.nextInt();
        System.out.println("Factorial of " +n+ " is: " + fact(n));
    }
    public static int fact(int n){
        if(n==0)
            return 1;

        return n*fact(n-1);
    }
}

/*
    Test Cases:
    Enter Number: 7
    Factorial of 7 is: 5040

    Enter Number: 0
    Factorial of 0 is: 1

    Time Complexity: O(n)
    Space Complexity: O(n)
*/