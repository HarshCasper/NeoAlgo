import java.util.HashMap;
import java.util.Scanner;

public class UniqueIII {

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

        int result = findUnique(arr, size);

        if (result == -1) {
            System.out.println("No unique number found.");
        } else {
            System.out.println("Unique number:" + result);
        }
    }

    private static int findUnique(int[] arr, int length) {
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for (int i = 0; i < length; i++) {
            if (freq.containsKey(arr[i])) {
                freq.put(arr[i], freq.get(arr[i]) + 1);
            } else {
                freq.put(arr[i], 1);
            }
        }

        for(Integer i : freq.keySet()) {
            if (freq.get(i) == 1) {
                return i;
            }
        }
        return -1;
    }
}
/*
 * Enter number of elements:
 * 7
 * Enter array elements:
 * 6 2 5 2 2 6 6
 * Unique number:5
 */
