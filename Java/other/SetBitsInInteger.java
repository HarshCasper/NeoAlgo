// Problem Description

// Write a function that takes an integer and returns the number of 1 bits it has.

// Problem Constraints
// 1 <= A <= 109

// Input Format
// First and only argument contains integer A

// Output Format
// Return an integer as the answer

// Example Input
// Input1:
//     11

// Example Output
// Output1:
// 3

// Example Explanation
// Explaination1:
// 11 is represented as 1101 in binary 

import java.util.Scanner;

public class SetBitsInInteger {
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {

        // asking the user for input and storing the input in int variable n
        System.out.println("Kindly enter the number: ");
        int n = scan.nextInt();
        int count = findSetBits(n);
        System.out.println("Number of set bits = " + count);
    }

    private static int findSetBits(int num) {
        int count = 0;

        while (num > 0) {
            num = num & (num - 1);
            count++;
        }

        return count;
    }
}

/*
 * Sample Outputs:
 * 
 * Kindly enter the number: 3 Binary form: 11 2
 * 
 * 
 * Kindly enter the number: 2 Binary form: 10 1
 * 
 * 
 * Kindly enter the number: 16 Binary form: 10000 1
 * 
 * 
 */
