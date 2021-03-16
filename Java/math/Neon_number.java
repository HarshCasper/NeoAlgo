/*
Program by :: Anand Dasani
Date :: 13-03-2021

Aim :: To check the given number is Neon or not.

What is Neon number ?
A Neon number is a number where the sum of digits of square of the number is equal to that number.

                        ALGO
1. Take a number from the user
2. Find the square of the given number.
3. By using loop , find the sum of the square of the all individual digits
4. Check condition if our sum is equal to the user given number
        (a.) Return true
        (b.) Else return false.
5. Exit
 */

import java.util.Scanner; // for scanner class

public class Neon_number {

    public static void main(String[] args) {

        System.out.print("\nEnter the number :: ");

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if (isNeon(n)) // checking the number is Neon or not
            System.out.println(n + " is Neon number :)");
        else
            System.out.println(n + " is not a Neon number :(");

    }

    /**
     * method to check the given number is Neon or not
     *
     * @param num for storing the value given by user
     * @return ture if number is Neon else return false
     */
    public static boolean isNeon(int num) {

        // Accumulator :-> A running total is a sum of numbers that accumulate with each iteration of a loop
        int n, sum = 0; // assuming sum as accumulator

        n = num * num;
        while (n != 0) { // running loop till we consider all the digits of the squared number
            sum += (n % 10); //getting the last digit & adding the last digit to sum
            n /= 10; // neglecting the last number which we have counted
        }

        if (sum == num)
            return true;

        return false;
    }
}

/*
Test case :: T = 1
Enter the number :: 9   // input
9 is Neon number :)     // output

Explanation :->
1. square the number i,e.. 9 * 9 = 81
2. add up all the individual digits i,e.. 8 + 1 = 9
3. check the sum is equal to the given number ?  i,e.. ( 9 == 9 ? true : false )

Test case :: T = 2
Enter the number :: 0   // input
9 is Neon number :)     // output

Test case :: T = 3
Enter the number :: 1   // input
9 is Neon number :)     // output

Test case :: T = 4
Enter the number :: 3   // input
9 is not a Neon number :(     // output

Time complexity :: O(log(n))
Space complexity :: O(1)

 */
