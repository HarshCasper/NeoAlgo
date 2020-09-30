import java.util.Scanner;

public class LetterCodeRecursion {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Codes will be decoded according to positions of letters, for example: 1=A, 2=B, ..., 26=Z");
        System.out.println("Enter the length of given code:");
        int size = scanner.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter the numbers of the given code (with spaces):");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        int result = countCodes(arr, size);

        System.out.println("Number of codes:" + result);
    }

    private static int countCodes(int[] arr, int size) {

        // basic situation
        if (size == 1 || size == 0) {
            return 1;
        }

        // for a situation for example 0543
        if (arr[0] == 0) {
            return 0;
        }

        int count = 0; // initialize count

        if (arr[size-1] > 0) {
            // only if the digit under counting is greater than 0
            count = countCodes(arr, size - 1);
        } else {
            // cannot find codes if a digit is 0
            return 0;
        }

        if (arr[size - 2] == 1 || (arr[size - 2] == 2 && arr[size - 1] < 7) ) {
            count += countCodes(arr, size - 2);
        }

        return count;
    }
}

/*
* Sample input/output:
* Codes will be decoded according to positions of letters, for example: 1=A, 2=B, ..., 26=Z
* Enter the length of given code:
* 4
* Enter the numbers of the given code (with spaces):
* 1 2 3 4
* Number of codes:3
*
* (ABCD, LCD, AWD)
*
* Time complexity = O(2^n)
*/
