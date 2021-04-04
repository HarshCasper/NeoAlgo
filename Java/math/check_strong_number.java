
/*
Checking for a strong number using indirect recursion
Strong Number = 145
1! + 4! + 5! =145
sumOfFactorialOfDigit(int n) - extracts digit of n and calls factorial(n). Returns sum of factorial of digits
factorial(n)- returns factorial of extracted digits passed in the argument
*/

import java.util.*;
class check_strong_number {
    /*recursive function for sum of factorial of digits*/
    public static int sumOfFactorialOfDigit(int n)

    {
        if (n == 0)
            return n;
        else
            return (factorial(n % 10) + sumOfFactorialOfDigit(n / 10));

    }
    /*recursive function to find the factorial of n */
    public static int factorial(int n) {
        if (n == 0)
            return 1;
        else
            return (n * factorial(n - 1));
    }

    public static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Number. N = ");
        int num = sc.nextInt();
        if (num == sumOfFactorialOfDigit(num))
            System.out.println(" It is a Strong Number");
        else
            System.out.println(" It is not a Strong Number");
    }
}

/*
Sample Input And Output :
N = 145
It is a Strong Number
N = 534
It is not a Strong Number

Time Complexity : O(n)
Space Complexity : 1
*/
