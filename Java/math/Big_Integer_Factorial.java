/*BigInteger class is used for mathematical operation which involves very big integer calculations that are outside the limit of all available primitive data types. For example factorial of 100 contains 158 digits in it so we can't store it in any primitive data type available*/
import java.math.*;
import java.util.*;
class Big_Integer_Factorial {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number to find the factorial of");
        int n = sc.nextInt();
        System.out.println(" The factorial of " + n + " is : " + factorial(n));
    }
    public static BigInteger factorial(int n) {
        BigInteger fact = new BigInteger(Integer.toString(n));
        for (int i = 1; i < n; i++)
            fact = fact.multiply(BigInteger.valueOf(i));
        return fact;

    }

}
/* Sample Input and Output : 
 * Enter the number to find the factorial of
32
 The factorial of 32 is : 263130836933693530167218012160000000
Time Complexity : O(n)
Space Complexity : O(1)
 */