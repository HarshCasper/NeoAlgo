import java.util.HashMap;
import java.util.Scanner;

public class FindNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of elements:");
        int size = scanner.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        findNonRepeating(arr, size);
    }

    private static void findNonRepeating(int[] arr, int length) {
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for (int i = 0; i < length; i++) {
            if (freq.containsKey(arr[i])) {
                freq.put(arr[i], freq.get(arr[i]) + 1);
            } else {
                freq.put(arr[i], 1);
            }
        }

        System.out.println("Unique terms are:");
        for (Integer i : freq.keySet()) {
            if (freq.get(i) == 1) {
                System.out.println(i);
            }
        }
    }
}

/*
* Sample input/output
* Enter number of elements:
* 6
* Enter array elements:
* 1 2 3 2 1 4
* Unique terms are:
* 3
* 4
*
* Time and space complexity: O(n)
*/
