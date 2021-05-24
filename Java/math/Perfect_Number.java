// A perfect number is a number which is equal to sum of its factors other than the number itself

import java.util.Scanner;

public class PerfectNumber {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter an integer to check:");
        int n = s.nextInt();
        if (isPerfectNumber(n)) {
            System.out.println(n + " is a perfect number");
        } else {
            System.out.println(n + " is not a perfect number");
        }
    }

    // Method to check if a number is a perfect number or not
    public static boolean isPerfectNumber(int number) {
        if (number < 1) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i < number; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum == number;
    }
}
/*
Sample Output
Enter an integer to check:28
28 is a perfect number

Complexities
Time Complexity:O(n^0.5)
Space Complexity:O(1)
 */

