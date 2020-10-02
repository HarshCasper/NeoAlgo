import java.util.*;

public class FirstMissingPositiveNumber {

    private static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static int findMissingPositive(int arr[]) {
        // we firstly separate the positive numbers from negative numbers
        int j = 0, i;
        // j is for counting non-positive integers
        for (i = 0; i < arr.length; i++) {
            if (arr[i] <= 0) {
                swap(arr, i, j);
                j += 1;
            }
        }

        // getting array for only positive numbers in arr2
        int arr2[] = new int[arr.length - j];
        i = j;
        j = 0;
        for (; i < arr.length; i++) {
            arr2[j] = arr[i];
            j += 1;
        }

        // marking the number visited by its negative
        // for only those that don't go beyond length of the
        // array of positive numbers
        for (i = 0; i < arr2.length; i++) {
            int checkNum = Math.abs(arr2[i]);
            if (checkNum - 1 < arr2.length && arr2[checkNum - 1] > 0) {
                arr2[checkNum - 1] = -arr2[checkNum - 1];
            }
        }

        for (i = 0; i < arr2.length; i++) {
            if (arr2[i] > 0) {
                return i + 1;
            }
        }
        return arr2.length + 1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter array elements:");
        for (int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        int missingNum = findMissingPositive(arr);

        System.out.println("Lowest missing positive integer in the array is:" + missingNum);
    }
}
/**
 * Sample input/output:
 * Enter size of array:
 * 8
 * Enter array elements:
 * 1
 * -1
 * -5
 * -3
 * 3
 * 4
 * 2
 * 8
 * Lowest missing positive integer in the array is:5
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
