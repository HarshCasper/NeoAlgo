import java.util.*;

public class DoubleFactorial {

    // Recursive approach
    private static int recursiveDoubleFactorial(int num) {
        // checking for 1 and 0
        if (num == 0 || num == 1) {
            return 1;
        }

        // using recursion
        return num * recursiveDoubleFactorial(num - 2);
    }

    // Iterative approach
    private static int iterDoubleFactorial(int num) {
        int result = 1;
        // using iterations
        for (int i = num; i >= 0; i = i-2) {

            if (i == 0 || i == 1) {
                return result;
            } else {
                result *= i;
            }
        }

        return result;
    }
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number:");
        int num = sc.nextInt();
        System.out.println("Which approach would you like to use?");
        System.out.println("1. Recursive");
        System.out.println("2. Iterative");
        int ch = sc.nextInt();
        sc.close();

        int result;
        switch(ch) {
            case 1:
                result = recursiveDoubleFactorial(num);
                System.out.println("Double factorial:" + result);
                break;

            case 2:
                result = iterDoubleFactorial(num);
                System.out.println("Double factorial:" + result);
                break;

            default:
                System.out.println("Invalid choice.");
        }
    }
}
/**
 * Sample input/output
 * Enter the number:
 * 5
 * Which approach would you like to use?
 * 1. Recursive
 * 2. Iterative
 * 1
 * Double factorial:15
 * 
 * Enter the number:
 * 6
 * Which approach would you like to use?
 * 1. Recursive
 * 2. Iterative
 * 2
 * Double factorial:48
 * 
 * Time complexity for both the approaches is O(n)
 */
