import java.util.*;

public class RussianPeasant {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter 2 numbers:");
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        int result = 0; // for storing the product

        // as long as second number is greater than 0
        while (b > 0) {

            // if second becomes odd add first to result
            if ((b & 1) != 0) {
                result += a;
            }

            // double first and halve the second
            a = a << 1;
            b = b >> 1;
        }

        System.out.println("Product:" + result);
    }
}
/*
* Sample input/output
* Enter 2 numbers:
* 20 12
* Product:240
*
* Time complexity: O(1)
*/
